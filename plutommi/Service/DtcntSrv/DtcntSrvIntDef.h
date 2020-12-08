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
 * DtcntSrvIntDef.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is the internal definitions header files of data account services.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DTCNT_SRV_INT_DEF_H
#define _DTCNT_SRV_INT_DEF_H

#include "MMI_features.h"
#include "DtcntSrvIprot.h"

#define SRV_DTCNT_MAX_NODE_ID_LEN       (64)
#define SRV_DTCNT_MAX_WEP_KEY_NUM       (4)

/* Data account Srvice Root Folder */
#define SRV_DTCNT_ROOT_FOLDER             L"z:\\@Dtcnt\\"

/* folder storing all data account profiles */
#define SRV_DTCNT_DB_PATH       (SRV_DTCNT_ROOT_FOLDER L"DB\\")

/* folder storing sim card data account profiles */
#define SRV_DTCNT_SIM_PROF_PATH  (SRV_DTCNT_ROOT_FOLDER L"DB\\SIM\\")

/* folder storing sim card data account profiles */
#define SRV_DTCNT_SIM_PROF_RESET_FILE  (SRV_DTCNT_ROOT_FOLDER L"DB\\SIM\\sim_reset_fact.dat")

/* folder storing user defined data account profiles */
#define SRV_DTCNT_USER_PROF_PATH (SRV_DTCNT_ROOT_FOLDER L"DB\\USER\\")

/* defines the filename that stores the last database operation for implementing atomic database transaction */
#define SRV_DTCNT_ATOMIC_OP_FILENAME    (SRV_DTCNT_ROOT_FOLDER L"atomic_op.dat")

/* defines the filename that stores the last database operation for implementing atomic database transaction */
#define SRV_DTCNT_DB_CONFIG_FILENAME    (SRV_DTCNT_ROOT_FOLDER L"config.dat")

/* data account profile store database information file */
#define SRV_DTCNT_DB_STORE_INFOFILE_NAME    (SRV_DTCNT_ROOT_FOLDER L"DB\\store_info.dat")

/* data account profile store database information backup file */
#define SRV_DTCNT_DB_STORE_INFOFILE_BAK_NAME    (SRV_DTCNT_ROOT_FOLDER L"DB\\store_info.dat.bak")
/* data account profile store database account backup file */
#define SRV_DTCNT_DB_ACC_FILE_BAK_NAME          (SRV_DTCNT_ROOT_FOLDER L"DB\\update_prof.bak")

/* max number of characters of a full filename, not including zero-terminate byte (starting from C:\ to end of file extension) */
#define SRV_DTCNT_DB_FILENAME_LENGTH         260

/* Data account MUTEX */
#define SRV_DTCNT_MUTEX_OP_NAME       "DA SRV Mutex Op"

#define SRV_DTCNT_GLOBAL_LOCK   kal_take_mutex(g_srv_dtcnt_mutex_op)
#define SRV_DTCNT_GLOBAL_UNLOCK kal_give_mutex(g_srv_dtcnt_mutex_op)

/*
#define U64_BIT(n)      ( (kal_uint64)1 << (n) )
#define SRV_DTCNT_DEFAULT_APP_TYPE  U64_BIT(DTCNT_APPTYPE_DEF)
#define SRV_DTCNT_APP_MMS           U64_BIT(DTCNT_APPTYPE_MMS)
#define SRV_DTCNT_APP_BRW_WAP       U64_BIT(DTCNT_APPTYPE_BRW_WAP)
#define SRV_DTCNT_APP_BRW_HTTP      U64_BIT(DTCNT_APPTYPE_BRW_HTTP)
#define SRV_DTCNT_APP_DM            U64_BIT(DTCNT_APPTYPE_DM)
*/

#define DATA_RATE_2400    2400
#define DATA_RATE_4800    4800
#define DATA_RATE_9600    9600
#define DATA_RATE_14400   14400


#ifdef SYNCML_DM_SUPPORT
#if defined (__TCPIP_OVER_CSD__) && defined (__MMI_GPRS_FEATURES__)
#define RESERVED_DM_ACC_NUM (2)
#elif defined (__TCPIP_OVER_CSD__) || defined (__MMI_GPRS_FEATURES__)
#define RESERVED_DM_ACC_NUM (1)
#else /* defined (__TCPIP_OVER_CSD__) || defined (__MMI_GPRS_FEATURES__) */
#define RESERVED_DM_ACC_NUM (0)
#endif /* defined (__TCPIP_OVER_CSD__) || defined (__MMI_GPRS_FEATURES__) */
#else /* !SYNCML_DM_SUPPORT */
#define RESERVED_DM_ACC_NUM (0)
#endif /* SYNCML_DM_SUPPORT */

#if (MMI_MAX_SIM_NUM == 4)
#define SRV_DTCNT_RESERVED_DM_ACC_NUM (RESERVED_DM_ACC_NUM + RESERVED_DM_ACC_NUM + RESERVED_DM_ACC_NUM + RESERVED_DM_ACC_NUM)
#elif (MMI_MAX_SIM_NUM == 3)
#define SRV_DTCNT_RESERVED_DM_ACC_NUM (RESERVED_DM_ACC_NUM + RESERVED_DM_ACC_NUM + RESERVED_DM_ACC_NUM)
#elif (MMI_MAX_SIM_NUM == 2)
#define SRV_DTCNT_RESERVED_DM_ACC_NUM (RESERVED_DM_ACC_NUM + RESERVED_DM_ACC_NUM)
#else
#define SRV_DTCNT_RESERVED_DM_ACC_NUM (RESERVED_DM_ACC_NUM)
#endif /* MMI_MAX_SIM_NUM */

#ifdef __MMI_WLAN_FEATURES__
#define AUTO_POWER_ON

/* WPA, WAPI Cipher type */
#define WPA_CIPHER_NONE             SRV_DTCNT_BIT(0)
#define WPA_CIPHER_WEP40            SRV_DTCNT_BIT(1)
#define WPA_CIPHER_WEP104           SRV_DTCNT_BIT(2)
#define WPA_CIPHER_TKIP             SRV_DTCNT_BIT(3)
#define WPA_CIPHER_CCMP             SRV_DTCNT_BIT(4)
#define WAPI_CIPHER_SMS4	        SRV_DTCNT_BIT(5)

/* WPA authentication algorithm */
#define WPA_AUTH_ALG_OPEN           SRV_DTCNT_BIT(0)
#define WPA_AUTH_ALG_SHARED         SRV_DTCNT_BIT(1)
#define WPA_AUTH_ALG_LEAP           SRV_DTCNT_BIT(2)

/* WPA protocol type */
#define WPA_PROTO_WPA               SRV_DTCNT_BIT(0)
#define WPA_PROTO_RSN               SRV_DTCNT_BIT(1)
#define WPA_PROTO_WAPI              SRV_DTCNT_BIT(2)

#endif /* __MMI_WLAN_FEATURES__ */

#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)

#define SRV_DTCNT_MAX_WLAN_OTA_PROF_NUM     (6)
#define SRV_DTCNT_MIN_PASSPHRASE_LEN        (8)

/* Change max OTA profile# according to max WLAN profile# */
#if SRV_DTCNT_MAX_WLAN_OTA_PROF_NUM > SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM
    #undef  SRV_DTCNT_MAX_WLAN_OTA_PROF_NUM
    #define SRV_DTCNT_MAX_WLAN_OTA_PROF_NUM SRV_DTCNT_MAX_WLAN_ACCOUNT_NUM
#endif

#endif /* defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__) */

#endif /* _DTCNT_SRV_INT_DEF_H */ 
