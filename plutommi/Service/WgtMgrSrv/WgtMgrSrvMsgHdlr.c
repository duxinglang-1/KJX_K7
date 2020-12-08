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
 * WgtMgrSrvMain.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
/************************************************************************/
/* Include Header                                                       */
/************************************************************************/
#ifdef __GADGET_SUPPORT__
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "fs_type.h"
#include "fs_func.h"   
#include "widget_adp_struct.h"
#include "app_str.h"
#include "Conversions.h"
#include "WgtMgrSrvGprot.h"
#include "WgtMgrSrvIprot.h"
#include "WgtMgrSrv.h"
//#include "widget_api.h"

#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "stack_ltlcom.h"
#include "stack_common.h"
#include "task_config.h"

#include "mmi_frm_nvram_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "DebugInitDef_Int.h"
#include "PixcomFontEngine.h"
#include "string.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "certman_api.h"

#ifdef __PLUTO_MMI_PACKAGE__
#include "vadp_p2v_hs.h"
#endif

#ifdef __WGTMGR_MAIN_MENU_SUPPORT__
#include "AppMgrSrvGprot.h"
#endif

#include "mmi_rp_srv_wgtmgr_def.h"

/************************************************************************/
/* Structure and Definition                                             */
/************************************************************************/

/************************************************************************/
/* Internal Function Declaration                                        */
/************************************************************************/
static void srv_wgtmgr_send_message(
    module_type dest_mod, 
    msg_type msg_id,
    void *local_param_ptr, 
    void *peer_buf_ptr);

static srv_wgtmgr_result_enum srv_wgtmgr_translate_error(int ret);
#ifdef __WGTMGR_SAVE_ICON_FILE__
static void srv_wgtmgr_backup_icon_file(U16 id);
static void srv_wgtmgr_delete_icon_file(U16 id);
#endif
static void srv_wgtmgr_pre_install_wgt_rsp_hdlr(void *msg);
static void srv_wgtmgr_get_all_wgt_version_rsp_hdlr(void *msg);
static void srv_wgtmgr_get_all_wgt_name_rsp_hdlr(void *msg);
static void srv_wgtmgr_install_wgt_rsp_hdlr(void *msg, S32 mod_src, void *ilm_p);
static void srv_wgtmgr_install_wgt_cont_rsp_hdlr(void *msg);
static void srv_wgtmgr_delete_wgt_rsp_hdlr(void *msg);
static void srv_wgtmgr_delete_wgt_multiple_rsp_hdlr(void *msg);
static void srv_wgtmgr_certmain_ready_cnf_hdlr(void *msg);
static void srv_wgtmgr_send_pre_install_wgt_req(S32 start_index);

/************************************************************************/
/* External Function Declaration                                        */
/************************************************************************/
extern void widget_unload_widget(int instance_id);
extern int gadget_adp_mgr_record_last_modified_time(int instance_id);

/************************************************************************/
/* Golbal Variable                                                      */
/************************************************************************/
static widget_mgr_preload_wgt_table_struct *g_srv_wgtmgr_preload_wgt_table_p = NULL;

#ifdef __WGTMGR_MAIN_MENU_SUPPORT__
static CHAR g_widget_install_app_name[SRV_WGTMGR_MAX_WGT_NAME_LEN];
#endif

/************************************************************************/
/* Local Function Definition                                            */
/************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_send_message
 * DESCRIPTION
 *  This function is used to send primitive
 * PARAMETERS
 *  dest_mod :[IN]
 *  msg_id :[IN]
 *  local_param_ptr :[IN]
 *  peer_buf_ptr :[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_send_message(
    module_type dest_mod, 
    msg_type msg_id,
    void *local_param_ptr, 
    void *peer_buf_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = local_param_ptr;
    ilm_ptr->msg_id         = msg_id;
    ilm_ptr->peer_buff_ptr  = peer_buf_ptr;

    SEND_ILM(MOD_MMI, dest_mod, GADGET_MMI_SAP, ilm_ptr);
}



/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_translate_error
 * DESCRIPTION
 *  This function is used to translate error code
 * PARAMETERS
 *  ret: [IN] the error code in WIDGET task
 * RETURNS
 *  the error code in Widget Manager Service
 *****************************************************************************/
static srv_wgtmgr_result_enum srv_wgtmgr_translate_error(int ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    srv_wgtmgr_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (ret)
    {
        case WIDGET_MGR_RET_OK:
            result = SRV_WGTMGR_RET_OK;
            break;

        case WIDGET_MGR_RET_MEM_NOT_ENOUGH:
            result = SRV_WGTMGR_RET_MEM_NOT_ENOUGH;
            break;

        case WIDGET_MGR_RET_WGT_CURRUPTED:
            result = SRV_WGTMGR_RET_WGT_CORRUPTED;
            break;

        case WIDGET_MGR_RET_WGT_UNTRUSTED:
            result = SRV_WGTMGR_RET_WGT_UNTRUSTED;
            break;

        case WIDGET_MGR_RET_WGT_INSTALLED:
            result = SRV_WGTMGR_RET_WGT_INSTALLED;
            break;

        case WIDGET_MGR_RET_FILE_NOT_EXIST:
            result = SRV_WGTMGR_RET_FILE_NOT_EXIST;
            break;

        case WIDGET_MGR_RET_FILE_NOT_VALID:
            result = SRV_WGTMGR_RET_WGT_NOT_VALID;
            break;

        case WIDGET_MGR_RET_EXCEED_MAX_INSTALLED_NUM:
            result = SRV_WGTMGR_RET_EXCEED_MAX_INSTALLED_NUM;
            break;

        case WIDGET_MGR_RET_OLD_VERSION:
            result = SRV_WGTMGR_RET_OLD_VERSION;
            break;
 
        case WIDGET_MGR_RET_NEW_VERSION:
            result = SRV_WGTMGR_RET_NEW_VERSION;
            break;

        case WIDGET_MGR_RET_ALREADY_INSTALLED:
            result = SRV_WGTMGR_RET_ALREADY_INSTALLED;
            break;

        case WIDGET_MGR_RET_DISK_SPACE_NOT_ENOUGH:
            result = SRV_WGTMGR_RET_DISK_SPACE_NOT_ENOUGH;
            break;

        case WIDGET_MGR_RET_CONTINUE:
            result = SRV_WGTMGR_RET_CONTINUE;
            break;


        default:
            result = SRV_WGTMGR_RET_ERROR;
            break;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_create_stamp_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id: [IN] widget id
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_create_stamp_file(U16 id, U32 install_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    char drive = srv_wgtmgr_get_drive_letter((srv_wgtmgr_wgt_drive_enum)g_srv_wgtmgr_cntx_p->dwgt_drive[id]);
    WCHAR dst_path[50];
    S32 fd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(dst_path, "%c:\\@gadget\\%03d\\%d", drive, id, install_time);
    fd = FS_Open(dst_path, FS_READ_WRITE | FS_CREATE);
    FS_Close(fd);
}

#ifdef __WGTMGR_SAVE_ICON_FILE__
/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_backup_icon_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id: [IN] widget id
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_backup_icon_file(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    char drive = srv_wgtmgr_get_drive_letter((srv_wgtmgr_wgt_drive_enum)g_srv_wgtmgr_cntx_p->dwgt_drive[id]);
    WCHAR icon_path[30];
    WCHAR dst_path[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(icon_path, "%c:\\@gadget\\%03d\\@icon.png", drive, id);
    kal_wsprintf(dst_path, "Z:\\@wgtmgr\\icon\\%03d.png", id);
    FS_Move(icon_path, dst_path, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_delete_icon_file
 * DESCRIPTION
 *  
 * PARAMETERS
 *  id: [IN] widget id
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_delete_icon_file(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
    WCHAR dst_path[30];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wsprintf(dst_path, "Z:\\@wgtmgr\\icon\\%03d.png", id);
    FS_Delete(dst_path);
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_pre_install_wgt_rsp_hdlr
 * DESCRIPTION
 *  This is the handler of response of WIDGET_MGR_PRE_INSTALL_WGT_RSP
 * PARAMETERS
 *  msg: [IN] the local parameter of response
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_pre_install_wgt_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_pre_install_wgt_rsp_struct *rsp = (widget_mgr_pre_install_wgt_rsp_struct *)msg;
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    widget_mgr_preload_wgt_table_struct *preload_table_p = g_srv_wgtmgr_preload_wgt_table_p;
    widget_mgr_preload_wgt_table_struct *rsp_preload_table_p = &(rsp->preload_wgts);
    srv_wgtmgr_result_enum ret;
    widget_mgr_wgt_info_struct *wgt_p;
    srv_wgtmgr_wgt_item_struct wgt_item;
    U16 wgt_id;
    S16 error;
    S32 i;    
    U8 done = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (preload_table_p == NULL)
    {
        preload_table_p = (widget_mgr_preload_wgt_table_struct *)OslMalloc(sizeof(widget_mgr_preload_wgt_table_struct));
        preload_table_p->pre_load_wgt_num = 0;
        g_srv_wgtmgr_preload_wgt_table_p = preload_table_p;
    }

    if (rsp->preload_wgts.pre_load_wgt_num > 0)
    {
        for (i = 0; i < rsp->preload_wgts.pre_load_wgt_num; i++)
        {
            widget_mgr_preload_wgt_struct *preload_wgt_p = &(preload_table_p->pre_load_wgt_table[preload_table_p->pre_load_wgt_num]);
            memcpy(preload_wgt_p, &(rsp_preload_table_p->pre_load_wgt_table[i]), sizeof(widget_mgr_preload_wgt_struct));
            preload_table_p->pre_load_wgt_num++;
        }
    }

    ret = srv_wgtmgr_translate_error(rsp->result);
    if (rsp->num > 0)
    {
        /* read installed seqence from NVRAM Cache */
        for (i = 0; i < rsp->num; i++)
        {
            wgt_p = &(rsp->wgt[i]);
            wgt_id = wgt_p->wgt_id;

            /* the default status of a newly installed widget is enabled */
            if (srv_wgtmgr_get_enabled_wgt_num() < SRV_WGTMGT_MAX_ENABLED_WGT_NUM)
            {
                cntx_p->dwgt_status[wgt_id] = SRV_WGTMGR_WGT_STATUS_ENABLED;
            }
            else
            {
                cntx_p->dwgt_status[wgt_id] = SRV_WGTMGR_WGT_STATUS_DISABLED;
            }

            cntx_p->dwgt_drive[wgt_id] = wgt_p->drive;

            /* assign the installed sequence, this is for sort by installed time */
            wgt_item.install_time = srv_wgtmgr_get_current_time_in_sec();

            /* assign size of widget folder */
		    wgt_item.size = wgt_p->size;

            /* translate widget attribute */
            wgt_item.attribute = wgt_p->attribute;

            /* translate */
            wgt_item.drive = wgt_p->drive;

            wgt_item.idle_width = wgt_p->idle_width;

            wgt_item.idle_height = wgt_p->idle_height;

            wgt_item.max_resolution = wgt_p->max_resolution;

        #ifdef __WGTMGR_MAIN_MENU_SUPPORT__
            if (wgt_p->mainmenu_support)
            {
                wgt_item.attribute |= SRV_WGTMGR_ATTR_MAINMENU;
            }
        #endif

            /* save widget info to nvram */
            srv_wgtmgr_save_wgt_info_to_nvram(wgt_id, &wgt_item);

            /* create a file for check identity */
            srv_wgtmgr_create_stamp_file(wgt_id, wgt_item.install_time);

            srv_wgtmgr_save_wgt_name_and_version_to_file(wgt_id, wgt_p->name, wgt_p->version);

        #ifdef __WGTMGR_SAVE_ICON_FILE__
            srv_wgtmgr_backup_icon_file(wgt_id);
        #endif

        #ifdef __WGTMGR_MAIN_MENU_SUPPORT__
            /* if widget has defined main menu support attribute */
            if (wgt_p->mainmenu_support)   
            {
                sprintf(g_widget_install_app_name, "widget.mtk.%d", wgt_id);
                srv_appmgr_update_app_info(g_widget_install_app_name, EVT_ID_SRV_APPMGR_INSTALL_PACKAGE);
            }
        #endif

            gadget_adp_mgr_record_last_modified_time(wgt_id);
        }

        /* save widget status to nvram */
        srv_wgtmgr_save_wgt_status_to_nvram();
    }

    if (ret == SRV_WGTMGR_RET_OK)
    {
        srv_wgtmgr_notify_evt_struct event;

        WriteValue(NVRAM_WGTMGR_PRE_INSTALL_DONE, &done, DS_BYTE, &error);        
        srv_wgtmgr_set_data_need_update(SRV_WGTMGR_UPDATE_NAME | SRV_WGTMGR_UPDATE_VERSION);

        MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_WGTMGR_FINISH_PRE_INSATLL_WIDGET_IND);
        MMI_FRM_CB_EMIT_POST_EVENT(&event);
    }
    else if (ret == SRV_WGTMGR_RET_CONTINUE)
    {
        srv_wgtmgr_send_pre_install_wgt_req(rsp->next_index);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_all_wgt_version_rsp_hdlr
 * DESCRIPTION
 *  This is the handler of response of WIDGET_MGR_GET_ALL_WGT_VERSION_RSP
 * PARAMETERS
 *  msg: [IN] the local parameter of response
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_get_all_wgt_version_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* has received the response, set request flag to false */
	cntx_p->req_table.send_version_req = MMI_FALSE;

    /* set need_update_name to false since it has been updated */
    if (cntx_p->need_update_data & SRV_WGTMGR_UPDATE_VERSION)
    {
        cntx_p->need_update_data ^= SRV_WGTMGR_UPDATE_VERSION;
        WriteValue(NVRAM_WGTMGR_WGT_NEED_UPDATE_NAME, &(cntx_p->need_update_data), DS_BYTE, &error);
    }

    srv_wgtmgr_start_cont();
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_wgt_detail_rsp_hdlr
 * DESCRIPTION
 *  This is the handler of response of WIDGET_MGR_GET_WGT_DETAIL_RSP
 * PARAMETERS
 *  msg: [IN] the local parameter of response
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_get_wgt_detail_rsp_hdlr(void *msg, S32 mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    srv_wgtmgr_wgt_detail_struct *info;
    widget_mgr_get_wgt_detail_rsp_struct *rsp = (widget_mgr_get_wgt_detail_rsp_struct *)msg;
    ilm_struct  *ilm_ptr = (ilm_struct *)ilm_p;
    widget_mgr_get_wgt_detail_rsp_pb_struct *peer_buff;
    srv_wgtmgr_result_enum ret;
    srv_wgtmgr_get_wgt_detail_cb_func_ptr callback = cntx_p->cb_table.get_wgt_detail_cb;
    U16 len;
    void *user_data = cntx_p->cb_table.get_wgt_detail_cb_user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p->cb_table.get_wgt_detail_cb = NULL;

    if (callback != NULL)
    {
        info = (srv_wgtmgr_wgt_detail_struct *)OslMalloc(sizeof(srv_wgtmgr_wgt_detail_struct));
        ret = srv_wgtmgr_translate_error(rsp->result);
        info->result = ret;
        info->wgt_id = rsp->wgt_id;

        if (ret == SRV_WGTMGR_RET_OK)
        {
            app_ucs2_strcpy((kal_int8*)info->wgt_name, (const kal_int8*)rsp->name);
            app_ucs2_strcpy((kal_int8*)info->wgt_version, (const kal_int8*)rsp->version);

            peer_buff = (widget_mgr_get_wgt_detail_rsp_pb_struct *)get_pdu_ptr(ilm_ptr->peer_buff_ptr, &len);

            app_ucs2_strcpy((kal_int8*)info->wgt_author, (const kal_int8*)peer_buff->author);
            app_ucs2_strcpy((kal_int8*)info->wgt_copyright, (const kal_int8*)peer_buff->copyright);
        }		
        callback(info, user_data);
        OslMfree(info);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_all_wgt_name_rsp_hdlr
 * DESCRIPTION
 *  This is the handler of response of WIDGET_MGR_GET_ALL_WGT_NAME_RSP
 * PARAMETERS
 *  msg: [IN] the local parameter of response
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_get_all_wgt_name_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* has received the response, set request flag to false */
	cntx_p->req_table.send_name_req = MMI_FALSE;
	
    /* set need_update_name to false since it has been updated */
    if (cntx_p->need_update_data & SRV_WGTMGR_UPDATE_NAME)
   	{
        cntx_p->need_update_data ^= SRV_WGTMGR_UPDATE_NAME;
        WriteValue(NVRAM_WGTMGR_WGT_NEED_UPDATE_NAME, &(cntx_p->need_update_data), DS_BYTE, &error);
    }

    /* write widget language to NVRAM */
    WriteValue(NVRAM_WGTMGR_WGT_PHONE_LANG, &(cntx_p->wgt_lang), DS_DOUBLE, &error);

    srv_wgtmgr_start_cont();

}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_verify_wgt_rsp_hdlr
 * DESCRIPTION
 *  This is the message handler of WIDGET_MGR_VERIFY_WGT_RSP
 * PARAMETERS
 *  msg: [IN] the local parameter of response
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_install_wgt_rsp_hdlr(void *msg, S32 mod_src, void *ilm_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_install_wgt_rsp_struct *rsp = (widget_mgr_install_wgt_rsp_struct *)msg;
    ilm_struct  *ilm_ptr = (ilm_struct *)ilm_p;
    widget_mgr_install_wgt_rsp_pb_struct *peer_buff;
    srv_wgtmgr_install_wgt_result_struct info;
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    srv_wgtmgr_cb_table_struct *cb_table_p = &(cntx_p->cb_table);
    srv_wgtmgr_install_wgt_cont_cb_func_ptr callback = cb_table_p->install_wgt_cont_cb;
    void * user_data = cb_table_p->install_wgt_cont_cb_user_data;
    srv_wgtmgr_result_enum ret;
    S16 wgt_id = -1;
    U16 len;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((callback != NULL) && (cntx_p->job_id == rsp->job_id))
    {
        ret = srv_wgtmgr_translate_error(rsp->result);
        info.result = ret;
        if (ret == SRV_WGTMGR_RET_OK ||
			ret == SRV_WGTMGR_RET_ALREADY_INSTALLED ||
			ret == SRV_WGTMGR_RET_NEW_VERSION ||
			ret == SRV_WGTMGR_RET_OLD_VERSION)
        {

            wgt_id = rsp->wgt_id;
            app_ucs2_strcpy((kal_int8*)info.wgt_name, (const kal_int8*)rsp->name);
            app_ucs2_strcpy((kal_int8*)info.wgt_version_install, (const kal_int8*)rsp->version_install);

            peer_buff = (widget_mgr_install_wgt_rsp_pb_struct *)get_pdu_ptr(ilm_ptr->peer_buff_ptr, &len);

            app_ucs2_strcpy((kal_int8*)info.wgt_author, (const kal_int8*)peer_buff->author);
            app_ucs2_strcpy((kal_int8*)info.wgt_copyright, (const kal_int8*)peer_buff->copyright);
            cntx_p->updating_wgt_id = wgt_id;

            /* rule out the case that the installation is falsely considered as upadte */
            if (wgt_id >= 0 && cntx_p->dwgt_status[wgt_id] == SRV_WGTMGR_WGT_STATUS_NULL)
            {
                info.result = SRV_WGTMGR_RET_OK;
            }

            /* update a widget */
            if (ret != SRV_WGTMGR_RET_OK)
            {
                app_ucs2_strcpy((kal_int8*)info.wgt_version_original, (const kal_int8*)rsp->version_original);
            }
        }		

        cb_table_p->install_wgt_cont_cb = NULL;
        cb_table_p->install_wgt_cont_cb_user_data= NULL;
        callback(wgt_id, &info, user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_install_wgt_cont_rsp_hdlr
 * DESCRIPTION
 *  This is the message handler of WIDGET_MGR_INSTALL_WGT_CONT_RSP
 * PARAMETERS
 *  msg: [IN] the local parameter of response
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_install_wgt_cont_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_install_wgt_cont_rsp_struct *rsp = (widget_mgr_install_wgt_cont_rsp_struct *)msg;
    srv_wgtmgr_wgt_item_struct wgt_item;
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    srv_wgtmgr_install_wgt_finished_cb_func_ptr callback = cntx_p->cb_table.install_wgt_finished_cb;
    void * user_data = cntx_p->cb_table.install_wgt_finished_cb_user_data;
    srv_wgtmgr_result_enum ret;
    S16 error;
    S16 wgt_id = rsp->wgt_id;
    srv_wgtmgr_wgt_item_struct *dwgt_info;
    U8 attr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_wgtmgr_translate_error(rsp->result);
    if (ret == SRV_WGTMGR_RET_OK)
    {
        /* save widget name and version to file */
        srv_wgtmgr_save_wgt_name_and_version_to_file(wgt_id, rsp->name, rsp->version);

        /* assign the installed sequence, this is for sort by installed time */
        wgt_item.install_time = srv_wgtmgr_get_current_time_in_sec();

        /* assign size of widget folder */
        wgt_item.size = rsp->size;

        /* assign the drive which widget is installed */
        wgt_item.drive = rsp->drive;

        wgt_item.idle_width = rsp->idle_width;

        wgt_item.idle_height= rsp->idle_height;

        wgt_item.max_resolution = rsp->max_resolution;

        /* translate widget attribute */
        if (cntx_p->dwgt_status[wgt_id] == SRV_WGTMGR_WGT_STATUS_UPDATING)
        {
            dwgt_info = (srv_wgtmgr_wgt_item_struct*)OslMalloc(sizeof(srv_wgtmgr_wgt_item_struct) * SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM);
            if (dwgt_info == NULL)
            {
                MMI_ASSERT(0);
            }

            /* read downloaded widget info from nvram */
            srv_wgtmgr_read_wgt_info_from_nvram(dwgt_info);

            wgt_item.attribute = rsp->attribute;

            attr = dwgt_info[wgt_id].attribute;

            if (attr & SRV_WGTMGR_ATTR_UNDELETABLE)
            {
                wgt_item.attribute |= SRV_WGTMGR_ATTR_UNDELETABLE;
            }

            if (attr & SRV_WGTMGR_ATTR_NOT_DISABLE)
            {
                wgt_item.attribute |= SRV_WGTMGR_ATTR_NOT_DISABLE;
            }

            OslMfree(dwgt_info);
        }
        else
        {			
            wgt_item.attribute = rsp->attribute;
        }
        
#ifdef __WGTMGR_MAIN_MENU_SUPPORT__
        if (rsp->mainmenu_support)
        {
            wgt_item.attribute |= SRV_WGTMGR_ATTR_MAINMENU;
        }
#endif
        /* save widget info to nvram */
        srv_wgtmgr_save_wgt_info_to_nvram(wgt_id, &wgt_item);

        /* set need_update_name to true if necessary */
        if (strcmp(cntx_p->wgt_lang, (const char *)Get_Current_Lang_CountryCode()) != 0)
        {
            if (!(cntx_p->need_update_data & SRV_WGTMGR_UPDATE_NAME))
   	        {
                cntx_p->need_update_data |= SRV_WGTMGR_UPDATE_NAME;
                WriteValue(NVRAM_WGTMGR_WGT_NEED_UPDATE_NAME, &(cntx_p->need_update_data), DS_BYTE, &error);
            }
        }

        /* the default status of a newly installed widget is enabled */
        if (srv_wgtmgr_get_enabled_wgt_num() < SRV_WGTMGT_MAX_ENABLED_WGT_NUM)
        {
            cntx_p->dwgt_status[wgt_id] = SRV_WGTMGR_WGT_STATUS_ENABLED;
        }
        else
        {
            cntx_p->dwgt_status[wgt_id] = SRV_WGTMGR_WGT_STATUS_DISABLED;
        }
        /* save widget status to nvram */
        srv_wgtmgr_save_wgt_status_to_nvram();

        /* update drive info in global context */
        cntx_p->dwgt_drive[wgt_id] = rsp->drive;

        /* create a file for check identity */
        srv_wgtmgr_create_stamp_file(wgt_id, wgt_item.install_time);

#ifdef __WGTMGR_SAVE_ICON_FILE__
        srv_wgtmgr_backup_icon_file(wgt_id);
#endif

#ifdef __WGTMGR_MAIN_MENU_SUPPORT__
        /* if widget has defined main menu support attribute */
        if (rsp->mainmenu_support)   
		{
            sprintf(g_widget_install_app_name, "widget.mtk.%d", wgt_id);
            srv_appmgr_update_app_info(g_widget_install_app_name, EVT_ID_SRV_APPMGR_INSTALL_PACKAGE);
        }
#endif
        if (gadget_adp_mgr_record_last_modified_time(wgt_id) == 0)
        {
            ret = SRV_WGTMGR_RET_MEM_NOT_ENOUGH;
        }
    }

    /* ensure @gadget folder is in correct status */
    srv_wgtmgr_recover_gadget_folder();

    if (callback != NULL &&
        cntx_p->job_id == rsp->job_id)
    {                
        cntx_p->cb_table.install_wgt_finished_cb = NULL;
        cntx_p->cb_table.install_wgt_finished_cb_user_data = NULL;
        callback(ret, user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_delete_wgt_rsp_hdlr
 * DESCRIPTION
 *  This is the message handler of WIDGET_MGR_DELETE_WGT_RSP
 * PARAMETERS
 *  msg: [IN] the local parameter of response
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_delete_wgt_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_delete_wgt_rsp_struct *rsp = (widget_mgr_delete_wgt_rsp_struct *)msg;
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    srv_wgtmgr_delete_wgt_cb_func_ptr callback = cntx_p->cb_table.delete_wgt_cb;
    void * user_data = cntx_p->cb_table.delete_wgt_cb_user_data;
    srv_wgtmgr_result_enum ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set widget status to NULL and save to nvram */
    ret = srv_wgtmgr_translate_error(rsp->result);
    if (ret == SRV_WGTMGR_RET_OK)
    {
        cntx_p->dwgt_status[rsp->wgt_id] = SRV_WGTMGR_WGT_STATUS_NULL;
        srv_wgtmgr_save_wgt_status_to_nvram();
    }

    if (callback != NULL &&
        cntx_p->job_id == rsp->job_id)
    {
        cntx_p->cb_table.delete_wgt_cb = NULL;
        cntx_p->cb_table.delete_wgt_cb_user_data = NULL;	
        callback(user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_delete_wgt_multiple_rsp_hdlr
 * DESCRIPTION
 *  This is the message handler of WIDGET_MGR_DELETE_WGT_MULTIPLE_RSP
 * PARAMETERS
 *  msg: [IN] the local parameter of response
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_delete_wgt_multiple_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_delete_wgt_multiple_rsp_struct *rsp = (widget_mgr_delete_wgt_multiple_rsp_struct *)msg;    
    U8 *status = g_srv_wgtmgr_cntx_p->dwgt_status;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* set widget status to NULL and save to nvram */
    for (i = 0; i < rsp->num; i++)
    {
        status[rsp->wgt_id[i]] = SRV_WGTMGR_WGT_STATUS_NULL;
    }
    srv_wgtmgr_save_wgt_status_to_nvram();
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_delete_wgt_multiple_rsp_hdlr
 * DESCRIPTION
 *  This is the message handler of WIDGET_MGR_DELETE_WGT_MULTIPLE_RSP
 * PARAMETERS
 *  msg: [IN] the local parameter of response
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_certmain_ready_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_send_pre_install_wgt_req(0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_send_pre_install_wgt_req
 * DESCRIPTION
 *  This function is used to send MSG_ID_WIDGET_MGR_PRE_INSTALL_WGT_REQ to WIDGET task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_wgtmgr_send_pre_install_wgt_req(S32 start_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_pre_install_wgt_req_struct *req = (widget_mgr_pre_install_wgt_req_struct *)construct_local_para(sizeof(widget_mgr_pre_install_wgt_req_struct), TD_RESET);    
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req->start_index = start_index;
    srv_wgtmgr_send_message(MOD_GADGET, MSG_ID_WIDGET_MGR_PRE_INSTALL_WGT_REQ, req, NULL);
}


/************************************************************************/
/* Global Function Definition                                            */
/************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_protocol_event_handler
 * DESCRIPTION
 *  This function is used to set protocol event handler 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_set_protocol_event_handler()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_MGR_PRE_INSTALL_WGT_RSP,      (PsIntFuncPtr)srv_wgtmgr_pre_install_wgt_rsp_hdlr,      MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_MGR_GET_ALL_WGT_NAME_RSP,     (PsIntFuncPtr)srv_wgtmgr_get_all_wgt_name_rsp_hdlr,     MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_MGR_GET_ALL_WGT_VERSION_RSP,  (PsIntFuncPtr)srv_wgtmgr_get_all_wgt_version_rsp_hdlr,  MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_MGR_INSTALL_WGT_RSP,          (PsIntFuncPtr)srv_wgtmgr_install_wgt_rsp_hdlr,          MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_MGR_INSTALL_WGT_CONT_RSP,     (PsIntFuncPtr)srv_wgtmgr_install_wgt_cont_rsp_hdlr,     MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_MGR_DELETE_WGT_RSP,           (PsIntFuncPtr)srv_wgtmgr_delete_wgt_rsp_hdlr,           MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_MGR_DELETE_WGT_MULTIPLE_RSP,  (PsIntFuncPtr)srv_wgtmgr_delete_wgt_multiple_rsp_hdlr,  MMI_FALSE);
    mmi_frm_set_protocol_event_handler(MSG_ID_CERTMAN_READY_SUBSCRIBE_CNF,         (PsIntFuncPtr)srv_wgtmgr_certmain_ready_cnf_hdlr,  MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_WIDGET_MGR_GET_WGT_DETAIL_RSP,       (PsIntFuncPtr)srv_wgtmgr_get_wgt_detail_rsp_hdlr,  MMI_TRUE);

}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_send_name_req
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_GET_ALL_WGT_NAME_REQ to WIDGET task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_send_name_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_get_all_wgt_name_req_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (widget_mgr_get_all_wgt_name_req_struct*) construct_local_para(sizeof(widget_mgr_get_all_wgt_name_req_struct), TD_RESET);
    req->job_id = ++g_srv_wgtmgr_cntx_p->job_id;
    app_ucs2_strcpy((kal_int8 *)req->data_path, (const kal_int8 *)g_srv_wgtmgr_name_data);
    app_ucs2_strcpy((kal_int8 *)req->guard_path, (const kal_int8 *)g_srv_wgtmgr_name_guard);

    srv_wgtmgr_send_message(MOD_GADGET, MSG_ID_WIDGET_MGR_GET_ALL_WGT_NAME_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_send_version_req
 * DESCRIPTION
 *
 * PARAMETERS
 * 
 * RETURNS
 *
 *****************************************************************************/
void srv_wgtmgr_send_version_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_get_all_wgt_version_req_struct *req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* compose ILM */
    req = (widget_mgr_get_all_wgt_version_req_struct*) construct_local_para(sizeof(widget_mgr_get_all_wgt_version_req_struct), TD_RESET);
    req->job_id = ++g_srv_wgtmgr_cntx_p->job_id;
    app_ucs2_strcpy((kal_int8*)req->data_path, (const kal_int8*)g_srv_wgtmgr_version_data);
    app_ucs2_strcpy((kal_int8*)req->guard_path, (const kal_int8*)g_srv_wgtmgr_version_guard);

    srv_wgtmgr_send_message(MOD_GADGET, MSG_ID_WIDGET_MGR_GET_ALL_WGT_VERSION_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_wgt_detail
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_DELETE_WGT_REQ to WIDGET task
 * PARAMETERS
 *  id: [IN] the id of widget to delete
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_get_downloaded_wgt_detail(S32 id, srv_wgtmgr_get_wgt_detail_cb_func_ptr callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    widget_mgr_get_wgt_detail_req_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        cntx_p->cb_table.get_wgt_detail_cb = callback;
        cntx_p->cb_table.get_wgt_detail_cb_user_data = user_data;
        req = (widget_mgr_get_wgt_detail_req_struct*) construct_local_para(sizeof(widget_mgr_get_wgt_detail_req_struct), TD_RESET);
        req->wgt_id = id;
        srv_wgtmgr_send_message(MOD_GADGET, MSG_ID_WIDGET_MGR_GET_WGT_DETAIL_REQ, req, NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_install_wgt
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_INSTALL_WGT_REQ to WIDGET task
 * PARAMETERS
 *  path: [IN] the path of widget file to install
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_install_wgt(WCHAR *path, srv_wgtmgr_install_wgt_cont_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_install_wgt_req_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_wgtmgr_cntx_p->cb_table.install_wgt_cont_cb = callback;
    g_srv_wgtmgr_cntx_p->cb_table.install_wgt_cont_cb_user_data = user_data;

    req = (widget_mgr_install_wgt_req_struct*) construct_local_para(sizeof(widget_mgr_install_wgt_req_struct), TD_RESET);
    req->job_id = ++g_srv_wgtmgr_cntx_p->job_id;
    mmi_chset_ucs2_to_utf8_string((kal_uint8 *)req->path, sizeof(req->path), (kal_uint8 *)path);
    srv_wgtmgr_send_message(MOD_GADGET, MSG_ID_WIDGET_MGR_INSTALL_WGT_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_install_wgt_cont
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_INSTALL_WGT_CONT_REQ to WIDGET task
 * PARAMETERS
 *  path: [IN] the path of widget file to install
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_install_wgt_cont(srv_wgtmgr_op_enum op, srv_wgtmgr_wgt_drive_enum drive, srv_wgtmgr_install_wgt_finished_cb_func_ptr callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_install_wgt_cont_req_struct *req = NULL;
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p->cb_table.install_wgt_finished_cb = callback;
    cntx_p->cb_table.install_wgt_cont_cb_user_data = user_data;

    req = (widget_mgr_install_wgt_cont_req_struct*) construct_local_para(sizeof(widget_mgr_install_wgt_cont_req_struct), TD_RESET);
    req->job_id = ++cntx_p->job_id;

    /* assign different parameter according to type of operation*/
    if (op == SRV_WGTMGR_INSTALL_CONT)
    {
        if (drive == SRV_WGTMGR_DRIVE_PUBLIC)
        {
            req->drive = WIDGET_MGR_DRIVE_PUBLIC;
        }
        else
        {
            req->drive = WIDGET_MGR_DRIVE_MEMORY_CARD;
        }	

        /* change widget status to updating */
        if (cntx_p->updating_wgt_id >= 0)
        {
            cntx_p->dwgt_status[cntx_p->updating_wgt_id] = SRV_WGTMGR_WGT_STATUS_UPDATING;
            srv_wgtmgr_save_wgt_status_to_nvram();
        }
        req->op = WIDGET_MGR_INSTALL_CONT;
    }
    else
    {
        req->op = WIDGET_MGR_INSTALL_CANCEL;
    }
    
    srv_wgtmgr_send_message(MOD_GADGET, MSG_ID_WIDGET_MGR_INSTALL_WGT_CONT_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_delete_wgt
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_DELETE_WGT_REQ to WIDGET task
 * PARAMETERS
 *  id: [IN] the id of widget to delete
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_delete_wgt(S32 id, srv_wgtmgr_delete_wgt_cb_func_ptr callback, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cntx_p->cb_table.delete_wgt_cb = callback;
    cntx_p->cb_table.delete_wgt_cb_user_data = user_data;

    widget_unload_widget(id);

    srv_wgtmgr_delete_wgt_int(id);

    if (cntx_p->is_start == MMI_TRUE)
    {
        srv_wgtmgr_sort_wgt();
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_delete_wgt_int
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_DELETE_WGT_REQ to WIDGET task
 * PARAMETERS
 *  id: [IN] the id of widget to delete
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_delete_wgt_int(U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_cntx_struct *cntx_p = g_srv_wgtmgr_cntx_p;
    srv_wgtmgr_notify_evt_struct event;
#ifdef __WGTMGR_MAIN_MENU_SUPPORT__
    srv_wgtmgr_wgt_item_struct wgt_info;
#endif 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Set widget status to DELETING */
    cntx_p->dwgt_status[id] = SRV_WGTMGR_WGT_STATUS_DELETING;

    /* Save widget status to NVRAM */
    srv_wgtmgr_save_wgt_status_to_nvram();

#ifdef __WGTMGR_MAIN_MENU_SUPPORT__
    /* if widget has defined main menu support attribute */
    srv_wgtmgr_read_wgt_info_from_nvram_by_id(id, &wgt_info);    
   
    if (wgt_info.attribute & SRV_WGTMGR_ATTR_MAINMENU)
    {
        wgt_info.attribute &= !SRV_WGTMGR_ATTR_MAINMENU;
        sprintf(g_widget_install_app_name, "widget.mtk.%d", id);
        srv_appmgr_update_app_info(g_widget_install_app_name, EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE);
    }
    srv_wgtmgr_save_wgt_info_to_nvram(id, &wgt_info);
#endif 

    /* Send delete request to WIDGET */
    srv_wgtmgr_send_delete_wgt_req(id);

#ifdef __WGTMGR_SAVE_ICON_FILE__
    /* Remove the icon in system drive */
    srv_wgtmgr_delete_icon_file(id);
#endif

    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_WGTMGR_DELETE_WIDGET_IND);
    event.id = id;
    MMI_FRM_CB_EMIT_POST_EVENT(&event);
}



/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_send_delete_wgt_req
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_DELETE_WGT_REQ to WIDGET task
 * PARAMETERS
 *  instance_id: [IN] the instance id of widget to delete
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_send_delete_wgt_req(U16 instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_delete_wgt_req_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (widget_mgr_delete_wgt_req_struct*) construct_local_para(sizeof(widget_mgr_delete_wgt_req_struct), TD_RESET);
    req->job_id = ++g_srv_wgtmgr_cntx_p->job_id;
    req->wgt_id = instance_id;

    srv_wgtmgr_send_message(MOD_GADGET, MSG_ID_WIDGET_MGR_DELETE_WGT_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_send_delete_wgt_multiple_req
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_DELETE_WGT_REQ to WIDGET task
 * PARAMETERS
 *  instance_id: [IN] the instance id of widget to delete
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_send_delete_wgt_multiple_req(U8 num, U16 *instance_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_delete_wgt_multiple_req_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (widget_mgr_delete_wgt_multiple_req_struct*) construct_local_para(sizeof(widget_mgr_delete_wgt_multiple_req_struct), TD_RESET);
    req->num = num;
    kal_mem_cpy(req->wgt_id, instance_id, sizeof(U16) * num);

    srv_wgtmgr_send_message(MOD_GADGET, MSG_ID_WIDGET_MGR_DELETE_WGT_MULTIPLE_REQ, req, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_shutdown_evt_hdlr
 * DESCRIPTION
 *  This function is used to send MSG_ID_WIDGET_SHUTDOWN_IND to WIDGET task
 * PARAMETERS
 *  event
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_wgtmgr_shutdown_evt_hdlr(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_send_message(MOD_GADGET, MSG_ID_WIDGET_SHUTDOWN_IND, NULL, NULL);
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_preinstall_widget
 * DESCRIPTION
 *  This function is to check if a id is valid
 * PARAMETERS
 *  id:  [IN] data account id 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_wgtmgr_preinstall_widget(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_wgtmgr_is_preinstall_widget_finished() == MMI_TRUE)
    {
        return MMI_TRUE;
    }
	
#ifdef __COSMOS_MMI_PACKAGE__
    vapp_widget_init_evt_hdlr(NULL);
#else
    widget_init_evt_hdlr(NULL);
#endif

	srv_wgtmgr_init();
    
    mmi_frm_send_ilm(MOD_CERTMAN, MSG_ID_MMI_READY_NOTIFY_REQ, NULL, NULL);
    certman_send_ready_subscribe_req(MOD_MMI);

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_preload_widget_num
 * DESCRIPTION
 *  This function is to get number of preload widgets
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_wgtmgr_get_preload_widget_num(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_wgtmgr_preload_wgt_table_p == NULL)
    {
        return 0;
    }

    return g_srv_wgtmgr_preload_wgt_table_p->pre_load_wgt_num;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_preload_widget_list
 * DESCRIPTION
 *  This function is to get list of preload widgets
 * PARAMETERS
 *  list:  [IN/OUT] widget list
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_wgtmgr_get_preload_widget_list(srv_wgtmgt_preload_wgt_struct *list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_mgr_preload_wgt_table_struct *table_p = g_srv_wgtmgr_preload_wgt_table_p;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (table_p == NULL)
    {
        return -1;
    }

    for (i = 0; i < table_p->pre_load_wgt_num; i++)
    {
        list[i].id = table_p->pre_load_wgt_table[i].id;
        list[i].page = table_p->pre_load_wgt_table[i].page;
        list[i].x_pos = table_p->pre_load_wgt_table[i].x_pos;
        list[i].y_pos = table_p->pre_load_wgt_table[i].y_pos;
    }

    OslMfree(table_p);
    g_srv_wgtmgr_preload_wgt_table_p = NULL;
    return i;
}

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_bearer_disconnect
 * DESCRIPTION
 *  This function is used to send MSG_ID_WIDGET_BEARER_DISCONNECT_IND to WIDGET task
 * PARAMETERS
 *  event
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_bearer_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_wgtmgr_send_message(MOD_GADGET, MSG_ID_WIDGET_BEARER_DISCONNECT_IND, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_bearer_switch
 * DESCRIPTION
 *  This function is used to send MSG_ID_WIDGET_BEARER_SWITCH_IND to WIDGET task
 * PARAMETERS
 *  event
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wgtmgr_bearer_switch(kal_bool user_result, int switch_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    widget_bearer_switch_ind_struct* ind = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ind = (widget_bearer_switch_ind_struct*) construct_local_para(sizeof(widget_bearer_switch_ind_struct), TD_RESET);
    ind->user_result = user_result;
    ind->type = switch_type;

    srv_wgtmgr_send_message(MOD_GADGET, MSG_ID_WIDGET_BEARER_SWITCH_IND, ind, NULL);
}


#endif /* __GADGET_SUPPORT__ */
