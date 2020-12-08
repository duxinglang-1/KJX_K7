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
 *  vapp_gallery_index.h
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

#ifndef __VAPP_GALLERY_INDEX_H__
#define __VAPP_GALLERY_INDEX_H__


/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "vfx_mc_include.h"
#include "vcp_include.h"

/*****************************************************************************
 * Gallery Feature Option Define
 *****************************************************************************/
#include "vapp_gallery_slim.h"

#include "vapp_gallery_slim_player.h"
#include "vapp_gallery_slim_picture.h"
#include "vapp_gallery_slim_setting.h"

/*****************************************************************************
 * Enum and constants
 *****************************************************************************/
enum PageName
{
    PN_MY_SHOOTING = 'SHOT',
    PN_MY_PICTURE = 'PICT',
    PN_MY_VIDEO = 'VIDO',
    PN_WEB_ALBUM = 'WEBB',
    PN_SETTING = 'SETT',

    PN_INVALID = -1,
};

/*****************************************************************************
 * Foward declaration
 *****************************************************************************/
class VappGalleryCollectionSetting;

/*****************************************************************************
 * Class
 *****************************************************************************/
// This data structure records differnt menu items in index menu.
class VappGalleryIndexMenuItem
{
public:
    PageName pageName;
    MMI_ID captionStrID;
    MMI_IMG_ID defaultImgID;
    MMI_IMG_ID badgeImgID;
};

class VappGalleryCollectionSetting
{
public:
    VappGalleryCollectionSetting()
    {
        // default no extra filters,
        // use collection defaults.
        FMGR_FILTER_INIT(&m_filter);
        FMGR_FILTER_SET_ALL(&m_filter);

        // read default setting from global option
        VappGalleryStorageSetting setting;
        m_storage = setting.getDefaultStorage();
    }

    U8 getDefaultDrive()
    {
        const U8 drv = srv_fmgr_drv_get_letter_by_type(m_storage);
        return drv;
    }

public:
    srv_fmgr_drv_type_enum m_storage;
    FMGR_FILTER m_filter;
};


class VappGalleryIndexPage : public VappGalleryPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappGalleryIndexPage);

public:
    static const VfxS32 INDEX_MENU_ITEM_COUNT = 3;  // Shooting, Picture, and Video.
    static const VfxS32 INDEX_MENU_ITEM_COUNT_CUI = 2; // Shooting, and only one of Picture and Video

// Override
public:
    VappGalleryIndexPage();
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onExit(VfxBool isBackward);
    virtual void onExited2();

// Implement IVcpListMenuContentProvider
public:
    virtual VfxU32 getCount() const;
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const;

    // Provide custom layout cells
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame);
    virtual void closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *cell);

// methods
public:
    virtual void refreshStorage(VfxBool directRefresh);

protected:
    void onIndexItemTapped(VcpListMenu *sender, VfxU32 index);
    void onGotoPage(PageName pageID);

#ifdef __VAPP_GALLERY_ENABLE_USER_DRIVE__
    void onSelectStorage(VfxObject *sender, VfxId btnId);
#endif
#ifdef __VAPP_GALLERY_ENABLE_SETTING_PAGE__
    void onToolbarCommand(VfxObject *sender, VfxId btnId);
#endif
    // returns Picker CUI instance if hosted
    // under it. NULL if hosted under ordinary APP
    VcuiGalleryPickerBase *getParentPickerCUI() const;

    // returns Picker CUI instance if hosted
    // under it. NULL if hosted under ordinary APP
    VcuiGalleryImagePicker *getParentImagePickerCUI() const;

    // returns Picker CUI instance if hosted
    // under it. NULL if hosted under ordinary APP
    VcuiGalleryVideoPicker *getParentVideoPickerCUI() const;

    // create Page instnaces from a given name
    // and perform page-specific initialization
    VfxPage* createPageFromName(PageName name);

#ifdef __VAPP_GALLERY_ENABLE_USER_DRIVE__
    void createStorageSelectionTab(
                    VfxBool updateStorage    // VFX_TRUE means automatically update storage. Otherwise keep current focus.
                    );
#endif

    // create Page instances from index menu index
    PageName getPageNameFromCellIndex(VfxU32 index);
    VappGalleryIndexMenuItem* getItemInfoFromIndex(VfxU32 index);


    // only update page message (does not requrie FG memory)
    // VFX_FALSE is returned if no further update is required.
    VfxBool handleStorageChangeLite(VappGalleryStorageSetting &storageSetting);

    // initializes DB &  (requires FG memory)
    void handleStorageChange(VappGalleryStorageSetting &storageSetting);
    static mmi_ret onDevicePlugInOut(mmi_event_struct *param);
    mmi_ret handleDevicePlugInOut(mmi_event_struct *param);

private:
    VcpListMenu *m_indexMenu;                           // the menu component
    VfxBool m_shouldRefreshOnEnter;                     // VFX_TRUE if we should refresh the storage upon re-enter
    VfxS32 m_itemIndices[INDEX_MENU_ITEM_COUNT];          // map item order to index in g_indexMenuItems

    // Index item list definition
    static VappGalleryIndexMenuItem g_indexMenuItems[INDEX_MENU_ITEM_COUNT];

};

#endif /* __VAPP_GALLERY_INDEX_H__ */

