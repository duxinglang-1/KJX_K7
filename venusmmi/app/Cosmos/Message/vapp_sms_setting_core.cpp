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
 *  vapp_sms_setting_content.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#include "vapp_sms_setting_core.h"
#include "vapp_sms_util.h"
#include "vapp_msg_features.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmsSrvGprot.h"
    #include "PhbSrvGprot.h"
    #include "mmi_frm_nvram_gprot.h"
	#include "mmi_rp_srv_sms_def.h"
	#include "SimCtrlSrvGprot.h"
#ifdef __cplusplus
}
#endif

static VfxWeakPtr <SmsSetting> settingPtr = NULL;


/***************************************************************************** 
 * Class 
 *****************************************************************************/

 /***************************************************************************** 
  * Class SmsSetting
  *****************************************************************************/
//VFX_IMPLEMENT_CLASS("SmsSetting", SmsSetting, VfxObject);

void SmsSetting::onInit()
{
	m_replyPathSet = VFX_FALSE;
    for (VfxU8 simIndex = 0; simIndex < VAPP_SMS_TOTAL_SIM; simIndex++)
    {
        srv_sms_sim_enum sim_id =  vapp_sms_sim_index_to_sim_id(simIndex);
		mmi_sim_enum mmi_sim = vapp_sms_sim_index_to_mmi_sim(simIndex);
        const srv_sms_setting_struct *settings;
        settings = srv_sms_get_default_setting(sim_id);
		VfxBool isSimAvailable = (srv_sim_ctrl_is_available(mmi_sim)? VFX_TRUE: VFX_FALSE);
		if (isSimAvailable && (m_replyPathSet == VFX_FALSE))
        {
			m_replyPathSet = VFX_TRUE;
            m_replyPath = (settings->reply_path? VFX_TRUE: VFX_FALSE);
        }
	#ifdef __SRV_SMS_DELIVERY_STATUS__
        m_deliveryReport[simIndex] = (settings->status_report? VFX_TRUE: VFX_FALSE);
	#endif //__SRV_SMS_DELIVERY_STATUS__

        memcpy(m_profileName[simIndex], settings->profile_name, (SRV_SMS_MAX_PROFILE_NAME_LEN + 1)*ENCODING_LENGTH);
    }

	settingPtr = this;

#ifdef __SMS_OVER_PS_SUPPORT__
    m_bearerInitDone = VFX_FALSE;

    srv_sms_get_setting_para(
        SRV_SMS_PRE_BEARER,
        NULL,
        SRV_SMS_SIM_1,
        &SmsSetting::onBearerInitDone,
        this);
#endif
}

#ifdef __SMS_OVER_PS_SUPPORT__
void SmsSetting::onBearerInitDone(srv_sms_callback_struct *callbackData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SmsSetting *myObject =  (SmsSetting *) callbackData->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (settingPtr.isValid())
    {
        if (callbackData->result == MMI_TRUE)
        {
            VfxU8 *value = (VfxU8*)callbackData->action_data;
            settingPtr->m_preferCon = *value;
            settingPtr->m_bearerInitDone = VFX_TRUE;
            settingPtr->m_signalBearerInitDone.emit(myObject, (VfxBool)callbackData->result);
        }
    }

    settingPtr = NULL;
}
#endif /*__SMS_OVER_PS_SUPPORT__*/

const VfxWChar* SmsSetting::getActiveProfileName(srv_sms_sim_enum sim_id)
{
    VfxU8 index = vapp_sms_sim_id_to_sim_index(sim_id);

    return m_profileName[index];
}

VfxBool SmsSetting::setActiveProfileName(const VfxWChar* name, srv_sms_sim_enum sim_id)
{
    VfxU8 index = vapp_sms_sim_id_to_sim_index(sim_id);

    memcpy(m_profileName[index], name, (SRV_SMS_MAX_PROFILE_NAME_LEN + 1)*ENCODING_LENGTH);

    return VFX_TRUE;
}
#ifdef __SRV_SMS_DELIVERY_STATUS__
VfxBool SmsSetting::getDeliveryReport(srv_sms_sim_enum sim_id)
{
    VfxU8 simIndex = vapp_sms_sim_id_to_sim_index(sim_id);

    return m_deliveryReport[simIndex];
}
VfxBool SmsSetting::setDeliveryReport(VfxBool set, srv_sms_sim_enum sim_id)
{
    VfxU8 set_data[2];
    VfxU8 simIndex = vapp_sms_sim_id_to_sim_index(sim_id);

    m_deliveryReport[simIndex] = set;
    set_data[0] = m_deliveryReport[simIndex];
    set_data[1] = m_replyPath;

    srv_sms_set_setting_para(SRV_SMS_COMMON_SETTINGS,
                             set_data,
                             sim_id,
                             NULL,
                             NULL);

    return VFX_TRUE;
}
#endif //__SRV_SMS_DELIVERY_STATUS__

VfxBool SmsSetting::getReplyPath()
{
    return m_replyPath;
}

VfxBool SmsSetting::setReplyPath(VfxBool set)
{
    VfxU8 set_data[2];
    srv_sms_sim_enum sim_id;

    m_replyPath = set;

    set_data[1] = m_replyPath;

    for (VfxU8 simIndex = 0; simIndex < VAPP_SMS_TOTAL_SIM; simIndex++)
    {
        sim_id =  vapp_sms_sim_index_to_sim_id(simIndex);
	#ifdef __SRV_SMS_DELIVERY_STATUS__
        set_data[0] = m_deliveryReport[simIndex];
	#else
		set_data[0] = 0;
	#endif
        srv_sms_set_setting_para(SRV_SMS_COMMON_SETTINGS,
                                set_data,
                                sim_id,
                                NULL,
                                NULL);
    }

    return VFX_TRUE;
}

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
srv_sms_storage_enum SmsSetting::getDefaultStorage(srv_sms_sim_enum sim_id)
{
	return srv_sms_get_prefer_storage(sim_id);
}

srv_sms_filter_enum SmsSetting::getSmsMsgFilter()
{
	return srv_sms_get_storage_filter();
}
#endif
VfxU8 SmsSetting::getActiveProfileIndex(srv_sms_sim_enum sim_id)
{
    U8 active_profile_index = 0;
    S16 error_code = 0;
	mmi_rp_srv_sms_mmi_cache_enum sms_cache_arry[] = 
		{
			NVRAM_SMS_ACTIVE_PROFILE_INDEX,
#if (MMI_MAX_SIM_NUM >= 2)
			NVRAM_SIM2_ACTIVE_PROFILE_IDX,
		#if (MMI_MAX_SIM_NUM >= 3)
			NVRAM_SIM3_ACTIVE_PROFILE_IDX,
		#if (MMI_MAX_SIM_NUM >= 4)
			NVRAM_SIM4_ACTIVE_PROFILE_IDX
		#endif
#endif
#endif
		};
	VfxU8 sim_index = vapp_sms_sim_id_to_sim_index(sim_id);
	mmi_rp_srv_sms_mmi_cache_enum sms_cache_index = sms_cache_arry[sim_index];

    ReadValue(sms_cache_index, &active_profile_index, DS_BYTE, &error_code);

        if (active_profile_index >= VAPP_SMS_MAX_LFOUR_PROFILES)
        {
            active_profile_index = 0;
        WriteValue(sms_cache_index, &(active_profile_index), DS_BYTE, &error_code);
        }
    return (VfxU8)active_profile_index;
}

#ifdef __SMS_OVER_PS_SUPPORT__
VfxBool SmsSetting::getPreferBearer(VfxU8 *bearer)
{
    if (m_bearerInitDone)
    {
        *bearer = m_preferCon;
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxBool SmsSetting::setPreferBearer(VfxU8 value)
{
    m_preferCon = value;
    return VFX_TRUE;
}
#endif

/***************************************************************************** 
 * Class SmsProfileList
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("SmsProfileList", SmsProfileList, VfxObject);

void SmsProfileList::onInit()
{
    m_initDone = VFX_FALSE;


    memset((U8*)m_profileName, 0, (SRV_SMS_MAX_PROFILE_NAME_LEN + 1)*(SRV_SMS_MAX_LFOUR_PROFILES)*ENCODING_LENGTH);

    srv_sms_get_setting_para(
        SRV_SMS_GET_PROFILE_LIST,
        NULL,
        m_simId,
        &Self::onInitDone,
        getObjHandle());
}


void SmsProfileList::onInitDone(srv_sms_callback_struct *callbackData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //SmsProfileList *myObject =  (SmsProfileList *) callbackData->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SmsProfileList *profileList = (SmsProfileList*)VfxObject::handleToObject((VfxObjHandle)callbackData->user_data);
    if (profileList)
    {
        if (callbackData->result == MMI_TRUE)
        {
            //SmsProfileList *myObject = (SmsProfileList*)profileListPtr;
            srv_sms_profile_list_struct *data = (srv_sms_profile_list_struct*)callbackData->action_data;
            profileList->m_activeProfileIndex = data->cur_req_profile_no;
            profileList->m_maxProfileNum = data->cur_max_ps_profiles;
            memcpy(profileList->m_profileName, data->profile_name, (SRV_SMS_MAX_PROFILE_NAME_LEN + 1)*(SRV_SMS_MAX_LFOUR_PROFILES)*ENCODING_LENGTH);
            profileList->m_profileNameLen = data->profile_name_len;
            profileList->m_initDone = VFX_TRUE;
            profileList->m_signalInitDone.emit(callbackData->result? VFX_TRUE: VFX_FALSE);
        }
    }
}


VfxU8 SmsProfileList::getActiveProfileIndex()
{
    return m_activeProfileIndex;
}


VfxU8 SmsProfileList::getMaxProfileNum()
{
    return m_maxProfileNum;
}


const VfxWChar* SmsProfileList::getProfileName(VfxU8 index)
{
    return m_profileName[index];
}

VfxU8 SmsProfileList::getMaxNameLen()
{
    if (m_profileNameLen < SRV_SMS_MAX_PROFILE_NAME_LEN)
    {
        return m_profileNameLen;
    }
    else
    {
        return SRV_SMS_MAX_PROFILE_NAME_LEN;
    }
}

VfxBool SmsProfileList::setProfileName(const VfxWChar* profileName, VfxU8 index)
{
    memcpy(m_profileName[index], profileName, (SRV_SMS_MAX_PROFILE_NAME_LEN + 1)*ENCODING_LENGTH);

    return VFX_TRUE;
}

VfxBool SmsProfileList::setActiveProfile(VfxU8 index)
{
    m_activeProfileIndex = index;
    srv_sms_set_setting_para(
        SRV_SMS_SET_ACTIVE_PROFILE,
        &index,
        m_simId,
        NULL,
        NULL);

    return VFX_TRUE;
}

/***************************************************************************** 
 * Class SmsProfile
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("SmsProfile", SmsProfile, VfxObject);

void SmsProfile::onInit()
{
    m_initDone = VFX_FALSE;
    srv_sms_get_setting_para(
        SRV_SMS_PROFILE_DETAIL,
        &m_profileIndex,
        m_simId,
        &Self::onInitDone,
        getObjHandle());
}


void SmsProfile::onInitDone(srv_sms_callback_struct *callbackData)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //SmsProfile *myObject =  (SmsProfile *) callbackData->user_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SmsProfile *profile = (SmsProfile*)VfxObject::handleToObject((VfxObjHandle)callbackData->user_data);
    if (profile)
    {
        if (callbackData->result == MMI_TRUE)
        {
            srv_sms_profile_struct *data = (srv_sms_profile_struct*)callbackData->action_data;
            memcpy(profile->m_profileName, data->profile_name, (SRV_SMS_MAX_PROFILE_NAME_LEN + 1)*ENCODING_LENGTH);
            memcpy(profile->m_scAddress, data->sc_addr, (SRV_SMS_MAX_ADDR_LEN + 1)*ENCODING_LENGTH);
            profile->m_profileNameDcs = data->profile_name_dcs;
            profile->m_vp = data->vp_index;
            profile->m_msgType = data->msg_type_index;

            profile->m_initDone = VFX_TRUE;
            profile->m_signalInitDone.emit(callbackData->result? VFX_TRUE: VFX_FALSE);
        }

    }
}

const VfxWChar* SmsProfile::getProfileName()
{
    return m_profileName;
}

const VfxWChar* SmsProfile::getScAddress()
{
    return m_scAddress;
}


VfxBool SmsProfile::setProfileName(const VfxWChar* profileName)
{
    memcpy(m_profileName, profileName, (SRV_SMS_MAX_PROFILE_NAME_LEN + 1)*ENCODING_LENGTH);

    if (srv_phb_check_ucs2_character((U16*)m_profileName))
    {
        m_profileNameDcs = PHB_UCS2;
    }
    else
    {
        m_profileNameDcs = PHB_ASCII;
    }

    return VFX_TRUE;
}

VfxBool SmsProfile::setScAddress(const VfxWChar* scAddress)
{
    memcpy(m_scAddress, scAddress, (SRV_SMS_MAX_ADDR_LEN + 1)*ENCODING_LENGTH);

    return VFX_TRUE;
}

#ifdef __MMI_SMS_VALIDITY_PERIOD_SUPPOTR__

VfxS32 SmsProfile::getValidityPeriod()
{
    return m_vp;
}

VfxBool SmsProfile::setValidityPeriod(VfxS32 vp)
{
    m_vp = vp;
    return VFX_TRUE;
}
#endif

#ifdef __MMI_SMS_MESSAGE_TYPE_SUPPORT__


VfxS32 SmsProfile::getMsgType()
{
    return m_msgType;
}


VfxBool SmsProfile::setMsgType(VfxS32 smsType)
{
    m_msgType = smsType;
    return VFX_TRUE;
}
#endif
VfxBool SmsProfile::saveProfile()
{
    srv_sms_profile_struct data;
    data.vp_index = m_vp;
    data.msg_type_index = m_msgType;
    memcpy(data.profile_name, m_profileName, (SRV_SMS_MAX_PROFILE_NAME_LEN + 1)*ENCODING_LENGTH);
    data.profile_name_dcs = m_profileNameDcs;
    data.profile_index = m_profileIndex;
    memcpy(data.sc_addr, m_scAddress,  (SRV_SMS_MAX_ADDR_LEN + 1)*ENCODING_LENGTH);

    srv_sms_set_setting_para(
        SRV_SMS_PROFILE_DETAIL,
        &data,
        m_simId,
        NULL,
        NULL);

    return VFX_TRUE;
}


