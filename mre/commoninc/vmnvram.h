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
 * vmnvram.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * nvram
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
 * removed!
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

#ifndef VMNVRAM_H_
#define VMNVRAM_H_
#include "vmswitch.h"

#include "vmsys.h"

#ifdef __cplusplus
extern "C" {
#endif

#define VM_NVRAM_RW_ERROR -1

#define PK_CONTENT_LEN		(200)

#define ROOT_PK_LIST_SIZE   (8)

#define BAN_LIST_SIZE		(256)

#define NVRAM_PKEY_LIST_NUM								(3648)

#define ROOT_MTK_PK_LIST_SIZE   (16)


typedef struct 
{
	VMINT pkey_index;	
	VMINT8 pkey_content[PK_CONTENT_LEN];
	vm_time_t pkey_time_stamp;
} vm_pkey_t;

typedef struct 
{
	VMINT pkey_index;	
	VMINT8 pkey_content[164];
	vm_time_t pkey_time_stamp;
} vm_pkey_ex_t;


typedef struct 
{
	vm_pkey_t pkey_item[ROOT_PK_LIST_SIZE];
} vm_nvram_root_pkey_list_t;


typedef struct 
{
	VMUINT app_ban_item[BAN_LIST_SIZE];
	vm_time_t app_ban_time_stamp;
} vm_nvram_app_ban_list_t;

typedef struct 
{
	VMUINT8 firstflag;
	VMUINT8 flag[ROOT_MTK_PK_LIST_SIZE];
}vm_nvram_setting_list_t;

#define SYM_PERMISSION_LEN 200

typedef enum 
{
	VM_ENTRY_REFUSE = 0, 
	VM_ENTRY_ACCEPT = 1 
} vm_permission_e;

typedef struct 
{
	VMINT operate_index;
	vm_permission_e permission;
} vm_permission_t;


typedef struct
{
	VMINT vm_sym_permission_list_len;
	vm_permission_t vm_sym_permission_list[SYM_PERMISSION_LEN];
} vm_nvram_permission_list_t;   


typedef struct
{
	vm_time_t sys_time_stamp[5]; 
	VMINT uid;
	VMINT mobile_phone_id;
} vm_nvram_sysconf_t;

#ifdef __MRE_CORE_SAFETY__


VMINT vm_nvram_get_pkey_list(VMINT list_index, vm_nvram_root_pkey_list_t * pkey_list);

VMINT vm_nvram_set_pkey_list(VMINT list_index, vm_nvram_root_pkey_list_t * pkey_list);

VMINT vm_nvram_adjust_pkey_list(vm_nvram_root_pkey_list_t * pkey_list, vm_nvram_root_pkey_list_t * pkey_list_bak);

VMINT vm_nvram_get_ban_list(vm_nvram_app_ban_list_t * ban_list_ptr);

VMINT vm_nvram_set_ban_list(vm_nvram_app_ban_list_t * ban_list_ptr);

VMINT vm_load_app_ban_list(void);

void vm_unload_app_ban_list(void);

VMINT vm_app_in_ban_list(VMUINT app_id);

VMINT vm_nvram_set_sym_permission(vm_nvram_permission_list_t * permission_list_ptr);

VMINT vm_nvram_get_sym_permission(vm_nvram_permission_list_t * permission_list_ptr);

VMINT vm_nvram_write_record(VMUINT16 rec_name, VMUINT16 rec_index, VMINT rec_size, void* write_buff, VMUINT16 buff_len);

VMINT vm_nvram_read_record(VMUINT16 rec_name, VMUINT16 rec_index, VMINT rec_size, void* read_buff, VMUINT16 buff_len);

#endif

VMINT vm_get_sysconf(vm_nvram_sysconf_t * sysconfig_ptr);

VMINT vm_set_sysconf(vm_nvram_sysconf_t * sysconfig_ptr);


#ifdef __cplusplus
}
#endif


#endif



