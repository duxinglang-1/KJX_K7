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
 *  vapp_gallery_slideshow.cpp
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
#include "cp\vapp_image_viewer_cp.h"

#if defined(__MMI_FTO_GALLERY__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_gallery_viewer.h"

////////////////////////////////
// Slideshow Base
////////////////////////////////
void VappGallerySlideshowBase::onInit()
{
    VfxFrame::onInit();
}

void VappGallerySlideshowBase::onDeinit()
{
    VfxFrame::onDeinit();
}

#if defined(__VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__)
////////////////////////////////
// Transition slideshow
////////////////////////////////
VappGalleryTransitionSlideshow::VappGalleryTransitionSlideshow():
    m_currentMedia(NULL),
    m_nextMedia(NULL),
    m_pagePanel(NULL),
    m_effectType(VCP_PAGE_EFFECT_NONE)
{
}

void VappGalleryTransitionSlideshow::onInit()
{
    VappGallerySlideshowBase::onInit();

    VFX_OBJ_CREATE(m_pagePanel, VcpPagePanel, this);
    m_pagePanel->setPos(0, 0);
    m_pagePanel->setSize(getSize());
    m_pagePanel->setAlignParent(
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE,
                            VFX_FRAME_ALIGNER_MODE_SIDE);
    m_pagePanel->m_signalFinished.connect(this, &VappGalleryTransitionSlideshow::onPageEffectFinish);
}

void VappGalleryTransitionSlideshow::onDeinit()
{
    VappGallerySlideshowBase::onDeinit();
}

void VappGalleryTransitionSlideshow::configEffectType(VcpPageEffectType effectType)
{
    m_effectType = effectType;
}

void VappGalleryTransitionSlideshow::getOrientationLimit(
        VfxBool &hasLimit,
        VfxScrRotateTypeEnum &orientation)
{
    hasLimit = VFX_FALSE;
    orientation = VFX_SCR_ROTATE_TYPE_NORMAL;
}

void VappGalleryTransitionSlideshow::playOpening()
{
    m_signalFinished.postEmit(NULL, FT_OPENING, VFX_TRUE);
}

void VappGalleryTransitionSlideshow::playEnding()
{
    m_signalFinished.postEmit(NULL, FT_ENDING, VFX_TRUE);
}

void VappGalleryTransitionSlideshow::setNextMedia(VfxFrame *frame)
{
    m_pagePanel->addChildFrame(frame);
    if(NULL == m_currentMedia)
    {
        // if there is no current media, (first media set)
        // then update current media first
        m_currentMedia = frame;
        m_nextMedia = NULL;
        m_pagePanel->setCurrentFrame(m_currentMedia);
    }
    else
    {
        m_nextMedia = frame;
    }
}

void VappGalleryTransitionSlideshow::playMedia()
{
    VFX_ASSERT(m_pagePanel);
    if(m_currentMedia && m_nextMedia)
    {
        // play page effect animation
        m_pagePanel->addChildFrame(m_currentMedia);
        m_pagePanel->addChildFrame(m_nextMedia);
        m_pagePanel->switchTo(
                        m_nextMedia,
                        m_effectType,
                        VappGallerySlideShowSetting::TRANSITION_TIME_MSEC,
                        VCP_PAGE_DIRECTION_FROM_RIGHT);
    }
    else if(m_currentMedia)
    {
        // first media, no transition animation, finish immediately.
        m_pagePanel->addChildFrame(m_currentMedia);
        m_pagePanel->setCurrentFrame(m_currentMedia);
        m_signalFinished.postEmit(m_currentMedia, FT_MEDIA, VFX_TRUE);
    }

}

void VappGalleryTransitionSlideshow::onPageEffectFinish(VfxFrame *target, VfxBool isCompleted)
{
    m_signalFinished.postEmit(target, FT_MEDIA, isCompleted);
}

#endif // __VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__
#endif // __MMI_FTO_GALLERY__