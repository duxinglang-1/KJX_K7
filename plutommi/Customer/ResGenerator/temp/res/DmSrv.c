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
 *  DmSrv.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  DM service resource.
 *
 * Author:
 * -------
 *   Yixiong Zhao (mtk80274)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 02 16 2012 yixiong.zhao
 * [MAUI_03131496] Move timer id to app res files
 * .
 *
 * 02 07 2012 yixiong.zhao
 * [MAUI_03125918] [DM] Fota Cosmos implement
 * .
 *
 * 12 20 2011 yixiong.zhao
 * [MAUI_03092807] [Cosmos][DM] SIM hotswap/recovery
 * .
 *
 * 12 13 2011 yixiong.zhao
 * [MAUI_03097129] [DM][Lawmo] App/Srv split and cosmos implement
 * .
 *
 * 11 10 2011 yan.liang
 * [MAUI_03077746] [MMI FRM]Fix callback manager spelling mistake
 * <saved by Perforce>
 *
 * 10 12 2011 yixiong.zhao
 * [MAUI_03036813] SIM Recovery Enhancement check-in
 * .
 *
 * 09 27 2011 yixiong.zhao
 * [MAUI_03036813] SIM Recovery Enhancement check-in
 * .
 *
 * 06 12 2011 yixiong.zhao
 * [MAUI_02954526] [DM] App/Srv split check in
 * .
 *
 * 06 02 2011 yixiong.zhao
 * [MAUI_02954526] [DM] App/Srv split check in
 * .
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#ifdef SYNCML_DM_SUPPORT
<APP id="SRV_DM">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_DMUI_MAIN"/>
    <STRING id="STR_ID_DMUI_SERVERID"/>
    <STRING id="STR_ID_DMUI_SERVER_PASSWORD"/>
    <STRING id="STR_ID_DMUI_SERVER_ADDRESS"/>
    <STRING id="STR_ID_DMUI_USER_PASSWORD"/>
    <STRING id="STR_ID_DMUI_AUTHTYPE"/>
    <STRING id="STR_ID_DMUI_AUTHTYPE_BASIC"/>
    <STRING id="STR_ID_DMUI_AUTHTYPE_MD5"/>
    <STRING id="STR_ID_DMUI_AUTHTYPE_HMAC"/>
    <STRING id="STR_ID_DMUI_INFO_INVALID_SERVER_ADDRESS"/>
    <STRING id="STR_ID_DMUI_INFO_SERVERID_EMPTY"/>
    <STRING id="STR_ID_DMUI_INFO_SERVERID_EXIST"/>
    <STRING id="STR_ID_DMUI_INFO_SERVERID_INVALID"/>
    <STRING id="STR_ID_DMUI_NOTIF_ENTER_PIN"/>
    <STRING id="STR_ID_DMUI_NOTIF_DOWNLOAD_CAPTION"/>
    <STRING id="STR_ID_DMUI_NOTIF_DOWNLOAD_TITLE"/>
    <STRING id="STR_ID_DMUI_NOTIF_DOWNLOAD_INFO"/>
    <STRING id="STR_ID_DMUI_NOTIF_DOWNLOAD_RESUME"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_CAPTION"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_TITLE"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_INFO"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_REBOOT"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_DEFER"/>
    <STRING id="STR_ID_DMUI_UPDATE_DEFER_INFO"/>
    <STRING id="STR_ID_DMUI_UPDATE_DEFER_HOUR_LATER"/>
    <STRING id="STR_ID_DMUI_UPDATE_DEFER_HOURS_LATER"/>
    <STRING id="STR_ID_DM_FOTA_UPDATE_DEFER_TITLE"/>
    <STRING id="STR_ID_DMUI_UPDATE_SUCCESS"/>
    <STRING id="STR_ID_DMUI_UPDATE_FAILURE"/>
    <STRING id="STR_ID_DMUI_NOTIF_NAME"/>
    <STRING id="STR_ID_DMUI_NOTIF_TYPE"/>
    <STRING id="STR_ID_DMUI_NOTIF_SIZE"/>
    <STRING id="STR_ID_DMUI_NOTIF_DESCRIPTION"/>
    <STRING id="STR_ID_DMUI_TIMEOUT_POPUP"/>
    <STRING id="STR_ID_DMUI_DELETE_ASK"/>
    <STRING id="STR_ID_DMUI_NOTIF_UPDATE_REQUEST"/>
    <STRING id="STR_ID_DMUI_NOTIF_DOWNLOAD_REQUEST"/>
    <STRING id="STR_ID_DMUI_NOTIF_REBOOT"/>
    <STRING id="STR_ID_DMUI_NOTIF_REBOOT_PROGRESS"/>
    <STRING id="STR_ID_DMUI_NOTIF_REBOOT_FAIL"/>
    <STRING id="STR_ID_DMUI_ALERT_DM_INFO_CAPTION"/>
    <STRING id="STR_ID_DM_OTA_PROFILE"/>
    <STRING id="STR_ID_DM_OTA_SERVERID_EXIST_REPLACE"/>
    <STRING id="STR_ID_DM_OTA_SERVERID_FULL_REPLACE"/>
    <STRING id="STR_ID_DM_OTA_SERVERID"/>
    <STRING id="STR_ID_DM_OTA_SERVER_ADDRESS"/>
    <STRING id="STR_ID_DMUI_SESSION_FAILURE"/>
    <STRING id="STR_ID_DMUI_DOWNLOAD_FAILURE"/>
    <STRING id="STR_ID_DMUI_DOWNLOAD_PAUSE_BY_NETWORK_ANOMALY"/>
    <STRING id="STR_ID_DM_DL_RESUME_ASK"/>
#ifdef __OP01__
    <STRING id="STR_ID_DM_SESSION_NOTIFICATION_INFO_CMCC"/>
    <STRING id="STR_ID_DM_SESSION_NOTIFICATION_USER_INTERACTION_CMCC"/>
#endif
#ifdef __OP02__
    <STRING id="STR_ID_DM_SESSION_NOTIFICATION_INFO_CU"/>
    <STRING id="STR_ID_DM_SESSION_NOTIFICATION_USER_INTERACTION_CU"/>
#endif

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_DMUI_MAIN" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Device_manangerment.pbm"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_NO_IMAGE" >CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_SEL_IMAGE" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_V.bmp"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_SERVERID" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Server_ID.pbm"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_SERVER_PASSWORD" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Server_Password.pbm"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_CONNECTION_SETTING" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Date_account.pbm"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_SERVER_ADDRESS" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Server_add.pbm"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_USERNAME" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_User_name.pbm"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_USER_PASSWORD" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_User_password.pbm"</IMAGE>
    <IMAGE id="IMG_ID_DMUI_AUTHTYPE" >CUST_IMG_PATH"\\\\MainLCD\\\\DMUI\\\\DM_Auth_type.pbm"</IMAGE>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!--Menu Tree Area-->
    /* Type Support:OPTION, APP_MAIN, APP_SUB, default value is ORIGINAL */
    /* default="TRUE" means this item is active item when use CSK.       */
    /* type="SEPARATOR" means that CUI will show a separator here        */

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_DMAPP_SETTING"/>
    <SCREEN id="GRP_ID_DMAPP_GLOBAL"/>
    <SCREEN id="GRP_ID_DMAPP_OTA"/>

    <SCREEN id="SCR_ID_DM_NOTIFICATION_CNF"/>
    <SCREEN id="SCR_ID_DM_ALERT_CNF"/>
    <SCREEN id="SCR_ID_DMUI_MAIN"/>
    <SCREEN id="SCR_ID_DMUI_OPTION"/>
    <SCREEN id="SCR_ID_DMUI_UPDATE"/>
    <SCREEN id="SCR_ID_DMUI_UPDATE_DEFER"/>
    <SCREEN id="SCR_ID_DMUI_DOWNLOAD"/>
    <SCREEN id="SCR_ID_DMUI_DOWNLOAD_PROGRESS"/>
    <SCREEN id="SCR_ID_DMUI_ENTER_PIN"/>
    <SCREEN id="SCR_ID_DMUI_REBOOT"/>
    <SCREEN id="SCR_ID_DMUI_ALERT_INPUT"/>
    <SCREEN id="SCR_ID_DMUI_VIEW_INFO"/>
    <SCREEN id="SCR_ID_DMUI_ALERT_SINGLE_CHOICE"/>
    <SCREEN id="SCR_ID_DMUI_ALERT_MULTI_CHOICE"/>
    <SCREEN id="SCR_ID_DMUI_WAITING"/>
    <SCREEN id="SCR_ID_DMUI_OTA_CONFIRM"/>
    <SCREEN id="SCR_ID_DM_OTA_PROVISIONING_INFO"/>
    <SCREEN id="SCR_ID_DM_OTA_SERVERID_LIST"/>
    <SCREEN id="SCR_ID_DMUI_PROMPT_MESSAGE"/>
    <SCREEN id="SCR_ID_DMUI_POPUP"/>
    <SCREEN id="SCR_ID_DMUI_POPUP_CONFIRM"/>
    <SCREEN id="SCR_ID_DM_DL_RESUME_CNF"/>

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="srv_dm_sim_unavailable_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" proc="srv_dm_nw_info_srv_avail_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" proc="srv_dm_acc_dtcnt_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" proc="srv_dm_acc_dtcnt_changed_hdlr"/>
    // restore factory notification
    <RECEIVER id="EVT_ID_SRV_RESTORE_START_NOTIFY" proc="srv_dm_restore_start_notify_hdlr"/>
#ifdef __DM_LAWMO_SUPPORT__
    <SENDER id="EVT_ID_SRV_DM_LAWMO_LOCK_IND" hfile="DmSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_DM_LAWMO_WIPE_IND" hfile="DmSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_DM_LAWMO_WIPE_EX_IND" hfile="DmSrvGprot.h"/>
#endif /* __DM_LAWMO_SUPPORT__ */
    <CACHEDATA type="byte" id="NVRAM_DM_FOTA_UPDATE_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> DM is doing fota flag </DESCRIPTION>
    </CACHEDATA>

    <TIMER id="TIMER_ID_DM_SRV_SESSION_SUSPEND"/>
    <TIMER id="TIMER_ID_DM_SRV_NOTIFICATION_CNF_USER_INTERACTION"/>
    <TIMER id="TIMER_ID_DM_SRV_ALERT_INFO_DURATION"/>
    <TIMER id="TIMER_ID_DM_SRV_ALERT_CNF_USER_INTERACTION"/>
    <TIMER id="TIMER_ID_DM_SRV_DL_AUTO_RESUME"/>
    <TIMER id="TIMER_ID_DM_SRV_USER_INTERACTION_DEFER"/>
    <TIMER id="TIMER_ID_DM_SRV_LAWMO_TRY_SWITCH_MODE"/>

</APP>
#endif /* SYNCML_DM_SUPPORT */
