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
 *  PhbSrv.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file contains internal prototypes for phb service layer.
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef PHBSRV_H
#define PHBSRV_H


/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "custom_phb_config.h"
#include "phbsrvgprot.h"
#ifdef __MMI_VCARD__
#include "vcard_lib.h"
#include "FileMgrType.h"
#endif

#include "MMI_features.h"
#include "MMI_common_app_trc.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "PhbSrvGprot.h"
#include "wgui_categories_list.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

#define SRV_PHB_TRACE_GROUP MMI_COMMON_TRC_G4_PHB

#define SRV_PHB_ALPHA_LIST_COUNT                (26)
#define MMI_PHB_MAX_PINYIN_LENGTH               (6)

#define SRV_PHB_PINYIN_LEN              10        /* Cache 10 pinyin */
#define SRV_PHB_NUM_ADV_COMP_COUNT      20        /* Compare 20 entries for number filed */

#define SRV_PHB_INVALID_NUMBER        2000000000                                /* invalid number */
#define SRV_PHB_EMPTY_NUMBER          1000000000                                /* empty number */

#ifndef min
#define min(a, b) ((a < b) ? a : b)
#endif  /* min */

/***************************************************************************** 
 * Typedef 
 *****************************************************************************/

/* phonebook number tyoe enmu */
typedef enum
{
    SRV_PHB_NUMBER_TYPE_DEFAULT = 129,    /* deafault number */
    SRV_PHB_NUMBER_TYPE_INTERNATIONAL = 145    /* international number */
} srv_phb_number_type_enum;


typedef enum
{
    SRV_PHB_GROUP_FIELD_OP_TYPE_ADD,
    SRV_PHB_GROUP_FIELD_OP_TYPE_REMOVE,
    SRV_PHB_GROUP_FIELD_OP_TYPE_SET,
    SRV_PHB_GROUP_FIELD_OP_TYPE_TOTAL
} srv_phb_group_field_op_type_enum;


typedef enum
{
    SRV_PHB_DATAMGR_OP_TYPE_ADD,
    SRV_PHB_DATAMGR_OP_TYPE_UPD,
    SRV_PHB_DATAMGR_OP_TYPE_DEL,
    SRV_PHB_DATAMGR_OP_TYPE_COPY,
    SRV_PHB_DATAMGR_OP_TYPE_TOTAL
} srv_phb_datamgr_op_type_enum;


typedef enum
{
    SRV_PHB_CHARSET_BCD = 0x01,              /* BCD  */
    SRV_PHB_CHARSET_ASCII = 0x00,            /* ASCII */
    SRV_PHB_CHARSET_UCS2 = 0x08              /* UCS2 */
#if defined(__PHB_0x81_SUPPORT__)
        ,     
    SRV_PHB_CHARSET_UCS2_81 = 0x09,          /* 0X81 */
    SRV_PHB_CHARSET_UCS2_82 = 0x10           /* 0X82 */
#endif
} srv_phb_charset_enum;


/* phonebook type enmu */
typedef enum
{
    SRV_PHB_SIM_TYPE_NONE,           /* none */    
    SRV_PHB_SIM_TYPE_ECC,            /* ECC */
    SRV_PHB_SIM_TYPE_FDN,            /* FDN */
    SRV_PHB_SIM_TYPE_BDN,            /* BDN */
    SRV_PHB_SIM_TYPE_MSISDN,         /* MSISDN */
    SRV_PHB_SIM_TYPE_SDN,            /* SDN */
    SRV_PHB_SIM_TYPE_ADN,            /* ADN */
    SRV_PHB_SIM_TYPE_GAS,            /* GAS */
    SRV_PHB_SIM_TYPE_GRP,            /* GRP */
    SRV_PHB_SIM_TYPE_ANR,            /* ANR */
    SRV_PHB_SIM_TYPE_SNE,            /* SNE */
    SRV_PHB_SIM_TYPE_TOTAL           /* other */
} srv_phb_sim_type_enum;


/* phonebook save notify enum */
typedef enum
{
    SRV_PHB_SAVE_CONTACT_NOTIFY_OFF,
    SRV_PHB_SAVE_CONTACT_NOTIFY_ON
} srv_phb_save_notify_enum;

typedef struct
{
    U16 total_count;
    U8 sim_interface;
    U8 anr_count;
    U8 email_count;
    U8 sne_count;
    U8 aas_count;
    U8 gas_count;
}srv_phb_startup_sim_init_cntx;


typedef struct _srv_phb_node_struct
{
    struct _srv_phb_node_struct* next;
} srv_phb_node_struct;


typedef struct
{
    MMI_BOOL is_busy;
    U8 op_type;
    srv_phb_update_mode_enum mode;
    U32 update_field;
    srv_phb_contact_pos_struct pos;
    mmi_phb_contact_id src_id;
    srv_phb_contact contact;
    srv_phb_op_callback_type cb;
    void* user_data;
} srv_phb_datamgr_op_cntx_struct;

typedef struct
{
    S32 result;
    mmi_phb_contact_id id;
} srv_phb_datamgr_op_status_struct;

typedef struct
{
    U8 storage;
    srv_phb_update_mode_enum mode;
    U16 record_index;
    srv_phb_contact contact;
    srv_phb_op_callback_type cb;
    void* user_data;
} srv_phb_datamgr_add_req_struct;

typedef struct
{
    mmi_phb_contact_id id;
    srv_phb_update_mode_enum mode;
    U32 update_field;
    srv_phb_contact contact;
    srv_phb_op_callback_type cb;
    void* user_data;
} srv_phb_datamgr_update_req_struct;

typedef struct
{
    mmi_phb_contact_id id;
    srv_phb_op_callback_type cb;
    void* user_data;
} srv_phb_datamgr_delete_req_struct;

typedef struct
{
    U8 storage;
    mmi_phb_contact_id id;
    srv_phb_op_callback_type cb;
    void* user_data;
} srv_phb_datamgr_copy_req_struct;

typedef struct
{
    mmi_phb_contact_id id;    /* Store Index of Phonebook, Begin from 0 */
    U32 number;
} srv_phb_lookup_number_node_struct;


typedef struct
{
    S32 result;
    mmi_phb_contact_id id;
    srv_phb_op_callback_type cb;
    void* user_data;
} srv_phb_op_fail_struct;


typedef struct
{
    U8 number_count;
    U8 number_id[MMI_PHB_NUMBER_FIELD_COUNT];   /* save index, not sub id*/
    srv_phb_query_match_info_struct match_info;
} srv_phb_query_result_struct;

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  srv_phb_stop_op
 * DESCRIPTION
 *  This func is for datamgr stop any op when phb re-init
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void srv_phb_stop_op(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
CHAR* srv_phb_datamgr_get_number(mmi_phb_contact_id id, U8 save_index, U8* type);


#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_all_phone_group_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_get_all_phone_group_field(U8* gourp_field);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_all_phone_group_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * 
 *****************************************************************************/
void srv_phb_set_all_phone_group_field(U8* gourp_field);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_pri_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_get_pri_group_info(U32 group_mask, mmi_phb_group_info_struct* group_info);
#endif /* __MMI_PHB_CALLER_GROUP__ */


#if defined(__MMI_PHB_PINYIN_SORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_util_make_pinyin_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_make_pinyin_cache(mmi_phb_contact_id id, U16* name);
#endif /* __MMI_PHB_PINYIN_SORT__ */


#if defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_phb_number_find_first_without_extension
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mid             [IN]        
 *  number          [IN]        
 *  number_in       [?]         
 * RETURNS
 *  
 *****************************************************************************/
CHAR* srv_phb_sse_remove_number_prefix(CHAR* number_in);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_compare_number
 * DESCRIPTION
 *  compare two number
 * PARAMETERS
 *  number1        :   [IN]      number to search
 *  number2        :   [IN]      number from phonebook            
 * RETURNS
 *  S32
 * RETURN VALUES
 *  SRV_PHB_NO_ERROR           :    number is same
 *  SRV_PHB_ERROR              :    number not same
 *  SRV_PHB_HALF_MARTCHED      :    the same mean with SRV_PHB_ERROR for other app, 
                                    mean half martched for lookup number search
 *****************************************************************************/
S32 srv_phb_sse_compare_number(CHAR* number1, CHAR* number2);
#endif /* defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__) */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sort_build_name_index
 * DESCRIPTION
 *  This function is just for template.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_phb_sse_build_name_index(srv_phb_async_func_type cb, void* user_data);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_init_build_lookup_table
 * DESCRIPTION
 *  This function builds the lookup table for cross-referencing during MO/MT calls.
 *  This table contains the home/mobile/fax/office number(s) of a phonebook entry.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_build_lookup_table(FuncPtr cb);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_check_store_index
 * DESCRIPTION
 *  sqlite exec
 * PARAMETERS
 *  command     [IN]    SQL command want to run
 *  callback    [IN]    callback function
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
S32 srv_phb_sse_store_index_to_sort_index(U8 storage, mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_sort_index_to_store_index
 * DESCRIPTION
 *  sqlite exec
 * PARAMETERS
 *  command     [IN]    SQL command want to run
 *  callback    [IN]    callback function
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
S32 srv_phb_sse_sort_index_to_store_index(U8 storage, U16 sort_index);





/*****************************************************************************
 * FUNCTION
 *  mmi_phb_clear_lookup_table_by_index
 * DESCRIPTION
 *  clear all number of a contact in lookup table
 * PARAMETERS
 *  store_index     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_lookup_table_remove_contact(mmi_phb_contact_id id, CHAR* number);


/*****************************************************************************
* FUNCTION
*  mmi_phb_insert_contact_to_lookup_table
* DESCRIPTION
*  add some number of a contact into lookup table
* PARAMETERS
*  store_index     [IN]        
*  number          [IN]         
*  home            [IN]         
*  office          [IN]         
*  fax             [IN]         
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_lookup_table_add_contact(mmi_phb_contact_id id, CHAR* number);


/*****************************************************************************
* FUNCTION
*  srv_phb_sse_remove_number_cache
* DESCRIPTION
*  populate a number to lookup table
* PARAMETERS
*  store_index     : [IN]        number's store_index
*  number          : [IN]        number
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_remove_number_cache(mmi_phb_contact_id id);


/*****************************************************************************
* FUNCTION
*  srv_phb_sse_add_number_cache
* DESCRIPTION
*  populate a number to lookup table
* PARAMETERS
*  store_index     : [IN]        number's store_index
*  number          : [IN]        number
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_set_number_cache(mmi_phb_contact_id id, CHAR* number, U32 order_id);


/*****************************************************************************
* FUNCTION
*  srv_phb_sse_insert_name_index
* DESCRIPTION
*  This function is just for template.
* PARAMETERS
*  store_index     [IN]            
*  a(?)            [IN/OUT]        First variable, used as returns
*  b(?)            [IN]            Second variable
* RETURNS
*  the description of return value, if any.
*****************************************************************************/
U16 srv_phb_sse_insert_name_index(mmi_phb_contact_id id, WCHAR* name);


/*****************************************************************************
* FUNCTION
*  srv_phb_sse_insert_name_index
* DESCRIPTION
*  This function is just for template.
* PARAMETERS
*  store_index     [IN]            
*  a(?)            [IN/OUT]        First variable, used as returns
*  b(?)            [IN]            Second variable
* RETURNS
*  the description of return value, if any.
*****************************************************************************/
void srv_phb_sse_populate_name_index(mmi_phb_contact_id id);


/*****************************************************************************
* FUNCTION
*  mmi_phb_op_delete_update_index
* DESCRIPTION
*  This function is just for template.
* PARAMETERS
*  store_index     [IN]        
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_delete_name_index(mmi_phb_contact_id id);


/*****************************************************************************
* FUNCTION
*  mmi_phb_op_delete_update_index
* DESCRIPTION
*  This function is just for template.
* PARAMETERS
*  store_index     [IN]        
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_delete_name_index_by_storage(U8 storage);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_sse_build_contact_list
 * DESCRIPTION
 *  sqlite exec
 * PARAMETERS
 *  command     [IN]    SQL command want to run
 *  callback    [IN]    callback function
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
S32 srv_phb_sse_build_contact_list(srv_phb_filter_struct* filter, U16* entry_array, U32 max_count);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_build_alpha_jump_table
 * DESCRIPTION
 *  build contact store_index array by filter
 * PARAMETERS
 *  filter                   : [IN]        build list filter
 *  entry_array              : [OUT]       output store_index array
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0             :          matched contact's count
 *  <0              :          refer phb error result
 *****************************************************************************/
void srv_phb_sse_build_alpha_jump_table(U16* entry_array, U16 entry_count);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_oplib_build_contact_list
 * DESCRIPTION
 *  build contact store_index array by filter
 * PARAMETERS
 *  filter                   : [IN]        build list filter
 *  entry_array              : [OUT]       output store_index array
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0             :          matched contact's count
 *  <0              :          refer phb error result
 *****************************************************************************/
U16 srv_phb_sse_get_alpha_index(U16 input_char);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_dm_check_store_index
 * DESCRIPTION
 *  sqlite exec
 * PARAMETERS
 *  command     [IN]    SQL command want to run
 *  callback    [IN]    callback function
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
S32 srv_phb_sse_search_num(U16* num_wcs, U32* number_index);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_dm_check_store_index
 * DESCRIPTION
 *  sqlite exec
 * PARAMETERS
 *  command     [IN]    SQL command want to run
 *  callback    [IN]    callback function
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
S32 srv_phb_sse_search_name(U16* name_wcs);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_convert_number_to_int
 * DESCRIPTION
 *  Converts the last n characters of a phone number to digits
 * PARAMETERS
 *  ascii_number        :   [IN]    Input ascii number
 * RETURNS
 *  interger of input number
 *****************************************************************************/
U32 srv_phb_sse_convert_number_to_int(CHAR *ascii_number);


/*****************************************************************************
* FUNCTION
*  srv_phb_check_storage_condition
* DESCRIPTION
*  check phonebook storage status by condition
* PARAMETERS
*  storage             [IN]
*  check_type          [IN]
*  need_popup          [IN]
* RETURNS
*  test result
*****************************************************************************/
S32 srv_phb_check_storage_condition(U8 storage, srv_phb_check_storage_type_enum check_type);


/*****************************************************************************
* FUNCTION
*  srv_phb_check_stoage_accessible
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  S32
*****************************************************************************/
S32 srv_phb_check_stoage_accessible(U8 storage);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_update_l4_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_update_l4_status_req(void);



/****************************************************/
/*                                                  */
/*              dmgr srv                            */
/*                                                  */
/****************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_res_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *  video_id        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_datamgr_get_res_path(U32 fied_mask, U16 index, U16 from_file, U16* path);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_video_update_by_index_for_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *          
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_clear_res_path(U32 field_mask, U16 id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_update_res_path
 * DESCRIPTION
 *  
 * PARAMETERS
 *          
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_datamgr_update_res_path(U32 field_mask, U16 original_id, MMI_BOOL original_type, U16* new_id, MMI_BOOL new_type, U16* res_path);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_used_contacts
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_datamgr_used_contacts(U8 storage);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_total_contacts
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_datamgr_total_contacts(U8 storage);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_check_store_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_datamgr_check_store_index(U16 store_index, U32 field_type);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_datamgr_get_field_mask(U16 store_index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_name
 * DESCRIPTION
 *  sqlite exec
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_get_name(U16 index, U16* name, S32 out_len);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_num_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_datamgr_get_num_count(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_email_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_datamgr_get_email_count(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
CHAR* srv_phb_datamgr_get_email(mmi_phb_contact_id id, U8 save_index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_init(void);


/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_phb_startup_callback_type
 * DESCRIPTION
 *  Definition of callback for startup procedure
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_phb_startup_callback_type) (void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_datamgr_ready_hdlr
 * DESCRIPTION
 *  This function is used to notify Startup to continue following startup procedure when DataMgr becomes ready.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_startup_datamgr_ready_hdlr(void);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_set_startup_ready
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_datamgr_set_startup_ready(phb_storage_enum storage);


/*****************************************************************************
 * FUNCTION
 *  mmi_phb_ind_startup_read
 * DESCRIPTION
 *  This function receives the read indication from L4 Phb at bootup time.
 *  Stores each indication to the global phonebook list.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_datamgr_startup_read_sim_finish(U8 sim_interface, U16 sim_total);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_startup_read_sim_begin
 * DESCRIPTION
 *  This function receives the read indication from L4 Phb at bootup time.
 *  Stores each indication to the global phonebook list.
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_datamgr_startup_read_sim_begin(srv_phb_startup_sim_init_cntx *info);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_set_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_set_field_mask(mmi_phb_contact_id id, U32 filed_flag, MMI_BOOL exist);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_commit_all_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_commit_all_field_mask(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_read_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_read_contact(mmi_phb_contact_id id, srv_phb_contact contact, srv_phb_field_filter filter);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_get_op_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
srv_phb_datamgr_op_cntx_struct* srv_phb_datamgr_get_op_cntx(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_send_set_contact_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_phb_datamgr_op_done(srv_phb_datamgr_op_status_struct* status);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_add_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_add_contact(srv_phb_datamgr_add_req_struct* req);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_update_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_update_contact(srv_phb_datamgr_update_req_struct* req);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_delete_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_delete_contact(srv_phb_datamgr_delete_req_struct* req);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_datamgr_copy_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_datamgr_copy_contact(srv_phb_datamgr_copy_req_struct* req);


/****************************************************/
/*                                                  */
/*               Phone  mgr srv                     */
/*                                                  */
/****************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_support_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_phone_support_field(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_support_field_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_phone_support_field_count(mmi_phb_contact_field_id_enum field);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_alpha_field_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_phone_alpha_field_len(mmi_phb_contact_field_id_enum field);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_phone_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_set_phone_field_mask(mmi_phb_contact_id id, U32 filed_flag, MMI_BOOL exist);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_change_phone_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_change_phone_field_mask(mmi_phb_contact_id id, U32 filed_flag, MMI_BOOL exist);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_commit_phone_fields_mask
 * DESCRIPTION
 * 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_commit_phone_fields_mask(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_commit_all_phone_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_commit_all_phone_field_mask(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_phone_field_mask(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_read_optional_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_phone_read_optional_nvram(U16 store_index, mmi_phb_optional_fields_struct* optional_fields_data);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_multi_read_optional_nvram
 * DESCRIPTION
 *  
 * PARAMETERS
 *           
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_phone_multi_read_optional_nvram(U16 store_index, mmi_phb_optional_fields_struct* optional_fields_data, U16 count);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_fname
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
WCHAR* srv_phb_get_phone_fname(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_lname
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
WCHAR* srv_phb_get_phone_lname(mmi_phb_contact_id id);



/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_num_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_get_phone_num_count(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_email_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_get_phone_email_count(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_optional_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_phb_optional_fields_struct* srv_phb_get_phone_optional_field(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_phone_optional_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_write_phone_optional_field(mmi_phb_contact_id id, mmi_phb_optional_fields_struct* optional_fields_data);


#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_group_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_get_phone_group_field(mmi_phb_contact_id id, U8* group_mask);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_phone_group_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_set_phone_group_field(mmi_phb_contact_id id, U8* group_mask, U8 type);
#endif /* __MMI_PHB_CALLER_GROUP__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_next_phone_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
U16 srv_phb_get_next_phone_contact(U16 start, U32 field_mask);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_used
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_get_phone_used(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_phone_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_get_phone_total(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_phone_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_init_phone_name(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_phone_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_read_phone_contact(mmi_phb_contact_id id, srv_phb_contact contact, srv_phb_field_filter filter);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_phone_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *       
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_write_phone_contact(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_phone_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_delete_phone_contact(srv_phb_contact_pos_struct* pos);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_copy_phone_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_copy_phone_contact(mmi_phb_contact_id src_id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_add_type
 * DESCRIPTION
 *  add a new type
 * PARAMETERS
 *  type_info          :   [IN]    type info
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0                 :           type id
 *  -1                  :           error
 *****************************************************************************/
S32 srv_phb_phone_add_type(WCHAR* type_label, mmi_phb_contact_field_id_enum field);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_type
 * DESCRIPTION
 *  delete a type
 * PARAMETERS
 *  type_id            :   [IN]    type id
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_phb_phone_delete_type(U8 type_id, mmi_phb_contact_field_id_enum field);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_get_type_list
 * DESCRIPTION
 *  get type id list ordered by type name
 * PARAMETERS
 *  type_array         :   [OUT]   type id array
 * RETURNS
 *  U8
 * RETURN VALUES
 *  count               :           type count
 ****************************************************************************/
U8 srv_phb_phone_get_type_list(U8* type_array, mmi_phb_contact_field_id_enum field);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_get_type_label
 * DESCRIPTION
 *  get a type label by id
 * PARAMETERS
 *  type_id            :   [IN]    type id
 *  field              :   [IN]    field
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
WCHAR* srv_phb_phone_get_type_label(U8 type_id, mmi_phb_contact_field_id_enum field);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_update_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
S32 srv_phb_phone_update_type(U8 type_id, WCHAR* type_label, mmi_phb_contact_field_id_enum field);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_get_type_max
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_phone_get_type_max(mmi_phb_contact_field_id_enum field);


/****************************************************/
/*                                                  */
/*               SIM  mgr srv                       */
/*                                                  */
/****************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_support_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_sim_support_field(phb_storage_enum storage);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_support_field_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_sim_support_field_count(phb_storage_enum storage, mmi_phb_contact_field_id_enum field);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_alpha_field_len
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_sim_alpha_field_len(phb_storage_enum storage, mmi_phb_contact_field_id_enum field);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_sim_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_set_sim_field_mask(mmi_phb_contact_id id, U32 filed_flag, MMI_BOOL exist);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_field_mask
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_sim_field_mask(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_used
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_get_sim_used(phb_storage_enum storage);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_total
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_phb_get_sim_total(phb_storage_enum storage);



/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_reset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_sim_reset(srv_phb_startup_sim_init_cntx *info);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_startup_read_finish
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sim_startup_read_finish(U8 sim_interface, U16 sim_total);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_sim_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
WCHAR* srv_phb_get_sim_name(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_name
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
WCHAR* srv_phb_get_sim_nick_name(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_num_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_get_sim_num_count(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
CHAR* srv_phb_get_sim_number(mmi_phb_contact_id id, U8 save_index, U8* type);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_email_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_get_sim_email_count(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_email
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
CHAR* srv_phb_get_sim_email(mmi_phb_contact_id id, U8 save_index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_read_sim_contact(mmi_phb_contact_id id, srv_phb_contact contact, srv_phb_field_filter filter);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_write_sim_contact(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *   
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_delete_sim_contact(srv_phb_contact_pos_struct* pos);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_copy_sim_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_copy_sim_contact(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_type_list
 * DESCRIPTION
 *  get type id list
 * PARAMETERS
 *  type_array         :   [OUT]   type id array
 * RETURNS
 *  U8
 * RETURN VALUES
 *  count               :           type count
 ****************************************************************************/
U8 srv_phb_sim_get_type_list(U8* type_array, phb_storage_enum storage);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_type_label
 * DESCRIPTION
 *  get a type label by id
 * PARAMETERS
 *  type_id            :   [IN]    type id
 *  field              :   [IN]    field
 * RETURNS
 *  WCHAR*
 *****************************************************************************/
WCHAR* srv_phb_sim_get_type_label(U8 type_id, phb_storage_enum storage);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_type_max
 * DESCRIPTION
 *  get type id list ordered by type name
 * PARAMETERS
 *  type_array         :   [OUT]   type id array
 * RETURNS
 *  U8
 * RETURN VALUES
 *  count               :           type count
 ****************************************************************************/
U8 srv_phb_sim_get_type_max(phb_storage_enum storage);

/****************************************************/
/*                                                  */
/*               T card service                */
/*                                                  */
/****************************************************/
#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_tcard_used_count
 * DESCRIPTION
 *  get T card used count
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_phb_get_tcard_used_count(void);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_tcard_total_count
 * DESCRIPTION
 *  get T card total support count
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_phb_get_tcard_total_count(void);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_tcard_field_mask
 * DESCRIPTION
 *  get T card contact field mask
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_phb_get_tcard_field_mask(mmi_phb_contact_id id);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_first_name
 * DESCRIPTION
 *  get T card contact first name
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* srv_phb_get_tcard_fname(mmi_phb_contact_id id);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_last_name
 * DESCRIPTION
 *  get T card contact last name
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* srv_phb_get_tcard_lname(mmi_phb_contact_id id);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_tcard_number
 * DESCRIPTION
 *  get T card contact number
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
CHAR* srv_phb_get_tcard_number(mmi_phb_contact_id id, U32 num_index, U16 *sub_id, U8 *type, U8 *prefer_sim);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_tcard_num_count
 * DESCRIPTION
 *  get T card contact number count
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_phb_get_tcard_num_count(mmi_phb_contact_id id);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_tcard_email
 * DESCRIPTION
 *  get T card contact email
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
CHAR* srv_phb_get_tcard_email(mmi_phb_contact_id id, U32 email_index, U16 *sub_id, U8 *type);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_image
 * DESCRIPTION
 *  get T card contact image
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_get_tcard_image(mmi_phb_contact_id id, U16 *image_id, U16 *image_path, U16 *res_type);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_ringtone
 * DESCRIPTION
 * get T card contact ringtone
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_get_tcard_ringtone(mmi_phb_contact_id id, U16 *ringtone_id, U16 *ringtone_path, U16 *res_type);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_video
 * DESCRIPTION
 *  get T card contact video
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_get_tcard_video(mmi_phb_contact_id id, U16 *video_id, U16 *video_path, U16 *res_type);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_company
 * DESCRIPTION
 *  get T card contact company
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* srv_phb_get_tcard_company(U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_title
 * DESCRIPTION
 *  get T card contact title
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* srv_phb_get_tcard_title(U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_url
 * DESCRIPTION
 *  get T card contact url
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
CHAR* srv_phb_get_tcard_url(U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_note
 * DESCRIPTION
 *  get T card contact note
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
WCHAR* srv_phb_get_tcard_note(U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_address
 * DESCRIPTION
 *  get T card contact address
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_phb_address_struct* srv_phb_get_tcard_address(U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_birthday
 * DESCRIPTION
 *  get T card contact birthday
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_phb_bday_struct* srv_phb_get_tcard_birthday(U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_tcard_info_field
 * DESCRIPTION
 *  get T card info field
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
mmi_phb_info_struct* srv_phb_get_tcard_info_field(mmi_phb_contact_id id);

#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_tcard_group_info
 * DESCRIPTION
 *  get a group infomation
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_get_tcard_group_info(U8 group_id, srv_phb_group_info_struct* group_info);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_tcard_group_info
 * DESCRIPTION
 *  add, update or delete group
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_set_tcard_group_info(U8 group_id, srv_phb_group_info_struct* group_info, srv_phb_group_op_type_enum op_type);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_tcard_all_group_field
 * DESCRIPTION
 *  get tcard group field
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_get_tcard_all_group_field(U32 *buffer);

#endif

/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_tcard_contact
 * DESCRIPTION
 *  get a T card contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_read_tcard_contact(mmi_phb_contact_id id, srv_phb_contact contact, srv_phb_field_filter filter);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_tcard_contact
 * DESCRIPTION
 *  update or add a contact 
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_write_tcard_contact(void);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_copy_tcard_contact
 * DESCRIPTION
 *  copy a contact to T card
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_copy_tcard_contact(void);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_tcard_contact
 * DESCRIPTION
 *  delete a T card contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_delete_tcard_contact(srv_phb_contact_pos_struct* pos);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_init
 * DESCRIPTION
 *  init T card contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_tcard_init(void);

#endif
/****************************************************/
/*                                                  */
/*               Group  mgr srv                     */
/*                                                  */
/****************************************************/

/****************************************************/
/*                                                  */
/*               filter srv                         */
/*                                                  */
/****************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_number_by_feild_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_check_number_by_feild_filter(srv_phb_field_filter filter, U8 number_type, MMI_BOOL is_default);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_field_by_feild_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_check_field_by_feild_filter(srv_phb_field_filter filter, U32 filed_type);


/****************************************************/
/*                                                  */
/*               contact filter srv                 */
/*                                                  */
/****************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_contact_filter_cache
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filter                 : [IN]      filter
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_init_contact_filter_cache(srv_phb_contact_filter filter);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_condition_check_contact
 * DESCRIPTION
 *  filter a contact by condition
 * PARAMETERS
 *  id                 : [IN]      contact's store_index
 *  filter          : [IN]      storage filter
 * RETURNS
 *  MMI_BOOL
 * RETURN VALUES
 *  MMI_TRUE                  :                    matched
 *  MMI_FALSE                 :                    not matched
 *****************************************************************************/
MMI_BOOL srv_phb_filter_contact(mmi_phb_contact_id id, srv_phb_contact_filter filter, srv_phb_query_result_struct* info);


/****************************************************/
/*                                                  */
/*               query srv                          */
/*                                                  */
/****************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_add_match_item
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_query_add_match_item(
                    srv_phb_query_handle handle,
                    mmi_phb_contact_id id,
                    mmi_phb_contact_field_id_enum align_field,
                    U8 order_id,
                    srv_phb_query_match_info_struct* match_info,
                    MMI_BOOL item_order);


#ifdef __MMI_DIALER_SEARCH__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_add_match_clg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_phb_query_add_match_clg(srv_phb_query_handle handle, SRV_CLOG_ID clog_id);
#endif


/****************************************************/
/*                                                  */
/*               sse srv                            */
/*                                                  */
/****************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_gen_alpha_index
 * DESCRIPTION
 *  gen a contact's alpha index
 * PARAMETERS
 *  id              : [IN]        contact id
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_phb_sse_gen_alpha_index(mmi_phb_contact_id id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  srv_phb_query_req_struct        : [IN]    req
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_query(srv_phb_query_req_struct* req, srv_phb_query_handle handle);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_start_async_query
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_sse_start_async_query(srv_phb_query_req_struct *req, srv_phb_query_handle handle);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_latin
 * DESCRIPTION
 *  This function is used to convert lowercase letter to uppercase letter.
 * PARAMETERS
 *  wc:                 [IN]        
 * RETURNS
 *  Wild character
 *****************************************************************************/
U16 srv_phb_convert_to_latin(U16 wc);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_wcs_n_cmp
 * DESCRIPTION
 *  This function is used to compare two wcs strings.
 * PARAMETERS
 *  string1:            [IN]        First string
 *  string2:            [IN]        Second string
 * RETURNS
 *  >0:                 First is greater than second
 *  =0:                 First is identical to second
 *  <0:                 First is less than second
 *****************************************************************************/
S32 srv_phb_wcs_n_cmp(const WCHAR* string1, const WCHAR* string2, S32 count);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_acs_wcs_n_cmp
 * DESCRIPTION
 *  This function is used to compare two ucs2 strings.
 * PARAMETERS
 *  string1:            [IN]        First string
 *  string2:            [IN]        Second string
 * RETURNS
 *  >0:                 First is greater than second
 *  =0:                 First is identical to second
 *  <0:                 First is less than second
 *****************************************************************************/
S32 srv_phb_acs_wcs_n_cmp(const CHAR* string1, const WCHAR* string2, U16 count);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_chinese_char
 * DESCRIPTION
 *  This function is check a character is chinese
 * PARAMETERS
 *  char:              [IN]        First character
 * RETURNS
 *  MMI_TRUE:                  chinese
 *  MMI_FALSE:                 not chinese
 *****************************************************************************/
MMI_BOOL srv_phb_check_chinese_char(WCHAR code);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_is_chinese_string
 * DESCRIPTION
 *  This function check a string is chinese
 * PARAMETERS
 *  string:              [IN]        input string
 * RETURNS
 *  MMI_TRUE:                 is chinese
 *  MMI_FALSE:                not chinese
 *****************************************************************************/
MMI_BOOL srv_phb_is_chinese_string(WCHAR* string);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_punctuation_char
 * DESCRIPTION
 *  This function is check a character is unicode punctuation
 * PARAMETERS
 *  char:              [IN]        character
 * RETURNS
 *  MMI_TRUE:                  punctuation
 *  MMI_FALSE:                 not punctuation
 *****************************************************************************/
MMI_BOOL srv_phb_check_punctuation_char(WCHAR code);



/*****************************************************************************
 * FUNCTION
 *  srv_phb_free_link
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_free_link(srv_phb_node_struct* head, srv_phb_node_struct* tail);


#ifdef __MMI_VCARD__

/*****************************************************************************
 * FUNCTION
 *  srv_phb_vcard_is_valid_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  contact       [IN]        
 *  vcard_object    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_phb_vcard_is_valid_contact(vcard_object_struct *vcard_object);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_number_type_to_vcard
 * DESCRIPTION
 *  convert phone book number type to vcard number type
 * PARAMETERS
 *  type       :  [IN] mmi_phb_num_type_enum
 * RETURNS
 *  vcard_tel_type_enum
 *****************************************************************************/
vcard_tel_type_enum srv_phb_convert_number_type_to_vcard(mmi_phb_num_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_number_type_from_vcard
 * DESCRIPTION
 *  convert from vcard telephone type to phone book number type
 * PARAMETERS
 *  type       [IN]           
 * RETURNS
 *  vcard_tel_type_enum
 *****************************************************************************/
mmi_phb_num_type_enum srv_phb_convert_number_type_from_vcard(vcard_tel_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_email_type_to_vcard
 * DESCRIPTION
 *  convert phone book email type to vcard email type
 * PARAMETERS
 *  type       [IN]           
 * RETURNS
 *  vcard_email_type_enum
 *****************************************************************************/
vcard_email_type_enum srv_phb_convert_email_type_to_vcard(mmi_phb_email_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_email_type_from_vcard
 * DESCRIPTION
 *  convert vcard email type to phone book email type
 * PARAMETERS
 *  type       [IN]           
 * RETURNS
 *  mmi_phb_email_type_enum
 *****************************************************************************/
mmi_phb_email_type_enum srv_phb_convert_email_type_from_vcard(vcard_email_type_enum type);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_image_type_to_vcard
 * DESCRIPTION
 *  convert file image type to vcard photo type
 * PARAMETERS
 *  type       [IN]           
 * RETURNS
 *  vcard_photo_type_enum
 *****************************************************************************/
vcard_photo_type_enum srv_phb_convert_image_type_to_vcard(mmi_fmgr_filetype_enum type);

#endif /* __MMI_VCARD__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_init
 * DESCRIPTION
 *  This function is used to register L4C STARTUP BEGIN & END indication.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_startup_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_clear_ready_flag
 * DESCRIPTION
 *  set ready status as false
 * PARAMETERS
 *  void      
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_startup_clear_ready_flag(void);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_read_entry_by_index_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *         
 * RETURNS
 *  U16
 *****************************************************************************/
void srv_phb_startup_read_entry_by_index_rsp(void *info, int mod_src);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_set_initing_entry_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]
 *  entry_type          [IN]
 * RETURNS
 *  U16
 *****************************************************************************/
void srv_phb_startup_set_initing_entry_type(U8 sim_interface, phb_type_enum entry_type);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_startup_get_initing_entry_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 * RETURNS
 *  phb_type_enum
 *****************************************************************************/
phb_type_enum srv_phb_startup_get_initing_entry_type(U8 sim_interface);


#define IN_PHBATSRV_C

/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_init
 * DESCRIPTION
 *  This function is used to register L4C AT indication.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_at_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_mem_init
 * DESCRIPTION
 *  phonebook memory management init function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_mem_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_init
 * DESCRIPTION
 *  This function is used to register L4C AT indication.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_init(void);


/*****************************************************************************
* FUNCTION
*  srv_phb_setting_init
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
void srv_phb_setting_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_query_async_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_query_async_init(void);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_build_l4phb_entry
 * DESCRIPTION
 *  This function is used to build L4PHB entry by name and number.
 * PARAMETERS
 *  phb_entry:          [OUT]       L4PHB entry to store the result
 *  name:               [IN]        First name
 *  l_name:             [IN]        Last name
 *  number:             [IN]        Mobile number
 * RETURNS
 *  void
 *****************************************************************************/
 void srv_phb_build_l4phb_entry(l4c_phb_entry_struct *phb_entry, U16 *name, U16 *l_name, U16 *number);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_parse_l4phb_entry
 * DESCRIPTION
 *  This function is used to parse L4PHB entry to name and number.
 * PARAMETERS
 *  phb_entry:          [IN]        L4PHB entry
 *  name:               [OUT]       First name
 *  l_name:             [OUT]       Last name
 *  number:             [OUT]       Mobile number
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_parse_l4phb_entry(l4c_phb_entry_struct *phb_entry, U16 *name, U16 *l_name, U16 *number);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_get_sim_imsi
 * DESCRIPTION
 *  get sim imsi by sim id
 * PARAMETERS
 *  sim_id      : [IN] sim index
 *  imsi         : [OUT] imsi
 *  len           : [IN] imsi length SRV_MAX_IMSI_LEN
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_phone_get_sim_imsi(U8 sim_id, CHAR *imsi, U16 len);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_phone_set_sim_imsi
 * DESCRIPTION
 *  get sim imsi by sim id
 * PARAMETERS
 *  sim_id      : [IN] sim index
 *  imsi         : [IN] imsi
 *  len           : [IN] imsi length SRV_MAX_IMSI_LEN
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_phone_set_sim_imsi(U8 sim_id, CHAR *imsi, U16 len);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  SQLITE error code
 *****************************************************************************/
U8 srv_phb_get_sim_id(phb_storage_enum storage);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_anr_rsp
 * DESCRIPTION
 *  request message to L4 for delete one entry
 * PARAMETERS
 *  storage      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_read_anr_rsp(void *info, int mod_src);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_read_fdn_to_ram
 * DESCRIPTION
 *  This function is used to read FDN list (both SIM1 and SIM2) to ram for call querying name.
 *  This permanent list will be different from Phonebook settings->Extra#->FDN list after adding/editing/deleting some FDN entry.
 *  But when FDN entry changed, it will automatically read all FDN list again.
 *  So just copy it to keep them synchronized.
 * PARAMETERS
 *  init_cb:            [IN]        startup callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_read_fdn_to_ram(sim_interface_enum sim_id, srv_phb_startup_callback_type init_cb, void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_read_fdn_to_ram_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_read_fdn_to_ram_rsp(void *info, int mod_id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_set_read_false
 * DESCRIPTION
 *  This function will set the read value of the FDN for each sim to MMI_FALSE.
 * PARAMETERS
 *  init_cb:            [IN]        startup callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_set_read_false(void);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_get_dial_mode
 * DESCRIPTION
 *  This function is used to read dial mode during phonebook startup.
 * PARAMETERS
 *  init_cb:            [IN]        startup callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_read_dial_mode(sim_interface_enum sim_id, srv_phb_startup_callback_type init_cb, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sse_get_fdn_by_sim_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface        : [IN]    sim id
 *  index                   : [OUT]  index array
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sse_get_fdn_by_sim_id(U8 sim_interface, U16 *index);

/*****************************************************************************
* FUNCTION
*  srv_phb_sse_clear_fdn_name_index
* DESCRIPTION
*  clear fdn name_index array
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_phb_sse_clear_fdn_name_index(sim_interface_enum sim_id);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_xmgnt_clear_dial_mode_flag
 * DESCRIPTION
 *  clear dial mode flag
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_xmgnt_clear_dial_mode_flag(void);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_compare_fdn_number
 * DESCRIPTION
 *  This function is used to compare dail number with FDN numbers.
 * PARAMETERS
 *  approve_number:            [IN]        the number for approve
 *  fdn_number:                  [IN]        the fdn list number
 * RETURN VALUES
 *  MMI_TRUE:           Equal
 *  MMI_FALSE:          Not equal
 *****************************************************************************/
MMI_BOOL srv_phb_compare_fdn_number(CHAR *approve_number, CHAR *fdn_number);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_get_gas
 * DESCRIPTION
 *  This function is used to get group name of sim.
 * PARAMETERS
 *  sim_id:                         [IN]        the sim index of gas to get
 *  store_index:                  [IN]        index of gas in sim_id
 *  group_name:                 [OUT]     gas alpha
 * RETURN VALUES
 *  group_name
 *****************************************************************************/
U16 *srv_phb_sim_get_gas(U8 sim_id, U16 store_index, U16 *group_name);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_group_insert_group_index
 * DESCRIPTION
 *  This function is used to insert group index into sort cache.
 * PARAMETERS
 *  group_id:                       [IN]        the sim index of gas to get
 *  group_name:                  [IN]        group name
 * RETURN VALUES
 *  group index
 *****************************************************************************/
U32 srv_phb_group_insert_group_index(U8 group_id, U16* group_name);

/*****************************************************************************
 * FUNCTION
*  srv_phb_group_delete_group_index
 * DESCRIPTION
*  Insert a group to group sort array
 * PARAMETERS
*  group_id                : [IN]            group store index :group_id < MMI_PHB_GROUP_COUNT -->phone
                                                                   group_id >= MMI_PHB_GROUP_COUNT-->USIM
 * RETURNS
*  insert postion
 *****************************************************************************/
U32 srv_phb_group_delete_group_index(U8 group_id);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sim_set_gas
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sim_set_gas(phb_storage_enum storage, U16 record_id, WCHAR* gas_alpha);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_phone_group_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_group_set_group_done(S32 result, U8 group_id, WCHAR* group_name);

/*****************************************************************************
* FUNCTION
*  srv_phb_group_init
* DESCRIPTION
*  phone group init
* PARAMETERS
* NULL
* RETURNS
*  insert postion
*****************************************************************************/
void srv_phb_group_init(void);

#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
void srv_phb_java_handler_init(void);
#endif

#ifdef __VCARD_CLOUD_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_cloud_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_cloud_op_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void srv_phb_cloud_op_done(void);
#endif

#endif /* PHBSRV_H */ 
