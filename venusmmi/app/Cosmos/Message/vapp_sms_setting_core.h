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
 *  vapp_sms_setting_core.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#ifndef __VAPP_SMS_SETTING_CORE_H__
#define __VAPP_SMS_SETTING_CORE_H__
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vapp_sms_util.h"
#include "vapp_msg_features.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
    #include "SmssrvGprot.h"
#ifdef __cplusplus
}
#endif

#define VAPP_SMS_MAX_LFOUR_PROFILES    (4)

/***************************************************************************** 
 * Class 
 *****************************************************************************/

/***************************************************************************** 
 * Class SmsSetting
 *****************************************************************************/
class SmsSetting: public VfxObject
{
    //VFX_DECLARE_CLASS(SmsSetting);
public:
    SmsSetting(){};
    const VfxWChar *getActiveProfileName(srv_sms_sim_enum sim_id = SRV_SMS_SIM_1);
    VfxBool setActiveProfileName(const VfxWChar* name, srv_sms_sim_enum sim_id);
#ifdef __SRV_SMS_DELIVERY_STATUS__
    VfxBool getDeliveryReport(srv_sms_sim_enum sim_id = SRV_SMS_SIM_1);
    VfxBool setDeliveryReport(VfxBool set, srv_sms_sim_enum sim_id = SRV_SMS_SIM_1);
#endif
    VfxBool getReplyPath();
    VfxBool setReplyPath(VfxBool set);
    VfxU8 getActiveProfileIndex(srv_sms_sim_enum sim_id = SRV_SMS_SIM_1);
#ifdef __SMS_OVER_PS_SUPPORT__
    VfxBool getPreferBearer(VfxU8 *bearer);
    VfxBool setPreferBearer(VfxU8 value);
#endif

#ifdef __MMI_SMS_TCARD_STORAGE_SUPPORT__
	srv_sms_storage_enum getDefaultStorage(srv_sms_sim_enum sim_id);
	srv_sms_filter_enum getSmsMsgFilter();
#endif


protected:
    virtual void onInit();

private:
#ifdef __SMS_OVER_PS_SUPPORT__
    static void onBearerInitDone(srv_sms_callback_struct *callbackData);
#endif

public:
    VfxSignal2<VfxObject*, VfxBool> m_signalBearerInitDone;

private:
    VfxBool m_bearerInitDone;
    VfxWChar m_profileName[VAPP_SMS_TOTAL_SIM][SRV_SMS_MAX_PROFILE_NAME_LEN + 1];
#ifdef __SRV_SMS_DELIVERY_STATUS__
    VfxBool m_deliveryReport[VAPP_SMS_TOTAL_SIM];
#endif
    VfxBool m_replyPath;
	VfxBool m_replyPathSet;
    VfxU8 m_preferCon;
};


/***************************************************************************** 
 * Class SmsProfileList
 *****************************************************************************/
class SmsProfileList: public VfxObject
{
//VFX_DECLARE_CLASS(SmsProfileList);

typedef SmsProfileList  Self;

public:
    SmsProfileList(srv_sms_sim_enum simId = SRV_SMS_SIM_1): 
		m_simId(simId),m_maxProfileNum(0){};
    VfxU8 getActiveProfileIndex();
    VfxU8 getMaxProfileNum();
    const VfxWChar *getProfileName(VfxU8 index);
    VfxU8 getMaxNameLen();
    VfxBool setProfileName(const VfxWChar* profileName, VfxU8 index);
    VfxBool setActiveProfile(VfxU8 index);


protected:
    virtual void onInit();

private:
    static void onInitDone(srv_sms_callback_struct *callbackData);

public:
    VfxSignal1<VfxBool> m_signalInitDone;

private:
    VfxBool m_initDone;
    srv_sms_sim_enum m_simId;
    VfxU8 m_activeProfileIndex;
    VfxU8 m_maxProfileNum;
    VfxWChar m_profileName[SRV_SMS_MAX_LFOUR_PROFILES][SRV_SMS_MAX_PROFILE_NAME_LEN + 1];
    VfxU8 m_profileNameLen;
};


/***************************************************************************** 
 * Class SmsProfile
 *****************************************************************************/
class SmsProfile: public VfxObject
{
//VFX_DECLARE_CLASS(SmsProfile);

typedef SmsProfile  Self;

public:
    typedef struct
    {
        srv_sms_sim_enum simId;
        VfxU8 profileIndex;
    }SmsProfileInitData;

public:
    SmsProfile(){}
    SmsProfile(SmsProfileInitData data): m_profileIndex(data.profileIndex), m_simId(data.simId){}
    const VfxWChar *getProfileName();
    const VfxWChar *getScAddress();
#ifdef __MMI_SMS_VALIDITY_PERIOD_SUPPOTR__

    VfxS32 getValidityPeriod();
    VfxBool setValidityPeriod(VfxS32 vp);
#endif
#ifdef __MMI_SMS_MESSAGE_TYPE_SUPPORT__

    VfxS32 getMsgType();
    VfxBool setMsgType(VfxS32 smsType);
#endif
    VfxBool setProfileName(const VfxWChar* profileName);
    VfxBool setScAddress(const VfxWChar* scAddress);

    VfxBool saveProfile();

private:
    static void onInitDone(srv_sms_callback_struct *callbackData);

protected:
    virtual void onInit();

public:
    VfxSignal1<VfxBool> m_signalInitDone;

private:
    VfxBool m_initDone;
    VfxU8 m_profileIndex;
    srv_sms_sim_enum m_simId;
    VfxU16 m_profileName[SRV_SMS_MAX_PROFILE_NAME_LEN + 1];
    VfxU16 m_scAddress[SRV_SMS_MAX_ADDR_LEN + 1];
    VfxU8 m_profileNameDcs;
    VfxS32 m_vp;
    VfxS32 m_msgType;
};


#endif /* __VAPP_SMS_SETTING_CORE_H__ */
