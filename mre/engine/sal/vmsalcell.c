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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "vmswitch.h"
#ifdef __MRE_SAL_CELL__
#include "DevConfigGprot.h"
#include "vmcell.h"
#include "vmsys.h"
#include "string.h"
#include "vmlog.h"
#include "vmmem.h"
#include "vmsalcell.h"
#include "vmmacrostub.h"

vm_cell_info_struct* s_vm_sal_cur_cell_info = NULL;
vm_cell_info_struct* s_vm_sal_nbr_cell_info[VM_SAL_CELL_NBR_MAX] = {NULL,NULL,NULL,NULL,NULL,NULL};
VMINT s_vm_sal_cell_nbr_num;

static VMINT vm_sal_cell_is_valid(void);

static void vm_sal_cell_free_mem(void);
static VMINT vm_sal_cell_is_valid(void)
{
	if (sysconf.remote_sensing.cell_info_support)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
VMINT vm_sal_cell_reg_req(void)
{
	vm_log_debug("vm_sal_cell_reg_req:start");
	if (vm_sal_cell_is_valid())
	{
		int i;

		if((s_vm_sal_cur_cell_info = (vm_cell_info_struct*)_vm_kernel_malloc(sizeof(vm_cell_info_struct))) == NULL)
		{
			vm_log_error("vm_sal_cell_reg_req:malloc cur cell mem faild");
			return VM_SAL_CELL_REG_CUR_MALLOC_FAILED;
		}
		for(i = 0; i < VM_SAL_CELL_NBR_MAX; i++)
		{
			if((s_vm_sal_nbr_cell_info[i] = (vm_cell_info_struct*)_vm_kernel_malloc(sizeof(vm_cell_info_struct))) == NULL)
			{
				vm_sal_cell_free_mem();
				vm_log_error("vm_sal_cell_reg_req:malloc nbr cell mem faild");
				return VM_SAL_CELL_REG_NBR_MALLOC_FAILED;
			}
		}
	
		memset(s_vm_sal_cur_cell_info,0,sizeof(vm_cell_info_struct));
		for(i = 0; i < VM_SAL_CELL_NBR_MAX; i++)
		{
			memset(s_vm_sal_nbr_cell_info[i],0, sizeof(vm_cell_info_struct));
		}
		if (vm_sal_stub_cell_reg_req())
		{
			vm_log_debug("vm_sal_cell_reg_req:cell reg success");
			return VM_SAL_CELL_REG_SUCCESS;
		}
		else
		{
			vm_sal_cell_free_mem();
			vm_log_error("vm_sal_cell_reg_req:ilm malloc faild");
			return VM_SAL_CELL_REG_ILM_MALLOC_FAILED;	
		}
	}
	else
	{
		vm_log_error("vm_sal_cell_reg_req:cell is not valid");
		return VM_SAL_CELL_REG_NO_CELL;
	}
}

void vm_sal_cell_dereg_req(void)
{
	vm_log_debug("vm_sal_cell_dereg_req:start");
	if (vm_sal_cell_is_valid())
	{
		vm_sal_stub_cell_dereg_req();
		vm_sal_cell_free_mem();
	}
	vm_log_debug("vm_sal_cell_dereg_req:end");
}


vm_cell_info_struct* vm_sal_cell_get_cur_cell_info(void)
{
	if (vm_sal_cell_is_valid())
	{
		if(s_vm_sal_cur_cell_info != NULL)
		{
			return (s_vm_sal_cur_cell_info);
		}
	}
	return NULL;
}

 vm_cell_info_struct** vm_sal_cell_get_nbr_cell_info(void)
{
	if (vm_sal_cell_is_valid())
	{
		if(s_vm_sal_nbr_cell_info != NULL)
		{
			return (s_vm_sal_nbr_cell_info);
		}
	}
	return NULL;
}

VMINT* vm_sal_cell_get_nbr_num(void)
{
	if (vm_sal_cell_is_valid())
	{
		return &s_vm_sal_cell_nbr_num;
	}
	return NULL;
}
static void vm_sal_cell_free_mem(void)
{
	VMINT i;
	if(s_vm_sal_cur_cell_info != NULL)
	{
		_vm_kernel_free(s_vm_sal_cur_cell_info);
		s_vm_sal_cur_cell_info = NULL;
	}
	for(i=0;i<VM_SAL_CELL_NBR_MAX;i++)
	{
		if(s_vm_sal_nbr_cell_info[i] != NULL)
		{
			_vm_kernel_free(s_vm_sal_nbr_cell_info[i]);
			s_vm_sal_nbr_cell_info[i] = NULL;
		}
	}
}
	
#endif /* __MRE_SAL_CELL__ */
