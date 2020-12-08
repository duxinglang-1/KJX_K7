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
 *  PhbTcardSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  for Tcard contact
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "MMI_features.h"
#ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
/***************************************************************************** 
 * Include 
 *****************************************************************************/
#include "FileMgrSrvGProt.h"
#include "PhbSrvGprot.h"
#include "TcardSrvGprot.h"
#include "PhbTcardSrv.h"
#include "PhbSrv.h"
#include "mmi_rp_srv_phb_def.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGprot.h"
#endif

/***************************************************************************** 
 * local defination 
 *****************************************************************************/
#define MMI_PHB_TCARD_CONTACT_DATA_FIELD (MMI_PHB_CONTACT_FIELD_NAME | MMI_PHB_CONTACT_FIELD_NUMBER | MMI_PHB_CONTACT_FIELD_EMAIL | MMI_PHB_CONTACT_FIELD_RES)
#define MMI_PHB_TCARD_CONTACT_INFO_FIELD (MMI_PHB_CONTACT_FIELD_GROUP | MMI_PHB_CONTACT_FIELD_COMPANY | MMI_PHB_CONTACT_FIELD_NOTE |MMI_PHB_CONTACT_FIELD_TITLE | MMI_PHB_CONTACT_FIELD_URL | MMI_PHB_CONTACT_FIELD_BDAY | MMI_PHB_CONTACT_FIELD_ADDRESS)

typedef enum
{
    SRV_PHB_TCARD_OP_TYPE_READ,
    SRV_PHB_TCARD_OP_TYPE_WRITE
} srv_phb_tcard_op_type_enum;

typedef struct
{
    mmi_phb_name_struct name[MMI_PHB_TCARD_ENTRIES];
    mmi_phb_asc_num_struct number[MMI_PHB_TCARD_ENTRIES][MMI_PHB_NUMBER_FIELD_COUNT];
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
    mmi_phb_email_struct email[MMI_PHB_TCARD_ENTRIES][MMI_PHB_EMAIL_FIELD_COUNT];
    #endif
    U32 field_mask[MMI_PHB_TCARD_ENTRIES];
    U16 used_count;
    U16 total_count;
    MMI_BOOL is_ready;
} srv_phb_tcard_cache_struct;

typedef struct
{
    mmi_phb_info_struct * info_field;
} srv_phb_tcard_info_cache_struct;

typedef struct
{
    srv_phb_tcard_data_struct *data;
    srv_phb_tcard_info_struct *info;
    S32 result;
    U16 record_id;
    U16 count;
} srv_phb_tcard_op_cntx;

#ifdef __MMI_PHB_CALLER_GROUP__
typedef struct
{
    U16 group_name[MMI_PHB_GROUP_NAME_LENGTH + 1];                   /*group name*/
    U16 res_type;                                                    /*res type*/
    U16 image_id;
    U16 image_path[SRV_FMGR_PATH_MAX_LEN + 1];                       /*image file path*/
    U16 ringtone_id;
    U16 ringtone_path[SRV_FMGR_PATH_MAX_LEN + 1];                    /*ringtone file path*/
    #ifdef __MMI_PHB_CALLER_VIDEO__
    U16 video_id;
    U16 video_path[SRV_FMGR_PATH_MAX_LEN + 1];                       /*video path*/
    #endif
} srv_phb_tcard_group_info_struct;

typedef struct
{
    U32 group_mask[MMI_PHB_TCARD_ENTRIES];
    srv_phb_tcard_group_info_struct group_info[MMI_PHB_TCARD_GROUP_COUNT];
} srv_phb_tcard_group_cache_struct;

static srv_phb_tcard_group_cache_struct g_srv_phb_tcard_group_cache;
#endif

static srv_phb_tcard_cache_struct g_srv_phb_tcard_cache;
static srv_phb_tcard_info_cache_struct g_srv_phb_tcard_info_cache[MMI_PHB_TCARD_ENTRIES];

/***************************************************************************** 
 * local function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_read_record
 * DESCRIPTION
 *  read T card record
 * PARAMETERS
 *        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_read_record(U16 field_id, U16 record_id, U16 count, CHAR* buffer, SrvTcardCallbackFunc cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_op_struct op_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    op_cntx.app_index = SRV_TCARD_APP_INDEX_PHB;
    op_cntx.file_index = (srv_tcard_file_index_enum)field_id;
    op_cntx.start_record_id = record_id;
    op_cntx.record_num = count;
    srv_tcard_read_record(&op_cntx, buffer, cb, user_data);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_write_record
 * DESCRIPTION
 *  write T card record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_tcard_write_record(U16 field_id, U16 record_id, U16 count, CHAR* buffer, SrvTcardCallbackFunc cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_op_struct op_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    op_cntx.app_index = SRV_TCARD_APP_INDEX_PHB;
    op_cntx.file_index = (srv_tcard_file_index_enum)field_id;
    op_cntx.start_record_id = record_id;
    op_cntx.record_num = count;
    srv_tcard_write_record(&op_cntx, buffer, cb, user_data);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_free_index
 * DESCRIPTION
 *  get a free index to save a new contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 srv_phb_tcard_get_free_index(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_srv_phb_tcard_cache.used_count < g_srv_phb_tcard_cache.total_count)
    {
        for (i = 0; i < g_srv_phb_tcard_cache.total_count; i++)
        {
            if (!g_srv_phb_tcard_cache.field_mask[i])
            {
                return i;
            }
        }
    }
    return SRV_PHB_INVALID_INDEX;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_free_sub_id
 * DESCRIPTION
 *  get a new sub id to save number
 * PARAMETERS
 *  void        
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 srv_phb_tcard_get_free_sub_id(srv_phb_tcard_data_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 mask = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i = 0; i < MMI_PHB_TCARD_NUMBER_COUNT; i ++)
    {
        if (data->num[i].number[0])
        {
            mask |= 1 << i;
        }
    }

    for (i = 0; i < MMI_PHB_TCARD_NUMBER_COUNT; i ++)
    {
        if (!(mask & (1 << i)))
        {
            return i;
        }
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_save_index
 * DESCRIPTION
 *  convert contact id to save index
 * PARAMETERS
 *  void        
 * RETURNS
 *  U16
 *****************************************************************************/
static U16 srv_phb_tcard_get_save_index(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id >= MMI_PHB_BASIC_ENTRIES && id < MMI_PHB_ENTRIES)
    {
        return (id - MMI_PHB_BASIC_ENTRIES);
    }
    return SRV_PHB_INVALID_INDEX;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_malloc_info_cache
 * DESCRIPTION
 *  malloc info cache buffer
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_malloc_info_cache(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (g_srv_phb_tcard_info_cache[index].info_field == NULL)
    {
         g_srv_phb_tcard_info_cache[index].info_field = 
            srv_phb_mem_malloc(sizeof(mmi_phb_info_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(g_srv_phb_tcard_info_cache[index].info_field, 0x00, sizeof(mmi_phb_info_struct));
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_malloc_info_cache
 * DESCRIPTION
 *  mall info cache buffer
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_write_res_path(srv_phb_tcard_res_path_struct *res, U32 record_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_tcard_op_struct op_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    op_cntx.app_index = SRV_TCARD_APP_INDEX_PHB;
    op_cntx.file_index = SRV_PHB_TCARD_RES_PATH_FIELD;
    op_cntx.start_record_id = record_id;
    op_cntx.record_num = 1;
    srv_tcard_sync_write_record(&op_cntx, (CHAR *)res);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_read_res_path
 * DESCRIPTION
 *  read res path field
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_read_res_path(U32 record_id, srv_phb_tcard_res_path_struct *res)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_op_struct op_cntx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    op_cntx.app_index = SRV_TCARD_APP_INDEX_PHB;
    op_cntx.file_index = SRV_PHB_TCARD_RES_PATH_FIELD;
    op_cntx.start_record_id = record_id;
    op_cntx.record_num = 1;
    srv_tcard_sync_read_record(&op_cntx, (CHAR *)res);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_name
 * DESCRIPTION
 *  set name
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_phb_tcard_set_name(U16 index, WCHAR *name, WCHAR *l_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL modified = MMI_FALSE;
    mmi_phb_name_struct* entry = &g_srv_phb_tcard_cache.name[index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name != NULL && name[0])
    {
        if (mmi_wcscmp(entry->name, name) != 0)
        {
            mmi_wcsncpy(entry->name, name, MMI_PHB_NAME_FIELD_LENGTH);
            modified = MMI_TRUE;
        }
    }
    else
    {
        if (entry->name[0])
        {
            modified = MMI_TRUE;
        }
        entry->name[0] = 0;
    }
    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
    if (l_name != NULL && l_name[0])
    {
        if (mmi_wcscmp(entry->l_name, l_name) != 0)
        {
            mmi_wcsncpy(entry->l_name, l_name, MMI_PHB_NAME_FIELD_LENGTH);
            modified = MMI_TRUE;
        }
    }
    else
    {
        if (entry->l_name[0])
        {
            modified = MMI_TRUE;
        }
        entry->l_name[0] = 0;
    }
    #endif
    return modified;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_clear_number
 * DESCRIPTION
 *  clear number field
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_clear_number(U32 index)
{
    memset(g_srv_phb_tcard_cache.number[index], 0x00, sizeof(mmi_phb_asc_num_struct) * MMI_PHB_NUMBER_FIELD_COUNT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_number
 * DESCRIPTION
 *  set number
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_number(U32 index, U32 num_index, CHAR *number, U16 sub_id, U8 type, U8 last_used_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_asc_num_struct * num = &g_srv_phb_tcard_cache.number[index][num_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number != NULL && number[0])
    {
        strncpy((CHAR *)num->number, number, MMI_PHB_NUMBER_LENGTH);
        num->type = (mmi_phb_num_type_enum)type;
        num->sub_id = sub_id;
        num->last_used_sim = last_used_sim;
    }
    else
    {
        num->number[0] = 0;
        num->sub_id = 0;
        num->type = MMI_PHB_NUM_TYPE_NONE;
        num->last_used_sim = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_clear_email
 * DESCRIPTION
 *  clear number field
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_clear_email(U32 index)
{
    memset(g_srv_phb_tcard_cache.email[index], 0x00, sizeof(mmi_phb_email_struct) * MMI_PHB_EMAIL_FIELD_COUNT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_email
 * DESCRIPTION
 *  set email
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_email(U32 index, U32 email_index, CHAR *email, U16 sub_id, U8 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_email_struct* e_mail = &g_srv_phb_tcard_cache.email[index][email_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (email != NULL && email[0])
    {
        strncpy((CHAR *)(e_mail->email), email, MMI_PHB_EMAIL_LENGTH);
        e_mail->type = type;
        e_mail->sub_id = sub_id;
    }
    else
    {
        e_mail->email[0] = 0;
        e_mail->sub_id = 0;
        e_mail->type = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_image
 * DESCRIPTION
 *  set image
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_image(U32 index, U16 image_id, U16 res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_tcard_info_cache[index].info_field->image_id = image_id;
    g_srv_phb_tcard_info_cache[index].info_field->res_type = res_type;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_ringtone
 * DESCRIPTION
 *  set ringtone
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_ringtone(U32 index, U16 ringtone_id, U16 res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*if (g_srv_phb_tcard_info_cache[index].info_field == NULL)
    {
        srv_phb_tcard_malloc_info_cache(index);
    }*/
    g_srv_phb_tcard_info_cache[index].info_field->res_type = res_type;
    g_srv_phb_tcard_info_cache[index].info_field->ringtone_id = ringtone_id;
}

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
static WCHAR* srv_phb_tcard_get_first_name(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_srv_phb_tcard_cache.name[index].name;
}

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
static WCHAR* srv_phb_tcard_get_last_name(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #ifdef __MMI_PHB_LAST_NAME_FIELD__
    return g_srv_phb_tcard_cache.name[index].l_name;
    #else
    return NULL;
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_number
 * DESCRIPTION
 *  get T card contact number
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static CHAR* srv_phb_tcard_get_number(U32 index, U32 num_index, U16 *sub_id, U8 *type, U8 *last_used_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_asc_num_struct *number = &(g_srv_phb_tcard_cache.number[index][num_index]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sub_id)
    {
        *sub_id = number->sub_id;
    }
    if (type)
    {
        *type = number->type;
    }
    if (last_used_sim)
    {
        *last_used_sim = number->last_used_sim;
    }
    return (CHAR *)(number->number);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_num_count
 * DESCRIPTION
 *  get T card contact number count
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_phb_tcard_get_num_count(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 count = 0;
    mmi_phb_asc_num_struct *number = &(g_srv_phb_tcard_cache.number[index][0]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i ++)
    {
        if (number->number[0])
        {
            count ++;
        }
        number++;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_email
 * DESCRIPTION
 *  get T card contact email
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static CHAR* srv_phb_tcard_get_email(U32 index, U32 email_index, U16 *sub_id, U8 *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_email_struct *email = &(g_srv_phb_tcard_cache.email[index][email_index]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sub_id)
    {
        *sub_id = email->sub_id;
    }
    if (type)
    {
        *type = email->type;
    }
    return (CHAR *)(email->email);
}

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
static void srv_phb_tcard_get_image(U32 index, U16 *image_id, U16 *image_path, U16 *res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_info_struct *info_field = g_srv_phb_tcard_info_cache[index].info_field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *res_type = 0;

    if ((info_field->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE) && image_path)
    {
        srv_phb_tcard_res_path_struct *res = srv_phb_mem_malloc(sizeof(srv_phb_tcard_res_path_struct), SRV_PHB_MEMORY_TYPE_ADM);
        srv_phb_tcard_read_res_path(index, res);
        mmi_wcsncpy(image_path, res->image_path, SRV_FMGR_PATH_MAX_LEN);
        *res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
        srv_phb_mem_free(res);
    }
    else if ((info_field->res_type & SRV_PHB_RES_TYPE_IMAGE_ID) && image_id)
    {
        *image_id = info_field->image_id;
        *res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
    }
}

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
static void srv_phb_tcard_get_ringtone(U32 index, U16 *ringtone_id, U16 *ringtone_path, U16 *res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_info_struct *info_field = g_srv_phb_tcard_info_cache[index].info_field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *res_type = 0;

    if ((info_field->res_type & SRV_PHB_RES_TYPE_RING_FILE) && ringtone_path)
    {
        srv_phb_tcard_res_path_struct *res = srv_phb_mem_malloc(sizeof(srv_phb_tcard_res_path_struct), SRV_PHB_MEMORY_TYPE_ADM);
        srv_phb_tcard_read_res_path(index, res);
        mmi_wcsncpy(ringtone_path, res->ring_path, SRV_FMGR_PATH_MAX_LEN);
        *res_type |= SRV_PHB_RES_TYPE_AUDIO_RING_FILE;
        srv_phb_mem_free(res);
    }
    else if ((info_field->res_type & SRV_PHB_RES_TYPE_RING_ID) && ringtone_id)
    {
        *ringtone_id = info_field->ringtone_id;
        *res_type |= SRV_PHB_RES_TYPE_RING_ID;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_info_field
 * DESCRIPTION
 * get T card info field
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_phb_info_struct* srv_phb_tcard_get_info_field(U32 index)
{
    return g_srv_phb_tcard_info_cache[index].info_field;
}

#ifdef __MMI_PHB_CALLER_VIDEO__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_video
 * DESCRIPTION
 *  set video
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_video(U32 index, U16 video_id, U16 res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_tcard_info_cache[index].info_field->video_id = video_id;
    g_srv_phb_tcard_info_cache[index].info_field->res_type = res_type;
}

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
static void srv_phb_tcard_get_video(U32 index, U16 *video_id, U16 *video_path, U16 *res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_info_struct *info_field = g_srv_phb_tcard_info_cache[index].info_field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((info_field->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE) && video_path)
    {
        srv_phb_tcard_res_path_struct *res = srv_phb_mem_malloc(sizeof(srv_phb_tcard_res_path_struct), SRV_PHB_MEMORY_TYPE_ADM);
        srv_phb_tcard_read_res_path(index, res);
        mmi_wcsncpy(video_path, res->video_path, SRV_FMGR_PATH_MAX_LEN);
        *res_type |= SRV_PHB_RES_TYPE_VIDEO_FILE;
        srv_phb_mem_free(res);
    }
    else if ((info_field->res_type & SRV_PHB_RES_TYPE_VIDEO_ID) && video_id)
    {
        *video_id = info_field->video_id;
        *res_type |= SRV_PHB_RES_TYPE_VIDEO_ID;
    }
}
#endif

#ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_company
 * DESCRIPTION
 *  set company
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_company(U32 index, WCHAR *company)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *dest = g_srv_phb_tcard_info_cache[index].info_field->company;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (company != NULL && company[0])
    {
        mmi_wcsncpy(dest, company, MMI_PHB_COMPANY_LENGTH);
    }
    else
    {
        dest[0] = 0;
    }
}

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
static WCHAR* srv_phb_tcard_get_company(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_srv_phb_tcard_info_cache[index].info_field->company;
}
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */

#ifdef __MMI_PHB_INFO_FIELD__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_title
 * DESCRIPTION
 *  set title
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_title(U32 index, WCHAR *title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *dest = g_srv_phb_tcard_info_cache[index].info_field->title;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (title != NULL && title[0])
    {
        mmi_wcscpy(dest, title);
    }
    else
    {
        title[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_note
 * DESCRIPTION
 *  set note
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_note(U32 index, WCHAR *note)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *dest = g_srv_phb_tcard_info_cache[index].info_field->note;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (note != NULL && note[0])
    {
        mmi_wcscpy(dest, note);
    }
    else
    {
        note[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_url
 * DESCRIPTION
 *  set url
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_url(U32 index, CHAR *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *dest = g_srv_phb_tcard_info_cache[index].info_field->url;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (url != NULL && url[0])
    {
        strcpy((char *)dest, url);
    }
    else
    {
        url[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_address
 * DESCRIPTION
 *  set address
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_address(U32 index, mmi_phb_address_struct *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_address_struct *dest = &(g_srv_phb_tcard_info_cache[index].info_field->address);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (address != NULL)
    {
        mmi_wcsncpy(
            (WCHAR*)(dest->pobox),
            (WCHAR*)(address->pobox),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(dest->extension),
            (WCHAR*)(address->extension),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(dest->street),
            (WCHAR*)(address->street),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(dest->city),
            (WCHAR*)(address->city),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(dest->state),
            (WCHAR*)(address->state),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(dest->postalcode),
            (WCHAR*)(address->postalcode),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(dest->country),
            (WCHAR*)(address->country),
            MMI_PHB_ADDRESS_LENGTH);
    }
    else
    {
        dest->pobox[0] = 0;
        dest->extension[0] = 0;
        dest->street[0] = 0;
        dest->city[0] = 0;
        dest->state[0] = 0;
        dest->postalcode[0] = 0;
        dest->country[0] = 0;
    }
}

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
static WCHAR* srv_phb_tcard_get_title(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_srv_phb_tcard_info_cache[index].info_field->title;
}

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
static CHAR* srv_phb_tcard_get_url(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return (CHAR *)(g_srv_phb_tcard_info_cache[index].info_field->url);
}

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
static WCHAR* srv_phb_tcard_get_note(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_srv_phb_tcard_info_cache[index].info_field->note;
}

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
static mmi_phb_address_struct* srv_phb_tcard_get_address(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return &g_srv_phb_tcard_info_cache[index].info_field->address;
}
#endif

#ifdef __MMI_PHB_BIRTHDAY_FIELD__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_birthday
 * DESCRIPTION
 *  set birthday
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_birthday(U32 index, mmi_phb_bday_struct *birthday)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_bday_struct *dest = &(g_srv_phb_tcard_info_cache[index].info_field->bday);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (birthday != NULL)
    {
        dest->b_year = birthday->b_year;
        dest->b_month = birthday->b_month;
        dest->b_day = birthday->b_day;
    }
    else
    {
        dest->b_year = 0;
        dest->b_month = 0;
        dest->b_day = 0;
    }
}

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
static mmi_phb_bday_struct* srv_phb_tcard_get_birthday(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return &g_srv_phb_tcard_info_cache[index].info_field->bday;
}
#endif

#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_group_info
 * DESCRIPTION
 *  set tcard group field
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_group_info(U32 index, srv_phb_tcard_group_info_struct *group_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_tcard_group_info_struct *dest = &(g_srv_phb_tcard_group_cache.group_info[index]);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dest, 0x00, sizeof(srv_phb_tcard_group_info_struct));
    if (group_info)
    {
        mmi_wcsncpy(dest->group_name, group_info->group_name, MMI_PHB_GROUP_NAME_LENGTH);
        if (group_info->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
        {
            mmi_wcsncpy(dest->image_path, group_info->image_path, SRV_FMGR_PATH_MAX_LEN);
            dest->res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
        }
        else
        {
            dest->image_id = group_info->image_id;
            dest->res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
        }
        if (group_info->res_type & SRV_PHB_RES_TYPE_RING_FILE)
        {
            mmi_wcsncpy(dest->ringtone_path, group_info->ringtone_path, SRV_FMGR_PATH_MAX_LEN);
            dest->res_type |= SRV_PHB_RES_TYPE_RING_FILE;
        }
        else
        {
            dest->ringtone_id = group_info->ringtone_id;
            dest->res_type |= SRV_PHB_RES_TYPE_RING_ID;
        }
        #ifdef __MMI_PHB_CALLER_VIDEO__
        if (group_info->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE)
        {
            mmi_wcsncpy(dest->video_path, group_info->video_path, SRV_FMGR_PATH_MAX_LEN);
            dest->res_type |= SRV_PHB_RES_TYPE_VIDEO_FILE;
        }
        else
        {
            dest->video_id = group_info->video_id;
            dest->res_type |= SRV_PHB_RES_TYPE_VIDEO_ID;
        }
        #endif
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_read_all_group_info
 * DESCRIPTION
 *  init tcard group field
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_read_all_group_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U32 i;
    U8 group_id;
    srv_tcard_op_struct op_cntx;
    srv_phb_tcard_group_struct *group_info = srv_phb_mem_malloc(sizeof(srv_phb_tcard_group_struct), SRV_PHB_MEMORY_TYPE_ADM);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    op_cntx.app_index = SRV_TCARD_APP_INDEX_PHB;
    op_cntx.file_index = SRV_PHB_TCARD_GROUP_INFO_FIELD;
    op_cntx.record_num = 1;

    for (i = 0; i < MMI_PHB_TCARD_GROUP_COUNT; i ++)
    {
        op_cntx.start_record_id = i;
        srv_tcard_sync_read_record(&op_cntx, (CHAR *)group_info);
        srv_phb_tcard_set_group_info(i, (srv_phb_tcard_group_info_struct *)group_info);
        group_id = i + MMI_PHB_GROUP_COUNT + MMI_PHB_GROUP_USIM_COUNT;
        srv_phb_group_delete_group_index(group_id);
        srv_phb_group_insert_group_index(group_id, group_info->group_name);
    }
    srv_phb_mem_free(group_info);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_write_group_info
 * DESCRIPTION
 *  write tcard group field
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_write_group_info(U32 record_id, srv_phb_tcard_group_struct *group_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tcard_op_struct op_cntx;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    op_cntx.app_index = SRV_TCARD_APP_INDEX_PHB;
    op_cntx.file_index = SRV_PHB_TCARD_GROUP_INFO_FIELD;
    op_cntx.start_record_id = record_id;
    op_cntx.record_num = 1;
    srv_tcard_sync_write_record(&op_cntx, (CHAR *)group_info);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_group_info
 * DESCRIPTION
 *  get tcard group info
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static srv_phb_tcard_group_info_struct * srv_phb_tcard_get_group_info(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &(g_srv_phb_tcard_group_cache.group_info[index]);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_group_mask
 * DESCRIPTION
 *  set group mask for a contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_group_mask(U32 index, U32 group_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_tcard_group_cache.group_mask[index] = group_mask;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_group_mask
 * DESCRIPTION
 *  set group mask for a contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static U32 srv_phb_tcard_get_group_mask(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_tcard_group_cache.group_mask[index];
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_dup_group_info
 * DESCRIPTION
 *  convert from srv_phb_group_info_struct to srv_phb_tcard_group_struct
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_tcard_dup_group_info(srv_phb_tcard_group_struct *dest, srv_phb_group_info_struct *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy(dest->group_name, src->group_name);
    if (src->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
    {
        mmi_wcsncpy(dest->image_path, src->image_path, SRV_FMGR_PATH_MAX_LEN);
    }
    else
    {
        dest->image_id = src->image_id;
    }
    if (src->res_type & SRV_PHB_RES_TYPE_RING_FILE)
    {
        mmi_wcsncpy(dest->ringtone_path, src->ringtone_path, SRV_FMGR_PATH_MAX_LEN);
    }
    else
    {
        dest->ringtone_id = src->ringtone_id;
    }
    #ifdef __MMI_PHB_CALLER_VIDEO__
    if (src->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE)
    {
        mmi_wcsncpy(dest->video_path, src->video_path, SRV_FMGR_PATH_MAX_LEN);
    }
    else
    {
        dest->video_id = src->video_id;
    }
    #endif
    dest->res_type = src->res_type;
    
}

#endif

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_field_mask
 * DESCRIPTION
 *  update field mask
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_field_mask(U32 index, U32 field_mask, MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 *mask = &g_srv_phb_tcard_cache.field_mask[index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (is_set == MMI_TRUE)
    {
        *mask |= field_mask;
    }
    else
    {
        *mask &= ~field_mask;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_total_count
 * DESCRIPTION
 *  set T card total cound
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_total_count(U16 total)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_srv_phb_tcard_cache.total_count = total;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_increase_used_count
 * DESCRIPTION
 *  increase T card used count when add a new contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_increase_used_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_srv_phb_tcard_cache.used_count ++;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_decrease_used_count
 * DESCRIPTION
 *  decrease used count when delete a contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_decrease_used_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_srv_phb_tcard_cache.used_count --;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_clear_used_count
 * DESCRIPTION
 *  clear all contacts when T card plug out
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_clear_used_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_srv_phb_tcard_cache.used_count = 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_set_ready
 * DESCRIPTION
 *  set tcard ready
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_set_ready(MMI_BOOL is_ready)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_tcard_ready_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_tcard_cache.is_ready = is_ready;
    
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHB_TCARD_READY);
    evt.is_ready = is_ready;
    MMI_FRM_CB_EMIT_EVENT(&evt);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_get_field_mask
 * DESCRIPTION
 *  get T card contact field mask
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static U32 srv_phb_tcard_get_field_mask(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_srv_phb_tcard_cache.field_mask[index];
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_is_field_mask_update
 * DESCRIPTION
 *  check field mask update or not
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_phb_tcard_is_field_mask_update(U32 index, U32 field_mask)
{
    return (MMI_BOOL)(g_srv_phb_tcard_cache.field_mask[index] != field_mask);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_name
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_name(srv_phb_tcard_data_struct *buffer, WCHAR *name, WCHAR *l_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (name != NULL && name[0])
    {
        mmi_wcsncpy(buffer->name, name, MMI_PHB_NAME_FIELD_LENGTH);
    }
    else
    {
        buffer->name[0] = 0;
    }
    if (l_name != NULL && l_name[0])
    {
        mmi_wcsncpy(buffer->l_name, l_name, MMI_PHB_NAME_FIELD_LENGTH);
    }
    else
    {
        buffer->l_name[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_number
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_number(
                srv_phb_tcard_data_struct * buffer,
                CHAR *number,
                U16 sub_id,
                U8 type,
                U8 last_used_sim,
                U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (number != NULL && number[0])
    {
        buffer->num[index].sub_id = sub_id;
        buffer->num[index].type =(mmi_phb_num_type_enum)type;
        buffer->num[index].last_used_sim = last_used_sim;
        strncpy((CHAR *)(buffer->num[index].number), number, MMI_PHB_NUMBER_PLUS_LENGTH);
    }
    else
    {
        buffer->num[index].sub_id = 0;
        buffer->num[index].type = MMI_PHB_NUM_TYPE_NONE;
        buffer->num[index].last_used_sim = 0;
        buffer->num[index].number[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_email
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_email(
                srv_phb_tcard_data_struct * buffer,
                CHAR *email,
                U16 sub_id,
                U8 type,
                U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (email != NULL && email[0])
    {
        buffer->email[index].sub_id = sub_id;
        buffer->email[index].type = type;
        strncpy((CHAR *)(buffer->email[index].email), email, MMI_PHB_EMAIL_LENGTH);
    }
    else
    {
        buffer->email[index].sub_id = 0;
        buffer->email[index].type = 0;
        buffer->email[index].email[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_image
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_image(srv_phb_tcard_data_struct * buffer, srv_phb_tcard_res_path_struct *res_path, U16 image_id, U16 *image_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *res_type = &(buffer->res_field.res_type);
    *res_type &= ~ SRV_PHB_RES_TYPE_IMAGE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (image_path && image_path[0])
    {
        *res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
        mmi_wcsncpy(res_path->image_path, image_path, SRV_FMGR_PATH_MAX_LEN);
    }
    else
    {
        *res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
        buffer->res_field.image_id = image_id;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_ring
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_ring(srv_phb_tcard_data_struct * buffer, srv_phb_tcard_res_path_struct *res_path, U16 ringtone_id, U16 *ring_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *res_type = &(buffer->res_field.res_type);
    *res_type &= ~ SRV_PHB_RES_TYPE_RING;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ring_path && ring_path[0])
    {
        *res_type |= SRV_PHB_RES_TYPE_RING_FILE;
        mmi_wcsncpy(res_path->ring_path, ring_path, SRV_FMGR_PATH_MAX_LEN);
    }
    else
    {
        *res_type |= SRV_PHB_RES_TYPE_RING_ID;
        buffer->res_field.ringtone_id = ringtone_id;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_video
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_video(srv_phb_tcard_data_struct * buffer, srv_phb_tcard_res_path_struct *res_path, U16 video_id, U16 *video_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 *res_type = &(buffer->res_field.res_type);
    *res_type &= ~ SRV_PHB_RES_TYPE_VIDEO;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (video_path && video_path[0])
    {
        *res_type |= SRV_PHB_RES_TYPE_VIDEO_FILE;
        mmi_wcsncpy(res_path->video_path, video_path, SRV_FMGR_PATH_MAX_LEN);
    }
    else
    {
        *res_type |= SRV_PHB_RES_TYPE_VIDEO_ID;
        buffer->res_field.video_id = video_id;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_group
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_group(srv_phb_tcard_info_struct *buffer, U32 group_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    buffer->group = group_mask;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_company
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_company(srv_phb_tcard_info_struct *buffer, WCHAR *company)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (company != NULL && company[0])
    {
        mmi_wcsncpy(buffer->company, company, MMI_PHB_COMPANY_LENGTH);
    }
    else
    {
        buffer->company[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_title
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_title(srv_phb_tcard_info_struct *buffer, WCHAR *title)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (title != NULL && title[0])
    {
        mmi_wcsncpy(buffer->title, title, MMI_PHB_COMPANY_LENGTH);
    }
    else
    {
        buffer->title[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_note
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_note(srv_phb_tcard_info_struct *buffer, WCHAR *note)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (note != NULL)
    {
        mmi_wcsncpy(buffer->note, note, MMI_PHB_NOTE_LENGTH);
    }
    else
    {
        buffer->note[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_url
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_url(srv_phb_tcard_info_struct *buffer, CHAR *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (url != NULL && url[0])
    {
        strcpy((CHAR *)(buffer->url), url);
    }
    else
    {
        buffer->url[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_birthday
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_birthday(srv_phb_tcard_info_struct *buffer, mmi_phb_bday_struct* birthday)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (birthday != NULL)
    {
        buffer->bday.b_year = birthday->b_year;
        buffer->bday.b_month = birthday->b_month;
        buffer->bday.b_day = birthday->b_day;
    }
    else
    {
        buffer->bday.b_year = 0;
        buffer->bday.b_month = 0;
        buffer->bday.b_day = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_buffer_address
 * DESCRIPTION
 *  build buffer for writing record
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_buffer_address(srv_phb_tcard_info_struct *buffer, mmi_phb_address_struct *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (address != NULL)
    {
        mmi_wcsncpy(
            (WCHAR*)(buffer->address.pobox),
            (WCHAR*)(address->pobox),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(buffer->address.extension),
            (WCHAR*)(address->extension),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(buffer->address.street),
            (WCHAR*)(address->street),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(buffer->address.city),
            (WCHAR*)(address->city),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(buffer->address.state),
            (WCHAR*)(address->state),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(buffer->address.postalcode),
            (WCHAR*)(address->postalcode),
            MMI_PHB_ADDRESS_LENGTH);
        mmi_wcsncpy(
            (WCHAR*)(buffer->address.country),
            (WCHAR*)(address->country),
            MMI_PHB_ADDRESS_LENGTH);
    }
    else
    {
        buffer->address.pobox[0] = 0;
        buffer->address.extension[0] = 0;
        buffer->address.street[0] = 0;
        buffer->address.city[0] = 0;
        buffer->address.state[0] = 0;
        buffer->address.postalcode[0] = 0;
        buffer->address.country[0] = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_init_data_buffer
 * DESCRIPTION
 *  init data buffer
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_init_data_buffer(srv_phb_tcard_data_struct *data, srv_phb_tcard_res_path_struct *res_path, U16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 field_mask = srv_phb_tcard_get_field_mask(index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (field_mask & MMI_PHB_CONTACT_FIELD_NAME)
    {
        srv_phb_tcard_build_buffer_name(
            data,
            srv_phb_tcard_get_first_name(index),
            srv_phb_tcard_get_last_name(index));
    }
    if (field_mask & MMI_PHB_CONTACT_FIELD_NUMBER)
    {
        U16 sub_id;
        U8 type;
        U8 last_used_sim;
        CHAR *number;
        for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i ++)
        {
            number = srv_phb_tcard_get_number(index, i, &sub_id, &type, &last_used_sim);
            srv_phb_tcard_build_buffer_number(
                data,
                number,
                sub_id,
                type,
                last_used_sim,
                i);
        }
    }
    if (field_mask & MMI_PHB_CONTACT_FIELD_EMAIL)
    {
        U16 sub_id;
        U8 type;
        CHAR *email;
        for (i = 0; i < MMI_PHB_EMAIL_FIELD_COUNT; i ++)
        {
            email = srv_phb_tcard_get_email(index, i, &sub_id, &type);
            srv_phb_tcard_build_buffer_email(
                data,
                email,
                sub_id,
                type,
                i);
        }
    }
    if (field_mask & MMI_PHB_CONTACT_FIELD_IMAGE)
    {
        U16 image_id;
        U16 image_path[SRV_FMGR_PATH_MAX_LEN + 1];
        U16 res_type;
        srv_phb_tcard_get_image(
            index,
            &image_id,
            image_path,
            &res_type);
        srv_phb_tcard_build_buffer_image(
            data,
            res_path,
            image_id,
            image_path);
    }
    if (field_mask & MMI_PHB_CONTACT_FIELD_RING)
    {
        U16 ringtone_id;
        U16 ringtone_path[SRV_FMGR_PATH_MAX_LEN + 1];
        U16 res_type;
        srv_phb_tcard_get_ringtone(
            index,
            &ringtone_id,
            ringtone_path,
            &res_type);
        srv_phb_tcard_build_buffer_ring(
            data,
            res_path,
            ringtone_id,
            ringtone_path);
    }
    
    #ifdef __MMI_PHB_CALLER_VIDEO__
    if (field_mask & MMI_PHB_CONTACT_FIELD_VIDEO)
    {
        U16 video_id = 0;
        U16 video_path[SRV_FMGR_PATH_MAX_LEN + 1];
        U16 res_type;
        srv_phb_tcard_get_video(
            index,
            &video_id,
            video_path,
            &res_type);
        srv_phb_tcard_build_buffer_video(
            data,
            res_path,
            video_id,
            video_path);
    }
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_init_info_buffer
 * DESCRIPTION
 *  init info buffer
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_init_info_buffer(srv_phb_tcard_info_struct *info, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field_mask = srv_phb_tcard_get_field_mask(index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #ifdef __MMI_PHB_CALLER_GROUP__
    if (field_mask & MMI_PHB_CONTACT_FIELD_GROUP)
    {
        srv_phb_tcard_build_buffer_group(info, srv_phb_tcard_get_group_mask(index));
    }
    #endif

    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    if (field_mask & MMI_PHB_CONTACT_FIELD_COMPANY)
    {
        srv_phb_tcard_build_buffer_company(info, srv_phb_tcard_get_company(index));
    }
    #endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */

    #ifdef __MMI_PHB_INFO_FIELD__
    if (field_mask & MMI_PHB_CONTACT_FIELD_TITLE)
    {
        srv_phb_tcard_build_buffer_title(info, srv_phb_tcard_get_title(index));
    }
    if (field_mask & MMI_PHB_CONTACT_FIELD_NOTE)
    {
        srv_phb_tcard_build_buffer_note(info, srv_phb_tcard_get_note(index));
    }
    if (field_mask & MMI_PHB_CONTACT_FIELD_URL)
    {
        srv_phb_tcard_build_buffer_url(info, srv_phb_tcard_get_url(index));
    }
    if (field_mask & MMI_PHB_CONTACT_FIELD_ADDRESS)
    {
        srv_phb_tcard_build_buffer_address(info, srv_phb_tcard_get_address(index));
    }
    #endif

    #ifdef __MMI_PHB_BIRTHDAY_FIELD__
    if (field_mask & MMI_PHB_CONTACT_FIELD_BDAY)
    {
        srv_phb_tcard_build_buffer_birthday(info, srv_phb_tcard_get_birthday(index));
    }
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_data_buffer
 * DESCRIPTION
 *  build data buffer
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_data_buffer(srv_phb_tcard_data_struct *data, srv_phb_tcard_res_path_struct *res_path, srv_phb_contact contact, U32 update_field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (update_field & MMI_PHB_CONTACT_FIELD_NAME)
    {
        srv_phb_tcard_build_buffer_name(
            data,
            srv_phb_contact_get_fname(contact),
            srv_phb_contact_get_lname(contact)
            );
    }
    if (update_field & MMI_PHB_CONTACT_FIELD_NUMBER)
    {
        srv_phb_iterator iterator = srv_phb_contact_get_number_iterator(contact);
        CHAR asc_number[MMI_PHB_NUMBER_LENGTH + 1];
        srv_phb_number_struct *number;
        memset(data->num, 0x00, sizeof(mmi_phb_asc_num_struct) * MMI_PHB_TCARD_NUMBER_COUNT);
        while (iterator)
        {
            number = srv_phb_contact_get_number_next(&iterator);
            if (number != NULL)
            {
                mmi_wcs_to_asc(asc_number, number->number);
                if (number->sub_id == SRV_PHB_INVALID_INDEX)
                {
                    number->sub_id = srv_phb_tcard_get_free_sub_id(data);
                }
                srv_phb_tcard_build_buffer_number(
                    data,
                    asc_number,
                    number->sub_id,
                    number->type,
                    number->last_used_sim,
                    i ++);
            }
        }
    }
    if (update_field & MMI_PHB_CONTACT_FIELD_EMAIL)
    {
        srv_phb_iterator iterator = srv_phb_contact_get_email_iterator(contact);
        srv_phb_email_struct *email;
        CHAR asc_email[MMI_PHB_EMAIL_LENGTH + 1];
        i = 0;
        memset(data->email, 0x00, sizeof(mmi_phb_email_struct) * MMI_PHB_TCARD_EMAIL_COUNT);
        while (iterator)
        {
            email = srv_phb_contact_get_email_next(&iterator);
            if (email != NULL)
            {
                mmi_wcs_to_asc(asc_email, email->email);
                srv_phb_tcard_build_buffer_email(
                    data,
                    asc_email,
                    email->sub_id,
                    email->type,
                    i ++);
            }
        }
    }

    if (update_field & MMI_PHB_CONTACT_FIELD_IMAGE)
    {
        srv_phb_res_struct *image = srv_phb_contact_get_image(contact);
        if (image != NULL)
        {
            srv_phb_tcard_build_buffer_image(
                data,
                res_path,
                image->res_id,
                image->res_path);
        }
    }

    if (update_field & MMI_PHB_CONTACT_FIELD_RING)
    {
        srv_phb_res_struct *ringtone = srv_phb_contact_get_ringtone(contact);
        if (ringtone != NULL)
        {
            srv_phb_tcard_build_buffer_ring(
                data,
                res_path,
                ringtone->res_id,
                ringtone->res_path);
        }
    }
    if (update_field & MMI_PHB_CONTACT_FIELD_VIDEO)
    {
        srv_phb_res_struct *video = srv_phb_contact_get_video(contact);
        if (video != NULL)
        {
            srv_phb_tcard_build_buffer_video(
                data,
                res_path,
                video->res_id,
                video->res_path);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_info_buffer
 * DESCRIPTION
 *  build info buffer
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_build_info_buffer(srv_phb_tcard_info_struct *info, srv_phb_contact contact, U32 update_field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (update_field & MMI_PHB_CONTACT_FIELD_GROUP)
    {
        U32 i;
        U32 group_mask = 0;
        srv_phb_group_struct * group = srv_phb_contact_get_group(contact);
        if (group != NULL)
        {
            for (i = 0; i < group->group_count; i ++)
            {
                group_mask |= 1 << (group->group_id[i] - MMI_PHB_GROUP_COUNT - MMI_PHB_GROUP_USIM_COUNT);
            }
            srv_phb_tcard_build_buffer_group(info, group_mask);
        }
    }
    if (update_field & MMI_PHB_CONTACT_FIELD_COMPANY)
    {
        srv_phb_tcard_build_buffer_company(info, srv_phb_contact_get_company(contact));
    }
    if (update_field & MMI_PHB_CONTACT_FIELD_TITLE)
    {
        srv_phb_tcard_build_buffer_title(info, srv_phb_contact_get_title(contact));
    }
    if (update_field & MMI_PHB_CONTACT_FIELD_NOTE)
    {
        srv_phb_iterator iterator = srv_phb_contact_get_note_iterator(contact);
        srv_phb_note_struct *note = srv_phb_contact_get_note_next(&iterator);
        if (note != NULL)
        {
            srv_phb_tcard_build_buffer_note(info, note->note);
        }
    }
    if (update_field & MMI_PHB_CONTACT_FIELD_URL)
    {
        srv_phb_iterator iterator = srv_phb_contact_get_url_iterator(contact);
        srv_phb_url_struct *url = srv_phb_contact_get_url_next(&iterator);
        if (url != NULL)
        {
            CHAR asc_url[MMI_PHB_URL_LENGTH + 1];
            mmi_wcs_to_asc(asc_url, url->url);
            srv_phb_tcard_build_buffer_url(info, asc_url);
        }
    }
    if (update_field & MMI_PHB_CONTACT_FIELD_ADDRESS)
    {
        srv_phb_iterator iterator = srv_phb_contact_get_address_iterator(contact);
        srv_phb_address_struct *address = srv_phb_contact_get_address_next(&iterator);
        if (address != NULL)
        {
            srv_phb_tcard_build_buffer_address(info, &(address->address));
        }
    }
    if (update_field & MMI_PHB_CONTACT_FIELD_BDAY)
    {
        srv_phb_tcard_build_buffer_birthday(info, srv_phb_contact_get_bday(contact));
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_build_field_mask
 * DESCRIPTION
 *  build field mask for the update contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static U32 srv_phb_tcard_build_field_mask(srv_phb_tcard_data_struct *data, srv_phb_tcard_info_struct *info, srv_phb_tcard_res_path_struct *res_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 field_mask = 0;
    MMI_BOOL is_exist = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (data != NULL)
    {
        if (data->name[0] || data->l_name[0])
        {
            field_mask |= MMI_PHB_CONTACT_FIELD_NAME;
            is_exist = MMI_TRUE;
        }
        if (data->num[0].number[0])
        {
            field_mask |= MMI_PHB_CONTACT_FIELD_NUMBER;
            is_exist = MMI_TRUE;
        }
        if (data->email[0].email[0])
        {
            field_mask |= MMI_PHB_CONTACT_FIELD_EMAIL;
            is_exist = MMI_TRUE;
        }
        if (is_exist == MMI_TRUE)
        {
            field_mask |= MMI_PHB_CONTACT_FIELD_EXIST;
            if (res_path->image_path[0] || data->res_field.image_id)
            {
                field_mask |= MMI_PHB_CONTACT_FIELD_IMAGE;
            }
            if (res_path->ring_path[0] || data->res_field.ringtone_id)
            {
                field_mask |= MMI_PHB_CONTACT_FIELD_RING;
            }
            if (res_path->video_path[0] || data->res_field.video_id)
            {
                field_mask |= MMI_PHB_CONTACT_FIELD_VIDEO;
            }
        }
    }

    if (info != NULL && is_exist == MMI_TRUE)
    {
        if (info->group)
        {
            field_mask |= MMI_PHB_CONTACT_FIELD_GROUP;
        }
        if (info->company[0])
        {
            field_mask |= MMI_PHB_CONTACT_FIELD_COMPANY;
        }
        if (info->title[0])
        {
            field_mask |= MMI_PHB_CONTACT_FIELD_TITLE;
        }
        if (info->note[0])
        {
            field_mask |= MMI_PHB_CONTACT_FIELD_NOTE;
        }
        if (info->url[0])
        {
            field_mask |= MMI_PHB_CONTACT_FIELD_URL;
        }
        if (info->address.pobox[0] ||
            info->address.extension[0] ||
            info->address.street[0] ||
            info->address.city[0] ||
            info->address.state[0] ||
            info->address.postalcode[0] ||
            info->address.country[0])
        {
            field_mask |= MMI_PHB_CONTACT_FIELD_ADDRESS;
        }
        if (info->bday.b_year)
        {
            field_mask |= MMI_PHB_CONTACT_FIELD_BDAY;
        }
    }

    return field_mask;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_op_done
 * DESCRIPTION
 *  when an operation done, free memory here
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_op_done(void *cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_tcard_op_cntx *op_cntx = cntx;
    srv_phb_datamgr_op_cntx_struct* datamgr_cntx = srv_phb_datamgr_get_op_cntx();
    if (datamgr_cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_COPY && datamgr_cntx->contact)
    {
        srv_phb_free_contact(datamgr_cntx->contact);
        datamgr_cntx->contact = NULL;
    }

    if (op_cntx != NULL)
    {
        srv_phb_datamgr_op_status_struct status;
        status.result = op_cntx->result;
        srv_phb_mem_free(op_cntx->data);
        op_cntx->data = NULL;
        srv_phb_mem_free(op_cntx->info);
        op_cntx->info = NULL;
        srv_phb_record_index_to_store_index(PHB_STORAGE_TCARD, op_cntx->record_id, &status.id);
        srv_phb_datamgr_op_done(&status);
        srv_phb_mem_free(op_cntx);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_write_info_field_cb
 * DESCRIPTION
 *  write info field call back
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_write_info_field_cb(srv_tcard_callback_struct *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_set;
    srv_phb_tcard_op_cntx *op_cntx = (srv_phb_tcard_op_cntx *)(user_data->user_data);
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    U16 index = cntx->pos.index;
    srv_phb_contact contact = cntx->contact;
    U32 update_field = cntx->update_field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #ifdef __MMI_PHB_CALLER_GROUP__
    if (update_field & MMI_PHB_CONTACT_FIELD_GROUP)
    {
        U32 i;
        U32 group_mask = 0;
        srv_phb_group_struct *group = srv_phb_contact_get_group(contact);
        if (group != NULL)
        {
            for (i = 0; i < group->group_count; i ++)
            {
                group_mask |= 1 << (group->group_id[i] - MMI_PHB_GROUP_COUNT - MMI_PHB_GROUP_USIM_COUNT);
            }
            srv_phb_tcard_set_group_mask(index, group_mask);
            is_set = MMI_TRUE;
        }
        else
        {
            is_set = MMI_FALSE;
        }
        srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_GROUP, is_set);
    }
    #endif

    #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    if (update_field & MMI_PHB_CONTACT_FIELD_COMPANY)
    {
        WCHAR *company = srv_phb_contact_get_company(contact);
        if (company != NULL)
        {
            srv_phb_tcard_set_company(index, company);
            is_set = MMI_TRUE;
        }
        else
        {
            is_set = MMI_FALSE;
        }
        srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_COMPANY, is_set);
    }
    #endif

    #ifdef __MMI_PHB_INFO_FIELD__
    if (update_field & MMI_PHB_CONTACT_FIELD_TITLE)
    {
        WCHAR *title = srv_phb_contact_get_title(contact);
        if (title != NULL)
        {
            srv_phb_tcard_set_title(index, title);
            is_set = MMI_TRUE;
        }
        else
        {
            is_set = MMI_FALSE;
        }
        srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_TITLE, is_set);
    }

    if (update_field & MMI_PHB_CONTACT_FIELD_NOTE)
    {
        srv_phb_iterator iterator = srv_phb_contact_get_note_iterator(contact);
        srv_phb_note_struct *note = srv_phb_contact_get_note_next(&iterator);
        if (note != NULL)
        {
            srv_phb_tcard_set_note(index, note->note);
            is_set = MMI_TRUE;
        }
        else
        {
            is_set = MMI_FALSE;
        }
        srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_ID_NOTE, is_set);
    }

    if (update_field & MMI_PHB_CONTACT_FIELD_URL)
    {
        srv_phb_iterator iterator = srv_phb_contact_get_url_iterator(contact);
        srv_phb_url_struct *url = srv_phb_contact_get_url_next(&iterator);
        if (url != NULL)
        {
            CHAR asc_url[MMI_PHB_URL_LENGTH + 1];
            mmi_wcs_to_asc(asc_url, url->url);
            srv_phb_tcard_set_url(index, asc_url);
            is_set = MMI_TRUE;
        }
        else
        {
            is_set = MMI_FALSE;
        }
        srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_URL, is_set);
    }

    if (update_field & MMI_PHB_CONTACT_FIELD_ADDRESS)
    {
        srv_phb_iterator iterator = srv_phb_contact_get_address_iterator(contact);
        srv_phb_address_struct *address = srv_phb_contact_get_address_next(&iterator);
        if (address != NULL)
        {
            srv_phb_tcard_set_address(index, &(address->address));
            is_set = MMI_TRUE;
        }
        else
        {
            is_set = MMI_FALSE;
        }
        srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_ADDRESS, is_set);
    }
    #endif

    #ifdef __MMI_PHB_BIRTHDAY_FIELD__
    if (update_field & MMI_PHB_CONTACT_FIELD_BDAY)
    {
        srv_phb_bday_struct * birthday = srv_phb_contact_get_bday(contact);
        if (birthday != NULL && birthday->b_year)
        {
            srv_phb_tcard_set_birthday(index, birthday);
            is_set = MMI_TRUE;
        }
        else
        {
            is_set = MMI_FALSE;
        }
        srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_BDAY, is_set);
    }
    #endif

    srv_phb_async_event_interface(srv_phb_tcard_op_done, op_cntx);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_write_data_field_cb
 * DESCRIPTION
 *  write data field call back
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_write_data_field_cb(srv_tcard_callback_struct *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 id;
    MMI_BOOL is_set;
    U16 res_type = 0;
    srv_phb_tcard_op_cntx *op_cntx = (srv_phb_tcard_op_cntx *)(user_data->user_data);
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    U16 index = cntx->pos.index;
    srv_phb_contact contact = cntx->contact;
    U32 update_field = cntx->update_field;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (user_data->result == MMI_TRUE)
    {
        srv_phb_record_index_to_store_index(PHB_STORAGE_TCARD, cntx->pos.index, &id);
        if (cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_ADD || cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_COPY)
        {
            srv_phb_tcard_increase_used_count();
            srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_EXIST, MMI_TRUE);
            update_field = srv_phb_get_support_field(PHB_STORAGE_TCARD);
        }
        if (update_field & MMI_PHB_CONTACT_FIELD_NAME)
        {
            MMI_BOOL is_modify = srv_phb_tcard_set_name(
                                            index,
                                            srv_phb_contact_get_fname(contact),
                                            srv_phb_contact_get_lname(contact));
            if ((cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_UPD) && (is_modify))
            {
                srv_phb_sse_delete_name_index(id);
            }
            if ((cntx->op_type != SRV_PHB_DATAMGR_OP_TYPE_UPD) || (is_modify))
            {
                WCHAR *name = srv_phb_contact_get_name(contact);
                srv_phb_sse_insert_name_index(id, name);            
                #if defined(__MMI_PHB_PINYIN_SORT__)
                srv_phb_sse_make_pinyin_cache(id, name);
                #endif
                if (name != NULL && name[0])
                {
                    is_set = MMI_TRUE;
                }
                else
                {
                    is_set = MMI_FALSE;
                }
                srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_NAME, is_set);
            }
        }

        if (update_field & MMI_PHB_CONTACT_FIELD_NUMBER) 
        {
            srv_phb_iterator iterator = srv_phb_contact_get_number_iterator(contact);
            srv_phb_number_struct *number;
            CHAR asc_number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
            U32 i = 0;
            srv_phb_tcard_clear_number(index);
            while (iterator)
            {
                number = srv_phb_contact_get_number_next(&iterator);
                if (number != NULL)
                {
                    mmi_wcs_to_asc(asc_number, number->number);
                    srv_phb_tcard_set_number(
                        index,
                        i ++,
                        asc_number,
                        number->sub_id,
                        number->type,
                        number->last_used_sim
                        );
                    if (asc_number[0])
                    {
                        srv_phb_sse_lookup_table_remove_contact(id, asc_number);
                        srv_phb_sse_lookup_table_add_contact(id, asc_number);
                    }
                }
            }
            if (i == 0)
            {
                is_set = MMI_FALSE;
            }
            else
            {
                is_set = MMI_TRUE;
            }
            srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_NUMBER, is_set);
        }

        if (update_field & MMI_PHB_CONTACT_FIELD_EMAIL) 
        {
            srv_phb_iterator iterator = srv_phb_contact_get_email_iterator(contact);
            srv_phb_email_struct *email;
            CHAR asc_email[MMI_PHB_EMAIL_LENGTH + 1];
            U32 i = 0;
            srv_phb_tcard_clear_email(index);
            while (iterator)
            {
                email = srv_phb_contact_get_email_next(&iterator);
                if (email != NULL)
                {
                    mmi_wcs_to_asc(asc_email, email->email);
                    srv_phb_tcard_set_email(
                        index,
                        i ++,
                        asc_email,
                        email->sub_id,
                        email->type
                        );
                }
            }
            if (i == 0)
            {
                is_set = MMI_FALSE;
            }
            else
            {
                is_set = MMI_TRUE;
            }
            srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_EMAIL, is_set);
        }

        if (update_field & MMI_PHB_CONTACT_FIELD_IMAGE)
        {
            srv_phb_res_struct *image = srv_phb_contact_get_image(contact);
            if (image != NULL)
            {
                res_type &= ~SRV_PHB_RES_TYPE_IMAGE;
                if (image->res_path[0])
                {
                    res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
                }
                else
                {
                    res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
                }
                srv_phb_tcard_set_image(index, image->res_id, res_type);
                is_set = MMI_TRUE;
            }
            else
            {
                is_set = MMI_FALSE;
            }
            srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_IMAGE, is_set);
        }

        if (update_field & MMI_PHB_CONTACT_FIELD_RING)
        {
            srv_phb_res_struct *ringtone = srv_phb_contact_get_ringtone(contact);
            if (ringtone != NULL)
            {
                res_type &= ~SRV_PHB_RES_TYPE_RING;
                if (ringtone->res_path[0])
                {
                    res_type |= SRV_PHB_RES_TYPE_RING_FILE;
                }
                else
                {
                    res_type |= SRV_PHB_RES_TYPE_RING_ID;
                }
                srv_phb_tcard_set_ringtone(index, ringtone->res_id, res_type);
                is_set = MMI_TRUE;
            }
            else
            {
                is_set = MMI_FALSE;
            }
            srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_RING, is_set);
        }
        #ifdef __MMI_PHB_CALLER_VIDEO__
        if (update_field & MMI_PHB_CONTACT_FIELD_ID_VIDEO)
        {
            srv_phb_res_struct *video = srv_phb_contact_get_video(contact);
            if (video != NULL)
            {
                res_type &= ~SRV_PHB_RES_TYPE_VIDEO;
                if (video->res_path[0])
                {
                    res_type |= SRV_PHB_RES_TYPE_VIDEO_FILE;
                }
                else
                {
                    res_type |= SRV_PHB_RES_TYPE_VIDEO_ID;
                }
                srv_phb_tcard_set_video(index, video->res_id, res_type);
                is_set = MMI_TRUE;
            }
            else
            {
                is_set = MMI_FALSE;
            }
            srv_phb_tcard_set_field_mask(index, MMI_PHB_CONTACT_FIELD_VIDEO, is_set);
        }
        #endif

        if (op_cntx->info != NULL && cntx->update_field & MMI_PHB_TCARD_CONTACT_INFO_FIELD)
        {
            srv_phb_tcard_write_record(
                SRV_PHB_TCARD_INFO_FIELD,
                cntx->pos.index,
                1,
                (CHAR *)(op_cntx->info),
                srv_phb_tcard_write_info_field_cb,
                op_cntx);
            return;
        }
    }
    else
    {
        op_cntx->result = SRV_PHB_TCARD_ERROR; //T card not pass error code,just true  or false, so here no detail error code.
    }
    srv_phb_async_event_interface(srv_phb_tcard_op_done, op_cntx);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_delete_contact_cb
 * DESCRIPTION
 *  delete contact call back
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_delete_contact_cb(srv_tcard_callback_struct *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_contact_id id;
    srv_phb_tcard_op_cntx *op_cntx = (srv_phb_tcard_op_cntx *)(user_data->user_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    srv_phb_tcard_decrease_used_count();
    srv_phb_record_index_to_store_index(PHB_STORAGE_TCARD, op_cntx->record_id, &id);
    srv_phb_sse_delete_name_index(id);
    srv_phb_sse_lookup_table_remove_contact(id, NULL);
    srv_phb_tcard_set_field_mask((op_cntx->record_id), MMI_PHB_CONTACT_FIELD_ALL, MMI_FALSE);
    srv_phb_async_event_interface(srv_phb_tcard_op_done, op_cntx);
}

static void srv_phb_tcard_read_data_field_cb(srv_tcard_callback_struct *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_read_next
 * DESCRIPTION
 *  read next contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_read_next(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_tcard_op_cntx *op_cntx = (srv_phb_tcard_op_cntx *)user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   
    if (op_cntx->record_id + op_cntx->count > MMI_PHB_TCARD_ENTRIES)
    {
        op_cntx->count = MMI_PHB_TCARD_ENTRIES - op_cntx->record_id;
    }
    srv_phb_tcard_read_record(
        SRV_PHB_TCARD_DATA_FIELD,
        op_cntx->record_id,
        op_cntx->count,
        (CHAR *)(op_cntx->data),
        srv_phb_tcard_read_data_field_cb,
        op_cntx);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_init_done
 * DESCRIPTION
 *  tcard init read done
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_init_done(void *cntx)
{
    srv_phb_tcard_read_all_group_info();
    srv_phb_tcard_set_ready(MMI_TRUE);
    srv_phb_tcard_op_done(cntx);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_read_info_field_cb
 * DESCRIPTION
 *  read info field call back
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_read_info_field_cb(srv_tcard_callback_struct *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_phb_tcard_op_cntx *op_cntx = (srv_phb_tcard_op_cntx *)(user_data->user_data);
    U32 index = op_cntx->record_id;
    U32 field_mask = srv_phb_tcard_get_field_mask(index);
    srv_phb_tcard_info_struct *info = op_cntx->info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < op_cntx->count; i++)
    {
        #ifdef __MMI_PHB_CALLER_GROUP__
        if (field_mask & MMI_PHB_CONTACT_FIELD_GROUP)
        {
            srv_phb_tcard_set_group_mask(index, info->group);
        }
        #endif

        #ifdef __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
        if (field_mask & MMI_PHB_CONTACT_FIELD_COMPANY)
        {
            srv_phb_tcard_set_company(index, info->company);
        }
        #endif

        #ifdef __MMI_PHB_INFO_FIELD__
        if (field_mask & MMI_PHB_CONTACT_FIELD_URL)
        {
            srv_phb_tcard_set_url(index, (CHAR *)(info->url));
        }
        if (field_mask & MMI_PHB_CONTACT_FIELD_TITLE)
        {
            srv_phb_tcard_set_title(index, info->title);
        }
        if (field_mask & MMI_PHB_CONTACT_FIELD_NOTE)
        {
            srv_phb_tcard_set_note(index, info->note);
        }
        if (field_mask & MMI_PHB_CONTACT_FIELD_ADDRESS)
        {
            srv_phb_tcard_set_address(index, &(info->address));
        }
        #endif

        #ifdef __MMI_PHB_BIRTHDAY_FIELD__
        if (field_mask & MMI_PHB_CONTACT_FIELD_BDAY)
        {
            srv_phb_tcard_set_birthday(index, &(info->bday));
        }
        #endif
        index ++;
    }
    
    op_cntx->record_id += op_cntx->count;
    if (op_cntx->record_id < MMI_PHB_TCARD_ENTRIES)
    {
        srv_phb_async_event_interface(srv_phb_tcard_read_next, op_cntx);
    }
    else
    {
        srv_phb_tcard_init_done(op_cntx);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_read_data_field_cb
 * DESCRIPTION
 *  read data field call back
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_tcard_read_data_field_cb(srv_tcard_callback_struct *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     U32 i, j; 
     U32 field_mask;
     U16 name[MMI_PHB_NAME_LENGTH + 1];
     U16 id;
     MMI_BOOL load_info = MMI_FALSE;
     srv_phb_tcard_op_cntx *op_cntx = (srv_phb_tcard_op_cntx *)(user_data->user_data);
     srv_phb_tcard_data_struct *data = op_cntx->data;
     U32 index = op_cntx->record_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    for (i = 0; i < op_cntx->count; i++)
    {
        field_mask = data->field_mask;
        if (field_mask & MMI_PHB_CONTACT_FIELD_EXIST)
        {
            srv_phb_record_index_to_store_index(PHB_STORAGE_TCARD, index, &id);
            if (field_mask & MMI_PHB_CONTACT_FIELD_NAME)
            {
                srv_phb_tcard_set_name(index, data->name, data->l_name);
            }
            
            if (field_mask & MMI_PHB_CONTACT_FIELD_NUMBER)
            {
                for (j = 0; j < MMI_PHB_NUMBER_FIELD_COUNT; j ++)
                {
                    CHAR * asc_number = (CHAR *)(data->num[j].number);
                    srv_phb_tcard_set_number(index, j, asc_number, data->num[j].sub_id, data->num[j].type, data->num[j].last_used_sim);
                    if (asc_number[0])
                    {
                        srv_phb_sse_lookup_table_remove_contact(id, asc_number);
                        srv_phb_sse_lookup_table_add_contact(id, asc_number);
                    }
                }
            }

            if (field_mask & MMI_PHB_CONTACT_FIELD_EMAIL)
            {
                for (j = 0; j < MMI_PHB_EMAIL_FIELD_COUNT; j ++)
                {
                    srv_phb_tcard_set_email(index, j, (CHAR *)(data->email[j].email), data->email[j].sub_id, data->email[j].type);
                }
            }
            srv_phb_tcard_malloc_info_cache(index);
            if (field_mask & MMI_PHB_CONTACT_FIELD_IMAGE)
            {
                srv_phb_tcard_set_image(index, data->res_field.image_id, data->res_field.res_type);
            }

            if (field_mask & MMI_PHB_CONTACT_FIELD_RING)
            {
                srv_phb_tcard_set_ringtone(index, data->res_field.ringtone_id, data->res_field.res_type);
            }

            #ifdef __MMI_PHB_CALLER_VIDEO__
            if (field_mask & MMI_PHB_CONTACT_FIELD_VIDEO)
            {
                srv_phb_tcard_set_video(index, data->res_field.video_id, data->res_field.res_type);
            }
            #endif
            
            srv_phb_tcard_increase_used_count();
            srv_phb_tcard_set_field_mask(index, field_mask, MMI_TRUE);
            srv_phb_convert_to_name(name, data->name, data->l_name, MMI_PHB_NAME_LENGTH);
            srv_phb_sse_insert_name_index(id, name);
            #if defined(__MMI_PHB_PINYIN_SORT__)
            srv_phb_sse_make_pinyin_cache(id, name);
            #endif
        }
        if (field_mask & MMI_PHB_TCARD_CONTACT_INFO_FIELD)
        {
            load_info = MMI_TRUE;
        }
        index ++;
    }

    if (load_info)
    {
        srv_phb_tcard_read_record(
            SRV_PHB_TCARD_INFO_FIELD,
            op_cntx->record_id,
            op_cntx->count,
            (CHAR *)op_cntx->info,
            srv_phb_tcard_read_info_field_cb,
            op_cntx);
    }
    else
    {
        op_cntx->record_id += op_cntx->count;
        if (op_cntx->record_id < MMI_PHB_TCARD_ENTRIES)
        {
            srv_phb_async_event_interface(srv_phb_tcard_read_next, op_cntx);
        }
        else
        {
            srv_phb_tcard_init_done(op_cntx);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_init_start
 * DESCRIPTION
 *  start to read records
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_tcard_init_start(void)
{
    srv_phb_tcard_op_cntx *op_cntx = srv_phb_mem_malloc(sizeof(srv_phb_tcard_op_cntx), SRV_PHB_MEMORY_TYPE_CTR);
    op_cntx->data = srv_phb_mem_malloc(sizeof(srv_phb_tcard_data_struct), SRV_PHB_MEMORY_TYPE_ADM);
    op_cntx->info = srv_phb_mem_malloc(sizeof(srv_phb_tcard_info_struct), SRV_PHB_MEMORY_TYPE_ADM);;
    op_cntx->record_id = 0;
    op_cntx->count = 1;
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_TCARD_INIT_START);
    srv_phb_tcard_set_ready(MMI_FALSE);
    srv_phb_tcard_clear_used_count();
    srv_phb_tcard_set_total_count(MMI_PHB_TCARD_ENTRIES);
    srv_phb_sse_delete_name_index_by_storage(PHB_STORAGE_TCARD);
    srv_phb_tcard_read_record(
        SRV_PHB_TCARD_DATA_FIELD,
        op_cntx->record_id,
        1,
        (CHAR *)(op_cntx->data),
        srv_phb_tcard_read_data_field_cb,
        op_cntx);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_on_tcard_ready
 * DESCRIPTION
 *  when tcard send ready event
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret srv_phb_tcard_on_tcard_ready(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    srv_tcard_event_struct *event = (srv_tcard_event_struct *)evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_TCARD_ON_TCARD_READY, ((srv_tcard_event_tcard_ready_struct *)(event->event_info))->is_tcard_ready);
    if (((srv_tcard_event_tcard_ready_struct *)(event->event_info))->is_tcard_ready == MMI_TRUE)
    {
        srv_phb_tcard_init_start();
    }
    else
    {
        srv_phb_tcard_set_ready(MMI_FALSE);
    }
    return MMI_RET_OK;
}


/***************************************************************************** 
 * external function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_phb_tcard_is_ready
 * DESCRIPTION
 *  is tcard ready or not
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_phb_tcard_is_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_srv_phb_tcard_cache.is_ready;
}

#ifdef __MMI_PHB_CALLER_GROUP__
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
void srv_phb_set_tcard_group_info(U8 group_id, srv_phb_group_info_struct* group_info, srv_phb_group_op_type_enum op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    S32 result = SRV_PHB_NO_ERROR;
    U32 record_id = 0;
    srv_phb_tcard_group_struct * group = srv_phb_mem_malloc(sizeof(srv_phb_tcard_group_struct), SRV_PHB_MEMORY_TYPE_ADM);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    memset(group, 0x00, sizeof(srv_phb_tcard_group_struct));
    switch (op_type)
    {
        case SRV_PHB_GROUP_OP_TYPE_ADD:
        {
            for (i = 0; i < MMI_PHB_GROUP_TCARD_COUNT; i ++)
            {
                if (g_srv_phb_tcard_group_cache.group_info[i].group_name[0] == 0)
                {
                    record_id = i;
                    group_id = record_id + MMI_PHB_GROUP_COUNT + MMI_PHB_GROUP_USIM_COUNT; 
                    break;
                }
            }
            if (record_id == MMI_PHB_GROUP_TCARD_COUNT)
            {
                result = SRV_PHB_GROUP_FULL;
                break;
            }
            srv_phb_tcard_dup_group_info(group, group_info);
            break;
        }
        case SRV_PHB_GROUP_OP_TYPE_UPD:
        {
            record_id = group_id - MMI_PHB_GROUP_COUNT - MMI_PHB_GROUP_USIM_COUNT;
            srv_phb_tcard_dup_group_info(group, group_info);
            break;
        }
        case SRV_PHB_GROUP_OP_TYPE_DEL:
        {
            record_id = group_id - MMI_PHB_GROUP_COUNT - MMI_PHB_GROUP_USIM_COUNT;
            break;
        }
    }
    if (srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV) == MMI_TRUE && srv_phb_tcard_is_ready())
    {
        srv_phb_tcard_write_group_info(record_id, group);
        srv_phb_tcard_set_group_info(record_id, (srv_phb_tcard_group_info_struct *)group_info);
    }
    else
    {
        result = SRV_PHB_TCARD_NOT_AVAILABLE;
    }
    srv_phb_group_set_group_done(result, group_id, group->group_name);
    srv_phb_mem_free(group);
}

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
void srv_phb_get_tcard_group_info(U8 group_id, srv_phb_group_info_struct* group_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    U32 index = group_id - MMI_PHB_GROUP_COUNT - MMI_PHB_GROUP_USIM_COUNT;
    srv_phb_tcard_group_info_struct* src = srv_phb_tcard_get_group_info(index);
    mmi_wcsncpy(group_info->group_name, src->group_name, MMI_PHB_GROUP_NAME_LENGTH);
    if (src->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
    {
        mmi_wcsncpy(group_info->image_path, src->image_path, SRV_FMGR_PATH_MAX_LEN);
        group_info->image_id = (0xC000 + group_id);
    }
    else
    {
        group_info->image_id = src->image_id;
        group_info->image_path[0] = 0;
    }
    if (src->res_type & SRV_PHB_RES_TYPE_RING_FILE)
    {
        mmi_wcsncpy(group_info->ringtone_path, src->ringtone_path, SRV_FMGR_PATH_MAX_LEN);
        group_info->ringtone_id = (0xC000 + group_id);
    }
    else
    {
        group_info->ringtone_id = src->ringtone_id;
        group_info->ringtone_path[0] = 0;
    }
    #ifdef __MMI_PHB_CALLER_VIDEO__
    if (src->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE)
    {
        mmi_wcsncpy(group_info->video_path, src->video_path, SRV_FMGR_PATH_MAX_LEN);
        group_info->video_id = (0xC000 + group_id);
    }
    else
    {
        group_info->video_id = src->video_id;
        group_info->video_path[0] = 0;
    }
    #endif
    group_info->res_type = src->res_type;
    group_info->storage = PHB_STORAGE_TCARD;
}

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
void srv_phb_get_tcard_all_group_field(U32 *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        memcpy(buffer, g_srv_phb_tcard_group_cache.group_mask, sizeof(U32) * MMI_PHB_TCARD_ENTRIES);
    }
}

#endif

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
U32 srv_phb_get_tcard_field_mask(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_tcard_is_ready()
        #ifdef __MMI_USB_SUPPORT__
        && srv_usb_is_in_mass_storage_mode_ext() == MMI_FALSE
        #endif
        )
    {
        return srv_phb_tcard_get_field_mask(srv_phb_tcard_get_save_index(id));
    }
    else
    {
        return 0;
    }
}

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
U32 srv_phb_get_tcard_used_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_tcard_cache.used_count;
}

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
U32 srv_phb_get_tcard_total_count(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_srv_phb_tcard_cache.total_count;
}

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
WCHAR* srv_phb_get_tcard_fname(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_phb_tcard_get_first_name(srv_phb_tcard_get_save_index(id));
}

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
WCHAR* srv_phb_get_tcard_lname(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_phb_tcard_get_last_name(srv_phb_tcard_get_save_index(id));

}

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
CHAR* srv_phb_get_tcard_number(mmi_phb_contact_id id, U32 num_index, U16 *sub_id, U8 *type, U8 *prefer_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_tcard_get_number(srv_phb_tcard_get_save_index(id), num_index, sub_id, type, prefer_sim);
}

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
U8 srv_phb_get_tcard_num_count(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_phb_tcard_get_num_count(srv_phb_tcard_get_save_index(id));
}


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
CHAR* srv_phb_get_tcard_email(mmi_phb_contact_id id, U32 email_index, U16 *sub_id, U8 *type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return srv_phb_tcard_get_email(srv_phb_tcard_get_save_index(id), email_index, sub_id, type);
}

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
void srv_phb_get_tcard_image(mmi_phb_contact_id id, U16 *image_id, U16 *image_path, U16 *res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_phb_tcard_get_image(srv_phb_tcard_get_save_index(id), image_id, image_path, res_type);
}

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
void srv_phb_get_tcard_ringtone(mmi_phb_contact_id id, U16 *ringtone_id, U16 *ringtone_path, U16 *res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_phb_tcard_get_ringtone(srv_phb_tcard_get_save_index(id), ringtone_id, ringtone_path, res_type);
}

#ifdef __MMI_PHB_CALLER_VIDEO__
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
void srv_phb_get_tcard_video(mmi_phb_contact_id id, U16 *video_id, U16 *video_path, U16 *res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_phb_tcard_get_video(srv_phb_tcard_get_save_index(id), video_id, video_path, res_type);

}
#endif

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
mmi_phb_info_struct* srv_phb_get_tcard_info_field(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_tcard_get_info_field(srv_phb_tcard_get_save_index(id));
}

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
void srv_phb_read_tcard_contact(mmi_phb_contact_id id, srv_phb_contact contact, srv_phb_field_filter filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U16 index;
    U8 storage;
    U32 contact_mask;
    srv_phb_res_struct *res;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
    {
        return;
    }
    
    srv_phb_store_index_to_record_index(id, &storage, &index);
    contact_mask = srv_phb_tcard_get_field_mask(index);
    if (srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_NAME) &&
        (contact_mask & MMI_PHB_CONTACT_FIELD_NAME))
    {
        WCHAR* name;
        name = srv_phb_tcard_get_first_name(index);
        if (name && name[0])
        {
            srv_phb_contact_set_fname(contact, name);
        }

        #ifdef __MMI_PHB_LAST_NAME_FIELD__
        name = srv_phb_tcard_get_last_name(index);
        if (name && name[0])
        {
            srv_phb_contact_set_lname(contact, name);
        }
        #endif
    }
    if ((contact_mask & MMI_PHB_CONTACT_FIELD_NUMBER) &&
        srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_NUMBER))
    {
        CHAR *number;
        U16 sub_id;
        U8 type;
        U8 last_used_sim;
        for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
        {
            number = srv_phb_tcard_get_number(index, i, &sub_id, &type, &last_used_sim);
            if (number && number[0])
            {
                srv_phb_contact_add_asc_number_ex(
                    contact,
                    sub_id,
                    i,
                    type,
                    last_used_sim,
                    number,
                    srv_phb_phone_get_type_label(type, MMI_PHB_CONTACT_FIELD_ID_NUMBER),
                    MMI_FALSE);

            }
        }
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if ((contact_mask & MMI_PHB_CONTACT_FIELD_EMAIL) &&
        srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_EMAIL))
    {
        CHAR *email;
        U16 sub_id;
        U8 type;
        for (i = 0; i < MMI_PHB_EMAIL_FIELD_COUNT; i++)
        {
            email = srv_phb_tcard_get_email(index, i, &sub_id, &type);
            if (email && email[0])
            {
                srv_phb_contact_add_asc_email(
                    contact,
                    sub_id,
                    i,
                    type,
                    email,
                    srv_phb_phone_get_type_label(type, MMI_PHB_CONTACT_FIELD_ID_EMAIL));
            }
        }
    }
#if __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__
    if (contact_mask & MMI_PHB_CONTACT_FIELD_COMPANY &&
        srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_COMPANY))
    {
        srv_phb_contact_set_company(contact, srv_phb_tcard_get_company(index));
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD_ADDITIONAL__ */
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */

    #ifdef __MMI_PHB_CALLER_GROUP__
    if ((contact_mask & MMI_PHB_CONTACT_FIELD_GROUP) &&
         srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_GROUP))
    {
        U32 i;
        U32 group_mask = srv_phb_tcard_get_group_mask(index);
        srv_phb_group_struct * group = srv_phb_contact_set_group(contact, NULL);
        for (i = 0; i < MMI_PHB_GROUP_TCARD_COUNT; i ++)
        {
            if ((1 << i) & group_mask)
            {
                group->group_id[group->group_count] = (i + MMI_PHB_GROUP_COUNT + MMI_PHB_GROUP_USIM_COUNT);
                group->group_count ++;
            }
        }
    }
    #endif
    
    if ((contact_mask & MMI_PHB_CONTACT_FIELD_IMAGE) &&
         srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_IMAGE))
    {
        U16 res_type;
        U16 image_path[SRV_FMGR_PATH_MAX_LEN];
        res = srv_phb_contact_set_image(contact, NULL);
        srv_phb_tcard_get_image(index, &(res->res_id), image_path, &res_type);
        if (res_type & SRV_PHB_RES_TYPE_IMAGE_FILE &&
            image_path[0])
        {
            mmi_wcscpy(res->res_path, image_path);
        }

        if (res->res_path[0] && srv_fmgr_fs_path_exist(res->res_path) == 0)
        {
            res->res_id = (0x8000 + id);
        }
        else if (res->res_id == 0)
        {
            res->res_id = IMG_PHB_DEFAULT;
        }
    }
    
    if ((contact_mask & MMI_PHB_CONTACT_FIELD_RING) &&
        srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_RING))
    {
        U16 res_type;
        U16 ringtone_path[SRV_FMGR_PATH_MAX_LEN];
        res = srv_phb_contact_set_ringtone(contact, NULL);
        srv_phb_tcard_get_ringtone(index, &(res->res_id), ringtone_path, &res_type);

        if (res_type & SRV_PHB_RES_TYPE_RING_FILE &&
            ringtone_path[0])
        {
            if (srv_fmgr_fs_path_exist(ringtone_path) == 0)
            {
                res->res_id = (0x8000 + id);
                mmi_wcscpy(res->res_path, ringtone_path);
            }
        }
    }
        
    #if defined(__MMI_PHB_CALLER_VIDEO__)
    if ((contact_mask & MMI_PHB_CONTACT_FIELD_VIDEO) &&
        srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_VIDEO))
    {
        U16 res_type;
        U16 video_path[SRV_FMGR_PATH_MAX_LEN];
        res = srv_phb_contact_set_video(contact, NULL);
        srv_phb_tcard_get_video(index, &(res->res_id), video_path, &res_type);
        if (res_type & SRV_PHB_RES_TYPE_VIDEO_FILE &&
            video_path[0])
         {
             if (srv_fmgr_fs_path_exist(res->res_path) == 0)
             {
                 res->res_id = (0x8000 + id);
                 mmi_wcscpy(res->res_path, video_path);
             }
         }
    }
    #endif

    #if defined(__MMI_PHB_INFO_FIELD__)
    if (contact_mask & MMI_PHB_CONTACT_FIELD_URL &&
        srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_URL))
    {
        srv_phb_contact_add_asc_url(contact, 0, 0, srv_phb_tcard_get_url(index));
    }

    if (contact_mask & MMI_PHB_CONTACT_FIELD_TITLE &&
        srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_TITLE))
    {
        srv_phb_contact_set_title(contact, srv_phb_tcard_get_title(index));
    }

    if (contact_mask & MMI_PHB_CONTACT_FIELD_NOTE &&
        srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_NOTE))
    {
        srv_phb_contact_add_note_ex(contact, 0, 0, srv_phb_tcard_get_note(index));
    }

    if ((contact_mask & MMI_PHB_CONTACT_FIELD_ADDRESS) &&
        srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_ADDRESS))
    {
        srv_phb_contact_add_address_ex(contact, 0, 0, srv_phb_tcard_get_address(index));
    }
    #endif
    
    #if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    if ((contact_mask & MMI_PHB_CONTACT_FIELD_BDAY) &&
        srv_phb_check_field_by_feild_filter(filter, MMI_PHB_CONTACT_FIELD_BDAY))
    {
        srv_phb_contact_set_bday(contact, srv_phb_tcard_get_birthday(index));
    }
    #endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_write_tcard_contact
 * DESCRIPTION
 *  update or add a new contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_write_tcard_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_PHB_NO_ERROR;
    U16 index = 0;
    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    srv_phb_tcard_op_cntx *op_cntx = srv_phb_mem_malloc(sizeof(srv_phb_tcard_op_cntx), SRV_PHB_MEMORY_TYPE_CTR);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(op_cntx, 0x00, sizeof(srv_phb_tcard_op_cntx));
    if ((cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_ADD || 
         cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_COPY) &&
         cntx->pos.index == SRV_PHB_INVALID_INDEX)
    {
        index = srv_phb_tcard_get_free_index();
        if (index == SRV_PHB_INVALID_INDEX)
        {
            result = SRV_PHB_STORAGE_FULL;
        }
        else
        {
            cntx->pos.index = (U16)(index);
        }
    }
    else
    {
        if (cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_ADD && srv_phb_tcard_get_field_mask(cntx->pos.index))
        {
            cntx->op_type = SRV_PHB_DATAMGR_OP_TYPE_UPD;
        }
        index = cntx->pos.index;
    }
    op_cntx->record_id = index;
    if (result == SRV_PHB_NO_ERROR)
    {
        srv_phb_tcard_res_path_struct *res_path = srv_phb_mem_malloc(sizeof(srv_phb_tcard_res_path_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(res_path, 0x00, sizeof(srv_phb_tcard_res_path_struct));
        op_cntx->data = srv_phb_mem_malloc(sizeof(srv_phb_tcard_data_struct), SRV_PHB_MEMORY_TYPE_ADM);
        memset(op_cntx->data, 0x00, sizeof(srv_phb_tcard_data_struct));
        srv_phb_tcard_malloc_info_cache(index);
        if (cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_UPD)
        {
            srv_phb_tcard_init_data_buffer(op_cntx->data, res_path, index);
        }
        if (cntx->update_field & MMI_PHB_TCARD_CONTACT_DATA_FIELD)
        {
            srv_phb_tcard_build_data_buffer(
                op_cntx->data,
                res_path,
                cntx->contact,
                cntx->update_field
                );
        }
        if (cntx->update_field & MMI_PHB_TCARD_CONTACT_INFO_FIELD)
        {
            op_cntx->info = srv_phb_mem_malloc(sizeof(srv_phb_tcard_info_struct), SRV_PHB_MEMORY_TYPE_ADM);
            memset(op_cntx->info, 0x00, sizeof(srv_phb_tcard_info_struct));
            op_cntx->data->field_mask = srv_phb_tcard_get_field_mask(index);
            if (cntx->op_type == SRV_PHB_DATAMGR_OP_TYPE_UPD)
            {
                srv_phb_tcard_init_info_buffer(op_cntx->info, index);
            }
            srv_phb_tcard_build_info_buffer(
                op_cntx->info,
                cntx->contact,
                cntx->update_field
                );
        }
        (op_cntx->data)->field_mask = srv_phb_tcard_build_field_mask(op_cntx->data, op_cntx->info, res_path);
        if (cntx->update_field & MMI_PHB_CONTACT_FIELD_RES)
        {
            srv_phb_tcard_write_res_path(res_path, index);
        }
        srv_phb_mem_free(res_path);
        
        if (cntx->update_field & MMI_PHB_TCARD_CONTACT_DATA_FIELD || srv_phb_tcard_is_field_mask_update(index, (op_cntx->data)->field_mask))
        {
            srv_phb_tcard_write_record(
                SRV_PHB_TCARD_DATA_FIELD,
                cntx->pos.index,
                1,
                (CHAR *)(op_cntx->data),
                srv_phb_tcard_write_data_field_cb,
                op_cntx);
            return;
        }
        else if (cntx->update_field & MMI_PHB_TCARD_CONTACT_INFO_FIELD)
        {
            srv_phb_tcard_write_record(
                SRV_PHB_TCARD_INFO_FIELD,
                cntx->pos.index,
                1,
                (CHAR *)(op_cntx->info),
                srv_phb_tcard_write_info_field_cb,
                op_cntx);
            return;
        }
    }
    op_cntx->result = result;
    srv_phb_async_event_interface(srv_phb_tcard_op_done, op_cntx);
    
}

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
void srv_phb_copy_tcard_contact(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_phb_datamgr_op_cntx_struct* cntx = srv_phb_datamgr_get_op_cntx();
    cntx->update_field = srv_phb_datamgr_get_field_mask(cntx->src_id);
    if (cntx->contact == NULL)
    {
        cntx->contact = srv_phb_create_contact(NULL);
    }
    srv_phb_datamgr_read_contact(cntx->src_id, cntx->contact, NULL);
    srv_phb_write_tcard_contact();
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_delete_tcard_contact
 * DESCRIPTION
 *  delete a contact
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_delete_tcard_contact(srv_phb_contact_pos_struct* pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_phb_tcard_op_cntx *op_cntx = srv_phb_mem_malloc(sizeof(srv_phb_tcard_op_cntx), SRV_PHB_MEMORY_TYPE_CTR);
    op_cntx->data = srv_phb_mem_malloc(sizeof(srv_phb_tcard_data_struct), SRV_PHB_MEMORY_TYPE_ADM);
    op_cntx->record_id = pos->index;
    op_cntx->info = NULL;
    op_cntx->result = 0;
    memset(op_cntx->data, 0x00, sizeof(srv_phb_tcard_data_struct));
    srv_phb_tcard_write_record(
        SRV_PHB_TCARD_DATA_FIELD,
        pos->index,
        1,
        (CHAR *)(op_cntx->data),
        srv_phb_tcard_delete_contact_cb,
        op_cntx);
}

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
void srv_phb_tcard_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_cb_reg_event(EVT_ID_SRV_TCARD_READY, srv_phb_tcard_on_tcard_ready, NULL);
    MMI_TRACE(SRV_PHB_TRACE_GROUP, TRC_SRV_PHB_TCARD_INIT, srv_tcard_query_app_stauts(SRV_TCARD_APP_INDEX_PHB));
    if (srv_tcard_query_app_stauts(SRV_TCARD_APP_INDEX_PHB) == MMI_TRUE)
    {
        srv_phb_tcard_init_start();
    }
}
#endif
