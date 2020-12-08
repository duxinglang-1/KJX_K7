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
 *  vcp_input_popup.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  input popup implementation
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#include "vcp_popup.h"
#include "vcp_input_popup.h"
#include "vcp_res.h"
#include "GlobalResDef.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/*****************************************************************************
 * Class VcpInputPopup
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpInputPopup", VcpInputPopup, VfxBasePopup);
VcpInputPopup::VcpInputPopup():m_groupNum(1),
								m_isAllowdEmptyContent(VFX_FALSE),
								m_background(NULL),
								m_okButton(NULL),
								m_cancelButton(NULL),
								m_contentHeight(-1)

{
    for (VfxS32 i = 0; i < VCP_INPUT_POPUP_MAX_GROUP_NUM; i++)
    {
        m_hintTextFrame[i] = NULL;
        m_errorTextFrame[i] = NULL;
        m_inputbox[i] = NULL;
    }
}


void VcpInputPopup::onInit()
{
    VfxBasePopup::onInit();

    setAutoAnimate(VFX_TRUE);

    setPosZ(VFX_TOP_LEVEL_Z_INPUT_POPUP); 

    // title background
    VFX_OBJ_CREATE(m_titleBg, VfxFrame, this);        
    m_titleBg->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_TOP));
    m_titleBg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_titleBg->setSize(VCP_INPUT_POPUP_WIDTH, VCP_INPUT_POPUP_TITLE_HEIGHT);
    m_titleBg->setAutoAnimate(VFX_TRUE);

    // popup background
    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    m_background->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_BOTTOM));
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setIsCached(VFX_TRUE);
    m_background->setPos(0, VCP_INPUT_POPUP_TITLE_HEIGHT);
    m_background->setAutoAnimate(VFX_TRUE);

    // title frame
    VFX_OBJ_CREATE(m_titleFrame, VfxTextFrame, this);
    m_titleFrame->setString(m_title);
    m_titleFrame->setRect(
        VCP_INPUT_POPUP_TITLE_X,
        VCP_INPUT_POPUP_TITLE_Y,
        VCP_INPUT_POPUP_WIDTH,
        VCP_INPUT_POPUP_TITLE_HEIGHT);
    m_titleFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_titleFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
   // m_titleFrame->setColor(VfxColor(255,255,255,255));
#ifdef __MMI_VUI_COSMOS_CP__
    m_titleFrame->setColor(VFX_COLOR_RES(CLR_COSMOS_INPUT_POPUP_TITLE_TXT));
#else
    m_titleFrame->setColor(VfxColor(255,255,255,255));
#endif
    m_titleFrame->setFullLineHeightMode(VFX_FALSE);
    m_titleFrame->setAnchor(0, 0.5f);
    m_titleFrame->setPos(0, (VCP_INPUT_POPUP_TITLE_HEIGHT + 1) / 2);
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_INPUT_POPUP_TITLE_FONT_SIZE);
    fontDesc.effect = VFX_FE1_9;
    m_titleFrame->setFont(fontDesc);
    m_titleFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_titleFrame->setAutoAnimate(VFX_TRUE);

    // inputbox
    VFX_OBJ_CREATE(m_inputbox[0], VcpTextEditor, this);
    m_inputbox[0]->setText(VFX_WSTR_EMPTY, VCP_INPUT_POPUP_INPUTBOX_MAX_CHARS);
    m_inputbox[0]->setBounds(VfxRect(
        0,
        0,
        VCP_INPUT_POPUP_INPUTBOX_WIDTH,
        VCP_INPUT_POPUP_INPUTBOX_HEIGHT));
    m_inputbox[0]->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_inputbox[0]->setHint(VFX_WSTR_EMPTY);
    m_inputbox[0]->setAutoAnimate(VFX_TRUE);
    m_inputbox[0]->m_signalTextChanged.connect(this, &VcpInputPopup::onTextChanged);
    // activate inputbox only when one group
    vfxPostInvoke0(this, &VcpInputPopup::activateInputbox);

    // Ok button
    VFX_OBJ_CREATE(m_okButton, VcpButton, this);
    m_okButton->setText(VFX_WSTR_RES(STR_GLOBAL_OK));
    m_okButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_okButton->m_signalClicked.connect(this, &VcpInputPopup::onButtonClick);
    m_okButton->setId(0);
    m_okButton->setAutoAnimate(VFX_TRUE);

    // Cancel button
    VFX_OBJ_CREATE(m_cancelButton, VcpButton, this);
    m_cancelButton->setText(VFX_WSTR_RES(STR_GLOBAL_CANCEL));
    m_cancelButton->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
    m_cancelButton->m_signalClicked.connect(this, &VcpInputPopup::onButtonClick);
    m_cancelButton->setStyle(VCP_BUTTON_STYLE_GREY);
    m_cancelButton->setId(1);
    m_cancelButton->setAutoAnimate(VFX_TRUE);

    checkUpdate();
}


void VcpInputPopup::onUpdate()
{   
    VfxS32 i = 0;
    VfxS32 xPos = VCP_INPUT_POPUP_LR_GAP;
    VfxS32 yPos = VCP_INPUT_POPUP_TITLE_Y + VCP_INPUT_POPUP_TITLE_HEIGHT + VCP_INPUT_POPUP_TD_GAP;
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

    VfxS32 popupWidth;
    if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
    {
        popupWidth = VCP_INPUT_POPUP_WIDTH;
    }
    else
    {
        popupWidth = VCP_INPUT_POPUP_LANDSCAPE_WIDTH;
    }
    VfxS32 contentWidth = (popupWidth - 2 * VCP_INPUT_POPUP_LR_GAP);

    // resize title
    m_titleBg->setSize(popupWidth, VCP_INPUT_POPUP_TITLE_HEIGHT);
    m_titleFrame->setSize(popupWidth, VCP_INPUT_POPUP_TITLE_HEIGHT);

    // disable ok button if inputbox is empty
	setOkBtnState();
    // set group element pos (hint text, inputbox, error text)
    for (i = 0; i < m_groupNum; i++)
    {
        // show hint text only when more than one group
        if (m_groupNum > 1)
        {
            if (!m_hintText[i].isEmpty())
            {
                if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
                {
                    m_hintTextFrame[i]->setMaxLines(VCP_INPUT_POPUP_HINT_TEXT_MAX_LINE);
                }
                else
                {
                    // only display one line in landscape mode
                    m_hintTextFrame[i]->setMaxLines(1);
                }
                m_hintTextFrame[i]->setSize(contentWidth, 0);
                m_hintTextFrame[i]->setPos(xPos, yPos);
                yPos += (m_hintTextFrame[i]->getBounds().getHeight() + VCP_INPUT_POPUP_TD_GAP);
            }
            else
            {
                VFX_OBJ_CLOSE(m_hintTextFrame[i]);
            }
        }
        else
        {
            VFX_OBJ_CLOSE(m_hintTextFrame[i]);
        }
        m_inputbox[i]->setPos(xPos, yPos);
        m_inputbox[i]->setSize(contentWidth, VCP_INPUT_POPUP_INPUTBOX_HEIGHT);
        yPos += (VCP_INPUT_POPUP_INPUTBOX_HEIGHT + VCP_INPUT_POPUP_TD_GAP);
        if (!m_errorText[i].isEmpty())
        {
            if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
            {
                m_errorTextFrame[i]->setMaxLines(VCP_INPUT_POPUP_ERROR_TEXT_MAX_LINE);
            }
            else
            {
                // only display one line in landscape mode
                m_errorTextFrame[i]->setMaxLines(1);
            }
            m_errorTextFrame[i]->setPos(xPos, yPos);
            m_errorTextFrame[i]->setSize(contentWidth, 0);
            yPos += (m_errorTextFrame[i]->getBounds().getHeight() + VCP_INPUT_POPUP_TD_GAP);
        }
    }

    // set button pos
    VfxS32 buttonWidth = ((contentWidth - VCP_INPUT_POPUP_BUTTON_GAP) / 2);

    m_okButton->setInnerRect(VfxRect(
        VCP_INPUT_POPUP_LR_GAP,
        yPos,
        buttonWidth,
        VCP_INPUT_POPUP_BUTTON_HEIGHT));
    m_cancelButton->setInnerRect(VfxRect(
        VCP_INPUT_POPUP_LR_GAP + buttonWidth + VCP_INPUT_POPUP_BUTTON_GAP,
        yPos,
        buttonWidth,
        VCP_INPUT_POPUP_BUTTON_HEIGHT));

    yPos += VCP_INPUT_POPUP_BUTTON_HEIGHT + VCP_INPUT_POPUP_BOTTOM_GAP;

    // set background bounds
    m_background->setBounds(0, 0, popupWidth, yPos - VCP_INPUT_POPUP_TITLE_HEIGHT);

    if(m_contentHeight != -1)
    {
	  if(getBounds().getHeight() != yPos)
	  {
	  	resetPosition(yPos);
	  }
    }
    // set Popup bounds
    setBounds(0, 0, popupWidth, yPos);
}


void VcpInputPopup::setGroupNum(VfxU8 num)
{
    if (m_groupNum != num)
    {
        m_groupNum = VFX_MIN(VCP_INPUT_POPUP_MAX_GROUP_NUM, num);

        for (VfxS32 i = 0; i < m_groupNum; i++)
        {
            if (m_inputbox[i] == NULL)
            {
                VFX_OBJ_CREATE(m_inputbox[i], VcpTextEditor, this);
                m_inputbox[i]->setText(VFX_WSTR_EMPTY, VCP_INPUT_POPUP_INPUTBOX_MAX_CHARS);
                m_inputbox[i]->setBounds(VfxRect(
                    0,
                    0,
                    VCP_INPUT_POPUP_INPUTBOX_WIDTH,
                    VCP_INPUT_POPUP_INPUTBOX_HEIGHT));
                m_inputbox[i]->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
                m_inputbox[i]->setHint(VFX_WSTR_EMPTY);
                m_inputbox[i]->setAutoAnimate(VFX_TRUE);
                m_inputbox[i]->m_signalTextChanged.connect(this, &VcpInputPopup::onTextChanged);
            }
            m_inputbox[i]->setAutoActivated(VFX_FALSE);
        }
    }
}

void VcpInputPopup::setOkBtnState()
{
	if (!m_isAllowdEmptyContent)
    {
        VfxBool isDisable = VFX_FALSE;
        for (VfxS32 i = 0; i < m_groupNum; i++)
        {
            if (m_inputbox[i] != NULL && (m_inputbox[i]->getLength() == 0))
            {
				isDisable = VFX_TRUE;
                break;
            }
        }
		m_okButton->setIsDisabled(isDisable);
        
    }
    else
    {
        m_okButton->setIsDisabled(VFX_FALSE);
    }

}
void VcpInputPopup::onTextChanged(VcpTextEditor *inputbox)
{
	setOkBtnState();
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
}


void VcpInputPopup::activateInputbox()
{
 /*   if (m_groupNum == 1)*/
    {
        m_inputbox[0]->setAutoActivated(VFX_TRUE);
    }
}

/* vaib mem reduction*/
void VcpInputPopup::setTitle(VfxResId title_id)
{
	setTitle(VFX_WSTR_RES(title_id));
}

/* vaib mem reduction*/
void VcpInputPopup::setTitle(const VfxWChar* title_buf)
{
	setTitle(VFX_WSTR_MEM(title_buf));
}

void VcpInputPopup::setTitle(const VfxWString &title)
{
    if (m_title != title)
    {
        if (m_titleFrame)
        {
            m_titleFrame->setString(title);
            m_title = title;
            checkUpdate();
        }
    }
}


/* vaib mem reduction*/
void VcpInputPopup::setHintText(VfxResId text_id, VfxU8 index)
{
	setHintText(VFX_WSTR_RES(text_id),index);
}

/* vaib mem reduction*/
void VcpInputPopup::setHintText(const VfxWChar* text_buf, VfxU8 index)
{
	setHintText(VFX_WSTR_MEM(text_buf),index);
}

void VcpInputPopup::setHintText(const VfxWString &text, VfxU8 index)
{
    if (index > (m_groupNum - 1))
    {
        return;
    }

    if (m_hintText[index] != text)
    {
        m_hintText[index] = text;
        if (m_hintTextFrame[index] == NULL)
        {
            VFX_OBJ_CREATE(m_hintTextFrame[index], VfxTextFrame, this);
            m_hintTextFrame[index]->setSize(VCP_INPUT_POPUP_TEXT_WIDTH, 0);
#ifdef __MMI_VUI_COSMOS_CP__
            m_hintTextFrame[index]->setColor(VFX_COLOR_RES(CLR_COSMOS_INPUT_POPUP_HINT_TXT));			
#else	
            m_hintTextFrame[index]->setColor(VfxColor(255,15,15,15));
#endif

            m_hintTextFrame[index]->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
            m_hintTextFrame[index]->setMaxLines(VCP_INPUT_POPUP_HINT_TEXT_MAX_LINE);
            m_hintTextFrame[index]->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            VfxFontDesc fontHintDesc;
            fontHintDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_INPUT_POPUP_HINT_FONT_SIZE);
            m_hintTextFrame[index]->setFont(fontHintDesc);
        }
        m_hintTextFrame[index]->setString(text);
        checkUpdate();
    }
}


/* vaib mem reduction*/
void VcpInputPopup::setErrorText(VfxResId text_id, VfxU8 index)
{
	setErrorText(VFX_WSTR_RES(text_id),index);
}

/* vaib mem reduction*/
void VcpInputPopup::setErrorText(const VfxWChar* text_buf, VfxU8 index)
{
	setErrorText(VFX_WSTR_MEM(text_buf),index);
}

void VcpInputPopup::setErrorText(const VfxWString &text, VfxU8 index)
{
    if (index > (m_groupNum - 1))
    {
        return;
    }

    if (m_errorText[index] != text)
    {
        m_errorText[index] = text;
        if (m_errorTextFrame[index] == NULL)
        {
            VFX_OBJ_CREATE(m_errorTextFrame[index], VfxTextFrame, this);
            m_errorTextFrame[index]->setSize(VCP_INPUT_POPUP_TEXT_WIDTH, 0);
#ifdef __MMI_VUI_COSMOS_CP__
            m_errorTextFrame[index]->setColor(VFX_COLOR_RES(CLR_COSMOS_INPUT_POPUP_ERR_TXT));
#else
            m_errorTextFrame[index]->setColor(VfxColor(255,168,0,0));
#endif
            m_errorTextFrame[index]->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
            m_errorTextFrame[index]->setMaxLines(VCP_INPUT_POPUP_ERROR_TEXT_MAX_LINE);
            m_errorTextFrame[index]->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            VfxFontDesc fontHintDesc;
            fontHintDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_INPUT_POPUP_ERROR_FONT_SIZE);
            m_errorTextFrame[index]->setFont(fontHintDesc);
        }
        m_errorTextFrame[index]->setString(text);
        checkUpdate();
    }
}


/* vaib mem reduction*/
void VcpInputPopup::setText(VfxResId text_id, VfxS32 maxLen, VfxBool isStaticBuf, VfxU8 index)
{
	setText(VFX_WSTR_RES(text_id), maxLen, isStaticBuf, index);
}

/* vaib mem reduction*/
void VcpInputPopup::setText(const VfxWChar* text_buf, VfxS32 maxLen, VfxBool isStaticBuf, VfxU8 index)
{
	setText(VFX_WSTR_MEM(text_buf), maxLen, isStaticBuf, index);
}

void VcpInputPopup::setText(const VfxWString &text, VfxS32 maxLen, VfxBool isStaticBuf, VfxU8 index)
{
    if (index > (m_groupNum - 1))
    {
        return;
    }

    m_inputbox[index]->setText(text, maxLen, isStaticBuf);
    checkUpdate();
}


void VcpInputPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    m_signalButtonClicked.emit(this, (VcpInputPopupButtonEnum)id);
}


void VcpInputPopup::setIME(VfxU64 inputType, InputSettingEnum inputSetting, VfxU8 index)
{
    if (index > (m_groupNum - 1))
    {
        return;
    }

    m_inputbox[index]->setIME(inputType, inputSetting);
}


void VcpInputPopup::onRotate(const VfxScreenRotateParam &param)
{
   // processUpdate();
    if (!m_orgImePoint.isZero())
    {
        m_orgImePoint.setZero();
    }

    VfxPoint pos = getPos();

    checkUpdate();
    VfxBasePopup::onRotate(param);

    if ((param.rotateFrom == VFX_SCR_ROTATE_TYPE_90 && param.rotateTo == VFX_SCR_ROTATE_TYPE_270) ||
        (param.rotateFrom == VFX_SCR_ROTATE_TYPE_270 && param.rotateTo == VFX_SCR_ROTATE_TYPE_90))
    {
        // when rotate, the popup will reset to mid pos
        // so in this case, restore it.
        setPos(pos);
    }
}


VfxBool VcpInputPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {

        m_signalButtonClicked.emit(this, VCP_INPUT_POPUP_BTN_CANCEL);
        return VFX_TRUE;
    }

    return VfxBasePopup::onKeyInput(event);
}

void VcpInputPopup::onObjectNotify(VfxId id, void *userData)
{
	switch (id)
	{
		case VFX_FRAME_NOTIFY_ID_QUERY_IME_MODE:
		{
			*(VfxFrameImeModeEnum*)userData = VFX_FRAME_IME_MODE_SHIFT;
			return;

		}
		default:
		{
			VfxBasePopup::onObjectNotify(id, userData);
			return;
		}
	}
}

void VcpInputPopup::setIMElayout(VfxRect &imeRect, VfxFrame *imeOwner)
{
	m_contentHeight = imeRect.origin.y;	

    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    VfxS32 midX = mainScreenSize.width / 2;

    if (m_orgImePoint.isZero())
    {
        m_orgImePoint = getPos();
        // handle rotate case
        if (m_orgImePoint.x != midX)
        {
            m_orgImePoint.x = midX;
            m_orgImePoint.y = mainScreenSize.height / 2;
        }
    }
    
    cancelEffect();
    resetPosition(getBounds().getHeight());
    checkUpdate();
}


void VcpInputPopup::resetIMElayout()
{
    if (!m_orgImePoint.isZero())
    {
        setPos(m_orgImePoint);
        m_orgImePoint.setZero();
    }
	m_contentHeight = -1;
}


void VcpInputPopup::show(VfxBool isAnim)
{
    // disable inputpopup enter animation
  /*  if (m_groupNum == 1)*/
    {
        VfxBasePopup::show(VFX_FALSE);
    }
    /*else
    {
        VfxBasePopup::show(isAnim);
    }*/
}


void VcpInputPopup::onEnter()
{
    if (getPos().isZero())
    {
        VfxBasePopup::onEnter();
    }
    else
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        
        setHidden(VFX_FALSE);

    //    setPos(m_targetScreen->getBounds().getMidPoint());

        VfxAutoAnimate::commit();
    }
}

void VcpInputPopup::resetPosition(VfxS32 popupHeight)
{
    VfxS32 heightDiff = m_contentHeight - popupHeight;

    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    VfxS32 midX = mainScreenSize.width / 2;

    
    if (heightDiff >= 0)
    {
        // center align to top area
        setPos(midX, m_contentHeight / 2);
    }
    else
    {
        if (m_groupNum == 1)
        {
            setPos(midX, popupHeight / 2);
        }
        else if (m_groupNum == 2)
        {
            if (m_inputbox[0]->isActive())
            {
                // top align
                setPos(midX, popupHeight / 2);
            }
            else
            {
                // bottom align
                setPos(midX, (popupHeight / 2 + heightDiff));
            }
        }
    }
}
