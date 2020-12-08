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

/*******************************************************************************
 * Filename:
 * ---------
 * MMSMemoryManagerSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*********************************************************/
/*********************MEMORY RELATED WILL BE MOVED SOON***/
// #include "MMI_include.h"
#include "MMI_features.h"
#if defined (__MMI_MMS_2__)

#include "MMIDataType.h"
#include "string.h"
#include "kal_public_api.h"
#include "custom_wap_config.h"
#include "GlobalResDef.h"
#include "app_mem.h"
#include "kal_general_types.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mms_sap_struct.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_ltlcom.h" 

#include "kal_public_defs.h" 
#include "mms_adp.h"
#include "mma_api.h"
#include "mma_struct.h"

#include "MmsSrvGprot.h"
#include "MMSMemoryManagerSrv.h"
#include "MmsSrvProt.h"
#include "MmsMsgParseSrv.h"
#include "mmi_rp_srv_mms_def.h"

/*If Template is defined Template generation takes around >4K memory, if template is not defined but Cosmos NCentre */
/*is defined, it does not have memory to give to umms service, so umms service will use its memory*/
#if defined (__MMI_MMS_TEMPLATE_SUPPORT__) || defined(__COSMOS_MMI_PACKAGE__) 
#define SRV_MMS_APP_MEM_POOL_SIZE 10*1024
#define SRV_MMS_LOW_MEMORY_SIZE  3000
#else /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 
#define SRV_MMS_LOW_MEMORY_SIZE  1500
#define SRV_MMS_APP_MEM_POOL_SIZE 5*1024
#endif /* __MMI_MMS_TEMPLATE_SUPPORT__ */ 

#ifdef __MMI_MMS_USE_ASM__
#define SRV_MMS_ASM_POOL_SIZE 20*1024
#else 
#define SRV_MMS_ASM_POOL_SIZE 40*1024
#endif 

static srv_mms_mem_mgr_get_asm_alloc_struct g_asm_pool[SRV_MMS_MAX_ASM_POOL];
U32 g_srv_app_adm[SRV_MMS_APP_MEM_POOL_SIZE / sizeof(U32)];
static U32 g_asm_req_id;

static srv_mms_mem_mgr_get_asm_alloc_struct *srv_mms_mem_mgr_get_asm_pool(U16 app_asm_id);
static srv_mms_mem_mgr_get_asm_alloc_struct *srv_mms_mem_mgr_get_free_asm_pool(U16 app_id);
static void srv_mms_mem_mgr_register_app(U16 app_asm_id, U32 index);
static void srv_mms_mem_mgr_send_rsp_for_asm_pool_ptr(MMI_BOOL success_alloc);
static void srv_mms_mem_mgr_app_stop_cb_int(void);
static void srv_mms_mem_mgr_viewer_stop_cb_int(void);
static srv_mms_mem_mgr_get_asm_alloc_struct *srv_mms_mem_mgr_asm_get_pool_int(U16 app_asm_id, U32 index);

#ifdef __MMI_MMS_USE_ASM__
static void srv_mms_mem_mgr_service_stop_cb_int(void);
#endif 
/* Get context, set context and free context of ASM GENERIC */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_get_asm_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_asm_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_mem_mgr_get_asm_alloc_struct *srv_mms_mem_mgr_get_asm_pool(U16 app_asm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_MMS_MAX_ASM_POOL; i++)
    {
        if (g_asm_pool[i].app_asm_id == app_asm_id)
        {
            return &g_asm_pool[i];
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_get_free_asm_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_asm_id      [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_mem_mgr_get_asm_alloc_struct *srv_mms_mem_mgr_get_free_asm_pool(U16 app_asm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_MMS_MAX_ASM_POOL; i++)
    {
        if (g_asm_pool[i].is_used == MMI_UMMS_FALSE)
        {
            g_asm_pool[i].app_asm_id = app_asm_id;
            g_asm_pool[i].is_used = MMI_UMMS_TRUE;
            return &g_asm_pool[i];
        }
    }
    return NULL;
}

/* Get context, set context and free context of ASM */

/* init asm context for viewer */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_init_viewer_asm_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_asm_id          [IN]        
 *  index               [IN]        
 *  asm_in_cntx         [?]         
 *  success_cb(?)       [IN]        
 *  stop_cb(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_init_viewer_asm_pool(U16 app_asm_id, U32 index, srv_mms_mem_mgr_get_asm_alloc_struct *asm_in_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        index = SRV_MMS_INSTANCE_DEFAULT_INDEX;
    }
    asm_cntx = srv_mms_mem_mgr_asm_get_pool_int(app_asm_id, index);
    asm_cntx->img_id = asm_in_cntx->img_id;
    asm_cntx->str_id = asm_in_cntx->str_id;
    asm_cntx->app_pool_size = SRV_MMS_VIEWER_ASM_MEM_POOL_SIZE;
    asm_cntx->success_cb = asm_in_cntx->success_cb;
    asm_cntx->stop_cb = asm_in_cntx->stop_cb;
    asm_cntx->user_data = asm_in_cntx->user_data;
    asm_cntx->alloc_fn = asm_in_cntx->alloc_fn;
    asm_cntx->free_fn = asm_in_cntx->free_fn;
	#ifdef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__
    asm_cntx->cancel_cb = asm_in_cntx->cancel_cb;
    #endif
    srv_mms_mem_mgr_register_app(app_asm_id, index);
}

/* init asm context for app */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_init_app_asm_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_asm_id          [IN]        
 *  index               [IN]        
 *  asm_in_cntx         [?]         
 *  success_cb(?)       [IN]        
 *  stop_cb(?)          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_init_app_asm_pool(U16 app_asm_id, U32 index, srv_mms_mem_mgr_get_asm_alloc_struct *asm_in_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = NULL;
    srv_mms_instance_context_struct *inst = srv_mms_get_instance(index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(inst);
    asm_cntx = &inst->app_cntx;
    asm_cntx->img_id = asm_in_cntx->img_id;
    asm_cntx->str_id = asm_in_cntx->str_id;
    asm_cntx->app_pool_size = SRV_MMS_ASM_POOL_SIZE;
    asm_cntx->success_cb = asm_in_cntx->success_cb;
    asm_cntx->stop_cb = asm_in_cntx->stop_cb;
    asm_cntx->cancel_cb = asm_in_cntx->cancel_cb;
    asm_cntx->user_data = asm_in_cntx->user_data;
    asm_cntx->alloc_fn = asm_in_cntx->alloc_fn;
    asm_cntx->free_fn = asm_in_cntx->free_fn;
    srv_mms_mem_mgr_register_app(app_asm_id, index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_init_app_adm
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_init_app_adm(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_ADM_UMMS))
    {
        asm_cntx = srv_mms_mem_mgr_get_free_asm_pool(APPLIB_MEM_AP_ID_ADM_UMMS);
        ASSERT(asm_cntx);
        asm_cntx->img_id = 0;
        asm_cntx->str_id = 0;
        asm_cntx->app_pool_size = SRV_MMS_APP_MEM_POOL_SIZE;
        asm_cntx->success_cb = NULL;
        asm_cntx->stop_cb = NULL;
        asm_cntx->ptr_asm_pool = (PU8) & g_srv_app_adm;
        srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_ADM_UMMS, 0);
    }
}

/* register asm pool GENERIC */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_register_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_asm_id      [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_register_app(U16 app_asm_id, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = NULL;
    void (*stop_cb) (void);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    stop_cb = NULL;
    asm_cntx = srv_mms_mem_mgr_asm_get_pool_int(app_asm_id, index);
    if (app_asm_id == APPLIB_MEM_AP_ID_MMS_VIEWER)
    {
        stop_cb = srv_mms_mem_mgr_viewer_stop_cb_int;
    }
    else if (app_asm_id == APPLIB_MEM_AP_ID_UMMS)
    {
        stop_cb = srv_mms_mem_mgr_app_stop_cb_int;
    }
#ifdef __MMI_MMS_USE_ASM__
    if (app_asm_id == APPLIB_MEM_AP_ID_MMS_SERVICE)
    {
        stop_cb = srv_mms_mem_mgr_service_stop_cb_int;
    }
#endif /* __MMI_MMS_USE_ASM__ */ 
    applib_mem_ap_register(asm_cntx->app_asm_id, asm_cntx->str_id, asm_cntx->img_id, stop_cb);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_app_stop_cb_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_app_stop_cb_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_copy_pools(SRV_MMS_INSTANCE_DEFAULT_INDEX, APPLIB_MEM_AP_ID_UMMS);
    asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_UMMS);
    ASSERT(asm_cntx);
    asm_cntx->stop_cb(asm_cntx->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_viewer_stop_cb_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_viewer_stop_cb_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_copy_pools(SRV_MMS_INSTANCE_DEFAULT_INDEX, APPLIB_MEM_AP_ID_MMS_VIEWER);
    asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER);
    ASSERT(asm_cntx);
    asm_cntx->stop_cb(asm_cntx->user_data);
}

#ifdef __MMI_MMS_USE_ASM__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_service_stop_cb_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_service_stop_cb_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_MMS_SERVICE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(asm_cntx);
    asm_cntx->stop_cb(NULL);
}
#endif /* __MMI_MMS_USE_ASM__ */ 
/* alloc asm pool GENERIC */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_alloc_asm_pool
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_asm_id      [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_UMMS_ERROR srv_mms_mem_mgr_alloc_asm_pool(U16 app_asm_id, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = NULL;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asm_cntx = srv_mms_mem_mgr_asm_get_pool_int(app_asm_id, index);
    ASSERT(asm_cntx);
    if (asm_cntx->alloc_fn == NULL)
    {
        if (asm_cntx != NULL && asm_cntx->ptr_asm_pool == NULL)
        {
            asm_cntx->ptr_asm_pool = applib_mem_ap_alloc(asm_cntx->app_asm_id, asm_cntx->app_pool_size);
        }
        if (asm_cntx->ptr_asm_pool == NULL)
        {
            mmi_frm_appmem_prompt_to_release_mem(
                asm_cntx->app_asm_id,
                asm_cntx->img_id,
                asm_cntx->app_pool_size,
                asm_cntx->success_cb);
            if (asm_cntx->cancel_cb)
            {
                mmi_frm_appmem_set_cancel_callback((applib_mem_ap_id_enum)asm_cntx->app_asm_id, (mmi_frm_appmem_cb) asm_cntx->cancel_cb);
            }
            return MMI_UMMS_ASM_DRAW_SCR;
        }
        else if (asm_cntx->adm_pool_id == NULL
    #ifdef __MMI_MMS_USE_ASM__
                 && asm_cntx->app_asm_id != APPLIB_MEM_AP_ID_MMS_SERVICE
    #endif 
            )
        {
            asm_cntx->adm_pool_id = kal_adm_create(asm_cntx->ptr_asm_pool, asm_cntx->app_pool_size, NULL, MMI_FALSE);
            ASSERT(asm_cntx->adm_pool_id);
            if (asm_cntx->app_asm_id == APPLIB_MEM_AP_ID_MMS_VIEWER || asm_cntx->app_asm_id == APPLIB_MEM_AP_ID_UMMS)
                srv_mms_mem_mgr_copy_pools(index, asm_cntx->app_asm_id);
            return MMI_UMMS_TRUE;
        }
    }
    else
    {
        srv_mms_mem_mgr_copy_pools(index, asm_cntx->app_asm_id);
    }
    return MMI_UMMS_TRUE;

}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_is_asm_alloc_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_is_asm_alloc_done(U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_UMMS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (asm_cntx != NULL)
    {
        if (asm_cntx->ptr_asm_pool != NULL)
        {
            if (asm_cntx->adm_pool_id != NULL)
            {
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_check_asm_total_pool
 * DESCRIPTION
 *  Check total pool available
 * PARAMETERS
 *  success_cb          [IN]        
 *  index               [IN]        
 *  app_asm_id(?)       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR srv_mms_mem_mgr_check_asm_total_pool(app_asm_sucess_cb success_cb, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = NULL;
    PU8 ptr_asm_pool = NULL;
    U32 req_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asm_cntx = srv_mms_mem_mgr_asm_get_pool_int(APPLIB_MEM_AP_ID_UMMS, index);
    req_size = SRV_MMS_VIEWER_ASM_MEM_POOL_SIZE + SRV_MMS_ASM_POOL_SIZE;
#ifdef __MMI_MMS_USE_ASM__
    req_size += MMA_ASM_MEM_POOL_SIZE;
#endif 
    ptr_asm_pool = applib_mem_ap_alloc(asm_cntx->app_asm_id, req_size);
    if (ptr_asm_pool == NULL)
    {
        mmi_frm_appmem_prompt_to_release_mem(asm_cntx->app_asm_id, asm_cntx->img_id, req_size, success_cb);
        if (asm_cntx->cancel_cb)
            {
                mmi_frm_appmem_set_cancel_callback((applib_mem_ap_id_enum)asm_cntx->app_asm_id, (mmi_frm_appmem_cb) asm_cntx->cancel_cb);
            }
        return MMI_UMMS_ASM_DRAW_SCR;
    }
    else
    {
        applib_mem_ap_free(ptr_asm_pool);
        ptr_asm_pool = NULL;
    }

	return MMI_UMMS_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_asm_get_pool_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  app_asm_id      [IN]        
 *  index           [IN]        
 * RETURNS
 *  
 *****************************************************************************/
srv_mms_mem_mgr_get_asm_alloc_struct *srv_mms_mem_mgr_asm_get_pool_int(U16 app_asm_id, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = NULL;
    srv_mms_instance_context_struct *inst = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index == 0)
    {
        asm_cntx = srv_mms_mem_mgr_get_asm_pool(app_asm_id);
    }
    else
    {
        inst = srv_mms_get_instance(index);
        ASSERT(inst);
        if (app_asm_id == APPLIB_MEM_AP_ID_UMMS)
        {
            asm_cntx = &inst->app_cntx;
        }
        else
        {
            asm_cntx = &inst->viewer_cntx;
        }
        asm_cntx->app_asm_id = app_asm_id;
    }
    return asm_cntx;
}

/* Delete asm pool GENERIC */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_asm_deinit_memory
 * DESCRIPTION
 *  De-init memory from ASM pool
 * PARAMETERS
 *  app_asm_id      [IN]        
 *  index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_asm_deinit_memory(U16 app_asm_id, U32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_asm_get_pool_int(app_asm_id, index);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MMI_TRACE(MMI_INET_TRC_G6_MMS, MMI_UMMS_MEMORY_DEINIT); */
    ASSERT(asm_cntx);
    if (asm_cntx->alloc_fn == NULL && asm_cntx->app_id == 0)
    {
        if (asm_cntx->adm_pool_id)
        {
            kal_adm_delete(asm_cntx->adm_pool_id);
            asm_cntx->adm_pool_id = 0;
        }

        if (asm_cntx->ptr_asm_pool)
        {
            applib_mem_ap_free(asm_cntx->ptr_asm_pool);
            asm_cntx->ptr_asm_pool = NULL;
        }
        if (app_asm_id == APPLIB_MEM_AP_ID_UMMS || app_asm_id == APPLIB_MEM_AP_ID_MMS_VIEWER)
        {
            memset(asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
            srv_mms_mem_mgr_copy_pools(index, app_asm_id);
        }
    }
    else
    {
#ifdef __MMI_MMS_USE_ASM__
		if(app_asm_id == APPLIB_MEM_AP_ID_MMS_SERVICE && asm_cntx->app_id)
		{
			mmi_frm_asm_free_r(asm_cntx->app_id, asm_cntx->ptr_asm_pool);
			memset(asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
		}
		else
#endif /*__MMI_MMS_USE_ASM__*/
		{
			memset(asm_cntx, 0, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
			srv_mms_mem_mgr_copy_pools(index, app_asm_id);
		}
	}
}

/* memory manger asm related */


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_viewer_asm_alloc_userdata
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_mms_mem_mgr_viewer_asm_alloc_userdata(U32 size, void* user_data)
{
    return srv_mms_mem_mgr_viewer_asm_alloc(size);
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_viewer_asm_free_userdata
 * DESCRIPTION
 *  free memory
 * PARAMETERS
 *  pmem        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_viewer_asm_free_userdata(void *pmem, void* user_data)
{
    srv_mms_mem_mgr_viewer_asm_free(pmem);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_viewer_asm_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_mms_mem_mgr_viewer_asm_alloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER);

    ASSERT(asm_cntx);
    if (asm_cntx->alloc_fn)
    {
        return asm_cntx->alloc_fn(size, asm_cntx->user_data);
    }
    if (asm_cntx->adm_pool_id)
    {
        return kal_adm_alloc(asm_cntx->adm_pool_id, size);

    }

	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_app_asm_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_mms_mem_mgr_app_asm_alloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *memory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_UMMS);

    ASSERT(asm_cntx);
    if (asm_cntx->alloc_fn)
    {
        memory = asm_cntx->alloc_fn(size, asm_cntx->user_data);
        if (memory == NULL)
        {
            EXT_ASSERT(0, 0, 0, 0);
            return memory;
        }
        return memory;
    }
    if (asm_cntx->adm_pool_id)
    {
        memory = kal_adm_alloc(asm_cntx->adm_pool_id, size);
        if (memory == NULL)
        {
            EXT_ASSERT(0, 0, 0, 0);
            return memory;
        }
        return memory;
    }

	return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_viewer_asm_free
 * DESCRIPTION
 *  free memory
 * PARAMETERS
 *  pmem        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_viewer_asm_free(void *pmem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_MMS_VIEWER);

    ASSERT(asm_cntx);
    if (asm_cntx->free_fn)
    {
        asm_cntx->free_fn(pmem);
        return;
    }
    if (asm_cntx->adm_pool_id)
    {
        kal_adm_free(asm_cntx->adm_pool_id, pmem);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_app_asm_free
 * DESCRIPTION
 *  free memory
 * PARAMETERS
 *  pmem        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_app_asm_free(void *pmem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_UMMS);

    ASSERT(asm_cntx);
    if (asm_cntx->free_fn)
    {
        asm_cntx->free_fn(pmem);
        return;
    }
    if (asm_cntx->adm_pool_id)
    {
        kal_adm_free(asm_cntx->adm_pool_id, pmem);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_app_adm_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void *srv_mms_mem_mgr_app_adm_alloc(U32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *memory;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_ADM_UMMS);

    memory = kal_adm_alloc(asm_cntx->adm_pool_id, size);
    if (memory == NULL)
    {
        EXT_ASSERT(0, 0, 0, 0);
        return NULL;
    }
    return memory;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_app_adm_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pmem        [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_app_adm_free(void *pmem)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_ADM_UMMS);

    ASSERT(asm_cntx);
    kal_adm_free(asm_cntx->adm_pool_id, pmem);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_app_adm_low_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
BOOL srv_mms_mem_mgr_app_adm_low_memory(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 left_size;
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_ADM_UMMS);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    left_size = kal_adm_get_total_left_size(asm_cntx->adm_pool_id);
    if (left_size <= SRV_MMS_LOW_MEMORY_SIZE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/* ASM Support For MMS Service */
#ifdef __MMI_MMS_USE_ASM__


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_init_asm_for_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  pmem        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
MMI_UMMS_ERROR srv_mms_mem_mgr_init_asm_for_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_MMS_SERVICE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (asm_cntx == NULL)
    {
        asm_cntx = srv_mms_mem_mgr_get_free_asm_pool(APPLIB_MEM_AP_ID_MMS_SERVICE);
        ASSERT(asm_cntx);
    }
    asm_cntx->img_id = IMG_ID_SRV_MMS_VIEWER_APP;
    asm_cntx->str_id = STR_ID_UMMS_MMS_SERVICE;
    asm_cntx->success_cb = srv_mms_mem_mgr_success_cb_asm_for_service;
    asm_cntx->stop_cb = srv_mms_mem_mgr_stop_cb_asm_for_service;
    asm_cntx->cancel_cb = srv_mms_mem_mgr_cancel_cb_asm_for_service;

	return MMI_UMMS_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_init_asm_for_service_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  pmem        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_init_asm_for_service_ext(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_MMS_SERVICE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (asm_cntx == NULL)
    {
        asm_cntx = srv_mms_mem_mgr_get_free_asm_pool(APPLIB_MEM_AP_ID_MMS_SERVICE);
        ASSERT(asm_cntx);
    }
	MMI_ASSERT(app_id);
	asm_cntx->app_id = app_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_success_cb_asm_for_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 *  pmem        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_success_cb_asm_for_service(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_MMS_SERVICE);
    MMI_UMMS_ERROR ret_val = MMI_UMMS_FALSE;
    srv_mms_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_ASM_SUCCESS);
    /* Call For Pool ptr also */
    ret_val = srv_mms_mem_mgr_alloc_asm_pool(APPLIB_MEM_AP_ID_MMS_SERVICE, 0);
    if (ret_val == MMI_UMMS_TRUE)
    {
        srv_mms_mem_mgr_send_rsp_for_asm_pool_ptr((MMI_BOOL)ret_val);
        mmi_frm_cb_emit_event((mmi_event_struct*) & evt);
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_stop_cb_asm_for_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  user_data       [?]     
 *  pmem        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_stop_cb_asm_for_service(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_MMS_SERVICE);
    srv_mms_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_ASM_STOP);
    srv_mms_mem_mgr_send_deinit_asm_memory_req();
    mmi_frm_cb_emit_event((mmi_event_struct*) & evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_send_deinit_asm_memory_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_send_deinit_asm_memory_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_get_deinit_asm_pool_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req =
        (mmi_mms_get_deinit_asm_pool_req_struct*) OslConstructDataPtr(sizeof(mmi_mms_get_deinit_asm_pool_req_struct));

    req->req_id = g_asm_req_id;

    srv_mms_send_message(
        MOD_MMI,
        mms_get_service_module(MSG_ID_MMI_MMS_GET_DEINIT_SERVICE_ASM_REQ),
        0,
        MSG_ID_MMI_MMS_GET_DEINIT_SERVICE_ASM_REQ,
        (oslParaType*) req,
        NULL);

    return;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_deinit_asm_pool_for_service_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  rsp     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_deinit_asm_pool_for_service_rsp(void *rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_mms_get_deinit_asm_pool_rsp_struct *rsp_data = (mmi_mms_get_deinit_asm_pool_rsp_struct*) rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (rsp_data->result == MMA_RESULT_OK)
    {
        srv_mms_mem_mgr_asm_deinit_memory(APPLIB_MEM_AP_ID_MMS_SERVICE, 0);
        applib_mem_ap_notify_stop_finished(APPLIB_MEM_AP_ID_MMS_SERVICE, MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_cancel_cb_asm_for_service
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cancel_info     [?]     
 *  pmem        [?](?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_cancel_cb_asm_for_service(void *cancel_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_MMS_SERVICE);
    srv_mms_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_ASM_CANCEL);
    srv_mms_mem_mgr_send_rsp_for_asm_pool_ptr(MMI_FALSE);
    mmi_frm_cb_emit_event((mmi_event_struct*) & evt);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_get_asm_pool_for_service_req_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inreq       [?]     [?]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_mms_mem_mgr_get_asm_pool_for_service_req_hdlr(void *inreq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = NULL;
    MMI_UMMS_ERROR ret_val = MMI_UMMS_TRUE;
    mmi_mms_get_asm_pool_req_struct *req = (mmi_mms_get_asm_pool_req_struct*) inreq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_init_asm_for_service();
    asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_MMS_SERVICE);
    ASSERT(asm_cntx);
    g_asm_req_id = req->req_id;
    /* Register API */
    asm_cntx->app_pool_size = MMA_ASM_MEM_POOL_SIZE;
	if(!asm_cntx->app_id)
	{
		srv_mms_mem_mgr_register_app(APPLIB_MEM_AP_ID_MMS_SERVICE, 0);
		/* Call For Pool ptr also */
		asm_cntx->ptr_asm_pool = applib_mem_ap_alloc(asm_cntx->app_asm_id, asm_cntx->app_pool_size);
	}
	else
	{
		asm_cntx->ptr_asm_pool = mmi_frm_asm_alloc_r(asm_cntx->app_id, asm_cntx->app_pool_size);
		MMI_ASSERT(asm_cntx->ptr_asm_pool);
	}
    if (ret_val == MMI_UMMS_TRUE)
    {
        srv_mms_mem_mgr_send_rsp_for_asm_pool_ptr(MMI_TRUE);
    #ifdef __ASM_UNIT_TEST__
        /* For testing ASM */
        srv_mms_mem_mgr_check_asm_total_pool(srv_mms_mem_mgr_success_cb_asm_for_service);
        return;
        /* For testing ASM */
    #endif /* __ASM_UNIT_TEST__ */ 
    }

	return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_send_rsp_for_asm_pool_ptr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  success_alloc       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_mms_mem_mgr_send_rsp_for_asm_pool_ptr(MMI_BOOL success_alloc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_get_asm_pool(APPLIB_MEM_AP_ID_MMS_SERVICE);

    /* MYQUEUE Message; */
    mmi_mms_get_asm_pool_rsp_struct *asm_alloc_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asm_alloc_rsp = (mmi_mms_get_asm_pool_rsp_struct*) OslConstructDataPtr(sizeof(mmi_mms_get_asm_pool_rsp_struct));
    asm_alloc_rsp->asm_pool_ptr = asm_cntx->ptr_asm_pool;
    asm_alloc_rsp->result = success_alloc;
    asm_alloc_rsp->req_id = g_asm_req_id;
    /*
     * Message.oslSrcId = MOD_MMI;
     * Message.oslDestId = MOD_MMS;
     * Message.oslMsgId = MSG_ID_MMI_MMS_GET_ASM_MEM_PTR_RSP;
     * Message.oslDataPtr = (oslParaType*) asm_alloc_rsp;
     * Message.oslPeerBuffPtr = NULL;
     * OslMsgSendExtQueue(&Message);
     */
    mmi_frm_send_ilm(MOD_MMS, MSG_ID_MMI_MMS_GET_ASM_MEM_PTR_RSP, (oslParaType*) asm_alloc_rsp, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_free_asm_pool_for_service_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inreq       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_free_asm_pool_for_service_req(void *inreq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	g_asm_req_id = 0;
    srv_mms_mem_mgr_asm_deinit_memory(APPLIB_MEM_AP_ID_MMS_SERVICE, 0);
    srv_mms_send_events_ex(EVT_ID_SRV_MMS_SERVICE_MEM_FREE_DONE, NULL);
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mms_check_asm_memory_is_int
 * DESCRIPTION
 *  
 * PARAMETERS
 *  inreq       [?]     
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_mms_check_asm_memory_is_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	return (MMI_BOOL)g_asm_req_id;
}
#endif /* __MMI_MMS_USE_ASM__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_mms_get_viewer_asm_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
U32 srv_mms_get_viewer_asm_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 result = SRV_MMS_VIEWER_ASM_MEM_POOL_SIZE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#ifdef __MMI_MMS_USE_ASM__
	result += MMA_ASM_MEM_POOL_SIZE ;
    #endif
    return result ;
}


/*****************************************************************************
 * FUNCTION
 *  srv_mms_mem_mgr_copy_pools
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 *  asm_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mms_mem_mgr_copy_pools(U32 index, U16 asm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx = srv_mms_mem_mgr_asm_get_pool_int(asm_id, index);
    srv_mms_mem_mgr_get_asm_alloc_struct *asm_cntx1 = srv_mms_mem_mgr_get_asm_pool(asm_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (asm_cntx1 == NULL)
    {
        asm_cntx1 = srv_mms_mem_mgr_get_free_asm_pool(asm_id);
    }
    memcpy(asm_cntx1, asm_cntx, sizeof(srv_mms_mem_mgr_get_asm_alloc_struct));
}
#endif /* defined (__MMI_MMS_2__) */ 

