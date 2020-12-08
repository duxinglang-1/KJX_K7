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

#ifndef __VAPP_AUTOCAP_SETTING_ITEM__
#define __VAPP_AUTOCAP_SETTING_ITEM__
#include "MMI_include.h"
#include "MMI_features.h"
#include "MMI_features_camcorder.h"

#if defined(__MMI_CAMCORDER__) && (defined(__MMI_CAMCO_FEATURE_CAM_AUTORAMA_SHOT__) || defined(__MMI_CAMCO_FEATURE_CAM_MULTI_ANGLE_VIEW_SHOT__))
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

#include "vapp_autocap_setting.h"

#include "FileManagerDef.h"
#include "FileMgrGProt.h"
#include "FileMgrSrvGProt.h"
#include "FileMgr.h"
#include "FileManagerResDef.h"
#include "vapp_fmgr_table.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define SETTING_ITEM_NONE (500)
#define VAPP_AUTOCAP_SETTING_NA (65536)
#define IS_ENABLE(x) (x == VAPP_AUTOCAP_SETTING_STATUS_ENABLED)
#define IS_NOT_SUPPORT(x) (x == (1ll <<VAPP_AUTOCAP_SETTING_STATUS_DRV_NOT_SUPPORT))
#define IS_DISABLE(x, y) (x == (1ll <<y))
#define ENABLE() (VAPP_AUTOCAP_SETTING_STATUS_ENABLED)
#define NOT_SUPPORT() (1ll <<VAPP_AUTOCAP_SETTING_STATUS_DRV_NOT_SUPPORT)
#define DISABLE(y) (1ll <<y)

class AutoCapSettingMgr;

/***************************************************************************** 
 * Class
 *****************************************************************************/
 
// The class of setting unit
// One object mean the one item of setting
// it contains its status/image/string
class AutoCapSettingUnit : public VfxObject
{

// Method
public:
    // The function return the status of the setting unit
    // RETURN: status of the setting unit (ENABLE / DISABLE / NOT_SUPPORT) 
    vapp_autocap_setting_cap_enum getStatus(void) const
    {
        if(IS_ENABLE(m_cap))
            return VAPP_AUTOCAP_SETTING_CAP_ENABLED;
        else if(IS_NOT_SUPPORT(m_cap))
            return VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT;
        else
            return VAPP_AUTOCAP_SETTING_CAP_DISABLED;
    };

    // The function return the Image ID of the setting unit
    // RETURN: Image ID of the setting unit
    MMI_ID_TYPE  getImg(void) const
    {
        return m_img_id;
    };

    MMI_ID_TYPE  getStatusIcon(void) const
    {
        return m_statusIcon;
    };    

    // The function return the String ID of the setting unit
    // RETURN: Image ID of the setting unit    
    MMI_ID_TYPE getStr(void) const
    {
        return m_str_id;
    };
 
    // The function return the value of the setting unit
    // RETURN: value of the setting unit    
    VfxU16 getValue(void) const
    {
        return m_value;
    };

    // The function set the status of the setting unit (ENABLE / DISABLE / NOT_SUPPORT) 
    // RETURN: N/A       
    void setStatus(
        vapp_autocap_setting_enum setting,
        vapp_autocap_setting_cap_enum cap      // [IN] the new staus of setting unit
    )
    {
        if(cap == VAPP_AUTOCAP_SETTING_CAP_ENABLED)
        {
            if(!IS_NOT_SUPPORT(m_cap))
                m_cap &= ~(1ll << setting);            
        }            
        else if(cap == VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            m_cap = NOT_SUPPORT();
        }
        else if(cap == VAPP_AUTOCAP_SETTING_CAP_DISABLED)
        {
            if(!IS_NOT_SUPPORT(m_cap))
                m_cap |= (1ll << setting);            
        }

    };    

    void setStatus(
        vapp_autocap_setting_cap_enum cap          // [IN] the new staus of setting unit
    )
    {
        if(cap == VAPP_AUTOCAP_SETTING_CAP_ENABLED)
        {
            m_cap = VAPP_AUTOCAP_SETTING_STATUS_ENABLED;            
        }            
        else if(cap == VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            m_cap = NOT_SUPPORT();
        }
    };  
    

    // The function set the status of the Image ID of the setting unit
    // RETURN: N/A          
    void setImg(
        MMI_ID_TYPE i       // [IN] the image ID of setting unit
    )
    {
        m_img_id = i;
    };    
    
    void setStatusIcon(
        MMI_ID_TYPE i       // [IN] the image ID of setting unit
    )
    {
        m_statusIcon = i;
    };    

    // The function set the status of the string ID of the setting unit
    // RETURN: N/A           
    void setStr(
        MMI_ID_TYPE s       // [IN] the string ID of setting unit
    )
    {
        m_str_id = s;
    };        

    // The function set the status of the string ID of the setting unit
    // RETURN: N/A           
    void setValue(
        VfxU16 v            // [IN] the value of setting unit
    )
    {
        m_value = v;
    };        

    // The function init setting unit
    // RETURN: N/A       
    void initialize(void)
    {
        m_cap = NOT_SUPPORT(); 
        m_img_id = 0;
        m_statusIcon = 0;
        m_str_id = 0;
        m_value = 0;
    };  

// Variables    
private:
    
    VfxU64                          m_cap;          // the status of the setting unit (ENABLE / DISABLE / NOT_SUPPORT)  
    MMI_ID_TYPE                     m_img_id;       // the Image ID of the setting unit
    MMI_ID_TYPE                     m_statusIcon;   // the Image ID of the setting unit    
    MMI_ID_TYPE                     m_str_id;       // the string ID of the setting unit
    VfxU16                          m_value;   
};

class AutoCapSettingItem : public VfxObject
{

// Method
public:
    virtual void onInit()
    {
        VfxObject:: onInit();
        
        for(VfxU32 i = 0; i < VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT; i++)
        {
            VFX_OBJ_CREATE(m_content[i], AutoCapSettingUnit, this); 
        }
    }

    vapp_autocap_setting_enum getType(void)
    {
        return m_settingType;
    };    
    
    vapp_autocap_setting_cap_enum getStatus(void)
    {
        if(IS_ENABLE(m_cap))
            return VAPP_AUTOCAP_SETTING_CAP_ENABLED;
        else if(IS_NOT_SUPPORT(m_cap))
            return VAPP_AUTOCAP_SETTING_CAP_DRV_NOT_SUPPORT;
        else
            return VAPP_AUTOCAP_SETTING_CAP_DISABLED;    
    };
    
    VfxU16 getValue(void)
    {
        return m_currentValue;
    };  
        
    MMI_ID_TYPE getImg(void)
    {
        return m_mainImgId;
    };
    
    MMI_ID_TYPE getStr(void)
    {
        return m_mainStrId;
    };
    
    VfxBool onHilited(void)
    {
        return m_isHiliteMode;
    };

    
    const AutoCapSettingUnit& getItem(
        VfxU16 i        
    )
    {
        return *m_content[i];
    };

    virtual void setValue(
        VfxU16 v
    );

    void resetValue(VfxU16 v);
        
    void setMgr(
        AutoCapSettingMgr* Mgr
    )
    {
        m_settingMgr = Mgr;
    };            
    
    void hide(vapp_autocap_setting_enum setting);        
    
    void show(vapp_autocap_setting_enum setting);            
    
    virtual void initialize(void);    
    
    virtual void setDefault(void);   
    
    void CheckandSet(
        VfxS32 value
    );    
    
    void setSettingBound(
        vapp_autocap_setting_enum setting,         
        VfxU16 start, 
        VfxU16 end
    );
    
    void onSettingUpdate(
        vapp_autocap_setting_enum change_setting, 
        VfxU16 change_value, 
        VfxU16 last_value
    );

    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);    
        
    virtual MMI_BOOL  queryCapbilityInfo(
        vapp_autocap_cap_info *cap_info
    );

    virtual VfxU32 getMappingID(VfxU32 mmiID);

    virtual VfxU32 getMaxValue(void);

    virtual VfxU32 getMinValue(void);    

    virtual VfxU32 getSettingCount(void);      

// Variables
public:

    VfxSignal3 <
        vapp_autocap_setting_enum,   // type
        VfxU16,                      // value
        VfxU16                       // last value        
    > m_signalSettingModified;



// Variables  
protected:    
    
    VfxU32                          m_lastValue;        
    VfxU32                          m_currentValue;    
     
    
    vapp_autocap_setting_enum       m_settingType;
    MMI_ID_TYPE                     m_mainImgId;
    MMI_ID_TYPE                     m_mainStrId;  
    VfxBool                         m_isHiliteMode;
    VfxU64                          m_cap;
    VfxU64                          m_statusBitMap;
    AutoCapSettingUnit             *m_content[VAPP_AUTOCAP_MAX_SETTING_ITEM_COUNT]; 
    AutoCapSettingMgr*              m_settingMgr;
};


class AutoCapCapModeSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);

};

class AutoCapCamSceneModeSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);    

};

class AutoCapCapSizeSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);    
    void getMappingSize(VfxU32 mmiID, U16 *width_p, U16 *height_p);    
    VfxU16 mdi_vs_mmi_capsize[VAPP_AUTOCAP_CAPSIZE_END];

private:
    void config_capsize_capability(void);
};

class AutoCapHighlightSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);        
    VfxBool isHighlightON(void);

private:
    VfxBool m_isHighlightON;
};

class AutoCapAFRangeSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);    
    
    VfxU16 m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_END];

};

class AutoCapISOSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    void getIsoBinning(void);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);        
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void); 

    VfxBool is_current_iso_binning;
    VfxBool vapp_autocap_isobinning_vs_capsize[VAPP_AUTOCAP_ISO_END][VAPP_AUTOCAP_CAPSIZE_END];
    
    mdi_camera_sensor_iso_binning_info iso_binning;

    VfxU16 m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_END];    


};
class AutoCapWBSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);        
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);     
    
    
private:

};
class AutoCapEffectSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);        
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void); 

};
class AutoCapStorageSetting : public AutoCapSettingItem
{
#define VAPP_AUTOCAP_STORAGE_CAM_FILEPATH            SHOOTING_DOWNLOAD_FOLDER_NAME
#define VAPP_AUTOCAP_STORAGE_REC_FILEPATH            SHOOTING_DOWNLOAD_FOLDER_NAME

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    void checkStorage(void);
    void setType(vapp_autocap_setting_enum type);        
    U8 getStorage(void);    
    void getStoragePath(WCHAR** storagePath);
    void genStoragePath(void);

private:    
    WCHAR m_storagePath[SRV_FMGR_PATH_BUFFER_SIZE];

};
class AutoCapCapqtySetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual VfxU32 getMappingID(VfxU32 mmiID);        

};
class AutoCapAFZoneSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);        

};
class AutoCapAEmeterSetting : public AutoCapSettingItem
{
public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);        

private:

};
class AutoCapSharpnessSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);        
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);     
    virtual VfxU32 getMaxValue(void);
    virtual VfxU32 getMinValue(void);   

    VfxU16 m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_END];
    
private:
    VfxU32 m_maxValue;
    VfxU32 m_minValue;  
  
};
class AutoCapContrastSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);        
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);     
    virtual VfxU32 getMaxValue(void);
    virtual VfxU32 getMinValue(void);   
    
    VfxU16 m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_END];

private:
    VfxU32 m_maxValue;
    VfxU32 m_minValue;    
};
class AutoCapSaturationSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);        
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);     
    virtual VfxU32 getMaxValue(void);
    virtual VfxU32 getMinValue(void);   
    
    VfxU16 m_CamSceneTable[VAPP_AUTOCAP_CAMSCENEMODE_END];

private:
    VfxU32 m_maxValue;
    VfxU32 m_minValue;  

};

class AutoCapShuttersoundSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    virtual void applyEffect(VfxU16 v);
    void play_shuttersound(VfxU16 shuttersound);   

};

class AutoCapBandingSetting : public AutoCapSettingItem
{

public:
    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual VfxU32 getMappingID(VfxU32 mmiID);    
    VfxU16 getBanding(void);

};

class AutoCapCamEVSetting : public AutoCapSettingItem
{

public:
    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);        
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);        
    virtual VfxU32 getMaxValue(void);
    virtual VfxU32 getMinValue(void);   

private:
    VfxU32 m_maxValue;
    VfxU32 m_minValue;    
};


class AutoCapCamZoomSetting : public AutoCapSettingItem
{

public:
    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    void onSettingUpdate(vapp_autocap_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_autocap_cap_info *cap_info);
    
    virtual VfxU32 getMinValue(void){return m_minStep;};
    virtual VfxU32 getMaxValue(void){return m_maxStep;};    
    VfxU16 getFactor(void){return m_currentFactor;};        
    void setFactor(VfxU16 v);      
    VfxU32 getMinFactor(void){return m_minValue;};
    VfxU32 getMaxFactor(void){return m_maxValue;};    
    
private:    
    VfxS32 m_minValue;
    VfxS32 m_maxValue;
    VfxU16 m_currentFactor;
    VfxU16 m_minStep;
    VfxU16 m_maxStep;    

};

class AutoCapRestoredefaultSetting : public AutoCapSettingItem
{

public:
    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    
};


class AutoCapCameraSensorSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    virtual VfxU32 getMappingID(VfxU32 mmiID);        
    void setCameraID(VfxU16 camid);   

};


class AutoCapPanoramaDirectionSetting : public AutoCapSettingItem
{

public:

    virtual void initialize(void);    
    virtual void setDefault(void);    
    virtual void setValue(VfxU16 v);    
    virtual VfxU32 getMappingID(VfxU32 mmiID);        


};

#endif

#endif
