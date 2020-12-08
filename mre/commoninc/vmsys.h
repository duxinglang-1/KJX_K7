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
 * Vmsys.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   mre system head file
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
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




#ifndef VMSYS_H_
#define VMSYS_H_

#include "mmi_features.h"

#if (defined (__FLAVOR_MRE_SDK_VENDOR__) || defined (__FLAVOR_MRE_SDK_VENDOR_EXPRESS__) || \
    defined (__FLAVOR_MRE_SDK_QVGA__) || \
    defined (__FLAVOR_MRE_SDK_WQVGA__) || \
    defined (__FLAVOR_MRE_SDK_HVGA__) || \
    defined (__FLAVOR_MRE_SDK_WVGA__) || \
    defined (__FLAVOR_MRE_SDK_LQVGA__) || \
    defined (__FLAVOR_MRE_SDK_QQVGA__) || \
    defined (__FLAVOR_MRE_SDK_QCIF__))
#define MRE_ENABLE_MEM_DEBUG
#endif

#define MRE_LOCK //kal_take_mutex(mre_mutex_id)
#define MRE_UNLOCK //kal_give_mutex(mre_mutex_id)


#include "vmsys_sdk.h"


#ifdef __cplusplus
extern "C" {
#endif

/* MRE VSM/VSO memory structure */
typedef struct
{
    VMUINT8* mem_base;
    VMINT   mem_size;
    VMINT p_handle;
    void* adm_id;
#ifdef MRE_ENABLE_MEM_DEBUG
	malloc_stat_t mem_stat;
#endif
	VMINT heap_size;
}vm_vsm_mem_struct;

void vm_restore_sb(VMINT sb);

extern VMINT g_vm_stub_sb;

extern VMINT g_vm_stub_sb_vrt;

#define VM_RESTORE_PCB_SB(sb) \
{	vm_restore_sb(sb);  \
	g_vm_stub_sb = sb;   \
}

extern VMINT vm_get_running_app_sb(void);

VMINT vm_get_system_info(VMCHAR info[], VMUINT* size);
void vm_stop_mre_envirment(void);

void vm_stop_mre_envirment_ex(VMINT param);

typedef struct
{
    VMINT   handle;
    VMINT   bSaveOnCard;
    VMINT   bUseDLA;
    VMWSTR  app_path;
    vm_update_mre_app_callback callback;
    void*   user_data;
}vm_update_download_param;

typedef struct
{
    VMSTR   URL;
    VMINT   port;
    VMINT   apn;
    VMINT   app_id;
    VMWSTR  app_path;
    VMSTR   app_ver;
    VMSTR   app_info;
    vm_update_mre_app_callback callback;
    void*   user_data;
}vm_update_check_version_param;

VMINT vm_update_check_version_ex(vm_update_check_version_param *param);


VMINT vm_update_download_ex(vm_update_download_param *param);

VMINT vm_update_update_file_ex(VMWSTR path,void (*callback)(VMINT result,VMWSTR path,void* user_data),void* user_data);
#ifdef __cplusplus
}
#endif 

#endif 
