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
 * A2dpSrv.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * A2DP service header file
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __A2DP_SRV_H__
#define __A2DP_SRV_H__

#include "BtcmSrvGprot.h"
#include "A2dpSrvGProt.h"

#include "mmi_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "bt_a2dp_base_struct.h"
#include "kal_general_types.h"
#include "MMI_features.h"

typedef enum
{
    AV_BT_STATE_IDLE,
    AV_BT_STATE_CONNECTED,
    AV_BT_STATE_CONFIGURED,
    AV_BT_STATE_OPEN,
    AV_BT_STATE_STREAMING,
    NO_OF_AV_BT_STATE
} av_bt_state_enum;

typedef enum
{
    AV_BT_WAIT_NONE_CNF,
    AV_BT_WAIT_CONNECT_CNF,
    AV_BT_WAIT_DISCOVER_CNF,
    AV_BT_WAIT_GET_CAP_CNF,
    AV_BT_WAIT_CONFIG_CNF,
    AV_BT_WAIT_OPEN_CNF,
    AV_BT_WAIT_START_CNF,
    AV_BT_WAIT_PAUSE_CNF,
    AV_BT_WAIT_CLOSE_CNF,
    AV_BT_WAIT_ABORT_CNF,
    AV_BT_WAIT_DISCONNECT_CNF,
    AV_BT_WAIT_HFP_CONNECT_CNF,
    AV_BT_WAIT_SCO_CONNECT_CNF,
    AV_BT_WAIT_SCO_DISCONNECT_CALLBACK,
    NO_OF_AV_BT_WAIT_CNF
} av_bt_wait_cnf_enum;

typedef enum
{
    SRV_A2DP_REQ_FLAG_NONE,
    SRV_A2DP_REQ_FLAG_APP = 1,
    SRV_A2DP_REQ_FLAG_CM = 2
} srv_a2dp_req_flag_enum;

#define MMI_A2DP_LOG_STATE()                                                   \
{                                                                              \
    MMI_TRACE(MMI_TRACE_INFO, MMI_A2DP_STATE_CURRENT, g_mmi_a2dp_cntx.state);\
}

#define MMI_A2DP_LOG_STATE_ERR()                                             \
{                                                                            \
    MMI_TRACE(MMI_TRACE_INFO, MMI_A2DP_STATE_ERROR, g_mmi_a2dp_cntx.state);\
}

#define MMI_A2DP_LOG_TRANS_STATE(x)                                                  \
{                                                                                    \
    MMI_TRACE(MMI_TRACE_INFO, MMI_A2DP_STATE_TRANSITION, g_mmi_a2dp_cntx.state, x);\
}

#define MMI_A2DP_STATE_TRANS(x)  \
{                                \
    MMI_A2DP_LOG_TRANS_STATE(x); \
    g_mmi_a2dp_cntx.state = x;   \
}

/* Internal Prototype */

extern void srv_bt_a2dp_activate_req(void);
extern void srv_bt_a2dp_activate_cnf_hdlr(void *msg);
extern void srv_bt_a2dp_deactivate_req(void);
extern void srv_bt_a2dp_deactivate_cnf_hdlr(void *msg);
extern void srv_bt_a2dp_connect_req(srv_bt_cm_bt_addr dev_addr);
extern void srv_bt_a2dp_connect_req_by_cm(srv_bt_cm_bt_addr dev_addr);
extern void srv_bt_a2dp_disconnect_req(srv_bt_cm_bt_addr dev_addr, U32 connect_id);
extern void srv_bt_a2dp_disconnect_req_by_cm(U32 connect_id);
extern void srv_bt_a2dp_connect_ind_hdlr(void *msg);
extern void srv_bt_a2dp_connect_cnf_hdlr(void *msg);
extern void srv_bt_a2dp_disconnect_cnf_hdlr(void *msg);
extern void srv_bt_a2dp_disconnect_ind_hdlr(void *msg);

extern kal_bool srv_a2dp_is_mp3_codec_open(void);
extern A2DP_SRV_CALLBACK srv_a2dp_get_callback(void);
extern kal_bool srv_a2dp_cmp_bt_addr(srv_bt_cm_bt_addr *bt_addr1, srv_bt_cm_bt_addr *bt_addr2);
extern void srv_a2dp_check_and_restart_disc_timer(void);
extern kal_bool srv_a2dp_open_dev(kal_bool done_callback);
extern kal_bool srv_a2dp_close_dev(void);
extern void srv_a2dp_start_disc_timer(void);
extern void srv_a2dp_stop_disc_timer(void);
extern void srv_a2dp_connect(void);
extern void srv_a2dp_disconnect(void);
extern kal_bool srv_a2dp_discover_stream(void);
extern kal_bool srv_a2dp_get_stream_cap(void);
extern void srv_a2dp_config_stream(void);
extern void srv_a2dp_open_stream(void);
extern void srv_a2dp_start_stream(void);
extern void srv_a2dp_delay_pause_stream_time_out(void);
extern void srv_a2dp_pause_stream(void);
extern void srv_a2dp_close_stream(void);
extern void srv_a2dp_abort_stream(void);
extern void srv_a2dp_connect_cnf(void* msg);
extern void srv_a2dp_connect_ind(void *msg);
extern void srv_a2dp_disconnect_cnf(void *msg);
extern void srv_a2dp_disconnect_ind(void *msg);
extern void srv_a2dp_discover_stream_cnf(void* msg);
extern void srv_a2dp_discover_stream_ind(void *msg);
extern void srv_a2dp_get_stream_cap_cnf(void *msg);
extern void srv_a2dp_get_stream_cap_ind(void *msg);
extern void srv_a2dp_config_stream_cnf(void* msg);
extern void srv_a2dp_config_stream_ind(void *msg);
extern void srv_a2dp_open_stream_cnf(void* msg);
extern void srv_a2dp_open_stream_ind(void* msg);
extern void srv_a2dp_start_stream_cnf(void *msg);
extern void srv_a2dp_start_stream_ind(void *msg);
extern void srv_a2dp_pause_stream_cnf(void *msg);
extern void srv_a2dp_pause_stream_ind(void *msg);
extern void srv_a2dp_abort_stream_cnf(void *msg);
extern void srv_a2dp_abort_stream_ind(void *msg);
extern void srv_a2dp_close_stream_cnf(void *msg);
extern void srv_a2dp_close_stream_ind(void *msg);
extern void srv_a2dp_close_codec_ind(void *msg);

#ifdef __MMI_BT_AUDIO_VIA_SCO__
extern mmi_ret srv_a2dp_sco_disconnected_event_hdlr(void *param);
extern srv_a2dp_open_result_enum srv_a2dp_open_audio_via_sco(void);
#endif

#ifdef __WIFI_BT_SINGLE_ANTENNA_SUPPORT__
extern kal_bool srv_bt_a2dp_if_apply_min_bit_rate(void);
#endif


#endif /* __A2DP_SRV_H__ */
