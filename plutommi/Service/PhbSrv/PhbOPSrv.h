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
 *  PhbOPSrv.h
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
 *==============================================================================
 *******************************************************************************/
#ifndef PHBOPSRV_H
#define PHBOPSRV_H


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "MMIDataType.h"
#include "Phbsrvgprot.h"
#include "Phbsrv.h"
#ifdef __MMI_MULTI_VCARD__
#include "vcard_lib.h"
#endif

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/
#define MMI_PHB_CONTACT_FIELD_LIST              (MMI_PHB_CONTACT_FIELD_NAME | MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL) /* query support fields */

#define SRV_PHB_QUERY_ITEM_COUNT                (200)

#define SRV_PHB_QUERY_PID_COUTN                 (100)

#define SRV_PHB_QUERY_INVALID_PID               (0)

#define SRV_PHB_QUERY_MAX_PID                   (0x6fffffff)

/****************************************************/
/*                                                  */
/*               Enum                               */
/*                                                  */
/****************************************************/


/****************************************************/
/*                                                  */
/*               Struct                             */
/*                                                  */
/****************************************************/

typedef struct
{
    S32 result;
    srv_phb_op_cb_type_enum type;
    MMI_BOOL is_canceled;
    MMI_BOOL is_stoped;
    void* user_data;
    srv_phb_async_op_callback_type cb;
} srv_phb_op_handle_struct;

typedef struct
{
    S32 result;
    srv_phb_op_cb_type_enum type;
    MMI_BOOL is_canceled;
    MMI_BOOL is_stoped;
    void* user_data;
    srv_phb_async_op_callback_type cb;
    mmi_phb_contact_id* id_array;
    srv_phb_contact contact;
    srv_phb_field_filter filter;
    U8 src_storage;
    U8 dest_storage;
    U16 active_index;
    U16 total_count;
    U16 finish_count;
    U16 fail_count;
    mmi_phb_contact_id id;
#ifdef __MMI_MULTI_VCARD__
    VB_HANDLE b_handle;
    VP_HANDLE p_handle;
    vcard_object_struct* vcard_object;
#endif
    /*S32 cloud_handle;
    U32 provider;
    U8  account_id;*/
} srv_phb_multi_op_handle_struct;

typedef struct
{
    S32 result;
    srv_phb_op_cb_type_enum type;
    MMI_BOOL is_canceled;
    MMI_BOOL is_stoped;
    void* user_data;
    srv_phb_async_op_callback_type cb;
    mmi_phb_contact_id id;
    srv_phb_contact contact;
} srv_phb_single_op_handle_struct;


typedef struct
{
    mmi_phb_contact_id id;
    mmi_phb_contact_field_id_enum align_field;
    U8 save_index;
    srv_phb_query_match_info_struct match_info;
} srv_phb_query_item_struct;


typedef struct _srv_phb_query_node_struct
{
    struct _srv_phb_query_node_struct* next;
    srv_phb_query_item_struct item[SRV_PHB_QUERY_ITEM_COUNT];
} srv_phb_query_node_struct;


typedef struct
{
    mmi_phb_contact_id id;
    U8 save_index;
} srv_phb_query_num_item_struct;


typedef struct _srv_phb_query_num_node_struct
{
    struct _srv_phb_query_num_node_struct* next;
    srv_phb_query_num_item_struct item[SRV_PHB_QUERY_ITEM_COUNT];
} srv_phb_query_num_node_struct;


#define MMI_PHB_PINYIN_CACHE_COUNT              (15)
#define MMI_PHB_CONTACT_FIELD_QUERY             (MMI_PHB_CONTACT_FIELD_NAME | MMI_PHB_CONTACT_FIELD_NUMBER) /* query support fields */


typedef struct
{
    WCHAR ori_char;                               /* original char */
    U16 len;
    WCHAR pinyin[MMI_PHB_MAX_PINYIN_LENGTH];      /* converted string */
} srv_phb_pinyin_cache_struct;


typedef struct
{
    U16* ime_table;
    WCHAR* keymap[10];                        //key 0-9 map char
    U16 keysize[10];                        //key 0-9 map char size
} srv_phb_key_cache_struct;


typedef struct
{
    srv_phb_pinyin_cache_struct pinyin_cache[MMI_PHB_PINYIN_CACHE_COUNT];
    MMI_BOOL cov_pinyin;
    U8 buffer_len;
    WCHAR* buffer_1;        /* dest compare buffer */
    WCHAR* buffer_2;        /* first char compare buffer */
    srv_phb_key_cache_struct key_info;
} srv_phb_query_cache_struct;


typedef struct
{
    U16 query_index;
    U16 start_index;
    U16 query_time;
    U16 now_match_field;
    srv_phb_query_async_func_type callback_func; 
    void *user_data;
} srv_phb_query_async_context_struct;


typedef struct
{
    U8 name_offset;
    MMI_BOOL is_new;
    MMI_BOOL wait_new;
    U8 conv_start;
    CHAR conv_len;
    U8 f_char_start;
    U8 f_char_len;
    WCHAR conv_buffer[SRV_PHB_QUERY_PATTERN_LEN * MMI_PHB_MAX_PINYIN_LENGTH];
    WCHAR f_char_buffer[SRV_PHB_QUERY_PATTERN_LEN];
    U8 conv_char_pos[SRV_PHB_QUERY_PATTERN_LEN * MMI_PHB_MAX_PINYIN_LENGTH];
} srv_phb_cov_name_cntx_struct;


typedef struct
{
    srv_phb_query_mem_alloc_func_type  mem_alloc_func;
    srv_phb_query_mem_free_func_type   mem_free_func;
    void *user_data;
} srv_phb_query_mem_entry_struct;


typedef struct
{
    srv_phb_query_type_enum type;
    U16 pattern_len;
    WCHAR pattern[SRV_PHB_QUERY_PATTERN_LEN + 1];
    U32 query_field;
    srv_phb_query_cache_struct cache;
    U16 match_field;
} srv_phb_query_cntx_struct;


#ifdef __MMI_PHB_CALLER_GROUP__
typedef struct
{
    U8 group_mask[MMI_PHB_GROUP_FIELD_SIZE];
    #if defined(__MMI_PHB_USIM_SUPPORT__) || defined(__SRV_PHB_TCARD_STORAGE_SUPPORT__)
    phb_storage_enum storage;
    #endif
    MMI_BOOL is_equal;
    U8* group_field;
} srv_phb_group_cntx_struct;
#endif /* __MMI_PHB_CALLER_GROUP__ */


typedef struct
{
    U32 field_type;
    U8 storage_mask;
    srv_phb_query_cntx_struct* query_cntx;
#ifdef __MMI_PHB_CALLER_GROUP__
    srv_phb_group_cntx_struct* group_cntx;
#endif

    srv_phb_query_mem_entry_struct mem_entry;

    srv_phb_query_async_context_struct query_async_cntx; 
} srv_phb_contact_filter_struct;


typedef struct
{
    srv_phb_query_node_struct* head;
    srv_phb_query_node_struct* tail;
    srv_phb_query_num_node_struct* num_head;
    srv_phb_query_num_node_struct* num_tail;
#ifdef __MMI_DIALER_SEARCH__
    SRV_CLOG_ID* clog_id;
    U16 clog_item;
#endif
    U16 contact_item;
    U16 number_item;
    U16 total_item;
    srv_phb_contact contact;
    srv_phb_query_match_info_struct match_info; /* common match info for number matched */
    srv_phb_alpha_info_struct alpha_table[SRV_PHB_ALPHA_LIST_COUNT + 2];
    MMI_BOOL gen_table;  /* alpha table is gen */
    U16 malloc_count;
    U16 number_malloc;

    // query async
    U32 pid;
    U16 match_field; // 0: name, 1: number, notice begin 0
    // asm memory
    srv_phb_query_mem_entry_struct mem_entry;
} srv_phb_query_struct;


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/* Define your local variable here */


/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_op_flag
 * DESCRIPTION
 *  get stop op flag
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
MMI_BOOL srv_phb_get_op_flag(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_multi_op_status
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
*****************************************************************************/
void srv_phb_update_multi_op_status(srv_phb_multi_op_handle_struct* handle);


/*****************************************************************************
* FUNCTION
*  srv_phb_multi_op_done
* DESCRIPTION
*  
* PARAMETERS
*         
* RETURNS
*  void
*****************************************************************************/
void srv_phb_multi_op_done(void* info);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_op_get_index_by_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_op_get_index_by_storage(U16 active_index, U8 storage, mmi_phb_contact_id* id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_search_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_query_search_pid(U32 pid);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_remove_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_query_remove_pid(U32 pid);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_insert_pid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_query_insert_pid(U32 pid);


/*****************************************************************************
* FUNCTION
*  srv_phb_free_link_ex
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_phb_free_link_ex(srv_phb_node_struct* head, srv_phb_node_struct* tail, srv_phb_query_mem_entry_struct *mem_entry_p);


#ifdef __VCARD_CLOUD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_backup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_cloud_backup(srv_phb_multi_op_handle_struct* handle, U32 provider, U8 account_id, srv_cloud_mem_alloc malloc_func, srv_cloud_mem_free free_func);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_restore
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_cloud_restore(srv_phb_multi_op_handle_struct* handle, U32 provider, U8 account_id, srv_cloud_mem_alloc malloc_func, srv_cloud_mem_free free_func);
#endif


#endif /* PHBOPSRV_H */ 

