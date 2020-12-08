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

#ifndef __VAPP_GALLERY_PICTURE_H__
#define __VAPP_GALLERY_PICTURE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_gallery_slim.h"
#include "vapp_gallery_slim_data.h"
#include "vapp_gallery_slim_util.h"

#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /*defined(__MMI_VUI_COSMOS_CP__)*/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
enum FolderDisplayIndex
{
    MY_PICTURE_FOLDER_INDEX = 0, 
    MY_RECEIVED_FOLDER_INDEX,
    MY_PICTURE_SUBFOLDER_INDEX
};

class VappGalleryFolderFileList : public VfxObject
{
    // Override
public:
    VappGalleryFolderFileList();
    virtual ~VappGalleryFolderFileList();

public:
    void config(IVappGalleryMediaList::ListEvent* pSignalAllFolderScanReady, 
		IVappGalleryMediaList::ListReloadEvent* pSignalFolderReloadStart, 
		IVappGalleryMediaList::ListReloadEvent* pSignalFolderReloadFinished,
        const FMGR_FILTER *filter = NULL
        );
    
    VfxBool isPrepared() const;
    
    VfxU32 getFileCount(VfxU32 index
		) const;

    VfxU32 getFolderCount() const;
    
    VfxBool getFolderPath(VfxU32 index, 
        VfxWString &path
        );

    VfxBool getFolderName(VfxU32 index, 
        VfxWString &caption
        );

    void getRootFolder(VfxWString &path,
        const VappGalleryFmgrDefaultFolder::DEFAULT_FOLDER_TYPE type = VappGalleryFmgrDefaultFolder::MY_PICTURE
        );

    void prepare();
    
protected:
	// reload folder list
	void onFolderListReloadStart(VcpMenuPos mediaPos);
	void onFolderListReloadFinished(VcpMenuPos mediaPos);
	
    // image files in each folder has scan complete
    void onSingleFolderFileListReady(VappGalleryPrepareResult prepareResult);
    
    void onFolderScanReady(VappGalleryPrepareResult prepareResult);
    
    void scanNextFolder();
    // image files in Images folder has scan complete
    void onImageFileListReady(VappGalleryPrepareResult prepareResult);

    // image files in recieved folder has scan complete
    void onReceivedImageFileListReady(VappGalleryPrepareResult prepareResult);

    // folders in Images folder has scan complete
    void onFolderListReady(VappGalleryPrepareResult prepareResult);
private:
    
    VfxU32* m_fileCountList;
    VfxU32 m_folderIndex;
    VfxU32 m_folderCount;
	VfxBool m_isPrepared;
    
    const FMGR_FILTER *m_fileFilter;

    VappGalleryFmgrImageList *m_imageFileList;
    VappGalleryFmgrFolderList *m_folderList;
    VappGalleryFmgrImageList *m_receivedImageFileList;

    IVappGalleryMediaList::ListEvent m_signalFolderScanReady;
    IVappGalleryMediaList::ListEvent m_signalSingleFolderFileListReady;
    IVappGalleryMediaList::ListEvent m_signalFolderListReady;
    IVappGalleryMediaList::ListEvent m_signalImageFileListReady;
    IVappGalleryMediaList::ListEvent m_signalReceivedImageFileListReady;
    
	// reload signal to notify refresh scan process
	IVappGalleryMediaList::ListReloadEvent m_signalReloadStart;
    IVappGalleryMediaList::ListReloadEvent m_signalReloadFinished;
    
    // use to notify picture page scan has ready
    IVappGalleryMediaList::ListEvent* m_pSignalAllFolderScanReady;

	// reload signal to notify for get folder name
	IVappGalleryMediaList::ListReloadEvent* m_pSignalFolderReloadStart;
    IVappGalleryMediaList::ListReloadEvent* m_pSignalFolderReloadFinished;
};


class VappGalleryPicturePage : public VappGalleryPage, public IVcpListMenuContentProvider
{
    VFX_DECLARE_CLASS(VappGalleryPicturePage);
// Override
public:
    VappGalleryPicturePage();
    virtual void onInit();
    virtual void onEntered();
    virtual void onUpdate();
    virtual void onExited2();

// Implement IVcpListMenuContentProvider
public:   
    
	virtual VfxU32 getCount() const;
	
    // Provide custom layout cells
    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(VfxU32 index, 
    	VfxFrame *parentFrame
    	);
	
    virtual void closeItemCustomContentFrame(VfxU32 index, 
		VcpListMenuCellClientBaseFrame *cell
		);
        
    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index
        ) const;

public:

	enum AnimateSlowTime
	{
		ANIM_SLOW_TIMING = 500
	};
	
#if defined(__MMI_MAINLCD_320X480__)
	enum PicturePageLayout
	{
		MENU_H = 71,            // height of menu item

	    ICON_W = 67,            // size of the entire "rotated" background
	    ICON_H = 67,            // size of the entire "rotated" background

	    BACK_THUMB_W = 48,      // image thumbnail size (for back)
	    BACK_THUMB_H = 48,
	    BACK_THUMB_CX = (ICON_W  / 2 - 1),
	    BACK_THUMB_CY = (ICON_H  / 2 - 1),
	    BACK_THUMB_ANGLE = 18,

	    FRONT_THUMB_W = 50,
	    FRONT_THUMB_H = 50,
	    FRONT_THUMB_CX = (ICON_W - FRONT_THUMB_W) / 2,
	    FRONT_THUMB_CY = (ICON_W - FRONT_THUMB_W) / 2,

	    FRONT_BORDER_W = 56,
	    FRONT_BORDER_H = 56,

	    BADGE_MARGIN_R = 12,
	    BADGE_MARGIN_D = 12,

	    ICON_MARGIN_L = 5,      // left of entire collage
	    ICON_MARGIN_T = 3,      // top of entire collage

	    TEXT_MARGIN_L = 82,
	    TEXT_W = 230,
	    TEXT_CAPTION_H = 24,
	    TEXT_DESC_H = 15,
	    TEXT_CAPTION_COLOR = 0xff151515,
	    TEXT_DESC_COLOR = 0xff505050,
	    DESC_FADEIN_OFFSET = 5,

	    FONT_SIZE_CAPTION = VCP_LIST_MENU_FONT_SIZE_MEDIUM,
	    FONT_SIZE_DESC = VCP_LIST_MENU_FONT_SIZE_SMALL,

	    PAD_TWO_LINE = 4, // 3
	   	PAD_THREE_LINE = 3  // 2
	};

#elif defined(__MMI_MAINLCD_480X800__)

	enum PicturePageLayout
	{
		MENU_H = 114,

	    ICON_W = 105,
	    ICON_H = 106,

	    BACK_THUMB_W = 78,
	    BACK_THUMB_H = 78,
	    BACK_THUMB_CX = (ICON_W  / 2 - 1),
	    BACK_THUMB_CY = (ICON_H  / 2 - 1),
	    BACK_THUMB_ANGLE = 18,

	    FRONT_THUMB_W = 80,
	    FRONT_THUMB_H = 82,
	    FRONT_THUMB_CX = (ICON_W - FRONT_THUMB_W) / 2,
	    FRONT_THUMB_CY = (ICON_W - FRONT_THUMB_W) / 2,

	    FRONT_BORDER_W = 87,
	    FRONT_BORDER_H = 90,

	    BADGE_MARGIN_R = 15,
	    BADGE_MARGIN_D = 15,

	    ICON_MARGIN_L = 5,
	    ICON_MARGIN_T = 4,

	    TEXT_MARGIN_L = 122,
	    TEXT_W = 440,
	    TEXT_CAPTION_H = 35,
	    TEXT_DESC_H = 23,
	    TEXT_CAPTION_COLOR = 0xff151515,
	    TEXT_DESC_COLOR = 0xff505050,
	    DESC_FADEIN_OFFSET = 8,

	    FONT_SIZE_CAPTION = VCP_LIST_MENU_FONT_SIZE_MEDIUM,
	    FONT_SIZE_DESC = VCP_LIST_MENU_FONT_SIZE_SMALL,

		PAD_TWO_LINE = 6, // 3
    	PAD_THREE_LINE = 4  // 2
	};

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
	enum PicturePageLayout
	{
	    MENU_H = 59,

	    ICON_W = 54,
	    ICON_H = 54,

	    BACK_THUMB_W = 40,
	    BACK_THUMB_H = 40,
	    BACK_THUMB_CX = (ICON_W  / 2 + 1),
	    BACK_THUMB_CY = (ICON_H  / 2 - 2),
	    BACK_THUMB_ANGLE = 18,

	    FRONT_THUMB_W = 40,
	    FRONT_THUMB_H = 40,
	    FRONT_THUMB_CX = (ICON_W - FRONT_THUMB_W) / 2,
	    FRONT_THUMB_CY = (ICON_W - FRONT_THUMB_W) / 2 - 1,

	    FRONT_BORDER_W = 45,
	    FRONT_BORDER_H = 46,

	    BADGE_MARGIN_R = 9,
	    BADGE_MARGIN_D = 10,

	    ICON_MARGIN_L = 5,
	    ICON_MARGIN_T = 4,

	    TEXT_MARGIN_L = 70,
	    TEXT_W = 160,
	    TEXT_CAPTION_H = 20,
	    TEXT_DESC_H = 13,
	    TEXT_CAPTION_COLOR = 0xff151515,
	    TEXT_DESC_COLOR = 0xff505050,
	    DESC_FADEIN_OFFSET = 8,

	    FONT_SIZE_CAPTION = VCP_LIST_MENU_FONT_SIZE_MEDIUM,
	    FONT_SIZE_DESC = VCP_LIST_MENU_FONT_SIZE_SMALL,

		PAD_TWO_LINE = 2,
    	PAD_THREE_LINE = 1
	};

#else

	// prevent compile error for undefined resolution
	enum PicturePageLayout
	{
	    MENU_H = 71,

	    ICON_W = 67,
	    ICON_H = 67,

	    BACK_THUMB_W = 48,
	    BACK_THUMB_H = 48,
	    BACK_THUMB_CX = (ICON_W  / 2 - 1),
	    BACK_THUMB_CY = (ICON_H  / 2 - 1),
	    BACK_THUMB_ANGLE = 18,

	    FRONT_THUMB_W = 50,
	    FRONT_THUMB_H = 50,
	    FRONT_THUMB_CX = (ICON_W - FRONT_THUMB_W) / 2,
	    FRONT_THUMB_CY = (ICON_W - FRONT_THUMB_W) / 2,

	    FRONT_BORDER_W = 56,
	    FRONT_BORDER_H = 56,

	    BADGE_MARGIN_R = 12,
	    BADGE_MARGIN_D = 12,

	    ICON_MARGIN_L = 5,
	    ICON_MARGIN_T = 3,

	    TEXT_MARGIN_L = 82,
	    TEXT_W = 230,
	    TEXT_CAPTION_H = 24,
	    TEXT_DESC_H = 13,
	    TEXT_CAPTION_COLOR = 0xff151515,
	    TEXT_DESC_COLOR = 0xff505050,
	    DESC_FADEIN_OFFSET = 5,

	    FONT_SIZE_CAPTION = VCP_LIST_MENU_FONT_SIZE_MEDIUM,
	    FONT_SIZE_DESC = VCP_LIST_MENU_FONT_SIZE_SMALL,

		PAD_TWO_LINE = 4, // 3
    	PAD_THREE_LINE = 3
	};
#endif
	// Method
public:
    // create a thumbnail list page
    // showing given folder, and notify
    // parent screen to show it.
    void gotoFolderThumbnailPage(const VfxWString &folder, const VfxWString &caption);

protected:
    // retrieves root folder to scan sub-folders and images.
    // based on settings of storage. (e.g. Phone/Card)
    void getRootFolder(VfxWString &path, 
                       const VappGalleryFmgrDefaultFolder::DEFAULT_FOLDER_TYPE type = VappGalleryFmgrDefaultFolder::MY_PICTURE);

    // initializes UI by scanning medias in folder
    void startRefreshUI();

protected:
    void onFolderScanReady(VappGalleryPrepareResult prepareResult);

    // user taps some folder item in folder list view
    void onFolderTapped(VcpListMenu *sender, VfxU32 index);

	// reload foldername list
	void onFolderListReloadStart(VcpMenuPos mediaPos);
	void onFolderListReloadFinished(VcpMenuPos mediaPos);

	private:	

		VappGalleryFolderFileList* m_folderFileList;
	    IVappGalleryMediaList::ListEvent m_signalFolderScanListReady;

	// reload signal to notify for get folder name
	IVappGalleryMediaList::ListReloadEvent m_signalFolderReloadStart;
    IVappGalleryMediaList::ListReloadEvent m_signalFolderReloadFinished;	

    VcpListMenu *m_folderListMenu;                           // the menu component
};

#endif /* __VAPP_GALLERY_PICTURE_H__ */