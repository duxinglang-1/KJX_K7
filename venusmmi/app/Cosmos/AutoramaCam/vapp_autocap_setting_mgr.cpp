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
#include "vapp_autocap_setting_mgr.h"

#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))

#include "Mmi_rp_vapp_autocap_common_def.h"

VfxU32 g_vapp_autocap_storage_setting = 0xFF;

void AutoCapSettingMgr::getSeetingLog(vapp_autocap_setting_enum s, VfxU32 v)
{
    switch (s)
    {
        case VAPP_AUTOCAP_SETTING_CAPMODE:    
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_CAPMODE, v);   
            break;
        case VAPP_AUTOCAP_SETTING_CAMSCENEMODE:                 
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_CAMSCENEMODE, v);   
            break;
        case VAPP_AUTOCAP_SETTING_CAPSIZE:                
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_CAPSIZE, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_HIGHLIGHT:                
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_HIGHLIGHT, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_AFRANGE:                
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_AFRANGE, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_ISO:                
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_ISO, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_WB:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_WB, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_EFFECT:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_EFFECT, v);         
            break;            
        case VAPP_AUTOCAP_SETTING_CAMSTORAGE:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_CAMSTORAGE, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_CAPQTY:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_CAPQTY, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_AFZONE:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_AFZONE, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_AEMETER:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_AEMETER, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_SHARPNESS:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_SHARPNESS, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_CONTRAST:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_CONTRAST, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_SATURATION:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_SATURATION, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_SHUTTERSOUND:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_SHUTTERSOUND, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_BANDING:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_BANDING, v);         
            break;            
        case VAPP_AUTOCAP_SETTING_CAMEV:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_CAMEV, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_CAMZOOM:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_CAMZOOM, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_RESTOREDEFAULT:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_RESTOREDEFAULT, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_ACT_CAM:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_ACT_CAM, v);     
            break;            
        case VAPP_AUTOCAP_SETTING_PANORAMA_DIRECTION:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE_PANORAMA_DIRECTION, v);      
            break;            
        default:
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_GET_VALUE, s, v);
            break;
    }
}

void AutoCapSettingMgr::setSeetingLog(vapp_autocap_setting_enum s, VfxU32 v)
{
    switch (s)
    {
        case VAPP_AUTOCAP_SETTING_CAPMODE:    
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_CAPMODE, v);   
            break;
        case VAPP_AUTOCAP_SETTING_CAMSCENEMODE:                 
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_CAMSCENEMODE, v);   
            break;
        case VAPP_AUTOCAP_SETTING_CAPSIZE:                
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_CAPSIZE, v);   
            break;              
        case VAPP_AUTOCAP_SETTING_HIGHLIGHT:                
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_HIGHLIGHT, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_AFRANGE:                
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_AFRANGE, v);   
            break;             
        case VAPP_AUTOCAP_SETTING_ISO:                
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_ISO, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_WB:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_WB, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_EFFECT:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_EFFECT, v);         
            break;            
        case VAPP_AUTOCAP_SETTING_CAMSTORAGE:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_CAMSTORAGE, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_CAPQTY:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_CAPQTY, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_AFZONE:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_AFZONE, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_AEMETER:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_AEMETER, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_SHARPNESS:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_SHARPNESS, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_CONTRAST:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_CONTRAST, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_SATURATION:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_SATURATION, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_SHUTTERSOUND:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_SHUTTERSOUND, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_BANDING:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_BANDING, v);         
            break;                   
        case VAPP_AUTOCAP_SETTING_CAMEV:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_CAMEV, v);   
            break;        
        case VAPP_AUTOCAP_SETTING_CAMZOOM:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_CAMZOOM, v);   
            break;              
        case VAPP_AUTOCAP_SETTING_RESTOREDEFAULT:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_RESTOREDEFAULT, v);   
            break;            
        case VAPP_AUTOCAP_SETTING_ACT_CAM:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_ACT_CAM, v);     
            break;          
        case VAPP_AUTOCAP_SETTING_PANORAMA_DIRECTION:              
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_PANORAMA_DIRECTION, v);      
            break;             
        default:
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE, s, v);
    }

}

void AutoCapSettingMgr::onInit(void)
{
    VfxObject :: onInit();
    
    m_ListCreated = VFX_FALSE;
    m_mainCount = 0;
    m_ActiveSetting = NULL;
    for(VfxU16 i = 0; i < VAPP_AUTOCAP_SETTING_END; i++)
    {
        m_mainList[i] = NULL;   
    }
    m_itemCount = 0;
    for(VfxU16 i = 0; i < VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT; i++)
    {
        m_itemList[i] = NULL;        
    }

    VFX_OBJ_CREATE(m_CapMode, AutoCapCapModeSetting , this);   
    VFX_OBJ_CREATE(m_CamSCN, AutoCapCamSceneModeSetting ,this);  
    VFX_OBJ_CREATE(m_CapSize, AutoCapCapSizeSetting ,this);   
    VFX_OBJ_CREATE(m_Hilite, AutoCapHighlightSetting ,this);   
    VFX_OBJ_CREATE(m_AFrange, AutoCapAFRangeSetting ,this);   
    VFX_OBJ_CREATE(m_ISO, AutoCapISOSetting ,this);   
    VFX_OBJ_CREATE(m_WB, AutoCapWBSetting ,this);   
    VFX_OBJ_CREATE(m_Effect, AutoCapEffectSetting ,this);   
    VFX_OBJ_CREATE(m_CamStorage, AutoCapStorageSetting ,this);   
    VFX_OBJ_CREATE(m_CapQty, AutoCapCapqtySetting ,this);   
    VFX_OBJ_CREATE(m_AFzone, AutoCapAFZoneSetting ,this);   
    VFX_OBJ_CREATE(m_AEmeter, AutoCapAEmeterSetting ,this);   
    VFX_OBJ_CREATE(m_Sharpness, AutoCapSharpnessSetting ,this);   
    VFX_OBJ_CREATE(m_Contrast, AutoCapContrastSetting ,this);   
    VFX_OBJ_CREATE(m_Saturation, AutoCapSaturationSetting ,this);   
    VFX_OBJ_CREATE(m_CapSound, AutoCapShuttersoundSetting ,this);   
    VFX_OBJ_CREATE(m_Banding, AutoCapBandingSetting ,this);   
    VFX_OBJ_CREATE(m_CapEV, AutoCapCamEVSetting ,this);   
    VFX_OBJ_CREATE(m_CapZoom, AutoCapCamZoomSetting ,this);   
    VFX_OBJ_CREATE(m_Restore, AutoCapRestoredefaultSetting ,this);      
    VFX_OBJ_CREATE(m_CamearaSensor, AutoCapCameraSensorSetting ,this);    
    VFX_OBJ_CREATE(m_panoDirection, AutoCapPanoramaDirectionSetting ,this);    

    m_allSettingList[0] = m_CapMode;
    m_allSettingList[1] = m_CamSCN;    
    m_allSettingList[2] = m_CapSize;
    m_allSettingList[3] = m_Hilite;
    m_allSettingList[4] = m_AFrange;
    m_allSettingList[5] = m_ISO;
    m_allSettingList[6] = m_WB;
    m_allSettingList[7] = m_Effect;
    m_allSettingList[8] = m_CamStorage;
    m_allSettingList[9] = m_CapQty;
    m_allSettingList[10] = m_AFzone;
    m_allSettingList[11] = m_AEmeter;
    m_allSettingList[12] = m_Sharpness;
    m_allSettingList[13] = m_Contrast;
    m_allSettingList[14] = m_Saturation;
    m_allSettingList[15] = m_CapSound;
    m_allSettingList[16] = m_Banding;
    m_allSettingList[17] = m_CapEV;
    m_allSettingList[18] = m_CapZoom;
    m_allSettingList[19] = m_Restore;
    m_allSettingList[20] = m_CamearaSensor;   
    m_allSettingList[21] = m_panoDirection;       
    
    m_allSettingCount = 22;

    m_CamearaSensor->setMgr(this);  
    for(VfxU32 i = 0; i < m_allSettingCount; i++)
    {
        m_allSettingList[i]->setMgr(this);
    }
    
    m_CamearaSensor->initialize();    
    for(VfxU32 i = 0; i < m_allSettingCount; i++)
    {
        m_allSettingList[i]->initialize();
    }    
    m_CamStorage->setType(VAPP_AUTOCAP_SETTING_CAMSTORAGE);

    m_isReadNvramData = VFX_TRUE;
    loadSetting();
    loadSceneSetting();
    m_isReadNvramData = VFX_FALSE;

    m_CamearaSensor->setDefault(); 
    for(VfxU32 i = 0; i < m_allSettingCount; i++)
    {
        m_allSettingList[i]->setDefault();
    }    
    
    m_CamearaSensor->m_signalSettingModified.connect(m_CapMode, &AutoCapCapModeSetting::onSettingUpdate);    
    m_CamearaSensor->m_signalSettingModified.connect(m_CapSize, &AutoCapCapSizeSetting::onSettingUpdate);    
  
    m_CamSCN->m_signalSettingModified.connect(m_AFrange, &AutoCapAFRangeSetting::onSettingUpdate);
    m_CamSCN->m_signalSettingModified.connect(m_ISO, &AutoCapISOSetting::onSettingUpdate);
    m_CamSCN->m_signalSettingModified.connect(m_WB, &AutoCapWBSetting::onSettingUpdate);
    m_CamSCN->m_signalSettingModified.connect(m_Sharpness, &AutoCapSharpnessSetting::onSettingUpdate);
    m_CamSCN->m_signalSettingModified.connect(m_Contrast, &AutoCapContrastSetting::onSettingUpdate);
    m_CamSCN->m_signalSettingModified.connect(m_Saturation, &AutoCapSaturationSetting::onSettingUpdate);
    m_CamSCN->m_signalSettingModified.connect(m_CapSize, &AutoCapCapSizeSetting::onSettingUpdate);    
    m_CamSCN->m_signalSettingModified.connect(m_CapMode, &AutoCapCapModeSetting::onSettingUpdate);    

    m_CapSize->m_signalSettingModified.connect(m_CapZoom, &AutoCapCamZoomSetting::onSettingUpdate);    
    m_CapSize->m_signalSettingModified.connect(m_CapMode, &AutoCapCapModeSetting::onSettingUpdate);    

    m_CapMode->m_signalSettingModified.connect(m_CapSize, &AutoCapCapSizeSetting::onSettingUpdate);

    m_CapMode->m_signalSettingModified.connect(m_CamSCN, &AutoCapCamSceneModeSetting::onSettingUpdate);
    m_CapMode->m_signalSettingModified.connect(m_Effect, &AutoCapEffectSetting::onSettingUpdate);    
    m_CapMode->m_signalSettingModified.connect(m_AFrange, &AutoCapAFRangeSetting::onSettingUpdate);   
    m_CapMode->m_signalSettingModified.connect(m_AFzone, &AutoCapAFZoneSetting::onSettingUpdate);  

    m_Effect->m_signalSettingModified.connect(m_CamSCN, &AutoCapCamSceneModeSetting::onSettingUpdate);        
    m_Effect->m_signalSettingModified.connect(m_Sharpness, &AutoCapSharpnessSetting::onSettingUpdate);        
    m_Effect->m_signalSettingModified.connect(m_Contrast, &AutoCapContrastSetting::onSettingUpdate);      
    m_Effect->m_signalSettingModified.connect(m_Saturation, &AutoCapSaturationSetting::onSettingUpdate);          
    
    m_ISO->m_signalSettingModified.connect(m_CapSize, &AutoCapCapSizeSetting::onSettingUpdate);    

    // set value after call connection is done
    setValueAllSetting();

}

void AutoCapSettingMgr::setCallingMode(VfxBool isExtCalling, vapp_autocap_param_struct Param)
{
    memcpy(&m_callingParam, &Param, sizeof(vapp_autocap_param_struct));    
}

void AutoCapSettingMgr::getGurrentSetting(AutoCapSettingItem** setting_p)
{
    (*setting_p) = m_ActiveSetting;
}

VfxS32 AutoCapSettingMgr::getCurrentSettingIdx(void)
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

VfxS32 AutoCapSettingMgr::getSettingIdx(vapp_autocap_setting_enum type)
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


void AutoCapSettingMgr::getSetting(vapp_autocap_setting_enum type, AutoCapSettingItem** setting_p)
{
    // these two setting should get by getValue() directly, they won't in setting list
    ASSERT(type != VAPP_AUTOCAP_SETTING_ACT_CAM);
    
    
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

const AutoCapSettingItem* AutoCapSettingMgr::getSetting(vapp_autocap_setting_enum type)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i];
        }
    }
    return m_allSettingList[VAPP_AUTOCAP_SETTING_DUMMY];
}


MMI_ID_TYPE AutoCapSettingMgr::getSettingImg(vapp_autocap_setting_enum type)
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

MMI_ID_TYPE AutoCapSettingMgr::getSettingStatusImg(vapp_autocap_setting_enum type)
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

MMI_ID_TYPE AutoCapSettingMgr::getSettingStatusIcon(vapp_autocap_setting_enum type)
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

vapp_autocap_setting_enum AutoCapSettingMgr::getCurrentSetting(void)
{
    return m_ActiveSetting->getType();
}

VfxBool AutoCapSettingMgr::setCurrentSetting(void)
{
    m_ActiveSetting = m_mainList[0];
    m_ActiveSettingIdx = 0;
    CleanItemList();    
    genItemList();     
    return VFX_TRUE;    
}         

VfxBool AutoCapSettingMgr::setCurrentSetting(VfxU16 index)
{
    m_ActiveSetting = m_mainList[index];
    m_ActiveSettingIdx = index;    
    CleanItemList();    
    genItemList();         
    return VFX_TRUE;

}

VfxBool AutoCapSettingMgr::setCurrentSetting(vapp_autocap_setting_enum type)
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

VfxU16 AutoCapSettingMgr :: getValue(vapp_autocap_setting_enum type)
{
    
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            getSeetingLog(type, m_allSettingList[i]->getValue());        
            return m_allSettingList[i]->getValue();
        }
    }

    return SETTING_ITEM_NONE;

}


VfxBool AutoCapSettingMgr :: setValue(vapp_autocap_setting_enum type, VfxU16 value)
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
            return VFX_TRUE;
        }
    }    
    return VFX_FALSE;    
}


VfxBool AutoCapSettingMgr :: setValue(VfxU16 value)
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
    return VFX_TRUE;    
}

VfxBool AutoCapSettingMgr :: setValue(VfxU16 newHiliteIdx, VfxBool dummy)
{
    setSeetingLog(m_ActiveSetting->getType(), m_itemList[newHiliteIdx]->getValue());

    m_ActiveSetting->setValue(m_itemList[newHiliteIdx]->getValue());
    m_ActiveSetting->applyEffect(m_itemList[newHiliteIdx]->getValue());    
    m_ActiveSettingItemIdx = newHiliteIdx;
    return VFX_TRUE;    
}

vapp_autocap_setting_cap_enum AutoCapSettingMgr :: getStatus(vapp_autocap_setting_enum type)
{
      
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getStatus();
        }
    }

    return VAPP_AUTOCAP_SETTING_CAP_DISABLED;

}

VfxU32 AutoCapSettingMgr::getMappingID(vapp_autocap_setting_enum type)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_CAPMODE, type, m_allSettingList[i]->getMappingID(m_allSettingList[i]->getValue()));           
            return m_allSettingList[i]->getMappingID(m_allSettingList[i]->getValue());
        }
    }
    
    return 0;

}


VfxU32 AutoCapSettingMgr::getMappingID(vapp_autocap_setting_enum type, VfxU32 mmiID)
{

    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            MMI_TRACE(TRACE_GROUP_2, VAPP_AUTOCAP_SETTING_SET_VALUE_CAPMODE, type, m_allSettingList[i]->getMappingID(mmiID));                   
            return m_allSettingList[i]->getMappingID(mmiID);
        }
    }
    
    return 0;

}


void AutoCapSettingMgr :: setHilite(VfxU16 value)
{
    m_ActiveSetting->applyEffect(value);    
}

VfxU32 AutoCapSettingMgr::getMaxValue(void)
{
    return m_ActiveSetting->getMaxValue();
}

VfxU32 AutoCapSettingMgr::getMaxValue(vapp_autocap_setting_enum type)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getMaxValue();            
        }
    }
    return 0;
}

VfxU32 AutoCapSettingMgr::getMinValue(vapp_autocap_setting_enum type)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getMinValue();            
        }
    }
    return 0;
}  

VfxU32 AutoCapSettingMgr::getMinValue(void)
{
    return m_ActiveSetting->getMinValue();
}

VfxU32 AutoCapSettingMgr::getSettingCount(vapp_autocap_setting_enum type)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() == type)
        {
            return m_allSettingList[i]->getSettingCount();            
        }
    }
    return 0;
}

VfxBool AutoCapSettingMgr::moveNextSetting(void)
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

VfxBool AutoCapSettingMgr::movePrevSetting(void)
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

VfxBool AutoCapSettingMgr::moveNextSettingItem(void)
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

VfxBool AutoCapSettingMgr::movePrevSettingItem(void)
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


void AutoCapSettingMgr::getSettingList(vapp_autocap_setting_list_struct* List_p)
{
    List_p->settingCount = m_mainCount;
    for(VfxU16 i = 0; i < m_mainCount; i++)
    {
        List_p->settingStrId[i] = m_mainList[i]->getStr();
        List_p->settingImgId[i] = m_mainList[i]->getImg();        
        List_p->settingValue[i] = m_mainList[i]->getType();      
        if(m_mainList[i]->getType() == m_ActiveSetting->getType())
        {
            List_p->CurrentSettingIdx = i;
        }                
    }
    
    List_p->settingItemCount = m_itemCount;
    for(VfxU16 i = 0; i < m_itemCount; i++)
    {
        List_p->settingItemStrId[i] = m_itemList[i]->getStr();
        List_p->settingItemImgId[i] = m_itemList[i]->getImg();        
        List_p->settingItemValue[i] = m_itemList[i]->getValue();         
    }
    List_p->CurrentSettingValue = m_ActiveSetting->getValue();
    List_p->CurrentSettingValueIdx = m_ActiveSettingItemIdx;

}

void AutoCapSettingMgr :: initAllSetting(void)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() != VAPP_AUTOCAP_SETTING_ACT_CAM)
        {    
            m_allSettingList[i]->initialize();   
        }
    }
}

void AutoCapSettingMgr :: setDefaultAllSetting(void)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() != VAPP_AUTOCAP_SETTING_ACT_CAM)
        {
            m_allSettingList[i]->setDefault();   
        }
    }

}

void AutoCapSettingMgr :: setValueAllSetting(void)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        if(m_allSettingList[i]->getType() != VAPP_AUTOCAP_SETTING_ACT_CAM)
        {
            m_allSettingList[i]->setValue(m_allSettingList[i]->getValue());   
        }
    }

}


void AutoCapSettingMgr :: resetEffect(void)
{
    for(VfxU16 i = 0; i < m_allSettingCount; i++)
    {
        m_allSettingList[i]->resetEffect();   
    }
}

void AutoCapSettingMgr :: restoreFactorySetting(void)
{
#if (PERSISTENT_SETTING_SAVING)
    mmi_frm_reset_record(NVRAM_RESET_CERTAIN, 0, NVRAM_EF_CAMCO_VAPP_MAIN_SETTING_LID, 1, NVRAM_EF_CAMCO_VAPP_MAIN_SETTING_TOTAL);
#ifdef DUAL_CAMERA_SUPPORT
    mmi_frm_reset_record(NVRAM_RESET_CERTAIN, 0, NVRAM_EF_CAMCO_VAPP_SUB_SETTING_LID, 1, NVRAM_EF_CAMCO_VAPP_SUB_SETTING_TOTAL);
#endif
#endif
    m_CapMode->resetValue(VAPP_AUTOCAP_CAPMODE_PANORAMA);
    m_panoDirection->resetValue(VAPP_AUTOCAP_PANORAMA_DIRECTION_RIGHT);
    m_CamSCN->resetValue(VAPP_AUTOCAP_CAMSCENEMODE_AUTO);     
    m_CapSize->resetValue(0xff);
    m_Hilite->resetValue(VAPP_AUTOCAP_HIGHLIGHT_OFF);
    m_AFrange->resetValue(0xff);
    m_ISO->resetValue(VAPP_AUTOCAP_ISO_AUTO);
    m_WB->resetValue(VAPP_AUTOCAP_WB_AUTO);
    m_Effect->resetValue(VAPP_AUTOCAP_EFFECT_NORMAL);
    m_CamStorage->resetValue(0xff);
    m_CapQty->resetValue(VAPP_AUTOCAP_CAPQTY_FINE);
    m_AFzone->resetValue(VAPP_AUTOCAP_AFZONE_SINGLE);
    m_AEmeter->resetValue(VAPP_AUTOCAP_AEMETER_AUTO);
    m_Sharpness->resetValue(0xff);
    m_Saturation->resetValue(0xff);    
    m_Contrast->resetValue(0xff);
    m_CapSound->resetValue(VAPP_AUTOCAP_SHUTTERSOUND_SOUND_1);
    m_Banding->resetValue(VAPP_AUTOCAP_BANDING_60HZ);
    m_CapEV->resetValue(VAPP_AUTOCAP_EV_0);
    m_CapZoom->resetValue(m_CapZoom->getValue());
    m_CapZoom->setValue(0);
    m_Restore->resetValue(VAPP_AUTOCAP_RESTOREDEFAULT_OPTION);    
    
    storeSetting();

    setDefaultAllSetting();
    setValueAllSetting();    

}

void AutoCapSettingMgr :: loadSetting(void)
{
    {
    #if (!PERSISTENT_SETTING_SAVING)

		m_CamearaSensor->resetValue(VAPP_AUTOCAP_SENSOR_MAIN_CAMERA);
        m_CapMode->resetValue(0xFF);
        m_CamSCN->resetValue(0xFF);
        m_CapSize->resetValue(0xFF);
        m_Hilite->resetValue(0xFF);
        m_AFrange->resetValue(0xFF);
        m_ISO->resetValue(0xFF);
        m_WB->resetValue(0xFF);
        m_Effect->resetValue(0xFF);
        m_CamStorage->resetValue(g_vapp_autocap_storage_setting);        
        m_CapQty->resetValue(0xFF);
        m_AFzone->resetValue(0xFF);
        m_AEmeter->resetValue(0xFF);
        m_Sharpness->resetValue(0xFF);
        m_Contrast->resetValue(0xFF);
        m_Saturation->resetValue(0xFF);
        m_CapSound->resetValue(0xFF);
        m_Banding->resetValue(0xFF);
        m_Restore->resetValue(0xFF);
        m_panoDirection->resetValue(0xFF);
    #else
        S16 error;
        nvram_ef_camco_vapp_setting_struct nvram_data;
        nvram_ef_camco_vapp_info_struct nvram_autocap_info;
        
        if(m_isReadNvramData)
        {
            m_CamearaSensor->resetValue(VAPP_AUTOCAP_SENSOR_MAIN_CAMERA);                
        }
        else
        {
            ReadRecord(
                NVRAM_EF_CAMCO_VAPP_INFO_LID,
                1,  /* first one is from 1 */
                (void*)&nvram_autocap_info,
                NVRAM_EF_CAMCO_VAPP_INFO_SIZE,
                &error);

            m_CamearaSensor->resetValue((VfxU16)nvram_autocap_info.active_cam);

            if (m_CamearaSensor->getValue() == 0xff)
            {
                m_CamearaSensor->resetValue(VAPP_AUTOCAP_SENSOR_MAIN_CAMERA);
            }

        }
        
        if (m_CamearaSensor->getValue() == VAPP_AUTOCAP_SENSOR_MAIN_CAMERA)
        {
            ReadRecord(
                NVRAM_EF_CAMCO_VAPP_MAIN_SETTING_LID,
                1,  /* first one is from 1 */
                (void*)&nvram_data,
                NVRAM_EF_CAMCO_VAPP_MAIN_SETTING_SIZE,
                &error);
        }
    #ifdef DUAL_CAMERA_SUPPORT
        else if (m_CamearaSensor->getValue() == VAPP_AUTOCAP_SENSOR_SUB_CAMERA)
        {
            ReadRecord(
                NVRAM_EF_CAMCO_VAPP_SUB_SETTING_LID,
                1,  /* first one is from 1 */
                (void*)&nvram_data,
                NVRAM_EF_CAMCO_VAPP_SUB_SETTING_SIZE,
                &error);
        }
    #endif /* DUAL_CAMERA_SUPPORT */ 
        else
        {
            MMI_ASSERT(0);
        }
        
        
        if(m_isReadNvramData)
            m_CapMode->resetValue(VAPP_AUTOCAP_CAPMODE_PANORAMA);
        else
            m_CapMode->resetValue((VfxU16)nvram_data.capmode);            
        m_CamSCN->resetValue((VfxU16)nvram_data.camscenemode);
        m_CapSize->resetValue((VfxU16)nvram_data.capsize);
        m_Hilite->resetValue((VfxU16)nvram_data.highlight);
        m_AFrange->resetValue((VfxU16)nvram_data.afrange);
        m_panoDirection->resetValue((VfxU16)nvram_data.panorama_direct);
        m_ISO->resetValue((VfxU16)nvram_data.iso);
        m_WB->resetValue((VfxU16)nvram_data.wb);
        m_Effect->resetValue((VfxU16)nvram_data.effect);
        m_CamStorage->resetValue((VfxU16)nvram_data.storage);
        m_CapQty->resetValue((VfxU16)nvram_data.capqty);
        m_AFzone->resetValue((VfxU16)nvram_data.afzone);
        m_AEmeter->resetValue((VfxU16)nvram_data.aemeter);
        m_Sharpness->resetValue((VfxU16)nvram_data.sharpness);
        m_Contrast->resetValue((VfxU16)nvram_data.contrast);
        m_Saturation->resetValue((VfxU16)nvram_data.saturation);
        m_CapSound->resetValue((VfxU16)nvram_data.shuttersound);
        m_Banding->resetValue((VfxU16)nvram_data.banding);
        m_Restore->resetValue((VfxU16)nvram_data.restoredefault);
        m_panoDirection->resetValue((VfxU16)nvram_data.panorama_direct);

        /* save to NVRAM */
        storeSetting();
    #endif
    }
}

void AutoCapSettingMgr :: storeSetting(void)
{

    g_vapp_autocap_storage_setting = m_CamStorage->getValue();

#if (PERSISTENT_SETTING_SAVING)

    S16 error;
    nvram_ef_camco_vapp_setting_struct nvram_data;
    nvram_ef_camco_vapp_info_struct nvram_autocap_info;

    nvram_autocap_info.active_app = VAPP_AUTOCAP_APP_CAMERA;
    nvram_autocap_info.active_cam = m_CamearaSensor->getValue();

    WriteRecord(
        NVRAM_EF_CAMCO_VAPP_INFO_LID,
        1,  /* first one is from 1 */
        (void*)&nvram_autocap_info,
        NVRAM_EF_CAMCO_VAPP_INFO_SIZE,
        &error);

    nvram_data.capmode = m_CapMode->getValue();
    nvram_data.camscenemode = m_CamSCN->getValue();
    nvram_data.capsize = m_CapSize->getValue();
    nvram_data.highlight = m_Hilite->getValue();
    nvram_data.afrange = m_AFrange->getValue();
    nvram_data.iso = m_ISO->getValue();
    nvram_data.wb = m_WB->getValue();
    nvram_data.effect = m_Effect->getValue();
    nvram_data.storage = m_CamStorage->getValue();
    nvram_data.capqty = m_CapQty->getValue();
    nvram_data.afzone = m_AFzone->getValue();
    nvram_data.aemeter = m_AEmeter->getValue();
    nvram_data.sharpness = m_Sharpness->getValue();
    nvram_data.contrast = m_Contrast->getValue();
    nvram_data.saturation = m_Saturation->getValue();
    nvram_data.shuttersound = m_CapSound->getValue();
    nvram_data.banding = m_Banding->getValue();
    nvram_data.restoredefault = m_Restore->getValue();
    nvram_data.panorama_direct = m_panoDirection->getValue();
    nvram_data.panorama_direct = m_panoDirection->getValue();
    nvram_data.last_active_app = VAPP_AUTOCAP_APP_CAMERA;

    if (getCurrCam()== VAPP_AUTOCAP_SENSOR_MAIN_CAMERA)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_VAPP_MAIN_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_VAPP_MAIN_SETTING_SIZE,
            &error);
    }
#ifdef DUAL_CAMERA_SUPPORT
    else if (getCurrCam() == VAPP_AUTOCAP_SENSOR_SUB_CAMERA)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_VAPP_SUB_SETTING_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_VAPP_SUB_SETTING_SIZE,
            &error);
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
    else
    {
        MMI_ASSERT(0);
    }
#endif
}   

void AutoCapSettingMgr :: loadSceneSetting(void)
{

    {
    #if (!PERSISTENT_SETTING_SAVING)

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = 0xFF;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = 0xFF;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = 0xFF;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = 0xFF;
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = 0xFF;

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = 0xFF;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = 0xFF;

        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = 0xFF;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = 0xFF;
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = 0xFF;

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = 0xFF;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = 0xFF;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = 0xFF;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = 0xFF;
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = 0xFF;

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = 0xFF;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = 0xFF;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = 0xFF;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = 0xFF;
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = 0xFF;

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = 0xFF;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = 0xFF;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = 0xFF;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = 0xFF;
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = 0xFF;

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = 0xFF;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = 0xFF;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = 0xFF;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = 0xFF;
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = 0xFF;
        
        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = 0xFF;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = 0xFF;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = 0xFF;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = 0xFF;
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = 0xFF;   
        
    #else
    
        S16 error;
        nvram_ef_camco_vapp_setting_scene_sel_struct nvram_data;

        if (getCurrCam() == VAPP_AUTOCAP_SENSOR_MAIN_CAMERA)
        {
            ReadRecord(
                NVRAM_EF_CAMCO_VAPP_MAIN_SETTING_SCENE_SEL_LID,
                1,  /* first one is from 1 */
                (void*)&nvram_data,
                NVRAM_EF_CAMCO_VAPP_MAIN_SETTING_SCENE_SEL_SIZE,
                &error);
        }
    #ifdef DUAL_CAMERA_SUPPORT
        else if (getCurrCam() == VAPP_AUTOCAP_SENSOR_SUB_CAMERA)
        {
            ReadRecord(
                NVRAM_EF_CAMCO_VAPP_SUB_SETTING_SCENE_SEL_LID,
                1,  /* first one is from 1 */
                (void*)&nvram_data,
                NVRAM_EF_CAMCO_VAPP_SUB_SETTING_SCENE_SEL_SIZE,
                &error);
        }
    #endif /* DUAL_CAMERA_SUPPORT */ 
        else
        {
            MMI_ASSERT(0);
        }

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = nvram_data.cam_auto.afrange;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = nvram_data.cam_auto.iso;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = nvram_data.cam_auto.sharpness;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = nvram_data.cam_auto.contrast;
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO] = nvram_data.cam_auto.saturation;

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = nvram_data.cam_portrait.afrange;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = nvram_data.cam_portrait.iso;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = nvram_data.cam_portrait.sharpness;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = nvram_data.cam_portrait.contrast;
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT] = nvram_data.cam_portrait.saturation;

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = nvram_data.cam_landscape.afrange;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = nvram_data.cam_landscape.iso;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = nvram_data.cam_landscape.sharpness;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = nvram_data.cam_landscape.contrast;
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE] = nvram_data.cam_landscape.saturation;

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = nvram_data.cam_sport.afrange;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = nvram_data.cam_sport.iso;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = nvram_data.cam_sport.sharpness;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = nvram_data.cam_sport.contrast;
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT] = nvram_data.cam_sport.saturation;

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = nvram_data.cam_night.afrange;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = nvram_data.cam_night.iso;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = nvram_data.cam_night.sharpness;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = nvram_data.cam_night.contrast; 
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT] = nvram_data.cam_night.saturation;

        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = nvram_data.cam_document.afrange;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = nvram_data.cam_document.iso;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = nvram_data.cam_document.sharpness;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = nvram_data.cam_document.contrast; 
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT] = nvram_data.cam_document.saturation;
        
        m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = nvram_data.cam_antishake.afrange;
        m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = nvram_data.cam_antishake.iso;
        m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = nvram_data.cam_antishake.sharpness;
        m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = nvram_data.cam_antishake.contrast;  
        m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE] = nvram_data.cam_antishake.saturation;    

    #endif
    }
}


void AutoCapSettingMgr :: storeSceneSetting(void)
{

#if (PERSISTENT_SETTING_SAVING)

    S16 error;
    nvram_ef_camco_vapp_setting_scene_sel_struct nvram_data;

    nvram_data.cam_auto.afrange = m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO];
    nvram_data.cam_auto.iso = m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO];
    nvram_data.cam_auto.sharpness = m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO];
    nvram_data.cam_auto.contrast = m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO];
    nvram_data.cam_auto.saturation= m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_AUTO];

    nvram_data.cam_portrait.afrange = m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT];
    nvram_data.cam_portrait.iso = m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT];
    nvram_data.cam_portrait.sharpness= m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT];
    nvram_data.cam_portrait.contrast= m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT];
    nvram_data.cam_portrait.saturation= m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_PORTRAIT];

    nvram_data.cam_landscape.afrange = m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE];
    nvram_data.cam_landscape.iso = m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE];
    nvram_data.cam_landscape.sharpness= m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE];
    nvram_data.cam_landscape.contrast= m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE];
    nvram_data.cam_landscape.saturation= m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_LANDSCAPE];
        
    nvram_data.cam_sport.afrange = m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT];
    nvram_data.cam_sport.iso = m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT];
    nvram_data.cam_sport.sharpness= m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT];
    nvram_data.cam_sport.contrast= m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT];
    nvram_data.cam_sport.saturation= m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_SPORT];

    nvram_data.cam_night.afrange = m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT];
    nvram_data.cam_night.iso = m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT];
    nvram_data.cam_night.sharpness= m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT];
    nvram_data.cam_night.contrast= m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT];
    nvram_data.cam_night.saturation= m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_NIGHT];

    nvram_data.cam_document.afrange = m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT];
    nvram_data.cam_document.iso = m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT];
    nvram_data.cam_document.sharpness= m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT];
    nvram_data.cam_document.contrast= m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT];
    nvram_data.cam_document.saturation= m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_DOCUMENT];

    nvram_data.cam_antishake.afrange = m_AFrange->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE];
    nvram_data.cam_antishake.iso = m_ISO->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE];
    nvram_data.cam_antishake.sharpness= m_Sharpness->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE];
    nvram_data.cam_antishake.contrast= m_Contrast->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE];
    nvram_data.cam_antishake.saturation= m_Saturation->m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_ANTI_SHAKE];
        
    if (getCurrCam() == VAPP_AUTOCAP_SENSOR_MAIN_CAMERA)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_VAPP_MAIN_SETTING_SCENE_SEL_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_VAPP_MAIN_SETTING_SCENE_SEL_SIZE,
            &error);
    }
#ifdef DUAL_CAMERA_SUPPORT
    else if (getCurrCam() == VAPP_AUTOCAP_SENSOR_SUB_CAMERA)
    {
        WriteRecord(
            NVRAM_EF_CAMCO_VAPP_SUB_SETTING_SCENE_SEL_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_data,
            NVRAM_EF_CAMCO_VAPP_SUB_SETTING_SCENE_SEL_SIZE,
            &error);
    }
#endif /* DUAL_CAMERA_SUPPORT */ 
    else
    {
        MMI_ASSERT(0);
    }
#endif
} 

void AutoCapSettingMgr :: genMainList(vapp_autocap_setting_mainlist_type_enum type)
{
    m_settingListType = type;

    switch (type)
    {
        case VAPP_AUTOCAP_SETTING_MAINLIST_STIRAGE_ONLY:    
        {
            CleanMainList();
            AddtoMainList((AutoCapSettingItem*)m_CamStorage);            
            
            m_ListCreated = VFX_TRUE;            
            setCurrentSetting(VAPP_AUTOCAP_SETTING_CAMSTORAGE);            
            break;                

        }                                
                        
    }

    
}

void AutoCapSettingMgr :: genItemList(void)
{
    AutoCapSettingItem* setting = m_ActiveSetting;

    for(VfxU16 i = 0; i < VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT; i++)
    {
        if(setting->getItem(i).getStatus() == VAPP_AUTOCAP_SETTING_CAP_ENABLED)
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

void AutoCapSettingMgr :: genItemList(vapp_autocap_setting_enum type){};  


void AutoCapSettingMgr :: CleanMainList(void)
{
    m_ListCreated = VFX_FALSE;
    m_mainCount = 0;
    m_ActiveSetting = NULL;
    for(VfxU16 i = 0; i < VAPP_AUTOCAP_SETTING_END; i++)
    {
        m_mainList[i] = NULL;;        
    }
    m_itemCount = 0;
    for(VfxU16 i = 0; i < VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT; i++)
    {
        m_itemList[i] = NULL;;        
    }
}

void AutoCapSettingMgr :: CleanItemList(void)
{
    m_itemCount = 0;
    for(VfxU16 i = 0; i < VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT; i++)
    {
        m_itemList[i] = NULL;;        
    }
}

VfxBool AutoCapSettingMgr :: AddtoMainList(AutoCapSettingItem* setting)
{
    if(setting->getStatus() == VAPP_AUTOCAP_SETTING_CAP_ENABLED)
    {
        m_mainList[m_mainCount] = setting;    
        m_mainCount++;
    }        

    return VFX_TRUE;

}

#endif
