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
 *  vapp_widget_gallery_control_bar.cpp
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

#include "vapp_widget_gallery.h"
#include "vapp_widget_gallery_control_bar.h"
#include "mmi_rp_vapp_widget_gallery_def.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif


#ifdef __cplusplus
}
#endif

extern "C" void vapp_widget_gallery_setting_launch();


/*****************************************************************************
 * Enum
 *****************************************************************************/
enum VappWidgetGalleryBtnEnum
{
    PausePlayBtnId = 0,
    NextPhotoBtnId,
    ViewBtnId,
    SettingBtnId
};


/*****************************************************************************
 * Define
 *****************************************************************************/
struct vapp_widget_gallery_play_btn_struct
{
    VfxResId resId;
};

struct vapp_widget_gallery_control_bar_button_struct
{
    VappWidgetGalleryBtnEnum btnEnum;
    VfxResId resId;
};


/*****************************************************************************
 * VappWidgetGalleryControlBar
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidgetGalleryControlBar", VappWidgetGalleryControlBar, VfxImageFrame);

VappWidgetGalleryControlBar::VappWidgetGalleryControlBar():
    m_playBtnState(STATE_PLAY)
{
}


void VappWidgetGalleryControlBar::onInit()
{
    VfxImageFrame::onInit();
    setBgColor(VFX_COLOR_TRANSPARENT);
    setResId(IMG_ID_VAPP_WIDGET_GALLERY_CONTROL_BAR_BG);
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setSize( VAPP_WIDGET_GALLERY_CONTROL_BAR_WIDTH, getSize().height);

    static const vapp_widget_gallery_control_bar_button_struct btnMapTbl[] =
    {
        { PausePlayBtnId, IMG_ID_VAPP_WIDGET_GALLERY_BTN_PAUSE},    // initial image is pause
        { NextPhotoBtnId, IMG_ID_VAPP_WIDGET_GALLERY_BTN_REFRESH},
        { ViewBtnId, IMG_ID_VAPP_WIDGET_GALLERY_BTN_VIEW},
        { SettingBtnId, IMG_ID_VAPP_WIDGET_GALLERY_BTN_SETTIG},
    };

    VfxS32 i=0;
    for(i=0; i<VAPP_WIDGET_GALLERY_BUTTON_NUM; i++)
    {
        VFX_OBJ_CREATE(m_button[i], VcpImageButton, this);
        m_button[i]->setAnchor(0.5, 0.5);
        m_button[i]->setSize(VAPP_WIDGET_GALLERY_BUTTON_WIDTH, VAPP_WIDGET_GALLERY_BUTTON_HEIGHT);
        m_button[i]->setImage(VcpStateImage(btnMapTbl[i].resId));
        m_button[i]->setId(btnMapTbl[i].btnEnum);
        m_button[i]->setIsEffect(VFX_TRUE);
        m_button[i]->setEffectSize(VfxSize(VAPP_WIDGET_GALLERY_BUTTON_HALO_WIDTH,VAPP_WIDGET_GALLERY_BUTTON_HALO_HEIGHT));
        m_button[i]->m_signalClicked.connect(this, &VappWidgetGalleryControlBar::onBtnClicked);

        if(i == 0)
        {
            m_button[i]->setPos( getSize().width/2 - 1.5*(VAPP_WIDGET_GALLERY_BUTTON_WIDTH+VAPP_WIDGET_GALLERY_BUTTON_GAP), 
                                 getSize().height/2);
        }
        else if(i == 1)
        {
            m_button[i]->setPos( getSize().width/2 - 0.5*(VAPP_WIDGET_GALLERY_BUTTON_WIDTH+VAPP_WIDGET_GALLERY_BUTTON_GAP), 
                                 getSize().height/2);            
        }
        else if(i == 2)
        {
            m_button[i]->setPos( getSize().width/2 + 0.5*(VAPP_WIDGET_GALLERY_BUTTON_WIDTH+VAPP_WIDGET_GALLERY_BUTTON_GAP), 
                                 getSize().height/2); 
        }
        else if(i == 3)
        {
            m_button[i]->setPos( getSize().width/2 + 1.5*(VAPP_WIDGET_GALLERY_BUTTON_WIDTH+VAPP_WIDGET_GALLERY_BUTTON_GAP), 
                                 getSize().height/2);
        }
    }   
}


void VappWidgetGalleryControlBar::onDeinit()
{
    VfxImageFrame::onDeinit();
}


void VappWidgetGalleryControlBar::onBtnClicked(VfxObject *btn, VfxId id)
{
    VappWidgetGallery *galleryWidget = (VappWidgetGallery *)getParentFrame();

    galleryWidget->restartHideControlBarTimer();

    switch(id)
    {
        case PausePlayBtnId:
            onPausePlayBtnClicked();
            break;
            
        case NextPhotoBtnId:    
            galleryWidget->getGalleryViewer()->changeToNextPhoto();
            break;
            
        case ViewBtnId:
            galleryWidget->getGalleryViewer()->viewCurrentPhoto();
            break;
            
        case SettingBtnId:
            vapp_widget_gallery_setting_launch();
            break;
            
        default:
            VFX_ASSERT(0);
            break;
    }
}


void VappWidgetGalleryControlBar::setPlayBtnState(VfxS32 state)
{
    VFX_ASSERT(state < STATE_LAST);
    m_playBtnState = (GalleryWidgetBtnStateEnum) state;

    if(getPlayBtnState() == STATE_PAUSE)
    {
        pauseSlideShow();
    }
    else
    {
        playSlideShow();
    }
}


VfxS32 VappWidgetGalleryControlBar::getPlayBtnState()
{
    return m_playBtnState;
}


void VappWidgetGalleryControlBar::onPausePlayBtnClicked()
{
    switchPlayBtnState();
}


void VappWidgetGalleryControlBar::switchPlayBtnState()
{
    if(m_playBtnState == STATE_PLAY)
    {
        m_playBtnState = STATE_PAUSE;
    }
    else
    {
        m_playBtnState = STATE_PLAY;
    }
    setPlayBtnState(m_playBtnState);
}


void VappWidgetGalleryControlBar::playSlideShow()
{
    VappWidgetGallery *galleryWidget = (VappWidgetGallery *)getParentFrame();
    galleryWidget->getGalleryViewer()->setPauseSlideShow(VFX_FALSE);

    // show pause btn when play state
    m_button[PausePlayBtnId]->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_GALLERY_BTN_PAUSE));
}
    

void VappWidgetGalleryControlBar::pauseSlideShow()
{
    VappWidgetGallery *galleryWidget = (VappWidgetGallery *)getParentFrame();
    galleryWidget->getGalleryViewer()->setPauseSlideShow(VFX_TRUE);

    // show pause btn when play state
    m_button[PausePlayBtnId]->setImage(VcpStateImage(IMG_ID_VAPP_WIDGET_GALLERY_BTN_PLAY));
}
#endif
