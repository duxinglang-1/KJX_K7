/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_gallery_setting.h
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

#ifndef __VAPP_GALLERY_SETTING_H__
#define __VAPP_GALLERY_SETTING_H__


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "mmi_rp_vapp_gallery_def.h"
#include "GlobalResDef.h"
#include "vcp_page_panel.h"
#include "vapp_gallery.h"
#include "vapp_gallery_util.h"
extern "C"
{
#include "FileMgrSrvGprot.h"
#include "FileMgrType.h"
}
#include "cp\vapp_media_list.h"
/*****************************************************************************
 * typedef
 *****************************************************************************/
class VappGallerySlideShowSetting;
/*****************************************************************************
 * Class
 *****************************************************************************/
class VappGalleryStorageSetting
{
public:
    VappGalleryStorageSetting();

    ~VappGalleryStorageSetting();

    // get default storage, if correntInvalidStorage is VFX_TRUE(default),
    // then Phone storage is returned when current default storage is not available.
    srv_fmgr_drv_type_enum getDefaultStorage(VfxBool correntInvalidStorage = VFX_TRUE);
    // set default storage
    void setDefaultStorage(srv_fmgr_drv_type_enum drvType);

protected:
    void readFromNVRAM();
    void flushToNVRAM();

private:
    VfxBool m_dirty;
    srv_fmgr_drv_type_enum m_defaultDriveType;
};
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __VAPP_GALLERY_ENABLE_SETTING_PAGE__
class VappGallerySettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappGallerySettingPage);

    #ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
    VappGallerySlideShowSetting settingProxy;
    VcpFormItemLauncherCell *m_pLaunchDelaySetting;
    VcpFormItemLauncherCell *m_pLaunchTransitionSetting;
    VcpFormItemSwitchCell *m_pShuffleSwitch;
    VcpFormItemSwitchCell *m_pRepeatSwitch;
    #endif

    #ifdef __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__
    VcpFormItemLauncherCell *m_pLaunchStreamingSetting;
    #endif

// Override
public:
    VappGallerySettingPage();
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onUpdate();
    virtual void onExit(VfxBool isBackward);

    static VfxBool isSettingRelatedPage(VfxPage *p);

private:
    VcpForm *options;
    #ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
    void onShuffleChange(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus);
    void onRepeatChange(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus);
    void onPickDelay(VcpFormItemCell* item, VfxId id);
    void onPickEffect(VcpFormItemCell* item, VfxId id);
    #endif
    #ifdef __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__
    void onStreamingSetting(VcpFormItemCell* item, VfxId id);
    #endif
};
#endif // __VAPP_GALLERY_ENABLE_SETTING_PAGE__

/*****************************************************************************
 * Slideshow setting 
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__
class VappGallerySettingDelayPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappGallerySettingDelayPage);

    VappGallerySlideShowSetting *m_pSettingProxy;
    VcpListMenu *m_pDelayMenu;

// supporting list menu
public:
    VappGallerySettingDelayPage():
        m_pSettingProxy(NULL),
        m_pDelayMenu(NULL)
    {
    }

    virtual ~VappGallerySettingDelayPage()
    {
        m_pSettingProxy = NULL;
        m_pDelayMenu = NULL;
    }

    void setSettingProxy(VappGallerySlideShowSetting *pSetting)
    {
        m_pSettingProxy = pSetting;
        if(m_pDelayMenu)
        {
            m_pDelayMenu->setContentProvider(m_pSettingProxy ? this : NULL);
        }
    }

// Override
public:
    virtual void onInit();

// supporting list menu
public:
    void onItemTapped(VcpListMenu *sender, VfxU32 index);
    void onItemSelectionChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState);

    virtual VfxU32 getCount() const
    {
        VFX_DEV_ASSERT(m_pSettingProxy);
        return m_pSettingProxy->getDelayOptionCount();
    }

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
    {
        VFX_DEV_ASSERT(m_pSettingProxy);
        if(VCP_LIST_MENU_FIELD_TEXT ==  fieldType)
        {
            VfxS32 sec = m_pSettingProxy->getDelayTimeByOptionIndex(index) / 1000;
            text.format("%d ", sec);
            text += VFX_WSTR_RES(sec > 1 ? STR_ID_VAPP_GALLERY_SETTING_SECS : STR_ID_VAPP_GALLERY_SETTING_SEC);
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index
        ) const
    {
        VFX_DEV_ASSERT(m_pSettingProxy);
        if (m_pSettingProxy->getSelectedDelayOptionIndex() == index)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }

};

class VappGallerySettingEffectPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappGallerySettingEffectPage);

    VappGallerySlideShowSetting *m_pSettingProxy;
    VcpListMenu *m_pEffectMenu;

// supporting list menu
public:
    VappGallerySettingEffectPage():
        m_pSettingProxy(NULL),
        m_pEffectMenu(NULL)
    {
    }

    virtual ~VappGallerySettingEffectPage()
    {
        m_pSettingProxy = NULL;
        m_pEffectMenu = NULL;
    }

    void setSettingProxy(VappGallerySlideShowSetting *pSetting)
    {
        m_pSettingProxy = pSetting;
        if(m_pEffectMenu)
        {
            m_pEffectMenu->setContentProvider(m_pSettingProxy ? this : NULL);
        }
    }

// Override
public:
    virtual void onInit();

// supporting list menu
public:
    void onItemTapped(VcpListMenu *sender, VfxU32 index);
    void onPreviewBtnTapped(VcpListMenu *sender, VfxU32 index);
    void onItemSelectionChanged(VcpListMenu *sender, VfxU32 index, VcpListMenuItemStateEnum newState);

    virtual VfxU32 getCount() const
    {
        VFX_DEV_ASSERT(m_pSettingProxy);
        return m_pSettingProxy->getEffectOptionCount();
    }

    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        )
    {
        VFX_DEV_ASSERT(m_pSettingProxy);
        if(VCP_LIST_MENU_FIELD_TEXT ==  fieldType)
        {
            text = VFX_WSTR_RES(m_pSettingProxy->getEffectNameByOptionIndex(index));
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index
        ) const
    {
        VFX_DEV_ASSERT(m_pSettingProxy);
        if (m_pSettingProxy->getSelectedEffectOptionIndex() == index)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }

    virtual VcpListMenuCellBaseControl *getItemCustomControl(
                                                VfxU32 index,                                       // [IN] index of the item
                                                VcpListMenuCellControlLocationTypeEnum location,    // [IN] Control location
                                                VfxFrame *parentFrame                               // [IN] parent frame of the custom content frame
                                                );

    virtual void closeItemCustomControl(
        VfxU32 index,                                       // [IN] index of the item
        VcpListMenuCellControlLocationTypeEnum location,    // [IN] Control location
        VcpListMenuCellBaseControl *cellControl             // [IN] the content frame to be released
        );

    virtual VfxBool getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image              // [OUT] the image resource
        )
    {
        VfxId imgId = 0;
        switch(fieldType)
        {
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL:
            imgId = IMG_ID_VAPP_GALLERY_SLD_PREV_PLAY_N;
            break;
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED:
            imgId = IMG_ID_VAPP_GALLERY_SLD_PREV_PLAY_P;
            break;
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED:
            imgId = IMG_ID_VAPP_GALLERY_SLD_PREV_PLAY_D;
            break;
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT:
            imgId = IMG_ID_VAPP_GALLERY_SLD_PREV_PLAY_P;
            break;
        default:
            break;
        }

        if(0 == imgId)
        {
            return VFX_FALSE;
        }
        else
        {
            image.setResId(imgId);
            return VFX_TRUE;
        }
    }

};

class VappGallerySlideshowPreviewPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappGallerySlideshowPreviewPage);
public:
    VappGallerySlideshowPreviewPage();

// override
public:
    virtual void onEnter(VfxBool isBack);
    virtual void onEntered();
    virtual void onExit(VfxBool isBack);
    virtual void onExited2();

public:
    void setEffect(VcpPageEffectType effectType);
    void play();

protected:
    virtual VfxBool onPenInput(VfxPenEvent &event);
    void onEffectFinish(VfxFrame *target, VfxBool isCompleted);
protected:
    VcpPageEffectType m_effectType;
    VcpPagePanel *m_previewPanel;
    VfxFrame *m_outFrame;   // the "A" frame of transition
    VfxFrame *m_inFrame;    // the "B" frame of transition
    VappGallerySlideShowSetting m_setting;
    VfxBool m_isPlaying;
};
#endif // __VAPP_GALLERY_ENABLE_SLIDESHOW_SETTING_PAGE__


/*****************************************************************************
 * Streaming setting 
 *****************************************************************************/
#ifdef __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__
class VappGalleryStreamingSettingPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappGalleryStreamingSettingPage);

    VfxId m_daCuiId;
    VcpFormItemLauncherCell *m_simAccountCell;

public:
    VappGalleryStreamingSettingPage();
    virtual void onInit();
    virtual void onDeinit();

private:
    void onSetDefaultDataAccount(VcpFormItemCell *obj, VfxId id);
    mmi_ret handleDataAccountCUIEvent(mmi_event_struct *evt);        // handle CUI event
    mmi_ret handleDataAccountChangeEvent(mmi_event_struct *evt);     // handle DA account change event (not from CUI)

    static mmi_ret onDataAccontCUIEvent(mmi_event_struct *evt);      // handle CUI event
    static mmi_ret onDataAccountChangeEvent(mmi_event_struct *evt);  // handle DA account change event (not from CUI)
};
#endif // __VAPP_GALLERY_ENABLE_STREAMING_SETTING_PAGE__

#endif /* __VAPP_GALLERY_SETTING_H__ */

