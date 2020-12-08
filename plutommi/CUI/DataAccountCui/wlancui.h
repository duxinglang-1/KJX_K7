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
 *   WLANCui.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Data Account header file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
 
#ifdef __MMI_WLAN_FEATURES__
#ifndef CUI_DTCNT_H
#define CUI_DTCNT_H
#include "MMI_features.h"
#include "DataAccountDef.h"
#include "DataAccountStruct.h"
#include "mmi_res_range_def.h"
#include "MMIDataType.h"
#include "wndrv_cnst.h"
#include "DataAccountEnum.h"

/*******************************************************************************
* Include Header File
*******************************************************************************/

/*******************************************************************************
* Macro Define
*******************************************************************************/
typedef enum
{
    CUI_WLAN_SCREEN_GROUP = DATA_ACCOUNT_BASE + 1,
    CUI_WLAN_SCREEN_GROUP_ALL
} cui_wlan_screen_group_enum;

typedef enum
{
    CUI_WLAN_USER_INFO_USERNAME_STR = 0,
    CUI_WLAN_USER_INFO_USERNAME,
    CUI_WLAN_USER_INFO_PASSWORD_STR,
    CUI_WLAN_USER_INFO_PASSWORD,
    CUI_WLAN_USER_INFO_INLINE_TOTAL
} cui_wlan_user_info_inline_enum;

typedef enum
{
    CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT_STR = 0,
    CUI_WLAN_WAPI_PSK_EDIT_KEY_FORMAT,
    CUI_WLAN_WAPI_PSK_EDIT_KEY_STR,
    CUI_WLAN_WAPI_PSK_EDIT_KEY,
    CUI_WLAN_WAPI_PSK_EDIT_INLINE_TOTAL
} cui_wlan_wapi_psk_edit_inline_enum;

typedef enum
{
    CUI_WLAN_WAPI_EDIT_ASE_CERT_STR = 0,
    CUI_WLAN_WAPI_EDIT_ASE_CERT,
    CUI_WLAN_WAPI_EDIT_USER_CERT_STR,
    CUI_WLAN_WAPI_EDIT_USER_CERT,
    CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD_STR,
    CUI_WLAN_WAPI_EDIT_PRIV_KEY_PASSWD,
    CUI_WLAN_WAPI_EDIT_INLINE_TOTAL
} CUI_wlan_wapi_edit_inline_enum;

typedef enum
{
    CUI_WLAN_AP_LIST_ACTION_CONNECT,
    CUI_WLAN_AP_LIST_ACTION_CANCEL,
    CUI_WLAN_AP_LIST_ACTION_FAILED,
    CUI_WLAN_AP_LIST_ACTION_CLOSE,
    CUI_WLAN_AP_LIST_ACTION_TOTAL
} cui_wlan_ap_list_action;

typedef void (*cui_wlan_ap_list_action_cb_func_ptr) (cui_wlan_ap_list_action action);

typedef struct
{
    U8 valid;
    U8 current_item_selected;
    U8 list_se_num;
    U8 list_sa_num;
    U8 list_se_sa_num;	
    mmi_wlan_wizard_list_struct prof_list[WNDRV_MAX_SCAN_RESULTS_NUM + MAX_WLAN_DATA_ACCOUNT_NUM];
    mmi_wlan_wizard_list_struct se_temp_list[WNDRV_MAX_SCAN_RESULTS_NUM];
    wlan_match_type_enum list_option;

    // mmi_id curr_cui_id;
    mmi_id inline_cui_id;
    mmi_id passphrase_editor_id;
    mmi_id eap_inline_cui_id;
    mmi_id wapi_psk_inline_cui_id;
    mmi_id wapi_cert_inline_cui_id;
}cui_wlan_list_struct;

#ifdef __MMI_OP01_WIFI__
typedef struct
{
    U8 account_name[(SRV_DTCNT_PROF_MAX_ACC_NAME_LEN + 1) * ENCODING_LENGTH];
    U32 profile_id;
} mmi_wlan_disp_name; 

static mmi_wlan_disp_name g_wlan_accnt_name[SRV_DTCNT_PROF_MAX_ACCOUNT_NUM];
static U32 g_mmi_wlan_acct_num;
static U32 g_mmi_wlan_ssid_num;
#endif 

/*******************************************************************************
* Export API 
*******************************************************************************/

#endif /* CUI_CAMERACUI_H */ 

#endif /* __MMI_WLAN_FEATURES__ */
