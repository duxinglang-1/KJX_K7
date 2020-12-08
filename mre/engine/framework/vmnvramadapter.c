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
 * vmnvramadapter.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * nvramadapter
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vmswitch.h"
	 
#ifdef __MRE_CORE_SAFETY__

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "vmsys.h"
#include "vmnvram.h"
#include "vmnvramadapter.h"
#include "vmrsa.h"
#include "vmlog.h"


/*****************************************************************************
 * FUNCTION
 *  vm_save_mobile_phone_id_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_save_mobile_phone_id_record(VMINT mid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_nvram_sysconf_t* system_configuration = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((system_configuration = vm_malloc(sizeof(vm_nvram_sysconf_t))) == NULL)
		return VM_ADAPTER_NVRAM_ERROR_MEM;

	if (!vm_get_sysconf(system_configuration))
	{
		vm_free(system_configuration);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}

	system_configuration->mobile_phone_id = mid;

	if (!vm_set_sysconf(system_configuration))
	{
		vm_free(system_configuration);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}
	
	vm_free(system_configuration);
	return VM_ADAPTER_NVRAM_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_save_user_id_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  uid     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_save_user_id_record(VMINT uid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_nvram_sysconf_t* system_configuration = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if ((system_configuration = vm_malloc(sizeof(vm_nvram_sysconf_t))) == NULL)
		return VM_ADAPTER_NVRAM_ERROR_MEM;
	
	if (!vm_get_sysconf(system_configuration))
	{
		vm_free(system_configuration);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}
	
	system_configuration->uid = uid;
	
	if (!vm_set_sysconf(system_configuration))
	{
		vm_free(system_configuration);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}
	
	vm_free(system_configuration);
	return VM_ADAPTER_NVRAM_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_load_mobile_phone_id_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mid     [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_load_mobile_phone_id_record(VMINT* mid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_nvram_sysconf_t* system_configuration = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!mid)
		return  VM_ADAPTER_NVRAM_ERROR_PARAM;

	if ((system_configuration = vm_malloc(sizeof(vm_nvram_sysconf_t))) == NULL)
		return VM_ADAPTER_NVRAM_ERROR_MEM;
	
	if (!vm_get_sysconf(system_configuration))
	{
		vm_free(system_configuration);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}

	*mid = system_configuration->mobile_phone_id;
	vm_free(system_configuration);
	return VM_ADAPTER_NVRAM_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_load_user_id_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  uid     [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_load_user_id_record(VMINT* uid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_nvram_sysconf_t* system_configuration = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!uid)
		return  VM_ADAPTER_NVRAM_ERROR_PARAM;
	
	if ((system_configuration = vm_malloc(sizeof(vm_nvram_sysconf_t))) == NULL)
		return VM_ADAPTER_NVRAM_ERROR_MEM;
	
	if (!vm_get_sysconf(system_configuration))
	{
		vm_free(system_configuration);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}
	
	*uid = system_configuration->uid;
	vm_free(system_configuration);
	return VM_ADAPTER_NVRAM_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_merge_timestamp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timestamps          [?]         
 *  curr_timestamp      [?]         
 *  time_type           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_merge_timestamp(
        vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP],
        vm_time_t *curr_timestamp,
        TIMESTAMP_TYPE time_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT result = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (curr_timestamp && timestamps)
	{
		switch (time_type)
		{
		case VM_NVRAM_SYSTEM_TIMESTAMP:
		case VM_NVRAM_BAN_APP_LST_TIMESTAMP:
		case VM_NVRAM_SYS_PERMISSION_TIMESTAMP:
		case VM_NVRAM_PUBLIC_CERT_LST_TIMESTAMP:
			memcpy(timestamps + (VMINT)time_type, curr_timestamp, sizeof(vm_time_t));
			result = TRUE;
			break;
		default:
			// DO NOTHING.
			break;	
		}	
	}
	
	return result;
}


/*****************************************************************************
 * FUNCTION
 *  vm_split_timestamp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timestamps          [?]         
 *  curr_timestamp      [?]         
 *  time_type           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_split_timestamp(
        vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP],
        vm_time_t *curr_timestamp,
        TIMESTAMP_TYPE time_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	VMINT result = FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (curr_timestamp && timestamps)
	{
		switch (time_type)
		{
		case VM_NVRAM_SYSTEM_TIMESTAMP:
		case VM_NVRAM_BAN_APP_LST_TIMESTAMP:
		case VM_NVRAM_SYS_PERMISSION_TIMESTAMP:
		case VM_NVRAM_PUBLIC_CERT_LST_TIMESTAMP:
			memcpy(curr_timestamp, timestamps + (VMINT)time_type, sizeof(vm_time_t));
			result = TRUE;
			break;
		default:
			// DO NOTHING.
			break;
		}	
	}
	
	return result;
}


/*****************************************************************************
 * FUNCTION
 *  vm_save_timestamps_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timestamps      [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_save_timestamps_record(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_nvram_sysconf_t* system_configuration = NULL;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!timestamps)
		return VM_ADAPTER_NVRAM_ERROR_PARAM;

	if ((system_configuration = vm_malloc(sizeof(vm_nvram_sysconf_t))) == NULL)
		return VM_ADAPTER_NVRAM_ERROR_MEM;
	
	if (!vm_get_sysconf(system_configuration))
	{
		vm_free(system_configuration);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}
	
	memcpy(system_configuration->sys_time_stamp, timestamps, 
		sizeof(vm_time_t) * VM_NVRAM_MAX_TIMESTAMP);
	
	if (!vm_set_sysconf(system_configuration))
	{
		vm_free(system_configuration);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}
	
	vm_free(system_configuration);
	return VM_ADAPTER_NVRAM_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_load_timestamps_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  timestamps      [?]     
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_load_timestamps_record(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_nvram_sysconf_t* system_configuration = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!timestamps)
		return VM_ADAPTER_NVRAM_ERROR_PARAM;

	if ((system_configuration = vm_malloc(sizeof(vm_nvram_sysconf_t))) == NULL)
		return VM_ADAPTER_NVRAM_ERROR_MEM;
	
	if (!vm_get_sysconf(system_configuration))
	{
		vm_free(system_configuration);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}
	
	memcpy(timestamps, system_configuration->sys_time_stamp, 
		sizeof(vm_time_t) * VM_NVRAM_MAX_TIMESTAMP);

	vm_free(system_configuration);
	return VM_ADAPTER_NVRAM_SUCCESS;
}

#ifdef __MRE_CORE_SANDBOX__


/*****************************************************************************
 * FUNCTION
 *  vm_save_ban_app_lst_records
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ban_app_lst     [?]         
 *  lst_num         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_save_ban_app_lst_records(VMUINT* ban_app_lst, VMUINT lst_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_nvram_app_ban_list_t* ban_lst = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!ban_app_lst || lst_num == 0)
		return VM_ADAPTER_NVRAM_ERROR_PARAM;

	if (lst_num > BAN_LIST_SIZE)
		return VM_ADAPTER_NVRAM_OVERFLOW_STORAGE;

	if ((ban_lst = vm_malloc(sizeof(vm_nvram_app_ban_list_t))) == NULL)
		return VM_ADAPTER_NVRAM_ERROR_MEM;

	memset(ban_lst, 0x00, sizeof(vm_nvram_app_ban_list_t));
	memcpy(ban_lst->app_ban_item, ban_app_lst, sizeof(VMUINT) * lst_num);

	if (!vm_nvram_set_ban_list(ban_lst))
	{
		vm_free(ban_lst);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}
	
	vm_free(ban_lst);
	return VM_ADAPTER_NVRAM_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  vm_save_sys_permission_lst_records
 * DESCRIPTION
 *  
 * PARAMETERS
 *  permission_lst      [?]         
 *  lst_num             [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_save_sys_permission_lst_records(sys_permission_record *permission_lst, VMUINT lst_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_nvram_permission_list_t* perm_lst = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!permission_lst || lst_num == 0)
		return VM_ADAPTER_NVRAM_ERROR_PARAM;

	if (lst_num > SYM_PERMISSION_LEN)
		return VM_ADAPTER_NVRAM_OVERFLOW_STORAGE;

	if ((perm_lst = vm_malloc(sizeof(vm_nvram_permission_list_t))) == NULL)
		return VM_ADAPTER_NVRAM_ERROR_MEM;

	memset(perm_lst, 0x00, sizeof(vm_nvram_permission_list_t));
	memcpy(perm_lst->vm_sym_permission_list, permission_lst, 
		sizeof(vm_permission_t) * lst_num);
	perm_lst->vm_sym_permission_list_len = lst_num;

	if (!vm_nvram_set_sym_permission(perm_lst))
	{
		vm_free(perm_lst);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}
	
	vm_free(perm_lst);
	return VM_ADAPTER_NVRAM_SUCCESS;
}
#endif /* __MRE_CORE_SANDBOX__ */ 


/*****************************************************************************
 * FUNCTION
 *  vm_save_cert_lst_records
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cert_lst        [?]         
 *  lst_num         [IN]        
 * RETURNS
 *  
 *****************************************************************************/
VMINT vm_save_cert_lst_records(vm_cert_record* cert_lst, VMUINT lst_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	vm_nvram_root_pkey_list_t* pk_lst = NULL;
	VMUINT i = 0, j = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!cert_lst || lst_num == 0)
		return VM_ADAPTER_NVRAM_ERROR_PARAM;

	for (i = 0; i < lst_num; i++)
	{
		for (j = i + 1; j < lst_num; j++)
		{
			if (cert_lst[i].pKey.id == cert_lst[j].pKey.id)
				return VM_ADAPTER_NVRAM_ERROR_PARAM;
		}
	}

	if (lst_num > (ROOT_PK_LIST_SIZE * 2))
		return VM_ADAPTER_NVRAM_OVERFLOW_STORAGE;

	if ((pk_lst = vm_malloc(sizeof(vm_nvram_root_pkey_list_t))) == NULL)
		return VM_ADAPTER_NVRAM_ERROR_MEM;
	
	memset(pk_lst, 0x00, sizeof(vm_nvram_root_pkey_list_t));
	for (i = 0; i < lst_num && i < ROOT_PK_LIST_SIZE; i++)
	{
		memcpy(&(pk_lst->pkey_item[i].pkey_time_stamp), 
			&cert_lst[i].timestamp, sizeof(vm_time_t));
		pk_lst->pkey_item[i].pkey_index = cert_lst[i].pKey.id;
		memcpy(pk_lst->pkey_item[i].pkey_content, &(cert_lst[i].pKey), sizeof(VMKey));
	}

	if (!vm_nvram_set_pkey_list(0, pk_lst))
	{
		vm_free(pk_lst);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}

	memset(pk_lst, 0x00, sizeof(vm_nvram_root_pkey_list_t));
	for (i = ROOT_PK_LIST_SIZE; i < lst_num; i++)
	{
		memcpy(&(pk_lst->pkey_item[i - ROOT_PK_LIST_SIZE].pkey_time_stamp), 
			&cert_lst[i].timestamp, sizeof(vm_time_t));
		pk_lst->pkey_item[i - ROOT_PK_LIST_SIZE].pkey_index = cert_lst[i].pKey.id;
		memcpy(pk_lst->pkey_item[i - ROOT_PK_LIST_SIZE].pkey_content, &(cert_lst[i].pKey), sizeof(VMKey));
	}
	if (!vm_nvram_set_pkey_list(1, pk_lst))
	{
		vm_free(pk_lst);
		return VM_ADAPTER_NVRAM_INTERNAL_ERROR;
	}
	
	vm_free(pk_lst);
	return VM_ADAPTER_NVRAM_SUCCESS;
}

#endif /* __MRE_CORE_SAFETY__ */ 

