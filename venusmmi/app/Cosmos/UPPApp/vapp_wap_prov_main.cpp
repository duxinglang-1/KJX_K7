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
 * vapp_wap_prov_main.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
*------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_include.h"
#ifndef _VAPP_WAP_PROV_MAIN_CPP_
#define _VAPP_WAP_PROV_MAIN_CPP_


#ifdef __cplusplus
extern "C"
{
#endif /* __CPLUSPLUS__ */

#include "WAPprovisioningSrvProt.h"
#include "WAPProfileSrvGprot.h"
#include "DtcntSrvGprot.h"


#ifdef __cplusplus
}
#endif /* __cplusplus */

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vcp_page_panel.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_wap_prov_main.h"
#include "Vapp_dtcnt.h"
#include "vapp_dtcnt_gprot.h"
#include "mmi_rp_vapp_wap_prof_def.h"
#include "vapp_cca_gprot.h"
#include "mmi_rp_vapp_cca_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "GlobalResDef.h"
#include "mmi_rp_vcui_wap_prov_def.h"


static mmi_id cui_id = GRP_ID_INVALID;
static U32 profile_count = 0;
/*****************************************************************************
* FUNCTION
*  vapp_wap_prov_create_display_info
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  PU8(?)
*****************************************************************************/
void vapp_wap_prov_app_create_display_info(U8 *out_buffer, S32 size)
{
/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S8 single_space_char_ucs2[3 * ENCODING_LENGTH];
	S8 *colon_char_ucs2;    /* MAUI_01105762 */
	U8 new_line_info[SRV_WAP_PROV_NEW_LINE_SIZE];
	S8 buffer[MAX_DATA_ACCOUNT_NAME_LEN * ENCODING_LENGTH];     /* MAUI_00062290 */
	S8 ascii_buffer[MAX_DATA_ACCOUNT_NAME_LEN * ENCODING_LENGTH];
	S32 index;
	U32 max_subMenuData_ucs2_chars = ((MAX_SUB_MENUS * MAX_SUB_MENU_SIZE) / ENCODING_LENGTH) - 1;
	U32 used_chars_count = 0;
	//   U32 max_buffer_chars = MAX_DATA_ACCOUNT_NAME_LEN;   /* MAUI_00062290 */
	U32 max_buffer_bytes = sizeof(buffer);
#ifdef __MMI_WAP_PROF_MMS_SETTING_OTA_SUPPORT__
	srv_wap_prov_mms_setting_data_list_struct   *mms_setting_data_p;
#endif
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	memset(out_buffer, 0, size);
	mmi_asc_to_ucs2((S8*) new_line_info, (S8*) "\n");    /* MAUI_00062290 */
	mmi_asc_to_ucs2((S8*) single_space_char_ucs2, (S8*) " ");    /* MAUI_00062290 */
	colon_char_ucs2 = (S8*) GetString(STR_ID_VAPP_WAP_PROF_COLON_CHAR);     /* MAUI_01105762 */
#ifdef BROWSER_SUPPORT
	if (SRV_WAP_PROF_APPID_BRW == srv_wap_prov_get_app_id())
	{
		mmi_ucs2ncpy((PS8) out_buffer, (PS8) GetString(STR_ID_VAPP_CCA_BROWSER), max_subMenuData_ucs2_chars);
	}
	else
	{
#ifdef MMS_SUPPORT	
		mmi_ucs2ncpy((PS8) out_buffer, (PS8) GetString(STR_ID_VAPP_CCA_MMS), max_subMenuData_ucs2_chars);
#endif		
	}
#endif
	mmi_ucs2cat((PS8) out_buffer, (S8*) new_line_info);
	mmi_ucs2cat(
		(PS8) out_buffer,
		(PS8) GetString(STR_ID_VAPP_CCA_PROFILE));
	/* MAUI_01105762 */
	mmi_ucs2cat((PS8) out_buffer, (PS8) colon_char_ucs2);
	mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);
	/* MAUI_01105762 ends */

	memset(buffer, 0, max_buffer_bytes);
	memset(ascii_buffer, 0, sizeof(ascii_buffer));
	sprintf(
		(S8*) ascii_buffer,
		/*            (S8*) "%c %d/%d", ':',  MAUI_01105762 */ (S8*) "%d/%d",     /* MAUI_01105762 */
		srv_wap_prov_get_current_bkm_mms_index() + 1,
		srv_wap_prov_get_current_bkm_mms_index() + srv_wap_prov_get_profile_count());

	mmi_asc_to_ucs2((S8*) buffer, (S8*) ascii_buffer);
	mmi_ucs2cat((PS8) out_buffer, (PS8) buffer); /* MAUI_00062290 */
	mmi_ucs2cat((PS8) out_buffer, (S8*) "\n");
	mmi_ucs2cat((PS8) out_buffer, (S8*) "\n");

	if (srv_wap_prov_get_bkm_cnt() > 0)
	{
		mmi_ucs2cat((PS8) out_buffer, (S8*) new_line_info);    /* MAUI_00062290 */
		mmi_ucs2cat((PS8) out_buffer, 
			(PS8) GetString(STR_ID_VAPP_WAP_PROF_PROV_BOOKMARKS_COLON));
		mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);

		memset(buffer, '\0', max_buffer_bytes);
		memset(ascii_buffer, 0, sizeof(ascii_buffer));
		sprintf(
			(S8*) ascii_buffer,
			(S8*) "%d",
			srv_wap_prov_get_bkm_cnt());
		mmi_asc_to_ucs2((S8*) buffer, (S8*) ascii_buffer);
		mmi_ucs2cat((PS8) out_buffer, buffer);

		for (index = 0; index < srv_wap_prov_get_bkm_cnt(); index++)
		{
			mmi_ucs2cat((PS8) out_buffer, (S8*) new_line_info);
			used_chars_count = mmi_ucs2strlen((PS8) out_buffer);

			memset(buffer, '\0', max_buffer_bytes);
			mmi_ucs2ncat((PS8) out_buffer, 
				GetString(STR_ID_VAPP_WAP_PROF_PROV_BOOKMARK), 
				(max_subMenuData_ucs2_chars - used_chars_count - 1 - 1));
			sprintf((S8*) ascii_buffer, (S8*) "%d", index + 1);       /* MAUI_01105762 */
			mmi_asc_to_ucs2((S8*) buffer, (S8*) ascii_buffer);  /* MAUI_00062290 */
			mmi_ucs2ncat((PS8) out_buffer, (PS8) buffer, (max_subMenuData_ucs2_chars - used_chars_count - 1));
			/* MAUI_01105762 */
			mmi_ucs2cat((PS8) out_buffer, (PS8) colon_char_ucs2);
			mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);
			/* MAUI_01105762 ends */
			used_chars_count = mmi_ucs2strlen((PS8) out_buffer);

		  if (mmi_ucs2strlen(srv_wap_prov_get_bm_title(index)) != 0)
			{
				if ((S32)
					(max_subMenuData_ucs2_chars - used_chars_count - 1 -
					mmi_ucs2strlen((S8*) g_srv_wap_prov_cntx.profile_list[g_srv_wap_prov_cntx.crnt_prof_index]->
					bookmark[index]->bm_title)) <= 0)
				{
					/* 
					*  break out if length of destination is not large enough.
					*/
					break;
				}
				srv_wap_prof_prov_get_displayable_data(out_buffer,srv_wap_prov_get_bm_title(index),
					SRV_WAP_PROF_DCS_UCS2);
			}

			if ((S32) (max_subMenuData_ucs2_chars - used_chars_count - 1 - strlen(srv_wap_prov_get_bm_url(index))) <= 0)
			{
				/* 
				*  break out if length of destination is not large enough.
				*/
				break;
			}
			srv_wap_prof_prov_get_displayable_data(out_buffer,srv_wap_prov_get_bm_url(index),
				SRV_WAP_PROF_DCS_ASCII);
		}
	}

	/* MAUI_00808274 starts */

#ifdef __MMI_WAP_PROF_MMS_SETTING_OTA_SUPPORT__

	mms_setting_data_p = srv_wap_prov_get_mms_setting_data();

	if (mms_setting_data_p)
	{
		mmi_ucs2cat((PS8) out_buffer, (S8*) new_line_info);        /* MAUI_00062290 */
		used_chars_count = mmi_ucs2strlen((PS8) out_buffer);
		mmi_ucs2ncat((PS8) out_buffer, 
			(PS8) GetString (STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTINGS), 
			(max_subMenuData_ucs2_chars - used_chars_count - 1));

		for (; mms_setting_data_p; mms_setting_data_p = mms_setting_data_p->next)
		{
			used_chars_count = mmi_ucs2strlen((PS8) out_buffer);
			if (used_chars_count >= max_subMenuData_ucs2_chars)
			{
				/* No more space to put characters. */
				break;
			}

			mmi_ucs2cat((PS8) out_buffer, (S8*) new_line_info);
			switch (mms_setting_data_p->key)
			{
			
			case SRV_WAP_PROV_MMS_SETTING_CM:
				mmi_ucs2ncat((PS8) out_buffer, 
						(PS8) GetString (STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_CM_COLON), 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
				
#ifdef __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__
			case SRV_WAP_PROV_MMS_SETTING_RM:
				mmi_ucs2ncat((PS8) out_buffer, 
						(PS8) GetString (STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_RM_COLON), 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));				
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__ */
#endif
				mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);
				used_chars_count = mmi_ucs2strlen((PS8) out_buffer);

				if (SRV_WAP_PROV_MMS_SETTING_RESTRICTED <= mms_setting_data_p->value_i && 
						mms_setting_data_p->value_i <= SRV_WAP_PROV_MMS_SETTING_FREE)
				{
					mmi_ucs2ncat((PS8) out_buffer, 
						(PS8) GetString (STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_VALUE_RESTRICTED + 
											(mms_setting_data_p->value_i - SRV_WAP_PROV_MMS_SETTING_RESTRICTED)), 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
				}
				else
				{
					mmi_ucs2ncat((PS8) out_buffer, /*(CHAR*) GetString (STR_ID_VAPP_PROF_PROV_MMS_SETTING_VALUE_INVALID), */
						(PS8) GetString (STR_GLOBAL_INVALID),  /* Global string usage */
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
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
				#endif
				break;

#ifdef __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__

			case SRV_WAP_PROV_MMS_SETTING_MA:
				mmi_ucs2ncat((PS8) out_buffer, 
					(PS8) GetString (STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_MA_COLON), 
					(max_subMenuData_ucs2_chars - used_chars_count - 1));
				mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);
				used_chars_count = mmi_ucs2strlen((PS8) out_buffer);

				if (SRV_WAP_PROV_MMS_SETTING_MA_DISABLE <= mms_setting_data_p->value_i && 
						mms_setting_data_p->value_i <= SRV_WAP_PROV_MMS_SETTING_MA_LOCKED)
				{
					mmi_ucs2ncat((PS8) out_buffer, 
						(PS8) GetString (STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_VALUE_DISABLE + 
											(mms_setting_data_p->value_i - SRV_WAP_PROV_MMS_SETTING_MA_DISABLE)), 
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
				}
				else
				{
					mmi_ucs2ncat((PS8) out_buffer, /*(CHAR*) GetString (STR_ID_VAPP_PROF_PROV_MMS_SETTING_VALUE_INVALID), */
						(PS8) GetString (STR_GLOBAL_INVALID),  /* Global string usage */
						(max_subMenuData_ucs2_chars - used_chars_count - 1));
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
				#endif
				break;

			case SRV_WAP_PROV_MMS_SETTING_MS:
				mmi_ucs2ncat((PS8) out_buffer, 
					(PS8) GetString (STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_MS_COLON), 
					(max_subMenuData_ucs2_chars - used_chars_count - 1));
				mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);
				used_chars_count = mmi_ucs2strlen((PS8) out_buffer);

				sprintf((S8*) ascii_buffer, 
					(S8*) "%d", 
					mms_setting_data_p->value_i);
				mmi_asc_to_ucs2(
					(S8*) buffer,
					(S8*) ascii_buffer);

				mmi_ucs2ncat((PS8) out_buffer, 
					(PS8) buffer, 
					(max_subMenuData_ucs2_chars - used_chars_count - 1));
				break;

			case SRV_WAP_PROV_MMS_SETTING_PCADDR:
				mmi_ucs2ncat((PS8) out_buffer, 
					(PS8) GetString (STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_PCADDR_COLON), 
					(max_subMenuData_ucs2_chars - used_chars_count - 1));
				mmi_ucs2cat((PS8) out_buffer, single_space_char_ucs2);

				srv_wap_prof_prov_get_displayable_data(out_buffer, (S8*) mms_setting_data_p->value_s,
					SRV_WAP_PROF_DCS_ASCII);
				/* MAUI_00062290 ends */

				break;
#endif /* __MMI_WAP_PROF_MMS_1_3_SETTING_OTA_SUPPORT__ */
			}
		}
	}
#endif /* __MMI_WAP_PROF_MMS_SETTING_OTA_SUPPORT__ */
	/* MAUI_00808274 ends */
}


/* Create Cui and run it */
extern "C" mmi_id vcui_prov_setting_display_create(mmi_id parent_id)
{

    mmi_id cui_id = VfxAppLauncher::createCui(
                                        VCUI_WAP_PROV,
                                        VFX_OBJ_CLASS_INFO(VappProvSettingDisplay),
                                        vapp_cca_get_parent_id());
	vfxSetCuiCallerScr(cui_id, vapp_cca_get_parent_screen());
    return cui_id;
}



/* Execute CUI*/
extern "C" void vcui_prov_setting_display_run(mmi_id cui_id)
{
    VfxAppLauncher::runCui(cui_id);
}

/* Close CUI */
extern "C" void  vcui_prov_setting_display_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
	cui_id = GRP_ID_INVALID;

}

extern "C" void vcui_prov_setting_redisplay(mmi_id cui_id,VfxS32 profile_count)
{
   if(profile_count)
{
   VappProvSettingDisplay *pagecui 
	   = ((VappProvSettingDisplay *)VfxAppLauncher::getObject(cui_id));
   pagecui->m_scr->redrawPage();
   }
   else
      vcui_prov_setting_display_close(cui_id);

}



/*****************************************************************************
 * FUNCTION
 * mmi_wap_prof_prov_app__prov_screen_hdlr
 * DESCRIPTION
 *  function to handle the service callback
 * PARAMETERS
 *    param :      [IN]  event parameter.
 * RETURNS
 *  Return MMI_RET_OK if success;
 *****************************************************************************/
extern "C" S32 vapp_wap_prof_prov_app_prov_screen_hdlr(mmi_event_struct* evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
	  srv_wap_prov_create_prov_scrn_evt_struct *event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	event = (srv_wap_prov_create_prov_scrn_evt_struct*)evt;
	switch (event->evt_id)
    {
    case EVT_ID_SRV_UPP_CREATE_PROV_SCR_IND:
			cui_id = vcui_prov_setting_display_create(1);
            vcui_prov_setting_display_run(cui_id);
        break;
    case EVT_ID_SRV_UPP_RECREATE_PROV_SCR_IND:
			profile_count = event->profile_count;
		if(cui_id!=GRP_ID_INVALID)
		vcui_prov_setting_redisplay(cui_id, profile_count);
        break;
    default:
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  vapp_wap_prov_app_dtcnt_ready_check_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 * evt
 * RETURNS
 *  S32
 *****************************************************************************/
extern "C" S32 vapp_wap_prov_app_dtcnt_ready_check_hdlr(mmi_event_struct *evt)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
      srv_wap_prov_dtcnt_ready_check_evt_struct *event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
	event = (srv_wap_prov_dtcnt_ready_check_evt_struct*)evt;
	if(vapp_dtcnt_ready_check(event->callback, event->scrn_lock)) 
	{
		srv_wap_prof_prov_dtcnt_ready_callback();  //10ADA
	}
return MMI_RET_OK;	
}


/***************************************************************************** 
 * Class VappProvSettingDisplay
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappProvSettingDisplay", VappProvSettingDisplay, VfxCui);

void VappProvSettingDisplay::onRun(void * arg,VfxU32 argSize)
{   
    VFX_OBJ_CREATE(m_scr, VappProvSettingScr, this);
    m_scr->show();
}

mmi_ret VappProvSettingDisplay::onProc(mmi_event_struct * evt)
{
    return MMI_RET_OK;
}


void VappProvSettingPage::onBack()
{
	VcpConfirmPopup *m_confirmPopup;
    VfxWString confirmString;
    confirmString.loadFromRes(STR_ID_VAPP_CCA_EXIT_INSTALL_CONFIRM);
    VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
    m_confirmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    m_confirmPopup->setText(confirmString);
    //m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
	m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
	m_confirmPopup->setCustomButton(
			(VfxResId)(STR_GLOBAL_YES),
			(VfxResId)(STR_GLOBAL_NO),
			VCP_POPUP_BUTTON_TYPE_RECOMMEND,
			VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_confirmPopup->show(VFX_TRUE);
    m_confirmPopup->m_signalButtonClicked.connect(this, &VappProvSettingPage::exitProvScrnHandler);

}

void VappProvSettingPage::exitProvScrnHandler(VfxObject* obj, VfxId id)
{
    MMI_BOOL status_sent =MMI_FALSE;
	srv_wap_prov_get_status_sent(&status_sent);
	if (id == VCP_CONFIRM_POPUP_BUTTON_USER_1)
    {
        
		if((cui_id!=GRP_ID_INVALID) && (MMI_FALSE == status_sent))
		{
			srv_wap_prof_prov_reset_info_on_back();
			//VfxAppLauncher::terminate(cui_id);
	        cui_id = GRP_ID_INVALID;
			
		}
		
    }
}



/***************************************************************************** 
 * Class VappProvSettingScr
 *****************************************************************************/

void VappProvSettingScr::on1stReady()
{
    VfxMainScr::on1stReady();
   
	VFX_OBJ_CREATE(m_page, VappProvSettingPage, this);
	pushPage(0, m_page);	

 
}


void VappProvSettingPage::onInit()
{
    VfxPage::onInit(); // call base class

	//setBgColor(VFX_COLOR_WHITE);
	
	VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);    
    VfxWString str;
    str.loadFromRes(STR_ID_VAPP_CCA_INSTALL_SETTING);
    m_titleBar->setTitle(str);
    setTopBar(m_titleBar);

     VFX_ALLOC_MEM(m_bodyText, 1024, this);
    
	 vapp_wap_prov_app_create_display_info((VfxU8*)m_bodyText, 1024);
     
	 VFX_OBJ_CREATE(m_bodyTextView, VcpTextView, this);

    VfxRect page_rect = getRect();
	m_bodyTextView->setRect(0, 0, page_rect.size.width, page_rect.size.height);
	m_bodyTextView->setAlignParent(
	VFX_FRAME_ALIGNER_MODE_SIDE,
	VFX_FRAME_ALIGNER_MODE_SIDE,
	VFX_FRAME_ALIGNER_MODE_SIDE,
	VFX_FRAME_ALIGNER_MODE_SIDE);

	m_bodyTextView->setText(m_bodyText);
	m_bodyTextView->setLineMode(VCP_TEXT_LINE_MODE_MULTI);

	m_bodyTextView->setMargins(LEFT_GAPS, LEFT_GAPS, LEFT_GAPS, LEFT_GAPS);

    
    VFX_OBJ_CREATE(m_tool_bar, VcpToolBar, this);   
    m_tool_bar->addItem(PROV_SETTING_VIEWER_INSTALL,(VfxResId)(VCP_STR_TOOL_BAR_INSTALL), IMG_ID_VAPP_CCA_INSTALL);

    m_tool_bar->addItem(PROV_SETTING_VIEWER_SKIP, (VfxResId)(STR_ID_VAPP_CCA_SKIP), IMG_ID_VAPP_CCA_SKIP);
    m_tool_bar->m_signalButtonTap.connect(this, &VappProvSettingPage::onProvSettingPageTBClick);
    setBottomBar(m_tool_bar);


    
}

void VappProvSettingPage::onDeinit()
{
    MMI_BOOL status_sent =MMI_FALSE; 
	
     VFX_FREE_MEM(m_bodyText);
   
	 
	srv_wap_prov_get_status_sent(&status_sent);
	if((cui_id!=GRP_ID_INVALID) && (MMI_FALSE == status_sent))
		{
			srv_wap_prof_prov_reset_info_on_back();
			//VfxAppLauncher::terminate(cui_id);
	        cui_id = GRP_ID_INVALID;
			
		}
	 VfxPage::onDeinit();
}

void VappProvSettingPage::onProvSettingPageTBClick(VfxObject* sender, VfxId id)
{
	switch(id)
	{
		case PROV_SETTING_VIEWER_INSTALL:
			 srv_wap_prov_install_setting();			
		     break;
			
		case PROV_SETTING_VIEWER_SKIP:	        
	        srv_wap_prov_skip_profile();
	         break;
	   default:
			 break;
	}
}


#endif /* _VAPP_WAP_PROV_MAIN_CPP_ */
