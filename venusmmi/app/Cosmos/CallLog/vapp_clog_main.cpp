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
 *  vapp_clog_main.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h"

#include "vfx_object.h"
#include "vfx_datatype.h"
#include "vdat_systime.h"
#include "vapp_ncenter_base_cell.h"
#include "vapp_clog_gprot.h"
#include "vapp_clog_config.h"
#include "vapp_clog_usage.h"
#include "vapp_clog_ui.h"
#include "vapp_clog_data_provider.h"
#include "vsrv_notification.h"
#include "vsrv_ncenter.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "mmi_rp_vapp_calllog_def.h"
#include "mmi_rp_srv_calllog_def.h"

#include "mmi_include.h" //temp
#include "MMIDataType.h"
#include "mmi_cb_mgr_gprot.h"
#include "PhbSrvGprot.h"
#include "CallLogSrvGprot.h"
#include "CallLogSrvIprot.h"
//#include "wgui_categories_util.h"
#include "gui_typedef.h"
#include "MMI_common_app_trc.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_calllog_def.h"
#include "AppMgrSrvGprot.h"
#include "NativeAppFactorySrvGprot.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
static NMGR_HANDLE g_nmgr_handle = 0;
static mmi_ret vapp_clog_init_srv(mmi_event_struct *evt);
static void vapp_clog_update_status_icon(void);
static void vapp_clog_update_ncenter(void);
#ifdef __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__
static void vapp_clog_clear_all_read_status(void);
static VfxS32 vapp_clog_clear_all_read_status_result(
                SRV_CLOG_HANDLE handle,
                S32 pid,
                void *req_data,
                void *cnf_data,
                MMI_BOOL more,
                srv_clog_ret_enum ret);
#endif /* __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__ */

/***************************************************************************** 
 * Function
 *****************************************************************************/


extern "C" mmi_ret vapp_clog_init(mmi_event_struct *evt)
{
    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_INIT, 0);
    // do calllog service init work
    vapp_clog_init_srv(evt);

    // do calllog app init work
#if (defined(__MMI_CLOG_CALL_TIME__) || defined(__MMI_CLOG_CALL_COST__) || defined(__MMI_CLOG_SMS_COUNT__) || defined(__MMI_CLOG_GPRS_COUNT__))
    // do calllog usage init work
    vapp_clog_usage_init(NULL);
#endif

    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_INIT, 1);
    
    return MMI_RET_OK;
}

static mmi_ret vapp_clog_init_srv(mmi_event_struct *evt)
{
    srv_clog_init(evt);

    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_SRV_INIT_SET_SRV_STYLE, SRV_CLOG_STYLE_TYPE_NUM, VAPP_CLOG_STYLE_NUM);
    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_NUM, VAPP_CLOG_STYLE_NUM, NULL);

    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_SRV_INIT_SET_SRV_STYLE, SRV_CLOG_STYLE_TYPE_MERGE, VAPP_CLOG_STYLE_MERGE);
    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_MERGE, VAPP_CLOG_STYLE_MERGE, NULL);

    MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_SRV_INIT_SET_SRV_STYLE, SRV_CLOG_STYLE_TYPE_PHB_SYNC, VAPP_CLOG_STYLE_PHB_SYNC);
    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_PHB_SYNC, VAPP_CLOG_STYLE_PHB_SYNC, NULL);

    MMI_TRACE(
        VAPP_CLOG_TRC_INFO,
        TRC_VCLOG_SRV_INIT_SET_SRV_STYLE,
        SRV_CLOG_STYLE_TYPE_SIM_SYNC,
        VAPP_CLOG_STYLE_SIM_SYNC);
    srv_clog_set_def_style(SRV_CLOG_STYLE_TYPE_SIM_SYNC, VAPP_CLOG_STYLE_SIM_SYNC, NULL);

    srv_clog_start();

    
    return MMI_RET_OK;
}


extern "C"
mmi_ret vapp_clog_package_proc(mmi_event_struct *evt)
{
    VfxU32 badge_num;
    
    mmi_ret tmp_value = MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_BADGE:
        {
            srv_nativeappfactory_query_app_badge_evt_struct *badge_evt = (srv_nativeappfactory_query_app_badge_evt_struct*)evt;
            
            badge_num = srv_clog_get_unread_missed_call_num();
            if (0 == badge_num)
            {
                badge_evt->badge[0] = '\0';
            }
            else
            {
                mmi_wsprintf_ex(
                    (*badge_evt).badge, 
                    (SRV_APPMGR_BADGE_MAX_LEN + 1) * sizeof(WCHAR),
                    (WCHAR*)L"%d", 
                    badge_num);
            }
            tmp_value = MMI_RET_OK;

            break;
            //return MMI_RET_OK;
        }
            
        default:
            tmp_value = MMI_RET_DONT_CARE;
            //return MMI_RET_DONT_CARE;
            break;
    }
    
    return tmp_value;
}


void vapp_clog_intent_callback(VsrvNotification* noti, VsrvNIntent intent,
                                   void* userData, VfxU32 userDataSize)
{
    if (intent.type == VSRV_NINTENT_TYPE_LAUNCH)
    {
        vapp_clog_mclt_launch();
    }
    else if(intent .type == VSRV_NINTENT_TYPE_LANGUAGE_CHANGED)
    {
        vapp_clog_update_ncenter();
    }
    else if (intent.type == VSRV_NINTENT_TYPE_CLEAR)
    {
        VfxU8 isHaveNoti = 0;
        VfxS16 err;
        
        WriteValue(NVRAM_VAPP_CLOG_NCENTER_HAVE_NOTI, &isHaveNoti, DS_BYTE, &err);

        VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_CALLLOG, 0);
        
        //wgui_status_icon_bar_hide_icon(STATUS_ICON_MISSED_CALL);
        if (g_nmgr_handle > 0)
        {
            mmi_frm_nmgr_alert_cancel(g_nmgr_handle);
            g_nmgr_handle = 0;
        }
    }
    else if (intent.type == VSRV_NINTENT_TYPE_CLOSE)
    {
        if (g_nmgr_handle > 0)
        {
            mmi_frm_nmgr_alert_cancel(g_nmgr_handle);
            g_nmgr_handle = 0;
        }    
        VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_CALLLOG, 0);
    }
}


// for missed calls status icon
extern "C"
mmi_ret vapp_clog_srv_evt_hdlr(mmi_event_struct *evt)
{
    mmi_ret tmp_value = MMI_RET_OK;

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_CLOG_READY:
        {
        #ifdef __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__
            vapp_clog_clear_all_read_status();
        #else
            VfxU8 isHaveNoti;
            VfxS16 err;
                
            ReadValue(NVRAM_VAPP_CLOG_NCENTER_HAVE_NOTI, &isHaveNoti, DS_BYTE, &err);
            if (isHaveNoti)
            {
                vapp_clog_update_ncenter();
                vapp_clog_update_status_icon();
            }
        #endif
            tmp_value = MMI_RET_OK;
            break;
         }

        case EVT_ID_SRV_CLOG_ADD_LOG:
        case EVT_ID_SRV_CLOG_UPDATE_LOG:
        case EVT_ID_SRV_CLOG_UPDATE_ALL:
        {
            srv_clog_get_last_log_req_struct req_data;
            srv_clog_get_last_log_cnf_struct cnf_data;
            srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_REQ, &req_data);
            srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_CNF, &cnf_data);
            //req_data.log_type = SRV_CLOG_CLT_MISSED;
            
            srv_clog_get_last_log(0,
                    (const srv_clog_get_last_log_req_struct *)&req_data,
                    &cnf_data);
            srv_clog_call_log_struct *calllog = &(cnf_data.log.data.call_log); 
            if (calllog->log_type == SRV_CLOG_CLT_MISSED)
            {
                VfxU8 isHaveNoti = 1;
                VfxS16 err;
            
                WriteValue(NVRAM_VAPP_CLOG_NCENTER_HAVE_NOTI, &isHaveNoti, DS_BYTE, &err); 
            
                vapp_clog_update_status_icon();
            
                vapp_clog_update_ncenter();
            }

            srv_appmgr_update_app_info("native.mtk.calllog", EVT_ID_SRV_APPMGR_UPDATE_BADGE);
            tmp_value = MMI_RET_OK;
            break;
            //return MMI_RET_OK;
        }

        case EVT_ID_SRV_CLOG_DEL_LOG:
        case EVT_ID_SRV_CLOG_DEL_ALL:
        {
            srv_appmgr_update_app_info("native.mtk.calllog", EVT_ID_SRV_APPMGR_UPDATE_BADGE);
            
            vapp_clog_update_status_icon();
            
            vapp_clog_update_ncenter();

            //return MMI_RET_OK;
            tmp_value = MMI_RET_OK;
            break;
        }
        
        default:
            tmp_value = MMI_RET_DONT_CARE;
            break;
            
            //return MMI_RET_DONT_CARE;
    }
    return tmp_value;
    //return MMI_RET_OK;
}


// if return 0, suggest don't show calllog name
VfxS32 vapp_clog_check_phb_id(mmi_phb_contact_id id)
{
    VfxU8 store_type = srv_phb_get_storage(id);
    if (0xFF == store_type)
        return 0xFF;
    else
    {
        if (srv_phb_check_storage_is_hide(store_type))
        {
            MMI_TRACE(VAPP_CLOG_TRC_INFO, TRC_VCLOG_CHECK_PHB_ID, store_type);
            return 0;
        }
        else
        {
            return 1;
        }
    }
}


#ifdef __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__

static void vapp_clog_clear_all_read_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS32 ret;
    VfxU32 unread_num;
    srv_clog_update_all_logs_req_struct req_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    unread_num = srv_clog_get_unread_missed_call_num();
    if (unread_num == 0)
        return;

    srv_clog_init_para(SRV_CLOG_PARA_UPDATE_ALL_LOGS_REQ, &req_data);
    req_data.cate = SRV_CLOG_CATE_CALL;
    req_data.log_type = SRV_CLOG_CLT_MISSED;
    req_data.req_fields = SRV_CLOG_LOG_FIELD_UNREAD_NUM;
    req_data.read = MMI_TRUE;

    ret = srv_clog_update_all_logs(0, 0, &req_data, vapp_clog_clear_all_read_status_result);
}


static VfxS32 vapp_clog_clear_all_read_status_result(
                SRV_CLOG_HANDLE handle,
                S32 pid,
                void *req_data,
                void *cnf_data,
                MMI_BOOL more,
                srv_clog_ret_enum ret)
{
    vapp_clog_update_status_icon();
    return SRV_CLOG_RET_OK;
}
#endif /* __MMI_CLOG_REBOOT_NO_UNREAD_SUPPORT__ */


void vapp_clog_check_nmgr_alert(void)
{
    if (g_nmgr_handle > 0)
    {
        mmi_frm_nmgr_alert_cancel(g_nmgr_handle);
        g_nmgr_handle = 0;
    }
}


static void vapp_clog_update_status_icon(void)
{
    VfxU32 unread_num;

    unread_num = srv_clog_get_unread_missed_call_num();

    if (unread_num != 0)
    {
        //wgui_status_icon_bar_set_icon_display(STATUS_ICON_MISSED_CALL);
        mmi_frm_nmgr_alert_struct alert_info;
        memset(&alert_info, 0, sizeof(mmi_frm_nmgr_alert_struct));
        alert_info.app_id = VAPP_CALLLOG;
        alert_info.ui_mask = MMI_FRM_NMGR_UI_STATUS_ICON_MASK;
        alert_info.behavior_mask = FORCE_ICON_ONLY;
        alert_info.alert_option = MMI_FRM_NMGR_DISABLE_TONE | MMI_FRM_NMGR_DISABLE_VIB;
        alert_info.status_bar_icon_para.icon_id = STATUS_ICON_MISSED_CALL;
        g_nmgr_handle = mmi_frm_nmgr_alert(&alert_info);
    }
    else
    {
        //wgui_status_icon_bar_reset_icon_display(STATUS_ICON_MISSED_CALL);
        if (g_nmgr_handle > 0)
        {
            mmi_frm_nmgr_alert_cancel(g_nmgr_handle);
            g_nmgr_handle = 0;
        }
    }

    //wgui_status_icon_bar_update();
}


static void vapp_clog_update_ncenter(void)
{
    VfxU32 unread_num = srv_clog_get_unread_missed_call_num();
    if (unread_num != 0)
    {
        srv_clog_get_last_log_req_struct req_data;
        srv_clog_get_last_log_cnf_struct cnf_data;
        srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_REQ, &req_data);
        srv_clog_init_para(SRV_CLOG_PARA_GET_LAST_LOG_CNF, &cnf_data);
        req_data.log_type = SRV_CLOG_CLT_MISSED;
        
        srv_clog_get_last_log(0,
                (const srv_clog_get_last_log_req_struct *)&req_data,
                &cnf_data);
        srv_clog_call_log_struct *calllog = &(cnf_data.log.data.call_log);

        VsrvNGroupSingleTitle *group = NULL;
        VSRV_NGROUP_CREATE_EX(group, VsrvNGroupSingleTitle, (VAPP_CALLLOG));
       // group->setTitle(VFX_WSTR_RES(STR_ID_VAPP_CLOG_NCENTER_GROUP_TITLE));
       group->setTitle(STR_ID_VAPP_CLOG_NCENTER_GROUP_TITLE);
        VsrvNotificationEvent *noti = NULL;
        VSRV_NOTIFICATION_CREATE_EX(noti, VsrvNotificationEvent, ((VsrvNGroup*)group, 0));
        noti->setIcon(VfxImageSrc(IMG_ID_VAPP_CLOG_NMGR_MISSED));
        //noti->setMainText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_MISSED_CALL));
        noti->setMainText(STR_ID_VAPP_CLOG_MISSED_CALL);
        noti->setAutoClose(VFX_FALSE);
        VfxDateTime dateTime;
        VappCLogUtils utils;
        utils.convertUTC2DT(calllog->timestamp[SRV_CLOG_LASTEST_TIME_IDX], dateTime);
        noti->setTimeStamp(dateTime);
        
        if (unread_num == 1)
        {
            if (calllog->name[0] != 0) // have name string
                //noti->setSubText(VFX_WSTR_MEM((VfxWChar *)calllog->name));
                noti->setSubText((VfxWChar *)calllog->name);
            else if (calllog->cid[0] != 0)
                //noti->setSubText(VFX_WSTR_MEM((VfxWChar *)calllog->cid));
                noti->setSubText((VfxWChar *)calllog->cid);
            else
                //noti->setSubText(VFX_WSTR_RES(STR_ID_VAPP_CLOG_UNKONWN_NUMBER));
                noti->setSubText(STR_ID_VAPP_CLOG_UNKONWN_NUMBER);
        }
        else
        {
            //noti->setMainText(VFX_WSTR_RES(STR_GLOBAL_MISSED_CALLS));
            VfxWString subText;
            //subText.format("%d%ws", unread_num, get_string(STR_ID_VAPP_CLOG_MULTI_MISSED_CALLS));//get_string(MMI_ID_TYPE i)
            subText.format("%d", unread_num);
            subText += VFX_WSTR_RES(STR_ID_VAPP_CLOG_MULTI_MISSED_CALLS);
            noti->setSubText(subText);
        }

        noti->setIntentCallback(vapp_clog_intent_callback);
        noti->notify();
    }
    else
    {
        VSRV_NOTIFICATION_CLOSE_EX((VsrvNGroupId)VAPP_CALLLOG, 0);
    }    
}


