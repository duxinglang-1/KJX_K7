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
 *  vapp_gallery_index.cpp
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

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_GALLERY_SLIM__
#include "mmi_rp_vapp_gallery_def.h"
#include "mmi_rp_vapp_fmgr_def.h"
#include "vapp_gallery_slim_index.h"
#include "vapp_gallery_slim_data.h"
#include "vapp_gallery_slim_setting.h"
#include "vapp_gallery_slim_shooting.h"
#include "vapp_gallery_slim_picture.h"
#include "vapp_gallery_slim_video.h"
#include "vapp_gallery_slim_util.h"
#include "vapp_gallery_slim_file_operation.h"
#include "vcp_include.h"
#include "vcp_tab_title_bar.h"
#include "../xml/vfx_xml_loader.h"
extern "C"
{
#include "MMI_media_app_trc.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
}

/*****************************************************************************
 * Define
 *****************************************************************************/
static const VfxMsec ANIM_SLOW_TIMING = 500;

#if defined(__MMI_MAINLCD_320X480__)
class IndexPageLayout
{
public:
    const static VfxS32 MENU_H = 71;            // height of menu item

    const static VfxS32 ICON_W = 67;            // size of the entire "rotated" background
    const static VfxS32 ICON_H = 67;            // size of the entire "rotated" background

    const static VfxS32 BACK_THUMB_W = 48;      // image thumbnail size (for back)
    const static VfxS32 BACK_THUMB_H = 48;
    const static VfxS32 BACK_THUMB_CX = (ICON_W  / 2 - 1);
    const static VfxS32 BACK_THUMB_CY = (ICON_H  / 2 - 1);
    const static VfxS32 BACK_THUMB_ANGLE = 18;

    const static VfxS32 FRONT_THUMB_W = 50;
    const static VfxS32 FRONT_THUMB_H = 50;
    const static VfxS32 FRONT_THUMB_CX = (ICON_W - FRONT_THUMB_W) / 2;
    const static VfxS32 FRONT_THUMB_CY = (ICON_W - FRONT_THUMB_W) / 2;

    const static VfxS32 FRONT_BORDER_W = 56;
    const static VfxS32 FRONT_BORDER_H = 56;

    const static VfxS32 BADGE_MARGIN_R = 12;
    const static VfxS32 BADGE_MARGIN_D = 12;

    const static VfxS32 ICON_MARGIN_L = 5;      // left of entire collage
    const static VfxS32 ICON_MARGIN_T = 3;      // top of entire collage

    const static VfxS32 TEXT_MARGIN_L = 82;
    const static VfxS32 TEXT_W = 230;
    const static VfxS32 TEXT_CAPTION_H = 24;
    const static VfxS32 TEXT_DESC_H = 15;
    const static VfxU32 TEXT_CAPTION_COLOR = 0xff151515;
    const static VfxU32 TEXT_DESC_COLOR = 0xff505050;
    const static VfxS32 DESC_FADEIN_OFFSET = 5;

    const static VfxS32 FONT_SIZE_CAPTION = VCP_LIST_MENU_FONT_SIZE_MEDIUM;
    const static VfxS32 FONT_SIZE_DESC = VCP_LIST_MENU_FONT_SIZE_SMALL;

    const static VfxS32 FONT_SIZE_LAST_PLAY_CAPTION = 13;
    const static VfxS32 FONT_SIZE_LAST_PLAY_FILENAME = 14;
    const static VfxS32 FONT_SIZE_LAST_PLAY_TIME = 12;

    const static VfxS32 PAD_TWO_LINE = 4; // 3
    const static VfxS32 PAD_THREE_LINE = 3;  // 2
};

#elif defined(__MMI_MAINLCD_480X800__)

class IndexPageLayout
{
public:
    const static VfxS32 MENU_H = 114;

    const static VfxS32 ICON_W = 105;
    const static VfxS32 ICON_H = 106;

    const static VfxS32 BACK_THUMB_W = 78;
    const static VfxS32 BACK_THUMB_H = 78;
    const static VfxS32 BACK_THUMB_CX = (ICON_W  / 2 - 1);
    const static VfxS32 BACK_THUMB_CY = (ICON_H  / 2 - 1);
    const static VfxS32 BACK_THUMB_ANGLE = 18;

    const static VfxS32 FRONT_THUMB_W = 80;
    const static VfxS32 FRONT_THUMB_H = 82;
    const static VfxS32 FRONT_THUMB_CX = (ICON_W - FRONT_THUMB_W) / 2;
    const static VfxS32 FRONT_THUMB_CY = (ICON_W - FRONT_THUMB_W) / 2;

    const static VfxS32 FRONT_BORDER_W = 87;
    const static VfxS32 FRONT_BORDER_H = 90;

    const static VfxS32 BADGE_MARGIN_R = 15;
    const static VfxS32 BADGE_MARGIN_D = 15;

    const static VfxS32 ICON_MARGIN_L = 5;
    const static VfxS32 ICON_MARGIN_T = 4;

    const static VfxS32 TEXT_MARGIN_L = 122;
    const static VfxS32 TEXT_W = 440;
    const static VfxS32 TEXT_CAPTION_H = 35;
    const static VfxS32 TEXT_DESC_H = 23;
    const static VfxU32 TEXT_CAPTION_COLOR = 0xff151515;
    const static VfxU32 TEXT_DESC_COLOR = 0xff505050;
    const static VfxS32 DESC_FADEIN_OFFSET = 8;

    const static VfxS32 FONT_SIZE_CAPTION = VCP_LIST_MENU_FONT_SIZE_MEDIUM;
    const static VfxS32 FONT_SIZE_DESC = VCP_LIST_MENU_FONT_SIZE_SMALL;

    const static VfxS32 FONT_SIZE_LAST_PLAY_CAPTION = 20;
    const static VfxS32 FONT_SIZE_LAST_PLAY_FILENAME = 22;
    const static VfxS32 FONT_SIZE_LAST_PLAY_TIME = 18;

    const static VfxS32 PAD_TWO_LINE = 6; // 3
    const static VfxS32 PAD_THREE_LINE = 4;  // 2
};

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
class IndexPageLayout
{
public:
    const static VfxS32 MENU_H = 59;

    const static VfxS32 ICON_W = 54;
    const static VfxS32 ICON_H = 54;

    const static VfxS32 BACK_THUMB_W = 40;
    const static VfxS32 BACK_THUMB_H = 40;
    const static VfxS32 BACK_THUMB_CX = (ICON_W  / 2 + 1);
    const static VfxS32 BACK_THUMB_CY = (ICON_H  / 2 - 2);
    const static VfxS32 BACK_THUMB_ANGLE = 18;

    const static VfxS32 FRONT_THUMB_W = 40;
    const static VfxS32 FRONT_THUMB_H = 40;
    const static VfxS32 FRONT_THUMB_CX = (ICON_W - FRONT_THUMB_W) / 2;
    const static VfxS32 FRONT_THUMB_CY = (ICON_W - FRONT_THUMB_W) / 2 - 1;

    const static VfxS32 FRONT_BORDER_W = 45;
    const static VfxS32 FRONT_BORDER_H = 46;

    const static VfxS32 BADGE_MARGIN_R = 9;
    const static VfxS32 BADGE_MARGIN_D = 10;

    const static VfxS32 ICON_MARGIN_L = 5;
    const static VfxS32 ICON_MARGIN_T = 4;

    const static VfxS32 TEXT_MARGIN_L = 70;
    const static VfxS32 TEXT_W = 160;
    const static VfxS32 TEXT_CAPTION_H = 20;
    const static VfxS32 TEXT_DESC_H = 13;
    const static VfxU32 TEXT_CAPTION_COLOR = 0xff151515;
    const static VfxU32 TEXT_DESC_COLOR = 0xff505050;
    const static VfxS32 DESC_FADEIN_OFFSET = 8;

    const static VfxS32 FONT_SIZE_CAPTION = VCP_LIST_MENU_FONT_SIZE_MEDIUM;
    const static VfxS32 FONT_SIZE_DESC = VCP_LIST_MENU_FONT_SIZE_SMALL;

    const static VfxS32 FONT_SIZE_LAST_PLAY_CAPTION = 13;
    const static VfxS32 FONT_SIZE_LAST_PLAY_FILENAME = 12;
    const static VfxS32 FONT_SIZE_LAST_PLAY_TIME = 12;

    const static VfxS32 PAD_TWO_LINE = 2;
    const static VfxS32 PAD_THREE_LINE = 1;
};

#else

// prevent compile error for undefined resolution
class IndexPageLayout
{
public:
    const static VfxS32 MENU_H = 71;

    const static VfxS32 ICON_W = 67;
    const static VfxS32 ICON_H = 67;

    const static VfxS32 BACK_THUMB_W = 48;
    const static VfxS32 BACK_THUMB_H = 48;
    const static VfxS32 BACK_THUMB_CX = (ICON_W  / 2 - 1);
    const static VfxS32 BACK_THUMB_CY = (ICON_H  / 2 - 1);
    const static VfxS32 BACK_THUMB_ANGLE = 18;

    const static VfxS32 FRONT_THUMB_W = 50;
    const static VfxS32 FRONT_THUMB_H = 50;
    const static VfxS32 FRONT_THUMB_CX = (ICON_W - FRONT_THUMB_W) / 2;
    const static VfxS32 FRONT_THUMB_CY = (ICON_W - FRONT_THUMB_W) / 2;

    const static VfxS32 FRONT_BORDER_W = 56;
    const static VfxS32 FRONT_BORDER_H = 56;

    const static VfxS32 BADGE_MARGIN_R = 12;
    const static VfxS32 BADGE_MARGIN_D = 12;

    const static VfxS32 ICON_MARGIN_L = 5;
    const static VfxS32 ICON_MARGIN_T = 3;

    const static VfxS32 TEXT_MARGIN_L = 82;
    const static VfxS32 TEXT_W = 230;
    const static VfxS32 TEXT_CAPTION_H = 24;
    const static VfxS32 TEXT_DESC_H = 13;
    const static VfxU32 TEXT_CAPTION_COLOR = 0xff151515;
    const static VfxU32 TEXT_DESC_COLOR = 0xff505050;
    const static VfxS32 DESC_FADEIN_OFFSET = 5;

    const static VfxS32 FONT_SIZE_CAPTION = VCP_LIST_MENU_FONT_SIZE_MEDIUM;
    const static VfxS32 FONT_SIZE_DESC = VCP_LIST_MENU_FONT_SIZE_SMALL;

    const static VfxS32 FONT_SIZE_LAST_PLAY_CAPTION = 13;
    const static VfxS32 FONT_SIZE_LAST_PLAY_FILENAME = 14;
    const static VfxS32 FONT_SIZE_LAST_PLAY_TIME = 12;

    const static VfxS32 PAD_TWO_LINE = 4; // 3
    const static VfxS32 PAD_THREE_LINE = 3;  // 2
};
#endif

VappGalleryIndexMenuItem VappGalleryIndexPage::g_indexMenuItems[3] = {\
    // Page name     Collection factory     Title                              Default icon                            Badge (on the thumbnail)
    {PN_MY_SHOOTING,    STR_ID_VAPP_GALLERY_IDX_SHOOTING,  IMG_ID_VAPP_GALLERY_IDX_SHOOTING_ICON,  NULL},
    {PN_MY_PICTURE,    STR_ID_VAPP_GALLERY_IDX_PICTURE,   IMG_ID_VAPP_GALLERY_IDX_PICTURE_ICON,   NULL},
    {PN_MY_VIDEO,    STR_ID_VAPP_GALLERY_IDX_VIDEO,     IMG_ID_VAPP_GALLERY_IDX_VIDEO_ICON,     NULL},
};

class VappGalleryIndexItemCell : public VcpListMenuCellClientBaseFrame
{
private:
    static const VfxS32 MAX_DESC_COUNT = 0; // at most 2 rows of descriptions
    VfxTextFrame *m_caption;                // Main item label
	VfxImageFrame *m_icon;        // the default icon and thumbnail collage
	VappGalleryIndexMenuItem *m_itemInfo;   // store static item information

public:
    VappGalleryIndexItemCell():
      m_caption(NULL),
      m_icon(NULL),
      m_itemInfo(NULL)
    {
    }

    VfxU32 getDescriptionCount() const
    {
        return MAX_DESC_COUNT;
    }

    void setItemInfo(VappGalleryIndexMenuItem *itemInfo)
    {
        m_itemInfo = itemInfo;
    }

public:

    // create icon and text fields
    virtual void onCreateElements()
    {
        VFX_OBJ_CREATE(m_caption, VfxTextFrame, this);
        m_caption->setAutoFontSize(VFX_FALSE);
        m_caption->setAutoResized(VFX_FALSE);
        m_caption->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(IndexPageLayout::FONT_SIZE_CAPTION)));
        m_caption->setSize(IndexPageLayout::TEXT_W, IndexPageLayout::TEXT_CAPTION_H);
        m_caption->setColor(VfxColor(IndexPageLayout::TEXT_CAPTION_COLOR));
        m_caption->setAutoAnimate(VFX_TRUE);

		// front thumb
		VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
		m_icon->setSize(IndexPageLayout::FRONT_THUMB_W, IndexPageLayout::FRONT_THUMB_H);
		m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
		m_icon->setAnchor(0.5, 0.5);
        m_icon->setPos(IndexPageLayout::ICON_W / 2, IndexPageLayout::ICON_H / 2);

	}

    // release children frame
    virtual void onCloseElements()
    {
        if(m_caption)
        {
            VFX_OBJ_CLOSE(m_caption);
            m_caption = NULL;
        }
    }

    virtual void onLayoutElements()
    {
        VFX_DEV_ASSERT(m_caption && m_icon && m_itemInfo);

        // fade-in
        const VfxS32 itemHeight = getSize().height;
        const VfxS32 textPos = (itemHeight - getTotalTextHeight()) / 2;
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_FALSE);
        VfxAutoAnimate::setDuration(ANIM_SLOW_TIMING);
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE);
        m_caption->setPos(IndexPageLayout::TEXT_MARGIN_L, textPos);
        VfxAutoAnimate::commit();

        // update item info & content here
        m_caption->setString(VfxWString(m_itemInfo->captionStrID));

        if(NULL != m_itemInfo->defaultImgID)
        {
            m_icon->setResId((VfxS32)m_itemInfo->defaultImgID);
        }

    }
        

    VfxS32 getTotalTextHeight()
    {
        return m_caption->getSize().height;
    }

    // Get the latest data of the elements (text, images...) from content provider
    virtual void onUpdateElements()
    {
        VcpListMenuCell *pCell = getCell();
        if(NULL == pCell)
        {
            return;

        }

        const VfxColor captionColor = pCell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_NORMAL);
        if(m_caption)
        {
            m_caption->setColor(captionColor);
        }
    }
};

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappGalleryIndexPage", VappGalleryIndexPage, VappGalleryPage);

VappGalleryIndexPage::VappGalleryIndexPage():
    m_indexMenu(NULL),
    m_shouldRefreshOnEnter(VFX_FALSE)
{
    m_itemIndices[0] = 0;   // My Shooting
    m_itemIndices[1] = 1;   // My Picture
    m_itemIndices[2] = 2;   // My Video
}

void VappGalleryIndexPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_INDEX_ON_INIT);
    VappGalleryPage::onInit();

    // set bg color to avoid abnormal bg color caused by page transition from page with different bg color
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // initialize gallery database later, when enter page
    m_shouldRefreshOnEnter = VFX_TRUE;

    // title bar (a tab title bar that allows storage selection)
    #ifdef __VAPP_GALLERY_ENABLE_USER_DRIVE__
    VcpTabTitleBar *tabBar = NULL;
    VFX_OBJ_CREATE(tabBar, VcpTabTitleBar, this);
    tabBar->m_signalTabSwitched.connect(this, &VappGalleryIndexPage::onSelectStorage);
    setTopBar(tabBar);
    createStorageSelectionTab(VFX_TRUE);
    #else
    VcpTitleBar *titleBar = NULL;
    VFX_OBJ_CREATE(titleBar, VcpTitleBar, this);
    titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_AP_NAME));
    setTopBar(titleBar);
    #endif

    // toolbar, only show under full app, not in picker-based CUIs
#ifdef __VAPP_GALLERY_ENABLE_SETTING_PAGE__
    const VcuiGalleryPickerBase *pickerCUI = getParentPickerCUI();
    const VfxBool showToolbar = (NULL == pickerCUI);
    if(showToolbar)
    {
        VcpToolBar *tbar = NULL;
        VFX_OBJ_CREATE(tbar, VcpToolBar, this);
        tbar->addItem('SETT', VFX_WSTR_RES(VCP_STR_TOOL_BAR_SETTINGS), VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING);
        tbar->m_signalButtonTap.connect(this, &VappGalleryIndexPage::onToolbarCommand);
        setBar(VFX_PAGE_BAR_LOCATION_BOTTOM, tbar, VFX_TRUE);
    }
#endif

}

void VappGalleryIndexPage::onDeinit()
{
    VappGalleryPage::onDeinit();
}

void VappGalleryIndexPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_INDEX_ON_EXIT);
    VappGalleryPage::onExit(isBackward);

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    VfxMainScr *pMainScr = getMainScr();
    if(pMainScr && pMainScr->getIsSnapshotDrawing())
    {
        return;
    }

    // register device plug-in to refresh toolbar
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappGalleryIndexPage::onDevicePlugInOut, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappGalleryIndexPage::onDevicePlugInOut, this);
}

void VappGalleryIndexPage::onExited2()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_INDEX_ON_EXITED2);

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    VfxMainScr *pMainScr = getMainScr();
    if(pMainScr && pMainScr->getIsSnapshotDrawing())
    {
        return;
    }

    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();

    VFX_OBJ_CLOSE(m_indexMenu);

    return VappGalleryPage::onExited2();
}

void VappGalleryIndexPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_INDEX_ON_ENTER);
    VappGalleryPage::onEnter(isBackward);

    // Index of pages, which is a list menu.
    VFX_OBJ_CLOSE(m_indexMenu);
    if(NULL == m_indexMenu)
    {
        VFX_OBJ_CREATE(m_indexMenu, VcpListMenu, this);
        m_indexMenu->setSize(getSize().width, getSize().height);
        m_indexMenu->setItemHeight(IndexPageLayout::MENU_H);
        m_indexMenu->setContentProvider(this);
        m_indexMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
        m_indexMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
        m_indexMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
        m_indexMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_indexMenu->m_signalItemTapped.connect(this, &VappGalleryIndexPage::onIndexItemTapped);
    }
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

#if 1

    // CUI may assign custom file filter
    // check if there is CUI-assigned custom file filter
    // then initialize collections,
    // since image picker and video picker have different collection set
    if(getParentImagePickerCUI())
    {
        m_itemIndices[0] = 0; // my shooting
        m_itemIndices[1] = 1; // my picture
        m_itemIndices[2] = -1;
    }
    else if(getParentVideoPickerCUI())
    {
        m_itemIndices[0] = 0; // my shooting
        m_itemIndices[1] = 2; // my video
        m_itemIndices[2] = -1;
    }
    
#endif

    VappGalleryStorageSetting storageSetting;
    handleStorageChangeLite(storageSetting);

    // register device plug-in to refresh tab bar
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappGalleryIndexPage::onDevicePlugInOut, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappGalleryIndexPage::onDevicePlugInOut, this);
}

#ifdef __VAPP_GALLERY_ENABLE_USER_DRIVE__
void VappGalleryIndexPage::onSelectStorage(VfxObject *sender, VfxId btnId)
{
    VFX_UNUSED(sender);

    // btnId are srv_fmgr_drv_type_enum
    const srv_fmgr_drv_type_enum drvType = (srv_fmgr_drv_type_enum)btnId;

    VappGalleryStorageSetting storageSetting;
    if(drvType != storageSetting.getDefaultStorage(VFX_FALSE))
    {
        storageSetting.setDefaultStorage(drvType);
        handleStorageChange(storageSetting);
    }
}
#endif

#ifdef __VAPP_GALLERY_ENABLE_SETTING_PAGE__
void VappGalleryIndexPage::onToolbarCommand(VfxObject *sender, VfxId btnId)
{
    switch(btnId)
    {
    case 'SETT':
        onGotoPage(PN_SETTING);
        break;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);
        break;
    }
}
#endif

void VappGalleryIndexPage::refreshStorage(VfxBool directRefresh)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_INDEX_REFRESH_STORAGE, directRefresh);

    if(!directRefresh)
    {
        // simply set dirty flag, to refresh the entry in onEnter
        m_shouldRefreshOnEnter = VFX_TRUE;
    }
    else
    {
        // refresh UI
		#ifdef __VAPP_GALLERY_ENABLE_USER_DRIVE__
        createStorageSelectionTab(VFX_FALSE);
		#endif
        VappGalleryStorageSetting setting;
        handleStorageChange(setting);
    }
}

VfxBool VappGalleryIndexPage::handleStorageChangeLite(VappGalleryStorageSetting &storageSetting)
{
    // check non-exist drives
    const srv_fmgr_drv_type_enum defaultStorage = storageSetting.getDefaultStorage(VFX_FALSE);
    const U8 drv = srv_fmgr_drv_get_letter_by_type(defaultStorage);
    if(MMI_FALSE == srv_fmgr_drv_is_accessible(drv))
    {
        // update page message
        setPageMessage(VFX_WSTR_RES(STR_GLOBAL_INSERT_MEMORY_CARD));
        showPageMessage(VFX_TRUE);
        if(m_indexMenu)
        {
            m_indexMenu->setHidden(VFX_TRUE);
        }
        // update toolbar
        VcpTabTitleBar *tabBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTabTitleBar);
        if(tabBar)
        {
            tabBar->setHighlightedTab(defaultStorage);
        }

        return VFX_FALSE;
    }
    else
    {
        showPageMessage(VFX_FALSE);
        if(m_indexMenu)
        {
            m_indexMenu->setHidden(VFX_FALSE);
        }
        return VFX_TRUE;
    }
}

void VappGalleryIndexPage::handleStorageChange(VappGalleryStorageSetting &storageSetting)
{
    m_shouldRefreshOnEnter = VFX_FALSE;

    if(!handleStorageChangeLite(storageSetting))
    {
        return;
    }

    // check if there is CUI-assigned custom file filter
    VappGalleryCollectionSetting setting;

    // CUI may assign custom file filter
    VcuiGalleryPickerBase *cui = getParentPickerCUI();
    if(cui)
    {
        setting.m_filter = *cui->getTypeFilter();
    }

    // assign chosen storage
    const srv_fmgr_drv_type_enum defaultStorage = storageSetting.getDefaultStorage(VFX_FALSE);
    setting.m_storage = defaultStorage;

    // update UI, update tab and notify collection to re-query
    VcpTabTitleBar *tabBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTabTitleBar);
    if(tabBar)
    {
        tabBar->setHighlightedTab(setting.m_storage);
    }

    // refresh menu items
    showPageMessage(VFX_FALSE);
    m_indexMenu->setHidden(VFX_FALSE);
    m_indexMenu->updateAllItems();

    // force update entire page
    checkUpdate();
}

mmi_ret VappGalleryIndexPage::onDevicePlugInOut(mmi_event_struct *param)
{
    if(NULL == param)
    {
        return MMI_RET_OK;
    }
    VappGalleryIndexPage* pThis = (VappGalleryIndexPage*)param->user_data;
    if(NULL == pThis)
    {
        return MMI_RET_OK;
    }

    return pThis->handleDevicePlugInOut(param);
}

mmi_ret VappGalleryIndexPage::handleDevicePlugInOut(mmi_event_struct *param)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_INDEX_HANDLE_DEVICE_PLUG_IN_OUT);

    // update storage selection tab
    // note that we don't update storage,
    // it is handled by VappGalleryApp or VcuiGalleryBase
    #ifdef __VAPP_GALLERY_ENABLE_USER_DRIVE__
    createStorageSelectionTab(VFX_FALSE);
    #endif
	
    // then, we check if the arrival drive is exactly
    // what user choosed. if so, we need to refresh the current storage.
    do
    {
        if(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN != param->evt_id)
        {
            break;
        }

        if(sizeof(srv_fmgr_notification_dev_plug_event_struct) != param->size)
        {
            break;
        }

        #ifdef __VAPP_GALLERY_ENABLE_USER_DRIVE__
        VcpTabTitleBar *tabBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTabTitleBar);
        if(NULL == tabBar)
        {
            break;
        }
        #endif
        const srv_fmgr_notification_dev_plug_event_struct* plugEvent = (srv_fmgr_notification_dev_plug_event_struct*)param;
        VappGalleryStorageSetting setting;
        const VfxId currentStorageType = setting.getDefaultStorage(VFX_FALSE);
        for(U8 i = 0; i < plugEvent->count; ++i)
        {
            if(currentStorageType == srv_fmgr_drv_get_type(plugEvent->drv_letters[i]))
            {
                handleStorageChange(setting);
                break;
            }
        }
    }while(0);

    return MMI_RET_OK;
}

#ifdef __VAPP_GALLERY_ENABLE_USER_DRIVE__
void VappGalleryIndexPage::createStorageSelectionTab(VfxBool updateStorage)
{
    VcpTabTitleBar *tabBar = VFX_OBJ_DYNAMIC_CAST(getBar(VFX_PAGE_BAR_LOCATION_TOP), VcpTabTitleBar);
    if(NULL == tabBar)
    {
        return;
    }

    // try to remember highlighted item
    const VfxId previousHighlight = tabBar->getHighlightedTab();
    if(tabBar->getTabCount())
    {
        tabBar->removeAllTabs();
    }

    // insert accessible drive names
    VfxWString driveName;
    SRV_FMGR_DRVLIST_HANDLE hDrvList = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    for(VfxS32 i = 0; i < srv_fmgr_drivelist_count(hDrvList); ++i)
    {
        const U8 drv = srv_fmgr_drivelist_get_drv_letter(hDrvList, i);

        const srv_fmgr_drv_type_enum drvType = (srv_fmgr_drv_type_enum)srv_fmgr_drv_get_type(drv);
        // assign icon
        const VfxId iconId = drvType < SRV_FMGR_DRV_CARD_TYPE ? IMG_ID_VAPP_FMGR_TAB_PHONE_ICN : IMG_ID_VAPP_FMGR_TAB_CARD_ICN;

        // assign name
        VfxWChar *nameBuf = driveName.lockBuf(SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
        srv_fmgr_drv_get_name(drv, nameBuf, SRV_FMGR_PATH_MAX_FILE_NAME_LEN);
        driveName.unlockBuf();

        tabBar->addTab(drvType,VcpStateImage(iconId), driveName);
    }
    srv_fmgr_drivelist_destroy(hDrvList);
    hDrvList = NULL;

    if(updateStorage)
    {
        // set default focus tab
        // retrieve default setting
        VappGalleryStorageSetting setting;
        tabBar->setHighlightedTab(setting.getDefaultStorage(VFX_TRUE));
    }
    else
    {
        tabBar->setHighlightedTab(previousHighlight);
    }
}
#endif

void VappGalleryIndexPage::onIndexItemTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(sender == m_indexMenu);
    const PageName page = getPageNameFromCellIndex(index);
    onGotoPage(page);
}

void VappGalleryIndexPage::onGotoPage(PageName pageId)
{
    VfxPage *nextPage = createPageFromName(pageId);
    if(nextPage)
    {
        // TODO: we should also use dirty flag for
        // shooting/picture/video case
        m_shouldRefreshOnEnter = (PN_SETTING == pageId) ? VFX_FALSE : VFX_TRUE;

        if(PN_MY_SHOOTING == pageId)
        {
            // only Shooting page have special page id for now.
            getMainScr()->pushPage(pageId, nextPage);
        }
        else
        {
            getMainScr()->pushPage(0, nextPage);
        }
    }
}

VcuiGalleryPickerBase* VappGalleryIndexPage::getParentPickerCUI() const
{
    VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
    return cui;
}

VcuiGalleryImagePicker *VappGalleryIndexPage::getParentImagePickerCUI() const
{
    VcuiGalleryImagePicker *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryImagePicker);
    return cui;
}

VcuiGalleryVideoPicker *VappGalleryIndexPage::getParentVideoPickerCUI() const
{
    VcuiGalleryVideoPicker *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryVideoPicker);
    return cui;
}

VfxPage* VappGalleryIndexPage::createPageFromName(PageName name)
{
    VfxPage *nextPage = NULL;
    // create page and perform page-specific configuration
    switch(name)
    {
#ifdef __VAPP_GALLERY_ENABLE_SETTING_PAGE__
	case PN_SETTING:
		VFX_OBJ_CREATE(nextPage, VappGallerySettingPage, getMainScr());
		break;
#endif
    case PN_MY_SHOOTING:
        {
            VappGalleryShootingPage *shootingPage = NULL;
            VFX_OBJ_CREATE(shootingPage, VappGalleryShootingPage, getMainScr());
            nextPage = shootingPage;

            // config sort method
            shootingPage->configSortMethod(FS_SORT_TIME);

            // still enter shooting folder,
            // but displays image files only
            if(getParentPickerCUI())
            {
                VappGalleryCollectionSetting setting;
                VfxWString folderPath;
                VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                                            setting.getDefaultDrive(),
                                                            VappGalleryFmgrDefaultFolder::MY_SHOOTING,
                                                            folderPath);
                if(getParentImagePickerCUI())
                {
                    shootingPage->configCustomFolder(folderPath, VappGalleryShootingPage::ALLOW_IMAGE);
                }
                else if(getParentVideoPickerCUI())
                {
                    shootingPage->configCustomFolder(folderPath, VappGalleryShootingPage::ALLOW_VIDEO);
                }

                // MAUI_02654637, image picker should not have camera button
                shootingPage->configNoCameraButton(VFX_TRUE);
            }
        }

        break;
    case PN_MY_PICTURE:
        VFX_OBJ_CREATE(nextPage, VappGalleryPicturePage, getMainScr());
        break;
    case PN_MY_VIDEO:
        {
            VappGalleryShootingPage *shootingPage = NULL;
            VFX_OBJ_CREATE(shootingPage, VappGalleryShootingPage, getMainScr());
            nextPage = shootingPage;

            // config sort method
            shootingPage->configSortMethod(FS_SORT_TIME);

			VappGalleryCollectionSetting setting;
			VfxWString folderPath;
			VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
														setting.getDefaultDrive(),
														VappGalleryFmgrDefaultFolder::MY_VIDEO,
														folderPath);
			
			shootingPage->configCustomFolder(folderPath, VappGalleryShootingPage::ALLOW_VIDEO);
			shootingPage->configNoCameraButton(VFX_TRUE);
			shootingPage->setCustomTitle(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IDX_VIDEO));
		}
        break;
    }
    return nextPage;
}

PageName VappGalleryIndexPage::getPageNameFromCellIndex(VfxU32 index)
{
    const VfxS32 itemIdx = m_itemIndices[index];
    if(itemIdx == -1)
    {
        return PN_INVALID;
    }
    VappGalleryIndexMenuItem *item = getItemInfoFromIndex(itemIdx);
    if(NULL == item)
    {
        return PN_INVALID;
    }
    else
    {
        return item->pageName;
    }
}

VappGalleryIndexMenuItem* VappGalleryIndexPage::getItemInfoFromIndex(VfxU32 index)
{
    if(index >= INDEX_MENU_ITEM_COUNT)
    {
        return NULL;
    }
    return &g_indexMenuItems[index];
}

VcpListMenuCellClientBaseFrame *VappGalleryIndexPage::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
    // Query info from table, and create corresponding MediaCollection.
    VappGalleryIndexItemCell *pCellFrame = NULL;
    VFX_OBJ_CREATE(pCellFrame, VappGalleryIndexItemCell, parentFrame);

    const VfxS32 itemIdx = m_itemIndices[index];
    VFX_ASSERT(itemIdx != -1);
	
    VappGalleryIndexMenuItem *info = getItemInfoFromIndex(itemIdx);
    pCellFrame->setItemInfo(info);

    return pCellFrame;
}

// Provide custom cells for layout
void VappGalleryIndexPage::closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *pCell)
{
    VFX_OBJ_CLOSE(pCell);
    return;
}

VfxU32 VappGalleryIndexPage::getCount() const
{
    if(getParentPickerCUI())
    {
        // last item (video) is NOT displayed under
        // image picker CUI.
        return INDEX_MENU_ITEM_COUNT - 1;
    }
    else
    {

        return INDEX_MENU_ITEM_COUNT;
    }
}

VcpListMenuItemStateEnum VappGalleryIndexPage::getItemState(VfxU32 index) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}


#endif
