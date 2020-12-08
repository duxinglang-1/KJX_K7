/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_fm_radio_util.h
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  FM Radio utility header file
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_FM_RADIO_UTIL_SLIM_H__
#define __VAPP_FM_RADIO_UTIL_SLIM_H__

#include "MMI_features.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/
#if defined(__MMI_FM_RADIO_SLIM__)

// Test feature option
//#undef __MMI_BT_FM_VIA_SCO__
//#undef __MMI_FM_VIA_A2DP__
//#undef __MMI_AVRCP_SUPPORT__
//#undef __MMI_FM_RADIO_RECORD__

//#undef __MMI_NCENTER_SUPPORT__
//#undef __MMI_VUI_WIDGET_FM_RADIO__


#include "vfx_input_event.h"
#include "vcp_popup.h"

#ifdef __cplusplus
extern "C"
{
#endif
#include "mdi_audio.h"
#include "fmr_config_customize.h"

#if (defined(__MMI_BT_FM_VIA_SCO__) || defined(__MMI_FM_VIA_A2DP__))
#include "BtAudioSrvGprot.h"
#include "BthScoPathSrvGProt.h"
#endif

#ifdef __MMI_FM_VIA_A2DP__
#include "A2dpSrvGprot.h"
#endif

#ifdef __MMI_AVRCP_SUPPORT__
#include "AvrcpSrvGprot.h"
#endif

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

typedef enum
{
    VADP_FM_RADIO_POWER_OFF,
    VADP_FM_RADIO_POWER_ON,
    VADP_FM_RADIO_SEEKING,
    VADP_FM_RADIO_SCANING,
    VADP_FM_RADIO_INTERRUPT,
    VADP_FM_RADIO_STATE_COUNT
} vadp_fm_radio_state_enum;


#ifdef __MMI_FM_VIA_A2DP__
typedef enum 
{
    VADP_FM_RADIO_A2DP_DISCONNECTED,
    VADP_FM_RADIO_A2DP_CONNECTING,
    VADP_FM_RADIO_A2DP_CONNECTING_WHILE_PLAY,
    VADP_FM_RADIO_A2DP_CONNECTED
} vadp_fm_radio_a2dp_connect_state_enum;
#endif

typedef void (*vadp_fmr_proc_callback)(mmi_event_struct *evt, void *user_data);

typedef struct
{
    mdi_ext_callback handler;
    void* user_data;
} vadp_fm_radio_power_on_struct;

typedef struct
{
    mdi_bg_callback handler;
    void* user_data;
} vadp_fm_radio_background_struct;


typedef struct
{
    mdi_fmr_seek_cb_fct handler;
    void* user_data;
} vadp_fm_radio_seek_struct;


typedef struct
{
    vadp_fmr_proc_callback handler;
    void* user_data;
} vadp_fm_radio_proc_struct;

#ifdef __MMI_AVRCP_SUPPORT__
typedef VfxBool (*vadp_fmr_avrcp_cmd_callback)(VfxKeyEvent &event, VfxBool is_from_avrcp, void *user_data);

typedef struct
{
    vadp_fmr_avrcp_cmd_callback handler;
    void *user_data;
} vadp_fm_radio_avrcp_cmd_struct;
#endif


typedef struct 
{
    MMI_EVT_PARAM_HEADER
    VfxS32 popup_handle;
} vapp_fm_radio_cancel_popup_event_struct;

typedef struct  
{
    MMI_EVT_GROUP_PARAM_HEADER
    VfxBool is_shown;
} vapp_fm_radio_ncenter_update_evt_struct;

#define VADP_FM_RADIO_APP   0
#define VADP_FM_RADIO_NCENTER 1
#define VADP_FM_RADIO_TOTAL 2


/***************************************************************************** 
 * Function
 *****************************************************************************/

#ifdef __cplusplus
extern "C"
{
#endif
extern void* vadp_fm_radio_get_app_control(void);
extern const WCHAR* vapp_fm_radio_get_fav_name(VfxU16 freq);
extern VfxU8 vapp_fm_radio_get_fav_count(void);
extern void vapp_fm_radio_add_to_fav_list(VfxU16 freq, VfxWString name);
extern void vadp_fm_radio_write_cur_freq(void);
extern void vadp_fm_radio_set_cur_freq(U16 cur_freq);
extern U16 vadp_fm_radio_get_cur_freq(void);
extern void vadp_fm_radio_toggle_aud_path(void);
extern U8 vadp_fm_radio_get_aud_path(void);
extern void vadp_fm_radio_reset_aud_path(void);
extern mmi_ret vadp_fm_radio_init(mmi_event_struct *evt);
extern void vadp_fm_radio_app_power_off(void);
extern void vadp_fm_radio_power_on_callback(mdi_result result, void* user_data);
extern void vadp_fm_radio_power_on_with_path(U8 path, U8 app_id);
extern void vadp_fm_radio_scan(void);
extern void vadp_fm_radio_update_scan_freq(U8 total,VfxU16* signalBand);
extern void vadp_fm_radio_scan_callback(mdi_fmr_cb_reason_enum result, void* cb_data, void* user_data);
extern void vadp_fm_radio_seek_callback(mdi_fmr_cb_reason_enum result, U16 stop_freq, MMI_BOOL is_valid, void* user_data);
extern void vadp_fm_radio_seek(U16 start_freq, VfxBool forward);
extern void vadp_fm_radio_background_callback(mdi_result result, void* user_data);
extern void vadp_fm_radio_set_background_handler(void);
extern void vadp_fm_radio_clear_background_handler(void);
extern void vadp_fm_radio_register_general_callback(mdi_ext_callback handler, void *user_data, U8 app_id);
extern void vadp_fm_radio_deregister_general_callback(U8 app_id);
extern void vadp_fm_radio_register_background_callback(mdi_bg_callback handler, void *user_data, U8 app_id);
extern void vadp_fm_radio_deregister_background_callback(U8 app_id);
extern void vadp_fm_radio_register_seek_callback(mdi_fmr_seek_cb_fct handler, void *user_data, U8 app_id);
extern void vadp_fm_radio_deregister_seek_callback(U8 app_id);
extern void vadp_fm_radio_register_proc_callback(vadp_fmr_proc_callback handler, void *user_data, U8 app_id);
extern void vadp_fm_radio_deregister_proc_callback(U8 app_id);
extern void vadp_fm_radio_set_global_popup_could_close(VfxBool could_close);
extern void vadp_fm_radio_set_global_popup_handle(VfxU32 popup_handle);
extern VfxU32 vadp_fm_radio_get_global_popup_handle();
extern void vadp_fm_radio_close_global_popup();
extern mmi_ret vadp_fm_radio_cancel_global_popup(mmi_event_struct *evt);
extern vadp_fm_radio_state_enum vadp_fm_radio_query_state(void);

extern void vadp_fm_radio_update_state(vadp_fm_radio_state_enum state);
#if defined(__MMI_NCENTER_SUPPORT__)  
extern void vadp_fm_radio_update_ncenter();
#endif
extern void vadp_fm_radio_update_status_icon_bar();
extern mmi_ret vadp_fm_radio_evt_proc(mmi_event_struct *evt);
extern void vadp_fm_radio_power_off(void);


// Start playing FM Radio.
extern void vadp_fm_radio_start_playing(void);
// Stop playing FM Radio.
extern void vadp_fm_radio_stop_playing(void);
//Return whether fm radio is playing.
extern VfxBool vadp_fm_radio_is_playing(void);

#ifdef __MMI_FM_VIA_A2DP__
// A2dp connect state get accessor.
extern vadp_fm_radio_a2dp_connect_state_enum vadp_fm_radio_get_a2dp_connect_state(void);
// A2dp connect state set accessor.
extern void vadp_fm_radio_set_a2dp_connect_state(vadp_fm_radio_a2dp_connect_state_enum a2dp_connect_state);
// Set up a2dp connection.
extern void vadp_fm_radio_connect_a2dp(void);
// Close a2dp connection
extern void vadp_fm_radio_close_a2dp_connection(void);
// A2dp connect callback function.
extern void vadp_fm_radio_a2dp_connect_callback(
    S32 result  // [in] The result of connect a2dp. type: srv_a2dp_callback_event_enum
);
#endif // __MMI_FM_VIA_A2DP__

#ifdef __MMI_AVRCP_SUPPORT__
// Register AVRCP cmd callback function. Used by FM Radio component.
extern void vadp_fm_radio_register_avrcp_cmd_callback(
    vadp_fmr_avrcp_cmd_callback handler,    //  [in] The callback function, 
    void *user_data,                        //  [in] User data, usually is a VfxObjHandle (a object pointer).
    U8 app_id                               // [in] Component id, one of [App, Widget, Lock] 
);
// Deregister AVRCP cmd callback function. Used by FM Radio component.
extern void vadp_fm_radio_deregister_avrcp_cmd_callback(
    U8 app_id   // [in] Component id, one of [App, Widget, Lock] 
);
// AVRCP cmd callback function. Will be called when AVRCP cmd produce. And transfer the AVRCP cmd to key event
// RETURNS: The implement result of AVRCP cmd. one of 
//                [SRV_AVRCP_CR_ACCEPT, SRV_AVRCP_CR_REJECT, SRV_AVRCP_CR_NOT_IMPLEMENT]
extern U8 vadp_fm_radio_avrcp_cmd_callback(
    U8 command,                         // [in] AVRCP cmd
    srv_avrcp_key_events key_events     // [in] AVRCP key event type
);
// If AVRCP cmd don't process by components, then this api will process it.
extern VfxBool vadp_fm_radio_process_avrcp_cmd(
    VfxKeyEvent &event,     // [in] Key event transfered from AVRCP cmd
    VfxBool is_from_avrcp,  // [in] Indicate whether the key event is transfered from AVRCP cmd
    void *user_data         // [in] User data, no use in this api 
);
#endif // __MMI_AVRCP_SUPPORT__

#if (defined(__MMI_BT_FM_VIA_SCO__) || defined(__MMI_FM_VIA_A2DP__))
// Return whether fm is connecting bt headset
extern VfxBool vadp_fm_radio_is_connecting_bt_headset();
// Enable and try to play via bt headset.
extern void vadp_fm_radio_enable_play_via_bt_headset(void);
// Disable play via bt headset.
extern void vadp_fm_radio_disable_play_via_bt_headset(void);
// Listen to bt connection both SCO and A2DP.
// Only intrested in BTAUD_EV_STEREO_CONFIG_IND in FM Radio.
extern void vadp_fm_radio_listen_to_BT_connection(void);
// Callback and process function of BT audio event.
// Only intrested in BTAUD_EV_STEREO_CONFIG_IND in FM Radio.
// Return true if the event has been processed, otherwise return false.
extern S32 vadp_fm_radio_BT_aud_event_handler(BtAudEvent event, U32 arg, void *user_data);
// Toggle BT connection both SCO and A2DP.
extern void vadp_fm_radio_toggle_bt_aud_path();
#endif // (defined(__MMI_BT_FM_VIA_SCO__) || defined(__MMI_FM_VIA_A2DP__))


#ifdef __cplusplus
}
#endif

#endif

#endif /* __VAPP_FM_RADIO_UTIL_SLIM_H__ */
