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
*    vmwps.c
*
* Project:
* --------
*    MAUI
*
* Description:
* ------------
*    Adaptation for http/https services
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "mmi_features.h"
#include "vmswitch.h"

#if defined(__MRE_SAL_WPS__)

#include "mmi_include.h"
#include "stdio.h"
#include "kal_release.h"        /* Basic data type */

#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */
#include "app_buff_alloc.h"

#include "syscomp_config.h"
#include "task_config.h"        /* Task creation */
#include "custom_config.h"

#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h" /* Event scheduler */
#include "stack_timer.h"        /* Stack timer */
#include "fat_fs.h"

#include "wps_sap.h"
#include "wps_struct.h"
#include "vmhttps.h"
#include "vmpromng.h"
#include "vmmod.h"
#include "vmresmng.h"
#include "vmlog.h"
#include "vmwps.h"
#include "kal_public_api.h"
#include "vmsock.h"

/*macro to support global context information*/
#define MRE_WPS_CNXT_INUSE	1
#define MRE_WPS_MAX_AGENT_CONTEXT 4			/*Max. instance of WPS at any time*/
#define MRE_WPS_MAX_REQ_PER_CHANNEL 4		/*MAx. number of channel*/


/* state*/
typedef enum
{
    MRE_WPS_STATE_NULL = 1,
    MRE_WPS_STATE_QUERY_REQ_SENT,
    MRE_WPS_STATE_SET_CHANNEL_SENT,
    MRE_WPS_STATE_UNSET_CHANNEL_SENT,
    MRE_WPS_RELEASE_ALL_REQ_SENT
}mre_wps_cntxt_state_enum;

/*
* Contains information of particular application context.
*/
typedef struct
{
    kal_int32  handle;      /* APP handle */
    kal_uint8  src_app_id;	/*source application id*/						
    kal_uint8  state;		/*state variable*/
    kal_uint8  inuse;		/*is context is being used*/
    kal_int8   channel_id;	/*channel id*/
    kal_uint16 req_id[MRE_WPS_MAX_REQ_PER_CHANNEL];	/*request per channel sent by src application*/
    kal_uint16 wps_req_id[MRE_WPS_MAX_AGENT_CONTEXT];	/*internal request id mapped to src. app. request id*/
    mre_wps_send_set_channel_rsp_cb set_channel_rsp_cb;
    mre_wps_unset_channel_rsp_cb unset_channel_cb;
    mre_wps_send_release_all_req_rsp_cb release_all_req_cb;
    mre_wps_send_wps_termination_ind_cb terminal_ind_cb;
    mre_wps_send_http_rsp_cb http_rsp_cb;
    mre_wps_send_read_content_rsp_cb read_content_rsp_cb;
    mre_wps_send_cancel_rsp_cb cancel_rsp_cb;
    mre_wps_send_status_query_rsp_cb status_query_rsp_cb;
    mre_wps_post_ind_cb post_ind_cb;
    kal_uint32 account_id;
    kal_uint8  app_id;
	//abm hold
    VMINT res_id;
}mre_wps_cntxt_struct;

/*Global context of MMI WPS Agent contains info about all channels*/
static mre_wps_cntxt_struct g_mre_wps_cntxt[MRE_WPS_MAX_AGENT_CONTEXT];

#define MRE_WPS_CONTEXT_SRC_APP_ID(x)       g_mre_wps_cntxt[x].src_app_id
#define MRE_WPS_CONTEXT_HANDLE(x)           g_mre_wps_cntxt[x].handle
#define MRE_WPS_CONTEXT_STATE_VALUE(x)		g_mre_wps_cntxt[x].state
#define MRE_WPS_CONTEXT_INUSE_VALUE(x)		g_mre_wps_cntxt[x].inuse
#define MRE_WPS_CONTEXT_CHANNEL_VALUE(x)    g_mre_wps_cntxt[x].channel_id

#define MRE_WPS_CONTEXT_EXT_REQ_VALUE(x, y)    g_mre_wps_cntxt(x).wps_req_id[y]

extern VMINT vm_get_app_id(VMINT apn, VMUINT8 *app_id);

/*global variable to assign unique value to each external request id */
static kal_uint32 wps_request_id = 0;

#define STATIC_FUNC_LIST
static void mre_wps_clear_channel_info( kal_int8 index, kal_uint8 channel_id);
static void mre_wps_clear_cntxt_info(kal_int8 index);
static void mre_wps_status_query_rsp_hdlr(void *msg);
static MMI_BOOL mre_wps_set_channel_rsp_hdlr(void *msg);
static MMI_BOOL mre_wps_termination_ind_hdlr(void);
static MMI_BOOL mre_wps_unset_channel_rsp_hdlr(void *msg);
static MMI_BOOL mre_wps_http_rsp_hdlr( void *msg, kal_uint8 src_id, void *ilm_p);

static MMI_BOOL mre_wps_read_content_rsp_hdlr(void *msg, kal_uint8 src_id,  void *ilm_p);
static MMI_BOOL mre_wps_cancel_rsp_hdlr(void *msg);
static MMI_BOOL vm_wps_post_rsp_hdlr(void *msg);
static void mre_wps_ready_ind_hdlr(kal_uint8 status);
static void mre_wps_send_ilm( void *local_para_ptr, void *peer_buff_ptr,
                             msg_type ilm_id, module_type dst_id);


#define WPS_FUNCTIONS

static void vm_wps_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{
    VMINT resHandle = 0, bufSize = 0, j;
    mre_wps_cntxt_struct* wps_context = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 3, __LINE__);

    switch (sys_state)
    {
        case VM_PMNG_UNLOAD:
        {
            resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_WPS_HANDLE);
            if (VM_RES_NOT_FIND == resHandle)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 3, __LINE__);
                break;
            }
            
            do
            {
                if (vm_res_get_data(VM_RES_TYPE_WPS_HANDLE, 
                    resHandle, (void**)&wps_context, &bufSize) == 0 && wps_context != NULL)
                {                    
                    /* Cancel all request id  to -1 */
                    if (MRE_WPS_CNXT_INUSE  == wps_context->inuse)
                    {
                        for(j =0; j< MRE_WPS_MAX_REQ_PER_CHANNEL; j++)
                        {
                            if (wps_context->wps_req_id[j] != 0xffff)
                            {
                                mre_wps_send_cancel_req(wps_context->req_id[j]);

                                wps_context->req_id[j]		= 0xffff;
                                wps_context->wps_req_id[j]	= 0xffff;                        
                            }
                        }

                        mre_wps_send_unset_channel_req(wps_context->channel_id);

                        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
                            wps_context->handle,
                            wps_context->channel_id,
                            wps_context->inuse,
                            wps_context->state,
                            wps_context->src_app_id,
                            wps_context->account_id,
                            3, __LINE__);
                            
                        wps_context->channel_id = 0xff; 
                        wps_context->src_app_id = 0xff; 
                        wps_context->inuse = 0; 
                        wps_context->state = 0;
                        wps_context->handle = 0;
                        wps_context->set_channel_rsp_cb = 0;
                        wps_context->unset_channel_cb = 0;
                        wps_context->release_all_req_cb = 0;
                        wps_context->terminal_ind_cb = 0;
                        wps_context->http_rsp_cb = 0;
                        wps_context->read_content_rsp_cb = 0;
                        wps_context->cancel_rsp_cb = 0;
                        wps_context->status_query_rsp_cb = 0;
                        wps_context->post_ind_cb = 0;
                        wps_context->account_id = 0;
                        wps_context->app_id = 0;
	//abm hold
                        wps_context->res_id = -1;
                    }
                    
                }
                else
                {
                    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 3, __LINE__);
                }
                vm_res_release_data(VM_RES_TYPE_WPS_HANDLE, resHandle);
            }
            while (VM_RES_NOT_FIND != 
                (resHandle = vm_res_findnext(process_handle, VM_RES_TYPE_WPS_HANDLE)));
            
            vm_res_findclose(VM_RES_TYPE_WPS_HANDLE); 
        }
        break;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 3, __LINE__);
    
}


static VMINT initialize_wps_resource(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 1, __LINE__);
    if (vm_res_type_set_notify_callback(VM_RES_TYPE_WPS_HANDLE, 
        vm_wps_notify_process_status) != 0)
    {
        return -1;
    }

    ///TODO: other init.
    mre_wps_init_wps_agent_app();

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 1, __LINE__);
    return 0;
}

static VMINT finialize_wps_resource(void)
{
    VMINT resHandle = 0, bufSize = 0, j;
    mre_wps_cntxt_struct* wps_context = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 2, __LINE__);
    
    if (VM_RES_NOT_FIND == 
        (resHandle = vm_res_findfirst(-1, VM_RES_TYPE_WPS_HANDLE)))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 2, __LINE__);
        return 0;
    }

    do
    {
        if (vm_res_get_data(VM_RES_TYPE_WPS_HANDLE, 
            resHandle, (void**)&wps_context, &bufSize) == 0 && wps_context != NULL)
        {
            /* Cancel all request id  to -1 */
            if (wps_context->inuse == MRE_WPS_CNXT_INUSE)
            {
                for(j =0; j< MRE_WPS_MAX_REQ_PER_CHANNEL; j++)
                {
                    if (wps_context->wps_req_id[j] != 0xffff)
                    {
                        mre_wps_send_cancel_req(wps_context->req_id[j]);

                        wps_context->req_id[j]		= 0xffff;
                        wps_context->wps_req_id[j]	= 0xffff;                        
                    }
                }
                mre_wps_send_unset_channel_req(wps_context->channel_id);

                MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
                    wps_context->handle,
                    wps_context->channel_id,
                    wps_context->inuse,
                    wps_context->state,
                    wps_context->src_app_id,
                    wps_context->account_id,
                    2, __LINE__);

                wps_context->channel_id = 0xff; 
                wps_context->src_app_id = 0xff; 
                wps_context->inuse = 0; 
                wps_context->state = 0;  
                wps_context->handle = 0;
                wps_context->set_channel_rsp_cb = 0;
                wps_context->unset_channel_cb = 0;
                wps_context->release_all_req_cb = 0;
                wps_context->terminal_ind_cb = 0;
                wps_context->http_rsp_cb = 0;
                wps_context->read_content_rsp_cb = 0;
                wps_context->cancel_rsp_cb = 0;
                wps_context->status_query_rsp_cb = 0;
                wps_context->post_ind_cb = 0;
                wps_context->account_id = 0;
                wps_context->app_id = 0;
	//abm hold
                wps_context->res_id = -1;
            }
        }
        else
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 2, __LINE__);
        }
        vm_res_release_data(VM_RES_TYPE_WPS_HANDLE, resHandle);
    }
    while (VM_RES_NOT_FIND != 
        (resHandle = vm_res_findfirst(-1, VM_RES_TYPE_WPS_HANDLE)));

    vm_res_findclose(VM_RES_TYPE_WPS_HANDLE);
    
    vm_res_type_set_notify_callback(VM_RES_TYPE_WPS_HANDLE, NULL);
    

    ///TODO: Deregister WPS relate functions

    mre_wps_deinit_wps_agent_app();

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 2, __LINE__);
    return 0;
}

static VMINT wps_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (initialize_wps_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        finialize_wps_resource();
        break;
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    default:
        vm_log_error("[WPS MODULE]Receive unkown[%d] event.", event);
        return -2;
    }

    return 0;
}

VMINT _vm_reg_wps_module(void)
{
    int res_code = REG_MRE_MODULE_SUCCESS;
    
    if ((res_code = _vm_reg_module("WPS MODULE", (MOD_EVT_PROCESS)wps_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        vm_log_error("[WPS MODULE]Failed to regisiter wps module. Error Code : %d", res_code);
    }

    return res_code;
}


static mre_wps_cntxt_struct* vm_get_wps_context(VMINT channel_id)
{
    VMINT resHandle = 0, bufSize = 0;
    mre_wps_cntxt_struct* wps_context = NULL;
    
    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_WPS_HANDLE)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_WPS_HANDLE, 
            resHandle, (void**)&wps_context, &bufSize) == 0 && wps_context != NULL)
        {
            if (wps_context->channel_id  == channel_id)
            {
                vm_res_findclose(VM_RES_TYPE_WPS_HANDLE);
                return wps_context;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_WPS_HANDLE)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_WPS_HANDLE, 
                resHandle, (void**)&wps_context, &bufSize) == 0 && wps_context != NULL)
            {
                if (wps_context->channel_id == channel_id)
                {
                    vm_res_findclose(VM_RES_TYPE_WPS_HANDLE);
                    return wps_context;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_WPS_HANDLE);
    }   
    return NULL;
}
        

/*****************************************************************************
* FUNCTION
*  mre_wps_init_wps_agent_app
* DESCRIPTION
*  this function is to initialize the MMI WPS agent global context
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
void mre_wps_init_wps_agent_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i,j;
    mre_wps_cntxt_struct * ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Initialize the global context */
    for(i =0; i< MRE_WPS_MAX_AGENT_CONTEXT; i++)
    {
        ptr = &g_mre_wps_cntxt[i];
        ptr->inuse = 0;
        ptr->channel_id = 0xff;
        ptr->src_app_id = 0xff;
        ptr->state = 0;
        ptr->handle           = 0;
        ptr->app_id           = 0;
        ptr->account_id       = 0;

        /* reset all request id's to -1 */
        for(j =0; j< MRE_WPS_MAX_REQ_PER_CHANNEL; j++)
        {
            ptr->req_id[j]     = 0xffff;
            ptr->wps_req_id[j] = 0xffff;
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mre_wps_deinit_wps_agent_app
* DESCRIPTION
*  this function is to de-initialize the MMI WPS agent global context
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
void mre_wps_deinit_wps_agent_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for(i =0; i< MRE_WPS_MAX_AGENT_CONTEXT; i++)
    {
        /* Is context being used */
        if( MRE_WPS_CONTEXT_INUSE_VALUE(i))
        {
            /*clear channel info and the request info*/
            mre_wps_clear_channel_info( i, MRE_WPS_CONTEXT_CHANNEL_VALUE(i));
            /*clear wps context which are being used*/
            mre_wps_clear_cntxt_info(i);
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mre_wps_find_free_cntxt_slot
* DESCRIPTION
*  this function is to find available wps context slot
* CALLS
*  
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
static kal_int8 mre_wps_find_free_cntxt_slot(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*traverse the global list and hunt for available slot*/
    for(i =0; i< MRE_WPS_MAX_AGENT_CONTEXT; i++)
    {
        /*is this context free*/
        if( MRE_WPS_CONTEXT_INUSE_VALUE(i) == 0 )
        {
            return i;
        }
    }
    return -1;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_find_free_req_slot
* DESCRIPTION
*  this function is intend for process the outside message.
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
static kal_int8 mre_wps_find_free_req_slot(kal_int8 cntxt_idx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int j;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*is the context idx valid*/
    if( cntxt_idx >= MRE_WPS_MAX_AGENT_CONTEXT )
        return -1;
    ptr = &g_mre_wps_cntxt[cntxt_idx];
    /*check any free request slot*/
    for(j =0; j< MRE_WPS_MAX_REQ_PER_CHANNEL; j++)
    {
        if( ptr->req_id[j] == 0xffff )
        {
            return j;
        }
    }
    return -1;
}


/*****************************************************************************
* FUNCTION
*  mre_wps_find_cntxt_by_app_id
* DESCRIPTION
*  this function is to search the context based on src app id
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
static kal_int8 mre_wps_find_cntxt_by_handle(kal_int32 handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Find wps context based on app handle, search through the entire array */
    for(i =0; i< MRE_WPS_MAX_AGENT_CONTEXT; i++)
    {
        if( g_mre_wps_cntxt[i].handle == handle )
        {
            return i;
        }
    }
    return -1;
}



/*****************************************************************************
* FUNCTION
*  mre_wps_find_cntxt_by_app_id
* DESCRIPTION
*  this function is to search the context based on src app id
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
static kal_int8 mre_wps_find_cntxt_by_app_id(kal_uint8 src_app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Find wps context based on src app id, search through the entire array */
    for(i =0; i< MRE_WPS_MAX_AGENT_CONTEXT; i++)
    {
        if( MRE_WPS_CONTEXT_SRC_APP_ID(i) == src_app_id )
        {
            return i;
        }
    }
    return -1;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_search_cntxt_by_channel
* DESCRIPTION
*  this function is to search the context based on channel id
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
static kal_int8 mre_wps_search_cntxt_by_channel (kal_uint8 channel_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Find wps context based on channel id */
    for(i =0; i< MRE_WPS_MAX_AGENT_CONTEXT; i++)
    {
        if( MRE_WPS_CONTEXT_CHANNEL_VALUE(i) == channel_id)
        {
            return i;
        }
    }
    return -1;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_search_req_id
* DESCRIPTION
*  this function is to search the context based on application request id
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
static kal_int16 mre_wps_search_req_id( kal_int8 ctxt_idx, kal_uint16 req_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Find wps context based on channel id */
    ptr = &g_mre_wps_cntxt[ctxt_idx];
    for(i =0; i< MRE_WPS_MAX_REQ_PER_CHANNEL; i++)
    {
        if( (ptr->req_id[i] == req_id))
        {
            return i;
        }
    }
    return -1;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_search_ext_req_id_by_req_id
* DESCRIPTION
*  this function is to search the context based on application request id
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
static kal_int16 mre_wps_search_ext_req_id_by_req_id( kal_int8 index, kal_uint16 req_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Find wps context based on channel id */
    
    ptr = &g_mre_wps_cntxt[index];
    for(i =0; i< MRE_WPS_MAX_REQ_PER_CHANNEL; i++)
    {
        if( (ptr->req_id[i] == req_id))
        {
            return ptr->wps_req_id[i];
        }
    }
    return -1;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_find_external_req_id
* DESCRIPTION
*  this function is to search the context based on external request id
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
static kal_int8 mre_wps_find_external_req_id( kal_uint16 wps_req_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i,j;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*Find wps context based on channel id */
    for(i =0; i< MRE_WPS_MAX_AGENT_CONTEXT; i++)
    {
        ptr = &g_mre_wps_cntxt[i];
        /*Find wps context based on channel id */
        for(j =0; j< MRE_WPS_MAX_REQ_PER_CHANNEL; j++)
        {
            if( (ptr->wps_req_id[j] == wps_req_id))
            {
                return i;
            }
        }
    }	
    return -1;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_find_req_id_ext_req_id
* DESCRIPTION
*  this function is to search the context based on external request id
* CALLS
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
static kal_int16 mre_wps_find_req_id_ext_req_id( kal_int8 index, kal_uint16 wps_req_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int j;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( index < 0 && index >=MRE_WPS_MAX_AGENT_CONTEXT )
        return -1;

    ptr = &g_mre_wps_cntxt[index];
    /*Find wps context based on channel id */
    for(j =0; j< MRE_WPS_MAX_REQ_PER_CHANNEL; j++)
    {
        if( (ptr->wps_req_id[j] == wps_req_id))
        {
            return ptr->req_id[j];
        }
    }
    return -1;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_clear_cntxt_info
* DESCRIPTION
*  this function is clear global context info
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
static void mre_wps_clear_cntxt_info(kal_int8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( index < 0 && index >=MRE_WPS_MAX_AGENT_CONTEXT )
        return;
    
    ptr = &g_mre_wps_cntxt[index];
    kal_mem_set(ptr, 0, sizeof(mre_wps_cntxt_struct));
    ptr->channel_id = 0xff;
    ptr->src_app_id = 0xff;

}

/*****************************************************************************
* FUNCTION
*  mre_wps_clear_channel_info
* DESCRIPTION
*  this function is to clear channel information
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
static void mre_wps_clear_channel_info( kal_int8 index, kal_uint8 channel_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if( index < 0 && index >=MRE_WPS_MAX_AGENT_CONTEXT )
        return;
    ptr = &g_mre_wps_cntxt[index];
    /*Find wps context based on channel id */
    //MRE_WPS_CONTEXT_CHANNEL_VALUE(index) = 0xff;
    ptr->channel_id = 0xff;

    for(i =0; i< MRE_WPS_MAX_REQ_PER_CHANNEL; i++)
    {
        if( ptr->req_id[i] != 0xffff)
        {
            ptr->req_id[i]		= 0xffff;
            ptr->wps_req_id[i]	= 0xffff;
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mre_wps_clear_req_info
* DESCRIPTION
*  this function is clear request information
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
static void mre_wps_clear_req_info( kal_uint16 cntxt_id, kal_uint16 wps_req_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( cntxt_id >=MRE_WPS_MAX_AGENT_CONTEXT )
        return;

    ptr = &g_mre_wps_cntxt[cntxt_id];
    for(i =0; i< MRE_WPS_MAX_REQ_PER_CHANNEL; i++)
    {
        if( ptr->wps_req_id[i] == wps_req_id)
        {
            ptr->req_id[i] = 0xffff;
            ptr->wps_req_id[i] = 0xffff;
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mre_wps_send_ilm
* DESCRIPTION
*  This function is used to send ILM to WPS task
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static void mre_wps_send_ilm( void *local_para_ptr, void *peer_buff_ptr,
                             msg_type ilm_id, module_type dst_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = (local_para_struct*) local_para_ptr;
    ilm_ptr->msg_id = ilm_id;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

    ilm_ptr->src_mod_id  = MOD_MMI;
    ilm_ptr->dest_mod_id = dst_id;
    ilm_ptr->sap_id = WPS_APP_SAP;
    msg_send_ext_queue(ilm_ptr);
}

extern VMINT mre_wps_reg_post_content(mre_wps_post_ind_cb cb)
{
    kal_int8 index = 0;
    
    mre_wps_cntxt_struct * ptr;
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 16, __LINE__);
    index = mre_wps_find_cntxt_by_handle(vm_pmng_get_current_handle());
    
    if(index < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 16, __LINE__);
        return MRE_WPS_ERROR_CNTXT_NOT_REGISTERED;
    }

    
    ptr = &g_mre_wps_cntxt[index];

    ptr->post_ind_cb = cb;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        ptr->handle,
        ptr->post_ind_cb,
        ptr->app_id,
        ptr->account_id,
        index,
        0,
        16, __LINE__);
    
    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_POST_CONTENT_IND, (PsIntFuncPtr)vm_wps_post_rsp_hdlr, MMI_TRUE);

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 16, __LINE__);

    return MRE_WPS_OK;

}

/*****************************************************************************
* FUNCTION
*  mre_wps_register_wps_cntxt_and_callback
* DESCRIPTION
*  this function is to register callback function
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
kal_uint8 mre_wps_register_wps_cntxt_and_callback(kal_int32 apn,
                                                  mre_wps_send_set_channel_rsp_cb set_channel_rsp_cb,
                                                  mre_wps_unset_channel_rsp_cb unset_channel_cb,
                                                  mre_wps_send_release_all_req_rsp_cb release_all_req_cb,
                                                  mre_wps_send_wps_termination_ind_cb terminal_ind_cb,
                                                  mre_wps_send_http_rsp_cb http_rsp_cb,
                                                  mre_wps_send_read_content_rsp_cb read_content_rsp_cb,
                                                  mre_wps_send_cancel_rsp_cb cancel_rsp_cb,
                                                  mre_wps_send_status_query_rsp_cb status_query_rsp_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 index;
    VMINT res_id = -1;
    VMINT is_new = 0;
    
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 4, __LINE__);
    index = mre_wps_find_cntxt_by_handle(vm_pmng_get_current_handle());
    
    MMI_PRINT(MOD_MRE, MMI_MRE_TRC_G4_SOC, "[https] reg cur handle[0x%x] hdl[%d]", 
        vm_pmng_get_current_handle(), g_mre_wps_cntxt[0].handle);
    
    if(index < 0)
    {
        /* Find free wps context slot*/
        index = mre_wps_find_free_cntxt_slot();

        if(index < 0)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 4, __LINE__);
            return MRE_WPS_ERROR_NO_CNTXT_AVAILABLE;
        }
        res_id = vm_res_save_data(
            VM_RES_TYPE_WPS_HANDLE, 
            (void*)&(g_mre_wps_cntxt[index]), 
            sizeof(mre_wps_cntxt_struct), 
            NULL, 
            vm_pmng_get_current_handle());

        if (res_id < 0)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 4, __LINE__);
            return MRE_WPS_ERROR_NO_RESOURCE;
        }


        MRE_WPS_CONTEXT_INUSE_VALUE(index) = MRE_WPS_CNXT_INUSE;

        g_mre_wps_cntxt[index].handle = vm_pmng_get_current_handle();

        is_new = 1;
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E3, 4, __LINE__);
    }
    
    if (VM_E_SOC_SUCCESS != vm_get_encoded_dtacct_id(apn, &(g_mre_wps_cntxt[index].account_id)))
    {
        if (is_new)
        {
            vm_res_release_data(VM_RES_TYPE_WPS_HANDLE, res_id);
        }
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E4, 4, __LINE__);
        return MRE_WPS_ERROR_INVALID_PARAM;
    }

    if (VM_E_SOC_SUCCESS != vm_get_app_id(apn, &(g_mre_wps_cntxt[index].app_id)))
    {
        if (is_new)
        {
            vm_res_release_data(VM_RES_TYPE_WPS_HANDLE, res_id);
        }
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E5, 4, __LINE__);
        return MRE_WPS_ERROR_INVALID_PARAM;
    }
    
    MRE_WPS_CONTEXT_SRC_APP_ID(index) = g_mre_wps_cntxt[index].app_id;

    ptr = &g_mre_wps_cntxt[index];

	//abm hold
    ptr->res_id = res_id;

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        ptr->handle,
        apn,
        ptr->app_id,
        ptr->account_id,
        res_id,
        index,
        4, __LINE__);

    /*callback function pointer*/
    ptr->set_channel_rsp_cb		= set_channel_rsp_cb;
    ptr->unset_channel_cb			= unset_channel_cb;
    ptr->release_all_req_cb		= release_all_req_cb;
    ptr->terminal_ind_cb			= terminal_ind_cb;
    ptr->http_rsp_cb				= http_rsp_cb;
    ptr->read_content_rsp_cb		= read_content_rsp_cb;
    ptr->cancel_rsp_cb			= cancel_rsp_cb;
    ptr->status_query_rsp_cb		= status_query_rsp_cb;
    ptr->post_ind_cb		= 0;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 4, __LINE__);
    return MRE_WPS_OK;
}


/*****************************************************************************
* FUNCTION
*  mre_wps_send_set_channel_req
* DESCRIPTION
*  this function is  to send set channel request information to WPS
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
kal_uint8 mre_wps_send_set_channel_req(kal_bool use_default, kal_uint8 conn_type,
                                       kal_uint32 req_id, 
                                       kal_uint32 timeout, kal_bool use_proxy,
                                       kal_uint8 prx_ip[4], kal_uint16 prx_port,
                                       kal_uint8 *username, kal_uint8 username_len,
                                       kal_uint8 *password, kal_uint8 password_len,
                                       kal_uint8 *server_auth_username,
                                       kal_uint8 server_auth_username_len,
                                       kal_uint8 *server_auth_password,   
                                       kal_uint8 server_auth_password_len,
                                       kal_uint32 static_header_len,
                                       kal_uint8* static_header )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_set_channel_req_struct *set_channel_req = NULL;
    wps_set_channel_req_var_struct set_channel_req_var = {0};
    kal_uint16 pdu_length = 0;
    peer_buff_struct * peer_buff_ptr = NULL;
    kal_int8 index;
    kal_int8 req_slot;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*find wps context created by src application*/
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 5, __LINE__);
    index = mre_wps_find_cntxt_by_handle(vm_pmng_get_current_handle());
    if(index < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 5, __LINE__);
        return MRE_WPS_ERROR_CNTXT_NOT_REGISTERED;
    }
    if (MRE_WPS_STATE_SET_CHANNEL_SENT == MRE_WPS_CONTEXT_STATE_VALUE(index))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 5, __LINE__);
        return MRE_WPS_ERROR_INACTIVE_CHANNEL;
    }
    /*check channel id matching with the app. chanel id*/
    if(g_mre_wps_cntxt[index].channel_id != (kal_int8)0xff)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E3, 5, __LINE__);
        return MRE_WPS_ERROR_NO_RESOURCE;
    }
    req_slot = mre_wps_find_free_req_slot(index);
    if(req_slot < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E4, 5, __LINE__);
        return MRE_WPS_ERROR_NO_RESOURCE;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        index,
        MRE_WPS_CONTEXT_STATE_VALUE(index),
        req_slot,
        use_proxy,
        req_id,
        0,
        50, __LINE__);
        
    set_channel_req = (wps_set_channel_req_struct*)
        construct_local_para(sizeof(wps_set_channel_req_struct),
        TD_CTRL | TD_RESET);

    set_channel_req->use_default = use_default;
    set_channel_req->app_id = g_mre_wps_cntxt[index].app_id;
    set_channel_req->conn_type = conn_type;
    set_channel_req->req_id = ++wps_request_id;
    set_channel_req->net_id = g_mre_wps_cntxt[index].account_id;
    set_channel_req->timeout = timeout;
    set_channel_req->use_proxy = use_proxy;

    if (prx_ip != NULL)
    {
        kal_uint8 * px_addr;
        VMINT i = 0, j = 0;
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #else
        px_addr = set_channel_req->prx_addr;
        for (i=0; i<4; i++)
        {
            if (prx_ip[i] >= 100)
            {
                px_addr[j] = 0x30 + prx_ip[i]/100;
                j++;
                px_addr[j] = 0x30 + prx_ip[i]%100/10;
                j++;
                px_addr[j] = 0x30 + prx_ip[i]%100%10;
            }
            else if (prx_ip[i] >= 10)
            {
                px_addr[j] = 0x30 + prx_ip[i]%100/10;
                j++;
                px_addr[j] = 0x30 + prx_ip[i]%100%10;
            }
            else
            {
                px_addr[j] = 0x30 + prx_ip[i];
            }
            j++;
            if (i < 3)
            {
                px_addr[j] = '.';
                j++;
            }
            else
            {
                px_addr[j] = '\0';
            }

        }
        /*
        for (i=0; i<4; i++)
        {
            set_channel_req->prx_addr[j] = 0x30 + prx_ip[i]/100;
            if (set_channel_req->prx_addr[j] != 0x30)
            {
                j++;
                set_channel_req->prx_addr[j] = 0x30 + (prx_ip[i]%100)/10;
                j++;
                set_channel_req->prx_addr[j] = 0x30 + prx_ip[i]%10;
            }
            else
            {
                set_channel_req->prx_addr[j] = 0x30 + prx_ip[i]/10;
                if (set_channel_req->prx_addr[j] != 0x30)
                {
                    j++;
                }
                set_channel_req->prx_addr[j] = 0x30 + prx_ip[i]%10;
            }
            j++;
            if (i < 3)
            {
                set_channel_req->prx_addr[j] = '.';
                j++;
            }
            else
            {
                set_channel_req->prx_addr[j] = '\0';
            }
            
        }
        */
        #endif
        set_channel_req->prx_port = prx_port;
    }
    if (username)
    {
        strncpy((char*)set_channel_req->username, (char*)username, username_len);
    }
    if (password)
    {
        strncpy((char*)set_channel_req->password, (char*)password, password_len);
    }
    if (server_auth_username)
    {
        strncpy((char*)set_channel_req->server_auth_username, (char*)server_auth_username, server_auth_username_len);
    }
    if (server_auth_password)
    {
        strncpy((char*)set_channel_req->server_auth_password, (char*)server_auth_password, server_auth_password_len);
    }

    /*Process Static headers*/
    if (static_header)
    {
        set_channel_req_var.static_header_len = strlen((char*)static_header);
        if (set_channel_req_var.static_header_len > 2000)
        {
            set_channel_req_var.static_header_len = 2000;
        }
        set_channel_req_var.static_header = static_header;
        pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_SET_CHANNEL_REQ, &set_channel_req_var, NULL);
        peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);
        wps_pun_var_part(
            WPS_PUN_PACK,
            MSG_ID_WPS_SET_CHANNEL_REQ,
            &set_channel_req_var,
            get_pdu_ptr(peer_buff_ptr, &pdu_length));        
    }        

    ptr = &g_mre_wps_cntxt[index];

    //MRE_WPS_CONTEXT_STATE_VALUE(index) = MRE_WPS_STATE_SET_CHANNEL_SENT;
    ptr->state = MRE_WPS_STATE_SET_CHANNEL_SENT;
    ptr->req_id[req_slot] = req_id;
    ptr->wps_req_id[req_slot] = wps_request_id;

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        ptr->state,
        ptr->req_id[req_slot],
        ptr->wps_req_id[req_slot],
        set_channel_req->timeout,
        ptr->account_id,
        static_header,
        51, __LINE__);

    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_SET_CHANNEL_RSP, (PsIntFuncPtr)mre_wps_set_channel_rsp_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_TERMINATION_IND, (PsIntFuncPtr)mre_wps_termination_ind_hdlr, MMI_TRUE);

    mre_wps_send_ilm( set_channel_req, peer_buff_ptr, MSG_ID_WPS_SET_CHANNEL_REQ, MOD_WPS);

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 5, __LINE__);
    return MRE_WPS_OK;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_send_unset_channel_req
* DESCRIPTION
*  this function is  to send unset channel request information to WPS
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  unset_channel_req       [?]         
* RETURNS
*  void
*****************************************************************************/
kal_uint8 mre_wps_send_unset_channel_req(kal_uint8 channel_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_unset_channel_req_struct *unset_channel_req;
    kal_int8 index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*find wps context created by src application*/	
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 6, __LINE__);
    index = mre_wps_find_cntxt_by_handle(vm_pmng_get_current_handle());
    if(index < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 6, __LINE__);
        return MRE_WPS_ERROR_CNTXT_NOT_REGISTERED;
    }
    /*check channel id matching with the app. chanel id*/
    if(MRE_WPS_CONTEXT_CHANNEL_VALUE(index) != channel_id)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 6, __LINE__);
        return MRE_WPS_ERROR_INVALID_CHANNEL_ID;
    }
    unset_channel_req = (wps_unset_channel_req_struct*)
        construct_local_para(sizeof(wps_unset_channel_req_struct),
        TD_CTRL | TD_RESET);
    unset_channel_req->channel_id = channel_id;

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        index,
        unset_channel_req->channel_id,
        MRE_WPS_CONTEXT_STATE_VALUE(index),
        0,
        0,
        0, 
        5, __LINE__);
        
    /*set context state*/
    MRE_WPS_CONTEXT_STATE_VALUE(index) = MRE_WPS_STATE_UNSET_CHANNEL_SENT;

    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_UNSET_CHANNEL_RSP, (PsIntFuncPtr)mre_wps_unset_channel_rsp_hdlr, MMI_TRUE);
    mre_wps_send_ilm( unset_channel_req, NULL, MSG_ID_WPS_UNSET_CHANNEL_REQ, MOD_WPS);

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 6, __LINE__);
    return MRE_WPS_OK;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_send_http_req_ext
* DESCRIPTION
*  this function is to send a HTTP/WSP request.
* CALLS
*  
* PARAMETERS
*  src_mod_id          [IN]        
*  http_req            [?]         
*  http_req_var        [?]         
* RETURNS
*  void
*****************************************************************************/
kal_uint8 mre_wps_send_http_req_ext(kal_uint16 request_id, kal_uint8 method,      
                                kal_uint32 option, kal_uint8 reply_type,  
                                kal_uint32 reply_segment_len,
                                kal_uint32 request_url_len, 
                                kal_uint8* request_url, kal_uint32 request_header_len, 
                                kal_uint8* request_header,
                                kal_uint32 post_segment_len,
                                kal_uint8* post_segment, 
                                kal_bool more_post,
                                kal_uint8 post_type,
                                kal_uint32 num_entries,
                                vm_wps_content_t content[WPS_MAX_MULTIPART_CONTENT_NUM]
                                )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_req_struct *http_req = NULL;
    wps_http_req_var_struct http_req_var = {0};    
    kal_uint16 pdu_length = 0;
    peer_buff_struct *peer_buff_ptr = NULL;
    kal_int8 index;
    kal_int8 req_slot;
    kal_int32 param_ok = 1;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*find wps context created by src application*/	
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 7, __LINE__);
    index = mre_wps_find_cntxt_by_handle(vm_pmng_get_current_handle());
    if(index < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 7, __LINE__);
        return MRE_WPS_ERROR_CNTXT_NOT_REGISTERED;
    }
    
    ptr = &g_mre_wps_cntxt[index];
    if (MRE_WPS_CONTEXT_CHANNEL_VALUE(index) != ptr->channel_id)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 7, __LINE__);
        return MRE_WPS_ERROR_INVALID_CHANNEL_ID;
    }
    req_slot = mre_wps_find_free_req_slot(index);
    if(req_slot < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E3, 7, __LINE__);
        return MRE_WPS_ERROR_NO_RESOURCE;
    }

    http_req = (wps_http_req_struct*) construct_local_para(sizeof(wps_http_req_struct), TD_CTRL | TD_RESET);
    http_req->request_id	= ++wps_request_id;
    http_req->channel_id	= ptr->channel_id;
    http_req->method		= method;
    http_req->option		= option;
    http_req->reply_type	= reply_type;  
    http_req->post_type = post_type/*MRE_WPS_DATA_TYPE_BUFFER*/;

    /* This is the length total post data to be sent */
    http_req->post_total_len = post_segment_len;

    http_req->reply_segment_len		= reply_segment_len;
    http_req->more_post = more_post;
    http_req_var.request_url_len	= request_url_len;
    http_req_var.request_url		= (kal_uint8*)request_url;
    http_req_var.request_header_len = request_header_len;
    http_req_var.request_header		= (kal_uint8*)request_header;    
    http_req_var.post_segment = post_segment;
    if (num_entries > 0)
    {
        kal_uint32 i = 0;
        //wps_content_t * ct_tmp = http_req_var.content;
        http_req_var.num_entries = num_entries;

        for (i = 0; i < num_entries && i < WPS_MAX_MULTIPART_CONTENT_NUM; i++)
        {
            vm_wps_content_t * ct_p = &content[i];
            wps_content_t * ct_tmp = &(http_req_var.content[i]);
            if (ct_p->contentTypelen > 0)
            {
                ct_tmp->contentTypelen = (kal_uint32)ct_p->contentTypelen;
                strncpy((char *)ct_tmp->contentType, (const char *)ct_p->contentType, 
                    (ct_tmp->contentTypelen > 31) ? 31 : ct_tmp->contentTypelen);
            }
            if (ct_p->namelen > 0)
            {
                ct_tmp->namelen = (kal_uint32)ct_p->namelen;
                strncpy((char *)ct_tmp->name, (const char *)ct_p->name, 
                    (ct_tmp->namelen > 31) ? 31 : ct_tmp->namelen);
            }
            if (ct_p->fileNamelen > 0)
            {
                ct_tmp->fileNamelen = (kal_uint32)ct_p->fileNamelen;
                strncpy((char *)ct_tmp->fileName, (const char *)ct_p->fileName, 
                    (ct_tmp->fileNamelen > 31) ? 31 : ct_tmp->fileNamelen);
            }
            
            ct_tmp->charset = (kal_uint32)ct_p->charset;
            ct_tmp->dataType = (kal_uint32)ct_p->dataType;
            ct_tmp->dataLen = (kal_uint32)ct_p->dataLen;
            
            if (ct_p->filepathNamelen > 0)
            {
                // http_req_var.content[i].filepathNamelen is bytes long.
                ct_tmp->filepathNamelen = 
                    ((kal_uint32)ct_p->filepathNamelen > 31) ? 62 : 2*(kal_uint32)ct_p->filepathNamelen;
                kal_wstrncpy((WCHAR *)ct_tmp->filepathName, (const WCHAR *)ct_p->filepathName, 
                    (ct_p->filepathNamelen > 31) ? 31 : ct_p->filepathNamelen);
                if (ct_p->filepathNamelen > 31)
                {
                    param_ok = 1; // need to be set 0, wait sns
                    break;
                }
            }

        }
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        index,
        ptr->channel_id,
        method,
        option,
        reply_type,
        http_req->more_post, 
        70, __LINE__);

    if (!param_ok)
    {
        mre_wps_clear_req_info(index, req_slot);
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E4, 7, __LINE__);
        return MRE_WPS_ERROR_INVALID_PARAM;
    }
        
    /* This(post_segment_len) is the first chunk of post data. Application may not have enough 
    buffer to send all the data at once. So this variable indicated the first 
    chunk of post data.
    http_req->more_post should be true to indicate that there is more post data.

    To see how to post data in mulitple chunks, refer mre_wps_send_post_content_res

    Also each chunk must be less than 2K

    For sample app, post_total_len = post_segment_len
    */


    http_req_var.post_segment_len = post_segment_len;

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_HTTP_REQ,
        &http_req_var, NULL);

    peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);

    wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_HTTP_REQ, &http_req_var,
        get_pdu_ptr(peer_buff_ptr, &pdu_length));

    ptr->req_id[req_slot] = request_id;
    ptr->wps_req_id[req_slot] = wps_request_id;

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        index,
        ptr->req_id[req_slot],
        ptr->wps_req_id[req_slot],
        ptr->handle,
        ptr->state,
        ptr->inuse,
        71, __LINE__);

    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_HTTP_RSP, (PsIntFuncPtr)mre_wps_http_rsp_hdlr, MMI_TRUE);

    mre_wps_send_ilm( (void*)http_req, (void*)peer_buff_ptr,
        MSG_ID_WPS_HTTP_REQ, MOD_WPS);

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 7, __LINE__);
    return MRE_WPS_OK;

}

/*****************************************************************************
* FUNCTION
*  mre_wps_send_read_content_req
* DESCRIPTION
*  this function is to send request to continue to read HTTP/WSP reply content.
* CALLS
*  
* PARAMETERS
*  src_mod_id              [IN]        
*  read_content_req        [?]         
* RETURNS
*  void
*****************************************************************************/
kal_uint8 mre_wps_send_read_content_req(kal_uint16 request_id,
                                        kal_uint8 seq_num,    
                                        kal_uint32 read_segnemtn_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_req_struct *read_content_req = NULL;
    kal_int8 index;
    kal_int16 wps_req_id;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*find wps context created by src application*/	
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 8, __LINE__);
    index = mre_wps_find_cntxt_by_handle(vm_pmng_get_current_handle());
    if(index < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 8, __LINE__);
        return MRE_WPS_ERROR_CNTXT_NOT_REGISTERED;
    }
    ptr = &g_mre_wps_cntxt[index];
    if(MRE_WPS_CONTEXT_CHANNEL_VALUE(index) != ptr->channel_id)
    {        
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 8, __LINE__);
        return MRE_WPS_ERROR_INVALID_CHANNEL_ID;
    }
    if( mre_wps_search_req_id(index, request_id) < 0 )
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E3, 8, __LINE__);
        return MRE_WPS_ERROR_INVALID_REQUEST_ID;
    }
    wps_req_id = mre_wps_search_ext_req_id_by_req_id(index, request_id);
    if(wps_req_id < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E4, 8, __LINE__);
        return MRE_WPS_ERROR_INVALID_REQUEST_ID;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        index,
        ptr->channel_id,
        request_id,
        wps_req_id,
        0,
        0,
        80, __LINE__);
        
    read_content_req=(wps_read_content_req_struct*)
        construct_local_para(sizeof(wps_read_content_req_struct),
        TD_CTRL | TD_RESET);

    read_content_req->request_id = wps_req_id;
    read_content_req->channel_id = ptr->channel_id;
    read_content_req->seq_num = seq_num;
    read_content_req->read_segnemtn_len = read_segnemtn_len;

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        index,
        seq_num,
        read_segnemtn_len,
        0,
        0,
        0,
        81, __LINE__);
        
    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_READ_CONTENT_RSP, (PsIntFuncPtr)mre_wps_read_content_rsp_hdlr, MMI_TRUE);
    mre_wps_send_ilm( (void*)read_content_req, NULL,
        MSG_ID_WPS_READ_CONTENT_REQ, MOD_WPS);

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 8, __LINE__);
    return MRE_WPS_OK;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_send_post_content_res
* DESCRIPTION
*  this function is to to handle continuous content post of a HTTP request.
* CALLS
*  
* PARAMETERS
*  src_mod_id                  [IN]        
*  post_content_res            [?]         
*  post_content_res_var        [?]         
* RETURNS
*  void
*****************************************************************************/
kal_uint8 mre_wps_send_post_content_res(kal_uint16 request_id,       
                                        kal_uint8 seq_num,           
                                        kal_bool more,               
                                        kal_uint32 post_segment_len, 
                                        kal_uint8* post_segment )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_post_content_res_struct *post_content_res = NULL;
    wps_post_content_res_var_struct post_content_res_var = {0};    
    kal_uint16 pdu_length = 0;
    peer_buff_struct *peer_buff_ptr = NULL;
    kal_int8 index;
    kal_int16 wps_req_id;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*find wps context created by src application*/	
    index = mre_wps_find_cntxt_by_handle(vm_pmng_get_current_handle());
    if(index < 0)
        return MRE_WPS_ERROR_CNTXT_NOT_REGISTERED;

    ptr = &g_mre_wps_cntxt[index];

    if( mre_wps_search_req_id(index, request_id) < 0 )
        return MRE_WPS_ERROR_INVALID_REQUEST_ID;

    wps_req_id = mre_wps_search_ext_req_id_by_req_id(index, request_id);
    if(wps_req_id < 0)
    {
        return MRE_WPS_ERROR_INVALID_REQUEST_ID;
    }

    post_content_res = (wps_post_content_res_struct*)construct_local_para(
        sizeof(wps_post_content_res_struct),TD_CTRL | TD_RESET);

    post_content_res->request_id = wps_req_id;
    post_content_res->channel_id = ptr->channel_id;
    post_content_res->seq_num = seq_num;
    post_content_res->more = more;


    post_content_res_var.post_segment_len = post_segment_len;
    post_content_res_var.post_segment = post_segment;

    pdu_length = wps_pun_var_part(WPS_PUN_SIZE, MSG_ID_WPS_POST_CONTENT_RES,
        &post_content_res_var, NULL);

    peer_buff_ptr = construct_peer_buff(pdu_length, 0, 0, TD_CTRL);

    wps_pun_var_part(WPS_PUN_PACK, MSG_ID_WPS_POST_CONTENT_RES,
        &post_content_res_var, get_pdu_ptr(peer_buff_ptr,
        &pdu_length));

    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_HTTP_RSP, (PsIntFuncPtr)mre_wps_http_rsp_hdlr, MMI_TRUE);

    mre_wps_send_ilm( (void*)post_content_res, (void*)peer_buff_ptr,
        MSG_ID_WPS_POST_CONTENT_RES, MOD_WPS);

    return MRE_WPS_OK;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_send_cancel_req
* DESCRIPTION
*  this function is to send a request to cancel an incomplete WSP/HTTP request.
* CALLS
*  
* PARAMETERS
*  src_mod_id      [IN]        
*  cancel_req      [?]         
* RETURNS
*  void
*****************************************************************************/
kal_uint8 mre_wps_send_cancel_req(kal_uint16 request_id )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_cancel_req_struct *cancel_req = NULL;
    kal_int8 index;
    kal_int16 wps_req_id;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*find wps context created by src application*/	
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 9, __LINE__);
    index = mre_wps_find_cntxt_by_handle(vm_pmng_get_current_handle());
    if(index < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 9, __LINE__);
        return MRE_WPS_ERROR_CNTXT_NOT_REGISTERED;
    }
    
    ptr = &g_mre_wps_cntxt[index];
    if( mre_wps_search_req_id(index, request_id) < 0 )
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E3, 9, __LINE__);
        return MRE_WPS_ERROR_INVALID_REQUEST_ID;
    }
    wps_req_id = mre_wps_search_ext_req_id_by_req_id(index, request_id);
    if(wps_req_id < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E4, 9, __LINE__);
        return MRE_WPS_ERROR_INVALID_REQUEST_ID;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        index,
        ptr->channel_id,
        request_id, 
        wps_req_id,
        0,
        0, 
        9, __LINE__);
        
    cancel_req = (wps_cancel_req_struct*) 
        construct_local_para(sizeof(wps_cancel_req_struct),
        TD_CTRL | TD_RESET);

    cancel_req->request_id = wps_req_id;
    cancel_req->channel_id = ptr->channel_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_WPS_CANCEL_RSP, (PsIntFuncPtr)mre_wps_cancel_rsp_hdlr, MMI_TRUE);

    mre_wps_send_ilm((void*)cancel_req, NULL, MSG_ID_WPS_CANCEL_REQ, MOD_WPS);  

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 9, __LINE__);
    return MRE_WPS_OK;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_set_channel_rsp_hdlr
* DESCRIPTION
*  This function is used to
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mre_wps_set_channel_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 index;
    kal_int16 app_req_id;
    wps_set_channel_rsp_struct *channel_rsp;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    channel_rsp = (wps_set_channel_rsp_struct*) msg;
    ASSERT(channel_rsp);

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 51, __LINE__);
    
    index = mre_wps_find_external_req_id(channel_rsp->req_id);
    if(index < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 51, __LINE__);
        return MMI_FALSE;
    }
    ptr = &g_mre_wps_cntxt[index];
    app_req_id = mre_wps_find_req_id_ext_req_id(index, channel_rsp->req_id);
    if(app_req_id < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 51, __LINE__);
        return MMI_FALSE;
    }


    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        index,
        app_req_id,
        channel_rsp->req_id,
        0,
        0,
        0, 
        510, __LINE__);
        
    if( MRE_WPS_CONTEXT_STATE_VALUE(index) == MRE_WPS_STATE_SET_CHANNEL_SENT)
    {
        /*update the wps context with channel id*/
        MRE_WPS_CONTEXT_CHANNEL_VALUE(index) = channel_rsp->channel_id;

        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
            index,
            channel_rsp->channel_id,
            ptr->set_channel_rsp_cb, 
            0,
            0,
            0, 
            511, __LINE__);
            
        /*callback application handler to get set channel result*/
        if(ptr->set_channel_rsp_cb )
        {
            mre_wps_clear_req_info(index, channel_rsp->req_id);
            MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
                index, 
                channel_rsp->req_id,
                0, 
                0,
                0,
                0, 
                512, __LINE__);
            {
                VMINT phandle = ptr->handle;//vm_pmng_get_current_handle();

                if (vm_pmng_set_ctx(phandle)  == VM_PMNG_OP_OK)
                {
                    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
                        index, 
                        phandle, 
                        ptr->inuse, 
                        0,
                        0,
                        0, 
                        513, __LINE__);
                        
                    (*ptr->set_channel_rsp_cb)(app_req_id, channel_rsp->channel_id,
                        channel_rsp->result);
                    vm_pmng_reset_ctx();
                    
                    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
                        phandle, 
                        ptr->inuse,
                        0,
                        0,
                        0,
                        0, 
                        514, __LINE__);
                }
            }
        }
        else
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E3, 51, __LINE__);
            return MMI_FALSE;
        }
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E4, 51, __LINE__);
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 51, __LINE__);
    return MMI_TRUE;
}


/*****************************************************************************
* FUNCTION
*  mre_wps_unset_channel_rsp_hdlr
* DESCRIPTION
*  This function is used to
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mre_wps_unset_channel_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 index = 0;
    wps_unset_channel_rsp_struct *unset_channel_rsp;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 61, __LINE__);
    
    unset_channel_rsp = (wps_unset_channel_rsp_struct*) msg;
    ASSERT(unset_channel_rsp);
    /*search wps context based on channel id which is always unique */
    index = mre_wps_search_cntxt_by_channel(unset_channel_rsp->channel_id);

    if(index < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 61, __LINE__);
        return MMI_FALSE;
    }
    ptr = &g_mre_wps_cntxt[index];
    /*clear channel info as it has been unset at WPS end*/
    mre_wps_clear_channel_info( index, unset_channel_rsp->channel_id);

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        index,
        unset_channel_rsp->channel_id,
        unset_channel_rsp->result,
        ptr->unset_channel_cb,
        0,
        0, 
        610, __LINE__);

    /*callback application handler to get unset channel result*/
    if(ptr->unset_channel_cb)
    {
        VMINT phandle = ptr->handle;//vm_pmng_get_current_handle();

        
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
            phandle, 
            ptr->inuse,
            0,
            0,
            0,
            0,
            611, __LINE__);
            
        if (vm_pmng_set_ctx(phandle)  == VM_PMNG_OP_OK  && ptr->inuse != 0)
        {
            (*ptr->unset_channel_cb)(unset_channel_rsp->channel_id,
                unset_channel_rsp->result);
            vm_pmng_reset_ctx();
            
            MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
                phandle, 
                ptr->inuse,
                0,
                0,
                0,
                0,
                612, __LINE__);
        }

    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 61, __LINE__);
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 61, __LINE__);
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_http_rsp_hdlr
* DESCRIPTION
*  This function is used to
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mre_wps_http_rsp_hdlr( void *msg, kal_uint8 src_id, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_http_rsp_struct *http_rsp;
    wps_http_rsp_var_struct http_rsp_var = {0};
    kal_uint16 pdu_length = 0;
    kal_int8 index;
    kal_uint8 content_type_len;
    ilm_struct          *ilm_ptr;
    kal_int16 app_req_id;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    http_rsp = (wps_http_rsp_struct*) msg;
    ASSERT(http_rsp);

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 71, __LINE__);
    ilm_ptr = (ilm_struct*)ilm_p;
    /*search wps context based on channel id which is always unique */
    index = mre_wps_find_external_req_id(http_rsp->request_id);
    if(index < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 71, __LINE__);
        return MMI_FALSE;
    }
    ptr = &g_mre_wps_cntxt[index];
    app_req_id = mre_wps_find_req_id_ext_req_id(index, http_rsp->request_id);
    if(app_req_id < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 71, __LINE__);
        return MMI_FALSE;
    }
    
    if (ilm_ptr->peer_buff_ptr)
    {
        wps_pun_var_part(WPS_PUN_UNPACK, ilm_ptr->msg_id, &http_rsp_var,
            get_pdu_ptr(ilm_ptr->peer_buff_ptr, &pdu_length));
    }
    /*callback application handler to get unset channel result*/
    if(ptr->http_rsp_cb )
    {
        if(http_rsp->more == KAL_FALSE || 
            http_rsp->result)
        {
            mre_wps_clear_req_info(index, http_rsp->request_id);
        }

        content_type_len = strlen((const char *)http_rsp->content_type);


        {
            VMINT phandle = ptr->handle;//vm_pmng_get_current_handle();

            
            MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
                phandle, 
                ptr->inuse, 
                http_rsp->result,
                http_rsp->status,
                http_rsp->cause,
                http_rsp->protocol,
                710, __LINE__);
                
            if (vm_pmng_set_ctx(phandle)  == VM_PMNG_OP_OK)
            {
                (*ptr->http_rsp_cb)(  (kal_uint16)app_req_id,
                    http_rsp->result,
                    http_rsp->status,
                    http_rsp->cause,
                    http_rsp->protocol,
                    content_type_len,
                    http_rsp->content_type,
                    http_rsp->content_length,
                    http_rsp->more,
                    http_rsp_var.new_url_len,
                    http_rsp_var.new_url,
                    http_rsp_var.reply_header_len,
                    http_rsp_var.reply_header,
                    http_rsp_var.reply_segment_len,
                    http_rsp_var.reply_segment);
                vm_pmng_reset_ctx();
                
                MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
                    ptr->inuse,
                    http_rsp->content_length,
                    http_rsp->more,
                    http_rsp_var.new_url_len,
                    http_rsp_var.reply_header_len,
                    http_rsp_var.reply_segment_len,
                    711, __LINE__);
            }

        }

    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E3, 71, __LINE__);
        return MMI_FALSE;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 71, __LINE__);
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_status_query_rsp_hdlr
* DESCRIPTION
*  This function is used to
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static void mre_wps_status_query_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_status_query_rsp_struct *status_query_rsp;
    int i;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    status_query_rsp = (wps_status_query_rsp_struct*) msg;
    ASSERT(status_query_rsp);

    /*check all WPS context which wants to know query status*/
    for(i =0; i< MRE_WPS_MAX_AGENT_CONTEXT; i++)
    {
        if(MRE_WPS_CONTEXT_STATE_VALUE(i) == MRE_WPS_STATE_QUERY_REQ_SENT)
        {
            ptr = &g_mre_wps_cntxt[i];
            /*check registered callback function*/
            if(ptr->status_query_rsp_cb)
            {
                VMINT phandle = ptr->handle;//vm_pmng_get_current_handle();

                if (vm_pmng_set_ctx(phandle)  == VM_PMNG_OP_OK)
                {
                    (*ptr->status_query_rsp_cb)( status_query_rsp->status);
                    vm_pmng_reset_ctx();
                }
            }
        }
    }
}

/*****************************************************************************
* FUNCTION
*  mre_wps_ready_ind_hdlr
* DESCRIPTION
*  This function is used to
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static void mre_wps_ready_ind_hdlr(kal_uint8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*check all WPS context which wants to know query status*/
    for(i =0; i< MRE_WPS_MAX_AGENT_CONTEXT; i++)
    {
        /*check the state of WPS context*/
        if(MRE_WPS_CONTEXT_STATE_VALUE(i) == MRE_WPS_STATE_QUERY_REQ_SENT)
        {
            ptr = &g_mre_wps_cntxt[i];
            /*check registered callback function*/
            if(ptr->status_query_rsp_cb)
            {
                VMINT phandle = ptr->handle;//vm_pmng_get_current_handle();

                if (vm_pmng_set_ctx(phandle)  == VM_PMNG_OP_OK)
                {
                    (*ptr->status_query_rsp_cb)(status);
                    vm_pmng_reset_ctx();
                }
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mre_wps_termination_ind_hdlr
* DESCRIPTION
*  This function is used to
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mre_wps_termination_ind_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*check all WPS context which wants to know query status*/
    for(i =0; i< MRE_WPS_MAX_AGENT_CONTEXT; i++)
    {
        if(MRE_WPS_CONTEXT_INUSE_VALUE(i) == MRE_WPS_CNXT_INUSE)
        {
            ptr = &g_mre_wps_cntxt[i];
            /*clear channel information maintained at WPS agent*/
            mre_wps_clear_channel_info( i, MRE_WPS_CONTEXT_CHANNEL_VALUE(i));

            if(ptr->terminal_ind_cb)
            {
                //VMINT phandle = ptr->handle;//vm_pmng_get_current_handle();

                if (vm_pmng_set_ctx(ptr->handle)  == VM_PMNG_OP_OK)
                {
                    (*ptr->terminal_ind_cb)();
                    vm_pmng_reset_ctx();
                    
                    mre_wps_clear_cntxt_info(i);
                    return MMI_TRUE;
                }
            }
            /*clear context information maintained at WPS agent*/
            mre_wps_clear_cntxt_info(i);
        }
    }

    return MMI_FALSE;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_read_content_rsp_hdlr
* DESCRIPTION
*  This function is used to
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mre_wps_read_content_rsp_hdlr(void *msg, kal_uint8 src_id, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wps_read_content_rsp_struct *read_content_rsp;
    wps_read_content_rsp_var_struct read_content_rsp_var = {0};
    kal_uint16 pdu_length = 0;   
    kal_int8 index;	
    kal_int16 app_req_id;
    ilm_struct  *ilm_ptr;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 81, __LINE__);
    read_content_rsp = (wps_read_content_rsp_struct*) msg;
    ASSERT(read_content_rsp);

    ilm_ptr = (ilm_struct*)ilm_p;
    /*search wps context based on channel id which is always unique */
    index = mre_wps_find_external_req_id(read_content_rsp->request_id);
    if(index < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 81, __LINE__);
        return MMI_FALSE;
    }
    
    ptr = &g_mre_wps_cntxt[index];
    app_req_id = mre_wps_find_req_id_ext_req_id(index, read_content_rsp->request_id);
    if(app_req_id < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 81, __LINE__);
        return MMI_FALSE;
    }
    
    if (ilm_ptr->peer_buff_ptr)
    {
        wps_pun_var_part(WPS_PUN_UNPACK, ilm_ptr->msg_id,
            &read_content_rsp_var, 
            get_pdu_ptr(ilm_ptr->peer_buff_ptr, &pdu_length));
    }    

    
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        index, 
        app_req_id,
        ilm_ptr->peer_buff_ptr,
        ptr->read_content_rsp_cb,
        0,
        0,
        810, __LINE__);

    /*callback application handler to get unset channel result*/
    if(ptr->read_content_rsp_cb )
    {
        if(read_content_rsp->more == KAL_FALSE || 
            read_content_rsp->result)
        {
            mre_wps_clear_req_info(index, read_content_rsp->request_id);
        }

        {
            //VMINT phandle = ptr->handle;//vm_pmng_get_current_handle();

            MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
                ptr->handle, 
                read_content_rsp->more, 
                read_content_rsp->result,
                read_content_rsp->seq_num,
                read_content_rsp_var.reply_segment_len,
                read_content_rsp_var.reply_segment,
                811, __LINE__);
            if (vm_pmng_set_ctx(ptr->handle)  == VM_PMNG_OP_OK)
            {
                (*ptr->read_content_rsp_cb)( app_req_id,
                    read_content_rsp->seq_num,
                    read_content_rsp->result,
                    read_content_rsp->more,
                    read_content_rsp_var.reply_segment_len,
                    read_content_rsp_var.reply_segment);

                vm_pmng_reset_ctx();
                
                MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
                    ptr->handle, 
                    read_content_rsp->more, 
                    read_content_rsp->result,
                    read_content_rsp->seq_num,
                    read_content_rsp_var.reply_segment_len,
                    read_content_rsp_var.reply_segment,
                    812, __LINE__);

            }
        }
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E3, 81, __LINE__);
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 81, __LINE__);
    return MMI_TRUE;
}

/*****************************************************************************
* FUNCTION
*  mre_wps_cancel_rsp_hdlr
* DESCRIPTION
*  This function is used to
* PARAMETERS
*
* RETURNS
*  void
*****************************************************************************/
static MMI_BOOL mre_wps_cancel_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 index;
    kal_int16 app_req_id;
    wps_cancel_rsp_struct *cancel_rsp;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 91, __LINE__);
    cancel_rsp = (wps_cancel_rsp_struct*) msg;
    ASSERT(cancel_rsp);

    /*search wps context based on channel id which is always unique */
    index = mre_wps_find_external_req_id(cancel_rsp->request_id);
    if(index < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 91, __LINE__);
        return MMI_FALSE;
    }
    ptr = &g_mre_wps_cntxt[index];
    app_req_id = mre_wps_find_req_id_ext_req_id(index, cancel_rsp->request_id);
    if(app_req_id < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 91, __LINE__);
        return MMI_FALSE;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        index, 
        app_req_id, 
        ptr->cancel_rsp_cb,
        ptr->handle,
        0,
        0,
        910, __LINE__);
    

    /*callback application handler to get unset channel result*/
    if(ptr->cancel_rsp_cb )
    {
        //VMINT phandle = g_mre_wps_cntxt[index].handle;//vm_pmng_get_current_handle();

        if (vm_pmng_set_ctx(ptr->handle)  == VM_PMNG_OP_OK)
        {
            (*ptr->cancel_rsp_cb)( app_req_id, cancel_rsp->result);
            vm_pmng_reset_ctx();
            
            MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
                index, 
                app_req_id, 
                ptr->cancel_rsp_cb,
                ptr->handle,
                cancel_rsp->result,
                ptr->inuse,
                911, __LINE__);
        }
    }
    else
    {
        mre_wps_clear_req_info(index, cancel_rsp->request_id);
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E3, app_req_id, __LINE__);
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E3, 91, __LINE__);
        return MMI_FALSE;
    }

    mre_wps_clear_req_info(index, cancel_rsp->request_id);

    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 91, __LINE__);
    return MMI_TRUE;
}


static MMI_BOOL vm_wps_post_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int8 i;
    wps_post_content_ind_struct * ind = msg;
    kal_int16 app_req_id = 0;
    mre_wps_cntxt_struct * ptr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*check all WPS context which wants to know query status*/
    ASSERT(ind);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 161, __LINE__);
    i = mre_wps_find_external_req_id(ind->request_id);

    
    if (i < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E1, 161, __LINE__);
        return MMI_FALSE;
    }
    
    ptr = &g_mre_wps_cntxt[i];
    app_req_id = mre_wps_find_req_id_ext_req_id(i, ind->request_id);
    if(app_req_id < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E2, 161, __LINE__);
        return MMI_FALSE;
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_LOG, 
        i, 
        ind->request_id, 
        ind->seq_num,
        ind->result,
        ptr->handle,
        0,
        161, __LINE__);
    
    if(ptr->post_ind_cb)
    {
        //VMINT phandle = g_mre_wps_cntxt[i].handle;//vm_pmng_get_current_handle();

        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 162, __LINE__);
        if (vm_pmng_set_ctx(ptr->handle)  == VM_PMNG_OP_OK)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_S, 163, __LINE__);
            (*ptr->post_ind_cb)(app_req_id, ind->seq_num, ind->result);
            MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 164, __LINE__);
            vm_pmng_reset_ctx();
        }
        MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 165, __LINE__);
    }

    
    MMI_TRACE(MMI_MRE_TRC_MOD_HTTPS, TRC_MRE_VMSOCK_HTTPS_E, 161, __LINE__);
    return MMI_TRUE;
}

	//abm hold
kal_uint32 vm_get_https_acctid_by_chnlid(VMINT channel_id)
{
    kal_int8 idx = mre_wps_search_cntxt_by_channel(channel_id);
    
    if(idx < 0)
    {
        return 0;
    }

    return g_mre_wps_cntxt[idx].account_id;
    
}


#endif /* __MRE_SAL_WPS__ */

