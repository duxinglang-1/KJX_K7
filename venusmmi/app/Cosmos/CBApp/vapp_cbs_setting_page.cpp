/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *  Vapp_CBS_pages.cpp
 *
 * Project:
 * --------
 *  App CBS
 *
 * Description:
 * ------------
 *  Venus App CBS multi option screen implements for C++
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *			   HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

#include "vapp_cbs_setting_page.h"
#include "vapp_cbs_channel_page.h"
#include "vapp_cbs_language_page.h"
#include "vapp_cbs_iprot.h"
#include "vapp_sms_util.h"
#include "vapp_sim_setting_gprot.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"

extern "C"
{
#include "NwUsabSrvGprot.h"
#include "SimCtrlSrvGprot.h"
#include "ModeSwitchSrvGProt.h"
#include "CphsSrvGprot.h"

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
#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
								    #if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
	   								#endif
                                    #if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
	   								#endif
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    	#if (MMI_MAX_SIM_NUM >= 2)
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
#if (MMI_MAX_SIM_NUM >= 2)	
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
#if (MMI_MAX_SIM_NUM >= 3)	
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
#if (MMI_MAX_SIM_NUM >= 4)	
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
/* under construction !*/
#endif

VappCbsSettingPage::VappCbsSettingPage() : m_ListMenu(NULL),
	m_isNosimInsert(VFX_FALSE), m_groupNumber(0) 
{
    for (VfxS32 simIndex = 0; simIndex < MMI_MAX_SIM_NUM; simIndex++)
    {
        m_listMenuControl[simIndex] = NULL;
    }
}


VfxU32 VappCbsSettingPage::getCount(VfxU32 group) const
{
	return m_GroupItemCnt;
}
void VappCbsSettingPage::getGroupNumber()
{
	m_isNosimInsert =  VFX_FALSE;
	m_groupNumber = 0;
	for(VfxU8 index = 0; index < VAPP_SMS_TOTAL_SIM; index++)
	{
	    mmi_sim_enum simIndex = vapp_sms_sim_index_to_mmi_sim(index);
		if (srv_sim_ctrl_is_inserted(simIndex))
		{

			m_groupToSimIndex[m_groupNumber++] = index;
		}
	}
    if (m_groupNumber == 0)
    {
        m_isNosimInsert = VFX_TRUE;
        ++m_groupNumber;
    }
}

VfxU32 VappCbsSettingPage::getGroupCount() const
{
	return m_groupNumber;
}
VfxBool VappCbsSettingPage::getItemText(
		VcpMenuPos pos, 				   
		VcpListMenuFieldEnum fieldType,  
		VfxWString &text,				 
		VcpListMenuTextColorEnum &color  
		)
{
	
	if (fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
	{
		if (m_isNosimInsert)
        {
            text.loadFromRes(STR_ID_VAPP_CBS_SIM);
        }
		else
		{
			const VfxResId CbsSimResId[]=
			{
			    STR_GLOBAL_SIM_1,
			#if (MMI_MAX_SIM_NUM >= 2)
			    STR_GLOBAL_SIM_2,
			#if (MMI_MAX_SIM_NUM >= 3)
			    STR_GLOBAL_SIM_3,
			#if (MMI_MAX_SIM_NUM >= 4)
			    STR_GLOBAL_SIM_4
			#endif
			#endif
			#endif
			};
			VfxS32 simIndex = m_groupToSimIndex[pos.group]; 
			if (m_groupNumber == 1)
			{
				text.loadFromRes(STR_ID_VAPP_CBS_SIM);
			}
			else
			{
	        text.loadFromRes(CbsSimResId[simIndex]);
			}
	        mmi_sim_enum mmi_sim = vapp_sms_sim_index_to_mmi_sim(simIndex);
	        VfxWString name = vapp_sim_settings_get_sim_name(mmi_sim);
	        if (!name.isEmpty())
	        {
	            text += VFX_WSTR("(");
	            text += name;
	            text += VFX_WSTR(")");
	        }
		}
	}
	else if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
	{
		const VfxResId CbsSettingResId[]=
		{
		    STR_ID_VAPP_CBS_MAIN_ACTIVATION,
			STR_ID_VAPP_CBS_MAIN_RECEIVING_CHANNELS,
		    STR_ID_VAPP_CBS_MAIN_LANGUAGES
		};
		text.loadFromRes(CbsSettingResId[pos.pos]);

	}
	return VFX_TRUE;
}

VfxBool VappCbsSettingPage::getItemIsDisabled(
		VcpMenuPos pos	 // [IN] position of the item
		) const
{
	if (m_isNosimInsert)
	{
		return VFX_TRUE;
	}
	
	VfxS32 simIndex = m_groupToSimIndex[pos.group]; 
	mmi_sim_enum mmi_sim = vapp_sms_sim_index_to_mmi_sim(simIndex);	
	srv_sms_sim_enum sim_id = vapp_sms_sim_index_to_sim_id(simIndex);
	MMI_BOOL isSimReady = srv_cbs_is_ready(sim_id);
	MMI_BOOL isSimUsable = srv_nw_usab_is_usable(mmi_sim);
	MMI_BOOL isSimCspOn = srv_cphs_is_service_available(SRV_CPHS_GROUP_TELESERVICES, SRV_CPHS_SERVICE_SM_CB, mmi_sim);

	if (isSimReady && isSimUsable && isSimCspOn)
	{
		return VFX_FALSE;
	}
	else
	{
		return VFX_TRUE;
	}
}
VfxBool VappCbsSettingPage::getItemImage(
		VcpMenuPos pos, 				 // [IN] the position of item
		VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
		VfxImageSrc &image				 // [OUT] the image resource
		)
{
	VfxBool result = VFX_FALSE;
    switch (fieldType)
    {
        case VCP_LIST_MENU_FIELD_DISCLOSURE_IMG:
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
            result = VFX_TRUE;
            break;

        case VCP_LIST_MENU_FIELD_HIGHLIGHT_DISCLOSURE_IMG:
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE);
            result = VFX_TRUE;
            break;

        default :
            break;
    }
    return result;
}

VfxBool VappCbsSettingPage::getItemIsHighlightable(
		VcpMenuPos pos	 // [IN] position of the item
		) const
{
	if (pos.pos == ITEM_ID_ACTIVATION)
	{
		return VFX_FALSE;
	}
	else
	{
		return VFX_TRUE;
	}
}
VcpListMenuCellBaseControl* VappCbsSettingPage::getItemCustomControl(
		VcpMenuPos pos, 								 // [IN] position of the item
		VcpListMenuCellControlLocationTypeEnum location, // [IN] Control location
		VfxFrame *parentFrame							 // [IN] parent frame of the custom content frame
		)
{
	
	VappSmsSettingSwitchCp* listMenuControl = NULL;


	
	if (location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
	{
		if (pos.pos == ITEM_ID_ACTIVATION)
		{	
			VFX_OBJ_CREATE(listMenuControl, VappSmsSettingSwitchCp, parentFrame);
			if (!m_isNosimInsert)
			{
				VfxS32 simIndex = m_groupToSimIndex[pos.group];
				srv_sms_sim_enum simId = vapp_sms_sim_index_to_sim_id(simIndex);
				mmi_sim_enum mmi_sim = vapp_sms_sim_index_to_mmi_sim(simIndex);
				listMenuControl->setSwitchStatus(srv_cbs_get_receive_mode(simId));
				if (srv_sim_ctrl_is_available(mmi_sim))
				{
					listMenuControl->m_signalSwitchChanged.connect(this, &VappCbsSettingPage::activationSwitched);
				}
				else
				{
					listMenuControl->setSwitchMovable(VFX_FALSE);
					listMenuControl->m_signalSwitchUnmovable.connect(this, &VappCbsSettingPage::OnSRSwitchUnmovable);
				}
				m_listMenuControl[simIndex] = listMenuControl;
			}
			else
			{
                m_listMenuControl[0] = listMenuControl;
			}
		}
		if (listMenuControl)
		{
			listMenuControl->setAlignParent(
			    VFX_FRAME_ALIGNER_MODE_NONE,
			    VFX_FRAME_ALIGNER_MODE_NONE,
			    VFX_FRAME_ALIGNER_MODE_SIDE,
			    VFX_FRAME_ALIGNER_MODE_MID);
		}
	}
	return listMenuControl;
}
void VappCbsSettingPage::onInit()
{
	VfxPage::onInit();
	getGroupNumber();
	
	VcpTitleBar *m_titleBar = NULL;
	VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
	m_titleBar->setTitle((VfxResId)STR_ID_VAPP_CBS_MAIN_TITLE);
    setTopBar(m_titleBar);
    setStatusBar(VFX_TRUE);

    VFX_OBJ_CREATE(m_ListMenu, VcpGroupListMenu, this);
    m_ListMenu->setSize(getSize());
    m_ListMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_ListMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_ListMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE, VFX_FALSE);
    m_ListMenu->setContentProvider(this);
    m_ListMenu->m_signalItemTapped.connect(this, &VappCbsSettingPage::onItemTapped);

	
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY, VappCbsSettingPage::onFlightModeSwitchProc, getObjHandle());
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappCbsSettingPage::onFlightModeSwitchProc, getObjHandle());
}

void VappCbsSettingPage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY, VappCbsSettingPage::onFlightModeSwitchProc, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappCbsSettingPage::onFlightModeSwitchProc, getObjHandle());
	VfxPage::onDeinit();
}

mmi_ret VappCbsSettingPage::onFlightModeSwitchProc(mmi_event_struct *evt)
{
	VappCbsSettingPage *page = (VappCbsSettingPage*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
	if (page)
 	{
		switch (evt->evt_id)
		{
			case EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY:
			{
				page->m_ListMenu->setIsDisabled(VFX_TRUE);
				break;
			}

		    case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
			{
				page->m_ListMenu->setIsDisabled(VFX_FALSE);
 				page->m_ListMenu->resetAllItems();
		        break;
	    	}
			default:
				break;
		}

 	}
	return MMI_RET_OK;
}

void VappCbsSettingPage::onItemTapped(VcpGroupListMenu * sender, VcpMenuPos pos)
{
	VfxS32 simIndex = m_groupToSimIndex[pos.group]; 
	mmi_sim_enum mmi_sim = vapp_sms_sim_index_to_mmi_sim(simIndex);

	if (!srv_sim_ctrl_is_available(mmi_sim))
    {
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    	balloon->addItem(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_CBS_UNAVAILABLE_SIM));
		return;
    }
	
	VfxMainScr *mainScr = (VfxMainScr *)(getMainScr());

	VfxPage *page = NULL;
	//VappCbsSimEnum cbsSim = simIndexToCbssim(simIndex);
	switch (pos.pos)
	{
		case ITEM_ID_CHANNEL:
			{
			    //VappCbsChannelListPage *channelPage = NULL;
	    		VFX_OBJ_CREATE_EX(page, VappCbsChannelListPage, mainScr, (simIndex));
	    		//channelPage->setSim(simIndexToCbssim(simIndex));
	    		//channelPage->showPage();
	    		//mainScr->pushPage(0, channelPage);
			}
			break;
		case ITEM_ID_LANGUAGE:
			{
			    //VappCbsLanguagePage *languagePage = NULL;
	    		VFX_OBJ_CREATE_EX(page, VappCbsLanguagePage, mainScr, (simIndex));
	    		//languagePage->setSim(simIndexToCbssim(simIndex));
	    		//languagePage->showPage();
	    		//mainScr->pushPage(0, languagePage);
			}
			break;

		default:
			return;
			
	}
	mainScr->pushPage(0, page);

}

void VappCbsSettingPage::activationSwitched(VfxObject *sender, VfxBool isChecked)
{
    for (VfxS32 simIndex = 0; simIndex < MMI_MAX_SIM_NUM; simIndex++)
    {
        if (sender == m_listMenuControl[simIndex])
        {
        	kal_bool is_subscribe = isChecked ? KAL_TRUE : KAL_FALSE;
            srv_sms_sim_enum simId = vapp_sms_sim_index_to_sim_id(simIndex);
			//srv_cbs_subscribe(is_subscribe, simId, &VappCbsSettingPage::switchActivationCallback, getObjHandle());
			srv_cbs_subscribe(is_subscribe, simId, NULL, NULL);
        }
    }
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
#endif
void VappCbsSettingPage::OnSRSwitchUnmovable()
{
    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    balloon->addItem(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_CBS_UNAVAILABLE_SIM));
    return;

}
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#if (MMI_MAX_SIM_NUM >= 2)
/* under construction !*/
		#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
		#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
		#endif
		#endif
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void VappCbsSettingPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}


