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
 *   jvm_resource_manager.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __JVM_RESOURCE_MANAGER_H__
#define __JVM_RESOURCE_MANAGER_H__

#define JVM_RESOUCE_ARRAY_SIZE 20
#define JVM_RESOURCE_MGR_INVALIDE_VM_ID MAX_VM_INSTANCE_NUM     /* Id used for the whole VM */
#define JVM_RESOURCE_MGR_MAX_NUM    (MAX_VM_INSTANCE_NUM + 1)

#define JVM_RES_CS_ENTER()        jvm_resource_mgr_mutex_lock()
#define JVM_RES_CS_LEAVE()        jvm_resource_mgr_mutex_unlock()

typedef struct _jvm_resource_mgr_struct
{
    kal_int32 device_type;
    kal_int32 handle;
    kal_int32(*suspend) (kal_int32 handle);
    kal_int32(*resume) (kal_int32 handle);
    kal_int32(*close) (kal_int32 handle);
} jvm_resource_mgr_struct;

typedef struct _jvm_resource_mgr_array_struct
{
    struct _jvm_resource_mgr_array_struct *next;
    kal_int32 next_free_index;  /* next_free_index == -1 means no free entry */
    jvm_resource_mgr_struct resouce[JVM_RESOUCE_ARRAY_SIZE];
} jvm_resource_mgr_array_struct;

void jvm_resource_mgr_mutex_lock(void);
void jvm_resource_mgr_mutex_unlock(void);
kal_int32 jvm_resource_mgr_initialize(void);
void jvm_resource_mgr_finalize_all(void);
void jvm_resource_mgr_finalize(kal_int32 vm_id);
kal_int32 jvm_resource_mgr_register(kal_int32 vm_id,
                                    kal_int32 device_type,
                                    kal_int32 handle,
                                    kal_int32(*suspend) (kal_int32 handle),
                                    kal_int32(*resume) (kal_int32 handle), kal_int32(*close) (kal_int32 handle));
kal_int32 jvm_resource_mgr_deregister(kal_int32 vm_id, kal_int32 device_type, kal_int32 handle);
kal_int32 jvm_resource_mgr_get_invalide_vm_id(void);

#endif /* __JVM_RESOURCE_MANAGER_H__ */ 


