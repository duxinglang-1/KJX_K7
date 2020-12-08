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
 *  vapp_soundrec.cpp
 *
 * Project:
 * --------
 *  Cosmos
 *
 * Description:
 * ------------
 *  Sound recorder source code file
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
 *
 * removed!
 * removed!
 *
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

#ifdef __MMI_SOUNDREC_SLIM__

#include "vapp_soundrec_slim.h"
#include "vapp_soundrec_util_slim.h"
#include "mmi_rp_vapp_soundrec_def.h"
#include "vapp_vol_dialog_gprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "vapp_usb_gprot.h"
#endif
#include "vapp_ncenter_gprot.h"
#include "vapp_screen_lock_gprot.h"
//#include "vapp_fmgr_gprot.h"


/* Pluto MMI headers */
#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_media_app_trc.h"
#include "mmi_rp_srv_prof_def.h"
#include "mdi_audio.h"
#include "app_str.h"
#include "FileMgrSrvGProt.h"
#include "vapp_fmgr_cui_gprot.h"
#include "Fs_gprot.h"
#include "SoundRecSrvGProt.h"
#include "AppMgrSrvGprot.h"
#include "ProfilesSrvGprot.h"
#include "UcmSrvGprot.h"
#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGProt.h"
#endif
#include "Wgui_categories_util.h"
#ifdef __cplusplus
}
#endif

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
 * Function
 *****************************************************************************/

extern "C" mmi_id vapp_soundrec_launch_app(void)
{
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__)
	DCM_Load(DYNAMIC_CODE_COMPRESS_SOUNDREC, 0, 0);
#endif
    return VfxAppLauncher::launch( 
                    VAPP_SOUNDREC,
                    VFX_OBJ_CLASS_INFO(VappSoundRecorderApp),
                    GRP_ID_ROOT);
}

extern "C" MMI_ID vapp_soundrec_launch(mmi_app_launch_param_struct* param, U32 param_size)
{
    MMI_ID app_id = GRP_ID_INVALID;
	
#ifdef __MMI_USB_SUPPORT__
    /* check is in mass storage mode */
    if (srv_usb_is_in_mass_storage_mode())
    {
        vapp_usb_unavailable_popup(0);
        return GRP_ID_INVALID;
    }
#endif /* __MMI_USB_SUPPORT__ */ 

    if (param == NULL && param_size == 0)
    {
        app_id = vapp_soundrec_launch_app();
    }
    else
    {
        switch (param->cat)
        {
            case MMI_LAUNCH_APP_IN_OPEN_CATEGORY:
            app_id = vapp_soundrec_launch_app();
            break;
        }
    }
    return app_id;
}

#pragma arm section code = "DYNAMIC_CODE_SOUNDREC_ROCODE", rodata = "DYNAMIC_CODE_SOUNDREC_RODATA"
 

/***************************************************************************** 
 * Class VappSoundRecorderApp implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSoundRecorderApp", VappSoundRecorderApp, VfxApp);

void VappSoundRecorderApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize); 

    /* create and display main screen */
    VFX_OBJ_CREATE(scr, VappSoundRecorderScreen, this);
    scr->show();
}

void VappSoundRecorderApp::onInit()
{
    VfxApp::onInit();

    /*Register event handler when APP running */
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappSoundRecorderApp::eventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappSoundRecorderApp::eventHandler, this);

#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_USB_ENTER_MS_MODE, &VappSoundRecorderApp::eventHandler, this);
#endif
}

void VappSoundRecorderApp::onDeinit()
{
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, &VappSoundRecorderApp::eventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, &VappSoundRecorderApp::eventHandler, this);
#ifdef __MMI_USB_SUPPORT__
    mmi_frm_cb_dereg_event(EVT_ID_USB_ENTER_MS_MODE, &VappSoundRecorderApp::eventHandler, this);
#endif

    VfxApp::onDeinit();
#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_C__)
    DCM_Unload(DYNAMIC_CODE_COMPRESS_SOUNDREC);
#endif

}

mmi_ret VappSoundRecorderApp::eventHandler(mmi_event_struct *evt)
{
    if (evt->user_data == NULL)
        return MMI_RET_OK;

    VappSoundRecorderApp* app = (VappSoundRecorderApp*) evt->user_data;

    switch (evt->evt_id)
    {
    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            /* Exit application */
            app->exit();
            break;
        }
    #endif
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
        {
            app->scr->notifyTopPage(evt);
            break;
        }
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
             app->scr->notifyTopPage(evt);
            break;
        }
    }
    return MMI_RET_OK;
}

/***************************************************************************** 
 * Class VappSoundRecorderScreen implementation
 *****************************************************************************/
void VappSoundRecorderScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    /* create and display first page */
    VappSoundRecorderRecordPage *page;
    VFX_OBJ_CREATE(page, VappSoundRecorderRecordPage, this);
    pushPage(0, page);
}

void VappSoundRecorderScreen::notifyTopPage(mmi_event_struct *evt)
{
    VfxPage *topPage = getPage(0);
    if(topPage != NULL)
    {
        topPage->processProc(evt);
    }
}

/***************************************************************************** 
 * Class VappSoundRecorderRecordPage implementation
 *****************************************************************************/
VappSoundRecorderRecordPage::VappSoundRecorderRecordPage() :
m_btnPressed(SNDREC_BTN_TOTAL),
m_text_record_file_name(NULL),
m_text_record_time(NULL),
m_text_remain_time(NULL),
m_confirmPopup(NULL),
m_indicator(NULL)
{
}

void VappSoundRecorderRecordPage::onInit()
{
    VfxPage::onInit();

    /* Init variables */
    m_state = SNDREC_STATE_IDLE;
    m_current_time = 0;
    m_check_remain_timer_dur = 0;

#ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
	// Init member variables
	m_storageType = ((srv_fmgr_drv_get_type(srv_soundrec_get_storage()) == SRV_FMGR_DRV_CARD_TYPE) ? SNDREC_STORAGE_MEMORY_CARD : SNDREC_STORAGE_PHONE);
	m_selectStoragePopup = NULL;
#endif

    /* Create page components */
    createScreenComponent();

    mmi_frm_cb_reg_event(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, &VappSoundRecorderRecordPage::eventHandler, this);
}

void VappSoundRecorderRecordPage::onDeinit()
{
    /* Force stop and show info ballon to inform user when exit app */
    if(SNDREC_STATE_IDLE != m_state)
    {
        recordStop(VFX_TRUE);    
        mmi_frm_nmgr_balloon(
            MMI_SCENARIO_ID_DEFAULT,
            MMI_EVENT_INFO_BALLOON,
            MMI_NMGR_BALLOON_TYPE_INFO,
            (WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_SNDREC_RECORD_SAVED).getBuf());  
    }

    VfxPage::onDeinit();

    mmi_frm_cb_dereg_event(EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING, &VappSoundRecorderRecordPage::eventHandler, this);
}

void VappSoundRecorderRecordPage::onEnter(VfxBool isBackward)
{
    /* Update remain time string */
    updateRemainTimeText(VFX_TRUE);
}

void VappSoundRecorderRecordPage::onExit(VfxBool isBackward)
{
    /* Always turn off now since Ogg can not resume interrupted record */
#ifdef __COSMOS_SOUNDREC_INTERRUPT_SUPPORT__
    if(SNDREC_STATE_RECORD == m_state || SNDREC_STATE_PAUSE == m_state)
    {
        recordStop(VFX_FALSE);
    }
#else
    stopRecordAndExit(VFX_FALSE);
#endif

    /* If finding path, stop it when exit screen */
    m_timer_find_name->stop();
    stopLoading();

	m_timer_error_check->stop();
}


mmi_ret VappSoundRecorderRecordPage::onProc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {
		#ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
			if(m_selectStoragePopup != NULL)
			{				
				m_selectStoragePopup->setIsDisableItem(SNDREC_STORAGE_MEMORY_CARD, VFX_TRUE);
			}			
			
            VfxU8 drive = srv_soundrec_get_storage();
            if(SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(drive))
		#endif
			{
				if(m_timer_find_name->getIsEnabled())
				{
					m_timer_find_name->stop();
					stopLoading();
				}

	            updateRemainTimeText(VFX_TRUE);
				
	            if(SNDREC_STATE_IDLE != m_state)
	            {
	                recordStop(VFX_TRUE);
	            }
            }
            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
		{
            updateRemainTimeText(VFX_TRUE);

		#ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
			if(m_selectStoragePopup != NULL)
			{
				m_selectStoragePopup->setIsDisableItem(SNDREC_STORAGE_MEMORY_CARD, VFX_FALSE);
			}
		#endif
            break;
        }
		
        case EVT_ID_VAPP_NCENTER_DRAG:
		{
            if(m_state != SNDREC_STATE_IDLE)
            {
                /* Disable NCenter drag down to avoid exit sound recorder */
                return MMI_RET_ERR;
            }
            else
            {
                return VfxPage::onProc(evt);
            }
        }
		
        default:
            return VfxPage::onProc(evt);
    }
    return MMI_RET_OK;
}

mmi_ret VappSoundRecorderRecordPage::eventHandler(mmi_event_struct *evt)
{
    VappSoundRecorderRecordPage* page = (VappSoundRecorderRecordPage*) evt->user_data;

    switch (evt->evt_id)
    {
        case EVT_ID_VAPP_SCREEN_LOCK_PRE_LOCK_EVT_ROUTING:
            if(SNDREC_STATE_RECORD == page->m_state || SNDREC_STATE_PAUSE == page->m_state)
            {
                return MMI_RET_ERR;
            }
            break;
        default:
            break;
    }

    return MMI_RET_OK;
}

void VappSoundRecorderRecordPage::onButtonClicked(VfxObject* obj, VfxId id)
{
	// record the button pressed
	m_btnPressed = (SoundrRecBtnEnum) id;

    switch(m_btnPressed)
    {		
        case SNDREC_BTN_REC:
        {
            if(m_state == SNDREC_STATE_IDLE)
            {
                if(findRecordPath())
                {
                    recordStart();
                }
            }
            else if(m_state == SNDREC_STATE_INTERRUPTED)
            {
                recordStart();
            }
            else if(m_state == SNDREC_STATE_RECORD)
            {
                recordPause();
            }
            else if(m_state == SNDREC_STATE_PAUSE)
            {
                recordResume();
            }
            break;
        }
		
        case SNDREC_BTN_STOP:
		{
            stopRecordAndExit(VFX_TRUE);

            /* If still in finding record path path process, stop it when user press stop */
            if(m_timer_find_name->getIsEnabled())
            {
                m_timer_find_name->stop();
                stopLoading();
            }
            break;
        }

		case SNDREC_BTN_TOOL_BAR_REC_LIST:
        {		
			if(checkRecordPath())
			{
				// Enter file manager
				FMGR_FILTER filter;
    			FMGR_FILTER_SET_ALL(&filter);
				vapp_fmgr_launch_by_app((WCHAR *) m_record_path, &filter);
			}

            break;
        }
		
    #ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
		case SNDREC_BTN_TOOL_BAR_STORAGE:
        {
			selectStoragePopup();
			break;
		}
    #endif

        default:
            break;
    }
}

#ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__ 
void VappSoundRecorderRecordPage::setStorageType(SoundrRecStorageEnum storageType)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_RECPAGE_SET_STORAGE_TYPE, storageType);

	m_storageType = storageType;

	srv_fmgr_drv_type_enum drv_type = ((storageType == SNDREC_STORAGE_PHONE) ? SRV_FMGR_DRV_PHONE_TYPE : SRV_FMGR_DRV_CARD_TYPE) ;
	srv_soundrec_set_storage(srv_fmgr_drv_get_letter_by_type(drv_type));	
	
	updateRemainTimeText(VFX_TRUE);
}

void VappSoundRecorderRecordPage::selectStoragePopup(void)
{	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_RECPAGE_SELECT_STORAGE_POPUP, m_storageType);

    VFX_OBJ_CREATE(m_selectStoragePopup, VcpSelectPopup, this);
	m_selectStoragePopup->setText(STR_ID_VAPP_SNDREC_SELECT_STORAGE);
	VfxBool isPhoneDrive = (m_storageType == SNDREC_STORAGE_PHONE);
	m_selectStoragePopup->addItem(SNDREC_STORAGE_PHONE, VFX_WSTR_RES(STR_GLOBAL_PHONE), isPhoneDrive);
	m_selectStoragePopup->addItem(SNDREC_STORAGE_MEMORY_CARD, VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD), !isPhoneDrive);	
    m_selectStoragePopup->setAutoDestory(VFX_TRUE);
    m_selectStoragePopup->m_signalButtonClicked.connect(this, &VappSoundRecorderRecordPage::onStorageSelected);

	if(!vapp_soundrec_util_check_memory_card_ready())
	{
		m_selectStoragePopup->setIsDisableItem(SNDREC_STORAGE_MEMORY_CARD, VFX_TRUE);
	}
	
	m_selectStoragePopup->show(VFX_TRUE);
}

void VappSoundRecorderRecordPage::onStorageSelected(VfxObject* sender, VfxId id)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_RECPAGE_ON_STORAGE_SELECTED, id, id);
	
    VcpSelectPopup *storagePopup = (VcpSelectPopup*)sender;
	SoundrRecStorageEnum storageType = (SoundrRecStorageEnum) storagePopup->getFirstSeletedId();;
	if(storageType != m_storageType)
	{
		// Storage is changed, need to save it.
		setStorageType(storageType);
	}

	VFX_OBJ_CLOSE(m_selectStoragePopup);
	m_selectStoragePopup = NULL;
}


void VappSoundRecorderRecordPage::showDefaultStoragePopup(void)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_RECPAGE_SHOW_DEFAULT_STORAGE_POPUP);

    /* Show confirm popup */
    VcpConfirmPopup *storagePopup;
    VFX_OBJ_CREATE(storagePopup, VcpConfirmPopup, this);
    storagePopup->setInfoType(VCP_POPUP_TYPE_QUESTION);
    storagePopup->setText(VFX_WSTR_RES(STR_GLOBAL_MC_REMOVED_USE_PHONE));
    storagePopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_YES_NO);
    storagePopup->m_signalButtonClicked.connect(this, &VappSoundRecorderRecordPage::onDefaultStorageConfirm);
    storagePopup->setAutoDestory(VFX_TRUE);
    storagePopup->show(VFX_TRUE);
}

void VappSoundRecorderRecordPage::onDefaultStorageConfirm(VfxObject* vfx_obj, VfxId id)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_RECPAGE_ON_DEFAULT_STORAGE_CONFIRM, id);

    if (id == VCP_CONFIRM_POPUP_BUTTON_YES)
    {
		setStorageType(SNDREC_STORAGE_PHONE);		

		onButtonClicked(this, m_btnPressed);
    }
}
#endif // __MMI_SOUNDREC_SLIM_PHONE_DRIVE__

void VappSoundRecorderRecordPage::onUpdateTimerExpir(VfxTimer *timer)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_RECPAGE_UPDATE_TIMER, m_state);
    
    if(m_state == SNDREC_STATE_RECORD)
    {
    #ifdef __MTK_TARGET__
        m_current_time = mdi_audio_get_record_time() + m_accumulate_time;
    #else
        m_current_time = (m_current_time/1000 + 1)*1000;
    #endif

        MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_RECPAGE_UPDATE_TIMER_GET_TIME, static_cast<VfxS32>(m_current_time));
        updateTimeText(m_text_record_time, m_current_time);
    }

}

void VappSoundRecorderRecordPage::onCheckRemainTimerExpir(VfxTimer *timer)
{
    /* Update remain time string */
    updateRemainTimeText(VFX_FALSE);
}

void VappSoundRecorderRecordPage::onErrorCheckTimerExpir(VfxTimer *timer)
{
    /* Update remain time string */
    updateRemainTimeText(VFX_TRUE);
}


void VappSoundRecorderRecordPage::onFindPathTimerExpir(VfxTimer *timer)
{
    // TODO: Add trace here

    if(findRecordPathLoop())
    {
        /* Write to NVRAM after record success */
        stopLoading();
        recordStart();
    }
    else
    {
        /* Can't find record path, show error*/
        if(m_last_seq == m_stop_seq)
        {
            /* Check for stop sequence again to avoid last seq unchecked */
            if(findRecordPathLoop())
            {
                /* Write to NVRAM after record success */
                stopLoading();
                recordStart();
            }
            else
            {
                stopLoading();
                showConfirmPopup(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_ERR_MAX_SEQ));
            }
        }
        else
        {
            /* Continue to find */
            m_timer_find_name->start();
        }
    }
}

void VappSoundRecorderRecordPage::createScreenComponent(void)
{
	// set background color
	setBgColor(MAIN_PAGE_BG_COLOR);
	
    // Create tool bar
	VFX_OBJ_CREATE(m_toolbar, VcpToolBar, this);
	m_toolbar->addItem(SNDREC_BTN_TOOL_BAR_REC_LIST, VFX_WSTR_RES(STR_ID_VAPP_SNDREC_RECLIST), VCP_IMG_TOOL_BAR_COMMON_ITEM_LIST);
#ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__	
	m_toolbar->addItem(SNDREC_BTN_TOOL_BAR_STORAGE, VFX_WSTR_RES(STR_GLOBAL_STORAGE), VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE);
#endif

	m_toolbar->m_signalButtonTap.connect(this, &VappSoundRecorderRecordPage::onButtonClicked);
	setBottomBar(m_toolbar);
	
	// Create record file name 	
    VFX_OBJ_CREATE(m_text_record_file_name, VfxTextFrame, this);
	m_text_record_file_name->setAnchor(0.5f,0);
	m_text_record_file_name->setPos(TEXT_RECORD_FILE_NAME_X,TEXT_RECORD_FILE_NAME_Y);
	m_text_record_file_name->setSize(TEXT_RECORD_FILE_NAME_WIDTH,TEXT_RECORD_FILE_NAME_HEIGHT);
    m_text_record_file_name->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_RECORD_FILE_NAME_FONT_SIZE)));
	m_text_record_file_name->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	m_text_record_file_name->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_text_record_file_name->setColor(VFX_COLOR_WHITE);
	
	// Create remain time 	
    VFX_OBJ_CREATE(m_text_remain_time, VfxTextFrame, this);
	m_text_remain_time->setAnchor(0.5f,0);
	m_text_remain_time->setPos(TEXT_REMAIN_TIME_X,TEXT_REMAIN_TIME_Y);
	m_text_remain_time->setSize(TEXT_REMAIN_TIME_WIDTH,TEXT_REMAIN_TIME_HEIGHT);
    m_text_remain_time->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_REMAIN_TIME_FONT_SIZE)));
    m_text_remain_time->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	m_text_remain_time_color = VFX_COLOR_WHITE;

	// Create record time 	
    VFX_OBJ_CREATE(m_text_record_time, VfxTextFrame, this);
	m_text_record_time->setPos(TEXT_RECORD_TIME_X,TEXT_RECORD_TIME_Y);
	m_text_record_time->setSize(TEXT_RECORD_TIME_WIDTH,TEXT_RECORD_TIME_HEIGHT);
    m_text_record_time->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TEXT_RECORD_TIME_FONT_SIZE)));
	m_text_record_time->setColor(VFX_COLOR_WHITE);
	m_text_record_time->setString(VFX_WSTR("00:00:00"));
	
    // Create record button 	
    VFX_OBJ_CREATE(m_image_btn_rec, VcpButton, this);
    m_image_btn_rec->setId(SNDREC_BTN_REC);
	m_image_btn_rec->setMargin(0,0,0,0);
	m_image_btn_rec->setAnchor(0,1);
	m_image_btn_rec->setPos(BTN_RECORD_X,BTN_RECORD_Y);
	m_image_btn_rec->setSize(BTN_RECORD_WIDTH,BTN_RECORD_HEIGHT);
	m_image_btn_rec->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_REC,IMG_ID_VAPP_SNDREC_BTN_REC,IMG_ID_VAPP_SNDREC_BTN_REC_D,0));
	m_image_btn_rec->setBgImageList(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_BG1_N,IMG_ID_VAPP_SNDREC_BTN_BG1_P,IMG_ID_VAPP_SNDREC_BTN_BG1_N,0));
	m_image_btn_rec->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_image_btn_rec->m_signalClicked.connect(this, &VappSoundRecorderRecordPage::onButtonClicked);
	m_image_btn_rec->setFuzzy(VFX_FALSE);
	
    /* Create stop button */
	VFX_OBJ_CREATE(m_image_btn_stop, VcpButton, this);
    m_image_btn_stop->setId(SNDREC_BTN_STOP);
	m_image_btn_stop->setMargin(0,0,0,0);
	m_image_btn_stop->setAnchor(1,1);
	m_image_btn_stop->setPos((LCD_WIDTH - BTN_RECORD_X),BTN_RECORD_Y);
	m_image_btn_stop->setSize(BTN_RECORD_WIDTH,BTN_RECORD_HEIGHT);
	m_image_btn_stop->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_STOP,IMG_ID_VAPP_SNDREC_BTN_STOP,IMG_ID_VAPP_SNDREC_BTN_STOP_D,0));
	m_image_btn_stop->setBgImageList(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_BG1_N,IMG_ID_VAPP_SNDREC_BTN_BG1_P,IMG_ID_VAPP_SNDREC_BTN_BG1_N,0));
	m_image_btn_stop->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    m_image_btn_stop->m_signalClicked.connect(this, &VappSoundRecorderRecordPage::onButtonClicked);
    m_image_btn_stop->setIsDisabled(VFX_TRUE);
	m_image_btn_stop->setFuzzy(VFX_FALSE);

    /* Create screen update timer for recording */
    VFX_OBJ_CREATE(m_timer_update, VfxTimer, this);
    m_timer_update->setStartDelay(0);
    m_timer_update->setDuration(TIMER_UPDATE_CURRENT_TIME);
    m_timer_update->m_signalTick.connect(this, &VappSoundRecorderRecordPage::onUpdateTimerExpir);

    VFX_OBJ_CREATE(m_timer_check_remain, VfxTimer, this);
    m_timer_check_remain->setStartDelay(TIMER_CHECK_REMAIN_TIME);
    m_timer_check_remain->setDuration(TIMER_CHECK_REMAIN_TIME);
    m_timer_check_remain->m_signalTick.connect(this, &VappSoundRecorderRecordPage::onCheckRemainTimerExpir);

    VFX_OBJ_CREATE(m_timer_error_check, VfxTimer, this);
    m_timer_error_check->setStartDelay(TIMER_CHECK_REMAIN_TIME);
    m_timer_error_check->m_signalTick.connect(this, &VappSoundRecorderRecordPage::onErrorCheckTimerExpir);

    VFX_OBJ_CREATE(m_timer_find_name, VfxTimer, this);
    m_timer_find_name->setStartDelay(TIMER_FIND_NAME);
    m_timer_find_name->m_signalTick.connect(this, &VappSoundRecorderRecordPage::onFindPathTimerExpir);

}

VfxU64 VappSoundRecorderRecordPage::updateRemainTimeText(VfxBool forceUpdate)
{
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_RECPAGE_UPDATE_REMAIN_TIME, forceUpdate);

    /* Check if memory card exists, only update when force update called */
    if(forceUpdate)
    {
    #ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
        VfxU8 m_drive = srv_soundrec_get_storage();
        if(SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(m_drive))
	#endif
		{
			 VfxWChar record_drive[10];
			 S32 fs_handle;
			 
			 kal_wsprintf(record_drive, "%c:\\", vapp_soundrec_util_get_storage_drive());
			 if((fs_handle = FS_Open(record_drive, FS_READ_ONLY)) < FS_NO_ERROR)
			 {
				 m_text_remain_time->setColor(m_text_remain_time_color);			
				 if((FS_DRIVE_NOT_FOUND == fs_handle || FS_MEDIA_CHANGED == fs_handle))
				 {	
					 m_text_remain_time->setString(VFX_WSTR_RES(STR_GLOBAL_NO_MEMORY_CARD));
					 m_timer_check_remain->stop();
				 }
				 else
				 {
					 //m_text_remain_time->setString(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(fs_handle)));
					 m_timer_error_check->start();
				 }
				 return 0;
			 }
			 else
			 {		 
				 FS_Close(fs_handle);
			 }
		 }

    }

	return updateFreeSpaceTimeText(forceUpdate);
}

VfxU64 VappSoundRecorderRecordPage::updateFreeSpaceTimeText(VfxBool forceUpdate)
{
    VfxS32 record_rate;
    VfxU64 remain_time = 0, new_timer_dur;
	vapp_soundrec_check_size_result check_result;

    /* Get record bitrate */
    mdi_audio_rec_param_struct rec_param;
    mdi_audio_get_record_param(MDI_AUDIO_REC_MODE_IDLE, VADP_SOUND_RECORDER_REC_QUALITY, &rec_param);

    record_rate = rec_param.byte_rate;
    
    /* Get disk size */
    check_result = vapp_soundrec_util_get_record_drv_free_space();

    /* Caculate remain time (in seconds) */
    if(record_rate > 0)
    {
        remain_time = (U64) (check_result.disk_size / record_rate);
    }
	
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_RECPAGE_UPDATE_FREE_SPACE, static_cast<VfxS32>(remain_time));
	
    /* Show text */
    VfxU32 hour, minute;
    
    if(remain_time > 3600)
    {
        hour = (VfxU32) remain_time / 3600;

        VfxWString temp_str;
        temp_str.loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME);
        temp_str += VfxWString().loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME_LARGER);
        temp_str += VfxWString().format(" %d ", hour);
        if(hour == 1)
        {
            temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_HOUR);
        }
        else
        {
            temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_HOURS);
        }

        m_text_remain_time->setColor(m_text_remain_time_color);
        m_text_remain_time->setString(temp_str);
        new_timer_dur = 300000; /* Check remain storage every 5 minutes */
    }
    else if(remain_time > 60)
    {
        minute = (VfxU32) remain_time / 60;

        VfxWString temp_str;
        temp_str.loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME);
        temp_str += VfxWString().loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME_LARGER);
        temp_str += VfxWString().format(" %d ", minute);
        if(minute == 1)
        {
            temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_MIN);
            new_timer_dur = (remain_time - 60) * 1000; /* Check remain again when time < 1 min */
        }
        else
        {
            temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_MINS);
            new_timer_dur = 10000; /* Check remain storage every 10 seconds */
        }

        m_text_remain_time->setColor(m_text_remain_time_color);
        m_text_remain_time->setString(temp_str);
    }
    else if(remain_time == 0)
    {
		if(check_result.ret >= 0)
		{
        	m_text_remain_time->setString(VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL));
		}
		else
		{
			m_text_remain_time->setString(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(check_result.ret)));
			m_timer_error_check->start();
		}
        m_text_remain_time->setColor(VFX_COLOR_RED);
        m_timer_check_remain->stop();

        /* Disable record button when memory full */
        m_image_btn_rec->setIsDisabled(VFX_TRUE);
        return 0;
    }
    else if(remain_time <= 60)
    {
        /* Only update remain time for 60, 55, 50, 45, ... for last minutes */
        if(forceUpdate || 
          (remain_time % 5 == 0) ||
          (m_last_update_remain_time == 0) ||
          (m_last_update_remain_time >= remain_time + 5))
        {
            VfxWString temp_str;
            temp_str.loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME);
            temp_str += VfxWString().loadFromRes(STR_ID_VAPP_SNDREC_AVAILABLE_TIME_IS);
            temp_str += VfxWString().format(" %d ", remain_time);
            if(remain_time == 1)
            {
                temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_SEC);
            }
            else
            {
                temp_str += VFX_WSTR_RES(STR_ID_VAPP_SNDREC_TIME_SECS);
            }

            m_text_remain_time->setColor(VFX_COLOR_RED);            
            m_text_remain_time->setString(temp_str);
            m_last_update_remain_time = remain_time;
        }
        
        if(remain_time % 5 == 0)
        {
            new_timer_dur = 5000;
        }
        else
        {
            new_timer_dur = (remain_time%5) * 1000;
        }
    }
    else
    {
        m_text_remain_time->setColor(m_text_remain_time_color);
        m_text_remain_time->setString(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_ERR_CHECK_REMAIN_TIME));
        m_timer_check_remain->stop();
        return 0;
    }

    m_image_btn_rec->setIsDisabled(VFX_FALSE);

    if(new_timer_dur != m_check_remain_timer_dur)
    {
        m_check_remain_timer_dur = new_timer_dur;
        m_timer_check_remain->stop();

        m_timer_check_remain->setStartDelay((VfxMsec) m_check_remain_timer_dur);
        m_timer_check_remain->setDuration((VfxMsec) m_check_remain_timer_dur);

        // If update by timer expire, restart again
        if(!forceUpdate)
        {
            m_timer_check_remain->start();
        }
    }

    return remain_time;
}

void VappSoundRecorderRecordPage::updateRecButtonState(VfxBool is_pause)
{
	if(is_pause)
	{
		m_image_btn_rec->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_PAUSE,IMG_ID_VAPP_SNDREC_BTN_PAUSE,0,0));
	}
	else
	{
		m_image_btn_rec->setImage(VcpStateImage(IMG_ID_VAPP_SNDREC_BTN_REC,IMG_ID_VAPP_SNDREC_BTN_REC,IMG_ID_VAPP_SNDREC_BTN_REC_D,0));
	}
}


void VappSoundRecorderRecordPage::updateTimeText(VfxTextFrame *text, VfxU64 display_time)
{
    VfxWChar str_buf[12];
    VfxU32 hour, minute, second;

    display_time = display_time / 1000;

    hour = (VfxU32) display_time / 3600;
    minute = (display_time %3600)/60;
    second = (display_time %3600)%60;

    kal_wsprintf(str_buf, "%02d:%02d:%02d", hour, minute, second);

    text->setString(VFX_WSTR_MEM(str_buf));
}

VfxBool VappSoundRecorderRecordPage::checkRecordPath(void)
{
	kal_wsprintf(m_record_path, "%c:\\%w", vapp_soundrec_util_get_storage_drive(), RECORD_DOWNLOAD_FOLDER_NAME);
	
    /* Check and create folder */
	VfxS32 result = srv_fmgr_fs_create_folder(m_record_path);
    if(result < FS_NO_ERROR)
    {
        /* Check if user wants to apply to default storage */
        if((FS_DRIVE_NOT_FOUND == result || FS_MEDIA_CHANGED == result) &&
           (SRV_FMGR_DRV_CARD_TYPE == srv_fmgr_drv_get_type(vapp_soundrec_util_get_storage_drive())))
        {
			#ifndef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
	            mmi_frm_nmgr_balloon(
	                MMI_SCENARIO_ID_DEFAULT,
	                MMI_EVENT_INFO_BALLOON,
	                MMI_NMGR_BALLOON_TYPE_INFO,
	                (WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_SNDREC_INSERT_MEMORY_CARD).getBuf());
			#else
            	showDefaultStoragePopup();
			#endif
        }
        else
        {
            showConfirmPopup(VFX_WSTR_RES(srv_fmgr_fs_error_get_string(result)));
        }
		
        return VFX_FALSE;
    }

	return VFX_TRUE;
}

VfxBool VappSoundRecorderRecordPage::findRecordPath(void)
{
    FMGR_FILTER filter;
    S16 error;
    VfxU16 last_seq = 1;

	/* Check if in background call*/
	//#ifdef __MMI_BACKGROUND_CALL__
		if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
		{
			mmi_frm_nmgr_balloon(
				MMI_SCENARIO_ID_DEFAULT,
				MMI_EVENT_INFO_BALLOON,
				MMI_NMGR_BALLOON_TYPE_FAILURE,
				(WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
			return VFX_FALSE;
		}
	//#endif

	if(!checkRecordPath())
	{
        return VFX_FALSE;
    }

    /* Check if folder empty. if empty, reset the max file sequence */
    vadp_soundrec_util_filter_set(&filter);
    if(srv_fmgr_fs_path_is_not_empty(m_record_path, &filter) == 0)
    {
        WriteValue(NVRAM_APP_SNDREC_FILE_SEQ, &last_seq, DS_SHORT, &error);
    }
    else
    {
        /* Get last max sequence number */
        ReadValue(NVRAM_APP_SNDREC_FILE_SEQ, &last_seq, DS_SHORT, &error);
        if(last_seq > VAPP_SNDREC_MAX_SEQUENCE)
        {
            last_seq = 1;
            WriteValue(NVRAM_APP_SNDREC_FILE_SEQ, &last_seq, DS_SHORT, &error);
        }
    }

    m_last_seq = last_seq;
    if(last_seq == 1)
    {
        m_stop_seq = VAPP_SNDREC_MAX_SEQUENCE;
    }
    else
    {
        m_stop_seq = last_seq - 1;
    }

    if(findRecordPathLoop())
    {
        return VFX_TRUE;
    }
    else
    {
        /* If can't find file name, start a timer and find again later */
        showLoading();
        m_timer_find_name->start();
        return VFX_FALSE;
    }
}

VfxBool VappSoundRecorderRecordPage::findRecordPathLoop(void)
{
    VfxU16 start_index, stop_index, result_index;

    // TODO: Add trace here
    start_index = m_last_seq;

    if(m_last_seq > m_stop_seq)
    {
        if( (start_index + VAPP_SNDREC_FIND_SEQ_RANGE - 1) <= VAPP_SNDREC_MAX_SEQUENCE)
        {
            stop_index = start_index + VAPP_SNDREC_FIND_SEQ_RANGE - 1;
        }
        else
        {
            stop_index = VAPP_SNDREC_MAX_SEQUENCE;
        }
    }
    else
    {
        if( (start_index + VAPP_SNDREC_FIND_SEQ_RANGE - 1) <= m_stop_seq)
        {
            stop_index = start_index + VAPP_SNDREC_FIND_SEQ_RANGE - 1;
        }
        else 
        {
            stop_index = m_stop_seq;
        }
    }

    /* Get file name */
    if(!vapp_soundrec_util_get_record_file_path(start_index, stop_index, &result_index, m_record_path, ((VAPP_SNDREC_FILEPATH_LEN + 1)*sizeof(VfxWChar))))
    {
        /* Something wrong */
        if(result_index == 0xFFFF)
        {
        	stopLoading();
            showConfirmPopup(VFX_WSTR_RES(STR_ID_VAPP_SNDREC_ERR_CREATE_PATH));
        }
        else
        {
            if(result_index == m_stop_seq)
            {
                m_last_seq = m_stop_seq;
            }
            else
            {
                if(result_index >= VAPP_SNDREC_MAX_SEQUENCE)
                {
                    m_last_seq = 1;
                }
                else
                {
                    m_last_seq = result_index + 1;
                }
            }
        }
        return VFX_FALSE;
    }
    else
    {
        if(result_index < VAPP_SNDREC_MAX_SEQUENCE)
        {
            m_last_seq = result_index + 1;
        }
        else
        {
            result_index = VAPP_SNDREC_MAX_SEQUENCE;
        }

        /* Write  m_last_seqto NVRAM after record success */
        return VFX_TRUE;
    }
}

void VappSoundRecorderRecordPage::recordErrorHdlr(mdi_result result)
{
	VfxResId string = STR_GLOBAL_ERROR;
	
    if(result == MDI_AUDIO_DISC_FULL)
    {
    	string = STR_GLOBAL_MEMORY_FULL;
    }
	
    showConfirmPopup(VFX_WSTR_RES(string));
}

void VappSoundRecorderRecordPage::recordCallbackHdlr(mdi_result result)
{
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, TRC_VAPP_SOUNDREC_SLIM_RECPAGE_RECCALLBACK, result);
    
    switch (result)
    {
        /* Interrupted */
        case MDI_AUDIO_TERMINATED:
            recordStop(VFX_FALSE);
            break;
        /* Reach record limit */
        case MDI_AUDIO_SUCCESS:
            onButtonClicked(this, SNDREC_BTN_STOP);
            break;
        /* Disc full */
        case MDI_AUDIO_DISC_FULL:
			recordStop(VFX_TRUE);
			showConfirmPopup(VFX_WSTR_RES(STR_GLOBAL_MEMORY_FULL));
			updateRemainTimeText(VFX_TRUE);
            break;
        default:
            break;
    }
}


void VappSoundRecorderRecordPage::recordStart(void)
{
    mdi_result result;
    VfxS16 error;   

    /* Check if in background call*/
//#ifdef __MMI_BACKGROUND_CALL__
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_DEFAULT,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_FAILURE,
			(WCHAR *)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL).getBuf());
        return;
    }
//#endif

    /* Set start time to 0, if it is a new record */
    if(SNDREC_STATE_IDLE == m_state)
    {
        m_current_time = 0;
        m_accumulate_time = 0;
    }
    else if(SNDREC_STATE_INTERRUPTED == m_state)
    {
        m_current_time = m_accumulate_time;
    }

    /* Terminate background play */
    mdi_audio_terminate_background_play();

    /* update remain time */
    m_last_update_remain_time = 0;
    updateRemainTimeText(VFX_TRUE);
    
    /* Start record */
    result = vadp_soundrec_rec_start(m_record_path, this);

    if(result == MDI_AUDIO_SUCCESS)
    {
        /* Write last seq number after record success */
        WriteValue(NVRAM_APP_SNDREC_FILE_SEQ, &m_last_seq, DS_SHORT, &error);

        /* Change state */
        m_state = SNDREC_STATE_RECORD;
        m_image_btn_stop->setIsDisabled(VFX_FALSE);
        wgui_status_icon_bar_show_icon(STATUS_ICON_VOICE_RECORD); 
    }
	else
	{
		recordErrorHdlr(result);
		return;
	}

    /* Show record file name */
    m_text_record_file_name->setString(VFX_WSTR_MEM(srv_fmgr_path_get_filename_ptr(m_record_path)));
	m_text_record_file_name->setHidden(VFX_FALSE);

    /* Start timer to update duration and remain time */
    m_timer_update->start();
    m_timer_check_remain->start();

    /* Change button to pause icon */
    updateRecButtonState(VFX_TRUE);

    /* Disable m_toolbar */
	m_toolbar->setDisableItem(SNDREC_BTN_TOOL_BAR_REC_LIST, VFX_TRUE);
#ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
	m_toolbar->setDisableItem(SNDREC_BTN_TOOL_BAR_STORAGE, VFX_TRUE);
#endif
}

void VappSoundRecorderRecordPage::recordPause(void)
{
    mdi_result result;
    
    /* Pause record */
    result = vadp_soundrec_rec_pause(this);
    if(result != MDI_AUDIO_SUCCESS)
    {
		recordStop(VFX_TRUE);
    	recordErrorHdlr(result);
		updateRemainTimeText(VFX_TRUE);
		return;
    }

    /* Change state */
    m_state = SNDREC_STATE_PAUSE;
    wgui_status_icon_bar_hide_icon(STATUS_ICON_VOICE_RECORD); 

    /* Stop update duration */
    m_timer_update->stop();
    m_timer_check_remain->stop();

    /* update remaining time */
    //updateRemainTimeText(VFX_TRUE);

    /* Change button to record state */
    updateRecButtonState(VFX_FALSE);
}

void VappSoundRecorderRecordPage::recordResume(void)
{
    mdi_result result;

    result = vadp_soundrec_rec_resume(this);
    if(result != MDI_AUDIO_SUCCESS)
    {
		recordStop(VFX_TRUE);
    	recordErrorHdlr(result);
		updateRemainTimeText(VFX_TRUE);
		return;
    }

    /* Change state */
    m_state = SNDREC_STATE_RECORD;
    wgui_status_icon_bar_show_icon(STATUS_ICON_VOICE_RECORD); 

    /* Start update duration */
    m_timer_update->start();
    m_timer_check_remain->start();

    /* Change button to pause state */
    updateRecButtonState(VFX_TRUE);
}

void VappSoundRecorderRecordPage::recordStop(VfxBool is_finish)
{
    if(m_state == SNDREC_STATE_RECORD || m_state == SNDREC_STATE_PAUSE)
    {
        if(is_finish)
        {
            /* Change state */
            m_state = SNDREC_STATE_IDLE;
            m_image_btn_stop->setIsDisabled(VFX_TRUE);

            /* Clear file name and path if record finish */
            m_text_record_time->setString(VFX_WSTR("00:00:00"));
			m_text_record_file_name->setHidden(VFX_TRUE);
        }
        else
        {
            /* Keep total record time for interrupt case */
            m_accumulate_time = m_current_time;
            m_state = SNDREC_STATE_INTERRUPTED;
        }

        /* Stop record */
        vadp_soundrec_rec_stop();

        wgui_status_icon_bar_hide_icon(STATUS_ICON_VOICE_RECORD); 

        /* Stop update duration */
        m_timer_update->stop();
        m_timer_check_remain->stop();

        /* update remaining time */
        updateRemainTimeText(VFX_TRUE);

        /* Change button to record state */
        updateRecButtonState(VFX_FALSE);
    }
    else if (SNDREC_STATE_INTERRUPTED == m_state)
    {
        if(is_finish)
        {
            /* Change state */
            m_state = SNDREC_STATE_IDLE;
            m_image_btn_stop->setIsDisabled(VFX_TRUE);            

            /* Clear file name and path if record finish */
            m_text_record_time->setString(VFX_WSTR("00:00:00"));
			m_text_record_file_name->setHidden(VFX_TRUE);
        }
    }

    /* Enable m_toolbar */
    if(is_finish)
    {
		m_toolbar->setDisableItem(SNDREC_BTN_TOOL_BAR_REC_LIST, VFX_FALSE);
	#ifdef __MMI_SOUNDREC_SLIM_PHONE_DRIVE__
		m_toolbar->setDisableItem(SNDREC_BTN_TOOL_BAR_STORAGE, VFX_FALSE);
	#endif
    }
}

void VappSoundRecorderRecordPage::stopRecordAndExit(VfxBool user_stop)
{
    /* Force stop and show info ballon to inform user when exit app */
    if(SNDREC_STATE_IDLE != m_state)
    {
        recordStop(VFX_TRUE); 

        /* For app mode, remain in record screen */
		mmi_frm_nmgr_balloon(
			MMI_SCENARIO_ID_DEFAULT,
			MMI_EVENT_INFO_BALLOON,
			MMI_NMGR_BALLOON_TYPE_INFO,
			(WCHAR *)VFX_WSTR_RES(STR_ID_VAPP_SNDREC_RECORD_SAVED).getBuf());  
    }
}

void VappSoundRecorderRecordPage::onCpopupButtonClicked(VfxObject* sender, VfxId btn)
{
    switch(btn)
    {
        case VCP_CONFIRM_BUTTON_SET_OK:
        {
            break;
        }
    }
	VFX_OBJ_CLOSE(m_confirmPopup);
}

void VappSoundRecorderRecordPage::showConfirmPopup(const VfxWString &text)
{
	if(m_confirmPopup == NULL)
	{
		VFX_OBJ_CREATE(m_confirmPopup, VcpConfirmPopup, this);
		m_confirmPopup->setInfoType(VCP_POPUP_TYPE_FAILURE);
		m_confirmPopup->setText(text);
		
		m_confirmPopup->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
		m_confirmPopup->setAutoDestory(VFX_FALSE);
		m_confirmPopup->m_signalButtonClicked.connect(this, &VappSoundRecorderRecordPage::onCpopupButtonClicked);
		m_confirmPopup->show(VFX_TRUE);
	}
}

void VappSoundRecorderRecordPage::showLoading(void)
{
    /* Show loading */
    if(m_indicator == NULL)
    {
        VFX_OBJ_CREATE(m_indicator, VcpActivityIndicator, this);

        /* Sets the position and width of indicator bar. */

        m_indicator->setPos(getSize().width / 2, POPUP_Y);
		m_indicator->setAnchor(0.5, 0.5);
		m_indicator->start();
    }
}

void VappSoundRecorderRecordPage::stopLoading(void)
{
    if(m_indicator != NULL)
    {
        VFX_OBJ_CLOSE(m_indicator);
        m_indicator = NULL;
    }
}

#pragma arm section code, rodata

#endif // __MMI_SOUNDREC_SLIM__
