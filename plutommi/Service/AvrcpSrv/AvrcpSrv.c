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
 * BTMMIAVRCP.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for Bluetooth AVRCP MMI application
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"
#include "MMI_features.h"
#if (defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__))
/***************************************************************************** 
* Included files
*****************************************************************************/
//#include "ProtocolEvents.h"
#if defined(__MMI_TOUCH_SCREEN__)
#endif
/* Trace Header Files */

/* avrcp header files */
#include "bt_avrcp_struct.h"
#include "bt_avrcp.h"

#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"

#ifdef __MMI_A2DP_SUPPORT__
//#include "av_bt.h"
#endif

#include "mmi_rp_srv_avrcp_def.h"

#include "AvrcpSrv.h"
#include "AvrcpSrvGprot.h"
#include "A2dpSrv.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_conn_app_trc.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "TimerEvents.h"
#include "wgui_categories_list.h"
#include "mmi_frm_timer_gprot.h"

/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
/*
* Target global context, use channel 0
* Controller global context, use channel 1
*/
static const srv_bt_cm_profile_struct g_avrcp_tg_prof = {
    SRV_BT_CM_AV_REMOTE_CONTROL_TARGET_UUID,
    srv_avrcp_activate_tg_req,
    srv_avrcp_deactivate_tg_req,
    srv_avrcp_disconnect_tg_req,
};

static const srv_bt_cm_profile_struct g_avrcp_ct_prof = {
    SRV_BT_CM_AV_REMOTE_CONTROL_UUID,
    srv_avrcp_activate_ct_req,
    srv_avrcp_deactivate_ct_req,
    srv_avrcp_disconnect_ct_req
};

mmi_avrcp_cntx_struct g_mmi_avrcp_cntx[BT_AVRCP_MAX_CHANNEL];

#define BT_AVRCP_MAX_CALLBACK_NUM 2
//static AVRCP_SRV_CMD_CALLBACK g_mmi_avrcp_cmd_func_ptr;
static AVRCP_SRV_CMD_CALLBACK g_mmi_avrcp_cmd_func_ptr_list[BT_AVRCP_MAX_CALLBACK_NUM]; /* at most 2 func ptr */
static S32 g_mmi_avrcp_cmd_func_ptr_count = 0 ; /* at most 2 func ptr */
static MMI_BOOL g_mmi_avrcp_disconnect_from_av_bt = MMI_FALSE; /* indicate if it is disconnect from a2dp actuvely disconnection*/

static U8 g_mmi_avrcp_last_pressed_cmd = 0xff; /* last pressed command, 0xff is a non spec command value to identify there is no command */
static U8 g_mmi_avrcp_pressed_cmd_count = 0 ;  /* to accumulate total pressed cmd numer with the same av/c command */
static MMI_BOOL g_mmi_avrcp_frm_blocked = MMI_FALSE ;  /* framework keypad / touch blocked */
#ifdef __MMI_AVRCP_CT_SUPPORT__
static AVRCP_SRV_CMD_CNF_CALLBACK g_mmi_avrcp_cmd_cnf_ptr;
#endif

#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
static MMI_BOOL g_mmi_avrcp_actively_connect_tg = MMI_FALSE;
#endif

/***************************************************************************** 
* External Functions
*****************************************************************************/

/***************************************************************************** 
* Functions
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_cmd_hdlr
 * DESCRIPTION
 *  This function is to get the latest register cmd hdlr ptr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static AVRCP_SRV_CMD_CALLBACK srv_avrcp_get_cmd_hdlr_func_ptr(void)
{
    S32 i = g_mmi_avrcp_cmd_func_ptr_count;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_GET_CMD_HDLR_FUNC_HDLR, i);

    if (i == 0)
        return NULL;

    ASSERT( i <= BT_AVRCP_MAX_CALLBACK_NUM );

    return g_mmi_avrcp_cmd_func_ptr_list[i-1];
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_init
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_INIT);
    srv_avrcp_init_event_handler();

    srv_bt_cm_profile_register(&g_avrcp_tg_prof);
    srv_bt_cm_profile_register(&g_avrcp_ct_prof);

    for(i = 0 ; i < BT_AVRCP_MAX_CHANNEL ; i++)
    {
        MMI_AVRCP_STATE_TRANS(i, SRV_AVRCP_IDLE);
    }

//    g_mmi_avrcp_cmd_func_ptr_count = 0;
//    g_mmi_avrcp_cmd_func_ptr_list[0] = g_mmi_avrcp_cmd_func_ptr_list[1] = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_init_event_handler
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_init_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_INIT_EVENT_HDLR);

    SetProtocolEventHandler(srv_avrcp_activate_cnf_hdlr, MSG_ID_BT_AVRCP_ACTIVATE_CNF);
    SetProtocolEventHandler(srv_avrcp_deactivate_cnf_hdlr, MSG_ID_BT_AVRCP_DEACTIVATE_CNF);
    SetProtocolEventHandler(srv_avrcp_connect_cnf_hdlr, MSG_ID_BT_AVRCP_CONNECT_CNF);
    SetProtocolEventHandler(srv_avrcp_connect_ind_hdlr, MSG_ID_BT_AVRCP_CONNECT_IND);
    SetProtocolEventHandler(srv_avrcp_disconnect_cnf_hdlr, MSG_ID_BT_AVRCP_DISCONNECT_CNF);
    SetProtocolEventHandler(srv_avrcp_disconnect_ind_hdlr, MSG_ID_BT_AVRCP_DISCONNECT_IND);

    SetProtocolEventHandler(srv_avrcp_cmd_frame_cnf_hdlr, MSG_ID_BT_AVRCP_CMD_FRAME_CNF);
    SetProtocolEventHandler(srv_avrcp_cmd_frame_ind_hdlr, MSG_ID_BT_AVRCP_CMD_FRAME_IND);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_activate_tg_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_activate_tg_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_activate_req(BT_AVRCP_TG);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_activate_ct_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_activate_ct_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_activate_req(BT_AVRCP_CT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_activate_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  avrcp_role      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_activate_req(U8 avrcp_role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_ACTIVATE_REQ);    
    MMI_AVRCP_LOG_STATE(avrcp_role);

    MMI_AVRCP_ASSERT(avrcp_role == BT_AVRCP_TG || avrcp_role == BT_AVRCP_CT);

    if (MMI_AVRCP_CTX(avrcp_role, avrcp_state) != SRV_AVRCP_IDLE)
    {
        return;
    }

    g_mmi_avrcp_cntx[avrcp_role].avrcp_role = avrcp_role;

    /* Currently two channels, use role value as channel number */
    bt_avrcp_send_activate_req(MOD_MMI, avrcp_role, avrcp_role);

    MMI_AVRCP_STATE_TRANS(avrcp_role, SRV_AVRCP_ACTIVATING);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_activate_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_activate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_activate_cnf_struct *msg_p = (bt_avrcp_activate_cnf_struct*) msg;
    U8 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_ACTIVATE_CNF_HDLR);

    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;

    if (msg_p->result == BT_AVRCP_RESULT_SUCCESS)
    {
        if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == SRV_AVRCP_ACTIVATING)
        {
            MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_ACTIVATED);
            if (g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_TG)
            {
                srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_AV_REMOTE_CONTROL_TARGET_UUID);
            }
            else if (g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_CT)
            {
                srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_AV_REMOTE_CONTROL_UUID);
            }
        }
    }
    else /* Should not activate fail*/
    {
        MMI_AVRCP_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_deactivate_tg_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_deactivate_tg_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_deactivate_req(BT_AVRCP_TG);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_deactivate_ct_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_deactivate_ct_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_deactivate_req(BT_AVRCP_CT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_deactivate_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_deactivate_req(U8 avrcp_chnl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DEACTIVATE_REQ);
    MMI_AVRCP_ASSERT(avrcp_chnl < BT_AVRCP_MAX_CHANNEL);

    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == SRV_AVRCP_ACTIVATED ||
        MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == SRV_AVRCP_ACTIVATING)
    {
        bt_avrcp_send_deactivate_req(MOD_MMI, avrcp_chnl);
        MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_DEACTIVATING);
    }
    /* If in connected state, need to disconnect in advance */
    else if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == SRV_AVRCP_CONNECTED)
    {
        bt_avrcp_send_disconnect_req(MOD_MMI, avrcp_chnl);
        MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_DEACTIVATING);
    }
    /* Wait connect / disconnect response to deactivate AVRCP */
    else if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == SRV_AVRCP_DISCONNECTING ||
             MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == SRV_AVRCP_CONNECTING)
    {
        MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_DEACTIVATING);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_deactivate_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_deactivate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_deactivate_cnf_struct *msg_p = (bt_avrcp_deactivate_cnf_struct*) msg;
    U8 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DEACTIVATE_CNF_HDLR);
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;

    if (msg_p->result == BT_AVRCP_RESULT_SUCCESS)
    {
        MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_IDLE);

        if (g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_TG)
        {
            srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_AV_REMOTE_CONTROL_TARGET_UUID);
        }
        else
        {
            srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_AV_REMOTE_CONTROL_UUID);
        }
    }
    else
    {
        /* Should not deactivate fail */
        MMI_AVRCP_ASSERT(0);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_tg_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_connect_tg_req(srv_bt_cm_bt_addr dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_connect_req(BT_AVRCP_TG, dev_addr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_ct_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_connect_ct_req(srv_bt_cm_bt_addr dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_connect_req(BT_AVRCP_CT, dev_addr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_connect_req(U8 avrcp_chnl, srv_bt_cm_bt_addr dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_dev_addr_struct bt_addr;
    U32 profile_id = 0;
    S32 cmgr_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CONNECT_REQ);
    MMI_AVRCP_ASSERT(avrcp_chnl < BT_AVRCP_MAX_CHANNEL);
    
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) != SRV_AVRCP_ACTIVATED)
        return;

    if (avrcp_chnl == BT_AVRCP_CT)
        profile_id = SRV_BT_CM_AV_REMOTE_CONTROL_UUID;
    else
        profile_id = SRV_BT_CM_AV_REMOTE_CONTROL_TARGET_UUID;

    cmgr_id = srv_bt_cm_start_conn(MMI_FALSE, profile_id, &dev_addr, NULL);

    g_mmi_avrcp_cntx[avrcp_chnl].cmgr_id = cmgr_id;

    bt_addr.lap = dev_addr.lap;
    bt_addr.uap = dev_addr.uap;
    bt_addr.nap = dev_addr.nap;

    bt_avrcp_send_connect_req(MOD_MMI, avrcp_chnl, &bt_addr, g_mmi_avrcp_cntx[avrcp_chnl].avrcp_role);

    MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_CONNECTING);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_connect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_connect_cnf_struct *msg_p = (bt_avrcp_connect_cnf_struct*) msg;
    U8 avrcp_chnl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CONNECT_CNF_HDLR);
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;
    
    g_mmi_avrcp_cntx[avrcp_chnl].device_addr = msg_p->device_addr;

    switch (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state))
    {
        case SRV_AVRCP_CONNECTING:

            /* Change state when connect success */
            if (msg_p->result == BT_AVRCP_RESULT_SUCCESS)
            {
                MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_CONNECTED);
                g_mmi_avrcp_last_pressed_cmd = 0xff;
                g_mmi_avrcp_pressed_cmd_count = 0;
                srv_bt_cm_connect_ind(g_mmi_avrcp_cntx[avrcp_chnl].cmgr_id);
            }
            /* Connect fail */
            else
            {
                MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_ACTIVATED);
                srv_bt_cm_stop_conn(g_mmi_avrcp_cntx[avrcp_chnl].cmgr_id);
                g_mmi_avrcp_cntx[avrcp_chnl].cmgr_id = 0;
            }

            break;

        case SRV_AVRCP_DISCONNECTING:
            break;

        case SRV_AVRCP_DEACTIVATING:
            bt_avrcp_send_deactivate_req(MOD_MMI, avrcp_chnl);
            break;

        default:
            MMI_AVRCP_LOG_STATE_ERR(avrcp_chnl);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_ind_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_connect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_connect_ind_struct *msg_p = (bt_avrcp_connect_ind_struct*) msg;
    U32 profile_id;
    U8 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CONNECT_IND_HDLR);
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;
    
    g_mmi_avrcp_cntx[avrcp_chnl].device_addr = msg_p->device_addr;

    switch (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state))
    {
        case SRV_AVRCP_ACTIVATED:
        case SRV_AVRCP_CONNECTING:

            MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_CONNECTED);
            g_mmi_avrcp_last_pressed_cmd = 0xff;
            g_mmi_avrcp_pressed_cmd_count = 0;

            if (avrcp_chnl == BT_AVRCP_CT)
                profile_id = SRV_BT_CM_AV_REMOTE_CONTROL_UUID;
            else
                profile_id = SRV_BT_CM_AV_REMOTE_CONTROL_TARGET_UUID;
            g_mmi_avrcp_cntx[avrcp_chnl].cmgr_id = srv_bt_cm_start_conn(MMI_TRUE, profile_id, (srv_bt_cm_bt_addr*)&msg_p->device_addr, NULL);

            srv_bt_cm_connect_ind(g_mmi_avrcp_cntx[avrcp_chnl].cmgr_id);
            
            break;

        default:
            MMI_AVRCP_LOG_STATE_ERR(avrcp_chnl);
            break;
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_from_a2dp
 * DESCRIPTION
 *  to set the flag of disconnect avrcp from av_bt, 
 *  so that we can judge if we shall inform cm for disconnect ind or cnf
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_from_a2dp(MMI_BOOL set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DISCONNECT_FROM_AVBT,g_mmi_avrcp_disconnect_from_av_bt,set);

    g_mmi_avrcp_disconnect_from_av_bt = set;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_tg_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_tg_req(U32 cmgr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_disconnect_req(
        BT_AVRCP_TG, 
        *((srv_bt_cm_bt_addr *)&g_mmi_avrcp_cntx[BT_AVRCP_TG].device_addr),
        cmgr_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_ct_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_ct_req(U32 cmgr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_disconnect_req(
        BT_AVRCP_CT, 
        *((srv_bt_cm_bt_addr *)&g_mmi_avrcp_cntx[BT_AVRCP_CT].device_addr),
        cmgr_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        [IN]        
 *  connect_id      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_req(U8 avrcp_chnl, srv_bt_cm_bt_addr dev_addr, U32 cmgr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DISCONNECT_REQ);
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    //if (cmgr_id != g_mmi_avrcp_cntx[avrcp_chnl].cmgr_id)
    //    return;

    if (MMI_AVRCP_CTX(avrcp_chnl,avrcp_state) == SRV_AVRCP_CONNECTED ||
        MMI_AVRCP_CTX(avrcp_chnl,avrcp_state) == SRV_AVRCP_CONNECTING)
    {
        bt_avrcp_send_disconnect_req(MOD_MMI, avrcp_chnl);

        MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_DISCONNECTING);
    }
    else
    {
        srv_avrcp_disconnect_from_a2dp(MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_disconnect_cnf_struct *msg_p = (bt_avrcp_disconnect_cnf_struct*) msg;
    U8 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DISCONNECT_CNF_HDLR);
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;

    srv_avrcp_disconnect_from_a2dp(MMI_FALSE);

    switch (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state))
    {
        case SRV_AVRCP_DISCONNECTING:
        {
            MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_ACTIVATED);

            srv_bt_cm_stop_conn(g_mmi_avrcp_cntx[avrcp_chnl].cmgr_id);
            g_mmi_avrcp_cntx[avrcp_chnl].cmgr_id = 0;

            break;
        }

        case SRV_AVRCP_DEACTIVATING:
        {
            bt_avrcp_send_deactivate_req(MOD_MMI, avrcp_chnl);
            break;
        }

        default:
        {
            MMI_AVRCP_LOG_STATE_ERR(avrcp_chnl);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_ind_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_disconnect_ind_struct *msg_p = (bt_avrcp_disconnect_ind_struct*)msg;
    U8 avrcp_chnl;
    AVRCP_SRV_CMD_CALLBACK func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DISCONNECT_IND_HDLR);

    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;

    srv_avrcp_disconnect_from_a2dp(MMI_FALSE);

    /* Change to activated state if not in idle state */
    if(MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) > SRV_AVRCP_IDLE)
    {
        srv_bt_cm_stop_conn(g_mmi_avrcp_cntx[avrcp_chnl].cmgr_id);
        g_mmi_avrcp_cntx[avrcp_chnl].cmgr_id = 0;

        MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_ACTIVATED);

        /*to handle the button down cancel action*/
        if ( (func_ptr = srv_avrcp_get_cmd_hdlr_func_ptr()) != NULL && g_mmi_avrcp_last_pressed_cmd != 0xff)
        {
            func_ptr(g_mmi_avrcp_last_pressed_cmd, (srv_avrcp_key_events)MMI_AVRCP_KEY_CANCELED);
            g_mmi_avrcp_last_pressed_cmd = 0xff;
            g_mmi_avrcp_pressed_cmd_count = 0;
        }        
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_cmd_frame_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_cmd_frame_req(U8 avrcp_chnl, U8 op_code, U8 op_id, U8 key_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ctype = 0;
    U8 subunit_type = 0;
    U8 subunit_id = 0;
    U8 send_data[BT_AVRCP_MAX_CMD_FRAME_SIZE];
    U16 length = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CMD_FRAME_REQ);
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) != SRV_AVRCP_CONNECTED)
    {
        return;
    }

    switch (op_code)
    {
        case BT_AVRCP_OP_UNIT_INFO:
            ctype = BT_AVRCP_CR_STATUS;
            subunit_type = BT_AVRCP_SUBUNIT_TYPE_UNIT_INFO;
            subunit_id = BT_AVRCP_SUBUNIT_ID_UNIT_INFO;
            send_data[0] = BT_AVRCP_OP_UNIT_INFO;
            send_data[1] = 0xFF;
            send_data[2] = 0xFF;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF; 
            length = 6;
            
        break;

        case BT_AVRCP_OP_SUBUNIT_INFO:
            ctype = BT_AVRCP_CR_STATUS;
            subunit_type = BT_AVRCP_SUBUNIT_TYPE_SUBUNIT_INFO; 
            subunit_id = BT_AVRCP_SUBUNIT_ID_SUBUNIT_INFO;
            send_data[0] = BT_AVRCP_OP_SUBUNIT_INFO;
            send_data[1] = 0x07;
            send_data[2] = 0xFF;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF; 
            length = 6; 
            
        break;

        case BT_AVRCP_OP_PASS_THROUGH:
            ctype = BT_AVRCP_CR_CONTROL;
            subunit_type = BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH;            
            subunit_id = BT_AVRCP_SUBUNIT_ID_PASS_THROUGH;
            send_data[0] = BT_AVRCP_OP_PASS_THROUGH;

            if(key_down) /* down */
            {
                send_data[1] = op_id;
            }
            else /* up */
            {
                send_data[1] = op_id | 0x80;          
            }

            send_data[2] = 0;
            length = 3 ;
        break;

        case BT_AVRCP_OP_VENDOR:
        default:
            /*not support now*/
        return;
    }
        

    bt_avrcp_send_cmd_frame_req(MOD_MMI,
                                avrcp_chnl,
                                0, /* Not used */
                                ctype,
                                subunit_type,
                                subunit_id,
                                length,
                                &send_data[0]);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_cmd_frame_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_set_cmd_frame_cnf_hdlr(AVRCP_SRV_CMD_CNF_CALLBACK callback_func)
{
#ifdef __MMI_AVRCP_CT_SUPPORT__
    g_mmi_avrcp_cmd_cnf_ptr = callback_func;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_cmd_frame_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_cmd_frame_cnf_hdlr(void *msg)
{
#ifdef __MMI_AVRCP_CT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_cmd_frame_cnf_struct *msg_p = (bt_avrcp_cmd_frame_cnf_struct*) msg;
    U16 cmd_type = 0;
    U8 avrcp_chnl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CMD_FRAME_CNF_HDLR);
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);
    avrcp_chnl = msg_p->chnl_num;
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    cmd_type = srv_avrcp_util_check_cmd_type(
                msg_p->c_type,
                msg_p->subunit_type,
                msg_p->subunit_id,
                msg_p->data_len,
                msg_p->frame_data);
                
    switch (cmd_type)
    {
        case BT_AVRCP_OP_UNIT_INFO:
            if (g_mmi_avrcp_cmd_cnf_ptr != NULL)
            {
                g_mmi_avrcp_cmd_cnf_ptr(BT_AVRCP_OP_UNIT_INFO, 0, 0);
            }
            break;

        case BT_AVRCP_OP_SUBUNIT_INFO:
            if (g_mmi_avrcp_cmd_cnf_ptr != NULL)
            {
                g_mmi_avrcp_cmd_cnf_ptr(BT_AVRCP_OP_SUBUNIT_INFO, 0, 0);
            }
            break;

        case BT_AVRCP_OP_PASS_THROUGH:
            if (g_mmi_avrcp_cmd_cnf_ptr != NULL)
            {
                g_mmi_avrcp_cmd_cnf_ptr(BT_AVRCP_OP_PASS_THROUGH,(U16) (msg_p->frame_data[1] & 0x7f), (BOOL) (msg_p->frame_data[1] & 0x80));
            }
            break;

        default:
            break;
    }
#endif /* __MMI_AVRCP_CT_SUPPORT__ */
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_cmd_frame_ind_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg     [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_cmd_frame_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_cmd_frame_ind_struct *msg_p = (bt_avrcp_cmd_frame_ind_struct*) msg;
    AVRCP_SRV_CMD_CALLBACK func_ptr;
    U16 cmd_type = 0;
    U8 send_len;
    U8 send_data[6];
    U8 type_result = BT_AVRCP_CR_NOT_IMPLEMENT;
    U8 avrcp_chnl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CMD_FRAME_IND_HDLR,g_mmi_avrcp_frm_blocked);
    MMI_AVRCP_ASSERT(msg_p->chnl_num < BT_AVRCP_MAX_CHANNEL);    
    avrcp_chnl = msg_p->chnl_num;
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    cmd_type = srv_avrcp_util_check_cmd_type(
                msg_p->c_type,
                msg_p->subunit_type,
                msg_p->subunit_id,
                msg_p->data_len,
                msg_p->frame_data);

#ifdef __MMI_A2DP_SUPPORT__
    srv_a2dp_check_and_restart_disc_timer();
#endif

    switch (cmd_type)
    {
        case BT_AVRCP_OP_UNIT_INFO:
        {
            send_data[0] = BT_AVRCP_OP_UNIT_INFO;
            send_data[1] = 0x07;
            send_data[2] = 0x48;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF;
            send_len = 6;

            bt_avrcp_send_cmd_frame_ind_res(
                MOD_MMI,
                avrcp_chnl,                
                msg_p->seq_id,
                msg_p->profile_id,
                BT_AVRCP_CR_STABLE,
                BT_AVRCP_SUBUNIT_TYPE_UNIT_INFO,
                BT_AVRCP_SUBUNIT_ID_UNIT_INFO,
                send_len,
                send_data);
        }
        break;

        case BT_AVRCP_OP_SUBUNIT_INFO:
        {
            send_data[0] = BT_AVRCP_OP_SUBUNIT_INFO;
            send_data[1] = 0x07;
            send_data[2] = 0x48;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF;
            send_len = 6;

            bt_avrcp_send_cmd_frame_ind_res(
                MOD_MMI,
                avrcp_chnl,                
                msg_p->seq_id,
                msg_p->profile_id,
                BT_AVRCP_CR_STABLE,
                BT_AVRCP_SUBUNIT_TYPE_SUBUNIT_INFO,
                BT_AVRCP_SUBUNIT_ID_SUBUNIT_INFO,
                send_len,
                send_data);
        }
        break;

        case BT_AVRCP_OP_PASS_THROUGH:
        {
            type_result = MMI_AVRCP_CR_REJECT;
            
            if ((func_ptr = srv_avrcp_get_cmd_hdlr_func_ptr()) != NULL && !g_mmi_avrcp_frm_blocked)
            {
                U8 command = msg_p->frame_data[1] & 0x7f ;
                if( (msg_p->frame_data[1] & 0x80) == 0 )
                {
                    /*key pressed*/

                    /* receive another pressed cmd while previous */
                    /* pressed command has not released yet,      */
                    /* 1. auto relase previous command first      */
                    /* 2. pass current pressed cmd                */
                    if( (g_mmi_avrcp_last_pressed_cmd != 0xff) && (g_mmi_avrcp_last_pressed_cmd != command))
                    {
                        srv_avrcp_auto_release_cmd();
                        g_mmi_avrcp_last_pressed_cmd = command ;
                        g_mmi_avrcp_pressed_cmd_count = 1 ;
                        type_result = func_ptr( command, (srv_avrcp_key_events)MMI_AVRCP_KEY_DOWN);
                        StartTimer(BT_AVRCP_AUTO_RELEASE_TIMER, 2000, (FuncPtr)srv_avrcp_auto_release_cmd);
                    }
                    /* receive the same pressed cmd, */
                    /* 1. restart timer              */
                    /* 2. pass longpress or repeat   */
                    else if(g_mmi_avrcp_last_pressed_cmd == command)
                    {
                        StartTimer(BT_AVRCP_AUTO_RELEASE_TIMER, 2000, (FuncPtr)srv_avrcp_auto_release_cmd);
                        g_mmi_avrcp_pressed_cmd_count ++ ;
                        if( g_mmi_avrcp_pressed_cmd_count > 2 )
                        {
                            type_result = func_ptr( command, (srv_avrcp_key_events)MMI_AVRCP_KEY_REPEAT);
                        }
                        else
                        {
                            type_result = func_ptr( command, (srv_avrcp_key_events)MMI_AVRCP_KEY_LONGPRESS);
                        }

                        if(type_result == MMI_AVRCP_CR_REJECT)
                        {
                            g_mmi_avrcp_pressed_cmd_count -- ;
                        }
                    }
                    /* first time receive pressed cmd */
                    else
                    {
                        g_mmi_avrcp_last_pressed_cmd = command ;
                        g_mmi_avrcp_pressed_cmd_count = 1 ;
                        type_result = func_ptr( command, (srv_avrcp_key_events)MMI_AVRCP_KEY_DOWN);
                        StartTimer(BT_AVRCP_AUTO_RELEASE_TIMER, 2000, (FuncPtr)srv_avrcp_auto_release_cmd);
                    }
                }
                else if( g_mmi_avrcp_last_pressed_cmd == command )
                {
                    /*key released and matched key pressed command*/
                    /*reset previous pressed command to oxff*/
                    StopTimer(BT_AVRCP_AUTO_RELEASE_TIMER);
                    g_mmi_avrcp_last_pressed_cmd = 0xff ;
                    g_mmi_avrcp_pressed_cmd_count = 0 ;
                    type_result = func_ptr( command, (srv_avrcp_key_events)MMI_AVRCP_KEY_UP);
                }
                else
                {
                    /*key released but key pressed command not matched*/
                    type_result = MMI_AVRCP_CR_REJECT ;
                }
            }

        #ifndef __MMI_AVRCP_TEST__
            bt_avrcp_send_cmd_frame_ind_res(
                MOD_MMI,
                avrcp_chnl,                
                msg_p->seq_id,
                msg_p->profile_id,
                type_result,
                msg_p->subunit_type,
                msg_p->subunit_id,
                msg_p->data_len,
                msg_p->frame_data);
        #endif
            break;
        }

        case BT_AVRCP_OP_VENDOR:
        {
            type_result = MMI_AVRCP_CR_REJECT;

            msg_p->frame_data[1] = 0x00;
            msg_p->frame_data[2] = 0x19;
            msg_p->frame_data[3] = 0x58;

            msg_p->frame_data[5] = 0x00;    // packet type
            msg_p->frame_data[6] = 0x00;    // parameter length
            msg_p->frame_data[7] = 0x01;    // parameter length
            msg_p->frame_data[8] = 0x00;    // error code: invalid cmd
            msg_p->data_len = 9;            // opcode: 1 + company id: 3 + pdu id: 1 + packet type: 1 + len: 2 + error code: 1

            bt_avrcp_send_cmd_frame_ind_res(
                MOD_MMI,
                avrcp_chnl,
                msg_p->seq_id,
                msg_p->profile_id,
                type_result,
                msg_p->subunit_type,
                msg_p->subunit_id,
                msg_p->data_len,
                msg_p->frame_data);
            break;
        }

        default:
            // TODO: Error Trace Here.
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_util_check_cmd_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c_type              [IN]        
 *  subunit_type        [IN]        
 *  subunit_id          [IN]        
 *  data_len            [IN]        
 *  frame_data          [?]         
 * RETURNS
 *  
 *****************************************************************************/
U16 srv_avrcp_util_check_cmd_type(U8 c_type, U8 subunit_type, U8 subunit_id, U16 data_len, U8 *frame_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_len > 0)
    {
        /* check if pass through command */
        if ((subunit_type == BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH) &&
            (subunit_id == BT_AVRCP_SUBUNIT_ID_PASS_THROUGH) && (frame_data[0] == BT_AVRCP_OP_PASS_THROUGH))
        {
            return BT_AVRCP_OP_PASS_THROUGH;
        }

        /* check if unit info command */
        if ((subunit_type == BT_AVRCP_SUBUNIT_TYPE_UNIT_INFO) &&
            (subunit_id == BT_AVRCP_SUBUNIT_ID_UNIT_INFO) && (frame_data[0] == BT_AVRCP_OP_UNIT_INFO))
        {
            return BT_AVRCP_OP_UNIT_INFO;
        }

        /* check if unit info command */
        if ((subunit_type == BT_AVRCP_SUBUNIT_TYPE_SUBUNIT_INFO) &&
            (subunit_id == BT_AVRCP_SUBUNIT_ID_SUBUNIT_INFO) && (frame_data[0] == BT_AVRCP_OP_SUBUNIT_INFO))
        {
            return BT_AVRCP_OP_SUBUNIT_INFO;
        }

        /* check if unit info command */
        if ((subunit_type == BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH) &&
            (subunit_id == BT_AVRCP_SUBUNIT_ID_PASS_THROUGH) && (frame_data[0] == BT_AVRCP_OP_VENDOR))
        {
            return BT_AVRCP_OP_VENDOR;
        }        

    }

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  callback_func       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_set_cmd_hdlr(AVRCP_SRV_CMD_CALLBACK callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Already registered */
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_SET_CMD_HDLR);
    for (i = 0 ; i < BT_AVRCP_MAX_CALLBACK_NUM ; i++)
    {
        if (g_mmi_avrcp_cmd_func_ptr_list[i] == callback_func)
        {
            return;
        }
    }
    
    ASSERT(g_mmi_avrcp_cmd_func_ptr_count < BT_AVRCP_MAX_CALLBACK_NUM);

    g_mmi_avrcp_cmd_func_ptr_list[g_mmi_avrcp_cmd_func_ptr_count++] = callback_func;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_SET_CMD_HDLR1,g_mmi_avrcp_cmd_func_ptr_count);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_clear_cmd_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_clear_cmd_hdlr(AVRCP_SRV_CMD_CALLBACK callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    U8 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CLEAR_CMD_HDLR,g_mmi_avrcp_cmd_func_ptr_count);
    
    for (i = 0 ; i < BT_AVRCP_MAX_CALLBACK_NUM ; i++)
    {
        if (g_mmi_avrcp_cmd_func_ptr_list[i] == callback_func)
        {
            g_mmi_avrcp_cmd_func_ptr_list[i] = NULL;
            g_mmi_avrcp_cmd_func_ptr_count--;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CLEAR_CMD_HDLR1,g_mmi_avrcp_cmd_func_ptr_count);            
        }
    }

    if(g_mmi_avrcp_cmd_func_ptr_list[0] == NULL && g_mmi_avrcp_cmd_func_ptr_list[1] != NULL)
    {
       g_mmi_avrcp_cmd_func_ptr_list[0] = g_mmi_avrcp_cmd_func_ptr_list[1];
       g_mmi_avrcp_cmd_func_ptr_list[1] = NULL;
    }

    ASSERT(g_mmi_avrcp_cmd_func_ptr_count >= 0);

}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_auto_release_cmd
 * DESCRIPTION
 *  automatically pass a released command to application
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_auto_release_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    AVRCP_SRV_CMD_CALLBACK func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_AUTO_RELEASE1);

    if ((func_ptr = srv_avrcp_get_cmd_hdlr_func_ptr()) != NULL && g_mmi_avrcp_last_pressed_cmd != 0xff)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_AUTO_RELEASE2);
        func_ptr( g_mmi_avrcp_last_pressed_cmd, (srv_avrcp_key_events)MMI_AVRCP_KEY_UP);
        g_mmi_avrcp_last_pressed_cmd = 0xff ;
        g_mmi_avrcp_pressed_cmd_count = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_frm_sync_calllback
 * DESCRIPTION
 *  for framework to callback if keypad / touch is triggered.
 * PARAMETERS
 *  BOOL    [IN] is keypad / touch blocked by target
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_frm_sync_calllback(MMI_BOOL is_blocked)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    AVRCP_SRV_CMD_CALLBACK func_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_FRAMEWORK_BLOCK, is_blocked);

    g_mmi_avrcp_frm_blocked = is_blocked;
    /* if blocked                                            */
    /* 1. cancel previous key down cmd                       */
    /* 2. pass key up cmd for previous longpress, repeat cmd */
    if(is_blocked && (func_ptr = srv_avrcp_get_cmd_hdlr_func_ptr()) != NULL && g_mmi_avrcp_last_pressed_cmd != 0xff)
    {
        if(g_mmi_avrcp_pressed_cmd_count == 1)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_FRAMEWORK_SYNC1);
            func_ptr(g_mmi_avrcp_last_pressed_cmd, (srv_avrcp_key_events)MMI_AVRCP_KEY_CANCELED);
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_FRAMEWORK_SYNC2);
            func_ptr(g_mmi_avrcp_last_pressed_cmd, (srv_avrcp_key_events)MMI_AVRCP_KEY_UP);
        }
        StopTimer(BT_AVRCP_AUTO_RELEASE_TIMER);
        g_mmi_avrcp_last_pressed_cmd = 0xff;
        g_mmi_avrcp_pressed_cmd_count = 0;
    }
    
}

#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_actively_connect_tg_flag
 * DESCRIPTION
 *  get flag 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_avrcp_get_actively_connect_tg_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_GET_ACTIVELY_TG,g_mmi_avrcp_actively_connect_tg);

    return g_mmi_avrcp_actively_connect_tg;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_actively_connect_tg_flag
 * DESCRIPTION
 *  for em to set this flag
 * PARAMETERS
 *  MMI_BOOL    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_set_actively_connect_tg_flag(MMI_BOOL on_off)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_SET_ACTIVELY_TG,on_off);

    g_mmi_avrcp_actively_connect_tg = on_off ;
}

#endif

#endif /* (defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)) */

