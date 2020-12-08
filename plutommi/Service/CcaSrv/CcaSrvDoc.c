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
 *  CentralConfigAgentDocument.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  CCA Document Manipulation Functions
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

//#ifdef __CCA_SUPPORT__

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
#include "MMI_features.h"
#include "MMI_include.h"

#include "string.h"

#include "kal_general_types.h"
#include "kal_public_api.h"

#include "MMIDataType.h"
#include "DebugInitDef_Int.h"


#include "CcaSrvGProt.h"
#include "CcaSrvConfig.h"
#include "CcaSrvProt.h"

#ifdef __MMI_CCA_SUPPORT__

/*----------------------------------------------------------------------------*/
/* Macro define                                                               */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Constant                                                                   */
/*----------------------------------------------------------------------------*/
#define CCA_TREE_MAX_LEVELS     10      /* includes root, so max 10 = root + level 1 to 9 */

/*----------------------------------------------------------------------------*/
/* Enum                                                                       */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Typedef                                                                    */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Structure                                                                  */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static API declaration                                                     */
/*----------------------------------------------------------------------------*/
#define SRV_CCA_DOC_API_LIST

/* Core Data */
static srv_cca_status_enum srv_cca_doc_coredata_extend(srv_cca_core_data_struct *data_obj, U32 num_extend);
#if 0
/* under construction !*/
#endif

#ifdef __SRV_CCA_SLIM__
static srv_cca_status_enum srv_cca_doc_update_coredata(srv_cca_core_data_struct *data_obj, srv_cca_data_type_enum data_type, S32 size, const void* values);
#endif

static srv_cca_status_enum srv_cca_doc_update_coredata_ints(srv_cca_core_data_struct *data_obj, S32 size, const S32 *values);
static srv_cca_status_enum srv_cca_doc_update_coredata_strs(srv_cca_core_data_struct *data_obj, S32 size, const CHAR **values);

static S32 srv_cca_doc_coredata_values_exists_int(S32 *values_i, S32 size, S32 val);
static S32 srv_cca_doc_coredata_exists_int(srv_cca_core_data_struct *coredata, S32 val);
static S32 srv_cca_doc_coredata_exists_str(srv_cca_core_data_struct *coredata, CHAR *str);

#ifdef __SRV_CCA_SLIM__
static S32 srv_cca_doc_coredata_is_subset(srv_cca_core_data_struct *dst, srv_cca_core_data_struct *src);
#endif

static S32 srv_cca_doc_coredata_is_equal(srv_cca_core_data_struct *cd1, srv_cca_core_data_struct *cd2);

/* Data List */
static void srv_cca_doc_datalist_attach_to_node(srv_cca_doc_node_struct *node, srv_cca_doc_node_datalist_struct *datalist);
static srv_cca_doc_node_datalist_struct *srv_cca_doc_detach_datalist(srv_cca_doc_node_struct *node, U16 param_id);
static S32 srv_cca_doc_datalist_has_param_value(
            srv_cca_doc_node_datalist_struct *datalist,
            U16 param_id,
            srv_cca_data_type_enum datatype,
            void *value);


/* Node */
#if 0
/* under construction !*/
#endif

static void srv_cca_doc_node_release(srv_cca_doc_node_struct *node, U8 deep_delete);
static void srv_cca_doc_node_release_all_recur(S32 hNode);

#ifdef __SRV_CCA_SLIM__
static S32 srv_cca_doc_node_datalist_check_subset(srv_cca_doc_node_datalist_struct *dst, srv_cca_doc_node_datalist_struct *src);
#endif

/* Node Data */

#ifdef __SRV_CCA_SLIM__
static srv_cca_status_enum srv_cca_doc_add_nodedata(S32 hNode, U16 param_id, srv_cca_data_type_enum data_type, S32 size, const void *values);
#endif
static srv_cca_status_enum srv_cca_doc_add_nodedata_ints(S32 hNode, U16 param_id, S32 size, const S32 *values);
static srv_cca_status_enum srv_cca_doc_add_nodedata_strs(S32 hNode, U16 param_id, S32 size, const CHAR **values);

#ifdef __SRV_CCA_SLIM__
static srv_cca_status_enum srv_cca_doc_update_nodedata(S32 hNode, U16 param_id, srv_cca_data_type_enum data_type, S32 size, const void *values);
static srv_cca_status_enum srv_cca_doc_nodedata_first(S32 hNode, U16 param_id, srv_cca_data_type_enum data_type, void *value);
static srv_cca_status_enum srv_cca_doc_nodedata(S32 hNode, U16 param_id, srv_cca_data_type_enum data_type, void **values, S32 *size);
#endif /* __SRV_CCA_SLIM__ */

/* Node List*/
static srv_cca_doc_nodelist_struct *srv_cca_doc_nodelist_new(srv_cca_doc_node_struct *node);
static void srv_cca_doc_nodelist_release(srv_cca_doc_nodelist_struct *nodelist, U8 deep_delete);

/* Iterator */
static void srv_cca_iterator_fill(
                srv_cca_iterator_struct *iter,
                srv_cca_traverse_type_enum trType,
                srv_cca_iter_type_enum itType,
                srv_cca_generic_ptr_struct *begin,
                U8 dpDel);
static void srv_cca_iterator_next_preorder_node(srv_cca_iterator_struct *iter);

/* Nodedata list iterator */
#ifdef __SRV_CCA_SLIM__
static srv_cca_status_enum srv_cca_doc_get_nodedata_first(srv_cca_iterator_struct *iter, U16 param_id, srv_cca_data_type_enum data_type, void *value);
static srv_cca_status_enum srv_cca_doc_get_nodedata_list(srv_cca_iterator_struct *iter, U16 param_id, srv_cca_data_type_enum data_type, void **values, S32 *size);
#endif /* __SRV_CCA_SLIM__ */

/* Node List Iterator */
static srv_cca_doc_iter_nodes_struct *srv_cca_doc_iter_nodes_new(U16 node_id);
static void srv_cca_doc_iter_nodes_list_release(srv_cca_doc_iter_nodes_struct *iter_nodes_list, U8 releaseLevel);
static srv_cca_doc_iter_nodes_struct *srv_cca_doc_iter_nodes_find(srv_cca_doc_iter_nodes_struct *iter_nodes_list, U16 node_id);
static srv_cca_doc_iter_nodes_struct *srv_cca_doc_construct_iter_nodes_list(srv_cca_doc_node_struct *root);

/* Document Parsing */
static srv_cca_doc_node_struct *srv_cca_doc_parse_mapping_table(const U16 *table, S32 size);
static srv_cca_doc_node_struct *srv_cca_doc_match(srv_cca_doc_node_struct *root, U16 *path, U32 size);

/*----------------------------------------------------------------------------*/
/* Extern API declaration                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Static global variable                                                     */
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* End                                                                        */
/*----------------------------------------------------------------------------*/

#define SRV_CCA_DOC_UTILS
/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_link_list_elem_to_last
 * DESCRIPTION
 *  link the element to the end of a generic list
 * PARAMETERS
 *  start       [IN]        
 *  elem        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_doc_link_list_elem_to_last(srv_cca_generic_ptr_struct **start, srv_cca_generic_ptr_struct *elem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_generic_ptr_struct *crt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(*start))
    {
        /* list is empty */
        *start = elem;
    }
    else
    {
        /* find last elem in list */
        crt = *start;
        while (crt->next)
            crt = crt->next;

        /* attach elem to end of list */
        crt->next = elem;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_list_find
 * DESCRIPTION
 *  to find an elem from the specified list
 * PARAMETERS
 *  list            [IN]        
 *  fpEqual         [IN]        
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_cca_doc_list_find(srv_cca_generic_ptr_struct *list, SRV_CCA_FP_LIST_ELEM_EQUAL fpEqual, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (list)
    {
        if (fpEqual((void*)list, user_data))
            return (void*)list;
        list = list->next;
    }
    return 0;
}



#define SRV_CCA_DOC_COREDATA


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_check
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_coredata            [IN]        
 *  result                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_coredata_check(SRV_CCA_HANDLE h_coredata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata = (srv_cca_core_data_struct*)h_coredata;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!h_coredata)
        return SRV_CCA_STATUS_INVALID_PARAM;

    if (coredata->id == 0 || coredata->type >= SRV_CCA_DATA_TYPE_MAX_ITEM)
        return SRV_CCA_STATUS_INVALID_PARAM;
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_data_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_coredata            [IN]        
 *  result                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_cca_doc_coredata_get_data_type(SRV_CCA_HANDLE h_coredata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct  *core_data = SRV_CCA_H2P(h_coredata, srv_cca_core_data_struct);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CCA_H_CHK(h_coredata))
        return SRV_CCA_INVALID_CORE_DATA;
    return core_data->type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_coredata            [IN]        
 *  result                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_cca_doc_coredata_get_param_id(SRV_CCA_HANDLE h_coredata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct  *core_data = SRV_CCA_H2P(h_coredata, srv_cca_core_data_struct);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CCA_H_CHK(h_coredata))
        return SRV_CCA_INVALID_CORE_DATA;
    return core_data->id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_coredata            [IN]        
 *  result                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_cca_doc_coredata_get_num(SRV_CCA_HANDLE h_coredata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct  *core_data = SRV_CCA_H2P(h_coredata, srv_cca_core_data_struct);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CCA_H_CHK(h_coredata))
        return SRV_CCA_INVALID_CORE_DATA;
    return core_data->size;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_coredata            [IN]        
 *  result                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_cca_doc_coredata_get_int(SRV_CCA_HANDLE h_coredata, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct  *core_data = SRV_CCA_H2P(h_coredata, srv_cca_core_data_struct);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CCA_H_CHK(h_coredata))
        return SRV_CCA_INVALID_CORE_DATA;
    if (index >= core_data->size)
        return SRV_CCA_INVALID_CORE_DATA;
    return core_data->values.i[index];
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_get_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  h_coredata            [IN]        
 *  result                [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
CHAR *srv_cca_doc_coredata_get_str(SRV_CCA_HANDLE h_coredata, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct  *core_data = SRV_CCA_H2P(h_coredata, srv_cca_core_data_struct);
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!SRV_CCA_H_CHK(h_coredata))
        return NULL;
    if (index >= core_data->size)
        return NULL;
    return core_data->values.s[index];
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_extend
 * DESCRIPTION
 *  pre: valid coredata obj ptr & initialised
 *  extend the size of coredata value array by the specified num_extend
 * PARAMETERS
 *  data_obj        [IN]        
 *  num_extend      [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
static srv_cca_status_enum srv_cca_doc_coredata_extend(srv_cca_core_data_struct *data_obj, U32 num_extend)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *values_i;
    CHAR **values_s;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    values_i = 0;
    values_s = 0;
    if (data_obj->type == SRV_CCA_DATA_TYPE_INT)
    {
        values_i = (S32*) srv_cca_malloc((num_extend + data_obj->size) * sizeof(S32));
        if (!values_i)
            return SRV_CCA_STATUS_MEMFULL;

        kal_mem_set(values_i, 0, (num_extend + data_obj->size) * sizeof(S32));
        if (data_obj->values.i)
        {
            kal_mem_cpy(values_i, data_obj->values.i, data_obj->size * sizeof(S32));
            srv_cca_mfree(data_obj->values.i);
        }
        data_obj->values.i = values_i;
        data_obj->size += num_extend;
    }
    else if (data_obj->type == SRV_CCA_DATA_TYPE_STR)
    {
        values_s = (CHAR **) srv_cca_malloc((num_extend + data_obj->size) * sizeof(CHAR*));
        if (!values_s)
            return SRV_CCA_STATUS_MEMFULL;

        kal_mem_set(values_s, 0, (num_extend + data_obj->size) * sizeof(CHAR*));
        if (data_obj->values.s)
        {
            kal_mem_cpy(values_s, data_obj->values.s, data_obj->size * sizeof(CHAR*));
            srv_cca_mfree(data_obj->values.s);
        }
        data_obj->values.s = values_s;
        data_obj->size += num_extend;
    }
    else
    {
        SRV_CCA_ASSERT(0);
    }
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_append
 * DESCRIPTION
 *  pre: valid coredata obj ptr & initialised & coredata type matches "type" parameter
 *  append values array to the existing coredata
 * PARAMETERS
 *  data_obj        [IN]        
 *  size            [IN]        
 *  values          [IN]        Type of values: S32* if int, CHAR** if str
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_coredata_append(srv_cca_core_data_struct *data_obj, S32 size, void *values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, offset, txtsize, absindex;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cca_doc_coredata_extend(data_obj, size) == SRV_CCA_STATUS_MEMFULL)
        return SRV_CCA_STATUS_MEMFULL;

    offset = data_obj->size - size;
    if (data_obj->type == SRV_CCA_DATA_TYPE_INT)
    {
        kal_mem_cpy(data_obj->values.i + offset, values, size * sizeof(S32));
    }
    else
    {
        for (i = 0; i < size; i++)
        {
            absindex = i + offset;
            if (((CHAR **) values)[i])
                txtsize = strlen((const char*)((CHAR **) values)[i]) + 1;
            else
                txtsize = 0;

            if (!txtsize)
            {
                data_obj->values.s[absindex] = 0;
                continue;
            }

            data_obj->values.s[absindex] = (CHAR*) srv_cca_malloc(txtsize * sizeof(CHAR));
            if (data_obj->values.s[absindex])
            {
                data_obj->values.s[absindex][0] = 0;
                if (((CHAR **) values)[i])
                    kal_mem_cpy(data_obj->values.s[absindex], (void*)((CHAR **) values)[i], txtsize * sizeof(CHAR));
            }
            else
            {
                /* free all alloc string mem just then */
                i--;    /* ignore index of last elem that just malloc as alloc failed */
                while ((i -= 1) >= 0)
                    srv_cca_mfree(data_obj->values.s[i + offset]);

                /* restore coredata size state (the extended mem slots arent freed 'cos too much troubles
                   to alloc another array with less elements and re-copy all data back in)
                   the extended mem will still be freed later on when coredata is freed */
                data_obj->size -= size;
                if (data_obj->size == 0)
                {
                    srv_cca_mfree(data_obj->values.s);
                    data_obj->values.s = 0;
                }
                return SRV_CCA_STATUS_MEMFULL;
            }
        }
    }
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_reset
 * DESCRIPTION
 *  free all memory occupied by the value array in coredata and reset all its parameters
 * PARAMETERS
 *  coredata        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_doc_coredata_reset(srv_cca_core_data_struct *coredata)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!coredata)
        return;

    srv_cca_doc_coredata_release_values(coredata);

    coredata->id = 0;
    coredata->size = 0;
    coredata->type = SRV_CCA_DATA_TYPE_INT;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_release_values
 * DESCRIPTION
 *  free all memory occupied by the value array in coredata
 * PARAMETERS
 *  coredata        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_doc_coredata_release_values(srv_cca_core_data_struct *coredata)
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

    if (coredata->type == SRV_CCA_DATA_TYPE_INT)
    {
        if (coredata->values.i)
            srv_cca_mfree(coredata->values.i);
        coredata->values.i = 0;
    }
    else
    {
        if (coredata->values.s)
        {
            for (i = 0; i < coredata->size; i++)
                if (coredata->values.s[i])
                    srv_cca_mfree(coredata->values.s[i]);
            srv_cca_mfree(coredata->values.s);
            coredata->values.s = 0;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_remove_value
 * DESCRIPTION
 *  remove value + release its memory from the coredata
 * PARAMETERS
 *  coredata        [IN]        
 *  type            [IN]        
 *  value           [IN]        (S32 if int, CHAR* if str)
 * RETURNS
 *  0           value not removed
 *  1           value removed from coredata
 *****************************************************************************/
U8 srv_cca_doc_coredata_remove_value(srv_cca_core_data_struct *coredata, srv_cca_data_type_enum type, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    S32 j;
    U8 toRemove;
    U8 removed = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!coredata || coredata->type != type)
        return 0;

    for (i = 0; i < coredata->size; i++)
    {
        toRemove = 0;
        if (type == SRV_CCA_DATA_TYPE_INT && coredata->values.i[i] == (S32) value)
            toRemove = 1;
        if (type == SRV_CCA_DATA_TYPE_STR &&
            (coredata->values.s[i] == (CHAR*) value ||
             (coredata->values.s[i] && value && strcmp(coredata->values.s[i], (CHAR*) value) == 0)))
        {
            if (coredata->values.s[i])
                srv_cca_mfree(coredata->values.s[i]);
            coredata->values.s[i] = 0;
            toRemove = 1;
        }
        if (toRemove)
        {
            for (j = i; j < coredata->size - 1; j++)
            {
                if (type == SRV_CCA_DATA_TYPE_INT)
                    coredata->values.i[j] = coredata->values.i[j + 1];
                else
                    coredata->values.s[j] = coredata->values.s[j + 1];
            }
            if (type == SRV_CCA_DATA_TYPE_INT)
                coredata->values.i[coredata->size - 1] = 0;
            else
                coredata->values.s[coredata->size - 1] = 0;
            coredata->size--;
            i--;
            removed = 1;
        }
    }
    if (!(coredata->size))
    {
        if (type == SRV_CCA_DATA_TYPE_INT)
        {
            if (coredata->values.i)
                srv_cca_mfree(coredata->values.i);
            coredata->values.i = 0;
        }
        else
        {
            if (coredata->values.s)
                srv_cca_mfree(coredata->values.s);
            coredata->values.s = 0;
        }
    }
    return removed;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_update_coredata_int
 * DESCRIPTION
 *  replaces values in coredata with specified value (ie, remove all old value and add new value)
 *  the new data type will be set to "int" should operation succeeded
 * PARAMETERS
 *  data_obj        [IN]        
 *  value           [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_update_coredata_int(srv_cca_core_data_struct *data_obj, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_CCA_SLIM__

    return srv_cca_doc_update_coredata_ints(data_obj, 1, (const S32 *)&value);

#else /* __SRV_CCA_SLIM__ */


    srv_cca_doc_coredata_release_values(data_obj);
    data_obj->type = SRV_CCA_DATA_TYPE_INT;
    data_obj->size = 0;

    return srv_cca_doc_coredata_append(data_obj, 1, (void*)&value);

#endif /* __SRV_CCA_SLIM__*/

}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_update_coredata_str
 * DESCRIPTION
 *  replaces values in coredata with specified value (ie, remove all old value and add new value)
 *  the new data type will be set to "str" should operation succeeded
 * PARAMETERS
 *  data_obj        [IN]        
 *  value           [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_update_coredata_str(srv_cca_core_data_struct *data_obj, const CHAR *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_CCA_SLIM__

    return srv_cca_doc_update_coredata_strs(data_obj, 1, (const CHAR * *)&value);

#else /* __SRV_CCA_SLIM__ */

    srv_cca_doc_coredata_release_values(data_obj);
    data_obj->type = SRV_CCA_DATA_TYPE_STR;
    data_obj->size = 0;

    return srv_cca_doc_coredata_append(data_obj, 1, (void*)&value);
#endif /* __SRV_CCA_SLIM__*/
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_update_coredata_ints
 * DESCRIPTION
 *  replaces values in coredata with specified value (ie, remove all old value and add new value)
 *  the new data type will be set to "int" should operation succeeded
 * PARAMETERS
 *  data_obj        [IN]        
 *  size            [IN]        
 *  values          [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
#ifdef __SRV_CCA_SLIM__

static srv_cca_status_enum srv_cca_doc_update_coredata(srv_cca_core_data_struct *data_obj, srv_cca_data_type_enum data_type, S32 size, const void* values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cca_doc_coredata_release_values(data_obj);
    data_obj->type = data_type;
    data_obj->size = 0;

    return srv_cca_doc_coredata_append(data_obj, size, (void*)values);
}

#endif /* __SRV_CCA_SLIM__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_update_coredata_ints
 * DESCRIPTION
 *  replaces values in coredata with specified value (ie, remove all old value and add new value)
 *  the new data type will be set to "int" should operation succeeded
 * PARAMETERS
 *  data_obj        [IN]        
 *  size            [IN]        
 *  values          [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
static srv_cca_status_enum srv_cca_doc_update_coredata_ints(srv_cca_core_data_struct *data_obj, S32 size, const S32 *values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_CCA_SLIM__

    return srv_cca_doc_update_coredata(data_obj, SRV_CCA_DATA_TYPE_INT, size, (const void *)values);
    
#else /* __SRV_CCA_SLIM__ */    

    srv_cca_doc_coredata_release_values(data_obj);
    data_obj->type = SRV_CCA_DATA_TYPE_INT;
    data_obj->size = 0;

    return srv_cca_doc_coredata_append(data_obj, size, (void*)values);
#endif /* __SRV_CCA_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_update_coredata_strs
 * DESCRIPTION
 *  replaces values in coredata with specified value (ie, remove all old value and add new value)
 *  the new data type will be set to "str" should operation succeeded
 * PARAMETERS
 *  data_obj        [IN]        
 *  size            [IN]        
 *  values          [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
static srv_cca_status_enum srv_cca_doc_update_coredata_strs(srv_cca_core_data_struct *data_obj, S32 size, const CHAR **values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_CCA_SLIM__
    
    return srv_cca_doc_update_coredata(data_obj, SRV_CCA_DATA_TYPE_STR, size, (const void *)values);
        
#else /* __SRV_CCA_SLIM__ */    

    srv_cca_doc_coredata_release_values(data_obj);
    data_obj->type = SRV_CCA_DATA_TYPE_STR;
    data_obj->size = 0;

    return srv_cca_doc_coredata_append(data_obj, size, (void*)values);

#endif /* __SRV_CCA_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_values_exists_int
 * DESCRIPTION
 *  check whether this coredata contain specified value
 * PARAMETERS
 *  values_i        [IN]        
 *  size            [IN]        
 *  val             [IN]        
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
static S32 srv_cca_doc_coredata_values_exists_int(S32 *values_i, S32 size, S32 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((size -= 1) >= 0)
    {
        if (values_i[size] == val)
            return 1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_values_exists_str
 * DESCRIPTION
 *  check whether this coredata contain specified value
 * PARAMETERS
 *  values_s        [IN]        
 *  size            [IN]        
 *  str             [IN]        
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
S32 srv_cca_doc_coredata_values_exists_str(CHAR **values_s, S32 size, CHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((size -= 1) >= 0)
    {
        if (strcmp(values_s[size], str) == 0)
            return 1;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_exists_int
 * DESCRIPTION
 *  check whether this coredata contain specified value
 * PARAMETERS
 *  coredata        [IN]        
 *  val             [IN]        
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
static S32 srv_cca_doc_coredata_exists_int(srv_cca_core_data_struct *coredata, S32 val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (coredata->type != SRV_CCA_DATA_TYPE_INT)
        return 0;
    return srv_cca_doc_coredata_values_exists_int(coredata->values.i, coredata->size, val);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_exists_str
 * DESCRIPTION
 *  check whether this coredata contain specified value
 * PARAMETERS
 *  coredata        [IN]        
 *  str             [IN]        
 * RETURNS
 *  1 if found, 0 otherwise
 *****************************************************************************/
static S32 srv_cca_doc_coredata_exists_str(srv_cca_core_data_struct *coredata, CHAR *str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (coredata->type != SRV_CCA_DATA_TYPE_STR)
        return 0;
    return srv_cca_doc_coredata_values_exists_str(coredata->values.s, coredata->size, str);
}


#ifdef __SRV_CCA_SLIM__

static S32 srv_cca_doc_coredata_is_subset(srv_cca_core_data_struct *dst, srv_cca_core_data_struct *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (count = 0; count < src->size; count++)
    {
        if ((src->type == SRV_CCA_DATA_TYPE_INT && !srv_cca_doc_coredata_exists_int(dst, src->values.i[count])) ||
            (src->type == SRV_CCA_DATA_TYPE_STR && !srv_cca_doc_coredata_exists_str(dst, src->values.s[count])))
        {
            return 0;
        }
    }
    return 1;
}

#endif /* __SRV_CCA_SLIM__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_coredata_is_equal
 * DESCRIPTION
 *  check whether the 2 coredata have the same contents (the order of values in array is not considered)
 * PARAMETERS
 *  cd1     [IN]        
 *  cd2     [IN]        
 * RETURNS
 *  0 = not equal
 *  1 = equal
 *****************************************************************************/
static S32 srv_cca_doc_coredata_is_equal(srv_cca_core_data_struct *cd1, srv_cca_core_data_struct *cd2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __SRV_CCA_SLIM__
    S32 count;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cd1->id != cd2->id || cd1->type != cd2->type || cd1->size != cd2->size)
        return 0;

#ifdef __SRV_CCA_SLIM__

    if (srv_cca_doc_coredata_is_subset(cd1, cd2) && srv_cca_doc_coredata_is_subset(cd2, cd1))
        return 1;
    else
        return 0;
        
#else /* __SRV_CCA_SLIM__ */


    for (count = 0; count < cd1->size; count++)
    {
        if ((cd1->type == SRV_CCA_DATA_TYPE_INT && !srv_cca_doc_coredata_exists_int(cd2, cd1->values.i[count])) ||
            (cd1->type == SRV_CCA_DATA_TYPE_STR && !srv_cca_doc_coredata_exists_str(cd2, cd1->values.s[count])))
        {
            return 0;
        }
    }
    for (count = 0; count < cd2->size; count++)
    {
        if ((cd2->type == SRV_CCA_DATA_TYPE_INT && !srv_cca_doc_coredata_exists_int(cd1, cd2->values.i[count])) ||
            (cd2->type == SRV_CCA_DATA_TYPE_STR && !srv_cca_doc_coredata_exists_str(cd1, cd2->values.s[count])))
        {
            return 0;
        }
    }
    return 1;

#endif /* __SRV_CCA_SLIM__ */

}


#define SRV_CCA_DOC_DATALIST
/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_datalist_new
 * DESCRIPTION
 *  create a new datalist object
 * PARAMETERS
 *  param_id        [IN]        
 *  data_type       [IN]        
 * RETURNS
 *  constructed datalist or 0 if memory full
 *****************************************************************************/
srv_cca_doc_node_datalist_struct *srv_cca_doc_datalist_new(U16 param_id, srv_cca_data_type_enum data_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_datalist_struct *datalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((datalist = srv_cca_malloc_type(srv_cca_doc_node_datalist_struct)) != 0)
    {
        datalist->next = 0;
        datalist->data.id = param_id;
        datalist->data.size = 0;
        datalist->data.type = data_type;
        if (data_type == SRV_CCA_DATA_TYPE_INT)
            datalist->data.values.i = 0;
        else
            datalist->data.values.s = 0;
    }

    return datalist;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_datalist_release
 * DESCRIPTION
 *  release all memory occupied by datalist,
 *  setting deep_delete to 1 will delete all datalist linked to it
 * PARAMETERS
 *  datalist        [IN]        
 *  deep_delete     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_doc_datalist_release(srv_cca_doc_node_datalist_struct *datalist, U8 deep_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_datalist_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (datalist)
    {
        next = datalist->next;
        if (deep_delete)
            srv_cca_doc_coredata_release_values(&(datalist->data));
        srv_cca_mfree(datalist);
        datalist = next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_datalist_attach_to_node
 * DESCRIPTION
 *  attach a datalist to a node, caller MUST ensures param associated with this datalist does not exists in node
 * PARAMETERS
 *  node            [IN]        
 *  datalist        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_doc_datalist_attach_to_node(srv_cca_doc_node_struct *node, srv_cca_doc_node_datalist_struct *datalist)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_CCA_ASSERT(node->num_data < SRV_CCA_ELM_MAX_NUM);

    node->num_data++;
    srv_cca_doc_link_list_elem_to_last(
        (srv_cca_generic_ptr_struct **) & (node->listchain),
        (srv_cca_generic_ptr_struct*) datalist);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_detach_datalist
 * DESCRIPTION
 *  detach datalist object matching the param_id
 * PARAMETERS
 *  node            [IN]        
 *  param_id        [IN]        
 * RETURNS
 *  0 if not found
 *****************************************************************************/
static srv_cca_doc_node_datalist_struct *srv_cca_doc_detach_datalist(srv_cca_doc_node_struct *node, U16 param_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_datalist_struct *prev;
    srv_cca_doc_node_datalist_struct *datalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prev = 0;
    datalist = node->listchain;
    while (datalist)
    {
        if (datalist->data.id == param_id)
        {
            if (!prev)
                node->listchain = datalist->next;
            else
                prev->next = datalist->next;
            datalist->next = 0;
            node->num_data--;
            return datalist;
        }
        prev = datalist;
        datalist = datalist->next;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_datalist_find_ptr
 * DESCRIPTION
 *  find the matched datalist with the specified param_id
 * PARAMETERS
 *  datalist        [IN]        
 *  param_id        [IN]        
 * RETURNS
 *  function returns the datalist pointer pointing to the one containing the specified param_id
 *  datalist can be a NULL pointer, in this case, NULL pointer will be returned
 *****************************************************************************/
srv_cca_doc_node_datalist_struct *srv_cca_doc_datalist_find_ptr(srv_cca_doc_node_datalist_struct *datalist, U16 param_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (datalist)
    {
        if (datalist->data.id == param_id)
            return datalist;
        datalist = datalist->next;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_datalist_has_param_value
 * DESCRIPTION
 *  check if the specified param and value pair exists in datalist
 * PARAMETERS
 *  datalist        [IN]        
 *  param_id        [IN]        
 *  datatype        [IN]        
 *  value           [IN]        (S32 if int, CHAR* if str)
 * RETURNS
 *  0 if not found
 *  1 if found
 *****************************************************************************/
static S32 srv_cca_doc_datalist_has_param_value(
    srv_cca_doc_node_datalist_struct *datalist,
    U16 param_id,
    srv_cca_data_type_enum datatype,
    void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (datalist)
    {
        if (datalist->data.id == param_id &&
            datalist->data.type == datatype &&
            ((datalist->data.type == SRV_CCA_DATA_TYPE_INT && srv_cca_doc_coredata_exists_int(&(datalist->data), (S32) value)) ||
             (datalist->data.type == SRV_CCA_DATA_TYPE_STR && srv_cca_doc_coredata_exists_str(&(datalist->data), (CHAR*) value))))
        {
            return 1;
        }
        datalist = datalist->next;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_equal_param_id
 * DESCRIPTION
 *  check whether elem matches the user_data
 * PARAMETERS
 *  elem            [IN]        Datalist
 *  user_data       [IN]        Param_id
 * RETURNS
 *  0 = not equal
 *  1 = equal
 *****************************************************************************/
U8 srv_cca_doc_equal_param_id(void *elem, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_datalist_struct *datalist;
    U16 param_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    datalist = (srv_cca_doc_node_datalist_struct*) elem;
    param_id = *((U16*) user_data);
    return (U8) (datalist->data.id == param_id);
}


#define SRV_CCA_DOC_NODE
/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_new
 * DESCRIPTION
 *  API to create a new CCA node
 * PARAMETERS
 *  node_symbol     [IN]        
 * RETURNS
 *  constructed node handle, 0=memory full
 *****************************************************************************/
S32 srv_cca_doc_node_new(U16 node_symbol)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = srv_cca_malloc_type(srv_cca_doc_node_struct);
    if (node)
    {
#ifdef __SRV_CCA_SLIM__

        memset(node, 0x0, sizeof(srv_cca_doc_node_struct));

#else /* __SRV_CCA_SLIM__ */
        
        /* init root node's sibling / child / datalist */
        node->next = 0;
        node->parent = 0;
        node->child = 0;
        node->listchain = 0;

        /* init root node's statistic */
        node->num_data = 0;
        node->num_child = 0;

#endif /* __SRV_CCA_SLIM__ */

        node->node_id = node_symbol;

    }
    return (S32) node;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_new_rootnode
 * DESCRIPTION
 *  API to create a new CCA root node
 * PARAMETERS
 *  void
 * RETURNS
 *  constructed node handle, 0=memory full
 *****************************************************************************/
S32 srv_cca_doc_new_rootnode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_cca_doc_node_new(SRV_CCA_NS_DOCROOT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_duplicate
 * DESCRIPTION
 *  API to duplicate a CCA node,
 *  Including all parameters within this node,
 *  as well as re-constructing the source's child nodes hierachy.
 *  Parent of the duplicated node will be set to 0.
 * PARAMETERS
 *  hNode       [IN]        
 * RETURNS
 *  constructed node handle, 0=memory full
 *****************************************************************************/
S32 srv_cca_doc_node_duplicate(S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *nodedup;
    srv_cca_doc_node_struct *nodesrc;
    srv_cca_doc_node_struct *nodechild;
    srv_cca_doc_node_struct *nodechilddup;
    srv_cca_doc_node_datalist_struct *listchain;
    srv_cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return 0;
    nodesrc = (srv_cca_doc_node_struct*) hNode;

    /* create new node */
    nodedup = (srv_cca_doc_node_struct*) srv_cca_doc_node_new(nodesrc->node_id);
    if (!nodedup)
        return 0;

    /* duplicate datalist */
    listchain = nodesrc->listchain;
    while (listchain)
    {
        /* add all data in a parameter to node */
        if (listchain->data.type == SRV_CCA_DATA_TYPE_INT)
            status = srv_cca_doc_add_nodedata_ints(
                        (S32) nodedup,
                        listchain->data.id,
                        listchain->data.size,
                        listchain->data.values.i);
        else    /* SRV_CCA_DATA_TYPE_STR */
            status = srv_cca_doc_add_nodedata_strs(
                        (S32) nodedup,
                        listchain->data.id,
                        listchain->data.size,
                        (const CHAR **)(listchain->data.values.s));

        /* check if mem full */
        if (status == SRV_CCA_STATUS_MEMFULL)
        {
            srv_cca_doc_node_release(nodedup, 1);
            return 0;
        }
        SRV_CCA_ASSERT(status == SRV_CCA_STATUS_OK);

        listchain = listchain->next;
    }

    /* duplicate child nodes */
    nodechild = nodesrc->child;
    while (nodechild)
    {
        nodechilddup = (srv_cca_doc_node_struct*) srv_cca_doc_node_duplicate((S32) nodechild);
        if (!nodechilddup)
        {
            srv_cca_doc_node_release(nodedup, 1);
            return 0;
        }
        srv_cca_doc_node_attach((S32) nodechilddup, (S32) nodedup);
        nodechild = nodechild->next;
    }

    return (S32) nodedup;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_release
 * DESCRIPTION
 *  release all memory occupied by this node
 * PARAMETERS
 *  node            [IN]        
 *  deep_delete     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_doc_node_release(srv_cca_doc_node_struct *node, U8 deep_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!node)
        return;

    if (deep_delete && node->listchain)
        srv_cca_doc_datalist_release(node->listchain, 1);
    srv_cca_mfree(node);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_release_all_recur
 * DESCRIPTION
 *  helper function used for srv_cca_doc_node_free()
 * PARAMETERS
 *  hNode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_doc_node_release_all_recur(S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* not memory efficient! --> too many context switches... may need to rewrite using loop approach */
    node = (srv_cca_doc_node_struct*) hNode;
    if (!node)
        return;

    srv_cca_doc_node_release_all_recur((S32) (node->child));
    srv_cca_doc_node_release_all_recur((S32) (node->next));

    srv_cca_doc_node_release(node, 1);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_free
 * DESCRIPTION
 *  release all memory held by this node and all its sub-nodes (ie, the entire tree)
 * PARAMETERS
 *  hNode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_doc_node_free(S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return;

    srv_cca_doc_node_detach(hNode);
    srv_cca_doc_node_release_all_recur(hNode);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_attach
 * DESCRIPTION
 *  API to attach a node to the specified parent node
 * PARAMETERS
 *  hNode           [IN]        
 *  hParentNode     [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_OK
 *  SRV_CCA_STATUS_FAIL
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_node_attach(S32 hNode, S32 hParentNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *nodeParent;
    srv_cca_doc_node_struct *nodeChild;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nodeParent = (srv_cca_doc_node_struct*) hParentNode;
    nodeChild = (srv_cca_doc_node_struct*) hNode;
    if (!nodeParent || !nodeChild)
        return SRV_CCA_STATUS_FAIL;

    srv_cca_doc_link_list_elem_to_last(
        (srv_cca_generic_ptr_struct **) & (nodeParent->child),
        (srv_cca_generic_ptr_struct*) nodeChild);

    nodeChild->parent = nodeParent;

    SRV_CCA_ASSERT(nodeParent->num_child < SRV_CCA_ELM_MAX_NUM);
    
    nodeParent->num_child++;

    return SRV_CCA_STATUS_OK;
}




/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_new_and_attach
 * DESCRIPTION
 *  API to create a new CCA node and attach to the specified parent node
 * PARAMETERS
 *  node_symbol     [IN]        
 *  hParentNode     [IN]        
 * RETURNS
 *  constructed node handle, 0=memory full
 *****************************************************************************/
S32 srv_cca_doc_node_new_and_attach(U16 node_symbol, S32 hParentNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (srv_cca_doc_node_struct*) srv_cca_doc_node_new(node_symbol);
    if (node)
    {
        if (srv_cca_doc_node_attach((S32) node, hParentNode) != SRV_CCA_STATUS_OK)
        {
            srv_cca_mfree(node);
            node = 0;
        }
    }
    return (S32) node;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_add_node_to_parent
 * DESCRIPTION
 *  API to add a node to the specified parent node
 *  this API will duplicate the hNode first, then attach to parent node.
 * PARAMETERS
 *  hNode           [IN]        
 *  hParentNode     [IN]        
 * RETURNS
 *  CCA_STATUS_OK
 *  CCA_STATUS_FAIL
 *  CCA_STATUS_MEMFULL
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_add_node_to_parent(S32 hNode, S32 hParentNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hParentNode)
        return SRV_CCA_STATUS_FAIL;

    hNode = srv_cca_doc_node_duplicate(hNode);
    if (!hNode)
        return SRV_CCA_STATUS_MEMFULL;

    return srv_cca_doc_node_attach(hNode, hParentNode);
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_detach
 * DESCRIPTION
 *  detach a node from its parent and sibling
 *  this API does not free the node
 * PARAMETERS
 *  hNode       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_doc_node_detach(S32 hNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;
    srv_cca_doc_node_struct *sibling;
    srv_cca_doc_node_struct *parent;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (srv_cca_doc_node_struct*) hNode;
    if (!node)
        return;

    parent = node->parent;
    if (!parent)
    {
        /* if node has no parent, then it should not be connected to any sibling either */
        SRV_CCA_ASSERT(!(node->next));
        return;
    }

    sibling = parent->child;
    /* if parent's first child = specified node */
    if (sibling == node)
    {
        parent->child = node->next;
        parent->num_child--;
        node->next = 0;
        node->parent = 0;
        return;
    }

    while (sibling->next)
    {
        if (sibling->next == node)
        {
            sibling->next = node->next;
            parent->num_child--;
            node->next = 0;
            node->parent = 0;
            break;
        }
        sibling = sibling->next;
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_equal_node_id
 * DESCRIPTION
 *  check whether elem matches the user_data
 * PARAMETERS
 *  elem            [IN]        Node
 *  user_data       [IN]        Node_id
 * RETURNS
 *  0 = not equal
 *  1 = equal
 *****************************************************************************/
U8 srv_cca_doc_equal_node_id(void *elem, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;
    U16 node_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (srv_cca_doc_node_struct*) elem;
    node_id = *((U16*) user_data);
    return (U8) (node->node_id == node_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_check_equal_content
 * DESCRIPTION
 *  Check if src is the sub-set of the dst
 * PARAMETERS
 *  hNode1      [IN]        
 *  hNode2      [IN]        
 * RETURNS
 *  0 = not equal
 *  1 = equal
 *****************************************************************************/
#ifdef __SRV_CCA_SLIM__

static S32 srv_cca_doc_node_datalist_check_subset(srv_cca_doc_node_datalist_struct *dst, srv_cca_doc_node_datalist_struct *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_datalist_struct *src_temp = src;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (dst == src)
        return 1;
    if ((dst && !src) || (!dst && src))
        return 0;

    while (dst)
    {
        src_temp = src;
        while (src_temp)
        {
            if (srv_cca_doc_coredata_is_equal(&(dst->data), &(src_temp->data)))
                break;
            src_temp = src_temp->next;
        }
        if (!src_temp)
            return 0;
        dst = dst->next;
    }
    return 1;
}

#endif /* __SRV_CCA_SLIM__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_check_equal_content
 * DESCRIPTION
 *  check whether the 2 nodes have the same contents (ie, all param+values match the another)
 *  this func does not check for the node's siblings or its child
 *  please note that this API is an expensive operation, and is not recommanded to be used frequently
 * PARAMETERS
 *  hNode1      [IN]        
 *  hNode2      [IN]        
 * RETURNS
 *  0 = not equal
 *  1 = equal
 *****************************************************************************/
U8 srv_cca_doc_node_check_equal_content(S32 hNode1, S32 hNode2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node1;
    srv_cca_doc_node_struct *node2;
#ifndef __SRV_CCA_SLIM__
    srv_cca_doc_node_datalist_struct *datalist1;
    srv_cca_doc_node_datalist_struct *datalist2;
#endif /* __SRV_CCA_SLIM__  */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode1 && !hNode2)
        return 1;
    if (hNode1 == hNode2)
        return 1;
    if ((hNode1 && !hNode2) || (!hNode1 && hNode2))
        return 0;

    node1 = (srv_cca_doc_node_struct*) hNode1;
    node2 = (srv_cca_doc_node_struct*) hNode2;
    if ((node1->node_id != node2->node_id) || (node1->num_data != node2->num_data))
        return 0;

#ifdef __SRV_CCA_SLIM__

    if (srv_cca_doc_node_datalist_check_subset(node1->listchain, node2->listchain) &&
        srv_cca_doc_node_datalist_check_subset(node2->listchain, node1->listchain))
    {
        return 1;
    }
    else
    {
        return 0;
    }
    
#else /* __SRV_CCA_SLIM__ */

    datalist1 = node1->listchain;
    datalist2 = node2->listchain;
    if (datalist1 == datalist2)
        return 1;
    if ((datalist1 && !datalist2) || (!datalist1 && datalist2))
        return 0;

    while (datalist1)
    {
        datalist2 = node2->listchain;
        while (datalist2)
        {
            if (srv_cca_doc_coredata_is_equal(&(datalist1->data), &(datalist2->data)))
                break;
            datalist2 = datalist2->next;
        }
        if (!datalist2)
            return 0;
        datalist1 = datalist1->next;
    }

    datalist1 = node1->listchain;
    datalist2 = node2->listchain;
    while (datalist2)
    {
        datalist1 = node1->listchain;
        while (datalist1)
        {
            if (srv_cca_doc_coredata_is_equal(&(datalist2->data), &(datalist1->data)))
                break;
            datalist1 = datalist1->next;
        }
        if (!datalist1)
            return 0;
        datalist2 = datalist2->next;
    }
    return 1;

#endif /* __SRV_CCA_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_node_has_param_value
 * DESCRIPTION
 *  check whether the node contains the specified parameter + value pair
 * PARAMETERS
 *  hNode           [IN]        
 *  param           [IN]        
 *  datatype        [IN]        
 *  value           [IN]        (S32 if int, CHAR* if str)
 * RETURNS
 *  0 = not found
 *  1 = found
 *****************************************************************************/
U8 srv_cca_doc_node_has_param_value(S32 hNode, U16 param, srv_cca_data_type_enum datatype, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return 0;
    return srv_cca_doc_datalist_has_param_value(((srv_cca_doc_node_struct*) hNode)->listchain, param, datatype, value);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_find_node_match_param_value
 * DESCRIPTION
 *  return the first node matching the node_symbol + values in the specified param
 * PARAMETERS
 *  hStartNode      [IN]        
 *  node_symbol     [IN]        SRV_CCA_NS__NULL to skip this arguement
 *  param           [IN]        
 *  datatype        [IN]        
 *  value           [IN]        (S32 if int, CHAR* if str)
 * RETURNS
 *  0 = not found
 *  otherwise the matched node
 *****************************************************************************/
S32 srv_cca_doc_find_node_match_param_value(
        S32 hStartNode,
        U16 node_symbol,
        U16 param,
        srv_cca_data_type_enum datatype,
        void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hStartNode)
        return 0;

    node = (srv_cca_doc_node_struct*) hStartNode;
    while (node)
    {
        if ((node_symbol == SRV_CCA_NS__NULL || node->node_id == node_symbol) &&
            srv_cca_doc_node_has_param_value((S32) node, param, datatype, value))
        {
            return (S32) node;
        }
        node = node->next;
    }
    return 0;
}





#define SRV_CCA_DOC_NODEDATA


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodedata_add_int
 * DESCRIPTION
 *  append an int data to this node
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  value           [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_nodedata_add_int(S32 hNode, U16 param_id, S32 value)
{
#ifdef __SRV_CCA_SLIM__

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_cca_doc_add_nodedata_ints(hNode, param_id, 1, &value);
    
    
#else /* __SRV_CCA_SLIM__ */ 
    

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;
    srv_cca_doc_node_datalist_struct *datalist;
    U8 isNewList;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (srv_cca_doc_node_struct*) hNode;
    datalist = srv_cca_doc_datalist_find_ptr(node->listchain, param_id);
    isNewList = 0;

    /* retrieve datalist or create new */
    if (!datalist)
    {
        /* create a new datalist if datalist of this param cannot be found */
        datalist = srv_cca_doc_datalist_new(param_id, SRV_CCA_DATA_TYPE_INT);
        if (!datalist)
            return SRV_CCA_STATUS_MEMFULL;
        isNewList = 1;
    }
    else
    {
        /* datalist of this param already exists, check existing datalist type */
        if (datalist->data.type != SRV_CCA_DATA_TYPE_INT)
            return SRV_CCA_STATUS_TYPE_MISMATCHED;
    }

    /* append values to end of data array */
    if (srv_cca_doc_coredata_append(&(datalist->data), 1, (void*)&value) != SRV_CCA_STATUS_OK)
    {
        if (isNewList)
        {
            /* only needs to free datalist ptr mem as the coredata would
               have been dealloc completely if coredata_append failed */
            srv_cca_mfree(datalist);
        }
        return SRV_CCA_STATUS_MEMFULL;
    }

    /* attach datalist to node if datalist is newly created */
    if (isNewList)
        srv_cca_doc_datalist_attach_to_node(node, datalist);

    return SRV_CCA_STATUS_OK;

#endif /* __SRV_CCA_SLIM__ */    
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodedata_add_str
 * DESCRIPTION
 *  append a str data to this node
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  value           [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_nodedata_add_str(S32 hNode, U16 param_id, const CHAR *value)
{
#ifdef __SRV_CCA_SLIM__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_cca_doc_add_nodedata_strs(hNode, param_id, 1, &value);



#else /* __SRV_CCA_SLIM__ */ 


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;
    srv_cca_doc_node_datalist_struct *datalist;
    U8 isNewList;


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (srv_cca_doc_node_struct*) hNode;
    datalist = srv_cca_doc_datalist_find_ptr(node->listchain, param_id);
    isNewList = 0;

    /* retrieve datalist or create new */
    if (!datalist)
    {
        /* create a new datalist if datalist of this param cannot be found */
        datalist = srv_cca_doc_datalist_new(param_id, SRV_CCA_DATA_TYPE_STR);
        if (!datalist)
            return SRV_CCA_STATUS_MEMFULL;
        isNewList = 1;
    }
    else
    {
        /* datalist of this param already exists, check existing datalist type */
        if (datalist->data.type != SRV_CCA_DATA_TYPE_STR)
            return SRV_CCA_STATUS_TYPE_MISMATCHED;
    }

    /* append values to end of data array */
    if (srv_cca_doc_coredata_append(&(datalist->data), 1, (void*)&value) != SRV_CCA_STATUS_OK)
    {
        if (isNewList)
        {
            /* only needs to free datalist ptr mem as the coredata would
               have been dealloc completely if coredata_append failed */
            srv_cca_mfree(datalist);
        }
        return SRV_CCA_STATUS_MEMFULL;
    }

    /* attach datalist to node if datalist is newly created */
    if (isNewList)
        srv_cca_doc_datalist_attach_to_node(node, datalist);



    return SRV_CCA_STATUS_OK;

#endif /* __SRV_CCA_SLIM__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_add_nodedata
 * DESCRIPTION
 *  append all values in an int array to this node
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  size            [IN]        
 *  values          [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
#ifdef __SRV_CCA_SLIM__

static srv_cca_status_enum srv_cca_doc_add_nodedata(S32 hNode, U16 param_id, srv_cca_data_type_enum data_type, S32 size, const void *values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;
    srv_cca_doc_node_datalist_struct *datalist;
    U8 isNewList;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (srv_cca_doc_node_struct*) hNode;
    datalist = srv_cca_doc_datalist_find_ptr(node->listchain, param_id);
    isNewList = 0;

    /* retrieve datalist or create new */
    if (!datalist)
    {
        /* create a new datalist if datalist of this param cannot be found */
        datalist = srv_cca_doc_datalist_new(param_id, data_type);
        if (!datalist)
            return SRV_CCA_STATUS_MEMFULL;
        isNewList = 1;
    }
    else
    {
        /* datalist of this param already exists, check existing datalist type */
        if (datalist->data.type != data_type)
            return SRV_CCA_STATUS_TYPE_MISMATCHED;
    }

    /* append values to end of data array */
    if (srv_cca_doc_coredata_append(&(datalist->data), size, (void*)values) != SRV_CCA_STATUS_OK)
    {
        if (isNewList)
        {
            /* only needs to free datalist ptr mem as the coredata would
               have been dealloc completely if coredata_append failed */
            srv_cca_mfree(datalist);
        }
        return SRV_CCA_STATUS_MEMFULL;
    }

    /* attach datalist to node if datalist is newly created */
    if (isNewList)
        srv_cca_doc_datalist_attach_to_node(node, datalist);

    return SRV_CCA_STATUS_OK;
}

#endif /* __SRV_CCA_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_add_nodedata_ints
 * DESCRIPTION
 *  append all values in an int array to this node
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  size            [IN]        
 *  values          [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
static srv_cca_status_enum srv_cca_doc_add_nodedata_ints(S32 hNode, U16 param_id, S32 size, const S32 *values)
{
#ifdef __SRV_CCA_SLIM__

    return srv_cca_doc_add_nodedata(hNode, param_id, SRV_CCA_DATA_TYPE_INT, size, (const void *) values);

#else /* __SRV_CCA_SLIM__ */

    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;
    srv_cca_doc_node_datalist_struct *datalist;
    U8 isNewList;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (srv_cca_doc_node_struct*) hNode;
    datalist = srv_cca_doc_datalist_find_ptr(node->listchain, param_id);
    isNewList = 0;

    /* retrieve datalist or create new */
    if (!datalist)
    {
        /* create a new datalist if datalist of this param cannot be found */
        datalist = srv_cca_doc_datalist_new(param_id, SRV_CCA_DATA_TYPE_INT);
        if (!datalist)
            return SRV_CCA_STATUS_MEMFULL;
        isNewList = 1;
    }
    else
    {
        /* datalist of this param already exists, check existing datalist type */
        if (datalist->data.type != SRV_CCA_DATA_TYPE_INT)
            return SRV_CCA_STATUS_TYPE_MISMATCHED;
    }

    /* append values to end of data array */
    if (srv_cca_doc_coredata_append(&(datalist->data), size, (void*)values) != SRV_CCA_STATUS_OK)
    {
        if (isNewList)
        {
            /* only needs to free datalist ptr mem as the coredata would
               have been dealloc completely if coredata_append failed */
            srv_cca_mfree(datalist);
        }
        return SRV_CCA_STATUS_MEMFULL;
    }

    /* attach datalist to node if datalist is newly created */
    if (isNewList)
        srv_cca_doc_datalist_attach_to_node(node, datalist);

    return SRV_CCA_STATUS_OK;

   
#endif /* __SRV_CCA_SLIM__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_add_nodedata_strs
 * DESCRIPTION
 *  append all values in a str array to this node
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  size            [IN]        
 *  values          [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
static srv_cca_status_enum srv_cca_doc_add_nodedata_strs(S32 hNode, U16 param_id, S32 size, const CHAR **values)
{
#ifdef __SRV_CCA_SLIM__
    
    return srv_cca_doc_add_nodedata(hNode, param_id, SRV_CCA_DATA_TYPE_STR, size, (const void *) values);
    
#else /* __SRV_CCA_SLIM__ */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;
    srv_cca_doc_node_datalist_struct *datalist;
    U8 isNewList;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    node = (srv_cca_doc_node_struct*) hNode;
    datalist = srv_cca_doc_datalist_find_ptr(node->listchain, param_id);
    isNewList = 0;

    /* retrieve datalist or create new */
    if (!datalist)
    {
        /* create a new datalist if datalist of this param cannot be found */
        datalist = srv_cca_doc_datalist_new(param_id, SRV_CCA_DATA_TYPE_STR);
        if (!datalist)
            return SRV_CCA_STATUS_MEMFULL;
        isNewList = 1;
    }
    else
    {
        /* datalist of this param already exists, check existing datalist type */
        if (datalist->data.type != SRV_CCA_DATA_TYPE_STR)
            return SRV_CCA_STATUS_TYPE_MISMATCHED;
    }

    /* append values to end of data array */
    if (srv_cca_doc_coredata_append(&(datalist->data), size, (void*)values) != SRV_CCA_STATUS_OK)
    {
        if (isNewList)
        {
            /* only needs to free datalist ptr mem as the coredata would
               have been dealloc completely if coredata_append failed */
            srv_cca_mfree(datalist);
        }
        return SRV_CCA_STATUS_MEMFULL;
    }

    /* attach datalist to node if datalist is newly created */
    if (isNewList)
        srv_cca_doc_datalist_attach_to_node(node, datalist);

    return SRV_CCA_STATUS_OK;

#endif /* __SRV_CCA_SLIM__ */
}







/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_remove_nodedata
 * DESCRIPTION
 *  detach + release the datalist & coredata object matching the specified param_id within this node
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_OK
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_remove_nodedata(S32 hNode, U16 param_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_datalist_struct *datalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    datalist = srv_cca_doc_detach_datalist((srv_cca_doc_node_struct*) hNode, param_id);
    if (!datalist)
        return SRV_CCA_STATUS_NOT_FOUND;

    srv_cca_doc_datalist_release(datalist, 1);
    return SRV_CCA_STATUS_OK;
}



#ifdef __SRV_CCA_SLIM__
static srv_cca_status_enum srv_cca_doc_update_nodedata(S32 hNode, U16 param_id, srv_cca_data_type_enum data_type,  S32 size, const void *values)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum status;
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_cca_doc_nodedata_by_param(hNode, param_id, &coredata);
    if (status != SRV_CCA_STATUS_OK)
        return status;

    return srv_cca_doc_update_coredata(coredata, data_type, size, values);
}
#endif /* __SRV_CCA_SLIM__ */

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_update_nodedata_int
 * DESCRIPTION
 *  replaces values in coredata matching the specified param_id within the node to the specified value
 *  the new data type will be set to "int" should operation succeeded
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  value           [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_update_nodedata_int(S32 hNode, U16 param_id, S32 value)
{
#ifdef __SRV_CCA_SLIM__

    return srv_cca_doc_update_nodedata(hNode, param_id,  SRV_CCA_DATA_TYPE_INT, 1, (const void *)&value);

#else  /* __SRV_CCA_SLIM__ */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum status;
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_cca_doc_nodedata_by_param(hNode, param_id, &coredata);
    if (status != SRV_CCA_STATUS_OK)
        return status;

    return srv_cca_doc_update_coredata_int(coredata, value);
    
#endif /* __SRV_CCA_SLIM__ */
       
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_update_nodedata_str
 * DESCRIPTION
 *  replaces values in coredata matching the specified param_id within the node to the specified value
 *  the new data type will be set to "str" should operation succeeded
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  value           [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_update_nodedata_str(S32 hNode, U16 param_id, const CHAR *value)
{
#ifdef __SRV_CCA_SLIM__
    
    return srv_cca_doc_update_nodedata(hNode, param_id, SRV_CCA_DATA_TYPE_STR, 1, (const void *)&value);
    
#else  /* __SRV_CCA_SLIM__ */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum status;
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_cca_doc_nodedata_by_param(hNode, param_id, &coredata);
    if (status != SRV_CCA_STATUS_OK)
        return status;

    return srv_cca_doc_update_coredata_str(coredata, value);
    
#endif /* __SRV_CCA_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_update_nodedata_ints
 * DESCRIPTION
 *  replaces values in coredata matching the specified param_id within the node to the specified value
 *  the new data type will be set to "int" should operation succeeded
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  size            [IN]        
 *  values          [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_update_nodedata_ints(S32 hNode, U16 param_id, S32 size, const S32 *values)
{
#ifdef __SRV_CCA_SLIM__
    
    return srv_cca_doc_update_nodedata(hNode, param_id, SRV_CCA_DATA_TYPE_INT, size, (const void *)values);
    
#else  /* __SRV_CCA_SLIM__ */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum status;
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_cca_doc_nodedata_by_param(hNode, param_id, &coredata);
    if (status != SRV_CCA_STATUS_OK)
        return status;

    return srv_cca_doc_update_coredata_ints(coredata, size, values);
    
#endif /* __SRV_CCA_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_update_nodedata_strs
 * DESCRIPTION
 *  replaces values in coredata matching the specified param_id within the node to the specified value
 *  the new data type will be set to "str" should operation succeeded
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  size            [IN]        
 *  values          [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_update_nodedata_strs(S32 hNode, U16 param_id, S32 size, const CHAR **values)
{
#ifdef __SRV_CCA_SLIM__
        
    return srv_cca_doc_update_nodedata(hNode, param_id, SRV_CCA_DATA_TYPE_STR, size, (const void *)values);
        
#else  /* __SRV_CCA_SLIM__ */

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_status_enum status;
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_cca_doc_nodedata_by_param(hNode, param_id, &coredata);
    if (status != SRV_CCA_STATUS_OK)
        return status;

    return srv_cca_doc_update_coredata_strs(coredata, size, values);

#endif /* __SRV_CCA_SLIM__ */
}


#ifdef __SRV_CCA_SLIM__
static srv_cca_status_enum srv_cca_doc_nodedata_first(S32 hNode, U16 param_id, srv_cca_data_type_enum data_type, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    if (srv_cca_doc_nodedata_by_param(hNode, param_id, &coredata) == SRV_CCA_STATUS_NOT_FOUND)
        return SRV_CCA_STATUS_NOT_FOUND;

    if (coredata->type != data_type)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (value)
    {
        if (data_type == SRV_CCA_DATA_TYPE_INT)
            (*((S32*)value))= (coredata->size ? coredata->values.i[0] : 0);
        else
            (*((CHAR**)value))= (coredata->size ? coredata->values.s[0] : 0);
    }

    return SRV_CCA_STATUS_OK;
}
#endif /* __SRV_CCA_SLIM__ */



/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodedata_int_first
 * DESCRIPTION
 *  retrieve the first int data of the matching the specified param_id in the specified node
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  value           [OUT]       Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_nodedata_int_first(S32 hNode, U16 param_id, S32 *value)
{
#ifdef __SRV_CCA_SLIM__

   return srv_cca_doc_nodedata_first(hNode, param_id, SRV_CCA_DATA_TYPE_INT, (void *) value);

#else /* __SRV_CCA_SLIM__ */

    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    if (srv_cca_doc_nodedata_by_param(hNode, param_id, &coredata) == SRV_CCA_STATUS_NOT_FOUND)
        return SRV_CCA_STATUS_NOT_FOUND;

    if (coredata->type != SRV_CCA_DATA_TYPE_INT)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (value)
        *value = (coredata->size ? coredata->values.i[0] : 0);

    return SRV_CCA_STATUS_OK;

#endif /* __SRV_CCA_SLIM__ */

}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodedata_str_first
 * DESCRIPTION
 *  retrieve the first str data of the matching the specified param_id in the specified node
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  value           [IN]        Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_nodedata_str_first(S32 hNode, U16 param_id, CHAR **value)
{
#ifdef __SRV_CCA_SLIM__

    return srv_cca_doc_nodedata_first(hNode, param_id, SRV_CCA_DATA_TYPE_STR, (void *) value);

#else /* __SRV_CCA_SLIM__ */
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    if (srv_cca_doc_nodedata_by_param(hNode, param_id, &coredata) == SRV_CCA_STATUS_NOT_FOUND)
        return SRV_CCA_STATUS_NOT_FOUND;

    if (coredata->type != SRV_CCA_DATA_TYPE_STR)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (value)
        *value = (coredata->size ? coredata->values.s[0] : 0);

    return SRV_CCA_STATUS_OK;

#endif /* __SRV_CCA_SLIM__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodedata_by_param
 * DESCRIPTION
 *  retrieve the coredata object matching the specified param_id in the specified node
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  data_obj        [OUT]       Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_nodedata_by_param(S32 hNode, U16 param_id, srv_cca_core_data_struct **data_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_datalist_struct *datalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    datalist = srv_cca_doc_datalist_find_ptr(((srv_cca_doc_node_struct*) hNode)->listchain, param_id);
    if (!datalist)
        return SRV_CCA_STATUS_NOT_FOUND;

    if (data_obj)
        *data_obj = &(datalist->data);

    return SRV_CCA_STATUS_OK;
}


#ifdef __SRV_CCA_SLIM__

static srv_cca_status_enum srv_cca_doc_nodedata(S32 hNode, U16 param_id, srv_cca_data_type_enum data_type, void **values, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    if (srv_cca_doc_nodedata_by_param(hNode, param_id, &coredata) == SRV_CCA_STATUS_NOT_FOUND)
        return SRV_CCA_STATUS_NOT_FOUND;

    if (coredata->type != data_type)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (size)
        *size = coredata->size;

    if (values)
    {
        if (data_type == SRV_CCA_DATA_TYPE_INT)
            *((S32 **)values) = (coredata->size ? coredata->values.i : 0);
        else
            *((CHAR ***)values) = (coredata->size ? coredata->values.s : 0);
            
    }
    return SRV_CCA_STATUS_OK;
}
#endif /* __SRV_CCA_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodedata_ints
 * DESCRIPTION
 *  retrieve the int array data of the matching the specified param_id in the specified node
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  values          [OUT]       Can be NULL pointer
 *  size            [OUT]       Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_nodedata_ints(S32 hNode, U16 param_id, S32 **values, S32 *size)
{
#ifdef __SRV_CCA_SLIM__

    return srv_cca_doc_nodedata(hNode, param_id, SRV_CCA_DATA_TYPE_INT, (void * *) values, size);

#else /* __SRV_CCA_SLIM__ */


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    if (srv_cca_doc_nodedata_by_param(hNode, param_id, &coredata) == SRV_CCA_STATUS_NOT_FOUND)
        return SRV_CCA_STATUS_NOT_FOUND;

    if (coredata->type != SRV_CCA_DATA_TYPE_INT)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (size)
        *size = coredata->size;

    if (values)
        *values = (coredata->size ? coredata->values.i : 0);

    return SRV_CCA_STATUS_OK;
    
#endif /* __SRV_CCA_SLIM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodedata_strs
 * DESCRIPTION
 *  retrieve the str array data of the matching the specified param_id in the specified node
 * PARAMETERS
 *  hNode           [IN]        
 *  param_id        [IN]        
 *  values          [OUT]       Can be NULL pointer
 *  size            [OUT]       Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_nodedata_strs(S32 hNode, U16 param_id, CHAR ***values, S32 *size)
{
#ifdef __SRV_CCA_SLIM__
    
     return srv_cca_doc_nodedata(hNode, param_id, SRV_CCA_DATA_TYPE_STR,(void * *)values, size);
    
#else /* __SRV_CCA_SLIM__ */
    

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hNode)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    if (srv_cca_doc_nodedata_by_param(hNode, param_id, &coredata) == SRV_CCA_STATUS_NOT_FOUND)
        return SRV_CCA_STATUS_NOT_FOUND;

    if (coredata->type != SRV_CCA_DATA_TYPE_STR)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (size)
        *size = coredata->size;

    if (values)
        *values = (coredata->size ? coredata->values.s : 0);

    return SRV_CCA_STATUS_OK;
    
#endif /* __SRV_CCA_SLIM__ */
}


#define SRV_CCA_DOC_NODELIST

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodelist_new
 * DESCRIPTION
 *  pre: valid node object
 *  construct a new nodelist object wrapping this node
 * PARAMETERS
 *  node        [IN]        
 * RETURNS
 *  constructed nodelist object or 0 if mem full
 *****************************************************************************/
static srv_cca_doc_nodelist_struct *srv_cca_doc_nodelist_new(srv_cca_doc_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_nodelist_struct *nodelist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!node)
        return 0;

    nodelist = srv_cca_malloc_type(srv_cca_doc_nodelist_struct);
    if (nodelist)
    {
        nodelist->next = 0;
        nodelist->node = node;
    }
    return nodelist;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodelist_release
 * DESCRIPTION
 *  release all memory occupied by this nodelist
 *  setting deep_delete will delete all nodelist obj linked to it
 * PARAMETERS
 *  nodelist        [IN]        
 *  deep_delete     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_doc_nodelist_release(srv_cca_doc_nodelist_struct *nodelist, U8 deep_delete)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_nodelist_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (nodelist)
    {
        next = nodelist->next;
        if (deep_delete && nodelist->node)
            srv_cca_doc_node_release(nodelist->node, 1);
        srv_cca_mfree(nodelist);
        nodelist = next;
    }
}


#define SRV_CCA_DOC_ITER

/*****************************************************************************
 * FUNCTION
 *  srv_cca_iterator_new
 * DESCRIPTION
 *  construct a new iterator with specified parameters
 * PARAMETERS
 *  trType      [IN]        
 *  itType      [IN]        
 *  begin       [IN]        
 *  dpDel       [IN]        
 * RETURNS
 *  constructed iterator object or 0 (mem full)
 *****************************************************************************/
srv_cca_iterator_struct *srv_cca_iterator_new(
                        srv_cca_traverse_type_enum trType,
                        srv_cca_iter_type_enum itType,
                        srv_cca_generic_ptr_struct *begin,
                        U8 dpDel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_iterator_struct *iter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iter = srv_cca_malloc_type(srv_cca_iterator_struct);
    if (iter)
        srv_cca_iterator_fill(iter, trType, itType, begin, dpDel);

    return iter;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_iterator_release
 * DESCRIPTION
 *  release memory occupied by iterator only, and not its pointed data
 * PARAMETERS
 *  iter        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_iterator_release(srv_cca_iterator_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!iter)
        return;

    /* currently deep_delete is not considered... will be implemented in future if needed */
    srv_cca_mfree(iter);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_iterator_fill
 * DESCRIPTION
 *  pre: valid iterator
 *  fill in iterator parameters to the already constructed iterator object
 * PARAMETERS
 *  iter        [IN/OUT]        
 *  trType      [IN]            
 *  itType      [IN]            
 *  begin       [IN]            
 *  dpDel       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_iterator_fill(
        srv_cca_iterator_struct *iter,
        srv_cca_traverse_type_enum trType,
        srv_cca_iter_type_enum itType,
        srv_cca_generic_ptr_struct *begin,
        U8 dpDel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iter->current = 0;
    iter->head_node = begin;
    iter->prev_node = 0;
    iter->traverse_type = trType;
    iter->iter_type = itType;
    iter->deep_delete = dpDel;
    iter->crt_level = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_iterator_restart
 * DESCRIPTION
 *  reset iterator to its begin state
 * PARAMETERS
 *  iter        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_iterator_restart(srv_cca_iterator_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iter)
    {
        iter->current = 0;
        iter->prev_node = 0;
        iter->crt_level = 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_iterator_next_preorder_node
 * DESCRIPTION
 *  performs a preorder traversal and move to next node in iterator
 * PARAMETERS
 *  iter        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_iterator_next_preorder_node(srv_cca_iterator_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iter->current == 0)
        return;

    if (iter->current->next)
        iter->current = iter->current->next;
    else
    {
        iter->current = iter->current->parent;
        /* crt_level = -1 when all nodes/childs traversed.. ie, end of traversal */
        iter->crt_level--;
        srv_cca_iterator_next_preorder_node(iter);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_iterator_next
 * DESCRIPTION
 *  move to next node in iterator
 * PARAMETERS
 *  iter        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_cca_iterator_next(srv_cca_iterator_struct *iter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!iter)
        return 0;

    iter->prev_node = iter->current;

    if (iter->current == 0)
    {
        iter->current = iter->head_node;
        iter->crt_level = 0;
    }
    else if (iter->traverse_type == SRV_CCA_TR_LIST)
    {
        iter->current = iter->current->next;
    }
    else if (iter->traverse_type == SRV_CCA_TR_PREORDER)
    {
        if (iter->current->child)
        {
            iter->current = iter->current->child;
            iter->crt_level++;
        }
        else
            srv_cca_iterator_next_preorder_node(iter);
    }

    return (void*)iter->current;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_nodedata_next
 * DESCRIPTION
 *  retrieve the coredata obj of the next pointed datalist
 * PARAMETERS
 *  iter_datalist       [IN]        
 *  data_obj            [IN]        Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_ITER
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_nodedata_next(srv_cca_iterator_struct *iter_datalist, srv_cca_core_data_struct **data_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_datalist_struct *crtDatalist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_obj)
        *data_obj = 0;

    if (!iter_datalist || iter_datalist->iter_type != SRV_CCA_IT_DATALIST)
        return SRV_CCA_STATUS_INVALID_ITER;

    crtDatalist = (srv_cca_doc_node_datalist_struct*) srv_cca_iterator_next(iter_datalist);
    if (!crtDatalist)
        return SRV_CCA_STATUS_ENDLIST;

    if (data_obj)
        *data_obj = &(crtDatalist->data);

    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_get_nodedata
 * DESCRIPTION
 *  retrieve the iterator to the datalist (ie, list of parameters) held in the node pointed by this iterator
 * PARAMETERS
 *  iter_nodelist       [IN]        
 *  iter_datalist       [IN]        Can be NULL pointer
 *  size                [IN]        Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_ITER
 *  SRV_CCA_STATUS_ENDLIST
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_get_nodedata(
                    srv_cca_iterator_struct *iter_nodelist,
                    srv_cca_iterator_struct **iter_datalist,
                    S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_node_struct *node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (iter_datalist)
        *iter_datalist = 0;
    if (size)
        *size = 0;

    if (!iter_nodelist || (iter_nodelist->iter_type != SRV_CCA_IT_NODELIST && iter_nodelist->iter_type != SRV_CCA_IT_NODECHAIN))
        return SRV_CCA_STATUS_INVALID_ITER;

    if (!(iter_nodelist->current))
        return SRV_CCA_STATUS_ENDLIST;

    if (iter_nodelist->iter_type == SRV_CCA_IT_NODELIST)
        node = ((srv_cca_doc_nodelist_struct*) (iter_nodelist->current))->node;
    else
        node = (srv_cca_doc_node_struct*) (iter_nodelist->current);

    if (!node || !(node->listchain))
        return SRV_CCA_STATUS_NOT_FOUND;

    if (iter_datalist)
    {
        *iter_datalist = srv_cca_iterator_new(
                            SRV_CCA_TR_LIST,
                            SRV_CCA_IT_DATALIST,
                            (srv_cca_generic_ptr_struct*) (node->listchain),
                            0);
        if (!(*iter_datalist))
            return SRV_CCA_STATUS_MEMFULL;
    }

    if (size)
        *size = node->num_data;

    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_get_nodedata_by_param
 * DESCRIPTION
 *  retrieve the coredata object matching the specified param_id in the node pointed by this iterator
 * PARAMETERS
 *  iter            [IN]        Can be a valid nodelist iterator or a valid datalist iterator
 *  param_id        [IN]        
 *  data_obj        [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_ITER
 *  SRV_CCA_STATUS_ENDLIST
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_get_nodedata_by_param(
                    srv_cca_iterator_struct *iter,
                    U16 param_id,
                    srv_cca_core_data_struct **data_obj)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_iterator_struct *iter_datalist;
    srv_cca_status_enum status;
    srv_cca_core_data_struct *coredata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_obj)
        *data_obj = 0;

    if (!iter)
        return SRV_CCA_STATUS_INVALID_ITER;

    if (iter->iter_type == SRV_CCA_IT_DATALIST)
    {
        iter_datalist = iter;
    }
    else if (iter->iter_type == SRV_CCA_IT_NODELIST || iter->iter_type == SRV_CCA_IT_NODECHAIN)
    {
        if (!(iter->current))
            return SRV_CCA_STATUS_ENDLIST;

        status = srv_cca_doc_get_nodedata(iter, &iter_datalist, 0);
        if (status != SRV_CCA_STATUS_OK)
            return status;
    }
    else
    {
        SRV_CCA_ASSERT(0);
    }

    if (!data_obj)
    {
        if (iter->iter_type == SRV_CCA_IT_NODELIST || iter->iter_type == SRV_CCA_IT_NODECHAIN)
            srv_cca_iterator_release(iter_datalist);
        return SRV_CCA_STATUS_OK;
    }

    srv_cca_iterator_restart(iter_datalist);
    while (srv_cca_iterator_next(iter_datalist))
    {
        coredata = &(((srv_cca_doc_node_datalist_struct*) (iter_datalist->current))->data);
        if (coredata->id == param_id)
        {
            *data_obj = coredata;
            if (iter->iter_type == SRV_CCA_IT_NODELIST || iter->iter_type == SRV_CCA_IT_NODECHAIN)
                srv_cca_iterator_release(iter_datalist);
            return SRV_CCA_STATUS_OK;
        }
    }
    if (iter->iter_type == SRV_CCA_IT_NODELIST || iter->iter_type == SRV_CCA_IT_NODECHAIN)
        srv_cca_iterator_release(iter_datalist);
    return SRV_CCA_STATUS_NOT_FOUND;
}


#ifdef __SRV_CCA_SLIM__

static srv_cca_status_enum srv_cca_doc_get_nodedata_first(srv_cca_iterator_struct *iter, U16 param_id, srv_cca_data_type_enum data_type, void *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;
    srv_cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_cca_doc_get_nodedata_by_param(iter, param_id, &coredata);
    if (status != SRV_CCA_STATUS_OK)
        return status;

    if (coredata->type != data_type)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (value)
    {
        if (data_type == SRV_CCA_DATA_TYPE_INT)
            *((S32*)value) = (coredata->size ? coredata->values.i[0] : 0);
        else
            *((CHAR**)value) = (coredata->size ? coredata->values.s[0] : 0);
            
    }
    return SRV_CCA_STATUS_OK;
}
#endif /* __SRV_CCA_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_get_nodedata_int_first
 * DESCRIPTION
 *  retrieve the first int data of the matching the specified param_id in the node pointed by the iterator
 * PARAMETERS
 *  iter            [IN]        Can be a valid nodelist iterator or a valid datalist iterator
 *  param_id        [IN]        
 *  value           [OUT]       Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_ITER
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_get_nodedata_int_first(srv_cca_iterator_struct *iter, U16 param_id, S32 *value)
{
#ifdef __SRV_CCA_SLIM__

    return srv_cca_doc_get_nodedata_first(iter, param_id, SRV_CCA_DATA_TYPE_INT, (void *) value);

#else /* __SRV_CCA_SLIM__ */
    

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;
    srv_cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_cca_doc_get_nodedata_by_param(iter, param_id, &coredata);
    if (status != SRV_CCA_STATUS_OK)
        return status;

    if (coredata->type != SRV_CCA_DATA_TYPE_INT)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (value)
        *value = (coredata->size ? coredata->values.i[0] : 0);

    return SRV_CCA_STATUS_OK;

#endif /* __SRV_CCA_SLIM__ */

}




/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_get_nodedata_str_first
 * DESCRIPTION
 *  retrieve the first str data of the matching the specified param_id in the node pointed by the iterator
 * PARAMETERS
 *  iter            [IN]        Can be a valid nodelist iterator or a valid datalist iterator
 *  param_id        [IN]        
 *  value           [OUT]       Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_ITER
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_get_nodedata_str_first(srv_cca_iterator_struct *iter, U16 param_id, CHAR **value)
{
#ifdef __SRV_CCA_SLIM__

    return srv_cca_doc_get_nodedata_first(iter, param_id, SRV_CCA_DATA_TYPE_STR, (void *) value);

#else /* __SRV_CCA_SLIM__ */
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;
    srv_cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_cca_doc_get_nodedata_by_param(iter, param_id, &coredata);
    if (status != SRV_CCA_STATUS_OK)
        return status;

    if (coredata->type != SRV_CCA_DATA_TYPE_STR)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (value)
        *value = (coredata->size ? coredata->values.s[0] : 0);

    return SRV_CCA_STATUS_OK;

#endif /* __SRV_CCA_SLIM__ */
}



#ifdef __SRV_CCA_SLIM__
static srv_cca_status_enum srv_cca_doc_get_nodedata_list(srv_cca_iterator_struct *iter, U16 param_id, srv_cca_data_type_enum data_type, void **values, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;
    srv_cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_cca_doc_get_nodedata_by_param(iter, param_id, &coredata);
    if (status != SRV_CCA_STATUS_OK)
        return status;

    if (coredata->type != data_type)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (size)
        *size = coredata->size;

    if (values)
    {
        if (data_type == SRV_CCA_DATA_TYPE_INT)
            *((S32**)values) = (coredata->size ? coredata->values.i : 0);
        else
            *(CHAR ***)values = (coredata->size ? coredata->values.s : 0);
    }
    return SRV_CCA_STATUS_OK;
}
#endif /* __SRV_CCA_SLIM__ */


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_get_nodedata_ints
 * DESCRIPTION
 *  retrieve the int array of the matching the specified param_id in the node pointed by the iterator
 * PARAMETERS
 *  iter            [IN]        Can be a valid nodelist iterator or a valid datalist iterator
 *  param_id        [IN]        
 *  values          [IN]        Can be NULL pointer
 *  size            [IN]        Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_ITER
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_get_nodedata_ints(srv_cca_iterator_struct *iter, U16 param_id, S32 **values, S32 *size)
{
#ifdef __SRV_CCA_SLIM__

    return srv_cca_doc_get_nodedata_list(iter, param_id, SRV_CCA_DATA_TYPE_INT, (void * *) values, size);

#else /* __SRV_CCA_SLIM__ */


    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;
    srv_cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_cca_doc_get_nodedata_by_param(iter, param_id, &coredata);
    if (status != SRV_CCA_STATUS_OK)
        return status;

    if (coredata->type != SRV_CCA_DATA_TYPE_INT)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (size)
        *size = coredata->size;

    if (values)
        *values = (coredata->size ? coredata->values.i : 0);

    return SRV_CCA_STATUS_OK;

#endif /* __SRV_CCA_SLIM__ */
}




/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_get_nodedata_strs
 * DESCRIPTION
 *  retrieve the str array of the matching the specified param_id in the node pointed by the iterator
 * PARAMETERS
 *  iter            [IN]        Can be a valid nodelist iterator or a valid datalist iterator
 *  param_id        [IN]        
 *  values          [OUT]       Can be NULL pointer
 *  size            [OUT]       Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_ITER
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_TYPE_MISMATCHED
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_get_nodedata_strs(srv_cca_iterator_struct *iter, U16 param_id, CHAR ***values, S32 *size)
{
#ifdef __SRV_CCA_SLIM__

    return srv_cca_doc_get_nodedata_list(iter, param_id, SRV_CCA_DATA_TYPE_STR, (void * *) values, size);

#else /* __SRV_CCA_SLIM__ */
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_core_data_struct *coredata;
    srv_cca_status_enum status;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status = srv_cca_doc_get_nodedata_by_param(iter, param_id, &coredata);
    if (status != SRV_CCA_STATUS_OK)
        return status;

    if (coredata->type != SRV_CCA_DATA_TYPE_STR)
        return SRV_CCA_STATUS_TYPE_MISMATCHED;

    if (size)
        *size = coredata->size;

    if (values)
        *values = (coredata->size ? coredata->values.s : 0);

    return SRV_CCA_STATUS_OK;

#endif /* __SRV_CCA_SLIM__ */
}



#define SRV_CCA_DOC_ITER_NODE

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_iter_nodes_new
 * DESCRIPTION
 *  construct an iter_nodes object (for document structural info)
 * PARAMETERS
 *  node_id     [IN]        
 * RETURNS
 *  constructed iter_nodes object or 0 if mem full
 *****************************************************************************/
static srv_cca_doc_iter_nodes_struct *srv_cca_doc_iter_nodes_new(U16 node_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_iter_nodes_struct *iter_nodes_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    iter_nodes_list = srv_cca_malloc_type(srv_cca_doc_iter_nodes_struct);
    if (iter_nodes_list)
    {
        iter_nodes_list->nodes = 0;
        iter_nodes_list->next = 0;
        iter_nodes_list->num_nodes = 0;
        iter_nodes_list->node_id = node_id;
    }
    return iter_nodes_list;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_iter_nodes_list_release
 * DESCRIPTION
 *  release all memory occupied by this iter_nodes_list
 *  releaseLevel:
 *  0 = free each elem ptr only
 *  1 = free each elem ptr + free each nodelist elem ptr
 *  2 = free each elem ptr + free each nodelist elem ptr + free all nodes in nodelist
 * PARAMETERS
 *  iter_nodes_list     [IN]        
 *  releaseLevel        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_cca_doc_iter_nodes_list_release(srv_cca_doc_iter_nodes_struct *iter_nodes_list, U8 releaseLevel)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_doc_iter_nodes_struct *next;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (iter_nodes_list)
    {
        next = iter_nodes_list->next;
        if (iter_nodes_list->nodes)
            srv_cca_doc_nodelist_release(iter_nodes_list->nodes, (U8) (releaseLevel - 1));
        srv_cca_mfree(iter_nodes_list);
        iter_nodes_list = next;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_iter_nodes_find
 * DESCRIPTION
 *  find the matching iter_nodes of the node_id
 * PARAMETERS
 *  iter_nodes_list     [IN]        
 *  node_id             [IN]        
 * RETURNS
 *  constructed iter_nodes object or 0 if mem full
 *****************************************************************************/
static srv_cca_doc_iter_nodes_struct *srv_cca_doc_iter_nodes_find(srv_cca_doc_iter_nodes_struct *iter_nodes_list, U16 node_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (iter_nodes_list)
    {
        if (iter_nodes_list->node_id == node_id)
            return iter_nodes_list;
        iter_nodes_list = iter_nodes_list->next;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_construct_iter_nodes_list
 * DESCRIPTION
 *  analyse this doc tree and construct an iterator to the iter_nodes object for document structural info
 * PARAMETERS
 *  root        [IN]        
 * RETURNS
 *  constructed object or 0 if mem full
 *****************************************************************************/
static srv_cca_doc_iter_nodes_struct *srv_cca_doc_construct_iter_nodes_list(srv_cca_doc_node_struct *root)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_iterator_struct *iter_doc;
    srv_cca_doc_node_struct *crtNode;
    srv_cca_doc_iter_nodes_struct *iter_nodes_list;
    srv_cca_doc_iter_nodes_struct *matched_iter_nodes_list;
    srv_cca_doc_nodelist_struct *nodelist;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!root)
        return 0;

    iter_doc = srv_cca_iterator_new(SRV_CCA_TR_PREORDER, SRV_CCA_IT_DOC, (srv_cca_generic_ptr_struct*) root, 0);

    if (!iter_doc)
        return 0;

    iter_nodes_list = 0;
    while ((crtNode = (srv_cca_doc_node_struct*) srv_cca_iterator_next(iter_doc)) != 0)
    {
        /* attempt to find existing iter_nodes_list elem */
        matched_iter_nodes_list = srv_cca_doc_iter_nodes_find(iter_nodes_list, crtNode->node_id);

        /* create an empty iter_nodes_list if not found */
        if (!matched_iter_nodes_list)
        {
            matched_iter_nodes_list = srv_cca_doc_iter_nodes_new(crtNode->node_id);
            if (!matched_iter_nodes_list)
            {
                /* need to release iter_nodes_list!!! */
                srv_cca_doc_iter_nodes_list_release(iter_nodes_list, 1);
                iter_nodes_list = 0;
                break;
            }
            srv_cca_doc_link_list_elem_to_last(
                (srv_cca_generic_ptr_struct **) & iter_nodes_list,
                (srv_cca_generic_ptr_struct*) matched_iter_nodes_list);
        }

        /* add node to nodelist of the iter_nodes_list just then */
        nodelist = srv_cca_doc_nodelist_new(crtNode);
        if (!nodelist)
        {
            /* need to release iter_nodes_list!!! */
            srv_cca_doc_iter_nodes_list_release(iter_nodes_list, 1);
            iter_nodes_list = 0;
            break;
        }
        else
        {
            srv_cca_doc_link_list_elem_to_last(
                (srv_cca_generic_ptr_struct **) & (matched_iter_nodes_list->nodes),
                (srv_cca_generic_ptr_struct*) nodelist);

            SRV_CCA_ASSERT(matched_iter_nodes_list->num_nodes < SRV_CCA_ELM_MAX_NUM);
            
            matched_iter_nodes_list->num_nodes++;
        }
    }

    srv_cca_iterator_release(iter_doc);
    return iter_nodes_list;
}


#define SRV_CCA_DOC_NEW
/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_new
 * DESCRIPTION
 *  API to create a new CCA document with root node set to hRootNode
 * PARAMETERS
 *  hRootNode       [IN]        
 * RETURNS
 *  constructed document handle, 0=memory full or unable to construct
 *****************************************************************************/
S32 srv_cca_doc_new(S32 hRootNode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_document_struct *doc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!hRootNode)
        return 0;

    doc = srv_cca_malloc_type(srv_cca_document_struct);
    if (doc)
    {
        memset(doc, 0, sizeof(srv_cca_document_struct));

        doc->doc_tree = (srv_cca_doc_node_struct*) hRootNode;
        doc->iter_nodes_list = srv_cca_doc_construct_iter_nodes_list(doc->doc_tree);
        if (!(doc->iter_nodes_list))
        {
            srv_cca_mfree(doc);
            doc = 0;
        }
    }
    return (S32) doc;
}



/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_destroy
 * DESCRIPTION
 *  release all memory held by this document object
 * PARAMETERS
 *  hConfig     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_cca_doc_destroy(S32 hConfig)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_document_struct *doc;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (srv_cca_document_struct*) hConfig;
    if (!doc)
        return;

    srv_cca_doc_node_free((S32) (doc->doc_tree));
    srv_cca_doc_iter_nodes_list_release(doc->iter_nodes_list, 1);

    srv_cca_mfree(doc);
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_create
 * DESCRIPTION
 *  
 * PARAMETERS
 *          
 * RETURNS
 *  
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_create(srv_cca_spec_enum spec_type, SRV_CCA_HANDLE h_root_node, SRV_CCA_HANDLE *h_config)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_CCA_HANDLE h_cca_doc;
//    SRV_CCA_HANDLE h_dep_node;
    srv_cca_status_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    
    if (!h_root_node)
        return SRV_CCA_STATUS_INVALID_PARAM;

    if (!h_config)
    {
        h_cca_doc = srv_cca_doc_new(h_root_node);
        if (h_cca_doc)
            return SRV_CCA_STATUS_OK;
        else
            return SRV_CCA_STATUS_MEMFULL;
    }

    if (!h_config)
        return SRV_CCA_STATUS_INVALID_PARAM;
/*
    srv_cca_oma_fix_doc(h_root_node);
    h_dep_node = srv_cca_oma_generate_deprel_node(h_root_node);
    if (!h_dep_node)
        return SRV_CCA_STATUS_MEMFULL;
    srv_cca_doc_node_attach(h_dep_node, h_root_node);
    srv_cca_oma_sort_new_doc(h_root_node);
    h_cca_doc = srv_cca_doc_new(h_root_node);
    if (!h_cca_doc)
    {
       srv_cca_doc_node_detach(h_dep_node);
       srv_cca_doc_node_free(h_dep_node);
       return SRV_CCA_STATUS_MEMFULL;
    }
*/

    SRV_CCA_ASSERT(spec_type == SRV_CCA_SPEC_OMA);

    ret = srv_cca_oma_revise_doc(h_root_node);
    if (ret != SRV_CCA_STATUS_OK)
        return ret;
    h_cca_doc = srv_cca_doc_new(h_root_node);
    if (!h_cca_doc)
    {
        *h_config = 0;
        return SRV_CCA_STATUS_MEMFULL;
    }
    *h_config = h_cca_doc;
    return SRV_CCA_STATUS_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_get_nodes
 * DESCRIPTION
 *  retrieve an interator of nodelist of the same node_symbol
 * PARAMETERS
 *  hConfig             [IN]        
 *  node_symbol         [IN]        
 *  iter_nodelist       [OUT]       Can be NULL pointer
 *  size                [OUT]       Can be NULL pointer
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_NOT_FOUND
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_OK
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_get_nodes(S32 hConfig, U16 node_symbol, srv_cca_iterator_struct **iter_nodelist, S32 *size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_document_struct *doc;
    srv_cca_doc_iter_nodes_struct *iter_nodes_list;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (srv_cca_document_struct*) hConfig;
    if (iter_nodelist)
        *iter_nodelist = 0;
    if (size)
        *size = 0;

    if (!doc)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    iter_nodes_list = srv_cca_doc_iter_nodes_find(doc->iter_nodes_list, node_symbol);
    if (!iter_nodes_list)
        return SRV_CCA_STATUS_NOT_FOUND;

    if (size)
        *size = iter_nodes_list->num_nodes;

    if (iter_nodelist && iter_nodes_list->nodes)
    {
        *iter_nodelist = srv_cca_iterator_new(
                            SRV_CCA_TR_LIST,
                            SRV_CCA_IT_NODELIST,
                            (srv_cca_generic_ptr_struct*) iter_nodes_list->nodes,
                            0);

        if (!(*iter_nodelist))
        {
            if (size)
                *size = 0;
            return SRV_CCA_STATUS_MEMFULL;
        }
    }

    return SRV_CCA_STATUS_OK;
}






#define SRV_CCA_DOC_PARSE

/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_parse_mapping_table
 * DESCRIPTION
 *  pre: well-formed mapping table
 *  parse target application specified mapping table to a CCA tree
 * PARAMETERS
 *  table       [IN]        
 *  size        [IN]        
 * RETURNS
 *  constructed tree
 *****************************************************************************/
static srv_cca_doc_node_struct *srv_cca_doc_parse_mapping_table(const U16 *table, S32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 trigType;
    U16 crtSymbol;
    U16 entryID;
    U16 mappedSymbol;
    S32 index;
    srv_cca_doc_node_struct *root;
    srv_cca_doc_node_struct *crtNode;
    srv_cca_doc_node_struct *matchedChild;
    U8 state;   /* 0:new entry, 1:parsing node hierachy, 2:mapped symbol identified */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    root = (srv_cca_doc_node_struct*) srv_cca_doc_node_new(SRV_CCA_NS_DOCROOT);
    if (!root)
        return 0;

    mappedSymbol = 0;
    entryID = 0;
    trigType = 0;
    state = 0;
    crtNode = root;
    for (index = 0; index < size; index++)
    {
        crtSymbol = table[index];

        if (state == 0)
        {
            trigType = crtSymbol;
            state++;
        }
        else if (state == 1)
        {
            if (trigType == SRV_CCA_NS_TRIGPARM && table[index + 2] == 0xFFFF)
            {
                entryID = crtSymbol;
                mappedSymbol = table[index + 1];
                state++;
                index++;
                continue;
            }
            if (table[index + 1] == 0xFFFF) /* trigType = SRV_CCA_NS_TRIGNODE only */
            {
                entryID = SRV_CCA_NS_TRIGNODE;
                mappedSymbol = crtSymbol;
                state++;
                continue;
            }
            matchedChild = (srv_cca_doc_node_struct*) srv_cca_doc_list_find(
                                                    (srv_cca_generic_ptr_struct*) (crtNode->child),
                                                    srv_cca_doc_equal_node_id,
                                                    (void*)&crtSymbol);
            if (!matchedChild)
            {
                matchedChild = (srv_cca_doc_node_struct*) srv_cca_doc_node_new_and_attach(crtSymbol, (S32) crtNode);
                if (!matchedChild)
                {
                    /* cleanup!!! */
                    srv_cca_doc_node_free((S32) root);
                    root = 0;
                    break;
                }
            }
            crtNode = matchedChild;
        }
        else if (state == 2)
        {
            SRV_CCA_ASSERT(crtSymbol == 0xFFFF);
            if (srv_cca_doc_nodedata_add_int((S32) crtNode, entryID, (S32) mappedSymbol) != SRV_CCA_STATUS_OK)
            {
                /* cleanup!! */
                srv_cca_doc_node_free((S32) root);
                root = 0;
                break;
            }
            state = 0;
            crtNode = root;
        }
    }
    return root;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_match
 * DESCRIPTION
 *  pre: each child node of a same parent node must have different node ID
 *  path must start from SRV_CCA_NS_DOCROOT, and last node matching the path will be returned.
 *  attempt to find the node of the specified path from the specified doc tree (from "root")
 * PARAMETERS
 *  root        [IN]        
 *  path        [IN]        
 *  size        [IN]        
 * RETURNS
 *  matched node, 0 otherwise
 *****************************************************************************/
static srv_cca_doc_node_struct *srv_cca_doc_match(srv_cca_doc_node_struct *root, U16 *path, U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    level = 0;
    while (root && level < size)
    {
        if (root->node_id != path[level])
        {
            root = root->next;
            continue;
        }

        if (level == size - 1)
            return root;

        level++;
        root = root->child;
    }
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_cca_doc_process
 * DESCRIPTION
 *  the main processing function for application (ie, doc traversal->eliminate irrelevant nodes), symbol conversion)
 * PARAMETERS
 *  hConfig             [IN]        
 *  mapping_table       [IN]        
 *  size                [IN]        
 *  param_callback      [IN]        
 *  node_callback       [IN]        
 *  user_data           [IN]        
 * RETURNS
 *  SRV_CCA_STATUS_INVALID_HANDLE
 *  SRV_CCA_STATUS_MEMFULL
 *  SRV_CCA_STATUS_ABORT
 *  SRV_CCA_STATUS_OK
 *  ...or callback returned status
 *****************************************************************************/
srv_cca_status_enum srv_cca_doc_process(
                    S32 hConfig,
                    const U16 *mapping_table,
                    S32 size,
                    SRV_CCA_FP_PARAM_PROC param_callback,
                    SRV_CCA_FP_NODE_PROC node_callback,
                    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_document_struct *doc;
    srv_cca_doc_node_struct *tableRoot;

    srv_cca_doc_node_struct *crtNode;
    srv_cca_doc_node_struct *matchedTableNode;

    srv_cca_iterator_struct *iter_docDatalist;
    srv_cca_iterator_struct *iter_tableDatalist;

    srv_cca_core_data_struct *tableCoredata;
    srv_cca_core_data_struct *docCoredata;

    S32 symbol;
    U16 pathSymbols[CCA_TREE_MAX_LEVELS];
    srv_cca_status_enum retStatus, procStatus;
    U32 crtLevel;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    doc = (srv_cca_document_struct*) hConfig;
    if (!doc || !mapping_table)
        return SRV_CCA_STATUS_INVALID_HANDLE;

    /* SRV_CCA_LOG_DOC(hConfig); */

    if ((tableRoot = srv_cca_doc_parse_mapping_table(mapping_table, size)) == 0)
        return SRV_CCA_STATUS_MEMFULL;

    retStatus = SRV_CCA_STATUS_OK;
    crtLevel = 0;
    crtNode = doc->doc_tree;
    while (crtNode)
    {
        kal_mem_set(pathSymbols + crtLevel, 0, (CCA_TREE_MAX_LEVELS - crtLevel) * sizeof(U16));
        pathSymbols[crtLevel] = crtNode->node_id;

        matchedTableNode = srv_cca_doc_match(tableRoot, (U16*) pathSymbols, crtLevel + 1);
        if (matchedTableNode)
        {
            if (crtLevel == 1)
            {
                /* ***** check whether this node's in app's context + has dependency setting available ***** */
                if (!srv_cca_oma_is_in_app_context(crtNode))
                    goto process_visit_next;
            }

            /* ***** trigger callback(s) ***** */
            /* init datalist iterators */
            iter_tableDatalist = srv_cca_iterator_new(
                                    SRV_CCA_TR_LIST,
                                    SRV_CCA_IT_DATALIST,
                                    (srv_cca_generic_ptr_struct*) (matchedTableNode->listchain),
                                    0);
            iter_docDatalist = srv_cca_iterator_new(SRV_CCA_TR_LIST, SRV_CCA_IT_DATALIST, (srv_cca_generic_ptr_struct*) (crtNode->listchain), 0);
            if (!iter_tableDatalist || !iter_docDatalist)
            {
                srv_cca_iterator_release(iter_tableDatalist);
                srv_cca_iterator_release(iter_docDatalist);
                srv_cca_doc_node_free((S32) tableRoot);
                return SRV_CCA_STATUS_MEMFULL;
            }
            /* always trigger node callback first if defined in mapping table */
            if (node_callback &&
                srv_cca_doc_get_nodedata_by_param(iter_tableDatalist, SRV_CCA_NS_TRIGNODE, &tableCoredata) == SRV_CCA_STATUS_OK)
            {
                /* namespace conversion */
                symbol = crtNode->node_id;
                crtNode->node_id = tableCoredata->values.i[0];
                /* trigger callback */
                procStatus = node_callback(hConfig, (S32) crtNode, crtNode->node_id, iter_docDatalist, user_data);
                /* restore namespace */
                crtNode->node_id = symbol;

                if (procStatus != SRV_CCA_STATUS_OK)
                    retStatus = procStatus;

                if (retStatus == SRV_CCA_STATUS_ABORT)
                {
                    srv_cca_iterator_release(iter_docDatalist);
                    srv_cca_iterator_release(iter_tableDatalist);
                    srv_cca_doc_node_free((S32) tableRoot);
                    return SRV_CCA_STATUS_ABORT;
                }
            }   /* end if (node_callback ...) */

            /* trigger param callback */
            if (param_callback)
            {
                srv_cca_iterator_restart(iter_tableDatalist);
                /* loop through all interested param entries of this node as defined in mapping table */
                while (srv_cca_doc_nodedata_next(iter_tableDatalist, &tableCoredata) == SRV_CCA_STATUS_OK)
                {
                    /* ignore trigger by node entry */
                    if (tableCoredata->id == SRV_CCA_NS_TRIGNODE)
                        continue;

                    /* move to next param entry in mapping table if this param is not found in config doc */
                    if (srv_cca_doc_get_nodedata_by_param(iter_docDatalist, tableCoredata->id, &docCoredata) !=
                        SRV_CCA_STATUS_OK)
                        continue;

                    /* namespace conversion */
                    symbol = docCoredata->id;
                    docCoredata->id = tableCoredata->values.i[0];
                    /* trigger callback */
                    procStatus = param_callback(hConfig, docCoredata->id, docCoredata, user_data);
                    /* restore namespace */
                    docCoredata->id = symbol;

                    if (procStatus != SRV_CCA_STATUS_OK)
                        retStatus = procStatus;

                    if (retStatus == SRV_CCA_STATUS_ABORT)
                    {
                        srv_cca_iterator_release(iter_docDatalist);
                        srv_cca_iterator_release(iter_tableDatalist);
                        srv_cca_doc_node_free((S32) tableRoot);
                        return SRV_CCA_STATUS_ABORT;
                    }
                }
            }   /* end if (param_callback ...) */

            srv_cca_iterator_release(iter_docDatalist);
            srv_cca_iterator_release(iter_tableDatalist);

            /* visit child */
            if (crtNode->child)
            {
                crtNode = crtNode->child;
                crtLevel++;
                continue;
            }
        }   /* end if (matchedTableNode) */

      process_visit_next:
        /* if path not defined in mapping table --> dont bother visit its child */
        /* OR a defined node has no child --> find next node to visit */
        /* find next node to visit (ie, next sibling node, or parent's sibling node if this node is a leaf node) */
        while (crtNode && !(crtNode->next))
        {
            crtNode = crtNode->parent;
            crtLevel--;
        }
        if (crtNode)
            crtNode = crtNode->next;

    }   /* end while(crtNode) */
    srv_cca_doc_node_free((S32) tableRoot);
    return retStatus;
}


#define SRV_CCA_API_ADAPTOR
/*----------------------------------------------------------------------------*/
/* Adaptor APIs                                                               */
/*----------------------------------------------------------------------------*/
extern srv_cca_status_enum srv_cca_doc_coredata_get_ints(SRV_CCA_HANDLE h_coredata, S32 **values, S32 *num)
{
    return SRV_CCA_STATUS_FAIL;
}

extern srv_cca_status_enum srv_cca_doc_coredata_get_strs(SRV_CCA_HANDLE h_coredata, CHAR **values, S32 *num)
{
    return SRV_CCA_STATUS_FAIL;
}


srv_cca_status_enum srv_cca_doc_coredata_update_int(SRV_CCA_HANDLE h_coredata,S32 index,  S32 value)
{
    if (index < 0)
        return srv_cca_doc_update_coredata_int((srv_cca_core_data_struct *)h_coredata, value);
    else
    {
		return SRV_CCA_STATUS_FAIL;
    }
}

srv_cca_status_enum srv_cca_doc_coredata_update_str(SRV_CCA_HANDLE h_coredata, S32 index, const CHAR *value)
{
    if (index < 0)
        return srv_cca_doc_update_coredata_str((srv_cca_core_data_struct*)h_coredata, value);
    else
    {
		return SRV_CCA_STATUS_FAIL;

    }
}


extern srv_cca_status_enum srv_cca_doc_coredata_get_value(SRV_CCA_HANDLE h_coredata, S32 index, 
                    srv_cca_data_type_enum *data_type, void *value)
{
    return SRV_CCA_STATUS_FAIL;
}

extern srv_cca_status_enum srv_cca_doc_coredata_get_all_value(SRV_CCA_HANDLE h_coredata, S32 index, 
                    srv_cca_data_type_enum *data_type, void **value_list, S32 *num)
{
    return SRV_CCA_STATUS_FAIL;
}


extern srv_cca_status_enum srv_cca_doc_coredata_update_value(SRV_CCA_HANDLE h_coredata, S32 index, 
                    srv_cca_data_type_enum data_type, void *value)
{
    return SRV_CCA_STATUS_FAIL;
}


extern SRV_CCA_HANDLE srv_cca_doc_node_create(U16 node_symbol, SRV_CCA_HANDLE h_parent_node)
{
    if (!h_parent_node)
        return srv_cca_doc_node_new(node_symbol);
    return srv_cca_doc_node_new_and_attach(node_symbol, h_parent_node);
}

extern SRV_CCA_HANDLE srv_cca_doc_node_clone(U16 node_symbol, SRV_CCA_HANDLE h_parent_node)
{
    S32 hNode;

    /* duplicate a node and attach it to its parent node */
    hNode =  srv_cca_doc_node_duplicate(node_symbol);
    if (h_parent_node)
       srv_cca_doc_node_attach(hNode, h_parent_node);
    return hNode;
}

extern void srv_cca_doc_node_destroy(SRV_CCA_HANDLE h_node)
{
    srv_cca_doc_node_free(h_node);
}


/* The name is duplicated, temp use it */
srv_cca_status_enum srv_cca_doc_node_add_int(SRV_CCA_HANDLE h_node, U16 param_id, S32 value)
{
    return srv_cca_doc_nodedata_add_int(h_node, param_id, value);
}

/* The name is duplicated, temp use it */
srv_cca_status_enum srv_cca_doc_node_add_str(SRV_CCA_HANDLE h_node, U16 param_id, const CHAR *value)
{
    return srv_cca_doc_nodedata_add_str(h_node, param_id, value);
}

srv_cca_status_enum srv_cca_doc_nodedata_update_int(SRV_CCA_HANDLE h_node, U16 param_id, S32 value)
{
    return srv_cca_doc_update_nodedata_int(h_node, param_id, value);
}

srv_cca_status_enum srv_cca_doc_nodedata_update_str(SRV_CCA_HANDLE h_node, U16 param_id, const CHAR *value)
{
    return srv_cca_doc_update_nodedata_str(h_node, param_id, value);
}


srv_cca_status_enum srv_cca_doc_node_get_data(SRV_CCA_HANDLE h_node, U16 param_id, SRV_CCA_HANDLE *h_coredata)
{
    return  srv_cca_doc_nodedata_by_param(h_node, param_id, (srv_cca_core_data_struct **)h_coredata);
}


extern SRV_CCA_HANDLE srv_cca_doc_iterator_new(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_cca_iterator_struct *iter;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Just set it with invalid value unused */
    iter = srv_cca_iterator_new(SRV_CCA_TR_LIST, SRV_CCA_IT_NODELIST, NULL, MMI_FALSE);
    srv_cca_iterator_restart(iter);
    return (SRV_CCA_HANDLE)iter;
}


extern SRV_CCA_HANDLE srv_cca_doc_iterator_restart(SRV_CCA_HANDLE h_iter)
{
    srv_cca_iterator_restart((srv_cca_iterator_struct *)h_iter);
    return h_iter;
}

extern SRV_CCA_HANDLE srv_cca_doc_iterator_next(SRV_CCA_HANDLE h_iter, SRV_CCA_HANDLE *h_obj)
{
    SRV_CCA_HANDLE h_elm;
    srv_cca_iterator_struct *iter = (srv_cca_iterator_struct*)h_iter;
    
    h_elm = (SRV_CCA_HANDLE)srv_cca_iterator_next((srv_cca_iterator_struct*)h_iter);

    if (!h_obj)
        return h_elm;

    switch(iter->iter_type)
    {
    case SRV_CCA_IT_NODELIST:
        *h_obj = (SRV_CCA_HANDLE)(((srv_cca_doc_nodelist_struct*)iter->current)->node);
        break;
        
    case SRV_CCA_IT_NODECHAIN:
        *h_obj = (SRV_CCA_HANDLE)((srv_cca_doc_node_struct*)iter->current);
        break;

    case SRV_CCA_IT_DATALIST:
        *h_obj = (SRV_CCA_HANDLE)&(((srv_cca_doc_node_datalist_struct*)iter->current)->data);
        break;
        
    default:
        *h_obj = SRV_CCA_INVALID_HANDLE;
        break;
    }
	return h_elm;
}


extern srv_cca_status_enum srv_cca_doc_iterator_create_node_iter(
                        SRV_CCA_HANDLE h_config,
                        U16 node_symbol,
                        SRV_CCA_HANDLE *h_iter_nodelist,
                        S32 *size)
{
    
    return  srv_cca_doc_get_nodes(h_config, node_symbol, 
                                 (srv_cca_iterator_struct **)h_iter_nodelist, size);
}


extern srv_cca_status_enum srv_cca_doc_iterator_create_nodedata_iter(
                        SRV_CCA_HANDLE h_iter_nodelist,
                        SRV_CCA_HANDLE *h_iter_datalist,
                        S32 *size)
{
    return srv_cca_doc_get_nodedata(
                            (srv_cca_iterator_struct *)h_iter_nodelist,
                            (srv_cca_iterator_struct **)h_iter_datalist,
                            size);

}

extern void srv_cca_doc_iterator_destroy(SRV_CCA_HANDLE h_iter)
{
    srv_cca_iterator_release((srv_cca_iterator_struct *)h_iter);
}


#endif /* __CCA_SUPPORT__ */ 

