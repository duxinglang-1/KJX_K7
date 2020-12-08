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
 * Vmsalcontact.h
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

#ifndef VMPHONEBOOKSAL_H_
#define VMPHONEBOOKSAL_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "vmcontact.h"


 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_add_contact
 * DESCRIPTION
 *  add item in phone book
 * PARAMETERS
 *  req_info : [IN]        
 *  cb : [IN]        
 * RETURNS
 *  vm_phb_req_error_enum
 *****************************************************************************/
vm_phb_req_error_enum vm_sal_phb_add_contact(vm_phb_add_req_struct* req_info,  vm_phb_callback_type cb);

 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_delete_contact
 * DESCRIPTION
 *  delete item in phone book
 * PARAMETERS
 *  req_info : [IN]        
 *  cb : [IN]        
 * RETURNS
 *  vm_phb_req_error_enum
 *****************************************************************************/
vm_phb_req_error_enum vm_sal_phb_delete_contact(vm_phb_delete_req_struct* req_info,   vm_phb_callback_type cb);

 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_update_contact
 * DESCRIPTION
 *  update item in phone book
 * PARAMETERS
 *  req_info : [IN]        
 *  cb : [IN]        
 * RETURNS
 *  vm_phb_req_error_enum
 *****************************************************************************/
vm_phb_req_error_enum vm_sal_phb_update_contact(vm_phb_update_req_struct* req_info,  vm_phb_callback_type cb);

 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_search_contact
 * DESCRIPTION
 *  search item in phone book
 * PARAMETERS
 *  req_info : [IN]        
 *  cb : [IN]        
 * RETURNS
 *  vm_phb_req_error_enum
 *****************************************************************************/
vm_phb_req_error_enum vm_sal_phb_search_contact(vm_phb_search_req_struct* req_info,   vm_phb_callback_type cb);


 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_search_contact_list
 * DESCRIPTION
 *  search all the match item in phone book
 * PARAMETERS
 *  req_info : [IN]   
 *  pos_array : [OUT]
 *  post_array_len : [IN]        
 * RETURNS
 *  number of match item
 *****************************************************************************/
VMINT vm_sal_phb_search_contact_list(vm_phb_search_list_req_struct* req_info, vm_phb_contact_pos_struct* pos_array, VMINT post_array_len);


 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_get_contact
 * DESCRIPTION
 *  get item
 * PARAMETERS
 *  req_info : [IN]        
 *  cb : [IN]        
 * RETURNS
 *  vm_phb_req_error_enum
 *****************************************************************************/
vm_phb_req_error_enum vm_sal_phb_get_contact(vm_phb_get_req_struct* req_info,  vm_phb_callback_type cb);
 
 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_search_contact_syn
 * DESCRIPTION
 *  search item (sync) ,return the first match item
 * PARAMETERS
 *  req_info : [IN]              
 * RETURNS
 *  vm_phb_req_error_enum
 *****************************************************************************/
vm_phb_req_error_enum vm_sal_phb_search_contact_syn(vm_phb_search_req_struct* req_info);


 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_get_contact_syn
 * DESCRIPTION
 *  get item (sync)
 * PARAMETERS
 *  req_info : [IN]             
 * RETURNS
 *  vm_phb_req_error_enum
 *****************************************************************************/
vm_phb_req_error_enum vm_sal_phb_get_contact_syn(vm_phb_get_req_struct* req_info);

 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_get_total_contacts
 * DESCRIPTION
 *  get total storage limitation of items
 * PARAMETERS
 *  storage : [IN]              
 * RETURNS
 *  number of items
 *****************************************************************************/
VMINT vm_sal_phb_get_total_contacts(vm_phb_storage_loc_enum storage);

 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_get_used_contacts
 * DESCRIPTION
 *  get used items
 * PARAMETERS
 *  pos_array : [OUT]        
 *  storage : [IN]        
 * RETURNS
 *  number of items
 *****************************************************************************/
VMINT vm_sal_phb_get_used_contacts(vm_phb_contact_pos_struct* pos_array,  vm_phb_storage_loc_enum storage);
 
 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_get_used_contacts_count
 * DESCRIPTION
 *  get used number items
 * PARAMETERS
 *  storage : [IN]               
 * RETURNS
 *  number of items
 *****************************************************************************/
VMINT vm_sal_phb_get_used_contacts_count(vm_phb_storage_loc_enum storage);

 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_get_group_list_count
 * DESCRIPTION
 *  get count in group
 * PARAMETERS     
 * RETURNS
 *  number
 *****************************************************************************/
VMINT vm_sal_phb_get_group_list_count(void);
 
 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_delete_contact
 * DESCRIPTION
 *  get group
 * PARAMETERS
 *  group_array : [OUT]        
 *  group_array_len : [IN]        
 * RETURNS
 *  number
 *****************************************************************************/
VMINT vm_sal_phb_get_group_list(vm_phb_group_struct* group_array, VMINT  group_array_len);
 
 /*****************************************************************************
 * FUNCTION
 *  vm_sal_phb_get_group_name_by_id
 * DESCRIPTION
 *  get group name by id
 * PARAMETERS
 *  group_id : [IN]        
 *  group_name : [OUT 
 *  len : [IN]
 * RETURNS
 *  1 success
 *  0 fail
 *****************************************************************************/
VMINT vm_sal_phb_get_group_name_by_id(VMUINT group_id, VMWCHAR*  group_name, VMINT len);


#ifdef __cplusplus
}
#endif

#endif
