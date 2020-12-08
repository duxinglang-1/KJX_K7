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
 *  SmsAppUmSap.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to handle the Common SAP between UM and SMS applciation
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "mmi_features.h"
#ifdef __MOD_SMSAL__
/**************************************************************
 * Header Files Include
 **************************************************************/
extern "C"
{
#include "stack_common.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "Unicodexdcl.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_events_gprot.h"

#include "SmsSrvGprot.h"
#include "UmSrvGProt.h"
#include "mmi_rp_app_vapp_sms_def.h"
#include "DateTimeGprot.h"
#include "App_usedetails.h"
}
#include "vfx_mc_include.h"
#include "vfx_system.h"
#include "vapp_sms_provider.h"
#include "vapp_sms_util.h"

/**************************************************************
* MARCO
**************************************************************/
#define MMI_SMS_REPORT_SUBJECT_LEN      60
#define SIM_ID_BIT_OFFSET               16
#define SIM_ID_BIT_MASK                 0xFFFF
#define STORAGE_BIT_OFFSET              8
#define STORAGE_BIT_MASK                0xFF
#define STATUS_BIT_OFFSET               0
#define STATUS_BIT_MASK                 0xFF

#define VAPP_SMS_SEND_ILM(destMod, msgId, loacPara)	\
			mmi_frm_send_ilm(destMod, msgId, (oslParaType*)loacPara, NULL)

#define __VAPP_SMS_VOBJECT__

/**************************************************************
* Structure Declaration
**************************************************************/
typedef enum
{
    SMS_UM_STATUS_NONE,
    SMS_UM_STATUS_READ,
    SMS_UM_STATUS_UNREAD,
    SMS_UM_STATUS_SENT,
    SMS_UM_STATUS_UNSENT,
    SMS_UM_STATUS_DRAFT,
    SMS_UM_STATUS_SEND_WAITING,
    SMS_UM_STATUS_SEND_FAIL,
    SMS_UM_STATUS_SEND_SENDING,

    SMS_UM_STATUS_TOTAL
} VappSmsUmStatusEnum;

typedef struct
{
    srv_um_msg_box_enum msg_box_type;
} vapp_sms_um_del_folder_struct;

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
typedef struct
{
    kal_uint32 app_id;
    srv_um_msg_box_enum um_box_type;
    srv_um_mark_several_op_action_enum action_type;
    VfxU16 curr_index;
    VfxU16 total_num;
    VfxU16 msg_id[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];
    VfxBool result[SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP];
} vapp_sms_um_multi_op_cntx_struct;
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */


/**************************************************************
 * Global Variables Declaration
 **************************************************************/

/**************************************************************
 * Global Function Declaration
 **************************************************************/

/**************************************************************
 * Static Variables Defination
 **************************************************************/

/**************************************************************
 * Static Function Declaration
 **************************************************************/
static VfxBool vapp_sms_um_get_num_req_hdlr(void* inMsg);
static VfxBool vapp_sms_um_get_list_info_req_hdlr(void* inMsg);
static VfxBool vapp_sms_um_get_msg_info_req_hdlr(void* inMsg);
static VfxBool vapp_sms_um_del_folder_req_hdlr(void* inMsg);

static void vapp_sms_um_get_msg_num(
                srv_um_get_msg_num_rsp_struct *rsp_data,
                srv_um_sim_enum um_sim_id);
static VfxBool vapp_sms_um_get_msg_list_info_hdlr(
                    srv_um_get_msg_list_rsp_struct *rsp_data,
                    srv_um_get_msg_list_req_struct *req_data);
static void vapp_sms_um_get_msg_list_info(
                VfxU16 msg_id,
                srv_um_msg_list_struct *list_info,
                srv_um_list_idx_data_union *list_idx_data,
                srv_um_list_idx_enum list_idx_type);

static void vapp_sms_um_get_msg_address(
				VfxWChar* address,
				srv_um_addr_enum* addr_type,
				VfxU16 msg_id,
				VfxU32 address_len);
static void vapp_sms_um_get_msg_subject(
				VfxWChar *subject,
				VfxU16 msg_id,
				VfxU32 subject_len);

static void vapp_sms_um_get_msg_info_hdlr(srv_um_get_msg_info_req_struct *req_data);
static VfxBool vapp_sms_um_get_msg_info_content(
                    srv_um_msg_info_struct *msg_info,
                    VfxU16 msg_id,
                    srv_um_msg_box_enum msg_box_type);
static void vapp_sms_um_get_msg_common_info(
                srv_um_msg_info_struct *msg_info,
                VfxU16 msg_id,
                srv_um_msg_box_enum msg_box_type);

static void vapp_sms_um_del_folder_callback(srv_sms_callback_struct* callback_data);
static void vapp_sms_um_del_folder_hdlr(VfxBool result, srv_um_msg_box_enum msg_box_type);

static VfxU16 vapp_sms_um_get_box_size(srv_um_msg_box_enum um_box_type, srv_um_sim_enum um_sim_id);
static VfxU16 vapp_sms_um_get_unread_msg_num(srv_um_sim_enum um_sim_id);

#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
static VfxBool vapp_sms_um_multi_op_req_hdlr(void *in_msg);
static void vapp_sms_um_multi_op_init(
                vapp_sms_um_multi_op_cntx_struct *cntx,
                srv_um_mark_several_op_req_struct *req_msg);
static void vapp_sms_um_multi_op_hdlr(vapp_sms_um_multi_op_cntx_struct *cntx);
static void vapp_sms_um_multi_op_callback(srv_sms_callback_struct* callback_data);
static void vapp_sms_um_multi_op_send_rsp_to_um(vapp_sms_um_multi_op_cntx_struct *cntx);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */

#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__

#ifdef LOW_COST_SUPPORT
typedef struct
{
	srv_um_traverse_msg_req_struct req_info;
	srv_um_msg_detail_struct detail_info;	
	VfxU16 curr_index;
	VfxU16 total_msg_count;
	VfxU16 complete_msg_count;
	VfxBool is_continue;
	VfxBool is_more;
	VfxBool result;
	
} vapp_sms_um_traverse_msg_context;

static VfxBool vapp_sms_um_traverse_msg_req_hdlr_async(void *inMsg);

static vapp_sms_um_traverse_msg_context *vapp_sms_um_create_and_init_msg_context(srv_um_traverse_msg_req_struct *msgReq);

static void vapp_sms_um_get_content_callback(srv_sms_callback_struct* callback_data);

static VfxBool vapp_sms_um_check_msg_subject(vapp_sms_um_traverse_msg_context *context,VfxU16 msg_id,VfxU32 subject_len);

static VfxBool vapp_sms_um_traverse_msg_async(vapp_sms_um_traverse_msg_context *context);
#else
static VfxBool vapp_sms_um_traverse_msg_req_hdlr(void *inMsg);

static VfxBool vapp_sms_um_traverse_msg(srv_um_traverse_msg_req_struct *msgReq,VfxU16 *msg_number,VfxBool *more);
#endif /*LOW_COST_SUPPORT */

static void vapp_sms_um_get_traverse_msg_addr(srv_um_addr_struct* um_addr,U16 msg_id);

static void vapp_sms_um_send_traverse_msg_rsp(VfxU32 app_id, VfxU32 msg_number, VfxBool more, VfxBool result);

#ifdef __SRV_SMS_MULTI_ADDR__
static void vapp_sms_um_free_multi_addr_buffer(srv_um_addr_struct* um_addr);
#endif /* __SRV_SMS_MULTI_ADDR__ */

static void vapp_sms_um_free_traverse_msg_buffer(srv_um_msg_detail_struct *msg_detail);
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */

static VfxU32 vapp_sms_um_get_msg_status(VfxU16 msg_id);
static VfxU16 vapp_sms_get_msg_icon(VfxU16 msg_id);

static srv_um_msg_box_enum vapp_sms_um_get_box_type(
                            srv_sms_status_enum status_type, 
                            srv_sms_folder_enum folder_type,
                            srv_sms_storage_enum storage_type);
static srv_sms_box_enum vapp_sms_um_um_box_to_sms(srv_um_msg_box_enum um_box_type);
static srv_um_msg_box_enum vapp_sms_um_sms_box_to_um(srv_sms_box_enum sms_box_type);


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_sap_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" void vapp_sms_um_sap_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_NUM_REQ, (PsIntFuncPtr)vapp_sms_um_get_num_req_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_LIST_REQ, (PsIntFuncPtr)vapp_sms_um_get_list_info_req_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_GET_MSG_INFO_REQ, (PsIntFuncPtr)vapp_sms_um_get_msg_info_req_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_DELETE_FOLDER_REQ, (PsIntFuncPtr)vapp_sms_um_del_folder_req_hdlr, MMI_TRUE);
#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_MARK_SEVERAL_OP_REQ, (PsIntFuncPtr)vapp_sms_um_multi_op_req_hdlr, MMI_TRUE);
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */
#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
#ifdef LOW_COST_SUPPORT
	mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_TRAVERSE_MSG_REQ, (PsIntFuncPtr)vapp_sms_um_traverse_msg_req_hdlr_async, MMI_TRUE);
#else
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_UM_TRAVERSE_MSG_REQ, (PsIntFuncPtr)vapp_sms_um_traverse_msg_req_hdlr, MMI_TRUE);
#endif /* LOW_COST_SUPPORT */
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_ready_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" mmi_ret vapp_sms_um_ready_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_ready_ind_struct *ind_msg = NULL;
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_sms_ready_struct *event_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_sms_ready_struct*)event_data->event_info;
    ind_msg = (srv_um_ready_ind_struct*)OslConstructDataPtr(sizeof(srv_um_ready_ind_struct));

    ind_msg->result = (kal_bool)event_info->is_sms_ready;
    ind_msg->msg_type = SRV_UM_MSG_SMS;

    VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_READY_IND, ind_msg);

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_new_msg_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" mmi_ret vapp_sms_um_new_msg_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_new_sms_struct *event_info = (srv_sms_event_new_sms_struct*)event_data->event_info;
    srv_sms_new_msg_struct *msg_data = (srv_sms_new_msg_struct*)event_info->msg_data;
    srv_um_refresh_ind_struct *refresh_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/* If the message is class0 msg, it don't need to inform UM */
	if (event_info->msg_id != SRV_SMS_INVALID_MSG_ID)
	{
	    refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));
	    refresh_ind->msg_type = SRV_UM_MSG_SMS;
	    refresh_ind->refresh_type = SRV_UM_REFRESH_NEW_INCOMING_MSG;

	#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
	    if (msg_data->storage_type == SRV_SMS_STORAGE_SIM)
	    {
	        refresh_ind->msg_box_type = SRV_UM_MSG_BOX_SIM;
	    }
	    else
	#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
	    {
	        refresh_ind->msg_box_type = SRV_UM_MSG_BOX_INBOX;
	    }

	    refresh_ind->msg_id = event_info->msg_id;
	    refresh_ind->addr_number = 1;
	    refresh_ind->addr_type = SRV_UM_ADDR_PHONE_NUMBER;
	    mmi_asc_to_wcs((WCHAR*)refresh_ind->address, (char*)msg_data->number);

	    VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);
	}

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_msg_add_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  VfxBool
 *****************************************************************************/
extern "C" mmi_ret vapp_sms_um_msg_add_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready())
    {
        srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
        srv_sms_event_add_struct *event_info;
        srv_um_msg_box_enum msg_box_type;
        srv_um_refresh_ind_struct *refresh_ind;

        event_info = (srv_sms_event_add_struct*)event_data->event_info;

        msg_box_type = vapp_sms_um_get_box_type(
                        event_info->msg_info.status,
                        event_info->msg_info.folder_id,
                        event_info->msg_info.storage_type);

        refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));

        refresh_ind->msg_type = SRV_UM_MSG_SMS;
        refresh_ind->msg_box_type = msg_box_type;
        refresh_ind->refresh_type = SRV_UM_REFRESH_CREATE_MSG;
        refresh_ind->msg_id = event_info->msg_id;
        refresh_ind->addr_number = 1;
        refresh_ind->addr_type = SRV_UM_ADDR_PHONE_NUMBER;
       	vfx_sys_wcscpy((VfxWChar*)refresh_ind->address, (VfxWChar*)event_info->msg_info.number);

        VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_msg_del_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  VfxBool
 *****************************************************************************/
extern "C" mmi_ret vapp_sms_um_msg_del_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready())
    {
        srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
        srv_sms_event_delete_struct *event_info;
        srv_um_msg_box_enum msg_box_type;
        srv_um_refresh_ind_struct *refresh_ind;

        event_info = (srv_sms_event_delete_struct*)event_data->event_info;

        msg_box_type = vapp_sms_um_get_box_type(
                        event_info->msg_info.status,
                        event_info->msg_info.folder_id,
                        event_info->msg_info.storage_type);

        refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));

        refresh_ind->msg_type = SRV_UM_MSG_SMS;
        refresh_ind->msg_box_type = msg_box_type;
        refresh_ind->refresh_type = SRV_UM_REFRESH_MSG_DELETED;
        refresh_ind->msg_id = event_info->msg_id;
        refresh_ind->addr_number = 1;
        refresh_ind->addr_type = SRV_UM_ADDR_PHONE_NUMBER;
        vfx_sys_wcscpy((VfxWChar*)refresh_ind->address, (VfxWChar*)event_info->msg_info.number);

        VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_msg_update_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event_data      [IN]        
 * RETURNS
 *  VfxBool
 *****************************************************************************/
extern "C" mmi_ret vapp_sms_um_msg_update_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_sms_ready())
    {
        srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
        srv_sms_event_update_struct *event_info;
        srv_um_msg_box_enum src_box_type;
        srv_um_msg_box_enum dest_box_type;
        srv_um_refresh_ind_struct *refresh_ind;

        event_info = (srv_sms_event_update_struct*)event_data->event_info;      

        src_box_type = vapp_sms_um_get_box_type(
                        event_info->old_msg_info.status,
                        event_info->old_msg_info.folder_id,
                        event_info->old_msg_info.storage_type);

        dest_box_type = vapp_sms_um_get_box_type(
                            event_info->new_msg_info.status,
                            event_info->new_msg_info.folder_id,
                            event_info->new_msg_info.storage_type);

        if ((event_info->old_msg_info.status != event_info->new_msg_info.status) ||
            (event_info->old_msg_info.storage_type != event_info->new_msg_info.storage_type) ||
            (event_info->old_msg_info.sim_id != event_info->new_msg_info.sim_id))
        {
		    return MMI_RET_OK;
        }

        refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));

        refresh_ind->msg_type = SRV_UM_MSG_SMS;
        refresh_ind->msg_box_type = (srv_um_msg_box_enum)(src_box_type | dest_box_type);
        refresh_ind->msg_id = event_info->msg_id;
        refresh_ind->addr_number = 1;
        refresh_ind->addr_type = SRV_UM_ADDR_PHONE_NUMBER;
        vfx_sys_wcscpy((VfxWChar*)refresh_ind->address, (VfxWChar*)event_info->new_msg_info.number);

        if (src_box_type != dest_box_type)
        {
            refresh_ind->refresh_type = SRV_UM_REFRESH_MSG_FOLDER_CHANGED;
        }
        else
        {
            if ((event_info->old_msg_info.status != event_info->new_msg_info.status) ||
                (event_info->old_msg_info.storage_type != event_info->new_msg_info.storage_type) ||
                (event_info->old_msg_info.sim_id != event_info->new_msg_info.sim_id))
            {
                /* those will cause the status icon change */
                // refresh_ind->refresh_type = SRV_UM_REFRESH_MSG_STATUS_CHANGED;
				    return MMI_RET_OK;

            }
            else if (event_info->change_para_flag & SRV_SMS_PARA_CONTENT)
            {
                refresh_ind->refresh_type = SRV_UM_REFRESH_MSG_CONTENT_CHANGED;
            }
            else
            {
                refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;
            }
        }

        VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);
    }

    return MMI_RET_OK;
}

extern "C" mmi_ret vapp_sms_um_msg_refresh_event_proc(mmi_event_struct *evt)
{



    srv_um_refresh_ind_struct *refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));

    refresh_ind->msg_type = SRV_UM_MSG_SMS;
    refresh_ind->msg_box_type = SRV_UM_MSG_BOX_ALL;
    refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;
    VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);
	return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_unsent_msg_update_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" mmi_ret vapp_sms_um_unsent_msg_update_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_sms_event_update_unsent_msg_status_struct *event_info;
    VfxU16 unsent_msg_id;
    VfxBool need_refresh = VFX_TRUE;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_info = (srv_sms_event_update_unsent_msg_status_struct*)event_data->event_info;
    unsent_msg_id = event_info->msg_id;

	switch (event_info->status)
	{
		case SRV_SMS_SEND_SUCCESS:
		case SRV_SMS_SEND_SENDING:
		case SRV_SMS_SEND_WAITING:	
		case SRV_SMS_SEND_FAIL:
		default:
			break;
	}

    if (need_refresh)
    {
        srv_um_refresh_ind_struct *refresh_ind;

        refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));

        refresh_ind->msg_type = SRV_UM_MSG_SMS;
        refresh_ind->msg_box_type = SRV_UM_MSG_BOX_UNSENT;
        refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;
        refresh_ind->msg_id = unsent_msg_id;
        refresh_ind->addr_number = 1;
        refresh_ind->addr_type = SRV_UM_ADDR_PHONE_NUMBER;
        srv_sms_get_msg_address(unsent_msg_id, (char*)refresh_ind->address);

        VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);
    }
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    return MMI_RET_OK;
}


#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_unsent_msg_update_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" mmi_ret vapp_sms_um_folder_changed_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* event_data = (srv_sms_event_struct*)evt;
    srv_um_msg_box_enum um_box_type = SRV_UM_MSG_BOX_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SMS_CLEAR_FOLDER:
        {
            srv_sms_event_clear_folder_struct *event_info;

            event_info = (srv_sms_event_clear_folder_struct*)event_data->event_info;

            if (event_info->folder_id == SRV_SMS_FOLDER_ARCHIVE)
            {
                um_box_type = SRV_UM_MSG_BOX_ARCHIVE;
            }
            break;
        }

        case EVT_ID_SRV_SMS_HIDE_LIST:
        {
            srv_sms_event_hide_list_struct *event_info;

            event_info = (srv_sms_event_hide_list_struct*)event_data->event_info;

            if (event_info->list_type == SRV_SMS_BOX_ARCHIVE)
            {
                um_box_type = SRV_UM_MSG_BOX_ARCHIVE;
            }
            break;
        }

        default:
            break;
    }

    if (um_box_type != SRV_UM_MSG_BOX_NONE)
    {
        srv_um_refresh_ind_struct *refresh_ind;

        refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));

        refresh_ind->msg_type = SRV_UM_MSG_SMS;
        refresh_ind->msg_box_type = um_box_type;
        refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;

        VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);
    }
    return MMI_RET_OK;
}
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_get_icon_by_status
 * DESCRIPTION
 *  get sms icon id
 * PARAMETERS
 *  msg_type        [IN]        
 *  msg_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
extern "C" VfxU16 vapp_sms_get_icon_by_status(VfxU32 msg_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 msg_id = (VfxU16)(msg_status >> 16);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    return vapp_sms_get_msg_icon(msg_id);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_num_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  VfxBool
 *****************************************************************************/
static VfxBool vapp_sms_um_get_num_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_num_req_struct *req_data = (srv_um_get_msg_num_req_struct*)inMsg;
    VfxBool result = VFX_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_data->msg_type == SRV_UM_MSG_SMS)
    {
    #if (MMI_MAX_SIM_NUM >= 2)
        srv_um_sim_enum um_sim_id = req_data->sim_id;
    #else /* __MMI_DUAL_SIM_MASTER__ */
        srv_um_sim_enum um_sim_id = SRV_UM_SIM_ALL;
    #endif /* __MMI_DUAL_SIM_MASTER__ */
        srv_um_get_msg_num_rsp_struct *rsp_data;

        rsp_data = (srv_um_get_msg_num_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_get_msg_num_rsp_struct));

        rsp_data->result = KAL_TRUE; 
        rsp_data->msg_type = SRV_UM_MSG_SMS;

        vapp_sms_um_get_msg_num(rsp_data, um_sim_id);

        VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_NUM_RSP, rsp_data);
    }
    else
    {
        result = VFX_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  VfxBool
 *****************************************************************************/
static void vapp_sms_um_get_msg_num(
                srv_um_get_msg_num_rsp_struct *rsp_data,
                srv_um_sim_enum um_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 inbox_box_size;
    VfxU16 inbox_unread_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inbox_box_size = vapp_sms_um_get_box_size(SRV_UM_MSG_BOX_INBOX, um_sim_id);
    inbox_unread_num = vapp_sms_um_get_unread_msg_num(um_sim_id);

    rsp_data->inbox_unread_msg_number = inbox_unread_num;
    rsp_data->inbox_read_msg_number = inbox_box_size - inbox_unread_num;
    rsp_data->unsent_msg_number = vapp_sms_um_get_box_size(SRV_UM_MSG_BOX_UNSENT, um_sim_id);
    rsp_data->sent_msg_number = vapp_sms_um_get_box_size(SRV_UM_MSG_BOX_SENT, um_sim_id);
    rsp_data->draft_msg_number = vapp_sms_um_get_box_size(SRV_UM_MSG_BOX_DRAFT, um_sim_id);
#ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
    rsp_data->archive_msg_number = vapp_sms_um_get_box_size(SRV_UM_MSG_BOX_ARCHIVE, um_sim_id);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    rsp_data->sim_msg_number = vapp_sms_um_get_box_size(SRV_UM_MSG_BOX_SIM, um_sim_id);
#endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_list_info_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static VfxBool vapp_sms_um_get_list_info_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_list_req_struct *req_data = (srv_um_get_msg_list_req_struct*) (inMsg);
    VfxBool result = VFX_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_data->msg_type == SRV_UM_MSG_SMS)
    {
        srv_um_get_msg_list_rsp_struct *rsp_data;

        rsp_data = (srv_um_get_msg_list_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_get_msg_list_rsp_struct));

        rsp_data->msg_type = SRV_UM_MSG_SMS;
        rsp_data->msg_box_type = req_data->msg_box_type;
        rsp_data->start_entry = req_data->start_entry;
        rsp_data->result = (kal_bool)vapp_sms_um_get_msg_list_info_hdlr(rsp_data, req_data);

        VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_LIST_RSP, rsp_data);
    }
    else
    {
        result = VFX_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_msg_list_info_hdlr
 * DESCRIPTION
 *  get sms list info
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  start_entry         [IN]        
 *  max_msg_number      [IN]        
 *  msg_number          [?]         
 *  list_info           [?]         
 *  more                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static VfxBool vapp_sms_um_get_msg_list_info_hdlr(
                    srv_um_get_msg_list_rsp_struct *rsp_data,
                    srv_um_get_msg_list_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 list_index = req_data->start_entry;
    srv_sms_box_enum sms_box_type;
    VfxU16 msg_box_size;
    VfxU16 msg_count = 0;
#if (MMI_MAX_SIM_NUM >= 2)
    srv_um_sim_enum um_sim_id = req_data->sim_id;
    srv_sms_sim_enum sms_sim_id = SRV_SMS_SIM_1;
#endif /* __MMI_DUAL_SIM_MASTER__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_data->msg_box_type = req_data->msg_box_type;
    rsp_data->start_entry = list_index;

    sms_box_type = vapp_sms_um_um_box_to_sms(req_data->msg_box_type);
    msg_box_size = srv_sms_get_list_size(sms_box_type);       

#if (MMI_MAX_SIM_NUM >= 2)
    /* Get Start List Index */
    if (um_sim_id != SRV_UM_SIM_ALL)
    {
        VfxU16 i ;
        VfxU32 tmp_index = 0;

        if (um_sim_id == SRV_UM_SIM_GSM_SIM2)
        {
            sms_sim_id = SRV_SMS_SIM_2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        if (um_sim_id == SRV_UM_SIM_GSM_SIM3)
        {
            sms_sim_id = SRV_SMS_SIM_3;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        if (um_sim_id == SRV_UM_SIM_GSM_SIM4)
        {
            sms_sim_id = SRV_SMS_SIM_4;
        }
    #endif
        for (i = 0; i < msg_box_size; i++)
        {
            VfxU16 msg_id = srv_sms_get_msg_id(sms_box_type, i);
            
            if (srv_sms_get_msg_sim_id(msg_id) == sms_sim_id)
            {
                if (tmp_index == list_index)
                {
                    list_index = i;
                    break;
                }
                else
                {
                    tmp_index++;
                }
            }
        }
    }
#endif

    while (msg_count < SRV_UM_MAX_GET_MSG_LIST_NUMBER)
    {
        VfxU16 msg_id = srv_sms_get_msg_id(sms_box_type, list_index);

        if (msg_id != SRV_SMS_INVALID_MSG_ID)
        {
        #if (MMI_MAX_SIM_NUM >= 2)
            if ((um_sim_id == SRV_UM_SIM_ALL) ||
                (srv_sms_get_msg_sim_id(msg_id) == sms_sim_id))
        #endif /* __MMI_DUAL_SIM_MASTER__ */
            {
                vapp_sms_um_get_msg_list_info(
                    msg_id,
                    &rsp_data->list_info[msg_count],
                #ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
                    &rsp_data->list_idx_data[msg_count],
                    req_data->list_idx_type
                #else /* __UNIFIED_MESSAGE_LIST_INDEX_DATA__ */
                    NULL,
                    SRV_UM_LIST_IDX_TIMESTAMP
                #endif /* __UNIFIED_MESSAGE_LIST_INDEX_DATA__ */
                    );

                msg_count++;
            }
  
            list_index++;
        }
        else
        {
            break;
        }
    }

    rsp_data->msg_number = msg_count;

    if (list_index < msg_box_size)
    {
        rsp_data->more = KAL_TRUE;
    }
    else
    {
        rsp_data->more = KAL_FALSE;
    }

    return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_msg_list_info
 * DESCRIPTION
 *  get sms list info
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_get_msg_list_info(
                VfxU16 msg_id,
                srv_um_msg_list_struct *list_info,
                srv_um_list_idx_data_union *list_idx_data,
                srv_um_list_idx_enum list_idx_type)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_info->msg_id = msg_id;

    list_info->timestamp = srv_sms_get_msg_timestamp_utc_sec(msg_id);

#if (MMI_MAX_SIM_NUM >= 2)
    srv_sms_sim_enum sms_sim = srv_sms_get_msg_sim_id(msg_id);
    if (sms_sim == SRV_SMS_SIM_1)
    {
        list_info->sim_id = SRV_UM_SIM_GSM_SIM1;
    }
    if (sms_sim == SRV_SMS_SIM_2)
    {
        list_info->sim_id = SRV_UM_SIM_GSM_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    if (sms_sim == SRV_SMS_SIM_3)
    {
        list_info->sim_id = SRV_UM_SIM_GSM_SIM3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    if (sms_sim == SRV_SMS_SIM_4)
    {
        list_info->sim_id = SRV_UM_SIM_GSM_SIM4;
    }
#endif

#endif /* __MMI_DUAL_SIM_MASTER__ */

#ifdef __UNIFIED_MESSAGE_LIST_INDEX_DATA__
    switch(list_idx_type)
    {
        case SRV_UM_LIST_IDX_TIMESTAMP:
            break;

        case SRV_UM_LIST_IDX_MSG_SIZE:
            list_idx_data->msg_size = srv_sms_get_msg_size(msg_id);
            break;

        case SRV_UM_LIST_IDX_MSG_TYPE:
            list_idx_data->msg_type = SRV_UM_MSG_SMS;
            break;

        case SRV_UM_LIST_IDX_SUBJECT:
        {
            vapp_sms_um_get_msg_subject(
                list_idx_data->subject,
                msg_id,
                SRV_UM_MAX_LIST_INDEX_LEN);
            break;
        }

        case SRV_UM_LIST_IDX_ADDRESS:
        {
			srv_um_addr_enum addr_type;

			vapp_sms_um_get_msg_address(
				list_idx_data->address,
				&addr_type,
				msg_id,
				SRV_UM_MAX_LIST_INDEX_LEN);           	
            break;
        }

        case SRV_UM_LIST_IDX_READ_STATUS:
        {
            if ((srv_sms_get_msg_status(msg_id) & SRV_SMS_STATUS_UNREAD))
            {
                list_idx_data->read_status = KAL_FALSE;
            }
            else
            {
                list_idx_data->read_status = KAL_TRUE;
            }
            break;
        }

        default:
            MMI_ASSERT(0);
            break;
    }
#endif /* __UNIFIED_MESSAGE_LIST_INDEX_DATA__ */
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_msg_address
 * DESCRIPTION
 *  get sms list info
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_get_msg_address(
				VfxWChar *address,
				srv_um_addr_enum* addr_type,
				VfxU16 msg_id,
				VfxU32 address_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_mti_enum sms_mti;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_mti = srv_sms_get_msg_mti(msg_id);

    if (sms_mti == SRV_SMS_MTI_STATUS_REPORT)
    {
        *addr_type = SRV_UM_ADDR_PLAIN_TEXT;

        vfx_sys_wcsncpy((VfxWChar*)address, vfxSysResGetStr(STR_ID_VAPP_SMS_REPORT), address_len);
    }
    else
    {
        *addr_type = SRV_UM_ADDR_PHONE_NUMBER;
        srv_sms_get_msg_address(msg_id, (char*)address);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_msg_subject
 * DESCRIPTION
 *  get sms list info
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_get_msg_subject(
				VfxWChar *subject,
				VfxU16 msg_id,
				VfxU32 subject_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_status_enum msg_status;
#ifdef __MMI_SMS_PORT_MSG__
	VappSmsPortReg *portReg = VFX_OBJ_GET_INSTANCE(VappSmsPortReg);
	VfxU16 port;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	port = srv_sms_get_msg_port(msg_id);

	if (portReg->findPort(port))
	{
		const VfxWChar *app_name = portReg->getAppName(port);

        vfx_sys_wcsncpy(subject, app_name, subject_len);
	}
	else
#endif
	{
	    msg_status = srv_sms_get_msg_status(msg_id);
		const VfxWChar *content;

	    if (!srv_sms_is_msg_complete(msg_id))
	    {
			content = vfxSysResGetStr(STR_ID_VAPP_SMS_IMCOMPLETE);
	    }
	    else if (srv_sms_get_msg_mti(msg_id) == SRV_SMS_MTI_STATUS_REPORT)
	    {
			content = vfxSysResGetStr(STR_ID_VAPP_SMS_DELIVERY_REPORT);
	    }
	    else if (msg_status & SRV_SMS_STATUS_UNSUPPORTED)
	    {
			content = vfxSysResGetStr(STR_ID_VAPP_SMS_NOT_SUPPORT);
	    }
	    else
	    {
			content = (const VfxWChar*)srv_sms_get_msg_content(msg_id);
	    }

        vfx_sys_wcsncpy(subject, content, subject_len);
	}
    subject[subject_len] = '\0';
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_msg_info_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static VfxBool vapp_sms_um_get_msg_info_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_info_req_struct *req_data = (srv_um_get_msg_info_req_struct*)(inMsg);
    VfxBool result = VFX_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_data->msg_type == SRV_UM_MSG_SMS)
    {
        vapp_sms_um_get_msg_info_hdlr(req_data);
    }
    else
    {
        result = VFX_FALSE;
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_msg_info_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_get_msg_info_hdlr(srv_um_get_msg_info_req_struct *req_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_get_msg_info_req_struct *msgReq = req_data;
    srv_um_get_msg_info_rsp_struct *rsp_msg;
    VfxU16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_msg = (srv_um_get_msg_info_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_get_msg_info_rsp_struct));

    rsp_msg->app_id = msgReq->app_id;
    rsp_msg->msg_type = SRV_UM_MSG_SMS;
    rsp_msg->msg_box_type = msgReq->msg_box_type;
    rsp_msg->msg_number = msgReq->msg_number;

    for (i = 0; i < msgReq->msg_number; i++)
    {
        VfxU16 msg_id = (VfxU16)msgReq->msg_id[i];
        srv_um_msg_info_struct *msg_info = &rsp_msg->msg_info[i];

        rsp_msg->msg_id[i] = msg_id;
        rsp_msg->result[i] = (kal_bool)vapp_sms_um_get_msg_info_content(
                                        msg_info,
                                        msg_id,
                                        msgReq->msg_box_type);
    }

    VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_GET_MSG_INFO_RSP, rsp_msg);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_msg_info_content
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static VfxBool vapp_sms_um_get_msg_info_content(
                    srv_um_msg_info_struct *msg_info,
                    VfxU16 msg_id,
                    srv_um_msg_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxBool result = VFX_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_sms_is_msg_exist(msg_id))
    {
        vapp_sms_um_get_msg_common_info(msg_info, msg_id, msg_box_type);

		vapp_sms_um_get_msg_address(
			msg_info->address,
			&msg_info->address_type,
			msg_id,
			SRV_UM_MAX_ADDR_LEN);
        msg_info->address_length = vfx_sys_wcslen((VfxWChar*)msg_info->address);

		vapp_sms_um_get_msg_subject(msg_info->subject, msg_id, SRV_UM_MAX_SUBJECT_LEN);
        msg_info->subject_length = vfx_sys_wcslen((VfxWChar*)msg_info->subject);
    }
    else
    {
        result = VFX_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_msg_common_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_get_msg_common_info(
                srv_um_msg_info_struct *msg_info,
                VfxU16 msg_id,
                srv_um_msg_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_info->msg_id = msg_id;
    msg_info->timestamp = srv_sms_get_msg_timestamp_utc_sec(msg_id);
    //msg_info->timestamp = applib_dt_sec_local_to_utc(msg_info->timestamp);
    msg_info->icon_id = vapp_sms_get_msg_icon(msg_id);
    msg_info->msg_status = vapp_sms_um_get_msg_status(msg_id);

#if (MMI_MAX_SIM_NUM >= 2)
    srv_sms_sim_enum sms_sim = srv_sms_get_msg_sim_id(msg_id);
    if (sms_sim == SRV_SMS_SIM_1)
    {
        msg_info->sim_id = SRV_UM_SIM_GSM_SIM1;
    }
    if (sms_sim == SRV_SMS_SIM_2)
    {
        msg_info->sim_id = SRV_UM_SIM_GSM_SIM2;
    }
#if (MMI_MAX_SIM_NUM >= 3)
    if (sms_sim == SRV_SMS_SIM_3)
    {
        msg_info->sim_id = SRV_UM_SIM_GSM_SIM3;
    }
#endif
#if (MMI_MAX_SIM_NUM >= 4)
    if (sms_sim == SRV_SMS_SIM_4)
    {
        msg_info->sim_id = SRV_UM_SIM_GSM_SIM4;
    }
#endif

#endif /* __MMI_DUAL_SIM_MASTER__ */
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_del_folder_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inMsg       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static VfxBool vapp_sms_um_del_folder_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_folder_req_struct *req_data = (srv_um_delete_folder_req_struct*)inMsg;
    VfxBool result = VFX_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_data->msg_type == SRV_UM_MSG_SMS)
    {
        srv_um_msg_box_enum um_box_type = req_data->msg_box_type;
        VfxU32 sms_box_type = SRV_SMS_BOX_NONE;
        VfxU32 sim_id = SRV_SMS_SIM_1;

    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
        if (um_box_type & SRV_UM_MSG_BOX_ARCHIVE)
        {
            sms_box_type |= SRV_SMS_BOX_ARCHIVE;
        }   
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        if (um_box_type & SRV_UM_MSG_BOX_SIM)
        {
            sms_box_type |= SRV_SMS_BOX_SIM;
        }
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

        if (um_box_type & SRV_UM_MSG_BOX_INBOX)
        {
            sms_box_type |= SRV_SMS_BOX_INBOX;
        }

        if (um_box_type & SRV_UM_MSG_BOX_SENT)
        {
            sms_box_type |= SRV_SMS_BOX_OUTBOX;
        }

        if (um_box_type & SRV_UM_MSG_BOX_UNSENT)
        {
            sms_box_type |= SRV_SMS_BOX_UNSENT;
        }

        if (um_box_type & SRV_UM_MSG_BOX_DRAFT)
        {
            sms_box_type |= SRV_SMS_BOX_DRAFTS;
        }

    #if (MMI_MAX_SIM_NUM >= 2)
        if (req_data->sim_id == SRV_UM_SIM_ALL)
        {
            sim_id |= SRV_SMS_SIM_2;
        }
        if (req_data->sim_id == SRV_UM_SIM_GSM_SIM2)
        {
            sim_id = SRV_SMS_SIM_2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        if (req_data->sim_id == SRV_UM_SIM_GSM_SIM3)
        {
            sim_id = SRV_SMS_SIM_3;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        if (req_data->sim_id == SRV_UM_SIM_GSM_SIM4)
        {
            sim_id = SRV_SMS_SIM_4;
        }
    #endif
    #endif /* __MMI_DUAL_SIM_MASTER__ */

        if (sms_box_type != SRV_SMS_BOX_NONE)
        {
            vapp_sms_um_del_folder_struct *del_folder_cntx;

            del_folder_cntx = (vapp_sms_um_del_folder_struct*)OslMalloc(sizeof(vapp_sms_um_del_folder_struct));
    	
            del_folder_cntx->msg_box_type = um_box_type;

            srv_sms_delete_msg_list(
                (srv_sms_box_enum)sms_box_type,
                (srv_sms_sim_enum)sim_id,
                vapp_sms_um_del_folder_callback,
                del_folder_cntx);
        }
        else
        {
            vapp_sms_um_del_folder_hdlr(VFX_TRUE, um_box_type);
        }
    }
    else
    {
        result = VFX_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_del_folder_callback
 * DESCRIPTION
 *  delete sms msg box
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_del_folder_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_sms_um_del_folder_struct *del_folder_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    del_folder_cntx = (vapp_sms_um_del_folder_struct*)callback_data->user_data;

    vapp_sms_um_del_folder_hdlr((callback_data->result)? VFX_TRUE: VFX_FALSE, del_folder_cntx->msg_box_type);

    OslMfree(del_folder_cntx);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_del_folder_hdlr
 * DESCRIPTION
 *  delete sms msg box
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_del_folder_hdlr(VfxBool result, srv_um_msg_box_enum msg_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_delete_folder_rsp_struct *rsp_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp_data = (srv_um_delete_folder_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_delete_folder_rsp_struct));

    rsp_data->msg_type = SRV_UM_MSG_SMS;
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    if ((msg_box_type & SRV_UM_MSG_BOX_UNSENT) &&
        (srv_sms_get_list_size(SRV_SMS_BOX_UNSENT) != 0))
	{
	    rsp_data->result = KAL_FALSE;
	}
	else
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
	{
	    rsp_data->result = (kal_bool)result;
	}

    VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_DELETE_FOLDER_RSP, rsp_data);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_box_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static VfxU16 vapp_sms_um_get_box_size(srv_um_msg_box_enum um_box_type, srv_um_sim_enum um_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 box_size;
    srv_sms_box_enum sms_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_box_type = vapp_sms_um_um_box_to_sms(um_box_type);
    box_size = srv_sms_get_list_size(sms_box_type);

#if (MMI_MAX_SIM_NUM >= 2)
    if (um_sim_id != SRV_UM_SIM_ALL)
    {
        srv_sms_sim_enum sms_sim_id = SRV_SMS_SIM_1;
        VfxU16 real_num = 0;
        VfxU16 i;

        if (um_sim_id == SRV_UM_SIM_GSM_SIM1)
        {
            sms_sim_id = SRV_SMS_SIM_1;
        }
        if (um_sim_id == SRV_UM_SIM_GSM_SIM2)
        {
            sms_sim_id = SRV_SMS_SIM_2;
        }
    #if(MMI_MAX_SIM_NUM >= 3)
        if (um_sim_id == SRV_UM_SIM_GSM_SIM3)
        {
            sms_sim_id = SRV_SMS_SIM_3;
        }
    #endif
    #if(MMI_MAX_SIM_NUM >= 4)
        if (um_sim_id == SRV_UM_SIM_GSM_SIM4)
        {
            sms_sim_id = SRV_SMS_SIM_4;
        }
    #endif
        for (i = 0; i < box_size; i++)
        {
            VfxU16 msg_id = srv_sms_get_msg_id(sms_box_type, i);
        
            if (srv_sms_get_msg_sim_id(msg_id) == sms_sim_id)
            {
                real_num++;
            }
        }

        box_size = real_num;
    }
#endif /* __MMI_DUAL_SIM_MASTER__ */

    return box_size;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_unread_msg_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static VfxU16 vapp_sms_um_get_unread_msg_num(srv_um_sim_enum um_sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 uread_num;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    if (um_sim_id != SRV_UM_SIM_ALL)
    {
        VfxU16 i;
        VfxU16 inbox_total;
        srv_sms_sim_enum sms_sim_id = SRV_SMS_SIM_1;

        uread_num = 0;

        if (um_sim_id == SRV_UM_SIM_GSM_SIM1)
        {
            sms_sim_id = SRV_SMS_SIM_1;
        }
        if (um_sim_id == SRV_UM_SIM_GSM_SIM2)
        {
            sms_sim_id = SRV_SMS_SIM_2;
        }
    #if (MMI_MAX_SIM_NUM >= 3)
        if (um_sim_id == SRV_UM_SIM_GSM_SIM3)
        {
            sms_sim_id = SRV_SMS_SIM_3;
        }
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        if (um_sim_id == SRV_UM_SIM_GSM_SIM4)
        {
            sms_sim_id = SRV_SMS_SIM_4;
        }
    #endif
        inbox_total = srv_sms_get_list_size(SRV_SMS_BOX_INBOX);

        for (i = 0; i < inbox_total; i++)
        {
            VfxU16 msg_id = srv_sms_get_msg_id(SRV_SMS_BOX_INBOX, i);
        
            if (srv_sms_get_msg_sim_id(msg_id) == sms_sim_id)
            {
                uread_num++;   
                if (srv_sms_get_msg_status(msg_id) & SRV_SMS_STATUS_UNREAD)
                {
                    uread_num++;
                }
            }
        }
    }
    else
#endif /* __MMI_DUAL_SIM_MASTER__ */
    {
        uread_num = srv_sms_get_unread_sms_num();
    }

    return uread_num;
}


#ifdef __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_multi_op_req_hdlr
 * DESCRIPTION
 *  Handle UM multi-operate request
 * PARAMETERS
 *  in_msg		[IN] msg data
 * RETURNS
 *  void
 *****************************************************************************/
static VfxBool vapp_sms_um_multi_op_req_hdlr(void *in_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_mark_several_op_req_struct *req_msg = (srv_um_mark_several_op_req_struct*)in_msg;
    VfxBool result = VFX_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req_msg->msg_type == SRV_UM_MSG_SMS)
    {
        vapp_sms_um_multi_op_cntx_struct *cntx;

        cntx = (vapp_sms_um_multi_op_cntx_struct*)OslMalloc(sizeof(vapp_sms_um_multi_op_cntx_struct));

        vapp_sms_um_multi_op_init(cntx, req_msg);
        vapp_sms_um_multi_op_hdlr(cntx);
    }
    else
    {
        result = VFX_FALSE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_init_data
 * DESCRIPTION
 *  init the data for UM multi-operate
 * PARAMETERS
 *  in_msg		[IN] multi-operate request data	
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_multi_op_init(
                vapp_sms_um_multi_op_cntx_struct *cntx,
                srv_um_mark_several_op_req_struct *req_msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 i;
    VfxU16 total = req_msg->msg_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_ASSERT(total <= SRV_UM_MAX_MSG_PER_MARK_SEVERAL_OP);

    cntx->app_id = req_msg->app_id;
    cntx->um_box_type = req_msg->msg_box_type;
    cntx->action_type = req_msg->action_type;
    cntx->curr_index = 0;
    cntx->total_num = total;

    for (i = 0; i < total; i++)
    {
        cntx->msg_id[i] = (VfxU16)req_msg->msg_id[i];
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_msg_um_multi_op_delete
 * DESCRIPTION
 *  Handle UM delete multi message
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_multi_op_hdlr(vapp_sms_um_multi_op_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_mark_several_op_action_enum action_type = cntx->action_type;
    VfxBool is_continue = VFX_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (is_continue && (cntx->curr_index < cntx->total_num))
	{
    	VfxU16 msg_id = cntx->msg_id[cntx->curr_index];

        is_continue = VFX_FALSE;

        switch (action_type)
        {
            case SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE:
            {
                srv_sms_delete_msg(
                    msg_id,
                    vapp_sms_um_multi_op_callback,
                    cntx);
                break;
            }

        #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__
            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_ARCHIVE:
            {
                VfxBool is_valid = VFX_TRUE;
                srv_sms_mti_enum sms_mti;
                srv_sms_status_enum status;

                sms_mti = srv_sms_get_msg_mti(msg_id);
                status = srv_sms_get_msg_status(msg_id);

                if ((sms_mti == SRV_SMS_MTI_STATUS_REPORT) || 
                    (status & SRV_SMS_STATUS_UNSUPPORTED) ||
                    (status & SRV_SMS_STATUS_UNSENT) ||
                    (status & SRV_SMS_STATUS_DRAFT))
                {
                    is_valid = VFX_FALSE;
                }

                if (is_valid)
                {
                    srv_sms_copy_msg_to_archive(
            	        msg_id,
            	        vapp_sms_um_multi_op_callback,
            	        cntx);
                }
                else
                {
                    is_continue = VFX_TRUE;
                	cntx->result[cntx->curr_index] = VFX_FALSE;
                	cntx->curr_index++;
                }
                break;
            }
        #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__*/

        #ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_MEMORY_CARD:
            {
        	    srv_sms_copy_msg(
        	        msg_id,
        	        SRV_SMS_STORAGE_TCARD,
        	        vapp_sms_um_multi_op_callback,
        	        cntx);
                break;
            }
        #endif
        
        #ifdef __MMI_MESSAGES_COPY__
            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM:
            {
        	    srv_sms_copy_msg(
        	        msg_id,
        	        SRV_SMS_STORAGE_SIM,
        	        vapp_sms_um_multi_op_callback,
        	        cntx);
                break;
            }

            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_PHONE:
            {
        	    srv_sms_copy_msg(
        	        msg_id,
        	        SRV_SMS_STORAGE_ME,
        	        vapp_sms_um_multi_op_callback,
        	        cntx);
    	        break;
            }

            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM1:
            {
                srv_sms_copy_msg_ext(
        	        msg_id,
        	        SRV_SMS_STORAGE_SIM,
        	        SRV_SMS_SIM_1,
        	        vapp_sms_um_multi_op_callback,
        	        cntx);
                break;
            }

            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM2:
            {
                srv_sms_copy_msg_ext(
        	        msg_id,
        	        SRV_SMS_STORAGE_SIM,
        	        SRV_SMS_SIM_2,
        	        vapp_sms_um_multi_op_callback,
        	        cntx);
                break;
            }

        #if (MMI_MAX_SIM_NUM >= 3)
            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM3:
            {
                srv_sms_copy_msg_ext(
                    msg_id,
                    SRV_SMS_STORAGE_SIM,
                    SRV_SMS_SIM_3,
                    vapp_sms_um_multi_op_callback,
                    cntx);
                break;
            }
        #endif

        #if (MMI_MAX_SIM_NUM >= 4)
            case SRV_UM_MARK_SEVERAL_OP_ACTION_COPY_TO_SIM4:
            {
                srv_sms_copy_msg_ext(
                    msg_id,
                    SRV_SMS_STORAGE_SIM,
                    SRV_SMS_SIM_4,
                    vapp_sms_um_multi_op_callback,
                    cntx);
                break;
            }
        #endif

        #endif /* __MMI_MESSAGES_COPY__ */

            default:
            {
                is_continue = VFX_TRUE;
            	cntx->result[cntx->curr_index] = VFX_FALSE;
            	cntx->curr_index++;
                break;
            }
        }
	}

	if (cntx->curr_index == cntx->total_num)
	{
		vapp_sms_um_multi_op_send_rsp_to_um(cntx);
        OslMfree(cntx);
	}
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_multi_op_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dummy       [?]         
 *  mod         [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_multi_op_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vapp_sms_um_multi_op_cntx_struct *cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx = (vapp_sms_um_multi_op_cntx_struct*)callback_data->user_data;

	cntx->result[cntx->curr_index] = ((callback_data->result)?VFX_TRUE: VFX_FALSE);
	cntx->curr_index++;

    vapp_sms_um_multi_op_hdlr(cntx);
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_multi_op_send_rsp_to_um
 * DESCRIPTION
 *  Send mulit operate respone to UM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_multi_op_send_rsp_to_um(vapp_sms_um_multi_op_cntx_struct *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_mark_several_op_rsp_struct *rsp_msg;
    VfxU16 i;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	rsp_msg = (srv_um_mark_several_op_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_mark_several_op_rsp_struct));

	rsp_msg->msg_type = SRV_UM_MSG_SMS;
	rsp_msg->app_id = cntx->app_id;
	rsp_msg->msg_box_type = cntx->um_box_type;
	rsp_msg->action_type = cntx->action_type;
	rsp_msg->msg_number = cntx->total_num;

    for (i = 0; i < cntx->total_num; i++)
    {
        rsp_msg->msg_id[i] = cntx->msg_id[i];
        rsp_msg->action_result[i] = (kal_bool)cntx->result[i];
    }
	
    VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_MARK_SEVERAL_OP_RSP, rsp_msg);
}
#endif /* __UNIFIED_MESSAGE_MARK_SEVERAL_SUPPORT__ */


#ifdef __SRV_UM_THREAD_MESSAGE_SUPPORT__
#ifdef LOW_COST_SUPPORT 
/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_traverse_msg_req_hdlr
 * DESCRIPTION
 *  When open conversation box, um will need several boxes messges.
 * PARAMETERS
 *  inMsg       [IN]: Request structure from UM    
 * RETURNS
 *  void
 *****************************************************************************/
static VfxBool vapp_sms_um_traverse_msg_req_hdlr_async(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_traverse_msg_req_struct *msgReq = (srv_um_traverse_msg_req_struct*)inMsg;
    VfxBool result = VFX_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (msgReq->msg_type != SRV_UM_MSG_SMS)
    {
        result = VFX_FALSE;
    }
    else
    {
	    if ((msgReq->msg_box_type == SRV_UM_MSG_BOX_PREDEF_TEMPLATES)
	        || (msgReq->msg_box_type == SRV_UM_MSG_BOX_PREDEF_TEMPLATES))
	    {
	        MMI_ASSERT(0);
	    }
		vapp_sms_um_traverse_msg_context *context = vapp_sms_um_create_and_init_msg_context(msgReq);
	    result = vapp_sms_um_traverse_msg_async(context);
    }

    return result;
}




static vapp_sms_um_traverse_msg_context *vapp_sms_um_create_and_init_msg_context(srv_um_traverse_msg_req_struct *msgReq)
{
	vapp_sms_um_traverse_msg_context *context = (vapp_sms_um_traverse_msg_context *)OslMalloc(sizeof(vapp_sms_um_traverse_msg_context));
	memset(context, 0, sizeof(vapp_sms_um_traverse_msg_context));

	if (msgReq->start_entry < 0)
	{
		context->total_msg_count = msgReq->msg_number;
		context->curr_index = 0;
	}
	else
	{
        srv_sms_box_enum sms_msg_box_type = vapp_sms_um_um_box_to_sms(msgReq->msg_box_type);
        context->total_msg_count = srv_sms_get_list_size(sms_msg_box_type);   
        context->curr_index = (VfxU16)msgReq->start_entry;
	}

	context->is_continue = VFX_TRUE;
	context->complete_msg_count = 0;
	context->is_more = VFX_TRUE;
	context->result = VFX_TRUE;

	context->req_info.app_id = msgReq->app_id;
	context->req_info.msg_type= msgReq->msg_type;
	context->req_info.start_entry = msgReq->start_entry;
	context->req_info.msg_number= msgReq->msg_number;
	context->req_info.msg_box_type = msgReq->msg_box_type;
	context->req_info.field = msgReq->field;
	context->req_info.traverse_func = msgReq->traverse_func;
	context->req_info.user_data = msgReq->user_data;


	for (VfxS32 index = 0; index < SRV_UM_MAX_TRAVERSE_MSG_NUMBER; index++)
	{
		context->req_info.msg_id[index] = msgReq->msg_id[index];
	}
	
    context->detail_info.subject = (kal_wchar*)OslMalloc((SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar));
    context->detail_info.address.addr = (kal_wchar*)OslMalloc((SRV_SMS_MAX_ADDR_LEN + 1) * sizeof(kal_wchar));
	return context;
	
	
}

static void vapp_sms_um_get_content_callback(srv_sms_callback_struct* callback_data)
{
	
    /*----------------------------------------------------------------*/
    vapp_sms_um_traverse_msg_context *context = (vapp_sms_um_traverse_msg_context *)callback_data->user_data;

	if (callback_data->result)
	{
	    srv_sms_get_msg_content_async_cb_struct *get_content_cb = (srv_sms_get_msg_content_async_cb_struct*)callback_data->action_data;
		srv_um_msg_detail_struct *msg_info = &context->detail_info;


        VfxS32 len = mmi_ucs2strlen((char*)get_content_cb->content);
        if (SRV_UM_MAX_SUBJECT_LEN < len)
        { 
            len = SRV_UM_MAX_SUBJECT_LEN;
        }
        mmi_ucs2ncpy((char*)msg_info->subject, get_content_cb->content, len);	
	
	}

	VfxS32 traverse_ret = context->req_info.traverse_func(context->req_info.user_data, &context->detail_info);
	switch (traverse_ret)
	{
        case SRV_UM_RESULT_OK:
        	context->curr_index++;
			context->complete_msg_count++;
            break;

        case SRV_UM_RESULT_BUFFER_FULL:
        	context->is_continue = VFX_FALSE;
            break;
		default:
			MMI_ASSERT(0);
			break;
	}
#ifdef __SRV_SMS_MULTI_ADDR__
	vapp_sms_um_free_multi_addr_buffer(context->detail_info.address.next);
#endif /* __SRV_SMS_MULTI_ADDR__ */
	vapp_sms_um_traverse_msg_async(context);
}

static VfxBool vapp_sms_um_check_msg_subject(
				vapp_sms_um_traverse_msg_context *context,
				VfxU16 msg_id,
				VfxU32 subject_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VfxWChar *subject = context->detail_info.subject;
    srv_sms_status_enum msg_status = SRV_SMS_STATUS_NONE;
#ifdef __MMI_SMS_PORT_MSG__
	VappSmsPortReg *portReg = VFX_OBJ_GET_INSTANCE(VappSmsPortReg);
	VfxU16 port = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	port = srv_sms_get_msg_port(msg_id);
	if (portReg->findPort(port))
	{
		const VfxWChar *app_name = portReg->getAppName(port);

        vfx_sys_wcsncpy(subject, app_name, subject_len);
	}
	else
#endif
	{
	    msg_status = srv_sms_get_msg_status(msg_id);
		const VfxWChar *content = NULL;
	    if (!srv_sms_is_msg_complete(msg_id))
	    {
			content = vfxSysResGetStr(STR_ID_VAPP_SMS_IMCOMPLETE);
	    }
	    else if (srv_sms_get_msg_mti(msg_id) == SRV_SMS_MTI_STATUS_REPORT)
	    {
			content = vfxSysResGetStr(STR_ID_VAPP_SMS_DELIVERY_REPORT);
	    }
	    else if (msg_status & SRV_SMS_STATUS_UNSUPPORTED)
	    {
			content = vfxSysResGetStr(STR_ID_VAPP_SMS_NOT_SUPPORT);
	    }
	    else
	    {
			srv_sms_get_msg_content_async(msg_id, vapp_sms_um_get_content_callback, context);
			return VFX_FALSE;
	    }

        vfx_sys_wcsncpy(subject, content, subject_len);
	}
    subject[subject_len] = '\0';
	return VFX_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_traverse_msg_sync
 * DESCRIPTION
 *  UM traverse message to get msg list info.
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  start_entry         [IN]        
 *  msg_number          [OUT]
 *  msg_id_set          [IN]
 *  sim_id              [IN]
 *  more                [OUT]
 *  field               [IN]
 *  traverse_func       [IN]
 *  user_data           [IN]
 * RETURNS
 *  KAL_TRUE
 *  KAL_FALSE
 *****************************************************************************/
static VfxBool vapp_sms_um_traverse_msg_async(
					vapp_sms_um_traverse_msg_context *context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_traverse_msg_req_struct *msgReq = &context->req_info;
    srv_um_msg_detail_struct *msg_detail = &context->detail_info;

    if (context->is_continue && (context->curr_index < context->total_msg_count))
    {
	    VfxU16 msg_id = 0;
	    VfxS32 traverse_ret = 0;
	    srv_sms_status_enum msg_status = SRV_SMS_STATUS_NONE;
        srv_sms_box_enum curr_box_type = SRV_SMS_BOX_NONE;

	    if (msgReq->start_entry < 0)
	    {
			MMI_ASSERT(context->curr_index < SRV_UM_MAX_TRAVERSE_MSG_NUMBER);
	        msg_id = (VfxU16)msgReq->msg_id[context->curr_index];
		}
		else
		{
			msg_id = srv_sms_get_msg_id(vapp_sms_um_um_box_to_sms(msgReq->msg_box_type), context->curr_index);
		}

		VFX_ASSERT(msg_id != SRV_SMS_INVALID_MSG_ID);
		srv_sms_sim_enum sms_sim = srv_sms_get_msg_sim_id(msg_id);
	#ifdef __MMI_DUAL_SIM_MASTER__
		msg_detail->sim_id = vapp_sms_sim_id_to_um_sim(sms_sim);
	#endif
        msg_detail->msg_type = SRV_UM_MSG_SMS;
        msg_detail->msg_id = msg_id;
        srv_sms_get_msg_list_index(&curr_box_type, msg_id);
        msg_detail->msg_box_type = vapp_sms_um_sms_box_to_um(curr_box_type);
        msg_detail->msg_status = vapp_sms_um_get_msg_status(msg_id);
        msg_detail->timestamp = srv_sms_get_msg_timestamp_utc_sec(msg_id);
        msg_detail->msg_size = srv_sms_get_msg_size(msg_id);

        /* Get message status */
        msg_status = srv_sms_get_msg_status(msg_id);

        if (msg_status & SRV_SMS_STATUS_UNREAD)
        {
            msg_detail->read_status = KAL_FALSE;
        }
        else
        {
            msg_detail->read_status = KAL_TRUE;
        }

        if (msg_status != SRV_SMS_STATUS_NONE)
        {
		    vapp_sms_um_get_traverse_msg_addr(&msg_detail->address, msg_id);
		    VfxBool is_getContent = vapp_sms_um_check_msg_subject(context, msg_id, SRV_UM_MAX_SUBJECT_LEN);
			if (is_getContent)
			{
		        traverse_ret = msgReq->traverse_func(msgReq->user_data, msg_detail);

				switch (traverse_ret)
				{
			        case SRV_UM_RESULT_OK:
			        	context->curr_index++;
						context->complete_msg_count++;
			            break;

			        case SRV_UM_RESULT_BUFFER_FULL:
			        	context->is_continue = VFX_FALSE;
			            break;
					default:
						MMI_ASSERT(0);
						break;
				}
			#ifdef __SRV_SMS_MULTI_ADDR__
				vapp_sms_um_free_multi_addr_buffer(context->detail_info.address.next);
			#endif /* __SRV_SMS_MULTI_ADDR__ */
				vapp_sms_um_traverse_msg_async(context);
			}			
    }
        else
        {
            srv_um_refresh_ind_struct *refresh_ind;

            refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));
            refresh_ind->msg_type = SRV_UM_MSG_SMS;
            refresh_ind->msg_box_type = SRV_UM_MSG_BOX_ALL;
            refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;
            VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);
			context->is_more = VFX_FALSE;
			context->result = VFX_FALSE;
			context->is_continue = VFX_FALSE;
			vapp_sms_um_traverse_msg_async(context);
}

    }
	else
	{
		if (context->curr_index == context->total_msg_count)
		{
    		context->is_more = VFX_FALSE;
		}
    	vapp_sms_um_free_traverse_msg_buffer(msg_detail);
		vapp_sms_um_send_traverse_msg_rsp(context->req_info.app_id, context->complete_msg_count, context->is_more, context->result);
		OslMfree(context);
	}
    return VFX_TRUE;
}
#else /* LOW_COST_SUPPORT */

/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_traverse_msg_req_hdlr
 * DESCRIPTION
 *  When open conversation box, um will need several boxes messges.
 * PARAMETERS
 *  inMsg       [IN]: Request structure from UM    
 * RETURNS
 *  void
 *****************************************************************************/
static VfxBool vapp_sms_um_traverse_msg_req_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_traverse_msg_req_struct *msgReq = (srv_um_traverse_msg_req_struct*)inMsg;
    VfxBool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    if (msgReq->msg_type != SRV_UM_MSG_SMS)
    {
        result = VFX_FALSE;
    }
    else
    {
	    VfxU16 msg_number;
	    VfxBool more;

	    if ((msgReq->msg_box_type == SRV_UM_MSG_BOX_PREDEF_TEMPLATES)
	        || (msgReq->msg_box_type == SRV_UM_MSG_BOX_PREDEF_TEMPLATES))
	    {
	        MMI_ASSERT(0);
	    }

	    result = vapp_sms_um_traverse_msg(msgReq, &msg_number, &more);

	    vapp_sms_um_send_traverse_msg_rsp(msgReq->app_id, msg_number, more, result);
    }

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_traverse_msg
 * DESCRIPTION
 *  UM traverse message to get msg list info.
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  start_entry         [IN]        
 *  msg_number          [OUT]
 *  msg_id_set          [IN]
 *  sim_id              [IN]
 *  more                [OUT]
 *  field               [IN]
 *  traverse_func       [IN]
 *  user_data           [IN]
 * RETURNS
 *  KAL_TRUE
 *  KAL_FALSE
 *****************************************************************************/
static VfxBool vapp_sms_um_traverse_msg(
					srv_um_traverse_msg_req_struct *msgReq,
                    VfxU16 *msg_number,
                    VfxBool *more)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS16 start_entry = msgReq->start_entry;
	VfxU16 msg_total;
	VfxU16 msg_count = 0;
    VfxU16 list_index;
    srv_um_msg_box_enum um_box_type = msgReq->msg_box_type;
    srv_sms_box_enum sms_msg_box_type = SRV_SMS_BOX_NONE;
    srv_um_msg_detail_struct msg_detail;
	VfxBool is_continue = VFX_TRUE;
	VfxBool result = VFX_TRUE;
    srv_um_traverse_func traverse_func = msgReq->traverse_func; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *more = KAL_TRUE;

    if (start_entry < 0)
    {
		msg_total = msgReq->msg_number;
		list_index = 0;
    }
	else
    {
        sms_msg_box_type = vapp_sms_um_um_box_to_sms(um_box_type);
        msg_total = srv_sms_get_list_size(sms_msg_box_type);   
        list_index = (VfxU16)start_entry;
    }
    
    memset(&msg_detail, 0, sizeof(srv_um_msg_detail_struct));
    msg_detail.subject = (kal_wchar*)OslMalloc((SRV_UM_MAX_SUBJECT_LEN + 1) * sizeof(kal_wchar));
    msg_detail.address.addr = (kal_wchar*)OslMalloc((SRV_SMS_MAX_ADDR_LEN + 1) * sizeof(kal_wchar));

    while (is_continue && (list_index < msg_total))
    {
	    VfxU16 msg_id;
	    VfxS32 traverse_ret;
	    srv_sms_status_enum msg_status;
        srv_sms_box_enum curr_box_type;

	    if (start_entry < 0)
	    {
			MMI_ASSERT(list_index < SRV_UM_MAX_TRAVERSE_MSG_NUMBER);
	        msg_id = (VfxU16)msgReq->msg_id[list_index];
		}
		else
		{
			msg_id = srv_sms_get_msg_id(sms_msg_box_type, list_index);
		}

		VFX_ASSERT(msg_id != SRV_SMS_INVALID_MSG_ID);
        srv_sms_sim_enum sms_sim = srv_sms_get_msg_sim_id(msg_id);
	#ifdef __MMI_DUAL_SIM_MASTER__	
		    msg_detail.sim_id = vapp_sms_sim_id_to_um_sim(sms_sim);
	#endif
        msg_detail.msg_type = SRV_UM_MSG_SMS;
        msg_detail.msg_id = msg_id;
        srv_sms_get_msg_list_index(&curr_box_type, msg_id);
        msg_detail.msg_box_type = vapp_sms_um_sms_box_to_um(curr_box_type);
        msg_detail.msg_status = vapp_sms_um_get_msg_status(msg_id);
        msg_detail.timestamp = srv_sms_get_msg_timestamp_utc_sec(msg_id);
        msg_detail.msg_size = srv_sms_get_msg_size(msg_id);

        /* Get message status */
        msg_status = srv_sms_get_msg_status(msg_id);

        if (msg_status & SRV_SMS_STATUS_UNREAD)
        {
            msg_detail.read_status = KAL_FALSE;
        }
        else
        {
            msg_detail.read_status = KAL_TRUE;
        }

        if (msg_status != SRV_SMS_STATUS_NONE)
        {
		    vapp_sms_um_get_traverse_msg_addr(&msg_detail.address, msg_id);
		    vapp_sms_um_get_msg_subject(msg_detail.subject, msg_id, SRV_UM_MAX_SUBJECT_LEN);      
            traverse_ret = traverse_func(msgReq->user_data, &msg_detail);
        }
        else
        {
            srv_um_refresh_ind_struct *refresh_ind;

            refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));

            refresh_ind->msg_type = SRV_UM_MSG_SMS;
            refresh_ind->msg_box_type = SRV_UM_MSG_BOX_ALL;
            refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;

            VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);

            traverse_ret = SRV_UM_RESULT_CANCELLLED;
        }

        switch (traverse_ret)
        {
            case SRV_UM_RESULT_OK:
		        list_index++;
        		msg_count++;
                break;

            case SRV_UM_RESULT_BUFFER_FULL:
            	is_continue = VFX_FALSE;
                break;

            case SRV_UM_RESULT_CANCELLLED:
            	is_continue = VFX_FALSE;
                *more = KAL_FALSE;
            	result = KAL_FALSE;
                break;

            default:
                MMI_ASSERT(0);
                break;
        }

	#ifdef __SRV_SMS_MULTI_ADDR__
		vapp_sms_um_free_multi_addr_buffer(msg_detail.address.next);
	#endif /* __SRV_SMS_MULTI_ADDR__ */
    }

	if (list_index == msg_total)
	{
		*more = KAL_FALSE;
	}

    vapp_sms_um_free_traverse_msg_buffer(&msg_detail);

    *msg_number = msg_count;

    return result;
}
#endif /* LOW_COST_SUPPORT */

/***********************************************************************************
 * FUNCTION
 *  vapp_sms_um_send_traverse_msg_rsp
 * DESCRIPTION
 *  Send MSG_ID_MMI_UM_TRAVERSE_MSG_RSP response back to UM
 * PARAMETERS
 *  app_id       [IN]: app id
 *  more         [IN]: Info um that whether there has more sms need to handle or not    
 *  result       [IN]: Info um traverse msg result
 * RETURNS
 *  void
 ***********************************************************************************/
void vapp_sms_um_send_traverse_msg_rsp(VfxU32 app_id, VfxU32 msg_number, VfxBool more, VfxBool result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_traverse_msg_rsp_struct *msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    msg = (srv_um_traverse_msg_rsp_struct*)OslConstructDataPtr(sizeof(srv_um_traverse_msg_rsp_struct));
    msg->msg_type = SRV_UM_MSG_SMS;
    msg->app_id   = app_id;
    msg->msg_number = msg_number;
    msg->more = (kal_bool)more;
    msg->result = (kal_bool)result;
    VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_TRAVERSE_MSG_RSP, msg);
}




/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_traverse_msg_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
static void vapp_sms_um_get_traverse_msg_addr(
				srv_um_addr_struct* um_addr,
				U16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sms_status_enum status;
#ifdef __SRV_SMS_MULTI_ADDR__
	U32 addr_num;
	U32 count = 0;
	srv_um_addr_struct* curr_addr = um_addr;
	srv_um_addr_struct* prev_addr = NULL;
#endif /* __SRV_SMS_MULTI_ADDR__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_MULTI_ADDR__
	addr_num = srv_sms_get_msg_addr_num(msg_id);

	do
	{
		if (count > 0)
		{
			curr_addr = (srv_um_addr_struct*)OslMalloc(sizeof(srv_um_addr_struct));
    		curr_addr->addr = (kal_wchar*)OslMalloc((SRV_SMS_MAX_ADDR_LEN + 1) * sizeof(kal_wchar));
		}

		curr_addr->previous = NULL;
		curr_addr->next = NULL;

    	srv_sms_get_msg_multi_addr(curr_addr->addr, &status, msg_id, count);

	    if (curr_addr->addr[0] && (!applib_is_valid_number_unicode(um_addr->addr)))
	    {
	        curr_addr->type = SRV_UM_ADDR_PLAIN_TEXT;
	    }
	    else
	    {
		    curr_addr->type = SRV_UM_ADDR_PHONE_NUMBER;
	    }

	    if ((status & SRV_SMS_STATUS_UNREAD) || (status & SRV_SMS_STATUS_READ))
	    {
	        curr_addr->group = SRV_UM_ADDR_GROUP_FROM;
	    }
	    else
	    {
			curr_addr->group = SRV_UM_ADDR_GROUP_TO;
	    }

		if (prev_addr)
		{
			prev_addr->next = curr_addr;
			curr_addr->previous = prev_addr;
		}

		prev_addr = curr_addr;

		count++;
	} while (count < addr_num);

#else /* __SRV_SMS_MULTI_ADDR__ */
    um_addr->previous = NULL;
    um_addr->next = NULL;

	srv_sms_get_msg_address(msg_id, (char*)um_addr->addr);

    status = srv_sms_get_msg_status(msg_id);

    if (um_addr->addr[0] && (!applib_is_valid_number_unicode(um_addr->addr)))
    {
        um_addr->type = SRV_UM_ADDR_PLAIN_TEXT;
    }
    else
    {
	    um_addr->type = SRV_UM_ADDR_PHONE_NUMBER;
    }

    if ((status & SRV_SMS_STATUS_UNREAD) || (status & SRV_SMS_STATUS_READ))
    {
        um_addr->group = SRV_UM_ADDR_GROUP_FROM;
    }
    else
    {
		um_addr->group = SRV_UM_ADDR_GROUP_TO;
    }
#endif /* __SRV_SMS_MULTI_ADDR__ */
}

#ifdef __SRV_SMS_MULTI_ADDR__
/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_free_traverse_msg_buffer
 * DESCRIPTION
 *  Free the control buffer for traverse msg.
 * PARAMETERS
 *  sms_traverse_cntx   [IN]: buffer need to free.
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_free_multi_addr_buffer(srv_um_addr_struct* um_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_addr_struct* curr_addr = um_addr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (curr_addr)
    {
		srv_um_addr_struct* free_addr = curr_addr;

		curr_addr = curr_addr->next;

		if (free_addr->addr)
		{
			OslMfree(free_addr->addr);
		}

		OslMfree(free_addr);
    }
}
#endif /* __SRV_SMS_MULTI_ADDR__ */


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_free_traverse_msg_buffer
 * DESCRIPTION
 *  Free the control buffer for traverse msg.
 * PARAMETERS
 *  sms_traverse_cntx   [IN]: buffer need to free.
 * RETURNS
 *  void
 *****************************************************************************/
static void vapp_sms_um_free_traverse_msg_buffer(srv_um_msg_detail_struct *msg_detail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msg_detail->subject != NULL)
    {
        OslMfree(msg_detail->subject);
    }

    if (msg_detail->address.addr != NULL)
    {
        OslMfree(msg_detail->address.addr);
    }
}
#endif /* __SRV_UM_THREAD_MESSAGE_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_msg_status
 * DESCRIPTION
 *  get msg status for UM
 * PARAMETERS
 *  msg_id          [IN]    Msg ID        
 * RETURNS
 *  VappSmsUmStatusEnum
 *****************************************************************************/
static VfxU32 vapp_sms_um_get_msg_status(VfxU16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU32 msg_status = SMS_UM_STATUS_NONE;
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_box_enum msg_box_tpye;
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    srv_sms_get_msg_list_index(&msg_box_tpye, msg_id);

    if (msg_box_tpye == SRV_SMS_BOX_UNSENT)
    {
        srv_sms_send_status_enum unsent_status;

        unsent_status = srv_sms_get_unsent_msg_status(msg_id);

        switch (unsent_status)
        {
            case SRV_SMS_SEND_WAITING:
                msg_status = SMS_UM_STATUS_SEND_WAITING;
                break;

            case SRV_SMS_SEND_FAIL:
                msg_status = SMS_UM_STATUS_SEND_FAIL;
                break;

            case SRV_SMS_SEND_SENDING:
                msg_status = SMS_UM_STATUS_SEND_SENDING;
                break;

            default:
                MMI_ASSERT(0);
                break;
        }
    }
    else
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */
    {
        VfxU32 sms_status;

        sms_status = srv_sms_get_msg_status(msg_id);

        sms_status &= (~SRV_SMS_STATUS_UNSUPPORTED);

        switch (sms_status)
        {
            case SRV_SMS_STATUS_UNREAD:
                msg_status = SMS_UM_STATUS_UNREAD;
                break;

            case SRV_SMS_STATUS_READ:
                msg_status = SMS_UM_STATUS_READ;
                break;

            case SRV_SMS_STATUS_SENT:
                msg_status = SMS_UM_STATUS_SENT;
                break;

            case SRV_SMS_STATUS_DRAFT:
                msg_status = SMS_UM_STATUS_DRAFT;
                break;

            case SRV_SMS_STATUS_UNSENT:
            default:
                msg_status = SMS_UM_STATUS_UNSENT;
                break;
        }
    }

	msg_status |= (msg_id << 16);

    return msg_status;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_get_msg_icon
 * DESCRIPTION
 *  get sms icon id
 * PARAMETERS
 *  msg_type        [IN]        
 *  msg_index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static VfxU16 vapp_sms_get_msg_icon(VfxU16 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxU16 icon_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    VfxU32 status;
		status = srv_sms_get_msg_status(msg_id);
    status &= (~SRV_SMS_STATUS_UNSUPPORTED);
		if (status == SRV_SMS_STATUS_UNSENT)
		{
	        srv_sms_send_status_enum unsent_status;
	        unsent_status = srv_sms_get_unsent_msg_status(msg_id);
			if (unsent_status == SRV_SMS_SEND_FAIL)
			{
				icon_id = IMG_ID_VAPP_SMS_SEND_FAIL;
			}
        return icon_id;
		}
#endif /* __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__ */

#ifdef __MMI_SMS_PORT_MSG__
    VappSmsPortReg *portReg = VFX_OBJ_GET_INSTANCE(VappSmsPortReg);
    VfxU16 port;
    port = srv_sms_get_msg_port(msg_id);
    if (portReg->findPort(port))
	{
		icon_id = portReg->getAppImageResId(port);
    }
#endif
    return icon_id;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_get_box_type
 * DESCRIPTION
 *  convert the SMS box type to UM type
 * PARAMETERS
 *  msg_box_type        [IN]  	sms app box type      
 * RETURNS
 *  void
 *****************************************************************************/
static srv_um_msg_box_enum vapp_sms_um_get_box_type(
                            srv_sms_status_enum status_type, 
                            srv_sms_folder_enum folder_type,
                            srv_sms_storage_enum storage_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_msg_box_enum um_box_type;
    srv_sms_box_enum sms_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sms_box_type = srv_sms_get_list_type(status_type, storage_type, folder_type);

    um_box_type = vapp_sms_um_sms_box_to_um(sms_box_type);

	return um_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_um_box_to_sms
 * DESCRIPTION
 *  convert the UM box type to SMS type
 * PARAMETERS
 *  msg_box_type        [IN]     UM Box type   
 * RETURNS
 *  void
 *****************************************************************************/
static srv_sms_box_enum vapp_sms_um_um_box_to_sms(srv_um_msg_box_enum um_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_sms_box_enum sms_box_type = SRV_SMS_BOX_NONE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (um_box_type)
    {
        case SRV_UM_MSG_BOX_INBOX:
            sms_box_type = SRV_SMS_BOX_INBOX;
            break;

        case SRV_UM_MSG_BOX_UNSENT:
            sms_box_type = SRV_SMS_BOX_UNSENT;
            break;

        case SRV_UM_MSG_BOX_SENT:
            sms_box_type = SRV_SMS_BOX_OUTBOX;
            break;

        case SRV_UM_MSG_BOX_DRAFT:
            sms_box_type = SRV_SMS_BOX_DRAFTS;
            break;

    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
        case SRV_UM_MSG_BOX_ARCHIVE:
            sms_box_type = SRV_SMS_BOX_ARCHIVE;
            break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_UM_MSG_BOX_SIM:
            sms_box_type = SRV_SMS_BOX_SIM;
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    #ifdef __MMI_UM_REPORT_BOX__
        case SRV_UM_MSG_BOX_REPORT:
            sms_box_type = SRV_SMS_BOX_REPORT;
            break;
    #endif /* __MMI_UM_REPORT_BOX__ */

        default:
        {
            break;
        }
    }

	return sms_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_sms_um_sms_box_to_um
 * DESCRIPTION
 *  convert the SMS box type to UM type
 * PARAMETERS
 *  msg_box_type        [IN]  	sms app box type      
 * RETURNS
 *  void
 *****************************************************************************/
static srv_um_msg_box_enum vapp_sms_um_sms_box_to_um(srv_sms_box_enum sms_box_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_um_msg_box_enum um_box_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (sms_box_type)
    {
        case SRV_SMS_BOX_INBOX:
            um_box_type = SRV_UM_MSG_BOX_INBOX;
            break;

        case SRV_SMS_BOX_UNSENT:
            um_box_type = SRV_UM_MSG_BOX_UNSENT;
            break;

        case SRV_SMS_BOX_OUTBOX:
            um_box_type = SRV_UM_MSG_BOX_SENT;
            break;

        case SRV_SMS_BOX_DRAFTS:
            um_box_type = SRV_UM_MSG_BOX_DRAFT;
            break;

    #ifdef __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__        
        case SRV_SMS_BOX_ARCHIVE:
            um_box_type = SRV_UM_MSG_BOX_ARCHIVE;
            break;
    #endif /* __UNIFIED_MESSAGE_ARCHIVE_SUPPORT__ */

    #ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
        case SRV_SMS_BOX_SIM:
            um_box_type = SRV_UM_MSG_BOX_SIM;
            break;
    #endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */

    #ifdef __MMI_UM_REPORT_BOX__
        case SRV_SMS_BOX_REPORT:
            um_box_type = SRV_UM_MSG_BOX_REPORT;
            break;
    #endif /* __MMI_UM_REPORT_BOX__ */

        default:
        {
            um_box_type = SRV_UM_MSG_BOX_NONE;
            break;
        }
    }

	return um_box_type;
}
#endif /* __MOD_SMSAL__ */

