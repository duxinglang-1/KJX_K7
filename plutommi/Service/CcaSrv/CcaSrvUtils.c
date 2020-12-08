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
*  CentralConfigAgentMisc.c
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/


//#ifdef __CCA_SUPPORT__
/*----------------------------------------------------------------------------*/
/* Comments                                                                   */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "MMI_include.h"

#include "string.h"

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "kal_public_api.h"
#include "kal_trace.h"
#include "kal_debug.h"

#include "che_api.h"

#include "MMIDataType.h"
#include "MMI_inet_app_trc.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_queue_gprot.h"

#include "CcaSrvGprot.h"
#include "CcaSrvConfig.h"
#include "CcaSrvProt.h"


#ifdef __MMI_CCA_SUPPORT__


/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define  SRV_CCA_DUMP_BUFF_SIZE                     (256)


/*----------------------------------------------------------------------------*/
/* Macro                                                                      */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/
typedef struct  
{
    KAL_ADM_ID adm_id;
    U8 pool[SRV_CCA_MAX_MEM_SIZE];
    SRV_CCA_MEM_FULL_HDLR mf_hdlr_tbl[SRV_CCA_MEM_FULL_MAX_ITEM];
} srv_cca_mem_cntx_struct;

/*----------------------------------------------------------------------------*/
/* Static Global Variable                                                     */
/*----------------------------------------------------------------------------*/
static srv_cca_mem_cntx_struct g_srv_cca_mem_cntx;

/*----------------------------------------------------------------------------*/
/* Static Function Declaration                                                */
/*----------------------------------------------------------------------------*/
/* Memory Init */
static void srv_cca_trigger_memfull_notify(void);

/*----------------------------------------------------------------------------*/
/* Extern Function Defines                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Function Definition                                                        */
/*----------------------------------------------------------------------------*/


#define SRV_CCA_DOC_DUMP

#ifdef __SRV_CCA_DUMP__
/*****************************************************************************
 * FUNCTION
 *  srv_cca_log
 * DESCRIPTION
 *  CCA LOG function
 * PARAMETERS
 *  format      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_log(CHAR *format, ...)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR log[SRV_CCA_DUMP_BUFF_SIZE];
    va_list arg_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    va_start(arg_list, format);
#ifdef __MTK_TARGET__
    vsnprintf(log, SRV_CCA_DUMP_BUFF_SIZE, format, arg_list);
#else 
    _vsnprintf(log, SRV_CCA_DUMP_BUFF_SIZE, format, arg_list);
#endif 
    va_end(arg_list);

#ifdef __MTK_TARGET__
    /*
     * PRINT_INFORMATION_2(SRV_CCA_TRC_INFO, "%s", log);
     */
#else 
    kal_printf("%s", log);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_dump_coredata
 * DESCRIPTION
 *  
 * PARAMETERS
 *  coredata        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dump_coredata(srv_cca_core_data_struct *coredata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!coredata)
        return;

    kal_printf("\tParam ID: %X\tType: %d\tSize: %d\tData: {", coredata->id, coredata->type, coredata->size);
    for (i = 0; i < coredata->size; i++)
    {
        if (coredata->type == 0)
            kal_printf("%x", coredata->values.i[i]);
        else
        {
            if (coredata->values.s[i])
                kal_printf("\"%s\"", coredata->values.s[i]);
            else
                kal_printf("<null>");
        }

        if (i < coredata->size - 1)
            kal_printf(", ");
        else
            kal_printf("}\n");
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_dump_iter_datalist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  iter_datalist       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dump_iter_datalist(srv_cca_iterator_struct *iter_datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_datalist_struct *datalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((datalist = (srv_cca_doc_node_datalist_struct*) srv_cca_iterator_next(iter_datalist)))
        srv_cca_dump_coredata(&(datalist->data));
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_dump_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  node        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dump_node(srv_cca_doc_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_iterator_struct *iterDatalist;
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!node)
        return;

    kal_printf("Node ID: %X\tNum Data: %d\tNum Child: %d\n", node->node_id, node->num_data, node->num_child);

    iterDatalist = srv_cca_iterator_new(SRV_CCA_TR_LIST, SRV_CCA_IT_DATALIST, (srv_cca_generic_ptr_struct*) node->listchain, 0);
    if (!iterDatalist)
    {
        kal_printf("Error: Memory full!\n");
        return;
    }
    while (srv_cca_doc_nodedata_next(iterDatalist, &coredata) == SRV_CCA_STATUS_OK)
        srv_cca_dump_coredata(coredata);
    srv_cca_iterator_release(iterDatalist);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_dump_iter_nodelist
 * DESCRIPTION
 *  
 * PARAMETERS
 *  iter_nodelist       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dump_iter_nodelist(srv_cca_iterator_struct *iter_nodelist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_nodelist_struct *nodelist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((nodelist = (srv_cca_doc_nodelist_struct*) srv_cca_iterator_next(iter_nodelist)))
        srv_cca_dump_node(nodelist->node);
}





/*****************************************************************************
 * FUNCTION
 *  srv_cca_dump_doc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  root        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_dump_doc(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_iterator_struct *iter;
    srv_cca_doc_node_struct *crtNode;
    srv_cca_generic_ptr_struct *root;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hConfig)
        return;
    root = (srv_cca_generic_ptr_struct*)(((srv_cca_document_struct*)hConfig)->doc_tree);
    if (!root)
        return;
    
    iter = srv_cca_iterator_new(SRV_CCA_TR_PREORDER, SRV_CCA_IT_DOC, root, 0);
    if (!iter)
    {
        kal_printf("Error: Memory full!\n");
        return;
    }
    while ((crtNode = (srv_cca_doc_node_struct*) srv_cca_iterator_next(iter)))
    {
        kal_printf("LEVEL %d\t", iter->crt_level);
        srv_cca_dump_node(crtNode);
    }

    srv_cca_iterator_release(iter);
}

#endif /* __SRV_CCA_DUMP__ */



/*****************************************************************************
 * FUNCTION
 *  srv_cca_generate_hash_value
 * DESCRIPTION
 *  revise the sim_id
 * PARAMETERS
 *  src_string      [IN]        
 *  dst_buf         [OUT]       
 *  buf_len         [IN]        
 * RETURNS
 *  new sim_id
 *****************************************************************************/
srv_cca_status_enum srv_cca_generate_hash_value(const CHAR *src_string, U8 *dst_buf, int buf_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    STCHE che_ctnx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src_string == NULL || src_string[0] == '\0' || dst_buf == NULL || buf_len < SRV_CCA_HASH_VALUE_MAX_BYTES)
        return SRV_CCA_STATUS_FAIL;

    che_init(&che_ctnx, CHE_MD5);
    che_process(
        &che_ctnx,
        CHE_MD5,
        CHE_MODE_NULL,
        CHE_HASH,
        (kal_uint8*) src_string,
        (kal_uint8*) dst_buf,
        strlen(src_string),
        KAL_TRUE);
    che_deinit(&che_ctnx);

    return SRV_CCA_STATUS_OK;
}


#define SRV_CCA_MEMORY


/*****************************************************************************
 * FUNCTION
 *  srv_cca_mem_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_mem_init(void)
{
    g_srv_cca_mem_cntx.adm_id = kal_adm_create(g_srv_cca_mem_cntx.pool, 
        SRV_CCA_MAX_MEM_SIZE, NULL, KAL_FALSE);

    SRV_CCA_ASSERT(g_srv_cca_mem_cntx.adm_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_malloc
 * DESCRIPTION
 *  CCA malloc function
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_cca_malloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ptr = kal_adm_alloc(g_srv_cca_mem_cntx.adm_id, (kal_uint32) size);
    if (!ptr)
    {
        srv_cca_trigger_memfull_notify();
        
        MMI_TRACE(SRV_CCA_TRC_ERROR, TRC_SRV_CCA_MALLOC_MEMORY_INFO, 
            size, kal_adm_get_max_alloc_size(g_srv_cca_mem_cntx.adm_id),
            kal_adm_get_total_left_size(g_srv_cca_mem_cntx.adm_id));
        
        MMI_TRACE(SRV_CCA_TRC_ERROR, TRC_SRV_CCA_MALLOC_NULL);
    }


#ifdef  __SRV_CCA_PRINT_MEM_INFO__

    SRV_CCA_LOG(("Malloc: size =%d, max alloc=%d, total left=%d\n\n",
            size, kal_adm_get_max_alloc_size(g_srv_cca_mem_cntx.adm_id),
            kal_adm_get_total_left_size(g_srv_cca_mem_cntx.adm_id)));

    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_MALLOC_MEMORY_INFO, 
        size, kal_adm_get_max_alloc_size(g_srv_cca_mem_cntx.adm_id),
        kal_adm_get_total_left_size(g_srv_cca_mem_cntx.adm_id));

#endif /* __SRV_CCA_PRINT_MEM_INFO__ */


    return ptr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_mfree
 * DESCRIPTION
 *  CCA mfree function
 * PARAMETERS
 *  ptr     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_mfree(void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!ptr)
        return;
    
    kal_adm_free(g_srv_cca_mem_cntx.adm_id, ptr);


    
#ifdef  __SRV_CCA_PRINT_MEM_INFO__

    SRV_CCA_LOG(("Free: size =?, max alloc=%d, total left=%d\n\n",
            kal_adm_get_max_alloc_size(g_srv_cca_mem_cntx.adm_id),
            kal_adm_get_total_left_size(g_srv_cca_mem_cntx.adm_id)));

    /* alloc = -100 means it's free */
    MMI_TRACE(SRV_CCA_TRC_INFO, TRC_SRV_CCA_MALLOC_MEMORY_INFO, 
            -100, kal_adm_get_max_alloc_size(g_srv_cca_mem_cntx.adm_id),
            kal_adm_get_total_left_size(g_srv_cca_mem_cntx.adm_id));
    
#endif /* __SRV_CCA_PRINT_MEM_INFO__ */


}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_register_memfull_notify
 * DESCRIPTION
 *  register a callback func to be triggered when CCA mem full
 * PARAMETERS
 *  callback        [IN]        
 *  identifier      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_register_memfull_notify(SRV_CCA_MEM_FULL_HDLR hdlr, U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CCA_ASSERT(type < SRV_CCA_MEM_FULL_MAX_ITEM);
    g_srv_cca_mem_cntx.mf_hdlr_tbl[type] = hdlr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_deregister_memfull_notify
 * DESCRIPTION
 *  deregister a memfull callback func
 * PARAMETERS
 *  identifier      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_deregister_memfull_notify(U32 type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CCA_ASSERT(type < SRV_CCA_MEM_FULL_MAX_ITEM);
    g_srv_cca_mem_cntx.mf_hdlr_tbl[type] = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_trigger_memfull_notify
 * DESCRIPTION
 *  trigger all memfull notify func
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_trigger_memfull_notify(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_CCA_MEM_FULL_MAX_ITEM; i++)
    {
        if (g_srv_cca_mem_cntx.mf_hdlr_tbl[i])
            g_srv_cca_mem_cntx.mf_hdlr_tbl[i] (i);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_slist_add_tail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 *  node        [IN]        
 * RETURNS
 *  new single link
 *****************************************************************************/
srv_cca_slist_struct *srv_cca_slist_add_tail(srv_cca_slist_struct *slist, srv_cca_slist_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_slist_struct *cur;

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
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = node;
    return slist;
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_slist_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 *  node        [IN]        
 * RETURNS
 *  new single list,
 *  remove node no matter whether the node exists in the single link or not
 *****************************************************************************/
srv_cca_slist_struct *srv_cca_slist_remove(srv_cca_slist_struct *slist, srv_cca_slist_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_slist_struct *cur;
    srv_cca_slist_struct *prev;

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
            if (cur == slist)
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


/*****************************************************************************
 * FUNCTION
 *  srv_cca_slist_remove
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 *  node        [IN]        
 * RETURNS
 *  new single list,
 *  remove node no matter whether the node exists in the single link or not
 *****************************************************************************/
srv_cca_slist_struct *srv_cca_slist_remove_by_index(srv_cca_slist_struct **slist, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    srv_cca_slist_struct *cur;
    srv_cca_slist_struct *prev;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slist == NULL || *slist == NULL)
        return NULL;

    cur = *slist;
    prev = *slist;
    while (cur != NULL)
    {
        if (count == index)
        {
            if (cur == *slist)
                *slist = (*slist)->next;
            else
                prev->next = cur->next;
            cur->next = NULL;
            return cur;
        }
        prev = cur;
        cur = cur->next;
        count++;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_slist_get_node_by_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 *  index       [IN]        
 * RETURNS
 *  the node found by the index
 *****************************************************************************/
srv_cca_slist_struct *srv_cca_slist_get_node_by_index(srv_cca_slist_struct *slist, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    srv_cca_slist_struct *cur;

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
 *  mmi_provbox_slist_get_node_by_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist               [IN]        
 *  compare_func        [IN]        
 *  data                [IN]        
 * RETURNS
 *  the node found by comparing the data
 *****************************************************************************/
srv_cca_slist_struct *srv_cca_slist_get_node_by_data(
                            srv_cca_slist_struct *slist,
                            SRV_CCA_SLIST_CMP_FUNC compare_func,
                            void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_slist_struct *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur = slist;
    while (cur != NULL)
    {
        if (SRV_CCA_CMP_RESULT_EQUAL == compare_func(cur, data))
            return cur;
        cur = cur->next;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_slist_get_num_by_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist               [IN]        
 *  compare_func        [IN]        
 *  data                [IN]        
 * RETURNS
 *  the node found by comparing the data
 *****************************************************************************/
S32 srv_cca_slist_get_num_by_data(
                            srv_cca_slist_struct *slist,
                            SRV_CCA_SLIST_CMP_FUNC compare_func,
                            void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count = 0;
    srv_cca_slist_struct *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cur = slist;
    while (cur != NULL)
    {
        if (SRV_CCA_CMP_RESULT_EQUAL == compare_func(cur, data))
            count++;
        cur = cur->next;
    }
    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_slist_get_index
 * DESCRIPTION
 *  
 * PARAMETERS
 *  slist       [IN]        
 *  node        [IN]        
 *  index       [IN]        
 * RETURNS
 *  index of the node in the single link
 *****************************************************************************/
S32 srv_cca_slist_get_index(srv_cca_slist_struct *slist, srv_cca_slist_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 num = 0;
    srv_cca_slist_struct *cur;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (slist == NULL || node == NULL)
        return -1;

    cur = slist;
    while (cur != NULL)
    {
        if (cur == node)
            return num;
        num++;
        cur = cur->next;
    }
    return -1;
}




#endif /* __CCA_SUPPORT__ */




