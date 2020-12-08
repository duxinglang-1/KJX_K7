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
 *  vapp_dtcnt_gprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  This file define inferfaces for other app
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_DTCNT_GPROT_H__
#define __VAPP_DTCNT_GPROT_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMIDatatype.h"
#include "vfx_datatype.h"
#ifdef __cplusplus
extern "C"
{
#endif

#include "DtcntSrvGprot.h"
#include "custom_data_account.h"
#include "cbm_consts.h"

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

// data account name max length
#define DATA_ACCOUNT_NAME_SUFFIX_LEN         7
#ifdef MAX_DATA_ACCOUNT_NAME_LEN
#undef MAX_DATA_ACCOUNT_NAME_LEN
#endif
#define MAX_DATA_ACCOUNT_NAME_LEN            (SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + DATA_ACCOUNT_NAME_SUFFIX_LEN)

/* For CSD type profile */
#define DATA_ACCOUNT_BEARER_CSD  0x01

/* For GPRS type profile */
#define DATA_ACCOUNT_BEARER_GPRS 0x02

/* For WiFi type profile */
#define DATA_ACCOUNT_BEARER_WIFI 0x04

/* For all type profile */
#define DATA_ACCOUNT_BEARER_ALL        DATA_ACCOUNT_BEARER_CSD | DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI

/* Packet Switching Bearer only #define DATA_ACCOUNT_BEARER_PS_ONLY    DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_WIFI */ 
#define DATA_ACCOUNT_BEARER_PS_ONLY    DATA_ACCOUNT_BEARER_GPRS

/* Circuit Switching Bearer only */
#define DATA_ACCOUNT_BEARER_CS_ONLY    DATA_ACCOUNT_BEARER_CSD  

/* Automatic account id */
#define VAPP_DTCNT_AUTOMATIC_ID (0x00003e00 + CBM_DEFAULT_ACCT_ID)


/*******************************************************************************
* Enum 
*******************************************************************************/

// Note: in FTO, not support bearer fallback, so ap just need to use VAPP_DTCNT_GET_ACCT_NAME_TYPE_SINGLE now
typedef enum
{
    VAPP_DTCNT_GET_ACCT_NAME_TYPE_SINGLE, // single account name
    VAPP_DTCNT_GET_ACCT_NAME_TYPE_DUAL,   // dual account name, not support for FTO
    VAPP_DTCNT_GET_ACCT_NAME_TYPE_END
} VappDtcntGetAcctNameTypeEnum;

// valid type for encoded account. In FTO, just use fisrt and none now
typedef enum
{
    DTCNT_ACCT_VALID_FIRST,     /* only for dual account, and first account is valid, second is invalid */
    DTCNT_ACCT_VALID_SECOND,    /* only for dual account, and first account is invalid, second is valid */
    DTCNT_ACCT_VALID_FULL,      /* for single account it stands for valid, for dual account it stands for both accounts are valid */
    DTCNT_ACCT_VALID_NONE,      /* for single account it stands for invalid, for dual account it stands for both accounts are invalid */
    DTCNT_ACCT_VALID_TOTAL
} VappDtcntAcctValidTypeEnum;


/*******************************************************************************
* Export API 
*******************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

// mmi_dtcnt_get_full_account_name
MMI_BOOL vapp_dtcnt_get_full_account_name(
    U32 acctId,                          // account id
    WCHAR *dest,                         // buffer for account name    
    U8 len,                              // length of VfxWChar, not byte length
    VappDtcntGetAcctNameTypeEnum type   // get account name type
);

MMI_BOOL vapp_dtcnt_get_apn_list_ids(
    U32 *ids,  // account id array buffer point
    U32 *num_ids, //number of account ids
    srv_dtcnt_sim_type_enum sim_type //sim info
);

// mmi_dtcnt_acct_is_valid
VappDtcntAcctValidTypeEnum vapp_dtcnt_acct_is_valid(
    U32 encodedAcctId, 
    MMI_BOOL bearerFallback
);


// mmi_dtcnt_ready_check
MMI_BOOL vapp_dtcnt_ready_check(
    FuncPtr readyCallback, // callback function
    MMI_BOOL withScrLock    // need to lock screen or not     
); 


// mmi_dtcnt_subscribe_account
MMI_BOOL vapp_dtcnt_subscribe_account(
    U32 acctOld,     // [IN] encoded old account id
    U32 acctNew,     // [IN] encoded new account id
    U16 appStrId,    // [IN] string id of application
    U16 appIconId    // [IN] icon id of application
);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

// mmi_dtcnt_get_invalid_name_str_id
extern VfxU16 vapp_dtcnt_get_invalid_name_str_id();


// mmi_dtcnt_get_default_name_str_id
extern VfxU16 vapp_dtcnt_get_default_name_str_id();

#endif /* #endif */

#endif /* __VAPP_DTCNT_GPROT_H__ */
