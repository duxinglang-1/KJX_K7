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
 *  vapp_widget_gallery_viewer.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 

#if defined(__MMI_VUI_WIDGET_GALLERY__)

#include "vcp_include.h"
#include "vfx_uc_include.h"

#include "vapp_widget_gallery_viewer.h"
#include "vapp_widget_gallery_setting.h"
#include "vapp_widget_gallery_slide_show_interval_setting.h"

#include "mmi_rp_vapp_widget_gallery_def.h"
#include "stdlib.h"

// for VappGalleryMediaListMediaCache
#include "vapp_gallery_data.h"
#include "vapp_media_list.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

#include "custmenures.h"
#include "FileMgrSrvGProt.h"
#include "Nvram_common_defs.h"
#include "custom_mmi_folders_config.h"

#ifdef __cplusplus
}
#endif


/*****************************************************************************
 * VappWidgetGalleryViewerPanel
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetGalleryViewerPanel", VappWidgetGalleryViewerPanel, VfxImageFrame);

VappWidgetGalleryViewerPanel::VappWidgetGalleryViewerPanel():
    m_isPanelPrepared(VFX_FALSE),
    m_panelId(-1),
    m_picIndex(-1)
{
}
    

void VappWidgetGalleryViewerPanel::onInit()
{
    VfxImageFrame::onInit();

    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    setBackgroundPic();

    VFX_OBJ_CREATE(m_imgPhoto, VfxImageFrame, this);
    m_imgPhoto->setPos(VAPP_WIDGET_GALLERY_PHOTO_FRAME_POS_X, VAPP_WIDGET_GALLERY_PHOTO_FRAME_POS_Y);

    // Activity Indicator
    VFX_OBJ_CREATE(m_indicator, VcpActivityIndicator, this);

    // Sets the position of indicator bar.
    m_indicator->setAnchor(0.5,0.5);
    m_indicator->setPos(getSize().width/2, getSize().height/2);

    //setDefaultPic();
    clear();

    VfxTransform t = getTransform();
    t.type = VRT_TRANSFORM_TYPE_AFFINE;
    t.setIdentity();
    setTransform(t);
}


void VappWidgetGalleryViewerPanel::onDeinit()
{
    VfxImageFrame::onDeinit();
}


void VappWidgetGalleryViewerPanel::setPanelId(VfxS32 index)
{
    m_panelId = index;
}

VfxS32 VappWidgetGalleryViewerPanel::getPanelId() const
{
    return m_panelId;
}


void VappWidgetGalleryViewerPanel::setPicIndex(VfxS32 index)
{
    m_picIndex = index;
}

VfxS32 VappWidgetGalleryViewerPanel::getPicIndex() const
{
    return m_picIndex;
}


void VappWidgetGalleryViewerPanel::setDefaultPic()
{
    m_imgPhoto->setResId(IMG_ID_VAPP_WIDGET_GALLERY_DE_COVER);
}


VfxBool VappWidgetGalleryViewerPanel::isDefaultPic()
{
    VfxResId resId = m_imgPhoto->getImgContent().getResId();   
    return (resId == IMG_ID_VAPP_WIDGET_GALLERY_DE_COVER) ? VFX_TRUE : VFX_FALSE;
}


void VappWidgetGalleryViewerPanel::setErrorPic()
{
    m_imgPhoto->setResId(IMG_ID_VAPP_WIDGET_GALLERY_ERROR_INDICATOR);
}


void VappWidgetGalleryViewerPanel::setPicImageContent(const VfxImageSrc &value)
{
    m_imgPhoto->setImgContent(value);
}


const VfxImageSrc VappWidgetGalleryViewerPanel::getPicImageContent()
{
    return m_imgPhoto->getImgContent();
}


void VappWidgetGalleryViewerPanel::setBackgroundPic()
{
    setResId(IMG_ID_VAPP_WIDGET_GALLERY_PHOTO_BG);
}


void VappWidgetGalleryViewerPanel::setPrepared(VfxBool isPrepared)
{
    m_isPanelPrepared = isPrepared;
}


VfxBool VappWidgetGalleryViewerPanel::getIsPrepared()
{
    return m_isPanelPrepared;
}


void VappWidgetGalleryViewerPanel::clear()
{
    showLoading();
    setPrepared(VFX_FALSE);
    setPicIndex(-1);
    setHidden(VFX_TRUE);
}


void VappWidgetGalleryViewerPanel::setRotation(const VfxFloat degree)
{
    VfxTransform t = getTransform();
    VFX_ASSERT(t.type == VRT_TRANSFORM_TYPE_AFFINE);
    t.data.affine.rz = VFX_DEG_TO_RAD(degree);
    setTransform(t);
}


void VappWidgetGalleryViewerPanel::viewPhoto()
{
    VfxWString path = m_imgPhoto->getImgContent().getPath();

    filetypes_file_type_enum fileType = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath(path.getBuf());
    
    VfxS32 opt_menu = srv_fmgr_types_get_option_menu(fileType, NULL, 0);
    VfxS32 opt_menu_count = GetNumOfChild(opt_menu);        

    VfxS32 fs_ret;
    if (opt_menu_count != 0)
    {
        /* Get first child menu item to launch */                               
        VfxS32 child_id = GetSeqItemId(opt_menu, 0);            
        fs_ret = srv_fmgr_types_launch_option((const WCHAR*)path.getBuf(), child_id);
    }
}
    

void VappWidgetGalleryViewerPanel::showLoading()
{
    m_indicator->start();
}


void VappWidgetGalleryViewerPanel::hideLoading()
{
    m_indicator->stop();
}


VfxBool VappWidgetGalleryViewerPanel::isLoading()
{
    return m_indicator->isAnimating();
}


/*****************************************************************************
 * VappWidgetGalleryViewer
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetGalleryViewer", VappWidgetGalleryViewer, VfxFrame);

VappWidgetGalleryViewer::VappWidgetGalleryViewer():
    m_prepareMemoryFail(VFX_FALSE),
    m_disableSlideShow(VFX_FALSE),
    m_pauseSlideShow(VFX_FALSE),
    m_rotateDirFlag(VFX_FALSE),
    m_nextLockPicId(0),
    m_nextAvailablePanelId(0),
    m_fadeOutPanelId(0),
    m_fadeInPanelId(0),
    m_totalPicNum(0),
    m_lockedCacheNum(0),
    m_usedPanelNum(0),
    m_totalPanelNum(VAPP_WIDGET_GALLERY_MAX_IMAGE_FRAME),
    m_totalCacheNum(VAPP_WIDGET_GALLERY_MAX_IMAGE_FRAME),
    m_timerSlideShow(NULL),
    m_tlFrameFadeOut(NULL),
    m_tlFrameFadeIn(NULL),
    m_state(STATE_INIT),
    m_mediaList(NULL)
{
    // minus backup panel
    m_maxConcurrentShowingPanelNum = m_totalPanelNum-2;

    m_folderPath.setNull();
}


void VappWidgetGalleryViewer::onInit()
{
    VfxFrame::onInit();
    setSize(getParentFrame()->getSize());
    VfxS32 i;
    for(i=0; i<m_totalPanelNum; i++)
    {
        VFX_OBJ_CREATE(m_picPanel[i], VappWidgetGalleryViewerPanel, this);
        m_picPanel[i]->setPanelId(i);
        m_picPanel[i]->setAnchor(0.5, 0.5);
        resetPanelPos(m_picPanel[i]);
        m_picPanel[i]->showLoading();
    }

    showDefaultPic();

    // temp slide show time
    VFX_OBJ_CREATE(m_timerSlideShow, VfxTimer, this);
    m_timerSlideShow->setStartDelay(getSlideShowTime());
    m_timerSlideShow->m_signalTick.connect(this,&VappWidgetGalleryViewer::onSlideShowTimeout);

    // arrow timeline
    VFX_OBJ_CREATE(m_tlFrameFadeOut, VfxFloatTimeline, this);
    m_tlFrameFadeOut->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_tlFrameFadeOut->setDuration(VAPP_WIDGET_GALLERY_FADE_OUT_TIME);
    m_tlFrameFadeOut->m_signalStopped.connect(this, &VappWidgetGalleryViewer::tlFadeOutStoppedHandler);
    m_tlFrameFadeOut->setFromValue(1);
    m_tlFrameFadeOut->setToValue(0);

    VFX_OBJ_CREATE(m_tlFrameFadeIn, VfxFloatTimeline, this);
    m_tlFrameFadeIn->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_tlFrameFadeIn->setDuration(VAPP_WIDGET_GALLERY_FADE_IN_TIME);
    m_tlFrameFadeIn->m_signalStopped.connect(this, &VappWidgetGalleryViewer::tlFadeInStoppedHandler);
    m_tlFrameFadeIn->setFromValue(0);
    m_tlFrameFadeIn->setToValue(1);

}

void VappWidgetGalleryViewer::onDeinit()
{
    m_timerSlideShow->m_signalTick.disconnect(this,&VappWidgetGalleryViewer::onSlideShowTimeout);

    VFX_OBJ_CLOSE(m_timerSlideShow);

    VfxS32 i=0;

    // unlock all locked cache before close media cache
    VappWidgetGalleryViewerPanel *panel;
    for(i=0; i<m_totalPanelNum; i++)
    {
        panel = getPanelById(i);
        if(panel->getIsPrepared() && !panel->isDefaultPic())
        {
            m_mediaList->unlockThumb(
                VcpMenuPos(0,panel->getPicIndex()), 
                panel->getPicImageContent().getImageBuffer());
        }
    }

    for(i=0; i<VAPP_WIDGET_GALLERY_MAX_IMAGE_FRAME; i++)
    {
        VFX_OBJ_CLOSE(m_picPanel[i]);
    }

    VFX_OBJ_CLOSE(m_mediaList);   
    
    VfxFrame::onDeinit();
}


void VappWidgetGalleryViewer::createMediaList()
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_CREATE_MEDIA_LIST, 200);
    if(m_folderPath == getSelectedFolderPath())
    {   
        if(isAllowSlideShow())
        {
            startSlideShowTimer();
        }
        return;
    }

    if(m_mediaList == NULL)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_CREATE_MEDIA_LIST, 201);
        VFX_OBJ_CREATE(m_mediaList, VappGalleryMediaListMediaCache, this);
        m_mediaList->configUseAnonymousASM(VFX_TRUE);
        m_mediaList->configCache(VGCT_THUMBNAIL, VAPP_WIDGET_GALLERY_MAX_IMAGE_FRAME);
        m_mediaList->configThumbnailSize(VfxSize(VAPP_WIDGET_GALLERY_PHOTO_WIDTH, VAPP_WIDGET_GALLERY_PHOTO_HEIGHT));

        // image folder scans only image, no video
        FMGR_FILTER filter;
        FMGR_FILTER_INIT(&filter);
        FMGR_FILTER_SET_IMAGE(&filter);
        m_mediaList->configFileTypeFilter(&filter);
    }

    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_CREATE_MEDIA_LIST, 202);
    const U8 defaultDrv = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
    VfxWString dbFolder;
    VappGalleryDB::getDBFolderPath(defaultDrv, dbFolder);
    VfxWString dbName = VFX_WSTR("GalleryWidget.db");

    // re-config selected folder after widget restore
    m_folderPath = getSelectedFolderPath();
    m_mediaList->configPath(
                    m_folderPath, 
                    dbFolder,
                    dbName
                );
    
    // start prepare media list
    m_mediaList->getListEvent()->connect(this, &VappWidgetGalleryViewer::onMediaListReady);
    m_mediaList->prepareList();

    m_mediaList->getDecodeEvent()->connect(this, &VappWidgetGalleryViewer::onDecodeResult);
}


void VappWidgetGalleryViewer::onMediaListReady(VappGalleryPrepareResult prepareResult)
{
    VfxBool noContent = (0 == m_mediaList->getGroupCount() ||
                         0 == m_mediaList->getMediaCountInGroup(0));
    VfxImageBuffer thumbBuf;

    if(noContent)
    {
        // show default pic
        m_usedPanelNum = 1;
        panelAppearingControlHandler();
    }
    else
    {
        if(prepareResult == PREPARE_ERROR_OUT_OF_MEMORY)
        {
            m_prepareMemoryFail = VFX_TRUE;
            panelAppearingControlHandler();
            return;
        }
    
        if(m_totalPicNum != m_mediaList->getMediaCountInGroup(0))
        {
            m_totalPicNum = m_mediaList->getMediaCountInGroup(0);
            
            // reset next lock pic id if folder content changed
            setNextLockPicId(0);
        }
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_ON_MEDIA_LIST_READY, m_totalPicNum, 200);
        if(m_totalPicNum < m_totalPanelNum)
        {
            m_usedPanelNum = m_totalPicNum+1;
        }
        else
        {
            m_usedPanelNum = m_totalPanelNum;
        }
        
        VfxS32 index = getNextLockPicId();
        VappGalleryDecodeResult result =  m_mediaList->startDecodeThumb(VcpMenuPos(0,index), thumbBuf);
        decodeResultHandler(result, index, thumbBuf);
    }
}


// This funciton is called after lockThumb, so img buffer OK if result is OK
void VappWidgetGalleryViewer::decodeResultHandler(const VappGalleryDecodeResult result, VfxS32 picIndex, const VfxImageBuffer imgBuf)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_DECODE_RESULT_HANDLER, result, picIndex, 200);

    switch(result)
    {
        case DECODING:
            break;
            
        case CANCELLED:
        case UNEXPECTED:
        case FORMAT_UNSUPPORTED:
        case DRM_LOCKED:
            decodeFinishedHandler(getNextAvailablePanel(), picIndex, imgBuf, VFX_FALSE);
            break;

        case OK:
            decodeFinishedHandler(getNextAvailablePanel(), picIndex, imgBuf, VFX_TRUE);
            break;      
    }

}


// This funciton is callback of media cache, it needs to lock again if result is OK
void VappWidgetGalleryViewer::onDecodeResult(VcpMenuPos menuPos, VappGalleryDecodeResult result)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_ON_DECODE_RESULT, result, menuPos.pos, 200);
    VfxImageBuffer imgBuf;
    VappGalleryDecodeResult res;

    switch(result)
    {
        case DECODING:
            break;
            
        case CANCELLED:
        case UNEXPECTED:
        case FORMAT_UNSUPPORTED:
        case DRM_LOCKED:
            decodeFinishedHandler(getNextAvailablePanel(), menuPos.pos, imgBuf, VFX_FALSE);
            break;

        case OK:
            // after receive callback, it should lock again to get imgBuf
            res =  m_mediaList->lockThumb(menuPos, imgBuf, SRV_MEDIACACHE_IMAGE_SOURCE_CACHE);
            decodeFinishedHandler(getNextAvailablePanel(), menuPos.pos, imgBuf, VFX_TRUE);
            break;      
    }
}


// TODO : need to be modified
void VappWidgetGalleryViewer::decodeFinishedHandler(VappWidgetGalleryViewerPanel *panel, VfxS32 picIndex, const VfxImageBuffer imgBuf, VfxBool isSuccess)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_DECODE_FINISHED_HANDLER, panel->getPanelId(), picIndex, 200);

    if(isSuccess)
    {
        preparePanel(panel, picIndex, imgBuf);        
    }
    else
    {
        // decode fail, prepare default cover on panel
        prepareDefaultPanel(panel, picIndex);
    }
    
    m_lockedCacheNum++;
    VFX_ASSERT(m_lockedCacheNum <= m_totalCacheNum);
    if(m_state == STATE_INIT)
    {
        if((m_lockedCacheNum == m_totalPicNum) &&
           (m_lockedCacheNum > 1) &&
           (m_lockedCacheNum < m_totalCacheNum))
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_DECODE_FINISHED_HANDLER, 0, 0, 300);
            VappWidgetGalleryViewerPanel* tmpPanel = getPanelById(getFadeOutPanelId());
            VfxImageBuffer tmpBuf;
            VfxS32 tmpIndex = tmpPanel->getPicIndex();
            if(tmpPanel->isDefaultPic())
            {
                prepareDefaultPanel(getNextAvailablePanel(), tmpIndex);
            }
            else
            {
                tmpBuf = tmpPanel->getPicImageContent().getImageBuffer();
                preparePanel(getNextAvailablePanel(), tmpIndex, tmpBuf);
            }
            m_state = STATE_ACTIVE;
            panelAppearingControlHandler();
            return;
        }
            
        if(!isCacheEnough())
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_DECODE_FINISHED_HANDLER, 0, 0, 301);
            m_state = STATE_ACTIVE;
            panelAppearingControlHandler();
            return;            
        }
        
        VfxImageBuffer thumbBuf;
        VfxS32 index = getNextLockPicId();
        if(index == m_picPanel[getFadeOutPanelId()]->getPicIndex())
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_DECODE_FINISHED_HANDLER, 0, 0, 302);
            panelAppearingControlHandler();
            return;
        }
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_DECODE_FINISHED_HANDLER, 0, 0, 200);
        VappGalleryDecodeResult result =  m_mediaList->startDecodeThumb(
                                    VcpMenuPos(0, index), 
                                    thumbBuf);      
        decodeResultHandler(result, index, thumbBuf);
    }
}


void VappWidgetGalleryViewer::prepareDefaultPanel(VappWidgetGalleryViewerPanel *panel, VfxS32 picIndex)
{
    VFX_ASSERT(picIndex >= 0);
    panel->hideLoading();
    panel->setPicIndex(picIndex);
    panel->setPrepared(VFX_TRUE);
    panel->setDefaultPic();

    transformPanel(panel);
}


void VappWidgetGalleryViewer::preparePanel(VappWidgetGalleryViewerPanel *panel, VfxS32 picIndex, const VfxImageBuffer imgBuf)
{
    // random rotate panel -4 ~ 4 degree
    transformPanel(panel);
    
    setImageBufferToPanel(panel, picIndex, imgBuf);
}


// control handler the appearing of all panels
void VappWidgetGalleryViewer::showDefaultPic()
{
    VappWidgetGalleryViewerPanel *panel;
    panel = getPanelById(0);
    panel->setHidden(VFX_FALSE);
    panel->sendToBack();

    VfxS32 i=0;
    for(i=1; i<m_totalPanelNum; i++)
    {
        panel = getPanelById(i);
        panel->setHidden(VFX_TRUE);
        panel->sendToBack();        
    }
}


void VappWidgetGalleryViewer::transformPanel(VappWidgetGalleryViewerPanel* panel)
{
    VfxS32 degree = rand() % 5;
    if(!m_rotateDirFlag)
    {
        degree = -degree;
    }

    m_rotateDirFlag = !m_rotateDirFlag;
    panel->setRotation(degree);

    VfxS32 offsetX = rand() % VAPP_WIDGET_GALLERY_PHOTO_RANDOM_X_RANGE;
    VfxS32 offsetY = rand() % VAPP_WIDGET_GALLERY_PHOTO_RANDOM_Y_RANGE;
    VfxS32 directionX = rand() % 2;
    VfxS32 directionY = rand() % 2;

    if(directionX == 0)
    {
        offsetX = -offsetX;
    }
 
    if(directionY == 0)
    {
        offsetY = -offsetY;
    }   

    panel->setPos(panel->getPos().x+offsetX, panel->getPos().y+offsetY);
}


void VappWidgetGalleryViewer::setImageBufferToPanel(VappWidgetGalleryViewerPanel *panel, VfxS32 picIndex, const VfxImageBuffer imgBuf)
{
    VFX_ASSERT(picIndex >= 0);
    panel->hideLoading();
    panel->setPicIndex(picIndex);
    panel->setPicImageContent(VfxImageSrc(imgBuf));
    panel->setPrepared(VFX_TRUE);
}


VfxS32 VappWidgetGalleryViewer::getNextLockPicId()
{
    VfxS32 index = m_nextLockPicId;
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_GALLERY_VIEWER_GET_NEXT_LOCK_PIC_ID, index, 200);
    
    m_nextLockPicId++;
    m_nextLockPicId = m_nextLockPicId % m_totalPicNum;
    return index;
}


void VappWidgetGalleryViewer::setNextLockPicId(VfxS32 index)
{
    m_nextLockPicId = index;
}


VfxS32 VappWidgetGalleryViewer::getFadeoutPicId()
{
    // there is no pic loading finished
    if(getPanelById(getFadeOutPanelId())->getPicIndex() < 0)
    {
        return 0;
    }
    return getPanelById(getFadeOutPanelId())->getPicIndex();
}


VfxS32 VappWidgetGalleryViewer::getNextPanelIdAfterIndex(VfxS32 index)
{
    return (index+1) % m_usedPanelNum;
    //return (index+1) % m_totalPanelNum;
}


VfxS32 VappWidgetGalleryViewer::getFadeOutPanelId()
{
    return m_fadeOutPanelId;
}


VfxS32 VappWidgetGalleryViewer::getFadeInPanelId()
{
    return m_fadeInPanelId;
}


VfxS32 VappWidgetGalleryViewer::getNextAvailablePanelId()
{
    VfxS32 index = m_nextAvailablePanelId;

    m_nextAvailablePanelId++;
    //m_nextAvailablePanelId = m_nextAvailablePanelId % m_totalPanelNum;
    m_nextAvailablePanelId = m_nextAvailablePanelId % m_usedPanelNum;
    return index;
}


VappWidgetGalleryViewerPanel* VappWidgetGalleryViewer::getNextAvailablePanel()
{
    VappWidgetGalleryViewerPanel *panel = m_picPanel[getNextAvailablePanelId()];
    if(panel->getIsPrepared())
    {
        // this panel should be free to be assigned image
        VFX_ASSERT(0);
    }
    return panel;
}


void VappWidgetGalleryViewer::startSlideShowTimer()
{
    m_timerSlideShow->start();
}
    


void VappWidgetGalleryViewer::stopSlideShowTimer()
{
    m_timerSlideShow->stop();
}


void VappWidgetGalleryViewer::onSlideShowTimeout(VfxTimer* pTimer)
{
    changeToNextPhoto();
}


VappWidgetGalleryViewerPanel*  VappWidgetGalleryViewer::getPanelById(VfxS32 id)
{
    return m_picPanel[id];
}


// control handler the appearing of all panels
void VappWidgetGalleryViewer::panelAppearingControlHandler()
{
    if(m_prepareMemoryFail == VFX_TRUE)
    {
        // show error picture
        VappWidgetGalleryViewerPanel *panel;
        panel = getPanelById(0);
        panel->hideLoading();
        panel->setErrorPic();
        showDefaultPic();
        return;
    }

    if(m_totalPicNum == 0)
    {
        // show default picture
        VappWidgetGalleryViewerPanel *panel;
        panel = getPanelById(0);
        panel->hideLoading();
        panel->setDefaultPic();
        showDefaultPic();
        return;
    }

    VfxS32 index = 0;

    VfxS32 firstPanelId = getFadeOutPanelId();
    VappWidgetGalleryViewerPanel *panel;
    panel = getPanelById(firstPanelId);
    panel->setHidden(VFX_FALSE);
    panel->sendToBack();

    // set the showing panel visible
    VfxS32 maxShowPanelNum = 0;
    if(m_totalPicNum < m_maxConcurrentShowingPanelNum)
    {
        maxShowPanelNum = m_totalPicNum;
    }
    else
    {
        maxShowPanelNum = m_maxConcurrentShowingPanelNum;
    }
    index = firstPanelId;
    
    VfxS32 i =0;
    for(i=1; i<maxShowPanelNum; i++)
    {
        index = getNextPanelIdAfterIndex(index);
        panel = getPanelById(index);
        panel->setHidden(VFX_FALSE);
        panel->sendToBack();
    }
    
    m_fadeInPanelId = getNextPanelIdAfterIndex(index);

    for(i=maxShowPanelNum; i<m_usedPanelNum; i++)
    {
        index = getNextPanelIdAfterIndex(index);
        panel = getPanelById(index);
        panel->setHidden(VFX_TRUE);
        panel->sendToBack();        
    }

    // hide unused panel
    for(i=m_usedPanelNum; i<m_totalPanelNum; i++)
    {
        panel = getPanelById(i);
        panel->setHidden(VFX_TRUE);
        panel->sendToBack();           
    }
}


void VappWidgetGalleryViewer::changeToNextPhoto()
{
    VappWidgetGalleryViewerPanel *panel;
    VfxS32 fadeOutPanelId = getFadeOutPanelId();
    panel = getPanelById(fadeOutPanelId);
    if(panel->isLoading())
    {
        // No necessary to change pic when panel is in loading state.
        return;
    }

    panelAppearingControlHandler();

    if(m_tlFrameFadeOut->getIsEnabled() ||
       m_tlFrameFadeIn->getIsEnabled() )
    {
        m_tlFrameFadeOut->stop();
        m_tlFrameFadeIn->stop();
        return;
    }
        
    stopSlideShowTimer();

    if(m_totalPicNum <= 1)
    {
        return;
    }

    panel = getPanelById(getNextPanelIdAfterIndex(getFadeOutPanelId()));
    // stop change to next panel if next panel image is not ready
    if(!panel->getIsPrepared())
    {
        if(isAllowSlideShow())
        {
            startSlideShowTimer();
        }
        return;
    }
    
    VfxS32 backupPanelId = getNextPanelIdAfterIndex(getFadeInPanelId());
    panel = getPanelById(backupPanelId);
    if((m_totalPicNum > m_totalPanelNum) && !panel->getIsPrepared())
    {
        if(isAllowSlideShow())
        {
            startSlideShowTimer();
        }
        return;
    }
    
    fadeOutPanelId = getFadeOutPanelId();
    panel = getPanelById(fadeOutPanelId);
    //VFX_ASSERT(panel->getIsPrepared());

    m_tlFrameFadeOut->setTarget(panel);
    m_tlFrameFadeOut->start();
}


void VappWidgetGalleryViewer::viewCurrentPhoto()
{
    VappWidgetGalleryViewerPanel *panel = getPanelById(getFadeOutPanelId());

    VfxImageSrc src;
    m_mediaList->getMediaSource( VcpMenuPos(0,panel->getPicIndex()), src);
    
    VfxWString path = src.getPath();

    filetypes_file_type_enum fileType = (filetypes_file_type_enum)srv_fmgr_types_find_type_by_filepath(path.getBuf());
    
    VfxS32 opt_menu = srv_fmgr_types_get_option_menu(fileType, NULL, 0);
    VfxS32 opt_menu_count = GetNumOfChild(opt_menu);        

    VfxS32 fs_ret;
    if (opt_menu_count != 0)
    {
        /* Get first child menu item to launch */                               
        VfxS32 child_id = GetSeqItemId(opt_menu, 0);            
        fs_ret = srv_fmgr_types_launch_option((const WCHAR*)path.getBuf(), child_id);
    }
}


VfxBool VappWidgetGalleryViewer::isAllowSlideShow()
{
    if(m_disableSlideShow || m_pauseSlideShow)
    {
        return VFX_FALSE;
    }
    
    return VFX_TRUE;    
}


void VappWidgetGalleryViewer::setDisableSlideShow(VfxBool disable)
{
    m_disableSlideShow = disable;   
}


void VappWidgetGalleryViewer::setPauseSlideShow(VfxBool pause)
{
    m_pauseSlideShow = pause;   
}


void VappWidgetGalleryViewer::switchImgSrcBetweenPanels()
{
    if(m_totalPicNum == 1)
    {
        return;
    }
    
    VfxS32 i=0;
    VappWidgetGalleryViewerPanel *panel = getPanelById(getFadeOutPanelId());
    VfxImageSrc tmp_imgSrc;
    VfxS32 panelId = panel->getPanelId();
    tmp_imgSrc = panel->getPicImageContent();
    
    for(i=0; i<m_totalPicNum-1; i++)
    {
        panel = getPanelById(panelId);
        panel->setPicImageContent(getPanelById(getNextPanelIdAfterIndex(panelId))->getPicImageContent());
        panelId = getNextPanelIdAfterIndex(panelId);
    }
    m_fadeInPanelId = panelId;
    panel = getPanelById(panelId);
    panel->setPicImageContent(tmp_imgSrc);
}


void VappWidgetGalleryViewer::tlFadeOutStoppedHandler(
    VfxBaseTimeline *timeline, 
    VfxBool isCompleted)
{    
    VappWidgetGalleryViewerPanel *panel = (VappWidgetGalleryViewerPanel *)timeline->getTarget();
    VFX_OBJ_ASSERT_VALID(panel);

    panel->setOpacity(1);
    panel->setOpacity(0);

    if(m_totalPicNum <= m_totalPanelNum)
    {
        VappWidgetGalleryViewerPanel *nextPanel = getPanelById(getNextPanelIdAfterIndex(panel->getPanelId()));
        VFX_OBJ_ASSERT_VALID(nextPanel);

        m_fadeOutPanelId = getNextPanelIdAfterIndex(panel->getPanelId());
        
        insertChildFrameAfter(
            getPanelById(getFadeInPanelId()),
            panel);
        resetPanelPos(panel);

        if(m_totalPicNum == m_totalPanelNum)
        {
            // only need to put this panel in the end of list
            transformPanel(panel);
        }
        else
        {
            panel->clear();
            
            // assign next panel img buffer to this panel
            if(nextPanel->isDefaultPic())
            {
                prepareDefaultPanel(panel, nextPanel->getPicIndex());
            }
            else
            {
                preparePanel(
                    panel, 
                    nextPanel->getPicIndex(),
                    nextPanel->getPicImageContent().getImageBuffer());
            } 
        }
    }
    else
    {
        if(!panel->isDefaultPic())
        {
            // unlock first pic and lock next pic
            m_mediaList->unlockThumb(
                VcpMenuPos(0,panel->getPicIndex()), 
                panel->getPicImageContent().getImageBuffer());
        }

        m_fadeOutPanelId = getNextPanelIdAfterIndex(panel->getPanelId());

        panel->clear();
        resetPanelPos(panel);
        
        m_lockedCacheNum--;

        VfxImageBuffer thumbBuf;
        VfxS32 index = getNextLockPicId();
        VappGalleryDecodeResult result =  m_mediaList->startDecodeThumb(
                                    VcpMenuPos(0, index), 
                                    thumbBuf);      
        decodeResultHandler(result, index, thumbBuf);
    }

    // fade in next image after fade out complete
    VfxS32 fadeInPanelId = getFadeInPanelId();
    if(fadeInPanelId != -1)
    {
        panel = getPanelById(fadeInPanelId);
        //VFX_ASSERT(panel->getIsPrepared());
        m_tlFrameFadeIn->setTarget(panel);
        m_tlFrameFadeIn->start();
        panel->setHidden(VFX_FALSE);
    }
}


void VappWidgetGalleryViewer::tlFadeInStoppedHandler(
    VfxBaseTimeline *timeline, 
    VfxBool isCompleted)
{
    VappWidgetGalleryViewerPanel *panel = (VappWidgetGalleryViewerPanel *)timeline->getTarget();
    VFX_OBJ_ASSERT_VALID(panel);

    panel->setOpacity(0);
    panel->setOpacity(1);
    
    if(isAllowSlideShow())
    {
        startSlideShowTimer();
    }
}


VfxMsec VappWidgetGalleryViewer::getSlideShowTime()
{
    return vapp_widget_gallery_set_get_slide_show_timeout_value_in_msec();
}


void VappWidgetGalleryViewer::resetPanelPos(VappWidgetGalleryViewerPanel *panel)
{
    panel->setPos(VAPP_WIDGET_GALLERY_PANEL_ORI_POS_X,VAPP_WIDGET_GALLERY_PANEL_ORI_POS_Y);
}


VfxBool VappWidgetGalleryViewer::isCacheEnough()
{
    return (m_lockedCacheNum == m_totalCacheNum) ? VFX_FALSE : VFX_TRUE;
}


VfxWString VappWidgetGalleryViewer::getSelectedFolderPath()
{
    VfxWChar buffer[SRV_FMGR_PATH_MAX_LEN + 1];
    S16 error;
    memset(buffer, 0, (SRV_FMGR_PATH_MAX_LEN + 1));
    ReadRecord(
        NVRAM_EF_VAPP_WIDGET_GALLERY_PHOTO_FOLDER_PATH_LID, 
        1, 
        &buffer, 
        NVRAM_EF_VAPP_WIDGET_GALLERY_PHOTO_FOLDER_PATH_SIZE, 
        &error); 

    if(mmi_wcslen(buffer) == 0)
    {   
        mmi_wcscat(buffer, srv_fmgr_drv_get_path_by_type(SRV_FMGR_DRV_PHONE_TYPE));
        mmi_wcscat(buffer, (VfxWChar*)SHOOTING_DOWNLOAD_FOLDER_NAME);
    }
    
    return  VFX_WSTR_MEM(buffer);
}
#endif
