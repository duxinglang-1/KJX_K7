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
 * vcui_dtcnt_wlan_gprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   These are the external api provided by data account - wlan ui.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/***************************************************************************** 
 *          CUI - DATA ACCOUNT WLAN
 *****************************************************************************/
#ifndef __VCUI_DTCNT_WLAN_GPROT_H__
#define __VCUI_DTCNT_WLAN_GPROT_H__

/*******************************************************************************
* Include Header File
*******************************************************************************/
#ifdef __TCPIP__
#include "mmi_features.h"
#ifdef __MMI_WLAN_FEATURES__

#ifdef __cplusplus
extern "C" {
#endif
/*******************************************************************************
* Enum Define
*******************************************************************************/

/* Wlan CUI event ID */
typedef enum
{
    /* If user selected an AP to connect network, send this event to APP's proc */
    EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_OK ,
    /* If user press cancel/backkey/homekey, send this event to APP's proc */
    EVT_ID_VCUI_WLAN_LIST_EVENT_RESULT_CANCEL,  
    /* If CUI's part screen closed abnormally not by user, send this event to APP's proc */
    EVT_ID_VCUI_WLAN_LIST_EVENT_CLOSE,           
    EVT_ID_VCUI_WLAN_LIST_EVENT_TOTAL
} VCUI_WLAN_AP_LIST_EVENT_ENUM;

typedef enum
{
    /* send connect request to dtcnt srv if any available network found */
    VCUI_WLAN_AUTO_CONN_ACTION_START,
    /* not to connect to any network after call api */
    /* Ex. no networks existed around */
    /* Ex. no networks belongs to OP and no saved networks existed around */
    VCUI_WLAN_AUTO_CONN_ACTION_CANCEL,
    VCUI_WLAN_AUTO_CONN_ACTION_TOTAL
} VCUI_WLAN_AUTO_CONN_ACTION_ENUM;

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
#endif

/*******************************************************************************
* Structure Define
*******************************************************************************/

/*******************************************************************************
* Structure Define
*******************************************************************************/
typedef struct	
{
    MMI_EVT_GROUP_PARAM_HEADER   /* screen group standard header */
    U32 reserved;     /* The reserved parameter */
} vcui_wlan_list_event_struct;

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
#endif

/*****************************************************************************
 * FUNCTION
 *  cui_wifi_ap_list_create
 * DESCRIPTION
 *  Create a wifi ap list CUI to use.
 * PARAMETERS
 *  parent_gid     [IN]    Parent's screen group ID
 *  user_data      [IN]    For future extension 
 * RETURNS
 *  mmi_id         Screen group ID of create CUI
 *   - Create CUI failed if return GRP_ID_INVALID 
 *****************************************************************************/
mmi_id vcui_wifi_ap_list_create(mmi_id parent_gid, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  cui_wifi_ap_list_run
 * DESCRIPTION
 *  Start to excute CUI, show ap list screen
 * PARAMETERS
 *  cui_gid     [IN]      Created CUI's group ID  
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_wifi_ap_list_run(mmi_id cui_gid);

/*****************************************************************************
 * FUNCTION
 *  cui_wifi_ap_list_close
 * DESCRIPTION
 *  Close created CUI to release memory and resources
 * PARAMETERS
 *  cui_gid     [IN]      Created CUI's group ID  
 * RETURNS
 *  void
 *****************************************************************************/
void vcui_wifi_ap_list_close(mmi_id cui_gid);

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  vcui_wlan_auto_conn_cb_func_ptr
 * DESCRIPTION
 *  Callback function after invoke auto connect api.
 * PARAMETERS
 *  VCUI_WLAN_AUTO_CONN_ACTION_ENUM :   [IN]    execute auto connect or not
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*vcui_wlan_auto_conn_cb_func_ptr) (VCUI_WLAN_AUTO_CONN_ACTION_ENUM action);

/*****************************************************************************
 * FUNCTION
 *  vcui_wlan_auto_conn_networks
 * DESCRIPTION
 *  Provide interface for CBM to trigger connection to default trust AP(customization) or
 *  trust APs in wlan service database
 *  Logic flow:
 *  1. scan for networks
 *  2. If scan result equals 0, post event ...
 *  3. Otherwise, 
 *      a. If found OP network and it's never been connect successfully before,
 *         connect to it automatically.
 *      b. Connect to saved AP according to priority.
 * PARAMETERS
 *  cb  :   [IN]    callback function for auto connect
 * RETURNS
 *  U32 :   scan job ID
 *****************************************************************************/
U32 vcui_wlan_auto_conn_networks(vcui_wlan_auto_conn_cb_func_ptr cb);

/*****************************************************************************
 * FUNCTION
 *  vapp_wlan_send_cmcc_deinit()
 * DESCRIPTION
 *  Provide interface for widget to logout the connecting default trust AP(customization) and
 *  send deinit request to dtcnt srv.
 *  Logic flow:
 *  1. when default trust AP is connecting,
 *  1) logout the AP,
 *  2) send deinit request to dtcnt srv.
 *
 *  2. when other AP is connecting,
 *  1) send deinit request to dtcnt srv
 *
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void vapp_wlan_send_cmcc_deinit();

#ifdef __cplusplus
}
#endif

#endif  // __MMI_WLAN_FEATURES__
#endif  // __TCP_IP__
#endif  // __VCUI_DTCNT_WLAN_GPROT_H__
