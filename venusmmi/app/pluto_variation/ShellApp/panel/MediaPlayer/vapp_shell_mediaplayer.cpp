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
 *  vapp_shell_mediaplayer.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Shell Media Player Panel
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_MEDIA_PLAYER__
#include "vapp_shell_mediaplayer.h"
#include "mmi_rp_app_shellapp_base_def.h"
//#include "vtst_main.h"
#include "ShellApp\panel\MediaPlayer\vadp_shell_mediaplayer.h"
#include "mmi_rp_app_venus_shell_mediaplayer_def.h"
#include "vapp_shell_mediaplayer_cfg.h"
#include "trc/vadp_app_trc.h"
/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "MediaAppWidgetDef.h"
#include "plstSrvGprot.h"
#include "mdi_audio.h"
#include "vadp_app_trc.h"
#include "kal_general_types.h"
#include "stdio.h"
#include "kal_public_api.h"
#include "MMIDataType.h"
#include "Unicodexdcl.h"
#include "stack_config.h"
#include "kal_trace.h"
#include "string.h"
#include "Conversions.h"
#include "MediaCacheSrvGprot.h"
#include "BTMMIAVRCPGProt.h"

extern void mmi_medply_app_pre_entry(void);
extern void (*g_medply_shell_play_callback)(void);
extern void mmi_medply_stop_playing(void);
#ifdef __cplusplus
}
#endif


#include "vadp_shell_mediaplayer.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_primitive_frame.h"
#include "vfx_frame.h"
#include "vfx_input_event.h"
#include "vfx_basic_type.h"
#include "vfx_signal.h"
#include "vfx_base_popup.h"
#include "vfx_image_src.h"
#include "vcp_image_button.h"
#include "vcp_state_image.h"
#include "vfx_timer.h"
#include "vfx_class_info.h"
#include "vfx_control.h"
#include "vfx_renderer.h"
#include "vfx_system.h"
#include "vrt_datatype.h"
#include "vrt_system.h"
#include "vcp_segment_button.h"
#include "vfx_string.h"
#include "vcp_marquee.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vcp_page_panel.h"
#include "vcp_waiting_icon.h"
#include "vfx_weak_ptr.h"
#include "vcp_command_title.h"
#include "vcp_wheel_menu.h"
#include "vapp_shell_panel.h"

#if 0// defined(__MTK_TARGET__)
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
#else
#define START_TIME() 
#define STOP_TIME(_trace_)
#endif

#if defined(__MMI_MAINLCD_240X320__) && defined(__MMI_VUI_SHELL_MEDIA_PLAYER_SLIM__) && defined(__CPU_ARM7EJ_S__)
#define __SHELL_MEDIAPLAYER_SUPER_SLIM__
#endif

/***************************************************************************** 
 * VappShellMediaplayerProgressBar Implementation
 *****************************************************************************/

VappShellMediaplayerProgressBar::VappShellMediaplayerProgressBar() : 
m_ratio(0),
m_imageHd(NULL),
m_barWidth(0),
m_barHeight(0),
m_progressHeight(0),
m_progressWidth(0),
m_minWidth(0)
{

}

VappShellMediaplayerProgressBar::~VappShellMediaplayerProgressBar()
{

}

void VappShellMediaplayerProgressBar::setMinWidth(VfxS32 minWidth)
{
    m_minWidth = minWidth;
}

void VappShellMediaplayerProgressBar::setRatio(VfxS32 ratio)
{
    m_ratio = ratio;
    m_progressWidth = (m_barWidth*ratio)/100;

    if (m_progressWidth < m_progressMinWidth && m_progressWidth !=0)
        m_imageFg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_LEFT);
    else
        m_imageFg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    
    //kal_prompt_trace(MOD_VAPP,"xxxxxxxxxxxxxxxxxxxxxx width=%d, line:%d\n", m_progressWidth,__LINE__);    
    //VFX_TRACE(("xxxxxxxxxxxxxxxxxxxxxx width=%d, line:%d\n", m_progressWidth,__LINE__));    
    m_imageFg->setSize(m_progressWidth,m_progressHeight);
    m_imageFg->setBounds(0,0,m_progressWidth,m_progressHeight);
    m_imageFg->invalidate();
    if (m_imageHd!=NULL)
    {
        m_imageHd->setPos(m_progressWidth-m_imageHdOffsetX,0);//(m_barHeight/2)-m_imageHdOffsetY);
    }
}

VfxS32 VappShellMediaplayerProgressBar::getRatio() const
{
    return m_ratio;
}

void VappShellMediaplayerProgressBar::setHead(VfxResId resId)
{
    if (m_imageHd == NULL)
    {
        VFX_OBJ_CREATE(m_imageHd, VfxImageFrame, this);
    }

    m_imageHd->setAutoAnimate(VFX_FALSE);
    m_imageHd->bringToFront();
    m_imageHd->setOpacity(1);
    m_imageHd->setResId(resId);
    m_imageHdOffsetX = m_imageHd->getBounds().getWidth()/2;
    m_imageHdOffsetY = getBounds().getHeight()/2;
    m_imageHd->setPos(m_progressWidth-m_imageHdOffsetX,0);//(m_barHeight/2)-m_imageHdOffsetY);
}

    
void VappShellMediaplayerProgressBar::onInit()
{
    VfxFrame::onInit();

    VFX_OBJ_CREATE(m_imageFg, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_imageBg, VfxImageFrame, this);

    m_imageFg->setAutoAnimate(VFX_FALSE);
    m_imageFg->bringToFront();
    m_imageFg->setOpacity(1);
    m_imageBg->setAutoAnimate(VFX_FALSE);
    m_imageBg->setOpacity(1);
}

void VappShellMediaplayerProgressBar::onDeinit()
{   
    VfxFrame::onDeinit();
}

void VappShellMediaplayerProgressBar::setBarWidth(VfxU32 width)
{
    m_barWidth = width;
    m_imageBg->setSize(m_barWidth,m_barHeight);
    m_imageBg->setBounds(0,0,m_barWidth,m_barHeight);
    m_imageFg->setSize(0,0);
    m_imageFg->setBounds(0,0,0,0);
    setBounds(m_imageBg->getBounds());
}

void VappShellMediaplayerProgressBar::setImage(VfxS32 bgImage,VfxS32 fgImage)
{
    //VfxRect size;    
    m_imageFg->setResId(fgImage);
    m_progressMinWidth = m_imageFg->getBounds().getWidth();
    
    m_imageFg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_imageBg->setResId(bgImage);
    m_imageBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
  
    m_barHeight = m_imageBg->getBounds().getHeight();
    m_progressHeight = m_imageFg->getBounds().getHeight();
}

VfxBool VappShellMediaplayerProgressBar::onPenInput(VfxPenEvent &event)
{
	VfxPoint p;
	p =	event.getRelPos(this);

    //VFX_TRACE("xxxxxxxxxxxxxxxxxxxxx x=%d, y= %d",p.x,p.y);

	VfxS32 ratio;
	if (p.x<0)
		p.x =0;
	
	ratio = ((p.x) * 100)/ m_barWidth;

    if (ratio>100)
        ratio=100;

	m_eventPenDown.emit(ratio);
    return VFX_TRUE;
}
/*****************************************************************************
 * Class VappShellMediaplayerMainScreen
 *****************************************************************************/
VappShellMediaplayerVolCtrlPopup::VappShellMediaplayerVolCtrlPopup(void):
m_progress(NULL),
m_volCtrlButton(NULL)
{

}

void VappShellMediaplayerVolCtrlPopup::onInit()
{
    Super::onInit();
    
    /* initilize cell */
    VfxImageSrc imgSrc(IMG_ID_SHELL_MEDIAPLAYER_VOL_BG);    
    setImgContent(imgSrc);
	//setOpacity(0.5);
    setAnchor(VfxFPoint(0.5, 0.5));
    setIsCached(VFX_TRUE);
    setBounds(0,0,VOLUME_POPUP_PANEL_WIDTH,VOLUME_POPUP_PANEL_HEIGHT);
    setRect(VfxRect(VOLUME_POPUP_PANEL_OFFSET_X, VOLUME_POPUP_PANEL_OFFSET_Y, VOLUME_POPUP_PANEL_WIDTH, VOLUME_POPUP_PANEL_HEIGHT));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);    

    VFX_OBJ_CREATE(m_progress, VappShellMediaplayerProgressBar, this);
    m_progress->setImage(IMG_ID_SHELL_MEDIAPLAYER_VOL_BAR01, IMG_ID_SHELL_MEDIAPLAYER_VOL_BAR02);
    m_progress->setBarWidth(VOLUME_BAR_WIDTH);
    m_progress->setPos(VfxPoint(VOLUME_BAR_OFFSET_X,VOLUME_BAR_OFFSET_Y ));

    m_volLevel = vadp_shell_mediaplayer_player_get_volume();
    m_ratio = m_volLevel*100/MDI_AUD_VOL_EX_MUTE_MAX;
    m_progress->setRatio(m_ratio);
    m_progress->m_eventPenDown.connect(this,&Self::onRatioChange);
    m_progress->setMinWidth(VOLUME_BAR_MINWDITH);

    VFX_OBJ_CREATE(m_volCtrlButton, VcpImageButton, this);
    VfxResId rId = 0;
    if (m_volLevel == 0)
    {
        rId = IMG_ID_SHELL_MEDIAPLAYER_VOLUME_MUTE;
        m_isMute = VFX_TRUE;
    }
    else
    {
        rId = IMG_ID_SHELL_MEDIAPLAYER_VOLUME;
        m_isMute = VFX_FALSE;
    }
    m_volCtrlButton->setImage(VcpStateImage(rId,0,0,0));
    m_volCtrlButton->m_signalClicked.connect(this, &Self::onButtonClick);
    m_volCtrlButton->setRect(VfxRect(VOLUME_ICON_OFFSET_X,VOLUME_ICON_OFFSET_Y,VOLUME_ICON_WIDTH,VOLUME_ICON_HEIGHT));

    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(5000);
    m_timer->m_signalTick.connect(this, &Self::onTimerExpired); 
    m_timer->start();
}

void VappShellMediaplayerVolCtrlPopup::onTimerExpired(VfxTimer *source)
{
    m_player->setFocused(VFX_TRUE);
    exit(VFX_TRUE);
}


void VappShellMediaplayerVolCtrlPopup::onRatioChange(VfxS32 ratio)
{
    VfxU8 newVol = (ratio*MDI_AUD_VOL_EX_MUTE_MAX)/100 +1;

    m_timer->stop();

    if (ratio <= 0)
    {
        newVol = 0;
        if (m_isMute == VFX_FALSE)
        {
            m_volCtrlButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_VOLUME_MUTE,0,0,0));
            m_isMute = VFX_TRUE;
        }      
    }
    else
    {
        if (newVol >MDI_AUD_VOL_EX_MUTE_MAX)
            newVol = MDI_AUD_VOL_EX_MUTE_MAX;

        if (m_isMute == VFX_TRUE)
        {
            m_volCtrlButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_VOLUME,0,0,0));
            m_isMute = VFX_FALSE;
        }                 
    }

    m_ratio = newVol*100/MDI_AUD_VOL_EX_MUTE_MAX;
    //kal_prompt_trace(MOD_VAPP,"xxxxxxxxxxxxxxxxxxxxxx volume level = (%d), ratio = (%d), line:%d\n", newVol,m_ratio,__LINE__);    
    //VFX_TRACE(("xxxxxxxxxxxxxxxxxxxxxx volume level = (%d), ratio = (%d), line:%d\n", newVol,m_ratio,__LINE__));    
    m_progress->setRatio(m_ratio);
    vadp_shell_mediaplayer_player_set_volume(newVol);
    m_volLevel = newVol;
    m_timer->setStartDelay(3000);
    m_timer->start();
}

void VappShellMediaplayerVolCtrlPopup::onButtonClick(VfxObject *sender, VfxId Id)
{
    if (sender == m_volCtrlButton)
    {
        m_timer->stop();
    
        if (m_isMute == VFX_TRUE)
        {            
            if(m_volLevel == 0)
                m_volLevel = 1;
            
            VfxS32 ratio = m_volLevel*100/MDI_AUD_VOL_EX_MUTE_MAX;
            m_volCtrlButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_VOLUME,0,0,0));
            m_progress->setRatio(ratio);
            vadp_shell_mediaplayer_player_set_volume(m_volLevel);
            m_isMute = VFX_FALSE;
        }
        else
        {
            m_isMute = VFX_TRUE;
            m_volCtrlButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_VOLUME_MUTE,0,0,0));
            m_progress->setRatio(0);
            vadp_shell_mediaplayer_player_set_volume(0);
        }
        m_timer->setStartDelay(3000);  
        m_timer->start();
    }
}


void VappShellMediaplayerVolCtrlPopup::onDeinit(void)
{
    VFX_OBJ_CLOSE(m_volCtrlButton);
    VFX_OBJ_CLOSE(m_progress);
    Super::onDeinit();
}

VfxBool VappShellMediaplayerVolCtrlPopup::onPenInput(VfxPenEvent &event)
{
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    return Super::onPenInput(event);
}

void VappShellMediaplayerVolCtrlPopup::setPlayer(VappShellMediaplayer* player)
{
    m_player = player;
}

void VappShellMediaplayerVolCtrlPopup::changeVolume(void)
{
    m_timer->stop(); 
    m_volLevel = vadp_shell_mediaplayer_player_get_volume();
    m_player->setVol(m_volLevel);
    kal_prompt_trace(MOD_VAPP,"[Baoqi] changeVolume m_volLevel = [%d], at line: [%d]", m_volLevel, __LINE__);    

    if (m_volLevel <= MDI_AUD_VOL_EX_MUTE_MAX && m_volLevel >= MDI_AUD_VOL_EX_MUTE_MIN)
    {
        m_ratio = m_volLevel*100/MDI_AUD_VOL_EX_MUTE_MAX;
        m_progress->setRatio(m_ratio);
        if (m_volLevel == MDI_AUD_VOL_EX_MUTE_MIN)
        {
            m_volCtrlButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_VOLUME_MUTE,0,0,0));
            m_isMute = VFX_TRUE;
        }
        else
        {
            m_volCtrlButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_VOLUME,0,0,0));
            m_isMute = VFX_FALSE;
        }
    }
    else
    {
        kal_prompt_trace(MOD_VAPP,"[Baoqi][Error] changeVolume m_volLevel = [%d], at line: [%d]", m_volLevel, __LINE__);    
    }
    m_timer->setStartDelay(3000);
    m_timer->start();
}

void VappShellMediaplayerVolCtrlPopup::increaseVolume(void)
{
    m_timer->stop(); 
    if (m_volLevel<=MDI_AUD_VOL_EX_MUTE_MAX)
    {
        if (m_isMute==VFX_TRUE)
        {
            m_volLevel=1;
            m_volCtrlButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_VOLUME,0,0,0));
            m_isMute = VFX_FALSE;
        }
        else if (m_volLevel < MDI_AUD_VOL_EX_MUTE_MAX)
        {
            m_volLevel++;
        }
        else
        {
            return;
        }
        m_ratio = m_volLevel*100/MDI_AUD_VOL_EX_MUTE_MAX;
        m_progress->setRatio(m_ratio);
        vadp_shell_mediaplayer_player_set_volume(m_volLevel);                
        m_player->setVol(m_volLevel);
    }
    m_timer->setStartDelay(3000);
    m_timer->start();
}

void VappShellMediaplayerVolCtrlPopup::decreaseVolume(void)
{
    m_timer->stop();
    if (m_volLevel>0 && m_isMute!=VFX_TRUE)
    {
        m_volLevel--;
        m_ratio = m_volLevel*100/MDI_AUD_VOL_EX_MUTE_MAX;
        m_progress->setRatio(m_ratio);
        vadp_shell_mediaplayer_player_set_volume(m_volLevel);
        m_player->setVol(m_volLevel);
        m_isMute = VFX_FALSE;
        if (m_volLevel == 0)
        {
            m_volCtrlButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_VOLUME_MUTE,0,0,0));
            m_isMute = VFX_TRUE;
        }
    }
    m_timer->setStartDelay(3000);
    m_timer->start();
}

VfxBool VappShellMediaplayerVolCtrlPopup::onKeyInput(VfxKeyEvent &event)
{
    switch( event.keyCode )
    {
        case VFX_KEY_CODE_VOL_UP:
        if (event.type != VFX_KEY_EVENT_TYPE_UP)
		{
             m_timer->stop(); 
            if (m_volLevel<=MDI_AUD_VOL_EX_MUTE_MAX)
            {
                if (m_isMute==VFX_TRUE)
                {
                    m_volLevel=1;
                    m_volCtrlButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_VOLUME,0,0,0));
                    m_isMute = VFX_FALSE;
                }
                else if (m_volLevel < MDI_AUD_VOL_EX_MUTE_MAX)
                {
                    m_volLevel++;
                }
                else
                {
                    break;
                }
                m_ratio = m_volLevel*100/MDI_AUD_VOL_EX_MUTE_MAX;
                m_progress->setRatio(m_ratio);
                vadp_shell_mediaplayer_player_set_volume(m_volLevel);                
                m_player->setVol(m_volLevel);
            }
		
		}
		else
		{
            return VFX_TRUE;
		}
            break;
    
        case VFX_KEY_CODE_VOL_DOWN:
        if (event.type != VFX_KEY_EVENT_TYPE_UP)
		{
            m_timer->stop();
            if (m_volLevel>0 && m_isMute!=VFX_TRUE)
            {
                m_volLevel--;
                m_ratio = m_volLevel*100/MDI_AUD_VOL_EX_MUTE_MAX;
                m_progress->setRatio(m_ratio);
                vadp_shell_mediaplayer_player_set_volume(m_volLevel);
                m_player->setVol(m_volLevel);
                m_isMute = VFX_FALSE;
                if (m_volLevel == 0)
                {
                    m_volCtrlButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_VOLUME_MUTE,0,0,0));
                    m_isMute = VFX_TRUE;
                }
            }
		}
		else
		{
            return VFX_TRUE;
		}
            break;
        case VFX_KEY_CODE_END:
            m_player->setFocused(VFX_TRUE);
            exit(VFX_TRUE);
            break;

		default:
			return Super::onKeyInput(event);
    }


    m_timer->setStartDelay(3000);
    m_timer->start();

    return VFX_TRUE;
}

void VappShellMediaplayerVolCtrlPopup::onPenInputOnOutside(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        // TODO: Chenage to leave(VFX_TRUE); later
        m_player->setFocused(VFX_TRUE);
        exit(VFX_TRUE);
        
        return;
    }
    Super::onPenInputOnOutside(event);
}


/*****************************************************************************
 * Class VappShellMediaplayerMainScreen
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappShellMediaplayerMainScreen", VappShellMediaplayerMainScreen, VfxControl);

VfxResId VappShellMediaplayerMainScreen::toolbarConfig[VAPP_SHELL_MP_TOOLBAR_TOTAL_ENUM][4] = VAPP_SHELL_MP_TOOLBAR_SETTING;

VappShellMediaplayerMainScreen::VappShellMediaplayerMainScreen(void) :
    m_toolbar(NULL),
    m_waitingIcon(NULL),
    m_timer(NULL),
    m_currTimeMsec(0),
    m_durationMsec(0)
{

}

VappShellMediaplayerMainScreen::~VappShellMediaplayerMainScreen()
{

}
void VappShellMediaplayerMainScreen::onExitView()
{
    /* reset album */
    m_activePhotoFrame->setResId(IMG_ID_SHELL_MEDIAPLAYER_ALBUM_NO_MUSIC);
    m_activePhotoFrame->setPos(VfxPoint(0,0));
}

void VappShellMediaplayerMainScreen::enableButton()
{
    m_toolbar->setButtonIsDisabled(BUTTON_BACKWARD, VFX_FALSE);
    m_toolbar->setButtonIsDisabled(BUTTON_FORWARD, VFX_FALSE);
    m_toolbar->setButtonIsDisabled(BUTTON_PLAY, VFX_FALSE);
}

void VappShellMediaplayerMainScreen::disableButton()
{
    m_toolbar->setButtonIsDisabled(BUTTON_BACKWARD, VFX_TRUE);
    m_toolbar->setButtonIsDisabled(BUTTON_FORWARD, VFX_TRUE);
    m_toolbar->setButtonIsDisabled(BUTTON_PLAY, VFX_TRUE);
}

void VappShellMediaplayerMainScreen::setPlayer(VappShellMediaplayer* player)
{
    m_player = player;
}

void VappShellMediaplayerMainScreen::prepare()
{
    if (m_player->state() == VappShellMediaplayer::STATE_PLAYING || m_player->state() == VappShellMediaplayer::STATE_TAPTOPLAY)
    {
        m_toolbar->setButtonImage(1,VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_PAUSE_NOR,IMG_ID_SHELL_MEDIAPLAYER_PAUSE_PRE,0,0));       

        if (m_player->state() == VappShellMediaplayer::STATE_TAPTOPLAY)
        {
            vadp_shell_mediaplayer_player_play();        
            m_player->setState(VappShellMediaplayer::STATE_PLAYING);            
        }

        if (m_timer!=NULL)
            m_timer->start();        

    }    
    else if (m_player->getSongCount()>0)
    {
        m_toolbar->setButtonImage(1,VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_PLAY_NOR,IMG_ID_SHELL_MEDIAPLAYER_PLAY_PRE,IMG_ID_SHELL_MEDIAPLAYER_PLAY_DIS,0));
    }

}

void VappShellMediaplayerMainScreen::unprepare()
{
    if (m_timer != NULL)
        m_timer->stop();

    if (m_player->state() == VappShellMediaplayer::STATE_IDLE && m_player->getSrvState() == VappShellMediaplayer::SRV_STATE_READY)
    {
        m_toolbar->setButtonImage(1,VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_PLAY_NOR,IMG_ID_SHELL_MEDIAPLAYER_PLAY_PRE,IMG_ID_SHELL_MEDIAPLAYER_PLAY_DIS,0));
    }
}

void VappShellMediaplayerMainScreen::onStatusChanged(VappShellMediaplayerStatusChangeEnum statusEnum)
{
    //VFX_TRACE("onStatusChange %d",resultP);
    updateMainScreenInfo();
    if (m_player->state() == VappShellMediaplayer::STATE_PLAYING)
    {
        m_toolbar->setButtonImage(1,VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_PAUSE_NOR,IMG_ID_SHELL_MEDIAPLAYER_PAUSE_PRE,0,0));       

        if (m_timer!=NULL)
            m_timer->start();        
    }
    else 
    {
        m_toolbar->setButtonImage(1,VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_PLAY_NOR,IMG_ID_SHELL_MEDIAPLAYER_PLAY_PRE,IMG_ID_SHELL_MEDIAPLAYER_PLAY_DIS,0));
    }

    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();

}
void VappShellMediaplayerMainScreen::setNeedToSwitch(VfxBool needToSwitch)
{
    m_needToSwitch = needToSwitch;
}


void VappShellMediaplayerMainScreen::onMediaChanged(void* resultP)
{
    //VFX_TRACE("onMediaChange %d",resultP);
    //VappShellMediaplayer::VappShellMediaplayerStateEnum preState = m_player->state();

    //m_player->setState(VappShellMediaplayer::STATE_MEDIACHANGE);
    m_needToSwitch = VFX_TRUE;
    updateMainScreenInfo();

    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
}

void VappShellMediaplayerMainScreen::onPlayEnd(void* resultP)
{
    //VFX_TRACE("VappShellMediaplayerMenu::onPlayEnd(%d)\n",resultP);
    // TODO: Update progress bar
    m_player->setLastIndex(m_player->index());
    
    m_currTimeMsec = m_durationMsec;
    updateProgressBar();
    
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
}

void VappShellMediaplayerMainScreen::onFinishSwitchView(VfxFrame * target,VfxBool isCompleted)
{
    if (m_player->state() == VappShellMediaplayer::STATE_PLAYING || m_player->state() == VappShellMediaplayer::STATE_TAPTOPLAY)
    {
        m_toolbar->setButtonImage(1,VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_PAUSE_NOR,IMG_ID_SHELL_MEDIAPLAYER_PAUSE_PRE,0,0));       

        if (m_player->state() == VappShellMediaplayer::STATE_TAPTOPLAY)
        {
            m_player->setState(VappShellMediaplayer::STATE_PLAYING);
            vadp_shell_mediaplayer_player_play();        
        }

        if (m_timer!=NULL)
            m_timer->start();        

    }    
    else
    {
        if(m_player->getSrvState()== VappShellMediaplayer::SRV_STATE_READY && m_player->getSongCount()>=1)
        {
            m_toolbar->setButtonImage(1,VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_PLAY_NOR,IMG_ID_SHELL_MEDIAPLAYER_PLAY_PRE,IMG_ID_SHELL_MEDIAPLAYER_PLAY_DIS,0));
        }
    }

}


void VappShellMediaplayerMainScreen::onListEnd(void* resultP)
{
    //VFX_TRACE("onListEnd %d",resultP);
    //updateMainScreenInfo();
    m_toolbar->setButtonImage(1,VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_PLAY_NOR,IMG_ID_SHELL_MEDIAPLAYER_PLAY_PRE,IMG_ID_SHELL_MEDIAPLAYER_PLAY_DIS,0));
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();
}


void VappShellMediaplayerMainScreen::getTimeString(VfxU64 msec, VfxWChar *timeStr,VfxU32 maxLength) const
{
    VfxS64 totol_secs = msec / 1000;
    VfxS32 hour;
    VfxS32 hour_remain;
    VfxS32 min;
    VfxS32 sec;

    #define STRING_LENGTH_MAX (10)
    VfxChar *temp;    
    VfxU32 wtemp_length;    
    VfxChar temp_string[STRING_LENGTH_MAX];
    VfxWChar temp_wstring[STRING_LENGTH_MAX];
    VfxChar seperator;

    seperator = ':';
   
    hour = totol_secs / 3600;
    hour_remain = totol_secs % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60; 

    temp = &temp_string[0];

    if(hour >= 100)
    {
        sprintf(temp, "99:59:59");
        *(temp + 8) = '\0';
    }
    else
    {
        if (hour > 0)
        {
            sprintf(temp, "%02d%c%02d%c%02d", hour, seperator, min, seperator, sec);
            *(temp + 8) = '\0';
        }
        else
        {
            sprintf(temp, "%02d%c%02d",  min, seperator, sec);
            *(temp + 5) = '\0';
        }
    }

    wtemp_length = vfx_sys_strlen(temp_string);
    VFX_ASSERT(wtemp_length<STRING_LENGTH_MAX);
    mmi_asc_n_to_ucs2((CHAR*)temp_wstring, (CHAR*)temp_string, wtemp_length + 1);

    if (maxLength < wtemp_length)
    {
        return;
    }

    vfx_sys_wcscpy(timeStr, temp_wstring);

}

void VappShellMediaplayerMainScreen::onInit(void)
{
    Super::onInit();

    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    setRect(0, 0, main_screen_size.width, main_screen_size.height);

    VfxImageFrame *bg;
    VFX_OBJ_CREATE(bg, VfxImageFrame, this);
    bg->setResId(VAPP_SHELL_IMG_SWITCH_BG);
    bg->setBgColor(VFX_COLOR_BLACK);
    bg->setIsOpaque(VFX_TRUE);

    m_needToSwitch = VFX_FALSE;

    // 1. Toolbar
    VFX_OBJ_CREATE(m_toolbar, VcpSegmentButton, this);
    m_toolbar->setAnchor(VfxFPoint(0.5f, 0.0f));
    m_toolbar->setPos(main_screen_size.width / 2, VAPP_SHELL_MP_TOOLBAR_Y_POSITION);
    m_toolbar->setSize(VAPP_SHELL_MP_TOOLBAR_BUTTON_WIDTH * VAPP_SHELL_MP_TOOLBAR_TOTAL_ENUM, VAPP_SHELL_MP_TOOLBAR_BUTTON_HEIGTH);
    m_toolbar->setBgColor(VRT_COLOR_TRANSPARENT);
    for(int i = 0; i < VAPP_SHELL_MP_TOOLBAR_TOTAL_ENUM ; i++)
    {
        m_toolbar->addButton(
            i,
            VcpStateImage(
                Self::toolbarConfig[i][0], Self::toolbarConfig[i][1],
                Self::toolbarConfig[i][2], Self::toolbarConfig[i][3]),
            VFX_WSTR(""));
    }

    m_toolbar->m_signalButtonClicked.connect(this, &Self::onButtonClick);

    // 2. Shuffle button
    VFX_OBJ_CREATE(m_shuffleButton, VcpImageButton, this);
    m_shuffleButton->setImage(
        VcpStateImage(
        IMG_ID_SHELL_MEDIAPLAYER_SHUFFLE_ON,
        0,
        IMG_ID_SHELL_MEDIAPLAYER_SHUFFLE_OFF,
        0)
    );
    m_shuffleButton->setId(BUTTON_SHUFFLE);
    m_shuffleButton->setRect(VfxRect(SHUFFLE_ICON_OFFSET_X,SHUFFLE_ICON_OFFSET_Y,ICON_WIDTH,ICON_HEIGHT));
    
    // 3. Repeat button 
    VFX_OBJ_CREATE(m_repeatButton, VcpImageButton, this);
    m_repeatButton->setImage(
        VcpStateImage(
        IMG_ID_SHELL_MEDIAPLAYER_REPONE_ON,
        0,
        IMG_ID_SHELL_MEDIAPLAYER_REPONE_OFF,
        0)
    );
    m_repeatButton->setId(BUTTON_REPEAT);
    m_repeatButton->setRect(VfxRect(REPEAT_ICON_OFFSET_X,REPEAT_ICON_OFFSET_Y,ICON_WIDTH,ICON_HEIGHT));


    // 4. Album icon
    VFX_OBJ_CREATE(m_albumIcon, VfxImageFrame, this);
    m_albumIcon->setPos(ALBUM_ICON_OFFSET_X,ALBUM_ICON_OFFSET_Y);
    m_albumIcon->setResId(IMG_ID_SHELL_MEDIAPLAYER_ALBUM_ICON);

    // 5. Artist icon
    VFX_OBJ_CREATE(m_artistIcon, VfxImageFrame, this);
    m_artistIcon->setPos(ARTIST_ICON_OFFSET_X,ARTIST_ICON_OFFSET_Y);
    m_artistIcon->setResId(IMG_ID_SHELL_MEDIAPLAYER_ARTIST_ICON);

    // 6. Song name
	VFX_OBJ_CREATE(m_songStr, VcpMarquee, this);
	m_songStr->setTextColor(VFX_COLOR_WHITE);
	m_songStr->setPos(SONG_NAME_OFFSET_X,SONG_NAME_OFFSET_Y);
    m_songStr->setBounds(0,0,SONG_NAME_WIDTH,SONG_NAME_HEIGHT+2);
    m_songStr->setHalign(VcpMarquee::HALIGN_CENTER);
    m_songStr->setValign(VcpMarquee::VALIGN_CENTER);
    m_songStr->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);
    m_songStr->setStartDelay(VcpMarquee::DEFAULT_START_DELAY);
    //m_songStr->setMovableFrame(VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_SONG3), VAPP_SHELL_MEDIAPLAYER_FONT_LARGE);//VCP_MARQUEE_DEFAULT_FONT);
    //m_songStr->startScroll();

    // 7. Current play time
    VFX_OBJ_CREATE(m_currPlaytimeStr, VfxTextFrame, this);    
    m_currPlaytimeStr->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_currPlaytimeStr->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_currPlaytimeStr->setColor(VFX_COLOR_WHITE);
    m_currPlaytimeStr->setFont(VAPP_SHELL_MEDIAPLAYER_FONT_SMALL);//VFX_FONT_DESC_SMALL);
    m_currPlaytimeStr->setPos(CURRENT_PLAY_TIME_OFFSET_X,CURRENT_PLAY_TIME_OFFSET_Y);
    m_currPlaytimeStr->setBounds(0,0,CURRENT_PLAY_TIME_WIDTH,CURRENT_PLAY_TIME_HEIGHT);

    VfxWChar str_buf[10];
    getTimeString(m_currTimeMsec,str_buf,10);
    m_currPlaytimeStr->setString(VFX_WSTR_MEM(str_buf));

    // 8. Total duration 
    VFX_OBJ_CREATE(m_totalPlaytimeStr, VfxTextFrame, this);    
    m_totalPlaytimeStr->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_totalPlaytimeStr->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_totalPlaytimeStr->setColor(VFX_COLOR_WHITE);
    m_totalPlaytimeStr->setFont(VAPP_SHELL_MEDIAPLAYER_FONT_SMALL);//VFX_FONT_DESC_SMALL);
    m_totalPlaytimeStr->setPos(TOTAL_DURATION_OFFSET_X,TOTAL_DURATION_OFFSET_Y);
    m_totalPlaytimeStr->setBounds(0,0,CURRENT_PLAY_TIME_WIDTH,CURRENT_PLAY_TIME_HEIGHT);

    getTimeString(m_durationMsec,str_buf,10);
    m_totalPlaytimeStr->setString(VFX_WSTR_MEM(str_buf));

    // 9. Artist name
    VFX_OBJ_CREATE(m_artistStr, VfxTextFrame, this);
    m_artistStr->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_artistStr->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_artistStr->setColor(VFX_COLOR_WHITE);
    m_artistStr->setFont(VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM);//VFX_FONT_DESC_SMALL);
    m_artistStr->setPos(ARTIST_NAME_OFFSET_X,ARTIST_NAME_OFFSET_Y);
    m_artistStr->setBounds(0,0,ARTIST_NAME_WIDTH,ARTIST_NAME_HEIGHT);
    //m_artistStr->setString(VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_SONG1));

    // 10. album name
    VFX_OBJ_CREATE(m_albumStr, VfxTextFrame, this);
    m_albumStr->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_albumStr->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_albumStr->setColor(VFX_COLOR_WHITE);
    m_albumStr->setFont(VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM);//VFX_FONT_DESC_SMALL);
    m_albumStr->setPos(ALBUM_NAME_OFFSET_X,ALBUM_NAME_OFFSET_Y);
    m_albumStr->setBounds(0,0,ALBUM_NAME_WIDTH,ALBUM_NAME_HEIGHT);
    //m_albumStr->setString(VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_SONG2));

    // 11. Album Cover button 
    VFX_OBJ_CREATE(m_albumCoverButton, VcpImageButton, this);
    m_albumCoverButton->setImage(
        VcpStateImage(
        IMG_ID_SHELL_MEDIAPLAYER_ALBUM_COVER,
        0,
        0,
        0)
    );
    m_albumCoverButton->m_signalClicked.connect(this, &Self::onButtonClick);
    m_albumCoverButton->setId(BUTTON_ALBUM);
    m_albumCoverButton->setRect(VfxRect(ALBUM_COVER_OFFSET_X,ALBUM_COVER_OFFSET_Y,ALBUM_COVER_WIDTH,ALBUM_COVER_HEIGHT));    
    
    // 12. Album Photo
    VFX_OBJ_CREATE(m_albumPagePanel, VcpPagePanel, m_albumCoverButton);
    VFX_OBJ_CREATE(m_albumPhoto, VfxImageFrame, m_albumPagePanel);
    VFX_OBJ_CREATE(m_albumPhoto2, VfxImageFrame, m_albumPagePanel);

#if !defined(__MMI_MAINLCD_240X320__)
    VFX_OBJ_CREATE(m_albumCover, VfxImageFrame, m_albumCoverButton);
    m_albumCover->setResId(IMG_ID_SHELL_MEDIAPLAYER_ALBUM_GLOSS);
    m_albumCover->setPos(VfxPoint(ALBUM_PHOTO_OFFSET_X-ALBUM_COVER_OFFSET_X,ALBUM_PHOTO_OFFSET_Y-ALBUM_COVER_OFFSET_Y));
#endif

    m_albumPhoto->setResId(IMG_ID_SHELL_MEDIAPLAYER_ALBUM_NO_MUSIC);
    m_albumPhoto->setPos(VfxPoint(ALBUM_PHOTO_OFFSET_X-ALBUM_COVER_OFFSET_X,ALBUM_PHOTO_OFFSET_Y-ALBUM_COVER_OFFSET_Y));
    m_albumPagePanel->setRect(m_albumPhoto->getRect());
    m_albumPhoto2->setRect(m_albumPhoto->getRect());
    m_albumPhoto->setPos(VfxPoint(0,0));
    m_albumPhoto2->setPos(VfxPoint(0,0));
    m_albumPagePanel->setCurrentFrame(m_albumPhoto);

    m_activePhotoFrame = m_albumPhoto;
    m_idlePhotoFrame = m_albumPhoto2;

    // 13. Volume control button 
    VFX_OBJ_CREATE(m_volumeCtrlButton, VcpImageButton, this);
    m_volumeCtrlButton->setImage(
        VcpStateImage(
        IMG_ID_SHELL_MEDIAPLAYER_VOLUME_NOR,
        IMG_ID_SHELL_MEDIAPLAYER_VOLUME_PRE,
        IMG_ID_SHELL_MEDIAPLAYER_VOLUME_DIS,
        0)
    );
    m_volumeCtrlButton->m_signalClicked.connect(this, &Self::onButtonClick);
    m_volumeCtrlButton->setRect(VfxRect(VOLUME_ICON_OFFSET_X,VOLUME_ICON_OFFSET_Y,ICON_WIDTH,ICON_HEIGHT));    
    m_volumeCtrlButton->setId(BUTTON_VOLUME_CTRL);

    /* 14. Progress bar */
    VFX_OBJ_CREATE(m_progress, VappShellMediaplayerProgressBar,this);
    m_progress->setImage(IMG_ID_SHELL_MEDIAPLAYER_PROGRESS_BAR_OFF, IMG_ID_SHELL_MEDIAPLAYER_PROGRESS_BAR_ON);
    m_progress->setBarWidth(PROGRESS_BAR_WIDTH);
    m_progress->setPos(VfxPoint(PROGRESS_BAR_OFFSET_X,PROGRESS_BAR_OFFSET_Y));
    m_progress->setRatio(0);
    m_progress->setMinWidth(PROGRESS_BAR_MINWDITH);
    

    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(500);
    m_timer->m_signalTick.connect(this, &Self::onTimerExpired); 

    VFX_OBJ_CREATE(m_waitingIcon, VcpWaitingIcon, this);
    m_waitingIcon->setAnchor(VfxFPoint(0.5f, 0.5f));
    m_waitingIcon->setPos(main_screen_size.width / 2 , main_screen_size.height/ 2);
    m_waitingIcon->setHiddenWhenStopped(VFX_TRUE);
    m_waitingIcon->start();

}

void VappShellMediaplayerMainScreen::setAlbumPhoto(VfxImageBuffer &imageBuf)
{
    if (m_needToSwitch==VFX_FALSE)
    {
        //m_activePhotoFrame->setPos(VfxPoint(ALBUM_PHOTO_OFFSET_X-ALBUM_COVER_OFFSET_X,ALBUM_PHOTO_OFFSET_Y-ALBUM_COVER_OFFSET_Y));
        m_activePhotoFrame->setPos(VfxPoint(0,0));
        m_activePhotoFrame->setImgContent(VfxImageSrc(imageBuf));
        m_activePhotoFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);        
        m_activePhotoFrame->setBounds(0,0,ALBUM_PHOTO_WIDTH,ALBUM_PHOTO_HEIGHT);
    }
    else
    {
        //m_idlePhotoFrame->setPos(VfxPoint(ALBUM_PHOTO_OFFSET_X-ALBUM_COVER_OFFSET_X,ALBUM_PHOTO_OFFSET_Y-ALBUM_COVER_OFFSET_Y));
        m_idlePhotoFrame->setPos(VfxPoint(0,0));
        m_idlePhotoFrame->setImgContent(VfxImageSrc(imageBuf));
        m_idlePhotoFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);        
        m_idlePhotoFrame->setBounds(0,0,ALBUM_PHOTO_WIDTH,ALBUM_PHOTO_HEIGHT);

        VcpPageEffectTypeDirection direction = VCP_PAGE_DIRECTION_FROM_LEFT;
        VfxImageFrame   *tempFrame;
        if (m_player->isNext())
        {
            direction = VCP_PAGE_DIRECTION_FROM_RIGHT;
        
        }
        m_albumPagePanel->switchTo(m_idlePhotoFrame, VCP_PAGE_EFFECT_PUSH, 500, direction, VFX_FALSE);

        tempFrame = m_activePhotoFrame;
        m_activePhotoFrame = m_idlePhotoFrame;
        m_idlePhotoFrame = tempFrame;
        
        m_needToSwitch = VFX_FALSE;
    }

}

void VappShellMediaplayerMainScreen::onDeinit(void)
{
    VFX_OBJ_CLOSE(m_toolbar);
    VFX_OBJ_CLOSE(m_shuffleButton); 
    VFX_OBJ_CLOSE(m_repeatButton); 
    VFX_OBJ_CLOSE(m_albumIcon);
    VFX_OBJ_CLOSE(m_artistIcon); 
    VFX_OBJ_CLOSE(m_songStr);
    VFX_OBJ_CLOSE(m_currPlaytimeStr);
    VFX_OBJ_CLOSE(m_totalPlaytimeStr);    
    VFX_OBJ_CLOSE(m_albumStr);
    VFX_OBJ_CLOSE(m_artistStr);
    VFX_OBJ_CLOSE(m_albumCoverButton);
    VFX_OBJ_CLOSE(m_progress);
    if (m_timer!=NULL)
        VFX_OBJ_CLOSE(m_timer);
    Super::onDeinit();

}

void VappShellMediaplayerMainScreen::updateProgressBar()
{
    VfxS32 ratio = 0;

    if (m_durationMsec == 0)
        ratio = 0;
	else
        ratio = m_currTimeMsec*100/m_durationMsec;

    m_progress->setRatio(ratio);

    VfxWChar str_buf[10];
    getTimeString(m_currTimeMsec,str_buf,10);
    m_currPlaytimeStr->setString(VFX_WSTR_MEM(str_buf));
    m_currPlaytimeStr->invalidate();

    getTimeString(m_durationMsec,str_buf,10);
    m_totalPlaytimeStr->setString(VFX_WSTR_MEM(str_buf));
    m_totalPlaytimeStr->invalidate();
}

void VappShellMediaplayerMainScreen::onTimerExpired(VfxTimer *source)
{
    // update progress bar
    vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_PLAYTIME,&m_currTimeMsec);
    vadp_shell_mediaplayer_player_get_info(VADP_SHELL_MEDIAPLAYER_PLAYER_INFO_DURATION,&m_durationMsec);

    if (m_currTimeMsec > m_durationMsec)
        m_durationMsec = m_currTimeMsec;

    m_player->setCurrPlayTime(m_currTimeMsec);
    m_player->setDuration(m_durationMsec);

    updateProgressBar();

    if (m_player->state() == VappShellMediaplayer::STATE_PLAYING)
    {
        m_timer->start();
    }    
}

void VappShellMediaplayerMainScreen::updateMainScreenSetting()
{
    
    if (m_player->isShuffle())
    {
        m_shuffleButton->setImage(
        VcpStateImage(
        IMG_ID_SHELL_MEDIAPLAYER_SHUFFLE_ON,
        0,
        0,
        0));
    }
    else
    {
        m_shuffleButton->setImage(
        VcpStateImage(
        IMG_ID_SHELL_MEDIAPLAYER_SHUFFLE_OFF,
        0,
        0,
        0));

    }
    m_shuffleButton->setId(BUTTON_SHUFFLE);
    m_shuffleButton->setRect(VfxRect(SHUFFLE_ICON_OFFSET_X,SHUFFLE_ICON_OFFSET_Y,23,23));

    switch(vadp_shell_mediaplayer_player_get_repeat_mode())
    {    
        case VADP_SHELL_MEDIAPLAYER_REPEAT_ALL:
            m_repeatButton->setImage(
                VcpStateImage(
                IMG_ID_SHELL_MEDIAPLAYER_REPALL_ON,
                0,
                0,
                0)
            );
            break;
        case VADP_SHELL_MEDIAPLAYER_REPEAT_ONE:
            m_repeatButton->setImage(
                VcpStateImage(
                IMG_ID_SHELL_MEDIAPLAYER_REPONE_ON,
                0,
                0,
                0)
            );
            break;
        case VADP_SHELL_MEDIAPLAYER_REPEAT_OFF:
        default:
            m_repeatButton->setImage(
                VcpStateImage(
                IMG_ID_SHELL_MEDIAPLAYER_REPALL_OFF,
                0,
                0,
                0)
            );
            break;            
    }
    m_repeatButton->setId(BUTTON_REPEAT);
    m_repeatButton->setRect(VfxRect(REPEAT_ICON_OFFSET_X,REPEAT_ICON_OFFSET_Y,23,23));

    if (m_player->getSongCount() > 0 && m_player->getSrvState()==VappShellMediaplayer::SRV_STATE_READY)
    {   
        m_shuffleButton->m_signalClicked.connect(this, &Self::onButtonClick);
        m_repeatButton->m_signalClicked.connect(this, &Self::onButtonClick);
    }
    else
    {
        m_repeatButton->setImage(
        VcpStateImage(
        IMG_ID_SHELL_MEDIAPLAYER_REPALL_OFF,
        0,
        0,
        0)
        );
        m_shuffleButton->setImage(
        VcpStateImage(
        IMG_ID_SHELL_MEDIAPLAYER_SHUFFLE_OFF,
        0,
        0,
        0));
    }

}

void VappShellMediaplayerMainScreen::setCurrPlaytimeMsec(VfxU64 time)
{
    m_currTimeMsec = time;    
}


void VappShellMediaplayerMainScreen::setDurationMsec(VfxU64 duration)
{
    m_durationMsec = duration;
}

void VappShellMediaplayerMainScreen::updateMainScreenInfo()
{
    VfxImageBuffer imageBuf;
    VfxU8 * tmpImageBuf;
    //VfxS32 tmpImageWidth;
    //VfxS32 tmpImageHeight;
    srv_plst_media_details_struct *details;


    if (m_player->getSongCount() > 0 && m_player->getSrvState()==VappShellMediaplayer::SRV_STATE_READY)
    {
        START_TIME();
        // set photo    
        m_waitingIcon->stop();
        vadp_shell_mediaplayer_get_cur_artwork((void**)&tmpImageBuf, ALBUM_PHOTO_WIDTH, ALBUM_PHOTO_HEIGHT);

        STOP_TIME("get_artwork_by_index() = %d MSec, line: %d");

        if (tmpImageBuf != NULL)
        {
            imageBuf.ptr = (VfxU8*)tmpImageBuf;
            imageBuf.pitchBytes = ALBUM_PHOTO_WIDTH * 2;
            imageBuf.width = ALBUM_PHOTO_WIDTH;
            imageBuf.height = ALBUM_PHOTO_HEIGHT;

            imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
            setAlbumPhoto(imageBuf);
        }
        else
        {
            if (m_needToSwitch==VFX_FALSE)
            {
                m_activePhotoFrame->setResId(IMG_ID_SHELL_MEDIAPLAYER_ALBUM_NO_MUSIC);
                //m_activePhotoFrame->setPos(VfxPoint(ALBUM_PHOTO_OFFSET_X-ALBUM_COVER_OFFSET_X,ALBUM_PHOTO_OFFSET_Y-ALBUM_COVER_OFFSET_Y));            
                m_activePhotoFrame->setPos(VfxPoint(0,0));            
            }
            else
            {
                m_idlePhotoFrame->setResId(IMG_ID_SHELL_MEDIAPLAYER_ALBUM_NO_MUSIC);
                //m_idlePhotoFrame->setPos(VfxPoint(ALBUM_PHOTO_OFFSET_X-ALBUM_COVER_OFFSET_X,ALBUM_PHOTO_OFFSET_Y-ALBUM_COVER_OFFSET_Y));            
                m_idlePhotoFrame->setPos(VfxPoint(0,0));
                VcpPageEffectTypeDirection direction = VCP_PAGE_DIRECTION_FROM_LEFT;
                VfxImageFrame   *tempFrame;
                if (m_player->isNext())
                {
                    direction = VCP_PAGE_DIRECTION_FROM_RIGHT;
                }
                m_player->setIsNext(VFX_TRUE);
                m_albumPagePanel->switchTo(m_idlePhotoFrame, VCP_PAGE_EFFECT_PUSH, 500, direction, VFX_FALSE);

                tempFrame = m_activePhotoFrame;
                m_activePhotoFrame = m_idlePhotoFrame;
                m_idlePhotoFrame = tempFrame;

                m_needToSwitch = VFX_FALSE;
            }
        }

        // init player 
        //if (m_player->state()==VappShellMediaplayer::STATE_IDLE)
        if (!vadp_shell_mediaplayer_is_list_ready())
            vadp_shell_mediaplayer_player_set_index(m_player->index());

        START_TIME();
        // Get details
        details = (srv_plst_media_details_struct *)mmi_frm_asm_alloc_anonymous_sw(sizeof(srv_plst_media_details_struct));
        //VFX_SYS_ALLOC_MEM(details, sizeof(srv_plst_media_details_struct));
        ASSERT(details!=NULL);
        memset(details,0x0, sizeof(srv_plst_media_details_struct));
        vadp_shell_mediaplayer_get_active_details(m_player->index(),details);
        STOP_TIME("get_active_details = %d MSec, line: %d");

        // Title
        m_songStr->setMovableFrame(VFX_WSTR_MEM((const U16*)details->title), VAPP_SHELL_MEDIAPLAYER_FONT_LARGE);
        m_songStr->startScroll();

        // Artist
        m_artistStr->setString(VFX_WSTR_MEM((const U16*)details->artist));
        m_artistStr->invalidate();
        
        // Album
        m_albumStr->setString(VFX_WSTR_MEM((const U16*)details->album));
        m_albumStr->invalidate();

        //VFX_SYS_FREE_MEM(details);
        mmi_frm_asm_free_anonymous(details);
        // TODO: It takes time to get duration.
        vadp_shell_mediaplayer_player_get_info(VADP_SHELL_MEDIAPLAYER_PLAYER_INFO_DURATION,&m_durationMsec);
        vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_PLAYTIME,&m_currTimeMsec);

        if (m_currTimeMsec > m_durationMsec)
            m_durationMsec = m_currTimeMsec;

        updateProgressBar();

        enableButton();

    }
    else
    {
        if( m_player->getSrvState()!= VappShellMediaplayer::SRV_STATE_IDLE)
        {
            m_waitingIcon->stop();

            m_songStr->setMovableFrame(VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_NO_MUSIC), VAPP_SHELL_MEDIAPLAYER_FONT_LARGE);//VCP_MARQUEE_DEFAULT_FONT);
            m_songStr->startScroll();
  
            m_activePhotoFrame->setResId(IMG_ID_SHELL_MEDIAPLAYER_ALBUM_NO_MUSIC);
            m_activePhotoFrame->setPos(VfxPoint(0,0));

            // Artist
            m_artistStr->setString(VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_UNKNOWN_INFO));
            m_artistStr->invalidate();

            // Album
            m_albumStr->setString(VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_UNKNOWN_INFO));
            m_albumStr->invalidate();

            if (m_player->isEnterView()==VFX_TRUE)
            {
                VFX_OBJ_CREATE(m_noPlaylistStr, VfxTextFrame, m_albumCoverButton);
                m_noPlaylistStr->setPos(ALBUM_STR_OFFSET_X-ALBUM_COVER_OFFSET_X ,ALBUM_STR_OFFSET_Y-ALBUM_COVER_OFFSET_Y);
                m_noPlaylistStr->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
                m_noPlaylistStr->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
                m_noPlaylistStr->setColor(VFX_COLOR_WHITE);

                #if defined(__MMI_MAINLCD_240X320__)
                m_noPlaylistStr->setFont(VfxFontDesc(128+10));
                #else
                m_noPlaylistStr->setFont(VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM);//VFX_FONT_DESC_SMALL);
                #endif
                m_noPlaylistStr->setBounds(0,0,ALBUM_STR_WIDTH,ALBUM_STR_HEIGHT);
                m_noPlaylistStr->setString(VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_TOUCH_TO_ADD));
                m_noPlaylistStr->bringToFront();
            }
        }
        disableButton();
    }
}


void VappShellMediaplayerMainScreen::showVolCtrlPopup()
{
    if (m_volCtrlPopup == NULL || !m_volCtrlPopup->isValid())
    {
    VFX_OBJ_CREATE(m_volCtrlPopup, VappShellMediaplayerVolCtrlPopup, findScreen());
    m_volCtrlPopup->setAutoDestory(VFX_TRUE);   
    m_volCtrlPopup->setPlayer(m_player);
    m_volCtrlPopup->show(VFX_TRUE);
    m_volCtrlPopup->setFocused(VFX_TRUE);
}
    else
    {
        kal_prompt_trace(MOD_VAPP,"[Baoqi] showVolCtrlPopup isValid = [%d] at line: [%d]", 0, __LINE__);    
    }
    return;
}

void VappShellMediaplayerMainScreen::hideWaitingIcon()
{
    m_waitingIcon->stop();
}

void VappShellMediaplayerMainScreen::displayWaitingIcon()
{
    m_waitingIcon->start();
}

void VappShellMediaplayerMainScreen::delayPlay(VfxTimer *source)
{      
    VFX_UNUSED(source);
    vadp_shell_mediaplayer_player_play();
}

void VappShellMediaplayerMainScreen::onButtonClick(VfxObject *sender, VfxId id)
{      
    if (m_player->isEnterView()==VFX_FALSE)
    {
        return;
    }

    VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_ONBUTTONCLICK,id,m_player->state());

    if (id == BUTTON_ALBUM)
    {
        m_signalSwitchButtonClicked.emit();
    }
    else if ( id == BUTTON_SHUFFLE )//sender == m_shuffleButton)
    {
        if (m_player->isShuffle())
        {
            m_shuffleButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_SHUFFLE_OFF));
            vadp_shell_mediaplayer_player_set_shuffle(VFX_FALSE);
            m_player->setShuffle(VFX_FALSE);
        }
        else
        {
            m_shuffleButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_SHUFFLE_ON));
            vadp_shell_mediaplayer_player_set_shuffle(VFX_TRUE);
            m_player->setShuffle(VFX_TRUE);
        }
    }
    else if ( id == BUTTON_REPEAT ) //sender == m_repeatButton)
    {
        vadp_shell_mediaplayer_repeat_mode_enum r = m_player->repeatMode();
        switch(r)
        {    
            case VADP_SHELL_MEDIAPLAYER_REPEAT_OFF:
                r = VADP_SHELL_MEDIAPLAYER_REPEAT_ALL;
                m_repeatButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_REPALL_ON));
                break;
            case VADP_SHELL_MEDIAPLAYER_REPEAT_ALL:
                r = VADP_SHELL_MEDIAPLAYER_REPEAT_ONE;
                m_repeatButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_REPONE_ON));
                break;
            case VADP_SHELL_MEDIAPLAYER_REPEAT_ONE:
                r = VADP_SHELL_MEDIAPLAYER_REPEAT_OFF;
                m_repeatButton->setImage(VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_REPALL_OFF));
                break;            
        }
        m_player->setRepeatMode(r);
        vadp_shell_mediaplayer_player_set_repeat_mode(r);
        m_repeatButton->invalidate();
    }    
    else if (id == BUTTON_PLAY) // play
    {
        if (m_player->state() == VappShellMediaplayer::STATE_IDLE)
        {
            m_timer->start();
            m_toolbar->setButtonImage(1,VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_PAUSE_NOR,IMG_ID_SHELL_MEDIAPLAYER_PAUSE_PRE,0,0));
            VfxWeakPtr<VappShellMediaplayerMainScreen> this_ptr = this;
            m_player->setState(VappShellMediaplayer::STATE_PLAYING);
            vadp_shell_mediaplayer_player_play();
            if (this_ptr == NULL)
                return;
        }
        else
        {
            m_timer->stop();
            m_toolbar->setButtonImage(1,VcpStateImage(IMG_ID_SHELL_MEDIAPLAYER_PLAY_NOR,IMG_ID_SHELL_MEDIAPLAYER_PLAY_PRE,IMG_ID_SHELL_MEDIAPLAYER_PLAY_DIS,0));
            m_player->setState(VappShellMediaplayer::STATE_TAPTOSTOP);
            VfxWeakPtr<VappShellMediaplayerMainScreen> this_ptr = this;
            m_player->setState(VappShellMediaplayer::STATE_IDLE);
            vadp_shell_mediaplayer_player_pause();
            if (this_ptr == NULL)
                return;           
        }

    }
    else if (id == BUTTON_BACKWARD) // backward
    {
        m_player->setIsNext(VFX_FALSE);
        kal_wap_trace(MOD_VAPP,TRACE_GROUP_2,"[SHELL][MEDPLY]onButtonClick: state=[%d], line=[%d]", m_player->state(),__LINE__);\
        if (m_player->state() == VappShellMediaplayer::STATE_IDLE)
        {
            // Change to previous song
            VfxWeakPtr<VappShellMediaplayerMainScreen> this_ptr = this;
            vadp_shell_mediaplayer_cache_set_index(m_player->prev());
            if (this_ptr == NULL)
                return;           
        }
        else //if (m_player->state() == VappShellMediaplayer::STATE_PLAYING)
        {
            // stop
            VfxWeakPtr<VappShellMediaplayerMainScreen> this_ptr = this;
            vadp_shell_mediaplayer_player_pause();
            if (this_ptr == NULL)
                return;           

            vadp_shell_mediaplayer_cache_set_index(m_player->prev());
            if (this_ptr == NULL)
                return;

            VfxTimer *player_timer;
            VFX_OBJ_CREATE(player_timer, VfxTimer, this);
            player_timer->setStartDelay(0);
            player_timer->m_signalTick.connect(this,&VappShellMediaplayerMainScreen::delayPlay);
            player_timer->start();
        }
        //else
        //{
        //    ASSERT(0);
        //}
        

    }
    else if (id == BUTTON_FORWARD) // forward 
    {
        m_player->setIsNext(VFX_TRUE);
        kal_wap_trace(MOD_VAPP,TRACE_GROUP_2,"[SHELL][MEDPLY]onButtonClick: state=[%d], line=[%d]", m_player->state(),__LINE__);\
        if (m_player->state() == VappShellMediaplayer::STATE_IDLE)
        {
            // Change to previous song
            VfxWeakPtr <VappShellMediaplayerMainScreen>this_ptr = this;            
            vadp_shell_mediaplayer_cache_set_index(m_player->next());
            if (this_ptr == NULL)
                return;
        }
        else //if (m_player->state() == VappShellMediaplayer::STATE_PLAYING)
        {
            VfxWeakPtr<VappShellMediaplayerMainScreen> this_ptr = this;

            vadp_shell_mediaplayer_player_pause();
            if (this_ptr == NULL)
                return;           
            vadp_shell_mediaplayer_cache_set_index(m_player->next());
            if (this_ptr == NULL)
                return;

            VfxTimer *player_timer;
            VFX_OBJ_CREATE(player_timer, VfxTimer, this);
            player_timer->setStartDelay(0);
            player_timer->m_signalTick.connect(this,&VappShellMediaplayerMainScreen::delayPlay);
            player_timer->start();
        }
        //else
        //{
        //    ASSERT(0);
        //}
    }
    else if (id == BUTTON_VOLUME_CTRL)
    {
        VFX_OBJ_CREATE(m_volCtrlPopup, VappShellMediaplayerVolCtrlPopup, findScreen());
        m_volCtrlPopup->setAutoDestory(VFX_TRUE);   
        m_volCtrlPopup->setPlayer(m_player);
        m_volCtrlPopup->show(VFX_TRUE);
        m_volCtrlPopup->setFocused(VFX_TRUE);
    }
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}


/***************************************************************************** 
 * VappShellMediaplayerCell Implementation
 *****************************************************************************/
VappShellMediaplayerCell::VappShellMediaplayerCell(VfxS32 index) : 
    m_index(index), 
    m_bgImage(NULL),
    m_playingIcon(NULL),
    m_albumPhoto(NULL),
    m_songName(NULL),
    m_artistName(NULL),
    m_isHighlight(VFX_FALSE),
    m_currTimeMsec(0),
    m_durationMsec(0),
    m_state(STATE_IDLE)
{
    //VFX_TRACE(("[SHELL MEDIAPLAYER CELL] Constructor(%d,%d)\n", m_index, m_state));        

    m_durationToDisplay = VFX_WSTR_EMPTY;
}


VappShellMediaplayerCell::~VappShellMediaplayerCell()
{
    //VFX_TRACE(("[SHELL MEDIAPLAYER CELL] ~Constructor(%d,%d)\n", m_index, m_state));        
}


void VappShellMediaplayerCell::onInit()
{
    VfxControl::onInit();

    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_CELL_ONINIT,m_index, m_state);

    VFX_OBJ_CREATE(m_bgImage, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_albumPhoto, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_songName, VcpMarquee, this);
    VFX_OBJ_CREATE(m_progress, VappShellMediaplayerProgressBar,this);
    VFX_OBJ_CREATE(m_artistName, VfxTextFrame, this);
    
    VfxImageSrc imgSrc(IMG_ID_SHELL_MEDIAPLAYER_CELL_BG);
    
    /* initilize cell */
    setImgContent(imgSrc);
    setOpacity(1);
    setAnchor(VfxFPoint(0.5, 0.5));
    setIsCached(VFX_TRUE);
#if defined(__SHELL_MEDIAPLAYER_SUPER_SLIM__)
    setIsOpaque(VFX_TRUE);
#endif    
    setRect(VfxRect(0, 0, CELL_ITEM_WIDTH, CELL_ITEM_HEIGHT));

    /* artist name */
    m_artistName->setPos(VfxPoint(CELL_ARTIST_NAME_OFFSET_X,CELL_ARTIST_NAME_OFFSET_Y));
    m_artistName->setBounds(VfxRect(0,0,CELL_ARTIST_NAME_WIDTH,CELL_ARTIST_NAME_HEIGHT));
    m_artistName->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_artistName->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_artistName->setColor(VFX_COLOR_WHITE);
    m_artistName->setFont(VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM_CELL);    

    /* album photo */
    m_albumPhoto->setResId(IMG_ID_SHELL_MEDIAPLAYER_CELL_NO_IMAGE);
    m_albumPhoto->setPos(VfxPoint(CELL_ALBUM_OFFSET_X,CELL_ALBUM_OFFSET_Y));
    m_albumPhoto->setBorderColor(VFX_COLOR_WHITE);


    /* progress bar */
    m_progress->setImage(IMG_ID_SHELL_MEDIAPLAYER_PROGRESS_BAR_OFF, IMG_ID_SHELL_MEDIAPLAYER_PROGRESS_BAR_ON);
    m_progress->setBarWidth(CELL_PROGRESS_BAR_WIDTH);
    m_progress->setPos(VfxPoint(CELL_PROGRESS_BAR_OFFSET_X,CELL_PROGRESS_BAR_OFFSET_Y));
    m_progress->setMinWidth(CELL_PROGRESS_BAR_MINWDITH);

    /* song name */
    m_songName->setPos(VfxPoint(CELL_SONG_NAME_OFFSET_X, CELL_SONG_NAME_OFFSET_Y));
    m_songName->setBounds(VfxRect(0, 0, CELL_SONG_NAME_WIDTH, CELL_SONG_NAME_HEIGHT+2));
    m_songName->setHalign(VcpMarquee::HALIGN_NATURAL);
    m_songName->setValign(VcpMarquee::VALIGN_CENTER);
    m_songName->setSpeed(VcpMarquee::DEFAULT_SPEED / 3);
    m_songName->setStartDelay(VcpMarquee::DEFAULT_START_DELAY);
    m_songName->setTextColor(VFX_COLOR_YELLOW);
    //m_songName->setMovableFrame(VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_MUSIC), VCP_MARQUEE_DEFAULT_FONT);
    //m_songName->startScroll();
 
    // duration string
    VFX_OBJ_CREATE(m_durationStr,VfxTextFrame, this);
    m_durationStr->setPos(VfxPoint(CELL_DURATION_OFFSET_X,CELL_DURATION_OFFSET_Y));
    m_durationStr->setBounds(VfxRect(0,0,CELL_DURATION_WIDTH,CELL_DURATION_HEIGHT));
    m_durationStr->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_durationStr->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_durationStr->setColor(VFX_COLOR_WHITE);
    m_durationStr->setFont(VAPP_SHELL_MEDIAPLAYER_FONT_MEDIUM_CELL);


}

void VappShellMediaplayerCell::onDeinit()
{
    VFX_OBJ_CLOSE(m_bgImage);
    VFX_OBJ_CLOSE(m_playingIcon);
    VFX_OBJ_CLOSE(m_albumPhoto);
    VFX_OBJ_CLOSE(m_songName);
    VFX_OBJ_CLOSE(m_progress);

    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_CELL_ONDEINIT,m_index, m_state);

    m_state = STATE_IDLE;

    VfxControl::onDeinit();
}

void VappShellMediaplayerCell::setPlaying(VfxBool isPlaying)
{
    if (isPlaying == VFX_TRUE)
    {
        if (m_playingIcon == NULL)
        {
            /* playing icon */
            VFX_OBJ_CREATE(m_playingIcon, VfxImageFrame, this);
            m_playingIcon->setResId(IMG_ID_SHELL_MEDIAPLAYER_CELL_PLAY_ICON);
            m_playingIcon->setPos(VfxPoint(CELL_PLAYING_ICON_OFFSET_X,CELL_PLAYING_ICON_OFFSET_Y));
        }
        else
        {
            m_playingIcon->setHidden(VFX_FALSE);
        }
    }
    else
    {
        if (m_playingIcon != NULL)
        {
            VFX_OBJ_CLOSE(m_playingIcon);
            m_playingIcon = NULL;
        }
    }
}


void VappShellMediaplayerCell::onHightLight()
{
    m_isHighlight = VFX_TRUE;
    setAutoAnimate(VFX_TRUE);
    bringToFront();
    //m_playingIcon->setHidden(VFX_FALSE);
    m_songName->startScroll();  

    // TODO: Remove the black mask
}


void VappShellMediaplayerCell::onDeHightLight()
{
    m_isHighlight = VFX_FALSE;
    setAutoAnimate(VFX_FALSE);
    //m_playingIcon->setHidden(VFX_TRUE);
    m_songName->stopScroll();      
    // TODO: Add the black mask
}

void VappShellMediaplayerCell::setCurrPlaytimeMsec(VfxU64 time)
{
    if (time != m_currTimeMsec)
        is_time_dirty = VFX_TRUE;
    
    m_currTimeMsec = time;    
}

VfxU64 VappShellMediaplayerCell::getDurationMsec()
{
    return m_durationMsec;
}

void VappShellMediaplayerCell::setDurationMsec(VfxU64 duration)
{
    if (duration != m_durationMsec)
        is_time_dirty = VFX_TRUE;
    
    m_durationMsec = duration;
}

void VappShellMediaplayerCell::getTimeString(VfxU64 msec, VfxWChar *timeStr,VfxU32 maxLength) const
{
    VfxS64 totol_secs = msec / 1000;
    VfxS32 hour;
    VfxS32 hour_remain;
    VfxS32 min;
    VfxS32 sec;

    #define STRING_LENGTH_MAX (10)
    VfxChar *temp;    
    VfxU32 wtemp_length;    
    VfxChar temp_string[STRING_LENGTH_MAX];
    VfxWChar temp_wstring[STRING_LENGTH_MAX];
    VfxChar seperator;

    seperator = ':';
   
    hour = totol_secs / 3600;
    hour_remain = totol_secs % 3600;
    min = hour_remain / 60;
    sec = hour_remain % 60; 

    temp = &temp_string[0];

    if(hour >= 100)
    {
        sprintf(temp, "99:59:59");
        *(temp + 8) = '\0';    
    }
    else
    {
        if (hour > 0)
        {
            sprintf(temp, "%02d%c%02d%c%02d", hour, seperator, min, seperator, sec);
            *(temp + 8) = '\0';        
        }
        else
        {
            sprintf(temp, "%02d%c%02d",  min, seperator, sec);
            *(temp + 5) = '\0';
        }
    }

    wtemp_length = vfx_sys_strlen(temp_string);
    VFX_ASSERT(wtemp_length<STRING_LENGTH_MAX);
    mmi_asc_n_to_ucs2((CHAR*)temp_wstring, (CHAR*)temp_string, wtemp_length + 1);

    if (maxLength < wtemp_length)
    {
        return;
    }

    vfx_sys_wcscpy(timeStr, temp_wstring);

}

void VappShellMediaplayerCell::updateTitle(VfxWString title)
{
    m_songName->setMovableFrame(title, VAPP_SHELL_MEDIAPLAYER_FONT_LARGE_CELL);
}

void VappShellMediaplayerCell::updateArtist(VfxWString title)
{
    m_artistName->setString(title);
}


void VappShellMediaplayerCell::updateProgressBar()
{
    VfxS32 ratio = 0;
    if (m_durationMsec==0)
        ratio = 0;
    else
        ratio = m_currTimeMsec*100/m_durationMsec;
    m_progress->setRatio(ratio);
}
void VappShellMediaplayerCell::hideTime()
{
    m_durationStr->setHidden(TRUE);
    m_progress->setRatio(0);
}

void VappShellMediaplayerCell::updateTime()
{
    m_durationStr->setHidden(FALSE);
    
    if (is_time_dirty)
    {
        VfxWChar str_buf[30];
        VfxWChar str_buf2[10];

//        if (m_currTimeMsec == 0)
//        {
//            getTimeString(m_durationMsec,str_buf2,10);
//            m_durationStr->setString(VFX_WSTR_MEM(str_buf2));
//        }
//        else
        {
            // prepare currplay str
            getTimeString(m_currTimeMsec,str_buf,10);

            // append " / "
            mmi_wcsncat(str_buf,(const WCHAR*)L" / ",3);

            // append duration str
            getTimeString(m_durationMsec,str_buf2,10);

            mmi_wcsncat(str_buf,str_buf2,10);
            
            m_durationStr->setString(VFX_WSTR_MEM(str_buf));
        }
    }
}

VfxS32 VappShellMediaplayerCell::state()
{
    return m_state;
}

VfxImageSrcTypeEnum VappShellMediaplayerCell::getImageType()
{
    return m_albumPhoto->getImgContent().getType();
}

VfxS32 VappShellMediaplayerCell::index()
{
    return m_index;
}


void VappShellMediaplayerCell::useDefaultImage()
{
    m_state = STATE_IMAGE;

    //VFX_TRACE(("[SHELL MEDIAPLAYER CELL], useDefaultImage(%d,%d)\n", m_index, m_state));        
}

VfxU8 *VappShellMediaplayerCell::getImageBuffer()
{
    return m_imageBuf;
}


void VappShellMediaplayerCell::setImageBuffer(VfxU8 *buf_ptr, VfxS32 width, VfxS32 height)
{
    VfxImageBuffer imageBuf;

    m_state = STATE_IMAGE;

    //VFX_TRACE(("[SHELL MEDIAPLAYER CELL], setImageBuffer(%d,%d)\n", m_index, m_state));        

    m_imageBuf = buf_ptr;
    imageBuf.ptr = (VfxU8*)m_imageBuf;
    imageBuf.pitchBytes = width * 2;
    imageBuf.width = width;
    imageBuf.height = height;
    imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;
        
    setAutoAnimate(VFX_FALSE);
    m_albumPhoto->setPos(VfxPoint(CELL_ALBUM_OFFSET_X,CELL_ALBUM_OFFSET_Y));
    m_albumPhoto->setBounds(0,0,CELL_ALBUM_WIDTH,CELL_ALBUM_HEIGHT);
    m_albumPhoto->setImgContent(VfxImageSrc(imageBuf));
    m_albumPhoto->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);       
    m_albumPhoto->setBorderWidth(1);
}

/***************************************************************************** 
 * VappShellMediaplayerMenuFrame Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappShellMediaplayerMenuFrame", VappShellMediaplayerMenuFrame, VfxFrame);

VappShellMediaplayerMenuFrame::VappShellMediaplayerMenuFrame(void):
    m_menu(NULL),
    m_cmdTitle(NULL),
    m_player(NULL),
    m_tapStr(NULL)
{

}


void VappShellMediaplayerMenuFrame::onInit()
{
    Super::onInit();  
    
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    // back group image
    VfxImageFrame *bg;
    VFX_OBJ_CREATE(bg, VfxImageFrame, this);
    bg->setResId(VAPP_SHELL_IMG_SWITCH_BG);
    bg->setBgColor(VFX_COLOR_BLACK);
    bg->setIsOpaque(VFX_TRUE);
    bg->sendToBack();

    // CommandTitle
    VFX_OBJ_CREATE(m_cmdTitle, VcpCommandTitle, this);    
    m_cmdTitle->setSize(main_screen_size.width, 46);
    m_cmdTitle->setAnchor(VfxFPoint(0.0, 0.0));
    m_cmdTitle->setPos(VfxPoint(0, 18));
    m_cmdTitle->setText(VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_MUSIC));
    m_cmdTitle->setAutoAnimate(VFX_TRUE);

    m_cmdTitle->setAddOnTextButton(0, VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_LIBRARY), 0, VcpCommandTitleButtonCB(this, &Self::onBackButtonClick));
    m_cmdTitle->setAddOnImageButton(
    1,
    VcpStateImage(
        VAPP_SHELL_IMG_BK_NORMAL,
        VAPP_SHELL_IMG_BK_PRESS,
        VAPP_SHELL_IMG_BK_DISABLE,
        0),
    1,
    VcpCommandTitleButtonCB(this, &Self::onBackButtonClick));

    // WheelMenu
    VFX_OBJ_CREATE(m_menu, VappShellMediaplayerMenu, this);
    m_menu->setRect(0, 0, main_screen_size.width, main_screen_size.height);
    m_menu->setBgColor(VRT_COLOR_TRANSPARENT);
    m_menu->setFocused(VFX_TRUE);

    m_cmdTitle->bringToFront();

}

void VappShellMediaplayerMenuFrame::onDeinit()
{
    VFX_OBJ_CLOSE(m_cmdTitle);
    VFX_OBJ_CLOSE(m_menu);

    Super::onDeinit();  
}

void VappShellMediaplayerMenuFrame::setPlayer(VappShellMediaplayer* player)
{
    m_player = player;
    m_menu->setPlayer(player);
}

void VappShellMediaplayerMenuFrame::showString(VfxS32 active_song_count)
{
    if (m_tapStr == NULL)
    {
        VFX_OBJ_CREATE(m_tapStr,VfxTextFrame,this);
        m_tapStr->setPos(STRING_OFFSET_X,STRING_OFFSET_Y);
        m_tapStr->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_tapStr->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_tapStr->setColor(VFX_COLOR_WHITE);
        m_tapStr->setFont(VfxFontDesc(128+STRING_HEIGHT));//VFX_FONT_DESC_SMALL);
        m_tapStr->setBounds(0,0,STRING_WIDTH,STRING_HEIGHT);
        m_tapStr->setLineMode(VfxTextFrame::LINE_MODE_MULTI); 
        m_tapStr->setMaxLines(3);
        if(active_song_count > 0)
        {
            m_tapStr->setString(VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_BD_ERROR));
        }
        else
        {
            m_tapStr->setString(VFX_WSTR_RES(STR_ID_SHELL_MEDIAPLAYER_TOUCH_LIBRARY_TO_SELECT_PLST));
        }
        m_tapStr->bringToFront();        
    }
}


void VappShellMediaplayerMenuFrame::onBackButtonClick(VfxObject* sender, VfxId id)
{
    if (m_player->isEnterView()==VFX_FALSE)
    {
        return;
    }

    if (id == 0 /* Library */)
    {
        m_player->setViewMode(VappShellMediaplayer::MAIN_SCREEN_VIEW);
        vadp_shell_mediaplayer_entry_library(VappShellMediaplayer::onListChange, (void*)m_player);
    }
    else if (id == 1)
    {
        //m_player->setIndex(m_backupIndex);
        m_signalSwitchButtonClicked.emit();
    }
}


/***************************************************************************** 
 * VappShellMediaplayerMenu Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappShellMediaplayerMenu", VappShellMediaplayerMenu, VcpWheelMenu);

VappShellMediaplayerMenu::VappShellMediaplayerMenu():
    m_player(NULL),
    m_timer(NULL),
    m_updateTimer(NULL)
{

}

    

void VappShellMediaplayerMenu::onInit()
{
    VcpWheelMenu::onInit();
    m_behindCount = CELL_ITEM_BEHIND_COUNT;
    m_aheadCount = CELL_ITEM_AHEAD_COUNT;
    setIsZSortChild(VFX_TRUE);

    m_isDragging = VFX_FALSE;
    m_isDecoding = VFX_FALSE;
   
    VFX_OBJ_CREATE(m_timer, VfxTimer, this);
    m_timer->setStartDelay(100);
    m_timer->setDuration(100);
    m_timer->m_signalTick.connect(this, &VappShellMediaplayerMenu::onTimerTick);

    VFX_OBJ_CREATE(m_updateTimer, VfxTimer, this);
      
    m_updateTimer->setStartDelay(500);
    m_updateTimer->m_signalTick.connect(this, &Self::onUpdateTimerExpired);

}


void VappShellMediaplayerMenu::onUpdateTimerExpired(VfxTimer *source)
{
    VappShellMediaplayerCell* cell;

    if (m_player->state()==VappShellMediaplayer::STATE_PLAYING && m_player->getViewMode()==VappShellMediaplayer::LIST_MENU_VIEW)
    {
        VfxU64 currTimeMsec;
        VfxU64 durationMsec;
        cell = (VappShellMediaplayerCell*)getCellIfPresent(m_player->index(), 0);
        if (cell)
        {
            vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_PLAYTIME,&currTimeMsec);
            vadp_shell_mediaplayer_player_get_info(VADP_SHELL_MEDIAPLAYER_PLAYER_INFO_DURATION,&durationMsec);

            if (currTimeMsec > durationMsec)
                durationMsec = currTimeMsec;
            
            cell->setCurrPlaytimeMsec(currTimeMsec);
            cell->setDurationMsec(durationMsec);
            cell->updateTime();
            cell->updateProgressBar();
            m_updateTimer->start();
        }
    }
}

void VappShellMediaplayerMenu::onTimerTick(VfxTimer *source)
{
    VFX_UNUSED(source);

    m_timer->stop();
    if (!m_isDragging && m_player->isEnterView()==VFX_TRUE)
    {
        VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_CALL_UPDATECELLIMAGE, __LINE__);
        updateCellImage();
    }
}

void VappShellMediaplayerMenu::prepare()
{
    /* Set wheelmenu */
    m_isDecoding = VFX_FALSE;
    setCount(m_player->getSongCountMenu());
    setFocus(m_player->index(),0);

    VappShellMediaplayerCell* cell;          
    cell = (VappShellMediaplayerCell*) getCellIfPresent(m_player->index());
    VfxU64 currTimeMsec;
    VfxU64 durationMsec;

    if (cell)
    {
        vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_PLAYTIME,&currTimeMsec);
        vadp_shell_mediaplayer_player_get_info(VADP_SHELL_MEDIAPLAYER_PLAYER_INFO_DURATION,&durationMsec);

        if (currTimeMsec > durationMsec)
            durationMsec = currTimeMsec;

        cell->setCurrPlaytimeMsec(currTimeMsec);
        cell->setDurationMsec(durationMsec);
        cell->updateTime();
        cell->updateProgressBar();
    }    
    updateCellImage();
}

void VappShellMediaplayerMenu::unprepare()
{
    if (m_updateTimer!=NULL)
    {
        m_updateTimer->stop();
    }
}


void VappShellMediaplayerMenu::onStartPlaying()
{
    VappShellMediaplayerCell* cell;  
    m_updateTimer->start();
    cell = (VappShellMediaplayerCell*)getCellIfPresent(m_player->index(), 0);

    if (cell)
    {
        cell->setPlaying(VFX_TRUE);
    }

}


void VappShellMediaplayerMenu::onStopPlaying()
{
    VappShellMediaplayerCell* cell;  
    cell = (VappShellMediaplayerCell*)getCellIfPresent(m_player->index(), 0);
    m_updateTimer->stop();
    if (cell)
    {
        cell->setPlaying(VFX_FALSE);
    }
}


void VappShellMediaplayerMenu::onDeinit()
{
    // TODO: De-initial the data base
    VFX_OBJ_CLOSE(m_timer);
    VcpWheelMenu::onDeinit();   
}


void VappShellMediaplayerMenu::setPlayer(VappShellMediaplayer* player)
{
    m_player = player;
}


void VappShellMediaplayerMenu::onStatusChanged(VappShellMediaplayerStatusChangeEnum statusEnum)
{
    //VFX_TRACE("onStatusChange %d",resultP);
    if (statusEnum == VAPP_SHELL_MEDIPALAYER_STATU_IDLE_TO_PLAY)
    {
        onStartPlaying();
    }
}

void VappShellMediaplayerMenu::onMediaChanged(void* resultP)
{
    //VFX_TRACE("onMediaChange %d",resultP);

    VappShellMediaplayerCell* cell;  
    m_lastIndex = m_player->getLastIndex();
    cell = (VappShellMediaplayerCell*)getCellIfPresent(m_lastIndex, 0);
    if (cell!=NULL)
    {
        cell->hideTime();
    }

    if (getFocus()==m_lastIndex)
    {
        VfxS32 index = m_player->index();
        VfxU32 diff = 0;
    
        if(index >= m_lastIndex)
        {
            diff = index - m_lastIndex;
        }
        else
        {
            diff = m_lastIndex - index;
        }

        if(diff > 5)
        {
            setFocus(m_player->index(),0);
        }
        else
        {
            setFocus(m_player->index());
        }
    }
    else
    {
        //update wheel menu
        update();
    }
}

void VappShellMediaplayerMenu::onPlayEnd(void* resultP)
{
    //VFX_TRACE("VappShellMediaplayerMenu::onPlayEnd(%d)\n",resultP);
    // TODO: Update progress bar    

    VappShellMediaplayerCell* cell;  
    m_lastIndex = m_player->index();
    m_player->setLastIndex(m_lastIndex);
    cell = (VappShellMediaplayerCell*)getCellIfPresent(m_lastIndex, 0);

    if (cell!=NULL)
    {
        cell->setCurrPlaytimeMsec(cell->getDurationMsec());
        cell->updateTime();
        cell->updateProgressBar();
        //cell->onDeHightLight();

        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        renderer->mustShowNextFrame();
    }
    
}

void VappShellMediaplayerMenu::onFinishSwitchView(VfxFrame * target,VfxBool isCompleted)
{
    if (m_player->state()==VappShellMediaplayer::STATE_PLAYING && m_updateTimer!=NULL)
    {
        m_updateTimer->start();
    }

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
#endif    
    updateCellImage();
}


void VappShellMediaplayerMenu::onListEnd(void* resultP)
{
    //VFX_TRACE("onListEnd %d",resultP);
}



void VappShellMediaplayerMenu::setDragging(VfxBool dragging)
{
    m_isDragging = dragging;
}


VfxFrame* VappShellMediaplayerMenu::createCell(VfxS32 pos, VfxS32 subcell)
{
    VappShellMediaplayerCell *cell;

    VFX_LOG(VFX_INFO, VAPP_SHELL_MEDIAPLAYER_CREATECELL,pos,__LINE__);
    
    VFX_OBJ_CREATE_EX(
        cell,
        VappShellMediaplayerCell, 
        this, 
        (pos));    /* constructor parameters */ 

    if (getFocus() == pos)
    {
        cell->onHightLight();
    }
    
    WheelMenuUserData data;
    data.index = pos;
    data.subcell = 0;
    data.tick = 0;
    setCellUserData(pos, subcell, cell, &data, sizeof(WheelMenuUserData));     


    // TODO: to evaluate performance
    // update play info.

    srv_plst_media_details_struct details;    
    START_TIME();
    memset(&details,0x0,sizeof(srv_plst_media_details_struct));
    vadp_shell_mediaplayer_get_details(pos,&details);
    STOP_TIME("[SHELL MEDIAPLAYER Cell] get details in %d MSecs, line:%d");

    // Title
    VfxWString temp;
    temp = VFX_WSTR_MEM((const U16*)details.title);
    cell->updateTitle(temp);

    // Artist
    temp = VFX_WSTR_MEM((const U16*)details.artist);
    cell->updateArtist(temp);

    if (m_player->state()==VappShellMediaplayer::STATE_PLAYING && m_player->getViewMode()==VappShellMediaplayer::LIST_MENU_VIEW && m_player->index() == pos)
    {
        m_updateTimer->start();
    }
    
    return cell;
}


ShellMediaplayerResEnum VappShellMediaplayerMenu::getImageBuffer(VfxS32 index, VfxS32 type, VfxU8 **tmpImageBuf, VfxS32 *tmpImageWidth, VfxS32 *tmpImageHeight)
{
    srv_mediacache_image_source_enum source;
    VfxS32 error_code = SRV_MEDIACACHE_ERR_DECODING;
    ShellMediaplayerResEnum ret;

    // Call MediaLib to decode image
    if (type == VappShellMediaplayerCell::DATA_TYPE_MEMORY)
    {
        source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE;
    }
    else if (type == VappShellMediaplayerCell::DATA_TYPE_DB)
    {
        source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE;
    }
    else if (type == VappShellMediaplayerCell::DATA_TYPE_FILE)
    {
        source = SRV_MEDIACACHE_IMAGE_SOURCE_CACHE_AND_DATABASE_AND_DECODE;
    }

    if (type == VappShellMediaplayerCell::DATA_TYPE_MEMORY || type == VappShellMediaplayerCell::DATA_TYPE_DB || type == VappShellMediaplayerCell::DATA_TYPE_FILE)
    {
    #if defined(__MTK_INTERNAL__)       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif  
        
        error_code = vadp_shell_mediaplayer_cache_srv_get_lock_image_buffer(index, source, (void**)tmpImageBuf, tmpImageWidth, tmpImageHeight);

    #if defined(__MTK_INTERNAL__)       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif      
    }

    if (error_code == SRV_MEDIACACHE_OK)
    {
        VFX_LOG(VFX_INFO, VAPP_SHELL_MEDIAPLAYER_GETIMAGEBUFFER_OK,index,__LINE__);
        ret = VAPP_SHELL_MP_RES_MEDIACACHE_OK;
    }
    else if (error_code == SRV_MEDIACACHE_ERR_NOT_READY || 
             error_code == SRV_MEDIACACHE_ERR_NOT_ENOUGH_CACHE ||
             error_code == SRV_MEDIACACHE_ERR_DECODING)
    {
        VFX_LOG(VFX_INFO, VAPP_SHELL_MEDIAPLAYER_GETIMAGEBUFFER_DECODING,index,__LINE__);
        ret = VAPP_SHELL_MP_RES_MEDIACACHE_DECODING;
    }
    else
    {
        VFX_LOG(VFX_INFO, VAPP_SHELL_MEDIAPLAYER_GETIMAGEBUFFER_FAIL,index,__LINE__);
        ret = VAPP_SHELL_MP_RES_MEDIACACHE_NOT_SUPPORT;
    }

    return ret;
}




void VappShellMediaplayerMenu::onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    VappShellMediaplayerCell* item = (VappShellMediaplayerCell*) cellFrame;
    VfxS32 type = VappShellMediaplayerCell::DATA_TYPE_DB;

    VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_ONUPDATECELL,item->index(),__LINE__);
    if (cell == getFocus())
    {
        item->onHightLight();
    }
    else
    {
        item->onDeHightLight();
    }

    if (item->index() == m_player->index())
    {
        VfxU64 currTimeMsec;
        VfxU64 durationMsec;
        
        vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_PLAYTIME,&currTimeMsec);
        vadp_shell_mediaplayer_player_get_info(VADP_SHELL_MEDIAPLAYER_PLAYER_INFO_DURATION,&durationMsec);

        if (currTimeMsec > durationMsec)
            durationMsec = currTimeMsec;

        item->setCurrPlaytimeMsec(currTimeMsec);
        item->setDurationMsec(durationMsec);
        item->updateTime();
        item->updateProgressBar();
    
        if (m_player->state() == VappShellMediaplayer::STATE_PLAYING)
        {
            item->setPlaying(VFX_TRUE);
        }
        else
        {
            item->setPlaying(VFX_FALSE);
        }
    }
    else
    {
        item->setPlaying(VFX_FALSE);
    }

    // 1. update image.
    if (item->state() == VappShellMediaplayerCell::STATE_IMAGE)
    {
        VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_ONUPDATECELL_IMAGE,item->index(),__LINE__);
        return ;
    }
    if (m_isDragging || m_player->isEnterView()==VFX_FALSE)
    {
        type = VappShellMediaplayerCell::DATA_TYPE_MEMORY;            
    }

    VfxU8* imageBuf;
    VfxS32 width;
    VfxS32 height;
    ShellMediaplayerResEnum return_error;

    return_error = getImageBuffer(item->index(),type, &imageBuf, &width, &height);

    if (return_error == VAPP_SHELL_MP_RES_MEDIACACHE_OK)
    {
        VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_ONUPDATECELL_SETIMAGE,item->index(),__LINE__);
        item->setImageBuffer(imageBuf, width, height);
    }
    else if (return_error == VAPP_SHELL_MP_RES_MEDIACACHE_NOT_SUPPORT)
    {
        VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_ONUPDATECELL_USEDEFAULT,item->index(),__LINE__);
        item->useDefaultImage();        
    }
    else
    {
        // image is not decoded yet, still need to wait for callback
    }
    
}

void VappShellMediaplayerMenu::updateCellImage()
{
    VappShellMediaplayerCell* cell;
    void *buffer_p;
    VfxS32 ret = 0;
    VfxS32 start_index;

    if (m_isDragging == VFX_TRUE || m_player->isEnterView()==VFX_FALSE || m_isDecoding == VFX_TRUE)
    {
        VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_EXIT_UDPATECELLIMAGE,__LINE__);
        return;
    }


    cell = (VappShellMediaplayerCell*) getCellIfPresent(getFocus());
    if (cell && cell->state() != VappShellMediaplayerCell::STATE_IMAGE)
        start_index = getFocus();
    else
        start_index = getFirstVisibleIndex();
    
    for (VfxS32 i = start_index; i < getLastVisibleIndex(); i++)
    {
        cell = (VappShellMediaplayerCell*)getCellIfPresent(i, 0);
        if (cell && cell->state() != VappShellMediaplayerCell::STATE_IMAGE)
        {
            VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_UDPATECELLIMAGE_LOCKIMAGE,i,__LINE__);

            //VAPP_SHELLIV_START_LOGGING("UNB");
            ret = vadp_shell_mediaplayer_cache_srv_get_lock_image_buffer_nonblocking(
                    (void*)this, 
                    i, 
                    onDecodeCallBack, 
                    &buffer_p);

            //VAPP_SHELLIV_STOP_LOGGING("UNB");
            if (ret == SRV_MEDIACACHE_OK)
            {
                VfxS32 width,height;
                ret = vadp_shell_mediaplayer_cache_srv_get_image_info(i, &width, &height);
                if (ret == SRV_MEDIACACHE_OK)
                {
                    VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_UDPATECELLIMAGE_LOCKIMAGE_OK,i,__LINE__);
                    cell->setImageBuffer((VfxU8*)buffer_p,width,height);
                    m_timer->start();   
                }
                else
                {
                    VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_UDPATECELLIMAGE_LOCKIMAGE_FAIL,i,__LINE__);
                    cell->useDefaultImage();
                    m_timer->start();
                }
            }
            else if (ret == SRV_MEDIACACHE_ERR_NOT_SUPPORT)
            {
                VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_UDPATECELLIMAGE_LOCKIMAGE_FAIL,i,__LINE__);
                cell->useDefaultImage();
                m_timer->start();
            }
            else
            {
                m_isDecoding = VFX_TRUE;
                VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_UDPATECELLIMAGE_LOCKIMAGE_WAITING,i,__LINE__);
            }
            break;

        }     
    }

    VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_EXIT_UDPATECELLIMAGE,__LINE__);
}

void VappShellMediaplayerMenu::onDecodeCallBack(void* user_data, VfxS32 index, VfxS32 error_code)
{
    VappShellMediaplayerMenu* this_ptr = (VappShellMediaplayerMenu*) user_data;
    VfxObjWeakPtr weak_ptr = this_ptr;

    VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_ONDECODECALLBACK,index,__LINE__);

    VAPP_SHELLIV_START_LOGGING("DCB");
    if (weak_ptr != NULL)
    {
        VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_CALL_UPDATEDECODERESULT,index,__LINE__);
        this_ptr->updateDecodeResult(index, error_code);
    }
    else
    {
        VFX_LOG(VFX_INFO,VAPP_SHELL_MEDIAPLAYER_CALL_UPDATEDECODERESULT_FAIL,index,__LINE__);
    }
    VAPP_SHELLIV_STOP_LOGGING("DCB");
}


void VappShellMediaplayerMenu::updateDecodeResult(VfxS32 index, VfxS32 error_code)
{
    VappShellMediaplayerCell* cell;

    cell = (VappShellMediaplayerCell*)getCellIfPresent(index, 0);

    m_isDecoding = VFX_FALSE;
    if (cell && (cell->state() != VappShellMediaplayerCell::STATE_IMAGE))
    {
        VFX_LOG(VFX_INFO, VAPP_SHELL_MEDIAPLAYER_UPDATEDECODERESULT_CELLEXIST, index,__LINE__);
        if (error_code == SRV_MEDIACACHE_OK)
        {
            VfxU8* imageBuf;
            VfxS32 width;
            VfxS32 height;
            ShellMediaplayerResEnum return_error;

            return_error = getImageBuffer(cell->index(),VappShellMediaplayerCell::DATA_TYPE_DB, &imageBuf, &width, &height);

            if (return_error == VAPP_SHELL_MP_RES_MEDIACACHE_OK)
            {
                VFX_LOG(VFX_INFO, VAPP_SHELL_MEDIAPLAYER_UPDATEDECODERESULT_OK, index,__LINE__);
                cell->setImageBuffer(imageBuf, width, height);
            }
            else if (return_error == VAPP_SHELL_MP_RES_MEDIACACHE_NOT_SUPPORT)
            {
                VFX_LOG(VFX_INFO, VAPP_SHELL_MEDIAPLAYER_UPDATEDECODERESULT_FAIL, index,__LINE__);
                cell->useDefaultImage();        
            }
            else
            {
                VFX_LOG(VFX_INFO, VAPP_SHELL_MEDIAPLAYER_UPDATEDECODERESULT_WAIT, index,__LINE__);
                // image is not decoded yet, still need to wait for callback
            }
        }
        else
        {
            VFX_LOG(VFX_INFO, VAPP_SHELL_MEDIAPLAYER_UPDATEDECODERESULT_FAIL, index,__LINE__);
            cell->useDefaultImage();
        }
    }
    VFX_LOG(VFX_INFO, VAPP_SHELL_MEDIAPLAYER_CALL_UPDATECELLIMAGE, __LINE__);
    updateCellImage();
}



void VappShellMediaplayerMenu::setCount(VfxS32 count)
{
	m_count = count;
}

VfxS32 VappShellMediaplayerMenu::getCount()
{
    return m_count;
}

VcpWheelMenuFrameEffectCBFuncPtr VappShellMediaplayerMenu::getFrameEffectCB()
{
    return &VappShellMediaplayerMenu::FrameEffectCB;
}

//VfxS32 array_x[7] = {197,160,132,113,132,160,197};
//VfxS32 array_y[7] = {57,102,154,213,285,344,391};
#if defined(__MMI_MAINLCD_320X480__)&& defined(__MMI_VUI_SHELL_MEDIA_PLAYER_SLIM__)
VfxS32 array_x[7] = {270,202,166,132,166,202,270};
VfxS32 array_y[7] = {77,127,187,267,351,411,461};
#elif defined(__MMI_MAINLCD_240X400__)
VfxS32 array_x[7] = {197,154,126,98,126,154,197};
VfxS32 array_y[7] = {57,109,157,223,295,343,391};
#elif defined(__MMI_MAINLCD_240X320__) && defined(__SHELL_MEDIAPLAYER_SUPER_SLIM__)
VfxS32 array_x[7] = {240,196,143,102,143,196,240};
VfxS32 array_y[7] = {70,117,145,197,270,318,321};
#elif defined(__MMI_MAINLCD_240X320__)
VfxS32 array_x[7] = {210,165,130,102,130,160,205};
VfxS32 array_y[7] = {55,101,138,197,268,310,321};
#endif

vrt_render_dirty_type_enum VappShellMediaplayerMenu::FrameEffectCB(
    VfxS32                              cell,           // [IN] the cell index
    VfxS32                              subCell,        // [IN] the sub cell index
    VfxFloat                            cellRelPos,     // [IN] the cell position
    vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
    VfxFloat                            fPos,           // [IN] animating index value
    VfxS32                              focus,          // the focus value of the menu
    VfxRect                             viewBounds,     // the menu bounds
    void                                *userData,      // user data
    VfxU32                              userDataSize,    // user data size
    VcpWheelMenuState                   state,          // [IN] the state of Menu
    VfxFloat                            level           // [IN] the level of state
    )
{
    VFX_UNUSED(focus);
    VFX_UNUSED(viewBounds);
    VFX_UNUSED(userDataSize);
    VFX_DEV_ASSERT(target_frame != NULL);
    VFX_DEV_ASSERT(userDataSize == sizeof(WheelMenuUserData));

#if defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_VUI_SHELL_MEDIA_PLAYER_SLIM__)
    VfxS32 w = viewBounds.size.width / 2;
    VfxS32 h = viewBounds.size.height / 2;
    // define the semimajor axis a and semiminor axis b of ellipse. 
    VfxS32 a = CELL_ITEM_X_AXIS_RADIUS;
    VfxS32 b = CELL_ITEM_Y_AXIS_RADIUS;

    float d = vfxCos(cellRelPos * CELL_ITEM_ROTATE_ANGLE / 180.0f * VFX_PI);
    float e = vfxSin(cellRelPos * CELL_ITEM_ROTATE_ANGLE_Y/ 180.0f * VFX_PI);
    // calculate the pos by ellipse parametric equation.
    // notice that we offset 10 in X axis, so the menu is looked on left side.
	target_frame->pos.x = VfxS32(w + (1 - d) * a ) - CELL_ITEM_X_SHIFT;
    target_frame->pos.y = VfxS32(CELL_ITEM_OFFSET_Y + h + e * b);

    if (cellRelPos>=1)
    {
        target_frame->pos.y += 24;
    }
    else if (cellRelPos > 0)
    {
        target_frame->pos.y += (cellRelPos)*24;
    }
#else
    VfxFloat cellPosIndex = (cellRelPos)+3;
    if (!(cellPosIndex < 0 || cellPosIndex>6))
    {
        VfxS32 min = VfxS32(cellPosIndex);
        VfxS32 max = min+1;
        VfxFloat offset = cellPosIndex - min;

        VfxS32 x = array_x[min]* (1-offset)+ array_x[max] *(offset);
        VfxS32 y = array_y[min]* (1-offset) + array_y[max] *(offset);
        target_frame->pos.x = x;
        target_frame->pos.y = y;
    }
#endif    
    // set opacity
    //scale the item
    target_frame->transform.type = VRT_TRANSFORM_TYPE_AFFINE;

    float c = VFX_ABS(cellRelPos);
    float scale = 1.0f;
    VfxFloat behindCount = CELL_ITEM_BEHIND_COUNT;
    VfxFloat aheadCount = CELL_ITEM_AHEAD_COUNT;
    behindCount++;
    aheadCount++;

    VFX_TRACE(("oooooooooooooooooooooooooooooooooooo  cellRelPos=%f \n",cellRelPos));

    if (cellRelPos > -aheadCount && cellRelPos < behindCount)
    {
        VFX_TRACE(("oooooooooooooooooooooooooooooooooooo  VISIABLE \n"));
        target_frame->opacity = 1;
    }
    else 
    {
        VFX_TRACE(("oooooooooooooooooooooooooooooooooooo  IN-VISIABLE \n"));
        target_frame->opacity = 0;
    }

#if !defined(__SHELL_MEDIAPLAYER_SUPER_SLIM__)
    if (c==0)
    {
        // do nothing
    }
    else if (c<=1)
    {
        target_frame->opacity = 1-(c*0.1);
        scale = 1-(c*0.1);
    }
    else if (c<=2)
    {
        target_frame->opacity = 1.08f - (0.18*c);
        scale = 1.08f - (0.18*c);        
    }
    else
    {
    
        scale = 1.16f - (0.22*c);        
        if (c>3)
            c = 3;
        target_frame->opacity = 2.16f - (0.72*c);
    }
#endif

    target_frame->transform.data.affine.sx = scale;// 1 - VFX_ABS(cellRelPos) * CELL_ITEM_SCALE_X;
    target_frame->transform.data.affine.sy = scale;// 1 - VFX_ABS(cellRelPos) * CELL_ITEM_SCALE_Y;

    target_frame->pos_z = VFX_ABS(cellRelPos);

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


ShellMediaplayerResEnum VappShellMediaplayerMenu::unlockImageBuffer(VfxU8 *tmpImageBuf)
{
    VfxS32 error_code;

    if (tmpImageBuf==NULL)
    {
        ASSERT(0);
    }
    
    error_code = vadp_shell_mediaplayer_cache_srv_free_image_buffer((void*)tmpImageBuf);

    if (error_code == SRV_MEDIACACHE_OK)
    {
        return VAPP_SHELL_MP_RES_MEDIACACHE_OK;
    }
    else
    {
        ASSERT(0);
        return VAPP_SHELL_MP_RES_MEDIACACHE_BUFFER_NOT_FOUND;
    }
}


void VappShellMediaplayerMenu::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    VappShellMediaplayerCell *item = (VappShellMediaplayerCell *)cellFrame;

    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONCLOSECELL, item->index(),__LINE__);

    // Free image buffer 
    if (item->state() == VappShellMediaplayerCell::STATE_IMAGE && item->getImageType() == VFX_IMAGE_SRC_TYPE_IMAGE_BUFFER)
    {
        unlockImageBuffer(item->getImageBuffer());
        //VFX_TRACE(("[SHELL MEDIAPLAYER CELL] unlock frame buffer [%d,%d]\n", item->index(),item->state()));        
    }
    VFX_UNUSED(subcell);
    VFX_OBJ_CLOSE(cellFrame);
}

void VappShellMediaplayerMenu::onBeforeUpdateCell()
{
}

void VappShellMediaplayerMenu::onAfterUpdateCell()
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_CALL_UPDATECELLIMAGE, __LINE__);
    updateCellImage();
}

void VappShellMediaplayerMenu::onFocusIndexChange(VfxS32 focusItem, VfxS32 previousFocusItem)
{
    if (VCP_WHEELMENU_IS_VALID_INDEX(previousFocusItem))
    {
        VappShellMediaplayerCell* cell = (VappShellMediaplayerCell*) getCellIfPresent(previousFocusItem);
        if (cell)
        {
            cell->onDeHightLight();
        }
    }
    if (VCP_WHEELMENU_IS_VALID_INDEX(focusItem))
    {
        VappShellMediaplayerCell* cell = (VappShellMediaplayerCell*) getCellIfPresent(focusItem);
        if (cell)
        {
            cell->onHightLight();
        }
    }
}


void VappShellMediaplayerMenu::onDragStart() 
{
    VcpWheelMenu::onDragStart();

    if (m_player->isEnterView()==VFX_FALSE)
    {
        return;
    }
    
    m_isDragging = VFX_TRUE;
}


void VappShellMediaplayerMenu::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    VFX_UNUSED(xspeed);

    if (m_player->isEnterView()==VFX_FALSE)
    {
        return;
    }

    yspeed *= (-1);

    m_isDragging = VFX_FALSE;
    if (yspeed == 0)
    {
        setFocus(VfxS32(getScrollIndex() + 0.5f));
    }
    else
    {
        VfxS32   s  = yspeed > 0 ? -1 : 1;
        VfxFloat m  = VFX_ABS(yspeed) / 333.3f;
            
        if (m > 3) m = 3;
            
        setFocus(VfxS32(getScrollIndex() - s * m + 0.5f), 300);
    }
}

void VappShellMediaplayerMenu::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VFX_UNUSED(xoffset);
    //VFX_TRACE(("xoffset = %d, yoffset = %d, ScrollIndex= %f \n", xoffset, yoffset, getScrollIndex() + VfxFloat(yoffset) / VappShellMediaplayerCell::CELL_ITEM_HEIGHT));
    if (m_player->isEnterView()==VFX_FALSE)
    {
        return;
    }
    yoffset *= (-1);

    VfxFloat perc = getScrollIndex() + VfxFloat(yoffset) / VappShellMediaplayerCell::CELL_ITEM_HEIGHT;
    VfxFloat threshold = (VfxFloat)m_count - 0.5f;

//    if (yoffset > 10)
//        m_eventDragStart.emit();

    if (m_count < CELL_ITEM_VIEW_COUNT && m_count >= 1)
    {
        if (perc > threshold)
            setScrollIndex(threshold, 0);
        else if (perc < 0)
            setScrollIndex(-0.5, 0);
        else
            setScrollIndex(perc, 0);
    }
    else
        setScrollIndex(perc, 0);
        
}


void VappShellMediaplayerMenu::onTap(VfxPoint pt)
{
    VfxS32 up   = CELL_ITEM_POS_Y;
    VfxS32 down = CELL_ITEM_POS_Y + VappShellMediaplayerCell::CELL_ITEM_HEIGHT;

    if (m_player->isEnterView()==VFX_FALSE)
    {
        return;
    }

    if (pt.y >= up && pt.y <= down)
    {
        VappShellMediaplayerCell* cell = (VappShellMediaplayerCell*)getCellIfPresent(getFocus());
        if (cell)
        {
            setFocus(getFocus());
            cell->onHightLight();

            if (m_player->index()!=getFocus())
            {
                // apply this index to play and wait for mediachange to switch back to main screen
                VappShellMediaplayer::VappShellMediaplayerStateEnum preState = m_player->state();
                m_player->setState(VappShellMediaplayer::STATE_TAPTOPLAY);
                m_player->setLastIndex(m_player->index());
                m_player->setIndex(getFocus());

                vadp_shell_mediaplayer_player_stop();
                //vadp_shell_mediaplayer_player_set_index(m_player->index());                

                cell = (VappShellMediaplayerCell*)getCellIfPresent(m_player->index());
                if (cell)
                {
                    cell->hideTime();
                }

                m_signalTapToPlay.emit();
            }
            else 
            {
                if (m_player->state() == VappShellMediaplayer::STATE_IDLE)
                {
                    m_player->setState(VappShellMediaplayer::STATE_TAPTOPLAY);

                    m_signalTapToPlay.emit();
                }
            }
        } 
    }
    else if (pt.y < up)
    {
        setFocus(getFocus() - 1);
    }
    else if (pt.y > down)
    {
        setFocus(getFocus() + 1);
    }
}


/*****************************************************************************
 * Class VappShellIVPanel
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappShellMediaplayer", VappShellMediaplayer, VappShellPanel);

VappShellMediaplayer::VappShellMediaplayer(void):
    m_pagePanel(NULL),
    m_menuFrame(NULL),
    m_mainScreen(NULL),
    m_viewMode(MAIN_SCREEN_VIEW),
    m_isNext(VFX_FALSE),
    m_state(STATE_IDLE),
    m_forceToPlay(VFX_FALSE),
    m_initService(SRV_STATE_IDLE)
{

}

void VappShellMediaplayer::onPlayerCallback(void* userdata, VfxU32 type, void* resultP)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappShellMediaplayer* this_ptr = (VappShellMediaplayer*) userdata;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    VFX_LOG(VFX_INFO2,VAPP_SHELL_MEDIAPLAYER_ONPLAYERCALLBACK,type);

    if (type == MMI_WIDGET_PLAYER_STATUS_CHANGE_CALLBACK)
    {
        this_ptr->onStatusChanged(resultP);
    }
    else if (type == MMI_WIDGET_PLAYER_MEDIA_CHANGE_CALLBACK)
    {
        this_ptr->onMediaChanged(resultP);
    }
    else if (type == MMI_WIDGET_PLAYER_PLAY_END_CALLBACK)
    {
        this_ptr->onPlayEnd(resultP);
    }
    else if (type == MMI_WIDGET_PLAYER_LIST_END_CALLBACK)
    {
        this_ptr->onListEnd(resultP);    
    }
    else if (type == MMI_WIDTET_PLAYER_VOL_CHANGE_CALLBACK)
    {
        this_ptr->m_mainScreen->showVolCtrlPopup();
        this_ptr->m_mainScreen->getVolCtrlPopup()->changeVolume();
    }
}


void VappShellMediaplayer::onInit()
{
    VappShellPanel::onInit(); 
    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONINIT);
}


void VappShellMediaplayer::onDeinit()
{
    VappShellPanel::onDeinit();
    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONDEINIT);
}


void VappShellMediaplayer::onFinishSwitchView(VfxFrame * target,VfxBool isCompleted)
{    
    m_isEnterView = VFX_TRUE;
    
    if (m_viewMode == MAIN_SCREEN_VIEW)
    {
        if (m_mainScreen.isValid())
        {
            m_mainScreen->onFinishSwitchView(target,isCompleted);
        }
    }
    else
    {
        if (m_menuFrame.isValid())
        {
            m_menuFrame->m_menu->onFinishSwitchView(target,isCompleted);
        }
    }

    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONFINISHSWITCHVIEW, target, isCompleted);    
}


void VappShellMediaplayer::onInitView()
{
    Super::onInitView();    

    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONINITVIEW);    

    VFX_OBJ_CREATE(m_pagePanel, VcpPagePanel, this);
    VFX_OBJ_CREATE(m_mainScreen, VappShellMediaplayerMainScreen, m_pagePanel);

    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    m_pagePanel->setRect(0, 0, main_screen_size.width, main_screen_size.height);
    m_pagePanel->m_signalFinished.connect(this, &Self::onFinishSwitchView);
    m_pagePanel->setBgColor(VRT_COLOR_BLACK);
    m_pagePanel->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);


    hideShortcutBar(VFX_FALSE);
    m_pagePanel->setCurrentFrame(m_mainScreen.get());    

    m_isEnterView = VFX_FALSE;
    m_isShuffle = VFX_FALSE;
    m_repeatMode = VADP_SHELL_MEDIAPLAYER_REPEAT_OFF;
    
    m_mainScreen->setRect(0, 0, main_screen_size.width, main_screen_size.height);
    m_mainScreen->setBgColor(VRT_COLOR_TRANSPARENT);
    m_mainScreen->m_signalSwitchButtonClicked.connect(this, &Self::onSwitchView);
    m_mainScreen->setPlayer(this);
    m_mainScreen->setIsOpaque(VFX_TRUE);
   
    VFX_OBJ_CREATE(m_waitingTimer, VfxTimer, this);
    m_waitingTimer->setStartDelay(1000);
    m_waitingTimer->m_signalTick.connect(this, &Self::onWaitingTimerExpired);
    m_waitingTimer->start();

    m_mainScreen->updateMainScreenSetting(); 
    m_mainScreen->updateMainScreenInfo();
    
}

#if defined(__MMI_AVRCP_SUPPORT__) 
VfxU8 VappShellMediaplayer::avrcpCommandHandler(void* userdata, VfxU8 command, mmi_avrcp_key_events event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = MMI_AVRCP_CR_ACCEPT;
    VappShellMediaplayer* this_ptr = (VappShellMediaplayer*) userdata;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (command)
    {
        case MMI_AVRCP_POP_PLAY:
        case MMI_AVRCP_POP_PAUSE:    
            //PRINT_INFORMATION(("[MTV_AVRCP] command: PLAY or POP, line:%d", __LINE__));    
            if (event == MMI_AVRCP_KEY_UP)
            {

                //m_mainScreen->onButtonClick(NULL, VappShellMediaplayerMainScreen::BUTTON_PLAY);
                #if 1
				
		        vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_STATE,&m_playerState);
		        if (m_playerState == VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_PLAY)
		        {
		            this_ptr->m_state = STATE_PLAYING;
		        }
		        else if (m_playerState == VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_PROCESS)
		        {
		            this_ptr->m_state = STATE_PROCESSING;        
		        }
		        else
		        {
		            this_ptr->m_state = STATE_IDLE;
		        }
				
                if (this_ptr->m_state == STATE_IDLE)
                {
                    vadp_shell_mediaplayer_player_play();
                    setState(STATE_PLAYING);
                    if (m_viewMode == MAIN_SCREEN_VIEW)
                    {
                        //incase the play action triggers pop up so that shell is exited
                        if(m_mainScreen != NULL)
                        {
                            m_mainScreen->prepare();
                        }
                    }
                    else
                    {
                        if(m_menuFrame != NULL)
                        {
                            m_menuFrame->m_menu->prepare();
                            m_menuFrame->m_menu->onStartPlaying();
                        }
                    }           
                }
                else
                {
                    this_ptr->m_state = STATE_TAPTOSTOP;
                    vadp_shell_mediaplayer_player_pause();
                    if (m_viewMode == MAIN_SCREEN_VIEW)
                    {
                        if(m_mainScreen != NULL)
                        {
                            m_mainScreen->unprepare();
                        }
                    }
                    else
                    {
                        if(m_menuFrame != NULL)
                        {
                            m_menuFrame->m_menu->unprepare();
                            m_menuFrame->m_menu->onStopPlaying();
                        }
                    }
                    this_ptr->m_state = STATE_IDLE;

                }
                #endif
            }
            else
            {
                /* ingore others */
            }        

            break;
        case MMI_AVRCP_POP_FORWARD:
            {
                if (event == MMI_AVRCP_KEY_UP)
                {
                    this_ptr->setIsNext(VFX_TRUE);
                    m_mainScreen->setNeedToSwitch(VFX_TRUE);
                    if (this_ptr->m_state == STATE_IDLE)
                    {
                        vadp_shell_mediaplayer_cache_set_index(next());
                        //vadp_shell_mediaplayer_player_set_index(index());                 

                        if (this_ptr->m_viewMode == MAIN_SCREEN_VIEW)
                        {
                            if(m_mainScreen != NULL)
                            {
                                m_mainScreen->updateMainScreenInfo();
                            } 

                        }
                        else
                        {
                            if(m_menuFrame != NULL)
                            {
                                m_menuFrame->m_menu->prepare();
                            }
                        }
                        
                    }
                    else if (this_ptr->m_state == STATE_PLAYING)
                    {
                        vadp_shell_mediaplayer_player_pause();
                        vadp_shell_mediaplayer_cache_set_index(next());
                        //vadp_shell_mediaplayer_player_set_index(index());
                        vadp_shell_mediaplayer_player_play();
                    }
                }
                else
                {
                    /* ingore others */
                }   
            }
            break;
        case MMI_AVRCP_POP_BACKWARD:
            {
                if (event == MMI_AVRCP_KEY_UP)
                {
                    this_ptr->setIsNext(VFX_FALSE);
                    m_mainScreen->setNeedToSwitch(VFX_TRUE);
                    if (this_ptr->m_state == STATE_IDLE)
                    {
                        vadp_shell_mediaplayer_cache_set_index(prev());
                        //vadp_shell_mediaplayer_player_set_index(index());                 

                        if (this_ptr->m_viewMode == MAIN_SCREEN_VIEW)
                        {
                            if(m_mainScreen != NULL)
                            {                        
                                m_mainScreen->updateMainScreenInfo();
                            }
                        }
                        else
                        {
                            if(m_menuFrame != NULL)
                            {
                                m_menuFrame->m_menu->prepare();
                            }
                        }
                        
                    }
                    else if (this_ptr->m_state == STATE_PLAYING)
                    {
                        vadp_shell_mediaplayer_player_pause();
                        vadp_shell_mediaplayer_cache_set_index(prev());
                        //vadp_shell_mediaplayer_player_set_index(index());
                        vadp_shell_mediaplayer_player_play();
                    }
                }
                else
                {
                    /* ingore others */
                }   
            }
            break;            
        default:
            result = MMI_AVRCP_CR_NOT_IMPLEMENT;
            break;
    }

    return result;

}

VfxU8 VappShellMediaplayer::avrcpCmdHdlr(void* userdata, VfxU8 command, mmi_avrcp_key_events event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VappShellMediaplayer* this_ptr = (VappShellMediaplayer*) userdata;
        
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return this_ptr->avrcpCommandHandler(userdata,command,event);
}
#endif /* __MMI_AVRCP_SUPPORT__ */


void VappShellMediaplayer::onDeinitView()
{    
    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONDEINITVIEW);
    VFX_OBJ_CLOSE(m_waitingTimer);
    VFX_OBJ_CLOSE(m_pagePanel);    
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    VappShellPanel::onDeinitView();
}
    
void VappShellMediaplayer::onWaitingTimerExpired(VfxTimer *source)
{
    if (m_mainScreen.isValid())
    {
        m_mainScreen->hideWaitingIcon();
    }
}

void VappShellMediaplayer::onEnterView()
{
    VappShellPanel::onEnterView();

    m_waitingTimer->stop();

    m_mainScreen->displayWaitingIcon();
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->mustShowNextFrame();

    ShellMediaplayerResEnum error = initPlstService();

    if (error == VAPP_SHELL_MEDIAPLAYER_RES_OK)
    {
        m_initService = SRV_STATE_READY;
        /* Get player state */
        vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_STATE,&m_playerState);

        m_repeatMode = vadp_shell_mediaplayer_player_get_repeat_mode();
        m_isShuffle = vadp_shell_mediaplayer_player_is_shuffle();

        if (m_playerState == VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_PLAY)
        {
            m_state = STATE_PLAYING;
        }
        else if (m_playerState == VADP_SHELL_MEDIAPLAYER_STATE_LOADING)
        {
            m_state = STATE_PROCESSING;        
        }
        else
        {
            m_state = STATE_IDLE;
        }        

        vadp_shell_mediaplayer_player_register_callback((void*)this, onPlayerCallback);

    }
    else
    {
        m_initService = SRV_STATE_NOT_READY;
        m_state = STATE_IDLE;
    }

    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONENTERVIEW,m_songCount,m_songCountMenu,m_highlightIndex,m_state);

    m_mainScreen->updateMainScreenSetting(); 

    m_mainScreen->prepare();
    m_mainScreen->updateMainScreenInfo();

    VFX_OBJ_CREATE(m_menuFrame, VappShellMediaplayerMenuFrame, m_pagePanel);
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    m_menuFrame->setRect(0, 0, main_screen_size.width, main_screen_size.height);
    m_menuFrame->setBgColor(VRT_COLOR_TRANSPARENT);
    m_menuFrame->m_signalSwitchButtonClicked.connect(this, &Self::onSwitchView);
    m_menuFrame->setPlayer(this);
    m_menuFrame->setIsOpaque(VFX_TRUE);
    m_menuFrame->m_menu->m_signalTapToPlay.connect(this, &Self::onTapToPlay);

    m_volume = vadp_shell_mediaplayer_player_get_volume();        

    if (m_songCountMenu > 0)
    {
        ShellMediaplayerResEnum error = initMediaCacheService();
        VFX_ASSERT(error == VAPP_SHELL_MEDIAPLAYER_RES_OK);

    }
    else
    {
        m_menuFrame->showString(m_songCount);
    }

    if (m_songCount > 0)
    {
        vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_STATE,&m_playerState);
        if (m_playerState == VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_PLAY)
        {
            m_state = STATE_PLAYING;
        }
        else if (m_playerState == VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_PROCESS)
        //else if (m_playerState == VADP_SHELL_MEDIAPLAYER_STATE_LOADING)
        {
            m_state = STATE_PROCESSING;        
        }
        else
        {
            m_state = STATE_IDLE;
        }
    #if defined(__MMI_AVRCP_SUPPORT__)
        vadp_shell_mediaplayer_player_avrcp_callback((void*)this,avrcpCmdHdlr);
    #endif 

        if(g_tapToPlay == VFX_TRUE)
        {
            m_state = STATE_TAPTOPLAY;
            mmi_medply_stop_playing();
            // apply index to select
            vadp_shell_mediaplayer_player_apply_picked_file();
			//MAUI_02952213
			//The first time to stop playing will enter PURE_AUDIO_READY state according to media_type of VIDEO
			//Media type only be update while apply picked file.
			//So, we need to stop playing again to confirm the right state will be toggled.
            mmi_medply_stop_playing();
            m_mainScreen->updateMainScreenInfo();
            g_tapToPlay = VFX_FALSE;
            m_forceToPlay = VFX_TRUE;
        }
    }
    else
    	{
    		        if(g_tapToPlay == VFX_TRUE)
        {
            mmi_medply_stop_playing();
            vadp_shell_mediaplayer_player_apply_picked_file();
            mmi_medply_stop_playing();
            m_mainScreen->updateMainScreenInfo();
            g_tapToPlay = VFX_FALSE;
        }
        
    		}

    if (m_viewMode == MAIN_SCREEN_VIEW)
    {
        hideShortcutBar(VFX_FALSE);
        m_pagePanel->setCurrentFrame(m_mainScreen.get());
        m_mainScreen->prepare();
    }
    else
    {
        hideShortcutBar(VFX_TRUE);
        m_menuFrame->m_backupIndex = m_highlightIndex;
        m_pagePanel->setCurrentFrame(m_menuFrame.get());
        m_menuFrame->m_menu->prepare();
    }

    m_isEnterView = VFX_TRUE;
}


void VappShellMediaplayer::onExitView(ShellExitCauseEnum cause)
{
    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONEXITVIEW);    
    m_isEnterView = VFX_FALSE;

    m_waitingTimer->stop();    

    // need to destroy menuFrame first, due to it will use database service.
    VFX_OBJ_CLOSE(m_menuFrame);
    
    if (cause == APP_SHELL_END_KEY_EXIT)
    {
        m_viewMode = MAIN_SCREEN_VIEW;
    }     	

    m_mainScreen->unprepare();
    m_mainScreen->onExitView();

    deinitMediaCacheService();
    vadp_shell_mediaplayer_deregister_callback();

    if (m_initService == SRV_STATE_READY)
    {
        //vadp_shell_mediaplayer_player_sync_repeat_mode_to_medply(m_repeatMode);
        //vadp_shell_mediaplayer_player_sync_shuffle_with_medply(m_isShuffle);
        deinitPlstService();
        m_initService = SRV_STATE_IDLE;
    }
    
#if defined(__MMI_AVRCP_SUPPORT__)
    vadp_shell_mediaplayer_player_avrcp_callback((void*)this,NULL);
#endif 

    
    VappShellPanel::onExitView(cause);
}


VfxBool VappShellMediaplayer::onKeyInput(VfxKeyEvent &event)
{
	if (event.type != VFX_KEY_EVENT_TYPE_UP)
	{
    switch( event.keyCode )
    {
        case VFX_KEY_CODE_VOL_UP:    
        case VFX_KEY_CODE_VOL_DOWN:
            m_mainScreen->showVolCtrlPopup();
            break;
    }
	}

    return Super::onKeyInput(event);
}

void VappShellMediaplayer::onMenuDragStart()
{
    VappShellPanel::cancelDefaultPageAct();
}

void VappShellMediaplayer::onTapToPlay()
{    
    START_TIME();
    vadp_shell_mediaplayer_player_set_index(index());
    STOP_TIME("onTapToPlay:set_index()=%d ms, line:%d");

    START_TIME();
    // apply switch effect
    m_mainScreen->updateMainScreenInfo();
    STOP_TIME("onTapToPlay:udpateMainscreenInfo()=%d ms, line:%d");

    onSwitchView();

}

void VappShellMediaplayer::onSwitchView()
{
    m_menuFrame->m_menu->setDragging(VFX_TRUE);

    m_isEnterView = VFX_FALSE;
        
    if (m_viewMode == MAIN_SCREEN_VIEW)
    {
        VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONSWITCHVIEW,MAIN_SCREEN_VIEW,LIST_MENU_VIEW);    
        hideShortcutBar(VFX_TRUE);

        m_mainScreen->unprepare();
        m_menuFrame->m_backupIndex = m_highlightIndex;
        m_menuFrame->m_menu->prepare();
        m_pagePanel->switchTo(m_menuFrame.get(), VCP_PAGE_EFFECT_SMALL_FLIP, 500, VCP_PAGE_DIRECTION_FROM_LEFT);
        m_viewMode = LIST_MENU_VIEW;
      
    }
    else
    {
        VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONSWITCHVIEW,LIST_MENU_VIEW,MAIN_SCREEN_VIEW);    
        m_menuFrame->m_menu->unprepare();

        if(m_initService == SRV_STATE_READY && m_songCount >=1)
        {
            // Do not need to call prepare here, we will do this after switch finished.
            vadp_shell_mediaplayer_player_get_info(VADP_SHELL_MEDIAPLAYER_PLAYER_INFO_DURATION,&m_durationMsec);
            vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_PLAYTIME,&m_currTimeMsec);
            m_mainScreen->setCurrPlaytimeMsec(m_currTimeMsec);
            m_mainScreen->setDurationMsec(m_durationMsec);
            m_mainScreen->updateProgressBar();
        }
        
        m_pagePanel->switchTo(m_mainScreen.get(), VCP_PAGE_EFFECT_SMALL_FLIP, 500, VCP_PAGE_DIRECTION_FROM_LEFT);
        hideShortcutBar(VFX_FALSE);
        m_viewMode = MAIN_SCREEN_VIEW;        
    }

    m_menuFrame->m_menu->setDragging(VFX_FALSE);
}

ShellMediaplayerResEnum VappShellMediaplayer::initPlstService()
{   
    START_TIME();
    // init plst service 
    if (vadp_shell_mediaplayer_init() == KAL_TRUE)
    {
        STOP_TIME("init() = %dMSec, line: %d");

        m_songCount = vadp_shell_mediaplayer_get_active_item_count();
        m_songCountMenu = vadp_shell_mediaplayer_get_menu_item_count();

        m_highlightIndex  = vadp_shell_mediaplayer_get_active_index();
        //VFX_TRACE("\n[Shell Mediaplayer] total count= %d, highlight = %d", m_songCount, m_highlightIndex);

        if (m_songCount <= 0 || m_highlightIndex == -1)
        {
            // TODO: need to handle this case.
            //ASSERT(0);
            m_songCount = 0;
            m_songCountMenu = 0;
            m_highlightIndex = 0;
            return VAPP_SHELL_MEDIAPLAYER_RES_OK;
        }

    }
    else
    {
        // TODO: handle this case
        //ASSERT(0);
        m_songCount = 0;
        m_songCountMenu = 0;
        m_highlightIndex = 0;        
        return VAPP_SHELL_MEDIAPLAYER_RES_FAIL;
    }
	return VAPP_SHELL_MEDIAPLAYER_RES_OK;

}

VappShellMediaplayer::VappShellMediaplayerStateEnum VappShellMediaplayer::state()
{
    return m_state;
}

void VappShellMediaplayer::setVol(VfxU8 volume)
{
    m_volume = volume;
}


void VappShellMediaplayer::setState(VappShellMediaplayer::VappShellMediaplayerStateEnum state)
{
    m_state = state;
}

VfxU8 VappShellMediaplayer::playerState()
{
    return m_playerState;
}



void VappShellMediaplayer::setDuration(VfxU64 durationMsec)
{
    m_durationMsec = durationMsec;
}

void VappShellMediaplayer::setCurrPlayTime(VfxU64 currPlayTimeMsec)
{
    m_currTimeMsec = currPlayTimeMsec;
}

VfxU64 VappShellMediaplayer::getCurrPlayTime()
{
    return m_currTimeMsec;
}

VfxU64 VappShellMediaplayer::getDuration()
{
    return m_durationMsec;
}

ShellMediaplayerResEnum VappShellMediaplayer::deinitPlstService()
{
    vadp_shell_mediaplayer_deinit_plst();
	return VAPP_SHELL_MEDIAPLAYER_RES_OK;    
}

ShellMediaplayerResEnum VappShellMediaplayer::initMediaCacheService()
{
    // init cache service 
    vadp_shell_mediaplayer_cache_init_srv(m_songCountMenu);
    vadp_shell_mediaplayer_cache_set_index(m_highlightIndex);
	return VAPP_SHELL_MEDIAPLAYER_RES_OK;
}

ShellMediaplayerResEnum VappShellMediaplayer::deinitMediaCacheService()
{
    vadp_shell_mediaplayer_deinit_cache_srv();
    vadp_shell_mediaplayer_unregister_cache_callback();      
	return VAPP_SHELL_MEDIAPLAYER_RES_OK;
}


VfxBool VappShellMediaplayer::isEnterView()
{
    return m_isEnterView;
}

VappShellMediaplayer::VappShellMediaplayerSrvStateEnum VappShellMediaplayer::getSrvState()
{
    return m_initService;
}

VfxS32 VappShellMediaplayer::getSongCount()
{
    return m_songCount;
}

VfxS32 VappShellMediaplayer::getSongCountMenu()
{
    return m_songCountMenu;
}

void VappShellMediaplayer::setIndex(VfxS32 index)
{
    m_highlightIndex = index;
}


VfxBool VappShellMediaplayer::isNext()
{
    return m_isNext;
}

void VappShellMediaplayer::setIsNext(VfxBool isNext)
{
    m_isNext = isNext;
}

VfxS32 VappShellMediaplayer::getLastIndex()
{
    return m_preIndex;
}


void VappShellMediaplayer::setLastIndex(VfxS32 i)
{
    m_preIndex = i;
}

VfxS32 VappShellMediaplayer::index()
{
    return m_highlightIndex;
}

VfxS32 VappShellMediaplayer::next()
{
    m_preIndex = m_highlightIndex;
    m_highlightIndex = vadp_shell_mediaplayer_player_next();
    return m_highlightIndex;
}

VfxS32 VappShellMediaplayer::prev()
{
    m_preIndex = m_highlightIndex;
    m_highlightIndex = vadp_shell_mediaplayer_player_previous();
    return m_highlightIndex;
}

void VappShellMediaplayer::onStatusChanged(void* resultP)
{
    vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_STATE,&m_playerState);
       
    //VFX_TRACE("onStatusChange %d",resultP);

    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONSTATUSCHANGED,m_state, m_playerState);

    if (m_state == STATE_TAPTOSTOP && m_playerState == VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_INIT)
    {
        vadp_shell_mediaplayer_player_get_info(VADP_SHELL_MEDIAPLAYER_PLAYER_INFO_DURATION,&m_durationMsec);
        vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_PLAYTIME,&m_currTimeMsec);

        if (m_currTimeMsec> m_durationMsec)
            m_durationMsec = m_currTimeMsec;

        //if (m_viewMode == MAIN_SCREEN_VIEW)
        {
            m_mainScreen->onStatusChanged(VAPP_SHELL_MEDIPALAYER_STATU_PLAY_TO_IDLE);
        }
        //else
        {    
            m_menuFrame->m_menu->onStatusChanged(VAPP_SHELL_MEDIPALAYER_STATU_PLAY_TO_IDLE);
        }
        m_state = STATE_IDLE; 
    }
    else if (m_state == STATE_IDLE && (m_playerState == VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_PLAY || m_playerState == VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_PROCESS))
    {
        m_state = STATE_PLAYING;         
        //if (m_viewMode == MAIN_SCREEN_VIEW)
        {
            m_mainScreen->onStatusChanged(VAPP_SHELL_MEDIPALAYER_STATU_IDLE_TO_PLAY);
        }
        //else
        {    
            m_menuFrame->m_menu->onStatusChanged(VAPP_SHELL_MEDIPALAYER_STATU_IDLE_TO_PLAY);
        }
    }

    if(m_state != STATE_TAPTOPLAY)
    {
        m_forceToPlay = VFX_FALSE;
    }
    
}

void VappShellMediaplayer::onMediaChanged(void* resultP)
{
    //VFX_TRACE("onMediaChange %d",resultP);
    m_highlightIndex = vadp_shell_mediaplayer_get_active_index();

    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONMEDIACHANGED,m_state, m_highlightIndex);

    // ignore when we force to change 
    if (m_state == STATE_TAPTOPLAY || m_forceToPlay == VFX_TRUE)
    {
        // need to update cell to disable some content on panel.
        m_menuFrame->m_menu->onMediaChanged(resultP);
        //g_tapToPlay = VFX_FALSE;
        m_forceToPlay = VFX_FALSE;
        return;
    }

    m_mainScreen->onMediaChanged(resultP);
    m_menuFrame->m_menu->onMediaChanged(resultP);
}

void VappShellMediaplayer::onPlayEnd(void* resultP)
{
    //VFX_TRACE("onPlayEnd %d",resultP);

    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONPLAYEND,m_viewMode);

    m_currTimeMsec = m_durationMsec;  	

    if (m_viewMode == MAIN_SCREEN_VIEW)
    {
        m_mainScreen->onPlayEnd(resultP);
    }
    else
    {
        m_menuFrame->m_menu->onPlayEnd(resultP);
    }

}

void VappShellMediaplayer::onListEnd(void* resultP)
{
    //VFX_TRACE("onListEnd %d",resultP);
    m_state = STATE_IDLE;

    VFX_LOG(VFX_INFO2, VAPP_SHELL_MEDIAPLAYER_ONLISTEND,m_viewMode);

    if (m_viewMode == MAIN_SCREEN_VIEW)
    {
        m_mainScreen->onListEnd(resultP);
    }
    else
    {
        m_menuFrame->m_menu->onListEnd(resultP);
    }
}

void VappShellMediaplayer::onListChange(void)
{
}

void VappShellMediaplayer::onListChange(void* user_data)
{
    VappShellMediaplayer* this_ptr = (VappShellMediaplayer*) user_data;
    VfxObjWeakPtr weak_ptr = this_ptr;

    VfxU8 playerState;
    vadp_shell_mediaplayer_player_get_info(VADP_SEHLL_MEDIAPLAYER_PLAYER_INFO_CURRENT_STATE,&playerState);

    //if (playerState != VADP_SHELL_MEDIAPLAYER_PLAYER_STATE_INIT)
    //{
    //    vadp_shell_mediaplayer_player_pause();
    //}
    
    if (weak_ptr!=NULL)
    {
        this_ptr->onListChange();
    }
}

void VappShellMediaplayer::setViewMode(VfxS32 viewMode)
{
    m_viewMode = viewMode;
}

VfxS32 VappShellMediaplayer::getViewMode()
{
    return m_viewMode;
}


vadp_shell_mediaplayer_repeat_mode_enum VappShellMediaplayer::repeatMode()
{
    return m_repeatMode;
}

void VappShellMediaplayer::setRepeatMode(vadp_shell_mediaplayer_repeat_mode_enum  mode)
{
    m_repeatMode = mode;
}

VfxBool VappShellMediaplayer::isShuffle()
{
    return m_isShuffle;
}

void VappShellMediaplayer::setShuffle(VfxBool shuffle)
{
    m_isShuffle = shuffle;
}


#endif /* __MMI_VUI_SHELL_MEDIA_PLAYER__ */
