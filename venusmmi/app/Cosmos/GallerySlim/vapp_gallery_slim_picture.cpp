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
 *  vapp_gallery_picture.cpp
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
#include "vapp_gallery_slim_picture.h"
#include "vapp_gallery_slim_index.h"
#include "vapp_gallery_slim_shooting.h"
#include "vcp_include.h"
#include "../xml/vfx_xml_loader.h"
#include "vapp_fmgr_table.h"
extern "C"
{
#include "MMI_media_app_trc.h"
}

/*****************************************************************************
 * Define
 *****************************************************************************/


/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Global Variable
 *****************************************************************************/

/*****************************************************************************
 * Class Implementation
 *****************************************************************************/
VappGalleryFolderFileList::VappGalleryFolderFileList() : 
    m_fileCountList(NULL), 
    m_folderIndex(MY_PICTURE_FOLDER_INDEX), 
    m_folderCount(0), 
    m_isPrepared(VFX_FALSE), 
    m_fileFilter(NULL),
    m_imageFileList(NULL), 
    m_folderList(NULL),    
    m_receivedImageFileList(NULL), 
    m_pSignalAllFolderScanReady(NULL),
    m_pSignalFolderReloadStart(NULL),
    m_pSignalFolderReloadFinished(NULL)
{
    
}

VappGalleryFolderFileList::~VappGalleryFolderFileList()
{
    VFX_FREE_MEM(m_fileCountList);
}

void VappGalleryFolderFileList::config(IVappGalleryMediaList::ListEvent* pSignalAllFolderScanReady, 
	IVappGalleryMediaList::ListReloadEvent* pSignalFolderReloadStart, 
	IVappGalleryMediaList::ListReloadEvent* pSignalFolderReloadFinished,
        const FMGR_FILTER *filter)
{
    m_pSignalAllFolderScanReady = pSignalAllFolderScanReady;
	m_pSignalFolderReloadStart = pSignalFolderReloadStart;
	m_pSignalFolderReloadFinished = pSignalFolderReloadFinished;	
    m_fileFilter = filter;
}

void VappGalleryFolderFileList::prepare()
{
    // fisrt start scan all sub-folders, calculate folder count
    if(NULL == m_folderList)
    {
        VFX_OBJ_CREATE(m_folderList, VappGalleryFmgrFolderList, this);
        VappGalleryStorageSetting setting;
        const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(setting.getDefaultStorage());
        
        m_signalFolderListReady.connect(this, &VappGalleryFolderFileList::onFolderListReady);
		m_signalReloadStart.connect(this, &VappGalleryFolderFileList::onFolderListReloadStart);
		m_signalReloadFinished.connect(this, &VappGalleryFolderFileList::onFolderListReloadFinished);
		
		m_folderList->config(defaultDrv, &m_signalFolderListReady, &m_signalReloadStart, &m_signalReloadFinished);
    }
    m_folderList->prepare();
}

void VappGalleryFolderFileList::onFolderListReady(VappGalleryPrepareResult prepareResult)
{
    // +1 means My Picture folder
    m_folderCount = m_folderList->getTotalFileCount() + 1;
    if (m_folderCount == 0)
    {
        VFX_ASSERT(m_pSignalAllFolderScanReady != NULL);
        m_signalFolderScanReady.postEmit(PREPARE_OK);
		return;
    }

    VFX_ALLOC_MEM(m_fileCountList, m_folderCount * sizeof(VfxU32), this);
    memset(m_fileCountList, 0, m_folderCount * sizeof(VfxU32));
    m_signalSingleFolderFileListReady.connect(this, &VappGalleryFolderFileList::onSingleFolderFileListReady);
    m_signalFolderScanReady.connect(this, &VappGalleryFolderFileList::onFolderScanReady);
    scanNextFolder();
}

void VappGalleryFolderFileList::onFolderListReloadStart(VcpMenuPos mediaPos)
{
	if(!m_isPrepared)
	{
		MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PICTURE_ON_FOLDER_SCAN_RELOAD_START, mediaPos.group, mediaPos.pos);
	}
	// show loading icon when update list menu item if folder name is on reload status
	else if(m_pSignalFolderReloadStart)
	{
		m_pSignalFolderReloadStart->postEmit(mediaPos);
	}
}

void VappGalleryFolderFileList::onFolderListReloadFinished(VcpMenuPos mediaPos)
{
	// continue to scan folder when reload finished if scan folder has not been finished
	if(!m_isPrepared)
	{
		MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PICTURE_ON_FOLDER_SCAN_RELOAD_FINISH, mediaPos.group, mediaPos.pos);
		scanNextFolder();
	}
	// refresh list menu when reload finished if scan folder has already finished
	else if(m_pSignalFolderReloadFinished)
	{
		m_pSignalFolderReloadFinished->postEmit(mediaPos);
	}
}

void VappGalleryFolderFileList::scanNextFolder()
{  
	VfxU32 index = m_folderIndex;
#ifdef __VAPP_GALLERY_ENABLE_MY_RECEIVED_AS_THE_FIRST_FOLDER__
    // first entry is always "Received" folder
    index = m_folderIndex + 1;
#endif
    VfxWString path;   
    VcpMenuPos pos(0, index);
    if (m_imageFileList)
    {
        VFX_OBJ_CLOSE(m_imageFileList);
    }
    
    VFX_OBJ_CREATE(m_imageFileList, VappGalleryFmgrImageList, this);
    VappGalleryDecodeResult decodeResult = m_folderList->getPathName(pos, path);
    // [MAUI_03307593] do not assert when return value is not ok
	// VFX_ASSERT(decodeResult == OK);
	if(decodeResult == OK)
    {
	    m_imageFileList->configFolder(path, &m_signalSingleFolderFileListReady);
	    if (m_fileFilter)
	    {
	        m_imageFileList->configFileTypeLimit(m_fileFilter);
	    }
	    m_imageFileList->prepare();
	}
}

void VappGalleryFolderFileList::onSingleFolderFileListReady(VappGalleryPrepareResult prepareResult)
{
    VfxU32 index = MY_PICTURE_SUBFOLDER_INDEX + m_folderIndex;
	if (index >= m_folderCount)
    {
        m_signalFolderScanReady.postEmit(prepareResult);
        return;
    }
    m_fileCountList[index] = m_imageFileList->getTotalFileCount();
    ++m_folderIndex;
    scanNextFolder();
}

void VappGalleryFolderFileList::getRootFolder(VfxWString &path, 
                                           const VappGalleryFmgrDefaultFolder::DEFAULT_FOLDER_TYPE type)
{
    VappGalleryStorageSetting setting;
    const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(setting.getDefaultStorage());
    VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                                    defaultDrv,
                                                    type,
                                                    path);
}

void VappGalleryFolderFileList::onFolderScanReady(VappGalleryPrepareResult prepareResult)
{
    // start get My Picture image count
    if (m_imageFileList)
    {
        VFX_OBJ_CLOSE(m_imageFileList);
    }

    VFX_OBJ_CREATE(m_imageFileList, VappGalleryFmgrImageList, this);
    m_signalImageFileListReady.connect(this, &VappGalleryFolderFileList::onImageFileListReady);
    VfxWString rootFolder;
    getRootFolder(rootFolder);
    m_imageFileList->configFolder(rootFolder, &m_signalImageFileListReady);
    if (m_fileFilter)
    {
        m_imageFileList->configFileTypeLimit(m_fileFilter);
    }
    m_imageFileList->prepare();
}

void VappGalleryFolderFileList::onImageFileListReady(VappGalleryPrepareResult prepareResult)
{
    m_fileCountList[MY_PICTURE_FOLDER_INDEX] = m_imageFileList->getTotalFileCount();
    // scan my received image count
    if(NULL == m_receivedImageFileList)
    {
        VFX_OBJ_CREATE(m_receivedImageFileList, VappGalleryFmgrImageList, this);
        m_signalReceivedImageFileListReady.connect(this, &VappGalleryFolderFileList::onReceivedImageFileListReady);
        VfxWString rootFolder;
        getRootFolder(rootFolder, VappGalleryFmgrDefaultFolder::MY_RECEIVED);
        m_receivedImageFileList->configFolder(rootFolder, &m_signalReceivedImageFileListReady);

        if (m_fileFilter)
        {
            m_receivedImageFileList->configFileTypeLimit(m_fileFilter);
        }
    }

    m_receivedImageFileList->prepare();
}

void VappGalleryFolderFileList::onReceivedImageFileListReady(VappGalleryPrepareResult prepareResult)
{
    VFX_ASSERT(m_imageFileList->isPrepared() && 
        m_folderList->isPrepared() && 
        m_receivedImageFileList->isPrepared() &&
        m_pSignalAllFolderScanReady != NULL);
    
    m_fileCountList[MY_RECEIVED_FOLDER_INDEX] = m_receivedImageFileList->getTotalFileCount();   
	m_isPrepared = VFX_TRUE;
    m_pSignalAllFolderScanReady->postEmit(prepareResult);
}

VfxBool VappGalleryFolderFileList::isPrepared() const
{ 
    return m_isPrepared;
}

VfxU32 VappGalleryFolderFileList::getFolderCount() const 
{
    return (m_folderList && m_folderList->isPrepared()) ? m_folderCount : 0;
}

VfxU32 VappGalleryFolderFileList::getFileCount(VfxU32 index) const 
{
    return isPrepared() ? m_fileCountList[index] : 0;
}
    
VfxBool VappGalleryFolderFileList::getFolderPath(VfxU32 index, 
    VfxWString &path)
{
    VfxBool bRet = VFX_TRUE;
    if (index == 0)
    {
        getRootFolder(path);
    }
    else if (index == 1)
    {
        getRootFolder(path, VappGalleryFmgrDefaultFolder::MY_RECEIVED);
    }
    else
    {
#ifdef __VAPP_GALLERY_ENABLE_MY_RECEIVED_AS_THE_FIRST_FOLDER__
        // first entry is always "Received" folder
        index = index + 1;
#endif
        VcpMenuPos pos(0, index - 2);
        bRet = m_folderList->getPathName(pos, path) == OK;
    }
    return bRet;
}

VfxBool VappGalleryFolderFileList::getFolderName(VfxU32 index, 
    VfxWString &caption)
{
    VfxBool bRet = VFX_TRUE;
    if (index == 0)
    {
        caption = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IDX_PICTURE);
    }
    else if (index == 1)
    {
        caption = VFX_WSTR_RES(STR_ID_VAPP_FMGR_MYRECEIVED);
    }
    else
    {
#ifdef __VAPP_GALLERY_ENABLE_MY_RECEIVED_AS_THE_FIRST_FOLDER__
        // first entry is always "Received" folder
        index = index + 1;
#endif
        VcpMenuPos pos(0, index - 2);
        bRet = m_folderList->getFileName(pos, caption) == OK;
    }
    return bRet;
}


class VappGalleryPictureItemCell : public VcpListMenuCellClientBaseFrame
{
public:
	enum ImageFolderType
	{
		MY_PICTURE_FOLDER,
		MY_RECEIVED_FOLDER,
		MY_PICTURE_SUB_FOLDER
	};
private:
    VfxTextFrame *m_folderNameDes;                // folder name label
    VfxTextFrame *m_imageCountDes;             // image count label
    VfxWString m_folderName;
    VfxU32 m_imageCount;
	VfxImageFrame *m_icon;
	ImageFolderType m_folderType;

public:
    VappGalleryPictureItemCell() :
      m_folderNameDes(NULL), 
      m_imageCountDes(NULL),
      m_imageCount(0), 
      m_icon(NULL)
    {
        m_folderName.setNull();
    }

    VfxU32 getDescriptionCount() const
    {
        return 0;
    }

    void setItemInfo(VfxWString &folderName, VfxU32 imageCount, ImageFolderType folderType)
    {
        m_folderName = folderName;
        m_imageCount = imageCount;
		m_folderType = folderType;
    }

public:

    // create icon and text fields
    virtual void onCreateElements()
    {
        VFX_OBJ_CREATE(m_folderNameDes, VfxTextFrame, this);
        m_folderNameDes->setAutoFontSize(VFX_FALSE);
        m_folderNameDes->setAutoResized(VFX_FALSE);
        m_folderNameDes->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VappGalleryPicturePage::FONT_SIZE_CAPTION)));
        m_folderNameDes->setSize(VappGalleryPicturePage::TEXT_W, VappGalleryPicturePage::TEXT_CAPTION_H);
        m_folderNameDes->setColor(VfxColor(VappGalleryPicturePage::TEXT_CAPTION_COLOR));
        m_folderNameDes->setAutoAnimate(VFX_TRUE);

        VFX_OBJ_CREATE(m_imageCountDes, VfxTextFrame, this);
        m_imageCountDes->setAutoFontSize(VFX_FALSE);
        m_imageCountDes->setAutoResized(VFX_FALSE);
        m_imageCountDes->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VappGalleryPicturePage::FONT_SIZE_DESC)));
        m_imageCountDes->setSize(VappGalleryPicturePage::TEXT_W, VappGalleryPicturePage::TEXT_CAPTION_H);
        m_imageCountDes->setColor(VfxColor(VappGalleryPicturePage::TEXT_CAPTION_COLOR));
        m_imageCountDes->setAutoAnimate(VFX_TRUE);
		
		// front thumb
		VFX_OBJ_CREATE(m_icon, VfxImageFrame, this);
		m_icon->setSize(VappGalleryPicturePage::FRONT_THUMB_W, VappGalleryPicturePage::FRONT_THUMB_H);
		m_icon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
		m_icon->setPos(VappGalleryPicturePage::FRONT_THUMB_CX,
							 VappGalleryPicturePage::FRONT_THUMB_CY);

	}

    // release children frame
    virtual void onCloseElements()
    {
        VFX_OBJ_CLOSE(m_folderNameDes);        
        VFX_OBJ_CLOSE(m_imageCountDes);
        VFX_OBJ_CLOSE(m_icon);
    }

    virtual void onLayoutElements()
    {
        VFX_DEV_ASSERT(m_folderNameDes && m_icon && m_imageCountDes);

        // fade-in
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_FALSE);
        VfxAutoAnimate::setDuration(/*ANIM_SLOW_TIMING*/500);
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE);

		m_icon->setResId(m_folderType == MY_PICTURE_FOLDER ? IMG_ID_VAPP_GALLERY_IDX_PICTURE_ICON : IMG_ID_VAPP_GALLERY_PICTURE_FOLDER_ICON);
        m_folderNameDes->setPos(VappGalleryPicturePage::TEXT_MARGIN_L, (getSize().height - getTotalTextHeight()) / 2);

		// we update textPos after adding each description item
        VfxS32 textPos = (VappGalleryPicturePage::MENU_H - getTotalTextHeight()) / 2;
        // skip the caption text height & padding
        const VfxS32 linePadding = VappGalleryPicturePage::PAD_TWO_LINE;
        textPos += VappGalleryPicturePage::TEXT_CAPTION_H + linePadding;
        m_imageCountDes->setPos(VappGalleryPicturePage::TEXT_MARGIN_L, textPos + VappGalleryPicturePage::DESC_FADEIN_OFFSET);
        VfxAutoAnimate::commit();

		// display when only folder name is not empty
		if(m_folderName.isEmpty())
		{
			return;
		}
        m_folderNameDes->setString(m_folderName);
        VfxWString text;
        text.format("%d  ", m_imageCount);
		text += VFX_WSTR_RES(m_imageCount <= 1 ?    
			STR_ID_VAPP_GALLERY_IDX_IMAGE_COUNT_SUFFIX_SINGLE :
            STR_ID_VAPP_GALLERY_IDX_IMAGE_COUNT_SUFFIX);     
        m_imageCountDes->setString(text);
    }      

    VfxS32 getTotalTextHeight()
    {
    	const VfxS32 captionH = VappGalleryPicturePage::TEXT_CAPTION_H;
        const VfxS32 descH = VappGalleryPicturePage::TEXT_DESC_H;
        const VfxS32 linePadding = VappGalleryPicturePage::PAD_TWO_LINE;
        return captionH + descH + linePadding;
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
        if(m_folderNameDes)
        {
            m_folderNameDes->setColor(captionColor);
        }
        if(m_imageCountDes)
        {
            m_imageCountDes->setColor(captionColor);
        }
    }
};

VFX_IMPLEMENT_CLASS("VappGalleryPicturePage", VappGalleryPicturePage, VappGalleryPage);

VappGalleryPicturePage::VappGalleryPicturePage() :
    m_folderFileList(NULL), 
    m_folderListMenu(NULL)   
{
}

void VappGalleryPicturePage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PICTURE_ON_INIT);
    VappGalleryPage::onInit(); // call base class
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
    // title bar
    VcpTitleBar *bar = NULL;
    VFX_OBJ_CREATE(bar, VcpTitleBar, this);
    bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IDX_PICTURE));
    setTopBar(bar);
}

void VappGalleryPicturePage::onExited2()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PICTURE_ON_EXITED);
    // close all components
    VFX_OBJ_CLOSE(m_folderListMenu);
    VFX_OBJ_CLOSE(m_folderFileList);
    VappGalleryPage::onExited2();
}

void VappGalleryPicturePage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PICTURE_ON_ENTERED);
    // list menu
    if(NULL == m_folderListMenu)
    {
        VFX_OBJ_CREATE(m_folderListMenu, VcpListMenu, this);
        m_folderListMenu->setSize(getSize().width, getSize().height);
        m_folderListMenu->setItemHeight(VappGalleryPicturePage::MENU_H);
        m_folderListMenu->setContentProvider(this);
        m_folderListMenu->setCellStyle(VCP_LIST_MENU_CELL_STYLE_CUSTOM);
        m_folderListMenu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_FALSE);
        m_folderListMenu->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_NORMAL, VFX_FALSE);
        m_folderListMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);
        m_folderListMenu->m_signalItemTapped.connect(this, &VappGalleryPicturePage::onFolderTapped);
        m_folderListMenu->setHidden(VFX_TRUE);
    }
    
    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

	showPageWaitIcon(VFX_TRUE);    
    //checkUpdate();
    startRefreshUI();
}

void VappGalleryPicturePage::onUpdate()
{
    if (m_folderListMenu)
    {
        m_folderListMenu->setHidden(VFX_FALSE);
        m_folderListMenu->updateAllItems();
    }
    VappGalleryPage::onUpdate();
}

VfxU32 VappGalleryPicturePage::getCount() const
{
    return m_folderFileList && m_folderFileList->isPrepared() ? m_folderFileList->getFolderCount() : 0;
}

VcpListMenuItemStateEnum VappGalleryPicturePage::getItemState(VfxU32 index) const
{
    return VCP_LIST_MENU_ITEM_STATE_NONE;
}

VcpListMenuCellClientBaseFrame *VappGalleryPicturePage::getItemCustomContentFrame(VfxU32 index, VfxFrame *parentFrame)
{
    VappGalleryPictureItemCell *pCellFrame = NULL;
    VFX_OBJ_CREATE(pCellFrame, VappGalleryPictureItemCell, parentFrame);

	VfxWString folderName;
	VfxU32 fileCount = 0;
    if (m_folderFileList && m_folderFileList->isPrepared() && m_folderFileList->getFolderName(index, folderName))
	{
	    fileCount = m_folderFileList->getFileCount(index);
	}	
	
    pCellFrame->setItemInfo(folderName, 
		fileCount, 
		index == 0 ? VappGalleryPictureItemCell::MY_PICTURE_FOLDER : VappGalleryPictureItemCell::MY_PICTURE_SUB_FOLDER);
    return pCellFrame;
}

// Provide custom cells for layout
void VappGalleryPicturePage::closeItemCustomContentFrame(VfxU32 index, VcpListMenuCellClientBaseFrame *pCell)
{
    VFX_OBJ_CLOSE(pCell);
    return;
}


void VappGalleryPicturePage::startRefreshUI()
{
    // fisrt start scan all sub-folders, calculate folder count
    if(NULL == m_folderFileList)
    {
        VFX_OBJ_CREATE(m_folderFileList, VappGalleryFolderFileList, this);
        VcuiGalleryPickerBase *cui = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryPickerBase);
        if(cui)
        {
            m_folderFileList->config(&m_signalFolderScanListReady, 
				&m_signalFolderReloadStart,
    			&m_signalFolderReloadFinished,
				cui->getTypeFilter());
        }
        else
        {
            m_folderFileList->config(&m_signalFolderScanListReady,
				&m_signalFolderReloadStart,
				&m_signalFolderReloadFinished);
        }
        m_signalFolderReloadStart.connect(this, &VappGalleryPicturePage::onFolderListReloadStart);
		m_signalFolderReloadFinished.connect(this, &VappGalleryPicturePage::onFolderListReloadFinished);
        m_signalFolderScanListReady.connect(this, &VappGalleryPicturePage::onFolderScanReady);
    }
    
    m_folderFileList->prepare();
}

void VappGalleryPicturePage::onFolderListReloadStart(VcpMenuPos mediaPos)
{
	// show loading icon when update list menu item if folder name is on reload status
	MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PICTURE_ON_FOLDER_LIST_RELOAD_START, mediaPos.group, mediaPos.pos);
	showPageWaitIcon(VFX_TRUE);
}

void VappGalleryPicturePage::onFolderListReloadFinished(VcpMenuPos mediaPos)
{
	// refresh list menu when reload finished if scan folder has already finished
	VappGalleryPictureItemCell *item = NULL;
	VcpMenuPos p;
	VcpMenuRegionIter itr(m_folderListMenu, m_folderListMenu->getRealContentRegion());
	VfxWString folderName;
	MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_SLIM_PICTURE_ON_FOLDER_LIST_RELOAD_FINISH, mediaPos.group, mediaPos.pos);
    while(!itr.isEnd())
    {
        p = itr.next();
       	item = (VappGalleryPictureItemCell *)m_folderListMenu->getContentFrame(p.pos);
	    if(item && m_folderFileList)
	    {
	       	if(!m_folderFileList->getFolderName(p.pos, folderName))
        	{
        		continue;
        	}
			item->setItemInfo(folderName, 
				m_folderFileList->getFileCount(p.pos), 
				p.pos == 0 ? VappGalleryPictureItemCell::MY_PICTURE_FOLDER : VappGalleryPictureItemCell::MY_PICTURE_SUB_FOLDER);
       	    item->update(VFX_TRUE);
        }
    }
	showPageWaitIcon(VFX_FALSE);	
}

void VappGalleryPicturePage::onFolderScanReady(VappGalleryPrepareResult prepareResult)
{
    VFX_ASSERT(m_folderFileList && m_folderFileList->isPrepared());
	checkUpdate();
	showPageWaitIcon(VFX_FALSE);
}

void VappGalleryPicturePage::onFolderTapped(VcpListMenu *sender, VfxU32 index)
{
    VFX_ASSERT(sender == m_folderListMenu);
    VfxWString folderPath;
    VfxWString caption;
    if ((VFX_FALSE == m_folderFileList->getFolderPath(index, folderPath)) || 
        (VFX_FALSE == m_folderFileList->getFolderName(index, caption)))
    {
        return;
    }
    gotoFolderThumbnailPage(folderPath, caption);
}

void VappGalleryPicturePage::gotoFolderThumbnailPage(const VfxWString &folder, const VfxWString &caption)
{
    VappGalleryShootingPage *thumbnailPage = NULL;
    VFX_OBJ_CREATE(thumbnailPage, VappGalleryShootingPage, getMainScr());

    // configure source folder and page title
    thumbnailPage->configNoCameraButton(VFX_TRUE);
    thumbnailPage->configCustomFolder(folder, VappGalleryShootingPage::ALLOW_IMAGE);
    thumbnailPage->setCustomTitle(caption);

    // goto the page
    // previous id is err PN_MY_SHOOTING
    getMainScr()->pushPage(PN_MY_PICTURE, thumbnailPage);
    return;
}

void VappGalleryPicturePage::getRootFolder(VfxWString &path, 
                                           const VappGalleryFmgrDefaultFolder::DEFAULT_FOLDER_TYPE type)
{
    VappGalleryStorageSetting setting;
    const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(setting.getDefaultStorage());
    VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                                    defaultDrv,
                                                    type,
                                                    path);
}

#endif

