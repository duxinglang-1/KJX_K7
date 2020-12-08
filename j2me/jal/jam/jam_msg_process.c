/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * --------- 
 *   j2me_msg_handler.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements J2ME message handler definition
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

/*************************************************************************
 * Include Statements
 *************************************************************************/

#include "MMI_features.h"
#include "jal.h"
#include "jnw_internal.h"
#include "jvm_internal.h"
#include "jvm_adaptor.h"
#include "jam_internal.h"
#include "jui_interface.h"
#include "jma_internal.h"
#include "jam_msg_handler.h"
#include "jam_interface.h"
#include "j2me_custom.h"
#include "JavaAgencyDef.h"
#include "JavaAgencyGProt.h"
#include "JavaAgencyProt.h"
#include "wgui_categories.h"

#ifdef __DRM_SUPPORT__
#include "DateTimeType.h"
#include "drm_def.h"
#include "drm_gprot.h"
#endif /* __DRM_SUPPORT__ */ 

#include "jwa_internal.h"
#include "j2me_custom_option.h"
#include "j2me_custom_param.h"
#include "app_mem.h"
#include "mmi_frm_gprot.h"

#define MMIAPI_USING_SMS
#include "mmiapi_struct.h"

#include "cbm_api.h"
#include "mmc_struct.h"

/* PKI */
#ifdef __SSL_SUPPORT__
#include "app_datetime.h"
#include "certman_api.h"
#include "pki_api.h"
#endif
#include "jsec_interface.h"
#include "Dtcntsrvgprot.h"
#include "Jam_mvm_manager.h"

/*************************************************************************
 * External Declaration
 *************************************************************************/

/* Local Function Declaration */
extern char g_jam_ota_user_name[];
extern char g_jam_ota_passwd[];

#ifdef __SSL_SUPPORT__
extern certman_validate_cnf_struct *verify_cnf;
#endif

kal_int32 g_jvm_get_next_event_result;
#ifdef __MTK_TARGET__
static kal_uint8 g_jam_sleep_handle = 0xFF;
#endif
/*************************************************************************
 * Global Definition
 *************************************************************************/
install_update_struct install_update_status =
    {KAL_FALSE, KAL_FALSE, KAL_FALSE, KAL_FALSE, KAL_FALSE, 0, KAL_FALSE, KAL_FALSE, KAL_FALSE};
install_report_info_struct g_jam_install_report = {-1,NULL,NULL,NULL,NULL};

srv_dtcnt_prof_proxy_info_cnf_struct net_prof[MAX_VM_INSTANCE_NUM];
srv_dtcnt_prof_proxy_info_cnf_struct net_prof_temp;
srv_dtcnt_prof_proxy_info_cnf_struct net_prof_install;
kal_uint32 g_jam_install_acc_id;
extern kal_bool g_jam_brw_profile_is_success;

kal_bool g_jam_is_jvm_in_busy = KAL_TRUE;
kal_bool g_jam_is_jam_in_busy = KAL_FALSE;


jam_task_state g_jam_task_state = JAM_TASK_IN_INIT;

kal_int32 g_jam_engineer_mode_memory_size = -1;

extern java_context_struct g_java;
kal_bool g_jam_install_abort = KAL_FALSE;

/*************************************************************************
 * Local Definition
 *************************************************************************/

/*************************************************************************
 * Message Handler Table
 *************************************************************************/
#ifdef OGDR_SECURITY_SETTING
kal_char *g_jam_operator_domain_str_tbl[] = { "OPERATOR", NULL};
kal_char *g_jam_manufacturer_domain_str_tbl[] = { "MANUFACTURER", NULL};
kal_char *g_jam_thirdparty_domain_str_tbl[] = { "THIRDPARTY", "3RD-DMN", "3rdparty", NULL};
kal_char *g_jam_untrusted_domain_str_tbl[] = { "UNTRUSTED", NULL};


/*****************************************************************************
 * FUNCTION
 *  jam_domain_compare
 * DESCRIPTION
 *  Compare security domain.
 * PARAMETERS
 *  domain              [?]         Input domain string retrieved from security policy
 *  domain_index        [IN]        One of domain_enum.
 * RETURNS
 *  kal_bool  KAL_TRUE if string matches
 *****************************************************************************/
kal_bool jam_domain_compare(kal_wchar *domain, kal_int32 domain_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char **str_tbl;
    kal_int32 str_index = 0;
    kal_int32 tbl_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (domain_index)
    {
        case JAM_OPERATOR_DOMAIN:
            str_tbl = g_jam_operator_domain_str_tbl;
            break;
        case JAM_MANUFACTURER_DOMAIN:
            str_tbl = g_jam_manufacturer_domain_str_tbl;
            break;
        case JAM_THIRDPARTY_DOMAIN:
            str_tbl = g_jam_thirdparty_domain_str_tbl;
            break;
        case JAM_UNTRUSTED_DOMAIN:
            str_tbl = g_jam_untrusted_domain_str_tbl;
            break;
        default:
            return KAL_FALSE;
    }
    while (str_tbl[tbl_index] != NULL)
    {
        while (domain[str_index] == str_tbl[tbl_index][str_index] ||
               domain[str_index] == str_tbl[tbl_index][str_index] + 32)
        {
            if (domain[str_index] == 0)
            {
                return KAL_TRUE;
            }
            str_index++;
        }
        tbl_index++;
    }
    return KAL_FALSE;
}

#endif /* OGDR_SECURITY_SETTING */ 


/*****************************************************************************
 * FUNCTION
 *  jam_success_call_back
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void jam_success_call_back(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
 * FUNCTION
 *  jam_vm_is_busy
 * DESCRIPTION
 *  This function can be used by any task that has higher priority than Java task
 *  to test if Java is in storage recovery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jam_vm_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (MAX_VM_INSTANCE_NUM == 1)
    kal_trace(TRACE_FUNC, FUNC_JAM_VM_IS_BUSY, g_jam_is_jvm_in_busy);
    return g_jam_is_jvm_in_busy || g_jam_is_jam_in_busy || jam_is_own_screen();
#else
	return KAL_FALSE;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  jam_is_busy
 * DESCRIPTION
 *  This function can be used by any task that has higher priority than Java task
 *  to test if Java is in storage recovery
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jam_is_busy(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_JAM_VM_IS_BUSY, g_jam_is_jam_in_busy);
    return (g_jam_is_jam_in_busy);
}

/*****************************************************************************
 * FUNCTION
 *  jam_vm_task_ready
 * DESCRIPTION
 *  This function is used to prevent MMI installing, updating, or any unpredictable operation
 *  if JVM task is not ready yet ( may on cleaning Java storage )
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool jam_vm_task_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (kal_bool)(g_jam_task_state == JAM_TASK_IN_MAIN);
}



/*****************************************************************************
 * FUNCTION
 *  get_event_general
 * DESCRIPTION
 *  
 * PARAMETERS
 *  wait_forever        [IN]        
 *  wait_in_ms          [IN]        
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 get_event_general(kal_bool wait_forever, kal_uint32 wait_in_ms)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 temp_time;
    kal_int64 start_time, current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&temp_time);
    start_time = temp_time;
	/* get sleep handle */
#ifdef __MTK_TARGET__
	if (g_jam_sleep_handle == 0xFF)
	{
		g_jam_sleep_handle = L1SM_GetHandle();
	}
	ASSERT(g_jam_sleep_handle != 0xFF);
	L1SM_SleepDisable(g_jam_sleep_handle);
#endif
    if (wait_forever || wait_in_ms != 0)
    {
        jvm_keypad_register_notify();
    }

    do
    {
        kal_status status = KAL_Q_EMPTY;
        kal_uint16 msg_size;

        status = kal_deque_msg(task_info_g[INDX_J2ME].task_ext_qid, (void*)&current_ilm, &msg_size, KAL_NO_WAIT);

        if (status == KAL_SUCCESS)
        {
            kal_trace(TRACE_FUNC, FUNC_J2ME_GET_NEXT_EVENT, -1, current_ilm.msg_id);

            /* we should process common event first. add by hjf, modified by Justin */
            if (j2me_task_general_msg_handler(&current_ilm) && current_ilm.msg_id != MSG_ID_MMI_JAVA_ABORT_REQ)
            {
                free_ilm(&current_ilm);
            #ifdef __MTK_TARGET__
            L1SM_SleepEnable(g_jam_sleep_handle);
            #endif
                return J2ME_NO_ERROR;
            }
            /* handle abort from MMI or WAP */
            if (current_ilm.msg_id == MSG_ID_MMI_JAVA_ABORT_REQ)
            {
                mmi_java_abort_req_struct *abort_req_ptr;
                mmi_java_abort_cnf_struct *abort_cnf_ptr;

                abort_req_ptr = (mmi_java_abort_req_struct*) current_ilm.local_para_ptr;

                abort_cnf_ptr = construct_local_para(sizeof(mmi_java_abort_cnf_struct), TD_CTRL);
                abort_cnf_ptr->error_code = J2ME_NO_ERROR;

                /* ??? can check_incoming_call_and_block() be removed? */
                check_incoming_call_and_block();
                java_send_msg_from_active_mod(MOD_MMI,J2ME_MMI_SAP,MSG_ID_MMI_JAVA_ABORT_CNF,abort_cnf_ptr);

                /* the message should be freed here!!! */
                free_ilm(&current_ilm);
            #ifdef __MTK_TARGET__
				L1SM_SleepEnable(g_jam_sleep_handle);
            #endif
                return J2ME_USER_CANCEL;
            }
            /* unknow event */

            kal_trace(TRACE_FUNC, FUNC_J2ME_GET_NEXT_EVENT_CLEAN, current_ilm.msg_id);
            free_ilm(&current_ilm);
        #ifdef __MTK_TARGET__
			L1SM_SleepEnable(g_jam_sleep_handle);
        #endif
            return J2ME_NO_ERROR;
        }
        else if (status == KAL_Q_EMPTY)
        {
        #ifdef __JBLENDIA__
            kal_uint32 flag = 0;
        #endif 
            if (wait_forever)
            {
                /* Sleep for a while, and polling again. */
                kal_sleep_task(10);
                continue;
            }

            if (wait_in_ms == 0)
            {
            #ifdef __MTK_TARGET__
				L1SM_SleepEnable(g_jam_sleep_handle);
            #endif
                return -1;
            }

        #ifdef __JBLENDIA__
            kal_retrieve_eg_events(jblendia_eventgroup, JBLENDIA_SYS_EVENT, KAL_OR_CONSUME, &flag, KAL_NO_SUSPEND);

            if (flag & JBLENDIA_SYS_EVENT)
            {
                //kal_prompt_trace(MOD_JAM, "get_event_general returns!");
            #ifdef __MTK_TARGET__
				L1SM_SleepEnable(g_jam_sleep_handle);
            #endif
                return J2ME_NO_ERROR;
            }
        #endif /* __JBLENDIA__ */ 

            kal_get_time(&temp_time);

            current_time = temp_time;

            if (current_time >= start_time)
            {
                if ((((current_time - start_time) * 4725) >> 10) > (kal_int64) wait_in_ms)
                {
                #ifdef __MTK_TARGET__
					L1SM_SleepEnable(g_jam_sleep_handle);
                #endif
                    return -1;
                }
            }
            else
            {
                if (((((0xFFFFFFFFL) - start_time + current_time) * 4725) >> 10) > (kal_int64) wait_in_ms)
                {
                #ifdef __MTK_TARGET__
					L1SM_SleepEnable(g_jam_sleep_handle);
                #endif
                    return -1;
                }
            }
            /* Sleep for a while, and polling again. */
            kal_sleep_task(10);
        }
        else
        {
            ASSERT(0);
        }
    } while (wait_forever || wait_in_ms > 0);
#ifdef __MTK_TARGET__
	L1SM_SleepEnable(g_jam_sleep_handle);
#endif
    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  get_next_event
 * DESCRIPTION
 *  get next event
 * PARAMETERS
 *  wait_forever            [IN]        
 *  expected_msg            [IN]        
 *  clean_msg               [IN]        
 *  must_match              [IN]        
 *  abort_msg_received      [?]         [?]
 * RETURNS
 *  The important information in the event
 *****************************************************************************/
/* static kal_int32 g_jvm_incoming_call_serial_for_install = 0; */
kal_int32 get_next_event(
            kal_bool wait_forever,
            msg_type expected_msg,
            kal_bool clean_msg,
            kal_bool must_match,
            kal_bool *abort_msg_received)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_int32 returnValue = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  reGetMessage:
    /* Wait forever case */
    /* Wait forever case */
    do
    {
        kal_status status = KAL_Q_EMPTY;
        kal_uint16 msg_size;

        if (g_jam_is_op_715  && (install_update_status.is_normal_install || install_update_status.is_update))
        {
            install_update_status.can_be_aborted = KAL_FALSE;
            install_update_status.is_aborted = KAL_TRUE;
            g_jam_allowed_sending_abort_from_idle = KAL_TRUE;
        }
        
        if( g_java.mids_install_state == INSTALL_ABORT_STATE &&!needToSendGetListReq)
        {
            g_jam_install_abort = KAL_TRUE;
            install_update_status.can_be_aborted = KAL_FALSE;
            install_update_status.is_aborted = KAL_TRUE;
            g_jam_allowed_sending_abort_from_idle = KAL_TRUE;
        }
            
        status = kal_deque_msg(task_info_g[INDX_JAM].task_ext_qid, (void*)&current_ilm, &msg_size, KAL_NO_WAIT);

        if (status == KAL_SUCCESS)
        {
            /* we should process common event first. add by hjf, modified by Justin */
            if (j2me_task_general_msg_handler(&current_ilm) && current_ilm.msg_id != MSG_ID_MMI_JAVA_ABORT_REQ&&current_ilm.msg_id !=MSG_ID_MMI_JAVA_ASM_ABORT_REQ)
            {
                free_ilm(&current_ilm);
                continue;
            }

            /* SHK: General message can not handle the incoming message. */
            break;
        }
        else if (status == KAL_Q_EMPTY)
        {
            if (!wait_forever)
            {
                return J2ME_NO_ERROR;
            }
            /* Sleep for a while, and polling again. */
            kal_sleep_task(10);
        }
        else
        {
            ASSERT(0);
        }
    } while (wait_forever);

    kal_trace(MOD_JAM, FUNC_J2ME_GET_NEXT_EVENT, expected_msg, current_ilm.msg_id);

    /* SHK: If we set must_match, then we fail to receive MSG_ID_MMI_JAVA_ABORT_REQ message. */
    if (must_match && current_ilm.msg_id != expected_msg)
    {
        if (current_ilm.msg_id == MSG_ID_MMI_JAVA_ABORT_REQ)
        {
            *abort_msg_received = KAL_TRUE;
        }
        free_ilm(&current_ilm);
        goto reGetMessage;
    }

    /* handle abort from MMI or WAP */
    switch (current_ilm.msg_id)
    {
        case MSG_ID_MMI_JAVA_ABORT_REQ:
        {
            mmi_java_abort_req_struct *abort_req_ptr;
            mmi_java_abort_cnf_struct *abort_cnf_ptr;
            ilm_struct *send_ilm;

            abort_req_ptr = (mmi_java_abort_req_struct*) current_ilm.local_para_ptr;

            abort_cnf_ptr = construct_local_para(sizeof(mmi_java_abort_cnf_struct), TD_CTRL);
            abort_cnf_ptr->error_code = J2ME_NO_ERROR;

            send_ilm = allocate_ilm(INDX_JAM);
            send_ilm->src_mod_id = INDX_JAM;
            send_ilm->dest_mod_id = MOD_MMI;
            send_ilm->local_para_ptr = (local_para_struct*) abort_cnf_ptr;
            send_ilm->peer_buff_ptr = NULL;
            send_ilm->msg_id = MSG_ID_MMI_JAVA_ABORT_CNF;
            send_ilm->sap_id = J2ME_MMI_SAP;

            /* ??? can check_incoming_call_and_block() be removed? */
            if(!jam_get_g_jam_exit_by_asm())
            {
            check_incoming_call_and_block();
            }
            msg_send_ext_queue(send_ilm);

            /* the message should be freed here!!! */
            free_ilm(&current_ilm);
            install_update_status.can_be_aborted = KAL_FALSE;
            install_update_status.is_aborted = KAL_TRUE;
            g_jam_allowed_sending_abort_from_idle = KAL_TRUE;
            if (abort_msg_received == NULL)
            {
                return 0;
            }
            else
            {
                *abort_msg_received = KAL_TRUE;
                return -1;
            }
        }
        case MSG_ID_MMI_JAVA_ASM_ABORT_REQ:
            *abort_msg_received = KAL_TRUE;
            return -1;
            /* MIDlet Start/Stop */
        case MSG_ID_MMI_JAVA_MID_START_REQ:
            jam_mid_start_req_handler(&current_ilm);
            break;

            /* Update MIDlet Suite */
        case MSG_ID_MMI_JAVA_MIDS_UPDATE_REQ:
            jam_mids_update_req_handler(&current_ilm);
            break;

            /* Remove MIDlet Suite */
        case MSG_ID_MMI_JAVA_MIDS_REMOVE_REQ:
            jam_mids_remove_req_handler(&current_ilm);
            break;
    }

    if (clean_msg)
    {
        kal_trace(MOD_JAM, FUNC_J2ME_GET_NEXT_EVENT_CLEAN, current_ilm.msg_id);
        free_ilm(&current_ilm);
        /* recursively call until message queue empty */
        goto reGetMessage;
    }

    /* check if the massage should be presented in the current state */
    {
        /* if (expected_msg == 0) {
           kal_int32 msg_indx = current_ilm.msg_id - j2me_current_state->msg_begin;
           if ((msg_indx < 0) || (msg_indx >= (kal_int32)j2me_current_state->msgs_limit) ) {
           ASSERT(msg_indx == 0);
           }
           } else
           EXT_ASSERT(current_ilm.msg_id == expected_msg, current_ilm.msg_id, expected_msg, 0); */
    }

    switch (current_ilm.msg_id)
    {
            /* remove MIDlet Suite confirm response */
        case MSG_ID_MMI_JAVA_MIDS_REMOVE_CONFIRM_RES:
        {

            mmi_java_mids_remove_confirm_res_struct *remove_res_ptr;

            remove_res_ptr = (mmi_java_mids_remove_confirm_res_struct*) current_ilm.local_para_ptr;
            if (remove_res_ptr->confirm == KAL_TRUE)
            {
                returnValue = (kal_int32) TRUE;
            }
            else
            {
                returnValue = (kal_int32) FALSE;
            }
            break;
        }

        case MSG_ID_MMI_JAVA_INSTALL_RESET_RMS_RES:
        {
            mmi_java_install_reset_rms_res_struct *reset_rms_res;

            reset_rms_res = (mmi_java_install_reset_rms_res_struct*) current_ilm.local_para_ptr;
            if (reset_rms_res->confirm == KAL_TRUE)
            {
                returnValue = (kal_int32) TRUE;
            }
            else
            {
                returnValue = (kal_int32) FALSE;
            }
            break;
        }

        case MSG_ID_MMI_JAVA_INSTALL_CONFIRM_RES:
        {
            mmi_java_install_confirm_res_struct *install_cnf_res;

            install_cnf_res = (mmi_java_install_confirm_res_struct*) current_ilm.local_para_ptr;
            if (install_cnf_res->confirm == KAL_TRUE)
            {
                returnValue = (kal_int32) TRUE;
            }
            else
            {
                returnValue = (kal_int32) FALSE;
            }
            break;
        }

            /* case MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_RES:
               {
               mmi_java_get_file_and_save_res_struct *get_file_res;
               get_file_res = (mmi_java_get_file_and_save_res_struct *)current_ilm.local_para_ptr;
               returnValue = get_file_res->progress;
               break;
               } */
        case MSG_ID_JAVA_WAP_GET_FILE_AND_SAVE_CNF:
        {
            java_wap_get_file_and_save_cnf_struct *get_file_cnf;

            get_file_cnf = (java_wap_get_file_and_save_cnf_struct*) current_ilm.local_para_ptr;
            download_error_code = get_file_cnf->download_error_code;
            returnValue = get_file_cnf->error_code;
            break;
        }
        case MSG_ID_JAVA_WAP_POST_DATA_CNF:
        {
            java_wap_post_data_cnf_struct *post_data_cnf;

            post_data_cnf = (java_wap_post_data_cnf_struct*) current_ilm.local_para_ptr;
            if (post_data_cnf->header != NULL)
            {
                free_ctrl_buffer(post_data_cnf->header);
            }
            if (post_data_cnf->error_code == J2ME_NO_ERROR)
            {
                returnValue = post_data_cnf->http_return_code;
            }
            else
            {
                returnValue = -1;
            }
            break;
        }
        case MSG_ID_MMI_JAVA_GET_FILE_AND_SAVE_RES:
        {
            returnValue = 0;
        }
            break;
       /* DA modify
        case MSG_ID_WAP_GET_PROF_CONTENT_RSP:
        {
            // backup the wap_get_prof_content_rsp_struct to wap_prof variable 
            memcpy((void*)&wap_prof, (void*)current_ilm.local_para_ptr, sizeof(wap_get_prof_content_rsp_struct));
        }*/
        case MSG_ID_SRV_DTCNT_PROF_PROXY_INFO_CNF:
            memcpy((void*)&net_prof_temp, (void*)current_ilm.local_para_ptr, sizeof(srv_dtcnt_prof_proxy_info_cnf_struct));
            break;
    #if defined(SUPPORT_JSR_205)
        case MSG_ID_WAP_MMC_GET_MMS_PROF_RSP:
        {
            wap_mmc_get_mms_prof_rsp_struct *mms_prof_rsp;

            mms_prof_rsp = (wap_mmc_get_mms_prof_rsp_struct*) current_ilm.local_para_ptr;

            memset(j2me_mms_mmsc_addr, 0, J2ME_MMS_MMSC_ADDR_LEN);

            if (mms_prof_rsp->result == 0)
            {   /* success */
                kal_int32 len = mms_prof_rsp->value_len;

                if (len > J2ME_MMS_MMSC_ADDR_LEN)
                {
                    len = J2ME_MMS_MMSC_ADDR_LEN;
                }

                memcpy((void*)j2me_mms_mmsc_addr, (void*)mms_prof_rsp->value, len);
            }
        }
            break;
    #endif /* defined(SUPPORT_JSR_205) */ 

            /* Get user agent header from WAP */
            /* case MSG_ID_WAP_GET_USER_AGENT_RSP:
               {
               wap_get_user_agent_rsp_struct *user_agent_rsp;
               
               user_agent_rsp = (wap_get_user_agent_rsp_struct*) current_ilm.local_para_ptr;
               
               jam_set_user_agent(user_agent_rsp->user_agent, user_agent_rsp->user_agent_len);
               }
               break;            */

#ifdef BROWSER_SUPPORT
        case MSG_ID_MMI_JAVA_NW_INSTALL_CNF:
            g_jam_brw_profile_is_success = ((jam_nw_install_data_struct*) current_ilm.local_para_ptr)->is_success;
            break;
#endif
        case MSG_ID_MMI_JAVA_GET_CONFIRM_RES:
        {
            returnValue = ((mmi_java_get_confirm_res_struct*) current_ilm.local_para_ptr)->confirm;
        }
            break;
        case MSG_ID_MMI_JAVA_GET_INSTALL_DRV_RES:
        {
            returnValue = ((mmi_java_get_install_drv_res_struct*) current_ilm.local_para_ptr)->drv;
        }
            break;
#ifdef __MMI_JAVA_CATEGORY_SUPPORT__
        case MSG_ID_MMI_JAVA_GET_INSTALL_CATEGORY_RES:
        {
            returnValue = ((mmi_java_get_install_category_res_struct*) current_ilm.local_para_ptr)->category;
        }
            break;
#endif /*__MMI_JAVA_CATEGORY_SUPPORT__*/
        case MSG_ID_MMS_GET_ACTIVE_MMS_ATTACHMENT_RSP:
        {
            mms_get_attachment_rsp_struct *msg = (mms_get_attachment_rsp_struct*) current_ilm.local_para_ptr;

            if (msg->result == MMC_RESULT_OK)
            {
                kal_int32 len = get_ucs2_len(msg->filepath);
                kal_wchar *file_path = get_ctrl_buffer((len << 1) + 2);

                memcpy(file_path, msg->filepath, (len << 1) + 2);
                returnValue = (kal_int32) file_path;
            }
            else
            {
                returnValue = 0;
            }
        }
            break;
        case MSG_ID_MMI_JAVA_GET_AUTH_RES:
        {
            kal_char username[MMI_JAVA_AUTH_LEN_USERNAME];
            kal_char password[MMI_JAVA_AUTH_LEN_USERNAME];
            mmi_java_get_auth_res_struct *msg = (mmi_java_get_auth_res_struct*) current_ilm.local_para_ptr;

            username[MMI_JAVA_AUTH_LEN_USERNAME - 1] = 0;
            password[MMI_JAVA_AUTH_LEN_PASSWORD - 1] = 0;
            trans_ucs2_to_utf8((kal_char*) username, (kal_wchar*) msg->username);
            trans_ucs2_to_utf8((kal_char*) password, (kal_wchar*) msg->password);
            
            username[MMI_JAVA_AUTH_LEN_USERNAME - 1] = 0;
            password[MMI_JAVA_AUTH_LEN_PASSWORD - 1] = 0;
            memcpy(g_jam_ota_user_name, username, MMI_JAVA_AUTH_LEN_USERNAME);
            memcpy(g_jam_ota_passwd, password, MMI_JAVA_AUTH_LEN_PASSWORD);


            returnValue = 0;
        }
            break;

        case MSG_ID_WPS_SEC_VERIFY_CERT_CHAIN_RSP:
        {
            wps_sec_verify_cert_chain_rsp_struct *verify_cert_chain_rsp;

            verify_cert_chain_rsp = (wps_sec_verify_cert_chain_rsp_struct*) current_ilm.local_para_ptr;

            jnw_http_verify_cert_chain_hdlr(
                verify_cert_chain_rsp->format,
                verify_cert_chain_rsp->root_len,
                verify_cert_chain_rsp->root_cert);
            returnValue = verify_cert_chain_rsp->result;
        }
        break;  

        case MSG_ID_WPS_CLEAR_RSP:
        {
            wps_clear_rsp_struct *p = (wps_clear_rsp_struct*) current_ilm.local_para_ptr;
            returnValue = jnw_http_clear_cache_rsp_hdlr(p->request_id, p->result);
        }
        break; 

        case MSG_ID_WPS_UNSET_CHANNEL_RSP:
        {
            wps_unset_channel_rsp_struct *p = (wps_unset_channel_rsp_struct*) current_ilm.local_para_ptr;
            returnValue = jnw_http_unset_channel_rsp_hdlr(p->channel_id, p->result);
        }
            break;

    #ifdef __SSL_SUPPORT__
        case MSG_ID_CERTMAN_VALIDATE_CNF:
	    {
		    certman_validate_cnf_struct *cnf = (certman_validate_cnf_struct *) current_ilm.local_para_ptr;

            memcpy(verify_cnf, cnf, sizeof(certman_validate_cnf_struct));
	    }
            break;
   #endif /* __SSL_SUPPORT__ */

        /*case MSG_ID_MMIAPI_SMS_GET_SMSC_ADDR_RSP:
		{
			mmiapi_sms_get_smsc_addr_rsp_struct *get_sms_prof_rsp; 
            get_sms_prof_rsp = (mmiapi_sms_get_smsc_addr_rsp_struct*) current_ilm.local_para_ptr;
			memset(j2me_sms_smsc_addr, 0, J2ME_SMS_SMSC_ADDR_LEN);
            if(get_sms_prof_rsp->result == MMI_FRM_SMS_OK)
			{
				memcpy(j2me_sms_smsc_addr, (char*)get_sms_prof_rsp->sc_addr, get_sms_prof_rsp->sc_addr_len);
            }
        }
		    break;*/

        default:
        {
            free_ilm(&current_ilm);
            goto reGetMessage;
        }
    }

    free_ilm(&current_ilm);
    return returnValue;
}

/*****************************************************************************
 * FUNCTION
 *  get_next_event
 * DESCRIPTION
 *  get next event
 * PARAMETERS
 *  wait_forever            [IN]        
 *  expected_msg            [IN]        
 *  clean_msg               [IN]        
 *  must_match              [IN]        
 *  abort_msg_received      [?]         [?]
 * RETURNS
 *  The important information in the event
 *****************************************************************************/
/* static kal_int32 g_jvm_incoming_call_serial_for_install = 0; */
kal_int32 jvm_send_and_get_next_event(
            ilm_struct *send_ilm,
            kal_bool wait_forever,
            msg_type expected_msg,
            kal_bool clean_msg,
            kal_bool must_match,
            kal_bool *abort_msg_received)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *input;
    kal_int32 input_len;
    kal_int32 cur = 0;
    kal_uint32 flag = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    input_len = sizeof(kal_bool)*3 + sizeof(msg_type) ;
    if (abort_msg_received)
    {
        input_len += sizeof(kal_bool*);
    }
    
    input = get_ctrl_buffer(input_len);
    if (abort_msg_received)
    {
        memcpy(input+cur,&abort_msg_received,sizeof(kal_bool*));
        cur += sizeof(kal_bool*); 
    }
    memcpy(input+cur,&wait_forever,sizeof(kal_bool));
    cur += sizeof(kal_bool);
    memcpy(input+cur,&expected_msg,sizeof(msg_type));
    cur += sizeof(msg_type);
    memcpy(input+cur,&clean_msg,sizeof(kal_bool));
    cur += sizeof(kal_bool);
    memcpy(input+cur,&must_match,sizeof(kal_bool));
    cur += sizeof(kal_bool); 
    
    
    jam_jvm_send_general_assist_req(JVM_GET_NEXT_EVENT_INDX, input, input_len);
    free_ctrl_buffer(input);
    msg_send(send_ilm);
    
    kal_retrieve_eg_events(g_java_event_group_2, JAVA_EG_JVM_GET_NEXT_EVENT_1, KAL_OR_CONSUME, &flag, KAL_SUSPEND);
    return g_jvm_get_next_event_result;
}

/*****************************************************************************
 * FUNCTION
 *  jam_set_engineer_mode_memory
 * DESCRIPTION
 *  
 * PARAMETERS
 *  size        [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool jam_set_engineer_mode_memory(kal_int32 size)
{
#if DATACACHE_FBBR_ON
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (size != 8 * 1024 * 1024 && size != 6 * 1024 * 1024 && size != 4 * 1024 * 1024 && size != 3 * 1024 * 1024 &&
        size != 2 * 1024 * 1024 && size != 1024 * 1024 && size != (512 + 1024) * 1024 &&
        size != (256 + 1024) * 1024 && size != 768 * 1024 && size != 512 * 1024)
    {
        return KAL_FALSE;
    }
#endif /* DATACACHE_FBBR_ON */ 
    g_jam_engineer_mode_memory_size = size;
    return KAL_TRUE;
}

