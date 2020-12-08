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
*  
*
* Project:
* --------
*  MAUI
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
 *
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/


#include "MMI_features.h"
#include "vmswitch.h"

#ifdef __MRE_SAL_TIMER__
#include "TimerEvents.h"
#include "MMIDataType.h"
#include "mmi_frm_timer_gprot.h"
#include "vmsys.h"
#include "vmmod.h"
#include "vmlog.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmem.h"
#include "vmtimer.h"
#include "mmi_rp_app_mre_def.h"

#define VM_SET_BIT(X,Y) X|=(1<<Y)
#define VM_CLR_BIT(X,Y) X&=~(1<<Y)

#define MRE_TIMER_IN_USE 1
#define MRE_TIMER_NOT_IN_USE 0

VMUINT *g_pTimerState = NULL;
VMINT g_nMax_Integer_Count = 0;

extern VMINT mre_running;

typedef struct
{
    VM_P_HANDLE m_pHandle;
    VM_TIMERPROC_T m_pAppTimerCB;
    VMINT m_nInterval;
    VMINT m_timer_type;
    VMINT m_nMTKTimerID;
    VMINT m_nResid;
    VMINT m_nIndex;
} vm_timer_struct;




/*****************************************************************************
 * FUNCTION
 *  vm_test_is_binary_bit_0
 * DESCRIPTION
 *  
 * PARAMETERS
 *  n       [IN]        
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_test_is_binary_bit_0(VMUINT n, VMINT pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(pos>=0 && pos<=31); */
    if (n & (1 << pos))
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_set_timer_used_state_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  bIsUsed     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void vm_set_timer_used_state_by_index(VMINT index, VMINT bIsUsed)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int op_index = -1;
    int pos = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(index>=0); */
    op_index = index / 32;
    pos = index % 32;
    if (bIsUsed)
    {
        VM_SET_BIT(g_pTimerState[op_index], pos);
    }
    else
    {
        VM_CLR_BIT(g_pTimerState[op_index], pos);
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_get_free_mtk_timer_id_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_get_free_mtk_timer_id_index()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    int pos = 0;
    int index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* ASSERT(g_pTimerState != NULL); */
    for (i = 0; i < g_nMax_Integer_Count; i++)
    {
        for (pos = 0; pos < 32; pos++)
        {
            if (vm_test_is_binary_bit_0(g_pTimerState[i], pos))
            {
                return index;
            }
            else
            {
                index++;
            }
        }
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  vm_timer_proc_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_timer_proc_internal(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_timer_struct *p = (vm_timer_struct*) user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	vm_log_debug("vm_timer_proc_internal: start: user_data = %x",user_data);
    if (p != NULL)
    {
    
        vm_timer_struct *res_p = NULL;
        VMINT res_node_size = 0;
        vm_log_debug(
            "vm_timer_proc_internal:phandle=%d,resid=%d,interval=%d",
            p->m_pHandle,
            p->m_nResid,
            p->m_nInterval);


		if (p->m_timer_type == VM_RES_TYPE_TIMER)
        {
			vm_log_debug("vm_timer_proc_internal start again TIMER:mtkid = %d",p->m_nMTKTimerID);
            StartNonAlignTimerEx(p->m_nMTKTimerID, (U32) p->m_nInterval, vm_timer_proc_internal, (void*)p);
        }
        else if (p->m_timer_type == VM_RES_TYPE_TIMER_EX)
        {
			vm_log_debug("vm_timer_proc_internal start again TIMER_EX:mtkid = %d",p->m_nMTKTimerID);
            StartTimerEx(p->m_nMTKTimerID, (U32) p->m_nInterval, vm_timer_proc_internal, (void*)p);
        }
        else
        {
	        vm_log_debug("vm_timer_proc_internal: bad timer type");

            /* ASSERT(0); */
        }

        if (vm_pmng_set_ctx(p->m_pHandle) == VM_PMNG_OP_OK)
        {
            if (mre_running == FALSE)
            {
                vm_pmng_reset_ctx();
                return;
            }
            if (p->m_pAppTimerCB)
            {
                p->m_pAppTimerCB(p->m_nResid);
            }
            vm_pmng_reset_ctx();
        }


    }
    else
    {
        vm_log_debug("vm_timer_proc_internal: bad user data");
        /* ASSERT(0); */
    }

}




/*****************************************************************************
 * FUNCTION
 *  vm_timer_process_state_pro
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phandle         [IN]        
 *  pro_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_timer_process_state_pro(VM_P_HANDLE phandle, VMINT pro_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pro_state)
    {
        case VM_PMNG_UNLOAD:
            while ((i = vm_res_findfirst(phandle, VM_RES_TYPE_TIMER)) != VM_RES_NOT_FIND)
            {
                vm_delete_timer(i);
                vm_log_debug("vm_timer_process_state_pro : delete timerid=%d", i);
                vm_res_findclose(VM_RES_TYPE_TIMER);
            }
            break;
        case VM_PMNG_FOREGROUND:
            break;
        case VM_PMNG_BACKGROUND:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_timer_ex_process_state_pro
 * DESCRIPTION
 *  
 * PARAMETERS
 *  phandle         [IN]        
 *  pro_state       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_timer_ex_process_state_pro(VM_P_HANDLE phandle, VMINT pro_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pro_state)
    {
        case VM_PMNG_UNLOAD:
            while ((i = vm_res_findfirst(phandle, VM_RES_TYPE_TIMER_EX)) != VM_RES_NOT_FIND)
            {
                vm_delete_timer_ex(i);
                vm_log_debug("vm_timer_ex_process_state_pro : delete timerexid=%d", i);
                vm_res_findclose(VM_RES_TYPE_TIMER_EX);
            }

            break;
        case VM_PMNG_FOREGROUND:
            break;
        case VM_PMNG_BACKGROUND:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  vm_timer_initial
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_timer_initial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT total = vm_res_type_max_handle(VM_RES_TYPE_TIMER) + vm_res_type_max_handle(VM_RES_TYPE_TIMER_EX);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_nMax_Integer_Count =
        total % (sizeof(VMUINT) * 8) > 0 ? (total / (sizeof(VMUINT) * 8) + 1) : total / (sizeof(VMUINT) * 8);
    if (g_pTimerState != NULL)
    {
        _vm_kernel_free(g_pTimerState);
        g_pTimerState = NULL;
    }

    g_pTimerState = _vm_kernel_malloc(g_nMax_Integer_Count * sizeof(VMUINT));
    /* ASSERT(g_pTimerState != NULL); */
    if (g_pTimerState != NULL)
    {
        memset(g_pTimerState, 0, sizeof(g_nMax_Integer_Count * sizeof(VMUINT)));
    }

    vm_res_type_set_notify_callback(VM_RES_TYPE_TIMER, vm_timer_process_state_pro);
    vm_res_type_set_notify_callback(VM_RES_TYPE_TIMER_EX, vm_timer_ex_process_state_pro);
}


/*****************************************************************************
 * FUNCTION
 *  vm_timer_finialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_timer_finialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT i = VM_RES_NOT_FIND;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_log_debug("vm_timer_finialize start");
    while ((i = vm_res_findfirst(-1, VM_RES_TYPE_TIMER)) != VM_RES_NOT_FIND)
    {
        vm_log_debug("vm_timer_finialize : will delete timerid=%d", i);
        vm_delete_timer(i);
        vm_log_debug("vm_timer_finialize : have delete timerid=%d", i);
        vm_res_findclose(VM_RES_TYPE_TIMER);
    }

    vm_log_debug("vm_timer_finialize free timer end");

    vm_log_debug("vm_timer_finialize free timer_ex start");
    while ((i = vm_res_findfirst(-1, VM_RES_TYPE_TIMER_EX)) != VM_RES_NOT_FIND)
    {
        vm_delete_timer_ex(i);
        vm_log_debug("vm_timer_finialize : delete timerexid=%d", i);
        vm_res_findclose(VM_RES_TYPE_TIMER_EX);
    }

    vm_log_debug("vm_timer_finialize free timer_ex end");
    if (g_pTimerState != NULL)
    {
        _vm_kernel_free(g_pTimerState);
        g_pTimerState = NULL;
    }

    vm_res_type_set_notify_callback(VM_RES_TYPE_TIMER, NULL);
    vm_res_type_set_notify_callback(VM_RES_TYPE_TIMER_EX, NULL);
    vm_log_debug("vm_timer_finialize end2");
}


/*****************************************************************************
 * FUNCTION
 *  vm_timer_mod_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_timer_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
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
            vm_timer_initial();
            break;
        case EVT_MOD_RELEASE:
            vm_timer_finialize();
            break;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_reg_timer_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_reg_timer_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int res = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((res = _vm_reg_module("TIMER MODULE", (MOD_EVT_PROCESS) vm_timer_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        vm_log_debug("_vm_reg_timer_modual : failed to register timer module. errorcode=%d", res);
    }
    return res;
}


/*****************************************************************************
 * FUNCTION
 *  _vm_create_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_type      [IN]        
 *  millisec        [IN]        
 *  timerproc       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT _vm_create_timer(VMINT timer_type, VMUINT32 millisec, VM_TIMERPROC_T timerproc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT timerid = VM_TIMER_ERROR;
    vm_timer_struct *timer_p = NULL;
    VM_P_HANDLE phandle = vm_pmng_get_current_handle();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phandle < 0)
        return VM_TIMER_ERROR_OF_PROCESS;

    timer_p = _vm_kernel_malloc(sizeof(vm_timer_struct));
    if (timer_p == NULL)
    {
        vm_log_debug("_vm_create_timer : _vm_kernel_malloc fail!!");

        return VM_TIMER_ERROR_OF_MEM;
    }
	else
	{
		vm_log_debug("_vm_create_timer : _vm_kernel_malloc success: timer_p = %x",timer_p);

	}
    timer_p->m_nInterval = millisec;
    timer_p->m_pAppTimerCB = timerproc;
    timer_p->m_pHandle = phandle;
    timer_p->m_timer_type = timer_type;

    timerid = vm_res_save_data(timer_type, timer_p, sizeof(timer_p), (void*)NULL, phandle);
    if (timerid < 0)
    {
        vm_log_debug("_vm_create_timer : save res fail!!");
        _vm_kernel_free(timer_p);
        timerid = VM_TIMER_ERROR_OF_RES;
    }
    else
    {

        vm_log_debug("_vm_create_timer : save res success!!");
        timer_p->m_nIndex = vm_get_free_mtk_timer_id_index();
        timer_p->m_nMTKTimerID = timer_p->m_nIndex + MRE_SYS_TIMER_0;
        timer_p->m_nResid = timerid;

        /* set mtk id state : in use */
        vm_set_timer_used_state_by_index(timer_p->m_nIndex, MRE_TIMER_IN_USE);

        /* start mtk timer callback */
        vm_log_debug("_vm_create_timer:mtk_id = %d,interval = %d,res_id = %d", timer_p->m_nMTKTimerID,timer_p->m_nInterval);

        if (timer_p->m_timer_type == VM_RES_TYPE_TIMER)
        {
            vm_log_debug("vm_timer_proc_internal start again TIMER");
            StartNonAlignTimerEx(
                timer_p->m_nMTKTimerID,
                (U32) timer_p->m_nInterval,
                vm_timer_proc_internal,
                (void*)timer_p);
        }
        else if (timer_p->m_timer_type == VM_RES_TYPE_TIMER_EX)
        {
            vm_log_debug("vm_timer_proc_internal start again TIMER_EX");
            StartTimerEx(timer_p->m_nMTKTimerID, (U32) timer_p->m_nInterval, vm_timer_proc_internal, (void*)timer_p);
        }
        else
        {
            /* ASSERT(0); */
			vm_log_debug("_vm_create_timer bad timer type");
        }
    }

    return timerid;
}


/*****************************************************************************
 * FUNCTION
 *  vm_create_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  millisec        [IN]        
 *  timerproc       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_create_timer(VMUINT32 millisec, VM_TIMERPROC_T timerproc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_log_debug("vm_create_timer interval=%d,callback = %d", millisec, timerproc);

    return _vm_create_timer(VM_RES_TYPE_TIMER, millisec, timerproc);
}


/*****************************************************************************
 * FUNCTION
 *  vm_create_timer_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  millisec        [IN]        
 *  timerproc       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_create_timer_ex(VMUINT32 millisec, VM_TIMERPROC_T timerproc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_log_debug("vm_create_timer_ex interval=%d,callback = %d", millisec, timerproc);

    return _vm_create_timer(VM_RES_TYPE_TIMER_EX, millisec, timerproc);
}


/*****************************************************************************
 * FUNCTION
 *  _vm_delete_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timer_type      [IN]        
 *  timerid         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT _vm_delete_timer(VMINT timer_type, VMINT timerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT index = -1;
    VMINT res_node_size = 0;
    vm_timer_struct *res_p = NULL;
    VMINT mtk_timerid = -1;
    VM_P_HANDLE phandle = -1;
    VM_P_HANDLE curr_phandle = vm_pmng_get_current_handle();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_log_debug("_vm_delete_timer : current_pro = %d,type=%d, timerid=%d", curr_phandle, timer_type, timerid);
    if ((phandle = vm_res_get_process_handle(timer_type, timerid)) < 0)
        return VM_TIMER_ERROR_OF_RES;
    if (curr_phandle > 0)   /* app, not engine */
    {
        if (phandle != curr_phandle)    /* application A can not delete timer belongs to application B */
            return VM_TIMER_ERROR_OF_PROCESS;
    }

    if (vm_res_get_data(timer_type, timerid, (void **)&res_p, &res_node_size) < VM_RES_OK)
        return VM_TIMER_ERROR_OF_RES;
	else
	{
		vm_log_debug("_vm_delete_timer:vm_res_get_data success");
	}
    index = res_p->m_nIndex;
    mtk_timerid = res_p->m_nMTKTimerID;
	vm_log_debug("_vm_delete_timer:_vm_kernel_free addr = %x",res_p);

    _vm_kernel_free(res_p);

    vm_res_set_data(timer_type, timerid, NULL, 0);
    vm_res_set_callback(timer_type, timerid, NULL);

    if (vm_res_release_data(timer_type, timerid) < VM_RES_OK)
        return VM_TIMER_ERROR;
	else
	{
		vm_log_debug("_vm_delete_timer:vm_res_release_data success");

	}

    /* set mtk id state : not in use */
    vm_set_timer_used_state_by_index(index, MRE_TIMER_NOT_IN_USE);
	vm_log_debug("_vm_delete_timer: will stoptimer mtkid = %d",mtk_timerid);
    StopTimer(mtk_timerid);

    return VM_TIMER_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vm_delete_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timerid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_delete_timer(VMINT timerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return _vm_delete_timer(VM_RES_TYPE_TIMER, timerid);
}


/*****************************************************************************
 * FUNCTION
 *  vm_delete_timer_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timerid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_delete_timer_ex(VMINT timerid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return _vm_delete_timer(VM_RES_TYPE_TIMER_EX, timerid);
}
#endif /* __MRE_SAL_TIMER__ */ 

