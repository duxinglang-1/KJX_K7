/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   vapp_tone_selector_cui.cpp
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Tone Selector CUI file
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifdef __cplusplus
extern "C"
{
#endif
#include "MMI_features.h"
#include "ProfilesSrv.h" 
#include "mdi_audio.h"
#include "Mmi_rp_srv_venus_component_tool_bar_def.h"
#include "mmi_rp_srv_venus_component_list_menu_def.h"
#include "mmi_rp_vcui_tone_selector_def.h"
#include "mmi_rp_app_usbsrv_def.h"
#include "mmi_rp_vapp_vol_dialog_def.h"
#include "mmi_rp_srv_prof_def.h"
#include "USBSrvGprot.h"
#include "Filemgrcuigprot.h"
#include "GlobalConstants.h"
#include "UcmSrvGprot.h"
#include "FileMgrType.h"
#include "Wgui_categories_util.h"
#ifdef __cplusplus
}
#endif

#include "vapp_vol_dialog_gprot.h"
#include "vapp_fmgr_cui_gprot.h"
#include "vcui_tone_selector.h"
#include "Vapp_usb_gprot.h"

#ifdef __cplusplus
extern "C"
{
#endif

mmi_id vcui_tone_selector_create(mmi_id parent_id)
{
#ifdef __MMI_USB_SUPPORT__
    if(srv_usb_is_in_mass_storage_mode())
    {
        vapp_usb_unavailable_popup(0);
        return GRP_ID_INVALID;
    }
#endif
    mmi_id cui_id = VfxAppLauncher::createCui(VCUI_TONE_SELECTOR,VFX_OBJ_CLASS_INFO(VappToneSelector),parent_id);

    VappToneSelector *cui = (VappToneSelector *)VfxApp::getObject(cui_id);

    cui->m_cuiId = cui_id;

    return cui_id;
}

VfxS32 vcui_tone_selector_run(mmi_id cui_id)
{
    VappToneSelector *cui = (VappToneSelector *)VfxApp::getObject(cui_id);
    VfxBool hit = VFX_FALSE;
    VfxU8 cur_end = 0;
    if(VCUI_TONE_SELECTOR_FILTER_IS_SET(cui->m_filter,VCUI_TONE_SELECTOR_FILTER_FILE))
    {
        //File
        cui->m_fileNum = 1 ;
        cui->m_fileBegin = 0;
        cui->m_fileEnd = cui->m_fileBegin + cui->m_fileNum;
        cur_end = cui->m_fileEnd;

        if(cui->m_audioId == 0)
        {
            hit = VFX_TRUE;
        }
    }
    if(VCUI_TONE_SELECTOR_FILTER_IS_SET(cui->m_filter,VCUI_TONE_SELECTOR_FILTER_TONE))
    {
        //Tone
        cui->m_toneNum = (VfxU32)srv_prof_get_num_of_audio_resource(SRV_PROF_AUDIO_RES_TONE);
        cui->m_toneBegin = cur_end;
        cui->m_toneEnd = cui->m_toneBegin + cui->m_toneNum;
        cur_end = cui->m_toneEnd;

        VfxS32 start = (VfxS32)srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_TONE,0);
        VfxS32 end = start + cui->m_toneNum -1 ;

        if(cui->m_audioId >= start && cui->m_audioId <= end)
        {
            hit = VFX_TRUE;
        }
    }
    if(VCUI_TONE_SELECTOR_FILTER_IS_SET(cui->m_filter,VCUI_TONE_SELECTOR_FILTER_RING))
    {
        //Ring
        cui->m_ringNum = (VfxU32)srv_prof_get_num_of_audio_resource(SRV_PROF_AUDIO_RES_RING);
        cui->m_ringBegin = cur_end;
        cui->m_ringEnd = cui->m_ringBegin + cui->m_ringNum;

        VfxS32 start = (VfxS32)srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_RING,0);
        VfxS32 end = start + cui->m_ringNum -1 ;

        if(cui->m_audioId >= start && cui->m_audioId <= end)
        {
            hit = VFX_TRUE;
        }
    }

    if(!hit)
    {
        if(cui->m_toneNum != 0)
        {
            cui->m_audioId = (VfxS32)srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_TONE,0);
        }
        else if(cui->m_ringNum != 0)
        {
            cui->m_audioId = (VfxS32)srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_RING,0);
        }
        else
        {
            //only file, shall use filemgr cui
            VFX_ASSERT(0);
        }
    }

    VfxAppLauncher::runCui(cui_id);
	return 0;
}

VfxS32 vcui_tone_selector_set_title_id(mmi_id cui_id, VfxResId str_id, VfxResId img_id)
{
    VappToneSelector *cui = (VappToneSelector *)VfxApp::getObject(cui_id);
    cui->m_strId = str_id;
	return 0;
}

//set tone_id to 0 for file, if there is no file, the first one will be chosen
VfxS32 vcui_tone_selector_set_hightlight_tone(mmi_id cui_id, VfxS32 tone_id)
{
    VappToneSelector *cui = (VappToneSelector *)VfxApp::getObject(cui_id);
    cui->m_audioId = tone_id;
	return 0;
}

mmi_ret vcui_tone_selector_get_selected_filepath(mmi_id cui_id, srv_fmgr_fileinfo_struct *info, VfxWChar* path_buffer, VfxS32 path_size)
{
    VappToneSelector *cui = (VappToneSelector *)VfxApp::getObject(cui_id);

    mmi_ret result = MMI_RET_OK;

    if(!cui)
    {
        return MMI_RET_ERR;
    }

    if (cui->m_fsCuiId != GRP_ID_INVALID)
    {
        result = vcui_file_selector_get_selected_filepath(cui->m_fsCuiId, info, path_buffer, path_size);
    }
    else
    {
        result = MMI_RET_ERR;
    }

    return result;

}

mmi_ret vcui_tone_selector_set_filter(mmi_id cui_id, VfxU16 filter)
{
    VappToneSelector *cui = (VappToneSelector *)VfxApp::getObject(cui_id);

    if(!cui)
    {
        return MMI_RET_ERR;
    }

    cui->m_filter = filter;
    return MMI_RET_OK;

}

mmi_ret vcui_tone_selector_set_user_data(mmi_id cui_id, void *data)
{
    VappToneSelector* cui = (VappToneSelector *)VfxApp::getObject(cui_id);

    if(!cui)
    {
        return MMI_RET_ERR;
    }

    cui->m_userData = data;
    return MMI_RET_OK;

}

void* vcui_tone_selector_get_user_data (mmi_id cui_id)
{
    VappToneSelector* cui = (VappToneSelector *)VfxApp::getObject(cui_id);

    if(!cui)
    {
        return NULL;
    }

    return cui->m_userData;
}

void vcui_tone_selector_close(mmi_id cui_id)
{
    VfxAppLauncher::terminate(cui_id);
}
#ifdef __cplusplus
}
#endif

/////////////////////////////////////////////////////////////////////////////////

VFX_IMPLEMENT_CLASS("VappToneSelector", VappToneSelector, VfxCui);

VappToneSelector::VappToneSelector():
    m_toneNum(0),
    m_toneBegin(0),
    m_toneEnd(0),
    m_ringNum(0),
    m_ringBegin(0),
    m_ringEnd(0),
    m_fileNum(0),
    m_fileBegin(0),
    m_fileEnd(0),
    m_filter(VCUI_TONE_SELECTOR_FILTER_TONE),
    m_audioId(0),
    m_previewId(0),
    m_previewIndex(-1),
    m_strId(0),
    m_userData(NULL),
    m_cuiId(GRP_ID_INVALID),
    m_fsCuiId(GRP_ID_INVALID),
    m_mainpage(NULL)
{
    return;
}

void VappToneSelector::onInit(void)
{
    VfxApp::onInit();
	
#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_TRUE);
#endif

	registerCBEvent(EVT_ID_SRV_PROF_PROFILE_SWITCHED, VFX_TRUE);

}

void VappToneSelector::onDeinit(void)
{
#ifdef __MMI_USB_SUPPORT__
    registerCBEvent(EVT_ID_USB_ENTER_MS_MODE, VFX_FALSE);
#endif

    registerCBEvent(EVT_ID_SRV_PROF_PROFILE_SWITCHED, VFX_FALSE);

	VfxApp::onDeinit();
}

void VappToneSelector::onRun(void * args, VfxU32 argSize)
{
    VfxCui::onRun(args, argSize);

    // create and display main screen
    VappToneSelectorScreen *scr;
    VFX_OBJ_CREATE(scr, VappToneSelectorScreen, this);
    scr->show();
}

mmi_ret VappToneSelector::onProc(mmi_event_struct* evt)
{
    VfxApp::onProc(evt);

    switch(evt->evt_id)
    {
        case EVT_ID_VCUI_FILE_SELECTOR_RESULT:
        {
            vcui_file_selector_result_event_struct * evt_fs = (vcui_file_selector_result_event_struct *)evt;

            VFX_ASSERT(m_fsCuiId == evt_fs->sender_id);

            if (evt_fs->result > 0)
            {
                /*user selected a file*/
                fileSelected();
            }
            else
            {   /*user cancel or FS error*/
                vcui_file_selector_close(m_fsCuiId);
            }
            break;
        }
	#ifdef __MMI_USB_SUPPORT__
        case EVT_ID_USB_ENTER_MS_MODE:
        {
            this->exit();
            break;
        }
	#endif

		case EVT_ID_SRV_PROF_PROFILE_SWITCHED:
		{
			if(m_previewId != 0)
			{
				m_mainpage->previewToneStop();
			
				VfxS32 previewIndex = m_previewIndex;
				m_previewIndex = -1;
				m_previewId = 0;
				m_mainpage->m_toneList->updateItem(previewIndex);
			}

			break;
		}
		
        case EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE:
        {
            vapp_vol_dialog_evt_struct *volEvent = (vapp_vol_dialog_evt_struct*) evt;

            if (volEvent->type == VAPP_VOL_DIALOG_IS_MEDIA)
            {
                return !MMI_RET_OK;
            }
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}

void VappToneSelector::onGroupTopActive(void)
{
    registerCBEvent(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, VFX_TRUE);
}

void VappToneSelector::onGroupTopInactive(void)
{
    registerCBEvent(EVT_ID_VOL_DIALOG_CHECK_VOL_TYPE, VFX_FALSE);
}


VfxS8 VappToneSelector::countIndex(void)
{
    VfxU16 offset;

    srv_prof_audio_resource_type_enum type_srv = srv_prof_get_audio_info_from_audio_resourece((srv_prof_audio_id)m_audioId, (U16*)&offset);

    switch(type_srv)
    {
        case SRV_PROF_AUDIO_RES_NONE:
        {
            // set as file
            if(m_audioId == 0)
            {
                return 0;
            }
            break;
        }

        case SRV_PROF_AUDIO_RES_TONE:
        {
            if(m_toneNum == 0)
            {
                return -1;
            }

            return m_toneBegin + offset;
        }

        case SRV_PROF_AUDIO_RES_RING:
        {
            if(m_ringNum == 0)
            {
                return -1;
            }
            
            return m_ringBegin + offset;
        }

        default:
            return -1 ;

    }

	return -1 ;

}

void VappToneSelector::fileSelected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VfxChar filepath[SRV_FMGR_PATH_BUFFER_SIZE];
    srv_fmgr_fileinfo_struct fileinfo;
    VfxU8 mdi_type = MDI_FORMAT_SMF;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vcui_file_selector_get_selected_filepath(m_fsCuiId, &fileinfo, (WCHAR*)&filepath, SRV_FMGR_PATH_BUFFER_SIZE);

    if(fileinfo.type == FMGR_TYPE_IMY || fileinfo.type == FMGR_TYPE_MIDI || fileinfo.type == FMGR_TYPE_MID)
    {
        if(fileinfo.type == FMGR_TYPE_IMY)
        {
            mdi_type = MDI_FORMAT_IMELODY;
        }

        if (fileinfo.size > mdi_audio_get_size_limit(mdi_type))
        {
            VfxWString info;
            info.loadFromRes(STR_ID_VCUI_TONE_SELECTOR_FILE_TOO_LARGE);
            mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
            return;
        }
    }

    if (((VfxWChar*)filepath)[0] != 0)
    {
        /*post result to parent*/
        postResultToParent(VFX_FALSE);
        exitRequest();
    }
}


void VappToneSelector::postResultToParent(VfxBool is_default_sound)
{
    vcui_tone_selector_evt_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_TONE_SELECTOR_RESULT, m_cuiId);

    evt.is_default_sound = is_default_sound;

    if (is_default_sound == MMI_TRUE)
    {
        evt.selected_tone = m_audioId;
    }
    else
    {
        evt.selected_tone = 0;
    }

    postToCaller((mmi_group_event_struct*)&evt);

}


void VappToneSelector::exitRequest(void)
{
    mmi_group_event_struct evt;
    MMI_FRM_INIT_GROUP_EVENT(&evt, EVT_ID_VCUI_TONE_SELECTOR_CLOSE_REQUEST, m_cuiId);
    postToCaller((mmi_group_event_struct*)&evt);
}

/////////////////////////////////////////////////////////////////////////////////

VFX_IMPLEMENT_CLASS("VappToneSelectorScreen", VappToneSelectorScreen, VfxMainScr);

void VappToneSelectorScreen::on1stReady()
{
    VfxMainScr::on1stReady();

    VappToneSelectorPage *page;

    VFX_OBJ_CREATE(page, VappToneSelectorPage, this);
    pushPage(0,page);

    VappToneSelector *cui = (VappToneSelector *)getApp();

	cui->m_mainpage = page;
}

/////////////////////////////////////////////////////////////////////////////////

VFX_IMPLEMENT_CLASS("VappToneSelectorPage", VappToneSelectorPage, VfxPage);

void VappToneSelectorPage::onInit(void)
{
    VfxPage::onInit();

    m_cui = (VappToneSelector *)getApp();

    //Draw Page
    drawPage();
    m_toneList->setVisibleMenuItem(m_cui->countIndex());
}

void VappToneSelectorPage::onExit(VfxBool isBackward)
{
    if(m_cui->m_previewId != 0)
    {
        previewToneStop();

        VfxS32 previewIndex = m_cui->m_previewIndex;
        m_cui->m_previewIndex = -1;
        m_toneList->updateItem(previewIndex);
    }

//    mdi_audio_resume_background_play();
}

void VappToneSelectorPage::onBack(void)
{
    m_cui->exitRequest();
}

VfxU32 VappToneSelectorPage::getCount(void) const
{
    return m_cui->m_toneNum + m_cui->m_ringNum + m_cui->m_fileNum ;
}

VappToneSelectorPage::VappToneSelectorResTypeEnum VappToneSelectorPage::indexMapping(VfxU32 index, VfxU32 &offset) const
{
    if(index >= m_cui->m_fileBegin && index < m_cui->m_fileEnd)
    {
        //file
        offset = 0;
        return AUDIO_RES_FILE;
    }
    else if (index >= m_cui->m_toneBegin && index < m_cui->m_toneEnd)
    {
        //tone
        offset = index - m_cui->m_toneBegin ;
        return AUDIO_RES_TONE;
    }
    else if (index >= m_cui->m_ringBegin && index < m_cui->m_ringEnd)
    {
        //ring        
        offset = index - m_cui->m_ringBegin ;
        return AUDIO_RES_RING;
    }

    //shall not happen
    offset = 0;
    return AUDIO_RES_FILE;
    
}

VfxBool VappToneSelectorPage::getItemImage(VfxU32 index,                    // [IN] the index of item
                                           VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                                           VfxImageSrc &image               // [OUT] the image resource
                                           ) 
{
    switch(fieldType)
    {
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL:
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED:
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT:
        {
            if(index == m_cui->m_previewIndex)
            {
                image.setResId(IMG_ID_VCUI_TONE_SELECTOR_STOP_N);
            }
            else
            {
	        image.setResId(IMG_ID_VCUI_TONE_SELECTOR_PLAY_N);
            }
            return VFX_TRUE;
        }
            
        case VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED:
        {
            if(index == m_cui->m_previewIndex)
            {
                image.setResId(IMG_ID_VCUI_TONE_SELECTOR_STOP_P);
            }
            else
            {
                image.setResId(IMG_ID_VCUI_TONE_SELECTOR_PLAY_P);
             }
            return VFX_TRUE;
        }

        case VCP_LIST_MENU_FIELD_DISCLOSURE_IMG:
        {
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
            return VFX_TRUE;
        }

        default:
            return VFX_FALSE;

    }

}

VcpListMenuCellBaseControl* VappToneSelectorPage::getItemCustomControl(VfxU32 index,                                    // [IN] index of the item
                                                                       VcpListMenuCellControlLocationTypeEnum location, // [IN] Control location
                                                                       VfxFrame *parentFrame                            // [IN] parent frame of the custom content frame
                                                                       )
{
    if(index == 0 && m_cui->m_fileNum == 1 && location == VCP_LIST_MENU_CELL_CONTROL_LOCATION_TYPE_TAIL)
    {
        VcpListMenuDisclosure* disclosure = NULL;
        VfxImageSrc image;
        image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
        VFX_OBJ_CREATE_EX(disclosure, VcpListMenuDisclosure, parentFrame,(image));

        return disclosure;
    }

    return NULL;
}


VfxBool VappToneSelectorPage::getItemText(VfxU32 index,                    // [IN] the index of item
                                          VcpListMenuFieldEnum fieldType,  // [IN] the type of the field in the cell
                                          VfxWString &text,                // [OUT] the text resource
                                          VcpListMenuTextColorEnum &color  // [OUT] the text color
                                          )
{
    if(fieldType != VCP_LIST_MENU_FIELD_TEXT)
    {
        return VFX_FALSE;
    }

    VfxU32 offset;
    VappToneSelectorResTypeEnum type = indexMapping(index, offset);

    switch(type)
    {
        case AUDIO_RES_FILE:
        {
            text.loadFromRes(STR_ID_VCUI_TONE_SELECTOR_FROM_FILE);
            break;
        }

        case AUDIO_RES_TONE:
        {
            VfxResId id = (VfxResId)srv_prof_get_string_id_from_audio_resourece(SRV_PROF_AUDIO_RES_TONE, offset);
            text.loadFromRes(id);
            break;
        }

        case AUDIO_RES_RING:
        {
            VfxResId id = (VfxResId)srv_prof_get_string_id_from_audio_resourece(SRV_PROF_AUDIO_RES_RING, offset);
            text.loadFromRes(id);            
            break;
        }

        default:
            break;

    }

     return VFX_TRUE;
}


VcpListMenuItemStateEnum VappToneSelectorPage::getItemState(VfxU32 index) const   // [IN] index of the item
{
        VfxU32 offset1;
        VfxU16 offset2;
        VappToneSelectorResTypeEnum type_cui = indexMapping(index, offset1);

        srv_prof_audio_resource_type_enum type_srv = srv_prof_get_audio_info_from_audio_resourece((srv_prof_audio_id)m_cui->m_audioId, (U16*)&offset2);

        switch(type_cui)
        {
            case AUDIO_RES_FILE:
            {
                if(m_cui->m_audioId == 0)
                {
                    return VCP_LIST_MENU_ITEM_STATE_SELECTED;
                }
                break;
            }

            case AUDIO_RES_TONE:
            {
                if(type_srv == SRV_PROF_AUDIO_RES_TONE && offset1 == offset2)
                {
                    return VCP_LIST_MENU_ITEM_STATE_SELECTED;
                }
                break;
            }

            case AUDIO_RES_RING:
            {
                if(type_srv == SRV_PROF_AUDIO_RES_RING && offset1 == offset2)
                {
                    return VCP_LIST_MENU_ITEM_STATE_SELECTED;
                }                
                break;
            }
        }

        return VCP_LIST_MENU_ITEM_STATE_NONE;
}

void VappToneSelectorPage::previewTonePlayCallback(mdi_result result, void *user_data)
{
    VappToneSelectorPage* ptr = (VappToneSelectorPage*)handleToObject((VfxObjHandle)user_data);

    if(ptr == NULL)
    {
        return;
    }

    VfxS32 previewIndex = ptr->m_cui->m_previewIndex;
    ptr->m_toneList->updateItem(previewIndex);
    ptr->m_cui->m_previewIndex = -1;
    ptr->m_cui->m_previewId = 0; 
}


VfxBool VappToneSelectorPage::previewTonePlay(VfxU32 index)
{
    if (srv_ucm_is_any_call())
    {
        VfxWString info;
        info = VFX_WSTR_RES(STR_GLOBAL_CURRENTLY_NOT_AVAILABLE_IN_CALL);            
        mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)info.getBuf());
        return VFX_FALSE;
    }

    VfxU32 offset;
    VappToneSelectorResTypeEnum type = indexMapping(index, offset);

    switch(type)
    { 
        case AUDIO_RES_FILE:
        {
            m_cui->m_previewId = 0;
            return VFX_FALSE;
        }

        case AUDIO_RES_TONE:
        {
            m_cui->m_previewId = (VfxS32)srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_TONE,offset);
            break;
        }

        case AUDIO_RES_RING:
        {
            m_cui->m_previewId = (VfxS32)srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_RING,offset);            
            break;
        }

    }

    U8          audio_type;
    U32         audio_len;
    U8 *        audio_data;
    mdi_result  result;

    audio_data = get_audio((MMI_ID_TYPE)m_cui->m_previewId, &audio_type, &audio_len);

    if (audio_data != NULL)
    {
        result = mdi_audio_play_string_with_vol_path(
                    (void*)audio_data,
                    audio_len,
                    audio_type,
                    DEVICE_AUDIO_PLAY_INFINITE,
                    &VappToneSelectorPage::previewTonePlayCallback,
                    getObjHandle(),
                    srv_prof_get_media_vol(),
                    MDI_DEVICE_SPEAKER2);

        if (result == MDI_AUDIO_SUCCESS)
        {
        	return VFX_TRUE;
        }
		else
        {
        	VfxU16 string_id;
        	mmi_event_notify_enum event_type;
        	string_id = mdi_audio_get_error_info(result, &event_type);
        	mmi_frm_nmgr_balloon(MMI_SCENARIO_ID_DEFAULT, MMI_EVENT_INFO_BALLOON, MMI_NMGR_BALLOON_TYPE_INFO, (WCHAR*)GetString(string_id));
        	return VFX_FALSE;
        }
    }

    m_cui->m_previewId = 0;
    return VFX_FALSE;

}

void VappToneSelectorPage::previewToneStop(void)
{
    if(m_cui->m_previewId != 0)
    {
        mdi_audio_stop_string();
        m_cui->m_previewId = 0;
    }
}

void VappToneSelectorPage::enterFileSelector(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_id fs_gid;
    FMGR_FILTER filter;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter,FMGR_TYPE_FOLDER);
    srv_fmgr_types_filter_set_group(&filter, FMGR_GROUP_AUDIO);
#ifdef __RM_DEC_SUPPORT__
    FMGR_FILTER_CLEAR(&filter,FMGR_TYPE_RA);
#endif


    fs_gid = vcui_file_selector_create(m_cui->m_cuiId, 
                                      (WCHAR*) L"root", 
                                      &filter, 
                                      VCUI_FILE_SELECTOR_STYLE_FILE_ONLY, 
                                      VCUI_FILE_SELECTOR_OPT_AUDIO_PREVIEW_ON | VCUI_FILE_SELECTOR_OPT_FIXED_PATH_ON | VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);

    if (fs_gid != GRP_ID_INVALID)
    {  
        vcui_file_selector_run(fs_gid);
        m_cui->m_fsCuiId = fs_gid;
    }

}

void VappToneSelectorPage::onItemTapped(VcpListMenu *menu, VfxU32 index)
{
    VfxU32 offset;
    VappToneSelectorResTypeEnum type = indexMapping(index, offset);

    switch(type)
    { 
        case AUDIO_RES_FILE:
        {
            if(m_cui->m_previewId != 0)
            {
                previewToneStop();
                VfxS32 previewIndex = m_cui->m_previewIndex;
                m_cui->m_previewIndex = -1;

                menu->updateItem(previewIndex);
            }
            enterFileSelector();
            break;
        }
        case AUDIO_RES_TONE:
        {
            m_cui->m_audioId = (VfxS32)srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_TONE,offset);
            m_cui->postResultToParent(VFX_TRUE);
            m_cui->exitRequest();
            break;
        }
        case AUDIO_RES_RING:
        {
            m_cui->m_audioId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_RING,offset);
            m_cui->postResultToParent(VFX_TRUE);
            m_cui->exitRequest();
            break;
        }

        default:
            break;
    }

}


void VappToneSelectorPage::onItemSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        VfxU32 offset;
        VappToneSelectorResTypeEnum type = indexMapping(index, offset);

        switch(type)
        { 
            case AUDIO_RES_FILE:
            {
                if(m_cui->m_previewId != 0)
                {
                    previewToneStop();
                    VfxS32 previewIndex = m_cui->m_previewIndex;
                    m_cui->m_previewIndex = -1;

                    menu->updateItem(previewIndex);
                }
                enterFileSelector();
                break;
            }
            case AUDIO_RES_TONE:
            {
                m_cui->m_audioId = (VfxS32)srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_TONE,offset);
                m_cui->postResultToParent(VFX_TRUE);
                m_cui->exitRequest();
                break;
            }
            case AUDIO_RES_RING:
            {
                m_cui->m_audioId = srv_prof_get_audio_id_from_audio_resourece(SRV_PROF_AUDIO_RES_RING,offset);
                m_cui->postResultToParent(VFX_TRUE);
                m_cui->exitRequest();
                break;
            }

            default:
                break;
        }

    }

}

void VappToneSelectorPage::onCmdButtonClicked(VcpListMenu *menu, VfxU32 index)
{
    //stop preivous preview
    if(m_cui->m_previewId != 0)
    {
        VfxS32 previewIndex = m_cui->m_previewIndex;
        previewToneStop();
        m_cui->m_previewIndex = -1;

        menu->updateItem(previewIndex);

        if(index == previewIndex)
        {
            //same item, stop only
            return;
        }
    }

    //start current preview
    VfxBool result = previewTonePlay(index);

    if(result == VFX_TRUE)
    {
        m_cui->m_previewIndex = index;
        menu->updateItem(index);
    }
}

void VappToneSelectorPage::onButtonTap(VfxObject* obj, VfxId id)
{
    switch(id)
    {
        case BUTTON_SAVE:
        {
//            m_cui->postResultToParent(VFX_TRUE);
//            m_cui->exitRequest();
            break;
        }

        case BUTTON_CANCEL:
        {
            m_cui->exitRequest();
            break;
        }

        default:
            break;
    }

}

void VappToneSelectorPage::drawPage(void)
{
    VappToneSelector *cui = (VappToneSelector *)getApp();

    VcpTitleBar *tBar;
    VFX_OBJ_CREATE(tBar, VcpTitleBar, this);

    tBar->setTitle(VFX_WSTR_RES(cui->m_strId));
    setTopBar(tBar);

    //VcpListMenu * toneList;
    VFX_OBJ_CREATE(m_toneList, VcpListMenu, this);
    m_toneList->setSize(getSize());
    m_toneList->setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
    m_toneList->setMenuMode(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK,VFX_FALSE);
    m_toneList->setMenuControlMode(VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON,VFX_FALSE);
//    m_toneList->m_signalItemSelectionStateChanged.connect(this,&VappToneSelectorPage::onItemSelectionChanged);
    m_toneList->m_signalItemTapped.connect(this,&VappToneSelectorPage::onItemTapped);
    m_toneList->m_signalCmdButtonClicked.connect(this,&VappToneSelectorPage::onCmdButtonClicked);
    m_toneList->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE,VFX_FRAME_ALIGNER_MODE_SIDE);
    m_toneList->setContentProvider(this);

}

