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
#ifdef __VAPP_CAMCO__

#include "mmi_rp_vapp_camco_def.h"
#include "vapp_camco_setting_item.h"
#include "vapp_camco_setting_mgr.h"
#include "vapp_camco_app.h"


#if defined(HORIZONTAL_CAMERA)

#if defined(__CAMERA_CAPTURE_STANDARD_SET__)
VfxBool vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_END][VAPP_CAMCO_CAPSIZE_END] = 
{
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},       
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},  
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},      
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
    {VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_FALSE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
};

VfxBool vapp_camco_facedetect_vs_capsize[VAPP_CAMCO_FACEDETECT_END][VAPP_CAMCO_CAPSIZE_END] = 
{
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
};

#else 
VfxBool vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_END][VAPP_CAMCO_CAPSIZE_END] = 
{
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},      
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_FALSE, VFX_FALSE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_FALSE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
};

VfxBool vapp_camco_facedetect_vs_capsize[VAPP_CAMCO_FACEDETECT_END][VAPP_CAMCO_CAPSIZE_END] = 
{
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
};

#endif 
#else /* defined(HORIZONTAL_CAMERA) */ 

#if defined(__CAMERA_CAPTURE_STANDARD_SET__)
VfxBool vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_END][VAPP_CAMCO_CAPSIZE_END] = 
{
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},    
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},   
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},       
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
    {VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
};

VfxBool vapp_camco_facedetect_vs_capsize[VAPP_CAMCO_FACEDETECT_END][VAPP_CAMCO_CAPSIZE_END] = 
{
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
};

#else 
VfxBool vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_END][VAPP_CAMCO_CAPSIZE_END] = 
{
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},    
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_FALSE, VFX_FALSE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_FALSE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_FALSE, VFX_FALSE, VFX_FALSE},
};

VfxBool vapp_camco_facedetect_vs_capsize[VAPP_CAMCO_FACEDETECT_END][VAPP_CAMCO_CAPSIZE_END] = 
{
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
    {VFX_TRUE, VFX_FALSE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE, VFX_TRUE},
};

#endif 
#endif /* defined(HORIZONTAL_CAMERA) */ 

VfxBool vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[VAPP_CAMCO_VISCODEC_END][VAPP_CAMCO_RECSIZE_END][VAPP_CAMCO_VISQTY_END][2];
vapp_camco_banding_enum g_vapp_camco_banding_setting;

#define VAPP_CAMCO_SETTING_CHECK \
    if(m_cap == (1ll << VAPP_CAMCO_SETTING_STATUS_DRV_NOT_SUPPORT)) \
        return;

vapp_camco_setting_cap_enum CamcoSettingItem::getStatus(void)
{
    // recorder no need check capmode 
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_RECORDER && IS_DISABLE(m_cap, VAPP_CAMCO_SETTING_STATUS_DISABLED_CAPMODE))
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
};

void CamcoSettingItem::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    ASSERT(v != VAPP_CAMCO_SETTING_DUMMY_VALUE);
    
    if(m_currentValue != 0xff)
        m_lastValue = m_currentValue;
    else
        m_lastValue = VAPP_CAMCO_SETTING_NA;
    //if(m_currentValue != v)
    {
        m_currentValue = v;
        m_signalSettingModified.emit(m_settingType, v, m_lastValue);
    }
};        

void CamcoSettingItem::resetValue(VfxU16 v)
{
    m_currentValue = v;
}

void CamcoSettingItem::hide(vapp_camco_setting_enum setting)
{
    if(!IS_NOT_SUPPORT(m_cap))
        m_cap |= (1ll << setting);      
};        

void CamcoSettingItem::show(vapp_camco_setting_enum setting)
{
    if(!IS_NOT_SUPPORT(m_cap))
        m_cap &= ~(1ll << setting);   
};          

void CamcoSettingItem :: setSettingBound(vapp_camco_setting_enum setting, VfxU16 start, VfxU16 end)
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
};

void CamcoSettingItem::initialize(void)
{

    for(VfxU8 i =0; i < VAPP_CAMCO_MAX_SETTING_ITEM_COUNT;i++)
    {
        m_content[i]->initialize();
    }
    
    m_cap = NOT_SUPPORT();
    m_statusBitMap = 0;
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
        ASSERT(m_currentValue != 0xff);
    }
}

void CamcoSettingItem::applyEffect(VfxU16 v)
{
}

void CamcoSettingItem::resetEffect(void)
{
}

void CamcoSettingItem::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    MMI_TRACE(TRACE_GROUP_2, VAPP_CAMCO_SETTING_UPDATE, change_setting, change_value, last_value);
}

void ApplicationSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_ACT_APP;    
}    
void ApplicationSetting :: setDefault(void)
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
    CheckandSet(VAPP_CAMCO_APP_CAMERA);
    

}    
    
void ApplicationSetting :: setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);

}       

void CameraSensorSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_ACT_CAM;    
}    

void CameraSensorSetting :: setDefault(void)   
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
    CheckandSet(VAPP_CAMCO_SENSOR_MAIN_CAMERA);

}    

void CameraSensorSetting :: setValue(VfxU16 v)    
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    mdi_camera_set_camera_id(getMappingID(v));
    mdi_video_set_camera_id(getMappingID(v));    
}    

VfxU32 CameraSensorSetting :: getMappingID(VfxU32 mmiID)
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

void CameraSensorSetting :: setCameraID(VfxU16 camid)
{
    mdi_camera_set_camera_id(getMappingID(camid));
    mdi_video_set_camera_id(getMappingID(camid));
}

void CapModeSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CAPMODE;            

    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_SETTING_CAPMODE_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_CAPMODE;    

    /* init item str id */
    m_content[VAPP_CAMCO_CAPMODE_NORMAL]->setStr(STR_ID_VAPP_CAMCO_CAPMODE_NORMAL);
    m_content[VAPP_CAMCO_CAPMODE_BEST_SHOT]->setStr(STR_ID_VAPP_CAMCO_CAPMODE_BEST_SHOT);
    m_content[VAPP_CAMCO_CAPMODE_CONT_SHOT]->setStr(STR_ID_VAPP_CAMCO_CAPMODE_CONT_SHOT);
    m_content[VAPP_CAMCO_CAPMODE_BURST_SHOT_SEL]->setStr(STR_ID_VAPP_CAMCO_CAPMODE_BURST_SHOT_SEL);
    m_content[VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL]->setStr(STR_ID_VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL);
    m_content[VAPP_CAMCO_CAPMODE_HDR_SHOT]->setStr(STR_ID_VAPP_CAMCO_CAPMODE_HDR_SHOT); 
    m_content[VAPP_CAMCO_CAPMODE_ASD_SHOT]->setStr(STR_ID_VAPP_CAMCO_CAPMODE_ASD_SHOT); 
    m_content[VAPP_CAMCO_CAPMODE_ZSD_SHOT]->setStr(STR_ID_VAPP_CAMCO_CAPMODE_ZSD_SHOT); 
    m_content[VAPP_CAMCO_CAPMODE_ADD_FRAME]->setStr(STR_ID_VAPP_CAMCO_CAPMODE_ADD_FRAME);
    m_content[VAPP_CAMCO_CAPMODE_SMILE_SHOT]->setStr(STR_ID_VAPP_CAMCO_CAPMODE_SMILE_SHOT);

    /* init item img id */
    m_content[VAPP_CAMCO_CAPMODE_NORMAL]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_CAPMODE_NORMAL_ICON);    
    m_content[VAPP_CAMCO_CAPMODE_BEST_SHOT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_CAPMODE_BEST_SHOT_ICON);
    m_content[VAPP_CAMCO_CAPMODE_CONT_SHOT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_CAPMODE_CONT_SHOT_ICON);
    m_content[VAPP_CAMCO_CAPMODE_BURST_SHOT_SEL]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_CAPMODE_BURST_SHOT_ICON);
    m_content[VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_CAPMODE_EVB_SHOT_ICON);
    m_content[VAPP_CAMCO_CAPMODE_HDR_SHOT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_CAPMODE_HDR_SHOT_ICON);    
    m_content[VAPP_CAMCO_CAPMODE_ASD_SHOT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_CAPMODE_ASD_SHOT_ICON);      
    m_content[VAPP_CAMCO_CAPMODE_ZSD_SHOT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_CAPMODE_ZSD_SHOT_ICON);     
    m_content[VAPP_CAMCO_CAPMODE_ADD_FRAME]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_CAPMODE_ADDFRAME_ICON);
    m_content[VAPP_CAMCO_CAPMODE_SMILE_SHOT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_CAPMODE_SMILE_DETECT_SHOT_ICON);

    m_content[VAPP_CAMCO_CAPMODE_NORMAL]->setStatusIcon(0);    
    m_content[VAPP_CAMCO_CAPMODE_BEST_SHOT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_BEST_SHOT_ICON);
    m_content[VAPP_CAMCO_CAPMODE_CONT_SHOT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_CONT_SHOT_ICON);
    m_content[VAPP_CAMCO_CAPMODE_BURST_SHOT_SEL]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_BURST_SHOT_ICON);
    m_content[VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_EVBSHOT_ICON);
    m_content[VAPP_CAMCO_CAPMODE_HDR_SHOT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_HDR_SHOT_ICON);    
    m_content[VAPP_CAMCO_CAPMODE_ASD_SHOT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ASD_SHOT_ICON);      
    m_content[VAPP_CAMCO_CAPMODE_ZSD_SHOT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ZSD_SHOT_ICON);       
    m_content[VAPP_CAMCO_CAPMODE_ADD_FRAME]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_ADDFRAME_ICON);
    m_content[VAPP_CAMCO_CAPMODE_SMILE_SHOT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPMODE_SMILE_DETECT_ICON);
    
};


void CapModeSetting :: setDefault(void)
{
    CamcoSettingItem :: setDefault();

#ifndef __MMI_CAMCO_FEATURE_CAM_BESTSHOT__
    m_content[VAPP_CAMCO_CAPMODE_BEST_SHOT]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif 
        
#ifndef __MMI_CAMCO_FEATURE_CAM_BURSTSHOT_SELECT__
    m_content[VAPP_CAMCO_CAPMODE_BURST_SHOT_SEL]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif 
        
#ifndef __MTK_TARGET__
    m_content[VAPP_CAMCO_CAPMODE_BURST_SHOT_SEL]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif 

#ifndef __MMI_CAMCO_FEATURE_CAM_AEBSHOT_SELECT__
    m_content[VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif         

#ifndef __MTK_TARGET__
    m_content[VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif         

#ifndef __MMI_CAMCO_FEATURE_CAM_HDRSHOT__
    m_content[VAPP_CAMCO_CAPMODE_HDR_SHOT]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif 

#ifndef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__
    m_content[VAPP_CAMCO_CAPMODE_ASD_SHOT]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif 

#ifndef __MMI_CAMCO_FEATURE_CAM_ZSD_SHOT__
    m_content[VAPP_CAMCO_CAPMODE_ZSD_SHOT]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif 

#ifndef __MDI_CAMERA_ADDFRAME_SUPPORT__
    m_content[VAPP_CAMCO_CAPMODE_ADD_FRAME]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif
    
#ifndef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX__
    m_content[VAPP_CAMCO_CAPMODE_ADD_FRAME]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#else
    if (m_settingMgr->getCurrCam() != VAPP_CAMCO_SENSOR_MAIN_CAMERA)
    {
        m_content[VAPP_CAMCO_CAPMODE_ADD_FRAME]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
    }
#endif 
        
#ifndef __SMILE_SHUTTER_SUPPORT__
    m_content[VAPP_CAMCO_CAPMODE_SMILE_SHOT]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif 

    for(VfxU16 i = 0; i < VAPP_CAMCO_CAPMODE_END; i++)
    {
        m_content[i]->setValue(i);   
    }
   
#ifdef __SMILE_SHUTTER_SUPPORT__
    if (m_settingMgr->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
    {
        m_content[VAPP_CAMCO_CAPMODE_SMILE_SHOT]->setStatus(VAPP_CAMCO_SETTING_ACT_CAM, VAPP_CAMCO_SETTING_CAP_ENABLED);
    }
    else
    {
        m_content[VAPP_CAMCO_CAPMODE_SMILE_SHOT]->setStatus(VAPP_CAMCO_SETTING_ACT_CAM, VAPP_CAMCO_SETTING_CAP_DISABLED);
    }
#endif 

#ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__    
    if (m_settingMgr->getCurrCam() == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
    {
        m_content[VAPP_CAMCO_CAPMODE_ASD_SHOT]->setStatus(VAPP_CAMCO_SETTING_ACT_CAM, VAPP_CAMCO_SETTING_CAP_ENABLED);                 
    }
    else
    {                                 
        m_content[VAPP_CAMCO_CAPMODE_ASD_SHOT]->setStatus(VAPP_CAMCO_SETTING_ACT_CAM, VAPP_CAMCO_SETTING_CAP_DISABLED);                 
    }  
#endif
    
    if(m_settingMgr->IsExtSetting())
    {
        for(VfxU16 j = 0; j < VAPP_CAMCO_CAPMODE_END; j++)
        {
            if (j != VAPP_CAMCO_CAPMODE_NORMAL && j != VAPP_CAMCO_CAPMODE_ADD_FRAME)
            {
                m_content[j]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
            }
        }  
        
        for(VfxU32 i = 0; i < m_settingMgr->m_callingParam.settingLimitNum; i++)
        {            
            if(m_settingMgr->m_callingParam.settingLimitation[i].type == VCUI_CAMCO_SETTING_LIMIT_CAPMODE)
            {
                if(m_settingMgr->m_callingParam.settingLimitation[i].detail == VCUI_CAMCO_SETTING_LIMIT_CAPMODE_ADDFRAME_ONLY)
                {
                    for(VfxU16 j = 0; j < VAPP_CAMCO_CAPMODE_END; j++)
                    {
                        if (j != VAPP_CAMCO_CAPMODE_ADD_FRAME)
                        {
                            m_content[j]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
                        }
                    }    
                    ASSERT(m_content[VAPP_CAMCO_CAPMODE_ADD_FRAME]->getStatus() == VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
                    break;
                }                
                else if(m_settingMgr->m_callingParam.settingLimitation[i].detail == VCUI_CAMCO_SETTING_LIMIT_CAPMODE_NORMAL_ONLY)            
                {
                    for(VfxU16 j = 0; j < VAPP_CAMCO_CAPMODE_END; j++)
                    {
                        if (j != VAPP_CAMCO_CAPMODE_NORMAL)
                        {
                            m_content[j]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
                        }
                    }        
                }
                break;
            }            
        }            
    }
    
    CheckandSet(VAPP_CAMCO_CAPMODE_NORMAL);

};

void CapModeSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_ACT_CAM)
    {    
    #ifdef __SMILE_SHUTTER_SUPPORT__
        if (m_settingMgr->IsExtSetting() || change_value == VAPP_CAMCO_SENSOR_SUB_CAMERA)
        {
            m_content[VAPP_CAMCO_CAPMODE_SMILE_SHOT]->setStatus(VAPP_CAMCO_SETTING_ACT_CAM, VAPP_CAMCO_SETTING_CAP_DISABLED);
        }
        else
        {
            m_content[VAPP_CAMCO_CAPMODE_SMILE_SHOT]->setStatus(VAPP_CAMCO_SETTING_ACT_CAM, VAPP_CAMCO_SETTING_CAP_ENABLED);        
        }   
    #endif   

    #ifdef __MMI_CAMCO_FEATURE_CAM_ASD_SHOT__    
        if (m_settingMgr->IsExtSetting() || change_value == VAPP_CAMCO_SENSOR_SUB_CAMERA)
        {
            m_content[VAPP_CAMCO_CAPMODE_ASD_SHOT]->setStatus(VAPP_CAMCO_SETTING_ACT_CAM, VAPP_CAMCO_SETTING_CAP_DISABLED);                 
        }
        else
        {                                 
            m_content[VAPP_CAMCO_CAPMODE_ASD_SHOT]->setStatus(VAPP_CAMCO_SETTING_ACT_CAM, VAPP_CAMCO_SETTING_CAP_ENABLED);                 
        }  
    #endif
    
        if (m_settingMgr->IsExtSetting() || change_value == VAPP_CAMCO_SENSOR_SUB_CAMERA)
        {
            m_content[VAPP_CAMCO_CAPMODE_ADD_FRAME]->setStatus(VAPP_CAMCO_SETTING_ACT_CAM, VAPP_CAMCO_SETTING_CAP_DISABLED);                 
        }
        else
        {                                 
            m_content[VAPP_CAMCO_CAPMODE_ADD_FRAME]->setStatus(VAPP_CAMCO_SETTING_ACT_CAM, VAPP_CAMCO_SETTING_CAP_ENABLED);                 
        }      
    }
    else if(change_setting == VAPP_CAMCO_SETTING_CAPSIZE)
    {
        // basically, all capmode should show even current size is not match
        // we will update size when certain capmode is selected
        //
        // only for WP size, 
        // becasue horizontal/verticall screen difference, hide not match capmode       
        if (change_value == VAPP_CAMCO_CAPSIZE_WALLPAPER)
        {
            m_content[VAPP_CAMCO_CAPMODE_ADD_FRAME]->setStatus(VAPP_CAMCO_SETTING_CAPSIZE, VAPP_CAMCO_SETTING_CAP_DISABLED);                 
        }
        else
        {                                 
            m_content[VAPP_CAMCO_CAPMODE_ADD_FRAME]->setStatus(VAPP_CAMCO_SETTING_CAPSIZE, VAPP_CAMCO_SETTING_CAP_ENABLED);                 
        }  

    }
#if defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)    
    else if(change_setting == VAPP_CAMCO_SETTING_AFMODE)
    {
        AFmodeSetting * af_p;
        m_settingMgr->getSetting(VAPP_CAMCO_SETTING_AFMODE, (CamcoSettingItem**)&af_p);
        if(af_p->getItem(VAPP_CAMCO_AFMODE_CONT).getStatus() == VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            m_content[VAPP_CAMCO_CAPMODE_CONT_SHOT]->setStatus(VAPP_CAMCO_SETTING_AFMODE, VAPP_CAMCO_SETTING_CAP_DISABLED);
        }
        else
        {
            m_content[VAPP_CAMCO_CAPMODE_CONT_SHOT]->setStatus(VAPP_CAMCO_SETTING_AFMODE, VAPP_CAMCO_SETTING_CAP_ENABLED);
        }            
    }       
#endif    
};

void CapModeSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);

    m_settingMgr->needRestartPreview();
};

MMI_BOOL CapModeSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_CAPMODE, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_CAPMODE, cap_info);  

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
            case MDI_CAMERA_CAP_MODE_NORMAL:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPMODE_NORMAL;
                break;

            case MDI_CAMERA_CAP_MODE_BEST_SHOT:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPMODE_BEST_SHOT;
                break;

            case MDI_CAMERA_CAP_MODE_CONT_SHOT:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPMODE_CONT_SHOT;
                break;

            case MDI_CAMERA_CAP_MODE_BURST_SHOT:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPMODE_BURST_SHOT_SEL;
                break;

            case MDI_CAMERA_CAP_MODE_EV_BRACKETING:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL;
                break;
                
            case MDI_CAMERA_CAP_MODE_ADD_FRAME:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPMODE_ADD_FRAME;
                break;

            case MDI_CAMERA_CAP_MODE_HDR:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPMODE_HDR_SHOT;
                break;                

            case MDI_CAMERA_CAP_MODE_SMILE_SHOT:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPMODE_SMILE_SHOT;
                break;                  

            case MDI_CAMERA_CAP_MODE_ASD:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPMODE_ASD_SHOT;
                break; 

            case MDI_CAMERA_CAP_MODE_ZSD:
                cap_info->support_item[idx] = VAPP_CAMCO_CAPMODE_ZSD_SHOT;
                break; 

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;

}

VfxU32 CapModeSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_CAPMODE_NORMAL:
            return MDI_CAMERA_CAP_MODE_NORMAL;

        case VAPP_CAMCO_CAPMODE_BEST_SHOT:
            return MDI_CAMERA_CAP_MODE_BEST_SHOT;

        case VAPP_CAMCO_CAPMODE_CONT_SHOT:
            return MDI_CAMERA_CAP_MODE_CONT_SHOT;

        case VAPP_CAMCO_CAPMODE_BURST_SHOT_SEL:
            return MDI_CAMERA_CAP_MODE_BURST_SHOT;

        case VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL:
            return MDI_CAMERA_CAP_MODE_EV_BRACKETING;

        case VAPP_CAMCO_CAPMODE_ADD_FRAME:
            return MDI_CAMERA_CAP_MODE_ADD_FRAME;

        case VAPP_CAMCO_CAPMODE_HDR_SHOT:
            return MDI_CAMERA_CAP_MODE_HDR;

        case VAPP_CAMCO_CAPMODE_SMILE_SHOT:
            return MDI_CAMERA_CAP_MODE_SMILE_SHOT;

        case VAPP_CAMCO_CAPMODE_ASD_SHOT:
            return MDI_CAMERA_CAP_MODE_ASD;

        case VAPP_CAMCO_CAPMODE_ZSD_SHOT:
            return MDI_CAMERA_CAP_MODE_ZSD;

    }
    return CamcoSettingItem::getMappingID(mmiID);

}

void CamSceneModeSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CAMSCENEMODE;    
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_SETTING_SCN_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_SCENEMODE;

    /* init item str id */
    m_content[VAPP_CAMCO_CAMSCENEMODE_AUTO]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_AUTO);
    m_content[VAPP_CAMCO_CAMSCENEMODE_PORTRAIT]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_PORTRAIT);
    m_content[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_LANDSCAPE);
    m_content[VAPP_CAMCO_CAMSCENEMODE_NIGHT]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_NIGHT);
    m_content[VAPP_CAMCO_CAMSCENEMODE_SPORT]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_SPORT);
    m_content[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_DOCUMENT);
    m_content[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_ANTI_SHAKE);

    /* init item img id */
    m_content[VAPP_CAMCO_CAMSCENEMODE_AUTO]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_SCN_MODE_AUTO_ICON);    
    m_content[VAPP_CAMCO_CAMSCENEMODE_PORTRAIT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_SCN_MODE_PORTRAIT_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_SCN_MODE_VIEW_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_NIGHT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_SCN_MODE_NIGHT_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_SPORT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_SCN_MODE_SPORT_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_SCN_MODE_TEXT_ICON);
    m_content[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_SCN_MODE_ANTI_SHAKE_ICON);    

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
    
};

void CamSceneModeSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();
    CheckandSet(VAPP_CAMCO_CAMSCENEMODE_AUTO);    

    m_activeScene = VAPP_CAMCO_CAMSCENEMODE_AUTO;
};

void CamSceneModeSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        if(change_value == VAPP_CAMCO_CAPMODE_ASD_SHOT)
        {    
            setValue(VAPP_CAMCO_CAMSCENEMODE_AUTO);    
            setActiveValue(MDI_CAMERA_SCENE_MODE_AUTO);
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        }     
        else if(change_value == VAPP_CAMCO_CAPMODE_SMILE_SHOT)
        {        
            show(VAPP_CAMCO_SETTING_CAPMODE);
            
            m_content[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_CAMSCENEMODE_NIGHT]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_CAMSCENEMODE_SPORT]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            m_content[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_DISABLED);
            
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

};

VfxU16 CamSceneModeSetting::getValue(void)
{
    if(m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAPMODE) == VAPP_CAMCO_CAPMODE_ASD_SHOT)
    {
        return m_activeScene;
    }
    else
    {
        return CamcoSettingItem::getValue();
    }
}; 

void CamSceneModeSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    if(m_lastValue != m_currentValue)
    {    
        m_settingMgr->needRestartPreview();
    }
};

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

MMI_BOOL CamSceneModeSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
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

VfxU32 CamSceneModeSetting :: getMappingID(VfxU32 mmiID)
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


void CapSizeSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CAPSIZE;        
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_CAPSIZE_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_CAPSIZE;

    /* init item str id */
    m_content[VAPP_CAMCO_CAPSIZE_WALLPAPER]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_WALLPAPER);
    m_content[VAPP_CAMCO_CAPSIZE_HLCD]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_HLCD);
    m_content[VAPP_CAMCO_CAPSIZE_VGA]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_VGA);
    m_content[VAPP_CAMCO_CAPSIZE_1MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_1MP);
    m_content[VAPP_CAMCO_CAPSIZE_2MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_2MP);
    m_content[VAPP_CAMCO_CAPSIZE_3MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_3MP);
    m_content[VAPP_CAMCO_CAPSIZE_4MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_4MP);
    m_content[VAPP_CAMCO_CAPSIZE_5MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_5MP);

    /* init item img id */
    m_content[VAPP_CAMCO_CAPSIZE_WALLPAPER]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPSIZE_WP_ICON);
    m_content[VAPP_CAMCO_CAPSIZE_HLCD]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPSIZE_HLCD_ICON);
    m_content[VAPP_CAMCO_CAPSIZE_VGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPSIZE_VGA_ICON);
    m_content[VAPP_CAMCO_CAPSIZE_1MP]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPSIZE_1M_ICON);
    m_content[VAPP_CAMCO_CAPSIZE_2MP]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPSIZE_2M_ICON);
    m_content[VAPP_CAMCO_CAPSIZE_3MP]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPSIZE_3M_ICON);
    m_content[VAPP_CAMCO_CAPSIZE_4MP]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPSIZE_4M_ICON);
    m_content[VAPP_CAMCO_CAPSIZE_5MP]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPSIZE_5M_ICON);     

    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_WALLPAPER].width = GDI_LCD_WIDTH;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_WALLPAPER].height = GDI_LCD_HEIGHT;       
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_HLCD].width = GDI_LCD_HEIGHT;
    mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_HLCD].height = GDI_LCD_WIDTH;       
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
};
void CapSizeSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();
    
    m_content[VAPP_CAMCO_CAPSIZE_HLCD]->setValue(VAPP_CAMCO_CAPSIZE_HLCD);

#ifndef __VAPP_CAMCO_ROTATABLE_UI__
    if(m_settingMgr->getCurrCam() ==  VAPP_CAMCO_SENSOR_MAIN_CAMERA)
    #if defined(HORIZONTAL_CAMERA)
        m_content[VAPP_CAMCO_CAPSIZE_HLCD]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    #else
        m_content[VAPP_CAMCO_CAPSIZE_HLCD]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
    #endif
    else
        m_content[VAPP_CAMCO_CAPSIZE_HLCD]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
#endif

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

};
void CapSizeSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {       
        setDefault();
        if(change_value == VAPP_CAMCO_CAPMODE_BURST_SHOT_SEL)
        {
        #ifdef __CAMERA_CAPTURE_STANDARD_SET__
            if (m_currentValue > VAPP_CAMCO_CAPSIZE_VGA)
            {
                setValue(VAPP_CAMCO_CAPSIZE_VGA);
        #else /* __CAMERA_CAPTURE_STANDARD_SET__ */ 
            if (m_currentValue > VAPP_CAMCO_CAPSIZE_3MP)
            {
                setValue(VAPP_CAMCO_CAPSIZE_3MP);
        #endif /* __CAMERA_CAPTURE_STANDARD_SET__ */ 
            }

            config_capsize_capability();            
        }
        else if (change_value == VAPP_CAMCO_CAPMODE_ADD_FRAME)
        {
        
        #ifdef __CAMERA_CAPTURE_STANDARD_SET__
            if (m_currentValue != VAPP_CAMCO_CAPSIZE_VGA)
            {
                setValue(VAPP_CAMCO_CAPSIZE_VGA);
            }            
        #else /* __CAMERA_CAPTURE_STANDARD_SET__ */             
            if (m_currentValue == VAPP_CAMCO_CAPSIZE_WALLPAPER || m_currentValue == VAPP_CAMCO_CAPSIZE_HLCD ||
                m_currentValue > VAPP_CAMCO_CAPSIZE_2MP)
            {
                if (m_currentValue > VAPP_CAMCO_CAPSIZE_2MP)
                {
                    setValue(VAPP_CAMCO_CAPSIZE_2MP);                    
                }
                else
                {
                    setValue(VAPP_CAMCO_CAPSIZE_VGA);                        
                }

            }
        #endif /* __CAMERA_CAPTURE_STANDARD_SET__ */ 
            
            config_capsize_capability();         
        }
        else if (change_value == VAPP_CAMCO_CAPMODE_ZSD_SHOT)
        {
            // because we dont know which size is OK for ZSD
            // we update status firstly
            // for ADD frame and Burst shot, we have deal to know which size will be support not using query
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
    #ifndef __VAPP_CAMCO_ROTATABLE_UI__    
        if (change_value == VAPP_CAMCO_SENSOR_MAIN_CAMERA)
        {
            #if defined(HORIZONTAL_CAMERA)
                m_content[VAPP_CAMCO_CAPSIZE_HLCD]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
            #else
                m_content[VAPP_CAMCO_CAPSIZE_HLCD]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
            #endif
        }
        else
        {
            m_content[VAPP_CAMCO_CAPSIZE_HLCD]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);             
        }
    #endif        
        config_capsize_capability();        
    }

    
};

void CapSizeSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
    
    // update zoom cap before set value
    // because set value will triger update zoom by signal directly
    U16 image_width, image_height;    
    getMappingSize(v, &image_width, &image_height);
    mdi_camera_update_para_image_size(image_width, image_height);
    mdi_camera_update_para_zoom(0);
        
    CamcoSettingItem::setValue(v);
    
    m_settingMgr->needRestartPreview();    
        

};

MMI_BOOL CapSizeSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
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
    
    if (!cap_info_p->is_support)
    {
        return MMI_FALSE;
    }
    
    ASSERT(cap_info_p->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (VfxU32 idx = 0; idx < cap_info_p->item_count; idx++)
    {
        VfxU16 item = cap_info_p->support_item[idx];

        // update size mapping
        // ============================================================
        if(item != MDI_CAMERA_CAP_SIZE_WALLPAPER && item != VAPP_CAMCO_CAPSIZE_VGA)
        {
            VfxU32 current_size = VAPP_CAMCO_CAPSIZE_WALLPAPER;
            switch (item)
            {
                case MDI_CAMERA_CAP_SIZE_1M:
                    current_size = VAPP_CAMCO_CAPSIZE_1MP;
                    break;
            
                case MDI_CAMERA_CAP_SIZE_2M:
                    current_size = VAPP_CAMCO_CAPSIZE_2MP;
                    break;
            
                case MDI_CAMERA_CAP_SIZE_3M:
                    current_size = VAPP_CAMCO_CAPSIZE_3MP;
                    break;
            
                case MDI_CAMERA_CAP_SIZE_4M:
                    current_size = VAPP_CAMCO_CAPSIZE_4MP;
                    break;
            
                case MDI_CAMERA_CAP_SIZE_5M:
                    current_size = VAPP_CAMCO_CAPSIZE_5MP;
                    break;                
            }        
    
            if((mdi_real_capture_size[current_size].width != cap_info_p->image_size[idx].image_width) ||
               (mdi_real_capture_size[current_size].height != cap_info_p->image_size[idx].image_height))
            {
               mdi_real_capture_size[current_size].width = cap_info_p->image_size[idx].image_width;
               mdi_real_capture_size[current_size].height = cap_info_p->image_size[idx].image_height;

                if(item == MDI_CAMERA_CAP_SIZE_1M)
                    m_content[VAPP_CAMCO_CAPSIZE_1MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_1MP_EX);
                else if(item == MDI_CAMERA_CAP_SIZE_2M)
                    m_content[VAPP_CAMCO_CAPSIZE_2MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_2MP_EX);
                else if(item == MDI_CAMERA_CAP_SIZE_3M)                
                    m_content[VAPP_CAMCO_CAPSIZE_3MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_3MP_EX);
                else if(item == MDI_CAMERA_CAP_SIZE_4M)                
                    m_content[VAPP_CAMCO_CAPSIZE_4MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_4MP_EX);
                else if(item == MDI_CAMERA_CAP_SIZE_5M)                
                    m_content[VAPP_CAMCO_CAPSIZE_5MP]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_5MP_EX);                
            }
        }
        // ============================================================            
        
        switch (item)
        {
            case MDI_CAMERA_CAP_SIZE_WALLPAPER:
                cap_info_p->support_item[idx] = VAPP_CAMCO_CAPSIZE_WALLPAPER;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_WALLPAPER] = VAPP_CAMCO_CAPSIZE_WALLPAPER;
                break;
    
            case MDI_CAMERA_CAP_SIZE_VGA:
                cap_info_p->support_item[idx] = VAPP_CAMCO_CAPSIZE_VGA;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_VGA] = VAPP_CAMCO_CAPSIZE_VGA;
                break;
    
            case MDI_CAMERA_CAP_SIZE_1M:
                cap_info_p->support_item[idx] = VAPP_CAMCO_CAPSIZE_1MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_1M] = VAPP_CAMCO_CAPSIZE_1MP;
                break;
    
            case MDI_CAMERA_CAP_SIZE_2M:
                cap_info_p->support_item[idx] = VAPP_CAMCO_CAPSIZE_2MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_2M] = VAPP_CAMCO_CAPSIZE_2MP;
                break;
    
            case MDI_CAMERA_CAP_SIZE_3M:
                cap_info_p->support_item[idx] = VAPP_CAMCO_CAPSIZE_3MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_3M] = VAPP_CAMCO_CAPSIZE_3MP;
                break;
    
            case MDI_CAMERA_CAP_SIZE_4M:
                cap_info_p->support_item[idx] = VAPP_CAMCO_CAPSIZE_4MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_4M] = VAPP_CAMCO_CAPSIZE_4MP;
                break;
    
            case MDI_CAMERA_CAP_SIZE_5M:
                cap_info_p->support_item[idx] = VAPP_CAMCO_CAPSIZE_5MP;
                mdi_vs_mmi_capsize[MDI_CAMERA_CAP_SIZE_5M] = VAPP_CAMCO_CAPSIZE_5MP;
                break;
    
            default:
                cap_info_p->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    // ==================================================================================================
    // query ZSD support size in addition        
    // for some sensor, it mayy not support full size as normal shot
    if(m_settingMgr->getCurrApp() != VAPP_CAMCO_APP_CAMERA)    
        return MMI_TRUE;

    for(VfxU32 idx = 0; idx < VAPP_CAMCO_CAPSIZE_END;idx++)
        vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_ZSD_SHOT][idx] = VFX_FALSE;

    vapp_camco_cap_info zsd_size_cap_info;

    mdi_camera_query_support_info(MDI_CAMERA_SETTING_ZSD_CAPSIZE, &zsd_size_cap_info);

    if (!zsd_size_cap_info.is_support)
        return MMI_TRUE;
    
    ASSERT(zsd_size_cap_info.item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    for (VfxU32 idx = 0; idx < zsd_size_cap_info.item_count; idx++)
    {
        VfxU16 item = zsd_size_cap_info.support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_CAP_SIZE_WALLPAPER:
                vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_ZSD_SHOT][VAPP_CAMCO_CAPSIZE_WALLPAPER] = VFX_TRUE;
                vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_ZSD_SHOT][VAPP_CAMCO_CAPSIZE_HLCD] = VFX_TRUE;                
                break;
    
            case MDI_CAMERA_CAP_SIZE_VGA:
                vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_ZSD_SHOT][VAPP_CAMCO_CAPSIZE_VGA] = VFX_TRUE;
                break;
    
            case MDI_CAMERA_CAP_SIZE_1M:
                vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_ZSD_SHOT][VAPP_CAMCO_CAPSIZE_1MP] = VFX_TRUE;
                break;
    
            case MDI_CAMERA_CAP_SIZE_2M:
                vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_ZSD_SHOT][VAPP_CAMCO_CAPSIZE_2MP] = VFX_TRUE;
                break;
    
            case MDI_CAMERA_CAP_SIZE_3M:
                vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_ZSD_SHOT][VAPP_CAMCO_CAPSIZE_3MP] = VFX_TRUE;
                break;
    
            case MDI_CAMERA_CAP_SIZE_4M:
                vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_ZSD_SHOT][VAPP_CAMCO_CAPSIZE_4MP] = VFX_TRUE;
                break;
    
            case MDI_CAMERA_CAP_SIZE_5M:
                vapp_camco_capmode_vs_capsize[VAPP_CAMCO_CAPMODE_ZSD_SHOT][VAPP_CAMCO_CAPSIZE_5MP] = VFX_TRUE;
                break;   
        }
    }    
    
    return MMI_TRUE;

}

VfxU32 CapSizeSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_CAPSIZE_WALLPAPER:
            return MDI_CAMERA_CAP_SIZE_WALLPAPER;

        case VAPP_CAMCO_CAPSIZE_HLCD:
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


void CapSizeSetting :: getMappingSize(VfxU32 mmiID, U16 *width_p, U16 *height_p)
{
    (*width_p) = mdi_real_capture_size[mmiID].width;
    (*height_p) = mdi_real_capture_size[mmiID].height;
}

void CapSizeSetting :: config_capsize_capability(void)
{

    ISOSetting * ISO_p;
    VfxU16 ISOValue;    
    VfxU16 capmodeValue;
    VfxU16 facedetectValue;    
    VfxBool is_capsize_support;

    m_settingMgr->getSetting(VAPP_CAMCO_SETTING_ISO, (CamcoSettingItem**)&ISO_p);
    ISOValue = ISO_p->getValue();
    capmodeValue = m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAPMODE);
    if(m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAPMODE) ==VAPP_CAMCO_CAPMODE_SMILE_SHOT)
        facedetectValue = 1;    
    else
        facedetectValue = 0;         

    for (VfxS8 idx = 0; idx < VAPP_CAMCO_CAPSIZE_END; idx++)
    {
        if (getItem(idx).getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            if(ISO_p->getStatus() != VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
            {
                if (!ISO_p->iso_binning.IsoBinningInfo[ISOValue].BinningEnable)
                {
                    is_capsize_support =
                        (vapp_camco_capmode_vs_capsize[capmodeValue][idx] &
                         vapp_camco_facedetect_vs_capsize[facedetectValue][idx]);
                }
                else
                {
                    is_capsize_support =
                        (vapp_camco_capmode_vs_capsize[capmodeValue][idx] &
                         ISO_p->vapp_camco_isobinning_vs_capsize[ISOValue][idx] &
                         vapp_camco_facedetect_vs_capsize[facedetectValue][idx]);
                }
            }
            else
            {
                is_capsize_support =
                    (vapp_camco_capmode_vs_capsize[capmodeValue][idx] &
                     vapp_camco_facedetect_vs_capsize[facedetectValue][idx]);            
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

void FlashSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_FLASH;        
        
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_SETTING_FLASH_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_FLASH;

    /* init item str id */
    m_content[VAPP_CAMCO_FLASH_AUTO]->setStr(STR_ID_VAPP_CAMCO_FLASH_AUTO);
    m_content[VAPP_CAMCO_FLASH_OFF]->setStr(STR_GLOBAL_OFF);
    m_content[VAPP_CAMCO_FLASH_FORCE_ON]->setStr(STR_ID_VAPP_CAMCO_FLASH_FORCE_ON);
    m_content[VAPP_CAMCO_FLASH_RED_EYE]->setStr(STR_ID_VAPP_CAMCO_FLASH_RED_EYE);

    /* init item img id */
    m_content[VAPP_CAMCO_FLASH_AUTO]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_FLASH_AUTO_ICON);
    m_content[VAPP_CAMCO_FLASH_OFF]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_FLASH_OFF_ICON);
    m_content[VAPP_CAMCO_FLASH_FORCE_ON]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_FLASH_FORCE_ON_ICON);
    m_content[VAPP_CAMCO_FLASH_RED_EYE]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_FLASH_REDEYE_ICON);        

    m_content[VAPP_CAMCO_FLASH_AUTO]->setStatusIcon(0);
    m_content[VAPP_CAMCO_FLASH_OFF]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_FLASH_OFF_ICON);
    m_content[VAPP_CAMCO_FLASH_FORCE_ON]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_FLASH_FORCE_ON_ICON);
    m_content[VAPP_CAMCO_FLASH_RED_EYE]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_FLASH_REDEYE_ICON);            
};

void FlashSetting :: setDefault(void)
{
#if defined(LED_FLASHLIGHT_SUPPORT)
    flash_type = VAPP_CAMCO_FLASH_TYPE_LED;
    m_cap = ENABLE();
#else 
    flash_type = VAPP_CAMCO_FLASH_TYPE_NONE;
    m_cap = NOT_SUPPORT();
#endif 

    /*only reset when first time, others use previous setting */
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = VAPP_CAMCO_FLASH_AUTO;    
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = VAPP_CAMCO_FLASH_AUTO;
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_SPORT] = VAPP_CAMCO_FLASH_AUTO;
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_NIGHT] = VAPP_CAMCO_FLASH_AUTO;
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT] = VAPP_CAMCO_FLASH_AUTO;        
    }            
    /* use recommend setting */
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_PORTRAIT] = VAPP_CAMCO_FLASH_OFF;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE] = VAPP_CAMCO_FLASH_OFF;


    if (flash_type != VAPP_CAMCO_FLASH_TYPE_NONE)
    {
        CamcoSettingItem::setDefault();
        CheckandSet(VAPP_CAMCO_FLASH_AUTO);          
    }    


};
void FlashSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        MMI_BOOL is_prev_ledflash_support = MMI_FALSE;
        MMI_BOOL is_curr_ledflash_support = MMI_FALSE;
    
        if (flash_type == VAPP_CAMCO_FLASH_TYPE_LED)
        {
            if (last_value != VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL &&
                last_value != VAPP_CAMCO_CAPMODE_HDR_SHOT &&
                last_value != VAPP_CAMCO_CAPMODE_ZSD_SHOT &&
                last_value != VAPP_CAMCO_CAPMODE_SMILE_SHOT)
            {
                is_prev_ledflash_support = MMI_TRUE;
            }
        
            if (change_value != VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL && 
                change_value != VAPP_CAMCO_CAPMODE_HDR_SHOT &&
                change_value != VAPP_CAMCO_CAPMODE_ZSD_SHOT &&                
                change_value != VAPP_CAMCO_CAPMODE_SMILE_SHOT)
            {
                is_curr_ledflash_support = MMI_TRUE;
            }
        
            if (is_prev_ledflash_support ^ is_curr_ledflash_support)
            {
                if (is_curr_ledflash_support)
                {
                    setValue(m_currentValue);
                }
                else
                {
                    setValue(VAPP_CAMCO_FLASH_OFF);                
                }
            }
            else if (is_prev_ledflash_support & is_curr_ledflash_support)
            {
                setValue(m_currentValue);            
            }
        }

        /* multi shot */
        if(change_value != VAPP_CAMCO_CAPMODE_NORMAL && change_value != VAPP_CAMCO_CAPMODE_ADD_FRAME)
        {
            if (flash_type == VAPP_CAMCO_FLASH_TYPE_LED)
            {
                if (change_value == VAPP_CAMCO_CAPMODE_EV_BRACKET_SEL || 
                    change_value == VAPP_CAMCO_CAPMODE_HDR_SHOT ||                     
                    change_value == VAPP_CAMCO_CAPMODE_ZSD_SHOT ||
                    change_value == VAPP_CAMCO_CAPMODE_SMILE_SHOT)
                {
                    hide(VAPP_CAMCO_SETTING_CAPMODE);
                }
                else
                {
                    show(VAPP_CAMCO_SETTING_CAPMODE);
                    if (m_currentValue == VAPP_CAMCO_FLASH_RED_EYE)
                    {
                        setValue(VAPP_CAMCO_FLASH_AUTO);
                    }
                    setSettingBound(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_FLASH_FORCE_ON, VAPP_CAMCO_FLASH_AUTO);
                }
            }
        }
        /* single shot */
        else
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);        
            if (flash_type == VAPP_CAMCO_FLASH_TYPE_LED)
            {           
                setSettingBound(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_FLASH_FORCE_ON, VAPP_CAMCO_FLASH_RED_EYE);
            }
        }
        
    }
    else if(change_setting == VAPP_CAMCO_SETTING_CAMSCENEMODE)
    {
        
        if(last_value != VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE && last_value != VAPP_CAMCO_CAMSCENEMODE_SPORT && last_value != VAPP_CAMCO_SETTING_NA)
        {
            m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = m_currentValue;
            m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_PORTRAIT] = m_currentValue;
            m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_NIGHT] = m_currentValue;
            m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT] = m_currentValue;
            m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = m_currentValue;                
        }
            
        if (change_value == VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE || change_value == VAPP_CAMCO_CAMSCENEMODE_SPORT)
        {
            /* apply the scenemode setting */
            setValue(m_CamSceneTable[change_value]);
            hide(VAPP_CAMCO_SETTING_CAMSCENEMODE);
        }
        else
        {
            if( last_value != VAPP_CAMCO_SETTING_NA)
            {
                show(VAPP_CAMCO_SETTING_CAMSCENEMODE);
                setValue(m_CamSceneTable[change_value]);
            }                    
        }  

    }    

};
void FlashSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    CamcoSettingItem::setValue(v);
    m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = m_currentValue;

    mdi_camera_update_para_flash(getMappingID(v));

};

MMI_BOOL FlashSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
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

VfxU32 FlashSetting :: getMappingID(VfxU32 mmiID)
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


void HighlightSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_HIGHLIGHT;        
        
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_HIGHLIGHT_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_HIGHLIGHT;

    /* init item str id */
    m_content[VAPP_CAMCO_HIGHLIGHT_OFF]->setStr(STR_GLOBAL_OFF);
    m_content[VAPP_CAMCO_HIGHLIGHT_ON]->setStr(STR_GLOBAL_ON);
    
};

void HighlightSetting :: setDefault(void)
{

#ifdef LED_ONOFF_SUPPORT
    m_cap = ENABLE();
    
    m_content[VAPP_CAMCO_HIGHLIGHT_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_HIGHLIGHT_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);

    m_content[VAPP_CAMCO_HIGHLIGHT_OFF]->setValue(VAPP_CAMCO_HIGHLIGHT_OFF);
    m_content[VAPP_CAMCO_HIGHLIGHT_ON]->setValue(VAPP_CAMCO_HIGHLIGHT_ON);    
#else /* LED_ONOFF_SUPPORT */ 
    m_cap = NOT_SUPPORT();

    m_content[VAPP_CAMCO_HIGHLIGHT_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);
    m_content[VAPP_CAMCO_HIGHLIGHT_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT);    

    m_content[VAPP_CAMCO_HIGHLIGHT_OFF]->setValue(VAPP_CAMCO_HIGHLIGHT_OFF);
    m_content[VAPP_CAMCO_HIGHLIGHT_ON]->setValue(VAPP_CAMCO_HIGHLIGHT_ON);
#endif /* LED_ONOFF_SUPPORT */     

    CheckandSet(VAPP_CAMCO_HIGHLIGHT_OFF);  

    
};

void HighlightSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 

    CamcoSettingItem::setValue(v);
    if(!m_isHiliteMode)
    {
        switch (m_currentValue)
        {
            case VAPP_CAMCO_HIGHLIGHT_OFF:
                /* Turn off LED */
                if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
                {    
                    mdi_camera_flash_setting(VFX_FALSE);
                }
                else
                {
                    mdi_video_flash_setting(VFX_FALSE);
                }                
                m_isHighlightON = VFX_FALSE;            
                break;

            case VAPP_CAMCO_HIGHLIGHT_ON:
                /* Turn On LED */
                if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
                {    
                    mdi_camera_flash_setting(VFX_TRUE);
                }
                else
                {
                    mdi_video_flash_setting(VFX_TRUE);
                }                      
                m_isHighlightON = VFX_TRUE;     
                break;

            default:
                ASSERT(0);
        }    
    }
    m_isHiliteMode = VFX_FALSE;    

};

void HighlightSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{

    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);

};

void HighlightSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;
    switch (v)
    {
        case VAPP_CAMCO_HIGHLIGHT_OFF:
            /* Turn off LED */
            if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
            {    
                mdi_camera_flash_setting(VFX_FALSE);
            }
            else
            {
                mdi_video_flash_setting(VFX_FALSE);
            }    
            m_isHighlightON = VFX_FALSE;            
            break;

        case VAPP_CAMCO_HIGHLIGHT_ON:
            /* Turn On LED */
            if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
            {    
                mdi_camera_flash_setting(VFX_TRUE);
            }
            else
            {
                mdi_video_flash_setting(VFX_TRUE);
            }    
            m_isHighlightON = VFX_TRUE;     
            break;

        default:
            ASSERT(0);
    }

}

void HighlightSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        switch (m_currentValue)
        {
            case VAPP_CAMCO_HIGHLIGHT_OFF:
                /* Turn off LED */
                if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
                {    
                    mdi_camera_flash_setting(VFX_FALSE);
                }
                else
                {
                    mdi_video_flash_setting(VFX_FALSE);
                }    
                m_isHighlightON = VFX_FALSE;
                break;

            case VAPP_CAMCO_HIGHLIGHT_ON:
                /* Turn On LED */
                if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
                {    
                    mdi_camera_flash_setting(VFX_TRUE);
                }
                else
                {
                    mdi_video_flash_setting(VFX_TRUE);
                }    
                m_isHighlightON = VFX_TRUE;                
                break;

            default:
                ASSERT(0);
        }
    }
}    

VfxBool HighlightSetting :: isHighlightON(void)
{
    return m_isHighlightON;
}



void AFRangeSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_AFRANGE;    
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_AF_RANGE_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_AFRANGE;

    /* init item str id */
    m_content[VAPP_CAMCO_AFRANGE_AUTO]->setStr(STR_ID_VAPP_CAMCO_AFRANGE_AUTO);
    m_content[VAPP_CAMCO_AFRANGE_MACRO]->setStr(STR_ID_VAPP_CAMCO_AFRANGE_MACRO);
    m_content[VAPP_CAMCO_AFRANGE_INFINTE]->setStr(STR_ID_VAPP_CAMCO_AFRANGE_INFINITE);

    /* init item img id */
    m_content[VAPP_CAMCO_AFRANGE_AUTO]->setStatusIcon(0);    
    m_content[VAPP_CAMCO_AFRANGE_MACRO]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_AF_MACRO_ICON);
    m_content[VAPP_CAMCO_AFRANGE_INFINTE]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_AF_INFINTE_ICON);        
};
void AFRangeSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();
    
    /*only reset when first time, others use previous setting */
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = VAPP_CAMCO_AFRANGE_AUTO;    
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = VAPP_CAMCO_AFRANGE_AUTO;
    }            
    /* use recommend setting */
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_PORTRAIT] = VAPP_CAMCO_AFRANGE_AUTO;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE] = VAPP_CAMCO_AFRANGE_INFINTE;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_SPORT] = VAPP_CAMCO_AFRANGE_INFINTE;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_NIGHT] = VAPP_CAMCO_AFRANGE_AUTO;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT] = VAPP_CAMCO_AFRANGE_MACRO;
    
    /*only reset when first time, others use previous setting */    
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_AUTO] = VAPP_CAMCO_AFRANGE_AUTO;
    }    
    /* use recommend setting */    
    m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_NIGHT] = VAPP_CAMCO_AFRANGE_INFINTE;

    CheckandSet(VAPP_CAMCO_AFRANGE_AUTO);        
    
};

void AFRangeSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_AFMODE)
    {
        if(change_value == VAPP_CAMCO_AFMODE_CONT)
        {
            hide(VAPP_CAMCO_SETTING_AFMODE);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_AFMODE);
        }
    }
    else if(change_setting == VAPP_CAMCO_SETTING_CAMSCENEMODE)
    {
        //setDefault();
        if(last_value == VAPP_CAMCO_CAMSCENEMODE_AUTO || last_value == VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
            m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = m_currentValue;
            m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = m_currentValue;             
        }
        
        if (change_value != VAPP_CAMCO_CAMSCENEMODE_AUTO && change_value != VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
            /* apply the scenemode setting */
            setValue(m_CamSceneTable[change_value]);
        }
        else
        {
            if( last_value != VAPP_CAMCO_SETTING_NA)
            {
                setValue(m_CamSceneTable[change_value]);
            }                    
        }        
    }        
    else if(change_setting == VAPP_CAMCO_SETTING_VDOSCENEMODE)
    {
        //setDefault();
        if(last_value == VAPP_CAMCO_VDOSCENEMODE_AUTO)
        {
            m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_AUTO] = m_currentValue;
        }
        
        if (change_value != VAPP_CAMCO_VDOSCENEMODE_AUTO)
        {
            /* apply the scenemode setting */
            setValue(m_VdoSceneTable[change_value]);
        }
        else
        {
            if( last_value != VAPP_CAMCO_SETTING_NA)
            {
                setValue(m_VdoSceneTable[change_value]);
            }                    
        }       
    }       
    else if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {

        if(change_value == VAPP_CAMCO_CAPMODE_ASD_SHOT)
        {       
            setValue(VAPP_CAMCO_AFRANGE_AUTO);   
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        }  
        else if(change_value == VAPP_CAMCO_CAPMODE_SMILE_SHOT)
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);         
            if (m_currentValue == VAPP_CAMCO_AFRANGE_INFINTE)
            {
                setValue(VAPP_CAMCO_AFRANGE_AUTO);
            }
            setSettingBound(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_AFRANGE_AUTO, VAPP_CAMCO_AFRANGE_MACRO);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);         
            setSettingBound(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_AFRANGE_AUTO, VAPP_CAMCO_AFRANGE_INFINTE);        
        }
    }    
    else if(change_setting == VAPP_CAMCO_SETTING_ACT_APP)
    {
        if(change_value == VAPP_CAMCO_APP_CAMERA)
        {
            m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = m_currentValue; 
            
            if(m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] == 0xff)
            {
                setValue(VAPP_CAMCO_AFRANGE_AUTO);
                m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = VAPP_CAMCO_AFRANGE_AUTO;
            }
            else
            {
                setValue(m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)]);
            }                
        }
        else
        {
            m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = m_currentValue; 
            
            if(m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] == 0xff)
            {
                setValue(VAPP_CAMCO_AFRANGE_AUTO);
                m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = VAPP_CAMCO_AFRANGE_AUTO;
            }
            else
            {
                setValue(m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)]);
            }           
        }
    }            
};

void AFRangeSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
        
    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();    
};

MMI_BOOL AFRangeSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());

    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_AFRANGE, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_AFRANGE, cap_info);        

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
            case MDI_CAMERA_AF_RANGE_AUTO:
                cap_info->support_item[idx] = VAPP_CAMCO_AFRANGE_AUTO;
                break;
        
            case MDI_CAMERA_AF_RANGE_MACRO:
                cap_info->support_item[idx] = VAPP_CAMCO_AFRANGE_MACRO;
                break;
        
            case MDI_CAMERA_AF_RANGE_LANDSCAPE:
                cap_info->support_item[idx] = VAPP_CAMCO_AFRANGE_INFINTE;
                break;
            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;

        }
    }

    return MMI_TRUE;

}

VfxU32 AFRangeSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_AFRANGE_AUTO:
            return MDI_CAMERA_AF_RANGE_AUTO;
    
        case VAPP_CAMCO_AFRANGE_MACRO:
            return MDI_CAMERA_AF_RANGE_MACRO;
    
        case VAPP_CAMCO_AFRANGE_INFINTE:
            return MDI_CAMERA_AF_RANGE_LANDSCAPE;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}


void SelfTimerSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_SELFTIMER;   
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_SETTING_TIMER_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_SELFTIMER;    

    /* init item str id */
    m_content[VAPP_CAMCO_SELFTIMER_OFF]->setStr(STR_GLOBAL_OFF);
    m_content[VAPP_CAMCO_SELFTIMER_5_SEC]->setStr(STR_ID_VAPP_CAMCO_SELFTIMER_5S);
    m_content[VAPP_CAMCO_SELFTIMER_10_SEC]->setStr(STR_ID_VAPP_CAMCO_SELFTIMER_10S);
    m_content[VAPP_CAMCO_SELFTIMER_15_SEC]->setStr(STR_ID_VAPP_CAMCO_SELFTIMER_15S);    

    /* init item img id */
    m_content[VAPP_CAMCO_SELFTIMER_OFF]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_TIMER_OFF_ICON);    
    m_content[VAPP_CAMCO_SELFTIMER_5_SEC]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_TIMER_5_ICON);
    m_content[VAPP_CAMCO_SELFTIMER_10_SEC]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_TIMER_10_ICON);
    m_content[VAPP_CAMCO_SELFTIMER_15_SEC]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_TIMER_15_ICON);    

    m_content[VAPP_CAMCO_SELFTIMER_OFF]->setStatusIcon(0);    
    m_content[VAPP_CAMCO_SELFTIMER_5_SEC]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_TIMER_5S_ICON);
    m_content[VAPP_CAMCO_SELFTIMER_10_SEC]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_TIMER_10S_ICON);        
    m_content[VAPP_CAMCO_SELFTIMER_15_SEC]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_TIMER_15S_ICON);       
};
void SelfTimerSetting :: setDefault(void)
{
    /* init capability */
    m_cap = ENABLE();
    m_content[VAPP_CAMCO_SELFTIMER_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SELFTIMER_5_SEC]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SELFTIMER_10_SEC]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SELFTIMER_15_SEC]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);    
    m_content[VAPP_CAMCO_SELFTIMER_OFF]->setValue(VAPP_CAMCO_SELFTIMER_OFF);
    m_content[VAPP_CAMCO_SELFTIMER_5_SEC]->setValue(VAPP_CAMCO_SELFTIMER_5_SEC);
    m_content[VAPP_CAMCO_SELFTIMER_10_SEC]->setValue(VAPP_CAMCO_SELFTIMER_10_SEC);    
    m_content[VAPP_CAMCO_SELFTIMER_15_SEC]->setValue(VAPP_CAMCO_SELFTIMER_15_SEC);        
    CheckandSet(VAPP_CAMCO_SELFTIMER_OFF);   

};

void SelfTimerSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        if (change_value == VAPP_CAMCO_CAPMODE_CONT_SHOT || change_value == VAPP_CAMCO_CAPMODE_SMILE_SHOT)
        {     
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);
        }       
    }
};

void SelfTimerSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 

    CamcoSettingItem::setValue(v);

};

void ISOSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_ISO;        
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_ISO_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_ISO;
    
    /* init item str id */
    m_content[VAPP_CAMCO_ISO_AUTO]->setStr(STR_ID_VAPP_CAMCO_ISO_AUTO);
    m_content[VAPP_CAMCO_ISO_100]->setStr(STR_ID_VAPP_CAMCO_ISO_100);
    m_content[VAPP_CAMCO_ISO_200]->setStr(STR_ID_VAPP_CAMCO_ISO_200);
    m_content[VAPP_CAMCO_ISO_400]->setStr(STR_ID_VAPP_CAMCO_ISO_400);
    m_content[VAPP_CAMCO_ISO_800]->setStr(STR_ID_VAPP_CAMCO_ISO_800);
    m_content[VAPP_CAMCO_ISO_1600]->setStr(STR_ID_VAPP_CAMCO_ISO_1600);

    /* init item img id */
    m_content[VAPP_CAMCO_ISO_AUTO]->setStatusIcon(0);    
    m_content[VAPP_CAMCO_ISO_100]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_ISO_100_ICON);
    m_content[VAPP_CAMCO_ISO_200]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_ISO_200_ICON);
    m_content[VAPP_CAMCO_ISO_400]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_ISO_400_ICON);
    m_content[VAPP_CAMCO_ISO_800]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_ISO_800_ICON);
    m_content[VAPP_CAMCO_ISO_1600]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_ISO_1600_ICON);

};

void ISOSetting :: setDefault(void)
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
    /*only reset when first time, others use previous setting */
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = VAPP_CAMCO_ISO_AUTO;    

    }            
    /* use recommend setting */
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_PORTRAIT] = VAPP_CAMCO_ISO_AUTO;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE] = VAPP_CAMCO_ISO_AUTO;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_SPORT] = VAPP_CAMCO_ISO_AUTO;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_NIGHT] = VAPP_CAMCO_ISO_AUTO;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT] = VAPP_CAMCO_ISO_AUTO;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = VAPP_CAMCO_ISO_AUTO;

        
    CheckandSet(VAPP_CAMCO_ISO_AUTO);          
};


void ISOSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_CAMSCENEMODE)
    {
        setDefault();
        if(last_value == VAPP_CAMCO_CAMSCENEMODE_AUTO )
        {
            m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = m_currentValue;      
        }
        
        if (change_value != VAPP_CAMCO_CAMSCENEMODE_AUTO)
        {
            /* apply the scenemode setting */
            setValue(m_CamSceneTable[change_value]);
            hide(VAPP_CAMCO_SETTING_CAMSCENEMODE);
        }
        else
        {
            if( last_value != VAPP_CAMCO_SETTING_NA)
            {
                setValue(m_CamSceneTable[change_value]);
                show(VAPP_CAMCO_SETTING_CAMSCENEMODE);                  
            }                    
        }  
      
    }       
    else if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        if(change_value == VAPP_CAMCO_CAPMODE_ASD_SHOT)
        {    
            setValue(VAPP_CAMCO_ISO_AUTO);
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);
        }
    }

};
void ISOSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    CamcoSettingItem::setValue(v);
    m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = m_currentValue;
    m_isHiliteMode = VFX_FALSE;
    m_settingMgr->needRestartPreview();
};

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

MMI_BOOL ISOSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
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

VfxU32 ISOSetting :: getMappingID(VfxU32 mmiID)
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

void ISOSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;
}

void ISOSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
    }
}    

void WBSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_WB;        
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_SETTING_WB_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_WB;

    /* init item str id */
    m_content[VAPP_CAMCO_WB_AUTO]->setStr(STR_ID_VAPP_CAMCO_WB_AUTO);
    m_content[VAPP_CAMCO_WB_DAYLIGHT]->setStr(STR_ID_VAPP_CAMCO_WB_DAYLIGHT);
    m_content[VAPP_CAMCO_WB_TUNGSTEN]->setStr(STR_ID_VAPP_CAMCO_WB_TUNGSTEN);
    m_content[VAPP_CAMCO_WB_FLUORESCENT]->setStr(STR_ID_VAPP_CAMCO_WB_FLUORESCENT);
    m_content[VAPP_CAMCO_WB_CLOUDY]->setStr(STR_ID_VAPP_CAMCO_WB_CLOUDY);
    m_content[VAPP_CAMCO_WB_INCANDESCENT]->setStr(STR_ID_VAPP_CAMCO_WB_INCANDESCENT);

    /* init item img id */
    m_content[VAPP_CAMCO_WB_AUTO]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_WB_NORMAL_ICON);    
    m_content[VAPP_CAMCO_WB_DAYLIGHT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_WB_DAYLIGHT_ICON);
    m_content[VAPP_CAMCO_WB_TUNGSTEN]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_WB_TUNGSTEN_ICON);
    m_content[VAPP_CAMCO_WB_FLUORESCENT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_WB_FLOURESCENT_ICON);
    m_content[VAPP_CAMCO_WB_CLOUDY]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_WB_CLOUDY_ICON);
    m_content[VAPP_CAMCO_WB_INCANDESCENT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_WB_INCADESCENT_ICON);        

};
void WBSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();
    
    /*only reset when first time, others use previous setting */    
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_AUTO] = VAPP_CAMCO_WB_AUTO;
        m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_NIGHT] = VAPP_CAMCO_WB_AUTO;           
    }    

    
    CheckandSet(VAPP_CAMCO_WB_AUTO);           
};

void WBSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        if(change_value == VAPP_CAMCO_CAPMODE_ASD_SHOT)
        {       
            setValue(VAPP_CAMCO_WB_AUTO);   
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        }  
        else
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);        
        }
    }

    
};
void WBSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    
    CamcoSettingItem::setValue(v);

    m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = m_currentValue;
    m_isHiliteMode = VFX_FALSE;    

    if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        mdi_camera_update_para_wb(getMappingID(v));
    }
    else if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_RECORDER)
    {
        mdi_video_rec_update_para_wb(getMappingID(v));
    }
    else
    {
        MMI_ASSERT(0);
    }   


};

MMI_BOOL WBSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
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

VfxU32 WBSetting :: getMappingID(VfxU32 mmiID)
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

void WBSetting :: applyEffect(VfxU16 v)
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
    else
    {
        MMI_ASSERT(0);
    }


}

void WBSetting :: resetEffect(void)
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
        else
        {
            MMI_ASSERT(0);
        }

    }
}    

void EffectSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_EFFECT;        
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_EFFECT_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_EFFECT;

    /* init item str id */
    m_content[VAPP_CAMCO_EFFECT_NORMAL]->setStr(STR_GLOBAL_NORMAL);
    m_content[VAPP_CAMCO_EFFECT_GRAYSCALE]->setStr(STR_ID_VAPP_CAMCO_EFFECT_GRAYSCALE);
    m_content[VAPP_CAMCO_EFFECT_SEPIA]->setStr(STR_ID_VAPP_CAMCO_EFFECT_SEPIA);
    m_content[VAPP_CAMCO_EFFECT_SEPIA_GREEN]->setStr(STR_ID_VAPP_CAMCO_EFFECT_SEPIA_GREEN);
    m_content[VAPP_CAMCO_EFFECT_SEPIA_BLUE]->setStr(STR_ID_VAPP_CAMCO_EFFECT_SEPIA_BLUE);
    m_content[VAPP_CAMCO_EFFECT_COLOR_INVERT]->setStr(STR_ID_VAPP_CAMCO_EFFECT_COLOR_INVERT);
    m_content[VAPP_CAMCO_EFFECT_GRAY_INVERT]->setStr(STR_ID_VAPP_CAMCO_EFFECT_GRAY_INVERT);
    m_content[VAPP_CAMCO_EFFECT_BLACKBOARD]->setStr(STR_ID_VAPP_CAMCO_EFFECT_BLACKBOARD);
    m_content[VAPP_CAMCO_EFFECT_WHITEBOARD]->setStr(STR_ID_VAPP_CAMCO_EFFECT_WHITEBOARD);
    m_content[VAPP_CAMCO_EFFECT_COPPER_CARVING]->setStr(STR_ID_VAPP_CAMCO_EFFECT_COPPER_CARVING);
    m_content[VAPP_CAMCO_EFFECT_BLUE_CARVING]->setStr(STR_ID_VAPP_CAMCO_EFFECT_BLUE_CARVING);
    m_content[VAPP_CAMCO_EFFECT_EMBOSSMENT]->setStr(STR_ID_VAPP_CAMCO_EFFECT_EMBOSSMENT);
    m_content[VAPP_CAMCO_EFFECT_CONTRAST]->setStr(STR_ID_VAPP_CAMCO_EFFECT_CONTRAST);
    m_content[VAPP_CAMCO_EFFECT_JEAN]->setStr(STR_ID_VAPP_CAMCO_EFFECT_JEAN);
    m_content[VAPP_CAMCO_EFFECT_SKETCH]->setStr(STR_ID_VAPP_CAMCO_EFFECT_SKETCH);
    m_content[VAPP_CAMCO_EFFECT_OIL]->setStr(STR_ID_VAPP_CAMCO_EFFECT_OIL);      
    m_content[VAPP_CAMCO_EFFECT_LOMO]->setStr(STR_ID_VAPP_CAMCO_EFFECT_LOMO);
    m_content[VAPP_CAMCO_EFFECT_COLOR_RED]->setStr(STR_ID_VAPP_CAMCO_EFFECT_COLOR_RED);
    m_content[VAPP_CAMCO_EFFECT_COLOR_YELLOW]->setStr(STR_ID_VAPP_CAMCO_EFFECT_COLOR_YELLOW);
    m_content[VAPP_CAMCO_EFFECT_COLOR_GREEN]->setStr(STR_ID_VAPP_CAMCO_EFFECT_COLOR_GREEN);
    m_content[VAPP_CAMCO_EFFECT_COLOR_BLUE]->setStr(STR_ID_VAPP_CAMCO_EFFECT_COLOR_BLUE);
    
    m_content[VAPP_CAMCO_EFFECT_NORMAL]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT1_ICON);
    m_content[VAPP_CAMCO_EFFECT_GRAYSCALE]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT2_ICON);
    m_content[VAPP_CAMCO_EFFECT_SEPIA]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT3_ICON);
    m_content[VAPP_CAMCO_EFFECT_SEPIA_GREEN]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT4_ICON);
    m_content[VAPP_CAMCO_EFFECT_SEPIA_BLUE]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT5_ICON);
    m_content[VAPP_CAMCO_EFFECT_COLOR_INVERT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT6_ICON);
    m_content[VAPP_CAMCO_EFFECT_GRAY_INVERT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT7_ICON);
    m_content[VAPP_CAMCO_EFFECT_BLACKBOARD]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT8_ICON);
    m_content[VAPP_CAMCO_EFFECT_WHITEBOARD]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT9_ICON);
    m_content[VAPP_CAMCO_EFFECT_COPPER_CARVING]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT10_ICON);
    m_content[VAPP_CAMCO_EFFECT_BLUE_CARVING]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT11_ICON);
    m_content[VAPP_CAMCO_EFFECT_EMBOSSMENT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT12_ICON);
    m_content[VAPP_CAMCO_EFFECT_CONTRAST]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT16_ICON); // seem no support now, move to the last 
    m_content[VAPP_CAMCO_EFFECT_JEAN]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT13_ICON);
    m_content[VAPP_CAMCO_EFFECT_SKETCH]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT14_ICON);
    m_content[VAPP_CAMCO_EFFECT_OIL]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT15_ICON);            
    m_content[VAPP_CAMCO_EFFECT_LOMO]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT15_ICON);
    m_content[VAPP_CAMCO_EFFECT_COLOR_RED]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT15_ICON);
    m_content[VAPP_CAMCO_EFFECT_COLOR_YELLOW]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT15_ICON);
    m_content[VAPP_CAMCO_EFFECT_COLOR_GREEN]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT15_ICON);
    m_content[VAPP_CAMCO_EFFECT_COLOR_BLUE]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EFFECT15_ICON); 
};
void EffectSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();
    CheckandSet(VAPP_CAMCO_EFFECT_NORMAL);     
    
};

void EffectSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        if(change_value == VAPP_CAMCO_CAPMODE_SMILE_SHOT || change_value == VAPP_CAMCO_CAPMODE_HDR_SHOT ||  change_value == VAPP_CAMCO_CAPMODE_ASD_SHOT)
        {
            setValue(VAPP_CAMCO_EFFECT_NORMAL);
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        }
        else
        {
            if(change_value == VAPP_CAMCO_CAPMODE_CONT_SHOT || change_value == VAPP_CAMCO_CAPMODE_NORMAL || change_value == VAPP_CAMCO_CAPMODE_BURST_SHOT_SEL)
            {
                m_content[VAPP_CAMCO_EFFECT_LOMO]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_ENABLED);
                m_content[VAPP_CAMCO_EFFECT_COLOR_RED]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_ENABLED);
                m_content[VAPP_CAMCO_EFFECT_COLOR_YELLOW]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_ENABLED);
                m_content[VAPP_CAMCO_EFFECT_COLOR_GREEN]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_ENABLED);
                m_content[VAPP_CAMCO_EFFECT_COLOR_BLUE]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_ENABLED);            
            }
            else
            {
                if(m_currentValue == VAPP_CAMCO_EFFECT_LOMO ||
                   m_currentValue == VAPP_CAMCO_EFFECT_COLOR_RED ||
                   m_currentValue == VAPP_CAMCO_EFFECT_COLOR_YELLOW ||
                   m_currentValue == VAPP_CAMCO_EFFECT_COLOR_GREEN ||
                   m_currentValue == VAPP_CAMCO_EFFECT_COLOR_BLUE)
                {
                    setValue(VAPP_CAMCO_EFFECT_NORMAL);
                }
                m_content[VAPP_CAMCO_EFFECT_LOMO]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_DISABLED);
                m_content[VAPP_CAMCO_EFFECT_COLOR_RED]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_DISABLED);
                m_content[VAPP_CAMCO_EFFECT_COLOR_YELLOW]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_DISABLED);
                m_content[VAPP_CAMCO_EFFECT_COLOR_GREEN]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_DISABLED);
                m_content[VAPP_CAMCO_EFFECT_COLOR_BLUE]->setStatus(VAPP_CAMCO_SETTING_CAPMODE, VAPP_CAMCO_SETTING_CAP_DISABLED);            
            }
            
            show(VAPP_CAMCO_SETTING_CAPMODE);
        }
    }
};
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
    else
    {
        MMI_ASSERT(0);
    }    

};

MMI_BOOL EffectSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
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

            case MDI_CAMERA_EFFECT_SEPIA_GREEN:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_SEPIA_GREEN;
                break;

            case MDI_CAMERA_EFFECT_SEPIA_BLUE:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_SEPIA_BLUE;
                break;

            case MDI_CAMERA_EFFECT_COLOR_INVERT:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_COLOR_INVERT;
                break;

            case MDI_CAMERA_EFFECT_GRAY_INVERT:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_GRAY_INVERT;
                break;

            case MDI_CAMERA_EFFECT_BLACKBOARD:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_BLACKBOARD;
                break;

            case MDI_CAMERA_EFFECT_WHITEBOARD:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_WHITEBOARD;
                break;

            case MDI_CAMERA_EFFECT_COPPER_CARVING:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_COPPER_CARVING;
                break;

            case MDI_CAMERA_EFFECT_BLUE_CARVING:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_BLUE_CARVING;
                break;

            case MDI_CAMERA_EFFECT_EMBOSSMENT:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_EMBOSSMENT;
                break;

            case MDI_CAMERA_EFFECT_CONTRAST:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_CONTRAST;
                break;

            case MDI_CAMERA_EFFECT_JEAN:
                cap_info->support_item[idx] = VAPP_CAMCO_EFFECT_JEAN;
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

VfxU32 EffectSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_EFFECT_NORMAL:
            return MDI_CAMERA_EFFECT_NOMRAL;
        
        case VAPP_CAMCO_EFFECT_GRAYSCALE:
            return MDI_CAMERA_EFFECT_GRAYSCALE;
        
        case VAPP_CAMCO_EFFECT_SEPIA:
            return MDI_CAMERA_EFFECT_SEPIA;
        
        case VAPP_CAMCO_EFFECT_SEPIA_GREEN:
            return MDI_CAMERA_EFFECT_SEPIA_GREEN;
        
        case VAPP_CAMCO_EFFECT_SEPIA_BLUE:
            return MDI_CAMERA_EFFECT_SEPIA_BLUE;
        
        case VAPP_CAMCO_EFFECT_COLOR_INVERT:
            return MDI_CAMERA_EFFECT_COLOR_INVERT;
        
        case VAPP_CAMCO_EFFECT_GRAY_INVERT:
            return MDI_CAMERA_EFFECT_GRAY_INVERT;
        
        case VAPP_CAMCO_EFFECT_BLACKBOARD:
            return MDI_CAMERA_EFFECT_BLACKBOARD;
        
        case VAPP_CAMCO_EFFECT_WHITEBOARD:
            return MDI_CAMERA_EFFECT_WHITEBOARD;
        
        case VAPP_CAMCO_EFFECT_COPPER_CARVING:
            return MDI_CAMERA_EFFECT_COPPER_CARVING;
        
        case VAPP_CAMCO_EFFECT_BLUE_CARVING:
            return MDI_CAMERA_EFFECT_BLUE_CARVING;
        
        case VAPP_CAMCO_EFFECT_EMBOSSMENT:
            return MDI_CAMERA_EFFECT_EMBOSSMENT;
        
        case VAPP_CAMCO_EFFECT_CONTRAST:
            return MDI_CAMERA_EFFECT_CONTRAST;
        
        case VAPP_CAMCO_EFFECT_JEAN:
            return MDI_CAMERA_EFFECT_JEAN;
        
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


void EffectSetting :: applyEffect(VfxU16 v)
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
    else
    {
        MMI_ASSERT(0);
    }

}

void EffectSetting :: resetEffect(void)
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
        else
        {
            MMI_ASSERT(0);
        }

    }
}    

void StorageSetting :: initialize(void)
{
    CamcoSettingItem::initialize();       

    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_STORAGE_ICON;
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

};

void StorageSetting :: setDefault(void)
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
    m_content[SRV_FMGR_DRV_CARD_TYPE]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
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

    CheckandSet(SRV_FMGR_DRV_PHONE_TYPE);  

    genStoragePath();


};

U8 StorageSetting::getStorage(void)
{    
    return srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)m_content[m_currentValue]->getValue());
}    

void StorageSetting::getStoragePath(WCHAR** storagePath)
{
    (*storagePath) = m_storagePath;
}

void StorageSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
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
};

void StorageSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    CamcoSettingItem::setValue(v);
    genStoragePath();
     
};

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

void CapqtySetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CAPQTY;        
        
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_QTY_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_CAPQTY;

    /* init item str id */
    m_content[VAPP_CAMCO_CAPQTY_FINE]->setStr(STR_ID_VAPP_CAMCO_CAPQTY_FINE);
    m_content[VAPP_CAMCO_CAPQTY_GOOD]->setStr(STR_ID_VAPP_CAMCO_CAPQTY_GOOD);
    m_content[VAPP_CAMCO_CAPQTY_NORMAL]->setStr(STR_ID_VAPP_CAMCO_CAPQTY_NORMAL);
    m_content[VAPP_CAMCO_CAPQTY_LOW]->setStr(STR_ID_VAPP_CAMCO_CAPQTY_LOW);

};
void CapqtySetting :: setDefault(void)
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

    CheckandSet(VAPP_CAMCO_CAPQTY_FINE);           
};

void CapqtySetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
};

void CapqtySetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    U16 mdi_capqty;

    CamcoSettingItem::setValue(v);

    mdi_capqty = getMappingID(v);
    mdi_camera_update_para_image_qty(mdi_capqty);

};


VfxU32 CapqtySetting :: getMappingID(VfxU32 mmiID)
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

void AFZoneSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_AFZONE;        
        
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_AF_ZONE_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_AFZONE;

    /* init item str id */
    m_content[VAPP_CAMCO_AFZONE_SINGLE]->setStr(STR_ID_VAPP_CAMCO_AFZONE_SINGLE);
    m_content[VAPP_CAMCO_AFZONE_MULTI]->setStr(STR_ID_VAPP_CAMCO_AFZONE_MULTI);        
    m_content[VAPP_CAMCO_AFZONE_CONTINUE]->setStr(STR_ID_VAPP_CAMCO_AFZONE_CONTINUE);     
};
void AFZoneSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();
    CheckandSet(VAPP_CAMCO_AFZONE_SINGLE);
};

void AFZoneSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
 
    if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        if(change_value == VAPP_CAMCO_CAPMODE_SMILE_SHOT || change_value == VAPP_CAMCO_CAPMODE_ASD_SHOT)
        {        
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        #if (AF_SUPPORT) 
            if(m_content[VAPP_CAMCO_AFZONE_CONTINUE]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
                setValue(VAPP_CAMCO_AFZONE_CONTINUE);
            else
                setValue(VAPP_CAMCO_AFZONE_SINGLE);
        #else
            setValue(VAPP_CAMCO_AFZONE_SINGLE);        
        #endif
        }
    #if defined(VAPP_CAMCO_TOUCH_AF_SUPPORT)
        else if(change_value == VAPP_CAMCO_CAPMODE_CONT_SHOT)
        {
            hide(VAPP_CAMCO_SETTING_CAPMODE);

            if(m_content[VAPP_CAMCO_AFZONE_CONTINUE]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
                setValue(VAPP_CAMCO_AFZONE_CONTINUE);
            else
                setValue(VAPP_CAMCO_AFZONE_SINGLE);
        }
    #endif
        else
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);
        }
    }

};

void AFZoneSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();

};

MMI_BOOL AFZoneSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_AFMODE, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_AFMODE, cap_info);        

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
            case MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE:
                cap_info->support_item[idx] = VAPP_CAMCO_AFZONE_SINGLE;
                break;
        
            case MDI_CAMERA_AF_OPERATION_MODE_MULTI_ZONE:
                cap_info->support_item[idx] = VAPP_CAMCO_AFZONE_MULTI;
                break;
                
            case MDI_CAMERA_AF_OPERATION_MODE_CONTINUOUS:
                cap_info->support_item[idx] = VAPP_CAMCO_AFZONE_CONTINUE;
                break;          
                
            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;

        }
    }

    return MMI_TRUE;

}

VfxU32 AFZoneSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_AFZONE_SINGLE:
            return MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE;
    
        case VAPP_CAMCO_AFZONE_MULTI:
            return MDI_CAMERA_AF_OPERATION_MODE_MULTI_ZONE;
    
        case VAPP_CAMCO_AFZONE_CONTINUE:
            return MDI_CAMERA_AF_OPERATION_MODE_CONTINUOUS;

    }
    return CamcoSettingItem::getMappingID(mmiID);    
}

void AEmeterSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_AEMETER;        
        
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_AE_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_AEMETER;

    /* init item str id */
    m_content[VAPP_CAMCO_AEMETER_AUTO]->setStr(STR_ID_VAPP_CAMCO_AEMETER_AUTO);
    m_content[VAPP_CAMCO_AEMETER_SPOT]->setStr(STR_ID_VAPP_CAMCO_AEMETER_SPOT);
    m_content[VAPP_CAMCO_AEMETER_CENTER_WEIGHT]->setStr(STR_ID_VAPP_CAMCO_AEMETER_CENTER_WEIGHT);
    m_content[VAPP_CAMCO_AEMETER_AVERAGE]->setStr(STR_ID_VAPP_CAMCO_AEMETER_AVERAGE);
        
};

void AEmeterSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();
    
    CheckandSet(VAPP_CAMCO_AEMETER_AUTO);
};

void AEmeterSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value); 
};

void AEmeterSetting ::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();

};

MMI_BOOL AEmeterSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_AEMETER, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_AEMETER, cap_info);     
    

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
            case MDI_CAMERA_AE_METER_AUTO:
                cap_info->support_item[idx] = VAPP_CAMCO_AEMETER_AUTO;
                break;

            case MDI_CAMERA_AE_METER_SPOT:
                cap_info->support_item[idx] = VAPP_CAMCO_AEMETER_SPOT;
                break;

            case MDI_CAMERA_AE_METER_CENTER:
                cap_info->support_item[idx] = VAPP_CAMCO_AEMETER_CENTER_WEIGHT;
                break;

            case MDI_CAMERA_AE_METER_AVERAGE:
                cap_info->support_item[idx] = VAPP_CAMCO_AEMETER_AVERAGE;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;

}


VfxU32 AEmeterSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_AEMETER_AUTO:
            return MDI_CAMERA_AE_METER_AUTO;
        
        case VAPP_CAMCO_AEMETER_SPOT:
            return MDI_CAMERA_AE_METER_SPOT;
        
        case VAPP_CAMCO_AEMETER_CENTER_WEIGHT:
            return MDI_CAMERA_AE_METER_CENTER;
        
        case VAPP_CAMCO_AEMETER_AVERAGE:
            return MDI_CAMERA_AE_METER_AVERAGE;

    }
    return CamcoSettingItem::getMappingID(mmiID);    
}



void SharpnessSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_SHARPNESS;        
        
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_SHARPNESS_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_SHARPNESS;

    /* init item str id */
    m_content[VAPP_CAMCO_SHARPNESS_ENHANCE]->setStr(STR_ID_VAPP_CAMCO_ENHANCE);
    m_content[VAPP_CAMCO_SHARPNESS_NORMAL]->setStr(STR_GLOBAL_NORMAL);
    m_content[VAPP_CAMCO_SHARPNESS_REDUCE]->setStr(STR_ID_VAPP_CAMCO_REDUCE);        

    
};
void SharpnessSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();

    /*only reset when first time, others use previous setting */
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = VAPP_CAMCO_SHARPNESS_NORMAL;    
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = VAPP_CAMCO_SHARPNESS_NORMAL;
    }            
    /* use recommend setting */
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_PORTRAIT] = VAPP_CAMCO_SHARPNESS_REDUCE;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE] = VAPP_CAMCO_SHARPNESS_ENHANCE;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_SPORT] = VAPP_CAMCO_SHARPNESS_NORMAL;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_NIGHT] = VAPP_CAMCO_SHARPNESS_REDUCE;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT] = VAPP_CAMCO_SHARPNESS_ENHANCE;
    
    /*only reset when first time, others use previous setting */    
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_AUTO] = VAPP_CAMCO_SHARPNESS_NORMAL;
    }    
    /* use recommend setting */    
    m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_NIGHT] = VAPP_CAMCO_SHARPNESS_REDUCE;         

    m_maxValue = VAPP_CAMCO_SHARPNESS_ENHANCE;
    m_minValue = VAPP_CAMCO_SHARPNESS_REDUCE;    
    for(VfxU32 i = VAPP_CAMCO_SHARPNESS_ENHANCE; i <= VAPP_CAMCO_SHARPNESS_REDUCE; i++)    
    {
        if(m_content[i]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
        {
            if(i > m_maxValue)
                m_maxValue = i;
            if(i < m_minValue)
                m_minValue = i;
        }
    } 
    
    CheckandSet(VAPP_CAMCO_SHARPNESS_NORMAL);
};

void SharpnessSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
 
    if(change_setting == VAPP_CAMCO_SETTING_EFFECT)
    {

        if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        {
            if (change_value != VAPP_CAMCO_EFFECT_NORMAL)
            {
                hide(VAPP_CAMCO_SETTING_EFFECT);
            }
            else
            {
                show(VAPP_CAMCO_SETTING_EFFECT);                                    
            }    
        }
        else
        {      
            if (change_value != VAPP_CAMCO_EFFECT_NORMAL)
            {
                hide(VAPP_CAMCO_SETTING_EFFECT);
            }
            else
            {
                show(VAPP_CAMCO_SETTING_EFFECT);                                    
            }  
        }

    } 
    else if(change_setting == VAPP_CAMCO_SETTING_CAMSCENEMODE)
    {
        if(m_settingMgr->getCurrApp() != VAPP_CAMCO_APP_CAMERA)
			return;
		
        if(last_value == VAPP_CAMCO_CAMSCENEMODE_AUTO || last_value == VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
           m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = m_currentValue;      
           m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = m_currentValue;                 
        }           
        
        if (change_value != VAPP_CAMCO_CAMSCENEMODE_AUTO && change_value != VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE )
        {
            /* apply the scenemode setting */
            setValue(m_CamSceneTable[change_value]);
            hide(VAPP_CAMCO_SETTING_CAMSCENEMODE);
        }
        else
        {
            setValue(m_CamSceneTable[change_value]);
            show(VAPP_CAMCO_SETTING_CAMSCENEMODE);                          
        }  
      
    }      
    else if(change_setting == VAPP_CAMCO_SETTING_VDOSCENEMODE)
    {
        if(m_settingMgr->getCurrApp() != VAPP_CAMCO_APP_RECORDER)
			return;
		
        if(last_value == VAPP_CAMCO_VDOSCENEMODE_AUTO)
        {
           m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_AUTO] = m_currentValue;                    
        }           
        
        if (change_value != VAPP_CAMCO_VDOSCENEMODE_AUTO)
        {
            /* apply the scenemode setting */
            setValue(m_VdoSceneTable[change_value]);
            hide(VAPP_CAMCO_SETTING_VDOSCENEMODE);
        }
        else
        {
            setValue(m_VdoSceneTable[change_value]);
            show(VAPP_CAMCO_SETTING_VDOSCENEMODE);                          
        } 

      
    }  
    else if(change_setting == VAPP_CAMCO_SETTING_ACT_APP)
    {
        show(VAPP_CAMCO_SETTING_ACT_APP);
        if(change_value == VAPP_CAMCO_APP_CAMERA)
        {
            m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = m_currentValue; 
            
            if(m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] == 0xff)
            {
                setValue(VAPP_CAMCO_SHARPNESS_NORMAL);
                m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = VAPP_CAMCO_SHARPNESS_NORMAL;
            }
            else
            {
                setValue(m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)]);
            }      
        }
        else
        {
            m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = m_currentValue; 
            
            if(m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] == 0xff)
            {
                setValue(VAPP_CAMCO_SHARPNESS_NORMAL);
                m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = VAPP_CAMCO_SHARPNESS_NORMAL;
            }
            else
            {
                setValue(m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)]);
            }                
        }
    }     
    else if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        if(change_value == VAPP_CAMCO_CAPMODE_ASD_SHOT)
        {       
            setValue(VAPP_CAMCO_SHARPNESS_NORMAL);   
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        }  
        else
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);        
        }
    }
};

void SharpnessSetting ::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    if(v > m_maxValue)
        v = m_maxValue;
    if(v < m_minValue)
        v = m_minValue;    

    CamcoSettingItem::setValue(v);
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = m_currentValue;
        m_isHiliteMode = VFX_FALSE;    
    }
    else
    {
        m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = m_currentValue;
        m_isHiliteMode = VFX_FALSE;        
    }
    
    if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {      
        mdi_camera_update_para_sharpness(getMappingID(v));
    }
    else
    {
        mdi_video_rec_update_para_sharpness(getMappingID(v));    	
    }    	
};

MMI_BOOL SharpnessSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_SHARPNESS, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_SHARPNESS, cap_info);     
        
    ASSERT(cap_info->item_count < MDI_CAMERA_SUPPORT_ITEM_MAX_NO);

    if (!cap_info->is_support)
    {
        return MMI_FALSE;
    }

    for (VfxU32 idx = 0; idx < cap_info->item_count; idx++)
    {
        VfxU16 item = cap_info->support_item[idx];
        switch (item)
        {
            case MDI_CAMERA_IE_LEVEL_LOW:
                cap_info->support_item[idx] = VAPP_CAMCO_SHARPNESS_REDUCE;
                break;

            case MDI_CAMERA_IE_LEVEL_MEDIUM:
                cap_info->support_item[idx] = VAPP_CAMCO_SHARPNESS_NORMAL;
                break;

            case MDI_CAMERA_IE_LEVEL_HIGH:
                cap_info->support_item[idx] = VAPP_CAMCO_SHARPNESS_ENHANCE;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;

        }
    }

    return MMI_TRUE;

}


VfxU32 SharpnessSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_SHARPNESS_ENHANCE:
            return MDI_CAMERA_IE_LEVEL_HIGH;
        
        case VAPP_CAMCO_SHARPNESS_NORMAL:
            return MDI_CAMERA_IE_LEVEL_MEDIUM;
        
        case VAPP_CAMCO_SHARPNESS_REDUCE:
            return MDI_CAMERA_IE_LEVEL_LOW;
    }
    return CamcoSettingItem::getMappingID(mmiID);    
}



void SharpnessSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;
    if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
    {    
        mdi_camera_update_para_sharpness(getMappingID(v));
    }
    else
    {
        mdi_video_rec_update_para_sharpness(getMappingID(v));
    }
}

void SharpnessSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;

        if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
		    {        
            mdi_camera_update_para_sharpness(getMappingID(m_currentValue));
        }
        else
        {
            mdi_video_rec_update_para_sharpness(getMappingID(m_currentValue));
        }	
    }
}    

VfxU32 SharpnessSetting::getMaxValue(void)
{
    return m_maxValue;
}

VfxU32 SharpnessSetting::getMinValue(void)
{
    return m_minValue;
}


void ContrastSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CONTRAST;        
        
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_CONTRAST_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_CONTRAST;

    /* init item str id */
    m_content[VAPP_CAMCO_CONTRAST_ENHANCE]->setStr(STR_ID_VAPP_CAMCO_ENHANCE);
    m_content[VAPP_CAMCO_CONTRAST_NORMAL]->setStr(STR_GLOBAL_NORMAL);
    m_content[VAPP_CAMCO_CONTRAST_REDUCE]->setStr(STR_ID_VAPP_CAMCO_REDUCE);        
};
void ContrastSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();
    
    /*only reset when first time, others use previous setting */
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = VAPP_CAMCO_CONTRAST_NORMAL;    
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = VAPP_CAMCO_CONTRAST_NORMAL;
    }            
    /* use recommend setting */
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_PORTRAIT] = VAPP_CAMCO_CONTRAST_NORMAL;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE] = VAPP_CAMCO_CONTRAST_NORMAL;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_SPORT] = VAPP_CAMCO_CONTRAST_NORMAL;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_NIGHT] = VAPP_CAMCO_CONTRAST_NORMAL;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT] = VAPP_CAMCO_CONTRAST_ENHANCE;
    
    /*only reset when first time, others use previous setting */    
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_AUTO] = VAPP_CAMCO_CONTRAST_NORMAL;
    }    
    /* use recommend setting */    
    m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_NIGHT] = VAPP_CAMCO_CONTRAST_NORMAL;    

    m_maxValue = VAPP_CAMCO_CONTRAST_ENHANCE;
    m_minValue = VAPP_CAMCO_CONTRAST_REDUCE;    
    for(VfxU32 i = VAPP_CAMCO_CONTRAST_ENHANCE; i <= VAPP_CAMCO_CONTRAST_REDUCE; i++)    
    {
        if(m_content[i]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
        {
            if(i > m_maxValue)
                m_maxValue = i;
            if(i < m_minValue)
                m_minValue = i;
        }
    } 
    
    CheckandSet(VAPP_CAMCO_CONTRAST_NORMAL);

       
};

void ContrastSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
 
    if(change_setting == VAPP_CAMCO_SETTING_EFFECT)
    {
           
        if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        {        
            if (change_value != VAPP_CAMCO_EFFECT_NORMAL)
            {
                hide(VAPP_CAMCO_SETTING_EFFECT);
            }
            else
            {
                show(VAPP_CAMCO_SETTING_EFFECT);                                    
            }    
        }
        else
        {
            if (change_value != VAPP_CAMCO_EFFECT_NORMAL)
            {
                hide(VAPP_CAMCO_SETTING_EFFECT);
            }
            else
            {
                show(VAPP_CAMCO_SETTING_EFFECT);                                    
            }  
        }

    }    
    else if(change_setting == VAPP_CAMCO_SETTING_CAMSCENEMODE)
    {
        if(m_settingMgr->getCurrApp() != VAPP_CAMCO_APP_CAMERA)
			return;
		
        if(last_value == VAPP_CAMCO_CAMSCENEMODE_AUTO || last_value == VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
           m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = m_currentValue;      
           m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = m_currentValue;                 
        }           
        
        if (change_value != VAPP_CAMCO_CAMSCENEMODE_AUTO && change_value != VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE )
        {
            /* apply the scenemode setting */
            setValue(m_CamSceneTable[change_value]);
            hide(VAPP_CAMCO_SETTING_CAMSCENEMODE);
        }
        else
        {
            setValue(m_CamSceneTable[change_value]);
            show(VAPP_CAMCO_SETTING_CAMSCENEMODE);                          
        }  
      
    }      
    else if(change_setting == VAPP_CAMCO_SETTING_VDOSCENEMODE)
    {
        if(m_settingMgr->getCurrApp() != VAPP_CAMCO_APP_RECORDER)
			return;

        if(last_value == VAPP_CAMCO_VDOSCENEMODE_AUTO)
        {
           m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_AUTO] = m_currentValue;                    
        }           
        
        if (change_value != VAPP_CAMCO_VDOSCENEMODE_AUTO)
        {
            /* apply the scenemode setting */
            setValue(m_VdoSceneTable[change_value]);
            hide(VAPP_CAMCO_SETTING_VDOSCENEMODE);
        }
        else
        {
            setValue(m_VdoSceneTable[change_value]);
            show(VAPP_CAMCO_SETTING_VDOSCENEMODE);                          
        }       
    }  
    else if(change_setting == VAPP_CAMCO_SETTING_ACT_APP)
    {
        show(VAPP_CAMCO_SETTING_ACT_APP);
        if(change_value == VAPP_CAMCO_APP_CAMERA)
        {
            m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = m_currentValue; 
            
            if(m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] == 0xff)
            {
                setValue(VAPP_CAMCO_CONTRAST_NORMAL);
                m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = VAPP_CAMCO_CONTRAST_NORMAL;
            }
            else
            {
                setValue(m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)]);
            }      
        }
        else
        {
            m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = m_currentValue; 
            
            if(m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] == 0xff)
            {
                setValue(VAPP_CAMCO_CONTRAST_NORMAL);
                m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = VAPP_CAMCO_CONTRAST_NORMAL;
            }
            else
            {
                setValue(m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)]);
            }              
        }
    }   
    else if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        if(change_value == VAPP_CAMCO_CAPMODE_ASD_SHOT)
        {       
            setValue(VAPP_CAMCO_CONTRAST_NORMAL);   
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        }  
        else
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);        
        }
    }


};
void ContrastSetting ::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    if(v > m_maxValue)
        v = m_maxValue;
    if(v < m_minValue)
        v = m_minValue;    
    
    CamcoSettingItem::setValue(v);
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = m_currentValue;
        m_isHiliteMode = VFX_FALSE;    
    }
    else
    {
        m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = m_currentValue;
        m_isHiliteMode = VFX_FALSE;        
    }    
    
    if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {  
        mdi_camera_update_para_contrast(getMappingID(v));
    }
    else
    {
        mdi_video_rec_update_para_contrast(getMappingID(v));    	
    }
};


MMI_BOOL ContrastSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{ 
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_CONTRAST, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_CONTRAST, cap_info);         

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
            case MDI_CAMERA_IE_LEVEL_LOW:
                cap_info->support_item[idx] = VAPP_CAMCO_CONTRAST_REDUCE;
                break;

            case MDI_CAMERA_IE_LEVEL_MEDIUM:
                cap_info->support_item[idx] = VAPP_CAMCO_CONTRAST_NORMAL;
                break;

            case MDI_CAMERA_IE_LEVEL_HIGH:
                cap_info->support_item[idx] = VAPP_CAMCO_CONTRAST_ENHANCE;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;


        }
    }

    return MMI_TRUE;

}

VfxU32 ContrastSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_CONTRAST_ENHANCE:
            return MDI_CAMERA_IE_LEVEL_HIGH;
        
        case VAPP_CAMCO_CONTRAST_NORMAL:
            return MDI_CAMERA_IE_LEVEL_MEDIUM;
        
        case VAPP_CAMCO_CONTRAST_REDUCE:
            return MDI_CAMERA_IE_LEVEL_LOW;
    }
    return CamcoSettingItem::getMappingID(mmiID);    
}



void ContrastSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
    {
        mdi_camera_update_para_contrast(getMappingID(v));
    }
    else
    {
        mdi_video_rec_update_para_contrast(getMappingID(v));
    }
}

void ContrastSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
		if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
		{      
            mdi_camera_update_para_contrast(getMappingID(m_currentValue));
		}
		else
		{
            mdi_video_rec_update_para_contrast(getMappingID(m_currentValue));
		}          

    }
}   

VfxU32 ContrastSetting::getMaxValue(void)
{
    return m_maxValue;
}

VfxU32 ContrastSetting::getMinValue(void)
{
    return m_minValue;
}


void SaturationSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_SATURATION;    
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_SATURATION_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_SATURATION;

    /* init item str id */
    m_content[VAPP_CAMCO_SATURATION_ENHANCE]->setStr(STR_ID_VAPP_CAMCO_ENHANCE);
    m_content[VAPP_CAMCO_SATURATION_NORMAL]->setStr(STR_GLOBAL_NORMAL);
    m_content[VAPP_CAMCO_SATURATION_REDUCE]->setStr(STR_ID_VAPP_CAMCO_REDUCE);        
};
void SaturationSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();

    /*only reset when first time, others use previous setting */
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = VAPP_CAMCO_SATURATION_NORMAL;    
        m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = VAPP_CAMCO_SATURATION_NORMAL;
    }            
    /* use recommend setting */
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_PORTRAIT] = VAPP_CAMCO_SATURATION_REDUCE;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_LANDSCAPE] = VAPP_CAMCO_SATURATION_NORMAL;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_SPORT] = VAPP_CAMCO_SATURATION_NORMAL;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_NIGHT] = VAPP_CAMCO_SATURATION_REDUCE;
    m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_DOCUMENT] = VAPP_CAMCO_SATURATION_ENHANCE;
    
    /*only reset when first time, others use previous setting */    
    if (m_currentValue == 0xff ||m_content[m_currentValue]->getStatus() != VAPP_CAMCO_SETTING_CAP_ENABLED)
    {
        m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_AUTO] = VAPP_CAMCO_SATURATION_NORMAL;
    }    
    /* use recommend setting */    
    m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_NIGHT] = VAPP_CAMCO_SATURATION_REDUCE;  

    m_maxValue = VAPP_CAMCO_SATURATION_ENHANCE;
    m_minValue = VAPP_CAMCO_SATURATION_REDUCE;    
    for(VfxU32 i = VAPP_CAMCO_SATURATION_ENHANCE; i <= VAPP_CAMCO_SATURATION_REDUCE; i++)    
    {
        if(m_content[i]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
        {
            if(i > m_maxValue)
                m_maxValue = i;
            if(i < m_minValue)
                m_minValue = i;
        }
    }    
    
    CheckandSet(VAPP_CAMCO_SATURATION_NORMAL);


};

void SaturationSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_EFFECT)
    {
             
        if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        {
            if (change_value != VAPP_CAMCO_EFFECT_NORMAL)
            {
                hide(VAPP_CAMCO_SETTING_EFFECT);
            }
            else
            {
                show(VAPP_CAMCO_SETTING_EFFECT);                                    
            }    
        }
        else
        {
            if (change_value != VAPP_CAMCO_EFFECT_NORMAL)
            {
                hide(VAPP_CAMCO_SETTING_EFFECT);
            }
            else
            {
                show(VAPP_CAMCO_SETTING_EFFECT);                                    
            }  
        }

    }    
    else if(change_setting == VAPP_CAMCO_SETTING_CAMSCENEMODE)
    {
        if(m_settingMgr->getCurrApp() != VAPP_CAMCO_APP_CAMERA)
			return;
		
        if(last_value == VAPP_CAMCO_CAMSCENEMODE_AUTO || last_value == VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE)
        {
           m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_AUTO] = m_currentValue;      
           m_CamSceneTable[VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE] = m_currentValue;                 
        }           
        
        if (change_value != VAPP_CAMCO_CAMSCENEMODE_AUTO && change_value != VAPP_CAMCO_CAMSCENEMODE_ANTI_SHAKE )
        {
            /* apply the scenemode setting */
            setValue(m_CamSceneTable[change_value]);
            hide(VAPP_CAMCO_SETTING_CAMSCENEMODE);
        }
        else
        {
            setValue(m_CamSceneTable[change_value]);
            show(VAPP_CAMCO_SETTING_CAMSCENEMODE);                          
        }  
      
    }      
    else if(change_setting == VAPP_CAMCO_SETTING_VDOSCENEMODE)
    {
        if(m_settingMgr->getCurrApp() != VAPP_CAMCO_APP_RECORDER)
			return;

        if(last_value == VAPP_CAMCO_VDOSCENEMODE_AUTO)
        {
           m_VdoSceneTable[VAPP_CAMCO_VDOSCENEMODE_AUTO] = m_currentValue;                    
        }           
        
        if (change_value != VAPP_CAMCO_VDOSCENEMODE_AUTO)
        {
            /* apply the scenemode setting */
            setValue(m_VdoSceneTable[change_value]);
            hide(VAPP_CAMCO_SETTING_VDOSCENEMODE);
        }
        else
        {
            setValue(m_VdoSceneTable[change_value]);
            show(VAPP_CAMCO_SETTING_VDOSCENEMODE);                          
        } 

      
    }  
    else if(change_setting == VAPP_CAMCO_SETTING_ACT_APP)
    {
        show(VAPP_CAMCO_SETTING_ACT_APP);
        if(change_value == VAPP_CAMCO_APP_CAMERA)
        {
            m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = m_currentValue; 
            
            if(m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] == 0xff)
            {
                setValue(VAPP_CAMCO_SATURATION_NORMAL);
                m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = VAPP_CAMCO_SATURATION_NORMAL;
            }
            else
            {
                setValue(m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)]);
            }      
        }
        else
        {
            m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = m_currentValue; 
            
            if(m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] == 0xff)
            {
                setValue(VAPP_CAMCO_SATURATION_NORMAL);
                m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = VAPP_CAMCO_SATURATION_NORMAL;
            }
            else
            {
                setValue(m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)]);
            }               
        }
    }   
    else if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        if(change_value == VAPP_CAMCO_CAPMODE_ASD_SHOT)
        {       
            setValue(VAPP_CAMCO_SATURATION_NORMAL);   
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        }  
        else
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);        
        }
    }


};
void SaturationSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    if(v > m_maxValue)
        v = m_maxValue;
    if(v < m_minValue)
        v = m_minValue;    
    
    CamcoSettingItem::setValue(v);
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {
        m_CamSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_CAMSCENEMODE)] = m_currentValue;
        m_isHiliteMode = VFX_FALSE;    
    }
    else
    {
        m_VdoSceneTable[m_settingMgr->getValue(VAPP_CAMCO_SETTING_VDOSCENEMODE)] = m_currentValue;
        m_isHiliteMode = VFX_FALSE;        
    }     
    if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
    {  
        mdi_camera_update_para_saturation(getMappingID(v));
    }
    else
    {
        mdi_video_rec_update_para_saturation(getMappingID(v)); 	
    }       


};

MMI_BOOL SaturationSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_SATURATION, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_SATURATION, cap_info);     

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
            case MDI_CAMERA_IE_LEVEL_LOW:
                cap_info->support_item[idx] = VAPP_CAMCO_SATURATION_REDUCE;
                break;

            case MDI_CAMERA_IE_LEVEL_MEDIUM:
                cap_info->support_item[idx] = VAPP_CAMCO_SATURATION_NORMAL;
                break;

            case MDI_CAMERA_IE_LEVEL_HIGH:
                cap_info->support_item[idx] = VAPP_CAMCO_SATURATION_ENHANCE;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;
        }
    }

    return MMI_TRUE;

}


VfxU32 SaturationSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_SATURATION_ENHANCE:
            return MDI_CAMERA_IE_LEVEL_HIGH;
        
        case VAPP_CAMCO_SATURATION_NORMAL:
            return MDI_CAMERA_IE_LEVEL_MEDIUM;
        
        case VAPP_CAMCO_SATURATION_REDUCE:
            return MDI_CAMERA_IE_LEVEL_LOW;
    }
    return CamcoSettingItem::getMappingID(mmiID);    
}


void SaturationSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    if (m_settingMgr->getCurrCam() == VAPP_CAMCO_APP_CAMERA)
    {
        mdi_camera_update_para_saturation(getMappingID(v));
    }
    else
    {
        mdi_video_rec_update_para_saturation(getMappingID(v));
    }
}

void SaturationSetting :: resetEffect(void)
{
    if(m_isHiliteMode)
    {
        m_isHiliteMode = VFX_FALSE;
        if (m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        {         
            mdi_camera_update_para_saturation(getMappingID(m_currentValue));
        }
        else
        {         
            mdi_video_rec_update_para_saturation(getMappingID(m_currentValue));
        }        	
    }
}   

VfxU32 SaturationSetting::getMaxValue(void)
{
    return m_maxValue;
}

VfxU32 SaturationSetting::getMinValue(void)
{
    return m_minValue;
}

void ShuttersoundSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_SHUTTERSOUND;        
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_CAP_AUD_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_SHUTTERSOUND;

    /* init item str id */
    m_content[VAPP_CAMCO_SHUTTERSOUND_OFF]->setStr(STR_GLOBAL_OFF);
    m_content[VAPP_CAMCO_SHUTTERSOUND_SOUND_1]->setStr(STR_ID_VAPP_CAMCO_SHUTTERSOUND_SOUND_1);
    m_content[VAPP_CAMCO_SHUTTERSOUND_SOUND_2]->setStr(STR_ID_VAPP_CAMCO_SHUTTERSOUND_SOUND_2);
    m_content[VAPP_CAMCO_SHUTTERSOUND_SOUND_3]->setStr(STR_ID_VAPP_CAMCO_SHUTTERSOUND_SOUND_3);        
};


void ShuttersoundSetting :: setDefault(void)
{
    m_cap = ENABLE();
    m_content[VAPP_CAMCO_SHUTTERSOUND_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SHUTTERSOUND_SOUND_1]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SHUTTERSOUND_SOUND_2]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_SHUTTERSOUND_SOUND_3]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);    

    m_content[VAPP_CAMCO_SHUTTERSOUND_OFF]->setValue(VAPP_CAMCO_SHUTTERSOUND_OFF);
    m_content[VAPP_CAMCO_SHUTTERSOUND_SOUND_1]->setValue(VAPP_CAMCO_SHUTTERSOUND_SOUND_1);
    m_content[VAPP_CAMCO_SHUTTERSOUND_SOUND_2]->setValue(VAPP_CAMCO_SHUTTERSOUND_SOUND_2);
    m_content[VAPP_CAMCO_SHUTTERSOUND_SOUND_3]->setValue(VAPP_CAMCO_SHUTTERSOUND_SOUND_3);        

    CheckandSet(VAPP_CAMCO_SHUTTERSOUND_SOUND_1);        
};

void ShuttersoundSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 

    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();

};


void ShuttersoundSetting :: applyEffect(VfxU16 v)
{
    if(m_lastValue == m_currentValue)
        return;

    switch (v)
    {
        case VAPP_CAMCO_SHUTTERSOUND_OFF:
            /* do nothing */
            break;

        case VAPP_CAMCO_SHUTTERSOUND_SOUND_1:
            /* play sound 1 */
            play_shuttersound(VAPP_CAMCO_SHUTTERSOUND_SOUND_1);
            break;

        case VAPP_CAMCO_SHUTTERSOUND_SOUND_2:
            /* play sound 2 */
            play_shuttersound(VAPP_CAMCO_SHUTTERSOUND_SOUND_2);
            break;

        case VAPP_CAMCO_SHUTTERSOUND_SOUND_3:
            /* play sound 3 */
            play_shuttersound(VAPP_CAMCO_SHUTTERSOUND_SOUND_3);
            break;

        default:
            MMI_ASSERT(0);
    }

}


void ShuttersoundSetting :: play_shuttersound(VfxU16 shuttersound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 aud_len;
    U8 *aud_data = NULL;
    U8 aud_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //if (vapp_camco_is_slient_mode())
    //{
    //    return;
    //}

    switch (shuttersound)
    {
        case VAPP_CAMCO_SHUTTERSOUND_OFF:
            break;

        case VAPP_CAMCO_SHUTTERSOUND_SOUND_1:
            aud_data = get_audio((U16) (AUD_ID_VAPP_CAMCO_CAPTURE_1), &aud_type, &aud_len);
            break;

        case VAPP_CAMCO_SHUTTERSOUND_SOUND_2:
            aud_data = get_audio((U16) (AUD_ID_VAPP_CAMCO_CAPTURE_2), &aud_type, &aud_len);
            break;

        case VAPP_CAMCO_SHUTTERSOUND_SOUND_3:
            aud_data = get_audio((U16) (AUD_ID_VAPP_CAMCO_CAPTURE_3), &aud_type, &aud_len);
            break;

        default:
            MMI_ASSERT(0);
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

void BandingSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_BANDING;        
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_BANDING_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_BANDING;

    /* init item str id */
    m_content[VAPP_CAMCO_BANDING_50HZ]->setStr(STR_ID_VAPP_CAMCO_BANDING_50HZ);
    m_content[VAPP_CAMCO_BANDING_60HZ]->setStr(STR_ID_VAPP_CAMCO_BANDING_60HZ);        
};


void BandingSetting :: setDefault(void)
{
    m_cap = ENABLE();
    m_content[VAPP_CAMCO_BANDING_50HZ]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_BANDING_60HZ]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);    

    m_content[VAPP_CAMCO_BANDING_50HZ]->setValue(VAPP_CAMCO_BANDING_50HZ);
    m_content[VAPP_CAMCO_BANDING_60HZ]->setValue(VAPP_CAMCO_BANDING_60HZ);        

    CheckandSet(VAPP_CAMCO_BANDING_60HZ);     

    g_vapp_camco_banding_setting = (vapp_camco_banding_enum)m_currentValue;
};

void BandingSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value); 
};

void BandingSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    CamcoSettingItem::setValue(v);

    m_settingMgr->needRestartPreview();

    g_vapp_camco_banding_setting = (vapp_camco_banding_enum)m_currentValue;
};


VfxU32 BandingSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_BANDING_50HZ:
            return MDI_CAMERA_BANDING_50HZ;
        
        case VAPP_CAMCO_BANDING_60HZ:
            return MDI_CAMERA_BANDING_60HZ;
    }
    return CamcoSettingItem::getMappingID(mmiID);    
}

VfxU16 BandingSetting :: getBanding(void)
{
    if (m_currentValue == 0xff ||m_currentValue == VAPP_CAMCO_BANDING_60HZ)
    {
        return MDI_CAMERA_BANDING_60HZ;
    }
    else
    {
        return MDI_CAMERA_BANDING_50HZ;
    }

}

void VdoSceneModeSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_VDOSCENEMODE;        
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_SETTING_SCN_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_SCENEMODE;

    /* init item str id */
    m_content[VAPP_CAMCO_VDOSCENEMODE_AUTO]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_AUTO);
    m_content[VAPP_CAMCO_VDOSCENEMODE_NIGHT]->setStr(STR_ID_VAPP_CAMCO_SCENEMODE_NIGHT);

    /* init item img id */
    m_content[VAPP_CAMCO_VDOSCENEMODE_AUTO]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_SCN_MODE_AUTO_ICON);    
    m_content[VAPP_CAMCO_VDOSCENEMODE_NIGHT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_SCN_MODE_NIGHT_ICON);        

    m_content[VAPP_CAMCO_VDOSCENEMODE_AUTO]->setStatusIcon(0);    
    m_content[VAPP_CAMCO_VDOSCENEMODE_NIGHT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_SCN_MODE_NIGHT_ICON);        
};


void VdoSceneModeSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();
    CheckandSet(VAPP_CAMCO_VDOSCENEMODE_AUTO);       
    
};


void VdoSceneModeSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value); 
};

void VdoSceneModeSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 

    CamcoSettingItem::setValue(v);
    if(m_lastValue != m_currentValue)
    {
        m_settingMgr->needRestartPreview();
    }

};

VfxU32 VdoSceneModeSetting :: getMappingID(VfxU32 mmiID)
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


MMI_BOOL VdoSceneModeSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
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

void RecSizeSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_RECSIZE;        
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_RECSIZE_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_RECSIZE;

    /* init item str id */   
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
    m_content[VAPP_CAMCO_RECSIZE_WALLPAPER]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_WALLPAPER);  
    
    /* init item img id */
    m_content[VAPP_CAMCO_RECSIZE_SQCIF]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_SQCIF_ICON);
    m_content[VAPP_CAMCO_RECSIZE_QQVGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_QQVGA_ICON);        
    m_content[VAPP_CAMCO_RECSIZE_QCIF]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_QCIF_ICON);
    m_content[VAPP_CAMCO_RECSIZE_QVGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_QVGA_ICON);
    m_content[VAPP_CAMCO_RECSIZE_CIF]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_CIF_ICON);  
    m_content[VAPP_CAMCO_RECSIZE_WQVGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_WQVGA_ICON);          
    m_content[VAPP_CAMCO_RECSIZE_CIF2]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_CIF2_ICON);      
    m_content[VAPP_CAMCO_RECSIZE_HVGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_HVGA_ICON);   
    m_content[VAPP_CAMCO_RECSIZE_NHD]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_NHD_ICON);        
    m_content[VAPP_CAMCO_RECSIZE_VGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_VGA_ICON);
    m_content[VAPP_CAMCO_RECSIZE_4CIF]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_4CIF_ICON);    
    m_content[VAPP_CAMCO_RECSIZE_D1]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_D1_ICON); 
    m_content[VAPP_CAMCO_RECSIZE_D12]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_D12_ICON);     
    m_content[VAPP_CAMCO_RECSIZE_WVGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_WVGA_ICON);                                        
    m_content[VAPP_CAMCO_RECSIZE_SVGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_SVGA_ICON);  
    m_content[VAPP_CAMCO_RECSIZE_WVGA2]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_WVGA2_ICON);             
    m_content[VAPP_CAMCO_RECSIZE_FWVGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_FWVGA_ICON);                 
    m_content[VAPP_CAMCO_RECSIZE_XGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_XGA_ICON);  
    m_content[VAPP_CAMCO_RECSIZE_720P]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_720P_ICON);  
    m_content[VAPP_CAMCO_RECSIZE_4VGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_4VGA_ICON);  
    m_content[VAPP_CAMCO_RECSIZE_SXGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_SXGA_ICON);  
    m_content[VAPP_CAMCO_RECSIZE_16CIF]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_16CIF_ICON);  
    m_content[VAPP_CAMCO_RECSIZE_4SVGA]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_4SVGA_ICON);  
    m_content[VAPP_CAMCO_RECSIZE_FHD]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_RECSIZE_FHD_ICON);      
    m_content[VAPP_CAMCO_RECSIZE_WALLPAPER]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_CAPSIZE_WP_ICON);      
};


void RecSizeSetting :: setDefault(void)
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
    m_content[VAPP_CAMCO_RECSIZE_WALLPAPER]->setValue(VAPP_CAMCO_RECSIZE_WALLPAPER);       

    memset(vapp_camco_codec_vs_recsize_vs_recqty_vs_storage, 0,  (sizeof(VfxBool) * VAPP_CAMCO_VISCODEC_END * VAPP_CAMCO_RECSIZE_END * VAPP_CAMCO_VISQTY_END * 2));

    mdi_video_rec_spec_struct spec_entry_struct;
    VfxU32 count = mdi_video_rec_query_entry_num_of_video_spec_table();
    for(VfxU32 i=0; i < count; i++)
    {
        VfxU32 l = 0, m = 0, n = 0;
        VfxS32 p =0, q = 0;
        
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

        #ifndef __VAPP_CAMCO_ROTATABLE_UI__                
        #if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)
        
            case MDI_VIDEO_REC_RESOLUTION_176x208:
                m_content[VAPP_CAMCO_RECSIZE_WALLPAPER]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);   
                m_wallpaperSizeMDIEnum = MDI_VIDEO_VIDEO_SIZE_WP_QCIF;
                m_wallpaperSize[0] = 176;
                m_wallpaperSize[1] = 208;                
                l = VAPP_CAMCO_RECSIZE_WALLPAPER;                
                break;    
                
            case MDI_VIDEO_REC_RESOLUTION_240x320:
                m_content[VAPP_CAMCO_RECSIZE_WALLPAPER]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);   
                m_wallpaperSizeMDIEnum = MDI_VIDEO_VIDEO_SIZE_WP_QVGA;
                m_wallpaperSize[0] = 240;
                m_wallpaperSize[1] = 320;                
                l = VAPP_CAMCO_RECSIZE_WALLPAPER;                
                break;    
                
            case MDI_VIDEO_REC_RESOLUTION_240x400:
                m_content[VAPP_CAMCO_RECSIZE_WALLPAPER]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);   
                m_wallpaperSizeMDIEnum = MDI_VIDEO_VIDEO_SIZE_WP_WQVGA;
                m_wallpaperSize[0] = 240;
                m_wallpaperSize[1] = 400;                
                l = VAPP_CAMCO_RECSIZE_WALLPAPER;                
                break;    
                
            case MDI_VIDEO_REC_RESOLUTION_320x480:
                m_content[VAPP_CAMCO_RECSIZE_WALLPAPER]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);   
                m_wallpaperSizeMDIEnum = MDI_VIDEO_VIDEO_SIZE_WP_HVGA;
                m_wallpaperSize[0] = 320;
                m_wallpaperSize[1] = 480;                
                l = VAPP_CAMCO_RECSIZE_WALLPAPER;                
                break;    
                
            case MDI_VIDEO_REC_RESOLUTION_480x800:
                m_content[VAPP_CAMCO_RECSIZE_WALLPAPER]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);   
                m_wallpaperSizeMDIEnum = MDI_VIDEO_VIDEO_SIZE_WP_WVGA;
                m_wallpaperSize[0] = 480;
                m_wallpaperSize[1] = 800;                
                l = VAPP_CAMCO_RECSIZE_WALLPAPER;                
                break;    
                
        #endif
        #endif
        
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
        }        
        vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[m][l][n][p] = VFX_TRUE;
        vapp_camco_codec_vs_recsize_vs_recqty_vs_storage[m][l][n][q] = VFX_TRUE;    

        // when ext calling, default use the last setting (lowest)
        if(i == 0 || m_settingMgr->IsExtSetting())    
        {
            if(m_settingMgr->IsExtSetting())
            {
                // when ext calling, defult size should not use wallpaper
                // it may be larger than CIF            
                // and we hope the size can as smaller as we can
                if((l != VAPP_CAMCO_RECSIZE_WALLPAPER && n >= m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISQTY)) ||
                   (m_settingMgr->getValue(VAPP_CAMCO_SETTING_RECSIZE) == 0XFF ||
                    m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISQTY) == 0XFF ||
                    m_settingMgr->getValue(VAPP_CAMCO_SETTING_VISCODEC) == 0XFF))
                {
    	            ((RecSizeSetting*)(m_settingMgr->getSetting(VAPP_CAMCO_SETTING_RECSIZE)))->resetValue(l);
    	            ((VisQtySetting*)(m_settingMgr->getSetting(VAPP_CAMCO_SETTING_VISQTY)))->resetValue(n);        
    	            ((VisCodecSetting*)(m_settingMgr->getSetting(VAPP_CAMCO_SETTING_VISCODEC)))->resetValue(m);                      
                }
            }
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
};


void RecSizeSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
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
};

void RecSizeSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 

    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();

};

MMI_BOOL RecSizeSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    return MMI_FALSE;
}

VfxU32 RecSizeSetting :: getMappingID(VfxU32 mmiID)
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
            
        case VAPP_CAMCO_RECSIZE_WALLPAPER:
            return  m_wallpaperSizeMDIEnum;
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

        case VAPP_CAMCO_RECSIZE_WALLPAPER:
            size.width = m_wallpaperSize[0];
            size.height = m_wallpaperSize[1];
            return size;           
            
    }

    size.width = 128;
    size.height = 96;
    return size;
}

void RecSizeSetting :: config_recsize_capability(vapp_camco_setting_enum changed_setting)
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
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_TIME_LAPSE_ICON;
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
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_TIME_LAPSE_PERIOD_ICON;
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

void LimitSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_LIMIT;            
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_LIMIT_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_LIMIT;

    /* init item str id */
    m_content[VAPP_CAMCO_LIMIT_NO_LIMIT]->setStr(STR_ID_VAPP_CAMCO_LIMIT_NO_LIMIT);
    m_content[VAPP_CAMCO_LIMIT_TIME_15S]->setStr(STR_ID_VAPP_CAMCO_LIMIT_TIME_15S);
    m_content[VAPP_CAMCO_LIMIT_TIME_30S]->setStr(STR_ID_VAPP_CAMCO_LIMIT_TIME_30S);
    m_content[VAPP_CAMCO_LIMIT_TIME_60S]->setStr(STR_ID_VAPP_CAMCO_LIMIT_TIME_60S);
    m_content[VAPP_CAMCO_LIMIT_TIME_300S]->setStr(STR_ID_VAPP_CAMCO_LIMIT_TIME_300S);
    m_content[VAPP_CAMCO_LIMIT_TIME_600S]->setStr(STR_ID_VAPP_CAMCO_LIMIT_TIME_600S);
    m_content[VAPP_CAMCO_LIMIT_SIZE_95K]->setStr(STR_ID_VAPP_CAMCO_LIMIT_SIZE_95K);
    m_content[VAPP_CAMCO_LIMIT_SIZE_195K]->setStr(STR_ID_VAPP_CAMCO_LIMIT_SIZE_195K);
    m_content[VAPP_CAMCO_LIMIT_SIZE_295K]->setStr(STR_ID_VAPP_CAMCO_LIMIT_SIZE_295K);

    /* init item img id */
    //m_content[VAPP_CAMCO_LIMIT_NO_LIMIT]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_LIMIT_NOLIMIT_ICON);    
    //m_content[VAPP_CAMCO_LIMIT_TIME_15S]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_LIMIT_15S_ICON);
    //m_content[VAPP_CAMCO_LIMIT_TIME_30S]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_LIMIT_30S_ICON);
    //m_content[VAPP_CAMCO_LIMIT_TIME_60S]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_LIMIT_60S_ICON);
    //m_content[VAPP_CAMCO_LIMIT_SIZE_95K]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_LIMIT_95K_ICON);
    //m_content[VAPP_CAMCO_LIMIT_SIZE_195K]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_LIMIT_195K_ICON);
    //m_content[VAPP_CAMCO_LIMIT_SIZE_295K]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_LIMIT_295K_ICON);

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
};


void LimitSetting :: setDefault(void)
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

    CheckandSet(VAPP_CAMCO_LIMIT_NO_LIMIT);       
};

void LimitSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
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

};

void LimitSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 

    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();

};

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


void VisQtySetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_VISQTY;                
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_QTY_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_VISQTY;

    /* init item str id */
    m_content[VAPP_CAMCO_VISQTY_FINE]->setStr(STR_ID_VAPP_CAMCO_VISQTY_FINE);
    m_content[VAPP_CAMCO_VISQTY_GOOD]->setStr(STR_ID_VAPP_CAMCO_VISQTY_GOOD);
    m_content[VAPP_CAMCO_VISQTY_NORMAL]->setStr(STR_ID_VAPP_CAMCO_VISQTY_NORMAL);
    m_content[VAPP_CAMCO_VISQTY_LOW]->setStr(STR_ID_VAPP_CAMCO_VISQTY_LOW);
    m_content[VAPP_CAMCO_VISQTY_LCD]->setStr(STR_ID_VAPP_CAMCO_CAPSIZE_WALLPAPER);    
    

    
};
void VisQtySetting :: setDefault(void)
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
        VfxU32 currectQty = VAPP_CAMCO_VISQTY_FINE;
        MDI_RESULT  ret = mdi_video_rec_get_video_spec_by_index(i, &spec_entry_struct, sizeof(spec_entry_struct));
        
        if(ret != MDI_RES_VDOREC_SUCCEED)
            continue;
            
        switch (spec_entry_struct.quality)
        {
            case MDI_VIDEO_REC_QTY_LOW:             
                m_content[VAPP_CAMCO_VISQTY_LOW]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);    
                currectQty = VAPP_CAMCO_VISQTY_LOW;
                break;           
            case MDI_VIDEO_REC_QTY_NORMAL:             
                m_content[VAPP_CAMCO_VISQTY_NORMAL]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);    
                currectQty = VAPP_CAMCO_VISQTY_NORMAL;                
                break;           
            case MDI_VIDEO_REC_QTY_FINE:             
                m_content[VAPP_CAMCO_VISQTY_FINE]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);    
                currectQty = VAPP_CAMCO_VISQTY_FINE;                
                break;           
            case MDI_VIDEO_REC_QTY_HIGH:             
                m_content[VAPP_CAMCO_VISQTY_GOOD]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);    
                currectQty = VAPP_CAMCO_VISQTY_GOOD;                
                break;               
        }
        
    #if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__)  
    
        if(recorder_config_has_dependency() && !m_settingMgr->IsExtSetting())
        {          
            switch (spec_entry_struct.video_size)
            {     
                case MDI_VIDEO_REC_RESOLUTION_176x208:
                case MDI_VIDEO_REC_RESOLUTION_240x320:
                case MDI_VIDEO_REC_RESOLUTION_240x400:
                case MDI_VIDEO_REC_RESOLUTION_320x480:
                case MDI_VIDEO_REC_RESOLUTION_480x800:
                    m_wallpaperQtyMDIEnum = currectQty;                            
                    m_content[VAPP_CAMCO_VISQTY_LCD]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);                
                    break;    
            }
        }   
        
    #endif
    
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
};


void VisQtySetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
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
};

void VisQtySetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();

};

VfxU32 VisQtySetting :: getMappingID(VfxU32 mmiID)
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

        case VAPP_CAMCO_VISQTY_LCD:
            return m_wallpaperQtyMDIEnum;            
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void VisQtySetting :: config_recqty_capability(vapp_camco_setting_enum changed_setting)
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


void AFmodeSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_AFMODE;            
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_AF_MODE_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_AFMODE;

    /* init item str id */
    m_content[VAPP_CAMCO_AFMODE_OFF]->setStr(STR_GLOBAL_OFF);
    m_content[VAPP_CAMCO_AFMODE_SINGLE]->setStr(STR_ID_VAPP_CAMCO_AFMODE_SINGLE);
    m_content[VAPP_CAMCO_AFMODE_CONT]->setStr(STR_ID_VAPP_CAMCO_AFMODE_CONT);

    //m_content[VAPP_CAMCO_AFMODE_OFF]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_AFMODE_OFF_ICON);
    //m_content[VAPP_CAMCO_AFMODE_SINGLE]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_AFMODE_SINGLE_ICON);
    //m_content[VAPP_CAMCO_AFMODE_CONT]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_AFMODE_CONT_ICON);    
};


void AFmodeSetting :: setDefault(void)
{
    CamcoSettingItem::setDefault();
    CheckandSet(VAPP_CAMCO_AFMODE_OFF);         
    
};


void AFmodeSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value); 

};

void AFmodeSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK 
        
    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();        
};

MMI_BOOL AFmodeSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
{
    m_settingMgr->setCurrCam(m_settingMgr->getCurrCam());
    
    if(m_settingMgr->getCurrApp() == VAPP_CAMCO_APP_CAMERA)
        mdi_camera_query_support_info(MDI_CAMERA_SETTING_AFMODE, cap_info);
    else
        mdi_video_rec_query_support_info(MDI_VIDEO_SETTING_AFMODE, cap_info);   

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
            case MDI_CAMERA_AF_OPERATION_MODE_OFF:
                cap_info->support_item[idx] = VAPP_CAMCO_AFMODE_OFF;
                break;
        
            case MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE:
                cap_info->support_item[idx] = VAPP_CAMCO_AFMODE_SINGLE;
                break;
        
            case MDI_CAMERA_AF_OPERATION_MODE_CONTINUOUS:
                cap_info->support_item[idx] = VAPP_CAMCO_AFMODE_CONT;
                break;

            default:
                cap_info->support_item[idx] = VAPP_CAMCO_SETTING_DUMMY_VALUE;
                break;


        }
    }

    return MMI_TRUE;

}

VfxU32 AFmodeSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_AFMODE_OFF:
            return MDI_CAMERA_AF_OPERATION_MODE_OFF;
    
        case VAPP_CAMCO_AFMODE_SINGLE:
            return MDI_CAMERA_AF_OPERATION_MODE_SINGLE_ZONE;
    
        case VAPP_CAMCO_AFMODE_CONT:
            return MDI_CAMERA_AF_OPERATION_MODE_CONTINUOUS;
    }
    return CamcoSettingItem::getMappingID(mmiID);    
}


void RecAudSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_RECAUD;                
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_REC_AUD_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_RECAUD;

    /* init item str id */
    m_content[VAPP_CAMCO_RECAUD_OFF]->setStr(STR_GLOBAL_OFF);
    m_content[VAPP_CAMCO_RECAUD_ON]->setStr(STR_ID_VAPP_CAMCO_RECAUD_ON);
        
};


void RecAudSetting :: setDefault(void)
{

#ifdef MJPG_ENCODE
    m_cap = DISABLE(VAPP_CAMCO_SETTING_STATUS_DISABLED_RECAUD);
#else 
    m_cap = ENABLE();
#endif 
    m_content[VAPP_CAMCO_RECAUD_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_RECAUD_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);   

    m_content[VAPP_CAMCO_RECAUD_OFF]->setValue(VAPP_CAMCO_RECAUD_OFF); 
    m_content[VAPP_CAMCO_RECAUD_ON]->setValue(VAPP_CAMCO_RECAUD_ON); 
    
    CheckandSet(VAPP_CAMCO_RECAUD_ON);        
};


void RecAudSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value); 

    if(change_setting == VAPP_CAMCO_SETTING_TIMELAPSE)
    {
        if(change_value == VAPP_CAMCO_TIME_LAPSE_ON)
        {
            setValue(VAPP_CAMCO_RECAUD_OFF);

            hide(VAPP_CAMCO_SETTING_TIMELAPSE);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_TIMELAPSE);
        }
    }
};

void RecAudSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();

};

VfxU32 RecAudSetting::getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_RECAUD_OFF:
            return 0;

        case VAPP_CAMCO_RECAUD_ON:
            return 1;
    }
    return CamcoSettingItem::getMappingID(mmiID);
}

void VisCodecSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_VISCODEC;                
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_VIS_CODEC_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_VISCODEC;

    /* init item str id */
    m_content[VAPP_CAMCO_VISCODEC_MP4]->setStr(STR_ID_VAPP_CAMCO_VISCODEC_MP4);
    m_content[VAPP_CAMCO_VISCODEC_3GP]->setStr(STR_ID_VAPP_CAMCO_VISCODEC_3GP);        
    m_content[VAPP_CAMCO_VISCODEC_MJPG]->setStr(STR_ID_VAPP_CAMCO_VISCODEC_MJPG);     
    m_content[VAPP_CAMCO_VISCODEC_H264]->setStr(STR_ID_VAPP_CAMCO_VISCODEC_H264);         
};


void VisCodecSetting :: setDefault(void)
{
    m_cap = ENABLE();

    mdi_video_rec_spec_struct spec_entry_struct;
    VfxU32 count = mdi_video_rec_query_entry_num_of_video_spec_table();
    for(VfxU32 i=0; i < count; i++)
    {
        VfxU32 currectCodec = VAPP_CAMCO_VISCODEC_MP4;
        MDI_RESULT  ret = mdi_video_rec_get_video_spec_by_index(i, &spec_entry_struct, sizeof(spec_entry_struct));
        
        if(ret != MDI_RES_VDOREC_SUCCEED)
            continue;
                    
        switch (spec_entry_struct.video_format)
        {
            case MDI_VIDEO_VIDEO_FORMAT_3GP:
                m_content[VAPP_CAMCO_VISCODEC_3GP]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);    
                currectCodec = VAPP_CAMCO_VISCODEC_3GP;
                break;
            case MDI_VIDEO_VIDEO_FORMAT_MP4:
                m_content[VAPP_CAMCO_VISCODEC_MP4]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);                
                currectCodec = VAPP_CAMCO_VISCODEC_MP4;                
                break;    
            case MDI_VIDEO_VIDEO_FORMAT_MJPEG:
                m_content[VAPP_CAMCO_VISCODEC_MJPG]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);                
                currectCodec = VAPP_CAMCO_VISCODEC_MJPG;                
                break;
            case MDI_VIDEO_VIDEO_FORMAT_H264:
                m_content[VAPP_CAMCO_VISCODEC_H264]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);                
                currectCodec = VAPP_CAMCO_VISCODEC_H264;                
                break;
        }
        if(recorder_config_has_dependency() && !m_settingMgr->IsExtSetting())
        {          
            switch (spec_entry_struct.video_size)
            {     
                case MDI_VIDEO_REC_RESOLUTION_176x208:
                case MDI_VIDEO_REC_RESOLUTION_240x320:
                case MDI_VIDEO_REC_RESOLUTION_240x400:
                case MDI_VIDEO_REC_RESOLUTION_320x480:
                case MDI_VIDEO_REC_RESOLUTION_480x800:
                    m_wallpaperCodecMDIEnum = currectCodec;                            
                    break;    
            }        
        }            
    }

    m_content[VAPP_CAMCO_VISCODEC_MP4]->setValue(VAPP_CAMCO_VISCODEC_MP4); 
    m_content[VAPP_CAMCO_VISCODEC_3GP]->setValue(VAPP_CAMCO_VISCODEC_3GP);     
    m_content[VAPP_CAMCO_VISCODEC_MJPG]->setValue(VAPP_CAMCO_VISCODEC_MJPG); 
    m_content[VAPP_CAMCO_VISCODEC_H264]->setValue(VAPP_CAMCO_VISCODEC_H264);     

    config_reccodec_capability(VAPP_CAMCO_SETTING_VISCODEC);

    if(m_settingMgr->IsExtSetting() && m_content[VAPP_CAMCO_VISCODEC_3GP]->getStatus() == VAPP_CAMCO_SETTING_CAP_ENABLED)
        CheckandSet(VAPP_CAMCO_VISCODEC_3GP);              
    else
        CheckandSet(-1);      
   
};



void VisCodecSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
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
};

void VisCodecSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK

    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();

};

VfxU32 VisCodecSetting :: getMappingID(VfxU32 mmiID)
{
    switch (mmiID)
    {
        case VAPP_CAMCO_VISCODEC_MP4:
            return MDI_VIDEO_VIDEO_FORMAT_MP4;
    
        case VAPP_CAMCO_VISCODEC_3GP:
            return MDI_VIDEO_VIDEO_FORMAT_3GP;

        case VAPP_CAMCO_VISCODEC_MJPG:
            return MDI_VIDEO_VIDEO_FORMAT_MJPEG;
            
        case VAPP_CAMCO_VISCODEC_H264:
            return MDI_VIDEO_VIDEO_FORMAT_H264;
    }
    return CamcoSettingItem::getMappingID(mmiID);    
}

void VisCodecSetting :: config_reccodec_capability(vapp_camco_setting_enum changed_setting)
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


void CamEVSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CAMEV;    

    m_mainImgId = IMG_ID_VAPP_CAMCO_SETTING_EV_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_EV;

    /* init item str id */
    m_content[VAPP_CAMCO_EV_P4]->setStr(STR_ID_VAPP_CAMCO_EVP4);
    m_content[VAPP_CAMCO_EV_P3]->setStr(STR_ID_VAPP_CAMCO_EVP3);
    m_content[VAPP_CAMCO_EV_P2]->setStr(STR_ID_VAPP_CAMCO_EVP2);
    m_content[VAPP_CAMCO_EV_P1]->setStr(STR_ID_VAPP_CAMCO_EVP1);
    m_content[VAPP_CAMCO_EV_0]->setStr(STR_ID_VAPP_CAMCO_EVZ0);
    m_content[VAPP_CAMCO_EV_N1]->setStr(STR_ID_VAPP_CAMCO_EVN1);
    m_content[VAPP_CAMCO_EV_N2]->setStr(STR_ID_VAPP_CAMCO_EVN2);
    m_content[VAPP_CAMCO_EV_N3]->setStr(STR_ID_VAPP_CAMCO_EVN3);
    m_content[VAPP_CAMCO_EV_N4]->setStr(STR_ID_VAPP_CAMCO_EVN4);    

    m_content[VAPP_CAMCO_EV_P4]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_P4_ICON);
    m_content[VAPP_CAMCO_EV_P3]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_P3_ICON);
    m_content[VAPP_CAMCO_EV_P2]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_P2_ICON);
    m_content[VAPP_CAMCO_EV_P1]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_P1_ICON);
    m_content[VAPP_CAMCO_EV_0]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_0_ICON);
    m_content[VAPP_CAMCO_EV_N1]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_N1_ICON);
    m_content[VAPP_CAMCO_EV_N2]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_N2_ICON);
    m_content[VAPP_CAMCO_EV_N3]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_N3_ICON);
    m_content[VAPP_CAMCO_EV_N4]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_N4_ICON);  

    m_content[VAPP_CAMCO_EV_P4]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_P4_ICON);
    m_content[VAPP_CAMCO_EV_P3]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_P3_ICON);
    m_content[VAPP_CAMCO_EV_P2]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_P2_ICON);
    m_content[VAPP_CAMCO_EV_P1]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_P1_ICON);
    m_content[VAPP_CAMCO_EV_0]->setStatusIcon(0);
    m_content[VAPP_CAMCO_EV_N1]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_N1_ICON);
    m_content[VAPP_CAMCO_EV_N2]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_N2_ICON);
    m_content[VAPP_CAMCO_EV_N3]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_N3_ICON);
    m_content[VAPP_CAMCO_EV_N4]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_N4_ICON);  

};


void CamEVSetting :: setDefault(void)
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

};


void CamEVSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
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
    else if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        if(change_value == VAPP_CAMCO_CAPMODE_ASD_SHOT)
        {     
            setValue(VAPP_CAMCO_EV_0);
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        }  
        else
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);        
        }
    }
};

void CamEVSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    if(v > m_maxValue)
        v = m_maxValue;
    if(v < m_minValue)
        v = m_minValue;    

    CamcoSettingItem::setValue(v);
    mdi_camera_update_para_ev(getMappingID(v));

};

MMI_BOOL CamEVSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
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

VfxU32 CamEVSetting :: getMappingID(VfxU32 mmiID)
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


void CamEVSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    mdi_camera_update_para_ev(getMappingID(v));

}

void CamEVSetting :: resetEffect(void)
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

void VdoEVSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_VDOEV;  

    m_mainImgId = IMG_ID_VAPP_CAMCO_SETTING_EV_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_EV;

    /* init item str id */
    m_content[VAPP_CAMCO_EV_P4]->setStr(STR_ID_VAPP_CAMCO_EVP4);
    m_content[VAPP_CAMCO_EV_P3]->setStr(STR_ID_VAPP_CAMCO_EVP3);
    m_content[VAPP_CAMCO_EV_P2]->setStr(STR_ID_VAPP_CAMCO_EVP2);
    m_content[VAPP_CAMCO_EV_P1]->setStr(STR_ID_VAPP_CAMCO_EVP1);
    m_content[VAPP_CAMCO_EV_0]->setStr(STR_ID_VAPP_CAMCO_EVZ0);
    m_content[VAPP_CAMCO_EV_N1]->setStr(STR_ID_VAPP_CAMCO_EVN1);
    m_content[VAPP_CAMCO_EV_N2]->setStr(STR_ID_VAPP_CAMCO_EVN2);
    m_content[VAPP_CAMCO_EV_N3]->setStr(STR_ID_VAPP_CAMCO_EVN3);
    m_content[VAPP_CAMCO_EV_N4]->setStr(STR_ID_VAPP_CAMCO_EVN4);   

    m_content[VAPP_CAMCO_EV_P4]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_P4_ICON);
    m_content[VAPP_CAMCO_EV_P3]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_P3_ICON);
    m_content[VAPP_CAMCO_EV_P2]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_P2_ICON);
    m_content[VAPP_CAMCO_EV_P1]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_P1_ICON);
    m_content[VAPP_CAMCO_EV_0]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_0_ICON);
    m_content[VAPP_CAMCO_EV_N1]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_N1_ICON);
    m_content[VAPP_CAMCO_EV_N2]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_N2_ICON);
    m_content[VAPP_CAMCO_EV_N3]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_N3_ICON);
    m_content[VAPP_CAMCO_EV_N4]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_EV_N4_ICON);  

    m_content[VAPP_CAMCO_EV_P4]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_P4_ICON);
    m_content[VAPP_CAMCO_EV_P3]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_P3_ICON);
    m_content[VAPP_CAMCO_EV_P2]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_P2_ICON);
    m_content[VAPP_CAMCO_EV_P1]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_P1_ICON);
    m_content[VAPP_CAMCO_EV_0]->setStatusIcon(0);
    m_content[VAPP_CAMCO_EV_N1]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_N1_ICON);
    m_content[VAPP_CAMCO_EV_N2]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_N2_ICON);
    m_content[VAPP_CAMCO_EV_N3]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_N3_ICON);
    m_content[VAPP_CAMCO_EV_N4]->setStatusIcon(IMG_ID_VAPP_CAMCO_STATUS_EV_N4_ICON);          
};


void VdoEVSetting :: setDefault(void)
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
};


void VdoEVSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
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

};

void VdoEVSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    if(v > m_maxValue)
        v = m_maxValue;
    if(v < m_minValue)
        v = m_minValue;    

    CamcoSettingItem::setValue(v);
    mdi_video_rec_update_para_ev(getMappingID(v));

};

MMI_BOOL VdoEVSetting :: queryCapbilityInfo(vapp_camco_cap_info *cap_info)
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

VfxU32 VdoEVSetting :: getMappingID(VfxU32 mmiID)
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

void VdoEVSetting :: applyEffect(VfxU16 v)
{
    m_isHiliteMode = VFX_TRUE;

    mdi_video_rec_update_para_ev(getMappingID(v));

}

void VdoEVSetting :: resetEffect(void)
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


void CamZoomSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_CAMZOOM;        
};


void CamZoomSetting :: setDefault(void)
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

};
void CamZoomSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_CAPSIZE)
    {
        setDefault();
    }

};
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

};

void CamZoomSetting :: setFactor(VfxU16 v)
{
    m_currentFactor = v;
}


void VdoZoomSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_VDOZOOM;    
};


void VdoZoomSetting :: setDefault(void)
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
};
void VdoZoomSetting :: onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_RECSIZE)
    {
        setDefault();
    }

};
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

};

void VdoZoomSetting :: setFactor(VfxU16 v)
{
    m_currentFactor = v;
}



void RestoredefaultSetting :: initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_RESTOREDEFAULT;        
    
    /* init main str/img id */
    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_RESTORE_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_DEFAULT;

    /* init item str id */
    m_content[VAPP_CAMCO_RESTOREDEFAULT_OPTION]->setStr(STR_GLOBAL_RESET);
       
};


void RestoredefaultSetting :: setDefault(void)
{
    m_cap = ENABLE();
    m_content[VAPP_CAMCO_RESTOREDEFAULT_OPTION]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);

    m_content[VAPP_CAMCO_RESTOREDEFAULT_OPTION]->setValue(VAPP_CAMCO_RESTOREDEFAULT_OPTION); 

    CheckandSet(VAPP_CAMCO_RESTOREDEFAULT_OPTION);         

};

void RestoredefaultSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 

    CamcoSettingItem::setValue(v);
             
};

void AddFrameFrameSetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_ADDFRAME_FRAME;        

    m_mainImgId = IMG_ID_VAPP_CAMCO_SETTING_FRAME_SELECT_ICON;
    m_mainStrId = 0;

    /* init item str id */
    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStr(STR_GLOBAL_1);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME1]->setStr(STR_GLOBAL_2);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME2]->setStr(STR_GLOBAL_3);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME3]->setStr(STR_GLOBAL_4);    
    m_content[VAPP_CAMCO_ADDFRAME_FRAME4]->setStr(STR_GLOBAL_5);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME5]->setStr(STR_GLOBAL_6);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME6]->setStr(STR_GLOBAL_7);    
    m_content[VAPP_CAMCO_ADDFRAME_FRAME7]->setStr(STR_GLOBAL_8);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME8]->setStr(STR_GLOBAL_9);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME9]->setStr(STR_GLOBAL_10);        

    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_ADDFRAME_FRAME1_ICON);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME1]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_ADDFRAME_FRAME2_ICON);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME2]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_ADDFRAME_FRAME3_ICON);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME3]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_ADDFRAME_FRAME4_ICON);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME4]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_ADDFRAME_FRAME5_ICON);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME5]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_ADDFRAME_FRAME6_ICON);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME6]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_ADDFRAME_FRAME7_ICON);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME7]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_ADDFRAME_FRAME8_ICON);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME8]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_ADDFRAME_FRAME9_ICON);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME9]->setImg(IMG_ID_VAPP_CAMCO_WHEEL_ADDFRAME_FRAME10_ICON);

#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX_1__        
    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatusIcon(IMG_ID_VAPP_CAMCO_ADD_FRAME_COLOR_IDX_1);
#else
    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatusIcon(0);
#endif
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX_2__     
    m_content[VAPP_CAMCO_ADDFRAME_FRAME1]->setStatusIcon(IMG_ID_VAPP_CAMCO_ADD_FRAME_COLOR_IDX_2);
#else
    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatusIcon(0);
#endif
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX_3__
    m_content[VAPP_CAMCO_ADDFRAME_FRAME2]->setStatusIcon(IMG_ID_VAPP_CAMCO_ADD_FRAME_COLOR_IDX_3);
#else
    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatusIcon(0);
#endif
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX_4__
    m_content[VAPP_CAMCO_ADDFRAME_FRAME3]->setStatusIcon(IMG_ID_VAPP_CAMCO_ADD_FRAME_COLOR_IDX_4);
#else
    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatusIcon(0);
#endif   
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX_5__
    m_content[VAPP_CAMCO_ADDFRAME_FRAME4]->setStatusIcon(IMG_ID_VAPP_CAMCO_ADD_FRAME_COLOR_IDX_5);
#else
    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatusIcon(0);
#endif
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX_6__
    m_content[VAPP_CAMCO_ADDFRAME_FRAME5]->setStatusIcon(IMG_ID_VAPP_CAMCO_ADD_FRAME_COLOR_IDX_6);
#else
    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatusIcon(0);
#endif
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX_7__
    m_content[VAPP_CAMCO_ADDFRAME_FRAME6]->setStatusIcon(IMG_ID_VAPP_CAMCO_ADD_FRAME_COLOR_IDX_7);  
#else
    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatusIcon(0);
#endif  
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX_8__
    m_content[VAPP_CAMCO_ADDFRAME_FRAME7]->setStatusIcon(IMG_ID_VAPP_CAMCO_ADD_FRAME_COLOR_IDX_8);
#else
    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatusIcon(0);
#endif
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX_9__
    m_content[VAPP_CAMCO_ADDFRAME_FRAME8]->setStatusIcon(IMG_ID_VAPP_CAMCO_ADD_FRAME_COLOR_IDX_9);
#else
    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatusIcon(0);
#endif    
#ifdef __MMI_CAMCO_FEATURE_ADD_FRAME_COLOR_IDX_10__
    m_content[VAPP_CAMCO_ADDFRAME_FRAME9]->setStatusIcon(IMG_ID_VAPP_CAMCO_ADD_FRAME_COLOR_IDX_10);    
#else
        m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatusIcon(0);
#endif

    
};    

void AddFrameFrameSetting::setDefault(void)
{
    m_cap = ENABLE();

    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME1]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME2]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME3]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME4]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME5]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME6]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME7]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME8]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME9]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);

    m_content[VAPP_CAMCO_ADDFRAME_FRAME0]->setValue(VAPP_CAMCO_ADDFRAME_FRAME0);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME1]->setValue(VAPP_CAMCO_ADDFRAME_FRAME1);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME2]->setValue(VAPP_CAMCO_ADDFRAME_FRAME2);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME3]->setValue(VAPP_CAMCO_ADDFRAME_FRAME3);    
    m_content[VAPP_CAMCO_ADDFRAME_FRAME4]->setValue(VAPP_CAMCO_ADDFRAME_FRAME4);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME5]->setValue(VAPP_CAMCO_ADDFRAME_FRAME5);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME6]->setValue(VAPP_CAMCO_ADDFRAME_FRAME6);    
    m_content[VAPP_CAMCO_ADDFRAME_FRAME7]->setValue(VAPP_CAMCO_ADDFRAME_FRAME7);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME8]->setValue(VAPP_CAMCO_ADDFRAME_FRAME8);
    m_content[VAPP_CAMCO_ADDFRAME_FRAME9]->setValue(VAPP_CAMCO_ADDFRAME_FRAME9);    
    
    CheckandSet(VAPP_CAMCO_ADDFRAME_FRAME0);      
};    

void AddFrameFrameSetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    CamcoSettingItem::setValue(v);
    m_settingMgr->needRestartPreview();
};  

void AuxiliarySetting::initialize(void)
{
    CamcoSettingItem::initialize();
    m_settingType = VAPP_CAMCO_SETTING_AUXILIARY;  

    m_mainImgId = IMG_ID_VAPP_CAMCO_WHEEL_AD_AUXILIARY_ICON;
    m_mainStrId = STR_ID_VAPP_CAMCO_AUXILIARY;

    /* init item str id */
    m_content[VAPP_CAMCO_AUXILIRY_ON]->setStr(STR_GLOBAL_ON);
    m_content[VAPP_CAMCO_AUXILIRY_OFF]->setStr(STR_GLOBAL_OFF);


    
};    

void AuxiliarySetting::setDefault(void)
{

    m_cap = ENABLE();
    
    m_content[VAPP_CAMCO_AUXILIRY_ON]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);
    m_content[VAPP_CAMCO_AUXILIRY_OFF]->setStatus(VAPP_CAMCO_SETTING_CAP_ENABLED);

    m_content[VAPP_CAMCO_AUXILIRY_ON]->setValue(VAPP_CAMCO_AUXILIRY_ON);
    m_content[VAPP_CAMCO_AUXILIRY_OFF]->setValue(VAPP_CAMCO_AUXILIRY_OFF);
    
    CheckandSet(VAPP_CAMCO_AUXILIRY_OFF);     
};    

void AuxiliarySetting::setValue(VfxU16 v)
{
    VAPP_CAMCO_SETTING_CHECK
 
    CamcoSettingItem::setValue(v);

};    

void AuxiliarySetting::onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value)
{
    VAPP_CAMCO_SETTING_CHECK
    CamcoSettingItem::onSettingUpdate(change_setting, change_value, last_value);
    
    if(change_setting == VAPP_CAMCO_SETTING_CAPMODE)
    {
        if(change_value == VAPP_CAMCO_CAPMODE_ADD_FRAME)
        {
            if(m_currentValue == VAPP_CAMCO_AUXILIRY_ON)
                setValue(VAPP_CAMCO_AUXILIRY_OFF);
            hide(VAPP_CAMCO_SETTING_CAPMODE);
        }
        else
        {
            show(VAPP_CAMCO_SETTING_CAPMODE);
        }
    }

}

#endif
