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
 *  Vapp_sat_editor.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements  SAT Editor Class.
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
#include "Unicodexdcl.h"
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
 #include "gui_virtual_keyboard.h" 
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
  
#include "vapp_sat_base.h"
#include "vapp_sat_editor.h"
#include "mmi_rp_vapp_sat_def.h"
#include "vadp_app_trc.h"
#include "vadp_app_trc_gen.h"
#include "mmi_rp_app_cosmos_global_def.h"


/***************************************************************************** 
 * Class VappSatEditorPage
 *****************************************************************************/
 
//VFX_IMPLEMENT_CLASS("VappSatEditorPage", VappSatEditorPage, VappSatBasePage);
#if 0
/* under construction !*/
/* under construction !*/
#ifndef __SAT_DISABLE_ICON_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __SAT_DISABLE_ICON_SUPPORT__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
VappSatEditorPage::VappSatEditorPage(srv_sat_proactive_sim_struct *cmdInfo) :
    VappSatBasePage(cmdInfo),
    m_text(VFX_WSTR_NULL),
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    m_icon(VFX_IMAGE_SRC_NULL),
#endif
    m_multiMode(VCP_TEXT_LINE_MODE_SINGLE),
    //m_height(0),
    //m_editBuf(NULL),
    //m_minNum(0),
    //m_maxNum(0),
    //m_inputMethod(SRV_SAT_INPUT_DIGIT_ONLY),
   
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    m_imageFrame(NULL),
#endif
    //m_textFrame(NULL),
    //m_textEditor(NULL),
    //m_funcBar(NULL),
    //m_form(NULL)
     m_echoMode(VFX_FALSE)
{
}

VappSatEditorPage::~VappSatEditorPage()
{}

void VappSatEditorPage::onInit()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_EDITOR_PAGE_ONINIT);

    VappSatBasePage::onInit();

    VFX_OBJ_CREATE(m_form, VcpForm, this);
    m_form->setSize(getSize());
    m_form->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE,
                    VFX_FRAME_ALIGNER_MODE_SIDE);

    VfxFrame *canvas;
    VFX_OBJ_CREATE(canvas, VfxFrame, m_form);
    canvas->setSize(getSize());
    canvas->setBgColor(VFX_COLOR_TRANSPARENT);

#ifndef __SAT_DISABLE_ICON_SUPPORT__
    VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, canvas);
#endif
    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, canvas);
    VFX_OBJ_CREATE(m_textEditor, VcpTextEditor, canvas);

    VcpFormItemCustomFrame *canvasForm;
    VFX_OBJ_CREATE(canvasForm, VcpFormItemCustomFrame, m_form);
    canvasForm->attachCustomFrame(canvas);

    m_form->addItem(canvasForm);

    VFX_OBJ_CREATE(m_funcBar, VcpFunctionBar, m_form);

    m_textEditor->setAutoActivated(VFX_TRUE);
    m_textEditor->m_signalTextChanged.connect(this, &VappSatEditorPage::onEditorTextChanged);

    cmdParser();
    setInputMethod();
    updateEditorPage();
    setTitleBar();
    setToolBar();
    setFunctionBar(m_funcBar);

    m_textEditor->setFunctionBar(m_funcBar);
    canvasForm->setHeight(m_formHeight);

    setTimerId(SAT_TIMER_NO_RESPONSE);
    setTimerDuration(VAPP_SAT_NO_RESPONSE_DURATION);
    addCmdTimer();
}

void VappSatEditorPage::onDeinit()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_EDITOR_PAGE_ONDEINIT);

    cmdSessionEnd();

    VFX_FREE_MEM(m_editBuf);

    VappSatBasePage::onDeinit();
}

void VappSatEditorPage::onUpdate()
{
    VappSatBasePage::onUpdate();
    updateEditorPage();
}

mmi_ret VappSatEditorPage::onProc(mmi_event_struct *evt)
{
    mmi_ret ret = MMI_RET_DONT_CARE;

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_EDITOR_PAGE_ONPROC, evt->evt_id);

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
            VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_EDITOR_PAGE_EXIT);
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

            getMainScr()->popPage();
            break;
        }

        default:
            break;
    }

    VappSatBasePage::onProc(evt);

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_EDITOR_PAGE_ONPROC_RET, ret);

    return ret;
}


VfxBool VappSatEditorPage::onResponse(VappSatToolbarTypeEnum btnId)
{
    VfxBool ret = VFX_FALSE;

    if ((VfxU16)mmi_ucs2strlen((CHAR *)m_textEditor->getText()) < m_minNum && btnId == TOOLBAR_OK)
    {
        srv_sat_pause_timer(getSimId(), getTimerId());

        VcpConfirmPopup *info;
        VFX_OBJ_CREATE(info, VcpConfirmPopup, this);

        info->setInfoType(VCP_POPUP_TYPE_INFO);
        VfxWChar*   strNUm;
        VFX_ALLOC_MEM(strNUm, 5 * ENCODING_LENGTH, this);
        //VfxWString str = VFX_WSTR_RES(STR_ID_VAPP_SAT_GET_INPUT_LENGTH_NOT_ENOUGH);
        VfxWString str(STR_ID_VAPP_SAT_GET_INPUT_LENGTH_NOT_ENOUGH);
        str += VFX_WSTR_MEM(mmi_wcs_itow(m_minNum, strNUm, 10));
        VFX_FREE_MEM(strNUm);

        info->setText(str);
        info->setButtonSet(VCP_CONFIRM_BUTTON_SET_OK);
        info->m_signalButtonClicked.connect(this, &VappSatEditorPage::onOKBtnClicked);
        info->setAutoDestory(VFX_TRUE);
        info->show(VFX_TRUE);

        setIsSent(VFX_FALSE);
        return VFX_FALSE;
    }

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_EDITOR_PAGE_ONRESPONS, getSimId(), getCmdType(), btnId);

    switch (getCmdType())
    {
        case SRV_SAT_CMD_GET_INKEY:
        {
            ret = mmi_sat_get_inkey_response(getSimId(), convertBtnIdToRspId(btnId), MMI_FALSE, m_textEditor->getText()) ? VFX_TRUE : VFX_FALSE;
            break;
        }

        case SRV_SAT_CMD_GET_INPUT:
        {
            ret = mmi_sat_get_input_response(getSimId(), convertBtnIdToRspId(btnId), m_textEditor->getText()) ? VFX_TRUE : VFX_FALSE;
            break;
        }
    }

    return ret;
}


void VappSatEditorPage::onOKBtnClicked(VfxObject* sender, VfxId id)
{
    srv_sat_resume_timer(getSimId(), getTimerId(), MMI_TRUE);
}

void VappSatEditorPage::cmdParser()
{
    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_EDITOR_PAGE_CMDPARSER, getCmdType());

    switch (getCmdType())
    {
        case SRV_SAT_CMD_GET_INKEY:
        {
            srv_sat_get_inkey_struct *get_inkey = (srv_sat_get_inkey_struct *)getCmdData();
            VFX_ASSERT(get_inkey->input_type != SRV_SAT_INPUT_YES_NO);
            m_text.loadFromMem(get_inkey->text_string);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(get_inkey->icon.data);
#endif
            m_height = 40;
            setHelpEnable(get_inkey->help_available ? VFX_TRUE : VFX_FALSE);
            m_minNum = 1;
            m_maxNum = 1;
            m_inputMethod = get_inkey->input_type;

            VFX_ALLOC_MEM(m_editBuf, m_maxNum * ENCODING_LENGTH + ENCODING_LENGTH, this);
            memset(m_editBuf, 0, m_maxNum * ENCODING_LENGTH + ENCODING_LENGTH);
            setEditorBuffer(m_editBuf, m_maxNum);
            m_textEditor->setCursorIndex(0);
            break;
        }

        case SRV_SAT_CMD_GET_INPUT:
        {
            srv_sat_get_input_struct * get_input = (srv_sat_get_input_struct *)getCmdData();
            m_text.loadFromMem(get_input->text_string);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
            m_icon = VfxImageSrc(get_input->icon.data);
#endif
            m_height = 40 * 3;
            setHelpEnable(get_input->help_available ? VFX_TRUE : VFX_FALSE);
            m_minNum = (VfxU16)get_input->min_length;
            m_maxNum = (VfxU16)get_input->max_length;
	    m_maxNum = m_maxNum >= m_minNum ? m_maxNum : m_minNum;
            m_inputMethod = get_input->input_type;
            m_echoMode = get_input->echo_mode;
            m_multiMode = VCP_TEXT_LINE_MODE_MULTI;

            VFX_ALLOC_MEM(m_editBuf, m_maxNum * ENCODING_LENGTH + ENCODING_LENGTH, this);
            memset(m_editBuf, 0, m_maxNum * ENCODING_LENGTH + ENCODING_LENGTH);
            if (get_input->default_text!= NULL && mmi_wcslen(get_input->default_text) <= m_maxNum)
            {
                mmi_wcscpy((WCHAR *)m_editBuf, get_input->default_text);
            }

            setEditorBuffer(m_editBuf, m_maxNum);
	    if(mmi_wcslen(get_input->default_text) <= m_maxNum)
	    {
                m_textEditor->setCursorIndex(mmi_wcslen(get_input->default_text));
	    }
	    else
	    {
	        m_textEditor->setCursorIndex(0);
	    }
            
            break;
        }

        default:
            VFX_ASSERT(0);
            break;
    }
}

void VappSatEditorPage::updateEditorPage()
{
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    updateImageFrame();
#endif
    updateTextFrame();
    updateTextEditor();
}
#ifndef __SAT_DISABLE_ICON_SUPPORT__
void VappSatEditorPage::updateImageFrame()
{
    if (getIcon().isNull())
    {
        m_imageFrame->setHidden(VFX_TRUE);
        return;
    }

    m_imageFrame->setImgContent(getIcon());

    m_imageFrame->setAnchor(0.5f, 0.0f);
    m_imageFrame->setPos(getSize().width / 2,  VAPP_SAT_EDITOR_PAGE_ICON_MARGIN);

    m_imageFrame->setHidden(VFX_FALSE);
}
#endif // __SAT_DISABLE_ICON_SUPPORT__
void VappSatEditorPage::updateTextFrame()
{
    m_textFrame->setString(m_text);

    m_textFrame->setAnchor(0, 0);
    VfxSize strSize = m_textFrame->getFont().measureStr(m_text.getBuf());

    m_textFrame->setSize(getSize().width, (strSize.width / getSize().width) * strSize.height);
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    if (getIcon().isEmpty())
    {
        m_textFrame->setPos(0, 0);
    }
    else
    {
        VfxU32 up_margin = m_imageFrame->getSize().height + VAPP_SAT_EDITOR_PAGE_ICON_MARGIN + VAPP_SAT_EDITOR_PAGE_ICON_DOWN_MARGIN;
        VfxU32 height = getSize().height - up_margin;
        m_textFrame->setPos(0, up_margin);
    }
#else
	m_textFrame->setPos(0, 0);
#endif


    m_textFrame->setMargins(VAPP_SAT_PAGE_CP_MARGIN, VAPP_SAT_PAGE_CP_MARGIN, VAPP_SAT_PAGE_CP_MARGIN, 0);

    m_textFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_MULTI);

    m_textFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VAPP_SAT_TEXT_FONT_SIZE)));
}

void VappSatEditorPage::updateTextEditor()
{
    m_textEditor->setLineMode(m_multiMode);

    m_textEditor->setAnchor(0, 0);
    m_textEditor->setPos(VAPP_SAT_PAGE_CP_MARGIN, m_textFrame->getPos().y + m_textFrame->getSize().height + VAPP_SAT_EDITOR_PAGE_ICON_DOWN_MARGIN);
    m_textEditor->setSize(getSize().width - VAPP_SAT_PAGE_CP_MARGIN * 2, m_height);

    if (m_multiMode == VCP_TEXT_LINE_MODE_MULTI)
    {
        m_textEditor->setAutoResized(VFX_TRUE, -1, m_height);
    }

    m_textEditor->setBgColor(VFX_COLOR_TRANSPARENT);
    m_formHeight = m_textEditor->getPos().y + m_textEditor->getSize().height;

    showEditorHintCount();
    setInputMethod();
}

void VappSatEditorPage::showEditorHintCount()
{
    VfxS32 char_count = mmi_wcslen(m_textEditor->getText());
    if (char_count + VAPP_SAT_EDITOR_SHOW_HINT_INTERVAL_NUM >= m_maxNum)
    {
        m_textEditor->hideCounter(VFX_FALSE);
    }
    else
    {
        m_textEditor->hideCounter(VFX_TRUE);
    }
}

void VappSatEditorPage::onEditorTextChanged(VcpTextEditor *editor)
{
    showEditorHintCount();

    if (getTimerId() != SAT_TIMER_WAIT)
    {
        srv_sat_resume_timer(getSimId(), SAT_TIMER_NO_RESPONSE, MMI_TRUE);
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
void VappSatEditorPage::setIcon(const VfxImageSrc &imgSrc)
{
    m_icon = imgSrc;
    checkUpdate();
}

VfxImageSrc VappSatEditorPage::getIcon() const
{
    return m_icon;
}
#endif // __SAT_DISABLE_ICON_SUPPORT__
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
#endif
void VappSatEditorPage::setInputMethod()
{
    VfxU32 inputType = IMM_INPUT_TYPE_NONE;

    if (getCmdType() == SRV_SAT_CMD_GET_INKEY)
    {
        if (m_inputMethod == SRV_SAT_INPUT_DIGIT_ONLY)
        {
            inputType = IMM_INPUT_TYPE_SIM_NUMERIC;
        }
        else
        {
            
            if (m_inputMethod == SRV_SAT_INPUT_SMS_DEFAULT)
            {
                inputType |= IMM_INPUT_TYPE_ASCII_CHAR;
            }
            else
            {
                inputType = IMM_INPUT_TYPE_SENTENCE;
            }
        }
    }
    else
    {
        if (m_inputMethod == SRV_SAT_INPUT_DIGIT_ONLY)
        {
            if (m_echoMode)
            {
                inputType = IMM_INPUT_TYPE_SIM_NUMERIC;
            }
            else
            {
                inputType = IMM_INPUT_TYPE_SAT_NUMERIC_PASSWORD;
            }
        }
        else
        {
            if (m_echoMode)
            {
                inputType = IMM_INPUT_TYPE_SENTENCE;
            }
            else
            {
                inputType = IMM_INPUT_TYPE_ALPHANUMERIC_PASSWORD;
            }

            if (m_inputMethod == SRV_SAT_INPUT_SMS_DEFAULT)
            {
                inputType &= ~IMM_INPUT_TYPE_SENTENCE;
                inputType |= IMM_INPUT_TYPE_ASCII_CHAR;
            }
			
        }
#ifdef __MMI_TOUCH_SCREEN__
				const gui_virtual_keyboard_pen_enum invalid_vk_events[] = {GUI_VKBD_PEN_NEWLINE, GUI_VKBD_PEN_NONE};
#endif
				
					
   #ifdef __MMI_TOUCH_SCREEN__
				mmi_imm_set_events(MMI_FALSE, invalid_vk_events);
#endif
    }

    VFX_LOG(VFX_INFO2, TRC_VAPP_SAT_MENU_PAGE_SETIME, inputType);

    m_textEditor->setIME(inputType);
}

void VappSatEditorPage::setEditorBuffer(VfxWChar *Buf, const VfxU8 &length)
{
    VFX_ASSERT(Buf != NULL && length != 0);

    m_textEditor->setText(Buf, length, VFX_TRUE);
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
#endif
