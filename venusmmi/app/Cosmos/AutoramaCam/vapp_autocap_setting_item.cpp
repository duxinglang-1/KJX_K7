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
#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))

#include "Mmi_rp_vapp_autocap_common_def.h"
#include "vapp_autocap_setting_item.h"
#include "vapp_autocap_setting_mgr.h"
#include "vcui_camco_gprot.h"

#if defined(HORIZONTAL_CAMERA)

#if defined(__CAMERA_CAPTURE_STANDARD_SET__)
VfxBool vapp_autocap_capmode_vs_capsize[VAPP_AUTOCAP_CAPMODE_END][VAPP_AUTOCAP_CAPSIZE_END] = 
{
    {VFX_FALSE, VFX_FALSE, VFX_TRUE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
};

#else 
VfxBool vapp_autocap_capmode_vs_capsize[VAPP_AUTOCAP_CAPMODE_END][VAPP_AUTOCAP_CAPSIZE_END] = 
{
    {VFX_FALSE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
};

#endif 
#else /* defined(HORIZONTAL_CAMERA) */ 

#if defined(__CAMERA_CAPTURE_STANDARD_SET__)
VfxBool vapp_autocap_capmode_vs_capsize[VAPP_AUTOCAP_CAPMODE_END][VAPP_AUTOCAP_CAPSIZE_END] = 
{
    {VFX_FALSE, VFX_TRUE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
};

#else 
VfxBool vapp_autocap_capmode_vs_capsize[VAPP_AUTOCAP_CAPMODE_END][VAPP_AUTOCAP_CAPSIZE_END] = 
{
    {VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
};

#endif 
#endif /* defined(HORIZONTAL_CAMERA) */ 

VfxBool vapp_autocap_recsize_vs_recqty_vs_storage_vs_codec[VAPP_AUTOCAP_RECSIZE_END][VAPP_AUTOCAP_VISQTY_END][2][VAPP_AUTOCAP_VISCODEC_END];
vapp_autocap_banding_enum g_vapp_autocap_banding_setting;

#define VAPP_AUTOCAP_SETTING_CHECK \
    if(m_cap == (1ll << VAPP_AUTOCAP_SETTING_STATUS_DRV_NOT_SUPPORT)) \
        return;


void AutoCapSettingItem::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK

    ASSERT(v != VAPP_AUTOCAP_SETTING_DUMMY_VALUE);
    
    if(m_currentValue != 0xff)
        m_lastValue = m_currentValue;
    else
        m_lastValue = VAPP_AUTOCAP_SETTING_NA;
    //if(m_currentValue != v)
    {
        m_currentValue = v;
        m_signalSettingModified.emit(m_settingType, v, m_lastValue);
    }
};        

void AutoCapSettingItem::resetValue(VfxU16 v)
{
    m_currentValue = v;
}

void AutoCapSettingItem::hide(vapp_autocap_setting_enum setting)
{
    if(!IS_NOT_SUPPORT(m_cap))
        m_cap |= (1ll << setting);      
};        

void AutoCapSettingItem::show(vapp_autocap_setting_enum setting)
{
    if(!IS_NOT_SUPPORT(m_cap))
        m_cap &= ~(1ll << setting);   
};                 

void AutoCapSettingItem :: setSettingBound(vapp_autocap_setting_enum setting, VfxU16 start, VfxU16 end)
{
    for(VfxU16 i = 0; i < VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT;i++)
    {
        if(i >= start && i <= end)
        {
            if(m_content[i]->getStatus() != VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT)
            {
                m_content[i]->setStatus(setting, VAPP_AUTOCAP_SETTING_CAP_ENABLED);
            }
        }                
        else
        {
            if(m_content[i]->getStatus() != VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT)
            {
                m_content[i]->setStatus(setting, VAPP_AUTOCAP_SETTING_CAP_DISABLED);
            }
        }               
    }
};

void AutoCapSettingItem::initialize(void)
{

    for(VfxU8 i =0; i < VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT;i++)
    {
        m_content[i]->initialize();
    }
    
    m_cap = NOT_SUPPORT();
    m_statusBitMap = 0;
    m_mainImgId = 0;
    m_mainStrId = 0;
    m_isHiliteMode = VFX_FALSE;    
}

void AutoCapSettingItem::setDefault(void)
{
    vapp_autocap_cap_info cap_info;
    S32 idx;

    if (queryCapbilityInfo(&cap_info))
    {
        m_cap = ENABLE();
        for (idx = 0; idx < cap_info.item_count; idx++)
        {
            if (cap_info.support_item[idx] != VAPP_AUTOCAP_SETTING_DUMMY_VALUE)
            {
                m_content[cap_info.support_item[idx]]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);            
                m_content[cap_info.support_item[idx]]->setValue(cap_info.support_item[idx]);                   
            }             
        }
    }
    else
    {
        m_cap = NOT_SUPPORT();
    }

}

MMI_BOOL AutoCapSettingItem::queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    return MMI_FALSE;
}

VfxU32 AutoCapSettingItem::getMappingID(VfxU32 mmiID)
{
    return 0;
}

VfxU32 AutoCapSettingItem::getMaxValue(void)
{
    return 0;
}

VfxU32 AutoCapSettingItem::getMinValue(void)
{
    return 0;
}

VfxU32 AutoCapSettingItem::getSettingCount(void)
{
    VfxU32 count = 0;
    for (VfxS32 idx = VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT - 1; idx >= 0; idx--)
    {
        if (m_content[idx]->getStatus() == VAPP_AUTOCAP_SETTING_CAP_ENABLED)
        {
            count++;
        }
    }
    return count;
}

void AutoCapSettingItem::CheckandSet(VfxS32 value)
{
    if(value >= 0) //it mean a certain value is set
    {
        if(IS_NOT_SUPPORT(m_cap))
        {
            resetValue(value);
        }   
        else
        {                 
            if (m_currentValue == 0xff || m_content[m_currentValue]->getStatus() != VAPP_AUTOCAP_SETTING_CAP_ENABLED)
            {
                setValue(value);
            }
        }
    }
    else //it mean to find a suitable value from current avaiable set
    {
        if (m_currentValue == 0xff || m_content[m_currentValue]->getStatus() != VAPP_AUTOCAP_SETTING_CAP_ENABLED)
        {
                           
            for (VfxU16 idx = VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT - 1; idx > 0; idx--)
            {
                if (m_content[idx]->getStatus() == VAPP_AUTOCAP_SETTING_CAP_ENABLED)
                {
                    setValue(idx);
                    break;
                }
            }
        }            
        ASSERT(m_currentValue != 0xff);
    }
}

void AutoCapSettingItem::applyEffect(VfxU16 v)
{
}

void AutoCapSettingItem::resetEffect(void)
{
}

void AutoCapSettingItem::onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_UPDATE, change_setting, change_value, last_value);
}

void AutoCapCameraSensorSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_ACT_CAM;    
}    

void AutoCapCameraSensorSetting :: setDefault(void)   
{
    m_cap = ENABLE();

    m_content[VAPP_AUTOCAP_SENSOR_MAIN_CAMERA]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_SENSOR_MAIN_CAMERA]->setValue(VAPP_AUTOCAP_SENSOR_MAIN_CAMERA);        
#if (defined(DUAL_CAMERA_SUPPORT))    
    m_content[VAPP_AUTOCAP_SENSOR_SUB_CAMERA]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_SENSOR_SUB_CAMERA]->setValue(VAPP_AUTOCAP_SENSOR_SUB_CAMERA);  
#else
    m_content[VAPP_AUTOCAP_SENSOR_SUB_CAMERA]->setStatus(VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT);
#endif
    CheckandSet(VAPP_AUTOCAP_SENSOR_MAIN_CAMERA);

}    

void AutoCapCameraSensorSetting :: setValue(VfxU16 v)    
{
    VAPP_AUTOCAP_SETTING_CHECK

    AutoCapSettingItem::setValue(v);
    mdi_camera_set_camera_id(getMappingID(v));
    mdi_video_set_camera_id(getMappingID(v));    
}    

VfxU32 AutoCapCameraSensorSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_SENSOR_MAIN_CAMERA:
            return MDI_CAMERA_MAIN;
            //break;

        case VAPP_AUTOCAP_SENSOR_SUB_CAMERA:
            return MDI_CAMERA_SUB;
            //break;

        default:
            return MDI_CAMERA_MAIN;
            //break;
    }

}    

void AutoCapCameraSensorSetting :: setCameraID(VfxU16 camid)
{
    mdi_camera_set_camera_id(getMappingID(camid));
    mdi_video_set_camera_id(getMappingID(camid));
}

void AutoCapCapModeSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_CAPMODE;            

    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_CAPMODE;    
    
};


void AutoCapCapModeSetting :: setDefault(void)
{
    AutoCapSettingItem :: setDefault();
    
    m_content[VAPP_AUTOCAP_CAPMODE_PANORAMA]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);       

    for(VfxU16 i = 0; i < VAPP_AUTOCAP_CAPMODE_END; i++)
    {
        m_content[i]->setValue(i);   
    }
                
#if defined(DUAL_CAMERA_SUPPORT) 

    if (m_settingMgr->getCurrCam() == VAPP_AUTOCAP_SENSOR_MAIN_CAMERA)
    {
        m_content[VAPP_AUTOCAP_CAPMODE_PANORAMA]->setStatus(VAPP_AUTOCAP_SETTING_CAPMODE, VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    }
    else
    {
        m_content[VAPP_AUTOCAP_CAPMODE_PANORAMA]->setStatus(VAPP_AUTOCAP_SETTING_CAPMODE, VAPP_AUTOCAP_SETTING_CAP_DISABLED);
    }
#endif /* defined(DUAL_CAMERA_SUPPORT) */ 
    
    CheckandSet(VAPP_AUTOCAP_CAPMODE_PANORAMA);

};

void AutoCapCapModeSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_AUTOCAP_SETTING_ACT_CAM)
    {
        if(change_value == VAPP_AUTOCAP_SENSOR_SUB_CAMERA)
        {
            m_content[VAPP_AUTOCAP_CAPMODE_PANORAMA]->setStatus(VAPP_AUTOCAP_SETTING_ACT_CAM, VAPP_AUTOCAP_SETTING_CAP_DISABLED);
        }
        else
        {
            m_content[VAPP_AUTOCAP_CAPMODE_PANORAMA]->setStatus(VAPP_AUTOCAP_SETTING_ACT_CAM, VAPP_AUTOCAP_SETTING_CAP_ENABLED);
        } 
    }
    else if(change_setting == VAPP_AUTOCAP_SETTING_CAPSIZE)
    {
        // basically, all capmode should show even current size is not match
        // we will update size when certain capmode is selected
        //
        // only for WP size, 
        // becasue horizontal/verticall screen difference, hide not match capmode        
        if (change_value == VAPP_AUTOCAP_CAPSIZE_WALLPAPER)
        {
            m_content[VAPP_AUTOCAP_CAPMODE_PANORAMA]->setStatus(VAPP_AUTOCAP_SETTING_CAPSIZE, VAPP_AUTOCAP_SETTING_CAP_DISABLED);
        }
        else
        {                            
            m_content[VAPP_AUTOCAP_CAPMODE_PANORAMA]->setStatus(VAPP_AUTOCAP_SETTING_CAPSIZE, VAPP_AUTOCAP_SETTING_CAP_ENABLED);
        } 

    }
       
};

void AutoCapCapModeSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK

    AutoCapSettingItem::setValue(v);

};

MMI_BOOL AutoCapCapModeSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;

    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAPMODE, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {                
            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;

}



void AutoCapCamSceneModeSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_CAMSCENEMODE;    
    
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_SCENEMODE;

    /* init item str id */
    m_content[VAPP_AUTOCAP_CAMSCENEMODE_AUTO]->setStr(STR_ID_VAPP_AUTOCAP_SCENEMODE_AUTO);
    m_content[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT]->setStr(STR_ID_VAPP_AUTOCAP_SCENEMODE_PORTRAIT);
    m_content[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE]->setStr(STR_ID_VAPP_AUTOCAP_SCENEMODE_LANDSCAPE);
    m_content[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT]->setStr(STR_ID_VAPP_AUTOCAP_SCENEMODE_NIGHT);
    m_content[VAPP_AUTOCAP_CAMSCENEMODE_SPORT]->setStr(STR_ID_VAPP_AUTOCAP_SCENEMODE_SPORT);
    m_content[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT]->setStr(STR_ID_VAPP_AUTOCAP_SCENEMODE_DOCUMENT);
    m_content[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE]->setStr(STR_ID_VAPP_AUTOCAP_SCENEMODE_ANTI_SHAKE);

};

void AutoCapCamSceneModeSetting :: setDefault(void)
{
    AutoCapSettingItem::setDefault();
    CheckandSet(VAPP_AUTOCAP_CAMSCENEMODE_AUTO);       
};

void AutoCapCamSceneModeSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
};

void AutoCapCamSceneModeSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK

    AutoCapSettingItem::setValue(v);
    if(m_lastValue != m_currentValue)
    {    
        m_settingMgr->needRestartPreview();
    }
};

MMI_BOOL AutoCapCamSceneModeSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    

    mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAMSCENE, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_SCENE_MODE_AUTO:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAMSCENEMODE_AUTO;
                break;

            case MDI_CAMERA_SCENE_MODE_PORTRAIT:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT;
                break;

            case MDI_CAMERA_SCENE_MODE_LANDSCAPE:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE;
                break;

            case MDI_CAMERA_SCENE_MODE_SPORT:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAMSCENEMODE_SPORT;
                break;
                
            case MDI_CAMERA_SCENE_MODE_NIGHT:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAMSCENEMODE_NIGHT;
                break;    
                
            case MDI_CAMERA_SCENE_MODE_DOCUMENT:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT;
                break;
                
            case MDI_CAMERA_SCENE_MODE_ISO_ANTI_HAND_SHAKE:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE;
                break;   
                
            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;
        }
    }


    return MMI_TRUE;

}

VfxU32 AutoCapCamSceneModeSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_CAMSCENEMODE_AUTO:
            return MDI_CAMERA_SCENE_MODE_AUTO;
           // break;

        case VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT:
            return MDI_CAMERA_SCENE_MODE_PORTRAIT;
            //break;

        case VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE:
            return MDI_CAMERA_SCENE_MODE_LANDSCAPE;
            //break;

        case VAPP_AUTOCAP_CAMSCENEMODE_SPORT:
            return MDI_CAMERA_SCENE_MODE_SPORT;
            //break;

        case VAPP_AUTOCAP_CAMSCENEMODE_NIGHT:
            return MDI_CAMERA_SCENE_MODE_NIGHT;
            //break;
        case VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT:
            return MDI_CAMERA_SCENE_MODE_DOCUMENT;
            //break;

        case VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE:
            return MDI_CAMERA_SCENE_MODE_ISO_ANTI_HAND_SHAKE;
            //break;
        default:
            return MDI_CAMERA_SCENE_MODE_AUTO;
            //break;
    }

}


void AutoCapCapSizeSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_CAPSIZE;        
    
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_CAPSIZE;

    /* init item str id */
    m_content[VAPP_AUTOCAP_CAPSIZE_WALLPAPER]->setStr(STR_ID_VAPP_AUTOCAP_CAPSIZE_WALLPAPER);
    m_content[VAPP_AUTOCAP_CAPSIZE_HLCD]->setStr(STR_ID_VAPP_AUTOCAP_CAPSIZE_HLCD);
    m_content[VAPP_AUTOCAP_CAPSIZE_VGA]->setStr(STR_ID_VAPP_AUTOCAP_CAPSIZE_VGA);
    m_content[VAPP_AUTOCAP_CAPSIZE_1MP]->setStr(STR_ID_VAPP_AUTOCAP_CAPSIZE_1MP);
    m_content[VAPP_AUTOCAP_CAPSIZE_2MP]->setStr(STR_ID_VAPP_AUTOCAP_CAPSIZE_2MP);
    m_content[VAPP_AUTOCAP_CAPSIZE_3MP]->setStr(STR_ID_VAPP_AUTOCAP_CAPSIZE_3MP);
    m_content[VAPP_AUTOCAP_CAPSIZE_4MP]->setStr(STR_ID_VAPP_AUTOCAP_CAPSIZE_4MP);
    m_content[VAPP_AUTOCAP_CAPSIZE_5MP]->setStr(STR_ID_VAPP_AUTOCAP_CAPSIZE_5MP);
   
};

void AutoCapCapSizeSetting :: setDefault(void)
{
    AutoCapSettingItem::setDefault();
    
    m_content[VAPP_AUTOCAP_CAPSIZE_HLCD]->setValue(VAPP_AUTOCAP_CAPSIZE_HLCD);

    if(m_settingMgr->getCurrCam() ==  VAPP_AUTOCAP_SENSOR_MAIN_CAMERA)
    #if defined(HORIZONTAL_CAMERA)
        m_content[VAPP_AUTOCAP_CAPSIZE_HLCD]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    #else
        m_content[VAPP_AUTOCAP_CAPSIZE_HLCD]->setStatus(VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT);
    #endif
    else
        m_content[VAPP_AUTOCAP_CAPSIZE_HLCD]->setStatus(VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT);

    CheckandSet(-1);        

};

void AutoCapCapSizeSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_AUTOCAP_SETTING_CAPMODE)
    {       
        setDefault();
        if (change_value == VAPP_AUTOCAP_CAPMODE_PANORAMA)
        {
            if(m_settingMgr->m_callingParam.isMultiAngleViewMode)
            {
                if (m_currentValue != VAPP_AUTOCAP_CAPSIZE_WALLPAPER && m_currentValue != VAPP_AUTOCAP_CAPSIZE_HLCD)
                {
                    setValue(VAPP_AUTOCAP_CAPSIZE_WALLPAPER);
                }
            }
            else
        {       
        #if defined(MMI_CAMCO_FEATURE_CAMO_PANORAMA_LARGE_SIZE_SUPPORT)
            if (m_currentValue != VAPP_AUTOCAP_CAPSIZE_1MP)
            {
                setValue(VAPP_AUTOCAP_CAPSIZE_1MP);
            }                     
		#else
            if (m_currentValue != VAPP_AUTOCAP_CAPSIZE_VGA)
            {
                setValue(VAPP_AUTOCAP_CAPSIZE_VGA);
            }
		#endif	
        }
        }
        
        config_capsize_capability();

    }
    else if(change_setting == VAPP_AUTOCAP_SETTING_ISO)
    {       
        AutoCapISOSetting *ISO;
        m_settingMgr->getSetting(VAPP_AUTOCAP_SETTING_ISO, (AutoCapSettingItem**)&ISO);
        
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
    else if(change_setting == VAPP_AUTOCAP_SETTING_ACT_CAM)
    {
        if (change_value == VAPP_AUTOCAP_SENSOR_MAIN_CAMERA)
        {
            #if defined(HORIZONTAL_CAMERA)
                m_content[VAPP_AUTOCAP_CAPSIZE_HLCD]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
            #else
                m_content[VAPP_AUTOCAP_CAPSIZE_HLCD]->setStatus(VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT);
            #endif                        
        }
        else
        {
            m_content[VAPP_AUTOCAP_CAPSIZE_HLCD]->setStatus(VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT);             
        }
        
        config_capsize_capability();        
    }

    
};

void AutoCapCapSizeSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
    
    AutoCapSettingItem::setValue(v);
    
    U16 image_width, image_height;    
    getMappingSize(v, &image_width, &image_height);
    mdi_camera_update_para_image_size(image_width, image_height);
    mdi_camera_update_para_zoom(0);
    m_settingMgr->needRestartPreview();

};

MMI_BOOL AutoCapCapSizeSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAPSIZE, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }
    
    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_CAP_SIZE_WALLPAPER:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAPSIZE_WALLPAPER;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_WALLPAPER] = VAPP_AUTOCAP_CAPSIZE_WALLPAPER;
                break;
    
            case MDI_CAMERA_CAP_SIZE_VGA:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAPSIZE_VGA;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_VGA] = VAPP_AUTOCAP_CAPSIZE_VGA;
                break;
    
            case MDI_CAMERA_CAP_SIZE_1M:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAPSIZE_1MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_1M] = VAPP_AUTOCAP_CAPSIZE_1MP;
                break;
    
            case MDI_CAMERA_CAP_SIZE_2M:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAPSIZE_2MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_2M] = VAPP_AUTOCAP_CAPSIZE_2MP;
                break;
    
            case MDI_CAMERA_CAP_SIZE_3M:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAPSIZE_3MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_3M] = VAPP_AUTOCAP_CAPSIZE_3MP;
                break;
    
            case MDI_CAMERA_CAP_SIZE_4M:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAPSIZE_4MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_4M] = VAPP_AUTOCAP_CAPSIZE_4MP;
                break;
    
            case MDI_CAMERA_CAP_SIZE_5M:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CAPSIZE_5MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_5M] = VAPP_AUTOCAP_CAPSIZE_5MP;
                break;
    
            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;

}

VfxU32 AutoCapCapSizeSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_CAPSIZE_WALLPAPER:
            return MDI_CAMERA_CAP_SIZE_WALLPAPER;
            //break;

        case VAPP_AUTOCAP_CAPSIZE_HLCD:
            return MDI_CAMERA_CAP_SIZE_WALLPAPER;            
            //break;

        case VAPP_AUTOCAP_CAPSIZE_VGA:
            return MDI_CAMERA_CAP_SIZE_VGA;            
            //break;

        case VAPP_AUTOCAP_CAPSIZE_1MP:
            return MDI_CAMERA_CAP_SIZE_1M;            
            //break;

        case VAPP_AUTOCAP_CAPSIZE_2MP:
            return MDI_CAMERA_CAP_SIZE_2M;                        
            //break;

        case VAPP_AUTOCAP_CAPSIZE_3MP:
            return MDI_CAMERA_CAP_SIZE_3M;                                    
            //break;

        case VAPP_AUTOCAP_CAPSIZE_4MP:
            return MDI_CAMERA_CAP_SIZE_4M;                                    
            //break;

        case VAPP_AUTOCAP_CAPSIZE_5MP:
            return MDI_CAMERA_CAP_SIZE_5M;                                    
            //break;

        default:
            return MDI_CAMERA_CAP_SIZE_VGA;  
            //break;
    }


}


void AutoCapCapSizeSetting :: getMappingSize(VfxU32 mmiID, U16 *width_p, U16 *height_p)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_CAPSIZE_WALLPAPER:
            *width_p = GDI_LCD_WIDTH;
            *height_p = GDI_LCD_HEIGHT;
            break;
    
        case VAPP_AUTOCAP_CAPSIZE_HLCD:
            *width_p = GDI_LCD_HEIGHT;
            *height_p = GDI_LCD_WIDTH;         
            break;
    
        case VAPP_AUTOCAP_CAPSIZE_VGA:
            *width_p = 640;
            *height_p = 480;          
            break;

        // for Autorama special modificaion
        // use 0.8MP size on 1MP ENUM
        case VAPP_AUTOCAP_CAPSIZE_1MP:
            //*width_p = 1280;
            //*height_p = 960;          
            *width_p = 1024;
            *height_p = 768;            
            break;
    
        case VAPP_AUTOCAP_CAPSIZE_2MP:
            *width_p = 1600;
            *height_p = 1200;                      
            break;
    
        case VAPP_AUTOCAP_CAPSIZE_3MP:
            *width_p = 2048;
            *height_p = 1536;                             
            break;
    
        case VAPP_AUTOCAP_CAPSIZE_4MP:
            *width_p = 2304;
            *height_p = 1728;                              
            break;
    
        case VAPP_AUTOCAP_CAPSIZE_5MP:
            *width_p = 2592;
            *height_p = 1944;                              
            break;

        default:
            *width_p = 640;
            *height_p = 480;   
            break;
    }


}

void AutoCapCapSizeSetting :: config_capsize_capability(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxS8 idx = 0;
    AutoCapISOSetting * ISO_p;
    VfxU16 ISOValue;    
    VfxU16 capmodeValue;
    VfxBool is_capsize_support;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    m_settingMgr->getSetting(VAPP_AUTOCAP_SETTING_ISO, (AutoCapSettingItem**)&ISO_p);
    ISOValue = ISO_p->getValue();
    capmodeValue = m_settingMgr->getValue(VAPP_AUTOCAP_SETTING_CAPMODE);

    for (idx = 0; idx < VAPP_AUTOCAP_CAPSIZE_END; idx++)
    {
        if (getItem(idx).getStatus() != VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            if(ISO_p->getStatus() != VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT)
            {
                if (!ISO_p->iso_binning.IsoBinningInfo[ISOValue].BinningEnable)
                {
                    is_capsize_support =
                        (vapp_autocap_capmode_vs_capsize[capmodeValue][idx]);
                }

                else
                {
                    is_capsize_support =
                        (vapp_autocap_capmode_vs_capsize[capmodeValue][idx] &
                         ISO_p->vapp_autocap_isobinning_vs_capsize[ISOValue][idx]);
                }
            }
            else
            {
                is_capsize_support =
                    (vapp_autocap_capmode_vs_capsize[capmodeValue][idx]);
            }

            if (is_capsize_support)
            {
                m_content[idx]->setStatus(VAPP_AUTOCAP_SETTING_CAPSIZE, VAPP_AUTOCAP_SETTING_CAP_ENABLED);
            }
            else
            {
                m_content[idx]->setStatus(VAPP_AUTOCAP_SETTING_CAPSIZE, VAPP_AUTOCAP_SETTING_CAP_DISABLED);            
            }
        }
    }
}


void AutoCapHighlightSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_HIGHLIGHT;        
        
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_HIGHLIGHT;

    /* init item str id */
    m_content[VAPP_AUTOCAP_HIGHLIGHT_OFF]->setStr(STR_GLOBAL_OFF);
    m_content[VAPP_AUTOCAP_HIGHLIGHT_ON]->setStr(STR_GLOBAL_ON);
    
};

void AutoCapHighlightSetting :: setDefault(void)
{

#ifdef LED_ONOFF_SUPPORT
    m_cap = ENABLE();
    m_content[VAPP_AUTOCAP_HIGHLIGHT_OFF]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_HIGHLIGHT_ON]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
#else /* LED_ONOFF_SUPPORT */ 
    m_cap = NOT_SUPPORT();
    m_content[VAPP_AUTOCAP_HIGHLIGHT_OFF]->setStatus(VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT);
    m_content[VAPP_AUTOCAP_HIGHLIGHT_ON]->setStatus(VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT);    
#endif /* LED_ONOFF_SUPPORT */     

    CheckandSet(VAPP_AUTOCAP_HIGHLIGHT_OFF);  

    
};

void AutoCapHighlightSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
 

    AutoCapSettingItem::setValue(v);
    if(!m_isHiliteMode)
    {
        switch (m_currentValue)
        {
            case VAPP_AUTOCAP_HIGHLIGHT_OFF:
                /* Turn off LED */
                mdi_camera_flash_setting(VFX_FALSE);
                m_isHighlightON = VFX_FALSE;            
                break;

            case VAPP_AUTOCAP_HIGHLIGHT_ON:
                /* Turn On LED */
                mdi_camera_flash_setting(VFX_TRUE);
                m_isHighlightON = VFX_TRUE;     
                break;

            default:
                ASSERT(0);
        }    
    }
    m_isHiliteMode = VFX_FALSE;    

};

void AutoCapHighlightSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{

    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);

};

void AutoCapHighlightSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;
    switch (v)
    {
        case VAPP_AUTOCAP_HIGHLIGHT_OFF:
            /* Turn off LED */
            mdi_camera_flash_setting(VFX_FALSE);
            m_isHighlightON = VFX_FALSE;            
            break;

        case VAPP_AUTOCAP_HIGHLIGHT_ON:
            /* Turn On LED */
            mdi_camera_flash_setting(VFX_TRUE);
            m_isHighlightON = VFX_TRUE;     
            break;

        default:
            ASSERT(0);
    }

}

void AutoCapHighlightSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        switch (m_currentValue)
        {
            case VAPP_AUTOCAP_HIGHLIGHT_OFF:
                /* Turn off LED */
                mdi_camera_flash_setting(VFX_FALSE);
                m_isHighlightON = VFX_FALSE;
                break;

            case VAPP_AUTOCAP_HIGHLIGHT_ON:
                /* Turn On LED */
                mdi_camera_flash_setting(VFX_TRUE);
                m_isHighlightON = VFX_TRUE;                
                break;

            default:
                ASSERT(0);
        }
    }
}    

VfxBool AutoCapHighlightSetting :: isHighlightON(void)
{
    return m_isHighlightON;
}

void AutoCapAFRangeSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_AFRANGE;    
    
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_AFRANGE;

    /* init item str id */
    m_content[VAPP_AUTOCAP_AFRANGE_AUTO]->setStr(STR_ID_VAPP_AUTOCAP_AFRANGE_AUTO);
    m_content[VAPP_AUTOCAP_AFRANGE_MACRO]->setStr(STR_ID_VAPP_AUTOCAP_AFRANGE_MACRO);
    m_content[VAPP_AUTOCAP_AFRANGE_INFINTE]->setStr(STR_ID_VAPP_AUTOCAP_AFRANGE_INFINITE);

};

void AutoCapAFRangeSetting :: setDefault(void)
{
    AutoCapSettingItem::setDefault();
    
    /*only reset when first time, others use previous setting */
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_AUTOCAP_SETTING_CAP_ENABLED)
    {
        m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = VAPP_AUTOCAP_AFRANGE_AUTO;    
        m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = VAPP_AUTOCAP_AFRANGE_AUTO;
    }            
    /* use recommend setting */
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = VAPP_AUTOCAP_AFRANGE_AUTO;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = VAPP_AUTOCAP_AFRANGE_INFINTE;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = VAPP_AUTOCAP_AFRANGE_INFINTE;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = VAPP_AUTOCAP_AFRANGE_AUTO;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = VAPP_AUTOCAP_AFRANGE_MACRO;   

    CheckandSet(VAPP_AUTOCAP_AFRANGE_AUTO);        
    
};

void AutoCapAFRangeSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_AUTOCAP_SETTING_CAMSCENEMODE)
    {
        setDefault();
        if(last_value == VAPP_AUTOCAP_CAMSCENEMODE_AUTO || last_value == VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE)
        {
            m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = m_currentValue;
            m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = m_currentValue;             
        }
        
        if (change_value != VAPP_AUTOCAP_CAMSCENEMODE_AUTO && change_value != VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE)
        {
            /* apply the scenemode setting */
            setValue(m_CamSceneTable[change_value]);
        }
        else
        {
            if( last_value != VAPP_AUTOCAP_SETTING_NA)
            {
                setValue(m_CamSceneTable[change_value]);
            }                    
        }    
    }                 
};

void AutoCapAFRangeSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
        
    AutoCapSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();    
};

MMI_BOOL AutoCapAFRangeSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    mdi_camera_query_support_info(MDI_CAMERA_SETTING_AFRANGE, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }
    
    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_AF_RANGE_AUTO:
                cap_info->support_item[idx] = VAPP_AUTOCAP_AFRANGE_AUTO;
                break;
        
            case MDI_CAMERA_AF_RANGE_MACRO:
                cap_info->support_item[idx] = VAPP_AUTOCAP_AFRANGE_MACRO;
                break;
        
            case MDI_CAMERA_AF_RANGE_LANDSCAPE:
                cap_info->support_item[idx] = VAPP_AUTOCAP_AFRANGE_INFINTE;
                break;
            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;

        }
    }

    return MMI_TRUE;

}

VfxU32 AutoCapAFRangeSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_AFRANGE_AUTO:
            return MDI_CAMERA_AF_RANGE_AUTO;
            //break;
    
        case VAPP_AUTOCAP_AFRANGE_MACRO:
            return MDI_CAMERA_AF_RANGE_MACRO;
            //break;
    
        case VAPP_AUTOCAP_AFRANGE_INFINTE:
            return MDI_CAMERA_AF_RANGE_LANDSCAPE;
            //break;
        default:
            return MDI_CAMERA_AF_RANGE_AUTO;
            //break;

    }

}

void AutoCapISOSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_ISO;        
    
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_ISO;
    
    /* init item str id */
    m_content[VAPP_AUTOCAP_ISO_AUTO]->setStr(STR_ID_VAPP_AUTOCAP_ISO_AUTO);
    m_content[VAPP_AUTOCAP_ISO_100]->setStr(STR_ID_VAPP_AUTOCAP_ISO_100);
    m_content[VAPP_AUTOCAP_ISO_200]->setStr(STR_ID_VAPP_AUTOCAP_ISO_200);
    m_content[VAPP_AUTOCAP_ISO_400]->setStr(STR_ID_VAPP_AUTOCAP_ISO_400);
    m_content[VAPP_AUTOCAP_ISO_800]->setStr(STR_ID_VAPP_AUTOCAP_ISO_800);
    m_content[VAPP_AUTOCAP_ISO_1600]->setStr(STR_ID_VAPP_AUTOCAP_ISO_1600);

};
void AutoCapISOSetting :: setDefault(void)
{
    vapp_autocap_cap_info cap_info;

    if (queryCapbilityInfo(&cap_info))
    {
        m_cap = ENABLE();
    }
    else
    {
        m_cap = NOT_SUPPORT();
    }

    getIsoBinning();    
    /*only reset when first time, others use previous setting */
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_AUTOCAP_SETTING_CAP_ENABLED)
    {
        m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = VAPP_AUTOCAP_ISO_AUTO;    

    }            
    /* use recommend setting */
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = VAPP_AUTOCAP_ISO_AUTO;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = VAPP_AUTOCAP_ISO_AUTO;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = VAPP_AUTOCAP_ISO_AUTO;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = VAPP_AUTOCAP_ISO_AUTO;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = VAPP_AUTOCAP_ISO_AUTO;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = VAPP_AUTOCAP_ISO_AUTO;

        
    CheckandSet(VAPP_AUTOCAP_ISO_AUTO);          
};


void AutoCapISOSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_AUTOCAP_SETTING_CAMSCENEMODE)
    {
        setDefault();
        if(last_value == VAPP_AUTOCAP_CAMSCENEMODE_AUTO )
        {
            m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = m_currentValue;      
        }
        
        if (change_value != VAPP_AUTOCAP_CAMSCENEMODE_AUTO)
        {
            /* apply the scenemode setting */
            setValue(m_CamSceneTable[change_value]);
            hide(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);
        }
        else
        {
            if( last_value != VAPP_AUTOCAP_SETTING_NA)
            {
                setValue(m_CamSceneTable[change_value]);
                show(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);                  
            }                    
        }  
      
    }       

};
void AutoCapISOSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
 
    AutoCapSettingItem::setValue(v);
    m_CamSceneTable[m_settingMgr->getValue(VAPP_AUTOCAP_SETTING_CAMSCENEMODE)] = m_currentValue;
    m_isHiliteMode = VFX_FALSE;
    m_settingMgr->needRestartPreview();
};

void AutoCapISOSetting::getIsoBinning(void)
{

    for (VfxU32 i = 0; i < VAPP_AUTOCAP_ISO_END; i++)
    {
        for (VfxU32 j = 0; j < VAPP_AUTOCAP_CAPSIZE_END; j++)
        {
            vapp_autocap_isobinning_vs_capsize[i][j] = MMI_TRUE;
        }
    }
    
    for (VfxU32 i = 0; i < VAPP_AUTOCAP_ISO_END; i++)
    {
        if (iso_binning.IsoBinningInfo[i].BinningEnable)
        {
            U16 mdi_capsize = iso_binning.IsoBinningInfo[i].MaxResolution;

            AutoCapCapSizeSetting * CapSize_p;
            m_settingMgr->getSetting(VAPP_AUTOCAP_SETTING_CAPSIZE, (AutoCapSettingItem**)&CapSize_p);
            
            vapp_autocap_capsize_enum cap_size = (vapp_autocap_capsize_enum)CapSize_p->mdi_vs_mmi_capsize[mdi_capsize];
            
            for (VfxU32 j = cap_size + 1; j < VAPP_AUTOCAP_CAPSIZE_END; j++)
            {
                vapp_autocap_isobinning_vs_capsize[i][j] = MMI_FALSE;
            }
        }
    }

}

MMI_BOOL AutoCapISOSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_ISO, &iso_binning);
    
    if (!iso_binning.IsoBinningInfo[MDI_CAMERA_ISO_AUTO].IsoSupported)
    {
        return MMI_FALSE;
    }
    
    vapp_autocap_iso_enum iso = VAPP_AUTOCAP_ISO_AUTO;
    
    for (idx = 0; idx < MDI_CAMERA_ISO_COUNT; idx++)
    {
        vapp_autocap_setting_cap_enum cap_value = VAPP_AUTOCAP_SETTING_CAP_DISABLED;
        
        if (iso_binning.IsoBinningInfo[idx].IsoSupported)
        {
            cap_value = VAPP_AUTOCAP_SETTING_CAP_ENABLED;
        }

        switch (idx)
        {
            case MDI_CAMERA_ISO_AUTO:
                iso = VAPP_AUTOCAP_ISO_AUTO;
                break;

            case MDI_CAMERA_ISO_100:
                iso = VAPP_AUTOCAP_ISO_100;
                break;

            case MDI_CAMERA_ISO_200:
                iso = VAPP_AUTOCAP_ISO_200;
                break;

            case MDI_CAMERA_ISO_400:
                iso = VAPP_AUTOCAP_ISO_400;
                break;
            case MDI_CAMERA_ISO_800:
                iso = VAPP_AUTOCAP_ISO_800;
                break;

            case MDI_CAMERA_ISO_1600:
                iso = VAPP_AUTOCAP_ISO_1600;
                break;
            default:
                break;
        }
        
        m_content[iso]->setStatus(cap_value);            
        m_content[iso]->setValue(iso);              
    }

    return MMI_TRUE;

}

VfxU32 AutoCapISOSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_ISO_AUTO:
            return MDI_CAMERA_ISO_AUTO;
            //break;
            
        case VAPP_AUTOCAP_ISO_100:
            return MDI_CAMERA_ISO_100;
            //break;
            
        case VAPP_AUTOCAP_ISO_200:
            return MDI_CAMERA_ISO_200;
            //break;

        case VAPP_AUTOCAP_ISO_400:
            return MDI_CAMERA_ISO_400;
            //break;
            
        case VAPP_AUTOCAP_ISO_800:
            return MDI_CAMERA_ISO_800;
            //break;

        case VAPP_AUTOCAP_ISO_1600:
            return MDI_CAMERA_ISO_1600;
            //break;
            
        default:
            return MDI_CAMERA_ISO_AUTO;
            //break;
    }



}

void AutoCapISOSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;
}

void AutoCapISOSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
    }
}    

void AutoCapWBSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_WB;        
    
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_WB;

    /* init item str id */
    m_content[VAPP_AUTOCAP_WB_AUTO]->setStr(STR_ID_VAPP_AUTOCAP_WB_AUTO);
    m_content[VAPP_AUTOCAP_WB_DAYLIGHT]->setStr(STR_ID_VAPP_AUTOCAP_WB_DAYLIGHT);
    m_content[VAPP_AUTOCAP_WB_TUNGSTEN]->setStr(STR_ID_VAPP_AUTOCAP_WB_TUNGSTEN);
    m_content[VAPP_AUTOCAP_WB_FLUORESCENT]->setStr(STR_ID_VAPP_AUTOCAP_WB_FLUORESCENT);
    m_content[VAPP_AUTOCAP_WB_CLOUDY]->setStr(STR_ID_VAPP_AUTOCAP_WB_CLOUDY);
    m_content[VAPP_AUTOCAP_WB_INCANDESCENT]->setStr(STR_ID_VAPP_AUTOCAP_WB_INCANDESCENT);
     

};
void AutoCapWBSetting :: setDefault(void)
{
    AutoCapSettingItem::setDefault();

    CheckandSet(VAPP_AUTOCAP_WB_AUTO);           
};

void AutoCapWBSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
};
void AutoCapWBSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
 
    
    AutoCapSettingItem::setValue(v);

    m_isHiliteMode = VFX_FALSE;    

    mdi_camera_update_para_wb(getMappingID(v));

};

MMI_BOOL AutoCapWBSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_WB, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }
    
    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_WB_AUTO:
                cap_info->support_item[idx] = VAPP_AUTOCAP_WB_AUTO;
                break;

            case MDI_CAMERA_WB_DAYLIGHT:
                cap_info->support_item[idx] = VAPP_AUTOCAP_WB_DAYLIGHT;
                break;

            case MDI_CAMERA_WB_TUNGSTEN:
                cap_info->support_item[idx] = VAPP_AUTOCAP_WB_TUNGSTEN;
                break;

            case MDI_CAMERA_WB_FLUORESCENT:
                cap_info->support_item[idx] = VAPP_AUTOCAP_WB_FLUORESCENT;
                break;

            case MDI_CAMERA_WB_CLOUD:
                cap_info->support_item[idx] = VAPP_AUTOCAP_WB_CLOUDY;
                break;

            case MDI_CAMERA_WB_INCANDESCENCE:
                cap_info->support_item[idx] = VAPP_AUTOCAP_WB_INCANDESCENT;
                break;

            case MDI_CAMERA_WB_MANUAL:
                cap_info->support_item[idx] = VAPP_AUTOCAP_WB_AUTO;
                break;

            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;


        }
    }

    return MMI_TRUE;

}

VfxU32 AutoCapWBSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_WB_AUTO:
            return MDI_CAMERA_WB_AUTO;
            //break;
    
        case VAPP_AUTOCAP_WB_DAYLIGHT:
            return MDI_CAMERA_WB_DAYLIGHT;
            //break;
    
        case VAPP_AUTOCAP_WB_TUNGSTEN:
            return MDI_CAMERA_WB_TUNGSTEN;
            //break;
    
        case VAPP_AUTOCAP_WB_FLUORESCENT:
            return MDI_CAMERA_WB_FLUORESCENT;
            //break;
    
        case VAPP_AUTOCAP_WB_CLOUDY:
            return MDI_CAMERA_WB_CLOUD;
            //break;
    
        case VAPP_AUTOCAP_WB_INCANDESCENT:
            return MDI_CAMERA_WB_INCANDESCENCE;
            //break;
    
        default:
            return MDI_CAMERA_WB_AUTO;
            //break;
    }


}

void AutoCapWBSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    mdi_camera_update_para_wb(getMappingID(v));

}

void AutoCapWBSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        mdi_camera_update_para_wb(getMappingID(m_currentValue));
    }
}    

void AutoCapEffectSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_EFFECT;        
    
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_EFFECT;
          
};
void AutoCapEffectSetting :: setDefault(void)
{
    AutoCapSettingItem::setDefault();
    CheckandSet(VAPP_AUTOCAP_EFFECT_NORMAL);     
    
};

void AutoCapEffectSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
};

void AutoCapEffectSetting::setValue(VfxU16 v)
{   
    VAPP_AUTOCAP_SETTING_CHECK
 
    AutoCapSettingItem::setValue(v);

    m_isHiliteMode = VFX_FALSE;   

    mdi_camera_update_para_effect(getMappingID(v));

};

MMI_BOOL AutoCapEffectSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_EFFECT, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_EFFECT_NOMRAL:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_NORMAL;
                break;

            case MDI_CAMERA_EFFECT_GRAYSCALE:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_GRAYSCALE;
                break;

            case MDI_CAMERA_EFFECT_SEPIA:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_SEPIA;
                break;

            case MDI_CAMERA_EFFECT_SEPIA_GREEN:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_SEPIA_GREEN;
                break;

            case MDI_CAMERA_EFFECT_SEPIA_BLUE:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_SEPIA_BLUE;
                break;

            case MDI_CAMERA_EFFECT_COLOR_INVERT:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_COLOR_INVERT;
                break;

            case MDI_CAMERA_EFFECT_GRAY_INVERT:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_GRAY_INVERT;
                break;

            case MDI_CAMERA_EFFECT_BLACKBOARD:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_BLACKBOARD;
                break;

            case MDI_CAMERA_EFFECT_WHITEBOARD:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_WHITEBOARD;
                break;

            case MDI_CAMERA_EFFECT_COPPER_CARVING:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_COPPER_CARVING;
                break;

            case MDI_CAMERA_EFFECT_BLUE_CARVING:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_BLUE_CARVING;
                break;

            case MDI_CAMERA_EFFECT_EMBOSSMENT:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_EMBOSSMENT;
                break;

            case MDI_CAMERA_EFFECT_CONTRAST:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_CONTRAST;
                break;

            case MDI_CAMERA_EFFECT_JEAN:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_JEAN;
                break;

            case MDI_CAMERA_EFFECT_SKETCH:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_SKETCH;
                break;

            case MDI_CAMERA_EFFECT_OIL:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EFFECT_OIL;
                break;

            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;


        }
    }

    return MMI_TRUE;

}

VfxU32 AutoCapEffectSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_EFFECT_NORMAL:
            return MDI_CAMERA_EFFECT_NOMRAL;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_GRAYSCALE:
            return MDI_CAMERA_EFFECT_GRAYSCALE;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_SEPIA:
            return MDI_CAMERA_EFFECT_SEPIA;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_SEPIA_GREEN:
            return MDI_CAMERA_EFFECT_SEPIA_GREEN;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_SEPIA_BLUE:
            return MDI_CAMERA_EFFECT_SEPIA_BLUE;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_COLOR_INVERT:
            return MDI_CAMERA_EFFECT_COLOR_INVERT;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_GRAY_INVERT:
            return MDI_CAMERA_EFFECT_GRAY_INVERT;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_BLACKBOARD:
            return MDI_CAMERA_EFFECT_BLACKBOARD;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_WHITEBOARD:
            return MDI_CAMERA_EFFECT_WHITEBOARD;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_COPPER_CARVING:
            return MDI_CAMERA_EFFECT_COPPER_CARVING;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_BLUE_CARVING:
            return MDI_CAMERA_EFFECT_BLUE_CARVING;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_EMBOSSMENT:
            return MDI_CAMERA_EFFECT_EMBOSSMENT;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_CONTRAST:
            return MDI_CAMERA_EFFECT_CONTRAST;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_JEAN:
            return MDI_CAMERA_EFFECT_JEAN;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_SKETCH:
            return MDI_CAMERA_EFFECT_SKETCH;
            //break;
        
        case VAPP_AUTOCAP_EFFECT_OIL:
            return MDI_CAMERA_EFFECT_OIL;
            //break;
        
        default:
            return MDI_CAMERA_EFFECT_NOMRAL;
            //break;

    }

}


void AutoCapEffectSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    mdi_camera_update_para_effect(getMappingID(v));

}

void AutoCapEffectSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;

        mdi_camera_update_para_effect(getMappingID(m_currentValue));
    }
}    


void AutoCapStorageSetting :: initialize(void)
{
    U8 drv_num;
    S32 drv_enum;
    U8 idx = 0;
    SRV_FMGR_DRVLIST_HANDLE drvlist;
    U8 drv;

    AutoCapSettingItem::initialize();       

    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_AUTOCAP_WHEEL_AD_STORAGE_ICON;
    m_mainStrId = STR_GLOBAL_STORAGE;

    drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    drv_num = srv_fmgr_drivelist_count(drvlist);

    for (idx = 0; idx < drv_num; idx++)
    {
        drv = srv_fmgr_drivelist_get_drv_letter(drvlist, idx);
        drv_enum = srv_fmgr_drv_get_type(drv);       

        m_content[drv_enum]->setStr((VfxU16)srv_fmgr_drv_get_string((U8)drv));

        m_content[drv_enum]->setValue(drv_enum);

    }        
#ifdef __FS_CARD_SUPPORT__
    m_content[SRV_FMGR_DRV_CARD_TYPE]->setStr(STR_FMGR_REM_DEVICE);
#endif 

};

void AutoCapStorageSetting :: setDefault(void)
{
    m_cap = ENABLE();

    // query from system support
    SRV_FMGR_DRVLIST_HANDLE drvlist = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    VfxS16 drv_num = srv_fmgr_drivelist_count(drvlist);
                        
    for (VfxU32 idx = 0; idx < drv_num; idx++)
    {
        U8 drv = srv_fmgr_drivelist_get_drv_letter(drvlist, idx);
        U8 drv_enum = srv_fmgr_drv_get_type(drv);        
    
        m_content[drv_enum]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
        m_content[drv_enum]->setValue(drv_enum);
    }
#ifdef __FS_CARD_SUPPORT__
    m_content[SRV_FMGR_DRV_CARD_TYPE]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
#endif 

#if defined(__LOW_COST_SUPPORT_COMMON__)
    setValue(SRV_FMGR_DRV_CARD_TYPE);
#else
    CheckandSet(SRV_FMGR_DRV_PHONE_TYPE);  
#endif

    genStoragePath();


};

U8 AutoCapStorageSetting::getStorage(void)
{    
    return srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)m_content[m_currentValue]->getValue());
}    

void AutoCapStorageSetting::getStoragePath(WCHAR** storagePath)
{
    (*storagePath) = m_storagePath;
}

void AutoCapStorageSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);

};

void AutoCapStorageSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
 
    AutoCapSettingItem::setValue(v);
    genStoragePath();
     
};

void AutoCapStorageSetting::checkStorage(void)
{
    initialize();
    setDefault();
}

void AutoCapStorageSetting::setType(vapp_autocap_setting_enum type)
{
    m_settingType = type;
}

void AutoCapStorageSetting::genStoragePath(void)
{
    CHAR drv_buf[8];
    CHAR buf[64];   
    U8 drv = srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)m_content[m_currentValue]->getValue());
    if (FS_NO_ERROR == FS_GetDevStatus(drv, FS_MOUNT_STATE_ENUM))
    {
        sprintf((CHAR *)buf, "%c:\\", drv);
        mmi_asc_to_ucs2((CHAR *)drv_buf, (CHAR *)buf);        
    }
    else
    {
        if (FS_NO_ERROR == FS_GetDevStatus(SRV_FMGR_PUBLIC_DRV, FS_MOUNT_STATE_ENUM))
        {
            sprintf((CHAR *)buf, "%c:\\", drv);
            mmi_asc_to_ucs2((CHAR *)drv_buf, (CHAR *)buf);
        }
        else
        {
            m_storagePath[0] = m_storagePath[1] = 0;         
            return;
        }
    }
    mmi_ucs2cpy((CHAR *) m_storagePath, (const CHAR *) drv_buf);      
    if (m_settingType == VAPP_AUTOCAP_SETTING_CAMSTORAGE)
    {  
        mmi_ucs2cat((CHAR *) m_storagePath, (const CHAR *) SHOOTING_DOWNLOAD_FOLDER_NAME);
    }
    else
    {
        mmi_ucs2cat((CHAR *) m_storagePath, (const CHAR *) SHOOTING_DOWNLOAD_FOLDER_NAME);
    }

    

}

void AutoCapCapqtySetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_CAPQTY;        
        
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_CAPQTY;


};
void AutoCapCapqtySetting :: setDefault(void)
{
    m_cap = ENABLE();
    m_content[VAPP_AUTOCAP_CAPQTY_FINE]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_CAPQTY_GOOD]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_CAPQTY_NORMAL]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_CAPQTY_LOW]->setStatus(VAPP_AUTOCAP_SETTING_CAP_DISABLED);    

    m_content[VAPP_AUTOCAP_CAPQTY_FINE]->setValue(VAPP_AUTOCAP_CAPQTY_FINE);
    m_content[VAPP_AUTOCAP_CAPQTY_GOOD]->setValue(VAPP_AUTOCAP_CAPQTY_GOOD);
    m_content[VAPP_AUTOCAP_CAPQTY_NORMAL]->setValue(VAPP_AUTOCAP_CAPQTY_NORMAL);
    m_content[VAPP_AUTOCAP_CAPQTY_LOW]->setValue(VAPP_AUTOCAP_CAPQTY_LOW);    

    CheckandSet(VAPP_AUTOCAP_CAPQTY_FINE);           
};

void AutoCapCapqtySetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
};

void AutoCapCapqtySetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
 
    U16 mdi_capqty;

    AutoCapSettingItem::setValue(v);

    mdi_capqty = getMappingID(v);
    mdi_camera_update_para_image_qty(mdi_capqty);

};


VfxU32 AutoCapCapqtySetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_CAPQTY_FINE:
            return MDI_CAMERA_JPG_QTY_HIGH;
            //break;

        case VAPP_AUTOCAP_CAPQTY_GOOD:
            return MDI_CAMERA_JPG_QTY_NORMAL;
            //break;

        case VAPP_AUTOCAP_CAPQTY_NORMAL:
            return MDI_CAMERA_JPG_QTY_LOW;
            //break;

        case VAPP_AUTOCAP_CAPQTY_LOW:
            return MDI_CAMERA_JPG_QTY_LOW;
            //break;

        default:
            return MDI_CAMERA_JPG_QTY_NORMAL;
            //break;
    }



}

void AutoCapAFZoneSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_AFZONE;        
        
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_AFZONE;

    /* init item str id */
    m_content[VAPP_AUTOCAP_AFZONE_SINGLE]->setStr(STR_ID_VAPP_AUTOCAP_AFZONE_SINGLE);
    m_content[VAPP_AUTOCAP_AFZONE_MULTI]->setStr(STR_ID_VAPP_AUTOCAP_AFZONE_MULTI);        
    m_content[VAPP_AUTOCAP_AFZONE_CONTINUE]->setStr(STR_ID_VAPP_AUTOCAP_AFZONE_CONTINUE);     
};
void AutoCapAFZoneSetting :: setDefault(void)
{
    AutoCapSettingItem::setDefault();
    CheckandSet(VAPP_AUTOCAP_AFZONE_SINGLE);
};

void AutoCapAFZoneSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
 
};

void AutoCapAFZoneSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
 
    AutoCapSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();

};

MMI_BOOL AutoCapAFZoneSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_AFMODE, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE:
                cap_info->support_item[idx] = VAPP_AUTOCAP_AFZONE_SINGLE;
                break;
        
            case MDI_CAMERA_AF_OPERATION_MODE_MULTI_ZONE:
                cap_info->support_item[idx] = VAPP_AUTOCAP_AFZONE_MULTI;
                break;
                
            case MDI_CAMERA_AF_OPERATION_MODE_CONTINUOUS:
                cap_info->support_item[idx] = VAPP_AUTOCAP_AFZONE_CONTINUE;
                break;          
                
            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;

        }
    }

    return MMI_TRUE;

}

VfxU32 AutoCapAFZoneSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_AFZONE_SINGLE:
            return MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE;
            //break;
    
        case VAPP_AUTOCAP_AFZONE_MULTI:
            return MDI_CAMERA_AF_OPERATION_MODE_MULTI_ZONE;
            //break;
    
        case VAPP_AUTOCAP_AFZONE_CONTINUE:
            return MDI_CAMERA_AF_OPERATION_MODE_CONTINUOUS;
            //break;            

        default:
            return MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE;
            //break;


    }
}

void AutoCapAEmeterSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_AEMETER;        
        
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_AEMETER;
        
};

void AutoCapAEmeterSetting :: setDefault(void)
{
    AutoCapSettingItem::setDefault();
    
    CheckandSet(VAPP_AUTOCAP_AEMETER_AUTO);
};

void AutoCapAEmeterSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);

};

void AutoCapAEmeterSetting ::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK

    AutoCapSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();

};

MMI_BOOL AutoCapAEmeterSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_AEMETER, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }
    
    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_AE_METER_AUTO:
                cap_info->support_item[idx] = VAPP_AUTOCAP_AEMETER_AUTO;
                break;

            case MDI_CAMERA_AE_METER_SPOT:
                cap_info->support_item[idx] = VAPP_AUTOCAP_AEMETER_SPOT;
                break;

            case MDI_CAMERA_AE_METER_CENTER:
                cap_info->support_item[idx] = VAPP_AUTOCAP_AEMETER_CENTER_WEIGHT;
                break;

            case MDI_CAMERA_AE_METER_AVERAGE:
                cap_info->support_item[idx] = VAPP_AUTOCAP_AEMETER_AVERAGE;
                break;

            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;

}


VfxU32 AutoCapAEmeterSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_AEMETER_AUTO:
            return MDI_CAMERA_AE_METER_AUTO;
            //break;
        
        case VAPP_AUTOCAP_AEMETER_SPOT:
            return MDI_CAMERA_AE_METER_SPOT;
            //break;
        
        case VAPP_AUTOCAP_AEMETER_CENTER_WEIGHT:
            return MDI_CAMERA_AE_METER_CENTER;
            //break;
        
        case VAPP_AUTOCAP_AEMETER_AVERAGE:
            return MDI_CAMERA_AE_METER_AVERAGE;
            //break;
        
        default:
            return MDI_CAMERA_AE_METER_AUTO;
            //break;

    }
}



void AutoCapSharpnessSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_SHARPNESS;        
        
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_SHARPNESS;
    
};
void AutoCapSharpnessSetting :: setDefault(void)
{
    AutoCapSettingItem::setDefault();

    /*only reset when first time, others use previous setting */
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_AUTOCAP_SETTING_CAP_ENABLED)
    {
        m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = VAPP_AUTOCAP_SHARPNESS_NORMAL;    
        m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = VAPP_AUTOCAP_SHARPNESS_NORMAL;
    }            
    /* use recommend setting */
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = VAPP_AUTOCAP_SHARPNESS_REDUCE;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = VAPP_AUTOCAP_SHARPNESS_ENHANCE;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = VAPP_AUTOCAP_SHARPNESS_NORMAL;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = VAPP_AUTOCAP_SHARPNESS_REDUCE;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = VAPP_AUTOCAP_SHARPNESS_ENHANCE;
       

    m_maxValue = VAPP_AUTOCAP_SHARPNESS_ENHANCE;
    m_minValue = VAPP_AUTOCAP_SHARPNESS_REDUCE;    
    for(VfxU32 i = VAPP_AUTOCAP_SHARPNESS_ENHANCE; i <= VAPP_AUTOCAP_SHARPNESS_REDUCE; i++)    
    {
        if(m_content[i]->getStatus() == VAPP_AUTOCAP_SETTING_CAP_ENABLED)
        {
            if(i > m_maxValue)
                m_maxValue = i;
            if(i < m_minValue)
                m_minValue = i;
        }
    } 
    
    CheckandSet(VAPP_AUTOCAP_SHARPNESS_NORMAL);
};

void AutoCapSharpnessSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
 
    if(change_setting == VAPP_AUTOCAP_SETTING_EFFECT)
    {
        VfxU16 scn_value;        

        scn_value = m_settingMgr->getValue(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);        
        setValue(m_CamSceneTable[scn_value]);        
        if (change_value != VAPP_AUTOCAP_EFFECT_NORMAL || (scn_value != VAPP_AUTOCAP_CAMSCENEMODE_AUTO && scn_value != VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE))
        {
            hide(VAPP_AUTOCAP_SETTING_EFFECT);
        }
        else
        {
            show(VAPP_AUTOCAP_SETTING_EFFECT);                                    
        }    

    } 
    else if(change_setting == VAPP_AUTOCAP_SETTING_CAMSCENEMODE)
    {
        if(last_value == VAPP_AUTOCAP_CAMSCENEMODE_AUTO || last_value == VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE)
        {
           m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = m_currentValue;      
           m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = m_currentValue;                 
        }           
        
        if (change_value != VAPP_AUTOCAP_CAMSCENEMODE_AUTO && change_value != VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE )
        {
            /* apply the scenemode setting */
            setValue(m_CamSceneTable[change_value]);
            hide(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);
        }
        else
        {
            setValue(m_CamSceneTable[change_value]);
            show(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);                          
        }  
      
    }        
};

void AutoCapSharpnessSetting ::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK

    if(v > m_maxValue)
        v = m_maxValue;
    if(v < m_minValue)
        v = m_minValue;    

    AutoCapSettingItem::setValue(v);
    m_CamSceneTable[m_settingMgr->getValue(VAPP_AUTOCAP_SETTING_CAMSCENEMODE)] = m_currentValue;
    m_isHiliteMode = VFX_FALSE;    
    
    mdi_camera_update_para_sharpness(getMappingID(v));
};

MMI_BOOL AutoCapSharpnessSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_SHARPNESS, cap_info);
        
    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_IE_LEVEL_LOW:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SHARPNESS_REDUCE;
                break;

            case MDI_CAMERA_IE_LEVEL_MEDIUM:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SHARPNESS_NORMAL;
                break;

            case MDI_CAMERA_IE_LEVEL_HIGH:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SHARPNESS_ENHANCE;
                break;

            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;

        }
    }

    return MMI_TRUE;

}


VfxU32 AutoCapSharpnessSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_SHARPNESS_ENHANCE:
            return MDI_CAMERA_IE_LEVEL_HIGH;
            //break;
        
        case VAPP_AUTOCAP_SHARPNESS_NORMAL:
            return MDI_CAMERA_IE_LEVEL_MEDIUM;
            //break;
        
        case VAPP_AUTOCAP_SHARPNESS_REDUCE:
            return MDI_CAMERA_IE_LEVEL_LOW;
            //break;
        
        default:
            return MDI_CAMERA_IE_LEVEL_MEDIUM;
            //break;


    }
}



void AutoCapSharpnessSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;
    mdi_camera_update_para_sharpness(getMappingID(v));
}

void AutoCapSharpnessSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        mdi_camera_update_para_sharpness(getMappingID(m_currentValue));
    }
}    

VfxU32 AutoCapSharpnessSetting::getMaxValue(void)
{
    return m_maxValue;
}

VfxU32 AutoCapSharpnessSetting::getMinValue(void)
{
    return m_minValue;
}


void AutoCapContrastSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_CONTRAST;        
        
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_CONTRAST;
    
};
void AutoCapContrastSetting :: setDefault(void)
{
    AutoCapSettingItem::setDefault();
    
    /*only reset when first time, others use previous setting */
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_AUTOCAP_SETTING_CAP_ENABLED)
    {
        m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = VAPP_AUTOCAP_CONTRAST_NORMAL;    
        m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = VAPP_AUTOCAP_CONTRAST_NORMAL;
    }            
    /* use recommend setting */
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = VAPP_AUTOCAP_CONTRAST_NORMAL;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = VAPP_AUTOCAP_CONTRAST_NORMAL;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = VAPP_AUTOCAP_CONTRAST_NORMAL;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = VAPP_AUTOCAP_CONTRAST_NORMAL;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = VAPP_AUTOCAP_CONTRAST_ENHANCE;
    

    m_maxValue = VAPP_AUTOCAP_CONTRAST_ENHANCE;
    m_minValue = VAPP_AUTOCAP_CONTRAST_REDUCE;    
    for(VfxU32 i = VAPP_AUTOCAP_CONTRAST_ENHANCE; i <= VAPP_AUTOCAP_CONTRAST_REDUCE; i++)    
    {
        if(m_content[i]->getStatus() == VAPP_AUTOCAP_SETTING_CAP_ENABLED)
        {
            if(i > m_maxValue)
                m_maxValue = i;
            if(i < m_minValue)
                m_minValue = i;
        }
    } 
    
    CheckandSet(VAPP_AUTOCAP_CONTRAST_NORMAL);

       
};

void AutoCapContrastSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
 
    if(change_setting == VAPP_AUTOCAP_SETTING_EFFECT)
    {
        VfxU16 scn_value;       
           
        scn_value = m_settingMgr->getValue(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);        
        setValue(m_CamSceneTable[change_value]);        
        if (change_value != VAPP_AUTOCAP_EFFECT_NORMAL || (scn_value != VAPP_AUTOCAP_CAMSCENEMODE_AUTO && scn_value != VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE))
        {
            hide(VAPP_AUTOCAP_SETTING_EFFECT);
        }
        else
        {
            show(VAPP_AUTOCAP_SETTING_EFFECT);                                    
        }    

    }    
    else if(change_setting == VAPP_AUTOCAP_SETTING_CAMSCENEMODE)
    {
        if(last_value == VAPP_AUTOCAP_CAMSCENEMODE_AUTO || last_value == VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE)
        {
           m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = m_currentValue;      
           m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = m_currentValue;                 
        }           
        
        if (change_value != VAPP_AUTOCAP_CAMSCENEMODE_AUTO && change_value != VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE )
        {
            /* apply the scenemode setting */
            setValue(m_CamSceneTable[change_value]);
            hide(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);
        }
        else
        {
            setValue(m_CamSceneTable[change_value]);
            show(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);                          
        }  
      
    }      

};
void AutoCapContrastSetting ::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK

    if(v > m_maxValue)
        v = m_maxValue;
    if(v < m_minValue)
        v = m_minValue;    
    
    AutoCapSettingItem::setValue(v);

    m_CamSceneTable[m_settingMgr->getValue(VAPP_AUTOCAP_SETTING_CAMSCENEMODE)] = m_currentValue;
    m_isHiliteMode = VFX_FALSE;    

    mdi_camera_update_para_contrast(getMappingID(v));

};


MMI_BOOL AutoCapContrastSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_CONTRAST, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }
    
    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_IE_LEVEL_LOW:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CONTRAST_REDUCE;
                break;

            case MDI_CAMERA_IE_LEVEL_MEDIUM:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CONTRAST_NORMAL;
                break;

            case MDI_CAMERA_IE_LEVEL_HIGH:
                cap_info->support_item[idx] = VAPP_AUTOCAP_CONTRAST_ENHANCE;
                break;

            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;


        }
    }

    return MMI_TRUE;

}

VfxU32 AutoCapContrastSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_CONTRAST_ENHANCE:
            return MDI_CAMERA_IE_LEVEL_HIGH;
            //break;
        
        case VAPP_AUTOCAP_CONTRAST_NORMAL:
            return MDI_CAMERA_IE_LEVEL_MEDIUM;
            //break;
        
        case VAPP_AUTOCAP_CONTRAST_REDUCE:
            return MDI_CAMERA_IE_LEVEL_LOW;
            //break;
        
        default:
            return MDI_CAMERA_IE_LEVEL_MEDIUM;
            //break;

    }
}



void AutoCapContrastSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    mdi_camera_update_para_contrast(getMappingID(v));

}

void AutoCapContrastSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        mdi_camera_update_para_contrast(getMappingID(m_currentValue));
    }
}   

VfxU32 AutoCapContrastSetting::getMaxValue(void)
{
    return m_maxValue;
}

VfxU32 AutoCapContrastSetting::getMinValue(void)
{
    return m_minValue;
}


void AutoCapSaturationSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_SATURATION;    
    
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_SATURATION;
 
};
void AutoCapSaturationSetting :: setDefault(void)
{
    AutoCapSettingItem::setDefault();

    /*only reset when first time, others use previous setting */
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_AUTOCAP_SETTING_CAP_ENABLED)
    {
        m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = VAPP_AUTOCAP_SATURATION_NORMAL;    
        m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = VAPP_AUTOCAP_SATURATION_NORMAL;
    }            
    /* use recommend setting */
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = VAPP_AUTOCAP_SATURATION_REDUCE;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = VAPP_AUTOCAP_SATURATION_NORMAL;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = VAPP_AUTOCAP_SATURATION_NORMAL;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = VAPP_AUTOCAP_SATURATION_REDUCE;
    m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = VAPP_AUTOCAP_SATURATION_ENHANCE;    

    m_maxValue = VAPP_AUTOCAP_SATURATION_ENHANCE;
    m_minValue = VAPP_AUTOCAP_SATURATION_REDUCE;    
    for(VfxU32 i = VAPP_AUTOCAP_SATURATION_ENHANCE; i <= VAPP_AUTOCAP_SATURATION_REDUCE; i++)    
    {
        if(m_content[i]->getStatus() == VAPP_AUTOCAP_SETTING_CAP_ENABLED)
        {
            if(i > m_maxValue)
                m_maxValue = i;
            if(i < m_minValue)
                m_minValue = i;
        }
    }    
    
    CheckandSet(VAPP_AUTOCAP_SATURATION_NORMAL);


};

void AutoCapSaturationSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_AUTOCAP_SETTING_EFFECT)
    {
        VfxU16 scn_value;        
        
        scn_value = m_settingMgr->getValue(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);        
        setValue(m_CamSceneTable[change_value]);        
        if (change_value != VAPP_AUTOCAP_EFFECT_NORMAL || (scn_value != VAPP_AUTOCAP_CAMSCENEMODE_AUTO && scn_value != VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE))
        {
            hide(VAPP_AUTOCAP_SETTING_EFFECT);
        }
        else
        {
            show(VAPP_AUTOCAP_SETTING_EFFECT);                                    
        }    

    }    
    else if(change_setting == VAPP_AUTOCAP_SETTING_CAMSCENEMODE)
    {
        if(last_value == VAPP_AUTOCAP_CAMSCENEMODE_AUTO || last_value == VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE)
        {
           m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = m_currentValue;      
           m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = m_currentValue;                 
        }           
        
        if (change_value != VAPP_AUTOCAP_CAMSCENEMODE_AUTO && change_value != VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE )
        {
            /* apply the scenemode setting */
            setValue(m_CamSceneTable[change_value]);
            hide(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);
        }
        else
        {
            setValue(m_CamSceneTable[change_value]);
            show(VAPP_AUTOCAP_SETTING_CAMSCENEMODE);                          
        }  
      
    }     

};
void AutoCapSaturationSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK

    if(v > m_maxValue)
        v = m_maxValue;
    if(v < m_minValue)
        v = m_minValue;    
    
    AutoCapSettingItem::setValue(v);

    m_CamSceneTable[m_settingMgr->getValue(VAPP_AUTOCAP_SETTING_CAMSCENEMODE)] = m_currentValue;
    m_isHiliteMode = VFX_FALSE;    

    mdi_camera_update_para_saturation(getMappingID(v));

};

MMI_BOOL AutoCapSaturationSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_SATURATION, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_IE_LEVEL_LOW:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SATURATION_REDUCE;
                break;

            case MDI_CAMERA_IE_LEVEL_MEDIUM:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SATURATION_NORMAL;
                break;

            case MDI_CAMERA_IE_LEVEL_HIGH:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SATURATION_ENHANCE;
                break;

            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;

}


VfxU32 AutoCapSaturationSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_SATURATION_ENHANCE:
            return MDI_CAMERA_IE_LEVEL_HIGH;
            //break;
        
        case VAPP_AUTOCAP_SATURATION_NORMAL:
            return MDI_CAMERA_IE_LEVEL_MEDIUM;
            //break;
        
        case VAPP_AUTOCAP_SATURATION_REDUCE:
            return MDI_CAMERA_IE_LEVEL_LOW;
            //break;
        
        default:
            return MDI_CAMERA_IE_LEVEL_MEDIUM;
            //break;


    }
}



void AutoCapSaturationSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    mdi_camera_update_para_saturation(getMappingID(v));

}

void AutoCapSaturationSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        mdi_camera_update_para_saturation(getMappingID(m_currentValue));
    }
}   

VfxU32 AutoCapSaturationSetting::getMaxValue(void)
{
    return m_maxValue;
}

VfxU32 AutoCapSaturationSetting::getMinValue(void)
{
    return m_minValue;
}

void AutoCapShuttersoundSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_SHUTTERSOUND;        
    
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_SHUTTERSOUND;
      
};


void AutoCapShuttersoundSetting :: setDefault(void)
{
    m_cap = ENABLE();
    m_content[VAPP_AUTOCAP_SHUTTERSOUND_OFF]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_SHUTTERSOUND_SOUND_1]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_SHUTTERSOUND_SOUND_2]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_SHUTTERSOUND_SOUND_3]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);    

    m_content[VAPP_AUTOCAP_SHUTTERSOUND_OFF]->setValue(VAPP_AUTOCAP_SHUTTERSOUND_OFF);
    m_content[VAPP_AUTOCAP_SHUTTERSOUND_SOUND_1]->setValue(VAPP_AUTOCAP_SHUTTERSOUND_SOUND_1);
    m_content[VAPP_AUTOCAP_SHUTTERSOUND_SOUND_2]->setValue(VAPP_AUTOCAP_SHUTTERSOUND_SOUND_2);
    m_content[VAPP_AUTOCAP_SHUTTERSOUND_SOUND_3]->setValue(VAPP_AUTOCAP_SHUTTERSOUND_SOUND_3);        

    CheckandSet(VAPP_AUTOCAP_SHUTTERSOUND_OFF);        
};

void AutoCapShuttersoundSetting::setValue(VfxU16 v)
{
    
    VAPP_AUTOCAP_SETTING_CHECK
 

    AutoCapSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();

};


void AutoCapShuttersoundSetting :: applyEffect(VfxU16 v)
{
    if(m_lastValue == m_currentValue)
        return;

    switch (v)
    {
        case VAPP_AUTOCAP_SHUTTERSOUND_OFF:
            /* do nothing */
            break;

        case VAPP_AUTOCAP_SHUTTERSOUND_SOUND_1:
            /* play sound 1 */
            play_shuttersound(VAPP_AUTOCAP_SHUTTERSOUND_SOUND_1);
            break;

        case VAPP_AUTOCAP_SHUTTERSOUND_SOUND_2:
            /* play sound 2 */
            play_shuttersound(VAPP_AUTOCAP_SHUTTERSOUND_SOUND_2);
            break;

        case VAPP_AUTOCAP_SHUTTERSOUND_SOUND_3:
            /* play sound 3 */
            play_shuttersound(VAPP_AUTOCAP_SHUTTERSOUND_SOUND_3);
            break;

        default:
            break;
    }

}


void AutoCapShuttersoundSetting :: play_shuttersound(VfxU16 shuttersound)
{

    U32 aud_len;
    U8 *aud_data = NULL;
    U8 aud_type;

    switch (shuttersound)
    {
        case VAPP_AUTOCAP_SHUTTERSOUND_OFF:
            break;

        case VAPP_AUTOCAP_SHUTTERSOUND_SOUND_1:
            aud_data = get_audio((U16) (AUD_ID_VAPP_AUTOCAP_CAPTURE_1), &aud_type, &aud_len);
            break;

        case VAPP_AUTOCAP_SHUTTERSOUND_SOUND_2:
            aud_data = get_audio((U16) (AUD_ID_VAPP_AUTOCAP_CAPTURE_2), &aud_type, &aud_len);
            break;

        case VAPP_AUTOCAP_SHUTTERSOUND_SOUND_3:
            aud_data = get_audio((U16) (AUD_ID_VAPP_AUTOCAP_CAPTURE_3), &aud_type, &aud_len);
            break;

        default:
            break;

    }

    if (aud_data != NULL)
    {
        mdi_audio_play_string_with_vol_path(
            (void*)aud_data,
            aud_len,
            aud_type,
            DEVICE_AUDIO_PLAY_ONCE,
            NULL,
            NULL,
            LEVEL5,
            MDI_DEVICE_SPEAKER_BOTH);
    }

}

void AutoCapBandingSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_BANDING;        
    
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_BANDING;
    
};


void AutoCapBandingSetting :: setDefault(void)
{
    m_cap = ENABLE();
    m_content[VAPP_AUTOCAP_BANDING_50HZ]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_BANDING_60HZ]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);    

    m_content[VAPP_AUTOCAP_BANDING_50HZ]->setValue(VAPP_AUTOCAP_BANDING_50HZ);
    m_content[VAPP_AUTOCAP_BANDING_60HZ]->setValue(VAPP_AUTOCAP_BANDING_60HZ);        

    CheckandSet(VAPP_AUTOCAP_BANDING_60HZ);     

    g_vapp_autocap_banding_setting = (vapp_autocap_banding_enum)m_currentValue;
};

void AutoCapBandingSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value); 
};

void AutoCapBandingSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
 
    AutoCapSettingItem::setValue(v);

    m_settingMgr->needRestartPreview();

    g_vapp_autocap_banding_setting = (vapp_autocap_banding_enum)m_currentValue;
};


VfxU32 AutoCapBandingSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_BANDING_50HZ:
            return MDI_CAMERA_BANDING_50HZ;
            //break;
        
        case VAPP_AUTOCAP_BANDING_60HZ:
            return MDI_CAMERA_BANDING_60HZ;
            //break;

        default:
            return MDI_CAMERA_BANDING_50HZ;
            //break;
    }
}

VfxU16 AutoCapBandingSetting :: getBanding(void)
{
    if (m_currentValue == 0xff ||m_currentValue == VAPP_AUTOCAP_BANDING_60HZ)
    {
        return MDI_CAMERA_BANDING_60HZ;
    }
    else
    {
        return MDI_CAMERA_BANDING_50HZ;
    }

}

void AutoCapCamEVSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_CAMEV;    

    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_EV;

};


void AutoCapCamEVSetting :: setDefault(void)
{
    AutoCapSettingItem::setDefault();


    m_maxValue = VAPP_AUTOCAP_EV_N4;
    m_minValue = VAPP_AUTOCAP_EV_P4;    
    for(VfxU32 i=VAPP_AUTOCAP_EV_N4; i<= VAPP_AUTOCAP_EV_P4; i++)    
    {
        if(m_content[i]->getStatus() == VAPP_AUTOCAP_SETTING_CAP_ENABLED)
        {
            if(i > m_maxValue)
                m_maxValue = i;
            if(i < m_minValue)
                m_minValue = i;
        }
    }
    
    setValue(VAPP_AUTOCAP_EV_0);

};


void AutoCapCamEVSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
   
};

void AutoCapCamEVSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
 
    if(v > m_maxValue)
        v = m_maxValue;
    if(v < m_minValue)
        v = m_minValue;    

    AutoCapSettingItem::setValue(v);
    mdi_camera_update_para_ev(getMappingID(v));

};

MMI_BOOL AutoCapCamEVSetting :: queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    VfxU32 idx;
    VfxU16 item;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    mdi_camera_query_support_info(MDI_CAMERA_SETTING_EV, cap_info);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (idx = 0; idx < cap_info->item_count; idx++)
    {
        item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_EV_N4:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EV_N4;
                break;

            case MDI_CAMERA_EV_N3:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EV_N3;
                break;

            case MDI_CAMERA_EV_N2:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EV_N2;
                break;

            case MDI_CAMERA_EV_N1:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EV_N1;
                break;

            case MDI_CAMERA_EV_0:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EV_0;
                break;

            case MDI_CAMERA_EV_P1:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EV_P1;
                break;

            case MDI_CAMERA_EV_P2:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EV_P2;
                break;

            case MDI_CAMERA_EV_P3:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EV_P3;
                break;

            case MDI_CAMERA_EV_P4:
                cap_info->support_item[idx] = VAPP_AUTOCAP_EV_P4;
                break;

            default:
                cap_info->support_item[idx] = VAPP_AUTOCAP_SETTING_DUMMY_VALUE;
                break;

        }
    }

    return MMI_TRUE;

}

VfxU32 AutoCapCamEVSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_EV_N4:
            return MDI_CAMERA_EV_N4;
            //break;
    
        case VAPP_AUTOCAP_EV_N3:
            return MDI_CAMERA_EV_N3;
            //break;
    
        case VAPP_AUTOCAP_EV_N2:
            return MDI_CAMERA_EV_N2;
            //break;
    
        case VAPP_AUTOCAP_EV_N1:
            return MDI_CAMERA_EV_N1;
            //break;
    
        case VAPP_AUTOCAP_EV_0:
            return MDI_CAMERA_EV_0;
            //break;
    
        case VAPP_AUTOCAP_EV_P1:
            return MDI_CAMERA_EV_P1;
            //break;
    
        case VAPP_AUTOCAP_EV_P2:
            return MDI_CAMERA_EV_P2;
            //break;
    
        case VAPP_AUTOCAP_EV_P3:
            return MDI_CAMERA_EV_P3;
            //break;
    
        case VAPP_AUTOCAP_EV_P4:
            return MDI_CAMERA_EV_P4;
            //break;
    
        default:
            return MDI_CAMERA_EV_0;
            //break;
    }

}


void AutoCapCamEVSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    mdi_camera_update_para_ev(getMappingID(v));

}

void AutoCapCamEVSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        mdi_camera_update_para_ev(getMappingID(m_currentValue));
    }
}   

VfxU32 AutoCapCamEVSetting::getMaxValue(void)
{
    return m_maxValue;
}

VfxU32 AutoCapCamEVSetting::getMinValue(void)
{
    return m_minValue;
}

void AutoCapCamZoomSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_CAMZOOM;        
};


void AutoCapCamZoomSetting :: setDefault(void)
{
    vapp_autocap_zoom_info zoom_info;
    
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    mdi_camera_query_zoom_info(&zoom_info);

    m_cap = ENABLE();    

    m_maxValue = zoom_info.max_zoom_factor;
    m_minValue = 100;
    m_currentFactor = m_minValue;

    m_maxStep= zoom_info.zoom_steps;
    m_minStep = 0;


    setValue(m_minStep);   

};
void AutoCapCamZoomSetting :: onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_AUTOCAP_SETTING_CHECK
    AutoCapSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_AUTOCAP_SETTING_CAPSIZE)
    {
        setDefault();
    }

};
MMI_BOOL AutoCapCamZoomSetting::queryCapbilityInfo(vapp_autocap_cap_info *cap_info)
{
    return MMI_FALSE;
}

void AutoCapCamZoomSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK

    if(v < m_minStep)
        v = m_minStep;
    if(v > m_maxStep)
        v = m_maxStep;    
    
    AutoCapSettingItem::setValue(v);

    VfxU32 current_idx = 100;
    mdi_camera_update_para_zoom(v);    
    mdi_camera_get_fast_zoom_factor(&current_idx);
    setFactor(current_idx);

};

void AutoCapCamZoomSetting :: setFactor(VfxU16 v)
{
    m_currentFactor = v;
}

void AutoCapRestoredefaultSetting :: initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_RESTOREDEFAULT;        
    
    /* init main str/img id */
    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_DEFAULT;
       
};


void AutoCapRestoredefaultSetting :: setDefault(void)
{
    m_cap = ENABLE();
    m_content[VAPP_AUTOCAP_RESTOREDEFAULT_OPTION]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);

    m_content[VAPP_AUTOCAP_RESTOREDEFAULT_OPTION]->setValue(VAPP_AUTOCAP_RESTOREDEFAULT_OPTION); 

    CheckandSet(VAPP_AUTOCAP_RESTOREDEFAULT_OPTION);         

};

void AutoCapRestoredefaultSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
 

    AutoCapSettingItem::setValue(v);
             
};

void AutoCapPanoramaDirectionSetting::initialize(void)
{
    AutoCapSettingItem::initialize();
    m_settingType = VAPP_AUTOCAP_SETTING_PANORAMA_DIRECTION;  

    m_mainImgId = 0;
    m_mainStrId = STR_ID_VAPP_AUTOCAP_PANORAMA_DIRECTION;

    /* init item str id */
    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_UP]->setStr(STR_ID_VAPP_AUTOCAP_PANORAMA_DIRECTION_UP);
    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_DOWN]->setStr(STR_ID_VAPP_AUTOCAP_PANORAMA_DIRECTION_DOWN);
    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT]->setStr(STR_ID_VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT);
    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT]->setStr(STR_ID_VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT);
    
};    

void AutoCapPanoramaDirectionSetting::setDefault(void)
{
    m_cap = ENABLE();
    
    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_UP]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_DOWN]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);
    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT]->setStatus(VAPP_AUTOCAP_SETTING_CAP_ENABLED);

    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_UP]->setValue(VAPP_AUTOCAP_PANORAMA_DIRECTION_UP);
    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_DOWN]->setValue(VAPP_AUTOCAP_PANORAMA_DIRECTION_DOWN);
    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT]->setValue(VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT);
    m_content[VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT]->setValue(VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT);    
    
    CheckandSet(VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT);        
};    

void AutoCapPanoramaDirectionSetting::setValue(VfxU16 v)
{
    VAPP_AUTOCAP_SETTING_CHECK
 
    AutoCapSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();
};    

VfxU32 AutoCapPanoramaDirectionSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_AUTOCAP_PANORAMA_DIRECTION_UP:
            return MDI_CAMERA_PANO_UP_DIR;
            //break;

        case VAPP_AUTOCAP_PANORAMA_DIRECTION_DOWN:
            return MDI_CAMERA_PANO_DOWN_DIR;
            //break;

        case VAPP_AUTOCAP_PANORAMA_DIRECTION_LEFT:
            return MDI_CAMERA_PANO_LEFT_DIR;
            //break;

        case VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT:
            return MDI_CAMERA_PANO_RIGHT_DIR;
            //break;

        default:
            return MDI_CAMERA_PANO_LEFT_DIR;
            //break;
    }

};        


#endif
