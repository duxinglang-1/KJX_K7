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

#ifndef __VAPP_CAMCO_SLIM_SETTING_MGR__
#define __VAPP_CAMCO_SLIM_SETTING_MGR__

#include "MMI_include.h"
#include "mmi_features_camcorder.h"

#ifdef __VAPP_CAMCO_SLIM__

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
#include "vcui_camco_gprot.h"
#include "vapp_camco_slim_setting_item.h"

typedef struct
{
    MMI_ID_TYPE                     settingImgId[VAPP_CMACO_MAX_SETTING_LIST_SIZE];
    MMI_ID_TYPE                     settingStrId[VAPP_CMACO_MAX_SETTING_LIST_SIZE];
    vapp_camco_setting_enum         settingValue[VAPP_CMACO_MAX_SETTING_LIST_SIZE];
    VfxBool                         settingEnable[VAPP_CMACO_MAX_SETTING_LIST_SIZE];
    VfxU16                          settingCount;
    VfxU16                          CurrentSettingIdx;

    MMI_ID_TYPE                     settingItemImgId[VAPP_CMACO_MAX_SETTING_LIST_SIZE][VAPP_CAMCO_MAX_SETTING_ITEM_COUNT];
    MMI_ID_TYPE                     settingItemStrId[VAPP_CMACO_MAX_SETTING_LIST_SIZE][VAPP_CAMCO_MAX_SETTING_ITEM_COUNT];
    VfxU16                          settingItemValue[VAPP_CMACO_MAX_SETTING_LIST_SIZE][VAPP_CAMCO_MAX_SETTING_ITEM_COUNT];
    VfxBool                         settingItemEnable[VAPP_CMACO_MAX_SETTING_LIST_SIZE][VAPP_CAMCO_MAX_SETTING_ITEM_COUNT];
    VfxU16                          settingItemCount[VAPP_CMACO_MAX_SETTING_LIST_SIZE];
    VfxU16                          CurrentSettingValue[VAPP_CMACO_MAX_SETTING_LIST_SIZE];
    VfxU16                          CurrentSettingValueIdx[VAPP_CMACO_MAX_SETTING_LIST_SIZE];

}vapp_camco_setting_list_struct;

class VappCamcoApp;

class CamcoSettingMgr : public VfxObject
{
public:

    virtual void onInit(void);

    void setCallingMode(VfxBool isExtCalling, vcui_camco_param_struct Param);

    VfxU16 getValue(void)
    {
        return m_ActiveSetting->getValue();
    };

    VfxU16 getValue(
        vapp_camco_setting_enum type
    );

    VfxBool setValue(vapp_camco_setting_enum type, VfxU16 value);

    VfxBool setValue(VfxU16 value);

    VfxBool setValue(void);

    VfxBool setValue(VfxU16 newHiliteIdx, VfxBool dummy);

    void setHilite(VfxU16 value);

    vapp_camco_app_enum getCurrApp(void)
    {
        return (vapp_camco_app_enum)m_Application->getValue();
    };

    vapp_camco_sensor_enum getCurrCam(void)
    {
        return (vapp_camco_sensor_enum)m_CamearaSensor->getValue();
    };

    void setCurrApp(vapp_camco_app_enum v)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SETTING_SET_VALUE_ACT_APP, v);
        m_Application->setValue(v);

        if(m_IsExternalSetting)
            return;

        nvram_ef_camco_ex_vapp_info_struct nvram_camco_info;
        S16 error;

        nvram_camco_info.active_app = m_Application->getValue();
        nvram_camco_info.active_cam = m_CamearaSensor->getValue();

        WriteRecord(
            NVRAM_EF_CAMCO_EX_VAPP_INFO_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_camco_info,
            NVRAM_EF_CAMCO_EX_VAPP_INFO_SIZE,
            &error);
    };

    void setCurrCam(vapp_camco_sensor_enum v)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_CAMCO_SLIM_SETTING_SET_VALUE_ACT_CAM, v);
        m_CamearaSensor->setValue(v);

        if(m_IsExternalSetting)
            return;

        nvram_ef_camco_ex_vapp_info_struct nvram_camco_info;
        S16 error;

        nvram_camco_info.active_app = m_Application->getValue();
        nvram_camco_info.active_cam = m_CamearaSensor->getValue();

        WriteRecord(
            NVRAM_EF_CAMCO_EX_VAPP_INFO_LID,
            1,  /* first one is from 1 */
            (void*)&nvram_camco_info,
            NVRAM_EF_CAMCO_EX_VAPP_INFO_SIZE,
            &error);
    };

    void getStoragePath(WCHAR** storagePath)
    {
        if(getCurrApp() == VAPP_CAMCO_APP_CAMERA)
            m_CamStorage->getStoragePath(storagePath);
        else
            m_RecStorage->getStoragePath(storagePath);
    }

    U8 getStorage(void)
    {
        if(getCurrApp() == VAPP_CAMCO_APP_CAMERA)
            return m_CamStorage->getStorage();
        else
            return m_RecStorage->getStorage();
    }


    VfxU32 getMappingID(vapp_camco_setting_enum type);
    VfxU32 getMappingID(vapp_camco_setting_enum type, VfxU32 mmiID);

    vapp_camco_setting_cap_enum getStatus(vapp_camco_setting_enum type);

    void genMainList(vapp_camco_setting_mainlist_type_enum type);

    void genItemList(void);
    void genItemList(vapp_camco_setting_enum type);

    vapp_camco_setting_mainlist_type_enum getListType(void)
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

    void getCurrentSetting(
        CamcoSettingItem** setting_p
    );

    void getSetting(
        vapp_camco_setting_enum type,
        CamcoSettingItem** setting_p
    );

    const CamcoSettingItem* getSetting(
        vapp_camco_setting_enum type
    );

    MMI_ID_TYPE getSettingImg(
        vapp_camco_setting_enum type
    ) const;

    MMI_ID_TYPE getSettingStatusImg(vapp_camco_setting_enum type);

    MMI_ID_TYPE getSettingStatusIcon(vapp_camco_setting_enum type);

    vapp_camco_setting_enum getCurrentSetting(void);

    VfxBool setCurrentSetting(void);

    VfxBool setCurrentSetting(vapp_camco_setting_enum type);

    VfxU32 getMaxValue(void);

    VfxU32 getMaxValue(vapp_camco_setting_enum type);

    VfxU32 getMinValue(vapp_camco_setting_enum type);

    VfxU32 getMinValue(void);

    VfxU32 getSettingCount(vapp_camco_setting_enum type);



    void getSettingList(vapp_camco_setting_list_struct* List_p);

    VfxBool initialized(void){ return m_ListCreated;};

    VfxBool IsExtSetting(void){return m_IsExternalSetting;};

    void setIsExtSetting(VfxBool isExt){m_IsExternalSetting = isExt;};

    void initAllSetting(void);
    void setDefaultAllSetting(void);
    void setValueAllSetting(void);

    void resetEffect(void);

    void loadSetting(void);
    void storeSetting(void);

    static void getNvRamSetting(vapp_camco_setting_set_struct *set);

    void needRestartPreview(void){m_isRestartPreview = VFX_TRUE;};
    void resetRestartPreview(void){m_isRestartPreview = VFX_FALSE;};
    VfxBool isNeedRestartPreview(void){return m_isRestartPreview;};

    // custom config related
    vapp_camco_setting_enum transTargetToMMI(recoorder_config_setting_target target);
    recoorder_config_setting_target transTargetFromMMI(vapp_camco_setting_enum target);
    VfxU16 transValueToMMI(recoorder_config_setting_value value);
    recoorder_config_setting_value transValueFromMMI(VfxU16 value, vapp_camco_setting_enum target);
    void customConfig(void);
    void customUpdate(vapp_camco_setting_enum target, VfxU16 value);
    VfxBool IsKeySetting(vapp_camco_setting_enum setting);

    vcui_camco_param_struct                 m_callingParam;

private:

    void CleanMainList(void);
    void CleanItemList(void);
    VfxBool AddtoMainList(CamcoSettingItem* setting);

    void getSeetingLog(vapp_camco_setting_enum s, VfxU32 v);
    void setSeetingLog(vapp_camco_setting_enum s, VfxU32 v);

    VfxBool                                 m_IsExternalSetting;
    VfxBool                                 m_isRestartPreview;
    VfxBool                                 m_isReadNvramData;

    CamcoSettingItem                       *m_allSettingList[VAPP_CAMCO_SETTING_END];
    VfxU16                                  m_allSettingCount;

    /* setting List related */
    VfxBool                                 m_ListCreated;

    vapp_camco_setting_mainlist_type_enum   m_settingListType;
    CamcoSettingItem                       *m_mainList[VAPP_CAMCO_SETTING_END];
    VfxU16                                  m_mainCount;
    const CamcoSettingUnit                 *m_itemList[VAPP_CAMCO_MAX_SETTING_ITEM_COUNT];
    VfxU16                                  m_itemCount;
    CamcoSettingItem                       *m_ActiveSetting;
    VfxU16                                  m_ActiveSettingIdx;
    const CamcoSettingUnit                 *m_ActiveSettingItem;
    VfxU16                                  m_ActiveSettingItemIdx;

    // custom config related
    vapp_camco_setting_enum                 m_keySettingType;

    /* each setting */
  
    CapSizeSetting                         *m_CapSize;
    ISOSetting                             *m_ISO;
    StorageSetting                         *m_CamStorage;
    StorageSetting                         *m_RecStorage;
    CapqtySetting                          *m_CapQty;
     RecSizeSetting                        *m_RecSize;
    VisQtySetting                          *m_RecQty;
    VisCodecSetting                        *m_RecCodec;
    CamZoomSetting                         *m_CapZoom;
    VdoZoomSetting                         *m_RecZoom;
    ApplicationSetting                     *m_Application;
    CameraSensorSetting                    *m_CamearaSensor;
};

#endif /*__VAPP_CAMCO_SLIM__*/
#endif /*__VAPP_CAMCO_SLIM_SETTING_MGR__*/
