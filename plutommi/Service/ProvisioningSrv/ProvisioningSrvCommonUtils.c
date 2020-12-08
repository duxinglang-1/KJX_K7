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
 * ProvisioningSrvCommonUtils.C
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file will keep common utilities required by PROV.
 *
 * Author:
 * -------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

//#include "MMI_include.h"

#include "MMI_features.h"

#ifndef _PROVISIONINGSRVCOMMONUTILS_C
#define _PROVISIONINGSRVCOMMONUTILS_C

#ifdef __MMI_PROVISIONING_SERVICE_SUPPORT__

#include "ProvisioningSrvMain.h"

//------------------------------ suggest Add ------------------------------
#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"
#include "string.h"
#include "ProvisioningSrvConfiguringSrc.h"
//------------------------------ usage ------------------------------


#ifdef __MMI_PROV_SERVICE_CCA_SUPPORT_ON__

//#include "ProvisioningSrvProt.h"

static U8 g_srv_prov_mempool[SRV_PROV_MAX_MEM_SIZE];
static KAL_ADM_ID g_srv_prov_adm_id = NULL;
static S32 g_srv_prov_mempool_max_alloc;
static S32 g_srv_prov_mempool_total_left;


/*****************************************************************************
 * FUNCTION
 *  srv_prov_init_adm
 * DESCRIPTION
 *  Initializes ADM.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_init_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Init ADM for PROV */
    if (NULL == g_srv_prov_adm_id)
    {
        g_srv_prov_adm_id = kal_adm_create(
                                (void*)g_srv_prov_mempool,
                                (kal_uint32) SRV_PROV_MAX_MEM_SIZE,
                                NULL,
                                (kal_bool) KAL_FALSE);
    }
    ASSERT(g_srv_prov_adm_id);
    g_srv_prov_mempool_max_alloc = kal_adm_get_max_alloc_size(g_srv_prov_adm_id);
    g_srv_prov_mempool_total_left = kal_adm_get_total_left_size(g_srv_prov_adm_id);

    MMI_TRACE(
        SRV_PROV_TRACE_GRP9,
        TRC_MMI_PROV_INIT_MEMORY_ALLOC_LEFT,
        g_srv_prov_mempool_max_alloc,
        g_srv_prov_mempool_total_left);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_deinit_adm
 * DESCRIPTION
 *  Deinit provisioning module.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_deinit_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_adm_delete(g_srv_prov_adm_id);
    g_srv_prov_adm_id = NULL;
    MMI_TRACE(SRV_PROV_TRACE_GRP9, TRC_MMI_PROV_DEINIT_EXIT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_mem_alloc
 * DESCRIPTION
 *  Allocate memory.
 * PARAMETERS
 *  i_size      [IN]        U32      size
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_prov_mem_alloc(U32 i_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *l_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    l_ptr = kal_adm_alloc(g_srv_prov_adm_id, (kal_uint32) i_size);
    g_srv_prov_mempool_max_alloc = kal_adm_get_max_alloc_size(g_srv_prov_adm_id);
    g_srv_prov_mempool_total_left = kal_adm_get_total_left_size(g_srv_prov_adm_id);

    if (NULL == l_ptr)
    {
        MMI_TRACE(
            SRV_PROV_TRACE_GRP9,
            TRC_MMI_PROV_MEM_ALLOC,
            i_size,
            g_srv_prov_mempool_max_alloc,
            g_srv_prov_mempool_total_left);
    }

    return l_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_mem_free
 * DESCRIPTION
 *  Free the memory.
 * PARAMETERS
 *  ptr     [IN]        Void*      input pointer
 * RETURNS
 *  void
 *****************************************************************************/
void srv_prov_mem_free(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(ptr);
    kal_adm_free(g_srv_prov_adm_id, ptr);
}

#ifdef __PROV_OMA_PIN_VALIDATION_SUPPORT__


/*****************************************************************************
 * FUNCTION
 *  srv_prov_char_to_nibble
 * DESCRIPTION
 *  Converts character to nibble value.
 * PARAMETERS
 *  c       [IN]        S8      input ASCII char
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_prov_char_to_nibble(S8 c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ('0' <= c && c <= '9')
    {
        return c - '0';
    }
    else if ('a' <= c && c <= 'f')
    {
        return c - 'a' + 0xa;
    }
    else if ('A' <= c && c <= 'F')
    {
        return c - 'A' + 0xa;
    }
    else
    {
        return 0xF;
    }
}

#endif /* __PROV_OMA_PIN_VALIDATION_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_prov_check_if_substring
 * DESCRIPTION
 *  This function checks whether the sub-string starts with the given string.
 *  on an error it returns -1 else returns 0.
 * PARAMETERS
 *  string_p            [IN]        The main string
 *  sub_string_p        [IN]        The sub string to be checked
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_prov_check_if_substring(const S8 *string_p, const S8 *sub_string_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 start_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string_p == NULL)
    {
        return -1;
    }
    if (sub_string_p == NULL)
    {
        return -1;
    }

    start_len = strlen(sub_string_p);

    if (start_len > strlen(string_p))
    {
        return -1;
    }

    if (0 == (strncmp(string_p, sub_string_p, start_len)))
    {
        return 0;
    }
    else
    {
        return -1;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_index_of_char
 * DESCRIPTION
 *  It returns the index number of a charcter in a buffer.
 * PARAMETERS
 *  ch          [IN]        
 *  buffer      [IN]        
 *  start       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_prov_index_of_char(S8 ch, const S8 *buffer, S32 start)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S8 *p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer == NULL)
    {
        return -1;
    }
    p = (S8*) buffer;
    i = 0;
    while (*p != '\0')
    {
        if (*p == ch && i >= start)
        {
            return i;
        }
        i++;
        p++;
    }
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_get_char_occurence
 * DESCRIPTION
 *  It gives the count of the character ch in the buffer.
 * PARAMETERS
 *  buffer      [IN]        
 *  ch          [IN]        
 *  index       [IN]        
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_prov_get_char_occurence(const S8 *buffer, S32 ch, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count;
    S8 *p;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer == NULL)
    {
        return -1;
    }
    p = (S8*) buffer;
    count = 0;
    i = 0;
    while (*p != '\0')
    {
        if (*p == ch && i >= index)
        {
            count++;
        }
        i++;
        p++;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_prov_copy_utf8_str
 * DESCRIPTION
 *  Copy strings.
 * PARAMETERS
 *  dest_str        [IN]        
 *  src_str         [IN]        
 * RETURNS
 *  SRV_PROV_RETCODE
 *****************************************************************************/
SRV_PROV_RETCODE srv_prov_copy_utf8_str(U8 **dest_str, U8 *src_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_PROV_RETCODE retcode = SRV_PROV_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_str == NULL)
    {
        return retcode;
    }
    ASSERT(*dest_str == NULL);
    *dest_str = srv_prov_mem_alloc(strlen((S8*) src_str) + 1);
    if (NULL == *dest_str)
    {
        retcode = SRV_PROV_MEM_FULL;
        return retcode;
    }
    strcpy((S8*) * dest_str, (S8*) src_str);
    return retcode;
}

#endif /* __MMI_PROV_SERVICE_CCA_SUPPORT_ON__ */ 
#endif /* __PROVISIONING_SERVICE_SUPPORT__ */ 
#endif /* _PROVSERVICECOMMONUTILS_C */ 

