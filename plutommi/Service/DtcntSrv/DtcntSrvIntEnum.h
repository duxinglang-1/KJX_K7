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
 * DtcntSrvIntEnum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the internal enum header files of data account services.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DTCNT_SRV_INT_ENUM_H
#define _DTCNT_SRV_INT_ENUM_H

#include "MMI_features.h"

typedef enum
{
    SRV_DTCNT_STORE_STATUS_NONE = 0,    /* no store */
    SRV_DTCNT_STORE_STATUS_CLOSED,
    SRV_DTCNT_STORE_STATUS_OPENED,
    SRV_DTCNT_STORE_STATUS_FIRST_BOOTUP,
    SRV_DTCNT_STORE_STATUS_RESET_FACTORY,
    SRV_DTCNT_STORE_STATUS_CORRUPT,
    SRV_DTCNT_STORE_STATUS_FS_ERROR,    
    SRV_DTCNT_STORE_STATUS_PROV_PROC,
    SRV_DTCNT_STORE_STATUS_TOTAL
} srv_dtcnt_store_status_enum;

#ifdef __MMI_WLAN_FEATURES__

typedef enum
{
    SRV_DTCNT_WLAN_ACTION_NULL = 0,
    SRV_DTCNT_WLAN_ACTION_INIT,
    SRV_DTCNT_WLAN_ACTION_CONNECT,
    SRV_DTCNT_WLAN_ACTION_DISCONNECT,
    SRV_DTCNT_WLAN_ACTION_DEINIT,
    SRV_DTCNT_WLAN_ACTION_SCAN,
    SRV_DTCNT_WLAN_ACTION_TOTAL
} srv_dtcnt_wlan_action_enum;


typedef enum
{
    SRV_DTCNT_WLAN_SCAN_STATE_NULL = 0,
    SRV_DTCNT_WLAN_SCAN_STATE_WAITING,
    SRV_DTCNT_WLAN_SCAN_STATE_ABORTING,
    SRV_DTCNT_WLAN_SCAN_STATE_TOTAL
} srv_dtcnt_wlan_scan_state_enum;

typedef enum
{
    SRV_DTCNT_WLAN_ACTION_DEL_OPT_NONE = 0,
    SRV_DTCNT_WLAN_ACTION_DEL_OPT_TERMINATED,
    SRV_DTCNT_WLAN_ACTION_DEL_OPT_DUPLICATED,
    SRV_DTCNT_WLAN_ACTION_DEL_OPT_TOTAL
} srv_dtcnt_wlan_action_del_opt_enum;


typedef enum
{
    SRV_DTCNT_WLAN_PROF_PRI_INFRA_NEW = 0,  /* infra has higher priority, then new profile has higher priority */
    SRV_DTCNT_WLAN_PROF_PRI_INFRA_OLD,
    SRV_DTCNT_WLAN_PROF_PRI_ADHOC_NEW,
    SRV_DTCNT_WLAN_PROF_PRI_ADHOC_OLD,
    SRV_DTCNT_WLAN_PROF_PRI_NEW_INFRA,
    SRV_DTCNT_WLAN_PROF_PRI_OLD_INFRA,
    SRV_DTCNT_WLAN_PROF_PRI_NEW_ADHOC,
    SRV_DTCNT_WLAN_PROF_PRI_OLD_ADHOC,
    SRV_DTCNT_WLAN_PROF_PRI_TOTAL
} srv_dtcnt_wlan_prof_priority_enum;


#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)
/* Converted symbols to define CCA namespace mapping table. */
typedef enum
{
    /* for proprietary OTA provisioning spec */
    WLAN_OTAP_NS_INFRA,
    WLAN_OTAP_NS_ADHOC,

    /* for OMA WLAN OTA provisioning extension */
    WLAN_OTAP_NS_NAPDEF,
    WLAN_OTAP_NS_WLAN,
    WLAN_OTAP_NS_SEC_SSID,
    WLAN_OTAP_NS_EAP,
    WLAN_OTAP_NS_CERT,
    WLAN_OTAP_NS_WEPKEY
} srv_dtcnt_cca_symbol_enum;
#endif /* !(defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)) */

#endif /* __MMI_WLAN_FEATURES__ */
#endif /* _DTCNT_SRV_INT_ENUM_H */ 
