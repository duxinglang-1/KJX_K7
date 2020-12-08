/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#include "MMI_include.h"
#include "vapp_camco_express_setting_mgr.h"

#ifdef __VAPP_CAMCO_EXPRESS__

#include "mmi_rp_vapp_camco_def.h"

void CamcoSettingMgr::getSeetingLog(vapp_camco_setting_enum s, VfxU32 v)
{
    switch (s)
    {
        case VAPP_CAMCO_SETTING_CAMSCENEMODE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_CAMSCENEMODE, v);
            break;
        case VAPP_CAMCO_SETTING_CAPSIZE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_CAPSIZE, v);
            break;
        case VAPP_CAMCO_SETTING_FLASH:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_FLASH, v);
            break;
        case VAPP_CAMCO_SETTING_SELFTIMER:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_SELFTIMER, v);
            break;
        case VAPP_CAMCO_SETTING_ISO:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_ISO, v);
            break;
        case VAPP_CAMCO_SETTING_WB:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_WB, v);
            break;
        case VAPP_CAMCO_SETTING_EFFECT:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_EFFECT, v);
            break;
        case VAPP_CAMCO_SETTING_CAMSTORAGE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_CAMSTORAGE, v);
            break;
        case VAPP_CAMCO_SETTING_VDOSTORAGE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_VDOSTORAGE, v);
            break;
        case VAPP_CAMCO_SETTING_CAPQTY:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_CAPQTY, v);
            break;
        case VAPP_CAMCO_SETTING_VDOSCENEMODE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_VDOSCENEMODE, v);
            break;
        case VAPP_CAMCO_SETTING_RECSIZE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_RECSIZE, v);
            break;
        case VAPP_CAMCO_SETTING_TIMELAPSE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_TIME_LAPSE, v);
            break;
        case VAPP_CAMCO_SETTING_TIMELAPSEPERIOD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_TIME_LAPSE_PERIOD, v);
            break;
        case VAPP_CAMCO_SETTING_LIMIT:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_LIMIT, v);
            break;
        case VAPP_CAMCO_SETTING_VISQTY:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_VISQTY, v);
            break;
        case VAPP_CAMCO_SETTING_VISCODEC:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_VISCODEC, v);
            break;
        case VAPP_CAMCO_SETTING_CAMEV:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_CAMEV, v);
            break;
        case VAPP_CAMCO_SETTING_VDOEV:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_VDOEV, v);
            break;
        case VAPP_CAMCO_SETTING_CAMZOOM:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_CAMZOOM, v);
            break;
        case VAPP_CAMCO_SETTING_VDOZOOM:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_VDOZOOM, v);
            break;
        case VAPP_CAMCO_SETTING_SD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_SD, v);
            break;
        case VAPP_CAMCO_SETTING_ASD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_ASD, v);
            break;
        case VAPP_CAMCO_SETTING_ZSD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_ZSD, v);
            break;
        case VAPP_CAMCO_SETTING_ACT_APP:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_ACT_APP, v);
            break;
        case VAPP_CAMCO_SETTING_ACT_CAM:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE_ACT_CAM, v);
            break;
        default:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_GET_VALUE, s, v);
            break;
    }
}

void CamcoSettingMgr::setSeetingLog(vapp_camco_setting_enum s, VfxU32 v)
{
    switch (s)
    {
        case VAPP_CAMCO_SETTING_CAMSCENEMODE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_CAMSCENEMODE, v);
            break;
        case VAPP_CAMCO_SETTING_CAPSIZE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_CAPSIZE, v);
            break;
        case VAPP_CAMCO_SETTING_FLASH:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_FLASH, v);
            break;
        case VAPP_CAMCO_SETTING_SELFTIMER:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_SELFTIMER, v);
            break;
        case VAPP_CAMCO_SETTING_ISO:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_ISO, v);
            break;
        case VAPP_CAMCO_SETTING_WB:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_WB, v);
            break;
        case VAPP_CAMCO_SETTING_EFFECT:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_EFFECT, v);
            break;
        case VAPP_CAMCO_SETTING_CAMSTORAGE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_CAMSTORAGE, v);
            break;
        case VAPP_CAMCO_SETTING_VDOSTORAGE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_VDOSTORAGE, v);
            break;
        case VAPP_CAMCO_SETTING_CAPQTY:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_CAPQTY, v);
            break;
        case VAPP_CAMCO_SETTING_VDOSCENEMODE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_VDOSCENEMODE, v);
            break;
        case VAPP_CAMCO_SETTING_RECSIZE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_RECSIZE, v);
            break;
        case VAPP_CAMCO_SETTING_TIMELAPSE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_TIME_LAPSE, v);
            break;
        case VAPP_CAMCO_SETTING_TIMELAPSEPERIOD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_TIME_LAPSE_PERIOD, v);
            break;
        case VAPP_CAMCO_SETTING_LIMIT:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_LIMIT, v);
            break;
        case VAPP_CAMCO_SETTING_VISQTY:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_VISQTY, v);
            break;
        case VAPP_CAMCO_SETTING_VISCODEC:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_VISCODEC, v);
            break;
        case VAPP_CAMCO_SETTING_CAMEV:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_CAMEV, v);
            break;
        case VAPP_CAMCO_SETTING_VDOEV:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_VDOEV, v);
            break;
        case VAPP_CAMCO_SETTING_CAMZOOM:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_CAMZOOM, v);
            break;
        case VAPP_CAMCO_SETTING_VDOZOOM:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_VDOZOOM, v);
            break;
        case VAPP_CAMCO_SETTING_SD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_SD, v);
            break;
        case VAPP_CAMCO_SETTING_ASD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_ASD, v);
            break;
        case VAPP_CAMCO_SETTING_ZSD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_ZSD, v);
            break;
        case VAPP_CAMCO_SETTING_ACT_APP:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_ACT_APP, v);
            break;
        case VAPP_CAMCO_SETTING_ACT_CAM:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_ACT_CAM, v);
            break;
        default:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE, s, v);
    }
}

void CamcoSettingMgr::onInit(void)
{
    VfxObject :: onInit();

    setIsExtSetting(VFX_FALSE);

    m_ListCreated = VFX_FALSE;
    m_mainCount = 0;
    m_ActiveSetting = NULL;
    for(VfxU16 i = 0; i < VAPP_CAMCO_SETTING_END; i++)
    {
        m_mainList[i] = NULL;
    }
    m_itemCount = 0;
    for(VfxU16 i = 0; i < VAPP_CAMCO_MAX_SETTING_ITEM_COUNT; i++)
    {
        m_itemList[i] = NULL;
    }

    VFX_OBJ_CREATE(m_CamSCN, CamSceneModeSetting ,this);
    VFX_OBJ_CREATE(m_RecSCN, VdoSceneModeSetting ,this);
    VFX_OBJ_CREATE(m_CapSize, CapSizeSetting ,this);
    VFX_OBJ_CREATE(m_Flash, FlashSetting ,this);
    VFX_OBJ_CREATE(m_SelfTimer, SelfTimerSetting ,this);
    VFX_OBJ_CREATE(m_ISO, ISOSetting ,this);
    VFX_OBJ_CREATE(m_WB, WBSetting ,this);
    VFX_OBJ_CREATE(m_Effect, EffectSetting ,this);
    VFX_OBJ_CREATE(m_CamStorage, StorageSetting ,this);
    VFX_OBJ_CREATE(m_RecStorage, StorageSetting ,this);
    VFX_OBJ_CREATE(m_CapQty, CapqtySetting ,this);
    VFX_OBJ_CREATE(m_RecSize, RecSizeSetting ,this);
    VFX_OBJ_CREATE(m_TimeLapse, TimeLapseSetting ,this);
    VFX_OBJ_CREATE(m_TimeLapsePeriod, TimeLapsePeriodSetting ,this);
    VFX_OBJ_CREATE(m_RecLimit, LimitSetting ,this);
    VFX_OBJ_CREATE(m_RecQty, VisQtySetting ,this);
    VFX_OBJ_CREATE(m_RecCodec, VisCodecSetting ,this);
    VFX_OBJ_CREATE(m_CapEV, CamEVSetting ,this);
    VFX_OBJ_CREATE(m_RecEV, VdoEVSetting ,this);
    VFX_OBJ_CREATE(m_CapZoom, CamZoomSetting ,this);
    VFX_OBJ_CREATE(m_RecZoom, VdoZoomSetting ,this);
    VFX_OBJ_CREATE(m_SmileDetect, SmileDetectSetting ,this);
    VFX_OBJ_CREATE(m_SceneDetect, SceneDetectSetting ,this);
    VFX_OBJ_CREATE(m_ZeroDelay, ZeroDelaySetting ,this);
    VFX_OBJ_CREATE(m_Application, ApplicationSetting ,this);
    VFX_OBJ_CREATE(m_CamearaSensor, CameraSensorSetting ,this);

    m_allSettingList[0] = m_CamSCN;
    m_allSettingList[1] = m_RecSCN;
    m_allSettingList[2] = m_CapSize;
    m_allSettingList[3] = m_Flash;
    m_allSettingList[4] = m_SelfTimer;
    m_allSettingList[5] = m_ISO;
    m_allSettingList[6] = m_WB;
    m_allSettingList[7] = m_Effect;
    m_allSettingList[8] = m_CamStorage;
    m_allSettingList[9] = m_RecStorage;
    m_allSettingList[10] = m_CapQty;
    m_allSettingList[11] = m_RecSize;
    m_allSettingList[12] = m_TimeLapse;
    m_allSettingList[13] = m_TimeLapsePeriod;
    m_allSettingList[14] = m_RecLimit;
    m_allSettingList[15] = m_RecQty;
    m_allSettingList[16] = m_RecCodec;
    m_allSettingList[17] = m_CapEV;
    m_allSettingList[18] = m_RecEV;
    m_allSettingList[19] = m_CapZoom;
    m_allSettingList[20] = m_RecZoom;
    m_allSettingList[21] = m_SmileDetect;
    m_allSettingList[22] = m_SceneDetect;
    m_allSettingList[23] = m_ZeroDelay;
    m_allSettingList[24] = m_Application;
    m_allSettingList[25] = m_CamearaSensor;

    m_allSettingCount = 26;

    m_Application->setMgr(this);
    m_CamearaSensor->setMgr(this);
    for(VfxU32 i = 0; i < m_allSettingCount; i++)
    {
        m_allSettingList[i]->setMgr(this);
    }

    // init all settings
    m_Application->initialize();
    m_CamearaSensor->initialize();
    for(VfxU32 i = 0; i < m_allSettingCount; i++)
    {
        m_allSettingList[i]->initialize();
    }
    m_CamStorage->setType(VAPP_CAMCO_SETTING_CAMSTORAGE);
    m_RecStorage->setType(VAPP_CAMCO_SETTING_VDOSTORAGE);

    // read setting value frme
    m_isReadNvramData = VFX_TRUE;
    loadSetting();
    m_isReadNvramData = VFX_FALSE;

    // set default all settings
    m_Application->setDefault();
    m_CamearaSensor->setDefault();
    for(VfxU32 i = 0; i < m_allSettingCount; i++)
    {
        m_allSettingList[i]->setDefault();
    }

    // conect all relation between settings
    m_CamearaSensor->m_signalSettingModified.connect(m_SmileDetect, &SmileDetectSetting::onSettingUpdate);
    m_CamearaSensor->m_signalSettingModified.connect(m_SceneDetect, &SceneDetectSetting::onSettingUpdate);
    m_CamearaSensor->m_signalSettingModified.connect(m_ZeroDelay, &ZeroDelaySetting::onSettingUpdate);
    m_CamearaSensor->m_signalSettingModified.connect(m_CapSize, &CapSizeSetting::onSettingUpdate);

    m_Application->m_signalSettingModified.connect(m_CapEV, &CamEVSetting::onSettingUpdate);
    m_Application->m_signalSettingModified.connect(m_RecEV, &VdoEVSetting::onSettingUpdate);
    m_Application->m_signalSettingModified.connect(m_Effect, &EffectSetting::onSettingUpdate);
    m_Application->m_signalSettingModified.connect(m_WB, &WBSetting::onSettingUpdate);
    m_Application->m_signalSettingModified.connect(m_ISO, &ISOSetting::onSettingUpdate);

    m_CamSCN->m_signalSettingModified.connect(m_Flash, &FlashSetting::onSettingUpdate);
    m_CamSCN->m_signalSettingModified.connect(m_ISO, &ISOSetting::onSettingUpdate);
    m_CamSCN->m_signalSettingModified.connect(m_WB, &WBSetting::onSettingUpdate);
    m_CamSCN->m_signalSettingModified.connect(m_CapSize, &CapSizeSetting::onSettingUpdate);

    m_CapSize->m_signalSettingModified.connect(m_CapZoom, &CamZoomSetting::onSettingUpdate);

    m_SmileDetect->m_signalSettingModified.connect(m_SelfTimer, &SelfTimerSetting::onSettingUpdate);
    m_SmileDetect->m_signalSettingModified.connect(m_Flash, &FlashSetting::onSettingUpdate);
    m_SmileDetect->m_signalSettingModified.connect(m_CamSCN, &CamSceneModeSetting::onSettingUpdate);
    m_SmileDetect->m_signalSettingModified.connect(m_Effect, &EffectSetting::onSettingUpdate);
    m_SmileDetect->m_signalSettingModified.connect(m_ZeroDelay, &ZeroDelaySetting::onSettingUpdate);
    m_SmileDetect->m_signalSettingModified.connect(m_SceneDetect, &SceneDetectSetting::onSettingUpdate);

    m_SceneDetect->m_signalSettingModified.connect(m_ISO, &ISOSetting::onSettingUpdate);
    m_SceneDetect->m_signalSettingModified.connect(m_CamSCN, &CamSceneModeSetting::onSettingUpdate);
    m_SceneDetect->m_signalSettingModified.connect(m_WB, &WBSetting::onSettingUpdate);
    m_SceneDetect->m_signalSettingModified.connect(m_CapEV, &CamEVSetting::onSettingUpdate);
    m_SceneDetect->m_signalSettingModified.connect(m_CamSCN, &CamSceneModeSetting::onSettingUpdate);
    m_SceneDetect->m_signalSettingModified.connect(m_Effect, &EffectSetting::onSettingUpdate);
    m_SceneDetect->m_signalSettingModified.connect(m_SmileDetect, &SmileDetectSetting::onSettingUpdate);
    m_SceneDetect->m_signalSettingModified.connect(m_ZeroDelay, &ZeroDelaySetting::onSettingUpdate);

    m_TimeLapse->m_signalSettingModified.connect(m_RecLimit, &LimitSetting::onSettingUpdate);

    m_ZeroDelay->m_signalSettingModified.connect(m_CapSize, &CapSizeSetting::onSettingUpdate);
    m_ZeroDelay->m_signalSettingModified.connect(m_Flash, &FlashSetting::onSettingUpdate);
    m_ZeroDelay->m_signalSettingModified.connect(m_Effect, &EffectSetting::onSettingUpdate);
    m_ZeroDelay->m_signalSettingModified.connect(m_SceneDetect, &SceneDetectSetting::onSettingUpdate);
    m_ZeroDelay->m_signalSettingModified.connect(m_ZeroDelay, &ZeroDelaySetting::onSettingUpdate);

    m_Effect->m_signalSettingModified.connect(m_CamSCN, &CamSceneModeSetting::onSettingUpdate);
    m_Effect->m_signalSettingModified.connect(m_RecSCN, &VdoSceneModeSetting::onSettingUpdate);

    m_RecSize->m_signalSettingModified.connect(m_RecZoom, &VdoZoomSetting::onSettingUpdate);
    m_RecSize->m_signalSettingModified.connect(m_RecLimit, &LimitSetting::onSettingUpdate);
    m_RecSize->m_signalSettingModified.connect(m_RecCodec, &VisCodecSetting::onSettingUpdate);
    m_RecSize->m_signalSettingModified.connect(m_RecQty, &VisQtySetting::onSettingUpdate);
    m_RecSize->m_signalSettingModified.connect(m_RecStorage, &CamcoSettingItem::onSettingUpdate);

    m_RecQty->m_signalSettingModified.connect(m_RecCodec, &VisCodecSetting::onSettingUpdate);
    m_RecQty->m_signalSettingModified.connect(m_RecSize, &RecSizeSetting::onSettingUpdate);
    m_RecQty->m_signalSettingModified.connect(m_RecStorage, &CamcoSettingItem::onSettingUpdate);

    m_ISO->m_signalSettingModified.connect(m_CapSize, &CapSizeSetting::onSettingUpdate);

    m_RecSCN->m_signalSettingModified.connect(m_Flash, &FlashSetting::onSettingUpdate);
    m_RecSCN->m_signalSettingModified.connect(m_ISO, &ISOSetting::onSettingUpdate);
    m_RecSCN->m_signalSettingModified.connect(m_WB, &WBSetting::onSettingUpdate);
    m_RecSCN->m_signalSettingModified.connect(m_RecSize, &RecSizeSetting::onSettingUpdate);

    m_CamStorage->m_signalSettingModified.connect(m_RecStorage, &StorageSetting::onSettingUpdate);
    m_RecStorage->m_signalSettingModified.connect(m_CamStorage, &StorageSetting::onSettingUpdate);
    m_RecStorage->m_signalSettingModified.connect(m_RecCodec, &VisCodecSetting::onSettingUpdate);
    m_RecStorage->m_signalSettingModified.connect(m_RecSize, &RecSizeSetting::onSettingUpdate);
    m_RecStorage->m_signalSettingModified.connect(m_RecQty, &VisQtySetting::onSettingUpdate);

    m_RecCodec->m_signalSettingModified.connect(m_RecQty, &VisQtySetting::onSettingUpdate);
    m_RecCodec->m_signalSettingModified.connect(m_RecSize, &RecSizeSetting::onSettingUpdate);
    m_RecCodec->m_signalSettingModified.connect(m_RecStorage, &CamcoSettingItem::onSettingUpdate);

    // set value after call connection is done
    setValueAllSetting();

    customConfig();
}

void CamcoSettingMgr::setCallingMode(VfxBool isExtCalling, vcui_camco_param_struct Param)
{
    m_IsExternalSetting = isExtCalling;
    memcpy(&m_callingParam, &Param, sizeof(vcui_camco_param_struct));
}

void CamcoSettingMgr::getGurrentSetting(CamcoSettingItem** setting_p)
{
    (*setting_p) = m_ActiveSetting;
}

VfxS32 CamcoSettingMgr::getCurrentSettingIdx(void)
{
    if(!initialized())
    {
        return -1;
    }

    for(VfxU16 i = 0; i < m_mainCount; i++)
    {
        if(m_mainList[i]->getType() == m_ActiveSetting->getType())
        {
            return i;
        }
    };
    return -1;
}

VfxS32 CamcoSettingMgr::getSettingIdx(vapp_camco_setting_enum type)
{
    if(!initialized())
    {
        return -1;
    }

    for(VfxU16 i = 0; i < m_mainCount; i++)
    {
        if(m_mainList[i]->getType() == type)
        {
            return i;
        }
    }
    return -1;
}


void CamcoSettingMgr::getSetting(vapp_camco_setting_enum type, CamcoSettingItem** setting_p)
{
    // these two setting should get by getValue() directly, they won't in setting list
    ASSERT(type != VAPP_CAMCO_SETTING_ACT_CAM);
    ASSERT(type != VAPP_CAMCO_SETTING_ACT_APP);


    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            (*setting_p) = m_allSettingList[i];
            return;
        }
    }
    (*setting_p) = NULL;
}

const CamcoSettingItem* CamcoSettingMgr::getSetting(vapp_camco_setting_enum type)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i];
        }
    }
    return m_allSettingList[0];
}


MMI_ID_TYPE CamcoSettingMgr::getSettingImg(vapp_camco_setting_enum type) const
{

    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getImg();
        }
    }
    return 0;
}

MMI_ID_TYPE CamcoSettingMgr::getSettingStatusImg(vapp_camco_setting_enum type)
{

    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getItem(m_allSettingList[i]->getValue()).getImg();
        }
    }
    return 0;
}

MMI_ID_TYPE CamcoSettingMgr::getSettingStatusIcon(vapp_camco_setting_enum type)
{

    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getItem(m_allSettingList[i]->getValue()).getStatusIcon();
        }
    }
    return 0;
}

vapp_camco_setting_enum CamcoSettingMgr::getCurrentSetting(void)
{
    return m_ActiveSetting->getType();
}

VfxBool CamcoSettingMgr::setCurrentSetting(void)
{
    m_ActiveSetting = m_mainList[0];
    m_ActiveSettingIdx = 0;
    CleanItemList();
    genItemList();
    return VFX_TRUE;
}

VfxBool CamcoSettingMgr::setCurrentSetting(VfxU16 index)
{
    m_ActiveSetting = m_mainList[index];
    m_ActiveSettingIdx = index;
    CleanItemList();
    genItemList();
    return VFX_TRUE;

}

VfxBool CamcoSettingMgr::setCurrentSetting(vapp_camco_setting_enum type)
{
    if(!initialized())
    {
        return VFX_FALSE;
    }

    for(VfxU16 i = 0; i < m_mainCount; i++)
    {
        if(m_mainList[i]->getType() == type)
        {
            m_ActiveSetting = m_mainList[i];
            m_ActiveSettingIdx = i;
            CleanItemList();
            genItemList();
            return VFX_TRUE;

        }
    }

    return VFX_FALSE;
}

VfxU16 CamcoSettingMgr :: getValue(vapp_camco_setting_enum type)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            getSeetingLog(type, m_allSettingList[i]->getValue());
            return m_allSettingList[i]->getValue();
        }
    }
    return 0;
}

VfxBool CamcoSettingMgr :: setValue(vapp_camco_setting_enum type, VfxU16 value)
{
    setSeetingLog(type, value);

    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            m_allSettingList[i]->setValue(value);
            m_allSettingList[i]->applyEffect(value);

            for(VfxU16 j = 0; j < m_itemCount; j++)
            {
                if(m_itemList[j]->getValue() == value)
                {
                    m_ActiveSettingItemIdx = j;
                    break;
                }
            }
            customUpdate(type, value);
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}

VfxBool CamcoSettingMgr :: setValue(VfxU16 value)
{
    setSeetingLog(m_ActiveSetting->getType(), value);

    m_ActiveSetting->setValue(value);
    m_ActiveSetting->applyEffect(value);
    for(VfxU16 j = 0; j < m_itemCount; j++)
    {
        if(m_itemList[j]->getValue() == value)
        {
            m_ActiveSettingItemIdx = j;
            break;
        }
    }
    customUpdate(m_ActiveSetting->getType(), value);
    return VFX_TRUE;
}

VfxBool CamcoSettingMgr :: setValue(VfxU16 newHiliteIdx, VfxBool dummy)
{
    setSeetingLog(m_ActiveSetting->getType(), m_itemList[newHiliteIdx]->getValue());

    m_ActiveSetting->setValue(m_itemList[newHiliteIdx]->getValue());
    m_ActiveSetting->applyEffect(m_itemList[newHiliteIdx]->getValue());
    m_ActiveSettingItemIdx = newHiliteIdx;
    customUpdate(m_ActiveSetting->getType(), m_itemList[newHiliteIdx]->getValue());
    return VFX_TRUE;
}

vapp_camco_setting_cap_enum CamcoSettingMgr :: getStatus(vapp_camco_setting_enum type)
{

    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getStatus();
        }
    }

    return VAPP_CAMCO_SETTING_CAP_DISABLED;

}

VfxU32 CamcoSettingMgr::getMappingID(vapp_camco_setting_enum type)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getMappingID(m_allSettingList[i]->getValue());
        }
    }
    return 0;
}

VfxU32 CamcoSettingMgr::getMappingID(vapp_camco_setting_enum type, VfxU32 mmiID)
{

    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getMappingID(mmiID);
        }
    }
    return 0;
}

void CamcoSettingMgr :: setHilite(VfxU16 value)
{
    m_ActiveSetting->applyEffect(value);
}

VfxU32 CamcoSettingMgr::getMaxValue(void)
{
    return m_ActiveSetting->getMaxValue();
}

VfxU32 CamcoSettingMgr::getMaxValue(vapp_camco_setting_enum type)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getMaxValue();
        }
    }
    return m_allSettingList[0]->getMaxValue();
}

VfxU32 CamcoSettingMgr::getMinValue(vapp_camco_setting_enum type)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getMinValue();
        }
    }
    return m_allSettingList[0]->getMinValue();
}

VfxU32 CamcoSettingMgr::getMinValue(void)
{
    return m_ActiveSetting->getMinValue();
}

VfxU32 CamcoSettingMgr::getSettingCount(vapp_camco_setting_enum type)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getSettingCount();
        }
    }
    return m_allSettingList[0]->getSettingCount();
}

VfxBool CamcoSettingMgr::moveNextSetting(void)
{
    if (m_ActiveSettingIdx <= m_mainCount)
    {
        setCurrentSetting(m_ActiveSettingIdx + 1);
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }

}

VfxBool CamcoSettingMgr::movePrevSetting(void)
{
    if (m_ActiveSettingIdx > 0)
    {
        setCurrentSetting(m_ActiveSettingIdx - 1);
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }

}

VfxBool CamcoSettingMgr::moveNextSettingItem(void)
{
    if (m_ActiveSettingItemIdx <= m_itemCount)
    {
        setValue(m_ActiveSettingItemIdx + 1, VFX_TRUE);
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }

}

VfxBool CamcoSettingMgr::movePrevSettingItem(void)
{
    if (m_ActiveSettingItemIdx > 0)
    {
        setValue(m_ActiveSettingItemIdx - 1, VFX_TRUE);
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }

}


void CamcoSettingMgr::getSettingList(vapp_camco_setting_list_struct* List_p)
{
    List_p->settingCount = m_mainCount;
    for(VfxU16 i = 0; i < m_mainCount; i++)
    {
        List_p->settingStrId[i] = m_mainList[i]->getStr();
        List_p->settingImgId[i] = m_mainList[i]->getImg();
        List_p->settingValue[i] = m_mainList[i]->getType();
        if(m_mainList[i]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
            List_p->settingEnable[i] = VFX_TRUE;
        else
            List_p->settingEnable[i] = VFX_FALSE;
        if(m_mainList[i]->getType() == m_ActiveSetting->getType())
        {
            List_p->CurrentSettingIdx = i;
        }

    }

    VfxU32 pervActiveIdx = m_ActiveSettingIdx;

    for(VfxU16 i = 0; i < m_mainCount; i++)
    {
        m_ActiveSetting = m_mainList[i];
        m_ActiveSettingIdx = i;
        CleanItemList();
        genItemList();

        List_p->settingItemCount[i] = m_itemCount;
        for(VfxU16 j = 0; j < m_itemCount; j++)
        {
            List_p->settingItemStrId[i][j] = m_itemList[j]->getStr();
            List_p->settingItemImgId[i][j] = m_itemList[j]->getImg();
            List_p->settingItemValue[i][j] = m_itemList[j]->getValue();
            if(m_itemList[j]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
                List_p->settingItemEnable[i][j] = VFX_TRUE;
            else
                List_p->settingItemEnable[i][j] = VFX_FALSE;
        }
        List_p->CurrentSettingValue[i] = m_ActiveSetting->getValue();
        List_p->CurrentSettingValueIdx[i] = m_ActiveSettingItemIdx;

    }

    m_ActiveSetting = m_mainList[pervActiveIdx];
    m_ActiveSettingIdx = pervActiveIdx;
    CleanItemList();
    genItemList();

}

void CamcoSettingMgr :: initAllSetting(void)
{
    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_ALL);

    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() != VAPP_CAMCO_SETTING_ACT_APP && m_allSettingList[i]->getType() != VAPP_CAMCO_SETTING_ACT_CAM)
        {
            m_allSettingList[i]->initialize();
        }
    }

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_ALL_F);
}

void CamcoSettingMgr :: setDefaultAllSetting(void)
{
    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_ALL);

    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() != VAPP_CAMCO_SETTING_ACT_APP && m_allSettingList[i]->getType() != VAPP_CAMCO_SETTING_ACT_CAM)
        {
            m_allSettingList[i]->setDefault();
        }
    }

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_ALL_F);
}

void CamcoSettingMgr :: setValueAllSetting(void)
{
    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_ALL);

    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() != VAPP_CAMCO_SETTING_ACT_APP && m_allSettingList[i]->getType() != VAPP_CAMCO_SETTING_ACT_CAM)
        {
            m_allSettingList[i]->setValue(m_allSettingList[i]->getValue());
        }
    }

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_SET_VALUE_ALL_F);
}


void CamcoSettingMgr :: resetEffect(void)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        m_allSettingList[i]->resetEffect();
    }
}

void CamcoSettingMgr :: loadSetting(void)
{

    if(m_IsExternalSetting)
    {
        m_SmileDetect->resetValue(0xFF);
        m_SceneDetect->resetValue(0xFF);
        m_ZeroDelay->resetValue(0xFF);
        m_CamSCN->resetValue(0xFF);
        m_CapSize->resetValue(0xFF);
        m_Flash->resetValue(0xFF);
        m_SelfTimer->resetValue(0xFF);
        m_ISO->resetValue(0xFF);
        m_WB->resetValue(0xFF);
        m_Effect->resetValue(0xFF);
        m_CamStorage->resetValue(0xFF);
        m_RecStorage->resetValue(0xFF);
        m_CapQty->resetValue(0xFF);
        m_RecSCN->resetValue(0xFF);
        m_RecSize->resetValue(0xFF);
        m_RecLimit->resetValue(0xFF);
        m_RecQty->resetValue(0xFF);
        m_RecCodec->resetValue(0xFF);
    }
    else
    {
        S16 error;
        nvram_ef_camco_ex_vapp_setting_struct nvram_data;
        nvram_ef_camco_ex_vapp_info_struct nvram_camco_info;

        if(m_isReadNvramData)
        {
            m_Application->resetValue(VAPP_CAMCO_APP_CAMERA);
            m_CamearaSensor->resetValue(VAPP_CAMCO_SENSOR_MAIN_CAMERA);
        }
        else
        {
            ReadRecord(
                NVRAM_EF_CAMCO_EX_VAPP_INFO_LID,
                1,  /* first one is from 1 */
                (void*)&nvram_camco_info,
                NVRAM_EF_CAMCO_EX_VAPP_INFO_SIZE,
                &error);

            m_Application->resetValue((VfxU16)nvram_camco_info.active_app);
            m_CamearaSensor->resetValue((VfxU16)nvram_camco_info.active_cam);

            if (m_Application->getValue()== 0xff)
            {
                m_Application->resetValue(VAPP_CAMCO_APP_CAMERA);
            }

            if (m_CamearaSensor->getValue() == 0xff)
            {
                m_CamearaSensor->resetValue(VAPP_CAMCO_SENSOR_MAIN_CAMERA);
            }

        }

        if (m_CamearaSensor->getValue() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
        {
            ReadRecord(
                NVRAM_EF_CAMCO_EX_VAPP_MAIN_SETTING_LID,
                1,  /* first one is from 1 */
                (void*)&nvram_data,
                NVRAM_EF_CAMCO_EX_VAPP_MAIN_SETTING_SIZE,
                &error);
        }
    #ifdef DUAL_CAMERA_SUPPORT
        else if (m_CamearaSensor->getValue() == VAPP_CAMCO_SENSOR_SUB_CAMERA)
        {
            ReadRecord(
                NVRAM_EF_CAMCO_EX_VAPP_SUB_SETTING_LID,
                1,  /* first one is from 1 */
                (void*)&nvram_data,
                NVRAM_EF_CAMCO_EX_VAPP_SUB_SETTING_SIZE,
                &error);
        }
    #endif /* DUAL_CAMERA_SUPPORT */
        else
        {
            MMI_ASSERT(0);
        }

        if(m_isReadNvramData)
        {
            m_SmileDetect->resetValue(0xFF);
            m_SceneDetect->resetValue(0xFF);
            m_ZeroDelay->resetValue(0xFF);
        }
        m_CamSCN->resetValue((VfxU16)nvram_data.camscenemode);
        m_CapSize->resetValue((VfxU16)nvram_data.capsize);
        m_Flash->resetValue((VfxU16)nvram_data.flash);
        if(m_isReadNvramData)
            m_SelfTimer->resetValue(VAPP_CAMCO_SELFTIMER_OFF);
        else
            m_SelfTimer->resetValue((VfxU16)nvram_data.selftimer);
        m_ISO->resetValue((VfxU16)nvram_data.iso);
        m_WB->resetValue((VfxU16)nvram_data.wb);
        m_Effect->resetValue((VfxU16)nvram_data.effect);
        m_CamStorage->resetValue((VfxU16)nvram_data.storage);
        m_RecStorage->resetValue((VfxU16)nvram_data.storage);
        m_CapQty->resetValue((VfxU16)nvram_data.capqty);
        m_RecSCN->resetValue((VfxU16)nvram_data.vdoscenemode);
        m_RecSize->resetValue((VfxU16)nvram_data.recsize);
        if(m_isReadNvramData)
            m_TimeLapse->resetValue(VAPP_CAMCO_TIME_LAPSE_OFF);
        m_TimeLapsePeriod->resetValue(VAPP_CAMCO_TIME_LAPSE_PERIOD_1);
        m_RecLimit->resetValue((VfxU16)nvram_data.limit);
        m_RecQty->resetValue((VfxU16)nvram_data.visqty);
        m_RecCodec->resetValue((VfxU16)nvram_data.viscodec);

        /* save to NVRAM */
        storeSetting();
    }
}

void CamcoSettingMgr :: storeSetting(void)
{
    if(m_IsExternalSetting)
        return;

    S16 error;
    nvram_ef_camco_ex_vapp_setting_struct nvram_data;
    nvram_ef_camco_ex_vapp_info_struct nvram_camco_info;

    nvram_camco_info.active_app = m_Application->getValue();
    nvram_camco_info.active_cam = m_CamearaSensor->getValue();

    WriteRecord(
        NVRAM_EF_CAMCO_EX_VAPP_INFO_LID,
        1,  /* first one is from 1 */
        (void*)&nvram_camco_info,
        NVRAM_EF_CAMCO_EX_VAPP_INFO_SIZE,
        &error);

    nvram_data.camscenemode = m_CamSCN->getValue();
    nvram_data.capsize = m_CapSize->getValue();
    nvram_data.flash = m_Flash->getValue();
    nvram_data.selftimer = m_SelfTimer->getValue();
    nvram_data.iso = m_ISO->getValue();
    nvram_data.wb = m_WB->getValue();
    nvram_data.effect = m_Effect->getValue();
    nvram_data.storage = m_CamStorage->getValue();
    nvram_data.storage = m_RecStorage->getValue();
    nvram_data.capqty = m_CapQty->getValue();
    nvram_data.vdoscenemode = m_RecSCN->getValue();
    nvram_data.recsize = m_RecSize->getValue();
    nvram_data.limit = m_RecLimit->getValue();
    nvram_data.visqty = m_RecQty->getValue();
    nvram_data.viscodec = m_RecCodec->getValue();

    if (getCurrCam()== VAPP_CAMCO_SENSOR_MAIN_CAMERA)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_EX_VAPP_MAIN_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_EX_VAPP_MAIN_SETTING_SIZE,
            &error);
    }
#ifdef DUAL_CAMERA_SUPPORT
    else if (getCurrCam() == VAPP_CAMCO_SENSOR_SUB_CAMERA)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_EX_VAPP_SUB_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_EX_VAPP_SUB_SETTING_SIZE,
            &error);
    }
#endif /* DUAL_CAMERA_SUPPORT */
    else
    {
        MMI_ASSERT(0);
    }
}

void CamcoSettingMgr::getNvRamSetting(vapp_camco_setting_set_struct *set)
{
    S16 error;
    nvram_ef_camco_ex_vapp_setting_struct nvram_data;
    nvram_ef_camco_ex_vapp_info_struct nvram_camco_info;

    ReadRecord(
        NVRAM_EF_CAMCO_EX_VAPP_INFO_LID,
        1,  /* first one is from 1 */
        (void*)&nvram_camco_info,
        NVRAM_EF_CAMCO_EX_VAPP_INFO_SIZE,
        &error);

    set->active_app = (VfxU16)nvram_camco_info.active_app;
    set->active_cam = (VfxU16)nvram_camco_info.active_cam;


    if (set->active_cam == 0xff || set->active_cam == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_EX_VAPP_MAIN_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_EX_VAPP_MAIN_SETTING_SIZE,
            &error);
    }
#ifdef DUAL_CAMERA_SUPPORT
    else if (set->active_cam == VAPP_CAMCO_SENSOR_SUB_CAMERA)
    {
        ReadRecord(
            NVRAM_EF_CAMCO_EX_VAPP_SUB_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_EX_VAPP_SUB_SETTING_SIZE,
            &error);
    }
#endif /* DUAL_CAMERA_SUPPORT */
    else
    {
        MMI_ASSERT(0);
    }

    set->scene_detect = 0;
    set->smile_detect = 0;
    set->zero_delay = 0;
    set->camscenemode = (nvram_data.camscenemode != 0xff)?nvram_data.camscenemode:0;
    set->capsize = (nvram_data.capsize != 0xff)?nvram_data.capsize:1;
    set->flash = (nvram_data.flash != 0xff)?nvram_data.flash:0;
    set->selftimer = (nvram_data.selftimer != 0xff)?nvram_data.selftimer:0;
    set->iso = (nvram_data.iso != 0xff)?nvram_data.iso:0;
    set->wb = (nvram_data.wb != 0xff)?nvram_data.wb:0;
    set->effect = (nvram_data.effect != 0xff)?nvram_data.effect:0;
    set->storage = (nvram_data.storage != 0xff)?nvram_data.storage:0;
    set->capqty = (nvram_data.capqty != 0xff)?nvram_data.capqty:0;
    set->vdoscenemode = (nvram_data.vdoscenemode != 0xff)?nvram_data.vdoscenemode:0;
    set->recsize = (nvram_data.recsize != 0xff)?nvram_data.recsize:0;
    set->limit = (nvram_data.limit != 0xff)?nvram_data.limit:0;
    set->visqty = (nvram_data.visqty != 0xff)?nvram_data.visqty:0;
    set->viscodec = (nvram_data.viscodec != 0xff)?nvram_data.viscodec:0;
}

void CamcoSettingMgr :: genMainList(vapp_camco_setting_mainlist_type_enum type)
{
    m_settingListType = type;

    switch (type)
    {
        case VAPP_CAMCO_SETTING_MAINLIST_CAMERA:
        {
            CleanMainList();
            AddtoMainList((CamcoSettingItem*)m_CapEV);
        #if defined(__VAPP_CAMCO_HIGHEND_SETTING__)
            AddtoMainList((CamcoSettingItem*)m_CamSCN);
        #endif
            AddtoMainList((CamcoSettingItem*)m_SelfTimer);
            AddtoMainList((CamcoSettingItem*)m_WB);
            AddtoMainList((CamcoSettingItem*)m_ISO);
            AddtoMainList((CamcoSettingItem*)m_Effect);
            AddtoMainList((CamcoSettingItem*)m_CapSize);
            //AddtoMainList((CamcoSettingItem*)m_CapQty);
        #if defined(__VAPP_CAMCO_HIGHEND_SETTING__) && !defined(__VAPP_CAMCO_NO_PUBLIC_DRV__)
            AddtoMainList((CamcoSettingItem*)m_CamStorage);
        #endif
            AddtoMainList((CamcoSettingItem*)m_SmileDetect);
            AddtoMainList((CamcoSettingItem*)m_SceneDetect);
            AddtoMainList((CamcoSettingItem*)m_ZeroDelay);
            m_ListCreated = VFX_TRUE;
            setCurrentSetting(VAPP_CAMCO_SETTING_CAPSIZE);
            break;

        }
        case VAPP_CAMCO_SETTING_MAINLIST_FLASH_ONLY:
        {
            CleanMainList();
            AddtoMainList((CamcoSettingItem*)m_Flash);

            m_ListCreated = VFX_TRUE;
            setCurrentSetting();
            break;
        }
        case VAPP_CAMCO_SETTING_MAINLIST_RECORDER:
        {
            CleanMainList();
            AddtoMainList((CamcoSettingItem*)m_RecEV);
        #if defined(__VAPP_CAMCO_HIGHEND_SETTING__)
            AddtoMainList((CamcoSettingItem*)m_RecSCN);
        #endif
            AddtoMainList((CamcoSettingItem*)m_RecLimit);
            AddtoMainList((CamcoSettingItem*)m_WB);
            AddtoMainList((CamcoSettingItem*)m_Effect);
            AddtoMainList((CamcoSettingItem*)m_TimeLapse);
            AddtoMainList((CamcoSettingItem*)m_RecQty);
            if(!recorder_config_has_dependency())
            {
                AddtoMainList((CamcoSettingItem*)m_RecSize);
                AddtoMainList((CamcoSettingItem*)m_RecCodec);
            }
        #if defined(__VAPP_CAMCO_HIGHEND_SETTING__) && !defined(__VAPP_CAMCO_NO_PUBLIC_DRV__)
            AddtoMainList((CamcoSettingItem*)m_RecStorage);
        #endif
            m_ListCreated = VFX_TRUE;
            setCurrentSetting(VAPP_CAMCO_SETTING_LIMIT);
            break;
        }

    }


}

void CamcoSettingMgr :: genItemList(void)
{
    CamcoSettingItem* setting = m_ActiveSetting;

    for(VfxU16 i = 0; i < VAPP_CAMCO_MAX_SETTING_ITEM_COUNT; i++)
    {
        if(setting->getItem(i).getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            m_itemList[m_itemCount] = &(setting->getItem(i));
            if(setting->getValue() == i)
            {
                m_ActiveSettingItem = m_itemList[m_itemCount];
                m_ActiveSettingItemIdx = m_itemCount;
            }
            m_itemCount++;
        }
    }

};

void CamcoSettingMgr :: genItemList(vapp_camco_setting_enum type){};


void CamcoSettingMgr :: CleanMainList(void)
{
    m_ListCreated = VFX_FALSE;
    m_mainCount = 0;
    m_ActiveSetting = NULL;
    for(VfxU16 i = 0; i < VAPP_CAMCO_SETTING_END; i++)
    {
        m_mainList[i] = NULL;;
    }
    m_itemCount = 0;
    for(VfxU16 i = 0; i < VAPP_CAMCO_MAX_SETTING_ITEM_COUNT; i++)
    {
        m_itemList[i] = NULL;;
    }
}

void CamcoSettingMgr :: CleanItemList(void)
{
    m_itemCount = 0;
    for(VfxU16 i = 0; i < VAPP_CAMCO_MAX_SETTING_ITEM_COUNT; i++)
    {
        m_itemList[i] = NULL;;
    }
}

VfxBool CamcoSettingMgr :: AddtoMainList(CamcoSettingItem* setting)
{
    if(setting->getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
    {
        m_mainList[m_mainCount] = setting;
        m_mainCount++;
    }

    return VFX_TRUE;

}

vapp_camco_setting_enum CamcoSettingMgr::transTargetToMMI(recoorder_config_setting_target target)
{

    if(target == SETTING_CONFIG_SETTING_QTY)
    {
        return VAPP_CAMCO_SETTING_VISQTY;
    }
    else if(target == SETTING_CONFIG_SETTING_CODEC)
    {
        return VAPP_CAMCO_SETTING_VISCODEC;
    }
    else if(target == SETTING_CONFIG_SETTING_RESOLUTION)
    {
        return VAPP_CAMCO_SETTING_RECSIZE;
    }
    else
    {
        return VAPP_CAMCO_SETTING_END;
    }
}


recoorder_config_setting_target CamcoSettingMgr::transTargetFromMMI(vapp_camco_setting_enum target)
{
    if(target == VAPP_CAMCO_SETTING_VISQTY)
    {
        return SETTING_CONFIG_SETTING_QTY;
    }
    else if(target == VAPP_CAMCO_SETTING_VISCODEC)
    {
        return SETTING_CONFIG_SETTING_CODEC;
    }
    else if(target == VAPP_CAMCO_SETTING_RECSIZE)
    {
        return SETTING_CONFIG_SETTING_RESOLUTION;
    }
    else
    {
        return SETTING_CONFIG_TARGET_NONE;
    }
}


VfxU16 CamcoSettingMgr::transValueToMMI(recoorder_config_setting_value value)
{

    if(value == SETTING_CONFIG_QTY_FINE)
    {
        return VAPP_CAMCO_VISQTY_FINE;
    }
    else if(value == SETTING_CONFIG_QTY_GOOD)
    {
        return VAPP_CAMCO_VISQTY_GOOD;
    }
    else if(value == SETTING_CONFIG_QTY_NORMAL)
    {
        return VAPP_CAMCO_VISQTY_NORMAL;
    }
    else if(value == SETTING_CONFIG_QTY_LOW)
    {
        return VAPP_CAMCO_VISQTY_LOW;
    }
    if(value == SETTING_CONFIG_QTY_LCD)
    {
        return VAPP_CAMCO_VISQTY_LCD;
    }
    else if(value == SETTING_CONFIG_CODEC_MP4)
    {
        return VAPP_CAMCO_VISCODEC_MP4;
    }
    else if(value == SETTING_CONFIG_CODEC_3GP)
    {
        return VAPP_CAMCO_VISCODEC_3GP;
    }
    else if(value == SETTING_CONFIG_CODEC_MJPG)
    {
        return VAPP_CAMCO_VISCODEC_MJPG;
    }
    else if(value == SETTING_CONFIG_CODEC_H264)
    {
        return VAPP_CAMCO_VISCODEC_H264;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_SQCIF)
    {
        return VAPP_CAMCO_RECSIZE_SQCIF;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_QQVGA)
    {
        return VAPP_CAMCO_RECSIZE_QQVGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_QCIF)
    {
        return VAPP_CAMCO_RECSIZE_QCIF;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_QVGA)
    {
        return VAPP_CAMCO_RECSIZE_QVGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_CIF)
    {
        return VAPP_CAMCO_RECSIZE_CIF;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_WQVGA)
    {
        return VAPP_CAMCO_RECSIZE_WQVGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_CIF2)
    {
        return VAPP_CAMCO_RECSIZE_CIF2;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_HVGA)
    {
        return VAPP_CAMCO_RECSIZE_HVGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_NHD)
    {
        return VAPP_CAMCO_RECSIZE_NHD;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_VGA)
    {
        return VAPP_CAMCO_RECSIZE_VGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_4CIF)
    {
        return VAPP_CAMCO_RECSIZE_4CIF;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_D1)
    {
        return VAPP_CAMCO_RECSIZE_D1;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_D12)
    {
        return VAPP_CAMCO_RECSIZE_D12;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_WVGA)
    {
        return VAPP_CAMCO_RECSIZE_WVGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_SVGA)
    {
        return VAPP_CAMCO_RECSIZE_SVGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_WVGA2)
    {
        return VAPP_CAMCO_RECSIZE_WVGA2;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_FWVGA)
    {
        return VAPP_CAMCO_RECSIZE_FWVGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_XGA)
    {
        return VAPP_CAMCO_RECSIZE_XGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_720P)
    {
        return VAPP_CAMCO_RECSIZE_720P;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_4VGA)
    {
        return VAPP_CAMCO_RECSIZE_4VGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_SXGA)
    {
        return VAPP_CAMCO_RECSIZE_SXGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_16CIF)
    {
        return VAPP_CAMCO_RECSIZE_16CIF;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_4SVGA)
    {
        return VAPP_CAMCO_RECSIZE_4SVGA;
    }
    else if(value == SETTING_CONFIG_RESOLUTION_FHD)
    {
        return VAPP_CAMCO_RECSIZE_FHD;
    }

    return 0;
}

recoorder_config_setting_value CamcoSettingMgr::transValueFromMMI(VfxU16 value, vapp_camco_setting_enum target)
{

    if(target == VAPP_CAMCO_SETTING_VISQTY)
    {
        if(value == VAPP_CAMCO_VISQTY_FINE)
        {
            return SETTING_CONFIG_QTY_FINE;
        }
        else if(value == VAPP_CAMCO_VISQTY_GOOD)
        {
            return SETTING_CONFIG_QTY_GOOD;
        }
        else if(value == VAPP_CAMCO_VISQTY_NORMAL)
        {
            return SETTING_CONFIG_QTY_NORMAL;
        }
        else if(value == VAPP_CAMCO_VISQTY_LOW)
        {
            return SETTING_CONFIG_QTY_LOW;
        }
        else if(value == VAPP_CAMCO_VISQTY_LCD)
        {
            return SETTING_CONFIG_QTY_LCD;
        }
    }
    else if(target == VAPP_CAMCO_SETTING_VISCODEC)
    {
        if(value == VAPP_CAMCO_VISCODEC_MP4)
        {
            return SETTING_CONFIG_CODEC_MP4;
        }
        else if(value == VAPP_CAMCO_VISCODEC_3GP)
        {
            return SETTING_CONFIG_CODEC_3GP;
        }
        else if(value == VAPP_CAMCO_VISCODEC_MJPG)
        {
            return SETTING_CONFIG_CODEC_MJPG;
        }
        else if(value == VAPP_CAMCO_VISCODEC_H264)
        {
            return SETTING_CONFIG_CODEC_H264;
        }
    }
    else if(target == VAPP_CAMCO_SETTING_RECSIZE)
    {

        if(value == VAPP_CAMCO_RECSIZE_SQCIF)
        {
            return SETTING_CONFIG_RESOLUTION_SQCIF;
        }
        else if(value == VAPP_CAMCO_RECSIZE_QQVGA)
        {
            return SETTING_CONFIG_RESOLUTION_QQVGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_QCIF)
        {
            return SETTING_CONFIG_RESOLUTION_QCIF;
        }
        else if(value == VAPP_CAMCO_RECSIZE_QVGA)
        {
            return SETTING_CONFIG_RESOLUTION_QVGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_CIF)
        {
            return SETTING_CONFIG_RESOLUTION_CIF;
        }
        else if(value == VAPP_CAMCO_RECSIZE_WQVGA)
        {
            return SETTING_CONFIG_RESOLUTION_WQVGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_CIF2)
        {
            return SETTING_CONFIG_RESOLUTION_CIF2;
        }
        else if(value == VAPP_CAMCO_RECSIZE_HVGA)
        {
            return SETTING_CONFIG_RESOLUTION_HVGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_NHD)
        {
            return SETTING_CONFIG_RESOLUTION_NHD;
        }
        else if(value == VAPP_CAMCO_RECSIZE_VGA)
        {
            return SETTING_CONFIG_RESOLUTION_VGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_4CIF)
        {
            return SETTING_CONFIG_RESOLUTION_4CIF;
        }
        else if(value == VAPP_CAMCO_RECSIZE_D1)
        {
            return SETTING_CONFIG_RESOLUTION_D1;
        }
        else if(value == VAPP_CAMCO_RECSIZE_D12)
        {
            return SETTING_CONFIG_RESOLUTION_D12;
        }
        else if(value == VAPP_CAMCO_RECSIZE_WVGA)
        {
            return SETTING_CONFIG_RESOLUTION_WVGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_SVGA)
        {
            return SETTING_CONFIG_RESOLUTION_SVGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_WVGA2)
        {
            return SETTING_CONFIG_RESOLUTION_WVGA2;
        }
        else if(value == VAPP_CAMCO_RECSIZE_FWVGA)
        {
            return SETTING_CONFIG_RESOLUTION_FWVGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_XGA)
        {
            return SETTING_CONFIG_RESOLUTION_XGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_720P)
        {
            return SETTING_CONFIG_RESOLUTION_720P;
        }
        else if(value == VAPP_CAMCO_RECSIZE_4VGA)
        {
            return SETTING_CONFIG_RESOLUTION_4VGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_SXGA)
        {
            return SETTING_CONFIG_RESOLUTION_SXGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_16CIF)
        {
            return SETTING_CONFIG_RESOLUTION_16CIF;
        }
        else if(value == VAPP_CAMCO_RECSIZE_4SVGA)
        {
            return SETTING_CONFIG_RESOLUTION_4SVGA;
        }
        else if(value == VAPP_CAMCO_RECSIZE_FHD)
        {
            return SETTING_CONFIG_RESOLUTION_FHD;
        }
    }
    return SETTING_CONFIG_QTY_FINE;
}

void CamcoSettingMgr::customConfig(void)
{
    if(recorder_config_has_dependency())
    {
        MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_CUSTOM_DEP, 1);

        recoorder_config_setting_value key_setting_value = SETTING_CONFIG_VALUE;

        for(VfxU32 i = 0; i < m_allSettingCount; i++)
        {
            if(recorder_config_is_key(transTargetFromMMI(m_allSettingList[i]->getType())))
            {
                m_keySettingType = m_allSettingList[i]->getType();
                key_setting_value = transValueFromMMI(m_allSettingList[i]->getValue(), m_keySettingType);
            }
        }
        MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_CUSTOM_KEY, key_setting_value);

        for(VfxU32 i = 0; i < m_allSettingCount; i++)
        {
            if(recorder_config_is_depended(transTargetFromMMI(m_allSettingList[i]->getType())))
            {
                setSeetingLog(m_allSettingList[i]->getType(), transValueToMMI(recorder_config_get_setting(key_setting_value, transTargetFromMMI(m_allSettingList[i]->getType()))));
                m_allSettingList[i]->setValue(transValueToMMI(recorder_config_get_setting(key_setting_value, transTargetFromMMI(m_allSettingList[i]->getType()))));
            }
        }

        for(VfxU32 i = 0; i < m_allSettingCount; i++)
        {
            if(recorder_config_is_depended(transTargetFromMMI(m_allSettingList[i]->getType())))
            {
                MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_CUSTOM_HIDE, i);
                m_allSettingList[i]->hide(m_allSettingList[i]->getType());
            }
        }

    }
    else
    {
        MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_CUSTOM_DEP, 0);
    }

}

void CamcoSettingMgr::customUpdate(vapp_camco_setting_enum target, VfxU16 value)
{
    if(recorder_config_has_dependency())
    {

        if(m_keySettingType == target)
        {
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_CUSTOM_UPDATE);

            recoorder_config_setting_set setting_set;

            recoorder_config_setting_value key_setting_value = transValueFromMMI(value, m_keySettingType);

            recorder_config_get_setting_set(key_setting_value, &setting_set);

            for(VfxU16 i=0; i<setting_set.count; i++)
            {
                setSeetingLog(transTargetToMMI(setting_set.target[i]), transValueToMMI(setting_set.value[i]));
                setValue(transTargetToMMI(setting_set.target[i]), transValueToMMI(setting_set.value[i]));
            }
            storeSetting();
        }
    }
}

VfxBool CamcoSettingMgr::IsKeySetting(vapp_camco_setting_enum setting)
{

    if(recorder_config_is_key(transTargetFromMMI(setting)))
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }

}

#endif /*__VAPP_CAMCO_EXPRESS__*/
