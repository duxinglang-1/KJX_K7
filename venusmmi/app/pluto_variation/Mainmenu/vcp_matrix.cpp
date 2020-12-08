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
 *  vcp_matrix_scr.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Internal UI componets of home screen application category
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

/* 
 * Code revise todo:
 * 1. Abstract each effect in a class
 * 2. Provide softkey-like signal when selecting an item by pen
 * 3. Make row/column count customizable (especially when number of items != rows * height -> not handled)
 */

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_VUI_MAINMENU__
extern "C"
{
    #include "MMIDataType.h"
    #include "MainmenuDef.h"
    #include "stdlib.h"
    #include "gui_touch_feedback.h"
	#include "CustMenuRes.h"
}

#include "vfx_uc_include.h"
#include "vcp_matrix.h"
#include "mainmenu/vapp_mm_scr.h"
#include "vdat_include.h"

#include "vfx_cpp_base.h"
#include "vfx_datatype.h"
#include "vfx_control.h"
#include "vfx_object.h"
#include "vfx_signal.h"
#include "vfx_basic_type.h"
#include "vfx_string.h"
#include "vfx_timer.h"
#include "vfx_animation.h"
#include "vfx_transform.h"
#include "vrt_datatype.h"
#include "vfx_auto_animate.h"
#include "vfx_sys_memory.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "vcp_squeeze_filter.h"
#include "vcp_jelly_filter.h"
#include "vcp_matrix_item.h"
#include "vfx_frame.h"
#include "vfx_input_event.h"
#include "vrt_canvas.h"
#include "gui_typedef.h"
#include "vcp_softkey.h"
#include "kal_public_api.h"
#include "kal_general_types.h"

/*
 * Porting Venus UI to Plutommi
 */ 
extern "C"
{
    // TODO: include the proper header files
    extern void GoBackHistory(void);
    extern void vadp_v2p_main_menu_style1_Highlight_handler(S32 hiliteid);
}

#define __MMI_VUI_MAIN_MENU_SUPPORT_FASTMOVE

/***************************************************************************** 
 * Class VcpSimpleMatrix
 *****************************************************************************/

VcpSimpleMatrix::VcpSimpleMatrix()
{
    
    m_numRows = DEFAULT_ROWS;
    m_numColumns = DEFAULT_COLUMNS;
    m_penState = PEN_STATE_UP;
    m_penHighlightChanged = VFX_FALSE;
    m_highlightEffectFinished = VFX_TRUE;
    m_fastMoveCount = -1;
    m_bubbleAnimIndex = 0;
    m_stopByKey = VFX_FALSE;

    VfxS32 i;
    for (i = 0; i < TOTAL_ITEMS; i++)
    {
        m_normalItems[i] = NULL;
    }
    
    m_penTimer = NULL;
    m_highlightTimer = NULL;
    m_highlightDrag = NULL;    
    m_squfilter = NULL;
    m_filterTimeline = NULL;
    m_jelfilter = NULL;

    m_isBlockInput = VFX_FALSE;
    
    m_highlightFrame = NULL;
    m_highlightItem = NULL;
    m_rotateTimeline2 = NULL;
    m_rotateTimeline1 = NULL;
    for (i = 0; i < TOTAL_ITEMS; i++)
    {
        m_dragPosTimeline[i] = NULL;
        m_dragTransformTimeline[i] = NULL;
    }
    m_opacityTimeline = NULL;
    for (i = 0; i < FAST_MOVE_QUEUE_SIZE; i++)
    {
        m_fastMoveTimelines[i] = NULL;
    }
    m_effectPosTimeline1 = NULL;
    m_effectPosTimeline2 = NULL;
    m_highlightIndex = -1;
}


void VcpSimpleMatrix::onInit()
{
    VfxControl::onInit();
    
    // Stop drag & move after switch  backlight.
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->m_signalBacklightSwitch.connect(this, &VcpSimpleMatrix::onPropertyBacklightSwitch); 
}


void VcpSimpleMatrix::onDeinit()
{
    VfxControl::onDeinit();
}


void VcpSimpleMatrix::updateHighlightItem()
{
    VfxPoint pt;
    MMI_IMG_ID menuId;
    MMI_IMG_ID imageID;

    m_highlightItem->setHidden(VFX_FALSE);
    menuId = mmi_res_get_mainmenu_id_by_img(m_normalItems[m_highlightIndex]->m_image->getResId(), MMI_RG_MM_IMG_VENUS1);
    imageID = mmi_res_get_mainmenu_img(menuId, MMI_RG_MM_IMG_VENUS1_HIGHLIGHT);
    m_highlightItem->m_image->setResId(imageID);
    m_highlightItem->updateString(m_normalItems[m_highlightIndex]->m_text->getString());
    if (m_penState != PEN_STATE_LONG_TAP)
    {
        m_normalItems[m_highlightIndex]->setHidden(VFX_TRUE);
        
    }
    // TODO: remove it: the following invalidate() are workaround that changing resid & string property doesn't invalidate the screen
    m_highlightFrame->invalidate();
    m_highlightItem->invalidate();
#ifdef VCP_SIMPLE_MATRIX_WITH_TITLE
    m_signalTitleChanged.emit(m_normalItems[m_highlightIndex]->m_text->getString());
#endif /* VCP_SIMPLE_MATRIX_WITH_TITLE */
}


void VcpSimpleMatrix::onFilterTimer(VfxTimer *source)
{
    VFX_UNUSED(source);
    m_highlightTimer->stop();
    updateHighlightItem();
}


void VcpSimpleMatrix::onFilterStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);

#ifdef VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON
    m_highlightItem->m_text->setHidden(VFX_FALSE);
#endif

    if (isCompleted)
    {
        m_highlightEffectFinished = VFX_TRUE;
        // Handler the event in queue of fast move.
        if (m_fastMoveCount != -1)
        {
            changeCurrentHighlightIndex(m_fastMoveQueue[m_fastMoveCount]);
        }
    }
    else
    {
        // Force set filtertiming if the timeline is not complete.
        m_highlightTimer->stop();
        updateHighlightItem();
        // TODO: force set value
        m_highlightFrame->setFilterTiming(0.9F);
        m_highlightFrame->setFilterTiming(1.0F);
    }
}


void VcpSimpleMatrix::onRotateStep2Stop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    if (isCompleted)
    {
        m_highlightFrame->setIsCached(VFX_TRUE);
        m_highlightFrame->setAutoAnimate(VFX_TRUE);
        m_highlightEffectFinished = VFX_TRUE;
        // Handler the event in queue of fast move.
        if (m_fastMoveCount != -1)
        {
            changeCurrentHighlightIndex(m_fastMoveQueue[m_fastMoveCount]);
        }
    }
    else
    {
        // Force set rz of transform and opacity if the timeline is not complete.
        VfxTransform frame_transform = m_highlightFrame->getTransform();
        // TODO: force set value
        frame_transform.data.affine.rz = VFX_DEG_TO_RAD(1);
        m_highlightFrame->setTransform(frame_transform);
        frame_transform.data.affine.rz = VFX_DEG_TO_RAD(0);
        m_highlightFrame->setTransform(frame_transform);
        m_highlightItem->setOpacity(1.0F);
    }
}


void VcpSimpleMatrix::onRotateStep1Stop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    // Change highlight icon in the middle of rotate transition effect.
    updateHighlightItem();
    if (isCompleted)
    {
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDuration(ROTATE_INTERVAL);
        m_highlightItem->setOpacity(1.0F);
        VfxAutoAnimate::commit();        
    }
}


void VcpSimpleMatrix::setupRotateEffect(VfxS32 old_index, VfxS32 x, VfxS32 y)
{
    VFX_UNUSED(x);
    VFX_UNUSED(y);
    VfxBool clockwise;

    if (old_index >= 0 && old_index < m_numRows * m_numColumns)
    {
        m_normalItems[old_index]->setHidden(VFX_FALSE);
    }

    if (m_highlightIndex == 0 && old_index == m_numRows * m_numColumns - 1)
    {
        clockwise = VFX_TRUE;
    }
    else if (m_highlightIndex == m_numRows * m_numColumns - 1 && old_index == 0)
    {
        clockwise = VFX_FALSE;
    }
    if (m_highlightIndex > old_index)
    {
        clockwise = VFX_TRUE;
    }
    else
    {
        clockwise = VFX_FALSE;
    }
    
    //updateHighlightItem();
    if (old_index != -1)
    {
        if (m_rotateTimeline1 == NULL)
        {
            VFX_OBJ_CREATE(m_rotateTimeline1, VfxFloatTimeline, this);
        }
        if (m_rotateTimeline2 == NULL)
        {
            VFX_OBJ_CREATE(m_rotateTimeline2, VfxFloatTimeline, this);
        }
        
        m_rotateTimeline1->setTarget(m_highlightFrame);
        m_rotateTimeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_RZ);
        m_rotateTimeline1->m_signalStopped.connect(this, &VcpSimpleMatrix::onRotateStep1Stop);  
        m_rotateTimeline1->setAutoReversed(VFX_FALSE);
        if (clockwise)
        {
            m_rotateTimeline1->setFromValue(VFX_DEG_TO_RAD(360));
            m_rotateTimeline1->setToValue(VFX_DEG_TO_RAD(180));
        }
        else
        {
            m_rotateTimeline1->setFromValue(VFX_DEG_TO_RAD(-360));
            m_rotateTimeline1->setToValue(VFX_DEG_TO_RAD(-180));        
        }
        m_rotateTimeline1->setDurationTime(ROTATE_INTERVAL);
        m_rotateTimeline1->setRepeatCount(1);
        m_highlightItem->setAutoAnimate(VFX_TRUE);
        m_highlightFrame->setAutoAnimate(VFX_TRUE);
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDuration(ROTATE_INTERVAL);
        m_highlightItem->setOpacity(0.5);
        VfxAutoAnimate::commit();
        m_rotateTimeline1->start();
        
        m_rotateTimeline2->setTarget(m_highlightFrame);
        m_rotateTimeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_RZ);
        m_rotateTimeline2->m_signalStopped.connect(this, &VcpSimpleMatrix::onRotateStep2Stop);  
        m_rotateTimeline2->setAutoReversed(VFX_FALSE);
        if (clockwise)
        {        
            m_rotateTimeline2->setFromValue(VFX_DEG_TO_RAD(180));
            m_rotateTimeline2->setToValue(VFX_DEG_TO_RAD(0));
        }
        else
        {
            m_rotateTimeline2->setFromValue(VFX_DEG_TO_RAD(-180));
            m_rotateTimeline2->setToValue(VFX_DEG_TO_RAD(0));        
        }
        m_rotateTimeline2->setDurationTime(ROTATE_INTERVAL);
        m_rotateTimeline2->setStartTime(ROTATE_INTERVAL);
        m_rotateTimeline2->setRepeatCount(1);
        m_rotateTimeline2->start();
    }
    else
    {
        updateHighlightItem();
    }
}


void VcpSimpleMatrix::onFastMoveStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);

    updateHighlightItem();
    addChildFrame(m_highlightFrame);
    if (isCompleted)
    {
        m_highlightEffectFinished = VFX_TRUE;
        // Handler the event in queue of fast move.
        if (m_fastMoveCount != -1)
        {
            changeCurrentHighlightIndex(m_fastMoveQueue[m_fastMoveCount]);
        }
        return;
    }
    else
    {
        return;
    }
}


void VcpSimpleMatrix::setupFastMoveTimelines(VfxS32 old_index, VfxS32 index)
{
    VfxS32 delayTime = 0, durationTime = 0;
    VfxS32 i;
    
    //Move normal items to the top position
    for (i = 0; i < m_numColumns * m_numRows; i++)
    {
        addChildFrame(m_normalItems[i]);
    }
    // Handle all the event in queue in one duration.
    if (m_highlightEffect == VCP_MATRIX_EFFECT_BUBBLE)
    {
        durationTime = BUBBLE_INTERVAL * 5 / (m_fastMoveCount + 1);
    }
    else if (m_highlightEffect == VCP_MATRIX_EFFECT_ROTATE)
    {
        durationTime = ROTATE_INTERVAL * 2 / (m_fastMoveCount + 1);
    }
    else if (m_highlightEffect == VCP_MATRIX_EFFECT_SQUEEZE)
    {
        durationTime = SQUEEZED_INTERVAL / (m_fastMoveCount + 1);
    }
    else if (m_highlightEffect == VCP_MATRIX_EFFECT_JELLY)
    {
        durationTime = SQUEEZED_INTERVAL / (m_fastMoveCount + 1);
    }
    else if (m_highlightEffect == VCP_MATRIX_EFFECT_JUMP)
    {
        durationTime = JELLY_INTERVAL / (m_fastMoveCount + 1);
    }
    else if (m_highlightEffect == VCP_MATRIX_EFFECT_NONE)
    {
        durationTime = SQUEEZED_INTERVAL / (m_fastMoveCount + 1);
    }
    for (i = 0; i <= m_fastMoveCount; i++)
    {
        VfxRect rect =getBounds();
        index = m_fastMoveQueue[i];
        VfxS32 width = rect.size.width / m_numColumns;
        VfxS32 height = (rect.size.height) / m_numRows;
        VfxS32 x = (rect.size.width - width * m_numColumns) / 2;
        VfxS32 y = (rect.size.height - height * m_numRows) / 2;
        VfxS32 row = index / m_numColumns;
        VfxS32 column = index % m_numColumns;
        x += (column) * width;
        y += (row) * height;
        VfxS32 x1 = x + width / 2;
        VfxS32 y1 = y + height / 2;
        if(row == m_numRows - 1) 
        {
            y1 -= HIGHLIGHT_IMAGE_OFFSET_Y;
        }
        else if(row == 0) 
        {
            y1 += HIGHLIGHT_IMAGE_OFFSET_Y;
        }
        
        if(column == m_numColumns - 1) 
        {
            x1 -= HIGHLIGHT_IMAGE_OFFSET_X;
        }
        else if(column == 0) 
        {
            x1 += HIGHLIGHT_IMAGE_OFFSET_X;
        }
        row = old_index / m_numColumns;
        column = old_index % m_numColumns;
        x = (rect.size.width - width * m_numColumns) / 2;
        y = (rect.size.height - height * m_numRows) / 2;
        x += (column) * width;
        y += (row) * height;
        VfxS32 x2 = x + width / 2;
        VfxS32 y2 = y + height / 2;
        if(row == m_numRows - 1) 
        {
            y2 -= HIGHLIGHT_IMAGE_OFFSET_Y;
        }
        else if(row == 0) 
        {
            y2 += HIGHLIGHT_IMAGE_OFFSET_Y;
        }
        
        if(column == m_numColumns - 1) 
        {
            x2 -= HIGHLIGHT_IMAGE_OFFSET_X;
        }
        else if(column == 0) 
        {
            x2 += HIGHLIGHT_IMAGE_OFFSET_X;
        }
        
        if (m_fastMoveTimelines[i] == NULL)
        {
            VFX_OBJ_CREATE(m_fastMoveTimelines[i], VfxPointTimeline, this);        
        }
        else
        {
            m_fastMoveTimelines[i]->m_signalStopped.disconnect(this, &VcpSimpleMatrix::onFastMoveStop);  
            m_fastMoveTimelines[i]->stop();
        }

        m_fastMoveTimelines[i]->setIsFromCurrent(VFX_TRUE);
        m_fastMoveTimelines[i]->setFromValue(VfxPoint(x2, y2));
        m_fastMoveTimelines[i]->setToValue(VfxPoint(x1, y1));
        m_fastMoveTimelines[i]->setDurationTime(durationTime);
        m_fastMoveTimelines[i]->setStartTime(delayTime);
        m_fastMoveTimelines[i]->setRepeatCount(1);
        m_fastMoveTimelines[i]->setTarget(m_highlightFrame);
        m_fastMoveTimelines[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
        if (i == m_fastMoveCount)
        {
            m_fastMoveTimelines[i]->m_signalStopped.connect(this, &VcpSimpleMatrix::onFastMoveStop);  
        }
        m_fastMoveTimelines[i]->start();
        delayTime += durationTime;
        old_index = index;
    }
    
}


void VcpSimpleMatrix::setupBubbleEffect(VfxS32 old_index, VfxS32 index, VfxS32 x, VfxS32 y)
{
    VFX_UNUSED(x);
    VFX_UNUSED(y);
    MMI_IMG_ID menuId;
    MMI_IMG_ID imageID;
    
    if (m_bubbleAnimIndex != 0)
    {
        m_highlightFrame->setImgContent(VfxImageSrc(MAIN_MENU_STYLE_HIGHLIGHT_IMG));
        
        m_highlightItem->setHidden(VFX_FALSE);
        
        menuId = mmi_res_get_mainmenu_id_by_img(m_normalItems[m_highlightIndex]->m_image->getResId(), MMI_RG_MM_IMG_VENUS1);
        imageID = mmi_res_get_mainmenu_img(menuId, MMI_RG_MM_IMG_VENUS1_HIGHLIGHT);
        m_highlightItem->m_image->setResId(imageID);
        m_highlightFrame->invalidate();
        m_highlightItem->invalidate();
        m_highlightItem->updateString(m_normalItems[index]->m_text->getString());
    }
    
    m_highlightFrame->setAutoAnimate(VFX_TRUE);
    m_highlightItem->setHidden(VFX_TRUE);
    
    if (old_index >= 0 && old_index < m_numRows * m_numColumns)
    {
        m_normalItems[old_index]->setHidden(VFX_FALSE);
    }
    if (old_index != -1)
    {
        if (m_highlightTimer)
        {
            VFX_OBJ_CLOSE(m_highlightTimer);
        }
        VFX_OBJ_CREATE(m_highlightTimer, VfxTimer, m_highlightFrame);
        m_highlightTimer->setDuration(BUBBLE_INTERVAL);
        m_highlightTimer->setStartDelay(0);
        m_highlightTimer->m_signalTick.connect(this, &VcpSimpleMatrix::onBubbleTimer);
        m_highlightTimer->start();
        m_bubbleAnimIndex = 0;
    }
    else
    {
        updateHighlightItem();
    }
}


void VcpSimpleMatrix::setupSqueezeEffect(VfxS32 old_index, VfxS32 index)
{
    VfxRect rect = getBounds();
    if (m_squfilter == NULL)
    {
        VFX_OBJ_CREATE(m_squfilter, VcpSqueezeFilter, this);
    }
    m_squfilter->m_imageWidth  = HIGHLIGHT_IMAGE_WIDTH;
    m_squfilter->m_imageHeight = HIGHLIGHT_IMAGE_HEIGHT;
    m_squfilter->m_anchorX = HIGHLIGHT_IMAGE_WIDTH >>1;
    m_squfilter->m_anchorY = HIGHLIGHT_IMAGE_HEIGHT >>1;
    
    m_squfilter->m_leftMargin = (HIGHLIGHT_IMAGE_WIDTH - HIGHLIGHT_IMAGE_OFFSET_X_GAP * 2) / 2;
    m_squfilter->m_rightMargin = m_squfilter->m_leftMargin;
    m_squfilter->m_topMargin = (HIGHLIGHT_IMAGE_HEIGHT - HIGHLIGHT_IMAGE_OFFSET_Y_GAP * 2) / 2;
    m_squfilter->m_bottomMargin = m_squfilter->m_topMargin;
    
    DirectionEnum dir = getEffectDirection(old_index, index);
   
    switch (dir)
    {
    case DIRECTION_RIGHTWARD:
        m_squfilter->m_transitionDirection = VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_RIGHTWARD;
        m_squfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_X_GAP;
        m_squfilter->m_travelLength = rect.size.width / m_numColumns - HIGHLIGHT_IMAGE_OFFSET_X;
        break;
        
    case DIRECTION_LEFTWARD:
        m_squfilter->m_transitionDirection = VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_LEFTWARD;
        m_squfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_X_GAP;
        m_squfilter->m_travelLength = rect.size.width / m_numColumns - HIGHLIGHT_IMAGE_OFFSET_X;
        break;

    case DIRECTION_UPWARD:
        m_squfilter->m_transitionDirection = VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_UPWARD;
        m_squfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_Y_GAP;
        m_squfilter->m_travelLength = rect.size.width / m_numColumns - HIGHLIGHT_IMAGE_OFFSET_Y;
        break;

    case DIRECTION_DOWNWARD:
        m_squfilter->m_transitionDirection = VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_DOWNWARD;
        m_squfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_Y_GAP;
        m_squfilter->m_travelLength = rect.size.width / m_numColumns - HIGHLIGHT_IMAGE_OFFSET_Y;
        break;
    }

    m_highlightFrame->setFilter(m_squfilter);
    
    if (m_filterTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_filterTimeline, VfxFloatTimeline, this);
    }
    else
    {
        m_filterTimeline->stop();
    }
    m_filterTimeline->setIsFromCurrent(VFX_FALSE);
    m_filterTimeline->setFromValue(0.0f);
    m_filterTimeline->setToValue(1.0f);
    m_filterTimeline->setDurationTime(SQUEEZED_INTERVAL);
    m_filterTimeline->setRepeatCount(1);//VFX_TIMELINE_REPEAT_INFINITE;
    m_filterTimeline->setTarget(m_highlightFrame);
    m_filterTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_filterTimeline->m_signalStopped.connect(this, &VcpSimpleMatrix::onFilterStop);  
    m_filterTimeline->start();

    // Set text hidden property here because previous m_filterTimeline stop callback may unset it
#if defined(VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON)
    m_highlightItem->m_text->setHidden(VFX_TRUE);
#endif
    
    if (m_highlightTimer)
    {
        m_highlightTimer->stop();
        VFX_OBJ_CLOSE(m_highlightTimer);
    }
    VFX_OBJ_CREATE(m_highlightTimer, VfxTimer, m_highlightFrame);
    m_highlightTimer->setDuration(0);
    m_highlightTimer->setStartDelay(SQUEEZED_INTERVAL / 2);
    m_highlightTimer->m_signalTick.connect(this, &VcpSimpleMatrix::onFilterTimer);
    m_highlightTimer->start();
}


void VcpSimpleMatrix::setupJumpEffect(VfxS32 old_index, VfxS32 index)
{
    VfxRect rect = getBounds();

    if (m_squfilter == NULL)
    {
        VFX_OBJ_CREATE(m_squfilter, VcpSqueezeFilter, this);
    }
    m_squfilter->m_imageWidth  = HIGHLIGHT_IMAGE_WIDTH;
	m_squfilter->m_imageHeight = HIGHLIGHT_IMAGE_HEIGHT;
	m_squfilter->m_anchorX = (VfxS32) (HIGHLIGHT_IMAGE_WIDTH * VCP_SIMPLE_MATRIX_JUMP_EFFECT_FACTOR);
	m_squfilter->m_anchorY = (VfxS32) (HIGHLIGHT_IMAGE_HEIGHT * VCP_SIMPLE_MATRIX_JUMP_EFFECT_FACTOR);

	m_squfilter->m_leftMargin = (HIGHLIGHT_IMAGE_WIDTH - HIGHLIGHT_IMAGE_OFFSET_X_GAP * 2) / 2;
	m_squfilter->m_rightMargin = m_squfilter->m_leftMargin;
	m_squfilter->m_topMargin = (HIGHLIGHT_IMAGE_HEIGHT - HIGHLIGHT_IMAGE_OFFSET_Y_GAP * 2) / 2;
	m_squfilter->m_bottomMargin = m_squfilter->m_topMargin;

    DirectionEnum dir = getEffectDirection(old_index, index);
    
    switch (dir)
    {
    case DIRECTION_RIGHTWARD:
        m_squfilter->m_transitionDirection = VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_RIGHTWARD;
        m_squfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_X_GAP;
        m_squfilter->m_travelLength = rect.size.width / m_numColumns - HIGHLIGHT_IMAGE_OFFSET_X;
        break;
        
    case DIRECTION_LEFTWARD:
        m_squfilter->m_transitionDirection = VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_LEFTWARD;
        m_squfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_X_GAP;
        m_squfilter->m_travelLength = rect.size.width / m_numColumns - HIGHLIGHT_IMAGE_OFFSET_X;
        break;
        
    case DIRECTION_UPWARD:
        m_squfilter->m_transitionDirection = VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_UPWARD;
        m_squfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_Y_GAP;
        m_squfilter->m_travelLength = rect.size.width / m_numColumns - HIGHLIGHT_IMAGE_OFFSET_Y;
        break;
        
    case DIRECTION_DOWNWARD:
        m_squfilter->m_transitionDirection = VCP_SQUEEZE_FILTER_TRANSITION_DIRECTION_DOWNWARD;
        m_squfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_Y_GAP;
        m_squfilter->m_travelLength = rect.size.width / m_numColumns - HIGHLIGHT_IMAGE_OFFSET_Y;
        break;
    }

    m_highlightFrame->setFilter(m_squfilter);
    
    if (m_filterTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_filterTimeline, VfxFloatTimeline, this);
    }
    m_filterTimeline->setIsFromCurrent(VFX_FALSE);
    m_filterTimeline->setFromValue(0.0f);
    
    m_filterTimeline->setToValue(1.0f);
    m_filterTimeline->setDurationTime(JELLY_INTERVAL);
    m_filterTimeline->setRepeatCount(1);//VFX_TIMELINE_REPEAT_INFINITE;
    m_filterTimeline->setTarget(m_highlightFrame);
    m_filterTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_filterTimeline->m_signalStopped.connect(this, &VcpSimpleMatrix::onFilterStop);  
    m_filterTimeline->start();

    // Set text hidden property here because previous m_filterTimeline stop callback may unset it
#if defined(VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON)
    m_highlightItem->m_text->setHidden(VFX_TRUE);
#endif
    
    if (m_highlightTimer)
    {
        VFX_OBJ_CLOSE(m_highlightTimer);
    }
    VFX_OBJ_CREATE(m_highlightTimer, VfxTimer, m_highlightFrame);
    m_highlightTimer->setDuration(0);
    m_highlightTimer->setStartDelay(JELLY_INTERVAL / 2);
    m_highlightTimer->m_signalTick.connect(this, &VcpSimpleMatrix::onFilterTimer);
    m_highlightTimer->start();
}


const vcp_jelly_filter_key_frame_setting_struct jelly_key_frame_setting_left[] =
{
    /* {effect_func_p,	squeeze_point, squeeze_point_2, anchor, startLevel, endLevel} */
    /* elegant small jump */
    /*
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.6), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH*0.9), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_Y, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.55), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT*0), (VfxFloat)0.2, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.4), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH*0.4), (VfxFloat)0.4, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    */
    /*	super twist */
    /*
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.6), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH), (VfxFloat)0.7, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_Y, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.55), VCP_JELLY_FILTER_NULL_VALUE, 0, (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.4), VCP_JELLY_FILTER_NULL_VALUE, 0, (VfxFloat)0.6, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_Y, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.55), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.55), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.55), (VfxFloat)0.7, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    */
    /* jelly drift */
    /*
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.1), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.9), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.3), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.7), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.5), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.5), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.7), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.3), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    */
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, (VfxS32)(VcpSimpleMatrix::HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.7, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    //{VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_Y, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, (VfxS32)(VcpSimpleMatrix::HIGHLIGHT_IMAGE_HEIGHT* 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
};

const vcp_jelly_filter_key_frame_setting_struct jelly_key_frame_setting_right[] =
{
    /* {effect_func_p,	squeeze_point, squeeze_point_2, anchor, startLevel, endLevel} */
    /* elegant small jump */
    /*
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.6), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH*0.1), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_Y, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.45), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT*0), (VfxFloat)0.2, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.4), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH*0.6), (VfxFloat)0.4, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    */
    /*
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.6), (HIGHLIGHT_IMAGE_HEIGHT * 0.2), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH*0.1), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_Y, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.45), (HIGHLIGHT_IMAGE_WIDTH * 0.45), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT*0), (VfxFloat)0.2, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.4), (HIGHLIGHT_IMAGE_HEIGHT * 0.6), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH*0.6), (VfxFloat)0.4, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    */
    /* jelly drift */
    /*
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.1), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.9), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.3), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.7), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.5), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.5), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.7), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.3), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    */
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, (VfxS32)(VcpSimpleMatrix::HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.7, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    //{VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_Y, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, (VfxS32)(VcpSimpleMatrix::HIGHLIGHT_IMAGE_HEIGHT* 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
};

const vcp_jelly_filter_key_frame_setting_struct jelly_key_frame_setting_down[] =
{
    /* {effect_func_p,	squeeze_point, squeeze_point_2, anchor, startLevel, endLevel} */
    /* elegant small jump */
    /*
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_Y, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.6), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT*0.1), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.45), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH*0), (VfxFloat)0.2, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_Y, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.4), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT*0.6), (VfxFloat)0.4, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    */
    /* jelly drift */
    /*
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.1), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.9), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.3), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.7), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.5), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.5), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.7), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.3), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    */
    //{VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, (VfxS32)(VcpSimpleMatrix::HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_Y, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, (VfxS32)(VcpSimpleMatrix::HIGHLIGHT_IMAGE_HEIGHT* 0.5), (VfxFloat)0.7, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
};

const vcp_jelly_filter_key_frame_setting_struct jelly_key_frame_setting_up[] =
{
    /* {effect_func_p,	squeeze_point, squeeze_point_2, anchor, startLevel, endLevel} */
    /* elegant small jump */
    /*
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_Y, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.6), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT*0.9), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.55), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH*0), (VfxFloat)0.2, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_SQUEEZE_IN_Y, (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.4), VCP_JELLY_FILTER_NULL_VALUE, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT*0.4), (VfxFloat)0.4, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    */
    /* jelly drift */
    /*
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.1), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.9), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.3), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.7), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.5), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.5), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.7), (VfxS32)(HIGHLIGHT_IMAGE_HEIGHT * 0.3), (VfxS32)(HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    */
    //{VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_X, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, (VfxS32)(VcpSimpleMatrix::HIGHLIGHT_IMAGE_WIDTH * 0.5), (VfxFloat)0.5, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
    {VCP_JELLY_FILTER_FUNCTYPE_TYPE_TWO_SQUEEZE_IN_Y, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, VCP_JELLY_FILTER_CONTINUED_SQUEEZE, (VfxS32)(VcpSimpleMatrix::HIGHLIGHT_IMAGE_HEIGHT* 0.5), (VfxFloat)0.7, VCP_JELLY_FILTER_NULL_LEVEL, VCP_JELLY_FILTER_NULL_LEVEL},
};


void VcpSimpleMatrix::setupJellyEffect(VfxS32 old_index, VfxS32 index)
{
    
    if (m_jelfilter == NULL)
    {
        VFX_OBJ_CREATE(m_jelfilter, VcpJellyFilter, this);
    }
    m_jelfilter->m_imageWidth  = HIGHLIGHT_IMAGE_WIDTH;
    m_jelfilter->m_imageHeight = HIGHLIGHT_IMAGE_HEIGHT;
    //m_jelfilter->m_keyFrameSettingArray = jelly_key_frame_setting;
    //m_jelfilter->m_keyFrameCount = sizeof(jelly_key_frame_setting) / sizeof(vcp_jelly_filter_key_frame_setting_struct);

    DirectionEnum dir = getEffectDirection(old_index, index);
    
    switch (dir)
    {
    case DIRECTION_RIGHTWARD:
        m_jelfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_X_GAP;
        m_jelfilter->m_transitionDirection = VCP_JELLY_FILTER_TRANSITION_DIRECTION_RIGHTWARD;
        m_jelfilter->m_keyFrameSettingArray = jelly_key_frame_setting_right;
        m_jelfilter->m_keyFrameCount = sizeof(jelly_key_frame_setting_right) / sizeof(vcp_jelly_filter_key_frame_setting_struct);
        break;
        
    case DIRECTION_LEFTWARD:
        m_jelfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_X_GAP;
        m_jelfilter->m_transitionDirection = VCP_JELLY_FILTER_TRANSITION_DIRECTION_LEFTWARD;
        m_jelfilter->m_keyFrameSettingArray = jelly_key_frame_setting_left;
        m_jelfilter->m_keyFrameCount = sizeof(jelly_key_frame_setting_left) / sizeof(vcp_jelly_filter_key_frame_setting_struct);
        break;
        
    case DIRECTION_UPWARD:
        m_jelfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_Y_GAP;
        m_jelfilter->m_transitionDirection = VCP_JELLY_FILTER_TRANSITION_DIRECTION_UPWARD;
        m_jelfilter->m_keyFrameSettingArray = jelly_key_frame_setting_up;
        m_jelfilter->m_keyFrameCount = sizeof(jelly_key_frame_setting_up) / sizeof(vcp_jelly_filter_key_frame_setting_struct);
        break;
        
    case DIRECTION_DOWNWARD:
        m_jelfilter->m_warpRadius = HIGHLIGHT_IMAGE_OFFSET_Y_GAP;
        m_jelfilter->m_transitionDirection = VCP_JELLY_FILTER_TRANSITION_DIRECTION_DOWNWARD;
        m_jelfilter->m_keyFrameSettingArray = jelly_key_frame_setting_down;
        m_jelfilter->m_keyFrameCount = sizeof(jelly_key_frame_setting_down) / sizeof(vcp_jelly_filter_key_frame_setting_struct);
        break;
    }
    
    m_highlightFrame->setFilter(m_jelfilter);
    m_highlightFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    
    if (m_filterTimeline == NULL)
    {
        VFX_OBJ_CREATE(m_filterTimeline, VfxFloatTimeline, this);
    }
    m_filterTimeline->setIsFromCurrent(VFX_FALSE);
    m_filterTimeline->setFromValue(0.0f);
    m_filterTimeline->setToValue(1.0f);
    m_filterTimeline->setDurationTime(SQUEEZED_INTERVAL);
    m_filterTimeline->setRepeatCount(1);//VFX_TIMELINE_REPEAT_INFINITE;
    m_filterTimeline->setTarget(m_highlightFrame);
    m_filterTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_FILTER_TIMING);
    m_filterTimeline->m_signalStopped.connect(this, &VcpSimpleMatrix::onFilterStop);  
    m_filterTimeline->start();

    // Set text hidden property here because previous m_filterTimeline stop callback may unset it
#if defined(VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON)
    m_highlightItem->m_text->setHidden(VFX_TRUE);
#endif

    if (m_highlightTimer)
    {
        VFX_OBJ_CLOSE(m_highlightTimer);
    }
    VFX_OBJ_CREATE(m_highlightTimer, VfxTimer, m_highlightFrame);
    m_highlightTimer->setDuration(SQUEEZED_INTERVAL / 2);
    m_highlightTimer->setStartDelay(0);
    m_highlightTimer->m_signalTick.connect(this, &VcpSimpleMatrix::onFilterTimer);
    m_highlightTimer->start();
}


VfxS32 VcpSimpleMatrix::getCurrentHighlightIndex()
{
    return m_highlightIndex;
}


void VcpSimpleMatrix::changeCurrentHighlightIndex(VfxS32 highlightIndex)
{
    VfxS32 x, y, width, height, x2, y2, x1, y1; 
    VfxS32 old_index = m_highlightIndex;
    VfxS32 row, column, oldRow, oldColmun;
    VfxRect rect =getBounds();
    
    m_highlightIndex = highlightIndex;
    width = rect.size.width / m_numColumns;
    height = (rect.size.height) / m_numRows;
    x = (rect.size.width - width * m_numColumns) / 2;
    y = (rect.size.height - height * m_numRows) / 2;
    row = highlightIndex / m_numColumns;
    column = highlightIndex % m_numColumns;
    oldRow = old_index / m_numColumns;
    oldColmun = old_index % m_numColumns;
    x += (column) * width;
    y += (row) * height;
    x1 = x + width / 2;
    y1 = y + height / 2;
    if(row == m_numRows - 1) 
    {
        y1 -= HIGHLIGHT_IMAGE_OFFSET_Y;
    }
    else if(row == 0) 
    {
        y1 += HIGHLIGHT_IMAGE_OFFSET_Y;
    }
    
    if(column == m_numColumns - 1) 
    {
        x1 -= HIGHLIGHT_IMAGE_OFFSET_X;
    }
    else if(column == 0) 
    {
        x1 += HIGHLIGHT_IMAGE_OFFSET_X;
    }
    
    x = (rect.size.width - width * m_numColumns) / 2;
    y = (rect.size.height - height * m_numRows) / 2;
    x += (oldColmun) * width;
    y += (oldRow) * height;
    x2 = x + width / 2;
    y2 = y + height / 2;
    if(oldRow == m_numRows - 1) 
    {
        y2 -= HIGHLIGHT_IMAGE_OFFSET_Y;
    }
    else if(oldRow == 0) 
    {
        y2 += HIGHLIGHT_IMAGE_OFFSET_Y;
    }
    
    if(oldColmun == m_numColumns - 1) 
    {
        x2 -= HIGHLIGHT_IMAGE_OFFSET_X;
    }
    else if(oldColmun == 0) 
    {
        x2 += HIGHLIGHT_IMAGE_OFFSET_X;
    }
    
    
    if (m_penTimer && old_index != m_highlightIndex)
    {
        m_penTimer->stop();
    }
#ifdef VCP_SIMPLE_MATRIX_WITH_TITLE
    if (old_index != -1)
    {
        m_signalTitleChanged.emit(m_normalItems[highlightIndex]->m_text->getString());
    }
#endif /* VCP_SIMPLE_MATRIX_WITH_TITLE */
    
    if (m_penState == PEN_STATE_LONG_TAP)
    {
        m_highlightFrame->setPos(VfxPoint(x1, y1));
        updateHighlightItem();
    }
    else
    {
        if (old_index == -1)
        {
            m_highlightFrame->setPos(VfxPoint(x1, y1));
            m_highlightEffectFinished = VFX_TRUE;
        }
        else if (m_highlightTriggeredByPen == VFX_TRUE)
        {
            m_highlightFrame->setAutoAnimate(VFX_FALSE);
            if (m_highlightTimer)
            {
                m_highlightTimer->stop();
                m_highlightFrame->setImgContent(VfxImageSrc(MAIN_MENU_STYLE_HIGHLIGHT_IMG));
                m_highlightItem->setHidden(VFX_FALSE);
                m_highlightFrame->setOpacity(1.0F);
            }
            if (m_rotateTimeline1 || m_rotateTimeline2)
            {
                if (m_rotateTimeline1)
                {
                    m_rotateTimeline1->stop();
                }
                if (m_rotateTimeline2)
                {
                    m_rotateTimeline2->stop();
                }
                VfxTransform frame_transform = m_highlightFrame->getTransform();
                frame_transform.data.affine.rz = VFX_DEG_TO_RAD(0);
                m_highlightFrame->setTransform(frame_transform);
                m_highlightItem->setOpacity(1.0F);
            }
            if (m_filterTimeline)
            {
                m_filterTimeline->stop();
                m_highlightFrame->setFilterTiming(1.0F);
            #ifdef VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON
                m_highlightItem->m_text->setHidden(VFX_FALSE);
            #endif
            }
            for (VfxS32 i = 0; i < FAST_MOVE_QUEUE_SIZE; i++)
            {
                if (m_fastMoveTimelines[i])
                {
                    m_fastMoveTimelines[i]->stop();
                }
            }
            if (m_effectPosTimeline1)
            {
                m_effectPosTimeline1->stop();
            }
            if (m_effectPosTimeline2)
            {
                m_effectPosTimeline2->stop();
            }
            
            if (old_index >= 0 && old_index < m_numRows * m_numColumns)
            {
                m_normalItems[old_index]->setHidden(VFX_FALSE);
            }
            // TODO: force set value
            m_highlightFrame->setPos(VfxPoint(x1 - 1, y1));
            m_highlightFrame->setPos(VfxPoint(x1, y1));
            updateHighlightItem();
            m_highlightFrame->setAutoAnimate(VFX_TRUE);
            m_highlightEffectFinished = VFX_TRUE;
        }
        else if (m_fastMoveCount != -1 && m_fastMoveCount != 0)
        {
            m_highlightEffectFinished = VFX_FALSE;
            m_normalItems[old_index]->setHidden(VFX_FALSE);
            m_highlightItem->setHidden(VFX_TRUE);
            setupFastMoveTimelines(old_index, highlightIndex);
        }
        else if (m_highlightEffect == VCP_MATRIX_EFFECT_BUBBLE)
        {
            m_highlightEffectFinished = VFX_FALSE;
            setupPosTimeline(row, oldRow, column, oldColmun, x1, y1, x2, y2);
            setupBubbleEffect(old_index, highlightIndex, x1, y1);
        }
        else if (m_highlightEffect == VCP_MATRIX_EFFECT_ROTATE)
        {
            if (!m_highlightEffectFinished)
            {
                updateHighlightItem();
            }
            m_highlightEffectFinished = VFX_FALSE;
            setupPosTimeline(row, oldRow, column, oldColmun, x1, y1, x2, y2);
            setupRotateEffect(old_index, x1, y1);            
        }
        else if (m_highlightEffect == VCP_MATRIX_EFFECT_SQUEEZE)
        {
            if (!m_highlightEffectFinished)
            {
                updateHighlightItem();
            }
            m_highlightEffectFinished = VFX_FALSE;
            if (old_index >= 0 && old_index < m_numRows * m_numColumns)
            {
                m_normalItems[old_index]->setHidden(VFX_FALSE);
            }
            setupPosTimeline(row, oldRow, column, oldColmun, x1, y1, x2, y2);
            setupSqueezeEffect(old_index, highlightIndex);
        }
        else if (m_highlightEffect == VCP_MATRIX_EFFECT_JUMP)
        {
            if (!m_highlightEffectFinished)
            {
                updateHighlightItem();
            }
            m_highlightEffectFinished = VFX_FALSE;
            if (old_index >= 0 && old_index < m_numRows * m_numColumns)
            {
                m_normalItems[old_index]->setHidden(VFX_FALSE);
            }
            setupPosTimeline(row, oldRow, column, oldColmun, x1, y1, x2, y2);
            setupJumpEffect(old_index, highlightIndex);
        }
        else if (m_highlightEffect == VCP_MATRIX_EFFECT_JELLY)
        {
            if (!m_highlightEffectFinished)
            {
                updateHighlightItem();
            }
            m_highlightEffectFinished = VFX_FALSE;
            if (old_index >= 0 && old_index < m_numRows * m_numColumns)
            {
                m_normalItems[old_index]->setHidden(VFX_FALSE);
            }
            setupPosTimeline(row, oldRow, column, oldColmun, x1, y1, x2, y2);
            setupJellyEffect(old_index, highlightIndex);
        }
        else if (m_highlightEffect == VCP_MATRIX_EFFECT_NONE)
        {
            if (!m_highlightEffectFinished)
            {
                updateHighlightItem();
            }
            if (old_index >= 0 && old_index < m_numRows * m_numColumns)
            {
                m_normalItems[old_index]->setHidden(VFX_FALSE);
            }
            setupPosTimeline(row, oldRow, column, oldColmun, x1, y1, x2, y2);
            m_highlightEffectFinished = VFX_TRUE;
        }
        else
        {
            if (old_index >= 0 && old_index < m_numRows * m_numColumns)
            {
                m_normalItems[old_index]->setHidden(VFX_FALSE);
            }
            setupPosTimeline(row, oldRow, column, oldColmun, x1, y1, x2, y2);
            updateHighlightItem();
            m_highlightEffectFinished = VFX_TRUE;
        }
        m_fastMoveCount = -1;
        
    }
    vadp_v2p_main_menu_style1_Highlight_handler(m_menuOrder[highlightIndex]);
    m_highlightTriggeredByPen = VFX_FALSE;

    this->invalidate();
    return;
}


void VcpSimpleMatrix::onTimelineCleanup(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if (isCompleted)
    {
        // TODO: workaround framework issue that timeline stop callback will be invoked twice; remove it in w09.32
        VFX_OBJ_CLOSE(timeline);
    }
}


void VcpSimpleMatrix::onNoneEffectStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    VFX_UNUSED(timeline);
    VFX_UNUSED(isCompleted);

    updateHighlightItem();
}


void VcpSimpleMatrix::setupPosTimeline(VfxS32 row, VfxS32 oldRow, VfxS32 column, VfxS32 oldColumn, VfxS32 x1, VfxS32 y1, VfxS32 x2, VfxS32 y2)
{
    VfxS32 duration;
    VfxS32 newx1, newy1, newx2, newy2;

    switch(m_highlightEffect)
    {
        case VCP_MATRIX_EFFECT_BUBBLE:
            duration = BUBBLE_INTERVAL * 5 / 2;
            break;

        case VCP_MATRIX_EFFECT_ROTATE:
            duration = ROTATE_INTERVAL;
            break;

        case VCP_MATRIX_EFFECT_SQUEEZE:
            duration = SQUEEZED_INTERVAL / 2;
            break;

        case VCP_MATRIX_EFFECT_JUMP:
            duration = JELLY_INTERVAL / 2;
            break;

        case VCP_MATRIX_EFFECT_JELLY:
            duration = SQUEEZED_INTERVAL / 2;
            break;

        case VCP_MATRIX_EFFECT_NONE:
            duration = NONE_EFFECT_INTERVAL;
            break;

        default:
            duration = NONE_EFFECT_INTERVAL;
            break;
    }
    
    if (column == 0 && oldColumn == m_numColumns - 1)
    {
        newx1 = x1 - HIGHLIGHT_ICON_WIDTH / 2;
        newx2 = x2 + HIGHLIGHT_ICON_WIDTH / 2;
        newy2 = y2;
        newy1 = y1;
    }
    else if (oldColumn == 0 && column == m_numColumns - 1)
    {
        newx1 = x1 + HIGHLIGHT_ICON_WIDTH / 2;
        newx2 = x2 - HIGHLIGHT_ICON_WIDTH / 2;
        newy2 = y2;
        newy1 = y1;
    }
    else if (oldRow == 0 && row == m_numRows - 1)
    {
        newx1 = x1;
        newx2 = x2;
        newy2 = y2 - HIGHLIGHT_ICON_HEIGHT / 2;
        newy1 = y1 + HIGHLIGHT_ICON_HEIGHT / 2;
        
    }
    else if (row == 0 && oldRow == m_numRows - 1)
    {
        newx1 = x1;
        newx2 = x2;
        newy2 = y2 + HIGHLIGHT_ICON_HEIGHT / 2;
        newy1 = y1 - HIGHLIGHT_ICON_HEIGHT / 2;
    }
    else
    {
        newx1 = x1 + (x2 - x1) / 2;
        newx2 = newx1;
        newy1 = y1 + (y2 - y1) / 2;
        newy2 = newy1;
    }
    if (m_effectPosTimeline1 == NULL)
    {
        VFX_OBJ_CREATE(m_effectPosTimeline1, VfxPointTimeline, this);        
    }
    else
    {
        m_effectPosTimeline1->stop();
    }
    m_effectPosTimeline1->setIsFromCurrent(VFX_FALSE);
    m_effectPosTimeline1->setFromValue(VfxPoint(x2, y2));
    m_effectPosTimeline1->setToValue(VfxPoint(newx2, newy2));
    m_effectPosTimeline1->setDurationTime(duration);
    m_effectPosTimeline1->setStartTime(0);
    m_effectPosTimeline1->setRepeatCount(1);
    m_effectPosTimeline1->setTarget(m_highlightFrame);
    m_effectPosTimeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
    if (m_highlightEffect == VCP_MATRIX_EFFECT_NONE)
    {
        m_effectPosTimeline1->m_signalStopped.connect(this, &VcpSimpleMatrix::onNoneEffectStop);  
    }
    m_effectPosTimeline1->start();
    
    if (m_effectPosTimeline2 == NULL)
    {
        VFX_OBJ_CREATE(m_effectPosTimeline2, VfxPointTimeline, this);        
    }
    else
    {
        m_effectPosTimeline2->stop();
    }
    m_effectPosTimeline2->setIsFromCurrent(VFX_FALSE);
    m_effectPosTimeline2->setFromValue(VfxPoint(newx1, newy1));
    m_effectPosTimeline2->setToValue(VfxPoint(x1, y1));
    m_effectPosTimeline2->setDurationTime(duration);
    m_effectPosTimeline2->setStartTime(duration);
    m_effectPosTimeline2->setRepeatCount(1);
    m_effectPosTimeline2->setTarget(m_highlightFrame);
    m_effectPosTimeline2->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS);
    m_effectPosTimeline2->start();

    m_highlightFrame->setPos(VfxPoint(x1, y1));
}


void VcpSimpleMatrix::setRowsColumns(VfxS32 numRows, VfxS32 numColumns)
{
    VfxS32 i, count; 
    
    m_numRows = numRows;
    m_numColumns = numColumns;
    count = m_numRows * m_numColumns;
    if (count > TOTAL_ITEMS)
    {
        count = TOTAL_ITEMS;
    }
    if (m_normalItems[0] == NULL)
    {
        // Create a image frame
        for (i = 0; i < count; i++)
        {
            VFX_OBJ_CREATE(m_normalItems[i], VcpSimpleMatrixIcon, this);
            m_normalItems[i]->setAnchor(VfxFPoint(0.5F, 0.5F));
        #ifndef VCP_MATRIX_DISABLE_ITEM_FRAME_CACHE
            m_normalItems[i]->setIsCached(VFX_TRUE);
        #endif
        #ifndef VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON  
            m_normalItems[i]->m_text->setHidden(VFX_TRUE);
        #endif
            m_normalItems[i]->setAutoAnimate(VFX_TRUE);
        }
    }
    if (m_highlightFrame == NULL)
    {
        VFX_OBJ_CREATE(m_highlightFrame, VfxFrame, this);
        m_highlightFrame->setAnchor(VfxFPoint(0.5F, 0.5F));
		m_highlightFrame->setImgContent(VfxImageSrc(MAIN_MENU_STYLE_HIGHLIGHT_IMG));
        m_highlightFrame->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(HIGHLIGHT_IMAGE_WIDTH, HIGHLIGHT_IMAGE_HEIGHT)));
        m_highlightFrame->setIsCached(VFX_TRUE);
		m_highlightFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
        VFX_OBJ_CREATE(m_highlightItem, VcpSimpleMatrixIcon, m_highlightFrame);
#ifndef VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON  
        m_highlightItem->m_text->setHidden(VFX_TRUE);
#endif
        m_highlightItem->setAnchor(VfxFPoint(0.5F, 0.5F));
        m_highlightItem->setIsCached(VFX_TRUE);
        m_highlightItem->m_isHighlighted = VFX_TRUE;
        m_highlightItem->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(HIGHLIGHT_ICON_WIDTH, HIGHLIGHT_ICON_HEIGHT)));
        m_highlightFrame->setAutoAnimate(VFX_TRUE);
        m_highlightItem->setAutoAnimate(VFX_TRUE);
        m_highlightItem->setPos(VfxPoint(HIGHLIGHT_ICON_X, HIGHLIGHT_ICON_Y));
        
    }
    layoutItems();
}


void VcpSimpleMatrix::setItemImage(VfxS32 rows, VfxS32 columns, VfxImageSrc &image)
{
    VfxS32 index;
    MMI_IMG_ID menuId;
    MMI_IMG_ID imageID;
    
    index = rows * m_numColumns + columns;
    if (rows >= m_numRows || columns >= m_numColumns)
    {
        return;
    }
    
	m_normalItems[index]->m_image->setImgContent(image);
    
    if (index == m_highlightIndex)
    {
        if (image.isNull() == VFX_FALSE)
        {
            
            menuId = mmi_res_get_mainmenu_id_by_img(image.getResId(), MMI_RG_MM_IMG_VENUS1);
            imageID = mmi_res_get_mainmenu_img(menuId, MMI_RG_MM_IMG_VENUS1_HIGHLIGHT);
			m_highlightItem->m_image->setImgContent(VfxImageSrc(imageID));
            m_highlightFrame->invalidate();
            m_highlightItem->invalidate();
            m_highlightItem->updateString(m_normalItems[index]->m_text->getString());
        }
        m_normalItems[index]->setHidden(VFX_TRUE);
    }
} 


void VcpSimpleMatrix:: setItemString(VfxS32 rows, VfxS32 columns, const VfxWString &text)
{
    VfxS32 index;
    
    index = rows * m_numColumns + columns;
    if (rows >= m_numRows || columns >= m_numColumns)
    {
        return;
    }
    m_normalItems[index]->updateString(text);
    if (index == m_highlightIndex)
    {
        m_highlightItem->updateString(m_normalItems[index]->m_text->getString());
    #ifdef VCP_SIMPLE_MATRIX_WITH_TITLE
        m_signalTitleChangedNoRedraw.emit(m_normalItems[index]->m_text->getString());
    #endif /* VCP_SIMPLE_MATRIX_WITH_TITLE */
    }
}


void VcpSimpleMatrix::layoutItems()
{
    VfxS32 i, j, k = 0;
    VfxS32 x, y, width, height;
    VfxRect rect = getBounds();
    
    width = rect.size.width / m_numColumns;
    height = (rect.size.height) / m_numRows;
    x = (rect.size.width - width * m_numColumns) / 2;
    y = (rect.size.height - height * m_numRows) / 2;
    for (i = 0; i < m_numRows; i++)
    {
        for(j = 0; j < m_numColumns; j++)
        {
            m_normalItems[k]->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(NORMAL_ICON_WIDTH, NORMAL_ICON_HEIGHT)));
            m_normalItems[k]->m_x = x + width / 2;
            m_normalItems[k]->m_y = y + height / 2 - NORMAL_IMAGE_Y;
            m_normalItems[k]->setPos(VfxPoint(x + width / 2, y + height / 2 - NORMAL_IMAGE_Y));
            x = x + width;
            k++;
            if (k >= TOTAL_ITEMS)
            {
                break;
            }
        }
        x = (rect.size.width - width * m_numColumns) / 2;
        y = y + height;
    }
}


VfxBool VcpSimpleMatrix::stopDragMove()
{
    m_penState = PEN_STATE_UP;
    MMI_IMG_ID menuId;
    MMI_IMG_ID imageID;
    
    VfxS32 i; 
    VfxTransform frame_transform;
    
    if (m_highlightDrag)
    {   
        m_dragIndex = m_numColumns * m_numRows;
        VFX_OBJ_CLOSE(m_highlightDrag);
    }
    
    if (m_opacityTimeline)
    {
        m_opacityTimeline->stop();
        VFX_OBJ_CLOSE(m_opacityTimeline);
    }
    
    for(i = 0; i < m_numColumns * m_numRows; i++)
    {
        if (m_dragPosTimeline[i])
        {
            m_dragPosTimeline[i]->stop();
            VFX_OBJ_CLOSE(m_dragPosTimeline[i]);
        }
    #ifdef VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE
        if (m_dragTransformTimeline[i])
        {
            m_dragTransformTimeline[i]->stop();
            VFX_OBJ_CLOSE(m_dragTransformTimeline[i]);
        }
    #endif
    }

    // Disable auto animation temporarily
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    
    for(i = 0; i < m_numColumns * m_numRows; i++)
    {
        m_normalItems[i]->setAnchor(VfxFPoint(0.5F, 0.5F)); // reset the anchor point
    #ifdef VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE
        VfxTransform frame_transform = m_normalItems[i]->getTransform();
        frame_transform = m_normalItems[i]->getTransform();
        frame_transform.data.affine.rz = VFX_DEG_TO_RAD(0);
        m_normalItems[i]->setTransform(frame_transform);
    #endif
    }

    layoutItems();

    // the highlighted item was scaled, reset to normal
    frame_transform = m_normalItems[m_highlightIndex]->getTransform();
    frame_transform.data.affine.sx = 1.0F;
    frame_transform.data.affine.sy = 1.0F;
    m_normalItems[m_highlightIndex]->setTransform(frame_transform);
    m_normalItems[m_highlightIndex]->setHidden(VFX_TRUE); // overlapped with highlighted frame

    VfxAutoAnimate::commit();

    // Keep the auto animation of enlarging the highlight frame
    frame_transform = m_highlightFrame->getTransform();
    frame_transform.data.affine.sx = 1.0F;
    frame_transform.data.affine.sy = 1.0F;
    m_highlightFrame->setTransform(frame_transform);
    m_highlightFrame->setHidden(VFX_FALSE);
    m_highlightFrame->setOpacity(1.0F);    
    addChildFrame(m_highlightFrame); // Move to top
    
    menuId = mmi_res_get_mainmenu_id_by_img(m_normalItems[m_highlightIndex]->m_image->getResId(), MMI_RG_MM_IMG_VENUS1);
    imageID = mmi_res_get_mainmenu_img(menuId, MMI_RG_MM_IMG_VENUS1_HIGHLIGHT);
    m_highlightItem->m_image->setResId(imageID);
        

    m_signalSoftkeyStateChanged.emit(VCP_MATRIX_SOFTKEY_ENABLED);
    
    for (i = 0; i < TOTAL_ITEMS; i++)
    {
        m_menuPreOrder[i] = m_menuOrder[i];
    }
    
    return VFX_TRUE;
}


void VcpSimpleMatrix::restoreOrder()
{
    VcpSimpleMatrixIcon     *oldItems[TOTAL_ITEMS];
    VfxS32 i, j;

    for (i = 0; i < TOTAL_ITEMS; i++)
    {
        j = m_menuOrder[i];
        oldItems[j] = m_normalItems[i];
    }

    for (i = 0; i < TOTAL_ITEMS; i++)
    {
        j = m_menuPreOrder[i];
        m_normalItems[i] = oldItems[j];
    }
    for (i = 0; i < TOTAL_ITEMS; i++)
    {
        m_menuOrder[i] = m_menuPreOrder[i];
    }
    m_highlightItem->updateString(m_normalItems[m_highlightIndex]->m_text->getString());
#ifdef VCP_SIMPLE_MATRIX_WITH_TITLE
    m_signalTitleChanged.emit(m_normalItems[m_highlightIndex]->m_text->getString());
#endif /* VCP_SIMPLE_MATRIX_WITH_TITLE */
        
    return;
}


VfxBool VcpSimpleMatrix::onKeyInput(VfxKeyEvent &event)
{
    if (m_isBlockInput)
    {
        // Block input event
        return VFX_FALSE;
    }

    VfxS32 count = m_numColumns * m_numRows, index = m_highlightIndex;
    VfxTransform frame_transform;
    
    if ((event.type == VFX_KEY_EVENT_TYPE_DOWN) || (event.type == VFX_KEY_EVENT_TYPE_REPEAT))
    {
        if (m_penState == PEN_STATE_LONG_TAP/* && event.keyCode != VFX_KEY_CODE_ENTER*/)
        {
            stopDragMove();            
        }
        m_highlightTriggeredByPen = VFX_FALSE;
#ifdef __MMI_VUI_MAIN_MENU_SUPPORT_FASTMOVE
        if (m_highlightEffectFinished)
        {
            // Transition effect is finished, matrix can handle key event directly.
            m_fastMoveCount = -1;
#endif
            switch (event.keyCode)
            {
                case VFX_KEY_CODE_VOL_UP:
                    /* FALLTHROUGH no break */
                case VFX_KEY_CODE_ARROW_LEFT:
                    if (m_highlightIndex > 0)
                    {
                        changeCurrentHighlightIndex(index - 1);
                    }
                    else
                    {
                        changeCurrentHighlightIndex(count - 1);
                    }
                    break;

                case VFX_KEY_CODE_VOL_DOWN:
                    /* FALLTHROUGH no break */
                case VFX_KEY_CODE_ARROW_RIGHT:
                    if (m_highlightIndex < count - 1)
                    {
                        changeCurrentHighlightIndex(index + 1);
                    }
                    else
                    {
                        changeCurrentHighlightIndex(0);
                    }
                    break;

                case VFX_KEY_CODE_ARROW_UP:
                    if (m_highlightIndex >= m_numColumns)
                    {
                        changeCurrentHighlightIndex(index - m_numColumns);
                    }
                    else
                    {
                        changeCurrentHighlightIndex(count - m_numColumns + index);
                    }
                    break;

                case VFX_KEY_CODE_ARROW_DOWN:
                    if (m_highlightIndex < count - m_numColumns)
                    {
                        changeCurrentHighlightIndex(index + m_numColumns);
                    }
                    else
                    {
                        changeCurrentHighlightIndex(index % m_numColumns);
                    }
                    break;
            }
#ifdef __MMI_VUI_MAIN_MENU_SUPPORT_FASTMOVE
        }
        else 
        {
            // Transition effect is not finished, key event will be recorded in the queue of fastmove
            if(m_fastMoveCount != -1)
            {
                index = m_fastMoveQueue[m_fastMoveCount];
            }
            
            switch (event.keyCode)
            {
                case VFX_KEY_CODE_VOL_UP:
                    /* FALLTHROUGH no break */
                case VFX_KEY_CODE_ARROW_LEFT:
                    
                    m_fastMoveCount++;
                    if (m_fastMoveCount >= FAST_MOVE_QUEUE_SIZE)
                    {
                        m_fastMoveCount = FAST_MOVE_QUEUE_SIZE - 1;
                    }
                    if (index > 0)
                    {
                        m_fastMoveQueue[m_fastMoveCount] = index - 1;
                    }
                    else
                    {
                        m_fastMoveQueue[m_fastMoveCount] = count - 1;
                    }
                    break;

                case VFX_KEY_CODE_VOL_DOWN:
                    /* FALLTHROUGH no break */
                case VFX_KEY_CODE_ARROW_RIGHT:
                    
                    m_fastMoveCount++;
                    if (m_fastMoveCount >= FAST_MOVE_QUEUE_SIZE)
                    {
                        m_fastMoveCount = FAST_MOVE_QUEUE_SIZE - 1;
                    }
                    if (index < count - 1)
                    {
                        m_fastMoveQueue[m_fastMoveCount] = index + 1;
                    }
                    else
                    {
                        m_fastMoveQueue[m_fastMoveCount] = 0;
                    }
                    break;

                case VFX_KEY_CODE_ARROW_UP:
                    
                    m_fastMoveCount++;
                    if (m_fastMoveCount >= FAST_MOVE_QUEUE_SIZE)
                    {
                        m_fastMoveCount = FAST_MOVE_QUEUE_SIZE - 1;
                    }
                    if (index >= m_numColumns)
                    {
                        m_fastMoveQueue[m_fastMoveCount] = (VfxS32)index - (VfxS32)m_numColumns;
                    }
                    else
                    {
                        m_fastMoveQueue[m_fastMoveCount] = count - m_numColumns + index;
                    }
                    break;

                case VFX_KEY_CODE_ARROW_DOWN:
                    
                    m_fastMoveCount++;
                    if (m_fastMoveCount >= FAST_MOVE_QUEUE_SIZE)
                    {
                        m_fastMoveCount = FAST_MOVE_QUEUE_SIZE - 1;
                    }
                    if (index < count - m_numColumns)
                    {
                        m_fastMoveQueue[m_fastMoveCount] = index + m_numColumns;
                    }
                    else
                    {
                        m_fastMoveQueue[m_fastMoveCount] = index % m_numColumns;
                    }
                    break;
            }
        }
#endif
    }
    /*else if (event.type == VFX_KEY_EVENT_TYPE_UP)
    {
        if (event.keyCode == VFX_KEY_CODE_ENTER)
            m_signalLSK.emit(VCP_SOFTKEY_UP);
    }*/
    
    return VFX_TRUE;
}


void VcpSimpleMatrix::onDragTransitionStop(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    // Start the shaking effect
    
#define DRAG_MOVE_OFFSET_TABLE_SIZE 8
    static const VfxS8 offset_table[DRAG_MOVE_OFFSET_TABLE_SIZE][4] = 
    {
        // {x1 offset, y1 offset, x2 offset, y2 offset}
        {-2, -2, 1, 1},
        {0, -2, 0, 2},
        {2, -2, -1, 1},
        {2, 0, -2, 0},
        {2, 2, -1, -1},
        {0, 2, 0, -2},
        {-2, 2, 1, -1},
        {-2, 0, 2, 0}
    };

    if (isCompleted)
    {
        VFX_OBJ_CLOSE(timeline);
        m_opacityTimeline = NULL;
        
        m_normalItems[m_highlightIndex]->setHidden(VFX_FALSE);
        if (m_highlightDrag)
        {
            m_highlightDrag->setHidden(VFX_FALSE);
        }

        VfxTransform frame_transform;
    #ifndef __MMI_VUI_LITE_DISPLAY__
        frame_transform = m_normalItems[m_highlightIndex]->getTransform();
        frame_transform.data.affine.sx = 1.2F;
        frame_transform.data.affine.sy = 1.2F;
        m_normalItems[m_highlightIndex]->setTransform(frame_transform);
    #endif /* __MMI_VUI_LITE_DISPLAY__ */

        frame_transform = m_highlightFrame->getTransform(); // TODO: seems redundant to stopDragMove()
        frame_transform.data.affine.sx = 1.0F;
        frame_transform.data.affine.sy = 1.0F;
        m_highlightFrame->setTransform(frame_transform);
        m_highlightFrame->setOpacity(1.0F);                
        m_highlightFrame->setHidden(VFX_TRUE);
        m_stopByKey = VFX_FALSE;
        

        // Setup the timelines to modify anchor points of frames such that it won't interfere the drag-n-move effect.
        // When menu order is changed, we do not need to stop the timelines.
        for (VfxS32 i = 0; i < m_numRows * m_numColumns; i++)
        {
            VfxS32 startTime = rand() % DRAG_EFFECT_RANDOM_DELAY;

            if (m_dragPosTimeline[i] == NULL)
            {
                VFX_OBJ_CREATE(m_dragPosTimeline[i], VfxFPointTimeline, this);        
            }
            
            m_dragPosTimeline[i]->setIsFromCurrent(VFX_TRUE);
            const VfxS8 *offsets = offset_table[(rand() % DRAG_MOVE_OFFSET_TABLE_SIZE)];
            m_dragPosTimeline[i]->setFromValue(VfxFPoint(0.5F + 0.015F * offsets[0], 0.5F + 0.015F * offsets[1]));
            m_dragPosTimeline[i]->setToValue(VfxFPoint(0.5F + 0.015F * offsets[2], 0.5F + 0.015F * offsets[3]));
            m_dragPosTimeline[i]->setDurationTime(DRAG_MOVE_DURATION);
            m_dragPosTimeline[i]->setAutoReversed(VFX_TRUE);
            m_dragPosTimeline[i]->setStartTime(startTime);
            m_dragPosTimeline[i]->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
            m_dragPosTimeline[i]->setTarget(m_normalItems[i]);
            m_dragPosTimeline[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_ANCHOR_POINT);

        #ifdef VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE
            if (m_dragTransformTimeline[i] == NULL)
            {
                VFX_OBJ_CREATE(m_dragTransformTimeline[i], VfxFloatTimeline, this);        
            }
            m_dragTransformTimeline[i]->setIsFromCurrent(VFX_TRUE);
            m_dragTransformTimeline[i]->setFromValue(VFX_DEG_TO_RAD(-5));
            m_dragTransformTimeline[i]->setToValue(VFX_DEG_TO_RAD(5));
            m_dragTransformTimeline[i]->setDurationTime(DRAG_MOVE_DURATION);
            m_dragTransformTimeline[i]->setAutoReversed(VFX_TRUE);
            
            m_dragTransformTimeline[i]->setStartTime(startTime);
            m_dragTransformTimeline[i]->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
            m_dragTransformTimeline[i]->setTarget(m_normalItems[i]);
            m_dragTransformTimeline[i]->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM_AFFINE_RZ);
        #endif

            if (i != m_dragIndex)
            {
                m_normalItems[i]->setAutoAnimate(VFX_TRUE); // for auto re-ordering effect
                m_dragPosTimeline[i]->start();
            #ifdef VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE
                m_dragTransformTimeline[i]->start();
            #endif
            }
            else
            {
                m_normalItems[i]->setAutoAnimate(VFX_FALSE); // drag by pen
            }
        }
    }
}


void VcpSimpleMatrix::startDragMove()
{    
    m_penState = PEN_STATE_LONG_TAP;
    
    VfxTransform frame_transform = m_highlightFrame->getTransform();
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDuration(DRAG_MOVE_START);
    frame_transform.data.affine.sx = 0.6F;
    frame_transform.data.affine.sy = 0.6F;
    m_highlightFrame->setTransform(frame_transform);
    VfxAutoAnimate::commit();  
    
    for (VfxS32 i = 0; i < TOTAL_ITEMS; i++)
    {
        m_menuPreOrder[i] = m_menuOrder[i];
    }
    
    VFX_OBJ_CREATE(m_opacityTimeline, VfxFloatTimeline, this);
    m_opacityTimeline->setIsFromCurrent(VFX_TRUE);
    m_opacityTimeline->setFromValue(1.0F);
    m_opacityTimeline->setToValue(0.2F);
    m_opacityTimeline->setDurationTime(DRAG_MOVE_START);
    m_opacityTimeline->setAutoReversed(VFX_TRUE);
    m_opacityTimeline->setStartTime(0);
    m_opacityTimeline->setRepeatCount(1);
    m_opacityTimeline->setTarget(m_highlightFrame);
    m_opacityTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_opacityTimeline->m_signalStopped.connect(this, &VcpSimpleMatrix::onDragTransitionStop);  
    m_opacityTimeline->start();
    gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_HOLD);
}


void VcpSimpleMatrix::onPenTimer(VfxTimer *source)
{
    VfxTransform frame_transform;
    VfxRect rect = getBounds();
    
    // Longtap at one item, entry drag and move mode.    
    VFX_UNUSED(source);
    
    if (m_penTimer)
    {
        m_penTimer->stop();
    }
    
    m_dragIndex = m_highlightIndex;
    if (m_highlightDrag == NULL)
    {
        VFX_OBJ_CREATE(m_highlightDrag, VfxFrame, m_normalItems[m_highlightIndex]);
        addChildFrame(m_normalItems[m_highlightIndex]); // move the seleted item to the top position in this matrx
        m_normalItems[m_highlightIndex]->insertChildFrameBefore(m_normalItems[m_highlightIndex]->m_image, m_highlightDrag);
        m_highlightDrag->setAnchor(VfxFPoint(0.5F, 0.5F));
		m_highlightDrag->setImgContent(VfxImageSrc(MAIN_MENU_STYLE1_DRAG_HIGHLIGHT));
        m_highlightDrag->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(NORMAL_ICON_WIDTH, NORMAL_ICON_WIDTH)));
    #ifndef VCP_MATRIX_DISABLE_ITEM_FRAME_CACHE        
        m_highlightDrag->setIsCached(VFX_TRUE);
    #endif
        m_highlightDrag->setPos(m_normalItems[m_highlightIndex]->m_image->getPos());
        m_normalItems[m_highlightIndex]->setPos(VfxPoint(m_normalItems[m_highlightIndex]->m_x, m_normalItems[m_highlightIndex]->m_y));
        
        m_highlightDrag->setHidden(VFX_TRUE);
    }
    startDragMove();
    m_penHighlightChanged = VFX_TRUE;   
    
    m_signalSoftkeyStateChanged.emit(VCP_MATRIX_SOFTKEY_RESET);
}


void VcpSimpleMatrix::onBubbleTimer(VfxTimer *source)
{
    
    VFX_UNUSED(source);
    switch(m_bubbleAnimIndex)
    {
        case 0:
			m_highlightFrame->setImgContent(VfxImageSrc(MAIN_MENU_BUBBLE_HIGHLIGHT_1));
            break;
        case 1:
			m_highlightFrame->setImgContent(VfxImageSrc(MAIN_MENU_BUBBLE_HIGHLIGHT_2));
            break;
        case 2:
			m_highlightFrame->setImgContent(VfxImageSrc(MAIN_MENU_BUBBLE_HIGHLIGHT_3));
            break;
        case 3:
			m_highlightFrame->setImgContent(VfxImageSrc(MAIN_MENU_BUBBLE_HIGHLIGHT_4));
            break;
        case 4:
			m_highlightFrame->setImgContent(VfxImageSrc(MAIN_MENU_STYLE_HIGHLIGHT_IMG));
            // Change back to highlight image
            m_highlightItem->setHidden(VFX_FALSE);
            break;
    }
    m_highlightFrame->invalidate();
    
    m_bubbleAnimIndex++;
    if (m_bubbleAnimIndex == 5)
    {
        updateHighlightItem();
        m_bubbleAnimIndex = 0;
        m_highlightTimer->stop();
        m_highlightEffectFinished = VFX_TRUE;
        // Handler the event in queue of fast move.
        if (m_fastMoveCount != -1)
        {
            changeCurrentHighlightIndex(m_fastMoveQueue[m_fastMoveCount]);
        }
    }
}


VfxBool VcpSimpleMatrix::onPenInput(VfxPenEvent &event)
{
    if (m_isBlockInput)
    {
        // Block input event
        return VFX_FALSE;
    }

    VfxS32 nrow, ncolumn;
    VfxS32 index = m_highlightIndex, new_index;
    VfxS32 x, y, width, height, i;
    VfxPoint pos = event.getRelPos(this);
    VfxRect rect = getBounds();
    VfxS32 old_index;
    VcpSimpleMatrixIcon *old_item;
    VfxTransform frame_transform;
    
    width = rect.size.width / m_numColumns;
    height = (rect.size.height)/ m_numRows;
    x = (rect.size.width - width * m_numColumns) / 2;
    y = (rect.size.height - height * m_numRows) / 2;
    ncolumn = (pos.x - x) / width;
    nrow = (pos.y - y) / height;
    if (ncolumn >= m_numColumns)
    {
        ncolumn = m_numColumns - 1;
    }
    if (ncolumn < 0)
    {
        ncolumn = 0;
    }
    if (nrow >= m_numRows)
    {
        nrow = m_numRows - 1;
    }
    if (nrow < 0)
    {
        nrow = 0;
    }    
    
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        if (pos.y <= 0)
        {
            return VFX_FALSE;
        }
        m_highlightTriggeredByPen = VFX_TRUE;
        m_penHighlightChanged = VFX_FALSE;
        m_penDownPos = event.getRelPos(this);
        changeCurrentHighlightIndex(nrow * m_numColumns + ncolumn);
        index = m_highlightIndex;
        if (m_penState != PEN_STATE_LONG_TAP)
        {
            //updateHighlightItem();
            m_penState = PEN_STATE_DOWN;
            VFX_OBJ_CREATE(m_penTimer, VfxTimer, this);
            m_penTimer->setStartDelay(LONG_TAP_INTERVAL);
            m_penTimer->m_signalTick.connect(this, &VcpSimpleMatrix::onPenTimer);
            m_penTimer->start();
        }
        else
        {
            if (m_highlightDrag == NULL)
            {
                m_dragPosTimeline[index]->stop(); // disable the shaking effect of highlighted item
            #ifdef VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE
                m_dragTransformTimeline[index]->stop();// disable the rotate effect of highlighted item
            
                VfxTransform frame_transform = m_normalItems[index]->getTransform();
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDisable(VFX_TRUE);
                frame_transform.data.affine.rz = VFX_DEG_TO_RAD(0);
                m_normalItems[index]->setTransform(frame_transform);
                VfxAutoAnimate::commit();
            #endif 
                
                VFX_OBJ_CREATE(m_highlightDrag, VfxFrame, m_normalItems[index]);

                addChildFrame(m_normalItems[index]); // move the seleted item to the top position in this matrx
                m_normalItems[index]->insertChildFrameBefore(m_normalItems[index]->m_image, m_highlightDrag);
                
                m_highlightDrag->setAnchor(VfxFPoint(0.5F, 0.5F));
				m_highlightDrag->setImgContent(VfxImageSrc(MAIN_MENU_STYLE1_DRAG_HIGHLIGHT));
                m_highlightDrag->setBounds(VfxRect(VFX_POINT_ZERO, VfxSize(NORMAL_ICON_WIDTH, NORMAL_ICON_WIDTH)));
            #ifndef VCP_MATRIX_DISABLE_ITEM_FRAME_CACHE
                m_highlightDrag->setIsCached(VFX_TRUE);
            #endif
                m_highlightDrag->setPos(m_normalItems[index]->m_image->getPos());
                
                VfxAutoAnimate::begin();
                VfxAutoAnimate::setDisable(VFX_TRUE);
                m_normalItems[index]->setPos(VfxPoint(m_normalItems[index]->m_x, m_normalItems[index]->m_y));
                m_normalItems[index]->setAnchor(VfxFPoint(0.5F, 0.5F)); // reset the anchor point
                VfxAutoAnimate::commit();

            #ifndef __MMI_VUI_LITE_DISPLAY__
                m_normalItems[index]->setAutoAnimate(VFX_TRUE);                
                frame_transform = m_normalItems[index]->getTransform();
                frame_transform.data.affine.sx = 1.2F;
                frame_transform.data.affine.sy = 1.2F;
                m_normalItems[index]->setTransform(frame_transform);
                m_normalItems[index]->setAutoAnimate(VFX_FALSE);                
            #endif /* __MMI_VUI_LITE_DISPLAY__ */
                
                m_dragIndex = index;
            }
        }
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_MOVE)
    {
        new_index = nrow * m_numColumns + ncolumn;
        if (new_index != index || pos.y <= 0 || pos.y >= rect.size.height)
        {
            if (m_penTimer)
            {
                m_penTimer->stop();
            }
        }
        m_highlightTriggeredByPen = VFX_TRUE;
        if (m_penState == PEN_STATE_LONG_TAP)
        {
            if (m_highlightDrag && m_opacityTimeline == NULL)
            {
                // In drag and move mode
                if (m_penLastPos.x == pos.x && m_penLastPos.y == pos.y)
                {
                    return VFX_TRUE;
                }
                m_penLastPos = event.getRelPos(this);
                for(i = 0; i < m_numColumns * m_numRows; i++)
                {
                    if (i != index)
                    {
                        m_normalItems[i]->setAutoAnimate(VFX_TRUE); // for later auto reordering effect
                    }
                    else
                    {
                        m_normalItems[i]->setAutoAnimate(VFX_FALSE); // to conrol the position more precisely
                    }
                }

                new_index = nrow * m_numColumns + ncolumn;
                if (new_index <= 0)
                {
                    new_index = 0;
                }
                if (new_index >= m_numColumns * m_numRows)
                {
                    new_index = m_numColumns * m_numRows - 1;
                }

                if (index != new_index)
                {
                    // Insert the item in new position.
                    old_item = m_normalItems[index];
                    old_index = m_menuOrder[index];
                    VfxFPointTimeline *oldPosTimeline = m_dragPosTimeline[index];
                #ifdef VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE
                    VfxFloatTimeline *oldTransfromTimeline = m_dragTransformTimeline[index];
                #endif
                    if (new_index < index)
                    {
                        for (i = index; i > new_index; i--)
                        {
                            m_normalItems[i] = m_normalItems[i - 1];
                            m_menuOrder[i] = m_menuOrder[i - 1];
                            m_dragPosTimeline[i] = m_dragPosTimeline[i - 1];
                        #ifdef VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE
                            m_dragTransformTimeline[i] = m_dragTransformTimeline[i - 1];
                        #endif
                        }
                        m_normalItems[new_index] = old_item;
                        m_menuOrder[new_index] = old_index;
                        m_dragPosTimeline[new_index] = oldPosTimeline;
                    #ifdef VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE
                        m_dragTransformTimeline[new_index] = oldTransfromTimeline;
                    #endif
                    }
                    else if (new_index > index)
                    {
                        for (i = index; i < new_index; i++)
                        {
                            m_normalItems[i] = m_normalItems[i + 1];
                            m_menuOrder[i] = m_menuOrder[i + 1];
                            m_dragPosTimeline[i] = m_dragPosTimeline[i + 1];
                        #ifdef VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE
                            m_dragTransformTimeline[i] = m_dragTransformTimeline[i + 1];
                        #endif
                        }
                        m_normalItems[new_index] = old_item;
                        m_menuOrder[new_index] = old_index;                    
                        m_dragPosTimeline[new_index] = oldPosTimeline;
                    #ifdef VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE
                        m_dragTransformTimeline[new_index] = oldTransfromTimeline;
                    #endif
                    }
                #ifndef VCP_MATRIX_REORDER_ITEMS_AFTER_PEN_UP                    
                    layoutItems();
                #endif

                    changeCurrentHighlightIndex(new_index);
                }
                                
                // Adjust the position of highlighted item to pen position
                m_normalItems[new_index]->setPos(VfxPoint(pos.x, pos.y));
                
                m_dragIndex = new_index;
            }
            else
            {
                // Do not really entry drag and move mode.
                // Matrix will back to normal mode if pen move to another item in this case.
                if (new_index != index)
                {
                    stopDragMove();
                    changeCurrentHighlightIndex(nrow * m_numColumns + ncolumn);
                    index = m_highlightIndex;
                }
            }
        }
        else
        {
            if (pos.y > 0 && pos.y < rect.size.height)
            {
                changeCurrentHighlightIndex(nrow * m_numColumns + ncolumn);
                if (index != m_highlightIndex)
                {
                    m_penHighlightChanged = VFX_TRUE;
                }
                index = m_highlightIndex;
            }
        }
        m_penDownPos = event.getRelPos(this);
    }
    else if(event.type == VFX_PEN_EVENT_TYPE_UP || event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        if (m_penTimer)
        {
            m_penTimer->stop();
        }
        if (m_penState == PEN_STATE_LONG_TAP)
        {
            if (m_opacityTimeline == NULL)
            {
                // Do not show the background of drag item.
                m_dragPosTimeline[index]->start();
            #ifdef VCP_SIMPLE_MATRIX_ROTATE_IN_DRAG_MODE
                m_dragTransformTimeline[index]->start();
            #endif
                if (m_highlightDrag)
                {
                    frame_transform = m_normalItems[index]->getTransform();
                    frame_transform.data.affine.sx = 1.0F;
                    frame_transform.data.affine.sy = 1.0F;
                    m_normalItems[index]->setTransform(frame_transform);
                    layoutItems();
                    m_dragIndex = m_numColumns * m_numRows;
                    VFX_OBJ_CLOSE(m_highlightDrag);
                }
            }
            else
            {
                // Back to normal mode.
                stopDragMove();
            }
        }
        else
        {   
            if (m_highlightDrag)
            {
                frame_transform = m_normalItems[index]->getTransform();
                frame_transform.data.affine.sx = 1.0F;
                frame_transform.data.affine.sy = 1.0F;
                m_normalItems[index]->setTransform(frame_transform);
                VFX_OBJ_CLOSE(m_highlightDrag);
            }
            if (pos.x >= x && pos.x <= x + width * m_numColumns && pos.y >= y && pos.y <= y + height * m_numRows)
            {
                if (m_penHighlightChanged == VFX_FALSE && event.type != VFX_PEN_EVENT_TYPE_ABORT)
                {
                    m_signalSoftkeyStateChanged.emit(VCP_MATRIX_SOFTKEY_ENABLED);
                    m_signalLSK.emit(VCP_SOFTKEY_UP);
                    m_signalSoftkeyStateChanged.emit(VCP_MATRIX_SOFTKEY_ENABLED);
                } 
            }
            m_penState = PEN_STATE_UP;
            m_highlightTriggeredByPen = VFX_FALSE;
            
        }
        
    }
    return VFX_TRUE;
}


void VcpSimpleMatrix::initEntryAnimation()
{
    VfxS32 i, j, k = 0;

    m_isBlockInput = VFX_TRUE;
    m_signalSoftkeyStateChanged.emit(VCP_MATRIX_SOFTKEY_DISABLED);

    for (i = 0; i < m_numRows; i++)
    {
        for(j = 0; j < m_numColumns; j++)
        {
            VfxS32 x = m_normalItems[k]->m_x;
            VfxS32 y = m_normalItems[k]->m_y;            

            if (j <= m_numColumns / 2 - 1)
            {
                x -= NORMAL_ICON_WIDTH;
            }
            else if (j > (m_numColumns / 2) + (m_numColumns % 2) - 1) /* if column is odd */
            {
                x += NORMAL_ICON_WIDTH;
            }

            if (i <= m_numRows / 2 - 1)
            {
                y -= NORMAL_ICON_HEIGHT;
            }
            else if (i > (m_numRows / 2) + (m_numRows % 2) - 1)
            {
                y += NORMAL_ICON_HEIGHT;       
            }
            
            m_normalItems[k]->setPos(VfxPoint(x, y));

        #ifdef VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON
            // Hide text first
            m_normalItems[k]->m_text->setHidden(VFX_TRUE);
        #endif
            
            k++;
            if (k >= TOTAL_ITEMS)
            {
                break;
            }
        }
    }

    // Hide the highlight frame
    m_highlightFrame->setHidden(VFX_TRUE);

    // Do not hide the normal icon behind the highlight
    VFX_ASSERT(m_highlightIndex >= 0);
    m_normalItems[m_highlightIndex]->setHidden(VFX_FALSE);      
}


void VcpSimpleMatrix::startEntryAnimation()
{
    VfxAutoAnimate::initAnimateBegin();
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDuration(ENTRY_ANIMATION_INTERVAL);

    VfxS32 i, j, k = 0;
    for (i = 0; i < m_numRows; i++)
    {
        for(j = 0; j < m_numColumns; j++)
        {
            VfxS32 x = m_normalItems[k]->m_x;
            VfxS32 y = m_normalItems[k]->m_y;            

            m_normalItems[k]->setPos(VfxPoint(x, y));

            k++;
            if (k >= TOTAL_ITEMS)
            {
                break;
            }
        }
    }

    VfxAutoAnimate::commit();
    VfxAutoAnimate::initAnimateEnd();

    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(ENTRY_ANIMATION_INTERVAL + ENTRY_ANIMATION_INTERVAL2);
    timer->m_signalTick.connect(this, &VcpSimpleMatrix::onEntryAnimTimer);
    timer->start();
}


void VcpSimpleMatrix::onEntryAnimTimer(VfxTimer *source)
{
    m_isBlockInput = VFX_FALSE;
    m_signalSoftkeyStateChanged.emit(VCP_MATRIX_SOFTKEY_ENABLED);

    // Show the highlight frame and hide the icon behind the highlight frame
    m_highlightFrame->setHidden(VFX_FALSE);

    VFX_ASSERT(m_highlightIndex >= 0);
    m_normalItems[m_highlightIndex]->setHidden(VFX_TRUE);   

    // Show text under each menu item
#ifdef VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON  
    for (VfxS32 i = 0; i < TOTAL_ITEMS; i++)
    {
        m_normalItems[i]->m_text->setHidden(VFX_FALSE);
    }
#endif /* VCP_SIMPLE_MATRIX_TEXT_UNDER_ICON */

    // Close the timer
    VFX_OBJ_CLOSE(source);
}


void VcpSimpleMatrix::resetNormal()
{
    stopDragMove();   
    m_highlightTriggeredByPen = VFX_FALSE;
}


void VcpSimpleMatrix::resetNormalAndRestore()
{
    restoreOrder();
    stopDragMove();   
    vadp_v2p_main_menu_style1_Highlight_handler(m_menuOrder[m_highlightIndex]);
    m_highlightTriggeredByPen = VFX_FALSE;
}


void VcpSimpleMatrix::onEventinput(VfxS32 num) // TODO: move this function to VappMmScr
{
    if (m_stopByKey == VFX_TRUE)
    {
        // Matrix back to normal mode by this event.
        m_stopByKey = VFX_FALSE;
        return;
    }
    if (num >= (m_numRows * m_numColumns) || num < 0)
    {
        // Invalid input
        return;
    }
    if(m_isBlockInput)
	{
		return;
	}
    m_highlightTriggeredByPen = VFX_TRUE;
    m_isBlockInput = VFX_TRUE;
    changeCurrentHighlightIndex(num);
    m_signalLSK.emit(VCP_SOFTKEY_UP);
}


void VcpSimpleMatrix::onStopDrag()
{
    if (m_penState == PEN_STATE_LONG_TAP)
    {
        stopDragMove();            
        m_stopByKey = VFX_TRUE;
    }
}


void VcpSimpleMatrix::onPropertyBacklightSwitch(VfxBool isOn)
{
    if (isOn)
    {
        // Back to normal mode if backlight is turn on.
        stopDragMove();   
        m_highlightTriggeredByPen = VFX_FALSE;
    }
}


VcpSimpleMatrix::DirectionEnum VcpSimpleMatrix::getEffectDirection(VfxS32 OldIndex, VfxS32 index)
{
    VfxS32 oldRow = OldIndex / m_numColumns;
    VfxS32 oldColumn = OldIndex % m_numColumns;
    VfxS32 row = index / m_numColumns;
    VfxS32 column = index % m_numColumns;

    if (column == 0 && oldColumn == m_numColumns - 1)
    {
        return DIRECTION_RIGHTWARD;
    }
    else if (oldColumn == 0 && column == m_numColumns - 1)
    {
        return DIRECTION_LEFTWARD;
    }
    else if (oldRow == 0 && row == m_numRows - 1)
    {
        return DIRECTION_UPWARD;
    }
    else if (row == 0 && oldRow == m_numRows - 1)
    {
        return DIRECTION_DOWNWARD;
    }
    else if (column < oldColumn)
    {
        return DIRECTION_LEFTWARD;
    }
    else if (column > oldColumn)
    {
        return DIRECTION_RIGHTWARD;
    }
    else if (row < oldRow)
    {
        return DIRECTION_UPWARD;
    }
    else
    {
        return DIRECTION_DOWNWARD;
    }
}
#endif
