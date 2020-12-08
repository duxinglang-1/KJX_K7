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

#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_include.h"

#include "MMI_features_camcorder.h"
#include "mdi_datatype.h"
#include "mdi_camera.h"
#include "mdi_video.h"

#include "ProfilesSrvGprot.h"      /* playRequestedTone */
#include "AudioInc.h"   /* Play record tone */

#include "FileMgrSrvGProt.h"

#include "Wgui_categories_util.h"
#include "FileMgrResDef.h"

#ifdef __cplusplus
}
#endif
#ifdef __VAPP_CAMCO_EXPRESS__

#include "mmi_rp_vapp_camco_def.h"
#include "vapp_camco_express_setting_item.h"
#include "vapp_camco_express_setting_mgr.h"


#if defined(HORIZONTAL_CAMERA)
VfxBool vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPSIZE_END] =
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE};

#else /* defined(HORIZONTAL_CAMERA) */
VfxBool vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPSIZE_END] =
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE};

#endif /* defined(HORIZONTAL_CAMERA) */

// [AFrange / SharpnessSetting / ContrastSetting / SaturationSetting]
// [NIGHT, SPORT , AUTO, PORTRAIT, LANDSCAPE, DOCUMENT, ANTI_SHAKE]
VfxU32 camSceneTable[4][VAPP_CAMCO_CAMSCENEMODE_ASD_AUTO] =
{
    {MDI_CAMERA_AF_RANGE_AUTO,
     MDI_CAMERA_AF_RANGE_LANDSCAPE,
     MDI_CAMERA_AF_RANGE_AUTO,
     MDI_CAMERA_AF_RANGE_AUTO,
     MDI_CAMERA_AF_RANGE_LANDSCAPE,
     MDI_CAMERA_AF_RANGE_MACRO,
     MDI_CAMERA_AF_RANGE_AUTO
    },
    {MDI_CAMERA_IE_LEVEL_LOW,
     MDI_CAMERA_IE_LEVEL_MEDIUM,
     MDI_CAMERA_IE_LEVEL_MEDIUM,
     MDI_CAMERA_IE_LEVEL_LOW,
     MDI_CAMERA_IE_LEVEL_HIGH,
     MDI_CAMERA_IE_LEVEL_HIGH,
     MDI_CAMERA_IE_LEVEL_MEDIUM
    },
    {MDI_CAMERA_IE_LEVEL_MEDIUM,
     MDI_CAMERA_IE_LEVEL_MEDIUM,
     MDI_CAMERA_IE_LEVEL_MEDIUM,
     MDI_CAMERA_IE_LEVEL_MEDIUM,
     MDI_CAMERA_IE_LEVEL_MEDIUM,
     MDI_CAMERA_IE_LEVEL_HIGH,
     MDI_CAMERA_IE_LEVEL_MEDIUM
    },
    {MDI_CAMERA_IE_LEVEL_LOW,
     MDI_CAMERA_IE_LEVEL_MEDIUM,
     MDI_CAMERA_IE_LEVEL_MEDIUM,
     MDI_CAMERA_IE_LEVEL_LOW,
     MDI_CAMERA_IE_LEVEL_MEDIUM,
     MDI_CAMERA_IE_LEVEL_HIGH,
     MDI_CAMERA_IE_LEVEL_MEDIUM
    },
};

// [AFrange / SharpnessSetting / ContrastSetting / SaturationSetting]
// [AUTO, NIGHT]
VfxU32 vdoSceneTable[4][VAPP_CAMCO_VDOSCENEMODE_END] =
{
    {MDI_CAMERA_AF_RANGE_AUTO,
     MDI_CAMERA_AF_RANGE_LANDSCAPE
    },
    {MDI_CAMERA_IE_LEVEL_LOW,
     MDI_CAMERA_IE_LEVEL_MEDIUM
    },
    {MDI_CAMERA_IE_LEVEL_MEDIUM,
     MDI_CAMERA_IE_LEVEL_MEDIUM
    },
    {MDI_CAMERA_IE_LEVEL_LOW,
     MDI_CAMERA_IE_LEVEL_MEDIUM
    },
};

VfxBool vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[VAPP_CAMCO_VISCODEC_END][VAPP_CAMCO_RECSIZE_END][VAPP_CAMCO_VISQTY_END][2];

#define VAPP_CAMCO_SETTING_CHECK \
    if(m_cap == (1 << VAPP_CAMCO_SETTING_STATUS_DRV_NOT_SUPPORT)) \
        return;

vapp_camco_setting_cap_enum CamcoSettingItem::getStatus(void)
{
    // recorder no need check capmode
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_RECORDER && IS_DISABLE(m_cap, VAPP_CAMCO_SETTING_STATUS_DISABLED_SD))
    {
        return VAPP_CAMCO_SETTING_CAP_ENABLED;
    }
    else if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_RECORDER && IS_DISABLE(m_cap, VAPP_CAMCO_SETTING_STATUS_DISABLED_ASD))
    {
        return VAPP_CAMCO_SETTING_CAP_ENABLED;
    }
    else if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_RECORDER && IS_DISABLE(m_cap, VAPP_CAMCO_SETTING_STATUS_DISABLED_ZSD))
    {
        return VAPP_CAMCO_SETTING_CAP_ENABLED;
    }
    else
    {
        if(IS_ENABLE(m_cap))
            return VAPP_CAMCO_SETTING_CAP_ENABLED;
        else if(IS_NOT_SUPPORT(m_cap))
            return VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
        else
            return VAPP_CAMCO_SETTING_CAP_DISABLED;
    }
}

void CamcoSettingItem::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    if(m_currentValue != 0xff)
        m_lastValue = m_currentValue;
    else
        m_lastValue = 0;
    m_currentValue = v;
    m_signalSettingModified.emit(m_settingType, v, m_lastValue);
}

void CamcoSettingItem::resetValue(VfxU16 v)
{
    m_currentValue = v;
}

void CamcoSettingItem::hide(vapp_camco_setting_enum setting)
{
    if(!IS_NOT_SUPPORT(m_cap))
        m_cap |= (1 << setting);
}

void CamcoSettingItem::show(vapp_camco_setting_enum setting)
{
    if(!IS_NOT_SUPPORT(m_cap))
        m_cap &= ~(1 << setting);
}

void CamcoSettingItem::setSettingBound(vapp_camco_setting_enum setting, VfxU16 start, VfxU16 end)
{
    for(VfxU16 i = 0; i < VAPP_CAMCO_MAX_SETTING_ITEM_COUNT;i++)
    {
        if(i >= start && i <= end)
        {
            m_content[i]->setStatus(setting, VAPP_CAMCO_SETTING_CAP_ENABLED);
        }
        else
        {
            m_content[i]->setStatus(setting, VAPP_CAMCO_SETTING_CAP_DISABLED);
        }
    }
}

void CamcoSettingItem::initialize(void)
{
    switch (m_settingType)
    {
        case VAPP_CAMCO_SETTING_CAMSCENEMODE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_CAMSCENEMODE);
            break;
        case VAPP_CAMCO_SETTING_CAPSIZE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_CAPSIZE);
            break;
        case VAPP_CAMCO_SETTING_FLASH:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_FLASH);
            break;
        case VAPP_CAMCO_SETTING_SELFTIMER:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_SELFTIMER);
            break;
        case VAPP_CAMCO_SETTING_ISO:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_ISO);
            break;
        case VAPP_CAMCO_SETTING_WB:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_WB);
            break;
        case VAPP_CAMCO_SETTING_EFFECT:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_EFFECT);
            break;
        case VAPP_CAMCO_SETTING_CAMSTORAGE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_CAMSTORAGE);
            break;
        case VAPP_CAMCO_SETTING_VDOSTORAGE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_VDOSTORAGE);
            break;
        case VAPP_CAMCO_SETTING_CAPQTY:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_CAPQTY);
            break;
        case VAPP_CAMCO_SETTING_VDOSCENEMODE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_VDOSCENEMODE);
            break;
        case VAPP_CAMCO_SETTING_RECSIZE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_RECSIZE);
            break;
        case VAPP_CAMCO_SETTING_TIMELAPSE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_TIME_LAPSE);
            break;
        case VAPP_CAMCO_SETTING_TIMELAPSEPERIOD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_TIME_LAPSE_PERIOD);
            break;
        case VAPP_CAMCO_SETTING_LIMIT:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_LIMIT);
            break;
        case VAPP_CAMCO_SETTING_VISQTY:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_VISQTY);
            break;
        case VAPP_CAMCO_SETTING_VISCODEC:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_VISCODEC);
            break;
        case VAPP_CAMCO_SETTING_CAMEV:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_CAMEV);
            break;
        case VAPP_CAMCO_SETTING_VDOEV:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_VDOEV);
            break;
        case VAPP_CAMCO_SETTING_CAMZOOM:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_CAMZOOM);
            break;
        case VAPP_CAMCO_SETTING_VDOZOOM:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_VDOZOOM);
            break;
        case VAPP_CAMCO_SETTING_SD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_SD);
            break;
        case VAPP_CAMCO_SETTING_ASD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_ASD);
            break;
        case VAPP_CAMCO_SETTING_ZSD:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_ZSD);
            break;
        case VAPP_CAMCO_SETTING_ACT_APP:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_ACT_APP);
            break;
        case VAPP_CAMCO_SETTING_ACT_CAM:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_INIT_ACT_CAM);
            break;
    }

    for(VfxU8 i =0; i < VAPP_CAMCO_MAX_SETTING_ITEM_COUNT;i++)
    {
        m_content[i]->initialize();
    }

    m_cap = NOT_SUPPORT();
    m_mainImgId = 0;
    m_mainStrId = 0;
    m_isHiliteMode = VFX_FALSE;
}

void CamcoSettingItem::setDefault(void)
{
    vapp_camco_cap_info cap_info;

    if (queryCapbilityInfo(&cap_info))
    {
        m_cap = ENABLE();
        for (VfxS32 idx = 0; idx < cap_info.item_count; idx++)
        {
            if (cap_info.support_item[idx] != VAPP_CAMCO_SETTING_DUMMY_VALUE)
            {
                m_content[cap_info.support_item[idx]]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                m_content[cap_info.support_item[idx]]->setValue(cap_info.support_item[idx]);
            }
        }
    }
    else
    {
        m_cap = NOT_SUPPORT();
    }

    switch (m_settingType)
    {
        case VAPP_CAMCO_SETTING_CAMSCENEMODE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_CAMSCENEMODE, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_CAPSIZE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_CAPSIZE, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_FLASH:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_FLASH, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_WB:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_WB, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_EFFECT:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_EFFECT, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_CAMSTORAGE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_CAMSTORAGE, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_VDOSTORAGE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_VDOSTORAGE, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_VDOSCENEMODE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_VDOSCENEMODE, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_RECSIZE:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_RECSIZE, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_VISQTY:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_VISQTY, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_VISCODEC:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_VISCODEC, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_CAMEV:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_CAMEV, m_currentValue);
            break;
        case VAPP_CAMCO_SETTING_VDOEV:
            MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_VDOEV, m_currentValue);
            break;
    }
}

MMI_BOOL CamcoSettingItem::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    return MMI_FALSE;
}

VfxU32 CamcoSettingItem::getMappingID(VfxU32 mmiID)
{
    return 0;
}

VfxU32 CamcoSettingItem::getMaxValue(void)
{
    return 0;
}

VfxU32 CamcoSettingItem::getMinValue(void)
{
    return 0;
}

VfxU32 CamcoSettingItem::getSettingCount(void)
{
    VfxU32 count = 0;
    for (VfxS32 idx = VAPP_CAMCO_MAX_SETTING_ITEM_COUNT - 1; idx >= 0; idx--)
    {
        if (m_content[idx]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
        {
            count++;
        }
    }
    return count;
}

void CamcoSettingItem::CheckandSet(VfxS32 value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_SETTING_CHECK_AND_SET_S, m_settingType, value, m_currentValue);

    if(value >= 0) //it mean a certain value is set
    {
        if(IS_NOT_SUPPORT(m_cap))
        {
            resetValue(value);
        }
        else
        {
            if (m_currentValue == 0xff || m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
            {
                setValue(value);
            }
        }
    }
    else //it mean to find a suitable value from current avaiable set
    {
        if (m_currentValue == 0xff || m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
        {

            for (VfxS16 idx = VAPP_CAMCO_MAX_SETTING_ITEM_COUNT - 1; idx >= 0; idx--)
            {
                if (m_content[idx]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
                {
                    setValue(idx);
                    break;
                }
            }
        }
        if(m_currentValue == 0xff)
        {
            setValue(0);
        }
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_SETTING_CHECK_AND_SET_E, m_currentValue);
}

void CamcoSettingItem::applyEffect(VfxU16 v)
{
}

void CamcoSettingItem::resetEffect(void)
{
}

void CamcoSettingItem::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_EXPRESS_SETTING_UPDATE, change_setting, change_value, last_value);
}

void ApplicationSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_ACT_APP;
}

void ApplicationSetting::setDefault(void)
{
    m_cap = ENABLE();

    m_content[VAPP_CAMCO_APP_CAMERA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_APP_RECORDER]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);

    m_content[VAPP_CAMCO_APP_CAMERA]->setValue(VAPP_CAMCO_APP_CAMERA);
    m_content[VAPP_CAMCO_APP_RECORDER]->setValue(VAPP_CAMCO_APP_RECORDER);

    if(m_settingMgr->IsExtSetting())
    {

        if(m_settingMgr->m_callingParam.mode == VCUI_CAMCO_CAMERA)
        {
            setValue(VAPP_CAMCO_APP_CAMERA);
            return;
        }
        else
        {
            setValue(VAPP_CAMCO_APP_RECORDER);
            return;
        }
    }
    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_ACT_APP, m_currentValue);

    CheckandSet(VAPP_CAMCO_APP_CAMERA);
}

void ApplicationSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);
}

void CameraSensorSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_ACT_CAM;
}

void CameraSensorSetting::setDefault(void)
{
    m_cap = ENABLE();

    m_content[VAPP_CAMCO_SENSOR_MAIN_CAMERA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SENSOR_MAIN_CAMERA]->setValue(VAPP_CAMCO_SENSOR_MAIN_CAMERA);
#if (defined(DUAL_CAMERA_SUPPORT))
    m_content[VAPP_CAMCO_SENSOR_SUB_CAMERA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SENSOR_SUB_CAMERA]->setValue(VAPP_CAMCO_SENSOR_SUB_CAMERA);
#else
    m_content[VAPP_CAMCO_SENSOR_SUB_CAMERA]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_ACT_CAM, m_currentValue);

    CheckandSet(VAPP_CAMCO_SENSOR_MAIN_CAMERA);
}

void CameraSensorSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    mdi_camera_set_camera_id(getMappingID(v));
    mdi_video_set_camera_id(getMappingID(v));
}

VfxU32 CameraSensorSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_SENSOR_MAIN_CAMERA:
            return MDI_CAMERA_MAIN;

        case VAPP_CAMCO_SENSOR_SUB_CAMERA:
            return MDI_CAMERA_SUB;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void CameraSensorSetting::setCameraID(VfxU16 camid)
{
    mdi_camera_set_camera_id(getMappingID(camid));
    mdi_video_set_camera_id(getMappingID(camid));
}

void SmileDetectSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_SD;

    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_CAPMODE_SMILE_SHOT;

    /* init item str id */
    m_content[VAPP_CAMCO_SMILE_DETECT_ON]->setStr(STR_GLOBAL_ON);
    m_content[VAPP_CAMCO_SMILE_DETECT_OFF]->setStr(STR_GLOBAL_OFF);

    m_content[VAPP_CAMCO_SMILE_DETECT_ON]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_SD_ICON);
}

void SmileDetectSetting::setDefault(void)
{
#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
    m_cap = ENABLE();

    m_content[VAPP_CAMCO_SMILE_DETECT_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SMILE_DETECT_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
#else
    m_cap = NOT_SUPPORT();

    m_content[VAPP_CAMCO_SMILE_DETECT_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SMILE_DETECT_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
#endif

    m_content[VAPP_CAMCO_SMILE_DETECT_ON]->setValue(VAPP_CAMCO_SMILE_DETECT_ON);
    m_content[VAPP_CAMCO_SMILE_DETECT_OFF]->setValue(VAPP_CAMCO_SMILE_DETECT_OFF);

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_SD, m_currentValue);

    CheckandSet(VAPP_CAMCO_SMILE_DETECT_OFF);
}

void SmileDetectSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);

    m_settingMgr->needRestartPreview();
}

void SmileDetectSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

#ifdef __MMI_CAMCO_FEATURE_CAM_SD_SHOT__
    if(change_setting == VAPP_CAMCO_SETTING_ACT_CAM)
    {
        if (m_settingMgr->IsExtSetting() || change_value == VAPP_CAMCO_SENSOR_SUB_CAMERA)
        {
            hide(VAPP_CAMCO_SETTING_ACT_CAM);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_ACT_CAM);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_ASD)
    {
        if(change_value == VAPP_CAMCO_SCENE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_SMILE_DETECT_OFF);
            hide(VAPP_CAMCO_SETTING_ASD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_ASD);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_ZSD)
    {
        if(change_value == VAPP_CAMCO_ZERO_DELAY_ON)
        {
            setValue(VAPP_CAMCO_SMILE_DETECT_OFF);
            hide(VAPP_CAMCO_SETTING_ZSD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_ZSD);
        }
    }
#endif
}

void ZeroDelaySetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_ZSD;

    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_CAPMODE_ZSD_SHOT;

    /* init item str id */
    m_content[VAPP_CAMCO_ZERO_DELAY_ON]->setStr(STR_GLOBAL_ON);
    m_content[VAPP_CAMCO_ZERO_DELAY_OFF]->setStr(STR_GLOBAL_OFF);

    m_content[VAPP_CAMCO_ZERO_DELAY_ON]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ZSD_ICON);
}

void ZeroDelaySetting::setDefault(void)
{
#ifdef __MMI_CAMCO_FEATURE_CAM_ZSD_SHOT__
    m_cap = ENABLE();

    m_content[VAPP_CAMCO_ZERO_DELAY_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_ZERO_DELAY_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
#else
    m_cap = NOT_SUPPORT();

    m_content[VAPP_CAMCO_ZERO_DELAY_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_ZERO_DELAY_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
#endif

    m_content[VAPP_CAMCO_ZERO_DELAY_ON]->setValue(VAPP_CAMCO_SMILE_DETECT_ON);
    m_content[VAPP_CAMCO_ZERO_DELAY_OFF]->setValue(VAPP_CAMCO_SMILE_DETECT_OFF);

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_ZSD, m_currentValue);

    CheckandSet(VAPP_CAMCO_ZERO_DELAY_OFF);
}

void ZeroDelaySetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);

    m_settingMgr->needRestartPreview();

#ifdef __MMI_CAMCO_FEATURE_CAM_ZSD_SHOT__
    // ==================================================================================================
    // query ZSD support size in addition
    // for some sensor, it mayy not support full size as normal shot
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        if(v == VAPP_CAMCO_ZERO_DELAY_ON)
        {
            for(VfxU32 idx = 0; idx < VAPP_CAMCO_CAPSIZE_END;idx++)
                vapp_camco_capmode_vs_capsize[idx] = VFX_FALSE;

            vapp_camco_cap_info zsd_size_cap_info;

            mdi_camera_query_support_info(MDI_CAMERA_SETTING_ZSD_CAPSIZE, &zsd_size_cap_info);

            if (!zsd_size_cap_info.is_support)
                return;

            ASSERT(zsd_size_cap_info.item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

            for (VfxU32 idx = 0; idx < zsd_size_cap_info.item_count; idx++)
            {
                VfxU16 item = zsd_size_cap_info.support_item[idx];
                switch (item)
                {
                    case MDI_CAMERA_CAP_SIZE_WALLPAPER:
                        vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPSIZE_WALLPAPER] = VFX_TRUE;
                        break;

                    case MDI_CAMERA_CAP_SIZE_VGA:
                        vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPSIZE_VGA] = VFX_TRUE;
                        break;

                    case MDI_CAMERA_CAP_SIZE_1M:
                        vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPSIZE_1MP] = VFX_TRUE;
                        break;

                    case MDI_CAMERA_CAP_SIZE_2M:
                        vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPSIZE_2MP] = VFX_TRUE;
                        break;

                    case MDI_CAMERA_CAP_SIZE_3M:
                        vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPSIZE_3MP] = VFX_TRUE;
                        break;

                    case MDI_CAMERA_CAP_SIZE_4M:
                        vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPSIZE_4MP] = VFX_TRUE;
                        break;

                    case MDI_CAMERA_CAP_SIZE_5M:
                        vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPSIZE_5MP] = VFX_TRUE;
                        break;
                }
            }
        }
        else
        {
            for(VfxU32 idx = 0; idx < VAPP_CAMCO_CAPSIZE_END;idx++)
                vapp_camco_capmode_vs_capsize[idx] = VFX_TRUE;
        }
    }
#endif
}

void ZeroDelaySetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

#ifdef __MMI_CAMCO_FEATURE_CAM_ZSD_SHOT__
    if(change_setting == VAPP_CAMCO_SETTING_ACT_CAM)
    {

        if (m_settingMgr->IsExtSetting() || change_value == VAPP_CAMCO_SENSOR_SUB_CAMERA)
        {
            hide(VAPP_CAMCO_SETTING_ACT_CAM);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_ACT_CAM);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_ASD)
    {
        if(change_value == VAPP_CAMCO_SCENE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_ZERO_DELAY_OFF);
            hide(VAPP_CAMCO_SETTING_ASD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_ASD);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_SD)
    {
        if(change_value == VAPP_CAMCO_SMILE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_ZERO_DELAY_OFF);
            hide(VAPP_CAMCO_SETTING_SD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_SD);
        }
    }
#endif
}

void SceneDetectSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_ASD;

    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_CAPMODE_ASD_SHOT;

    /* init item str id */
    m_content[VAPP_CAMCO_SCENE_DETECT_ON]->setStr(STR_GLOBAL_ON);
    m_content[VAPP_CAMCO_SCENE_DETECT_OFF]->setStr(STR_GLOBAL_OFF);

    m_content[VAPP_CAMCO_SCENE_DETECT_ON]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ASD_ICON);
}

void SceneDetectSetting::setDefault(void)
{
#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    m_cap = ENABLE();

    m_content[VAPP_CAMCO_SCENE_DETECT_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SCENE_DETECT_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
#else
    m_cap = NOT_SUPPORT();

    m_content[VAPP_CAMCO_SCENE_DETECT_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SCENE_DETECT_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
#endif

    m_content[VAPP_CAMCO_SCENE_DETECT_ON]->setValue(VAPP_CAMCO_SMILE_DETECT_ON);
    m_content[VAPP_CAMCO_SCENE_DETECT_OFF]->setValue(VAPP_CAMCO_SMILE_DETECT_OFF);

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_ASD, m_currentValue);

    CheckandSet(VAPP_CAMCO_SCENE_DETECT_OFF);
}

void SceneDetectSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);

    m_settingMgr->needRestartPreview();
}

void SceneDetectSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    if(change_setting == VAPP_CAMCO_SETTING_ZSD)
    {
        if(change_value == VAPP_CAMCO_ZERO_DELAY_ON)
        {
            setValue(VAPP_CAMCO_SCENE_DETECT_OFF);
            hide(VAPP_CAMCO_SETTING_ZSD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_ZSD);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_SD)
    {
        if(change_value == VAPP_CAMCO_SMILE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_SCENE_DETECT_OFF);
            hide(VAPP_CAMCO_SETTING_SD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_SD);
        }
    }
#endif
}

void CamSceneModeSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CAMSCENEMODE;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_SCENEMODE;

    /* init item str id */
    m_content[VAPP_CAMCO_CAMSCENEMODE_AUTO]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_AUTO);
    m_content[VAPP_CAMCO_CAMSCENEMODE_PORTRAIT]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_PORTRAIT);
    m_content[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_LANDSCAPE);
    m_content[VAPP_CAMCO_CAMSCENEMODE_NIGHT]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_NIGHT);
    m_content[VAPP_CAMCO_CAMSCENEMODE_SPORT]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_SPORT);
    m_content[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_DOCUMENT);
    m_content[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_ANTI_SHAKE);

    m_content[VAPP_CAMCO_CAMSCENEMODE_AUTO]->setStatusIcon(0);
    m_content[VAPP_CAMCO_CAMSCENEMODE_PORTRAIT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_SCN_MODE_PORTRAIT_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_SCN_MODE_VIEW_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_NIGHT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_SCN_MODE_NIGHT_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_SPORT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_SCN_MODE_SPORT_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_SCN_MODE_TEXT_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_SCN_MODE_ANTI_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_ASD_AUTO]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ASD_SHOT_AUTO_MODE_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_ASD_BACKLIGHT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ASD_SHOT_BACKLIGHT_MODE_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_ASD_BACKLIGHT_PORTRAIT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ASD_SHOT_BACKLIGHT_PORTRAIT_MODE_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_ASD_LANDSCAPE]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ASD_SHOT_LANDSCAPE_MODE_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_ASD_NIGHT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ASD_SHOT_NIGHT_MODE_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_ASD_NIGHT_PORTRAIT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ASD_SHOT_NIGHT_PORTRAIT_MODE_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_ASD_PORTRAIT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ASD_SHOT_PORTRAIT_MODE_ICON);
}

void CamSceneModeSetting::setDefault(void)
{
    CamcoSettingItem::setDefault();
    CheckandSet(VAPP_CAMCO_CAMSCENEMODE_AUTO);

    m_activeScene = VAPP_CAMCO_CAMSCENEMODE_ASD_AUTO;
}

void CamSceneModeSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_ASD)
    {
        if(change_value == VAPP_CAMCO_SCENE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_CAMSCENEMODE_AUTO);
            setActiveValue(MDI_CAMERA_SCENE_MODE_AUTO);
            hide(VAPP_CAMCO_SETTING_ASD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_ASD);
            setDefault();
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_SD)
    {
        if(change_value == VAPP_CAMCO_SMILE_DETECT_ON)
        {
            m_content[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE]->setStatus(VAPP_CAMCO_SETTING_SD, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_CAMSCENEMODE_NIGHT]->setStatus(VAPP_CAMCO_SETTING_SD, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_CAMSCENEMODE_SPORT]->setStatus(VAPP_CAMCO_SETTING_SD, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT]->setStatus(VAPP_CAMCO_SETTING_SD, VAPP_CAMCO_SETTING_CAP_DISABLED);

            if (m_currentValue != VAPP_CAMCO_CAMSCENEMODE_AUTO &&
                m_currentValue != VAPP_CAMCO_CAMSCENEMODE_PORTRAIT &&
                m_currentValue != VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
            {
                setValue(VAPP_CAMCO_CAMSCENEMODE_AUTO);
            }
        }
        else
        {
            setDefault();
        }
    }
}

VfxU16 CamSceneModeSetting::getValue(void)
{
    if(m_settingMgr->getValue(VAPP_CAMCO_SETTING_ASD) == VAPP_CAMCO_SCENE_DETECT_ON)
    {
        return m_activeScene;
    }
    else
    {
        return CamcoSettingItem::getValue();
    }
}

void CamSceneModeSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);

    if(m_lastValue != m_currentValue)
    {
        m_settingMgr->needRestartPreview();
    }
}

void CamSceneModeSetting::setActiveValue(VfxU16 v)
{
    switch (v)
    {
        case MDI_CAMERA_SCENE_MODE_AUTO:
            m_activeScene = VAPP_CAMCO_CAMSCENEMODE_ASD_AUTO;
            break;

        case MDI_CAMERA_SCENE_MODE_BACKLIGHT:
            m_activeScene = VAPP_CAMCO_CAMSCENEMODE_ASD_BACKLIGHT;
            break;

        case MDI_CAMERA_SCENE_MODE_BACKLIGHT_PORTRAIT:
            m_activeScene = VAPP_CAMCO_CAMSCENEMODE_ASD_BACKLIGHT_PORTRAIT;
            break;

        case MDI_CAMERA_SCENE_MODE_LANDSCAPE:
            m_activeScene = VAPP_CAMCO_CAMSCENEMODE_ASD_LANDSCAPE;
            break;

        case MDI_CAMERA_SCENE_MODE_NIGHT:
            m_activeScene = VAPP_CAMCO_CAMSCENEMODE_ASD_NIGHT;
            break;

        case MDI_CAMERA_SCENE_MODE_NIGHT_PORTRAIT:
            m_activeScene = VAPP_CAMCO_CAMSCENEMODE_ASD_NIGHT_PORTRAIT;
            break;

        case MDI_CAMERA_SCENE_MODE_PORTRAIT:
            m_activeScene = VAPP_CAMCO_CAMSCENEMODE_ASD_PORTRAIT;
            break;

        default:
            m_activeScene = VAPP_CAMCO_CAMSCENEMODE_AUTO;
            break;
    }
}

MMI_BOOL CamSceneModeSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());


    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAMSCENE, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_CAMSCENE, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (VfxU32 idx = 0; idx < cap_info->item_count; idx++)
    {
        VfxU16 item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_SCENE_MODE_AUTO:
                cap_info->support_item[idx] = VAPP_CAMCO_CAMSCENEMODE_AUTO;
                break;

            case MDI_CAMERA_SCENE_MODE_PORTRAIT:
                cap_info->support_item[idx] = VAPP_CAMCO_CAMSCENEMODE_PORTRAIT;
                break;

            case MDI_CAMERA_SCENE_MODE_LANDSCAPE:
                cap_info->support_item[idx] = VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE;
                break;

            case MDI_CAMERA_SCENE_MODE_SPORT:
                cap_info->support_item[idx] = VAPP_CAMCO_CAMSCENEMODE_SPORT;
                break;

            case MDI_CAMERA_SCENE_MODE_NIGHT:
                cap_info->support_item[idx] = VAPP_CAMCO_CAMSCENEMODE_NIGHT;
                break;

            case MDI_CAMERA_SCENE_MODE_DOCUMENT:
                cap_info->support_item[idx] = VAPP_CAMCO_CAMSCENEMODE_DOCUMENT;
                break;

            case MDI_CAMERA_SCENE_MODE_ISO_ANTI_HAND_SHAKE:
                cap_info->support_item[idx] = VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }
    return MMI_TRUE;
}

VfxU32 CamSceneModeSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_CAMSCENEMODE_AUTO:
            return MDI_CAMERA_SCENE_MODE_AUTO;

        case VAPP_CAMCO_CAMSCENEMODE_PORTRAIT:
            return MDI_CAMERA_SCENE_MODE_PORTRAIT;

        case VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE:
            return MDI_CAMERA_SCENE_MODE_LANDSCAPE;

        case VAPP_CAMCO_CAMSCENEMODE_SPORT:
            return MDI_CAMERA_SCENE_MODE_SPORT;

        case VAPP_CAMCO_CAMSCENEMODE_NIGHT:
            return MDI_CAMERA_SCENE_MODE_NIGHT;

        case VAPP_CAMCO_CAMSCENEMODE_DOCUMENT:
            return MDI_CAMERA_SCENE_MODE_DOCUMENT;

        case VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE:
            return MDI_CAMERA_SCENE_MODE_ISO_ANTI_HAND_SHAKE;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void CapSizeSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CAPSIZE;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_CAPSIZE;

    /* init item img id */
    m_content[VAPP_CAMCO_CAPSIZE_WALLPAPER]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_WALLPAPER);
    m_content[VAPP_CAMCO_CAPSIZE_VGA]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_VGA);
    m_content[VAPP_CAMCO_CAPSIZE_1MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_1MP);
    m_content[VAPP_CAMCO_CAPSIZE_2MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_2MP);
    m_content[VAPP_CAMCO_CAPSIZE_3MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_3MP);
    m_content[VAPP_CAMCO_CAPSIZE_4MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_4MP);
    m_content[VAPP_CAMCO_CAPSIZE_5MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_5MP);

    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_WALLPAPER].width = GDI_LCD_WIDTH;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_WALLPAPER].height = GDI_LCD_HEIGHT;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_VGA].width = 640;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_VGA].height = 480;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_1MP].width = 1280;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_1MP].height = 960;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_2MP].width = 1600;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_2MP].height = 1200;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_3MP].width = 2048;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_3MP].height = 1536;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_4MP].width = 2304;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_4MP].height = 1728;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_5MP].width = 2592;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_5MP].height = 1944;
}

void CapSizeSetting::setDefault(void)
{
    CamcoSettingItem::setDefault();

    // ext calling config
    if(m_settingMgr->IsExtSetting())
    {
        VfxS32 marker = -1;

        for(VfxU32 i = 0; i < m_settingMgr->m_callingParam.settingLimitNum; i++)
        {
            if(m_settingMgr->m_callingParam.settingLimitation[i].type == VCUI_CAMCO_SETTING_LIMIT_CAPSIZE)
            {
                if(m_settingMgr->m_callingParam.settingLimitation[i].detail == VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_WP_ONLY)
                {
                    for(VfxU32 i = 0; i < VAPP_CAMCO_CAPSIZE_END; i++)
                    {
                        if(i != VAPP_CAMCO_CAPSIZE_WALLPAPER)
                            m_content[i]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
                        ASSERT(m_content[VAPP_CAMCO_CAPSIZE_WALLPAPER]->getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
                    }
                    break;
                }
                else
                {
                    marker = m_settingMgr->m_callingParam.settingLimitation[i].detail - VCUI_CAMCO_SETTING_LIMIT_CAPSIZE_BELOW_WALLPAPER;
                }
                break;
            }
        }
        if(marker != -1)
        {
            for(VfxU32 i = marker + 1; i < VAPP_CAMCO_CAPSIZE_END; i++)
            {
                m_content[i]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
            }
        }
    }
    CheckandSet(-1);
}

void CapSizeSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_ZSD)
    {
        setDefault();
        if (change_value == VAPP_CAMCO_ZERO_DELAY_ON)
        {
            config_capsize_capability();

            if(m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
            {
                VfxS32 i;
                for(i = VAPP_CAMCO_CAPSIZE_END - 1; i >= 0; i--)
                {
                    if(m_content[i]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
                    {
                        setValue(i);
                        break;
                    }
                }
                ASSERT(i >= 0);
            }
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_ISO)
    {
        ISOSetting *ISO;
        m_settingMgr->getSetting(VAPP_CAMCO_SETTING_ISO, (CamcoSettingItem**)&ISO);

        if(ISO->getStatus() == VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
            return;

        if (ISO->iso_binning.IsoBinningInfo[change_value].BinningEnable)
        {
            U16 upperbound_capsize = 0;


            ISO->is_current_iso_binning = MMI_TRUE;

            upperbound_capsize = ISO->iso_binning.IsoBinningInfo[change_value].MaxResolution;

            if (m_currentValue > mdi_vs_mmi_capsize[upperbound_capsize])
            {
                setValue(mdi_vs_mmi_capsize[upperbound_capsize]);
            }
        }
        else
        {
            ISO->is_current_iso_binning = MMI_FALSE;
        }
        config_capsize_capability();
    }
    else if(change_setting == VAPP_CAMCO_SETTING_ACT_CAM)
    {
        config_capsize_capability();
    }
}

void CapSizeSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    // update image size and zoom cap before set value
    // because set value will triger update zoom by signal directly using old size
    U16 image_width, image_height;
    getMappingSize(v, &image_width, &image_height);
    mdi_camera_update_para_image_size(image_width, image_height);
    mdi_camera_update_para_zoom(0);

    CamcoSettingItem::setValue(v);

    m_settingMgr->needRestartPreview();
}

MMI_BOOL CapSizeSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    // use ext-struct to query capture size capability
    // ============================================================
    mdi_camera_sensor_capture_resolution_info cap_info_ex, *cap_info_p;
    cap_info_p = &cap_info_ex;
    // ============================================================

    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAPSIZE_WITH_DIMENSION, cap_info_p);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_CAPSIZE, cap_info_p);

    // copy to input struct
    // ============================================================
    cap_info->is_support = cap_info_p->is_support;
    cap_info->item_count = cap_info_p->item_count;
    for(VfxU32 i = 0; i < CAMERA_SUPPORT_ITEM_MAX_NO; i++)
    {
        cap_info->support_item[i] = cap_info_p->support_item[i];
    }
    // ============================================================

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (VfxU32 idx = 0; idx < cap_info->item_count; idx++)
    {
        VfxU16 item = cap_info->support_item[idx];
        VfxU32 current_size = VAPP_CAMCO_CAPSIZE_WALLPAPER;

        switch (item)
        {
            case MDI_CAMERA_CAP_SIZE_WALLPAPER:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPSIZE_WALLPAPER;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_WALLPAPER] = VAPP_CAMCO_CAPSIZE_WALLPAPER;
                break;

            case MDI_CAMERA_CAP_SIZE_VGA:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPSIZE_VGA;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_VGA] = VAPP_CAMCO_CAPSIZE_VGA;
                current_size = VAPP_CAMCO_CAPSIZE_VGA;
                break;

            case MDI_CAMERA_CAP_SIZE_1M:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPSIZE_1MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_1M] = VAPP_CAMCO_CAPSIZE_1MP;
                current_size = VAPP_CAMCO_CAPSIZE_1MP;
                break;

            case MDI_CAMERA_CAP_SIZE_2M:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPSIZE_2MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_2M] = VAPP_CAMCO_CAPSIZE_2MP;
                current_size = VAPP_CAMCO_CAPSIZE_2MP;
                break;
/*   50 will not support in normal case
            case MDI_CAMERA_CAP_SIZE_3M:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPSIZE_3MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_3M] = VAPP_CAMCO_CAPSIZE_3MP;
                current_size = VAPP_CAMCO_CAPSIZE_3MP;
                break;

            case MDI_CAMERA_CAP_SIZE_4M:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPSIZE_4MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_4M] = VAPP_CAMCO_CAPSIZE_4MP;
                current_size = VAPP_CAMCO_CAPSIZE_4MP;
                break;

            case MDI_CAMERA_CAP_SIZE_5M:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPSIZE_5MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_5M] = VAPP_CAMCO_CAPSIZE_5MP;
                current_size = VAPP_CAMCO_CAPSIZE_5MP;
                break;
*/
            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }

        // update size mapping
        // ============================================================
        if(current_size != VAPP_CAMCO_CAPSIZE_WALLPAPER)
        {
            if((mdi_real_capture_size[current_size].width != cap_info_p->image_size[idx].image_width) ||
               (mdi_real_capture_size[current_size].height != cap_info_p->image_size[idx].image_height))
            {
               mdi_real_capture_size[current_size].width = cap_info_p->image_size[idx].image_width;
               mdi_real_capture_size[current_size].height = cap_info_p->image_size[idx].image_height;
            }
        }
        // ============================================================
    }
    return MMI_TRUE;
}

VfxU32 CapSizeSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_CAPSIZE_WALLPAPER:
            return MDI_CAMERA_CAP_SIZE_WALLPAPER;

        case VAPP_CAMCO_CAPSIZE_VGA:
            return MDI_CAMERA_CAP_SIZE_VGA;

        case VAPP_CAMCO_CAPSIZE_1MP:
            return MDI_CAMERA_CAP_SIZE_1M;

        case VAPP_CAMCO_CAPSIZE_2MP:
            return MDI_CAMERA_CAP_SIZE_2M;

        case VAPP_CAMCO_CAPSIZE_3MP:
            return MDI_CAMERA_CAP_SIZE_3M;

        case VAPP_CAMCO_CAPSIZE_4MP:
            return MDI_CAMERA_CAP_SIZE_4M;

        case VAPP_CAMCO_CAPSIZE_5MP:
            return MDI_CAMERA_CAP_SIZE_5M;

    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void CapSizeSetting::getMappingSize(VfxU32 mmiID, U16 *width_p, U16 *height_p)
{
#if defined(__JPEG_SENSOR_SUPPORT__)

    *width_p = mdi_real_capture_size[mmiID].width ;
    *height_p = mdi_real_capture_size[mmiID].height;

#else

#if( (GDI_LCD_WIDTH == 480) && (GDI_LCD_HEIGHT == 800) )
    #define W  (5)
    #define H  (3)
#elif( (GDI_LCD_WIDTH == 320) && (GDI_LCD_HEIGHT == 480) )
    #define W  (3)
    #define H  (2)
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 400) )
    #define W  (5)
    #define H  (3)
#elif( (GDI_LCD_WIDTH == 240) && (GDI_LCD_HEIGHT == 320) )
    #define W  (4)
    #define H  (3)
#else
    #define W  (4)
    #define H  (3)
#endif

    switch (mmiID)
    {
        case VAPP_CAMCO_CAPSIZE_WALLPAPER:
            *width_p = GDI_LCD_WIDTH;
            *height_p = GDI_LCD_HEIGHT;
            break;

        case VAPP_CAMCO_CAPSIZE_VGA:
            *width_p = 640;
            *height_p = (640*H)/W;;
            break;

        case VAPP_CAMCO_CAPSIZE_1MP:
            *width_p = 1280;
            *height_p = (1280*H)/W;
            break;

        case VAPP_CAMCO_CAPSIZE_2MP:
            *width_p = 1600;
            *height_p = (1600*H)/W;
            break;

        case VAPP_CAMCO_CAPSIZE_3MP:
            *width_p = 2048;
            *height_p = (2048*H)/W;
            break;

        case VAPP_CAMCO_CAPSIZE_4MP:
            *width_p = 2304;
            *height_p = (2304*H)/W;
            break;

        case VAPP_CAMCO_CAPSIZE_5MP:
            *width_p = 2592;
            *height_p = (2592*H)/W;
            break;

        default:
            *width_p = GDI_LCD_WIDTH;
            *height_p = GDI_LCD_HEIGHT;
            break;
    }

    // make sure size is 2x size
    if((*height_p % 2))
    {
        (*height_p)--;
    }
#endif
}

void CapSizeSetting::config_capsize_capability(void)
{
    ISOSetting * ISO_p;
    VfxU16 ISOValue;
    VfxBool is_capsize_support;

    m_settingMgr->getSetting(VAPP_CAMCO_SETTING_ISO, (CamcoSettingItem**)&ISO_p);
    ISOValue = ISO_p->getValue();

    for (VfxS8 idx = 0; idx < VAPP_CAMCO_CAPSIZE_END; idx++)
    {
        if (getItem(idx).getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            if(ISO_p->getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
            {
                if (!ISO_p->iso_binning.IsoBinningInfo[ISOValue].BinningEnable)
                {
                    is_capsize_support = vapp_camco_capmode_vs_capsize[idx];
                }
                else
                {
                    is_capsize_support = vapp_camco_capmode_vs_capsize[idx] & ISO_p->vapp_camco_isobinning_vs_capsize[ISOValue][idx];
                }
            }
            else
            {
                is_capsize_support = vapp_camco_capmode_vs_capsize[idx];
            }

            if (is_capsize_support)
            {
                m_content[idx]->setStatus(VAPP_CAMCO_SETTING_CAPSIZE, VAPP_CAMCO_SETTING_CAP_ENABLED);
            }
            else
            {
                m_content[idx]->setStatus(VAPP_CAMCO_SETTING_CAPSIZE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            }
        }
    }
}

void FlashSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_FLASH;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_FLASH;

    /* init item str id */
    m_content[VAPP_CAMCO_FLASH_AUTO]->setStr(STR_ID_VAPP_CAMCO_FLASH_AUTO);
    m_content[VAPP_CAMCO_FLASH_OFF]->setStr(STR_GLOBAL_OFF);
    m_content[VAPP_CAMCO_FLASH_FORCE_ON]->setStr(STR_ID_VAPP_CAMCO_FLASH_FORCE_ON);
    m_content[VAPP_CAMCO_FLASH_RED_EYE]->setStr(STR_ID_VAPP_CAMCO_FLASH_RED_EYE);

    /* init item img id */
    m_content[VAPP_CAMCO_FLASH_AUTO]->setImg(IMG_ID_VAPP_CAMCO_FLASH_AUTO_ICON);
    m_content[VAPP_CAMCO_FLASH_OFF]->setImg(IMG_ID_VAPP_CAMCO_FLASH_OFF_ICON);
    m_content[VAPP_CAMCO_FLASH_FORCE_ON]->setImg(IMG_ID_VAPP_CAMCO_FLASH_FORCE_ON_ICON);
    m_content[VAPP_CAMCO_FLASH_RED_EYE]->setImg(IMG_ID_VAPP_CAMCO_FLASH_REDEYE_ICON);
}

void FlashSetting::setDefault(void)
{
#if defined(__MTK_INTERNAL__) && !defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
#else
#if defined(LED_FLASHLIGHT_SUPPORT)
    flash_type = VAPP_CAMCO_FLASH_TYPE_LED;
    m_cap = ENABLE();
#else
    flash_type = VAPP_CAMCO_FLASH_TYPE_NONE;
    m_cap = NOT_SUPPORT();
#endif
#endif
    if (flash_type != VAPP_CAMCO_FLASH_TYPE_NONE)
    {
        CamcoSettingItem::setDefault();
        CheckandSet(VAPP_CAMCO_FLASH_AUTO);
    }
}

void FlashSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_SD)
    {
        if(change_value == VAPP_CAMCO_SMILE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_FLASH_OFF);
            hide(VAPP_CAMCO_SETTING_SD);
        }
        else
        {
            setValue(VAPP_CAMCO_FLASH_AUTO);
            show(VAPP_CAMCO_SETTING_SD);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_ZSD)
    {
        if(change_value == VAPP_CAMCO_ZERO_DELAY_ON)
        {
            setValue(VAPP_CAMCO_FLASH_OFF);
            hide(VAPP_CAMCO_SETTING_ZSD);
        }
        else
        {
            setValue(VAPP_CAMCO_FLASH_AUTO);
            show(VAPP_CAMCO_SETTING_ZSD);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_CAMSCENEMODE)
    {
        if(change_value == VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE || change_value == VAPP_CAMCO_CAMSCENEMODE_SPORT)
        {
            setValue(VAPP_CAMCO_FLASH_OFF);
            hide(VAPP_CAMCO_SETTING_CAMSCENEMODE);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_CAMSCENEMODE);
        }
    }
}

void FlashSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);

    mdi_camera_update_para_flash(getMappingID(v));
}

MMI_BOOL FlashSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_FLASH, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_FLASH, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

#if defined(__MTK_INTERNAL__) && !defined(__MTK_TARGET__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (VfxU32 idx = 0; idx < cap_info->item_count; idx++)
    {
        VfxU16 item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_FLASH_OFF:
                cap_info->support_item[idx] = VAPP_CAMCO_FLASH_OFF;
                break;

            case MDI_CAMERA_FLASH_ON:
                cap_info->support_item[idx] = VAPP_CAMCO_FLASH_FORCE_ON;
                break;

            case MDI_CAMERA_FLASH_AUTO:
                cap_info->support_item[idx] = VAPP_CAMCO_FLASH_AUTO;
                break;

            case MDI_CAMERA_FLASH_REDEYE:
                cap_info->support_item[idx] = VAPP_CAMCO_FLASH_RED_EYE;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }
    return MMI_TRUE;
}

VfxU32 FlashSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_FLASH_AUTO:
            return MDI_CAMERA_FLASH_AUTO;

        case VAPP_CAMCO_FLASH_OFF:
            return MDI_CAMERA_FLASH_OFF;

        case VAPP_CAMCO_FLASH_FORCE_ON:
            return MDI_CAMERA_FLASH_ON;

        case VAPP_CAMCO_FLASH_RED_EYE:
            return MDI_CAMERA_FLASH_REDEYE;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void SelfTimerSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_SELFTIMER;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_SELFTIMER;

    /* init item img id */
    m_content[VAPP_CAMCO_SELFTIMER_OFF]->setStr(STR_GLOBAL_OFF);
    m_content[VAPP_CAMCO_SELFTIMER_5_SEC]->setStr(STR_ID_VAPP_CAMCO_SELFTIMER_5S);
    m_content[VAPP_CAMCO_SELFTIMER_10_SEC]->setStr(STR_ID_VAPP_CAMCO_SELFTIMER_10S);

    m_content[VAPP_CAMCO_SELFTIMER_OFF]->setStatusIcon(0);
    m_content[VAPP_CAMCO_SELFTIMER_5_SEC]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_TIMER_5S_ICON);
    m_content[VAPP_CAMCO_SELFTIMER_10_SEC]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_TIMER_10S_ICON);
}

void SelfTimerSetting::setDefault(void)
{
    /* init capability */
    m_cap = ENABLE();
    m_content[VAPP_CAMCO_SELFTIMER_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SELFTIMER_5_SEC]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SELFTIMER_10_SEC]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SELFTIMER_OFF]->setValue(VAPP_CAMCO_SELFTIMER_OFF);
    m_content[VAPP_CAMCO_SELFTIMER_5_SEC]->setValue(VAPP_CAMCO_SELFTIMER_5_SEC);
    m_content[VAPP_CAMCO_SELFTIMER_10_SEC]->setValue(VAPP_CAMCO_SELFTIMER_10_SEC);

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_SELFTIMER, m_currentValue);

    CheckandSet(VAPP_CAMCO_SELFTIMER_OFF);
}

void SelfTimerSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_SD)
    {
        if (change_value == VAPP_CAMCO_SMILE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_SELFTIMER_OFF);
            hide(VAPP_CAMCO_SETTING_SD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_SD);
        }
    }
}

void SelfTimerSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);
}

void ISOSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_ISO;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_ISO;

    /* init item img id */
    m_content[VAPP_CAMCO_ISO_AUTO]->setStr(STR_ID_VAPP_CAMCO_ISO_AUTO);
    m_content[VAPP_CAMCO_ISO_100]->setStr(STR_ID_VAPP_CAMCO_ISO_100);
    m_content[VAPP_CAMCO_ISO_200]->setStr(STR_ID_VAPP_CAMCO_ISO_200);
    m_content[VAPP_CAMCO_ISO_400]->setStr(STR_ID_VAPP_CAMCO_ISO_400);
    m_content[VAPP_CAMCO_ISO_800]->setStr(STR_ID_VAPP_CAMCO_ISO_800);
    m_content[VAPP_CAMCO_ISO_1600]->setStr(STR_ID_VAPP_CAMCO_ISO_1600);
}

void ISOSetting::setDefault(void)
{
    vapp_camco_cap_info cap_info;

    if (queryCapbilityInfo(&cap_info))
    {
        m_cap = ENABLE();
    }
    else
    {
        m_cap = NOT_SUPPORT();
    }

    getIsoBinning();

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_ISO, m_currentValue);

    CheckandSet(VAPP_CAMCO_ISO_AUTO);
}

void ISOSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_ASD)
    {
        if(change_value == VAPP_CAMCO_SCENE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_ISO_AUTO);
            hide(VAPP_CAMCO_SETTING_ASD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_ASD);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_CAMSCENEMODE)
    {
        if(change_value != VAPP_CAMCO_CAMSCENEMODE_AUTO)
        {
            setValue(VAPP_CAMCO_ISO_AUTO);
            hide(VAPP_CAMCO_SETTING_CAMSCENEMODE);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_CAMSCENEMODE);
        }
    }
}

void ISOSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);

    m_isHiliteMode = VFX_FALSE;
    m_settingMgr->needRestartPreview();
}

void ISOSetting::getIsoBinning(void)
{
    for (VfxU32 i = 0; i < VAPP_CAMCO_ISO_END; i++)
    {
        for (VfxU32 j = 0; j < VAPP_CAMCO_CAPSIZE_END; j++)
        {
            vapp_camco_isobinning_vs_capsize[i][j] = MMI_TRUE;
        }
    }

    for (VfxU32 i = 0; i < VAPP_CAMCO_ISO_END; i++)
    {
        if (iso_binning.IsoBinningInfo[i].BinningEnable)
        {
            U16 mdi_capsize = iso_binning.IsoBinningInfo[i].MaxResolution;

            CapSizeSetting * CapSize_p;
            m_settingMgr->getSetting(VAPP_CAMCO_SETTING_CAPSIZE, (CamcoSettingItem**)&CapSize_p);

            vapp_camco_capsize_enum cap_size = (vapp_camco_capsize_enum)CapSize_p->mdi_vs_mmi_capsize[mdi_capsize];

            for (VfxU32 j = cap_size + 1; j < VAPP_CAMCO_CAPSIZE_END; j++)
            {
                vapp_camco_isobinning_vs_capsize[i][j] = MMI_FALSE;
            }
        }
    }
}

MMI_BOOL ISOSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_ISO, &iso_binning);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_ISO, &iso_binning);

    if (!iso_binning.IsoBinningInfo[MDI_CAMERA_ISO_AUTO].IsoSupported)
    {
        return MMI_FALSE;
    }

    for (VfxU32 idx = 0; idx < MDI_CAMERA_ISO_COUNT; idx++)
    {
        vapp_camco_setting_cap_enum cap_value = VAPP_CAMCO_SETTING_CAP_DISABLED;
        vapp_camco_iso_enum iso = VAPP_CAMCO_ISO_AUTO;

        if (iso_binning.IsoBinningInfo[idx].IsoSupported)
        {
            cap_value = VAPP_CAMCO_SETTING_CAP_ENABLED;
        }

        switch (idx)
        {
            case MDI_CAMERA_ISO_AUTO:
                iso = VAPP_CAMCO_ISO_AUTO;
                break;

            case MDI_CAMERA_ISO_100:
                iso = VAPP_CAMCO_ISO_100;
                break;

            case MDI_CAMERA_ISO_200:
                iso = VAPP_CAMCO_ISO_200;
                break;

            case MDI_CAMERA_ISO_400:
                iso = VAPP_CAMCO_ISO_400;
                break;
            case MDI_CAMERA_ISO_800:
                iso = VAPP_CAMCO_ISO_800;
                break;

            case MDI_CAMERA_ISO_1600:
                iso = VAPP_CAMCO_ISO_1600;
                break;
            default:
                break;
        }

        m_content[iso]->setStatus(cap_value);
        m_content[iso]->setValue(iso);
    }

    return MMI_TRUE;
}

VfxU32 ISOSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_ISO_AUTO:
            return MDI_CAMERA_ISO_AUTO;

        case VAPP_CAMCO_ISO_100:
            return MDI_CAMERA_ISO_100;

        case VAPP_CAMCO_ISO_200:
            return MDI_CAMERA_ISO_200;

        case VAPP_CAMCO_ISO_400:
            return MDI_CAMERA_ISO_400;

        case VAPP_CAMCO_ISO_800:
            return MDI_CAMERA_ISO_800;

        case VAPP_CAMCO_ISO_1600:
            return MDI_CAMERA_ISO_1600;

    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void ISOSetting::applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;
}

void ISOSetting::resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
    }
}

void WBSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_WB;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_WB;

    /* init item str id */
    m_content[VAPP_CAMCO_WB_AUTO]->setStr(STR_ID_VAPP_CAMCO_WB_AUTO);
    m_content[VAPP_CAMCO_WB_DAYLIGHT]->setStr(STR_ID_VAPP_CAMCO_WB_DAYLIGHT);
    m_content[VAPP_CAMCO_WB_TUNGSTEN]->setStr(STR_ID_VAPP_CAMCO_WB_TUNGSTEN);
    m_content[VAPP_CAMCO_WB_FLUORESCENT]->setStr(STR_ID_VAPP_CAMCO_WB_FLUORESCENT);
    m_content[VAPP_CAMCO_WB_CLOUDY]->setStr(STR_ID_VAPP_CAMCO_WB_CLOUDY);
    m_content[VAPP_CAMCO_WB_INCANDESCENT]->setStr(STR_ID_VAPP_CAMCO_WB_INCANDESCENT);
}

void WBSetting::setDefault(void)
{
    CamcoSettingItem::setDefault();

    CheckandSet(VAPP_CAMCO_WB_AUTO);
}

void WBSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_ASD)
    {
        if(change_value == VAPP_CAMCO_SCENE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_WB_AUTO);
            hide(VAPP_CAMCO_SETTING_ASD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_ASD);
        }
    }
}

void WBSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);

    m_isHiliteMode = VFX_FALSE;

    if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        mdi_camera_update_para_wb(getMappingID(v));
    }
    else if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_RECORDER)
    {
        mdi_video_rec_update_para_wb(getMappingID(v));
    }
}

MMI_BOOL WBSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_WB, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_CAMERA_SETTING_WB, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (VfxU32 idx = 0; idx < cap_info->item_count; idx++)
    {
        VfxU16 item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_WB_AUTO:
                cap_info->support_item[idx] = VAPP_CAMCO_WB_AUTO;
                break;

            case MDI_CAMERA_WB_DAYLIGHT:
                cap_info->support_item[idx] = VAPP_CAMCO_WB_DAYLIGHT;
                break;

            case MDI_CAMERA_WB_TUNGSTEN:
                cap_info->support_item[idx] = VAPP_CAMCO_WB_TUNGSTEN;
                break;

            case MDI_CAMERA_WB_FLUORESCENT:
                cap_info->support_item[idx] = VAPP_CAMCO_WB_FLUORESCENT;
                break;

            case MDI_CAMERA_WB_CLOUD:
                cap_info->support_item[idx] = VAPP_CAMCO_WB_CLOUDY;
                break;

            case MDI_CAMERA_WB_INCANDESCENCE:
                cap_info->support_item[idx] = VAPP_CAMCO_WB_INCANDESCENT;
                break;

            case MDI_CAMERA_WB_MANUAL:
                cap_info->support_item[idx] = VAPP_CAMCO_WB_AUTO;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }
    return MMI_TRUE;
}

VfxU32 WBSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_WB_AUTO:
            return MDI_CAMERA_WB_AUTO;

        case VAPP_CAMCO_WB_DAYLIGHT:
            return MDI_CAMERA_WB_DAYLIGHT;

        case VAPP_CAMCO_WB_TUNGSTEN:
            return MDI_CAMERA_WB_TUNGSTEN;

        case VAPP_CAMCO_WB_FLUORESCENT:
            return MDI_CAMERA_WB_FLUORESCENT;

        case VAPP_CAMCO_WB_CLOUDY:
            return MDI_CAMERA_WB_CLOUD;

        case VAPP_CAMCO_WB_INCANDESCENT:
            return MDI_CAMERA_WB_INCANDESCENCE;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void WBSetting::applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
    {
        mdi_camera_update_para_wb(getMappingID(v));
    }
    else if (m_settingMgr->getCurrCam()  == VAPP_CAMCO_APP_RECORDER)
    {
        mdi_video_rec_update_para_wb(getMappingID(v));
    }
}

void WBSetting::resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
        {
            mdi_camera_update_para_wb(getMappingID(m_currentValue));
        }
        else if (m_settingMgr->getCurrCam()  == VAPP_CAMCO_APP_RECORDER)
        {
            mdi_video_rec_update_para_wb(getMappingID(m_currentValue));
        }
    }
}

void EffectSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_EFFECT;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_EFFECT;

    /* init item str id */
    m_content[VAPP_CAMCO_EFFECT_NORMAL]->setStr(STR_GLOBAL_NORMAL);
    m_content[VAPP_CAMCO_EFFECT_GRAYSCALE]->setStr(STR_ID_VAPP_CAMCO_EFFECT_GRAYSCALE);
    m_content[VAPP_CAMCO_EFFECT_SEPIA]->setStr(STR_ID_VAPP_CAMCO_EFFECT_SEPIA);
    m_content[VAPP_CAMCO_EFFECT_COLOR_INVERT]->setStr(STR_ID_VAPP_CAMCO_EFFECT_COLOR_INVERT);
    m_content[VAPP_CAMCO_EFFECT_SKETCH]->setStr(STR_ID_VAPP_CAMCO_EFFECT_SKETCH);
    m_content[VAPP_CAMCO_EFFECT_OIL]->setStr(STR_ID_VAPP_CAMCO_EFFECT_OIL);
    m_content[VAPP_CAMCO_EFFECT_LOMO]->setStr(STR_ID_VAPP_CAMCO_EFFECT_LOMO);
    m_content[VAPP_CAMCO_EFFECT_COLOR_RED]->setStr(STR_ID_VAPP_CAMCO_EFFECT_COLOR_RED);
    m_content[VAPP_CAMCO_EFFECT_COLOR_YELLOW]->setStr(STR_ID_VAPP_CAMCO_EFFECT_COLOR_YELLOW);
    m_content[VAPP_CAMCO_EFFECT_COLOR_GREEN]->setStr(STR_ID_VAPP_CAMCO_EFFECT_COLOR_GREEN);
    m_content[VAPP_CAMCO_EFFECT_COLOR_BLUE]->setStr(STR_ID_VAPP_CAMCO_EFFECT_COLOR_BLUE);

    /* init item img id */
    m_content[VAPP_CAMCO_EFFECT_NORMAL]->setImg(IMG_ID_VAPP_CAMCO_EFFECT1_ICON);
    m_content[VAPP_CAMCO_EFFECT_GRAYSCALE]->setImg(IMG_ID_VAPP_CAMCO_EFFECT2_ICON);
    m_content[VAPP_CAMCO_EFFECT_SEPIA]->setImg(IMG_ID_VAPP_CAMCO_EFFECT3_ICON);
    m_content[VAPP_CAMCO_EFFECT_COLOR_INVERT]->setImg(IMG_ID_VAPP_CAMCO_EFFECT4_ICON);
    m_content[VAPP_CAMCO_EFFECT_SKETCH]->setImg(IMG_ID_VAPP_CAMCO_EFFECT5_ICON);
    m_content[VAPP_CAMCO_EFFECT_OIL]->setImg(IMG_ID_VAPP_CAMCO_EFFECT6_ICON);
    m_content[VAPP_CAMCO_EFFECT_LOMO]->setImg(IMG_ID_VAPP_CAMCO_EFFECT7_ICON);
    m_content[VAPP_CAMCO_EFFECT_COLOR_RED]->setImg(IMG_ID_VAPP_CAMCO_EFFECT8_ICON);
    m_content[VAPP_CAMCO_EFFECT_COLOR_YELLOW]->setImg(IMG_ID_VAPP_CAMCO_EFFECT9_ICON);
    m_content[VAPP_CAMCO_EFFECT_COLOR_GREEN]->setImg(IMG_ID_VAPP_CAMCO_EFFECT10_ICON);
    m_content[VAPP_CAMCO_EFFECT_COLOR_BLUE]->setImg(IMG_ID_VAPP_CAMCO_EFFECT11_ICON);
}

void EffectSetting::setDefault(void)
{
    CamcoSettingItem::setDefault();
    CheckandSet(VAPP_CAMCO_EFFECT_NORMAL);
}

void EffectSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_SD)
    {
        if(change_value == VAPP_CAMCO_SMILE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_EFFECT_NORMAL);
            hide(VAPP_CAMCO_SETTING_SD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_SD);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_ASD)
    {
        if(change_value == VAPP_CAMCO_SCENE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_EFFECT_NORMAL);
            hide(VAPP_CAMCO_SETTING_ASD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_ASD);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_ZSD)
    {
        if(change_value == VAPP_CAMCO_ZERO_DELAY_ON)
        {
            if(m_currentValue == VAPP_CAMCO_EFFECT_LOMO ||
               m_currentValue == VAPP_CAMCO_EFFECT_COLOR_RED ||
               m_currentValue == VAPP_CAMCO_EFFECT_COLOR_YELLOW ||
               m_currentValue == VAPP_CAMCO_EFFECT_COLOR_GREEN ||
               m_currentValue == VAPP_CAMCO_EFFECT_COLOR_BLUE)
            {
                setValue(VAPP_CAMCO_EFFECT_NORMAL);
            }
            m_content[VAPP_CAMCO_EFFECT_LOMO]->setStatus(VAPP_CAMCO_SETTING_ZSD, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_EFFECT_COLOR_RED]->setStatus(VAPP_CAMCO_SETTING_ZSD, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_EFFECT_COLOR_YELLOW]->setStatus(VAPP_CAMCO_SETTING_ZSD, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_EFFECT_COLOR_GREEN]->setStatus(VAPP_CAMCO_SETTING_ZSD, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_EFFECT_COLOR_BLUE]->setStatus(VAPP_CAMCO_SETTING_ZSD, VAPP_CAMCO_SETTING_CAP_DISABLED);
        }
        else
        {
            m_content[VAPP_CAMCO_EFFECT_LOMO]->setStatus(VAPP_CAMCO_SETTING_ZSD, VAPP_CAMCO_SETTING_CAP_ENABLED);
            m_content[VAPP_CAMCO_EFFECT_COLOR_RED]->setStatus(VAPP_CAMCO_SETTING_ZSD, VAPP_CAMCO_SETTING_CAP_ENABLED);
            m_content[VAPP_CAMCO_EFFECT_COLOR_YELLOW]->setStatus(VAPP_CAMCO_SETTING_ZSD, VAPP_CAMCO_SETTING_CAP_ENABLED);
            m_content[VAPP_CAMCO_EFFECT_COLOR_GREEN]->setStatus(VAPP_CAMCO_SETTING_ZSD, VAPP_CAMCO_SETTING_CAP_ENABLED);
            m_content[VAPP_CAMCO_EFFECT_COLOR_BLUE]->setStatus(VAPP_CAMCO_SETTING_ZSD, VAPP_CAMCO_SETTING_CAP_ENABLED);

        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_ACT_APP)
    {
        if(change_value == VAPP_CAMCO_APP_RECORDER)
        {
            setValue(VAPP_CAMCO_EFFECT_NORMAL);
        }
    }
}

void EffectSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);

    m_isHiliteMode = VFX_FALSE;

    if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        mdi_camera_update_para_effect(getMappingID(v));
    }
    else if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_RECORDER)
    {
        mdi_video_rec_update_para_effect(getMappingID(v));
    }
}

MMI_BOOL EffectSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_EFFECT, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_EFFECT, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (VfxU32 idx = 0; idx < cap_info->item_count; idx++)
    {
        VfxU16 item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_EFFECT_NOMRAL:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_NORMAL;
                break;

            case MDI_CAMERA_EFFECT_GRAYSCALE:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_GRAYSCALE;
                break;

            case MDI_CAMERA_EFFECT_SEPIA:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_SEPIA;
                break;

            case MDI_CAMERA_EFFECT_COLOR_INVERT:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_COLOR_INVERT;
                break;

            case MDI_CAMERA_EFFECT_SKETCH:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_SKETCH;
                break;

            case MDI_CAMERA_EFFECT_OIL:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_OIL;
                break;

            case MDI_CAMERA_EFFECT_LOMO:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_LOMO;
                break;

            case MDI_CAMERA_EFFECT_COLOR_RED:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_COLOR_RED;
                break;

            case MDI_CAMERA_EFFECT_COLOR_YELLOW:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_COLOR_YELLOW;
                break;

            case MDI_CAMERA_EFFECT_COLOR_GREEN:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_COLOR_GREEN;
                break;

            case MDI_CAMERA_EFFECT_COLOR_BLUE:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_COLOR_BLUE;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }
    return MMI_TRUE;
}

VfxU32 EffectSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_EFFECT_NORMAL:
            return MDI_CAMERA_EFFECT_NOMRAL;

        case VAPP_CAMCO_EFFECT_GRAYSCALE:
            return MDI_CAMERA_EFFECT_GRAYSCALE;

        case VAPP_CAMCO_EFFECT_SEPIA:
            return MDI_CAMERA_EFFECT_SEPIA;

        case VAPP_CAMCO_EFFECT_COLOR_INVERT:
            return MDI_CAMERA_EFFECT_COLOR_INVERT;

        case VAPP_CAMCO_EFFECT_SKETCH:
            return MDI_CAMERA_EFFECT_SKETCH;

        case VAPP_CAMCO_EFFECT_OIL:
            return MDI_CAMERA_EFFECT_OIL;

        case VAPP_CAMCO_EFFECT_LOMO:
            return MDI_CAMERA_EFFECT_LOMO;

        case VAPP_CAMCO_EFFECT_COLOR_RED:
            return MDI_CAMERA_EFFECT_COLOR_RED;

        case VAPP_CAMCO_EFFECT_COLOR_YELLOW:
            return MDI_CAMERA_EFFECT_COLOR_YELLOW;

        case VAPP_CAMCO_EFFECT_COLOR_GREEN:
            return MDI_CAMERA_EFFECT_COLOR_GREEN;

        case VAPP_CAMCO_EFFECT_COLOR_BLUE:
            return MDI_CAMERA_EFFECT_COLOR_BLUE;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void EffectSetting::applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
    {
        mdi_camera_update_para_effect(getMappingID(v));
    }
    else if (m_settingMgr->getCurrCam()  == VAPP_CAMCO_APP_RECORDER)
    {
        mdi_video_rec_update_para_effect(getMappingID(v));
    }
}

void EffectSetting::resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        {
            mdi_camera_update_para_effect(getMappingID(m_currentValue));
        }
        else if (m_settingMgr->getCurrApp()  == VAPP_CAMCO_APP_RECORDER)
        {
            mdi_video_rec_update_para_effect(getMappingID(m_currentValue));
        }
    }
}

void StorageSetting::initialize(void)
{
    CamcoSettingItem::initialize();

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_GLOBAL_STORAGE;

    SRV_FMGR_DRVLIST_HANDLE drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    VfxU8 drv_num = srv_fmgr_drivelist_count(drvlist);

    for (VfxU32 idx = 0; idx < drv_num; idx++)
    {
        U8 drv = srv_fmgr_drivelist_get_drv_letter(drvlist, idx);
        S32 drv_enum = srv_fmgr_drv_get_type(drv);

        m_content[drv_enum]->setStr((VfxU16)srv_fmgr_drv_get_string(drv));
        m_content[drv_enum]->setValue(drv_enum);
    }

#ifdef __FS_CARD_SUPPORT__
    m_content[SRV_FMGR_DRV_CARD_TYPE]->setStr(STR_FMGR_REM_DEVICE);
#endif
#ifdef __OTG_ENABLE__
    m_content[SRV_FMGR_DRV_OTG_TYPE]->setStr(STR_FMGR_USB_STORAGE);
#endif
}

void StorageSetting::setDefault(void)
{
    m_cap = ENABLE();

    // query from system support
    SRV_FMGR_DRVLIST_HANDLE drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    VfxS16 drv_num = srv_fmgr_drivelist_count(drvlist);

    for (VfxU32 idx = 0; idx < drv_num; idx++)
    {
        U8 drv = srv_fmgr_drivelist_get_drv_letter(drvlist, idx);
        S32 drv_enum = srv_fmgr_drv_get_type(drv);

        m_content[drv_enum]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
        m_content[drv_enum]->setValue(drv_enum);
    }
#ifdef __FS_CARD_SUPPORT__
    if(m_content[SRV_FMGR_DRV_CARD_TYPE]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
        m_content[SRV_FMGR_DRV_CARD_TYPE]->setStatus(VAPP_CAMCO_SETTING_CAP_DISABLED);
#endif
#ifdef __OTG_ENABLE__
    if(m_content[SRV_FMGR_DRV_OTG_TYPE]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
        m_content[SRV_FMGR_DRV_OTG_TYPE]->setStatus(VAPP_CAMCO_SETTING_CAP_DISABLED);
#endif

    // query from codec support
    mdi_video_rec_spec_struct spec_entry_struct;
    VfxU32 count = mdi_video_rec_query_entry_num_of_video_spec_table();
    VfxBool isPhoneSupport = VFX_FALSE, isCardSupport = VFX_FALSE;
    for(VfxU32 i=0; i < count; i++)
    {
        MDI_RESULT  ret = mdi_video_rec_get_video_spec_by_index(i, &spec_entry_struct, sizeof(spec_entry_struct));

        if(ret != MDI_RES_VDOREC_SUCCEED)
            continue;

        switch (spec_entry_struct.storage)
        {
            case MDI_VIDEO_REC_STORAGE_PHONE:
                isPhoneSupport = VFX_TRUE;
                break;

            case MDI_VIDEO_REC_STORAGE_SD:
                isCardSupport = VFX_TRUE;
                break;

            case MDI_VIDEO_REC_STORAGE_ALL:
                isPhoneSupport = VFX_TRUE;
                isCardSupport = VFX_TRUE;
                break;
        }
    }
    if(!isPhoneSupport)
    {
        m_content[SRV_FMGR_DRV_PHONE_TYPE]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
        m_content[SRV_FMGR_DRV_PHONE_2_TYPE]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
    }

    if(!isCardSupport)
    {
        m_content[SRV_FMGR_DRV_CARD_TYPE]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
        m_content[SRV_FMGR_DRV_CARD_2_TYPE]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
    }

#if defined(__VAPP_CAMCO_NO_PUBLIC_DRV__)
    setValue(SRV_FMGR_DRV_CARD_TYPE);
#else
    CheckandSet(SRV_FMGR_DRV_PHONE_TYPE);
#endif
    genStoragePath();
}

U8 StorageSetting::getStorage(void)
{
    return srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)m_content[m_currentValue]->getValue());
}

void StorageSetting::getStoragePath(WCHAR** storagePath)
{
    (*storagePath) = m_storagePath;
}

void StorageSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_VDOSTORAGE && m_settingType == VAPP_CAMCO_SETTING_CAMSTORAGE)
    {
        if(change_value != m_currentValue)
        {
            setValue(change_value);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_CAMSTORAGE && m_settingType == VAPP_CAMCO_SETTING_VDOSTORAGE)
    {
        if(change_value != m_currentValue)
        {
            setValue(change_value);
        }
    }
    else if(m_settingType == VAPP_CAMCO_SETTING_VDOSTORAGE)
    {
        if(change_setting == VAPP_CAMCO_SETTING_VISQTY)
        {
            config_recstorage_capability(VAPP_CAMCO_SETTING_VISQTY);
        }
        else if(change_setting == VAPP_CAMCO_SETTING_RECSIZE)
        {
            config_recstorage_capability(VAPP_CAMCO_SETTING_RECSIZE);
        }
        else if(change_setting == VAPP_CAMCO_SETTING_VISQTY)
        {
            config_recstorage_capability(VAPP_CAMCO_SETTING_VISQTY);
        }
    }
}

void StorageSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    genStoragePath();
}

void StorageSetting::checkStorage(void)
{
    initialize();
    setDefault();
}

void StorageSetting::setType(vapp_camco_setting_enum type)
{
    m_settingType = type;
}

void StorageSetting::genStoragePath(void)
{
    WCHAR drv_buf[8];
    CHAR buf[64];
    U8 drv = srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)m_content[m_currentValue]->getValue());
    if (FS_NO_ERROR == FS_GetDevStatus(drv, FS_MOUNT_STATE_ENUM))
    {
        sprintf((CHAR *)buf, "%c:\\", (U8)drv);
        mmi_asc_to_wcs(drv_buf, (CHAR *)buf);
    }
    else
    {
        if (FS_NO_ERROR == FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM))
        {
            sprintf((CHAR *)buf, "%c:\\", (U8)drv);
            mmi_asc_to_wcs(drv_buf, (CHAR *)buf);
        }
        else
        {
            m_storagePath[0] = m_storagePath[1] = 0;
            return;
        }
    }
    mmi_wcscpy(m_storagePath, drv_buf);
    if (m_settingType == VAPP_CAMCO_SETTING_CAMSTORAGE)
    {
        mmi_wcscat(m_storagePath, (WCHAR *)SHOOTING_DOWNLOAD_FOLDER_NAME);
    }
    else
    {
        mmi_wcscat(m_storagePath, (WCHAR *)SHOOTING_DOWNLOAD_FOLDER_NAME);
    }
}

void StorageSetting::config_recstorage_capability(vapp_camco_setting_enum changed_setting)
{
    // Vdo storage may be key setting and need to show all
    // others depended setting will be hide
    if(recorder_config_has_dependency() && (recorder_config_is_key(m_settingMgr->transTargetFromMMI(m_settingType))))
    {
        // Let storage always show, or user will not be able to choose some time if setting is independant to each other
        m_content[SRV_FMGR_DRV_PHONE_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
        m_content[SRV_FMGR_DRV_PHONE_2_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
        m_content[SRV_FMGR_DRV_CARD_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
        m_content[SRV_FMGR_DRV_CARD_2_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
    }
    else
    {

        VfxU16 reccodec = m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISCODEC);
        VfxU32 recsize = m_settingMgr->getValue(VAPP_CAMCO_SETTING_RECSIZE);
        VfxU32 recqty = m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISQTY);
        VfxU32 storage = m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSTORAGE);

        if(storage == SRV_FMGR_DRV_PHONE_TYPE || storage == SRV_FMGR_DRV_PHONE_2_TYPE)
        {
            storage = 0;
        }
        else if(storage == SRV_FMGR_DRV_CARD_TYPE || storage == SRV_FMGR_DRV_CARD_2_TYPE)
        {
            storage = 1;
        }
        VfxU32 maxMatchCouunt = 0;
        VfxBool currSettingMatch = VFX_FALSE;

        VfxU32 selectedRecsize = recsize, selectedRecqty = recqty, selectedStorage = storage;

        for (VfxU32 k = 0; k < 2; k++)
        {
            if (getItem(k).getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
            {
                VfxBool isActive = VFX_FALSE;

                for (VfxU32 i = 0; i < VAPP_CAMCO_RECSIZE_END; i++)
                {
                    for (VfxU32 j = 0; j < VAPP_CAMCO_VISQTY_END; j++)
                    {
                        if (vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[reccodec][i][j][k])
                        {
                            VfxU32 matchCouunt = 0;
                            VfxBool isChangedSettingMatch = VFX_FALSE;

                            if(i == recsize)
                            {
                                matchCouunt++;
                                if(changed_setting == VAPP_CAMCO_SETTING_RECSIZE)
                                {
                                    isChangedSettingMatch = VFX_TRUE;
                                }
                            }
                            if(j == recqty)
                            {
                                matchCouunt++;
                                if(changed_setting == VAPP_CAMCO_SETTING_VISQTY)
                                {
                                    isChangedSettingMatch = VFX_TRUE;
                                }
                            }
                            if(k ==  storage)
                            {
                                matchCouunt++;
                                if(changed_setting == VAPP_CAMCO_SETTING_VDOSTORAGE)
                                {
                                    isChangedSettingMatch = VFX_TRUE;
                                }
                            }

                            if((maxMatchCouunt < matchCouunt) || ((!currSettingMatch)&&isChangedSettingMatch))
                            {
                                selectedRecsize = i;
                                selectedRecqty = j;
                                selectedStorage = k;
                                maxMatchCouunt = matchCouunt;
                                currSettingMatch = isChangedSettingMatch;

                            }
                            isActive = VFX_TRUE;

                        }
                    }
                }

                if (isActive)
                {
                    if(k == 0)
                    {
                        m_content[SRV_FMGR_DRV_PHONE_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
                        m_content[SRV_FMGR_DRV_PHONE_2_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
                    }
                    else
                    {
                        m_content[SRV_FMGR_DRV_CARD_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
                        m_content[SRV_FMGR_DRV_CARD_2_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
                    }
                }
                else
                {
                    if(k == 0)
                    {
                        m_content[SRV_FMGR_DRV_PHONE_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_DISABLED);
                        m_content[SRV_FMGR_DRV_PHONE_2_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_DISABLED);
                    }
                    else
                    {
                        m_content[SRV_FMGR_DRV_CARD_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_DISABLED);
                        m_content[SRV_FMGR_DRV_CARD_2_TYPE]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_DISABLED);
                    }
                }


            }
        }
        if (m_currentValue == 0xFF ||
            m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED ||
            !vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[reccodec][recsize][recqty][storage])
        {
            if(selectedRecsize != recsize)
            {
                m_settingMgr->setValue(VAPP_CAMCO_SETTING_RECSIZE, selectedRecsize);
            }

            if(selectedRecqty != recqty)
            {
                m_settingMgr->setValue(VAPP_CAMCO_SETTING_VISQTY, selectedRecqty);
            }

            if(selectedStorage != storage)
            {
                if(selectedStorage == 0)
                    m_settingMgr->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, SRV_FMGR_DRV_PHONE_TYPE);
                else
                    m_settingMgr->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, SRV_FMGR_DRV_CARD_TYPE);
            }
        }
    }
}

void CapqtySetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CAPQTY;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_CAPQTY;

    /* init item img id */
    m_content[VAPP_CAMCO_CAPQTY_FINE]->setStr(STR_ID_VAPP_CAMCO_CAPQTY_FINE);
    m_content[VAPP_CAMCO_CAPQTY_GOOD]->setStr(STR_ID_VAPP_CAMCO_CAPQTY_GOOD);
    m_content[VAPP_CAMCO_CAPQTY_NORMAL]->setStr(STR_ID_VAPP_CAMCO_CAPQTY_NORMAL);
    m_content[VAPP_CAMCO_CAPQTY_LOW]->setStr(STR_ID_VAPP_CAMCO_CAPQTY_LOW);
}

void CapqtySetting::setDefault(void)
{
    m_cap = ENABLE();
    m_content[VAPP_CAMCO_CAPQTY_FINE]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_CAPQTY_GOOD]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_CAPQTY_NORMAL]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_CAPQTY_LOW]->setStatus(VAPP_CAMCO_SETTING_CAP_DISABLED);

    m_content[VAPP_CAMCO_CAPQTY_FINE]->setValue(VAPP_CAMCO_CAPQTY_FINE);
    m_content[VAPP_CAMCO_CAPQTY_GOOD]->setValue(VAPP_CAMCO_CAPQTY_GOOD);
    m_content[VAPP_CAMCO_CAPQTY_NORMAL]->setValue(VAPP_CAMCO_CAPQTY_NORMAL);
    m_content[VAPP_CAMCO_CAPQTY_LOW]->setValue(VAPP_CAMCO_CAPQTY_LOW);

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_CAPQTY, m_currentValue);

    CheckandSet(VAPP_CAMCO_CAPQTY_FINE);
}

void CapqtySetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
}

void CapqtySetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    U16 mdi_capqty;

    CamcoSettingItem::setValue(v);

    mdi_capqty = getMappingID(v);
    mdi_camera_update_para_image_qty(mdi_capqty);

}

VfxU32 CapqtySetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_CAPQTY_FINE:
            return MDI_CAMERA_JPG_QTY_HIGH;

        case VAPP_CAMCO_CAPQTY_GOOD:
            return MDI_CAMERA_JPG_QTY_NORMAL;

        case VAPP_CAMCO_CAPQTY_NORMAL:
            return MDI_CAMERA_JPG_QTY_LOW;

        case VAPP_CAMCO_CAPQTY_LOW:
            return MDI_CAMERA_JPG_QTY_LOW;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void VdoSceneModeSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_VDOSCENEMODE;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_SCENEMODE;

    /* init item str id */
    m_content[VAPP_CAMCO_VDOSCENEMODE_AUTO]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_AUTO);
    m_content[VAPP_CAMCO_VDOSCENEMODE_NIGHT]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_NIGHT);

    m_content[VAPP_CAMCO_VDOSCENEMODE_AUTO]->setStatusIcon(0);
    m_content[VAPP_CAMCO_VDOSCENEMODE_NIGHT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_SCN_MODE_NIGHT_ICON);
}

void VdoSceneModeSetting::setDefault(void)
{
    CamcoSettingItem::setDefault();
    CheckandSet(VAPP_CAMCO_VDOSCENEMODE_AUTO);
}

void VdoSceneModeSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
}

void VdoSceneModeSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);

    if(m_lastValue != m_currentValue)
    {
        m_settingMgr->needRestartPreview();
    }
}

VfxU32 VdoSceneModeSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_VDOSCENEMODE_AUTO:
            return MDI_VIDEO_SCENE_MODE_AUTO;

        case VAPP_CAMCO_VDOSCENEMODE_NIGHT:
            return MDI_VIDEO_SCENE_MODE_NIGHT;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

MMI_BOOL VdoSceneModeSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_VIDEOSCENE, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_VIDEOSCENE, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (VfxU32 idx = 0; idx < cap_info->item_count; idx++)
    {
        VfxU16 item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_SCENE_MODE_VIDEO_AUTO:
                cap_info->support_item[idx] = VAPP_CAMCO_VDOSCENEMODE_AUTO;
                break;

            case MDI_CAMERA_SCENE_MODE_VIDEO_NIGHT:
                cap_info->support_item[idx] = VAPP_CAMCO_VDOSCENEMODE_NIGHT;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }
    return MMI_TRUE;
}

void RecSizeSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_RECSIZE;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_RECSIZE;

    /* init item img id */
    m_content[VAPP_CAMCO_RECSIZE_SQCIF]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_SQCIF);
    m_content[VAPP_CAMCO_RECSIZE_QQVGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_QQVGA);
    m_content[VAPP_CAMCO_RECSIZE_QCIF]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_QCIF);
    m_content[VAPP_CAMCO_RECSIZE_QVGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_QVGA);
    m_content[VAPP_CAMCO_RECSIZE_CIF]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_CIF);
    m_content[VAPP_CAMCO_RECSIZE_WQVGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_WQVGA);
    m_content[VAPP_CAMCO_RECSIZE_CIF2]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_CIF2);
    m_content[VAPP_CAMCO_RECSIZE_HVGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_HVGA);
    m_content[VAPP_CAMCO_RECSIZE_NHD]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_NHD);
    m_content[VAPP_CAMCO_RECSIZE_VGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_VGA);
    m_content[VAPP_CAMCO_RECSIZE_4CIF]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_4CIF);
    m_content[VAPP_CAMCO_RECSIZE_D1]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_D1);
    m_content[VAPP_CAMCO_RECSIZE_D12]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_D12);
    m_content[VAPP_CAMCO_RECSIZE_WVGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_WVGA);
    m_content[VAPP_CAMCO_RECSIZE_SVGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_SVGA);
    m_content[VAPP_CAMCO_RECSIZE_WVGA2]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_WVGA2);
    m_content[VAPP_CAMCO_RECSIZE_FWVGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_FWVGA);
    m_content[VAPP_CAMCO_RECSIZE_XGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_XGA);
    m_content[VAPP_CAMCO_RECSIZE_720P]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_720P);
    m_content[VAPP_CAMCO_RECSIZE_4VGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_4VGA);
    m_content[VAPP_CAMCO_RECSIZE_SXGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_SXGA);
    m_content[VAPP_CAMCO_RECSIZE_16CIF]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_16CIF);
    m_content[VAPP_CAMCO_RECSIZE_4SVGA]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_4SVGA);
    m_content[VAPP_CAMCO_RECSIZE_FHD]->setStr(STR_ID_VAPP_CAMCO_RECSIZE_FHD);
}

void RecSizeSetting::setDefault(void)
{
    m_content[VAPP_CAMCO_RECSIZE_SQCIF]->setValue(VAPP_CAMCO_RECSIZE_SQCIF);
    m_content[VAPP_CAMCO_RECSIZE_QQVGA]->setValue(VAPP_CAMCO_RECSIZE_QQVGA);
    m_content[VAPP_CAMCO_RECSIZE_QCIF]->setValue(VAPP_CAMCO_RECSIZE_QCIF);
    m_content[VAPP_CAMCO_RECSIZE_QVGA]->setValue(VAPP_CAMCO_RECSIZE_QVGA);
    m_content[VAPP_CAMCO_RECSIZE_CIF]->setValue(VAPP_CAMCO_RECSIZE_CIF);
    m_content[VAPP_CAMCO_RECSIZE_WQVGA]->setValue(VAPP_CAMCO_RECSIZE_WQVGA);
    m_content[VAPP_CAMCO_RECSIZE_CIF2]->setValue(VAPP_CAMCO_RECSIZE_CIF2);
    m_content[VAPP_CAMCO_RECSIZE_HVGA]->setValue(VAPP_CAMCO_RECSIZE_HVGA);
    m_content[VAPP_CAMCO_RECSIZE_NHD]->setValue(VAPP_CAMCO_RECSIZE_NHD);
    m_content[VAPP_CAMCO_RECSIZE_VGA]->setValue(VAPP_CAMCO_RECSIZE_VGA);
    m_content[VAPP_CAMCO_RECSIZE_4CIF]->setValue(VAPP_CAMCO_RECSIZE_4CIF);
    m_content[VAPP_CAMCO_RECSIZE_D1]->setValue(VAPP_CAMCO_RECSIZE_D1);
    m_content[VAPP_CAMCO_RECSIZE_D12]->setValue(VAPP_CAMCO_RECSIZE_D12);
    m_content[VAPP_CAMCO_RECSIZE_WVGA]->setValue(VAPP_CAMCO_RECSIZE_WVGA);
    m_content[VAPP_CAMCO_RECSIZE_SVGA]->setValue(VAPP_CAMCO_RECSIZE_SVGA);
    m_content[VAPP_CAMCO_RECSIZE_WVGA2]->setValue(VAPP_CAMCO_RECSIZE_WVGA2);
    m_content[VAPP_CAMCO_RECSIZE_FWVGA]->setValue(VAPP_CAMCO_RECSIZE_FWVGA);
    m_content[VAPP_CAMCO_RECSIZE_XGA]->setValue(VAPP_CAMCO_RECSIZE_XGA);
    m_content[VAPP_CAMCO_RECSIZE_720P]->setValue(VAPP_CAMCO_RECSIZE_720P);
    m_content[VAPP_CAMCO_RECSIZE_4VGA]->setValue(VAPP_CAMCO_RECSIZE_4VGA);
    m_content[VAPP_CAMCO_RECSIZE_SXGA]->setValue(VAPP_CAMCO_RECSIZE_SXGA);
    m_content[VAPP_CAMCO_RECSIZE_16CIF]->setValue(VAPP_CAMCO_RECSIZE_16CIF);
    m_content[VAPP_CAMCO_RECSIZE_4SVGA]->setValue(VAPP_CAMCO_RECSIZE_4SVGA);
    m_content[VAPP_CAMCO_RECSIZE_FHD]->setValue(VAPP_CAMCO_RECSIZE_FHD);

    memset(vapp_camco_codec_vs_recsize_vs_recqty_vs_storage, 0,  (sizeof(VfxBool) * VAPP_CAMCO_VISCODEC_END * VAPP_CAMCO_RECSIZE_END * VAPP_CAMCO_VISQTY_END * 2));

    mdi_video_rec_spec_struct spec_entry_struct;
    VfxU32 count = mdi_video_rec_query_entry_num_of_video_spec_table();
    for(VfxU32 i = 0; i < count; i++)
    {
        VfxU32 l = 0, m = 0, n = 0;
        VfxS32 p =0, q = 0;
        VfxBool isMapped = VFX_TRUE;
        VfxBool isinit = VFX_FALSE;

        MDI_RESULT  ret = mdi_video_rec_get_video_spec_by_index(i, &spec_entry_struct, sizeof(spec_entry_struct));

        if(ret != MDI_RES_VDOREC_SUCCEED)
            continue;

        switch (spec_entry_struct.video_size)
        {
            case MDI_VIDEO_REC_RESOLUTION_128x96:             // SQCIF
                m_content[VAPP_CAMCO_RECSIZE_SQCIF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_SQCIF;
                break;

            case MDI_VIDEO_REC_RESOLUTION_160x120:            // QQVGA
                m_content[VAPP_CAMCO_RECSIZE_QQVGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_QQVGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_176x144:            // QCIF
                m_content[VAPP_CAMCO_RECSIZE_QCIF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_QCIF;
                break;

            case MDI_VIDEO_REC_RESOLUTION_320x240:            // QVGA
                m_content[VAPP_CAMCO_RECSIZE_QVGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_QVGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_352x288:            // CIF
                m_content[VAPP_CAMCO_RECSIZE_CIF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_CIF;
                break;

            case MDI_VIDEO_REC_RESOLUTION_400x240:            // WQVGA
                m_content[VAPP_CAMCO_RECSIZE_WQVGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_WQVGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_432x240:            // CIF
                m_content[VAPP_CAMCO_RECSIZE_CIF2]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_CIF2;
                break;

            case MDI_VIDEO_REC_RESOLUTION_480x320:            // HVGA
                m_content[VAPP_CAMCO_RECSIZE_HVGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_HVGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_640x368:            // NHD
                m_content[VAPP_CAMCO_RECSIZE_NHD]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_NHD;
                break;

            case MDI_VIDEO_REC_RESOLUTION_640x480:            // VGA
                m_content[VAPP_CAMCO_RECSIZE_VGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_VGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_704x576:
                m_content[VAPP_CAMCO_RECSIZE_4CIF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_4CIF;
                break;

            case MDI_VIDEO_REC_RESOLUTION_720x480:            // D1
                m_content[VAPP_CAMCO_RECSIZE_D1]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_D1;
                break;

            case MDI_VIDEO_REC_RESOLUTION_720x576:            // D1
                m_content[VAPP_CAMCO_RECSIZE_D12]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_D12;
                break;

            case MDI_VIDEO_REC_RESOLUTION_800x480:            // WVGA
                m_content[VAPP_CAMCO_RECSIZE_WVGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_WVGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_800x608:            // SVGA
                m_content[VAPP_CAMCO_RECSIZE_SVGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_SVGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_848x480:            // WVGA
                m_content[VAPP_CAMCO_RECSIZE_WVGA2]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_WVGA2;
                break;

            case MDI_VIDEO_REC_RESOLUTION_864x480:            // FWVGA
                m_content[VAPP_CAMCO_RECSIZE_FWVGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_FWVGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_1024x768:           // XGA
                m_content[VAPP_CAMCO_RECSIZE_XGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_XGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_1280x720:           // 720P
                m_content[VAPP_CAMCO_RECSIZE_720P]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_720P;
                break;

            case MDI_VIDEO_REC_RESOLUTION_1280x960:           // 4VGA
                m_content[VAPP_CAMCO_RECSIZE_4VGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_4VGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_1280x1024:          // SXGA
                m_content[VAPP_CAMCO_RECSIZE_SXGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_SXGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_1408x1152:          // 16CIF
                m_content[VAPP_CAMCO_RECSIZE_16CIF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_16CIF;
                break;

            case MDI_VIDEO_REC_RESOLUTION_1600x1200:          // 4SVGA
                m_content[VAPP_CAMCO_RECSIZE_4SVGA]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_4SVGA;
                break;

            case MDI_VIDEO_REC_RESOLUTION_1920x1088:          // FHD
                m_content[VAPP_CAMCO_RECSIZE_FHD]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                l = VAPP_CAMCO_RECSIZE_FHD;
                break;

            default:
                isMapped = VFX_FALSE;
                break;
        }
        switch (spec_entry_struct.video_format)
        {
            case MDI_VIDEO_VIDEO_FORMAT_3GP:
                m = VAPP_CAMCO_VISCODEC_3GP;
                break;
            case MDI_VIDEO_VIDEO_FORMAT_MP4:
                m = VAPP_CAMCO_VISCODEC_MP4;
                break;
            case MDI_VIDEO_VIDEO_FORMAT_MJPEG:
                m = VAPP_CAMCO_VISCODEC_MJPG;
                break;
            case MDI_VIDEO_VIDEO_FORMAT_H264:
                m = VAPP_CAMCO_VISCODEC_H264;
                break;
            default:
                isMapped = VFX_FALSE;
                break;
        }
        switch (spec_entry_struct.quality)
        {
            case MDI_VIDEO_REC_QTY_LOW:
                n = VAPP_CAMCO_VISQTY_LOW;
                break;
            case MDI_VIDEO_REC_QTY_NORMAL:
                n = VAPP_CAMCO_VISQTY_NORMAL;
                break;
            case MDI_VIDEO_REC_QTY_FINE:
                n = VAPP_CAMCO_VISQTY_FINE;
                break;
            case MDI_VIDEO_REC_QTY_HIGH:
                n = VAPP_CAMCO_VISQTY_GOOD;
                break;
            default:
                isMapped = VFX_FALSE;
                break;
        }
        switch (spec_entry_struct.storage)
        {
            case MDI_VIDEO_REC_STORAGE_PHONE:
                p = 0;
                q = 0;
                break;

            case MDI_VIDEO_REC_STORAGE_SD:
                p = 1;
                q = 1;
                break;

            case MDI_VIDEO_REC_STORAGE_ALL:
                p = 0;
                q = 1;
                break;
            default:
                isMapped = VFX_FALSE;
                break;
        }

        // we may query the non-support size (wallpaper), and we skip it
        if(isMapped)
        {
            vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[m][l][n][p] = VFX_TRUE;
            vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[m][l][n][q] = VFX_TRUE;

            // give a initialize value or it will fail to config recsize capability
            if(!isinit || m_settingMgr->IsExtSetting())
            {
                // when ext calling default use the last setting (lowest)
                if(m_settingMgr->IsExtSetting())
                {
                    if(!isinit || n >= m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISQTY))
                    {
                        ((RecSizeSetting*)(m_settingMgr->getSetting(VAPP_CAMCO_SETTING_RECSIZE)))->resetValue(l);
                        ((VisQtySetting*)(m_settingMgr->getSetting(VAPP_CAMCO_SETTING_VISQTY)))->resetValue(n);
                        ((VisCodecSetting*)(m_settingMgr->getSetting(VAPP_CAMCO_SETTING_VISCODEC)))->resetValue(m);
                    }
                    isinit = VFX_TRUE;
                }
                // when not ext calling give a valid value firstly
                else
                {
                    // is App not CUI and is has inited, keep it
                    if(m_settingMgr->getValue(VAPP_CAMCO_SETTING_RECSIZE) == 0XFF ||
                       m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISQTY) == 0XFF ||
                       m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISCODEC) == 0XFF)
                    {
                        ((RecSizeSetting*)(m_settingMgr->getSetting(VAPP_CAMCO_SETTING_RECSIZE)))->resetValue(l);
                        ((VisQtySetting*)(m_settingMgr->getSetting(VAPP_CAMCO_SETTING_VISQTY)))->resetValue(n);
                        ((VisCodecSetting*)(m_settingMgr->getSetting(VAPP_CAMCO_SETTING_VISCODEC)))->resetValue(m);
                    }
                    isinit = VFX_TRUE;
                }
            }
        }
    }
    m_cap = ENABLE();

    config_recsize_capability(VAPP_CAMCO_SETTING_RECSIZE);

    // ext calling config
    if(m_settingMgr->IsExtSetting())
    {
        VfxS32 marker = -1;

        for(VfxU32 i = 0; i < m_settingMgr->m_callingParam.settingLimitNum; i++)
        {
            if(m_settingMgr->m_callingParam.settingLimitation[i].type == VCUI_CAMCO_SETTING_LIMIT_RECSIZE)
            {
                marker = m_settingMgr->m_callingParam.settingLimitation[i].detail - VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_WALLPAPER;
                break;
            }
        }
        if(marker != -1)
        {
            for(VfxU32 i = marker + 1; i < VAPP_CAMCO_RECSIZE_END; i++)
            {
                m_content[i]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
            }
        }
    }
    CheckandSet(-1);
}

void RecSizeSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_VISQTY)
    {
        config_recsize_capability(VAPP_CAMCO_SETTING_VISQTY);
    }
    else if(change_setting == VAPP_CAMCO_SETTING_VISCODEC)
    {
        config_recsize_capability(VAPP_CAMCO_SETTING_VISCODEC);
    }
    else if(change_setting == VAPP_CAMCO_SETTING_VDOSTORAGE)
    {
        config_recsize_capability(VAPP_CAMCO_SETTING_VDOSTORAGE);
    }
}

void RecSizeSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::setValue(v);

    m_settingMgr->needRestartPreview();
}

MMI_BOOL RecSizeSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    return MMI_FALSE;
}

VfxU32 RecSizeSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_RECSIZE_SQCIF:
            return MDI_VIDEO_VIDEO_SIZE_SQCIF;

        case VAPP_CAMCO_RECSIZE_QQVGA:
            return MDI_VIDEO_VIDEO_SIZE_QQVGA;

        case VAPP_CAMCO_RECSIZE_QCIF:
            return MDI_VIDEO_VIDEO_SIZE_QCIF;

        case VAPP_CAMCO_RECSIZE_QVGA:
            return MDI_VIDEO_VIDEO_SIZE_QVGA;

        case VAPP_CAMCO_RECSIZE_CIF:
            return MDI_VIDEO_VIDEO_SIZE_CIF;

        case VAPP_CAMCO_RECSIZE_WQVGA:
            return MDI_VIDEO_VIDEO_SIZE_WQVGA;

        case VAPP_CAMCO_RECSIZE_CIF2:
            return MDI_VIDEO_VIDEO_SIZE_CIF_2;

        case VAPP_CAMCO_RECSIZE_HVGA:
            return MDI_VIDEO_VIDEO_SIZE_HVGA;

        case VAPP_CAMCO_RECSIZE_NHD:
            return MDI_VIDEO_VIDEO_SIZE_NHD;

        case VAPP_CAMCO_RECSIZE_VGA:
            return MDI_VIDEO_VIDEO_SIZE_VGA;

        case VAPP_CAMCO_RECSIZE_4CIF:
            return MDI_VIDEO_VIDEO_SIZE_4CIF;

        case VAPP_CAMCO_RECSIZE_D1:
            return MDI_VIDEO_VIDEO_SIZE_D1;

        case VAPP_CAMCO_RECSIZE_D12:
            return MDI_VIDEO_VIDEO_SIZE_D1_2;

        case VAPP_CAMCO_RECSIZE_WVGA:
            return MDI_VIDEO_VIDEO_SIZE_WVGA;

        case VAPP_CAMCO_RECSIZE_SVGA:
            return MDI_VIDEO_VIDEO_SIZE_SVGA;

        case VAPP_CAMCO_RECSIZE_WVGA2:
            return MDI_VIDEO_VIDEO_SIZE_WVGA_2;

        case VAPP_CAMCO_RECSIZE_FWVGA:
            return MDI_VIDEO_VIDEO_SIZE_FWVGA;

        case VAPP_CAMCO_RECSIZE_XGA:
            return MDI_VIDEO_VIDEO_SIZE_XGA;

        case VAPP_CAMCO_RECSIZE_720P:
            return MDI_VIDEO_VIDEO_SIZE_720P;

        case VAPP_CAMCO_RECSIZE_4VGA:
            return MDI_VIDEO_VIDEO_SIZE_4VGA;

        case VAPP_CAMCO_RECSIZE_SXGA:
            return MDI_VIDEO_VIDEO_SIZE_SXGA;

        case VAPP_CAMCO_RECSIZE_16CIF:
            return MDI_VIDEO_VIDEO_SIZE_16CIF;

        case VAPP_CAMCO_RECSIZE_4SVGA:
            return MDI_VIDEO_VIDEO_SIZE_4SVGA;

        case VAPP_CAMCO_RECSIZE_FHD:
            return MDI_VIDEO_VIDEO_SIZE_FHD;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

VfxSize RecSizeSetting::getSize(VfxU16 v)
{
    VfxSize size;

    switch (v)
    {
        case VAPP_CAMCO_RECSIZE_SQCIF:
            size.width = 128;
            size.height = 96;
            return size;

        case VAPP_CAMCO_RECSIZE_QQVGA:
            size.width = 160;
            size.height = 120;
            return size;

        case VAPP_CAMCO_RECSIZE_QCIF:
            size.width = 176;
            size.height = 144;
            return size;

        case VAPP_CAMCO_RECSIZE_QVGA:
            size.width = 320;
            size.height = 240;
            return size;

        case VAPP_CAMCO_RECSIZE_CIF:
            size.width = 352;
            size.height = 288;
            return size;

        case VAPP_CAMCO_RECSIZE_WQVGA:
            size.width = 400;
            size.height = 240;
            return size;

        case VAPP_CAMCO_RECSIZE_CIF2:
            size.width = 432;
            size.height = 240;
            return size;

        case VAPP_CAMCO_RECSIZE_HVGA:
            size.width = 480;
            size.height = 320;
            return size;

        case VAPP_CAMCO_RECSIZE_NHD:
            size.width = 640;
            size.height = 368;
            return size;

        case VAPP_CAMCO_RECSIZE_VGA:
            size.width = 640;
            size.height = 480;
            return size;

        case VAPP_CAMCO_RECSIZE_4CIF:
            size.width = 704;
            size.height = 576;
            return size;

        case VAPP_CAMCO_RECSIZE_D1:
            size.width = 720;
            size.height = 480;
            return size;

        case VAPP_CAMCO_RECSIZE_D12:
            size.width = 720;
            size.height = 576;
            return size;

        case VAPP_CAMCO_RECSIZE_WVGA:
            size.width = 800;
            size.height = 480;
            return size;

        case VAPP_CAMCO_RECSIZE_SVGA:
            size.width = 800;
            size.height = 608;
            return size;

        case VAPP_CAMCO_RECSIZE_WVGA2:
            size.width = 848;
            size.height = 480;
            return size;

        case VAPP_CAMCO_RECSIZE_FWVGA:
            size.width = 864;
            size.height = 480;
            return size;

        case VAPP_CAMCO_RECSIZE_XGA:
            size.width = 1024;
            size.height = 768;
            return size;

        case VAPP_CAMCO_RECSIZE_720P:
            size.width = 1280;
            size.height = 720;
            return size;

        case VAPP_CAMCO_RECSIZE_4VGA:
            size.width = 1280;
            size.height = 960;
            return size;

        case VAPP_CAMCO_RECSIZE_SXGA:
            size.width = 1280;
            size.height = 1024;
            return size;

        case VAPP_CAMCO_RECSIZE_16CIF:
            size.width = 1408;
            size.height = 1152;
            return size;
            //break;

        case VAPP_CAMCO_RECSIZE_4SVGA:
            size.width = 1600;
            size.height = 1200;
            return size;

        case VAPP_CAMCO_RECSIZE_FHD:
            size.width = 1920;
            size.height = 1088;
            return size;
    }
    size.width = 128;
    size.height = 96;
    return size;
}

void RecSizeSetting::config_recsize_capability(vapp_camco_setting_enum changed_setting)
{
    // Recsize may be key setting and need to show all
    // others depended setting will be hide
    if(recorder_config_has_dependency() && (recorder_config_is_key(m_settingMgr->transTargetFromMMI(m_settingType))))
    {
        // Let recsize always show, or user will not be able to choose some time if setting is independant to each other
        for (VfxU32 idx = 0; idx < VAPP_CAMCO_RECSIZE_END; idx++)
        {
            if (getItem(idx).getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
            {
                m_content[idx]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
            }
        }
    }
    else
    {
        VfxU16 reccodec = m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISCODEC);
        VfxU32 recsize = m_settingMgr->getValue(VAPP_CAMCO_SETTING_RECSIZE);
        VfxU32 recqty = m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISQTY);
        VfxU32 storage = m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSTORAGE);

        if(storage == SRV_FMGR_DRV_PHONE_TYPE || storage == SRV_FMGR_DRV_PHONE_2_TYPE)
        {
            storage = 0;
        }
        else if(storage == SRV_FMGR_DRV_CARD_TYPE || storage == SRV_FMGR_DRV_CARD_2_TYPE)
        {
            storage = 1;
        }
        VfxU32 maxMatchCouunt = 0;
        VfxBool currSettingMatch = VFX_FALSE;

        VfxU32 selectedRecsize = recsize, selectedRecqty = recqty, selectedStorage = storage;

        for (VfxU32 i = 0; i < VAPP_CAMCO_RECSIZE_END; i++)
        {
            if (getItem(i).getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
            {
                VfxBool isActive = VFX_FALSE;

                for (VfxU32 j = 0; j < VAPP_CAMCO_VISQTY_END; j++)
                {
                    for (VfxU32 k = 0; k < 2; k++)
                    {
                        if (vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[reccodec][i][j][k])
                        {
                            VfxU32 matchCouunt = 0;
                            VfxBool isChangedSettingMatch = VFX_FALSE;

                            if(i == recsize)
                            {
                                matchCouunt++;
                                if(changed_setting == VAPP_CAMCO_SETTING_RECSIZE)
                                {
                                    isChangedSettingMatch = VFX_TRUE;
                                }
                            }
                            if(j == recqty)
                            {
                                matchCouunt++;
                                if(changed_setting == VAPP_CAMCO_SETTING_VISQTY)
                                {
                                    isChangedSettingMatch = VFX_TRUE;
                                }
                            }
                            if(k == storage)
                            {
                                matchCouunt++;
                                if(changed_setting == VAPP_CAMCO_SETTING_VDOSTORAGE)
                                {
                                    isChangedSettingMatch = VFX_TRUE;
                                }
                            }

                            if((maxMatchCouunt < matchCouunt) || ((!currSettingMatch)&&isChangedSettingMatch))
                            {
                                selectedRecsize = i;
                                selectedRecqty = j;
                                selectedStorage = k;
                                maxMatchCouunt = matchCouunt;
                                currSettingMatch = isChangedSettingMatch;
                            }
                            isActive = VFX_TRUE;

                        }
                    }
                }

                if (isActive)
                {
                    m_content[i]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
                }
                else
                {
                    m_content[i]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_DISABLED);
                }

            }
        }
        if (m_currentValue == 0xFF ||
            m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED ||
            !vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[reccodec][recsize][recqty][storage])
        {
            if(selectedRecsize != recsize)
            {
                m_settingMgr->setValue(VAPP_CAMCO_SETTING_RECSIZE, selectedRecsize);
            }

            if(selectedRecqty != recqty)
            {
                m_settingMgr->setValue(VAPP_CAMCO_SETTING_VISQTY, selectedRecqty);
            }

            if(selectedStorage != storage)
            {
                if(selectedStorage == 0)
                    m_settingMgr->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, SRV_FMGR_DRV_PHONE_TYPE);
                else
                    m_settingMgr->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, SRV_FMGR_DRV_CARD_TYPE);
            }
        }
    }
}

void TimeLapseSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_TIMELAPSE;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_TIME_LAPSE;

    /* init item img id */
    m_content[VAPP_CAMCO_TIME_LAPSE_OFF]->setStr(STR_GLOBAL_OFF);
    m_content[VAPP_CAMCO_TIME_LAPSE_ON]->setStr(STR_GLOBAL_ON);

    m_content[VAPP_CAMCO_TIME_LAPSE_OFF]->setStatusIcon(0);
    m_content[VAPP_CAMCO_TIME_LAPSE_ON]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_TIME_LAPSE_ON_ICON);
}

void TimeLapseSetting::setDefault(void)
{
#if defined(__TIME_LAPSE_VIDEO_RECORDER__)
    /* init capability */
    if(!m_settingMgr->IsExtSetting())
    {
        m_cap = ENABLE();
        m_content[VAPP_CAMCO_TIME_LAPSE_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
        m_content[VAPP_CAMCO_TIME_LAPSE_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    }
    else
    {
        m_cap = NOT_SUPPORT();
        m_content[VAPP_CAMCO_TIME_LAPSE_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
        m_content[VAPP_CAMCO_TIME_LAPSE_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
    }
#else
    m_cap = NOT_SUPPORT();
    m_content[VAPP_CAMCO_TIME_LAPSE_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
    m_content[VAPP_CAMCO_TIME_LAPSE_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif

    m_content[VAPP_CAMCO_TIME_LAPSE_OFF]->setValue(VAPP_CAMCO_TIME_LAPSE_OFF);
    m_content[VAPP_CAMCO_TIME_LAPSE_ON]->setValue(VAPP_CAMCO_TIME_LAPSE_ON);

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_TIME_LAPSE, m_currentValue);

    CheckandSet(VAPP_CAMCO_TIME_LAPSE_OFF);
}

void TimeLapseSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();
}

VfxU32 TimeLapseSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_TIME_LAPSE_OFF:
            return MDI_VIDEO_REC_QTY_FINE;

        case VAPP_CAMCO_TIME_LAPSE_ON:
            return MDI_VIDEO_REC_QTY_HIGH;

    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void TimeLapsePeriodSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_TIMELAPSEPERIOD;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_TIME_LAPSE_PERIOD;

    /* init item img id */
    m_content[VAPP_CAMCO_TIME_LAPSE_PERIOD_1]->setStr(0);

    m_content[VAPP_CAMCO_TIME_LAPSE_PERIOD_1]->setStatusIcon(0);
}

void TimeLapsePeriodSetting::setDefault(void)
{
#if defined(__TIME_LAPSE_VIDEO_RECORDER__)
    /* init capability */
    m_cap = ENABLE();
    m_content[VAPP_CAMCO_TIME_LAPSE_PERIOD_1]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
#else
    m_cap = NOT_SUPPORT();
    m_content[VAPP_CAMCO_TIME_LAPSE_PERIOD_1]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif

    m_content[VAPP_CAMCO_TIME_LAPSE_PERIOD_1]->setValue(VAPP_CAMCO_TIME_LAPSE_PERIOD_1);

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_TIME_LAPSE_PERIOD, m_currentValue);

    CheckandSet(VAPP_CAMCO_TIME_LAPSE_PERIOD_1);
}

void TimeLapsePeriodSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();
}

VfxU32 TimeLapsePeriodSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_TIME_LAPSE_PERIOD_1:
            return RECORDER_TIME_LAPSE_SAMPLE_PERIOD * 1000;

    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void LimitSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_LIMIT;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_LIMIT;

    /* init item img id */
    m_content[VAPP_CAMCO_LIMIT_NO_LIMIT]->setStr(STR_ID_VAPP_CAMCO_LIMIT_NO_LIMIT);
    m_content[VAPP_CAMCO_LIMIT_TIME_15S]->setStr(STR_ID_VAPP_CAMCO_LIMIT_TIME_15S);
    m_content[VAPP_CAMCO_LIMIT_TIME_30S]->setStr(STR_ID_VAPP_CAMCO_LIMIT_TIME_30S);
    m_content[VAPP_CAMCO_LIMIT_TIME_60S]->setStr(STR_ID_VAPP_CAMCO_LIMIT_TIME_60S);
    m_content[VAPP_CAMCO_LIMIT_TIME_300S]->setStr(STR_ID_VAPP_CAMCO_LIMIT_TIME_300S);
    m_content[VAPP_CAMCO_LIMIT_TIME_600S]->setStr(STR_ID_VAPP_CAMCO_LIMIT_TIME_600S);
    m_content[VAPP_CAMCO_LIMIT_SIZE_95K]->setStr(STR_ID_VAPP_CAMCO_LIMIT_SIZE_95K);
    m_content[VAPP_CAMCO_LIMIT_SIZE_195K]->setStr(STR_ID_VAPP_CAMCO_LIMIT_SIZE_195K);
    m_content[VAPP_CAMCO_LIMIT_SIZE_295K]->setStr(STR_ID_VAPP_CAMCO_LIMIT_SIZE_295K);

    m_content[VAPP_CAMCO_LIMIT_NO_LIMIT]->setStatusIcon(0);
    m_content[VAPP_CAMCO_LIMIT_TIME_15S]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_LIMIT_15S_ICON);
    m_content[VAPP_CAMCO_LIMIT_TIME_30S]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_LIMIT_30S_ICON);
    m_content[VAPP_CAMCO_LIMIT_TIME_60S]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_LIMIT_60S_ICON);
    m_content[VAPP_CAMCO_LIMIT_TIME_300S]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_LIMIT_300S_ICON);
    m_content[VAPP_CAMCO_LIMIT_TIME_600S]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_LIMIT_600S_ICON);
    m_content[VAPP_CAMCO_LIMIT_SIZE_95K]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_LIMIT_95K_ICON);
    m_content[VAPP_CAMCO_LIMIT_SIZE_195K]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_LIMIT_195K_ICON);
    m_content[VAPP_CAMCO_LIMIT_SIZE_295K]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_LIMIT_295K_ICON);

    m_extLimit = -1;
}

void LimitSetting::setDefault(void)
{
    /* init capability */
    m_cap = ENABLE();
    m_content[VAPP_CAMCO_LIMIT_NO_LIMIT]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_LIMIT_TIME_15S]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_LIMIT_TIME_30S]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_LIMIT_TIME_60S]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
#if defined(__TIME_LAPSE_VIDEO_RECORDER__)
    m_content[VAPP_CAMCO_LIMIT_TIME_300S]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_LIMIT_TIME_600S]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
#endif
#ifndef MJPG_ENCODE
    m_content[VAPP_CAMCO_LIMIT_SIZE_95K]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_LIMIT_SIZE_195K]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_LIMIT_SIZE_295K]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
#endif /* MJPG_ENCODE */
    m_content[VAPP_CAMCO_LIMIT_NO_LIMIT]->setValue(VAPP_CAMCO_LIMIT_NO_LIMIT);
    m_content[VAPP_CAMCO_LIMIT_TIME_15S]->setValue(VAPP_CAMCO_LIMIT_TIME_15S);
    m_content[VAPP_CAMCO_LIMIT_TIME_30S]->setValue(VAPP_CAMCO_LIMIT_TIME_30S);
    m_content[VAPP_CAMCO_LIMIT_TIME_60S]->setValue(VAPP_CAMCO_LIMIT_TIME_60S);
    m_content[VAPP_CAMCO_LIMIT_TIME_300S]->setValue(VAPP_CAMCO_LIMIT_TIME_300S);
    m_content[VAPP_CAMCO_LIMIT_TIME_600S]->setValue(VAPP_CAMCO_LIMIT_TIME_600S);
    m_content[VAPP_CAMCO_LIMIT_SIZE_95K]->setValue(VAPP_CAMCO_LIMIT_SIZE_95K);
    m_content[VAPP_CAMCO_LIMIT_SIZE_195K]->setValue(VAPP_CAMCO_LIMIT_SIZE_195K);
    m_content[VAPP_CAMCO_LIMIT_SIZE_295K]->setValue(VAPP_CAMCO_LIMIT_SIZE_295K);

    // ext calling config
    if(m_settingMgr->IsExtSetting())
    {
        for(VfxU32 i = 0; i < m_settingMgr->m_callingParam.settingLimitNum; i++)
        {
            if(m_settingMgr->m_callingParam.settingLimitation[i].type == VCUI_CAMCO_SETTING_LIMIT_RECLIMIT)
            {
                m_extIsSizeLimit = (m_settingMgr->m_callingParam.settingLimitation[i].detail == VCUI_CAMCO_SETTING_LIMIT_RECLIMIT_SIZE);
                m_extLimit = m_settingMgr->m_callingParam.settingLimitation[i].additionalInfo;
                m_cap = NOT_SUPPORT();
                break;
            }
        }
    }

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_LIMIT, m_currentValue);

    CheckandSet(VAPP_CAMCO_LIMIT_NO_LIMIT);
}

void LimitSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_RECSIZE)
    {
        if(change_value > VAPP_CAMCO_RECSIZE_CIF)
        {
            setSettingBound(VAPP_CAMCO_SETTING_RECSIZE, VAPP_CAMCO_LIMIT_NO_LIMIT, VAPP_CAMCO_LIMIT_TIME_600S);

            if(m_currentValue > VAPP_CAMCO_LIMIT_TIME_600S)
                setValue(VAPP_CAMCO_LIMIT_NO_LIMIT);
        }
        else
        {
            setSettingBound(VAPP_CAMCO_SETTING_RECSIZE, VAPP_CAMCO_LIMIT_NO_LIMIT, VAPP_CAMCO_LIMIT_SIZE_295K);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_TIMELAPSE)
    {
        if(change_value == VAPP_CAMCO_TIME_LAPSE_ON)
        {
            m_content[VAPP_CAMCO_LIMIT_TIME_15S]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_LIMIT_TIME_30S]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_LIMIT_TIME_60S]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_LIMIT_TIME_300S]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_ENABLED);
            m_content[VAPP_CAMCO_LIMIT_TIME_600S]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_ENABLED);
            m_content[VAPP_CAMCO_LIMIT_SIZE_95K]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_LIMIT_SIZE_195K]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_LIMIT_SIZE_295K]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_DISABLED);

        }
        else
        {
            m_content[VAPP_CAMCO_LIMIT_TIME_15S]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_ENABLED);
            m_content[VAPP_CAMCO_LIMIT_TIME_30S]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_ENABLED);
            m_content[VAPP_CAMCO_LIMIT_TIME_60S]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_ENABLED);
            m_content[VAPP_CAMCO_LIMIT_TIME_300S]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_LIMIT_TIME_600S]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_LIMIT_SIZE_95K]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_ENABLED);
            m_content[VAPP_CAMCO_LIMIT_SIZE_195K]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_ENABLED);
            m_content[VAPP_CAMCO_LIMIT_SIZE_295K]->setStatus(VAPP_CAMCO_SETTING_TIMELAPSE, VAPP_CAMCO_SETTING_CAP_ENABLED);
        }

        if(m_currentValue != VAPP_CAMCO_LIMIT_NO_LIMIT)
            setValue(VAPP_CAMCO_LIMIT_NO_LIMIT);
    }
}

void LimitSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();
}

VfxU32 LimitSetting::getSizeLimit(void)
{
    if(m_extLimit < 0)
    {
        if(m_currentValue == VAPP_CAMCO_LIMIT_NO_LIMIT || m_currentValue == VAPP_CAMCO_LIMIT_TIME_15S || m_currentValue == VAPP_CAMCO_LIMIT_TIME_30S || m_currentValue == VAPP_CAMCO_LIMIT_TIME_60S || m_currentValue == VAPP_CAMCO_LIMIT_TIME_300S || m_currentValue == VAPP_CAMCO_LIMIT_TIME_600S)
        {
            return 0;
        }
        else
        {
            if(m_currentValue == VAPP_CAMCO_LIMIT_SIZE_95K)
                return 95;
            if(m_currentValue == VAPP_CAMCO_LIMIT_SIZE_195K)
                return 195;
            if(m_currentValue == VAPP_CAMCO_LIMIT_SIZE_295K)
                return 295;
        }
    }
    else
    {
        if(m_extIsSizeLimit)
            return m_extLimit;
        else
            return 0;
    }
    return 0;
}

VfxU32 LimitSetting::getTimeLimit(void)
{
    if(m_extLimit < 0)
    {
        if(m_currentValue == VAPP_CAMCO_LIMIT_NO_LIMIT || m_currentValue == VAPP_CAMCO_LIMIT_SIZE_95K || m_currentValue == VAPP_CAMCO_LIMIT_SIZE_195K || m_currentValue == VAPP_CAMCO_LIMIT_SIZE_295K)
        {
            return 0;
        }
        else
        {
            if(m_currentValue == VAPP_CAMCO_LIMIT_TIME_15S)
                return 15;
            if(m_currentValue == VAPP_CAMCO_LIMIT_TIME_30S)
                return 30;
            if(m_currentValue == VAPP_CAMCO_LIMIT_TIME_60S)
                return 60;
            if(m_currentValue == VAPP_CAMCO_LIMIT_TIME_300S)
                return 300;
            if(m_currentValue == VAPP_CAMCO_LIMIT_TIME_600S)
                return 600;
        }
    }
    else
    {
        if(!m_extIsSizeLimit)
            return m_extLimit;
        else
            return 0;
    }
    return 0;
}

void VisQtySetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_VISQTY;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_VISQTY;

    /* init item img id */
    m_content[VAPP_CAMCO_VISQTY_FINE]->setStr(STR_ID_VAPP_CAMCO_VISQTY_FINE);
    m_content[VAPP_CAMCO_VISQTY_GOOD]->setStr(STR_ID_VAPP_CAMCO_VISQTY_GOOD);
    m_content[VAPP_CAMCO_VISQTY_NORMAL]->setStr(STR_ID_VAPP_CAMCO_VISQTY_NORMAL);
    m_content[VAPP_CAMCO_VISQTY_LOW]->setStr(STR_ID_VAPP_CAMCO_VISQTY_LOW);
    m_content[VAPP_CAMCO_VISQTY_LCD]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_WALLPAPER);
}

void VisQtySetting::setDefault(void)
{
    m_cap = ENABLE();

    m_content[VAPP_CAMCO_VISQTY_FINE]->setValue(VAPP_CAMCO_VISQTY_FINE);
    m_content[VAPP_CAMCO_VISQTY_GOOD]->setValue(VAPP_CAMCO_VISQTY_GOOD);
    m_content[VAPP_CAMCO_VISQTY_NORMAL]->setValue(VAPP_CAMCO_VISQTY_NORMAL);
    m_content[VAPP_CAMCO_VISQTY_LOW]->setValue(VAPP_CAMCO_VISQTY_LOW);
    m_content[VAPP_CAMCO_VISQTY_LCD]->setValue(VAPP_CAMCO_VISQTY_LCD);

    mdi_video_rec_spec_struct spec_entry_struct;
    VfxU32 count = mdi_video_rec_query_entry_num_of_video_spec_table();
    for(VfxU32 i=0; i < count; i++)
    {
        //VfxU32 currectQty = VAPP_CAMCO_VISQTY_FINE;
        MDI_RESULT  ret = mdi_video_rec_get_video_spec_by_index(i, &spec_entry_struct, sizeof(spec_entry_struct));

        if(ret != MDI_RES_VDOREC_SUCCEED)
            continue;

        switch (spec_entry_struct.quality)
        {
            case MDI_VIDEO_REC_QTY_LOW:
                m_content[VAPP_CAMCO_VISQTY_LOW]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                //currectQty = VAPP_CAMCO_VISQTY_LOW;
                break;
            case MDI_VIDEO_REC_QTY_NORMAL:
                m_content[VAPP_CAMCO_VISQTY_NORMAL]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                //currectQty = VAPP_CAMCO_VISQTY_NORMAL;
                break;
            case MDI_VIDEO_REC_QTY_FINE:
                m_content[VAPP_CAMCO_VISQTY_FINE]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                //currectQty = VAPP_CAMCO_VISQTY_FINE;
                break;
            case MDI_VIDEO_REC_QTY_HIGH:
                m_content[VAPP_CAMCO_VISQTY_GOOD]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                //currectQty = VAPP_CAMCO_VISQTY_GOOD;
                break;
        }
    }

    config_recqty_capability(VAPP_CAMCO_SETTING_VISQTY);
    if(!m_settingMgr->IsExtSetting())
    {
        CheckandSet(-1);
    }
    else
    {
        for(VfxU32 i = 0; i < m_settingMgr->m_callingParam.settingLimitNum; i++)
        {
            if(m_settingMgr->m_callingParam.settingLimitation[i].type == VCUI_CAMCO_SETTING_LIMIT_RECQTY)
            {
                if(m_settingMgr->m_callingParam.settingLimitation[i].detail == VCUI_CAMCO_SETTING_LIMIT_RECQTY_MMS_QTY)
                {
                    m_content[VAPP_CAMCO_VISQTY_FINE]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
                    m_content[VAPP_CAMCO_VISQTY_GOOD]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
                    m_content[VAPP_CAMCO_VISQTY_NORMAL]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
                    m_content[VAPP_CAMCO_VISQTY_LCD]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
                    CheckandSet(VAPP_CAMCO_VISQTY_LOW);
                }
                break;
            }
        }
        CheckandSet(-1);
    }
}

void VisQtySetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_RECSIZE)
    {
        config_recqty_capability(VAPP_CAMCO_SETTING_RECSIZE);
    }
    else if(change_setting == VAPP_CAMCO_SETTING_VISCODEC)
    {
        config_recqty_capability(VAPP_CAMCO_SETTING_VISCODEC);
    }
    else if(change_setting == VAPP_CAMCO_SETTING_VDOSTORAGE)
    {
        config_recqty_capability(VAPP_CAMCO_SETTING_VDOSTORAGE);
    }
}

void VisQtySetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();
}

VfxU32 VisQtySetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_VISQTY_FINE:
            return MDI_VIDEO_REC_QTY_FINE;

        case VAPP_CAMCO_VISQTY_GOOD:
            return MDI_VIDEO_REC_QTY_HIGH;

        case VAPP_CAMCO_VISQTY_NORMAL:
            return MDI_VIDEO_REC_QTY_NORMAL;

        case VAPP_CAMCO_VISQTY_LOW:
            return MDI_VIDEO_REC_QTY_LOW;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void VisQtySetting::config_recqty_capability(vapp_camco_setting_enum changed_setting)
{
    // Qty may be key setting and need to show all
    // others depended setting will be hide
    if(recorder_config_has_dependency() && (recorder_config_is_key(m_settingMgr->transTargetFromMMI(m_settingType))))
    {
        // Let qty always show, or user will not be able to choose some time if setting is independant to each other
        for (VfxU32 idx = 0; idx < VAPP_CAMCO_VISQTY_END; idx++)
        {
            if (getItem(idx).getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
            {
                m_content[idx]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
            }
        }
    }
    else
    {
        VfxU16 reccodec = m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISCODEC);
        VfxU32 recsize = m_settingMgr->getValue(VAPP_CAMCO_SETTING_RECSIZE);
        VfxU32 recqty = m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISQTY);
        VfxU32 storage = m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSTORAGE);

        if(storage == SRV_FMGR_DRV_PHONE_TYPE || storage == SRV_FMGR_DRV_PHONE_2_TYPE)
        {
            storage = 0;
        }
        else if(storage == SRV_FMGR_DRV_CARD_TYPE || storage == SRV_FMGR_DRV_CARD_2_TYPE)
        {
            storage = 1;
        }
        VfxU32 maxMatchCouunt = 0;
        VfxBool currSettingMatch = VFX_FALSE;

        VfxU32 selectedRecsize = recsize, selectedRecqty = recqty, selectedStorage = storage;

        for (VfxU32 j = 0; j < VAPP_CAMCO_VISQTY_END; j++)
        {
            if (getItem(j).getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
            {
                VfxBool isActive = VFX_FALSE;

                for (VfxU32 i = 0; i < VAPP_CAMCO_RECSIZE_END; i++)
                {
                    for (VfxU32 k = 0; k < 2; k++)
                    {
                        if (vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[reccodec][i][j][k])
                        {
                            VfxU32 matchCouunt = 0;
                            VfxBool isChangedSettingMatch = VFX_FALSE;

                            if(i == recsize)
                            {
                                matchCouunt++;
                                if(changed_setting == VAPP_CAMCO_SETTING_RECSIZE)
                                {
                                    isChangedSettingMatch = VFX_TRUE;
                                }
                            }
                            if(j == recqty)
                            {
                                matchCouunt++;
                                if(changed_setting == VAPP_CAMCO_SETTING_VISQTY)
                                {
                                    isChangedSettingMatch = VFX_TRUE;
                                }
                            }
                            if(k == storage)
                            {
                                matchCouunt++;
                                if(changed_setting == VAPP_CAMCO_SETTING_VDOSTORAGE)
                                {
                                    isChangedSettingMatch = VFX_TRUE;
                                }
                            }

                            if((maxMatchCouunt < matchCouunt) || ((!currSettingMatch)&&isChangedSettingMatch))
                            {
                                selectedRecsize = i;
                                selectedRecqty = j;
                                selectedStorage = k;
                                maxMatchCouunt = matchCouunt;
                                currSettingMatch = isChangedSettingMatch;
                            }
                            isActive = VFX_TRUE;

                        }
                    }
                }

                if (isActive)
                {
                    m_content[j]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
                }
                else
                {
                    m_content[j]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_DISABLED);
                }

            }
        }
        if (m_currentValue == 0xFF ||
            m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED ||
            !vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[reccodec][recsize][recqty][storage])
        {
            if(selectedRecsize != recsize)
            {
                m_settingMgr->setValue(VAPP_CAMCO_SETTING_RECSIZE, selectedRecsize);
            }

            if(selectedRecqty != recqty)
            {
                m_settingMgr->setValue(VAPP_CAMCO_SETTING_VISQTY, selectedRecqty);
            }

            if(selectedStorage != storage)
            {
                if(selectedStorage == 0)
                    m_settingMgr->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, SRV_FMGR_DRV_PHONE_TYPE);
                else
                    m_settingMgr->setValue(VAPP_CAMCO_SETTING_VDOSTORAGE, SRV_FMGR_DRV_CARD_TYPE);
            }
        }
    }
}

void VisCodecSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_VISCODEC;

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_VISCODEC;

    /* init item img id */
    m_content[VAPP_CAMCO_VISCODEC_3GP]->setStr(STR_ID_VAPP_CAMCO_VISCODEC_3GP);
    m_content[VAPP_CAMCO_VISCODEC_MP4]->setStr(STR_ID_VAPP_CAMCO_VISCODEC_MP4);
    m_content[VAPP_CAMCO_VISCODEC_MJPG]->setStr(STR_ID_VAPP_CAMCO_VISCODEC_MJPG);
    m_content[VAPP_CAMCO_VISCODEC_H264]->setStr(STR_ID_VAPP_CAMCO_VISCODEC_H264);
}

void VisCodecSetting::setDefault(void)
{
    m_cap = ENABLE();

    mdi_video_rec_spec_struct spec_entry_struct;
    VfxU32 count = mdi_video_rec_query_entry_num_of_video_spec_table();
    for(VfxU32 i=0; i < count; i++)
    {
        //VfxU32 currectCodec = VAPP_CAMCO_VISCODEC_MP4;
        MDI_RESULT  ret = mdi_video_rec_get_video_spec_by_index(i, &spec_entry_struct, sizeof(spec_entry_struct));

        if(ret != MDI_RES_VDOREC_SUCCEED)
            continue;

        switch (spec_entry_struct.video_format)
        {
            case MDI_VIDEO_VIDEO_FORMAT_3GP:
                m_content[VAPP_CAMCO_VISCODEC_3GP]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                //currectCodec = VAPP_CAMCO_VISCODEC_3GP;
                break;
            case MDI_VIDEO_VIDEO_FORMAT_MP4:
                m_content[VAPP_CAMCO_VISCODEC_MP4]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                //currectCodec = VAPP_CAMCO_VISCODEC_MP4;
                break;
            case MDI_VIDEO_VIDEO_FORMAT_MJPEG:
                m_content[VAPP_CAMCO_VISCODEC_MJPG]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                //currectCodec = VAPP_CAMCO_VISCODEC_MJPG;
                break;
            case MDI_VIDEO_VIDEO_FORMAT_H264:
                m_content[VAPP_CAMCO_VISCODEC_H264]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
                //currectCodec = VAPP_CAMCO_VISCODEC_H264;
                break;
        }
    }
    m_content[VAPP_CAMCO_VISCODEC_3GP]->setValue(VAPP_CAMCO_VISCODEC_3GP);
    m_content[VAPP_CAMCO_VISCODEC_MP4]->setValue(VAPP_CAMCO_VISCODEC_MP4);
    m_content[VAPP_CAMCO_VISCODEC_MJPG]->setValue(VAPP_CAMCO_VISCODEC_MJPG);
    m_content[VAPP_CAMCO_VISCODEC_H264]->setValue(VAPP_CAMCO_VISCODEC_H264);

    config_reccodec_capability(VAPP_CAMCO_SETTING_VISCODEC);

    if(m_settingMgr->IsExtSetting() && m_content[VAPP_CAMCO_VISCODEC_3GP]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
        CheckandSet(VAPP_CAMCO_VISCODEC_3GP);
    else
        CheckandSet(-1);
}

void VisCodecSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_VISQTY)
    {
        config_reccodec_capability(VAPP_CAMCO_SETTING_VISQTY);
    }
    else if(change_setting == VAPP_CAMCO_SETTING_RECSIZE)
    {
        config_reccodec_capability(VAPP_CAMCO_SETTING_RECSIZE);
    }
    else if(change_setting == VAPP_CAMCO_SETTING_VDOSTORAGE)
    {
        config_reccodec_capability(VAPP_CAMCO_SETTING_VDOSTORAGE);
    }
}

void VisCodecSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();
}

VfxU32 VisCodecSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_VISCODEC_3GP:
            return MDI_VIDEO_VIDEO_FORMAT_3GP;

        case VAPP_CAMCO_VISCODEC_MP4:
            return MDI_VIDEO_VIDEO_FORMAT_MP4;

        case VAPP_CAMCO_VISCODEC_MJPG:
            return MDI_VIDEO_VIDEO_FORMAT_MJPEG;

        case VAPP_CAMCO_VISCODEC_H264:
            return MDI_VIDEO_VIDEO_FORMAT_H264;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void VisCodecSetting::config_reccodec_capability(vapp_camco_setting_enum changed_setting)
{
    // Let codec always show, or user will not be able to choose some time if setting is independant to each other
    for (VfxU32 idx = 0; idx < VAPP_CAMCO_VISCODEC_END; idx++)
    {
        if (getItem(idx).getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            m_content[idx]->setStatus(VAPP_CAMCO_SETTING_VISCODEC, VAPP_CAMCO_SETTING_CAP_ENABLED);
        }
    }
}

void CamEVSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CAMEV;

    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_EV;
}

void CamEVSetting::setDefault(void)
{
    CamcoSettingItem::setDefault();

    m_maxValue = VAPP_CAMCO_EV_N4;
    m_minValue = VAPP_CAMCO_EV_P4;
    for(VfxU32 i=VAPP_CAMCO_EV_N4; i<= VAPP_CAMCO_EV_P4; i++)
    {
        if(m_content[i]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
        {
            if(i > m_maxValue)
                m_maxValue = i;
            if(i < m_minValue)
                m_minValue = i;
        }
    }
    setValue(VAPP_CAMCO_EV_0);
}

void CamEVSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_ACT_APP)
    {
        if(change_value == VAPP_CAMCO_APP_CAMERA)
        {
            setValue(m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOEV));
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_ASD)
    {
        if(change_value == VAPP_CAMCO_SCENE_DETECT_ON)
        {
            setValue(VAPP_CAMCO_EV_0);
            hide(VAPP_CAMCO_SETTING_ASD);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_ASD);
        }
    }
}

void CamEVSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    if(v > m_maxValue)
        v = m_maxValue;
    if(v < m_minValue)
        v = m_minValue;

    CamcoSettingItem::setValue(v);
    mdi_camera_update_para_ev(getMappingID(v));
}

MMI_BOOL CamEVSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    mdi_camera_query_support_info(MDI_CAMERA_SETTING_EV, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (VfxU32 idx = 0; idx < cap_info->item_count; idx++)
    {
        VfxU16 item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_EV_N4:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_N4;
                break;

            case MDI_CAMERA_EV_N3:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_N3;
                break;

            case MDI_CAMERA_EV_N2:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_N2;
                break;

            case MDI_CAMERA_EV_N1:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_N1;
                break;

            case MDI_CAMERA_EV_0:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_0;
                break;

            case MDI_CAMERA_EV_P1:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_P1;
                break;

            case MDI_CAMERA_EV_P2:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_P2;
                break;

            case MDI_CAMERA_EV_P3:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_P3;
                break;

            case MDI_CAMERA_EV_P4:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_P4;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;

        }
    }
    return MMI_TRUE;
}

VfxU32 CamEVSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_EV_N4:
            return MDI_CAMERA_EV_N4;

        case VAPP_CAMCO_EV_N3:
            return MDI_CAMERA_EV_N3;

        case VAPP_CAMCO_EV_N2:
            return MDI_CAMERA_EV_N2;

        case VAPP_CAMCO_EV_N1:
            return MDI_CAMERA_EV_N1;

        case VAPP_CAMCO_EV_0:
            return MDI_CAMERA_EV_0;

        case VAPP_CAMCO_EV_P1:
            return MDI_CAMERA_EV_P1;

        case VAPP_CAMCO_EV_P2:
            return MDI_CAMERA_EV_P2;

        case VAPP_CAMCO_EV_P3:
            return MDI_CAMERA_EV_P3;

        case VAPP_CAMCO_EV_P4:
            return MDI_CAMERA_EV_P4;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void CamEVSetting::applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    mdi_camera_update_para_ev(getMappingID(v));
}

void CamEVSetting::resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        mdi_camera_update_para_ev(getMappingID(m_currentValue));
    }
}

VfxU32 CamEVSetting::getMaxValue(void)
{
    return m_maxValue;
}

VfxU32 CamEVSetting::getMinValue(void)
{
    return m_minValue;
}

void VdoEVSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_VDOEV;

    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_CAMCO_EV;
}

void VdoEVSetting::setDefault(void)
{
    CamcoSettingItem::setDefault();

    m_maxValue = VAPP_CAMCO_EV_N4;
    m_minValue = VAPP_CAMCO_EV_P4;
    for(VfxU32 i=VAPP_CAMCO_EV_N4; i<= VAPP_CAMCO_EV_P4; i++)
    {
        if(m_content[i]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
        {
            if(i > m_maxValue)
                m_maxValue = i;
            if(i < m_minValue)
                m_minValue = i;
        }
    }
    setValue(VAPP_CAMCO_EV_0);
}

void VdoEVSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_ACT_APP)
    {
        if(change_value == VAPP_CAMCO_APP_RECORDER)
        {
            setValue(m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMEV));
        }
    }
}

void VdoEVSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    if(v > m_maxValue)
        v = m_maxValue;
    if(v < m_minValue)
        v = m_minValue;

    CamcoSettingItem::setValue(v);
    mdi_video_rec_update_para_ev(getMappingID(v));
}

MMI_BOOL VdoEVSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_EV, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (VfxU32 idx = 0; idx < cap_info->item_count; idx++)
    {
        VfxU16 item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_EV_N4:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_N4;
                break;

            case MDI_CAMERA_EV_N3:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_N3;
                break;

            case MDI_CAMERA_EV_N2:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_N2;
                break;

            case MDI_CAMERA_EV_N1:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_N1;
                break;

            case MDI_CAMERA_EV_0:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_0;
                break;

            case MDI_CAMERA_EV_P1:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_P1;
                break;

            case MDI_CAMERA_EV_P2:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_P2;
                break;

            case MDI_CAMERA_EV_P3:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_P3;
                break;

            case MDI_CAMERA_EV_P4:
                cap_info->support_item[idx] = VAPP_CAMCO_EV_P4;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;

        }
    }
    return MMI_TRUE;
}

VfxU32 VdoEVSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_EV_N4:
            return MDI_CAMERA_EV_N4;

        case VAPP_CAMCO_EV_N3:
            return MDI_CAMERA_EV_N3;

        case VAPP_CAMCO_EV_N2:
            return MDI_CAMERA_EV_N2;

        case VAPP_CAMCO_EV_N1:
            return MDI_CAMERA_EV_N1;

        case VAPP_CAMCO_EV_0:
            return MDI_CAMERA_EV_0;

        case VAPP_CAMCO_EV_P1:
            return MDI_CAMERA_EV_P1;

        case VAPP_CAMCO_EV_P2:
            return MDI_CAMERA_EV_P2;

        case VAPP_CAMCO_EV_P3:
            return MDI_CAMERA_EV_P3;

        case VAPP_CAMCO_EV_P4:
            return MDI_CAMERA_EV_P4;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void VdoEVSetting::applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    mdi_video_rec_update_para_ev(getMappingID(v));
}

void VdoEVSetting::resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        mdi_video_rec_update_para_ev(getMappingID(m_currentValue));
    }
}

VfxU32 VdoEVSetting::getMaxValue(void)
{
    return m_maxValue;
}

VfxU32 VdoEVSetting::getMinValue(void)
{
    return m_minValue;
}

void CamZoomSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CAMZOOM;
}

void CamZoomSetting::setDefault(void)
{
    vapp_camco_zoom_info zoom_info;

    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    mdi_camera_query_zoom_info(&zoom_info);

    m_cap = ENABLE();

    m_maxValue = zoom_info.max_zoom_factor;
    m_minValue = 100;
    m_currentFactor = m_minValue;

    m_maxStep= zoom_info.zoom_steps;
    m_minStep = 0;

    setValue(m_minStep);

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_CAMZOOM, m_minStep);
}

void CamZoomSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_CAPSIZE)
    {
        setDefault();
    }
}

MMI_BOOL CamZoomSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    return MMI_FALSE;
}

void CamZoomSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    if(v < m_minStep)
        v = m_minStep;
    if(v > m_maxStep)
        v = m_maxStep;

    CamcoSettingItem::setValue(v);

    VfxU32 current_idx = 100;
    mdi_camera_update_para_zoom(v);
    mdi_camera_get_fast_zoom_factor(&current_idx);
    setFactor(current_idx);
}

void CamZoomSetting::setFactor(VfxU16 v)
{
    m_currentFactor = v;
}

void VdoZoomSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_VDOZOOM;
}

void VdoZoomSetting::setDefault(void)
{
    vapp_camco_zoom_info zoom_info;

    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    mdi_video_rec_query_zoom_info(&zoom_info);

    m_cap = ENABLE();

    m_maxValue = zoom_info.max_zoom_factor;
    m_minValue = 100;
    m_currentFactor = m_minStep;

    m_maxStep= zoom_info.zoom_steps;
    m_minStep = 0;

    setValue(m_minStep);

    MMI_TRACE(TRACE_GROUP_2,TRC_VAPP_CAMCO_EXPRESS_SETTING_DEFAULT_VDOZOOM, m_minStep);
}

void VdoZoomSetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

    if(change_setting == VAPP_CAMCO_SETTING_RECSIZE)
    {
        setDefault();
    }
}

MMI_BOOL VdoZoomSetting::queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    return MMI_FALSE;
}

void VdoZoomSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    if(v < m_minStep)
        v = m_minStep;
    if(v > m_maxStep)
        v = m_maxStep;

    CamcoSettingItem::setValue(v);

    VfxU32 current_idx = 100;
    mdi_video_rec_update_para_zoom(v);
    mdi_video_rec_get_fast_zoom_factor(&current_idx);
    setFactor(current_idx);
}

void VdoZoomSetting::setFactor(VfxU16 v)
{
    m_currentFactor = v;
}

#endif /*__VAPP_CAMCO_EXPRESS__*/
