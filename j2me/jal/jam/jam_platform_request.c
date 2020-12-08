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
 *  jam_platform_request.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "mmi_include.h"
#include "wap_ps_struct.h"
#include "JavaAgencyGProt.h"
#include "mmiapi_struct.h"
#include "mmiapi_enum.h"
#include "mmiapi.h"
#include "jal.h"
#include "jal_internal.h"
#include "jam_msg_handler.h"
#include "wapadp.h"
#include "MediaAppGProt.h"
#include "ucmsrvgprot.h"
#include "cbm_api.h"
#include "SimCtrlSrvGprot.h"
#ifdef BROWSER_SUPPORT
#include "browser_struct.h"
#endif
#include "app_ua.h"

/* WAP User Agent. The size is determined by wap_get_user_agent_rsp_struct */
#ifndef __MVM__
static kal_uint8 g_jam_user_agent[256] = {0};
static kal_bool g_jam_parse_the_first_word = KAL_TRUE;
#endif /*__MVM__*/

/*****************************************************************************
 * FUNCTION
 *  jam_activate_wap_browser
 * DESCRIPTION
 *  launch browser and connet to the specified URL
 * PARAMETERS
 *  url     [?]     [?]     URL address in ascii encoding
 * RETURNS
 *  0 if success
 *****************************************************************************/
kal_int32 jam_activate_wap_browser(char *url)
{
#ifdef BROWSER_SUPPORT

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;

    wap_browser_startup_req_struct *para = NULL;
    kal_int32 vm_id= jam_mvm_get_current_vm_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    kal_trace(TRACE_GROUP_9, FUNC_JAM_ACTIVATE_WAP_BROWSER);
    kal_print_string_trace(MOD_J2ME,TRACE_FUNC,"url:%s",url);
    //kal_prompt_trace(MOD_J2ME,url);
    kal_sleep_task(40);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    
#ifdef J2ME_SUPPORT_BACKGROUND
    if(jam_mvm_is_vm_support_bg(vm_id))
    {
        /* platform request is not available during bg running state */
        if (jam_mvm_get_vm_state(vm_id) == JVM_BG_RUNNING_STATE
    		|| jam_mvm_get_vm_state(vm_id) == JVM_SHORT_EVENT_STATE || jam_mvm_get_vm_state(vm_id) == JVM_LONG_EVENT_STATE)
        {
            kal_trace(TRACE_GROUP_9, FUNC_JAM_ACTIVATE_WAP_BROWSER_FAIL,1);
            return JAM_PR_BROWSER_NOT_AVAILABLE;
        }
    }
#endif /* J2ME_SUPPORT_BACKGROUND */ 

    if(sizeof(url) > 768)
    {
        return JAM_PR_BROWSER_URL_INVALIDATE;
    }
    
    /* Disable key handler to prevent sending duplicated requests */
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);

    para =
        (wap_browser_startup_req_struct*) construct_local_para((kal_uint16) sizeof(wap_browser_startup_req_struct), 0);

    para->type = 2;
    strncpy((char*)para->url, url, (sizeof(para->url) - 1));
    java_send_msg_from_active_mod(wap_get_service_module(MSG_ID_WAP_BROWSER_STARTUP_REQ),J2ME_WAP_SAP,MSG_ID_WAP_BROWSER_STARTUP_REQ,para);
    return JAM_PR_BROWSER_OK;
#else /*!BROWSER_SUPPORT*/
    return JAM_PR_BROWSER_NO_NETWORK_SERVICE;
#endif /*!BROWSER_SUPPORT*/
}


/*****************************************************************************
 * FUNCTION
 *  jam_make_call
 * DESCRIPTION
 *  make a outgoing phone call
 * PARAMETERS
 *  number      [?]     [?]     phone number in UCS2 encoding
 * RETURNS
 *  -1 if empty number; 0 if success
 *****************************************************************************/
kal_int32 jam_make_call(char *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;
    mmi_make_call_req_ind_struct *p = NULL;
    kal_bool is_always_ask = KAL_FALSE;
    kal_int32 vm_id = jam_mvm_get_current_vm_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    kal_trace(TRACE_GROUP_9, FUNC_JAM_MAKE_CALL);
    kal_print_string_trace(MOD_J2ME,TRACE_FUNC,"number:%s",number);
    //kal_prompt_trace(MOD_J2ME,number);
    kal_sleep_task(40);    
    if (number == NULL)
    {
        kal_trace(TRACE_GROUP_9, FUNC_JAM_MAKE_CALL_FAIL,0);        
        return JAM_PR_CALL_INVALID_PHONE_NUMBER;
    }

    /* number is too long */
    if (get_ucs2_len((kal_wchar*) number) > 90)
    {
        kal_trace(TRACE_GROUP_9, FUNC_JAM_MAKE_CALL_FAIL,1);        
        return JAM_PR_CALL_INVALID_PHONE_NUMBER;
    }

#ifdef J2ME_SUPPORT_BACKGROUND
	if(jam_mvm_is_vm_support_bg(vm_id))
	{
        /* platform request is not available during bg running state */
        if (jam_mvm_get_vm_state(vm_id) == JVM_BG_RUNNING_STATE && !jam_is_own_mmi_screen(vm_id) 
    		|| jam_mvm_get_vm_state(vm_id) == JVM_SHORT_EVENT_STATE || jam_mvm_get_vm_state(vm_id) == JVM_LONG_EVENT_STATE)
        {
            kal_trace(TRACE_GROUP_9, FUNC_JAM_MAKE_CALL_FAIL,2);        
            return JAM_PR_CALL_NOT_AVAILABLE;
        }
	}
#endif /* J2ME_SUPPORT_BACKGROUND */ 

    p = (mmi_make_call_req_ind_struct*) construct_local_para(sizeof(mmi_make_call_req_ind_struct), TD_CTRL);

    memcpy(p->strNumber, number, (get_ucs2_len((kal_wchar*) number) << 1) + 2);

    switch(cbm_get_sim_id(J2ME_active_nw_acc_id[vm_id]))
    {
        case CBM_SIM_ID_SIM1:
            p->call_type = SRV_UCM_VOICE_CALL_TYPE;
            break;
        case CBM_SIM_ID_SIM2:
            p->call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
            break;
        case CBM_SIM_ID_SIM3:
            p->call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
            break;
        case CBM_SIM_ID_SIM4:
            p->call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
            break;
        default:
            break;
    }

    java_send_msg_from_active_mod(MOD_MMI,MMI_J2ME_SAP,MSG_ID_MMI_JAVA_PR_MAKE_CALL_REQ,p);
    return JAM_PR_CALL_OK;
}


/*****************************************************************************
 * FUNCTION
 *  jam_activate_rtsp_player
 * DESCRIPTION
 *  launch RTSP player and connet to the specified URL
 * PARAMETERS
 *  url     [?]     [?]     URL address in ascii encoding
 * RETURNS
 *  0 if success
 *****************************************************************************/
kal_int32 jam_activate_rtsp_player(char *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 vm_id= jam_mvm_get_current_vm_id();
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_GROUP_9, FUNC_JAM_ACTIVATE_RTSP_PLAYER);
    kal_print_string_trace(MOD_J2ME,TRACE_FUNC,"url:%s",url);
    //kal_prompt_trace(MOD_J2ME,url);


        
            
#ifndef __MMI_VIDEO_STREAM__
    return JAM_PR_RTSP_NOT_SUPPORT;
#else /* __MMI_VIDEO_STREAM__ */ 

#ifndef SUPPORT_JSR_135_VIDEO
    return JAM_PR_RTSP_NOT_AVAILABLE;
#endif 

    if (mmi_java_is_no_network_service())
    {
        kal_trace(TRACE_GROUP_9, FUNC_JAM_ACTIVATE_RTSP_PLAYER_FAIL, 0);
        return JAM_PR_RTSP_NO_NETWORK_SERVICE;
    }

#ifdef J2ME_SUPPORT_BACKGROUND
	if(jam_mvm_is_vm_support_bg(vm_id))
	{
        /* platform request is not available during bg running state */
        if (jam_mvm_get_vm_state(vm_id) == JVM_BG_RUNNING_STATE
            || jam_mvm_get_vm_state(vm_id) == JVM_SHORT_EVENT_STATE 
            || jam_mvm_get_vm_state(vm_id) == JVM_LONG_EVENT_STATE)
        {
                kal_trace(TRACE_GROUP_9, FUNC_JAM_ACTIVATE_RTSP_PLAYER_FAIL, 1);
            return JAM_PR_RTSP_NOT_AVAILABLE;
        }
	}
#endif /* J2ME_SUPPORT_BACKGROUND */ 

    if(strlen(url) > 520)
    {
        return JAM_PR_RTSP_URL_INVALIDATE;
    }
    
    /* Disable key handler to prevent sending duplicated requests */
    ClearAllKeyHandler();
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
#ifdef __PLUTO_MMI_PACKAGE__
    mmi_media_app_send_rtsp_url(url);
#endif
    return JAM_PR_RTSP_OK;

#endif /* __MMI_VIDEO_STREAM__ */ 

}

/*****************************************************************************
 * FUNCTION
 *  jam_get_user_agent
 * DESCRIPTION
 *  get user agent
 * PARAMETERS
 *  void
 * RETURNS
 *  pointer to user agent array
 *****************************************************************************/
kal_uint8 *jam_get_user_agent()
{
    return (kal_uint8*)applib_inet_get_user_agent_string();
}

#ifdef __MMI_BACKGROUND_CALL__
/*****************************************************************************
 * FUNCTION
 *  jam_PR_outgoing_call_deleted_CB
 * DESCRIPTION
 *  
 * PARAMETERS
 *  ucm_data        [?]     
 *  ucm_dataagent    [void*](?)
 * RETURNS
 *  kal_bool
 *****************************************************************************/
mmi_ret jam_PR_outgoing_call_deleted_CB(mmi_event_struct *ucm_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (1)
    {
        return SRV_UCM_APP_EXIT_QUERY_RESULT_NO;
    }
    return SRV_UCM_APP_EXIT_QUERY_RESULT_YES;
}
#endif /* __MMI_BACKGROUND_CALL__ */ 

