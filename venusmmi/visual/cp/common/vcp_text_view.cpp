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
 *  vcp_textview.cpp
 *
 * Project:
 * --------
 *  Venus MMI
 *
 * Description:
 * ------------
 *  textview class
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
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "mmi_features.h"
#include "vcp_text_view.h"
#include "vcp_text_editor.h"
#include "mmi_rp_srv_venus_component_text_view_def.h"
#include "vadp_sys_trc.h"
#include "vfx_adp_device.h"

#if defined(__COSMOS_MMI_PACKAGE__)
#include "vcp_info_balloon.h"
#include "mmi_rp_app_cosmos_global_def.h"
#endif

#include "mmi_rp_srv_editor_def.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_scrollable.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"

#include "vcp_text_layout.h"
#include "vfx_signal.h"
#include "vcp_text_storage.h"
#include "vsrv_clipboard.h"
#include "vfx_image_src.h"
#include "vfx_draw_context.h"
#include "vfx_frame.h"
#include "vrt_datatype.h"
#include "vfx_basic_type.h"
#include "MMIDataType.h"
#include "vrt_system.h"
#include "vcp_text_utils.h"
#include "vfx_string.h"
#include "vfx_font_desc.h"
#include "vfx_stream.h"
#include "lcd_sw_inc.h"
#include "vfx_input_event.h"
    
extern "C"
{
#include "mmi_frm_input_gprot.h"
}


/*
SWLA labels:
TE1    VcpTextEditor::onInit
TE2    VcpTextEditor::activateInternal
TEI    VcpEditing::insertText
TED    VcpEditing::deleteChars
TEC    VcpTextCursor::setIndex

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

/***************************************************************************** 
 * Class Defination
 *****************************************************************************/
#define SCROLL_NONE                          0
#define SCROLL_TO_RIGHT                      1
#define SCROLL_TO_LEFT                       2
#define SCROLL_TO_UP                         3
#define SCROLL_TO_DOWN                       4

// adjust view offset of singleline when selecting text
#define VCP_TEXT_VIEW_ADJUST_OFFSET          20

// adjust finger touch area to be upwards for better UE
#ifdef __TOUCH_PANEL_CAPACITY__
#if defined(__MMI_MAINLCD_480X800__)
#define VCP_TEXT_VIEW_TOUCH_OFFSET           10
#else
#define VCP_TEXT_VIEW_TOUCH_OFFSET            5
#endif
#else
#define VCP_TEXT_VIEW_TOUCH_OFFSET            0
#endif


// pen move offset
#if defined(__MMI_MAINLCD_480X800__)
#define VCP_TEXT_VIEW_TOUCH_MOVE_OFFSET           10
#else
#define VCP_TEXT_VIEW_TOUCH_MOVE_OFFSET            5
#endif

/***************************************************************************** 
 * Class VcpTextView
 *****************************************************************************/

VFX_IMPLEMENT_CLASS(VCP_TEXTVIEW_CLASS_NAME, VcpTextView, VcpScrollable);

VcpTextView::VcpTextView()
{
    m_storage = NULL;
    m_layout = NULL;
    m_minHeight = 0;
    m_maxHeight = 0x7FFFFFFF;
    m_lineMode = VCP_TEXT_LINE_MODE_MULTI;
    m_countOfCellView = 0;
    m_scrollWarning = 0;
    m_scrollDir = SCROLL_NONE;
    m_editing = NULL;
    m_activated = VFX_FALSE;
    m_leftMargin = m_rightMargin = m_topMargin = m_bottomMargin = VCP_TEXTVIEW_DEFAULT_MARGIN;
    m_autoResized = VFX_FALSE;
    m_autoFontSize = VFX_FALSE;
    m_checkForceUpdate = VFX_FALSE;
    m_autoResizedMaxValue = -1;
    m_autoResizedMinValue = -1;
    m_progressValue = -1;
    m_progressFrame = NULL;
    m_isDisableBg = VFX_TRUE;
    m_isDisableClipboard = VFX_FALSE;
    m_isDisableMagnifier = VFX_FALSE;
    m_marginFrame = NULL;
    m_normalBgImageId = VCP_IMG_TEXT_VIEW_NORMAL_BG;
    m_hiliteBgImageId = VCP_IMG_TEXT_VIEW_HIGHLIGHT_BG;
    m_orgFontSize = 0;
    m_isUpdating = VFX_FALSE;
    m_scrollTimer = NULL;
#if VCP_TEXT_CLIPBOARD_SUPPORT
    m_clipboard = NULL;
#endif
    m_clipboardTimer = NULL;
    m_isSelectingText = VFX_FALSE;
    m_selStart = 0;
    m_isMagnifierState = VFX_FALSE;
#if VCP_TEXT_MAGNIFIER_SUPPORT
    m_magnifier = NULL;
    m_magnifierTimer = NULL;
#endif
    m_bgImageFrame = NULL;
#if defined(__COSMOS_MMI_PACKAGE__)
    m_waitingInd = NULL;
#endif
    m_setValidRectTimer = NULL;
    m_visibleStartIndex = -1;
    m_scrollVisibleTimer = NULL;
}

#if 0
/* under construction !*/
/* under construction !*/
#if VCP_TEXT_MAGNIFIER_SUPPORT
/* under construction !*/
#endif
#endif


void VcpTextView::onInit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TV1", SA_start);
#endif
    VFX_OBJ_CREATE(m_bgImageFrame, VfxFrame, this);

    VcpScrollable::onInit();

    // create textStorage
    VFX_ALLOC_NEW_EX(m_storage, VcpTextStorage, this, (this));

    setLayout();

    m_view->m_signalBoundsChanged.connect(this, &VcpTextView::onViewBoundsChanged);
    m_signalScrollStarted.connect(this, &VcpTextView::notifyScrollStart);
    m_signalScrollStopped.connect(this, &VcpTextView::notifyScrollEnd);
    m_signalContentWarning.connect(this, &VcpTextView::onContentWarning);
    m_signalContentError.connect(this, &VcpTextView::onContentError);

    enableHorizontalScrollIndicator(VFX_FALSE);

#if VCP_TEXT_CLIPBOARD_SUPPORT
    VFX_OBJ_CREATE_EX(m_clipboard, VsrvClipboard, this, (this));
    m_clipboard->m_signalClipboardEvent.connect(this, &VcpTextView::onClipboardEvent);
#endif
    VFX_OBJ_CREATE(m_clipboardTimer, VfxTimer, this);
    m_clipboardTimer->setStartDelay(VCP_TEXTVIEW_CLIPBOARD_START_TIMER);
    m_clipboardTimer->m_signalTick.connect(this, &VcpTextView::onClipboardTimer);

    if (!m_isDisableBg)
    {
        m_bgImageFrame->setImgContent(VfxImageSrc(m_normalBgImageId));
    }
    m_bgImageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bgImageFrame->setAutoAnimate(VFX_TRUE);

    // set Original font size
    m_orgFontSize = m_layout->m_font.size;

#if VCP_TEXT_MAGNIFIER_SUPPORT
    VFX_OBJ_CREATE(m_magnifierTimer, VfxTimer, this);
  //  m_magnifierTimer->setStartDelay(VCP_TEXT_MAGNIFIER_START_TIMER);
    m_magnifierTimer->setStartDelay(VCP_TEXT_MAGNIFIER_START_TIMER);
    m_magnifierTimer->m_signalTick.connect(this, &VcpTextView::onMagnifierTimer);
#endif

    setAutoAnimate(VFX_TRUE);

    // register access key for UNK and DNK
    registerKeyHandler(VFX_KEY_CODE_ARROW_UP);
    registerKeyHandler(VFX_KEY_CODE_ARROW_DOWN);

#if defined(__COSMOS_MMI_PACKAGE__)
    // set theme color
    setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    setColor(VCP_TEXT_HINT_TEXT_COLOR, VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
    setColor(VCP_TEXT_UNDERLINE_COLOR, VFX_COLOR_RES(CLR_COSMOS_TEXT_LINK));
#endif

    VFX_OBJ_GET_INSTANCE(VfxTopLevel)->m_signalRotated.connect(this, &VcpTextView::onRotated);
    VFX_OBJ_GET_INSTANCE(VfxTopLevel)->m_signalBeforeRotate.connect(this, &VcpTextView::onBeforeRotate);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TV1", SA_stop);
#endif
}


void VcpTextView::onDeinit()
{
#if VCP_TEXT_CLIPBOARD_SUPPORT
    // show put before close other object because hideMenu will reference them
    if (m_clipboard)
    {
        // hide clipboard menu
        m_clipboard->hideMenu();
        VFX_OBJ_CLOSE(m_clipboard);
    }
#endif
    if (m_clipboardTimer)
        VFX_OBJ_CLOSE(m_clipboardTimer);

    if (m_layout)
        VFX_OBJ_CLOSE(m_layout);

    if (m_storage)
        VFX_DELETE(m_storage);

    if (m_marginFrame)
        VFX_FREE_MEM(m_marginFrame);

    if (m_scrollTimer)
        VFX_OBJ_CLOSE(m_scrollTimer);

#if VCP_TEXT_MAGNIFIER_SUPPORT
    if (m_magnifier)
        VFX_OBJ_CLOSE(m_magnifier);

    if (m_magnifierTimer)
        VFX_OBJ_CLOSE(m_magnifierTimer);

    if (m_setValidRectTimer)
        VFX_OBJ_CLOSE(m_setValidRectTimer);
#endif
#if defined(__COSMOS_MMI_PACKAGE__)
    if (m_waitingInd)
    {
        VFX_OBJ_CLOSE(m_waitingInd);
    }
#endif

    if (m_scrollVisibleTimer)
        VFX_OBJ_CLOSE(m_scrollVisibleTimer);

    releaseCellView();
    
    VcpScrollable::onDeinit();
}


void VcpTextView::onDraw(VfxDrawContext &dc)
{
    // draw background progress if needed
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
#endif
}


void VcpTextView::setProgressValue(VfxFloat value)
{
    if (value < 0)
    {
        value  = 0;
    }
    else if (value > 1)
    {
        value  = 1;
    }

    if (m_progressFrame == NULL)
    {
        VFX_OBJ_CREATE(m_progressFrame, VfxFrame, this);
        m_progressFrame->setBgColor(VfxColor(255, 0, 216, 255));
        m_progressFrame->setPos(2, 2);
    }

    m_progressValue = value;
    m_progressFrame->setSize(VfxSize((VfxS32)((getBounds().getWidth() - 4) * m_progressValue), getBounds().getHeight() - 4));
    m_progressFrame->sendToBack();
    m_bgImageFrame->sendToBack();

    invalidate();
}


void VcpTextView::releaseCellView()
{
    for(VfxS32 i =0; i<m_countOfCellView; i++)
        VFX_OBJ_CLOSE(m_cellView[i]);

    m_countOfCellView = 0;
}


void VcpTextView::setBoundsInternal(const VfxRect &value, VfxBool isForce)
{
    if ((m_bounds == value) && !isForce)
    {
        return;
    }

#if VCP_TEXT_CLIPBOARD_SUPPORT
    if (m_clipboard)
    {
        // hide clipboard menu if bounds changes, like rotate happens
        // otherwise, the menu postion will not correct
        m_clipboard->hideMenu();
    }
#endif
    
    releaseCellView();
    
    VcpScrollable::setBounds(value);

    // set view and layout rect
    setLayoutRect();
    
    VfxS32 max = VFX_MAX(m_view->getBounds().size.width, m_view->getBounds().size.height);
    setMaxDecelerationDistance(max *2, max * 2);

    // set margin frame position according new position
    if (m_marginFrame != NULL)
    {
        // left margin frame center align
        if (m_marginFrame[0])
        {
            m_marginFrame[0]->setPos(
                m_leftMargin - m_marginFrame[0]->getBounds().getWidth() - VCP_TEXTVIEW_DEFAULT_MARGIN - VCP_TEXTVIEW_MARGIN_FRAME_GAP,
                (getBounds().getHeight() - m_marginFrame[0]->getBounds().getHeight()) / 2);
        }

        // right margin frame center align
        if (m_marginFrame[1])
        {
            m_marginFrame[1]->setPos(
                getBounds().getWidth() - m_rightMargin + VCP_TEXTVIEW_DEFAULT_MARGIN,
                (getBounds().getHeight() - m_marginFrame[1]->getBounds().getHeight()) / 2);
        }

        // top margin frame center align
        if (m_marginFrame[2])
        {
            m_marginFrame[2]->setPos(
                (getBounds().getWidth() - m_marginFrame[2]->getBounds().getWidth()) / 2,
                m_topMargin - m_marginFrame[2]->getBounds().getHeight());
        }

        // top margin frame center align
        if (m_marginFrame[3])
        {
            m_marginFrame[3]->setPos(
                (getBounds().getWidth() - m_marginFrame[3]->getBounds().getWidth()) / 2,
                getBounds().getHeight() - m_bottomMargin);
        }
    }

    m_bgImageFrame->setBounds(value);

    checkUpdate();
}


void VcpTextView::setBounds(const VfxRect &value)
{
    setBoundsInternal(value, VFX_TRUE);
}


void VcpTextView::setMargins(VfxS32 margin)
{
    if (m_leftMargin != margin ||
        m_rightMargin != margin ||
        m_topMargin != margin ||
        m_bottomMargin != margin)
    {
        // should left margin for default margin
        m_leftMargin += margin;
        m_rightMargin += margin;
        m_topMargin += margin;
        m_bottomMargin += margin;
        releaseCellView();
        checkForceUpdate();
    }    
}


void VcpTextView::getMargins(VfxS32 *leftMargin, VfxS32 *topMargin, VfxS32 *rightMargin, VfxS32 *bottomMargin)
{
    if (leftMargin)
    {
        *leftMargin = m_leftMargin;
    }
    if (rightMargin)
    {
        *rightMargin = m_rightMargin;
    }
    if (topMargin)
    {
        *topMargin = m_topMargin;
    }
    if (bottomMargin)
    {
        *bottomMargin = m_bottomMargin;
    }
}


void VcpTextView::setMargins(VfxS32 leftMargin, VfxS32 topMargin, VfxS32 rightMargin, VfxS32 bottomMargin)
{
    if (m_leftMargin != leftMargin ||
        m_rightMargin != rightMargin ||
        m_topMargin != topMargin ||
        m_bottomMargin != bottomMargin)
    {
        // should left margin for default margin
        m_leftMargin += leftMargin;
        m_rightMargin += rightMargin;
        m_topMargin += topMargin;
        m_bottomMargin += bottomMargin;
        releaseCellView();
        checkForceUpdate();
    }
}


void VcpTextView::onViewBoundsChanged(VfxFrame *view, const VfxRect &old)
{
    VfxRect newRect = m_view->getBounds();

    if (newRect == old)
        return;
    
    if (newRect.size != old.size)
    {
        // view size is changed, rebuild all the cellview.
        releaseCellView();
        //onLayoutChanged(&newRect);
		checkUpdate();
        return;
    }
}


void VcpTextView::onUpdate()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TV2", SA_start);
#endif

    setBasePosInternal(m_basePos);

    VcpScrollable::onUpdate();

    if (m_countOfCellView == 0)
        buildCellView();

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TV2", SA_stop);
#endif
}


void VcpTextView::scrollWarningArea()
{
   // if (m_countOfCellView < VCP_TEXTVIEW_CELLVIEW_MAX && !getIsIntersectScreen())
    if (getNeedMultiViewCount() <= VCP_TEXTVIEW_CELLVIEW_MAX)
        return;
    
    VfxRect unionRect;
    VfxRect validView = getValidViewBounds();

    VfxRect rectFirst, rectLast;
    // get normal warning rect
    rectFirst = VfxRect(m_cellView[1]->getPos(), m_cellView[1]->getSize());
    rectLast = VfxRect(m_cellView[m_countOfCellView-2]->getPos(), m_cellView[m_countOfCellView-2]->getSize());
    unionRect = rectFirst;
    unionRect.unionWith(rectLast);
        
    // union with current validview
    unionRect.unionWith(validView);

    if (m_cellView[0]->getPos().isZero())
    {
        unionRect.unionWith(m_cellView[0]->getBounds());
    }

    setWarningContentRect(unionRect);
}



void VcpTextView::onAddChild(VfxObject *child)
{
    // All child should be added to text view except VcpTextCellView and VcpTextCursor
    // because these frame should scroll with scrollable
    
    // check if cell view frame
    VcpTextCellView *cellViewFrame = VFX_OBJ_DYNAMIC_CAST(child, VcpTextCellView);
    if (cellViewFrame != NULL)
    {
        VcpScrollable::onAddChild(child);
        return;
    }

    // check if cursor frame
    if (m_editing != NULL)
    {
        VcpTextCursor *cursorFrame = VFX_OBJ_DYNAMIC_CAST(child, VcpTextCursor);
        if (cursorFrame != NULL)
        {
            VcpScrollable::onAddChild(child);
            return;
        }
    }

    VfxFrame::onAddChild(child);
}


void VcpTextView::addChildToScrollable(VfxObject *child)
{
    if (child)
    {
        VcpScrollable::onAddChild(child);
    }
}


void VcpTextView::startScroll()
{
    if (m_scrollTimer == NULL)
    {
        VFX_OBJ_CREATE(m_scrollTimer, VfxTimer, this);
        m_scrollTimer->setStartDelay(VCP_TEXTVIEW_AUTO_SCROLL_TIMER);
        m_scrollTimer->m_signalTick.connect(this, &VcpTextView::onAutoScroll);
    }
    m_scrollTimer->start();
}


void VcpTextView::stopScroll()
{
    if (m_scrollTimer != NULL)
    {
        m_scrollTimer->stop();
    }
}



void VcpTextView::onAutoScroll(VfxTimer *timer)
{
    VFX_UNUSED(timer);

    if (scroll(0, VCP_TEXTVIEW_AUTO_SCROLL_OFFSET))
    { 
        m_scrollTimer->start();
    }
}


VfxBool VcpTextView::scroll(VfxS32 offsetX, VfxS32 offsetY, VfxBool isAnimation)
{
    if (offsetX == 0 && offsetY == 0)
    {
        return VFX_FALSE;
    }

    VfxRect scrollRect = getViewBounds();

    // if in bounds change animation, should use scroll view real height, not VRT rect get from getViewBounds()
    VfxRect viewBounds = m_view->getBounds();
    if (scrollRect.size.height != viewBounds.size.height)
    {
        scrollRect.size.height = viewBounds.size.height;
    }

    // VfxRect validRect = getValidContentRect();
    // because the valid content rect may update in a timer (VcpTextView::setValidContent)
    // if we get valide content rect before timeout, it will get wrong rect
    // so we use content rect instead which is the same size as valid rect
    VfxRect validRect = VfxRect(getContentOrigin(), getContentSize());
    VfxS32 realOffsetX = offsetX;
    VfxS32 realOffsetY = offsetY;

    // should not scroll if still in change bounds animation (small bounds<-> big bounds)
    // scrollRect get from getViewBounds() will use VRT rect which is intermediate size.
    // the scroll view bounds may be override by scroll if scroll.
    if (m_lineMode == VCP_TEXT_LINE_MODE_MULTI)
    {
        // we check the width as tricky way for multiline which is dangerous
        if (scrollRect.getWidth() != validRect.getWidth())
        {
            return VFX_FALSE;
        }
    }
    else
    {
        // we check the height as tricky way for singleline which is dangerous
        if (scrollRect.getHeight() != validRect.getHeight())
        {
            return VFX_FALSE;
        }
    }

    if (offsetX > 0)
    {
        if (scrollRect.getMaxX() >= validRect.getMaxX())
        {
            // if already scroll to end
            return VFX_FALSE;
        }
        else
        {
            realOffsetX = VFX_MIN(offsetX, (validRect.getMaxX() - scrollRect.getMaxX()));
        }
    }
    else if (offsetX < 0)
    {
        if (scrollRect.getMinX() <= validRect.getMinX())
        {
            // if already scroll to start
            return VFX_FALSE;
        }
        else
        {
            realOffsetX = -VFX_MIN(abs(offsetX), abs((validRect.getMinX() - scrollRect.getMinX())));
        }
    }

    if (offsetY > 0)
    {
        if (scrollRect.getMaxY() >= validRect.getMaxY())
        {
            // if already scroll to end
            return VFX_FALSE;
        }
        else
        {
            realOffsetY = VFX_MIN(offsetY, (validRect.getMaxY() - scrollRect.getMaxY()));
        }
    }
    else if (offsetY < 0)
    {
        if (scrollRect.getMinY() <= validRect.getMinY())
        {
            // if already scroll to start
            return VFX_FALSE;
        }
        else
        {
            realOffsetY = -VFX_MIN(abs(offsetY), abs((validRect.getMinY() - scrollRect.getMinY())));
        }
    }

    scrollRect.offsetWith(realOffsetX, realOffsetY);

    scrollRectToVisible(scrollRect, isAnimation);

    // reset visible start index if app want to scroll to specific position after rotate
    // m_visibleStartIndex will be used after rotated
    // Scenario: Scroll to 100 -> rotate  -> App call scroll() scroll to 0 -> after rotate
    // if not reset m_visibleStartIndex, onRotated will scroll to 100 again which is not app want
    m_visibleStartIndex = -1;

    return VFX_TRUE;
}


VfxBool VcpTextView::scrollToEnd()
{
    // in case when app call setText then call scrollToEnd, the layout not updated
    if (m_checkForceUpdate)
    {
        forceUpdate();
    }

    VfxRect scrollRect = getViewBounds();
    //VfxRect validRect = getValidContentRect();
    VfxRect validRect = VfxRect(getContentOrigin(), getContentSize());
    VfxS32 offsetX = validRect.getMaxX() - scrollRect.getMaxX();
    VfxS32 offsetY = validRect.getMaxY() - scrollRect.getMaxY();

    if (offsetX > 0 || offsetY > 0)
    {
        return scroll(offsetX, offsetY, VFX_FALSE);
    }
    else
    {
        return VFX_FALSE;
    }
}


VfxBool VcpTextView::scrollToStart()
{
    // in case when app change text view properties then all scrollToStart, the layout not updated
    if (m_checkForceUpdate)
    {
        forceUpdate();
    }

    VfxRect scrollRect = getViewBounds();
    VfxRect validRect = getValidContentRect();
    VfxS32 offsetX = validRect.getMinX() - scrollRect.getMinX();
    VfxS32 offsetY = validRect.getMinY() - scrollRect.getMinY();

    return scroll(offsetX, offsetY, VFX_FALSE);
}


VfxBool VcpTextView::previousLine()
{
    VcpTextUtils tuTemp(this);
    VfxS32 minHeight, ascent, descent;
    minHeight = tuTemp.getTextHeightOfCommonLang(&m_layout->m_font, &ascent, &descent);

    return scroll(0, -(minHeight + VCP_TEXT_DEFAULT_LINE_GAP));
}


VfxBool VcpTextView::nextLine()
{
    VcpTextUtils tuTemp(this);
    VfxS32 minHeight, ascent, descent;
    minHeight = tuTemp.getTextHeightOfCommonLang(&m_layout->m_font, &ascent, &descent);

    return scroll(0, minHeight + VCP_TEXT_DEFAULT_LINE_GAP);
}


VfxBool VcpTextView::previousPage()
{
    VcpTextUtils tuTemp(this);
    VfxS32 minHeight, ascent, descent;
    minHeight = tuTemp.getTextHeightOfCommonLang(&m_layout->m_font, &ascent, &descent);

    return scroll(0, -(m_view->getBounds().size.height - minHeight));
}


VfxBool VcpTextView::nextPage()
{
    VcpTextUtils tuTemp(this);
    VfxS32 minHeight, ascent, descent;
    minHeight = tuTemp.getTextHeightOfCommonLang(&m_layout->m_font, &ascent, &descent);

    return scroll(0, m_view->getBounds().size.height - minHeight);
}


void VcpTextView::setValidContent(VfxRect rect)
{
    VfxRect oldValidRect = getValidContentRect();
    // enlarge valid rect
    if (rect.getWidth() > oldValidRect.getWidth() || rect.getHeight() > oldValidRect.getHeight())
    {
        setValidContentRect(rect);
    }
    else
    {
        // shrink valid rect
        // Because the text view bounds changes with animation
        // if set valid content directly, it will lead to scrollable freeze (bounds > valid rect)
        // so we start a timer to set the valid rect
        if (!m_setValidRectTimer)
        {
            VFX_OBJ_CREATE(m_setValidRectTimer, VfxTimer, this);
            m_setValidRectTimer->setStartDelay(VfxAutoAnimate::getDuration());
            m_setValidRectTimer->m_signalTick.connect(this, &VcpTextView::setValidRectTimerHandler);
        }
        m_setValidRectTimer->start();
    }
}


void VcpTextView::scrollCellView()
{
    VcpScrollable::onUpdate();

    if (getNeedMultiViewCount() <= VCP_TEXTVIEW_CELLVIEW_MAX)
        return;

    VfxSize cellSize= m_cellView[0]->getSize();

    VfxRect validView = getValidViewBounds();
    
    VfxRect rectFirst = VfxRect(m_cellView[0]->getPos(), m_cellView[0]->getSize());
    VfxRect rectLast = VfxRect(m_cellView[m_countOfCellView-1]->getPos(), m_cellView[m_countOfCellView-1]->getSize());
    VfxRect unionRect = rectFirst;
    VfxS32 i, j;
        
    unionRect.unionWith(rectLast);
    unionRect.intersectWith(validView);
    
    if (unionRect.getWidth() <=0 || unionRect.getHeight() <= 0)
    {
        VfxS32 cellStart;
        VfxS32 cellEnd;
            
        // the visible area is completely out of cellviews area
        if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
        {
            cellStart = validView.getMinX()/cellSize.width;
            cellEnd = validView.getMaxX()/cellSize.width;
        }
        else
        {
            cellStart = validView.getMinY()/cellSize.height;
            cellEnd = validView.getMaxY()/cellSize.height;
        }
        
        if (cellStart == 0)
        {
            cellEnd = m_countOfCellView - 1;
        }
        else
        {
            if (cellStart == cellEnd - 1)
            {
                cellStart--;
                cellEnd++;
            }
            else
            {
                if (m_scrollDir == SCROLL_TO_LEFT)
                {
                    cellStart--;
                }
                else
                {
                    cellEnd++;
                }
            }
        }

        for (i=0; i<m_countOfCellView; i++)
        {
            if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
                m_cellView[i]->setPos(cellSize.width*(cellStart+i), m_cellView[i]->getPos().y);
            else
                m_cellView[i]->setPos(m_cellView[i]->getPos().x, cellSize.height*(cellStart+i));
            m_cellView[i]->refresh();
        }
    }
    else
    {
        // some cellview can be reused
        VfxS32 startReused;
        VfxS32 endReused;
        VfxS32 startOriginCell;
        
        if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
        {
            startOriginCell = m_cellView[0]->getPos().x/cellSize.width;
            startReused = unionRect.getMinX()/cellSize.width;
            endReused = unionRect.getMaxX()/cellSize.width;
        }
        else
        {
            startOriginCell = m_cellView[0]->getPos().y/cellSize.height;
            startReused = unionRect.getMinY()/cellSize.height;
            endReused = unionRect.getMaxY()/cellSize.height;
        }

        if (m_scrollDir == SCROLL_TO_LEFT)
        {
            for(i=m_countOfCellView-1, j=1; i>=endReused-startOriginCell+1; i--,j++)
            {
                if (startOriginCell - j>=0)
                {
                    m_cellView[i]->setPos(
                        cellSize.width*(startOriginCell - j),
                        m_cellView[i]->getPos().y);
                    m_cellView[i]->refresh();
                }
            }
        }
        else if (m_scrollDir == SCROLL_TO_RIGHT)
        {
            for(i=0, j=1; i<startReused - startOriginCell; i++,j++)
            {
                m_cellView[i]->setPos(
                    cellSize.width*((startOriginCell + m_countOfCellView - 1) + j),
                    m_cellView[i]->getPos().y);
                m_cellView[i]->refresh();
            }
        }
        else if (m_scrollDir == SCROLL_TO_UP)
        {
            for(i=m_countOfCellView-1, j=1; i>=endReused-startOriginCell+1; i--,j++)
            {
                if (startOriginCell-j>=0)
                {
                    m_cellView[i]->setPos(
                        m_cellView[i]->getPos().x,
                        cellSize.height*(startOriginCell-j));
                    m_cellView[i]->refresh();
                }
            }
        }
        else if (m_scrollDir == SCROLL_TO_DOWN)
        {
            for(i=0, j=1; i<startReused-startOriginCell; i++,j++)
            {
                m_cellView[i]->setPos(
                    m_cellView[i]->getPos().x,
                    cellSize.height*((startOriginCell + m_countOfCellView - 1)+j));
                m_cellView[i]->refresh();
            }
        }
    }

    if (m_scrollDir != SCROLL_NONE)
        sortCellView();

    scrollWarningArea();
    //rectFirst = VfxRect(m_cellView[0]->getPos(), m_cellView[0]->getSize());
    //rectLast = VfxRect(m_cellView[m_countOfCellView-1]->getPos(), m_cellView[m_countOfCellView-1]->getSize());
    //unionRect = rectFirst;
    //unionRect.unionWith(rectLast);
    
    //setWarningContentRect(unionRect);
    m_scrollDir = SCROLL_NONE;
}


void VcpTextView::sortCellView()
{
    VfxS32 i=0, j=0;
    VcpTextCellView* t;
    
    if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
    {
        for(i=0; i<m_countOfCellView; i++)
        {
            for(j=i+1; j<m_countOfCellView; j++)
            {
                if (m_cellView[j]->getPos().x < m_cellView[i]->getPos().x)
                {
                    t = m_cellView[i];
                    m_cellView[i] = m_cellView[j];
                    m_cellView[j] = t;
                }
            }
        }
    }
    else
    {
        for(i=0; i<m_countOfCellView; i++)
        {
            for(j=i+1; j<m_countOfCellView; j++)
            {
                if (m_cellView[j]->getPos().y < m_cellView[i]->getPos().y)
                {
                    t = m_cellView[i];
                    m_cellView[i] = m_cellView[j];
                    m_cellView[j] = t;
                }
            }
        }
    }
    
}


void VcpTextView::limitTextViewToValidRect()
{
    VfxRect validRect, rectTextView;
    VfxRect rectVisible = m_view->getBounds();//getViewBounds();

    if (m_layout->getDirtyRange().getLength() > 0)
    {
        // not limit text view when layout not done
        return;
    }
    
    if (m_countOfCellView < 1)
        return;

    validRect = getLayoutRect();
    
    rectTextView = VfxRect(VfxPoint(0, 0), m_view->getSize());

    if (rectTextView.intersectWith(validRect) == validRect)
        return;
    
    if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
    {
        if (validRect.getWidth() > rectVisible.getWidth() &&
            (rectVisible.getMaxX() > validRect.getMaxX()))
        {
            rectVisible.offsetWith(validRect.getMaxX()-rectVisible.getMaxX(), 0);
            scrollRectToVisible(rectVisible, VFX_FALSE);
        }
    }
    else
    {
        if (validRect.getHeight() > rectVisible.getHeight() &&
            (rectVisible.getMaxY() > validRect.getMaxY()))
        {
            // pull back the view area
            rectVisible.offsetWith(0, validRect.getMaxY()-rectVisible.getMaxY());
            scrollRectToVisible(rectVisible, VFX_FALSE);

            // re-calculate the valid content size
            validRect.unionWith(m_view->getBounds());
            setContentSize(VfxSize(validRect.getWidth(), validRect.getHeight()));
            setValidContent(validRect);
        }
    }    
}


void VcpTextView::onContentWarning(VcpScrollableView* sender)
{
    VfxRect currBounds = getValidViewBounds();
    VfxRect warningBounds = getWarningContentRect();

    if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
    {
        if (currBounds.getMinX() < warningBounds.getMinX())
            m_scrollDir = SCROLL_TO_LEFT;
        else if (currBounds.getMaxX() > warningBounds.getMaxX())
            m_scrollDir = SCROLL_TO_RIGHT;
        else
            m_scrollDir = SCROLL_NONE;
    }
    else
    {
        if (currBounds.getMinY() < warningBounds.getMinY())
            m_scrollDir = SCROLL_TO_UP;
        else if (currBounds.getMaxY() > warningBounds.getMaxY())
            m_scrollDir = SCROLL_TO_DOWN;
        else
            m_scrollDir = SCROLL_NONE;
    }

    //checkUpdate();
    scrollCellView();
}


void VcpTextView::onContentError(VcpScrollableView* sender)
{
    //releaseCellView();
    //buildCellView();
}


void VcpTextView::notifyScrollStart(VcpScrollable* sender)
{
    
}


void VcpTextView::notifyScrollEnd(VcpScrollable* sender)
{
    
}


void VcpTextView::onSelectionChanged(VfxRect rect)
{
    // find out the dirty cellview to refresh
    for (VfxS32 i=0; i<m_countOfCellView; i++)
    {
        VfxRect cellRect = m_cellView[i]->getBounds();
        cellRect.offsetWith(m_cellView[i]->getPos());
        cellRect.intersectWith(rect);
        
        if (cellRect.getWidth() > 0 && cellRect.getHeight() > 0)
            m_cellView[i]->refresh(VFX_FALSE);
    }
}


void VcpTextView::onLayoutChanged(VfxRect rect)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TV3", SA_start);
#endif
    VfxRect validRect = getLayoutRect();

    if (validRect.isEmpty())
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TV3", SA_stop);
#endif
        return;
    }
    
    // adjust view origin if layout rect is smaller than view rect
    if (validRect.getHeight() <= m_view->getBounds().getHeight())
    {
        VfxRect viewRect = m_view->getBounds();
        viewRect.origin.y = 0;
        m_view->setBounds(viewRect);
    }
    if (validRect.getWidth() <= m_view->getBounds().getWidth())
    {
        VfxRect viewRect = m_view->getBounds();
        viewRect.origin.x = 0;
        m_view->setBounds(viewRect);
    }

    updateLayoutInfo();
    
    // scroll view to valid rect
    limitTextViewToValidRect();

    // get layout rect again because it will change in updateLayoutInfo
    validRect = getLayoutRect();

    validRect.unionWith(m_view->getBounds());
        
    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

    // Do not set content size if auto resize mode when bounds not updated in updateLayoutInfo
    if (!(m_autoResized && m_editing != NULL && isActive() && m_layout->getDirtyRange().getLength() > 0 &&
        getBounds().size.height >= UI_device_height))
    {
        setContentSize(VfxSize(validRect.getWidth(), validRect.getHeight()));
        setValidContent(validRect);
    }
    else
    {
        // We still need to set the content width if auto resized when layout not done
        setContentSize(VfxSize(validRect.getWidth(), getContentSize().height));
    }

    if (m_countOfCellView == 0)
    {
       buildCellView();
    }
    else
    {
        //update Cell
        if (m_countOfCellView != getNeedMultiViewCount())
        {
            releaseCellView();
            onLayoutChanged(rect);
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TV3", SA_stop);
#endif
            return;
        }
        else
        {
            // find out the dirty cellview to refresh
            for (VfxS32 i=0; i<m_countOfCellView; i++)
            {
                VfxRect cellRect = m_cellView[i]->getBounds();
                cellRect.offsetWith(m_cellView[i]->getPos());
                cellRect.intersectWith(rect);
                
                if (cellRect.getWidth() > 0 && cellRect.getHeight() > 0)
                    m_cellView[i]->refresh();
            }
        }
    }

    // scroll view to valid rect
    limitTextViewToValidRect();

    // set cursor index when layout is ok, otherwise, the cursor rect may not correctly set
    // For example, user create a editor and call activate() to activate it. But this time, the
    // layout is not ready, so the cursor size is not set in setIndex(). We need to set when layout is ready.
    // when selecting text, it will also send layout change notification due to setMarked text
    // so in this case, should not set index here
    if (m_editing != NULL && !m_isSelectingText)
    {
        if (isActive())
        {
            VfxS32 cursorIndex = m_editing->m_cursor->getIndex();
            m_editing->m_cursor->setIndex(cursorIndex, NULL, VFX_TRUE);
        }
    }

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TV3", SA_stop);
#endif
}


void VcpTextView::setValidRectTimerHandler(VfxTimer *source)
{
    VfxRect validRect = VfxRect(getContentOrigin(), getContentSize());
    setValidContentRect(validRect);
    VFX_OBJ_CLOSE(m_setValidRectTimer);
}


void VcpTextView::buildCellView()
{
    VfxS32 visibleWidth = m_view->getBounds().getWidth();
    VfxS32 visibleHeight = m_view->getBounds().getHeight();
    
    if ((visibleWidth == 0) || (visibleHeight == 0))
    {
        // return if bounds is not init
        return;
    }

    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);

    // the first time to display content
    if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
    {
        VfxS32 layoutWidth = getLayoutRect().getWidth();
        VfxS32 cellViewCnt = getNeedMultiViewCount();

        if (cellViewCnt > 1)
        {
            //find the first view position
            VfxS32 perCellWidth = cellViewWidth();

            // swith to interset mode when frame width over limit
            if (perCellWidth >= VCP_TEXT_FRAME_MAX_WIDTH)
            {
                // use screen width as cell width
              //  perCellWidth = mainScreenSize.width;
                enableIntersectScreen(VFX_TRUE);
                m_view->setCacheMode(VFX_CACHE_MODE_PREVENT);
                setCacheMode(VFX_CACHE_MODE_PREVENT);
            }
            else
            {
                enableIntersectScreen(VFX_FALSE);
                m_view->setCacheMode(VFX_CACHE_MODE_AUTO);
                setCacheMode(VFX_CACHE_MODE_AUTO);
            }

            VfxS32 x = m_view->getBounds().getMinX() / perCellWidth;

            if (cellViewCnt <= VCP_TEXTVIEW_CELLVIEW_MAX)
            {
                // if content size smaller then max cell view number, always place the cell view start from 0
                x = 0;
            }
            else
            {
                if (x> 0)
                    x --;

                x = x*perCellWidth;
            }

            cellViewCnt = VFX_MIN(cellViewCnt, VCP_TEXTVIEW_CELLVIEW_MAX);
            
            // use multi-cellview
            for (VfxS32 i=0; i< cellViewCnt; i++)
            {
                VFX_OBJ_CREATE(m_cellView[i], VcpTextCellView, this);
                m_cellView[i]->setPos(i*perCellWidth + x, 0);
                m_cellView[i]->setBounds(VfxRect(0, 0, perCellWidth, visibleHeight));
                m_cellView[i]->setLayout(m_layout);
            }

            m_countOfCellView = cellViewCnt;
            setWarningContentRect(VfxRect(m_cellView[0]->getPos().x, 
                                          m_cellView[0]->getPos().y, 
                                          m_countOfCellView*perCellWidth,
                                          visibleHeight));
        }
        else
        {
            // only create one cellview
            VFX_OBJ_CREATE(m_cellView[0], VcpTextCellView, this);
            VfxS32 cvWidth = cellViewWidth();
            m_cellView[0]->setBounds(VfxRect(0, 0, cvWidth, visibleHeight));
            m_cellView[0]->setLayout(m_layout);
            m_view->setCacheMode(VFX_CACHE_MODE_AUTO);
            enableIntersectScreen(VFX_FALSE);
            setWarningContentRect(m_cellView[0]->getBounds());
            m_countOfCellView = 1;
        }
            
    }
    else // m_lineMode == LINE_MODE_Multi
    {
        VfxS32 layoutHeight = getLayoutRect().getHeight();
        VfxS32 cellViewCnt = getNeedMultiViewCount();
        
        if (cellViewCnt > 1)
        {
            //find the first view position
            VfxS32 perCellHeight = cellViewHeight();

            VfxS32 y = m_view->getBounds().getMinY() / perCellHeight;

            // swith to interset mode when frame height over limit
            if (perCellHeight >= VCP_TEXT_FRAME_MAX_HEIGHT)
            {
                // use 1/2 screen height as cell width
              //  perCellHeight = (mainScreenSize.height >> 1);
                enableIntersectScreen(VFX_TRUE);
                m_view->setCacheMode(VFX_CACHE_MODE_PREVENT);
                setCacheMode(VFX_CACHE_MODE_PREVENT);
                y = getIntersectRect().getMinY() / perCellHeight;
            }
            else
            {
                enableIntersectScreen(VFX_FALSE);
                m_view->setCacheMode(VFX_CACHE_MODE_AUTO);
                setCacheMode(VFX_CACHE_MODE_AUTO);
            }

            if (cellViewCnt <= VCP_TEXTVIEW_CELLVIEW_MAX)
            {
                // if content size smaller then max cell view number, always place the cell view start from 0
                y = 0;
            }
            else
            {
                if (y> 0)
                    y --;
                y = y*perCellHeight;
            }

            cellViewCnt = VFX_MIN(cellViewCnt, VCP_TEXTVIEW_CELLVIEW_MAX);

            // use multi-cellview
            for (VfxS32 i=0; i< cellViewCnt; i++)
            {
                VFX_OBJ_CREATE(m_cellView[i], VcpTextCellView, this);
                m_cellView[i]->setPos(0, i*perCellHeight + y);
                m_cellView[i]->setBounds(VfxRect(0, 0, visibleWidth, perCellHeight));
                m_cellView[i]->setLayout(m_layout);
            }

            m_countOfCellView = cellViewCnt;
            setWarningContentRect(VfxRect(m_cellView[0]->getPos().x, 
                                          m_cellView[0]->getPos().y,
                                          visibleWidth,
                                          m_countOfCellView*perCellHeight));
        }
        else
        {
            // only create one cellview
            VFX_OBJ_CREATE(m_cellView[0], VcpTextCellView, this);
            VfxS32 cvHeight = cellViewHeight();
            m_cellView[0]->setBounds(VfxRect(0, 0, visibleWidth, cvHeight));
            m_cellView[0]->setLayout(m_layout);
            m_view->setCacheMode(VFX_CACHE_MODE_AUTO);
            enableIntersectScreen(VFX_FALSE);
            setWarningContentRect(m_cellView[0]->getBounds());
            m_countOfCellView = 1;
        }
    }

    refreshAllCell();    
}


void VcpTextView::refreshAllCell()
{
    for (VfxS32 i=0; i<m_countOfCellView; i++)
    {
        m_cellView[i]->refresh();
    }
}

VfxS32 VcpTextView::getNeedMultiViewCount()
{
    VfxS32 visibleWidth = m_view->getBounds().getWidth();
    VfxS32 visibleHeight = m_view->getBounds().getHeight();
    
    if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
    {
        VfxS32 layoutWidth = getLayoutRect().getWidth();
        VfxS32 cellWidth = cellViewWidth();
        return ((layoutWidth / cellWidth) + ((layoutWidth % cellWidth) > 0 ? 1 : 0));
    }
    else
    {
        VfxS32 layoutHeight = getLayoutRect().getHeight();
        VfxS32 cellHeight = cellViewHeight();
        return ((layoutHeight / cellHeight) + ((layoutHeight % cellHeight) > 0 ? 1 : 0));
    }
}


void VcpTextView::setText(VfxResId resId, VcpRichTextFormat *format)
{
    m_storage->setText(VFX_WSTR_RES(resId), VFX_FALSE, VcpTextStorage::TEXT_ENCODING_UCS2, -1, format);

    if (m_lineMode == VCP_TEXT_LINE_MODE_MULTI)
    {
        // when text changes, need to reset the view bounds to (0, 0)
        VfxRect bounds = m_view->getBounds();
        bounds.origin.x = 0;
        bounds.origin.y = 0;
	    m_view->setBounds(bounds);
    }

    // clear highlight when set text
    setHighlight(0, 0);

    checkForceUpdate();
}


void VcpTextView::setText(const VfxWChar *text, VfxBool isStaticBuf, VcpRichTextFormat *format)
{
    VfxWString tmpText;

    tmpText = VFX_WSTR_STATIC(text);
    
    m_storage->setText(tmpText, isStaticBuf, VcpTextStorage::TEXT_ENCODING_UCS2, -1, format);

    if (m_lineMode == VCP_TEXT_LINE_MODE_MULTI)
    {
        // when text changes, need to reset the view bounds to (0, 0)
        VfxRect bounds = m_view->getBounds();
        bounds.origin.x = 0;
        bounds.origin.y = 0;
	    m_view->setBounds(bounds);
    }

    // clear highlight when set text
    setHighlight(0, 0);

    checkForceUpdate();
}


void VcpTextView::setText(const VfxWString &text, VfxBool isStaticBuf, VcpRichTextFormat *format)
{
    m_storage->setText(text, isStaticBuf, VcpTextStorage::TEXT_ENCODING_UCS2, -1, format);

    if (m_lineMode == VCP_TEXT_LINE_MODE_MULTI)
    {
        // when text changes, need to reset the view bounds to (0, 0)
        VfxRect bounds = m_view->getBounds();
        bounds.origin.x = 0;
        bounds.origin.y = 0;
	    m_view->setBounds(bounds);
    }

    // clear highlight when set text
    setHighlight(0, 0);

    checkForceUpdate();
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VfxS32 VcpTextView::addText(
    const VfxWString &text,
    VfxS32 maxLen,
    VcpRichTextFormat *format)
{
    m_storage->setMaxLength(maxLen);
    return m_storage->insertText(m_storage->getTextLength(), text, format);
}


VfxBool VcpTextView::addDetail(const VfxWString &text, VcpTextDetailEnum dType, VfxS32 maxLen)
{
    VfxBool ret = VFX_FALSE;
    VfxS32 retLen = 0;

    if (dType == VCP_TEXT_DETAIL_TITLE)
    {
        VfxFontDesc titleFont;
        titleFont.size = VFX_FONT_DESC_VF_SIZE(VCP_TEXTVIEW_DETAIL_TITLE_FONT_SIZE);
        VcpRichText title;
        title.setFont(titleFont);
    #if defined(__COSMOS_MMI_PACKAGE__)
        title.setTextColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
    #else
        title.setTextColor(VRT_COLOR_MAKE(255, 15, 15, 15));
    #endif
        title.setRange(0, text.getLength());
        retLen = addText(text, maxLen, (VcpRichTextFormat *)&title);

        ret = (retLen > 0 ? VFX_TRUE : VFX_FALSE);
    }
    else
    {
        VfxFontDesc contentFont;
        contentFont.size = VFX_FONT_DESC_VF_SIZE(VCP_TEXTVIEW_DETAIL_CONTENT_FONT_SIZE);
        VcpRichText content;
        content.setFont(contentFont);
    #if defined(__COSMOS_MMI_PACKAGE__)
        content.setTextColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_SUB));
    #else
        content.setTextColor(VRT_COLOR_MAKE(255, 50, 50, 50));
    #endif
        content.setRange(0, text.getLength());
        retLen = addText(text, maxLen, (VcpRichTextFormat *)&content);

        // extra line gap, use min font for line gap
        VfxFontDesc minFont;
        minFont.size = VFX_FONT_DESC_VF_SIZE(VCP_TEXTVIEW_DETAIL_MIN_FONT_SIZE);
        VcpRichText dummyLine;
        dummyLine.setFont(minFont);
        dummyLine.setRange(0, 1);
        retLen = addText(VFX_WSTR("\n"), maxLen, (VcpRichTextFormat *)&dummyLine);

        ret = (retLen > 0 ? VFX_TRUE : VFX_FALSE);
    }

    // disable clipboard function in detail screen to sync behavior in all detail screen
    setDisableClipboard(VFX_TRUE);
    setDisableMagnifier(VFX_TRUE);

    return ret;
}


VfxWChar *VcpTextView::getText() const
{
    VfxWChar *p = NULL;

    p = (VfxWChar *)m_storage->getText();

    return p;
}


VcpRichTextFormat *VcpTextView::getFormatObject() const
{
    return m_storage->getRichTextFormat();
}


VfxS32 VcpTextView::getLength() const
{
    return m_storage->getTextLength();
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
#endif


void VcpTextView::setFont(const VfxFontDesc &fontDesc)
{
    m_layout->m_font = fontDesc;
    m_orgFontSize = fontDesc.size;
    m_layout->m_orgFontSize = fontDesc.size;

    checkForceUpdate();
}


VfxFontDesc &VcpTextView::getFont() const
{
    return m_layout->m_font;
}


void VcpTextView::setHint(VfxResId resId)
{
    m_layout->setHintText(VFX_WSTR_RES(resId));

    invalidate();
}


void VcpTextView::setHint(const VfxWString &string)
{
    m_layout->setHintText(string);

    invalidate();
}


const VfxWString& VcpTextView::getHint() const
{
    return m_layout->getHintText();
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VcpTextView::setTextFormat(VcpRichTextFormat *format)
{
    VfxBool bOrgAffectLayout = VFX_FALSE;
    VfxBool bNewAffectLayout = VFX_FALSE;
    VfxS32 textLen = getLength();
    VcpRichTextFormat *orgFormat = m_storage->getRichTextFormat();
    if (orgFormat && orgFormat->testAffectLayout(&m_layout->m_font, 0, textLen))
    {
        bOrgAffectLayout = VFX_TRUE;
    }
    
    m_storage->setFormat(format);

    if (format && format->testAffectLayout(&m_layout->m_font, 0, textLen))
    {
        bNewAffectLayout = VFX_TRUE;
    }

    // re-layout only when the format will affect layout
    if (bOrgAffectLayout || bNewAffectLayout)
    {
        checkForceUpdate();
    }
    else
    {
        releaseCellView();
        checkUpdate();
    }
}


void VcpTextView::addTextFormat(const VcpRichTextFormat &format)
{
    m_storage->addFormat(format);
}


VfxBool VcpTextView::removeTextFormat(const VcpRichTextFormat &format)
{
    VfxBool ret = m_storage->removeFormat(format);
    if (ret)
    {
        // force update all content because the format removed
        checkForceUpdate();
    }

    return ret;
}


void VcpTextView::checkForceUpdate()
{
    if (!m_checkForceUpdate)
    {
        m_checkForceUpdate = VFX_TRUE;
        m_layout->m_checkForceUpdate = VFX_TRUE;
        vfxPostInvoke1(this, &VcpTextView::forceUpdateInternal, VFX_TRUE);
    }
}


void VcpTextView::forceUpdate(VfxBool isAsync)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TVU", SA_start);
#endif
    m_checkForceUpdate = VFX_TRUE;

    forceUpdateInternal(isAsync);

#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TVU", SA_stop);
#endif
}


void VcpTextView::UpdateViewForCustomFrame()
{
    if (m_layout->getLineCount() > 0 && m_layout->getDirtyRange().getLength() == 0)
    {
        releaseCellView();
        m_layout->UpdateViewForCustomFrame();
    }
    else
    {
        // not layout or layout not done, forceUpdate layout first
        forceUpdate();
    }
    checkUpdate();
}


void VcpTextView::forceUpdateInternal(VfxBool isAsync)
{
    if (m_checkForceUpdate)
    {
        m_checkForceUpdate = VFX_FALSE;
        m_layout->m_checkForceUpdate = VFX_FALSE;
        releaseCellView();

        // for margin
        setBounds(getBounds());

        m_layout->forceLayout(isAsync);
        processUpdate();
    }
}


void VcpTextView::setLayout()
{
    if (m_layout)
    {
        VFX_OBJ_CLOSE(m_layout);
    }

    // create textLayout
    if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
    {
        VFX_OBJ_CREATE_EX(m_layout, VcpTextSingleLineLayout, this, (this));
    }
    else
    {
        if (editable())
            VFX_OBJ_CREATE_EX(m_layout, VcpTextDynamicLayout, this, (this));
        else
            VFX_OBJ_CREATE_EX(m_layout, VcpTextStaticLayout, this, (this));
    }
    
    // connect textLayout updated signal
    m_layout->m_signalLayoutChanged.connect(this, &VcpTextView::onLayoutChanged);
    m_layout->m_signalSelectionChanged.connect(this, &VcpTextView::onSelectionChanged);
    m_layout->m_signalMaxLineReached.connect(this, &VcpTextView::onMaxLayoutLineNumReached);
    m_layout->setTextStorage(m_storage);
}


void VcpTextView::setLayoutRect()
{
    if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
    {
        setViewRect(VfxRect(m_leftMargin, 
                            m_topMargin, 
                            getBounds().size.width - m_leftMargin - m_rightMargin, 
                            getBounds().size.height - m_topMargin - m_bottomMargin));
    }
    else
    {
        setViewRect(VfxRect(0, 
                            m_topMargin, 
                            getBounds().size.width, 
                            getBounds().size.height - m_topMargin - m_bottomMargin));
    }

    // connect textLayout updated signal
    VfxS32 width = m_view->getBounds().size.width;
    
    if (m_editing != NULL)
    {
        width -= VCP_EDITOR_CURSOR_WIDTH; /* left for cursor */
    }

    if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
    {
        m_layout->setLayoutRect(VfxRect(0, 0, width, m_view->getBounds().size.height));
    }
    else
    {
        m_layout->setLayoutRect(VfxRect(m_leftMargin, 0, width - m_leftMargin - m_rightMargin, m_view->getBounds().size.height));
    }
}


VfxRect VcpTextView::getLayoutRect()
{
    VfxRect retRect = VfxRect(0, 0, m_layout->getWidth(), m_layout->getHeight());
    if (m_lineMode == VCP_TEXT_LINE_MODE_SINGLE && m_editing == NULL)
    {
        retRect.size.width -= VCP_EDITOR_CURSOR_WIDTH;
    }

    return retRect;
}


void VcpTextView::setLineMode(VcpTextLineModeEnum mode)
{
    if (m_lineMode == mode)
    {
        return;
    }

    m_lineMode = mode;
    releaseCellView();
    
    setLayout();

    // set view and layout rect
    setLayoutRect();
}


void VcpTextView::setHighlight(VfxS32 start, VfxS32 end)
{
    m_layout->setHighlight(start, end);
}


void VcpTextView::getHighlight(VfxS32 *start, VfxS32 *end)
{
    m_layout->getHighlight(start, end);
}


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VcpTextView::setKeyword(VfxS32  mode)
{
    m_storage->setKeyword(mode);
    checkForceUpdate();
}


void VcpTextView::setIconMode(VfxBool mode, VcpIconTable *mapping, VfxU8 size)
{
#ifdef __MMI_VUI_TEXT_EMOTION_ICON_SUPPORT__
    m_storage->setIconMode(mode, mapping, size);
#endif
}


void VcpTextView::setTruncateMode(VcpTextTruncateModeEnum value)
{
    m_layout->setTruncateMode((VcpTextBasicLayout::TruncateModeEnum)value);

    if (VCP_TEXT_TRUNCATE_WITH_AUTO_RESIZE == value)
    {
        setAutoResized(VFX_TRUE);
    }
}


void VcpTextView::setColor(VcpTextColorTypeEnum  id, const VfxColor &vColor)
{
    switch (id)
    {
    case VCP_TEXT_NORMAL_TEXT_COLOR:
        m_layout->m_normalTextColor = vColor;
        break;
    case VCP_TEXT_HINT_TEXT_COLOR:
        m_layout->m_hintTextColor = vColor;
        break;
   // case VCP_TEXT_HIGHLIGHTED_TEXT_COLOR:
    //    m_layout->m_hiliteTextColor = vColor;
    //    break;
   // case VCP_TEXT_HIGHLIGHT_FILLER_COLOR:
     //   m_layout->m_hiliteFillerColor = vColor;
     //   break;
    case VCP_TEXT_UNDERLINE_COLOR:
        m_layout->m_underlineColor = vColor;
        break;
    default:
        break;
    }

    // force redraw the cell view in case of cache
    refreshAllCell();
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VcpTextView::setNormalBgImage(VfxResId imageId)
{
    if (m_normalBgImageId != imageId)
    {
        // if editor, should subtract the default image margin
        if (m_editing && !m_isDisableBg && m_normalBgImageId == VCP_IMG_TEXT_VIEW_NORMAL_BG)
        {
            m_leftMargin -= VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN;
            m_rightMargin -= VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN;
            m_topMargin -= VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN;
            m_bottomMargin -= VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN;
        }
    #ifdef __COSMOS_3D_V10__
        enableBoundaryLight(VFX_TRUE);
    #endif
        m_normalBgImageId = imageId;
        m_bgImageFrame->setImgContent(VfxImageSrc(m_normalBgImageId));

        checkUpdate();
    }
}


void VcpTextView::setHiliteBgImage(VfxResId imageId)
{
    if (m_hiliteBgImageId != imageId)
    {
        m_hiliteBgImageId = imageId;
        m_bgImageFrame->setImgContent(VfxImageSrc(m_hiliteBgImageId));
    #ifdef __COSMOS_3D_V10__
        enableBoundaryLight(VFX_TRUE);
    #endif
        checkUpdate();
    }
}


void VcpTextView::setAlignMode(VcpTextAlignModeEnum value)
{
    m_layout->setAlignMode((VcpTextBasicLayout::AlignModeEnum)value);
}


void VcpTextView::setHorizontalAlignMode(VcpTextAlignModeEnum value)
{
    m_layout->setAlignMode((VcpTextBasicLayout::AlignModeEnum)value);
}


void VcpTextView::setVerticalAlignMode(VcpTextVertAlignModeEnum value)
{
    m_layout->setVerticalAlignMode((VcpTextBasicLayout::VertAlignModeEnum)value);
}


void VcpTextView::setTextWrapStyle(VcpTextWrapStyleEnum wrap)
{
    m_layout->setTextWrapStyle(wrap);
}


void VcpTextView::setMinLineHeight(VfxS32 value)
{
    m_layout->setMinLineHeight(value);
}


void VcpTextView::setLineGap(VfxS32 value)
{
    m_layout->setLineGap(value);
}


void VcpTextView::setHyperLink(VfxS32 start, VfxS32 end, const VfxWString &hyperlink, VfxFontDesc *font)
{
    VcpRichTextHyperLink hyperLinkObj;

    if (font)
    {
        hyperLinkObj.setFont(*font);
    }
    else
    {
    #if defined(__COSMOS_MMI_PACKAGE__)
        VfxFontDesc textFont = VFX_FONT_RES(VCP_FNT_TEXT_VIEW_TXT);
    #else
        VfxFontDesc textFont;
    #endif
        textFont.attr |= VFX_FONT_DESC_ATTR_UNDERLINE;
        hyperLinkObj.setFont(textFont);
    }
#if defined(__COSMOS_MMI_PACKAGE__)
    hyperLinkObj.setTextColor(VFX_COLOR_RES(VCP_COL_TEXT_VIEW_HYPELINK));
#else
    hyperLinkObj.setTextColor(VRT_COLOR_MAKE(255, 110, 165, 50));
#endif
    hyperLinkObj.m_range.setRange(start, end);
    hyperLinkObj.setLinkText(hyperlink);

    addTextFormat(hyperLinkObj);

    m_signalTapEvent.connect(this, &VcpTextView::onHyperLinkClicked);
}


void VcpTextView::onHyperLinkClicked(VcpTextView *view, VcpTextTapAreaEnum type, VcpRichTextFormat *obj)
{
    if (type == VCP_TEXT_TAP_AREA_OBJECT && obj && (obj->getType() == VCP_RICH_TEXT_TYPE_HYPERLINK))
    {
        m_signalHyperLinkClicked.postEmit(this, ((VcpRichTextHyperLink *)obj)->getLinkText());
    }
}


void VcpTextView::setAutoResized(VfxBool value, VfxS32 minValue, VfxS32 maxValue)
{
    if (m_autoResized != value || m_autoResizedMinValue != minValue || m_autoResizedMaxValue != maxValue)
    {
        m_autoResized = value;
        m_autoResizedMinValue = minValue;
        m_autoResizedMaxValue = maxValue;

        if (m_autoResizedMaxValue == -1)
        {
            enableVerticalScrollIndicator(VFX_FALSE);
        }
        
        releaseCellView();
        checkForceUpdate();
    }
}


void VcpTextView::setAutoFontSize(VfxBool value)
{
    if (m_autoFontSize != value
        || m_autoResized)
    {
        m_autoFontSize = value;
        // disable bounds auto resize
        m_autoResized = VFX_FALSE;
        checkForceUpdate();
    }
}


void VcpTextView::disableBackground(VfxBool value)
{
    if (m_isDisableBg != value)
    {
        m_isDisableBg = value;
        if (m_isDisableBg)
        {
            m_leftMargin -= VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN;
            m_rightMargin -= VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN;
            if (m_lineMode == VCP_TEXT_LINE_MODE_MULTI)
            {
                m_topMargin -= VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN;
                m_bottomMargin -= VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN;
            }
            m_bgImageFrame->setImgContent(VFX_IMAGE_SRC_NULL);
            setBgColor(VRT_COLOR_TRANSPARENT);
        #ifdef __COSMOS_3D_V10__
            enableBoundaryLight(VFX_TRUE);
        #endif
        }
        else
        {
            m_leftMargin += VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN;
            m_rightMargin += VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN;
            if (m_lineMode == VCP_TEXT_LINE_MODE_MULTI)
            {
                m_topMargin += VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN;
                m_bottomMargin += VCP_TEXTVIEW_BG_IMAGE_TD_MARGIN;
            }
            m_bgImageFrame->setImgContent(VfxImageSrc(m_normalBgImageId));
        }
        // reset bound because the text margin will change is no background
        setBounds(getBounds());
    }
}


void VcpTextView::setMarginFrame(VcpTextMarginFrameEnum value, VfxFrame *frame)
{
    if (frame != NULL)
    {
        if (m_marginFrame == NULL)
        {
            VFX_ALLOC_MEM(m_marginFrame, VCP_TEXT_MARGIN_FRAME_TOTAL * sizeof(VfxFrame*), this);
            VfxS32 i;
            for (i = 0; i < VCP_TEXT_MARGIN_FRAME_TOTAL; i++)
            {
                m_marginFrame[i] = NULL;
            }
        }

        switch (value)
        {
        case VCP_TEXT_MARGIN_FRAME_LEFT:
            if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_LEFT] != frame)
            {
                // remove first
                if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_LEFT])
                {
                    removeMarginFrame(VCP_TEXT_MARGIN_FRAME_LEFT, m_marginFrame[VCP_TEXT_MARGIN_FRAME_LEFT]);
                }
                frame->setHidden(VFX_FALSE);
                frame->setPos(
                    m_leftMargin,
                    (getBounds().getHeight() - frame->getBounds().getHeight()) / 2);
                m_leftMargin += (frame->getBounds().getWidth() + VCP_TEXTVIEW_DEFAULT_MARGIN + VCP_TEXTVIEW_MARGIN_FRAME_GAP);
                addChildFrame(frame);
                m_marginFrame[VCP_TEXT_MARGIN_FRAME_LEFT] = frame;
            }
            break;
        case VCP_TEXT_MARGIN_FRAME_RIGHT:
            if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_RIGHT] != frame)
            {
                // remove first
                if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_RIGHT])
                {
                    removeMarginFrame(VCP_TEXT_MARGIN_FRAME_RIGHT, m_marginFrame[VCP_TEXT_MARGIN_FRAME_RIGHT]);
                }
                frame->setHidden(VFX_FALSE);
                frame->setPos(
                    getBounds().getWidth() - m_rightMargin - frame->getBounds().getWidth(),
                    (getBounds().getHeight() - frame->getBounds().getHeight()) / 2);
                m_rightMargin += (frame->getBounds().getWidth() + VCP_TEXTVIEW_DEFAULT_MARGIN - VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN);
                addChildFrame(frame);
                m_marginFrame[VCP_TEXT_MARGIN_FRAME_RIGHT] = frame;
            }
            break;
        case VCP_TEXT_MARGIN_FRAME_TOP:
            if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_TOP] != frame)
            {
                // remove first
                if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_TOP])
                {
                    removeMarginFrame(VCP_TEXT_MARGIN_FRAME_TOP, m_marginFrame[VCP_TEXT_MARGIN_FRAME_TOP]);
                }
                frame->setHidden(VFX_FALSE);
                frame->setPos(
                    (getBounds().getWidth() - frame->getBounds().getWidth()) / 2,
                    m_topMargin);
                m_topMargin += (frame->getBounds().getHeight() + VCP_TEXTVIEW_DEFAULT_MARGIN);
                addChildFrame(frame);
                m_marginFrame[VCP_TEXT_MARGIN_FRAME_TOP] = frame;
            }
            break;
        case VCP_TEXT_MARGIN_FRAME_BOTTOM:
            if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_BOTTOM] != frame)
            {
                // remove first
                if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_BOTTOM])
                {
                    removeMarginFrame(VCP_TEXT_MARGIN_FRAME_BOTTOM, m_marginFrame[VCP_TEXT_MARGIN_FRAME_BOTTOM]);
                }
                frame->setHidden(VFX_FALSE);
                frame->setPos(
                    (getBounds().getWidth() - frame->getBounds().getWidth()) / 2,
                    getBounds().getHeight() - m_bottomMargin - frame->getBounds().getHeight());
                m_bottomMargin += (frame->getBounds().getHeight() + VCP_TEXTVIEW_DEFAULT_MARGIN);
                addChildFrame(frame);
                m_marginFrame[VCP_TEXT_MARGIN_FRAME_BOTTOM] = frame;
            }
            break;
        default:
            break;
        }
        checkForceUpdate();
    }
}


void VcpTextView::removeMarginFrame(VcpTextMarginFrameEnum value, VfxFrame *frame)
{
    if (frame != NULL && (m_marginFrame != NULL))
    {
        switch (value)
        {
        case VCP_TEXT_MARGIN_FRAME_LEFT:
            if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_LEFT] && (frame == m_marginFrame[VCP_TEXT_MARGIN_FRAME_LEFT]))
            {
                frame->setHidden(VFX_TRUE);
                m_leftMargin -= (frame->getBounds().getWidth() + VCP_TEXTVIEW_DEFAULT_MARGIN + VCP_TEXTVIEW_MARGIN_FRAME_GAP);
                m_marginFrame[VCP_TEXT_MARGIN_FRAME_LEFT] = NULL;
            }
            break;
        case VCP_TEXT_MARGIN_FRAME_RIGHT:
            if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_RIGHT] && (frame == m_marginFrame[VCP_TEXT_MARGIN_FRAME_RIGHT]))
            {
                frame->setHidden(VFX_TRUE);
                m_rightMargin -= (frame->getBounds().getWidth() + VCP_TEXTVIEW_DEFAULT_MARGIN - VCP_TEXTVIEW_BG_IMAGE_LR_MARGIN);
                m_marginFrame[VCP_TEXT_MARGIN_FRAME_RIGHT] = NULL;
            }
            break;
        case VCP_TEXT_MARGIN_FRAME_TOP:
            if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_TOP] && (frame == m_marginFrame[VCP_TEXT_MARGIN_FRAME_TOP]))
            {
                frame->setHidden(VFX_TRUE);
                m_topMargin -= (frame->getBounds().getHeight() + VCP_TEXTVIEW_DEFAULT_MARGIN);
                m_marginFrame[VCP_TEXT_MARGIN_FRAME_TOP] = NULL;
            }
            break;
        case VCP_TEXT_MARGIN_FRAME_BOTTOM:
            if (m_marginFrame[VCP_TEXT_MARGIN_FRAME_BOTTOM] && (frame == m_marginFrame[VCP_TEXT_MARGIN_FRAME_BOTTOM]))
            {
                frame->setHidden(VFX_TRUE);
                m_bottomMargin -= (frame->getBounds().getHeight() + VCP_TEXTVIEW_DEFAULT_MARGIN);
                m_marginFrame[VCP_TEXT_MARGIN_FRAME_BOTTOM] = NULL;
            }
            break;
        default:
            break;
        }
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

void VcpTextView::updateLayoutInfo()
{
    VfxS32 height;
    VfxS32 width;
    VfxS32 boundsHeight = getBounds().size.height;
    VfxS32 boundsWidth = getBounds().size.width;

    // return if is updateing (auto font size)
    if (m_isUpdating)
    {
        return;
    }

    height = getLayoutRect().getHeight() + m_bottomMargin + m_topMargin;
    width = getLayoutRect().getWidth() + m_leftMargin + m_rightMargin;

    if (m_autoFontSize)
    {
        VfxBool ret = VFX_TRUE;
        m_isUpdating = VFX_TRUE;
        if (m_lineMode == VCP_TEXT_LINE_MODE_MULTI)
        {
            if (height > boundsHeight)
            {
                // try to decrease change font size
                while (height > boundsHeight)
                {
                    ret = m_layout->decFontSize();
                    if (ret)
                    {
                        forceUpdate();
                        height = getLayoutRect().getHeight() + m_bottomMargin + m_topMargin;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (height < boundsHeight)
            {
                // try to increase change font size
                while(height < boundsHeight)
                {
                    ret = m_layout->incFontSize();
                    if (ret)
                    {
                        forceUpdate();
                        height = getLayoutRect().getHeight() + m_bottomMargin + m_topMargin;
                    }
                    else
                    {
                        m_isUpdating = VFX_FALSE;
                        return;
                    }
                }

                // adjust the font size to correct one
                m_layout->decFontSize();
                forceUpdate();
            }
        }
        else
        {
            // single line
            if (width > boundsWidth)
            {
                // try to decrease change font size
                while (width > boundsWidth)
                {
                    ret = m_layout->decFontSize();
                    if (ret)
                    {
                        forceUpdate();
                        width = getLayoutRect().getWidth() + m_leftMargin + m_rightMargin;;
                    }
                    else
                    {
                        break;
                    }
                }
            }
            else if (width < boundsWidth)
            {
                // try to increase change font size
                while(width < boundsWidth)
                {
                    
                    ret = m_layout->incFontSize();
                    if (ret)
                    {
                        forceUpdate();
                        width = getLayoutRect().getWidth() + m_leftMargin + m_rightMargin;;
                    }
                    else
                    {
                        m_isUpdating = VFX_FALSE;
                        return;
                    }
                }

                // adjust the font size to correct one
                m_layout->decFontSize();
                forceUpdate();
            }
        }
        m_isUpdating = VFX_FALSE;
    }
    else if (m_autoResized && (m_editing == NULL ||        // text view always update bounds when layout change
             !isActive() ||                                // text editor always update bounds when not active
             m_layout->getDirtyRange().getLength() == 0 || // update bounds when 1). all text layout is done
             boundsHeight < UI_device_height))             // 2). Visible layout is done (make sure resize the editor bounds to at least the visible area height)
    {
        if (m_lineMode == VCP_TEXT_LINE_MODE_MULTI)
        {
            VfxS32 rectHeight;
            VfxS32 maxHeight;
            VfxS32 minHeight;

            minHeight = m_autoResizedMinValue > 0 ? m_autoResizedMinValue : VCP_TEXTVIEW_AUTO_RESIZE_MIN_HEIGHT;
            maxHeight = m_autoResizedMaxValue > 0 ? m_autoResizedMaxValue : VCP_TEXTVIEW_AUTO_RESIZE_MAX_HEIGHT;

            if (height < minHeight)
            {
                height = minHeight;
            }
            else if (height > maxHeight)
            {
                height = maxHeight;
            }
            rectHeight = height;

            if (editable())
            {
                width += VCP_EDITOR_CURSOR_WIDTH;
            }

            if (m_layout->getDirtyRange().getLength() == 0)
            {
                setBoundsInternal(VfxRect(0, 0, width, rectHeight), VFX_FALSE);
            }
            else
            {
                // turn off m_view animation when layout not done and update bounds because
                // if VcpScrollable in bounds animation, it will became unhitable (return VFX_FALSE in VcpScrollableView::onPreviewPenInput)
                VfxBool isAnimate = m_view->getAutoAnimate();
                m_view->setAutoAnimate(VFX_FALSE);
                setBoundsInternal(VfxRect(0, 0, width, rectHeight), VFX_FALSE);
                m_view->setAutoAnimate(isAnimate);
            }
        }
        else
        {
            VfxS32 rectWidth;
            VfxS32 maxWidth;
            VfxS32 minWidth;

            minWidth = m_autoResizedMinValue > 0 ? m_autoResizedMinValue : VCP_TEXTVIEW_AUTO_RESIZE_MIN_WIDTH;
            maxWidth = m_autoResizedMaxValue > 0 ? m_autoResizedMaxValue : VCP_TEXTVIEW_AUTO_RESIZE_MAX_WIDTH;

            if (width < minWidth)
            {
                width = minWidth;
            }
            else if (width > maxWidth)
            {
                width = maxWidth;
            }
            rectWidth = width;

            if (editable())
            {
                rectWidth += VCP_EDITOR_CURSOR_WIDTH;
            }

            setBoundsInternal(VfxRect(0, 0, rectWidth, height), VFX_FALSE);
        }
    }
    else if ((m_lineMode == VCP_TEXT_LINE_MODE_SINGLE) && (boundsHeight == 0))
    {
        setBoundsInternal(getLayoutRect(), VFX_FALSE);
    }
}


VfxS32 VcpTextView::getLineCount() const
{
    return m_layout->getLineCount();
}


VfxS32 VcpTextView::adjustIndexForLanguage(VfxS32 index, VfxBool isPrevious)
{
#if !defined(__MMI_LANG_THAI__) && !defined(__MMI_LANG_ARMENIAN__) && !defined(__MMI_INDIC_ALG__) && \
    !defined(__MMI_ARSHAPING_ENGINE__) && !defined(__MMI_LANG_VIETNAMESE__) && !defined(__MMI_LM_LANG_EUROPEAN_SUPPORT__)
    return index;
#else
    VfxS32 lineIndex = getTextLayout()->getLineIndex(index);
    const VfxWChar *lineText;
    VfxS32 lineTextLen = 0;
    VfxS32 lineStart = 0;
    lineText = m_layout->getLineText(lineIndex, &lineTextLen);
    lineStart = m_layout->getLineStart(lineIndex); 

    VcpTextUtils tu(this);
    VcpTextMetrics *pMetric = NULL;
    tu.setText(lineText, lineTextLen);
    pMetric = tu.getMetric(index - lineStart);

    if (pMetric && pMetric->metrics.index < (VfxU32)(index - lineStart))
    {
        if (isPrevious)
        {
            return lineStart + pMetric->metrics.index;
        }
        else
        {
            return lineStart + pMetric->metrics.index + pMetric->metrics.len;
        }
    }
    return index;
#endif
}


VfxBool VcpTextView::isReachMaxLineNum()
{
    VfxS32 maxLine = m_layout->getMaxLineNum();
    VfxBool ret = VFX_FALSE;
    if (maxLine > 0 && m_layout->getLineCount() >= maxLine)
    {
        ret = VFX_TRUE;
    }

    return ret;
}


void VcpTextView::setMaxLayoutMemory(VfxS32 bufSize)
{
    VfxS32 lineNum = bufSize / VCP_TEXT_LINE_SIZE;
    m_layout->setMaxLineNum(lineNum);
}


VcpScrollableView *VcpTextView::onCreateView()
{
    VcpTextScrollView *view;

    VFX_OBJ_CREATE(view, VcpTextScrollView, this);

    return view;
}


#if VCP_TEXT_CLIPBOARD_SUPPORT
void VcpTextView::onClipboardEvent(VfxCcpEventType type, VfxWChar** string, VfxS32 len, VfxS32 *ret_len)
{
    VfxTextRange selRange = m_layout->getSelection();
    VfxS32 selLength = selRange.getLength();
    switch (type)
    {
    case VFX_CCP_NOTIFY_COPY:
    case VFX_CCP_NOTIFY_COPY_ALL:
    case VFX_CCP_NOTIFY_HIDE_MENU:
        // if in smart pinyin input method, the highlight should not clear for replace requirement
        if (!(m_editing && m_editing->m_inputManager && m_editing->m_inputManager->isIMEState()))
        {
            m_layout->setSelection(VfxTextRange(0, 0));
        }
        break;
    case VFX_CCP_CMD_GET_TEXT:
        if (selLength > 0)
        {
            *string =  getText() + selRange.getStart();
            *ret_len = selLength;
        }
        else
        {
            *string = NULL;
            *ret_len = 0;
        }
        break;
        
    case VFX_CCP_CMD_GET_ALL_TEXT:
        *string =  getText();
        *ret_len = getLength();
        break;
        
    case VFX_CCP_CMD_DEL_TEXT:
        {
            if (selLength > 0 && m_editing)
            {
                // only cut copied chars
                if (selLength > VCCP_MAX_BUFFER_SIZE / 2)
                {
                    VfxS32 newSelEnd = selRange.getStart() + VCCP_MAX_BUFFER_SIZE / 2;
                    m_layout->getSelection().setEnd(newSelEnd);
                }
                m_editing->deleteChars();
            }
            break;
        }
    case VFX_CCP_CMD_DEL_ALL_TEXT:
        if (m_editing)
        {
            if (getLength() > VCCP_MAX_BUFFER_SIZE / 2)
            {
                m_layout->getSelection().setRange(0, VCCP_MAX_BUFFER_SIZE / 2);
                m_editing->deleteChars();
            }
            else
            {
                m_editing->clear();
            }
        }
        break;
        
    case VFX_CCP_CMD_INSERT_TEXT:
        if (m_editing != NULL)
        {
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
        #else
            // insert one by one and check at insert step
            // performance is bad but can meet some App's requirement
            // the same as PLUTO
            kal_uint32 time1,time2;
            kal_get_time(&time1); 
            VfxS32 i;
            VfxS32 retLen = 0;
            VfxS32 insertLen = 0;
            VfxWChar *insertString = *string;
            m_editing->beginBatchEdit(); 
           
            for (i = 0; i < len; i++)
            {
                VfxWChar insertChar = insertString[i];
                // begin the batch edit mode
                if (m_editing->testInput(insertChar))
                {
                    retLen = m_editing->insertText(insertChar, -1);
                    if (retLen == 0)
                    {
                        playTone(VCP_TEXT_TONE_CANNOT_INSERT);
                        break;
                    }
                }
                else
                {
                    playTone(VCP_TEXT_TONE_CANNOT_INSERT);
                    break;
                }
            }

            insertLen = i;
            m_editing->endBatchEdit(); 

            kal_get_time(&time2); 
            VFX_LOG(VFX_FUNC2, VCP_TEXT_CLIPBOARD_PASTE, len, insertLen, kal_ticks_to_milli_secs(time2 - time1));
        #endif

            if (insertLen > 0)
            {
                // notify IME
                VfxRect cursorRect = m_editing->m_cursor->convertRectTo(m_editing->m_cursor->getBounds(), VFX_OBJ_GET_INSTANCE(VfxTopLevel));

                if (m_editing->m_inputManager)
                {
                    m_editing->m_inputManager->cursorPosChanged(cursorRect);
                }

                // notify APP
                m_editing->m_cursor->m_signalCursorIndexChanged.postEmit(m_editing->m_cursor);
            }
            
            *ret_len = insertLen;
        }
        break;
        
    case VFX_CCP_REQ_IS_SELECTED_TEXT:
        *ret_len = (selLength > 0) ? 1 : 0;
        break;
        
    case VFX_CCP_REQ_IS_EMPTY:
        *ret_len = (getLength() == 0) ? 1 : 0;
        break;
        
    case VFX_CCP_REQ_IS_READ_ONLY:
        {
            if (m_editing)
            {
                if (isActive())
                {
                    *ret_len = 0;
                }
                else
                {
                    // if inactive, should not show paste button
                    *ret_len = 1;
                }
            }
            else
            {
                *ret_len = 1;
            }
            break;
        }
    case VFX_CCP_REQ_IS_PASSWORD:
        if (m_editing && m_editing->m_inputBinding.m_inputType & IMM_INPUT_TYPE_EXT_PASSWORD)
        {
            *ret_len = 1;
        }
        else
        {
            *ret_len = 0;
        }
        break;
        
    default:
        break;
    }    
}
#endif


void VcpTextView::playTone(VcpTextToneEnum type)
{
    switch (type)
    {
    case VCP_TEXT_TONE_CANNOT_INSERT:
        UI_editor_play_tone_cannot_insert();
        break;
    case VCP_TEXT_TONE_CANNOT_DELETE:
        UI_editor_play_tone_cannot_change();
        break;
    case VCP_TEXT_TONE_CANNOT_NAVIGATE:
        UI_editor_play_tone_cannot_navigate();
        break;
    default:
        break;
    }
}


VfxBool VcpTextView::onKeyInput(VfxKeyEvent &event)
{
    VfxBool ret = VFX_FALSE;

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
        
    case VFX_KEY_CODE_ARROW_LEFT:
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
        {
            ret = VFX_FALSE;//previousPage();
        }
        break;
        
    case VFX_KEY_CODE_ARROW_RIGHT:
        if (event.type == VFX_KEY_EVENT_TYPE_DOWN || event.type == VFX_KEY_EVENT_TYPE_REPEAT)
        {
            ret = VFX_FALSE;//nextPage();
        }
        break; 
    default:
        ret = VFX_FALSE;
        break;
    }

    return ret;
}


void VcpTextView::onFocusChanged(VfxBool focused)
{
    if (focused)
    {
        activate(VFX_FALSE);
    }
    else
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
	
    #if VCP_TEXT_MAGNIFIER_SUPPORT
        if (m_magnifier)
        {
            VFX_OBJ_CLOSE(m_magnifier);
            m_isMagnifierState = VFX_FALSE;
        }
    #endif
        deactivate(VFX_FALSE);
    }
}


void VcpTextView::onObjectNotify(VfxId id, void *userData)
{
    switch (id)
    {
        case VFX_FRAME_NOTIFY_ID_FOCUS_CHANGED:
        {
            onFocusChanged(*(VfxBool *)userData);
            return;
        }
        case VFX_OBJECT_NOTIFY_ID_ADD_CHILD:
        {
            onAddChild((VfxObject *)userData);
            return;
        }
        default:
        {
            VcpScrollable::onObjectNotify(id, userData);
            return;
        }
    }
}


void VcpTextView::onBeforeRotate(VfxScreenRotateParam rotateParam)
{
    // save the first visible index
    // the text view should not on background screen
    VfxScreen *screen = findScreen();
    VfxScreen *actScreen = VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getActiveScr();
    m_visibleStartIndex = -1;
    if (m_lineMode == VCP_TEXT_LINE_MODE_MULTI && (m_editing == NULL || !isActive()) && screen && (screen == actScreen))
    {
        VfxRect viewBounds = getValidViewBounds();

        // if view point is at the start of text, don't save the start index (for first line is custom frame case)
        // if we save the index, the custom frame will be scroll out of visible area after rotate
        if (viewBounds.origin.y > 0)
        {
            VfxS32 lineIndex = m_layout->getLineIndexByY(viewBounds.getMinY());
            m_visibleStartIndex = m_layout->getLineStart(lineIndex);
        }
    }

#if defined(__COSMOS_MMI_PACKAGE__)
    // stop waiting icon before rotate
    if (m_waitingInd)
    {
        VFX_OBJ_CLOSE(m_waitingInd);
    }
#endif
}


void VcpTextView::onMaxLayoutLineNumReached(VcpTextBasicLayout *layout)
{
#if defined(__COSMOS_MMI_PACKAGE__)
    // notify user if max layout line number reached
    VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
    balloon->addItem(
        VCP_INFO_BALLOON_TYPE_INFO,
        VFX_WSTR_RES(STR_ID_CLIPBOARD_MAX_LINE_REACHED));
#endif

    VfxS32 lastPos = m_layout->getDirtyRange().getEnd();
    if (m_editing && (m_editing->getCursorIndex() > lastPos))
    {
        m_editing->m_cursor->setIndex(lastPos);
    }
}


void VcpTextView::onRotated(VfxScreenRotateParam rotateParam)
{
    // move the view point to first visible index saved before rotate (onBeforeRotate)
    // the text view should not on background screen
    VfxScreen *screen = findScreen();
    VfxScreen *actScreen = VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getActiveScr();
    if ((m_lineMode == VCP_TEXT_LINE_MODE_MULTI) && (m_visibleStartIndex >= 0) && screen && (screen == actScreen))
    {
        // force update layout before get line information
        forceUpdate(VFX_TRUE);

        scrollVisibleTimerHandler(NULL);
    }
}

void VcpTextView::scrollVisibleTimerHandler(VfxTimer *source)
{
    // scrollToVisibleStart until all layout is done, 
    // if layout is not done, use timer wait until done
    if (m_layout->getDirtyRange().getLength() > 0)
    {
        if (!m_scrollVisibleTimer)
        {
            VFX_OBJ_CREATE(m_scrollVisibleTimer, VfxTimer, this);
            m_scrollVisibleTimer->setStartDelay(VCP_MAX_LAYOUT_TIMER + 1);
            m_scrollVisibleTimer->m_signalTick.connect(this, &VcpTextView::scrollVisibleTimerHandler);
        }
        m_scrollVisibleTimer->start();

    #if defined(__COSMOS_MMI_PACKAGE__)
        // show waiting indicator
        if (m_waitingInd == NULL)
        {
            VFX_OBJ_CREATE(m_waitingInd, VcpActivityIndicator, VFX_OBJ_GET_INSTANCE(VfxTopLevel));
        }
        vrt_size_struct mainScreenSize;
        vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
        m_waitingInd->setAnchor(0.5f, 0.5f);
        m_waitingInd->setPos(mainScreenSize.width / 2, mainScreenSize.height / 2);
        m_waitingInd->setPosZ(VFX_TOP_LEVEL_Z_IME_UI - 1);
        m_waitingInd->setSize(VCP_TEXTVIEW_WAITING_ICON_SIZE, VCP_TEXTVIEW_WAITING_ICON_SIZE);
        m_waitingInd->start();
    #endif
    }
    else
    {
    #if defined(__COSMOS_MMI_PACKAGE__)
        if (m_waitingInd)
        {
            VFX_OBJ_CLOSE(m_waitingInd);
           // m_waitingInd->stop();
        }
    #endif
        scrollToVisibleStart();
    }
}


void VcpTextView::setBasePos(const VfxPoint pos)
{
    m_basePos = pos;

    checkUpdate();
}


void VcpTextView::setBasePosInternal(const VfxPoint pos)
{
    if (pos.isZero())
        return;

    VfxS32 baseline = m_layout->getLineBaseLine(0);

    setPos(pos.x, pos.y - baseline - m_topMargin);
}


void VcpTextView::scrollToVisibleStart()
{
    VfxS32 lineIndex = m_layout->getLineIndex(m_visibleStartIndex);
    VfxRect lineBounds = m_layout->getLineBounds(lineIndex);
    VfxRect scrollRect = m_view->getBounds();
    scrollRect.origin.y = lineBounds.origin.y - m_layout->getLineGap();

    // if the layout rect smaller than the view rect, limit the visible area with in valid rect
    VfxRect validRect = getLayoutRect();
    if ((m_lineMode == VCP_TEXT_LINE_MODE_MULTI) && (validRect.getHeight() <= scrollRect.getHeight()))
    {
        scrollRect.origin.y = 0;
    }

    scrollRectToVisible(scrollRect, VFX_TRUE);

    // limit text view visible area within valid rect
    limitTextViewToValidRect();
    m_visibleStartIndex = -1;
}


void VcpTextView::onClipboardTimer(VfxTimer *timer)
{
    VFX_UNUSED(timer);

    // if disable clipboard, return
    if (m_isDisableClipboard)
    {
        return;
    }

    // reset ime state when begin clipboard operation
    if (m_editing && m_editing->m_inputManager)
    {
        m_editing->m_inputManager->resetIMEState();
    }

    // activate text view, if not active, the onfocuschange will not come when enter sleep mode
    if (!isActive())
    {
        activate();
        if (m_editing != NULL)
        {
            // activate editor only because there're too many thing happened in editor activate
            return;
        }
    }

    // play touch feedback
    vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_HOLD);

    VfxS32 index = 0;
#if VCP_TEXT_MAGNIFIER_SUPPORT
    if (!m_penMovePos.isZero())
    {
        // if no pen move happened
        index = getTextLayout()->getIndexOfPos(m_penMovePos, NULL);
    }
    else
#endif
    {
        index = getTextLayout()->getIndexOfPos(m_penDownPos, NULL);
    }

    getTextLayout()->setSelection(VfxTextRange(0, 0));

    // show clipboard menu
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxPoint pos;
#if VCP_TEXT_MAGNIFIER_SUPPORT
    if (!m_penMovePos.isZero())
    {
        // if no pen move happened
        pos = getTextLayout()->getPosOfIndex(m_penMovePos, index);
    }
    else
#endif
    {
        pos = getTextLayout()->getPosOfIndex(m_penDownPos, index);
    }

    // convert to screen point
    VfxPoint cursor_screen_point = m_view->convertPointTo(pos, topLevel);//topLevel->convertPointFrom(pos, m_view);

#if VCP_TEXT_MAGNIFIER_SUPPORT
    if (m_magnifier)
    {
        m_magnifier->setSelectTextMode(VFX_TRUE);
    }
#else
    #if VCP_TEXT_CLIPBOARD_SUPPORT
    // do not show clipboard menu when enter clipboard state if in magnifier enable
    VfxS32 curLineHeight = 0;
    curLineHeight = getTextLayout()->getLineTextHeight(getTextLayout()->getLineIndex(index));
    m_clipboard->showMenu(
        VFX_CCP_FLOATING_MENU,
        cursor_screen_point,    // y1
        VfxPoint(cursor_screen_point.x, cursor_screen_point.y + curLineHeight)); // y2
    #endif
#endif
    m_isSelectingText = VFX_TRUE;

    m_selStart = index;

    // set cursor position
    if (m_editing != NULL)
    {
        m_editing->m_cursor->setIndex(index, &pos);
    }
}


#if VCP_TEXT_MAGNIFIER_SUPPORT

void VcpTextView::onMagnifierTimer(VfxTimer *timer)
{
    VFX_UNUSED(timer);

    if (m_isDisableMagnifier)
    {
        return;
    }

    // reset ime state when begin magnifier operation
    if (m_editing && m_editing->m_inputManager)
    {
        m_editing->m_inputManager->resetIMEState();
    }

    // activate text view, if not active, the onfocuschange will not come when enter sleep mode
    if (!isActive())
    {
        activate();
        if (m_editing != NULL)
        {
            // activate editor only, not show magnifer
            // because there're too many thing happened in editor activate
            return;
        }
    }

    VfxS32 index = 0;
    if (!m_penMovePos.isZero())
    {
        // if pen move happened
        index = getTextLayout()->getIndexOfPos(m_penMovePos, NULL);
    }
    else
    {
        index = getTextLayout()->getIndexOfPos(m_penDownPos, NULL);
    }

    // convert to screen point
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxPoint pos = getTextLayout()->getPosOfIndex(m_penDownPos, index);
    // convert to screen point
    VfxPoint cursor_screen_point = m_view->convertPointTo(pos, topLevel);

    // for mix languages, example: "|EEE|AAAA", there're two points for the same index.
    // we need to know where is the cursor locate to in the content area
    // which will decide the cursor pos in the magnifier area
    VfxPoint tempPos1, tempPos2;
    VfxBool isUsingPos1 = VFX_TRUE;
    tempPos1 = getTextLayout()->getPosOfIndex(index, &tempPos2);
    if (pos == tempPos1)
    {
        isUsingPos1 = VFX_TRUE;
    }
    else
    {
        isUsingPos1 = VFX_FALSE;
    }

    if (m_magnifier == NULL)
    {
        VFX_OBJ_CREATE(m_magnifier, VcpTextMagnifier, this);
        topLevel->addChildFrame(m_magnifier);
    }

    m_magnifier->setPos(cursor_screen_point);
    m_magnifier->setSize(0, 0);
    m_magnifier->setOpacity(0);

    m_magnifier->setAutoAnimate(VFX_TRUE);
    VfxAutoAnimate::initAnimateBegin();

    // It magnifier move out of screen area, pull back to screen scale.
    VfxS32 magnifierYPos = cursor_screen_point.y - VCP_TEXT_MAGNIFIER_DIST_TO_TEXT;
    m_magnifier->setPos(VfxPoint(cursor_screen_point.x, magnifierYPos));
    m_magnifier->setSize(VCP_TEXT_MAGNIFIER_WIDTH, VCP_TEXT_MAGNIFIER_HEIGHT);
    m_magnifier->setOpacity(VCP_TEXT_MAGNIFIER_BG_OPACITY);
    VfxAutoAnimate::initAnimateEnd();

    // get cursor line text
    const VfxWChar *lineText;
    VfxS32 lineTextLen;
    VfxS32 lineIndex = getTextLayout()->getLineIndex(index);
    VfxS32 lineStartIndex = getTextLayout()->getLineStart(lineIndex);
    // if index is the last positon of current line, should not move to next line
    // For example:
    // ________________
    // | Abcdefg|     |
    // | hijklm       |
    // |______________|
    // if cursor is after 'g' and index is 7, lineIndex will be 1, but it should be 0
    // should magnifier last position of first line instead of first position of second line
    // so need to set lineIndex = lineIndex - 1
    if (!(getTextLayout()->isIndexInCurrentLine(index, pos)))
    {
        lineIndex--;
    }
    lineStartIndex = getTextLayout()->getLineStart(lineIndex);

    VcpRichTextFormat *textFormat = NULL;

    lineText = getTextLayout()->getLineText(lineIndex, &lineTextLen);
    textFormat = m_storage->getRichTextFormat(
                    getTextLayout()->getLineStart(lineIndex), 
                    getTextLayout()->getLineEnd(lineIndex));
    VfxWChar *contentText;
    VFX_ALLOC_MEM(contentText, sizeof(VfxWChar) * (lineTextLen + 1), this);
    vfx_sys_wcsncpy(contentText, lineText, lineTextLen);

    m_magnifier->setText(contentText, textFormat);

    // if password mode, should set mask style
    if (m_editing && m_editing->m_inputBinding.m_inputType & IMM_INPUT_TYPE_EXT_PASSWORD)
    {
        m_magnifier->getContentView()->getTextLayout()->setMask(VFX_TRUE);
    }

    // free format object memory
    m_storage->deleteRichTextFormat(textFormat);
    VFX_FREE_MEM(contentText);

    // forceupdate to get size
    m_magnifier->getContentView()->forceUpdate();
        
    VfxPoint magPos1, magPos2;
    VfxS32 cursorOffset;
    magPos1 = m_magnifier->getContentView()->getTextLayout()->getPosOfIndex(index - lineStartIndex, &magPos2);
    if (isUsingPos1)
    {
        cursorOffset = magPos1.x;
    }
    else
    {
        cursorOffset = magPos2.x;
    }

    // set text position
    if (m_magnifier->getContentView()->getBounds().getHeight() < VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT)
    {
        m_magnifier->getContentView()->setAnchor(0, 0.5f);
        m_magnifier->getContentView()->setPos(VfxPoint(
            VCP_TEXT_MAGNIFIER_CONTENT_WIDTH / 2 - cursorOffset,
            VCP_TEXT_MAGNIFIER_HEIGHT / 2 - (VCP_TEXT_MAGNIFIER_HEIGHT - VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT) / 2));
    }
    else
    {
        m_magnifier->getContentView()->setAnchor(0, 1.0f);
        m_magnifier->getContentView()->setPos(VfxPoint(
            VCP_TEXT_MAGNIFIER_CONTENT_WIDTH / 2 - cursorOffset,
            VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT));
    }

    // get current text highlight
    VfxS32 hStart, hEnd;
    getHighlight(&hStart, &hEnd);
    VfxTextRange highlight(hStart - lineStartIndex,hEnd - lineStartIndex);
    highlight.limitTo(VfxTextRange(0, lineTextLen));
    if (highlight.getLength() > 0)
    {
        m_magnifier->getContentView()->setHighlight(highlight.getStart(), highlight.getEnd());
    }

    // disable text animation because it will be too dizzy when locate cursor
    m_magnifier->getContentView()->setAutoAnimate(VFX_FALSE);
    m_magnifier->setSelectTextMode(VFX_FALSE);

    m_isMagnifierState = VFX_TRUE;

    // set cursor position
    if (m_editing != NULL)
    {
        m_editing->m_cursor->setIndex(index, &pos);
    }

    // save current line index
    m_magnifier->m_lineIndex = lineIndex;

    // start clipboard timer
    m_clipboardTimer->start();

#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_config_move_offset(
        VCP_TEXT_VIEW_TOUCH_MOVE_OFFSET,
        VFX_SYS_PEN_SKIP_MOVE_OFFSET,
        VFX_SYS_PEN_SKIP_LONGTAP_OFFSET,
        VFX_SYS_PEN_SKIP_LONGTAP_OFFSET);
#endif
}

#endif


VfxRect VcpTextView::getValidViewBounds()
{
    if (getIsIntersectScreen() && !(getIntersectRect().isEmpty()))
    {
        return getIntersectRect();
    }
    else
    {
        return getViewBounds();
    }
}


/***************************************************************************** 
 * Class VcpTextCellView
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpTextCellView", VcpTextCellView, VfxControl);

void VcpTextCellView::onDraw(VfxDrawContext &dc)
{
#if 0
#ifdef __MAUI_SOFTWARE_LA__
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
/* under construction !*/
#ifdef __MAUI_SOFTWARE_LA__
/* under construction !*/
#endif
#endif
}


void VcpTextCellView::refresh(VfxBool isNeedRedrawText)
{
    if (isNeedRedrawText)
    {
        m_contentText->invalidate();
    }
    m_contentHilite->invalidate();
}

void VcpTextCellView::onInit()
{
    VfxControl::onInit();
#if defined(__COSMOS_MMI_PACKAGE__)
    // in cosmos project, the highlight is transparent and draw above the text, so the hilite frame should create after text
    VFX_OBJ_CREATE_EX(m_contentText, VcpTextCellContentView, this, (VcpTextCellContentView::VCP_TEXT_CELL_CONTENT_TEXT));
    VFX_OBJ_CREATE_EX(m_contentHilite, VcpTextCellContentView, this, (VcpTextCellContentView::VCP_TEXT_CELL_CONTENT_HILITE));
#else
    // in non cosmos project, the highlight is not transparent and draw below the text, so the hilite frame should create before text
    VFX_OBJ_CREATE_EX(m_contentHilite, VcpTextCellContentView, this, (VcpTextCellContentView::VCP_TEXT_CELL_CONTENT_HILITE));
    VFX_OBJ_CREATE_EX(m_contentText, VcpTextCellContentView, this, (VcpTextCellContentView::VCP_TEXT_CELL_CONTENT_TEXT));
#endif
    sendToBack();
}


void VcpTextCellView::setLayout(VcpTextBasicLayout* layout)
{
    m_layout = layout;
    m_contentText->setLayout(m_layout);
    m_contentHilite->setLayout(m_layout);
}


void VcpTextCellView::setBounds(const VfxRect &value)
{
    VfxFrame::setBounds(value);
    m_contentText->setBounds(value);
    m_contentHilite->setBounds(value);
}


/***************************************************************************** 
 * Class VcpTextCellContentView
 *****************************************************************************/
void VcpTextCellContentView::onDraw(VfxDrawContext &dc)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TCD", SA_start);
#endif
    VfxPoint p = ((VfxFrame *)getParent())->getPos();
    VfxRect drawRect(((VfxFrame *)getParent())->getPos(), getSize());

    p.x = -p.x;
    p.y = -p.y;

    if (!drawRect.isEmpty())
    {
        if (m_type == VCP_TEXT_CELL_CONTENT_TEXT)
        {
            m_layout->draw(dc, drawRect, p);
        }
        else if (m_type == VCP_TEXT_CELL_CONTENT_HILITE)
        {
            m_layout->draw(dc, drawRect, p, VFX_TRUE);
        }
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TCD", SA_stop);
#endif
}


void VcpTextCellContentView::refresh()
{
    invalidate();
}

void VcpTextCellContentView::onInit()
{
    VfxControl::onInit();

    if (m_type == VCP_TEXT_CELL_CONTENT_TEXT)
    {
        VfxFrameHintsEnum frameHints = (VfxFrameHintsEnum)(VFX_FRAME_HINTS_RARE_TRANSLUCENT | (VfxU16)VFX_FRAME_HINTS_SW_IMG_CONTENT_OVERLAY);

        setHints(frameHints);

        setCacheMode(VFX_CACHE_MODE_FORCE);
    }
}


/***************************************************************************** 
 * Class VcpTextScrollView
 *****************************************************************************/
VcpTextScrollView::VcpTextScrollView() : 
    m_selectingText(VFX_FALSE)
{
    
}


VfxBool VcpTextScrollView::onPenAbortAccepted(VfxControl *aborter, VfxPenAbortReasonEnum reason)
{
    VcpTextView *view = getTextView();
    if (!view->m_isSelectingText && !view->m_isMagnifierState)
    {
        return VcpScrollableView::onPenAbortAccepted(aborter, reason);
    }
    else
    {
        return VFX_FALSE;
    }
}


void VcpTextScrollView::limitPosWithinRect(VfxPoint &pos, VfxRect rect)
{
    if (pos.x < rect.getMinX())
    {
        pos.x = rect.getMinX();
    }
    else if (pos.x > rect.getMaxX())
    {
        pos.x = rect.getMaxX();
    }

    if (pos.y < rect.getMinY())
    {
        pos.y = rect.getMinY();
    }
    else if (pos.y > rect.getMaxY())
    {
        pos.y = rect.getMaxY();
    }
}

    
VfxBool VcpTextScrollView::onPenInput(VfxPenEvent &event)
{
    VcpTextView *view = getTextView();
    VfxBool ret = VFX_FALSE;
    VfxBool isPenUpMove = VFX_FALSE; // check if the pen moves when pen up
    VfxPoint penRealPos = event.getRelPos(this);
    penRealPos.y -= VCP_TEXT_VIEW_TOUCH_OFFSET;
#if defined(__COSMOS_MMI_PACKAGE__)
    static VfxBool s_selectNotify = VFX_TRUE; // if need to notify when select more than limitation
#endif
    if (event.type == VFX_PEN_EVENT_TYPE_UP)
    {
        VfxS32 xDistance = 0;
        VfxS32 yDistance = 0;
        xDistance = VFX_ABS(event.pos.x - event.downPos.x);
        yDistance = VFX_ABS(event.pos.y - event.downPos.y);
        if (xDistance > VCP_TEXTVIEW_TAP_DISTANCE_RADIUS || yDistance > VCP_TEXTVIEW_TAP_DISTANCE_RADIUS)
        {
            isPenUpMove = VFX_TRUE;
        }
    }

    // should not scroll multiline content if in clipboard state
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    if (view->m_isSelectingText || view->m_isMagnifierState)
    {
        ret = VFX_TRUE;
    }
    else
    {
        ret = VcpScrollableView::onPenInput(event);
    }
    
    if (view->m_editing != NULL)
    {
        if (view->isActive())
        {
            // dispatch pen event to IME
            if (view->m_editing->m_inputManager)
            {
                if (!isPenUpMove && !view->m_isSelectingText && !view->m_isMagnifierState)
                {
                    if (view->m_editing->m_inputManager->dispatchPenEvent(event))
                        return VFX_TRUE;
                }
                else
                {
                    // send abort event to IME
                    VfxPenEvent abortEvent = event;
                    abortEvent.type = VFX_PEN_EVENT_TYPE_ABORT;
                    view->m_editing->m_inputManager->dispatchPenEvent(abortEvent);
                }
            }
        }
    }

    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            {
                // clear selection
                view->getTextLayout()->setSelection(VfxTextRange(0, 0));
    #if VCP_TEXT_CLIPBOARD_SUPPORT
                view->m_clipboard->hideMenu();
    #endif
                // postEmit keyword click event
                VcpRichTextFormat *obj = view->m_layout->getObjectOfPos(event.getRelPos(this));

                // highlight keyword if any
                if (view->m_storage->isKeywordMode())
                {
                    if (obj && obj->getType() == VCP_RICH_TEXT_TYPE_TEXT &&
                        ((VcpRichText*)obj)->isKeywordFormat())
                    {
                        view->setHighlight(obj->m_range.getStart(), obj->m_range.getEnd());
                    }
                    else
                    {
                        view->setHighlight(0, 0);
                    }
                    view->checkUpdate();
                }

                // highlight hyperlink if there're any
                if (obj && obj->getType() == VCP_RICH_TEXT_TYPE_HYPERLINK)
                {
                    view->setHighlight(obj->m_range.getStart(), obj->m_range.getEnd());
                }

                // start a timer for magnifier
            #if VCP_TEXT_MAGNIFIER_SUPPORT
                view->m_magnifierTimer->start();
            #else
                // start a timer for clipboard
                view->m_clipboardTimer->start();
            #endif

                view->m_penDownPos = penRealPos;
                view->m_penMovePos.setZero();
            #if defined(__COSMOS_MMI_PACKAGE__)
                s_selectNotify = VFX_TRUE;
            #endif
                break;
            }
        case VFX_PEN_EVENT_TYPE_UP:
            {
            #if VCP_TEXT_MAGNIFIER_SUPPORT
                view->m_magnifierTimer->stop();
            #endif
                view->m_clipboardTimer->stop();
                if (!m_isDecelerating || view->m_isSelectingText)
                {
                    /* no scroll happened */
                    if (!isPenUpMove &&
                        !view->m_isSelectingText && !view->m_isMagnifierState)
                    {
                        if (view->m_editing != NULL)
                        {
                            if (view->isActive())
                            {
                                /* clear selection if not selecting mode */
                                if (!view->m_isSelectingText)
                                {
                                    view->setHighlight(0, 0);
                                }

                                if (event.prevPos != event.pos)
                                {
                                    view->m_editing->locateCursorTo(event.getRelPrevPos(this));
                                }
                                else
                                {
                                    view->m_editing->locateCursorTo(event.getRelPos(this));
                                }
                            }
                            else
                            {
                                view->activate();
                                // always open VK when tap on editor to activate
                                if (!view->m_editing->m_inputManager->isSoftInputVisible())
                                {
                                    view->m_editing->m_inputManager->showSoftInput();
                                }
                            }
                        }
                    }               
                    if (view->m_isSelectingText)
                    {
                        if (view->m_editing)
                        {
                            VfxS32 selEnd = view->m_editing->getCursorIndex();
                            VfxS32 selStart = view->m_selStart;
                            if (selEnd > view->m_selStart)
                            {
                                view->getTextLayout()->setSelection(VfxTextRange(selStart, selEnd));
                            }
                            else
                            {
                                view->getTextLayout()->setSelection(VfxTextRange(selEnd, selStart));
                            }
                            // set cursor position to selection end position
                            VfxPoint cursorRealPos = view->getTextLayout()->getPosOfIndex(penRealPos, selEnd);
                            view->m_editing->m_cursor->setIndex(selEnd, &cursorRealPos);
                        }
                    #if VCP_TEXT_CLIPBOARD_SUPPORT

                        VfxTextRange selRange = view->getTextLayout()->getSelection();
                        VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
                        const VfxFrame *root = renderer->getRootFrame();

                        if (selRange.getLength() > 0)
                        {
                            VfxPoint p1;
                            VfxPoint p2;
                            p1 = view->getTextLayout()->getPosOfIndex(view->m_penDownPos, selRange.getStart());
                            p2 = view->getTextLayout()->getPosOfIndex(penRealPos, selRange.getEnd());

                            // limit the pos within the view bounds
                             VfxRect viewBounds = view->getValidViewBounds();

                            limitPosWithinRect(p1, viewBounds);
                            limitPosWithinRect(p2, viewBounds);

                            // convert to screen point
                            p1 = root->convertPointFrom(p1, this);
                            p2 = root->convertPointFrom(p2, this);

                            VfxS32 curLineHeight = 0;
                            curLineHeight = view->getTextLayout()->getLineTextHeight(view->getTextLayout()->getLineIndex(selRange.getEnd()));
                            view->m_clipboard->showMenu(VFX_CCP_FLOATING_MENU, p1, VfxPoint(p2.x, p1.y + curLineHeight));
                        }
                        else
                        {
                            VfxS32 index = view->getTextLayout()->getIndexOfPos(penRealPos, NULL);
                            VfxPoint pos = view->getTextLayout()->getPosOfIndex(penRealPos, index);

                            if (view->m_editing)
                            {
                                pos = view->m_editing->m_cursor->getPos();
                            }
                            else
                            {
                                // limit the pos within the view bounds
                                VfxRect viewBounds = view->getValidViewBounds();

                                limitPosWithinRect(pos, viewBounds);
                            }

                            pos = root->convertPointFrom(pos, this);
                            VfxS32 curLineHeight = 0;
                            curLineHeight = view->getTextLayout()->getLineTextHeight(view->getTextLayout()->getLineIndex(index));
                            view->m_clipboard->showMenu(VFX_CCP_FLOATING_MENU, pos, VfxPoint(pos.x, pos.y + curLineHeight));
                        }
					
                    #endif /* VCP_TEXT_CLIPBOARD_SUPPORT */
                    }
                    else
                    {
                        VfxS32 xDistance = 0;
                        VfxS32 yDistance = 0;
                        xDistance = VFX_ABS(event.pos.x - event.downPos.x);
                        yDistance = VFX_ABS(event.pos.y - event.downPos.y);

                        // response key word click event and tap event if not in magnifier state
                        if (!view->m_isMagnifierState &&
                            (xDistance < VCP_TEXTVIEW_TAP_DISTANCE_RADIUS && yDistance < VCP_TEXTVIEW_TAP_DISTANCE_RADIUS))
                        {
                            // pen down object
                            VcpRichTextFormat *obj = view->m_layout->getObjectOfPos(event.getRelPos(this));

                            // postEmit keyword click event
                            if (view->m_storage->isKeywordMode())
                            {
                                if (obj && obj->getType() == VCP_RICH_TEXT_TYPE_TEXT &&
                                    ((VcpRichText*)obj)->isKeywordFormat() &&
                                    view->m_layout->getSelection().getLength() > 0) // Pen down should on the keyword also (pen down on key word will setHighlight)
                                {
                                    view->m_signalKeywordClick.postEmit(
                                        ((VcpRichText*)obj)->m_mode,
                                        view->getText() + obj->m_range.getStart(),
                                        obj->m_range.getLength());
                                }
                            }

                            // tap event
                            VfxRect validRect = view->getValidContentRect();
                            if (((view->m_storage->getTextLength() == 0) && (view->m_storage->getRichTextFormat() == NULL)) ||
                                     !(validRect.contains(event.getRelPos(this))))
                            {
                                // when view content is empty
                                view->m_signalTapEvent.postEmit(view, VCP_TEXT_TAP_AREA_EMPTY, NULL);
                            }
                            else if (obj)
                            {
                                if(obj->getType() == VCP_RICH_TEXT_TYPE_CUSTOM_FRAME)
                                {
                                    VfxRect objRect;
                                    objRect.origin = ((VcpRichTextCustomFrame *)obj)->getPos();
                                    objRect.size = ((VcpRichTextCustomFrame *)obj)->getSize();

                                    // if obj center align, the anchor point is (0.5f, 0)
                                    if (obj->getObjectAttribute() == VCP_RICH_TEXT_OBJ_ARRT_MID_ALIGN)
                                    {
                                        objRect.origin.x -= (objRect.size.width / 2);
                                    }

                                    if (objRect.contains(event.getRelPos(this)))
                                    {
                                        view->m_signalTapEvent.postEmit(view, VCP_TEXT_TAP_AREA_OBJECT, obj);
                                    }
                                    else
                                    {
                                        view->m_signalTapEvent.postEmit(view, VCP_TEXT_TAP_AREA_EMPTY, NULL);
                                    }
                                }
                                else
                                {
                                    view->m_signalTapEvent.postEmit(view, VCP_TEXT_TAP_AREA_OBJECT, obj);
                                }
                            }
                            else
                            {
                                view->m_signalTapEvent.postEmit(view, VCP_TEXT_TAP_AREA_TEXT, NULL);
                            }
                        }
                    }
                }
            }
        #if VCP_TEXT_MAGNIFIER_SUPPORT
            // close magnifier
            if (view->m_magnifier && view->m_isMagnifierState)
            {
                // limit the pen up pos within the view bounds
                VfxRect viewBounds = view->getValidViewBounds();
                limitPosWithinRect(penRealPos, viewBounds);

                VfxS32 index = view->getTextLayout()->getIndexOfPos(penRealPos, NULL);
                VfxPoint pos = view->getTextLayout()->getPosOfIndex(penRealPos, index);
                
                VfxPoint adjustPos = pos;
                VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
                const VfxFrame *root = renderer->getRootFrame();
                adjustPos = root->convertPointFrom(adjustPos, this);

                // if not selecting text and pen up, also show clipboard menu so user
                // can paste, copy all, cut all...
                if (!view->m_isSelectingText && !view->m_isDisableClipboard)
                {
                    // set cursor position to up position
                    if (isPenUpMove && (view->m_editing != NULL))
                    {
                        view->m_editing->m_cursor->setIndex(index, &pos);
                    }

                    if (view->m_editing)
                    {
                        // always show menu above cursor position when no selection
                        adjustPos = view->m_editing->m_cursor->getPos();
                        adjustPos = VFX_OBJ_GET_INSTANCE(VfxRenderer)->getRootFrame()->convertPointFrom(adjustPos, this);
                    }
                #if VCP_TEXT_CLIPBOARD_SUPPORT

                    VfxS32 curLineHeight = 0;
                    curLineHeight = view->getTextLayout()->getLineTextHeight(view->getTextLayout()->getLineIndex(index));
                    view->m_clipboard->showMenu(VFX_CCP_FLOATING_MENU, adjustPos, VfxPoint(adjustPos.x, adjustPos.y + curLineHeight));
                #endif
                }
                view->m_magnifier->setAutoAnimate(VFX_TRUE);
                view->m_magnifier->getContentView()->setAutoAnimate(VFX_TRUE);
                VfxAutoAnimate::initAnimateBegin();
                view->m_magnifier->setPos(adjustPos);
                view->m_magnifier->setSize(0, 0);
                view->m_magnifier->setOpacity(0);
                VfxAutoAnimate::initAnimateEnd();
                view->m_isMagnifierState = VFX_FALSE;
            }
        #endif
            view->m_isSelectingText = VFX_FALSE;
            break;
        case VFX_PEN_EVENT_TYPE_LONG_TAP:
            {
            }
            break;
        case VFX_PEN_EVENT_TYPE_MOVE:
            {
                VfxS32 xDistance = 0;
                VfxS32 yDistance = 0;
                xDistance = VFX_ABS(event.pos.x - event.downPos.x);
                yDistance = VFX_ABS(event.pos.y - event.downPos.y);

                if (!(xDistance < VCP_TEXTVIEW_TAP_DISTANCE_RADIUS && yDistance < VCP_TEXTVIEW_TAP_DISTANCE_RADIUS))
                {
                    // pen move then need to stop the clipboad and magnifier timer
                #if VCP_TEXT_MAGNIFIER_SUPPORT
                    view->m_magnifierTimer->stop();
                #else
                    view->m_clipboardTimer->stop();
                #endif
                }

            #if VCP_TEXT_MAGNIFIER_SUPPORT
                if (view->m_isMagnifierState)
                {
                    // after show magnifier if not move for a while, show enter clipboard state
                    xDistance = VFX_ABS(event.pos.x - view->m_penMovePos.x);
                    yDistance = VFX_ABS(event.pos.y - view->m_penMovePos.y);
                    if (!(xDistance < VCP_TEXTVIEW_TAP_DISTANCE_RADIUS && yDistance < VCP_TEXTVIEW_TAP_DISTANCE_RADIUS))
                    {
                        // pen move then need to stop the clipboad
                        view->m_clipboardTimer->stop();
                    }
                }
            #endif
            #if VCP_TEXT_CLIPBOARD_SUPPORT
                view->m_clipboard->hideMenu();
            #endif
                VfxPoint realPos = penRealPos;

                // adjust view when move out of view area
                if (view->m_isSelectingText || view->m_isMagnifierState)
                {
                    if (view->m_lineMode == VCP_TEXT_LINE_MODE_SINGLE)
                    {
                        if (realPos.x < getBounds().getMinX())
                        {
                            VfxBool ret = view->scroll(-VCP_TEXT_VIEW_ADJUST_OFFSET, 0);
                            if (ret)
                            {
                                realPos.x = getBounds().getMinX() + VCP_TEXT_VIEW_ADJUST_OFFSET;
                            }
                        }
                        else if (realPos.x > getBounds().getMaxX())
                        {
                            VfxBool ret = view->scroll(VCP_TEXT_VIEW_ADJUST_OFFSET, 0);
                            if (ret)
                            {
                                realPos.x = getBounds().getMaxX() - VCP_TEXT_VIEW_ADJUST_OFFSET;
                            }
                        }
                    }
                    else
                    {
                        VfxS32 minLineHeight, ascent, descent;
                        VcpTextUtils tuTemp(this);
                        minLineHeight = tuTemp.getTextHeightOfCommonLang(&view->m_layout->m_font, &ascent, &descent);

                        if (realPos.y < getBounds().getMinY())
                        {
                            VfxBool ret = view->previousLine();
                            if (ret)
                            {
                                realPos.y = getBounds().getMinY() + minLineHeight;
                            }
                        }
                        else if (realPos.y > getBounds().getMaxY())
                        {
                            VfxBool ret = view->nextLine();
                            if (ret)
                            {
                                realPos.y = getBounds().getMaxY() - minLineHeight;
                            }
                        }
                    }
                }

                VcpTextUtils assignTu(this);
                VfxS32 index = view->getTextLayout()->getIndexOfPos(realPos, NULL, &assignTu);
                VfxPoint cursorRealPos = view->getTextLayout()->getPosOfIndex(realPos, index, &assignTu);
                if (view->m_isSelectingText == VFX_TRUE)
                {
                    VfxS32 selStart = view->m_selStart;
                    if (index > view->m_selStart)
                    {
                        view->getTextLayout()->setSelection(VfxTextRange(selStart, index));
                    }
                    else
                    {
                        view->getTextLayout()->setSelection(VfxTextRange(index, selStart));
                    }
                #if defined(__COSMOS_MMI_PACKAGE__)
                #if VCP_TEXT_CLIPBOARD_SUPPORT
                    // notify user if max copy/cut text is selected
                    if (view->getTextLayout()->getSelection().getLength() > VCCP_MAX_BUFFER_SIZE / 2)
                    {
                        if (s_selectNotify)
                        {
                            // popup info ballon
                            VcpInfoBalloon *balloon = VFX_OBJ_GET_INSTANCE(VcpInfoBalloon);
                            balloon->addItem(
                                VCP_INFO_BALLOON_TYPE_INFO,
                                VFX_WSTR_RES(STR_ID_CLIPBOARD_MAX_COPY_TEXT_SELECTED));
                            s_selectNotify = VFX_FALSE;
                        }
                    }
                    else
                    {
                        s_selectNotify = VFX_TRUE;
                    }
                #endif
                #endif
                #if !VCP_TEXT_MAGNIFIER_SUPPORT
                    // set cursor position
                    if (view->m_editing != NULL)
                    {
                        view->m_editing->m_cursor->setIndex(index, &cursorRealPos);
                    }
                #endif
                }
            #if VCP_TEXT_MAGNIFIER_SUPPORT
                if (view->m_isMagnifierState)
                {
                    // for mix languages, example: "|EEE|AAAA", there're two points for the same index.
                    // we need to know where is the cursor locate to in the content area
                    // which will decide the cursor pos in the magnifier area
                    VfxPoint tempPos1, tempPos2;
                    VfxBool isUsingPos1 = VFX_TRUE;
                    tempPos1 = view->getTextLayout()->getPosOfIndex(index, &tempPos2, &assignTu);
                    if (cursorRealPos == tempPos1)
                    {
                        isUsingPos1 = VFX_TRUE;
                    }
                    else
                    {
                        isUsingPos1 = VFX_FALSE;
                    }

                    view->m_magnifier->setAutoAnimate(VFX_FALSE);
                    VfxPoint screenPos;
                    if (view->m_editing)
                    {
                        // always show menu above cursor position
                        screenPos = view->m_editing->m_cursor->getPos();
                        screenPos = VFX_OBJ_GET_INSTANCE(VfxRenderer)->getRootFrame()->convertPointFrom(screenPos, this);
                    }
                    else
                    {
                        screenPos = view->m_view->convertPointTo(cursorRealPos, VFX_OBJ_GET_INSTANCE(VfxTopLevel));
                    }

                    // It magnifier move out of screen area, pull back to screen scale.
                    VfxS32 magnifierYPos = screenPos.y - VCP_TEXT_MAGNIFIER_DIST_TO_TEXT;
                    view->m_magnifier->setPos(VfxPoint(screenPos.x, magnifierYPos));

                    VfxS32 lineIndex = view->getTextLayout()->getLineIndex(index);
                    VfxS32 lineStartIndex = view->getTextLayout()->getLineStart(lineIndex);

                    // if index is the last positon of current line, should not move to next line
                    // For example:
                    // ________________
                    // | Abcdefg|     |
                    // | hijklm       |
                    // |______________|
                    // if cursor is after 'g' and index is 7, lineIndex will be 1, but it should be 0
                    // should magnifier last position of first line instead of first position of second line
                    // so need to set lineIndex = lineIndex - 1
                    if (!(view->getTextLayout()->isIndexInCurrentLine(index, cursorRealPos)))
                    {
                        lineIndex--;
                    }
                    lineStartIndex = view->getTextLayout()->getLineStart(lineIndex);

                    // only set text when move to another line
                    if (view->m_magnifier->m_lineIndex != lineIndex)
                    {
                        // get cursor line text
                        VfxS32 lineTextLen = 0;
                        VcpRichTextFormat *textFormat = NULL;
                        const VfxWChar *lineText;
                        lineText = view->getTextLayout()->getLineText(lineIndex, &lineTextLen);
                        textFormat = view->m_storage->getRichTextFormat(
                                        view->getTextLayout()->getLineStart(lineIndex), 
                                        view->getTextLayout()->getLineEnd(lineIndex));


                        VfxWChar *contentText;
                        VFX_ALLOC_MEM(contentText, sizeof(VfxWChar) * (lineTextLen + 1), this);
                        vfx_sys_wcsncpy(contentText, lineText, lineTextLen);

                        view->m_magnifier->setText(contentText, textFormat);

                        // free format object memory
                        view->m_storage->deleteRichTextFormat(textFormat);
                        VFX_FREE_MEM(contentText);

                        view->m_magnifier->m_lineIndex = lineIndex;

                        // when switch to another line, the size should be reset. 
                        // Otherwise, when update the line bounds in forceUpdate,
                        // the line start position will be wrong in right alignment
                        view->m_magnifier->getContentView()->setSize(0, 0);

                        // forceupdate to get size
                        view->m_magnifier->getContentView()->forceUpdate();
                    }

                    VfxPoint magPos1, magPos2;
                    VfxS32 cursorOffset;
                    magPos1 = view->m_magnifier->getContentView()->getTextLayout()->getPosOfIndex(index - lineStartIndex, &magPos2);
                    if (isUsingPos1)
                    {
                        cursorOffset = magPos1.x;
                    }
                    else
                    {
                        cursorOffset = magPos2.x;
                    }

                    // set text position
                    if (view->m_magnifier->getContentView()->getBounds().getHeight() < VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT)
                    {
                        view->m_magnifier->getContentView()->setAnchor(0, 0.5f);
                        view->m_magnifier->getContentView()->setPos(VfxPoint(
                            VCP_TEXT_MAGNIFIER_CONTENT_WIDTH / 2 - cursorOffset,
                            VCP_TEXT_MAGNIFIER_HEIGHT / 2 - (VCP_TEXT_MAGNIFIER_HEIGHT - VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT) / 2));
                    }
                    else
                    {
                        view->m_magnifier->getContentView()->setAnchor(0, 1.0f);
                        view->m_magnifier->getContentView()->setPos(VfxPoint(
                            VCP_TEXT_MAGNIFIER_CONTENT_WIDTH / 2 - cursorOffset,
                            VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT));
                    }
                    // set highlight of magnifier area
                    VfxS32 hStart = 0, hEnd = 0;
                    view->getTextLayout()->getHighlight(&hStart, &hEnd);
                    view->m_magnifier->getContentView()->setHighlight(hStart - lineStartIndex, hEnd - lineStartIndex);

                    if (view->m_editing != NULL)
                    {
                        view->m_editing->m_cursor->setIndex(index, &cursorRealPos);
                    }

                    // start clipboard timer
                    if (!view->m_isSelectingText)
                    {
                        view->m_clipboardTimer->start();
                    }

                    // restore pen move offset
                #ifdef __MMI_TOUCH_SCREEN__
                    mmi_pen_config_move_offset(
                        VFX_SYS_PEN_SKIP_MOVE_OFFSET,
                        VFX_SYS_PEN_SKIP_MOVE_OFFSET,
                        VFX_SYS_PEN_SKIP_LONGTAP_OFFSET,
                        VFX_SYS_PEN_SKIP_LONGTAP_OFFSET);
                #endif
                }
            #endif
                    // save move pos
                    view->m_penMovePos = event.getRelPrevPos(this);
                    view->m_penMovePos.y -= VCP_TEXT_VIEW_TOUCH_OFFSET;
                }
            break;
        case VFX_PEN_EVENT_TYPE_ABORT:
            {
                // reset clipboard and mark text
                if (view->m_isSelectingText)
                {
                    view->m_isSelectingText = VFX_FALSE;
                    // clear selection
                    view->getTextLayout()->setSelection(VfxTextRange(0, 0));
                }

                view->m_clipboardTimer->stop();
				
            #if VCP_TEXT_CLIPBOARD_SUPPORT
                view->m_clipboard->hideMenu();
            #endif

            #if VCP_TEXT_MAGNIFIER_SUPPORT
                // reset magnifier
                view->m_magnifierTimer->stop();
                view->m_isMagnifierState = VFX_FALSE;
                if (view->m_magnifier)
                {
                    VFX_OBJ_CLOSE(view->m_magnifier);
                }

                // restore pen move offset
            #ifdef __MMI_TOUCH_SCREEN__
                mmi_pen_config_move_offset(
                    VFX_SYS_PEN_SKIP_MOVE_OFFSET,
                    VFX_SYS_PEN_SKIP_MOVE_OFFSET,
                    VFX_SYS_PEN_SKIP_LONGTAP_OFFSET,
                    VFX_SYS_PEN_SKIP_LONGTAP_OFFSET);
            #endif
            #endif
            }
            break;
    }

    return ret;
}


VcpTextView* VcpTextScrollView::getTextView()
{
    return (VcpTextView*) getParentFrame();
}


#if VCP_TEXT_MAGNIFIER_SUPPORT

/***************************************************************************** 
 * Class VcpTextMagnifier
 *****************************************************************************/
VcpTextMagnifier::VcpTextMagnifier()
{
    m_contentView = NULL;
    m_textFrame = NULL;
    m_magnifierBackground = NULL;
    m_magnifierMask = NULL;
    m_magnifierCursorFrame = NULL;
    m_lineIndex = -1;
    m_effect = NULL;
}


void VcpTextMagnifier::onInit(void)
{
    VfxControl::onInit();

    setAnchor(0.5f, 1.0f);

    // background
    VFX_OBJ_CREATE(m_magnifierBackground, VfxFrame, this);
    m_magnifierBackground->setOpacity(VCP_TEXT_MAGNIFIER_BG_OPACITY);
    m_magnifierBackground->setSize(VCP_TEXT_MAGNIFIER_WIDTH, VCP_TEXT_MAGNIFIER_HEIGHT);
    m_magnifierBackground->setImgContent(VfxImageSrc(VCP_IMG_TEXT_MAGNIFIER_BG));
    m_magnifierBackground->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_magnifierBackground->setAutoAnimate(VFX_TRUE);

    // text frame
    VFX_OBJ_CREATE(m_textFrame, VfxFrame, this);
    m_textFrame->setPos(VCP_TEXT_MAGNIFIER_CONTENT_X, VCP_TEXT_MAGNIFIER_CONTENT_Y);
    m_textFrame->setSize(VCP_TEXT_MAGNIFIER_CONTENT_WIDTH, VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT);
    m_textFrame->setAutoAnimate(VFX_TRUE);

    // create font effect object
    VFX_ALLOC_NEW(m_effect, VfxFontEffect, this);
    m_effect->setType(VFX_FONT_EFFECT_SHADOW);
    m_effect->setShadow(VFX_COLOR_BLACK,    // shadow color
        135,                                // degree of shadow color
        2,                                  // distant between the shadow original to the text original
        0,                                  // shadow range
        40                                  // shadow intensity
    );

    // text content
    VFX_OBJ_CREATE(m_contentView, VcpTextView, m_textFrame);
    m_contentView->setAnchor(0, 0.5f);
    m_contentView->setPos(
        VCP_TEXT_MAGNIFIER_WIDTH / 2, 
        VCP_TEXT_MAGNIFIER_HEIGHT / 2 - (VCP_TEXT_MAGNIFIER_HEIGHT - VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT) / 2);
    m_contentView->setLineMode(VCP_TEXT_LINE_MODE_SINGLE);
    m_contentView->setAutoResized(VFX_TRUE);
    m_contentView->setColor(VCP_TEXT_NORMAL_TEXT_COLOR, VFX_COLOR_WHITE);
    VfxFontDesc magFont;
    magFont.size = VFX_FONT_DESC_VF_SIZE(VCP_TEXT_MAGNIFIER_FONT_SIZE);
    magFont.effect = m_effect->getEffectId();
    m_contentView->setFont(magFont);
    m_contentView->setAutoAnimate(VFX_TRUE);

    // mask
    VFX_OBJ_CREATE(m_magnifierMask, VfxFrame, this);
    m_magnifierMask->setSize(VCP_TEXT_MAGNIFIER_WIDTH, VCP_TEXT_MAGNIFIER_HEIGHT);
    m_magnifierMask->setImgContent(VfxImageSrc(VCP_IMG_TEXT_MAGNIFIER_MASK));
    m_magnifierMask->setAutoAnimate(VFX_TRUE);

    // cursor
    VFX_OBJ_CREATE(m_magnifierCursorFrame, VfxFrame, m_textFrame);
    m_magnifierCursorFrame->setAnchor(0.5f, 0.5f);
    m_magnifierCursorFrame->setPos(VCP_TEXT_MAGNIFIER_CONTENT_WIDTH / 2, VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT / 2);
    m_magnifierCursorFrame->setSize(VCP_TEXT_MAGNIFIER_CURSOR_WIDTH, VCP_TEXT_MAGNIFIER_CURSOR_HEIGHT);
    m_magnifierCursorFrame->setAutoAnimate(VFX_TRUE);
#if defined(__COSMOS_MMI_PACKAGE__)
    m_magnifierCursorFrame->setBgColor(VFX_COLOR_RES(VCP_COL_TEXT_EDITOR_CURSOR));
#else
    m_magnifierCursorFrame->setBgColor(VFX_COLOR_RED);
#endif
}


void VcpTextMagnifier::onDeinit(void)
{
    VfxControl::onDeinit();

    if (m_contentView)
    {
        VFX_OBJ_CLOSE(m_contentView);
    }

    if (m_textFrame)
    {
        VFX_OBJ_CLOSE(m_textFrame);
    }

    if (m_magnifierBackground)
    {
        VFX_OBJ_CLOSE(m_magnifierBackground);
    }

    if (m_magnifierMask)
    {
        VFX_OBJ_CLOSE(m_magnifierMask);
    }

    if (m_effect)
    {
        VFX_DELETE(m_effect);
    }
}

void VcpTextMagnifier::setPos(const VfxPoint &value)
{
    // adjust pos within screen area
    vrt_size_struct mainScreenSize;
    vrt_sys_get_main_screen_info(&mainScreenSize, NULL);
    VfxPoint pos = value;

    if (pos.x < 0)
    {
        pos.x = 0;
    }
    else if (pos.x > mainScreenSize.width)
    {
        pos.x = mainScreenSize.width;
    }

    if (pos.y < VCP_TEXT_MAGNIFIER_HEIGHT)
    {
        pos.y = VCP_TEXT_MAGNIFIER_HEIGHT;
    }
    else if (pos.y > mainScreenSize.height)
    {
        pos.y = mainScreenSize.height;
    }

    VfxControl::setPos(pos);
}


void VcpTextMagnifier::setText(VfxWChar *text, VcpRichTextFormat *format)
{
    // set all format size to magnifier font size
    if (format)
    {
        VcpRichTextFormat *pFormat = format;
        while (pFormat)
        {
            if (pFormat->getType() == VCP_RICH_TEXT_TYPE_TEXT || pFormat->getType() == VCP_RICH_TEXT_TYPE_HYPERLINK)
            {
                ((VcpRichText*)pFormat)->m_font.size = VFX_FONT_DESC_VF_SIZE(VCP_TEXT_MAGNIFIER_FONT_SIZE);
                ((VcpRichText*)pFormat)->setTextColor(VRT_COLOR_WHITE);
            }
            pFormat = pFormat->getNext();
        }
    }

    getContentView()->setText(text, VFX_FALSE, format);
}


void VcpTextMagnifier::setSelectTextMode(VfxBool value)
{
    if (value)
    {
        m_magnifierCursorFrame->setAutoAnimate(VFX_FALSE);
        m_contentView->setHighlight(0, 0);
        m_magnifierCursorFrame->setSize(0, 0);
        m_magnifierCursorFrame->setOpacity(0);
        m_magnifierCursorFrame->setBgColor(VFX_COLOR_TRANSPARENT);
        m_magnifierCursorFrame->setSize(VCP_TEXT_MAGNIFIER_MARK_CURSOR_WIDTH, VCP_TEXT_MAGNIFIER_CURSOR_HEIGHT + 8);
        m_magnifierCursorFrame->setAutoAnimate(VFX_TRUE);
        VfxAutoAnimate::initAnimateBegin();
        m_magnifierCursorFrame->setImgContent(VfxImageSrc(VCP_IMG_TEXT_MAGNIFIER_MARK_CURSOR));
        m_magnifierCursorFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_magnifierCursorFrame->setPos(VCP_TEXT_MAGNIFIER_CONTENT_WIDTH / 2, VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT / 2 + 1);
        m_magnifierCursorFrame->setOpacity(1.0);
        VfxAutoAnimate::initAnimateEnd();
    }
    else
    {
    #if defined(__COSMOS_MMI_PACKAGE__)
        m_magnifierCursorFrame->setBgColor(VFX_COLOR_RES(VCP_COL_TEXT_EDITOR_CURSOR));
    #else
        m_magnifierCursorFrame->setBgColor(VFX_COLOR_RED);
    #endif
        m_magnifierCursorFrame->setPos(VCP_TEXT_MAGNIFIER_CONTENT_WIDTH / 2, VCP_TEXT_MAGNIFIER_CONTENT_HEIGHT / 2);
        m_magnifierCursorFrame->setSize(VCP_TEXT_MAGNIFIER_CURSOR_WIDTH, VCP_TEXT_MAGNIFIER_CURSOR_HEIGHT);
        m_magnifierCursorFrame->setImgContent(VFX_IMAGE_SRC_NULL);
    }
}


#endif
