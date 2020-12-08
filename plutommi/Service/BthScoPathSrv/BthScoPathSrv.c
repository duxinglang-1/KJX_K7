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
 *
 *
 * Project:
 * --------
 *  Cosmos
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"
#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
#include "mdi_video.h"
#include "mdi_bitstream.h"
#endif

#include "BthfSrvGprot.h"
#include "BthScoPathSrvGprot.h"

#include "mmi_rp_srv_btsco_def.h"

#include "gpiosrvGprot.h"
#include "ProfilesSrvGprot.h"

//#include "BTMMIA2DP.h"
#include "A2dpSrvGprot.h"

#include "MMIDataType.h"
#include "BtcmSrvGprot.h"
#include "med_struct.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "kal_release.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/
#define BT_SCO_CONNECT_TIMEOUT_DURATION 4000 /* Timeout to disconnect duration */
#define BT_SCO_RECONNECT_TIMER_DURATION 3000 /* Reconnect duration */

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#ifdef __MMI_BT_AUDIO_SUPPORT__
static U8 g_mmi_bt_sco_reset_pending;
static void (*g_mmi_bt_sco_reset_callback)(void);

static MMI_BOOL g_mmi_bt_sco_is_in_call = MMI_FALSE;
static U8 g_mmi_bt_sco_disalbe_sco = 0; /* Disable SCO connection */
static MMI_BOOL g_mmi_bt_sco_inquerying = MMI_FALSE; /* No SCO connection when inquerying */
#ifdef __MMI_HFP_SUPPORT__
static MMI_BOOL g_mmi_bt_sco_always_use_in_call = MMI_FALSE;
static void (*mmi_bt_sco_connect_sco_app_callback) (void) = NULL;
static MMI_BOOL g_mmi_bt_sco_app_in_use = MMI_FALSE;
#endif /* __MMI_HFP_SUPPORT__ */ 
#endif /* __MMI_BT_AUDIO_SUPPORT__ */ 

#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
static MMI_BOOL g_mmi_bt_sco_connect_timeout = MMI_TRUE; /* Timeout mechanism */
static void (*g_mmi_bt_sco_inquery_callback) (void) = NULL;
#endif /* #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__) */

/***************************************************************************** 
 * Function
 *****************************************************************************/
//#ifdef __MMI_BT_AUDIO_SUPPORT__
//extern void mmi_bt_a2dp_deactivate_req(void);
//#endif
extern void srv_bt_a2dp_deactivate_req(void);
extern MMI_BOOL mdi_mtv_is_playing(void);
#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
static void _srv_btsco_connect_timeout(void);
static MMI_BOOL _srv_btsco_is_sco_app_idle(void);
#endif


#ifdef __MMI_BT_AUDIO_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_btsco_is_profile_connect_allowed
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_btsco_is_profile_connect_allowed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL connect_sco = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Not support bluetooth mode, use wired earphone as default output path */
    if(SRV_PROF_RET_PROFILE_NOT_SUPPORTED == srv_prof_is_profile_activated(SRV_PROF_BLUETOOTH_MODE))
    {
        /* Allow to connect in call, earphone plug-in, or FM playing */
        if(g_mmi_bt_sco_is_in_call || !srv_earphone_is_plug_in() || mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO))
        {
            connect_sco = MMI_TRUE;
        }
    }
    /* Bluetooth mode supported, try to connect SCO */
    else if(SRV_PROF_RET_PROFILE_ACTIVATED == srv_prof_is_profile_activated(SRV_PROF_BLUETOOTH_MODE))
    {
        connect_sco = MMI_TRUE;
    }

    return connect_sco;
}


/*****************************************************************************
 * FUNCTION
 *  _srv_btsco_is_hfp_connected
 * DESCRIPTION
 *  to check if bt hfp is connected
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL _srv_btsco_is_hfp_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bt_connect = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    bt_connect = (MMI_BOOL) (srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION));
#endif
    return bt_connect;
}


/*****************************************************************************
 * FUNCTION
 *  _srv_btsco_get_hfp_connection_id
 * DESCRIPTION
 *  To get HFP connection ID
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
S32 _srv_btsco_get_hfp_connection_id(void)
{
#ifdef __MMI_HFP_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 dev_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (srv_bthf_list_device(&dev_id, 1))
    {
        bthf_dev_info_struct info;
        srv_bthf_get_device_info(dev_id, &info);
        
        return info.conn_id; // this is connection ID used before
    }
    else
#endif /*__MMI_HFP_SUPPORT__*/
    {
         // no HFP audio device connected
         return 0;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_is_sco_open
 * DESCRIPTION
 *  to check if bt is connected
 * PARAMETERS
 *  connect_type        [IN]        
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_btsco_is_sco_open(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bt_connect = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bt_connect = (MMI_BOOL) mdi_audio_bt_is_stream_open(BT_HFP);
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_IS_SCO_OPEN, 0, bt_connect);

    return bt_connect;
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_is_sco_connect_allowed
 * DESCRIPTION
 *  check if bt sco connect request is allowed
 * PARAMETERS
 *  void
 * RETURNS
 *  TURE if allowed
 *****************************************************************************/
MMI_BOOL srv_btsco_is_sco_connect_allowed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* Can not connect SCO while FM/mobile TV is recording */
    if(!mdi_audio_is_resource_available(MDI_AUDIO_PLAY_VIA_SCO, NULL))
    {
        return MMI_FALSE;
    }

    return (MMI_BOOL)(!g_mmi_bt_sco_disalbe_sco && !g_mmi_bt_sco_inquerying);
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_is_sco_in_call
 * DESCRIPTION
 *  check is it allowed to popup
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_btsco_is_sco_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_bt_sco_is_in_call;
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_connect_sco_req
 * DESCRIPTION
 *  Connect sco link before running application, use callback to make sure sco connected
 * PARAMETERS
 *  callback        [IN]
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_btsco_connect_sco_req(void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL connect = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_CONNECT_SCO, g_mmi_bt_sco_disalbe_sco, g_mmi_bt_sco_inquerying);

    if(srv_btsco_is_profile_connect_allowed())
    {
    	if(srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION))
    	{
            connect = srv_btsco_open_stream_req();
    		if( connect )
    		{
    			mmi_bt_sco_connect_sco_app_callback = callback;
    		}
        #ifdef __MMI_BT_AUDIO_VIA_SCO__
            /* Already Connected, start a timeout timer */
            else if(g_mmi_bt_sco_connect_timeout && srv_btsco_is_sco_open())
            {
                StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, _srv_btsco_connect_timeout);
            }
        #endif /* __MMI_BT_AUDIO_VIA_SCO__ */
    	}

    	g_mmi_bt_sco_app_in_use = MMI_TRUE;
    }
#endif /* __MMI_HFP_SUPPORT__ */ 
    return connect;
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_disconnect_sco_req
 * DESCRIPTION
 *  disconnect sco link
 * PARAMETERS
 *  void
 * RETURNS
 * BOOL
 *****************************************************************************/
MMI_BOOL srv_btsco_disconnect_sco_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL disconnect = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_HFP_SUPPORT__
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_DISCONNECT_SCO,g_mmi_bt_sco_is_in_call,g_mmi_bt_sco_always_use_in_call,((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) && srv_bt_cm_is_audio_path_to_headset()));

    if (!g_mmi_bt_sco_is_in_call ||
        g_mmi_bt_sco_disalbe_sco ||
        !(g_mmi_bt_sco_always_use_in_call ||
        ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) && srv_bt_cm_is_audio_path_to_headset())))
    {
        disconnect = (MMI_BOOL)mdi_audio_bt_is_stream_open(BT_HFP);
        mdi_audio_bt_close_stream(BT_HFP);
        mmi_bt_sco_connect_sco_app_callback = NULL;
    }
    g_mmi_bt_sco_app_in_use = MMI_FALSE;
#endif /* __MMI_HFP_SUPPORT__ */ 
    return disconnect;
}

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_deactivate_cnf_hdlr
 * DESCRIPTION
 *  the cnf handler for bt a2dp deactivate req
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_deactivate_cnf_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_mmi_bt_sco_reset_pending != 0)
    {
        g_mmi_bt_sco_reset_pending &= 0x0D;

        if ((g_mmi_bt_sco_reset_pending == 0) && (g_mmi_bt_sco_reset_callback != NULL))
        {
            g_mmi_bt_sco_reset_callback();
            g_mmi_bt_sco_reset_callback = NULL;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_reset
 * DESCRIPTION
 *  to reset bt profile
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_reset(void (*painc_cb)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_RESET,g_mmi_bt_sco_reset_pending);

#if defined(__MMI_A2DP_SUPPORT__)
    //mmi_a2dp_bt_power_off_callback(TRUE);
    //mmi_bt_a2dp_deactivate_req();
    srv_bt_a2dp_deactivate_req();
//    if (mmi_bt_a2dp_query_state() != MMI_A2DP_STATE_IDLE)
    if (srv_bt_a2dp_query_state() != SRV_A2DP_STATE_IDLE)
    {
        g_mmi_bt_sco_reset_pending |= 2;
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_RESET,g_mmi_bt_sco_reset_pending);
    }
#endif

#ifdef __MMI_HFP_SUPPORT__
    if (srv_btsco_is_sco_open())
    {
        g_mmi_bt_sco_reset_pending |= 1;
        srv_btsco_close_stream_req();
    }
    mmi_bt_sco_connect_sco_app_callback = NULL;
#endif /* __MMI_HFP_SUPPORT__ */ 

    if (g_mmi_bt_sco_reset_pending == 0)
    {
        if(painc_cb != NULL)
        {
            painc_cb();
        }
        g_mmi_bt_sco_reset_callback = NULL;
    }
    else
    {
        g_mmi_bt_sco_reset_callback = painc_cb;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_open_stream_callback
 * DESCRIPTION
 *  a callback function for open bt stream cnf
 * PARAMETERS
 *  profile     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_open_stream_callback(U8 profile, mdi_result result, U16 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_OPEN_STREAM_CALLBACK, profile, result);
	#ifdef __BT_DIALER_SUPPORT__
	if(srv_bt_cm_get_btdialor_mode() == MMI_TRUE)
	{
		mdi_audio_set_sco_mode(MDI_AUD_BT_SCO_MODE_BT_DIALER);
	}
	#endif /*__BT_DIALER_SUPPORT__*/
    switch (profile)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case BT_HFP:
            if (result == MDI_AUDIO_SUCCESS)
            {
            /* add a condition check for SCO, if it's not allowed, then disconnect it */
        #if !defined(__MMI_BT_AUDIO_VIA_SCO__)
            #ifdef __MMI_BT_FM_VIA_SCO__
                if( !g_mmi_bt_sco_app_in_use && !g_mmi_bt_sco_is_in_call && !mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO) )
            #else
                if( !g_mmi_bt_sco_app_in_use && !g_mmi_bt_sco_is_in_call)
            #endif            
                {
                    srv_btsco_close_stream_req();
                    return;
                }
        #endif /* #if !defined(__MMI_BT_AUDIO_VIA_SCO__) */
            
                if (g_mmi_bt_sco_is_in_call)
                {
                    g_mmi_bt_sco_always_use_in_call = MMI_TRUE;
                }

                /* Call back BT CM to inficate state */
				srv_bt_cm_sco_connect_ind_hdler(_srv_btsco_get_hfp_connection_id());

        #ifdef __MMI_BT_AUDIO_VIA_SCO__
     	#ifdef __BT_DIALER_SUPPORT__
			if(srv_bt_cm_get_btdialor_mode() == MMI_FALSE)
			{
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_START_SCO_TIMER, g_mmi_bt_sco_connect_timeout);
                if(g_mmi_bt_sco_connect_timeout)
                {
                    StopTimer(BT_SCO_CONNECT_TIMER);
                    StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, _srv_btsco_connect_timeout);
                }
			}
			#else
                MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_START_SCO_TIMER, g_mmi_bt_sco_connect_timeout);
                if(g_mmi_bt_sco_connect_timeout)
                {
                    StopTimer(BT_SCO_CONNECT_TIMER);
                    StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, _srv_btsco_connect_timeout);
                }
			#endif
        #endif /* #ifdef __MMI_BT_AUDIO_VIA_SCO__ */
            }
            else
            {
                srv_bt_cm_sco_connect_cnf_hdler(error_cause, _srv_btsco_get_hfp_connection_id());
            }

            if (mmi_bt_sco_connect_sco_app_callback != NULL)
            {
                mmi_bt_sco_connect_sco_app_callback();
                mmi_bt_sco_connect_sco_app_callback = NULL;
            }
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_close_stream_callback
 * DESCRIPTION
 *  a callback function for close bt stream cnf
 * PARAMETERS
 *  profile     [IN]        
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_close_stream_callback(U8 profile, mdi_result result, U16 error_cause)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
    void (*inquery_callback) (void);
#endif    
    mmi_evt_srv_btsco_close_ind_struct evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_CLOSE_STREAM_CALLBACK, profile, result);

    switch (profile)
    {
    #ifdef __MMI_HFP_SUPPORT__
        case BT_HFP:
            /* Check if panic while disconnecting */
            if (g_mmi_bt_sco_reset_pending != 0)
            {
                g_mmi_bt_sco_reset_pending &= 0x0E;
                if ((g_mmi_bt_sco_reset_pending == 0) && (g_mmi_bt_sco_reset_callback != NULL))
                {
                    g_mmi_bt_sco_reset_callback();
                    g_mmi_bt_sco_reset_callback = NULL;                    
                }
            }

            /* Inform BT CM about disconnect */
    		srv_bt_cm_sco_disconnect_ind_hdler(_srv_btsco_get_hfp_connection_id());

    #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
            /* Callback inquery function because the SCO disconnect is called by BT inquery */
            if(g_mmi_bt_sco_inquery_callback)
            {
                inquery_callback = g_mmi_bt_sco_inquery_callback;
                g_mmi_bt_sco_inquery_callback = NULL;                
                inquery_callback();
            }
    #endif

            /* Event to notify app SCO close */
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BTSCO_CLOSE_IND);
            evt.result = result;
            evt.error_cause = error_cause;
            MMI_FRM_CB_EMIT_EVENT(&evt);
 
            break;
    #endif /* __MMI_HFP_SUPPORT__ */ 
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_btsco_open_stream_req
 * DESCRIPTION
 *  bt connect request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_btsco_open_stream_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 connect_id;
    MMI_BOOL is_connect = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_OPEN_STREAM_REQ, 0, g_mmi_bt_sco_disalbe_sco, g_mmi_bt_sco_inquerying);

#ifdef __MMI_HFP_SUPPORT__
    if(srv_btsco_is_sco_connect_allowed() && srv_btsco_is_profile_connect_allowed())
    {
        connect_id = _srv_btsco_get_hfp_connection_id();
        ASSERT(connect_id >= 0);
        is_connect = (MMI_BOOL)mdi_audio_bt_open_stream(BT_HFP, (U16) connect_id);
    }
#endif /* __MMI_HFP_SUPPORT__ */ 
    return is_connect;
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_close_stream_req
 * DESCRIPTION
 *  bt disconnect request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_close_stream_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_CLOSE_STREAM_REQ, 0);

#ifdef __MMI_HFP_SUPPORT__
    mdi_audio_bt_close_stream(BT_HFP);

    if (mmi_bt_sco_connect_sco_app_callback != NULL)
    {
        mmi_bt_sco_connect_sco_app_callback();
        mmi_bt_sco_connect_sco_app_callback = NULL;
    }
#endif /* __MMI_HFP_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_call_start_callback
 * DESCRIPTION
 *  the call back function for call start
 * PARAMETERS
 *  void
 *  BOOL(?)     [IN]        Turn on
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_call_start_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL speech_on = mdi_audio_is_speech_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_CALL_START_CALLBACK, g_mmi_bt_sco_is_in_call, speech_on);

    if (!g_mmi_bt_sco_is_in_call)
    {
    #ifdef __MMI_HFP_SUPPORT__
        if (_srv_btsco_is_hfp_connected())
        {
        #if defined(__MMI_A2DP_SUPPORT__)
            srv_a2dp_close(MMI_TRUE);
        #endif
        #ifdef __BT_SPK_VOL_CONTROL__
            srv_speech_set_mode_volume();
        #endif
            if (g_mmi_bt_sco_always_use_in_call ||
                ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) && srv_bt_cm_is_audio_path_to_headset()))
            {
                srv_btsco_open_stream_req();
            #ifdef __MMI_BT_AUDIO_VIA_SCO__
                /* Stop SCO timeout timer during call */
                StopTimer(BT_SCO_CONNECT_TIMER);
            #endif /* #ifdef __MMI_BT_AUDIO_VIA_SCO__ */
            }
        }
    #endif /* __MMI_HFP_SUPPORT__ */  

        g_mmi_bt_sco_is_in_call = MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_call_end_callback
 * DESCRIPTION
 *  the call back function for call end
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_call_end_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL speech_on = mdi_audio_is_speech_mode();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_CALL_END_CALLBACK, g_mmi_bt_sco_is_in_call, speech_on);

    if (g_mmi_bt_sco_is_in_call)
    {
    #ifdef __MMI_HFP_SUPPORT__
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #if defined(__MMI_BT_AUDIO_VIA_SCO__) /* && defined(__MMI_BT_SCO_KEY_TONE__) */
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
                #else
/* under construction !*/
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        /* Always disconnect SCO afer call end, FM/audio needs to reconnect it to avoid IOT problem. (MAUI_03111389) */
        {
            srv_btsco_close_stream_req();
        }       

        g_mmi_bt_sco_always_use_in_call = MMI_FALSE;
    #endif /* __MMI_HFP_SUPPORT__ */ 

        g_mmi_bt_sco_is_in_call = MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_hfp_connect_callback
 * DESCRIPTION
 *  the call back function for HFP connect indication
 * PARAMETERS
 *  callback_type       [IN] : HFP callback type (ind, rsp)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_hfp_connect_callback(U8 callback_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,  SRV_BTSCO_HFP_CONNECT_CALLBACK, 0, callback_type, 0);

#ifdef __MMI_HFP_SUPPORT__
    /* For HFP connected case, if earphone is plugged, do not connect SCO */
    if(srv_earphone_is_plug_in() && !mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO))
    {
        MMI_TRACE(MMI_MEDIA_TRC_G2_APP,  SRV_BTSCO_HFP_CONNECT_CALLBACK, 0, callback_type, 1);
        return;
    }

    srv_btsco_switch_profile_path(MMI_TRUE);
#endif /* __MMI_HFP_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_hfp_disconnect_callback
 * DESCRIPTION
 *  the call back function for HFP connect indication
 * PARAMETERS
 *  callback_type       [IN] : HFP callback type (ind, rsp)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_hfp_disconnect_callback(U8 callback_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,  SRV_BTSCO_HFP_DISCONNECT_CALLBACK, 0, callback_type, 0);

#ifdef __MMI_HFP_SUPPORT__
    if (callback_type == SRV_BT_SCO_IND || callback_type == SRV_BT_SCO_RSP)
    {
        srv_btsco_close_stream_req();
    }
    /* Change audio path back to phone before disconnect HFP ACL link */
    else if (callback_type == SRV_BT_SCO_REQ)
    {
        mdi_audio_bt_hfp_turn_off();
    }

    /* Resume audio background play if HFP ACL disconnected while BT inquirying */
    if(g_mmi_bt_sco_inquerying)
    {
        mdi_audio_resume_background_play();
    }

#endif /* __MMI_HFP_SUPPORT__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_switch_profile_path
 * DESCRIPTION
 *
 * PARAMETERS
 *  turn_on_sco              [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_switch_profile_path(MMI_BOOL turn_on_sco)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,  SRV_BTSCO_SWITCH_PROFILE_PATH, turn_on_sco);

    if(turn_on_sco)
    {
    #ifdef __MMI_HFP_SUPPORT__
        if (_srv_btsco_is_hfp_connected())
        {
    #ifdef __MMI_BT_AUDIO_VIA_SCO__

            /* When HFP is connected, suspend audio background play when inquirying */
            if(g_mmi_bt_sco_inquerying && ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION) ) && ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) && srv_bt_cm_is_audio_path_to_headset())))
            {
                mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_SCO_INQ);
            }

            /* Connect SCO according to HFP audio path setting */
            if (srv_bt_cm_is_audio_path_to_headset() && (g_mmi_bt_sco_is_in_call || !_srv_btsco_is_sco_app_idle()))
    #else /*__MMI_BT_AUDIO_VIA_SCO__*/
        #ifdef __MMI_BT_FM_VIA_SCO__
            /* Need to check FM radio if FM via SCO on  */
            if ((g_mmi_bt_sco_is_in_call || mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO)) &&
                (g_mmi_bt_sco_always_use_in_call || srv_bt_cm_is_audio_path_to_headset()))
        #else
            if (g_mmi_bt_sco_is_in_call && (g_mmi_bt_sco_always_use_in_call || srv_bt_cm_is_audio_path_to_headset()))
        #endif
    #endif /*__MMI_BT_AUDIO_VIA_SCO__*/
            {
                srv_btsco_open_stream_req();
            }
        }
    #endif /* __MMI_HFP_SUPPORT__ */ 
    }
    else
    {
        if(!mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO))
        {
            srv_btsco_close_stream_req();
        }

    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        /* If output path not from SCO, can resume background play */
        if(g_mmi_bt_sco_inquerying)
        {
            mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_SCO_INQ); 
        }
    #endif /*__MMI_BT_AUDIO_VIA_SCO__*/
    }
}


#if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__)
/*****************************************************************************
 * FUNCTION
 *  _srv_btsco_is_sco_app_idle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL _srv_btsco_is_sco_app_idle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if( !mdi_audio_is_playing(MDI_AUDIO_PLAY_ANY)
        && !mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO)
        && !mdi_audio_is_recording()
    #if defined(__MMI_VIDEO_PLAY_SUPPORT__)
        && !mdi_video_is_playing()
    #endif
    #if defined(__MMI_VIDEO_RECORDER__) || defined(__MMI_CAMCORDER__)
        && !mdi_video_is_recording()
    #endif
    #if defined(BGSND_ENABLE)
        && mdi_audio_snd_is_idle()
    #endif
    #if defined(__MMI_ATV_SUPPORT__) || defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
        && (mdi_mtv_is_playing()==MMI_FALSE)
    #endif
    #if defined(__BITSTREAM_API_SUPPORT__)
        && (mdi_bitstream_audio_get_open_handle_count() == 0)
    #endif
        )
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_set_always_on
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_set_always_on(MMI_BOOL is_always_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_SET_ALWAYS_ON, is_always_on);

    if(is_always_on)
    {
        StopTimer(BT_SCO_CONNECT_TIMER);
        g_mmi_bt_sco_connect_timeout = MMI_FALSE;
    }
    else
    {
        g_mmi_bt_sco_connect_timeout = MMI_TRUE;

        if(srv_btsco_is_sco_open())
        {
            StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, _srv_btsco_connect_timeout);
        }    
    }
}


/*****************************************************************************
 * FUNCTION
 *  _srv_btsco_enable_sco_connect_delay_timer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _srv_btsco_enable_sco_connect_delay_timer_callback(void)
{
    /* Press key or play audio in call will not connect SCO,
    *   call setup may leave the voice in phone */
    if(!g_mmi_bt_sco_is_in_call && ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) && srv_bt_cm_is_audio_path_to_headset()))
    {
        srv_btsco_connect_sco_req(NULL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_disable_sco_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_disable_sco_connection(U8 type_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_DISABLE_SCO_CONNECTION, g_mmi_bt_sco_disalbe_sco, type_id);
    
    StopTimer(BT_SCO_CONNECT_TIMER);
    StopTimer(BT_SCO_ENABLE_CONNECT_DELAY_TIMER);
    g_mmi_bt_sco_disalbe_sco |= type_id;

    srv_btsco_disconnect_sco_req();
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_enable_sco_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_enable_sco_connection(U8 type_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_ENABLE_SCO_CONNECTION, g_mmi_bt_sco_disalbe_sco, type_id);

    g_mmi_bt_sco_disalbe_sco &= ~type_id;

    if(!g_mmi_bt_sco_disalbe_sco)
    {
        /* Connect SCO if the audio path is "forward to BT", or the application is runnung */
        if(((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) && srv_bt_cm_is_audio_path_to_headset()) && !_srv_btsco_is_sco_app_idle())
        {
            StartTimer(BT_SCO_ENABLE_CONNECT_DELAY_TIMER, BT_SCO_RECONNECT_TIMER_DURATION, _srv_btsco_enable_sco_connect_delay_timer_callback);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _srv_btsco_connect_timeout
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _srv_btsco_connect_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_CONNECT_TIMEOUT, srv_btsco_is_sco_open(), g_mmi_bt_sco_is_in_call);
    
    if(srv_btsco_is_sco_open())
    {
        /* If audio/video is not playing or not in call */
        if(!g_mmi_bt_sco_is_in_call && _srv_btsco_is_sco_app_idle())
        {
            srv_btsco_disconnect_sco_req();
        }
        /* still using audio resource, disconnect later */
        else if(g_mmi_bt_sco_connect_timeout && !g_mmi_bt_sco_is_in_call)
        {
            StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, _srv_btsco_connect_timeout);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_reset_connection_timer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_reset_connection_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    StopTimer(BT_SCO_CONNECT_TIMER);
    StartTimer(BT_SCO_CONNECT_TIMER, BT_SCO_CONNECT_TIMEOUT_DURATION, _srv_btsco_connect_timeout);
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_inquiry_start_callback
 * DESCRIPTION
 *  Callback function for BT inquery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_btsco_inquiry_result_enum srv_btsco_inquiry_start_callback(void (*callback) (void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 sco_status;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sco_status = mdi_audio_bt_get_stream_status(BT_HFP);

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_INQUERY_START_CALLBACK, sco_status);

    g_mmi_bt_sco_inquery_callback = NULL;
    g_mmi_bt_sco_inquerying = MMI_TRUE;

    /* If not turn on FM via SCO, no need to turn suspend FM radio background play */
#if !defined(__MMI_BT_FM_VIA_SCO__)
    if(mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO))
    {
        return SRV_BT_SCO_INQ_SCO_DISCONNECTED;
    }
#endif

    /* If wire earphone is plugged, and not playing from FM radio, no need to disconnect SCO */
    if(srv_earphone_is_plug_in() && !mdi_audio_is_playing(MDI_AUDIO_PLAY_FM_RADIO) && !srv_btsco_is_sco_in_call())
    {
        return SRV_BT_SCO_INQ_SCO_DISCONNECTED;
    }

    /* When HFP is connected, suspend audio background play */
    if((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION) ) && ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) && srv_bt_cm_is_audio_path_to_headset()))
    {
        mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_SCO_INQ);
        
        switch(sco_status)
        {
            case MDI_AUDIO_BT_STATE_IDLE:
                return SRV_BT_SCO_INQ_SCO_DISCONNECTED;
                
            case MDI_AUDIO_BT_STATE_WAIT_CLOSE:
                g_mmi_bt_sco_inquery_callback = callback;
                break;
                
            case MDI_AUDIO_BT_STATE_OPEN:
            case MDI_AUDIO_BT_STATE_WAIT_OPEN:
                if(g_mmi_bt_sco_is_in_call)
                {
                    g_mmi_bt_sco_inquerying = MMI_FALSE;

                    /* May let caller always call stop inquiry function to resume background play*/
                    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_SCO_INQ); 
                    return SRV_BT_SCO_INQ_SCO_CONNECTED_IN_CALL;
                }

                StopTimer(BT_SCO_CONNECT_TIMER);
                g_mmi_bt_sco_inquery_callback = callback;    
                srv_btsco_disconnect_sco_req();
                break;

            default:
                ASSERT(0);
                break;
        }
    }
    else
    {
        return SRV_BT_SCO_INQ_SCO_DISCONNECTED;
    }

    return SRV_BT_SCO_INQ_SCO_CONNECTED_DISCONNECTABLE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_inquiry_stop_callback
 * DESCRIPTION
 *  Callback function for BT inquery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_btsco_inquiry_stop_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_INQUERY_STOP_CALLBACK);

    g_mmi_bt_sco_inquery_callback = NULL;

    /* Connect SCO after background play resume */
    g_mmi_bt_sco_inquerying = MMI_FALSE;

    /* If HFP connect during inquiry and the audio is playing, then connect SCO */
    if((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION) ) &&
        ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) && srv_bt_cm_is_audio_path_to_headset())&&
        !_srv_btsco_is_sco_app_idle())
    {
        /* not connect right away because it is not desire by the driver */
        StartTimer(BT_SCO_ENABLE_CONNECT_DELAY_TIMER, BT_SCO_RECONNECT_TIMER_DURATION, _srv_btsco_enable_sco_connect_delay_timer_callback);    
    }

    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_SCO_INQ); 

}


/*****************************************************************************
 * FUNCTION
 *  srv_btsco_connect_audio_via_sco
 * DESCRIPTION
 *  connect sco link
 * PARAMETERS
 *  void
 * RETURNS
 * void
 *****************************************************************************/
void srv_btsco_connect_audio_via_sco(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, SRV_BTSCO_CONNECT_AUDIO_VIA_SCO, g_mmi_bt_sco_is_in_call);

    /* Press key or play audio in call will not connect SCO,
    *   call setup may leave the voice in phone */
    if(!g_mmi_bt_sco_is_in_call && ((srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)) && srv_bt_cm_is_audio_path_to_headset()))
    {
        srv_btsco_connect_sco_req(NULL);
    }
}

#endif /* #if defined(__MMI_BT_AUDIO_VIA_SCO__) || defined(__MMI_BT_FM_VIA_SCO__) */

#endif /* __MMI_BT_AUDIO_SUPPORT__ */ 

