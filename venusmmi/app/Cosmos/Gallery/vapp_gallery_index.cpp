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

#ifdef __MMI_FTO_GALLERY__
#include "mmi_rp_vapp_gallery_def.h"
#include "mmi_rp_vapp_fmgr_def.h"
#include "vapp_gallery_index.h"
#include "vapp_gallery_data.h"
#include "vapp_gallery_setting.h"
#include "vapp_gallery_shooting.h"
#include "vapp_gallery_picture.h"
#include "vapp_gallery_video.h"
#include "vapp_gallery_util.h"
#include "vapp_gallery_file_operation.h"
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
IVappGalleryMediaCollection* collectionFactory(PageName name, VfxObject *parent, VfxApp *app);

VappGalleryIndexMenuItem VappGalleryIndexPage::g_indexMenuItems[3] = {\
    // Page name     Collection factory     Title                              Default icon                            Badge (on the thumbnail)
    {PN_MY_SHOOTING, &collectionFactory,          STR_ID_VAPP_GALLERY_IDX_SHOOTING,  IMG_ID_VAPP_GALLERY_IDX_SHOOTING_ICON,  IMG_ID_VAPP_GALLERY_IDX_SHOOTING_BADGE},
    {PN_MY_PICTURE,  &collectionFactory,          STR_ID_VAPP_GALLERY_IDX_PICTURE,   IMG_ID_VAPP_GALLERY_IDX_PICTURE_ICON,   NULL},
    {PN_MY_VIDEO,    &collectionFactory,          STR_ID_VAPP_GALLERY_IDX_VIDEO,     IMG_ID_VAPP_GALLERY_IDX_VIDEO_ICON,     IMG_ID_VAPP_GALLERY_IDX_VIDEO_BADGE},
};

class VappGalleryCollectionBase : public VfxObject, public IVappGalleryMediaCollection
{
public:
    VappGalleryCollectionBase():
        m_pDB(NULL)
		,m_frontThumbBuffer(NULL)
        ,m_appId(NULL)
    {
    }

public:
    virtual void onInit()
    {
        VfxObject::onInit();
        m_pDB = NULL;

        // repare front/back thumbnail cache buffer
        m_appId = findRootAppId(this);
    }

    virtual void releaseLists()
    {
        stopQuery();
        destroyFmgrList();
    }

    virtual void reset(const VappGalleryCollectionSetting &setting)
    {
        // clear all previous states
        stopQuery();
        resetQueryState();
        destroyFmgrList();

        configDB(setting.m_pDB);

        // initialize new settings
        m_setting = setting;
        // allow derived to customize file lists.
        m_signalListReady.connect(this, &VappGalleryCollectionBase::onListReady);
        createFmgrList(&m_signalListReady, &m_setting);
    }

    virtual void onDeinit()
    {
        unlockThumb();
        m_pDB = NULL;
        VfxObject::onDeinit();
    }

    virtual void destroy()
    {
        VappGalleryCollectionBase *pThis = this;
        VFX_OBJ_CLOSE(pThis);
    }

    virtual void lockThumb()
    {
         if(NULL == m_frontThumbBuffer)
         {
             VFX_OBJ_CREATE(m_frontThumbBuffer, VappGalleryCachedImage, this);
         }
         if(NULL == m_frontThumbBuffer->m_bufPtr)
         {
            m_frontThumbBuffer->lockBuffer(m_appId, IndexPageLayout::FRONT_THUMB_W, IndexPageLayout::FRONT_THUMB_H);
         }
    }

    virtual void unlockThumb()
    {
        if(m_frontThumbBuffer)
            m_frontThumbBuffer->unlockBuffer();
    }

//overridable
protected:

    // derived class should create they own file lists,
    // and the listReadySignal should be emitted when the all the file-lists are ready.
    virtual void createFmgrList(IVappGalleryMediaList::ListEvent *listReadySignal, VappGalleryCollectionSetting *setting) = 0;

    // derived class should stop & destroy their own file lists.
    virtual void destroyFmgrList() = 0;

    // derived class should clear their state to before query.
    virtual void resetQueryState() = 0;

    // derived should prepare text description from list results
    // or they can be created on the fly in queryDescription
    virtual void prepareDescFromList() = 0;


protected:
    void onListReady(VappGalleryPrepareResult prepareResult)
    {
        prepareDescFromList();
        m_descReadySignal.emit(0, DONE);
    }

// method
public:
    void configDB(VappGalleryDB *pDB)
    {
        m_pDB = pDB;
    }
    virtual DescriptionUpdateSignal* getDescriptionUpdateSignal()
    {
        return &m_descReadySignal;
    }

    virtual ThumbnailUpdateSignal* getThumbnailUpdateSignal()
    {
        return &m_thumbReadySignal;
    }

protected:
    VfxWeakPtr <VappGalleryDB> m_pDB;
    VappGalleryCachedImage *m_frontThumbBuffer;
    mmi_id m_appId;
    DescriptionUpdateSignal m_descReadySignal;
    ThumbnailUpdateSignal m_thumbReadySignal;
    IVappGalleryMediaList::ListEvent m_signalListReady;
    VappGalleryCollectionSetting m_setting;   // settings used to initialize the collection
    friend class VappGalleryCollectionDecoderOutput;
};

class VappGalleryCollectionDecoderOutput : public VappGalleryFolderThumbnailDecoderOutputBase
{

public:
    VappGalleryCollectionDecoderOutput():
        m_pCollection(NULL)
    {
    }

    void config(VappGalleryCollectionBase *pCollection)
    {
        m_pCollection = pCollection;
    }

// impelements VappGalleryFolderThumbnailDecoderOutputBase
public:
    // total file count in the folder
    virtual void setFileCount(VfxS32 fileCount)
    {
        // we don't really need the file count.
        // collections handle their own file count
        return;
    }

    // thumbnail buffer count that can be filled by decoder
    virtual VfxS32 getMaxThumbCount()
    {
        // decode front thumbnail only
        return 1;
    }

    // successfully decoded thumbnail count
    virtual void setDecodedThumbCount(VfxS32 thumbCount)
    {
        m_decodedThumbCount = thumbCount;
    }

    // retrieve a thumbnail buffer for decoder to write
    virtual VfxImageBuffer getImageBuffer(VfxS32 thumbIndex) const
    {
        VFX_ASSERT(m_pCollection);

        VfxImageSrc imgSrc;
        m_pCollection->m_frontThumbBuffer->fillImageSrc(imgSrc);
        return imgSrc.getImageBuffer();
    }

public:
    VappGalleryCollectionBase *m_pCollection;
    VfxS32 m_decodedThumbCount;
};

class VappGalleryShootingCollection : public VappGalleryCollectionBase
{
public:
    VappGalleryShootingCollection():
        VappGalleryCollectionBase(),
        m_photoCount(0),
        m_videoCount(0),
        m_queryFinished(VFX_FALSE),
        m_showPhotoOnly(VFX_FALSE),
        m_showVideoOnly(VFX_FALSE),
        m_fileList(NULL),
        m_decoder(NULL),
        m_decoderOutput(NULL),      
        m_decodedThumbCount(0)
    {
    }

// override
protected:
    virtual void createFmgrList(IVappGalleryMediaList::ListEvent *listReadySignal, VappGalleryCollectionSetting *setting)
    {
        // close folder decoders since we're going to change file list
        VFX_OBJ_CLOSE(m_decoder);
        VFX_OBJ_CLOSE(m_decoderOutput);
        m_decodedThumbCount = 0;

        VFX_ASSERT(setting);
        VFX_OBJ_CREATE(m_fileList, VappGalleryFmgrImageVideoList, this);
        const U8 drv = srv_fmgr_drv_get_letter_by_type(setting->m_storage);
        VfxWString shootingFolder;
        VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                                drv,
                                                VappGalleryFmgrDefaultFolder::MY_SHOOTING,
                                                shootingFolder);
        m_fileList->configFolder(shootingFolder, listReadySignal);
        m_fileList->configFileTypeLimit(&setting->m_filter);
        m_fileList->configSortMethod(FS_SORT_TIME);
    }

    virtual void destroyFmgrList()
    {
        VFX_OBJ_CLOSE(m_fileList);
        // close folder decoders since we're going to change file list
        VFX_OBJ_CLOSE(m_decoder);
        VFX_OBJ_CLOSE(m_decoderOutput);
        m_decodedThumbCount = 0;
    }

    virtual void resetQueryState()
    {
        m_queryFinished = VFX_FALSE;
        VFX_OBJ_CLOSE(m_decoder);
        VFX_OBJ_CLOSE(m_decoderOutput);
        m_decodedThumbCount = 0;
    }

    virtual void prepareDescFromList()
    {
        // loop through file list and check file types
        m_photoCount = 0;
        m_videoCount = 0;

        const VfxU32 fileCount = m_fileList->getTotalFileCount();
        SRV_FMGR_FILELIST_HANDLE hList = m_fileList->getFileList();
        srv_fmgr_fileinfo_struct fileInfo;
        memset(&fileInfo, 0, sizeof(fileInfo));
        for(VfxU32 i = 0; i < fileCount; ++i)
        {
            srv_fmgr_filelist_get_fileinfo(hList, i, &fileInfo);
            filetypes_group_type_enum group = srv_fmgr_types_find_group_by_type((filetypes_file_type_enum)fileInfo.type);
            if(FMGR_GROUP_IMAGE == group)
                ++m_photoCount;
            if(FMGR_GROUP_VIDEO == group)
                ++m_videoCount;
        }

        if(m_photoCount == 0 &&
           m_videoCount == 0)
        {
            m_queryFinished = VFX_TRUE;
            // release file list to save memory
            VFX_OBJ_CLOSE(m_fileList);
            // notify client that thumbnails are ready(no thumb)
            m_thumbReadySignal.postEmit(0, DONE);
        }
        else
        {
            // we have to wait for decoder finish
            m_queryFinished = VFX_FALSE;

            // start decoding with folder decoder.
            // we must not release file list until decoding finished
            VFX_OBJ_CLOSE(m_decoder);
            VFX_OBJ_CLOSE(m_decoderOutput);
            lockThumb();
            m_decodedThumbCount = 0;
            m_frontThumbBuffer->setValid(VFX_FALSE);

            VFX_OBJ_CREATE(m_decoder, VappGalleryFolderThumbnailDecoder, this);
            VFX_OBJ_CREATE(m_decoderOutput, VappGalleryCollectionDecoderOutput, this);
            m_decoderOutput->config(this);
            m_decoder->config(m_decoderOutput, m_fileList, NULL, NULL);
            m_decoder->getDecodeSignal()->connect(this, &VappGalleryShootingCollection::onFolderThumbnailDecodeResult);
            m_decoder->start();
        }
    }

public:
    virtual VfxBool startQuery()
    {
        if(m_queryFinished || NULL == m_fileList)
        {
            return VFX_FALSE;
        }

        m_fileList->prepare();
        return VFX_TRUE;
    }

    virtual void stopQuery()
    {
        VFX_OBJ_CLOSE(m_decoder);
        VFX_OBJ_CLOSE(m_decoderOutput);
        if(m_queryFinished)
        {
            return;
        }
        if(m_fileList)
        {
            m_fileList->stop();
        }
    }

    virtual VfxBool isQueryFinished()
    {
        return m_queryFinished;
    }

    virtual QueryResult queryDescriptionCount(VfxU32 &count)
    {
        if(!m_queryFinished)
        {
            count = 0;
            return DONE;
        }

        // under image picker CUI, display image count only.
        if(m_showPhotoOnly || m_showVideoOnly)
        {
            count = 1;
            return DONE;
        }
        if(0 == m_photoCount && 0 == m_videoCount)
        {
            count = 1;
            return DONE;
        }

        count = 2;
        return DONE;
    }

    virtual QueryResult queryDescription(VfxU32 index, VfxWString &description)
    {
        if(index >= 2)
            return ERROR;

        if(!m_queryFinished)
        {
            description = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IDX_SCANNING);
            return DONE;
        }

        if(m_showPhotoOnly && 0 == m_photoCount)
        {
            description = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_NO_PHT);
            return DONE;
        }

        if(m_showVideoOnly && 0 == m_videoCount)
        {
            description = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_NO_VID);
            return DONE;
        }

        if(0 == m_photoCount && 0 == m_videoCount)
        {
            description = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_NO_IMG_VID);
            return DONE;
        }

        if(m_showPhotoOnly || (!m_showVideoOnly && index == 0))
        {
            // photo
            description.format("%d ", m_photoCount);
            description += VFX_WSTR_RES(m_photoCount <= 1 ?
                                        STR_ID_VAPP_GALLERY_IDX_PHOTO_COUNT_SUFFIX_SINGLE :
                                        STR_ID_VAPP_GALLERY_IDX_PHOTO_COUNT_SUFFIX);
        }
        else if(m_showVideoOnly || index == 1)
        {
            // video
            description.format("%d ", m_videoCount);
            description += VFX_WSTR_RES(m_videoCount <= 1 ?
                                        STR_ID_VAPP_GALLERY_IDX_VIDEO_COUNT_SUFFIX_SINGLE :
                                        STR_ID_VAPP_GALLERY_IDX_VIDEO_COUNT_SUFFIX);
        }

        return DONE;
    }

    virtual QueryResult queryThumbnailCount(VfxU32 &count)
    {
        if(!isQueryFinished())
        {
            count = 0;
            return DONE;
        }

        count = m_decodedThumbCount;
        return DONE;
    }

    virtual QueryResult lockThumbnail(VfxU32 index, VfxImageSrc &imgSrc)
    {
        if((S32)index >= m_decodedThumbCount)
        {
            return ERROR;
        }

        if(m_frontThumbBuffer->isValid() && m_frontThumbBuffer->fillImageSrc(imgSrc))
        {
            return DONE;
        }
        return ERROR;
    }

    virtual void unlockAllThumbnail(VfxU32 index, VfxImageSrc &imgSrc)
    {
        // thumbnail buffers are allocated along with collection.
        // so no need to free.
        return;
    }


public:
    void showPhotoDescriptionOnly(VfxBool showPhotoOnly)
    {
        m_showPhotoOnly = showPhotoOnly;
    }

    void showVideoDescriptionOnly(VfxBool showVideoOnly)
    {
        m_showVideoOnly = showVideoOnly;
    }

protected:
    void onFolderThumbnailDecodeResult(VappGalleryFolderThumbnailDecoder *decoder, VappGalleryDecodeResult res)
    {
        m_decodedThumbCount = m_decoderOutput->m_decodedThumbCount;
        VFX_OBJ_CLOSE(m_decoder);
        VFX_OBJ_CLOSE(m_decoderOutput);
        VFX_OBJ_CLOSE(m_fileList);

        m_frontThumbBuffer->setValid(m_decodedThumbCount > 0);
        m_queryFinished = VFX_TRUE;
        m_thumbReadySignal.emit(0, DONE);
    }

protected:
    VfxU32 m_photoCount;
    VfxU32 m_videoCount;
    VfxBool m_queryFinished;
    VfxBool m_showPhotoOnly;
    VfxBool m_showVideoOnly;
    VappGalleryFmgrImageVideoList *m_fileList;
    VappGalleryFolderThumbnailDecoder *m_decoder;
    VappGalleryCollectionDecoderOutput *m_decoderOutput;
    VfxS32 m_decodedThumbCount;
    VfxWString m_frontThumbPath;
};

class VappGalleryPictureCollection : public VappGalleryCollectionBase
{
public:
    VappGalleryPictureCollection():
        VappGalleryCollectionBase(),
		m_queryFinished(VFX_FALSE),
		m_photoCount(0),
		m_folderCount(0),
        m_receivedPhotoCount(0),
        m_photoList(NULL),
        m_folderList(NULL),
        m_receivedPhotoList(NULL),      
        m_decoder(NULL),
        m_decoderOutput(NULL)
    {
    }

// override
protected:
    virtual void createFmgrList(IVappGalleryMediaList::ListEvent *listReadySignal, VappGalleryCollectionSetting *setting)
    {
        // make sure decoder is destroyed
        VFX_OBJ_CLOSE(m_decoder);
        VFX_OBJ_CLOSE(m_decoderOutput);
        m_decodedThumbCount = 0;

        VFX_OBJ_CREATE(m_photoList, VappGalleryFmgrImageList, this);
        VFX_OBJ_CREATE(m_folderList, VappGalleryFmgrFolderList, this);
        VFX_OBJ_CREATE(m_receivedPhotoList, VappGalleryFmgrImageList, this);

        VfxWString pictureFolder;
        const U8 drv = setting->getDefaultDrive();
        VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                                drv,
                                                VappGalleryFmgrDefaultFolder::MY_PICTURE,
                                                pictureFolder);
        // start scan image files first.
        m_photoList->configFolder(pictureFolder, &m_signalPhotoListReady);
        m_photoList->configFileTypeLimit(&setting->m_filter);
        m_signalPhotoListReady.connect(this, &VappGalleryPictureCollection::onPhotoListReady);

        // once folder list complete, notify base class.
        // note folder list ignores extra file filter
        m_folderList->config(drv, listReadySignal);

        // receive folder case
        VfxWString receiveFolder;
        VappGalleryFmgrDefaultFolder::getFolderPathFromDrv(
                                                drv,
                                                VappGalleryFmgrDefaultFolder::MY_RECEIVED,
                                                receiveFolder);

        // start scan image files first.
        m_receivedPhotoList->configFolder(receiveFolder, &m_signalReceivedPhotoListReady);
        m_receivedPhotoList->configFileTypeLimit(&setting->m_filter);
        m_signalReceivedPhotoListReady.connect(this, &VappGalleryPictureCollection::onRecievedPhotoListReady);
    }


    virtual void destroyFmgrList()
    {
        VFX_OBJ_CLOSE(m_photoList);
        VFX_OBJ_CLOSE(m_folderList);
        VFX_OBJ_CLOSE(m_receivedPhotoList);
        VFX_OBJ_CLOSE(m_decoder);
        VFX_OBJ_CLOSE(m_decoderOutput);
        m_decodedThumbCount = 0;
    }

    virtual void resetQueryState()
    {
        m_queryFinished = VFX_FALSE;
        VFX_OBJ_CLOSE(m_decoder);
        VFX_OBJ_CLOSE(m_decoderOutput);
        m_decodedThumbCount = 0;
    }

    virtual void prepareDescFromList()
    {
        m_photoCount = m_photoList->getTotalFileCount();
        m_folderCount = m_folderList->getTotalFileCount();
        m_receivedPhotoCount = m_receivedPhotoList->getTotalFileCount();

        if(m_photoCount)
        {
            // we have to wait for decoder finish
            m_queryFinished = VFX_FALSE;

            // start decoding with folder decoder.
            // we must not release file list until decoding finished
            VFX_OBJ_CLOSE(m_decoder);
            VFX_OBJ_CLOSE(m_decoderOutput);
            lockThumb();
            m_decodedThumbCount = 0;
            m_frontThumbBuffer->setValid(VFX_FALSE);

            VFX_OBJ_CREATE(m_decoder, VappGalleryFolderThumbnailDecoder, this);
            VFX_OBJ_CREATE(m_decoderOutput, VappGalleryCollectionDecoderOutput, this);
            m_decoderOutput->config(this);
            m_decoder->config(m_decoderOutput, m_photoList, NULL, NULL);
            m_decoder->getDecodeSignal()->connect(this, &VappGalleryPictureCollection::onFolderThumbnailDecodeResult);
            m_decoder->start();
        }
        else
        {
            m_queryFinished = VFX_TRUE;
            // release list to save memory
            VFX_OBJ_CLOSE(m_photoList);
            VFX_OBJ_CLOSE(m_folderList);

            // notify client that thumnails are ready (no thumb)
            m_thumbReadySignal.postEmit(0, DONE);
        }
        return;
    }

public:
    virtual VfxBool startQuery()
    {
        if(m_queryFinished || NULL == m_photoList)
        {
            return VFX_FALSE;
        }

        m_photoList->prepare();
        return VFX_TRUE;
    }

    virtual void stopQuery()
    {
        if(m_queryFinished)
        {
            return;
        }

        if(m_photoList)
            m_photoList->stop();
        if(m_folderList)
            m_folderList->stop();
        if(m_receivedPhotoList)
            m_receivedPhotoList->stop();

        VFX_OBJ_CLOSE(m_decoder);
        VFX_OBJ_CLOSE(m_decoderOutput);

        return;
    }

    virtual VfxBool isQueryFinished()
    {
        return m_queryFinished;
    }

    virtual QueryResult queryDescriptionCount(VfxU32 &count)
    {
        if(!isQueryFinished())
        {
            count =  0;
            return DONE;
        }
        else if(0 == m_photoCount && 1 == m_folderCount && 0 == m_receivedPhotoCount)
        {
            count = 1;
            return DONE;
        }
        else
        {
            count = 2;
            return DONE;
        }
    }

    virtual QueryResult queryDescription(VfxU32 index, VfxWString &description)
    {
        if(index >= 2)
            return ERROR;

        if(!isQueryFinished())
        {
            description = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IDX_SCANNING);
            return DONE;
        }

        // empty case
        if(0 == m_photoCount && 1 == m_folderCount && 0 == m_receivedPhotoCount)
        {
            description = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_NO_IMG);
            return DONE;
        }

        // first line is image count
        // 2nd line is folder count
        switch(index)
        {
        case 0:
            {
                description.format("%d ", m_photoCount);
                description += VFX_WSTR_RES(m_photoCount <= 1 ?
                                            STR_ID_VAPP_GALLERY_IDX_IMAGE_COUNT_SUFFIX_SINGLE :
                                            STR_ID_VAPP_GALLERY_IDX_IMAGE_COUNT_SUFFIX);
                break;
            }
        case 1:
            {
                description.format("%d ", m_folderCount);
                description += VFX_WSTR_RES(m_folderCount <= 1 ?
                                            STR_ID_VAPP_GALLERY_IDX_FOLDER_COUNT_SUFFIX_SINGLE :
                                            STR_ID_VAPP_GALLERY_IDX_FOLDER_COUNT_SUFFIX);
                break;
            }
        default:
            return ERROR;
        }
        return DONE;
    }

    virtual QueryResult queryThumbnailCount(VfxU32 &count)
    {
        if(!isQueryFinished())
        {
            count = 0;
            return DONE;
        }

        count = m_decodedThumbCount;
        return DONE;
    }

    virtual QueryResult lockThumbnail(VfxU32 index, VfxImageSrc &imgSrc)
    {
        if((VfxS32)index >= m_decodedThumbCount)
        {
            return ERROR;
        }

        // decide which cache to fill
        if(m_frontThumbBuffer->isValid() && m_frontThumbBuffer->fillImageSrc(imgSrc))
        {
            return DONE;
        }
        return ERROR;
    }

    virtual void unlockAllThumbnail(VfxU32 index, VfxImageSrc &imgSrc)
    {
        // since front/back thumbnails are allocated by collection
        // there is no need to release them
        return;
    }

protected:
    void onPhotoListReady(VappGalleryPrepareResult prepareResult)
    {
        if(m_queryFinished)
        {
            return;
        }

        if(m_receivedPhotoList)
        {
            m_receivedPhotoList->prepare();
        }
    }

    void onRecievedPhotoListReady(VappGalleryPrepareResult prepareResult)
    {
        if(m_queryFinished)
        {
            return;
        }

        if(m_folderList)
        {
            m_folderList->prepare();
        }
    }

    void onFolderThumbnailDecodeResult(VappGalleryFolderThumbnailDecoder *decoder, VappGalleryDecodeResult res)
    {
        m_decodedThumbCount = m_decoderOutput->m_decodedThumbCount;
        VFX_OBJ_CLOSE(m_decoder);
        VFX_OBJ_CLOSE(m_decoderOutput);
        VFX_OBJ_CLOSE(m_photoList);
        VFX_OBJ_CLOSE(m_folderList);
        VFX_OBJ_CLOSE(m_receivedPhotoList);

        m_frontThumbBuffer->setValid(m_decodedThumbCount > 0);
        m_queryFinished = VFX_TRUE;
        m_thumbReadySignal.emit(0, DONE);
    }

protected:
    VfxBool m_queryFinished;
    VfxS32 m_photoCount;
    VfxS32 m_folderCount;
    VfxS32 m_receivedPhotoCount;

    VappGalleryFmgrImageList *m_photoList;          // used to count photo. release after use
    VappGalleryFmgrFolderList *m_folderList;        // used to count folder. release after use
    VappGalleryFmgrImageList *m_receivedPhotoList;   // used to count photo. release after use

    VappGalleryFolderThumbnailDecoder *m_decoder;
    VappGalleryCollectionDecoderOutput *m_decoderOutput;
    VfxS32 m_decodedThumbCount;
    VfxWString m_frontThumbPath;
    IVappGalleryMediaList::ListEvent m_signalPhotoListReady;
    IVappGalleryMediaList::ListEvent m_signalReceivedPhotoListReady;
};


class VappGalleryVideoCollection : public VappGalleryCollectionBase
{
protected:
    VfxU32 m_videoCount;
    VfxBool m_queryFinished;
    VfxWString m_frontThumbPath;
    VappGalleryFmgrList *m_videoList;
    VappGalleryVideoThumbnail *m_decoder;

public:
    VappGalleryVideoCollection():
        VappGalleryCollectionBase(),
        m_videoCount(0),
        m_queryFinished(VFX_FALSE),
        m_videoList(NULL),
        m_decoder(NULL)
    {
    }

// override
protected:
    virtual void createFmgrList(IVappGalleryMediaList::ListEvent *listReadySignal, VappGalleryCollectionSetting *setting)
    {
        VFX_ASSERT(setting);
        VFX_OBJ_CREATE(m_videoList, VappGalleryFmgrList, this);
        const U8 defaultDrv = setting->getDefaultDrive();
        m_videoList->config(defaultDrv, listReadySignal);
        m_videoList->configFileTypeLimit(&setting->m_filter);
        VFX_OBJ_CLOSE(m_decoder);
    }

    virtual void destroyFmgrList()
    {
        VFX_OBJ_CLOSE(m_videoList);
        VFX_OBJ_CLOSE(m_decoder);
    }

    virtual void resetQueryState()
    {
        m_queryFinished = VFX_FALSE;

        VFX_OBJ_CLOSE(m_decoder);
        m_frontThumbPath.setEmpty();
        if(m_frontThumbBuffer)
        {
            m_frontThumbBuffer->setValid(VFX_FALSE);
        }
    }

    virtual void prepareDescFromList()
    {
        m_videoCount = m_videoList->getTotalFileCount();

        // collect thumbnail paths
        resetQueryState();

        if(m_videoCount > 0)
        {
            // HACK: just test video thumbnail decoder
            m_videoList->getPathName(VcpMenuPos(0, 0), m_frontThumbPath);
        }

        VFX_OBJ_CLOSE(m_videoList);
        m_videoList = NULL;

        do
        {
            if(m_videoCount == 0)
            {
                break;
            }

            // first check for DB entry
            if(m_pDB.isValid() && m_frontThumbBuffer)
            {
                ivd_db_video_result_info thumbQuery;
                thumbQuery.thumb_width = m_frontThumbBuffer->m_width;
                thumbQuery.thumb_height = m_frontThumbBuffer->m_height;
                thumbQuery.thumb_buf_len = m_frontThumbBuffer->m_bufLen;
                thumbQuery.thumb_buf_ptr = m_frontThumbBuffer->m_bufPtr;
                m_pDB->getItemInfoBlocking((WCHAR*)m_frontThumbPath.getBuf(),  &thumbQuery);
                if(MMI_IVD_OK == thumbQuery.result_code)
                {
                    m_frontThumbBuffer->setValid(VFX_TRUE);
                    break;
                }
            }

            // then decode the thumbnail
            VFX_OBJ_CLOSE(m_decoder);
            VFX_OBJ_CREATE(m_decoder, VappGalleryVideoThumbnail, this);
            lockThumb();
            VfxImageSrc src;
            m_frontThumbBuffer->fillImageSrc(src);
            VfxImageBuffer imgBuf = src.getImageBuffer();
            m_decoder->getReadySignal()->connect(this, &VappGalleryVideoCollection::onThumbDecoded);
            m_decoder->decode(m_frontThumbPath, imgBuf);
            // we have to wait for decode finish
            m_queryFinished = VFX_FALSE;
            return;

        }while(0);

        m_queryFinished = VFX_TRUE;
        // notify client that thumnails are ready (no thumb)
        m_thumbReadySignal.postEmit(0, DONE);
    }


protected:
    void onThumbDecoded(VappGalleryDecoderBase *sender, VappGalleryDecodeResult result)
    {
        VFX_ASSERT(m_decoder == sender);
        if(OK == result)
        {
            m_frontThumbBuffer->setValid(VFX_TRUE);
            // insert into DB
            if(m_pDB.isValid())
            {
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
#endif
            }
        }
        VFX_OBJ_CLOSE(m_decoder);
        m_queryFinished = VFX_TRUE;
        m_thumbReadySignal.emit(0, DONE);
    }

// implements IVappGalleryMediaCollection
public:
    virtual VfxBool startQuery()
    {
        if(m_queryFinished || NULL == m_videoList)
        {
            return VFX_FALSE;
        }

        if(m_videoList->isPrepared())
        {
            return VFX_FALSE;
        }

        VFX_OBJ_CLOSE(m_decoder);
        m_videoList->prepare();
        return VFX_TRUE;
    }

    virtual void stopQuery()
    {
        if(m_queryFinished)
        {
            return;
        }

        VFX_OBJ_CLOSE(m_decoder);

        if(m_videoList)
            m_videoList->stop();
        return;
    }

    virtual VfxBool isQueryFinished()
    {
        return m_queryFinished;
    }

    virtual QueryResult queryDescriptionCount(VfxU32 &count)
    {
        count = isQueryFinished() ? 1 : 0;
        return DONE;
    }

    virtual QueryResult queryDescription(VfxU32 index, VfxWString &description)
    {
        if(index != 0)
            return ERROR;

        if(!m_queryFinished)
        {
            description = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IDX_SCANNING);
            return DONE;
        }

        if(0 == m_videoCount)
        {
            description = VFX_WSTR_RES(STR_ID_VAPP_GALLERY_NO_VID);
        }
        else
        {
            description.format("%d ", m_videoCount);
            description += VFX_WSTR_RES(m_videoCount <= 1 ?
                                        STR_ID_VAPP_GALLERY_IDX_VIDEO_COUNT_SUFFIX_SINGLE :
                                        STR_ID_VAPP_GALLERY_IDX_VIDEO_COUNT_SUFFIX);
        }
        return DONE;
    }

    virtual QueryResult queryThumbnailCount(VfxU32 &count)
    {
        if(isQueryFinished() && m_frontThumbBuffer &&
           m_frontThumbBuffer->isValid())
        {
            count = 1;
        }
        else
        {
            count = 0;
        }
        return DONE;
    }

    virtual QueryResult lockThumbnail(VfxU32 index, VfxImageSrc &imgSrc)
    {
        // allow only 2 thumbnails to be queried.
        if(!m_pDB.isValid() || index >= 2)
        {
            return ERROR;
        }

        if(m_frontThumbBuffer->isValid() && m_frontThumbBuffer->fillImageSrc(imgSrc))
        {
            return DONE;
        }
        return ERROR;
    }

    virtual void unlockAllThumbnail(VfxU32 index, VfxImageSrc &imgSrc)
    {
        // thumbnail buffers are allocated in onInit().
        // they will be release in onDeinit().
        return;
    }
};


IVappGalleryMediaCollection *collectionFactory(PageName name, VfxObject *parent, VfxApp *app)
{
    switch(name)
    {
    case PN_MY_SHOOTING:
        {
            VappGalleryShootingCollection *ret = NULL;
            VFX_OBJ_CREATE(ret, VappGalleryShootingCollection, parent);
            VcuiGalleryImagePicker *imagePicker = VFX_OBJ_DYNAMIC_CAST(app, VcuiGalleryImagePicker);
            VcuiGalleryVideoPicker *videoPicker = VFX_OBJ_DYNAMIC_CAST(app, VcuiGalleryVideoPicker);
            if(imagePicker)
            {
                ret->showPhotoDescriptionOnly(VFX_TRUE);
            }
            else if(videoPicker)
            {
                ret->showVideoDescriptionOnly(VFX_TRUE);
            }
            return ret;
        }
    case PN_MY_PICTURE:
        {
            VappGalleryPictureCollection *ret = NULL;
            VFX_OBJ_CREATE(ret, VappGalleryPictureCollection, parent);
            return ret;
        }
    case PN_MY_VIDEO:
        {
            VappGalleryVideoCollection *ret = NULL;
            VFX_OBJ_CREATE(ret, VappGalleryVideoCollection, parent);
            return ret;
        }
    }
    return NULL;
}

class VappGalleryIndexItemCell : public VcpListMenuCellClientBaseFrame
{
private:
    static const VfxS32 MAX_DESC_COUNT = 2; // at most 2 rows of descriptions
    VfxTextFrame *m_caption;                // Main item label
    VappGalleryIndexCollage *m_icon;        // the default icon and thumbnail collage
    VappGalleryIndexMenuItem *m_itemInfo;   // store static item information
    IVappGalleryMediaCollection *m_collectionInfo; // stores collection info (e.g. picture count)
    VfxTextFrame *m_desc[MAX_DESC_COUNT];   // text descriptions

public:
    VappGalleryIndexItemCell():
      m_caption(NULL),
      m_icon(NULL),
      m_itemInfo(NULL),
      m_collectionInfo(NULL)
    {
        for(int i = 0; i < sizeof(m_desc) / sizeof(m_desc[0]); ++i)
        {
            m_desc[i] = NULL;
        }
    }

    VfxU32 getDescriptionCount() const
    {
        return MAX_DESC_COUNT;
    }

    void setItemInfo(VappGalleryIndexMenuItem *itemInfo)
    {
        m_itemInfo = itemInfo;
    }

    VappGalleryIndexMenuItem* getItemInfo()
    {
        return m_itemInfo;
    }

    void setCollectionInfo(IVappGalleryMediaCollection *collectionInfo)
    {
        m_collectionInfo = collectionInfo;
    }

    IVappGalleryMediaCollection* getCollectionIfno()
    {
        return m_collectionInfo;
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

        for(VfxU32 i = 0; i < getDescriptionCount(); ++i)
        {
            VFX_OBJ_CREATE(m_desc[i], VfxTextFrame, this);
            m_desc[i]->setAutoFontSize(VFX_FALSE);
            m_desc[i]->setAutoResized(VFX_FALSE);
            m_desc[i]->setAutoAnimate(VFX_TRUE);
            m_desc[i]->setOpacity(0.0f);
            m_desc[i]->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(IndexPageLayout::FONT_SIZE_DESC)));
            m_desc[i]->setColor(VfxColor(IndexPageLayout::TEXT_DESC_COLOR));
            m_desc[i]->setSize(IndexPageLayout::TEXT_W, IndexPageLayout::TEXT_DESC_H);
            m_desc[i]->setHidden(VFX_TRUE);
        }

        VFX_OBJ_CREATE(m_icon, VappGalleryIndexCollage, this);
        m_icon->setPos(IndexPageLayout::ICON_MARGIN_L, IndexPageLayout::ICON_MARGIN_T);
        m_icon->setSize(IndexPageLayout::ICON_W, IndexPageLayout::ICON_H);
    }

    // release children frame
    virtual void onCloseElements()
    {
        if(m_caption)
        {
            VFX_OBJ_CLOSE(m_caption);
            m_caption = NULL;
        }

        if(m_icon)
        {
            VFX_OBJ_CLOSE(m_caption);
            m_caption = NULL;
        }


        for(VfxU32 i = 0; i < getDescriptionCount(); ++i)
        {
            if(m_desc[i])
            {
                VFX_OBJ_CLOSE(m_desc[i]);
            }
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

        if(NULL != m_itemInfo->badgeImgID)
        {
            m_icon->setBadge(m_itemInfo->badgeImgID);
        }

        VfxBool collageShown = VFX_FALSE;

        if(NULL == m_collectionInfo)
        {
            // put descpiption to animation start position.
            for(VfxU32 i = 0 ; i < getDescriptionCount(); ++i)
            {
                m_desc[i]->setPos(IndexPageLayout::TEXT_MARGIN_L , textPos);
            }
        }
        else
        {
            if(updateThumbnails())
            {
                collageShown = VFX_TRUE;
            }
            updateDescription();
        }

        // only set default icon when collage is not show,
        // since this resets animation.
        if(!collageShown)
        {
            m_icon->setAndDisplayDefaultIcon(m_itemInfo->defaultImgID);
        }
    }

    // returns VFX_TRUE if collection thumbnails are succesfully retrieved and set
    VfxBool updateThumbnails()
    {
        if(NULL == m_collectionInfo)
        {
            return VFX_FALSE;
        }

        VfxU32 thumbCount = 0;
        m_collectionInfo->queryThumbnailCount(thumbCount);
        if(thumbCount > 0)
        {
            VfxImageSrc frontSrc;
            VfxImageSrc backSrc;

            backSrc.setNull();
            // grab either the front or back thumbnail
            if(IVappGalleryMediaCollection::DONE != m_collectionInfo->lockThumbnail(0, frontSrc))
            {
                frontSrc.setNull();
            }
            if(IVappGalleryMediaCollection::DONE != m_collectionInfo->lockThumbnail(1, backSrc))
            {
                backSrc.setNull();
            }

            if(!frontSrc.isNull() || !backSrc.isNull())
            {
                // use only 1 thumbnail if only 1 available.
                if(frontSrc.isNull())
                {
                    frontSrc = backSrc;
                }
                else if(backSrc.isNull())
                {
                    backSrc = frontSrc;
                }
                m_icon->setAndDisplayCollageSources(frontSrc, backSrc);
                return VFX_TRUE;
            }
        }
        // no collection thumbnail queried
        return VFX_FALSE;
    }

    void updateDescription()
    {
        if(NULL == m_collectionInfo)
        {
            MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ITEM_CELL_UPDATE_DESCRIPTION, 0);
            return;
        }

        VFX_DEV_ASSERT(m_collectionInfo);
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ITEM_CELL_UPDATE_DESCRIPTION, 1);
        VfxU32 visibleDescCount = 0;
        m_collectionInfo->queryDescriptionCount(visibleDescCount);

        // we update textPos after adding each description item
        VfxS32 textPos = (IndexPageLayout::MENU_H - getTotalTextHeight()) / 2;

        // skip the caption text height & padding
        const VfxS32 linePadding = (visibleDescCount <= 1) ? IndexPageLayout::PAD_TWO_LINE : IndexPageLayout::PAD_THREE_LINE;
        textPos += IndexPageLayout::TEXT_CAPTION_H + linePadding;

        VfxWString descStr;
        for(VfxU32 i = 0 ; i < MAX_DESC_COUNT; ++i)
        {
            VfxTextFrame *desc = m_desc[i];

            // invisible case, simply hide the string
            if(i >= visibleDescCount)
            {
                m_desc[i]->setHidden(VFX_TRUE);
                continue;
            }

            m_collectionInfo->queryDescription(i, descStr);
            desc->setString(descStr);

            // hidden -> visible
            // displays fade-in animation
            if(desc->getHidden())
            {
                // start from visible but opacity 0
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDisable(VFX_TRUE);
                desc->setHidden(VFX_FALSE);
                desc->setOpacity(0);
                desc->setPos(IndexPageLayout::TEXT_MARGIN_L , textPos + IndexPageLayout::DESC_FADEIN_OFFSET);
                VfxAutoAnimate::commit();

                // fade-in
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDisable(VFX_FALSE);
                VfxAutoAnimate::setDuration(ANIM_SLOW_TIMING);
                desc->setOpacity(1.0f);
                desc->setPos(IndexPageLayout::TEXT_MARGIN_L , textPos);
                VfxAutoAnimate::commit();
            }

            textPos += (linePadding + IndexPageLayout::TEXT_DESC_H);
        }
    }

    VfxS32 getTotalTextHeight()
    {
        VFX_DEV_ASSERT(m_caption && m_icon && m_itemInfo);

        if(NULL == m_collectionInfo)
        {
            return m_caption->getSize().height;
        }
        else
        {
            VfxU32 count = 0;
            m_collectionInfo->queryDescriptionCount(count);

            const VfxS32 captionH = IndexPageLayout::TEXT_CAPTION_H;
            const VfxS32 descH = IndexPageLayout::TEXT_DESC_H;
            const VfxS32 linePadding = (count <= 1) ? IndexPageLayout::PAD_TWO_LINE : IndexPageLayout::PAD_THREE_LINE;
            return captionH + count * (descH + linePadding);
        }
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

        const VfxColor descColor = pCell->getTextColor(VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT);
        for(VfxS32 i = 0; i < MAX_DESC_COUNT; ++i)
        {
            if(m_desc[i])
            {
                m_desc[i]->setColor(descColor);
            }
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
    m_galleryDB(NULL),
	m_lastPlayPanel(NULL),
    m_indexMenu(NULL),
    m_updater(NULL), 
    m_querying(VFX_FALSE),  
    m_shouldRefreshOnEnter(VFX_FALSE),
    m_delayEnteredTimer(NULL)
{
    memset(&m_lastPlayVideoInfo, 0, sizeof(m_lastPlayVideoInfo));
    for(int i = 0; i < INDEX_MENU_ITEM_COUNT; ++i)
    {
        m_collections[i] = NULL;
    }

    m_itemIndices[0] = 0;   // My Shooting
    m_itemIndices[1] = 1;   // My Picture
    m_itemIndices[2] = 2;   // My Video
}

void VappGalleryIndexPage::onInit()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ON_INIT);
    VappGalleryPage::onInit();

    // set bg color to avoid abnormal bg color caused by page transition from page with different bg color
    setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));

    // initialize gallery database later, when enter page
    m_galleryDB = NULL;
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
    freeLastPlayInfoBuffer();
    VappGalleryPage::onDeinit();
}

void VappGalleryIndexPage::createLastPlayPanel()
{
#ifdef __VAPP_GALLERY_ENABLE_LAST_PLAY_INFO__
    // Last play panel sticks to top of toolbar
    VFX_OBJ_CREATE(m_lastPlayPanel, VappGalleryLastPlayFrame, this);
    m_lastPlayPanel->setPos(0, getSize().height - m_lastPlayPanel->getSize().height);
    m_lastPlayPanel->setAlignParent(
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_NONE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE);
    m_lastPlayPanel->setOpacity(0.0f);
    m_lastPlayPanel->setAutoAnimate(VFX_TRUE);
    m_lastPlayPanel->m_signalClicked.connect(this, &VappGalleryIndexPage::onLastPlayTapped);
#endif
}

void VappGalleryIndexPage::allocLastPlayInfoBuffer()
{
#ifdef __VAPP_GALLERY_ENABLE_LAST_PLAY_INFO__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ALLOC_LAST_PLAY_INFO_BUFFER);
    VFX_ASSERT(NULL == m_lastPlayVideoInfo.thumb_buf_ptr);
    // initialize video info data members
    m_lastPlayVideoInfo.thumb_width = VappGalleryVideoInfoCacheItem::VIDEO_THUMB_W;
    m_lastPlayVideoInfo.thumb_height = VappGalleryVideoInfoCacheItem::VIDEO_THUMB_H;
    m_lastPlayVideoInfo.thumb_buf_len = VappGalleryVideoInfoCacheItem::VIDEO_THUMB_W *
                                        VappGalleryVideoInfoCacheItem::VIDEO_THUMB_H * VAPP_GALLERY_THUMB_BPP;
    m_lastPlayVideoInfo.thumb_buf_ptr = (U8*)applib_asm_alloc_nc_r(getApp()->getGroupId(), m_lastPlayVideoInfo.thumb_buf_len);
    VFX_ASSERT(NULL != m_lastPlayVideoInfo.thumb_buf_ptr);
#endif
}

void VappGalleryIndexPage::freeLastPlayInfoBuffer()
{
#ifdef __VAPP_GALLERY_ENABLE_LAST_PLAY_INFO__
    if(NULL == m_lastPlayVideoInfo.thumb_buf_ptr)
    {
        return;
    }
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_FREE_LAST_PLAY_INFO_BUFFER);
    applib_asm_free_r(getApp()->getGroupId(), m_lastPlayVideoInfo.thumb_buf_ptr);
    m_lastPlayVideoInfo.thumb_buf_ptr = NULL;
    m_lastPlayVideoInfo.thumb_buf_len = 0;
    m_lastPlayVideoInfo.thumb_width = 0;
    m_lastPlayVideoInfo.thumb_height = 0;
#endif
}

void VappGalleryIndexPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ON_EXIT);
    VappGalleryPage::onExit(isBackward);

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    VfxMainScr *pMainScr = getMainScr();
    if(pMainScr && pMainScr->getIsSnapshotDrawing())
    {
        return;
    }

    if(m_delayEnteredTimer)
    {
        m_delayEnteredTimer->m_signalTick.disconnect(this, &VappGalleryIndexPage::onDelayEntered);
        m_delayEnteredTimer->stop();
        VFX_OBJ_CLOSE(m_delayEnteredTimer);
        m_delayEnteredTimer = NULL;
    }

    // register device plug-in to refresh toolbar
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappGalleryIndexPage::onDevicePlugInOut, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappGalleryIndexPage::onDevicePlugInOut, this);

    if(m_updater)
    {
        m_updater->forceStopCheck();
        VFX_OBJ_CLOSE(m_updater);
    }

    // stops all querying operations,
    // since new page may also access FMgr lists
    for(int i = 0; i < INDEX_MENU_ITEM_COUNT; ++i)
    {
        if(m_collections[i] && !m_collections[i]->isQueryFinished())
        {
            m_collections[i]->releaseLists();
        }
    }

    // must close DB since IVD allows only single instance
    VFX_OBJ_CLOSE(m_galleryDB);
}

void VappGalleryIndexPage::onExited2()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ON_EXITED2);

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    VfxMainScr *pMainScr = getMainScr();
    if(pMainScr && pMainScr->getIsSnapshotDrawing())
    {
        return;
    }

    VFX_OBJ_GET_INSTANCE(VfxRenderer)->suspendUntilCommit();
    for(int i = 0; i < INDEX_MENU_ITEM_COUNT; ++i)
    {
        if(m_collections[i])
        {
            m_collections[i]->destroy();
            m_collections[i] = NULL;
        }
    }

#ifdef __VAPP_GALLERY_ENABLE_LAST_PLAY_INFO__
    if(m_lastPlayPanel)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_lastPlayPanel->setOpacity(0.0f);
        VfxAutoAnimate::commit();
    }
#endif

    freeLastPlayInfoBuffer();
    VFX_OBJ_CLOSE(m_lastPlayPanel);
    VFX_OBJ_CLOSE(m_indexMenu);

    return VappGalleryPage::onExited2();
}

void VappGalleryIndexPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ON_ENTER);
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
    // initialize resource for last play
    allocLastPlayInfoBuffer();

    // CUI may assign custom file filter
    // check if there is CUI-assigned custom file filter
    // then initialize collections,
    // since image picker and video picker have different collection set
    VcuiGalleryPickerBase *cui = getParentPickerCUI();
    const VfxS32 count = cui ? INDEX_MENU_ITEM_COUNT_CUI : INDEX_MENU_ITEM_COUNT;

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

    for(VfxS32 i = 0; i < count; ++i)
    {
        if(-1 == m_itemIndices[i])
        {
            continue;
        }

        VappGalleryIndexMenuItem *item = getItemInfoFromIndex(m_itemIndices[i]);
        if(NULL == item)
        {
            continue;
        }
        IVappGalleryMediaCollection *collection = NULL;
        collection = item->itemFactory(item->pageName, this, getApp());
        if(NULL == collection)
        {
            continue;
        }

        // prepare collection and connect signals
        collection->getDescriptionUpdateSignal()->connect(this, &VappGalleryIndexPage::onDescriptionUpdate);
        collection->getThumbnailUpdateSignal()->connect(this, &VappGalleryIndexPage::onCollectionUpdate);
        m_collections[i] = collection;
    }
#endif

    VappGalleryStorageSetting storageSetting;
    handleStorageChangeLite(storageSetting);
}

void VappGalleryIndexPage::onEntered()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ON_ENTERED);
    VappGalleryPage::onEntered();

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    VfxMainScr *pMainScr = getMainScr();
    if(pMainScr && pMainScr->getIsSnapshotDrawing())
    {
        return;
    }

    if(NULL == m_delayEnteredTimer)
    {
        VFX_OBJ_CREATE(m_delayEnteredTimer, VfxTimer, this);
        m_delayEnteredTimer->setStartDelay(10);
        m_delayEnteredTimer->setDuration(0);
    }
    m_delayEnteredTimer->m_signalTick.connect(this, &VappGalleryIndexPage::onDelayEntered);
    m_delayEnteredTimer->start();
}

void VappGalleryIndexPage::onDelayEntered(VfxTimer *timer)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_ON_DELAY_ENTERED);
    timer->stop();
    timer->m_signalTick.disconnect(this, &VappGalleryIndexPage::onDelayEntered);

    if(NULL == m_updater)
    {
        // create updater logic
        VFX_OBJ_CREATE(m_updater, VappGalleryMenuUpdater, this);
        m_updater->setMenu(m_indexMenu, this);
    }

    // special case: handling destroying case
    VcuiGalleryBase *cuiBase = VFX_OBJ_DYNAMIC_CAST(getApp(), VcuiGalleryBase);
    if(cuiBase && cuiBase->isDestroying())
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_CALLED_DURING_CUI_DESTORYING);
        return;
    }

    // in Snapshot mode, we're not in FG, cannot allocate resources!
    if(getMainScr() && getMainScr()->getIsSnapshotDrawing())
    {
        return;
    }

    // last play panel is NOT created
    // under Image Picker CUI and QVGA
    VfxBool isQVGA = VFX_FALSE;
#ifdef __MMI_MAINLCD_240X320__
    isQVGA = VFX_TRUE;
#endif
    if(NULL == m_lastPlayPanel &&
       NULL == getParentPickerCUI() &&
       !isQVGA)
    {
        createLastPlayPanel();
    }

    // make sure tab bar UI is up-to-date
    createStorageSelectionTab(VFX_FALSE);

    // then update storage-related UI elements
    if(NULL == m_galleryDB || m_shouldRefreshOnEnter)
    {
        VappGalleryStorageSetting storageSetting;
        handleStorageChange(storageSetting);
    }

    // register device plug-in to refresh tab bar
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappGalleryIndexPage::onDevicePlugInOut, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappGalleryIndexPage::onDevicePlugInOut, this);
}

void VappGalleryIndexPage::onUpdate()
{
    VappGalleryPage::onUpdate();
    if(m_updater)
    {
        // kick off menu refresh
        m_updater->forceStartCheck();
    }
}

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

void VappGalleryIndexPage::refreshStorage(VfxBool directRefresh)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_REFRESH_STORAGE, directRefresh);

    if(!directRefresh)
    {
        // simply set dirty flag, to refresh the entry in onEnter
        m_shouldRefreshOnEnter = VFX_TRUE;
    }
    else
    {
        // refresh UI
        createStorageSelectionTab(VFX_FALSE);
        VappGalleryStorageSetting setting;
        handleStorageChange(setting);
    }
}

VfxBool VappGalleryIndexPage::handleStorageChangeLite(VappGalleryStorageSetting &storageSetting)
{
    // stops all querying operations to avoid fata error caused by
    // querying DB while it already be destoryed
    for(int i = 0; i < INDEX_MENU_ITEM_COUNT; ++i)
    {
        if(m_collections[i] && !m_collections[i]->isQueryFinished())
        {
            m_collections[i]->releaseLists();
        }
    }

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

#ifdef __VAPP_GALLERY_ENABLE_LAST_PLAY_INFO__
        // make sure the last panel is updated
        if(m_lastPlayPanel)
        {
            // since the drive is not accessible, we should
            // force clear the video info.
            m_lastPlayVideoInfo.result_code = MMI_IVD_ERR_EMPTY;
            m_lastPlayPanel->setInfo(m_lastPlayVideoInfo);
            m_lastPlayPanel->invalidate();
        }
#endif
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
    // handles any device change.
    // note: if a memory card is removed, we still keep the "default storage".
    // only update UI to display "No memory card".

    // stops all querying operations to avoid fata error caused by
    // querying DB while it already be destoryed
    for(int i = 0; i < INDEX_MENU_ITEM_COUNT; ++i)
    {
        if(m_collections[i] && !m_collections[i]->isQueryFinished())
        {
            m_collections[i]->releaseLists();
        }
    }

    VFX_OBJ_CLOSE(m_galleryDB);
    m_shouldRefreshOnEnter = VFX_FALSE;

    if(!handleStorageChangeLite(storageSetting))
    {
        return;
    }

    // create gallery DB according to new storage setting
    VFX_OBJ_CREATE_EX(m_galleryDB, VappGalleryDB, this, (storageSetting));

    // check if there is CUI-assigned custom file filter
    VappGalleryCollectionSetting setting;
    setting.m_pDB = m_galleryDB;
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
    for(int i = 0; i < INDEX_MENU_ITEM_COUNT; ++i)
    {
        if(m_collections[i])
        {
            m_collections[i]->reset(setting);
        }
    }

    // since we reset collections, their enhance is now stopped.
    m_querying = VFX_FALSE;

    // refresh menu items
    showPageMessage(VFX_FALSE);
    m_indexMenu->setHidden(VFX_FALSE);
    m_indexMenu->updateAllItems();

#ifdef __VAPP_GALLERY_ENABLE_LAST_PLAY_INFO__
    // update last play info
    if(m_galleryDB && m_lastPlayPanel)
    {
        m_galleryDB->getRecentPlayVideoBlocking(&m_lastPlayVideoInfo);
        m_lastPlayPanel->setInfo(m_lastPlayVideoInfo);
        m_lastPlayPanel->invalidate();
    }
#endif

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
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_HANDLE_DEVICE_PLUG_IN_OUT);

    // update storage selection tab
    // note that we don't update storage,
    // it is handled by VappGalleryApp or VcuiGalleryBase
    createStorageSelectionTab(VFX_FALSE);

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

void VappGalleryIndexPage::onToolbarCommand(VfxObject *sender, VfxId btnId)
{
    switch(btnId)
    {
    case 'REFR':
        // Does not support refresh in W11.12MP
        break;
    case 'SETT':
        onGotoPage(PN_SETTING);
        break;
    default:
        VFX_DEV_ASSERT(VFX_FALSE);
        break;
    }
}

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

        if(m_shouldRefreshOnEnter)
        {
            VFX_OBJ_CLOSE(m_galleryDB);
        }

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
            VappGalleryVideoPage *videoPage = NULL;
            VFX_OBJ_CREATE(videoPage, VappGalleryVideoPage, getMainScr());
            nextPage = videoPage;
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

VappGalleryIndexMenuItem* VappGalleryIndexPage::getItemInfoFromIndex(VfxS32 index)
{
    if(index < 0 || index >= INDEX_MENU_ITEM_COUNT)
    {
        return NULL;
    }
    return &g_indexMenuItems[index];
}

void VappGalleryIndexPage::onDescriptionUpdate(VfxU32 descIndex, IVappGalleryMediaCollection::QueryResult result)
{
    if(m_indexMenu)
    {
        m_indexMenu->updateAllItems();
    }
}

void VappGalleryIndexPage::onCollectionUpdate(VfxU32 descIndex, IVappGalleryMediaCollection::QueryResult result)
{
    m_querying = VFX_FALSE;
    if(m_indexMenu)
    {
        m_indexMenu->updateAllItems();
    }
    if(m_updater)
    {
        m_updater->forceStartCheck();
    }
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
    if(info->itemFactory && m_collections[index])
    {
        pCellFrame->setCollectionInfo(m_collections[index]);
    }
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

VfxRect VappGalleryIndexPage::getViewRect()
{
    if(NULL == m_indexMenu)
        return VfxRect();

    return m_indexMenu->getRect();
}

VfxBool VappGalleryIndexPage::needUpdate(const VcpMenuPos &pos, VfxFrame *frame)
{
    if(pos.group > 0 || pos.pos >= INDEX_MENU_ITEM_COUNT || NULL == m_collections[pos.pos])
        return VFX_FALSE;

    return !m_collections[pos.pos]->isQueryFinished();
}

VfxBool VappGalleryIndexPage::updateMenuCell(
                    const VcpMenuPos &pos,
                    const VfxFrame *frame,
                    VfxBool canEnhance)
{
    if(pos.group > 0 || pos.pos >= INDEX_MENU_ITEM_COUNT || NULL == m_collections[pos.pos])
        return VFX_FALSE;

    VappGalleryIndexItemCell *pCell = (VappGalleryIndexItemCell*)m_indexMenu->getContentFrame(pos.pos);
    pCell->updateDescription();
    pCell->updateThumbnails();

    // still querying, cannot enhance another item
    if(m_querying && canEnhance)
    {
        return VFX_FALSE;
    }

    if(canEnhance)
    {
        m_collections[pos.pos]->startQuery();
        m_querying = VFX_TRUE;
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappGalleryIndexPage::onLastPlayTapped(VfxObject *lastPlay, VfxId btnId)
{
    VappGalleryPlayerPage *playerPage = NULL;
    VFX_OBJ_CREATE(playerPage, VappGalleryPlayerPage, getMainScr());
    playerPage->configStoreLastPlay(VFX_TRUE);

    // check if there is a bookmark;
    // start from bookmark to play if there is one.
    playerPage->setLocalFile(m_lastPlayVideoInfo.file_name, m_lastPlayVideoInfo.bookmark_sec * 1000);

    // show player page
    getMainScr()->pushPage(0, playerPage);
}

/////////////////////////////////////////////////////////////////
//  Implementation of VappGalleryLastPlayFrame
/////////////////////////////////////////////////////////////////
#ifdef __VAPP_GALLERY_ENABLE_LAST_PLAY_INFO__
VappGalleryLastPlayFrame::VappGalleryLastPlayFrame():
    m_thumbnail(NULL),
    m_caption(NULL),
    m_filename(NULL),
    m_duration(NULL),
    m_bookmark(NULL)
{
}

void VappGalleryLastPlayFrame::onInit()
{
    VcpImageButton::onInit();

    // different area have different font sizes.
    // currently we cannot set font size to text frame.
    VfxXmlLoader::loadBegin(this, VAPP_GALLERY_LAYOUT_LAST_PLAY);

    // caption of panel
    m_caption = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("caption")),
                                                 VfxTextFrame);
    VFX_ASSERT(m_caption);
    m_caption->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(IndexPageLayout::FONT_SIZE_LAST_PLAY_CAPTION), VFX_FONT_DESC_ATTR_BOLD));
    m_caption->setString(VFX_WSTR_RES(STR_ID_VAPP_GALLERY_IDX_LAST_PLAY));
    m_caption->setAutoResized(VFX_TRUE);

    // thumbnail
    m_thumbnail = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("thumbnail")),
                                                 VfxFrame);
    VFX_ASSERT(m_thumbnail);
    m_thumbnail->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_thumbnail->setBgColor(VFX_COLOR_TRANSPARENT);

    // pause icon, used to align last play bookmark
    VfxFrame *pauseIcon = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("pauseIcon")),
                                               VfxFrame);
    VFX_ASSERT(pauseIcon);

    // filename
    m_filename = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("filename")),
                                                 VfxTextFrame);
    VFX_ASSERT(m_filename);
    m_filename->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(IndexPageLayout::FONT_SIZE_LAST_PLAY_FILENAME), VFX_FONT_DESC_ATTR_BOLD));
    m_filename->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    const VfxS32 filenameRightMargin = IndexPageLayout::ICON_MARGIN_L + pauseIcon->getSize().width;
#else
    const VfxS32 filenameRightMargin = 0;
#endif
    m_filename->setSize(getSize().width - m_filename->getPos().x - filenameRightMargin, IndexPageLayout::FONT_SIZE_LAST_PLAY_FILENAME);

    // duration text
    m_duration = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("duration")),
                                                 VfxTextFrame);
    VFX_ASSERT(m_duration);
    m_duration->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(IndexPageLayout::FONT_SIZE_LAST_PLAY_TIME),
                                    VFX_FONT_DESC_ATTR_MONOSPACE));

    // last play bookmark
    m_bookmark = VFX_OBJ_DYNAMIC_CAST(VfxXmlLoader::findObjByName(VFX_WSTR("position")),
                                                 VfxTextFrame);
    VFX_ASSERT(m_bookmark);
    m_bookmark->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
    m_bookmark->setAutoResized(VFX_FALSE);
    // make sure bookmark text align to right side of pause icon
    m_bookmark->setSize(pauseIcon->getPos().x - m_bookmark->getPos().x - IndexPageLayout::ICON_MARGIN_L, IndexPageLayout::FONT_SIZE_LAST_PLAY_TIME);
    m_bookmark->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(IndexPageLayout::FONT_SIZE_LAST_PLAY_TIME),
                                    VFX_FONT_DESC_ATTR_MONOSPACE));
    VfxXmlLoader::loadEnd();

    // set background
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_IDX_BG_LAST_PLAY));

}

void VappGalleryLastPlayFrame::setInfo(const ivd_db_video_result_last_play_info &videoInfo)
{
    const VfxBool isFileExist = VappGalleryFileUtil::isFileExist((const VfxWChar*)videoInfo.file_name);
    if(MMI_IVD_OK != videoInfo.result_code ||
       !isFileExist)
    {
        MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_GALLERY_INDEX_NO_LAST_PLAY_VIDEO_DB_D_FS_D, videoInfo.result_code, isFileExist);
        setOpacity(0.0f);
        setIsDisabled(VFX_TRUE);
        return;
    }

    setIsDisabled(VFX_FALSE);
    setOpacity(1.0f);

    // get real file name,
    // we re-get the actual filename, since
    // DB always use lower case for path
    VfxWString fileNameString;
    fileNameString.setEmpty();
    SRV_FMGR_FILEINFO_HANDLE hInfo = NULL;
    do
    {
        if(0 != srv_fmgr_fileinfo_create(videoInfo.file_name, &hInfo))
        {
            break;
        }

        const S32 reqLenInChar = 1 + srv_fmgr_fileinfo_get_name(hInfo, NULL, 0);
        WCHAR* pBuf = fileNameString.lockBuf(reqLenInChar);
        if(NULL == pBuf)
        {
            break;
        }
        srv_fmgr_fileinfo_get_name(hInfo, pBuf, reqLenInChar * sizeof(WCHAR));
        fileNameString.unlockBuf();
    }while(0);

    if(hInfo)
    {
        srv_fmgr_fileinfo_destroy(hInfo);
        hInfo = NULL;
    }

    m_filename->setString(fileNameString);

    // duration formatting
    VfxWString text;
    formatTimeText(text, videoInfo.duration_sec * 1000);
    m_duration->setString(text);
    formatTimeText(text, videoInfo.bookmark_sec * 1000);
    m_bookmark->setString(text);

    // video thumbnail
    VfxImageSrc thumbSrc;
    VfxImageBuffer thumbBuf;
    thumbBuf.width = videoInfo.thumb_width;
    thumbBuf.height = videoInfo.thumb_height;
    thumbBuf.pitchBytes = videoInfo.thumb_width * VAPP_GALLERY_THUMB_BPP;
    thumbBuf.colorFormat = GALLERY_VRT_CF_THUMB;
    thumbBuf.ptr = videoInfo.thumb_buf_ptr;
    thumbSrc.setImageBuffer(thumbBuf);
    m_thumbnail->setImgContent(thumbSrc);
    m_thumbnail->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
    m_thumbnail->invalidate();
    return;
}
#endif

/////////////////////////////////////////////////////////////////
//  Implementation of VappGalleryIndexCollage
/////////////////////////////////////////////////////////////////
VappGalleryIndexCollage::VappGalleryIndexCollage():
    m_thumbGroup(NULL),
    m_frontThumb(NULL),
    m_backThumb(NULL),
    m_frontBorder(NULL),
    m_backBorder(NULL),
    m_imgBadge(NULL),   
    m_isDisplayCollage(VFX_FALSE)
{
}

void VappGalleryIndexCollage::onInit()
{
    VfxFrame::onInit();

    setSize(IndexPageLayout::ICON_W, IndexPageLayout::ICON_H);

    // create child frame that groups thumbnails and borders
    VFX_OBJ_CREATE(m_thumbGroup, VfxFrame, this);
    m_thumbGroup->setSize(getSize());
    m_thumbGroup->setOpacity(0.0f);
    m_thumbGroup->setAutoAnimate(VFX_TRUE);

    // put all thumb (non-default icon) related images under m_thumbGroup
    // from back to front: (back thumb -> back border) -> front thumb -> front border -> badge

    // back thumb
    VFX_OBJ_CREATE(m_backThumb, VfxFrame, m_thumbGroup);
    m_backThumb->setAnchor(0.5, 0.5);
    m_backThumb->setSize(IndexPageLayout::BACK_THUMB_W, IndexPageLayout::BACK_THUMB_H);
    m_backThumb->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    m_backThumb->setPos(IndexPageLayout::BACK_THUMB_CX,
                        IndexPageLayout::BACK_THUMB_CY);
    // currently, IMG_ID_VAPP_GALLERY_IDX_THUMB_FRAME_ROTATED is not transparent,
    // so we hide back thumbnail.
    // If IMG_ID_VAPP_GALLERY_IDX_THUMB_FRAME_ROTATED is a transparent border,
    // we should show this back thumbnail.
    m_backThumb->setHidden(VFX_TRUE);

    // rotate the back thumb
    VfxTransform backThumbRotation = m_backThumb->getTransform();
    backThumbRotation.type = VRT_TRANSFORM_TYPE_AFFINE;
    backThumbRotation.data.affine.rz = VFX_DEG_TO_RAD(IndexPageLayout::BACK_THUMB_ANGLE);
    m_backThumb->setTransform(backThumbRotation);

    // back border
    VFX_OBJ_CREATE(m_backBorder, VfxImageFrame, m_thumbGroup);
    m_backBorder->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_IDX_THUMB_FRAME_ROTATED));
    m_backBorder->setPos(0, 0);

    // front thumb
    VFX_OBJ_CREATE(m_frontThumb, VfxFrame, m_thumbGroup);
    m_frontThumb->setSize(IndexPageLayout::FRONT_THUMB_W, IndexPageLayout::FRONT_THUMB_H);
    m_frontThumb->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    m_frontThumb->setPos(IndexPageLayout::FRONT_THUMB_CX,
                         IndexPageLayout::FRONT_THUMB_CY);

    // front border
    VFX_OBJ_CREATE(m_frontBorder, VfxImageFrame, m_thumbGroup);
    m_frontBorder->setImgContent(VfxImageSrc(IMG_ID_VAPP_GALLERY_IDX_THUMB_FRAME));
    m_frontBorder->setPos((IndexPageLayout::ICON_W - IndexPageLayout::FRONT_BORDER_W) / 2
                         ,(IndexPageLayout::ICON_H - IndexPageLayout::FRONT_BORDER_H) / 2);

    // badge (small icon on the thumbnail)
    VFX_OBJ_CREATE(m_imgBadge, VfxImageFrame, m_thumbGroup);
    m_imgBadge->setHidden(VFX_TRUE);

    // begin with collage frames hidden
    m_isDisplayCollage = VFX_FALSE;
}

void VappGalleryIndexCollage::setBadge(VfxId badgeIconID)
{
    m_imgBadge->setImgContent(VfxImageSrc(badgeIconID));
    m_imgBadge->setHidden(VFX_FALSE);
    const VfxSize groupSize = m_thumbGroup->getSize();
    const VfxSize badgeSize = m_imgBadge->getSize();
    m_imgBadge->setPos(groupSize.width - badgeSize.width - IndexPageLayout::BADGE_MARGIN_R,
                       groupSize.height - badgeSize.height - IndexPageLayout::BADGE_MARGIN_D);
}

void VappGalleryIndexCollage::setAndDisplayCollageSources(const VfxImageSrc &front, const VfxImageSrc &back)
{
    if(m_isDisplayCollage)
    {
        m_frontThumb->setImgContent(front);
        m_backThumb->setImgContent(back);
        m_frontThumb->invalidate();
        m_backThumb->invalidate();
        return;
    }

    m_isDisplayCollage = VFX_TRUE;

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_frontThumb->setImgContent(front);
        m_backThumb->setImgContent(back);
        m_frontThumb->invalidate();
        m_backThumb->invalidate();
        m_thumbGroup->setHidden(VFX_FALSE);
        m_thumbGroup->setOpacity(0.0f);
    }
    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    {
        VfxAutoAnimate::setDuration(ANIM_SLOW_TIMING);
        VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE);
        VfxAutoAnimate::setDisable(VFX_FALSE);
        m_thumbGroup->setOpacity(1.0f);
    }
    VfxAutoAnimate::commit();
}

void VappGalleryIndexCollage::setAndDisplayDefaultIcon(VfxId defaultIconID)
{
    m_isDisplayCollage = VFX_FALSE;
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    setImgContent(VfxImageSrc(defaultIconID));
    m_thumbGroup->setOpacity(0.0f);
}

#endif
