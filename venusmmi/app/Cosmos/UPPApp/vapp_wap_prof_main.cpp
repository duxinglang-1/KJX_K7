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
* WAPProfileMain.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   This is main source file for UPP profile module.
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
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/
#include "MMI_include.h"
#ifndef _VAPP_WAP_PROF_MAIN_CPP_
#define _VAPP_WAP_PROF_MAIN_CPP_

//#include "ServiceDefs.h"
#ifdef WAP_SUPPORT
#ifdef __cplusplus
extern "C"
{
#endif



#include "WAPProfSrvConfig.h"
#include "WAPProfileSrvType.h"
#include "WAPProvisioningSrvType.h"        /* prov action enum. */
#include "WAPProfileSrvProt.h"
#include "WAPProfileSrvGprot.h"
#include "GlobalResDef.h"
#include "Wap_ps_struct.h"
#include "custom_nvram_editor_data_item.h"
#include "Nvram_enums.h"
#include "WAPProvisioningSrvProt.h"
#include "mmi_rp_srv_wap_prof_def.h"
#include "DtcntSrvGprot.h"

#include "Custom_data_account.h"
#include "dtcntsrviprot.h"
#include "cbm_api.h"
#include "cbm_consts.h"

#ifdef __cplusplus
}
#endif

#include "vapp_dtcnt_gprot.h"
#include "vcui_dtcnt_select_gprot.h"


#include "WAPProfResDef.h"
#include "vapp_wap_prof_main.h"
#include "mmi_rp_vapp_wap_prof_def.h"





mmi_id vapp_wap_prof_dtcnt_cui_id =  GRP_ID_INVALID;
mmi_id VAPP_WAP_PROF_DTCNT_CUI_GRP_ID = SRV_WAP_PROF_BASE + 1;
srv_wap_prof_sim_id_enum cui_sim_id;
srv_wap_prof_app_id_enum cui_app_id;


/*****************************************************************************
* FUNCTION
*  vapp_wap_prof_app_init
* DESCRIPTION
*  This is the WAP PROF Initialization API. Called at bootup.
* PARAMETERS
*  void
* RETURNS
*  mmi_ret
*****************************************************************************/
extern "C" mmi_ret vapp_wap_prof_app_init(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	cbm_app_info_struct info;
	U8 cbm_brwmms_app_id;
	  
    kal_uint16 vapp_icon_id[] = 
    {
        IMG_GLOBAL_WEB_BROWSER_CSK,
#if (MMI_MAX_SIM_NUM >= 2)
        IMG_GLOBAL_COMMON_CSK,
#endif
#if (MMI_MAX_SIM_NUM >= 3)
        IMG_GLOBAL_MARK_CSK,
#endif
#if (MMI_MAX_SIM_NUM >= 4)
        IMG_GLOBAL_NEXT_CSK
#endif
    };
    //VfxU32 simF = MMI_MAX_SIM_NUM;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_INIT_ENTER);

	/***** initialization for Browser *******/

	info.app_str_id = STR_ID_VAPP_WAP_PROF_CBM_BROWSER;

#ifdef WAP2
	info.app_type = DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_BRW_HTTP;
#else
	info.app_type = DTCNT_APPTYPE_BRW_WAP;
#endif 

    for(VfxU32 i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        info.app_icon_id = vapp_icon_id[i];
        cbm_brwmms_app_id = srv_wap_prof_get_cbm_app_id(SRV_WAP_PROF_APPID_BRW, 
								srv_wap_prof_sim_id_enum(SRV_WAP_PROF_SIMID_SIM1 + i));
        cbm_register_app_id_with_app_info(
		&info,
		&cbm_brwmms_app_id);
        srv_wap_prof_set_cbm_app((srv_wap_prof_sim_id_enum)i , SRV_WAP_PROF_APPID_BRW, cbm_brwmms_app_id);
    }
    
#ifdef MMS_SUPPORT
	info.app_str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;	
	info.app_type = DTCNT_APPTYPE_MMS;
    
    for(VfxU32 i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        info.app_icon_id = vapp_icon_id[i];
        cbm_brwmms_app_id = srv_wap_prof_get_cbm_app_id(SRV_WAP_PROF_APPID_MMS, 
								srv_wap_prof_sim_id_enum(SRV_WAP_PROF_SIMID_SIM1 + i));
        cbm_register_app_id_with_app_info(
		&info,
		&cbm_brwmms_app_id);
        srv_wap_prof_set_cbm_app((srv_wap_prof_sim_id_enum)i, SRV_WAP_PROF_APPID_MMS, cbm_brwmms_app_id);
    }
#endif
    
	srv_wap_prof_process_init_event();

	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  vapp_wap_prof_app_activate_profile
* DESCRIPTION
*  Activates a profile. It is a Non-Blocking API as primitive needs to be sent to WAP.
*  if other modules need not be informed then pass MMI_FALSE as 2nd parm.
* PARAMETERS
*  index                       [IN]        
*  b_inform_other_module       [IN]        
* RETURNS
*  void
*****************************************************************************/
extern "C" void vapp_wap_prof_app_activate_profile(U32 index, MMI_BOOL b_inform_other_module, srv_wap_prof_sim_id_enum sim_info, srv_wap_prof_app_id_enum app_info )
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	//MMI_BOOL is_subs_dtcnt;
	srv_wap_prof_sim_id_enum sim_id = sim_info;
	srv_wap_prof_app_id_enum app_id = app_info;

	//U16 app_str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;
	//U16 app_icon_id = IMG_GLOBAL_WEB_BROWSER_CSK;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(SRV_WAP_PROF_TRC_GRP9, TRC_MMI_WAP_PROF_ACTIVATE_PROFILE, index);

	if ((app_id >= SRV_WAP_PROF_APPID_END) || (sim_id >= SRV_WAP_PROF_SIMID_END))
	{
		ASSERT(app_id < SRV_WAP_PROF_APPID_END);
		ASSERT(sim_id < SRV_WAP_PROF_SIMID_END);
		return;
	}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM>=2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM>=3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM>=4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
#endif
#endif	
	
	if ((vapp_wap_prof_dtcnt_cui_id != GRP_ID_INVALID) && (SRV_WAP_PROF_PROFILE_SRC_OTA_PROV==srv_wap_prof_get_profile_source()))
	{

        vcui_dtcnt_select_set_account_id(vapp_wap_prof_dtcnt_cui_id, cui_dtcnt_sim_enum(CUI_DTCNT_SIM1 + 
            (sim_id - SRV_WAP_PROF_SIMID_SIM1)), index);

	}
	
	/* Update active profile index. Dont commit to NVRAM. */
	/* Commit to NVRAM if not informing other modules. */
	/* index has to be from 0-9 only, and 10-12 for SIM profiles. */
	// srv_wap_prof_set_active_profile_index(sim_id, app_id, index, !(b_inform_other_module));

	if (MMI_TRUE == b_inform_other_module)
	{
		srv_wap_prof_set_active_profile_index(sim_id, app_id, index, MMI_FALSE);

		srv_wap_prof_set_module_status();
		/* Call other application API/ Primitive to change active profile. */
		srv_wap_prof_active_profile_changed(sim_id, app_id);
		/*
		* Do not do anything after sending active profile changed req as it is Non Blocking. 
		* * anythign else should be done in srv_wap_prof_active_profile_change_confirmation_callback(..)
		*/
	}
	else
		srv_wap_prof_set_active_profile_index(sim_id, app_id, index, MMI_TRUE);
}


/*****************************************************************************
* FUNCTION
*  srv_wap_prof_dtcnt_cui_proc
* DESCRIPTION
*  Proc function for Data account CUI.
* PARAMETERS
*  mmi_event_struct*                    [IN]        
* RETURNS
*  mmi_ret
*****************************************************************************/
extern "C" mmi_ret vapp_wap_prof_dtcnt_cui_proc(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	cbm_account_info_struct data_account_info;
	U32 get_account_id = 0;
	U8 primary_dtcnt_id = (U8) -1;
	U8 secondary_dtcnt_id = (U8) -1;
	cui_dtcnt_sim_enum sim;
	U32 sim1AccountId;






	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/


	switch(evt->evt_id)
	{

	case EVT_ID_GROUP_DEINIT:
		vapp_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;  
		break;

	case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
         cui_dtcnt_select_event_any_sim_selected_struct *event;
         event = (cui_dtcnt_select_event_any_sim_selected_struct *)evt;
		/* If user selected an account and press OK, send this event to APP’s proc, APP need to save the account ID and close the CUI */
		sim = event->selectSim;

        sim1AccountId = (U32)event->accountId;
		cbm_decode_data_account_id_ext(sim1AccountId, &data_account_info);
		primary_dtcnt_id = data_account_info.account[0].account_id;
		secondary_dtcnt_id = data_account_info.account[1].account_id;
		cui_sim_id = srv_wap_prof_sim_id_enum(SRV_WAP_PROF_SIMID_SIM1 + (sim - CUI_DTCNT_SIM1));
		get_account_id = srv_wap_prof_encode_dtcnt(primary_dtcnt_id, secondary_dtcnt_id, cui_sim_id, cui_app_id);
		
		if(get_account_id != srv_wap_prof_get_active_dtcnt_index(cui_sim_id, cui_app_id) )
		{


			cbm_decode_data_account_id_ext(get_account_id, &data_account_info);

			primary_dtcnt_id = data_account_info.account[0].account_id;
			secondary_dtcnt_id = (U8) - 1;

			if (data_account_info.acct_num > 1)
			{
				secondary_dtcnt_id = data_account_info.account[1].account_id;
			}

			vapp_wap_prof_app_activate_profile(get_account_id, MMI_TRUE, cui_sim_id, cui_app_id);

		}

		else if(get_account_id == srv_wap_prof_get_active_dtcnt_index(cui_sim_id, cui_app_id) )

		{    
			if(SRV_WAP_PROF_AXN_CFG_DTCNT == srv_wap_prof_get_action())

				vapp_wap_prof_app_activate_profile(get_account_id, MMI_TRUE,cui_sim_id, cui_app_id);
		}
       break;

	/* If user press cancel, send this event to APP’s proc, APP can just close the CUI */
    case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
	case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
	/* If CUI’s part screen closed abnormally not by user, send this event to APP’s proc, APP can just  close the CUI*/
	case CUI_DTCNT_SELECT_EVENT_CLOSE:
		vcui_dtcnt_select_close(vapp_wap_prof_dtcnt_cui_id);
		mmi_frm_group_close(VAPP_WAP_PROF_DTCNT_CUI_GRP_ID);
		vapp_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;
	/* If APP fill wrong parameter to run CUI it will send this event, no need to close CUI */   
	case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
		break;
	}
	return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  srv_wap_prof_entry_dtcnt_cui
* DESCRIPTION
*  API for entering the data account cui.
* PARAMETERS
*  void                    [IN]        
* RETURNS
*  void
*****************************************************************************/
void vapp_wap_prof_entry_dtcnt_cui(U8 cbm_app_id, mmi_id parent_id, U16 icon_id)
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	VappDtcntAcctValidTypeEnum dtcnt_validity_status_sim1;
	U32 sim1_account_id = 0;
/*#if (MMI_MAX_SIM_NUM<2)
	srv_dtcnt_sim_type_enum sim_info; 
#endif*/
	cui_dtcnt_select_run_struct para;

	U8 primary_dtcnt_id = (U8) -1;
	//U8 secondary_dtcnt_id = (U8) -1;
	cbm_account_info_struct data_account_info;


	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/ 


	memset(&para, 0, sizeof(cui_dtcnt_select_run_struct));
	memset(&data_account_info, 0, sizeof(cbm_account_info_struct));
    //*******************************************************************************************
    for(VfxU32 i = 0; i < MMI_MAX_SIM_NUM; i++)
    {
        sim1_account_id  = srv_wap_prof_get_active_dtcnt_index(SRV_WAP_PROF_SIMID_SIM1 + i,cui_app_id);
    	dtcnt_validity_status_sim1 = vapp_dtcnt_acct_is_valid( sim1_account_id, MMI_FALSE);
    	if (dtcnt_validity_status_sim1 == DTCNT_ACCT_VALID_NONE)
    	{

    		//para.sim_account_id[0] = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, CBM_SIM_ID_SIM1, cbm_app_id, KAL_FALSE);  
            sim1_account_id = cbm_encode_data_account_id(CBM_DEFAULT_ACCT_ID, cbm_sim_id_enum(CBM_SIM_ID_SIM1 + i),
                cbm_app_id, KAL_FALSE);
    	}
    	cbm_decode_data_account_id_ext(sim1_account_id, &data_account_info);

    	primary_dtcnt_id = data_account_info.account[0].account_id;
    	//secondary_dtcnt_id = data_account_info.account[1].account_id;


    	if(primary_dtcnt_id == CBM_DEFAULT_ACCT_ID)
    		srv_dtcnt_get_auto_acc_id(sim1_account_id, &para.sim_account_id[i]);
    	else 
    		para.sim_account_id[i] = sim1_account_id;
    }
    //*****************************************************************************************
    
	para.bearers = srv_wap_prof_get_data_account_list_bearer_scope(cui_app_id);
	para.option = CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT;
    para.app_id = cbm_app_id;


	para.icon_id = icon_id;
	para.str_id = STR_GLOBAL_DATA_ACCOUNT;

	para.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
	para.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;
	para.option = (cui_dtcnt_select_option_enum) (CUI_DTCNT_SELECT_DEFAULT | 
					CUI_DTCNT_SELECT_BEARER_SWITCH |
					CUI_DTCNT_SELECT_ALLOW_SAME_BEARER_SWITCH |
					CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT);


	mmi_frm_group_create (parent_id, VAPP_WAP_PROF_DTCNT_CUI_GRP_ID, vapp_wap_prof_dtcnt_cui_proc, NULL);

	mmi_frm_group_enter (VAPP_WAP_PROF_DTCNT_CUI_GRP_ID, MMI_FRM_NODE_SMART_CLOSE_FLAG);


	vapp_wap_prof_dtcnt_cui_id = vcui_dtcnt_select_create(VAPP_WAP_PROF_DTCNT_CUI_GRP_ID);


	vcui_dtcnt_select_set_param(vapp_wap_prof_dtcnt_cui_id, &para);


	vcui_dtcnt_select_run(vapp_wap_prof_dtcnt_cui_id);

} 

/*****************************************************************************
* FUNCTION
* vapp_wap_prof_app_entry_cui_hdlr
* DESCRIPTION
*  function to handle the service callback
* PARAMETERS
*    param :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/
void vapp_wap_prof_entry_dtcnt_cui_hdlr(void)
{
	return ;
}


/*****************************************************************************
* FUNCTION
* vapp_wap_prof_app_entry_cui_hdlr
* DESCRIPTION
*  function to handle the service callback
* PARAMETERS
*    param :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/

extern "C" void vapp_wap_prof_app_dtcnt_ready_check_hdlr(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_wap_prov_dtcnt_ready_check_evt_struct *event;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	event = (srv_wap_prov_dtcnt_ready_check_evt_struct *)evt;
	if(vapp_dtcnt_ready_check(event->callback, event->scrn_lock))
	{
		srv_wap_prof_prov_dtcnt_ready_callback();
	}
}

/*****************************************************************************
* FUNCTION
* vapp_wap_prof_app_entry_cui_hdlr
* DESCRIPTION
*  function to handle the service callback
* PARAMETERS
*    param :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/
extern "C" S32 vapp_wap_prof_app_entry_cui_hdlr(mmi_event_struct* evt)   
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	//srv_wap_prof_sim_id_enum sim_id;
	//srv_wap_prof_app_id_enum app_id;
	srv_wap_prof_entry_dtcnt_cui_struct *event;
	U8 cbm_app_id;
	mmi_id parent_id;
	U16 icon_id;


	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	event = (srv_wap_prof_entry_dtcnt_cui_struct*)evt;
	cui_sim_id = event->sim_id;
	cui_app_id = event->app_id;
	cbm_app_id = event->cbm_app_id;
	parent_id = event->parent_id;
	icon_id = event->icon_id;
	if(vapp_dtcnt_ready_check(vapp_wap_prof_entry_dtcnt_cui_hdlr, MMI_FALSE) )
	{
		vapp_wap_prof_entry_dtcnt_cui(cbm_app_id, parent_id, icon_id);
	}

	return MMI_RET_OK;

}

/*****************************************************************************
* FUNCTION
* vapp_wap_prof_app_activate_profile_hdlr
* DESCRIPTION
*  function to handle the service callback
* PARAMETERS
*    evt :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/
extern "C" S32 vapp_wap_prof_app_activate_profile_hdlr(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_wap_prof_sim_id_enum sim_id;
	srv_wap_prof_app_id_enum app_id;
	MMI_BOOL inform_others;
	U32 index;
	srv_wap_prof_activate_profile_struct *event;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	event = (srv_wap_prof_activate_profile_struct*)evt;

	sim_id = event->sim_info;
	app_id = event->app_info;
	inform_others = event->inform_others;
	index = event->index;

	vapp_wap_prof_app_activate_profile(index,inform_others, sim_id, app_id);		

	return MMI_RET_OK;

}
/*****************************************************************************
* FUNCTION
* mmi_wap_prof_app_is_dtcnt_valid_hdlr
* DESCRIPTION
*  function to handle the service callback for data acccount validity status.
* PARAMETERS
*    param :      [IN]  event parameter.
* RETURNS
*  Return MMI_RET_OK if success;
*****************************************************************************/
extern "C" mmi_ret	vapp_wap_prof_app_is_dtcnt_valid_hdlr(mmi_event_struct* param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	VappDtcntAcctValidTypeEnum dtcnt_validity_status;

		srv_wap_prof_check_dtcnt_valid_struct *event;
		
		srv_wap_prof_sim_id_enum sim_id;
		srv_wap_prof_app_id_enum app_id;
		U8 profile_id;
	
		event = (srv_wap_prof_check_dtcnt_valid_struct*)param;
	
		sim_id = event->sim_id;
		app_id = event->app_id;
		profile_id = event->profile_id;
		event->result = KAL_TRUE;

#if (MMI_MAX_SIM_NUM>=2) && defined(__MMI_WLAN_FEATURES__)  
	if(sim_id == SRV_WAP_PROF_SIMID_WLAN )
	{ 
			event->result = KAL_TRUE;

	}
#endif
	if(profile_id != 0)
	{
		dtcnt_validity_status = vapp_dtcnt_acct_is_valid(srv_wap_prof_get_active_dtcnt_index(sim_id, app_id), MMI_FALSE);


		if (dtcnt_validity_status == DTCNT_ACCT_VALID_NONE) 
		{   
				event->result = KAL_FALSE;


		}
	}
		return MMI_RET_OK;


}


/*****************************************************************************
* FUNCTION
*  mmi_wap_prof_app_close_cui
* DESCRIPTION
*  close all the profile operations abruptly.
* PARAMETERS
*  app_id
* RETURNS
*  void
*****************************************************************************/
extern "C" void vapp_wap_prof_app_close_cui(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if( vapp_wap_prof_dtcnt_cui_id != GRP_ID_INVALID )
	{
		vcui_dtcnt_select_close(vapp_wap_prof_dtcnt_cui_id);
		mmi_frm_group_close(VAPP_WAP_PROF_DTCNT_CUI_GRP_ID);
		vapp_wap_prof_dtcnt_cui_id = GRP_ID_INVALID;

	}

}


/*****************************************************************************
* FUNCTION
*  mmi_wap_prof_app_is_re_entry_allowed
* DESCRIPTION
*  This API checks if profile re-entry scenario is allowed. If yes, it de-inits previous instance.
* PARAMETERS
*  void
* RETURNS
* MMI_BOOL
*****************************************************************************/
extern "C" mmi_ret vapp_wap_prof_app_is_re_entry_allowed(mmi_event_struct* param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_wap_prof_module_status_enum module_status;
	srv_wap_prof_re_entry_allowed_struct *event;
		
	//srv_wap_prof_sim_id_enum sim_id;//revise
	// srv_wap_prof_app_id_enum app_id;
	
	event = (srv_wap_prof_re_entry_allowed_struct *)param;

	//sim_id = event->sim_id;
	// app_id = event->app_id;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	srv_wap_prof_get_module_status(&module_status);


	if((SRV_WAP_PROF_PROFILE_SRC_OTA_PROV==srv_wap_prof_get_profile_source())
		||(SRV_WAP_PROF_WAITING == module_status))
	{
		/* 
		* Re-entry not allowed in case if provisioning is going on or profile is waiting, which will be ready after sometime.
		* If does not become ready, then it is a bug. Display info screen is deleted by UM if ProvBox is ON, hence this check
		* will work only when Provisioning inbox is turned OFF.
		*/


        event->result = MMI_FALSE;
		return MMI_RET_OK;

	}
/*	else if ( vapp_wap_prof_dtcnt_cui_id != GRP_ID_INVALID ) //10ADA Checks if DA screen is present
	{

		srv_wap_prof_kill_profile(app_id);
	}
*/

    event->result = MMI_TRUE;
	return MMI_RET_OK;

}


/*****************************************************************************
* FUNCTION
*  mmi_wap_prof_register_cbm_app_id
* DESCRIPTION
*  This API is used to register app id with cbm dynamically.
* PARAMETERS
*  MMI_BOOL id
*  srv_wap_prof_sim_id_enum sim_id
*  srv_wap_prof_app_id_enum app_id
* RETURNS
* U8
*****************************************************************************/

extern "C" U8 mmi_wap_prof_register_cbm_app_id(MMI_BOOL id, srv_wap_prof_sim_id_enum sim_id, srv_wap_prof_app_id_enum app_id)
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	  U8 value;
	  U32 account_id,temp_account_id;
	  cbm_app_info_struct info;
	  U8 cbm_app_id;
	  // srv_wap_prof_cbm_app_id_enum temp = SRV_WAP_PROF_CBM_BRW_APP_ID_1;

	kal_uint16 app_icon_id[] = 
    {
            IMG_GLOBAL_WEB_BROWSER_CSK,
		#if (MMI_MAX_SIM_NUM>=2)	
            IMG_GLOBAL_COMMON_CSK,
		#endif
		#if (MMI_MAX_SIM_NUM >= 3)
			IMG_GLOBAL_MARK_CSK,
		#endif
		#if (MMI_MAX_SIM_NUM >= 4)
			IMG_GLOBAL_NEXT_CSK
		#endif
    };
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
   	if(app_id == SRV_WAP_PROF_APPID_BRW)
	{
			if(id == MMI_TRUE)
			{
					#ifdef WAP2
						info.app_type = DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_BRW_HTTP | DTCNT_APPTYPE_SKIP_WIFI;
					#else
						info.app_type = DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_SKIP_WIFI;
					#endif 
			}
			else
			{
					#ifdef WAP2
						info.app_type = DTCNT_APPTYPE_BRW_WAP | DTCNT_APPTYPE_BRW_HTTP;
					#else
						info.app_type = DTCNT_APPTYPE_BRW_WAP;
					#endif 
			}
			info.app_str_id = STR_ID_VAPP_WAP_PROF_CBM_BROWSER;
	}
		
	else
	{
			if(id == MMI_TRUE)
					info.app_type = DTCNT_APPTYPE_MMS | DTCNT_APPTYPE_SKIP_WIFI;
			else
					info.app_type = DTCNT_APPTYPE_MMS;

			info.app_str_id = STR_GLOBAL_MULTIMEDIA_MESSAGE;
	}
		
    info.app_icon_id = app_icon_id[sim_id];

	cbm_app_id = srv_wap_prof_get_cbm_app_id(app_id, sim_id);

    cbm_deregister_app_id(cbm_app_id);
	value = cbm_register_app_id_with_app_info(
		&info,
			&cbm_app_id);

   account_id  = srv_wap_prof_get_active_dtcnt_index(app_id,sim_id);

   temp_account_id = cbm_set_app_id(account_id, cbm_app_id);

   srv_wap_prof_set_active_profile_index(sim_id, app_id, temp_account_id, MMI_TRUE);

   srv_wap_prof_set_cbm_app(sim_id, app_id,cbm_app_id);

   return value;

}


#endif /* WAP_SUPPORT */ 
#endif /* _VAPP_WAP_PROF_MAIN_CPP_ */
