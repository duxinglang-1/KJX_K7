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
 *   jpim_phonebook.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines CMCC phonebook native API
 *
 * Author:
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "j2me_custom_option.h"
#if defined(SUPPORT_JSR_75_PIM) || defined(SUPPORT_CMCC)

#include "MMI_features.h"
#include "mmi_platform.h"
#include "j2me_trace.h"
#include "jvm_interface.h"
#include "jam_interface.h"
#include "jpim_interface.h"
#include "jpim_internal.h"
#include "jvm_adaptor.h"
#include "app_str.h"
#include "PhoneBookResDef.h"
#include "GlobalDefs.h"
#include "mmi_rp_app_java_def.h"
#ifndef __COSMOS_MMI_PACKAGE__
#include "mmi_rp_app_phonebook_def.h"
#else
#include "mmi_rp_vapp_java_def.h"
#include "mmi_rp_vapp_contact_def.h"
#endif
#include "jam_internal.h"

/*************************************************************************
 * Function Definition
 *************************************************************************/
extern kal_eventgrpid g_java_event_group_1;

//===========================================================================
//  PIM GLOBAL USE
//===========================================================================

/*****************************************************************************
 * FUNCTION
 *  jpim_transfer_error_code
 * DESCRIPTION
 * PARAMETERS
 *  type        [IN]
 *  code        [IN]
 * RETURNS
 *****************************************************************************/
kal_int32 jpim_transfer_error_code(kal_int32 type, kal_int32 code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(type == JPIM_PHONEBOOK)
    {
        switch(code)
        {
            case MMI_PHB_JAVA_ERROR:                return JPIM_ERROR;
            case MMI_PHB_JAVA_SUCCESS:              return JPIM_SUCCESS;
            case MMI_PHB_JAVA_NOT_READY:            return JPIM_NOT_READY;
            case MMI_PHB_JAVA_NOT_SUPPORT:          return JPIM_NOT_SUPPORT;
            case MMI_PHB_JAVA_NOT_FOUND:            return JPIM_NOT_FOUND;
            case MMI_PHB_JAVA_STORAGE_FULL:         return JPIM_STORAGE_FULL;
            case MMI_PHB_JAVA_NUMBER_TOO_LONG:      return JPIM_NUMBER_TOO_LONG;
            case MMI_PHB_JAVA_ADN_FORBID:           return JPIM_FDN_ON;
            case MMI_PHB_JAVA_OUT_OF_INDEX:         return JPIM_OUT_OF_INDEX;
            case MMI_PHB_JAVA_EMAIL_FULL:           return JPIM_EMAIL_FULL;
            case MMI_PHB_JAVA_ANR_FULL:             return JPIM_ANR_FULL;
            default:
                return JPIM_ERROR;
        }
    }
#if defined(SUPPORT_JSR_75_PIM)
    else if(type == JPIM_EVENTDB)
    {
        switch(code)
        {
            case MMI_EVTDB_JAVA_TDL_EXPIRED_ALARM :        return JPIM_SUCCESS;
            case MMI_EVTDB_JAVA_SUCCESS:                   return JPIM_SUCCESS;
            case MMI_EVTDB_JAVA_NOT_SUPPORT:               return JPIM_NOT_SUPPORT;
            case MMI_EVTDB_JAVA_TDL_NOT_READY:             return JPIM_NOT_READY;
            case MMI_EVTDB_JAVA_NOT_FOUND:                 return JPIM_NOT_FOUND;
            case MMI_EVTDB_JAVA_STORAGE_FULL:              return JPIM_STORAGE_FULL;
            case MMI_EVTDB_JAVA_DELETE_FAIL:               return JPIM_DELETE_FAIL;
            case MMI_EVTDB_JAVA_OUT_OF_INDEX:              return JPIM_OUT_OF_INDEX;
            case MMI_EVTDB_JAVA_INVALID_HANDLE:            return JPIM_INVALID_HANDLE;
            case MMI_EVTDB_JAVA_INVALID_DATE:              return JPIM_INVALID_DATE;
            case MMI_EVTDB_JAVA_TDL_INVALID_START_TIME:    return JPIM_INVALID_START_TIME;
            case MMI_EVTDB_JAVA_TDL_INVALID_END_TIME:      return JPIM_INVALID_END_TIME;
            case MMI_EVTDB_JAVA_TDL_INVALID_NOTES:         return JPIM_INVALID_NOTES;
            case MMI_EVTDB_JAVA_TDL_INVALID_ALARM:         return JPIM_INVALID_ALARM;
            case MMI_EVTDB_JAVA_TDL_INVALID_REPEAT:        return JPIM_INVALID_REPEAT;
            case MMI_EVTDB_JAVA_ERROR:                     return JPIM_ERROR;
            default:
                return JPIM_ERROR;
        }
    }
#endif
    else
    {
        ASSERT(0);
    }

    return code;

}
/*****************************************************************************
 * FUNCTION
 *  jpim_transfer_error_code
 * DESCRIPTION
 * PARAMETERS
 *  type        [IN]
 *  code        [IN]
 * RETURNS
 *****************************************************************************/
kal_int32 jpim_transfer_phb_sort(kal_int32 sort)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(sort)
    {
        case JPIM_PHB_NO_SORT:                return MMI_PHB_NO_SORT;
        case JPIM_PHB_SORT_BY_NAME:           return MMI_PHB_BY_NAME;
        case JPIM_PHB_SORT_BY_EMAIL:          return MMI_PHB_BY_EMAIL;
        case JPIM_PHB_SORT_BY_NUMBER:         return MMI_PHB_BY_NUMBER;
        default:
            ASSERT(0);
            return MMI_PHB_BY_NAME;
    }
}

/*****************************************************************************
 * FUNCTION
 *  jpim_transfer_error_code
 * DESCRIPTION
 * PARAMETERS
 *  type        [IN]
 *  code        [IN]
 * RETURNS
 *****************************************************************************/
kal_int32 jpim_transfer_phb_storage(kal_int32 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(storage)
    {
        case JPIM_PHB_STORAGE_NONE:         return PHB_STORAGE_NONE;
        case JPIM_PHB_SIM:                  return PHB_STORAGE_SIM;
    #if (MMI_MAX_SIM_NUM >= 2)
        case JPIM_PHB_SIM2:                 return PHB_STORAGE_SIM2;
    #endif
    #if (MMI_MAX_SIM_NUM >= 3)
        case JPIM_PHB_SIM3:                 return PHB_STORAGE_SIM3;
    #endif
    #if (MMI_MAX_SIM_NUM >= 4)
        case JPIM_PHB_SIM4:                 return PHB_STORAGE_SIM4;
    #endif
        case JPIM_PHB_NVRAM:                return PHB_STORAGE_NVRAM;
        case JPIM_PHB_STORAGE_BOTH:         return PHB_STORAGE_MAX;
        default:
            ASSERT(0);
            return PHB_STORAGE_MAX;
    }
}

/*****************************************************************************
 * FUNCTION
 *  jpim_transfer_error_code
 * DESCRIPTION
 * PARAMETERS
 *  type        [IN]
 *  code        [IN]
 * RETURNS
 *****************************************************************************/
kal_bool jpim_check_vm_state(kal_bool write, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    state = jam_mvm_get_vm_state(vm_id);

    if (state == JVM_PAUSED_STATE || state == JVM_TERMINATE_STATE)
    {
        JPIM_DEBUG(TRACE_GROUP_2, JPIM_CHECK_VM_STATE, write, state);
        return KAL_FALSE;
    }

    if (write)
    {
        if (state == JVM_FG_RUNNING_STATE || state == JVM_SHORT_EVENT_STATE  || state == JVM_FG_MMI_RUNNING_STATE)
        {
            return KAL_TRUE;
        }
        else
        {
            JPIM_DEBUG(TRACE_GROUP_2, JPIM_CHECK_VM_STATE, write, state);
            return KAL_FALSE;
        }
    }
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  jpim_send_ilm
 * DESCRIPTION
 * PARAMETERS
 *  local_para_ptr      [?]
 *  msg_id              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void jpim_send_ilm(void *local_para_ptr, msg_type msg_id)
{
    java_send_msg_from_active_mod(MOD_MMI,MMI_J2ME_SAP,msg_id,local_para_ptr);
}

//===========================================================================
//  PHONEBOOK
//===========================================================================
typedef enum
{
    JPIM_PHB_STATE_IDLE,
    JPIM_PHB_STATE_GET_COUNT,
    JPIM_PHB_STATE_GET_ENTRY,
    JPIM_PHB_STATE_APPEND_ENTRY,
    JPIM_PHB_STATE_UPDATE_ENTRY,
    JPIM_PHB_STATE_DELETE_ENTRY,
    JPIM_PHB_STATE_SEARCH_ENTRY,
    JPIM_PHB_STATE_GET_GROUP_COUNT,
    JPIM_PHB_STATE_GET_GROUP_INFO,
    JPIM_PHB_STATE_SET_GROUP_INFO
} jpim_phb_state_enum;

static kal_int32 jpim_phb_count = 0;
static kal_int32 jpim_phb_result = 0;
static kal_int32 jpim_phb_index = -1;
static kal_int32 jpim_phb_handle = 0xFFFF;

static jpim_phb_state_enum jpim_phb_state = JPIM_PHB_STATE_IDLE;
/*****************************************************************************
 * FUNCTION
 *  jpim_phb_getSupportField
 * DESCRIPTION
 *  This function retrieves the support field of the phonebook database.
 * PARAMETERS
 *  storage     [in]        jpim_phb_storage_enum
 *  size        [in/out]    If *size = 0, will return the size of buffer that  need.
 *                          If *size != 0, will return the real size that we put into buffer
 *  field       [out]       buffer to put supported fields
 * RETURNS
 *  jpim_error_code_enum
 *  JPIM_SIZE_TOO_SMALL - buffer size is too small
 *****************************************************************************/
kal_int32 jpim_phb_getSupportField(kal_int32 storage, kal_int32* size, kal_int32* field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    const static kal_int32 sim[] = { JPIM_C_FORMATTED_NAME, JPIM_C_TEL };
    const static kal_int32 nsim = sizeof(sim)/sizeof(kal_int32);
#ifndef __COSMOS_MMI_PACKAGE__
    const static kal_int32 phone[] =
        {
            JPIM_C_FORMATTED_NAME
            ,JPIM_C_TEL
            ,JPIM_C_ORG
            ,JPIM_C_EMAIL
    #ifdef JSR_75_PIM_EXTRA_BIRTHDAY
            ,JPIM_C_BIRTHDAY
    #endif
    #ifdef JSR_75_PIM_EXTRA_IMAGE
            ,JPIM_C_PHOTO
    #endif
    #ifdef JSR_75_PIM_EXTRA_INFO
            ,JPIM_C_TITLE
            ,JPIM_C_URL
            ,JPIM_C_ADDR
            ,JPIM_C_NOTE
            ,JPIM_C_UID // UID revise
    #endif
        };
#else
    const static kal_int32 phone[] =
        {
    #ifdef JSR_75_PIM_EXTRA_IMAGE
            JPIM_C_PHOTO,
    #endif
            JPIM_C_FORMATTED_NAME
    #ifdef JSR_75_PIM_EXTRA_INFO
            ,JPIM_C_TITLE
    #endif
            ,JPIM_C_ORG
            ,JPIM_C_TEL
            ,JPIM_C_EMAIL
    #ifdef JSR_75_PIM_EXTRA_INFO
            ,JPIM_C_ADDR
    #endif
    #ifdef JSR_75_PIM_EXTRA_BIRTHDAY
            ,JPIM_C_BIRTHDAY
    #endif
    #ifdef JSR_75_PIM_EXTRA_INFO
            ,JPIM_C_NOTE
            ,JPIM_C_URL
            ,JPIM_C_UID // UID revise
    #endif
        };
#endif
    const static kal_int32 nphone = sizeof(phone)/sizeof(kal_int32);

    kal_int32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if (MMI_MAX_SIM_NUM == 4)
    if (storage == JPIM_PHB_SIM || storage == JPIM_PHB_SIM2 || storage == JPIM_PHB_SIM3 || storage == JPIM_PHB_SIM4)
#elif (MMI_MAX_SIM_NUM == 3)
    if (storage == JPIM_PHB_SIM || storage == JPIM_PHB_SIM2 || storage == JPIM_PHB_SIM3)
#elif (MMI_MAX_SIM_NUM == 2)
    if (storage == JPIM_PHB_SIM || storage == JPIM_PHB_SIM2)
#else
    if (storage == JPIM_PHB_SIM)
#endif
    {
        if( *size < nsim)
        {
            *size = nsim;
            return JPIM_SIZE_TOO_SMALL;
        }

        *size = nsim;

        for( i = 0 ;i < nsim; i++ )
        {
            field[i] = sim[i];
        }
        return JPIM_SUCCESS;

    }
    else if( storage == JPIM_PHB_NVRAM || storage == JPIM_PHB_STORAGE_BOTH)
    {

        if( *size < nphone)
        {
            *size = nphone;
            return JPIM_SIZE_TOO_SMALL;
        }

        *size = nphone;

        for( i = 0 ;i < nphone; i++ )
        {
            field[i] = phone[i];
        }
        return JPIM_SUCCESS;
    }
    else
    {
        return JPIM_PARA_ERROR;
    }

    return JPIM_ERROR;

}
/*****************************************************************************
 * FUNCTION
 *  jpim_phb_getSupportAttr
 * DESCRIPTION
 *  This function retrieves the support attribute of the phonebook database.
 * PARAMETERS
 *  storage     [in]        jpim_phb_storage_enum
 *  field       [in]
 *  size        [in/out]
 *  attr        [out]
 * RETURNS
 *  jpim_error_code_enum
 *  JPIM_SIZE_TOO_SMALL - buffer size is too small
 *****************************************************************************/
kal_int32  jpim_phb_getSupportAttr(kal_int32 storage, kal_int32 field, kal_int32* size, kal_int32* attr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const static kal_int32 sim[] = { JPIM_C_ATTR_NONE, JPIM_C_ATTR_MOBILE};
    const static kal_int32 phone[] = {
		JPIM_C_ATTR_NONE,
        JPIM_C_ATTR_MOBILE,
        JPIM_C_ATTR_HOME,
        JPIM_C_ATTR_WORK,
        JPIM_C_ATTR_FAX,
    #ifdef JSR_75_PIM_EXTRA_PREFERRED_NUMBER
        JPIM_C_ATTR_PREFERRED
    #endif
        };
    const static kal_int32 nsim = sizeof(sim)/sizeof(kal_int32);
    const static kal_int32 nphone = sizeof(phone)/sizeof(kal_int32);

#ifdef __COSMOS_MMI_PACKAGE__
    const static kal_int32 phone_email[] = {
        JPIM_C_ATTR_NONE,
        JPIM_C_ATTR_HOME,
        JPIM_C_ATTR_WORK
        };
    const static kal_int32 nphone_email = sizeof(phone_email)/sizeof(kal_int32);
#endif

    kal_int32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


#if (MMI_MAX_SIM_NUM == 4)
    if (storage == JPIM_PHB_SIM || storage == JPIM_PHB_SIM2 || storage == JPIM_PHB_SIM3 || storage == JPIM_PHB_SIM4)
#elif (MMI_MAX_SIM_NUM == 3)
    if (storage == JPIM_PHB_SIM || storage == JPIM_PHB_SIM2 || storage == JPIM_PHB_SIM3)
#elif (MMI_MAX_SIM_NUM == 2)
    if (storage == JPIM_PHB_SIM || storage == JPIM_PHB_SIM2)
#else
    if (storage == JPIM_PHB_SIM)
#endif
    {
        if (field == JPIM_C_TEL || field == JPIM_NONE)
        {
            if( *size < nsim )
            {
                *size = nsim;
                return JPIM_SIZE_TOO_SMALL;
            }
            *size = nsim;

            for(i = 0 ;i < nsim; i++)
            {
                attr[i] = sim[i];
            }

            return JPIM_SUCCESS;
        }
    }
    else if( storage == JPIM_PHB_NVRAM || storage == JPIM_PHB_STORAGE_BOTH)
    {
        if(field == JPIM_C_TEL || field == JPIM_NONE)
        {
            if( *size < nphone )
            {
                *size = nphone;
                return JPIM_SIZE_TOO_SMALL;
            }

            *size = nphone;

            for(i = 0 ;i < nphone; i++)
            {
                attr[i] = phone[i];
            }
            return JPIM_SUCCESS;
        }
#ifdef __COSMOS_MMI_PACKAGE__
        else if (field == JPIM_C_EMAIL)
        {
            if( *size < nphone_email)
            {
                *size = nphone_email;
                return JPIM_SIZE_TOO_SMALL;
            }

            *size = nphone_email;

            for(i = 0 ;i < nphone_email; i++)
            {
                attr[i] = phone_email[i];
            }
            return JPIM_SUCCESS;
        }
#endif
    }
    else
    {
        *size = 0;
        return JPIM_PARA_ERROR;
    }

    return JPIM_ERROR;

}



/*****************************************************************************
 * FUNCTION
 *  jpim_phb_getIndexByHandle
 * DESCRIPTION
 *  This function can transfer the item handle to index by specific sort type.
 * PARAMETERS
 *  sort_type       [in]    jpim_phb_sort_type_enum
 *  storage         [in]    jpim_phb_storage_enum
 *  handle          [in]
 * RETURNS
 *  0~ 0xfffe -- the index value
 *  0xffff -- error
 *****************************************************************************/
kal_uint16 jpim_phb_getIndexByHandle(kal_uint8 sort_type,kal_uint8 storage, kal_uint16 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_store_index_to_sort_index(
            (U8)jpim_transfer_phb_storage(storage),
            (U16)handle);
}
/*****************************************************************************
 * FUNCTION
 *  jpim_phb_getHandleByIndex
 * DESCRIPTION
 *  This function can transfer the item sort index to handle
 * PARAMETERS
 *  sort_type       [in]    jpim_phb_sort_type_enum
 *  storage         [in]    jpim_phb_storage_enum
 *  index           [in]
 * RETURNS
 *  0~ 0xfffe -- the handle value
 *  0xffff -- error
 *****************************************************************************/
kal_uint16 jpim_phb_getHandleByIndex(kal_uint8 sort_type,kal_uint8 storage, kal_uint16 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_sort_index_to_store_index(
            (U8)jpim_transfer_phb_storage(storage),
            (U16)index);
}

/*****************************************************************************
 * FUNCTION
 *  jpim_phb_getName
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_wchar* jpim_phb_getName(kal_int32 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_GET_NAME);

    switch(storage)
    {
#if (MMI_MAX_SIM_NUM == 1)
        case JPIM_PHB_SIM:
            return (kal_wchar*) GetString(STR_GLOBAL_SIM);
#endif
#if (MMI_MAX_SIM_NUM >= 2)
        case JPIM_PHB_SIM:
            return (kal_wchar*) GetString(STR_GLOBAL_SIM_1);
        case JPIM_PHB_SIM2:
            return (kal_wchar*) GetString(STR_GLOBAL_SIM_2);
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        case JPIM_PHB_SIM3:
            return (kal_wchar*) GetString(STR_GLOBAL_SIM_3);
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        case JPIM_PHB_SIM4:
            return (kal_wchar*) GetString(STR_GLOBAL_SIM_4);
#endif
#ifndef __COSMOS_MMI_PACKAGE__
        case JPIM_PHB_NVRAM:
            return (kal_wchar*) GetString(STR_GLOBAL_PHONE);
        default:
            return (kal_wchar*) GetString(STR_SCR_PBOOK_CAPTION);
#else
        case JPIM_PHB_NVRAM:
            return (kal_wchar*) GetString(VAPP_PHB_STR_PHONE);
        default:
            return (kal_wchar*) GetString(VAPP_PHB_STR_CONTACT);
#endif
    }

    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_getFieldLabel
 * DESCRIPTION
 *
 * PARAMETERS
 *  field       [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_wchar *jpim_phb_getFieldLabel(kal_int32 field)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG_1(TRACE_GROUP_2, JPIM_PHB_GETFIELDLABEL, field);

    switch (field)
    {
#ifndef __COSMOS_MMI_PACKAGE__
#ifdef JSR_75_PIM_EXTRA_BIRTHDAY
        case JPIM_C_BIRTHDAY:
            return (kal_wchar*) GetString(STR_ID_PHB_BIRTHDAY);
#endif			
        case JPIM_C_EMAIL:
            return (kal_wchar*) GetString(STR_EMAIL_ADRESS);
        case JPIM_C_FORMATTED_ADDR:
            return (kal_wchar*) GetString(STR_GLOBAL_ADDRESS);
        case JPIM_C_FORMATTED_NAME:
            return (kal_wchar*) GetString(STR_ID_PHB_NAME);
        case JPIM_C_NICKNAME:
            return (kal_wchar*) GetString(STR_ID_FNG_JAVA_PIM_NICK_NAME);
#ifdef JSR_75_PIM_EXTRA_INFO
        case JPIM_C_NOTE:
            return (kal_wchar*) GetString(STR_ID_PHB_NOTE);
#endif			
        case JPIM_C_ORG:
            return (kal_wchar*) GetString(STR_COMPNAY_NAME);
        case JPIM_C_TEL:
            return (kal_wchar*) GetString(STR_ID_PHB_NUMBER);
#ifdef JSR_75_PIM_EXTRA_INFO			
        case JPIM_C_TITLE:
            return (kal_wchar*) GetString(STR_ID_PHB_TITLE);
#endif			
        case JPIM_C_URL:
            return (kal_wchar*) GetString(STR_GLOBAL_URL);
        case JPIM_C_ADDR:
            return (kal_wchar*) GetString(STR_GLOBAL_ADDRESS);
        case JPIM_C_PHOTO:
            return (kal_wchar*) GetString(STR_ID_PHB_CALLER_PIC);
        case JPIM_C_UID:
            return (kal_wchar*) L"UID"; // UID revise
#else
#ifdef JSR_75_PIM_EXTRA_BIRTHDAY
        case JPIM_C_BIRTHDAY:
            return (kal_wchar*) GetString(VAPP_PHB_STR_BDAY);
#endif			
        case JPIM_C_EMAIL:
            return (kal_wchar*) GetString(VAPP_PHB_STR_EMAIL);
        case JPIM_C_FORMATTED_ADDR:
            return (kal_wchar*) GetString(VAPP_PHB_STR_ADDRESS);
        case JPIM_C_FORMATTED_NAME:
            return (kal_wchar*) GetString(VAPP_PHB_STR_NAME);
        case JPIM_C_NICKNAME:
            return (kal_wchar*) GetString(STR_ID_FNG_JAVA_PIM_NICK_NAME);
#ifdef JSR_75_PIM_EXTRA_INFO
        case JPIM_C_NOTE:
            return (kal_wchar*) GetString(VAPP_PHB_STR_NOTE);
#endif			
        case JPIM_C_ORG:
            return (kal_wchar*) GetString(VAPP_PHB_STR_COMPANY);
        case JPIM_C_TEL:
            return (kal_wchar*) GetString(VAPP_PHB_STR_NUMBER);
#ifdef JSR_75_PIM_EXTRA_INFO			
        case JPIM_C_TITLE:
            return (kal_wchar*) GetString(VAPP_PHB_STR_TITLE);
#endif			
        case JPIM_C_URL:
            return (kal_wchar*) GetString(VAPP_PHB_STR_URL);
        case JPIM_C_ADDR:
            return (kal_wchar*) GetString(VAPP_PHB_STR_ADDRESS);
        case JPIM_C_PHOTO:
            return (kal_wchar*) GetString(STR_ID_FNG_JAVA_PIM_PHOTO);
        case JPIM_C_UID:
            return (kal_wchar*) L"UID"; // UID revise
#endif
        default:
            return NULL;
    }
}
/*****************************************************************************
 * FUNCTION
 *  jpim_phb_getFieldLabel
 * DESCRIPTION
 *
 * PARAMETERS
 *  field       [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_wchar *jpim_phb_getFieldEleLabel(kal_int32 field, kal_int32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG_1(TRACE_GROUP_2, JPIM_PHB_GETFIELDLABEL, field);

#ifdef JSR_75_PIM_EXTRA_INFO
    if (field == JPIM_C_ADDR)
    {
        switch(index)
        {
#ifndef __COSMOS_MMI_PACKAGE__
        case JPIM_C_ADDR_POBOX:
            return (kal_wchar*)GetString(STR_ID_PHB_ADR_POBOX);
        case JPIM_C_ADDR_EXTRA:
            return (kal_wchar*)GetString(STR_ID_PHB_ADR_EXTENSION);
        case JPIM_C_ADDR_STREET:
            return (kal_wchar*)GetString(STR_ID_PHB_ADR_STREET);
        case JPIM_C_ADDR_LOCALITY:
            return (kal_wchar*)GetString(STR_ID_PHB_ADR_CITY);
        case JPIM_C_ADDR_REGION:
            return (kal_wchar*)GetString(STR_ID_PHB_ADR_STATE);
        case JPIM_C_ADDR_POSTALCODE:
            return (kal_wchar*)GetString(STR_ID_PHB_ADR_POSTALCODE);
        case JPIM_C_ADDR_COUNTRY:
            return (kal_wchar*)GetString(STR_ID_PHB_ADR_COUNTRY);
#else
        case JPIM_C_ADDR_POBOX:
            return (kal_wchar*)GetString(VAPP_PHB_STR_POBOX);
        case JPIM_C_ADDR_EXTRA:
            return (kal_wchar*)GetString(VAPP_PHB_STR_EXTENSION);
        case JPIM_C_ADDR_STREET:
            return (kal_wchar*)GetString(VAPP_PHB_STR_STREET);
        case JPIM_C_ADDR_LOCALITY:
            return (kal_wchar*)GetString(VAPP_PHB_STR_CITY);
        case JPIM_C_ADDR_REGION:
            return (kal_wchar*)GetString(VAPP_PHB_STR_STATE);
        case JPIM_C_ADDR_POSTALCODE:
            return (kal_wchar*)GetString(VAPP_PHB_STR_POSTALCODE);
        case JPIM_C_ADDR_COUNTRY:
            return (kal_wchar*)GetString(VAPP_PHB_STR_COUNTRY);
#endif
        }
    }
#endif
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_getAttrLabel
 * DESCRIPTION
 *
 * PARAMETERS
 *  attr        [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_wchar *jpim_phb_getAttrLabel(kal_int32 attr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG_1(TRACE_GROUP_2, JPIM_PHB_GETATTRLABEL, attr);

    switch (attr)
    {
        case JPIM_C_ATTR_NONE:
			return (kal_wchar*) GetString(STR_ID_FNG_JAVA_PIM_ATTR_NONE);
#ifndef __COSMOS_MMI_PACKAGE__
        case JPIM_C_ATTR_FAX:
            return (kal_wchar*) GetString(STR_FAX_NUMBER);
        case JPIM_C_ATTR_HOME:
            return (kal_wchar*) GetString(STR_HOME_NUMBER);
        case JPIM_C_ATTR_MOBILE:
            return (kal_wchar*) GetString(STR_ID_PHB_MOBILE_NUMBER);
        case JPIM_C_ATTR_WORK:
            return (kal_wchar*) GetString(STR_OFFICE_NUMBER);
#else
        case JPIM_C_ATTR_FAX:
            return (kal_wchar*) GetString(VAPP_PHB_STR_FAX);
        case JPIM_C_ATTR_HOME:
            return (kal_wchar*) GetString(VAPP_PHB_STR_HOME);
        case JPIM_C_ATTR_MOBILE:
            return (kal_wchar*) GetString(VAPP_PHB_STR_MOBILE);
        case JPIM_C_ATTR_WORK:
            return (kal_wchar*) GetString(VAPP_PHB_STR_WORK);
#endif
        case JPIM_C_ATTR_PREFERRED:
            return (kal_wchar*) GetString(STR_ID_FNG_JAVA_PIM_PREFERRED_NUMBER);
        default:
            return NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_getCount
 * DESCRIPTION
 *
 * PARAMETERS
 *  storage             [IN]
 *  group               [IN]
 *  sort_type(?)        [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_int32 jpim_phb_getCount(kal_uint8 storage, kal_uint8 group, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    mmi_phb_handler_get_entry_req_struct *p =
        (mmi_phb_handler_get_entry_req_struct*) construct_local_para(
                                                    sizeof(mmi_phb_handler_get_entry_req_struct),
                                                    TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_GETCOUNT);

    p->count = 0;
    p->entry_ptr = NULL;
    p->index = 1;
    p->sort_type = MMI_PHB_NO_SORT;
    p->storage = jpim_transfer_phb_storage(storage);
    p->group = group;

    /* set cmccphk_state before send message!! */
    jpim_phb_state = JPIM_PHB_STATE_GET_COUNT;
    jpim_phb_result = MMI_PHB_JAVA_ERROR;
    jpim_phb_count = -1;

	if (jpim_check_vm_state(0, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_PHB_JAVA_GET_ENTRY_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_GETCOUNT, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
	else
    {
        free_local_para((local_para_struct*) p);
    }

    if (jpim_phb_result != MMI_PHB_JAVA_SUCCESS)
    {
        return -1;
    }
    else
    {
        return jpim_phb_count;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_fetchByIndex
 * DESCRIPTION
 *
 * PARAMETERS
 *  entry           [?]         [?]
 *  index           [IN]
 *  sort_type       [IN]
 *  storage         [IN]
 *  group           [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_int32 jpim_phb_fetchByIndex(mmi_phb_handler_entry_struct *entry,
                                     kal_uint16 index,
                                     kal_uint8 sort_type,
                                     kal_uint8 storage,
                                     kal_uint8 group,
                                     kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;

    kal_uint8 i;

    mmi_phb_handler_get_entry_req_struct *p =
        (mmi_phb_handler_get_entry_req_struct*) construct_local_para(
                                                    sizeof(mmi_phb_handler_get_entry_req_struct),
                                                    TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    p->count = 1;
    p->entry_ptr = entry;
    p->index = index;
    p->sort_type = jpim_transfer_phb_sort(sort_type);
    p->storage = jpim_transfer_phb_storage(storage);
    p->group = group;

    jpim_phb_result = MMI_PHB_JAVA_ERROR;
    jpim_phb_state = JPIM_PHB_STATE_GET_ENTRY;

	if (jpim_check_vm_state(0, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_PHB_JAVA_GET_ENTRY_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_FETCH_INDEX, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_FETCHBYINDEX, entry->store_index, entry->sort_index);
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }

#ifdef __COSMOS_MMI_PACKAGE__
    if (jpim_transfer_error_code(JPIM_PHONEBOOK, jpim_phb_result) == JPIM_SUCCESS)
    {
        for (i = 0; i < MMI_PHB_NUMBER_FIELD_COUNT; i++)
        {
            if (entry->opt_num[i].type >= MMI_PHB_NUM_TYPE_TOTAL)
            {
                entry->opt_num[i].type = MMI_PHB_NUM_TYPE_MOBILE;
            }
        }
		
        for (i = 0; i < MMI_PHB_EMAIL_FIELD_COUNT; i++)
        {
            if (entry->emailAddresses[i].type >= MMI_PHB_EMAIL_TYPE_TOTAL)
            {
                entry->emailAddresses[i].type = MMI_PHB_EMAIL_TYPE_OFFICE;
            }
        }
    }
#endif

    return jpim_transfer_error_code(JPIM_PHONEBOOK, jpim_phb_result);
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_adjustEntry
 * DESCRIPTION
 *  This function adds a new entry into the event database.
 *  If the entry is successfully added, values are assigned to the
 *  index and handle fields of the entry.
 * PARAMETERS
 *  entry         [IN/OUT]
 *  db_type       [IN]              jpim_evtdb_db_enum
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
void jpim_phb_adjustEntry(mmi_phb_handler_entry_struct *entry, kal_uint8 storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( app_ucs2_strlen((kal_int8*)entry->name) == 0  &&
#ifndef __COSMOS_MMI_PACKAGE__
        app_ucs2_strlen((kal_int8*)entry->number) == 0
#else
        app_ucs2_strlen((kal_int8*)((entry->opt_num[0]).number)) == 0
#endif
        )
    {
        app_asc_str_to_ucs2_str((kal_int8*)entry->name, (kal_int8*)"No Name");
    }

#ifndef __COSMOS_MMI_PACKAGE__
    if ((entry->number)[0] != (U16)'+')
    {
        (entry->number)[MMI_PHB_NUMBER_LENGTH] = (U16)0;
    }
#endif

    if (((entry->opt_num[0]).number)[0] != (U16)'+')
    {
        ((entry->opt_num[0]).number)[MMI_PHB_NUMBER_LENGTH] = (U16)0;
    }

    if (((entry->opt_num[1]).number)[0] != (U16)'+')
    {
        ((entry->opt_num[1]).number)[MMI_PHB_NUMBER_LENGTH] = (U16)0;
    }

    if (((entry->opt_num[2]).number)[0] != (U16)'+')
    {
        ((entry->opt_num[2]).number)[MMI_PHB_NUMBER_LENGTH] = (U16)0;
    }

#ifdef __COSMOS_MMI_PACKAGE__
    if (((entry->opt_num[3]).number)[0] != (U16)'+')
    {
        ((entry->opt_num[3]).number)[MMI_PHB_NUMBER_LENGTH] = (U16)0;
    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  jpim_phb_appendEntry
 * DESCRIPTION
 *  This function adds a new entry into the event database.
 *  If the entry is successfully added to the database, the index and entry
 *  handle fields are assigned values.
 *  The application must assign a value to at least "Name" or "Number"
 *  to add a new entry.
 * PARAMETERS
 *  entry           [IN/OUT]    The correct values are assigned to the index and handle.
 *  sort_type       [IN]        jpim_phb_sort_type_enum
 *  storage         [IN]        jpim_phb_storage_enum
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
kal_int32 jpim_phb_appendEntry(mmi_phb_handler_entry_struct *entry, kal_uint8 storage, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint32 event_group;

    mmi_phb_handler_set_entry_req_struct *p =
        (mmi_phb_handler_set_entry_req_struct*) construct_local_para(
                                                    sizeof(mmi_phb_handler_set_entry_req_struct),
                                                    TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_APPENDENTRY);

    jpim_phb_adjustEntry(entry, storage);

    p->entry_ptr = entry;
    p->index = 0xffff;
    p->storage = jpim_transfer_phb_storage(storage);

    jpim_phb_result = MMI_PHB_JAVA_ERROR;
    jpim_phb_state = JPIM_PHB_STATE_APPEND_ENTRY;
    jpim_phb_index = 0xffff;
    jpim_phb_handle = 0xffff;

	if (jpim_check_vm_state(1, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_PHB_JAVA_SET_ENTRY_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_APPEND_ENTRY, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        entry->sort_index = jpim_phb_index;
        entry->store_index = jpim_phb_handle;
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }

    return jpim_transfer_error_code(JPIM_PHONEBOOK, jpim_phb_result);

}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_upddateEntry
 * DESCRIPTION
 *  This function updates an entry in the phonebook database.
 *  The index (physical storage index) must refer to a valid entry in the
 *  database, otherwise an "invalid index" error is returned.
 *  If the sort index changes after the update, a new sort index is assigned.
 * PARAMETERS
 *  entry           [IN/OUT]    The correct values are assigned to the index and handle.
 *  sort_type       [IN]        jpim_phb_sort_type_enum
 *  storage         [IN]        jpim_phb_storage_enum
 *  index           [IN]
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
kal_int32 jpim_phb_upddateEntry(mmi_phb_handler_entry_struct *entry, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint32 event_group;

    mmi_phb_handler_set_entry_req_struct *p =
        (mmi_phb_handler_set_entry_req_struct*) construct_local_para(
                                                    sizeof(mmi_phb_handler_set_entry_req_struct),
                                                    TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_UPDDATEENTRY);

    jpim_phb_adjustEntry(entry, PHB_STORAGE_MAX);

    p->entry_ptr = entry;
    p->index = entry->store_index;
    p->storage = PHB_STORAGE_MAX;

    jpim_phb_result = MMI_PHB_JAVA_ERROR;
    jpim_phb_state = JPIM_PHB_STATE_UPDATE_ENTRY;
    jpim_phb_index = 0xffff;
    jpim_phb_handle = 0xffff;

	if (jpim_check_vm_state(1, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_PHB_JAVA_SET_ENTRY_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_UPDATE_ENTRY, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        entry->sort_index = jpim_phb_index;
        entry->store_index = jpim_phb_handle;
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }

    return jpim_transfer_error_code(JPIM_PHONEBOOK, jpim_phb_result);
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_deleteEntry
 * DESCRIPTION
 *  This function deletes an entry from the phonebook database.
 * PARAMETERS
 *  handle           [IN]
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/
kal_int32 jpim_phb_deleteEntry(kal_uint16 handle, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_uint32 event_group;

    mmi_phb_handler_set_entry_req_struct *p =
        (mmi_phb_handler_set_entry_req_struct*) construct_local_para(
                                                    sizeof(mmi_phb_handler_set_entry_req_struct),
                                                    TD_CTRL);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_DELETEENTRY);

    p->entry_ptr = NULL;
    p->index = handle;
    p->storage = PHB_STORAGE_MAX;

    jpim_phb_result = MMI_PHB_JAVA_ERROR;
    jpim_phb_state = JPIM_PHB_STATE_DELETE_ENTRY;

	if (jpim_check_vm_state(1, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_PHB_JAVA_SET_ENTRY_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_DELETE_ENTRY, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }
    return jpim_transfer_error_code(JPIM_PHONEBOOK, jpim_phb_result);
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_searchEntry
 * DESCRIPTION
 *  This function searches for a specific pattern in the phonebook database.
 *  If the search type is by number, the entry with the smallest distance to
 *  the pattern (best match) is returned. If the search type is "Name" or
 *  "E-mail", only the prefix-matched items are listed.
 *  Therefore, possibly nothing is returned if searching by "Name"
 *  or "Email". Furthermore, the sort index in entry sorting is assigned by
 *  the sort_type.
 * PARAMETERS
 *  entry           [IN/OUT]
 *  sort_type       [IN]        jpim_phb_sort_type_enum
 *  storage         [IN]        jpim_phb_storage_enum
 *  search_type     [IN]        jpim_phb_sort_type_enum
 *  group           [IN]
 *  start_index     [IN]
 *  pattern         [IN]
 * RETURNS
 *  jpim_error_code_enum
 *****************************************************************************/

kal_int32 jpim_phb_searchEntry(mmi_phb_handler_entry_struct *entry,
                                    kal_uint8 storage,
                                    kal_uint8 search_type,
                                    kal_uint16 start_index,
                                    kal_uint8 group,
                                    kal_char *pattern,
			                        kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    mmi_phb_handler_search_entry_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_SEARCHENTRY);

    p = (mmi_phb_handler_search_entry_req_struct*)
        construct_local_para(sizeof(mmi_phb_handler_search_entry_req_struct), TD_CTRL);

    p->entry_ptr = entry;
    p->sort_type = MMI_PHB_BY_NAME;
    p->storage = jpim_transfer_phb_storage(storage);
    p->search_type = jpim_transfer_phb_sort(search_type);
    p->group = 0;
    p->start_index = start_index;
    app_ucs2_strcpy((kal_int8*)p->pattern, (kal_int8*)pattern);

    jpim_phb_result = MMI_PHB_JAVA_ERROR;
    jpim_phb_state = JPIM_PHB_STATE_SEARCH_ENTRY;
    jpim_phb_index = 0;

	if (jpim_check_vm_state(0, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_SEARCH_ENTRY, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
        entry->sort_index = jpim_phb_index;
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }

    return jpim_transfer_error_code(JPIM_PHONEBOOK, jpim_phb_result);
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_getGroupCount
 * DESCRIPTION
 *  This function retrieves the number of group on handset.
 * PARAMETERS
 *  storage         [IN]
 * RETURNS
 *  Number of groups
 *****************************************************************************/
kal_int32 jpim_phb_getGroupCount(kal_uint8 storage, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    mmi_phb_handler_get_group_info_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    p = (mmi_phb_handler_get_group_info_req_struct*)
        construct_local_para(sizeof(mmi_phb_handler_get_group_info_req_struct), TD_CTRL);

    p->storage = jpim_transfer_phb_storage(storage);
    p->max_group = 0;
    p->group_ptr = NULL;

    jpim_phb_result = MMI_PHB_JAVA_ERROR;
    jpim_phb_state = JPIM_PHB_STATE_GET_GROUP_COUNT;
    jpim_phb_count = 0;

	if (jpim_check_vm_state(0, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_GET_GROUP_INFO, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }

    if (jpim_phb_result != MMI_PHB_JAVA_SUCCESS)
    {
        return 0;
    }
    else
    {
        return jpim_phb_count;
    }
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_getGroupInfo
 * DESCRIPTION
 *  This function retrieves all the group names in the phonebook database.
 * PARAMETERS
 *  storage         [IN]
 *  max_group       [IN/OUT]
 *  group_ptr       [OUT]
 * RETURNS
 *  Number of groups
 *****************************************************************************/
kal_int32 jpim_phb_getGroupInfo(kal_uint8 storage, kal_uint8 *max_group, mmi_phb_handler_group_struct *group_ptr, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    mmi_phb_handler_get_group_info_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_GETGROUPINFO);

    p = (mmi_phb_handler_get_group_info_req_struct*)
        construct_local_para(sizeof(mmi_phb_handler_get_group_info_req_struct), TD_CTRL);

    p->max_group = *max_group;
    p->group_ptr = group_ptr;
    p->storage = jpim_transfer_phb_storage(storage);

    jpim_phb_result = MMI_PHB_JAVA_ERROR;
    jpim_phb_state = JPIM_PHB_STATE_GET_GROUP_INFO;
    jpim_phb_count = 0;

	if (jpim_check_vm_state(0, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_GET_GROUP_INFO, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }

    if (jpim_phb_result != MMI_PHB_JAVA_SUCCESS)
    {
        *max_group = 0;
    }
    else
    {
        *max_group = jpim_phb_count;
    }
    return jpim_transfer_error_code(JPIM_PHONEBOOK, jpim_phb_result);
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_addGroupInfo
 * DESCRIPTION
 *
 * PARAMETERS
 *  group_ptr       [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_int32 jpim_phb_addGroupInfo(mmi_phb_handler_group_struct *group_ptr, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    mmi_phb_handler_set_group_info_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_ADDGROUPINFO);

    p = (mmi_phb_handler_set_group_info_req_struct*)
        construct_local_para(sizeof(mmi_phb_handler_set_group_info_req_struct), TD_CTRL);

    p->group_id = 0xFF;
    p->group_ptr = group_ptr;
		p->delete_list_ptr = NULL;

    jpim_phb_result = MMI_PHB_JAVA_ERROR;
    jpim_phb_state = JPIM_PHB_STATE_SET_GROUP_INFO;

    if (jpim_check_vm_state(1, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_SET_GROUP_INFO, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }

    return jpim_transfer_error_code(JPIM_PHONEBOOK, jpim_phb_result);
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_deleteGroupInfo
 * DESCRIPTION
 *
 * PARAMETERS
 *  group_id         [IN]
 *  delete_list_ptr [IN/OUT]
 * RETURNS
 *
 *****************************************************************************/
kal_int32 jpim_phb_deleteGroupInfo(kal_uint8 group_id, mmi_phb_handler_delete_member_list_struct *delete_list_ptr, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    mmi_phb_handler_set_group_info_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_DELETEGROUPINFO);

    p = (mmi_phb_handler_set_group_info_req_struct*)
        construct_local_para(sizeof(mmi_phb_handler_set_group_info_req_struct), TD_CTRL);

    p->group_id = group_id;
    p->group_ptr = NULL;
		p->delete_list_ptr = delete_list_ptr;

    jpim_phb_result = MMI_PHB_JAVA_ERROR;
    jpim_phb_state = JPIM_PHB_STATE_SET_GROUP_INFO;

    if (jpim_check_vm_state(1, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_SET_GROUP_INFO, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }

    return jpim_transfer_error_code(JPIM_PHONEBOOK, jpim_phb_result);
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_setGroupInfo
 * DESCRIPTION
 *
 * PARAMETERS
 *  group_id        [IN]
 *  group_ptr       [IN]
 * RETURNS
 *
 *****************************************************************************/
kal_int32 jpim_phb_setGroupInfo(kal_uint8 group_id, mmi_phb_handler_group_struct *group_ptr, kal_int32 vm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 event_group;
    mmi_phb_handler_set_group_info_req_struct *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_SETGROUPINFO);

    p = (mmi_phb_handler_set_group_info_req_struct*)
        construct_local_para(sizeof(mmi_phb_handler_set_group_info_req_struct), TD_CTRL);

    p->group_id = group_id;
    p->group_ptr = group_ptr;
		p->delete_list_ptr = NULL;

    jpim_phb_result = MMI_PHB_JAVA_ERROR;
    jpim_phb_state = JPIM_PHB_STATE_SET_GROUP_INFO;

	if (jpim_check_vm_state(1, vm_id))
    {
        jpim_send_ilm(p, MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_REQ);
        kal_retrieve_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_SET_GROUP_INFO, KAL_OR_CONSUME, &event_group, KAL_SUSPEND);
    }
    else
    {
        free_local_para((local_para_struct*) p);
    }

    return jpim_transfer_error_code(JPIM_PHONEBOOK, jpim_phb_result);
}


/*****************************************************************************
 * FUNCTION
 *  jpim_phb_handler
 * DESCRIPTION
 *
 * PARAMETERS
 *  ilm_ptr     [?]     [?]
 * RETURNS
 *
 *****************************************************************************/
kal_bool jpim_phb_handler(ilm_struct *ilm_ptr)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ilm_ptr->msg_id)
    {
        case MSG_ID_MMI_PHB_JAVA_GET_ENTRY_RSP:
        {
            mmi_phb_handler_get_entry_rsp_struct *p = (mmi_phb_handler_get_entry_rsp_struct*) ilm_ptr->local_para_ptr;

            if (jpim_phb_state == JPIM_PHB_STATE_GET_COUNT)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_GET_COUNT_RSP);

                jpim_phb_result = p->result;
                jpim_phb_count = p->count;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_GETCOUNT, KAL_OR);
            }
            else if (jpim_phb_state == JPIM_PHB_STATE_GET_ENTRY)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_GET_ENTRY_RSP);

                jpim_phb_result = p->result;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_FETCH_INDEX, KAL_OR);
            }
            else
            {
                ASSERT(0);
            }
            jpim_phb_state = JPIM_PHB_STATE_IDLE;
            break;
        }
        case MSG_ID_MMI_PHB_JAVA_SET_ENTRY_RSP:
        {
            mmi_phb_handler_set_entry_rsp_struct *p = (mmi_phb_handler_set_entry_rsp_struct*) ilm_ptr->local_para_ptr;

            if (jpim_phb_state == JPIM_PHB_STATE_APPEND_ENTRY)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_APPEND_ENTRY_RSP);
                jpim_phb_result = p->result;
                jpim_phb_handle = p->store_index;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_APPEND_ENTRY, KAL_OR);
            }
            else if (jpim_phb_state == JPIM_PHB_STATE_UPDATE_ENTRY)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_UPDATE_ENTRY_RSP);
                jpim_phb_result = p->result;
                jpim_phb_handle = p->store_index;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_UPDATE_ENTRY, KAL_OR);
            }
            else if (jpim_phb_state == JPIM_PHB_STATE_DELETE_ENTRY)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_DELETE_ENTRY_RSP);
                jpim_phb_result = p->result;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_DELETE_ENTRY, KAL_OR);
            }
            else
            {
                ASSERT(0);
            }
            jpim_phb_state = JPIM_PHB_STATE_IDLE;
            break;
        }
        case MSG_ID_MMI_PHB_JAVA_SEARCH_ENTRY_RSP:
        {
            mmi_phb_handler_search_entry_rsp_struct *p =
                (mmi_phb_handler_search_entry_rsp_struct*) ilm_ptr->local_para_ptr;

            if (jpim_phb_state == JPIM_PHB_STATE_SEARCH_ENTRY)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_SEARCH_ENTRY_RSP);
                jpim_phb_result = p->result;
                jpim_phb_index = p->index;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_SEARCH_ENTRY, KAL_OR);
            }
            else
            {
                ASSERT(0);
            }
            jpim_phb_state = JPIM_PHB_STATE_IDLE;
            break;
        }
        case MSG_ID_MMI_PHB_JAVA_GET_GROUP_INFO_RSP:
        {
            mmi_phb_handler_get_group_info_rsp_struct *p =
                (mmi_phb_handler_get_group_info_rsp_struct*) ilm_ptr->local_para_ptr;

            if (jpim_phb_state == JPIM_PHB_STATE_GET_GROUP_INFO)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_GET_GROUP_INFO_RSP);
                jpim_phb_result = p->result;
                jpim_phb_count = p->count;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_GET_GROUP_INFO, KAL_OR);
            }
            else if(jpim_phb_state == JPIM_PHB_STATE_GET_GROUP_COUNT)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_GET_GROUP_INFO_RSP);
                jpim_phb_result = p->result;
                jpim_phb_count = p->count;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_GET_GROUP_INFO, KAL_OR);
            }
            else
            {
                ASSERT(0);
            }
            jpim_phb_state = JPIM_PHB_STATE_IDLE;
            break;
        }
        case MSG_ID_MMI_PHB_JAVA_SET_GROUP_INFO_RSP:
        {
            mmi_phb_handler_set_group_info_rsp_struct *p =
                (mmi_phb_handler_set_group_info_rsp_struct*) ilm_ptr->local_para_ptr;

            if (jpim_phb_state == JPIM_PHB_STATE_SET_GROUP_INFO)
            {
                JPIM_DEBUG(TRACE_GROUP_2, JPIM_PHB_SET_GROUP_INFO);
                jpim_phb_result = p->result;
                kal_set_eg_events(g_java_event_group_1, JAVA_EG_PIM_PHB_SET_GROUP_INFO, KAL_OR);
            }
            else
            {
                ASSERT(0);
            }
            jpim_phb_state = JPIM_PHB_STATE_IDLE;
            break;
        }

        default:
            return KAL_FALSE;
    }

    return KAL_TRUE;
}
#endif
