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
 *  vmpromng.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  MRE process management header file
 *
 * Author:
 * -------
 *   
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#ifndef	_VM_PRO_MNG_
#define _VM_PRO_MNG_


#include "vmpromng_sdk.h"

#ifdef __cplusplus
extern "C" {
#endif

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
* FUNCTION
 *    vm_pmng_init
 * DESCRIPTION
 *  initialize process management and only invoked when start MRE core.
 * RETURNS
 *  If succeed it will return VM_PMNG_OP_OK, else will returns error code
*****************************************************************************/
VMINT vm_pmng_init(void);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_finialize
 * DESCRIPTION
 *  finalize process management and invoked only after all the other module release and 
 *  before MRE core exit.
*****************************************************************************/
void vm_pmng_finialize(void);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_finialize_ex
 * DESCRIPTION
 *  finalize process management and invoked only after all the other module release and 
 * PARAMETERS
 *  param : [IN]  the reason of finialize. 
 *  before MRE core exit.
*****************************************************************************/
void vm_pmng_finialize_ex(VMINT param);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_create_process
 * DESCRIPTION
 *  create a process for specified file name. If the application has been created, 
 *  it will come to foreground running, else start it and make it foreground running.
 *  MRE application can invoke this function to create its child process during foreground
 *  running, if create successfully it will receive HIDE message and go to background state.
 * PARAMETERS
 *  file_name : [IN]  file name of full path encoding with UCS2 format.
 * RETURNS
 *  process ID if create successfully, error code if failed.
 * RETURN VALUES                                      
 *  VM_PMNG_NO_OP_IN_STATUS : current application is not during foreground state.
 *  VM_PMNG_ERROR_PARAM : parameter error.
 *  VM_PMNG_ERROR_IO :  vxp file operation error. 
 *  VM_PMNG_NO_MEM : insufficient memory.
 *  VM_PMNG_NO_SCHEDULE : can not enter foreground state for running application.
 *  VM_PMNG_SEC_TAG_PLATFORM_PARAM_DISMATCH : platform is dismatch with application tag.
 *  VM_PMNG_SEC_APP_TIMESTAMP_ERROR : application is out of date.
 *  VM_PMNG_SEC_IMSI_DISMATCH : IMSI dismatch with application.
 *  VM_PMNG_SEC_BAN_LIST_APP : application is in ban list.
 *  VM_PMNG_SEC_INVALIDATE_APP : cerfication verification failed.
 *  VM_PMNG_SEC_CERT_OMREDUE : cerfication 
 *  
*****************************************************************************/
    VM_P_HANDLE vm_pmng_create_process(VMWSTR fileName, VMUINT8* mem_base);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_delete_process
 * DESCRIPTION
 *  delete specified process. This function can be invoked only by AM or the parent process of specified process.
 *  If no other process running after delete this one, MRE core will exit.
 * PARAMETERS
 *  p_handle : [IN]  process handle to be deleted.
 * RETURNS
 *  result of deletion
 * RETURN VALUES                                      
 *  VM_PMNG_OP_OK : delete successfully.
 *  VM_PMNG_PROCESS_NO_EXISTS : specified process does not exist.
 *  
*****************************************************************************/
VMINT vm_pmng_delete_process(VM_P_HANDLE p_handle);

/* DOM-NOT_FOR_SDK-END */

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
* FUNCTION
 *    vm_pmng_max_counter
 * DESCRIPTION
 *  get the maxium number of process that can be created.
 * RETURNS
 *  maxium number of process that can be created.
 *  
*****************************************************************************/
VMINT vm_pmng_max_counter(void);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_current_counter
 * DESCRIPTION
 *  get the number of process that have created already.
 * RETURNS
 *  the number of process that have created already.
 *  
*****************************************************************************/
VMINT vm_pmng_current_counter(void);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_fg_process
 * DESCRIPTION
 *  get the process ID of current running.
 * RETURNS
 *  the process ID of current running if larger than zero, 0 means no process running 
 *  
*****************************************************************************/
VM_P_HANDLE vm_pmng_fg_process(void);

/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
* FUNCTION
 *    vm_pmng_is_fg
 * DESCRIPTION
 *  check the specified process is foreground state or not.
 * RETURNS
 *  TRUE means foreground state, FALSE means not in foreground state.
*****************************************************************************/
VMINT vm_pmng_is_fg(VM_P_HANDLE p_handle);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_send_sys_msg
 * DESCRIPTION
 *  send message to specified process
 * PARAMETERS
 *  p_handle : [IN]  process handle to be checked. If want to get current process state,
 *  it should be VM_PMNG_CUR_HANDLE.
 *  user_message : [IN] message ID
 *  memsage_param : [IN] message data
 * RETURNS
 *  result of sending message
* RETURN VALUES                                      
 *  VM_PMNG_OP_OK : send successfully
 *  VM_PMNG_PROCESS_NO_EXISTS : specified process does not exist.
 *  VM_PMNG_ERROR_PARAM : message ID is smaller than 5000
 *  
*****************************************************************************/
VMINT vm_pmng_send_sys_msg(VM_P_HANDLE p_handle, VMINT user_message, VMINT memsage_param);

#define	PMNG_WRAP_CALLBACK(PHANDLE, APP_CALLBACK_CALLER) \
    if (vm_pmng_set_ctx(PHANDLE) == VM_PMNG_OP_OK){\
        APP_CALLBACK_CALLER;\
        vm_pmng_reset_ctx();\
    }

/*****************************************************************************
* FUNCTION
 *    vm_pmng_set_ctx
 * DESCRIPTION
 *  set context of specified process. This function must be called before callback to 
 *  MRE application code. Also vm_pmng_reset_ctx() must be called after callback function
 *  returned.
 * PARAMETERS
 *  p_handle : [IN]  process handle to be set
 * RETURNS
 *  result of setting context.
* RETURN VALUES                                      
 *  VM_PMNG_OP_OK : send successfully
 *  VM_PMNG_PROCESS_NO_EXISTS : specified process does not exist.
 *  VM_PMNG_NO_OP_IN_STATUS : this will be returned if re-invoke this function without
 *                                                vm_pmng_reset_ctx().
 * EXAMPLE                                   [this TAG is optional]
  * <code>
  * if (vm_pmng_set_ctx(handle) == VM_PMNG_OP_OK)
  * {
  *     app_callback(event);
  *     vm_pmng_reset_ctx();
  * }
  * </code>
 *  
*****************************************************************************/
VMINT vm_pmng_set_ctx(VM_P_HANDLE p_handle);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_reset_ctx
 * DESCRIPTION
 *  reset context. This function must be called to reset the context of vm_pmng_set_ctx()
 *  after return from callback.
 * RETURNS
 *  result of resetting context.
* RETURN VALUES                                      
 *  VM_PMNG_OP_OK : send successfully
 *  VM_PMNG_NO_OP_IN_STATUS : if no vm_pmng_set_ctx() invoked before this.
 *  
*****************************************************************************/
VMINT vm_pmng_reset_ctx(void);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_file_name
 * DESCRIPTION
 *  get file name of specified process
 * PARAMETERS
 *  p_handle : [IN]  process handle to be checked. 
 *  filename_buf : [OUT] output file name string encoding with UCS2 format.
 *  filename_len : [OUT] output filename_buf length.
 * RETURNS
 *  result of getting file name.
* RETURN VALUES                                      
 *  VM_PMNG_OP_OK : send successfully
 *  VM_PMNG_ERROR_PARAM : parameter error.
 *  VM_PMNG_PROCESS_NO_EXISTS : specified process does not exist.
 *  
*****************************************************************************/
VMINT vm_pmng_file_name(VM_P_HANDLE p_handle, VMWCHAR* filename_buf, VMINT filename_len);

VMINT vm_pmng_destroy_bg_process(VMWSTR filename);

VMINT vm_pmng_get_process_lst(VM_PROCESS_STATUS status, VM_P_HANDLE** pHandle, 
    VMUINT* process_num);

/*****************************************************************************
* FUNCTION
 *    vm_pmng_app_id
 * DESCRIPTION
 *  get app_id of specified process
 * PARAMETERS
 *  p_handle : [IN]  process handle to be checked. 
 * RETURNS
 *  app_id of specified process or 0.
 *  
*****************************************************************************/
VMINT vm_pmng_app_id(VM_P_HANDLE p_handle);

/* DOM-NOT_FOR_SDK-END */


/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
* FUNCTION
 *    vm_pmng_is_support_bg
 * DESCRIPTION
 *  check specified process support background running or not
 * PARAMETERS
 *  p_handle : [IN]  process handle to be checked. 
 * RETURNS
 *  TRUE means support background running, FALSE means not support.
 *  
*****************************************************************************/
VMINT vm_pmng_is_support_bg(VM_P_HANDLE p_handle);

VMINT vm_send_system_message(VM_P_HANDLE handle,VMINT msg, VMINT param);

/* DOM-NOT_FOR_SDK-END */

VMINT vm_pmng_set_bg_ex(VM_P_HANDLE pHandle);
VM_P_HANDLE vm_pmng_set_fg_ex(VM_P_HANDLE pHandle);
VMINT vm_pmng_set_inactive(VM_P_HANDLE pHandle);

VMINT vm_pmng_set_ctx_vrt(VM_P_HANDLE p_handle);
VMINT vm_pmng_reset_ctx_vrt(void);

#ifdef __cplusplus
}
#endif

#endif
