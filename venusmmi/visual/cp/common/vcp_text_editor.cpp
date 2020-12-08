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
 *  vcp_text_editor.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  text editor class
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "Vcp_text_editor.h"
#include "mmi_rp_srv_venus_component_text_view_def.h"
#if defined(__COSMOS_MMI_PACKAGE__)
#include "mmi_rp_app_cosmos_global_def.h"
#include "vcp_info_balloon.h"
#endif
#include "mmi_rp_srv_editor_def.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_text_view.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_signal.h"
#include "vcp_text_utils.h"
#include "vcp_text_storage.h"
#include "vfx_string.h"
#include "vsrv_input_manager.h"
#include "vfx_input_event.h"
#include "vfx_image_src.h"
#include "vfx_basic_type.h"
#include "vfx_control.h"
#include "vfx_frame.h"
#include "vfx_timer.h"
#include "vrt_datatype.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
    
extern "C"
{
#include "ImeGprot.h"
#include "gui_switch.h"
#include "gui_config.h"
#include "gui.h"
#include "wgui_inputs.h"
#include "ScrLockerGprot.h"
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)
#include "IndicEngineGprot.h"
#endif
}

/*
SWLA labels:
TE1    VcpTextEditor::onInit
TE2    VcpTextEditor::activateInternal
TEI    VcpEditing::insertText
TED    VcpEditing::deleteChars
TEC    VcpTextCursor::setIndex
TEM    IME activate

TV1    VcpTextView::onInit
TV2    VcpTextView::onUpdate
TV3    VcpTextView::onLayoutChanged
TVU    VcpTextView::forceUpdate
TVD    VcpTextCellView::onDraw

TLD    VcpTextBasicLayout::draw
TLU    VcpTextBasicLayout::updateLayout
TL1    VcpTextSingleLineLayout::layout
TL2    VcpTextStaticLayout::layout
TL3    VcpTextDynamicLayout::layout

TS1    VcpTextStorage::insertText
TS2    VcpTextStorage::deleteText
TS3    VcpTextStorage::getIconObject
TS4    VcpTextStorage::getKeyword

TU1    VcpTextUtils::getTextMetrics
*/
#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

extern "C"
{
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif
}

#if defined(__MMI_MAINLCD_480X800__)
#define VCP_TEXT_EDITOR_FUNCTION_BAR_SHADOW     4
#else
#define VCP_TEXT_EDITOR_FUNCTION_BAR_SHADOW     2
#endif

#define VCP_TEXT_EDITOR_CURSOR_BLINK_TIME   500

#define VCP_TEXT_INJECT_STRING_TO_MODULE_MAX_LENGTH 128
#define VCP_TEXT_INJECT_STRING_TO_MODULE_UNICODE_UNDONE_INDEX 10
#define VCP_TEXT_INJECT_STRING_TO_MODULE_UNICODE_DONE_INDEX 11
#define VCP_TEXT_INJECT_STRING_TO_MODULE_ASCII_UNDONE_INDEX 12
#define VCP_TEXT_INJECT_STRING_TO_MODULE_ASCII_DONE_INDEX 13
extern "C"
{
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))
extern U8 mtkmultitap_ire_bengali_ndicator;
static U8 to_decide_to_reshuffle_inline = 0;
#endif
}
/***************************************************************************** 
 * Class VcpTextEditor
 *****************************************************************************/

VcpTextEditor *VcpTextEditor::s_activateEditor = NULL;

VFX_IMPLEMENT_CLASS(VCP_EDITOR_CLASS_NAME, VcpTextEditor, VcpTextView);

VcpTextEditor::VcpTextEditor()
{
    m_counter = NULL;
    m_leftMargin = m_rightMargin = (VCP_TEXTVIEW_DEFAULT_MARGIN + VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN);
    m_topMargin = m_bottomMargin = (VCP_TEXTVIEW_DEFAULT_MARGIN + VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN);
    m_isDisableBg = VFX_FALSE;
    m_enableDeleteButton = VFX_FALSE;
    m_deleteButton = NULL;
    m_autoDeactivated = VFX_FALSE;
    m_autoActivated = VFX_FALSE;
    m_autoCloseFunctionBar = VFX_TRUE;
    m_freezActiveState = VFX_FALSE;
    m_history = NULL;
    m_imeHistory = NULL;
    m_counterDispMode = VCP_TEXT_COUNTER_DISP_AUTO;
    m_isTextReady = VFX_TRUE;
    m_isHideCursor = VFX_FALSE;
    m_isDeactivateWhenHideVK = VFX_FALSE;
	m_isShowIMEPopup = VFX_FALSE;
}


void VcpTextEditor::onInit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TE1", SA_start);
#endif
    VcpTextView::onInit();

    VFX_OBJ_CREATE(m_editing, VcpEditing, this);

    m_editing->m_signalTextChanged.connect(this, &VcpTextEditor::onTextChanged);
    m_editing->m_signalActivated.connect(this, &VcpTextEditor::onActived);
    m_editing->m_signalBeforeChange.connect(this, &VcpTextEditor::onBeforeTextChange);
    m_editing->m_signalEnterKeyClicked.connect(this, &VcpTextEditor::onEnterKeyClicked);

    m_editing->attachTo(this);

    m_editing->getCursor()->m_signalCursorIndexChanged.connect(this, &VcpTextEditor::onCursorIndexChanged);

    VFX_OBJ_CREATE(m_counter, VcpTextCounter, this);
    m_counter->setOwner(this);

    counterFPEData userData;

    userData.viewObjHandle = m_view->getObjHandle();
    userData.editorObjHandle = getObjHandle();

    m_counter->setPropertyEffectCallback(
        this,
        &VcpTextEditor::framePropertyEffectCallback,
        &userData,
        sizeof(counterFPEData),
        VRT_FPE_TRIGGER_TYPE_EVERYTIME);

    // create history buffer
    VFX_ALLOC_MEM(m_history, sizeof(VcpTextEditorHistoryStruct), this);
    memset(m_history, 0, sizeof(VcpTextEditorHistoryStruct));

    // for direct input from MODIS/test module
    //wgui_inputs_set_current_input_box_type(EDITOR_MULTILINE_INPUT_BOX);

    // sort cursor to top
    setIsZSortChild(VFX_TRUE);
    m_counter->setPosZ(-1.0);

#if VCP_TEXT_CLIPBOARD_SUPPORT
    if (m_clipboard)
    {
        m_clipboard->m_signalClipboardEvent.connect(this, &VcpTextEditor::onClipboardEvent);
    }
#endif

#if defined(__COSMOS_MMI_PACKAGE__)
    // set theme color
    setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_RES(VCP_COL_TEXT_VIEW_NRML_TEXT));
    setColor(VCP_TEXT_HINT_TEXT_COLOR, VFX_COLOR_RES(VCP_COL_TEXT_VIEW_HINT_TEXT));
    setColor(VCP_TEXT_UNDERLINE_COLOR, VFX_COLOR_RES(VCP_COL_TEXT_VIEW_UNDERLINE));
#endif

#ifdef __COSMOS_3D_V10__
    // disable boundary light by default because of the editor background image
    // we'll turn on it if application disable editor background or set other bg image
    enableBoundaryLight(VFX_FALSE);
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TE1", SA_stop);
#endif
}


#if VCP_TEXT_CLIPBOARD_SUPPORT
void VcpTextEditor::onClipboardEvent(VfxCcpEventType type, VfxWChar** string, VfxS32 len, VfxS32 *ret_len)
{
    if (type == VFX_CCP_NOTIFY_HIDE_MENU)
    {
        // clear history selection
        if (m_history && m_history->isSaved)
        {
            m_history->selection.setRange(0, 0);
        }
    }
}
#endif


void VcpTextEditor::onPenEventProcessed(VfxPenEvent &event, VfxControl *control)
{
    if (event.type != VFX_PEN_EVENT_TYPE_DOWN || !control || !m_autoDeactivated || control == this)
    {
        return;
    }

    // if pen down on another editor, do not deactivate directly to avoid the VK flash.
    // the editor will be deactivated when activate editor
    // 1. if the control is editor's child mean it pen down on editor
    VfxFrame *iControl = NULL;
    for (iControl = control; iControl != NULL; iControl = iControl->getParentFrame())
    {
        VcpTextEditor *editor = VFX_OBJ_DYNAMIC_CAST(iControl, VcpTextEditor);
        if (editor)
        {
            return;
        }
    }
    // 2. if the hit frame is the child of editor, 
    // we use the same way as VfxPen::findHitControl
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
        VfxFrame *rootFrame = renderer->getRootFrame();
        VfxFrame *targetFrame = NULL;
        if (rootFrame != NULL)
        {
            VfxFrame *hitFrame = rootFrame->hitTest(event.pos);
            VfxFrame *i;

            // find the hit frame
            for (i = hitFrame; i != NULL; i = i->getParentFrame())
            {
                VfxControl *ctrl = VFX_OBJ_DYNAMIC_CAST(i, VfxControl);
                if (ctrl != NULL)
                {
                    targetFrame = ctrl;
                    break;
                }
            }

            // if the hit frame is editor's child mean it pen down on editor
            for (; targetFrame != NULL; targetFrame = targetFrame->getParentFrame())
            {
                VcpTextEditor *editor = VFX_OBJ_DYNAMIC_CAST(targetFrame, VcpTextEditor);
                if (editor)
                {
                    return;
                }
            }
        }
    }

    VfxPoint point = event.getRelPos(this);
            
    if (hitTest(point))
    {
        return;
    }

#if VCP_TEXT_CLIPBOARD_SUPPORT
    if (m_clipboard && m_clipboard->hitTest(event))
    {
        return;
    }
#endif
    if (getFunctionBar() != NULL)
    {
        VfxPoint fbPoint = event.getRelPos(getFunctionBar());
        
        if (getFunctionBar()->hitTest(fbPoint))
        {
            return;
        }
    }

    if (VFX_OBJ_GET_INSTANCE(VsrvInputManager)->isInputMethodUIControl(control))
    {
        return;
    }

    deactivate();
}


void VcpTextEditor::onRotated(VfxScreenRotateParam rotateParam)
{
    VFX_OBJ_GET_INSTANCE(VsrvInputManager)->rotate();
}


void VcpTextEditor::onRotateTo(VfxScreenRotateParam rotateParam)
{
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    topLevel->resetIMElayout();
    VFX_OBJ_GET_INSTANCE(VsrvInputManager)->beforeRotate();
}


void VcpTextEditor::onTextChanged(VcpTextView *view)
{
    if (m_deleteButton)
    {
        if (m_enableDeleteButton && getLength() > 0)
        {
            setMarginFrame(VCP_TEXT_MARGIN_FRAME_RIGHT, m_deleteButton);
        }
        else
        {
            removeMarginFrame(VCP_TEXT_MARGIN_FRAME_RIGHT, m_deleteButton);
        }
    }

    updateCounter(getMaxLength());

    if (m_isTextReady)
    {
        m_signalTextChanged.postEmit((VcpTextEditor *)view);
    }
}


void VcpTextEditor::onActived(VcpTextView *view, VfxBool active)
{
	if (!active)
	{
		// don't send deacitvate signal to app if it's entering IME popup and deactivate editor
		// In some app scenario, deactivate will be used as confirm input like main menu new/rename folder name
		if (!m_isShowIMEPopup)
		{
			m_signalActivated.postEmit((VcpTextEditor *)view, active);
		}
	}
	else
	{
		m_isShowIMEPopup = VFX_FALSE;
		m_signalActivated.postEmit((VcpTextEditor *)view, active);
	}
}


void VcpTextEditor::onBeforeTextChange(VfxWChar *text, VfxS32 curPos, VcpTextChangeEnum type, VfxBool *ret)
{
    m_signalBeforeChange.emit(text, curPos, type, ret);
}


void VcpTextEditor::onEnterKeyClicked(VcpTextView *editor, IMEVKEnterKeyStyleEnum style)
{
    m_signalEnterKeyClicked.postEmit(this, style);
}


void VcpTextEditor::onCursorIndexChanged(VcpTextCursor *cursor)
{
    m_signalCursorIndexChanged.emit(this, getCursorIndex());
}


void VcpTextEditor::onDeleteButtonClick(VfxObject *obj, VfxId id)
{
    activate();

    // reset IME state first then delete all
    if (m_editing->m_inputManager->isIMEState())
    {
        m_editing->m_inputManager->resetIMEState();
    }

    deleteAll();
}


void VcpTextEditor::onDeinit()
{
    deactivate();

    if (m_autoCloseFunctionBar)
    {
        VfxFrame *frame = getFunctionBar();

        if (frame)
        {
            VFX_OBJ_CLOSE(frame);
        }
    }

    if (m_deleteButton)
    {
        VFX_OBJ_CLOSE(m_deleteButton);
    }

    // for direct input from MODIS/test module
    //wgui_inputs_set_current_input_box_type(EDITOR_NONE_INPUT_BOX);
    VFX_FREE_MEM(m_history);
    VFX_FREE_MEM(m_imeHistory);
    
    VFX_OBJ_CLOSE(m_editing);
    VcpTextView::onDeinit();
}


void VcpTextEditor::setLineMode(VcpTextLineModeEnum mode)
{
    if (m_lineMode == mode)
    {
        return;
    }

    VcpTextView::setLineMode(mode);
    if (mode == VCP_TEXT_LINE_MODE_SINGLE && m_counter != NULL)
    {
        VFX_OBJ_CLOSE(m_counter);
    }

    // disable new line symbol in single line mode and enable in multi line mode
    VsrvInputBinding inputBinding = m_editing->m_inputBinding;
    if (mode == VCP_TEXT_LINE_MODE_MULTI)
    {
        VFX_OBJ_CLOSE(m_deleteButton);
        inputBinding.m_inputSettingFlags &= ~IME_DISABLE_NEW_LINE_SYMBOL;

        // TODO: enhance margin
        setMargins(0, VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN, 0, VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN);
    }
    else
    {
        inputBinding.m_inputSettingFlags |= IME_DISABLE_NEW_LINE_SYMBOL;

        // TODO: enhance margin
        // because in single line editor we always use vertical middle aligment to place the text
        // so to aviod the text area is too small due to margin, we set the top/down margin to 0
        setMargins(0, -VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN, 0, -VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN);
    }
    setIME(inputBinding);
}


void VcpTextEditor::hideCounter(VfxBool isHide)
{
    if (m_counter)
    {
        m_counter->setHidden(isHide);

        if (isHide)
        {
            setCounterDisplayMode(VCP_TEXT_COUNTER_DISP_HIDE);
        }
        else
        {
            setCounterDisplayMode(VCP_TEXT_COUNTER_DISP_SHOW);
        }
        checkUpdate();
    }
}


void VcpTextEditor::setCounterDisplayMode(VcpTextCounterDisplayModeEnum mode)
{
    if (mode != m_counterDispMode)
    {
        m_counterDispMode = mode;

		updateCounter(getMaxLength());

        checkUpdate();
    }
}


VfxS32 VcpTextEditor::setText(
    VfxWChar *text,
    VfxS32 maxLen,
    VfxBool isStaticBuf,
    VcpTextEncodingEnum type,
    VcpRichTextFormat *format)
{
    m_storage->setText(VFX_WSTR_STATIC(text), isStaticBuf, (VcpTextStorage::TextEncodingEnum)type, maxLen, format);

    // check cursor index validation in case the text changed
    VfxS32 curIndex = getCursorIndex();
    VfxS32 textLen = vfx_sys_wcslen(text);
    if (curIndex > textLen)
    {
        // set cursor to last position
        setCursorIndex(textLen);
    }

    if (m_editing && m_editing->m_inputManager && m_editing->m_inputManager->isIMEState())
    {
        m_editing->m_inputManager->resetIMEState();
    }

    // Clear highlight which is set for previous text
    // TODO: use a better way to clear highlight so that it will not clear highlight which is user set
    // For example: App first 1). setHighlight, then 2). setText, the highlight set in 1) will be cleared
    setHighlight(0, 0);

    // change history cursor index
    // should keep ime history
    if (m_history && m_history->isSaved)
    {
        m_history->cursorIndex = textLen;
        m_history->selection.setRange(0, 0);
    }

    return 0;
}


VfxS32 VcpTextEditor::changeText(
    VfxWChar *text,
    VfxS32 maxLen,
    VfxBool isStaticBuf,
    VcpTextEncodingEnum type,
    VcpRichTextFormat *format)
{
    VfxS32 retLen = 0;
    m_isTextReady = VFX_FALSE;
    retLen = setText(text, maxLen, isStaticBuf, type, format);
    m_isTextReady = VFX_TRUE;

    return retLen;
}


VfxS32 VcpTextEditor::setText(
    const VfxWString &text,
    VfxS32 maxLen,
    VfxBool isStaticBuf,
    VcpTextEncodingEnum type,
    VcpRichTextFormat *format)
{
    m_storage->setText(text, isStaticBuf, (VcpTextStorage::TextEncodingEnum)type, maxLen, format);

    // check cursor index validation in case the text changed
    VfxS32 curIndex = getCursorIndex();
    VfxS32 textLen = text.getLength();
    if (curIndex > textLen)
    {
        // set cursor to last position
        setCursorIndex(textLen);
    }

    if (m_editing && m_editing->m_inputManager && m_editing->m_inputManager->isIMEState())
    {
        m_editing->m_inputManager->resetIMEState();
    }

    // Clear highlight which is set for previous text
    // TODO: use a better way to clear highlight so that it will not clear highlight which is user set
    // For example: App first 1). setHighlight, then 2). setText, the highlight set in 1) will be cleared
    setHighlight(0, 0);

    // change history cursor index
    // should keep ime history
    if (m_history && m_history->isSaved)
    {
        m_history->cursorIndex = textLen;
        m_history->selection.setRange(0, 0);
    }

    return 0;
}


void VcpTextEditor::setMaxLength(VfxS32 maxLen)
{
    m_storage->setMaxLength(maxLen);

    updateCounter(maxLen);
}


void VcpTextEditor::setIME(VfxU64 inputType, VfxU32 inputSetting)
{
    VsrvInputBinding inputBinding = m_editing->m_inputBinding;

    if (inputBinding.m_inputType != inputType ||
        inputBinding.m_inputSettingFlags != inputSetting)
    {
        inputBinding.m_inputType = inputType;
        inputBinding.m_inputSettingFlags = inputSetting;
        setIME(inputBinding);
    }
}


void VcpTextEditor::setIME(const VsrvInputBinding &inputBinding)
{
    m_editing->setIME(inputBinding);
    // set IME owner so that all IME UI alloc memory from editor's parent
    (m_editing->m_inputBinding).setOwner(this); 
}


VfxBool VcpTextEditor::onKeyInput(VfxKeyEvent &event)
{
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_REDUCED_KEYPAD__)
    if (event.keyCode == VFX_KEY_CODE_0 ||
        event.keyCode == VFX_KEY_CODE_STAR ||
        event.keyCode == VFX_KEY_CODE_POUND) 
    {
        return VFX_FALSE; /* For MoDIS rotation by PC keyboard */
    }
#endif

    // for dialer screen, the editor is not active but still need to process key input
    if (isActive())
    {
        return processKeyInput(event);
    }
    else
    {
        VfxBool ret = VFX_FALSE;
        switch(event.keyCode)
        {
        case VFX_KEY_CODE_ARROW_UP:
            if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
            {
                ret = previousPage();
            }
            break;
            
        case VFX_KEY_CODE_ARROW_DOWN:
            if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
            {
                ret = nextPage();
            }
            break;

        default:
            activate();
            ret = processKeyInput(event);
            break;
        }
        return ret;
    }
}


void VcpTextEditor::setAutoActivateByKey(VfxBool value)
{
    if (value)
    {
        registerKeyHandler(VFX_KEY_CODE_SPECIAL_ALL_IME_SYM_KEYS);

    #ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
        mmi_frm_set_keypad_mode(KEYPAD_1KEY_QWERTY);
    #endif
    }
    else
    {
        unregisterKeyHandler(VFX_KEY_CODE_SPECIAL_ALL_IME_SYM_KEYS);
    }
}

    
VfxBool VcpTextEditor::processKeyInput(VfxKeyEvent &event)
{
    VfxBool ret = VFX_TRUE; 
    VfxKeyCodeEnum normalKeyCode = event.keyCode;

    VfxBool canProcess = VFX_TRUE;
    m_signalOnBeforeKeyInput.emit(this, event, canProcess);
    if (canProcess == VFX_FALSE)
    {
        return VFX_FALSE;
    }

#ifdef __MMI_QWERTY_KEYPAD_SUPPORT__
    if (((VfxS32)normalKeyCode >= (VfxS32)VFX_KEY_CODE_0 && (VfxS32)normalKeyCode <= (VfxS32)VFX_KEY_CODE_9)
        || ((VfxS32)normalKeyCode >= (VfxS32)VFX_KEY_CODE_A && (VfxS32)normalKeyCode <= (VfxS32)VFX_KEY_CODE_Z)
        || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_STAR
        || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_POUND
        || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_QUESTION
        || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_PERIOD
        || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_DOLLAR)
    {
        if (!isActive() && (event.type == VFX_KEY_EVENT_TYPE_DOWN))
        {
            activate();
        }
    }
#else
    if (((VfxS32)normalKeyCode >= (VfxS32)VFX_KEY_CODE_0 && (VfxS32)normalKeyCode <= (VfxS32)VFX_KEY_CODE_9)
        || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_STAR
        || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_POUND
        || (VfxS32)normalKeyCode == (VfxS32)VFX_KEY_CODE_QWERTY)
    {
        if (!isActive() && (event.type == VFX_KEY_EVENT_TYPE_DOWN))
        {
            activate();
        }
    }
#endif

    if (m_editing)
    {
    #if VCP_TEXT_CLIPBOARD_SUPPORT
        if (m_clipboard)
        {
            // hide clipboard menu
            m_clipboard->hideMenu();
            m_isSelectingText = VFX_FALSE;
        }
    #else
        m_isSelectingText = VFX_FALSE;
    #endif

        // should not input key if layout is not done because the cursor info is incorrect in that case
        // IME use cursor position and rect to decide the IMUI (like candidate box) pos
        VfxTextRange dirtyRange = m_layout->getDirtyRange();
        if (m_editing->m_inputManager &&
            !(dirtyRange.getLength() > 0 && dirtyRange.getStart() <= getCursorIndex()))
        {
            // translate key to IME
            if (m_editing->m_inputManager->dispatchKeyEvent(event))
            {
                // The editor position maybe not visible before input
                // for example, scroll editor out of screen then input using pinyin input method,
                // if not updateViewForCursor, the editor will not appear until char is input.
                if (event.type == VFX_KEY_EVENT_TYPE_DOWN && m_editing->m_cursor)
                {
                    m_editing->m_cursor->updateViewForCursor();
                }
                return VFX_TRUE;
            }
        }

        if (event.keyCode == VFX_KEY_CODE_BACK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
        {
            if (m_editing->m_inputManager && m_editing->m_inputManager->isSoftInputVisible())
            {
                m_editing->m_inputManager->hideSoftInput();

                return VFX_TRUE;
            }
            else
            {
                return VFX_FALSE;
            }
        }

        switch(event.keyCode)
        {
            case VFX_KEY_CODE_ARROW_UP:
                if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
                {
                    if (previousLine() <= 0)
                    {
                        deactivate();
                    }
                }
                break;
                
            case VFX_KEY_CODE_ARROW_DOWN:
                if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
                {
                    if (nextLine() <= 0)
                    {
                        deactivate();
                    }
                }
                break;
                
            case VFX_KEY_CODE_ARROW_LEFT:
            case VFX_KEY_CODE_ARROW_RIGHT:
                if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
                {
                    if (isActive())
                    {
                        // clear highlight first
                        if (m_layout->getSelection().getLength() > 0)
                        {
                            m_layout->setSelection(VfxTextRange(0, 0));
                        }
                        else
                        {
                            if (event.keyCode == VFX_KEY_CODE_ARROW_LEFT)
                            {
                                previous();
                            }
                            else
                            {
                                next();
                            }
                        }
                    }
                    else
                    {
                        ret = VFX_FALSE;
                    }
                }
                break;

            case VFX_KEY_CODE_CLEAR:
            case VFX_KEY_CODE_RSK:
                if (event.type == VFX_KEY_EVENT_TYPE_DOWN)
                {
                    deleteChars();
                }
                else if (event.type == VFX_KEY_EVENT_TYPE_LONG_PRESS)
                {
                    deleteAll();
                }
                break;

            default:
                ret = VFX_FALSE;
                break;
        }

        return ret;
    }

    
    return VFX_FALSE;
}


void VcpTextEditor::setFunctionBar(VfxFrame *frame, VfxBool isAutoClose)
{
    m_autoCloseFunctionBar = isAutoClose;
    
    m_editing->setFunctionBar(frame);
}


VfxFrame * VcpTextEditor::getFunctionBar()
{
    return m_editing->getFunctionBar();
}


VfxBool VcpTextEditor::onPenInput(VfxPenEvent &event)
{
    return VFX_FALSE;
}


VfxWChar* VcpTextEditor::getText()
{
    return m_editing->getText();
    
}


void VcpTextEditor::setBounds(const VfxRect &value)
{
    VcpTextView::setBounds(value);
}


void VcpTextEditor::onFocusChanged(VfxBool focused)
{
    if (focused)
    {
        setHistory();
        activateInternal(VFX_FALSE);
    }
    else
    {
    #if VCP_TEXT_CLIPBOARD_SUPPORT
        if (m_clipboard)
        {
            // hide clipboard menu
            m_clipboard->hideMenu();
        }
    #endif
    #if VCP_TEXT_MAGNIFIER_SUPPORT
        if (m_magnifier)
        {
            VFX_OBJ_CLOSE(m_magnifier);
        }
    #endif
        getHistory();
        deactivateInternal(VFX_FALSE);
    }
}


void VcpTextEditor::activate(VfxBool isSetFocus)
{
    setFocused(VFX_TRUE);
}


void VcpTextEditor::deactivate(VfxBool isSetFocus)
{
    setFocused(VFX_FALSE);
}


void VcpTextEditor::activateInternal(VfxBool isSetFocus)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TE2", SA_start);
#endif
    if (!isActive() && !m_freezActiveState)
    {
        VcpTextView::activate(isSetFocus);

        // set IME owner so that all IME UI alloc memory from editor's parent
        (m_editing->m_inputBinding).setOwner(this); 

        m_editing->activate();

        m_layout->hideHintText(VFX_TRUE);

        if (!m_isDisableBg)
        {
            m_bgImageFrame->setImgContent(VfxImageSrc(m_hiliteBgImageId));
        }

        VFX_OBJ_GET_INSTANCE(VfxPen)->m_signalEventProcessed.connect(this, &VcpTextEditor::onPenEventProcessed);
        VFX_OBJ_GET_INSTANCE(VfxTopLevel)->m_signalRotated.connect(this, &VcpTextEditor::onRotated);
        VFX_OBJ_GET_INSTANCE(VfxTopLevel)->m_signalBeforeRotate.connect(this, &VcpTextEditor::onRotateTo);

        setCurrentActivateEditor(this);
        if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
        {
            wgui_inputs_set_current_input_box_type(EDITOR_SINGLE_LINE_INPU_BOX);
        }
        else
        {
            wgui_inputs_set_current_input_box_type(EDITOR_MULTILINE_INPUT_BOX);
        }

        // set cursor FPE when activate
        VfxObjHandle objHandle = m_editing->m_cursor->getObjHandle();
        m_editing->m_cursor->setPropertyEffectCallback(
                    this,
                    &VcpTextCursor::framePropertyEffectCallback, 
                    &objHandle,
                    sizeof(VfxObjHandle),
                    VRT_FPE_TRIGGER_TYPE_EVERYTIME);
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TE2", SA_stop);
#endif
}


void VcpTextEditor::deactivateInternal(VfxBool isSetFocus)
{
    if (isActive() && !m_freezActiveState)
    {
        VcpTextView::deactivate(isSetFocus);
        m_editing->deactivate();
        m_layout->hideHintText(VFX_FALSE);
        m_editing->getCursor()->setVisible(VFX_FALSE);

        if (!m_isDisableBg)
        {
            m_bgImageFrame->setImgContent(VfxImageSrc(m_normalBgImageId));
        }

        VFX_OBJ_GET_INSTANCE(VfxPen)->m_signalEventProcessed.disconnect(this, &VcpTextEditor::onPenEventProcessed);
        VFX_OBJ_GET_INSTANCE(VfxTopLevel)->m_signalRotated.disconnect(this, &VcpTextEditor::onRotated);
        VFX_OBJ_GET_INSTANCE(VfxTopLevel)->m_signalBeforeRotate.disconnect(this, &VcpTextEditor::onRotateTo);

        setCurrentActivateEditor(NULL);
        wgui_inputs_set_current_input_box_type(EDITOR_NONE_INPUT_BOX);

    #if defined(__COSMOS_MMI_PACKAGE__)
        if (m_waitingInd)
        {
            VFX_OBJ_CLOSE(m_waitingInd);
           // m_waitingInd->stop();
        }
    #endif

        // work around for performance
        // set opacity to 1 then 0 to make the setting take effect in VRT
        // if set to 0 only, VFX will not set opacity to VRT because VFX will check if current opacity the same as set one.
        m_editing->m_cursor->setOpacity(1);
        m_editing->m_cursor->setOpacity(0);

        // clear cursor FPE when deactivate
        m_editing->m_cursor->setPropertyEffectCallback(
                    this,
                    NULL, 
                    NULL,
                    0,
                    VRT_FPE_TRIGGER_TYPE_EVERYTIME);
    }
}


void VcpTextEditor::setIsDisabled (VfxBool isDisabled)
{
    VfxControl::setIsDisabled(isDisabled);

    if (isDisabled)
    {
        deactivate();
        setOpacity(0.3f);
        setIsUnhittable(VFX_TRUE);
        setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_GREY);
        checkUpdate();
    }
    else
    {
        setOpacity(1.0f);
        setIsUnhittable(VFX_FALSE);
        // restore corlor
    #if defined(__COSMOS_MMI_PACKAGE__)
        setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_RES(VCP_COL_TEXT_VIEW_NRML_TEXT));
    #else
        setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_BLACK);
    #endif
    }
}


vrt_render_dirty_type_enum VcpTextEditor::framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
{
    counterFPEData *userData = (counterFPEData *)user_data;
    
    VcpScrollableView *scrollableView = (VcpScrollableView *)handleToObject(userData->viewObjHandle);
    VcpTextEditor *editor = (VcpTextEditor *)handleToObject(userData->editorObjHandle);

    if (!scrollableView || !editor)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    vrt_frame_property_handle viewVrtPropertyHandle = vrt_canvas_get_frame_property_handle((vrt_frame_handle)scrollableView->getHandle());
    vrt_frame_property_handle editorVrtPropertyHandle = vrt_canvas_get_frame_property_handle((vrt_frame_handle)editor->getHandle());

    if (viewVrtPropertyHandle == NULL || editorVrtPropertyHandle == NULL)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    vrt_rect_struct viewRect = watch_frame->bounds;

    vrt_canvas_intersect_rect_to_root_frame(editorVrtPropertyHandle, &viewRect);

    if (vrt_rect_is_empty(&viewRect))
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }
    else
    {
        vrt_point_struct temp_point = g_vrt_point_zero;

        vrt_canvas_convert_point_to_root_frame(editorVrtPropertyHandle, &temp_point); // Get the coordinate offest from editor to root frame

        viewRect.origin.x -= temp_point.x; // Convert the rect from root frame to editor coordinate system
        viewRect.origin.y -= temp_point.y;

        if (target_frame->pos.y != viewRect.origin.y + VCP_EDITOR_COUNTER_POS)
        {
            target_frame->pos.y = viewRect.origin.y + VCP_EDITOR_COUNTER_POS;
            
            return VRT_RENDER_DIRTY_TYPE_DIRTY;
        }

        return VRT_RENDER_DIRTY_TYPE_NONE;
    }
}


VfxU32 VcpTextEditor::insertText(VfxWChar *string) 
{
    VfxU32 retLen = m_editing->insertText(string, -1);
    // after insert text, should clear selection
    setHighlight(0, 0);
    if (m_history && m_history->isSaved)
    {
        m_history->cursorIndex = getCursorIndex();
        m_history->selection.setRange(0, 0);
        if (m_imeHistory)
        {
            m_editing->m_inputManager->enableAutoCapInHistory(m_imeHistory);
        }
    }
    return retLen;
}


VfxU32 VcpTextEditor::insertText(VfxWChar wChar) 
{
    VfxU32 retLen = m_editing->insertText(wChar, -1);
    // after insert text, should clear selection
    setHighlight(0, 0);
    if (m_history && m_history->isSaved)
    {
        m_history->cursorIndex = getCursorIndex();
        m_history->selection.setRange(0, 0);
        // enable IME auto capital
        if (m_imeHistory)
        {
            m_editing->m_inputManager->enableAutoCapInHistory(m_imeHistory);
        }
    }
    return retLen;
}


VfxU32 VcpTextEditor::deleteChars(VfxS32 start, VfxS32 end)
{
    VfxU32 retLen = m_editing->deleteChars(start, end);
    if (m_history && m_history->isSaved)
    {
        m_history->cursorIndex = getCursorIndex();
    }
    return retLen;
}


VfxU32 VcpTextEditor::deleteChars()
{
    VfxU32 retLen = m_editing->deleteChars();
    if (m_history && m_history->isSaved)
    {
        m_history->cursorIndex = getCursorIndex();
    }
    return retLen;
}


void VcpTextEditor::deleteAll(void)
{
    if (m_history && m_history->isSaved)
    {
        m_history->cursorIndex = 0;

        // enable IME auto capital
        if (m_imeHistory)
        {
            m_editing->m_inputManager->enableAutoCapInHistory(m_imeHistory);
        }
    }
    return m_editing->clear();
}


VfxWChar VcpTextEditor::getCharBeforeCursor()
{
    return m_editing->getCharBeforeCursor(1, 0, NULL);
}


VfxWChar VcpTextEditor::getCharBeforeCursor(VfxS32 n)
{
    return m_editing->getCharBeforeCursor(n, 0, NULL);
}


VfxWChar VcpTextEditor::getCharAfterCursor()
{
    return m_editing->getCharAfterCursor(1, 0, NULL);
}


VfxWChar VcpTextEditor::getCharAfterCursor(VfxS32 n)
{
    return m_editing->getCharAfterCursor(n, 0, NULL);
}


VfxS32 VcpTextEditor::previous()
{
    return m_editing->getCursor()->previous();
}


VfxS32 VcpTextEditor::previous(VfxS32 steps)
{
    return m_editing->getCursor()->previous(steps);
}


VfxS32 VcpTextEditor::next()
{
    return m_editing->getCursor()->next();
}


VfxS32 VcpTextEditor::next(VfxS32 steps)
{
    return m_editing->getCursor()->next(steps);
}


VfxS32 VcpTextEditor::previousLine()
{
    return m_editing->getCursor()->previousLine();
}


VfxS32 VcpTextEditor::nextLine()
{
    return m_editing->getCursor()->nextLine();
}


void VcpTextEditor::setCursorIndex(VfxS32 index)
{
	if (m_isDisabled)
	{
		return;
	}
    // if call setCursorIndex after setText, the layout is not update, the cursor information will be wrong.
    // so we need to forceupdate here.
    forceUpdate();
    m_editing->getCursor()->setIndex(index);

	if (m_history && m_history->isSaved)
    {
        m_history->cursorIndex = index;
    }
}


VfxS32 VcpTextEditor::getCursorIndex(void) const
{
    return m_editing->getCursor()->getIndex();
}


void VcpTextEditor::setDeleteButton(VfxBool value)
{
    if (m_lineMode != VCP_TEXT_LINE_MODE_SINGLE)
    {
        return;
    }

    if (m_deleteButton == NULL)
    {
        VFX_OBJ_CREATE(m_deleteButton, VcpImageButton, this);
        m_deleteButton->setSize(VCP_EDITOR_DELETE_BTN_WIDTH, VCP_EDITOR_DELETE_BTN_HEIGHT);
        m_deleteButton->setImage(VcpStateImage(VCP_IMG_TEXT_EDITOR_DEL_ICON, 
                                VCP_IMG_TEXT_EDITOR_DEL_ICON, 
                                VCP_IMG_TEXT_EDITOR_DEL_ICON, 
                                VCP_IMG_TEXT_EDITOR_DEL_ICON));
        m_deleteButton->setAutoAnimate(VFX_FALSE);
        m_deleteButton->setIsStretchMode(VFX_FALSE);
        m_deleteButton->m_signalClicked.connect(this, &VcpTextEditor::onDeleteButtonClick);
        m_deleteButton->setHidden(VFX_TRUE);
    }

    if (m_enableDeleteButton != value)
    {
        m_enableDeleteButton = value;
        if (value == VFX_TRUE)
        {
            if (getLength() > 0)
            {
                setMarginFrame(VCP_TEXT_MARGIN_FRAME_RIGHT, m_deleteButton);
            }
            else
            {
                removeMarginFrame(VCP_TEXT_MARGIN_FRAME_RIGHT, m_deleteButton);
            }
        }
        else
        {
            removeMarginFrame(VCP_TEXT_MARGIN_FRAME_RIGHT, m_deleteButton);
        }
    }
}


void VcpTextEditor::setEnterKeyEnabled(VfxBool value)
{
    VsrvInputBinding inputBinding = m_editing->m_inputBinding;
    
    if (inputBinding.m_isVKEnterKeyEnabled != value)
    {
        if (!isActive())
        {
            inputBinding.m_isVKEnterKeyEnabled = value;
            setIME(inputBinding);
        }
        else if (m_editing->m_inputManager)
        {
            m_editing->m_inputManager->setSpecialEnterKey(value);
        }
    }
}


void VcpTextEditor::setEnterKeyStyle(IMEVKEnterKeyStyleEnum style)
{
    VsrvInputBinding inputBinding = m_editing->m_inputBinding;
    
    if (inputBinding.m_vkEnterKeyStyle != style)
    {
        inputBinding.m_vkEnterKeyStyle = style;
        setIME(inputBinding);
    }
}


void VcpTextEditor::setAutoDeactivated(VfxBool isAutoDeactivated)
{
    m_autoDeactivated = isAutoDeactivated;
}


void VcpTextEditor::setAutoActivated(VfxBool isAutoActivated, VfxS32 cursorIndex)
{
    if (m_autoActivated != isAutoActivated)
    {
        m_autoActivated = isAutoActivated;

        setCursorIndex(cursorIndex);

        if (m_autoActivated)
        {
            vfxPostInvoke1(this, &VcpTextEditor::activate, VFX_TRUE);
        }
        else
        {
            vfxPostInvoke1(this, &VcpTextEditor::deactivate, VFX_TRUE);
        }
    }
}


VfxBool VcpTextEditor::onSerialize(VfxArchive &ar)
{
    // save editor history
    // 1. cursor index
    VfxS32 cursorIndex = m_editing->getCursor()->getIndex();
    ar.write((VfxU8 *)&cursorIndex, sizeof(VfxS32));

    // 2. active state
    VfxBool isAct = isActive();
    ar.write((VfxU8 *)&isAct, sizeof(VfxBool));

    // save ime history
    void* imeHistory;
    VfxS32 imeHistorySize = m_editing->m_inputManager->getInputMethodHistorySize();
    VFX_ALLOC_MEM(imeHistory, imeHistorySize, this);
    m_editing->m_inputManager->getInputMethodHistory(imeHistory);
    ar.write((VfxU8 *)imeHistory, imeHistorySize);
    VFX_FREE_MEM(imeHistory);

    return VFX_TRUE;
}


void VcpTextEditor::onRestore(VfxArchive &ar)
{
    // restore ime history
    void* imeHistory;
    VfxS32 imeHistorySize = m_editing->m_inputManager->getInputMethodHistorySize();
    VFX_ALLOC_MEM(imeHistory, imeHistorySize, this);
    ar.read((VfxU8 *)imeHistory, imeHistorySize);
    m_editing->m_inputManager->setInputMethodHistory(imeHistory);
    VFX_FREE_MEM(imeHistory);

    // restore editor history
    // 1. active state
    VfxBool isAct = VFX_FALSE;
    ar.read((VfxU8 *)isAct, sizeof(VfxBool));
    if (isAct)
    {
        activate();
    }
    else
    {
        deactivate();
    }

    // 2. cursor index
    VfxS32 cursorIndex = 0;
    ar.read((VfxU8 *)&cursorIndex, sizeof(VfxS32));
    m_editing->getCursor()->setIndex(cursorIndex);
}


void VcpTextEditor::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_FRAME_NOTIFY_ID_FOCUS_CHANGED:
        {
            onFocusChanged(*(VfxBool *)userData);
            return;
        }
        default:
        {
            VcpTextView::onObjectNotify(id, userData);
            return;
        }
    }
}


void VcpTextEditor::getHistory()
{
    if (m_history)
    {
        // save editor history
        m_history->cursorIndex = m_editing->getCursor()->getIndex();
        m_history->isActive = isActive();
        if (!(m_editing && m_editing->m_inputManager && m_editing->m_inputManager->isIMEState()))
        {
            m_history->selection = getTextLayout()->getSelection();
        }
        //save ime history
        VfxS32 imeHistorySize = m_editing->m_inputManager->getInputMethodHistorySize();
        if (imeHistorySize > 0)
        {
            if (m_imeHistory == NULL)
            {
                VFX_ALLOC_MEM(m_imeHistory, imeHistorySize, this);
            }
            m_editing->m_inputManager->getInputMethodHistory(m_imeHistory);
        }
        else
        {
            VFX_FREE_MEM(m_imeHistory);
        }
        m_history->isSaved = VFX_TRUE;
    }
}


void VcpTextEditor::setHistory()
{
    if (m_history && m_history->isSaved)
    {
        // restore editor history

        // check cursor index validation in case the text changed after getHistory
        VfxS32 textLen = getLength();
        if (m_history->cursorIndex > textLen)
        {
            // set cursor to last position
            m_editing->getCursor()->setIndex(textLen);
        }
        else
        {
            m_editing->getCursor()->setIndex(m_history->cursorIndex);
        }

        getTextLayout()->setSelection(m_history->selection);

        if (m_imeHistory)
        {
            // restore IME history
            m_editing->m_inputManager->setInputMethodHistory(m_imeHistory);
            VFX_FREE_MEM(m_imeHistory);
        }

        if (m_history->isActive)
        {
            activate();
        }

        m_history->isSaved = VFX_FALSE;
    }
}


void VcpTextEditor::getHistory(VcpTextEditorHistoryStruct *history)
{
    if (history)
    {
        // save cursor index
        history->cursorIndex = m_editing->getCursor()->getIndex();
        history->isActive = isActive();
        // save IME history
        m_editing->m_inputManager->getInputMethodHistory((void*)&history->imeHistory);
        history->isSaved = VFX_TRUE;
    }
}


void VcpTextEditor::setHistory(VcpTextEditorHistoryStruct *history)
{
    if (history && history->isSaved)
    {
        // restore cursor index
        m_editing->getCursor()->setIndex(history->cursorIndex);

        // restore IME history
        m_editing->m_inputManager->setInputMethodHistory((void*)&history->imeHistory);

        if (history->isActive)
        {
            activate();
        }

        history->isSaved = VFX_FALSE;
    }
}


VfxU32 VcpTextEditor::directInput(VfxU8 index, VfxWChar *p)
{
    if (s_activateEditor)
    {
        VfxU32 size = 0;
        VfxWChar *input = NULL;
        VfxU32 i = 0;
        VfxU16 input_buff[VCP_TEXT_INJECT_STRING_TO_MODULE_MAX_LENGTH];

        if (index == VCP_TEXT_INJECT_STRING_TO_MODULE_UNICODE_DONE_INDEX ||
            index == VCP_TEXT_INJECT_STRING_TO_MODULE_UNICODE_UNDONE_INDEX)
        {
            /* For byte alignment */
            memcpy(input_buff, p, VCP_TEXT_INJECT_STRING_TO_MODULE_MAX_LENGTH);
            input = input_buff;
            input[VCP_TEXT_INJECT_STRING_TO_MODULE_MAX_LENGTH / 2 - 1] = 0;
        }
        else if (index == VCP_TEXT_INJECT_STRING_TO_MODULE_ASCII_DONE_INDEX ||
                 index == VCP_TEXT_INJECT_STRING_TO_MODULE_ASCII_UNDONE_INDEX)
        {
            VfxChar *pTemp = (VfxChar *)p;
            pTemp[VCP_TEXT_INJECT_STRING_TO_MODULE_MAX_LENGTH - 1] = 0;
            while ((*pTemp) != 0)
            {
                input_buff[i++] = *(pTemp++);
            }
            input_buff[i] = 0;
            input = input_buff;
        }
        else if (index == 0)
        {
            input = p;
        }
        else
        {
            return 0;
        }
        
        size = s_activateEditor->insertText(input);
        return size;
    }
    return 0;
}


void VcpTextEditor::showSoftInput()
{
    if (m_editing && m_editing->m_inputManager)
    {
        m_editing->m_inputManager->showSoftInput();
    }
}


void VcpTextEditor::hideSoftInput()
{
    if (m_editing && m_editing->m_inputManager)
    {
        m_editing->m_inputManager->hideSoftInput();
    }
}


void VcpTextEditor::disableAutoCap()
{
    if (m_editing && m_editing->m_inputManager)
    {
        m_editing->m_inputManager->override_autocap();
    }
}


void VcpTextEditor::setIsHideCursor(VfxBool value)
{
    m_isHideCursor = value;
    if (m_editing)
    {
        if (value)
        {
            m_editing->getCursor()->setVisible(VFX_FALSE);
        }
        else
        {
            if (isActive())
            {
                m_editing->getCursor()->setVisible(VFX_TRUE);
            }
        }
        checkUpdate();
    }
}


void VcpTextEditor::updateCounter(VfxS32 maxLen)
{
    // update editor counter
    if (m_counter)
    {
        VfxS32 textLen = getLength();
        if (m_counterDispMode == VCP_TEXT_COUNTER_DISP_AUTO)
        {
            if (textLen >= VCP_EDITOR_COUNTER_DISP_PERCENTAGE * maxLen)
            {
                m_counter->setHidden(VFX_FALSE);
            }
            else
            {
                m_counter->setHidden(VFX_TRUE);
            }
        }
        else if (m_counterDispMode == VCP_TEXT_COUNTER_DISP_SHOW)
        {
            m_counter->setHidden(VFX_FALSE);
        }
        else if (m_counterDispMode == VCP_TEXT_COUNTER_DISP_HIDE)
        {
            m_counter->setHidden(VFX_TRUE);
        }
        checkUpdate();

        m_counter->updateCounter();
    }
}


/***************************************************************************** 
 * Class VcpEditing
 *****************************************************************************/
VcpEditing::VcpEditing()
{
    m_inputManager = NULL;
    m_cursor = NULL;
    m_isModify = VFX_FALSE;
    m_batchEdit = 0;
    m_showFunctionBarTimeline = NULL;
    m_hideFunctionBarTimeline = NULL;
}


void VcpEditing::attachTo(VcpTextView *textView)
{
    m_view = textView;
    m_isModify = VFX_FALSE;

    setIME(IMM_INPUT_TYPE_SENTENCE, IME_SETTING_FLAG_NONE);

    if (m_cursor == NULL)
    {
        VFX_OBJ_CREATE(m_cursor, VcpTextCursor, m_view);
    }

    m_view->getTextStorage()->m_signalTextChanged.connect(this, &VcpEditing::onTextChanged);
}


void VcpEditing::setIME(VfxU64 inputType, VfxU32 inputSetting)
{
    InputConnection *con = static_cast<InputConnection*> (this);

    setIME(VsrvInputBinding(inputType, inputSetting, IME_INPUT_STYLE_NONE, con));
}

void VcpEditing::setIME(const VsrvInputBinding &inputBinding)
{
	VfxBool isInputTypeChanged = (m_inputBinding.m_inputType != inputBinding.m_inputType);

    m_inputBinding = inputBinding;

    // disable new line symbol in single line mode
    if (m_view->m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
    {
        m_inputBinding.m_inputSettingFlags |= IME_DISABLE_NEW_LINE_SYMBOL;
    }

    VfxBool isActive = m_view->isActive();

    VfxS32 imeHistorySize = 0;
    void *imeHistory = NULL;
    if (m_inputManager && m_inputManager->getBinding() == &m_inputBinding)
    {
		if (!isInputTypeChanged)
		{
			// before deactivate, should save current history
			imeHistorySize = m_inputManager->getInputMethodHistorySize();
			VFX_ALLOC_MEM(imeHistory, imeHistorySize, this);
			m_inputManager->getInputMethodHistory(imeHistory);
		}

        m_inputManager->deactivateInput();
        m_inputManager->unbindInput(&m_inputBinding);

        m_inputManager = NULL;
    }

    m_inputManager = VFX_OBJ_GET_INSTANCE(VsrvInputManager);

    if (isActive && m_inputManager)
    {
        // restore history
        if (imeHistory)
        {
            m_inputManager->setInputMethodHistory(imeHistory);
        }
        m_inputManager->bindInput(&m_inputBinding);
        m_inputManager->activateInput();
    }

    VFX_FREE_MEM(imeHistory);

    if (m_inputBinding.m_inputType & IMM_INPUT_TYPE_EXT_PASSWORD)
    {
        m_view->getTextLayout()->setMask(VFX_TRUE);
    }
	else
    {
        m_view->getTextLayout()->setMask(VFX_FALSE);
    }

    if (m_inputBinding.m_inputSettingFlags & IME_PLUS_CHAR_HANDLING)
    {
        m_view->getTextStorage()->setPlusCharHandling(VFX_TRUE);
    }
}

void VcpEditing::activate()
{
    if (!mmi_scr_locker_is_locked())
    {
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TEM", SA_start);
    #endif
        if (m_inputManager)
        {
            m_inputManager->bindInput(&m_inputBinding);
            m_inputManager->activateInput();
        }
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TEM", SA_stop);
    #endif

        if (m_cursor->getIndex() < 0)
        {
            m_cursor->setIndex(m_view->getTextStorage()->getTextLength());
        }
        else
        {
            m_cursor->setIndex(m_cursor->getIndex());
        }

        if (!((VcpTextEditor *)m_view)->m_isHideCursor)
        {
            m_cursor->setVisible(VFX_TRUE);
        }
        m_cursor->bringToFront();
        m_signalActivated.emit(m_view, VFX_TRUE);

        configFunctionBar();
    }    
}


void VcpEditing::deactivate()
{
    if (m_inputManager)
    {
        if (m_inputManager->getBinding() == &m_inputBinding)
        {
            m_inputManager->deactivateInput();
            m_inputManager->unbindInput(&m_inputBinding);
        }
        m_signalActivated.emit(m_view, VFX_FALSE);

        if (m_functionBarPtr != NULL)
        {
            m_functionBarPtr->removeFromParentFrame();
        }
    }
}


VfxS32 VcpEditing::moveCursorByLine(VfxS32 steps)
{
    VfxS32 i = 0;
    VfxS32 ret = 0;

    if (steps > 0)
    {
        for (i = 0; i < steps; i++)
        {
            ret = getCursor()->nextLine();
            if (ret <= 0)
            {
                break;
            }
        }
    }
    else
    {
        for (i = 0; i < -steps; i++)
        {
            ret = getCursor()->previousLine();
            if (ret <= 0)
            {
                break;
            }
        }
    }

    return i;
}


VfxS32 VcpEditing::moveCursorByChar(VfxS32 steps)
{
    if (steps > 0)
    {
        return getCursor()->next(steps);
    }
    else
    {
        return getCursor()->previous(-steps);
    }
}


void VcpEditing::scrollViewForCursor()
{
    // if cursor not created
    if (m_cursor == NULL)
        return;

    VfxRect rectVisible = m_view->m_view->getBounds();//m_view->getViewBounds();
    VfxRect rectCursor = VfxRect(m_cursor->getPos(), m_cursor->getSize());
    VfxRect rectIntersect = rectVisible;
    VfxRect rectUnion = rectVisible;

    // if the cursor rect has out of scrollable valid content rect, should adjust the content rect to contain it
    VfxRect validContentRect = VfxRect(0, 0, m_view->m_view->getContentSize().width, m_view->m_view->getContentSize().height);//m_view->m_view->getValidContentRect();
    VfxRect cursorIntersectValidRect = validContentRect;
    cursorIntersectValidRect.intersectWith(rectCursor);
    if (cursorIntersectValidRect != rectCursor)
    {
        VfxRect cursorUnionValidRect = validContentRect;
        validContentRect.unionWith(rectCursor);

        m_view->setContentSize(VfxSize(validContentRect.getWidth(), validContentRect.getHeight()));
        m_view->setValidContent(validContentRect);
    }
    
    if (rectVisible.isEmpty())
        return;

    if (rectIntersect.intersectWith(rectCursor) == rectCursor)
        return;

    rectUnion.unionWith(rectCursor);
    if (rectUnion.getMinX() < rectVisible.getMinX()
        || rectUnion.getMinY() < rectVisible.getMinY())
    {
        rectVisible.origin.x = rectUnion.getMinX();
        rectVisible.origin.y = rectUnion.getMinY();
    }
    else if (rectUnion.getMaxX() > rectVisible.getMaxX()
        || rectUnion.getMaxY() > rectVisible.getMaxY())
    {
        rectVisible.origin.x = rectUnion.getMaxX() - rectVisible.getWidth() + 1;
        rectVisible.origin.y = rectUnion.getMaxY() - rectVisible.getHeight() + 1;
    }

    // scroll cell view to visible area, otherwise it will flash a blank area
    if (m_view->m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
    {
        // not scroll with animation because it will be very strange for singleline, like in dialer
        m_view->scrollRectToVisible(rectVisible, VFX_FALSE);
        // scroll right SCROLL_TO_RIGHT
        m_view->m_scrollDir = 1;
    }
    else
    {
        m_view->scrollRectToVisible(rectVisible, VFX_TRUE);
        // scroll down SCROLL_TO_DOWN
        m_view->m_scrollDir = 4;
    }
    m_view->scrollCellView();
}


void VcpEditing::locateCursorTo(const VfxPoint &point)
{
    VfxS32 lineIndex = m_view->getTextLayout()->getLineIndexByY(point.y);
    VfxS32 index = 0;
    VfxS32 charLineIndex = 0;
    VfxPoint newPos;
    
    if (lineIndex >= m_view->getTextLayout()->getLineCount())
    {
        index = m_view->getTextStorage()->getTextLength();
        m_cursor->setIndex(index);
        return;
    }

    charLineIndex =  m_view->getTextLayout()->getIndexOfPos(lineIndex, point.x, &newPos);
    m_cursor->setIndex(charLineIndex, &newPos);
    
}


void VcpEditing::setFunctionBar(VfxFrame *frame)
{
    if (frame)
    {
        m_functionBarPtr = frame;

        configFunctionBar(m_view->isActive());
    }
}


void VcpEditing::configFunctionBar(VfxBool value)
{
    VfxFrame *frame = m_functionBarPtr.get();
    if (frame)
    {
        if (value)
        {
            frame->setAutoAnimate(VFX_FALSE);

            VFX_OBJ_GET_INSTANCE(VfxTopLevel)->addChildFrame(frame);

            frame->setAnchor(0.5, 0);
        }

        vrt_size_struct mainScreenSize;
        vrt_color_type_enum mainScreenColorFormat;
        vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);

        // turn off animation to avoid the function bar (button) child animation
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(!frame->getAutoAnimate());
        frame->setSize(mainScreenSize.width, frame->getSize().height);
        VfxAutoAnimate::commit();

        VsrvInputManager* inputManager = VFX_OBJ_GET_INSTANCE(VsrvInputManager);
        VsrvInputBinding* inputBinding = NULL;
        if (inputManager)
        {
            inputBinding = inputManager->getBinding();
        }

        VcpEditing* editing = NULL;
        if (inputBinding != NULL)
        {
            editing = (VcpEditing*)(inputBinding->getConnection());
        }

        // should hide the function bar in following case:
        // 1. IME is active and IME is connect to current editor and VK is hide
        // 2. IME is not active
        // 3. IME is active and IME is not connect to this editor and this function bar(frame) is not current active function bar
        if ((inputBinding && inputBinding == &m_inputBinding && inputManager && !inputManager->isSoftInputVisible()) ||
            (inputBinding == NULL) ||
            (inputBinding && (inputBinding != &m_inputBinding) && editing && editing->getFunctionBar() != frame))
        {
            // set original position for animation when VK appear
            frame->setPos(mainScreenSize.width / 2, mainScreenSize.height - m_functionBarPtr->getSize().height);
            frame->setHidden(VFX_TRUE);
        }

        if (value)
        {
            frame->setAutoAnimate(VFX_TRUE);
            frame->setPosZ(VFX_TOP_LEVEL_Z_IME_UI);
            frame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_NONE,
                VFX_FRAME_ALIGNER_MODE_SIDE,
                VFX_FRAME_ALIGNER_MODE_SIDE);
        }
    }
}


VfxFrame * VcpEditing::getFunctionBar()
{
    if (m_functionBarPtr.get())
    {
        return (VfxFrame *)m_functionBarPtr.get();
    }
    else
    {
        return NULL;
    }
}


VfxBool VcpEditing::beginBatchEdit()
{
    if (m_batchEdit)
    {
        m_batchEdit++;
        return VFX_FALSE;
    }

    // disable layout
    m_view->getTextLayout()->setBatch(VFX_TRUE);
    m_batchEdit = 1;
    return VFX_TRUE;
}


VfxBool VcpEditing::endBatchEdit()
{
    if (m_batchEdit)
    {
        m_batchEdit--;
        if (m_batchEdit > 0)
            return VFX_FALSE;
    }

    // enable layout and layout
    m_view->getTextLayout()->setBatch(VFX_FALSE);
    if (m_isModify)
    {
        m_signalTextChanged.emit(m_view);
    }
    return VFX_TRUE;
}


VfxU32 VcpEditing::insertText(VfxWChar *string, VfxS32 newCursorPos, VfxS32 index)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TEI", SA_start);
#endif
    VfxS32 curPos = 0;
    VfxBool ret = VFX_TRUE;

    // setAutoActivate will defaultly set the cursor to -1, 
    // if insert text before editor activated, should set index to the last position of the editor
    if (m_cursor->getIndex() < 0)
    {
        m_cursor->setIndex(m_view->getLength());
    }

    if (m_view->isReachMaxLineNum())
    {
    #if defined(__COSMOS_MMI_PACKAGE__)
        // notify user if max layout line number reached
        VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
        balloon->addItem(
            VCP_INFO_BALLOON_TYPE_INFO,
            VFX_WSTR_RES(STR_ID_CLIPBOARD_MAX_LINE_REACHED));
    #endif
    #ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TEI", SA_stop);
#endif
        return 0;
    }

#if VCP_TEXT_CLIPBOARD_SUPPORT
    m_view->m_clipboard->hideMenu();
#endif

    // begin the batch edit mode
    beginBatchEdit();

    // delete marked text or selection text
    if (m_view->getTextLayout()->getSelection().getLength() > 0 ||
        m_view->getTextLayout()->getMarkedText().getLength() > 0)
    {
#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))
        if(to_decide_to_reshuffle_inline == 1)
        {
            VfxS32 str_len = 0;
            VfxChar *textBuffer = (VfxChar *)(m_view->getTextStorage()->getText());
			str_len =(2*(m_cursor->getIndex()));
			ire_reshuffling_editor_buffer_for_bengali_spec((PU8)textBuffer, (S32)str_len);
            to_decide_to_reshuffle_inline = 0;
        }
    #endif
   
        VfxS32 retDel = deleteChars();
        if (retDel > 0)
        {
            // on deleteChars, the text change signal will not be emit because it's in batch mode
            // so we should emit here to let application can update its context in text change slot
            // otherwise, the app context maybe wrong even after delete the text thun the query in m_signalBeforeChange will fail
            // example: current editor 39/40, if input char in multitap (40/40), the second char can't be insert because when delete the 
            // first char in multitap, the application context still be 40/40
            ((VcpTextEditor *)m_view)->m_signalTextChanged.emit((VcpTextEditor *)m_view);
        }
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TEI", SA_start);
#endif
    // query if the character can be insert or not
    if (index >= 0)
    {
        m_signalBeforeChange.emit(string, index, VCP_TEXT_CHANGE_INSERT_CHAR, &ret);
    }
    else
    {
        m_signalBeforeChange.emit(string, m_cursor->getIndex(), VCP_TEXT_CHANGE_INSERT_CHAR, &ret);
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TEI", SA_stop);
#endif
    VfxS32 retLen = 0;
    curPos = m_cursor->getIndex();

    if (ret == VFX_TRUE)
    {
        if (index >= 0)
        {
            retLen = m_view->getTextStorage()->insertText(index, string, NULL);
        }
        else
        {
            retLen = m_view->getTextStorage()->insertText(curPos, string, NULL);
        }

#if defined(__MMI_MULTITAP_BANGLA_SPEC__)&&( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))
        if(mtkmultitap_ire_bengali_ndicator == 1)
        {
            VfxChar *temp_texp_p;
            VfxS32 str_len;
            temp_texp_p =  (VfxChar *)string;
            VfxChar *textBuffer = (VfxChar *)(m_view->getTextStorage()->getText());

            if(( temp_texp_p[0] | (temp_texp_p[1] << 8)) == 0x09b0)
            {
                temp_texp_p += 2;
                if(( temp_texp_p[0] | (temp_texp_p[1] << 8)) == 0x09cd)
                {                                                                    
                    str_len =(2*(m_cursor->getIndex())) +4;
                    ire_shuffling_editor_buffer_for_bengali_spec((PU8)textBuffer, (S32)str_len);
                    to_decide_to_reshuffle_inline = 1;
                }
            }
        }
    #endif

        if (retLen > 0)
        {
            m_cursor->setMoveStartX(-1);
            m_isModify = VFX_TRUE;
        }
        else if (vfx_sys_wcslen((const VfxWChar*)string) > 0)
        {
            m_view->playTone(VCP_TEXT_TONE_CANNOT_INSERT);
        }
    }
    else
    {
        m_view->playTone(VCP_TEXT_TONE_CANNOT_INSERT);
    }

    // complete the batch edit mode
    endBatchEdit();

    if (retLen > 0)
    {
        // no need to set cursor pos because when layout ready, it will be set except auto resize mode
        VfxBool isNeedSetPos = VFX_FALSE;
        // because auto font size mode will update the layout in above step, so if in auto resize mode,
        // should set cursor position here
        if (m_view->m_autoFontSize && m_view->isActive())
        {
            isNeedSetPos = VFX_TRUE;
        }

        if (newCursorPos < 0)
        {
            m_cursor->setIndex(curPos + retLen, NULL, isNeedSetPos);
        }
        else
        {
            m_cursor->setIndex(newCursorPos, NULL, isNeedSetPos);
        }
    }

#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    VfxU32 txtLen = vfx_sys_wcslen((const VfxWChar*)string);
    if (m_view->m_storage->isIconMode() && (retLen == txtLen))
    {
        VfxResId imgId = m_view->m_storage->getIconIdByText(string);
        if (imgId != VFX_RES_ID_NULL)
        {
            // add a special image object format
            VcpRichTextImage iconObj(this);
            iconObj.setImage(imgId);
            iconObj.m_range.setRange(curPos, curPos + retLen);
            iconObj.setObjectAttribute(VCP_RICH_TEXT_OBJ_EMOTION_ICON);
            m_view->addTextFormat(iconObj);
        }
    }
#endif

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TEI", SA_stop);
#endif
    return retLen;
}


VfxU32 VcpEditing::insertText(VfxWChar wChar, VfxS32 newCursorPos, VfxS32 index)
{
    VfxWChar string[2] = {wChar, 0};

    return insertText(string, newCursorPos, index);
}


VfxU32 VcpEditing::setMarkedText(
        VfxWChar *string, 
        VfxS32 selRangeStart, 
        VfxS32 selRangeEnd, 
        VfxS32 newCursorPos)
{
    VfxU32 len;
    VfxTextRange selRange(selRangeStart, selRangeEnd);
    VfxTextRange markedRange = m_view->getTextLayout()->getMarkedText();
    VfxTextRange selectionRange = m_view->getTextLayout()->getSelection();
    VfxTextRange range(markedRange);

    // begin the batch edit mode
    beginBatchEdit();

    if (markedRange.getLength() == 0)
    {
        if (selectionRange.getLength())
        {
            range.setStart(vfxMin(selectionRange.getStart(), selectionRange.getEnd()));
        }
        else
        {
            range.setStart(m_cursor->getIndex());
        }
    }

    len = insertText(string, newCursorPos);
    range.setEnd(range.getStart() + len);
    m_view->getTextLayout()->setMarkedText(range);

    // mapping to offset of the whole text
    selRange.shift(range.getStart());

    selRange.limitTo(range);
    if (selRange.getLength() > 0)
    {
        setSelection(selRange.getStart(), selRange.getEnd());
    }

    m_isModify = VFX_TRUE;

    // end the batch edit mode
    endBatchEdit();

    return range.getLength();
}


void VcpEditing::finishMarkedText()
{
    // begin the batch edit mode
    beginBatchEdit();

    // confirm the marked text
    m_view->getTextLayout()->setMarkedText(VfxTextRange(0, 0));

    // clear selection
    m_view->getTextLayout()->setSelection(VfxTextRange(0, 0));

    // forceUpdate for password mode
    // in password mode, the actual char will be replaced by '*' when finish mark text by IME
    // if not update, the layout will be wrong
    if (m_view->getTextLayout()->getMask())
    {
        m_view->forceUpdate();
    }

#if defined(__MMI_MULTITAP_BANGLA_SPEC__) && ( defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_REDUCED_KEYPAD__))
    to_decide_to_reshuffle_inline = 0;
#endif
    // end the batch edit mode
    endBatchEdit();
}


void VcpEditing::sendKeyEvent(
        VfxKeyEventTypeEnum type,           // Key type
        VfxKeyCodeEnum      keyCode,        // Key code
        VfxWChar            ucs2,           // UCS2
        VfxU32              specialKeyFlag, // Key special flag, see VFX_SPECIAL_KEY_FLAG_XXXX.
        VfxMsec             timeStamp       // Time stemp of the key input event
        )
{
    // TODO:
}


void VcpEditing::clear()
{
    if (length() == 0)
        return;

#if VCP_TEXT_CLIPBOARD_SUPPORT
    m_view->m_clipboard->hideMenu();
#endif

    VfxBool ret = VFX_TRUE;
    m_signalBeforeChange.emit(NULL, m_cursor->getIndex(), VCP_TEXT_CHANGE_DELETE_ALL, &ret);

    // don't delete all if return false
    if (ret == VFX_FALSE)
    {
        return;
    }

    // begin the batch edit mode
    beginBatchEdit();

    // turn off auto animation to avoid the cursor jumping when delete all content
    VfxBool isAutoAnimate = m_view->m_view->getAutoAnimate();
    m_view->m_view->setAutoAnimate(VFX_FALSE);

    m_view->getTextStorage()->clear();
    clearSelectionRange();
    m_isModify = VFX_TRUE;

    // complete the batch edit mode
    endBatchEdit();

    // need to forceUpdate immediatly when delete all
    // If app first delete all, then insert text (like calculator)
    // the layout(start, end, charchangecount) will be wrong in this case
    m_view->forceUpdate();

    // reset the cursor position
    m_cursor->setIndex(0);
    m_view->m_view->setAutoAnimate(isAutoAnimate);
}


VfxU32 VcpEditing::deleteChars(VfxS32 start, VfxS32 end)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TED", SA_start);
#endif

    VfxS32 deleteCnt;
    VfxS32 curIndex;

    if (length() == 0)
    {
        m_view->playTone(VCP_TEXT_TONE_CANNOT_DELETE);
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TED", SA_stop);
    #endif
        return 0;
    }
#if VCP_TEXT_CLIPBOARD_SUPPORT
    m_view->m_clipboard->hideMenu();
#endif
    VfxBool ret = VFX_TRUE;
    m_signalBeforeChange.emit(
        (VfxWChar *)(m_view->getTextStorage()->getText() + start),
        m_cursor->getIndex(),
        VCP_TEXT_CHANGE_DELETE_CHAR,
        &ret);
    // don't delete if return false
    if (ret == VFX_FALSE)
    {
        m_view->playTone(VCP_TEXT_TONE_CANNOT_DELETE);
    #ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TED", SA_stop);
    #endif
        return 0;
    }
    
    // begin the batch edit mode
    beginBatchEdit();

    VfxS32 curPos = m_cursor->getIndex();

    if (start == -1 && end == -1)
    {
        deleteCnt = m_view->getTextStorage()->deleteText(curPos - 1, 1);
        curIndex = curPos - deleteCnt;
    }
    else
    {
        deleteCnt = m_view->getTextStorage()->deleteText(start, end - start);

        if (curPos <= start)
        {
            // keep cursor index
            curIndex = curPos;
        }
        else if (curPos > start/* && curPos <= end*/)
        {
            // set cursor index to delete start position
            // case: "a|ab", "ab" is a cluster, '|' is cursor position (index = 1), multitap input sequence 'x'->'b'
            // 1. multitap insert 'x', -> "axab|" ("axab" is a cluster and cursor move to last position (index = 4)
            // 2. multitap insert 'b'
            //     2.1. it will first delete 'x': -> "a|ab", (in this case, curIndex should reset to start postion (curIndex = 1))
            //     2.2. insert 'b': "ab|ab"
            curIndex = start;
        }
        else
        {
            // calculate new cursor position after deletion
            curIndex = curPos - deleteCnt;
        }
    }

    if (deleteCnt)
    {
        m_cursor->setMoveStartX(-1);
        m_isModify = VFX_TRUE;
    }
    else
    {
        m_view->playTone(VCP_TEXT_TONE_CANNOT_DELETE);
    }

    // complete the batch edit mode
    endBatchEdit();

    m_cursor->setIndex(curIndex, NULL, VFX_FALSE);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TED", SA_stop);
#endif
    return deleteCnt;
}


VfxU32 VcpEditing::deleteChars()
{

#if VCP_TEXT_CLIPBOARD_SUPPORT
    m_view->m_clipboard->hideMenu();
#endif

    VfxTextRange selectionRange(m_view->getTextLayout()->getSelection());
    VfxTextRange markedRange(m_view->getTextLayout()->getMarkedText());
    if (length() == 0)
    {
        // empty
        m_view->playTone(VCP_TEXT_TONE_CANNOT_DELETE);
        return 0;
    }

    if (markedRange.getLength() > 0)
    {
        // some marked text exist. clear them
        VfxTextRange range(markedRange);

        finishMarkedText();
        
        return deleteChars(range.getStart(), range.getEnd());
    }
    else if (selectionRange.getLength() > 0)
    {
        VfxU32 ret;

        ret = deleteChars(selectionRange.getStart(), selectionRange.getEnd());
        clearSelectionRange();

        return ret;
    }
    else
    {
        return deleteAtCursor(1, 0);
    }
}


VfxBool VcpEditing::clearSelectionRange()
{
#if VCP_TEXT_CLIPBOARD_SUPPORT
    m_view->m_clipboard->hideMenu();
#endif
    if (m_view->getTextLayout()->getSelection().getLength() > 0)
    {
        // begin the batch edit mode
        beginBatchEdit();

        m_view->getTextLayout()->setSelection(VfxTextRange(0, 0));
        
        // complete the batch edit mode
        endBatchEdit();

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


VfxU32 VcpEditing::deleteAtCursor(VfxS32 leftLength, VfxS32 rightLength)
{
    VfxS32 start, end;
    VfxU32 ret;
    VfxTextRange markedRange = m_view->getTextLayout()->getMarkedText();
    VfxTextRange selectionRange = m_view->getTextLayout()->getSelection();

#if VCP_TEXT_CLIPBOARD_SUPPORT
    m_view->m_clipboard->hideMenu();
#endif

    if (length() == 0)
        return 0;

    if (markedRange.getLength())
    {
        // some marked text exist. clear them
        VfxTextRange range(markedRange);
        
        finishMarkedText();
        ret = deleteChars(range.getStart(), range.getEnd());
        return ret;
    }
    else if (selectionRange.getLength())
    {  
        ret = deleteChars(selectionRange.getStart(), selectionRange.getEnd());
        clearSelectionRange();
        
        return ret;
    }
    else
    {
        VfxS32 curIndex = m_cursor->getIndex();
        // should delete the whole emotion icon
        VcpRichTextFormat *obj = m_view->getTextLayout()->getObjectOfIndex(curIndex - 1);
        if (obj && obj->getType() != VCP_RICH_TEXT_TYPE_TEXT && obj->getType() != VCP_RICH_TEXT_TYPE_HYPERLINK)
        {
            start = obj->m_range.getStart() + 1 - leftLength;
            end = curIndex + rightLength;
        }
        else
        {
            start = curIndex - leftLength;
            end = curIndex + rightLength;
        }
        
        // handle 0x0D0A
        VfxWChar *pBuf = (VfxWChar *)(m_view->getTextStorage()->getText());
        if ((start > 0) && (pBuf[start] == 0x0A) && (pBuf[start - 1] == 0x0D))
        {
            // need to delete 0D0A
            start--;
        }
        
        // validation hanlde
        if (start < 0)
            start = 0;
        if (end > length())
            end = length();
        
        return deleteChars(start, end);
    }
}


VfxS32 VcpEditing::length() const
{
    return m_view->getTextStorage()->getTextLength();
}


VfxS32 VcpEditing::maxLength() const
{
    return m_view->getTextStorage()->getMaxLength();
}


VfxWChar VcpEditing::getCharBeforeCursor(VfxS32 index, VfxS32 moveType, VfxS32 *charType)
{
    VfxS32 charIndex = m_cursor->getIndex() - index;
    if (charIndex < 0)
    {
        return 0;
    }
    else
    {
        const VfxWChar *text;
        VfxS32 retLen;
        m_view->getTextStorage()->getText(&text, charIndex, 1, &retLen, NULL);
        if (retLen)
        {
            return *text;
        }
        else
        {
            return 0;
        }
    }
}


VfxWChar VcpEditing::getCharAfterCursor(VfxS32 index, VfxS32 moveType, VfxS32 *charType)
{
    VfxS32 charIndex = m_cursor->getIndex() + index;
    if (charIndex >= length())
    {
        return 0;
    }
    else
    {
        const VfxWChar *text;
        VfxS32 retLen;
        m_view->getTextStorage()->getText(&text, charIndex, 1, &retLen, NULL);
        if (retLen)
        {
            return *text;
        }
        else
        {
            return 0;
        }
    }
}


VfxS32 VcpEditing::setSelection(VfxS32 start, VfxS32 end)
{
    VfxS32 ret;
    
    // begin the batch edit mode
    beginBatchEdit();

    m_view->getTextLayout()->setSelection(VfxTextRange(start, end));

    // because when set cursor position, the selection is not set, so the cursor position is not correct
    // we need re-calculate the cursor position for mask character.
    if (m_view->getTextLayout()->getMask())
    {
        m_cursor->setIndex(m_cursor->getIndex());
    }

    // TODO:
    ret = end - start;

    // begin the batch edit mode
    endBatchEdit();

    return ret;
}


void VcpEditing::getSelection(VfxS32 *start, VfxS32 *end)
{
    VfxTextRange selection = m_view->getTextLayout()->getSelection();
    *start = selection.getStart();
    *end = selection.getEnd();
}


VfxWChar* VcpEditing::getText()
{
    return (VfxWChar*)m_view->getTextStorage()->getText();
}


void VcpEditing::setIMEUILayout(
        VfxS32 x,       // The x coordinate of IME UI rectangle
        VfxS32 y,       // The y coordinate of IME UI rectangle
        VfxS32 width,   // The width of IME UI rectangle
        VfxS32 height,   // The height of IME UI rectangle
        VfxS32 vkX,       // The x coordinate of VK rectangle
        VfxS32 vkY,       // The y coordinate of VK  rectangle
        VfxS32 vkWidth,   // The width of VK  rectangle
        VfxS32 vkHeight,   // The height of VK  rectangle
        VfxBool isAnim     // If need animation
        )
{
    VfxRect imeRect(x, y, width, height);
    VfxRect vkRect(vkX, vkY, vkWidth, vkHeight);

    // should hide clipboard menu first, otherwise, the menu position will be wrong
#if VCP_TEXT_CLIPBOARD_SUPPORT
    if (m_view->m_clipboard)
    {
        // hide clipboard menu
        m_view->m_clipboard->hideMenu();
    }
#endif

    if (m_functionBarPtr != NULL)
    {
        vrt_size_struct mainScreenSize;
        vrt_color_type_enum mainScreenColorFormat;
        vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);
        
        if (vkRect.size.width != 0 && vkRect.size.height != 0 )
        {
            if (vkRect.size.height == imeRect.size.height)
            {
#if 1
                //VfxAutoAnimate::begin();
                //VfxAutoAnimate::setDisable(!isAnim);
                //VfxAutoAnimate::setDuration(100);

                if (isAnim)
                {
                    if (!m_showFunctionBarTimeline)
                    {
                        VFX_OBJ_CREATE(m_showFunctionBarTimeline, VfxPointTimeline, this);
                    }

                    m_showFunctionBarTimeline->setTarget(m_functionBarPtr.get());
                    m_showFunctionBarTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                    // show from the bottom of screen
                    m_showFunctionBarTimeline->setFromValue(VfxPoint(mainScreenSize.width / 2, mainScreenSize.height));
                    m_showFunctionBarTimeline->setToValue(VfxPoint(mainScreenSize.width / 2, vkRect.origin.y - m_functionBarPtr->getSize().height));
                    m_showFunctionBarTimeline->setDurationTime(VfxAutoAnimate::getDuration());
                    m_showFunctionBarTimeline->start();
                    m_functionBarPtr->setPos(mainScreenSize.width / 2, vkRect.origin.y - m_functionBarPtr->getSize().height);
                }
                else
                {
                    // no animate
                    VfxAutoAnimate::begin();
                    VfxAutoAnimate::setDisable(VFX_TRUE);
                    m_functionBarPtr->setPos(mainScreenSize.width / 2, vkRect.origin.y - m_functionBarPtr->getSize().height);
                    VfxAutoAnimate::commit();

                    if (m_showFunctionBarTimeline) 
                    {
                        m_showFunctionBarTimeline->stop();
                        m_functionBarPtr->forcePos(VfxPoint(mainScreenSize.width / 2, vkRect.origin.y - m_functionBarPtr->getSize().height));
                    }
                }

                //VfxAutoAnimate::commit();
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
                m_functionBarPtr->setHidden(VFX_FALSE);

                imeRect.origin.y -= (m_functionBarPtr->getSize().height - VCP_TEXT_EDITOR_FUNCTION_BAR_SHADOW);
                imeRect.size.height += (m_functionBarPtr->getSize().height - VCP_TEXT_EDITOR_FUNCTION_BAR_SHADOW);
            }
            else
            {
                m_functionBarPtr->setHidden(VFX_TRUE);
                m_functionBarPtr->setPos(mainScreenSize.width / 2, vkRect.origin.y - m_functionBarPtr->getSize().height);
                if (m_showFunctionBarTimeline) 
                {
                    m_showFunctionBarTimeline->stop();
                    m_functionBarPtr->forcePos(VfxPoint(mainScreenSize.width / 2, vkRect.origin.y - m_functionBarPtr->getSize().height));
                }
            }
        }
        else if (!m_functionBarPtr->getHidden())
        {
            if (m_showFunctionBarTimeline) 
            {
                m_showFunctionBarTimeline->stop();
            }

            if (isAnim)
            {
                if (!m_hideFunctionBarTimeline)
                {
                    VFX_OBJ_CREATE(m_hideFunctionBarTimeline, VfxPointTimeline, this);
                }

                m_hideFunctionBarTimeline->setTarget(m_functionBarPtr.get());
                m_hideFunctionBarTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
                m_hideFunctionBarTimeline->setIsFromCurrent(VFX_TRUE);
                m_hideFunctionBarTimeline->setToValue(VfxPoint(mainScreenSize.width / 2, mainScreenSize.height));

                // to sync the function bar and VK animation, we calculate the duration according to moved distance
                VfxS32 vkDurationT = VfxAutoAnimate::getDuration();
                VfxS32 fbDistance = mainScreenSize.height - m_functionBarPtr->getPos().y;
                VfxS32 vkDistance = fbDistance - m_functionBarPtr->getSize().height;
                VfxS32 fbDurationT;
                if (vkDistance)
                {
                    fbDurationT = (vkDurationT * fbDistance) / vkDistance;
                }
                else
                {
                    fbDurationT = vkDurationT;
                }
                m_hideFunctionBarTimeline->setDurationTime(fbDurationT);
                m_hideFunctionBarTimeline->m_signalStopped.connect(this, &VcpEditing::onHideFunctionBarTimelineStoppped);
                m_hideFunctionBarTimeline->start();
                m_functionBarPtr->setPos(mainScreenSize.width / 2, mainScreenSize.height);
            }
            else
            {
                m_functionBarPtr->setHidden(VFX_TRUE);
                m_functionBarPtr->setPos(mainScreenSize.width / 2, mainScreenSize.height - m_functionBarPtr->getSize().height);
            }
        }
        else
        {
            if (m_showFunctionBarTimeline) 
            {
                m_showFunctionBarTimeline->stop();
            }
            m_functionBarPtr->setPos(mainScreenSize.width / 2, mainScreenSize.height - m_functionBarPtr->getSize().height);
            m_functionBarPtr->forcePos(VfxPoint(mainScreenSize.width / 2, mainScreenSize.height - m_functionBarPtr->getSize().height));
        }
    }

    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);

    if (topLevel)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(!isAnim);
                
        if (imeRect.size.width == 0 || imeRect.size.height == 0)
        {
            topLevel->resetIMElayout();

            // if editor content empty, deactivate editor
            if (m_view && m_view->m_editing && m_view->getLength() == 0 && m_view->isActive() &&
                ((VcpTextEditor *)m_view)->m_isDeactivateWhenHideVK)
            {
                vfxPostInvoke1((VcpTextEditor *)m_view, &VcpTextEditor::deactivate, VFX_TRUE);
            }
        }
        else
        {
            // use m_cursor instead of m_view as IME owner frame because when input character,
            // we need to assure the cursor is visible.
            // topLevel->setIMElayout(imeRect, m_view);
            if (m_view->m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
            {
                topLevel->setIMElayout(imeRect, m_view);
            }
            else
            {
                // scroll cursor in visible area
                scrollViewForCursor();
                topLevel->setIMElayout(imeRect, m_cursor);
            }
        }

        VfxAutoAnimate::commit();
    }
}


void VcpEditing::onHideFunctionBarTimelineStoppped(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    vrt_size_struct mainScreenSize;
    vrt_color_type_enum mainScreenColorFormat;
    vrt_sys_get_main_screen_info(&mainScreenSize, &mainScreenColorFormat);
        
    if (m_functionBarPtr != NULL && isCompleted && m_functionBarPtr->getPos() == VfxPoint(mainScreenSize.width / 2, mainScreenSize.height))
    {
        m_functionBarPtr->setHidden(VFX_TRUE);
        // set to correct position for VK out animation
        m_functionBarPtr->setPos(mainScreenSize.width / 2, mainScreenSize.height - m_functionBarPtr->getSize().height);
    }
}


VcpTextCursor* VcpEditing::getCursor()
{
    return m_cursor;
}


VfxS32 VcpEditing::getCursorIndex(VfxBool isSkipIcon)
{
    if (m_cursor)
    {
        if (isSkipIcon)
        {
            VfxS32 curIdx = m_cursor->getIndex();
            VcpRichTextFormat *obj = m_view->m_layout->getObjectOfIndex(curIdx - 1);

            while (obj)
            {
                if ((obj->getType() == VCP_RICH_TEXT_TYPE_IMAGE) &&
                    (curIdx > obj->m_range.getStart() && (curIdx <= obj->m_range.getEnd())))
                {
                    curIdx = obj->m_range.getStart();
                }
                obj = m_view->m_layout->getObjectOfIndex(curIdx - 1);
            }
            return curIdx;
        }
        else
        {
            return m_cursor->getIndex();
        }
    }
    else
    {
        return 0;
    }
}


VfxBool VcpEditing::getCursorRect(
        VfxS32 *x,       // The x coordinate of cursor, should be related to the whole screen
        VfxS32 *y,       // The y coordinate of cursor, should be related to the whole screen
        VfxS32 *width,   // The width of cursor
        VfxS32 *height   // The height of cursor
        )
{
    if (m_cursor && m_cursor->getActiveInstance() == m_cursor)
    {
        VfxRect cursorRect = m_cursor->getBounds();

        cursorRect = m_cursor->convertRectTo(m_cursor->getBounds(), VFX_OBJ_GET_INSTANCE(VfxTopLevel));

        *x = cursorRect.origin.x;
        *y = cursorRect.origin.y;
        *width = cursorRect.getWidth();
        *height = cursorRect.getHeight();

        return VFX_TRUE;
    }
    else
    {
        *x = 0;
        *y = 0;
        *width = 0;
        *height = 0;
        return VFX_FALSE;
    }
}


VfxBool VcpEditing::sendIMENotification(InputNotificationEnum notificationID, void *data)
{
    switch (notificationID)
    {
    case IME_NOTIFICATION_PEN_DOWN_IN_IMUI_CONTROL:
#if VCP_TEXT_CLIPBOARD_SUPPORT
        m_view->m_clipboard->hideMenu();
#endif
        break;
	case IME_NOTIFICATION_SHOW_IME_POPUP:
#if VCP_TEXT_CLIPBOARD_SUPPORT
        m_view->m_clipboard->hideMenu();
#endif
		((VcpTextEditor *)m_view)->m_isShowIMEPopup = VFX_TRUE;
        break;
	case IME_NOTIFICATION_CLOSE_IME_POPUP:
		((VcpTextEditor *)m_view)->m_isShowIMEPopup = VFX_FALSE;
		break;

    case IME_NOTIFICATION_DEACTIVATED_BY_INTERRUPT:
    case IME_NOTIFICATION_DEACTIVATE_EDITOR:
        m_view->deactivate();
        break;

    case IME_NOTIFICATION_ACTIVATE_EDITOR:
        m_view->activate();
        break;

    case IME_NOTIFICATION_QUERY_CLIENT_SSP_STATE:
        if (m_view->m_view->m_isDecelerating)
            return VFX_TRUE;
        else
            return VFX_FALSE;

    case IME_NOTIFICATION_IF_DEACTIVATE_BY_PEN_INTERRUPT:
        {
            VfxPenEvent* event = (VfxPenEvent*)data;

            VfxPoint point = event->getRelPos(m_view);
            
            if (m_view->hitTest(point))
            {
                return VFX_FALSE;
            }
#if VCP_TEXT_CLIPBOARD_SUPPORT
            if (m_view->m_clipboard && m_view->m_clipboard->hitTest(*event))
            {
                return VFX_FALSE;
            }
#endif
            if (m_functionBarPtr != NULL)
            {
                VfxPoint fbPoint = event->getRelPos(m_functionBarPtr.get());
                
                if (m_functionBarPtr->hitTest(fbPoint))
                {
                    return VFX_FALSE;
                }
            }

            if (!(((VcpTextEditor *)m_view)->m_autoDeactivated))
            {
                return VFX_FALSE;
            }
        }
        break;
    case IME_NOTIFICATION_SPECIAL_VK_ENTER_KEY_CLICKED:
        m_signalEnterKeyClicked.postEmit(m_view, m_inputBinding.m_vkEnterKeyStyle);
        break;

    case IME_NOTIFICATION_FREEZ_ACTIVE_STATE:
        ((VcpTextEditor *)m_view)->m_freezActiveState = *((VfxBool *)data);
        break;
        
    case IME_NOTIFICATION_IS_CLIPBOARD_STATE:
        return m_view->m_isSelectingText;

    default:
        break;
    }

    return VFX_TRUE;
}


void VcpEditing::onTextChanged(VfxS32 start, VfxS32 end, VfxS32 changedCharCount, VcpTextStorage::TextChangeEnum changed)
{
    if (m_batchEdit > 0)
    {
        // when end batch edit, the m_signalTextChanged will be postEmit
    }
    else
    {
        m_signalTextChanged.emit(m_view);
    }
}


VfxU32 VcpEditing::testInput(VfxWChar ch)
{
    VfxWChar string[2] = {ch, 0};

    // only check the validation according to current input method
    // don't check app's validation because it will check before insert char again.
    // if we check here, it will degrade the performance
    if (m_inputManager && m_inputManager->isValidInputStringForPaste((VfxWChar*)string, 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


VfxU32 VcpEditing::testInput(VfxWChar *text)
{
    VfxU32 i;
    for (i = 0; i < vfx_sys_wcslen(text); i++)
    {
        if (testInput(text[i]) == 0)
        {
            break;
        }
    }

    return i;
}


/***************************************************************************** 
 * Class VcpTextCursor
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpTextCursor", VcpTextCursor, VfxFrame);

VcpTextCursor* VcpTextCursor::s_activeCursor = NULL;

VcpTextCursor::VcpTextCursor()
{

}


void VcpTextCursor::onInit()
{
    VfxFrame::onInit();
    
    VcpTextView *view = (VcpTextView*)(((VcpTextScrollView*)getParentFrame())->getTextView());

    setIndex(-1);
#if defined(__COSMOS_MMI_PACKAGE__)
    setBgColor(VFX_COLOR_RES(VCP_COL_TEXT_EDITOR_CURSOR));
#else
    setBgColor(VFX_COLOR_RED);
#endif

    setBounds(0, 0, VCP_EDITOR_CURSOR_WIDTH, VCP_EDITOR_CURSOR_HEIGHT);
    m_moveType = LOGIC_MOVE;
    
    // init click timer
    VFX_OBJ_CREATE(m_blinkTimer, VfxTimer, this);
    
    m_blinkTimer->setStartDelay(VCP_TEXT_EDITOR_CURSOR_BLINK_TIME);
    m_blinkTimer->m_signalTick.connect(this, &VcpTextCursor::onBlink);
    m_isHidden = VFX_TRUE;

    setOpacity(0);
    
    m_moveStartX = -1;
}


void VcpTextCursor::onDeinit()
{
    setVisible(VFX_FALSE);
    
    VfxFrame::onDeinit();    
}


void VcpTextCursor::setIndex(VfxS32 index, VfxPoint * newPos, VfxBool needSetPos) 
{ 
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TEC", SA_start);
#endif
    VfxS32 oldIndex = m_logicIndex;

    VcpTextView *view = (VcpTextView*)(((VcpTextScrollView*)getParentFrame())->getTextView());
    VfxPoint pos;

    // DO not change cursor index when hide cursor style except select text mode
    if (((VcpTextEditor *)view)->m_isHideCursor && !view->m_isSelectingText)
    {
        index = view->getLength();
    }

    // Adjust cursor position for icon
    if (view->m_storage->getRichTextFormat())
    {
        VcpRichTextFormat *obj = view->m_layout->getObjectOfIndex(index);
        if (obj && (obj->getType() == VCP_RICH_TEXT_TYPE_IMAGE) &&
            (index > obj->m_range.getStart() && (index < obj->m_range.getEnd())))
        {
            index = obj->m_range.getEnd();
        }
    }

    m_logicIndex = index;

    if (!needSetPos)
    {
        // notify only when index changes
        if (oldIndex != index && view->m_editing != NULL && view->m_editing->m_batchEdit == 0)
        {
            // not notify IME when cursor after icon object
            // to avoid ime change caps for icon
          //  if (!(view->m_layout->isIndexAfterObject(index)))
            {
                // notify IME
                VfxRect cursorRect = convertRectTo(getBounds(), VFX_OBJ_GET_INSTANCE(VfxTopLevel));

                if (view->m_editing->m_inputManager)
                {
                    view->m_editing->m_inputManager->cursorPosChanged(cursorRect);
                }
            }

            // notify APP
            m_signalCursorIndexChanged.postEmit(this);
        }


#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TEC", SA_stop);
#endif
        return;
    }

    // should not set cursor index if layout is not done because the line info is incorrect in that case
    VfxTextRange dirtyRange = view->getTextLayout()->getDirtyRange();
    if (dirtyRange.getLength() > 0 && dirtyRange.getStart() <= index)
    {
    #if defined(__COSMOS_MMI_PACKAGE__)
		if (dirtyRange.getLength() > VCP_MIN_LAYOUT_CHARS)
		{
			// show waiting indicator
			if (view->m_waitingInd == NULL)
			{
				VFX_OBJ_CREATE(view->m_waitingInd, VcpActivityIndicator, VFX_OBJ_GET_INSTANCE(VfxTopLevel));
				vrt_size_struct mainScreenSize;
				vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
				view->m_waitingInd->setAnchor(0.5f, 0.5f);
				view->m_waitingInd->setPos(mainScreenSize.width / 2, mainScreenSize.height / 2);
				view->m_waitingInd->setPosZ(VFX_TOP_LEVEL_Z_IME_UI - 1);
				view->m_waitingInd->setSize(VCP_TEXTVIEW_WAITING_ICON_SIZE, VCP_TEXTVIEW_WAITING_ICON_SIZE);
			}
			view->m_waitingInd->start();
		}
    #endif
        // hide cursor
        setHidden(VFX_TRUE);

#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TEC", SA_stop);
#endif
        return;
    }
    else
    {
        setHidden(VFX_FALSE);
    #if defined(__COSMOS_MMI_PACKAGE__)
        if (view->m_waitingInd)
        {
            VFX_OBJ_CLOSE(view->m_waitingInd);
            //view->m_waitingInd->stop();
        }
    #endif
        // adjust the index for some special language when layout is done
        index = view->adjustIndexForLanguage(index);
        m_logicIndex = index;
    }
    
    if (newPos == NULL)
    {
        pos = view->getTextLayout()->getPosOfIndex(index);
    }
    else
    {
        pos = *newPos;
        m_moveStartX = pos.x;
    }

    if (getPos() != pos)
    {
        setPos(pos);
    }

    VfxS32 lineCount = view->getTextLayout()->getLineCount();

    if (lineCount > 0)
    {
        // if not in init stage, set the cursor size
        VfxS32 lineIndex = view->getTextLayout()->getLineIndex(index);
        VfxRect lineRect = view->getTextLayout()->getLineBounds(lineIndex);
        if (!(view->getTextLayout()->isIndexInCurrentLine(index, pos)))
        {
            /* If Cursor locate at the last position of line the lineInex will be the next line,
               so in this case, we should use the (lineIndex - 1) as the real line index */
            lineRect = view->getTextLayout()->getLineBounds(lineIndex - 1);
        }

        setSize(
            getSize().width,
            VFX_MIN(view->m_view->getBounds().getHeight(), (lineRect.getMaxY() - pos.y + 1)));
    }

    // notify IME
    if (view->m_editing != NULL)
    {
        // if auto font size mode, the text will always be in visible area and will not
        // scroll to invisible area. Also to fix the scroll bar will flash in some time when
        // update layout for correct font size
        if (!view->m_autoFontSize)
        {
            view->m_editing->scrollViewForCursor();
        }

        // not notify IME when cursor after icon object
        // to avoid ime change caps for icon
   //     if (!(view->m_layout->isIndexAfterObject(index)))
        {
            VfxRect cursorRect = convertRectTo(getBounds(), VFX_OBJ_GET_INSTANCE(VfxTopLevel));
            
            if (view->m_editing->m_inputManager && (oldIndex != index))
            {
                view->m_editing->m_inputManager->cursorPosChanged(cursorRect);
            }
        }
    }

    // when delete/insert text, setIMELayout will not be called, so we call parent's updateViewForIme directly
    // should adjust after scrollViewForCursor
    updateViewForCursor();

    // notify APP
    if (oldIndex != index)
    {
        // notify only when index changes
        m_signalCursorIndexChanged.postEmit(this);
    }

    if (s_activeCursor == this)
    {
        directDraw(VFX_TRUE);
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TEC", SA_stop);
#endif
}


void VcpTextCursor::updateViewForCursor()
{
    // when delete/insert text, setIMELayout will not be called, so we call parent's updateViewForIme directly
    // as a tricky way.
    if (!getPos().isZero()) // only when cursor position is ready
    {
        VcpTextView *view = (VcpTextView*)(((VcpTextScrollView*)getParentFrame())->getTextView());
        VfxFrame *viewParent = (VfxFrame*)(view->getParentFrame());
        if (view && (view->m_lineMode == VCP_TEXT_LINE_MODE_MULTI))
        {
            while (viewParent)
            {
                // if multiline, we always makes cursor to be visible, so use this(cursor) as focusFrame
                // because if the multiline height is large, it is impossible to adjust view (form/list) to
                // make multiline appear
                if (viewParent->processUpdateViewForIme(this))
                {
                    break;
                }
                viewParent = (VfxFrame*)(viewParent->getParentFrame());
            }
        }
        else
        {
            while (viewParent)
            {
                // if singleline, we always makes editor to be visible, so use view(editor) as focusFrame
                if (viewParent->processUpdateViewForIme(view))
                {
                    break;
                }
                viewParent = (VfxFrame*)(viewParent->getParentFrame());
            }
        }
    }
}


void VcpTextCursor::setVisible(VfxBool visible)
{
    if (visible)
    {
        if (s_activeCursor != this)
        {
            s_activeCursor = this;
        }
        
        m_isHidden = VFX_FALSE;
        
        if (flash())
        {
            m_blinkTimer->start();
        }
    }
    else
    {
        if (s_activeCursor == this)
        {
            s_activeCursor = NULL;
        }

        if (flash())
        {
            m_blinkTimer->stop();
        }
        
        m_isHidden = VFX_TRUE;
    }
}


void VcpTextCursor::directDraw(VfxBool show)
{
    if (show)
    {
        m_isHidden = VFX_FALSE;
    }
    else
    {
        m_isHidden = VFX_TRUE;
    }

    if (flash())
    {
        m_blinkTimer->start();
    }
}


void VcpTextCursor::onBlink(VfxTimer *timer)
{
    VFX_UNUSED(timer);
    
    m_isHidden = !m_isHidden;
    
    m_blinkTimer->start();
}


VfxS32 VcpTextCursor::previousLine()
{
    VcpTextView *view = (VcpTextView*)(((VcpTextScrollView*)getParentFrame())->getTextView());
    VfxS32 ret = 0;

    VfxS32 newIndex = 0;
    if (m_moveStartX < 0)
    {
        m_moveStartX = getPos().x;
    }

    newIndex = view->getTextLayout()->getIndexOfPreLine(m_logicIndex, m_moveStartX);

    // Adjust cursor position for icon
    if (view->m_storage->getRichTextFormat())
    {
        VcpRichTextFormat *obj = view->m_layout->getObjectOfIndex(newIndex);
        if (obj && (obj->getType() == VCP_RICH_TEXT_TYPE_IMAGE) &&
            (newIndex > obj->m_range.getStart() && (newIndex < obj->m_range.getEnd())))
        {
            newIndex = obj->m_range.getEnd();
        }
    }

    // If first line
    if (newIndex < 0)
    {
        ret = 0;
    }
    else
    {
        ret = 1;
        setIndex(newIndex);
    }

    return ret;
}


VfxS32 VcpTextCursor::previous()
{
    return previous(1);
}


VfxS32 VcpTextCursor::previous(VfxS32 steps)
{
    if (m_moveType == LOGIC_MOVE)
    {
        VfxS32 newIndex = m_logicIndex - steps;

        // Adjust cursor position for icon
        VcpTextView *view = (VcpTextView*)(((VcpTextScrollView*)getParentFrame())->getTextView());
        if (view->m_storage->getRichTextFormat())
        {
            VcpRichTextFormat *obj = view->m_layout->getObjectOfIndex(newIndex);
            if (obj && obj->getType() != VCP_RICH_TEXT_TYPE_TEXT && obj->getType() != VCP_RICH_TEXT_TYPE_HYPERLINK)
            {
                newIndex = obj->m_range.getStart();
            }
        }

        // if reach to first position, loop to last position
        if (newIndex < 0)
        {
            newIndex = view->m_editing->length();
        }
        // set cursor new position

        newIndex = view->adjustIndexForLanguage(newIndex, VFX_TRUE);
        setIndex(newIndex);
    }
    else
    {
        // TODO:
    }
    m_moveStartX = -1;
    
    return steps;
}


VfxS32 VcpTextCursor::nextLine()
{
    VcpTextView *view = (VcpTextView*)(((VcpTextScrollView*)getParentFrame())->getTextView());
    VfxS32 newIndex = 0;
    VfxS32 ret = 0;

    if (m_moveStartX < 0)
    {
        m_moveStartX = getPos().x;
    }

    newIndex = view->getTextLayout()->getIndexOfNextLine(m_logicIndex, m_moveStartX);

    // Adjust cursor position for icon
    if (view->m_storage->getRichTextFormat())
    {
        VcpRichTextFormat *obj = view->m_layout->getObjectOfIndex(newIndex);
        if (obj && (obj->getType() == VCP_RICH_TEXT_TYPE_IMAGE) &&
            (newIndex > obj->m_range.getStart() && (newIndex < obj->m_range.getEnd())))
        {
            newIndex = obj->m_range.getEnd();
        }
    }

    // If last line
    if (newIndex > view->m_editing->length())
    {
        newIndex = view->m_editing->length();
        ret = 0;
    }
    else if (newIndex < 0)
    {
        // return 0 to play warning tone
        ret = 0;
    }
    else
    {
        ret = 1;
    }

    if (ret)
    {
        setIndex(newIndex);
    }
    return ret;
}


VfxS32 VcpTextCursor::next()
{
    return next(1);
}


VfxS32 VcpTextCursor::next(VfxS32 steps)
{
    VcpTextView *view = (VcpTextView*)(((VcpTextScrollView*)getParentFrame())->getTextView());
    if (m_moveType == LOGIC_MOVE)
    {
        VfxS32 newIndex = m_logicIndex + steps;

        // Adjust cursor position for icon
        if (view->m_storage->getRichTextFormat())
        {
            VcpRichTextFormat *obj = view->m_layout->getObjectOfIndex(newIndex - 1);
            if (obj && (obj->getType() == VCP_RICH_TEXT_TYPE_IMAGE))
            {
                newIndex = obj->m_range.getEnd();
            }
        }

        // if reach to last position, loop to first position
        if (newIndex > view->m_editing->length())
        {
            newIndex = 0;
        }

        // set cursor new position
        setIndex(newIndex);
    }
    else
    {
        // TODO:
    }
    m_moveStartX = -1;
    return steps;
}


vrt_render_dirty_type_enum VcpTextCursor::framePropertyEffectCallback(
        vrt_frame_visual_property_struct *target_frame,
        const vrt_frame_visual_property_struct *watch_frame,
        void *user_data,
        vrt_u32 user_data_size)
{
    VFX_DEV_ASSERT(target_frame != NULL);
    VFX_DEV_ASSERT(watch_frame != NULL);
    
    VcpTextCursor *cursor = (VcpTextCursor *)(VfxObject::handleToObject(*(VfxObjHandle *)user_data));

    if (cursor == NULL)
    {
        return VRT_RENDER_DIRTY_TYPE_NONE;
    }

    if (target_frame->opacity == 1.0f)
    {
        if (cursor->m_isHidden == VFX_TRUE)
        {
            target_frame->opacity = 0;
            return VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
    }

    if (target_frame->opacity == 0)
    {
        if (cursor->m_isHidden == VFX_FALSE)
        {
            VfxBool allowShow = VFX_TRUE;
            VcpTextScrollView *sView =  (VcpTextScrollView*)(cursor->getParentFrame());
            VcpTextView *view = NULL;
            if (sView)
            {
                view = (VcpTextView*)(sView->getTextView());
            }
            else
            {
                return VRT_RENDER_DIRTY_TYPE_NONE;
            }

            if (view == NULL)
            {
                return VRT_RENDER_DIRTY_TYPE_NONE;
            }

            VfxTextRange dirtyRange = view->getTextLayout()->getDirtyRange();
            if (dirtyRange.getLength() > 0 && dirtyRange.getStart() < cursor->getIndex())
            {
                allowShow = VFX_FALSE;
            }
            // if pos not sync, do not show cursor
            // if layout is not done, do not show cursor
            if ((target_frame->pos.x != cursor->getPos().x) || (target_frame->pos.y != cursor->getPos().y) || !allowShow)
            {
                target_frame->opacity = 0;
            }
            else
            {
                target_frame->opacity = 1;
            }
            return VRT_RENDER_DIRTY_TYPE_DIRTY;
        }
    }

    return VRT_RENDER_DIRTY_TYPE_NONE;
}

/***************************************************************************** 
 * Class VcpTextCounter
 *****************************************************************************/
VcpTextCounter::VcpTextCounter()
{
}


void VcpTextCounter::onInit()
{
    VfxTextFrame::onInit();

    setAnchor(1.0, 0);
    setAlignMode(ALIGN_MODE_CENTER);
    setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCP_EDITOR_COUNTER_FONT_SIZE)));
    setBgColor(VRT_COLOR_MAKE(150, 64, 64, 64));
    setMargins(VCP_EDITOR_COUNTER_LR_MARGIN, VCP_EDITOR_COUNTER_TD_MARGIN, VCP_EDITOR_COUNTER_LR_MARGIN, VCP_EDITOR_COUNTER_TD_MARGIN);
    setFullLineHeightMode(VFX_FALSE);
}


void VcpTextCounter::onTextChanged(VfxS32 start, VfxS32 end, VfxS32 changedCharCount, VcpTextStorage::TextChangeEnum changed)
{
    updateCounter();
}


void VcpTextCounter::updateCounter()
{
    VfxS32 used = 0, max = 0;
    VfxWString outString;

    VcpTextView *view = (VcpTextView *)getParent();

    used = view->getTextStorage()->getTextEncodingLength();

    max = view->getTextStorage()->getMaxLength();
    
    outString.format("%d/%d", used, max);

    setString(outString);

}


void VcpTextCounter::setOwner(VcpTextView *view)
{
    //setParent(view);
    view->getTextStorage()->m_signalTextChanged.connect(this, &VcpTextCounter::onTextChanged);
    view->m_signalBoundsChanged.connect(this, &VcpTextCounter::onParentBoundsChanged);
}


void VcpTextCounter::onParentBoundsChanged(VfxFrame *frame, const VfxRect &rect)
{
    setPos(frame->getSize().width - VCP_EDITOR_COUNTER_POS, VCP_EDITOR_COUNTER_POS);
}


VfxBool VcpTextCounter::onContainPoint(const VfxPoint &point) const
{
    return VFX_FALSE;
}
