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
 *  vapp_sms_setting_scrn.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  SMS setting for Venus UI
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "GlobalResDef.h"
#include "vapp_sms_setting_scrn.h"
#include "vapp_sms_setting_core.h"
#include "vapp_sim_setting_gprot.h"

#include "vapp_sms_voicemail_scrn.h"
#include "mmi_rp_app_vapp_sms_def.h"
#include "vfx_xml_loader.h"
#include "vfx_adp_device.h"

#include "mmi_rp_app_cosmos_global_def.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"
#include "Wgui_categories_inputs.h"

#include "vapp_usb_gprot.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "vapp_msg_features.h"


/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmssrvGprot.h"
    #include "CphsSrvGprot.h"
    #include "SimCtrlSrvGProt.h"
    #include "ModeSwitchSrvGProt.h"
	#include "FileMgrSrvGProt.h"
	#include "UmSrvStruct.h"
	#include "USBsrvGprot.h"
#ifdef __cplusplus
}
#endif

#define VAPP_SMS_SEND_ILM(destMod, msgId, loacPara)	\
			mmi_frm_send_ilm(destMod, msgId, (oslParaType*)loacPara, NULL)

/***************************************************************************** 
 * Class 
 *****************************************************************************/
const VfxResId SmsSettingResId[] = 
{
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	STR_ID_SMS_DEFAULT_STORAGE,
	STR_ID_SMS_MSG_FILTER,
#endif

#ifdef __SMS_OVER_PS_SUPPORT__
    STR_ID_VAPP_SMS_PREFERED_BEARER,
#endif //__SMS_OVER_PS_SUPPORT__
    STR_ID_VAPP_SMS_REPLY_PATH,


    STR_ID_VAPP_SMS_PROFILE_SETTING,
    STR_ID_VAPP_SMS_VM_SERVER,
#ifdef __SRV_SMS_DELIVERY_STATUS__
    STR_ID_VAPP_SMS_DELIVERY_REPORT,
#endif //__SRV_SMS_DELIVERY_STATUS__
#ifdef __VAPP_SMSPREFER_STORAGE_SETTING__
    STR_ID_VAPP_SMS_PREFER_STORAGE,
#endif //__VAPP_SMSPREFER_STORAGE_SETTING__

#if (MMI_MAX_SIM_NUM >= 2)
    STR_ID_VAPP_SMS_PROFILE_SETTING,
    STR_ID_VAPP_SMS_VM_SERVER,
#ifdef __SRV_SMS_DELIVERY_STATUS__
    STR_ID_VAPP_SMS_DELIVERY_REPORT,
#endif //__SRV_SMS_DELIVERY_STATUS__    
#ifdef __VAPP_SMSPREFER_STORAGE_SETTING__
		STR_ID_VAPP_SMS_PREFER_STORAGE,
#endif //__VAPP_SMSPREFER_STORAGE_SETTING__
#endif //MMI_MAX_SIM_NUM >= 2

#if (MMI_MAX_SIM_NUM >= 3)
    STR_ID_VAPP_SMS_PROFILE_SETTING,
    STR_ID_VAPP_SMS_VM_SERVER,
    
#ifdef __SRV_SMS_DELIVERY_STATUS__
    STR_ID_VAPP_SMS_DELIVERY_REPORT,
#endif //__SRV_SMS_DELIVERY_STATUS__  
#ifdef __VAPP_SMSPREFER_STORAGE_SETTING__
    STR_ID_VAPP_SMS_PREFER_STORAGE,
#endif //__VAPP_SMSPREFER_STORAGE_SETTING__
#endif //MMI_MAX_SIM_NUM >= 3

#if (MMI_MAX_SIM_NUM >= 4)
    STR_ID_VAPP_SMS_PROFILE_SETTING,
    STR_ID_VAPP_SMS_VM_SERVER,   
#ifdef __SRV_SMS_DELIVERY_STATUS__
    STR_ID_VAPP_SMS_DELIVERY_REPORT,
#endif //__SRV_SMS_DELIVERY_STATUS__ 
#ifdef __VAPP_SMSPREFER_STORAGE_SETTING__
    STR_ID_VAPP_SMS_PREFER_STORAGE,
#endif //__VAPP_SMSPREFER_STORAGE_SETTING__
#endif //MMI_MAX_SIM_NUM >= 4
};


#ifdef __VAPP_SMSPREFER_STORAGE_SETTING__
	#ifdef __SRV_SMS_DELIVERY_STATUS__
#define SMS_SIM_SETTING_CNT  4
	#else ////__SRV_SMS_DELIVERY_STATUS__ 
		#define SMS_SIM_SETTING_CNT  3
	#endif //__SRV_SMS_DELIVERY_STATUS__  
#else //__VAPP_SMSPREFER_STORAGE_SETTING__
	#ifdef __SRV_SMS_DELIVERY_STATUS__
#define SMS_SIM_SETTING_CNT  3
	#else ////__SRV_SMS_DELIVERY_STATUS__ 
		#define SMS_SIM_SETTING_CNT  2
	#endif //__SRV_SMS_DELIVERY_STATUS__  
#endif //__VAPP_SMSPREFER_STORAGE_SETTING__
const VfxResId SmsSettingGroupResId[]=
{
    0,
    STR_GLOBAL_SIM_1,
    STR_GLOBAL_SIM_2,
    STR_GLOBAL_SIM_3,
    STR_GLOBAL_SIM_4
};

VfxS32 SmsSettingGroupItemNum[]=
{

#ifdef __SMS_OVER_PS_SUPPORT__
	#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		4,
	#else
    2,
	#endif
#else //__SMS_OVER_PS_SUPPORT__
	#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		3,
	#else
    1,
	#endif
#endif //__SMS_OVER_PS_SUPPORT__

    SMS_SIM_SETTING_CNT, 
    SMS_SIM_SETTING_CNT,
    SMS_SIM_SETTING_CNT,
    SMS_SIM_SETTING_CNT
};

static const VfxResId defaultProfileNames[VAPP_SMS_MAX_LFOUR_PROFILES] = 
{
    STR_ID_VAPP_SMS_SET0,
    STR_ID_VAPP_SMS_SET1,
    STR_ID_VAPP_SMS_SET2,
    STR_ID_VAPP_SMS_SET3
};
/*****************************************************************************
 * Class VcpSmsSwitch    Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VcpSmsSwitch", VcpSmsSwitch, VcpSwitch);

VcpSmsSwitch::VcpSmsSwitch():m_isSwitchMovable(VFX_TRUE)
{
}
void VcpSmsSwitch::setMovable(VfxBool isMovable)
{
    m_isSwitchMovable = isMovable;
}

VfxBool VcpSmsSwitch::onPenInput(VfxPenEvent &event)
{
    VfxBool ret;

    ret = VFX_FALSE;
    if (m_isSwitchMovable == VFX_FALSE)
    {
        m_signalSwitchUnmovable.emit();
        return ret;       
    }

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
                if(getIsHapticTouchEnabled())
                {
                    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);
                }
        case VFX_PEN_EVENT_TYPE_MOVE:        
            ret = VFX_TRUE;
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            // toggle state
            setChecked(!getChecked() );

            // emit value change signal
            m_signalSwitchChanged.emit(this, getChecked());
            
            ret = VFX_TRUE;
            break;

        default:
            break;       
    }

    return ret;

}


/*****************************************************************************
 * Class VappSmsSettingSwitchCp Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSmsSettingSwitchCp", VappSmsSettingSwitchCp, VcpListMenuCellBaseControl);

void VappSmsSettingSwitchCp::onInit()
{
    Super::onInit();

    VFX_OBJ_CREATE(m_switch, VcpSmsSwitch, this);

    m_switch->setChecked(VFX_TRUE, VFX_TRUE);
    setSize(m_switch->getSize());
    m_switch->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_NONE,
        VFX_FRAME_ALIGNER_MODE_NONE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_MID);
    m_switch->m_signalBoundsChanged.connect(this, &Self::onSwitchBoundsChanged);
    m_switch->m_signalSwitchChanged.connect(this, &Self::OnSwitchSignal);
    m_switch->m_signalSwitchUnmovable.connect(this, &Self::onSwitchUnmovable);
}

void VappSmsSettingSwitchCp::onDeinit()
{
    m_switch->m_signalBoundsChanged.disconnect(this, &Self::onSwitchBoundsChanged);
    m_switch->m_signalSwitchChanged.disconnect(this, &Self::OnSwitchSignal);
    VFX_OBJ_CLOSE(m_switch);

    Super::onDeinit();
}

void VappSmsSettingSwitchCp::setSwitchStatus(VfxBool checked)
{
    m_switchStatus = checked;
    m_switch->setChecked(checked, VFX_TRUE);
}
void VappSmsSettingSwitchCp::setSwitchMovable(VfxBool isMovable)
{
    m_switch->setMovable(isMovable);
}


void VappSmsSettingSwitchCp::onSwitchBoundsChanged(VfxFrame *source, const VfxRect &oldBounds)
{
    setBounds(source->getBounds());
}

void VappSmsSettingSwitchCp::OnSwitchSignal(VcpSwitch *sw, VfxBool isChecked)
{
    m_signalSwitchChanged.postEmit(this, isChecked);
}

void VappSmsSettingSwitchCp::onSwitchUnmovable()
{
    m_signalSwitchUnmovable.postEmit();
}

/*****************************************************************************
 * Class VappSmsSettingPage Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSmsSettingPage", VappSmsSettingPage, VfxPage);
VappSmsSettingPage::VappSmsSettingPage():
    m_groupListMenu(NULL),
    m_settings(NULL),
    m_bearerPage(NULL),
    m_profilePage(NULL)
{
    for (VfxU8 i = 0; i < VAPP_SMS_TOTAL_SIM; i++)
    {
        m_listMenuControl[i] = NULL;
    }
}

void VappSmsSettingPage::onInit()
{
    Super::onInit();
    getGroupNumber();

    setStatusBar(VFX_TRUE);

    VFX_OBJ_CREATE(m_settings, SmsSetting, this);
#ifdef __SMS_OVER_PS_SUPPORT__
    m_settings->m_signalBearerInitDone.connect(this, &Self::onInitBearerDone);
#endif

    VcpTitleBar *titleBar;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle((VfxResId)STR_ID_VAPP_SMS_SETTING);
    setTopBar(titleBar);

    VFX_OBJ_CREATE(m_groupListMenu, VcpGroupListMenu, this);
	VfxSize parentSize = getSize();
    m_groupListMenu->setSize(parentSize);
    m_groupListMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_groupListMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_groupListMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE, VFX_FALSE);
    m_groupListMenu->setContentProvider(this);
    m_groupListMenu->m_signalItemTapped.connect(this, &Self::onItemTapped);

	for (int index = 0; index < VAPP_SMS_TOTAL_SIM; index++)
	{
		srv_sms_sim_enum simId = vapp_sms_sim_index_to_sim_id(index);
		VFX_OBJ_CREATE_EX(m_profileList[index], SmsProfileList, this, (simId));
	}
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY, VappSmsSettingPage::onFlightModeSwitchProc, getObjHandle());
    mmi_frm_cb_reg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappSmsSettingPage::onFlightModeSwitchProc, getObjHandle());
}

void VappSmsSettingPage::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY, VappSmsSettingPage::onFlightModeSwitchProc, getObjHandle());
    mmi_frm_cb_dereg_event(EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY, VappSmsSettingPage::onFlightModeSwitchProc, getObjHandle());
    Super::onDeinit();
}

mmi_ret VappSmsSettingPage::onFlightModeSwitchProc(mmi_event_struct *evt)
{
	VappSmsSettingPage *page = (VappSmsSettingPage*)VfxObject::handleToObject((VfxObjHandle)evt->user_data);
	if (page)
 	{
		switch (evt->evt_id)
		{
			case EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY:
			{
				page->m_groupListMenu->setIsDisabled(VFX_TRUE);
				break;
			}

		    case EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY:
			{
				page->m_groupListMenu->setIsDisabled(VFX_FALSE);
 				page->m_groupListMenu->resetAllItems();
		        break;
	    	}
			default:
				break;
		}

 	}
	return MMI_RET_OK;
}


VfxBool VappSmsSettingPage::getItemText(
    VcpMenuPos pos,                    // // [IN] the position of item
    VcpListMenuFieldEnum fieldType,    // [IN] the type of the field in the cell
    VfxWString &text,                  // [OUT] the text resource
    VcpListMenuTextColorEnum &color   // [OUT] the text color
    )
{
    VfxS32 number = 0, index;
    
    for(index = 0; index <pos.group; index++)
    {
        number += SmsSettingGroupItemNum[index];
    }

    if(fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
    {
    	if (pos.group == VAPP_SMS_SETTING_GROUP_ALL_SIM)
		{
        text.loadFromRes(SmsSettingGroupResId[pos.group]);
		}
	    else
	    {
	        if (m_isNosimInsert)
            {
                text.loadFromRes(STR_ID_VAPP_SMS_SIM);
                return VFX_TRUE;
            }   
			else if (m_groupNumber == 1)
			{
				text.loadFromRes(STR_ID_VAPP_SMS_SIM);
			}
			else
			{
	        text.loadFromRes(SmsSettingGroupResId[m_groupToSimIndex[pos.group - 1] + 1]);
			}
	        
	        mmi_sim_enum simIndex = vapp_sms_sim_index_to_mmi_sim(m_groupToSimIndex[pos.group - 1]);
	        VfxWString name = vapp_sim_settings_get_sim_name(simIndex);
            if(!name.isEmpty())
            {
	            text += VFX_WSTR("(");
	            text += name;
	            text += VFX_WSTR(")");
	        }
        }
    }
    else if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text.loadFromRes(SmsSettingResId[number+pos.pos]);
    }
    else if(fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
    {
    	if (pos.group == VAPP_SMS_SETTING_GROUP_ALL_SIM)
		{    
			if (m_isNosimInsert && (pos.pos == ITEM_ID_PREFER_BEARER))
	        {
	            text.loadFromRes(STR_ID_VAPP_SMS_PREFER_GPRS_BEARER);
	            return VFX_TRUE;
	        }
		}
		else
		{
        if (m_isNosimInsert && (pos.pos == ITEM_ID_PROFILE_SETTING))
        {
            text.loadFromRes(defaultProfileNames[0]);
            return VFX_TRUE;
        }
        }
    
        if ((pos.group > VAPP_SMS_SETTING_GROUP_ALL_SIM) && (pos.pos == ITEM_ID_PROFILE_SETTING))
        {
            VfxS32 simIndex = m_groupToSimIndex[pos.group - VAPP_SMS_SETTING_GROUP_SIM_1];
            srv_sms_sim_enum simId = vapp_sms_sim_index_to_sim_id(simIndex);

            const VfxWChar *name = m_settings->getActiveProfileName(simId);

            if (name[0] != '\0')
            {
                text.loadFromMem(name);
            }
            else
            {
                VfxU8 profileIndex = m_settings->getActiveProfileIndex(simId);
                text.loadFromRes(defaultProfileNames[profileIndex]);
            }
        }
    #ifdef __SMS_OVER_PS_SUPPORT__
        else if ((pos.group == VAPP_SMS_SETTING_GROUP_ALL_SIM) && (pos.pos == ITEM_ID_PREFER_BEARER))
        {
            VfxU8 index;
            if (m_settings->getPreferBearer(&index))
            {
            	mmi_rp_app_vapp_sms_str_enum str[] = 
                {
            			STR_ID_VAPP_SMS_PREFER_GPRS_BEARER,
						STR_ID_VAPP_SMS_PREFER_GSM_BEARER,
						STR_ID_VAPP_SMS_GSM_BEARER
            		};
				text.loadFromRes(str[index]);
            }
        }
    #endif //__SMS_OVER_PS_SUPPORT__
	#ifdef __VAPP_SMSPREFER_STORAGE_SETTING__
		else if ((pos.group > VAPP_SMS_SETTING_GROUP_ALL_SIM) && (pos.pos == ITEM_ID_PREFER_STORAGE))
		{
			text.loadFromRes(STR_ID_VAPP_SMS_PREFER_STORAGE_SUB);
		}
	#endif
	#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
		else if ((pos.group == VAPP_SMS_SETTING_GROUP_ALL_SIM) && (pos.pos == ITEM_ID_DEFAULT_STORAGE))
		{
        	srv_sms_storage_enum storage = m_settings->getDefaultStorage(SRV_SMS_SIM_1);
			STR_GLOBAL_LIST_ENUM str[] =
			{
					STR_GLOBAL_PHONE,
					STR_GLOBAL_SIM,
					STR_GLOBAL_MEMORY_CARD
				};
			text.loadFromRes(str[storage]);
		}
		else if ((pos.group == VAPP_SMS_SETTING_GROUP_ALL_SIM) && (pos.pos == ITEM_ID_MSG_FILTER))
		{
			srv_sms_filter_enum filter = srv_sms_get_storage_filter();
			if (filter == SRV_SMS_FILTER_ALL)
			{
	            text.loadFromRes(STR_GLOBAL_PHONE);
				text += VFX_WSTR("\\");
				text += VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD);
			}
			else if (filter & SRV_SMS_FILTER_ME)
			{
				text.loadFromRes(STR_GLOBAL_PHONE);
			}
			else if (filter & SRV_SMS_FILTER_TCARD)
			{
				text.loadFromRes(STR_GLOBAL_MEMORY_CARD);
			}
		}
	#endif/* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
    }
    return VFX_TRUE;
}

VfxBool VappSmsSettingPage::getItemIsDisabled(VcpMenuPos pos) const
{
#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__

	if (pos.group == VAPP_SMS_SETTING_GROUP_ALL_SIM)
	{
		if ((pos.pos == ITEM_ID_DEFAULT_STORAGE) || (pos.pos == ITEM_ID_MSG_FILTER))
		{
			return VFX_FALSE;
		}
	}
#endif/* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */


    if (m_isNosimInsert)
    {
        return VFX_TRUE;
    }
    
    VfxBool hideMenu = MMI_FALSE;

    if (pos.group == VAPP_SMS_SETTING_GROUP_ALL_SIM)
    {
        if (pos.pos == ITEM_ID_REPLY_PATH)
        {
            hideMenu =  VFX_TRUE;
	    for (VfxU8 i = 0; i < m_groupNumber; i++)
	    {
		mmi_sim_enum simIndex =  vapp_sms_sim_index_to_mmi_sim(m_groupToSimIndex[i]);
		if (srv_cphs_is_service_available(SRV_CPHS_GROUP_TELESERVICES, SRV_CPHS_SERVICE_REPLY_PATH, simIndex))
		{
		    hideMenu = VFX_FALSE;
		    break;
		}				
	    }
        }
    }
    else
    {
        mmi_sim_enum sim = vapp_sms_sim_index_to_mmi_sim(m_groupToSimIndex[pos.group - 1]);
 		if (!srv_mode_switch_get_network_mode(sim))
        {
            hideMenu =  VFX_TRUE;
        }
        else if ((pos.pos == ITEM_ID_VOICEMAIL_SERVER)
                && !srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_VPS, sim)
                )
        {
            hideMenu =  VFX_TRUE;
        }
	#ifdef __SRV_SMS_DELIVERY_STATUS__
        else if ((pos.pos == ITEM_ID_DELIVERY_REPORT)
                && !srv_cphs_is_service_available(SRV_CPHS_GROUP_TELESERVICES, SRV_CPHS_SERVICE_DEL_CONF, sim)
                )
        {
            hideMenu =  VFX_TRUE;
        }
	#endif //__SRV_SMS_DELIVERY_STATUS__
    }
    return hideMenu;
	
}


VfxBool VappSmsSettingPage::getItemImage(
    VcpMenuPos pos,                  // [IN] the position of item
    VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
    VfxImageSrc &image               // [OUT] the image resource
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


// Get the item count of the a group
VfxU32 VappSmsSettingPage::getCount(VfxU32 group) const
{
    return SmsSettingGroupItemNum[group];
}


// Get the group count of the lis menu
VfxU32 VappSmsSettingPage::getGroupCount() const
{
    return m_groupNumber + 1;
}

VfxBool VappSmsSettingPage::getItemIsHighlightable(VcpMenuPos pos) const
{
    if (((pos.group == VAPP_SMS_SETTING_GROUP_ALL_SIM) && (pos.pos == ITEM_ID_REPLY_PATH))
	#ifdef __SRV_SMS_DELIVERY_STATUS__
        ||((pos.group >= VAPP_SMS_SETTING_GROUP_SIM_1) && (pos.pos == ITEM_ID_DELIVERY_REPORT))
    #endif //__SRV_SMS_DELIVERY_STATUS__
        )
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}

VcpListMenuCellBaseControl* VappSmsSettingPage::getItemCustomControl(
    VcpMenuPos pos,                                  // [IN] position of the item
    VcpListMenuCellControlLocationTypeEnum location, // [IN] Control location
    VfxFrame *parentFrame                            // [IN] parent frame of the custom content frame
    )
{
    VFX_ASSERT(pos.group <= m_groupNumber);
    VFX_ASSERT(pos.group >= VAPP_SMS_SETTING_GROUP_ALL_SIM);

    VappSmsSettingSwitchCp* ListMenuControl = NULL;

    if (location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
    {
        if ((pos.group == VAPP_SMS_SETTING_GROUP_ALL_SIM) && (pos.pos == ITEM_ID_REPLY_PATH))
        {
            VFX_OBJ_CREATE(ListMenuControl, VappSmsSettingSwitchCp, parentFrame);
            if (!m_isNosimInsert)
            {
                ListMenuControl->setSwitchStatus(m_settings->getReplyPath());
                ListMenuControl->m_signalSwitchChanged.connect(this, &Self::OnRPSwitch);
            }
        }
	#ifdef __SRV_SMS_DELIVERY_STATUS__
        else if ((pos.group >= VAPP_SMS_SETTING_GROUP_SIM_1) && (pos.pos == ITEM_ID_DELIVERY_REPORT))
        {
            if (!m_isNosimInsert)
            {
                VfxS32 simIndex = m_groupToSimIndex[pos.group - VAPP_SMS_SETTING_GROUP_SIM_1];
                srv_sms_sim_enum simId = vapp_sms_sim_index_to_sim_id(simIndex);

                VFX_OBJ_CREATE(m_listMenuControl[simIndex], VappSmsSettingSwitchCp, parentFrame);
                ListMenuControl = m_listMenuControl[simIndex];
                ListMenuControl->setSwitchStatus(m_settings->getDeliveryReport(simId));
                ListMenuControl->m_signalSwitchChanged.connect(this, &Self::OnSRSwitch);
                ListMenuControl->m_signalSwitchUnmovable.connect(this, &Self::OnSRSwitchUnmovable);
                mmi_sim_enum mmi_sim = vapp_sms_sim_index_to_mmi_sim(simIndex);
                if (!srv_sim_ctrl_is_available(mmi_sim))
                {
                    ListMenuControl->setSwitchMovable(VFX_FALSE);
                }
            }
            else
            {
                VFX_OBJ_CREATE(m_listMenuControl[0], VappSmsSettingSwitchCp, parentFrame);
                ListMenuControl = m_listMenuControl[0];
            }
        }
	#endif //__SRV_SMS_DELIVERY_STATUS__

        if (ListMenuControl)
        {
            ListMenuControl->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_NONE,
                VFX_FRAME_ALIGNER_MODE_NONE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_MID);
        }
    }
    return ListMenuControl;
}

VcpListMenuCellClientBaseFrame* VappSmsSettingPage::getItemCustomContentFrame(VcpMenuPos pos, VfxFrame *parentFrame) 
{
    VcpListMenuCellMultiTextFrame *frame = NULL;

    if ((pos.pos == ITEM_ID_PROFILE_SETTING)
    #ifdef __SMS_OVER_PS_SUPPORT__
        || (pos.pos == ITEM_ID_PREFER_BEARER)
    #endif
	#ifdef __VAPP_SMSPREFER_STORAGE_SETTING__
		|| (pos.pos == ITEM_ID_PREFER_STORAGE)
	#endif
	#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	    || (pos.pos == ITEM_ID_DEFAULT_STORAGE)
	    || (pos.pos == ITEM_ID_MSG_FILTER)
    #endif
        )
    {
        VFX_OBJ_CREATE(frame, VcpListMenuCellMultiTextFrame, parentFrame);
    }

    return frame;
}

VfxBool VappSmsSettingPage::hasGroupHeader(VfxS32 group) const
{

#if (MMI_MAX_SIM_NUM >= 2)
    if (group == VAPP_SMS_SETTING_GROUP_ALL_SIM)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
#else
    return VFX_FALSE;
#endif
}

void VappSmsSettingPage::OnRPSwitch(VfxObject *sw, VfxBool isChecked)
{
    m_settings->setReplyPath(isChecked);
}

#ifdef __SRV_SMS_DELIVERY_STATUS__
void VappSmsSettingPage::OnSRSwitch(VfxObject *sender, VfxBool isChecked)
{
    for (VfxU8 simIndex = 0; simIndex < VAPP_SMS_TOTAL_SIM; simIndex++)
    {
        if (sender == m_listMenuControl[simIndex])
        {
            srv_sms_sim_enum simId = vapp_sms_sim_index_to_sim_id(simIndex);

            m_settings->setDeliveryReport(isChecked, simId);
        }
    }
}
void VappSmsSettingPage::OnSRSwitchUnmovable()
{
    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    balloon->addItem(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_SMS_UNAVAILABLE_SIM));
    return;

}
#endif


void VappSmsSettingPage::onItemTapped(VcpGroupListMenu * sender, VcpMenuPos pos)
{
    if(sender == m_groupListMenu)
    {
        VFX_ASSERT(pos.group <= m_groupNumber);
        VFX_ASSERT(pos.group >= VAPP_SMS_SETTING_GROUP_ALL_SIM);

        if (pos.group == VAPP_SMS_SETTING_GROUP_ALL_SIM)
        {
        #ifdef __SMS_OVER_PS_SUPPORT__
            if (pos.pos == ITEM_ID_PREFER_BEARER)
            {
                VfxU8 bearer;
                m_settings->getPreferBearer(&bearer);
                VFX_OBJ_CREATE_EX(m_bearerPage, VappSmsPreferBearerPage, getMainScr(), (bearer));
                m_bearerPage->m_signalChangedBearer.connect(this, &Self::onChangedBearer);
                getMainScr()->pushPage(VFX_ID_NULL, m_bearerPage);
            }
        #endif
		#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
			else if (pos.pos == ITEM_ID_DEFAULT_STORAGE)
			{
				VappSmsDefaultStoragePage *page = NULL;
                VFX_OBJ_CREATE(page, VappSmsDefaultStoragePage, getMainScr());
				page->m_signalDefaultStorageChanged.connect(this, &VappSmsSettingPage::onDefaultStorageChanged);
                getMainScr()->pushPage(VFX_ID_NULL, page);
			}
			else if (pos.pos == ITEM_ID_MSG_FILTER)
			{
				VappSmsMsgFilterPage *page = NULL;
				VFX_OBJ_CREATE(page, VappSmsMsgFilterPage, getMainScr());
				page->m_signalSmsMsgFilterChanged.connect(this, &VappSmsSettingPage::onSmsMsgFilterChanged);
                getMainScr()->pushPage(VFX_ID_NULL, page);
			}
		#endif /* __MMI_SMS_TCARD_STORAGE_SUPPORT__ */
		
        }
        else
        {
            VfxS32 simIndex = m_groupToSimIndex[pos.group - VAPP_SMS_SETTING_GROUP_SIM_1];
            srv_sms_sim_enum simId = vapp_sms_sim_index_to_sim_id(simIndex);
            mmi_sim_enum mmi_sim = vapp_sms_sim_index_to_mmi_sim(simIndex);
            if (!srv_sim_ctrl_is_available(mmi_sim))
            {
        	#ifdef __SRV_SMS_DELIVERY_STATUS__
                if (pos.pos != ITEM_ID_DELIVERY_REPORT)
                {
    		        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    		        balloon->addItem(MMI_NMGR_BALLOON_TYPE_INFO, VFX_WSTR_RES(STR_ID_VAPP_SMS_UNAVAILABLE_SIM));
                }
			#endif //__SRV_SMS_DELIVERY_STATUS__
                return;
            }
            if (pos.pos == ITEM_ID_PROFILE_SETTING)
            {
                VFX_OBJ_CREATE_EX(m_profilePage, VappSmsProfileListPage, getMainScr(), (simId,  m_profileList[simIndex]));
                m_profilePage->m_signalActiveProfilechanged.connect(this, &Self::onSelectNewItem);
                getMainScr()->pushPage(VFX_ID_NULL, m_profilePage);
            }
            else if (pos.pos == ITEM_ID_VOICEMAIL_SERVER)
            {
                VappVmServerListPage *page;
                VFX_OBJ_CREATE_EX(page, VappVmServerListPage, getMainScr(), (simId));
                getMainScr()->pushPage(VFX_ID_NULL, page);
            }
		#ifdef __VAPP_SMSPREFER_STORAGE_SETTING__
			else if (pos.pos == ITEM_ID_PREFER_STORAGE)
			{
				VfxS32 simIndex = m_groupToSimIndex[pos.group - VAPP_SMS_SETTING_GROUP_SIM_1];
				VFX_OBJ_CREATE_EX(m_selectPage, VappSmsPreferStoragePage, this, (simIndex));
				getMainScr()->pushPage(VFX_ID_NULL, m_selectPage);
			}
	 	#endif
        }
    }
}

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
void VappSmsSettingPage::onDefaultStorageChanged()
{
	VcpMenuPos pos;

    pos.group = VAPP_SMS_SETTING_GROUP_ALL_SIM;
    pos.pos = ITEM_ID_DEFAULT_STORAGE;
	m_groupListMenu->updateItem(pos);

	pos.pos = ITEM_ID_MSG_FILTER;
	m_groupListMenu->updateItem(pos);
}

void VappSmsSettingPage::onSmsMsgFilterChanged()
{
	VcpMenuPos pos;

    pos.group = VAPP_SMS_SETTING_GROUP_ALL_SIM;
    pos.pos = ITEM_ID_MSG_FILTER;
	m_groupListMenu->updateItem(pos);
}

#endif

void VappSmsSettingPage::onSelectNewItem(VfxObject *sender, VfxWString wString, srv_sms_sim_enum simId)
{
    VcpMenuPos pos;

    if (sender == m_profilePage)
    {
        VfxU8 simIndex = vapp_sms_sim_id_to_sim_index(simId);
	for (VfxU8 i = 0; i < m_groupNumber; i++)
	{
            if(m_groupToSimIndex[i] == simIndex)
		{
		    pos.group = VAPP_SMS_SETTING_GROUP_SIM_1 + i;
		    break;
		}
	}     
        pos.pos = ITEM_ID_PROFILE_SETTING;
        m_settings->setActiveProfileName(wString.getBuf(), simId);
        m_groupListMenu->updateItem(pos);
    }
}

#ifdef __SMS_OVER_PS_SUPPORT__
void VappSmsSettingPage::onInitBearerDone(VfxObject *sender, VfxBool result)
{
    VcpMenuPos pos;

    if (result)
    {
        pos.group = VAPP_SMS_SETTING_GROUP_ALL_SIM;
        pos.pos = ITEM_ID_PREFER_BEARER;
        m_groupListMenu->updateItem(pos);
    }

    }



void VappSmsSettingPage::onChangedBearer(VfxObject *sender, VfxU8 index)
{
    VcpMenuPos pos;

    if (sender == m_bearerPage)
    {
        pos.group = VAPP_SMS_SETTING_GROUP_ALL_SIM;
        pos.pos = ITEM_ID_PREFER_BEARER;
        m_settings->setPreferBearer(index);
        m_groupListMenu->updateItem(pos);
        m_bearerPage = NULL;
    }
}
#endif

void VappSmsSettingPage::getGroupNumber()
{
    m_isNosimInsert =  0;
	m_groupNumber = 0;
	for(VfxU8 i = 0; i < VAPP_SMS_TOTAL_SIM; i++)
	{
	    mmi_sim_enum simIndex = vapp_sms_sim_index_to_mmi_sim(i);
		if (srv_sim_ctrl_is_inserted(simIndex))
		{
			m_groupToSimIndex[m_groupNumber++] = i;
		}
	}
    if (m_groupNumber == 0)
    {
        m_isNosimInsert = 1;
        ++m_groupNumber;
    }
}

void VappSmsSettingPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}

/*****************************************************************************
 * Class VappSmsPreferBearerPage Function
 *****************************************************************************/
#ifdef __SMS_OVER_PS_SUPPORT__
//VFX_IMPLEMENT_CLASS("VappSmsPreferBearerPage", VappSmsPreferBearerPage, VfxPage);
void VappSmsPreferBearerPage::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_VAPP_SMS_PREFERED_BEARER);
    setTopBar(bar);

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setPos(0, 0);
	VfxSize parentSize = getSize();
    m_listMenu->setSize(parentSize);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &Self::onBearerItemTapped);
}

void VappSmsPreferBearerPage::onDeinit()
{
    m_listMenu->m_signalItemTapped.disconnect(this, &Self::onBearerItemTapped);

    VFX_OBJ_CLOSE(m_listMenu);

    Super::onDeinit();
}

VfxU32 VappSmsPreferBearerPage::getCount() const
{
    return ITEM_ID_SMS_BRARER_TOTAL;
}

VfxBool VappSmsPreferBearerPage::getItemText(
        VfxU32 index,
        VcpListMenuFieldEnum fieldType,
        VfxWString &text,
        VcpListMenuTextColorEnum &color
        )
{
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
    	mmi_rp_app_vapp_sms_str_enum str[] = 
        {
    			STR_ID_VAPP_SMS_PREFER_GPRS_BEARER,
				STR_ID_VAPP_SMS_PREFER_GSM_BEARER,
				STR_ID_VAPP_SMS_GSM_BEARER
    		};
		text.loadFromRes(str[index]);
    }

    return VFX_TRUE;
}

VcpListMenuItemStateEnum VappSmsPreferBearerPage::getItemState(VfxU32 index) const
{
    if (index == m_curBearer)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }

}

void VappSmsPreferBearerPage::onBearerItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(index < ITEM_ID_SMS_BRARER_TOTAL);

    if (index != m_curBearer)
    {
        m_curBearer = index;

        for (VfxU8 simIndex = 0; simIndex < VAPP_SMS_TOTAL_SIM; simIndex++)
        {
            srv_sms_sim_enum sim_id =  vapp_sms_sim_index_to_sim_id(simIndex);
        
            srv_sms_set_setting_para(
                SRV_SMS_PRE_BEARER,
                &m_curBearer,
                sim_id,
                NULL,
                NULL);
        }

        m_signalChangedBearer.postEmit(this, m_curBearer);
    }

    getMainScr()->popPage();
}

void VappSmsPreferBearerPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}
#endif //__SMS_OVER_PS_SUPPORT__


/*****************************************************************************
 * Class VappSmsProfileListPage Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSmsProfileListPage", VappSmsProfileListPage, VfxPage);
void VappSmsProfileListPage::onInit()
{
    Super::onInit();

    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle((VfxResId)STR_ID_VAPP_SMS_PROFILE_SETTING);
    setTopBar(m_titleBar);

	SmsProfile::SmsProfileInitData data;
	for (int index = 0; index < SRV_SMS_MAX_LFOUR_PROFILES; index++)
	{
    	data.simId = m_simId;
    	data.profileIndex = index;
    	VFX_OBJ_CREATE_EX(m_profile[index], SmsProfile, this, (data));
	}

	VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    VfxSize parentSize = getSize();
    m_listMenu->setSize(parentSize);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_listMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &Self::onProfileListItemTapped);
    m_listMenu->m_signalCmdButtonClicked.connect(this, &Self::onEditButtonClicked);
}

void VappSmsProfileListPage::onDeinit()
{
    Super::onDeinit();
}

VfxU32 VappSmsProfileListPage::getCount() const
{
    return m_profileList->getMaxProfileNum();
}

VfxBool VappSmsProfileListPage::getItemText(VfxU32 index,VcpListMenuFieldEnum fieldType,VfxWString &text, VcpListMenuTextColorEnum &color)
{
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        VFX_ASSERT(index < m_profileList->getMaxProfileNum());

        const VfxWChar *name;
        name = m_profileList->getProfileName(index);

        if (name[0] != '\0')
        {
            text.loadFromMem(name);
        }
        else
        {
            text.loadFromRes(defaultProfileNames[index]);
        }
    }
    return VFX_TRUE;
}

VfxBool VappSmsProfileListPage::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        )
{
    VfxBool result = VFX_FALSE;

    switch (fieldType)
    {
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL:
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT:
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED:
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED:
			image.setResId(IMG_ID_VAPP_SMS_BUTTON_EDIT);
            result = VFX_TRUE;
            break;

        default :
            break;
    }

    return result;
}

VcpListMenuItemStateEnum VappSmsProfileListPage::getItemState(VfxU32 index) const
{
    if (index == m_profileList->getActiveProfileIndex())
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}

void VappSmsProfileListPage::onProfileListItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(index < m_profileList->getMaxProfileNum());

    if (index != m_profileList->getActiveProfileIndex())
    {
        m_profileList->setActiveProfile((VfxU8)index);

        m_signalActiveProfilechanged.postEmit(this, VFX_WSTR_MEM(m_profileList->getProfileName((VfxU8)index)), m_simId);
    }
    getMainScr()->popPage();

}

void VappSmsProfileListPage::onProfleChanged(VfxObject *sender, VfxWString name, VfxU8 index)
{
    m_profileList->setProfileName(name.getBuf(), index);

    m_listMenu->updateItem(index); 

    if (index == m_profileList->getActiveProfileIndex())
    {
        m_signalActiveProfilechanged.postEmit(this, VFX_WSTR_MEM(m_profileList->getProfileName((VfxU8)index)), m_simId);
    }
}

void VappSmsProfileListPage::onEditButtonClicked(VcpListMenu *Sender, VfxU32 index)
{
    VappSmsProfileEditPage *page;
    VappSmsProfileEditPage::VappSmsProfileEditInitData data;
    data.simId = m_simId;
    data.profileIndex = index;
    data.profileNameLen = m_profileList->getMaxNameLen();
    VFX_OBJ_CREATE_EX(page, VappSmsProfileEditPage, getMainScr(), (data, m_profile[index]));
    page->m_signalProfileChanged.connect(this, &Self::onProfleChanged);
    getMainScr()->pushPage(VFX_ID_NULL, page);
}

void VappSmsProfileListPage::onLoadPrfoleListDone(VfxBool result)
{
    if (result)
    {
        m_listMenu->resetAllItems();
    }

    }

void VappSmsProfileListPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}

/*****************************************************************************
 * Class VappSmsProfileEditPage Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSmsProfileEditPage", VappSmsProfileEditPage, VfxPage);
VappSmsProfileEditPage::VappSmsProfileEditPage():
    m_form(NULL),
    m_toolBar(NULL),
    m_profile(NULL),
    m_simId(SRV_SMS_SIM_1),
    m_profleIndex(0),
    m_profileNameLen(0)
{
}

VappSmsProfileEditPage::VappSmsProfileEditPage(VappSmsProfileEditInitData data, SmsProfile *profile):
    m_form(NULL),
    m_toolBar(NULL),
    m_profile(profile),
    m_simId(data.simId),
    m_profleIndex(data.profileIndex),
    m_profileNameLen(data.profileNameLen)
{
}

void VappSmsProfileEditPage::onInit()
{
    Super::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_VAPP_SMS_EDIT_PROFILE);
    setTopBar(bar);

    updateView();
}


void VappSmsProfileEditPage::onToolbarTapped(VfxObject *sender, VfxId id)
{
    if (m_toolBar == sender)
    {
        if (id == ITEM_ID_TOOLBAR_SAVE)
        {
            onBarSaveCommond();
        }
        else if (id == ITEM_ID_TOOLBAR_CANCLE)
        {
            getMainScr()->popPage();
        }
    }
}



void VappSmsProfileEditPage::onProfileItemTapped(VfxId id)
{
    onSetTextEditorState(ITEM_ID_PROFILE_NAME, VFX_FALSE);
    onSetTextEditorState(ITEM_ID_PROFILE_SC, VFX_FALSE);
#ifdef __MMI_SMS_VALIDITY_PERIOD_SUPPOTR__
    if (id == ITEM_ID_VALIDITY_PERIOD)
    {
        VappSmsVpSelectPage::VappSmsVpSelectInitData data;
        data.simId = m_simId;
        data.curVp = m_profile->getValidityPeriod();

        VappSmsVpSelectPage *page;
        VFX_OBJ_CREATE_EX(page, VappSmsVpSelectPage, getMainScr(), (data));
        page->m_signalSelectNewItem.connect(this, &Self::onVpChanged);
        getMainScr()->pushPage(VFX_ID_NULL, page);
    }
#endif
#ifdef __MMI_SMS_MESSAGE_TYPE_SUPPORT__

    else if (id == ITEM_ID_MESSAGE_TYPE)
    {
        VappSmsTypeSelectPage::VappSmsTypeSelectInitData data;
        data.simId = m_simId;
        data.curType = m_profile->getMsgType();

        VappSmsTypeSelectPage *page;
        VFX_OBJ_CREATE_EX(page, VappSmsTypeSelectPage, getMainScr(), (data));
        page->m_signalSelectNewItem.connect(this, &Self::onMsgTypeChanged);
        getMainScr()->pushPage(VFX_ID_NULL, page);
    }
#endif
}


#ifdef __MMI_SMS_VALIDITY_PERIOD_SUPPOTR__

void VappSmsProfileEditPage::onVpChanged(VfxObject *sender, VfxS32 value)
{
    m_profile->setValidityPeriod(value);

    VcpFormItemBigArrowButton *validityPeriod;
    validityPeriod = (VcpFormItemBigArrowButton*)m_form->getItem(ITEM_ID_VALIDITY_PERIOD);
    VfxU16 strId = 0;
    switch(value)
    {
        case SRV_SMS_VP_1_HR:
            strId = STR_ID_VAPP_SMS_VP_1HOUR;
            break;
        case SRV_SMS_VP_6_HR:
            strId = STR_ID_VAPP_SMS_VP_6HOUR;
            break;
        case SRV_SMS_VP_12_HR:
            strId = STR_ID_VAPP_SMS_VP_12HOUR;
            break;
        case SRV_SMS_VP_24_HR:
            strId = STR_ID_VAPP_SMS_VP_1DAY;
            break;
        case SRV_SMS_VP_72_HR:
            strId = STR_ID_VAPP_SMS_VP_3DAY;
            break;
        case SRV_SMS_VP_1_WEEK:
            strId = STR_ID_VAPP_SMS_VP_1WEEK;
            break;
        case SRV_SMS_VP_MAX:
        default:
            strId = STR_GLOBAL_MAXIMUM;
            break;
    }
    validityPeriod->setHintText((VfxResId)strId);
}
#endif

#ifdef __MMI_SMS_MESSAGE_TYPE_SUPPORT__

void VappSmsProfileEditPage::onMsgTypeChanged(VfxObject *sender, VfxS32 value)
{
    m_profile->setMsgType(value);

    VcpFormItemBigArrowButton *messageType;
    messageType = (VcpFormItemBigArrowButton*)m_form->getItem(ITEM_ID_MESSAGE_TYPE);
    VfxU16 typeStrId = 0;
    switch(value)
    {
        case SMSAL_PAGING_PID:
            typeStrId = STR_ID_VAPP_SMS_TYPE_PAGE;
            break;
        case SMSAL_EMAIL_PID:
            typeStrId = STR_GLOBAL_EMAIL;
            break;
        case SMSAL_DEFAULT_PID:
            typeStrId = STR_GLOBAL_TEXT;
            break;
        case SMSAL_G3_FAX_PID:
            typeStrId = STR_ID_VAPP_SMS_TYPE_FAX;
            break;
        case SMSAL_G4_FAX_PID:
            typeStrId = STR_ID_VAPP_SMS_TYPE_GROUP4_FAX;
            break;
        case SRV_SMS_VP_1_WEEK:
            typeStrId = STR_ID_VAPP_SMS_VP_1WEEK;
            break;

        default:
            break;
    }
    messageType->setHintText((VfxResId)typeStrId);
}
#endif


void VappSmsProfileEditPage::updateView()
    {
        VFX_OBJ_CREATE(m_form, VcpForm, this);

    	VfxSize parentSize = getSize();
        m_form->setSize(parentSize);
        m_form->setAlignParent(
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE,
            VFX_FRAME_ALIGNER_MODE_SIDE);

        VcpFunctionBar *functionBar;
        VFX_OBJ_CREATE(functionBar, VcpFunctionBar, this);
        functionBar->addItem((VfxResId)STR_ID_VAPP_SMS_VK_PREV, (VfxId)ITEM_ID_FUNCBAR_PREV);
        functionBar->addItem((VfxResId)STR_ID_VAPP_SMS_VK_NEXT, (VfxId)ITEM_ID_FUNCBAR_NEXT);
        functionBar->addItem((VfxResId)STR_GLOBAL_SAVE, (VfxId)ITEM_ID_FUNCBAR_SAVE);
        functionBar->setItemSpecial(ITEM_ID_FUNCBAR_SAVE);
        functionBar->m_signalButtonTap.connect(this, &Self::onFunctionBarClicked);

        VcpFormItemTextInput *profileName;
        VFX_OBJ_CREATE(profileName, VcpFormItemTextInput, m_form);
        profileName->setLabelText((VfxResId)STR_ID_VAPP_SMS_PROFILE_NAME);
        profileName->setLabelPosition(VCPFORM_TOP_LEFT);
        const VfxWChar *name = m_profile->getProfileName();
        VcpTextEditor * nameEditor = profileName->getTextBox();
        if (name[0] != '\0')
        {
            nameEditor->setText(
                name,
                m_profileNameLen,
                VFX_FALSE,
                VCP_TEXT_ENCODING_GSM,
                NULL);
        }
        else
        {
            nameEditor->setText(
                VFX_WSTR_EMPTY,
                m_profileNameLen,
                VFX_FALSE,
                VCP_TEXT_ENCODING_GSM,
                NULL);
        }
        nameEditor->setIME(INPUT_TYPE_USE_ENCODING_BASED_LENGTH | INPUT_TYPE_ONE_LESS_CHARACTER | IMM_INPUT_TYPE_SENTENCE | INPUT_TYPE_GSM_EXTENDED_HANDLING);
        nameEditor->setFunctionBar((VfxFrame*)functionBar, VFX_TRUE);
        nameEditor->m_signalActivated.connect(this, &Self::onTextActivated);
        nameEditor->setId(ITEM_ID_PROFILE_EDITOR_NAME);
        m_form->addItem(profileName, ITEM_ID_PROFILE_NAME);

        VcpFormItemTextInput *scAddress;
        VFX_OBJ_CREATE(scAddress, VcpFormItemTextInput, m_form);
        scAddress->setLabelText((VfxResId)STR_ID_VAPP_SMS_PROFILE_SC);
        scAddress->setLabelPosition(VCPFORM_TOP_LEFT);
        const VfxWChar *number = m_profile->getScAddress();
        VcpTextEditor * numberEditor = scAddress->getTextBox();
        if (number[0] != '\0')
        {
            numberEditor->setText(
                number,
                SRV_SMS_MAX_ADDR_LEN-1,
                VFX_FALSE);
        }
        else
        {
            numberEditor->setText(
                VFX_WSTR_EMPTY,
                SRV_SMS_MAX_ADDR_LEN-1,
                VFX_FALSE);
        }
        numberEditor->setIME(IMM_INPUT_TYPE_SIM_NUMERIC, IME_PLUS_CHAR_HANDLING);
        numberEditor->setFunctionBar((VfxFrame*)functionBar, VFX_TRUE);
        numberEditor->m_signalActivated.connect(this, &Self::onTextActivated);
        numberEditor->setId(ITEM_ID_PROFILE_EDITOR_SC);
        m_form->addItem(scAddress, ITEM_ID_PROFILE_SC);

		
        mmi_sim_enum sim = vapp_sms_sim_id_to_mmi_sim(m_simId);
	#ifdef __MMI_SMS_VALIDITY_PERIOD_SUPPOTR__
        VcpFormItemBigArrowButton *validityPeriod;
        VFX_OBJ_CREATE(validityPeriod, VcpFormItemBigArrowButton, m_form);
        validityPeriod->setButtonText((VfxResId)STR_ID_VAPP_SMS_PROFILE_VP);
        if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_TELESERVICES, SRV_CPHS_SERVICE_VALIDITY_PERIOD, sim))
        {
            validityPeriod->setIsDisabled(MMI_TRUE);
        }
        VfxU16 strId = 0;
        switch(m_profile->getValidityPeriod())
        {
            case SRV_SMS_VP_1_HR:
                strId = STR_ID_VAPP_SMS_VP_1HOUR;
                break;
            case SRV_SMS_VP_6_HR:
                strId = STR_ID_VAPP_SMS_VP_6HOUR;
                break;
            case SRV_SMS_VP_12_HR:
                strId = STR_ID_VAPP_SMS_VP_12HOUR;
                break;
            case SRV_SMS_VP_24_HR:
                strId = STR_ID_VAPP_SMS_VP_1DAY;
                break;
            case SRV_SMS_VP_72_HR:
                strId = STR_ID_VAPP_SMS_VP_3DAY;
                break;
            case SRV_SMS_VP_1_WEEK:
                strId = STR_ID_VAPP_SMS_VP_1WEEK;
                break;
            case SRV_SMS_VP_MAX:
            default:
                strId = STR_GLOBAL_MAXIMUM;
                break;
        }
        validityPeriod->setHintText((VfxResId)(strId));
        validityPeriod->m_signalButtonClick.connect(this, &Self::onProfileItemTapped);
        m_form->addItem(validityPeriod, ITEM_ID_VALIDITY_PERIOD);
	#endif
	#ifdef __MMI_SMS_MESSAGE_TYPE_SUPPORT__
        VcpFormItemBigArrowButton *messageType;
        VFX_OBJ_CREATE(messageType, VcpFormItemBigArrowButton, m_form);
        messageType->setButtonText((VfxResId)(STR_ID_VAPP_SMS_PROFILE_MSG_TYPE));
        if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_TELESERVICES, SRV_CPHS_SERVICE_PROTOLCOL_ID, sim))
        {
            messageType->setIsDisabled(MMI_TRUE);
        }
        VfxU16 typeStrId = 0;
        switch(m_profile->getMsgType())
        {
            case SMSAL_PAGING_PID:
                typeStrId = STR_ID_VAPP_SMS_TYPE_PAGE;
                break;
            case SMSAL_EMAIL_PID:
                typeStrId = STR_GLOBAL_EMAIL;
                break;
            case SMSAL_DEFAULT_PID:
                typeStrId = STR_GLOBAL_TEXT;
                break;
            case SMSAL_G3_FAX_PID:
                typeStrId = STR_ID_VAPP_SMS_TYPE_FAX;
                break;
            case SMSAL_G4_FAX_PID:
                typeStrId = STR_ID_VAPP_SMS_TYPE_GROUP4_FAX;
                break;
            case SRV_SMS_VP_1_WEEK:
                typeStrId = STR_ID_VAPP_SMS_VP_1WEEK;
                break;

            default:
                typeStrId = STR_GLOBAL_TEXT;
                break;
        }
        messageType->setHintText((VfxResId)typeStrId);
        messageType->m_signalButtonClick.connect(this, &Self::onProfileItemTapped);
        m_form->addItem(messageType, ITEM_ID_MESSAGE_TYPE);
	#endif
        VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
        m_toolBar->addItem(
            ITEM_ID_TOOLBAR_SAVE,
            (VfxResId)STR_GLOBAL_SAVE,
            VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
        m_toolBar->addItem(
            ITEM_ID_TOOLBAR_CANCLE,
            (VfxResId)STR_GLOBAL_CANCEL,
            VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
        m_toolBar->m_signalButtonTap.connect(this, &Self::onToolbarTapped);
        setBottomBar(m_toolBar);

}
void VappSmsProfileEditPage::onFunctionBarClicked(VfxObject *sender, VfxId id)
{
    switch (id)
    {
        case ITEM_ID_FUNCBAR_PREV:
            onSetTextEditorState(ITEM_ID_PROFILE_NAME, VFX_TRUE);
            break;

        case ITEM_ID_FUNCBAR_NEXT:
            onSetTextEditorState(ITEM_ID_PROFILE_SC, VFX_TRUE);
            break;

        case ITEM_ID_FUNCBAR_SAVE:
            onSetTextEditorState(ITEM_ID_PROFILE_NAME, VFX_FALSE);
            onSetTextEditorState(ITEM_ID_PROFILE_SC, VFX_FALSE);
            onBarSaveCommond();
            break;

        default:
            break;
    }
}

void VappSmsProfileEditPage::onBarSaveCommond()
{
    VcpFormItemTextInput *profileName = (VcpFormItemTextInput*)m_form->getItem(ITEM_ID_PROFILE_NAME);
    VcpFormItemTextInput *profileNumber = (VcpFormItemTextInput*)m_form->getItem(ITEM_ID_PROFILE_SC);
    const VfxWChar *name = profileName->getText().getBuf();
    const VfxWChar *number = profileNumber->getText().getBuf();

    if (number[0] == '\0')
    {
        profileNumber->setWarningText((VfxResId)STR_GLOBAL_NO_NUMBER);
    }
    else if (!srv_sms_check_ucs2_number((CHAR*)number))
    {
        profileNumber->setWarningText((VfxResId)STR_GLOBAL_INVALID_NUMBER);
    }
    else
    {
        m_profile->setProfileName(name);
        m_profile->setScAddress(number);
        m_profile->saveProfile();
        
        m_signalProfileChanged.postEmit(this, profileName->getText(), m_profleIndex);
        
        getMainScr()->popPage();
    }
}

void VappSmsProfileEditPage::onSetTextEditorState(VfxId id,VfxBool activated)
{
    VcpTextEditor *textEdit;
    VcpFormItemTextInput *textInput = NULL;
    textInput = (VcpFormItemTextInput *)m_form->getItem(id);
    if (textInput)
    {
        textEdit = textInput->getTextBox();

        if (activated)
        {
            textEdit->activate();
        }
        else
        {
            textEdit->deactivate();
        }
    }
}

void VappSmsProfileEditPage::onTextActivated(VcpTextEditor *sender, VfxBool  activated)
{
    VfxId currId = sender->getId();
    VcpFunctionBar *functionBar = (VcpFunctionBar *)sender->getFunctionBar();

    if (activated)
    {
        if (currId == ITEM_ID_PROFILE_EDITOR_NAME)
        {
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_PREV, VFX_TRUE);
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_NEXT, VFX_FALSE);
        } 
        else if (currId == ITEM_ID_PROFILE_EDITOR_SC)
        {
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_PREV, VFX_FALSE);
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_NEXT, VFX_TRUE);
        }
        else
        {
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_PREV, VFX_TRUE);
            functionBar->setDisableItem(ITEM_ID_FUNCBAR_NEXT, VFX_TRUE);
        }
    }
}

void VappSmsProfileEditPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}

/*****************************************************************************
 * Class VappSmsVpSelectPage Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSmsVpSelectPage", VappSmsVpSelectPage, VfxPage);
#ifdef __MMI_SMS_VALIDITY_PERIOD_SUPPOTR__

void VappSmsVpSelectPage::onInit()
{
    Super::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_VAPP_SMS_PROFILE_VP);
    setTopBar(bar);

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setPos(0, 0);
    VfxSize parentSize = getSize();
    m_listMenu->setSize(parentSize);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &Self::onVpItemTapped);
}

void VappSmsVpSelectPage::onDeinit()
{
    m_listMenu->m_signalItemTapped.disconnect(this, &Self::onVpItemTapped);

    VFX_OBJ_CLOSE(m_listMenu);

    Super::onDeinit();
}

VfxU32 VappSmsVpSelectPage::getCount() const
{
    return ITEM_ID_SMS_VP_TOTAL;
}

VfxBool VappSmsVpSelectPage::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color
    )
{
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
    	VfxId str[] = 
        {
    			STR_ID_VAPP_SMS_VP_1HOUR,
				STR_ID_VAPP_SMS_VP_6HOUR,
				STR_ID_VAPP_SMS_VP_12HOUR,
				STR_ID_VAPP_SMS_VP_1DAY,
				STR_ID_VAPP_SMS_VP_3DAY,
				STR_ID_VAPP_SMS_VP_1WEEK,
				STR_GLOBAL_MAXIMUM
    		};
		text.loadFromRes(str[index]);

    }

    return VFX_TRUE;
}


VcpListMenuItemStateEnum VappSmsVpSelectPage::getItemState(VfxU32 index) const
{
    VfxU32 vpIdex;

    switch (m_curVp)
    {
        case SRV_SMS_VP_1_HR:
            vpIdex = 0;
            break;
        case SRV_SMS_VP_6_HR:
            vpIdex = 1;
            break;
        case SRV_SMS_VP_12_HR:
            vpIdex = 2;
            break;
        case SRV_SMS_VP_24_HR:
            vpIdex = 3;
            break;
        case SRV_SMS_VP_72_HR:
            vpIdex = 4;
            break;                
        case SRV_SMS_VP_1_WEEK:
            vpIdex = 5;
            break;
        case SRV_SMS_VP_MAX:
        default:
            vpIdex = 6;
            break;
    }

    if (index == vpIdex)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}


void VappSmsVpSelectPage::onVpItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(index < ITEM_ID_SMS_VP_TOTAL);

    VfxS32 vp;
	srv_sms_vp_enum vp_enum[] = 
    {
			SRV_SMS_VP_1_HR,
			SRV_SMS_VP_6_HR,
			SRV_SMS_VP_12_HR,
			SRV_SMS_VP_24_HR,
			SRV_SMS_VP_72_HR,
			SRV_SMS_VP_1_WEEK,
			SRV_SMS_VP_MAX
		};
	vp = vp_enum[index];
	

    if (vp != m_curVp)
    {
        m_signalSelectNewItem.postEmit(sender, vp);
    }

    getMainScr()->popPage();
}

void VappSmsVpSelectPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}
#endif
/*****************************************************************************
 * Class VappSmsTypeSelectPage Function
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSmsTypeSelectPage", VappSmsTypeSelectPage, VfxPage);

#ifdef __MMI_SMS_MESSAGE_TYPE_SUPPORT__

void VappSmsTypeSelectPage::onInit()
{
    Super::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_VAPP_SMS_PROFILE_MSG_TYPE);
    setTopBar(bar);

    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setPos(0, 0);
    VfxSize parentSize = getSize();
    m_listMenu->setSize(parentSize);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &Self::onSmsTypeItemTapped);
}

void VappSmsTypeSelectPage::onDeinit()
{
    m_listMenu->m_signalItemTapped.disconnect(this, &Self::onSmsTypeItemTapped);

    VFX_OBJ_CLOSE(m_listMenu);

    Super::onDeinit();
}

VfxU32 VappSmsTypeSelectPage::getCount() const
{
    return ITEM_ID_SMS_PID_TOTAL;
}

VfxBool VappSmsTypeSelectPage::getItemText(
    VfxU32 index,
    VcpListMenuFieldEnum fieldType,
    VfxWString &text,
    VcpListMenuTextColorEnum &color
    )
{
    if(fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        switch(index)
        {
            case ITEM_ID_SMS_PID_PAGING:
                text.loadFromRes(STR_ID_VAPP_SMS_TYPE_PAGE);
                break;
            case ITEM_ID_SMS_PID_EMAIL:
                text.loadFromRes(STR_GLOBAL_EMAIL);
                break;
            case ITEM_ID_SMS_PID_DEFAULT:
                text.loadFromRes(STR_GLOBAL_TEXT);
                break;
            case ITEM_ID_SMS_PID_FAX_GP3:
                text.loadFromRes(STR_ID_VAPP_SMS_TYPE_FAX);
                break;
            case ITEM_ID_SMS_PID_FAX_GP4:
                text.loadFromRes(STR_ID_VAPP_SMS_TYPE_GROUP4_FAX);
                break;

            default:
                break;
        }
    }
    return VFX_TRUE;

}

VfxBool VappSmsTypeSelectPage::getItemIsDisabled(VfxU32 index) const
{
    VfxBool hideMenu = MMI_FALSE;

    if (index == ITEM_ID_SMS_PID_PAGING)
    {
        mmi_sim_enum sim = vapp_sms_sim_id_to_mmi_sim(m_simId);

        if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_SM_MO_PAGING, sim))
        {
            hideMenu = MMI_TRUE;
        }
    }
    else if (index == ITEM_ID_SMS_PID_EMAIL)
    {
        mmi_sim_enum sim = vapp_sms_sim_id_to_mmi_sim(m_simId);

        if (!srv_cphs_is_service_available(SRV_CPHS_GROUP_VALUE_ADDED_SERVICES, SRV_CPHS_SERVICE_SM_MO_EMAIL, sim))
        {
            hideMenu = MMI_TRUE;
        }
    }

    return hideMenu;
}


VcpListMenuItemStateEnum VappSmsTypeSelectPage::getItemState(VfxU32 index) const
{
    VfxU32 pidIdex;

    switch (m_curType)
    {
        case SMSAL_PAGING_PID:
            pidIdex = ITEM_ID_SMS_PID_PAGING;
            break;
        case SMSAL_EMAIL_PID:
            pidIdex = ITEM_ID_SMS_PID_EMAIL;
            break;
        case SMSAL_DEFAULT_PID:
            pidIdex = ITEM_ID_SMS_PID_DEFAULT;
            break;
        case SMSAL_G3_FAX_PID:
            pidIdex = ITEM_ID_SMS_PID_FAX_GP3;
            break;
        case SMSAL_G4_FAX_PID:
            pidIdex = ITEM_ID_SMS_PID_FAX_GP4;
            break;

        default:
            pidIdex = ITEM_ID_SMS_PID_DEFAULT;
            break;
    }

    if (index == pidIdex)
    {
        return VCP_LIST_MENU_ITEM_STATE_SELECTED;
    }
    else
    {
        return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
    }
}


void VappSmsTypeSelectPage::onSmsTypeItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(index < ITEM_ID_SMS_PID_TOTAL);
    VfxS32 msgType;
    switch (index)
    {
        case ITEM_ID_SMS_PID_PAGING:
            msgType = SMSAL_PAGING_PID;
            break;
        case ITEM_ID_SMS_PID_EMAIL:
            msgType = SMSAL_EMAIL_PID;
            break;
        case ITEM_ID_SMS_PID_DEFAULT:
            msgType = SMSAL_DEFAULT_PID;
            break;
        case ITEM_ID_SMS_PID_FAX_GP3:
            msgType = SMSAL_G3_FAX_PID;
            break;
        case ITEM_ID_SMS_PID_FAX_GP4:
            msgType = SMSAL_G4_FAX_PID;
            break;                

        default:
            msgType = SMSAL_DEFAULT_PID;
            break;
    }

    if (msgType != m_curType)
    {
        m_signalSelectNewItem.postEmit(sender, msgType);
    }

    getMainScr()->popPage();
}

void VappSmsTypeSelectPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}

#endif
#ifdef __VAPP_SMSPREFER_STORAGE_SETTING__
VappSmsPreferStoragePage::VappSmsPreferStoragePage(VfxS32 simindex)
	:m_isMePreferStorage(VFX_TRUE), m_listMenu(NULL), m_simIndex(simindex)
{}

void VappSmsPreferStoragePage::onInit()
{
    VfxPage::onInit();

    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_VAPP_SMS_PREFER_STORAGE);
    setTopBar(bar);


	
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setPos(0, 0);
    VfxSize parentSize = getSize();
    m_listMenu->setSize(parentSize);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &VappSmsPreferStoragePage::onItemTapped);

	srv_sms_sim_enum simId = vapp_sms_sim_index_to_sim_id(m_simIndex);

	srv_sms_get_setting_para(
		SRV_SMS_PRE_STORAGE, 
		NULL, 
		simId, 
		&VappSmsPreferStoragePage::onPreferStorageInitDone, 
		getObjHandle());
}

void VappSmsPreferStoragePage::onPreferStorageInitDone(srv_sms_callback_struct *callbackData)
{
	VappSmsPreferStoragePage *page = (VappSmsPreferStoragePage *)VfxObject::handleToObject(callbackData->user_data);
	if (page == NULL)
		return;
	if (callbackData->result == MMI_TRUE)
	{
		VfxU8 *value = (VfxU8*)callbackData->action_data;
		srv_sms_storage_enum preferStorage = (srv_sms_storage_enum)*value;
		if (preferStorage == SRV_SMS_STORAGE_SIM)
		{
			page->m_preferStorage = SRV_SMS_STORAGE_SIM;
		}
		else
		{
			page->m_preferStorage = SRV_SMS_STORAGE_ME;
		}
	}
	page->m_listMenu->updateAllItems();

}

VfxU32 VappSmsPreferStoragePage::getCount() const
{
	return VAPP_PRESTO_ID_MAX;
}
VfxBool VappSmsPreferStoragePage::getItemText(
	 VfxU32 index,
	 VcpListMenuFieldEnum fieldType,
	 VfxWString &text,
	 VcpListMenuTextColorEnum &color
	 )
{
	switch (index)
	{
		case VAPP_PRESTO_ID_ME:
			text.loadFromRes(STR_ID_VAPP_SMS_PREFER_STORAGE_ME);
			break;
		case VAPP_PRESTO_ID_SIM:
			text.loadFromRes(STR_ID_VAPP_SMS_PREFER_STORAGE_SIM);
			break;
		default:
			text.loadFromRes(STR_ID_VAPP_SMS_PREFER_STORAGE_ME);
			break;

	}
	return VFX_TRUE;
}
VcpListMenuItemStateEnum VappSmsPreferStoragePage::getItemState(VfxU32 index) const
{
	switch (index)
	{
		case VAPP_PRESTO_ID_ME:		
			return m_preferStorage == SRV_SMS_STORAGE_ME ? VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
			
		case VAPP_PRESTO_ID_SIM:
			return m_preferStorage == SRV_SMS_STORAGE_ME ? VCP_LIST_MENU_ITEM_STATE_UNSELECTED : VCP_LIST_MENU_ITEM_STATE_SELECTED;
			
		default:
			return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	}
}

void VappSmsPreferStoragePage::onItemTapped(VcpListMenu *sender, VfxU32 index)
{
	
	switch (index)
	{
		case VAPP_PRESTO_ID_ME:
			m_preferStorage = SRV_SMS_STORAGE_ME;
			break;
			
		case VAPP_PRESTO_ID_SIM:
			m_preferStorage = SRV_SMS_STORAGE_SIM;
			break;
		default:
			m_preferStorage = SRV_SMS_STORAGE_ME;
			break;
	}

	srv_sms_sim_enum simId = vapp_sms_sim_index_to_sim_id(m_simIndex);
	
	srv_sms_set_setting_para(
        SRV_SMS_PRE_STORAGE, 
        (void *)&m_preferStorage, 
        simId, 
        NULL, 
        NULL);
	getMainScr()->popPage();
}
void VappSmsPreferStoragePage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}
#endif

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
VappSmsDefaultStoragePage::VappSmsDefaultStoragePage() :
	m_listMenu(NULL)
{

}


void VappSmsDefaultStoragePage::onInit()
{
    VfxPage::onInit();

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappSmsDefaultStoragePage::onTcardPlugInOutProc,
        getObjHandle());  

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappSmsDefaultStoragePage::onTcardPlugInOutProc,
        getObjHandle());

    mmi_frm_cb_reg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappSmsDefaultStoragePage::onTcardPlugInOutProc,
        getObjHandle());  

    mmi_frm_cb_reg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappSmsDefaultStoragePage::onTcardPlugInOutProc,
        getObjHandle()); 


	
    VcpTitleBar *bar;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_SMS_DEFAULT_STORAGE);
    setTopBar(bar);


	
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setPos(0, 0);
    VfxSize parentSize = getSize();
    m_listMenu->setSize(parentSize);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemTapped.connect(this, &VappSmsDefaultStoragePage::onItemTapped);

}


void VappSmsDefaultStoragePage::onDeinit()
{
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappSmsDefaultStoragePage::onTcardPlugInOutProc,
        getObjHandle());  

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappSmsDefaultStoragePage::onTcardPlugInOutProc,
        getObjHandle()); 

    mmi_frm_cb_dereg_event(
        EVT_ID_USB_ENTER_MS_MODE,
        VappSmsDefaultStoragePage::onTcardPlugInOutProc,
        getObjHandle());  

    mmi_frm_cb_dereg_event(
        EVT_ID_USB_EXIT_MS_MODE,
        VappSmsDefaultStoragePage::onTcardPlugInOutProc,
        getObjHandle()); 
	VfxPage::onDeinit();
}

VfxU32 VappSmsDefaultStoragePage::getCount() const
{
	return ITEM_ID_MAX;
}

VfxBool VappSmsDefaultStoragePage::getItemText(
	 VfxU32 index,
	 VcpListMenuFieldEnum fieldType,
	 VfxWString &text,
	 VcpListMenuTextColorEnum &color
	 )
{
	STR_GLOBAL_LIST_ENUM str[] = 
	{
			STR_GLOBAL_PHONE,
			STR_GLOBAL_MEMORY_CARD	
		};
	text.loadFromRes(str[index]);

	return VFX_TRUE;
}
VcpListMenuItemStateEnum VappSmsDefaultStoragePage::getItemState(VfxU32 index) const
{
	VcpListMenuItemStateEnum state = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
	srv_sms_storage_enum storage = srv_sms_get_prefer_storage(SRV_SMS_SIM_1);
	
	switch (index)
	{
		case ITEM_ID_PHONE:
		{
			if (storage == SRV_SMS_STORAGE_ME)
			{
				state = VCP_LIST_MENU_ITEM_STATE_SELECTED;
			}
			break;
		}
		case ITEM_ID_TCARD:
		{
			if (storage == SRV_SMS_STORAGE_TCARD)
			{
				state = VCP_LIST_MENU_ITEM_STATE_SELECTED;
			}
			break;
		}
		default:
		{
			break;
		} 
	}
	return state;
}

VfxBool VappSmsDefaultStoragePage::getItemIsDisabled(VfxU32 index) const
{
	VfxBool isDisabled = VFX_FALSE;
	VfxBool isMemoryCardAvailable = srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE));
	switch (index)
	{

		case ITEM_ID_TCARD:
		{
			if (isMemoryCardAvailable == VFX_FALSE)
			{
				isDisabled = VFX_TRUE;
			}
			break;
		}

		default:
		{
			break;
		}

	}
	return isDisabled;
}

void VappSmsDefaultStoragePage::onItemTapped(VcpListMenu *sender, VfxU32 index)
{
	srv_sms_storage_enum storage = SRV_SMS_STORAGE_ME;
	srv_sms_filter_enum filter = srv_sms_get_storage_filter();
	switch(index)
	{
		case ITEM_ID_PHONE:
		{
			storage = SRV_SMS_STORAGE_ME;
			filter = (srv_sms_filter_enum)(filter | SRV_SMS_FILTER_ME);
			break;
		}
		case ITEM_ID_TCARD:
		{
			storage = SRV_SMS_STORAGE_TCARD;
			filter = (srv_sms_filter_enum)(filter | SRV_SMS_FILTER_TCARD);
			break;
		}
		default:
		{
			break;
		} 
	}
	for (VfxS32 index = 0; index < MMI_MAX_SIM_NUM; index++)
	{
		srv_sms_sim_enum simId = vapp_sms_sim_index_to_sim_id(index);
		srv_sms_set_prefer_storage(storage, simId);
	}
	srv_sms_set_storage_filter(filter);
	m_signalDefaultStorageChanged.postEmit();
	
    srv_um_refresh_ind_struct *refresh_ind;

    refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));
    refresh_ind->msg_type = SRV_UM_MSG_SMS;
    refresh_ind->msg_box_type = SRV_UM_MSG_BOX_ALL;
    refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;
    VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);
	
	getMainScr()->popPage();
	
}

mmi_ret VappSmsDefaultStoragePage::onTcardPlugInOutProc(mmi_event_struct *evt)
{
    VappSmsDefaultStoragePage *page = (VappSmsDefaultStoragePage *)handleToObject((VfxObjHandle)evt->user_data);

	if (page)
	{
	    switch (evt->evt_id)
	    { 
		    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
		    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
			case EVT_ID_USB_ENTER_MS_MODE:
			case EVT_ID_USB_EXIT_MS_MODE:
		    {
				page->m_listMenu->updateItem(ITEM_ID_TCARD);
				break;
			}
			default:
			{
				break;
			}
				
		}
	}
	return MMI_RET_OK;
}

void VappSmsDefaultStoragePage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}

////////////////////////////////////////////////////////
VappSmsMsgFilterPage::VappSmsMsgFilterPage() :
	m_listMenu(NULL), m_toolBar(NULL)
{
	srv_sms_filter_enum filter = srv_sms_get_storage_filter();
	
	if (filter & SRV_SMS_FILTER_ME)
	{
		m_isItemSelected[ITEM_ID_PHONE] = VFX_TRUE;
	}
	else
	{
		m_isItemSelected[ITEM_ID_PHONE] = VFX_FALSE;
	}

	if (filter & SRV_SMS_FILTER_TCARD)
	{
		m_isItemSelected[ITEM_ID_TCARD] = VFX_TRUE;
	}
	else
	{
		m_isItemSelected[ITEM_ID_TCARD] = VFX_FALSE;
	}

	srv_sms_storage_enum storage = srv_sms_get_prefer_storage(SRV_SMS_SIM_1);
	if (storage == SRV_SMS_STORAGE_ME)
	{
		m_isItemSelected[ITEM_ID_PHONE] = VFX_TRUE;
	}
	if (storage == SRV_SMS_STORAGE_TCARD)
	{
		m_isItemSelected[ITEM_ID_TCARD] = VFX_TRUE;
	}

}


void VappSmsMsgFilterPage::onInit()
{
    VfxPage::onInit();

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappSmsMsgFilterPage::onTcardPlugInOutProc,
        getObjHandle());  

    mmi_frm_cb_reg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappSmsMsgFilterPage::onTcardPlugInOutProc,
        getObjHandle());  

    VcpTitleBar *bar = NULL;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle((VfxResId)STR_ID_SMS_MSG_FILTER);
    setTopBar(bar);


    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    m_toolBar->addItem(
        ITEM_ID_TOOLBAR_OK,
        (VfxResId)STR_GLOBAL_OK,
        VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem(
        ITEM_ID_TOOLBAR_CANCEL,
        (VfxResId)STR_GLOBAL_CANCEL,
        VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);
    m_toolBar->m_signalButtonTap.connect(this, &VappSmsMsgFilterPage::onToolbarTapped);
    setBottomBar(m_toolBar);
	
    VFX_OBJ_CREATE(m_listMenu, VcpListMenu, this);
    m_listMenu->setPos(0, 0);
    VfxSize parentSize = getSize();
    m_listMenu->setSize(parentSize);
    m_listMenu->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_listMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_listMenu->setMenuMode(VCP_LIST_MENU_MODE_MULTI_SELECTION, VFX_FALSE);
    m_listMenu->setContentProvider(this);
    m_listMenu->m_signalItemSelectionStateChanged.connect(this, &VappSmsMsgFilterPage::onItemStateChanged);

}

void VappSmsMsgFilterPage::onDeinit()
{
    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT,
        VappSmsMsgFilterPage::onTcardPlugInOutProc,
        getObjHandle());  

    mmi_frm_cb_dereg_event(
        EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN,
        VappSmsMsgFilterPage::onTcardPlugInOutProc,
        getObjHandle()); 
	VfxPage::onDeinit();
}

void VappSmsMsgFilterPage::onItemStateChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
	if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
	{
		m_isItemSelected[index] = VFX_TRUE;
	}
	else
	{
		m_isItemSelected[index] = VFX_FALSE;
	}

}

VfxU32 VappSmsMsgFilterPage::getCount() const
{
	return ITEM_ID_MAX;
}

VfxBool VappSmsMsgFilterPage::getItemText(
	 VfxU32 index,
	 VcpListMenuFieldEnum fieldType,
	 VfxWString &text,
	 VcpListMenuTextColorEnum &color
	 )
{
	STR_GLOBAL_LIST_ENUM str[] = 
	{
			STR_GLOBAL_PHONE,
			STR_GLOBAL_MEMORY_CARD	
		};
	text.loadFromRes(str[index]);

	return VFX_TRUE;
}

VfxBool VappSmsMsgFilterPage::getItemIsDisabled(VfxU32 index) const
{
	VfxBool isDisabled = VFX_FALSE;
	VfxBool isMemoryCardAvailable = srv_fmgr_drv_is_accessible(srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE));
	srv_sms_storage_enum storage = srv_sms_get_prefer_storage(SRV_SMS_SIM_1);
	switch (index)
	{
		case ITEM_ID_PHONE:
		{
			if (storage == SRV_SMS_STORAGE_ME)
			{
				isDisabled = VFX_TRUE;
			}
			break;
		}
		case ITEM_ID_TCARD:
		{
			if ((storage == SRV_SMS_STORAGE_TCARD) || (isMemoryCardAvailable == VFX_FALSE))
			{
				isDisabled = VFX_TRUE;
			}
			break;
		}

		default:
		{
			break;
		}

	}
	return isDisabled;
}

VcpListMenuItemStateEnum VappSmsMsgFilterPage::getItemState(VfxU32 index) const
{
	VcpListMenuItemStateEnum state = VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
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
#endif
	if (m_isItemSelected[index] == VFX_TRUE)
	{
		state = VCP_LIST_MENU_ITEM_STATE_SELECTED;
	}
		
	return state;
}


void VappSmsMsgFilterPage::onQueryRotateEx(VfxScreenRotateParam &param)
{
}

void VappSmsMsgFilterPage::onToolbarTapped(VfxObject *sender, VfxId id)
{
	srv_sms_filter_enum filter = SRV_SMS_FILTER_SIM;
	switch (id)
	{
		case ITEM_ID_TOOLBAR_OK:
		{
			VfxS32 index = 0;
			for(index = 0; index < ITEM_ID_MAX; index++)
			{
				if (m_isItemSelected[index] == VFX_FALSE)
				{
					break;
				}		
			}
			if (index == ITEM_ID_MAX)
			{
				filter = SRV_SMS_FILTER_ALL;
			}
			else if (m_isItemSelected[ITEM_ID_PHONE])
			{
				filter = (srv_sms_filter_enum)(filter | SRV_SMS_FILTER_ME);				  
			}
			else if (m_isItemSelected[ITEM_ID_TCARD])
			{
				filter = (srv_sms_filter_enum)(filter | SRV_SMS_FILTER_TCARD);
			}
			
			srv_sms_set_storage_filter(filter);

			break;
		}

		default:
		{
			break;
		} 
	}
    srv_um_refresh_ind_struct *refresh_ind;

    refresh_ind = (srv_um_refresh_ind_struct*)OslConstructDataPtr(sizeof(srv_um_refresh_ind_struct));
    refresh_ind->msg_type = SRV_UM_MSG_SMS;
    refresh_ind->msg_box_type = SRV_UM_MSG_BOX_ALL;
    refresh_ind->refresh_type = SRV_UM_REFRESH_NONE;
    VAPP_SMS_SEND_ILM(MOD_MMI, MSG_ID_MMI_UM_REFRESH_IND, refresh_ind);

	m_signalSmsMsgFilterChanged.postEmit();
	getMainScr()->popPage();
}

mmi_ret VappSmsMsgFilterPage::onTcardPlugInOutProc(mmi_event_struct *evt)
{
    VappSmsMsgFilterPage *page = (VappSmsMsgFilterPage *)handleToObject((VfxObjHandle)evt->user_data);

	if (page)
	{
	    switch (evt->evt_id)
	    { 
		    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
		    case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
		    {
				page->m_listMenu->updateItem(ITEM_ID_TCARD);
				break;
			}
			default:
			{
				break;
			}
				
		}
	}
	return MMI_RET_OK;
}

#endif

