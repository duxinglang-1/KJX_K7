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
 *  TetheringSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Wi-Fi hotspot service
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "mmi_features.h"
#ifdef __MMI_TETHERING__
/****************************************************************************
* Include Files                                                                
*****************************************************************************/
#include "MMI_include.h"
#include "TetheringSrvGprot.h"
#include "TetheringSrvIprot.h"

#include "hostap_abm_msgs.h"
#include "mmi2abm_struct.h"
#include "mmi_rp_srv_tethering_def.h"
#include "mmi2abm_struct.h"
#include "SimCtrlSrvGprot.h"
#include "BootupSrvGprot.h"
#include "ModeSwitchSrvGprot.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#include "mmi_conn_app_trc.h"
#include "wgui_categories_util.h" // show icon
#include "mmi_l3_enums.h" // SND_NO_DCOMP
#include "usbsrvgprot.h" // srv_usb_tethering_off
#include "CbmSrvGprot.h" // SRV_CBM_BEARER_DIALUP
#include "NwInfoSrvGprot.h"
#include "TimerEvents.h"
#include "CharBatSrvGprot.h"
#include "UcmSrvGprot.h"

/****************************************************************************
* Define
*****************************************************************************/
static const S8 power_change_dbm_tbl[SRV_TETHERING_WIFI_POWER_CHANGE_TYPE_TOTAL] =
{
    /* mode 1 (dbm) */
    10, // type none
    15  // type in charging
};

/****************************************************************************
* Typedef
*****************************************************************************/

/****************************************************************************
* Global Variable
*****************************************************************************/

/****************************************************************************
* Static Variable
*****************************************************************************/
static srv_tethering_cntx_struct srv_tethering_cntx;
/****************************************************************************
* Function Forward Declaration
*****************************************************************************/
#ifndef __MTK_TARGET__
void srv_tethering_ut_activate_req_hdlr(void *msg);
void srv_tethering_ut_deactivate_req_hdlr(void *msg);
#endif /* __MTK_TARGET__ */
extern void tcpip_change_priority(kal_int32 is_change);

/****************************************************************************
* Function Body
*****************************************************************************/

mmi_ret srv_tethering_bootup_init(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_BOOTUP_NORMAL_INIT:
        {
            srv_tethering_init();
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


void srv_tethering_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_app_info_struct cbm_app_info;
    srv_dtcnt_sim_type_enum sim_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_INIT);
    SetProtocolEventHandler(srv_tethering_abm_activate_cnf_hdlr, MSG_ID_MMI_ABM_SHARE_BEARER_ACTIVATE_CNF);
    SetProtocolEventHandler(srv_tethering_abm_deactivate_cnf_hdlr, MSG_ID_MMI_ABM_SHARE_BEARER_DEACTIVATE_CNF);
    SetProtocolEventHandler(srv_tethering_abm_bearer_share_query_cnf_hdlr, MSG_ID_MMI_ABM_SHARE_BEARER_QUERY_CNF);
    mmi_frm_set_protocol_event_handler(
        MSG_ID_MMI_ABM_BEARER_INFO_IND,
        (PsIntFuncPtr)srv_tethering_abm_bearer_info_ind_hdlr,
        MMI_TRUE);

    //test
    #ifndef __MTK_TARGET__
    SetProtocolEventHandler(srv_tethering_ut_activate_req_hdlr, MSG_ID_MMI_ABM_SHARE_BEARER_ACTIVATE_REQ);
    SetProtocolEventHandler(srv_tethering_ut_deactivate_req_hdlr, MSG_ID_MMI_ABM_SHARE_BEARER_DEACTIVATE_REQ);
    #endif /* __MTK_TARGET__ */

    cbm_app_info.app_str_id = STR_ID_SRV_TETHERING;
    cbm_app_info.app_icon_id = 0;
    cbm_app_info.app_type =
        DTCNT_APPTYPE_TETHERING |
        DTCNT_APPTYPE_SKIP_CSD;
    cbm_register_app_id_with_app_info(
        &cbm_app_info,
        &srv_tethering_cntx.common_cbm_app_id);

#ifdef __MMI_TETHERING_WIFI__
    cbm_app_info.app_str_id = STR_ID_SRV_TETHERING_WIFI_HS;
    cbm_app_info.app_icon_id = 0;
    cbm_app_info.app_type =
        DTCNT_APPTYPE_TETHERING |
        DTCNT_APPTYPE_WIFI_TETHERING |
        DTCNT_APPTYPE_SKIP_CSD;
    cbm_register_app_id_with_app_info(
        &cbm_app_info,
        &srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].cbm_app_id);
#endif /* __MMI_TETHERING_WIFI__ */

#ifdef __USB_TETHERING__
    cbm_app_info.app_str_id = STR_ID_SRV_TETHERING_USB;
    cbm_app_info.app_icon_id = 0;
    cbm_app_info.app_type =
        DTCNT_APPTYPE_TETHERING |
        DTCNT_APPTYPE_USB_TETHERING |
        DTCNT_APPTYPE_SKIP_CSD;
    cbm_register_app_id_with_app_info(
        &cbm_app_info,
        &srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_USB].cbm_app_id);
#endif /* __USB_TETHERING__ */

    // load data account to context, to make performance better
    for (sim_type = SRV_DTCNT_SIM_TYPE_1; sim_type < MMI_SIM_TOTAL + SRV_DTCNT_SIM_TYPE_1; sim_type++)
    {
        srv_tethering_get_dtcnt(sim_type);
    }
}


void srv_tethering_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_DEINIT);
    // free the memory
}


void srv_tethering_reg_app_avail_status_change_cb(
    srv_tethering_app_avail_status_change_notify_funcptr_type funcptr,
    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tethering_cntx.app_avail_status_change_info.avail_status_change_cb_hdlr = funcptr;
    srv_tethering_cntx.app_avail_status_change_info.user_data = user_data;
}


void srv_tethering_notify_app_change_avail_status(MMI_BOOL enable_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void *user_data = srv_tethering_cntx.app_avail_status_change_info.user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_tethering_cntx.app_avail_status_change_info.avail_status_change_cb_hdlr != NULL)
    {
        srv_tethering_cntx.app_avail_status_change_info.avail_status_change_cb_hdlr(enable_flag, user_data);
    }
}


void srv_tethering_switch_on(
        srv_tethering_type_enum tethering_type,
        srv_tethering_switch_cb_funcptr_type funcptr,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_status_enum status = srv_tethering_get_status(tethering_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_SWITCH_ON, status);
    if (status == SRV_TETHERING_STATUS_SRV_ON)
    {
        (*funcptr)(
            tethering_type,
            MMI_TRUE,
            SRV_TETHERING_STATUS_SRV_ON,
            user_data);
        return;
    }
    else if (status == SRV_TETHERING_STATUS_ON_SWITCHING_ON)
    {
        return;
    }

    // TOTO use dynamic memory
    srv_tethering_cntx.common_info[tethering_type].switch_req_info.funcptr = funcptr;
    srv_tethering_cntx.common_info[tethering_type].switch_req_info.user_data = user_data;

#ifdef __MMI_TETHERING_WIFI__
    // deinit wlan as wifi tethering
    if ((srv_dtcnt_wlan_state() != SRV_DTCNT_WLAN_STATE_NULL) &&
        tethering_type == SRV_TETHERING_TYPE_WIFI_HS)
    {
        MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_TURN_OFF_WLAN, status);

        srv_tethering_set_status(tethering_type, SRV_TETHERING_STATUS_ON_SWITCHING_ON);
        srv_tethering_set_ext_status(tethering_type,SRV_TETHERING_EXT_STATUS_DEINIT_WLAN);
        mmi_frm_cb_reg_event(
            EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND,
            srv_tethering_wifi_wlan_deinit_res_ind_hdlr,
            NULL);
        srv_dtcnt_wlan_deinit(NULL, NULL);
        return;
    }
#endif /* __MMI_TETHERING_WIFI__ */

    // send msg
    srv_tethering_abm_send_activate_req(tethering_type);
}


void srv_tethering_switch_off(
        srv_tethering_type_enum tethering_type,
        srv_tethering_switch_cb_funcptr_type funcptr,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_status_enum status = srv_tethering_get_status(tethering_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_SWITCH_OFF, status);
    if (status == SRV_TETHERING_STATUS_SRV_OFF)
    {
        (*funcptr)(
            tethering_type,
            MMI_TRUE,
            SRV_TETHERING_STATUS_SRV_OFF,
            user_data);
        return;
    }
    else if (status == SRV_TETHERING_STATUS_ON_SWITCHING_OFF)
    {
        return;
    }

    srv_tethering_cntx.common_info[tethering_type].switch_req_info.funcptr = funcptr;
    srv_tethering_cntx.common_info[tethering_type].switch_req_info.user_data = user_data;
    srv_tethering_set_status(tethering_type, SRV_TETHERING_STATUS_ON_SWITCHING_OFF);
    srv_tethering_abm_send_deactivate_req(tethering_type);
}


U32 srv_tethering_get_dtcnt(srv_dtcnt_sim_type_enum sim_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_srv_tethering_dtcnt_struct nvram_dtcnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sim_type == SRV_DTCNT_SIM_TYPE_NONE)
    {
        return CBM_INVALID_NWK_ACCT_ID;
    }

    if (srv_tethering_cntx.dtcnt_id[sim_type - 1] == 0)
    {
        ReadRecord(
            NVRAM_EF_SRV_TETHERING_DTCNT_LID,
            sim_type,
            &nvram_dtcnt,
            NVRAM_EF_SRV_TETHERING_DTCNT_SIZE,
            &error);

        if (nvram_dtcnt.data_account_id == 0xffffffff)
        {
            nvram_dtcnt.data_account_id = srv_tethering_reset_dtcnt(sim_type);
        }
        srv_tethering_cntx.dtcnt_id[sim_type - 1] = nvram_dtcnt.data_account_id;
    }

    return srv_tethering_cntx.dtcnt_id[sim_type - 1];
}


void srv_tethering_save_dtcnt(srv_dtcnt_sim_type_enum sim_type, U32 data_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_srv_tethering_dtcnt_struct nvram_dtcnt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_SAVE_DTCNT,
        sim_type,
        data_account_id);

    //write to nvram
    nvram_dtcnt.data_account_id = data_account_id;
    srv_tethering_cntx.dtcnt_id[sim_type - 1] = data_account_id;
    WriteRecord(
        NVRAM_EF_SRV_TETHERING_DTCNT_LID,
        sim_type,
        &nvram_dtcnt,
        NVRAM_EF_SRV_TETHERING_DTCNT_SIZE,
        &error);
}


U32 srv_tethering_reset_dtcnt(srv_dtcnt_sim_type_enum sim_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cbm_sim_id_enum cbm_sim_id = (cbm_sim_id_enum)(sim_type - 1);
    U32 default_account_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_RESET_DTCNT, sim_type);
    MMI_ASSERT(CBM_SIM_ID_SIM1 == SRV_DTCNT_SIM_TYPE_1 - 1);

    default_account_id = cbm_encode_data_account_id(
                            CBM_DEFAULT_ACCT_ID,
                            cbm_sim_id,
                            0,
                            KAL_FALSE);
    srv_tethering_cntx.dtcnt_id[sim_type - 1] = default_account_id;
    srv_tethering_save_dtcnt(sim_type, default_account_id);
    return default_account_id;
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
#endif

void srv_tethering_set_curr_common_dtcnt(U32 data_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tethering_cntx.conn_info.common_account_id = data_account_id;
}


U32 srv_tethering_get_curr_common_dtcnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_tethering_cntx.conn_info.common_account_id;
}


void srv_tethering_set_curr_dtcnt(srv_tethering_type_enum tethering_type, U32 data_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tethering_cntx.common_info[tethering_type].account_id = data_account_id;
}


U32 srv_tethering_get_curr_dtcnt(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_tethering_cntx.common_info[tethering_type].account_id;
}


U32 srv_tethering_get_used_dtcnt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 curr_used_dtcnt = 0;
    srv_tethering_type_enum tethering_type = (srv_tethering_type_enum)0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; tethering_type < SRV_TETHERING_TYPE_ALL; tethering_type++)
    {
        if (srv_tethering_is_on(tethering_type) == MMI_TRUE)
        {
            curr_used_dtcnt = srv_tethering_get_curr_dtcnt(tethering_type);
            break;
        }
    }
    return curr_used_dtcnt;
}


U32 srv_tethering_get_auto_dtcnt(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 encode_common_account;
    U32 auto_account;
    srv_dtcnt_result_enum result;
    U32 ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    encode_common_account =
        cbm_encode_data_account_id(
            srv_tethering_get_curr_common_dtcnt(),
            srv_tethering_cntx.conn_info.used_sim,
            srv_tethering_cntx.common_info[tethering_type].cbm_app_id,
            MMI_FALSE);
    result = srv_dtcnt_get_auto_acc_id(encode_common_account, &auto_account);
    if (SRV_DTCNT_RESULT_SUCCESS == result)
    {
        ret = auto_account;
    }
    else
    {
        ret = encode_common_account;
    }
    return ret;
}


void srv_tethering_get_used_dtcnt_apn(WCHAR *apn_wstr, U16 apn_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_prof_str_info_qry_struct apn_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    apn_info.dest = (S8*)apn_wstr;
    apn_info.dest_len = apn_len * 2;

    srv_dtcnt_get_apn(
        srv_tethering_get_used_dtcnt(),
        &apn_info,
        SRV_DTCNT_ACCOUNT_PRIMARY);
}


void srv_tethering_set_status(srv_tethering_type_enum tethering_type, srv_tethering_status_enum status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_SET_STATUS,
        tethering_type,
        status);

    MMI_ASSERT(tethering_type < SRV_TETHERING_TYPE_ALL);
    MMI_ASSERT(status < SRV_TETHERING_STATUS_END);
    srv_tethering_cntx.common_info[tethering_type].status = status;
    if (tethering_type == SRV_TETHERING_TYPE_WIFI_HS)
    {
        if (status == SRV_TETHERING_STATUS_SRV_ON)
        {
            srv_tethering_show_status_icon(SRV_TETHERING_TYPE_WIFI_HS);
        }
        else if (status == SRV_TETHERING_STATUS_SRV_OFF)
        {
            srv_tethering_hide_status_icon(SRV_TETHERING_TYPE_WIFI_HS);
        }
    }
}


srv_tethering_status_enum srv_tethering_get_status(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(tethering_type < SRV_TETHERING_TYPE_ALL);
    return srv_tethering_cntx.common_info[tethering_type].status;
}

void srv_tethering_set_ext_status(srv_tethering_type_enum tethering_type, srv_tethering_ext_status_enum ext_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_SET_EXT_STATUS,
        tethering_type,
        ext_status);
    
    MMI_ASSERT(tethering_type < SRV_TETHERING_TYPE_ALL);
    MMI_ASSERT(ext_status < SRV_TETHERING_EXT_STATUS_END);
    srv_tethering_cntx.common_info[tethering_type].ext_status = ext_status;
}


srv_tethering_ext_status_enum srv_tethering_get_ext_status(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(tethering_type < SRV_TETHERING_TYPE_ALL);
    return srv_tethering_cntx.common_info[tethering_type].ext_status;
}


void srv_tethering_set_conn_info(srv_tethering_conn_info_struct *conn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_SET_CONN_INFO,
        conn_info->common_account_id,
        conn_info->used_sim);

    memcpy(
        &srv_tethering_cntx.conn_info,
        conn_info,
        sizeof(srv_tethering_conn_info_struct));
}


void srv_tethering_get_conn_info(srv_tethering_conn_info_struct *conn_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(
        conn_info,
        &srv_tethering_cntx.conn_info,
        sizeof(srv_tethering_conn_info_struct));
}


void srv_tethering_set_sta_num(srv_tethering_type_enum tethering_type, U8 sta_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_SET_STA_NUM,
        tethering_type,
        sta_num);

    srv_tethering_cntx.common_info[tethering_type].curr_sta_num = sta_num;
}


U8 srv_tethering_get_sta_num(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_tethering_cntx.common_info[tethering_type].curr_sta_num;
}


U8 srv_tethering_get_cbm_app_id(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_tethering_cntx.common_info[tethering_type].cbm_app_id;
}


U8 srv_tethering_get_common_cbm_app_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_tethering_cntx.common_cbm_app_id;
}

void srv_tethering_show_status_icon(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_id = STATUS_ICON_WIFI_TETHERING;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (tethering_type)
    {
        case SRV_TETHERING_TYPE_WIFI_HS:
            icon_id = STATUS_ICON_WIFI_TETHERING;
            break;

        default:
            MMI_ASSERT(0);
    }
    
    wgui_status_icon_bar_show_icon(icon_id);
}


void srv_tethering_hide_status_icon(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 icon_id = STATUS_ICON_WIFI_TETHERING;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (tethering_type)
    {
        case SRV_TETHERING_TYPE_WIFI_HS:
            icon_id = STATUS_ICON_WIFI_TETHERING;
            break;

        default:
            MMI_ASSERT(0);
    }

    wgui_status_icon_bar_hide_icon(icon_id);
}


void srv_tethering_abm_update_settings(
    srv_tethering_type_enum tethering_type,
    srv_tethering_switch_cb_funcptr_type funcptr,
    void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_UPDATE_SETTINGS, tethering_type);

    srv_tethering_cntx.common_info[tethering_type].switch_req_info.funcptr = funcptr;
    srv_tethering_cntx.common_info[tethering_type].switch_req_info.user_data = user_data;
    srv_tethering_set_ext_status(tethering_type, SRV_TETHERING_EXT_STATUS_UPDATE_SETTINGS);

    // send msg
    srv_tethering_abm_send_deactivate_req(tethering_type);
}


void srv_tethering_abm_send_activate_req(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_share_bearer_activate_req_struct *activate_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_SEND_ACTIVATE_REQ, tethering_type);

    srv_tethering_set_status(tethering_type, SRV_TETHERING_STATUS_ON_SWITCHING_ON);

    activate_req = OslAllocDataPtr(mmi_abm_share_bearer_activate_req_struct);
    activate_req->share_bearer = srv_tethering_type_srv_to_ps(tethering_type);
    if (srv_sim_ctrl_any_sim_is_available() == MMI_FALSE)
    {
        srv_tethering_switch_cb_funcptr_type cb_func;
        
        MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_CHECK_SIM_UNAVAILABLE);
        srv_tethering_set_status(tethering_type, SRV_TETHERING_STATUS_SRV_OFF);
        cb_func = (srv_tethering_switch_cb_funcptr_type)srv_tethering_cntx.common_info[tethering_type].switch_req_info.funcptr;
        (*cb_func)(
            tethering_type,
            MMI_FALSE,
            SRV_TETHERING_STATUS_SRV_OFF,
            srv_tethering_cntx.common_info[tethering_type].switch_req_info.user_data);
        return;
    }

    switch (tethering_type)
    {
    #ifdef __MMI_TETHERING_WIFI__
        case SRV_TETHERING_TYPE_WIFI_HS:
        {
            srv_tethering_wifi_hs_settings_struct wifi_hs_settings;

            srv_tethering_wifi_hs_get_settings(&wifi_hs_settings);
            // ssid
            activate_req->hostap_config_profile.ssid_len = strlen((CHAR*)wifi_hs_settings.ssid);
            MMI_ASSERT(activate_req->hostap_config_profile.ssid_len <= HOSTAP_SSID_MAX_LEN);
            memcpy(
                activate_req->hostap_config_profile.ssid,
                wifi_hs_settings.ssid,
                HOSTAP_SSID_MAX_LEN);

            // psk
            activate_req->hostap_config_profile.fgIsPsk = KAL_TRUE;
            activate_req->hostap_config_profile.psk_len = strlen((CHAR*)wifi_hs_settings.psk);
            MMI_ASSERT(activate_req->hostap_config_profile.psk_len <= HOSTAP_PSK_MAX_LEN);
            memcpy(
                activate_req->hostap_config_profile.psk,
                wifi_hs_settings.psk,
                HOSTAP_PSK_MAX_LEN);

            // auth
            activate_req->hostap_config_profile.auth_alg = 
                srv_tethering_wifi_hs_auth_mode_srv_to_ps(wifi_hs_settings.auth_mode);

            // max sta
            activate_req->hostap_config_profile.max_sta_num = wifi_hs_settings.max_sta_num;

            // data account
            activate_req->account_id = srv_tethering_get_auto_dtcnt(tethering_type);
            srv_tethering_set_curr_dtcnt(tethering_type, activate_req->account_id);

            // reset sim id with new acct (automatic acct transform to any sim's acct)
            srv_tethering_cntx.conn_info.used_sim = cbm_get_sim_id(activate_req->account_id);
            break;
        }
    #endif /* __MMI_TETHERING_WIFI__ */

        case SRV_TETHERING_TYPE_USB:
        {
        #ifdef __USB_TETHERING__
            srv_dtcnt_store_prof_data_struct store_prof_data;
            srv_dtcnt_prof_gprs_struct prof_gprs;
            U32 temp_account_id;
            //srv_dtcnt_prof_str_info_qry_struct apn_info;
            //WCHAR apn_buf_w[MAX_GPRS_APN_LEN + 1];
            //S8 apn_buf_asc[MAX_GPRS_APN_LEN + 1];
            //apn_info.dest = (S8*)apn_buf_w;
            //apn_info.dest_len = (MAX_GPRS_APN_LEN + 1) * 2;

            // data account
            temp_account_id = srv_tethering_get_auto_dtcnt(tethering_type);
            srv_tethering_set_curr_dtcnt(tethering_type, temp_account_id);

            // reset sim id with new acct (automatic acct transform to any sim's acct)
            srv_tethering_cntx.conn_info.used_sim = cbm_get_sim_id(temp_account_id);

            // As usb tethering should use a unique account to create pdp context
            // here should get the original account info and send to abm
            // then replace the account id to the special one

            // query account info from dtcnt
            store_prof_data.prof_type = srv_dtcnt_get_bearer_type(temp_account_id, SRV_DTCNT_ACCOUNT_PRIMARY);
            store_prof_data.prof_fields = SRV_DTCNT_PROF_FIELD_ALL;
            store_prof_data.prof_data = &prof_gprs;
            srv_dtcnt_store_qry_prof(cbm_get_original_account(temp_account_id), &store_prof_data);

            // fill up request structure
            activate_req->usb_tr_profile.authentication_type = prof_gprs.prof_common_header.Auth_info.AuthType;
            strcpy((CHAR*)activate_req->usb_tr_profile.user_name, (CHAR*)prof_gprs.prof_common_header.Auth_info.UserName);
            strcpy((CHAR*)activate_req->usb_tr_profile.password, (CHAR*)prof_gprs.prof_common_header.Auth_info.Passwd);
            strcpy((CHAR*)activate_req->usb_tr_profile.dns, (CHAR*)prof_gprs.prof_common_header.PrimaryAddr);
            strcpy((CHAR*)activate_req->usb_tr_profile.sec_dns, (CHAR*)prof_gprs.prof_common_header.SecondaryAddr);
            memcpy(
                activate_req->usb_tr_profile.ps_account_info.apn,
                prof_gprs.APN,
                MAX_GPRS_APN_LEN);
            activate_req->usb_tr_profile.ps_account_info.apn_length =
                (MAX_GPRS_APN_LEN < strlen((CHAR*)prof_gprs.APN)) ? MAX_GPRS_APN_LEN : strlen((CHAR*)prof_gprs.APN);
            activate_req->usb_tr_profile.ps_account_info.dcomp_algo = SND_NO_DCOMP;
            activate_req->usb_tr_profile.ps_account_info.hcomp_algo = SND_NO_DCOMP;
            activate_req->usb_tr_profile.ps_account_info.pdp_type = IPV4_ADDR_TYPE;
            activate_req->usb_tr_profile.ps_account_info.pdp_addr_len = IPV4_ADDR_LEN;

            // encode with unique account id
            activate_req->account_id =
                cbm_encode_data_account_id(
                    CBM_USB_TR_PS_ACCT_ID,
                    srv_tethering_cntx.conn_info.used_sim,
                    srv_tethering_cntx.common_info[tethering_type].cbm_app_id,
                    MMI_FALSE);

        #endif /* __USB_TETHERING__ */
            break;
        }

        default:
            MMI_ASSERT(0);
            break;
    }

    mmi_frm_send_ilm(
#ifdef __MTK_TARGET__
        MOD_ABM,
#else /* __MTK_TARGET__ */
        MOD_MMI, // for UT
#endif /* __MTK_TARGET__ */
        MSG_ID_MMI_ABM_SHARE_BEARER_ACTIVATE_REQ,
        (local_para_struct*)activate_req,
        NULL);
}


void srv_tethering_abm_activate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_share_bearer_activate_cnf_struct *activate_cnf = (mmi_abm_share_bearer_activate_cnf_struct*)msg;
    srv_tethering_type_enum tethering_type = srv_tethering_type_ps_to_srv(activate_cnf->share_bearer);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_ACTIVATE_CNF, activate_cnf->result);

    if (activate_cnf->result == KAL_TRUE)
    {
        srv_tethering_set_status(tethering_type, SRV_TETHERING_STATUS_SRV_ON);
        srv_tethering_set_reactivate_flag(SRV_TETHERING_TYPE_USB, MMI_FALSE);
        srv_tethering_cntx.common_info[tethering_type].disconn_cause = SRV_TETHERING_DISCONNECT_CAUSE_NONE;

        if (srv_tethering_get_ext_status(tethering_type) == SRV_TETHERING_EXT_STATUS_FORCE_STOP)
        {
            MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_FORCE_STOP_STATUS);
            srv_tethering_abm_send_deactivate_req(tethering_type);
            return;
        }

        if (tethering_type == SRV_TETHERING_TYPE_USB)
        {
            srv_cbm_disallow_nwk_srv(
                SRV_CBM_BEARER_DIALUP,
                srv_tethering_cntx.common_info[tethering_type].cbm_app_id);
        }

        if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
        {
            MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_MODE_SWITCH_ALL_OFF);
            srv_tethering_set_ext_status(tethering_type, SRV_TETHERING_EXT_STATUS_SWITCH_ON_ROLL_BACK);
            srv_tethering_abm_send_deactivate_req(tethering_type);
            return;
        }

        // dynamically change TCPIP priority
        tcpip_change_priority(1);

#ifdef __MMI_TETHERING_WIFI__
        // change power if charging
        if (srv_charbat_is_charging() == MMI_TRUE)
        {
            srv_tethering_wifi_change_power(SRV_TETHERING_WIFI_POWER_CHANGE_TYPE_IN_CHARGING);
        }

        // auto turn off timer
        if (srv_tethering_check_auto_turn_off_flag() == MMI_TRUE &&
            srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].curr_sta_num == 0)
        {
            srv_tethering_start_auto_turn_off_timer();
        }
#endif /* __MMI_TETHERING_WIFI__ */
    }
    else
    {
        srv_tethering_set_status(tethering_type, SRV_TETHERING_STATUS_SRV_OFF);

        if (srv_tethering_get_ext_status(tethering_type) == SRV_TETHERING_EXT_STATUS_FORCE_STOP)
        {
            MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_FORCE_STOP_STATUS);
            srv_tethering_set_ext_status(tethering_type, SRV_TETHERING_EXT_STATUS_NONE);
            srv_tethering_run_cb_func(tethering_type, activate_cnf->result);
        #ifdef __MMI_USB_SUPPORT__
            // call USB service API to let it know the USB cable disconnection
            srv_usb_tethering_off();
        #endif /* __MMI_USB_SUPPORT__ */
            return;
        }
        else if (srv_tethering_get_ext_status(tethering_type) == SRV_TETHERING_EXT_STATUS_REACTIVATE)
        {
            MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_REACTIVATE_AGAIN);
            srv_tethering_reactivate_retry(tethering_type);
            return;
        }
    #ifdef __MMI_USB_SUPPORT__
        // call USB service API to let it know the USB cable disconnection
        srv_usb_tethering_off();
    #endif /* __MMI_USB_SUPPORT__ */
    }

    srv_tethering_report_app_switch_cnf(tethering_type, SRV_TETHERING_STATUS_SRV_ON, activate_cnf->result);
}


void srv_tethering_abm_send_deactivate_req(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_share_bearer_deactivate_req_struct *deactivate_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_DEACTIVATE_REQ,
        tethering_type);

    srv_tethering_set_status(tethering_type, SRV_TETHERING_STATUS_ON_SWITCHING_OFF);
    
    deactivate_req = OslAllocDataPtr(mmi_abm_share_bearer_deactivate_req_struct);
    deactivate_req->share_bearer = srv_tethering_type_srv_to_ps(tethering_type);
    switch (tethering_type)
    {
        case SRV_TETHERING_TYPE_WIFI_HS:
        {
            deactivate_req->account_id = srv_tethering_get_curr_dtcnt(tethering_type);
            break;
        }

        case SRV_TETHERING_TYPE_USB:
        {
        #ifdef __USB_TETHERING__
            srv_tethering_ext_status_enum ext_status =
                srv_tethering_get_ext_status(tethering_type);
            deactivate_req->account_id = CBM_USB_TR_PS_ACCT_ID;
            if (ext_status == SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_NO_SERVICE ||
                ext_status == SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_FLIGHT_MODE ||
                ext_status == SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_SIM_RECOVERY)
            {
                deactivate_req->deact_type = MMI_ABM_SHARE_BEARER_SUSPEND; // GPRS disconnect
            }
            else if (ext_status == SRV_TETHERING_EXT_STATUS_BEARER_DISCONNECT ||
                     ext_status == SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_CM_DISC)
            {
            #ifdef __MMI_USB_SUPPORT__
                // call USB service API to let it know the USB cable disconnection
                srv_usb_tethering_off();
            #endif /* __MMI_USB_SUPPORT__ */
                deactivate_req->deact_type = MMI_ABM_SHARE_BEARER_DISCONNECT; // cable disconnect
            }
            else
            {
            #ifdef __MMI_USB_SUPPORT__
                // call USB service API to let it know the USB cable disconnection
                srv_usb_tethering_off();
            #endif /* __MMI_USB_SUPPORT__ */
            }
        #endif /* __USB_TETHERING__ */
            break;
        }

        default:
            break;
    }

    mmi_frm_send_ilm(
#ifdef __MTK_TARGET__
        MOD_ABM,
#else /* __MTK_TARGET__ */
        MOD_MMI, // for UT
#endif /* __MTK_TARGET__ */
        MSG_ID_MMI_ABM_SHARE_BEARER_DEACTIVATE_REQ,
        (local_para_struct*)deactivate_req,
        NULL);
}


void srv_tethering_abm_deactivate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_share_bearer_deactivate_cnf_struct *deactivate_cnf = (mmi_abm_share_bearer_deactivate_cnf_struct*)msg;
    srv_tethering_type_enum tethering_type = srv_tethering_type_ps_to_srv(deactivate_cnf->share_bearer);
    srv_tethering_ext_status_enum ext_status = srv_tethering_get_ext_status(tethering_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_DEACTIVATE_CNF,
        deactivate_cnf->result,
        ext_status);

#ifdef __MMI_TETHERING_WIFI__
    srv_tethering_stop_auto_turn_off_timer();
#endif /* __MMI_TETHERING_WIFI__ */

    if (deactivate_cnf->result == KAL_TRUE)
    {
        srv_tethering_set_status(tethering_type, SRV_TETHERING_STATUS_SRV_OFF);
        if (tethering_type == SRV_TETHERING_TYPE_USB)
        {
            srv_cbm_allow_nwk_srv(
                SRV_CBM_BEARER_DIALUP,
                srv_tethering_cntx.common_info[tethering_type].cbm_app_id);
        }
        // reset TCPIP priority
        tcpip_change_priority(0);
    }
    else
    {
        srv_tethering_set_status(tethering_type, SRV_TETHERING_STATUS_SRV_ON);
    }

    switch (ext_status)
    {
        case SRV_TETHERING_EXT_STATUS_UPDATE_SETTINGS:
        {
            if (deactivate_cnf->result == MMI_TRUE)
            {
                srv_tethering_abm_send_activate_req(tethering_type);
            }
            else
            {
                srv_tethering_report_app_switch_cnf(tethering_type, SRV_TETHERING_STATUS_SRV_OFF, deactivate_cnf->result);
            }

            break;
        }

        case SRV_TETHERING_EXT_STATUS_SWITCH_ON_ROLL_BACK:
        {
            srv_tethering_report_app_switch_cnf(tethering_type, SRV_TETHERING_STATUS_SRV_OFF, MMI_FALSE);

            break;
        }

        case SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_NO_SERVICE:
        {
            srv_tethering_set_ext_status(tethering_type, SRV_TETHERING_EXT_STATUS_NONE);
            srv_tethering_disconnect_notify_app(tethering_type, SRV_TETHERING_DISCONNECT_CAUSE_NETWORK);
            break;
        }

        case SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_SIM_RECOVERY:
        {
            srv_tethering_set_ext_status(tethering_type, SRV_TETHERING_EXT_STATUS_NONE);
            srv_tethering_disconnect_notify_app(tethering_type, SRV_TETHERING_DISCONNECT_CAUSE_SIM_OFF);
            break;
        }

        case SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_CM_DISC:
        {
            srv_tethering_set_ext_status(tethering_type, SRV_TETHERING_EXT_STATUS_NONE);
            srv_tethering_disconnect_notify_app(tethering_type, SRV_TETHERING_DISCONNECT_CAUSE_CM_DISC);
            break;
        }

        case SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_FLIGHT_MODE:
        {
            srv_tethering_set_ext_status(tethering_type, SRV_TETHERING_EXT_STATUS_NONE);
            srv_tethering_disconnect_notify_app(tethering_type, SRV_TETHERING_DISCONNECT_CAUSE_FLIGHT_MODE);
            break;
        }
        
        case SRV_TETHERING_EXT_STATUS_BEARER_DISCONNECT:
        {
            srv_tethering_set_ext_status(tethering_type, SRV_TETHERING_EXT_STATUS_NONE);
            srv_tethering_disconnect_notify_app(tethering_type, SRV_TETHERING_DISCONNECT_CAUSE_BEARER);
            break;
        }

        case SRV_TETHERING_EXT_STATUS_FORCE_STOP:
        {
            srv_tethering_run_cb_func(tethering_type, deactivate_cnf->result);
            srv_tethering_report_app_switch_cnf(tethering_type, SRV_TETHERING_STATUS_SRV_OFF, deactivate_cnf->result);

            break;
        }

        case SRV_TETHERING_EXT_STATUS_DISCONN_AUTO_RETRY:
        {
            if (deactivate_cnf->result == MMI_TRUE)
            {
                srv_tethering_abm_send_activate_req(tethering_type);
            }

            break;
        }

        case SRV_TETHERING_EXT_STATUS_AUTO_TURN_OFF:
        {
            srv_tethering_set_ext_status(tethering_type, SRV_TETHERING_EXT_STATUS_NONE);
            srv_tethering_disconnect_notify_app(tethering_type, SRV_TETHERING_DISCONNECT_CAUSE_AUTO_TURN_OFF);
            break;
        }

        default:
        {
            srv_tethering_report_app_switch_cnf(tethering_type, SRV_TETHERING_STATUS_SRV_OFF, deactivate_cnf->result);
            break;
        }
    }
}


void srv_tethering_report_app_switch_cnf(srv_tethering_type_enum tethering_type, srv_tethering_status_enum dest_status, MMI_BOOL result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_switch_cb_funcptr_type cb_func;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_REPORT_APP_SWITCH_CNF,
        tethering_type,
        dest_status,
        result);
    
    srv_tethering_set_ext_status(tethering_type, SRV_TETHERING_EXT_STATUS_NONE);
    if (srv_tethering_cntx.common_info[tethering_type].switch_req_info.funcptr != NULL)
    {
        cb_func = (srv_tethering_switch_cb_funcptr_type)srv_tethering_cntx.common_info[tethering_type].switch_req_info.funcptr;
        (*cb_func)(
            tethering_type,
            result,
            dest_status,
            srv_tethering_cntx.common_info[tethering_type].switch_req_info.user_data);
    }
}


U8 srv_tethering_abm_bearer_info_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_bearer_info_ind_struct *bearer_info = (mmi_abm_bearer_info_ind_struct*)msg;
    U8 pure_bearer_account = cbm_get_original_account(bearer_info->profile_id);
    srv_tethering_type_enum tethering_type = (srv_tethering_type_enum)0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((bearer_info->bearer_type & CBM_PS) != 0)
    {
        for (; tethering_type < SRV_TETHERING_TYPE_ALL; tethering_type++)
        {
            if (srv_tethering_get_status(tethering_type) == SRV_TETHERING_STATUS_SRV_ON &&
                bearer_info->status == CBM_DEACTIVATED)
            {
                U8 pure_used_account = cbm_get_original_account(srv_tethering_cntx.common_info[tethering_type].account_id);
                if ((tethering_type == SRV_TETHERING_TYPE_WIFI_HS &&
                     pure_bearer_account == pure_used_account) ||
                    (tethering_type == SRV_TETHERING_TYPE_USB &&
                     pure_bearer_account == CBM_USB_TR_PS_ACCT_ID))
                {
                    cbm_sim_id_enum sim =  cbm_get_sim_id(srv_tethering_cntx.common_info[tethering_type].account_id);
                    if (bearer_info->cause == CBM_DISC_BY_CM)
                    {
                        srv_tethering_set_ext_status(
                            tethering_type,
                            SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_CM_DISC);
                    }
                    else if (srv_mode_switch_is_switching() == MMI_TRUE ||
                             srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_FLIGHT_MODE ||
                             srv_cbm_is_sim_nwk_srv_disallowed(sim, bearer_info->bearer_type) == MMI_TRUE)
                    {
                        srv_tethering_set_ext_status(
                            tethering_type,
                            SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_FLIGHT_MODE);
                    }
                    else if (srv_sim_ctrl_get_unavailable_cause(mmi_frm_index_to_sim(sim)) == SRV_SIM_CTRL_UA_CAUSE_RECOVERY)
                    {
                        srv_tethering_set_ext_status(
                            tethering_type,
                            SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_SIM_RECOVERY);
                    }
                    else
                    {
                        srv_tethering_set_ext_status(
                            tethering_type,
                            SRV_TETHERING_EXT_STATUS_NW_DISCONNECT_NO_SERVICE);
                    }
                    srv_tethering_disconnect_hdlr(tethering_type);
                }
            }
        }
    }
    else if (bearer_info->bearer_type == CBM_WIFI_HS &&
             bearer_info->status == CBM_WIFI_STA_INFO_MODIFY)
    {
    #ifdef __MMI_TETHERING_WIFI__
        srv_tethering_set_sta_num(SRV_TETHERING_TYPE_WIFI_HS, bearer_info->share_bearer_info.sta_num);
        srv_tethering_conn_info_changed_notify(SRV_TETHERING_TYPE_WIFI_HS, &bearer_info->share_bearer_info);

        if (srv_tethering_check_auto_turn_off_flag() == MMI_TRUE &&
            bearer_info->share_bearer_info.sta_num == 0 &&
            srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS) == SRV_TETHERING_STATUS_SRV_ON)
        {
            srv_tethering_start_auto_turn_off_timer();
        }
        else
        {
            srv_tethering_stop_auto_turn_off_timer();
        }
    #endif /* __MMI_TETHERING_WIFI__ */
    }
    else if (bearer_info->bearer_type == CBM_USB_TR && bearer_info->status == CBM_DEACTIVATED)
    {
        // usb cable disconnect
        srv_tethering_set_ext_status(
            SRV_TETHERING_TYPE_USB,
            SRV_TETHERING_EXT_STATUS_BEARER_DISCONNECT);
        srv_tethering_disconnect_hdlr(SRV_TETHERING_TYPE_USB);
    }

    // save dialup status
    if (bearer_info->connect_type == 1) // ABM_CONNECT_TYPE_DIALUP
    {
        if (bearer_info->status == CBM_ACTIVATING)
        {
            srv_tethering_cntx.dialup_status = MMI_TRUE;
        }
        else if (bearer_info->status == CBM_DEACTIVATED)
        {
            srv_tethering_cntx.dialup_status = MMI_FALSE;
        }
    }
    return 0;
}


cbm_bearer_enum srv_tethering_type_srv_to_ps(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(tethering_type)
    {
        case SRV_TETHERING_TYPE_WIFI_HS:
            return CBM_WIFI_HS;

        case SRV_TETHERING_TYPE_USB:
            return CBM_USB_TR;

        default:
            MMI_ASSERT(0);
    }
    return CBM_BEARER_NONE;
}


srv_tethering_type_enum srv_tethering_type_ps_to_srv(cbm_bearer_enum bearer_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(bearer_type)
    {
        case CBM_WIFI_HS:
            return SRV_TETHERING_TYPE_WIFI_HS;

        case CBM_USB_TR:
            return SRV_TETHERING_TYPE_USB;

        default:
            MMI_ASSERT(0);
    }
    return SRV_TETHERING_TYPE_WIFI_HS;
}


void srv_tethering_abm_send_bearer_share_query_req(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_share_bearer_query_req_struct *query_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_BEARER_SHARE_QUERY_REQ,
        tethering_type);

    query_req = OslAllocDataPtr(mmi_abm_share_bearer_query_req_struct);
    query_req->share_bearer = srv_tethering_type_srv_to_ps(tethering_type);
    mmi_frm_send_ilm(
        MOD_ABM,
        MSG_ID_MMI_ABM_SHARE_BEARER_QUERY_REQ,
        (local_para_struct*)query_req,
        NULL);
}


void srv_tethering_abm_bearer_share_query_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_BEARER_SHARE_QUERY_CNF);
}


mmi_ret srv_tethering_dtcnt_changed_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_dtcnt_sim_type_enum sim_type = SRV_DTCNT_SIM_TYPE_1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_DTCNT_CHANGED_HDLR);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
        {
            srv_dtcnt_acct_delete_ind_evt_struct *dtcnt_del_info = (srv_dtcnt_acct_delete_ind_evt_struct*)evt;
            for (i = 0; i < dtcnt_del_info->del_num; i++)
            {
                U32 del_account_pure_id = cbm_get_original_account(dtcnt_del_info->acc_id[i]);

                for (sim_type = SRV_DTCNT_SIM_TYPE_1; sim_type < NVRAM_EF_SRV_TETHERING_DTCNT_TOTAL + SRV_DTCNT_SIM_TYPE_1; sim_type++)
                {
                    U32 account_pure_id = cbm_get_original_account(srv_tethering_get_dtcnt(sim_type));

                    if (account_pure_id == del_account_pure_id)
                    {
                        srv_tethering_reset_dtcnt(sim_type);
                    }
                }
            }
            break;
        }

        case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:
        {
            srv_dtcnt_acct_update_ind_evt_struct *dtcnt_update_info = (srv_dtcnt_acct_update_ind_evt_struct*)evt;
            if (dtcnt_update_info->cause == 1) // provisioning replace
            {
                U32 update_account_pure_id = cbm_get_original_account(dtcnt_update_info->acc_id);

                for (sim_type = SRV_DTCNT_SIM_TYPE_1; sim_type < NVRAM_EF_SRV_TETHERING_DTCNT_TOTAL + SRV_DTCNT_SIM_TYPE_1; sim_type++)
                {
                    U32 account_pure_id = cbm_get_original_account(srv_tethering_get_dtcnt(sim_type));

                    if (account_pure_id == update_account_pure_id)
                    {
                        srv_tethering_reset_dtcnt(sim_type);
                        srv_tethering_dtcnt_changed_notify_app(
                            sim_type,
                            srv_tethering_get_dtcnt(sim_type));
                    }
                }
            }
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


void srv_tethering_dtcnt_set_changed_notify_cb(srv_tethering_dtcnt_changed_notify_func_ptr_type cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tethering_cntx.dtcnt_changed_notify_func_ptr = cb;
}


void srv_tethering_dtcnt_changed_notify_app(srv_dtcnt_sim_type_enum sim, U32 new_acct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_tethering_cntx.dtcnt_changed_notify_func_ptr != NULL)
    {
        srv_tethering_cntx.dtcnt_changed_notify_func_ptr(sim, new_acct);
    }
}


void srv_tethering_conn_info_changed_notify(srv_tethering_type_enum tethering_type, void *info_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_conn_info_notify_funcptr_type funcptr = srv_tethering_cntx.conn_info.conn_info_notify.funcptr;
    void *user_data = srv_tethering_cntx.conn_info.conn_info_notify.user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_CONN_INFO_CHANGED_NOTIFY,
        tethering_type);

    if (funcptr != NULL)
    {
        funcptr(tethering_type, info_data, user_data);
    }
}


void srv_tethering_disconnect_hdlr(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_status_enum status = srv_tethering_get_status(tethering_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_DISCONNECT_HDLR,
        tethering_type,
        status);

    if (status == SRV_TETHERING_STATUS_ON_SWITCHING_OFF ||
        status == SRV_TETHERING_STATUS_SRV_OFF)
    {
        srv_tethering_set_ext_status(
            tethering_type,
            SRV_TETHERING_EXT_STATUS_NONE);
        return;
    }
    else if (status == SRV_TETHERING_STATUS_SRV_ON)
    {
        srv_tethering_abm_send_deactivate_req(tethering_type);
    }
}


void srv_tethering_disconnect_notify_app(srv_tethering_type_enum tethering_type, srv_tethering_disconn_cause_enum cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_disconnect_notify_funcptr_type funcptr = srv_tethering_cntx.conn_info.disconnect_notify.funcptr;
    void *user_data = srv_tethering_cntx.conn_info.disconnect_notify.user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_DISCONNECT_NOTIFY_APP,
        tethering_type,
        cause);
    srv_tethering_cntx.common_info[tethering_type].disconn_cause = cause; 

    if (cause == SRV_TETHERING_DISCONNECT_CAUSE_NETWORK ||
        cause == SRV_TETHERING_DISCONNECT_CAUSE_SIM_OFF)
    {
        if (srv_tethering_check_launch_capab(tethering_type) == SRV_TETHERING_LAUNCH_RESULT_OK)
        {
            // directlly reactivate
            srv_tethering_reactivate_demand_ind_app(tethering_type);
        }
        else
        {
            srv_tethering_reactivate_start_timer(tethering_type);
        }
    }

    funcptr(tethering_type, cause, user_data);
}


void srv_tethering_reactivate_start_timer(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static srv_tethering_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_REACTIVATE_START_TIMER,
        tethering_type);
    type = tethering_type;
    StartTimerEx(
        TETHERING_REACTIVATE_TIMER_ID,
        SRV_TETHERING_MAX_REACTIVATE_TIME * 1000,
        srv_tethering_reactivate_timeout_hdlr,
        (void*)type);
}


void srv_tethering_reactivate_timeout_hdlr(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 type = (U32)arg;
    srv_tethering_type_enum tethering_type = (srv_tethering_type_enum)type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_REACTIVATE_TIMEOUT_HDLR,
        tethering_type);
    srv_tethering_reactivate_stop_timer(tethering_type);
    srv_tethering_cntx.common_info[tethering_type].disconn_cause =
        SRV_TETHERING_DISCONNECT_CAUSE_NONE;
}


void srv_tethering_reactivate_stop_timer(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_REACTIVATE_STOP_TIMER,
        tethering_type);
    StopTimer(TETHERING_REACTIVATE_TIMER_ID);
}


void srv_tethering_reactivate_retry(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static srv_tethering_type_enum type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_REACTIVATE_RETRY,
        tethering_type);
    type = tethering_type;
    StartTimerEx(
        TETHERING_REACTIVATE_RETRY_TIMER_ID,
        SRV_TETHERING_MAX_REACTIVATE_RETRY_FREQ * 1000,
        srv_tethering_reacivate_retry_timeout_hdlr,
        (void*)type);
}


void srv_tethering_reacivate_retry_timeout_hdlr(void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 type = (U32)arg;
    srv_tethering_type_enum tethering_type = (srv_tethering_type_enum)type;
    srv_tethering_launch_result_enum result = srv_tethering_check_launch_capab(tethering_type);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_REACTIVATE_RETRY_TIMEOUT_HDLR,
        tethering_type);

    srv_tethering_cntx.reactivate_retry_times++;

    if ((result != SRV_TETHERING_LAUNCH_RESULT_OK &&
         result != SRV_TETHERING_LAUNCH_RESULT_NETWORK_NOT_READY) ||
        srv_tethering_get_ext_status(tethering_type) == SRV_TETHERING_EXT_STATUS_FORCE_STOP ||
        srv_tethering_cntx.reactivate_retry_times > SRV_TETHERING_MAX_REACTIVATE_RETRY_TIMES)
    {
        srv_tethering_cntx.reactivate_retry_times = 0;
        srv_tethering_report_app_switch_cnf(
            tethering_type,
            SRV_TETHERING_STATUS_SRV_OFF,
            MMI_FALSE);
    }
    else
    {
        srv_tethering_abm_send_activate_req(tethering_type);
    }
}


mmi_ret srv_tethering_mode_switch_notify_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mode_switch_notify_struct *switch_notify = (srv_mode_switch_notify_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_MODE_SWITCH_NOTIFY_HDLR,
        switch_notify->curr_flight_mode,
        switch_notify->select_flight_mode);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY:
        {
            srv_tethering_notify_app_change_avail_status(MMI_FALSE);
            if (srv_tethering_get_status(SRV_TETHERING_TYPE_USB) == SRV_TETHERING_STATUS_SRV_ON &&
                switch_notify->select_flight_mode == SRV_MODE_SWITCH_ON)
            {
                srv_tethering_set_reactivate_flag(SRV_TETHERING_TYPE_USB, MMI_TRUE);
            }
            else if (switch_notify->select_flight_mode == SRV_MODE_SWITCH_ON)
            {
                srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].disconn_cause =
                    SRV_TETHERING_DISCONNECT_CAUSE_FLIGHT_MODE;
            }
            break;
        }

        case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
        {
            if (switch_notify->select_flight_mode == SRV_MODE_SWITCH_ON)
            {
                srv_tethering_notify_app_change_avail_status(MMI_FALSE);
            }
            else
            {
                if (srv_tethering_get_status(SRV_TETHERING_TYPE_USB) == SRV_TETHERING_STATUS_SRV_OFF &&
                    srv_tethering_get_reactivate_flag(SRV_TETHERING_TYPE_USB) == MMI_TRUE)
                {
                    srv_tethering_reactivate_demand_ind_app(SRV_TETHERING_TYPE_USB);
                }
                srv_tethering_notify_app_change_avail_status(MMI_TRUE);
            }
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


mmi_ret srv_tethering_nw_availability_changed_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *avail_changed_evt =
        (srv_nw_info_service_availability_changed_evt_struct*)evt;
    srv_dtcnt_sim_type_enum sim_type;
    srv_tethering_type_enum type = (srv_tethering_type_enum)0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_dtcnt_get_sim_preference(&sim_type);
    if (sim_type > SRV_DTCNT_SIM_TYPE_NONE)
    {
        if (avail_changed_evt->new_status == SRV_NW_INFO_SA_FULL_SERVICE &&
            avail_changed_evt->sim == mmi_frm_index_to_sim(sim_type - 1))
        {
            for (; type < SRV_TETHERING_TYPE_ALL; type++)
            {
                if ((srv_tethering_cntx.common_info[type].disconn_cause == SRV_TETHERING_DISCONNECT_CAUSE_SIM_OFF ||
                     srv_tethering_cntx.common_info[type].disconn_cause == SRV_TETHERING_DISCONNECT_CAUSE_NETWORK) &&
                    srv_tethering_get_status(type) == SRV_TETHERING_STATUS_SRV_OFF)
                {
                    srv_tethering_reactivate_demand_ind_app(type);
                }
            }
        }
    }
    return MMI_RET_OK;
}


srv_tethering_launch_result_enum srv_tethering_check_launch_main_menu_capab(void)
{
    if (srv_sim_ctrl_any_sim_is_available() == MMI_FALSE)
    {
        return SRV_TETHERING_LAUNCH_RESULT_UNAVAILABLE_SIM;
    }
    else if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        return SRV_TETHERING_LAUNCH_RESULT_FLIGHT_MODE;
    }
    else if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
    {
        return SRV_TETHERING_LAUNCH_RESULT_SIM_MODE_OFF;
    }
    else
    {
        return SRV_TETHERING_LAUNCH_RESULT_OK;
    }
}


// must set conn info before call this function
srv_tethering_launch_result_enum srv_tethering_check_launch_capab(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_launch_result_enum result = SRV_TETHERING_LAUNCH_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_tethering_check_launch_capab_common(tethering_type);
    if(result == SRV_TETHERING_LAUNCH_RESULT_OK)
    {
        MMI_ASSERT(CBM_SIM_ID_SIM1 == 0);
        result = srv_tethering_check_launch_capab_nw(mmi_frm_index_to_sim((U32)srv_tethering_cntx.conn_info.used_sim));
        if(result == SRV_TETHERING_LAUNCH_RESULT_OK)
        {
            result = srv_tethering_check_launch_capab_acct(tethering_type, srv_tethering_get_curr_common_dtcnt());
        }
    }

    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_LAUNCH_CAPAB,
        tethering_type,
        result);
    return result;
}


srv_tethering_launch_result_enum srv_tethering_check_launch_capab_common(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_launch_result_enum result = SRV_TETHERING_LAUNCH_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (tethering_type)
    {
        case SRV_TETHERING_TYPE_WIFI_HS:
        {
            if (srv_tethering_get_status(SRV_TETHERING_TYPE_USB) != SRV_TETHERING_STATUS_SRV_OFF)
            {
                result = SRV_TETHERING_LAUNCH_RESULT_USB_TETHERING_ACTIVATED;
                break;
            }

            if ((srv_dtcnt_wlan_status() & (SRV_DTCNT_WLAN_STATUS_ACTIVE | SRV_DTCNT_WLAN_STATUS_CONNECTED)) != 0)
            {
                result = SRV_TETHERING_LAUNCH_RESULT_WLAN_ACTIVATED;
                break;
            }
        }
            break;

        case SRV_TETHERING_TYPE_USB:
        {
            if (srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS) != SRV_TETHERING_STATUS_SRV_OFF)
            {
                result = SRV_TETHERING_LAUNCH_RESULT_WIFI_TETHERING_ACTIVATED;
                break;
            }

            if (srv_tethering_cntx.dialup_status == MMI_TRUE)
            {
                result = SRV_TETHERING_LAUNCH_RESULT_DIALUP_ACTIVATED;
                break;
            }
        }
            break;

        default:
            break;
    }

    if (srv_tethering_get_status(tethering_type) == SRV_TETHERING_STATUS_SRV_ON)
    {
        result = SRV_TETHERING_LAUNCH_RESULT_ALREADY_ACTIVATED;
    }
    else if (srv_tethering_is_switching(tethering_type) == MMI_TRUE)
    {
        result = SRV_TETHERING_LAUNCH_RESULT_ON_SWITCHING;
    }
    else if (srv_sim_ctrl_any_sim_is_available() == MMI_FALSE)
    {
        result = SRV_TETHERING_LAUNCH_RESULT_UNAVAILABLE_SIM;
    }
    else if (srv_mode_switch_is_network_service_available() == MMI_FALSE)
    {
        result = SRV_TETHERING_LAUNCH_RESULT_FLIGHT_MODE;
    }
    else if (srv_mode_switch_get_current_mode() == SRV_MODE_SWITCH_ALL_OFF)
    {
        result = SRV_TETHERING_LAUNCH_RESULT_SIM_MODE_OFF;
    }

    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_LAUNCH_CAPAB_COMMON,
        tethering_type,
        result);

    return result;
}


srv_tethering_launch_result_enum srv_tethering_check_launch_capab_nw(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_launch_result_enum result = SRV_TETHERING_LAUNCH_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_mode_switch_get_network_mode(sim) == SRV_MODE_SWITCH_OFF)
    {
        result = SRV_TETHERING_LAUNCH_RESULT_SIM_MODE_OFF;
    }
    else if (srv_nw_info_get_service_availability(sim) != SRV_NW_INFO_SA_FULL_SERVICE ||
             srv_cbm_is_sim_nwk_srv_disallowed((cbm_sim_id_enum)mmi_frm_sim_to_index(sim), CBM_PS) == MMI_TRUE)
    {
        result = SRV_TETHERING_LAUNCH_RESULT_NETWORK_NOT_READY;
    }
    else if (srv_nw_info_get_protocol(sim) == MMI_GSM &&
             srv_ucm_is_any_call() == MMI_TRUE)
    {
        result = SRV_TETHERING_LAUNCH_RESULT_INCALL;
    }
    else
    {
        result = SRV_TETHERING_LAUNCH_RESULT_OK;
    }


    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_LAUNCH_CAPAB_NW,
        sim,
        result);
    return result;
}


srv_tethering_launch_result_enum srv_tethering_check_launch_capab_acct(srv_tethering_type_enum tethering_type, U32 data_account_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 encode_account_id, auto_account_id;
    srv_dtcnt_result_enum ret;
    srv_tethering_launch_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    encode_account_id =
        cbm_encode_data_account_id(
            data_account_id,
            cbm_get_sim_id(data_account_id),
            srv_tethering_cntx.common_info[tethering_type].cbm_app_id,
            MMI_FALSE);
    // check if could get the real account
    ret = srv_dtcnt_get_auto_acc_id(encode_account_id, &auto_account_id);

    if (ret == SRV_DTCNT_RESULT_SUCCESS)
    {
        if (cbm_get_original_account(auto_account_id) == CBM_INVALID_NWK_ACCT_ID ||
            cbm_get_original_account(auto_account_id) == CBM_DEFAULT_ACCT_ID)
        {
            result = SRV_TETHERING_LAUNCH_RESULT_INVALID_ACCOUNT;
        }
        else
        {
            result = SRV_TETHERING_LAUNCH_RESULT_OK;
        }
    }
    else
    {
        result = SRV_TETHERING_LAUNCH_RESULT_INVALID_ACCOUNT;
    }

    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_LAUNCH_CAPAB_ACCT,
        tethering_type,
        data_account_id,
        auto_account_id,
        result);

    return result;
}


void srv_tethering_set_reactivate_flag(srv_tethering_type_enum tethering_type, MMI_BOOL reactivate_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tethering_cntx.common_info[tethering_type].reactivate_flag = reactivate_flag;
}


MMI_BOOL srv_tethering_get_reactivate_flag(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_tethering_cntx.common_info[tethering_type].reactivate_flag;
}


void srv_tethering_reg_reactivate_demand_cb_hdlr(srv_tethering_type_enum tethering_type, srv_tethering_reactivate_demand_ind_func_ptr_type cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tethering_cntx.common_info[tethering_type].reactivate_demand_func_ptr = cb;
}


void srv_tethering_reactivate_demand_ind_app(srv_tethering_type_enum tethering_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_reactivate_demand_ind_func_ptr_type func_ptr =
        srv_tethering_cntx.common_info[tethering_type].reactivate_demand_func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // trace
    srv_tethering_reactivate_stop_timer(tethering_type);
    srv_tethering_set_ext_status(tethering_type, SRV_TETHERING_EXT_STATUS_REACTIVATE);
    if (func_ptr != NULL)
    {
        func_ptr(tethering_type);
    }
}


mmi_ret srv_tethering_dtcnt_sim_prefer_update_hdlr(mmi_event_struct *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_sim_preference_update_ind_evt_struct *evt =
        (srv_dtcnt_sim_preference_update_ind_evt_struct*)param;
    srv_tethering_type_enum type = (srv_tethering_type_enum)0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; type < SRV_TETHERING_TYPE_ALL; type++)
    {
        if (evt->sim_id != evt->sim_id_old &&
            srv_tethering_is_off(type) == MMI_FALSE)
        {
            srv_tethering_stop(type, NULL, NULL);
        }
    }
    return MMI_RET_OK;
}

#ifdef __MMI_TETHERING_WIFI__
void srv_tethering_enable_auto_turn_off(MMI_BOOL enable_flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].auto_turn_off_flag = enable_flag;
    WriteValue(NVRAM_TETHERING_AUTO_TURN_OFF_FLAG, &enable_flag, DS_BYTE, &error);
    if (enable_flag == MMI_TRUE)
    {
        if (srv_tethering_get_status(SRV_TETHERING_TYPE_WIFI_HS) == SRV_TETHERING_STATUS_SRV_ON &&
            srv_tethering_get_sta_num(SRV_TETHERING_TYPE_WIFI_HS) == 0)
        {
            srv_tethering_start_auto_turn_off_timer();
        }
    }
    else
    {
        srv_tethering_stop_auto_turn_off_timer();
    }
}


MMI_BOOL srv_tethering_check_auto_turn_off_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(
        NVRAM_TETHERING_AUTO_TURN_OFF_FLAG,
        &srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].auto_turn_off_flag,
        DS_BYTE,
        &error);
    return srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].auto_turn_off_flag;
}


void srv_tethering_start_auto_turn_off_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (IsMyTimerExist(TETHERING_AUTO_TURN_OFF_TIMER_ID) == MMI_FALSE &&
        srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].remaining_time == 0)
    {
        srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].remaining_time = SRV_TETHERING_WIFI_AUTO_TURN_OFF_TIME;
        StartTimer(
            TETHERING_AUTO_TURN_OFF_TIMER_ID,
            1000,
            srv_tethering_auto_turn_off_timer_timeout_hdlr);
    }
}


void srv_tethering_stop_auto_turn_off_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopTimer(TETHERING_AUTO_TURN_OFF_TIMER_ID);
    srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].remaining_time = 0;
}


void srv_tethering_auto_turn_off_timer_timeout_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].remaining_time--;
    if (srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].remaining_time == 0)
    {
        srv_tethering_set_ext_status(SRV_TETHERING_TYPE_WIFI_HS, SRV_TETHERING_EXT_STATUS_AUTO_TURN_OFF);
        srv_tethering_abm_send_deactivate_req(SRV_TETHERING_TYPE_WIFI_HS);
    }
    else
    {
        StartTimer(
            TETHERING_AUTO_TURN_OFF_TIMER_ID,
            1000,
            srv_tethering_auto_turn_off_timer_timeout_hdlr);
    }
}


S32 srv_tethering_auto_turn_off_get_remaining_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_tethering_cntx.common_info[SRV_TETHERING_TYPE_WIFI_HS].remaining_time;
}


mmi_ret srv_tethering_wifi_wlan_deinit_res_ind_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_deinit_res_ind_evt_struct *deinit_res_ind =
        (srv_dtcnt_wlan_deinit_res_ind_evt_struct*)evt;
    srv_dtcnt_wlan_req_res_enum res = deinit_res_ind->res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_TURN_OFF_WLAN_CB, res);

    if (srv_tethering_get_ext_status(SRV_TETHERING_TYPE_WIFI_HS) != SRV_TETHERING_EXT_STATUS_DEINIT_WLAN)
    {
        return MMI_RET_OK;
    }

    switch (res)
    {
        case SRV_DTCNT_WLAN_REQ_RES_DONE:
        {
            srv_tethering_launch_result_enum result;

            mmi_frm_cb_dereg_event(
                EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND,
                srv_tethering_wifi_wlan_deinit_res_ind_hdlr,
                NULL);
            result = srv_tethering_check_launch_capab_nw(mmi_frm_index_to_sim((U32)srv_tethering_cntx.conn_info.used_sim));
            if (result == SRV_TETHERING_LAUNCH_RESULT_OK)
            {
                srv_tethering_set_ext_status(
                    SRV_TETHERING_TYPE_WIFI_HS,
                    SRV_TETHERING_EXT_STATUS_NONE);
                srv_tethering_abm_send_activate_req(SRV_TETHERING_TYPE_WIFI_HS);
            }
            else
            {
                srv_tethering_set_status(
                    SRV_TETHERING_TYPE_WIFI_HS,
                    SRV_TETHERING_STATUS_SRV_OFF);
                srv_tethering_report_app_switch_cnf(
                    SRV_TETHERING_TYPE_WIFI_HS,
                    SRV_TETHERING_STATUS_SRV_OFF,
                    MMI_FALSE);
            }

            break;
        }

        case SRV_DTCNT_WLAN_REQ_RES_TERMINATED:
        case SRV_DTCNT_WLAN_REQ_RES_FAILED:
        {
            srv_tethering_set_status(
                SRV_TETHERING_TYPE_WIFI_HS,
                SRV_TETHERING_STATUS_SRV_OFF);
            srv_tethering_set_ext_status(
                SRV_TETHERING_TYPE_WIFI_HS,
                SRV_TETHERING_EXT_STATUS_NONE);
            srv_tethering_report_app_switch_cnf(
                SRV_TETHERING_TYPE_WIFI_HS,
                SRV_TETHERING_STATUS_SRV_OFF,
                MMI_FALSE);
            mmi_frm_cb_dereg_event(
                EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND,
                srv_tethering_wifi_wlan_deinit_res_ind_hdlr,
                NULL);
            break;
        }

        case SRV_DTCNT_WLAN_REQ_RES_DUPLICATED:
        {
            break;
        }

        default:
            break;
    }
    return MMI_RET_OK;
}


void srv_tethering_wifi_hs_get_settings(srv_tethering_wifi_hs_settings_struct *settings)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_srv_tethering_wifi_hs_settings_struct nvram_record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(NVRAM_EF_SRV_TETHERING_WIFI_HS_MAX_SSID_LEN == SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN);
    MMI_ASSERT(NVRAM_EF_SRV_TETHERING_WIFI_HS_MAX_PSK_LEN == SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN);
    //write to nvram
    ReadRecord(
        NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_LID,
        1,
        &nvram_record,
        NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_SIZE,
        &error);

    memcpy(
        settings->ssid,
        nvram_record.ssid,
        SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN * sizeof(settings->ssid[0]));

    settings->auth_mode =
        (srv_tethering_wifi_hs_auth_mode_enum)nvram_record.auth_mode;

    strncpy(
        (CHAR*)settings->psk,
        (CHAR*)nvram_record.psk,
        SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN);
    settings->max_sta_num = HOSTAP_STA_MAX_NUM;
}


void srv_tethering_wifi_hs_save_settings(srv_tethering_wifi_hs_settings_struct *settings)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    nvram_ef_srv_tethering_wifi_hs_settings_struct nvram_record;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //write to nvram
    MMI_ASSERT(strlen((CHAR*)settings->ssid) <= HOSTAP_SSID_MAX_LEN);
    MMI_ASSERT(strlen((CHAR*)settings->psk) <= HOSTAP_PSK_MAX_LEN);
    MMI_ASSERT(settings->max_sta_num <= HOSTAP_STA_MAX_NUM);

    memcpy(
        nvram_record.ssid,
        settings->ssid,
        SRV_TETHERING_HOSTAP_SSID_MAX_BUF_LEN * sizeof(nvram_record.ssid[0]));
    nvram_record.auth_mode =
        (kal_uint16)settings->auth_mode;
    strncpy(
        (CHAR*)nvram_record.psk,
        (CHAR*)settings->psk,
        SRV_TETHERING_HOSTAP_PSK_MAX_BUF_LEN);
    nvram_record.max_sta_num = settings->max_sta_num;

    WriteRecord(
        NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_LID,
        1,
        &nvram_record,
        NVRAM_EF_SRV_TETHERING_WIFI_HS_SETTINGS_SIZE,
        &error);
}


void srv_tethering_wifi_hs_reset_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // set the default nvram setting
}


hostap_auth_alg_enum srv_tethering_wifi_hs_auth_mode_srv_to_ps(srv_tethering_wifi_hs_auth_mode_enum app_auth_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(app_auth_mode)
    {
        case SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN:
            return HOSTAP_AUTH_ALG_NONE;

        case SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK:
            return HOSTAP_AUTH_ALG_WPA2_PSK;

        default:
            MMI_ASSERT(0);
    }
    return HOSTAP_AUTH_ALG_NONE;
}


srv_tethering_wifi_hs_auth_mode_enum srv_tethering_wifi_hs_auth_mode_ps_to_srv(hostap_auth_alg_enum ps_auth_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(ps_auth_mode)
    {
        case HOSTAP_AUTH_ALG_NONE:
            return SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN;

        case HOSTAP_AUTH_ALG_WPA2_PSK:
            return SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK;

        default:
            MMI_ASSERT(0);
    }
    return SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN;
}


void srv_tethering_wifi_hs_set_power(S8 power_db, S8 power_dbm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_abm_set_tx_pwr_req_struct *req_mode0;
    mmi_abm_set_tx_pwr_req_struct *req_mode1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_WIFI_SET_POWER, power_db, power_dbm);
    req_mode0 = OslAllocDataPtr(mmi_abm_set_tx_pwr_req_struct);
    req_mode0->mode = 0;
    req_mode0->power = power_db;
    mmi_frm_send_ilm(
        MOD_ABM,
        MSG_ID_MMI_ABM_SET_TX_PWR_REQ,
        (local_para_struct*)req_mode0,
        NULL);

    req_mode1 = OslAllocDataPtr(mmi_abm_set_tx_pwr_req_struct);
    req_mode1->mode = 1;
    req_mode1->power = power_dbm;
    mmi_frm_send_ilm(
        MOD_ABM,
        MSG_ID_MMI_ABM_SET_TX_PWR_REQ,
        (local_para_struct*)req_mode1,
        NULL);
}


void srv_tethering_wifi_change_power(srv_tethering_wifi_power_change_type_enum power_change_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tethering_wifi_power_change_type_enum orig_type = srv_tethering_cntx.wifi_power_change_type;
    srv_tethering_wifi_power_change_type_enum dest_type = power_change_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G10_TETHERING,
        TRC_SRV_TETHERING_WIFI_CHANGE_POWER,
        orig_type,
        dest_type);
    if (orig_type == dest_type ||
        srv_tethering_is_on(SRV_TETHERING_TYPE_WIFI_HS) == MMI_FALSE)
    {
        return;
    }

    srv_tethering_wifi_hs_set_power(
        power_change_dbm_tbl[dest_type] - power_change_dbm_tbl[orig_type],
        power_change_dbm_tbl[dest_type]);

    srv_tethering_cntx.wifi_power_change_type = dest_type;
}


mmi_ret srv_tethering_charbat_notify_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_charbat_evt_notify_struct *info = (srv_charbat_evt_notify_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_CHARBAT_NOTIFY_HDLR, info->status);
    if (info->status == SRV_CHARBAT_STATUS_CHARGER_IN ||
        info->status == SRV_CHARBAT_STATUS_USB_CHARGER_IN)
    {
        srv_tethering_wifi_change_power(SRV_TETHERING_WIFI_POWER_CHANGE_TYPE_IN_CHARGING);
    }
    else if (info->status == SRV_CHARBAT_STATUS_CHARGER_OUT ||
             info->status == SRV_CHARBAT_STATUS_USB_CHARGER_OUT)
    {
        srv_tethering_wifi_change_power(SRV_TETHERING_WIFI_POWER_CHANGE_TYPE_NONE);
    }
    return MMI_RET_OK;
}
#endif /* __MMI_TETHERING_WIFI__ */


#ifdef __USB_TETHERING__
void srv_tethering_usb_reg_cable_disconnect_cb_hdlr(FuncPtr cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_tethering_cntx.usb_cable_disconnect_func_ptr = cb;
}


void srv_tethering_usb_cable_disconnect_notify_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_tethering_cntx.usb_cable_disconnect_func_ptr != NULL)
    {
        srv_tethering_cntx.usb_cable_disconnect_func_ptr();
    }
}


mmi_ret srv_tethering_usb_cable_status_changed_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_USB_SUPPORT__
    srv_usb_mmi_notify_action_enum act = (srv_usb_mmi_notify_action_enum)(evt->user_data);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (act == SRV_USB_MMI_NOTIFY_PLUGOUT)
    {
        // this may only be used when usb tethering is inactivated and there is some popup need to be removed
        MMI_TRACE(MMI_CONN_TRC_G10_TETHERING, TRC_SRV_TETHERING_USB_CABLE_DISCONN);
        srv_tethering_usb_cable_disconnect_notify_app();
        srv_tethering_stop(SRV_TETHERING_TYPE_USB, NULL, NULL);
    }
#endif /* __MMI_USB_SUPPORT__ */
    return MMI_RET_OK;
}

#endif /* __USB_TETHERING__ */

#define UT
#ifndef __MTK_TARGET__
void srv_tethering_ut_activate_req_hdlr(void *msg)
{
    mmi_abm_share_bearer_activate_req_struct *req = (mmi_abm_share_bearer_activate_req_struct*)msg;
    mmi_abm_share_bearer_activate_cnf_struct *cnf;

    cnf = OslAllocDataPtr(mmi_abm_share_bearer_activate_cnf_struct);
    cnf->share_bearer = req->share_bearer;
    cnf->result = MMI_TRUE;
    mmi_frm_send_ilm(
        MOD_MMI,
        MSG_ID_MMI_ABM_SHARE_BEARER_ACTIVATE_CNF,
        (local_para_struct*)cnf,
        NULL);
}


void srv_tethering_ut_deactivate_req_hdlr(void *msg)
{
    mmi_abm_share_bearer_deactivate_req_struct *req = (mmi_abm_share_bearer_deactivate_req_struct*)msg;
    mmi_abm_share_bearer_deactivate_cnf_struct *cnf;

    cnf = OslAllocDataPtr(mmi_abm_share_bearer_deactivate_cnf_struct);
    cnf->share_bearer = req->share_bearer;
    cnf->result = MMI_TRUE;
    mmi_frm_send_ilm(
        MOD_MMI,
        MSG_ID_MMI_ABM_SHARE_BEARER_DEACTIVATE_CNF,
        (local_para_struct*)cnf,
        NULL);
}
#endif /* __MTK_TARGET__ */

#endif /* __MMI_TETHERING__ */
