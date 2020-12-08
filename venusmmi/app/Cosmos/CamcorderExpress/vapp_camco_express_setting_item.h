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

#ifndef __VAPP_CAMCO_EXPRESS_SETTING_ITEM__
#define __VAPP_CAMCO_EXPRESS_SETTING_ITEM__

#include "MMI_include.h"
#include "mmi_features_camcorder.h"

#ifdef __VAPP_CAMCO_EXPRESS__
/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vfx_uc_include.h"
#include "vcp_include.h"

#include "vapp_camco_express_setting.h"

#include "FileManagerDef.h"
#include "FileMgrGProt.h"
#include "FileMgrSrvGProt.h"
#include "FileMgr.h"
#include "FileManagerResDef.h"
#include "vapp_fmgr_table.h"

/*****************************************************************************
 * Define
 *****************************************************************************/
#define IS_ENABLE(x) (x == VAPP_CAMCO_SETTING_STATUS_ENABLED)
#define IS_NOT_SUPPORT(x) (x == (1 <<VAPP_CAMCO_SETTING_STATUS_DRV_NOT_SUPPORT))
#define IS_DISABLE(x, y) (x == (1 <<y))
#define ENABLE() (VAPP_CAMCO_SETTING_STATUS_ENABLED)
#define NOT_SUPPORT() (1 <<VAPP_CAMCO_SETTING_STATUS_DRV_NOT_SUPPORT)
#define DISABLE(y) (1 <<y)
class CamcoSettingMgr;

//#if defined(__COSMOS_NO_USER_DRIVE__)
#define __VAPP_CAMCO_NO_PUBLIC_DRV__
//#endif

/*****************************************************************************
 * Class
 *****************************************************************************/

// The class of setting unit
// One object mean the one item of setting
// it contains its status/image/string
class CamcoSettingUnit : public VfxObject
{

// Method
public:
    // The function return the status of the setting unit
    // RETURN: status of the setting unit (ENABLE / DISABLE / NOT_SUPPORT)
    vapp_camco_setting_cap_enum getStatus(void) const
    {
        if(IS_ENABLE(m_cap))
            return VAPP_CAMCO_SETTING_CAP_ENABLED;
        else if(IS_NOT_SUPPORT(m_cap))
            return VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT;
        else
            return VAPP_CAMCO_SETTING_CAP_DISABLED;
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
        vapp_camco_setting_enum setting,
        vapp_camco_setting_cap_enum cap          // [IN] the new staus of setting unit
    )
    {
        if(cap == VAPP_CAMCO_SETTING_CAP_ENABLED)
        {
            if(!IS_NOT_SUPPORT(m_cap))
                m_cap &= ~(1 << setting);
        }
        else if(cap == VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
        {
            m_cap = NOT_SUPPORT();
        }
        else if(cap == VAPP_CAMCO_SETTING_CAP_DISABLED)
        {
            if(!IS_NOT_SUPPORT(m_cap))
                m_cap |= (1 << setting);
        }
    };

    void setStatus(
        vapp_camco_setting_cap_enum cap          // [IN] the new staus of setting unit
    )
    {
        if(cap == VAPP_CAMCO_SETTING_CAP_ENABLED)
        {
            m_cap = VAPP_CAMCO_SETTING_STATUS_ENABLED;
        }
        else if(cap == VAPP_CAMCO_SETTING_CAP_DRV_NOT_SUPPORT)
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
    virtual void initialize(void)
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
    VfxU16                          m_value;        // the setting unit value
};

class CamcoSettingItem : public VfxObject
{
// Method
public:
    virtual void onInit()
    {
        VfxObject:: onInit();

        for(VfxU32 i = 0; i < VAPP_CAMCO_MAX_SETTING_ITEM_COUNT; i++)
        {
            VFX_OBJ_CREATE(m_content[i], CamcoSettingUnit, this);
        }
    }

    vapp_camco_setting_enum getType(void)
    {
        return m_settingType;
    };

    vapp_camco_setting_cap_enum getStatus(void);

    virtual VfxU16 getValue(void)
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


    const CamcoSettingUnit& getItem(
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
        CamcoSettingMgr* Mgr
    )
    {
        m_settingMgr = Mgr;
    };

    void hide(vapp_camco_setting_enum setting);

    void show(vapp_camco_setting_enum setting);

    virtual void initialize(void);

    virtual void setDefault(void);

    void CheckandSet(
        VfxS32 value
    );

    void setSettingBound(
        vapp_camco_setting_enum setting,
        VfxU16 start,
        VfxU16 end
    );

    void onSettingUpdate(
        vapp_camco_setting_enum change_setting,
        VfxU16 change_value,
        VfxU16 last_value
    );

    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);

    virtual MMI_BOOL  queryCapbilityInfo(
        vapp_camco_cap_info *cap_info
    );

    virtual VfxU32 getMappingID(VfxU32 mmiID);

    virtual VfxU32 getMaxValue(void);

    virtual VfxU32 getMinValue(void);

    virtual VfxU32 getSettingCount(void);

// Variables
public:

    VfxSignal3 <
        vapp_camco_setting_enum,     // type
        VfxU16,                      // value
        VfxU16                       // last value
    > m_signalSettingModified;

// Variables
protected:

    VfxU32                          m_lastValue;                                    // the previous setting value
    VfxU32                          m_currentValue;                                 // the current setting value

    vapp_camco_setting_enum         m_settingType;                                  // type fo the setting
    MMI_ID_TYPE                     m_mainImgId;                                    // the image ID for the setting
    MMI_ID_TYPE                     m_mainStrId;                                    // the string ID for the setting
    VfxBool                         m_isHiliteMode;                                 // if the setting is hilited (apply the effect of current value)
    VfxU64                          m_cap;                                          // the status of the setting
    CamcoSettingUnit               *m_content[VAPP_CAMCO_MAX_SETTING_ITEM_COUNT];   // the list of setting unit in the setting
    CamcoSettingMgr*                m_settingMgr;                                   // the ptr point to its setting manager
};

class SmileDetectSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
};

class SceneDetectSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
};

class ZeroDelaySetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
};

class CamSceneModeSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual VfxU16 getValue(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);

    void setActiveValue(VfxU16 v);

private:
    VfxU32  m_activeScene;      // valid when capmode is ASD
};

class CapSizeSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
    void getMappingSize(VfxU32 mmiID, U16 *width_p, U16 *height_p);
    VfxU16 mdi_vs_mmi_capsize[VAPP_CAMCO_CAPSIZE_END];
    VfxSize mdi_real_capture_size[VAPP_CAMCO_CAPSIZE_END];

private:
    void config_capsize_capability(void);
};

class FlashSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
    vapp_camco_setting_flash_type_enum getFlashType(void){return flash_type;};

private:
    vapp_camco_setting_flash_type_enum flash_type;
};

class SelfTimerSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
};

class ISOSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    void getIsoBinning(void);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);

    VfxBool is_current_iso_binning;
    VfxBool vapp_camco_isobinning_vs_capsize[VAPP_CAMCO_ISO_END][VAPP_CAMCO_CAPSIZE_END];

    mdi_camera_sensor_iso_binning_info iso_binning;
};

class WBSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);
};

class EffectSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);
};

class StorageSetting : public CamcoSettingItem
{
#define VAPP_CAMCO_STORAGE_CAM_FILEPATH            SHOOTING_DOWNLOAD_FOLDER_NAME
#define VAPP_CAMCO_STORAGE_REC_FILEPATH            SHOOTING_DOWNLOAD_FOLDER_NAME

public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    void checkStorage(void);
    void setType(vapp_camco_setting_enum type);
    U8 getStorage(void);
    void getStoragePath(WCHAR** storagePath);
    void genStoragePath(void);

private:
    WCHAR m_storagePath[SRV_FMGR_PATH_BUFFER_SIZE/2];

    void config_recstorage_capability(vapp_camco_setting_enum changed_setting);
};

class CapqtySetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
};

class VdoSceneModeSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
};

class RecSizeSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
    VfxSize getSize(VfxU16 v);

private:
    void config_recsize_capability(vapp_camco_setting_enum changed_setting);
};

class TimeLapseSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
};

class TimeLapsePeriodSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
};

class LimitSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    VfxU32 getSizeLimit(void);
    VfxU32 getTimeLimit(void);

    VfxS32 m_extLimit;
    VfxBool m_extIsSizeLimit;
};

class VisQtySetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual VfxU32 getMappingID(VfxU32 mmiID);

private:
    void config_recqty_capability(vapp_camco_setting_enum changed_setting);
};

class VisCodecSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual VfxU32 getMappingID(VfxU32 mmiID);

private:
    void config_reccodec_capability(vapp_camco_setting_enum changed_setting);
};

class CamEVSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);
    virtual VfxU32 getMaxValue(void);
    virtual VfxU32 getMinValue(void);

private:
    VfxU32 m_maxValue;
    VfxU32 m_minValue;
};

class VdoEVSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
    virtual void applyEffect(VfxU16 v);
    virtual void resetEffect(void);
    virtual VfxU32 getMaxValue(void);
    virtual VfxU32 getMinValue(void);

private:
    VfxU32 m_maxValue;
    VfxU32 m_minValue;
};

class CamZoomSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);

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

class VdoZoomSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    void onSettingUpdate(vapp_camco_setting_enum change_setting, VfxU16 change_value, VfxU16 last_value);
    virtual MMI_BOOL queryCapbilityInfo(vapp_camco_cap_info *cap_info);


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

class ApplicationSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
};

class CameraSensorSetting : public CamcoSettingItem
{
public:
    virtual void initialize(void);
    virtual void setDefault(void);
    virtual void setValue(VfxU16 v);
    virtual VfxU32 getMappingID(VfxU32 mmiID);
    void setCameraID(VfxU16 camid);
};

#endif /*__VAPP_CAMCO_EXPRESS__*/
#endif /*__VAPP_CAMCO_EXPRESS_SETTING_ITEM__*/
