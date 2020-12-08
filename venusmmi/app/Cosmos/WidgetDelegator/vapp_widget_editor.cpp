/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  
 *
 * Project:
 * --------
 *  Venus UI
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"
#ifdef __MMI_GADGET_SUPPORT__
#include "vfx_uc_include.h"
#include "vcp_include.h"

#include "vapp_widget_editor.h"
#include "vapp_widget_adp.h"
#include "vapp_widget_popup_controller.h"
#include "mmi_rp_vapp_widget_delegator_def.h"
#include "GlobalResDef.h"

#include "vapp_widget_delegator.h"
#include "vapp_widget_view.h"

extern VappWidgetEditorManager *g_manager;
VfxWChar VappWidgetEditorPage::m_inputBuffer[TEXT_MAX_INPUT_LEN + 1] = {0}; 

extern "C" void vapp_widget_editor_send_response(void *local_para_ptr, void *peer_buff_ptr, msg_type ilm_id, module_type dst_id);
extern VfxU32 vapp_widget_editor_transform_method(int type, short pwd);

/***************************************************************************** 
 * Implementation
 *****************************************************************************/
//MyTextEditorScr Implementation
VFX_IMPLEMENT_CLASS("VappWidgetEditor", VappWidgetEditor, VfxControl);

VappWidgetEditor::VappWidgetEditor() : 
    m_multilineEditor(NULL),
    m_initHeight(TEXT_EDITOR_MULTILINE_HEIGHT)
{
    m_size = VfxSize(0, 0);
    m_alignH = 0;
    m_stringLength = TEXT_DEFAULT_INPUT_LEN;
}


VappWidgetEditor::VappWidgetEditor(
    VfxS32 editorType, 
    VfxWChar *str, 
    VfxS32 len, 
    VfxU64 inputType, 
    VfxU32 inputSetting,
    VfxBool isDetailsView) : 
    m_multilineEditor(NULL),
    m_initHeight(TEXT_EDITOR_MULTILINE_HEIGHT)
{
    m_size = VfxSize(0, 0);
    m_editorType = editorType;
    m_stringBuffer = str;
    m_stringLength = len;
    m_inputType = inputType;
    m_inputSetting = inputSetting;
    m_isDetailsView = isDetailsView;
}


VfxWChar* VappWidgetEditor::getInputText()
{
    memcpy(m_stringBuffer, m_multilineEditor->getText(), m_stringLength * sizeof(VfxWChar));

    return (VfxWChar *)m_stringBuffer;
}


void VappWidgetEditor::onInit()
{
	VfxControl::onInit();

    VfxS32 xPos, yPos;
    VfxS32 height = 0;
    VcpTextLineModeEnum mode;

    if (m_editorType)							// multiline
    {
        height = TEXT_EDITOR_MULTILINE_HEIGHT;
        mode = VCP_TEXT_LINE_MODE_MULTI;
    }
    else
    {
        height = TEXT_EDITOR_SINGLE_HEIGHT;      //adjust height or not?
        mode = VCP_TEXT_LINE_MODE_SINGLE;        
	}
    
    // Set size of page grid
    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    // set category size
    xPos = LCD_INITIAL_X;
    yPos = mainScreenSize.height + 1;
    setRect(VfxRect(xPos, yPos, mainScreenSize.width, mainScreenSize.height));
    setFocused(VFX_TRUE);
    setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_bgImage, VfxImageFrame, this);  
    addChildFrame(m_bgImage);
    m_bgImage->setResId(IMG_ID_VAPP_WIDGET_TEXT_BACKGROUND);
    m_bgImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bgImage->setSize(getSize());

    // multiple line text editor
    xPos = TEXT_VIEW_GAP_HORIZONTAL;
    yPos = TEXT_VIEW_GAP_VERTICAL;

	VFX_OBJ_CREATE(m_multilineEditor, VcpTextEditor, this);
    addChildFrame(m_multilineEditor);
	m_multilineEditor->setPos(xPos, yPos);
	m_multilineEditor->setText(m_stringBuffer, m_stringLength);
    m_multilineEditor->setSize(mainScreenSize.width - 3 * TEXT_VIEW_GAP_HORIZONTAL - TEXT_EDITOR_BUTTON_W, height);
    m_multilineEditor->setLineMode(mode);
    m_multilineEditor->hideCounter(VFX_TRUE);
    m_multilineEditor->setAutoActivated(VFX_TRUE);
    m_initHeight = ((m_multilineEditor->getLineCount() < 2) ? TEXT_EDITOR_SINGLE_HEIGHT : TEXT_EDITOR_MULTILINE_HEIGHT);

    VsrvInputBinding inputBinding(m_inputType, m_inputSetting, 0, m_multilineEditor->m_editing);
    m_multilineEditor->setIME(inputBinding);

	// save button
	xPos = LCD_WIDTH - TEXT_VIEW_GAP_HORIZONTAL- TEXT_EDITOR_BUTTON_W;
    
	VFX_OBJ_CREATE(m_saveButton, VcpButton, this);
	m_saveButton->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
	m_saveButton->setPos(xPos, yPos);
    addChildFrame(m_saveButton);

    m_saveButton->setBgImageList(VcpStateImage(IMG_ID_VAPP_WIDGET_TEXT_BTN_N));
    m_saveButton->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
	m_saveButton->setId(BUTTON_TYPE_SAVE);
	m_saveButton->setSize(TEXT_EDITOR_BUTTON_W,  height);
    m_saveButton->m_signalClicked.connect(this, &VappWidgetEditor::onButtonClicked);

}

void VappWidgetEditor::onDeinit()
{
    if (m_bgImage)
    {
        VFX_OBJ_CLOSE(m_bgImage);
    }

    if (m_multilineEditor)
    {
        VFX_OBJ_CLOSE(m_multilineEditor);
    }

    VfxControl::onDeinit();
}

VfxBool VappWidgetEditor::onPenInput(VfxPenEvent &event)
{
    return VFX_TRUE;
}

VfxBool VappWidgetEditor::onKeyInput(VfxKeyEvent &event)
{
    if (m_isDetailsView == VFX_FALSE 
        && event.keyCode == VFX_KEY_CODE_HOME 
        && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (m_saveButton)
        {
            m_signalClosed.postEmit(m_saveButton);
        }
        else 
        {
            m_signalClosed.postEmit(NULL);
        }

        return VFX_TRUE;
    }

    return VfxControl::onKeyInput(event);
}

void VappWidgetEditor::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_FRAME_NOTIFY_ID_QUERY_IME_MODE:
        {
            VfxFrameImeModeEnum ret = getImeMode();
            *((VfxFrameImeModeEnum *)userData) = ret;
            return;
        }
        case VFX_FRAME_NOTIFY_ID_ADJUST_IME_SHIFT:
        {
            VfxFrameAdjustImeShiftData *data = (VfxFrameAdjustImeShiftData *)userData;
            adjustImeShift(data->pos, data->focusFrame);
            return;
        }       
        default:
        {
            VfxControl::onObjectNotify(id, userData);
            return;
        }
    }
}

void VappWidgetEditor::adjustImeShift (const VfxPoint &pos, VfxFrame *focusFrame)
{
    VfxAutoAnimate::initAnimateBegin();

	vrt_size_struct mainScreenSize;
	vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

	if (pos.y < getPos().y)
	{
        VfxU32 adjustHeight = ((m_editorType == 0) ? TEXT_VIEW_GAP_VERTICAL : (TEXT_EDITOR_MULTILINE_HEIGHT - m_initHeight + TEXT_VIEW_GAP_VERTICAL * 2));
		setPos(pos.x, (VfxS32)pos.y - adjustHeight);
	}
	else if (pos.y == mainScreenSize.height + 1)
	{
		setPos(pos.x, pos.y);

        if (m_saveButton)
        {
            m_signalClosed.postEmit(m_saveButton);
        }
        else 
        {
            m_signalClosed.postEmit(NULL);
        }
	}
    
    VfxAutoAnimate::initAnimateEnd();
}


void VappWidgetEditor::onButtonClicked(VfxObject *sender, VfxId id)
{
    if (sender)
    {
        VcpButton *button = VFX_OBJ_DYNAMIC_CAST(sender, VcpButton);

        m_saveButton->setBgImageList(VcpStateImage(IMG_ID_VAPP_WIDGET_TEXT_BTN_P));
        
        m_signalClosed.postEmit(button);
    }
}





/***************************************************************************** 
 * Implementation
 *****************************************************************************/
//MyTextEditorScr Implementation
VFX_IMPLEMENT_CLASS("VappWidgetEditorPage", VappWidgetEditorPage, VfxPage);

VappWidgetEditorPage::VappWidgetEditorPage()
{
}

void VappWidgetEditorPage::onInit()
{
    VfxPage::onInit(); // call base class
    setBgColor(VFX_COLOR_WHITE);
         
    VFX_OBJ_CREATE(m_titleBar, VcpTitleBar, this);
    m_titleBar->setTitle(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_DOWNLOADED_WIDGETS)); //set title text
    setTopBar(m_titleBar.get());  

    VFX_OBJ_CREATE(m_toolBar, VcpToolBar, this);
    setBottomBar(m_toolBar.get());	
    m_toolBar->addItem(OK_BUTTON, VFX_WSTR_RES(VCP_STR_TOOL_BAR_OK), VCP_IMG_TOOL_BAR_COMMON_ITEM_OK);
    m_toolBar->addItem(CANCEL_BUTTON, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL), VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL);	
    m_toolBar->m_signalButtonTap.connect(this, &VappWidgetEditorPage::onToolBarTapped);
}

void VappWidgetEditorPage::onDeinit()
{
    if (m_titleBar.get() && m_titleBar.isValid())
    {
        VFX_OBJ_CLOSE(m_titleBar);
    }

    if (m_toolBar.get() && m_toolBar.isValid())
    {
        VFX_OBJ_CLOSE(m_toolBar);
    }

    if (m_textEditor.get() && m_textEditor.isValid())
    {
        VFX_OBJ_CLOSE(m_textEditor);
    }

    if (m_FunctionBar.get() && m_FunctionBar.isValid())
    {
        VFX_OBJ_CLOSE(m_FunctionBar);
    }

    if (m_widgetName)
    {
        OslMfree(m_widgetName);
    }

    VfxPage::onDeinit();
}

void VappWidgetEditorPage::createEditor(widget_enter_text_ind_struct *param)
{
    VfxU32 inputMethod;
    VfxS32 editorType = 0;

    m_bufferLen = ((param->length) > (TEXT_MAX_INPUT_LEN - 1)) ? (TEXT_MAX_INPUT_LEN - 1) : (param->length);

    memset(m_inputBuffer, 0, sizeof(m_inputBuffer));    

    if (param->length)
    {
        memcpy(m_inputBuffer, param->text, m_bufferLen * sizeof(VfxWChar));
    }

    m_instanceId = param->instance_id;
    m_passwordField = param->password_field;
    editorType = param->multiline;        //0: single line, 1: multi-line

    inputMethod = vapp_widget_editor_transform_method(param->type, param->password_field);

    m_widgetName = (VfxWChar *)OslMalloc(sizeof(VfxWChar) * (WIDGET_MAX_NAME_LENGTH + 1));
    if (m_widgetName)
    {
        memset(m_widgetName, 0, (WIDGET_MAX_NAME_LENGTH + 1));
    }
  
    srv_wgtmgr_get_downloaded_wgt_name(m_instanceId, m_widgetName, sizeof(VfxWChar) * WIDGET_MAX_NAME_LENGTH);
    m_titleBar->setTitle(VFX_WSTR_MEM(m_widgetName));

    VFX_OBJ_CREATE(m_textEditor, VcpTextEditor , this);
    m_textEditor->setPos(0,0);  
    m_textEditor->setText(m_inputBuffer, m_bufferLen);
    m_textEditor->setSize(getSize().width, getSize().height);
    m_textEditor->setMargins(TEXT_EDITOR_VIEW_MARGIN, 0, TEXT_EDITOR_VIEW_MARGIN, TEXT_EDITOR_VIEW_MARGIN);
    m_textEditor->setUnderline(VFX_TRUE);
    m_textEditor->setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE, 
        VFX_FRAME_ALIGNER_MODE_SIDE);
    m_textEditor->setMinLineHeight(TEXT_EDITOR_LINE_GAP);
    m_textEditor->hideCounter(VFX_TRUE);
    m_textEditor->setLineMode(VCP_TEXT_LINE_MODE_MULTI); //always show multiline layout

    if (!editorType) //single line - disable new line symbol
    {
        VsrvInputBinding inputBinding(inputMethod, IME_DISABLE_NEW_LINE_SYMBOL, 0, m_textEditor->m_editing);
        m_textEditor->setIME(inputBinding);        
    }
    else            //multiline
    {
        VsrvInputBinding inputBinding(inputMethod, IME_SETTING_FLAG_NONE, 0, m_textEditor->m_editing);
        m_textEditor->setIME(inputBinding);     
    }

	VFX_OBJ_CREATE(m_FunctionBar, VcpFunctionBar, this);
	m_FunctionBar->addItem(CANCEL_BUTTON, VFX_WSTR_RES(VCP_STR_TOOL_BAR_CANCEL));
	m_FunctionBar->addItem(OK_BUTTON, VFX_WSTR_RES(VCP_STR_TOOL_BAR_OK));
	m_FunctionBar->setItemSpecial(OK_BUTTON);
	m_textEditor->setFunctionBar(m_FunctionBar.get());
	m_FunctionBar->m_signalButtonTap.connect(this, &VappWidgetEditorPage::onToolBarTapped);

    m_textEditor->setAutoActivated(VFX_TRUE);

}

void VappWidgetEditorPage::onToolBarTapped(VfxObject *obj, VfxId id)
{
    switch (id)
    {
        case OK_BUTTON:
            vapp_widget_handle_enter_text_response(m_viewHandle, VFX_TRUE, m_textEditor->getText());

            vapp_widget_close_editor_by_id(0);

            break;
        case CANCEL_BUTTON:
            vapp_widget_close_editor_by_id(0);

            break;
        default:
            VFX_ASSERT(0);
    }
}

#endif
