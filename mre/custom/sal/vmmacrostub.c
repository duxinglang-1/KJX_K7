/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * vmmacrostub.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * 
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "mmi_features.h"
#include "vmswitch.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"

#include "DevConfigGprot.h"
#include "mdi_audio.h"
#include "med_main.h"
#include "Browser_api.h"
#include "kal_general_types.h"
#include "SST_secure.h"

#include "mdi_video.h"
#include "MMI_features.h"

#include "custom_phb_config.h"
#include "customer_email_num.h"
#include "GlobalConstants.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "MMIDataType.h"
#include "device.h"
#include "app_ltlcom.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "stack_common.h"
#include "string.h"
#include "lcd_if.h"
#include "DtcntSrvGprot.h"

#include "vmsys.h"
#include "vmmacrostub.h"

#include "vmstdlib.h"

#include "vmchset.h"
#include "vmpromng.h"
#include "vmvideo.h"
#include "vmtel.h"
#include "vmcell.h"
#include "vmbitstream.h"
#include "vmmm.h"
#include "vmgps.h"
#include "vmmms.h"
#include "vmlog.h"
#include "mdi_bitstream.h" 
#include "vmdl.h"
#include "vmgettag.h"
#include "vmcert.h"
#include "vmpromnginner.h"
#include "ModeSwitchSrvGProt.h"
#include "wgui_editor.h"
#include "vmeditor.h"

#define CHIPID_LENGTH		16





/**
 * SOC MOD FUNCTION
 */
VMINT stub_tcp_is_support_wifi(void)
{
#ifdef __MMI_WLAN_FEATURES__
	return TRUE;
#else
	return FALSE;
#endif
}


VMINT vm_wlan_get_status(void)
{
#ifdef __MMI_WLAN_FEATURES__
    if (srv_dtcnt_wlan_status() == SRV_DTCNT_WLAN_STATUS_CONNECTED)
    {
        return TRUE;
    }
#endif /* __MMI_WLAN_FEATURES__ */ 
    
    return FALSE;
}

/**
 * SOC MOD FUNCTION END
 */
 
#if defined(__USB_IN_NORMAL_MODE__)
extern kal_bool srv_usb_is_in_mass_storage_mode(void);
#endif
VMINT stub_mmi_usb_is_in_mass_storage_mode(void)
{
#ifdef __USB_IN_NORMAL_MODE__
	return srv_usb_is_in_mass_storage_mode();
#else
	return FALSE;
#endif
}

extern U8 mmi_gpio_get_current_battery_level(void);
VMINT stub_vm_get_battery_level(void)
{
if((mmi_gpio_get_current_battery_level()-BATTERY_LEVEL_0) < 0)
	{
		return 0;
		}
#ifdef BAT_4_LEVEL_
	return (mmi_gpio_get_current_battery_level()  - BATTERY_LEVEL_0) * 25;
#else
	if ((mmi_gpio_get_current_battery_level()  - BATTERY_LEVEL_0) * 33 == 99)
		return 100;
	else
		return (mmi_gpio_get_current_battery_level()  - BATTERY_LEVEL_0) * 33;
#endif
}

/*
 * GPS Mod Function From vmsalgps.c start
 */
extern VMINT mre_running;

/*
 * GPS Mod Function From vmsalgps.c end
 */

/*
 * MMS Mod Function From vmsalmms.c start
 */
#ifdef __MRE_SAL_MMS__
#include "mms_sap_struct.h"
#include "mms_sap.h"
#include "MmsSrvGprot.h"
#include "vmlog.h"
#include "vmstdlib.h"

extern  vm_mms_callback_type  vm_sal_mms_user_callback;
extern VMINT s_vm_sal_mms_sendstate;
extern VMUINT s_vm_sal_sim_id;
extern VMINT s_vm_sal_send_mms_cancel;
extern VMINT s_vm_sal_create_mms_success;
extern VMUINT s_vm_sal_cur_mms_msg_id;

 #ifdef __MMI_MMS_2__
static void vm_sal_mms_process_create_res(srv_mms_result_enum result, void *rsp_data, void *user_data);
static void vm_sal_mms_process_send_res(srv_mms_result_enum result, void *rsp_data, void *user_data);

static VMINT vm_sal_mms_send_req(VMUINT8 app_id, VMUINT msg_id);
static VMINT vm_sal_delete_mms_req(VMUINT msg_id);
#endif


VMINT vm_sal_mms_create_req(vm_send_mms_req_t * req)
{
#ifdef __MMI_MMS_2__
    srv_mms_create_req_struct req_struct;
    
    if(req == NULL)
	{
	    return VM_MMS_FAIL;
 	}	
    if (0 == req->xml_size)
    {
        vm_sal_mms_process_create_res(SRV_MMS_RESULT_FAIL,NULL,NULL);
    }
    memset(&req_struct,0,sizeof(req_struct));
    req_struct.app_id = MMI_MMS_VENDOR_CVM_APP_ID;
    req_struct.xml_size = req->xml_size;
    vm_wstrncpy((VMWSTR)req_struct.xml_filepath, (VMWSTR)req->xml_filepath, MMS_VENDOR_MAX_INTERNAL_FILENAME_LENGTH);
    req_struct.sim_id = req->sim_id;
    s_vm_sal_sim_id = req->sim_id;
    req_struct.mode = req->mms_type == MMI_MMS_VENDOR_TYPE_MIXED_MMS?MMA_MODE_MIXED:MMA_MODE_EDIT;
    req_struct.call_back = vm_sal_mms_process_create_res;
    srv_mms_create(&req_struct);
    vm_log_debug("vm_sal_mms_create_req:end!");
    return VM_MMS_SUCCESS;
    
#else
	vm_log_error("vm_sal_mms_create_req:mms is not valid");
	return VM_MMS_FAIL;
#endif

}

#ifdef __MMI_MMS_2__
static void vm_sal_mms_process_create_res(srv_mms_result_enum result, void *rsp_data, void *user_data)
{
	VMINT create_result;
    srv_mms_create_rsp_struct* rsp_struct_p = rsp_data;
    
	vm_log_debug("vm_sal_mms_process_create_res:start!");
	vm_log_debug("vm_sal_mms_process_create_res:result = %d", result);
	
	if(mre_running == FALSE)
	{
		return;
	}
 	switch(result)
 	{
   	case SRV_MMS_RESULT_FAIL:
		create_result = VM_MMS_FAIL;
	   	break;
 	case SRV_MMS_RESULT_OK:
 	  	create_result = VM_MMS_SUCCESS;  
	   	vm_log_debug("vm_sal_mms_process_create_res: res->app_id=%d, res->msg_id=%d", rsp_struct_p->app_id, rsp_struct_p->msg_id);
		s_vm_sal_create_mms_success = TRUE;
		s_vm_sal_cur_mms_msg_id = rsp_struct_p->msg_id;
		if(s_vm_sal_send_mms_cancel == TRUE)
		{
			create_result = VM_MMS_CANCEL;  
			if(vm_sal_delete_mms_req(rsp_struct_p->msg_id) < 0)
            {
             	vm_log_error("vm_sal_mms_process_create_res:cancel msg fail !");
          	}
		}
		else
		{
			if(vm_sal_mms_send_req(rsp_struct_p->app_id, rsp_struct_p->msg_id) < 0)
     		{
     			create_result = VM_MMS_FAIL; 	
	    		if(vm_sal_delete_mms_req(rsp_struct_p->msg_id) < 0)
             	{
             		vm_log_error("vm_sal_mms_process_create_res:cancel msg fail !");
          		}
     		}	 
		}
	  	break;
 	case SRV_MMS_RESULT_INSUFFICIENT_MEMORY:
        create_result = VM_MMS_MEMORY_NOT_ENOUGH;
	  	break;
 	default:
	   	create_result = VM_MMS_FAIL;
	   	break;
	}
		
	if(create_result != VM_MMS_SUCCESS)
  	{        
  		if(vm_sal_mms_user_callback != NULL)
		{
			s_vm_sal_create_mms_success = FALSE;
			s_vm_sal_send_mms_cancel = FALSE;
			vm_sal_mms_user_callback(create_result);
		}
	    s_vm_sal_mms_sendstate = FALSE;
  	}

   	vm_log_debug("vm_sal_mms_process_create_res:end!");
}

static VMINT vm_sal_mms_send_req(VMUINT8 app_id, VMUINT msg_id)
{
#ifdef __MMI_MMS_VENDOR_APP_SUPPORT__
	srv_mms_immed_send_req_struct req_struct;
	srv_mms_immed_send_rsp_struct rsp_struct;
    S32 result;

    vm_log_debug("vm_sal_mms_send_req:start!");
    
    req_struct.app_id = (U8)MMI_MMS_VENDOR_CVM_APP_ID;
    req_struct.msg_id = msg_id;
    req_struct.sim_id = s_vm_sal_sim_id;
    req_struct.call_back = vm_sal_mms_process_send_res;
    result = srv_mms_immed_send(&req_struct);
    vm_log_debug("vm_sal_mms_send_req:end!");

    if (result)
    {
        rsp_struct.app_id = app_id;
        rsp_struct.msg_id = msg_id;
        rsp_struct.result = MMI_FALSE;
        vm_sal_mms_process_send_res(SRV_MMS_RESULT_FAIL,&rsp_struct,NULL);
        return VM_MMS_FAIL;
    }
    return VM_MMS_SUCCESS;
#else
    return VM_MMS_FAIL;
#endif
}


static void vm_sal_mms_process_send_res(srv_mms_result_enum result, void *rsp_data, void *user_data)
{
	VMINT send_result;
    VMUINT msg_id;
    srv_mms_immed_send_rsp_struct * rsp_struct_p = rsp_data;
    
	vm_log_debug("vm_sal_mms_process_send_res:start!");
	vm_log_debug("vm_sal_mms_process_send_res:start result=%d", result); 
	
	if(mre_running == FALSE)
	{
		return;
	}
	
 	switch(result)
 	{
 		case SRV_MMS_RESULT_FAIL:
		    send_result = VM_MMS_FAIL;
	   	    break;
     	case SRV_MMS_RESULT_OK:
            send_result = VM_MMS_SUCCESS;    		 
    	   	break;
     	case SRV_MMS_RESULT_INSUFFICIENT_MEMORY:
            send_result = VM_MMS_MEMORY_NOT_ENOUGH;
    	   	break;
        default:
           	send_result = VM_MMS_FAIL;
           	break;
    } 
    
	msg_id = rsp_struct_p->msg_id;
	vm_log_debug("vm_sal_mms_process_send_res: msg_id=%d", rsp_struct_p->msg_id);
	
	if(vm_sal_delete_mms_req(msg_id) < 0)
 	{
 		vm_log_error("vm_sal_mms_process_send_res:vm_sal_delete_mms_req fail !");
 	}
 
		
    if(vm_sal_mms_user_callback != NULL)
	{
		s_vm_sal_create_mms_success = FALSE;
		s_vm_sal_send_mms_cancel = FALSE;
		vm_sal_mms_user_callback(send_result);
	}
 	s_vm_sal_mms_sendstate = FALSE;
	vm_log_debug("vm_sal_mms_process_send_res:end!"); 
}

static VMINT vm_sal_delete_mms_req(VMUINT msg_id)
{
    U8 result;	 
    vm_log_debug("vm_sal_delete_mms_req:start!");
    
    srv_mms_delete_msg(msg_id,&result);
    vm_log_debug("vm_sal_delete_mms_req:end! result = %d",result);
    
    if (result)
    {
        return VM_MMS_FAIL;
    }
    return VM_MMS_SUCCESS;
}

#endif/*__MMI_MMS_2__*/
void vm_sal_stub_mms_cancel_send_mms(void)
{
#ifdef __MMI_MMS_2__
	vm_log_debug("vm_sal_stub_mms_cancel_send_mms:start!");
	if (s_vm_sal_mms_sendstate == TRUE)
	{
	    //we can not cancel while sending,just cancel before sending and after ceate
		s_vm_sal_send_mms_cancel = TRUE;
	}
	vm_log_debug("vm_sal_stub_mms_cancel_send_mms:send cancel msg end!");
#endif
}
#endif
/*
 * MMS Mod Function From vmsalmms.c end
 */

/*
 * CELL Mod Function From vmsalcell.c start
 */
 #ifdef __NBR_CELL_INFO__
#include "CommonScreens.h"
#include "conversions.h"
#include "As2l4c_struct.h"
#endif
#include "vmsalcell.h"
#ifdef __NBR_CELL_INFO__
static void vm_sal_cell_reg_rsp(l4c_nbr_cell_info_ind_struct *msg_ptr);
static VMINT vm_sal_stub_cell_send_msg(msg_type msg_id);
#endif
extern vm_cell_info_struct* s_vm_sal_cur_cell_info;
extern vm_cell_info_struct* s_vm_sal_nbr_cell_info[VM_SAL_CELL_NBR_MAX];
extern VMINT s_vm_sal_cell_nbr_num;
VMINT vm_sal_stub_cell_reg_req(void)
{
#ifdef __NBR_CELL_INFO__
	
	SetProtocolEventHandler(vm_sal_cell_reg_rsp, MSG_ID_L4C_NBR_CELL_INFO_REG_CNF);
	SetProtocolEventHandler(vm_sal_cell_reg_rsp, MSG_ID_L4C_NBR_CELL_INFO_IND);

	if (vm_sal_stub_cell_send_msg(MSG_ID_L4C_NBR_CELL_INFO_REG_REQ))
	{
		return 1;
	}
	else
	{
		return 0;
	}
#else
	return 0;
#endif
}
VMINT vm_sal_stub_cell_dereg_req(void)
{
#ifdef __NBR_CELL_INFO__
	
	ClearProtocolEventHandler(MSG_ID_L4C_NBR_CELL_INFO_IND);
	ClearProtocolEventHandler(MSG_ID_L4C_NBR_CELL_INFO_REG_CNF);

	if (vm_sal_stub_cell_send_msg(MSG_ID_L4C_NBR_CELL_INFO_DEREG_REQ))
	{
		return 1;
	}
	else
	{
		return 1;
	}
#else
	return 0;
#endif
}

#ifdef __NBR_CELL_INFO__

static VMINT vm_sal_stub_cell_send_msg(msg_type msg_id)
{
#ifdef __MMI_DUAL_SIM__
    oslModuleType type = MOD_L4C;
    VMINT sim = 1;
    sim = vm_sim_get_active_sim_card();
    if (1 == sim)
    {
        type = MOD_L4C;
    }
    else if(2 == sim)
    {
        type = MOD_L4C_2;
    }    
    mmi_frm_send_ilm(type, msg_id, NULL, NULL);
#else
    mmi_frm_send_ilm(MOD_L4C, msg_id, NULL, NULL);
#endif
		return 1;
}

static void vm_sal_cell_reg_rsp(l4c_nbr_cell_info_ind_struct *msg_ptr)
{
	gas_nbr_cell_info_struct cell_info;
	VMINT i;

	vm_log_debug("vm_sal_cell_reg_rsp");
	if (mre_running == FALSE)
	{
     		return;
  	}
	if(msg_ptr)
	{
		if (KAL_TRUE == msg_ptr->is_nbr_info_valid)
		{
			memcpy((void *)&cell_info, (void *)(&(msg_ptr->ps_nbr_cell_info_union.gas_nbr_cell_info)), sizeof(gas_nbr_cell_info_struct));
		}
		else
		{
			memset((void *)&cell_info, 0, sizeof(gas_nbr_cell_info_struct));    
		}
	
		s_vm_sal_cur_cell_info->arfcn = cell_info.nbr_meas_rslt.nbr_cells[cell_info.serv_info.nbr_meas_rslt_index].arfcn;
		s_vm_sal_cur_cell_info->bsic = cell_info.nbr_meas_rslt.nbr_cells[cell_info.serv_info.nbr_meas_rslt_index].bsic;
		s_vm_sal_cur_cell_info->rxlev = cell_info.nbr_meas_rslt.nbr_cells[cell_info.serv_info.nbr_meas_rslt_index].rxlev;
		s_vm_sal_cur_cell_info->mcc = cell_info.serv_info.gci.mcc;
		s_vm_sal_cur_cell_info->mnc = cell_info.serv_info.gci.mnc;
		s_vm_sal_cur_cell_info->lac = cell_info.serv_info.gci.lac;
		s_vm_sal_cur_cell_info->ci = cell_info.serv_info.gci.ci;
		s_vm_sal_cell_nbr_num = cell_info.nbr_cell_num;
		vm_log_debug("vm_sal_cell_reg_rsp s_vm_sal_cell_nbr_num = %d",s_vm_sal_cell_nbr_num);

		for(i = 0; i < cell_info.nbr_cell_num; i++)
		{
			s_vm_sal_nbr_cell_info[i]->arfcn = cell_info.nbr_meas_rslt.nbr_cells[cell_info.nbr_cell_info[i].nbr_meas_rslt_index].arfcn;
			s_vm_sal_nbr_cell_info[i]->bsic = cell_info.nbr_meas_rslt.nbr_cells[cell_info.nbr_cell_info[i].nbr_meas_rslt_index].bsic;
			s_vm_sal_nbr_cell_info[i]->rxlev = cell_info.nbr_meas_rslt.nbr_cells[cell_info.nbr_cell_info[i].nbr_meas_rslt_index].rxlev;
			s_vm_sal_nbr_cell_info[i]->mcc = cell_info.nbr_cell_info[i].gci.mcc;
			s_vm_sal_nbr_cell_info[i]->mnc = cell_info.nbr_cell_info[i].gci.mnc;
			s_vm_sal_nbr_cell_info[i]->lac = cell_info.nbr_cell_info[i].gci.lac;
			s_vm_sal_nbr_cell_info[i]->ci = cell_info.nbr_cell_info[i].gci.ci;
		}
//		mmi_free_msg_local_para(msg_ptr);
	}
}
#endif/*__NBR_CELL_INFO__*/
/*
 * CELL Mod Function From vmsalcell.c end
 */






/* PHB START*/
#ifdef __MRE_SAL_PHONEBOOK__

#include "vmcontact.h"
#include "PhbSrvGprot.h"

extern vm_phb_storage_loc_enum vm_sal_phb_trans_storage_ex(phb_storage_enum storage);
void  vm_phb_build_contact_ptr(vm_phb_contact_struct* contact, srv_phb_sdk_contact_struct * contact_ptr)	
{
	if(contact == NULL || contact_ptr == NULL)
	{
		vm_log_error("vm_phb_build_contact_ptr:contact == NULL || contact_ptr == NULL");        
		return;
	}
	contact->pos.index =(vm_phb_storage_loc_enum)contact_ptr->pos.index;
	contact->pos.storage = (vm_phb_storage_loc_enum)vm_sal_phb_trans_storage_ex((phb_storage_enum)contact_ptr->pos.storage);
		 
	vm_wstrncpy((VMWSTR)contact->name, (VMWSTR)contact_ptr->name, VM_MAX_PHB_NAME_LENGTH);
	vm_wstrncpy((VMWSTR)contact->number, (VMWSTR)contact_ptr->number, VM_MAX_PHB_NUMBER_LENGTH + 1);
		 
	#ifdef __MMI_PHB_OPTIONAL_FIELD__
	vm_wstrncpy((VMWSTR)contact->home_number, (VMWSTR)contact_ptr->home_number, VM_MAX_PHB_NUMBER_LENGTH + 1);
	vm_wstrncpy((VMWSTR)contact->office_number, (VMWSTR)contact_ptr->office_number, VM_MAX_PHB_NUMBER_LENGTH + 1);
	vm_wstrncpy((VMWSTR)contact->fax_number, (VMWSTR)contact_ptr->fax_number, VM_MAX_PHB_NUMBER_LENGTH + 1);
	vm_wstrncpy((VMWSTR)contact->email_address, (VMWSTR)contact_ptr->email_address, VM_MAX_PHB_EMAIL_LENGTH );
	//vm_log_debug("vm_phb_build_contact_ptr:contact->office_number=%s", vm_gb2312_string((VMWSTR)contact->office_number));
	//vm_log_debug("vm_phb_build_contact_ptr:contact->fax_number=%s", vm_gb2312_string((VMWSTR)contact->fax_number));
		 
	#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
	vm_wstrncpy((VMWSTR)contact->email_address2, (VMWSTR)contact_ptr->email_address2, VM_MAX_PHB_EMAIL_LENGTH );
	#endif
		 
	vm_wstrncpy((VMWSTR)contact->company_name, (VMWSTR)contact_ptr->company_name, VM_MAX_PHB_COMPANY_LENGTH);
	#endif

	#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
	contact->birth_day = contact_ptr->birth_day;
	contact->birth_mon = contact_ptr->birth_mon;
	contact->birth_year = contact_ptr->birth_year;
	//vm_log_debug("vm_phb_build_contact_ptr:contact->birth_day=%d, contact->birth_mon=%d, contact->birth_year=%d",contact->birth_day, contact->birth_mon, contact->birth_year);
	#endif
		 
	#if defined(__MMI_PHB_INFO_FIELD__)
	vm_wstrncpy((VMWSTR)contact->title, (VMWSTR)contact_ptr->title, VM_MAX_PHB_TITLE_LENGTH); 
	vm_wstrncpy((VMWSTR)contact->url, (VMWSTR)contact_ptr->url, VM_MAX_PHB_URL_LENGTH); 
	vm_wstrncpy((VMWSTR)contact->adr_pobox, (VMWSTR)contact_ptr->adr_pobox, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_extension, (VMWSTR)contact_ptr->adr_extension, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_street, (VMWSTR)contact_ptr->adr_street, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_city, (VMWSTR)contact_ptr->adr_city, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_state, (VMWSTR)contact_ptr->adr_state, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_postal_code, (VMWSTR)contact_ptr->adr_postal_code, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_country, (VMWSTR)contact_ptr->adr_country, VM_MAX_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->note, (VMWSTR)contact_ptr->note, VM_MAX_PHB_NOTE_LENGTH);
	#endif
		 
	contact->group_mask = contact_ptr->group_mask;
		 

	vm_log_debug("vm_phb_build_contact_ptr:user_phb_contact->pos.index =%d",contact->pos.index);
	vm_log_debug("vm_phb_build_contact_ptr:user_phb_contact->pos.storage=%d",contact->pos.storage);
	//vm_log_debug("vm_phb_build_contact_ptr:user_phb_contact->name=%s", vm_gb2312_string((VMWSTR)contact->name));
	//vm_log_debug("vm_phb_build_contact_ptr:user_phb_contact->num=%s", vm_gb2312_string((VMWSTR)contact->number));
	   
}

void  vm_phb_build_contact(srv_phb_sdk_contact_struct * contact ,  vm_phb_contact_struct* contact_ptr)	
{
        if(contact == NULL || contact_ptr == NULL)
        {
                vm_log_error("vm_phb_build_contact:contact == NULL || contact_ptr == NULL");        
		  return;
        }
       vm_wstrncpy((VMWSTR)contact->name, (VMWSTR)contact_ptr->name, MMI_PHB_NAME_LENGTH);
	vm_wstrncpy((VMWSTR)contact->number, (VMWSTR)contact_ptr->number, MMI_PHB_NUMBER_PLUS_LENGTH);
	#ifdef __MMI_PHB_OPTIONAL_FIELD__
	vm_wstrncpy((VMWSTR)contact->home_number, (VMWSTR)contact_ptr->home_number, MMI_PHB_NUMBER_PLUS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->office_number, (VMWSTR)contact_ptr->office_number, MMI_PHB_NUMBER_PLUS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->fax_number, (VMWSTR)contact_ptr->fax_number,MMI_PHB_NUMBER_PLUS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->email_address, (VMWSTR)contact_ptr->email_address, MMI_PHB_EMAIL_LENGTH);
	//vm_log_debug("vm_phb_build_contact:contact->office_number=%s", vm_gb2312_string((VMWSTR)contact->office_number));
	//vm_log_debug("vm_phb_build_contact:contact->fax_number=%s", vm_gb2312_string((VMWSTR)contact->fax_number));
	
	#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
       vm_wstrncpy((VMWSTR)contact->email_address2, (VMWSTR)contact_ptr->email_address2, MMI_PHB_EMAIL_LENGTH);
	#endif
	
	vm_wstrncpy((VMWSTR)contact->company_name, (VMWSTR)contact_ptr->company_name, MMI_PHB_COMPANY_LENGTH);
	#endif	

	#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
  	contact->birth_day = contact_ptr->birth_day;
	contact->birth_mon = contact_ptr->birth_mon;
	contact->birth_year = contact_ptr->birth_year;
	//vm_log_debug("vm_phb_build_contact:contact->birth_day=%d, contact->birth_mon=%d, contact->birth_year=%d",contact->birth_day, contact->birth_mon, contact->birth_year);
	#endif
	
       #if defined(__MMI_PHB_INFO_FIELD__)
	vm_wstrncpy((VMWSTR)contact->title, (VMWSTR)contact_ptr->title, MMI_PHB_TITLE_LENGTH);
	vm_wstrncpy((VMWSTR)contact->url, (VMWSTR)contact_ptr->url, MMI_PHB_URL_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_pobox, (VMWSTR)contact_ptr->adr_pobox, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_extension, (VMWSTR)contact_ptr->adr_extension, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_street, (VMWSTR)contact_ptr->adr_street, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_city, (VMWSTR)contact_ptr->adr_city, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_state, (VMWSTR)contact_ptr->adr_state, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_postal_code, (VMWSTR)contact_ptr->adr_postal_code, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->adr_country, (VMWSTR)contact_ptr->adr_country, MMI_PHB_ADDRESS_LENGTH);
	vm_wstrncpy((VMWSTR)contact->note, (VMWSTR)contact_ptr->note, MMI_PHB_NOTE_LENGTH);
	#endif
	contact->group_mask = contact_ptr->group_mask;

	// vm_log_debug("vm_phb_build_contact:contact->name=%s", vm_gb2312_string((VMWSTR)contact->name));
	 //vm_log_debug("vm_phb_build_contact:contact->number=%s", vm_gb2312_string((VMWSTR)contact->number));

	return;

}

#endif //__MRE_SAL_PHONEBOOK__
/* PHB END*/

#ifndef __MMI_TOUCH_SCREEN__
void mmi_pen_reset(void)
{
	return;
}
void mmi_pen_register_down_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
void mmi_pen_register_up_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
void mmi_pen_register_move_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
void mmi_pen_register_long_tap_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
void mmi_pen_register_double_click_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
void mmi_pen_register_repeat_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
void mmi_pen_register_abort_handler(mmi_pen_hdlr pen_fp)
{
	return;
}
#endif

#include "vmio.h"
/**********chenkang 20100203add for qwerty keypad begin***********/
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
#define VM_SUPPORT_KEY_CODE_NUM			(69 + 2)
#else
#define VM_SUPPORT_KEY_CODE_NUM			(23 + 2)
#endif
/**********chenkang 20100203add for qwerty keypad end***********/

static short vmtransSysKey2mre [2][VM_SUPPORT_KEY_CODE_NUM] = {
	{
		KEY_LEFT_ARROW, 
		KEY_RIGHT_ARROW, 
		KEY_UP_ARROW, 
		KEY_DOWN_ARROW,
		KEY_ENTER, 
		KEY_LSK, 
		KEY_RSK, 
		KEY_0, 
		KEY_1, 
		KEY_2, 
		KEY_3, 
		KEY_4, 
		KEY_5, 
		KEY_6, 
		KEY_7, 
		KEY_8, 
		KEY_9, 
		KEY_STAR, 
		KEY_POUND,
		KEY_VOL_UP, 
		KEY_VOL_DOWN,
		KEY_CLEAR,
		KEY_BACK,
		KEY_HOME,
		KEY_END
		/**********chenkang 20100203add for qwerty keypad begin***********/
		#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    		,KEY_A ,
    		KEY_B,
    		KEY_C,
    		KEY_D,
    		KEY_E,
    		KEY_F,
    		KEY_G,
    		KEY_H,
    		KEY_I,
    		KEY_J,
    		KEY_K,
    		KEY_L,
    		KEY_M,
    		KEY_N,
    		KEY_O,
    		KEY_P,
    		KEY_Q,
    		KEY_R,
    		KEY_S,
    		KEY_T,
    		KEY_U,
    		KEY_V,
    		KEY_W,
    		KEY_X,
    		KEY_Y,
    		KEY_Z,
    		KEY_SPACE,
    		KEY_TAB,
    		KEY_DEL,
    		KEY_ALT,
    		KEY_CTRL,
    		KEY_WIN,
    		KEY_SHIFT,
    		KEY_QUESTION,
    		KEY_PERIOD,
    		KEY_COMMA,
    		KEY_EXCLAMATION,
    		KEY_APOSTROPHE,
    		KEY_AT,
    		KEY_BACKSPACE,
    		KEY_QWERTY_ENTER,
    		KEY_FN,
    		KEY_SYMBOL,
    		KEY_NUM_LOCK,
    		KEY_QWERTY_MENU,
    		KEY_OK,
		#endif /* __QWERTY_KEYPAD_SUPPORT__ */
/**********chenkang 20100203add for qwerty keypad end***********/
	},
	{
		VM_KEY_LEFT,
		VM_KEY_RIGHT,
		VM_KEY_UP,
		VM_KEY_DOWN,
		VM_KEY_OK,
		VM_KEY_LEFT_SOFTKEY,
		VM_KEY_RIGHT_SOFTKEY,
		VM_KEY_NUM0,
		VM_KEY_NUM1,
		VM_KEY_NUM2,
		VM_KEY_NUM3,
		VM_KEY_NUM4,
		VM_KEY_NUM5,
		VM_KEY_NUM6,
		VM_KEY_NUM7,
		VM_KEY_NUM8,
		VM_KEY_NUM9,
		VM_KEY_STAR,
		VM_KEY_POUND,
		VM_KEY_VOL_UP,
		VM_KEY_VOL_DOWN,
		VM_KEY_CLEAR,
		VM_KEY_BACK,
		VM_KEY_HOME,
		VM_KEY_END
/**********chenkang 20100203add for qwerty keypad begin***********/
		#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    		,VM_KEY_A ,
    		VM_KEY_B,
    		VM_KEY_C,
    		VM_KEY_D,
    		VM_KEY_E,
    		VM_KEY_F,
    		VM_KEY_G,
    		VM_KEY_H,
    		VM_KEY_I,
    		VM_KEY_J,
    		VM_KEY_K,
    		VM_KEY_L,
    		VM_KEY_M,
    		VM_KEY_N,
    		VM_KEY_O,
    		VM_KEY_P,
    		VM_KEY_Q,
    		VM_KEY_R,
    		VM_KEY_S,
    		VM_KEY_T,
    		VM_KEY_U,
    		VM_KEY_V,
    		VM_KEY_W,
    		VM_KEY_X,
    		VM_KEY_Y,
    		VM_KEY_Z,
    		VM_KEY_SPACE,
    		VM_KEY_TAB,
    		VM_KEY_DEL,
    		VM_KEY_ALT,
    		VM_KEY_CTRL,
    		VM_KEY_WIN,
    		VM_KEY_SHIFT,
    		VM_KEY_QUESTION,
    		VM_KEY_PERIOD,
    		VM_KEY_COMMA,
    		VM_KEY_EXCLAMATION,
    		VM_KEY_APOSTROPHE,
    		VM_KEY_AT,
    		VM_KEY_BACKSPACE,
    		VM_KEY_QWERTY_ENTER,
    		VM_KEY_FN,
    		VM_KEY_SYMBOL,
    		VM_KEY_NUM_LOCK,
    		VM_KEY_QWERTY_MENU,
    		VM_KEY_OK,
		#endif /* __QWERTY_KEYPAD_SUPPORT__ */
/**********chenkang 20100203add for qwerty keypad end***********/
	}
};
extern VMINT vm_pmng_deal_key_event(VMINT vmKeyCode, VMINT vmKeyEvent);
extern _vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MRE_LIB_EDITOR__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/**********chenkang 20100203add for qwerty keypad begin***********/
#include "mmi_frm_input_gprot.h"
static VMINT16 s_vm_usc2_value;
static VMINT s_vm_special_key_flag;

VMINT vm_sys_qwerty_keypad_is_open(void)
{
#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
	return TRUE;
#else
	return FALSE;
#endif
}
void vm_sys_get_usc2_and_special_key(VMINT16* ucs2_value,VMINT* special_key_flag )
{
	if (ucs2_value==NULL || special_key_flag==NULL)
	{
		return;
	}
	*ucs2_value = s_vm_usc2_value;
	*special_key_flag = s_vm_special_key_flag;
}

#include "vmpromnginner.h"
extern _vm_pcb_t ** vm_pmng_get_pcb_ptr();
MMI_BOOL vm_transfer_sys_2_mre_qwerty_key( S16 mmi_key_code,  S16 mmi_key_type, U16 ucs2_value, U32 special_key_flag)
{
	/*
	s_vm_usc2_value = ucs2_value;
	s_vm_special_key_flag = special_key_flag;

	vm_transfer_sys_2_mre_key();
	s_vm_usc2_value = 0;
	s_vm_special_key_flag = 0;
	return TRUE; 
	*/
	VMINT keycode = 0, keyevent = 0, i = 0;
	VMINT ret = 0;
	
	_vm_pcb_t* pcb = (vm_pmng_get_pcb_ptr())[VM_PMNG_FOREGROUND];


	s_vm_usc2_value = ucs2_value;
	s_vm_special_key_flag = special_key_flag;

    if (pcb && (NULL == pcb->keyExHandler))
    {
		if (mmi_key_code == KEY_END || 
	        KEY_HOME == mmi_key_code || 
	        KEY_POWER == mmi_key_code)
		{
			return MMI_FALSE;
		}
    }

#ifdef __MRE_LIB_EDITOR__
    /* handle editor key */
    if (vm_editor_get_active_editor() && wgui_editor_process_key_ext(mmi_key_code, mmi_key_type, ucs2_value, special_key_flag))
    {
        return MMI_TRUE;
    }
#endif

	/* ?¨¨¡Áa??KeyEvent */
	switch (mmi_key_type)
	{
	case KEY_EVENT_DOWN:
		keyevent = VM_KEY_EVENT_DOWN;
		break;
	case KEY_EVENT_UP:
		keyevent = VM_KEY_EVENT_UP;
		break;
	case KEY_LONG_PRESS:
		keyevent = VM_KEY_EVENT_LONG_PRESS;
		break;
	case KEY_REPEAT:
		keyevent = VM_KEY_EVENT_REPEAT;
		break;
	default:
		// do nothing.
		break;
	}

    for (i = 0; i < VM_SUPPORT_KEY_CODE_NUM; i++)
    {
        if (mmi_key_code == vmtransSysKey2mre[0][i])
        {
            vm_log_debug("[qwerty bk]sys_keycode[%d]", mmi_key_code);
            if (KEY_BACK == mmi_key_code)
            {
                _vm_pcb_t* pcb = NULL;

                VM_P_HANDLE handle_p = vm_pmng_fg_process();
                if (NULL != (pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, handle_p, NULL)))
                {
                    vm_log_debug("[qwerty bk]pcb->version[%d] 1", pcb->version);
                    if (1000 == pcb->version)
                    {
                        vm_log_debug("[qwerty bk]pcb->version[%d] 2", pcb->version);
                        keycode = VM_KEY_RIGHT_SOFTKEY;
                        break;   
                    }
                }
            }
            keycode = vmtransSysKey2mre[1][i];
            break;
        }
    }
	vm_log_debug("qwerty key test: sys_keycode=%d,sys_keytype=%d",mmi_key_code,mmi_key_type);
	vm_log_debug("qwerty key test: keycode=%d,keyevent=%d",keycode,keyevent);
	if (keycode && keyevent)
	{
		ret = vm_pmng_deal_key_event(keycode, keyevent);
	}
	s_vm_usc2_value = 0;
	s_vm_special_key_flag = 0;
	return ret ? MMI_TRUE : MMI_FALSE; 
}
/**********chenkang 20100203add for qwerty keypad end***********/

VMINT vm_transfer_mre_2_sys_key(VMINT vmKeyCode)
{
    VMINT i;
    for (i = 0; i < VM_SUPPORT_KEY_CODE_NUM; i++)
	{
		if (vmKeyCode == vmtransSysKey2mre[1][i])
		{
			return vmtransSysKey2mre[0][i];
		}
	}
    return -1;
}

//#ifdef __COSMOS_MMI_PACKAGE__
extern void vm_back_key_handler(void) ;
//#endif
extern _vm_pcb_t *g_cur_pcb;
void vm_reg_key_handler(void)
{
    //VMUINT is_support_vp = 0;
    //VMINT bufSize = 4;

	/**********chenkang 20100301add for qwerty keypad begin***********/
	#if 1/*def __MMI_QWERTY_KEYPAD_SUPPORT__*/
	mmi_frm_set_app_translate_key_handler(vm_transfer_sys_2_mre_qwerty_key);
	#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
//#ifdef __COSMOS_MMI_PACKAGE__
//	SetKeyHandler(vm_back_key_handler, KEY_BACK, KEY_EVENT_UP);
//#endif	
}


/*wap start*****************/
#ifdef __MRE_SAL_TELE__
#ifdef BROWSER_SUPPORT
extern void *_vm_kernel_malloc(int size);
extern void _vm_kernel_free(void* ptr);

static void vm_start_browser(VMWSTR url)
{
    int ret = wap_start_browser(WAP_BROWSER_GOTO_URL, (kal_uint8 *)url);
    MMI_PRINT(MOD_MRE,TRACE_GROUP_8,"vm_start_browser %d",ret);
    _vm_kernel_free(url);
}
#endif
VMINT vm_open_wap_url(VMWSTR url)
{
#ifdef BROWSER_SUPPORT
//	if (vm_pmng_is_fg(VM_PMNG_CUR_HANDLE))
	{
	    void* buff = NULL;
		if (url == NULL || url[0] == 0) 
		{
			vm_log_debug("[IME MODULE]The ptr of url's string is NULL.");
			return VM_OPEN_WAP_URL_ERROR_PARAM;
		}

        buff = (void*)_vm_kernel_malloc((kal_wstrlen((const WCHAR *)url)+1)*2);
        if (!buff)
        {
            return VM_OPEN_WAP_URL_ERROR_STATUS;
        }

        kal_wstrcpy((WCHAR *)buff,(const WCHAR *)url);
        StartTimerEx(0xffca,0,(oslTimerFuncPtr)vm_start_browser,buff);
		return VM_OPEN_WAP_URL_SUCCESS;
	}
#else
    {
        vm_log_warn("[IME MODULE] Current process is not allow to open wap browser.");
        return VM_OPEN_WAP_URL_ERROR_STATUS;
    }
#endif
}
#endif
/*wap end*****************/

VMINT vm_is_support_camera_sensor(void)
{
	return FALSE;
}

VMUINT vm_get_memory_size(void)
{
	 return sysconf.memory_size ;
}

#ifndef __MMI_QUERY_SRV__
  VMINT vm_create_service(VMINT clsid, VMINT iid, void ** pptr)
  {
  	
  } 
#endif

VMINT vm_get_trans_key(VMINT16 vm_key_code)
{
    VMINT i = 0;
    for (i = 0; i < VM_SUPPORT_KEY_CODE_NUM; i++)
    {
        if (vm_key_code == vmtransSysKey2mre[1][i])
        {
            return vmtransSysKey2mre[0][i];
        }
    }
    
    return (VMINT)0x7EEEEEEE;
}

/******************************************************************************
 * FUNCTION
 *  vm_is_support_downloadable_app_icon
 * DESCRIPTION
 *  check whether downloadable app icon is supported.
 * PARAMETERS
 *  void
 * RETURNS
 *  TRUE means support, FALSE means NOT support.
 ******************************************************************************/
VMINT vm_is_support_downloadable_app_icon(void)
{
    #ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
        return TRUE;
    #else /* __MMI_VUI_DOWNLOADABLE_APP_ICON__ */
        return FALSE;
    #endif /* __MMI_VUI_DOWNLOADABLE_APP_ICON__ */
}
