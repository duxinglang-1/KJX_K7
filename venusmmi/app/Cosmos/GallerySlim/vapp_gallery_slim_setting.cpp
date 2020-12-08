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
 *  vapp_gallery_setting.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_GALLERY_SLIM__

#include "vapp_gallery_slim_setting.h"
#include "mmi_rp_vapp_gallery_def.h"
#include "GlobalResDef.h"
#include "vcp_form.h"

#include "vcui_dtcnt_select_gprot.h"
#include "vapp_dtcnt_gprot.h"

extern "C"
{
#include "cbm_api.h"
#include "MMI_media_app_trc.h"
#include "SimCtrlSrvGprot.h"
}

#ifdef __COSMOS_3D_V10__
#define VAPP_GALLERY_3D_SLIDESHOW
#endif

#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /*defined(__MMI_VUI_COSMOS_CP__)*/

/*****************************************************************************
 * VappGalleryStorageSetting Implementation
 *****************************************************************************/
VappGalleryStorageSetting::VappGalleryStorageSetting()
{
    readFromNVRAM();
    m_dirty = VFX_FALSE;
}

VappGalleryStorageSetting::~VappGalleryStorageSetting()
{
    if(m_dirty)
    {
        flushToNVRAM();
    }
}

// get default storage
srv_fmgr_drv_type_enum VappGalleryStorageSetting::getDefaultStorage(VfxBool correntInvalidStorage)
{
    if(correntInvalidStorage)
    {
        // check if default storage is in accessible list
        SRV_FMGR_DRVLIST_HANDLE hDrvList = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE_ONLY);
        if(-1 == srv_fmgr_drivelist_get_index_by_drv_type(hDrvList, m_defaultDriveType))
        {
            m_dirty = VFX_TRUE;
            #ifdef __VAPP_GALLERY_ENABLE_USER_DRIVE__
            // fallback to phone storage if default drive is not accessible.
            m_defaultDriveType = SRV_FMGR_DRV_PHONE_TYPE;
            #else
            m_defaultDriveType = SRV_FMGR_DRV_CARD_TYPE;
            #endif
        }
        srv_fmgr_drivelist_destroy(hDrvList);
    }
#ifdef __VAPP_GALLERY_ENABLE_USER_DRIVE__
    return m_defaultDriveType;
#else
    if(SRV_FMGR_DRV_PHONE_TYPE == m_defaultDriveType)
    {
        m_defaultDriveType = SRV_FMGR_DRV_CARD_TYPE;
    }
    return m_defaultDriveType;
#endif
}

// set default storage
void VappGalleryStorageSetting::setDefaultStorage(srv_fmgr_drv_type_enum drvType)
{
    if(m_defaultDriveType != drvType)
    {
        m_dirty = VFX_TRUE;
        m_defaultDriveType = drvType;
    }
}

void VappGalleryStorageSetting::readFromNVRAM()
{
    // read MMI_CACHE
    VfxS16 sError = 0;
    // VfxS32 ret = 0;
    VfxU8 defaultStorage = 0;
    // ret = ReadValue(NVRAM_VAPP_GALLERY_OPT_DEFAULT_DRV_TYPE, (void*)&defaultStorage, DS_BYTE, &sError);
    ReadValue(NVRAM_VAPP_GALLERY_OPT_DEFAULT_DRV_TYPE, (void*)&defaultStorage, DS_BYTE, &sError);
    m_defaultDriveType = static_cast<srv_fmgr_drv_type_enum>(defaultStorage);
    // VFX_UNUSED(ret);
}

void VappGalleryStorageSetting::flushToNVRAM()
{
    // write MMI_CACHE
    VfxS16 sError = 0;
    // VfxS32 ret;
    VfxU8 defaultStorage = static_cast<VfxU8>(m_defaultDriveType);
    // ret = WriteValue(NVRAM_VAPP_GALLERY_OPT_DEFAULT_DRV_TYPE, (void*)&defaultStorage, DS_BYTE, &sError);
    WriteValue(NVRAM_VAPP_GALLERY_OPT_DEFAULT_DRV_TYPE, (void*)&defaultStorage, DS_BYTE, &sError);
    // VFX_UNUSED(ret);
}

/*****************************************************************************
 * Static Variable for Slideshow Setting
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
const VfxMsec VappGallerySlideShowSetting::g_delayOption[DELAY_OPTION_COUNT] = {\
    1000, 2000, 3000, 5000, 10000, 20000};

const VappGallerySlideshowEffectOption VappGallerySlideShowSetting::g_effectOption[] = {
#ifdef VAPP_GALLERY_3D_SLIDESHOW
    {VCP_PAGE_EFFECT_NONE, STR_ID_VAPP_GALLERY_SETTING_EFFECT_SCENE},
    {VCP_PAGE_EFFECT_3D_BRICK_FLIP, STR_ID_VAPP_GALLERY_SETTING_EFFECT_MOSAIC},
    {VCP_PAGE_EFFECT_3D_TWIST, STR_ID_VAPP_GALLERY_SETTING_EFFECT_TWIST},
    {VCP_PAGE_EFFECT_3D_FUSION, STR_ID_VAPP_GALLERY_SETTING_EFFECT_FUSION},
    {VCP_PAGE_EFFECT_3D_CURL, STR_ID_VAPP_GALLERY_SETTING_EFFECT_DOUBLE_PAGE_CURL},
    {VCP_PAGE_EFFECT_3D_RIPPLE, STR_ID_VAPP_GALLERY_SETTING_EFFECT_RIPPLE},
#else
    {VCP_PAGE_EFFECT_FADE_IN, STR_ID_VAPP_GALLERY_SETTING_EFFECT_FADE_IN},
    {VCP_PAGE_EFFECT_FLIP, STR_ID_VAPP_GALLERY_SETTING_EFFECT_FLIP},
    {VCP_PAGE_EFFECT_PUSH, STR_ID_VAPP_GALLERY_SETTING_EFFECT_PUSH},
    {VCP_PAGE_EFFECT_ZOOM, STR_ID_VAPP_GALLERY_SETTING_EFFECT_ZOOM},
#endif  // #ifdef VAPP_GALLERY_3D_SLIDESHOW
};
#endif //__VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
/*****************************************************************************
 * VappGallerySettingPage Implementation
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_SETTING_PAGE__
VFX_IMPLEMENT_CLASS("VappGallerySettingPage", VappGallerySettingPage, VfxPage);
VappGallerySettingPage::VappGallerySettingPage() :
    #ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
    m_pLaunchDelaySetting(NULL),
    m_pLaunchTransitionSetting(NULL),
    m_pShuffleSwitch(NULL),
    m_pRepeatSwitch(NULL),
    #endif
    #ifdef __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__
    m_pLaunchStreamingSetting(NULL),
    #endif
    options(NULL)
{

}

void VappGallerySettingPage::onInit()
{
    VfxPage::onInit(); // call base class

    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // title bar
    VcpTitleBar *bar = NULL;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SETTING_TITLE));
    setTopBar(bar);

    // form that contains options    
    VFX_OBJ_CREATE(options, VcpForm, this);
    options->setSize(getSize().width, getSize().height);

    #ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
	VFX_OBJ_CREATE(m_pLaunchDelaySetting, VcpFormItemLauncherCell, options);
	m_pLaunchDelaySetting->setMainText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SETTING_DELAY_PER_IMAGE));
	m_pLaunchDelaySetting->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_pLaunchDelaySetting->m_signalTap.connect(this, &VappGallerySettingPage::onPickDelay);

	VFX_OBJ_CREATE(m_pLaunchTransitionSetting, VcpFormItemLauncherCell, options);
	m_pLaunchTransitionSetting->setMainText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SETTING_SLIDE_TRANSITION_CAPTION));
    m_pLaunchTransitionSetting->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_pLaunchTransitionSetting->m_signalTap.connect(this, &VappGallerySettingPage::onPickEffect);

    VFX_OBJ_CREATE(m_pShuffleSwitch, VcpFormItemSwitchCell, options);
    m_pShuffleSwitch->setMainText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SETTING_SLIDE_SHUFFLE_CAPTION));
    m_pShuffleSwitch->setHintText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SETTING_SLIDE_SHUFFLE_DESC));
    m_pShuffleSwitch->setSwitchStatus(settingProxy.getShuffle());
    m_pShuffleSwitch->m_signalSwitchChangeReq.connect(this, &VappGallerySettingPage::onShuffleChange);
    m_pShuffleSwitch->setIsTappable(VFX_FALSE);

    VFX_OBJ_CREATE(m_pRepeatSwitch, VcpFormItemSwitchCell, options);
    m_pRepeatSwitch->setMainText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SETTING_SLIDE_REPEAT_CAPTION));
    m_pRepeatSwitch->setHintText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SETTING_SLIDE_REPEAT_DESC));
    m_pRepeatSwitch->setSwitchStatus(settingProxy.getRepeat());
    m_pRepeatSwitch->m_signalSwitchChangeReq.connect(this, &VappGallerySettingPage::onRepeatChange);
    m_pRepeatSwitch->setIsTappable(VFX_FALSE);
    #endif

    #ifdef __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__
    VFX_OBJ_CREATE(m_pLaunchStreamingSetting, VcpFormItemLauncherCell, options);
	m_pLaunchStreamingSetting->setMainText(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SETTING_STREAM_SETTING));
    m_pLaunchStreamingSetting->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_pLaunchStreamingSetting->m_signalTap.connect(this, &VappGallerySettingPage::onStreamingSetting);
    #endif

    #ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
	options->addItem(m_pLaunchDelaySetting, 0);
	options->addItem(m_pLaunchTransitionSetting, 1);
    options->addItem(m_pShuffleSwitch, 2);
    options->addItem(m_pRepeatSwitch, 3);
    #endif
    #ifdef __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__
    options->addItem(m_pLaunchStreamingSetting, 4);
    #endif
}

void VappGallerySettingPage::onDeinit()
{
    #ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
    // make sure the settings are updated.
    settingProxy.flushToNVRAM();
    #endif
    VfxPage::onDeinit();
}

void VappGallerySettingPage::onExit(VfxBool isBackward)
{
    #ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
    // make sure the settings are updated.
    settingProxy.flushToNVRAM();
    #endif
}

void VappGallerySettingPage::onEnter(VfxBool isBackward)
{
    checkUpdate();
}

void VappGallerySettingPage::onUpdate()
{
    VfxPage::onUpdate();
    #ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
    // hint text of delay time
    VfxWString hintText;
    VfxS32 sec = settingProxy.getDelayTime() / 1000;
    hintText.format("%d ", sec);
    hintText += VFX_WSTR_RES(sec > 1 ? STR_ID_VAPP_GALLERY_SETTING_SECS : STR_ID_VAPP_GALLERY_SETTING_SEC);
	m_pLaunchDelaySetting->setHintText(hintText);
    m_pLaunchTransitionSetting->setHintText(VFX_WSTR_RES(settingProxy.getEffectName()));
    #endif
}

VfxBool VappGallerySettingPage::isSettingRelatedPage(VfxPage *p)
{
    #ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
    VappGallerySettingDelayPage     *settingDelayPage     = NULL;
    VappGallerySettingEffectPage    *settingEffectPage    = NULL;
    VappGallerySlideshowPreviewPage *slideshowPreviewPage = NULL;
    #endif
    #ifdef __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__
    VappGalleryStreamingSettingPage *streamingSettingPage = NULL;
    #endif
    VappGallerySettingPage *settingPage = NULL;

    do
    {
        // check if page is slideshow setting page
        #ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
        settingDelayPage = VFX_OBJ_DYNAMIC_CAST(p, VappGallerySettingDelayPage);
        if(settingDelayPage){return VFX_TRUE;}

        settingEffectPage = VFX_OBJ_DYNAMIC_CAST(p, VappGallerySettingEffectPage);
        if(settingEffectPage){return VFX_TRUE;}

        slideshowPreviewPage = VFX_OBJ_DYNAMIC_CAST(p, VappGallerySlideshowPreviewPage);
        if(slideshowPreviewPage){return VFX_TRUE;}
        #endif

        // check if page is steaming setting page
        #ifdef __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__
        streamingSettingPage = VFX_OBJ_DYNAMIC_CAST(p, VappGalleryStreamingSettingPage);
        if(streamingSettingPage){return VFX_TRUE;}
        #endif

        settingPage = VFX_OBJ_DYNAMIC_CAST(p, VappGallerySettingPage);
        if(settingPage){return VFX_TRUE;}
    }while(0);
    return VFX_FALSE;
}

#ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
void VappGallerySettingPage::onShuffleChange(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus)
{
    settingProxy.setShuffle(newStatus);
    item->setSwitchStatus(newStatus);
    return;
}

void VappGallerySettingPage::onRepeatChange(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus)
{
    settingProxy.setRepeat(newStatus);
    item->setSwitchStatus(newStatus);
}

void VappGallerySettingPage::onPickDelay(VcpFormItemCell* item, VfxId id)
{
    VappGallerySettingDelayPage *pickPage = NULL;
    VFX_OBJ_CREATE(pickPage, VappGallerySettingDelayPage, getMainScr());
    pickPage->setSettingProxy(&settingProxy);
    getMainScr()->pushPage(0, pickPage);
}

void VappGallerySettingPage::onPickEffect(VcpFormItemCell* item, VfxId id)
{
    VappGallerySettingEffectPage *pickPage = NULL;
    VFX_OBJ_CREATE(pickPage, VappGallerySettingEffectPage, getMainScr());
    pickPage->setSettingProxy(&settingProxy);
    getMainScr()->pushPage(0, pickPage);
}
#endif //__VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__

#ifdef __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__
void VappGallerySettingPage::onStreamingSetting(VcpFormItemCell* item, VfxId id)
{
    VappGalleryStreamingSettingPage *streamingSettingPage = NULL;
    VFX_OBJ_CREATE(streamingSettingPage, VappGalleryStreamingSettingPage, getMainScr());
    getMainScr()->pushPage(0, streamingSettingPage);
}
#endif //__VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__
#endif // __VAPP_GALLERY_ENABLE_SETTING_PAGE__
/*****************************************************************************
 * VappGallerySettingDelayPage Implementation
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
VFX_IMPLEMENT_CLASS("VappGallerySettingDelayPage", VappGallerySettingDelayPage, VfxPage);
void VappGallerySettingDelayPage::onInit()
{
    VfxPage::onInit(); // call base class

    // title bar
    VcpTitleBar *bar = NULL;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SETTING_DELAY_PER_IMAGE));
    setTopBar(bar);

    // delay option list
    VFX_OBJ_CREATE(m_pDelayMenu, VcpListMenu, this);
    m_pDelayMenu->setSize(getSize());
    m_pDelayMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_pDelayMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_pDelayMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
    m_pDelayMenu->m_signalItemTapped.connect(this, &VappGallerySettingDelayPage::onItemTapped);
    m_pDelayMenu->m_signalItemSelectionStateChanged.connect(this, &VappGallerySettingDelayPage::onItemSelectionChanged);

    if(m_pSettingProxy)
    {
        m_pDelayMenu->setContentProvider(this);
    }
}

void VappGallerySettingDelayPage::onItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_DEV_ASSERT(m_pSettingProxy);
    m_pSettingProxy->setSelectedDelayOptionIndex(index);
    m_pSettingProxy->flushToNVRAM();
    exit();
}

void VappGallerySettingDelayPage::onItemSelectionChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    VFX_UNUSED(sender);
    VFX_UNUSED(index);
    VFX_UNUSED(newState);
}
#endif

/*****************************************************************************
 * VappGallerySlideShowSetting Implementation
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
VappGallerySlideShowSetting::VappGallerySlideShowSetting():
    m_delaySecondOptionIndex(0),
    m_effectOptionIndex(0),
    m_isShuffle(0),
    m_isRepeat(0)
{
    readFromNVRAM();
}

VappGallerySlideShowSetting::~VappGallerySlideShowSetting()
{
    flushToNVRAM();
}

void VappGallerySlideShowSetting::flushToNVRAM()
{
    // write MMI_CACHE
    VfxS16 sError = 0;
    VfxU8 selectedSec = getDelayTime() / MSEC_PER_SEC;  // we store seconds instead of index
    WriteValue(NVRAM_VAPP_GALLERY_SLD_DELAY_SEC, (void*)&selectedSec, DS_BYTE, &sError);
    WriteValue(NVRAM_VAPP_GALLERY_SLD_TRANSITION_ENUM, (void*)&m_effectOptionIndex, DS_SHORT, &sError);
    WriteValue(NVRAM_VAPP_GALLERY_SLD_IS_SHUFFLE, (void*)&m_isShuffle, DS_BYTE, &sError);
    WriteValue(NVRAM_VAPP_GALLERY_SLD_IS_REPEAT, (void*)&m_isRepeat, DS_BYTE, &sError);
}

VfxBool VappGallerySlideShowSetting::getShuffle()
{
    return m_isShuffle ? VFX_TRUE : VFX_FALSE;
}

void VappGallerySlideShowSetting::setShuffle(VfxBool isShuffle)
{
    m_isShuffle = isShuffle;
}

VfxBool VappGallerySlideShowSetting::getRepeat()
{
    return m_isRepeat ? VFX_TRUE : VFX_FALSE;
}

void VappGallerySlideShowSetting::setRepeat(VfxBool isRepeat)
{
    m_isRepeat = isRepeat;
}

VfxMsec VappGallerySlideShowSetting::getDelayTime()
{
    return getDelayTimeByOptionIndex(getSelectedDelayOptionIndex());
}

VfxS32 VappGallerySlideShowSetting::getDelayOptionCount() const
{
    return DELAY_OPTION_COUNT;
}

VfxMsec VappGallerySlideShowSetting::getDelayTimeByOptionIndex(VfxS32 idx)
{
    if(idx < 0 || idx >= getDelayOptionCount())
    {
        return 0;
    }
    return g_delayOption[idx];
}

void VappGallerySlideShowSetting::setSelectedDelayOptionIndex(VfxS32 idx)
{
    if(idx < 0 || idx >= getDelayOptionCount())
    {
        VFX_ASSERT(VFX_FALSE); // index out of bound
        return;
    }

    m_delaySecondOptionIndex = idx;
}

VfxS32 VappGallerySlideShowSetting::getSelectedDelayOptionIndex() const
{
    return m_delaySecondOptionIndex;
}

void VappGallerySlideShowSetting::getEffect(VfxBool &isTransitionEffect, VcpPageEffectType &transitionType)
{
    // TODO: read transition slideshow or scene slide show from MMI CACHE
    transitionType = getEffectByOptionIndex(m_effectOptionIndex);
    isTransitionEffect = (transitionType != VCP_PAGE_EFFECT_NONE);
    return;
}

MMI_STR_ID VappGallerySlideShowSetting::getEffectName()
{
    return getEffectNameByOptionIndex(m_effectOptionIndex);
}

VfxS32 VappGallerySlideShowSetting::getEffectOptionCount() const
{
    return sizeof(VappGallerySlideShowSetting::g_effectOption) / sizeof(VappGallerySlideShowSetting::g_effectOption[0]);
}

VcpPageEffectType VappGallerySlideShowSetting::getEffectByOptionIndex(VfxS32 idx)
{
    if(idx < 0 || idx >= getEffectOptionCount())
    {
        return VCP_PAGE_EFFECT_NONE;
    }
    return g_effectOption[idx].effectType;
}

MMI_STR_ID VappGallerySlideShowSetting::getEffectNameByOptionIndex(VfxS32 idx)
{
    if(idx < 0 || idx >= getEffectOptionCount())
    {
        return NULL;
    }
    return g_effectOption[idx].nameId;
}

void VappGallerySlideShowSetting::setSelectedEffectOptionIndex(VfxS32 idx)
{
    if(idx < 0 || idx >= getEffectOptionCount())
    {
        VFX_ASSERT(VFX_FALSE); // index out of bound
        return;
    }

    m_effectOptionIndex = idx;
}

VfxS32 VappGallerySlideShowSetting::getSelectedEffectOptionIndex() const
{
    return m_effectOptionIndex;
}

VfxMsec VappGallerySlideShowSetting::getTransitionDuration() const
{
    return TRANSITION_TIME_MSEC;
}

void VappGallerySlideShowSetting::readFromNVRAM()
{
    // read MMI_CACHE
    VfxS16 sError = 0;
    VfxU8 delaySecond = 1;
    ReadValue(NVRAM_VAPP_GALLERY_SLD_DELAY_SEC, (void*)&delaySecond, DS_BYTE, &sError);
    ReadValue(NVRAM_VAPP_GALLERY_SLD_TRANSITION_ENUM, (void*)&m_effectOptionIndex, DS_SHORT, &sError);
    ReadValue(NVRAM_VAPP_GALLERY_SLD_IS_SHUFFLE, (void*)&m_isShuffle, DS_BYTE, &sError);
    ReadValue(NVRAM_VAPP_GALLERY_SLD_IS_REPEAT, (void*)&m_isRepeat, DS_BYTE, &sError);
    // search for user-set index
    // return 0 (first index; default) if not found
    VfxS32 selectedIndex = vfxMin((VfxS32)2, getDelayOptionCount() - 1);
    const VfxMsec selectedMsec = delaySecond * MSEC_PER_SEC;
    for(VfxS32 i = 0; i < getDelayOptionCount(); ++i)
    {
        if(selectedMsec == g_delayOption[i])
        {
            selectedIndex = i;
            break;
        }
    }
    m_delaySecondOptionIndex = selectedIndex;
}
#endif
/*****************************************************************************
 * VappGallerySettingEffectPage Implementation
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
VFX_IMPLEMENT_CLASS("VappGallerySettingEffectPage", VappGallerySettingEffectPage, VfxPage);
void VappGallerySettingEffectPage::onInit()
{
    VfxPage::onInit(); // call base class

    // title bar
    VcpTitleBar *bar = NULL;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_SETTING_SLIDE_TRANSITION_CAPTION));
    setTopBar(bar);

    // effect option list
    VFX_OBJ_CREATE(m_pEffectMenu, VcpListMenu, this);
    m_pEffectMenu->setSize(getSize());
    m_pEffectMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_pEffectMenu->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK, VFX_FALSE);
    m_pEffectMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
    m_pEffectMenu->m_signalItemTapped.connect(this, &VappGallerySettingEffectPage::onItemTapped);
    m_pEffectMenu->m_signalItemSelectionStateChanged.connect(this, &VappGallerySettingEffectPage::onItemSelectionChanged);
    m_pEffectMenu->m_signalCmdButtonClicked.connect(this, &VappGallerySettingEffectPage::onPreviewBtnTapped);
    if(m_pSettingProxy)
    {
        m_pEffectMenu->setContentProvider(this);
    }
}

void VappGallerySettingEffectPage::onItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(m_pSettingProxy);
    m_pSettingProxy->setSelectedEffectOptionIndex(index);
    m_pSettingProxy->flushToNVRAM();
    exit();
}

void VappGallerySettingEffectPage::onPreviewBtnTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(m_pSettingProxy);
    VcpPageEffectType effectType = m_pSettingProxy->getEffectByOptionIndex(index);
    VappGallerySlideshowPreviewPage *previewPage = NULL;
    VFX_OBJ_CREATE(previewPage, VappGallerySlideshowPreviewPage, getMainScr());
    previewPage->setEffect(effectType);
    getMainScr()->pushPage(0, previewPage);
}

void VappGallerySettingEffectPage::onItemSelectionChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    VFX_UNUSED(sender);
    VFX_UNUSED(index);
    VFX_UNUSED(newState);
}

class VappGallerySettingDummyMenuControl : public VcpListMenuCellBaseControl
{
// Method
public:
    // <group DOM_ListMenu_VcpListMenuCellBaseControl_Method>
    // Show the control, sub-class need to override it
    virtual void show()
    {
        return;
    }

    // <group DOM_ListMenu_VcpListMenuCellBaseControl_Method>
    // Hide the control, sub-class need to override it
    virtual void hide()
    {
        return;
    }
};

VcpListMenuCellBaseControl *VappGallerySettingEffectPage::getItemCustomControl(VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VfxFrame *parentFrame)
{
    VappGallerySlideShowSetting s;
    if(VCP_PAGE_EFFECT_NONE == s.getEffectByOptionIndex(index) && VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL == location)
    {
        VappGallerySettingDummyMenuControl *dummy;
        VFX_OBJ_CREATE(dummy, VappGallerySettingDummyMenuControl, parentFrame);
        return dummy;
    }

    return NULL;
}

void VappGallerySettingEffectPage::closeItemCustomControl(VfxU32 index, VcpListMenuCellControlLocationTypeEnum location, VcpListMenuCellBaseControl *cellControl)
{
    if(VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL == location)
    {
        VFX_OBJ_CLOSE(cellControl);
    }
    else
    {
        IVcpListMenuContentProvider::closeItemCustomControl(index, location, cellControl);
    }
}
#endif
/*****************************************************************************
 * VappGallerySlideshowPreviewPage Implementation
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
VFX_IMPLEMENT_CLASS("VappGallerySlideshowPreviewPage", VappGallerySlideshowPreviewPage, VfxPage);
VappGallerySlideshowPreviewPage::VappGallerySlideshowPreviewPage():
    m_effectType(VCP_PAGE_EFFECT_NONE),
    m_previewPanel(NULL),
    m_outFrame(NULL),
    m_inFrame(NULL),
    m_isPlaying(VFX_FALSE)
{

}

void VappGallerySlideshowPreviewPage::onEnter(VfxBool isBack)
{
    if(m_previewPanel)
    {
        return;
    }

    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // create preview panel
    VFX_OBJ_CREATE(m_previewPanel, VcpPagePanel, this);
    m_previewPanel->setPos(0, 0);
    m_previewPanel->setSize(getSize());
    m_previewPanel->m_signalFinished.connect(this, &VappGallerySlideshowPreviewPage::onEffectFinish);

    VFX_OBJ_CREATE(m_inFrame, VfxControl, m_previewPanel);
    m_inFrame->setSize(getSize());
    m_inFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_SLD_TRANS_B));

    VFX_OBJ_CREATE(m_outFrame, VfxFrame, m_previewPanel);
    m_outFrame->setSize(getSize());
    m_outFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_SLD_TRANS_A));

    m_previewPanel->setCurrentFrame(m_outFrame);

    return VfxPage::onEnter(isBack);
}

void VappGallerySlideshowPreviewPage::onEntered()
{
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return VfxPage::onEntered();
    }

    m_isPlaying = VFX_TRUE;
    play();
    return VfxPage::onEntered();
}

void VappGallerySlideshowPreviewPage::onExit(VfxBool isBack)
{
    m_isPlaying = VFX_FALSE;
    return VfxPage::onExit(isBack);
}

void VappGallerySlideshowPreviewPage::onExited2()
{
    VFX_OBJ_CLOSE(m_inFrame);
    VFX_OBJ_CLOSE(m_outFrame);
    VFX_OBJ_CLOSE(m_previewPanel);
    return VfxPage::onExited2();
}

VfxBool VappGallerySlideshowPreviewPage::onPenInput(VfxPenEvent &event)
{
    // simply leave the preview page
    exit();
    return VfxPage::onPenInput(event);
}

void VappGallerySlideshowPreviewPage::setEffect(VcpPageEffectType effectType)
{
    m_effectType = effectType;
}

void VappGallerySlideshowPreviewPage::onEffectFinish(VfxFrame *target, VfxBool isCompleted)
{
    if(m_isPlaying)
    {
        play();
    }
}

void VappGallerySlideshowPreviewPage::play()
{
    if(NULL == m_previewPanel)
    {
        return;
    }

    VfxFrame *curFrame = m_previewPanel->getCurrentFrame();
    VfxFrame *nextFrame = (curFrame == m_outFrame) ? m_inFrame : m_outFrame;
    m_previewPanel->switchTo(
        nextFrame,
        m_effectType,
        VappGallerySlideShowSetting::TRANSITION_TIME_MSEC,
        VCP_PAGE_DIRECTION_FROM_RIGHT);
}
#endif
/*****************************************************************************
 * Class VappGalleryStreamingSettingPage
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__

VFX_IMPLEMENT_CLASS("VappGalleryStreamingSettingPage", VappGalleryStreamingSettingPage, VfxPage);
VappGalleryStreamingSettingPage::VappGalleryStreamingSettingPage() :
    m_daCuiId(GRP_ID_INVALID),
    m_simAccountCell(NULL)
{
}

void VappGalleryStreamingSettingPage::onInit()
{
    VfxPage::onInit();

    // Get setting data
    VappGalleryStreamingSetting streamingSetting;

    // Create title bar
    VcpTitleBar *titleBar = NULL;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_GLOBAL_DATA_ACCOUNT));
    setTopBar(titleBar);

    // Create form
    VcpForm *form = NULL;
    VFX_OBJ_CREATE(form, VcpForm, this);
    form->setSize(getSize());
    form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    // Create "Default data account" item
    VFX_ASSERT(NULL == m_simAccountCell);
    VFX_OBJ_CREATE(m_simAccountCell, VcpFormItemLauncherCell, this);
    m_simAccountCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    m_simAccountCell->setMainText(VFX_WSTR_RES(STR_GLOBAL_DATA_CONN_SETTING));
    m_simAccountCell->m_signalTap.connect(this, &VappGalleryStreamingSettingPage::onSetDefaultDataAccount);

    // diable m_simAccountCell while there is no SIM inserted
    m_simAccountCell->setIsDisabled(!srv_sim_ctrl_any_sim_is_available());
    form->addItem(m_simAccountCell, 'SIMS');
}

void VappGalleryStreamingSettingPage::onDeinit()
{
    if(GRP_ID_INVALID != m_daCuiId)
    {
        vcui_dtcnt_select_close(m_daCuiId);
        m_daCuiId = GRP_ID_INVALID;
        // unregister account event
        mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_ACCT_DELETE_IND, onDataAccountChangeEvent, getObjHandle());
        mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND, onDataAccountChangeEvent, getObjHandle());
    }

    VfxPage::onDeinit();
}

void VappGalleryStreamingSettingPage::onSetDefaultDataAccount(VcpFormItemCell *obj, VfxId id)
{
    if('SIMS' != id)
    {
        return;
    }

	// Create data account selection CUI
	VfxId appId = getApp()->getGroupId();
    m_daCuiId = vcui_dtcnt_select_create(appId);

    if(GRP_ID_INVALID == m_daCuiId)
    {
        // Fail to create CUI
        return;
    }

    // set CUI event handler
    mmi_frm_group_set_caller_proc(m_daCuiId, &onDataAccontCUIEvent, getObjHandle());

    // register DA change event to properly refresh DA CUI
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_DELETE_IND, onDataAccountChangeEvent, getObjHandle());
    mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND, onDataAccountChangeEvent, getObjHandle());


    // Set CUI parameter from setting
    VappGalleryStreamingSetting streamingSetting;
    cui_dtcnt_select_run_struct cuiParam;
    kal_mem_set(&cuiParam, 0, sizeof(cuiParam));


    cuiParam.bearers = DATA_ACCOUNT_BEARER_PS_ONLY; // We don't want Circuit Switch accounts
    cuiParam.app_id = VappGalleryApp::getCBMAppId();
    // Note: rely on the fact that CBM_SIM_ID_SIM1 starts from 0 ~ MMI_MAX_SIM_NUM
    cuiParam.sim_account_id[0] = streamingSetting.getSimAccount(CBM_SIM_ID_SIM1);
#if (MMI_MAX_SIM_NUM > 1)
    cuiParam.sim_account_id[1] = streamingSetting.getSimAccount(CBM_SIM_ID_SIM2);
#endif
#if (MMI_MAX_SIM_NUM > 2)
    cuiParam.sim_account_id[2] = streamingSetting.getSimAccount(CBM_SIM_ID_SIM3);
#endif
#if (MMI_MAX_SIM_NUM > 3)
    cuiParam.sim_account_id[3] = streamingSetting.getSimAccount(CBM_SIM_ID_SIM4);
#endif
    cuiParam.option = (cui_dtcnt_select_option_enum)(CUI_DTCNT_SELECT_SIM | CUI_DTCNT_SELECT_NOT_SUBSCRIBE_ACCOUNT);
    cuiParam.type = CUI_DTCNT_SELECT_TYPE_NORMAL;
    cuiParam.sim_selection = CUI_DTCNT_SELECT_SIM_ALL;

    vcui_dtcnt_select_set_param(m_daCuiId, &cuiParam);
    vcui_dtcnt_select_run(m_daCuiId);
}


mmi_ret VappGalleryStreamingSettingPage::onDataAccontCUIEvent(mmi_event_struct *evt)
{
    VappGalleryStreamingSettingPage *pThis = (VappGalleryStreamingSettingPage*)handleToObject((VfxObjHandle)evt->user_data);
    if(NULL == pThis)
    {
        return MMI_OK;
    }

    return pThis->handleDataAccountCUIEvent(evt);
}

mmi_ret VappGalleryStreamingSettingPage::onDataAccountChangeEvent(mmi_event_struct *evt)
{
    VappGalleryStreamingSettingPage *pThis = (VappGalleryStreamingSettingPage*)handleToObject((VfxObjHandle)evt->user_data);
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }

    return pThis->handleDataAccountChangeEvent(evt);
}

mmi_ret VappGalleryStreamingSettingPage::handleDataAccountChangeEvent(mmi_event_struct *param)
{
    if(GRP_ID_INVALID == m_daCuiId)
    {
        return MMI_RET_OK;
    }

    switch (param->evt_id)
    {
    case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:
        if(sizeof(srv_dtcnt_acct_update_ind_evt_struct) != param->size)
        {
            break;
        }
        else
        {
            const srv_dtcnt_acct_update_ind_evt_struct *updateEvt = (srv_dtcnt_acct_update_ind_evt_struct*)param;
            if(0 == updateEvt->cause)
            {
                // if user update, no need to refresh CUI
                break;
            }

            // refresh CUI to new setting
            vcui_dtcnt_select_set_account_id(m_daCuiId, (cui_dtcnt_sim_enum)updateEvt->sim_id, updateEvt->acc_id);
        }
        break;
    case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
        if(sizeof(srv_dtcnt_acct_delete_ind_evt_struct) != param->size)
        {
            break;
        }
        else
        {
            const srv_dtcnt_acct_delete_ind_evt_struct *deleteEvt = (srv_dtcnt_acct_delete_ind_evt_struct*)param;
            if(0 == deleteEvt->cause)
            {
                // if user update, no need to refresh CUI
                break;
            }

            for(VfxS32 i = 0; i < deleteEvt->del_num; ++i)
            {
                vcui_dtcnt_select_set_account_id(m_daCuiId, (cui_dtcnt_sim_enum)deleteEvt->sim_id[i], 0);
            }
        }
        break;
    }
    return MMI_RET_OK;
}

mmi_ret VappGalleryStreamingSettingPage::handleDataAccountCUIEvent(mmi_event_struct *evt)
{
    VfxBool closeCui = VFX_TRUE;
    VappGalleryStreamingSetting streamingSetting;

    switch (evt->evt_id)
    {
    case CUI_DTCNT_SELECT_EVENT_ANY_SIM_ACCOUNT_SELECTED:
        {
			cui_dtcnt_select_event_any_sim_selected_struct *daSelectResult = reinterpret_cast<cui_dtcnt_select_event_any_sim_selected_struct*>(evt);
			closeCui = VFX_FALSE;
			switch (daSelectResult->selectSim)
			{
			case CUI_DTCNT_SIM1:
				streamingSetting.setSimAccount(
									CUI_DTCNT_SIM1,
									daSelectResult->accountId);
				break;
			case CUI_DTCNT_SIM2:
				streamingSetting.setSimAccount(
									CUI_DTCNT_SIM2,
									daSelectResult->accountId);
				break;
			case CUI_DTCNT_SIM3:
				streamingSetting.setSimAccount(
									CUI_DTCNT_SIM3,
									daSelectResult->accountId);
				break;
			case CUI_DTCNT_SIM4:
				streamingSetting.setSimAccount(
									CUI_DTCNT_SIM4,
									daSelectResult->accountId);
				break;
			default:
				break;
			}
        }
        // continue following action
    case CUI_DTCNT_SELECT_EVENT_RESULT_OK:
    case CUI_DTCNT_SELECT_EVENT_RESULT_CANCEL:
    case CUI_DTCNT_SELECT_EVENT_RESULT_FAILED:
    case CUI_DTCNT_SELECT_EVENT_CLOSE:
        if(closeCui)
        {
            vcui_dtcnt_select_close(m_daCuiId);
            m_daCuiId = GRP_ID_INVALID;
            // unregister account event
            mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_ACCT_DELETE_IND, onDataAccountChangeEvent, getObjHandle());
            mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND, onDataAccountChangeEvent, getObjHandle());
        }
        break;
    }

    return MMI_RET_DONT_CARE;
}
#endif //__VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__

/*****************************************************************************
 * Class VappGalleryStreamingSetting
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_STREAMING__
extern "C"
{
S32 vapp_gallery_stream_dtcnt_acct_event_handler(mmi_event_struct* param);
}

S32 vapp_gallery_stream_dtcnt_acct_event_handler(mmi_event_struct* param)
{
    if(NULL == param)
    {
        return MMI_RET_OK;
    }

    switch(param->evt_id)
    {
    case EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND:
        if(sizeof(srv_dtcnt_acct_update_ind_evt_struct) != param->size)
        {
            break;
        }
        else
        {
            const srv_dtcnt_acct_update_ind_evt_struct *updateEvt = (srv_dtcnt_acct_update_ind_evt_struct*)param;
            VappGalleryStreamingSetting setting;
            setting.invalidateAccountId(updateEvt->acc_id);
        }
        break;
    case EVT_ID_SRV_DTCNT_ACCT_DELETE_IND:
        if(sizeof(srv_dtcnt_acct_delete_ind_evt_struct) != param->size)
        {
            break;
        }
        else
        {
            const srv_dtcnt_acct_delete_ind_evt_struct *deleteEvt = (srv_dtcnt_acct_delete_ind_evt_struct*)param;
            VappGalleryStreamingSetting setting;
            for(VfxS32 i = 0; i < deleteEvt->del_num; ++i)
            {
                setting.invalidateAccountId(deleteEvt->acc_id[i]);
            }
        }
        break;
    }

    return MMI_RET_OK;
}

VappGalleryStreamingSetting::VappGalleryStreamingSetting()
{
    readFromNVRAM();
}

VappGalleryStreamingSetting::~VappGalleryStreamingSetting()
{
    flushToNVRAM();
}

VfxU32 VappGalleryStreamingSetting::getActiveAccountId() const
{
    // Get preferred SIM setting
    srv_dtcnt_sim_type_enum preferred_sim = SRV_DTCNT_SIM_TYPE_NONE;
    if(MMI_FALSE == srv_dtcnt_get_sim_preference(&preferred_sim))
    {
        preferred_sim = SRV_DTCNT_SIM_TYPE_1;
    }

    switch (preferred_sim)
    {
    case SRV_DTCNT_SIM_TYPE_1:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_STREAMING_SIM_DATA_ACCOUNT, 1);
        return getSimAccount(0);
    case SRV_DTCNT_SIM_TYPE_2:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_STREAMING_SIM_DATA_ACCOUNT, 1);
        return getSimAccount(1);
    case SRV_DTCNT_SIM_TYPE_3:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_STREAMING_SIM_DATA_ACCOUNT, 3);
        return getSimAccount(2);
    case SRV_DTCNT_SIM_TYPE_4:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_STREAMING_SIM_DATA_ACCOUNT, 4);
        return getSimAccount(3);
    default:
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_STREAMING_SIM_DATA_ACCOUNT, 1);
        return getSimAccount(0);
    }
}

VfxU32 VappGalleryStreamingSetting::verifyAccountId(VfxS32 simCardIdx, VfxU32 dataAccountId) const
{
    VfxU32 verifiedId = dataAccountId;
    if(0 != verifiedId)
    {
        // update run-time App Id
        verifiedId = cbm_set_app_id(dataAccountId, VappGalleryApp::getCBMAppId());
    }

    // check validity, if invalid,
    // use DEFAULT account id
    if(0 == verifiedId ||
       DTCNT_ACCT_VALID_NONE == vapp_dtcnt_acct_is_valid(verifiedId, MMI_FALSE))
    {
        verifiedId = cbm_encode_data_account_id(
                                        CBM_DEFAULT_ACCT_ID,
                                        (cbm_sim_id_enum)simCardIdx,    // convert index to cbm_sim_id_enum
                                        VappGalleryApp::getCBMAppId(),
                                        KAL_FALSE);
    }

    return verifiedId;
}

VfxU32 VappGalleryStreamingSetting::getSimAccount(VfxS32 simCardIndex) const
{
    if(simCardIndex < 0 || simCardIndex >= MMI_MAX_SIM_NUM)
    {
        return 0;
    }

    return verifyAccountId(simCardIndex, m_simDataAccountId[simCardIndex]);
}

void VappGalleryStreamingSetting::setSimAccount(VfxS32 simCardIndex, VfxU32 dataAccountId)
{
    if(simCardIndex < 0 || simCardIndex >= MMI_MAX_SIM_NUM)
    {
        VFX_DEV_ASSERT(0);
        return;
    }

    m_simDataAccountId[simCardIndex] = verifyAccountId(simCardIndex, dataAccountId);
}

U16 VappGalleryStreamingSetting::getCacheIdFromSimIndex(VfxS32 simCardIndex)
{
    switch(simCardIndex)
    {
    case 0:
        return NVRAM_VAPP_GALLERY_STREAM_SIM1_ACCOUNT;
    case 1:
        return NVRAM_VAPP_GALLERY_STREAM_SIM2_ACCOUNT;
    case 2:
        return NVRAM_VAPP_GALLERY_STREAM_SIM3_ACCOUNT;
    case 3:
        return NVRAM_VAPP_GALLERY_STREAM_SIM4_ACCOUNT;
    default:
        return 0;
    }
}

void VappGalleryStreamingSetting::readFromNVRAM()
{
    // Wifi Only option
    VfxS16 sError = 0;

    // Data Account for each SIM card
    for(VfxS32 i = 0; i < MMI_MAX_SIM_NUM; ++i)
    {
        VfxId cacheId = getCacheIdFromSimIndex(i);
        if(0 == cacheId)
        {
            m_simDataAccountId[i] = 0;
            continue;
        }
        // read and truncate account ID from 8-byte to 4-byte
        VfxU64 simAccountValue = 0;
        ReadValue(cacheId, (void*)&simAccountValue, DS_DOUBLE, &sError);
        m_simDataAccountId[i] = static_cast<VfxU32>(simAccountValue);
    }
}

void VappGalleryStreamingSetting::flushToNVRAM()
{
    // Wifi Only option
    VfxS16 sError = 0;

    // Data Account for each SIM card
    for(VfxS32 i = 0; i < MMI_MAX_SIM_NUM; ++i)
    {
        VfxId cacheId = getCacheIdFromSimIndex(i);
        if(0 == cacheId)
        {
            continue;
        }
        // read and truncate account ID from 8-byte to 4-byte
        VfxU64 simAccountValue = verifyAccountId(i, m_simDataAccountId[i]);
        WriteValue(cacheId, (void*)&simAccountValue, DS_DOUBLE, &sError);
    }
}

void VappGalleryStreamingSetting::invalidateAccountId(U32 accountId)
{
    for(VfxS32 i = 0; i < MMI_MAX_SIM_NUM; ++i)
    {
        if(accountId == (U32)cbm_get_original_account(m_simDataAccountId[i]))
        {
            // if match, reset the account id used to default
            m_simDataAccountId[i] = 0;
        }
    }
}
#else
extern "C"
{
S32 vapp_gallery_stream_dtcnt_acct_event_handler(mmi_event_struct* param);
}

S32 vapp_gallery_stream_dtcnt_acct_event_handler(mmi_event_struct* param)
{
    return 0;
}
#endif // __VAPP_GALLERY_ENABLE_STREAMING__
#endif // __MMI_GALLERY_SLIM__
