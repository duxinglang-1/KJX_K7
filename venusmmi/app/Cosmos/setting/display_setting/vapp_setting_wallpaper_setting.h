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
 *  vapp_setting_wallpaper_setting.h
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
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SETTING_WALLPAPER_SETTING_H__
#define __VAPP_SETTING_WALLPAPER_SETTING_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_wallpaper_setting_method_gprot.h"
#include "vapp_video_player_cp.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    VAPP_WALLPAPER_SETTING_SYSTEM,
    VAPP_WALLPAPER_SETTING_GALLERY,

    VAPP_WALLPAPER_SETTING_TYPE_TOTAL
} VappWpSettingSourceTypeEnum;


typedef enum
{
    VAPP_WALLPAPER_FROM_PICTURE,
#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    VAPP_WALLPAPER_FROM_VIDEO,
#endif
    VAPP_WALLPAPER_FROM_TYPE_TOTAL
}VappWpSourceFromEnum;

class VappLiveWallpaperContentProvider;
/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappSettingWallpaperResPage : public VfxPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSettingWallpaperResPage);
    // Overrides
    public:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const {return VAPP_WALLPAPER_SETTING_TYPE_TOTAL;};
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual VfxBool getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image);

    // Methods
    public:
    VappSettingWallpaperResPage() : m_cuiId(0), m_wallpaperSettingCuiId(0), m_wpSourceType(VAPP_WALLPAPER_SETTING_SYSTEM) {};
    VappSettingWallpaperResPage(VappWallpaperType type) :m_cuiId(0), m_wallpaperSettingCuiId(0), m_wpType(type)
                                                        ,m_wpSourceType(VAPP_WALLPAPER_SETTING_SYSTEM){};
    void onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx);
    void setWallpaperFromSystem();
#ifndef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
    void setWallpaperFromGallery();
#endif
    void closeWallpaperPage();
    void closeStorageRelatedPage();
    #ifdef __MMI_USB_SUPPORT__
    static mmi_ret usbMassStorageModeHdlr(mmi_event_struct *evt);
    #endif /* __MMI_USB_SUPPORT__ */
    // Variables
    private:
    VcpListMenu *m_listMenu;
    VappLiveWallpaperContentProvider *m_liveWallpaperProvider;
    mmi_id       m_cuiId;
    mmi_id       m_wallpaperSettingCuiId;
    VappWallpaperType m_wpType;
    VappWpSettingSourceTypeEnum m_wpSourceType;
};

#ifdef __MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__
class VappSettingVideoPreviewPage;

class VappSettingWallpaperGalleryPage : public VfxPage,  public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSettingWallpaperGalleryPage);
    // Overrides
    public:
    virtual void onInit();
	virtual void onDeinit();
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
    virtual VfxU32 getCount() const {return VAPP_WALLPAPER_SETTING_TYPE_TOTAL;}
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual VfxBool getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image);

    // Methods
    public:
    VappSettingWallpaperGalleryPage() : m_cuiId(0), m_wallpaperSettingCuiId(0){};
    VappSettingWallpaperGalleryPage(VappWallpaperType wpType) 
            : m_cuiId(0), m_wallpaperSettingCuiId(0), m_wpType(wpType)
        {}
    
    void onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx);

    void setWallpaperFromGallery();
    void closeWallpaperPage();
    void closeStorageRelatedPage();
    #ifdef __MMI_USB_SUPPORT__
	static mmi_ret usbMassStorageModeHdlr(mmi_event_struct *evt);
    #endif //__MMI_USB_SUPPORT__

    // Variables
    private:
    VcpListMenu *m_listMenu;
    mmi_id       m_cuiId;
    mmi_id       m_wallpaperSettingCuiId;
    VappWallpaperType m_wpType;
    VappSettingVideoPreviewPage *m_preView;
};

class VappCustomImageFrame: public VcpListMenuCellIconSingleTextFrame
{
private:
#if defined(__MMI_MAINLCD_320X480__)
        enum
        {
            TEXT_LEFT_GAPS   = 0,
            TEXT_RIGHT_GAPS  = 10,
            IMG_LEFT_GAPS    = 3,
            IMG_RIGHT_GAPS   = 3,
            IMG_MAX_WIDTH    = 46,
            // Add for setting framework cell
            IMG_MAX_HEIGHT    = 46,        
            ACCESSORY_WIDTH  = 30,
            ACCESSORY_RIGHT_GAPS = 8
        };
#elif defined(__MMI_MAINLCD_480X800__)
        enum
        {
            TEXT_LEFT_GAPS   = 0,
            TEXT_RIGHT_GAPS  = 18,
            IMG_LEFT_GAPS    = 7,
            IMG_RIGHT_GAPS   = 7,
            IMG_MAX_WIDTH    = 72,
            // Add for setting framework cell
            IMG_MAX_HEIGHT    = 72,        
            ACCESSORY_WIDTH  = 30,
            ACCESSORY_RIGHT_GAPS = 8        
        };
#else
        enum
    {
            TEXT_LEFT_GAPS   = 0,
            TEXT_RIGHT_GAPS  = 8,
            IMG_LEFT_GAPS    = 3,
            IMG_RIGHT_GAPS   = 3,
            IMG_MAX_WIDTH    = 36,
            // Add for setting framework cell        
            IMG_MAX_HEIGHT    = 36,
            ACCESSORY_WIDTH  = 30,
            ACCESSORY_RIGHT_GAPS = 8        
        };
#endif  

public:
    virtual void onLayoutElements();    
};

class VappSettingSystemVideoPage : public VfxPage,  public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappSettingSystemVideoPage);
    // Overrides
    public:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool getItemText(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
        );
	virtual void onEntered();
    // TODO: The num and name are not prepared.
    virtual VfxU32 getCount() const;
    virtual mmi_ret onProc(mmi_event_struct *evt);
    virtual VfxBool getItemImage(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxImageSrc &image);
    virtual VcpListMenuItemStateEnum getItemState(VfxU32 index) const {return ((m_highlightItem == index) ? VCP_LIST_MENU_ITEM_STATE_SELECTED: VCP_LIST_MENU_ITEM_STATE_NONE);}
    virtual VcpListMenuCellClientBaseFrame* getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame);
    virtual void closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *cell);

    // Methods
    public:
    VappSettingSystemVideoPage(): m_wpType(VAPP_VIDEO_PWR_ON_SCREEN), m_cuiId(0), m_wallpaperSettingCuiId(0){};
    VappSettingSystemVideoPage(VappWallpaperType wpType): m_wpType(wpType), m_cuiId(0), m_wallpaperSettingCuiId(0){};

    void onSelectItem(VcpListMenu *listMenu, VfxU32 selectIdx);
    void onEnterVideoGallery(VfxObject* sender, VfxId id);
    void setHighlightItem(VfxU32 highlightItem) {m_highlightItem = highlightItem;}
    void closeWallpaperPage();
    VfxId indexToVideoId(VfxId index) const;
    void setWallpaperFromGallery();

    
    void closeStorageRelatedPage();
#ifdef __MMI_USB_SUPPORT__
    static mmi_ret usbMassStorageModeHdlr(mmi_event_struct *evt);
#endif /* __MMI_USB_SUPPORT__ */

    // Variables
    private:
    VcpListMenu *m_listMenu;
    VfxU32 m_highlightItem;
    VappWallpaperType m_wpType;
    VfxId m_cuiId;
    VfxId m_wallpaperSettingCuiId;
    VfxBool m_isGallery;
    VappSettingVideoPreviewPage* m_previewPage;
};

class VappSettingVideoPreviewPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappSettingVideoPreviewPage);
    // Overrides
    protected:
    virtual void onInit();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited2();
    virtual void onEnter(VfxBool isBackward);
    virtual void onEntered();
    // TODO: The num and name are not prepared.
    // Methods
    public:
    VappSettingVideoPreviewPage();    
    VappSettingVideoPreviewPage(VappWallpaperType wpType, VfxId videoId);
    void closeWallpaperPage();
    void onPreviewClick(VfxObject* sender, VfxId id);
    void onFileReady(VappVideoPlayerComponent *player, MDI_RESULT result);
    void onPlayFinished(VappVideoPlayerComponent *player, MDI_RESULT result);
    static mmi_ret onEvent(mmi_event_struct *param);
	void setOKayStatus(VfxBool status);
    private:
	void playVideo(VappVideoPlayerComponent *player, MDI_RESULT openStatus);
	void createPlayer();
    void proccessSetVideo();
    void closeSpecPage();

    private:
    VappWallpaperType m_wpType;
    VfxId           m_videoId;
    VappVideoPlayerComponent *m_player;
	VfxBool m_isEntered;
	VfxBool m_isVideoOpened;
	MDI_RESULT m_openStatus;
    //VfxBool         m_isBackWard;
};
#endif /*__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__*/
#endif /* __VAPP_SETTING_WALLPAPER_SETTING_H__ */
