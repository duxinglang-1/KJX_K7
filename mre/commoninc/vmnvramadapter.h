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
 * vmnvramadapter.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VM_NVRAM_ADAPTER
#define __VM_NVRAM_ADAPTER
#include "vmswitch.h"

#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmnvram.h"
#include "vmrsa.h"

#define VM_ADAPTER_NVRAM_SUCCESS			(0)

#define VM_ADAPTER_NVRAM_NOT_FOUND_RECORD	(1)

#define VM_ADAPTER_NVRAM_ERROR_MEM			(-1)

#define VM_ADAPTER_NVRAM_ERROR_PARAM		(-2)

#define VM_ADAPTER_NVRAM_INTERNAL_ERROR		(-3)

#define VM_ADAPTER_NVRAM_OVERFLOW_STORAGE	(-4)

VMINT vm_save_mobile_phone_id_record(VMINT mid);

VMINT vm_save_user_id_record(VMINT uid);

VMINT vm_load_mobile_phone_id_record(VMINT* mid);

VMINT vm_load_user_id_record(VMINT* uid);

typedef enum 
{
	VM_NVRAM_SYSTEM_TIMESTAMP = 0,
	VM_NVRAM_BAN_APP_LST_TIMESTAMP,
	VM_NVRAM_SYS_PERMISSION_TIMESTAMP,
	VM_NVRAM_PUBLIC_CERT_LST_TIMESTAMP,
	VM_NVRAM_MAX_TIMESTAMP
} TIMESTAMP_TYPE;

VMINT vm_merge_timestamp(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP], 
	vm_time_t* curr_timestamp, TIMESTAMP_TYPE time_type);

VMINT vm_split_timestamp(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP], 
	vm_time_t* curr_timestamp, TIMESTAMP_TYPE time_type);

VMINT vm_save_timestamps_record(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP]);

VMINT vm_load_timestamps_record(vm_time_t timestamps[VM_NVRAM_MAX_TIMESTAMP]);

#ifdef __MRE_CORE_SAFETY__

typedef struct {
	VMKey pKey;
	vm_time_t timestamp;
} vm_cert_record;

typedef vm_permission_t sys_permission_record;


VMINT vm_save_ban_app_lst_records(VMUINT* ban_app_lst, VMUINT lst_num);

VMINT vm_save_sys_permission_lst_records(sys_permission_record* permission_lst, 
	VMUINT lst_num);

VMINT vm_save_cert_lst_records(vm_cert_record* cert_lst, VMUINT lst_num);

/************************************************************************************/

#endif

#define			VM_PRECISE_COMMAND_SMS_TYPE			(1)
#define			VM_FUZZY_COMMAND_SMS_TYPE			(2)

#ifdef __cplusplus
}
#endif



#endif
