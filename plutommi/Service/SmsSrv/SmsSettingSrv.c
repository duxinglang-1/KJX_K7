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
 *  SmsSettingSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service Setting Handler
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
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MOD_SMSAL__
/**************************************************************
* Header Files Include
**************************************************************/
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "custom_mmi_default_value.h"
#include "kal_public_api.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "app_ltlcom.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#include "csmcc_enums.h"
#include "stack_msgs.h"
#include "mcd_l4_common.h"
#include "ps_public_enum.h"
#include "ps_public_struct.h"
#include "l4c2abm_struct.h"
#include "l4c_common_enum.h"
#include "stack_timer.h"        /* stack_timer_struct */
#include "l4a.h"                /* L4 data type */
#include "mmi_msg_struct.h"
#include "MMI_common_app_trc.h"

#include "ProtocolEvents.h"
#include "SmsSrvGprot.h"
#include "SmsUtilSrv.h"
#include "SmsStorageCoreSrv.h"

#include "SmsDispatchSrv.h"
#include "GSM7BitDefaultAlphabet.h"
#include "CphsSrvGprot.h"
#ifdef __MMI_MSG_REL4_SUPPORT__
#include "ps_public_utility.h"
#endif 
#include "PhbSrvGprot.h"
#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
#include "Nvram_common_defs.h"
#endif

/**************************************************************
* MARCO
**************************************************************/
#define SRV_SMS_MAX_CPHS_MAILBOX_NUM		2

/**************************************************************
* Structure Declaration
**************************************************************/
typedef struct
{
    srv_sms_sim_enum sim_id;
    MMI_BOOL status_report;
    MMI_BOOL reply_path;
    void *handle_data;
    SrvSmsCallbackFunc callback_func;
    void *user_data;
} srv_sms_setting_handle_struct;

#ifdef __MMI_MSG_REL4_SUPPORT__
typedef struct
{
    U8 mbi_id[4];
} srv_sms_mbi_struct;

typedef struct
{
    U8 mbi_num;
    srv_sms_mbi_struct mbi[SRV_SMS_MAX_MSP_NUM];
} srv_sms_get_mbi_struct;

typedef struct
{
    U8 state;
    U8 is_support_r4;
    U8 msp_no;
    U8 mailbox_num;
    MMI_BOOL need_update_mbi;
    srv_sms_get_mbi_struct mbi_info;
} srv_sms_voicemail_info_struct;

typedef struct
{
    U8 set_index;
    srv_sms_mbi_struct mbi;
} srv_sms_set_mbi_struct;
#endif /* __MMI_MSG_REL4_SUPPORT__ */

#ifdef __MMI_MESSAGES_SMS_EMAIL__
#define MAX_NO_OF_SMS_EMAIL_SC 4
typedef struct
{
    U8 email_addr_no[SRV_SMS_MAX_ADDR_LEN + 1];
} srv_sms_nvram_email_struct;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */ 

typedef struct
{
    MMI_BOOL is_ready;
    srv_sms_setting_struct default_setting;
    srv_sms_mailbox_struct mailbox_info;
} srv_sms_setting_cntx_struct;

typedef enum
{
    SRV_SMS_SIM1_SETTING_7BIT                = 0x01,
    SRV_SMS_SIM1_SETTING_LONG_SMS            = 0x02,
    SRV_SMS_SIM1_SETTING_SAVE_SENT_SMS       = 0x04,
    SRV_SMS_SIM1_SETTING_HILITE_VIEW         = 0x08,

    SRV_SMS_MISCELL_SETTING_END
} srv_sms_miscell_setting_enum;

typedef enum
{
    SRV_SMS_INIT_PROFILE_DETAIL         = 0x0001,
    SRV_SMS_INIT_COMMON_SETTING         = 0x0002,
    SRV_SMS_INIT_MAILBOX_INFO           = 0x0004,
    SRV_SMS_INIT_EMAIL_SC               = 0X0008,

    SRV_SMS_INIT_SETTING_END
} srv_sms_init_setting_require_enum;

/**************************************************************
* Global Variables Declaration
**************************************************************/ 


/**************************************************************
* Extern Function Declaration
**************************************************************/


/**************************************************************
* Static Variables Defination
**************************************************************/
static srv_sms_init_setting_require_enum init_require[MMI_SIM_TOTAL];
static srv_sms_setting_cntx_struct setting_cntx[MMI_SIM_TOTAL];

static srv_sms_mailbox_edit_struct *mailbox_details = NULL;

#ifdef __MMI_MSG_REL4_SUPPORT__
static srv_sms_voicemail_info_struct voicemail_info[MMI_SIM_TOTAL];
#endif

#ifdef __MMI_MESSAGES_SMS_EMAIL__
U8 g_srv_sms_email_pid = 0;
U8 g_srv_sms_email_pid_tmp = 0;
static U8 profile_index = 0;
static CHAR email_sc_addr[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */ 

/**************************************************************
* Static Function Declaration
**************************************************************/
static void srv_sms_get_profile_list(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_get_profile_list_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_get_profile_name_req(
                srv_sms_sim_enum sim_id,
                srv_sms_profile_list_struct *profile_list,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_get_profile_name_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_set_active_profile(
                U8 *index,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data); // active index need callback
static void srv_sms_update_default_profile_setting(srv_sms_callback_struct* callback_data);
static void srv_sms_set_default_profile_setting(srv_sms_sim_enum sim_id, srv_sms_profile_struct *profile);
static void srv_sms_get_sc_addr(
                U8 *index,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_get_sc_addr_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_set_sc_addr(
                srv_sms_edit_sc_struct *sc_info,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_set_sc_addr_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_set_active_sc_addr(
                U8 sc_addr[],
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_get_active_sc_addr(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_get_profile_detail(
                U8 *index,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_get_profile_detail_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_set_profile_partial(
                srv_sms_profile_ext_struct *profile_detail,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_set_profile_detail(
                srv_sms_profile_struct *profile_detail,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_set_profile_detail_callback(srv_sms_disp_cb_struct *callback_data);

static void srv_sms_get_common_settings(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_get_common_settings_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_set_common_settings(
                U8 commmon_setting[SRV_SMS_COMMON_SETTING_NUM],
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_set_common_settings_callback(srv_sms_disp_cb_struct *callback_data);

static void srv_sms_set_msg_waiting(
                srv_sms_msg_waiting_struct *msg_waiting,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_set_msg_waiting_callback(srv_sms_disp_cb_struct *callback_data);

#if defined(__MMI_GPRS_FEATURES__)
static void srv_sms_get_preferred_bearer(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_get_preferred_bearer_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_set_preferred_bearer(
                U8 *bearer,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_set_preferred_bearer_callback(srv_sms_disp_cb_struct *callback_data);
#endif /* defined(__MMI_GPRS_FEATURES__) */

static void srv_sms_get_mailbox_info_req(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);


#ifdef __MMI_MSG_REL4_SUPPORT__
static void srv_sms_get_mbi_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_get_mbi_info_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_set_mbi_info(
                srv_sms_set_mbi_struct *mbi_info,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_set_mbi_info_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_get_msp_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_get_msp_info_callback(srv_sms_disp_cb_struct *callback_data);

static void srv_sms_set_msp_info(
                U8 *select_index,
                srv_sms_sim_enum sim_id, 
                SrvSmsCallbackFunc callback_func,
                void *user_data);
void srv_sms_set_msp_info_callback(srv_sms_disp_cb_struct *callback_data);
#endif /* __MMI_MSG_REL4_SUPPORT__ */ 

#ifdef __MMI_MSG_REL4_SUPPORT__
static void srv_sms_get_voicemail_number(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_set_voicemail_number(
                srv_sms_mailbox_edit_struct *mailbox,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_vm_get_mbi_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_vm_get_mbi_info_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_vm_get_mailbox_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_vm_get_mailbox_info_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_vm_get_msp_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_vm_get_msp_info_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_vm_get_mailbox_num(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_vm_get_mailbox_num_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_vm_set_mailbox_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_vm_set_mailbox_info_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_vm_set_mbi_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_vm_set_mbi_info_callback(srv_sms_disp_cb_struct *callback_data);
#else /* __MMI_MSG_REL4_SUPPORT__ */
static void srv_sms_get_voicemail_number(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_get_voicemail_number_callback(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_set_voicemail_number(
                srv_sms_mailbox_edit_struct *mailbox,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_set_voicemail_number_callback(srv_sms_disp_cb_struct *callback_data);
#endif /* __MMI_MSG_REL4_SUPPORT__ */

#ifdef __MMI_MESSAGES_SMS_EMAIL__
static void srv_sms_get_active_email_sc_addr(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_set_active_email_sc_addr(
            U8 sc_addr[],
            SrvSmsCallbackFunc callback_func,
            void *user_data);
static void srv_sms_get_sms_pid_req(U8 index, srv_sms_sim_enum sim_id);
static void srv_sms_get_sms_pid_rsp(srv_sms_disp_cb_struct *callback_data);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

static MMI_BOOL srv_sms_get_miscell_setting(srv_sms_sim_enum sim_id, srv_sms_miscell_setting_enum type);
static MMI_BOOL srv_sms_set_miscell_setting(srv_sms_sim_enum sim_id, srv_sms_miscell_setting_enum type, MMI_BOOL flag);
static void srv_sms_setting_callback(
                MMI_BOOL result,
                void *action_data,
                SrvSmsCallbackFunc callback_func,
                void *user_data);
static void srv_sms_init_sim_setting(srv_sms_sim_enum sim_id);
static U16 srv_sms_setting_get_profile_data_id(srv_sms_sim_enum sim_id);
static void srv_sms_pre_init_profile_detail(srv_sms_disp_cb_struct *callback_data);
static void srv_sms_init_profile_detail(srv_sms_callback_struct* callback_data);
static void srv_sms_init_common_settings(srv_sms_callback_struct* callback_data);
static void srv_sms_init_mailbox_info(srv_sms_callback_struct* callback_data);
#ifdef __MMI_MESSAGES_SMS_EMAIL__
static void srv_sms_init_email_sc_address(srv_sms_callback_struct* callback_data);
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */

/**************************************************************
* Function Defination
**************************************************************/


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_default_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const srv_sms_setting_struct* srv_sms_get_default_setting(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_sms_sim_id_to_sim_index(sim_id);

    return &(setting_cntx[index].default_setting);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_default_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const char* srv_sms_get_email_sc_address(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    return email_sc_addr;
#else
    return NULL;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_prefer_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_storage_enum srv_sms_get_prefer_storage(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_PREFER_STORAGE_SETTING__
    U8 index;
    srv_sms_storage_enum storage_type = SRV_SMS_STORAGE_UNSPECIFIC;
    S16 erro_code;
#endif /* __SRV_SMS_PREFER_STORAGE_SETTING__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_PREFER_STORAGE_TYPE, sim_id);

#ifdef __SRV_SMS_PREFER_STORAGE_SETTING__
    ReadValue(NVRAM_SMS_PREFER_STORAGE, &index, DS_BYTE, &erro_code);

#if defined(__OP01__) && (MMI_MAX_SIM_NUM == 2)
	if (sim_id == SRV_SMS_SIM_2)
	{
		storage_type = (srv_sms_storage_enum)(index >> 4);
	}
	else
#endif
    {
    	storage_type = (srv_sms_storage_enum)(index & 0x0F);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_PREFER_STORAGE_TYPE_1, index);
    
    /* If the value is invalid */
    if ((storage_type != SRV_SMS_STORAGE_ME) && (storage_type != SRV_SMS_STORAGE_SIM)
    #ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
        && (storage_type != SRV_SMS_STORAGE_TCARD)
    #endif
        )
    {
    #ifdef __SRV_SMS_SIM_MEMORY_BASE__
    #if defined(__UNIFIED_MESSAGE_SIMBOX_SUPPORT__) && !defined(__OP01__)
        storage_type = SRV_SMS_STORAGE_ME;
    #else
        storage_type = SRV_SMS_STORAGE_SIM;
    #endif
    #else /* __SRV_SMS_SIM_MEMORY_BASE__ */
        storage_type = SRV_SMS_STORAGE_ME;
    #endif /* __SRV_SMS_SIM_MEMORY_BASE__ */
        
        /* Write the Default Value */
	#if defined(__OP01__) && (MMI_MAX_SIM_NUM == 2)
		if (sim_id == SRV_SMS_SIM_2)
		{
			index = (index & 0x0F) | (storage_type << 4);
		}
		else
	#endif
	    {
        	index = (index & 0xF0) | storage_type;
		}
        
        WriteValue(NVRAM_SMS_PREFER_STORAGE, &index, DS_BYTE, &erro_code);
    }
    return storage_type;

#else /* __SRV_SMS_PREFER_STORAGE_SETTING__ */

#ifdef __SRV_SMS_SIM_MEMORY_BASE__
    return SRV_SMS_STORAGE_SIM;
#else /* __SRV_SMS_SIM_MEMORY_BASE__ */
    return SRV_SMS_STORAGE_ME;
#endif /* __SRV_SMS_SIM_MEMORY_BASE__ */

#endif /* __SRV_SMS_PREFER_STORAGE_SETTING__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_prefer_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_set_prefer_storage(srv_sms_storage_enum type, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __SRV_SMS_PREFER_STORAGE_SETTING__
    U8 index;
    S16 erro_code;
#endif /* __SRV_SMS_PREFER_STORAGE_SETTING__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_PREFER_STORAGE_TYPE, type, sim_id);

#ifdef __SRV_SMS_PREFER_STORAGE_SETTING__
    ReadValue(NVRAM_SMS_PREFER_STORAGE, &index, DS_BYTE, &erro_code);

#if defined(__OP01__) && (MMI_MAX_SIM_NUM == 2)
	if (sim_id == SRV_SMS_SIM_2)
	{
		index = (type << 4) | (index & 0x0F);
	}
    else
#endif
	{
	    index = type | (index &0xF0);
	}

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_PREFER_STORAGE_TYPE_1, index);

    WriteValue(NVRAM_SMS_PREFER_STORAGE, &index, DS_BYTE, &erro_code);
    return MMI_TRUE;

#else /* __SRV_SMS_PREFER_STORAGE_SETTING__ */
    return MMI_FALSE;
#endif /* __SRV_SMS_PREFER_STORAGE_SETTING__ */
}


#ifdef __SRV_SMS_TCARD_STORAGE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msg_filter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
srv_sms_filter_enum srv_sms_get_storage_filter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 erro_code;
    U8 filter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SMS_STORAGE_FILTER, &filter, DS_BYTE, &erro_code);
    filter = filter & SRV_SMS_FILTER_ALL;
    kal_prompt_trace(MOD_MMI,"[SMS][TCARD] srv_sms_get_storage_filter,filter = %d",filter);
    if (filter & SRV_SMS_FILTER_ALL)
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        {
            return (srv_sms_filter_enum)filter;
        }
    	
    }
    else
    {
        filter = SRV_SMS_FILTER_ALL;

        WriteValue(NVRAM_SMS_STORAGE_FILTER, &filter, DS_BYTE, &erro_code);

        return SRV_SMS_FILTER_ALL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_prefer_storage
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_set_storage_filter(srv_sms_filter_enum filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;
    S16 erro_code;
    srv_sms_event_refresh_struct event;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    filter = filter & SRV_SMS_FILTER_ALL;
    kal_prompt_trace(MOD_MMI,"[SMS][TCARD] srv_sms_set_storage_filter,filter = %d",filter);
	if (filter & SRV_SMS_FILTER_ALL)
    {

		WriteValue(NVRAM_SMS_STORAGE_FILTER, &filter, DS_BYTE, &erro_code);
        srv_sms_set_show_list(SRV_SMS_BOX_INBOX);
        srv_sms_set_show_list(SRV_SMS_BOX_OUTBOX);
        srv_sms_set_show_list(SRV_SMS_BOX_DRAFTS);
#ifdef __SRV_SMS_UNSENT_LIST__
        srv_sms_set_show_list(SRV_SMS_BOX_UNSENT);
#endif
        srv_sms_emit_event(EVT_ID_SRV_SMS_REFRESH_MSG,&event);
        return MMI_TRUE;
	}
    else
    {
        return MMI_FALSE;
    }

   
    
    
}
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_setting_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
void srv_sms_get_setting_para(
            srv_sms_setting_type_enum type,
            void* get_data,
            srv_sms_sim_enum sim_id,
            SrvSmsCallbackFunc callback_func,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_SETTING_PARA, type);

    switch(type)
    {
        case SRV_SMS_GET_PROFILE_LIST:
            srv_sms_get_profile_list(sim_id, callback_func, user_data);
            break;

        case SRV_SMS_EDIT_SC_ADDR:
            srv_sms_get_sc_addr((U8*)get_data, sim_id, callback_func, user_data);
            break;

        case SRV_SMS_ACTIVE_SC_ADDR:         /* set U8 sc_addr[], get */
            srv_sms_get_active_sc_addr(sim_id, callback_func, user_data);
            break;
            
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        case SRV_SMS_ACTIVE_EMAIL_SC_ADDR:   /* set U8 email_sc_addr[], get */
            srv_sms_get_active_email_sc_addr(sim_id, callback_func, user_data);
            break;
    #endif

        case SRV_SMS_PROFILE_DETAIL:         /* set srv_sms_profile_struct, get U8 index */
            srv_sms_get_profile_detail((U8*)(get_data), sim_id, callback_func, user_data);
            break;

        case SRV_SMS_COMMON_SETTINGS:        /* set U8 setting[], get */ 
            srv_sms_get_common_settings(sim_id, callback_func, user_data);
            break;

        case SRV_SMS_GET_MEMORY_STATUS:      /* get srv_sms_memory_status_struct */
            get_data = OslMalloc(sizeof(srv_sms_memory_status_struct));
            result = srv_sms_get_memory_status(sim_id, (srv_sms_memory_status_struct*)get_data);
            srv_sms_setting_callback(result, (void*)get_data, callback_func, user_data);
            OslMfree(get_data);
            break;

        case SRV_SMS_PRE_STORAGE:            /* set U8 storage, get */
            {
                U8 storage;
                storage = srv_sms_get_prefer_storage(sim_id);
                srv_sms_setting_callback(
                    MMI_TRUE,
                    (void*)&storage,
                    callback_func,
                    user_data);
            }
            break;
    

    #ifdef __MMI_GPRS_FEATURES__
        case SRV_SMS_PRE_BEARER:             /* set U8 bearer, get */
            srv_sms_get_preferred_bearer(sim_id, callback_func, user_data);
            break;
    #endif

    #ifdef __MMI_MSG_REL4_SUPPORT__
        case SRV_SMS_MBI:                    /* set srv_sms_set_mbi_struct, get */
            srv_sms_get_mbi_info(sim_id, callback_func, user_data);
            break;

        case SRV_SMS_MSP:                    /* set U8 select_index, get */
            srv_sms_get_msp_info(sim_id, callback_func, user_data);
            break;
    #endif /* __MMI_MSG_REL4_SUPPORT__ */

        case SRV_SMS_MAILBOX_INFO:
        case SRV_SMS_VOICEMAIL_NUM:          /* set srv_sms_mailbox_struct, get */
            srv_sms_get_mailbox_info_req(sim_id, callback_func, user_data);
            break;

        default:
            break;
    }

}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_setting_para
 * DESCRIPTION
 *  Only set SRV_SMS_LONG_SMS_DYNAMIC_SEG and SRV_SMS_SAVE_SENT_SMS can return right
 *  value, others will always return MMI_TRUE.
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_set_setting_para(
            srv_sms_setting_type_enum type,
            void* set_data,
            srv_sms_sim_enum sim_id,
            SrvSmsCallbackFunc callback_func,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_SETTING_PARA, type);

    switch(type)
    {
        case SRV_SMS_SET_ACTIVE_PROFILE:     /* set U8 index */
            srv_sms_set_active_profile((U8*)set_data, sim_id, callback_func, user_data);
            break;

        case SRV_SMS_EDIT_SC_ADDR:
            srv_sms_set_sc_addr((srv_sms_edit_sc_struct*)set_data, sim_id, callback_func, user_data);
            break;

        case SRV_SMS_ACTIVE_SC_ADDR:         /* set U8 sc_addr[], get */
            srv_sms_set_active_sc_addr((U8*)set_data, sim_id, callback_func, user_data);
            break;
            
    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        case SRV_SMS_ACTIVE_EMAIL_SC_ADDR:   /* set U8 email_sc_addr[], get */
            srv_sms_set_active_email_sc_addr((U8*)set_data, callback_func, user_data);
            break;
    #endif

        case SRV_SMS_PROFILE_DETAIL:         /* set srv_sms_profile_struct, get U8 index */
            srv_sms_set_profile_detail((srv_sms_profile_struct*)set_data, sim_id, callback_func, user_data);
            break;
            
        case SRV_SMS_COMMON_SETTINGS:        /* set U8 setting[], get */ 
            srv_sms_set_common_settings((U8*)set_data, sim_id, callback_func, user_data);
            break;
             
        case SRV_SMS_PRE_STORAGE:            /* set U8 storage, get */
            {
                MMI_BOOL result;
                srv_sms_storage_enum storage_type = *(srv_sms_storage_enum*)set_data;
                result = srv_sms_set_prefer_storage(storage_type, sim_id);
                srv_sms_setting_callback(
                    result,
                    (void*)&storage_type,
                    callback_func,
                    user_data);
            }
            break;

    #ifdef __MMI_GPRS_FEATURES__
        case SRV_SMS_PRE_BEARER:             /* set U8 bearer, get */
            srv_sms_set_preferred_bearer((U8*)set_data, sim_id, callback_func, user_data);
            break;
    #endif

    #ifdef __MMI_MSG_REL4_SUPPORT__           
        case SRV_SMS_MBI:                    /* set srv_sms_set_mbi_struct, get */
            srv_sms_set_mbi_info((srv_sms_set_mbi_struct*)set_data, sim_id, callback_func, user_data);
            break;
            
        case SRV_SMS_MSP:                    /* set U8 select_index, get */
            srv_sms_set_msp_info((U8*)set_data, sim_id, callback_func, user_data);
            break;
    #endif /* __MMI_MSG_REL4_SUPPORT__ */

        case SRV_SMS_MAILBOX_INFO:
        case SRV_SMS_VOICEMAIL_NUM:          /* set srv_sms_mailbox_struct, get */
            srv_sms_set_voicemail_number((srv_sms_mailbox_edit_struct*)set_data, sim_id, callback_func, user_data);
            break;
            
        case SRV_SMS_SET_MSG_WAITING:        /* set srv_sms_msg_waiting_struct */
            srv_sms_set_msg_waiting((srv_sms_msg_waiting_struct*)set_data, sim_id, callback_func, user_data);
            break;

        case SRV_SMS_PROFILE_DETAIL_PARTIAL:
            srv_sms_set_profile_partial((srv_sms_profile_ext_struct*)set_data, sim_id, callback_func, user_data);
            break;

        default:
            break;      
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_profile_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_profile_list(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_PROFILE_LIST, sim_id);

    handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));
    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_PROFILE_NUM,
        0,
        0,
        sim_id,
        srv_sms_get_profile_list_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_profile_list_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_profile_list_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    mmi_sms_get_profile_num_rsp_struct *msgRsp = (mmi_sms_get_profile_num_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    srv_sms_profile_list_struct *profile_list = OslMalloc(sizeof(srv_sms_profile_list_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_PROFILE_LIST_CALLBACK, msgRsp->result);

    MMI_ASSERT(profile_list != NULL);

    profile_list->cur_max_ps_profiles = 0;
    profile_list->cur_req_profile_no = 0;

    if (msgRsp->result == MMI_TRUE)
    {
        profile_list->cur_max_ps_profiles = msgRsp->profile_no;
        profile_list->profile_name_len = msgRsp->name_len;

        if (profile_list->profile_name_len > SRV_SMS_MAX_PROFILE_NAME_LEN)
        {
            profile_list->profile_name_len = SRV_SMS_MAX_PROFILE_NAME_LEN;
        }
    }

    if (profile_list->cur_max_ps_profiles == 0)
    {
        srv_sms_setting_callback(
            msgRsp->result,
            (void*)profile_list,
            handle->callback_func,
            handle->user_data);

        OslMfree(profile_list);
    }
    else
    {
        srv_sms_get_profile_name_req(handle->sim_id, profile_list, handle->callback_func, handle->user_data);
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_profile_name_req
 * DESCRIPTION
 *  Get profile name request
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_profile_name_req(
                srv_sms_sim_enum sim_id,
                srv_sms_profile_list_struct *profile_list,
                SrvSmsCallbackFunc callback_func,
                void *user_data)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = profile_list->cur_req_profile_no;
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_PROFILE_NAME_REQ, sim_id, record_index);

    handle->sim_id = sim_id;
    handle->handle_data = profile_list;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_DETAIL_FROFILE,
        record_index,
        0,
        sim_id,
        srv_sms_get_profile_name_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_profile_name_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_profile_name_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_sms_get_profile_params_rsp_struct *msgRsp = (mmi_sms_get_profile_params_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    srv_sms_profile_list_struct *profile_list = handle->handle_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_PROFILE_NAME_CALLBACK, msgRsp->result);

    if (msgRsp->result == MMI_TRUE)
    {
        U16 temp_buf[SRV_SMS_MAX_PROFILE_NAME_LEN+1];
        U8 pf_name_dcs = msgRsp->profile_name.name_dcs;
        U8 pf_name_len = msgRsp->profile_name.name_length;

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        {
            S16 error_code;
            CHAR active_profile_index;

            ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &active_profile_index, DS_BYTE, &error_code);

            if (active_profile_index >= profile_list->cur_max_ps_profiles)
            {
                active_profile_index = 0;
            }
            if (active_profile_index == profile_list->cur_req_profile_no)
            {
                g_srv_sms_email_pid = msgRsp->pid;
            }
        }
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */ 

        memset(temp_buf, 0x0, (SRV_SMS_MAX_PROFILE_NAME_LEN+1)*ENCODING_LENGTH);

        if (pf_name_len > 0)
        {
            U8* pf_name = msgRsp->profile_name.name;

            /* add null terminator */
            if (pf_name_dcs == SMSAL_DEFAULT_DCS)
            {
                if (pf_name_len < 42)
                {
                    pf_name[pf_name_len] = '\0';
                }
                else
                {
                    pf_name[42] = '\0';
                }
            }
            else
            {
                if ((pf_name_len + 1) < 42)
                {
                    pf_name[pf_name_len] = '\0';
                    pf_name[pf_name_len + 1] = '\0';
                }
            }

            InputboxConvertGSMToDeviceEncoding(
                pf_name,
                (U8*)temp_buf,
                pf_name_len,
                (SRV_SMS_MAX_PROFILE_NAME_LEN +1)*ENCODING_LENGTH,
                pf_name_dcs,
                0,
                1);
        }

        memcpy((CHAR*) profile_list->profile_name[profile_list->cur_req_profile_no], temp_buf, (SRV_SMS_MAX_PROFILE_NAME_LEN +1)*ENCODING_LENGTH);

        profile_list->cur_req_profile_no++;
    }

    if ((profile_list->cur_req_profile_no >= profile_list->cur_max_ps_profiles) || (msgRsp->result == MMI_FALSE))
    {
        if (profile_list->cur_max_ps_profiles > 0)
        {
            S16 error_code = 0;
            U16 item_id = srv_sms_setting_get_profile_data_id(handle->sim_id);

            ReadValue(item_id, &(profile_list->cur_req_profile_no), DS_BYTE, &error_code);

            if (profile_list->cur_req_profile_no>= profile_list->cur_max_ps_profiles)
            {
                profile_list->cur_req_profile_no = 0;

                WriteValue(item_id, &(profile_list->cur_req_profile_no), DS_BYTE, &error_code);     
            }
        }

        srv_sms_setting_callback(
            msgRsp->result,
            (void*)profile_list,
            handle->callback_func,
            handle->user_data);

         OslMfree(profile_list);
    }
    else
    {
        srv_sms_get_profile_name_req(
            handle->sim_id,
            profile_list,
            handle->callback_func,
            handle->user_data);
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_active_profile
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_active_profile(
                U8 *index,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode;
    U16 item_id;
    U8 record_index = *index;
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_ACTIVE_PROFILE, sim_id, *index);

    item_id = srv_sms_setting_get_profile_data_id(sim_id);

    WriteValue(item_id, &record_index, DS_BYTE, &errorCode);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    srv_sms_get_sms_pid_req(*index, sim_id);
#endif 

    srv_sms_setting_callback(MMI_TRUE, &record_index, callback_func, user_data);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    srv_sms_get_active_email_sc_addr(sim_id, NULL, NULL);
#endif

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = NULL;
    handle->user_data = NULL;

    srv_sms_get_profile_detail(&record_index, sim_id, srv_sms_update_default_profile_setting, (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_update_default_profile_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_update_default_profile_setting(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_profile_struct *msgRsp = (srv_sms_profile_struct*) callback_data->action_data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_UPDATE_DEFALT_PROFILE_SETTING, callback_data->result);

    if (callback_data->result == MMI_TRUE)
    {
        srv_sms_set_default_profile_setting(handle->sim_id, msgRsp);
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_default_profile_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_set_default_profile_setting(srv_sms_sim_enum sim_id, srv_sms_profile_struct *profile)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 addr_len;
    U32 index;
    srv_sms_setting_struct *default_profile;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_sms_sim_id_to_sim_index(sim_id);

    default_profile = &(setting_cntx[index].default_setting);

    addr_len = mmi_ucs2_n_to_asc(default_profile->sc_addr, (CHAR*)(profile->sc_addr), SRV_SMS_MAX_ADDR_LEN *ENCODING_LENGTH);
    if (addr_len > SRV_SMS_MAX_ADDR_LEN)
    {
        addr_len = SRV_SMS_MAX_ADDR_LEN;
    }
    default_profile->sc_addr[addr_len] = '\0';

    mmi_ucs2ncpy((CHAR*)default_profile->profile_name, (CHAR*)(profile->profile_name), SRV_SMS_MAX_PROFILE_NAME_LEN);

    default_profile->vp =  (srv_sms_vp_enum)profile->vp_index;
    default_profile->pid =  (srv_sms_pid_enum)profile->msg_type_index;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_sc_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_sc_addr(
                U8 *index,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = *(U16*)index;
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_SC_ADDR, sim_id, record_index);

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_DETAIL_FROFILE,
        record_index,
        0,
        sim_id,
        srv_sms_get_sc_addr_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_sc_addr_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_sc_addr_callback(srv_sms_disp_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_profile_params_rsp_struct *msgRsp = (mmi_sms_get_profile_params_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    U8 sc_address[SRV_SMS_MAX_ADDR_LEN + 1];
    srv_sms_profile_struct *profile_detail = OslMalloc(sizeof(srv_sms_profile_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_SC_ADDR_CALLBACK, msgRsp->result);

    if (msgRsp->result == MMI_TRUE)
    {
        srv_sms_convert_l4_num_to_ascii_num(sc_address, &msgRsp->sc_addr, SRV_SMS_MAX_ADDR_LEN);

        mmi_asc_to_ucs2((CHAR*)profile_detail->sc_addr, (CHAR*)sc_address);
    }

    srv_sms_setting_callback(
        msgRsp->result,
        (void*)profile_detail->sc_addr,
        handle->callback_func,
        handle->user_data);

    if (profile_detail != NULL)
    {
        OslMfree(profile_detail);
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_sc_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_sc_addr(
                srv_sms_edit_sc_struct *sc_info,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));
    mmi_sms_set_profile_params_req_struct *msgReq;
    CHAR sc_address[SRV_SMS_MAX_ADDR_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_SC_ADDR, sim_id);

    mmi_ucs2_to_asc(sc_address, (CHAR*)sc_info->sc_addr);

    msgReq = (mmi_sms_set_profile_params_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    srv_sms_convert_ascii_num_to_l4_num(&msgReq->sc_addr, (U8*)sc_address);
    msgReq->profile_no = sc_info->index;
    msgReq->para_ind = SMSAL_PARA_SCA;

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_write_sim_req(
        SRV_SMS_FILE_DETAIL_FROFILE,
        0,
        sizeof(mmi_sms_set_profile_params_req_struct),
        (void*)msgReq,
        sim_id,
        srv_sms_set_sc_addr_callback,
        (void*)handle);

    OslMfree(msgReq);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_sc_addr_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_set_sc_addr_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_profile_params_rsp_struct *msgRsp = (mmi_sms_set_profile_params_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_SC_ADDR_CALLBACK, msgRsp->result);

    srv_sms_setting_callback(
        msgRsp->result,
        NULL,
        handle->callback_func,
        handle->user_data);

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_active_sc_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_active_sc_addr(
                U8 sc_addr[],
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index;
    U16 item_id;
    S16 error_code;
    srv_sms_edit_sc_struct sc_info;
    CHAR nvram_active_profile_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_ACTIVE_PROFILE_SC, sim_id, sc_addr);

    item_id = srv_sms_setting_get_profile_data_id(sim_id);
    
    ReadValue(item_id, &nvram_active_profile_index, DS_BYTE, &error_code);

    sc_info.index = nvram_active_profile_index;
    mmi_ucs2ncpy((CHAR*)sc_info.sc_addr, (CHAR*)sc_addr, SRV_SMS_MAX_ADDR_LEN);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    mmi_ucs2_to_asc(setting_cntx[index].default_setting.sc_addr, (CHAR*)sc_info.sc_addr); 

    srv_sms_set_sc_addr(&sc_info, sim_id, callback_func, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_active_sc_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_active_sc_addr(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error_code;
    U16 item_id;
    CHAR nvram_active_profile_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_ACTIVE_PROFILE_SC, sim_id);

    item_id = srv_sms_setting_get_profile_data_id(sim_id);
    
    ReadValue(item_id, &nvram_active_profile_index, DS_BYTE, &error_code);

    srv_sms_get_sc_addr((U8*)(&nvram_active_profile_index), sim_id, callback_func, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_profile_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_profile_detail(
                U8 *index,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 record_index = (U16)*index;
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_PROFILE_DETAIL, sim_id, record_index);

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    profile_index = *index;       /* ?????  */
#endif 

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_DETAIL_FROFILE,
        record_index,
        0,
        sim_id,
        srv_sms_get_profile_detail_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_profile_detail_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_profile_detail_callback(srv_sms_disp_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_profile_params_rsp_struct *msgRsp = (mmi_sms_get_profile_params_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    srv_sms_profile_struct *profile_detail = OslMalloc(sizeof(srv_sms_profile_struct));
    MMI_BOOL result = msgRsp->result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_PROFILE_DETAIL_CALLBACK, msgRsp->result);

    if (result == MMI_TRUE)
    {
        U16 temp_buf[SRV_SMS_MAX_PROFILE_NAME_LEN +1];
        U8 sc_address[SRV_SMS_MAX_ADDR_LEN + 1];
        U8 pf_name_dcs = msgRsp->profile_name.name_dcs;
        U8 pf_name_len = msgRsp->profile_name.name_length;

         memset(temp_buf, 0x0, (SRV_SMS_MAX_PROFILE_NAME_LEN+1)*ENCODING_LENGTH);

        if (pf_name_len > 0)
        {
            U8* pf_name = msgRsp->profile_name.name;

            /* add null terminator */
            if (pf_name_dcs == SMSAL_DEFAULT_DCS)
            {
                if (pf_name_len < 42)
                {
                    pf_name[pf_name_len] = '\0';
                }
                else
                {
                    pf_name[42] = '\0';
                }
            }
            else
            {
                if ((pf_name_len + 1) < 42)
                {
                    pf_name[pf_name_len] = '\0';
                    pf_name[pf_name_len + 1] = '\0';
                }
            }

            InputboxConvertGSMToDeviceEncoding(
                pf_name,
                (U8*)temp_buf,
                pf_name_len,
                (SRV_SMS_MAX_PROFILE_NAME_LEN +1)*ENCODING_LENGTH,
                pf_name_dcs,
                0,
                1);
        }

        memcpy(profile_detail->profile_name, temp_buf, (SRV_SMS_MAX_PROFILE_NAME_LEN +1)*ENCODING_LENGTH);
        profile_detail->profile_name_dcs = pf_name_dcs;

        profile_detail->vp_index = (U32) msgRsp->vp;
        profile_detail->msg_type_index = (U32) msgRsp->pid;

        srv_sms_convert_l4_num_to_ascii_num(sc_address, &msgRsp->sc_addr, SRV_SMS_MAX_ADDR_LEN);
        mmi_asc_to_ucs2((CHAR*)profile_detail->sc_addr, (CHAR*)sc_address);

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        {
            S16 error_code;
            srv_sms_nvram_email_struct info_struct;

            if (ReadRecord
                (NVRAM_EF_SMS_EMAIL_LID, (U16) (profile_index + 1), (void*)info_struct.email_addr_no,
                 NVRAM_SMS_EMAIL_RECORD_SIZE, &error_code) < 0)
            {
                email_sc_addr[0] = '\0';
                result = MMI_FALSE;
            }
            else
            {
                mmi_asc_n_to_ucs2(email_sc_addr, (CHAR*) info_struct.email_addr_no, strlen(info_struct.email_addr_no));
                memcpy(profile_detail->email_addr,  email_sc_addr, (SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH);
            }
        }
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */ 
    }

    srv_sms_setting_callback(
        result,
        (void*)profile_detail,
        handle->callback_func,
        handle->user_data);

    OslMfree(profile_detail);

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_profile_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_profile_partial(
                srv_sms_profile_ext_struct *profile_detail,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));
    mmi_sms_set_profile_params_req_struct *msgReq;
    srv_sms_profile_ext_struct *ext_profile = OslMalloc(sizeof(srv_sms_profile_ext_struct));
    U8 para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_PROFILE_DETAIL, sim_id);

    memcpy(ext_profile, profile_detail, sizeof(srv_sms_profile_ext_struct));
    para = ext_profile->para;

    msgReq = (mmi_sms_set_profile_params_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->para_ind = 0;

    if (para&SRV_SMS_PROFILE_VP)
    {
        msgReq->vp = ext_profile->vp_index;
        msgReq->para_ind |= SMSAL_PARA_VP;
    }

    if (para&SRV_SMS_PROFILE_PID)
    {
        msgReq->pid = ext_profile->msg_type_index;
        msgReq->para_ind |= SMSAL_PARA_PID;
    }

    if (para & SRV_SMS_PROFILE_NAME)
    {
        if (ext_profile->profile_name_dcs == PHB_UCS2)
        {
            msgReq->profile_name.name_dcs = PHB_UCS2;
            msgReq->profile_name.name_length = ((U8) mmi_ucs2strlen((CHAR*) ext_profile->profile_name)) * ENCODING_LENGTH;
            InputboxConvertDeviceEncodingToGSM(
                (PU8) ext_profile->profile_name,
                msgReq->profile_name.name,
                SRV_SMS_MAX_PROFILE_NAME_LEN,
                PHB_UCS2,
                0,
                1);
        }
        else
        {
            msgReq->profile_name.name_dcs = PHB_ASCII;
            msgReq->profile_name.name_length = (U8)InputboxConvertDeviceEncodingToGSM(
                                                    (PU8) ext_profile->profile_name,
                                                    msgReq->profile_name.name,
                                                    SRV_SMS_MAX_PROFILE_NAME_LEN + 1,
                                                    PHB_ASCII,
                                                    0,
                                                    1) - 1;
        }
        msgReq->profile_name.name[msgReq->profile_name.name_length] = '\0';
        msgReq->para_ind |= SMSAL_PARA_PROFILE_NAME;
    }

    msgReq->profile_no = ext_profile->profile_index;

    MMI_ASSERT(ext_profile->profile_index < SRV_SMS_MAX_LFOUR_PROFILES);

    if (para&SRV_SMS_PROFILE_SCA)
    {
        srv_sms_convert_ascii_num_to_l4_num(&msgReq->sc_addr, (U8*)ext_profile->sc_addr);
        msgReq->para_ind |= SMSAL_PARA_SCA;
    }

#ifdef __MMI_MESSAGES_SMS_EMAIL__
    g_srv_sms_email_pid_tmp = (U8) ext_profile->msg_type_index;
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */ 

    handle->sim_id = sim_id;
    handle->handle_data = (void*)ext_profile;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_write_sim_req(
        SRV_SMS_FILE_DETAIL_FROFILE,
        0,
        sizeof(mmi_sms_set_profile_params_req_struct),
        (void*)msgReq,
        sim_id,
        srv_sms_set_profile_detail_callback,
        (void*)handle);

    OslMfree(msgReq);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_profile_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_profile_detail(
                srv_sms_profile_struct *profile_detail,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_profile_ext_struct ext_profile;
    U16 addr_len;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ext_profile.vp_index = profile_detail->vp_index;
    ext_profile.msg_type_index = profile_detail->msg_type_index;
    memcpy(ext_profile.profile_name, profile_detail->profile_name, (SRV_SMS_MAX_PROFILE_NAME_LEN + 1) *ENCODING_LENGTH);
    ext_profile.profile_name_dcs = profile_detail->profile_name_dcs;
    ext_profile.profile_index = profile_detail->profile_index;
    addr_len = mmi_ucs2_n_to_asc((CHAR*)ext_profile.sc_addr, (CHAR*) profile_detail->sc_addr, SRV_SMS_MAX_ADDR_LEN * ENCODING_LENGTH);
    ext_profile.sc_addr[addr_len] = '\0';
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    addr_len = mmi_ucs2_n_to_asc((CHAR*)ext_profile.email_addr, (CHAR*) profile_detail->email_addr, SRV_SMS_MAX_ADDR_LEN * ENCODING_LENGTH);
    ext_profile.email_addr[addr_len] = '\0';
#endif
    ext_profile.para = SRV_SMS_PROFILE_VP | SRV_SMS_PROFILE_PID | SRV_SMS_PROFILE_NAME | SRV_SMS_PROFILE_SCA;
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    ext_profile.para |= SRV_SMS_PROFILE_EMAILSC;
#endif

    srv_sms_set_profile_partial(
        &ext_profile,
        sim_id,
        callback_func,
        user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_profile_detail_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_set_profile_detail_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_profile_params_rsp_struct *msgRsp = (mmi_sms_set_profile_params_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    srv_sms_profile_ext_struct *ext_profile = handle->handle_data;
    MMI_BOOL result = msgRsp->result;
    srv_sms_setting_para_enum para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_PROFILE_DETAIL_CALLBACK, msgRsp->result);

    para = (srv_sms_setting_para_enum)ext_profile->para;

    if (result == MMI_TRUE)
    {
        S16 error_code;
        U16 item_id;
        CHAR active_profile_index;

        item_id = srv_sms_setting_get_profile_data_id(handle->sim_id);

        ReadValue(item_id, &active_profile_index, DS_BYTE, &error_code);

        if (active_profile_index == ext_profile->profile_index)
        {
            U32 index;
            srv_sms_setting_struct *default_setting;

            index = srv_sms_sim_id_to_sim_index(handle->sim_id);
            default_setting = &(setting_cntx[index].default_setting);

            if (para&SRV_SMS_PROFILE_SCA)
            {
                memcpy(
                    default_setting->sc_addr,
                    ext_profile->sc_addr,
                    SRV_SMS_MAX_ADDR_LEN + 1);
            }
            if (para&SRV_SMS_PROFILE_NAME)
            {
                mmi_ucs2ncpy(
                    (CHAR*)default_setting->profile_name,
                    (CHAR*)(ext_profile->profile_name),
                    SRV_SMS_MAX_PROFILE_NAME_LEN);
            }
            if (para&SRV_SMS_PROFILE_VP)
            {
                default_setting->vp =  (srv_sms_vp_enum)ext_profile->vp_index;
            }
            if (para&SRV_SMS_PROFILE_PID)
            {
                default_setting->pid =  (srv_sms_pid_enum)ext_profile->msg_type_index;
            }
        }

    #ifdef __MMI_MESSAGES_SMS_EMAIL__
        if (para&SRV_SMS_PROFILE_EMAILSC)
        {
            U16 addr_len;
            srv_sms_nvram_email_struct info_struct;

            memcpy(info_struct.email_addr_no, ext_profile->email_addr, SRV_SMS_MAX_ADDR_LEN + 1);

            if (WriteRecord(
                    NVRAM_EF_SMS_EMAIL_LID,
                    (U16) (ext_profile->profile_index + 1),
                    (void*)&info_struct,
                    NVRAM_SMS_EMAIL_RECORD_SIZE,
                    &error_code) < 0)
            {
                result = MMI_FALSE;
            }

            if (active_profile_index == ext_profile->profile_index)
            {
                g_srv_sms_email_pid = g_srv_sms_email_pid_tmp;
                mmi_asc_n_to_ucs2(email_sc_addr, (CHAR*)ext_profile->email_addr, SRV_SMS_MAX_ADDR_LEN + 1);
            }
        }
    #endif /* __MMI_MESSAGES_SMS_EMAIL__ */ 
    }

    srv_sms_setting_callback(
        result,
        (void*)ext_profile,
        handle->callback_func,
        handle->user_data);

    if (ext_profile != NULL)
    {
        OslMfree(ext_profile);
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_common_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_common_settings(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_COMMON_SETTING, sim_id);

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_COMMON_PROFILE,
        0,
        0,
        sim_id,
        srv_sms_get_common_settings_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_common_settings_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_common_settings_callback(srv_sms_disp_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_common_params_rsp_struct *msgRsp = (mmi_sms_get_common_params_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    U8 settings[2] = {0, 0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_COMMON_SETTING_CALLBACK, msgRsp->result);

    if (msgRsp->result == MMI_TRUE)
    {
        U32 index;

        settings[0] = msgRsp->status_report;
        settings[1] = msgRsp->reply_path;

        index = srv_sms_sim_id_to_sim_index(handle->sim_id);

        setting_cntx[index].default_setting.status_report = (MMI_BOOL)msgRsp->status_report;
    }

    srv_sms_setting_callback(
        msgRsp->result,
        (void*)settings,
        handle->callback_func,
        handle->user_data);

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_common_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_common_settings(
                U8 commmon_setting[SRV_SMS_COMMON_SETTING_NUM],
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_common_params_req_struct *msgReq;
    U8 *DrRp = (U8*) commmon_setting;
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));
    mmi_sim_enum cphs_sim_id = MMI_SIM1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_COMMON_SETTING, sim_id);

    msgReq = (mmi_sms_set_common_params_req_struct*) OslConstructDataPtr(sizeof(*msgReq));

#if (MMI_MAX_SIM_NUM >= 2)
    cphs_sim_id = SRV_SMS_SMS_SIM_TO_MMI(sim_id);
#endif

    if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_TELESERVICES, SRV_CPHS_SERVICE_DEL_CONF, cphs_sim_id))
    {
        if (DrRp[0] == 0)
        {
            DrRp[0] = 0;
            DrRp[1] = 0;
        }
        else    /* DrRp[0] == 1 */
        {
            DrRp[0] = 0;
            DrRp[1] = 1;
        }
    }

    msgReq->status_report = DrRp[0];
    msgReq->reply_path = DrRp[1];
    msgReq->para_ind = SMSAL_COM_PARA_STATUS_REP | SMSAL_COM_PARA_REPLY_PATH;

    handle->sim_id = sim_id;
    handle->status_report = (MMI_BOOL)msgReq->status_report;
    handle->reply_path = (MMI_BOOL)msgReq->reply_path;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_write_sim_req(
        SRV_SMS_FILE_COMMON_PROFILE,
        0,
        sizeof(mmi_sms_set_common_params_req_struct),
        (void*)msgReq,
        sim_id,
        srv_sms_set_common_settings_callback,
        (void*)handle);

    OslMfree(msgReq);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_common_settings_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_set_common_settings_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_common_params_rsp_struct *msgRsp = (mmi_sms_set_common_params_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_COMMON_SETTING_CALLBACK, msgRsp->result);

    if (msgRsp->result == MMI_TRUE)
    {
        U32 index;

        index = srv_sms_sim_id_to_sim_index(handle->sim_id);

        setting_cntx[index].default_setting.status_report = handle->status_report;
        setting_cntx[index].default_setting.reply_path= handle->reply_path;
    }

    srv_sms_setting_callback(
        msgRsp->result,
        NULL,
        handle->callback_func,
        handle->user_data);

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_delivery_report_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_sms_is_delivery_report_setting(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MMI_MAX_SIM_NUM >= 2)
    index = srv_sms_sim_id_to_sim_index(sim_id);
#endif /*  (MMI_MAX_SIM_NUM >= 2) */

    return setting_cntx[index].default_setting.status_report;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_7bit_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL    is set 7bit setting
 *****************************************************************************/
MMI_BOOL srv_sms_is_7bit_setting(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
#ifdef __EMS_NON_STD_7BIT_CHAR__
    return srv_sms_get_miscell_setting(SRV_SMS_SIM_1, SRV_SMS_SIM1_SETTING_7BIT);
#else
    return MMI_FALSE;
#endif /* __EMS_NON_STD_7BIT_CHAR__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_7bit_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL   set result
 *****************************************************************************/
MMI_BOOL srv_sms_set_7bit_setting(MMI_BOOL is_set, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __EMS_NON_STD_7BIT_CHAR__
    return srv_sms_set_miscell_setting(SRV_SMS_SIM_1, SRV_SMS_SIM1_SETTING_7BIT, is_set);
#else
    return MMI_FALSE;
#endif /* __EMS_NON_STD_7BIT_CHAR__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_save_sent_sms_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL    is save send messages
 *****************************************************************************/
MMI_BOOL srv_sms_is_save_sent_sms_setting(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_save = MMI_TRUE;
    MMI_BOOL is_unsave = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    is_unsave = srv_sms_get_miscell_setting(SRV_SMS_SIM_1, SRV_SMS_SIM1_SETTING_SAVE_SENT_SMS);

    if (is_unsave)
    {
        is_save = MMI_FALSE;
    }

    return is_save;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_save_sent_sms_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL   set result
 *****************************************************************************/
MMI_BOOL srv_sms_set_save_sent_sms_setting(MMI_BOOL is_save, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    MMI_BOOL is_unsave = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (is_save)
    {
        is_unsave = MMI_FALSE;
    }

    result = srv_sms_set_miscell_setting(SRV_SMS_SIM_1, SRV_SMS_SIM1_SETTING_SAVE_SENT_SMS, is_unsave);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_is_highlight_view_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL   set result
 *****************************************************************************/
MMI_BOOL srv_sms_is_highlight_view_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
    return srv_sms_get_miscell_setting(SRV_SMS_SIM_1, SRV_SMS_SIM1_SETTING_HILITE_VIEW);
#else
    return MMI_FALSE;
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_highlight_view_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL   set result
 *****************************************************************************/
MMI_BOOL srv_sms_set_highlight_view_setting(MMI_BOOL is_set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGE_SMS_HILITE_VIEWER__
    return srv_sms_set_miscell_setting(SRV_SMS_SIM_1, SRV_SMS_SIM1_SETTING_HILITE_VIEW, is_set);
#else
    return MMI_FALSE;
#endif /* __MMI_MESSAGE_SMS_HILITE_VIEWER__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_long_sms_dynamic_seg_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_is_long_sms_dynamic_seg_setting(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __EMS_DYNAMIC_SEG_NUM__
    return srv_sms_get_miscell_setting(SRV_SMS_SIM_1, SRV_SMS_SIM1_SETTING_LONG_SMS);
#else
    return MMI_FALSE;
#endif /* __EMS_DYNAMIC_SEG_NUM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_long_sms_dynamic_seg_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL srv_sms_set_long_sms_dynamic_seg_setting(MMI_BOOL flag, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __EMS_DYNAMIC_SEG_NUM__
    return srv_sms_set_miscell_setting(sim_id, SRV_SMS_SIM1_SETTING_LONG_SMS, flag);
#else
    return MMI_FALSE;
#endif /* __EMS_DYNAMIC_SEG_NUM__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_msg_waiting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_msg_waiting(
                srv_sms_msg_waiting_struct *msg_waiting,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_msg_waiting_req_struct *msgReq;
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_MSG_WAITING, sim_id, msg_waiting);

    msgReq = (mmi_sms_set_msg_waiting_req_struct*) OslConstructDataPtr(sizeof(*msgReq));
    msgReq->line_no = msg_waiting->line_no;
    msgReq->waiting_num = msg_waiting->waiting_num;
    msgReq->ind_type = msg_waiting->ind_type;
    //msgReq->source_id = MMI_FRM_SMS_BACKGROUND_HAND;

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_write_sim_req(
        SRV_SMS_FILE_SMS_WAITING,
        0,
        sizeof(mmi_sms_set_msg_waiting_req_struct),
        (void*)msgReq,
        sim_id,
        srv_sms_set_msg_waiting_callback,
        (void*)handle);

    OslMfree(msgReq);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_msg_waiting_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_set_msg_waiting_callback(srv_sms_disp_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_msg_waiting_rsp_struct *msgRsp = (mmi_sms_set_msg_waiting_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_MSG_WAITING_CALLBACK, msgRsp->result);

    srv_sms_setting_callback(
        msgRsp->result,
        NULL,
        handle->callback_func,
        handle->user_data);

    OslMfree(handle);
}


#ifdef __MMI_GPRS_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_preferred_bearer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_preferred_bearer(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_PREFER_BEARER, sim_id);

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_COMMON_PROFILE,
        0,
        0,
        sim_id,
        srv_sms_get_preferred_bearer_callback,
        (void*)handle);

}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_preferred_bearer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_preferred_bearer_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_common_params_rsp_struct *msgRsp = (mmi_sms_get_common_params_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    U8 bearer = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRsp->result == MMI_TRUE)
    {
         if (msgRsp->bearer_service == SMS_PREFER_GPRS)
        {
            bearer = SRV_SMS_PREFER_GPRS;
        }
        else if (msgRsp->bearer_service == SMS_PREFER_GSM)
        {
            bearer = SRV_SMS_PREFER_GSM;
        }
        else if (msgRsp->bearer_service == SMS_GSM_ONLY)
        {
            bearer = SRV_SMS_GSM_ONLY;
        }
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_PREFER_BEARER_CALLBACK, msgRsp->result, bearer);

    srv_sms_setting_callback(
        msgRsp->result,
        (void*)&bearer,
        handle->callback_func,
        handle->user_data);

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_preferred_bearer
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_preferred_bearer(
                U8 *bearer,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_common_params_req_struct *msgReq;
    U8 bearer_type = *(U8*) bearer;
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_PREFER_BEARER, bearer_type);

    msgReq = (mmi_sms_set_common_params_req_struct*) OslConstructDataPtr(sizeof(*msgReq));

    switch (bearer_type)
    {
        case SRV_SMS_PREFER_GPRS:
            msgReq->bearer_service = SMS_PREFER_GPRS;
            break;
        case SRV_SMS_PREFER_GSM:
            msgReq->bearer_service = SMS_PREFER_GSM;
            break;
        case SRV_SMS_GSM_ONLY:
            msgReq->bearer_service = SMS_GSM_ONLY;
            break;
    }

    msgReq->para_ind = SMSAL_COM_PARA_BEARER;

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_write_sim_req(
        SRV_SMS_FILE_COMMON_PROFILE,
        0,
        sizeof(mmi_sms_set_common_params_req_struct),
        (void*)msgReq,
        sim_id,
        srv_sms_set_preferred_bearer_callback,
        (void*)handle);

    OslMfree(msgReq);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_preferred_bearer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_set_preferred_bearer_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_common_params_rsp_struct *msgRsp = (mmi_sms_set_common_params_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_PREFER_BEARER_CALLBACK, msgRsp->result);

    srv_sms_setting_callback(
        msgRsp->result,
        NULL,
        handle->callback_func,
        handle->user_data);

    OslMfree(handle);
}

#endif /* defined(__MMI_GPRS_FEATURES__) */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_mailbox_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static srv_sms_mailbox_struct* srv_sms_get_mailbox_info(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_mailbox_struct *mailbox_info;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_MAILBOX_INFO, sim_id);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    mailbox_info = &(setting_cntx[index].mailbox_info);

    return mailbox_info;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_mailbox_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_mailbox_info(srv_sms_sim_enum sim_id, srv_sms_mailbox_edit_struct *mailbox_detail)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_mailbox_struct *mailbox_info;
    U8 mailbox_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_MAILBOX_INFO, sim_id);

    mailbox_info = srv_sms_get_mailbox_info(sim_id);

    mailbox_index = mailbox_detail->mailbox_index;

    memcpy(
        mailbox_info->p_mailbox_name[mailbox_index],
        mailbox_detail->mailbox_name,
        (SRV_SMS_MAX_PROFILE_NAME_LEN *ENCODING_LENGTH) + ENCODING_LENGTH);

    memcpy(
        mailbox_info->p_mailbox_number[mailbox_index],
        mailbox_detail->mailbox_address,
        (MAX_CC_ADDR_LEN *ENCODING_LENGTH) + ENCODING_LENGTH);

    mailbox_info->mailbox_name_dcs[mailbox_index] = mailbox_detail->mailbox_name_dcs;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_mailbox_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
const srv_sms_mailbox_struct* srv_sms_get_mailbox_setting(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_mailbox_struct *mailbox_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_MAILBOX_SETTING, sim_id);

    mailbox_info = srv_sms_get_mailbox_info(sim_id);

    return mailbox_info;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_mailbox_info_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_mailbox_info_req(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_mailbox_struct *mailbox_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_MAILBOX_INFO_REQ, sim_id);

    mailbox_info = srv_sms_get_mailbox_info(sim_id);

    srv_sms_setting_callback(
        MMI_TRUE,
        (void*)mailbox_info,
        callback_func,
        user_data);
}


#ifdef __MMI_MSG_REL4_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_mbi_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_mbi_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_MBI_INFO, sim_id);

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_MBI,
        0,
        0,
        sim_id,
        srv_sms_get_mbi_info_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_mbi_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_mbi_info_callback(srv_sms_disp_cb_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_mbi_rsp_struct *msgRsp = (mmi_sms_get_mbi_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_MBI_INFO_CALLBACK, msgRsp->result);

    if (msgRsp->result == MMI_TRUE)
    {
        U32 i, j;
        srv_sms_get_mbi_struct cb_data;

        if (msgRsp->msp_num > SMSAL_MAX_MSP_NUM)
        {
            cb_data.mbi_num = SMSAL_MAX_MSP_NUM;
        }
        else
        {
            cb_data.mbi_num = msgRsp->msp_num;
        }

        for (i = 0; i < cb_data.mbi_num; i++)
        {
            for (j = 0; j < 4; j++)
            {
                if (msgRsp->mbi[i].mbi_id[j] < SMSAL_MAX_MAILBOX_NUM)
                {
                    cb_data.mbi[i].mbi_id[j] = msgRsp->mbi[i].mbi_id[j];
                }
                else
                {
                    cb_data.mbi[i].mbi_id[j] = 0xFF;
                }
            }
        }
 
        srv_sms_setting_callback(
            msgRsp->result,
            (void*)&cb_data,
            handle->callback_func,
            handle->user_data);
    }
    else
    {
        srv_sms_setting_callback(
            msgRsp->result,
            NULL,
            handle->callback_func,
            handle->user_data);
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_mbi_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_mbi_info(
                srv_sms_set_mbi_struct *mbi_info,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_mbi_req_struct *msgReq;
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_MBI_INFO, sim_id, mbi_info);

    msgReq = (mmi_sms_set_mbi_req_struct*) OslConstructDataPtr(sizeof(mmi_sms_set_mbi_req_struct));
    msgReq->msp_no = mbi_info->set_index;
    memcpy(msgReq->mbi.mbi_id, mbi_info->mbi.mbi_id, 4);

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_write_sim_req(
        SRV_SMS_FILE_MBI,
        0,
        sizeof(mmi_sms_set_mbi_req_struct),
        (void*)msgReq,
        sim_id,
        srv_sms_set_mbi_info_callback,
        (void*)handle);

    OslMfree(msgReq);
}



/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_mbi_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_set_mbi_info_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_mbi_rsp_struct *msgRsp = (mmi_sms_set_mbi_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_MBI_INFO_CALLBACK, msgRsp->result);

    srv_sms_setting_callback(
        msgRsp->result,
        NULL,
        handle->callback_func,
        handle->user_data);

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msp_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_msp_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_MSP_INFO, sim_id);

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_MSP,
        0,
        0,
        sim_id,
        srv_sms_get_msp_info_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_msp_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_msp_info_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_msp_rsp_struct *msgRsp = (mmi_sms_get_msp_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    U8 select_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_MSP_INFO_CALLBACK, msgRsp->result, msgRsp->msp_no);

    if (msgRsp->result == MMI_TRUE)
    {
        if (msgRsp->msp_no < SMSAL_MAX_MSP_NUM)
        {
            select_index = msgRsp->msp_no;
        }
        else
        {
            select_index = 0;
        }

        srv_sms_setting_callback(
            msgRsp->result,
            (void*)&select_index,
            handle->callback_func,
            handle->user_data);
    }
    else
    {
        srv_sms_setting_callback(
            msgRsp->result,
            NULL,
            handle->callback_func,
            handle->user_data);
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_msp_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_msp_info(
                U8 *select_index,
                srv_sms_sim_enum sim_id, 
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_msp_req_struct *msgReq;
    U8 index = *(U8*) select_index;
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_MSP_INFO, index, sim_id);

    msgReq = (mmi_sms_set_msp_req_struct*) OslConstructDataPtr(sizeof(mmi_sms_set_msp_req_struct));
    msgReq->msp_no = index;

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_write_sim_req(
        SRV_SMS_FILE_MSP,
        0,
        sizeof(mmi_sms_set_msp_req_struct),
        (void*)msgReq,
        sim_id,
        srv_sms_set_msp_info_callback,
        (void*)handle);

    OslMfree(msgReq);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_msp_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_set_msp_info_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_msp_rsp_struct *msgRsp = (mmi_sms_set_msp_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_MSP_INFO_CALLBACK, msgRsp->result);

    srv_sms_setting_callback(
        msgRsp->result,
        NULL,
        handle->callback_func,
        handle->user_data);

    OslMfree(handle);
}
#endif /* __MMI_MSG_REL4_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  srv_sms_check_r4_support
 * DESCRIPTION
 *  Get mailbox num response
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_sms_check_r4_support(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MSG_REL4_SUPPORT__
    if (smsal_is_support_r4_mbdn())
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
#else
    return MMI_FALSE;
#endif /* __MMI_MSG_REL4_SUPPORT__ */
}


#ifdef __MMI_MSG_REL4_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_voicemail_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_voicemail_number(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_voicemail_info_struct *vm_info;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_GET_VOICEMAIL_NUM, sim_id);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    vm_info =  &voicemail_info[index];

    vm_info->state = SRV_SMS_VOICEMAIL_GET_NUM;
    vm_info->need_update_mbi = MMI_FALSE;

    /* Check whether support R4 */
    if (vm_info->is_support_r4 == MMI_TRUE)
    {
        srv_sms_vm_get_mbi_info(sim_id, callback_func, user_data);
    }
    else    /* CPHS mode */
    {
        srv_sms_vm_get_mailbox_info(sim_id, callback_func, user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_voicemail_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_voicemail_number(
                srv_sms_mailbox_edit_struct *mailbox,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_voicemail_info_struct *vm_info;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_SET_VOICEMAIL_NUM, sim_id);

    index = srv_sms_sim_id_to_sim_index(sim_id);

    vm_info =  &voicemail_info[index];

//    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_MMI_SMS_FRM_SMS_SET_VOICEMIAL_NUMBER_REQ, vm_info, mailbox_details);

    if (mailbox_details != NULL)
    {
        OslMfree(mailbox_details);
        mailbox_details = NULL;
    }
    mailbox_details = OslMalloc(sizeof(srv_sms_mailbox_edit_struct));

    memcpy(mailbox_details, mailbox, sizeof(srv_sms_mailbox_edit_struct));

    vm_info->state = SRV_SMS_VOICEMAIL_SET_NUM;

    /* Check whether support R4 */
    if (vm_info->is_support_r4 == MMI_TRUE)
    {
        srv_sms_vm_get_mbi_info(sim_id, callback_func, user_data);
    }
    else
    {
        /* support CPHS */

        srv_sms_vm_set_mailbox_info(sim_id, callback_func, user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_vm_get_mbi_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_get_mbi_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_GET_MBI_INFO, sim_id);

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_MBI,
        0,
        0,
        sim_id,
        srv_sms_vm_get_mbi_info_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_mbi_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_get_mbi_info_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_voicemail_info_struct *vm_info;
    mmi_sms_get_mbi_rsp_struct *msgRsp = (mmi_sms_get_mbi_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_GET_MBI_INFO_CALLBACK, msgRsp->result);

    index = srv_sms_sim_id_to_sim_index(handle->sim_id);

    vm_info =  &voicemail_info[index];

    if (msgRsp->result == MMI_TRUE)
    {
        U32 i, j;

        if (msgRsp->msp_num > 0)
        {
            if (msgRsp->msp_num < SRV_SMS_MAX_MSP_NUM)
            {
                vm_info->mbi_info.mbi_num = msgRsp->msp_num;
            }
            else
            {
                vm_info->mbi_info.mbi_num = SRV_SMS_MAX_MSP_NUM;
            }

            for (i = 0; i < vm_info->mbi_info.mbi_num; i++)
            {
                for (j = 0; j < 4; j++)
                {
                    vm_info->mbi_info.mbi[i].mbi_id[j] = (U8) msgRsp->mbi[i].mbi_id[j];
                }
            }
        }
        else
        {
            vm_info->is_support_r4 = MMI_FALSE;
        }

        if (vm_info->state == SRV_SMS_VOICEMAIL_GET_NUM)
        {
            if (vm_info->is_support_r4 == MMI_FALSE)
            {
                srv_sms_vm_get_msp_info(handle->sim_id, handle->callback_func, handle->user_data);
            }
            else
            {
                srv_sms_vm_get_mailbox_info(handle->sim_id, handle->callback_func, handle->user_data);
            }
        }
        else
        {
            if (vm_info->is_support_r4 == MMI_TRUE)
            {
                srv_sms_vm_get_mailbox_num(handle->sim_id, handle->callback_func, handle->user_data);
            }
            else
            {
                srv_sms_vm_set_mailbox_info(handle->sim_id, handle->callback_func, handle->user_data);
            }
        }
    }
    else
    {
        srv_sms_setting_callback(
            msgRsp->result,
            NULL,
            handle->callback_func,
            handle->user_data);
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_vm_get_mailbox_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_get_mailbox_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_GET_MAILBOX_INFO, sim_id);

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_MAIL_ADDRESS,
        0,
        0,
        sim_id,
        srv_sms_vm_get_mailbox_info_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_vm_get_mailbox_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_get_mailbox_info_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_mailbox_address_rsp_struct *msgRsp = (mmi_sms_get_mailbox_address_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    MMI_BOOL result = MMI_FALSE;
    srv_sms_mailbox_struct mailbox_info;
    srv_sms_voicemail_info_struct *vm_info;
    U8 voicemail_num = 0;
    U32 i = 0;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_GET_MAILBOX_INFO_CALLBACK, msgRsp->result);

    memset(&mailbox_info, 0, sizeof(srv_sms_mailbox_struct));

    index = srv_sms_sim_id_to_sim_index(handle->sim_id);

    vm_info =  &voicemail_info[index];

    if (msgRsp->result == MMI_TRUE)
    {
        mailbox_info.mailbox_name_len = msgRsp->alpha_length;
        mailbox_info.mailbox_number_len= msgRsp->max_num_length;
        mailbox_info.is_support_r4 = vm_info->is_support_r4;

        /* if exist the MBI file in the SIM card */
        if (vm_info->is_support_r4 == MMI_TRUE)
        {
            U8 mailbox_num;

            voicemail_num = vm_info->mbi_info.mbi_num;

            if (msgRsp->mailbox_num < SRV_SMS_MAX_MAILBOX_NUM)
            {
                mailbox_num = msgRsp->mailbox_num;
            }
            else
            {
                mailbox_num = SRV_SMS_MAX_MAILBOX_NUM;
            }

            if (voicemail_num > mailbox_num)
            {
                voicemail_num = mailbox_num;
            }

            if (voicemail_num > SRV_SMS_MAX_MSP_NUM)
            {
                voicemail_num = SRV_SMS_MAX_MSP_NUM;
            }

            mailbox_info.mailbox_number = voicemail_num;

            if (vm_info->msp_no > voicemail_num)
            {
                mailbox_info.default_index = 0;
            }
            else
            {
                mailbox_info.default_index = vm_info->msp_no;
            }

            for (i = 0; i < voicemail_num; i++)
            {
                U8 index = vm_info->mbi_info.mbi[i].mbi_id[0];

                if (index < mailbox_num)
                {
                    U8 name_dcs = msgRsp->mailbox_info[index].name.name_dcs;
                    U8 type = (msgRsp->mailbox_info[index].number_info.type == CSMCC_INTERNATIONAL_ADDR) ? 1 : 0;
                    U8 num_length = msgRsp->mailbox_info[index].number_info.length;
                    U8 name_length = msgRsp->mailbox_info[index].name.name_length;

                    if (num_length > msgRsp->max_num_length)
                    {
                        num_length = msgRsp->max_num_length;
                    }

                    if ((type + num_length) > MAX_CC_ADDR_LEN)
                    {
                        num_length = MAX_CC_ADDR_LEN - type;
                    }

                    if (name_length > msgRsp->alpha_length)
                    {
                        name_length = msgRsp->alpha_length;
                    }

                    if (name_length > 0)
                    {
                        /* add null terminator */
                        if (name_dcs == PHB_ASCII)
                        {
                            if (name_length < sizeof(msgRsp->mailbox_info[index].name.name))
                            {
                                msgRsp->mailbox_info[index].name.name[name_length] = 0;
                            }
                        }
                    #ifdef __PHB_0x81_SUPPORT__
                        else if ((name_dcs == PHB_UCS2) || (name_dcs == PHB_UCS2_81) ||
                                 (name_dcs == PHB_UCS2_82))
                        {
                            if ((name_length + 1) < sizeof(msgRsp->mailbox_info[index].name.name))
                            {
                                msgRsp->mailbox_info[index].name.name[name_length] = 0;
                                msgRsp->mailbox_info[index].name.name[name_length + 1] = 0;
                            }
                        }
                    #endif /* __PHB_0x81_SUPPORT__ */ 
                        else
                        {
                            name_dcs = PHB_UCS2;

                            if ((name_length + 1) < sizeof(msgRsp->mailbox_info[index].name.name))
                            {
                                msgRsp->mailbox_info[index].name.name[name_length] = 0;
                                msgRsp->mailbox_info[index].name.name[name_length + 1] = 0;
                            }
                        }

                        InputboxConvertGSMToDeviceEncoding(
                            msgRsp->mailbox_info[index].name.name,
                            mailbox_info.p_mailbox_name[i],
                            name_length,
                            ((name_length + 1) * ENCODING_LENGTH),
                            name_dcs,
                            0,
                            1);
                    }

                    mailbox_info.mailbox_name_dcs[i] = name_dcs;

                    if (type)
                    {
                        mmi_asc_to_ucs2((CHAR*) mailbox_info.p_mailbox_number[i], (CHAR*) "+");
                    }

                    mmi_asc_n_to_ucs2(
                        (CHAR*) (mailbox_info.p_mailbox_number[i] + (type * ENCODING_LENGTH)),
                        (CHAR*) msgRsp->mailbox_info[index].number_info.number,
                        num_length);
                    memset(mailbox_info.p_mailbox_number[i] + ((type + num_length) * ENCODING_LENGTH), 0, ENCODING_LENGTH);
                }
                else
                {
                    U8 type = (msgRsp->mailbox_info[i].number_info.type == CSMCC_INTERNATIONAL_ADDR) ? 1 : 0;
                    U8 num_length = msgRsp->mailbox_info[i].number_info.length;
                    U8 name_length = msgRsp->mailbox_info[i].name.name_length;
    
                    if (num_length > msgRsp->max_num_length)
                    {
                        num_length = msgRsp->max_num_length;
                    }
    
                    if ((type + num_length) > MAX_CC_ADDR_LEN)
                    {
                        num_length = MAX_CC_ADDR_LEN - type;
                    }
    
                    if (name_length > msgRsp->alpha_length)
                    {
                        name_length = msgRsp->alpha_length;
                    }
    
                    mailbox_info.mailbox_name_dcs[i] = msgRsp->mailbox_info[i].name.name_dcs;

                    if (msgRsp->mailbox_info[i].name.name_length > 0)
                    {
                        /* add null terminator */
                        if (msgRsp->mailbox_info[i].name.name_dcs == SMSAL_DEFAULT_DCS)
                        {
                            if (name_length < sizeof(msgRsp->mailbox_info[i].name.name))
                            {
                                msgRsp->mailbox_info[i].name.name[name_length] = 0;
                            }
                        }
                        else
                        {
                            if ((name_length + 1) < sizeof(msgRsp->mailbox_info[i].name.name))
                            {
                                msgRsp->mailbox_info[i].name.name[name_length] = 0;
                                msgRsp->mailbox_info[i].name.name[name_length + 1] = 0;
                            }
                        }
    
                        InputboxConvertGSMToDeviceEncoding(
                            msgRsp->mailbox_info[i].name.name,
                            mailbox_info.p_mailbox_name[i],
                            name_length,
                            ((name_length + 1) * ENCODING_LENGTH),
                            msgRsp->mailbox_info[i].name.name_dcs,
                            0,
                            1);
                    }
 
                    if (type)
                    {
                        mmi_asc_to_ucs2((CHAR*) mailbox_info.p_mailbox_number[i], (CHAR*) "+");
                    }
                    mmi_asc_n_to_ucs2(
                        (CHAR*) (mailbox_info.p_mailbox_number[i] + (type * ENCODING_LENGTH)),
                        (CHAR*) msgRsp->mailbox_info[i].number_info.number,
                        num_length);
                    memset(mailbox_info.p_mailbox_number[i] + ((type + num_length) * ENCODING_LENGTH), 0, ENCODING_LENGTH);
                }
            }
            result = MMI_TRUE;
        }
        else
        {
            /* CPHS case */
            if (msgRsp->mailbox_num < SRV_SMS_MAX_CPHS_MAILBOX_NUM)
            {
                voicemail_num = msgRsp->mailbox_num;
            }
            else
            {
                voicemail_num = SRV_SMS_MAX_CPHS_MAILBOX_NUM;
            }

            mailbox_info.mailbox_number = voicemail_num;

            for (i = 0; i < voicemail_num; i++)
            {
                U8 type = (msgRsp->mailbox_info[i].number_info.type == CSMCC_INTERNATIONAL_ADDR) ? 1 : 0;
                U8 num_length = msgRsp->mailbox_info[i].number_info.length;
                U8 name_length = msgRsp->mailbox_info[i].name.name_length;

                if (num_length > msgRsp->max_num_length)
                {
                    num_length = msgRsp->max_num_length;
                }

                if ((type + num_length) > MAX_CC_ADDR_LEN)
                {
                    num_length = MAX_CC_ADDR_LEN - type;
                }

                if (name_length > msgRsp->alpha_length)
                {
                    name_length = msgRsp->alpha_length;
                }

                mailbox_info.mailbox_name_dcs[i] = msgRsp->mailbox_info[i].name.name_dcs;

                if (msgRsp->mailbox_info[i].name.name_length > 0)
                {
                    /* add null terminator */
                    if (msgRsp->mailbox_info[i].name.name_dcs == SMSAL_DEFAULT_DCS)
                    {
                        if (name_length < sizeof(msgRsp->mailbox_info[i].name.name))
                        {
                            msgRsp->mailbox_info[i].name.name[name_length] = 0;
                        }
                    }
                    else
                    {
                        if ((name_length + 1) < sizeof(msgRsp->mailbox_info[i].name.name))
                        {
                            msgRsp->mailbox_info[i].name.name[name_length] = 0;
                            msgRsp->mailbox_info[i].name.name[name_length + 1] = 0;
                        }
                    }

                    InputboxConvertGSMToDeviceEncoding(
                        msgRsp->mailbox_info[i].name.name,
                        mailbox_info.p_mailbox_name[i],
                        name_length,
                        ((name_length + 1) * ENCODING_LENGTH),
                        msgRsp->mailbox_info[i].name.name_dcs,
                        0,
                        1);
                }

                if (type)
                {
                    mmi_asc_to_ucs2((CHAR*) mailbox_info.p_mailbox_number[i], (CHAR*) "+");
                }
                mmi_asc_n_to_ucs2(
                    (CHAR*) (mailbox_info.p_mailbox_number[i] + (type * ENCODING_LENGTH)),
                    (CHAR*) msgRsp->mailbox_info[i].number_info.number,
                    num_length);
                memset(mailbox_info.p_mailbox_number[i] + ((type + num_length) * ENCODING_LENGTH), 0, ENCODING_LENGTH);
            }

            result = MMI_TRUE;
        }
    }

    srv_sms_setting_callback(
        result,
        (void*)&mailbox_info,
        handle->callback_func,
        handle->user_data);

    if (msgRsp->result == MMI_TRUE)
    {
        srv_sms_mailbox_struct *mailbox_info_temp;

        mailbox_info_temp = srv_sms_get_mailbox_info(handle->sim_id);
        memcpy(mailbox_info_temp, &mailbox_info, sizeof(srv_sms_mailbox_struct));
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_vm_get_msp_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_get_msp_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_GET_MSP_INFO, sim_id);

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_MSP,
        0,
        0,
        sim_id,
        srv_sms_vm_get_msp_info_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_vm_get_msp_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_get_msp_info_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_msp_rsp_struct *msgRsp = (mmi_sms_get_msp_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    srv_sms_voicemail_info_struct *vm_info;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_GET_MSP_INFO_CALLBACK, msgRsp->result);

    index = srv_sms_sim_id_to_sim_index(handle->sim_id);

    vm_info =  &voicemail_info[index];

    if (msgRsp->result == MMI_TRUE)
    {
        vm_info->msp_no = msgRsp->msp_no;
        
        srv_sms_vm_get_mailbox_info(handle->sim_id, handle->callback_func, handle->user_data);
    }
    else
    {
        /* if need set vm_info as 0 ??? */

        srv_sms_setting_callback(
            msgRsp->result,
            NULL,
            handle->callback_func,
            handle->user_data);
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_vm_get_mailbox_num
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_get_mailbox_num(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_GET_MAILBOX_NUM, sim_id);

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_MAIL_ADDRESS,
        0,
        0,
        sim_id,
        srv_sms_vm_get_mailbox_num_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_vm_get_mailbox_num_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_get_mailbox_num_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_mailbox_address_rsp_struct *msgRsp = (mmi_sms_get_mailbox_address_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    srv_sms_voicemail_info_struct *vm_info;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(handle != NULL);

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_GET_MAILBOX_NUM_CALLBACK, msgRsp->result);

    index = srv_sms_sim_id_to_sim_index(handle->sim_id);

    vm_info =  &voicemail_info[index];

    if (msgRsp->result == MMI_TRUE)
    {
        vm_info->mailbox_num = msgRsp->mailbox_num;

        srv_sms_vm_set_mailbox_info(
            handle->sim_id,
            handle->callback_func,
            handle->user_data);
    }
    else
    {
        if (vm_info->state == SRV_SMS_VOICEMAIL_SET_NUM)
        {
            if (mailbox_details != NULL)
            {
                OslMfree(mailbox_details);
                mailbox_details = NULL;
            }
        }

        /* if need set vm_info as 0 ??? */

        srv_sms_setting_callback(
            msgRsp->result,
            NULL,
            handle->callback_func,
            handle->user_data);
    }

    if (handle != NULL)
    {
        OslMfree(handle);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_vm_set_mailbox_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_set_mailbox_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_mailbox_address_req_struct *msgReq;
    CHAR mailbox_address[MAX_CC_ADDR_LEN + 1];
    U8 mailbox_index = 0;
    U32 i = 0;
    srv_sms_voicemail_info_struct *vm_info;
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_SET_MAILBOX_INFO, sim_id);

    index = srv_sms_sim_id_to_sim_index(handle->sim_id);

    vm_info =  &voicemail_info[index];

    if (vm_info->is_support_r4 == MMI_TRUE)
    {
        U8 voicemail_index;
        U8 mailbox_num = vm_info->mailbox_num;
        U8 mbi_index = mailbox_details->mailbox_index;

        voicemail_index = vm_info->mbi_info.mbi[mbi_index].mbi_id[0];

        if (voicemail_index > mailbox_num)
        {
            U32 j;
            U32 unused_index;

            /* Find a unused mailbox number index */
            for (unused_index = 0; unused_index < mailbox_num; unused_index++)
            {

                U8 is_used = MMI_FALSE;

                for (i = 0; i < vm_info->mbi_info.mbi_num; i++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        if (vm_info->mbi_info.mbi[i].mbi_id[j] == unused_index)
                        {
                            is_used = MMI_TRUE;
                            break;
                        }
                    }

                    if (is_used == MMI_TRUE)
                    {
                        break;
                    }
                }

                if (is_used == MMI_FALSE)
                {
                    break;
                }
            }

            if (unused_index < mailbox_details->mailbox_index)
            {
                U32 index;
                U8 is_used = MMI_FALSE;
                for (index = 0; index < mailbox_num; index++)
                {
                    for (j = 0; j < 4; j++)
                    {
                        if (vm_info->mbi_info.mbi[mailbox_details->mailbox_index].mbi_id[j] == index)
                        {
                            is_used = MMI_TRUE;
                            break;
                        }
                    }

                    if (is_used == MMI_TRUE)
                    {
                        break;
                    }
                }

                if (is_used == MMI_FALSE)
                {
                    unused_index = mailbox_details->mailbox_index;
                }
            }

            /* no unused mailbox index */
            if (unused_index == mailbox_num)
            {
                U32 vm_unused_index;

                /* find an index which the voicemail doesn't use. */
                for (vm_unused_index = 0; vm_unused_index < mailbox_num; vm_unused_index++)
                {
                    U8 is_duplicate = MMI_FALSE;

                    for (i = 0; i < vm_info->mbi_info.mbi_num; i++)
                    {
                        if (vm_info->mbi_info.mbi[i].mbi_id[0] == vm_unused_index)
                        {
                            is_duplicate = MMI_TRUE;
                            break;
                        }
                    }

                    if (is_duplicate == MMI_FALSE)
                    {
                        mailbox_index = vm_unused_index;
                        break;
                    }
                }
            }
            else
            {
                mailbox_index = unused_index;
            }

            vm_info->need_update_mbi = MMI_TRUE; 

            /* Update MBI voicemail index */
            vm_info->mbi_info.mbi[mbi_index].mbi_id[0] = mailbox_index;
        }
        else
        {
            mailbox_index = voicemail_index;
        }

        /* Update MBI index except voicemail */
        for (i = 1; i < 4; i++)
        {
            if (vm_info->mbi_info.mbi[mbi_index].mbi_id[i] >= mailbox_num)
            {
                vm_info->mbi_info.mbi[mbi_index].mbi_id[i] = 0xFF;
            }
        }
    }
    else
    {
        mailbox_index = mailbox_details->mailbox_index;
    }

    msgReq = (mmi_sms_set_mailbox_address_req_struct*) OslConstructDataPtr(sizeof(*msgReq));

    if (mailbox_details->mailbox_name_dcs == PHB_UCS2)
    {
        msgReq->name.name_dcs = PHB_UCS2;
        msgReq->name.name_length = ((U8) mmi_ucs2strlen((CHAR*) mailbox_details->mailbox_name)) * ENCODING_LENGTH;
        InputboxConvertDeviceEncodingToGSM(
            (PU8) mailbox_details->mailbox_name,
            msgReq->name.name,
            SRV_SMS_MAX_PROFILE_NAME_LEN,
            PHB_UCS2,
            0,
            1);
    }
    else
    {
        msgReq->name.name_dcs = PHB_ASCII;
        msgReq->name.name_length = InputboxConvertDeviceEncodingToGSM(
                                    (PU8) mailbox_details->mailbox_name,
                                    msgReq->name.name,
                                    SRV_SMS_MAX_PROFILE_NAME_LEN+1,
                                    PHB_ASCII,
                                    0,
                                    1) - 1;
    }

    msgReq->name.name[msgReq->name.name_length] = '\0';

    mmi_ucs2_to_asc(mailbox_address, (CHAR*)mailbox_details->mailbox_address);
    srv_sms_convert_ascii_num_to_l4_num(&msgReq->num_addr, (U8*)mailbox_address);
    msgReq->mailbox_num = mailbox_index;

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_write_sim_req(
        SRV_SMS_FILE_MAIL_ADDRESS,
        0,
        sizeof(mmi_sms_set_mailbox_address_req_struct),
        (void*)msgReq,
        sim_id,
        srv_sms_vm_set_mailbox_info_callback,
        (void*)handle);

    OslMfree(msgReq);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_vm_set_mailbox_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_set_mailbox_info_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_mailbox_address_rsp_struct *msgRsp = (mmi_sms_set_mailbox_address_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    srv_sms_voicemail_info_struct *vm_info;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_SET_MAILBOX_INFO_CALLBACK, msgRsp->result);

    index = srv_sms_sim_id_to_sim_index(handle->sim_id);

    vm_info =  &voicemail_info[index];

    if ((msgRsp->result) == MMI_TRUE)
    {
    	if ((vm_info->is_support_r4 == MMI_TRUE) &&
    	    (vm_info->need_update_mbi == MMI_TRUE))
        {
            srv_sms_vm_set_mbi_info(handle->sim_id, handle->callback_func, handle->user_data);
        }
        else
        {
            srv_sms_sim_enum sim_id = handle->sim_id;

            srv_sms_set_mailbox_info(sim_id, mailbox_details);

            srv_sms_setting_callback(
                msgRsp->result,
                (void*)mailbox_details,
                handle->callback_func,
                handle->user_data);

            OslMfree(mailbox_details);
            mailbox_details = NULL;

            srv_sms_get_voicemail_number(sim_id, NULL, NULL);
        }
    }
    else
    {
        srv_sms_setting_callback(
            msgRsp->result,
            (void*)mailbox_details,
            handle->callback_func,
            handle->user_data);
        
        OslMfree(mailbox_details);
        mailbox_details = NULL;
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_vm_set_mbi_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_set_mbi_info(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_mbi_req_struct *msgReq;
    srv_sms_voicemail_info_struct *vm_info;
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_SET_MBI_INFO, sim_id);

    msgReq = (mmi_sms_set_mbi_req_struct*) OslConstructDataPtr(sizeof(mmi_sms_set_mbi_req_struct));

    index = srv_sms_sim_id_to_sim_index(handle->sim_id);

    vm_info =  &voicemail_info[index];

    msgReq->msp_no = mailbox_details->mailbox_index;
    memcpy(msgReq->mbi.mbi_id, vm_info->mbi_info.mbi[mailbox_details->mailbox_index].mbi_id, 4);

    handle->sim_id = sim_id;
    handle->handle_data = vm_info;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_write_sim_req(
        SRV_SMS_FILE_MBI,
        0,
        sizeof(mmi_sms_set_mbi_req_struct),
        (void*)msgReq,
        sim_id,
        srv_sms_vm_set_mbi_info_callback,
        (void*)handle);

    OslMfree(msgReq);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_vm_set_mbi_info_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_vm_set_mbi_info_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_mbi_rsp_struct *msgRsp = (mmi_sms_set_mbi_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    srv_sms_sim_enum sim_id;
    srv_sms_mailbox_struct *mailbox_info;
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_VM_SETTING_SET_MBI_INFO_CALLBACK, msgRsp->result);

    sim_id = handle->sim_id;
    index = srv_sms_sim_id_to_sim_index(sim_id);

    mailbox_info = srv_sms_get_mailbox_info(sim_id);

    if (msgRsp->result == MMI_TRUE)
    {
        voicemail_info[index].is_support_r4 = MMI_FALSE;
        mailbox_details->is_support_r4 = MMI_FALSE;
        mailbox_info->is_support_r4 = MMI_FALSE;
    }

    srv_sms_set_mailbox_info(sim_id, mailbox_details);

    srv_sms_setting_callback(
        MMI_TRUE,
        (void*)mailbox_details,
        handle->callback_func,
        handle->user_data);
    
    OslMfree(mailbox_details);
    mailbox_details = NULL;

    OslMfree(handle);

    srv_sms_get_voicemail_number(sim_id, NULL, NULL);
}


#else /* __MMI_MSG_REL4_SUPPORT__ */ 
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_voicemail_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_voicemail_number(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_VOICEMAIL_NUM);

    handle->sim_id = sim_id;
    handle->handle_data = NULL;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_read_sim_req(
        SRV_SMS_FILE_MAIL_ADDRESS,
        0,
        0,
        sim_id,
        srv_sms_get_voicemail_number_callback,
        (void*)handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_voicemail_number_callback
 * DESCRIPTION
 *  Get mailbox info response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sms_get_voicemail_number_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_mailbox_address_rsp_struct *msgRsp = (mmi_sms_get_mailbox_address_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    srv_sms_mailbox_struct mailbox_info;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_MAILBOX_INFO_CALLBACK, msgRsp->result);

    memset(&mailbox_info, 0, sizeof(srv_sms_mailbox_struct));
    
    if (msgRsp->result == MMI_TRUE)
    {
        mailbox_info.mailbox_number = msgRsp->mailbox_num;

        if (mailbox_info.mailbox_number > SRV_SMS_MAX_MAILBOX_NUM)
        {
            mailbox_info.mailbox_number = SRV_SMS_MAX_MAILBOX_NUM;
        }

        mailbox_info.mailbox_name_len = msgRsp->alpha_length;
        mailbox_info.mailbox_number_len = msgRsp->max_num_length;

        for (i = 0; i < mailbox_info.mailbox_number; i++)
        {
            U8 name_dcs = msgRsp->mailbox_info[i].name.name_dcs;
            U8 type = (msgRsp->mailbox_info[i].number_info.type == CSMCC_INTERNATIONAL_ADDR) ? 1 : 0;
            U8 num_length = msgRsp->mailbox_info[i].number_info.length;
            U8 name_length = msgRsp->mailbox_info[i].name.name_length;
            U8* vm_name = msgRsp->mailbox_info[i].name.name;
            U8* vm_number = msgRsp->mailbox_info[i].number_info.number;
 
            if (num_length > msgRsp->max_num_length)
            {
                num_length = msgRsp->max_num_length;
            }

            if ((type + num_length) > MAX_CC_ADDR_LEN)
            {
                num_length = MAX_CC_ADDR_LEN - type;
            }

            if (name_length > msgRsp->alpha_length)
            {
                name_length = msgRsp->alpha_length;
            }

            if (name_length > 0)
            {
                /* add null terminator */
                if (name_dcs == PHB_ASCII)
                {
                    if (name_length < sizeof(vm_name))
                    {
                        vm_name[name_length] = 0;
                    }
                }
            #ifdef __PHB_0x81_SUPPORT__
                else if ((name_dcs == PHB_UCS2) || (name_dcs == PHB_UCS2_81) || (name_dcs == PHB_UCS2_82))
                {
                    if ((name_length + 1) < sizeof(vm_name))
                    {
                        vm_name[name_length] = 0;
                        vm_name[name_length + 1] = 0;
                    }
                }
            #endif /* __PHB_0x81_SUPPORT__ */ 
                else
                {
                    name_dcs = PHB_UCS2;

                    if ((name_length + 1) < sizeof(vm_name))
                    {
                        vm_name[name_length] = 0;
                        vm_name[name_length + 1] = 0;
                    }
                }

                InputboxConvertGSMToDeviceEncoding(
                    vm_name,
                    mailbox_info.p_mailbox_name[i],
                    name_length,
                    ((name_length + 1) * ENCODING_LENGTH),
                    name_dcs,
                    0,
                    1);
            }

            mailbox_info.mailbox_name_dcs[i] = name_dcs;

            if (type)
            {
                mmi_asc_to_ucs2((CHAR*) mailbox_info.p_mailbox_number[i], (CHAR*) "+");
            }

            mmi_asc_n_to_ucs2(
                (CHAR*) (mailbox_info.p_mailbox_number[i] + (type * ENCODING_LENGTH)),
                (CHAR*)vm_number,
                num_length);
  
            memset(mailbox_info.p_mailbox_number[i] + ((type + num_length) * ENCODING_LENGTH), 0, ENCODING_LENGTH);
        }
    }

    srv_sms_setting_callback(
        msgRsp->result,
        (void*)&mailbox_info,
        handle->callback_func,
        handle->user_data);

    if (msgRsp->result == MMI_TRUE)
    {
        srv_sms_mailbox_struct *mailbox_info_temp;

        mailbox_info_temp = srv_sms_get_mailbox_info(handle->sim_id);

        memcpy(mailbox_info_temp, &mailbox_info, sizeof(srv_sms_mailbox_struct));
    }

    OslMfree(handle);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_voicemail_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_voicemail_number(
                srv_sms_mailbox_edit_struct *mailbox,
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_mailbox_address_req_struct *msgReq;
    CHAR mailbox_address[MAX_CC_ADDR_LEN + 1];
    srv_sms_setting_handle_struct *handle = OslMalloc(sizeof(srv_sms_setting_handle_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_VOICEMAIL_NUM);

    mailbox_details = OslMalloc(sizeof(srv_sms_mailbox_edit_struct));
    memcpy(mailbox_details, mailbox, sizeof(srv_sms_mailbox_edit_struct));

    msgReq = (mmi_sms_set_mailbox_address_req_struct*) OslConstructDataPtr(sizeof(*msgReq));

    if (mailbox->mailbox_name_dcs == PHB_UCS2)
    {
        msgReq->name.name_dcs = PHB_UCS2;
        msgReq->name.name_length = ((U8) mmi_ucs2strlen((CHAR*) mailbox->mailbox_name)) * ENCODING_LENGTH;
        InputboxConvertDeviceEncodingToGSM(
            (PU8) mailbox->mailbox_name,
            msgReq->name.name,
            SRV_SMS_MAX_PROFILE_NAME_LEN,
            PHB_UCS2,
            0,
            1);
    }
    else
    {
        msgReq->name.name_dcs = PHB_ASCII;
        msgReq->name.name_length = InputboxConvertDeviceEncodingToGSM(
                                    (PU8) mailbox->mailbox_name,
                                    msgReq->name.name,
                                    SRV_SMS_MAX_PROFILE_NAME_LEN+1,
                                    PHB_ASCII,
                                    0,
                                    1) - 1;
    }

    msgReq->name.name[msgReq->name.name_length] = '\0';

    mmi_ucs2_to_asc(mailbox_address, (CHAR*) mailbox->mailbox_address);

    srv_sms_convert_ascii_num_to_l4_num(&msgReq->num_addr, (U8*)mailbox_address);

    msgReq->mailbox_num = mailbox->mailbox_index;

    handle->sim_id = sim_id;
    handle->handle_data = mailbox_details;
    handle->callback_func = callback_func;
    handle->user_data = user_data;

    srv_sms_write_sim_req(
        SRV_SMS_FILE_MAIL_ADDRESS,
        0,
        sizeof(mmi_sms_set_mailbox_address_req_struct),
        (void*)msgReq,
        sim_id,
        srv_sms_set_voicemail_number_callback,
        (void*)handle);

    OslMfree(msgReq);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_voicemail_number_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_set_voicemail_number_callback(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_set_mailbox_address_rsp_struct *msgRsp = (mmi_sms_set_mailbox_address_rsp_struct*) callback_data->data;
    srv_sms_setting_handle_struct *handle = (srv_sms_setting_handle_struct*)callback_data->user_data;
    srv_sms_mailbox_edit_struct *mailbox_detail = (srv_sms_mailbox_edit_struct*) handle->handle_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_MAILBOX_INFO_CALLBACK, msgRsp->result);

    if (msgRsp->result == MMI_TRUE)
    {
        srv_sms_set_mailbox_info(handle->sim_id, mailbox_detail);
    }

    srv_sms_setting_callback(
        msgRsp->result,
        (void*)mailbox_detail,
        handle->callback_func,
        handle->user_data);

    if (mailbox_detail != NULL)
    {
        OslMfree(mailbox_detail);
		mailbox_details = NULL;
    }

    OslMfree(handle);
}


#endif /* __MMI_MSG_REL4_SUPPORT__ */ 


#ifdef __MMI_MESSAGES_SMS_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_active_email_sc_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_get_active_email_sc_addr(
                srv_sms_sim_enum sim_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error_code = 0;
    CHAR nvram_active_profile_index = 0;
    srv_sms_nvram_email_struct info_struct;
    CHAR email_addr_no[(SRV_SMS_MAX_ADDR_LEN + 1) * ENCODING_LENGTH];
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &nvram_active_profile_index, DS_BYTE, &error_code);

    if ( ReadRecord(
        NVRAM_EF_SMS_EMAIL_LID,
        (U16) (nvram_active_profile_index + 1),
        &info_struct,
        NVRAM_SMS_EMAIL_RECORD_SIZE,
        &error_code) < 0)
    {
        result = MMI_FALSE;
    }
    else
    {
        mmi_asc_to_ucs2(email_addr_no, (CHAR*) info_struct.email_addr_no);
        mmi_ucs2ncpy(email_sc_addr, email_addr_no, SRV_SMS_MAX_ADDR_LEN);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_ACTIVE_EMAIL_SC, nvram_active_profile_index, result);

    srv_sms_setting_callback(result, (void *)email_addr_no, callback_func, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_active_email_sc_addr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_set_active_email_sc_addr(
            U8 sc_addr[],
            SrvSmsCallbackFunc callback_func,
            void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error_code = 0;
    CHAR nvram_active_profile_index = 0;
    srv_sms_nvram_email_struct info_struct;
    MMI_BOOL result = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SMS_ACTIVE_PROFILE_INDEX, &nvram_active_profile_index, DS_BYTE, &error_code);

    mmi_ucs2_to_asc((CHAR*)info_struct.email_addr_no, (CHAR*)sc_addr);

    if (WriteRecord(
            NVRAM_EF_SMS_EMAIL_LID,
            (U16) (nvram_active_profile_index + 1),
            (void*)&info_struct,
            NVRAM_SMS_EMAIL_RECORD_SIZE,
            &error_code) < 0)
    {
        result = MMI_FALSE;
    }
    else
    {
        mmi_ucs2ncpy(email_sc_addr, (CHAR*)sc_addr, SRV_SMS_MAX_ADDR_LEN);
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_ACTIVE_EMAIL_SC, nvram_active_profile_index, result);

    srv_sms_setting_callback(result, NULL, callback_func, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_sms_pid_req
 * DESCRIPTION
 *  Get sms pid request
 * PARAMETERS
 *  index       [IN]        The index of profile
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_sms_pid_req(U8 index, srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile_index = index;    /* ????????????????? */

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_SMS_PID_REQ, index, sim_id);

    srv_sms_read_sim_req(
        SRV_SMS_FILE_DETAIL_FROFILE,
        (U16)index,
        0,
        sim_id,
        srv_sms_get_sms_pid_rsp,
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_sms_pid_rsp
 * DESCRIPTION
 *  Get sms pid response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_get_sms_pid_rsp(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_profile_params_rsp_struct *msgRsp = (mmi_sms_get_profile_params_rsp_struct*) callback_data->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRsp->result == TRUE)
    {
        g_srv_sms_email_pid = msgRsp->pid;
    }
    else
    {
        g_srv_sms_email_pid = SRV_SMS_PID_DEFAULT;
    }

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_GET_SMS_PID_RSP, msgRsp->result, msgRsp->pid);
}

#endif /* __MMI_MESSAGES_SMS_EMAIL__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_actived_profile_pid
 * DESCRIPTION
 *  Get mailbox mailbox select profile info
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_sms_get_actived_profile_pid(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    return g_srv_sms_email_pid;
#else
    return (U8)SRV_SMS_PID_DEFAULT;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_miscell_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_get_miscell_setting(srv_sms_sim_enum sim_id, srv_sms_miscell_setting_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 errorCode = 0;
    CHAR nvramByte = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValue(NVRAM_SMS_MISCELL_SETTING, &nvramByte, DS_BYTE, &errorCode);

    if (nvramByte & type)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_set_miscell_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  type        [IN]        
 *  flag        [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL srv_sms_set_miscell_setting(srv_sms_sim_enum sim_id, srv_sms_miscell_setting_enum type, MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error_code = 0;
    CHAR nvram_byte = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_SET_MISCELL_SETTING, type, flag);

    ReadValue(NVRAM_SMS_MISCELL_SETTING, &nvram_byte, DS_BYTE, &error_code);

    if (flag)
    {
        nvram_byte |= type;
    }
    else
    {
        nvram_byte &= ~type;
    }

    WriteValue(NVRAM_SMS_MISCELL_SETTING, &nvram_byte, DS_BYTE, &error_code);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_setting_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_setting_callback(
                MMI_BOOL result,
                void *action_data,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_callback_struct callback_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_CALLBACK, result, callback_func);

    if (callback_func != NULL)
    {
        callback_data.result = result;
        callback_data.user_data = user_data;
        callback_data.action_data = action_data;

        callback_func(&callback_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_setting_event_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_sms_setting_event_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_sms_disp_struct *event_data = (mmi_evt_sms_disp_struct*)evt;
    mmi_sms_startup_read_ind_struct *read_ind = (mmi_sms_startup_read_ind_struct*)event_data->data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_EVENT_PROC, event_data->sim_id);

    switch (event_data->msg_id)
    {
        case PTR_MSG_ID_SRV_SMS_STARTUP_READ_IND:
            /* Check the SIM Card's state, is Valid? */
            if (read_ind->sim_status == L4C_SIM_INSERTED)
            {
                /* Init setting info */
                srv_sms_sim_enum sim_id = (srv_sms_sim_enum)event_data->sim_id;

                if ((sim_id == SRV_SMS_SIM_1)
                #if (MMI_MAX_SIM_NUM >= 2)
                    || (sim_id == SRV_SMS_SIM_2)
                #if (MMI_MAX_SIM_NUM >= 3)
                    || (sim_id == SRV_SMS_SIM_3)
                #if (MMI_MAX_SIM_NUM >= 4)
                    || (sim_id == SRV_SMS_SIM_4)
                #endif /*  (MMI_MAX_SIM_NUM >= 4) */
                #endif /*  (MMI_MAX_SIM_NUM >= 3) */  
                #endif /*  (MMI_MAX_SIM_NUM >= 2) */
                   )
                {
                    U32 index = srv_sms_sim_id_to_sim_index(sim_id);
                    init_require[index] = (srv_sms_init_setting_require_enum)0;
                    srv_sms_init_sim_setting(sim_id);
                }
            }
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_init_sim_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_init_sim_setting(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 index = srv_sms_sim_id_to_sim_index(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = srv_sms_sim_id_to_sim_index(sim_id);

    if ((init_require[index] & SRV_SMS_INIT_PROFILE_DETAIL) != SRV_SMS_INIT_PROFILE_DETAIL)
    {
        srv_sms_sim_enum *data = OslMalloc(sizeof(srv_sms_sim_enum));
        *data = sim_id;

        srv_sms_read_sim_req(
            SRV_SMS_FILE_PROFILE_NUM,
            0,
            0,
            sim_id,
            srv_sms_pre_init_profile_detail,
            data);
    }
    else if ((init_require[index] & SRV_SMS_INIT_COMMON_SETTING) != SRV_SMS_INIT_COMMON_SETTING)
    {
        srv_sms_sim_enum *data = OslMalloc(sizeof(srv_sms_sim_enum));
        *data = sim_id;

        srv_sms_get_common_settings(sim_id, srv_sms_init_common_settings, data);
    }
    else if ((init_require[index] & SRV_SMS_INIT_MAILBOX_INFO) != SRV_SMS_INIT_MAILBOX_INFO)
    {
        srv_sms_sim_enum *data = OslMalloc(sizeof(srv_sms_sim_enum));
        *data = sim_id;

    #ifdef __MMI_MSG_REL4_SUPPORT__
        if (srv_sms_check_r4_support() == MMI_TRUE)
        {
            voicemail_info[index].is_support_r4 = MMI_TRUE;
        }
        else
        {
            voicemail_info[index].is_support_r4 = MMI_FALSE;
        }
    #endif /* __MMI_MSG_REL4_SUPPORT__ */

        srv_sms_get_voicemail_number(sim_id, srv_sms_init_mailbox_info, data);
    }
#ifdef __MMI_MESSAGES_SMS_EMAIL__
    else if ((sim_id == SRV_SMS_SIM_1) && ((init_require[index] & SRV_SMS_INIT_EMAIL_SC) != SRV_SMS_INIT_EMAIL_SC))
    {
        srv_sms_sim_enum *data = OslMalloc(sizeof(srv_sms_sim_enum));
        *data = sim_id;
        srv_sms_get_active_email_sc_addr(sim_id, srv_sms_init_email_sc_address, data);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_setting_get_profile_data_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_sms_setting_get_profile_data_id(srv_sms_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 item_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (sim_id)
    {
    #if  (MMI_MAX_SIM_NUM >= 2)
        case SRV_SMS_SIM_2:
            item_id = NVRAM_SIM2_ACTIVE_PROFILE_IDX;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 3)
        case SRV_SMS_SIM_3:
            item_id = NVRAM_SIM3_ACTIVE_PROFILE_IDX;
            break;
    #endif

    #if (MMI_MAX_SIM_NUM >= 4)
        case SRV_SMS_SIM_4:
            item_id = NVRAM_SIM4_ACTIVE_PROFILE_IDX;
            break;
    #endif

        case SRV_SMS_SIM_1:
        default:
            item_id = NVRAM_SMS_ACTIVE_PROFILE_INDEX;
            break;
    }

    return item_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_pre_init_profile_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
static void srv_sms_pre_init_profile_detail(srv_sms_disp_cb_struct *callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sms_get_profile_num_rsp_struct *msgRsp = (mmi_sms_get_profile_num_rsp_struct*) callback_data->data;
    srv_sms_sim_enum *data = (srv_sms_sim_enum*) callback_data->user_data;
    srv_sms_sim_enum sim_id = *data;
    U8 nvram_active_profile_index = 0;
    S16 error_code = 0;
    U16 data_item_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_PRE_INIT_PROFILE_DETAIL, msgRsp->result);

    if (msgRsp->result == MMI_TRUE)
    {
        data_item_id = srv_sms_setting_get_profile_data_id(sim_id);

        ReadValue(data_item_id, &nvram_active_profile_index, DS_BYTE, &error_code);

        if (nvram_active_profile_index > msgRsp->profile_no)// || nvram_active_profile_index <= (CHAR)-1)
        {
            nvram_active_profile_index = 0;
            WriteValue(data_item_id, &(nvram_active_profile_index), DS_BYTE, &error_code);
        }

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_PRE_INIT_PROFILE_DETAIL_1, nvram_active_profile_index);

        srv_sms_get_profile_detail((U8*)&nvram_active_profile_index, sim_id, srv_sms_init_profile_detail, data);
    }
    else
    {
        U32 index = srv_sms_sim_id_to_sim_index(sim_id);

        init_require[index] |= SRV_SMS_INIT_PROFILE_DETAIL;

        OslMfree(data);

        srv_sms_init_sim_setting(sim_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_init_profile_detail
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_init_profile_detail(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_profile_struct *msgRsp = (srv_sms_profile_struct*) callback_data->action_data;
    srv_sms_sim_enum *data = (srv_sms_sim_enum*) callback_data->user_data;
    srv_sms_sim_enum sim_id = *data;
    U32 index = srv_sms_sim_id_to_sim_index(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_INIT_PROFILE_DETAIL_CALLBACK);

    if (callback_data->result == MMI_TRUE)
    {
        srv_sms_set_default_profile_setting(sim_id, msgRsp);
    }

    init_require[index] |= SRV_SMS_INIT_PROFILE_DETAIL;

    OslMfree(data);

    srv_sms_init_sim_setting(sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_init_common_settings
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_init_common_settings(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *msgRsp = (U8*) callback_data->action_data;
    srv_sms_sim_enum *data = (srv_sms_sim_enum*) callback_data->user_data;
    srv_sms_sim_enum sim_id = *data;
    U32 index = srv_sms_sim_id_to_sim_index(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_INIT_COMMON_SETTING_CALLBACK);

    if (callback_data->result == MMI_TRUE)
    {
        setting_cntx[index].default_setting.status_report =  (MMI_BOOL)msgRsp[0];
        setting_cntx[index].default_setting.reply_path =  (MMI_BOOL)msgRsp[1];
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_INIT_COMMON_SETTING_CALLBACK_1, msgRsp[0], msgRsp[1]);
    }

    init_require[index] |= SRV_SMS_INIT_COMMON_SETTING;

    OslMfree(data);
 
    srv_sms_init_sim_setting(sim_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_sms_init_mailbox_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_init_mailbox_info(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum *data = (srv_sms_sim_enum*) callback_data->user_data;
    srv_sms_sim_enum sim_id = *data;
    U32 index = srv_sms_sim_id_to_sim_index(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_INIT_MAILBOX_INFO_CALLBACK);

    init_require[index] |= SRV_SMS_INIT_MAILBOX_INFO;

    OslMfree(data);

    srv_sms_init_sim_setting(sim_id);
}


#ifdef __MMI_MESSAGES_SMS_EMAIL__
/*****************************************************************************
 * FUNCTION
 *  srv_sms_init_email_sc_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_sms_init_email_sc_address(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_sim_enum *data = (srv_sms_sim_enum*) callback_data->user_data;
    srv_sms_sim_enum sim_id = *data;
    U32 index = srv_sms_sim_id_to_sim_index(sim_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_SETTING_INIT_EMAIL_SC_CALLBACK);

    init_require[index] |= SRV_SMS_INIT_EMAIL_SC;

    OslMfree(data);

    srv_sms_init_sim_setting(sim_id);
}
#endif /* __MMI_MESSAGES_SMS_EMAIL__ */


/*****************************************************************************
 * FUNCTION
 *  srv_sms_get_mailbox_name
 * DESCRIPTION
 *  Find name correspond to number
 * PARAMETERS
 *  sim_id          [IN]        srv_sms_sim_enum
 *  ucs2_num        [IN]        U16 *ucs2_num[(MAX_CC_ADDR_LEN +1]
 *  ucs2_name       [OUT]       U16 *ucs2_name[SRV_SMS_MAX_PROFILE_NAME_LEN + 1]
 *                              The buffer need caller molloc and free
 * RETURNS
 *  MMI_BOOL        if find name correspond to number, return MMI_TRUE;
 *                   else if not find, return MMI_FALSE.
 *****************************************************************************/
MMI_BOOL srv_sms_get_mailbox_name(srv_sms_sim_enum sim_id, U16 *ucs2_num, U16 *ucs2_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_mailbox_struct *mailbox_info;
    MMI_BOOL result = MMI_FALSE;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mailbox_info = srv_sms_get_mailbox_info(sim_id);

    for (i = 0; i < mailbox_info->mailbox_number; i++)
    {
        U16 ucs2_num2[MAX_CC_ADDR_LEN + 1];
        memcpy((CHAR*)ucs2_num2, (CHAR*)mailbox_info->p_mailbox_number[i], (MAX_CC_ADDR_LEN + 1) *ENCODING_LENGTH);

        result = srv_phb_compare_number(ucs2_num, ucs2_num2);
        if (result == MMI_TRUE)
        {
            memcpy((CHAR*)ucs2_name, (CHAR*)mailbox_info->p_mailbox_name[i], (SRV_SMS_MAX_PROFILE_NAME_LEN + 1) *ENCODING_LENGTH);
            break;
        }
    }

    return result;
}

#endif /* __MOD_SMSAL__ */
