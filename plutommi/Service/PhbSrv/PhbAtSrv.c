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
 *  PhbAtSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements service functions for phb AT command handler.
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
#include "PhbSrvGprot.h"

#ifdef __MMI_PHB_ATCMD_SUPPORT__ 

#include "MMI_include.h"
#include "ProtocolEvents.h"
#include "FileMgrSrvGProt.h"
#include "PhbSrv.h"

#ifndef __COSMOS_MMI_PACKAGE__
#include "PhoneBookCore.h"
#endif

#ifdef __MMI_VCARD__
#include "vCard.h"
#include "vObjects.h"
#endif /* __MMI_VCARD__ */

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ps_public_struct.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "sim_common_enums.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_msg_struct.h"
#include "custom_phb_config.h"
#include "PhbSrvIprot.h"
#include "fs_errcode.h"
#include "mmi_frm_mem_gprot.h"
#include "fs_type.h"
#include "fs_func.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "Unicodexdcl.h"
#include "vcard_lib.h"
#include "string.h"
#include "ps_public_enum.h"

#ifdef __MMI_PHB_USIM_SUPPORT__
#include "GSM7BitDefaultAlphabet.h"
#endif
#include "app_usedetails.h"

#define SRV_PHB_AT_HANDLER

/* 
 * Define
 */
#define SRV_PHB_AT_VCARD_FIELD      (SRV_PHB_ENTRY_FIELD_OPT_NUM_1 |    \
                                     SRV_PHB_ENTRY_FIELD_OPT_NUM_2 |    \
                                     SRV_PHB_ENTRY_FIELD_OPT_NUM_3 |    \
                                     SRV_PHB_ENTRY_FIELD_EMAIL1 |       \
                                     SRV_PHB_ENTRY_FIELD_COMPANY |      \
                                     SRV_PHB_ENTRY_FIELD_BDAY)
#define SRV_PHB_AT_MOBILE_FIELD     (SRV_PHB_ENTRY_FIELD_NAME |         \
                                     SRV_PHB_ENTRY_FIELD_NUMBER)
#define SRV_PHB_AT_HOME_FIELD       (SRV_PHB_ENTRY_FIELD_OPT_NUM_1)
#define SRV_PHB_AT_WORKING_FIELD    (SRV_PHB_ENTRY_FIELD_OPT_NUM_2)
#define SRV_PHB_AT_FAX_FIELD        (SRV_PHB_ENTRY_FIELD_OPT_NUM_3)
#define SRV_PHB_AT_OTHERS_FIELD     (SRV_PHB_ENTRY_FIELD_NAME)

/* 
 * Typedef
 */
typedef enum
{
    SRV_PHB_AT_VCARD_WRITE_OP,      /* Write operation */
    SRV_PHB_AT_VCARD_READ_OP,       /* Read operation */
    SRV_PHB_AT_VCARD_QUERY_OP       /* Query operation */
} srv_phb_at_vcard_operation_enum;

typedef enum
{
    SRV_PHB_AT_MOBILE_NUMBER,       /* 'M' */
    SRV_PHB_AT_HOME_NUMBER,         /* 'H' */
    SRV_PHB_AT_WORKING_NUMBER,      /* 'W' */
    SRV_PHB_AT_FAX_NUMBER,          /* 'F' */
    SRV_PHB_AT_OTHERS_NUMBER        /* 'O' */
} srv_phb_at_number_category_enum;

typedef struct
{
    U8 sim_interface;
    U8 storage;
    U8 number_category;
    srv_phb_contact_info_struct *contact_p;
} srv_phb_at_phb_entry_struct;

/* 
 * Local Variable
 */
static U8 g_srv_phb_sim_interface;
static U8 g_srv_phb_src_id;
static U16 g_srv_phb_record_index;
static U16 *g_srv_phb_name;
static U16 *g_srv_phb_number;

#ifdef __MMI_PHB_USIM_SUPPORT__
static U8 g_srv_phb_cur_occur;
#endif

static const U32 g_srv_phb_number_field[] =
{
    SRV_PHB_AT_MOBILE_FIELD,
    SRV_PHB_AT_HOME_FIELD,
    SRV_PHB_AT_WORKING_FIELD,
    SRV_PHB_AT_FAX_FIELD,
    SRV_PHB_AT_OTHERS_FIELD
};

static const U32 g_srv_phb_number_field2[] =
{
    SRV_PHB_ENTRY_FIELD_NUMBER,
    SRV_PHB_ENTRY_FIELD_OPT_NUM_1,
    SRV_PHB_ENTRY_FIELD_OPT_NUM_2,
    SRV_PHB_ENTRY_FIELD_OPT_NUM_3,
    0
};

/* 
 * Local Function
 */
static void srv_phb_at_vcard_req_ind(void *info);
static void srv_phb_at_send_vcard_res_req(U8 mode, MMI_BOOL result, U8 *file_path);

#ifdef __MMI_VCARD__
static void srv_phb_at_vcard_update_contact(U16 store_index, srv_phb_contact_info_struct *contact_p);
static void srv_phb_at_vcard_update_contact_hdlr(S32 result, U16 store_index, void *user_data);
static MMI_BOOL srv_phb_at_parse_vcard(U8 *file_path, srv_phb_contact_info_struct *contact_p);
static MMI_BOOL srv_phb_at_build_vcard(U8 *file_path, srv_phb_contact_info_struct *contact_p);
static MMI_BOOL srv_phb_at_vcard_read_contact(U16 store_index, srv_phb_contact_info_struct *contact_p);
#endif /* __MMI_VCARD__ */

static void srv_phb_at_read_phb_req_ind(U8 sim_interface, void *info);
static void srv_phb_at_send_read_phb_res_req(
                U8 sim_interface,
                U8 storage,
                U8 type,
                U16 record_index,
                U8 result,
                U16 cause,
                l4c_phb_entry_struct *sim_entry);
static MMI_BOOL srv_phb_at_convert_number_category(U16 record_index, U8 *category_p);
static void srv_phb_at_read_phb(U16 result, l4c_phb_entry_struct *sim_entry);
static MMI_BOOL srv_phb_at_read_contact(U16 store_index, srv_phb_contact_info_struct *contact_p);

static void srv_phb_at_write_phb_req_ind(U8 sim_interface, void *info);
static void srv_phb_at_send_write_phb_res_req(U8 sim_interface, U16 record_index, U8 num_index, U8 result, U16 cause);

static void srv_phb_at_write_phb(U16 result);
static void srv_phb_at_add_contact(U8 sim_interface, U8 storage, U16 record_index, srv_phb_contact_info_struct *contact_p);
static void srv_phb_at_add_contact_hdlr(S32 result, U16 store_index, void *user_data);
static void srv_phb_at_update_contact(U8 sim_interface, U16 store_index, U8 number_category, srv_phb_contact_info_struct *contact_p);
static void srv_phb_at_update_contact_hdlr(S32 result, U16 store_index, void *user_data);

static void srv_phb_at_delete_phb_req_ind(U8 sim_interface, void *info);
static void srv_phb_at_send_delete_phb_res_req(U8 sim_interface, U16 record_index, U8 result, U16 cause);

static void srv_phb_at_delete_phb(U16 result);
static void srv_phb_at_delete_number(U8 sim_interface, U16 store_index, U8 number_category, srv_phb_contact_info_struct *contact_p);
static void srv_phb_at_delete_number_hdlr(S32 result, U16 store_index, void *user_data);
static void srv_phb_at_delete_contact(U8 sim_interface, U16 store_index, srv_phb_contact_info_struct *contact_p);
static void srv_phb_at_delete_contact_hdlr(S32 result, U16 store_index, void *user_data);

static void srv_phb_at_delete_all_contact(U8 sim_interface, U8 storage);
static void srv_phb_at_delete_all_contact_hdlr(U16 finish_count, U16 total_count, void *user_data);

static void srv_phb_at_sim_read_phb_req_ind(void *info, int mod_src);
static void srv_phb_at_sim_write_phb_req_ind(void *info, int mod_src);
static void srv_phb_at_sim_delete_phb_req_ind(void *info, int mod_src);

#ifdef __MMI_PHB_USIM_SUPPORT__
static void srv_phb_at_usim_read_additional_req_ind(void *info, int mod_src);
static void srv_phb_at_usim_write_additional_req_ind(void *info, int mod_src);
static void srv_phb_at_usim_delete_additional_req_ind(void *info, int mod_src);
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_at_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* AT+EVCARD */
    SetProtocolEventHandler(srv_phb_at_vcard_req_ind, PRT_PHB_VCARD_REQ_IND);

    /* AT+CPBR, AT+CPBW */
    SetProtocolEventHandler(srv_phb_at_sim_read_phb_req_ind, PRT_READ_PHB_REQ_IND);
    SetProtocolEventHandler(srv_phb_at_sim_write_phb_req_ind, PRT_WRITE_PHB_REQ_IND);
    SetProtocolEventHandler(srv_phb_at_sim_delete_phb_req_ind, PRT_DELETE_PHB_REQ_IND);
    
#ifdef __MMI_PHB_USIM_SUPPORT__
    SetProtocolEventHandler(srv_phb_at_usim_read_additional_req_ind, MSG_ID_MMI_L4C_READ_ADDITIONAL_REQ_IND);
    SetProtocolEventHandler(srv_phb_at_usim_write_additional_req_ind, MSG_ID_MMI_L4C_WRITE_ADDITIONAL_REQ_IND);
    SetProtocolEventHandler(srv_phb_at_usim_delete_additional_req_ind, MSG_ID_MMI_L4C_DELETE_ADDITIONAL_REQ_IND);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_sim1_sim2_read_phb_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 *  mod_src     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_sim_read_phb_req_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sim_interface = srv_phb_get_sim_id_by_mod_id(mod_src);
    srv_phb_at_read_phb_req_ind(g_srv_phb_sim_interface, info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_sim1_sim2_write_phb_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 *  mod_src     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_sim_write_phb_req_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sim_interface = srv_phb_get_sim_id_by_mod_id(mod_src);
    srv_phb_at_write_phb_req_ind(g_srv_phb_sim_interface, info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_sim1_sim2_delete_phb_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 *  mod_src     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_sim_delete_phb_req_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sim_interface = srv_phb_get_sim_id_by_mod_id(mod_src);
    srv_phb_at_delete_phb_req_ind(g_srv_phb_sim_interface, info);
}

#define SRV_PHB_AT_EVCARD


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_vcard_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_vcard_req_ind(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_vcard_req_ind_struct *local_ptr;
    U16 store_index;
#ifdef __MMI_VCARD__
    srv_phb_contact_info_struct *contact_p;
    U8 *file_path;
#endif /* __MMI_VCARD__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_eq_vcard_req_ind_struct*) info;

    store_index = local_ptr->index - 1; /* 1-based */
    if (store_index >= MMI_PHB_PHONE_ENTRIES)
    {
        srv_phb_at_send_vcard_res_req(local_ptr->mode, MMI_FALSE, NULL);
        return;
    }

#ifdef __MMI_VCARD__
    if (local_ptr->mode == SRV_PHB_AT_VCARD_WRITE_OP)   /* write */
    {
        if (!srv_phb_startup_is_phb_ready())
        {
            srv_phb_at_send_vcard_res_req(SRV_PHB_AT_VCARD_WRITE_OP, MMI_FALSE, NULL);
            return;
        }

        /* ALLOCATE buffer here for pending vcard data retrieval */
        contact_p = srv_phb_field_malloc(SRV_PHB_AT_VCARD_FIELD);

        if (!srv_phb_at_parse_vcard(local_ptr->file_path, contact_p))
        {
            srv_phb_at_send_vcard_res_req(SRV_PHB_AT_VCARD_WRITE_OP, MMI_FALSE, NULL);
            srv_phb_field_free(SRV_PHB_AT_VCARD_FIELD, contact_p);
            return;
        }

        /* Check number validality */
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        if (!srv_phb_check_valid_number(contact_p->field_data.opt_num[0]->number) ||
            !srv_phb_check_valid_number(contact_p->field_data.opt_num[1]->number) ||
            !srv_phb_check_valid_number(contact_p->field_data.opt_num[2]->number))
        {
            srv_phb_at_send_vcard_res_req(SRV_PHB_AT_VCARD_WRITE_OP, MMI_FALSE, NULL);
            srv_phb_field_free(SRV_PHB_AT_VCARD_FIELD, contact_p);
            return;
        }
    #endif /* __MMI_PHB_OPTIONAL_FIELD__ */

        /* RELEASE buffer at Op-lib callback handler */
        srv_phb_at_vcard_update_contact(store_index, contact_p);
    }
    else if (local_ptr->mode == SRV_PHB_AT_VCARD_READ_OP)   /* read */
    {
        /* ALLOCATE buffer here for pending contact info retrieval */
        contact_p = srv_phb_field_malloc(SRV_PHB_ENTRY_FIELD_SIM | SRV_PHB_AT_VCARD_FIELD);

        if (!srv_phb_at_vcard_read_contact(store_index, contact_p))
        {
            srv_phb_at_send_vcard_res_req(SRV_PHB_AT_VCARD_READ_OP, MMI_FALSE, NULL);
            srv_phb_field_free(SRV_PHB_ENTRY_FIELD_SIM | SRV_PHB_AT_VCARD_FIELD, contact_p);
            return;
        }

        file_path = OslMalloc(50);
        kal_wsprintf((U16*) file_path, "%c:\\~vcard_r.vcf", SRV_FMGR_PUBLIC_DRV);

        if (!srv_phb_at_build_vcard(file_path, contact_p))
        {
            srv_phb_at_send_vcard_res_req(SRV_PHB_AT_VCARD_READ_OP, MMI_FALSE, NULL);
            srv_phb_field_free(SRV_PHB_ENTRY_FIELD_SIM | SRV_PHB_AT_VCARD_FIELD, contact_p);
            OslMfree(file_path);
            return;
        }

        /* RELEASE buffer */
        srv_phb_at_send_vcard_res_req(SRV_PHB_AT_VCARD_READ_OP, MMI_TRUE, file_path);
        srv_phb_field_free(SRV_PHB_ENTRY_FIELD_SIM | SRV_PHB_AT_VCARD_FIELD, contact_p);
        OslMfree(file_path);
    }
    else if (local_ptr->mode == SRV_PHB_AT_VCARD_QUERY_OP)  /* query */
    {
        srv_phb_at_send_vcard_res_req(local_ptr->mode, MMI_TRUE, NULL);
    }
    else
    {
        srv_phb_at_send_vcard_res_req(local_ptr->mode, MMI_FALSE, NULL);
    }
#else /* __MMI_VCARD__ */
    srv_phb_at_send_vcard_res_req(local_ptr->mode, MMI_FALSE, NULL);
#endif /* __MMI_VCARD__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_send_vcard_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mode            [IN]        
 *  result          [IN]        
 *  file_path       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_send_vcard_res_req(U8 mode, MMI_BOOL result, U8 *file_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_vcard_res_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_eq_vcard_res_req_struct*) OslConstructDataPtr(sizeof(mmi_eq_vcard_res_req_struct));
    local_ptr->mode = mode;
    local_ptr->result = result;

    /* When file_path is passed as NULL, then it is not necessary to fill in this field. */
    if (file_path)
    {
        mmi_ucs2cpy((CHAR*) local_ptr->file_path, (CHAR*) file_path);
    }

    mmi_frm_send_ilm(MOD_L4C, PRT_PHB_VCARD_RES_REQ, (oslParaType*) local_ptr, NULL);
}

#ifdef __MMI_VCARD__


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_parse_vcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [?]     
 *  contact_p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_at_parse_vcard(U8 *file_path, srv_phb_contact_info_struct *contact_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VP_HANDLE vp;
    vcard_object_struct *object_p;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vp = vcard_open_parser(
            (U16*) file_path,
            (vcard_property_enum)(VCARD_PROPERTY_N | VCARD_PROPERTY_BDAY | VCARD_PROPERTY_TEL | VCARD_PROPERTY_EMAIL | VCARD_PROPERTY_ORG),
            NULL);
    if (!vp)
    {
        return MMI_FALSE;
    }

    vcard_set_parse_mode(vp, VCARD_PARSE_MODE_TEL_ALWAYS);

    result = vcard_parse(vp, &object_p);
    if (result == VCARD_RESULT_FAIL)
    {
        vcard_close_parser(vp);
        return MMI_FALSE;
    }

    srv_phb_convert_from_vcard_object(contact_p, object_p);

    vcard_close_parser(vp);
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_vcard_update_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  contact_p       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_vcard_update_contact(U16 store_index, srv_phb_contact_info_struct *contact_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_oplib_update_contact(store_index, contact_p, srv_phb_at_vcard_update_contact_hdlr, contact_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_vcard_update_contact_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_vcard_update_contact_hdlr(S32 result, U16 store_index, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_at_send_vcard_res_req(SRV_PHB_AT_VCARD_WRITE_OP, (result == SRV_PHB_NO_ERROR) ? MMI_TRUE : MMI_FALSE, NULL);
    srv_phb_field_free(SRV_PHB_AT_VCARD_FIELD, (srv_phb_contact_info_struct*) user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_vcard_read_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  contact_p       [?]         
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_at_vcard_read_contact(U16 store_index, srv_phb_contact_info_struct *contact_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_oplib_get_contact_info(store_index, contact_p) == SRV_PHB_NO_ERROR)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_build_vcard
 * DESCRIPTION
 *  
 * PARAMETERS
 *  file_path       [?]     
 *  contact_p       [?]     
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_at_build_vcard(U8 *file_path, srv_phb_contact_info_struct *contact_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VB_HANDLE vb;
    vcard_object_struct object;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vb = vcard_open_builder((U16*) file_path, VCARD_OPEN_MODE_DEFAULT, NULL);
    if (!vb)
    {
        return MMI_FALSE;
    }

    memset(&object, 0, sizeof(vcard_object_struct));
    srv_phb_convert_to_vcard_object(contact_p, &object);

    vcard_set_build_mode(vb, VCARD_BUILD_MODE_TEL_ALWAYS);

    result = vcard_build(vb, &object);
    if (result == VCARD_RESULT_FAIL)
    {
        vcard_close_builder(vb);
        return MMI_FALSE;
    }

    vcard_close_builder(vb);
    return MMI_TRUE;
}

#endif /* __MMI_VCARD__ */

#define SRV_PHB_AT_CPBR_READ_OP


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_read_phb_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  info                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_read_phb_req_ind(U8 sim_interface, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 type;
    U8 result = L4C_OK;
    U8 storage;
    U8 sim_id = 0;
    U8 num_index = 0;
    U8 number_category;
    U16 cause = PHB_NO_CAUSE;
    U16 *number;
    U16 *last_name;
    U16 store_index;
    l4c_phb_entry_struct sim_entry;
    l4c_phb_entry_struct *p_sim_entry = NULL;
    srv_phb_contact_info_struct *contact_p = NULL;
    mmi_l4c_read_phb_req_ind_struct *local_ptr;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_l4c_read_phb_req_ind_struct*) info;

    MMI_ASSERT(local_ptr != NULL);
    storage = local_ptr->storage;
    type = local_ptr->type;
    g_srv_phb_src_id = local_ptr->src_id;
    if (!srv_phb_startup_is_phb_ready())
    {
        result = L4C_ERROR;
    }

    if (result == L4C_OK)
    {
        if (local_ptr->type >= PHB_ECC && local_ptr->type <= PHB_SDN)
    {
        if ((storage != PHB_STORAGE_NVRAM && sim_interface != srv_phb_get_sim_id((phb_storage_enum)storage))||
            !srv_phb_startup_is_phb_support(sim_interface, local_ptr->type) ||
            !srv_phb_xmgnt_get_entry(sim_interface, local_ptr->type, local_ptr->record_index, srv_phb_at_read_phb))
        {
            result = L4C_ERROR;
        }
            else
            {
                return;
    }
    }
        else
    {
    store_index = local_ptr->record_index - 1;  /* 1-based */
        if (storage == PHB_STORAGE_SIM ||
            storage == PHB_STORAGE_SIM2 ||
            storage == PHB_STORAGE_SIM3 ||
            storage == PHB_STORAGE_SIM4)
    {
        number_category = local_ptr->num_index;
        /* Check SIM record index range, 1 ~ MMI_PHB_SIM_ENTRIES */
        if (store_index >= MMI_PHB_SIM_ENTRIES)
        {
                result = L4C_ERROR;
                type = PHB_PHONEBOOK;
        }
            else
            {
                sim_id = srv_phb_get_sim_id((phb_storage_enum)storage);
        store_index += MMI_PHB_PHONE_ENTRIES + MMI_PHB_SIM_ENTRIES * sim_id;
    }
        }
    else
    {
        /* Check NVRAM record index range, 1 ~ 4 * MMI_PHB_PHONE_ENTRIES for AT extension */
        /* Calculate number category */
        if (!srv_phb_at_convert_number_category(local_ptr->record_index, &number_category))
        {
                result = L4C_ERROR;
                storage = PHB_STORAGE_NVRAM;
                type = PHB_PHONEBOOK;
            }
        }
    }
    }
    if (result == L4C_OK)
    {
    contact_p = srv_phb_field_malloc(g_srv_phb_number_field[number_category]);
        if (srv_phb_at_read_contact(store_index, contact_p))
    {
    switch (number_category)
    {
        case SRV_PHB_AT_MOBILE_NUMBER:
                    num_index = 0;
            break;
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case SRV_PHB_AT_HOME_NUMBER:
                    num_index = 1;
                    break;
                case SRV_PHB_AT_WORKING_NUMBER:
                    num_index = 2;
                    break;
                case SRV_PHB_AT_FAX_NUMBER:
                    num_index = 3;
                    break;
                #endif /* __MMI_PHB_OPTIONAL_FIELD__ */
                default:
                    MMI_ASSERT(0);
                    break;
            }
            sim_entry.aas_id = 0xFF;
            if (num_index > 0)
            {
                if (contact_p->field_data.opt_num[num_index - 1]->type > MMI_PHB_NUM_TYPE_MOBILE)
                {
                    sim_entry.aas_id = contact_p->field_data.opt_num[num_index - 1]->type - MMI_PHB_NUM_TYPE_MOBILE;
                }
                number = contact_p->field_data.opt_num[num_index - 1]->number;
            }
            else
            {
                number = contact_p->field_data.number;
            }
            #if defined(__MMI_PHB_LAST_NAME_FIELD__)
            last_name = contact_p->field_data.l_name;
            #else
            last_name = NULL;
            #endif
            srv_phb_build_l4phb_entry(
                &sim_entry,
                contact_p->field_data.name,
                last_name,
                number);
            sim_entry.num_index = num_index;
            result = L4C_OK;
            type = PHB_PHONEBOOK;
            p_sim_entry = &sim_entry;
            }
            else
            {
            result = L4C_ERROR;
            cause = PHB_ERRNO_READ_EMPTY;
            type = PHB_PHONEBOOK;
            }
    }

    srv_phb_at_send_read_phb_res_req(
        sim_interface,
        storage,
        type,
        local_ptr->record_index,
        result,
        cause,
        p_sim_entry);
    
    if (contact_p != NULL)
    {
    srv_phb_field_free(g_srv_phb_number_field[number_category], contact_p);
}
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_send_read_phb_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  storage             [IN]        
 *  type                [IN]        
 *  record_index        [IN]        
 *  result              [IN]        
 *  cause               [IN]        
 *  sim_entry           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_send_read_phb_res_req(
                U8 sim_interface,
                U8 storage,
                U8 type,
                U16 record_index,
                U8 result,
                U16 cause,
                l4c_phb_entry_struct *sim_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_read_phb_res_req_struct *local_ptr;
    oslModuleType dest_mod = MOD_L4C;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_l4c_read_phb_res_req_struct*) OslConstructDataPtr(sizeof(mmi_l4c_read_phb_res_req_struct));
    local_ptr->phb_src = g_srv_phb_src_id;
    local_ptr->result.flag = result;
    local_ptr->result.cause = cause;

    if (result == L4C_OK)
    {
        if (sim_entry != NULL)
        {
            memcpy(&local_ptr->entry, sim_entry, sizeof(l4c_phb_entry_struct));
        }

        local_ptr->entry.storage = storage;
        local_ptr->entry.type = type;
        local_ptr->entry.index = record_index;
        local_ptr->entry.record_index = record_index;
    }

    dest_mod = mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_interface));
    mmi_frm_send_ilm(dest_mod, PRT_READ_PHB_RES_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_convert_number_category
 * DESCRIPTION
 *  
 * PARAMETERS
 *  record_index    [IN]        
 *  category_p      [?]         
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_at_convert_number_category(U16 record_index, U8 *category_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (record_index <= MMI_PHB_PHONE_ENTRIES)
    {
        *category_p = SRV_PHB_AT_MOBILE_NUMBER;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    else if (record_index <= 2 * MMI_PHB_PHONE_ENTRIES)
    {
        *category_p = SRV_PHB_AT_HOME_NUMBER;
    }
    else if (record_index <= 3 * MMI_PHB_PHONE_ENTRIES)
    {
        *category_p = SRV_PHB_AT_WORKING_NUMBER;
    }
    else if (record_index <= 4 * MMI_PHB_PHONE_ENTRIES)
    {
        *category_p = SRV_PHB_AT_FAX_NUMBER;
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */
    else
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_read_phb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  sim_entry       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_read_phb(U16 result, l4c_phb_entry_struct *sim_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_at_send_read_phb_res_req(
        g_srv_phb_sim_interface,
        sim_entry->storage,
        sim_entry->type,
        sim_entry->record_index,
        (U8) ((result == SRV_PHB_XMGNT_RESULT_OK) ? L4C_OK : L4C_ERROR),
        PHB_NO_CAUSE,
        sim_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_read_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  store_index     [IN]        
 *  contact_p       [?]         
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_phb_at_read_contact(U16 store_index, srv_phb_contact_info_struct *contact_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_oplib_get_contact_info(store_index, contact_p) == SRV_PHB_NO_ERROR)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

#define SRV_PHB_AT_CPBW_WRITE_OP


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_write_phb_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  info                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_write_phb_req_ind(U8 sim_interface, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_write_phb_req_ind_struct *local_ptr;
    U16 store_index;
    srv_phb_contact_info_struct *contact_p;
    U8 number_category;
    U8 sim_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_l4c_write_phb_req_ind_struct*) info;

    MMI_ASSERT(local_ptr != NULL);
    g_srv_phb_src_id = local_ptr->src_id;
    g_srv_phb_record_index = local_ptr->entry.record_index;

    if (!srv_phb_startup_is_phb_ready())
    {
        srv_phb_at_send_write_phb_res_req(sim_interface, local_ptr->entry.record_index, local_ptr->entry.num_index, L4C_ERROR, PHB_NO_CAUSE);
        return;
    }

    if (local_ptr->entry.type >= PHB_ECC && local_ptr->entry.type <= PHB_SDN)
    {
        if (!((sim_interface == SIM1 && local_ptr->entry.storage == PHB_STORAGE_SIM) ||
              (sim_interface == SIM2 && local_ptr->entry.storage == PHB_STORAGE_SIM2) ||
              (sim_interface == SIM3 && local_ptr->entry.storage == PHB_STORAGE_SIM3) ||
              (sim_interface == SIM4 && local_ptr->entry.storage == PHB_STORAGE_SIM4)) ||
            !srv_phb_startup_is_phb_support(sim_interface, local_ptr->entry.type))
        {
            srv_phb_at_send_write_phb_res_req(sim_interface, local_ptr->entry.record_index, local_ptr->entry.num_index, L4C_ERROR, PHB_NO_CAUSE);
            return;
        }

        g_srv_phb_name = srv_phb_mem_malloc((MMI_PHB_NAME_FIELD_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);
        g_srv_phb_number = srv_phb_mem_malloc((MMI_PHB_NUMBER_PLUS_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);
        srv_phb_parse_l4phb_entry(&local_ptr->entry, g_srv_phb_name, NULL, g_srv_phb_number);
        
        #ifndef __COSMOS_MMI_PACKAGE__
        if (local_ptr->entry.index == 0xFFFF && local_ptr->entry.record_index == 0xFFFF)
        {
            mmi_phb_cntx_mgr_at(MMI_PHB_OP_ADD);
        }
        else
        {
            mmi_phb_cntx_mgr_at(MMI_PHB_OP_EDIT);
        }
        #endif

        if (!srv_phb_xmgnt_set_entry(
                sim_interface,
                local_ptr->entry.type,
                local_ptr->entry.index,
                local_ptr->entry.record_index,
                g_srv_phb_name,
                g_srv_phb_number,
                srv_phb_at_write_phb))
        {
            srv_phb_at_send_write_phb_res_req(sim_interface, local_ptr->entry.record_index, local_ptr->entry.num_index, L4C_ERROR, PHB_NO_CAUSE);
            srv_phb_mem_free(g_srv_phb_name);
            srv_phb_mem_free(g_srv_phb_number);
        }
        return;
    }

    //MMI_ASSERT(local_ptr->entry.type == PHB_PHONEBOOK);

    store_index = local_ptr->entry.record_index - 1;    /* 1-based */
    if (local_ptr->entry.storage == PHB_STORAGE_SIM ||
        local_ptr->entry.storage == PHB_STORAGE_SIM2 ||
        local_ptr->entry.storage == PHB_STORAGE_SIM3 ||
        local_ptr->entry.storage == PHB_STORAGE_SIM4)
    {
        number_category = local_ptr->entry.num_index;

        if (local_ptr->entry.record_index == 0xFFFF)
        {
            /* Don't check SIM record index */
        }
        else
        {
            /* Check SIM record index range, 1 ~ MMI_PHB_SIM_ENTRIES */
            if (store_index >= MMI_PHB_SIM_ENTRIES)
            {
                srv_phb_at_send_write_phb_res_req(
                    sim_interface,
                    local_ptr->entry.record_index,
                    local_ptr->entry.num_index,
                    L4C_ERROR,
                    PHB_NO_CAUSE);
                return;
            }
            sim_id = srv_phb_get_sim_id((phb_storage_enum)local_ptr->entry.storage);
            store_index += MMI_PHB_PHONE_ENTRIES + MMI_PHB_SIM_ENTRIES * sim_id;
        }
    }
    else
    {
        if (local_ptr->entry.record_index == 0xFFFF)
        {
            /* Don't check NVRAM record index */
            number_category = SRV_PHB_AT_MOBILE_NUMBER;
        }
        else
        {
            /* Check NVRAM record index range, 1 ~ 4 * MMI_PHB_PHONE_ENTRIES for AT extension */
            /* Calculate number category */
            if (!srv_phb_at_convert_number_category(local_ptr->entry.record_index, &number_category))
            {
                srv_phb_at_send_write_phb_res_req(
                    sim_interface,
                    local_ptr->entry.record_index,
                    local_ptr->entry.num_index,
                    L4C_ERROR,
                    PHB_NO_CAUSE);
                return;
            }
        }
    }

    /* ALLOCATE buffer here for pending contact info saving */
    contact_p = srv_phb_field_malloc(g_srv_phb_number_field[number_category]);

    if (number_category == SRV_PHB_AT_MOBILE_NUMBER)
    {
        srv_phb_parse_l4phb_entry(
            &local_ptr->entry,
            contact_p->field_data.name,
        #if defined(__MMI_PHB_LAST_NAME_FIELD__)
            contact_p->field_data.l_name,
        #else
            NULL,
        #endif
            contact_p->field_data.number);
    }
    else
    {
        mmi_phb_wcs_num_struct* number = contact_p->field_data.opt_num[local_ptr->entry.num_index - 1];

        if (local_ptr->entry.tel.type == SRV_PHB_NUMBER_TYPE_INTERNATIONAL)
        {
            U8 decode_num[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
            /* now number is +**21*8123456# */
            /* call the applib decode API to transfer + to place just after SS pattern */
            applib_decode_number(local_ptr->entry.tel.number, decode_num, 0x91);
            /* now number is **21*+8123456#, so we can show the original data to user */
            mmi_asc_to_wcs(number->number, (CHAR*)decode_num);
        }
        else
        {
            mmi_asc_to_wcs(number->number, (CHAR*)local_ptr->entry.tel.number);
        }
    
        if (local_ptr->entry.aas_id != 0xff)
        {
            number->type = (mmi_phb_num_type_enum)(local_ptr->entry.aas_id + MMI_PHB_NUM_TYPE_MOBILE);
        }
        else
        {
            number->type = MMI_PHB_NUM_TYPE_MOBILE;
        }
    }

    if (local_ptr->entry.record_index == 0xFFFF || !srv_phb_datamgr_check_store_index(store_index, MMI_PHB_CONTACT_FIELD_SIM))
    {
        srv_phb_at_add_contact(sim_interface, local_ptr->entry.storage, local_ptr->entry.record_index, contact_p);
    }
    else
    {
        srv_phb_at_update_contact(sim_interface, store_index, number_category, contact_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_send_write_phb_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  record_index        [IN]        
 *  result              [IN]        
 *  cause               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_send_write_phb_res_req(U8 sim_interface, U16 record_index, U8 num_index, U8 result, U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_write_phb_res_req_struct *local_ptr;
    oslModuleType dest_mod = MOD_L4C;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_l4c_write_phb_res_req_struct*) OslConstructDataPtr(sizeof(mmi_l4c_write_phb_res_req_struct));
    local_ptr->phb_src = g_srv_phb_src_id;
    local_ptr->result.flag = result;
    local_ptr->result.cause = cause;
    local_ptr->num_index = num_index;
    local_ptr->record_index = record_index;
    dest_mod = mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_interface));
    mmi_frm_send_ilm(dest_mod, PRT_WRITE_PHB_RES_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_write_phb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_write_phb(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_at_send_write_phb_res_req(
        g_srv_phb_sim_interface,
        g_srv_phb_record_index,
        0,
        (U8) ((result == SRV_PHB_XMGNT_RESULT_OK) ? L4C_OK : L4C_ERROR),
        (U16) ((result == SIM_CHV_RETRY_ALLOW) ? SIM_CHV_RETRY_ALLOW : PHB_NO_CAUSE));
    srv_phb_mem_free(g_srv_phb_name);
    srv_phb_mem_free(g_srv_phb_number);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_add_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  storage             [IN]        
 *  record_index        [IN]        
 *  contact_p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_add_contact(U8 sim_interface, U8 storage, U16 record_index, srv_phb_contact_info_struct *contact_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_at_phb_entry_struct *phb_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_entry = srv_phb_mem_malloc(sizeof(srv_phb_at_phb_entry_struct), SRV_PHB_MEMORY_TYPE_CTR);
    phb_entry->sim_interface = sim_interface;
    phb_entry->storage = storage;
    phb_entry->contact_p = contact_p;
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_phb_cntx_mgr_at(MMI_PHB_OP_ADD);
    #endif
    srv_phb_oplib_add_contact(storage, record_index, contact_p, srv_phb_at_add_contact_hdlr, phb_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_add_contact_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_add_contact_hdlr(S32 result, U16 store_index, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_at_phb_entry_struct *phb_entry;
    U8 storage;
    U16 record_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_entry = (srv_phb_at_phb_entry_struct*) user_data;

    srv_phb_store_index_to_record_index(store_index, &storage, &record_index);
    srv_phb_at_send_write_phb_res_req(
        phb_entry->sim_interface,
        (g_srv_phb_record_index == 0xFFFF) ? record_index : g_srv_phb_record_index,
        0,
        (U8) ((result == SRV_PHB_NO_ERROR) ? L4C_OK : L4C_ERROR),
        (U16) ((srv_phb_get_used_contact(phb_entry->storage) ==
            srv_phb_get_total_contact(phb_entry->storage)) ? PHB_CAUSE_STORAGE_FULL : PHB_NO_CAUSE));

    srv_phb_field_free(SRV_PHB_AT_MOBILE_FIELD, phb_entry->contact_p);
    srv_phb_mem_free(phb_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_update_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  store_index         [IN]        
 *  number_category     [IN]        
 *  contact_p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_update_contact(U8 sim_interface, U16 store_index, U8 number_category, srv_phb_contact_info_struct *contact_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_at_phb_entry_struct *phb_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_entry = srv_phb_mem_malloc(sizeof(srv_phb_at_phb_entry_struct), SRV_PHB_MEMORY_TYPE_CTR);
    phb_entry->sim_interface = sim_interface;
    phb_entry->number_category = number_category;
    phb_entry->contact_p = contact_p;
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_phb_cntx_mgr_at(MMI_PHB_OP_EDIT);
    #endif
    srv_phb_oplib_update_contact(store_index, contact_p, srv_phb_at_update_contact_hdlr, phb_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_update_contact_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_update_contact_hdlr(S32 result, U16 store_index, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_at_phb_entry_struct *phb_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_entry = (srv_phb_at_phb_entry_struct*) user_data;

    srv_phb_at_send_write_phb_res_req(
        phb_entry->sim_interface,
        g_srv_phb_record_index,
        phb_entry->number_category,
        (U8) ((result == SRV_PHB_NO_ERROR) ? L4C_OK : L4C_ERROR),
        (U16) ((result == SRV_PHB_SIM_PARTIAL_ERROR) ? PHB_CAUSE_NOT_SUPPORT : PHB_NO_CAUSE));

    srv_phb_field_free(g_srv_phb_number_field[phb_entry->number_category], phb_entry->contact_p);
    srv_phb_mem_free(phb_entry);
}

#define SRV_PHB_AT_CPBW_DELETE_OP


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_delete_phb_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  info                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_delete_phb_req_ind(U8 sim_interface, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_delete_phb_req_ind_struct *local_ptr;
    U16 store_index;
    srv_phb_contact_info_struct *contact_p;
    U16 *name_p;
    U8 number_category;
    U8 sim_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_l4c_delete_phb_req_ind_struct*) info;

    MMI_ASSERT(local_ptr != NULL);
    g_srv_phb_src_id = local_ptr->src_id;
    g_srv_phb_record_index = local_ptr->record_index;

    if (!srv_phb_startup_is_phb_ready())
    {
        srv_phb_at_send_delete_phb_res_req(sim_interface, local_ptr->record_index, L4C_ERROR, PHB_NO_CAUSE);
        return;
    }

    if (local_ptr->type >= PHB_ECC && local_ptr->type <= PHB_SDN)
    {
        if (!((sim_interface == SIM1 && local_ptr->storage == PHB_STORAGE_SIM) ||
              (sim_interface == SIM2 && local_ptr->storage == PHB_STORAGE_SIM2) ||
              (sim_interface == SIM3 && local_ptr->storage == PHB_STORAGE_SIM3) ||
              (sim_interface == SIM4 && local_ptr->storage == PHB_STORAGE_SIM4)) ||
            !srv_phb_startup_is_phb_support(sim_interface, local_ptr->type))
        {
            srv_phb_at_send_delete_phb_res_req(sim_interface, local_ptr->record_index, L4C_ERROR, PHB_NO_CAUSE);
            return;
        }

        if (!srv_phb_xmgnt_delete_entry(sim_interface, local_ptr->type, 0xFFFF, local_ptr->record_index, srv_phb_at_delete_phb))
        {
            srv_phb_at_send_delete_phb_res_req(sim_interface, local_ptr->record_index, L4C_ERROR, PHB_NO_CAUSE);
        }
        return;
    }

    //MMI_ASSERT(local_ptr->type == PHB_PHONEBOOK);

    store_index = local_ptr->record_index - 1;  /* 1-based */
    if (local_ptr->storage == PHB_STORAGE_SIM ||
        local_ptr->storage == PHB_STORAGE_SIM2 ||
        local_ptr->storage == PHB_STORAGE_SIM3 ||
        local_ptr->storage == PHB_STORAGE_SIM4)
    {
        number_category = local_ptr->num_index;

        if (local_ptr->record_index == 0xFFFF)
        {
            /* Don't check SIM record index */
        }
        else
        {
            /* Check SIM record index range, 1 ~ MMI_PHB_SIM_ENTRIES */
            if (store_index >= MMI_PHB_SIM_ENTRIES)
            {
                srv_phb_at_send_delete_phb_res_req(sim_interface, local_ptr->record_index, L4C_ERROR, PHB_NO_CAUSE);
                return;
            }
            sim_id = srv_phb_get_sim_id((phb_storage_enum)local_ptr->storage);
            store_index += MMI_PHB_PHONE_ENTRIES + MMI_PHB_SIM_ENTRIES * sim_id;
        }
    }
    else
    {
        if (local_ptr->record_index == 0xFFFF)
        {
            /* Don't check NVRAM record index */
            number_category = SRV_PHB_AT_MOBILE_NUMBER;
        }
        else
        {
            /* Check NVRAM record index range, 1 ~ 4 * MMI_PHB_PHONE_ENTRIES for AT extension */
            /* Calculate number category */
            if (!srv_phb_at_convert_number_category(local_ptr->record_index, &number_category))
            {
                srv_phb_at_send_delete_phb_res_req(sim_interface, local_ptr->record_index, L4C_ERROR, PHB_NO_CAUSE);
                return;
            }
        }
    }

    if (local_ptr->record_index == 0xFFFF)
    {
        srv_phb_at_delete_all_contact(sim_interface, local_ptr->storage);
    }
    else
    {
        if (!srv_phb_check_entry_exist(store_index))
        {
            srv_phb_at_send_delete_phb_res_req(sim_interface, local_ptr->record_index, L4C_ERROR, PHB_NO_CAUSE);
            return;
        }

        /* ALLOCATE buffer here for pending contact number deleting */
        contact_p = srv_phb_field_malloc(g_srv_phb_number_field2[number_category]);
        name_p = srv_phb_mem_malloc((MMI_PHB_NAME_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);

        if (!srv_phb_get_name(store_index, name_p, MMI_PHB_NAME_LENGTH))
        {
            srv_phb_at_send_delete_phb_res_req(sim_interface, local_ptr->record_index, L4C_ERROR, PHB_NO_CAUSE);
            srv_phb_field_free(g_srv_phb_number_field2[number_category], contact_p);
            srv_phb_mem_free(name_p);
            return;
        }

        switch (number_category)
        {
            case SRV_PHB_AT_MOBILE_NUMBER:
                srv_phb_at_delete_contact(sim_interface, store_index, contact_p);
                srv_phb_field_free(g_srv_phb_number_field2[number_category], contact_p);
                srv_phb_mem_free(name_p);
                return;
                
        #ifdef __MMI_PHB_OPTIONAL_FIELD__
            case SRV_PHB_AT_HOME_NUMBER:
                contact_p->field_data.opt_num[0]->number[0] = 0;
                break;
            case SRV_PHB_AT_WORKING_NUMBER:
                contact_p->field_data.opt_num[1]->number[0] = 0;
                break;
            case SRV_PHB_AT_FAX_NUMBER:
                contact_p->field_data.opt_num[2]->number[0] = 0;
                break;
        #endif /* __MMI_PHB_OPTIONAL_FIELD__ */
            default:
                MMI_ASSERT(0);
                break;
        }

        srv_phb_at_delete_number(sim_interface, store_index, number_category, contact_p);
        srv_phb_mem_free(name_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_send_delete_phb_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  record_index        [IN]        
 *  result              [IN]        
 *  cause               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_send_delete_phb_res_req(U8 sim_interface, U16 record_index, U8 result, U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_delete_phb_res_req_struct *local_ptr;
    oslModuleType dest_mod = MOD_L4C;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_l4c_delete_phb_res_req_struct*) OslConstructDataPtr(sizeof(mmi_l4c_delete_phb_res_req_struct));
    local_ptr->phb_src = g_srv_phb_src_id;
    local_ptr->result.flag = result;
    local_ptr->result.cause = cause;
    local_ptr->record_index = record_index;
    dest_mod = mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_interface));
    mmi_frm_send_ilm(dest_mod, PRT_DELETE_PHB_RES_REQ, (oslParaType*) local_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_delete_phb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_delete_phb(U16 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result == SRV_PHB_XMGNT_RESULT_OK)
    {
        #ifndef __COSMOS_MMI_PACKAGE__
        mmi_phb_cntx_mgr_at(MMI_PHB_OP_DELETE);
        #endif
    }

    srv_phb_at_send_delete_phb_res_req(
        g_srv_phb_sim_interface,
        g_srv_phb_record_index,
        (U8) ((result == SRV_PHB_XMGNT_RESULT_OK) ? L4C_OK : L4C_ERROR),
        (U16) ((result == SIM_CHV_RETRY_ALLOW) ? SIM_CHV_RETRY_ALLOW : PHB_NO_CAUSE));
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_delete_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  store_index         [IN]        
 *  number_category     [IN]        
 *  contact_p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_delete_number(U8 sim_interface, U16 store_index, U8 number_category, srv_phb_contact_info_struct *contact_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_at_phb_entry_struct *phb_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_entry = srv_phb_mem_malloc(sizeof(srv_phb_at_phb_entry_struct), SRV_PHB_MEMORY_TYPE_CTR);
    phb_entry->sim_interface = sim_interface;
    phb_entry->number_category = number_category;
    phb_entry->contact_p = contact_p;
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_phb_cntx_mgr_at(MMI_PHB_OP_EDIT);
    #endif
    srv_phb_oplib_update_contact(store_index, contact_p, srv_phb_at_delete_number_hdlr, phb_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_delete_number_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_delete_number_hdlr(S32 result, U16 store_index, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_at_phb_entry_struct *phb_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_entry = (srv_phb_at_phb_entry_struct*) user_data;

    srv_phb_at_send_delete_phb_res_req(
        phb_entry->sim_interface,
        g_srv_phb_record_index,
        (U8) ((result == SRV_PHB_NO_ERROR) ? L4C_OK : L4C_ERROR),
        PHB_NO_CAUSE);

    srv_phb_field_free(g_srv_phb_number_field2[phb_entry->number_category], phb_entry->contact_p);
    srv_phb_mem_free(phb_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_delete_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  store_index         [IN]        
 *  contact_p           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_delete_contact(U8 sim_interface, U16 store_index, srv_phb_contact_info_struct *contact_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_at_phb_entry_struct *phb_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_entry = srv_phb_mem_malloc(sizeof(srv_phb_at_phb_entry_struct), SRV_PHB_MEMORY_TYPE_CTR);
    phb_entry->sim_interface = sim_interface;
    phb_entry->contact_p = contact_p;
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_phb_cntx_mgr_at(MMI_PHB_OP_DELETE);
    #endif
    srv_phb_oplib_delete_contact(store_index, srv_phb_at_delete_contact_hdlr, phb_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_delete_contact_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_delete_contact_hdlr(S32 result, U16 store_index, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_at_phb_entry_struct *phb_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_entry = (srv_phb_at_phb_entry_struct*) user_data;

    srv_phb_at_send_delete_phb_res_req(
        phb_entry->sim_interface,
        g_srv_phb_record_index,
        (U8) ((result == SRV_PHB_NO_ERROR) ? L4C_OK : L4C_ERROR),
        PHB_NO_CAUSE);

    srv_phb_mem_free(phb_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_delete_all_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  storage             [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_delete_all_contact(U8 sim_interface, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 user_data = sim_interface;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_phb_cntx_mgr_at(MMI_PHB_OP_DELETE_ALL);
    #endif
    srv_phb_oplib_delete_all_contact(storage, srv_phb_at_delete_all_contact_hdlr, (void*) user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_delete_all_contact_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  finish_count        [IN]        
 *  total_count         [IN]        
 *  user_data           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_delete_all_contact_hdlr(U16 finish_count, U16 total_count, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_at_send_delete_phb_res_req(
        (U8) (U32) user_data,
        0xFFFF,
        (U8) ((finish_count == total_count) ? L4C_OK : L4C_ERROR),
        PHB_NO_CAUSE);
}


#ifdef __MMI_PHB_USIM_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_send_read_additional_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  storage             [IN]        
 *  type                [IN]        
 *  record_index        [IN]        
 *  result              [IN]        
 *  cause               [IN]        
 *  sim_entry           [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_send_read_additional_res_req(
                U8 sim_interface,
                U8 storage,
                U8 type,
                U16 record_index,
                U8 result,
                U16 cause,
                l4c_phb_usim_entry *sim_entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_read_additional_res_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_l4c_read_additional_res_req_struct*) OslConstructDataPtr(sizeof(mmi_l4c_read_additional_res_req_struct));
    local_ptr->phb_src = g_srv_phb_src_id;
    local_ptr->result.flag = result;
    local_ptr->result.cause = cause;
    local_ptr->occurrence = g_srv_phb_cur_occur;
    local_ptr->storage = storage;
    local_ptr->type = type;
    local_ptr->record_index = record_index;

    if (result == L4C_OK)
    {
        if (sim_entry != NULL)
        {
            memcpy(&local_ptr->entry, sim_entry, sizeof(l4c_phb_usim_entry));
        }
    }
    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_interface)),
        MSG_ID_MMI_L4C_READ_ADDITIONAL_RES_REQ,
        (oslParaType *) local_ptr,
        NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_read_phb_additional_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  info                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_read_additional_req_ind(U8 sim_interface, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_read_additional_req_ind_struct *local_ptr;
    U16 store_index;
    srv_phb_contact_info_struct *contact_p;
    l4c_phb_usim_entry sim_entry;
    U8 sim_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_l4c_read_additional_req_ind_struct*) info;

    MMI_ASSERT(local_ptr != NULL);
    g_srv_phb_src_id = local_ptr->src_id;
    g_srv_phb_cur_occur = local_ptr->occurrence;

    if (!srv_phb_startup_is_phb_ready() || local_ptr->type != PHB_EMAIL)
    {
        srv_phb_at_send_read_additional_res_req(
            sim_interface,
            local_ptr->storage,
            local_ptr->type,
            local_ptr->record_index,
            L4C_ERROR,
            PHB_NO_CAUSE,
            NULL);
        return;
    }

    store_index = local_ptr->record_index - 1;  /* 1-based */
    if (local_ptr->storage == PHB_STORAGE_SIM ||
        local_ptr->storage == PHB_STORAGE_SIM2 ||
        local_ptr->storage == PHB_STORAGE_SIM3 ||
        local_ptr->storage == PHB_STORAGE_SIM4)
    {
        /* Check SIM record index range, 1 ~ MMI_PHB_SIM_ENTRIES */
        if (store_index >= MMI_PHB_SIM_ENTRIES ||
            g_srv_phb_cur_occur > srv_phb_get_support_field_count(PHB_STORAGE_SIM, MMI_PHB_CONTACT_FIELD_ID_EMAIL))
        {
            srv_phb_at_send_read_additional_res_req(
                sim_interface,
                local_ptr->storage,
                PHB_EMAIL,
                local_ptr->record_index,
                L4C_ERROR,
                PHB_NO_CAUSE,
                NULL);
            return;
        }
        sim_id = srv_phb_get_sim_id((phb_storage_enum)local_ptr->storage);
        store_index += MMI_PHB_PHONE_ENTRIES + MMI_PHB_SIM_ENTRIES * sim_id;
    }
    else
    {
        srv_phb_at_send_read_additional_res_req(
            sim_interface,
            local_ptr->storage,
            PHB_EMAIL,
            local_ptr->record_index,
            L4C_ERROR,
            PHB_NO_CAUSE,
            NULL);
        return;
    }

    /* ALLOCATE buffer here for pending contact info retrieval */
    contact_p = srv_phb_field_malloc(SRV_PHB_ENTRY_FIELD_EMAIL);

    if (!srv_phb_at_read_contact(store_index, contact_p))
    {
        srv_phb_at_send_read_additional_res_req(
            sim_interface,
            local_ptr->storage,
            PHB_EMAIL,
            local_ptr->record_index,
            L4C_ERROR,
            PHB_ERRNO_READ_EMPTY,
            NULL);
    }
    else
    {
        WCHAR* data;
        if (g_srv_phb_cur_occur == 1)
        {
            data = contact_p->field_data.email_address;
        }
        else
        {
            data = contact_p->field_data.email_address2;
        }
        
        sim_entry.field.email.adn_record_index = local_ptr->record_index;
        sim_entry.field.email.record_index = local_ptr->record_index;
        sim_entry.field.email.email_length = InputboxConvertDeviceEncodingToGSM(
                                                (PU8)data,
                                                sim_entry.field.email.email_address,
                                                MMI_PHB_EMAIL_LENGTH,
                                                SRV_PHB_CHARSET_ASCII,
                                                0,
                                                1) - 1;
        
        /* RELEASE buffer */
        srv_phb_at_send_read_additional_res_req(
            sim_interface,
            local_ptr->storage,
            PHB_EMAIL,
            local_ptr->record_index,
            L4C_OK,
            PHB_NO_CAUSE,
            &sim_entry);
    }
    srv_phb_field_free(SRV_PHB_ENTRY_FIELD_EMAIL, contact_p);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_send_write_additional_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  record_index        [IN]        
 *  result              [IN]        
 *  cause               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_send_write_additional_res_req(U8 sim_interface, U16 record_index, U8 storage, U8 type, U8 result, U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_write_additional_res_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_l4c_write_additional_res_req_struct*) OslConstructDataPtr(sizeof(mmi_l4c_write_additional_res_req_struct));
    local_ptr->phb_src = g_srv_phb_src_id;
    local_ptr->result.flag = result;
    local_ptr->result.cause = cause;
    local_ptr->type = type;
    local_ptr->storage = storage;
    local_ptr->occurrence = g_srv_phb_cur_occur;
    local_ptr->record_index = record_index;
    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_interface)),
        MSG_ID_MMI_L4C_WRITE_ADDITIONAL_RES_REQ,
        (oslParaType *) local_ptr,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_update_additional_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_update_additional_hdlr(S32 result, U16 store_index, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_at_phb_entry_struct *phb_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_entry = (srv_phb_at_phb_entry_struct*) user_data;
    srv_phb_at_send_write_additional_res_req(
        phb_entry->sim_interface,
        g_srv_phb_record_index,
        phb_entry->storage,
        PHB_EMAIL,
        (U8) ((result == SRV_PHB_NO_ERROR) ? L4C_OK : L4C_ERROR),
        (U16) ((result == SRV_PHB_SIM_PARTIAL_ERROR) ? PHB_CAUSE_NOT_SUPPORT : PHB_NO_CAUSE));

    srv_phb_field_free(phb_entry->number_category, phb_entry->contact_p);
    srv_phb_mem_free(phb_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_write_additional_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  info                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_write_additional_req_ind(U8 sim_interface, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_write_additional_req_ind_struct *local_ptr;
    U16 store_index;
    srv_phb_contact_info_struct *contact_p;
    srv_phb_at_phb_entry_struct *phb_entry;
    WCHAR* data;
    U8 sim_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_l4c_write_additional_req_ind_struct*) info;

    MMI_ASSERT(local_ptr != NULL);
    g_srv_phb_src_id = local_ptr->src_id;
    g_srv_phb_record_index = local_ptr->record_index;
    g_srv_phb_cur_occur = local_ptr->occurrence;

    if (!srv_phb_startup_is_phb_ready() || local_ptr->type != PHB_EMAIL)
    {
        srv_phb_at_send_write_additional_res_req(
            sim_interface,
            local_ptr->record_index,
            local_ptr->storage,
            local_ptr->type,
            L4C_ERROR,
            PHB_NO_CAUSE);
        return;
    }

    store_index = local_ptr->record_index - 1;    /* 1-based */
    if (local_ptr->storage == PHB_STORAGE_SIM ||
        local_ptr->storage == PHB_STORAGE_SIM2 ||
        local_ptr->storage == PHB_STORAGE_SIM3 ||
        local_ptr->storage == PHB_STORAGE_SIM4)
    {
        /* Check SIM record index range, 1 ~ MMI_PHB_SIM_ENTRIES */
        if (store_index >= MMI_PHB_SIM_ENTRIES)
        {
            srv_phb_at_send_write_additional_res_req(
                sim_interface,
                local_ptr->record_index,
                local_ptr->storage,
                local_ptr->type,
                L4C_ERROR,
                PHB_NO_CAUSE);
            return;
        }
        sim_id = srv_phb_get_sim_id((phb_storage_enum)local_ptr->storage);
        store_index += MMI_PHB_PHONE_ENTRIES + MMI_PHB_SIM_ENTRIES * sim_id;
    }
    else
    {
        srv_phb_at_send_write_additional_res_req(
            sim_interface,
            local_ptr->record_index,
            local_ptr->storage,
            local_ptr->type,
            L4C_ERROR,
            PHB_NO_CAUSE);
        return;
    }

    /* ALLOCATE buffer here for pending contact info saving */
    phb_entry = srv_phb_mem_malloc(sizeof(srv_phb_at_phb_entry_struct), SRV_PHB_MEMORY_TYPE_CTR);
    contact_p = srv_phb_field_malloc(SRV_PHB_ENTRY_FIELD_EMAIL);
    if (g_srv_phb_cur_occur == 1)
    {
        data = contact_p->field_data.email_address;
        phb_entry->number_category = SRV_PHB_ENTRY_FIELD_EMAIL1;
    }
    else
    {
        data = contact_p->field_data.email_address2;
        phb_entry->number_category = SRV_PHB_ENTRY_FIELD_EMAIL2;
    }
    InputboxConvertGSMToDeviceEncoding(
                local_ptr->entry.field.email.email_address,
                (U8*)data,
                local_ptr->entry.field.email.email_length,
                (MMI_PHB_EMAIL_LENGTH + 1) * ENCODING_LENGTH,
                SRV_PHB_CHARSET_ASCII,
                0,
                1);

    phb_entry->sim_interface = sim_interface;
    phb_entry->contact_p = contact_p;
    phb_entry->storage = local_ptr->storage;
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_phb_cntx_mgr_at(MMI_PHB_OP_EDIT);
    #endif
    srv_phb_oplib_update_contact(store_index, contact_p, srv_phb_at_update_additional_hdlr, phb_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_send_delete_additional_res_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  record_index        [IN]        
 *  result              [IN]        
 *  cause               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_send_delete_additional_res_req(U8 sim_interface, U16 record_index, U8 storage, U8 type, U8 result, U16 cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_delete_additional_res_req_struct *local_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr =
        (mmi_l4c_delete_additional_res_req_struct*) OslConstructDataPtr(sizeof(mmi_l4c_delete_additional_res_req_struct));
    local_ptr->phb_src = g_srv_phb_src_id;
    local_ptr->type = type;
    local_ptr->storage = storage;
    local_ptr->occurrence = g_srv_phb_cur_occur;
    local_ptr->result.flag = result;
    local_ptr->result.cause = cause;
    local_ptr->record_index = record_index;
    mmi_frm_send_ilm(
        mmi_frm_sim_to_l4c_mod(mmi_frm_index_to_sim(sim_interface)),
        PRT_DELETE_PHB_RES_REQ,
        (oslParaType *) local_ptr,
        NULL);  
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_update_additional_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result          [IN]        
 *  store_index     [IN]        
 *  user_data       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_delete_additional_hdlr(S32 result, U16 store_index, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_at_phb_entry_struct *phb_entry;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_entry = (srv_phb_at_phb_entry_struct*) user_data;
    srv_phb_at_send_delete_additional_res_req(
        phb_entry->sim_interface,
        g_srv_phb_record_index,
        phb_entry->storage,
        PHB_EMAIL,
        (U8) ((result == SRV_PHB_NO_ERROR) ? L4C_OK : L4C_ERROR),
        PHB_NO_CAUSE);

    srv_phb_field_free(phb_entry->number_category, phb_entry->contact_p);
    srv_phb_mem_free(phb_entry);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_delete_additional_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sim_interface       [IN]        
 *  info                [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_delete_additional_req_ind(U8 sim_interface, void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id;
    U16 store_index;
    WCHAR *data;
    srv_phb_contact_info_struct *contact_p;
    srv_phb_at_phb_entry_struct *phb_entry;
    mmi_l4c_delete_additional_req_ind_struct *local_ptr;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_ptr = (mmi_l4c_delete_additional_req_ind_struct*) info;

    MMI_ASSERT(local_ptr != NULL);
    g_srv_phb_src_id = local_ptr->src_id;
    g_srv_phb_record_index = local_ptr->record_index;
    g_srv_phb_cur_occur = local_ptr->occurrence;

    if (srv_phb_startup_is_phb_ready() && local_ptr->type == PHB_EMAIL)
    {
    store_index = local_ptr->record_index - 1;  /* 1-based */
        if ((local_ptr->storage == PHB_STORAGE_SIM ||
        local_ptr->storage == PHB_STORAGE_SIM2 ||
        local_ptr->storage == PHB_STORAGE_SIM3 ||
            local_ptr->storage == PHB_STORAGE_SIM4) &&
            store_index < MMI_PHB_SIM_ENTRIES)
        {
        sim_id = srv_phb_get_sim_id(local_ptr->storage);
        store_index += MMI_PHB_PHONE_ENTRIES + MMI_PHB_SIM_ENTRIES * sim_id;
            if (srv_phb_check_entry_exist(store_index))
    {
    phb_entry = srv_phb_mem_malloc(sizeof(srv_phb_at_phb_entry_struct), SRV_PHB_MEMORY_TYPE_CTR);
    contact_p = srv_phb_field_malloc(SRV_PHB_ENTRY_FIELD_EMAIL);
    if (g_srv_phb_cur_occur == 1)
    {
        data = contact_p->field_data.email_address;
        phb_entry->number_category = SRV_PHB_ENTRY_FIELD_EMAIL1;
    }
    else
    {
        data = contact_p->field_data.email_address2;
        phb_entry->number_category = SRV_PHB_ENTRY_FIELD_EMAIL2;
    }
    data[0] = 0;
    phb_entry->sim_interface = sim_interface;
    phb_entry->contact_p = contact_p;
    phb_entry->storage = local_ptr->storage;
    #ifndef __COSMOS_MMI_PACKAGE__
    mmi_phb_cntx_mgr_at(MMI_PHB_OP_EDIT);
    #endif
    srv_phb_oplib_update_contact(store_index, contact_p, srv_phb_at_delete_additional_hdlr, phb_entry);
}
        }
    }
    srv_phb_at_send_delete_additional_res_req(
        sim_interface,
        local_ptr->record_index,
        local_ptr->storage,
        local_ptr->type,
        L4C_ERROR,
        PHB_NO_CAUSE);
        return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_sim1_sim2_read_additional_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 *  mod_src     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_usim_read_additional_req_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sim_interface = mmi_frm_sim_to_index(mmi_frm_l4c_mod_to_sim(mod_src));
    srv_phb_at_read_additional_req_ind(g_srv_phb_sim_interface, info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_sim1_sim2_write_additional_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 *  mod_src     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_usim_write_additional_req_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sim_interface = mmi_frm_sim_to_index(mmi_frm_l4c_mod_to_sim(mod_src));
    srv_phb_at_write_additional_req_ind(g_srv_phb_sim_interface, info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_at_sim1_sim2_delete_additional_req_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info        [?]     
 *  mod_src     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_at_usim_delete_additional_req_ind(void *info, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_phb_sim_interface = mmi_frm_sim_to_index(mmi_frm_l4c_mod_to_sim(mod_src));
    srv_phb_at_delete_additional_req_ind(g_srv_phb_sim_interface, info);
}
#endif

#endif /* __MMI_PHB_ATCMD_SUPPORT__ */

