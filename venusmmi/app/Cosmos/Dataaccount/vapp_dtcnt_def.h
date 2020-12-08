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
 * vapp_dtcnt_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends to define const variable.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 /**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

#ifndef _VAPP_DTCNT_DEF_H
#define _VAPP_DTCNT_DEF_H
/***************************************************************************** 
 * Include
 *****************************************************************************/

extern "C"
{
#include "DtcntSrvGprot.h"
#include "custom_data_account.h"
}
#include "mmi_frm_utility_gprot.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

// url default string
#define VAPP_DTCNT_DEFAULT_URL                       "http://"
#define VAPP_DTCNT_DEFAULT_URL_SIZE                  strlen(MMI_WAP_PROF_DEFAULT_URL)

// sim provisioning profiles + common profiles
#define VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM (SRV_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM + MAX_CSD_SIM_PROV_NUM_PER_SIM + MAX_GPRS_SIM_PROV_NUM_PER_SIM)
#define VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM (VAPP_DTCNT_PROF_MAX_ACCOUNT_NUM_PER_SIM * MMI_SIM_TOTAL)

// ready check function slot
#define DTCNT_READY_CHECK_NUM 10

// max length for account setting attributes
//#define MAX_DIAL_NUM_LEN                    (SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN)
//#define MAX_USER_LEN                        (SRV_DTCNT_PROF_MAX_USER_LEN)
//#define MAX_PASSWD_LEN                      (SRV_DTCNT_PROF_MAX_PW_LEN)
//#define MAX_IPADDRES_LEN                    (SRV_DTCNT_PROF_MAX_IP_ADDR_LEN)
//#define MAX_PROXY_USER_LEN                  (SRV_DTCNT_PROF_MAX_PX_AUTH_ID_LEN)
//#define MAX_PROXY_PASSWD_LEN                (SRV_DTCNT_PROF_MAX_PX_AUTH_PW_LEN)
#define VAPP_DTCNT_MAX_PORT_LENGTH           (5)
#define VAPP_DTCNT_MAX_PORT_NUM              (65535)
#define VAPP_DTCNT_PROVURL_HASH_LEN          (SRV_DTCNT_PROVURL_HASH_LEN)
#define VAPP_DTCNT_NAPID_HASH_LEN            (SRV_DTCNT_NAPID_HASH_LEN)
//#define MAX_GPRS_USERNAME                   (SRV_DTCNT_PROF_MAX_USER_LEN)
//#define MAX_GPRS_USERPASSWD                 (SRV_DTCNT_PROF_MAX_PW_LEN)
//#define MAX_GPRS_MMI_APN_LEN                (SRV_DTCNT_PROF_MAX_APN_LEN)
#define MMI_DTCNT_GENERAL_STRING_LEN    (20)


#define MAX_PART_IP_ADDRESS                  4

// number for kinds of popup selection item
#define DATA_ACCOUNT_SPEED_RATE_TYPE_NUM 5
//#define DATA_ACCOUNT_INLINE_DIAL_TYPE_OPTION 2
//#define DATA_ACCOUNT_INLINE_AUTH_TYPE_OPTION 2
//#define DATA_ACCOUNT_INLINE_CONNECTION_TYPE_OPTION 2
//#define DATA_ACCOUNT_INLINE_USE_PROXY_OPTION 2
//#define DATA_ACCOUNT_INLINE_WAP_PORT_OPTION  2
//#define DATA_ACCOUNT_INLINE_SIM_SELECTION    2
//#define GPRS_DATA_ACCOUNT_INLINE_AUTH_TYPE_OPTION     2

// csd dial rate value
#define DATA_RATE_2400    2400
#define DATA_RATE_4800    4800
#define DATA_RATE_9600    9600
#define DATA_RATE_14400   14400

#if (SRV_DTCNT_PROF_MAX_APN_LEN + 1) > (SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN + 1)
    #define MAX_DTCNT_LIST_ADDR_LEN  (SRV_DTCNT_PROF_MAX_APN_LEN + 1)
#else 
    #define MAX_DTCNT_LIST_ADDR_LEN  (SRV_DTCNT_PROF_MAX_DIAL_NUM_LEN + 1)
#endif

// homepage length
#define MAX_ADDRESS_NAME_LEN 256

// cui item list(NONE, Automatic, ect)
#define MAX_DATA_ACCOUN_CUI_FIX_ITEM     (0)

/*  For all type number */
#define DATA_ACCOUNT_BEARER_TOTAL   3


#endif /* _VAPP_DTCNT_DEF_H */ 


