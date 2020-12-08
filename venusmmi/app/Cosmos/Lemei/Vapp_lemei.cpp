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
 *  Vapp_lemei.cpp
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_OP02_LEMEI_FTO__
//#include "GlobalResDef.h"
#include "Lemei.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "vcui_soundrec_gprot.h"
#include "UcSrvGprot.h"
#include "vapp_uc_gprot.h"
#include "vapp_fmgr_cui_gprot.h"
#include "FileMgrCuiGProt.h"
#include "FileMgrType.h"
#include "vapp_fmgr.h"
#include "vcp_global_popup.h"
//#include "mmi_rp_file_type_def.h"

extern "C"
{
#include "vcui_camco_gprot.h"
#include "vcui_gallery_gprot.h"
#include "wgui_categories_util.h"
#include "SimCtrlSrvGprot.h"
#include "NwUsabSrvGprot.h"
#include "UmSrvGprot.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define BUTTON_ID_LOACA_PICTURE '1'
#define BUTTON_ID_LOACA_AUDIO '2'
#define BUTTON_ID_LOACA_VIDEO '3'

#define VAPP_LEMEI_GET_SIZE(x)                  (sizeof(x) / sizeof(x[0]))

/***************************************************************************** 
 * Function
 *****************************************************************************/
extern "C" MMI_BOOL vapp_lemei_proprietary_sim(mmi_sim_enum sim)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR hplmn[SRV_MAX_PLMN_LEN + 1];
    S32 n_sim, size;
    S32 i;
    MMI_BOOL ret;
	const S8 *g_op02_lemei_sim[] =
	{
	    "46001",    /* China Unicom */
	};
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* If the SIM's IMSI is not ready, e.g., no SIM inserted, don't enable
       the Homescreen. */
    ret = srv_sim_ctrl_get_home_plmn(sim, hplmn, SRV_MAX_PLMN_LEN + 1);

    if (!ret)
    {
        return MMI_FALSE;
    }

    /* Check the MCC/MNC is the proprietary one. */
    n_sim = VAPP_LEMEI_GET_SIZE(g_op02_lemei_sim);

    for (i = 0; i < n_sim; i++)
    {
        size = strlen(g_op02_lemei_sim[i]);
        
        if (!memcmp(hplmn, g_op02_lemei_sim[i], size))
        {
            return MMI_TRUE;
        }
    }

    return MMI_FALSE;
}


extern "C" MMI_ID vapp_lemei_launch(void *param, U32 param_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (MMI_FALSE == srv_nw_usab_is_any_network_available())
	{
		mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
					(WCHAR*)VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE).getBuf());
        return NULL;
	}

	if (vapp_lemei_proprietary_sim(MMI_SIM1))
	{
		VfxAppLauncher::launch(VAPP_LEMEI, VFX_OBJ_CLASS_INFO(VappLemeiApp), GRP_ID_ROOT);
		return NULL;
	}
    #ifdef __MMI_DUAL_SIM__
    else if(vapp_lemei_proprietary_sim(MMI_SIM2))
    {
		VfxAppLauncher::launch(VAPP_LEMEI, VFX_OBJ_CLASS_INFO(VappLemeiApp), GRP_ID_ROOT);
		return NULL;
    }
    #endif
	else
	{
	    if (MMI_TRUE == srv_um_check_ready_type(srv_um_support_msg_type()))
	    {
			VfxAppLauncher::launch(VAPP_LEMEI, VFX_OBJ_CLASS_INFO(VappLemeiApp), GRP_ID_ROOT);
			return NULL;
	    }
	    else
	    {
	        //TODO: global popup need to modify the prototype
	        /* display a error popup */
	        vcp_global_popup_show_confirm_one_button_id(
	            GRP_ID_ROOT,
	            VCP_POPUP_TYPE_INFO, 
	            STR_ID_VAPP_LEMEI_NOT_READY, 
	            STR_GLOBAL_OK, 
	            VCP_POPUP_BUTTON_TYPE_NORMAL,  
	            NULL,
	            NULL);
	    }
	}

	//VfxAppLauncher::launch(VAPP_LEMEI, VFX_OBJ_CLASS_INFO(VappLemeiApp), GRP_ID_ROOT);
	
	return NULL;
}

VFX_IMPLEMENT_CLASS("VappLemeiApp", VappLemeiApp, VfxApp);
void VappLemeiApp::onRun(void * args, VfxU32 argSize)
{
	VfxApp::onRun(args, argSize);

	if (vapp_lemei_proprietary_sim(MMI_SIM1))
	{
	
		VappLemeiScreen * scr;
		VFX_OBJ_CREATE(scr, VappLemeiScreen, this);
		scr->show();
	}
    #ifdef __MMI_DUAL_SIM__
    else if(vapp_lemei_proprietary_sim(MMI_SIM2))
    {
    
		VappLemeiScreen * scr;
		VFX_OBJ_CREATE(scr, VappLemeiScreen, this);
		scr->show();
    }
    #endif
    else
    {
        launchNormalUnifiedComposer();
    }
}

void VappLemeiApp::launchNormalUnifiedComposer(void)
{
    VappUcEntryStruct data;
    memset(&data, 0, sizeof(VappUcEntryStruct));

    data.app_id = this->getGroupId();
    data.info_type = SRV_UC_INFO_TYPE_MMS;

	data.operation = (vappUcMsgOperationEnum) UC_OPERATION_WRITE_NEW_MSG;
	data.type = (srv_uc_state_enum)SRV_UC_STATE_WRITE_NEW_MSG; 
	data.msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;

    //vappUcAppLauncher(&data);
    mmi_id cui_id;
    cui_id = vcui_unifiedcomposer_create(this->getGroupId(), &data);
    if(cui_id != GRP_ID_INVALID)
    {
        //vfxSetCuiCallerScr(cui_id, this);
        vcui_unifiedcomposer_run(cui_id);
    }
}

mmi_ret VappLemeiApp::onProc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
	    case EVT_ID_CUI_UC_MSGCOMPOSER_CLOSE:
	    {
			VfxApp* app = NULL;
	        vcui_unifiedcomposer_close(((mmi_group_event_struct*) evt)->sender_id);

		    app = VfxAppLauncher::findApp(VAPP_LEMEI, VFX_OBJ_CLASS_INFO(VappLemeiApp), VFX_APP_LAUNACHER_FIND_APP_NORMAL_FLAG, 0);
		    if (app)
		    {
		        VfxAppLauncher::terminate(app->getGroupId());
		    }
			
	        break;
	    }
	}
	return MMI_RET_DONT_CARE;
}

VFX_IMPLEMENT_CLASS("VappLemeiScreen", VappLemeiScreen, VfxMainScr);
void VappLemeiScreen::on1stReady()
{
	VfxMainScr::on1stReady();
	VappLemeiPage * page;
	VFX_OBJ_CREATE(page, VappLemeiPage, this);
	pushPage(0, page);
}


VFX_IMPLEMENT_CLASS("VappLemeiPage", VappLemeiPage, VfxPage);

VappLemeiPage::VappLemeiPage() : 
    m_camcoLimit(NULL)
{

}
void VappLemeiPage::onInit()
{
	VfxPage::onInit();
	//setStatusBar(VFX_FALSE);

	VFX_OBJ_CREATE(m_background, VfxImageFrame, this);
    m_background->setResId(IMG_ID_VAPP_LEMEI_BG);
    m_background->setPos(0, 0);
	
	VcpTitleBar * bar;
	VFX_OBJ_CREATE(bar, VcpTitleBar, this);
	setTopBar(bar);
	bar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_LEMEI));
	
	VcpToolBar *toolbar;
	VFX_OBJ_CREATE(toolbar, VcpToolBar, this);

	toolbar->addItem(BUTTON_ID_LOACA_AUDIO, VFX_WSTR_RES(STR_ID_VAPP_LOCAL_AUDIO), VCP_IMG_TOOL_BAR_COMMON_ITEM_INSERT);
	toolbar->addItem(BUTTON_ID_LOACA_PICTURE, VFX_WSTR_RES(STR_ID_VAPP_LOCAL_PICTURE), VCP_IMG_TOOL_BAR_COMMON_ITEM_INSERT);
	toolbar->addItem(BUTTON_ID_LOACA_VIDEO, VFX_WSTR_RES(STR_ID_VAPP_LOCAL_VIDEO), VCP_IMG_TOOL_BAR_COMMON_ITEM_INSERT);
	toolbar->m_signalButtonTap.connect(this, &VappLemeiPage::onToolBarTapped);
	setBottomBar(toolbar);


	VFX_OBJ_CREATE(m_btnFrame, VappLemeiButtonFrame, this);
	m_btnFrame->setPos(VFX_BUTTON_FRAME_X, VFX_BUTTON_FRAME_Y);
	m_btnFrame->setSize(VFX_BUTTON_FRAME_WIDTH, VFX_BUTTON_FRAME_HEIGHT);
	m_btnFrame->m_signalButtonClicked.connect(this, &VappLemeiPage::onButtonClicked);

}

void VappLemeiPage::onDeinit()
{
	if (m_camcoLimit)
	{
		VFX_FREE_MEM(m_camcoLimit);
		m_camcoLimit = NULL;
	}
	VfxPage::onDeinit();
}

void VappLemeiPage::onButtonClicked(VappLemeiButtonFrame::VcpLemeiButtonTypeEnum id)
{
	LemeiEnterMultimediaApp(id);
}
mmi_ret VappLemeiPage::onProc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
		case EVT_ID_VCUI_SOUNDREC_RESULT:
		{
			vcui_soundrec_evt_struct *soundRecEvt = (vcui_soundrec_evt_struct*)evt;
			if (soundRecEvt->result > 0)
			{
				/*Success Handling*/
				
				//app->ucSelectObjectFromFmToInsertWarningModeCheck((PU16)soundRecEvt->file_path, 0);
				m_filepath.loadFromMem(soundRecEvt->file_path);
				vcui_soundrec_close(soundRecEvt->sender_id);
				LemeilaunchUnifiedComposer();
				return MMI_RET_OK;
			}
            else if (soundRecEvt->result == 0)
			{
				/*Cancel Handling*/
				vcui_soundrec_close(soundRecEvt->sender_id);

			}
            else 
			{
				/*Error handling*/
				vcui_soundrec_close(soundRecEvt->sender_id);
			}
			break;
		}
		case VCUI_CAMCO_EVENT_RESULT_SUCCESS:
		{
			vcui_camco_event_struct *camCoEvt = (vcui_camco_event_struct*)evt;

			if (m_camcoLimit)
			{
				VFX_FREE_MEM(m_camcoLimit);
				m_camcoLimit = NULL;
			}
			
			if (camCoEvt->errCode == VCUI_CAMCO_ERR_NONE)
			{
				//assuming success case
				VfxWChar * path_buffer;
				VfxS32 buff_size = (SRV_FMGR_PATH_MAX_LEN + 1 ) * sizeof(VfxWChar);

				if (NULL == camCoEvt->filePath)
				{
					vcui_camcorder_close(camCoEvt->sender_id);
				}
				else
				{
					VFX_ALLOC_MEM(path_buffer, buff_size, this);
					mmi_ucs2cpy((VfxChar*)path_buffer, (CHAR*)camCoEvt->filePath);

					//m_filepath = VFX_WSTR_MEM(camCoEvt->filePath);

					m_filepath.loadFromMem(path_buffer);
					VFX_FREE_MEM(path_buffer);
					
					vcui_camcorder_close(camCoEvt->sender_id);
					LemeilaunchUnifiedComposer();
				}
			}
			else
			{
				vcui_camcorder_close(camCoEvt->sender_id);
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
					(WCHAR*)VFX_WSTR_RES(vcui_camcorder_get_err_string(camCoEvt->errCode)).getBuf());	
			}
			break;
		}
		case VCUI_CAMCO_EVENT_RESULT_FAILED:
		{
			vcui_camco_event_struct *camCoEvt = (vcui_camco_event_struct*)evt;
			
			if (m_camcoLimit)
			{
				VFX_FREE_MEM(m_camcoLimit);
				m_camcoLimit = NULL;
			}
			if (camCoEvt->errCode != VCUI_CAMCO_ERR_NONE)
			{
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
					(WCHAR*)VFX_WSTR_RES(vcui_camcorder_get_err_string(camCoEvt->errCode)).getBuf());
			}
			vcui_camcorder_close(camCoEvt->sender_id);
			break;
		}

		case EVT_ID_VCUI_FILE_SELECTOR_RESULT: /*evrnt from file manager*/
		{
			vcui_file_selector_result_event_struct *fmgrEvt = (vcui_file_selector_result_event_struct*)evt;

			if (fmgrEvt->result > 0)
			{
				srv_fmgr_fileinfo_struct info = {0,};
				VfxWChar* path_buffer  = NULL;
				filetypes_group_type_enum fileGroup = FMGR_GROUP_UNKNOWN;
				VfxBool   fileToLarge = VFX_FALSE;
				U32 buff_size = (SRV_FMGR_PATH_MAX_LEN + 1 ) * sizeof(VfxWChar);

				VFX_ALLOC_MEM(path_buffer, buff_size, this);

				vcui_file_selector_get_selected_filepath(fmgrEvt->sender_id, &info, path_buffer, buff_size);

				fileGroup = srv_fmgr_types_find_group_by_type((filetypes_file_type_enum)(info.type));
				if ((FMGR_GROUP_AUDIO == fileGroup) || (FMGR_GROUP_VIDEO == fileGroup))
				{
					if (info.size >= 290 * 1024)
					{
						fileToLarge = VFX_TRUE;
					}
				}
				if (!fileToLarge)
				{
					m_filepath.loadFromMem(path_buffer);
					LemeilaunchUnifiedComposer();
				}
				getMainScr()->popPage(); //delete the audio tabpage
				vcui_file_selector_close(fmgrEvt->sender_id);
				VFX_FREE_MEM(path_buffer);
				if (fileToLarge)
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
									(WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_FILE_TOO_LARGE).getBuf());
				}
			}
            else  if (fmgrEvt->result == 0)
			{
				getMainScr()->popPage(); //delete the audio tabpage
				vcui_file_selector_close(fmgrEvt->sender_id);
			}
            else
			{
				getMainScr()->popPage(); //delete the audio tabpage
				vcui_file_selector_close(fmgrEvt->sender_id);

			}
			//getMainScr()->popPage(); //delete the audio tabpage
			break;
		}
			
		case EVT_ID_VCUI_GALLERY_CLOSE_GID: /*Event from Gallery*/
		{
			vcui_gallery_evt_struct *galleryEvt = (vcui_gallery_evt_struct*)evt;

			if (galleryEvt->result == VCUI_GALLERY_RESULT_OK)
			{
				WCHAR* path_buffer  = NULL;
				U32 buff_size = (SRV_FMGR_PATH_MAX_LEN + 1 ) * sizeof(WCHAR);
				srv_fmgr_fileinfo_struct info = {0,};
				filetypes_group_type_enum fileGroup = FMGR_GROUP_UNKNOWN;
				VfxBool   fileToLarge = VFX_FALSE;
				
				VFX_ALLOC_MEM(path_buffer, buff_size, this);
				vcui_gallery_picker_get_single_path(galleryEvt->sender_id, path_buffer, &buff_size);

				srv_fmgr_fs_path_get_fileinfo(path_buffer, &info);

				fileGroup = srv_fmgr_types_find_group_by_type((filetypes_file_type_enum)(info.type));
				if ((FMGR_GROUP_AUDIO == fileGroup) || (FMGR_GROUP_VIDEO == fileGroup))
				{
					if (info.size >= 290 * 1024)
					{
						fileToLarge = VFX_TRUE;
					}
				}
				if (!fileToLarge)
				{
					m_filepath.loadFromMem(path_buffer);
					LemeilaunchUnifiedComposer();
				}
				
				VFX_FREE_MEM(path_buffer);

				vcui_gallery_close(galleryEvt->sender_id);
				if (fileToLarge)
				{
					mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
									(WCHAR*)VFX_WSTR_RES(STR_ID_VAPP_FILE_TOO_LARGE).getBuf());
				}
			}
			else
			{
				vcui_gallery_close(galleryEvt->sender_id);
			}
		}
			break;

	    case EVT_ID_CUI_UC_LEMEICOMPOSER_CLOSE:
	    {
	        vcui_unifiedcomposer_close(((mmi_group_event_struct*) evt)->sender_id);
	        break;
	    }

		default:
			break;
	}
	return MMI_RET_DONT_CARE;
}

void VappLemeiPage::LemeiEnterMultimediaApp(VappLemeiButtonFrame::VcpLemeiButtonTypeEnum id)
{
	switch (id)
	{
		case VappLemeiButtonFrame::BTN_ADO:
		{
			mmi_id cui_id = vcui_soundrec_create(getApp()->getGroupId());
			if (cui_id > 0)
			{
				vfxSetCuiCallerScr(cui_id, getMainScr());
				/* Set size limit to 300k */
				//vcui_soundrec_set_record_size(cui_id, 290*1024);
				vcui_soundrec_set_record_time(cui_id,180);
				vcui_soundrec_set_record_quality(cui_id, VCUI_SOUNDREC_QUALITY_NORMAL);
				vcui_soundrec_set_param(cui_id, VCUI_SOUNDREC_PARAM_NO_PAUSE);
				vcui_soundrec_set_param(cui_id, VCUI_SOUNDREC_PARAM_NO_PREVIEW);   
				vcui_soundrec_set_param(cui_id, VCUI_SOUNDREC_PARAM_DISPLAY_REC_LIMIT);   
				
				vcui_soundrec_run(cui_id);
			}
			break;
		}
		case VappLemeiButtonFrame::BTN_CAM:
		{
			vcui_camco_err_code_enum errCode = VCUI_CAMCO_ERR_NONE;
			if ((errCode = vcui_camcorder_launchable_check())== VCUI_CAMCO_ERR_NONE)
			{
				vcui_camco_param_struct param;

				vcui_camcorder_struct_init(&param);
				param.level = VCUI_CAMCO_SETTING_FULL;
				param.mode = VCUI_CAMCO_CAMERA;

				mmi_id cui_id = vcui_camcorder_create(getApp()->getGroupId(), &param);
			
				if (cui_id > 0)
				{
					vfxSetCuiCallerScr(cui_id, getMainScr());
					vcui_camcorder_run(cui_id);
				}
			}
			else
			{
				//seems Camcoder not ready 
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
					(WCHAR*)VFX_WSTR_RES(vcui_camcorder_get_err_string(errCode)).getBuf());
			}
			break;
		}

		case VappLemeiButtonFrame::BTN_VDO:
		{
			vcui_camco_err_code_enum errCode = VCUI_CAMCO_ERR_NONE;
			if ((errCode = vcui_camcorder_launchable_check())== VCUI_CAMCO_ERR_NONE)
			{
				vcui_camco_param_struct param;
				vcui_camco_setting_limit_struct *temp_limit;


				vcui_camcorder_struct_init(&param);
				param.level = VCUI_CAMCO_SETTING_NONE;

				param.mode = VCUI_CAMCO_RECORDER;
				param.settingLimitNum = 3;

				VFX_ALLOC_MEM(m_camcoLimit, sizeof(vcui_camco_setting_limit_struct) * (param.settingLimitNum), this);

				temp_limit = (vcui_camco_setting_limit_struct*)m_camcoLimit;

                temp_limit[0].type = VCUI_CAMCO_SETTING_LIMIT_RECLIMIT;
                temp_limit[0].detail = VCUI_CAMCO_SETTING_LIMIT_RECLIMIT_TIME;
                temp_limit[0].additionalInfo = 20;
                temp_limit[1].type = VCUI_CAMCO_SETTING_LIMIT_RECQTY;
                temp_limit[1].detail = VCUI_CAMCO_SETTING_LIMIT_RECQTY_MMS_QTY;
                temp_limit[2].type = VCUI_CAMCO_SETTING_LIMIT_RECSIZE;
                temp_limit[2].detail = VCUI_CAMCO_SETTING_LIMIT_RECSIZE_BELOW_QCIF;

				param.settingLimitation = temp_limit;

				mmi_id cui_id = vcui_camcorder_create(getApp()->getGroupId(), &param);
			
				if (cui_id > 0)
				{
					vfxSetCuiCallerScr(cui_id, getMainScr());
					vcui_camcorder_run(cui_id);
				}
				else
				{
					VFX_FREE_MEM(m_camcoLimit);
					m_camcoLimit = NULL;
				}
			}
			else
			{
				//seems Camcoder not ready 
				mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_FAILURE,
					(WCHAR*)VFX_WSTR_RES(vcui_camcorder_get_err_string(errCode)).getBuf());
			}
			break;
		}
		default:
			break;
	}
}
void VappLemeiPage::LemeilaunchUnifiedComposer(void)
{
    VappUcEntryStruct data;
    memset(&data, 0, sizeof(VappUcEntryStruct));

    data.app_id = getApp()->getGroupId();
    data.media_num = 1;
    data.file_path = (VfxU8*)m_filepath.getBuf();
    //data.info_type = SRV_UC_INFO_TYPE_MMS;

	data.info_type = (srv_uc_info_type_enum) SRV_UC_INFO_TYPE_LEMEI_MMS;
	data.operation = (vappUcMsgOperationEnum) UC_OPERATION_WRITE_NEW_MSG;
	data.type = (srv_uc_state_enum)SRV_UC_STATE_WRITE_NEW_MSG; 
	data.msg_type = SRV_UC_MSG_TYPE_MMS_ONLY;
	data.edit_mode = SRV_UC_MMS_EDIT_MODE_LEMEI_MMS;
	data.subject = (U8*)get_string(STR_ID_VAPP_LEMEI_SUBJECT); /*special for Lemei*/

    
    //vappUcAppLauncher(&data);
    mmi_id cui_id;
    cui_id = vcui_unifiedcomposer_create(getApp()->getGroupId(), &data);
    if(cui_id != GRP_ID_INVALID)
    {
        vfxSetCuiCallerScr(cui_id, getMainScr());
        vcui_unifiedcomposer_run(cui_id);
    }
}

void VappLemeiPage::onToolBarTapped(VfxObject* sender, VfxId id)
{
    switch (id)
    {
        case BUTTON_ID_LOACA_AUDIO:
        {

			enterLocalAudioSelector();
			break;
		}

		case BUTTON_ID_LOACA_PICTURE:
		{    
			FMGR_FILTER filter;
            //mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_IMAGE_OPEN_MODE);
			setImageFilter(&filter);
		    mmi_id cui_id;
			cui_id = vcui_gallery_image_picker_create(getApp()->getGroupId(), MMI_FALSE, &filter);

			if (cui_id)
			{
				vfxSetCuiCallerScr(cui_id, getMainScr());
				vcui_gallery_run(cui_id);
			}
			break;
        }

        case BUTTON_ID_LOACA_VIDEO:
		{
			FMGR_FILTER filter;
            //mma_uc_set_file_mgr_filter(&filter, MMA_UC_FILTER_MODE_VIDEO_OPEN_MODE);
			setVideoFilter(&filter);
		    mmi_id cui_id;
			cui_id = vcui_gallery_video_picker_create(getApp()->getGroupId(), MMI_FALSE, &filter); 

			if (cui_id)
			{
				vfxSetCuiCallerScr(cui_id, getMainScr());
				vcui_gallery_run(cui_id);
			}
			break;
        }

		default:
			break;

    }
}

void VappLemeiPage::enterLocalAudioSelector()
{
	VfxMainScr *scr = getMainScr();
	VappLemeiLocalAudioTabPage *localAudioTabPage;
	VFX_OBJ_CREATE(localAudioTabPage, VappLemeiLocalAudioTabPage, scr);
	scr->pushPage(0, localAudioTabPage);
}

void VappLemeiPage::setImageFilter(FMGR_FILTER *filter)
{
	FMGR_FILTER_INIT(filter);
	FMGR_FILTER_SET(filter, FMGR_TYPE_BMP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_GIF);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBM);
    FMGR_FILTER_SET(filter, FMGR_TYPE_WBMP);
#ifdef GDI_USING_PNG
    FMGR_FILTER_SET(filter, FMGR_TYPE_PNG);
#endif 
#ifdef JPG_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPG);
    FMGR_FILTER_SET(filter, FMGR_TYPE_JPEG);
#endif /* JPG_DECODE */ 
#ifdef SVG_SUPPORT
    FMGR_FILTER_SET(filter, FMGR_TYPE_SVG);
#endif 

    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

void VappLemeiPage::setVideoFilter(FMGR_FILTER *filter)
{
	FMGR_FILTER_INIT(filter);
#ifdef __MMI_MMS_VIDEO_FEATURE__
#ifdef MP4_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
    FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
    FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#endif /* MP4_DECODE */ 
#ifdef __RM_DEC_SUPPORT__
    FMGR_FILTER_SET(filter, FMGR_TYPE_RV);
    FMGR_FILTER_SET(filter, FMGR_TYPE_RM);
    FMGR_FILTER_SET(filter, FMGR_TYPE_RMVB);
#endif /* __RM_DEC_SUPPORT__ */ 

#ifdef MJPG_DECODE
    FMGR_FILTER_SET(filter, FMGR_TYPE_AVI);
#endif 
#endif
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
    FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

VFX_IMPLEMENT_CLASS("VappLemeiButtonFrame", VappLemeiButtonFrame, VfxFrame);
void VappLemeiButtonFrame::onInit()
{
	VfxFrame::onInit();

	VFX_OBJ_CREATE(m_AdoImg, VfxImageFrame, this);
	m_AdoImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_LEMEI_AUDIO_RECORDER_UP));
	m_AdoImg->setPos(VFX_BUTTON_IMG_1_X, 0);

	VFX_OBJ_CREATE(m_camImg, VfxImageFrame, this);
	m_camImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_LEMEI_CAMERA_UP));
	m_camImg->setPos(VFX_BUTTON_IMG_2_X, 0);

	VFX_OBJ_CREATE(m_VdoImg, VfxImageFrame, this);
	m_VdoImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_LEMEI_VIDEO_RECORDER_UP));
	m_VdoImg->setPos(VFX_BUTTON_IMG_3_X, 0);

    VFX_OBJ_CREATE(m_btnAdo, VcpButton, this);
	m_btnAdo->setOpacity(0.0f);
	m_btnAdo->setPos(VFX_BUTTON_IMG_1_X + VFX_BUTTON_1_OFFSET, 0);
    m_btnAdo->setSize(VFX_BUTTON_WIDTH, VFX_BUTTON_HEIGHT);
    m_btnAdo->setId(VappLemeiButtonFrame::BTN_ADO);
	m_btnAdo->m_signalStateChanged.connect(this, &VappLemeiButtonFrame::onButtonStateChange);
	m_btnAdo->m_signalClicked.connect(this, &VappLemeiButtonFrame::onButtonClicked);

    VFX_OBJ_CREATE(m_btnCam, VcpButton, this);
	m_btnCam->setOpacity(0.0f);
	m_btnCam->setPos(VFX_BUTTON_IMG_2_X + VFX_BUTTON_2_OFFSET, 0);
    m_btnCam->setSize(VFX_BUTTON_WIDTH, VFX_BUTTON_HEIGHT);
    m_btnCam->setId(VappLemeiButtonFrame::BTN_CAM);
	m_btnCam->m_signalStateChanged.connect(this, &VappLemeiButtonFrame::onButtonStateChange);
	m_btnCam->m_signalClicked.connect(this, &VappLemeiButtonFrame::onButtonClicked);

    VFX_OBJ_CREATE(m_btnVdo, VcpButton, this);
	m_btnVdo->setOpacity(0.0f);
	m_btnVdo->setPos(VFX_BUTTON_IMG_3_X + VFX_BUTTON_3_OFFSET, 0);
    m_btnVdo->setSize(VFX_BUTTON_WIDTH, VFX_BUTTON_HEIGHT);
    m_btnVdo->setId(VappLemeiButtonFrame::BTN_VDO);
	m_btnVdo->m_signalStateChanged.connect(this, &VappLemeiButtonFrame::onButtonStateChange);
	m_btnVdo->m_signalClicked.connect(this, &VappLemeiButtonFrame::onButtonClicked);

}

void VappLemeiButtonFrame::onButtonClicked(VfxObject *sender, VfxId id)
{
    VFX_UNUSED(sender);

	m_signalButtonClicked.emit((VcpLemeiButtonTypeEnum)id);    

}

void VappLemeiButtonFrame::onButtonStateChange(VfxObject* obj, VfxId id, VcpButtonStateEnum state)
{
    switch((VcpLemeiButtonTypeEnum)id)
    {
        case BTN_ADO:
        {
		    if (state == VCP_BUTTON_STATE_PRESSED)
		    {
		        m_AdoImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_LEMEI_AUDIO_RECORDER_DOWN));
		    }
			if (state == VCP_BUTTON_STATE_NORMAL)
			{
		        m_AdoImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_LEMEI_AUDIO_RECORDER_UP));
			}
            break;
        }
		
        case BTN_CAM:
        {
		    if (state == VCP_BUTTON_STATE_PRESSED)
		    {
		        m_camImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_LEMEI_CAMERA_DOWN));
		    }
			if (state == VCP_BUTTON_STATE_NORMAL)
			{
		        m_camImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_LEMEI_CAMERA_UP));
			}
            break;
        }
		
        case BTN_VDO:
        {
		    if (state == VCP_BUTTON_STATE_PRESSED)
		    {
		        m_VdoImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_LEMEI_VIDEO_RECORDER_DOWN));
		    }
			if (state == VCP_BUTTON_STATE_NORMAL)
			{
		        m_VdoImg->setImgContent(VfxImageSrc(IMG_ID_VAPP_LEMEI_VIDEO_RECORDER_UP));
			}
            break;
        }
    }

}

VFX_IMPLEMENT_CLASS("VappLemeiLocalAudioTabPage", VappLemeiLocalAudioTabPage, VcpTabCtrlPage);

void VappLemeiLocalAudioTabPage::onInit()
{
	VcpTabCtrlPage::onInit();

    SRV_FMGR_DRVLIST_HANDLE drvListHd = srv_fmgr_drivelist_create(SRV_FMGR_DRIVELIST_TYPE_ACCESSIBLE);
    VfxS32 count = srv_fmgr_drivelist_count(drvListHd);
	VfxS32 fs_ret = 0;
	vapp_fmgr_drive_info_struct drv_info;
	VfxU16 icon_id = IMG_NONE;
	memset(&drv_info, 0, sizeof(vapp_fmgr_drive_info_struct));

	for (VfxS32 index = 0; index < count; index++)
	{
		drv_info.drv_type = srv_fmgr_drv_get_type(srv_fmgr_drivelist_get_drv_letter(drvListHd, index));
		memcpy((void*)drv_info.drv_path, (const void*) srv_fmgr_drv_get_path_by_type((srv_fmgr_drv_type_enum)drv_info.drv_type), (SRV_FMGR_DRV_MAX_NAME_LEN + 1));

		icon_id = drv_info.drv_type < SRV_FMGR_DRV_CARD_TYPE ? IMG_ID_VAPP_FMGR_TAB_PHONE_ICN : IMG_ID_VAPP_FMGR_TAB_CARD_ICN;
		
        VfxWString text;
		if (index == 0)
        {
            text = VFX_WSTR_RES(STR_GLOBAL_PHONE);
        }
        else
        {
			fs_ret = 0;
			//fs_ret = srv_fmgri_drv_get_volume_name(drv_info.drv_path[0], (WCHAR*)drv_name, 40);
			VfxS8 drv_name[40];
			fs_ret = srv_fmgr_drv_get_name(drv_info.drv_path[0], (WCHAR*)drv_name, 40);
            if (fs_ret >= 0)
            {
                text = VFX_WSTR_MEM((VfxWChar*)drv_name);
            }
            else
            {
                text = VFX_WSTR_RES(STR_GLOBAL_MEMORY_CARD);
            }
        }
							
			//addTab((drv_info.drv_type +1 ), text, VcpStateImage(icon_id));

		addTab((index + 1), text, VcpStateImage(icon_id));	
	}


	srv_fmgr_drivelist_destroy(drvListHd);
	setCurrTab(1);

}

VfxPage *VappLemeiLocalAudioTabPage::onCreateTabPage(VfxId tabId)
{
    // create tab page, and update its content
    VappLemeiLocalAudioPage *LocalAudioPage;
    //VFX_OBJ_CREATE(page, VappLemeiLocalAudioPage, this);
    VFX_OBJ_CREATE_EX(LocalAudioPage, VappLemeiLocalAudioPage, this, (tabId));
    switch(tabId)
    {
    case 1:
        
        break;
    case 2:

        break;
    }
    // return the page
    return LocalAudioPage;
}


VFX_IMPLEMENT_CLASS("VappLemeiLocalAudioPage", VappLemeiLocalAudioPage, VfxPage);

VappLemeiLocalAudioPage::VappLemeiLocalAudioPage(VfxId tabId):
	m_Id(tabId),
	m_messageFrame(NULL)
{
}


void VappLemeiLocalAudioPage::onInit()
{
	VfxPage::onInit(); 
	if (m_Id == 1)
	{
		VcpListMenu* m_localAudioList;
	    VFX_OBJ_CREATE(m_localAudioList, VcpListMenu, this);
	    m_localAudioList->setPos(0,0);
	    m_localAudioList->setSize(getSize());
	    m_localAudioList->setAlignParent(
	                VFX_FRAME_ALIGNER_MODE_SIDE,
	                VFX_FRAME_ALIGNER_MODE_SIDE,
	                VFX_FRAME_ALIGNER_MODE_SIDE,
	                VFX_FRAME_ALIGNER_MODE_SIDE);
		m_localAudioList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
		//m_localAudioList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
	    m_localAudioList->setItemHeight(VCP_LIST_MENU_CELL_HEIGHT_MULTI_LINE);
		m_localAudioList->setContentProvider(this);
		m_localAudioList->m_signalItemTapped.connect(this, &VappLemeiLocalAudioPage::onItemShortTapped);
	}
	else
	{

	    const U8 drv = srv_fmgr_drv_get_letter_by_type(SRV_FMGR_DRV_CARD_TYPE);
	    if(MMI_FALSE == srv_fmgr_drv_is_accessible(drv))
	    {
		    if(NULL == m_messageFrame)
		    {
		        VFX_OBJ_CREATE(m_messageFrame, VfxTextFrame, this);
		        m_messageFrame->setColor(0xff909090);
		        m_messageFrame->setAnchor(0.5f, 0.5f);
		        m_messageFrame->setAutoResized(VFX_TRUE);
		        m_messageFrame->setSize((VfxS32)(getSize().width * VCP_LIST_MENU_EMPTY_TEXT_WITH_RATIO), 0);
		        m_messageFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
		        m_messageFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
		        m_messageFrame->setPos(getSize().width / 2, getSize().height / 2);
		        m_messageFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID,
		                                       VFX_FRAME_ALIGNER_MODE_MID,
		                                       VFX_FRAME_ALIGNER_MODE_MID,
		                                       VFX_FRAME_ALIGNER_MODE_MID);
		    }
		    m_messageFrame->setHidden(VFX_FALSE);
		    m_messageFrame->setString(VFX_WSTR_RES(STR_GLOBAL_NO_MEMORY_CARD));
		    m_messageFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
		    m_messageFrame->bringToFront();

	    }
		else
		{

			VcpListMenu* m_localAudioList;
		    VFX_OBJ_CREATE(m_localAudioList, VcpListMenu, this);
		    m_localAudioList->setPos(0,0);
		    m_localAudioList->setSize(getSize());
		    m_localAudioList->setAlignParent(
		                VFX_FRAME_ALIGNER_MODE_SIDE,
		                VFX_FRAME_ALIGNER_MODE_SIDE,
		                VFX_FRAME_ALIGNER_MODE_SIDE,
		                VFX_FRAME_ALIGNER_MODE_SIDE);
			m_localAudioList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT);
			//m_localAudioList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON, VFX_FALSE);
		    m_localAudioList->setItemHeight(VCP_LIST_MENU_CELL_HEIGHT_MULTI_LINE);
			m_localAudioList->setContentProvider(this);
			m_localAudioList->m_signalItemTapped.connect(this, &VappLemeiLocalAudioPage::onItemShortTapped);
		}
	}	
}

VfxBool VappLemeiLocalAudioPage::getItemText(VfxU32 index,                    
									    VcpListMenuFieldEnum fieldType,  
									    VfxWString &text,                
									    VcpListMenuTextColorEnum &color)
{
	switch(index)
	{
		case 0:
			text = VFX_WSTR_RES(STR_ID_VAPP_FMGR_MYMUSIC);
			break;
		case 1:
			text = VFX_WSTR_RES(STR_ID_VAPP_FMGR_MYRECORD);
			break;
		case 2:
			text = VFX_WSTR_RES(STR_ID_VAPP_FMGR_MYRINGTONE);
			break;
		default:
			text = VFX_WSTR("");
			break;
	}
	return VFX_TRUE;
}

VfxBool VappLemeiLocalAudioPage::getItemImage(
        VfxU32 index,                    // [IN] the index of item
        VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
        VfxImageSrc &image               // [OUT] the image resource
        )
{
	image.setResId(IMG_ID_VAPP_FMGR_TYPE_DEF_FOLDER);
	return VFX_TRUE;
}


VfxU32 VappLemeiLocalAudioPage::getCount()const
{
	return 3;
}

void VappLemeiLocalAudioPage::onItemShortTapped(VcpListMenu *list, VfxU32 index)
{
	FMGR_FILTER filter;
	mmi_id cui_id;
	U16 file_path[SRV_FMGR_PATH_MAX_LEN];
	S8 drv_type = SRV_FMGR_PUBLIC_DRV;
	U16 folder_name[30];
	

	memset(file_path, 0, sizeof(file_path));
	memset(folder_name, 0, sizeof(folder_name));
	setAudioFilter(&filter);


	if (m_Id == 1)
	{
		drv_type = SRV_FMGR_PUBLIC_DRV;
	}
	else if (m_Id == 2)
	{
		drv_type = SRV_FMGR_CARD_DRV;
	}

	switch (index)
	{
		case 0:
			mmi_ucs2cpy((CHAR*)folder_name, (CHAR *)AUDIO_DOWNLOAD_FOLDER_NAME);
   
			break;
			
		case 1:
			mmi_ucs2cpy((CHAR*)folder_name, (CHAR *)RECORD_DOWNLOAD_FOLDER_NAME);
			break;
			
		case 2:
			mmi_ucs2cpy((CHAR*)folder_name, (CHAR *)RINGTONE_DOWNLOAD_FOLDER_NAME);
			break;
			
		default:
			mmi_ucs2cpy((CHAR*)folder_name, (CHAR *)AUDIO_DOWNLOAD_FOLDER_NAME);
			break;
	}
    init_audio_folder(file_path, drv_type, folder_name);
	cui_id = vcui_file_selector_create(getApp()->getGroupId(), (WCHAR*)file_path, &filter,
											VCUI_FILE_SELECTOR_STYLE_FILE_ONLY, CUI_FILE_SELECTOR_OPT_ARCHIVE_AS_FILE);
	if (cui_id)
	{
		vfxSetCuiCallerScr(cui_id, getMainScr());
		vcui_file_selector_run(cui_id);
	}
}

void VappLemeiLocalAudioPage::setAudioFilter(FMGR_FILTER *filter)
{
	FMGR_FILTER_INIT(filter);
	FMGR_FILTER_SET(filter, FMGR_TYPE_IMY);
	FMGR_FILTER_SET(filter, FMGR_TYPE_MID);
	FMGR_FILTER_SET(filter, FMGR_TYPE_MIDI);
	FMGR_FILTER_SET(filter, FMGR_TYPE_WAV);
	FMGR_FILTER_SET(filter, FMGR_TYPE_AMR);
    // FMGR_FILTER_SET(filter, FMGR_TYPE_VM);   /* cannot get duration */
#ifdef AAC_DECODE
	FMGR_FILTER_SET(filter, FMGR_TYPE_AAC);
#endif 
#ifdef DAF_DECODE
	FMGR_FILTER_SET(filter, FMGR_TYPE_DAF);
#endif 
    
#ifdef  __RM_DEC_SUPPORT__
	FMGR_FILTER_SET(filter, FMGR_TYPE_RA); 
#endif
#ifdef AMRWB_DECODE
	FMGR_FILTER_SET(filter, FMGR_TYPE_AWB);
#endif 
#ifndef __CPU_ARM7TDMI__ /* MT6205B */
	FMGR_FILTER_SET(filter, FMGR_TYPE_AIF);
	FMGR_FILTER_SET(filter, FMGR_TYPE_AIFF);
	FMGR_FILTER_SET(filter, FMGR_TYPE_AIFC);
	FMGR_FILTER_SET(filter, FMGR_TYPE_AU);
	FMGR_FILTER_SET(filter, FMGR_TYPE_SND);
#endif /* __CPU_ARM7TDMI__ *//* MT6205B */ 
#if defined(M4A_DECODE)
	FMGR_FILTER_SET(filter, FMGR_TYPE_M4A);
#endif 
#if defined(EXT_AUDIO_CHIP) || defined(MMF_DECODE)
	FMGR_FILTER_SET(filter, FMGR_TYPE_MMF);
#endif 
#ifdef WMA_DECODE
	FMGR_FILTER_SET(filter, FMGR_TYPE_WMA);
#endif 
#ifdef MUSICAM_DECODE
	FMGR_FILTER_SET(filter, FMGR_TYPE_MP2);
#endif 

#if !defined (MP4_DECODE) && defined(__MMI_PURE_AUDIO__)
	FMGR_FILTER_SET(filter, FMGR_TYPE_3GP);
	FMGR_FILTER_SET(filter, FMGR_TYPE_MP4);
	FMGR_FILTER_SET(filter, FMGR_TYPE_3G2);
#endif
#ifdef __APE_DECODE__
	FMGR_FILTER_SET(filter, FMGR_TYPE_APE);
#endif

	FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER);
	FMGR_FILTER_SET(filter, FMGR_TYPE_FOLDER_DOT);
}

void VappLemeiLocalAudioPage::init_audio_folder(U16* file_path, S8 drv_type, U16* folder_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_HANDLE file_handle;
    S8 drv[4];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(drv, "%c:\\", (S8) drv_type);
    mmi_asc_to_ucs2((S8*) file_path, drv);
    mmi_ucs2cat((S8*) file_path, (const S8*)folder_name);

    file_handle = FS_Open(file_path, FS_OPEN_DIR | FS_READ_ONLY);

    if (file_handle < 0)
    {
	    if (FS_CreateDir(file_path) < 0)
		{
			return;
		}
    }
    else
    {
        FS_Close(file_handle);
    }
    return;
}

#endif
