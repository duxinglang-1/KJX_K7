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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#ifndef VMDL_H_
#define VMDL_H_
#include "vmswitch.h"

#ifdef __MRE_CORE_BASE__
#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_APP_NAME_LEN					(260)

#define REDIRECT_APPNAME_SEPARATOR		L'?'

typedef VMINT (*vm_get_sym_entry_t)(char* sym);

typedef enum
{
	VM_EXEC_VXP,		/* vxp format */
	VM_EXEC_AXF,		/* axf format */
	VM_EXEC_ROM,		/* rom format */
	VM_EXEC_VSO,        /* vso file filemanager */
	VM_EXEC_DLL,		/* MoDIS support file */
	VM_EXEC_NO_FORMAT	/* no format */
} vm_exec_format_enum;

VMUINT8* vm_get_execrom_ptr(VMWSTR wfilename);

VMINT vm_get_execrom_size(VMUINT8* rom_ptr);

vm_exec_format_enum vm_parse_exec_format(VMWSTR wfilename);

VMINT vm_get_segment_from_filename(VMWSTR wfilename, VMINT file_index, VMWSTR wexec_filename, 
	VMINT wexec_filename_len);

VMINT vm_is_redirection_filename(VMWSTR exec_filename);

#define EXEC_SUCCESS								(0)
#define EXEC_INTERNAL_ERROR						(-1)
#define EXEC_ERROR_FORMAT							(-2)
#define EXEC_PARAM_ERROR							(-3)

#define EXEC_TAG_PLATFORM_PARAM_DISMATCH		(-4)
#define EXEC_APP_TIMESTAMP_ERROR					(-5)
#define EXEC_BAN_LIST_APP							(-6)
#define EXEC_INVALIDATE_APP						(-7)
#define EXEC_IMSI_DISMATCH							(-8)
#define EXEC_CERT_OMREDUE							(-9)

#define EXEC_NOT_EXEC_IN_STATUS					(-10)
#define EXEC_NO_MEM								(-11)

VMINT vm_exec(VMWSTR filename);

VMINT vm_exec_from_mem(VMUINT8 *ptr);

void vm_free_vreapp(void);

/**
 * execute format
 */
typedef enum {
	ASYN_EXECUTE_SHORTCUT_APP_TYPE = 1,	
	ASYN_EXECUTE_APP_STORE_TYPE	
} ASYN_EXECUTE_TYPE;

/**
 *  success
 */
#define APP_ASYN_EXECUTE_SUCCESS							(0)

/**
 * platform dismatch
 */
#define APP_ASYN_EXECUTE_PLATFORM_PARAM_DISMATCH		(-1)

/**
 * time error
 */
#define APP_ASYN_EXECUTE_TIMESTAMP_ERROR				(-2)

/**
 * banned app
 */
#define APP_ASYN_EXECUTE_BANNED_APP						(-3)

/**
 * invalidate app
 */
#define APP_ASYN_EXECUTE_INVALIDATE_APP					(-4)

/**
 * IMSI not dismatch
 */
#define APP_ASYN_EXECUTE_IMSI_DISMATCH					(-5)

/**
 * cert overtime
 */
#define APP_USE_CERT_OVERDUE								(-6)

/**
 * inter error
 */
#define APP_ASYN_EXECUTE_INTERNAL_ERROR					(-7)
/** @} */

#define ASYN_MAX_MEM_SIZE									(20)

typedef struct 
{
	VMWCHAR app_name[MAX_APP_NAME_LEN + 1];	
	VMINT pre_app_execute_ret;
	ASYN_EXECUTE_TYPE pre_app_execute_type;
	VMUCHAR pre_app_execute_user_data[ASYN_MAX_MEM_SIZE];
	VMUINT user_data_size;
	VMFILE pre_app_file_handle;
} vm_asyn_execute_context_t;

VMINT vm_save_execute_context(VMUCHAR* data, VMUINT data_size);

VMINT vm_load_execute_context(vm_asyn_execute_context_t* context);

#ifdef __cplusplus
}
#endif

#endif

#endif
