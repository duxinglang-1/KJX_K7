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
 * DtcntSrvGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   These are the external services provided by data account service module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DTCNT_SRV_GPROT_H
#define _DTCNT_SRV_GPROT_H

#include "MMIDataType.h"
#include "cbm_consts.h"

/* WLAN Services include files */
#include "wndrv_cnst.h"         /* WNDRV_XXX constants */
#include "supc_abm_msgs.h"      /* wlan supc related structures */

#ifndef CODEGEN_DTCNT_SRV /* for codegen */
#include "mmi_rp_srv_dtcnt_def.h"
#include "MMI_features.h"
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
/* CCA Services include files */
#include "CcaSrvGprot.h"
#endif /* __CCA_SUPPORT__ */
#endif /* CODEGEN_DTCNT_SRV */

#include "mmi_res_range_def.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "mmi_frm_utility_gprot.h"
#include "custom_data_account.h"
#define SRV_DTCNT_DEFS
/****************************************************************************/
/* Definitions                                                              */
/****************************************************************************/

/* Maximum number of AP list search result */
#define SRV_DTCNT_WLAN_MAX_AP_LIST_NUM          (WNDRV_MAX_SCAN_RESULTS_NUM)
/* Maximum length of WLAN SSID attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_SSID_LEN             (32)
/* Maximum length of WLAN profile name attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_WLAN_PROF_NAME_LEN   (SRV_DTCNT_PROF_MAX_SSID_LEN)
/* Maximum length of WLAN profile passphrase attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN       (64)
/* Maximum length of WLAN profile psk attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_PSK_LEN              (34)
/* Maximum length of WLAN profile wep key attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_WEP_KEY_LEN          (26)


/* Maximum length of homepage attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN     (256)
/* Maximum length of account name attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_ACC_NAME_LEN     (31)
/* Maximum length of CSD dial number attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN     (23)
/* Maximum length of username attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_USER_LEN         (MAX_GPRS_USER_NAME_LEN - 1)
/* Maximum length of password attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_PW_LEN           (MAX_GPRS_PASSWORD_LEN - 1)
/* Maximum length of GPRS APN attribute in Data account profile */
#ifdef __MMI_DTCNT_SLIM__
#define SRV_DTCNT_PROF_MAX_APN_LEN          (30)
#else
#define SRV_DTCNT_PROF_MAX_APN_LEN          (99)
#endif
/* Maximum length of profile IP address length in Data account profile */
#define SRV_DTCNT_PROF_MAX_IP_ADDR_LEN      (4)
#define SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN   CUSTOM_MAX_PROXY_ADDR_LEN

/* Maximum number of gprs and csd profiles in Data account SRV except WLAN account */
#ifdef __SLIM_NWK_PROFILE__

    #define SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM     (5)

#if (MMI_MAX_SIM_NUM == 4)
        #define SRV_DTCNT_PROF_MAX_ACCOUNT_NUM      (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM * MMI_MAX_SIM_NUM)
#elif (MMI_MAX_SIM_NUM == 3)
        #define SRV_DTCNT_PROF_MAX_ACCOUNT_NUM      (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM * MMI_MAX_SIM_NUM)
#elif (MMI_MAX_SIM_NUM == 2) && defined(__OP01__)
        #undef  SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM
        #define SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM (10)
        #define SRV_DTCNT_PROF_MAX_ACCOUNT_NUM      (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM * MMI_MAX_SIM_NUM)
#elif (MMI_MAX_SIM_NUM == 2)
        #define SRV_DTCNT_PROF_MAX_ACCOUNT_NUM      (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM * MMI_MAX_SIM_NUM)
#elif (MMI_MAX_SIM_NUM == 1 && defined (__OP01_3G__))
    #undef  SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM
	#define SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM (10)
#define SRV_DTCNT_PROF_MAX_ACCOUNT_NUM      (10)
#else
        #define SRV_DTCNT_PROF_MAX_ACCOUNT_NUM      (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM)
#endif /* MMI_MAX_SIM_NUM */

#else /* !__SLIM_NWK_PROFILE__ */

/* Maximum number of gprs and csd profiles in Data account SRV except WLAN account */
#define SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM     (10)
#define SRV_DTCNT_PROF_MAX_ACCOUNT_NUM		(SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM * MMI_SIM_TOTAL)
    
#endif /* __SLIM_NWK_PROFILE__ */

/* Maximum length of proxy name attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_PX_NAME_LEN      (40)
/* Maximum length of proxy auth ID attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN   (40)
/* Maximum length of proxy auth password attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN   (40)
/* Maximum length of proxy address attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_PX_ADDR_LEN      (SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN)
/* Maximum length of proxy ID attribute in Data account profile */
#define SRV_DTCNT_PROF_MAX_PX_ID_LEN        (40)


/* Maximum length of prvisioning profile URL hash length in Data account profile */
#define SRV_DTCNT_PROVURL_HASH_LEN          (16)
/* Maximum length of prvisioning profile NAPID hash length in Data account profile */
#define SRV_DTCNT_NAPID_HASH_LEN            (16)
/* Maximum length of prvisioning profile PROXYID hash length in Data account profile */
#define SRV_DTCNT_PROF_PXID_HASH_LEN        (16)
 
/* For CSD type profile */
#define DATA_ACCOUNT_BEARER_CSD  0x01
/* For GPRS type profile */
#define DATA_ACCOUNT_BEARER_GPRS 0x02

//#if defined (SYNCML_DM_SUPPORT) && defined(__CCA_SUPPORT__)
#if defined (SYNCML_DM_SUPPORT) && defined(__MMI_CCA_SUPPORT__)
#define SRV_DTCNT_DM_GPRS_NODE_ID		"GPRS_1"	/* temp_dm_gprs node string id for DM retrieve/update support */
#define SRV_DTCNT_DM_CSD_NODE_ID		"CSD_1"		/* temp_dm_csd node string id for DM retrieve/update support */
#define SRV_DTCNT_DM_PROXY_NODE_ID		"PROXY_1"	/* temp_dm_proxy node string id for DM retrieve/update support */
#endif /* defined (SYNCML_DM_SUPPORT) && defined(__CCA_SUPPORT__) */

/* DOM-NOT_FOR_SDK-BEGIN */
#define SRV_DTCNT_MAX_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM  (10)    /* MAX WLAN proxy exclusive ip address number */
/* DOM-NOT_FOR_SDK-END */

#define EVT_ID_SRV_DTCNT_TOTAL MMI_RP_SRV_DTCNT_EVENT_MAX

#define SRV_DTCNT_ENUMS
/****************************************************************************/
/* Enums                                                                    */
/****************************************************************************/

#ifdef __BUILD_DOM__
/* Data Account Srvice Event ID definition */
typedef enum
{        
    /**********************************************************************************************/
    /*  WLAN Bearer Status Related Events                                                         */
    /**********************************************************************************************/

    /* post type, srv_dtcnt_wlan_active_evt_struct, must return MMI_RET_OK */   
    EVT_ID_SRV_DTCNT_WLAN_ACTIVE = SRV_DTCNT_BASE + 1, 
    /* post type, srv_dtcnt_wlan_connected_evt_struct, must return MMI_RET_OK */
    EVT_ID_SRV_DTCNT_WLAN_CONNECTED,
    /* post type, srv_dtcnt_wlan_inactive_evt_struct, must return MMI_RET_OK */
    EVT_ID_SRV_DTCNT_WLAN_INACTIVE,
    /* post type, srv_dtcnt_wlan_scan_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_SCAN,
    /* post type, srv_dtcnt_wlan_conn_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_CONNECT,
    /* post type, srv_dtcnt_wlan_bearer_status_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_BEARER_STATUS,

    /**********************************************************************************************/
    /*  SRV Indication Events                                                                     */
    /**********************************************************************************************/

    /* post type, srv_dtcnt_wlan_conn_ind_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_CONN_IND,
    /* post type, srv_dtcnt_wlan_disc_ind_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_DISC_IND,
    /* post type, srv_dtcnt_wlan_ipaddr_update_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_IPADDR_UPDATE,
    /* post type, srv_dtcnt_wlan_ipaddr_conflict_ind_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_IPADDR_CONFLICT_IND,
    /* post type, srv_dtcnt_wlan_curr_ap_info_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_CURR_AP_INFO,
    /* post type, srv_dtcnt_wlan_wps_info_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_WPS_INFO,
    /* post type, srv_dtcnt_wlan_change_bearer_to_wlan_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_CHANGE_BEARER_TO_WLAN,
    /* post type, srv_dtcnt_wlan_change_bearer_to_cellular_network_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_CHANGE_BEARER_TO_CELLULAR_NETWORK,
    /* post type, srv_dtcnt_prov_ind_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    EVT_ID_SRV_DTCNT_PROV_IND,
    /* post type, srv_dtcnt_prov_install_res_ind_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    EVT_ID_SRV_DTCNT_PROV_INSTALL_RES_IND,
    /* post type, srv_dtcnt_prov_done_ind_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    EVT_ID_SRV_DTCNT_PROV_DONE_IND,
    /* post type, srv_dtcnt_acct_update_ind_evt_struct, must return MMI_RET_OK */
    EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND,
    /* post type, srv_dtcnt_acct_delete_ind_evt_struct, must return MMI_RET_OK */
    EVT_ID_SRV_DTCNT_ACCT_DELETE_IND,
    /* post type, srv_dtcnt_sim_preference_update_ind_evt_struct, must return MMI_RET_OK */
    EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND,
    /* post type, srv_dtcnt_change_real_acct_ind_evt_struct, must return MMI_RET_OK */
    EVT_ID_SRV_DTCNT_CHANGE_REAL_ACCT_IND,

    /**********************************************************************************************/
    /*  APP Request Response Indication Events                                                    */
    /**********************************************************************************************/

    /* post type, srv_dtcnt_wlan_init_res_ind_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND,
    /* post type, srv_dtcnt_wlan_deinit_res_ind_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND,
    /* post type, srv_dtcnt_wlan_conn_res_ind_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND,
    /* post type, srv_dtcnt_wlan_disc_res_ind_evt_struct, must return MMI_RET_OK */    
    EVT_ID_SRV_DTCNT_WLAN_DISC_RES_IND,
    /* send type, srv_dtcnt_wlan_scan_res_ind_evt_struct, must return MMI_RET_OK, applications need to copy information directly */
    EVT_ID_SRV_DTCNT_WLAN_SCAN_RES_IND,

    /**********************************************************************************************/
    /*  App/Srv Interaction Events                                                                */
    /**********************************************************************************************/
    
    /* send type, srv_dtcnt_wlan_ipaddr_change_qry_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_QRY,
    /* send type, srv_dtcnt_wifi_chip_invalid_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    EVT_ID_SRV_DTCNT_WIFI_CHIP_INVALID,
    /* post type, srv_dtcnt_wlan_search_ap_open_ind_evt_struct, must return MMI_RET_OK, only DA APP can register this event, please start to search AP list after receiving this event */
    EVT_ID_SRV_DTCNT_WLAN_SEARCH_AP_OPEN_IND,
    /* post type, srv_dtcnt_wlan_search_ap_close_ind_evt_struct, must return MMI_RET_OK, only DA APP can register this event, please close search AP list after receiving this event */
    EVT_ID_SRV_DTCNT_WLAN_SEARCH_AP_CLOSE_IND,
    /* send type, srv_dtcnt_bearer_init_wlan_ap_query_ind_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    EVT_ID_SRV_DTCNT_BEARER_INIT_WLAN_AP_QUERY_IND,    
    /* send type, srv_dtcnt_bearer_deinit_wlan_ap_query_ind_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    EVT_ID_SRV_DTCNT_BEARER_DEINIT_WLAN_AP_QUERY_IND,    
    /* send type, srv_dtcnt_wlan_ap_list_query_ind_evt_struct, must return MMI_RET_OK, only DA APP can register this event */
    EVT_ID_SRV_DTCNT_WLAN_AP_LIST_QUERY_IND,    
    /* post type*/
    EVT_ID_SRV_DTCNT_WLAN_LOGOUT_IND,

    EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_CNF,

    EVT_ID_SRV_DTCNT_WLAN_SWITCH_SAME_SSID_IND,

    EVT_ID_SRV_DTCNT_NET_STATUS_IND,

    EVT_ID_SRV_DTCNT_WLAN_CONN_PROF,

    EVT_ID_SRV_DTCNT_WLAN_SLEEP,

    EVT_ID_SRV_DTCNT_TOTAL
} mmi_rp_srv_dtcnt_event_enum;
#endif /* __BUILD_DOM__ */

/* Data Account services result enum */
typedef enum
{
    SRV_DTCNT_RESULT_SUCCESS    = 0,    /* success */
    SRV_DTCNT_RESULT_FAILED,            /* general failed case */
    SRV_DTCNT_RESULT_PROCESSING,        /* processing state implies Event notify */
    SRV_DTCNT_RESULT_STATE_ERROR,       /* service status error */
    SRV_DTCNT_RESULT_INVALID_INPUT,     /* the input parameter is invalid */
    SRV_DTCNT_RESULT_ABORTED,           /* the process is aborted */
    SRV_DTCNT_RESULT_TERMINATED,        /* the process is terminated */
    SRV_DTCNT_RESULT_ONE_STORE_EXISTS,  /* currently only support one store */
    SRV_DTCNT_RESULT_STORE_NOT_COMMIT,  /* store doesn't be config commited before */
    SRV_DTCNT_RESULT_INVALID_STORE,     /* store invalid */
    SRV_DTCNT_RESULT_STORE_FULL,        /* reach maximum profile storage */
    SRV_DTCNT_RESULT_READ_ONLY,         /* can't delete or update read_only profile */
    SRV_DTCNT_RESULT_FIRST_BOOTUP,      /* first bootup rerurn code for store open */
    SRV_DTCNT_RESULT_RESET_FACTORY,     /* the data base sim profiles folder is deleted */
    SRV_DTCNT_RESULT_FS_ERROR,          /* the database file system error */
    SRV_DTCNT_RESULT_IGNORE,
    SRV_DTCNT_RESULT_TOTAL
} srv_dtcnt_result_enum;

/* Data Account WLAN bearer status enum */
typedef enum
{
    SRV_DTCNT_WLAN_STATUS_INACTIVE      = 0x01, /* inactive state */
    SRV_DTCNT_WLAN_STATUS_ACTIVE        = 0x02, /* active state */
    SRV_DTCNT_WLAN_STATUS_CONNECTED     = 0x04, /* connected state */
    SRV_DTCNT_WLAN_STATUS_INVALID_MAC   = 0x08, /* current MAC address isn't valid, OR'd with ACTIVE and CONNECTED status */
    SRV_DTCNT_WLAN_STATUS_TOTAL         = 0xFF
} srv_dtcnt_wlan_status_enum;

/* Data Account WLAN request result enum */
typedef enum
{
    SRV_DTCNT_WLAN_REQ_RES_DONE = 0,    /* request completed successfully */
    SRV_DTCNT_WLAN_REQ_RES_TERMINATED,  /* request is terminated by newer request */
    SRV_DTCNT_WLAN_REQ_RES_DUPLICATED,  /* request is removed by newer same request */
    SRV_DTCNT_WLAN_REQ_RES_FAILED,      /* request is ignored due to state error */
    SRV_DTCNT_WLAN_REQ_RES_ADD_BY_SRV,
    SRV_DTCNT_WLAN_REQ_RES_TOTAL
} srv_dtcnt_wlan_req_res_enum;

/* Data Account encoded account enum */
typedef enum
{
    SRV_DTCNT_ACCOUNT_PRIMARY = 1,  /* encoded primary account */
    SRV_DTCNT_ACCOUNT_SECONDARY,    /* encoded secondary account */
    SRV_DTCNT_ACCOUNT_TOTAL
} srv_dtcnt_account_enum;

/* Data Account bearer enum */
typedef enum
{
    SRV_DTCNT_BEARER_UNKNOWN    = 0,  /* unknown type profile */
    SRV_DTCNT_BEARER_CSD        = 1,  /* For CSD type profile */
    SRV_DTCNT_BEARER_GPRS       = 2,  /* For GPRS type profile */
    SRV_DTCNT_BEARER_WIFI       = 4,  /* For WIFI type profile */
    SRV_DTCNT_BEARER_TOTAL
} srv_dtcnt_bearer_enum;       

/* Data Account address type enum */
typedef enum
{
    SRV_DTCNT_ADDR_TYPE_IPv4,  /* IPv4 */
    SRV_DTCNT_ADDR_TYPE_IPv6,  /* IPv6 */
    SRV_DTCNT_ADDR_TYPE_TOTAL
} srv_dtcnt_addr_type_enum;       

/* Data Account profile proxy service type enum */
typedef enum
{
    /*
     * CL-WSP               9200  WAP
     * CO-WSP               9201  WAP
     * CL-SEC-WSP           9202  WAP + Security ON
     * CO-SEC-WSP           9203  WAP + Security ON
     * CO-SEC-WTA           not supported
     * CL-SEC-WTA           not supported
     * OTA-HTTP-TO/PO       80    HTTP
     * OTA-HTTP-TLS-TO/PO   443   HTTP + Security ON
     */
     
    SRV_DTCNT_PROF_PX_SRV_NONE  = 0,    /* Not specified */
    SRV_DTCNT_PROF_PX_SRV_CL_WSP,       /* WSP, Connection less */
    SRV_DTCNT_PROF_PX_SRV_CO_WSP,       /* WSP, Connection oriented */
    SRV_DTCNT_PROF_PX_SRV_CL_SEC_WSP,   /* WSP, Connection less, security mode */
    SRV_DTCNT_PROF_PX_SRV_CO_SEC_WSP,   /* WSP, Connection oriented, security mode */
    SRV_DTCNT_PROF_PX_SRV_CL_SEC_WTA,   /* WTA, Connection less, security mode */
    SRV_DTCNT_PROF_PX_SRV_CO_SEC_WTA,   /* WTA, Connection oriented, security mode */
    SRV_DTCNT_PROF_PX_SRV_HTTP,         /* HTTP type */
    SRV_DTCNT_PROF_PX_SRV_HTTP_TLS,     /* HTTP type, enable TLS */
    SRV_DTCNT_PROF_PX_SRV_STARTTLS,     /* STARTTLS type */
    SRV_DTCNT_PROF_PX_SRV_TOTAL
} srv_dtcnt_prof_px_srv_enum;

/* Data Account WLAN scan result enum */
typedef enum
{
    SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS = 0,   /* WLAN scan success */
    SRV_DTCNT_WLAN_SCAN_RESULT_FAILED,        /* WLAN scan failed */
    SRV_DTCNT_WLAN_SCAN_RESULT_ABORTED,       /* WLAN scan service is aborted */
    SRV_DTCNT_WLAN_SCAN_RESULT_DELETE,        /* WLAN scan delete in CONNECT_WAIT */
    SRV_DTCNT_WLAN_SCAN_RESULT_TOTAL
} srv_dtcnt_wlan_scan_result_enum;

/* Data Account profile sim type enum */
typedef enum
{
    SRV_DTCNT_SIM_TYPE_NONE = 0,
    SRV_DTCNT_SIM_TYPE_1,       /* sim 1 */
    SRV_DTCNT_SIM_TYPE_2,       /* sim 2 */
    SRV_DTCNT_SIM_TYPE_3,       /* sim 3 */
    SRV_DTCNT_SIM_TYPE_4,       /* sim 4 */
    SRV_DTCNT_SIM_TYPE_TOTAL
} srv_dtcnt_sim_type_enum;

#define SRV_DTCNT_CALLBACKS
/****************************************************************************/
/* Callback function prototypes                                             */
/****************************************************************************/

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_dtcnt_wlan_cb_func_ptr
 * DESCRIPTION
 *  WLAN general callback function for no feedback arguments except application piggyback data
 * PARAMETERS
 *  user_data   :   [IN]    APP's piggyback user_data
 *  res         :   [IN]    request result
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_dtcnt_wlan_cb_func_ptr) (void *user_data, srv_dtcnt_wlan_req_res_enum res);

/****************************************************************************/
/* Structs                                                                  */
/****************************************************************************/

#define SRV_DTCNT_STRUCTS

/* this struct is designed for Data account SRV to send the connect result to APP */
typedef struct
{
    srv_dtcnt_result_enum   result;     /* SUCCESS: connected, FAILD: connect failed, 
                                         * ABORTED: preemptived by new connect req 
                                         * TERMINATED: terminated by new disconnect req
                                         * STATE_ERROR: can't perform connect req
                                         */
    supc_abm_cause_enum     cause;      /* Error cause, uses only if result = FAILD */
    U8                      bssid[WNDRV_MAC_ADDRESS_LEN];   /* MAC Address */
    U8                      ssid[WNDRV_SSID_MAX_LEN];       /* SSID */
    MMI_BOOL                init_by_soc;                    /* connection activated by socket flag */
    U16                     ssid_len;                       /* SSID length in array */
    U32                     channel_number;                 /* channel info from chip */
    U32                     profile_id;                     /* connected profile id */
    U32                         auth_type;
    U32                         eap_peap_auth_type;
    U32                         eap_ttls_auth_type;
    supc_connection_type_enum   conn_type;
    kal_uint16                  encry_mode; /*defaultly, it is WPS_ENCR_TYPES, 
                                              and now we don't to parse encry_mode in M2 */
    kal_uint8                   passphase[32];
    kal_uint8                   passphase_len;
    MMI_BOOL                need_login;
    MMI_BOOL                cancel_by_discon;
    int                     rssi;
} srv_dtcnt_wlan_conn_res_struct;

/* this struct is designed for Data account SRV to send the IP address updated information to APP */
typedef struct
{ 
    U8 ip_addr[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN]; /* updated IP address */
    U8 dns1[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];    /* updated primary DNS address */
    U8 dns2[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN];    /* updated secondary DNS address */
    U8 gateway[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN]; /* updated gateway address */
    U8 netmask[SRV_DTCNT_PROF_MAX_IP_ADDR_LEN]; /* updated netmask */
} srv_dtcnt_wlan_ipaddr_update_struct;

/* this struct is designed for Data account SRV to send the current AP information to APP */
typedef struct
{    
  U8    current_data_rate;  /* data rate */
  U16  ht_current_data_rate;
  S32   rssi;               /* rssi information */
} srv_dtcnt_wlan_curr_ap_info_struct;

/* this struct is designed for Data account APP to query the string type info attribute in profiles */
typedef struct
{      
    CHAR *dest;       /* destination buffer. */
    U16 dest_len;   /* application's dest buffer length. */
    U16 req_len;    /* if this attribute is provided by application (NOT NULL), 
                       DA SRV will hint application the required buffer length */
} srv_dtcnt_prof_str_info_qry_struct;

/* this struct is designed for Data accont SRV to report the proxy info for APP */
typedef struct
{
    U8  use_proxy;          /* use proxy flag */
    srv_dtcnt_addr_type_enum    px_addrtype;    /* IPv4 or IPv6 */
    srv_dtcnt_prof_px_srv_enum  px_service;     /* proxy service type */
    U8  px_addr[SRV_DTCNT_PROF_MAX_PROXY_ADDR_LEN + 1];        /* proxy addr */
    U8  px_authid[SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN + 1];   /* proxy auth. ID string (ASCII) */
    U8  px_authpw[SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN + 1];   /* proxy auth. PW (ASCII) */
    U8  px_startpage[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN + 1];  /* proxy homepage string (ASCII) */
    U16 px_port;                                /* proxy port */
    U32 acc_id;                                 /* associated account ID */
} srv_dtcnt_prof_proxy_info_struct;

/* This structure is designed for DA SRV proxy info query request 
 * MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_REQ in mcu\\interface\\mmi\\mmi_sap.h
 */
typedef struct
{
     U8     ref_count;  /* reference count */
     U16    msg_len;    /* message length */
     srv_dtcnt_account_enum idx;    /* account idx of acc_id */
     U32    request_id; /* application id */
     U32    acc_id;     /* specified account id */
} srv_dtcnt_prof_proxy_info_req_struct;

/* This structure is designed for DA SRV proxy info query confirm 
 * MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_CNF in mcu\\interface\\mmi\\mmi_sap.h
 */
typedef struct
{
     U8     ref_count;  /* reference count */
     U16    msg_len;    /* message length */
     U8     result;     /* 1 means success, 0 means failed */
     U32    request_id; /* application id */
     srv_dtcnt_prof_proxy_info_struct   px_info;    /* proxy information */
} srv_dtcnt_prof_proxy_info_cnf_struct;

/* this struct is designed for Data account SRV to send the scan result to APP */
typedef struct
{
    srv_dtcnt_wlan_scan_result_enum result;     /* scan result enum */
    U8                              ap_list_num;/* total num of searched ap list */
    const supc_abm_bss_info_struct* ap_list[SRV_DTCNT_WLAN_MAX_AP_LIST_NUM]; /* bss info array */
    U32 scan_job_id;                            /* scan_job_id, 0xFFFFFF means scan result broadcasting */    
} srv_dtcnt_wlan_scan_result_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
/* Used for CMCC TD WLAN spec. */
typedef struct
{
	U8  ip_addr[SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN+1];	/* IP address */
} srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct;

/* this struct is designed for proxy exclusive IP list query operation */
typedef struct
{
    srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct ips[SRV_DTCNT_MAX_WLAN_PROXY_EXCLUSIVE_IP_ADDR_NUM];  /* IP list query result */
    U8 num_ips;                                                                                         /* the number of queried IP list */
} srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct;

typedef enum
{
    SRV_DTCNT_WLAN_SLEEP_MODE_NEVER_SLEEP,
    SRV_DTCNT_WLAN_SLEEP_MODE_CHARGEIN_NEVER_SLEEP,
    SRV_DTCNT_WLAN_SLEEP_MODE_LCD_OFF_SLEEP
}srv_dtcnt_wlan_sleep_mode_enum;

typedef struct
{
    MMI_BOOL is_auto_search;
    U8 auto_search_interval;
    MMI_BOOL is_auto_conn;
    U8 network_switch; //cell to wlan, 0:always ask  1:auto  2:manual
    MMI_BOOL is_ssid_switch;// handover between same ssid
    U8 cellular_switch;// if wlan unavailable, whether use cell  0:always ask  1:auto  2:manual
    U8 auto_portal_switch; //0: need auth
    U8 power_saving_mode;
    U8 wlan_to_cellular;//wlan to cell  0:always ask  1:auto  2:manual
    srv_dtcnt_wlan_sleep_mode_enum sleep_mode;
    MMI_BOOL need_awake;
} srv_dtcnt_wlan_prefer_struct;

/* DOM-NOT_FOR_SDK-END */

#define SRV_DTCNT_EVENTS

/**********************************************************************************************/
/*  WLAN Bearer Status Related Events                                                         */
/**********************************************************************************************/

/* event structure for EVT_ID_SRV_DTCNT_WLAN_ACTIVE */
typedef struct {    
#ifdef __BUILD_DOM__
    U16 evt_id;		        /* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
    /* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_active_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_CONNECTED */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_connected_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_INACTIVE */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_inactive_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_SCAN */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_scan_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_CONNECT */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_conn_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_BEARER_STATUS */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_status_enum  status; /* current WLAN status */
} srv_dtcnt_wlan_bearer_status_evt_struct;

typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    U16  status; /* current WLAN status */
} srv_dtcnt_net_status_ind_evt_struct;


/**********************************************************************************************/
/*  SRV Indication Events                                                                     */
/**********************************************************************************************/

/* event structure for EVT_ID_SRV_DTCNT_WLAN_CONN_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_conn_res_struct conn_result; /* connect result for data account APP */
} srv_dtcnt_wlan_conn_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_IPADDR_UPDATE */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_ipaddr_update_struct new_ipaddr; /* new IP address information for data account APP */
} srv_dtcnt_wlan_ipaddr_update_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_IPADDR_CONFLICT_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_ipaddr_conflict_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_CURR_AP_INFO */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_wlan_curr_ap_info_struct curr_ap_info; /* current AP info for data account APP */
} srv_dtcnt_wlan_curr_ap_info_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_WPS_INFO */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    U8 num; 
    wifi_wps_ui_info_struct info[2];
} srv_dtcnt_wlan_wps_info_evt_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
/* Used for CMCC TD WLAN spec. */
/* event structure for EVT_ID_SRV_DTCNT_WLAN_CHANGE_BEARER_TO_WLAN */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_change_bearer_to_wlan_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_WLAN_CHANGE_BEARER_TO_CELLULAR_NETWORK */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_change_bearer_to_cellular_network_evt_struct;
/* DOM-NOT_FOR_SDK-END */

/* event structure for EVT_ID_SRV_DTCNT_WLAN_SEARCH_AP_IND */
typedef struct
{
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
} srv_dtcnt_wlan_search_ap_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    U8      sim_id;     /* associated new sim id, sim1:1, sim2:2, sim3:3, sim4:4 */
    U8      sim_id_old; /* associated old sim id, sim1:1, sim2:2, sim3:3, sim4:4 */
    U8      cause;      /* 0: user modification, 1: provisioning, 2:update created/change default acct */
    U32     acc_id;     /* account id(no sim id encoded) */
} srv_dtcnt_acct_update_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_ACCT_DELETE_IND */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    U8      cause;      /* 0: user deleted, 1: sim changed */
    U8      del_num;    /* #of deleted accounts in acc_id and sim_id array */
    U8      sim_id[SRV_DTCNT_PROF_MAX_ACCOUNT_NUM];     /* associated sim id, sim1:1, sim2:2, sim3:3, sim4:4 */
    U32     acc_id[SRV_DTCNT_PROF_MAX_ACCOUNT_NUM];     /* account id(no sim id encoded) */
} srv_dtcnt_acct_delete_ind_evt_struct;

/* event structure for EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    srv_dtcnt_sim_type_enum      sim_id;     /* associated new sim id */
    srv_dtcnt_sim_type_enum      sim_id_old; /* associated old sim id */
} srv_dtcnt_sim_preference_update_ind_evt_struct;

/* DOM-NOT_FOR_SDK-BEGIN */
/* Used for CMCC TD WLAN spec. */
/* event structure for EVT_ID_SRV_DTCNT_CHANGE_REAL_ACCT_IND */
typedef struct {
#ifdef __BUILD_DOM__
    U16 evt_id;				/* MMI_EVENT_ID */
    U16 size;               /* EVENT SIZE */
    void *user_data;	    /* Piggyback user data */
#endif
	/* DOM-NOT_FOR_SDK-BEGIN */
	MMI_EVT_PARAM_HEADER	/* MMI_EVENT_COMMON_HEADER */
	/* DOM-NOT_FOR_SDK-END */
    U32     ori_acct_id;     /* Original account id (32-bit encoded) */
    U32     rel_acct_id;     /* Real account id (32-bit encoded) */
} srv_dtcnt_change_real_acct_ind_evt_struct;
/* DOM-NOT_FOR_SDK-END */

/*DOM-NOT_FOR_SDK-BEGIN */
typedef struct
{
#ifdef __BUILD_DOM__
        U16 evt_id;             /* MMI_EVENT_ID */
        U16 size;               /* EVENT SIZE */
        void *user_data;        /* Piggyback user data */
#endif
        /* DOM-NOT_FOR_SDK-BEGIN */
        MMI_EVT_PARAM_HEADER    /* MMI_EVENT_COMMON_HEADER */
        /* DOM-NOT_FOR_SDK-END */
}srv_dtcnt_wlan_sleep_evt_struct;
/*DOM-NOT_FOR_SDK-END */

/****************************************************************************/
/* External Interfaces (User : Apps)                                        */
/****************************************************************************/

#define SRV_DTCNT_APP_EXTERNAL

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_init
 * DESCRIPTION
 *  To init data account service
 * PARAMETERS
 *  evt	:	[IN]	init event notification
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
extern mmi_ret srv_dtcnt_init(mmi_event_struct *evt);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_bearer_type
 * DESCRIPTION
 *  To get the bearer type of specified account id
 * PARAMETERS
 *  acc_id  :   [IN]    specified encoded account ID.  
 *  acc_idx :   [IN]    specified account index for query (primary or secondary).  
 * RETURNS
 *  srv_dtcnt_bearer_enum
 *****************************************************************************/
extern srv_dtcnt_bearer_enum srv_dtcnt_get_bearer_type(
                            U32 acc_id,
                            srv_dtcnt_account_enum acc_idx);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_apn
 * DESCRIPTION
 *  To get GPRS profile APN by specified account id
 *  1. Only dest_len will be copied, and reqired length will be set back to application.
 *  2. Also, if dest = NULL, and req_len exist, DA SRV will return MMI_FALSE
 *     with required length in req_len for application.
 * PARAMETERS
 *  acc_id      :   [IN]        specified account ID.
 *  out_apn     :   [IN/OUT]    APN string output location (UCS2)
 *  acc_idx     :   [IN]        specified account index for query (primary or secondary).
 * RETURNS
 *  MMI_TRUE    :   Get APN successfully
 *  MMI_FALSE   :   Get APN failed
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_get_apn(
            U32 acc_id, 
            srv_dtcnt_prof_str_info_qry_struct *out_apn,
            srv_dtcnt_account_enum acc_idx);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_homepage
 * DESCRIPTION
 *  To get GPRS profile Homepage by specified account id
 *  1. Only dest_len will be copied, and reqired length will be set back to application.
 *  2. Also, if dest = NULL, and req_len exist, DA SRV will return MMI_FALSE
 *     with required length in req_len for application.
 * PARAMETERS
 *  acc_id          :   [IN]        specified account ID.
 *  out_homepage    :   [IN/OUT]    Homepage string output location (ASCII)
 *  acc_idx         :   [IN]        specified account index for query (primary or secondary).
 * RETURNS
 *  MMI_TRUE    :   Get homepage successfully
 *  MMI_FALSE   :   Get homepage failed
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_get_homepage(
            U32 acc_id,
            srv_dtcnt_prof_str_info_qry_struct *out_homepage,
            srv_dtcnt_account_enum acc_idx);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_account_name
 * DESCRIPTION
 *  To get profile account name by specified account id
 *  1. Only dest_len will be copied, and reqired length will be set back to application.
 *  2. Also, if dest = NULL, and req_len exist, DA SRV will return MMI_FALSE
 *     with required length in req_len for application.
 * PARAMETERS
 *  acc_id          :   [IN]        specified account ID.
 *  out_acc_name    :   [IN/OUT]    account name string output location (UCS2)
 *  acc_idx         :   [IN]        specified account index for query (primary or secondary).
 * RETURNS
 *  MMI_TRUE    :   Get account name successfully
 *  MMI_FALSE   :   Get account name failed
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_get_account_name(
            U32 acc_id,
            srv_dtcnt_prof_str_info_qry_struct *out_acc_name,
            srv_dtcnt_account_enum acc_idx);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_csd_number
 * DESCRIPTION
 *  To get CSD dial number by specified account id
 *  1. Only dest_len will be copied, and reqired length will be set back to application.
 *  2. Also, if dest = NULL, and req_len exist, DA SRV will return MMI_FALSE
 *     with required length in req_len for application.
 * PARAMETERS
 *  acc_id  :   [IN]        specified account ID.
 *  out_csd :   [IN/OUT]    CSD number output location (UCS2)
 *  acc_idx :   [IN]        specified account index for query (primary or secondary).
 * RETURNS
 *  TRUE    :  Get CSD number successfully
 *  FALSE   :  Get CSD number failed
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_get_csd_number(
            U32 acc_id,
            srv_dtcnt_prof_str_info_qry_struct *out_csd,
            srv_dtcnt_account_enum acc_idx);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_set_homepage
 * DESCRIPTION
 *  To set profile Homepage by specified account id
 *  1. This API is designed for WAP/MMS to set homepage value into specified profile
 *  2. acc_id CBM_DEFAULT_NWK_ACCT_ID isn't allowed to set homepgae setting.
 *  3. If APP want to set homepage setting, APP should own the specified account ID 
 *     from CCA or CUI.
 *  4. If in_len larger than SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN, 
 *     only SRV_DTCNT_PROF_MAX_HOMEPAGE_LEN will be copied.
 * PARAMETERS
 *  acc_id      :   [IN]    specified account ID.
 *  in_homepage :   [IN]    specified homepage string (ASCII)
 *  in_len      :   [IN]    specified homepage string length
 * RETURNS
 *  MMI_TRUE    :   Set homepage successfully
 *  MMI_FALSE   :   Set homepage failed
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_set_homepage(
            U32 acc_id,
            CHAR *in_homepage,
            U32 in_len);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_proxy_info
 * DESCRIPTION
 *  To get the proxy information by specidied account id.
 *  APP SHOULD prepare the memory for proxy info struct 
 *  "srv_dtcnt_prof_proxy_info_struct", sizeof() is recommanded for malloc size information.
 *  By this API, application get proxy address with domain name format, 
 *  so application should use soc_gethostbyname to get IP address first.
 *  The detail of soc_gethostbyname please refer to soc_api.h 
 * PARAMETERS
 *  acc_id      :   [IN]    specified account ID.
 *  out_px_info :   [IN]    proxy info output buffer. (SHOULD prepared by APP)
 *  acc_idx     :   [IN]    specified account index for query (primary or secondary).
 * RETURN VALUES
 *  MMI_FALSE   : retrieve failed
 *  MMI_TRUE    : retrieve success
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_get_proxy_info(
            U32 acc_id,
            srv_dtcnt_prof_proxy_info_struct *out_px_info,
            srv_dtcnt_account_enum acc_idx);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_auto_acc_id
 * DESCRIPTION
 *  To get the account id which will be selected by specifed encoded ap_id and smart id.
 *  APP SHOULD prepare the encoded ap_id and account id into acc_id parameter.
 *  Also support dual account case query.
 *  Note: if acc_id encoded by not-smart id, then the account id won't be updated.
 * PARAMETERS
 *  acc_id      :   [IN]        encoded account ID.
 *  acc_id_out  :   [IN/OUT]    transferred account ID output location.
 * RETURNS
 *  SRV_DTCNT_RESULT_FAILED  : Query failed
 *  SRV_DTCNT_RESULT_SUCCESS : Query success
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_get_auto_acc_id(U32 acc_id, U32 *acc_id_out);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_acc_id_by_apn
 * DESCRIPTION
 *  To get the account id by specified apn string
 *  Note: return acc_id_out is encoded by sim id and account id.
 * PARAMETERS
 *  apn         :   [IN]        APN string (ASCII string with NULL terminated)
 *  acc_id_out  :   [IN/OUT]    transferred account ID output location.
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_INVALID_INPUT  : Input invalid
 *  SRV_DTCNT_RESULT_FAILED         : Query failed
 *  SRV_DTCNT_RESULT_SUCCESS        : Query success
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_get_acc_id_by_apn(CHAR *apn, U32 *acc_id_out);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_get_sim_preference
 * DESCRIPTION
 *  To get the SIM preference
 *  Note: If there is not any SIM plug in, get SRV_DTCNT_SIM_TYPE_NONE.
 * PARAMETERS
 *  sim_type    :   [IN/OUT]        SIM preference type
 * RETURN VALUES
 *  MMI_TRUE    :   Get SIM preference successfully
 *  MMI_FALSE   :   Get SIM preference failed
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_get_sim_preference(srv_dtcnt_sim_type_enum *sim_type);

/* DOM-NOT_FOR_SDK-END */


#define SRV_DTCNT_CCA_EXTERNAL

/* DOM-NOT_FOR_SDK-BEGIN */
#ifndef CODEGEN_DTCNT_SRV /* for codegen */
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
/*****************************************************************************
* FUNCTION
*  srv_dtcnt_prov_dm_update_ind
* DESCRIPTION
*  DM -> CCA -> APP, Update Profile Indication
* PARAMETERS
*  appid    :   [IN]    Profile info
*  profid   :   [IN]    profid
*  hconfig  :   [IN]    hconfig
* RETURNS
*  void
*****************************************************************************/
extern void srv_dtcnt_prov_dm_update_ind(U16 appid, S32 profid, S32 hconfig);

/*****************************************************************************
* FUNCTION
*  srv_dtcnt_prov_dm_retrieve_ind
* DESCRIPTION
*  DM -> CCA -> APP, Get Profile Indication
* PARAMETERS
*  appid    :   [IN]    Profile info
*  profid   :   [IN]    profid
* RETURNS
*  void
*****************************************************************************/
extern void srv_dtcnt_prov_dm_retrieve_ind(U16 appid, S32 profid);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_prov_is_cca_target
 * DESCRIPTION
 *  This function examines whether the configuration document has any settings
 *  relevant to data account.
 * PARAMETERS
 *  conf_id     :   [IN]    CCA configuration ID
 *  doc_hdl     :   [IN]    Configuration document handle
 *  data_list   :   [IN]    Level one node IDs and application IDs
 * RETURNS
 *  Return CCA_STATUS_OK if the document is relevant to VoIP data account; 
 *  otherwise, return CCA_STATUS_NOT_FOUND.
 *****************************************************************************/
extern cca_status_enum srv_dtcnt_prov_is_cca_target(
                    U16 conf_id, 
                    S32 doc_hdl,
                    cca_iterator_struct *data_list);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_prov_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to VoIP
 *  data account.
 * PARAMETERS
 *  newConfigDoc    :   [IN]    CCA provided CCA config document struct
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_dtcnt_prov_proc_cca_doc(mmi_cca_app_configure_ind_struct *newConfigDoc);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_prov_wlan_proc_cca_doc
 * DESCRIPTION
 *  This function is responsible for processing a CCA document relevant to WLAN
 *  data account.
 * PARAMETERS
 *  conf_id :   [IN]    CCA configuration ID
 *  doc_hdl :   [IN]    Configuration document handle
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_dtcnt_prov_wlan_proc_cca_doc(U16 conf_id, S32 doc_hdl);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_prov_wlan_is_cca_target
 * DESCRIPTION
 *  This function examines whether the configuration document has any settings
 *  relevant to WLAN data account.
 * PARAMETERS
 *  conf_id     :   [IN]    CCA configuration ID
 *  doc_hdl     :   [IN]    Configuration document handle
 *  data_list   :   [IN]    Level one node IDs and application IDs
 * RETURNS
 *  Return CCA_STATUS_OK if the document is relevant to WLAN data account; 
 *  otherwise, return CCA_STATUS_NOT_FOUND.
 *****************************************************************************/
extern cca_status_enum srv_dtcnt_prov_wlan_is_cca_target(
                    U16 conf_id, 
                    S32 doc_hdl, 
                    cca_iterator_struct *data_list);
#endif /* __CCA_SUPPORT__ */
#endif /* CODEGEN_DTCNT_SRV */
/* DOM-NOT_FOR_SDK-END */

#define SRV_DTCNT_WLAN_EXTERNAL

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_status
 * DESCRIPTION
 *  The function is query the status of WLAN services.
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_dtcnt_wlan_status_enum
 *****************************************************************************/
extern srv_dtcnt_wlan_status_enum srv_dtcnt_wlan_status(void);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_hw_reset_on
 * DESCRIPTION
 *  The function is used to reset WLAN hardware.
 *  If the WLAN previous state is ON, WLAN will be auto turned on after reset.
 * PARAMETERS
 *  callback    :   [IN]    callback function to notify applications the reset on operation is done
 *  user_data   :   [IN]    application piggyback data 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_dtcnt_wlan_hw_reset_on(
        srv_dtcnt_wlan_cb_func_ptr callback,
        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_hw_reset_off
 * DESCRIPTION
 *  The function is used to turn off the WLAN hardware.
 *  After turn off the WLAN hardware, the status will go back to INACTIVE state
 * PARAMETERS
 *  callback    :   [IN]    callback function to notify applications the turn off operation is done
 *  user_data   :   [IN]    application piggyback data 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_dtcnt_wlan_hw_reset_off(
        srv_dtcnt_wlan_cb_func_ptr callback,
        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_get_connected_ap_ssid
 * DESCRIPTION
 *  This API is to get connected AP's SSID.
 *  1. Only dest_len will be copied, and reqired length will be set back to application.
 *  2. Also, if dest = NULL, and req_len exist, DA SRV will return MMI_FALSE
 *     with required length in req_len for application.
 * PARAMETERS
 *  ssid_out    :   [IN/OUT]    ssid info output location
 * RETURN VALUES
 *  MMI_TRUE    :   Get ssid successfully
 *  MMI_FALSE   :   Get ssid failed
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_wlan_get_connected_ap_ssid(
                            srv_dtcnt_prof_str_info_qry_struct *ssid_out);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_get_connected_ap_rssi
 * DESCRIPTION
 *  This API is to get connected AP's signal strength.
 * PARAMETERS
 *  rssi_out    :   [IN/OUT]    rssi info output location
 * RETURN VALUES
 *  MMI_TRUE    :   Get rssi successfully
 *  MMI_FALSE   :   Get rssi failed
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_wlan_get_connected_ap_rssi(S32 *rssi_out);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_get_mac_address
 * DESCRIPTION
 *  The function is used to get MAC address.
 *  1. dest buffer length must be >= WNDRV_MAC_ADDRESS_LEN, i.e. dest_len must 
 *     be >= WNDRV_MAC_ADDRESS_LEN, otherwise DA SRV will return MMI_FALSE 
 *     and reqired length (WNDRV_MAC_ADDRESS_LEN) will be set back to application.
 *  2. Also, if dest = NULL, and req_len exist, DA SRV will return MMI_FALSE
 *     with required length in req_len for application.
 * PARAMETERS
 *  mac_address_out     :   [IN/OUT]    MAC address output location
 * RETURN VALUES
 *  MMI_TRUE    :   Get MAC address successfully
 *  MMI_FALSE   :   Get MAC address failed
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_wlan_get_mac_address(
                            srv_dtcnt_prof_str_info_qry_struct *mac_address_out);

/* DOM-NOT_FOR_SDK-BEGIN */
/* Used for CMCC TD WLAN spec. */
/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_qry_proxy_exclusive_ip_addr
 * DESCRIPTION
 *  The function is used to query IP address in the list which indicate that application need exclude using proxy.
 *  DA SRV will return the IP list in ips array with number in num_ips.
 * PARAMETERS
 *  qry_list    :   [IN]    Proxy exclusive IP address queryed list
 * RETURN VALUES
 *  SRV_DTCNT_RESULT_SUCCESS    :   Query successfully
 *  SRV_DTCNT_RESULT_FAILED     :   Query failed
 *****************************************************************************/
extern srv_dtcnt_result_enum srv_dtcnt_wlan_qry_proxy_exclusive_ip_addr(srv_dtcnt_wlan_proxy_exclusive_ip_addr_qry_struct *qry_list);

/*****************************************************************************
 * FUNCTION
 *  srv_dtcnt_wlan_is_proxy_exclusive_ip_addr
 * DESCRIPTION
 *  This API is to check IP address is in proxy exclusive list.
 * PARAMETERS
 *  exclusive_ip_addr   :   [IN]    IP address
 * RETURN VALUES
 *  MMI_TRUE    :   IP address is in proxy exclusive list
 *  MMI_FALSE   :   IP address is not in proxy exclusive list
 *****************************************************************************/
extern MMI_BOOL srv_dtcnt_wlan_is_proxy_exclusive_ip_addr(srv_dtcnt_wlan_proxy_exclusive_ip_addr_struct *exclusive_ip_addr);
/* DOM-NOT_FOR_SDK-END */

#endif /* _DTCNT_SRV_GPROT_H */ 
