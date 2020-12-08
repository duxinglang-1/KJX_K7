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
 * vmcell.c
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
#include "vmswitch.h"
#ifdef __MRE_SAL_CELL__
#include "vmsys.h"
#include "vmlog.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"

#include "vmsalcell.h"
#include "vmcell.h"

#define REG_CELL_MODULE_FAILED  -2

static VMINT s_vm_cell_is_opened;

static void vm_cell_modual_initialize(void);

static void vm_cell_modual_finialize(void);

static VMINT vm_cell_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event);

static void vm_cell_notify_process_handler(VM_P_HANDLE process_handle, VMINT sys_state);

static void vm_cell_delete_cur_process_res(VM_P_HANDLE process_handle);

static VMINT vm_cell_res_save_data_faild(void);

static VMINT vm_cell_open_by_cur_process(void);



/*****************************************************************************
 * FUNCTION
 *  _vm_reg_cell_modual
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_reg_cell_modual(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int res_code = REG_MRE_MODULE_SUCCESS;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((res_code = _vm_reg_module("CELL MODUAL", (MOD_EVT_PROCESS)vm_cell_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		vm_log_error("Failed to regisiter cell moudal. Error Code : %d", res_code);
	}

	return res_code;
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_mod_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_cell_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch(event)
	{
	case EVT_MOD_INIT:
		vm_cell_modual_initialize();
		break;
	case EVT_MOD_RELEASE:
		vm_cell_modual_finialize();
		break;
	default:
		vm_log_error("{CELL MODUAL}Receive unkown[%d] event.", event);
		return REG_CELL_MODULE_FAILED;
	}
	return REG_MRE_MODULE_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_notify_process_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process_handle      [IN]        
 *  sys_state           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_cell_notify_process_handler(VM_P_HANDLE process_handle, VMINT sys_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (sys_state == VM_PMNG_UNLOAD)
	{
		vm_cell_delete_cur_process_res(process_handle);
	}
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_modual_initialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_cell_modual_initialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	s_vm_cell_is_opened = FALSE;
	vm_res_type_set_notify_callback(VM_RES_TYPE_CELL, vm_cell_notify_process_handler);
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_modual_finialize
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_cell_modual_finialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(s_vm_cell_is_opened)
	{
		vm_sal_cell_dereg_req();
		s_vm_cell_is_opened = FALSE;
	}
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_cell_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT result;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	if(!s_vm_cell_is_opened)
	{
		result = vm_sal_cell_reg_req();
		if(result >= 0)
		{
			if (vm_cell_res_save_data_faild())
			{
				vm_sal_cell_dereg_req();
				return VM_CELL_OPEN_RES_LESS;
			}
			s_vm_cell_is_opened = TRUE;
			return VM_CELL_OPEN_SUCCESS;
		}
		return VM_CELL_OPEN_REG_ERROR;
	}
	else
	{
		if (vm_cell_res_save_data_faild())
		{
			return VM_CELL_OPEN_RES_LESS;
		}
		return VM_CELL_OPEN_ALREADY_OPEN;
	}
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void vm_cell_close(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	vm_cell_delete_cur_process_res(vm_pmng_get_current_handle());
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_get_cur_cell_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
vm_cell_info_struct* vm_cell_get_cur_cell_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (vm_cell_open_by_cur_process())
	{
		return vm_sal_cell_get_cur_cell_info();
	}
	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_get_nbr_cell_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
vm_cell_info_struct** vm_cell_get_nbr_cell_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (vm_cell_open_by_cur_process())
	{
		return vm_sal_cell_get_nbr_cell_info();
	}
	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_get_nbr_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT* vm_cell_get_nbr_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (vm_cell_open_by_cur_process())
	{
		return vm_sal_cell_get_nbr_num();
	}
	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_open_by_cur_process
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_cell_open_by_cur_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(s_vm_cell_is_opened)
	{
		if (vm_res_get_data_list_count_by_proecss(vm_pmng_get_current_handle(), VM_RES_TYPE_CELL) > 0)
		{
			return TRUE;
		}
	}
	return FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_delete_cur_process_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  process_handle      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void vm_cell_delete_cur_process_res(VM_P_HANDLE process_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_CELL) > 0)
	{
		VMINT res_handle = 0;

		if ((res_handle = vm_res_findfirst(process_handle, VM_RES_TYPE_CELL)) != VM_RES_NOT_FIND)
		{
			vm_res_release_data(VM_RES_TYPE_CELL, res_handle);
			if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_CELL) <= 0)
			{
				if(s_vm_cell_is_opened)
				{
					vm_sal_cell_dereg_req();
					s_vm_cell_is_opened = FALSE;
				}
			}
		}
		vm_res_findclose(VM_RES_TYPE_CELL);
	}
}


/*****************************************************************************
 * FUNCTION
 *  vm_cell_res_save_data_faild
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_cell_res_save_data_faild(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (vm_res_get_data_list_count_by_proecss(vm_pmng_get_current_handle(), VM_RES_TYPE_CELL) <= 0)
	{
		if (vm_res_save_data(VM_RES_TYPE_CELL, NULL, 0, NULL, vm_pmng_get_current_handle()) < 0)
		{
			return TRUE;
		}			
	}
	return FALSE;
}
	
#endif /*__MRE_SAL_CELL__ */
