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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  Vapp_sat_view.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements  SAT View Class.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 
/***************************************************************************** 
 * Include
 *****************************************************************************/

#ifdef __cplusplus
extern "C"{
#endif
 
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "ProfilesSrvGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "GpioSrvGprot.h"
#include "ImeGprot.h"
#include "gui.h"
#include "mmi_rp_app_charger_def.h"
#include "mmi_frm_queue_gprot.h"
#include "FileMgrSrvGProt.h"
#include "PhoneSetupGprots.h"
#include "GlobalResDef.h"
#include "GeneralSettingSrvGprot.h"
#include "CustDataRes.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "SatSrvGprot.h"
#include "SatCoreProt.h"
 
#ifdef BROWSER_SUPPORT
#include "Browser_api.h"
#endif /* BROWSER_SUPPORT */
 
#ifdef __cplusplus
}
#endif
 
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vfx_cpp_base.h"
#include "vfx_class_info.h"
#include "vfx_page_bar.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vcp_popup_data_type.h"
#include "vcp_global_popup.h"
#include "Vapp_nmgr_gprot.h"

#include "vapp_sat_base.h"
#include "vapp_sat_view.h"
#include "mmi_rp_vapp_sat_def.h"
#include "vadp_app_trc.h"
#include "vadp_app_trc_gen.h"
#include "mmi_rp_app_cosmos_global_def.h"


/***************************************************************************** 
 * Class VappSatViewPage
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappSatViewPage", VappSatViewPage, VappSatBasePage);
#if 0
/* under construction !*/
/* under construction !*/
#ifndef __SAT_DISABLE_ICON_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VappSatViewPage::VappSatViewPage(srv_sat_proactive_sim_struct *cmdInfo) :
    VappSatBasePage(cmdInfo),
    m_text(VFX_WSTR_NULL),
#ifndef __SAT_DISABLE_ICON_SUPPORT__    
    m_icon(VFX_IMAGE_SRC_NULL),
    m_imageFrame(NULL),
#endif
    m_textFrame(NULL)
{
}


VappSatViewPage::~VappSatViewPage()
{
}


void VappSatViewPage::onInit()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_VIEW_PAGE_ONINIT);

    VappSatBasePage::onInit();
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);
#endif
    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);

    cmdParser();
    updateViewPage();
    setTitleBar();
    setToolBar();
    cmdDoWithShow();
    addCmdTimer();
}


void VappSatViewPage::onDeinit()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_VIEW_PAGE_ONDEINIT);

    cmdSessionEnd();
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    VFX_OBJ_CLOSE(m_imageFrame);
#endif
    VFX_OBJ_CLOSE(m_textFrame);

    VappSatBasePage::onDeinit();
}

void VappSatViewPage::onUpdate()
{
    VappSatBasePage::onUpdate();

    updateViewPage();
}

mmi_ret VappSatViewPage::onProc(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_DONT_CARE;

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_VIEW_PAGE_ONPROC, evt->evt_id);

    switch (evt->evt_id)
    {
        case EVT_ID_SRV_SAT_PROACTIVE_SIM:
        {
            srv_sat_proactive_sim_event_struct *event = (srv_sat_proactive_sim_event_struct *)evt;

            if (isDontCareCmd(event->proactive_sim))
            {
                ret = MMI_RET_DONT_CARE;
                break;
            }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_VIEW_PAGE_EXIT);
            deleteCmdTimer();
            exit();

            break;
        }

        case EVT_ID_SRV_SAT_SESSION_END:
        {
            srv_sat_session_end_event_struct *event = (srv_sat_session_end_event_struct *)evt;
            if (event->sim_id != getSimId())
            {
                ret = MMI_RET_DONT_CARE;
                break;
            }

            if (getCmdType() == SRV_SAT_CMD_DISPLAY_TEXT)
            {
                srv_sat_display_text_struct *dis = (srv_sat_display_text_struct *)getCmdData();
                if (dis->immediate_res)
                {
                    break;
                }
            }

            getMainScr()->popPage();
            break;
        }

        default:
            break;
    }

    VappSatBasePage::onProc(evt);

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_VIEW_PAGE_ONPROC_RET, ret);

    return ret;
}

VfxBool VappSatViewPage::onResponse(VappSatToolbarTypeEnum btnId)
{
    VfxBool ret = VFX_FALSE;

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_VIEW_PAGE_ONRESPONSE, (VfxU32)getSimId(), (VfxU32)getCmdType(), (VfxU32)btnId);

    switch (getCmdType())
    {
        case SRV_SAT_CMD_DISPLAY_TEXT:
        {
            ret = mmi_sat_display_text_response(getSimId(), convertBtnIdToRspId(btnId)) ? VFX_TRUE : VFX_FALSE;
            break;
        }

        case SRV_SAT_CMD_GET_INKEY:
        {
            MMI_BOOL is_yes_selected = MMI_FALSE;
            if (btnId == TOOLBAR_YES)
            {
                is_yes_selected = MMI_TRUE;
            }

            ret = mmi_sat_get_inkey_response(getSimId(), convertBtnIdToRspId(btnId), is_yes_selected, NULL);
            break;
        }

        case SRV_SAT_CMD_PLAY_TONE:
        {
            ret = mmi_sat_play_tone_response(getSimId(), convertBtnIdToRspId(btnId));
            break;

        }

        case SRV_SAT_CMD_SEND_SMS:
        case SRV_SAT_CMD_SEND_SS:
            break;

        case SRV_SAT_CMD_SEND_SS_RETURN_RESULT:
        {
            srv_sat_send_ss_struct *send_ss = (srv_sat_send_ss_struct *)getCmdData();
            ret = mmi_sat_send_ss_result_response(getSimId(), convertBtnIdToRspId(btnId), send_ss->length, send_ss->additional_info);
            break;
        }

        case SRV_SAT_CMD_SEND_USSD:
            break;

        case SRV_SAT_CMD_SEND_USSD_RETURN_RESULT:
        {
            srv_sat_send_ussd_struct *send_ussd = (srv_sat_send_ussd_struct *)getCmdData();
            ret = mmi_sat_send_ussd_result_response(getSimId(), convertBtnIdToRspId(btnId), send_ussd->length, send_ussd->additional_info);
            break;
        }

        case SRV_SAT_CMD_SETUP_CALL:
        {
            srv_ucm_result_enum error_code = SRV_UCM_RESULT_OK;
            ret = mmi_sat_setup_call_response(getSimId(), convertBtnIdToRspId(btnId), &error_code);
            if (error_code != SRV_UCM_RESULT_OK)
            {
                vapp_nmgr_global_popup_show_confirm_one_button_id(
                            MMI_SCENARIO_ID_DEFAULT,
                            VCP_POPUP_TYPE_FAILURE,
                            srv_ucm_query_error_message(error_code),
                            STR_GLOBAL_OK,
                            VCP_POPUP_BUTTON_TYPE_NORMAL,
                            NULL,
                            NULL);
            }
	#ifndef	__SAT_DISABLE_ICON_SUPPORT__
            if (btnId != TOOLBAR_OK || error_code != SRV_UCM_RESULT_OK)
            {
                vapp_sat_free_calling_icon_path(getSimId());
            }
	#endif
            break;
        }

        case SRV_SAT_CMD_SEND_DTMF:
        {
            ret = mmi_sat_send_dtmf_response(getSimId(), convertBtnIdToRspId(btnId));
            break;
        }

    #ifdef BROWSER_SUPPORT
	#ifdef __SATCC__
        case SRV_SAT_CMD_LAUNCH_BROWSER:
        {
            ret = mmi_sat_launch_browser_response(getSimId(), convertBtnIdToRspId(btnId));
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            break;
        }
	#endif	
    #endif /* BROWSER_SUPPORT */

    #ifdef __SATCE__
        case SRV_SAT_CMD_OPEN_CHANNEL:
        {
            ret = mmi_sat_open_channel_response(getSimId(), convertBtnIdToRspId(btnId));
            break;
        }

        #ifdef __SRV_SAT_TR_CLOSE_CHANNEL__
        case SRV_SAT_CMD_CLOSE_CHANNEL:
        {
            ret = mmi_sat_close_channel_response(getSimId(), convertBtnIdToRspId(btnId));
            break;
        }
        #endif

        case SRV_SAT_CMD_SEND_DATA:
        {
            ret = mmi_sat_send_data_response(getSimId(), convertBtnIdToRspId(btnId));
            break;
        }

        case SRV_SAT_CMD_RECEIVE_DATA:
        {
            ret = mmi_sat_recv_data_response(getSimId(), convertBtnIdToRspId(btnId));
            break;
        }
    #endif /* __SATCE__ */

        default:
            break;
    }

    return ret;
}

void VappSatViewPage::cmdParser()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_VIEW_PAGE_CMDPARSER, (VfxU32)getCmdType());

    switch (getCmdType())
    {
        case SRV_SAT_CMD_DISPLAY_TEXT:
        {
            srv_sat_display_text_struct * display_text = (srv_sat_display_text_struct *)getCmdData();
            m_text.loadFromMem(display_text->text_string);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(display_text->icon.data);
#endif

            if (display_text->immediate_res)
            {
                onMeResponse(this, TOOLBAR_OK);
            }

            if (display_text->clear_type == SRV_SAT_CLEAR_AFTER_SHORT_DELAY)
            {
                setTimerId(SAT_TIMER_CLEAR_DELAY);
                setTimerDuration(VAPP_SAT_DISPLAY_TEXT_DELAY_DURATION);
            }
            else
            {
                setTimerId(SAT_TIMER_NO_RESPONSE);
                setTimerDuration(VAPP_SAT_NO_RESPONSE_DURATION);
            }
            break;
        }

        case SRV_SAT_CMD_GET_INKEY:
        {
            srv_sat_get_inkey_struct *get_inkey = (srv_sat_get_inkey_struct *)getCmdData();
            VFX_ASSERT(get_inkey->input_type == SRV_SAT_INPUT_YES_NO);
	    m_text.loadFromMem(get_inkey->text_string);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(get_inkey->icon.data);
#endif
            setHelpEnable(get_inkey->help_available  ? VFX_TRUE : VFX_FALSE);

            setTimerId(SAT_TIMER_NO_RESPONSE);
            setTimerDuration(VAPP_SAT_NO_RESPONSE_DURATION);
            break;
        }

        case SRV_SAT_CMD_PLAY_TONE:
        {
            srv_sat_play_tone_struct *play_tone = (srv_sat_play_tone_struct *)getCmdData();
			m_text.loadFromMem(play_tone->alpha_id);
#ifndef __SAT_DISABLE_ICON_SUPPORT__			
            m_icon = VfxImageSrc(play_tone->icon.data);
#endif
            setTimerId(SAT_TIMER_PLAY_TONE);
            setTimerDuration(play_tone->duration);
            break;
        }

        case SRV_SAT_CMD_SEND_SMS:
        {
            srv_sat_send_sms_struct *send_sms = (srv_sat_send_sms_struct *)getCmdData();
			m_text.loadFromMem(send_sms->alpha_id);
#ifndef __SAT_DISABLE_ICON_SUPPORT__			
            m_icon = VfxImageSrc(send_sms->icon.data);
#endif
            break;
        }

        case SRV_SAT_CMD_SEND_SS:
        {
            srv_sat_send_ss_struct *send_ss = (srv_sat_send_ss_struct *)getCmdData();
			m_text.loadFromMem(send_ss->alpha_id);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(send_ss->icon.data);
#endif
            break;
        }

        case SRV_SAT_CMD_SEND_SS_RETURN_RESULT:
        {
            srv_sat_send_ss_struct *send_ss_res = (srv_sat_send_ss_struct *)getCmdData();
            m_text.loadFromMem(send_ss_res->text_string);
            break;
        }

        case SRV_SAT_CMD_SEND_USSD:
        {
            srv_sat_send_ussd_struct *send_ussd = (srv_sat_send_ussd_struct *)getCmdData();
			m_text.loadFromMem(send_ussd->alpha_id);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(send_ussd->icon.data);
#endif
            break;
        }

        case SRV_SAT_CMD_SEND_USSD_RETURN_RESULT:
        {
            srv_sat_send_ussd_struct *send_ussd_res = (srv_sat_send_ussd_struct *)getCmdData();
            m_text.loadFromMem(send_ussd_res->text_string);
            break;
        }

        case SRV_SAT_CMD_SETUP_CALL:
        {
            srv_sat_setup_call_struct *call = (srv_sat_setup_call_struct *)getCmdData();
			m_text.loadFromMem(call->alpha_id1);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(call->icon1.data);

            if (call->icon2.available)
            {
                mmi_sat_create_folder();

                SAT_CONTEXT(getSimId())->calling_icon_available =
                    mmi_sat_save_calling_icon(
                        getSimId(),
                        call->icon2.data,
                        mmi_sat_create_calling_icon_path(
                            getSimId(),
                            &SAT_CONTEXT(getSimId())->calling_icon_path));
            }
#endif // __SAT_DISABLE_ICON_SUPPORT__
            break;
        }

        case SRV_SAT_CMD_SEND_DTMF:
        {
            srv_sat_send_dtmf_struct *dtmf = (srv_sat_send_dtmf_struct *)getCmdData();
			m_text.loadFromMem(dtmf->alpha_id);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(dtmf->icon.data);
#endif
            break;
        }

    #ifdef BROWSER_SUPPORT
        case SRV_SAT_CMD_LAUNCH_BROWSER:
        {
            srv_sat_launch_browser_struct *browser = (srv_sat_launch_browser_struct *)getCmdData();
			m_text.loadFromMem(browser->alpha_id);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(browser->icon.data);
#endif
            break;
        }
    #endif /* BROWSER_SUPPORT */

    #ifdef __SATCE__
        case SRV_SAT_CMD_OPEN_CHANNEL:
        {
            srv_sat_open_channel_struct *open_channel = (srv_sat_open_channel_struct *)getCmdData();
            m_text.loadFromMem(open_channel->alpha_id);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(open_channel->icon.data);
#endif
            break;
        }

        case SRV_SAT_CMD_CLOSE_CHANNEL:
        {
            srv_sat_close_channel_struct *close_channel = (srv_sat_close_channel_struct *)getCmdData();
            m_text.loadFromMem(close_channel->alpha_id);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(close_channel->icon.data);
#endif
            break;
        }

        case SRV_SAT_CMD_SEND_DATA:
        {
            srv_sat_send_data_struct *send_data = (srv_sat_send_data_struct *)getCmdData();
            m_text.loadFromMem(send_data->alpha_id);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(send_data->icon.data);
#endif
            break;
        }

        case SRV_SAT_CMD_RECEIVE_DATA:
        {
            srv_sat_receive_data_struct *recv_data = (srv_sat_receive_data_struct *)getCmdData();
            m_text.loadFromMem(recv_data->alpha_id);
#ifndef #ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(recv_data->icon.data);
#endif
            break;
        }
    #endif /* __SATCE__ */
	#ifdef __SATCB__
        case SRV_SAT_CMD_RUN_AT_COMMAND:
        {
            srv_sat_run_at_command_struct *at_cmd = (srv_sat_run_at_command_struct *)getCmdData();
            m_text.loadFromMem(at_cmd->alpha_id);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(at_cmd->icon.data);
#endif
            break;
        }
	#endif //__SATCB__
        default:
            VFX_ASSERT(0);
            break;
    }
}

void VappSatViewPage::cmdDoWithShow()
{
    switch (getCmdType())
    {
        case SRV_SAT_CMD_PLAY_TONE:
        {
        #ifdef __MMI_SILENT_MEETING_PROFILE__
            if ((srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED) &&
                (srv_prof_is_profile_activated(SRV_PROF_MEETING_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED))
        #else 
            if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) != SRV_PROF_RET_PROFILE_ACTIVATED)
        #endif 
            {
                /* not play tone in slient mode */
                srv_sat_play_tone_struct *play_tone = (srv_sat_play_tone_struct *)getCmdData();
                srv_prof_play_tone_with_id(SRV_PROF_TONE_SAT, play_tone->tone, SRV_PROF_RING_TYPE_REPEAT, NULL);
            }
            break;
        }

        case SRV_SAT_CMD_SEND_SMS:
        {
            setIsSent(VFX_TRUE);
            srv_sat_terminal_response_send_sms_stage1(getSimId());
            break;
        }

        case SRV_SAT_CMD_SEND_SS:
        {
            setIsSent(VFX_TRUE);
            srv_sat_terminal_response_send_ss_stage1(getSimId());
            break;
        }

        case SRV_SAT_CMD_SEND_USSD:
        {
            setIsSent(VFX_TRUE);
            srv_sat_terminal_response_send_ussd_stage1(getSimId());
            break;
        }
		case SRV_SAT_CMD_SEND_DTMF:
		{
			
			srv_sat_terminal_response_send_dtmf_stage1(getSimId());
			break;
		}

        default:
            break;
    }
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
#endif
#ifndef __SAT_DISABLE_ICON_SUPPORT__
void VappSatViewPage::setIcon(const VfxImageSrc &imgScr)
{
    m_icon = imgScr;
    checkUpdate();
}

VfxImageSrc VappSatViewPage::getIcon() const
{
    return m_icon;
}
#endif // __SAT_DISABLE_ICON_SUPPORT__
void VappSatViewPage::updateViewPage()
{
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    updateImageFrame();
#endif
    updateTextFrame();
}

#ifndef __SAT_DISABLE_ICON_SUPPORT__
void VappSatViewPage::updateImageFrame()
{
    if (getIcon().isNull())
    {
        m_imageFrame->setHidden(VFX_TRUE);
        return;
    }

    m_imageFrame->setImgContent(getIcon());

    m_imageFrame->setAnchor(0.5f, 0.0f);
    m_imageFrame->setPos(getSize().width / 2,  VAPP_SAT_VIEW_PAGE_ICON_MARGIN);

    m_imageFrame->setHidden(VFX_FALSE);
}
#endif
void VappSatViewPage::updateTextFrame()
{
    m_textFrame->setString(m_text);

    m_textFrame->setAnchor(0.5f, 0.0f);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    if (getIcon().isEmpty())
    {
#endif
        m_textFrame->setSize(getSize());
        m_textFrame->setPos(getSize().width / 2, 0);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    }
    else
    {
        VfxU32 up_margin = m_imageFrame->getSize().height + VAPP_SAT_VIEW_PAGE_ICON_MARGIN + VAPP_SAT_VIEW_PAGE_ICON_DOWN_MARGIN;
        VfxU32 height = getSize().height - up_margin;
        m_textFrame->setSize(getSize().width, height);
        m_textFrame->setPos(getSize().width / 2, up_margin);
    }
#endif

    m_textFrame->setMargins(VAPP_SAT_PAGE_CP_MARGIN, VAPP_SAT_PAGE_CP_MARGIN, VAPP_SAT_PAGE_CP_MARGIN, 0);
    m_textFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);

    m_textFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SAT_TEXT_FONT_SIZE)));
}
