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
 *
 * Filename:
 * ---------
 * wapadp.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for common functions provided in different WAP/MMS solutions.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "kal_release.h"        /* Basic data type */

#include "app_str.h"

/* plutommi includes */
//#include "resource_audio.h"     /* Standard tone */
#include "MMIDataType.h"
#include "CommonScreens.h"
#include "AlarmFrameworkProt.h" /* Alarm */
#include "MessagesMiscell.h"
#include "SettingProfile.h"
#include "gui_data_types.h"
//#include "ProfileGprots.h"      /* PlayRequestedTone */

#include "msf_def.h"
#include "wap_cmn.h"
#include "widget.h"
#include "wap_ps_struct.h"
#include "wapadp.h"
#include "DLAgentSrvDef.h"

/* To check for call cases in wap_start_browser */
#include "UcmSrvGprot.h"

#ifdef OBIGO_Q03C_MMS_V01
#include "mmsadp.h"
#include "mea_def.h"
#include "mms_def.h"
#include "WapDef.h"
//extern void goto_mms_editor(mms_content_entry_struct *data);
extern int wap_mms_is_open(void);
#endif /* OBIGO_Q03C_MMS_V01 */ 
#include "Browser_struct.h"
#include "BrowserGprots.h"
#ifdef BROWSER_SUPPORT
#include "Browser_api.h"
#endif
#include "WapResDef.h"

#include "ProcedureGprot.h"

static struct
{
    mmi_frm_proc_id_info_struct id_info;
} g_mmi_wap_deinit_cntx;


/*
extern void wap_entry_widget_not_ready(void);
extern void wap_entry_busy_progressing_screen_in_idle(void);
extern MsfEventType key_map[];
typedef enum
{
    WAP_SERVICE_MMS = 0,
    WAP_SERVICE_BROWSER
} wap_service_enum;
*/

#if defined (OBIGO_Q03C) && !defined (OBIGO_Q03C_BROWSER)
/*****************************************************************************
 * FUNCTION
 *  obigo_q03c_api_wap_is_ready
 * DESCRIPTION
 *  The function is used to check if wap task is ready (Browser, MMS and Transport modules are ready).
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int obigo_q03c_api_wap_is_ready()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int MSF_wapIsReady(void);

    return MSF_wapIsReady();
}


/*****************************************************************************
 * FUNCTION
 *  obigo_q03c_api_wap_is_init
 * DESCRIPTION
 *  The function is used to check if wap task is in initialization state.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int obigo_q03c_api_wap_is_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int MSF_wapIsInit(void);

    return MSF_wapIsInit();
}


/*****************************************************************************
 * FUNCTION
 *  obigo_q03c_api_wap_get_service_module
 * DESCRIPTION
 *  This function is to implement viewing a specific push message by index
 * CALLS
 *  
 * PARAMETERS
 *  msg_id    [IN]   primitve id     
 * RETURNS
 *  module id, MOD_MMI or MOD_WAP
 *****************************************************************************/
module_type obigo_q03c_api_wap_get_service_module(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch (msg_id)
    {
#ifdef WAP_SUPPORT
    case MSG_ID_WAP_GET_BRA_PROF_ID_REQ:
    case MSG_ID_WAP_GET_PROF_CONTENT_REQ:
    case MSG_ID_WAP_GET_PROF_LIST_REQ:
#endif /* WAP_SUPPORT */
        case MSG_ID_WAP_GET_USER_AGENT_REQ:
        case MSG_ID_WAP_BROWSER_STARTUP_REQ:
        case MSG_ID_WAP_MMI_LAUNCH_BROWSER_REQ:
        case MSG_ID_MMI_DA_DOWNLOAD_INFO_IND:
        return MOD_MMI;
    default:
        return MOD_WAP;
      }
}
#endif

#ifdef OBIGO_Q03C_BROWSER
/*****************************************************************************
 * FUNCTION
 *  wap_get_screen_id
 * DESCRIPTION
 *  This function returns the wap screen id
 * CALLS
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint16 wap_get_screen_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return mmi_brw_get_screen_id();
}
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  wap_is_ready
 * DESCRIPTION
 *  The function is used to check if wap task is ready (Browser, MMS and Transport modules are ready).
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int wap_is_ready()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int MSF_wapIsReady(void);

    return MSF_wapIsReady();
}


/*****************************************************************************
 * FUNCTION
 *  wap_mmi_ready_on_bootup
 * DESCRIPTION
 *  The function is used to check if wap task is ready (Browser, MMS and Transport modules are ready).
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
mmi_ret wap_mmi_ready_on_bootup(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static MMI_BOOL wap_ready_sent = MMI_FALSE;
    //MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (wap_ready_sent)
    {
        return MMI_RET_OK;
    }

    wap_ready_sent = MMI_TRUE;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
    mmi_frm_send_ilm(MOD_WAP,MSG_ID_MMI_READY_NOTIFY_REQ,(oslParaType *)NULL,NULL);
    return MMI_RET_OK;
}



/*****************************************************************************
 * FUNCTION
 *  wap_is_init
 * DESCRIPTION
 *  The function is used to check if wap task is in initialization state.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int wap_is_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    extern int MSF_wapIsInit(void);

    return MSF_wapIsInit();
}

#if defined (OBIGO_Q03C_BROWSER) || !defined (BROWSER_SUPPORT)

/*****************************************************************************
 * FUNCTION
 *  wap_get_service_module
 * DESCRIPTION
 *  This function is to implement viewing a specific push message by index
 * CALLS
 *  
 * PARAMETERS
 *  msg_id    [IN]   primitve id     
 * RETURNS
 *  module id, MOD_MMI or MOD_WAP
 *****************************************************************************/
module_type wap_get_service_module(kal_uint32 msg_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    switch (msg_id)
    {
#ifdef WAP_SUPPORT
    case MSG_ID_WAP_GET_BRA_PROF_ID_REQ:
    case MSG_ID_WAP_GET_PROF_CONTENT_REQ:
    case MSG_ID_WAP_GET_PROF_LIST_REQ:
#endif /* WAP_SUPPORT */
        case MSG_ID_WAP_GET_USER_AGENT_REQ:
        case MSG_ID_WAP_BROWSER_STARTUP_REQ:
        case MSG_ID_WAP_MMI_LAUNCH_BROWSER_REQ:
        case MSG_ID_MMI_DA_DOWNLOAD_INFO_IND:
        return MOD_MMI;
    default:
    return MOD_WAP;
}
}

#endif /**/

#ifdef OBIGO_Q03C_BROWSER

/*****************************************************************************
 * FUNCTION
 *  wap_browser_is_open
 * DESCRIPTION
 *  The function is used to check if browser is opened.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int wap_browser_is_open()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __COSMOS_MMI_PACKAGE__
    if (vappBrwRenderedPageOpen())
#else
    if (mmi_brw_is_rendered_page_open())
#endif
    {
        return TRUE;
    }

    return FALSE;
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


/*****************************************************************************
 * FUNCTION
 *  wap_bearer_csd_is_disc
 * DESCRIPTION
 *  The function is used to check if wap task is deinitializing CSD connection.
 * PARAMETERS
 *  void
 * RETURNS
 *  0: FASLE, 1: TRUE
 *****************************************************************************/
int wap_bearer_csd_is_disc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return 1;

}


/*****************************************************************************
 * FUNCTION
 *  wap_internet_key_hdlr
 * DESCRIPTION
 *  WAP internet key handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_internet_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if (defined( __MMI_OP01_WITH_WAP_KEY__) || defined(__MMI_OP02_WITH_WAP_KEY__) \
    || defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    mmi_brw_start_browser_action((U8)WAP_BROWSER_GOTO_OP_HOMEPAGE, NULL);
#else
    mmi_brw_start_browser_action((U8)WAP_BROWSER_GOTO_HOMEPAGE, NULL);
#endif /* defined( __MMI_OP01_WITH_WAP_KEY__) */

}


/*****************************************************************************
 * FUNCTION
 *  goto_mobile_suite_screen
*
 * DESCRIPTION
 *  WAP entry point from MMI menu
*
 * PARAMETERS
 *  void
 * RETURNS
 *  void
*
* GLOBALS AFFECTED
*  
 *****************************************************************************/
void goto_mobile_suite_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__    
    mmi_brw_pre_entry_internet_services();
#else
    vapp_brw_app_launch();
#endif        
        return;
    }


int wap_start_browser(kal_uint8 option, const kal_uint8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wap_browser_startup_req_struct *p = NULL;
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BACKGROUND_CALL__
    if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0) && option == WAP_BROWSER_GOTO_URL)
    {
        if(!srv_ucm_is_background_call())
        {
#ifndef __COSMOS_MMI_PACKAGE__
			mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_NOT_AVAILABLE_DURING_VIDEO_CALL),MMI_EVENT_FAILURE,GRP_ID_ROOT,NULL);
#else
			vapp_brw_display_popup(STR_GLOBAL_NOT_AVAILABLE_DURING_VIDEO_CALL);
#endif /* __COSMOS_MMI_PACKAGE__ */
            
            return -1;
        }
    }
#else
    if ((srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0) && option == WAP_BROWSER_GOTO_URL)
    {
        if ((srv_ucm_query_call_count(SRV_UCM_ACTIVE_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0) ||
            (srv_ucm_query_call_count(SRV_UCM_HOLD_STATE, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0))
        {
#ifndef __COSMOS_MMI_PACKAGE__
			mmi_popup_display_simple((WCHAR*) GetString(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL),MMI_EVENT_FAILURE,GRP_ID_ROOT,NULL);
#else
			vapp_brw_display_popup(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL);
#endif /* __COSMOS_MMI_PACKAGE__ */
            return -1;
        }
    }
#endif

#ifdef OBIGO_Q03C_MMS_V01
    if(wap_mms_is_open() && (option != WAP_BROWSER_ADD_BOOKMARK))
    {
        widget_MMI_shutdown_WAP_Widget_UI();
    }
#endif
#ifndef __COSMOS_MMI_PACKAGE__    
    mmi_brw_start_browser_action((U8)option, (U8*)url);
#else
    vapp_brw_start_browser_action((U8)option, (U8*)url);
#endif        
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  wap_entry_select_bookmark
 * DESCRIPTION
 *  This function is used by MMI applications to make entry to bookmark selector screen
 * PARAMETERS
 *  p
 * RETURNS
 *  void
 *****************************************************************************/
int wap_entry_select_bookmark(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __COSMOS_MMI_PACKAGE__
	mmi_popup_display_simple((WCHAR*)GetString(STR_GLOBAL_NOT_AVAILABLE),MMI_EVENT_FAILURE,GRP_ID_ROOT,NULL);
#else
	vapp_brw_display_popup(STR_GLOBAL_NOT_AVAILABLE);
#endif /* __COSMOS_MMI_PACKAGE__ */
    return -1;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}
#endif
/*****************************************************************************
 * FUNCTION
 *  wap_memory_card_plug_out_hdlr
 * DESCRIPTION
 *  This function is used by file manager applications to intimate the WAP
 * for memory card plug out.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wap_memory_card_plug_out_hdlr (void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!wap_is_ready())
    {
        return;
    }

    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->local_para_ptr = NULL;
    ilm_ptr->msg_id = MSG_ID_WAP_MEM_CARD_PLUG_OUT;
    ilm_ptr->peer_buff_ptr = NULL;

    SEND_ILM(MOD_MMI, MOD_WAP, WAP_MMI_SAP, ilm_ptr);
}


#ifdef __MMI_PUSH_IN_UM__
/*****************************************************************************
 * FUNCTION
 *  wap_um_entry_msg_wap_push
 * DESCRIPTION
 *  This function is to implement viewing a specific push message by index
 * CALLS
 *  
 * PARAMETERS
 *  msg_box_type        [IN]        
 *  msg_index           [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool wap_um_entry_msg_wap_push(kal_uint16 msg_box_type, kal_uint32 msg_id, kal_uint16 keycode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    extern MMI_BOOL mmi_push_handle_entry_msg_wap_push(kal_uint16 msg_box_type, kal_uint32 msg_id, kal_uint16 key_code);
    //return (kal_bool)mmi_push_handle_entry_msg_wap_push(msg_box_type,msg_id, keycode);
    return KAL_TRUE;

}
#endif /* __MMI_PUSH_IN_UM__ */ 


#ifdef WAP_SUPPORT

static void mmi_wap_browser_poweroff_rsp_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_proc_notify_completed(g_mmi_wap_deinit_cntx.id_info);
}

mmi_frm_proc_result_enum mmi_wap_deinit(void *arg, const mmi_frm_proc_id_info_struct id_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MYQUEUE msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_wap_deinit_cntx.id_info = id_info;
    
    SetProtocolEventHandler(mmi_wap_browser_poweroff_rsp_hdlr, MSG_ID_WAP_BROWSER_POWEROFF_RSP);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //0
	mmi_frm_send_ilm(MOD_WAP,MSG_ID_WAP_BROWSER_POWEROFF_REQ,(oslParaType *)NULL,NULL);
    return MMI_FRM_PROC_RESULT_NOTIFY_LATER;
}

#endif /* WAP_SUPPORT */
