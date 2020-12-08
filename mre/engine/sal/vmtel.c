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
 * Vmtel.c
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
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "vmswitch.h"
#ifdef __MRE_SAL_TELE__

//#include "mmi_include.h"
//#include "SimDetectionGprot.h"
//#include "MMI_features.h"
#include "MMIDataType.h"

#include "UcmGProt.h"
#include "UcmSrvGProt.h"
#include "vmtel.h"
#include "vmlog.h"
#include "vmstdlib.h"
#include "vmsim.h"
//#include "vmopt.h"
#include "vmmod.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmpromnginner.h"
#include "ModeSwitchSrvGProt.h"

#include "globalresdef.h"
#include "DialerCuiGprot.h"

extern pBOOL mmi_bootup_get_active_flight_mode(void);

static VMINT vm_callout_status;
static srv_ucm_id_info_struct g_vm_ivr_call_info;
static srv_ucm_incoming_call_ind_struct g_vm_ivr_incoming_data;

static mmi_ret vm_callout_ucm_callback(mmi_event_struct * param)
{
	//srv_ucm_status_change_evt_struct *evt = (srv_ucm_status_change_evt_struct *)param;
	VMINT resid = -1;
	VM_CALLOUT_RESPONSE_T callout_callback;
	VMWSTR phonenum = NULL;
	VMINT size = 0;

	VMINT callcount = 0;

	callcount = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);
	vm_log_debug("vm_callout_ucm_callback : callcount=%d", callcount);
	if (callcount > 0)
	{
		vm_callout_status = VM_CALLOUT_BUSY;
	}
	else
	{
		vm_callout_status = VM_CALLOUT_IDEL;
		
	}

	if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_CALLOUT)) != VM_RES_NOT_FIND)
	{
		VM_P_HANDLE phandle = vm_res_get_process_handle(VM_RES_TYPE_CALLOUT, resid);
		vm_res_get_callback(VM_RES_TYPE_CALLOUT, resid, (void**)&callout_callback);
		vm_res_get_data(VM_RES_TYPE_CALLOUT, resid, (void**)&phonenum, &size);

		if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
		{
			if (callout_callback != NULL)
			{
				callout_callback(phonenum, vm_callout_status);
			}

			vm_pmng_reset_ctx();
		}

		if (vm_callout_status == VM_CALLOUT_IDEL)
		{
			vm_res_release_data(VM_RES_TYPE_CALLOUT, resid);
		}
		
		vm_res_findclose(VM_RES_TYPE_CALLOUT);
		
	}
	return MMI_RET_OK;
}


static void vm_callout_process_state_pro(VM_P_HANDLE phandle, VMINT pro_state)
{
	VMINT resid = 0;
	
	switch(pro_state)
	{
		case VM_PMNG_UNLOAD:
			while ((resid = vm_res_findfirst(phandle, VM_RES_TYPE_CALLOUT)) != VM_RES_NOT_FIND)
			{
				vm_res_release_data(VM_RES_TYPE_CALLOUT, resid);		
				vm_res_findclose(VM_RES_TYPE_CALLOUT);		
			}				
			while ((resid = vm_res_findfirst(phandle, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
			{
			    srv_ucm_single_call_act_req_struct req;
                memcpy(&req.action_uid,&g_vm_ivr_call_info,sizeof(req.action_uid));
                
                srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT,&req,NULL,NULL);
                
				vm_res_release_data(VM_RES_TYPE_IVR, resid);		
				vm_res_findclose(VM_RES_TYPE_IVR);		
			}
			break;
		case VM_PMNG_FOREGROUND:
			break;
		case VM_PMNG_BACKGROUND:
			break;
	}
}


static void vm_callout_initial(void)
{
	VMINT callcount = 0;

	callcount = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);	
	
	if (callcount > 0)
	{
		vm_callout_status = VM_CALLOUT_BUSY;
	}
	else
	{
		vm_callout_status = VM_CALLOUT_IDEL;
	}
	
	mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, vm_callout_ucm_callback, NULL);

	vm_res_type_set_notify_callback(VM_RES_TYPE_CALLOUT, vm_callout_process_state_pro);	
	vm_res_type_set_notify_callback(VM_RES_TYPE_IVR, vm_callout_process_state_pro);	
}

static void vm_callout_finialize(void)
{
	VMINT callcount = 0;

	vm_res_type_set_notify_callback(VM_RES_TYPE_CALLOUT, NULL);

	mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, vm_callout_ucm_callback, NULL);
	
	callcount = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);	

	if (callcount > 0)
	{
		vm_callout_status = VM_CALLOUT_BUSY;
	}
	else
	{
		vm_callout_status = VM_CALLOUT_IDEL;
	}

	vm_log_debug("vm_callout_finialize : callcount=%d, status=%d", callcount, vm_callout_status);
}

 static VMINT vm_callout_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
		case EVT_MOD_INIT:
			vm_callout_initial();
			break;
 		case EVT_MOD_RELEASE:
			vm_callout_finialize();
			break;
	}
	return 0;
}

 VMINT _vm_reg_callout_module(void)
{
	int res = 0;

	if ((res = _vm_reg_module("CALLOUT MODULE", (MOD_EVT_PROCESS)vm_callout_mod_evt_proc)) 
		!= REG_MRE_MODULE_SUCCESS)
	{
		vm_log_debug("_vm_reg_callout_modual : failed to register callout module. errorcode=%d", res);
	}
	return res;
}

 static VMINT vm_available_phnum(VMWSTR phnum)
{
	while(*phnum != 0)
	{
		if (   *phnum != (VMWCHAR)L'0'
			&& *phnum != (VMWCHAR)L'1'
			&& *phnum != (VMWCHAR)L'2'
			&& *phnum != (VMWCHAR)L'3'
			&& *phnum != (VMWCHAR)L'4'
			&& *phnum != (VMWCHAR)L'5'
			&& *phnum != (VMWCHAR)L'6'
			&& *phnum != (VMWCHAR)L'7'
			&& *phnum != (VMWCHAR)L'8'
			&& *phnum != (VMWCHAR)L'9'
			&& *phnum != (VMWCHAR)L'P'
			&& *phnum != (VMWCHAR)L'*'
			&& *phnum != (VMWCHAR)L'+'
			&& *phnum != (VMWCHAR)L'#')
		{
			return FALSE;
		}
		phnum++;
	}
	return TRUE;
}

VMINT vm_callout_ex(VMWSTR phnum, VM_CALLOUT_RESPONSE_T callback)
{
	VM_P_HANDLE phandle =  vm_pmng_get_current_handle();
//	VMINT resid = -1;
	
	mmi_ucm_make_call_para_struct  make_call_para;
	VMUINT16 gid = 0;  

	if (vm_pmng_state(phandle) != VM_PMNG_FOREGROUND)
	{
		vm_log_debug("vm_callout: state is not foreground");
		return VM_CALLOUT_ERR_STATE;
	}
#ifdef __MRE_SAL_SIM__
 
	if (vm_sim_card_count() <= 0)
	{
		vm_log_debug("vm_callout: no sim card");
		return VM_CALLOUT_ERR_NO_SIM;
	}
#endif
 
	if (!srv_mode_switch_is_network_service_available())
	{
		vm_log_debug("vm_callout: flight mode");
		return VM_CALLOUT_ERR_FLIGHT;
	}
 
	if (vm_callout_status != VM_CALLOUT_IDEL)
	{
		vm_log_debug("vm_callout: device is busy now");
		return VM_CALLOUT_ERR_BUSY;
	}
	 
	if (phnum == NULL)
	{
		vm_log_debug("vm_callout : the ptr of phnum is NULL");
		return VM_CALLOUT_ERR_PHONE_NUM;
	}
	if ((vm_wstrlen(phnum) <= 0) || (vm_wstrlen(phnum) >= 40))
	{
		vm_log_debug("vm_callout : the len of phnum is error");
		return VM_CALLOUT_ERR_PHONE_NUM;
	}
	if (vm_available_phnum(phnum) == FALSE)
	{
		vm_log_debug("vm_callout : the content of phnum is error");
		return VM_CALLOUT_ERR_PHONE_NUM;
	}
	if (phandle < 0)
	{
		vm_log_debug("vm_callout : phandle is error");
		return VM_CALLOUT_ERR_PROCESS;
	}
	 
	if ((vm_res_save_data(VM_RES_TYPE_CALLOUT, phnum, (vm_wstrlen(phnum) * 2), (void*)callback, phandle)) < 0)
	{
	    VMINT resid = -1;
	    if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_CALLOUT)) != VM_RES_NOT_FIND)
    	{
    		vm_res_release_data(VM_RES_TYPE_CALLOUT, resid);   		
    		vm_res_findclose(VM_RES_TYPE_CALLOUT);    		
    	}
		
		if ((vm_res_save_data(VM_RES_TYPE_CALLOUT, phnum, (vm_wstrlen(phnum) * 2), (void*)callback, phandle)) < 0)
		{
		    vm_log_debug("vm_callout: res save error");
		    return VM_CALLOUT_ERR_NO_RES;
		}
	}

 
	vm_log_debug("vm_callout : before mmi_ucm_init_call_para");
	mmi_ucm_init_call_para(&make_call_para);  
	vm_log_debug("vm_callout : after mmi_ucm_init_call_para");

    switch (vm_sim_get_active_sim_card())
    {
    case 1:
        make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
        break;
    case 2:
        make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
        break;
    case 3:
        make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
        break;
    case 4:
        make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
        break;
    default:
        return VM_CALLOUT_ERR_NO_SIM;
    }
    
	make_call_para.ucs2_num_uri = (U16*)phnum;
    
	vm_log_debug("vm_callout : before mmi_ucm_call_launch");
	mmi_ucm_call_launch(gid, &make_call_para);	
	vm_log_debug("vm_callout : after mmi_ucm_call_launch");
	
	return VM_CALLOUT_NO_ERR;
}

void vm_callout(VMWSTR phnum) 
{
	vm_callout_ex(phnum, NULL);
}

static mmi_id g_vm_dialer_id = 0;

extern vm_dialer_launch_adp(VMSTR phone_num);

static mmi_ret vm_dialer_proce(mmi_event_struct *event)
{
    mmi_ret ret = MMI_RET_OK;

    switch (event->evt_id)
    {
        case EVT_ID_CUI_DIALER_CLOSE_REQ:
            cui_dialer_close(g_vm_dialer_id);
            break;
        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}

VMINT vm_dialer_launch(VMWSTR phone_num)
{
#ifndef __COSMOS_MMI_PACKAGE__
    mmi_id parent_id;

    parent_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vm_dialer_proce, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    g_vm_dialer_id = cui_dialer_create(parent_id);

    if (g_vm_dialer_id <= 0)
    {
        return -2;
    }
    
    if (phone_num)
    {
        cui_dialer_set_dial_string(g_vm_dialer_id, (WCHAR *)phone_num);
    }
    
    cui_dialer_run(g_vm_dialer_id);
#else
    vm_dialer_launch_adp((VMSTR)phone_num);
#endif    
    return 0;
}

static void _vm_ivr_send_indication(void)
{
    srv_ucm_send_indication(SRV_UCM_INCOMING_CALL_IND,&g_vm_ivr_incoming_data);
}

static mmi_ret _vm_ivr_end_callback(mmi_event_struct *param)
{
    srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)((srv_ucm_act_result_evt_struct*)param)->act_result;
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_end_callback %d",rsp->result_info.result);
    
    StartTimer(0xefda,1000,_vm_ivr_send_indication);
}
/*
static mmi_ret _vm_ivr_end_all_callback(mmi_event_struct *param)
{
    srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)((srv_ucm_act_result_evt_struct*)param)->act_result;
    srv_ucm_single_call_act_req_struct req;
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_end_all_callback %d",rsp->result_info.result);

    memcpy(&req.action_uid,&g_vm_ivr_call_info,sizeof(req.action_uid));   
//    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT,&req,NULL,_vm_ivr_end_callback);  
}
*/
static void _vm_ivr_handler_timer_cb(void)
{
    srv_ucm_single_call_act_req_struct req;

	memcpy(&req.action_uid,&g_vm_ivr_call_info,sizeof(req.action_uid));   
    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT,&req,NULL,_vm_ivr_end_callback);                
//    srv_ucm_act_request(SRV_UCM_END_ALL_PROCESSING_ACT,NULL,NULL,_vm_ivr_end_all_callback);
}

mmi_ret vm_ivr_handler(mmi_event_struct *param)
{
    mmi_ret result = MMI_RET_OK;
    ivr_callback_data data;
    srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)param->user_data;
    VMINT resid = -1;

    data.status = VM_IVR_CALLED_OUT;
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_handler1 %d", param->evt_id);
    if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
	{	    
        VM_P_HANDLE phandle = vm_res_get_process_handle(VM_RES_TYPE_IVR, resid);
        void* user_data;
        VMINT size = 4;
        vm_ivr_cb callback;        

        MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_handler");
        
        vm_res_get_callback(VM_RES_TYPE_IVR, resid, (void**)&callback);
        vm_res_get_data(VM_RES_TYPE_IVR, resid, (void**)&user_data, &size);
        data.user_data = user_data;
        
	    if (EVT_ID_SRV_UCM_STATUS_CHANGE == param->evt_id)
        {                
            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
        	{
                MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"1");
                data.status = VM_IVR_CALL_END;
        		if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
        		{
        			if (callback != NULL)
        			{
        				callback(&data);
        			}

        			vm_pmng_reset_ctx();
        		}
        		vm_res_release_data(VM_RES_TYPE_IVR, resid);
        		MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"2");
        	}
        	else
        	{
        	    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"3");
        	    data.status = VM_IVR_CALLED_OUT;
        	    if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
        		{
        			if (callback != NULL)
        			{
        				callback(&data);
        			}

        			vm_pmng_reset_ctx();
        		}
        		MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"4");
        	}
        	result = MMI_RET_ERR;
        }
        else if (EVT_ID_SRV_UCM_INDICATION == param->evt_id)
        {
            srv_ucm_ind_evt_struct* evt_struct = (srv_ucm_ind_evt_struct*)param;
            
            if (SRV_UCM_OUTGOING_CALL_IND == evt_struct->ind_type)
            {                
                srv_ucm_outgoing_call_ind_struct* info = (srv_ucm_outgoing_call_ind_struct*)evt_struct->ptr;
                memcpy(&g_vm_ivr_call_info,&info->uid_info,sizeof(g_vm_ivr_call_info));
                MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_handler%d,%d",g_vm_ivr_call_info.group_id,g_vm_ivr_call_info.call_id);

                result = MMI_RET_ERR;
            }            
            else if (SRV_UCM_INCOMING_CALL_IND == evt_struct->ind_type)
            {    
                srv_ucm_single_call_act_req_struct req;
                
                MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"6");
                data.status = VM_IVR_INTERRUPT;
        		if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
        		{
        			if (callback != NULL)
        			{
        				callback(&data);
        			}

        			vm_pmng_reset_ctx();
        		}       

                memcpy(&g_vm_ivr_incoming_data,evt_struct->ptr,sizeof(g_vm_ivr_incoming_data));
                vm_res_release_data(VM_RES_TYPE_IVR, resid);
                
        		StartTimer(0xefda,100,_vm_ivr_handler_timer_cb);
#if 0        		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif                
        		MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"7");
        		result = MMI_RET_ERR;
            }
            else
            {
                 MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"8");
                result = MMI_RET_ERR;
            }
            
        }
        else if (EVT_ID_SRV_UCM_ACTION_NOTIFY == param->evt_id)
        {
            MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"9");
            result = MMI_RET_ERR;
        }	
        vm_res_findclose(VM_RES_TYPE_IVR);
	}
	MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_handler end %d,%d",result,data.status);
	return result;    
}


static mmi_ret _vm_ivr_call_callback(mmi_event_struct *param)
{
    srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)((srv_ucm_act_result_evt_struct*)param)->act_result;
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_call_callback 1");
    
    if (rsp && SRV_UCM_RESULT_OK != rsp->result_info.result)
    {
        VMINT resid = -1;
        
        MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_call_callback fail");
        
        if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
    	{	
            VM_P_HANDLE phandle = vm_res_get_process_handle(VM_RES_TYPE_IVR, resid);
            void* user_data;
            VMINT size = 4;
            vm_ivr_cb callback;
            ivr_callback_data data;

            MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"1");
            
            vm_res_get_callback(VM_RES_TYPE_IVR, resid, (void**)&callback);
            vm_res_get_data(VM_RES_TYPE_IVR, resid, (void**)&user_data, &size);
            data.user_data = user_data;
            data.status = VM_IVR_FAIL;

            if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
    		{
    			if (callback != NULL)
    			{
    				callback(&data);
    			}

    			vm_pmng_reset_ctx();
    		}
    		vm_res_release_data(VM_RES_TYPE_IVR, resid);
    		vm_res_findclose(VM_RES_TYPE_IVR);
        }        
    }
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_call_callback end");
    return MMI_RET_OK; 
}

VMINT vm_ivr_call(vm_ivr_call_data* data)
{   
    VMINT result = 0;
    srv_ucm_dial_act_req_struct req;

    memset(&req, 0, sizeof(req));
    if (data->sim_card > vm_sim_max_card_count() || data->sim_card < 1)
    {
        result = -2;
        goto error;
    }

	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
	{
	    result = -3;
        goto error;
	}
	
    if ((vm_res_save_data(VM_RES_TYPE_IVR, data->user_data, 4, (void*)data->callback, vm_pmng_get_current_handle())) < 0)
	{
		result = -4;
        goto error;
	}
	req.call_type = 1<< ((data->sim_card-1)*8);
	kal_wstrncpy(req.num_uri,data->phone_num,SRV_UCM_MAX_NUM_URI_LEN+1);
	req.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
	req.is_ip_dial = 0;
	req.phb_data = NULL;
	
	srv_ucm_act_request(SRV_UCM_DIAL_ACT,&req,NULL,_vm_ivr_call_callback);
error:
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_call %d,%d",result,data->sim_card);
    return result;
}

/*
static mmi_ret _vm_ivr_dial_callback(mmi_event_struct *param)
{
    srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)((srv_ucm_act_result_evt_struct*)param)->act_result;
    VMINT resid = -1;

    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_dial_callback 1");
    
    if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
	{	
        VM_P_HANDLE phandle = vm_res_get_process_handle(VM_RES_TYPE_IVR, resid);
        void* user_data;
        VMINT size = 4;
        vm_ivr_cb callback;
        ivr_callback_data data;

        MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_dial_callback %d",rsp->result_info.result);
        
        vm_res_get_callback(VM_RES_TYPE_IVR, resid, (void**)&callback);
        vm_res_get_data(VM_RES_TYPE_IVR, resid, (void**)&user_data, &size);
        data.user_data = user_data;
        

		if (rsp && SRV_UCM_RESULT_OK == rsp->result_info.result)
        {
            data.status = VM_IVR_DIALED;
        }
        else
        {
            data.status = VM_IVR_DIAL_FAIL;
        }
        
        if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
		{
			if (callback != NULL)
			{
				callback(&data);
			}

			vm_pmng_reset_ctx();
		}
		vm_res_findclose(VM_RES_TYPE_IVR); 
    }   
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_dial_callback end");
    return MMI_RET_OK; 
}
*/
VMINT vm_ivr_dial_number(VMCHAR number)
{
    VMINT result = 0;
    srv_ucm_dtmf_struct digits;
    mmi_keypads_enum key;
    VMINT resid =1;
    
    if (!number)
    {
        result = -2;
        goto error;
    }

    if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
	{	
	    VM_P_HANDLE phandle;
	    
	    vm_res_findclose(VM_RES_TYPE_IVR);
	    phandle = vm_res_get_process_handle(VM_RES_TYPE_IVR, resid);
	    if (vm_pmng_get_current_handle() != phandle)
	    {
	        result = -3;
	        goto error;
	    }
		
    }   
    else
    {
        result = -4;
        goto error;
    }

	switch (number)
	{
	case '1':
	    key = KEY_1;
	    break;
	case '2':
	    key = KEY_2;
	    break;
	case '3': 
	    key = KEY_3;
	    break;
	case '4':
	    key = KEY_4;
	    break;
	case '5':
	    key = KEY_5;
	    break;
	case '6':
	    key = KEY_6;
	    break;
	case '7':
	    key = KEY_7;
	    break;
	case '8':
	    key = KEY_8;
	    break;
	case '9':
	    key = KEY_9;
	    break;
	case '0':
	    key = KEY_0;
	    break;
    case '*':
	    key = KEY_STAR;
	    break;
    case '#':
	    key = KEY_POUND;
	    break;	
    default:
        result = -5;
        goto error;
	}	
	
	digits.digit = key;
	srv_ucm_act_request(SRV_UCM_START_DTMF_ACT,&digits,NULL,NULL);
	srv_ucm_act_request(SRV_UCM_STOP_DTMF_ACT,&digits,NULL,NULL);
error:	
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_dial_number %d",result);
	return result;
}

VMINT vm_ivr_end(void)
{
    VMINT result = 0;
    VMINT resid = -1;
    srv_ucm_single_call_act_req_struct req;
    
    if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
	{	
	    VM_P_HANDLE phandle;
	    
	    vm_res_findclose(VM_RES_TYPE_IVR);	    
	    phandle = vm_res_get_process_handle(VM_RES_TYPE_IVR, resid);
	    if (vm_pmng_get_current_handle() != phandle)
	    {
	        result = -2;
	        goto error;
	    }		
    }   
    else
    {
        result = -3;
        goto error;
    }
    memcpy(&req.action_uid,&g_vm_ivr_call_info,sizeof(req.action_uid));
    
    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT,&req,NULL,NULL);
error:
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_end %d,%d,%d",result,req.action_uid.group_id,req.action_uid.call_id);
    return result;
}

#endif //__MRE_SAL_TELE__
 
