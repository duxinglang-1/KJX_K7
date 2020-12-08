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
 *  vapp_atv.cpp
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
 *
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

//#include "vapp_bt+_a2dp_gprot.h"

#include "vapp_atv_gprot.h"
#include "vcp_global_popup.h"
#include "vapp_atv.h"
#include "vapp_vol_dialog_gprot.h"
#include "mmi_rp_vapp_atv_def.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "vapp_atv_enum.h"

extern "C"
{
#include "mmi_rp_app_usbsrv_def.h"
#include "nvram_common_defs.h"
#include "A2dpSrvGprot.h"
#include "custom_mmi_folders_config.h"
#include "mdi_datatype.h"
#include "mdi_include.h"
#include "mdi_mtv.h"
#include "mdi_video.h"
#include "GPIOSrvGProt.h"
#include "UcmSrvGProt.h"
#include "med_global.h"
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
VappAtvApp* VappAtvApp::m_self = NULL;

/*****************************************************************************
 * Function
 *****************************************************************************/
extern "C" mmi_ret vapp_atv_package_proc(mmi_event_struct* param)
{
    return MMI_RET_DONT_CARE;
}

extern "C" void vapp_atv_launch(void)
{
    VfxAppLauncher::launch(
        VAPP_ATV,
        VFX_OBJ_CLASS_INFO(VappAtvApp),
        GRP_ID_ROOT);
}

/*****************************************************************************
 * APP Class
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappAtvApp", VappAtvApp, VfxApp);

VappAtvApp::VappAtvApp():
    m_mtvHandle(0),
    m_scrn(0),
    m_storageValid(VFX_FALSE),
    m_proc_close(MMI_FALSE),
    m_numServices(0),
    m_numPrevServices(0),
    m_services(NULL),
    m_timerSignal(NULL),
    m_recThumbBuffer(NULL),
    m_massStorageMode(VFX_FALSE),
    m_kernelState(ATV_KERNEL_CLOSED),
    m_playerState(ATV_PLAYER_STOPPED),
#ifdef __MMI_ATV_RECORD__
    m_recordState(ATV_RECORDER_STOPPED),
#endif
    m_1stEnter(VFX_FALSE),
    m_pageHighPrioSetCount(0),
    m_timerBTConnect(NULL), 
    m_tempBuffer(NULL)
{
}

void VappAtvApp::onInit(void)
{
    VfxApp::onInit();

    // Load Setting
    loadSetting();

    m_self = this;

    //update signal timer
	VFX_OBJ_CREATE(m_timerSignal, VfxTimer, this);
	m_timerSignal->setStartDelay(VAPP_ATV_SIGNAL_UPDATE_TIME);
	m_timerSignal->m_signalTick.connect(this, &VappAtvApp::onUpdateSignal);

    // register event
    registerCBEvent(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, VFX_TRUE);
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_TRUE);
    registerCBEvent(EVT_ID_USB_EXIT_MS_MODE, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE, VFX_TRUE);
    registerCBEvent(EVT_ID_SRV_UCM_INDICATION, VFX_TRUE);

}

void VappAtvApp::onGroupActive()
{
    // terminate & disable background play
    //mdi_audio_terminate_background_play();
    //mdi_audio_suspend_background_play();
}

void VappAtvApp::onGroupInactive()
{
    // enable background play
    //mdi_audio_resume_background_play();
}


void VappAtvApp::onDeinit(void)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_APP_ON_DEINIT, getKernelState());
	if(m_tempBuffer!=NULL)
	{
        applib_asm_free_r(getGroupId(), m_tempBuffer);
        m_tempBuffer = NULL;
	}
    freeStructure();

    // Write Setting
    writeSetting();

    // deregister event
    registerCBEvent(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, VFX_FALSE);
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_FALSE);
    registerCBEvent(EVT_ID_USB_EXIT_MS_MODE, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE, VFX_FALSE);
    registerCBEvent(EVT_ID_SRV_UCM_INDICATION, VFX_FALSE);
    m_self = NULL;

    clearPageHighPriority();
    srv_backlight_turn_off();
	mdi_audio_resume_background_play();
    VfxApp::onDeinit();
}

VfxAppCloseAnswerEnum VappAtvApp::onProcessClose(VfxAppCloseOption options)
{
#ifdef __MMI_ATV_RECORD__
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_APP_ON_PROCESS_CLOSE,
        options, getKernelState(), getPlayerState(), getRecorderState());
#else
	MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_APP_ON_PROCESS_CLOSE,
        options, getKernelState(), getPlayerState());
#endif

    if (getKernelState() == ATV_KERNEL_SCANNING)
    {
        abortScanService();
    }
#ifdef __MMI_ATV_RECORD__
    // stop recorder if in record or record_pause state
    stopRecord();
#endif

    deInitDisplay(VFX_TRUE);

    if (getKernelState() == ATV_KERNEL_CLOSED)
    {
        return VFX_APP_CLOSE_ANSWER_YES;
    }
    else
    {
        closeEngine();
        m_proc_close = MMI_TRUE;

        if (options & VFX_APP_CLOSE_OPTION_LATER_FLAG)
        {
            return VFX_APP_CLOSE_ANSWER_LATER;
        }
        else
        {
            return VFX_APP_CLOSE_ANSWER_YES;
        }
    }
}


void VappAtvApp::onRun(void * args, VfxU32 argSize)
{
    VfxApp::onRun(args, argSize);

	m_tempBuffer = (VfxU8 *)applib_asm_alloc_nc_r(
							VAPP_ATV, MED_ATV_BASE_MEM);
	ASSERT(m_tempBuffer);

    // Create and display main screen
    VFX_OBJ_CREATE(m_scrn, VappAtvScreen, this);
    m_scrn->show();
	mdi_audio_terminate_background_play();
	mdi_audio_suspend_background_play();
}

void VappAtvApp::PowerOnFailHdlr(VfxId id, void *userData)
{
    VappAtvApp *app = (VappAtvApp *)userData;

    // Destroy APP
    app->exit();
}

mmi_ret VappAtvApp::onProc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE:
        {
            vapp_vol_dialog_evt_struct *vol_evt = (vapp_vol_dialog_evt_struct*) evt;

            if(vol_evt->type == VAPP_VOL_DIALOG_IS_MTV)
            {
                return !MMI_RET_OK;
            }
            break;
        }

    #ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            m_massStorageMode = VFX_TRUE;
            m_storageValid = VFX_FALSE;

            updateFuncIcon();
            break;
        }

        case EVT_ID_USB_EXIT_MS_MODE:
        {
            m_massStorageMode = VFX_FALSE;
            updateStorageStatus();
            m_storageValid = VFX_TRUE;  //in this case ,the storage is always true.
            updateFuncIcon();

            break;
        }
    #endif

        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN:
		{
		#ifdef __ATV_RECORD_SUPPORT__
			if( (m_scrn->m_mainPage)&&
                (m_scrn->m_mainPage->m_dispType==ATV_DISP_PATH_CONFIRM))
			{
				if(m_scrn->m_mainPage->m_savePathCfmPopup!=NULL)
				{
				    m_scrn->m_mainPage->m_savePathCfmPopup->exit(VFX_TRUE);
					m_scrn->m_mainPage->m_savePathCfmPopup = NULL;
					m_scrn->m_mainPage->setDispType(ATV_DISP_CTRL_PANEL);
					
					if (isActive() && m_scrn->m_mainPage->isActive() 
						&& m_scrn->m_mainPage->m_vdoFrmPrepared)
					{
						initDisplay();
					}
				}
			}
		#endif
    	}	
        case EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT:
        {          		
		#ifdef __MMI_ATV_STORAGE_SELECT__
            if(m_scrn->m_storagePage)
            {
                 if(evt->evt_id==EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT)
                   m_scrn->m_storagePage->setItemDisable(1,VFX_TRUE);
                else if(evt->evt_id==EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN)
                   m_scrn->m_storagePage->setItemDisable(1,VFX_FALSE);
            }
		#endif       
            /* Storage is phone. Ignore */
            if (m_setting.storage == SRV_FMGR_DRV_PHONE_TYPE)
            {
                return MMI_RET_OK;
            }

            if(evt->evt_id==EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT)
            {
			#ifdef __MMI_ATV_THUMBNAIL__	
                if(m_scrn->m_mainPage)
                {
                    if(m_scrn->m_mainPage->m_dispType==ATV_DISP_THUMBNAIL)
	                {
	                    m_scrn->m_mainPage->closeThumb();
	                }
					else if(m_scrn->m_mainPage->m_dispType==ATV_DISP_QUICK_PREVIEW)
					{
						m_scrn->m_mainPage->stopHideTimer();
						VFX_OBJ_CLOSE(m_scrn->m_mainPage->m_qucikPreviewFrame);
						m_scrn->m_mainPage->setDispType(ATV_DISP_CTRL_PANEL);
						
						if (isActive() && m_scrn->m_mainPage->isActive() 
							&& m_scrn->m_mainPage->m_vdoFrmPrepared)
						{
							initDisplay();
						}
					}
                }
			#endif
				
			#ifdef __MMI_ATV_RECORD__
                if(m_scrn->m_mainPage)
                {
                    if(m_scrn->m_mainPage->m_dispType==ATV_DISP_RECORD_CONFIRM)
	                {
						if(m_scrn->m_mainPage->m_saveCfmPopup!=NULL)
						{
							m_scrn->m_mainPage->m_saveCfmPopup->exit(VFX_TRUE);
							m_scrn->m_mainPage->m_saveCfmPopup = NULL;
						}
						mdi_mtv_discard_unsaved_recording(m_mtvHandle);
						setRecorderState(ATV_RECORDER_STOPPED);
						
						//release component
						m_scrn->m_mainPage->closeRecComp();
						
						m_scrn->m_mainPage->showMdiFailConfirm(MDI_RES_MTV_ERR_SAVE_FAILED);
                	}
            	}
			#endif
            }

            updateStorageStatus();
            m_storageValid = VFX_TRUE;  //in this case ,the storage is always true.
            updateFuncIcon();

            break;
        }

        case EVT_ID_SRV_FMGR_NOTIFICATION_SET_DEF_STORAGE:
        {
            break;
        }

    #ifdef __MMI_BACKGROUND_CALL__
        case EVT_ID_SRV_UCM_INDICATION:
        {
            srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct *)evt;
            if (ind->ind_type == SRV_UCM_RELEASE_IND && !srv_ucm_is_any_call())
            {
                if (getPlayerState() == ATV_PLAYER_PLAY 
			#ifdef __MMI_ATV_RECORD__
					&& getRecorderState() == ATV_RECORDER_STOPPED
			#endif
					)
                {
                    //restart player
                    deInitDisplay(VFX_FALSE);
                    initDisplay();
                }
            }

            break;
        }
    #endif //__MMI_BACKGROUND_CALL__

        default:
            break;

    }


    return MMI_RET_OK;
}

void VappAtvApp::updateFuncIcon(void)
{
    if (m_scrn->m_mainPage)
    {
        m_scrn->m_mainPage->m_toolBar->setIsFuncEnabled();
    }
	
#if defined(__MMI_ATV_RECORD__) && defined(__MMI_ATV_STORAGE_SELECT__)
    if (m_scrn->m_settingPage)
    {
        m_scrn->m_settingPage->setIsCellEnabled();
    }
#endif

#if defined(__MMI_ATV_STORAGE_SELECT__)
	if(m_scrn->m_storagePage)
	{
		m_scrn->m_storagePage->setItemDisable(1,VFX_TRUE);
	}
#endif
}

void VappAtvApp::updateStorageStatus(void)
{
    VfxBool ret;
    //VfxWChar storagePath[SRV_FMGR_PATH_BUFFER_SIZE>>1];

    ret = getStoragePath(m_storagePath);
    if (ret)
    {
        if((getKernelState() != ATV_KERNEL_CLOSED) || 
			(getKernelState() != ATV_KERNEL_CLOSING))
        {
        #ifdef __MMI_ATV_RECORD__
            mdi_mtv_set_storage(m_mtvHandle, (PU8)m_storagePath);
        #endif
        }
    }
    else
    {
        //TODO
    }
}


void VappAtvApp::writeSetting(void)
{
    S16 error;

    // Read NVRAM
    WriteRecord(
        NVRAM_EF_ATV_SETTING_LID, 1, &m_setting,
        NVRAM_EF_ATV_SETTING_SIZE, &error);
}


void VappAtvApp::loadSetting(void)
{
    S16 error;

    // Read NVRAM
    ReadRecord(
        NVRAM_EF_ATV_SETTING_LID, 1, &m_setting,
        sizeof(nvram_atv_setting_struct), &error);

    if (m_setting.selected_channel == 0xFF)
    {
        restoreSetting();
    }

}

void VappAtvApp::restoreSetting(void)
{
    m_setting.brightness = MDI_MTV_BRIGHTNESS_0;
    m_setting.contrast = MDI_MTV_CONTRAST_0;
    m_setting.saturation = MDI_MTV_SATURATION_0;
    m_setting.selected_channel = 0;
    m_setting.selected_country = 0;
#ifdef __MMI_ATV_STORAGE_SELECT__ 
    m_setting.storage = (kal_uint8)SRV_FMGR_DRV_PHONE_TYPE;
#else
    m_setting.storage = (kal_uint8)SRV_FMGR_DRV_CARD_TYPE; // if undef this macro, card default.
#endif
    m_setting.is_inited = MMI_FALSE;
    m_setting.img_file_no = 0;
    m_setting.rec_file_no = 0;
    m_setting.record_size = MDI_MTV_RECORDER_SIZE_QVGA;
    // Write NVRAM
    writeSetting();
}


void VappAtvApp::setKernelState(VAPP_ATV_KERNEL_STATE_ENUM state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_SET_KERNEL_STATE, m_kernelState, state);
    m_kernelState = state;
}

void VappAtvApp::setPlayerState(VAPP_ATV_PLAYER_STATE_ENUM state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_SET_PLAYER_STATE, m_playerState, state);
    m_playerState = state;
}

#ifdef __MMI_ATV_RECORD__
void VappAtvApp::setRecorderState(VAPP_ATV_RECORDER_STATE_ENUM state)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_SET_RECORDER_STATE, m_recordState, state);
    m_recordState = state;
}
#endif

VAPP_ATV_KERNEL_STATE_ENUM VappAtvApp::getKernelState(void)
{
    return m_kernelState;
}

VAPP_ATV_PLAYER_STATE_ENUM VappAtvApp::getPlayerState(void)
{
    return m_playerState;
}

#ifdef __MMI_ATV_RECORD__
VAPP_ATV_RECORDER_STATE_ENUM VappAtvApp::getRecorderState(void)
{
    return m_recordState;
}
#endif

void VappAtvApp::allocStructure(void)
{
    if (!m_services)
    {
        ASSERT(sizeof(vapp_srv_info_struct) < VAPP_ATV_SERVICE_STRUCT_SIZE);

        m_services = (vapp_srv_info_struct *)applib_asm_alloc_r(
                        getGroupId(),
                        sizeof(vapp_srv_info_struct) * VAPP_ATV_MAX_SERVICES);

        //VFX_ALLOC_MEM(m_services,
        //    sizeof(vapp_srv_info_struct) * VAPP_ATV_MAX_SERVICES, this);

        ASSERT(m_services);
    }

    if (!m_recThumbBuffer)
    {
        m_recThumbBuffer = (VfxU8 *)applib_asm_alloc_nc_r(
                        getGroupId(), VAPP_ATV_THUMBNAIL_SIZE);

        ASSERT(m_recThumbBuffer);
    }

}


void VappAtvApp::freeStructure(void)
{
    if (m_services)
    {
        applib_asm_free_r(getGroupId(), m_services);
        m_services = NULL;

        //VFX_FREE_MEM(m_services);
    }

    if (m_recThumbBuffer)
    {
        applib_asm_free_r(getGroupId(), m_recThumbBuffer);
        m_recThumbBuffer = NULL;
    }

}

// Control function

void VappAtvApp::completeRecoverHdlr(S32 value, void *user_data)
{
    VappAtvApp *app = (VappAtvApp*)user_data;
    ASSERT(app != NULL);
}

void VappAtvApp::serviceFoundHdlr(mdi_mtv_service_info_struct *service_info, void *user_data)
{
    VappAtvApp* app = (VappAtvApp*)VfxObject::handleToObject((VfxObjHandle)user_data);
    ASSERT(app != NULL);

	if(app->m_numServices >= VAPP_ATV_MAX_SERVICES)
	{
		return;
	}
	
    //ASSERT(app->m_numServices < VAPP_ATV_MAX_SERVICES);
    vapp_srv_info_struct *info_p = &app->m_services[app->m_numServices];
    info_p->service_id = service_info->service_id;
    info_p->service_number = service_info->service_number;
    info_p->audio_mode = service_info->audio_mode;
    info_p->supported_audio_mode = service_info->supported_audio_mode;

    mmi_ucs2ncpy(
        (CHAR *)info_p->service_name,
        service_info->service_name,
        VAPP_ATV_NAME_STR_LENGTH);

    app->m_numServices ++;
}

void VappAtvApp::searchProgressHdlr(S32 value, void *user_data)
{
    VappAtvApp* app = (VappAtvApp*)VfxObject::handleToObject((VfxObjHandle)user_data);
    ASSERT(app != NULL);

    VappAtvScanProg *scanProg = app->getScanProg();
    ASSERT(scanProg != NULL);

    // TODO: not work
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    scanProg->setScanProgress((VfxFloat)value/100);

    if (value < 100)
    {
        return;
    }

    app->setKernelState(ATV_KERNEL_OPENED);

    // Scan again
    if (app->m_numServices == 0 && !app->m_liveScan)
    {
        app->m_setting.is_inited = MMI_FALSE;
        app->writeSetting();

        //rescan
        scanProg->startScan();
        return;
    }

    // Scan succeed
    scanProg->scanFinishHandler();
}

void VappAtvApp::systemEvtHdlr(U32 event_id, S32 param, void *user_data)
{
    VappAtvApp* app = (VappAtvApp*)VfxObject::handleToObject((VfxObjHandle)user_data);
    ASSERT(app != NULL);

    if (event_id == MDI_MTV_SYSTEM_CLOSED)
    {
        ASSERT(app->getKernelState() == ATV_KERNEL_CLOSING);
        app->setKernelState(ATV_KERNEL_CLOSED);

        if (app->m_proc_close)
        {
            app->m_proc_close = VFX_FALSE;
            app->continueClose(VFX_APP_CLOSE_ANSWER_YES);
        }
        else
        {
            app->exit();
        }
    }
}

void VappAtvApp::onUpdateSignal(VfxTimer *obj)
{
    mdi_mtv_service_status_struct status;
    VfxS32 level = 0;

    if (getKernelState() == ATV_KERNEL_READY)
    {
        mdi_mtv_service_get_status(m_mtvHandle, &status);

        if (status.signal_strength <= 25)
        {
            level = 0;
        }
        else if (status.signal_strength <= 44)
        {
            level = 1;
        }
        else if (status.signal_strength <= 63)
        {
            level = 2;
        }
        else if (status.signal_strength <= 82)
        {
            level = 3;
        }
        else
        {
            level = 4;
        }
    }

    m_scrn->m_mainPage->setSignalLevel(level);
    m_timerSignal->start();
}


void VappAtvApp::serviceReadyHdlr(VappAtvApp* app, mdi_mtv_service_info_struct *srvInfo)
{
    vapp_srv_info_struct *infoPtr = getActiveSrv();

    app->setKernelState(ATV_KERNEL_READY);

    // Store audio mode
    infoPtr->audio_mode = srvInfo->audio_mode;
    infoPtr->supported_audio_mode = srvInfo->supported_audio_mode;

    // Update signal level
    app->onUpdateSignal(app->m_timerSignal);

    if (app->getPlayerState() == ATV_PLAYER_STOPPED)
    {
        initDisplay();
    }
    else
    {
        m_scrn->m_mainPage->m_toolBar->setIsFuncEnabled();
    }
}


void VappAtvApp::serviceEvtHdlr(U32 event_id, S32 param, void *user_data)
{
    VappAtvApp* app = (VappAtvApp*)VfxObject::handleToObject((VfxObjHandle)user_data);
    ASSERT(app != NULL);

    mdi_mtv_service_info_struct *srvInfo = (mdi_mtv_service_info_struct*)param;
    vapp_srv_info_struct *infoPtr = app->getActiveSrv();

    if (event_id == MDI_MTV_SERVICE_READY)
    {
        app->serviceReadyHdlr(app, srvInfo);
    }
    else if (event_id == MDI_MTV_SERVICE_UPDATED)
    {
        infoPtr->audio_mode = srvInfo->audio_mode;
        infoPtr->supported_audio_mode = srvInfo->supported_audio_mode;
    }
}

void VappAtvApp::playerEvtHdlr(U32 event_id, S32 param, void *user_data)
{
    VappAtvApp* app = (VappAtvApp*)VfxObject::handleToObject((VfxObjHandle)user_data);
    ASSERT(app != NULL);
}

#ifdef __MMI_ATV_RECORD__
void VappAtvApp::recorderEvtHdlr(U32 event_id, S32 param, void *user_data)
{
    VappAtvApp* app = (VappAtvApp*)VfxObject::handleToObject((VfxObjHandle)user_data);
    ASSERT(app != NULL);

    if (event_id == MDI_MTV_RECORDER_ERROR)
    {
        app->setRecorderState(ATV_RECORDER_SAVE_CONFIRM);

        app->deInitDisplay(VFX_FALSE);

        //If memory card is removed when record, show fail directly.
        if( ((app->m_setting.storage == SRV_FMGR_DRV_CARD_TYPE) && 
        (!srv_fmgr_drv_is_accessible(
         srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE)))) || 
         (param == MDI_RES_MTV_ERR_DISC_IO_ERROR) )
        {
            mdi_mtv_discard_unsaved_recording(app->m_mtvHandle);
            app->setRecorderState(ATV_RECORDER_STOPPED);

            //release component
            app->m_scrn->m_mainPage->closeRecComp();

            app->m_scrn->m_mainPage->showMdiFailConfirm(MDI_RES_MTV_ERR_SAVE_FAILED);
        }
        else
        {
            app->m_scrn->m_mainPage->displaySaveConfirm((MDI_RESULT)param);
        }
    }
    else if (event_id == MDI_MTV_RECORDER_SAVING_SUCCEEDED)
    {
        app->setRecorderState(ATV_RECORDER_STOPPED);

        app->m_scrn->m_mainPage->finalizeRec(VFX_TRUE);

    }
    else if (event_id == MDI_MTV_RECORDER_SAVING_FAILED)
    {
        app->setRecorderState(ATV_RECORDER_STOPPED);

        //release component
        app->m_scrn->m_mainPage->closeRecComp();
        app->m_scrn->m_mainPage->showMdiFailConfirm((MDI_RESULT)param);

    }
    else if (event_id == MDI_MTV_RECORDER_RECORDING_DISCARDED)
    {
        app->setRecorderState(ATV_RECORDER_STOPPED);

        app->m_scrn->m_mainPage->finalizeRec(VFX_FALSE);
    }
}
#endif

VappAtvScanProg *VappAtvApp::getScanProg()
{
    VappAtvScanLocPage *scanPage = m_scrn->m_scanLocPage;
    if (scanPage)
    {
        return scanPage->m_scanProg;
    }

    VappAtvMainPage *mainPage = m_scrn->m_mainPage;
    if (mainPage)
    {
        return mainPage->m_scanProg;
    }
    ASSERT(0);
    return NULL;
}


MDI_RESULT VappAtvApp::openEngine(void)
{
    mdi_mtv_setting_struct mtv_setting = {0};
    mdi_mtv_service_config_struct mtv_service_config;
    //VfxWChar storagePath[SRV_FMGR_PATH_BUFFER_SIZE>>1];
    MDI_RESULT ret;

    ASSERT(getKernelState()== ATV_KERNEL_CLOSED);

    mtv_setting.brightness = m_setting.brightness;
    mtv_setting.contrast = m_setting.contrast;
    mtv_setting.saturation = m_setting.saturation;
    mtv_setting.record_size = m_setting.record_size;
    getStoragePath(m_storagePath);
    mtv_setting.record_dir = (PU8)m_storagePath;

    mtv_service_config.user_data = this;
    mtv_service_config.complete_recovering_hdlr = completeRecoverHdlr;
    mtv_service_config.search_progress_hdlr = searchProgressHdlr;
    mtv_service_config.service_found_hdlr = serviceFoundHdlr;
    mtv_service_config.system_event_hdlr = systemEvtHdlr;
    mtv_service_config.service_event_hdlr = serviceEvtHdlr;
    mtv_service_config.player_event_hdlr = playerEvtHdlr;
#ifdef __MMI_ATV_RECORD__
    mtv_service_config.recorder_event_hdlr = recorderEvtHdlr;
#else
    mtv_service_config.recorder_event_hdlr = NULL;
#endif
    mtv_service_config.user_data = getObjHandle();

    ret = mdi_mtv_open(getGroupId(), &m_mtvHandle, &mtv_setting, &mtv_service_config);

    if (ret == MDI_RES_MTV_SUCCEED)
    {
        setKernelState(ATV_KERNEL_OPENED);
    }
    return ret;
}

void VappAtvApp::closeEngine(void)
{
    ASSERT(getKernelState() == ATV_KERNEL_OPENED);

#ifdef __MMI_ATV_RECORD__
    if (getRecorderState() == ATV_RECORDER_SAVING)
    {
        mdi_mtv_recorder_abort_saving(m_mtvHandle);
        setRecorderState(ATV_RECORDER_SAVING);
    }
#endif

    mdi_mtv_close(m_mtvHandle);

    setKernelState(ATV_KERNEL_CLOSING);
}

MDI_RESULT VappAtvApp::scanService(void)
{

    MDI_RESULT ret;
    U32 band;

    ASSERT(getKernelState()== ATV_KERNEL_OPENED);
	mdi_audio_terminate_background_play();
	mdi_audio_suspend_background_play();
    band = getBand();

    // Initialize parameter
    m_numServices = 0;
    kal_mem_set(m_services, 0, sizeof(m_services) * VAPP_ATV_MAX_SERVICES);

    m_liveScan = MMI_FALSE;
    if (m_setting.is_inited && !m_scrn->m_mainPage)
    {
        ret = mdi_mtv_scan_services(
                m_mtvHandle, MDI_MTV_SOURCE_LOCAL_DATABASE, band, 0);

        if (ret != MDI_RES_MTV_SUCCEED)
        {
            m_setting.is_inited = MMI_FALSE;
            writeSetting();

            ret = mdi_mtv_scan_services(
                    m_mtvHandle, MDI_MTV_SOURCE_LIVE_SIGNAL, band, 0);
            if (ret == MDI_RES_MTV_SUCCEED)
            {
                m_liveScan = MMI_TRUE;
            }
        }
    }
    else
    {
        m_setting.is_inited = MMI_FALSE;
        writeSetting();
        
        ret = mdi_mtv_scan_services(
                m_mtvHandle, MDI_MTV_SOURCE_LIVE_SIGNAL, band, 0);
        if (ret == MDI_RES_MTV_SUCCEED)
        {
            m_liveScan = MMI_TRUE;
        }
    }

    if (ret == MDI_RES_MTV_SUCCEED)
    {
        setKernelState(ATV_KERNEL_SCANNING);
    }
    return ret;
}

void VappAtvApp::abortScanService(void)
{
    ASSERT(getKernelState() == ATV_KERNEL_SCANNING);

    mdi_mtv_abort_scan_services(m_mtvHandle);

    setKernelState(ATV_KERNEL_OPENED);
}


MDI_RESULT VappAtvApp::initDisplay()
{
    MDI_RESULT ret = MDI_RES_MTV_SUCCEED;

    if (getKernelState() == ATV_KERNEL_OPENED)
    {
        ret = startService();
    }
    else if (getKernelState() == ATV_KERNEL_READY)
    {
        if (getPlayerState() == ATV_PLAYER_STOPPED)
        {
        #if defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
            if (srv_a2dp_is_output_to_bt())
            {
				if(!srv_ucm_is_any_call())
				{
                	connectBT();

					if(m_timerBTConnect==NULL)
					{
						VFX_OBJ_CREATE(m_timerBTConnect, VfxTimer, this);
					}
					else
					{
						m_timerBTConnect->stop();
					}
					m_timerBTConnect->m_signalTick.connect(
	            		this, &VappAtvApp::BTConnectTimeout);
				    m_timerBTConnect->setStartDelay(1500); 
				    m_timerBTConnect->start();
				}
				else
				{
					ret = startPlayer();
				}
            }
            else
        #endif // defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
            {
                ret = startPlayer();
            }
        }
    }

    return ret;
}


void VappAtvApp::deInitDisplay(VfxBool incReady)
{
    //stop player
    if (getPlayerState() != ATV_PLAYER_STOPPED)
    {
        stopPlayer();
    }

    //abort init service
    if (getKernelState() == ATV_KERNEL_INIT ||
        (getKernelState() == ATV_KERNEL_READY && incReady))
    {
        stopService();
    }
	
	if(m_timerBTConnect!=NULL)
	{
		VFX_OBJ_CLOSE(m_timerBTConnect);
	}

	if(m_scrn->m_mainPage)
	{
		m_scrn->m_mainPage->closeLoadingPopup();
	}

}

MDI_RESULT VappAtvApp::startService()
{
    MDI_RESULT ret;
    mdi_mtv_player_setting_struct videoSetting = {0};

    ASSERT(getKernelState() == ATV_KERNEL_OPENED);
    ASSERT(getPlayerState() == ATV_PLAYER_STOPPED);

    serviceUnavailable = MMI_FALSE;

#if defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
    if (srv_a2dp_is_output_to_bt())
    {
        ret = mdi_mtv_start_service(
                m_mtvHandle,
                m_services[m_setting.selected_channel].service_id,
                MDI_MTV_SERVICE_TYPE_ANALOG_TV,
                MMI_FALSE, //Do not auto play
                NULL);
        if (ret == MDI_RES_MTV_SUCCEED)
        {
            setKernelState(ATV_KERNEL_INIT);
        }
    }
    else
#endif //defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
    {
        getVideoSetting(&videoSetting);

        ret = mdi_mtv_start_service(
                m_mtvHandle,
                m_services[m_setting.selected_channel].service_id,
                MDI_MTV_SERVICE_TYPE_ANALOG_TV,
                MMI_TRUE, //Auto play
                &videoSetting);

        if (ret == MDI_RES_MTV_SUCCEED)
        {
            setPlayerState(ATV_PLAYER_PLAY);
            m_storageValid = VFX_TRUE;  
            m_scrn->m_mainPage->m_toolBar->setIsFuncEnabled();

            setKernelState(ATV_KERNEL_INIT);
        }
        else
        {
            srv_pattern_play_req(srv_led_pattern_get_bg_pattern(), 1);
            srv_backlight_turn_off();
        }
    }
    return ret;
}



void VappAtvApp::getVideoSetting(mdi_mtv_player_setting_struct *video_setting)
{
    VfxVideoFrame *videoFrame;

	if(srv_ucm_is_any_call())
    {
        video_setting->play_audio = KAL_FALSE;
    }
    else
    {
        video_setting->play_audio = KAL_TRUE;
    }

    video_setting->rotate = MDI_MTV_LCD_ROTATE_0;
    video_setting->is_visual_update = MMI_TRUE;

    videoFrame = m_scrn->m_mainPage->m_videoFrame;
    ASSERT(videoFrame);

    video_setting->play_layer_handle = videoFrame->getLayerHandle();
    video_setting->blt_layer_flag = videoFrame->getDisplayLayerFlag();
    video_setting->play_layer_flag = videoFrame->getHwLayerFlag();

    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    srv_pattern_send_req_to_hw(srv_led_pattern_get_bg_pattern(), 0);

    mdi_audio_set_volume(MDI_VOLUME_ATV, srv_prof_get_media_vol());
}


void VappAtvApp::stopService()
{

    ASSERT(getKernelState() == ATV_KERNEL_INIT ||
           getKernelState() == ATV_KERNEL_READY);

    mdi_mtv_stop_service(
        m_mtvHandle, m_services[m_setting.selected_channel].service_id);
    setKernelState(ATV_KERNEL_OPENED);

    m_timerSignal->stop();
    m_scrn->m_mainPage->setSignalLevel(0);
}

#if defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
void VappAtvApp::BTConnectTimeout(VfxTimer *timer)
{	
	if(m_timerBTConnect!=NULL)
	{
    	VFX_OBJ_CLOSE(m_timerBTConnect);
	}

	if(m_scrn->m_mainPage)
	{
		m_scrn->m_mainPage->createLoadingPopup();
	}
}

void VappAtvApp::onBTOpenCallback(VfxS32 result)
{
    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_ON_BT_OPEN_CALLBACK, result);

    VappAtvApp* app = (VappAtvApp*)m_self;
    ASSERT(app);

    //TODO
	//StopTimer(MTV_PLAYER_BT_ANIMATION_TIMER);
    //mmi_mtv_player_stop_bt_connecting_anim();

	if(app->m_timerBTConnect!=NULL)
	{
		VFX_OBJ_CLOSE(app->m_timerBTConnect);
	}
	
	if(app->m_scrn->m_mainPage)
	{
		app->m_scrn->m_mainPage->closeLoadingPopup();
	}

	switch (result)
	{
		case SRV_A2DP_CALLBACK_EVENT_OPEN_OK:
		{
			if (app->getPlayerState() == ATV_PLAYER_BT_CONNECT)
            {
                srv_a2dp_open_codec(MMI_FALSE);
                app->startPlayer();
            }
            else if (app->getPlayerState() == ATV_PLAYER_PLAY)
            {
                srv_a2dp_open_codec(MMI_TRUE);
            }
			break;
		}
        case SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND:
        case SRV_A2DP_CALLBACK_EVENT_STREAM_SUSPEND_IND:
        case SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND:
            srv_a2dp_close_codec();
            // fall through
		case SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED:
        case SRV_A2DP_CALLBACK_EVENT_OPEN_STOPPED:
		case SRV_A2DP_CALLBACK_EVENT_OPEN_SCO:
		{
            if (app->getPlayerState() == ATV_PLAYER_BT_CONNECT)
            {
                app->startPlayer();
            }
            else if (app->getPlayerState() == ATV_PLAYER_PLAY)
            {
                srv_a2dp_close_codec();
            }
			break;
		}

		case SRV_A2DP_CALLBACK_EVENT_OPEN_CANCELED:
		case SRV_A2DP_CALLBACK_EVENT_INQUIRY_START_IND:
		case SRV_A2DP_CALLBACK_EVENT_INQUIRY_STOP_IND:
		case SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND:
			break;
	}
}

MDI_RESULT VappAtvApp::connectBT()
{
    vapp_srv_info_struct *infoPtr = getActiveSrv();
    U32 sampleRate, channelNum;
    VfxBool is_stereo;

    ASSERT(getKernelState() == ATV_KERNEL_READY);
    ASSERT(getPlayerState() == ATV_PLAYER_STOPPED);

    mdi_mtv_get_audio_sample_rate(
        m_mtvHandle, infoPtr->service_id, &sampleRate);
    mdi_mtv_get_audio_channel_number(
        m_mtvHandle, infoPtr->service_id, &channelNum);

    is_stereo = (channelNum == 2) ? VFX_TRUE : VFX_FALSE;

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
#endif

    srv_a2dp_open(
		srv_a2dp_get_bt_headset(),
		sampleRate,
		is_stereo,
		&VappAtvApp::onBTOpenCallback,
		MMI_TRUE);

    setPlayerState(ATV_PLAYER_BT_CONNECT);

    return MDI_RES_MTV_SUCCEED;
}
#endif  // defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)

MDI_RESULT VappAtvApp::startPlayer()
{

    MDI_RESULT ret;
    mdi_mtv_player_setting_struct videoSetting = {0};

    ASSERT(getKernelState() == ATV_KERNEL_READY);
    ASSERT(getPlayerState() == ATV_PLAYER_STOPPED ||
           getPlayerState() == ATV_PLAYER_BT_CONNECT);

	m_scrn->m_mainPage->closeLoadingPopup();

    getVideoSetting(&videoSetting);

    ret = mdi_mtv_player_play(m_mtvHandle, &videoSetting);

    if (ret == MDI_RES_MTV_SUCCEED)
    {
        setPlayerState(ATV_PLAYER_PLAY);
        m_storageValid = VFX_TRUE;  
        m_scrn->m_mainPage->m_toolBar->setIsFuncEnabled();
    }
    else
    {
    #if defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
        srv_a2dp_close_codec();
    #endif // defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)

        srv_pattern_play_req(srv_led_pattern_get_bg_pattern(), 1);
        srv_backlight_turn_off();
    }

    return ret;
}


void VappAtvApp::stopPlayer()
{
    if (getPlayerState() == ATV_PLAYER_PLAY)
    {
        mdi_mtv_player_stop(m_mtvHandle);

    #if defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
        srv_a2dp_close_codec();
        srv_a2dp_close(MMI_FALSE);
    #endif // defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)

        srv_pattern_play_req(srv_led_pattern_get_bg_pattern(), 1);
        srv_backlight_turn_off();
    }
#if defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
    else if (getPlayerState() == ATV_PLAYER_BT_CONNECT)
    {
        srv_a2dp_close(MMI_FALSE);
    }
#endif //  defined(__MMI_A2DP_SUPPORT__) && defined(__ATV_I2S_SUPPORT__)
    else
    {
        ASSERT(0);
    }

    setPlayerState(ATV_PLAYER_STOPPED);
    m_scrn->m_mainPage->m_toolBar->setIsFuncEnabled();
}

#ifdef __MMI_ATV_RECORD__
MDI_RESULT VappAtvApp::startRecord()
{
    MDI_RESULT ret;

    ASSERT(getKernelState() == ATV_KERNEL_READY);
    ASSERT(getRecorderState() == ATV_RECORDER_STOPPED);

    ret = mdi_mtv_recorder_start(m_mtvHandle, NULL);

    if (ret == MDI_RES_MTV_SUCCEED)
    {
        setRecorderState(ATV_RECORDER_RECORD);
    }

    return ret;
}

MDI_RESULT VappAtvApp::resumeRecord()
{
    MDI_RESULT ret;

    ASSERT(getKernelState() == ATV_KERNEL_READY);
    ASSERT(getRecorderState() == ATV_RECORDER_PAUSED);

    ret = mdi_mtv_recorder_resume(m_mtvHandle);

    if (ret == MDI_RES_MTV_SUCCEED)
    {
        setRecorderState(ATV_RECORDER_RECORD);
    }

    return ret;
}


MDI_RESULT VappAtvApp::pauseRecord()
{
    MDI_RESULT ret;
    ASSERT(getRecorderState() == ATV_RECORDER_RECORD);

    ret = mdi_mtv_recorder_pause(m_mtvHandle);
    if(ret==MDI_RES_MTV_SUCCEED)
    {
    setRecorderState(ATV_RECORDER_PAUSED);
}
    else
    {
        mdi_mtv_recorder_discard_recording(m_mtvHandle);
        deInitDisplay(VFX_FALSE);
        setRecorderState(ATV_RECORDER_STOPPED);
        m_scrn->m_mainPage->closeRecComp();
        m_scrn->m_mainPage->showMdiFailConfirm(ret);

    }
    return ret;
}

void VappAtvApp::stopRecord()
{
    VAPP_ATV_RECORDER_STATE_ENUM state = getRecorderState();
    if  (state == ATV_RECORDER_RECORD ||
state == ATV_RECORDER_PAUSED)
    {
        mdi_mtv_recorder_stop(m_mtvHandle);
        setRecorderState(ATV_RECORDER_SAVE_CONFIRM);
    }
}

MDI_RESULT VappAtvApp::saveRecord(VfxWChar *storagePath)
{
    MDI_RESULT ret;

    ASSERT(getRecorderState() == ATV_RECORDER_SAVE_CONFIRM);

    // check storage path
    ret = getStoragePath(storagePath);
    if (!ret)
    {
        return MDI_RES_MTV_ERR_SAVE_FAILED;
    }
    getNextFileName(storagePath, FILE_TYPE_REC);

    ret = mdi_mtv_recorder_save(m_mtvHandle, storagePath);

    if (ret == MDI_RES_MTV_SUCCEED)
    {
        setRecorderState(ATV_RECORDER_SAVING);
    }

    return ret;
}


void VappAtvApp::discardRecord()
{
    ASSERT(getRecorderState() == ATV_RECORDER_SAVE_CONFIRM);

    mdi_mtv_recorder_discard_recording(m_mtvHandle);
    setRecorderState(ATV_RECORDER_DELETING);
}
#endif

void VappAtvApp::getServiceList(void)
{
    MDI_RESULT ret;
    mdi_mtv_service_info_struct service_info;
    S32 i;

    for (i = 0; i < VAPP_ATV_MAX_SERVICES; i ++)
    {
        ret = mdi_mtv_get_service_by_index(m_mtvHandle, i, &service_info);
        if (ret != MDI_RES_MTV_SUCCEED)
        {
            break;
        }
        serviceFoundHdlr(&service_info, getObjHandle());
    }
}


U32 VappAtvApp::getBand(void)
{
    // The order MUST be the same as string ID
    U32 band[] = {
        MDI_MTV_ATV_AFGHANISTAN,
        MDI_MTV_ATV_ARGENTINA,
        MDI_MTV_ATV_AUSTRALIA,
        MDI_MTV_ATV_BRAZIL,
        MDI_MTV_ATV_CAMBODIA,
        MDI_MTV_ATV_CANADA, //5
        MDI_MTV_ATV_CHILE,
        MDI_MTV_ATV_CHINA,
        MDI_MTV_ATV_CHINA_HONGKONG,
        MDI_MTV_ATV_CHINA_SHENZHEN,
        MDI_MTV_ATV_CONGO,  //10
        MDI_MTV_ATV_EUROPE_EASTERN,
        MDI_MTV_ATV_FRANCE,
        MDI_MTV_ATV_GABON,
        MDI_MTV_ATV_INDIA,
        MDI_MTV_ATV_INDONESIA, //15
        MDI_MTV_ATV_IRAN,
        MDI_MTV_ATV_IRELAND,
        MDI_MTV_ATV_ITALY,
        MDI_MTV_ATV_IVORYCOAST,
        MDI_MTV_ATV_JAPAN,   //20
        MDI_MTV_ATV_KOREA,
        MDI_MTV_ATV_LAOS,
        MDI_MTV_ATV_MADAGASCAR,
        MDI_MTV_ATV_MALAYSIA,
        MDI_MTV_ATV_MEXICO, //25
        MDI_MTV_ATV_BURMA, /* String: MYANMAR */
        MDI_MTV_ATV_MOROCCO,
        MDI_MTV_ATV_NEWZEALAND,
        MDI_MTV_ATV_PAKISTAN,
        MDI_MTV_ATV_PARAGUAY, //30
        MDI_MTV_ATV_PHILIPPINES,
        MDI_MTV_ATV_PORTUGAL,
        MDI_MTV_ATV_REUNION,
        MDI_MTV_ATV_RUSSIA,
        MDI_MTV_ATV_RWANDA,  //35
        MDI_MTV_ATV_SENEGAL,
        MDI_MTV_ATV_SINGAPORE,
        MDI_MTV_ATV_SOUTHAFRICA,
        MDI_MTV_ATV_SPAIN,
        MDI_MTV_ATV_TAIWAN,  //40
        MDI_MTV_ATV_THAILAND,
        MDI_MTV_ATV_TURKEY,
        MDI_MTV_ATV_UNITED_ARAB_EMIRATES,
        MDI_MTV_ATV_UNITED_KINGDOM,
        MDI_MTV_ATV_USA,  //45
        MDI_MTV_ATV_URUGUAY,
        MDI_MTV_ATV_VENEZUELA,
        MDI_MTV_ATV_VIETNAM,
        MDI_MTV_ATV_EUROPE_WESTERN}; //49

    //ASSERT(m_setting.selected_country >= 0 &&
           //m_setting.selected_country < sizeof(band)/sizeof(band[0]));
    kal_prompt_trace(MOD_MMI, "VappAtvApp::getBand m_setting.selected_country = %d", m_setting.selected_country);

    return band[m_setting.selected_country];
}

vapp_srv_info_struct *VappAtvApp::getActiveSrv()
{
    return &m_services[m_setting.selected_channel];
}

void VappAtvApp::setAudMode(VfxU32 mode)
{
    vapp_srv_info_struct *infoPtr = getActiveSrv();

    infoPtr->audio_mode = mode;

    mdi_mtv_set_audio_mode(m_mtvHandle, infoPtr->service_id, mode);
}

VfxBool VappAtvApp::getStoragePath(VfxWChar *storagePath)
{
    VfxS32 ret;
    VfxU8 letter;
    FS_HANDLE handle;

    letter = srv_fmgr_drv_get_letter_by_type((srv_fmgr_drv_type_enum)m_setting.storage);
    ret = FS_GetDevStatus(letter, FS_MOUNT_STATE_ENUM);
    if (ret != FS_NO_ERROR)
    {
        m_storageValid = VFX_FALSE;
        return VFX_FALSE;
    }

    kal_wsprintf(storagePath, "%c:\\", letter);
    mmi_ucs2cat((VfxChar*) storagePath, (VfxChar*) SHOOTING_DOWNLOAD_FOLDER_NAME);

    handle = FS_Open((kal_uint16*) storagePath, FS_OPEN_DIR | FS_READ_ONLY);

    /* path already exist */
    if (handle >= 0)
    {
        FS_Close(handle);
        m_storageValid = VFX_TRUE;
        return VFX_TRUE;
    }

    /* create directory if it is not there */
    ret = FS_CreateDir((kal_uint16*) storagePath);
    if (ret == FS_NO_ERROR)
    {
        m_storageValid = VFX_TRUE;
        return VFX_TRUE;
    }
    else
    {
        m_storageValid = VFX_FALSE;
        return VFX_FALSE;
    }
}

#ifdef __MMI_ATV_STORAGE_SELECT__
void VappAtvApp::setStorage(srv_fmgr_drv_type_enum type)
{
    m_setting.storage = type;
    writeSetting();

    updateStorageStatus();

    MMI_TRACE(TRACE_GROUP_2, TRC_VAPP_ATV_SET_STORAGE, type, m_storageValid);

}
#endif

#ifdef __MMI_ATV_RECORD__
void VappAtvApp::initRecSizeList()
{
    VfxS32 idx;
    VfxBool supported = VFX_FALSE;
    mdi_mtv_get_supported_record_size(m_mtvHandle, &recSizeNum, recSizeList);

    ASSERT(recSizeNum > 0 && recSizeNum <= MDI_MTV_RECORDER_SIZE_COUNT);

    for (idx = 0; idx < recSizeNum; idx ++)
    {
        if (m_setting.record_size == recSizeList[idx])
        {
            supported = VFX_TRUE;
        }
    }
#ifdef __MMI_ATV_RECORD_SIZE_SELECT__
    if (!supported)
    {
        setRecSize(recSizeList[recSizeNum - 1]);
    }
#endif
}
#endif

void VappAtvApp::getNextFileName(VfxWChar *storagePath, FILE_TYPE_ENUM type)
{

    VfxU16 filename_seq_no;
    FS_HANDLE file_handle;
    VfxU16 file_check = 0;
    VfxS32 length;
    VfxWChar prefix[10];
    VfxWChar numStr[10];
    VfxWChar postfix[10];

    if (type == FILE_TYPE_IMG)
    {
        kal_wsprintf(prefix, "TVIMG");
        kal_wsprintf(postfix, ".jpg");
        filename_seq_no = m_setting.img_file_no;
    }
    else
    {
        kal_wsprintf(prefix, "TVREC");
        kal_wsprintf(postfix, ".3gp");
        filename_seq_no = m_setting.rec_file_no;
    }

    length = mmi_ucs2strlen((CHAR*)storagePath);
    if (filename_seq_no == 0xffff)
    {
        filename_seq_no = 0;    /* init value */
    }



    while (1)
    {
        filename_seq_no++;
        if (filename_seq_no > 99999) /* more than 5 digits */
        {
            filename_seq_no = 1;
        }

        kal_wsprintf(numStr, "%04d", filename_seq_no);
        storagePath[length] = 0;
        mmi_ucs2cat((CHAR*)storagePath, (CHAR*)prefix);
        mmi_ucs2cat((CHAR*)storagePath, (CHAR*)numStr);
        mmi_ucs2cat((CHAR*)storagePath, (CHAR*) postfix);

        file_handle = FS_Open(storagePath, FS_READ_ONLY);

        if (file_handle >= 0)
        {
            // file exist
            FS_Close(file_handle);

            file_check ++;

            if (file_check >= 99999)
            {
                break;
            }
        }
        else
        {
            if (type == FILE_TYPE_IMG)
            {
                m_setting.img_file_no = filename_seq_no;
            }
            else
            {
                m_setting.rec_file_no = filename_seq_no;
            }

            writeSetting();
            break;
        }
    }
}


MDI_RESULT VappAtvApp::getSnapshot(gdi_handle layer_handle, VfxWChar *storagePath)
{
    MDI_RESULT ret;
    VfxU8 *snapBuffer;
    gdi_handle snapHandle;
    VfxS32 width, height, bufferLen;
    gdi_color_format format;

    // check state
    if (getPlayerState() != ATV_PLAYER_PLAY)
    {
        return MDI_RES_MTV_ERR_SNAPSHOT_FAILED;
    }

    // check storage path
    ret = getStoragePath(storagePath);
    if (!ret)
    {
        return MDI_RES_MTV_ERR_SNAPSHOT_FAILED;
    }
    getNextFileName(storagePath, FILE_TYPE_IMG);

    // get width, height, format
    gdi_layer_push_and_set_active(layer_handle);
    gdi_layer_get_dimension(&width, &height);
    gdi_layer_get_color_format(&format);
    gdi_layer_pop_and_restore_active();
    bufferLen = width * height * (GDI_MAINLCD_BIT_PER_PIXEL>>3);

    // Allocate buffer & layer handle
    snapBuffer = (VfxU8 *)applib_asm_alloc_nc_r(getGroupId(), bufferLen);
    ASSERT(snapBuffer != NULL);

    gdi_layer_create_using_outside_memory(
        0, 0, width, height, &snapHandle, snapBuffer, bufferLen);
    ASSERT(snapHandle != GDI_LAYER_EMPTY_HANDLE);

    gdi_layer_push_and_set_active(snapHandle);
    gdi_layer_set_color_format(format);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    /* get buffer */
    ret = mdi_mtv_get_hw_layer_buffer_content(
            snapHandle, snapBuffer, bufferLen);
    if (ret != MDI_RES_MTV_SUCCEED)
    {
        goto release;
    }

    // stop player
    deInitDisplay(VFX_FALSE);

    // get snapshot
    ret = mdi_mtv_get_snapshot(
            m_mtvHandle, snapHandle, storagePath);

    // start player
    //initDisplay();

release:

    if (snapHandle != GDI_LAYER_EMPTY_HANDLE)
    {
        gdi_layer_free(snapHandle);
        snapHandle = GDI_LAYER_EMPTY_HANDLE;
    }

    if (snapBuffer != NULL)
    {
        applib_asm_free_r(getGroupId(), snapBuffer);
        snapBuffer = NULL;
    }

    return ret;
}

MDI_RESULT VappAtvApp::getRecFrame(VfxWChar *storagePath)
{
    MDI_RESULT ret;
    gdi_handle thumHandle;

    // check state
    if (getPlayerState() == ATV_PLAYER_PLAY)
    {
        return MDI_RES_MTV_FAILED;
    }

	
	gdi_handle tempLayerhandle;

    // create thumbnail handle
#ifdef __MDI_DISPLAY_YUYV422_SUPPORT__	
	VfxU8 * tempThumbnailMem;
	VFX_ALLOC_MEM_EX(tempThumbnailMem, VAPP_ATV_THUMBNAIL_SIZE,VFX_SYS_MEM_ALLOC_FLAG_FB, this);
	vfx_sys_mem_zero(tempThumbnailMem, VAPP_ATV_THUMBNAIL_SIZE);														   

	gdi_layer_create_cf_using_outside_memory(
		GDI_COLOR_FORMAT_UYVY422,
		0, 
		0, 
		VAPP_ATV_THUMBNAIL_W, 
		VAPP_ATV_THUMBNAIL_H,
		&tempLayerhandle, 
		tempThumbnailMem, 
		VAPP_ATV_THUMBNAIL_SIZE);

	ASSERT(tempLayerhandle != GDI_LAYER_EMPTY_HANDLE);

	gdi_layer_create_cf_using_outside_memory(
		GDI_COLOR_FORMAT_16,
		0, 
		0, 
		VAPP_ATV_THUMBNAIL_W, 
		VAPP_ATV_THUMBNAIL_H,
		&thumHandle, 
		m_recThumbBuffer, 
		VAPP_ATV_THUMBNAIL_SIZE);

#else
    gdi_layer_create_using_outside_memory(
		0, 
		0, 
		VAPP_ATV_THUMBNAIL_W, 
		VAPP_ATV_THUMBNAIL_H,
		&thumHandle, 
		m_recThumbBuffer, 
		VAPP_ATV_THUMBNAIL_SIZE);

#endif							

    ASSERT(thumHandle != GDI_LAYER_EMPTY_HANDLE);

	mdi_video_info_struct video_info;
#ifdef __MDI_DISPLAY_YUYV422_SUPPORT__	

	ret = mdi_video_ply_open_clip_file(getGroupId(), (const VfxChar*)storagePath, &video_info);
	if (ret != MDI_RES_VDOPLY_SUCCEED)
	{
		goto release;
	}
	mdi_video_ply_set_frame_mode(MDI_VIDEO_FRAME_MODE_FIT_OUTSIDE);
	ret = mdi_video_ply_seek_and_get_frame(0, tempLayerhandle);
	
	gdi_layer_push_and_set_active(thumHandle);
	gdi_layer_clear(GDI_COLOR_BLACK);
    mdi_video_ply_close_clip_file();
	
	gdi_layer_flatten(tempLayerhandle,0,0,0);
	gdi_layer_pop_and_restore_active();
	
#else

    gdi_layer_push_and_set_active(thumHandle);
    gdi_layer_clear(GDI_COLOR_BLACK);
    gdi_layer_pop_and_restore_active();

    // get frame
    mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_PREVIEW);
    ret = mdi_video_ply_open_clip_file(getGroupId(), (const VfxChar*)storagePath, &video_info);
    if (ret != MDI_RES_VDOPLY_SUCCEED)
    {
        goto release;
    }
    mdi_video_ply_set_frame_mode(MDI_VIDEO_FRAME_MODE_FIT_OUTSIDE);
	
    ret = mdi_video_ply_seek_and_get_frame(0, thumHandle);
    mdi_video_ply_close_clip_file();
#endif

release:
#ifdef __MDI_DISPLAY_YUYV422_SUPPORT__	
	gdi_layer_free(tempLayerhandle);
    VFX_FREE_MEM(tempThumbnailMem);
#endif
    gdi_layer_free(thumHandle);

    return ret;
}

#ifdef __MMI_ATV_RECORD_SIZE_SELECT__
void VappAtvApp::setRecSize(mdi_mtv_recorder_size_enum size)
{
	#ifdef __MMI_ATV_RECORD__
    mdi_mtv_set_record_size(size);
	#endif

    m_setting.record_size = size;
    writeSetting();
}
#endif

void VappAtvApp::setAdjustValue(VfxU8 brightness, VfxU8 contrast, VfxU8 saturation)
{
    m_setting.brightness = brightness;
    m_setting.contrast = contrast;
    m_setting.saturation = saturation;

    mdi_mtv_set_brightness(brightness);
    mdi_mtv_set_contrast(contrast);
    mdi_mtv_set_saturation(saturation);

    // store NVRAM
    writeSetting();
}



//Utility function
VfxWString VappAtvApp::getDrvString(srv_fmgr_drv_type_enum type)
{
    switch (type)
    {
        case SRV_FMGR_DRV_PHONE_TYPE:
            return VFX_WSTR_RES(STR_GLOBAL_PHONE);
        case SRV_FMGR_DRV_CARD_TYPE:
            return VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD);
        default:
            ASSERT(0);
            return VFX_WSTR_RES(STR_GLOBAL_PHONE);
    }

}

VfxWString VappAtvApp::getRecSizeString(mdi_mtv_recorder_size_enum size)
{
    switch (size)
    {
        case MDI_MTV_RECORDER_SIZE_QCIF:
            return VFX_WSTR_RES(STR_ID_VAPP_ATV_176X144);
//            break;
        case MDI_MTV_RECORDER_SIZE_QVGA:
            return VFX_WSTR_RES(STR_ID_VAPP_ATV_320X240);
           // break;
        case MDI_MTV_RECORDER_SIZE_HVGA:
            return VFX_WSTR_RES(STR_ID_VAPP_ATV_480X320);
           // break;
        default:
            ASSERT(0);
            return VFX_WSTR_RES(STR_ID_VAPP_ATV_176X144);
    }
}

void VappAtvApp::setPageHighPriority()
{
    if(m_pageHighPrioSetCount==0)
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
        m_pageHighPrioSetCount++;
    }
}

void VappAtvApp::clearPageHighPriority()
{
    while(m_pageHighPrioSetCount!=0)
    {
        mmi_frm_end_scenario(MMI_SCENARIO_ID_HIGHEST_SCRN);
        m_pageHighPrioSetCount--;
        //ASSERT(m_pageHighPrioSetCount >= 0);
        kal_prompt_trace(MOD_MMI, "VappAtvApp::clearPageHighPriority() m_pageHighPrioSetCount = %d", m_pageHighPrioSetCount);
    }
}

#endif // __MMI_ATV_SUPPORT__
