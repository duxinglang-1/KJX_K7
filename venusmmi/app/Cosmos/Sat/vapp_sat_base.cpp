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
 *  Vapp_sat_base.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements  SAT Base Class.
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
#include "AlarmSrvGprot.h"
#include "UCMGProt.h"
#include "UcmSrvGprot.h"
#include "SatSrvGprot.h"
#include "SatCoreProt.h"
#include "mmi_frm_utility_gprot.h"
#include "Lang_interface.h"


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

#include "vapp_sat.h"
#include "Vapp_sat_gprot.h"
#include "vapp_sat_base.h"
#include "mmi_rp_vapp_sat_def.h"
#include "vadp_app_trc.h"
#include "vadp_app_trc_gen.h"

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/


#ifdef __cplusplus
extern "C"{
#endif

/**************************************************************
 * Structure Declaration
 **************************************************************/


/**************************************************************
 * Static Variables Defination                                *
 **************************************************************/


#ifndef	__SAT_DISABLE_ICON_SUPPORT__
static vapp_sat_context_struct      g_sat_context[MMI_SIM_TOTAL];


/**************************************************************
 * Function Defination                                        *
 **************************************************************/

/*****************************************************************************
 * FUNCTION
 *  SAT_CONTEXT
 * DESCRIPTION
 *  get sat context by sim id.
 * PARAMETERS
 *  sim_id      [IN]    sim id
 * RETURNS
 *  sat context
 *****************************************************************************/
vapp_sat_context_struct *SAT_CONTEXT(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return &g_sat_context[mmi_frm_sim_to_index(sim_id)];
}

MMI_BOOL vapp_sat_is_calling_icon_available(mmi_sim_enum simId)
{
    return SAT_CONTEXT(simId)->calling_icon_available;
}


CHAR *vapp_sat_get_calling_icon_path(mmi_sim_enum simId)
{
    if (SAT_CONTEXT(simId)->calling_icon_available)
    {
        return SAT_CONTEXT(simId)->calling_icon_path;
    }
    else
    {
        return NULL;
    }
}

void vapp_sat_free_calling_icon_path(mmi_sim_enum simId)
{
    if (SAT_CONTEXT(simId)->calling_icon_path)
    {
        OslMfree(SAT_CONTEXT(simId)->calling_icon_path);
        SAT_CONTEXT(simId)->calling_icon_path = NULL;
    }

    SAT_CONTEXT(simId)->calling_icon_available = MMI_FALSE; 
}
#endif

#ifdef __cplusplus
}
#endif


/***************************************************************************** 
 * Class VappSatBasePage
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VappSatBasePage", VappSatBasePage, VfxPage);
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
#endif
VappSatBasePage::VappSatBasePage(srv_sat_proactive_sim_struct *cmdInfo) :
    m_simId(cmdInfo->sim_id),
    m_cmdType(cmdInfo->cmd_type),
    m_cmdInfo(cmdInfo),
    m_cmdData(&m_cmdInfo->cmd_data),
    m_bHelp(VFX_FALSE),
    m_bSent(VFX_FALSE),
    m_isWait(VFX_FALSE),
    m_titleBar(NULL),
    m_toolBar(NULL),
    m_popupInfo(NULL),
    m_resetPopup(NULL),
    m_timerId(SAT_TIMER_WAIT),
    m_duration(VAPP_SAT_INFINITE_DURATION)
{
    VFX_ASSERT(cmdInfo != NULL);
}


VappSatBasePage::VappSatBasePage(mmi_sim_enum simId, srv_sat_setup_menu_struct *mainmenu) :
    m_simId(simId),
    m_cmdType(SRV_SAT_CMD_SETUP_MENU),
    m_cmdInfo(NULL),
    m_cmdData(mainmenu),
    m_bHelp(VFX_FALSE),
    m_bSent(VFX_FALSE),
    m_isWait(VFX_FALSE),
    m_titleBar(NULL),
    m_toolBar(NULL),
    m_popupInfo(NULL),
    m_resetPopup(NULL),
    m_timerId(SAT_TIMER_WAIT),
    m_duration(VAPP_SAT_INFINITE_DURATION)
{
}


void VappSatBasePage::onInit()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_BASE_PAGE_ONINIT, (U32)m_simId, (U32)m_cmdType);

    VfxPage::onInit();

    VFX_OBJ_CREATE(m_titleBar, VappSatBaseTitleBar, this);
    VFX_OBJ_CREATE(m_toolBar, VcpToolBar,this);
    VFX_OBJ_CREATE(m_popupInfo, VcpIndicatorPopup, this);
    VFX_OBJ_CREATE(m_resetPopup, VcpConfirmPopup, this);

    setFocused(VFX_TRUE);
}


void VappSatBasePage::onDeinit()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_BASE_PAGE_ONDEINIT, (U32)m_simId, (U32)m_cmdType);

    VfxPage::onDeinit();
}


void VappSatBasePage::onUpdate()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_BASE_PAGE_ONUPDATE);

    VfxPage::onUpdate();
}


mmi_ret VappSatBasePage::onProc(mmi_event_struct *evt)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_BASE_PAGE_ONPROC, evt->evt_id);

    if (evt->evt_id == EVT_ID_SRV_SAT_SESSION_END)
    {
        hidePopup();
    }

    return MMI_RET_DONT_CARE;
}


void VappSatBasePage::onBack()
{
    switch (getCmdType())
    {
        case SRV_SAT_CMD_SETUP_MENU:
            VfxPage::onBack();
            break;

        case SRV_SAT_CMD_DISPLAY_TEXT:
        case SRV_SAT_CMD_GET_INKEY:
        case SRV_SAT_CMD_GET_INPUT:
        case SRV_SAT_CMD_PLAY_TONE:
        case SRV_SAT_CMD_SELECT_ITEM:
        case SRV_SAT_CMD_SETUP_CALL:
        case SRV_SAT_CMD_SEND_DTMF:
        case SRV_SAT_CMD_SEND_SS_RETURN_RESULT:
        case SRV_SAT_CMD_SEND_USSD_RETURN_RESULT:

    #ifdef BROWSER_SUPPORT
	#ifdef __SATCC__
        case SRV_SAT_CMD_LAUNCH_BROWSER:
	#endif
    #endif /* BROWSER_SUPPORT */

            onMeResponse(this, TOOLBAR_CANCEL);
            break;
	#ifdef __SATCB__
        case SRV_SAT_CMD_RUN_AT_COMMAND:
	#endif
        case SRV_SAT_CMD_SETUP_IDLE_MODE_TEXT:
        //case SRV_SAT_CMD_REFRESH:
        case SRV_SAT_CMD_SEND_SMS:
        case SRV_SAT_CMD_SEND_SS:
        case SRV_SAT_CMD_SEND_USSD:
            break;

    #ifdef __SATCE__
        case SRV_SAT_CMD_OPEN_CHANNEL:
            onMeResponse(this, TOOLBAR_CANCEL);
            break;

        case SRV_SAT_CMD_CLOSE_CHANNEL:
        case SRV_SAT_CMD_SEND_DATA:
        case SRV_SAT_CMD_RECEIVE_DATA:
            break;
    #endif /*__SATCE__*/

        default:
            break;
    }
}


VfxBool VappSatBasePage::onKeyInput(VfxKeyEvent &event)
{
    if (getTimerId() != SAT_TIMER_WAIT)
    {
        srv_sat_resume_timer(getSimId(), SAT_TIMER_NO_RESPONSE, MMI_TRUE);
    }

    return VfxPage::onKeyInput(event);
}


VfxBool VappSatBasePage::onPreviewPenInput(VfxPenEvent &event)
{
    if (getTimerId() != SAT_TIMER_WAIT)
    {
        srv_sat_resume_timer(getSimId(), SAT_TIMER_NO_RESPONSE, MMI_TRUE);
    }

    return VfxPage::onPenInput(event);
}


VfxBool VappSatBasePage::onPenInput(VfxPenEvent &event)
{
    if (getTimerId() != SAT_TIMER_WAIT)
    {
        srv_sat_resume_timer(getSimId(), SAT_TIMER_NO_RESPONSE, MMI_TRUE);
    }

    return VfxPage::onPenInput(event);
}


void VappSatBasePage::onMeResponse(VfxObject *sender, VfxId index)
{
    if (m_bSent)
    {
        if (getCmdType() == SRV_SAT_CMD_DISPLAY_TEXT)
        {
            VfxPage::onBack();
        }

        return;
    }
    m_bSent = VFX_TRUE;

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_BASE_PAGE_ONMERESPONSE, (VfxU32)index);

    m_isWait = onResponse((VappSatToolbarTypeEnum)index);

    if (m_isWait)
    {
        if (getCmdType() == SRV_SAT_CMD_DISPLAY_TEXT)
        {
            if (((srv_sat_display_text_struct *)getCmdData())->immediate_res)
            {
                return;
            }
        }

        showPopup(VFX_WSTR_RES(STR_GLOBAL_PLEASE_WAIT));
    }
}


VfxBool VappSatBasePage::onResponse(VappSatToolbarTypeEnum btnId)
{
    return VFX_TRUE;
}


void VappSatBasePage::onTimerExpiry(srv_sat_callback_struct *callback_data)
{
    VappSatBasePage *page = (VappSatBasePage *)callback_data->user_data;;

    if (!callback_data->result)
    {
        return;
    }

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_BASE_PAGE_TIMER_EXPIRY);

    switch (callback_data->timer_id)
    {
        case SAT_TIMER_WAIT:
        {
            break;
        }

        case  SAT_TIMER_CLEAR_DELAY:
        {
            page->onMeResponse(page, TOOLBAR_OK);
            break;
        }

        case SAT_TIMER_POPUP:
        {
            VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_BASE_PAGE_EXIT);
            page->exit();
            break;
        }

        case SAT_TIMER_PLAY_TONE:
        {
            srv_prof_stop_tone(SRV_PROF_TONE_SAT);
            page->onMeResponse(page, TOOLBAR_OK);
            break;
        }

        case SAT_TIMER_REFRESH_REBOOT:
        {
            break;
        }

        case SAT_TIMER_NO_RESPONSE:
        {
            switch (page->getCmdType())
            {
                case SRV_SAT_CMD_SELECT_ITEM:
                {
                    if (!page->getIsSent())
                    {
                        page->setIsSent(VFX_TRUE);
                        srv_sat_terminal_response_select_item(
                            callback_data->sim_id,
                            SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER,
                            0);
                    }
                    break;
                }

                case SRV_SAT_CMD_DISPLAY_TEXT:
                {
                    if (!page->getIsSent())
                    {
                        page->setIsSent(VFX_TRUE);
                        srv_sat_terminal_response_display_text(
                            callback_data->sim_id,
                            SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER,
                            SRV_SAT_ADDITIONAL_RES_NO_SPECIFIC_CAUSE);
                    }
                    break;
                }

                case SRV_SAT_CMD_GET_INKEY:
                {
                    if (!page->getIsSent())
                    {
                        page->setIsSent(VFX_TRUE);
                        srv_sat_terminal_response_get_inkey(
                                callback_data->sim_id,
                                SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER,
                                MMI_FALSE,
                                NULL);
                    }
                    break;
                }

                case SRV_SAT_CMD_GET_INPUT:
                {
                    if (!page->getIsSent())
                    {
                        page->setIsSent(VFX_TRUE);
                        srv_sat_terminal_response_get_input(
                                callback_data->sim_id,
                                SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER,
                                NULL);
                    }
                    break;
                }

                case SRV_SAT_CMD_SEND_SS:
                {
                    if (!page->getIsSent())
                    {
                        page->setIsSent(VFX_TRUE);
                        srv_sat_terminal_response_send_ss_stage2(
                                callback_data->sim_id,
                                SRV_SAT_TERMINAL_RES_NO_RESPONSE_FROM_USER,
                                0,
                                NULL);
                    }
                    break;
                }

                default:
                    break;
            }

            VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_BASE_PAGE_EXIT);
            page->exit();
            break;
        }

        default:
            break;
    }
}


void VappSatBasePage::addCmdTimer()
{
    if (getTimerId() != SAT_TIMER_WAIT)
    {
        srv_sat_start_timer(
                getSimId(),
                getTimerId(),
                getTimerDuration(),
                &VappSatBasePage::onTimerExpiry,
                this);
    }
}


void VappSatBasePage::deleteCmdTimer()
{
    if (getTimerId() != SAT_TIMER_WAIT)
    {
        srv_sat_stop_timer(getSimId(), getTimerId());
    }
}


mmi_core_sat_rsp_enum VappSatBasePage::convertBtnIdToRspId(VappSatToolbarTypeEnum btnId)
{
    mmi_core_sat_rsp_enum ret = SAT_RSP_OK;

    switch (btnId)
    {
        case TOOLBAR_OK:
            ret = SAT_RSP_OK;
            break;

        case TOOLBAR_HELP:
            ret = SAT_RSP_HELP;
            break;

        case TOOLBAR_TERMINATE:
            ret = SAT_RSP_TERMINATE;
            break;

        case TOOLBAR_CANCEL:
            if (m_cmdType == SRV_SAT_CMD_SETUP_CALL
                #ifdef BROWSER_SUPPORT
				#ifdef __SATCC__
                    || m_cmdType == SRV_SAT_CMD_LAUNCH_BROWSER
                #endif
                #endif /* BROWSER_SUPPORT */

                #ifdef __SATCE__
                    || m_cmdType == SRV_SAT_CMD_OPEN_CHANNEL
                #endif /* __SATCE__ */
                )
            {
                ret = SAT_RSP_CANCEL;
            }
            else
            {
                ret = SAT_RSP_BACK;
            }
            break;

        default:
            break;
    }

    return ret;
}


void VappSatBasePage::setTitleBar(const VfxImageSrc &imgScr, const VfxWString &string)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_BASE_PAGE_SETTITLEBAR);

    if (getCmdType() == SRV_SAT_CMD_SETUP_MENU || getCmdType() == SRV_SAT_CMD_SELECT_ITEM)
    {
        m_titleBar->setIconAndString(imgScr, string);
    }
    else if (string == VFX_WSTR_NULL)
    {
        VfxS32 index = VFX_OBJ_GET_INSTANCE(VappSatMgr)->getMainMenuItemIndex(getSimId());
        WCHAR *tempString = NULL;
        if (index < 0)
        {
            tempString = (WCHAR *)srv_sat_get_menu_title(getSimId());
        }
        else
        {
            tempString = (WCHAR *)srv_sat_get_menu_item(getSimId(), (S32)index);
        }

        m_titleBar->setIconAndString(imgScr, VFX_WSTR_MEM(tempString));
    }

    setBar(VFX_PAGE_BAR_LOCATION_TOP, m_titleBar, VFX_TRUE);
}


void VappSatBasePage::setToolBar()
{
    VappSatToolbarTypeEnum style = getToolbarStyle();

    if (style == TOOLBAR_NONE)
    {
        return;
    }

    if (style & TOOLBAR_OK)             // ok
    {
        //VfxWString string = VFX_WSTR_RES(STR_GLOBAL_OK);
        VfxWString string(STR_GLOBAL_OK);
        VfxResId   iconId = IMG_ID_VAPP_SAT_OK;

        if (m_cmdType == SRV_SAT_CMD_SETUP_CALL)
        {
            string.loadFromRes(STR_ID_VAPP_SAT_CALL);
            iconId = IMG_ID_VAPP_SAT_CALL;
        }

    #ifdef BROWSER_SUPPORT
	#ifdef __SATCC__
        if (m_cmdType == SRV_SAT_CMD_LAUNCH_BROWSER)
        {
	    string.loadFromRes(STR_ID_VAPP_SAT_LAUNCH);
            iconId = IMG_ID_VAPP_SAT_LAUNCH;
        }
	#endif	
    #endif /* BROWSER_SUPPORT */

        m_toolBar->addItem(TOOLBAR_OK, string, iconId);
    }

    if (style & TOOLBAR_YES)            // yes
    {
        m_toolBar->addItem(TOOLBAR_YES, STR_GLOBAL_YES, IMG_GLOBAL_YES);
    }

    if (style & TOOLBAR_HELP)           // help
    {
        m_toolBar->addItem(TOOLBAR_HELP, STR_GLOBAL_HELP, IMG_ID_VAPP_SAT_HELP2);
    }

    if (style & TOOLBAR_TERMINATE)      // terminate
    {
        m_toolBar->addItem(TOOLBAR_TERMINATE, STR_ID_VAPP_SAT_TERMINATE, IMG_ID_VAPP_SAT_TERMINATE);
    }

    if (style & TOOLBAR_CANCEL)         // cancel
    {
        m_toolBar->addItem(TOOLBAR_CANCEL, STR_GLOBAL_CANCEL, IMG_ID_VAPP_SAT_CANCEL);
    }

    if (style & TOOLBAR_NO)             // no
    {
        m_toolBar->addItem(TOOLBAR_NO, STR_GLOBAL_NO, IMG_GLOBAL_NO);
    }

    getBar(VFX_PAGE_BAR_LOCATION_BOTTOM);

    m_toolBar->m_signalButtonTap.connect(this, &VappSatBasePage::onMeResponse);
    setBottomBar(m_toolBar);
}


void VappSatBasePage::setFunctionBar(VcpFunctionBar *funcBar)
{
    VappSatToolbarTypeEnum style = getToolbarStyle();

    if (style & TOOLBAR_HELP)           // help
    {
        funcBar->addItem((VfxResId)STR_GLOBAL_HELP, (VfxId)TOOLBAR_HELP);
    }

    if (style & TOOLBAR_TERMINATE)      // terminate
    {
        funcBar->addItem((VfxResId)STR_ID_VAPP_SAT_TERMINATE, (VfxId)TOOLBAR_TERMINATE);
    }

    if (style & TOOLBAR_OK)             // ok
    {
        funcBar->addItem((VfxResId)STR_GLOBAL_OK, (VfxId)TOOLBAR_OK);
    }

    funcBar->setItemSpecial(TOOLBAR_OK);
    funcBar->m_signalButtonTap.connect(this, &VappSatBasePage::onMeResponse);
}


VappSatBasePage::VappSatToolbarTypeEnum VappSatBasePage::getToolbarStyle()
{
    VappSatToolbarTypeEnum ret = TOOLBAR_NONE;

    switch (m_cmdType)
    {
        //case SRV_SAT_CMD_SETUP_MENU:
    #ifndef __POPUP_SUPPORT__
        case SRV_SAT_CMD_SETUP_IDLE_MODE_TEXT:
        case SRV_SAT_CMD_PROVIDE_LOCAL_INFORMATION:
    #endif
        {
            if (m_bHelp)
            {
                ret = VAPP_SAT_TOOLBAE_OK_HELP_CANCEL;      // ok, help, cancel
            }
            else
            {
                ret = VAPP_SAT_TOOLBAE_OK_CANCEL;           // ok, cancel
            }
            break;
        }

        case SRV_SAT_CMD_SELECT_ITEM:
        {
            ret = TOOLBAR_TERMINATE;
            break;
        }

        case SRV_SAT_CMD_GET_INKEY:
        {
            srv_sat_get_inkey_struct *get_inkey = (srv_sat_get_inkey_struct *)getCmdData();
            if (get_inkey->input_type == SRV_SAT_INPUT_YES_NO)
            {
                if (m_bHelp)
                {
                    ret = VAPP_SAT_TOOLBAE_YES_HELP_TERMINATE_NO;    // yes, help, terminate, no
                }
                else
                {
                    ret = VAPP_SAT_TOOLBAE_YES_TERMINATE_NO;         // yes, terminate, no
                }
                break;
            }
        }

        case SRV_SAT_CMD_GET_INPUT:
        {
            if (m_bHelp)
            {
                ret = VAPP_SAT_TOOLBAE_OK_HELP_TERMINATE_CANCEL;    // ok, help, terminate, cancel
            }
            else
            {
                ret = VAPP_SAT_TOOLBAE_OK_TERMINATE_CANCEL;         // ok, terminate, cancel
            }
            break;
        }

        case SRV_SAT_CMD_DISPLAY_TEXT:
        case SRV_SAT_CMD_SETUP_CALL:

    #ifdef BROWSER_SUPPORT
	#ifdef __SATCC__
        case SRV_SAT_CMD_LAUNCH_BROWSER:
	#endif		
    #endif /* BROWSER_SUPPORT */

    #ifdef __SATCE__
        case SRV_SAT_CMD_OPEN_CHANNEL:
        case SRV_SAT_CMD_CLOSE_CHANNEL:
        case SRV_SAT_CMD_SEND_DATA:
        case SRV_SAT_CMD_RECEIVE_DATA:
    #endif /*__SATCE__*/
        {
            ret = VAPP_SAT_TOOLBAE_OK_TERMINATE_CANCEL;     // ok, terminate, cancel
            break;
        }

        case SRV_SAT_CMD_SEND_DTMF:
        case SRV_SAT_CMD_SEND_SS_RETURN_RESULT:
        case SRV_SAT_CMD_SEND_USSD_RETURN_RESULT:
        {
            ret = VAPP_SAT_TOOLBAE_OK_CANCEL;               // ok, cancel
            break;
        }

        default:
            break;
    }

    return ret;
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
#endif

void VappSatBasePage::showPopup(VfxWString string)
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_BASE_PAGE_SHOWPOPUP);

    m_popupInfo->setInfoType(VCP_INDICATOR_POPUP_STYLE_ACTIVITY);
    m_popupInfo->setText(string);
    m_popupInfo->setAutoDestory(VFX_TRUE);
    m_popupInfo->show(VFX_TRUE);
}


void VappSatBasePage::hidePopup()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_BASE_PAGE_HIDEPOPUP);

    m_popupInfo->hide(VFX_TRUE);
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
#ifndef __POPUP_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 2)
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
#if (MMI_MAX_SIM_NUM >= 3)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (MMI_MAX_SIM_NUM >= 4)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __SIM_RESET_BY_SIM__
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /*__SIM_RESET_BY_SIM__ */
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
#ifndef __MMI_VECTOR_FONT_MEMORY_CARD_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
void VappSatBasePage::cmdSessionEnd()
{
    if (getIsSent()
        || getCmdType() == SRV_SAT_CMD_SETUP_MENU
        #ifdef __SATCE__
        || getCmdType() == SRV_SAT_CMD_SEND_DATA
        || getCmdType() == SRV_SAT_CMD_RECEIVE_DATA
        #endif /* __SATCE__ */
        )
    {
        return;
    }

    deleteCmdTimer();
    onMeResponse(this, TOOLBAR_TERMINATE);
    srv_sat_free_last_proactive_sim(getSimId(), getCmdType());
}


VfxBool VappSatBasePage::isDontCareCmd(srv_sat_proactive_sim_struct *cmdInfo)
{
    return (cmdInfo->sim_id!= getSimId() ||
            cmdInfo->cmd_type == SRV_SAT_CMD_SETUP_MENU && getCmdType() != SRV_SAT_CMD_SETUP_MENU);
}


VfxBool VappSatBasePage::getIsSent() const
{
    return m_bSent;
}


void VappSatBasePage::setIsSent(VfxBool isTrue)
{
    m_bSent = isTrue;
}


void VappSatBasePage::setHelpEnable(VfxBool isTrue)
{
    m_bHelp = isTrue;
}


void *VappSatBasePage::getCmdData() const
{
    return m_cmdData;
}


mmi_sim_enum VappSatBasePage::getSimId() const
{
    return m_simId;
}


srv_sat_cmd_enum VappSatBasePage::getCmdType() const
{
    return m_cmdType;
}


VfxBool VappSatBasePage::getIsWait()
{
    return m_isWait;
}


mmi_core_sat_timer_enum VappSatBasePage::getTimerId() const
{
    return m_timerId;
}


void VappSatBasePage::setTimerId(mmi_core_sat_timer_enum timerId)
{
    m_timerId = timerId;
}


VfxU16 VappSatBasePage::getTimerDuration() const
{
    return m_duration;
}


void VappSatBasePage::setTimerDuration(VfxU16 duration)
{
    m_duration = duration;
}
