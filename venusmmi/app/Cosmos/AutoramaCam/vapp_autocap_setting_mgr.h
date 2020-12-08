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

#ifndef __VAPP_AUTOCAP_SETTING_MGR__
#define __VAPP_AUTOCAP_SETTING_MGR__

#include "MMI_include.h"
#include "MMI_features.h"
#include "MMI_features_camcorder.h"

#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))

#ifdef __cplusplus
extern "C"
{
#endif
#include "RestoreGprot.h"
#include "Common_nvram_editor_data_item.h"
#include "Nvram_common_defs.h"
#ifdef __cplusplus
}
#endif
#include "custom_rec_config.h"
#include "vapp_autocap_setting_item.h"
#include "vapp_autocap_setting.h"
#include "vapp_autocap_gprot.h"

typedef struct 
{
    MMI_ID_TYPE                     settingImgId[VAPP_AUTOCAP_SETTING_END];  
    MMI_ID_TYPE                     settingStrId[VAPP_AUTOCAP_SETTING_END];      
    vapp_autocap_setting_enum         settingValue[VAPP_AUTOCAP_SETTING_END];          
    VfxU16                          settingCount;
    VfxU16                          CurrentSettingIdx;    
    
    MMI_ID_TYPE                     settingItemImgId[VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT];  
    MMI_ID_TYPE                     settingItemStrId[VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT];          
    VfxU16                          settingItemValue[VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT];         
    VfxU16                          settingItemCount;        
    VfxU16                          CurrentSettingValue;       
    VfxU16                          CurrentSettingValueIdx;           
    
}vapp_autocap_setting_list_struct;

class VappAutoCapApp;

class AutoCapSettingMgr : public VfxObject
{
#define PERSISTENT_SETTING_SAVING  (0)
public:
    
    virtual void onInit(void);

    void setCallingMode(VfxBool isExtCalling, vapp_autocap_param_struct Param);

    VfxU16 getValue(void)
    { 
        return m_ActiveSetting->getValue();
    };
    
    VfxU16 getValue(
        vapp_autocap_setting_enum type
    );

    VfxBool setValue(vapp_autocap_setting_enum type, VfxU16 value);
    
    VfxBool setValue(VfxU16 value);   

    VfxBool setValue(void);

    VfxBool setValue(VfxU16 newHiliteIdx, VfxBool dummy);    

    void setHilite(VfxU16 value);
    
    vapp_autocap_app_enum getCurrApp(void)
    { 
        return VAPP_AUTOCAP_APP_CAMERA;
    };    
    
    vapp_autocap_sensor_enum getCurrCam(void)
    { 
        return (vapp_autocap_sensor_enum)m_CamearaSensor->getValue();    
    };     

    void setCurrApp(vapp_autocap_app_enum v)
    { 
    };    
    
    void setCurrCam(vapp_autocap_sensor_enum v)
    { 
        
        m_CamearaSensor->setValue(v);    
        
    #if (PERSISTENT_SETTING_SAVING)
        nvram_ef_camco_vapp_info_struct nvram_autocap_info;
        S16 error;

        nvram_autocap_info.active_app = VAPP_AUTOCAP_APP_CAMERA;
        nvram_autocap_info.active_cam = m_CamearaSensor->getValue();

        WriteRecord(
            NVRAM_EF_CAMCO_VAPP_INFO_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_autocap_info,
            NVRAM_EF_CAMCO_VAPP_INFO_SIZE,
            &error);   
    #endif
    };

    void getStoragePath(WCHAR** storagePath)
    {
        m_CamStorage->getStoragePath(storagePath);           
    }

    U8 getStorage(void)
    {
        return m_CamStorage->getStorage();         
    }    

    
    VfxU32 getMappingID(vapp_autocap_setting_enum type);
    VfxU32 getMappingID(vapp_autocap_setting_enum type, VfxU32 mmiID);

    vapp_autocap_setting_cap_enum getStatus(vapp_autocap_setting_enum type);

    void genMainList(vapp_autocap_setting_mainlist_type_enum type);
            
    void genItemList(void);    
    void genItemList(vapp_autocap_setting_enum type);  

    vapp_autocap_setting_mainlist_type_enum getListType(void)
    {
        return m_settingListType;
    };      

    VfxU16 getMainListCount(void)
    {
        return m_mainCount;
    };      

    VfxU16 getItemListCount(void)
    {
        return m_itemCount;
    };      
    
    void getGurrentSetting(
        AutoCapSettingItem** setting_p
    );

    VfxS32 getCurrentSettingIdx(void);
    
    void getSetting(
        vapp_autocap_setting_enum type, 
        AutoCapSettingItem** setting_p
    );

    const AutoCapSettingItem* getSetting(
        vapp_autocap_setting_enum type 
    );        

    VfxS32 getSettingIdx(
        vapp_autocap_setting_enum type
    );    

    MMI_ID_TYPE getSettingImg(
        vapp_autocap_setting_enum type
    );    

    MMI_ID_TYPE getSettingStatusImg(vapp_autocap_setting_enum type);

    MMI_ID_TYPE getSettingStatusIcon(vapp_autocap_setting_enum type);

    vapp_autocap_setting_enum getCurrentSetting(void);

    VfxBool setCurrentSetting(void);

    VfxBool setCurrentSetting(VfxU16 index);

    VfxBool setCurrentSetting(vapp_autocap_setting_enum type);    

    VfxU32 getMaxValue(void);
    
    VfxU32 getMaxValue(vapp_autocap_setting_enum type);

    VfxU32 getMinValue(vapp_autocap_setting_enum type);   
    
    VfxU32 getMinValue(void);    

    VfxU32 getSettingCount(vapp_autocap_setting_enum type);    

    VfxBool moveNextSetting(void);

    VfxBool movePrevSetting(void);

    VfxBool moveNextSettingItem(void);

    VfxBool movePrevSettingItem(void);
    
    void getSettingList(vapp_autocap_setting_list_struct* List_p);
    
    VfxBool initialized(void){ return m_ListCreated;};    

    void initAllSetting(void);    
    void setDefaultAllSetting(void);    
    void setValueAllSetting(void);      

    void restoreFactorySetting(void);

    void resetEffect(void);    

    void loadSetting(void);  
    void storeSetting(void);    
    void loadSceneSetting(void);
    void storeSceneSetting(void);    
    
    void needRestartPreview(void){m_isRestartPreview = VFX_TRUE;};
    void resetRestartPreview(void){m_isRestartPreview = VFX_FALSE;};
    VfxBool isNeedRestartPreview(void){return m_isRestartPreview;};

    // custom config related
    vapp_autocap_setting_enum transTargetToMMI(recoorder_config_setting_target target);
    recoorder_config_setting_target transTargetFromMMI(vapp_autocap_setting_enum target);
    VfxU16 transValueToMMI(recoorder_config_setting_value value);
    recoorder_config_setting_value transValueFromMMI(VfxU16 value, vapp_autocap_setting_enum target);
    void customConfig(void);
    void customUpdate(vapp_autocap_setting_enum target, VfxU16 value);    

    vapp_autocap_param_struct                 m_callingParam;

private:

    void CleanMainList(void);
    void CleanItemList(void);    
    VfxBool AddtoMainList(AutoCapSettingItem* setting);

    void getSeetingLog(vapp_autocap_setting_enum s, VfxU32 v);
    void setSeetingLog(vapp_autocap_setting_enum s, VfxU32 v);    

    VfxBool                                 m_isRestartPreview;
    VfxBool                                 m_isReadNvramData;    

    AutoCapSettingItem                       *m_allSettingList[VAPP_AUTOCAP_SETTING_END];    
    VfxU16                                  m_allSettingCount;     

    /* setting List related */
    VfxBool                                 m_ListCreated; 
    
    vapp_autocap_setting_mainlist_type_enum   m_settingListType;
    AutoCapSettingItem                       *m_mainList[VAPP_AUTOCAP_SETTING_END];
    VfxU16                                  m_mainCount; 
    const AutoCapSettingUnit                 *m_itemList[VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT];
    VfxU16                                  m_itemCount;       
    AutoCapSettingItem                       *m_ActiveSetting;
    VfxU16                                  m_ActiveSettingIdx;              
    const AutoCapSettingUnit                 *m_ActiveSettingItem;
    VfxU16                                  m_ActiveSettingItemIdx;

    // custom config related
    vapp_autocap_setting_enum                 m_keySettingType;

    /* each setting */   
    AutoCapCapModeSetting                    *m_CapMode;
    AutoCapCamSceneModeSetting               *m_CamSCN;     
    AutoCapCapSizeSetting                    *m_CapSize;
    AutoCapHighlightSetting                  *m_Hilite;
    AutoCapAFRangeSetting                    *m_AFrange;
    AutoCapISOSetting                        *m_ISO;
    AutoCapWBSetting                         *m_WB;
    AutoCapEffectSetting                     *m_Effect;
    AutoCapStorageSetting                    *m_CamStorage;  
    AutoCapCapqtySetting                     *m_CapQty;
    AutoCapAFZoneSetting                     *m_AFzone;
    AutoCapAEmeterSetting                    *m_AEmeter;
    AutoCapSharpnessSetting                  *m_Sharpness;
    AutoCapContrastSetting                   *m_Contrast;
    AutoCapSaturationSetting                 *m_Saturation;
    AutoCapShuttersoundSetting               *m_CapSound;
    AutoCapBandingSetting                    *m_Banding;
    AutoCapCamEVSetting                      *m_CapEV;
    AutoCapCamZoomSetting                    *m_CapZoom;
    AutoCapRestoredefaultSetting             *m_Restore;
    AutoCapCameraSensorSetting               *m_CamearaSensor;
    AutoCapPanoramaDirectionSetting          *m_panoDirection;

};

#endif
#endif
