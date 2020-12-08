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
 * MMSMemoryManagerSrv.h
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
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef MMS_SRV_MEM_H
#define MMS_SRV_MEM_H

#include "MMI_features.h"
#ifdef __MMI_MMS_2__
#include "kal_general_types.h"
#include "custom_wap_config.h"
#include "MmsSrvGprot.h"
#include "MMSAppUICommon.h"
#include "kal_public_defs.h"
#include "MMIDataType.h"
#define SRV_MMS_MAX_ASM_POOL 5

#define APPLIB_MEM_AP_ID_ADM_UMMS 2

typedef void (*app_asm_sucess_cb) (void);
typedef void (*stop_app_cb) (void *);

/* USE DETAILS */
#define SRV_MMS_VIEWER_MAX_USE_DETAILS (60)
#define SRV_MMS_VIEWER_MAX_USE_DETAILS_PER_SLIDE (15)
#define SRV_MMS_VIEWER_MAX_URL_LEN    (512)
/* sizeof(applib_address_node_struct) +SRV_MMS_VIEWER_MAX_URL_LEN */
#define SRV_MMS_VIEWER_USE_DETAIL_STRUCT_SIZE (24+SRV_MMS_VIEWER_MAX_URL_LEN)

/* ADDRESSES */
#define SRV_MMS_VIEWER_MAX_ADDRESS_LEN (312)    /* MMI_UC_MAX_ADDR_LEN */
/* sizeof(applib_address_node_struct) + SRV_MMS_VIEWER_MAX_ADDRESS_LEN */
#define SRV_MMS_VIEWER_ADDRESS_STRUCT_SIZE (24+SRV_MMS_VIEWER_MAX_ADDRESS_LEN)
#define SRV_MMS_VIEWER_MAX_MMS_ADDRESSES (WAP_CUSTOM_CFG_MAX_MMS_ADDRESS)

/* OBJECTS */
#define SRV_MMS_VIEWER_MAX_OBJECTS_PER_SLIDE (3)
#define SRV_MMS_VIEWER_MAX_SLIDES (WAP_CUSTOM_CFG_MAX_MMS_SLIDES)
#define SRV_MMS_VIEWER_MAX_OBJECTS (SRV_MMS_VIEWER_MAX_OBJECTS_PER_SLIDE * SRV_MMS_VIEWER_MAX_SLIDES)
#define SRV_MMS_VIEWER_MAX_FILE_PATH_LEN (260 * 2)
#define SRV_MMS_VIEWER_MAX_FILE_NAME_LEN (100 * 2)

/*  + sizeof(mmi_mv_attachment_info_struct) 
   + sizeof(wgui_mv_object_struct) 
   + sizeof(wgui_mv_slide_struct) 
   + SRV_MMS_VIEWER_MAX_FILE_PATH_LEN 
   + SRV_MMS_VIEWER_MAX_FILE_NAME_LEN */
#define SRV_MMS_VIEWER_MMS_OBJECT_STRUCT_SIZE (200 + SRV_MMS_VIEWER_MAX_FILE_PATH_LEN + SRV_MMS_VIEWER_MAX_FILE_NAME_LEN )

/* TEXT */
/* Temp UTF-8 Buffer's Size */
#define SRV_MMS_VIEWER_MAX_UTF8_TXT_SLIDE_LEN (20480)
/* UCS2 Buffer's Size (made from UTF-8 buffer) */
#define SRV_MMS_VIEWER_TXT_BUF_UCS2_SIZE (SRV_MMS_VIEWER_MAX_UTF8_TXT_SLIDE_LEN * 2)
/* Buffer supplied to multiline inputbox */
#define SRV_MMS_VIEWER_TXT_INPUTBOX_BUFFER_SIZE (5120)  /* CAT630_MAIN_TXT_BUFFER_SIZE => 512*5 *ENCODING_LENGTH */

/* USE DETAIL MEMORY REQUIREMENT */
#define SRV_MMS_VIEWER_USE_DETAIL_MEM_SIZE (SRV_MMS_VIEWER_USE_DETAIL_STRUCT_SIZE * SRV_MMS_VIEWER_MAX_USE_DETAILS)
/* ADDRESSES MEMORY REQUIREMENT */
#define SRV_MMS_VIEWER_ADDRESSES_MEM_SIZE (SRV_MMS_VIEWER_ADDRESS_STRUCT_SIZE * SRV_MMS_VIEWER_MAX_MMS_ADDRESSES)
/* OBJECTS MEMORY REQUIREMENT */
#define SRV_MMS_VIEWER_OBJECT_MEM_SIZE (SRV_MMS_VIEWER_MMS_OBJECT_STRUCT_SIZE * SRV_MMS_VIEWER_MAX_OBJECTS )
/* TEXT MEMORY REQUIREMENT */
#define SRV_MMS_VIEWER_TEXT_MEM_SIZE (SRV_MMS_VIEWER_MAX_UTF8_TXT_SLIDE_LEN +  SRV_MMS_VIEWER_TXT_BUF_UCS2_SIZE + SRV_MMS_VIEWER_TXT_INPUTBOX_BUFFER_SIZE)

#define SRV_MMS_VIEWER_CONTEXT_MEM_SIZE ((SRV_MMS_VIEWER_USE_DETAIL_MEM_SIZE) + \
                                (SRV_MMS_VIEWER_ADDRESSES_MEM_SIZE) +           \
                                (SRV_MMS_VIEWER_OBJECT_MEM_SIZE) +              \
                                (5 * 1024))

/* This size reduction is because of xml removal activity reduced but forced Ram usage */
/* So we are reducing overall Object support and reducing ASM usage to 120 K */
#if defined (__MMI_MMS_SIMPLIFIED_UI_SUPPORT__)
#define SRV_MMS_VIEWER_ASM_MEM_POOL_SIZE (120 * 1024)
#define SRV_MMS_TXT_COMPOSE_BUF_UCS2_SIZE (4 * 1024)
#define SRV_MMS_MAX_COMPOSE_UTF8_TXT_SLIDE_LEN (6 * 1024)
#elif defined(__MMI_MMS_USE_ASM__)
#define SRV_MMS_VIEWER_ASM_MEM_POOL_SIZE (120 * 1024)
#else 
#define SRV_MMS_VIEWER_ASM_MEM_POOL_SIZE ( SRV_MMS_VIEWER_TEXT_MEM_SIZE + SRV_MMS_VIEWER_CONTEXT_MEM_SIZE )
#endif 

#define APPLIB_MEM_AP_ID_ADM_UMMS 2

typedef void (*app_asm_sucess_cb) (void);
typedef void (*stop_app_cb) (void *);
typedef void (*cancel_app_cb) (void *);
typedef void *(*mem_alloc_fn) (U32 size, void *user_data);
typedef void *(*mem_free_fn) (void *mem);
typedef void *(*mem_free_ext_fn) (void *mem, void *user_data);
typedef struct
{
    KAL_ADM_ID adm_pool_id;
    PU8 ptr_asm_pool;
    kal_uint32 app_asm_id;
    U16 img_id;
    U16 str_id;
    kal_uint32 app_pool_size;
    kal_uint32 app_id;
    MMI_UMMS_ERROR is_used;
    app_asm_sucess_cb success_cb;
    stop_app_cb stop_cb;
    cancel_app_cb cancel_cb;
    mem_alloc_fn alloc_fn;
    mem_free_fn free_fn;
    void *user_data;
} srv_mms_mem_mgr_get_asm_alloc_struct;

/* init asm context for viewer */
extern void srv_mms_mem_mgr_init_viewer_asm_pool(
                U16 app_asm_id,
                U32 index,
                srv_mms_mem_mgr_get_asm_alloc_struct *asm_in_cntx);

/* init asm context for app */
extern void srv_mms_mem_mgr_init_app_asm_pool(
                U16 app_asm_id,
                U32 index,
                srv_mms_mem_mgr_get_asm_alloc_struct *asm_in_cntx);

#ifdef __MMI_MMS_USE_ASM__
/* init asm context for mms service */
extern void srv_mms_mem_mgr_init_asm_for_service_ext(U32);
#endif

/* alloc asm pool GENERIC */
extern MMI_UMMS_ERROR srv_mms_mem_mgr_alloc_asm_pool(U16 app_asm_id, U32 index);

/* check if already alloc asm pool */
extern MMI_BOOL srv_mms_is_asm_alloc_done(U32 index);

/* Delete asm pool GENERIC */

extern void srv_mms_mem_mgr_asm_deinit_memory(U16 app_asm_id, U32 index);

/* memory manger asm related */

extern void *srv_mms_mem_mgr_viewer_asm_alloc(U32 size);

extern void *srv_mms_mem_mgr_app_asm_alloc(U32 size);

extern void *srv_mms_mem_mgr_viewer_asm_alloc_userdata(U32 size, void* user_data);

extern void srv_mms_mem_mgr_viewer_asm_free_userdata(void *pmem, void* user_data);

extern void srv_mms_mem_mgr_viewer_asm_free(void *pmem);

extern void srv_mms_mem_mgr_app_asm_free(void *pmem);

extern void srv_mms_mem_mgr_init_app_adm(void);

extern void *srv_mms_mem_mgr_app_adm_alloc(U32 size);

extern void srv_mms_mem_mgr_app_adm_free(void *pmem);

extern BOOL srv_mms_mem_mgr_app_adm_low_memory(void);

extern MMI_UMMS_ERROR srv_mms_mem_mgr_check_asm_total_pool(app_asm_sucess_cb success_cb, U32 index);

void srv_mms_mem_mgr_copy_pools(U32 index, U16 asm_id);

/* ASM Support For MMS Core */

#ifdef __MMI_MMS_USE_ASM__

extern MMI_UMMS_ERROR srv_mms_mem_mgr_init_asm_for_service(void);

extern MMI_BOOL srv_mms_mem_mgr_get_asm_pool_for_service_req_hdlr(void *inreq);

extern void srv_mms_mem_mgr_success_cb_asm_for_service(void);

extern void srv_mms_mem_mgr_stop_cb_asm_for_service(void *);

extern void srv_mms_mem_mgr_cancel_cb_asm_for_service(void *cancel_info);

extern MMI_BOOL srv_mms_free_asm_pool_for_service_req(void *inreq);

extern void srv_mms_mem_mgr_send_deinit_asm_memory_req(void);

extern void srv_mms_deinit_asm_pool_for_service_rsp(void *rsp);

extern MMI_BOOL srv_mms_check_asm_memory_is_int(void);

#endif /* __MMI_MMS_USE_ASM__ */ 

#endif /* __MMI_MMS_2__ */ 
#endif /* MMS_SRV_MEM_H */ 

