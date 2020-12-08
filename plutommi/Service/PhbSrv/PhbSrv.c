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
 *  PhbSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements service functions for other apps.
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
#include "MMI_include.h"

#include <ctype.h>      /* isdigit, isspace */

#include "PhbSrvGprot.h"
#include "PhbSrv.h"
#include "GSM7BitDefaultAlphabet.h"
#include "app_usedetails.h"
#include "custom_ecc.h"
#include "mmi_rp_srv_phb_def.h"
#include "PhoneBookGprot.h"
#include "UcmSrvGprot.h"

#ifdef __SYNCML_SUPPORT__
#include "SyncMLGProt.h"
#endif

#ifdef __MMI_VCARD__
#include "vCard.h"
#include "Bluetooth_struct.h"
#endif /* __MMI_VCARD__ */


#include "MMI_features.h"
#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "PhbSrvIprot.h"
#include "MMIDataType.h"
#include "custom_phb_config.h"
#include "mmi_frm_events_gprot.h"
#include "stack_msgs.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_config.h"
#include "ps_public_struct.h"
#include "Unicodexdcl.h"
#include "mcd_l4_common.h"
#include "string.h"
#include "ps_public_enum.h"
#include "sim_common_enums.h"
#include "customer_email_num.h"
#include "FileMgrSrvGProt.h"
#include "vcard_lib.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "nvram_common_defs.h"
#include "CustDataRes.h"
#include "nvram_editor_data_item.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_data_items.h"
#include "stdlib.h"
#include "custom_mmi_default_value.h"
#include "wgui_categories_list.h"
#include "SimCtrlSrvGprot.h"

/* 
 * Typedef
 */

typedef enum
{
#ifdef __MMI_CALLER_RES_IMAGE_FIRST__
    SRV_PHB_CALLER_RES_TYPE_IMAGE,
    SRV_PHB_CALLER_RES_TYPE_VIDEO,
    SRV_PHB_CALLER_RES_TYPE_RING,
#else /* __MMI_CALLER_RES_IMAGE_FIRST__ */
    SRV_PHB_CALLER_RES_TYPE_RING,
    SRV_PHB_CALLER_RES_TYPE_VIDEO,
    SRV_PHB_CALLER_RES_TYPE_IMAGE,
#endif /* __MMI_CALLER_RES_IMAGE_FIRST__ */
    SRV_PHB_CALLER_RES_TYPE_TOTAL
} srv_phb_caller_res_type;

typedef struct
{
    LOCAL_PARA_HDR
    srv_phb_async_func_type func;
    void *user_data;
} srv_phb_async_event_struct;

typedef struct
{
    U32 magic_head;
    U16 name[MMI_PHB_NAME_LENGTH + 1];
    U32 number_index;
    U16 store_index;
    S32 ref_count;
} srv_phb_cm_user_data_struct;

#define SRV_PHB_MAGIC_NUM   0x87654321

static U16 g_srv_phb_name_display_type;


/*****************************************************************************
 * FUNCTION
 *  srv_phb_async_event_common_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  info:               [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_async_event_common_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_async_event_struct *local_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_data = (srv_phb_async_event_struct*) info;

    if (local_data && local_data->func)
    {
        local_data->func(local_data->user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_async_event_interface
 * DESCRIPTION
 *  This function is used to provide a sync.-to-async. interface.
 * PARAMETERS
 *  func:               [IN]        Execute function
 *  user_data:          [IN]        User data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_async_event_interface(srv_phb_async_func_type func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_async_event_struct *data_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_ptr = (srv_phb_async_event_struct*) OslConstructDataPtr(sizeof(srv_phb_async_event_struct));
    data_ptr->func = func;
    data_ptr->user_data = user_data;

    SetProtocolEventHandler(srv_phb_async_event_common_hdlr, MSG_ID_MMI_PHB_ASYNC_EVENT_IND);

    mmi_frm_send_ilm(MOD_MMI, MSG_ID_MMI_PHB_ASYNC_EVENT_IND, (oslParaType*) data_ptr, NULL);
}


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
void srv_phb_build_l4phb_entry(l4c_phb_entry_struct *phb_entry, U16 *name, U16 *l_name, U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__PHB_0x81_SUPPORT__)
    U8 length;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number != NULL)
    {
        U16 *encode_num = srv_phb_mem_malloc((MMI_PHB_NUMBER_PLUS_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);
        U8 encode_ton;

        srv_phb_remove_invalid_number_ex(number);

        /* now number is **21*+8123456# */
        /* call the applib encode API to transfer + to the first place */
        encode_ton = applib_encode_number_unicode(number, encode_num);
        /* now number is +**21*8123456#, so we know it is an international number */

        phb_entry->tel.type = (encode_ton == 0x91) ? SRV_PHB_NUMBER_TYPE_INTERNATIONAL : SRV_PHB_NUMBER_TYPE_DEFAULT;
        phb_entry->tel.length = (U8) mmi_wcslen(encode_num);
        mmi_wcs_to_asc((CHAR*) phb_entry->tel.number, encode_num);
        srv_phb_mem_free(encode_num);
    }

    if ((name != NULL) || (l_name != NULL))
    {
        U16 *full_name = srv_phb_mem_malloc((MMI_PHB_NAME_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);

        srv_phb_convert_to_name(full_name, name, l_name, MMI_PHB_NAME_LENGTH);
        srv_phb_remove_invalid_name(full_name);

        if (srv_phb_check_ucs2_character(full_name))
        {
        #if defined(__PHB_0x81_SUPPORT__)
            if ((length = srv_phb_convert_to_0x81(full_name, MMI_TRUE)) > 0)
            {
                phb_entry->alpha_id.name_dcs = SRV_PHB_CHARSET_UCS2_81;
                phb_entry->alpha_id.name_length = length;
                memcpy(phb_entry->alpha_id.name, full_name, length);
            }
            else
        #endif /* defined(__PHB_0x81_SUPPORT__) */
            {
                phb_entry->alpha_id.name_dcs = SRV_PHB_CHARSET_UCS2;
                phb_entry->alpha_id.name_length = InputboxConvertDeviceEncodingToGSM(
                    (PU8) full_name,
                    phb_entry->alpha_id.name,
                    sizeof(phb_entry->alpha_id.name),
                    SRV_PHB_CHARSET_UCS2,
                    0,
                    1) - 2;
                phb_entry->alpha_id.name[phb_entry->alpha_id.name_length] = 0;
                phb_entry->alpha_id.name[phb_entry->alpha_id.name_length + 1] = 0;
            }
        }
        else
        {
            phb_entry->alpha_id.name_dcs = SRV_PHB_CHARSET_ASCII;
            phb_entry->alpha_id.name_length = InputboxConvertDeviceEncodingToGSM(
                                                (PU8) full_name,
                                                phb_entry->alpha_id.name,
                                                sizeof(phb_entry->alpha_id.name),
                                                SRV_PHB_CHARSET_ASCII,
                                                0,
                                                1) - 1;
            phb_entry->alpha_id.name[phb_entry->alpha_id.name_length] = 0;
        }
        srv_phb_mem_free(full_name);
    }
}


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
void srv_phb_parse_l4phb_entry(l4c_phb_entry_struct *phb_entry, U16 *name, U16 *l_name, U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((phb_entry->alpha_id.name_length == 0) ||
        (phb_entry->alpha_id.name[0] == 0xFF && phb_entry->alpha_id.name[1] == 0xFF))
    {
        name[0] = 0;
    }
    else
    {
        InputboxConvertGSMToDeviceEncoding(
            phb_entry->alpha_id.name,
            (U8*) name,
            phb_entry->alpha_id.name_length,
            (MMI_PHB_NAME_FIELD_LENGTH + 1) * sizeof(U16),
            phb_entry->alpha_id.name_dcs,
            0,
            1);
    }

    /* Put the whole name into first name because l4phb only supports one name */
    if (l_name != NULL)
    {
        l_name[0] = 0;
    }

    if (phb_entry->tel.type == SRV_PHB_NUMBER_TYPE_INTERNATIONAL)
    {
        U8 *decode_num = srv_phb_mem_malloc(MMI_PHB_NUMBER_PLUS_LENGTH + 1, SRV_PHB_MEMORY_TYPE_CTR);

        /* now number is +**21*8123456# */
        /* call the applib decode API to transfer + to place just after SS pattern */
        applib_decode_number(phb_entry->tel.number, decode_num, 0x91);
        /* now number is **21*+8123456#, so we can show the original data to user */

        mmi_asc_to_wcs(number, (CHAR*) decode_num);
        srv_phb_mem_free(decode_num);
    }
    else
    {
        mmi_asc_to_wcs(number, (CHAR*) phb_entry->tel.number);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_storage
 * DESCRIPTION
 *  This function is used to get PHB storage by store index. If store index is not in a valid range,
 *  it will return 0xFF.
 * PARAMETERS
 *  id:             [IN]        Store index
 * RETURN VALUES
 *  PHB_STORAGE_NVRAM:      Phone storage
 *  PHB_STORAGE_SIM:        SIM storage
 *  PHB_STORAGE_SIM2:       SIM2 storage
 *****************************************************************************/
U8 srv_phb_get_storage(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id < MMI_PHB_PHONE_ENTRIES)
    {
        return PHB_STORAGE_NVRAM;
    }
    else if (id < MMI_PHB_BASIC_ENTRIES)
    {
        return srv_phb_get_storage_by_sim_id((id - MMI_PHB_PHONE_ENTRIES)/MMI_PHB_SIM_ENTRIES);
    }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else if(id < MMI_PHB_ENTRIES)
    {
        return PHB_STORAGE_TCARD;
    }
    #endif
    return 0xFF;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_store_index_in_storage
 * DESCRIPTION
 *  This function is used to check if store index is in the range of the specified storage.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  storage:            [IN]        PHB storage
 * RETURN VALUES
 *  MMI_TRUE:           In range
 *  MMI_FALSE:          Out of range
 *****************************************************************************/
MMI_BOOL srv_phb_check_store_index_in_storage(U16 store_index, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store_index >= MMI_PHB_ENTRIES)
    {
        return MMI_FALSE;
    }

    if (storage == PHB_STORAGE_MAX || storage == srv_phb_get_storage(store_index))
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_storage_status
 * DESCRIPTION
 *  This function is used to check the status of the specified storage.
 * PARAMETERS
 *  storage:            [IN]        PHB storage
 * RETURN VALUES
 *  SRV_PHB_STORAGE_STATUS_EMPTY:   Storage is empty
 *  SRV_PHB_STORAGE_STATUS_FULL:    Storage is full
 *  SRV_PHB_STORAGE_STATUS_OTHERS:  Others status
 *****************************************************************************/
U8 srv_phb_check_storage_status(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_get_used_contact(storage) == 0)
    {
        return SRV_PHB_STORAGE_STATUS_EMPTY;
    }
    else if (srv_phb_get_used_contact(storage) == srv_phb_get_total_contact(storage))
    {
        return SRV_PHB_STORAGE_STATUS_FULL;
    }

    return SRV_PHB_STORAGE_STATUS_OTHERS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_storage_accessible
 * DESCRIPTION
 *  This function is used to check if the specified storage is accessible.
 * PARAMETERS
 *  storage:            [IN]        PHB storage
 * RETURN VALUES
 *  MMI_TRUE:           Storage is accessible
 *  MMI_FALSE:          Don't allow to access it
 *****************************************************************************/
MMI_BOOL srv_phb_check_storage_accessible(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == PHB_STORAGE_NVRAM)
    {
        return MMI_TRUE;
    }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else if (storage == PHB_STORAGE_TCARD)
    {
        return srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV);
    }
    #endif
    else
    {
        return srv_phb_startup_is_phb_support(srv_phb_get_sim_id((phb_storage_enum)storage), PHB_PHONEBOOK);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_total_contact
 * DESCRIPTION
 *  This function is used to get PHB total records by PHB storage.
 * PARAMETERS
 *  storage:            [IN]        PHB storage
 * RETURNS
 *  PHB total No.
 *****************************************************************************/
U16 srv_phb_get_total_contact(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_datamgr_total_contacts(storage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_used_contact
 * DESCRIPTION
 *  This function is used to get PHB used records by PHB storage.
 * PARAMETERS
 *  storage:            [IN]        PHB storage
 * RETURNS
 *  PHB used No.
 *****************************************************************************/
U16 srv_phb_get_used_contact(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_datamgr_used_contacts(storage);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_store_index_to_sort_index
 * DESCRIPTION
 *  This function is used to convert store index to sort index.
 * PARAMETERS
 *  storage:            [IN]        PHB storage
 *  store_index:        [IN]        Store index
 * RETURNS
 *  Sort index
 *****************************************************************************/
U16 srv_phb_store_index_to_sort_index(U8 storage, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_sse_store_index_to_sort_index(storage, store_index);
    if (result < 0)
    {
        return MMI_PHB_INVALID_CONTACT_ID;
    }

    return (U16) result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sort_index_to_store_index
 * DESCRIPTION
 *  This function is used to convert sort index to store index.
 * PARAMETERS
 *  storage:            [IN]        PHB storage
 *  sort_index:         [IN]        Sort index
 * RETURNS
 *  Store index
 *****************************************************************************/
mmi_phb_contact_id srv_phb_sort_index_to_store_index(U8 storage, U16 sort_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_sse_sort_index_to_store_index(storage, sort_index);
    if (result < 0)
    {
        return MMI_PHB_INVALID_CONTACT_ID;
    }

    return (mmi_phb_contact_id)result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_store_index_to_record_index
 * DESCRIPTION
 *  This function is used to convert store index to record index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  storage:            [OUT]       PHB storage
 *  record_index:       [OUT]       Record index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_store_index_to_record_index(mmi_phb_contact_id id, U8 *storage, U16 *record_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (id < MMI_PHB_ENTRIES)
    {
        if (id < MMI_PHB_PHONE_ENTRIES)
        {
            *storage = PHB_STORAGE_NVRAM;
            *record_index = id + 1;
        }
        else if (id < MMI_PHB_BASIC_ENTRIES)
        {
             id -= MMI_PHB_PHONE_ENTRIES;
             *storage = srv_phb_get_storage_by_sim_id((U8)(id / MMI_PHB_SIM_ENTRIES));
             *record_index = id % MMI_PHB_SIM_ENTRIES + 1;
        }
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        else 
        {
            *record_index = id - MMI_PHB_BASIC_ENTRIES;
            *storage = PHB_STORAGE_TCARD;
        }
        #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_record_index_to_store_index
 * DESCRIPTION
 *  This function is used to convert record index to store index.
 * PARAMETERS
 *  storage:            [IN]        PHB storage
 *  record_index:       [IN]        Record index
 *  store_index:        [OUT]       Store index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_record_index_to_store_index(U8 storage, U16 record_index, mmi_phb_contact_id *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sim_id = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == PHB_STORAGE_NVRAM)
    {
        if (record_index <= MMI_PHB_PHONE_ENTRIES)
        {
            *id = record_index - 1;
        }
    }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else if (storage == PHB_STORAGE_TCARD)
    {
        if (record_index <= MMI_PHB_TCARD_ENTRIES)
        {
            *id = record_index + MMI_PHB_PHONE_ENTRIES + MMI_PHB_TOTAL_SIM_ENTRIES;
        }
    }
    #endif
    else
    {
        sim_id = srv_phb_get_sim_id((phb_storage_enum)storage);
        if (record_index <= MMI_PHB_SIM_ENTRIES)
        {
            *id = record_index + MMI_PHB_PHONE_ENTRIES + MMI_PHB_SIM_ENTRIES * sim_id - 1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_entry_exist
 * DESCRIPTION
 *  This function is used to check if PHB entry exists or not.
 * PARAMETERS
 *  id:        [IN]        Store index
 * RETURN VALUES
 *  MMI_TRUE:           Entry exist
 *  MMI_FALSE:          Doesn't exist
 *****************************************************************************/
MMI_BOOL srv_phb_check_entry_exist(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_datamgr_check_store_index(id, SRV_PHB_ENTRY_FIELD_ALL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_number_exist
 * DESCRIPTION
 *  This function is used to check if the given number exists in PHB conatcts or not.
 * PARAMETERS
 *  number:             [IN]        Number to check
 * RETURN VALUES
 *  MMI_TRUE:           Number exist
 *  MMI_FALSE:          Doesn't exist
 *****************************************************************************/
MMI_BOOL srv_phb_check_number_exist(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_oplib_search(number, SRV_PHB_SEARCH_TYPE_NUM) >= 0)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_field_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_mask      [IN]        
 * RETURNS
 *  contact_p
 *****************************************************************************/
srv_phb_contact_info_struct *srv_phb_field_malloc(U32 field_mask)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct *contact_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_p =
        srv_phb_mem_malloc(sizeof(srv_phb_contact_info_struct), SRV_PHB_MEMORY_TYPE_ADM);
    memset(contact_p, 0, sizeof(srv_phb_contact_info_struct));
    contact_p->field_mask = field_mask | SRV_PHB_ENTRY_FIELD_DEF;
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_NAME)
    {
        contact_p->field_data.name =
            srv_phb_mem_malloc((MMI_PHB_NAME_FIELD_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.name[0] = 0;
    #if defined(__MMI_PHB_LAST_NAME_FIELD__)
        contact_p->field_data.l_name =
            srv_phb_mem_malloc((MMI_PHB_NAME_FIELD_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.l_name[0] = 0;
    #else
        contact_p->field_data.l_name = NULL;
    #endif
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_NUMBER)
    {
        contact_p->field_data.number =
            srv_phb_mem_malloc((MMI_PHB_NUMBER_PLUS_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.number[0] = 0;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_1)
    {
        contact_p->field_data.opt_num[0] =
            srv_phb_mem_malloc(sizeof(mmi_phb_wcs_num_struct), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.opt_num[0]->number[0] = 0;
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_2)
    {
        contact_p->field_data.opt_num[1] =
            srv_phb_mem_malloc(sizeof(mmi_phb_wcs_num_struct), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.opt_num[1]->number[0] = 0;
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_3)
    {
        contact_p->field_data.opt_num[2] =
            srv_phb_mem_malloc(sizeof(mmi_phb_wcs_num_struct), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.opt_num[2]->number[0] = 0;
    }
    contact_p->field_data.opt_order = NULL;
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_EMAIL1)
    {
        contact_p->field_data.email_address =
            srv_phb_mem_malloc((MMI_PHB_EMAIL_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.email_address[0] = 0;
    }
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_EMAIL2)
    {
        contact_p->field_data.email_address2 =
            srv_phb_mem_malloc((MMI_PHB_EMAIL_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.email_address2[0] = 0;
    }
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_COMPANY)
    {
        contact_p->field_data.company_name =
            srv_phb_mem_malloc((MMI_PHB_COMPANY_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.company_name[0] = 0;
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */
#if defined(__MMI_PHB_INFO_FIELD__)
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_TITLE)
    {
        contact_p->field_data.title =
            srv_phb_mem_malloc((MMI_PHB_TITLE_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.title[0] = 0;
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_URL)
    {
        contact_p->field_data.url =
            srv_phb_mem_malloc((MMI_PHB_URL_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.url[0] = 0;
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_P0BOX)
    {
        contact_p->field_data.pobox =
            srv_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.pobox[0] = 0;
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_EXTENSION)
    {
        contact_p->field_data.extension =
            srv_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.extension[0] = 0;
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_STREET)
    {
        contact_p->field_data.street =
            srv_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.street[0] = 0;
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_CITY)
    {
        contact_p->field_data.city =
            srv_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.city[0] = 0;
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_STATE)
    {
        contact_p->field_data.state =
            srv_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.state[0] = 0;
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_POSTALCODE)
    {
        contact_p->field_data.postalcode =
            srv_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.postalcode[0] = 0;
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_COUNTRY)
    {
        contact_p->field_data.country =
            srv_phb_mem_malloc((MMI_PHB_ADDRESS_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.country[0] = 0;
    }
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_NOTE)
    {
        contact_p->field_data.note =
            srv_phb_mem_malloc((MMI_PHB_NOTE_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.note[0] = 0;
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */
    if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_PIC)
    {
        contact_p->field_data.image_path =
            srv_phb_mem_malloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_ADM);
        contact_p->field_data.image_path[0] = 0;
    }

    return contact_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_field_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  field_mask      [IN]        
 *  contact_p       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_field_free(U32 field_mask, srv_phb_contact_info_struct *contact_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (contact_p != NULL)
    {
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_NAME)
        {
            srv_phb_mem_free(contact_p->field_data.name);
        #if defined(__MMI_PHB_LAST_NAME_FIELD__)
            srv_phb_mem_free(contact_p->field_data.l_name);
        #endif
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_NUMBER)
        {
            srv_phb_mem_free(contact_p->field_data.number);
        }
    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_1)
        {
            srv_phb_mem_free(contact_p->field_data.opt_num[0]);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_2)
        {
            srv_phb_mem_free(contact_p->field_data.opt_num[1]);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_OPT_NUM_3)
        {
            srv_phb_mem_free(contact_p->field_data.opt_num[2]);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_EMAIL1)
        {
            srv_phb_mem_free(contact_p->field_data.email_address);
        }
    #ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_EMAIL2)
        {
            srv_phb_mem_free(contact_p->field_data.email_address2);
        }
    #endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_COMPANY)
        {
            srv_phb_mem_free(contact_p->field_data.company_name);
        }
    #endif /* __MMI_PHB_OPTIONAL_FIELD__ */
    #if defined(__MMI_PHB_INFO_FIELD__)
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_TITLE)
        {
            srv_phb_mem_free(contact_p->field_data.title);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_URL)
        {
            srv_phb_mem_free(contact_p->field_data.url);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_P0BOX)
        {
            srv_phb_mem_free(contact_p->field_data.pobox);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_EXTENSION)
        {
            srv_phb_mem_free(contact_p->field_data.extension);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_STREET)
        {
            srv_phb_mem_free(contact_p->field_data.street);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_CITY)
        {
            srv_phb_mem_free(contact_p->field_data.city);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_STATE)
        {
            srv_phb_mem_free(contact_p->field_data.state);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_POSTALCODE)
        {
            srv_phb_mem_free(contact_p->field_data.postalcode);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_COUNTRY)
        {
            srv_phb_mem_free(contact_p->field_data.country);
        }
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_NOTE)
        {
            srv_phb_mem_free(contact_p->field_data.note);
        }
    #endif /* defined(__MMI_PHB_INFO_FIELD__) */
        if (contact_p->field_mask & SRV_PHB_ENTRY_FIELD_PIC)
        {
            srv_phb_mem_free(contact_p->field_data.image_path);
        }
        srv_phb_mem_free(contact_p);
        contact_p = NULL;
    }
}

#ifdef __MMI_VCARD__

/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_vcard_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  contact_p       [IN]        
 *  vcard_object    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_convert_to_vcard_object(srv_phb_contact_info_struct *contact_p, vcard_object_struct *vcard_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmgr_filetype_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcard_object->n.given = contact_p->field_data.name;
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    vcard_object->n.family = contact_p->field_data.l_name;
#endif
    vcard_object->tel[0].tel = contact_p->field_data.number;
    vcard_object->tel[0].type = VCARD_TEL_TYPE_CELL;
    vcard_object->tel[0].is_preferred =
        ((contact_p->field_data.default_number == SRV_PHB_ENTRY_FIELD_NUMBER) ? KAL_TRUE : KAL_FALSE);
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (contact_p->field_data.opt_num[0])
    {
        vcard_object->tel[1].tel = contact_p->field_data.opt_num[0]->number;
        vcard_object->tel[1].type = srv_phb_convert_number_type_to_vcard(contact_p->field_data.opt_num[0]->type);
        vcard_object->tel[1].is_preferred =
            ((contact_p->field_data.default_number == SRV_PHB_ENTRY_FIELD_OPT_NUM_1) ? KAL_TRUE : KAL_FALSE);
    }
    if (contact_p->field_data.opt_num[1])
    {
        vcard_object->tel[2].tel = contact_p->field_data.opt_num[1]->number;
        vcard_object->tel[2].type = srv_phb_convert_number_type_to_vcard(contact_p->field_data.opt_num[1]->type);
        vcard_object->tel[2].is_preferred =
            ((contact_p->field_data.default_number == SRV_PHB_ENTRY_FIELD_OPT_NUM_2) ? KAL_TRUE : KAL_FALSE);
    }
    if (contact_p->field_data.opt_num[2])
    {
        vcard_object->tel[3].tel = contact_p->field_data.opt_num[2]->number;
        vcard_object->tel[3].type = srv_phb_convert_number_type_to_vcard(contact_p->field_data.opt_num[2]->type);
        vcard_object->tel[3].is_preferred =
            ((contact_p->field_data.default_number == SRV_PHB_ENTRY_FIELD_OPT_NUM_3) ? KAL_TRUE : KAL_FALSE);
    }
    vcard_object->email[0].email = contact_p->field_data.email_address;
    vcard_object->email[0].is_preferred = MMI_TRUE;
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    vcard_object->email[1].email = contact_p->field_data.email_address2;
    vcard_object->email[1].is_preferred = MMI_FALSE;
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    vcard_object->org.name = contact_p->field_data.company_name;
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    vcard_object->bday.year = contact_p->field_data.b_year;
    vcard_object->bday.month = contact_p->field_data.b_month;
    vcard_object->bday.day = contact_p->field_data.b_day;
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

#if defined(__MMI_PHB_INFO_FIELD__)
    vcard_object->title.title = contact_p->field_data.title;
    vcard_object->url[0].url = contact_p->field_data.url;
    vcard_object->adr[0].post_office = contact_p->field_data.pobox;
    vcard_object->adr[0].extended = contact_p->field_data.extension;
    vcard_object->adr[0].street = contact_p->field_data.street;
    vcard_object->adr[0].locality = contact_p->field_data.city;
    vcard_object->adr[0].region = contact_p->field_data.state;
    vcard_object->adr[0].postal_code = contact_p->field_data.postalcode;
    vcard_object->adr[0].country = contact_p->field_data.country;
    vcard_object->note.note = contact_p->field_data.note;
#endif /* defined(__MMI_PHB_INFO_FIELD__) */

    if (contact_p->field_data.image_path)
    {
        type = srv_fmgr_types_find_type_by_filename_str(contact_p->field_data.image_path);
        vcard_object->photo.type = srv_phb_convert_image_type_to_vcard(type);
        if (vcard_object->photo.type == VCARD_PHOTO_TYPE_TOTAL)
        {
            vcard_object->photo.file_name[0] = 0;
            return;
        }
        mmi_wcsncpy(vcard_object->photo.file_name, contact_p->field_data.image_path, SRV_FMGR_PATH_MAX_LEN);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_from_vcard_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  contact_p       [IN]        
 *  vcard_object    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_convert_from_vcard_object(srv_phb_contact_info_struct *contact_p, vcard_object_struct *vcard_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    if (contact_p->field_data.l_name && vcard_object->n.family)
    {
        mmi_wcsncpy(contact_p->field_data.l_name, vcard_object->n.family, MMI_PHB_NAME_FIELD_LENGTH);
        srv_phb_remove_invalid_name(contact_p->field_data.l_name);
    }
    if (contact_p->field_data.name && vcard_object->n.given)
    {
        mmi_wcsncpy(contact_p->field_data.name, vcard_object->n.given, MMI_PHB_NAME_FIELD_LENGTH);
        srv_phb_remove_invalid_name(contact_p->field_data.name);
    }
#else /* defined(__MMI_PHB_LAST_NAME_FIELD__) */
    if (contact_p->field_data.name)
    {
        srv_phb_convert_to_name(
            contact_p->field_data.name,
            vcard_object->n.given,
            vcard_object->n.family,
            MMI_PHB_NAME_FIELD_LENGTH);
        srv_phb_remove_invalid_name(contact_p->field_data.name);
    }
#endif /* defined(__MMI_PHB_LAST_NAME_FIELD__) */
    if (contact_p->field_data.number && vcard_object->tel[0].tel)
    {
        if (vcard_object->tel[0].tel[0] == L'+')
        {
            mmi_wcsncpy(contact_p->field_data.number, vcard_object->tel[0].tel, MMI_PHB_NUMBER_PLUS_LENGTH);
        }
        else
        {
            mmi_wcsncpy(contact_p->field_data.number, vcard_object->tel[0].tel, MMI_PHB_NUMBER_LENGTH);
        }
        srv_phb_remove_invalid_number(contact_p->field_data.number);
    }
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (contact_p->field_data.opt_num[0] && contact_p->field_data.opt_num[0]->number && vcard_object->tel[1].tel)
    {
        if (vcard_object->tel[1].tel[0] == L'+')
        {
            mmi_wcsncpy(contact_p->field_data.opt_num[0]->number, vcard_object->tel[1].tel, MMI_PHB_NUMBER_PLUS_LENGTH);
        }
        else
        {
            mmi_wcsncpy(contact_p->field_data.opt_num[0]->number, vcard_object->tel[1].tel, MMI_PHB_NUMBER_LENGTH);
        }
        srv_phb_remove_invalid_number(contact_p->field_data.opt_num[0]->number);
        contact_p->field_data.opt_num[0]->type = srv_phb_convert_number_type_from_vcard(vcard_object->tel[1].type);
    }
    if (contact_p->field_data.opt_num[1] && contact_p->field_data.opt_num[1]->number && vcard_object->tel[2].tel)
    {
        if (vcard_object->tel[2].tel[0] == L'+')
        {
            mmi_wcsncpy(contact_p->field_data.opt_num[1]->number, vcard_object->tel[2].tel, MMI_PHB_NUMBER_PLUS_LENGTH);
        }
        else
        {
            mmi_wcsncpy(contact_p->field_data.opt_num[1]->number, vcard_object->tel[2].tel, MMI_PHB_NUMBER_LENGTH);
        }
        srv_phb_remove_invalid_number(contact_p->field_data.opt_num[1]->number);
        contact_p->field_data.opt_num[1]->type = srv_phb_convert_number_type_from_vcard(vcard_object->tel[2].type);
    }
    if (contact_p->field_data.opt_num[2] && contact_p->field_data.opt_num[2]->number && vcard_object->tel[3].tel)
    {
        if (vcard_object->tel[3].tel[0] == L'+')
        {
            mmi_wcsncpy(contact_p->field_data.opt_num[2]->number, vcard_object->tel[3].tel, MMI_PHB_NUMBER_PLUS_LENGTH);
        }
        else
        {
            mmi_wcsncpy(contact_p->field_data.opt_num[2]->number, vcard_object->tel[3].tel, MMI_PHB_NUMBER_LENGTH);
        }
        srv_phb_remove_invalid_number(contact_p->field_data.opt_num[2]->number);
        contact_p->field_data.opt_num[2]->type = srv_phb_convert_number_type_from_vcard(vcard_object->tel[3].type);
    }
#if defined(__MMI_PHB_DEFAULT_NUMBER__)
    if (vcard_object->tel[0].is_preferred)
    {
        contact_p->field_data.default_number = SRV_PHB_ENTRY_FIELD_NUMBER;
    }
    else if (vcard_object->tel[1].is_preferred)
    {
        contact_p->field_data.default_number = SRV_PHB_ENTRY_FIELD_OPT_NUM_1;
    }
    else if (vcard_object->tel[2].is_preferred)
    {
        contact_p->field_data.default_number = SRV_PHB_ENTRY_FIELD_OPT_NUM_2;
    }
    else if (vcard_object->tel[3].is_preferred)
    {
        contact_p->field_data.default_number = SRV_PHB_ENTRY_FIELD_OPT_NUM_3;
    }
    else
    {
        contact_p->field_data.default_number = 0xFE;
    }
#endif /* defined(__MMI_PHB_DEFAULT_NUMBER__) */
    if (contact_p->field_data.email_address && vcard_object->email[0].email)
    {
        mmi_wcsncpy(contact_p->field_data.email_address, vcard_object->email[0].email, MMI_PHB_EMAIL_LENGTH);
    }
#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
    if (contact_p->field_data.email_address2 && vcard_object->email[1].email)
    {
        mmi_wcsncpy(contact_p->field_data.email_address2, vcard_object->email[1].email, MMI_PHB_EMAIL_LENGTH);
    }
#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */
    if (contact_p->field_data.company_name && vcard_object->org.name)
    {
        mmi_wcsncpy(contact_p->field_data.company_name, vcard_object->org.name, MMI_PHB_COMPANY_LENGTH);
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    contact_p->field_data.b_year = vcard_object->bday.year;
    contact_p->field_data.b_month = vcard_object->bday.month;
    contact_p->field_data.b_day = vcard_object->bday.day;
#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */

#if defined(__MMI_PHB_INFO_FIELD__)
    if (contact_p->field_data.title && vcard_object->title.title)
    {
        mmi_wcsncpy(contact_p->field_data.title, vcard_object->title.title, MMI_PHB_TITLE_LENGTH);
    }
    if (contact_p->field_data.url && vcard_object->url[0].url)
    {
        mmi_wcsncpy(contact_p->field_data.url, vcard_object->url[0].url, MMI_PHB_URL_LENGTH);
    }
    if (contact_p->field_data.pobox && vcard_object->adr[0].post_office)
    {
        mmi_wcsncpy(contact_p->field_data.pobox, vcard_object->adr[0].post_office, MMI_PHB_ADDRESS_LENGTH);
    }
    if (contact_p->field_data.extension && vcard_object->adr[0].extended)
    {
        mmi_wcsncpy(contact_p->field_data.extension, vcard_object->adr[0].extended, MMI_PHB_ADDRESS_LENGTH);
    }
    if (contact_p->field_data.street && vcard_object->adr[0].street)
    {
        mmi_wcsncpy(contact_p->field_data.street, vcard_object->adr[0].street, MMI_PHB_ADDRESS_LENGTH);
    }
    if (contact_p->field_data.city && vcard_object->adr[0].locality)
    {
        mmi_wcsncpy(contact_p->field_data.city, vcard_object->adr[0].locality, MMI_PHB_ADDRESS_LENGTH);
    }
    if (contact_p->field_data.state && vcard_object->adr[0].region)
    {
        mmi_wcsncpy(contact_p->field_data.state, vcard_object->adr[0].region, MMI_PHB_ADDRESS_LENGTH);
    }
    if (contact_p->field_data.postalcode && vcard_object->adr[0].postal_code)
    {
        mmi_wcsncpy(contact_p->field_data.postalcode, vcard_object->adr[0].postal_code, MMI_PHB_ADDRESS_LENGTH);
    }
    if (contact_p->field_data.country && vcard_object->adr[0].country)
    {
        mmi_wcsncpy(contact_p->field_data.country, vcard_object->adr[0].country, MMI_PHB_ADDRESS_LENGTH);
    }
    if (contact_p->field_data.note && vcard_object->note.note)
    {
        mmi_wcsncpy(contact_p->field_data.note, vcard_object->note.note, MMI_PHB_NOTE_LENGTH);
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */

    if (contact_p->field_data.image_path && vcard_object->photo.file_name)
    {
        mmi_wcsncpy(contact_p->field_data.image_path, vcard_object->photo.file_name, SRV_FMGR_PATH_MAX_LEN);
        if (vcard_object->photo.file_name[0])
        {
            contact_p->field_data.res_type = SRV_PHB_RES_TYPE_IMAGE_FILE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_to_vcard_object
 * DESCRIPTION
 *  
 * PARAMETERS
 *  contact       [IN]        
 *  vcard_object    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_contact_to_vcard_object(srv_phb_contact contact, vcard_object_struct *vcard_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_fmgr_filetype_enum type;
    srv_phb_iterator iter;
    srv_phb_number_struct* number;
    srv_phb_email_struct* email;
    srv_phb_bday_struct* birthday;
    srv_phb_address_struct* address;
    srv_phb_url_struct* url;
    srv_phb_note_struct* note;
    S32 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(vcard_object, 0, sizeof(vcard_object_struct));
    vcard_object->n.given = srv_phb_contact_get_fname(contact);
#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    vcard_object->n.family = srv_phb_contact_get_lname(contact);
#endif
    iter = srv_phb_contact_get_number_iterator(contact);
    while (iter && index < VCARD_MAX_TEL_COUNT)
    {
        number = srv_phb_contact_get_number_next(&iter);
        if (number)
        {
            vcard_object->tel[index].tel = number->number;
            vcard_object->tel[index].type = srv_phb_convert_number_type_to_vcard((mmi_phb_num_type_enum)(number->type));
            vcard_object->tel[index].is_preferred = number->is_default;
        }
        index++;
    }

    index = 0;
    iter = srv_phb_contact_get_email_iterator(contact);
    while (iter && index < VCARD_MAX_EMAIL_COUNT)
    {
        email = srv_phb_contact_get_email_next(&iter);
        if (email)
        {
            vcard_object->email[index].email = email->email;
            vcard_object->email[index].is_preferred = MMI_FALSE;
            vcard_object->email[index].type = srv_phb_convert_email_type_to_vcard((mmi_phb_email_type_enum)(email->type));
        }
        index++;
        #ifdef __OP01__
        break;
        #endif
    }

    vcard_object->org.name = srv_phb_contact_get_company(contact);

    birthday = srv_phb_contact_get_bday(contact);
    if (birthday)
    {
        vcard_object->bday.year = birthday->b_year;
        vcard_object->bday.month = birthday->b_month;
        vcard_object->bday.day = birthday->b_day;
    }

    #ifndef __OP01__
    vcard_object->title.title = srv_phb_contact_get_title(contact);

    index = 0;
    iter = srv_phb_contact_get_url_iterator(contact);
    while (iter && index < VCARD_MAX_URL_COUNT)
    {
        url = srv_phb_contact_get_url_next(&iter);
        if (url)
        {
            vcard_object->url[index].url = url->url;
        }
        index++;
    }

    index = 0;
    iter = srv_phb_contact_get_address_iterator(contact);
    while (iter && index < VCARD_MAX_ADR_COUNT)
    {
        address = srv_phb_contact_get_address_next(&iter);
        if (address)
        {
            vcard_object->adr[index].post_office = address->address.pobox;
            vcard_object->adr[index].extended = address->address.extension;
            vcard_object->adr[index].street = address->address.street;
            vcard_object->adr[index].locality = address->address.city;
            vcard_object->adr[index].region = address->address.state;
            vcard_object->adr[index].postal_code = address->address.postalcode;
            vcard_object->adr[index].country = address->address.country;
        }
        index++;
    }

    index = 0;
    iter = srv_phb_contact_get_note_iterator(contact);
    note = srv_phb_contact_get_note_next(&iter);
    if (note)
    {
        vcard_object->note.note = note->note;
    }

    if (srv_phb_contact_get_image(contact) && srv_phb_contact_get_image(contact)->res_path[0])
    {
        type = srv_fmgr_types_find_type_by_filename_str(srv_phb_contact_get_image(contact)->res_path);
        vcard_object->photo.type = srv_phb_convert_image_type_to_vcard(type);
        if (vcard_object->photo.type != VCARD_PHOTO_TYPE_TOTAL)
        {
            mmi_wcsncpy(vcard_object->photo.file_name, srv_phb_contact_get_image(contact)->res_path, SRV_FMGR_PATH_MAX_LEN);
        }
        else
        {
            vcard_object->photo.file_name[0] = 0;
        }
    }
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_vcard_object_to_contact
 * DESCRIPTION
 *  
 * PARAMETERS
 *  contact       [IN]        
 *  vcard_object    [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_phb_contact srv_phb_vcard_object_to_contact(srv_phb_contact contact, vcard_object_struct *vcard_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifndef __MMI_PHB_LAST_NAME_FIELD__
    U16 name[MMI_PHB_NAME_FIELD_LENGTH + 1];
    #endif
    srv_phb_bday_struct birthday;
    S32 i;
    mmi_phb_address_struct* adr = NULL;
    S32 number_count = (MMI_PHB_NUMBER_FIELD_COUNT < VCARD_MAX_TEL_COUNT ? MMI_PHB_NUMBER_FIELD_COUNT : VCARD_MAX_TEL_COUNT);
    S32 email_count = (MMI_PHB_EMAIL_FIELD_COUNT < VCARD_MAX_EMAIL_COUNT ? MMI_PHB_EMAIL_FIELD_COUNT : VCARD_MAX_EMAIL_COUNT);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (contact)
    {
        srv_phb_reset_contact(contact, MMI_PHB_CONTACT_FIELD_ALL);
    }
    else
    {
        contact = srv_phb_create_contact(NULL);
    }

#if defined(__MMI_PHB_LAST_NAME_FIELD__)
    if (vcard_object->n.family)
    {
        srv_phb_remove_invalid_name(vcard_object->n.family);
        srv_phb_contact_set_lname(contact, vcard_object->n.family);
    }
    if (vcard_object->n.given)
    {
        srv_phb_remove_invalid_name(vcard_object->n.given);
        srv_phb_contact_set_fname(contact, vcard_object->n.given);
    }
#else /* defined(__MMI_PHB_LAST_NAME_FIELD__) */
    srv_phb_remove_invalid_name(vcard_object->n.family);
    srv_phb_remove_invalid_name(vcard_object->n.given);
    srv_phb_convert_to_name(
            name,
            vcard_object->n.given,
            vcard_object->n.family,
            MMI_PHB_NAME_FIELD_LENGTH);
    srv_phb_contact_set_fname(contact, name);
#endif /* defined(__MMI_PHB_LAST_NAME_FIELD__) */

    for (i = 0; i < number_count; i++)
    {
        srv_phb_remove_invalid_number(vcard_object->tel[i].tel);
        if (vcard_object->tel[i].tel && vcard_object->tel[i].tel[0] && srv_phb_check_valid_number(vcard_object->tel[i].tel))
        {
            srv_phb_contact_add_number_ex(
                    contact,
                    MMI_PHB_SUB_ID_NEW,
                    i,
                    srv_phb_convert_number_type_from_vcard(vcard_object->tel[i].type),
                    vcard_object->tel[i].tel,
                    NULL,
                    vcard_object->tel[i].is_preferred);
        }
    }

    for (i = 0; i < email_count; i++)
    {
        if (applib_is_valid_email_address_unicode(vcard_object->email[i].email))
        {
            srv_phb_contact_add_email_ex(
                contact,
                MMI_PHB_SUB_ID_NEW,
                i,
                srv_phb_convert_email_type_from_vcard(vcard_object->email[i].type),
                vcard_object->email[i].email,
                NULL);
        }
    }

    if (vcard_object->org.name)
    {
        srv_phb_contact_set_company(contact, vcard_object->org.name);
    }

    birthday.b_year = vcard_object->bday.year;
    birthday.b_month = vcard_object->bday.month;
    birthday.b_day = vcard_object->bday.day;
    srv_phb_contact_set_bday(contact, &birthday);

    if (vcard_object->title.title)
    {
        srv_phb_contact_set_title(contact, vcard_object->title.title);
    }

    for (i = 0; i < VCARD_MAX_URL_COUNT; i++)
    {
        if (vcard_object->url[i].url && vcard_object->url[i].url[0])
        {
            srv_phb_contact_add_url_ex(
                contact,
                MMI_PHB_SUB_ID_NEW,
                0,
                vcard_object->url[i].url);
        }
    }

    for (i = 0; i < VCARD_MAX_ADR_COUNT; i++)
    {
        if (!adr)
        {
            adr = srv_phb_mem_malloc(sizeof(mmi_phb_address_struct), SRV_PHB_MEMORY_TYPE_ADM);
        }
        if (vcard_object->adr[i].post_office)
        {
            mmi_wcsncpy(adr->pobox, vcard_object->adr[i].post_office, MMI_PHB_ADDRESS_LENGTH);
        }
        if (vcard_object->adr[i].extended)
        {
            mmi_wcsncpy(adr->extension, vcard_object->adr[i].extended, MMI_PHB_ADDRESS_LENGTH);
        }
        if (vcard_object->adr[i].street)
        {
            mmi_wcsncpy(adr->street, vcard_object->adr[i].street, MMI_PHB_ADDRESS_LENGTH);
        }
        if (vcard_object->adr[i].locality)
        {
            mmi_wcsncpy(adr->city, vcard_object->adr[i].locality, MMI_PHB_ADDRESS_LENGTH);
        }
        if (vcard_object->adr[i].region)
        {
            mmi_wcsncpy(adr->state, vcard_object->adr[i].region, MMI_PHB_ADDRESS_LENGTH);
        }
        if (vcard_object->adr[i].postal_code)
        {
            mmi_wcsncpy(adr->postalcode, vcard_object->adr[i].postal_code, MMI_PHB_ADDRESS_LENGTH);
        }
        if (vcard_object->adr[i].country)
        {
            mmi_wcsncpy(adr->country, vcard_object->adr[i].country, MMI_PHB_ADDRESS_LENGTH);
        }
        
        srv_phb_contact_add_address_ex(
            contact,
            MMI_PHB_SUB_ID_NEW,
            0,
            adr);

    }
    if (adr)
    {
        srv_phb_mem_free(adr);
    }

    if (vcard_object->note.note && vcard_object->note.note[0])
    {
        srv_phb_contact_add_note_ex(
                contact,
                MMI_PHB_SUB_ID_NEW,
                0,
                vcard_object->note.note);
    }

    if (vcard_object->photo.file_name)
    {
        srv_phb_contact_set_image_ex(
                contact,
                0,
                vcard_object->photo.file_name);
    }
    return contact;
}


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
MMI_BOOL srv_phb_vcard_is_valid_contact(vcard_object_struct *vcard_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;
    MMI_BOOL flag = MMI_FALSE;
    WCHAR number[VCARD_MAX_TEL_LENGTH + 1];
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vcard_object == NULL)
    {
        return MMI_FALSE;
    }

    for (index = 0; index < VCARD_MAX_TEL_COUNT; index++)
    {
        if (vcard_object->tel[index].tel && vcard_object->tel[index].tel[0] != 0)
        {
            mmi_wcsncpy(number, vcard_object->tel[index].tel, VCARD_MAX_TEL_LENGTH + 1);
            srv_phb_remove_invalid_number(number);
            if (srv_phb_check_valid_number(number))
            {
                break;
            }
            else if (index == VCARD_MAX_TEL_COUNT - 1)
            {
                return MMI_FALSE;
            }
        }
    }

    for (index = 0; index < VCARD_MAX_EMAIL_COUNT; index++)
    {
        if (vcard_object->email[index].email && vcard_object->email[index].email[0] != 0 && !applib_is_valid_email_address_unicode(vcard_object->email[index].email))
        {
           // return MMI_FALSE;
        }
    }

    if (vcard_object->n.family && vcard_object->n.family[0] != 0)
    {
        flag = MMI_TRUE;
    }
    if (vcard_object->n.given && vcard_object->n.given[0] != 0)
    {
        flag = MMI_TRUE;
    }
    for (index = 0; index < VCARD_MAX_TEL_COUNT; index++)
    {
        if (vcard_object->tel[index].tel && vcard_object->tel[index].tel[0] != 0)
        {
            flag = MMI_TRUE;
        }
    }
    for (index = 0; index < VCARD_MAX_EMAIL_COUNT; index++)
    {
        if (vcard_object->email[index].email && vcard_object->email[index].email[0] != 0)
        {
            flag = MMI_TRUE;
        }
    }

    if (flag)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

#endif /* __MMI_VCARD__ */

#ifdef __SYNCML_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sync_get_index_array
 * DESCRIPTION
 *  This function is used to get PHB store index array.
 * PARAMETERS
 *  index_array:            [IN/OUT]    Store index array
 *  max_index_count:        [IN]        Index array size
 * RETURNS
 *  No. of contacts in Phone storage
 *****************************************************************************/
U16 srv_phb_sync_get_index_array(U16 *index_array, U16 max_index_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;
    srv_phb_filter_struct filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index_array == NULL)
    {
        return srv_phb_get_used_contact(PHB_STORAGE_NVRAM);
    }

    memset(&filter, 0, sizeof(srv_phb_filter_struct));
    filter.storage = PHB_STORAGE_NVRAM;
    filter.field_filter = SRV_PHB_ENTRY_FIELD_ALL;

    result = srv_phb_oplib_build_contact_list(&filter, index_array, max_index_count);
    if (result < 0)
    {
        return 0;
    }

    return (U16) result;
}

#ifdef __MMI_VCARD__


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sync_vcard_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result:                 [IN]        
 *  store_index:            [IN]        
 *  user_data:              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_sync_vcard_hdlr(srv_phb_async_op_cb_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_add_cb_struct *cb_cntx = (srv_phb_add_cb_struct *)info;
    if (cb_cntx->result != SRV_PHB_NO_ERROR)
    {
        mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_ERROR, 0xFFFF);
        return;
    }
    mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_SUCCESS, cb_cntx->id);
}

#endif /* __MMI_VCARD__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sync_vcard
 * DESCRIPTION
 *  This function is used to sync data from/to PHB to/from SyncML server.
 * PARAMETERS
 *  action:                 [IN]        SyncML action type
 *  file_path:              [IN]        vCard file path
 *  store_index:            [IN]        Store index
 *  charset:                [IN]        Default charset to parse vCard
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_sync_vcard(U8 action, U16 *file_path, U16 store_index, U8 charset)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    #ifdef __MMI_VCARD__
    srv_phb_contact contact;
    vcard_object_struct vcard_data;
    vcard_object_struct *vcard_data_p;
    srv_phb_delete_req_struct del_req;
    srv_phb_update_req_struct upd_req;
    srv_phb_add_req_struct add_req;
    VB_HANDLE vb;
    VP_HANDLE vp;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (action != SRV_PHB_VCARD_ADD && store_index >= MMI_PHB_PHONE_ENTRIES)
    {
        mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_INVALID_PARAM, store_index);
        return;
    }

    if (action != SRV_PHB_VCARD_DELETE && file_path == NULL)
    {
        mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_INVALID_PARAM, store_index);
        return;
    }

    if (!srv_phb_startup_is_phb_ready())
    {
        mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_NOT_READY, store_index);
        return;
    }

    if (action == SRV_PHB_VCARD_ADD)
    {
        if (srv_phb_get_used_contact(PHB_STORAGE_NVRAM) == srv_phb_get_total_contact(PHB_STORAGE_NVRAM))
        {
            mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_STORAGE_FULL, store_index);
            return;
        }
    }

    if (action == SRV_PHB_VCARD_DELETE)
    {
        if (!srv_phb_check_entry_exist(store_index))
        {
            mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_NOT_FOUND, store_index);
            return;
        }
    }

    if (action == SRV_PHB_VCARD_READ)
    {
        contact = srv_phb_read_contact(store_index, NULL, NULL);
        if (contact == NULL)
        {
            mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_ERROR, store_index);
            srv_phb_free_contact(contact);
            return;
        }
        vb = vcard_open_builder(file_path, VCARD_OPEN_MODE_DEFAULT, NULL);
        if (!vb)
        {
            mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_ERROR, store_index);
            srv_phb_free_contact(contact);
            return;
        }
        memset(&vcard_data, 0, sizeof(vcard_object_struct));
        srv_phb_contact_to_vcard_object(contact, &vcard_data);
        result = vcard_build(vb, &vcard_data);
        if (result == VCARD_RESULT_FAIL)
        {
            vcard_close_builder(vb);
            mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_ERROR, store_index);
            srv_phb_free_contact(contact);
            return;
        }

        vcard_close_builder(vb);

        mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_SUCCESS, store_index);
        srv_phb_free_contact(contact);
    }
    else if (action == SRV_PHB_VCARD_ADD || action == SRV_PHB_VCARD_UPDATE)
    {
        vp = vcard_open_parser(file_path, VCARD_PROPERTY_ALL, NULL);
        if (!vp)
        {
            mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_ERROR, store_index);
            return;
        }

        vcard_set_parse_charset(vp, charset);

        result = vcard_parse(vp, &vcard_data_p);
        if (result == VCARD_RESULT_FAIL)
        {
            vcard_close_parser(vp);
            mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_ERROR, store_index);
            return;
        }
        contact = srv_phb_vcard_object_to_contact(NULL, vcard_data_p);
        vcard_close_parser(vp);

        if (action == SRV_PHB_VCARD_ADD)
        {
            add_req.cb = srv_phb_sync_vcard_hdlr;
            add_req.contact = contact;
            add_req.storage = PHB_STORAGE_NVRAM;
            add_req.record_index = SRV_PHB_INVALID_INDEX;
            add_req.mode = SRV_PHB_UPDATE_MODE_IMPORT;
            add_req.user_data = NULL;
            srv_phb_add_contact(&add_req);
        }
        else
        {
            upd_req.cb = srv_phb_sync_vcard_hdlr;
            upd_req.contact = contact;
            upd_req.id = store_index;
            upd_req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
            upd_req.user_data = NULL;
            upd_req.update_field = MMI_PHB_CONTACT_FIELD_ALL;
            srv_phb_update_contact(&upd_req);
        }
        srv_phb_free_contact(contact);
    }
    else if (action == SRV_PHB_VCARD_DELETE)
    {
        del_req.cb = srv_phb_sync_vcard_hdlr;
        del_req.id = store_index;
        del_req.user_data = NULL;
        srv_phb_delete_contact(&del_req);
    }
    #else /* __MMI_VCARD__ */
    mmi_syncml_phb_sync_rsp(SRV_PHB_SYNC_NOT_SUPPORT, store_index);
    #endif /* __MMI_VCARD__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_sync_get_record_size
 * DESCRIPTION
 *  This function is used to get PHB record size which SyncML can support.
 * PARAMETERS
 *  void
 * RETURNS
 *  PHB record size
 *****************************************************************************/
U16 srv_phb_sync_get_record_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_size;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    record_size = sizeof(mmi_phb_name_struct) + sizeof(mmi_phb_optional_fields_struct) + sizeof(mmi_phb_info_struct);

#if defined(__MMI_VOIP__)
    record_size -= VOIP_URI_LEN;
#endif

#if defined(__MMI_IMPS__)
/* under construction !*/
#endif

#if defined(__MMI_PHB_MSN_FIELD__)
    record_size -= MMI_PHB_EMAIL_LENGTH + 1;
#endif

    return record_size;
}

#endif /* __SYNCML_SUPPORT__ */

#if defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_VCARD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* __MMI_VCARD__ */
/* under construction !*/
#endif /* __MMI_VCARD__ */
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IMPS__) && defined(IMPS_WV13_ENHANCEMENT) */

#if defined(__MMI_VCARD__)


/*****************************************************************************
 * FUNCTION
 *  srv_phb_build_vcard
 * DESCRIPTION
 *  This function is used to build vCard.
 * PARAMETERS
 *  file_path:          [IN]        vCard file path
 *  store_index:        [IN]        Store index
 *  is_append:          [IN]        write file from tail or not
 * RETURNS
 *  S32                             write result
 *****************************************************************************/
S32 srv_phb_build_vcard(U16 *file_path, U16 store_index, MMI_BOOL is_append, U8 vcard_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct *contact_p;
    vcard_object_struct vcard_data;
    VB_HANDLE vb;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_p = srv_phb_field_malloc(SRV_PHB_ENTRY_FIELD_VCARD);

    if (srv_phb_oplib_get_contact_info(store_index, contact_p) != SRV_PHB_NO_ERROR)
    {
        srv_phb_field_free(SRV_PHB_ENTRY_FIELD_VCARD, contact_p);
        return VCARD_NO_ERROR;
    }

    vb = vcard_open_builder(file_path, ((is_append == MMI_TRUE) ? VCARD_OPEN_MODE_APPEND : VCARD_OPEN_MODE_DEFAULT), &result);
    if (!vb)
    {
        srv_phb_field_free(SRV_PHB_ENTRY_FIELD_VCARD, contact_p);
        return result;
    }

    /* Convert contact info to vcard data */
    memset(&vcard_data, 0, sizeof(vcard_object_struct));
    srv_phb_convert_to_vcard_object(contact_p, &vcard_data);

    if (vcard_format == 1)
    {
        vcard_set_build_version(vb, VCARD_VERSION_3_0);
    }
    vcard_set_build_mode(vb, VCARD_BUILD_MODE_TEL_ALWAYS);

    result = vcard_build(vb, &vcard_data);
    if (result == VCARD_RESULT_FAIL)
    {
        result = vcard_get_build_error(vb);
        vcard_close_builder(vb);
        srv_phb_field_free(SRV_PHB_ENTRY_FIELD_VCARD, contact_p);
        return result;
    }

    vcard_close_builder(vb);

    srv_phb_field_free(SRV_PHB_ENTRY_FIELD_VCARD, contact_p);
    return VCARD_NO_ERROR;
}



/*****************************************************************************
 * FUNCTION
 *  srv_phb_build_vcard
 * DESCRIPTION
 *  This function is used to build vCard.
 * PARAMETERS
 *  file_path:          [IN]        vCard file path
 *  store_index:        [IN]        Store index
 *  is_append:          [IN]        write file from tail or not
 * RETURNS
 *  S32                             write result
 *****************************************************************************/
S32 srv_contact_build_vcard(U16 *file_path, U16 store_index, MMI_BOOL is_append, U8 vcard_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact contact = NULL;
    vcard_object_struct vcard_data;
    VB_HANDLE vb;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact = srv_phb_create_contact(NULL);

    if (srv_phb_read_contact(store_index, NULL, contact) == NULL)
    {
        srv_phb_free_contact(contact);
        return VCARD_NO_ERROR;
    }

    vb = vcard_open_builder(file_path, ((is_append == MMI_TRUE) ? VCARD_OPEN_MODE_APPEND : VCARD_OPEN_MODE_DEFAULT), &result);
    if (!vb)
    {
        srv_phb_free_contact(contact);
        return result;
    }

    /* Convert contact info to vcard data */
    memset(&vcard_data, 0, sizeof(vcard_object_struct));
    srv_phb_contact_to_vcard_object(contact, &vcard_data);

    if (vcard_format == 1)
    {
        vcard_set_build_version(vb, VCARD_VERSION_3_0);
    }
    vcard_set_build_mode(vb, VCARD_BUILD_MODE_TEL_ALWAYS);

    result = vcard_build(vb, &vcard_data);
    if (result == VCARD_RESULT_FAIL)
    {
        result = vcard_get_build_error(vb);
        vcard_close_builder(vb);
        srv_phb_free_contact(contact);
        return result;
    }

    vcard_close_builder(vb);

    srv_phb_free_contact(contact);
    return VCARD_NO_ERROR;
}

#endif /* defined(__MMI_VCARD__) */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_name_by_number
 * DESCRIPTION
 *  This function is used to get PHB name by the given number. It will call SSE API to search
 *  the number.
 *  If the search ok, but name is empty, or if the search fails, we will fill in name[out] with '\0'.
 * PARAMETERS
 *  number:             [IN]        Number to search
 *  name:               [OUT]       Name to store the search result
 *  len:                [IN]        Name length
 * RETURN VALUES
 *  MMI_TRUE:           Number found
 *  MMI_FALSE:          Number not found
 *****************************************************************************/
MMI_BOOL srv_phb_get_name_by_number(U16 *number, U16 *name, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_oplib_search(number, SRV_PHB_SEARCH_TYPE_NUM);
    if (result >= 0)
    {
        srv_phb_datamgr_get_name((U16) result, name, len);
        return MMI_TRUE;
    }

    name[0] = 0;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_store_index_by_number
 * DESCRIPTION
 *  This function is used to get store index by the given number. It will call SSE API to search
 *  the number. Then you can use store index to get PHB name.
 * PARAMETERS
 *  number:             [IN]        Number to search
 *  store_index:        [OUT]       Store index to store the search result
 * RETURN VALUES
 *  MMI_TRUE:           Number found
 *  MMI_FALSE:          Number not found
 *****************************************************************************/
MMI_BOOL srv_phb_get_store_index_by_number(U16 *number, U16 *store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_oplib_search(number, SRV_PHB_SEARCH_TYPE_NUM);
    if (result >= 0)
    {
        *store_index = (U16) result;
        return MMI_TRUE;
    }

    *store_index = 0xFFFF;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_invalid_number_id
 * DESCRIPTION
 *  This function is used to set number id as invalid value
 * PARAMETERS
 *  phb_id:        [IN]        phb number id to set
 * RETURNS
 *  Number id
 *****************************************************************************/
void srv_phb_set_invalid_number_id(SRV_PHB_ID* phb_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(phb_id, 0XFF, sizeof(SRV_PHB_ID));
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_check_number_id
 * DESCRIPTION
 *  This function is used to check a number's id is valid
 * PARAMETERS
 *  phb_id:        [IN]        phb number id to check
 * RETURNS
 *  MMI_TRUE:           valid
 *  MMI_FALSE:          invalid
 *****************************************************************************/
MMI_BOOL srv_phb_check_number_id(SRV_PHB_ID phb_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (phb_id.storage_type == PHB_PHONEBOOK)
    {
        if (srv_phb_datamgr_check_store_index(phb_id.contact_index, MMI_PHB_CONTACT_FIELD_NUMBER))
        {
            CHAR* temp = srv_phb_datamgr_get_number(phb_id.contact_index, phb_id.number_index, NULL);
            if (temp && temp[0])
            {
                return MMI_TRUE;
            }
        }
    }
    else if (phb_id.storage_type == PHB_FDN)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_create_number_id
 * DESCRIPTION
 *  This function is used to create a number's id
 * PARAMETERS
 *  storage_type:        [IN]        PHB_FDN or PHB_PHONEBOOK, refer phb_type_enum
 *  store_index:         [IN]        contact store_index
 *  number_index:        [IN]        SRV_PHB_ENTRY_FIELD_NUMBER or SRV_PHB_ENTRY_FIELD_OPTIONAL_NUM_1 or
 *                                   SRV_PHB_ENTRY_FIELD_OPTIONAL_NUM_2 orSRV_PHB_ENTRY_FIELD_OPTIONAL_NUM_3
 * RETURNS
 *  Number id
 *****************************************************************************/
SRV_PHB_ID srv_phb_create_number_id(U8 storage_type, U16 store_index, U8 number_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PHB_ID id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    id.contact_index = store_index;
    id.storage_type = storage_type;
    switch (number_index)
    {
        case SRV_PHB_ENTRY_FIELD_NUMBER:
            id.number_index = 0;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            id.number_index = 1;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            id.number_index = 2;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            id.number_index = 3;
            break;
            
        default:
            break;
    }
    return id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_name_by_number_id
 * DESCRIPTION
 *  This function is used to get contact's store_index by number id
 * PARAMETERS
 *  number_id:             [IN]       number id
 * RETURNS
 *  store_index
 *****************************************************************************/
U16 srv_phb_get_store_index_by_number_id(SRV_PHB_ID number_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return number_id.contact_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_name_by_number_id
 * DESCRIPTION
 *  This function is used to get contact's name by number id
 * PARAMETERS
 *  name:                  [OUT]        name data
 *  number_id:             [IN]       number id
 *  max_len:               [IN]        max Name length
 * RETURN VALUES
 *  MMI_TRUE:           Got name
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_name_by_number_id(U16 *name, SRV_PHB_ID number_id, U16 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number_id.storage_type != PHB_PHONEBOOK)
    {
        name[0] = 0;
        return MMI_FALSE;
    }
    return srv_phb_get_name(number_id.contact_index, name, max_len);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_number_by_number_id
 * DESCRIPTION
 *  This function is used to get contact's number by number id
 * PARAMETERS
 *  number:             [OUT]       number data
 *  number_id:          [IN]        number id
 *  len:                [IN]        max number length
 * RETURN VALUES
 *  MMI_TRUE:           Got number
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_number_by_number_id(U16 *number, SRV_PHB_ID number_id, U16 max_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    if (number_id.storage_type != PHB_PHONEBOOK)
    {
        number[0] = 0;
        return MMI_FALSE;
    }
    return srv_phb_get_number_ex(number_id.contact_index, number_id.number_index, number, NULL, max_len);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_number_id_check_modify
 * DESCRIPTION
 *  This function is used to check a number id's number is modified
 * PARAMETERS
 *  number:             [IN]      old number data
 *  number_id:          [IN]      contact number's id
 *  store_index:        [IN]      modified contact's store_index
 *  contact:            [IN]      modified contact's info
 * RETURN VALUES
 *  MMI_TRUE:           modified
 *  MMI_FALSE:          Not modified
 *****************************************************************************/
MMI_BOOL srv_phb_number_id_check_modify(WCHAR *number, SRV_PHB_ID number_id, mmi_phb_contact_id id, srv_phb_contact contact)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_number_struct* temp = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((number_id.storage_type != PHB_PHONEBOOK) ||
        (number_id.contact_index != id) ||
        !contact ||
        !number ||
        !(number[0]))
    {
        return MMI_FALSE;
    }
    temp = srv_phb_contact_get_number_by_save_index(contact, number_id.number_index);
    if (temp && (srv_phb_compare_number(number, temp->number) == MMI_FALSE))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_create_cm_user_data_ex
 * DESCRIPTION
 *  This function is used to create cm user data before making call.
 * PARAMETERS
 *  name:               [IN]        Caller name
 *  number:             [IN]        Caller number
 * RETURNS
 *  App user data
 *****************************************************************************/
void *srv_phb_create_cm_user_data_ex(U16 *name, U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index = SRV_PHB_INVALID_INDEX;
    U32 number_index = 0;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (name && number)
    {
        result = srv_phb_sse_search_num(number, &number_index);
        if (result >= 0)
        {
            U16 temp_name[MMI_PHB_NAME_LENGTH + 1];
            store_index = (U16) result;
            srv_phb_get_name(store_index, temp_name, MMI_PHB_NAME_LENGTH);
            if (mmi_wcscmp(name, temp_name) != 0)
            {
                store_index = SRV_PHB_INVALID_INDEX;
            }
            else
            {
                name = NULL;
            }
        }
    }
    return srv_phb_create_cm_user_data(name, number_index, store_index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_create_cm_user_data
 * DESCRIPTION
 *  This function is used to create cm user data before making call.
 *  App must set name or store index to this data so that PHB will search the right name.
 *  App must keep this pointer until call disconnected.
 * PARAMETERS
 *  name:               [IN]       Caller name
 *  number_type:        [IN]       Caller number type
 *  store_index:        [IN]       Caller store index
 * RETURNS
 *  App user data
 *****************************************************************************/
void *srv_phb_create_cm_user_data(U16 *name, U32 number_index, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_cm_user_data_struct *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data =
        (srv_phb_cm_user_data_struct*) srv_phb_mem_malloc(sizeof(srv_phb_cm_user_data_struct), SRV_PHB_MEMORY_TYPE_CTR);
    user_data->magic_head = SRV_PHB_MAGIC_NUM;
    if (name && name[0])
    {
        mmi_wcsncpy(user_data->name, name, MMI_PHB_NAME_LENGTH);
        user_data->store_index = SRV_PHB_INVALID_INDEX;
    }
    else
    {
        user_data->name[0] = 0;
        user_data->store_index = store_index;
    }
    switch (number_index)
    {
        case SRV_PHB_ENTRY_FIELD_NUMBER:
            user_data->number_index = 0;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            user_data->number_index = 1;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            user_data->number_index = 2;
            break;
            
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            user_data->number_index = 3;
            break;
            
        default:
            break;
    }
    user_data->ref_count = 1;
    return user_data;
}


void *srv_phb_create_cm_user_data_by_sub_id(U16 *name, U32 number_sub_id, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_cm_user_data_struct *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data =
        (srv_phb_cm_user_data_struct*) srv_phb_mem_malloc(sizeof(srv_phb_cm_user_data_struct), SRV_PHB_MEMORY_TYPE_CTR);
    user_data->magic_head = SRV_PHB_MAGIC_NUM;
    if (name && name[0])
    {
        mmi_wcsncpy(user_data->name, name, MMI_PHB_NAME_LENGTH);
        user_data->store_index = SRV_PHB_INVALID_INDEX;
    }
    else
    {
        user_data->name[0] = 0;
        user_data->store_index = store_index;
    }
    user_data->number_index = number_sub_id;
    user_data->ref_count = 1;
    return user_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_create_cm_user_data_by_id
 * DESCRIPTION
 *  This function is used to create cm user data before making call.
 *  App must set phb id to this data so that PHB will search the right name.
 *  App must keep this pointer until call disconnected.
 * PARAMETERS
 *  phb_id:               [IN]       phb id
 * RETURNS
 *  App user data
 *****************************************************************************/
void *srv_phb_create_cm_user_data_by_id(SRV_PHB_ID phb_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_cm_user_data_struct *user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    user_data =
        (srv_phb_cm_user_data_struct*) srv_phb_mem_malloc(sizeof(srv_phb_cm_user_data_struct), SRV_PHB_MEMORY_TYPE_CTR);
    user_data->magic_head = SRV_PHB_MAGIC_NUM;
    user_data->name[0] = 0;
    if (phb_id.storage_type == PHB_PHONEBOOK)
    {
        user_data->store_index = phb_id.contact_index;
        user_data->number_index = (U32)(phb_id.number_index);
    }
    else
    {
        user_data->store_index = SRV_PHB_INVALID_INDEX;
    }
    user_data->ref_count = 1;
    return user_data;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_hold_cm_user_data
 * DESCRIPTION
 *  This function is used to hold on cm user data.
 * PARAMETERS
 *  user_data:          [IN]        App user data
 * RETURN VALUES
 *  MMI_TRUE:           Hold on
 *  MMI_FALSE:          Fails
 *****************************************************************************/
MMI_BOOL srv_phb_hold_cm_user_data(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_cm_user_data_struct *cm_data = (srv_phb_cm_user_data_struct*) user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cm_data && cm_data->magic_head == SRV_PHB_MAGIC_NUM)
    {
        cm_data->ref_count++;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_destory_cm_user_data
 * DESCRIPTION
 *  This function is used to destroy cm user data after call disconnected.
 * PARAMETERS
 *  user_data:          [IN]        App user data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_destory_cm_user_data(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_cm_user_data_struct *cm_data = (srv_phb_cm_user_data_struct*) user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_data->ref_count--;
    if (cm_data->ref_count > 0)
    {
        return;
    }
    srv_phb_mem_free(user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_caller_info_by_number
 * DESCRIPTION
 *  This function is used to get caller info by number. As general, it is called by CM
 *  to show in-call screen with PHB name.
 * PARAMETERS
 *  cm_param:           [IN]        Number input by CM
 *  phb_info:           [OUT]       Caller info output by PHB
 * RETURN VALUES
 *  MMI_TRUE:           Number found
 *  MMI_FALSE:          Number not found
 *****************************************************************************/
MMI_BOOL srv_phb_get_caller_info_by_number(
            srv_phb_cm_number_struct *cm_param,
            srv_phb_caller_info_struct *phb_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 store_index;
    MMI_BOOL flag = MMI_FALSE;
    U8 *ecc_display_ptr;
    srv_phb_cm_user_data_struct *cm_data;
    srv_phb_contact_info_struct *contact_info;
#ifdef __MMI_PHB_CALLER_GROUP__
    mmi_phb_group_info_struct *group_info;
    U32 group_mask;
#endif /* __MMI_PHB_CALLER_GROUP__ */
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(phb_info, 0, sizeof(srv_phb_caller_info_struct));
    phb_info->image_id = IMG_PHB_DEFAULT;   /* Set default image */
    srv_phb_set_invalid_number_id(&(phb_info->phb_id));

    if (cm_param->is_mo_call)
    {
        phb_info->res_type |= SRV_PHB_RES_TYPE_IMAGE_ID; 
        /* ECC number verify, we will use the name found in EFecc */
        if (ecc_custom_verify_emergency_number(
                (U8*) cm_param->number,
                (U8) mmi_wcslen(cm_param->number),
                ECC_ENCODING_UCS2,
                (ecc_call_type_enum) cm_param->call_type,
                NULL,
                &ecc_display_ptr,
                NULL))
        {
            if (mmi_ucs2strlen((CHAR*) ecc_display_ptr) == 0)
            {
                mmi_ucs2ncpy((CHAR*) phb_info->name, GetString(STR_EMERGENCY_NUMBER), MMI_PHB_NAME_LENGTH);
            }
            else
            {
                mmi_ucs2ncpy((CHAR*) phb_info->name, (CHAR*) ecc_display_ptr, MMI_PHB_NAME_LENGTH);
            }
            return MMI_TRUE;
        }

        /* We will use the name set by user before making call */
        if (cm_param->user_data)
        {
            cm_data = (srv_phb_cm_user_data_struct*) cm_param->user_data;
            if (cm_data->magic_head == SRV_PHB_MAGIC_NUM)
            {
                if (cm_data->name && cm_data->name[0])
                {
                    /* XDN will use it */
                    mmi_wcscpy(phb_info->name, cm_data->name);
                    return MMI_TRUE;
                }
                else
                {
                    store_index = cm_data->store_index;
                    if (store_index == SRV_PHB_INVALID_INDEX)
                    {
                        return MMI_FALSE;
                    }
                    phb_info->phb_id.number_index = (U8)(cm_data->number_index);
                    flag = MMI_TRUE;
                }
            }
        }
    }

    /* We will try to search the name when user doesn't set it before making call */
    if (!flag)
    {
        U32 number_index;
        if (cm_param->is_voip_call)
        {
            return MMI_FALSE;
        }

        result = srv_phb_sse_search_num(cm_param->number, &number_index);
        if (result >= 0
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
        && (srv_phb_get_storage(result) != PHB_STORAGE_TCARD || srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
        #endif
        )
        {
            phb_info->phb_id.number_index = (U8)number_index;
            store_index = (U16) result;
            flag = MMI_TRUE;
        }
    }

    if (flag)
    {
        /* Get the detailed contact info, such as name, caller res, group info */
        contact_info = srv_phb_mem_malloc(sizeof(srv_phb_contact_info_struct), SRV_PHB_MEMORY_TYPE_CTR);
        contact_info->field_mask = SRV_PHB_ENTRY_FIELD_NAME | SRV_PHB_ENTRY_FIELD_RES | SRV_PHB_ENTRY_FIELD_GROUP;
        contact_info->field_data.name = phb_info->name;
        contact_info->field_data.l_name = NULL;
        contact_info->field_data.ringtone_path = srv_phb_mem_malloc((SRV_FMGR_PATH_MAX_LEN + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);
        contact_info->field_data.image_path = NULL;
    #if defined(__MMI_PHB_CALLER_VIDEO__)
        contact_info->field_data.video_path = NULL;
    #endif
        result = srv_phb_oplib_get_contact_info(store_index, contact_info);
        if (result == SRV_PHB_NO_ERROR)
        {
            srv_phb_get_number_ex(store_index, phb_info->phb_id.number_index, NULL, (U8*)(&phb_info->number_type), 0);
            phb_info->phb_id.storage_type = PHB_PHONEBOOK;
            phb_info->phb_id.contact_index = store_index;
            phb_info->ringtone_id = contact_info->field_data.ringtone_id;
            phb_info->image_id = contact_info->field_data.image_id;
        #if defined(__MMI_PHB_CALLER_VIDEO__)
            phb_info->video_id = contact_info->field_data.video_id;
        #endif
            phb_info->res_type = contact_info->field_data.res_type;
            if (contact_info->field_data.image_id == IMG_PHB_DEFAULT)
            {
                phb_info->res_type &= ~SRV_PHB_RES_TYPE_IMAGE_ID;
            }
        #if defined(__MMI_FILE_MANAGER__)
            if ((phb_info->res_type & SRV_PHB_RES_TYPE_RING_FILE) && srv_fmgr_fs_path_exist(contact_info->field_data.ringtone_path) != 0)
            {
                phb_info->res_type &= ~SRV_PHB_RES_TYPE_RING_FILE;
            }
        #endif /* defined(__MMI_FILE_MANAGER__) */
        #ifdef __MMI_PHB_CALLER_GROUP__
            group_mask = contact_info->field_data.group_mask;
            if (group_mask)
            {
                /* We will try to get the group info, such as alert, backlight */
                group_info = srv_phb_mem_malloc(sizeof(mmi_phb_group_info_struct), SRV_PHB_MEMORY_TYPE_CTR);
                result = srv_phb_get_pri_group_info(group_mask, group_info);
                if (result == SRV_PHB_NO_ERROR)
                {
                    /* The priority of contact is higher than group's priority */
                    if (!(phb_info->res_type & SRV_PHB_RES_TYPE_RING))
                    {
                        phb_info->ringtone_id = group_info->ringtone_id;
                        phb_info->res_type |= (group_info->res_type & SRV_PHB_RES_TYPE_RING);
                    }
                    if (!(phb_info->res_type & SRV_PHB_RES_TYPE_VISUAL))
                    {
                        phb_info->image_id = group_info->image_id;
                        phb_info->res_type |= (group_info->res_type & SRV_PHB_RES_TYPE_IMAGE);
                    #if defined(__MMI_PHB_CALLER_VIDEO__)
                        phb_info->video_id = group_info->video_id;
                        phb_info->res_type |= (group_info->res_type & SRV_PHB_RES_TYPE_VIDEO);
                    #endif /* defined(__MMI_PHB_CALLER_VIDEO__) */
                    }
                    else if (!(phb_info->res_type & SRV_PHB_RES_TYPE_IMAGE))
                    {
                        phb_info->image_id = group_info->image_id;
                        phb_info->res_type |= (group_info->res_type & SRV_PHB_RES_TYPE_IMAGE);
                    }
                }
                srv_phb_mem_free(group_info);
            }
        #endif /* __MMI_PHB_CALLER_GROUP__ */
        }
        srv_phb_mem_free(contact_info->field_data.ringtone_path);
        srv_phb_mem_free(contact_info);
        return MMI_TRUE;
    }
    else
    {
        /* We will try to search the name in FDN list */
        store_index = srv_phb_xmgnt_search_fdn_by_number(cm_param->sim_interface, cm_param->number, phb_info->name);
        if (store_index != 0xFFFF)
        {
           // phb_info->phb_id.storage_type = PHB_FDN;
          //  phb_info->phb_id.contact_index = store_index;
            return MMI_TRUE;
        }
    }

    phb_info->name[0] = 0;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_caller_res_info
 * DESCRIPTION
 *  This function is used to init caller res info
 * PARAMETERS
 *  res_info:           [IN/OUT]       Caller res info
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_phb_init_caller_res_info(srv_phb_caller_res_info_struct *res_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_info->pic_id = 0;
    res_info->pic_path[0] = 0;
#ifdef __MMI_PHB_CALLER_VIDEO__
    res_info->video_id = 0;
    res_info->video_path[0] = 0;
#endif
    res_info->ringtone_id = 0;
    res_info->ringtone_path[0] = 0;
    res_info->res_type = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_caller_res_info_by_id
 * DESCRIPTION
 *  This function is used to get caller res info by id. As general, it is called by CM
 *  to show in-call screen with image or video from PHB.
 * PARAMETERS
 *  res_id:             [IN]        Caller res id input by CM
 *  res_info:           [OUT]       Caller res info output by PHB
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_get_caller_res_info_by_id(
        srv_phb_caller_res_id_struct *res_id,
        srv_phb_caller_res_info_struct *res_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_init_caller_res_info(res_info);
    for (i = 0; i < SRV_PHB_CALLER_RES_TYPE_TOTAL; i++)
    {
        switch (i)
        {
            case SRV_PHB_CALLER_RES_TYPE_IMAGE:
                #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
                if (res_id->image_id & 0x8000 && res_id->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE)
                {
                    if (res_id->image_id & 0x4000)
                    {
                        srv_phb_group_info_struct group_info;
                        srv_phb_get_tcard_group_info((res_id->image_id - 0xC000), &group_info);
                        mmi_wcscpy(res_info->pic_path, group_info.image_path);
                    }
                    else
                    {
                        U16 res_type;
                        srv_phb_get_tcard_image((res_id->image_id - 0x8000), NULL, res_info->pic_path, &res_type);
                    }
                    res_info->res_type |= SRV_PHB_RES_TYPE_IMAGE_FILE;
                }
                else
                #endif
                #if defined(__SRV_PHB_CALLER_RES_DATA_STORE__)
                if ((res_id->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE) &&
                    srv_phb_datamgr_get_res_path(
                        MMI_PHB_CONTACT_FIELD_IMAGE,
                        res_id->image_id, 
                        (U16)(res_id->res_type & SRV_PHB_RES_TYPE_IMAGE_FILE),
                        res_info->pic_path))
                {
                    res_info->res_type |= res_id->res_type & SRV_PHB_RES_TYPE_IMAGE;
                }
                else
                #endif /* defined(__SRV_PHB_CALLER_RES_DATA_STORE__) */
                if (res_id->res_type & SRV_PHB_RES_TYPE_IMAGE_ID)
                {
                    res_info->pic_id = res_id->image_id;
                    res_info->res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
                }
                break;

            case SRV_PHB_CALLER_RES_TYPE_VIDEO:
            #ifdef __MMI_PHB_CALLER_VIDEO__
                if ((res_id->res_type & SRV_PHB_RES_TYPE_VIDEO) &&
                    srv_phb_datamgr_get_res_path(
                        MMI_PHB_CONTACT_FIELD_VIDEO,
                        res_id->video_id,
                        (U16)(res_id->res_type & SRV_PHB_RES_TYPE_VIDEO_FILE),
                        res_info->video_path))
                {
                    res_info->video_id = (res_id->video_id & 0x3FFF);
                    res_info->res_type |= (res_id->res_type & (SRV_PHB_RES_TYPE_VIDEO | SRV_PHB_RES_TYPE_VIDEO_SOUND_ON));
                }
            #endif /* __MMI_PHB_CALLER_VIDEO__ */
                break;

            case SRV_PHB_CALLER_RES_TYPE_RING:
                if (res_id->res_type & SRV_PHB_RES_TYPE_AUDIO_RING_FILE)
                {
                    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
                    if (res_id->ringtone_id & 0x8000)
                    {
                        if (res_id->ringtone_id & 0x4000)
                        {
                            srv_phb_group_info_struct group_info;
                            srv_phb_get_tcard_group_info((res_id->image_id - 0xC000), &group_info);
                            mmi_wcscpy(res_info->ringtone_path, group_info.ringtone_path);
                        }
                        else
                        {
                            U16 res_type;
                            srv_phb_get_tcard_ringtone((res_id->ringtone_id - 0x8000), NULL, res_info->ringtone_path, &res_type);
                        }
                        res_info->res_type |= SRV_PHB_RES_TYPE_AUDIO_RING_FILE;
                    }
                    else
                    #endif
                    if(srv_phb_datamgr_get_res_path(
                            MMI_PHB_CONTACT_FIELD_RING,
                            res_id->ringtone_id, 
                            (U16)(res_id->res_type & SRV_PHB_RES_TYPE_RING_FILE),
                            res_info->ringtone_path))
                    {
                        res_info->res_type |= SRV_PHB_RES_TYPE_AUDIO_RING_FILE;
                    }
                }
            #ifdef __MMI_PHB_CALLER_VIDEO__
                else if (res_id->res_type & SRV_PHB_RES_TYPE_VIDEO_RING_FILE)
                {
                    if(srv_phb_datamgr_get_res_path(
                            SRV_PHB_ENTRY_FIELD_RING,
                            res_id->ringtone_id, 
                            (U16)(res_id->res_type & SRV_PHB_RES_TYPE_RING_FILE),
                            res_info->video_path))
                    {
                        res_info->res_type |= (SRV_PHB_RES_TYPE_VIDEO_FILE | SRV_PHB_RES_TYPE_VIDEO_SOUND_ON);
                    }   
                }
            #endif
                else if (res_id->res_type & SRV_PHB_RES_TYPE_RING_ID)
                {
                    res_info->ringtone_id = res_id->ringtone_id;
                    res_info->res_type |= SRV_PHB_RES_TYPE_RING_ID;
                }
                break;

            default :
                break;
        }
    }
    if (!(res_info->res_type & SRV_PHB_RES_TYPE_IMAGE))
    {
    #if defined(__MMI_VIDEO_TELEPHONY__)
        if (res_id->call_type == SRV_UCM_VIDEO_CALL_TYPE ||
            res_id->call_type == SRV_UCM_VIDEO_CALL_TYPE_SIM2)
        {
            res_info->pic_id = IMG_PHB_VIDEO_DEFAULT;
        }
        else
    #endif /* defined(__MMI_VIDEO_TELEPHONY__) */
        {
            res_info->pic_id = IMG_PHB_DEFAULT;
        }
        res_info->res_type |= SRV_PHB_RES_TYPE_IMAGE_ID;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_preferred_sim
 * DESCRIPTION
 *  get last used sim id from a contact
 * PARAMETERS
 *  number    : [IN]    number to search
 *  id           :  [IN]    contact id, if you do not use this param, please set MMI_PHB_INVALID_CONTACT_ID
 *  op_type   : [IN]    please refer to srv_phb_number_op_type_enum
 *  sim_id     : [OUT] mmi_sim_enum
 * RETURNS
 *
 *  SRV_PHB_NO_ERROR             :                   success
 *  SRV_PHB_NOT_FOUND           :                   no number matched
 *  SRV_PHB_NUM_NOT_READY    :                   lookup table not ready
*****************************************************************************/
S32 srv_phb_get_preferred_sim (
                U16 *number,
                mmi_phb_contact_id id,
                srv_phb_number_op_type_enum op_type,
                mmi_sim_enum *sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 number_index = 0;
    U32 sim_index;
    S32 result;
    U8 storage;
    CHAR old_imsi[SRV_MAX_IMSI_LEN + 1];
    CHAR new_imsi[SRV_MAX_IMSI_LEN + 1];
    MMI_BOOL compare_result = MMI_FALSE;
    srv_phb_number_struct* query_number;
    srv_phb_field_filter filter;
    srv_phb_contact contact;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *sim_id = MMI_SIM_NONE;
    if (srv_phb_startup_is_phb_ready() == MMI_FALSE)
    {
        return SRV_PHB_NOT_READY;
    }
    if (id != MMI_PHB_INVALID_CONTACT_ID)
    {
        filter = srv_phb_create_field_filter_ext(MMI_PHB_CONTACT_FIELD_NUMBER);
        contact = srv_phb_read_contact(id, filter, NULL);
        compare_result = srv_phb_contact_find_number(contact, number, &number_index);
        srv_phb_free_contact(contact);
        if (compare_result == MMI_FALSE)
        {
            return SRV_PHB_NOT_FOUND;
        }
        result = id;
    }
    else
    {
        result = srv_phb_sse_search_num(number, &number_index);
    }

    if (result >= 0)
    {
        storage = srv_phb_get_storage(result);
        if (storage == PHB_STORAGE_NVRAM 
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
            || storage == PHB_STORAGE_TCARD
        #endif
        )
        {
            if (storage == PHB_STORAGE_TCARD && !srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
            {
                return SRV_PHB_NOT_FOUND;
            }
            filter = srv_phb_create_field_filter_ext(MMI_PHB_CONTACT_FIELD_NUMBER);
            contact = srv_phb_read_contact(result, filter, NULL);
            query_number = srv_phb_contact_get_number_by_save_index(contact, number_index);
            if (query_number == NULL)
            {
                return SRV_PHB_NOT_FOUND;
            }
            *sim_id = (mmi_sim_enum)(query_number->last_used_sim & op_type);
            if (op_type == SRV_PHB_NUMBER_OP_TYPE_MESSAGE)
            {
                *sim_id >>= 4;
            }
            if (*sim_id != MMI_SIM_NONE && *sim_id <= (1 << (MMI_MAX_SIM_NUM - 1)))
            {
                sim_index = mmi_frm_sim_to_index(*sim_id);
                srv_phb_phone_get_sim_imsi(sim_index, old_imsi, SRV_MAX_IMSI_LEN + 1);
                srv_sim_ctrl_get_imsi(*sim_id, new_imsi, SRV_MAX_IMSI_LEN + 1);
                if (strncmp(old_imsi, new_imsi, SRV_MAX_IMSI_LEN + 1) != 0)
                {
                    *sim_id = MMI_SIM_NONE;
                    srv_phb_phone_set_sim_imsi(sim_index, new_imsi, SRV_MAX_IMSI_LEN + 1);
                    srv_phb_set_preferred_sim(number, result, MMI_SIM_NONE, op_type);
                }
            }
            srv_phb_free_field_filter(filter);
            srv_phb_free_contact(contact);
        }
        else
        {
            *sim_id = mmi_frm_index_to_sim(srv_phb_get_sim_id((phb_storage_enum)storage));
        }
        return SRV_PHB_NO_ERROR;
    }
    else
    {
        return SRV_PHB_NOT_FOUND;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_preferred_sim
 * DESCRIPTION
 *  set last used sim for a contact
 * PARAMETERS
 *  number    : [IN]  number to set
 *  id           :  [IN]  contact id, if you do not use this param, please set MMI_PHB_INVALID_CONTACT_ID
 *  sim_id     : [IN]  last used sim id
 *  op_type   : [IN]  operater type of this number, refer to srv_phb_number_op_type_enum
 * RETURNS
 *  SRV_PHB_NO_ERROR          :                      success
 *  SRV_PHB_NOT_FOUND        :                      no number matched
 *  SRV_PHB_NUM_NOT_READY    :                   lookup table not ready
*****************************************************************************/
S32 srv_phb_set_preferred_sim (
               U16 *number,
               mmi_phb_contact_id id,
               mmi_sim_enum sim_id,
               srv_phb_number_op_type_enum op_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_set_preferred_sim_req req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.id = id;
    req.number = number; 
    req.sim_id = sim_id;  
    req.op_type = op_type;
    req.cb = NULL;
    req.user_data = NULL;
    return srv_phb_set_preferred_sim_ex(&req);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_preferred_sim_ex
 * DESCRIPTION
 *  set last used sim for a contact
 * PARAMETERS
 *  req
 * RETURNS
 *  SRV_PHB_NO_ERROR          :                      success
 *  SRV_PHB_NOT_FOUND        :                      no number matched
 *  SRV_PHB_NUM_NOT_READY    :                   lookup table not ready
*****************************************************************************/

S32 srv_phb_set_preferred_sim_ex(srv_phb_set_preferred_sim_req* req)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 number_index = 0;
    S32 result;
    CHAR sim_imsi[SRV_MAX_IMSI_LEN + 1];
    MMI_BOOL compare_result = MMI_FALSE;
    srv_phb_number_struct* query_number;
    srv_phb_contact contact;
    srv_phb_update_req_struct update_req;
    srv_phb_field_filter filter;
    U16 *number = req->number;
    mmi_sim_enum sim_id = req->sim_id;
    mmi_phb_contact_id id = req->id;
    srv_phb_number_op_type_enum op_type = req->op_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_startup_is_phb_ready() == MMI_FALSE)
    {
        return SRV_PHB_NOT_READY;
    }
    if (id != MMI_PHB_INVALID_CONTACT_ID)
    {
        filter = srv_phb_create_field_filter_ext(MMI_PHB_CONTACT_FIELD_NUMBER);
        contact = srv_phb_read_contact(id, filter, NULL);
        compare_result = srv_phb_contact_find_number(contact, number, &number_index);
        srv_phb_free_field_filter(filter);
        srv_phb_free_contact(contact);
        if (compare_result == MMI_FALSE)
        {
            return SRV_PHB_NOT_FOUND;
        }
        result = id;
    }
    else
    {
        result = srv_phb_sse_search_num(number, &number_index);
    }
    if (result >= 0 && 
        (srv_phb_get_storage(result) == PHB_STORAGE_NVRAM
        #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
         || (srv_phb_get_storage(result) == PHB_STORAGE_TCARD && srv_phb_tcard_is_ready())
        #endif
        ))
    {
        contact = srv_phb_read_contact(result, NULL, NULL);
        query_number = srv_phb_contact_get_number_by_save_index(contact, number_index);
        if (sim_id != MMI_SIM_NONE)
        {
            srv_sim_ctrl_get_imsi(sim_id, sim_imsi, SRV_MAX_IMSI_LEN + 1);
            srv_phb_phone_set_sim_imsi(mmi_frm_sim_to_index(sim_id), sim_imsi, SRV_MAX_IMSI_LEN + 1);
        }
        if (op_type == SRV_PHB_NUMBER_OP_TYPE_MESSAGE)
        {
            sim_id <<= 4;
        }
        query_number->last_used_sim &= ~op_type;
        query_number->last_used_sim |= sim_id;
        update_req.id = result;
        update_req.contact = contact;
        update_req.cb = req->cb;
        update_req.mode = SRV_PHB_UPDATE_MODE_REPLACE;
        update_req.update_field = MMI_PHB_CONTACT_FIELD_NUMBER;
        update_req.user_data = req->user_data;
        srv_phb_update_contact(&update_req);
        srv_phb_free_contact(contact);
        return SRV_PHB_NO_ERROR;
    }
    else
    {
        return SRV_PHB_NOT_FOUND;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_field
 * DESCRIPTION
 *  This function is used to get PHB field by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  field:              [OUT]       PHB field
 * RETURN VALUES
 *  MMI_TRUE:           Got field
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_field(U16 store_index, U32 *field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_check_entry_exist(store_index))
    {
        *field = srv_phb_datamgr_get_field_mask(store_index);
        return MMI_TRUE;
    }

    *field = 0;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_name
 * DESCRIPTION
 *  This function is used to get PHB name by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  name:               [OUT]       PHB name
 *  len:                [IN]        Name length
 * RETURN VALUES
 *  MMI_TRUE:           Got name
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_name(U16 store_index, U16 *name, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_check_entry_exist(store_index))
    {
        srv_phb_datamgr_get_name(store_index, name, len);
        return MMI_TRUE;
    }

    *name = 0;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_number
 * DESCRIPTION
 *  This function is used to get PHB mobile number by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  number:             [OUT]       PHB mobile number
 *  len:                [IN]        Mobile number length
 * RETURN VALUES
 *  MMI_TRUE:           Got number
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_number(U16 store_index, U16 *number, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_get_number_ex(store_index, 0, number, NULL, len);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_number
 * DESCRIPTION
 *  This function is used to get PHB mobile number by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  number:             [OUT]       PHB mobile number
 *  len:                [IN]        Mobile number length
 * RETURN VALUES
 *  MMI_TRUE:           Got number
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_number_ex(U16 store_index, U8 num_index, WCHAR *number, U8* type, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_phb_datamgr_check_store_index(store_index, MMI_PHB_CONTACT_FIELD_NUMBER))
    {
        CHAR* temp = srv_phb_datamgr_get_number(store_index, num_index, type);
        if (number && temp)
        {
            mmi_asc_n_to_wcs(number, temp, len);
        }
        return MMI_TRUE;
    }
    if (number)
    {
        *number = 0;
    }
    if (type)
    {
        *type = 0;
    }
    return MMI_FALSE;
}


#if defined(__MMI_PHB_BIRTHDAY_FIELD__)


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_birthday
 * DESCRIPTION
 *  This function is used to get PHB birthday by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  year:               [OUT]       Birthday year
 *  month:              [OUT]       Birthday month
 *  day:                [OUT]       Birthday day
 * RETURN VALUES
 *  MMI_TRUE:           Got birthday
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_birthday(U16 store_index, U16 *year, U8 *month, U8 *day)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info.field_mask = SRV_PHB_ENTRY_FIELD_BDAY;

    result = srv_phb_oplib_get_contact_info(store_index, &contact_info);
    if (result == SRV_PHB_NO_ERROR)
    {
        *year = contact_info.field_data.b_year;
        *month = contact_info.field_data.b_month;
        *day = contact_info.field_data.b_day;
        return MMI_TRUE;
    }

    return MMI_FALSE;
}

#endif /* defined(__MMI_PHB_BIRTHDAY_FIELD__) */


#ifdef __MMI_PHB_OPTIONAL_FIELD__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_home_number
 * DESCRIPTION
 *  This function is used to get PHB home number by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  number:             [OUT]       PHB home number
 *  len:                [IN]        Home number length
 * RETURN VALUES
 *  MMI_TRUE:           Got home number
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_optional_number(U16 store_index, U32 field_flag, WCHAR* number, mmi_phb_num_type_enum *type, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 num_index;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (field_flag)
    {
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            num_index = 1;
            break;

        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            num_index = 2;
            break;

        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            num_index = 3;
            break;

        default:
            if (number)
            {
                number[0] = 0;
            }
            return MMI_FALSE;
    }
    return srv_phb_get_number_ex(store_index, num_index, number, (U8*)type, len);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_home_number
 * DESCRIPTION
 *  This function is used to get PHB home number by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  number:             [OUT]       PHB home number
 *  len:                [IN]        Home number length
 * RETURN VALUES
 *  MMI_TRUE:           Got home number
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_optional_number_order(U16 store_index, U8* number_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;
    mmi_phb_wcs_num_struct temp;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info.field_mask = SRV_PHB_ENTRY_FIELD_OPT_NUM_1;
    contact_info.field_data.opt_num[0] = &temp;
    contact_info.field_data.opt_order = number_order;

    result = srv_phb_oplib_get_contact_info(store_index, &contact_info);
    if (result == SRV_PHB_NO_ERROR)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_email_address
 * DESCRIPTION
 *  This function is used to get PHB email address by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  email:              [OUT]       PHB email address
 *  len:                [IN]        Email address length
 * RETURN VALUES
 *  MMI_TRUE:           Got email address
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_email_address(U16 store_index, U16 *email, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info.field_mask = SRV_PHB_ENTRY_FIELD_EMAIL1;
    contact_info.field_data.email_address =
        srv_phb_mem_malloc((MMI_PHB_EMAIL_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);

    result = srv_phb_oplib_get_contact_info(store_index, &contact_info);
    if (result == SRV_PHB_NO_ERROR)
    {
        mmi_wcsncpy(email, contact_info.field_data.email_address, len);
        srv_phb_mem_free(contact_info.field_data.email_address);
        return MMI_TRUE;
    }

    *email = 0;
    srv_phb_mem_free(contact_info.field_data.email_address);
    return MMI_FALSE;
}


#ifdef __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_email_address2
 * DESCRIPTION
 *  This function is used to get PHB email address2 by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  email:              [OUT]       PHB email address2
 *  len:                [IN]        Email address2 length
 * RETURN VALUES
 *  MMI_TRUE:           Got email address
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_email_address2(U16 store_index, U16 *email, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info.field_mask = SRV_PHB_ENTRY_FIELD_EMAIL2;
    contact_info.field_data.email_address2 =
        srv_phb_mem_malloc((MMI_PHB_EMAIL_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);

    result = srv_phb_oplib_get_contact_info(store_index, &contact_info);
    if (result == SRV_PHB_NO_ERROR)
    {
        mmi_wcsncpy(email, contact_info.field_data.email_address2, len);
        srv_phb_mem_free(contact_info.field_data.email_address2);
        return MMI_TRUE;
    }

    *email = 0;
    srv_phb_mem_free(contact_info.field_data.email_address2);
    return MMI_FALSE;
}

#endif /* __MMI_PHB_OPTIONAL_FIELDS_2ND_EMAIL__ */

#endif /* __MMI_PHB_OPTIONAL_FIELD__ */

#if defined(__MMI_PHB_INFO_FIELD__)


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_url
 * DESCRIPTION
 *  This function is used to get URL number by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  url:                [OUT]       PHB URL number
 *  len:                [IN]        URL number length
 * RETURN VALUES
 *  MMI_TRUE:           Got URL number
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_url(U16 store_index, U16 *url, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info.field_mask = SRV_PHB_ENTRY_FIELD_URL;
    contact_info.field_data.url =
        srv_phb_mem_malloc((MMI_PHB_URL_LENGTH + 1) * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);

    result = srv_phb_oplib_get_contact_info(store_index, &contact_info);
    if (result == SRV_PHB_NO_ERROR)
    {
        mmi_wcsncpy(url, contact_info.field_data.url, len);
        srv_phb_mem_free(contact_info.field_data.url);
        return MMI_TRUE;
    }

    *url = 0;
    srv_phb_mem_free(contact_info.field_data.url);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_address
 * DESCRIPTION
 *  This function is used to get PHB address.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  pobox:              [OUT]       PHB pobox
 *  extension:          [OUT]       PHB extension
 *  street:             [OUT]       PHB street
 *  city:               [OUT]       PHB city
 *  state:              [OUT]       PHB state
 *  postalcode:         [OUT]       PHB postalcode
 *  country:            [OUT]       PHB country
 * RETURN VALUES
 *  MMI_TRUE:           Success
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_address(
            U16 store_index,
            U16 *pobox,
            U16 *extension,
            U16 *street,
            U16 *city,
            U16 *state,
            U16 *postalcode,
            U16 *country)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info.field_mask = SRV_PHB_ENTRY_FIELD_ADDRESS;
    contact_info.field_data.pobox = pobox;
    contact_info.field_data.extension = extension;
    contact_info.field_data.street = street;
    contact_info.field_data.city = city;
    contact_info.field_data.state = state;
    contact_info.field_data.postalcode = postalcode;
    contact_info.field_data.country = country;

    result = srv_phb_oplib_get_contact_info(store_index, &contact_info);
    if (result == SRV_PHB_NO_ERROR)
    {
        return MMI_TRUE;
    }

    if (pobox) *pobox = 0;
    if (extension) *extension = 0;
    if (street) *street = 0;
    if (city) *city = 0;
    if (state) *state = 0;
    if (postalcode) *postalcode = 0;
    if (country) *country = 0;
    return MMI_FALSE;
}

#endif /* defined(__MMI_PHB_INFO_FIELD__) */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_image
 * DESCRIPTION
 *  This function is used to get PHB image id & path by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  image_path:         [OUT]       PHB image path
 * RETURN VALUES
 *  MMI_TRUE:           Got image path
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_image(U16 store_index, U16* image_id, U16 *image_path, U16* res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info.field_mask = SRV_PHB_ENTRY_FIELD_PIC;
    contact_info.field_data.image_path = image_path;

    result = srv_phb_oplib_get_contact_info(store_index, &contact_info);
    if (result == SRV_PHB_NO_ERROR)
    {
        if (image_id)
        {
            *image_id = contact_info.field_data.image_id;
        }
        if (res_type)
        {
            *res_type = contact_info.field_data.res_type;
        }
        return MMI_TRUE;
    }
    if (image_path)
    {
       image_path[0] = 0; 
    }
    if (image_id)
    {
        *image_id = 0;
    }
    if (res_type)
    {
        *res_type = 0;
    }
    return MMI_FALSE;
}

#if defined(__MMI_PHB_CALLER_VIDEO__)


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_video
 * DESCRIPTION
 *  This function is used to get PHB video id & path by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  video_id:           [OUT]       PHB video id
 * RETURN VALUES
 *  MMI_TRUE:           Got video id
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_video(U16 store_index, U16 *video_id, U16* video_path, U16* res_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info.field_mask = SRV_PHB_ENTRY_FIELD_VIDEO;
    contact_info.field_data.video_path = video_path;

    result = srv_phb_oplib_get_contact_info(store_index, &contact_info);
    if (result == SRV_PHB_NO_ERROR)
    {
        if (video_id)
        {
            *video_id = contact_info.field_data.video_id;
        }
        if (res_type)
        {
            *res_type = contact_info.field_data.res_type;
        }
        return MMI_TRUE;
    }
    if (video_path)
    {
       video_path[0] = 0; 
    }
    if (video_id)
    {
        *video_id = 0;
    }
    if (res_type)
    {
        *res_type = 0;
    }
    return MMI_FALSE;
}

#endif /* defined(__MMI_PHB_CALLER_VIDEO__) */

#ifdef __MMI_PHB_DEFAULT_NUMBER__


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_default_number_id
 * DESCRIPTION
 *  This function is used to get PHB default number id by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  id:                 [OUT]       PHB default number id
 * RETURN VALUES
 *  MMI_TRUE:           Got default number id
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_default_number_id(U16 store_index, U8 *id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info.field_mask = SRV_PHB_ENTRY_FIELD_DEF;

    result = srv_phb_oplib_get_contact_info(store_index, &contact_info);
    if (result == SRV_PHB_NO_ERROR)
    {
        switch (contact_info.field_data.default_number)
        {
            case SRV_PHB_ENTRY_FIELD_NUMBER:
            case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
            case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
            case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
                *id = contact_info.field_data.default_number;
                break;

            case 0xFF:
                *id = SRV_PHB_ENTRY_FIELD_NUMBER;
                 break;

            case 0xFE:
            default:
                *id = 0xFF;
                return MMI_FALSE;
        }
        return MMI_TRUE;
    }

    *id = 0xFF;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_default_number
 * DESCRIPTION
 *  This function is used to get PHB default number by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  number:             [OUT]       PHB default number
 *  len:                [IN]        Default number length
 * RETURN VALUES
 *  MMI_TRUE:           Got default number
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_default_number(U16 store_index, WCHAR *number, mmi_phb_num_type_enum *type, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (type)
    {
        *type = MMI_PHB_NUM_TYPE_MOBILE;
    }
    if (!srv_phb_get_default_number_id(store_index, &id))
    {
        srv_phb_get_number(store_index, number, len);
        return MMI_FALSE;
    }

    switch (id)
    {
        case SRV_PHB_ENTRY_FIELD_NUMBER:
            return srv_phb_get_number(store_index, number, len);

    #ifdef __MMI_PHB_OPTIONAL_FIELD__
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_1:
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_2:
        case SRV_PHB_ENTRY_FIELD_OPT_NUM_3:
            return srv_phb_get_optional_number(store_index, (U32)id, number, type, len);
    #endif /* __MMI_PHB_OPTIONAL_FIELD__ */

        default:
            *number = 0;
            return MMI_FALSE;
    }
}

#endif /* __MMI_PHB_DEFAULT_NUMBER__ */

#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_IMPS__) */

#if defined(__MMI_VOIP__)


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_voip_number
 * DESCRIPTION
 *  This function is used to get VOIP number by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  voip:               [OUT]       PHB VOIP number
 *  len:                [IN]        VOIP number length
 * RETURN VALUES
 *  MMI_TRUE:           Got VOIP number
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_voip_number(U16 store_index, U16 *voip, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_contact_info_struct contact_info;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    contact_info.field_mask = SRV_PHB_ENTRY_FIELD_VOIP;
    contact_info.field_data.voip =
        srv_phb_mem_malloc(VOIP_URI_LEN * sizeof(U16), SRV_PHB_MEMORY_TYPE_CTR);

    result = srv_phb_oplib_get_contact_info(store_index, &contact_info);
    if (result == SRV_PHB_NO_ERROR)
    {
        mmi_wcsncpy(voip, contact_info.field_data.voip, len);
        srv_phb_mem_free(contact_info.field_data.voip);
        return MMI_TRUE;
    }

    *voip = 0;
    srv_phb_mem_free(contact_info.field_data.voip);
    return MMI_FALSE;
}

#endif /* defined(__MMI_VOIP__) */


#ifdef __MMI_PHB_CALLER_GROUP__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_group_name
 * DESCRIPTION
 *  This function is used to get group name by group index.
 * PARAMETERS
 *  group_id:           [IN]        group index
 *  group_name:         [OUT]       group name
 *  len:                [IN]        group name length
 * RETURN VALUES
 *  MMI_TRUE:           Got group name
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
MMI_BOOL srv_phb_get_group_name(U8 group_id, U16 *group_name, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_group_info_struct group_info;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_get_group_info(group_id, &group_info);

    if (result >= 0)
    {
        mmi_wcsncpy(group_name, group_info.group_name, len);
        return MMI_TRUE;
    }

    *group_name = 0;
    return MMI_FALSE;
}
#endif /* __MMI_PHB_CALLER_GROUP__ */


/*****************************************************************************
 * FUNCTION
 *  srv_phb_truncate_name
 * DESCRIPTION
 *  This function is used to truncate PHB name by storage.
 * PARAMETERS
 *  name:               [IN/OUT]    Name to truncate
 *  storage:            [IN]        PHB storage
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_truncate_name(U16 *name, U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == PHB_STORAGE_NVRAM || storage == PHB_STORAGE_TCARD)
    {
        return;/* not truncate for nvram */
    }
    srv_phb_truncate_name_ex(name, srv_phb_get_sim_id((phb_storage_enum)storage), PHB_PHONEBOOK);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_truncate_name_ex
 * DESCRIPTION
 *  This function is used to truncate PHB name by storage.
 * PARAMETERS
 *  name:               [IN/OUT]    Name to truncate
 *  sim_interface:      [IN]        SIM1/SIM2
 *  phb_type:           [IN]        PHB_ECC/PHB_FDN/PHB_BDN/PHB_MSISDN/PHB_SDN/PHB_PHONEBOOK
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_truncate_name_ex(U16 *name, U8 sim_interface, U8 phb_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 max_name_len, extend_num;

#if defined(__PHB_0x81_SUPPORT__)
    U32 convert_length;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    max_name_len = srv_phb_startup_get_alpha_length(sim_interface, phb_type);

#if defined(__PHB_0x81_SUPPORT__)
    if ((convert_length = srv_phb_convert_to_0x81(name, MMI_FALSE)) > 0)
    {
        if (convert_length > max_name_len)
        {
            name[max_name_len - 3] = 0;
        }
    }
    else
#endif /* defined(__PHB_0x81_SUPPORT__) */
    if (srv_phb_check_ucs2_character(name))
    {
        if (mmi_wcslen(name) >= (S32)(max_name_len / 2))
        {
            name[max_name_len / 2] = 0;
        }
    }
    else
    {
        extend_num = srv_phb_gsm_extended_count(name, max_name_len);
        if ((mmi_wcslen(name) + extend_num) > max_name_len)
        {
            name[max_name_len - extend_num] = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_truncate_number
 * DESCRIPTION
 *  This function is used to truncate PHB number.
 * PARAMETERS
 *  number:             [IN/OUT]    Number to truncate
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_truncate_number(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 num_len;
    U16 *temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    num_len = mmi_wcslen(number);
    if (num_len > MMI_PHB_NUMBER_LENGTH)
    {
        if (number[0] == L'+')
        {
            number++;
        }
        temp = number + num_len - MMI_PHB_NUMBER_LENGTH - 1;
        while (*temp)
        {
            *number++ = *temp++;
        }
        *number = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_compare_number
 * DESCRIPTION
 *  This function is used to compare two PHB numbers.
 * PARAMETERS
 *  number1:            [IN]        First number
 *  number2:            [IN]        Second number
 * RETURN VALUES
 *  MMI_TRUE:           Equal
 *  MMI_FALSE:          Not equal
 *****************************************************************************/
MMI_BOOL srv_phb_compare_number(U16 *number1, U16 *number2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR number1_ascii[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    CHAR number2_ascii[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    CHAR *number1_p, *number2_p;

#ifndef __MMI_PHB_ADV_NUM_MATCH_MOBILE__
    U32 integer1, integer2;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcs_n_to_asc(number1_ascii, number1, MMI_PHB_NUMBER_PLUS_LENGTH * sizeof(U16));
    mmi_wcs_n_to_asc(number2_ascii, number2, MMI_PHB_NUMBER_PLUS_LENGTH * sizeof(U16));

#if defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__)
    number1_p = srv_phb_sse_remove_number_prefix(number1_ascii);
    number2_p = srv_phb_sse_remove_number_prefix(number2_ascii);
    if (srv_phb_sse_compare_number(number1_p, number2_p) == SRV_PHB_NO_ERROR)
    {
        return MMI_TRUE;
    }
#else /* defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__) */
    integer1 = srv_phb_sse_convert_number_to_int(number1_ascii);
    integer2 = srv_phb_sse_convert_number_to_int(number2_ascii);
    if (integer1 == integer2)
    {
        return MMI_TRUE;
    }
#endif /* defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__) */

    return MMI_FALSE;
}

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
MMI_BOOL srv_phb_compare_fdn_number(CHAR *approve_number, CHAR *fdn_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    while (*approve_number && *fdn_number)
    {
        if (*approve_number == '?' || *approve_number == *fdn_number || *fdn_number == '?')
        {
            approve_number ++;
            fdn_number ++;
            continue;
        }
        else
        {
            break;
        }
    }
    
    if (!(*fdn_number))
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_read_compare_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_phb_read_compare_length(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 buffer[NVRAM_EF_SYS_CACHE_OCTET_SIZE];
    S16 error;
    static U8 comp_len = 0xFF;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (comp_len == 0xFF)
    {
        ReadRecord(
            NVRAM_EF_SYS_CACHE_OCTET_LID,
            NVRAM_SYS_PHB_COMPARE_DIGIT,
            &buffer,
            sizeof(buffer),
            &error);
    }
    else
    {
        return comp_len;
    }

    comp_len = buffer[0];
    if (comp_len < 6)
    {
        comp_len = 6;
    }
    else if (comp_len > 20)
    {
        comp_len = 20;
    }

    return comp_len;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_number_to_int
 * DESCRIPTION
 *  Converts the last n characters of a phone number to interger.
 * PARAMETERS
 *  number:         [IN]        Input number
 * RETURNS
 *  interger of input number
 *****************************************************************************/
U32 srv_phb_convert_number_to_int(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *number_p;
    CHAR temp_number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    U8 compare_length;  /* Maximum convert number length is 9. (4 bytes integer) */
    U16 num_len, ext_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number != NULL)
    {
        mmi_wcs_n_to_asc(temp_number, number, MMI_PHB_NUMBER_PLUS_LENGTH * sizeof(U16));
    }
    else
    {
        return SRV_PHB_INVALID_NUMBER;
    }

    number_p = temp_number;

    /* Ignore *31# and #31# case */
    while (((number_p[0] == '*') && (number_p[1] == '3') && (number_p[2] == '1') && (number_p[3] == '#')) ||
           ((number_p[0] == '#') && (number_p[1] == '3') && (number_p[2] == '1') && (number_p[3] == '#')))
    {
        number_p += 4;
    }

    /* Skip the first plus sign */
    if (number_p[0] == '+')
    {
        number_p++;
    }

    if (number_p[0] == '\0')
    {
        return SRV_PHB_INVALID_NUMBER;
    }

    /* Find the position of extension number */
    ext_len = strcspn(number_p, "+pPwW*#");
    if (!ext_len)
    {
        return SRV_PHB_INVALID_NUMBER;
    }
    else
    {
        number_p[ext_len] = '\0';
        num_len = strlen(number_p);

        /* Read compare length from NVRAM */
        compare_length = srv_phb_read_compare_length();
        if (compare_length > 9)
        {
            compare_length = 9;
        }

        /* Convert at most 9 digits integer */
        if (num_len > compare_length)
        {
            number_p += num_len - compare_length;
        }

        return atol(number_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_atoi64
 * DESCRIPTION
 *  
 * PARAMETERS
 *  nptr:           [IN]        
 * RETURNS
 *  __int64
 *****************************************************************************/
__int64 srv_phb_atoi64(const char *nptr)
{
    int c;              /* current char */
    __int64 total;      /* current total */
    int sign;           /* if '-', then negative, otherwise positive */

    /* skip whitespace */
    while (isspace((int)(unsigned char)*nptr))
    {
        ++nptr;
    }

    c = (int)(unsigned char)*nptr++;
    sign = c;           /* save sign indication */
    if (c == '-' || c == '+')
    {
        c = (int)(unsigned char)*nptr++;    /* skip sign */
    }

    total = 0;

    while (isdigit(c))
    {
        total = 10 * total + (c - '0');     /* accumulate digit */
        c = (int)(unsigned char)*nptr++;    /* get next char */
    }

    if (sign == '-')
    {
        return -total;
    }
    else
    {
        return total;   /* return result, negated if necessary */
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_number_to_int64
 * DESCRIPTION
 *  Converts the last n characters of a phone number to interger 64.
 * PARAMETERS
 *  number:         [IN]        Input number
 * RETURNS
 *  interger of input number
 *****************************************************************************/
__int64 srv_phb_convert_number_to_int64(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR *number_p;
    CHAR temp_number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    U8 compare_length;  /* Maximum convert number length is 18. (8 bytes integer) */
    U16 num_len, ext_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number != NULL)
    {
        mmi_wcs_n_to_asc(temp_number, number, MMI_PHB_NUMBER_PLUS_LENGTH * sizeof(U16));
    }
    else
    {
        return SRV_PHB_INVALID_INT64_NUMBER;
    }

    number_p = temp_number;

    /* Ignore *31# and #31# case */
    while (((number_p[0] == '*') && (number_p[1] == '3') && (number_p[2] == '1') && (number_p[3] == '#')) ||
           ((number_p[0] == '#') && (number_p[1] == '3') && (number_p[2] == '1') && (number_p[3] == '#')))
    {
        number_p += 4;
    }

    /* Skip the first plus sign */
    if (number_p[0] == '+')
    {
        number_p++;
    }

    if (number_p[0] == '\0')
    {
        return SRV_PHB_INVALID_INT64_NUMBER;
    }

    /* Find the position of extension number */
    ext_len = strcspn(number_p, "+pPwW*#");
    if (!ext_len)
    {
        return SRV_PHB_INVALID_INT64_NUMBER;
    }
    else
    {
        number_p[ext_len] = '\0';
        num_len = strlen(number_p);

        /* Read compare length from NVRAM */
        compare_length = srv_phb_read_compare_length();
        if (compare_length > 18)
        {
            compare_length = 18;
        }

        /* Convert at most 18 digits integer */
        if (num_len > compare_length)
        {
            number_p += num_len - compare_length;
        }

        return srv_phb_atoi64(number_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_name_display_type
 * DESCRIPTION
 *  get name display type
 * PARAMETERS
 *  void
 * RETURNS
 *  name display type
 *****************************************************************************/
srv_phb_name_display_type_enum srv_phb_get_name_display_type(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_name_display_type == 0)
    {
        S16 error;
        ReadValue(NVRAM_PHB_NAME_DISPLAY_TYPE, &g_srv_phb_name_display_type, DS_BYTE, &error);

    #ifdef __COSMOS_MMI_PACKAGE__
        if (g_srv_phb_name_display_type != SRV_CONTACT_NAME_DISPLAY_TYPE_1 && g_srv_phb_name_display_type != SRV_CONTACT_NAME_DISPLAY_TYPE_3)
        {
            g_srv_phb_name_display_type = SRV_CONTACT_NAME_DISPLAY_TYPE_1;
        }
    #endif
    }
    return (srv_phb_name_display_type_enum)g_srv_phb_name_display_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_set_name_display_type
 * DESCRIPTION
 *  set name display type
 * PARAMETERS
 *  type:         [IN]        name display type
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_phb_set_name_display_type(srv_phb_name_display_type_enum type, srv_phb_async_func_type cb, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_phb_name_display_type != type)
    {
        g_srv_phb_name_display_type = type;
        WriteValue(NVRAM_PHB_NAME_DISPLAY_TYPE, &g_srv_phb_name_display_type, DS_BYTE, &error);
        return srv_phb_sse_build_name_index(cb, user_data);
    }
    return MMI_TRUE;
}


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
S32 srv_phb_check_storage_condition(U8 storage, srv_phb_check_storage_type_enum check_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (check_type != SRV_PHB_CHECK_STORAGE_FULL && srv_phb_get_used_contact(storage) == 0)
    {
        return SRV_PHB_STORAGE_EMPTY;
    }
    else if (check_type != SRV_PHB_CHECK_STORAGE_EMPTY 
        && srv_phb_get_used_contact(storage) == srv_phb_get_total_contact(storage))
    {
        return SRV_PHB_STORAGE_FULL;
    }
    return SRV_PHB_NO_ERROR;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_is_stoage_accessible
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  S32
*****************************************************************************/
S32 srv_phb_check_stoage_accessible(U8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage >= PHB_STORAGE_SIM && storage <= PHB_STORAGE_SIM4)
    {
        if (!srv_phb_startup_is_phb_support(srv_phb_get_sim_id((phb_storage_enum)storage), PHB_PHONEBOOK))
        {
            return SRV_PHB_ADN_FORBID;
        }
    }
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    else if (storage == PHB_STORAGE_TCARD)
    {
        if (!srv_fmgr_drv_is_accessible((U8)SRV_FMGR_CARD_DRV))
        {
            return SRV_PHB_TCARD_NOT_AVAILABLE;
        }
    }
    #endif
    return SRV_PHB_NO_ERROR;
}


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
void srv_phb_update_l4_status_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_l4c_phb_update_status_res_req_struct *my_msg_ptr;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    my_msg_ptr = (mmi_l4c_phb_update_status_res_req_struct*) OslConstructDataPtr(sizeof(mmi_l4c_phb_update_status_res_req_struct));

    my_msg_ptr->type = PHB_PHONEBOOK;
    my_msg_ptr->storage = PHB_STORAGE_NVRAM;
    my_msg_ptr->total = srv_phb_datamgr_total_contacts(PHB_STORAGE_NVRAM);
    my_msg_ptr->used = srv_phb_datamgr_used_contacts(PHB_STORAGE_NVRAM);
    my_msg_ptr->free = my_msg_ptr->total - my_msg_ptr->used;
    mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_L4C_PHB_UPDATE_STATUS_RES_REQ, (oslParaType*) my_msg_ptr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_convert_field_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_convert_field_filter(U32 field_filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 new_field = 0; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (field_filter & SRV_PHB_ENTRY_FIELD_NAME)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_NAME;
    }
#ifdef __MMI_PHB_USIM_SUPPORT__
    if (field_filter & SRV_PHB_ENTRY_FIELD_NICK)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_NICK;
    }
#endif
    #ifdef __MMI_PHB_DEFAULT_NUMBER__
    if (field_filter & SRV_PHB_ENTRY_FIELD_DEF)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_NUMBER;
    }
    #endif
    if (field_filter & SRV_PHB_ENTRY_FIELD_GSM_NUM)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_NUMBER;
    }
    
#ifdef __MMI_PHB_OPTIONAL_FIELD__
    if (field_filter & SRV_PHB_ENTRY_FIELD_EMAIL)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_EMAIL;
    }

    if (field_filter & SRV_PHB_ENTRY_FIELD_COMPANY)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_COMPANY;
    }
#endif /* __MMI_PHB_OPTIONAL_FIELD__ */

#if defined(__MMI_PHB_BIRTHDAY_FIELD__)
    if (field_filter & SRV_PHB_ENTRY_FIELD_BDAY)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_BDAY;
    }
#endif /* __MMI_PHB_BIRTHDAY_FIELD__ */

#if defined(__MMI_PHB_INFO_FIELD__)
    if (field_filter & SRV_PHB_ENTRY_FIELD_TITLE)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_TITLE;
    }
    if (field_filter & SRV_PHB_ENTRY_FIELD_URL)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_URL;
    }

    if (field_filter & SRV_PHB_ENTRY_FIELD_NOTE)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_NOTE;
    }

    if (field_filter & SRV_PHB_ENTRY_FIELD_ADDRESS)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_ADDRESS;
    }
#endif /* defined(__MMI_PHB_INFO_FIELD__) */

    if (field_filter & SRV_PHB_ENTRY_FIELD_GROUP)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_GROUP;
    }
    if (field_filter & SRV_PHB_ENTRY_FIELD_RING)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_RING;
    }

    if (field_filter & SRV_PHB_ENTRY_FIELD_PIC)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_IMAGE;
    }

#if defined(__MMI_PHB_CALLER_VIDEO__)
    if (field_filter & SRV_PHB_ENTRY_FIELD_VIDEO)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_VIDEO;
    }
#endif /* __MMI_PHB_CALLER_VIDEO__ */

#if defined(__MMI_IMPS__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_IMPS__ */

#if defined(__MMI_VOIP__)
    if (field_filter & SRV_PHB_ENTRY_FIELD_VOIP)
    {
        new_field |= MMI_PHB_CONTACT_FIELD_VOIP;
    }
#endif /* __MMI_VOIP__ */
    return new_field;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_num_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_phb_get_num_count(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_datamgr_get_num_count(id);
}


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
U8 srv_phb_get_email_count(mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_datamgr_get_email_count(id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_support_field
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_support_field(phb_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage == PHB_STORAGE_MAX || storage == PHB_STORAGE_NONE)
    {
        return 0;
    }
    else if (storage == PHB_STORAGE_NVRAM
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    || storage == PHB_STORAGE_TCARD
    #endif
        )
    {
        return srv_phb_get_phone_support_field();
    }
    else
    {
        return srv_phb_get_sim_support_field((phb_storage_enum)storage);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_support_field_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_support_field_count(U8 storage, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage <= PHB_STORAGE_NONE || storage >= PHB_STORAGE_MAX)
    {
        return 0;
    }
    else if (storage == PHB_STORAGE_NVRAM
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__
    || storage == PHB_STORAGE_TCARD
    #endif
    )
    {
        return srv_phb_get_phone_support_field_count(field);
    }
    else
    {
        return srv_phb_get_sim_support_field_count((phb_storage_enum)storage, field);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_get_alpha_field_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_phb_get_alpha_field_length(phb_storage_enum storage, mmi_phb_contact_field_id_enum field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (storage <= PHB_STORAGE_NONE || storage >= PHB_STORAGE_MAX)
    {
        return 0;
    }
    else if (storage == PHB_STORAGE_NVRAM
    #ifdef __SRV_PHB_TCARD_STORAGE_SUPPORT__    
        || storage == PHB_STORAGE_TCARD
    #endif
        )
    {
        return srv_phb_get_phone_alpha_field_len(field);
    }
    else
    {
        return srv_phb_get_sim_alpha_field_len(storage, field);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init_protocol
 * DESCRIPTION
 *  Initialize phonebook srv protocol
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_init_protocol(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_startup_init();
    srv_phb_datamgr_init();
    srv_phb_sim_init();
#ifdef __MMI_PHB_ATCMD_SUPPORT__
    srv_phb_at_init();
#endif
    srv_phb_mem_init();
    srv_phb_xmgnt_init();
#ifdef __MMI_PHB_CALLER_GROUP__
    srv_phb_group_init();
#endif
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)
    srv_phb_java_handler_init();
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_init
 * DESCRIPTION
 *  Initialize phonebook srv
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_phb_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_setting_init();

    // query async
    srv_phb_query_async_init();
}
