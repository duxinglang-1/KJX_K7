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
 *  vapp_atv_main.cpp
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
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#ifdef __MMI_ATV_SUPPORT__

#include "vapp_atv.h"
#include "vcp_global_popup.h"
#include "mmi_rp_vapp_atv_def.h"
#include "vapp_atv_osd.h"
#include "vapp_atv_gprot.h"
#include "vapp_gallery_gprot.h"
#include "vapp_atv_enum.h"

extern "C"
{
#include "nvram_common_defs.h"
#include "gdi_lcd.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_mtv.h"
#include "UcmSrvGProt.h"
#include "BthScoPathSrvGProt.h"
#include "USBSrvGprot.h"
#include "A2dpSrvGprot.h"

}

/*****************************************************************************
 * Main Page Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvMainPage", VappAtvMainPage, VfxPage);

VappAtvMainPage::VappAtvMainPage():
    m_app(NULL),
    m_signalImg(NULL),
    m_toolBar(NULL),
    m_wheelPanel(NULL),
#ifdef __MMI_ATV_PLAYER_SETTING__
    m_adjustBar(NULL),
#endif
    m_videoFrame(NULL),
    m_saveCfmPopup(NULL),
    m_savePathCfmPopup(NULL),
    m_scanProg(NULL),
    m_dispType(ATV_DISP_CTRL_PANEL),
    m_imgFrmRecStatus(NULL),
    m_textFrmRecTime(NULL),
#ifdef __MMI_ATV_RECORD__
    m_timerUpdateRecTime(NULL),
#endif
    m_recIndPopup(NULL),
    m_timerHide(NULL),
    m_timerKeyEvt(NULL),
#ifdef __MMI_ATV_THUMBNAIL__
    m_thumbBtn(NULL),
#else
    m_thumbImgFrame(NULL),
#endif
    m_vdoFrmPrepared(VFX_FALSE),
    m_qucikPreviewFrame(NULL),
    m_loadingPopup(NULL),  
	m_isImageThumb(MMI_TRUE)
{
#ifdef __MMI_ATV_RECORD__
    m_recBtn[REC_BTN_PAUSE_RECORD] = NULL;
    m_recBtn[REC_BTN_STOP] = NULL;
#endif
}

void VappAtvMainPage::onInit()
{
    VfxPage::onInit();

    setStatusBar(MMI_FALSE);
    setBgColor(VFX_COLOR_BLACK);

    // Get App
    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappAtvApp);

    //video frame
    VFX_OBJ_CREATE(m_videoFrame, VfxVideoFrame, this);
    m_videoFrame->setMultimediaType(VfxVideoFrame::MULTIMEDIA_MATV);
    m_videoFrame->setIsAnimation(VFX_FALSE);
    m_videoFrame->setBgColor(VFX_COLOR_BLACK);
    setVideoFramePosSize();

    m_videoFrame->setBuffer(getApp()->getGroupId());
    m_videoFrame->m_signalPlayReady.connect(this, &VappAtvMainPage::onVideoFramePrepared);

    // Signal icon
    VFX_OBJ_CREATE(m_signalImg, VfxImageFrame, this);
    m_signalImg->setResId(IMG_ID_VAPP_ATV_SIGNAL_LEVEL_0);
    m_signalImg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_signalImg->setPos(VAPP_ATV_SIGNAL_X, VAPP_ATV_SIGNAL_Y);

    //check mass storage mode
#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        m_app->m_massStorageMode = VFX_TRUE;
    }
#endif
    // ToolBar
    VFX_OBJ_CREATE(m_toolBar, VappAtvToolBar, this);
    m_toolBar->setAutoAnimate(VFX_TRUE);

    VfxImageFrame *imgFrame;
    VFX_OBJ_CREATE(imgFrame, VfxImageFrame, this);
    imgFrame->setResId(IMG_ID_VAPP_ATV_TBAR_BTN_SHOW);
#ifndef __MMI_ATV_SLIM__
    m_toolBar->setBounds(
        0, 0, VAPP_ATV_TBAR_HANDLE_X + imgFrame->getSize().width * 2, LCD_WIDTH);
#else
    m_toolBar->setBounds(
        0, 0, VAPP_ATV_TBAR_HANDLE_X + imgFrame->getSize().width * 2, LCD_WIDTH); // width should not changed , must be like this
#endif

    m_toolBar->m_signalImgBtnClicked.connect(this, &VappAtvMainPage::onToolBarButtonCliked);
    m_toolBar->m_signalDrag.connect(this, &VappAtvMainPage::onToolBarDrag);

    VFX_OBJ_CLOSE(imgFrame);


    // WheelPanel
    #ifndef __MMI_ATV_SLIM__
    VFX_OBJ_CREATE(m_wheelPanel, VappAtvWheelPanel, this);
	#else
	VFX_OBJ_CREATE(m_wheelPanel, VappAtvWheelPanelSlim, this);
	#endif
    m_wheelPanel->m_signalChangeChannel.connect(this, &VappAtvMainPage::onChangeChannel);
    m_wheelPanel->m_endScrolling.connect(this, &VappAtvMainPage::onWheelEndScroll);

#ifndef __MMI_ATV_SLIM__
    VFX_OBJ_CREATE(imgFrame, VfxImageFrame, this);
    imgFrame->setResId(IMG_ID_VAPP_ATV_WHEEL_BG);
    m_wheelPanel->setBounds(
        0, 0, imgFrame->getSize().width, LCD_WIDTH);
    m_wheelPanel->setPos(LCD_HEIGHT, 0);
	VFX_OBJ_CLOSE(imgFrame);
#else
	m_wheelPanel->setBounds(0, 0, VAPP_ATV_WHEEL_SLIM_BG_FRAME_WIDTH, VAPP_ATV_WHEEL_SLIM_BG_FRAME_HEIGHT);
	m_wheelPanel->setPos(LCD_HEIGHT, VAPP_ATV_WHEEL_SLIM_BG_Y);
#endif

    m_wheelPanel->setAutoAnimate(VFX_TRUE);

    // init anchor
    resetAnchor();

    //timer
    VFX_OBJ_CREATE(m_timerKeyEvt, VfxTimer, this);
}

void VappAtvMainPage::onDeinit()
{
    m_app->m_scrn->m_mainPage = NULL;
    VfxPage::onDeinit();
}

void VappAtvMainPage::onEntered()
{
	if(m_app->getKernelState() == ATV_KERNEL_CLOSING)
	{
		return;
	}
	
    m_videoFrame->prepare();
	mdi_audio_terminate_background_play();
	mdi_audio_suspend_background_play();
}

void VappAtvMainPage::onEnter(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_MAINPAGE_ON_ENTER, m_dispType);

	if(m_app->getKernelState() == ATV_KERNEL_CLOSING)
	{
		return;
	}
	
    // control panel
    if (m_dispType == ATV_DISP_CTRL_PANEL)
    {
        hideCtrlPanel(VFX_FALSE);
        startHideTimer();

#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        //when back from settingpage, close the setting page. Or else, it wil cause some fatal error.
        if(m_app->m_scrn->m_settingPage && isBackward)
        {
            m_app->m_scrn->m_settingPage->exit();
            m_app->m_scrn->m_settingPage = NULL;
        }
#endif
    }
    else
    {
        if (m_dispType != ATV_DISP_POPUP_CONFIRM)
        {
            hideCtrlPanel(VFX_TRUE);
        }
    }

    // display something
#ifdef __MMI_ATV_PLAYER_SETTING__
    if (m_dispType == ATV_DISP_PLAYER_SETTING)
    {
        if (m_adjustBar == NULL)
        {
            displayPlayerSetting();
        }
    }
    else 
#endif
    if (m_dispType == ATV_DISP_SCAN_PROG)
    {
        if (!m_scanProg)
        {
            displayScanProg();
        }
        else
        {
            // display scan again confirm
            m_scanProg->m_signal.connect(this, 
                &VappAtvMainPage::scanEvthandler);
            
        }
    }
    else if (m_dispType == ATV_DISP_AUD_MODE ||
             m_dispType == ATV_DISP_POPUP_CONFIRM)
    {
        // do nothing
    }
#if defined(__MMI_ATV_RECORD__) && defined (__MMI_ATV_THUMBNAIL__)
    else if (m_dispType == ATV_DISP_THUMBNAIL)
    {
    	if(m_app->m_massStorageMode)
    	{
    		if(m_thumbBtn != NULL)
    			closeThumb();
    	}
		else
		{
            if (m_thumbBtn == NULL)
            {
                getRecThumb();
            }
            else
            {
                startHideTimer();
            }
        }
    }
#endif
	else if(m_dispType == ATV_DISP_QUICK_PREVIEW)
	{
		getQuickPreview();
	}
#ifdef __MMI_ATV_RECORD__    
    else if (m_dispType == ATV_DISP_RECORDER)
    {
        ASSERT(0);
    }
    else if (m_dispType == ATV_DISP_RECORD_CONFIRM)
    {
    	if((m_app->m_setting.storage == SRV_FMGR_DRV_CARD_TYPE) && 
        (!srv_fmgr_drv_is_accessible(
         srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE))))
		{
			if(m_saveCfmPopup!=NULL)
			{
				m_saveCfmPopup->exit(VFX_TRUE);
	    		m_saveCfmPopup = NULL;
			}
			
			mdi_mtv_discard_unsaved_recording(m_app->m_mtvHandle);
            m_app->setRecorderState(ATV_RECORDER_STOPPED);

            //release component
            m_app->m_scrn->m_mainPage->closeRecComp();

            m_app->m_scrn->m_mainPage->showMdiFailConfirm(MDI_RES_MTV_ERR_SAVE_FAILED);
		}
		else
    	{
	        // if record btn is hidden, unhide
	        unhideRecordBtn();

	        // display save confirm after interrupt finished
	        if (m_saveCfmPopup == NULL &&
	            m_app->getRecorderState() == ATV_RECORDER_SAVE_CONFIRM)
	        {
	            displaySaveConfirm(MDI_RES_MTV_SUCCEED);
	        }
    	}
    }
#endif
}

void VappAtvMainPage::onExit(VfxBool isBackward)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_MAINPAGE_ON_EXIT, m_dispType);
    exitForeground();

    //stop initing service and stop player
    m_app->deInitDisplay(MMI_FALSE);

    m_videoFrame->unPrepare();
    m_vdoFrmPrepared = VFX_FALSE;

    if (m_dispType == ATV_DISP_SCAN_PROG)  //guo
    {
        if(m_scanProg!=NULL)
        {
             m_scanProg->m_signal.disconnect(this, 
                &VappAtvMainPage::scanEvthandler);
        }
    }    


}

void VappAtvMainPage::onBack()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_MAINPAGE_ON_BACK, m_dispType);
    
    if(m_dispType == ATV_DISP_PLAYER_SETTING)
    {
        m_app->setAdjustValue(
            m_app->m_setting.brightness,
            m_app->m_setting.contrast,
            m_app->m_setting.saturation);

#ifdef __MMI_ATV_PLAYER_SETTING__
        if(m_adjustBar!=NULL)
        {
            VFX_OBJ_CLOSE(m_adjustBar);
            m_adjustBar = NULL;
        }
#endif
        setDispType(ATV_DISP_CTRL_PANEL);
#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        m_signalChangePage.emit(PAGE_SETTING);
#endif
        return;
    }
        
    exitForeground();

    //avoid do something wrong in onExit()
    setDispType(ATV_DISP_CTRL_PANEL);

    //stop service and stop player
    m_app->deInitDisplay(MMI_TRUE);

    m_app->closeEngine();
    displayPleaseWait();
}

void VappAtvMainPage::setDispType(VAPP_ATV_DISP_TYPE_ENUM type)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_SET_DISP_TYPE, m_dispType, type);
    m_dispType = type;
}

void VappAtvMainPage::onVideoFramePrepared()
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_ON_FRAME_PREPARED, m_dispType);
    m_vdoFrmPrepared = VFX_TRUE;

    if (m_app->m_numServices == 0)
    {
        return;
    }

    VfxBool play = VFX_TRUE;
    if (m_dispType == ATV_DISP_SCAN_PROG 
		|| m_dispType == ATV_DISP_RECORD_CONFIRM 
        || m_dispType == ATV_DISP_POPUP_CONFIRM 
        || m_dispType == ATV_DISP_AUD_MODE
        || m_dispType == ATV_DISP_PATH_CONFIRM
        || m_dispType == ATV_DISP_QUICK_PREVIEW
        )
    {
        play = VFX_FALSE;
    }

    if (play)
    {
        m_app->initDisplay();
    }
}

void VappAtvMainPage::exitForeground()
{
    if (m_dispType == ATV_DISP_SCAN_PROG && m_scanProg->m_progPopup)
    {
        if (m_app->getKernelState() == ATV_KERNEL_SCANNING)
        {
            m_app->clearPageHighPriority();
            m_app->abortScanService();
        }
        VFX_OBJ_CLOSE(m_scanProg);
    }
#ifdef __MMI_ATV_RECORD__
    else if (m_dispType == ATV_DISP_RECORDER)
    {
        //stop record
        m_app->stopRecord();

        m_timerUpdateRecTime->stop();


        setDispType(ATV_DISP_RECORD_CONFIRM);
    }
#endif

    stopHideTimer();
    m_wheelPanel->stopChangeIndexTimer();
    m_timerKeyEvt->stop();
    m_wheelPanel->m_btnPressed = VFX_FALSE;

    //may can be removed
    m_wheelPanel->m_timerResetScrollIdx->stop();
}

void VappAtvMainPage::setVideoFramePosSize()
{
    VfxS32 x, y, width, height;

    getTVPosSize(&x, &y, &width, &height);
    m_videoFrame->setPos(x, y);
    m_videoFrame->setSize(width, height);
}

void VappAtvMainPage::resetAnchor()
{
    VfxFloat anchorX = (VfxFloat)m_toolBar->getBgWidth() / m_toolBar->getBounds().size.width;
    m_toolBar->setAnchor(anchorX, 0);
    m_toolBar->setAllFuncEnabled(VFX_FALSE);
    m_toolBar->m_btn->setImgId(IMG_ID_VAPP_ATV_TBAR_BTN_SHOW);  //should reset the button.
	#ifndef __MMI_ATV_SLIM__
	m_wheelPanel->setAnchor(1, 0);
	#else
    m_wheelPanel->setAnchor(1, 0);
	#endif
}

void VappAtvMainPage::onWheelEndScroll(VfxObject *object)
{
	if(m_dispType == ATV_DISP_RECORDER)
			return;

    if (!m_wheelPanel->m_btnPressed)
    {
        onChangeChannel(m_wheelPanel->m_targetChannel);
    }
}

void VappAtvMainPage::onChangeChannel(VfxU8 target_channel)
{
	if(m_dispType == ATV_DISP_RECORDER)
		return;
	
    ASSERT(target_channel < m_app->m_numServices);
    if (target_channel == m_app->m_setting.selected_channel)
    {
        return;
    }

    //stop channel
    m_app->deInitDisplay(VFX_TRUE);

    //update index
    m_app->m_setting.selected_channel = target_channel;
    clearVideoFrame();

    if (m_app->isActive() && isActive() && m_vdoFrmPrepared)
    {
        //start channel
        m_app->initDisplay();
    }
}


void VappAtvMainPage::clearVideoFrame(void)
{
    VfxU32 handle;

    handle = m_videoFrame->getLayerHandle();
    if (handle != GDI_NULL_HANDLE)
    {
        mdi_util_hw_layer_switch_to_sw_layer(handle);
        gdi_layer_push_and_set_active(handle);
        gdi_lcd_lock_mutex();
        gdi_waiting_blt_finish();
        gdi_layer_clear(GDI_COLOR_BLACK);
        if (gdi_layer_is_double(handle))
        {
            gdi_layer_toggle_double();
            gdi_layer_clear(GDI_COLOR_BLACK);
        }
        gdi_layer_pop_and_restore_active();
        gdi_lcd_unlock_mutex();
    }
}


void VappAtvMainPage::hideCtrlPanel(VfxBool hide)
{
    m_toolBar->setHidden(hide);

    if (hide)
    {
        m_wheelPanel->setAnchor(0, 0);
        VFX_OBJ_CLOSE(m_timerHide);
    }
    else
    {
        // Tbar shows
        if (m_toolBar->getAnchor().x == 0)
        {
            m_wheelPanel->setAnchor(0, 0);
        }
        else
        {
            m_wheelPanel->setAnchor(1, 0);
        }

        setDispType(ATV_DISP_CTRL_PANEL);
    }
}

VfxBool VappAtvMainPage::isWheelPanelShow()
{
    if (m_wheelPanel->getAnchor().x == 0)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}

#ifdef __MMI_ATV_PLAYER_SETTING__
void VappAtvMainPage::onAdjustBtnClicked()
{
    VFX_OBJ_CLOSE(m_adjustBar);
    setDispType(ATV_DISP_CTRL_PANEL);
}
#endif

void VappAtvMainPage::setSignalLevel(VfxS32 level)
{
    m_signalImg->setResId(IMG_ID_VAPP_ATV_SIGNAL_LEVEL_0 + level);
}


void VappAtvMainPage::onAudModeSelected(VfxObject* sender, VfxU32 index)
{
	if (m_vdoFrmPrepared)
    {
        //When display audio select popup, the TV is still playing, 
        //and lock->unluck, it should stop,
        //and when click the button, TV play again.
        m_app->initDisplay();
    }
	
    if(index==VCP_POPUP_BUTTON_NO_PRESSED)
    {
        setDispType(ATV_DISP_CTRL_PANEL);
        return;
    }
    
    VcpSelectPopup *audModePopup = (VcpSelectPopup*)sender;
    m_app->setAudMode(audModePopup->getFirstSeletedId());
    setDispType(ATV_DISP_CTRL_PANEL);

}


void VappAtvMainPage::displayAudModeList()
{
    vapp_srv_info_struct *infoPtr = m_app->getActiveSrv();
    VfxS32 idx, num;
    VfxBool selected;

    VfxU32 audMode[] =
    {
       MDI_ATV_MONO,
       MDI_ATV_MTS_STEREO,
       MDI_ATV_MTS_SAP,

       MDI_ATV_MPX_MONO,
       MDI_ATV_MPX_STEREO,
       MDI_ATV_MPX_SUB,
       MDI_ATV_MPX_MAIN_SUB,
       MDI_ATV_MPX_MAIN,

       MDI_ATV_FM_MONO,
       MDI_ATV_A2_STEREO,
       MDI_ATV_A2_DUAL1,
       MDI_ATV_A2_DUAL2,
       MDI_ATV_NICAM_MONO,
       MDI_ATV_NICAM_STEREO,
       MDI_ATV_NICAM_DUAL1,
       MDI_ATV_NICAM_DUAL2
    };

    
    VFX_OBJ_CREATE(m_audModePopup, VcpSelectPopup, this);
    m_audModePopup->setText(VFX_WSTR_RES(STR_ID_VAPP_ATV_AUD_MODE));
    m_audModePopup->setType(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK);

    num = sizeof(audMode)/sizeof(audMode[0]);
    for (idx = 0; idx < num; idx ++)
    {
        if ((infoPtr->supported_audio_mode & audMode[idx]) != 0)
        {
            if ((infoPtr->audio_mode & audMode[idx]) != 0)
            {
                selected = VFX_TRUE;
            }
            else
            {
                selected = VFX_FALSE;
            }

            m_audModePopup->addItem(
                audMode[idx],
                VFX_WSTR_RES(STR_ID_VAPP_ATV_AUD_MODE_MONO + idx),
                selected);

        }
    }

    m_audModePopup->m_signalButtonClicked.connect(this, &VappAtvMainPage::onAudModeSelected);
    m_audModePopup->show(VFX_TRUE);

    setDispType(ATV_DISP_AUD_MODE);
    hideCtrlPanel(VFX_TRUE);
}

VfxBool VappAtvMainPage::recordValidate()
{
#if defined(__MMI_BT_AUDIO_SUPPORT__)
    if (srv_btsco_is_sco_open())
    {
        // Display popup
        //Moidfy the global popup to VcpConfirmPopup.
        VcpConfirmPopup *cfmScoOpen;
        VFX_OBJ_CREATE(cfmScoOpen, VcpConfirmPopup, this);
        cfmScoOpen->setInfoType(VCP_POPUP_TYPE_FAILURE);        
        cfmScoOpen->setText(VFX_WSTR_RES(STR_ID_VAPP_ATV_BT_IS_WORKING));
        cfmScoOpen->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        cfmScoOpen->m_signalButtonClicked.connect(
            this, &VappAtvMainPage::onMdiFailCfmClicked);
        cfmScoOpen->setAutoDestory(VFX_TRUE);
        cfmScoOpen->show(VFX_TRUE);

        return VFX_FALSE;
    }
#endif // __MMI_BT_AUDIO_SUPPORT__
#if defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
    if (srv_a2dp_is_output_to_bt())
    {
        // Display popup
        //Moidfy the global popup to VcpConfirmPopup.
        VcpConfirmPopup *cfmA2dp;
        VFX_OBJ_CREATE(cfmA2dp, VcpConfirmPopup, this);
        cfmA2dp->setInfoType(VCP_POPUP_TYPE_FAILURE);        
        cfmA2dp->setText(VFX_WSTR_RES(STR_ID_VAPP_ATV_BT_IS_WORKING));
        cfmA2dp->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        cfmA2dp->m_signalButtonClicked.connect(
            this, &VappAtvMainPage::onMdiFailCfmClicked);
        cfmA2dp->setAutoDestory(VFX_TRUE);
        cfmA2dp->show(VFX_TRUE);
        
        /*vcp_global_popup_show_confirm_one_button_id(
            GRP_ID_ROOT, VCP_POPUP_TYPE_FAILURE,
            STR_ID_VAPP_ATV_BT_IS_WORKING,
            STR_GLOBAL_OK, VCP_POPUP_BUTTON_TYPE_NORMAL, NULL, NULL);*/
        return VFX_FALSE;
    }

#endif // defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)

	if(srv_ucm_is_any_call())
    {
        // Display popup
        VcpConfirmPopup *backgroundCall;
        VFX_OBJ_CREATE(backgroundCall, VcpConfirmPopup, this);
        backgroundCall->setInfoType(VCP_POPUP_TYPE_FAILURE);        
        backgroundCall->setText(VFX_WSTR_RES(STR_ID_VAPP_ATV_IS_BACKGROUND_CALL));
        backgroundCall->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        backgroundCall->m_signalButtonClicked.connect(
            this, &VappAtvMainPage::onMdiFailCfmClicked);
        backgroundCall->setAutoDestory(VFX_TRUE);
        backgroundCall->show(VFX_TRUE);
        return VFX_FALSE;
    }

    return VFX_TRUE;
}

#ifdef __MMI_ATV_PLAYER_SETTING__
void VappAtvMainPage::displayPlayerSetting()
{
    ASSERT(m_adjustBar == NULL);

    VFX_OBJ_CREATE(m_adjustBar, VappAtvAdjustBar, this);
    m_adjustBar->setPos(0, VAPP_ATV_ADJUST_BAR_Y);
    m_adjustBar->setSize(LCD_HEIGHT, LCD_WIDTH - VAPP_ATV_ADJUST_BAR_Y);
    m_adjustBar->m_signalBtnClicked.connect(this, &VappAtvMainPage::onAdjustBtnClicked);

}
#endif

#ifdef __MMI_ATV_RECORD__
void VappAtvMainPage::UpdateRecTimeCyclic(VfxTimer *timer)
{
    VfxWChar string[20];

    if (m_textFrmRecTime == NULL)
    {
        // text frame
        ASSERT(m_textFrmRecTime == NULL);
        VFX_OBJ_CREATE(m_textFrmRecTime, VfxTextFrame, this);

        kal_wsprintf(string, "%02d:%02d:%02d", 0, 0, 0);
        m_textFrmRecTime->setString(VFX_WSTR_MEM(string));
        m_textFrmRecTime->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        m_textFrmRecTime->setColor(VfxColor(255, TIME_COLOR, TIME_COLOR, TIME_COLOR));
        VfxFontDesc font(VFX_FONT_DESC_VF_SIZE(VAPP_ATV_REC_TIME_FONT_SIZE), VFX_FONT_DESC_EFFECT_BORDER);
        m_textFrmRecTime->setFont(font);
        m_textFrmRecTime->setPos(VfxPoint(VAPP_ATV_REC_TIME_X, VAPP_ATV_REC_TIME_Y));

        // timer
        ASSERT(m_timerUpdateRecTime == NULL);
        VFX_OBJ_CREATE(m_timerUpdateRecTime, VfxTimer, this);
        m_timerUpdateRecTime->setStartDelay(DELAY_UPDATE_REC);
        m_timerUpdateRecTime->m_signalTick.connect(this, &VappAtvMainPage::UpdateRecTimeCyclic);
        m_timerUpdateRecTime->start();

        m_recTotalSec = 0;
        m_recStartSec = VfxTimer::getCurrentSystemTime();
    }
    else
    {
        VfxMsec curTime, tmp;
        VfxS32 hour, min, sec;

        curTime = VfxTimer::getCurrentSystemTime();
        m_recTotalSec += (curTime - m_recStartSec);
        m_recStartSec = curTime;

        tmp = m_recTotalSec / 1000;
        sec = tmp % 60;
        tmp /= 60;
        min = tmp % 60;
        tmp /= 60;
        hour = tmp % 60;
        kal_wsprintf(string, "%02d:%02d:%02d", hour, min, sec);
        m_textFrmRecTime->setString(VFX_WSTR_MEM(string));

        // timer
        m_timerUpdateRecTime->start();
    }
}

void VappAtvMainPage::displayRecordBtn()
{
    MDI_RESULT ret;
    VfxS32 idx, height;

    VfxU16 posX[] =
    {
        VAPP_ATV_REC_LEFT_BTN_X,
        VAPP_ATV_REC_RIGHT_BTN_X
    };

    VfxU16 width[] =
    {
        VAPP_ATV_REC_LEFT_BTN_W,
        VAPP_ATV_REC_RIGHT_BTN_W
    };

    VfxU16 imgN[] =
    {
        IMG_ID_VAPP_ATV_REC_LEFT_BG_N,
        IMG_ID_VAPP_ATV_REC_RIGHT_BG_N
    };

    VfxU16 imgD[] =
    {
        IMG_ID_VAPP_ATV_REC_LEFT_BG_D,
        IMG_ID_VAPP_ATV_REC_RIGHT_BG_D
    };

    VfxU16 icon[] =
    {
        IMG_ID_VAPP_ATV_REC_PAUSE,
        IMG_ID_VAPP_ATV_REC_STOP
    };

    VfxId callbackId[] =
    {
        REC_BTN_PAUSE_RECORD,
        REC_BTN_STOP
    };

    if (!recordValidate())
    {
        return;
    }

    mdi_mtv_recorder_discard_recording(m_app->m_mtvHandle);//before record, discard unsaved recording.

    ret = m_app->startRecord();
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        showMdiFailConfirm(ret);
        return;
    }

    // draw record left, right button
    for (idx = 0; idx < REC_BTN_NUM; idx ++)
    {
        ASSERT(m_recBtn[idx] == NULL);
        VFX_OBJ_CREATE(m_recBtn[idx], VcpButton, this);
        m_recBtn[idx]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);

        VcpStateImage img(icon[idx], icon[idx], icon[idx], icon[idx]);
        m_recBtn[idx]->setImage(img);

        VcpStateImage imgBG(imgN[idx], imgD[idx], imgN[idx], imgN[idx]);
        m_recBtn[idx]->setBgImageList(imgBG);

        height = imgBG.getImageNormal().getSize().height;
        m_recBtn[idx]->setRect(VfxRect(posX[idx], VAPP_ATV_REC_BTN_Y, width[idx], height));
        m_recBtn[idx]->setId(callbackId[idx]);
        m_recBtn[idx]->m_signalClicked.connect(this, &VappAtvMainPage::onRecBtnClicked);
        m_recBtn[idx]->m_signalStateChanged.connect(this, &VappAtvMainPage::onRecBtnStateChanged);
    }

    // record status
    ASSERT(m_imgFrmRecStatus == NULL);
    VFX_OBJ_CREATE(m_imgFrmRecStatus, VfxImageFrame, this);
    m_imgFrmRecStatus->setResId(IMG_ID_VAPP_ATV_REC_STATUS);
    m_imgFrmRecStatus->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_imgFrmRecStatus->setPos(VAPP_ATV_REC_STATUS_X, VAPP_ATV_REC_STATUS_Y);

    // record time
    UpdateRecTimeCyclic(NULL);

    setDispType(ATV_DISP_RECORDER);
    hideCtrlPanel(VFX_TRUE);

    startHideTimer();
}
#endif

void VappAtvMainPage::startHideTimer(void)
{
    if (m_dispType != ATV_DISP_CTRL_PANEL 
		&& m_dispType != ATV_DISP_RECORDER 
#ifdef __MMI_ATV_THUMBNAIL__		
        && m_dispType != ATV_DISP_THUMBNAIL
#endif
		&& m_dispType != ATV_DISP_QUICK_PREVIEW
        )
    {
        return;
    }

    if (m_timerHide)
    {
        m_timerHide->stop();
    }
    else
    {
        ASSERT(m_timerHide == NULL);
        VFX_OBJ_CREATE(m_timerHide, VfxTimer, this);

        m_timerHide->m_signalTick.connect(
            this, &VappAtvMainPage::hideIconTimeout);
    }
	
	if(m_dispType==ATV_DISP_QUICK_PREVIEW)
    	m_timerHide->setStartDelay(QUICK_PREVIEW);
	else
    	m_timerHide->setStartDelay(DELAY_HIDE);
	
    m_timerHide->start();
}

void VappAtvMainPage::hideIconTimeout(VfxTimer *timer)
{
    VFX_OBJ_CLOSE(m_timerHide);

    if (m_dispType == ATV_DISP_CTRL_PANEL)
    {
        hideCtrlPanel(VFX_TRUE);
    }
#ifdef __MMI_ATV_RECORD__
    else if (m_dispType == ATV_DISP_RECORDER)
    {
        if (m_recBtn[REC_BTN_PAUSE_RECORD] != NULL)
        {
            m_recBtn[REC_BTN_PAUSE_RECORD]->setHidden(VFX_TRUE);
            m_recBtn[REC_BTN_STOP]->setHidden(VFX_TRUE);
        }
    }
#endif
#ifdef __MMI_ATV_THUMBNAIL__    
    else if (m_dispType == ATV_DISP_THUMBNAIL)
    {
        closeThumb();
    }
#endif
	else if (m_dispType == ATV_DISP_QUICK_PREVIEW)
    {
    	VFX_OBJ_CLOSE(m_qucikPreviewFrame);
		m_qucikPreviewFrame = NULL;
		
		m_app->initDisplay();
		
#ifdef __MMI_ATV_THUMBNAIL__ 
		if(!( (m_app->m_setting.storage == SRV_FMGR_DRV_CARD_TYPE) && 
			(!srv_fmgr_drv_is_accessible(
			 srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE))) ) )
		{
			m_isImageThumb = MMI_TRUE;

			VfxImageSrc thumbImgSrc;
	    	thumbImgSrc = VfxImageSrc(VFX_WSTR_MEM(m_storagePath));
	    	displayThumb(&thumbImgSrc);
		}
#else
    	setDispType(ATV_DISP_CTRL_PANEL);
		hideCtrlPanel(VFX_FALSE);
		startHideTimer();
#endif
    }
    else
    {
        ASSERT(0);
    }


}


void VappAtvMainPage::stopHideTimer()
{
    if (m_timerHide)
    {
        m_timerHide->stop();
        VFX_OBJ_CLOSE(m_timerHide);
        m_timerHide = NULL;
    }
}

#ifdef __MMI_ATV_RECORD__
void VappAtvMainPage::unhideRecordBtn()
{
    if (m_recBtn[REC_BTN_PAUSE_RECORD] != NULL &&
        m_recBtn[REC_BTN_PAUSE_RECORD]->getHidden())
    {
        m_recBtn[REC_BTN_PAUSE_RECORD]->setHidden(VFX_FALSE);
        m_recBtn[REC_BTN_STOP]->setHidden(VFX_FALSE);
    }
}

void VappAtvMainPage::displaySaveConfirm(MDI_RESULT ret)
{
    stopHideTimer();
    m_timerUpdateRecTime->stop();

    ASSERT(m_saveCfmPopup == NULL);
    VFX_OBJ_CREATE(m_saveCfmPopup, VcpConfirmPopup, this);

    m_saveCfmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);

    if (ret == MDI_RES_MTV_SUCCEED)
    {
        m_saveCfmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_ATV_SAVE_RECORD_ASK));
    }
    else
    {
        mmi_event_notify_enum popup_type;
        MMI_ID_TYPE string_id;
        string_id = mdi_util_get_mdi_error_info(ret, &popup_type);
        mmi_ucs2cpy((CHAR *)m_saveCfmStr, GetString(string_id));
        mmi_ucs2cat((CHAR *)m_saveCfmStr, (CHAR *)L". ");
        mmi_ucs2cat((CHAR *)m_saveCfmStr, GetString(STR_ID_VAPP_ATV_SAVE_RECORD_ASK));

        m_saveCfmPopup->setText(VFX_WSTR_MEM(m_saveCfmStr));
    }

    m_saveCfmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_USER_DEFINE);
    m_saveCfmPopup->setCustomButton(
        VFX_WSTR_RES(STR_GLOBAL_SAVE),
        VFX_WSTR_RES(STR_GLOBAL_CANCEL),
        VCP_POPUP_BUTTON_TYPE_NORMAL,
        VCP_POPUP_BUTTON_TYPE_CANCEL);
    m_saveCfmPopup->m_signalButtonClicked.connect(
        this, &VappAtvMainPage::onSaveRecCfmClicked);
    m_saveCfmPopup->show(VFX_TRUE);

    setDispType(ATV_DISP_RECORD_CONFIRM);
}

void VappAtvMainPage::onSaveRecCfmClicked(VfxObject* sender, VfxU32 id)
{
    if(id==VCP_POPUP_BUTTON_NO_PRESSED)
        return;
    
    m_saveCfmPopup->exit(VFX_TRUE);
    m_saveCfmPopup = NULL;

    ASSERT(m_recIndPopup == NULL);

    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_USER_1:

            MDI_RESULT ret;
            ret = m_app->saveRecord(m_storagePath);
            if (ret != MDI_RES_MTV_SUCCEED)
            {
                //reset recorder
                mdi_mtv_discard_unsaved_recording(m_app->m_mtvHandle);
                m_app->setRecorderState(ATV_RECORDER_STOPPED);

                //release component
                closeRecComp();

                showMdiFailConfirm(ret);
                return;
            }

            VFX_OBJ_CREATE(m_recIndPopup, VcpIndicatorPopup, this);
            m_recIndPopup->setText(VFX_WSTR_RES(STR_GLOBAL_SAVING));

            break;
        case VCP_CONFIRM_POPUP_BUTTON_USER_2:
            m_app->discardRecord();

            VFX_OBJ_CREATE(m_recIndPopup,VcpIndicatorPopup,this);
            m_recIndPopup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));

            break;
    }

    m_recIndPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_recIndPopup->setAutoDestory(VFX_FALSE);
    m_recIndPopup->show(VFX_TRUE);
}
#endif

void VappAtvMainPage::displaySavePathCfm(VfxBool isRecorded)
{
    if((m_app->m_setting.storage == SRV_FMGR_DRV_CARD_TYPE) && 
        (!srv_fmgr_drv_is_accessible(
         srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE))))
    {
#ifdef __MMI_ATV_STORAGE_SELECT__
        ASSERT(m_savePathCfmPopup == NULL);
        VFX_OBJ_CREATE(m_savePathCfmPopup, VcpConfirmPopup, this);
        m_savePathCfmPopup->setText(VFX_WSTR_RES(STR_ID_VAPP_ATV_SAVE_PATH_CONFIRM));
        m_savePathCfmPopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
        m_savePathCfmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
        if(isRecorded)
        {
		#ifdef __MMI_ATV_RECORD__
            m_savePathCfmPopup->m_signalButtonClicked.connect(
                this, &VappAtvMainPage::onRecordSavePathCfm);
		#endif
        }
        else
        {
            m_savePathCfmPopup->m_signalButtonClicked.connect(
                this, &VappAtvMainPage::onSnapshotSavePathCfm);
        }
        m_savePathCfmPopup->show(VFX_TRUE);
        
		setDispType(ATV_DISP_PATH_CONFIRM);
		hideCtrlPanel(VFX_TRUE);
#else		
	VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
	balloon->addItem(IMG_GLOBAL_INFO, VFX_WSTR_RES(STR_ID_VAPP_ATV_NOTIFY_INSERT_MEMORY_CARD));
#endif
    }
    else
    {
        if(isRecorded)
        {
#ifdef __MMI_ATV_RECORD__
            displayRecordBtn();
#endif
        }
        else
            getImgThumb();
    }

}

#ifdef __MMI_ATV_RECORD__
void VappAtvMainPage::onRecordSavePathCfm(VfxObject* sender, VfxU32 id)
{
	if(id==VCP_POPUP_BUTTON_NO_PRESSED)
        return;

    m_savePathCfmPopup->exit(VFX_TRUE);
    m_savePathCfmPopup = NULL;
    
    setDispType(ATV_DISP_CTRL_PANEL);
	
	if (m_vdoFrmPrepared)
    {
        //When display path confirm popup, the TV is still playing, 
        //and lock->unluck, it should stop,
        //and when click the button, TV play again.
        m_app->initDisplay();
    }
	
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_YES:
		#ifdef __MMI_ATV_STORAGE_SELECT__
            m_app->setStorage(SRV_FMGR_DRV_PHONE_TYPE);
		#endif
            displayRecordBtn();
            break;
        case VCP_CONFIRM_POPUP_BUTTON_NO:
            //don't change storage, do nothing
            break;
    }
}
#endif

void VappAtvMainPage::onSnapshotSavePathCfm(VfxObject* sender, VfxU32 id)
{
	if(id==VCP_POPUP_BUTTON_NO_PRESSED)
        return;
	
    m_savePathCfmPopup->exit(VFX_TRUE);
    m_savePathCfmPopup = NULL;
    
    setDispType(ATV_DISP_CTRL_PANEL);
	
    if (m_vdoFrmPrepared)
    {
        //When display path confirm popup, the TV is still playing, 
        //and lock->unluck, it should stop,
        //and when click the button, TV play again.
        m_app->initDisplay();
    }
	
    switch (id)
    {
        case VCP_CONFIRM_POPUP_BUTTON_YES:
		#ifdef __MMI_ATV_STORAGE_SELECT__
            m_app->setStorage(SRV_FMGR_DRV_PHONE_TYPE);
		#endif
            getImgThumb();
            break;
        case VCP_CONFIRM_POPUP_BUTTON_NO:
            //don't change storage, do nothing
            break;
    }
}


#ifdef __MMI_ATV_RECORD__
void VappAtvMainPage::closeRecComp()
{
    // release object
    VFX_OBJ_CLOSE(m_imgFrmRecStatus);
    VFX_OBJ_CLOSE(m_textFrmRecTime);
    VFX_OBJ_CLOSE(m_timerUpdateRecTime);

    VFX_OBJ_CLOSE(m_recIndPopup);
    //m_recIndPopup->exit(VFX_TRUE);
    //m_recIndPopup = NULL;

    VFX_OBJ_CLOSE(m_recBtn[REC_BTN_PAUSE_RECORD]);
    VFX_OBJ_CLOSE(m_recBtn[REC_BTN_STOP]);

    stopHideTimer();
}

void VappAtvMainPage::finalizeRec(VfxBool preview)
{
    //release component
    closeRecComp();

    if (m_app->isActive() && isActive())
    {
        if (preview)
        {
        #ifdef	__MMI_ATV_THUMBNAIL__
            getRecThumb();
		#endif
        }
        else
        {
            setDispType(ATV_DISP_CTRL_PANEL);
        }

        //Start player
        if (m_vdoFrmPrepared)
        {
            m_app->initDisplay();
        }
    }
    else
    {
        if (preview)
        {
        #ifdef	__MMI_ATV_THUMBNAIL__
            setDispType(ATV_DISP_THUMBNAIL);
		#endif
        }
        else
        {
            setDispType(ATV_DISP_CTRL_PANEL);
        }
    }
}
#endif

VfxBool VappAtvMainPage::isClicked(VfxPoint &a, VfxPoint &b)
{
    if (vfxAbs(a.x - b.x) < CLICK_DIST && vfxAbs(a.y - b.y) < CLICK_DIST)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}

VfxBool VappAtvMainPage::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {

    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP ||
             event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        if (isClicked(event.pos, event.downPos))
        {
            if (m_dispType == ATV_DISP_CTRL_PANEL)
            {
                if (m_toolBar->getHidden())
                {
                    hideCtrlPanel(VFX_FALSE);
                }
                else
                {
                    hideCtrlPanel(VFX_TRUE);
                }
            }
		#ifdef __MMI_ATV_RECORD__
            else if (m_dispType == ATV_DISP_RECORDER)
            {
                unhideRecordBtn();
            }
		#endif
		#ifdef	__MMI_ATV_THUMBNAIL__
            else if (m_dispType == ATV_DISP_THUMBNAIL)
            {
                closeThumb();
            }
		#endif
        }
        else if (vfxAbs(event.pos.x - event.downPos.x) >
                 vfxAbs(event.pos.y - event.downPos.y))
        {
        	if(m_dispType == ATV_DISP_QUICK_PREVIEW || m_dispType == ATV_DISP_THUMBNAIL) // when quick preview,do nothing
        	{
				return VFX_TRUE;
        	}
			
            if (event.pos.x - event.downPos.x > STROKE_DIST)
            {
	            hideCtrlPanel(VFX_TRUE);
				
                if (m_dispType == ATV_DISP_CTRL_PANEL)
                {
                    keyRightHdlr();
                }
            }
            else if (event.downPos.x - event.pos.x > STROKE_DIST)
            {
            	hideCtrlPanel(VFX_TRUE);
				
                if (m_dispType == ATV_DISP_CTRL_PANEL)
                {
                    keyLeftHdlr();
                }
            }
        }


    }
    return VFX_TRUE;
}

void VappAtvMainPage::keyLeftHdlr()
{
    if (m_toolBar->getHidden())
    {
        m_wheelPanel->decChannelIndex(VFX_TRUE);
    }
    else
    {
        m_wheelPanel->decChannelIndex(VFX_TRUE);//VFX_FALSE
    }
}

void VappAtvMainPage::keyRightHdlr()
{
    if (m_toolBar->getHidden())
    {
        m_wheelPanel->incChannelIndex(VFX_TRUE);
    }
    else
    {
        m_wheelPanel->incChannelIndex(VFX_TRUE); //VFX_FALSE
    }
}

void VappAtvMainPage::keyLeftRepeatTimeout(VfxTimer *timer)
{
    keyLeftHdlr();

    m_timerKeyEvt->setStartDelay(DELAY_KEY_REPEAT);
    m_timerKeyEvt->start();
}

void VappAtvMainPage::keyRightRepeatTimeout(VfxTimer *timer)
{
    keyRightHdlr();

    m_timerKeyEvt->setStartDelay(DELAY_KEY_REPEAT);
    m_timerKeyEvt->start();
}

void VappAtvMainPage::keyUpLongPressTimeout(VfxTimer *timer)
{
#ifndef __MMI_ATV_SLIM__
    m_wheelPanel->wheelBtnLongPressHdlr(VappAtvWheelPanel::BTN_UP);
#else
	m_wheelPanel->wheelBtnLongPressHdlr(VappAtvWheelPanelSlim::BTN_UP);
#endif
}

void VappAtvMainPage::keyDownLongPressTimeout(VfxTimer *timer)
{
#ifndef __MMI_ATV_SLIM__
    m_wheelPanel->wheelBtnLongPressHdlr(VappAtvWheelPanel::BTN_DOWN);
#else
	m_wheelPanel->wheelBtnLongPressHdlr(VappAtvWheelPanelSlim::BTN_DOWN);
#endif
}


void VappAtvMainPage::disconnectKeyTimeoutAll()
{
    m_timerKeyEvt->m_signalTick.disconnect(
        this, &VappAtvMainPage::keyLeftRepeatTimeout);
    m_timerKeyEvt->m_signalTick.disconnect(
        this, &VappAtvMainPage::keyRightRepeatTimeout);
    m_timerKeyEvt->m_signalTick.disconnect(
        this, &VappAtvMainPage::keyUpLongPressTimeout);
    m_timerKeyEvt->m_signalTick.disconnect(
        this, &VappAtvMainPage::keyDownLongPressTimeout);
}

void VappAtvMainPage::handleKeyEvt(KEY_CODE_ENUM code, VfxKeyEventTypeEnum type)
{
    switch (type)
    {
        case VFX_KEY_EVENT_TYPE_DOWN:
            disconnectKeyTimeoutAll();
            if (code == ARROW_LEFT)
            {
                keyLeftHdlr();
                m_timerKeyEvt->m_signalTick.connect(
                    this, &VappAtvMainPage::keyLeftRepeatTimeout);
            }
            else if (code == ARROW_RIGHT)
            {
                keyRightHdlr();
                m_timerKeyEvt->m_signalTick.connect(
                    this, &VappAtvMainPage::keyRightRepeatTimeout);
            }
            else if (code == ARROW_UP)
            {
            	#ifndef __MMI_ATV_SLIM__
                m_wheelPanel->wheelBtnDownHdlr(VappAtvWheelPanel::BTN_UP);
				#else

				#endif
                m_timerKeyEvt->m_signalTick.connect(
                    this, &VappAtvMainPage::keyUpLongPressTimeout);
            }
            else if (code == ARROW_DOWN)
            {
            	#ifndef __MMI_ATV_SLIM__
                m_wheelPanel->wheelBtnDownHdlr(VappAtvWheelPanel::BTN_DOWN);
				#else

				#endif
                m_timerKeyEvt->m_signalTick.connect(
                    this, &VappAtvMainPage::keyDownLongPressTimeout);
            }
            m_wheelPanel->m_btnPressed = VFX_TRUE;

            m_timerKeyEvt->setStartDelay(DELAY_KEY_LONG_PRESS);
            m_timerKeyEvt->start();

            // stop panel hide
            stopHideTimer();
            break;
        case VFX_KEY_EVENT_TYPE_UP:
            if (code == ARROW_UP)
            {
            	#ifndef __MMI_ATV_SLIM__
                m_wheelPanel->wheelBtnUpHdlr(VappAtvWheelPanel::BTN_UP);
				#else

				#endif
            }
            else if (code == ARROW_DOWN)
            {
            	#ifndef __MMI_ATV_SLIM__
                m_wheelPanel->wheelBtnUpHdlr(VappAtvWheelPanel::BTN_DOWN);
				#else

				#endif
            }

            m_timerKeyEvt->stop();
            m_wheelPanel->m_btnPressed = VFX_FALSE;

            // start panel hide
            startHideTimer();
            break;

        default:
            break;
    }
}


VfxBool VappAtvMainPage::onKeyInput(VfxKeyEvent &event)
{
	if(m_dispType == ATV_DISP_QUICK_PREVIEW) // when quick preview,do nothing
		return VfxPage::onKeyInput(event);
	
    switch (event.keyCode)
    {
        case VFX_KEY_CODE_ARROW_UP:
            hideCtrlPanel(VFX_TRUE);
			
                handleKeyEvt(ARROW_UP, event.type);
                return VFX_TRUE;
            //break;

        case VFX_KEY_CODE_ARROW_DOWN:
            hideCtrlPanel(VFX_TRUE);
			
                handleKeyEvt(ARROW_DOWN, event.type);
                return VFX_TRUE;
           // break;

        case VFX_KEY_CODE_ARROW_LEFT:
			hideCtrlPanel(VFX_TRUE);
			
            if (m_dispType == ATV_DISP_CTRL_PANEL)
            {
                handleKeyEvt(ARROW_LEFT, event.type);
                return VFX_TRUE;
            }
			else if(m_dispType == ATV_DISP_THUMBNAIL)
			{
				startHideTimer();
			}
            break;
        case VFX_KEY_CODE_ARROW_RIGHT:
			hideCtrlPanel(VFX_TRUE);
			
            if (m_dispType == ATV_DISP_CTRL_PANEL)
            {
                handleKeyEvt(ARROW_RIGHT, event.type);
                return VFX_TRUE;
            }
			else if(m_dispType == ATV_DISP_THUMBNAIL)
			{
				startHideTimer();
			}

            break;
        default:
            break;
    }

    return VfxPage::onKeyInput(event);
}

VfxBool VappAtvMainPage::onPreviewPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
    	if(m_dispType!=ATV_DISP_QUICK_PREVIEW)
        	stopHideTimer();
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP ||
             event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
    	if(m_dispType!=ATV_DISP_QUICK_PREVIEW)
        	startHideTimer();
    }

    return VFX_FALSE;
}

#ifdef __MMI_ATV_RECORD__
void VappAtvMainPage::onRecBtnStateChanged(VfxObject* sender, VfxId id, VcpButtonStateEnum state)
{

}

void VappAtvMainPage::onRecBtnClicked(VfxObject *sender, VfxId Id)
{
    switch(Id)
    {
        case REC_BTN_PAUSE_RECORD:
            switchRecordBtn();
            break;

        case REC_BTN_STOP:
            m_app->stopRecord();
            m_app->deInitDisplay(VFX_FALSE);

            displaySaveConfirm(MDI_RES_MTV_SUCCEED);
            break;
        default:
            ASSERT(0);
    }
}

void VappAtvMainPage::switchRecordBtn()
{
    MDI_RESULT ret;
    if (m_app->getRecorderState() == ATV_RECORDER_RECORD)
    {
        ret = m_app->pauseRecord();
        if(ret == MDI_RES_MTV_SUCCEED)
        {
            m_timerUpdateRecTime->stop();

            // update total time
            VfxMsec curTime;
            curTime = VfxTimer::getCurrentSystemTime();
            m_recTotalSec += (curTime - m_recStartSec);

            //change icon from pause to record
            VcpStateImage SI(
                IMG_ID_VAPP_ATV_REC_START,
                IMG_ID_VAPP_ATV_REC_START,
                IMG_ID_VAPP_ATV_REC_START,
                IMG_ID_VAPP_ATV_REC_START);
            m_recBtn[REC_BTN_PAUSE_RECORD]->setImage(SI);
            m_imgFrmRecStatus->setResId(IMG_ID_VAPP_ATV_REC_PAUSE_STATUS);
        }
    }
    else if (m_app->getRecorderState() == ATV_RECORDER_PAUSED)
    {
        ret = m_app->resumeRecord();

        if (ret != MDI_RES_MTV_SUCCEED)
        {
            m_app->stopRecord();
            m_app->deInitDisplay(VFX_FALSE);


            // Todo: display ret error
            displaySaveConfirm(ret);

            return;
        }

        //change icon from record to pause
        VcpStateImage SI(
                IMG_ID_VAPP_ATV_REC_PAUSE,
                IMG_ID_VAPP_ATV_REC_PAUSE,
                IMG_ID_VAPP_ATV_REC_PAUSE,
                IMG_ID_VAPP_ATV_REC_PAUSE);
        m_recBtn[REC_BTN_PAUSE_RECORD]->setImage(SI);
        m_imgFrmRecStatus->setResId(IMG_ID_VAPP_ATV_REC_STATUS);

        // update start time
        m_recStartSec = VfxTimer::getCurrentSystemTime();
        UpdateRecTimeCyclic(NULL);
    }

}
#endif

#ifdef __MMI_ATV_THUMBNAIL__
void VappAtvMainPage::onThumbBtnClicked()
{
    vapp_gallery_image_viewer_launch_option_struct option;
    vapp_gallery_image_viewer_launch_option_init(&option);

	option.content_is_image = m_isImageThumb;

    vapp_gallery_image_viewer_launch(m_storagePath, &option);

    closeThumb();
}

void VappAtvMainPage::closeThumb()
{
    VFX_OBJ_CLOSE(m_thumbBtn);
    setDispType(ATV_DISP_CTRL_PANEL);
}

void VappAtvMainPage::displayThumb(VfxImageSrc *imgSrc)
{
	if((m_app->m_setting.storage == SRV_FMGR_DRV_CARD_TYPE) && 
		(!srv_fmgr_drv_is_accessible(
		 srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE))))
	{
		return;
	}
	
    ASSERT(m_thumbBtn == NULL);
    VFX_OBJ_CREATE_EX(m_thumbBtn, VappAtvThumbButton, this, (imgSrc));
    m_thumbBtn->setAnchor(0.5, 0.5);
    m_thumbBtn->setPos(VAPP_ATV_THUMBNAIL_X, VAPP_ATV_THUMBNAIL_Y);
    m_thumbBtn->m_signalClicked.connect(this, &VappAtvMainPage::onThumbBtnClicked);

    setDispType(ATV_DISP_THUMBNAIL);
    hideCtrlPanel(VFX_TRUE);
    startHideTimer();
}
#endif 
void VappAtvMainPage::getImgThumb()
{
    MDI_RESULT ret;
    VcpStateImage SI;

    ret = m_app->getSnapshot(m_videoFrame->getLayerHandle(), m_storagePath);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        showMdiFailConfirm(ret);
        return;
    }
	hideCtrlPanel(VFX_TRUE);
	getQuickPreview();
}

void VappAtvMainPage::getQuickPreview()
{
	if(((m_app->m_setting.storage == SRV_FMGR_DRV_CARD_TYPE) && 
	(!srv_fmgr_drv_is_accessible(
	 srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE))) )||
	 m_app->m_massStorageMode)
	{
		VFX_OBJ_CLOSE(m_timerHide);
		VFX_OBJ_CLOSE(m_qucikPreviewFrame);
		setDispType(ATV_DISP_CTRL_PANEL);
		return;
	}
	
    VfxImageSrc thumbImgSrc;
    thumbImgSrc = VfxImageSrc(VFX_WSTR_MEM(m_storagePath));
	
	if(m_qucikPreviewFrame==NULL)
	{
		VFX_OBJ_CREATE(m_qucikPreviewFrame, VfxFrame, this);
	}
	VfxS32 x, y, width, height;

    getTVPosSize(&x, &y, &width, &height);
    m_qucikPreviewFrame->setPos(x, y);
    m_qucikPreviewFrame->setSize(width, height);
	m_qucikPreviewFrame->setImgContent(thumbImgSrc);
	m_qucikPreviewFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
	m_qucikPreviewFrame->setBgColor(VRT_COLOR_BLACK);
	
	setDispType(ATV_DISP_QUICK_PREVIEW);
	startHideTimer();
}

#if defined(__MMI_ATV_RECORD__) && defined (__MMI_ATV_THUMBNAIL__)
void VappAtvMainPage::getRecThumb()
{
    MDI_RESULT ret;

    ret = m_app->getRecFrame(m_storagePath);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        showMdiFailConfirm(ret);
        return;
    }

	m_isImageThumb = MMI_FALSE;

    VfxImageBuffer imageBuf;
    imageBuf.ptr = (VfxU8*)m_app->m_recThumbBuffer;
    imageBuf.pitchBytes = VAPP_ATV_THUMBNAIL_W * 2;
    imageBuf.width = VAPP_ATV_THUMBNAIL_W;
    imageBuf.height = VAPP_ATV_THUMBNAIL_H;
    imageBuf.colorFormat = VRT_COLOR_TYPE_RGB565;

    VfxImageSrc thumbImgSrc;
    thumbImgSrc = VfxImageSrc(imageBuf);
    displayThumb(&thumbImgSrc);
}
#endif

void VappAtvMainPage::onToolBarButtonCliked(VappAtvToolBar::BUTTON_TYPE_ENUM type)
{
    switch (type)
    {
        case VappAtvToolBar::BUTTON_TYPE_HANDLE:
            toggleToolBar();
            break;

        case VappAtvToolBar::BUTTON_TYPE_SCAN:
            m_app->deInitDisplay(VFX_TRUE);
            displayScanProg();
            break;
#if !(defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__))
		case VappAtvToolBar::BUTTON_TYPE_SCAN_LOCATION:
			m_signalChangePage.emit(PAGE_SCAN_LOC);
			break;
#endif
        case VappAtvToolBar::BUTTON_TYPE_AUD_MODE:
            displayAudModeList();
            break;

        case VappAtvToolBar::BUTTON_TYPE_SNAPSHOT:
            displaySavePathCfm(VFX_FALSE);
            //getImgThumb();
            break;
#ifdef __MMI_ATV_RECORD__
        case VappAtvToolBar::BUTTON_TYPE_RECORD:
            displaySavePathCfm(VFX_TRUE);
            //displayRecordBtn();
            break;
#endif
#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        case VappAtvToolBar::BUTTON_TYPE_SETTING:
            m_signalChangePage.emit(PAGE_SETTING);
            break;
#endif
#if !defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
		case VappAtvToolBar::BUTTON_TYPE_STORAGE_SELECT:
            m_signalChangePage.emit(PAGE_STORAGE_SELECT);
            break;

#endif
        default:
            ASSERT(0);
            break;
    }
}

void VappAtvMainPage::onToolBarDrag(VappAtvToolBar::DRAG_TYPE_ENUM type, VfxS32 diffX)
{
    VfxId img = m_toolBar->m_btn->getImgId();
    VfxS32 bgWidth = m_toolBar->getBgWidth();
    VfxFloat anchorX = (VfxFloat)bgWidth / m_toolBar->getBounds().size.width;

    if (diffX > bgWidth)
    {
        diffX = bgWidth;
    }
    else if (diffX < -bgWidth)
    {
        diffX = - bgWidth;
    }

    VfxFloat ratio = (VfxFloat)vfxAbs(diffX) / m_toolBar->getBounds().size.width;

    if (img == IMG_ID_VAPP_ATV_TBAR_BTN_SHOW)
    {
        if (diffX > 0)
        {
            m_toolBar->setAnchor(anchorX - ratio, 0);
            m_wheelPanel->setAnchor((anchorX - ratio) / anchorX, 0);
        }
    }
    else // original show
    {
        if (diffX < 0)
        {
            m_toolBar->setAnchor(ratio, 0);
            m_wheelPanel->setAnchor(ratio / anchorX, 0);
        }
    }


    if (type == VappAtvToolBar::DRAG_TYPE_UP)
    {
        if (m_toolBar->getAnchor().x >= anchorX/2)
        {
            // toolbar moves out
            m_toolBar->m_btn->setImgId(IMG_ID_VAPP_ATV_TBAR_BTN_SHOW);
            m_toolBar->setAnchor(anchorX, 0);
            m_toolBar->setAllFuncEnabled(VFX_FALSE);

            // wheePanel slides in
            m_wheelPanel->setAnchor(1, 0);
        }
        else
        {
            // toolbar moves in
            m_toolBar->m_btn->setImgId(IMG_ID_VAPP_ATV_TBAR_BTN_HIDE);
            m_toolBar->setAnchor(0, 0);
            m_toolBar->setAllFuncEnabled(VFX_TRUE);

            // wheePanel slides out
            m_wheelPanel->setAnchor(0, 0);
        }
    }

}

void VappAtvMainPage::toggleToolBar()
{
    VfxFloat anchorX = (VfxFloat)m_toolBar->getBgWidth() / m_toolBar->getBounds().size.width;
    VfxFPoint point = m_toolBar->getAnchor();

    if (point.x >= anchorX/2)
    {
        // toolbar moves in
        m_toolBar->m_btn->setImgId(IMG_ID_VAPP_ATV_TBAR_BTN_HIDE);
        m_toolBar->setAnchor(0, 0);
        m_toolBar->setAllFuncEnabled(VFX_TRUE);

        // wheePanel slides out
        m_wheelPanel->setAnchor(0, 0);
    }
    else
    {
        // toolbar moves out
        m_toolBar->m_btn->setImgId(IMG_ID_VAPP_ATV_TBAR_BTN_SHOW);
        m_toolBar->setAnchor(anchorX, 0);
        m_toolBar->setAllFuncEnabled(VFX_FALSE);

        // wheePanel slides in
        m_wheelPanel->setAnchor(1, 0);
    }
}

void VappAtvMainPage::displayScanProg()
{
    //Before scan, should disconnect this two singal, 
    //or when you tap up/down key in the scaning process, assert happen in onChangeChannel().
    m_wheelPanel->m_signalChangeChannel.disconnect(this, &VappAtvMainPage::onChangeChannel);
    m_wheelPanel->m_endScrolling.disconnect(this, &VappAtvMainPage::onWheelEndScroll);

    ASSERT(m_scanProg == NULL);
    VFX_OBJ_CREATE(m_scanProg, VappAtvScanProg, this);
    m_scanProg->m_signal.connect(this, &VappAtvMainPage::scanEvthandler);

    setDispType(ATV_DISP_SCAN_PROG);
    hideCtrlPanel(VFX_TRUE);
}

void VappAtvMainPage::scanEvthandler(VappAtvScanProg::EVT_TYPE_ENUM evt)
{
    VFX_OBJ_CLOSE(m_scanProg);
    switch (evt)
    {
        case VappAtvScanProg::EVT_CHANGE_SCAN_LOC:

            setDispType(ATV_DISP_CTRL_PANEL);

            // display scan location page
            m_signalChangePage.emit(PAGE_SCAN_LOC);

            break;
        case VappAtvScanProg::EVT_EXIT:

            m_app->closeEngine();
            displayPleaseWait();

            break;
        case VappAtvScanProg::EVT_SCAN_FINISHED:

            //start service or start player
            if (m_vdoFrmPrepared)
            {
                m_app->initDisplay();
            }

            resetAnchor();

            hideCtrlPanel(VFX_FALSE);
            startHideTimer();

            break;
        case VappAtvScanProg::EVT_SCAN_FAIL:

            showMdiFailConfirm(MDI_RES_MTV_FAILED);

            break;
    }

    // when finish scan, connect the two signal.
    m_wheelPanel->m_signalChangeChannel.connect(this, &VappAtvMainPage::onChangeChannel);
    m_wheelPanel->m_endScrolling.connect(this, &VappAtvMainPage::onWheelEndScroll);

}

void VappAtvMainPage::onQueryRotateEx(
	VfxScreenRotateParam &param // The parameter to rotate
)
{
	param.rotateTo = VFX_SCR_ROTATE_TYPE_270;
}

void VappAtvMainPage::getTVPosSize(
    VfxS32 *x, VfxS32 *y, VfxS32 *width, VfxS32 *height)
{
#if defined(__MMI_ATV_RECORD__) 

    VfxS32 ratioW = 0, ratioH = 0;

    // ratio should be the same as record ratio
    switch (m_app->m_setting.record_size)
    {
        case MDI_MTV_RECORDER_SIZE_QCIF:
            ratioW = 176;
            ratioH = 144;
            break;
        case MDI_MTV_RECORDER_SIZE_QVGA:
            ratioW = 320;
            ratioH = 240;
            break;
        case MDI_MTV_RECORDER_SIZE_HVGA:
            ratioW = 480;
            ratioH = 320;
            break;
        default:
            ASSERT(0);
    }

    // center align
    if (LCD_HEIGHT * ratioH > LCD_WIDTH * ratioW)
    {
        *y = 0;
        *height = LCD_WIDTH;
        *width = LCD_WIDTH * ratioW / ratioH;
        *x = (LCD_HEIGHT - *width) >> 1;
    }
    else
    {
        *x = 0;
        *width = LCD_HEIGHT;
        *height = LCD_HEIGHT * ratioH / ratioW;
        *y = (LCD_WIDTH - *height) >> 1;
    }

    // even number
    *x = (*x % 2) ? (*x + 1): (*x);
    *y = (*y % 2) ? (*y + 1): (*y);
    *width = (*width % 2) ? (*width + 1): (*width);
    *height = (*height % 2) ? (*height + 1): (*height);
	
#else
	*x = 0;
	*y = 0;
    *width = LCD_HEIGHT;
    *height = LCD_WIDTH;
#endif
}

void VappAtvMainPage::showMdiFailConfirm(MDI_RESULT ret)
{
    stopHideTimer();

    VcpConfirmPopup *cfm;
    VFX_OBJ_CREATE(cfm, VcpConfirmPopup, this);

    cfm->setInfoType(VCP_POPUP_TYPE_WARNING);

    mmi_event_notify_enum popup_type;
    MMI_ID_TYPE string_id;
    string_id = mdi_util_get_mdi_error_info(ret, &popup_type);

    cfm->setText(VFX_WSTR_RES(string_id));
    cfm->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
    cfm->m_signalButtonClicked.connect(
        this, &VappAtvMainPage::onMdiFailCfmClicked);
    cfm->show(VFX_TRUE);

    if (m_vdoFrmPrepared)
    {
        //When display confirm popup, the TV is still playing, 
        //and lock->unluck, it should stop,
        //and when click the button, TV play again.
        m_app->initDisplay();
    }

    setDispType(ATV_DISP_POPUP_CONFIRM);
}

void VappAtvMainPage::displayPleaseWait()
{
    VcpIndicatorPopup *indPopup;

    VFX_OBJ_CREATE(indPopup, VcpIndicatorPopup, this);
    indPopup->setText(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
    indPopup->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    indPopup->show(VFX_TRUE);

    setDispType(ATV_DISP_POPUP_CONFIRM);
}

void VappAtvMainPage::onMdiFailCfmClicked(VfxObject* sender, VfxU32 id)
{
    setDispType(ATV_DISP_CTRL_PANEL);
	startHideTimer();

    if (m_vdoFrmPrepared)
    {
        //Start player
        m_app->initDisplay();
    }
}

void VappAtvMainPage::createLoadingPopup()
{
	if(m_loadingPopup==NULL)
	{
	    VFX_OBJ_CREATE(m_loadingPopup,VcpLoadingPopup,this);
	}
	
    m_loadingPopup->setIcon(VfxImageSrc(MAIN_MENU_ATV_ICON));
    m_loadingPopup->show(VFX_TRUE);
	m_loadingPopup->setAutoDestory(VFX_TRUE);

}

void VappAtvMainPage::closeLoadingPopup()
{
	if(m_loadingPopup!=NULL)
	{
		m_loadingPopup->exit(VFX_TRUE);
		VFX_OBJ_CLOSE(m_loadingPopup);
		m_loadingPopup = NULL;
	}
}

/*****************************************************************************
 * ToolBar Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvToolBar", VappAtvToolBar, VfxControl);

VappAtvToolBar::VappAtvToolBar():
    m_btn(NULL),
    m_handleDrag(VFX_FALSE)
{
    VfxS32 idx;

    for(idx = 0; idx < (BUTTON_ALL-1); idx ++)
    {
        m_tBarBtn[idx] = NULL;
    }
}


void VappAtvToolBar::onInit()
{
    VcpStateImage SI;
    VfxS32 idx, y, step, posX, posY, bgHeight;
    VfxSize size;
    VfxImageFrame *imgFrm;


    VfxControl::onInit();

    // Get App
    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappAtvApp);

    //BG
    step = VAPP_ATV_TBAR_BG_H / TBAR_BTN_NUM;
    y = VAPP_ATV_TBAR_BG_Y+(TBAR_BTN_NUM-(BUTTON_ALL-1))*(step>>1);
	bgHeight = VAPP_ATV_TBAR_BG_H-(TBAR_BTN_NUM-(BUTTON_ALL-1))*step;
		
    VFX_OBJ_CREATE(imgFrm, VfxImageFrame, this);
    imgFrm->setResId(IMG_ID_VAPP_ATV_TBAR_BG);
    imgFrm->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    imgFrm->setPos(0, y);
	#ifndef __MMI_ATV_SLIM__
    m_bgWidth = imgFrm->getSize().width;
    imgFrm->setSize(m_bgWidth, bgHeight);
	#else
	imgFrm->setSize(VAPP_ATV_TOOLBAR_SLIM_WIDTH, bgHeight);
	m_bgWidth = imgFrm->getSize().width; // must get the BG_width
	#endif
    

    // BG Line
    //step = VAPP_ATV_TBAR_BG_H / TBAR_BTN_NUM;
    //y = VAPP_ATV_TBAR_BG_Y+(TBAR_BTN_NUM-(BUTTON_ALL-1))*(step>>1);
	
    //y = VAPP_ATV_TBAR_BG_Y;
    //step = VAPP_ATV_TBAR_BG_H / (BUTTON_ALL-1);
    for (idx = 0; idx < (BUTTON_ALL - 1 - 1); idx ++)
    {
        y += step;
        VFX_OBJ_CREATE(imgFrm, VfxImageFrame, this);
        imgFrm->setResId(IMG_ID_VAPP_ATV_TBAR_BG_LINE);
        imgFrm->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        imgFrm->setPos(VAPP_ATV_TBAR_LINE_X, y);
		imgFrm->setSize(m_bgWidth, 1);
		imgFrm->setBounds(0,0,
			m_bgWidth,
			imgFrm->getSize().height
			);// set the line full contain the frame
    }

    // imgButton: tBar
    VfxU16 imgId[] =
    {
        IMG_ID_VAPP_ATV_TBAR_SCAN,
	#if !(defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__))
		IMG_ID_VAPP_ATV_TBAR_SCAN_LOCATION,
	#endif
        IMG_ID_VAPP_ATV_TBAR_AUD_MODE,
        IMG_ID_VAPP_ATV_TBAR_SNAPSHOT,
    #ifdef __MMI_ATV_RECORD__
        IMG_ID_VAPP_ATV_TBAR_RECORD,
    #endif
	#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        IMG_ID_VAPP_ATV_TBAR_SETTINGS,
    #endif
	#if !defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
		IMG_ID_VAPP_ATV_TBAR_SELECT_STORAGE  //select storage, need modify the pic
	#endif
    };

    VfxU16 imgIdD[] =
    {
        IMG_ID_VAPP_ATV_TBAR_SCAN,
	#if !(defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__))
		IMG_ID_VAPP_ATV_TBAR_SCAN_LOCATION,
	#endif			
	#ifndef __MMI_ATV_SLIM__
        IMG_ID_VAPP_ATV_TBAR_AUD_MODE_D,
        IMG_ID_VAPP_ATV_TBAR_SNAPSHOT_D,
    #else
		//IMG_ID_VAPP_ATV_TBAR_AUD_MODE,
        //IMG_ID_VAPP_ATV_TBAR_SNAPSHOT,
        IMG_ID_VAPP_ATV_TBAR_AUD_MODE_D,
        IMG_ID_VAPP_ATV_TBAR_SNAPSHOT_D,
	#endif
    #ifdef __MMI_ATV_RECORD__
        IMG_ID_VAPP_ATV_TBAR_RECORD_D,
    #endif
	#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        IMG_ID_VAPP_ATV_TBAR_SETTINGS,
	#endif
	#if !defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
		IMG_ID_VAPP_ATV_TBAR_SELECT_STORAGE  //select storage, need modify the pic
	#endif
    };

    VfxId callbackId[]=
    {
        BUTTON_TYPE_SCAN,
	#if !(defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__))
		BUTTON_TYPE_SCAN_LOCATION,
	#endif			
        BUTTON_TYPE_AUD_MODE,
        BUTTON_TYPE_SNAPSHOT,
	#ifdef __MMI_ATV_RECORD__
        BUTTON_TYPE_RECORD,
#endif
    #if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        BUTTON_TYPE_SETTING,    /* 4 */
	#endif 
	#if !defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
		BUTTON_TYPE_STORAGE_SELECT,  //select storage, need modify the pic
	#endif
    };

    step = VAPP_ATV_TBAR_BG_H / TBAR_BTN_NUM;
    y = VAPP_ATV_TBAR_BG_Y+(TBAR_BTN_NUM-(BUTTON_ALL-1))*(step>>1);
    //step = VAPP_ATV_TBAR_BG_H / (BUTTON_ALL-1);
    
    for (idx = 0; idx < (BUTTON_ALL - 1); idx ++)
    {
        SI = VcpStateImage(imgId[idx], imgId[idx], imgIdD[idx], imgId[idx]);
        size = SI.getImageNormal().getSize();

        VFX_OBJ_CREATE(m_tBarBtn[idx], VcpImageButton, this);
        m_tBarBtn[idx]->setImage(SI);
        posY = y + ((step - size.height) >> 1);
        posX = ((m_bgWidth - size.width) >> 1);
        m_tBarBtn[idx]->setPos(posX, posY);
        m_tBarBtn[idx]->setSize(size.width, size.height);
        m_tBarBtn[idx]->setId(callbackId[idx]);
        m_tBarBtn[idx]->m_signalClicked.connect(this, &VappAtvToolBar::onImgBtnClicked);
        m_tBarBtn[idx]->setIsEffect(VFX_TRUE);
        m_tBarBtn[idx]->setFuzzy(VFX_TRUE);
        m_tBarBtn[idx]->setEffectSize(size);
        m_tBarBtn[idx]->setEffectGlowType(VCP_GLOW_VISUAL_TYPE_2D); 
        y += step;
    }

    // set audMode, snapshot, record
    setIsFuncEnabled();

    // Button handle
    VfxImageFrame *tmpImgFrm;
    VFX_OBJ_CREATE(tmpImgFrm, VfxImageFrame, this);
    tmpImgFrm->setResId(IMG_ID_VAPP_ATV_TBAR_BTN_SHOW);
    VfxS32 handleW = tmpImgFrm->getSize().width;
    VfxS32 handleH = tmpImgFrm->getSize().height;
    VFX_OBJ_CLOSE(tmpImgFrm);
	#ifndef __MMI_ATV_SLIM__
    VFX_OBJ_CREATE_EX(m_btn, VappAtvImgButton, this,
        (IMG_ID_VAPP_ATV_TBAR_BTN_SHOW, handleW*2, handleH*2, 0, handleH/2));
	#else
    VFX_OBJ_CREATE_EX(m_btn, VappAtvImgButton, this,
        (IMG_ID_VAPP_ATV_TBAR_BTN_SHOW, handleW*2, handleH*2, 0, handleH/2));
	#endif	

    m_btn->setPos(VAPP_ATV_TBAR_HANDLE_X, VAPP_ATV_TBAR_HANDLE_Y - handleH/2);
    m_btn->m_signalPenEvent.connect(this, &VappAtvToolBar::onHandlePenEvent);

}

VfxS32 VappAtvToolBar::getBgWidth()
{
    return m_bgWidth;
}

void VappAtvToolBar::setAllFuncEnabled(VfxBool isEnabled)
{
    if(isEnabled)
    {
        m_tBarBtn[BUTTON_TYPE_SCAN]->setIsDisabled(VFX_FALSE);
	#if !(defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__))
		m_tBarBtn[BUTTON_TYPE_SCAN_LOCATION]->setIsDisabled(VFX_FALSE);
	#endif
        m_tBarBtn[BUTTON_TYPE_AUD_MODE]->setIsDisabled(VFX_FALSE);
        m_tBarBtn[BUTTON_TYPE_SNAPSHOT]->setIsDisabled(VFX_FALSE);
    #ifdef __MMI_ATV_RECORD__
        m_tBarBtn[BUTTON_TYPE_RECORD]->setIsDisabled(VFX_FALSE);
    #endif
	#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        m_tBarBtn[BUTTON_TYPE_SETTING]->setIsDisabled(VFX_FALSE);
	#endif
	#if !defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
		m_tBarBtn[BUTTON_TYPE_STORAGE_SELECT]->setIsDisabled(VFX_FALSE);
	#endif
	
        setIsFuncEnabled();    
               
    }
    else
    {
        m_tBarBtn[BUTTON_TYPE_SCAN]->setIsDisabled(VFX_TRUE);
	#if !(defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__))
		m_tBarBtn[BUTTON_TYPE_SCAN_LOCATION]->setIsDisabled(VFX_TRUE);
	#endif
        m_tBarBtn[BUTTON_TYPE_AUD_MODE]->setIsDisabled(VFX_TRUE);
        m_tBarBtn[BUTTON_TYPE_SNAPSHOT]->setIsDisabled(VFX_TRUE);
    #ifdef __MMI_ATV_RECORD__
        m_tBarBtn[BUTTON_TYPE_RECORD]->setIsDisabled(VFX_TRUE);
    #endif    
	#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
        m_tBarBtn[BUTTON_TYPE_SETTING]->setIsDisabled(VFX_TRUE);
	#endif
	#if !defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
		m_tBarBtn[BUTTON_TYPE_STORAGE_SELECT]->setIsDisabled(VFX_FALSE);
	#endif
    }
}

void VappAtvToolBar::setIsFuncEnabled()
{
    if (m_app->getKernelState() == ATV_KERNEL_READY &&
        m_app->getPlayerState() == ATV_PLAYER_PLAY)
    {
        m_tBarBtn[BUTTON_TYPE_AUD_MODE]->setIsDisabled(VFX_FALSE);

        if (m_app->m_storageValid)
        {
            m_tBarBtn[BUTTON_TYPE_SNAPSHOT]->setIsDisabled(VFX_FALSE);
			if(srv_ucm_is_any_call())
            {
            #ifdef __MMI_ATV_RECORD__
                m_tBarBtn[BUTTON_TYPE_RECORD]->setIsDisabled(VFX_TRUE);
            #endif

            #ifdef __MMI_USB_SUPPORT__
                if(m_app->m_massStorageMode)
                {
                    m_tBarBtn[BUTTON_TYPE_SNAPSHOT]->setIsDisabled(VFX_TRUE);
                }
            #endif /* __MMI_USB_SUPPORT__ */
            }
            else
        #ifdef __MMI_USB_SUPPORT__
             /* check is in mass storage mode */
            //if (srv_usb_is_in_mass_storage_mode_ext())
            if(m_app->m_massStorageMode)
            {
               m_tBarBtn[BUTTON_TYPE_SNAPSHOT]->setIsDisabled(VFX_TRUE);
            #ifdef __MMI_ATV_RECORD__
               m_tBarBtn[BUTTON_TYPE_RECORD]->setIsDisabled(VFX_TRUE);
            #endif
            }
            else
        #endif /* __MMI_USB_SUPPORT__ */
            {
            #ifdef __MMI_ATV_RECORD__
                m_tBarBtn[BUTTON_TYPE_RECORD]->setIsDisabled(VFX_FALSE);
            #endif
            }
        }
        else
        {
            m_tBarBtn[BUTTON_TYPE_SNAPSHOT]->setIsDisabled(VFX_TRUE);
        #ifdef __MMI_ATV_RECORD__
            m_tBarBtn[BUTTON_TYPE_RECORD]->setIsDisabled(VFX_TRUE);
        #endif
            //guo m_tBarBtn[BUTTON_TYPE_SNAPSHOT]->setIsDisabled(VFX_FALSE);
            //guo m_tBarBtn[BUTTON_TYPE_RECORD]->setIsDisabled(VFX_FALSE);
        }
    }
    else
    {
        m_tBarBtn[BUTTON_TYPE_AUD_MODE]->setIsDisabled(VFX_TRUE);
        m_tBarBtn[BUTTON_TYPE_SNAPSHOT]->setIsDisabled(VFX_TRUE);
    #ifdef __MMI_ATV_RECORD__
        m_tBarBtn[BUTTON_TYPE_RECORD]->setIsDisabled(VFX_TRUE);
    #endif
    }
}

void VappAtvToolBar::onImgBtnClicked(VfxObject *obj, VfxId id)
{
    m_signalImgBtnClicked.emit((BUTTON_TYPE_ENUM)id);
}

void VappAtvToolBar::onHandlePenEvent(VfxPenEvent &event, VfxId id)
{
    VfxS32 diff;

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            m_penDownX = event.getRelPos(m_btn).x;
            m_handleDrag = VFX_FALSE;
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            diff = event.getRelPos(m_btn).x - m_penDownX;

            m_handleDrag = VFX_TRUE;
            m_signalDrag.emit(DRAG_TYPE_MOVE, diff);

            break;

        case VFX_PEN_EVENT_TYPE_UP:
        case VFX_PEN_EVENT_TYPE_ABORT:
            diff = event.getRelPos(m_btn).x - m_penDownX;

            if (m_handleDrag && vfxAbs(diff) > MOVE_THRESHOLD)
            {
                m_signalDrag.emit(DRAG_TYPE_UP, diff);
            }
            else
            {
                //click
                //if (m_btn->containPoint(event.getRelPos(m_btn), VFX_TRUE))
                m_signalImgBtnClicked.emit(BUTTON_TYPE_HANDLE);

            }

            break;


    }

}

VfxBool VappAtvToolBar::onPenInput(VfxPenEvent &event)
{
    // avoid main screen handling the pen event pointing on the tool bar
    return VFX_TRUE;
}

#ifdef __MMI_ATV_PLAYER_SETTING__
/*****************************************************************************
 * AdjustBar Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvAdjustBar", VappAtvAdjustBar, VfxControl);

VappAtvAdjustBar::VappAtvAdjustBar()
{
}


void VappAtvAdjustBar::onInit()
{
    VfxS32 idx, barY, textY, barH, maxX, sliderX, sliderW, lineW;
    VfxS32 height, x;
    VfxImageFrame *imgFrmBar, *imgFrm;
    VfxTextFrame *textFrm;
    VcpButton* button;

    VfxU16 text[] =
    {
        STR_ID_VAPP_ATV_BRIGHTNESS,
        STR_ID_VAPP_ATV_CONTRAST,
        STR_ID_VAPP_ATV_SATURATION
    };

    VfxId callbackId[] =
    {
        BUTTON_OK,
        BUTTON_CANCEL
    };

    VfxU16 strId[] =
    {
        STR_GLOBAL_OK,
        STR_GLOBAL_CANCEL
    };

    VfxU8 level[] =
    {
        MDI_MTV_BRIGHTNESS_P5 - MDI_MTV_BRIGHTNESS_N5,
        MDI_MTV_CONTRAST_P5 - MDI_MTV_CONTRAST_N5,
        MDI_MTV_SATURATION_P5 - MDI_MTV_SATURATION_N5
    };

    VfxU8 minValue[] =
    {
        MDI_MTV_BRIGHTNESS_N5,
        MDI_MTV_CONTRAST_N5,
        MDI_MTV_SATURATION_N5
    };

    VfxU8 maxValue[] =
    {
        MDI_MTV_BRIGHTNESS_P5,
        MDI_MTV_CONTRAST_P5,
        MDI_MTV_SATURATION_P5
    };


    VfxControl::onInit();

    // Get App
    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappAtvApp);

    // Init parameter
    initAdjustValue();

    VfxU8 curValue[] =
    {
        m_brightness,
        m_contrast,
        m_saturation
    };

    /* Get Bar height */
    VFX_OBJ_CREATE(imgFrm, VfxImageFrame, this);
    imgFrm->setResId(IMG_ID_VAPP_ATV_ADJUST_LIST_BG);
    barH = imgFrm->getSize().height;
    VFX_OBJ_CLOSE(imgFrm);

    barY = maxX = 0;
    for (idx = 0; idx < BAR_NUM; idx ++)
    {
        //AdjustBarBG
        VFX_OBJ_CREATE(imgFrmBar, VfxImageFrame, this);
        imgFrmBar->setResId(IMG_ID_VAPP_ATV_ADJUST_LIST_BG);
        imgFrmBar->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        imgFrmBar->setPos(0, barY);
        imgFrmBar->setSize(LCD_HEIGHT, imgFrmBar->getSize().height);

        //AdjustText
        VFX_OBJ_CREATE(textFrm, VfxTextFrame, this);
        textFrm->setString(VFX_WSTR_RES(text[idx]));
        textFrm->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
        textFrm->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_ATV_ADJUST_TEXT_FONT_SIZE)));
        textFrm->setColor(VfxColor(255, TEXT_COLOR, TEXT_COLOR, TEXT_COLOR));
        textY = barY + ((barH - textFrm->getMeasureBounds().size.height) >> 1);
        textFrm->setPos(VfxPoint(VAPP_ATV_ADJUST_BORDER_WIDTH, textY));
        if (VAPP_ATV_ADJUST_BORDER_WIDTH + textFrm->getMeasureBounds().size.width > maxX)
        {
            maxX = VAPP_ATV_ADJUST_BORDER_WIDTH + textFrm->getMeasureBounds().size.width;
        }
        barY += barH;
    }

    sliderX = maxX + VAPP_ATV_ADJUST_SLIDER_OFFSET;
    sliderW = LCD_HEIGHT - sliderX - VAPP_ATV_ADJUST_BORDER_WIDTH;

    //slider
    barY = 0;
    for (idx = 0; idx < BAR_NUM; idx ++)
    {
        VFX_OBJ_CREATE(m_slider[idx], VcpSlider, this);
        height = m_slider[idx]->getSize().height;
        m_slider[idx]->setPos(sliderX, barY + ((barH - height) >> 1));
        m_slider[idx]->setLayout(VCP_SLIDER_LAYOUT_HORZ);
        m_slider[idx]->setLength(sliderW);
        m_slider[idx]->setTotalDiscreteStepsForPen(level[idx]);
        m_slider[idx]->setMinValue((VfxFloat)minValue[idx] / level[idx]);
        m_slider[idx]->setMaxValue((VfxFloat)maxValue[idx] / level[idx]);
        m_slider[idx]->setCurrentValue((VfxFloat)curValue[idx] / level[idx]);
        m_slider[idx]->m_signalThumbDrag.connect(this, &VappAtvAdjustBar::onSliderDrag);
        barY += barH;
    }

    VcpStateImage SI;
    SI = VcpStateImage(IMG_ID_VAPP_ATV_ADJUST_SOFTKEY_BG_N, IMG_ID_VAPP_ATV_ADJUST_SOFTKEY_BG_D, IMG_ID_VAPP_ATV_ADJUST_SOFTKEY_BG_N, IMG_ID_VAPP_ATV_ADJUST_SOFTKEY_BG_N);

    height = LCD_WIDTH - VAPP_ATV_ADJUST_BAR_Y - barY;

    //Left & right softkey bar
    x = 0;
    for (idx = 0; idx < BTN_NUM; idx ++)
    {
        VFX_OBJ_CREATE(button, VcpButton, this);
        button->setBgImageList(SI);
        button->setText(VFX_WSTR_RES(strId[idx]));
        button->setTextColor(VFX_COLOR_BLACK);
        button->setRect(VfxRect(x, barY, LCD_HEIGHT>>1, height));
        button->setId(callbackId[idx]);
        button->m_signalClicked.connect(this, &VappAtvAdjustBar::onAdjustBtnClicked);
        x += (LCD_HEIGHT>>1);
    }

    // Separate line
    VFX_OBJ_CREATE(imgFrm, VfxImageFrame, this);
    imgFrm->setResId(IMG_ID_VAPP_ATV_ADJUST_SOFTKEY_LINE);
    lineW = imgFrm->getSize().width;
    imgFrm->setPos((LCD_HEIGHT - lineW) >> 1, barY);
}

void VappAtvAdjustBar::onSliderDrag(VcpSlider *slider, VfxFloat value)
{
    VfxU8 level[] =
    {
        MDI_MTV_BRIGHTNESS_P5 - MDI_MTV_BRIGHTNESS_N5,
        MDI_MTV_CONTRAST_P5 - MDI_MTV_CONTRAST_N5,
        MDI_MTV_SATURATION_P5 - MDI_MTV_SATURATION_N5
    };

    if (slider == m_slider[SLIDER_BRIGHTNESS])
    {
        m_brightness = (VfxU8)(value * level[SLIDER_BRIGHTNESS]);
        mdi_mtv_set_brightness((VfxU16)m_brightness);

    }
    else if (slider == m_slider[SLIDER_CONTRAST])
    {
        m_contrast = (VfxU8)(value * level[SLIDER_CONTRAST]);
        mdi_mtv_set_contrast((VfxU16)m_contrast);

    }
    else if (slider == m_slider[SLIDER_SATURATION])
    {
        m_saturation = (VfxU8)(value * level[SLIDER_SATURATION]);
        mdi_mtv_set_saturation((VfxU16)m_saturation);
    }
}

void VappAtvAdjustBar::onAdjustBtnClicked(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case BUTTON_OK:
            m_app->setAdjustValue(m_brightness, m_contrast, m_saturation);
            break;

        case BUTTON_CANCEL:
            m_app->setAdjustValue(
                m_app->m_setting.brightness,
                m_app->m_setting.contrast,
                m_app->m_setting.saturation);
            m_app->m_scrn->entrySettingPage();
            
            break;
        default:
            ASSERT(0);
    }

    m_signalBtnClicked.emit();
}

void VappAtvAdjustBar::initAdjustValue()
{
    m_brightness = m_app->m_setting.brightness;
    m_contrast = m_app->m_setting.contrast;
    m_saturation = m_app->m_setting.saturation;
}
#endif

/*****************************************************************************
 * WheelPanel Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvWheelPanel", VappAtvWheelPanel, VcpWheelMenu);
#ifndef __MMI_ATV_SLIM__
VappAtvWheelPanel::VappAtvWheelPanel():
    m_btnPressed(VFX_FALSE),
    m_timerChangeIdx(NULL),
    m_timerResetScrollIdx(NULL)

{
    m_btn[BTN_UP] = NULL;
    m_btn[BTN_DOWN] = NULL;

    m_btnBGImg[BTN_UP] = NULL;
    m_btnBGImg[BTN_DOWN] = NULL;
}


void VappAtvWheelPanel::onInit()
{
    VfxS32 bg_width;
    VfxSize size;
    VcpWheelMenu::onInit();

    // Get App
    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappAtvApp);

    //BG
    VfxImageFrame *imgFrm;
    VFX_OBJ_CREATE(imgFrm, VfxImageFrame, this);
    imgFrm->setResId(IMG_ID_VAPP_ATV_WHEEL_BG);
    imgFrm->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    bg_width = imgFrm->getSize().width;
    imgFrm->setPos(0, 0);

    VfxResId imgBGNormalId[] =
    {
        IMG_ID_VAPP_ATV_WHEEL_BTN_UP_N,
        IMG_ID_VAPP_ATV_WHEEL_BTN_DOWN_N
    };


    VfxResId imgId[] =
    {
        IMG_ID_VAPP_ATV_WHEEL_ARROW_UP,
        IMG_ID_VAPP_ATV_WHEEL_ARROW_DOWN
    };


    VfxS32 btnImgY[] =
    {
        VAPP_ATV_WHEEL_BTN_UP_Y,
        VAPP_ATV_WHEEL_BTN_DOWN_Y
    };

    VfxId callbackId[] =
    {
        BTN_UP,
        BTN_DOWN
    };

    VfxS32 idx, posY = (LCD_WIDTH >>1);

    for (idx = 0; idx < BTN_NUM; idx ++)
    {
        // Button BG
        VFX_OBJ_CREATE(m_btnBGImg[idx], VfxImageFrame, this);
        m_btnBGImg[idx]->setResId(imgBGNormalId[idx]);
        m_btnBGImg[idx]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        size = m_btnBGImg[idx]->getSize();
        m_btnBGImg[idx]->setPos(
            bg_width - size.width,
            posY + size.height * (idx - 1));

        // Button
        VfxS32 btnX = bg_width - VAPP_ATV_WHEEL_BTN_WIDTH;
        VfxS32 btnY = (LCD_WIDTH>>1) + VAPP_ATV_WHEEL_BTN_HEIGHT * (idx - 1);

        VFX_OBJ_CREATE_EX(m_btn[idx], VappAtvImgButton, this,
            (imgId[idx],
             VAPP_ATV_WHEEL_BTN_WIDTH,
             VAPP_ATV_WHEEL_BTN_HEIGHT,
             VAPP_ATV_WHEEL_BTN_WIDTH - (LCD_HEIGHT - VAPP_ATV_WHEEL_BTN_X),
             btnImgY[idx] - btnY)
        );

        m_btn[idx]->setPos(btnX, btnY);
        m_btn[idx]->setCallbackId(callbackId[idx]);
        m_btn[idx]->m_signalPenEvent.connect(this, &VappAtvWheelPanel::onWheelBtnPenEvent);

    }

    //wheelMenu
    initWheelFocus();

    VFX_OBJ_CREATE(m_timerResetScrollIdx, VfxTimer, this);
    m_timerResetScrollIdx->setStartDelay(DELAY_RESET_SCROLL_IDX);
    m_timerResetScrollIdx->m_signalTick.connect(
            this, &VappAtvWheelPanel::resetScrollIdx);

}

void VappAtvWheelPanel::resetScrollIdx(VfxTimer *timer)
{
    setScrollIndex((VfxFloat)getFocus(), WHEEL_EFFECT_TIME);
}


void VappAtvWheelPanel::initWheelFocus()
{
    VfxS32 focus;
    VfxS32 nFocus = m_app->m_numServices * (MENU_TIMES>>1);

    if (m_app->m_liveScan)
    {
        switch (m_app->m_numServices)
        {
            case 1:
            case 2:
                focus = 0;
                break;
            case 3:
            case 4:
                focus = 1;
                break;
            case 5:
            case 6:
                focus = 2;
                break;
            default:
                focus = nFocus;
        }

        // Init selected channel
        m_app->m_setting.selected_channel = focus % m_app->m_numServices;
    }
    else
    {
        // check if original selected channel is valid
        if (m_app->m_setting.selected_channel >= m_app->m_numServices)
        {
            m_app->m_setting.selected_channel = 0;
        }

        // use the original selected channel
        if (m_app->m_numServices < MENU_FOCUSN_COUNT)
        {
            focus = m_app->m_setting.selected_channel;
        }
        else
        {
            focus = nFocus + m_app->m_setting.selected_channel;
        }
    }

    m_targetChannel = m_app->m_setting.selected_channel;
    setFocus(focus, 0);
}

void VappAtvWheelPanel::wheelBtnDownHdlr(VfxId id)
{
    VfxResId imgBGDownId[] =
    {
        IMG_ID_VAPP_ATV_WHEEL_BTN_UP_D,
        IMG_ID_VAPP_ATV_WHEEL_BTN_DOWN_D
    };

    m_btnBGImg[id]->setResId(imgBGDownId[id]);

    m_targetChannel = getFocus() % m_app->m_numServices;

    m_btnPressed = VFX_TRUE;

    if (id == BTN_UP)
    {
        decChannelIndex(VFX_TRUE);//VFX_FALSE
    }
    else
    {
        incChannelIndex(VFX_TRUE);//VFX_FALSE
    }
}

void VappAtvWheelPanel::wheelBtnUpHdlr(VfxId id)
{
    VfxResId imgBGNormalId[] =
    {
        IMG_ID_VAPP_ATV_WHEEL_BTN_UP_N,
        IMG_ID_VAPP_ATV_WHEEL_BTN_DOWN_N
    };

    m_btnBGImg[id]->setResId(imgBGNormalId[id]);
    m_btnPressed = VFX_FALSE;

    stopChangeIndexTimer();

    if (!getIsScrolling())
    {
        m_signalChangeChannel.emit(m_targetChannel);
    }
}

void VappAtvWheelPanel::wheelBtnLongPressHdlr(VfxId id)
{
    ASSERT(m_timerChangeIdx == NULL);
    VFX_OBJ_CREATE(m_timerChangeIdx, VfxTimer, this);
    m_timerChangeIdx->setStartDelay(DELAY_CHANGE_IDX);
    if (id == BTN_UP)
    {
        decChannelIndex(VFX_TRUE);//VFX_FALSE
        m_timerChangeIdx->m_signalTick.connect(
            this, &VappAtvWheelPanel::decChannelTimeout);
    }
    else
    {
        incChannelIndex(VFX_TRUE);//VFX_FALSE
        m_timerChangeIdx->m_signalTick.connect(
            this, &VappAtvWheelPanel::incChannelTimeout);
    }

    m_timerChangeIdx->start();
}


void VappAtvWheelPanel::onWheelBtnPenEvent(VfxPenEvent &event, VfxId id)
{
    ASSERT(id < BTN_NUM);

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            wheelBtnDownHdlr(id);
            break;

        case VFX_PEN_EVENT_TYPE_UP:
        case VFX_PEN_EVENT_TYPE_ABORT:
            wheelBtnUpHdlr(id);
            break;

        case VFX_PEN_EVENT_TYPE_LONG_TAP:
            wheelBtnLongPressHdlr(id);
            break;

    }

}

void VappAtvWheelPanel::incChannelTimeout(VfxTimer *timer)
{
    incChannelIndex(VFX_TRUE);//VFX_FALSE
    timer->start();
}

void VappAtvWheelPanel::decChannelTimeout(VfxTimer *timer)
{
    decChannelIndex(VFX_TRUE);//VFX_FALSE
    timer->start();
}

void VappAtvWheelPanel::incChannelIndex(VfxBool forceWrap)
{
    VfxS32 focus = getFocus();

    m_timerResetScrollIdx->stop();
    if (m_targetChannel == m_app->m_numServices - 1)
    {
        if (m_app->m_numServices >= MENU_FOCUSN_COUNT)
        {
            m_targetChannel = 0;
            if (focus == m_app->m_numServices * MENU_TIMES - 1)
            {
                focus = m_app->m_numServices * (MENU_TIMES>>1);
                setFocus(focus, 0);
            }
            else
            {
                focus ++;
                setFocus(focus, WHEEL_EFFECT_TIME);
            }

        }
        else if (forceWrap)
        {
            m_targetChannel = focus = 0;
            setFocus(focus, WHEEL_EFFECT_TIME * (m_app->m_numServices - 1));
        }
        // don't allow to increase channel index
        else
        {
            setScrollIndex((VfxFloat)(focus + 0.3), WHEEL_EFFECT_TIME);
            m_timerResetScrollIdx->start();
        }
    }
    else
    {
        m_targetChannel ++;
        setFocus(++focus, WHEEL_EFFECT_TIME);
    }
}

void VappAtvWheelPanel::decChannelIndex(VfxBool forceWrap)
{
    VfxS32 focus = getFocus();

    m_timerResetScrollIdx->stop();
    if (m_targetChannel == 0)
    {
        if (m_app->m_numServices >= MENU_FOCUSN_COUNT)
        {
            m_targetChannel = m_app->m_numServices - 1;
            if (focus == 0)
            {
                focus = m_app->m_numServices * (MENU_TIMES>>1) + m_targetChannel;
                setFocus(focus, 0);
            }
            else
            {
                focus --;
                setFocus(focus, WHEEL_EFFECT_TIME);
            }

        }
        else if (forceWrap)
        {
            m_targetChannel = focus = m_app->m_numServices - 1;
            setFocus(focus, WHEEL_EFFECT_TIME * (m_app->m_numServices - 1));
        }
        // don't allow to increase channel index
        else
        {
            setScrollIndex((VfxFloat)(focus - 0.3), WHEEL_EFFECT_TIME);
            m_timerResetScrollIdx->start();
        }
    }
    else
    {
        m_targetChannel --;
        setFocus(--focus, WHEEL_EFFECT_TIME);
    }
}

void VappAtvWheelPanel::stopChangeIndexTimer()
{
    if (m_timerChangeIdx)
    {
        m_timerChangeIdx->stop();
        VFX_OBJ_CLOSE(m_timerChangeIdx);
        m_timerChangeIdx = NULL;
    }
}

// Overwrite WheelMenu function
VfxS32 VappAtvWheelPanel::getCount()
{
    if (m_app->m_numServices >= MENU_FOCUSN_COUNT)
    {
        return m_app->m_numServices * MENU_TIMES;
    }
    else
    {
        return m_app->m_numServices;
    }
}

VfxS32 VappAtvWheelPanel::getBehindCount()
{
    return MENU_SIDE_COUNT;
}

VfxS32 VappAtvWheelPanel::getAheadCount()
{
    return MENU_SIDE_COUNT;
}


void VappAtvWheelPanel::updateCellFont(VfxS32 cell, VfxTextFrame *textFrm)
{
    VfxS32 focus = getFocus() % m_app->m_numServices;
    if (focus == cell)
    {
        VfxFontDesc font(VFX_FONT_DESC_VF_SIZE(VAPP_ATV_WHEEL_CENT_TEXT_FONT_SIZE), VFX_FE1_9);
        textFrm->setFont(font);
    }
    else
    {
        VfxFontDesc font(VFX_FONT_DESC_VF_SIZE(VAPP_ATV_WHEEL_TEXT_FONT_SIZE));
        textFrm->setFont(font);
    }
}

VfxFrame* VappAtvWheelPanel::createCell(VfxS32 cell, VfxS32 subcell)
{
    VfxTextFrame *textFrm;
    VfxWChar channelNo[5];

    VFX_OBJ_CREATE(textFrm, VfxTextFrame, this);

    cell = cell % m_app->m_numServices;

    kal_wsprintf(channelNo, "%02d", m_app->m_services[cell].service_number);
    textFrm->setString(VFX_WSTR_MEM(channelNo));
    textFrm->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    textFrm->setFuzzy(VFX_TRUE);

    updateCellFont(cell, textFrm);

    textFrm->setColor(VfxColor(255, TEXT_COLOR, TEXT_COLOR, TEXT_COLOR));
    textFrm->setAnchor(0.5, 0.5);

    return textFrm;
}

void VappAtvWheelPanel::onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame)
{
    cell = cell % m_app->m_numServices;
    VfxTextFrame *textFrm = (VfxTextFrame*)frame;
    updateCellFont(cell, textFrm);
}

void VappAtvWheelPanel::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
    VFX_OBJ_CLOSE(cellFrame);
}

VcpWheelMenuFrameEffectCBFuncPtr VappAtvWheelPanel::getFrameEffectCB()
{
    return &VappAtvWheelPanel::frameEffectCB;
}

vrt_render_dirty_type_enum VappAtvWheelPanel::frameEffectCB(
    VfxS32                              cell,           // [IN] the cell index
    VfxS32                              subCell,        // [IN] the sub cell index
    VfxFloat                            cellRelPos,     // [IN] the cell position
    vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
    VfxFloat                            fPos,           // [IN] animating index value
    VfxS32                              focus,          // the focus value of the menu
    VfxRect                             viewBounds,     // the menu bounds
    void                                *userData,      // user data
    VfxU32                              userDataSize,   // user data size
    VcpWheelMenuState                   state,          // [IN] the state of Menu
    VfxFloat                            level           // [IN] the level of state
)
{

    VfxS32 origin = VAPP_ATV_WHEEL_ORIGIN_X;
    VfxS32 r = VAPP_ATV_WHEEL_RADIUS;
    VfxFloat rad = VFX_DEG_TO_RAD(VAPP_ATV_WHEEL_DEGREE * cellRelPos);
    VfxS32 boundW = viewBounds.getWidth();

    target_frame->pos.y = (VfxS32)((LCD_WIDTH>>1) + r * vfxSin(rad));
    target_frame->pos.x = (VfxS32)(origin - r * vfxCos(rad));
    target_frame->pos.x = boundW - (LCD_HEIGHT - target_frame->pos.x);

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


void VappAtvWheelPanel::onTap(VfxPoint pt)
{
    VfxS32 idx, newFocus;
    VfxTextFrame* textFrm;

    for(idx = -MENU_SIDE_COUNT; idx <= MENU_SIDE_COUNT; idx++)
    {
        newFocus = getFocus()+idx;
        textFrm = (VfxTextFrame*) getCellIfPresent(newFocus);

        // no cell
        if(!textFrm)
        {
            continue;
        }

        VfxPoint point = convertPointTo(pt, textFrm);
        point.x -= textFrm->forceGetPos().x;
        point.y -= textFrm->forceGetPos().y;

        if (!textFrm->containPoint(point, VFX_TRUE))
        {
            continue;
        }

        if (idx != 0)
        {
            setFocus(newFocus, WHEEL_EFFECT_TIME * vfxAbs(idx));

            /* Avoid mod operand is less than zero. So add m_numServices */
            m_targetChannel = (m_targetChannel + idx + m_app->m_numServices) % m_app->m_numServices;
        }
        break;
    }
}

void VappAtvWheelPanel::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
    VfxFloat scrollIdx = getScrollIndex() - (VfxFloat)yoffset / VAPP_ATV_WHEEL_CENT_TEXT_FONT_SIZE;

    if (m_app->m_numServices < MENU_FOCUSN_COUNT)
    {
        if (scrollIdx <= -0.3)
        {
            scrollIdx = (VfxFloat)-0.3;
        }
        else if (scrollIdx >= m_app->m_numServices - 1 + 0.3)
        {
            scrollIdx = (VfxFloat)(m_app->m_numServices - 1 + 0.3);
        }
    }
    setScrollIndex(scrollIdx, 0);
}

void VappAtvWheelPanel::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
    VfxS32 focus;

	if (yspeed == 0)
	{
	    focus = VfxS32(getScrollIndex() + 0.5f);
	}
	else
	{
		VfxS32   s = yspeed > 0 ? 1 : -1;
		VfxFloat m = VFX_ABS(yspeed) / 333.3f;

		if (m > 3) m = 3;

        focus = VfxS32(getScrollIndex() - s * m + 0.5f);
	}
    if (focus < 0)
    {
        focus = 0;
    }

    if (m_app->m_numServices < MENU_FOCUSN_COUNT)
    {
        if (focus >= m_app->m_numServices)
        {
            focus = m_app->m_numServices - 1;
        }
    }

    setFocus(focus, WHEEL_EFFECT_TIME);
    m_targetChannel = focus % m_app->m_numServices;

}
#endif

#ifdef __MMI_ATV_SLIM__
/*****************************************************************************
 * VappWheelMenuSlim Class
 *****************************************************************************/
VappAtvWheelPanelSlim::VappAtvWheelPanelSlim():
	m_btnPressed(VFX_FALSE),
	m_timerChangeIdx(NULL)
{
	
}

void VappAtvWheelPanelSlim::onInit()
{
	//VfxS32 bg_width;
	VfxS32 bgline_idx;
    VfxSize size;
	VcpWheelMenu::onInit();
	 // Get App
    VfxMainScr * screen = VFX_OBJ_DYNAMIC_CAST(findScreen(),VfxMainScr);
    m_app = VFX_OBJ_DYNAMIC_CAST(screen->getApp(),VappAtvApp);

    //BG
    VfxImageFrame *imgFrm;
    VFX_OBJ_CREATE(imgFrm, VfxImageFrame, this);
    imgFrm->setResId(IMG_ID_VAPP_ATV_WHEEL_PANNEL);
    imgFrm->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    imgFrm->setPos(0, -VAPP_ATV_WHEEL_SLIM_OFFSET_Y);
	imgFrm->setSize(VAPP_ATV_WHEEL_SLIM_BG_FRAME_WIDTH, VAPP_ATV_WHEEL_SLIM_BG_FRAME_HEIGHT+VAPP_ATV_WHEEL_SLIM_OFFSET_DOUBLE_Y);
	//bg_width = imgFrm->getSize().width;

	//center focus triangle
	VfxImageFrame *triangle;
	VFX_OBJ_CREATE(triangle, VfxImageFrame, this);
	triangle->setResId(IMG_ID_VAPP_ATV_WHEEL_ARROW);
    triangle->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    triangle->setPos(VAPP_ATV_WHEEL_SLIM_CENTER_TRIANGGLE_X, VAPP_ATV_WHEEL_SLIM_CENTER_TRIANGGLE_Y);
	triangle->setAnchor(0.5,0.5);

	// BG LINE
	VfxU16 bgline_step[]=
	{
		VAPP_ATV_WHEEL_SLIM_STEP_BIG, 
		VAPP_ATV_WHEEL_SLIM_STEP_SMALL,
		VAPP_ATV_WHEEL_SLIM_STEP_SMALL,
		VAPP_ATV_WHEEL_SLIM_STEP_SMALL
	};
	VfxS32 bg_y = 0;
	//VfxS32 bg_x = LCD_HEIGHT - VAPP_ATV_WHEEL_SLIM_BG_FRAME_WIDTH;
	for (bgline_idx = 0; bgline_idx<4; bgline_idx++)
	{
		bg_y += bgline_step[bgline_idx];
		VFX_OBJ_CREATE(imgFrm, VfxImageFrame, this);
		imgFrm->setResId(IMG_ID_VAPP_ATV_TBAR_BG_LINE);
		imgFrm->setBounds(0,0,
			VAPP_ATV_WHEEL_SLIM_BG_FRAME_WIDTH - VAPP_ATV_WHEEL_SLIM_LINE_X,
			imgFrm->getSize().height
			);// set the line full contain the frame
        imgFrm->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        imgFrm->setPos(VAPP_ATV_WHEEL_SLIM_LINE_X, bg_y); // Set the frame position in it's parent frame coordinate system. 
	}

	// init wheel menu focus
	initWheelFocus();

	VFX_OBJ_CREATE(m_timerResetScrollIdx, VfxTimer, this);
    m_timerResetScrollIdx->setStartDelay(DELAY_RESET_SCROLL_IDX);
    m_timerResetScrollIdx->m_signalTick.connect(
            this, &VappAtvWheelPanelSlim::resetScrollIdx);
	
	
}

void VappAtvWheelPanelSlim::resetScrollIdx(VfxTimer *timer)
{
	setScrollIndex((VfxFloat)getFocus(), WHEEL_EFFECT_TIME);
}

void VappAtvWheelPanelSlim::wheelBtnDownHdlr(VfxId id)
{
    //m_btnBGImg[id]->setResId(imgBGDownId[id]);

    m_targetChannel = getFocus() % m_app->m_numServices;

    m_btnPressed = VFX_TRUE;

    if (id == BTN_UP)
    {
        decChannelIndex(VFX_TRUE);//VFX_FALSE
    }
    else
    {
        incChannelIndex(VFX_TRUE);//VFX_FALSE
    }
}

void VappAtvWheelPanelSlim::wheelBtnUpHdlr(VfxId id)
{
    //m_btnBGImg[id]->setResId(imgBGNormalId[id]);
    m_btnPressed = VFX_FALSE;

    stopChangeIndexTimer();

    if (!getIsScrolling())
    {
        //m_signalChangeChannel.emit(m_targetChannel);
		#ifndef __MTK_TARGET__
		kal_printf("onWheelEndScroll m_targetChannel = %d",m_targetChannel);
		#else
		kal_prompt_trace(MOD_MMI, "wheelBtnUpHdlr m_targetChannel = %d",m_targetChannel);
		#endif
    }
}


void VappAtvWheelPanelSlim::wheelBtnLongPressHdlr(VfxId id)
{

}

VfxS32 VappAtvWheelPanelSlim::getAheadCount()
{
	return MENU_SIDE_COUNT;
}

VfxS32 VappAtvWheelPanelSlim::getBehindCount()
{
	return MENU_SIDE_COUNT;
}

VfxS32 VappAtvWheelPanelSlim::getCount()
{
	if (m_app->m_numServices >= MENU_FOCUSN_COUNT)
    {
        return m_app->m_numServices * MENU_TIMES;
    }
    else
    {
        return m_app->m_numServices;
    }
}

void VappAtvWheelPanelSlim::initWheelFocus()
{
	VfxS32 focus;
    VfxS32 nFocus = m_app->m_numServices * (MENU_TIMES>>1);

    if (m_app->m_liveScan)
    {
        switch (m_app->m_numServices)
        {
            case 1:
            case 2:
                focus = 0;
                break;
            case 3:
            case 4:
                focus = 1;
                break;
            default:
                focus = nFocus;
        }

        // Init selected channel
        m_app->m_setting.selected_channel = focus % m_app->m_numServices;
    }
    else
    {
        // check if original selected channel is valid
        if (m_app->m_setting.selected_channel >= m_app->m_numServices)
        {
            m_app->m_setting.selected_channel = 0;
        }

        // use the original selected channel
        if (m_app->m_numServices < MENU_FOCUSN_COUNT)
        {
            focus = m_app->m_setting.selected_channel;
        }
        else
        {
            focus = nFocus + m_app->m_setting.selected_channel;
        }
    }

    m_targetChannel = m_app->m_setting.selected_channel;
    setFocus(focus, 0);
}

void VappAtvWheelPanelSlim::incChannelTimeout(VfxTimer *timer)
{
    incChannelIndex(VFX_TRUE);//VFX_FALSE
    timer->start();
}

void VappAtvWheelPanelSlim::decChannelTimeout(VfxTimer *timer)
{
    decChannelIndex(VFX_TRUE);//VFX_FALSE
    timer->start();
}


void VappAtvWheelPanelSlim::incChannelIndex(VfxBool forceWrap)
{
	VfxS32 focus = getFocus();

    m_timerResetScrollIdx->stop();
    if (m_targetChannel == m_app->m_numServices - 1)
    {
        if (m_app->m_numServices >= MENU_FOCUSN_COUNT)
        {
            m_targetChannel = 0;
            if (focus == m_app->m_numServices * MENU_TIMES - 1)
            {
                focus = m_app->m_numServices * (MENU_TIMES>>1);
                setFocus(focus, 0);
            }
            else
            {
                focus ++;
                setFocus(focus, WHEEL_EFFECT_TIME);
            }

        }
        else if (forceWrap)
        {
            m_targetChannel = focus = 0;
            setFocus(focus, WHEEL_EFFECT_TIME * (m_app->m_numServices - 1));
        }
        // don't allow to increase channel index
        else
        {
            setScrollIndex((VfxFloat)(focus + 0.3), WHEEL_EFFECT_TIME);
            m_timerResetScrollIdx->start();
        }
    }
    else
    {
        m_targetChannel ++;
        setFocus(++focus, WHEEL_EFFECT_TIME);
    }
}

void VappAtvWheelPanelSlim::decChannelIndex(VfxBool forceWrap)
{
	VfxS32 focus = getFocus();

    m_timerResetScrollIdx->stop();
    if (m_targetChannel == 0)
    {
        if (m_app->m_numServices >= MENU_FOCUSN_COUNT)
        {
            m_targetChannel = m_app->m_numServices - 1;
            if (focus == 0)
            {
                focus = m_app->m_numServices * (MENU_TIMES>>1) + m_targetChannel;
                setFocus(focus, 0);
            }
            else
            {
                focus --;
                setFocus(focus, WHEEL_EFFECT_TIME);
            }

        }
        else if (forceWrap)
        {
            m_targetChannel = focus = m_app->m_numServices - 1;
            setFocus(focus, WHEEL_EFFECT_TIME * (m_app->m_numServices - 1));
        }
        // don't allow to increase channel index
        else
        {
            setScrollIndex((VfxFloat)(focus - 0.3), WHEEL_EFFECT_TIME);
            m_timerResetScrollIdx->start();
        }
    }
    else
    {
        m_targetChannel --;
        setFocus(--focus, WHEEL_EFFECT_TIME);
    }
}

void VappAtvWheelPanelSlim::stopChangeIndexTimer()
{
	if (m_timerChangeIdx)
    {
        m_timerChangeIdx->stop();
        VFX_OBJ_CLOSE(m_timerChangeIdx);
        m_timerChangeIdx = NULL;
    }
}

VcpWheelMenuFrameEffectCBFuncPtr VappAtvWheelPanelSlim::getFrameEffectCB()
{
    return &VappAtvWheelPanelSlim::frameEffectCB;
}

vrt_render_dirty_type_enum VappAtvWheelPanelSlim::frameEffectCB(
    VfxS32                              cell,           // [IN] the cell index
    VfxS32                              subCell,        // [IN] the sub cell index
    VfxFloat                            cellRelPos,     // [IN] the cell position
    vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
    VfxFloat                            fPos,           // [IN] animating index value
    VfxS32                              focus,          // the focus value of the menu
    VfxRect                             viewBounds,     // the menu bounds
    void                                *userData,      // user data
    VfxU32                              userDataSize,   // user data size
    VcpWheelMenuState                   state,          // [IN] the state of Menu
    VfxFloat                            level           // [IN] the level of state
)
{
	VfxS32 posCenter = VAPP_ATV_WHEEL_SLIM_BG_FRAME_HEIGHT>>1;

	target_frame->pos.x = VAPP_ATV_WHEEL_SLIM_TARGET_FRAME_X;
	target_frame->pos.y = (VfxS32)(cellRelPos*VAPP_ATV_WHEEL_SLIM_STEP_SMALL + posCenter); // y = cellRelPos * range + central position y

    return VRT_RENDER_DIRTY_TYPE_DIRTY;
}


VfxFrame* VappAtvWheelPanelSlim::createCell(VfxS32 cell, VfxS32 subcell)
{
	VfxTextFrame *textFrm;
	VfxWChar channelNo[5];

    VFX_OBJ_CREATE(textFrm, VfxTextFrame, this);

    cell = cell % m_app->m_numServices;

    kal_wsprintf(channelNo, "%02d", m_app->m_services[cell].service_number);
    textFrm->setString(VFX_WSTR_MEM(channelNo));
    textFrm->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    textFrm->setFuzzy(VFX_TRUE);

    updateCellFont(cell, textFrm);

    //textFrm->setColor(VfxColor(255, TEXT_COLOR_FOCUS_R, TEXT_COLOR_FOCUS_G, TEXT_COLOR_FOCUS_B));
    textFrm->setAnchor(0.5, 0.5);
	return textFrm;
}

void VappAtvWheelPanelSlim::updateCellFont(VfxS32 cell, VfxTextFrame *textFrm)
{
	VfxS32 focus = getFocus() % m_app->m_numServices;
    if (focus == cell)
    {
        VfxFontDesc font(VFX_FONT_DESC_VF_SIZE(VAPP_ATV_WHEEL_SLIM_CENT_TEXT_FONT_SIZE), VFX_FE1_9);
        textFrm->setFont(font);
		textFrm->setColor(VfxColor(255, TEXT_COLOR_FOCUS_R, TEXT_COLOR_FOCUS_G, TEXT_COLOR_FOCUS_B));
    }
    else
    {
        VfxFontDesc font(VFX_FONT_DESC_VF_SIZE(VAPP_ATV_WHEEL_SLIM_TEXT_FONT_SIZE));
        textFrm->setFont(font);
		textFrm->setColor(VfxColor(255, TEXT_COLOR_NORMAL, TEXT_COLOR_NORMAL, TEXT_COLOR_NORMAL));
    }
}

void VappAtvWheelPanelSlim::onUpdateCell(VfxS32 cell, VfxS32 subcell, VfxFrame* frame)
{
	cell = cell % m_app->m_numServices;
    VfxTextFrame *textFrm = (VfxTextFrame*)frame;
    updateCellFont(cell, textFrm);
}

void VappAtvWheelPanelSlim::onCloseCell(VfxS32 cell, VfxS32 subcell, VfxFrame* cellFrame)
{
	VFX_OBJ_CLOSE(cellFrame);
}

void VappAtvWheelPanelSlim::onTap(VfxPoint pt)
{
	VfxS32 idx, newFocus;
    VfxTextFrame* textFrm;

    for(idx = -MENU_SIDE_COUNT; idx <= MENU_SIDE_COUNT; idx++)
    {
        newFocus = getFocus()+idx;
        textFrm = (VfxTextFrame*) getCellIfPresent(newFocus);

        // no cell
        if(!textFrm)
        {
            continue;
        }

        VfxPoint point = convertPointTo(pt, textFrm);
        point.x -= textFrm->forceGetPos().x;
        point.y -= textFrm->forceGetPos().y;

        if (!textFrm->containPoint(point, VFX_TRUE))
        {
            continue;
        }

        if (idx != 0)
        {
            setFocus(newFocus, WHEEL_EFFECT_TIME * vfxAbs(idx));

            /* Avoid mod operand is less than zero. So add m_numServices */
            m_targetChannel = (m_targetChannel + idx + m_app->m_numServices) % m_app->m_numServices;
        }
        break;
    }
	//m_signalChangeChannel.emit(m_targetChannel);
	kal_prompt_trace(MOD_MMI,"[VAPP_ATV]ontap end \n");
}

void VappAtvWheelPanelSlim::onDrag(VfxS32 xoffset, VfxS32 yoffset)
{
	VfxFloat scrollIdx = getScrollIndex() - (VfxFloat)yoffset / VAPP_ATV_WHEEL_SLIM_CENT_TEXT_FONT_SIZE;

	//kal_printf("scrollIdx = %f, yoffset = %d \n",scrollIdx,yoffset);

    if (m_app->m_numServices < MENU_FOCUSN_COUNT)
    {
        if (scrollIdx <= -0.3)
        {
            scrollIdx = (VfxFloat)-0.3;
        }
        else if (scrollIdx >= m_app->m_numServices - 1 + 0.3)
        {
            scrollIdx = (VfxFloat)(m_app->m_numServices - 1 + 0.3);
        }
    }
    setScrollIndex(scrollIdx, 0);
}

void VappAtvWheelPanelSlim::onDragEnd(VfxS32 xspeed, VfxS32 yspeed)
{
	VfxS32 focus;

	if (yspeed == 0)
	{
	    focus = VfxS32(getScrollIndex() + 0.5f);
	}
	else
	{
		VfxS32   s = yspeed > 0 ? 1 : -1;
		VfxFloat m = VFX_ABS(yspeed) / 333.3f;

		if (m > 3) m = 3;

        focus = VfxS32(getScrollIndex() - s * m + 0.5f);
	}
    if (focus < 0)
    {
        focus = 0;
    }

    if (m_app->m_numServices < MENU_FOCUSN_COUNT)
    {
        if (focus >= m_app->m_numServices)
        {
            focus = m_app->m_numServices - 1;
        }
    }

    setFocus(focus, WHEEL_EFFECT_TIME);
    m_targetChannel = focus % m_app->m_numServices;
	//m_signalChangeChannel.emit(m_targetChannel);
	//kal_printf("m_targetChannel = %d",m_targetChannel);
	kal_prompt_trace(MOD_MMI,"[VAPP_ATV]onDragEnd end \n");
}

#endif
/*****************************************************************************
 * VappAtvImgButton Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvImgButton", VappAtvImgButton, VfxControl);

VappAtvImgButton::VappAtvImgButton(
    VfxResId imgId, VfxS32 ctrlWidth, VfxS32 ctrlHeight, VfxS32 imgX, VfxS32 imgY):
    m_imgId(imgId),
    m_ctrlWidth(ctrlWidth),
    m_ctrlHeight(ctrlHeight),
    m_imgX(imgX),
    m_imgY(imgY),
    m_callbackId(0),
    m_imgFrame(NULL)
{
    setFuzzy(VFX_TRUE);
}


void VappAtvImgButton::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_imgFrame, VfxImageFrame, this);
    m_imgFrame->setResId(m_imgId);
    m_imgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    VfxSize size = m_imgFrame->getSize();
	#ifndef __MMI_ATV_SLIM__
    m_imgFrame->setPos(m_imgX, m_imgY);
	#else
	m_imgFrame->setPos(m_imgX + VAPP_ATV_TBAR_BG_GAP, m_imgY);
	#endif

    if (m_ctrlWidth == 0 || m_ctrlWidth == 0)
    {
        setBounds(0, 0, size.width, size.height);
    }
    else
    {
        setBounds(0, 0, m_ctrlWidth, m_ctrlHeight);
    }
}

void VappAtvImgButton::setImgId(VfxId imgId)
{
    m_imgId = imgId;
    m_imgFrame->setResId(m_imgId);
}

VfxId VappAtvImgButton::getImgId()
{
    return m_imgId;
}

void VappAtvImgButton::setCallbackId(VfxId id)
{
    m_callbackId = id;
}

VfxBool VappAtvImgButton::onPenInput(VfxPenEvent &event)
{
    m_signalPenEvent.emit(event, m_callbackId);
    return VFX_TRUE;
}

/*****************************************************************************
 * VappAtvThumbButton Class
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappAtvThumbButton", VappAtvThumbButton, VfxControl);


VappAtvThumbButton::VappAtvThumbButton(VfxImageSrc *imgSrc):
    m_imgSrc(*imgSrc)
{
}


void VappAtvThumbButton::onInit()
{
    VfxControl::onInit();



    // thumbnail
    VfxImageFrame *thumImgFrm;
    VFX_OBJ_CREATE(thumImgFrm, VfxImageFrame, this);
    thumImgFrm->setImgContent(m_imgSrc);
    thumImgFrm->setSize(VAPP_ATV_THUMBNAIL_W, VAPP_ATV_THUMBNAIL_H);
    thumImgFrm->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);


    // border
    VfxImageFrame *borderImgFrm;
    VFX_OBJ_CREATE(borderImgFrm, VfxImageFrame, this);
#ifndef __MMI_ATV_SLIM__
    borderImgFrm->setResId(IMG_ID_VAPP_ATV_REC_LAST_FRAME);
#else

#endif
    borderImgFrm->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    borderImgFrm->setPos(0, 0);

    // set attribute
    VfxSize borderSize = borderImgFrm->getSize();
    setBounds(0, 0, borderSize.width, borderSize.height);

    // set thumbnail position as center align
    VfxSize thumbSize = thumImgFrm->getSize();
    thumImgFrm->setPos(
        (borderSize.width - thumbSize.width)>>1,
        (borderSize.height - thumbSize.height)>>1);
}

VfxBool VappAtvThumbButton::onPenInput(VfxPenEvent &event)
{
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {

    }
    // don't handle pen abort event
    else if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        // click
        if (containPoint(event.getRelPos(this)))
        {
            m_signalClicked.emit();
        }
    }
    return VFX_TRUE;
}

#endif // __MMI_ATV_SUPPORT__

