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
*  ProvBoxMisc.c
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  This file implements all kinds of utilites used internally.
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

#include "string.h"
#include "mmi_frm_utility_gprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "MMIDataType.h"
#include "DebugInitDef_Int.h"
#include "Unicodexdcl.h"
#include "App_datetime.h"
#include "ProvBoxSrvProt.h"
#include "ProvBoxSrvGProt.h"

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
#ifdef __MMI_PROVBOX_LOG__
static MMI_BOOL srv_provbox_log_enable = MMI_FALSE;
#endif 


#ifdef __MMI_PROV_IN_UM__

static const srv_um_sim_enum g_srv_provbox_um_sim_id_tbl[] = 
{
    SRV_UM_SIM_GSM_SIM1,

#if (MMI_MAX_SIM_NUM >= 2)
    SRV_UM_SIM_GSM_SIM2,
#endif

#if (MMI_MAX_SIM_NUM >= 3)
    SRV_UM_SIM_GSM_SIM3,
#endif

#if (MMI_MAX_SIM_NUM >= 4)
    SRV_UM_SIM_GSM_SIM4,
#endif

};
#endif /* __MMI_PROV_IN_UM__ */

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/*----------------------Internal Log------------------------------------------*/
#ifdef __MMI_PROVBOX_LOG__
static MMI_BOOL srv_provbox_log_is_enabled(void);
#endif 

/*----------------------Dynamic Pointer Array---------------------------------*/

static srv_provbox_dpary_struct *srv_provbox_dpary_set_init_value(
                                    srv_provbox_dpary_struct *ary,
                                    U32 ary_size,
                                    U32 init_size,
                                    U32 inc_size,
                                    U32 dec_size,
                                    SRV_PROVBOX_DPARY_MALLOC malloc,
                                    SRV_PROVBOX_DPARY_FREE free);

static MMI_BOOL srv_provbox_dpary_is_need_realloc(
                    srv_provbox_dpary_struct *ary,
                    MMI_BOOL increase,
                    S32 change_elm_num);

static srv_provbox_dpary_struct *srv_provbox_dpary_realloc(
                                    srv_provbox_dpary_struct *ary,
                                    MMI_BOOL increase,
                                    S32 change_elm_num);

static srv_provbox_dpary_struct *srv_provbox_dpary_try_realloc(
                                    srv_provbox_dpary_struct *ary,
                                    MMI_BOOL increase,
                                    S32 change_elm_num);

/*----------------------------------------------------------------------------*/
/* Extern Function Declaration                                                */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Internal Log                                                               */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_log_is_enabled
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __MMI_PROVBOX_LOG__
static MMI_BOOL srv_provbox_log_is_enabled(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_provbox_log_enable;
}
#endif /* __MMI_PROVBOX_LOG__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_enable_log
 * DESCRIPTION
 *  
 * PARAMETERS
 *  enable      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_enable_log(MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_PROVBOX_LOG__
    srv_provbox_log_enable = enable;
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_log
 * DESCRIPTION
 *  CCA LOG function
 * PARAMETERS
 *  format      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_provbox_log(CHAR *format, ...)
{
#ifdef __MMI_PROVBOX_LOG__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char log[512];
    va_list arg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_provbox_log_is_enabled())
        return;

    va_start(arg_list, format);

#ifdef __MTK_TARGET__
    vsnprintf(log, 512, format, arg_list);
#else 
    _vsnprintf(log, 512, format, arg_list);
#endif 

    va_end(arg_list);

#ifdef __MTK_TARGET__
    /*
     * PRINT_INFORMATION_2(CCA_TRACE_INFO, "%s", log);
     */
#else 
    kal_printf("%s", log);
#endif 

#endif /* __MMI_PROVBOX_LOG__ */ 
}

/*----------------------------------------------------------------------------*/
/* Time Operation tion Defines                                                */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_curr_time
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_provbox_get_curr_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    applib_dt_get_rtc_time(&time);
    return applib_dt_sec_local_to_utc(applib_dt_mytime_2_utc_sec(&time, MMI_FALSE));
}

/*----------------------------------------------------------------------------*/
/* Flag Operation Function Defines                                            */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_get_flag_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  flag                [IN]        
 *  max_flag_num        [IN]        
 * RETURNS
 *  the bit index of this flag
 *****************************************************************************/
S32 srv_provbox_get_flag_index(U32 flag, U32 max_flag_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(max_flag_num <= SRV_PROVBOX_MAX_U32_BIT_MASK_NUM);

    for (i = 0; i < max_flag_num; i++)
    {
        if ((U32) (1 << i) == flag)
            return (S32) i;
    }
    return -1;
}

/*----------------------------------------------------------------------------*/
/* String Function Defines                                                    */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_ucs2_copy
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_str             [IN]        
 *  dst_str             [IN]        
 *  dst_buf_size        [IN]        
 * RETURNS
 *  destinated string address
 *****************************************************************************/
CHAR *srv_provbox_ucs2_copy(CHAR *dst_str, S32 dst_buf_size, const CHAR *src_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 src_char_len;
    S32 dst_copy_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dst_str == NULL || src_str == NULL)
        return NULL;
    src_char_len = mmi_ucs2strlen((const CHAR*)src_str);

    if ((src_char_len + 1) * ENCODING_LENGTH <= dst_buf_size)
    {
        mmi_ucs2cpy((CHAR*) dst_str, (const CHAR*)src_str);
    }
    else
    {
        /* Please note: mmi_ucs2ncpy already add end char to the destination string */
        dst_copy_len = dst_buf_size / 2 - 1;
        mmi_ucs2ncpy((CHAR*) dst_str, (const CHAR*)src_str, dst_copy_len);
    }
    return dst_str;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_utf8_strdup
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src     [IN]        
 * RETURNS
 *  new string address copied
 *****************************************************************************/
CHAR *srv_provbox_utf8_strdup(const CHAR *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int len;
    CHAR *new_str;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src == NULL || 0 == (len = strlen((const char*)src)))
        return NULL;

    new_str = SRV_PROVBOX_MALLOC(len + 1);
    if (new_str == NULL)
        return NULL;
    strcpy((char*)new_str, (const char*)src);
    return new_str;
}

/*----------------------------------------------------------------------------*/
/* single Link Function Defines                                               */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_slist_add_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 *  node        [IN]        
 * RETURNS
 *  new single link
 *****************************************************************************/
srv_provbox_slist_struct *srv_provbox_slist_add_head(srv_provbox_slist_struct *slist, srv_provbox_slist_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node == NULL)
        return slist;

    node->next = slist;
    return node;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_slist_add_tail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 *  node        [IN]        
 * RETURNS
 *  new single link
 *****************************************************************************/
srv_provbox_slist_struct *srv_provbox_slist_add_tail(srv_provbox_slist_struct *slist, srv_provbox_slist_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_slist_struct *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (node == NULL)
        return slist;

    node->next = NULL;
    if (slist == NULL)
    {
        slist = node;
        return slist;
    }

    cur = slist;
    while (cur != NULL && cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = node;
    return slist;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_slist_insert_sorted
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist               [IN]        
 *  node                [IN]        
 *  compare_func        [IN]        
 * RETURNS
 *  new single link
 *****************************************************************************/
srv_provbox_slist_struct *srv_provbox_slist_insert_sorted(
                            srv_provbox_slist_struct *slist,
                            srv_provbox_slist_struct *node,
                            SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC compare_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_slist_struct *cur;
    srv_provbox_slist_struct *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(compare_func);

    if (slist == NULL)
        return node;
    if (node == NULL)
        return slist;

    node->next = NULL;
    cur = slist;
    prev = slist;

    while (cur != NULL)
    {
        if (compare_func(cur, node) == SRV_PROVBOX_CMP_RESULT_AFTER)
        {
            /* check if node is the head */
            if (cur == slist)
            {
                node->next = slist;
                return node;
            }
            prev->next = node;
            node->next = cur;
            return slist;
        }
        prev = cur;
        cur = cur->next;
    }
    /* node is the tail now */
    prev->next = node;
    return slist;
}


#if 0
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_slist_get_length
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 * RETURNS
 *  node number of the single link
 *****************************************************************************/
U32 srv_provbox_slist_get_length(srv_provbox_slist_struct *slist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i = 0;
    srv_provbox_slist_struct *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur = slist;

    while (cur != NULL)
    {
        i++;
        cur = cur->next;
    }
    return i;
}


#if 0
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_slist_get_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 *  node        [IN]        
 *  index       [IN]        
 * RETURNS
 *  index of the node in the single link
 *****************************************************************************/
MMI_BOOL srv_provbox_slist_get_index(srv_provbox_slist_struct *slist, srv_provbox_slist_struct *node, U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num = 0;
    srv_provbox_slist_struct *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slist == NULL || node == NULL || index == NULL)
        return MMI_FALSE;

    cur = slist;
    while (cur != NULL)
    {
        if (cur == node)
        {
            *index = num;
            return MMI_TRUE;
        }
        num++;
        cur = cur->next;
    }
    *index = 0;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_slist_get_node_by_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist               [IN]        
 *  compare_func        [IN]        
 *  data                [IN]        
 * RETURNS
 *  the node found by comparing the data
 *****************************************************************************/
srv_provbox_slist_struct *srv_provbox_slist_get_node_by_data(
                            srv_provbox_slist_struct *slist,
                            SRV_PROVBOX_SLIST_COMPARE_NODE_FUNC compare_func,
                            void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_slist_struct *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur = slist;
    while (cur != NULL)
    {
        if (SRV_PROVBOX_CMP_RESULT_EQUAL == compare_func(cur, data))
            return cur;
        cur = cur->next;
    }
    return NULL;
}


#if 0
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_slist_get_node_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 *  index       [IN]        
 * RETURNS
 *  the node found by the index
 *****************************************************************************/
srv_provbox_slist_struct *srv_provbox_slist_get_node_by_index(srv_provbox_slist_struct *slist, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    srv_provbox_slist_struct *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur = slist;
    while (cur != NULL)
    {
        if (count == index)
            return cur;
        count++;
        cur = cur->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_slist_reverse
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 * RETURNS
 *  new single link reversed
 *****************************************************************************/
srv_provbox_slist_struct *srv_provbox_slist_reverse(srv_provbox_slist_struct *slist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_slist_struct *cur;
    srv_provbox_slist_struct *new_slist = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slist == NULL)
        return NULL;

    while (slist != NULL)
    {
        cur = slist;
        slist = slist->next;
        if (new_slist == NULL)
        {
            cur->next = NULL;
            new_slist = cur;
        }
        else
        {
            cur->next = new_slist;
            new_slist = cur;
        }
    }
    return new_slist;
}


#if 0
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_slist_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 *  node        [IN]        
 * RETURNS
 *  new single list,
 *  remove node no matter whether the node exists in the single link or not
 *****************************************************************************/
srv_provbox_slist_struct *srv_provbox_slist_remove(srv_provbox_slist_struct *slist, srv_provbox_slist_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_slist_struct *cur;
    srv_provbox_slist_struct *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slist == NULL)
        return NULL;

    if (node == NULL)
        return slist;

    cur = slist;
    prev = slist;
    while (cur != NULL)
    {
        if (cur == node)
        {
            if (cur == slist)   /* remove head */
                slist = slist->next;
            else
                prev->next = cur->next;
            cur->next = NULL;
            return slist;
        }
        prev = cur;
        cur = cur->next;
    }
    return slist;
}


#if 0
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_slist_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist           [IN]        
 *  node            [IN]        
 *  free_func       [IN]        
 * RETURNS
 *  new single link
 *****************************************************************************/
srv_provbox_slist_struct *srv_provbox_slist_delete(
                            srv_provbox_slist_struct *slist,
                            srv_provbox_slist_struct *node,
                            SRV_PROVBOX_SLIST_FREE_NODE_FUNC free_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_slist_struct *cur;
    srv_provbox_slist_struct *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slist == NULL)
        return NULL;

    if (node == NULL)
        return slist;

    cur = slist;
    prev = slist;
    while (cur != NULL)
    {
        if (cur == node)
        {
            if (cur == slist)   /* remove head */
                slist = slist->next;
            else
                prev->next = cur->next;
            cur->next = NULL;
            free_func(cur);
            return slist;
        }
        prev = cur;
        cur = cur->next;
    }
    return slist;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_slist_free_slist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist           [IN]        
 *  free_func       [IN]        
 * RETURNS
 *  new single link
 *****************************************************************************/
srv_provbox_slist_struct *srv_provbox_slist_free_slist(
                            srv_provbox_slist_struct *slist,
                            SRV_PROVBOX_SLIST_FREE_NODE_FUNC free_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_slist_struct *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (slist != NULL)
    {
        cur = slist;
        slist = slist->next;
        cur->next = NULL;
        free_func(cur);
    }
    return NULL;
}

/*----------------------------------------------------------------------------*/
/* Dynamic pointer array                                                      */
/*----------------------------------------------------------------------------*/


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  init_size       [IN]        Initialized array size
 *  inc_size        [IN]        Increase size if need to enlarge the array
 *  dec_size        [IN]        Decrease threshold value to check if need to reduce the array size
 *  malloc          [IN]        To alloc memory
 *  free            [IN]        To free memory
 * RETURNS
 *  The handler of the dynamic pointer array newly created
 *****************************************************************************/
S32 srv_provbox_dpary_new(
        U32 init_size,
        U32 inc_size,
        U32 dec_size,
        SRV_PROVBOX_DPARY_MALLOC malloc,
        SRV_PROVBOX_DPARY_FREE free)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 alloc_size;
    srv_provbox_dpary_struct *ary;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(malloc != NULL && free != NULL);

    if (init_size == 0)
        init_size = 1;
    alloc_size = sizeof(srv_provbox_dpary_struct) + sizeof(void*) * (init_size - 1);

    ary = malloc(alloc_size);
    if (ary == NULL)
        return 0;
    srv_provbox_dpary_set_init_value(ary, init_size, init_size, inc_size, dec_size, malloc, free);
    return (S32) ary;
}


#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_insert_sorted
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hary        [IN]        
 *  elm         [IN]        
 *  compare     [IN]        
 *  index       [OUT]       
 * RETURNS
 *  new array
 *****************************************************************************/
MMI_BOOL srv_provbox_dpary_insert_sorted(S32 *hary, void *elm, SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC compare, U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    MMI_BOOL find = MMI_FALSE;
    srv_provbox_dpary_struct *new_ary;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hary == NULL || *hary == 0)
        return MMI_FALSE;

    if (index)
        *index = 0;
    new_ary = srv_provbox_dpary_try_realloc((srv_provbox_dpary_struct*) (*hary), MMI_TRUE, 1);
    if (new_ary == NULL)
        return MMI_FALSE;

    for (i = new_ary->elm_num; i >= 1; i--)
    {
        if (compare(new_ary->elm[i - 1], elm) == SRV_PROVBOX_CMP_RESULT_AFTER)
        {
            new_ary->elm[i] = new_ary->elm[i - 1];
        }
        else
        {
            new_ary->elm[i] = elm;
            new_ary->elm_num++;
            if (index)
                *index = i;
            find = MMI_TRUE;
            break;
        }
    }
    if (find == MMI_FALSE)
    {
        new_ary->elm[0] = elm;
        new_ary->elm_num++;
        if (index)
            *index = 0;
    }
    *hary = (S32) new_ary;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_get_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hary        [IN]        
 * RETURNS
 *  the element number
 *****************************************************************************/
U32 srv_provbox_dpary_get_num(S32 hary)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hary == 0)

        return 0;
    return ((srv_provbox_dpary_struct*) hary)->elm_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_get_elm_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hary        [IN]        
 *  index       [IN]        
 *  elm         [OUT]       The element found
 * RETURNS
 *  MMI_TRUE: found
 *  MMI_FALSE: not found
 *****************************************************************************/
MMI_BOOL srv_provbox_dpary_get_elm_by_index(S32 hary, U32 index, void **elm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_dpary_struct *ary = (srv_provbox_dpary_struct*) hary;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(elm != NULL);

    *elm = NULL;
    if (hary == 0)
        return MMI_FALSE;
    if (index >= ary->elm_num)
        return MMI_FALSE;
    *elm = ary->elm[index];
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_get_elm_by_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hary        [IN]        
 *  data        [IN]        
 *  compare     [IN]        
 *  elm         [OUT]       The element found
 *  index       [OUT]       The index of the element found
 * RETURNS
 *  MMI_TRUE: find element
 *  MMI_FALSE: not found
 *****************************************************************************/
MMI_BOOL srv_provbox_dpary_get_elm_by_data(
            S32 hary,
            void *data,
            SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC compare,
            void **elm,
            U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 find_index;
    srv_provbox_dpary_struct *ary = (srv_provbox_dpary_struct*) hary;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(compare != NULL || elm != NULL);

    *elm = NULL;
    if (index)
        *index = 0;
    if (hary == 0)
        return MMI_FALSE;

    if (MMI_FALSE == srv_provbox_dpary_get_index_by_data(hary, data, compare, &find_index))
        return MMI_FALSE;

    *elm = ary->elm[find_index];
    if (index)
        *index = find_index;
    return MMI_TRUE;
}


#if 0
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_get_index_by_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hary        [IN]        
 *  data        [IN]        
 *  compare     [IN]        
 *  index       [OUT]       
 * RETURNS
 *  MMI_TRUE: success
 *  MMI_FALSE: fail
 *****************************************************************************/
MMI_BOOL srv_provbox_dpary_get_index_by_data(
            S32 hary,
            void *data,
            SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC compare,
            U32 *index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_provbox_dpary_struct *ary = (srv_provbox_dpary_struct*) hary;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(compare != NULL && index != NULL);

    if (hary == 0)
        return MMI_FALSE;

    for (i = 0; i < ary->elm_num; i++)
    {
        if (SRV_PROVBOX_CMP_RESULT_EQUAL == compare(ary->elm[i], data))
        {
            *index = i;
            return MMI_TRUE;
        }
    }
    *index = 0;
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_replace_elm_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hary        [IN]        
 *  index       [IN]        
 *  new_elm     [IN]        
 *  old_elm     [OUT]       
 * RETURNS
 *  MMI_TRUE: success
 *  MMI_FALSE: fail
 *****************************************************************************/
MMI_BOOL srv_provbox_dpary_replace_elm_by_index(S32 hary, U32 index, void *new_elm, void **old_elm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *cur_elm;
    srv_provbox_dpary_struct *ary = (srv_provbox_dpary_struct*) hary;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hary == 0)
        return MMI_FALSE;

    if (index >= ary->elm_num)
        return MMI_FALSE;

    cur_elm = ary->elm[index];
    ary->elm[index] = new_elm;
    if (old_elm)
        *old_elm = cur_elm;
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_sort
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hary        [IN]        
 *  compare     [IN]        
 * RETURNS
 *  array with all element are sorted
 *****************************************************************************/
S32 srv_provbox_dpary_sort(S32 hary, SRV_PROVBOX_DPARY_COMPARE_ELM_FUNC compare)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    void *cur_elm = NULL;
    srv_provbox_dpary_struct *ary = (srv_provbox_dpary_struct*) hary;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(compare != NULL);

    if (hary == 0)
        return hary;

    for (i = 0; i < ary->elm_num - 1; i++)
    {
        if (cur_elm == NULL)
        {
            if (compare(ary->elm[i], ary->elm[i + 1]) == SRV_PROVBOX_CMP_RESULT_AFTER)
            {
                cur_elm = ary->elm[i];
                ary->elm[i] = ary->elm[i + 1];
            }
        }
        else
        {
            if (i + 2 == ary->elm_num)
            {
                ary->elm[i + 1] = cur_elm;
                break;
            }
            if (compare(ary->elm[i], ary->elm[i + 2]) == SRV_PROVBOX_CMP_RESULT_AFTER)
            {
                ary->elm[i + 1] = ary->elm[i];
                ary->elm[i] = ary->elm[i + 2];
            }
            else
            {
                if (compare(cur_elm, ary->elm[i + 2]) == SRV_PROVBOX_CMP_RESULT_AFTER)
                {
                    ary->elm[i + 1] = ary->elm[i + 2];
                }
                else
                {
                    ary->elm[i + 1] = cur_elm;
                    cur_elm = NULL;
                }
            }
        }
    }

    return hary;
}


#if 0
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
/* under construction !*/
/* under construction !*/
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_remove_elm_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hary        [IN/OUT]        New array
 *  index       [IN]            
 * RETURNS
 *  the element removed
 *****************************************************************************/
void *srv_provbox_dpary_remove_elm_by_index(S32 *hary, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    void *elm;
    srv_provbox_dpary_struct *new_ary;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hary == NULL || *hary == 0)
        return NULL;

    new_ary = (srv_provbox_dpary_struct*) (*hary);

    if (index >= new_ary->elm_num)
        return NULL;

    elm = new_ary->elm[index];

    for (i = index; i < new_ary->elm_num - 1; i++)
    {
        new_ary->elm[i] = new_ary->elm[i + 1];
    }
    new_ary->elm_num--;

    new_ary = srv_provbox_dpary_try_realloc((srv_provbox_dpary_struct*) * hary, MMI_FALSE, 1);

    if (new_ary != NULL)
        *hary = (S32) new_ary;
    return elm;
}


#if 0
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_delete_elm_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hary            [IN/OUT]        
 *  index           [IN]            
 *  free_elm        [IN]            
 * RETURNS
 *  MMI_TRUE: success
 *  MMI_FALSE: fail
 *****************************************************************************/
MMI_BOOL srv_provbox_dpary_delete_elm_by_index(S32 *hary, U32 index, SRV_PROVBOX_DPARY_FREE_ELM_FUNC free_elm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *elm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(free_elm != NULL);

    if (hary == 0)
        return MMI_FALSE;

    elm = srv_provbox_dpary_remove_elm_by_index(hary, index);
    if (elm != NULL)
        free_elm(elm);
    return MMI_TRUE;
}


#if 0
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
#endif /* 0 */


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_delete_all
 * DESCRIPTION
 *  
 * PARAMETERS
 *  hary            [IN]        
 *  free_elm        [IN]        
 * RETURNS
 *  always 0, can use to reset the hary.
 *****************************************************************************/
S32 srv_provbox_dpary_delete_all(S32 hary, SRV_PROVBOX_DPARY_FREE_ELM_FUNC free_elm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    U32 del_num;
    srv_provbox_dpary_struct *new_ary;
    srv_provbox_dpary_struct *ary = (srv_provbox_dpary_struct*) hary;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(free_elm != NULL);

    if (hary == 0)
        return hary;

    for (i = 0; i < ary->elm_num; i++)
    {
        free_elm(ary->elm[i]);
    }
    del_num = ary->elm_num;
    ary->elm_num = 0;
    new_ary = srv_provbox_dpary_try_realloc(ary, MMI_FALSE, del_num);
    if (new_ary != NULL)
        ary = new_ary;
    return (S32) ary;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_set_init_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ary             [IN]        
 *  ary_size        [IN]        
 *  init_size       [IN]        
 *  inc_size        [IN]        
 *  dec_size        [IN]        
 *  malloc          [IN]        
 *  free            [IN]        
 * RETURNS
 *  The array set with init value
 *****************************************************************************/
static srv_provbox_dpary_struct *srv_provbox_dpary_set_init_value(
                                    srv_provbox_dpary_struct *ary,
                                    U32 ary_size,
                                    U32 init_size,
                                    U32 inc_size,
                                    U32 dec_size,
                                    SRV_PROVBOX_DPARY_MALLOC malloc,
                                    SRV_PROVBOX_DPARY_FREE free)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ary == NULL)
        return NULL;

    ary->ary_size = ary_size;
    ary->init_size = init_size;
    ary->inc_size = inc_size;
    ary->dec_size = dec_size;
    ary->elm_num = 0;
    ary->malloc = malloc;
    ary->free = free;

    memset(&ary->elm, 0x0, ary_size * sizeof(void*));
    if (ary->inc_size == 0)
        ary->inc_size++;

    return ary;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_is_need_realloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ary                 [IN]        
 *  increase            [IN]        
 *  change_elm_num      [IN]        Message num to add or remove
 * RETURNS
 *  MMI_TRUE: need realloc;
 *  MMI_FALSE: not need realloc
 *****************************************************************************/
static MMI_BOOL srv_provbox_dpary_is_need_realloc(srv_provbox_dpary_struct *ary, MMI_BOOL increase, S32 change_elm_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(ary);

    if (increase == MMI_FALSE)
        return ((ary->ary_size - ary->elm_num > ary->dec_size) ? MMI_TRUE : MMI_FALSE); /* ary->elm_num already updated, empty slot > threshold ? */
    else
        return ((ary->elm_num + change_elm_num > ary->ary_size) ? MMI_TRUE : MMI_FALSE); /* total num with new items > total slots ? */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_realloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ary                 [IN]        
 *  increase            [IN]        
 *  change_elm_num      [IN]        
 * RETURNS
 *  the new array
 *****************************************************************************/
static srv_provbox_dpary_struct *srv_provbox_dpary_realloc(
                                    srv_provbox_dpary_struct *ary,
                                    MMI_BOOL increase,
                                    S32 change_elm_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 inc_size;
    U32 alloc_size;
    U32 new_ary_size;
    srv_provbox_dpary_struct *new_ary;
    CHAR *src_pos;
    CHAR *dst_pos;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ary == NULL)
        return NULL;

    if (increase == MMI_FALSE)
    {
        MMI_ASSERT(ary->ary_size - ary->elm_num > ary->dec_size);
        new_ary_size = ary->ary_size - (ary->ary_size - ary->elm_num) / ary->dec_size * ary->dec_size;
		new_ary_size = (new_ary_size > ary->init_size ? new_ary_size : ary->init_size);
        alloc_size = sizeof(srv_provbox_dpary_struct) + sizeof(void*) * (new_ary_size - 1);
    }
    else
    {
        MMI_ASSERT(ary->elm_num + change_elm_num > ary->ary_size);
        inc_size = ary->elm_num + change_elm_num - ary->ary_size;
        if (ary->inc_size > inc_size)
            new_ary_size = ary->ary_size + ary->inc_size;
        else
            new_ary_size = ary->ary_size + inc_size;
        alloc_size = sizeof(srv_provbox_dpary_struct) + sizeof(void*) * (new_ary_size - 1);
    }
	
	MMI_ASSERT(new_ary_size >= 1); 
 
    new_ary = ary->malloc(alloc_size);
    if (new_ary == NULL)
        return NULL;

    srv_provbox_dpary_set_init_value(
        new_ary,
        new_ary_size,
        ary->init_size,
        ary->inc_size,
        ary->dec_size,
        ary->malloc,
        ary->free);
    
    new_ary->elm_num = ary->elm_num;

    src_pos = (CHAR*) & ary->elm[0];
    dst_pos = (CHAR*) & new_ary->elm[0];

    if (increase == MMI_FALSE)
    {
		if(ary->elm_num > 0)
	        memcpy((void*)dst_pos, (const void*)src_pos, ary->elm_num * sizeof(void*));
        if (new_ary->ary_size > ary->elm_num)
        {
            dst_pos += ary->elm_num * sizeof(void*);
            memset(dst_pos, 0x0, (new_ary->ary_size - ary->elm_num) * sizeof(void*));
        }
    }
    else
    {
		if(ary->elm_num > 0)
	        memcpy((void*)dst_pos, (const void*)src_pos, ary->elm_num * sizeof(void*));
        if (new_ary->ary_size > ary->elm_num)
        {
            dst_pos += ary->elm_num * sizeof(void*);
            memset(dst_pos, 0x0, (new_ary->ary_size - ary->elm_num) * sizeof(void*));
        }
    }
    new_ary->free(ary);
    return new_ary;
}


/*****************************************************************************
 * FUNCTION
 *  srv_provbox_dpary_try_realloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ary                 [IN]        
 *  increase            [IN]        
 *  change_elm_num      [IN]        The minimum size needed to increase or the element to remove
 * RETURNS
 *  new array
 *****************************************************************************/
static srv_provbox_dpary_struct *srv_provbox_dpary_try_realloc(
                                    srv_provbox_dpary_struct *ary,
                                    MMI_BOOL increase,
                                    S32 change_elm_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ary == NULL)
        return NULL;
    
    if (MMI_FALSE == srv_provbox_dpary_is_need_realloc(ary, increase, change_elm_num))
        return ary;
    
    return srv_provbox_dpary_realloc(ary, increase, change_elm_num);
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
U8 srv_provbox_change_sim_id(U8 sim_id)
{
    return mmi_frm_sim_to_index((mmi_sim_enum) sim_id);
}


#ifdef __MMI_PROV_IN_UM__

/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_box_type_enum srv_provbox_box_type_um2pbox(srv_um_msg_box_enum um_box_type)
{
    srv_provbox_box_type_enum srv_box_type = SRV_PROVBOX_BOX_TYPE_UNKNOWN;


    if (um_box_type & SRV_UM_MSG_BOX_INBOX)
    {
        srv_box_type |= SRV_PROVBOX_BOX_TYPE_INBOX;
    }
    
#ifdef __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__
    if (um_box_type & SRV_UM_MSG_BOX_ARCHIVE)
    {
        srv_box_type |= SRV_PROVBOX_BOX_TYPE_ARCHIVE;
    }
#endif /* __MMI_PROV_MESSAGE_ARCHIVE_SUPPORT__ */

    return srv_box_type;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
srv_um_sim_enum srv_provbox_sim_pbox2um(mmi_sim_enum prov_box_sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(prov_box_sim & MMI_SIM_ALL);
    
    return g_srv_provbox_um_sim_id_tbl[mmi_frm_sim_to_index(prov_box_sim)];;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
mmi_sim_enum srv_provbox_sim_um2pbox(srv_um_sim_enum um_sim)
{
    U32 i;


    for (i = 0; i < sizeof(g_srv_provbox_um_sim_id_tbl)/sizeof(srv_um_sim_enum); i++)
    {
        if (g_srv_provbox_um_sim_id_tbl[i] == um_sim)
            return mmi_frm_index_to_sim(i);
    }
    return MMI_SIM_NONE;
}



/*****************************************************************************
 * FUNCTION
 *  srv_provbox_addr_type_pbox2um
 * DESCRIPTION
 *  
 * PARAMETERS
 *  provbox_type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_um_addr_enum srv_provbox_addr_type_pbox2um(srv_provbox_addr_type_enum provbox_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_um_addr_enum um_addr_type = SRV_UM_ADDR_EMPTY;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (provbox_type)
    {
        case SRV_PROVBOX_ADDR_TYPE_PHONENUM:
            um_addr_type = SRV_UM_ADDR_PHONE_NUMBER;
            break;

        case SRV_PROVBOX_ADDR_TYPE_IPV4:
            um_addr_type = SRV_UM_ADDR_IP_ADDRESS;
            break;

        case  SRV_PROVBOX_ADDR_TYPE_TEXT:
            um_addr_type = SRV_UM_ADDR_PLAIN_TEXT;
            break;
            
        default:
            break;
    }
    
    return um_addr_type;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_provbox_read_status_pbox2um(srv_provbox_msg_read_status_enum read_status)
{
    MMI_BOOL result = MMI_FALSE;


    if (read_status == SRV_PROVBOX_MSG_READ_STATUS_UNREAD)
    {
        result = MMI_FALSE;
    }
    else if (read_status == SRV_PROVBOX_MSG_READ_STATUS_READ)
    {
        result = MMI_TRUE;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
srv_provbox_msg_op_enum srv_provbox_op_type_um2pbox(srv_um_mark_several_op_action_enum um_op_type)
{
    srv_provbox_msg_op_enum pbox_op_type = SRV_PROVBOX_MSG_OP_NONE;
    
    
    switch(um_op_type)
    {
        case SRV_UM_MARK_SEVERAL_OP_ACTION_DELETE:
            pbox_op_type = SRV_PROVBOX_MSG_OP_DELETE;
            break;
            
        case SRV_UM_MARK_SEVERAL_OP_ACTION_MOVE_TO_ARCHIVE:
            pbox_op_type = SRV_PROVBOX_MSG_OP_MOVE_TO_ARCHIVE;
            break;
            
        default:
            break;
    }
    
    return pbox_op_type;
}

#endif /* __MMI_PROV_IN_UM__ */


#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */ 

