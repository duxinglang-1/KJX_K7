/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * A2dpSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * A2dp connection service
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

//#include "MMI_include.h"
#include "MMI_features.h"
#if defined(__MMI_A2DP_SUPPORT__)

/***************************************************************************** 
* Included files
*****************************************************************************/
//#include "ProtocolEvents.h"

/* Trace Header Files */
#ifdef KUR_DECODE
#include "kuroapi.h"
#include "l1audio.h"
#include "med_main.h"
#endif /*KUR_DECODE*/

#include "med_struct.h"
#include "Aud_main.h"

/* a2dp header files */
//#include "bt_a2dp_struct.h"
#include "bt_a2dp.h"

#include "BTMMIScrGprots.h"

#include "BtcmSrvGprot.h"
//#include "BtcmCuiGprot.h"
//#include "BTMMIA2DP.h"
#ifdef __MMI_AVRCP_SUPPORT__
#include "BTMMIAVRCPGProt.h"
#endif
// mtk solution only

#include "mdi_datatype.h"
#include "mdi_audio.h"
//#include "bttypes.h"

//#include "BTMMISCOPathGprots.h"
#ifdef __MMI_BT_AUDIO_VIA_SCO__                  
#include "mmi_rp_srv_btsco_def.h"
#include "BthScoPathSrvGProt.h"
#endif

#include "av_bt.h"
#include "mmi_rp_srv_a2dp_def.h"
//#include "AVBTResDef.h"

//#include "Nvram_common_defs.h"
//#include "ConnectivityResDef.h"  /* for STR_BT_PROHIBIT_BY_SIMAP used by sap. */
//#include "MobileTVPlayerGProt.h"
//#include "CommonScreens.h"

//#include "conversions.h"

#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
#include "BTMMIAVRCPGProt.h"
#endif
//#include "SimDetectionGprot.h"

#if defined(AMR_CODEC)
#define AMR_DECODE
#endif

#include "A2dpSrv.h"
#ifdef __MMI_AVRCP_SUPPORT__
#include "AvrcpSrvGprot.h"
#endif
#include "BtAudioSrvGProt.h"

#include "DtcntSrvGprot.h"

#include "kal_general_types.h"
#include "bt_a2dp_base_struct.h"
#include "A2dpSrvGprot.h"
#include "stack_config.h"
#include "string.h"
#include "MMIDataType.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_conn_app_trc.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "MMI_media_app_trc.h"
#include "mmi_media_app_trc.h"
#include "fsal.h"
//#include "kurotypedef.h"
#include "mmi_frm_timer_gprot.h"
#include "wgui_categories_list.h"
#include "BTMMIA2DPScr.h"

typedef struct
{
    kal_uint8 cap_index;
    kal_uint8 cap_count;
    bt_sep_info_struct info;
    bt_a2dp_audio_cap_struct cap_list[MAX_NUM_REMOTE_CAPABILITIES];
} av_bt_sep_struct;

typedef struct
{
    kal_uint8 sep_index;
    kal_uint8 sep_count;
    av_bt_sep_struct sep_list[MAX_NUM_REMOTE_SEIDS];
    srv_bt_cm_bt_addr bt_addr;
} av_bt_dev_struct;

typedef struct
{
    A2DP_SRV_CALLBACK  retry_success_callback; /* this is a temp patch for MT6601 */
    A2DP_SRV_CALLBACK  callback;               /* current callback */
    A2DP_SRV_CALLBACK  default_callbacks[1];   /* if current callback is NULL, use default callback */
    A2DP_SRV_CHECK_OUTPUT_CALLBACK check_output_callback; /* to ask a2dp app if output to a2dp or not for ind case */
    A2DP_SRV_IS_OUTPUT_TO_BT_CALLBACK is_output_to_bt_callback; /* to ask a2dp app if output to a2dp or not */
    A2DP_SRV_GET_BT_HEADSET_CALLBACK get_bt_headset_callback; /* to query a2dp app for current headset address */
    kal_uint32 codec_seq_no;
    srv_bt_cm_bt_addr bt_addr;
    kal_uint16 connect_id;
    kal_bool is_inquiry;
    kal_bool is_codec_open;
    kal_bool need_stop;
    kal_bool need_reconnect;
    kal_bool need_reconfig;
    kal_bool bad_acp_seid_retry; /*to indicate if av_bt has handled bad_acp_seid error casue once*/
    kal_bool bad_state_retry; /* to indicate if av_bt has handled bad_state error casue once*/
    kal_bool sep_ind_use_retry; /* to indicate if av_bt has handled sep_ind_use error casue once*/
    kal_bool connect_post_proc;
    kal_uint8 local_seid;
    kal_uint8 state;
    kal_uint8 wait;
    kal_uint8 stream_handle;
    kal_uint8 req_cfg_index;
    av_bt_dev_struct dev;
    kal_uint16 disconnect_delay;
    bt_a2dp_audio_cap_struct req_cfg[2];
    bt_a2dp_audio_cap_struct tmp_cfg;
    bt_a2dp_audio_cap_struct cfg;
} av_bt_ctx_struct;

typedef struct
{
    srv_a2dp_state_enum state;
    U8 conn_req_flag;
    U8 disc_req_flag;
    U16 connect_id;
    srv_bt_cm_bt_addr bd_addr;
    S32 cmgr_id;
} mmi_a2dp_cntx_struct;

av_bt_ctx_struct av_bt_ctx;

extern void aud_send_bt_open_codec_req(module_type src_mod_id, 
    bt_a2dp_audio_cap_struct *cfg,
    kal_uint8 stream_handle,
    kal_bool immediate,
    kal_uint32 seq_no);
extern void aud_send_bt_close_codec_req(module_type src_mod_id);

extern kal_int16 med_get_media_type(kal_wchar *file_name);

extern const bt_a2dp_sbc_codec_cap_struct sbc_cap[1];
#if defined(DAF_DECODE) && !defined(__LOW_COST_SUPPORT_COMMON__)
extern const bt_a2dp_mp3_codec_cap_struct mp3_cap[1];
#endif

mmi_a2dp_cntx_struct g_mmi_a2dp_cntx;

static const srv_bt_cm_profile_struct g_a2dp_prof = {
    SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID,
    srv_bt_a2dp_activate_req,
    srv_bt_a2dp_deactivate_req,
    srv_bt_a2dp_disconnect_req_by_cm
};

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* init state & callback */
    av_bt_ctx.state = AV_BT_STATE_IDLE;
    av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
    av_bt_ctx.local_seid = 0x01;  /* valid between 0x01 ~ 0x3E */
    /* set msg hdlrs */
    SetProtocolEventHandler(srv_a2dp_discover_stream_cnf, MSG_ID_BT_A2DP_SEP_DISCOVER_CNF);
    SetProtocolEventHandler(srv_a2dp_discover_stream_ind, MSG_ID_BT_A2DP_SEP_DISCOVER_IND);
    SetProtocolEventHandler(srv_a2dp_get_stream_cap_cnf, MSG_ID_BT_A2DP_CAPABILITIES_GET_CNF);
    SetProtocolEventHandler(srv_a2dp_get_stream_cap_ind, MSG_ID_BT_A2DP_CAPABILITIES_GET_IND);
    SetProtocolEventHandler(srv_a2dp_config_stream_cnf, MSG_ID_BT_A2DP_STREAM_CONFIG_CNF);
    SetProtocolEventHandler(srv_a2dp_config_stream_ind, MSG_ID_BT_A2DP_STREAM_CONFIG_IND);
    SetProtocolEventHandler(srv_a2dp_open_stream_cnf, MSG_ID_BT_A2DP_STREAM_OPEN_CNF);
    SetProtocolEventHandler(srv_a2dp_open_stream_ind, MSG_ID_BT_A2DP_STREAM_OPEN_IND);
    SetProtocolEventHandler(srv_a2dp_start_stream_cnf, MSG_ID_BT_A2DP_STREAM_START_CNF);
    SetProtocolEventHandler(srv_a2dp_start_stream_ind, MSG_ID_BT_A2DP_STREAM_START_IND);
    SetProtocolEventHandler(srv_a2dp_pause_stream_cnf, MSG_ID_BT_A2DP_STREAM_PAUSE_CNF);
    SetProtocolEventHandler(srv_a2dp_pause_stream_ind, MSG_ID_BT_A2DP_STREAM_PAUSE_IND);
    SetProtocolEventHandler(srv_a2dp_close_stream_cnf, MSG_ID_BT_A2DP_STREAM_CLOSE_CNF);
    SetProtocolEventHandler(srv_a2dp_close_stream_ind, MSG_ID_BT_A2DP_STREAM_CLOSE_IND);
    SetProtocolEventHandler(srv_a2dp_abort_stream_cnf, MSG_ID_BT_A2DP_STREAM_ABORT_CNF);
    SetProtocolEventHandler(srv_a2dp_abort_stream_ind, MSG_ID_BT_A2DP_STREAM_ABORT_IND);
    SetProtocolEventHandler(srv_a2dp_close_codec_ind, MSG_ID_MEDIA_BT_CLOSE_CODEC_IND);

    MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_IDLE);

    SetProtocolEventHandler(srv_bt_a2dp_activate_cnf_hdlr, MSG_ID_BT_A2DP_ACTIVATE_CNF);
    SetProtocolEventHandler(srv_bt_a2dp_deactivate_cnf_hdlr, MSG_ID_BT_A2DP_DEACTIVATE_CNF);
    SetProtocolEventHandler(srv_bt_a2dp_connect_cnf_hdlr, MSG_ID_BT_A2DP_SIGNAL_CONNECT_CNF);
    SetProtocolEventHandler(srv_bt_a2dp_connect_ind_hdlr, MSG_ID_BT_A2DP_SIGNAL_CONNECT_IND);
    SetProtocolEventHandler(srv_bt_a2dp_disconnect_cnf_hdlr, MSG_ID_BT_A2DP_SIGNAL_DISCONNECT_CNF);
    SetProtocolEventHandler(srv_bt_a2dp_disconnect_ind_hdlr, MSG_ID_BT_A2DP_SIGNAL_DISCONNECT_IND);

    srv_bt_cm_profile_register(&g_a2dp_prof);

#ifdef __WIFI_BT_SINGLE_ANTENNA_SUPPORT__
    bt_a2dp_register_min_bit_rate_callback(srv_bt_a2dp_if_apply_min_bit_rate);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_auto_disconnect_dalay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msec  [IN] delay time in milli second
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_auto_disconnect_dalay(kal_uint16 msec)
{
    av_bt_ctx.disconnect_delay = msec;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_activate_req
 * DESCRIPTION
 *  send a activate req to bluetooth task
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_activate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(g_mmi_a2dp_cntx.state == SRV_A2DP_STATE_IDLE);

    bt_a2dp_send_activate_req(MOD_MMI, BT_A2DP_SOURCE);

    MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_ACTIVATING);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_activate_cnf_hdlr
 * DESCRIPTION
 *  handle a activate cnf from bluetooth task
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_activate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_activate_cnf_struct *msg_p = (bt_a2dp_activate_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Should not activate fail */
    if (msg_p->result == BT_A2DP_RESULT_OK)
    {
        if (g_mmi_a2dp_cntx.state == SRV_A2DP_STATE_ACTIVATING)
        {
            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_ACTIVATED);

            srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID);
        }
    }
    else
    {
        ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_deactivate_req
 * DESCRIPTION
 *  if it's in 'DEACTIVATED' state, then send a deactivate req to bluetooth task;
 *  otherwise, move on to 'DEACTIVATING' state and wait for connect or disconnect cnf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_deactivate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (g_mmi_a2dp_cntx.state)
    {
        case SRV_A2DP_STATE_ACTIVATED:
            bt_a2dp_send_deactivate_req(MOD_MMI);
            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_DEACTIVATING);
            break;
        case SRV_A2DP_STATE_CONNECTED:
            bt_a2dp_send_signal_disconnect_req(MOD_MMI, g_mmi_a2dp_cntx.connect_id);
            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_DEACTIVATING);
            break;
        case SRV_A2DP_STATE_CONNECTING:
        case SRV_A2DP_STATE_DISCONNECTING:
            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_DEACTIVATING);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_deactivate_cnf_hdlr
 * DESCRIPTION
 *  This function is to handle a deactivate cnf from bluetooth task
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_deactivate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_deactivate_cnf_struct *msg_p = (bt_a2dp_deactivate_cnf_struct*) msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_a2dp_cntx.state == SRV_A2DP_STATE_DEACTIVATING)
    {
        if (msg_p->result == BT_A2DP_RESULT_OK || msg_p->result == BT_A2DP_RESULT_PANIC)
        {
            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_IDLE);

            srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID);
        #ifdef __MMI_BT_AUDIO_SUPPORT__
            srv_btsco_deactivate_cnf_hdlr();
        #endif
        }
        else
        {
            ASSERT(0);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_connect_req
 * DESCRIPTION
 *  send a connect req to bluetooth task
 * PARAMETERS
 *  dev_addr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_connect_req(srv_bt_cm_bt_addr dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_device_addr_struct bd_addr;
    S32 cmgr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(g_mmi_a2dp_cntx.state == SRV_A2DP_STATE_CONNECTING)
    {
        return;
    }

    ASSERT(g_mmi_a2dp_cntx.state == SRV_A2DP_STATE_ACTIVATED);

    cmgr_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID, &dev_addr, NULL);

    g_mmi_a2dp_cntx.cmgr_id = cmgr_id;

    bd_addr.lap = dev_addr.lap;
    bd_addr.uap = dev_addr.uap;
    bd_addr.nap = dev_addr.nap;

    g_mmi_a2dp_cntx.conn_req_flag |= SRV_A2DP_REQ_FLAG_APP;

    if(!srv_a2dp_cmp_bt_addr(&av_bt_ctx.dev.bt_addr, &dev_addr))
    {
        /* connect from CM directly, always reset dev */
        memset(&av_bt_ctx.dev, 0, sizeof(av_bt_dev_struct));
        memcpy(&av_bt_ctx.dev.bt_addr, &dev_addr, sizeof(srv_bt_cm_bt_addr));
    }

    bt_a2dp_send_signal_connect_req(MOD_MMI, &bd_addr, BT_A2DP_SOURCE);

    MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_CONNECTING);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_connect_cnf_hdlr
 * DESCRIPTION
 *  handle a connect cnf from bluetooth task
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_connect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_signal_connect_cnf_struct *msg_p = (bt_a2dp_signal_connect_cnf_struct*) msg;
    bt_device_addr_struct *bd_addr = &msg_p->device_addr;
    BOOL success;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_a2dp_cntx.conn_req_flag = 0;
    
    if (msg_p->result == BT_A2DP_RESULT_OK)
    {
        success = TRUE;
        g_mmi_a2dp_cntx.bd_addr.lap = bd_addr->lap;
        g_mmi_a2dp_cntx.bd_addr.uap = bd_addr->uap;
        g_mmi_a2dp_cntx.bd_addr.nap = bd_addr->nap;
        g_mmi_a2dp_cntx.connect_id = msg_p->connect_id;
    }
    else
    {
        success = FALSE;
    }

    switch (g_mmi_a2dp_cntx.state)
    {
        case SRV_A2DP_STATE_CONNECTING:
        {
            if (success)
            {
                MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_CONNECTED);
            }
            else
            {
                MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_ACTIVATED);
            }

            if (success)
                srv_bt_cm_connect_ind(g_mmi_a2dp_cntx.cmgr_id);
            else
            {
                srv_bt_cm_stop_conn(g_mmi_a2dp_cntx.cmgr_id);
                g_mmi_a2dp_cntx.cmgr_id = 0;
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
#endif            
            srv_a2dp_connect_cnf(msg);
            
            break;
        }

        /*this means right after the connect req, there is a connect ind comes
          in this case, the bt profile layer will compare the bt_address, if identical
          then the send cnf with success, if not, then send cnf with bad sate*/
        case SRV_A2DP_STATE_CONNECTED:
        {
            srv_a2dp_connect_cnf(msg);
            break;
        }

        case SRV_A2DP_STATE_DEACTIVATING:
        {
            srv_a2dp_connect_cnf(msg);

            if (success)
            {
                bt_a2dp_send_signal_disconnect_req(MOD_MMI, msg_p->connect_id);
            }
            else    /* send a activate req */
            {
                bt_a2dp_send_deactivate_req(MOD_MMI);
            }
            break;
        }
        
        default:
        {
            //ASSERT(0);
            /*mark the assert because in many cases, the cnf is fail because bad state 
              so we shall just neglect this cnf*/
            break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_connect_ind_hdlr
 * DESCRIPTION
 *  handle a connect ind from bluetooth task
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_connect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_signal_connect_ind_struct *msg_p = (bt_a2dp_signal_connect_ind_struct*) msg;
    bt_device_addr_struct *bd_addr = &msg_p->device_addr;
    S32 cmgr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_a2dp_cntx.bd_addr.lap = bd_addr->lap;
    g_mmi_a2dp_cntx.bd_addr.uap = bd_addr->uap;
    g_mmi_a2dp_cntx.bd_addr.nap = bd_addr->nap;
    g_mmi_a2dp_cntx.conn_req_flag = 0;
    g_mmi_a2dp_cntx.connect_id = msg_p->connect_id;

    switch (g_mmi_a2dp_cntx.state)
    {
        case SRV_A2DP_STATE_ACTIVATED:
            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_CONNECTED);
            cmgr_id = srv_bt_cm_start_conn(
                        MMI_TRUE,
                        SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID,
                        &g_mmi_a2dp_cntx.bd_addr,
                        NULL);

            g_mmi_a2dp_cntx.cmgr_id = cmgr_id;

            srv_a2dp_connect_ind(msg);

            if(g_mmi_a2dp_cntx.cmgr_id > 0)
            {
                srv_bt_cm_connect_ind(g_mmi_a2dp_cntx.cmgr_id);
            }
            else
            {
                g_mmi_a2dp_cntx.cmgr_id = 0 ;
            }
#if 0            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

            break;
        case SRV_A2DP_STATE_CONNECTING:
        {
            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_CONNECTED);

            srv_bt_cm_connect_ind(g_mmi_a2dp_cntx.cmgr_id);

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
#endif            
            srv_a2dp_connect_ind(msg);

            break;
         }
        case SRV_A2DP_STATE_DEACTIVATING:
            srv_a2dp_connect_ind(msg);

            /* send a activate req */
            bt_a2dp_send_signal_disconnect_req(MOD_MMI, msg_p->connect_id);
            break;
        default:
            ASSERT(0);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_disconnect_req_by_cm
 * DESCRIPTION
 *  send a disconnect req to bluetooh task
 * PARAMETERS
 *  dev_addr        [IN]        
 *  connect_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_disconnect_req_by_cm(U32 connect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!g_mmi_a2dp_cntx.cmgr_id || g_mmi_a2dp_cntx.cmgr_id != connect_id)
        return;
    
    g_mmi_a2dp_cntx.disc_req_flag |= SRV_A2DP_REQ_FLAG_CM;

    switch (g_mmi_a2dp_cntx.state)
    {
        case SRV_A2DP_STATE_CONNECTED:
        {
            if(av_bt_ctx.state >= AV_BT_STATE_OPEN)
            {
                srv_a2dp_close_stream();
            }
            else
            {
                bt_a2dp_send_signal_disconnect_req(MOD_MMI, g_mmi_a2dp_cntx.connect_id);
            }
            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_DISCONNECTING);
            break;
        }
        case SRV_A2DP_STATE_DEACTIVATING:
        case SRV_A2DP_STATE_DISCONNECTING:
            break;
        default:
            ASSERT(0);
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_disconnect_req
 * DESCRIPTION
 *  send a disconnect req to bluetooh task
 * PARAMETERS
 *  dev_addr        [IN]        
 *  connect_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_disconnect_req(srv_bt_cm_bt_addr dev_addr, U32 connect_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_a2dp_cntx.disc_req_flag |= SRV_A2DP_REQ_FLAG_APP;

    switch (g_mmi_a2dp_cntx.state)
    {
        case SRV_A2DP_STATE_CONNECTED:
        {
            if(av_bt_ctx.state >= AV_BT_STATE_OPEN)
            {
                srv_a2dp_close_stream();
            }
            else
            {
                bt_a2dp_send_signal_disconnect_req(MOD_MMI, connect_id);
            }

            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_DISCONNECTING);
            break;
        }
        case SRV_A2DP_STATE_DEACTIVATING:
            break;
        case SRV_A2DP_STATE_DISCONNECTING:
            break;
        default:
            ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_disconnect_cnf_hdlr
 * DESCRIPTION
 *  handle a disconnect cnf from bluetooth task
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_disconnect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_a2dp_cntx.disc_req_flag = 0;

    switch (g_mmi_a2dp_cntx.state)
    {
        case SRV_A2DP_STATE_DISCONNECTING:
            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_ACTIVATED);

            srv_bt_cm_stop_conn(g_mmi_a2dp_cntx.cmgr_id);
            g_mmi_a2dp_cntx.cmgr_id = 0;

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
#endif            
            srv_a2dp_disconnect_cnf(msg);

        #ifdef __MMI_AVRCP_SUPPORT__
            {
                srv_avrcp_disconnect_from_a2dp(MMI_TRUE);
                srv_avrcp_disconnect_tg_req(0);
            }
        #endif

            break;
        case SRV_A2DP_STATE_DEACTIVATING:
            srv_a2dp_disconnect_cnf(msg);
            /* send a deactivate req */
            bt_a2dp_send_deactivate_req(MOD_MMI);
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_disconnect_ind_hdlr
 * DESCRIPTION
 *  handle a disconnect ind from bluetooth task
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_disconnect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_a2dp_cntx.disc_req_flag = 0;

    switch (g_mmi_a2dp_cntx.state)
    {
        case SRV_A2DP_STATE_CONNECTED:
            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_ACTIVATED);
            /* inform CM connect result */
            srv_bt_cm_stop_conn(g_mmi_a2dp_cntx.cmgr_id);
            g_mmi_a2dp_cntx.cmgr_id = 0;
#if 0            
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            srv_a2dp_disconnect_ind(msg);
            break;
        case SRV_A2DP_STATE_DISCONNECTING:
            MMI_A2DP_STATE_TRANS(SRV_A2DP_STATE_ACTIVATED);
            /* inform CM connect result */
            srv_bt_cm_stop_conn(g_mmi_a2dp_cntx.cmgr_id);
            g_mmi_a2dp_cntx.cmgr_id = 0;
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
#endif            
            srv_a2dp_disconnect_ind(msg);
            break;
        case SRV_A2DP_STATE_DEACTIVATING:
            srv_a2dp_disconnect_ind(msg);
            /* send a activate req */
            bt_a2dp_send_deactivate_req(MOD_MMI);
            break;
        default:
            break;
    }
}

#ifdef __WIFI_BT_SINGLE_ANTENNA_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_if_apply_min_bit_rate
 * DESCRIPTION
 *  for a2dp adaptor to check if need to apply min bit rate
 * PARAMETERS
 *  voide    
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool srv_bt_a2dp_if_apply_min_bit_rate(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return ( (srv_dtcnt_wlan_status() != SRV_DTCNT_WLAN_STATUS_INACTIVE) ? KAL_TRUE : KAL_FALSE );
    
}    
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_query_state
 * DESCRIPTION
 *  query a2dp state
 * PARAMETERS
 *  voide    
 * RETURNS
 *  void
 *****************************************************************************/
srv_a2dp_state_enum srv_bt_a2dp_query_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_USER_PROF_BT_A2DP_QUERY_STATE,g_mmi_a2dp_cntx.state);
    return g_mmi_a2dp_cntx.state;
    
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_default_callback
 * DESCRIPTION
 *  This function is to set default callback handler.
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_default_callback(A2DP_SRV_CALLBACK handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*currently only support audio player*/
    av_bt_ctx.default_callbacks[0] = handler;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_check_output_callback
 * DESCRIPTION
 *  This function is to set check output path hdlr
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_check_output_callback(A2DP_SRV_CHECK_OUTPUT_CALLBACK handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    av_bt_ctx.check_output_callback = handler;

}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_is_output_to_bt_callback
 * DESCRIPTION
 *  This function is to set is output to be callback
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_is_output_to_bt_callback(A2DP_SRV_IS_OUTPUT_TO_BT_CALLBACK handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    av_bt_ctx.is_output_to_bt_callback = handler;

}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_get_bt_headset_callback
 * DESCRIPTION
 *  This function is to set get bt headset address callbackk
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_get_bt_headset_callback(A2DP_SRV_GET_BT_HEADSET_CALLBACK handler)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    av_bt_ctx.get_bt_headset_callback = handler;

}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_output_to_bt
 * DESCRIPTION
 *  to check if currently application could go through a2dp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_output_to_bt(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return av_bt_ctx.is_output_to_bt_callback();
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_bt_headset
 * DESCRIPTION
 *  to query current a2dp headset setting to pass to a2dp service for signal connection
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_bt_addr *
 *****************************************************************************/
srv_bt_cm_bt_addr *srv_a2dp_get_bt_headset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return av_bt_ctx.get_bt_headset_callback();
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  result    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_open_result(kal_int32 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    void(*callback)(S32 res) = av_bt_ctx.callback;
    void(*retry_success_callback)(S32 res) = av_bt_ctx.retry_success_callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_OPEN_RESULT,result);

    av_bt_ctx.need_reconfig = KAL_FALSE;

    if (callback)
    {
        if (result != SRV_A2DP_CALLBACK_EVENT_OPEN_OK)
        {
        #ifdef __MMI_BT_AUDIO_VIA_SCO__
            if(result == SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED)
            {
                srv_a2dp_open_result_enum ret;
                ret = srv_a2dp_open_audio_via_sco();
                if( ret == SRV_A2DP_OPEN_WAITING)
                {    
                    return;
                }
                else if(ret == SRV_A2DP_OPEN_DONE)
                {
                    result = SRV_A2DP_CALLBACK_EVENT_OPEN_SCO;
                }
            }
        #endif
            if(result == SRV_A2DP_CALLBACK_EVENT_SECURITY_BLOCK)
            {
                result = SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED;
            }
            av_bt_ctx.callback = NULL;
        }
        mdi_audio_set_pseudo_play_file_callback(NULL, NULL);        
        callback(result);
    }
    else if (result == SRV_A2DP_CALLBACK_EVENT_OPEN_OK && retry_success_callback)
    {
        mdi_audio_set_pseudo_play_file_callback(NULL, NULL);
        av_bt_ctx.callback = retry_success_callback;
        retry_success_callback(result);
    }
    else
    {
        mdi_audio_set_pseudo_play_file_callback(NULL, NULL);
    }

}

#ifndef __LOW_COST_SUPPORT_COMMON__
/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_check_handset_mp3_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  mp3_cfg    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool srv_a2dp_check_handset_mp3_config(bt_a2dp_mp3_codec_cap_struct *mp3_cfg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    bt_a2dp_audio_cap_struct temp_cap[2] ;
    kal_uint16 result ; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    temp_cap[0].codec_type = BT_A2DP_MP3;
#ifdef DAF_DECODE
    memcpy(&(temp_cap[0].codec_cap.mp3), &mp3_cap[0], sizeof(bt_a2dp_mp3_codec_cap_struct));
#endif

    temp_cap[1].codec_type = BT_A2DP_MP3;
    memcpy(&(temp_cap[1].codec_cap.mp3), mp3_cfg, sizeof(bt_a2dp_mp3_codec_cap_struct));
    
    return bt_a2dp_match_audio_capabilities(&temp_cap[0], &temp_cap[1], &result);

}
#endif /*__LOW_COST_SUPPORT_COMMON__*/

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_calc_audio_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  aud_info    [IN]
 *  aud_cfg     [IN]
 *  aud_fmt     [IN]
 *  codec_type  [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_a2dp_aud_info_to_cfg(
            audInfoStruct *aud_info,
            bt_a2dp_audio_cap_struct *aud_cfg,
            kal_int16 aud_fmt,
            kal_uint8 codec_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*kal_bool stereo = aud_info->stereo;*/
    kal_uint32 samplerate = aud_info->sampleRate;
    kal_bool result = KAL_TRUE; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (codec_type == BT_A2DP_SBC)
    {   /* SBC transcoding is necessary */
        bt_a2dp_sbc_codec_cap_struct *sbc = &aud_cfg->codec_cap.sbc;

        samplerate /= 1000;
        switch (samplerate)
        {
            case 7:
            case 8:
            case 15:
            case 16:
    #if 0
/* under construction !*/
/* under construction !*/
    #endif
            case 31:
            case 32:
                sbc->sample_rate = 0x4; /* convert to 32000 sps */
                break;
            case 10:
            case 11:
            case 21:
            case 22:
            case 43:
            case 44:
                sbc->sample_rate = 0x2; /* convert to 44100 sps */
                break;
            case 12:
            case 23:
            case 24:
            case 47:
            case 48:
                sbc->sample_rate = 0x1; /* convert to 48000 sps */
                break;
            default:
                return KAL_FALSE;
        }

    #if 0   /* defined(L1SBC_SUPPORT_MONO) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* 1 */ 
            sbc->channel_mode = 0x1;    /* default: joint-stereo */

        sbc->block_len = 0x1;       /* 16: fixed */
        sbc->subband_num = 0x1;     /* 8: fixed */
        sbc->alloc_method = 0x1;    /* loudness: fixed */
        SBC_InitiateBitPool(sbc->channel_mode, sbc->sample_rate, &sbc->min_bit_pool, &sbc->max_bit_pool);
    }
    else
    {
    #ifndef __LOW_COST_SUPPORT_COMMON__
        /* not support transcoding here, media format shall be the same with codec type */
        if (codec_type == BT_A2DP_MP3 && (aud_fmt == MDI_FORMAT_DAF || aud_fmt == MDI_FORMAT_MUSICAM))
        {                       /* MP3 streaming */
            bt_a2dp_mp3_codec_cap_struct *mp3 = &aud_cfg->codec_cap.mp3;

            mp3->layer = 0x1;
            mp3->CRC = (kal_bool)aud_info->details.DAF.CRC;
            if (aud_info->details.DAF.channel_mode == 0x00)
               mp3->channel_mode = 0x2;
            else if (aud_info->details.DAF.channel_mode == 0x01)
               mp3->channel_mode = 0x1;
            else if (aud_info->details.DAF.channel_mode == 0x02)
               mp3->channel_mode = 0x4;
            else if (aud_info->details.DAF.channel_mode == 0x03)
               mp3->channel_mode = 0x8;
            else
               return KAL_FALSE;

            mp3->MPF = KAL_FALSE;
            if (samplerate == 48000)
               mp3->sample_rate = 0x1;
            else if (samplerate == 44100)
               mp3->sample_rate = 0x2;
            else if (samplerate == 32000)
               mp3->sample_rate = 0x4;
            else if (samplerate == 24000)
               mp3->sample_rate = 0x8;
            else if (samplerate == 22050)
               mp3->sample_rate = 0x10;
            else if (samplerate == 16000)
               mp3->sample_rate = 0x20;
            else
               return KAL_FALSE;
            mp3->VBR = KAL_TRUE;
            mp3->bit_rate = 0x4000;

            result = srv_a2dp_check_handset_mp3_config(mp3);

        }
        else if (codec_type == BT_A2DP_AAC && aud_fmt == MDI_FORMAT_AAC)
        {                       /* AAC streaming */
            /* bt_a2dp_aac_codec_cap_struct *aac = &aud_cfg->codec_cap.aac; */
            return KAL_FALSE;   /* not support now */
        }
        else
        {   /* not supported streaming codec */
            return KAL_FALSE;
        }

    #else
        return KAL_FALSE;
    #endif /*__LOW_COST_SUPPORT_COMMON__*/

    }

    if(result)
    {
        aud_cfg->codec_type = codec_type;
    }

    return result;

}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_aud_cfg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename    [IN]
 *  aud_cfg     [IN]
 *  sbc_only    [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 srv_a2dp_get_aud_cfg(kal_wchar* filename, bt_a2dp_audio_cap_struct *aud_cfg,
    kal_bool sbc_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 format, i, count;
    kal_uint8 codec_type[2] = {BT_A2DP_SBC, 0};
    kal_uint8* pFSALBuf;
    STFSAL file;
    audInfoStruct *aud_info;
#ifdef KUR_DECODE
    Media_KURO_Param extFormat;
    KURO_HEAD_INFO *kur_header_info;
    KURO_FUN_CODE kur_result;
#endif /*KUR_DECODE*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    aud_cfg[0].codec_type = 0;
    aud_cfg[1].codec_type = 0;
    //aud_info.bitRate = 0;

    format = med_get_media_type(filename);

    // open file
    if (FSAL_Open(&file, filename, FSAL_READ_SHARED) != FSAL_OK)
		return -1;

    // set FSAL buffer
    pFSALBuf = (kal_uint8*) get_ctrl_buffer(1024);
    FSAL_SetBuffer(&file, 1024, pFSALBuf);

    aud_info = (audInfoStruct*) get_ctrl_buffer(sizeof(audInfoStruct));
    aud_info->bitRate = 0;

    switch (format)
    {
#ifdef AMR_DECODE
        case MDI_FORMAT_AMR:
    #ifdef AMRWB_DECODE
        case MDI_FORMAT_AMR_WB:
    #endif 
            AMR_GetContentDescInfo(&file, aud_info, NULL);
            break;
#endif /* AMR_DECODE */ 
#ifdef __VM_CODEC_SUPPORT__
        case MDI_FORMAT_GSM_FR:
        case MDI_FORMAT_GSM_HR:
        case MDI_FORMAT_GSM_EFR:
#ifdef __MED_VR_MOD__
        case MDI_FORMAT_VR:
#endif 
            VM_GetContentDescInfo(&file, aud_info, &format);
            break;
#endif /*__VM_CODEC_SUPPORT__*/
#ifdef WAV_CODEC
        case MDI_FORMAT_PCM_16K:
        case MDI_FORMAT_PCM_8K:
        case MDI_FORMAT_DVI_ADPCM:
            PCM_GetContentDescInfo(&file, aud_info, (void*)format);
            break;
#endif /*WAV_CODEC*/
#ifdef DAF_DECODE
        case MDI_FORMAT_DAF:
#ifdef MUSICAM_DECODE        
        case MDI_FORMAT_MUSICAM:
#endif
            DAF_GetContentDescInfo(&file, aud_info, NULL);

        /* to prevent from performance issue, we do not support MP3 streaming now, 
           it is reference only now.*/
        #if defined(__MMI_A2DP_SUPPORT_DAF_STREAMING__) && !defined(__LOW_COST_SUPPORT_COMMON__)
            if (!sbc_only && aud_info->details.DAF.mediaFormat == MEDIA_FORMAT_DAF)
            {
                codec_type[0] = BT_A2DP_MP3;
                codec_type[1] = BT_A2DP_SBC;
            }
        #endif
            break;
#endif /* DAF_DECODE */ 
#ifdef WAV_CODEC
        case MDI_FORMAT_WAV:
        case MDI_FORMAT_WAV_ALAW:
        case MDI_FORMAT_WAV_ULAW:
        case MDI_FORMAT_WAV_DVI_ADPCM:
            WAV_GetContentDescInfo(&file, aud_info, NULL);
            break;
#endif /*WAV_CODEC*/
#ifdef AU_DECODE
        case MDI_FORMAT_AU:
            AU_GetContentDescInfo(&file, aud_info, NULL);
            break;
#endif /* AU_DECODE */
#ifdef AIFF_DECODE
        case MDI_FORMAT_AIFF:
            AIFF_GetContentDescInfo(&file, aud_info, NULL);
            break;
#endif /* AIFF_DECODE */
#ifdef WMA_DECODE
        case MDI_FORMAT_WMA:
            WMA_GetContentDescInfo(&file, aud_info, NULL);
            break;
#endif /* WMA_DECODE */ 
#ifdef AAC_DECODE
        case MDI_FORMAT_AAC:
#ifdef BSAC_DECODE
/* under construction !*/
#endif /* BSAC_DECODE */
            AAC_GetContentDescInfo(&file, aud_info, NULL);
            break;
#endif /* AAC_DECODE */ 
#ifdef M4A_DECODE
        case MDI_FORMAT_M4A:
            MP4S_GetContentDescInfo(&file, aud_info, NULL);
            break;
#endif /* M4A_DECODE */

#if defined(PURE_AUDIO_SUPPORT) //|| defined(MP4_DECODE)
        case MDI_FORMAT_3GP:
        case MDI_FORMAT_MP4:
            MP4S_GetContentDescInfo(&file, aud_info, NULL);
            break;
#endif /* defined(__MMI_PURE_AUDIO__) */ 

#ifdef __FLV_FILE_FORMAT_SUPPORT__
        case MDI_FORMAT_F4A:
        case MDI_FORMAT_F4V:
        case MDI_FORMAT_FLV:
            FLV_GetContentDescInfo(&file, aud_info, NULL);
            break;
#endif /*__FLV_FILE_FORMAT_SUPPORT__*/

    #ifdef KUR_DECODE
        case MDI_FORMAT_KURO:
            /* Get kuro header info for decrypt */
            kur_header_info = (void*)get_ctrl_buffer(sizeof(KURO_HEAD_INFO));
            kur_result = KURO_GetKuroHeadInfo(file.hFile, kur_header_info);

            if(kur_result != KURO_OK)
            {
                free_ctrl_buffer(kur_header_info);
                break;
            }

            extFormat.paramType.type = MEDIA_EXT_PARAM_KURO_CONTENT;
            extFormat.pInfo = (void*)kur_header_info;

            if(KURO_adp_get_media_type(kur_header_info) == MED_TYPE_KURO_AAC)
            {
                AAC_GetContentDescInfo(&file, aud_info, &extFormat);
            }
            else
            {
                DAF_GetContentDescInfo(&file, aud_info, &extFormat);
            }

            free_ctrl_buffer(kur_header_info);
            break;
    #endif /* KUR_DECODE */
    #ifdef __RM_DEC_SUPPORT__
        case MDI_FORMAT_RMVB:
        case MDI_FORMAT_RM:
        case MDI_FORMAT_RA:
        case MDI_FORMAT_RV:
            RM_GetContentDescInfo(&file, aud_info, NULL);
            break;
    #endif /*__RM_DEC_SUPPORT__*/
    #ifdef __APE_DECODE__
        case MDI_FORMAT_APE:
        	  APE_GetContentDescInfo(&file, aud_info, NULL);
        	break;
    #endif
    #ifdef __VORBIS_DECODE__
        case MDI_FORMAT_VORBIS:
            VORBIS_GetContentDescInfo(&file, aud_info, NULL);
            break;
    #endif

    #ifdef __FLAC_DECODE__
        case MDI_FORMAT_FLAC:
            FLAC_GetContentDescInfo(&file, aud_info, NULL);
            break;
    #endif
        default:
            aud_info->sampleRate = 32000;
            aud_info->stereo = KAL_TRUE;
            break;
    }

    FSAL_Close(&file);
    free_ctrl_buffer(pFSALBuf);

    for( count = i = 0; i < 2 && codec_type[i]; i++ )
    {
        if (srv_a2dp_aud_info_to_cfg(aud_info, &aud_cfg[count], format, codec_type[i]))
        {
            if( aud_cfg[count].codec_type == BT_A2DP_SBC )
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_GET_AUDIO_CFG_SBC,\
                    aud_cfg[count].codec_cap.sbc.min_bit_pool, \
                    aud_cfg[count].codec_cap.sbc.max_bit_pool, \
                    aud_cfg[count].codec_cap.sbc.sample_rate, \
                    aud_cfg[count].codec_cap.sbc.channel_mode);
            }
    #ifndef __LOW_COST_SUPPORT_COMMON__
            else if (aud_cfg[count].codec_type == BT_A2DP_MP3)
            {

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_GET_AUDIO_CFG_MP3,\
                    aud_cfg[count].codec_cap.mp3.bit_rate, \
                    aud_cfg[count].codec_cap.mp3.layer, \
                    aud_cfg[count].codec_cap.mp3.sample_rate, \
                    aud_cfg[count].codec_cap.mp3.channel_mode, \
                    aud_cfg[count].codec_cap.mp3.VBR, \
                    aud_cfg[count].codec_cap.mp3.MPF);
            }
            /* enforce a bitrate limit to 320K, otherwise, use SBC encode */
            if (codec_type[i] == BT_A2DP_MP3 && aud_info->bitRate >= 320000)
            {
                continue;
            }
    #endif
            count++;
        }
        else
        {
            continue;
        }
    }

    free_ctrl_buffer(aud_info);

    return (count > 0) ? 0: -1;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_aud_cfg_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sample_rate [IN]
 *  stereo      [IN]
 *  aud_cfg     [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 srv_a2dp_get_aud_cfg_ex(kal_uint16 sample_rate, kal_bool stereo, bt_a2dp_audio_cap_struct *aud_cfg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audInfoStruct *aud_info;
    aud_info = (audInfoStruct*) get_ctrl_buffer(sizeof(audInfoStruct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_GET_AUDIO_CFG_EX_1,sample_rate,stereo);

    aud_cfg[0].codec_type = 0;
    aud_cfg[1].codec_type = 0;

    aud_info->sampleRate = (kal_uint32)sample_rate;
    aud_info->stereo = stereo;

    if (!srv_a2dp_aud_info_to_cfg(aud_info, &aud_cfg[0], 0, BT_A2DP_SBC))
    {
        free_ctrl_buffer(aud_info);
        return -1;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_GET_AUDIO_CFG_EX_2, \
        aud_cfg[0].codec_cap.sbc.min_bit_pool, \
        aud_cfg[0].codec_cap.sbc.max_bit_pool, \
        aud_cfg[0].codec_cap.sbc.sample_rate, \
        aud_cfg[0].codec_cap.sbc.channel_mode);

    free_ctrl_buffer(aud_info);
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_match_aud_cfg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  dev         [IN]
 *  cfg         [IN]
 *  sep_index   [IN]
 *  cap_index   [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_bool srv_a2dp_match_aud_cfg(av_bt_dev_struct *dev, bt_a2dp_audio_cap_struct *cfg,
    kal_uint8 *sep_index, kal_uint8 *cap_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    int i, j;
    kal_uint16 result;
    av_bt_sep_struct *sep;
    bt_a2dp_audio_cap_struct *cap;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    for (i = 0; i < dev->sep_count; i++)
    {
        sep = &dev->sep_list[i];

        for (j = 0; j < sep->cap_count; j++)
        {
            cap = &sep->cap_list[j];

            if (bt_a2dp_match_audio_capabilities(cap, cfg, &result))
            {
                *sep_index = (kal_uint8)i;
                *cap_index = (kal_uint8)j;
                if( cfg->codec_type == BT_A2DP_SBC )
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_MATCH_AUDIO_CFG_SBC,
                        cfg->codec_cap.sbc.min_bit_pool,
                        cfg->codec_cap.sbc.max_bit_pool,
                        cfg->codec_cap.sbc.sample_rate,
                        cfg->codec_cap.sbc.channel_mode);
                        
                }
            #ifndef __LOW_COST_SUPPORT_COMMON__
                else if (cfg->codec_type == BT_A2DP_MP3)
                {
                    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_MATCH_AUDIO_CFG_MP3,
                        cfg->codec_cap.mp3.bit_rate,
                        cfg->codec_cap.mp3.layer,
                        cfg->codec_cap.mp3.sample_rate,
                        cfg->codec_cap.mp3.channel_mode,
                        cfg->codec_cap.mp3.VBR,
                        cfg->codec_cap.mp3.MPF);
                        
                }
            #endif
                return KAL_TRUE;
            }
        }
    }

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_cmp_aud_cfg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  aud_cfg1    [IN]
 *  aud_cfg2    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_a2dp_cmp_aud_cfg(bt_a2dp_audio_cap_struct *aud_cfg1, bt_a2dp_audio_cap_struct *aud_cfg2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    bt_a2dp_sbc_codec_cap_struct *sbc_cfg1, *sbc_cfg2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_cfg1->codec_type == aud_cfg2->codec_type)
    {
        switch (aud_cfg1->codec_type)
        {
            case BT_A2DP_SBC:
                sbc_cfg1 = &aud_cfg1->codec_cap.sbc;
                sbc_cfg2 = &aud_cfg2->codec_cap.sbc;
                result = (kal_bool)(sbc_cfg1->block_len == sbc_cfg2->block_len &&
                    sbc_cfg1->subband_num == sbc_cfg2->subband_num &&
                    sbc_cfg1->alloc_method == sbc_cfg2->alloc_method &&
                    sbc_cfg1->sample_rate == sbc_cfg2->sample_rate &&
                    sbc_cfg1->channel_mode == sbc_cfg2->channel_mode);
                break;
        #ifndef __LOW_COST_SUPPORT_COMMON__
            case BT_A2DP_MP3:
                result = (kal_bool)(memcmp(
                            (const void*)&aud_cfg1->codec_cap.mp3,
                            (const void*)&aud_cfg2->codec_cap.mp3,
                            sizeof(bt_a2dp_mp3_codec_cap_struct)) == 0);
                break;
            case BT_A2DP_AAC:
                result = (kal_bool)(memcmp(
                            (const void*)&aud_cfg1->codec_cap.aac,
                            (const void*)&aud_cfg2->codec_cap.aac,
                            sizeof(bt_a2dp_aac_codec_cap_struct)) == 0);
                break;
            case BT_A2DP_ATRAC:
                result = (kal_bool)(memcmp(
                            (const void*)&aud_cfg1->codec_cap.atrac,
                            (const void*)&aud_cfg2->codec_cap.atrac,
                            sizeof(bt_a2dp_atrac_codec_cap_struct)) == 0);
                break;
        #endif /*__LOW_COST_SUPPORT_COMMON__*/

            default:
                ASSERT(0);
        }
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_cmp_req_cfg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cfg    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_a2dp_cmp_req_cfg(bt_a2dp_audio_cap_struct *cfg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    for (i = 0; i < 2 && av_bt_ctx.req_cfg[i].codec_type; i++)
    {
        if (srv_a2dp_cmp_aud_cfg(&av_bt_ctx.req_cfg[i], cfg))
            return KAL_TRUE;
    }

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_cmp_bt_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_addr1    [IN]
 *  bt_addr2    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_a2dp_cmp_bt_addr(srv_bt_cm_bt_addr *bt_addr1, srv_bt_cm_bt_addr *bt_addr2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    if( (bt_addr1->lap & 0x00FFFFFF) == (bt_addr2->lap & 0x00FFFFFF) &&
        bt_addr1->uap == bt_addr2->uap && bt_addr1->nap == bt_addr2->nap)
    {
        result = KAL_TRUE;
    }
    else
    {
        result = KAL_FALSE;
    }

    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_interrupt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  cause    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_open_interrupt_hdlr(mdi_result cause, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_INTERRUPT_HDLR);

    av_bt_ctx.need_stop = KAL_TRUE;
    av_bt_ctx.need_reconnect = KAL_FALSE;
    av_bt_ctx.connect_post_proc = KAL_FALSE;
    srv_a2dp_start_disc_timer();
    // stop timer
    StopTimer(AV_BT_START_TIMER);

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    if(av_bt_ctx.wait == AV_BT_WAIT_HFP_CONNECT_CNF || av_bt_ctx.wait == AV_BT_WAIT_SCO_CONNECT_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
    }
#endif

    srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_OPEN_CANCELED);
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_mp3_codec_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_a2dp_is_mp3_codec_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __LOW_COST_SUPPORT_COMMON__
    return (av_bt_ctx.is_codec_open && av_bt_ctx.cfg.codec_type == BT_A2DP_MP3)?KAL_TRUE:KAL_FALSE;
#else
    return KAL_FALSE;
#endif

}
/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_bt_inquirying
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_bt_inquirying(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)av_bt_ctx.is_inquiry;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_codec_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_codec_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (MMI_BOOL)av_bt_ctx.is_codec_open ;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_streaming
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_streaming(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return ( (av_bt_ctx.state == AV_BT_STATE_STREAMING) ? KAL_TRUE : KAL_FALSE );
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_mp3_configured
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_mp3_configured(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

#ifndef __LOW_COST_SUPPORT_COMMON__

    kal_uint8 codec_type = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (!av_bt_ctx.need_stop)
    {
        if (av_bt_ctx.state < AV_BT_STATE_CONFIGURED)
        {
            if (av_bt_ctx.wait == AV_BT_WAIT_CONFIG_CNF)
                codec_type = av_bt_ctx.tmp_cfg.codec_type;
            else
                codec_type = av_bt_ctx.req_cfg[0].codec_type;
        }
        else
        {
            codec_type = av_bt_ctx.cfg.codec_type;
        }
    }

    return ( (codec_type == BT_A2DP_MP3)?KAL_TRUE:KAL_FALSE );
#else
    return MMI_FALSE;
#endif

}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  A2DP_SRV_CALLBACK
 *****************************************************************************/
A2DP_SRV_CALLBACK srv_a2dp_get_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return av_bt_ctx.callback;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_internal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_dev              [IN]
 *  filename            [IN]
 *  sample_rate         [IN]
 *  stereo              [IN]
 *  callback            [IN]
 *  sbc_only            [IN]
 *  immediate_callback  [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 srv_a2dp_open_internal(srv_bt_cm_bt_addr *bt_dev, kal_wchar* filename, 
    kal_uint16 sample_rate, kal_uint8 stereo, A2DP_SRV_CALLBACK callback, 
    kal_bool sbc_only, kal_bool immediate_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool close_dev = KAL_FALSE;
    kal_bool dev_changed;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    StopTimer(AV_BT_START_TIMER);

    av_bt_ctx.callback = callback;
    av_bt_ctx.retry_success_callback = callback;
    mdi_audio_set_pseudo_play_file_callback(srv_a2dp_open_interrupt_hdlr, NULL);
    av_bt_ctx.need_reconfig = KAL_FALSE;

    /* compare the prev bt addr with requested bt addr */
    if (av_bt_ctx.state == AV_BT_STATE_IDLE)
    {
        if (av_bt_ctx.wait == AV_BT_WAIT_CONNECT_CNF)
        {
            /* check if connecting bt addr different */
            dev_changed = ( (KAL_TRUE == srv_a2dp_cmp_bt_addr(&av_bt_ctx.bt_addr, bt_dev) )?KAL_FALSE:KAL_TRUE );
            if (dev_changed)
            {
                close_dev = KAL_TRUE;
            }
        }
        else
        {
            /* check if connected bt addr different */
            dev_changed = ( (KAL_TRUE == srv_a2dp_cmp_bt_addr(&av_bt_ctx.bt_addr, bt_dev) )?KAL_FALSE:KAL_TRUE );
        }
    }
    else
    {
        /* check if connected bt addr different */
        dev_changed = ( (KAL_TRUE == srv_a2dp_cmp_bt_addr(&av_bt_ctx.bt_addr, bt_dev) )?KAL_FALSE:KAL_TRUE );
        if (dev_changed)
        {
            close_dev = KAL_TRUE;
        }
    }

    if (close_dev)
    {
        /* close dev */
        close_dev = srv_a2dp_close_dev();
    }

    if (dev_changed)
    {
        /* reset dev */
        memset(&av_bt_ctx.dev, 0, sizeof(av_bt_dev_struct));
    }
    memcpy(&av_bt_ctx.dev.bt_addr, bt_dev, sizeof(srv_bt_cm_bt_addr));

        if (filename != NULL)
        {
            if (srv_a2dp_get_aud_cfg(filename, &av_bt_ctx.req_cfg[0], sbc_only) < 0)
            {
                av_bt_ctx.need_stop = KAL_TRUE;
                srv_a2dp_close(immediate_callback);
                return SRV_A2DP_OPEN_FAILED;
            }
        }
        else
        {
            if (srv_a2dp_get_aud_cfg_ex(sample_rate, (kal_bool)stereo, &av_bt_ctx.req_cfg[0]) < 0)
            {
                av_bt_ctx.need_stop = KAL_TRUE;
                srv_a2dp_close(immediate_callback);
                return SRV_A2DP_OPEN_FAILED;
            }
        }

        if (av_bt_ctx.state == AV_BT_STATE_CONNECTED && av_bt_ctx.wait == AV_BT_WAIT_CONFIG_CNF)
        {
            if (!srv_a2dp_cmp_req_cfg(&av_bt_ctx.tmp_cfg))
                av_bt_ctx.need_reconfig = KAL_TRUE;
        }

        /* handle IOT issues */

        if(av_bt_ctx.connect_post_proc && av_bt_ctx.wait == AV_BT_WAIT_CONNECT_CNF)
        {
            av_bt_ctx.need_reconnect = KAL_TRUE;  
        }
        else
        {
            av_bt_ctx.need_reconnect = close_dev;
        }

        av_bt_ctx.need_stop = KAL_FALSE;
        av_bt_ctx.bad_acp_seid_retry = KAL_FALSE;
        av_bt_ctx.bad_state_retry = KAL_FALSE;
        av_bt_ctx.sep_ind_use_retry = KAL_FALSE;
        srv_a2dp_stop_disc_timer();
        if (srv_a2dp_open_dev(immediate_callback))
            return SRV_A2DP_OPEN_DONE;

    return SRV_A2DP_OPEN_WAITING;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_dev              [IN]
 *  sample_rate         [IN]
 *  stereo              [IN]
 *  callback            [IN]
 *  immediate_callback  [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
S32 srv_a2dp_open(srv_bt_cm_bt_addr *bt_dev, U16 sample_rate, 
    U8 stereo, A2DP_SRV_CALLBACK callback, MMI_BOOL immediate_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_OPEN_EX,av_bt_ctx.state, av_bt_ctx.wait, immediate_callback);

    return srv_a2dp_open_internal(bt_dev, NULL, sample_rate, stereo, callback, KAL_TRUE, immediate_callback);
}

/*****************************************************************************
 * FUNCTION
 *  av_bt_open_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_dev              [IN]
 *  filename            [IN]
 *  callback            [IN]
 *  sbc_only            [IN]
 *  immediate_callback  [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
S32 srv_a2dp_open_ex(srv_bt_cm_bt_addr *bt_dev, WCHAR* filename, 
    A2DP_SRV_CALLBACK callback, MMI_BOOL sbc_only, MMI_BOOL immediate_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_OPEN,av_bt_ctx.state, av_bt_ctx.wait, sbc_only, immediate_callback);

#ifdef __PLUTO_MMI_PACKAGE__
    return srv_a2dp_open_internal(bt_dev, filename, 0, 0, callback, sbc_only, immediate_callback);
#else    
    if(immediate_callback && callback != NULL)
    {
        callback(SRV_A2DP_CALLBACK_EVENT_OPEN_STOPPED);
    }
    return SRV_A2DP_OPEN_FAILED;
#endif



}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close
 * DESCRIPTION
 *  
 * PARAMETERS
 *  notify_opener   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_close(MMI_BOOL notify_opener)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    void(*callback)(S32 res) = av_bt_ctx.callback;
    kal_bool need_stop = av_bt_ctx.need_stop;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CLOSE,notify_opener);

    av_bt_ctx.need_reconfig = KAL_FALSE;
    av_bt_ctx.need_reconnect = KAL_FALSE;
    av_bt_ctx.need_stop = KAL_TRUE;
    av_bt_ctx.callback = NULL;
    av_bt_ctx.retry_success_callback = NULL;
    mdi_audio_set_pseudo_play_file_callback(NULL, NULL);
    srv_a2dp_start_disc_timer();

    // stop timer
    StopTimer(AV_BT_START_TIMER);

    if (av_bt_ctx.state >= AV_BT_STATE_STREAMING && av_bt_ctx.wait == AV_BT_WAIT_NONE_CNF)
    {
    /* PTS can not handle us to pause streaing right after they send start streaming ind*/
    #ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
        if(srv_avrcp_get_actively_connect_tg_flag())
        {
            StartTimer(AV_BT_DELAY_PAUSE_TIMER, 1000, srv_a2dp_delay_pause_stream_time_out);
        }
        else
    #endif
            srv_a2dp_pause_stream();
    }

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    if(av_bt_ctx.wait == AV_BT_WAIT_HFP_CONNECT_CNF || av_bt_ctx.wait == AV_BT_WAIT_SCO_CONNECT_CNF || av_bt_ctx.wait == AV_BT_WAIT_SCO_DISCONNECT_CALLBACK)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
    }
#endif

    if (notify_opener && callback)
    {
        if (need_stop || av_bt_ctx.state != AV_BT_STATE_STREAMING || av_bt_ctx.wait == AV_BT_WAIT_PAUSE_CNF)
        {
            callback(SRV_A2DP_CALLBACK_EVENT_OPEN_STOPPED);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_pause
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_pause(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_PAUSE);

    av_bt_ctx.need_stop = KAL_TRUE;
    // stop timer
    StopTimer(AV_BT_START_TIMER);

    if (av_bt_ctx.state >= AV_BT_STATE_STREAMING && av_bt_ctx.wait == AV_BT_WAIT_NONE_CNF)
    {
        srv_a2dp_pause_stream();
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_codec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  immediate      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_open_codec(MMI_BOOL immediate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_OPEN_CODEC,av_bt_ctx.is_codec_open, av_bt_ctx.codec_seq_no);

    if (av_bt_ctx.state == AV_BT_STATE_STREAMING)
    {
        if (!av_bt_ctx.is_codec_open)
        {
            aud_send_bt_open_codec_req(MOD_MMI, &av_bt_ctx.cfg,
                av_bt_ctx.stream_handle, immediate, av_bt_ctx.codec_seq_no);
            av_bt_ctx.is_codec_open = KAL_TRUE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close_codec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_close_codec(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CLOSE_CODEC,av_bt_ctx.is_codec_open, av_bt_ctx.codec_seq_no);

    if (av_bt_ctx.is_codec_open)
    {
        aud_send_bt_close_codec_req(MOD_MMI);
        av_bt_ctx.codec_seq_no++;
        av_bt_ctx.is_codec_open = KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close_codec_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_close_codec_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    media_bt_close_codec_ind_struct *msg_p = (media_bt_close_codec_ind_struct*)msg;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CLOSE_CODEC_IND,av_bt_ctx.is_codec_open, av_bt_ctx.codec_seq_no);

    if (av_bt_ctx.is_codec_open && av_bt_ctx.codec_seq_no == msg_p->seq_no)
    {
        av_bt_ctx.is_codec_open = KAL_FALSE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_dev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  kal_bool
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_a2dp_open_dev(kal_bool done_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    kal_bool need_reconfig;
    kal_bool done = KAL_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_OPEN_DEV,done_callback,av_bt_ctx.need_reconnect, av_bt_ctx.wait);

    if (av_bt_ctx.need_reconnect)
    {
        return done;
    }

    switch (av_bt_ctx.state)
    {
    case AV_BT_STATE_IDLE:
        if (av_bt_ctx.wait == AV_BT_WAIT_NONE_CNF)
        {
            srv_a2dp_connect();
        }
        break;
    case AV_BT_STATE_CONNECTED:
        if (av_bt_ctx.wait == AV_BT_WAIT_NONE_CNF)
        {
            if (!srv_a2dp_discover_stream())
            {
                if (!srv_a2dp_get_stream_cap())
                {
                    srv_a2dp_config_stream();
                }
            }
        }
        break;
    case AV_BT_STATE_CONFIGURED:
        need_reconfig = (kal_bool)(!srv_a2dp_cmp_req_cfg(&av_bt_ctx.cfg));
        if (av_bt_ctx.wait == AV_BT_WAIT_NONE_CNF)
        {
            if (need_reconfig)
            {
                srv_a2dp_abort_stream();
            }
            else
            {
                srv_a2dp_open_stream();
            }
        }
        else
            av_bt_ctx.need_reconfig = need_reconfig;
        break;
    case AV_BT_STATE_OPEN:
        need_reconfig = (kal_bool)(!srv_a2dp_cmp_req_cfg(&av_bt_ctx.cfg));
        if (av_bt_ctx.wait == AV_BT_WAIT_NONE_CNF)
        {
            if (need_reconfig)
            {
                srv_a2dp_close_stream();
            }
            else
            {
                srv_a2dp_start_stream();
            }
        }
        else
            av_bt_ctx.need_reconfig = need_reconfig;
        break;
    case AV_BT_STATE_STREAMING:
        need_reconfig = (kal_bool)(!srv_a2dp_cmp_req_cfg(&av_bt_ctx.cfg));
        if (av_bt_ctx.wait == AV_BT_WAIT_NONE_CNF)
        {
            if (need_reconfig)
            {
                srv_a2dp_close_stream();
            }
            else
            {
                done = KAL_TRUE;

            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                /* Disconnect SCO if connect to A2DP */
                srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_A2DP);
            #endif

                if (done_callback)
                {
                    srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_OPEN_OK);
                }
            }
        }
        else
            av_bt_ctx.need_reconfig = need_reconfig;
        break;
    }

    return done;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close_dev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_a2dp_close_dev()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool wait_connect = (kal_bool)(av_bt_ctx.wait == AV_BT_WAIT_CONNECT_CNF);
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CLOSE_DEV);

    av_bt_ctx.connect_post_proc = KAL_FALSE;

    if (av_bt_ctx.wait != AV_BT_WAIT_DISCONNECT_CNF && 
        (av_bt_ctx.state != AV_BT_STATE_IDLE || wait_connect))
    {
        if (wait_connect)
        {
            av_bt_ctx.connect_post_proc = KAL_TRUE;
        }
        else
        {
            srv_a2dp_disconnect();
        }
        /* init cfg */
        memset(&av_bt_ctx.cfg, 0, sizeof(bt_a2dp_audio_cap_struct));
        memset(&av_bt_ctx.req_cfg[0], 0, 2*sizeof(bt_a2dp_audio_cap_struct));
        av_bt_ctx.req_cfg_index = 0;

        return KAL_TRUE;
    }

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_start_disc_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_start_disc_timer(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_START_DISC_TIMER);

#ifdef __MMI_BT_AUDIO_VIA_SCO__
        srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
#endif
    if(av_bt_ctx.disconnect_delay != 0)
    {
        StartTimer(AV_BT_DISC_TIMER, av_bt_ctx.disconnect_delay, (FuncPtr)srv_a2dp_close_dev);
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_stop_disc_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_stop_disc_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_STOP_DISC_TIMER);
    StopTimer(AV_BT_DISC_TIMER);
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_check_and_restart_disc_timer
 * DESCRIPTION
 *  check if disc timer exist and restart a new one
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_check_and_restart_disc_timer(void)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_RESTART_DISC_TIMER);

    if(IsMyTimerExist(AV_BT_DISC_TIMER))
    {
        StartTimer(AV_BT_DISC_TIMER, av_bt_ctx.disconnect_delay, (FuncPtr)srv_a2dp_close_dev);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_connect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_connect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CONNECT);

    ASSERT(av_bt_ctx.state == AV_BT_STATE_IDLE);

    srv_bt_a2dp_connect_req(*((srv_bt_cm_bt_addr*)&av_bt_ctx.dev.bt_addr));
    av_bt_ctx.wait = AV_BT_WAIT_CONNECT_CNF;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_disconnect
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_disconnect(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_DISCONNECT);

    ASSERT(av_bt_ctx.state >= AV_BT_STATE_CONNECTED);
 
    StopTimer(AV_BT_START_TIMER);

    srv_bt_a2dp_disconnect_req(*((srv_bt_cm_bt_addr*)&av_bt_ctx.bt_addr), av_bt_ctx.connect_id);
    av_bt_ctx.wait = AV_BT_WAIT_DISCONNECT_CNF;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_discover_stream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_a2dp_discover_stream(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_DISCOVER_STREAM);

    ASSERT(av_bt_ctx.state == AV_BT_STATE_CONNECTED);

    if (av_bt_ctx.dev.sep_count == 0)
    {
        bt_a2dp_send_sep_discover_req(MOD_MMI, av_bt_ctx.connect_id);
        av_bt_ctx.wait = AV_BT_WAIT_DISCOVER_CNF;
        return KAL_TRUE;
    }

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_stream_cap
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_a2dp_get_stream_cap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;
    av_bt_sep_struct *sep;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_GET_STREAM_CAP);

    ASSERT(av_bt_ctx.state == AV_BT_STATE_CONNECTED);

    for( i = 0; i < av_bt_ctx.dev.sep_count; i++ )
    {
        sep = &av_bt_ctx.dev.sep_list[i];

        if( sep->cap_count == 0 )
        {
            bt_a2dp_send_capabilities_get_req(MOD_MMI, av_bt_ctx.connect_id, 
                sep->info.seid);
            av_bt_ctx.dev.sep_index = i;
            av_bt_ctx.wait = AV_BT_WAIT_GET_CAP_CNF;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_config_stream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_config_stream(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    kal_bool match_cfg = KAL_FALSE;
    kal_uint8 sep_index, cap_index, i;
    av_bt_dev_struct *dev = &av_bt_ctx.dev;
    av_bt_sep_struct *sep;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CONFIG_STREAM);

    ASSERT(av_bt_ctx.state == AV_BT_STATE_CONNECTED);

    for (i = 0; i < 2 && av_bt_ctx.req_cfg[i].codec_type; i++)
    {
        match_cfg = srv_a2dp_match_aud_cfg(dev, &av_bt_ctx.req_cfg[i], &sep_index, &cap_index);
        if (match_cfg)
        {
            av_bt_ctx.req_cfg_index = i;
            break;
        }
    }

    if (match_cfg)
    {
        sep = &dev->sep_list[sep_index];
        sep->cap_index = cap_index;
        dev->sep_index = sep_index;
        memcpy(&av_bt_ctx.tmp_cfg, &av_bt_ctx.req_cfg[av_bt_ctx.req_cfg_index],
            sizeof(bt_a2dp_audio_cap_struct));

        /*the flag shall not be on before configuration*/
        if(av_bt_ctx.need_reconfig)
        {
            av_bt_ctx.need_reconfig = KAL_FALSE ;
        }

        bt_a2dp_send_stream_config_req(MOD_MMI,
            av_bt_ctx.connect_id, 
            sep->info.seid, 
            av_bt_ctx.local_seid,
            &av_bt_ctx.tmp_cfg);
        av_bt_ctx.wait = AV_BT_WAIT_CONFIG_CNF;
    }
    else
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CONFIG_STREAM_NOT_MATCH);

    #ifdef __MMI_BT_AUDIO_VIA_SCO__                    
        /* disable to make sure sco will not be activated*/
        srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
    #endif
        srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_stream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_open_stream(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_OPEN_STREAM);

    ASSERT(av_bt_ctx.state == AV_BT_STATE_CONFIGURED);

    bt_a2dp_send_stream_open_req(MOD_MMI, av_bt_ctx.stream_handle);
    av_bt_ctx.wait = AV_BT_WAIT_OPEN_CNF;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_start_stream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_start_stream(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_START_STREAM);

    ASSERT(av_bt_ctx.state == AV_BT_STATE_OPEN);

#ifdef __MMI_BT_AUDIO_VIA_SCO__                    
    /* disable to make sure sco will not be activated*/
    srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_A2DP);
    /* need to wait until sco disconnected ind*/
    if(srv_btsco_is_sco_open())
    {
        mmi_frm_cb_reg_event(EVT_ID_SRV_BTSCO_CLOSE_IND, (mmi_proc_func) srv_a2dp_sco_disconnected_event_hdlr, NULL);
        av_bt_ctx.wait = AV_BT_WAIT_SCO_DISCONNECT_CALLBACK;
    }
    else
#endif
    {
        bt_a2dp_send_stream_start_req(MOD_MMI, av_bt_ctx.stream_handle);
        av_bt_ctx.wait = AV_BT_WAIT_START_CNF;
    }

}

/*****************************************************************************
 * FUNCTION
 *  delay pause time out
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_delay_pause_stream_time_out(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    srv_a2dp_pause_stream();
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_pause_stream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_pause_stream(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_PAUSE_STREAM);

    if(av_bt_ctx.state != AV_BT_STATE_STREAMING)
    {
        return;
    }


    bt_a2dp_send_stream_pause_req(MOD_MMI, av_bt_ctx.stream_handle);
    av_bt_ctx.wait = AV_BT_WAIT_PAUSE_CNF;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close_stream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_close_stream(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CLOSE_STREAM);

    ASSERT(av_bt_ctx.state >= AV_BT_STATE_OPEN);
 
    StopTimer(AV_BT_START_TIMER);

    bt_a2dp_send_stream_close_req(MOD_MMI, av_bt_ctx.stream_handle);
    av_bt_ctx.wait = AV_BT_WAIT_CLOSE_CNF;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_abort_stream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_abort_stream(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_ABORT_STREAM);

    ASSERT(av_bt_ctx.state >= AV_BT_STATE_CONFIGURED);
 
    StopTimer(AV_BT_START_TIMER);

    bt_a2dp_send_stream_abort_req(MOD_MMI, av_bt_ctx.stream_handle);
    av_bt_ctx.wait = AV_BT_WAIT_ABORT_CNF;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close_or_start_stream
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_close_or_start_stream(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void(*callback)(S32 res) = av_bt_ctx.callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(!av_bt_ctx.check_output_callback())
    {
        av_bt_ctx.need_stop = KAL_TRUE;
        srv_a2dp_start_disc_timer();
        return;
    }

#ifdef __PLUTO_MMI_PACKAGE__
    /* let appliction know a stream is started and need to play a audio stuff */
    if (callback)
    {
        callback(SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND);
    }
    else
    {
        /* default callback: currently only support audio player */
        if(av_bt_ctx.default_callbacks[0] != NULL)
        {
            av_bt_ctx.default_callbacks[0](SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND);
        }
    }
#else /*Cosmos*/
    srv_btaud_stereo_notify(NULL);
#endif

    return;
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
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_connect_post_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_connect_post_proc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool is_connected;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	is_connected = (av_bt_ctx.state == AV_BT_STATE_CONNECTED)?KAL_TRUE:KAL_FALSE;
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CONNECT_POST_PROC,av_bt_ctx.connect_post_proc,is_connected,av_bt_ctx.need_reconnect);

    if (av_bt_ctx.connect_post_proc)
    {
        av_bt_ctx.connect_post_proc = KAL_FALSE;
        if (av_bt_ctx.need_reconnect)
        {
            if (is_connected)
            {
                /*check if the connected and reconnect bt addr are the same
                 if they are the same, no need to reconnect it */
                if (srv_a2dp_cmp_bt_addr(&av_bt_ctx.dev.bt_addr, &av_bt_ctx.bt_addr))
                {
                    av_bt_ctx.need_reconnect = KAL_FALSE; 
                    srv_a2dp_open_dev(KAL_TRUE);
                }
                else
                {
                    srv_a2dp_disconnect();
                }
            }
            else
            {
                av_bt_ctx.need_reconnect = KAL_FALSE;
                srv_a2dp_connect();
            }
        }
        else if (is_connected)
        {
            srv_a2dp_disconnect();
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_connect_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_connect_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    bt_a2dp_signal_connect_cnf_struct *msg_p = (bt_a2dp_signal_connect_cnf_struct*)msg;
    kal_bool go_on =( ( KAL_TRUE == (av_bt_ctx.need_stop || av_bt_ctx.need_reconnect || 
        av_bt_ctx.connect_post_proc) )?KAL_FALSE:KAL_TRUE );
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CONNECT_CNF,msg_p->result,av_bt_ctx.wait,go_on);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AV_BT_TRC_GO_ON_DETAILS,av_bt_ctx.need_stop,av_bt_ctx.need_reconnect,av_bt_ctx.connect_post_proc);

    if (msg_p->result == BT_A2DP_RESULT_OK)
    {
        av_bt_ctx.connect_id = msg_p->connect_id;
        memcpy(&av_bt_ctx.bt_addr, &msg_p->device_addr, sizeof(srv_bt_cm_bt_addr));
        av_bt_ctx.state = AV_BT_STATE_CONNECTED;
#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
        {
            srv_bt_cm_bt_addr *addr = (srv_bt_cm_bt_addr*)&(av_bt_ctx.bt_addr);
            if(srv_avrcp_get_actively_connect_tg_flag())
            {
                srv_avrcp_connect_tg_req(*addr);
            }
        }
#endif
    }
    
    if (av_bt_ctx.wait == AV_BT_WAIT_CONNECT_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
        if (msg_p->result == BT_A2DP_RESULT_OK)
        {
            if (go_on)
            {
                srv_a2dp_open_dev(KAL_TRUE);
            }
            else
            {
                srv_a2dp_connect_post_proc();
            }
        }
        else
        {
            /*this means there is a connect ind before our connect req and the bt deivce is not the same*/
            if(av_bt_ctx.state == AV_BT_STATE_CONNECTED)
            {
                av_bt_ctx.need_reconnect = KAL_TRUE;
                srv_a2dp_disconnect();
                return;
            }

            if (go_on)
            {
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                /* Reconnect SCO if A2DP connect fail */
                srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
            #endif

                if(msg_p->result == BT_A2DP_RESULT_SECURITY_BLOCK)
                {
                    srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_SECURITY_BLOCK);
                }
                else
                {
                    srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
                }
            }
            else
            {
                srv_a2dp_connect_post_proc();
            }
        }
    }
#ifndef __PLUTO_MMI_PACKAGE__ /*Cosmos*/
    /* when CM actively connect A2DP, notify application about it*/
    else if(msg_p->result == BT_A2DP_RESULT_OK)
    {
        srv_btaud_stereo_notify(NULL);
    }
#endif

}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_connect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_connect_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_signal_connect_ind_struct *msg_p = (bt_a2dp_signal_connect_ind_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    memcpy(&av_bt_ctx.bt_addr, &msg_p->device_addr, sizeof(srv_bt_cm_bt_addr));
    av_bt_ctx.connect_id = msg_p->connect_id;
    av_bt_ctx.state = AV_BT_STATE_CONNECTED;

    srv_a2dp_connect_post_proc();

    /* if currently we are not output to a2dp, and post_proc hss not disconnect a2dp yet, 
       or cm requst not to accept this connection
       we sahll disconnect a2dp*/
    if( (av_bt_ctx.wait != AV_BT_WAIT_DISCONNECT_CNF && !av_bt_ctx.check_output_callback()) || (g_mmi_a2dp_cntx.cmgr_id <= 0))
    {
        /*make sure it will not connect again*/
        av_bt_ctx.need_stop = KAL_TRUE;
        av_bt_ctx.need_reconnect = KAL_FALSE;
        srv_a2dp_disconnect();
    }

#ifdef __MMI_BT_AUDIO_VIA_SCO__
/*remove this part in case that earphone will not continue to go streaming thus SCO will always be disabled*/
//    if (av_bt_ctx.wait != AV_BT_WAIT_DISCONNECT_CNF)
//    {
		/* Reconnect SCO if A2DP disconnect */        
//    	srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_A2DP);
//    }
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_disconnect_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_disconnect_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    kal_bool need_stop = av_bt_ctx.need_stop;
    kal_bool need_reconnect = av_bt_ctx.need_reconnect;
    void(*callback)(S32 res) = av_bt_ctx.callback;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_DISCONNECT_CNF,av_bt_ctx.wait,need_stop,need_reconnect);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AV_BT_TRC_GO_ON_DETAILS,av_bt_ctx.need_stop,av_bt_ctx.need_reconnect,av_bt_ctx.connect_post_proc);

    av_bt_ctx.state = AV_BT_STATE_IDLE;
    av_bt_ctx.need_reconnect = KAL_FALSE;
    av_bt_ctx.need_stop = KAL_FALSE;
 
    StopTimer(AV_BT_START_TIMER);
    srv_a2dp_stop_disc_timer();

    /* disconnect ind may come right before disconnect cnf */
    if (av_bt_ctx.wait == AV_BT_WAIT_DISCONNECT_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;

        if (!need_stop || need_reconnect)
        {
            /* connect */
            srv_a2dp_connect();
        }
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        else
        {
            /* Reconnect SCO if A2DP disconnect */    
            srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);        
        }
    #endif        
    }
    else
    {
        /* init cfg */
        memset(&av_bt_ctx.cfg, 0, sizeof(bt_a2dp_audio_cap_struct));
        memset(&av_bt_ctx.req_cfg[0], 0, 2*sizeof(bt_a2dp_audio_cap_struct));
        av_bt_ctx.req_cfg_index = 0;

        /* unexpected disconnect cnf */
        if (callback)
        {
            callback(SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND);
        }
        
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        /* Reconnect SCO if A2DP disconnect */
        srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);        
    #endif         
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_disconnect_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_disconnect_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    kal_bool need_stop = av_bt_ctx.need_stop;
    void(*callback)(S32 res) = av_bt_ctx.callback;
    kal_uint8 state = av_bt_ctx.state;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    av_bt_ctx.state = AV_BT_STATE_IDLE;
    av_bt_ctx.need_reconnect = KAL_FALSE;
    av_bt_ctx.need_stop = KAL_FALSE;

    if(av_bt_ctx.wait == AV_BT_WAIT_DISCONNECT_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
    }

    // stop timer
    StopTimer(AV_BT_START_TIMER);
    srv_a2dp_stop_disc_timer();
    if (need_stop || !av_bt_ctx.check_output_callback() || state != AV_BT_STATE_STREAMING)
    {
        /* init cfg */
        memset(&av_bt_ctx.cfg, 0, sizeof(bt_a2dp_audio_cap_struct));
        memset(&av_bt_ctx.req_cfg[0], 0, 2*sizeof(bt_a2dp_audio_cap_struct));
        av_bt_ctx.req_cfg_index = 0;

    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        /* Reconnect SCO if A2DP disconnect */    
        srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
    #endif

       /* let appliction know a stream is started and need to play a audio stuff */
    	if (callback)
    	{
    	    callback(SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND);
    	}
    	else
    	{
    	    /* default callback: currently only support audio player */
    	    if(av_bt_ctx.default_callbacks[0] != NULL)
    	    {
    	        av_bt_ctx.default_callbacks[0](SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND);
    	    }
    	}
	
    }
    else
    {
        /* connect */
        srv_a2dp_connect();
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_discover_stream_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_discover_stream_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_sep_discover_cnf_struct *msg_p = (bt_a2dp_sep_discover_cnf_struct *)msg;
    int i;
    int sep_num = (int)msg_p->sep_num;
    bt_sep_info_struct* sep_list;
	kal_bool go_on = ( ( KAL_TRUE == (av_bt_ctx.need_stop || av_bt_ctx.need_reconnect) )?KAL_FALSE:KAL_TRUE);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_DISCOVER_CNF,msg_p->result,av_bt_ctx.wait,go_on);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AV_BT_TRC_GO_ON_DETAILS,av_bt_ctx.need_stop,av_bt_ctx.need_reconnect,av_bt_ctx.connect_post_proc);

    if (av_bt_ctx.wait == AV_BT_WAIT_DISCOVER_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;

        if (msg_p->result == BT_A2DP_RESULT_OK)
        {
            for (i = 0; i < sep_num; i++)
            {
                sep_list = &msg_p->sep_list[i];
                if (sep_list->sep_type == BT_A2DP_SINK && sep_list->media_type == BT_A2DP_MEDIA_AUDIO)
                {
                    memcpy(&av_bt_ctx.dev.sep_list[i].info, sep_list, sizeof(bt_sep_info_struct));
                    av_bt_ctx.dev.sep_list[i].cap_count = 0;
                }
            }
            av_bt_ctx.dev.sep_count = (kal_uint8)i;

            if (go_on)
            {
                srv_a2dp_open_dev(KAL_TRUE);
            }
        }
        else if (msg_p->result != BT_A2DP_RESULT_NO_CONNECTION)
        {
            if (go_on)
            {
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                /* Reconnect SCO if A2DP connect fail */
                srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
            #endif
                srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_discover_stream_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_discover_stream_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    bt_a2dp_sep_discover_ind_struct *msg_p = (bt_a2dp_sep_discover_ind_struct*)msg;
    bt_sep_info_struct sep_info;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 
    sep_info.in_use = (av_bt_ctx.state > AV_BT_STATE_CONNECTED);
    sep_info.seid = av_bt_ctx.local_seid;
    sep_info.media_type = BT_A2DP_MEDIA_AUDIO;
    sep_info.sep_type = BT_A2DP_SOURCE;

    bt_a2dp_send_sep_discover_res(MOD_MMI, msg_p->connect_id, BT_A2DP_RESULT_OK, 1, &sep_info);
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_stream_cap_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_get_stream_cap_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    bt_a2dp_capabilities_get_cnf_struct *msg_p = (bt_a2dp_capabilities_get_cnf_struct*)msg;
    av_bt_sep_struct *sep = &av_bt_ctx.dev.sep_list[av_bt_ctx.dev.sep_index];
	kal_bool go_on = ( ( KAL_TRUE == (av_bt_ctx.need_stop || av_bt_ctx.need_reconnect) )?KAL_FALSE:KAL_TRUE);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_GET_CAP_CNF,msg_p->result,av_bt_ctx.wait,go_on);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AV_BT_TRC_GO_ON_DETAILS,av_bt_ctx.need_stop,av_bt_ctx.need_reconnect,av_bt_ctx.connect_post_proc);

    if (av_bt_ctx.wait == AV_BT_WAIT_GET_CAP_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;

        if (msg_p->result == BT_A2DP_RESULT_OK && msg_p->audio_cap_num != 0)
        {
            sep->cap_count = msg_p->audio_cap_num;
            memcpy(&sep->cap_list[0], msg_p->audio_cap_list,
                msg_p->audio_cap_num * sizeof(bt_a2dp_audio_cap_struct));

            if (go_on)
            {
                srv_a2dp_open_dev(KAL_TRUE);
            }
        }
        else if (msg_p->result != BT_A2DP_RESULT_NO_CONNECTION)
        {
            if (go_on)
            {
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                /* Reconnect SCO if A2DP connect fail */
                srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
            #endif
                srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_stream_cap_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_get_stream_cap_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_capabilities_get_ind_struct *msg_p = (bt_a2dp_capabilities_get_ind_struct*)msg;
    bt_a2dp_audio_cap_struct local_caps[2];
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* sbc */
    local_caps[0].codec_type = BT_A2DP_SBC;
    memcpy(&(local_caps[0].codec_cap.sbc), &sbc_cap[0], sizeof(bt_a2dp_sbc_codec_cap_struct));

    bt_a2dp_send_capabilities_get_res(MOD_MMI, msg_p->connect_id, BT_A2DP_RESULT_OK, 1, &local_caps[0]);
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_config_stream_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_config_stream_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    bt_a2dp_stream_config_cnf_struct *msg_p = (bt_a2dp_stream_config_cnf_struct*)msg;
    kal_bool need_reconfig = av_bt_ctx.need_reconfig;
	kal_bool go_on = ( ( KAL_TRUE == (av_bt_ctx.need_stop || av_bt_ctx.need_reconnect) )?KAL_FALSE:KAL_TRUE);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CONFIG_STREAM_CNF,msg_p->result,av_bt_ctx.wait,go_on);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AV_BT_TRC_GO_ON_DETAILS,av_bt_ctx.need_stop,av_bt_ctx.need_reconnect,av_bt_ctx.connect_post_proc);

    if (av_bt_ctx.wait == AV_BT_WAIT_CONFIG_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
        av_bt_ctx.need_reconfig = KAL_FALSE;

        if (msg_p->result == BT_A2DP_RESULT_OK)
        {
            av_bt_ctx.stream_handle = msg_p->stream_handle;
            av_bt_ctx.state = AV_BT_STATE_CONFIGURED;
            memcpy(&av_bt_ctx.cfg, &av_bt_ctx.tmp_cfg, sizeof(bt_a2dp_audio_cap_struct));
        }

        if (av_bt_ctx.state == AV_BT_STATE_CONFIGURED)
        {
            if (go_on)
            {
                if (need_reconfig)
                {
                    srv_a2dp_abort_stream();
                }
                else
                {
                    srv_a2dp_open_stream(); 
                }
            }
        }
        else if (msg_p->result != BT_A2DP_RESULT_NO_CONNECTION)
        {
            MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CONFIG_FAIL_RETRY,av_bt_ctx.sep_ind_use_retry,av_bt_ctx.bad_acp_seid_retry,av_bt_ctx.bad_state_retry);
            
            if(msg_p->result == BT_A2DP_RESULT_SEP_IND_USE && !av_bt_ctx.sep_ind_use_retry && av_bt_ctx.state >= AV_BT_STATE_CONNECTED)
            {
                /*disconnect and connect again to see if we could fix headset's bad state situatoin*/
                av_bt_ctx.need_stop = KAL_FALSE;

                av_bt_ctx.need_reconnect = KAL_TRUE;
                av_bt_ctx.sep_ind_use_retry = KAL_TRUE;
                srv_a2dp_disconnect();
                return;
            }
            else if(msg_p->result == BT_A2DP_RESULT_BAD_ACP_SEID && !av_bt_ctx.bad_acp_seid_retry)
            {                 
                /*reset sep information and get all the information and config again*/
                /*config info*/
                memset(&av_bt_ctx.cfg, 0, sizeof(bt_a2dp_audio_cap_struct));
                memset(&av_bt_ctx.tmp_cfg, 0, sizeof(bt_a2dp_audio_cap_struct));
                av_bt_ctx.req_cfg_index = 0;

                /*device info, only the address part is left*/
                av_bt_ctx.dev.sep_count = 0;
                av_bt_ctx.dev.sep_index = 0;
                memset(&av_bt_ctx.dev.sep_list[0],0,MAX_NUM_REMOTE_SEIDS*sizeof(av_bt_sep_struct));

                srv_a2dp_open_dev(KAL_TRUE);
                
                av_bt_ctx.bad_acp_seid_retry = KAL_TRUE ;
                return;
            }
            else if(msg_p->result == BT_A2DP_RESULT_BAD_STATE && !av_bt_ctx.bad_state_retry && av_bt_ctx.state >= AV_BT_STATE_CONNECTED)
            {
                
                /*disconnect and connect again to see if we could fix headset's bad state situatoin*/
                av_bt_ctx.need_stop = KAL_FALSE;

                av_bt_ctx.need_reconnect = KAL_TRUE;
                av_bt_ctx.bad_state_retry = KAL_TRUE;
                srv_a2dp_disconnect();

                return;
            }

            if(av_bt_ctx.sep_ind_use_retry)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_BAD_SEP_IND_USE_RETRY_FALSE);
                av_bt_ctx.sep_ind_use_retry = KAL_FALSE;
            }
            
            if(av_bt_ctx.bad_acp_seid_retry)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_BAD_ACP_SEID_RETRY_FALSE);
                av_bt_ctx.bad_acp_seid_retry = KAL_FALSE ;
            }

            if(av_bt_ctx.bad_state_retry)
            {
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_BAD_STATE_RETRY_FALSE);
                av_bt_ctx.bad_state_retry = KAL_FALSE;
            }
            
            if (go_on)
            {
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                /* Reconnect SCO if A2DP connect fail */
                srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
            #endif
                srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_config_stream_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_config_stream_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    bt_a2dp_stream_config_ind_struct *msg_p = (bt_a2dp_stream_config_ind_struct*)msg;
    kal_uint16 response;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (av_bt_ctx.state == AV_BT_STATE_CONNECTED)
    {
        response = BT_A2DP_RESULT_OK;
        av_bt_ctx.state = AV_BT_STATE_CONFIGURED;
        av_bt_ctx.stream_handle = msg_p->stream_handle;
        memcpy(&av_bt_ctx.cfg, &msg_p->audio_cap, sizeof(bt_a2dp_audio_cap_struct));
    }
    else
    {
        response = BT_A2DP_BAD_STATE;
    }
    bt_a2dp_send_stream_config_res(MOD_MMI, response, msg_p->stream_handle);
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_stream_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_open_stream_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_stream_open_cnf_struct *msg_p = (bt_a2dp_stream_open_cnf_struct*)msg;
    kal_bool need_reconfig = av_bt_ctx.need_reconfig;
	kal_bool go_on = ( ( KAL_TRUE == (av_bt_ctx.need_stop || av_bt_ctx.need_reconnect) )?KAL_FALSE:KAL_TRUE);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_OPEN_STREAM_CNF,msg_p->result,av_bt_ctx.wait,go_on,need_reconfig);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AV_BT_TRC_GO_ON_DETAILS,av_bt_ctx.need_stop,av_bt_ctx.need_reconnect,av_bt_ctx.connect_post_proc);

    if (av_bt_ctx.wait == AV_BT_WAIT_OPEN_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
        av_bt_ctx.need_reconfig = KAL_FALSE;

        if (msg_p->result == BT_A2DP_RESULT_OK)
        {
            av_bt_ctx.state = AV_BT_STATE_OPEN;
        }

        if (av_bt_ctx.state == AV_BT_STATE_OPEN)
        {
            if (go_on)
            {
                if (need_reconfig)
                {
                    srv_a2dp_close_stream();
                }
                else
                {
                    srv_a2dp_start_stream();  
                }
            }
        }
        else if (msg_p->result != BT_A2DP_RESULT_NO_CONNECTION)
        {
            if (go_on)
            {
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                /* Reconnect SCO if A2DP connect fail */
                srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
            #endif
                srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_stream_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_open_stream_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 
    bt_a2dp_stream_open_ind_struct *msg_p = (bt_a2dp_stream_open_ind_struct*)msg;
    kal_uint16 response;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (av_bt_ctx.state == AV_BT_STATE_CONFIGURED)
    {
        av_bt_ctx.state = AV_BT_STATE_OPEN;
        response = BT_A2DP_RESULT_OK;
        /* start the timer for start streaming if remote side wouldn't send start_ind */
        StartTimer(AV_BT_START_TIMER, 500, (FuncPtr)srv_a2dp_close_or_start_stream);
    }
    else
    {
        response = BT_A2DP_BAD_STATE;
    }
    bt_a2dp_send_stream_open_res(MOD_MMI, response, msg_p->stream_handle);
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_start_stream_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_start_stream_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_stream_start_cnf_struct *msg_p = (bt_a2dp_stream_start_cnf_struct*)msg;
    kal_bool need_reconfig = av_bt_ctx.need_reconfig;
	kal_bool go_on = ( ( KAL_TRUE == (av_bt_ctx.need_stop || av_bt_ctx.need_reconnect) )?KAL_FALSE:KAL_TRUE);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_START_STREAM_CNF,msg_p->result,av_bt_ctx.wait,go_on,need_reconfig);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AV_BT_TRC_GO_ON_DETAILS,av_bt_ctx.need_stop,av_bt_ctx.need_reconnect,av_bt_ctx.connect_post_proc);

    if (av_bt_ctx.wait == AV_BT_WAIT_START_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
        av_bt_ctx.need_reconfig = KAL_FALSE;

        if (msg_p->result == BT_A2DP_RESULT_OK)
        {
            av_bt_ctx.state = AV_BT_STATE_STREAMING;
            if (go_on)
            {
                if (need_reconfig)
                {
                    srv_a2dp_close_stream();
                }
                else
                {
                #ifdef __MMI_BT_AUDIO_VIA_SCO__                    
                    /* disable to make sure sco will not be activated*/
                    srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_A2DP);
                #endif
                    srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_OPEN_OK);
                }
            }
            else
            {
                srv_a2dp_pause_stream();
            }
        }
        else if (msg_p->result != BT_A2DP_RESULT_NO_CONNECTION)
        {
            if (go_on)
            {
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                /* Reconnect SCO if A2DP connect fail */
                srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
            #endif
                srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_start_stream_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_start_stream_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_stream_start_ind_struct *msg_p = (bt_a2dp_stream_start_ind_struct*)msg;
    kal_uint16 response;
    void(*callback)(S32 res) = av_bt_ctx.callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    StopTimer(AV_BT_START_TIMER);
    srv_a2dp_stop_disc_timer();

    if (av_bt_ctx.state == AV_BT_STATE_OPEN && av_bt_ctx.check_output_callback())
    {
        av_bt_ctx.state = AV_BT_STATE_STREAMING;
        response = BT_A2DP_RESULT_OK;
    }
    else
    {
        response = BT_A2DP_BAD_STATE;
    }

    bt_a2dp_send_stream_start_res(MOD_MMI, response, msg_p->stream_handle);

    if(response != BT_A2DP_RESULT_OK)
    {
        return;
    }

    /* app already request a2dp srv to connect 
       BT headset start stream while a2dp service is disconnecting SCO,
       so let's postpone callback until disconnect sco is finished */
    if(av_bt_ctx.wait == AV_BT_WAIT_SCO_DISCONNECT_CALLBACK)
    {
        return;
    }

#ifdef __PLUTO_MMI_PACKAGE__
    /* let appliction know a stream is started and need to play a audio stuff */
    if (callback)
    {
        callback(SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND);
    }
    else
    {
        /* default callback: currently only support audio player */
        if(av_bt_ctx.default_callbacks[0] != NULL)
        {
            av_bt_ctx.default_callbacks[0](SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND);
        }
    }
#else /*Cosmos*/
    srv_btaud_stereo_notify(NULL);
#endif

    
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_pause_stream_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_pause_stream_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_stream_pause_cnf_struct *msg_p = (bt_a2dp_stream_pause_cnf_struct*)msg;
    kal_bool need_reconfig = av_bt_ctx.need_reconfig;
	kal_bool go_on = ( ( KAL_TRUE == (av_bt_ctx.need_stop || av_bt_ctx.need_reconnect) )?KAL_FALSE:KAL_TRUE);
    void(*callback)(S32 res) = av_bt_ctx.callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_PAUSE_CNF,msg_p->result,av_bt_ctx.wait,go_on,need_reconfig);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AV_BT_TRC_GO_ON_DETAILS,av_bt_ctx.need_stop,av_bt_ctx.need_reconnect,av_bt_ctx.connect_post_proc);

    if (av_bt_ctx.wait == AV_BT_WAIT_PAUSE_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;

        if (msg_p->result == BT_A2DP_RESULT_OK)
        {
            av_bt_ctx.state = AV_BT_STATE_OPEN;
        }

        if (av_bt_ctx.state == AV_BT_STATE_OPEN)
        {
            if (go_on)
            {
                if (need_reconfig)
                {
                    srv_a2dp_close_stream();
                }
                else
                {
                    srv_a2dp_start_stream();
                }
            }
        }
        else if (msg_p->result != BT_A2DP_RESULT_NO_CONNECTION)
        {
            if (go_on)
            {
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                /* Reconnect SCO if A2DP connect fail */
                srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
            #endif
                if (callback)
                {
                    av_bt_ctx.callback = NULL;
                    callback(SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
                }
            }
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_pause_stream_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_pause_stream_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_stream_pause_ind_struct *msg_p = (bt_a2dp_stream_pause_ind_struct*)msg;
    kal_uint16 response;
    void(*callback)(S32 res) = av_bt_ctx.callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (av_bt_ctx.state == AV_BT_STATE_STREAMING)
    {
        av_bt_ctx.state = AV_BT_STATE_OPEN;
        response = BT_A2DP_RESULT_OK;
        av_bt_ctx.need_stop = KAL_TRUE;
        srv_a2dp_start_disc_timer();
    }
    else
    {
        response = BT_A2DP_BAD_STATE;
    }

    bt_a2dp_send_stream_pause_res(MOD_MMI, response, msg_p->stream_handle);

    /* let appliction know a stream is paused and need to stop playing */
    if (callback)
    {
        callback(SRV_A2DP_CALLBACK_EVENT_STREAM_SUSPEND_IND);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close_stream_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_close_stream_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_bool go_on = ( ( KAL_TRUE == (av_bt_ctx.need_stop || av_bt_ctx.need_reconnect) )?KAL_FALSE:KAL_TRUE);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_CLOSE_CNF,av_bt_ctx.wait,go_on);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AV_BT_TRC_GO_ON_DETAILS,av_bt_ctx.need_stop,av_bt_ctx.need_reconnect,g_mmi_a2dp_cntx.state);

    if(g_mmi_a2dp_cntx.state == SRV_A2DP_STATE_DISCONNECTING)
    {
        av_bt_ctx.state = AV_BT_STATE_CONNECTED;

        if(av_bt_ctx.wait == AV_BT_WAIT_CLOSE_CNF)
        {
            av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
        }

        bt_a2dp_send_signal_disconnect_req(MOD_MMI, av_bt_ctx.connect_id);
        return;
    }

    if (av_bt_ctx.wait == AV_BT_WAIT_CLOSE_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
        av_bt_ctx.state = AV_BT_STATE_CONNECTED;
        if (go_on)
        {
            srv_a2dp_open_dev(KAL_TRUE);
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close_stream_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_close_stream_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_stream_close_ind_struct *msg_p = (bt_a2dp_stream_close_ind_struct*)msg;
    void(*callback)(S32 res) = av_bt_ctx.callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(av_bt_ctx.state == AV_BT_STATE_IDLE)
    {
        return;
    }

    av_bt_ctx.state = AV_BT_STATE_CONNECTED;

    bt_a2dp_send_stream_close_res(MOD_MMI, BT_A2DP_RESULT_OK, msg_p->stream_handle);
    
    StopTimer(AV_BT_START_TIMER);

    /* let appliction know a stream is paused and need to stop playing */

    if(av_bt_ctx.wait != AV_BT_WAIT_NONE_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
        /*this indicates that while application is expecting open result, earphone request to close*/
        srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND);

    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        /* Reconnect SCO if A2DP disconnect */    
        srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
    #endif

    }
    else if (callback)
    {
        callback(SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_abort_stream_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_abort_stream_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool go_on = ( ( KAL_TRUE == (av_bt_ctx.need_stop || av_bt_ctx.need_reconnect) )?KAL_FALSE:KAL_TRUE);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_ABORT_CNF,av_bt_ctx.wait,go_on);
    MMI_TRACE(MMI_MEDIA_TRC_G3_APP_DETAIL,MMI_AV_BT_TRC_GO_ON_DETAILS,av_bt_ctx.need_stop,av_bt_ctx.need_reconnect,av_bt_ctx.connect_post_proc);

    if (av_bt_ctx.wait == AV_BT_WAIT_ABORT_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
        av_bt_ctx.state = AV_BT_STATE_CONNECTED;
        if (go_on)
            srv_a2dp_open_dev(KAL_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_abort_stream_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_abort_stream_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_a2dp_stream_abort_ind_struct *msg_p = (bt_a2dp_stream_abort_ind_struct*)msg;
    void(*callback)(S32 res) = av_bt_ctx.callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    av_bt_ctx.state = AV_BT_STATE_CONNECTED;

    bt_a2dp_send_stream_abort_res(MOD_MMI, msg_p->stream_handle);
    
    StopTimer(AV_BT_START_TIMER);

    /* let appliction know a stream is paused and need to stop playing */
    if (callback)
    {
        callback(SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_inquiry_start_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_inquiry_start_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void(*callback)(S32 res) = av_bt_ctx.callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_INQUERY_START_CALLBACK,av_bt_ctx.is_inquiry, callback);

    if (!av_bt_ctx.is_inquiry)
    {
        av_bt_ctx.is_inquiry = KAL_TRUE;
        if (callback)
        {
            callback(SRV_A2DP_CALLBACK_EVENT_INQUIRY_START_IND);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_inquiry_stop_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_inquiry_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void(*callback)(S32 res) = av_bt_ctx.callback;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_INQUERY_STOP_CALLBACK,av_bt_ctx.is_inquiry, callback);
    
    if (av_bt_ctx.is_inquiry)
    {
        av_bt_ctx.is_inquiry = KAL_FALSE;
        if (callback)
        {
            callback(SRV_A2DP_CALLBACK_EVENT_INQUIRY_STOP_IND);
        }
        else
        {
            /* default callback: currently only support audio player, in cause during inquiry 
            time, callback is deleted so that application will not acting well*/
            if(av_bt_ctx.default_callbacks[0] != NULL)
            {
                av_bt_ctx.default_callbacks[0](SRV_A2DP_CALLBACK_EVENT_INQUIRY_STOP_IND);
            }
        }
    }
}

#ifdef __MMI_BT_AUDIO_VIA_SCO__
/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_sco_disconnected_event_hdlr
 * DESCRIPTION
 *  sco disconnected callback event hdlr
 * PARAMETERS
 *  param
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_a2dp_sco_disconnected_event_hdlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_SCO_DISCONNECTED,av_bt_ctx.need_stop);

    if(!av_bt_ctx.need_stop)
    {
        /* there is case that BT headset start stream ind when we are waiting for SCO disconnection, 
           for this case, the state will enter streaming thus don't need to connect again */

        if(av_bt_ctx.state == AV_BT_STATE_OPEN)
        {
            bt_a2dp_send_stream_start_req(MOD_MMI, av_bt_ctx.stream_handle);
            av_bt_ctx.wait = AV_BT_WAIT_START_CNF;
        }
        else if(av_bt_ctx.state == AV_BT_STATE_STREAMING)
        {
            av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;
            srv_a2dp_open_result(SRV_A2DP_CALLBACK_EVENT_OPEN_OK);
        }
    }

    mmi_frm_cb_dereg_event(EVT_ID_SRV_BTSCO_CLOSE_IND, (mmi_proc_func) srv_a2dp_sco_disconnected_event_hdlr, NULL);

    return MMI_RET_OK; 
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_connect_sco_callback_hdlr
 * DESCRIPTION
 *  sco connection callback hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_connect_sco_callback_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void(*callback)(S32 res) = av_bt_ctx.callback;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_SCO_CALLBACK,av_bt_ctx.wait,callback);

    if(av_bt_ctx.wait == AV_BT_WAIT_SCO_CONNECT_CNF)
    {
        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;

        if(callback)
        {
            av_bt_ctx.callback = NULL;
            av_bt_ctx.retry_success_callback = NULL;
            callback(SRV_A2DP_CALLBACK_EVENT_OPEN_SCO);
        }
        mdi_audio_set_pseudo_play_file_callback(NULL, NULL);
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_connect_hfp_callback_hdlr
 * DESCRIPTION
 *  connect HFP callback hdlr
 * PARAMETERS
 *  MMI_BOOL    [IN] indicate if connect success
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_connect_hfp_callback_hdlr(MMI_BOOL success)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    void(*callback)(S32 res) = av_bt_ctx.callback;
    MMI_BOOL output_to_bt = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_HFP_CALLBACK,av_bt_ctx.wait,success,callback);

    if(av_bt_ctx.wait == AV_BT_WAIT_HFP_CONNECT_CNF)
    {

        av_bt_ctx.wait = AV_BT_WAIT_NONE_CNF;

        if(!callback)
        {
            /*bt open request has been stopped*/
            mdi_audio_set_pseudo_play_file_callback(NULL, NULL);
            return;
        }

    #ifndef __MMI_A2DP_HIDE_BT_SETTINGS__
        output_to_bt = srv_bt_cm_is_audio_path_to_headset();
    #endif

        if(!success || !output_to_bt)
        {
            av_bt_ctx.callback = NULL;
            av_bt_ctx.retry_success_callback = NULL;
            mdi_audio_set_pseudo_play_file_callback(NULL, NULL);
            callback(SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
        }
        else
        {
            /*connect SCO with current hs conection*/
            if (srv_btsco_connect_sco_req(srv_a2dp_connect_sco_callback_hdlr))
            {
                /*start connecting*/
                av_bt_ctx.wait = AV_BT_WAIT_SCO_CONNECT_CNF;
            }
            else
            {
                /*not connect sco for some reason*/
                av_bt_ctx.callback = NULL;
                av_bt_ctx.retry_success_callback = NULL;
                mdi_audio_set_pseudo_play_file_callback(NULL, NULL);
                callback(SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
            }   
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_audio_via_sco
 * DESCRIPTION
 *  check if need to connect HFP / SCO
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_a2dp_open_result_enum    SRV_A2DP_OPEN_WAITING: need to wait HFP / SCO connect; 
 *                               SRV_A2DP_OPEN_FAILED: do not need to wait HFP / SCO connect
 *                               SRV_A2DP_OPEN_DONE: sco already connectd
 *****************************************************************************/
srv_a2dp_open_result_enum srv_a2dp_open_audio_via_sco(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_AV_BT_TRC_AUDIO_VIA_SCO);

#ifdef __MMI_A2DP_HIDE_BT_SETTINGS__
    {
        BtAudStatus status = srv_btaud_get_status(BTAUD_CHNL_ANY);

        if (status == BTAUD_ACTIVE)
        {
            if(!srv_bt_cm_is_audio_path_to_headset())
            {
               return SRV_A2DP_OPEN_FAILED;
            }

            /* not allow sco connection and return fail*/
            if(!srv_btsco_is_profile_connect_allowed())
            {
                return SRV_A2DP_OPEN_FAILED;
            }

            if (srv_btsco_connect_sco_req(srv_a2dp_connect_sco_callback_hdlr))
            {
                /*start connecting*/
                av_bt_ctx.wait = AV_BT_WAIT_SCO_CONNECT_CNF;
                return SRV_A2DP_OPEN_WAITING;
            }
            else
            {
                /*not connect sco for some reason*/
                return SRV_A2DP_OPEN_FAILED;
            }
        }
        
        if (status == BTAUD_SWITCH_ON)
        {
            /* not allow sco connection, so disconnect sco (casue sco might be connected by other module like FM) and return fail*/
            if(!srv_btsco_is_profile_connect_allowed())
            {
                srv_btsco_disconnect_sco_req();
                return SRV_A2DP_OPEN_FAILED;
            }
            else
            {
                return SRV_A2DP_OPEN_DONE;
            }
        }

        return SRV_A2DP_OPEN_FAILED;
    }

#else
    if(!srv_bt_cm_get_default_dev_addr(SRV_BT_CM_DEFAULT_DEV_TYPE_HS))
    {
        /*default earphone not existed*/

        if(!(srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)))
        {
            /*no existed hs connection*/
            return SRV_A2DP_OPEN_FAILED;
        }

    #ifndef __MMI_A2DP_HIDE_BT_SETTINGS__
        if(!srv_bt_cm_is_audio_path_to_headset())
        {
           return SRV_A2DP_OPEN_FAILED;
        }
    #endif

        /* not allow sco connection, so disconnect sco (casue sco might be connected by other module like FM) and return fail*/
        if(!srv_btsco_is_profile_connect_allowed())
        {
            srv_btsco_disconnect_sco_req();
            return SRV_A2DP_OPEN_FAILED;
        }

        if(srv_bt_cm_is_audio_link_on())
        {
            /* SCO already connected*/
            return SRV_A2DP_OPEN_DONE;
        }

        /*connect SCO with current hs conection*/
        if (srv_btsco_connect_sco_req(srv_a2dp_connect_sco_callback_hdlr))
        {
            /*start connecting*/
            av_bt_ctx.wait = AV_BT_WAIT_SCO_CONNECT_CNF;
            return SRV_A2DP_OPEN_WAITING;
        }
        else
        {
            /*not connect sco for some reason*/
            return SRV_A2DP_OPEN_FAILED;
        }
    }
    else
    {
        /*default earphone existed*/

        if(!(srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)))
        {
            /*no existed hs connection*/
            if(!srv_bt_cm_connect_default_headset(srv_a2dp_connect_hfp_callback_hdlr))
            {
                return SRV_A2DP_OPEN_FAILED;  
            }
            av_bt_ctx.wait = AV_BT_WAIT_HFP_CONNECT_CNF;
            return SRV_A2DP_OPEN_WAITING;
        }

    #ifndef __MMI_A2DP_HIDE_BT_SETTINGS__
        if(!srv_bt_cm_is_audio_path_to_headset())
        {
           return SRV_A2DP_OPEN_FAILED;
        }
    #endif

        /* not allow sco connection, so disconnect sco (casue sco might be connected by other module like FM) and return fail*/
        if(!srv_btsco_is_profile_connect_allowed())
        {
            srv_btsco_disconnect_sco_req();
            return SRV_A2DP_OPEN_FAILED;
        }

        if(srv_bt_cm_is_audio_link_on())
        {
            /* SCO already connected*/
            return SRV_A2DP_OPEN_DONE;
        }

        /*connect SCO with current hs conection*/
        if (srv_btsco_connect_sco_req(srv_a2dp_connect_sco_callback_hdlr))
        {
            /*start connecting*/
            av_bt_ctx.wait = AV_BT_WAIT_SCO_CONNECT_CNF;
            return SRV_A2DP_OPEN_WAITING;
        }
        else
        {
            /*not connect sco for some reason*/
            return SRV_A2DP_OPEN_FAILED;
        }

    }

#endif
}
#endif /*__MMI_BT_AUDIO_VIA_SCO__*/
    
#endif /* __MMI_A2DP_SUPPORT__ */
