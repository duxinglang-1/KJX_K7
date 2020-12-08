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
 * Vmalarm.c
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
 
#include "MMI_include.h"
#include "nvram_common_defs.h"
#include "custom_mmi_default_value.h"
#include "mmi_rp_srv_reminder_def.h"
#include "app_datetime.h"
#include "ReminderSrvGprot.h"
#include "vmalarm.h"
#include "vmsys.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmlog.h"
#include "vmmem.h"


typedef struct
{
    VM_P_HANDLE m_pHandle;
    VM_ALARMPROC_T m_pAppAlarmCB;
    vm_alarm_time_struct m_expire_time;
    VMINT m_nResid;
    VMINT m_nIndex;
} vm_alarm_struct;

extern VMINT mre_running;


VMINT vm_alarm_set(vm_alarm_time_struct* expire_time, VM_ALARMPROC_T alarm_proc)
{
	MYTIME alarm_expire_time;
	srv_reminder_ret_enum ret;
	vm_alarm_struct *alarm_p;
	VM_P_HANDLE phandle;	
    VMINT alarm_id;


	if ((phandle = vm_pmng_get_app_handle()) == 0)
	{
       	MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_101 );
		return VM_ALARM_ERROR;  		
	}
	
	if((alarm_p = (vm_alarm_struct *)_vm_kernel_malloc(sizeof(vm_alarm_struct))) == NULL)
    {
       	MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_107 );
		return VM_ALARM_ERROR_OF_MEM;
    }

	alarm_p->m_pHandle = phandle;
	alarm_p->m_pAppAlarmCB = alarm_proc;
	alarm_p->m_expire_time.nYear = expire_time->nYear;
	alarm_p->m_expire_time.nMonth = expire_time->nMonth;
	alarm_p->m_expire_time.nDay = expire_time->nDay;
	alarm_p->m_expire_time.nHour = expire_time->nHour;
	alarm_p->m_expire_time.nMin = expire_time->nMin;
	alarm_p->m_expire_time.nSec = expire_time->nSec;
	alarm_p->m_expire_time.DayIndex = expire_time->DayIndex;
	
	if ((alarm_id = vm_res_save_data(VM_RES_TYPE_ALARM, (void *) alarm_p, sizeof(vm_alarm_struct),NULL, phandle)) < 0)
	{
		_vm_kernel_free(alarm_p);
       	MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_124 );
		return VM_ALARM_ERROR_OF_RES;
	}
	alarm_p->m_nResid = alarm_id;


	alarm_expire_time.nYear = expire_time->nYear;
	alarm_expire_time.nMonth = expire_time->nMonth;
	alarm_expire_time.nDay = expire_time->nDay;
	alarm_expire_time.nHour = expire_time->nHour;
	alarm_expire_time.nMin = expire_time->nMin;
	alarm_expire_time.nSec = expire_time->nSec;
	alarm_expire_time.DayIndex = 0;


	ret = srv_reminder_set(SRV_REMINDER_TYPE_MRE_ALARM, &alarm_expire_time, alarm_id);
	if (ret == SRV_REMINDER_RET_OK)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_142 , alarm_id, ret);
		return alarm_id;
	}
	else if (ret == SRV_REMINDER_RET_INVALID_TIME)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_147 , alarm_id, ret);
		return VM_ALARM_ERROR_INVALID_TIME;
	}	
	else if (ret == SRV_REMINDER_RET_FAIL)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_152 , alarm_id, ret);
		return VM_ALARM_ERROR;
	}
	else if (ret == SRV_REMINDER_RET_STOP)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_157 , alarm_id, ret);
		return VM_ALARM_ERROR;
	}
	else
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_162 , alarm_id, ret);
		return VM_ALARM_ERROR;
	}
}


VMINT vm_alarm_cancel(VMINT alarm_id)
{
    VMINT res_node_size = 0;
    vm_alarm_struct *res_p = NULL;
    VMINT mtk_timerid = -1;
    VM_P_HANDLE phandle = -1;
    VM_P_HANDLE curr_phandle = vm_pmng_get_app_handle();
	MMI_BOOL ret;

    if ((phandle = vm_res_get_process_handle(VM_RES_TYPE_ALARM, alarm_id)) < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_179 , alarm_id); 
        return VM_ALARM_ERROR_INVALID_ID;
    }
	
    if (curr_phandle > 0)   /* app, not engine */
    {
        if (phandle != curr_phandle)    /* application A can not cancel alarm belongs to application B */
		{
            MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_187 , phandle, curr_phandle); 
            return VM_ALARM_ERROR_OF_PROCESS;
        }
    }

    if (vm_res_get_data(VM_RES_TYPE_ALARM, alarm_id, (void **)&res_p, &res_node_size) < VM_RES_OK)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_194 , alarm_id); 
		return VM_ALARM_ERROR;
	}

    _vm_kernel_free(res_p);

    if (vm_res_release_data(VM_RES_TYPE_ALARM, alarm_id) < VM_RES_OK)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_202 , alarm_id); 
		return VM_ALARM_ERROR;
	}	


	ret = srv_reminder_cancel(SRV_REMINDER_TYPE_MRE_ALARM, alarm_id);
	if (ret == MMI_FALSE)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_210 , alarm_id); 
		return VM_ALARM_ERROR;
	}		

	MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_214 , alarm_id);

    return VM_ALARM_OK;	
}


static void vm_alarm_expire_handler(VMINT alarm_id)
{
	VMINT res_node_size = 0;
	vm_alarm_struct *res_p = NULL;
    
	if (mre_running == FALSE)
	{
		return;
	}
	
	if (vm_res_get_data(VM_RES_TYPE_ALARM, alarm_id, (void **)&res_p, &res_node_size) < VM_RES_OK)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_227 , alarm_id); 
		return;
	}

	MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_231 , alarm_id);

	if (vm_pmng_set_ctx(res_p->m_pHandle) == VM_PMNG_OP_OK)
	{
		if (res_p->m_pAppAlarmCB)
		{
			res_p->m_pAppAlarmCB(alarm_id);
		}
		vm_pmng_reset_ctx();
	}

	_vm_kernel_free(res_p);
	
	if (vm_res_release_data(VM_RES_TYPE_ALARM, alarm_id) < VM_RES_OK)
	{
		MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_240 , alarm_id); 
		return;
	}	
}

mmi_ret vm_alarm_notify_hdlr(mmi_event_struct *evt)
{
	srv_reminder_evt_struct *remdr_evt;
	remdr_evt = (srv_reminder_evt_struct *)evt;

	MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_250 , remdr_evt->reminder_type, remdr_evt->usr_data); 

	if (remdr_evt->reminder_type == SRV_REMINDER_TYPE_MRE_ALARM)
	{
		switch(evt->evt_id)
		{		
			case EVT_ID_SRV_REMINDER_NOTIFY:
				srv_reminder_notify_finish(MMI_FALSE);
				vm_alarm_expire_handler(remdr_evt->usr_data);
				break;
			default:
				break;
		}
	}
	
	return MMI_RET_OK;
}


static void vm_alarm_mibr_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
 	VMINT i;
	
 	switch(sys_state)
 	{
 		case VM_PMNG_UNLOAD:
			if (vm_pmng_get_app_handle() == process_handle)
			{			
				while ((i = vm_res_findfirst(process_handle, VM_RES_TYPE_ALARM)) != VM_RES_NOT_FIND)
					{
						MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_280 , i);
						vm_alarm_cancel(i);
						vm_res_findclose(VM_RES_TYPE_ALARM);
					}				
			}
     		break;
		default:
			return;
	}
}

static void vm_alarm_initial(void)
{
	vm_res_type_set_notify_callback(VM_RES_TYPE_ALARM, vm_alarm_mibr_notify_callback);
}

static void vm_alarm_finialize(void)
{
    VMINT i = VM_RES_NOT_FIND;

    while ((i = vm_res_findfirst(-1, VM_RES_TYPE_ALARM)) != VM_RES_NOT_FIND)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_302 , i);
        vm_alarm_cancel(i);
        vm_res_findclose(VM_RES_TYPE_ALARM);
    }

	vm_res_type_set_notify_callback(VM_RES_TYPE_ALARM, NULL);
}

static VMINT vm_alarm_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case EVT_MOD_INIT:
            vm_alarm_initial();
            break;
        case EVT_MOD_RELEASE:
            vm_alarm_finialize();
            break;
    }
    return 0;
}

VMINT _vm_reg_alarm_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int res = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((res = _vm_reg_module("ALARM MODULE", (MOD_EVT_PROCESS) vm_alarm_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_ALARM, TRC_MRE_VMALARM_343 , res);
    }
    return res;
}



