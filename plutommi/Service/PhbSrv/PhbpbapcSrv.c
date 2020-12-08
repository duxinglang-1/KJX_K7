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
 *  PhbpbapcSrv.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  PBAPC
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"

#if defined(__BT_PBAP_CLIENT__)

#include "PbapSrvGprot.h"
#include "PhbpbapcSrv.h"
#include "PhbpbapSrvGprot.h"
#include "PhbSrvIprot.h"
#include "Unicodexdcl.h"


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbap_init
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
void srv_phb_pbap_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_p = &g_srv_phb_pbapc_cntx;
    memset(srv_phb_pbapc_cntx_p, 0x0, sizeof(srv_phb_pbapc_cntx_struct));

    srv_phb_pbapc_cntx_p->is_ready = MMI_TRUE;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_INIT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_cntx
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static srv_phb_pbapc_cntx_struct *srv_phb_pbapc_get_cntx(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_phb_pbapc_cntx_p;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_is_ready
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static MMI_BOOL srv_phb_pbapc_is_ready()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();

    return srv_cntx_p->is_ready;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_check_handle_exhausted
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static MMI_BOOL srv_phb_pbapc_check_handle_exhausted()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();

    return srv_cntx_p->handle_exhausted;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_is_busy
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_phb_pbapc_convert_ret(S32 pbap_ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PHB_PBAPC_RET_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pbap_ret)
    {
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
        #endif

        default:
        {
            ret = SRV_PHB_PBAPC_RET_UNKNOWN;
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_bt_notify
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_bt_notify(bt_pbap_client_event_notify_struct *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_async_hdlr_struct *user_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BT_NOTIFY, msg->type, msg->srvhd, msg->data);

    switch (msg->type)
    {
        case EVT_ID_PBAPC_CONNECT_RSP:
        case EVT_ID_PBAPC_CONNECT_IND:
        {
            break;
        }

        case EVT_ID_PBAPC_READ_FOLDER_RSP:
        {
            if (srv_phb_pbapc_get_job_type(msg->srvhd) == SRV_PHB_PBAPC_JOB_READ_FOLDER)
            {
                srv_phb_pbapc_read_folder_rsp_struct *folder_rsp = NULL;
                bt_pbap_client_read_folder_rsp_struct *rsp = (bt_pbap_client_read_folder_rsp_struct *)(msg->data);

                user_data = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_async_hdlr_struct), SRV_PHB_MEMORY_TYPE_CTR);
                /* copy rsp */
                folder_rsp = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_read_folder_rsp_struct), SRV_PHB_MEMORY_TYPE_CTR);
                folder_rsp->ret = rsp->cnf_code;
                folder_rsp->folder_path = SRV_PHB_PBAPC_FOLDER_PATH;

                /* set async data */
                user_data->srv_handle = msg->srvhd;
                user_data->para = folder_rsp;
                user_data->user_data = user_data;

                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BT_NOTIFY_FOLDER_RSP, rsp->cnf_code, rsp->phoneBookSize, 
                            rsp->newMissedCalls, user_data, folder_rsp);

                srv_phb_async_event_interface(srv_phb_pbapc_read_pse_folder_hdlr, user_data);
            }
            break;
        }
        case EVT_ID_PBAPC_READ_LIST_RSP:
        {
            if (srv_phb_pbapc_get_job_type(msg->srvhd) == SRV_PHB_PBAPC_JOB_READ_LIST)
            {
                S32 ret = -1;
                srv_phb_pbapc_handle_struct *handle = NULL;
                srv_phb_pbapc_read_list_rsp_struct *list_rsp = NULL;
                bt_pbap_client_read_list_rsp_struct *rsp = (bt_pbap_client_read_list_rsp_struct *)(msg->data);

                user_data = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_async_hdlr_struct), SRV_PHB_MEMORY_TYPE_CTR);
                /* copy rsp */
                list_rsp = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_read_list_rsp_struct), SRV_PHB_MEMORY_TYPE_CTR);
                list_rsp->ret = rsp->cnf_code;
                list_rsp->phb_size = rsp->phoneBookSize;
                list_rsp->mc = rsp->newMissedCalls;

                list_rsp->is_list_valid = MMI_FALSE;
                list_rsp->more_data = 0;
                list_rsp->entry_count = -1;
               // srv_phb_pbapc_copy_list_entry(msg->srvhd, rsp);

                /* set async data */
                user_data->srv_handle = msg->srvhd;
                user_data->para = list_rsp;
                user_data->user_data = user_data;

                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BT_NOTIFY_LIST_RSP, rsp->cnf_code, rsp->phoneBookSize,
                            rsp->newMissedCalls, user_data, list_rsp);

                if (rsp->cnf_code == 0) // success
                {
                    handle = srv_phb_pbapc_get_handle_from_srv_hd(msg->srvhd, &ret);
                    list_rsp->more_data = 1;
                    srv_phb_pbapc_change_job_type(handle, SRV_PHB_PBAPC_JOB_GET_LIST_DATA);
                }
                srv_phb_async_event_interface(srv_phb_pbapc_read_pse_list_hdlr, user_data);
            }
            break;
        }
        case EVT_ID_PBAPC_READ_DATA_RSP:
        {
            if (srv_phb_pbapc_get_job_type(msg->srvhd) == SRV_PHB_PBAPC_JOB_GET_LIST_DATA)
            {
                srv_phb_pbapc_read_list_rsp_struct *list_rsp = NULL;
                bt_pbap_list_data_rsp_struct *rsp = (bt_pbap_list_data_rsp_struct *)(msg->data);

                user_data = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_async_hdlr_struct), SRV_PHB_MEMORY_TYPE_CTR);
                /* copy rsp */
                list_rsp = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_read_list_rsp_struct), SRV_PHB_MEMORY_TYPE_CTR);

                list_rsp->phb_size = 0xffff;
                list_rsp->mc = 0xffff;
                list_rsp->ret = 0;

                list_rsp->is_list_valid = MMI_TRUE;
                list_rsp->more_data = rsp->more;
                list_rsp->entry_count = rsp->num_entries;

                srv_phb_pbapc_copy_list_entry(msg->srvhd, rsp);

                /* set async data */
                user_data->srv_handle = msg->srvhd;
                user_data->para = list_rsp;
                user_data->user_data = user_data;

                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BT_NOTIFY_DATA_RSP, rsp->more, rsp->num_entries, user_data, list_rsp);

                if (rsp->more == 0)
                {
                    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BT_NOTIFY_DATA_RSP_ASYNC);

                    srv_phb_async_event_interface(srv_phb_pbapc_read_pse_list_data_hdlr, user_data);
                }
                else
                {
                    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BT_NOTIFY_DATA_RSP_SYNC);

                    srv_phb_pbapc_read_pse_list_data_hdlr(user_data);
                }
            }
            break;
        }
        case EVT_ID_PBAPC_READ_ENTRY_RSP:
        {
            if (srv_phb_pbapc_get_job_type(msg->srvhd) == SRV_PHB_PBAPC_JOB_READ_ENTRY)
            {
                srv_phb_pbapc_read_entry_rsp_struct *entry_rsp = NULL;
                bt_pbap_client_read_entry_struct *rsp = (bt_pbap_client_read_entry_struct *)(msg->data);

                user_data = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_async_hdlr_struct), SRV_PHB_MEMORY_TYPE_CTR);
                /* copy rsp */
                entry_rsp = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_read_entry_rsp_struct), SRV_PHB_MEMORY_TYPE_CTR);
                entry_rsp->ret = rsp->cnf_code;
                entry_rsp->entry_path = SRV_PHB_PBAPC_ENTRY_FILE_PATH;

                user_data->srv_handle = msg->srvhd;
                user_data->para = entry_rsp;
                user_data->user_data = user_data;

                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BT_NOTIFY_ENTRY_RSP, rsp->cnf_code, user_data, entry_rsp);

                srv_phb_async_event_interface(srv_phb_pbapc_read_pse_entry_hdlr, user_data);
            }

            break;
        }
        case EVT_ID_PBAPC_SET_PATH_RSP:
        {
            if (srv_phb_pbapc_get_job_type(msg->srvhd) == SRV_PHB_PBAPC_JOB_SET_PATH)
            {
                srv_phb_pbapc_set_path_rsp_struct *path_rsp = NULL;
                bt_pbap_client_set_path_rsp_struct *rsp = (bt_pbap_client_set_path_rsp_struct *)(msg->data);

                user_data = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_async_hdlr_struct), SRV_PHB_MEMORY_TYPE_CTR);
                /* copy rsp */
                path_rsp = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_set_path_rsp_struct), SRV_PHB_MEMORY_TYPE_CTR);
                path_rsp->ret = rsp->cnf_code;

                user_data->srv_handle = msg->srvhd;
                user_data->para = path_rsp;
                user_data->user_data = user_data;

                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BT_NOTIFY_PATH_RSP, rsp->cnf_code, user_data, path_rsp);

                srv_phb_async_event_interface(srv_phb_pbapc_set_pse_path_hdlr, user_data);
            }
            break;
        }
        case EVT_ID_PBAPC_DISCONNECT_RSP:
        {
            break;
        }
        case EVT_ID_PBAPC_DISCONNECT_IND:
        {
            break;
        }
        case EVT_ID_PBAPC_ENABLE_RSP:
        {
            break;
        }
        /*
        case EVT_ID_PBAPC_DISABLE_RSP:
        {
            break;
        }
        */
        case EVT_ID_PBAPC_ABORT_IND:
        case EVT_ID_PBAPC_ABORT_RSP:
        {
            break;
        }
        case EVT_ID_PBAPC_AUTH_CHALLENGE_IND:
        {
            break;
        }
        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_create_handle
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_update_handle_usage()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    MMI_BOOL handle_exhausted = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    for (i = 0; i < SRV_PHB_PBAPC_MAX_HANDLE_NUM; ++i)
    {
        if (srv_cntx_p->pbapc_handle[i].used_flag == 0) /* can use this handle */
        {
            handle_exhausted = MMI_FALSE;
            break;
        }
    }

    srv_cntx_p->handle_exhausted = handle_exhausted;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_UPDATE_HD_USAGE, handle_exhausted);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_change_job_type
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_change_job_type(srv_phb_pbapc_handle_struct *handle, srv_phb_pbapc_job_enum job_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_CHANGE_JOB_TYPE, handle->srv_hd, handle->job_type, job_type);

    handle->job_type = job_type;
    handle->is_busy = ((job_type == SRV_PHB_PBAPC_JOB_NULL) ? (MMI_FALSE) : (MMI_TRUE));
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_change_pse_path
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_change_pse_path(srv_phb_pbapc_handle_struct *handle, srv_phb_pbap_storage_enum cur_path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_CHANGE_PSE_PATH, handle->srv_hd, handle->cur_path, cur_path);

    handle->cur_path = cur_path;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_handle_from_srv_hd
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static srv_phb_pbapc_handle_struct *srv_phb_pbapc_get_handle_from_srv_hd(S32 srv_hd, S32 *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 ret = SRV_PHB_PBAPC_RET_NOT_EXIST_HANDLE;
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_handle_struct *handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    for (i = 0; i < SRV_PHB_PBAPC_MAX_HANDLE_NUM; ++i)
    {
        if (srv_cntx_p->pbapc_handle[i].srv_hd == srv_hd)
        {
            handle = &(srv_cntx_p->pbapc_handle[i]);
            ret = SRV_PHB_PBAPC_RET_OK;

            break;
        }
    }

    if (result)
    {
        *result = ret;
    }
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_GET_HD_FROM_SRVHD, ret, srv_hd, handle);

    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_list_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_read_pse_list_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    srv_phb_pbapc_async_hdlr_struct *async_para = NULL;
    srv_phb_pbapc_read_pse_list_cb cb_func = NULL;
    srv_phb_pbapc_read_list_rsp_struct list_rsp, *rsp;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    async_para = (srv_phb_pbapc_async_hdlr_struct *) user_data;
    rsp = (srv_phb_pbapc_read_list_rsp_struct *) async_para->para;
    handle = srv_phb_pbapc_get_handle_from_srv_hd(async_para->srv_handle, &ret);

    /* copy rsp */
    list_rsp.phb_size = rsp->phb_size;
    list_rsp.mc = rsp->mc;
    list_rsp.more_data = rsp->more_data;
    list_rsp.list = (srv_phb_pbapc_read_list_entry *)(handle->ex_hd.para);
    list_rsp.ret = rsp->ret;
    list_rsp.is_list_valid = rsp->is_list_valid;
    list_rsp.entry_count = rsp->entry_count;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_LIST_HDLR_FREE, async_para->para, async_para);

    /* free mem */
    srv_phb_mem_free(async_para->para);
    srv_phb_mem_free(async_para);

    /* fail or no more data */
    if (list_rsp.ret != 0 || list_rsp.more_data == 0)
    {
        /* change job state */
        srv_phb_pbapc_change_job_type(handle, SRV_PHB_PBAPC_JOB_NULL);
    }
    else
    {
        srv_phb_pbapc_change_job_type(handle, SRV_PHB_PBAPC_JOB_GET_LIST_DATA);
    }
    /* call back app */
    cb_func = (srv_phb_pbapc_read_pse_list_cb)handle->func;
    ret = cb_func(&list_rsp, handle->user_data);

    if (list_rsp.ret == 0)
    {
        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_ASYNC_N_PARSE_DATA);
        srv_phb_async_event_interface(srv_phb_pbapc_start_read_data, NULL);
    }
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_LIST_HDLR_END, cb_func, handle->user_data, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_list_data_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_read_pse_list_data_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    srv_phb_pbapc_async_hdlr_struct *async_para = NULL;
    srv_phb_pbapc_read_pse_list_cb cb_func = NULL;
    srv_phb_pbapc_read_list_rsp_struct list_rsp, *rsp;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    async_para = (srv_phb_pbapc_async_hdlr_struct *) user_data;
    rsp = (srv_phb_pbapc_read_list_rsp_struct *) async_para->para;
    handle = srv_phb_pbapc_get_handle_from_srv_hd(async_para->srv_handle, &ret);

    /* copy rsp */
    list_rsp.phb_size = rsp->phb_size;
    list_rsp.mc = rsp->mc;
    list_rsp.more_data = rsp->more_data;
    list_rsp.list = (srv_phb_pbapc_read_list_entry *)(handle->ex_hd.para);
    list_rsp.ret = rsp->ret;
    list_rsp.is_list_valid = rsp->is_list_valid;
    list_rsp.entry_count = rsp->entry_count;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_LIST_DATA_HDLR_FREE, async_para->para, async_para);
    /* free mem */
    srv_phb_mem_free(async_para->para);
    srv_phb_mem_free(async_para);

    /* no more data */
    if (list_rsp.more_data == 0)
    {
        /* change job state */
        srv_phb_pbapc_change_job_type(handle, SRV_PHB_PBAPC_JOB_NULL);
    }
    /* call back app */
    cb_func = (srv_phb_pbapc_read_pse_list_cb)handle->func;
    ret = cb_func(&list_rsp, handle->user_data);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_LIST_DATA_HDLR_END, cb_func, handle->user_data, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_entry_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_read_pse_entry_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    srv_phb_pbapc_async_hdlr_struct *async_para = NULL;
    srv_phb_pbapc_read_pse_entry_cb cb_func = NULL;
    srv_phb_pbapc_read_entry_rsp_struct entry_rsp, *rsp;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    async_para = (srv_phb_pbapc_async_hdlr_struct *) user_data;
    rsp = (srv_phb_pbapc_read_entry_rsp_struct *) async_para->para;
    handle = srv_phb_pbapc_get_handle_from_srv_hd(async_para->srv_handle, &ret);

    /* copy rsp */
    entry_rsp.ret = rsp->ret;
    entry_rsp.entry_path = rsp->entry_path;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_ENTRY_HDLR_FREE, async_para->para, async_para);
    /* free mem */
    srv_phb_mem_free(async_para->para);
    srv_phb_mem_free(async_para);

    /* change job state */
    srv_phb_pbapc_change_job_type(handle, SRV_PHB_PBAPC_JOB_NULL);

    /* call back app */
    cb_func = (srv_phb_pbapc_read_pse_entry_cb)handle->func;
    ret = cb_func(&entry_rsp, handle->user_data);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_ENTRY_HDLR_END, cb_func, handle->user_data, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_folder_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_read_pse_folder_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    srv_phb_pbapc_async_hdlr_struct *async_para = NULL;
    srv_phb_pbapc_read_pse_folder_cb cb_func = NULL;
    srv_phb_pbapc_read_folder_rsp_struct folder_rsp, *rsp;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    async_para = (srv_phb_pbapc_async_hdlr_struct *) user_data;
    rsp = (srv_phb_pbapc_read_folder_rsp_struct *) async_para->para;
    handle = srv_phb_pbapc_get_handle_from_srv_hd(async_para->srv_handle, &ret);

    /* copy rsp */
    folder_rsp.ret = rsp->ret;
    folder_rsp.folder_path = rsp->folder_path;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_FOLDER_HDLR_FREE, async_para->para, async_para);
    /* free mem */
    srv_phb_mem_free(async_para->para);
    srv_phb_mem_free(async_para);

    /* change job state */
    srv_phb_pbapc_change_job_type(handle, SRV_PHB_PBAPC_JOB_NULL);

    /* call back app */
    cb_func = (srv_phb_pbapc_read_pse_folder_cb)handle->func;
    ret = cb_func(&folder_rsp, handle->user_data);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_FOLDER_HDLR_END, cb_func, handle->user_data, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_disconnect_pse_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_disconnect_pse_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //handle = srv_phb_pbapc_get_handle_from_srv_hd(srv_hd, &ret);
    srv_phb_mem_free(user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_set_pse_path_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_set_pse_path_hdlr(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    srv_phb_pbapc_async_hdlr_struct *async_para = NULL;
    srv_phb_pbapc_set_pse_path_cb cb_func = NULL;
    srv_phb_pbapc_set_path_rsp_struct path_rsp, *rsp;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    async_para = (srv_phb_pbapc_async_hdlr_struct *) user_data;
    rsp = (srv_phb_pbapc_set_path_rsp_struct *) async_para->para;
    handle = srv_phb_pbapc_get_handle_from_srv_hd(async_para->srv_handle, &ret);

    /* copy rsp */
    path_rsp.ret = rsp->ret;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PATH_HDLR_FREE, async_para->para, async_para);
    /* free mem */
    srv_phb_mem_free(async_para->para);
    srv_phb_mem_free(async_para);

    /* change job state */
    srv_phb_pbapc_change_job_type(handle, SRV_PHB_PBAPC_JOB_NULL);

    /* change path  */
    srv_phb_pbapc_change_pse_path(handle, handle->want_path);

    /* call back app */
    cb_func = (srv_phb_pbapc_set_pse_path_cb)handle->func;
    ret = cb_func(&path_rsp, handle->user_data);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PATH_HDLR_END, cb_func, handle->user_data, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_path_enum
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static mmi_pbapc_path_enum srv_phb_pbapc_get_path_enum(srv_phb_pbap_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pbapc_path_enum path = PBAPC_PATH_ROOT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (storage)
    {
        case SRV_PHB_PBAP_STORAGE_PHONE_PB:
        {
            path = PBAPC_PATH_PHONEBOOK;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
        {
            path = PBAPC_PATH_INCOMING;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
        {
            path = PBAPC_PATH_OUTGOING;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
        {
            path = PBAPC_PATH_MISSED;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_PHONE_CCH:
        {
            path = PBAPC_PATH_COMBINED;
            break;
        }
        /* sim */
        case SRV_PHB_PBAP_STORAGE_SIM1_PB:
        {
            path = PBAPC_PATH_SIM_PHONEBOOK;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_SIM1_ICH:
        {
            path = PBAPC_PATH_SIM_INCOMING;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_SIM1_OCH:
        {
            path = PBAPC_PATH_SIM_OUTGOING;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_SIM1_MCH:
        {
            path = PBAPC_PATH_SIM_MISSED;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_SIM1_CCH:
        {
            path = PBAPC_PATH_SIM_COMBINED;
            break;
        }

        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return path;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_copy_list_entry
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_copy_list_entry(S32 srv_hd, bt_pbap_list_data_rsp_struct *list_rsp)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    srv_phb_pbapc_read_list_req_ex_struct *list_entry_ex = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    S32 i = 0;
    S32 max_read = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = srv_phb_pbapc_get_handle_from_srv_hd(srv_hd, &ret);
    list_entry_ex = (srv_phb_pbapc_read_list_req_ex_struct *)(handle->ex_hd.para);
    kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]srv_phb_pbapc_copy_list_entry--list_entry: 0x%x, cnt: %d\n", 
                    list_entry_ex->list_entry, list_entry_ex->entry_count);
    max_read = (list_entry_ex->entry_count > list_rsp->num_entries ? (list_rsp->num_entries):(list_entry_ex->entry_count));

    for (i = 0; i < max_read; ++i)
    {
        list_entry_ex->list_entry[i].entry_index = list_rsp->handle[i];
        memcpy(list_entry_ex->list_entry[i].entry_name, list_rsp->name[i], SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN);
        list_entry_ex->list_entry[i].entry_name[SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN] = L'\0';
        kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]srv_phb_pbapc_copy_list_entry(data)--index: %d, name: %s\n", 
                        list_rsp->handle[i], list_rsp->name[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_copy_list_entry
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static srv_phb_pbapc_job_enum srv_phb_pbapc_get_job_type(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    handle = srv_phb_pbapc_get_handle_from_srv_hd(srv_hd, &ret);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_GET_JOB_TYPE, handle->job_type);

    return handle->job_type;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_obj_name
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_phb_pbapc_get_obj_name(U16 entry_index, U16 *obj_name, U16 name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wsprintf_ex((WCHAR *)obj_name, name_len, (WCHAR *)L"%d", entry_index);
    mmi_wcsncat(obj_name, SRV_PHB_PBAPC_OBJ_NAME_SUFFIX, mmi_wcslen(SRV_PHB_PBAPC_OBJ_NAME_SUFFIX));

    return mmi_wcslen(obj_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_folder_name
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_phb_pbapc_get_folder_name(srv_phb_pbap_storage_enum folder, U16 *folder_name, U16 name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR name[SRV_PHB_PBAPC_MAX_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy((WCHAR *) folder_name, srv_phb_pbapc_folder_name[folder]);
    mmi_wcs_to_asc(name, (WCHAR *)srv_phb_pbapc_folder_name[folder]);
    kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]name: %s\n", name);

    return mmi_wcslen(folder_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_folder_name
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_phb_pbapc_get_file_name(srv_phb_pbap_storage_enum folder, U16 *file_name, U16 name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //srv_phb_pbapc_get_folder_name(folder, file_name, name_len);
    mmi_wcscpy((WCHAR *)file_name, g_srv_phb_pbapc_path[folder]);
    mmi_wcscat((WCHAR *)file_name, (WCHAR *)L".vcf");

    return mmi_wcslen(file_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_vcard_filter
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_get_vcard_filter(PbapVcardFilter *vcard_filter, U32 filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(vcard_filter, 0x0, sizeof(PbapVcardFilter));

    filter &= (~SRV_PHB_PBAP_VCARD_FILTER_PHOTO); /* filter remove photo */

    for (i = PBAP_VCARD_FILTER_VER; i < SRV_PHB_PBAP_VCARD_FILTER_TOTAL; ++i)
    {
        if (filter & (1 << (i + 1)))
        {
            vcard_filter->byte[i / 8] |= (1 << (i % 8));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_prepare_read_pse_entry
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_prepare_read_pse_entry(srv_phb_pbapc_read_entry_req_struct *entry_req, srv_phb_pbapc_read_pse_entry_cb cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_set_path_req_struct path_req;
    srv_phb_pbapc_prepare_read_entry_req_struct *prpare_entry_req = NULL;
    srv_phb_pbapc_handle_struct *handle = NULL;
    U16 *folder_name = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prpare_entry_req = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_prepare_read_entry_req_struct), SRV_PHB_MEMORY_TYPE_CTR);

    handle = (srv_phb_pbapc_handle_struct *)(entry_req->handle);
    /* save entry req content */
    prpare_entry_req->storage = entry_req->storage;
    prpare_entry_req->user_data = entry_req->user_data;
    prpare_entry_req->cb_func = cb_func;
    prpare_entry_req->srv_hd = handle->srv_hd;

    prpare_entry_req->entry_index = entry_req->entry_index;
    prpare_entry_req->vcard_format = entry_req->vcard_format;
    prpare_entry_req->vcard_filter = entry_req->vcard_filter;


    path_req.handle = entry_req->handle;
    path_req.storage = entry_req->storage;
    path_req.user_data = prpare_entry_req;
    path_req.folder_type = SRV_PHB_PBAP_FORWARD_FOLDER;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_ENTRY, prpare_entry_req, prpare_entry_req->user_data, cb_func);

    ret = srv_phb_pbapc_set_pse_path(&path_req, srv_phb_pbapc_prepare_read_pse_entry_hdlr);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_ENTRY_RET, ret);
}

/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_prepare_read_pse_entry_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_phb_pbapc_prepare_read_pse_entry_hdlr(srv_phb_pbapc_set_path_rsp_struct *path_rsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_prepare_read_entry_req_struct *prepare_entry_req = NULL;
    srv_phb_pbapc_read_entry_req_struct entry_req;
    srv_phb_pbapc_handle_struct *handle = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prepare_entry_req = (srv_phb_pbapc_prepare_read_entry_req_struct *)user_data;
    handle = srv_phb_pbapc_get_handle_from_srv_hd(prepare_entry_req->srv_hd, &ret);

    /* set read entry req */
    entry_req.handle = (void *) handle;
    entry_req.storage = prepare_entry_req->storage;
    entry_req.user_data = prepare_entry_req->user_data;

    entry_req.entry_index = prepare_entry_req->entry_index;
    entry_req.vcard_format = prepare_entry_req->vcard_format;
    entry_req.vcard_filter = prepare_entry_req->vcard_filter;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_ENTRY_HDLR, prepare_entry_req, prepare_entry_req->user_data, prepare_entry_req->cb_func);

    ret = srv_phb_pbapc_read_pse_entry(&entry_req, prepare_entry_req->cb_func);

    /* free mem */
    srv_phb_mem_free(prepare_entry_req);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_ENTRY_HDLR_RET, ret);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_prepare_read_pse_list
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_prepare_read_pse_list(srv_phb_pbapc_read_list_req_struct *list_req, srv_phb_pbapc_read_pse_list_cb cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_set_path_req_struct path_req;
    srv_phb_pbapc_prepare_read_list_req_struct *prepare_list_req = NULL;
    srv_phb_pbapc_handle_struct *handle = NULL;

    U16 *folder_name = NULL;
    U8 *query_pattern = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prepare_list_req = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_prepare_read_list_req_struct), SRV_PHB_MEMORY_TYPE_CTR);

    if (list_req->folder_name)
    {
        folder_name = srv_phb_mem_malloc(sizeof(U16) * (SRV_PHB_PBAPC_MAX_PATH_LEN + 1), SRV_PHB_MEMORY_TYPE_CTR);
        memcpy(folder_name, list_req->folder_name, SRV_PHB_PBAPC_MAX_PATH_LEN);
        folder_name[SRV_PHB_PBAPC_MAX_PATH_LEN] = L'\0';
    }
    if (list_req->query_pattern)
    {
        query_pattern = srv_phb_mem_malloc(sizeof(U8) * (SRV_PHB_PBAPC_MAX_QUERY_LEN + 1), SRV_PHB_MEMORY_TYPE_CTR);
        memcpy(query_pattern, list_req->query_pattern, SRV_PHB_PBAPC_MAX_QUERY_LEN);
        query_pattern[SRV_PHB_PBAPC_MAX_QUERY_LEN] = '\0';
    }

    handle = (srv_phb_pbapc_handle_struct *)(list_req->handle);
    /* save list req content */
    prepare_list_req->storage = list_req->storage;
    prepare_list_req->user_data = list_req->user_data;
    prepare_list_req->cb_func = cb_func;
    prepare_list_req->srv_hd = handle->srv_hd;

    prepare_list_req->folder_name = folder_name;
    prepare_list_req->query_attr = list_req->query_attr;
    prepare_list_req->order = list_req->order;
    prepare_list_req->query_pattern = query_pattern;
    prepare_list_req->query_length = list_req->query_length;
    prepare_list_req->query_count = list_req->query_count;
    prepare_list_req->query_offset = list_req->query_offset;
    prepare_list_req->list_req_ex.list_entry = list_req->list_req_ex->list_entry;
    prepare_list_req->list_req_ex.entry_count = list_req->list_req_ex->entry_count;

    /* fill set path req */
    path_req.handle = list_req->handle;
    path_req.storage = list_req->storage;
    path_req.user_data = prepare_list_req;
    path_req.folder_type = SRV_PHB_PBAP_FORWARD_FOLDER;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_LIST, prepare_list_req, list_req->user_data,
                cb_func, list_req->list_req_ex, folder_name, query_pattern);

    ret = srv_phb_pbapc_set_pse_path(&path_req, srv_phb_pbapc_prepare_read_pse_list_hdlr);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_LIST_RET, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_prepare_read_pse_list_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_phb_pbapc_prepare_read_pse_list_hdlr(srv_phb_pbapc_set_path_rsp_struct *path_rsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_prepare_read_list_req_struct *prepare_list_req = NULL;
    srv_phb_pbapc_read_list_req_struct list_req;
    srv_phb_pbapc_handle_struct *handle = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prepare_list_req = (srv_phb_pbapc_prepare_read_list_req_struct *)user_data;
    handle = srv_phb_pbapc_get_handle_from_srv_hd(prepare_list_req->srv_hd, &ret);

    /* set read list req */
    /* fill head */
    list_req.handle = (void *)handle;
    list_req.storage = prepare_list_req->storage;
    list_req.user_data = prepare_list_req->user_data;

    list_req.folder_name = prepare_list_req->folder_name;
    list_req.query_attr = prepare_list_req->query_attr;
    list_req.order = prepare_list_req->order;
    list_req.query_pattern = prepare_list_req->query_pattern;
    list_req.query_length = prepare_list_req->query_length;
    list_req.query_count = prepare_list_req->query_count;
    list_req.query_offset = prepare_list_req->query_offset;
    list_req.list_req_ex = &prepare_list_req->list_req_ex;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_LIST_HDLR,
                prepare_list_req, prepare_list_req->user_data, prepare_list_req->cb_func, &(prepare_list_req->list_req_ex),
                prepare_list_req->folder_name, prepare_list_req->query_pattern);

    ret = srv_phb_pbapc_read_pse_list(&list_req, prepare_list_req->cb_func);

    /* free mem */
    if (prepare_list_req->folder_name)
    {
        srv_phb_mem_free(prepare_list_req->folder_name);
    }
    if (prepare_list_req->query_pattern)
    {
        srv_phb_mem_free(prepare_list_req->query_pattern);
    }
    srv_phb_mem_free(prepare_list_req);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_LIST_HDLR_RET, ret);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_prepare_read_pse_folder
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_prepare_read_pse_folder(srv_phb_pbapc_read_folder_req_struct *folder_req, srv_phb_pbapc_read_pse_folder_cb cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_set_path_req_struct path_req;
    srv_phb_pbapc_prepare_read_folder_req_struct *prpare_folder_req = NULL;
    srv_phb_pbapc_handle_struct *handle = NULL;
    U16 *folder_name = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prpare_folder_req = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_prepare_read_folder_req_struct), SRV_PHB_MEMORY_TYPE_CTR);

    if (folder_req->folder_name)
    {
        folder_name = srv_phb_mem_malloc(sizeof(U16) * (SRV_PHB_PBAPC_MAX_PATH_LEN + 1), SRV_PHB_MEMORY_TYPE_CTR);
        memcpy(folder_name, folder_req->folder_name, SRV_PHB_PBAPC_MAX_PATH_LEN);
        folder_name[SRV_PHB_PBAPC_MAX_PATH_LEN] = L'\0';
    }

    handle = (srv_phb_pbapc_handle_struct *)(folder_req->handle);
    /* save folder req content */
    prpare_folder_req->storage = folder_req->storage;
    prpare_folder_req->user_data = folder_req->user_data;
    prpare_folder_req->cb_func = cb_func;
    prpare_folder_req->srv_hd = handle->srv_hd;

    prpare_folder_req->folder_name = folder_name;
    prpare_folder_req->vcard_format = folder_req->vcard_format;
    prpare_folder_req->vcard_filter = folder_req->vcard_filter;
    prpare_folder_req->list_count = folder_req->list_count;
    prpare_folder_req->list_offset = folder_req->list_offset;

    path_req.handle = folder_req->handle;
    path_req.storage = folder_req->storage;
    path_req.user_data = prpare_folder_req;
    path_req.folder_type = SRV_PHB_PBAP_FORWARD_FOLDER;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_FOLDER, prpare_folder_req,
                prpare_folder_req->user_data, cb_func, folder_name);

    ret = srv_phb_pbapc_set_pse_path(&path_req, srv_phb_pbapc_prepare_read_pse_folder_hdlr);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_FOLDER_RET, ret);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_prepare_read_pse_folder_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_phb_pbapc_prepare_read_pse_folder_hdlr(srv_phb_pbapc_set_path_rsp_struct *path_rsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_prepare_read_folder_req_struct *prepare_folder_req = NULL;
    srv_phb_pbapc_read_folder_req_struct folder_req;
    srv_phb_pbapc_handle_struct *handle = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    prepare_folder_req = (srv_phb_pbapc_prepare_read_folder_req_struct *)user_data;
    handle = srv_phb_pbapc_get_handle_from_srv_hd(prepare_folder_req->srv_hd, &ret);

    /* set read list req */
    folder_req.handle = (void *) handle;
    folder_req.storage = prepare_folder_req->storage;
    folder_req.user_data = prepare_folder_req->user_data;

    folder_req.folder_name = prepare_folder_req->folder_name;
    folder_req.vcard_format = prepare_folder_req->vcard_format;
    folder_req.vcard_filter = prepare_folder_req->vcard_filter;
    folder_req.list_count = prepare_folder_req->list_count;
    folder_req.list_offset = prepare_folder_req->list_offset;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_FOLDER_HDLR, prepare_folder_req,
                prepare_folder_req->user_data, prepare_folder_req->cb_func, prepare_folder_req->folder_name);

    ret = srv_phb_pbapc_read_pse_folder(&folder_req, prepare_folder_req->cb_func);
    /* free mem */
    if (prepare_folder_req->folder_name)
    {
        srv_phb_mem_free(prepare_folder_req->folder_name);
    }
    srv_phb_mem_free(prepare_folder_req);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PREPARE_FOLDER_HDLR_RET, ret);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_start_read_data
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_start_read_data(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_START_PARSE_DATA);
    bt_pbapc_read_data();
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_set_pse_path
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_phb_pbapc_set_pse_path(srv_phb_pbapc_set_path_req_struct *path_req, srv_phb_pbapc_set_pse_path_cb cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!path_req)
    {
        ret = SRV_PHB_PBAPC_RET_POINTER_NULL;
    }
    else
    {
        handle = (srv_phb_pbapc_handle_struct *) (path_req->handle);

        if (handle)
        {
            if (handle->is_busy)
            {
                ret = SRV_PHB_PBAPC_RET_BUSY;
            }
            else
            {
                /* copy user sets */
                handle->func = (void *)cb_func;
                handle->user_data = path_req->user_data;
                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_SET_PATH_REQ, path_req->folder_type, path_req->storage, cb_func);
                /* set path req */
                if (srv_btpbapc_set_path_req(handle->srv_hd, (pbap_set_folder_type_enum)(path_req->folder_type), srv_phb_pbapc_get_path_enum(path_req->storage)) == 0)
                {
                    ret = SRV_PHB_PBAPC_RET_REQ_HANDLE_INVALID;
                    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_SET_PATH_SEND_REQ, ret);
                }
                else
                {
                    srv_phb_pbapc_change_job_type(handle, SRV_PHB_PBAPC_JOB_SET_PATH);
                }
            }
        }
        else
        {
            ret = SRV_PHB_PBAPC_RET_REQ_HANDLE_INVALID;
        }
    }
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_SET_PATH_END, ret);

    return ret;
}


#define SRV_PHB_PBAPC_EXTERN_API

/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_create_handle
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
SRV_PHB_PBAPC_HANDLE srv_phb_pbapc_create_handle(S32 *result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    S32 i = 0;
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_phb_pbapc_is_ready())
    {
        ret = SRV_PHB_PBAPC_RET_NOT_READY;
    }

    if ((ret == SRV_PHB_PBAPC_RET_OK) && srv_phb_pbapc_check_handle_exhausted())
    {
        ret = SRV_PHB_PBAPC_RET_HANDLE_RXHAUST;
    }

    if (SRV_PHB_PBAPC_RET_OK == ret)
    {
        srv_cntx_p = srv_phb_pbapc_get_cntx();
        for (i = 0; i < SRV_PHB_PBAPC_MAX_HANDLE_NUM; ++i)
        {
            if (srv_cntx_p->pbapc_handle[i].used_flag == 0) /* can use this handle */
            {
                handle = &srv_cntx_p->pbapc_handle[i];

                break;
            }
        }
        MMI_ASSERT(handle);

        handle->srv_hd = srv_btpbapc_client_open();
        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_CREATE_HD_OPEN, handle->srv_hd);
        if (handle->srv_hd < 0)
        {
            //ret = srv_phb_pbapc_convert_ret(handle->srv_hd);
            ret = SRV_PHB_PBAPC_RET_FAIL;
        }
        else
        {
            if (srv_btpbapc_client_register_notifier(handle->srv_hd, srv_phb_pbapc_bt_notify) == 0)
            {
                ret = SRV_PHB_PBAPC_RET_FAIL;
                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_CREATE_HD_REGISTER_CB);
            }
            else
            {
                ret = SRV_PHB_PBAPC_RET_OK;
                handle->used_flag = 1;
                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_CREATE_HANDLE_OK, handle->used_flag, handle->srv_hd,
                            handle->is_busy, handle->job_type, handle->user_data, handle->func);
            }
        }
    }

    srv_phb_pbapc_update_handle_usage();
    if (result)
    {
        *result = ret;
    }
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_CREATE_HANDLE, ret, handle);

    return handle;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_destory_handle
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_destory_handle(SRV_PHB_PBAPC_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *srv_handle = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_handle = (srv_phb_pbapc_handle_struct *)handle;

    if (srv_handle)
    {
        ret = srv_btpbapc_client_close(srv_handle->srv_hd);

        ret = (ret == 0 ) ? (SRV_PHB_PBAPC_RET_FAIL) : (SRV_PHB_PBAPC_RET_OK);
        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_DESTORY_HANDLE, ret, srv_handle, srv_handle->used_flag, srv_handle->srv_hd,
                    srv_handle->is_busy, srv_handle->job_type, srv_handle->user_data, srv_handle->func);
        srv_handle->used_flag = 0;
        srv_phb_pbapc_change_job_type(srv_handle, SRV_PHB_PBAPC_JOB_NULL);
        srv_phb_pbapc_change_pse_path(srv_handle, SRV_PHB_PBAP_STORAGE_NULL);
    }
    else
    {
        ret = SRV_PHB_PBAPC_RET_INVALID_PARAMETERS;
    }
    srv_phb_pbapc_update_handle_usage();

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_DESTORY_HANDLE_END, ret);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_init_para
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_init_para(srv_phb_pbapc_job_enum job_type, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    S32 size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (para)
    {
        switch(job_type)
        {
            case SRV_PHB_PBAPC_JOB_SET_PATH:
            {
                size = 0;
                break;
            }
            case SRV_PHB_PBAPC_JOB_READ_LIST:
            {
                size = sizeof(srv_phb_pbapc_read_list_req_struct);
                break;
            }
            case SRV_PHB_PBAPC_JOB_READ_FOLDER:
            {
                size = sizeof(srv_phb_pbapc_read_folder_req_struct);
                break;
            }
            case SRV_PHB_PBAPC_JOB_READ_ENTRY:
            {
                size = sizeof(srv_phb_pbapc_read_entry_req_struct);
                break;
            }

            default:
            {
                ret = SRV_PHB_PBAPC_RET_UNKNOW_JOB;
                break;
            }
        }
        if (SRV_PHB_PBAPC_RET_OK == ret)
        {
            memset(para, 0x0, size);
        }
    }
    else
    {
        ret = SRV_PHB_PBAPC_RET_POINTER_NULL;
    }
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_INIT_PARA, job_type, para, ret, size);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_list
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_read_pse_list(srv_phb_pbapc_read_list_req_struct *list_req, srv_phb_pbapc_read_pse_list_cb cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!list_req)
    {
        ret = SRV_PHB_PBAPC_RET_POINTER_NULL;
    }
    else
    {
        handle = (srv_phb_pbapc_handle_struct *) (list_req->handle);

        if (handle && handle->used_flag == 1)
        {
            if (handle->is_busy)
            {
                ret = SRV_PHB_PBAPC_RET_BUSY; /* job type is not null */
            }
            else
            {
                /* copy user sets */
                handle->func = (void *)cb_func;
                handle->user_data = list_req->user_data;
                //handle->ex_hd.para = list_req->list_req_ex;
                g_srv_phb_pbapc_list_req.entry_count = list_req->list_req_ex->entry_count;
                g_srv_phb_pbapc_list_req.list_entry = list_req->list_req_ex->list_entry;
                handle->ex_hd.para = (void *)(&g_srv_phb_pbapc_list_req);
                handle->want_path = list_req->storage;
                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_LIST_REQ, handle->func,
                            handle->user_data, handle->want_path, handle->cur_path);
                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_LIST_REQ_E, list_req->query_attr,
                            list_req->order, list_req->query_length, list_req->query_count, list_req->query_offset);

                if (handle->cur_path == list_req->storage)
                {
                    U16 *folder_name_p = NULL;
                    U16 folder_name[SRV_PHB_PBAPC_MAX_PATH_LEN + 1];
                    CHAR name[SRV_PHB_PBAPC_MAX_PATH_LEN + 1];
                    S32 len = 0;

                    if (list_req->folder_name)
                    {
                        //folder_name_p = list_req->folder_name;
                    }
                    else
                    {
                        len = srv_phb_pbapc_get_folder_name(list_req->storage, folder_name, SRV_PHB_PBAPC_MAX_PATH_LEN);
                        folder_name[SRV_PHB_PBAPC_MAX_PATH_LEN] = L'\0';
                        mmi_wcs_to_asc(name, (WCHAR *)folder_name);
                        //folder_name_p = folder_name;
                        kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]srv_phb_pbapc_read_pse_list--name: %s, len: %d", name, len);
                    }

                    if (srv_btpbapc_read_list_req(handle->srv_hd, folder_name_p, list_req->query_attr, list_req->query_pattern, \
                            list_req->query_length, list_req->query_count, list_req->query_offset, list_req->order) == 0)
                    {
                        ret = SRV_PHB_PBAPC_RET_FAIL;
                        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_LIST_SEND_REQ, ret);
                    }
                    else
                    {
                        srv_phb_pbapc_change_job_type(handle, SRV_PHB_PBAPC_JOB_READ_LIST);
                    }
                }
                else
                {
                    /* change path first */
                    srv_phb_pbapc_prepare_read_pse_list(list_req, cb_func);
                }
            }
        }
        else
        {
            ret = SRV_PHB_PBAPC_RET_REQ_HANDLE_INVALID;
        }
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_LIST_END, ret);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_entry
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_read_pse_entry(srv_phb_pbapc_read_entry_req_struct *entry_req, srv_phb_pbapc_read_pse_entry_cb cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    PbapVcardFilter vcard_filter;
    U16 obj_name[SRV_PHB_PBAPC_MAX_OBJ_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!entry_req)
    {
        ret = SRV_PHB_PBAPC_RET_POINTER_NULL;
    }
    else
    {
        handle = (srv_phb_pbapc_handle_struct *) (entry_req->handle);

        if (handle && handle->used_flag == 1)
        {
            if (handle->is_busy)
            {
                ret = SRV_PHB_PBAPC_RET_BUSY;
            }
            else
            {
                CHAR name[SRV_PHB_PBAPC_MAX_PATH_LEN + 1];
                U16 len = 0;

                /* copy user sets */
                handle->func = (void *)cb_func;
                handle->user_data = entry_req->user_data;

                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_ENTRY_REQ, handle->func, handle->user_data,
                            entry_req->entry_index, entry_req->vcard_format);
                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_ENTRY_REQ_E, entry_req->vcard_filter,
                            entry_req->storage, handle->cur_path);

                if (entry_req->storage == handle->cur_path)
                {
                    /* get index obj name */
                    len = srv_phb_pbapc_get_obj_name(entry_req->entry_index, obj_name, SRV_PHB_PBAPC_MAX_OBJ_NAME_LEN);
                    mmi_wcs_to_asc(name, (WCHAR *)obj_name);
                    kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]srv_phb_pbapc_read_pse_entry--name: %s, len: %d", name, len);
                    /* get vcard filter */
                    srv_phb_pbapc_get_vcard_filter(&vcard_filter, entry_req->vcard_filter);
                    /* call read entry */
                    if (srv_btpbapc_read_entry_req(handle->srv_hd, obj_name, vcard_filter, entry_req->vcard_format) == 0)
                    {
                        ret = SRV_PHB_PBAPC_RET_FAIL;
                        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_ENTRY_FAIL);
                    }
                    else
                    {
                        srv_phb_pbapc_change_job_type(handle, SRV_PHB_PBAPC_JOB_READ_ENTRY);
                    }
                }
                else
                {
                    /* change path first */
                    srv_phb_pbapc_prepare_read_pse_entry(entry_req, cb_func);
                }
            }
        }
        else
        {
            ret = SRV_PHB_PBAPC_RET_REQ_HANDLE_INVALID;
        }
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_ENTRY_END, ret);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_folder
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_read_pse_folder(srv_phb_pbapc_read_folder_req_struct *folder_req, srv_phb_pbapc_read_pse_folder_cb cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *handle = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    PbapVcardFilter vcard_filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!folder_req)
    {
        ret = SRV_PHB_PBAPC_RET_POINTER_NULL;
    }
    else
    {
        handle = (srv_phb_pbapc_handle_struct *) (folder_req->handle);

        if (handle && handle->used_flag == 1)
        {
            if (handle->is_busy)
            {
                ret = SRV_PHB_PBAPC_RET_BUSY; /* job type is not null */
            }
            else
            {
                /* copy user sets */
                handle->func = (void *)cb_func;
                handle->user_data = folder_req->user_data;
                handle->want_path = folder_req->storage;
                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_FOLDER_REQ, handle->func, handle->user_data,
                            handle->want_path, handle->cur_path);
                MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_FOLDER_REQ_E, folder_req->vcard_format,
                            folder_req->vcard_filter, folder_req->list_count, folder_req->list_offset);

                //if (handle->cur_path == folder_req->storage)
                if (MMI_TRUE)
                {
                    U16 *file_name_p = NULL;
                    U16 file_name[SRV_PHB_PBAPC_MAX_PATH_LEN + 1];
                    CHAR name[SRV_PHB_PBAPC_MAX_PATH_LEN + 1];
                    S32 len = 0;

                    //if (folder_req->folder_name)
                    //{
                    //    file_name_p = folder_req->folder_name;
                    //}
                    //else
                    {
                        len = srv_phb_pbapc_get_file_name(folder_req->storage, file_name, SRV_PHB_PBAPC_MAX_PATH_LEN);
                        file_name[SRV_PHB_PBAPC_MAX_PATH_LEN] = L'\0';
                        file_name_p = file_name;
                        mmi_wcs_to_asc(name, (WCHAR *)file_name_p);
                        kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]srv_phb_pbapc_read_pse_folder--name: %s, len: %d", name, len);
                    }

                    /* get vcard filter */
                    srv_phb_pbapc_get_vcard_filter(&vcard_filter, folder_req->vcard_filter);

                    if (srv_btpbapc_read_folder_req(handle->srv_hd, file_name_p, vcard_filter, \
                            folder_req->vcard_format, folder_req->list_count, folder_req->list_offset) == 0)
                    {
                        ret = SRV_PHB_PBAPC_RET_FAIL;
                    }
                    else
                    {
                        srv_phb_pbapc_change_job_type(handle, SRV_PHB_PBAPC_JOB_READ_FOLDER);
                    }
                }
                else
                {
                    /* change path first */
                    srv_phb_pbapc_prepare_read_pse_folder(folder_req, cb_func);
                }
            }
        }
        else
        {
            ret = SRV_PHB_PBAPC_RET_REQ_HANDLE_INVALID;
        }
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_FOLDER_END, ret);

    return ret;
}

#define TST_TEST_FUNC

#ifdef __SRV_PHB_PBAPC_TEST_TST__

SRV_PHB_PBAPC_HANDLE g_test_handle;

srv_phb_pbapc_list_entry_struct g_list_entry[SRV_PHB_PBAPC_MAX_READ_LIST_NUM];

static void srv_phb_pbapc_test_read_list(srv_phb_pbap_storage_enum path)
{
    S32 ret = -1;
    srv_phb_pbapc_read_list_req_struct list_req;
    srv_phb_pbapc_read_list_req_ex_struct ex_req;

    g_test_handle = srv_phb_pbapc_create_handle(&ret);
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_TEST_READ_LIST_CREATE_HD, path, g_test_handle, ret);

    if (ret == SRV_PHB_PBAPC_RET_OK)
    {
        ex_req.entry_count = SRV_PHB_PBAPC_MAX_READ_LIST_NUM;
        ex_req.list_entry = g_list_entry;
        /* Req head */
        list_req.handle = g_test_handle;
        list_req.storage = path;
        list_req.user_data = (void *)0xbabe;
        kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]srv_phb_pbapc_test_read_list(list_entry): 0x%x\n", &g_list_entry);

        list_req.folder_name = NULL;
        list_req.query_attr = SRV_PHB_PBAP_ATTR_NAME;
        list_req.order = SRV_PHB_PBAP_SORT_ORDER_ALPHA;
        list_req.query_pattern = NULL;
        list_req.query_length = 0;
        list_req.query_count = SRV_PHB_PBAPC_MAX_READ_LIST_COUNT;
        list_req.query_offset = 0;
        /*
        if (path == SRV_PHB_PBAP_STORAGE_PHONE_PB || path == SRV_PHB_PBAP_STORAGE_SIM1_PB)
        {
            list_req.query_offset = 0;
        }
        else
        {
            list_req.query_offset = 1;
        }
            */
        list_req.list_req_ex = &ex_req;

        ret = srv_phb_pbapc_read_pse_list(&list_req, srv_phb_pbapc_test_read_list_cb);

        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_TEST_READ_LIST, ret);
    }
}


static S32 srv_phb_pbapc_test_read_list_cb(srv_phb_pbapc_read_list_rsp_struct *list_rsp, void *user_data)
{
    S32 i = 0;
    char buf[128];
    srv_phb_pbapc_list_entry_struct *list_entry;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_TEST_READ_LIST_CB, list_rsp->ret,
                list_rsp->is_list_valid, user_data, list_rsp->more_data);

    if (list_rsp->is_list_valid)
    {
        list_entry = list_rsp->list->list_entry;
        for (i = 0; i < list_rsp->entry_count; ++i)
        {
            //MMI_PRINT(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhbPBAPC]srv_phb_pbapc_test_read_list_cb(print)--index: %d, name: %ls\n", 
                        //list_entry[i].entry_index, list_entry[i].entry_name);
            //mmi_wcs_to_asc(buf, list_entry[i].entry_name);
            kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]srv_phb_pbapc_test_read_list_cb(print)--index: %d, name: %s\n", 
                                    list_entry[i].entry_index, (CHAR *)(list_entry[i].entry_name));
        }
        if (list_rsp->more_data == 0)
        {
            srv_phb_pbapc_destory_handle(g_test_handle);
        }
    }
    if (list_rsp->ret != 0)
    {
        srv_phb_pbapc_destory_handle(g_test_handle);
    }

    return 0;
}


static void srv_phb_pbapc_test_read_folder(srv_phb_pbap_storage_enum path)
{
    S32 ret = -1;
    srv_phb_pbapc_read_folder_req_struct folder_req;

    g_test_handle = srv_phb_pbapc_create_handle(&ret);
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_TEST_READ_FOLDER_CREATE_HD, path, g_test_handle, ret);
    if (ret == SRV_PHB_PBAPC_RET_OK)
    {
        /* Req head */
        folder_req.handle = g_test_handle;
        folder_req.storage = path;
        folder_req.user_data = (void *)0xbabe;

        folder_req.folder_name = NULL;
        folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_ALL;
        folder_req.list_count = SRV_PHB_PBAPC_MAX_READ_LIST_COUNT;
        folder_req.list_offset = 0;
/*
        if (path == SRV_PHB_PBAP_STORAGE_PHONE_PB || path == SRV_PHB_PBAP_STORAGE_SIM1_PB)
        {
            folder_req.list_offset = 0;
        }
        else
        {
            folder_req.list_offset = 1;
        }
*/
        ret = srv_phb_pbapc_read_pse_folder(&folder_req, srv_phb_pbapc_test_read_folder_cb);

        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_TEST_READ_FOLDER, ret);
    }
}


static S32 srv_phb_pbapc_test_read_folder_cb(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data)
{
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_TEST_READ_FOLDER_CB, folder_rsp->ret, user_data);

    if (folder_rsp->ret == 0)
    {
        srv_phb_pbapc_test_print_file(folder_rsp->folder_path);
    }

    srv_phb_pbapc_destory_handle(g_test_handle);

    return 0;
}


#define PRINT_LEN   (64)
static void srv_phb_pbapc_test_print_file(U16 *file_name)
{
    
    FS_HANDLE handle, hd2;
    U32 len = 0, ret = 0;
    CHAR buf[PRINT_LEN + 1];

    //MMI_PRINT(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhbPBAPC]srv_phb_pbapc_test_print_file(start)--file: %ls\n", file_name);
    mmi_wcs_to_asc(buf, file_name);
    kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]file_name: %s", buf);

    handle = FS_Open(file_name, FS_READ_ONLY);
    if (handle < 0)
    {
        kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap] file open fail, handle: %d\n", handle);
        hd2 = FS_Open(L"Z:\\@pbap\\folder.tmp", FS_READ_ONLY);
        kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap] file open fail, hd2: %d\n", hd2);
        //MMI_ASSERT(0);
    }
    else
    {
        while(MMI_TRUE)
        {
            ret = FS_Read(handle, buf, PRINT_LEN, &len);
            if (ret != FS_NO_ERROR || len == 0)
            {
                kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]: break, len: %d, ret: %d", len, ret);
                break;
            }
            buf[len] = '\0';
            //MMI_PRINT(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhbPBAPC]--len: %d, buf: %ls\n", len, buf); 
            kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]: len: %d, ret: %d", len, ret);
            kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]: buf: %s", buf);
            buf[0] = '\0';
        }
        FS_Close(handle);
    }
}


static void srv_phb_pbapc_test_read_entry(U16 entry_index, srv_phb_pbap_storage_enum storage)
{
    S32 ret = -1;
    srv_phb_pbapc_read_entry_req_struct entry_req;

    g_test_handle = srv_phb_pbapc_create_handle(&ret);
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_TEST_READ_ENTRY_CREATE_HD, entry_index, g_test_handle, ret);

    if (ret == SRV_PHB_PBAPC_RET_OK)
    {
        /* Req head */
        entry_req.handle = g_test_handle;
        entry_req.storage = storage;
        entry_req.user_data = (void *)0xbabe;

        entry_req.entry_index = entry_index;
        entry_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        entry_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_ALL;

        ret = srv_phb_pbapc_read_pse_entry(&entry_req, srv_phb_pbapc_test_read_entry_cb);
        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_TEST_READ_ENTRY, ret);
    }
}


static S32 srv_phb_pbapc_test_read_entry_cb(srv_phb_pbapc_read_entry_rsp_struct *entry_rsp, void *user_data)
{
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_TEST_READ_ENTRY_CB, entry_rsp->ret, user_data);

    if (entry_rsp->ret == 0)
    {
        srv_phb_pbapc_test_print_file(entry_rsp->entry_path);
    }

    srv_phb_pbapc_destory_handle(g_test_handle);

    return 0;
}

/*****************************************************************************
* FUNCTION
*  srv_phb_pbapc_dump_trace_info
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_phb_pbapc_dump_trace_info(void *buf, int buf_len)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int max_buf_len = 128;
    kal_uint8* buf1 = (kal_uint8*)buf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/        
    if(buf_len > 0)
    {
        //while (buf_len > 0)
        {
            //kal_buffer_trace(SRV_PHB_PBAP_TRACE_GROUP, SRV_BT_DIALER_PBAP_RECV_BUFFER_TRACE, max_buf_len, (const kal_uint8*)buf1);
            //kal_buffer_trace(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BUFFER_TRACE, max_buf_len, (const kal_uint8*)buf1);
            //kal_prompt_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC]: %s", buf1);
            buf_len = buf_len - max_buf_len;
            buf1 = buf1+max_buf_len;
        }
    }
}


#endif /* __SRV_PHB_PBAPC_TEST_TST__ */

/* test through inject string */
U8 srv_phb_pbapc_proc_inject_string(U8 index, kal_uint8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* test read list */
#ifdef __SRV_PHB_PBAPC_TEST_TST__
    char str[256];

    sprintf(str, "srv_phb_pbapc_proc_inject_string--index: %d, string: ", index);
    strcat(str, string);
    //kal_prompt_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-prompt]: %s", str);
    kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb_PBAPC-wap]: %s", str);
    //srv_phb_pbapc_dump_trace_info(str, strlen(str));

    //srv_phb_pbapc_test_print_file(L"E:\\Contact_018_00_19_07_27_43___2012_12_12_17_33_17__T0003.vcf");

    if (strcmp((char *)string, "list_pb") == 0)
    {
        srv_phb_pbapc_test_read_list(SRV_PHB_PBAP_STORAGE_PHONE_PB);
    }
    else if (strcmp((char *)string, "list_ich") == 0)
    {
        srv_phb_pbapc_test_read_list(SRV_PHB_PBAP_STORAGE_PHONE_ICH);
    }
    else if (strcmp((char *)string, "list_och") == 0)
    {
        srv_phb_pbapc_test_read_list(SRV_PHB_PBAP_STORAGE_PHONE_OCH);
    }
    else if (strcmp((char *)string, "list_mch") == 0)
    {
        srv_phb_pbapc_test_read_list(SRV_PHB_PBAP_STORAGE_PHONE_MCH);
    }
    else if (strcmp((char *)string, "list_cch") == 0)
    {
        srv_phb_pbapc_test_read_list(SRV_PHB_PBAP_STORAGE_PHONE_CCH);
    }
    else if (strcmp((char *)string, "list_sim1_pb") == 0)
    {
        srv_phb_pbapc_test_read_list(SRV_PHB_PBAP_STORAGE_SIM1_PB);
    }
    else if (strcmp((char *)string, "list_sim1_ich") == 0)
    {
        srv_phb_pbapc_test_read_list(SRV_PHB_PBAP_STORAGE_SIM1_ICH);
    }
    else if (strcmp((char *)string, "list_sim1_och") == 0)
    {
        srv_phb_pbapc_test_read_list(SRV_PHB_PBAP_STORAGE_SIM1_OCH);
    }
    else if (strcmp((char *)string, "list_sim1_mch") == 0)
    {
        srv_phb_pbapc_test_read_list(SRV_PHB_PBAP_STORAGE_PHONE_MCH);
    }
    else if (strcmp((char *)string, "list_sim1_cch") == 0)
    {
        srv_phb_pbapc_test_read_list(SRV_PHB_PBAP_STORAGE_SIM1_CCH);
    }
 
    /* test read entry */
    if (strcmp((char *)string, "entry_pb") == 0)
    {
        srv_phb_pbapc_test_read_entry(index, SRV_PHB_PBAP_STORAGE_PHONE_PB);
    }
    else if (strcmp((char *)string, "entry_ich") == 0)
    {
        srv_phb_pbapc_test_read_entry(index, SRV_PHB_PBAP_STORAGE_PHONE_ICH);
    }
    else if (strcmp((char *)string, "entry_och") == 0)
    {
        srv_phb_pbapc_test_read_entry(index, SRV_PHB_PBAP_STORAGE_PHONE_OCH);
    }
    else if (strcmp((char *)string, "entry_mch") == 0)
    {
        srv_phb_pbapc_test_read_entry(index, SRV_PHB_PBAP_STORAGE_PHONE_MCH);
    }
    else if (strcmp((char *)string, "entry_cch") == 0)
    {
        srv_phb_pbapc_test_read_entry(index, SRV_PHB_PBAP_STORAGE_PHONE_CCH);
    }
    else if (strcmp((char *)string, "entry_sim1_pb") == 0)
    {
        srv_phb_pbapc_test_read_entry(index, SRV_PHB_PBAP_STORAGE_SIM1_PB);
    }
    else if (strcmp((char *)string, "entry_sim1_ich") == 0)
    {
        srv_phb_pbapc_test_read_entry(index, SRV_PHB_PBAP_STORAGE_SIM1_ICH);
    }
    else if (strcmp((char *)string, "entry_sim1_och") == 0)
    {
        srv_phb_pbapc_test_read_entry(index, SRV_PHB_PBAP_STORAGE_SIM1_OCH);
    }
    else if (strcmp((char *)string, "entry_sim1_mch") == 0)
    {
        srv_phb_pbapc_test_read_entry(index, SRV_PHB_PBAP_STORAGE_PHONE_MCH);
    }
    else if (strcmp((char *)string, "entry_sim1_cch") == 0)
    {
        srv_phb_pbapc_test_read_entry(index, SRV_PHB_PBAP_STORAGE_SIM1_CCH);
    }

    /* test read folder */
    if (strcmp((char *)string, "folder_pb") == 0)
    {
        srv_phb_pbapc_test_read_folder(SRV_PHB_PBAP_STORAGE_PHONE_PB);
    }
    else if (strcmp((char *)string, "folder_ich") == 0)
    {
        srv_phb_pbapc_test_read_folder(SRV_PHB_PBAP_STORAGE_PHONE_ICH);
    }
    else if (strcmp((char *)string, "folder_och") == 0)
    {
        srv_phb_pbapc_test_read_folder(SRV_PHB_PBAP_STORAGE_PHONE_OCH);
    }
    else if (strcmp((char *)string, "folder_mch") == 0)
    {
        srv_phb_pbapc_test_read_folder(SRV_PHB_PBAP_STORAGE_PHONE_MCH);
    }
    else if (strcmp((char *)string, "folder_cch") == 0)
    {
        srv_phb_pbapc_test_read_folder(SRV_PHB_PBAP_STORAGE_PHONE_CCH);
    }
    else if (strcmp((char *)string, "folder_sim1_pb") == 0)
    {
        srv_phb_pbapc_test_read_folder(SRV_PHB_PBAP_STORAGE_SIM1_PB);
    }
    else if (strcmp((char *)string, "folder_sim1_ich") == 0)
    {
        srv_phb_pbapc_test_read_folder(SRV_PHB_PBAP_STORAGE_SIM1_ICH);
    }
    else if (strcmp((char *)string, "folder_sim1_och") == 0)
    {
        srv_phb_pbapc_test_read_folder(SRV_PHB_PBAP_STORAGE_SIM1_OCH);
    }
    else if (strcmp((char *)string, "folder_sim1_mch") == 0)
    {
        srv_phb_pbapc_test_read_folder(SRV_PHB_PBAP_STORAGE_SIM1_MCH);
    }
    else if (strcmp((char *)string, "folder_sim1_cch") == 0)
    {
        srv_phb_pbapc_test_read_folder(SRV_PHB_PBAP_STORAGE_SIM1_CCH);
    }
    /* reset */
    if (strcmp((char *)string, "reset") == 0)
    {
        srv_phb_pbapc_destory_handle(g_test_handle);
    }
#endif /* __SRV_PHB_PBAPC_TEST_TST__ */

    return 0;
}

#endif /* defined(__BT_PBAP_CLIENT__) */

