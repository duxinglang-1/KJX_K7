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
 * WAPProfileSrvconfig.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is source file for WAP_PROF configurable items.
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"
#include "MMIDataType.h"

#ifdef WAP_SUPPORT
#include "WAPProfSrvConfig.h"
#include "WAPProfileSrvProt.h"
#include "WAPProfileSrvGProt.h"
#include "WAPPushSrvGprots.h"
#ifdef PROV_SUPPORT
#include "WAPProvisioningSrvProt.h"
#endif
#include "BrowserSrvGprot.h"
#ifdef __COSMOS_MMI_PACKAGE__
#ifdef __cplusplus
extern "C"
{
#endif

#include "vapp_dtcnt_gprot.h"

#ifdef __cplusplus
}
#endif
#else

#include "DataAccountGProt.h"   /* Bearer ENUM */
#endif
//------------------------------ suggest Add ------------------------------
#include "browser_api.h"
#include "wap_adp.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "mmi_inet_app_trc.h"
#include "MMI_inet_app_trc.h"
#include "kal_public_api.h"
#include "stack_config.h"
#include "kal_general_types.h"
//------------------------------ usage ------------------------------

/* Externs of browser API */

#ifdef BROWSER_SUPPORT
extern mmi_brw_sim_id_enum srv_brw_get_active_sim_id(void);
extern kal_bool mmi_brw_is_active_profile_in_use(mmi_brw_sim_id_enum sim_id);

extern void srv_brw_active_profile_changed_hdlr(
                srv_wap_prof_profile_content_struct *profile_content_p,
                srv_wap_prof_sim_id_enum sim_id,
                srv_wap_prof_response_funcptr_type callback);

extern void srv_brw_add_bookmark_provisioning(U8 *title_p, U8 *url_p, srv_wap_prof_response_funcptr_type callback);

#endif /*BROWSER_SUPPORT */



/* Externs of MMS API, to be placed in MMS_SUPPORT MACRO only. */
#ifdef MMS_SUPPORT
#ifdef __MMI_MMS_2__
extern void srv_mms_active_mms_profile_change_hdlr(
                srv_wap_prof_profile_content_struct *profile_content_p,
                srv_wap_prof_sim_id_enum sim_id,
                srv_wap_prof_response_funcptr_type callback);
#ifdef PROV_SUPPORT
#ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
extern void srv_mms_save_ota_mms_settings(
                srv_wap_prov_mms_setting_data_list_struct *mms_setting_content_p,
                srv_wap_prof_response_funcptr_type wap_prof_save_mms_setting_rsp_callback);
#endif
#endif
/* extern kal_bool mmi_umms_is_active_profile_in_use(void); */
extern kal_bool srv_mms_bgsr_is_in_use(kal_uint8 simId); /* MAUI_1420567 */

extern kal_bool mmi_umms_app_ready(void);

#ifdef __MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__
extern void srv_mms_bgsr_discard_bearer_fallback(U8 sim_id);
#endif 

#else /* __MMI_MMS_2__ */ 
#ifdef OBIGO_Q03C_MMS_V01
/* Q03c MMS API */
extern void mmi_mmsv01_active_mms_profile_change_hdlr(
                srv_wap_prof_profile_content_struct *profile_content_p,
                srv_wap_prof_sim_id_enum sim_id,
                srv_wap_prof_response_funcptr_type callback);

extern kal_bool mms_mmsv01_is_mms_active_profile_in_use(kal_uint8 sim_id);
#endif

#endif /* __MMI_MMS_2__ */ 

#endif /* MMS_SUPPORT */ 

srv_wap_prof_callback_struct g_srv_wap_prof_callback_st = 
{
    /* Active profile changed callback. */
    {
    #ifdef BROWSER_SUPPORT
     (srv_wap_prof_active_profile_chg_ind_funcptr_type) srv_brw_active_profile_changed_hdlr,    /* Q05a Browser callback */
    #else 
     NULL,
    #endif 

    #ifdef MMS_SUPPORT
    #ifdef __MMI_MMS_2__
     (srv_wap_prof_active_profile_chg_ind_funcptr_type) srv_mms_active_mms_profile_change_hdlr /* Q05a MMS callback */
    #else 
      //(srv_wap_prof_active_profile_chg_ind_funcptr_type) srv_wap_prof_active_mms_profile_chg_ind_callback        /* UPP callback for Q03c. */
      #ifdef OBIGO_Q03C_MMS_V01
     (srv_wap_prof_active_profile_chg_ind_funcptr_type) mmi_mmsv01_active_mms_profile_change_hdlr /* Q03c  MMS callback */
      #endif
     
    #endif 
    #else /* MMS_SUPPORT */ 
     NULL
    #endif /* MMS_SUPPORT */ 
     },

    /* is active profile in use callback. */
    {
    #ifdef BROWSER_SUPPORT
     (srv_wap_prof_is_active_profile_in_use_funcptr_type) mmi_brw_is_active_profile_in_use,     /* Q05a Browser callback */
    #else 
     NULL,
    #endif 

    #ifdef MMS_SUPPORT
    #ifdef __MMI_MMS_2__
     (srv_wap_prof_is_active_profile_in_use_funcptr_type) srv_mms_bgsr_is_in_use     /* Q05a MMS callback */    /* MAUI_1420567 */
    #else 
     (srv_wap_prof_is_active_profile_in_use_funcptr_type) mms_mmsv01_is_mms_active_profile_in_use /* Q03c MMS callback */
    #endif 
    #else /* MMS_SUPPORT */ 
     NULL
    #endif /* MMS_SUPPORT */ 
     },

    #ifdef BROWSER_SUPPORT
    /* Get Active sim id callback */
     srv_brw_get_active_sim_id,  /* Q05a browser callback. */
    #endif 

#ifdef PROV_SUPPORT
    /* Add bookmark callback */
    #ifdef BROWSER_SUPPORT
     srv_brw_add_bookmark_provisioning,    /* Q05a callback */
    #else 
     NULL,
    #endif 

    /* Save MMS OTA settings callback */
    #ifdef MMS_SUPPORT
    #ifdef __MMI_MMS_2__
    #ifndef __MMI_MMS_SIMPLIFIED_UI_SUPPORT__ 
     (srv_wap_prov_save_ota_mms_setting_funcptr_type) srv_mms_save_ota_mms_settings,    /* Q05a api */
    #else 
     NULL,
     #endif
    #else 
     NULL,   /* Q03c MMS callback, Not to be supported as of now. */
    #endif 
    #else /* MMS_SUPPORT */ 
     NULL,
    #endif /* MMS_SUPPORT */ 

#endif
    /* Is application ready callback. */
    {
    #ifdef __MMI_BROWSER_2__
     (srv_wap_prof_is_target_app_ready) wap_is_ready,   /* Q05a callback */
      #else  /*OPERA_V10_BROWSER*/
     NULL,
    #endif 

    #ifdef MMS_SUPPORT
    #ifdef __MMI_MMS_2__
     (srv_wap_prof_is_target_app_ready) mmi_umms_app_ready  /* Q05a api */
    #else 
     (srv_wap_prof_is_target_app_ready) wap_is_ready,   /* Q03c callback */
    #endif 
    #else /* MMS_SUPPORT */ 
     NULL
    #endif /* MMS_SUPPORT */ 
     },
      
};



/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_get_data_account_list_bearer_scope
 * DESCRIPTION
 *  Selects bearer scope for data account list display.
 * PARAMETERS
 *  app_id      [IN]        
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_wap_prof_get_data_account_list_bearer_scope(srv_wap_prof_app_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bearer_scope = 0;
    U8 csd_bearer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #ifdef __TCPIP_OVER_CSD__
    csd_bearer = DATA_ACCOUNT_BEARER_CSD;
#else
    csd_bearer = 0;
#endif 
    
#ifdef __COSMOS_MMI_PACKAGE__
 bearer_scope = csd_bearer | DATA_ACCOUNT_BEARER_GPRS | DATA_ACCOUNT_BEARER_ALL;
    if (SRV_WAP_PROF_APPID_BRW == app_id)
 {
 #if (MMI_MAX_SIM_NUM>=2) && defined(__MMI_WLAN_FEATURES__)  //10ADA : check this implementation
    { 
    	if(g_srv_wap_prof_cntx.sim_id != SRV_WAP_PROF_SIMID_WLAN)
       {
             bearer_scope  &= (~DATA_ACCOUNT_BEARER_WIFI);  
       }
      }
#endif
 }
 #else
    {
    if (SRV_WAP_PROF_APPID_BRW == app_id)
    {
    
    #ifdef __MMI_WAP_PROF_CBM_WAP_FALLBACK_SUPPORT__
        {
            /* Place CBM bearer scope. */
            bearer_scope |= DATA_ACCOUNT_BEARER_ALL;
            MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_UI_DTCNT_BEARER_SCOPE_ALL);
        }
   
    #else 
        {
            /* No fallback defined. */
            bearer_scope |= DATA_ACCOUNT_BEARER_ALL;
            MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_UI_DTCNT_BEARER_SCOPE_ALL);
        }
    #endif 
  
		
#if (MMI_MAX_SIM_NUM>=2) && defined(__MMI_WLAN_FEATURES__)    

     if(g_srv_wap_prof_cntx.sim_id != SRV_WAP_PROF_SIMID_WLAN)
       {
             bearer_scope  &= (~DATA_ACCOUNT_BEARER_WIFI);  
       }
#endif

    }

    else if (SRV_WAP_PROF_APPID_MMS == app_id)
    {
    #ifdef __MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__
        {
            /* Place CBM bearer scope. */
            bearer_scope |= csd_bearer | DATA_ACCOUNT_BEARER_GPRS;
            MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_UI_DTCNT_BEARER_SCOPE_GPRS_AND_CSD);
        }
   
    #else 
        {
            /* No fallback defined. */
            bearer_scope |= csd_bearer | DATA_ACCOUNT_BEARER_GPRS;
            MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_UI_DTCNT_BEARER_SCOPE_GPRS_AND_CSD);
        }
    #endif 
    }
    else
    {
        /* app_id is errorneous. */
        ASSERT(0);
    }
	}
     #endif  
    return bearer_scope;
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_active_profile_changed
 * DESCRIPTION
 *  interface to intimate WAP/MMI task applications of changed active profile.
 * PARAMETERS
 *  sim_id      [IN]        
 *  app_id      [IN]        
 *  msg(?)
 * RETURNS
 *  void
 *****************************************************************************/
void srv_wap_prof_active_profile_changed(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wap_prof_profile_content_struct *l_profile_content_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ACTIVE_PROFILE_CHANGED_ENTER);

#ifdef __MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__
    if (SRV_WAP_PROF_APPID_MMS == app_id)
    {
        srv_mms_bgsr_discard_bearer_fallback(sim_id);
    }
#endif /* __MMI_WAP_PROF_CBM_MMS_FALLBACK_SUPPORT__ */ 

    if (NULL == g_srv_wap_prof_callback_st.active_profile_changed_callback[app_id])
    {
        /* This check is for customer releases. */
        MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ERR_ACTIVE_PROFILE_CHANGED_CALLBACK_NULL);
        ASSERT(g_srv_wap_prof_callback_st.active_profile_changed_callback[app_id]);
        return;
    }

    l_profile_content_p = srv_wap_prof_get_profile_content(sim_id, app_id, (U8) - 1, SRV_WAP_PROF_DTCNT_PRIMARY, NULL);

    /* Send data to respective application. */

if(app_id == SRV_WAP_PROF_APPID_BRW)
{
#ifdef __WAP_PUSH_SUPPORT__
 srv_wap_push_active_profile_changed_hdlr(l_profile_content_p, sim_id, NULL);
#endif /*__WAP_PUSH_SUPPORT__*/
}


    g_srv_wap_prof_callback_st.active_profile_changed_callback[app_id] (l_profile_content_p,
                                                                        sim_id,
                                                                        (srv_wap_prof_response_funcptr_type)
                                                                        srv_wap_prof_active_profile_change_confirmation_callback);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_is_active_profile_in_use
 * DESCRIPTION
 *  Checks if active profile is in use. Generally used for DM operation.
 * PARAMETERS
 *  app_id      [IN]        
 *  msg(?)
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool srv_wap_prof_is_active_profile_in_use(srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id) /* MAUI_1420567 */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = MMI_TRUE;

#ifdef BROWSER_SUPPORT
    mmi_brw_sim_id_enum brw_sim_id = MMI_BRW_SIM_ID_SIM1;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* MAUI_01097065 starts */
#ifndef MMS_SUPPORT
    if (SRV_WAP_PROF_APPID_MMS == app_id)
    {
        return result;
    }
#endif /* MMS_SUPPORT */ 

#ifndef BROWSER_SUPPORT
    if(app_id ==  SRV_WAP_PROF_APPID_BRW )
    {
        return result;
    }

#endif

    /* MAUI_01097065 ends */
    if (NULL == g_srv_wap_prof_callback_st.is_active_profile_in_use_callback[app_id])
    {
        /* This check is for customer releases. */
        MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_PROV_ERR_DM_CHECK_ACTIVE_PROFILE_IN_USE_NO_CALLBACK);
        ASSERT(g_srv_wap_prof_callback_st.is_active_profile_in_use_callback[app_id]);
        return result;
    }


#ifdef BROWSER_SUPPORT

     if(app_id ==  SRV_WAP_PROF_APPID_BRW )
    {
		brw_sim_id = (mmi_brw_sim_id_enum)sim_id;
    result = (g_srv_wap_prof_callback_st.is_active_profile_in_use_callback[app_id] (brw_sim_id));
    }
    else
#endif
    {
    result = (g_srv_wap_prof_callback_st.is_active_profile_in_use_callback[app_id] (sim_id));
    }


    MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_PROV_DM_CHECK_ACTIVE_PROFILE_IN_USE_RESULT, result);
    return result;
}

#ifdef PROV_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_wap_prov_add_bookmark
 * DESCRIPTION
 *  adds bookmark.
 *  
 *  PARAMETERS:
 *  name        [?]     
 *  url         [?]     
 *****************************************************************************/
void srv_wap_prov_add_bookmark(U8 *name, U8 *url)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(
        SRV_WAP_PROF_MOD_INET_APP,
        SRV_WAP_PROF_TRC_GRP9,
        (S8*) "[WAP_PROF][PROV] Add bookmark, title = %s, url = %s",
        (S8*) name,
        (S8*) url);
    if (NULL == g_srv_wap_prof_callback_st.add_bookmark_callback)
    {
        /* This check is for customer releases. */
        MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_PROV_ERR_INSTALL_BOOKMARK_NULL_CALLBACK);
        ASSERT(g_srv_wap_prof_callback_st.add_bookmark_callback);
        return;
    }
    g_srv_wap_prof_callback_st.add_bookmark_callback(
                                name,
                                url,
                                (srv_wap_prof_response_funcptr_type) srv_wap_prov_add_bookmark_rsp_callback);
}


/*****************************************************************************
 * FUNCTION
 *  srv_wap_prov_save_ota_mms_setting
 * DESCRIPTION
 *  adds bookmark.
 *  
 *  PARAMETERS:
 *  data        [?]     
 *****************************************************************************/
void srv_wap_prov_save_ota_mms_setting(srv_wap_prov_mms_setting_data_list_struct *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_wap_prof_callback_st.save_ota_mms_setting_callback)
    {
        MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_PROV_INSTALL_MMS_SETTING);
        g_srv_wap_prof_callback_st.save_ota_mms_setting_callback(
                                    data,
                                    (srv_wap_prof_response_funcptr_type) srv_wap_prov_save_mms_setting_rsp_callback);
    }
    else
    {
        MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_PROV_ERR_INSTALL_MMS_SETTING_NO_CALLBACK);
        /* Support not required hence no API registered for Q03C. */
        srv_wap_prov_save_mms_setting_rsp_callback(SRV_WAP_PROF_ERR);
    }
}

#endif

/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_target_app_is_ready
 * DESCRIPTION
 *  Callback to check if target app is ready to recieve profiles.
 *  
 *  PARAMETERS:
 *  app_id      [IN]        
 *****************************************************************************/
MMI_BOOL srv_wap_prof_target_app_is_ready(srv_wap_prof_app_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_wap_prof_callback_st.is_application_ready[app_id])
    {
        if (KAL_TRUE == g_srv_wap_prof_callback_st.is_application_ready[app_id] ())
            return MMI_TRUE;
        else
            return MMI_FALSE;
    }
    else
    {
        /* 
         * As there is no callback means application is ready, only true for Q03c native.
         */
        return MMI_TRUE;
    }
}

#ifdef BROWSER_SUPPORT
/*****************************************************************************
 * FUNCTION
 *  srv_wap_prof_get_active_sim_id
 * DESCRIPTION
 *  Returns active sim id of WAP. Currently only for WAP is returned.
 * PARAMETERS:
 *  app_id      [IN]        
 *****************************************************************************/
srv_wap_prof_sim_id_enum srv_wap_prof_get_active_sim_id(srv_wap_prof_app_id_enum app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     mmi_brw_sim_id_enum active_sim_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    active_sim_id = g_srv_wap_prof_callback_st.active_sim_id_callback();

    
	switch(active_sim_id)
	{
	case MMI_BRW_SIM_ID_SIM1:
        return SRV_WAP_PROF_SIMID_SIM1;

#if (MMI_MAX_SIM_NUM>=2)
	case MMI_BRW_SIM_ID_SIM2:
        return SRV_WAP_PROF_SIMID_SIM2;
#if (MMI_MAX_SIM_NUM>=3)	            
	case MMI_BRW_SIM_ID_SIM3:      
		return SRV_WAP_PROF_SIMID_SIM3;       
#if (MMI_MAX_SIM_NUM>=4)	            
	case MMI_BRW_SIM_ID_SIM4:    
		return SRV_WAP_PROF_SIMID_SIM4;
#endif 
#endif
#endif

#if (MMI_MAX_SIM_NUM>=2) && defined(__MMI_WLAN_FEATURES__)	            
	case MMI_BRW_SIM_ID_WLAN:		
        return SRV_WAP_PROF_SIMID_WLAN;
#endif
	default: 
		return SRV_WAP_PROF_SIMID_SIM1;

	}     

    }

#endif


#endif /* WAP_SUPPORT */ 
