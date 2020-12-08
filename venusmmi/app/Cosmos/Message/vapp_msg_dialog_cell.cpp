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
 *  vapp_msg_dialog_cell.cpp
 *
 * Project:
 * --------
 *  Venus 
 *
 * Description:
 * ------------
 *  Message Dialog Cell
 *
 * Author:
 * -------
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
 * removed!
 * removed!
 * removed!
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

#include "vapp_msg_dialog_cell.h"
#ifdef __cplusplus
extern "C"
#endif
{
    #include "mmi_rp_vapp_msg_def.h"
    #include "mmi_rp_srv_venus_component_list_menu_def.h"  
}

#define DEBUG_LAYOUT(_obj,_color) //(_obj)->setBgColor(_color);

VFX_IMPLEMENT_VIRTUAL_CLASS("VappMsgDialogCell", VappMsgDialogCell, VcpVarHeightMenuCell);

VappMsgDialogCell::VappMsgDialogCell(VcpMenuPos menupos, VappMsgDialogCellSideEnum side, VappMsgDialogCellStyleEnum style) :
    VcpVarHeightMenuCell(menupos),
    m_isUpdate(VFX_FALSE),
    m_isMarked(VFX_FALSE),
    m_isDisabled(VFX_FALSE),
    m_isReadyForAnimation(VFX_FALSE),
    m_style(style),
    m_side(side),
    m_checkbox(NULL),
    m_container(NULL),
    m_bubble(NULL),
    m_bubbleMask(NULL),
    m_content(NULL),
    m_timeText(NULL),
    m_timeFontEffect(NULL),
    m_arrow(NULL),
    m_arrowMask(NULL),
    m_tl_init_opacity(NULL),
    m_tl_init_pos_x(NULL),
    m_tl_style_pos_x(NULL),
    m_tl_style_cb_pos_x(NULL)
{
}

VappMsgDialogCell::VappMsgDialogCellStyleEnum VappMsgDialogCell::getStyle()
{
    return m_style;
}

VappMsgDialogCell::VappMsgDialogCellSideEnum VappMsgDialogCell::getSide()
{
    return m_side;
}

VfxFrame *VappMsgDialogCell::getContentFrame()
{
    return m_content;
}

void VappMsgDialogCell::setMark(VfxBool isMark)
{
    if (CHECKBOX != m_style)
    {
        return;
    }
    
    m_isMarked = isMark;
    needRelayout();
}

void VappMsgDialogCell::setStyle(VappMsgDialogCellStyleEnum style, VfxBool with_animation)
{
    if (m_style == style)
    {
        return;
    }
    
    m_style = style;

    if (VFX_TRUE == with_animation)
    {
        if (LEFT == m_side)
        {
            if (NULL == m_tl_style_pos_x) 
            {
                VFX_OBJ_CREATE(m_tl_style_pos_x, VfxS32Timeline, this);
                m_tl_style_pos_x->setStartDelay(0);
                m_tl_style_pos_x->setDuration(CB_ANIMATION_DURATION);
                m_tl_style_pos_x->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
            }
        }        
        if (NULL == m_tl_style_cb_pos_x) 
        {
            VFX_OBJ_CREATE(m_tl_style_cb_pos_x, VfxS32Timeline, this);
            m_tl_style_cb_pos_x->setStartDelay(0);
            m_tl_style_cb_pos_x->setDuration(CB_ANIMATION_DURATION);
            m_tl_style_cb_pos_x->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
        }        
        if (CHECKBOX == m_style)
        {
            /* on demand create checkbox */
            if (NULL == m_checkbox)
            {
                VFX_OBJ_CREATE(m_checkbox, VcpImageButton, this);
                m_checkbox->m_signalClicked.connect(this, &VappMsgDialogCell::onMarkClicked);
                m_checkbox->setSize(CHECKBOX_SIZE, CHECKBOX_SIZE);
                m_checkbox->setPos((VfxS32)CHECKBOX_EXT_MARGIN_LEFT - BUBBLE_EXT_MARGIN_CB, CHECKBOX_EXT_MARGIN_TOP);
                m_checkbox->setImage(VcpStateImage(VCP_IMG_LIST_MENU_CHECK_BOX_OFF));
                DEBUG_LAYOUT(m_checkbox, VFX_COLOR_RED);
            }

            if (LEFT == m_side)
            {
                m_tl_style_pos_x->setTarget(m_container);
                m_tl_style_pos_x->setFromValue(BUBBLE_EXT_MARGIN_LEFT);
                m_tl_style_pos_x->setToValue(BUBBLE_EXT_MARGIN_CB - BUBBLE_ARROW_WIDTH + 1);
                m_tl_style_pos_x->start();
            }
            m_tl_style_cb_pos_x->setTarget(m_checkbox);
            m_tl_style_cb_pos_x->setFromValue((VfxS32)CHECKBOX_EXT_MARGIN_LEFT - (BUBBLE_EXT_MARGIN_CB - BUBBLE_ARROW_WIDTH + 1));
            m_tl_style_cb_pos_x->setToValue(CHECKBOX_EXT_MARGIN_LEFT);
            m_tl_style_cb_pos_x->start();
        }
        else
        {
            if (LEFT == m_side)
            {
                m_tl_style_pos_x->setTarget(m_container);
                m_tl_style_pos_x->setFromValue(BUBBLE_EXT_MARGIN_CB - BUBBLE_ARROW_WIDTH + 1);
                m_tl_style_pos_x->setToValue(BUBBLE_EXT_MARGIN_LEFT);
                m_tl_style_pos_x->start();
            }
            m_tl_style_cb_pos_x->setTarget(m_checkbox);
            m_tl_style_cb_pos_x->setFromValue(CHECKBOX_EXT_MARGIN_LEFT);
            m_tl_style_cb_pos_x->setToValue((VfxS32)CHECKBOX_EXT_MARGIN_LEFT - (BUBBLE_EXT_MARGIN_CB - BUBBLE_ARROW_WIDTH + 1));
            m_tl_style_cb_pos_x->start();
        }
    }

    needRelayout();
}

void VappMsgDialogCell::setSide(VappMsgDialogCellSideEnum side, VfxBool force)
{
    if (m_side == side && !force)
    {
        return;
    }    

    m_side = side;

    if (RIGHT == m_side)
    {
        m_arrow->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_ARROW_RIGHT));
        m_arrowMask->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_ARROW_RIGHT_DISABLED));
        m_bubble->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_BUBBLE_RIGHT));
        m_bubbleMask->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_BUBBLE_RIGHT_DISABLED));
    }
    else
    {
        m_arrow->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_ARROW_LEFT));
        m_arrowMask->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_ARROW_LEFT_DISABLED));
        m_bubble->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_BUBBLE_LEFT));
        m_bubbleMask->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_BUBBLE_LEFT_DISABLED));
    }    

    needRelayout();
}

void VappMsgDialogCell::setTime(const VfxWString &value)
{
    if (!m_timeText)
    {
        VFX_OBJ_CREATE(m_timeText, VfxTextFrame, m_container);
    }    

    VfxFontDesc font;
    font.size = VFX_FONT_DESC_VF_SIZE(BUBBLE_TIME_FONT_SIZE);
    font.effect = m_timeFontEffect->getEffectId();
    m_timeText->setFont(font);
    if (LEFT == m_side)
    {
        m_timeText->setColor(VFX_COLOR_RES(BUBBLE_TIME_FONT_COLOR_LEFT));
    }
    else
    {
        m_timeText->setColor(VFX_COLOR_RES(BUBBLE_TIME_FONT_COLOR_RIGHT));
    }
    m_timeText->setString(value);
    m_timeText->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);  
    DEBUG_LAYOUT(m_timeText, VFX_COLOR_YELLOW);
    needRelayout();
}

void VappMsgDialogCell::setContentFrame(VfxFrame *content)
{
    if (m_content)
    {
        VFX_OBJ_CLOSE(m_content);
    }   

    m_content = content;
    m_content->m_signalBoundsChanged.connect(this, &VappMsgDialogCell::onContentBoundsChanged);    
    m_container->addChildFrame(m_content);
    DEBUG_LAYOUT(m_content, VFX_COLOR_AQUA);
    needRelayout();
}

void VappMsgDialogCell::setDisabled(VfxBool disabled)
{
    if (m_isDisabled == disabled)
    {
        return;
    }    

    m_isDisabled = disabled;

    needRelayout();
}

void VappMsgDialogCell::prepareAnimation()
{
    setAutoAnimate(VFX_FALSE);
    setOpacity(0.0f);
}

void VappMsgDialogCell::playAnimation(VfxU32 start_seq)
{
    m_tl_init_opacity->setFromValue(0.0f);
    m_tl_init_opacity->setToValue(1.0f);
    m_tl_init_opacity->setStartDelay(start_seq * INIT_ANIMATION_DELAY);
    m_tl_init_opacity->setDuration(INIT_ANIMATION_DURATION);
    m_tl_init_opacity->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_tl_init_opacity->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_tl_init_opacity->setTarget(this);
    m_tl_init_opacity->m_signalStopped.connect(this, &VappMsgDialogCell::onTimelineStopped);
    m_tl_init_opacity->start();

    VfxS32 offset = (getSide() == VappMsgDialogCell::LEFT) ? -INIT_ANIMATION_OFFSET_X : INIT_ANIMATION_OFFSET_X;
    m_tl_init_pos_x->setFromValue(offset);
    m_tl_init_pos_x->setToValue(0);
    m_tl_init_pos_x->setStartDelay(start_seq * INIT_ANIMATION_DELAY);
    m_tl_init_pos_x->setDuration(INIT_ANIMATION_DURATION);
    m_tl_init_pos_x->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    m_tl_init_pos_x->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_POS_X);
    m_tl_init_pos_x->setTarget(this);
    m_tl_init_pos_x->start();
    
    //cell play animation 
    m_signalAnimationPlayed.postEmit();  
}

void VappMsgDialogCell::finishAnimation()
{    
    setOpacity(1.0f);
    setAutoAnimate(VFX_TRUE);
}

void VappMsgDialogCell::onInit()
{
    VcpVarHeightMenuCell::onInit();

    DEBUG_LAYOUT(this, m_menupos.pos % 2 ? VFX_COLOR_GREY : VFX_COLOR_SILVER);

    VFX_OBJ_CREATE(m_container, VfxFrame, this);
    DEBUG_LAYOUT(m_container, VFX_COLOR_RED);

    VFX_OBJ_CREATE(m_bubble, VfxFrame, m_container);
    m_bubble->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    VFX_OBJ_CREATE(m_bubbleMask, VfxFrame, m_container);
    m_bubbleMask->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_bubbleMask->setHidden(VFX_TRUE);
    DEBUG_LAYOUT(m_bubble, VFX_COLOR_GREEN);

    VFX_OBJ_CREATE(m_arrow, VfxFrame, m_container);
    m_arrow->setSize(BUBBLE_ARROW_WIDTH, BUBBLE_ARROW_HEIGHT);
    VFX_OBJ_CREATE(m_arrowMask, VfxFrame, m_container);
    m_arrowMask->setSize(BUBBLE_ARROW_WIDTH, BUBBLE_ARROW_HEIGHT);
    m_arrowMask->setHidden(VFX_TRUE);
    DEBUG_LAYOUT(m_arrow, VFX_COLOR_FUCHSIA);

    VFX_ALLOC_NEW(m_timeFontEffect, VfxFontEffect, this);
    m_timeFontEffect->setType(VFX_FONT_EFFECT_SHADOW);
    m_timeFontEffect->setShadow(
        VFX_COLOR_RES(BUBBLE_TIME_SHADOW_COLOR),
        BUBBLE_TIME_SHADOW_DEGREE,
        BUBBLE_TIME_SHADOW_DISTANCE,
        BUBBLE_TIME_SHADOW_RANGE,
        BUBBLE_TIME_SHADOW_INTENSITY
    );

    setSide(m_side, VFX_TRUE);   

    setAutoAnimate(VFX_TRUE);

    VFX_OBJ_CREATE(m_tl_init_opacity, VfxFloatTimeline, this);
    VFX_OBJ_CREATE(m_tl_init_pos_x, VfxS32Timeline, this);

    /* set size position of cell layout */
    reLayoutAllItems();

    if (getMenu()->hasAnimation() && !getMenu()->isAnimationPlayed())
    {
        prepareAnimation();
    }

    m_signalTapped.connect(this, &VappMsgDialogCell::onCellTapped);
}

void VappMsgDialogCell::onDeinit()
{
    VFX_DELETE(m_timeFontEffect);

    VcpVarHeightMenuCell::onDeinit();
}

void VappMsgDialogCell::onUpdate()
{
    VcpVarHeightMenuCell::onUpdate();

    setDisabled(isDisabled());
    
    if (VFX_TRUE == m_isUpdate)
    {        
        reLayoutAllItems();        
        m_isUpdate = VFX_FALSE;
    }
}

VfxRect VappMsgDialogCell::getHitRect()
{
    return convertRectFrom(m_bubble->getRect(), m_container);
}

void VappMsgDialogCell::setHighlight(VfxBool isHighlight)
{
    if (isHighlight && getStyle() != CHECKBOX)
    {
        if (RIGHT == m_side)
        {
            m_arrow->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_ARROW_RIGHT_HIGHLIGHT));
        }
        else
        {
            m_arrow->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_ARROW_LEFT_HIGHLIGHT));
        }
        m_bubble->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_BUBBLE_HIGHLIGHT));
    }
    else
    {
        if (RIGHT == m_side)
        {
            m_arrow->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_ARROW_RIGHT));
            m_bubble->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_BUBBLE_RIGHT));
        }
        else
        {
            m_arrow->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_ARROW_LEFT));
            m_bubble->setImgContent(VfxImageSrc(IMG_ID_VAPP_MSG_DIALOG_BUBBLE_LEFT));
        }    
    }
}

void VappMsgDialogCell::onBoundsChanged(VfxFrame *frame, const VfxRect &rect)
{
    if (this->getSize() == rect.size || this->getSize().isEmpty()) 
    {
        return;
    }

    VcpVarHeightMenuCell::onBoundsChanged(frame, rect);
    getMenu()->setItemHeight(m_menupos.pos, this->getSize().height);
    needRelayout();
}

VfxBool VappMsgDialogCell::isReadyForAnimation()
{
    return m_isReadyForAnimation;
}

void VappMsgDialogCell::setReadyForAnimation(VfxBool isReady)
{
    m_isReadyForAnimation = isReady;
}

void VappMsgDialogCell::needRelayout()
{
    if (!m_isUpdate)
    {
        m_isUpdate = VFX_TRUE;
        checkUpdate();
    }
}    

void VappMsgDialogCell::reLayoutAllItems()
{
    /* set widths */
    if (m_content)
    {
        m_content->setSize(getSize().width - BUBBLE_EXT_MARGIN_CB - BUBBLE_INT_MARGIN_LEFT - BUBBLE_INT_MARGIN_RIGHT - BUBBLE_EXT_MARGIN_RIGHT - BUBBLE_ARROW_WIDTH + 1, 0);
        forceUpdateContent();        

        /* set the cell body bg property */
        m_bubble->setSize(m_content->getSize().width + BUBBLE_INT_MARGIN_LEFT + BUBBLE_INT_MARGIN_RIGHT, 
                          m_content->getSize().height + BUBBLE_INT_MARGIN_TOP + BUBBLE_INT_MARGIN_BOTTOM);
    }

    /* set minimum width and height of the bubble */    
    if (m_bubble->getSize().width < BUBBLE_MIN_WIDTH)
    {
        m_bubble->setSize(BUBBLE_MIN_WIDTH, m_bubble->getSize().height);
    }
    if (m_bubble->getSize().height < BUBBLE_MIN_HEIGHT)
    {
        m_bubble->setSize(m_bubble->getSize().width, BUBBLE_MIN_HEIGHT);
    }

    /* set cell height */
    VfxS32 container_height = m_bubble->getSize().height;
    VfxS32 cell_height = m_bubble->getSize().height + BUBBLE_EXT_MARGIN_TOP + BUBBLE_EXT_MARGIN_BOTTOM + 
                         ( isTop()    ? BUBBLE_EXT_MARGIN_TOP_EXT    : 0 ) +
                         ( isBottom() ? BUBBLE_EXT_MARGIN_BOTTOM_EXT : 0 );
                         
    if (m_timeText) 
    {
        container_height += m_timeText->getSize().height + BUBBLE_TIME_MARGIN_TOP;
        cell_height += m_timeText->getSize().height + BUBBLE_TIME_MARGIN_TOP;
    }
    m_container->setSize(m_bubble->getSize().width + BUBBLE_ARROW_WIDTH, container_height);
    if (!m_content || m_content->getSize().height == 0)
       setSize(getSize().width, getMenu()->getItemHeight(m_menupos.pos));
    else
        setSize(getSize().width, cell_height);



    VfxS32 x = BUBBLE_EXT_MARGIN_LEFT;

    /* show/hide checkbox according to style */
    if (CHECKBOX == m_style)
    {
        /* on demand create checkbox */
        if (NULL == m_checkbox)
        {
            VFX_OBJ_CREATE(m_checkbox, VcpImageButton, this);
            m_checkbox->m_signalClicked.connect(this, &VappMsgDialogCell::onMarkClicked);
            m_checkbox->setSize(CHECKBOX_SIZE, CHECKBOX_SIZE);
            DEBUG_LAYOUT(m_checkbox, VFX_COLOR_RED);
        }
        m_checkbox->setPos(CHECKBOX_EXT_MARGIN_LEFT, CHECKBOX_EXT_MARGIN_TOP);

        /* set the background image of the bubble according to mark status */
        if (VFX_TRUE == m_isMarked)
        {
            m_checkbox->setImage(VcpStateImage(VCP_IMG_LIST_MENU_CHECK_BOX_ON));
        }
        else
        {
            m_checkbox->setImage(VcpStateImage(VCP_IMG_LIST_MENU_CHECK_BOX_OFF));
        }

        /* offset left bubble to accommodate the checkbox */
        if (LEFT == m_side)
        {
            x = BUBBLE_EXT_MARGIN_CB - BUBBLE_ARROW_WIDTH + 1;
        }
    }
    else
    {
        if (m_checkbox != NULL)
        {
            m_checkbox->setPos((VfxS32)CHECKBOX_EXT_MARGIN_LEFT - BUBBLE_EXT_MARGIN_CB, CHECKBOX_EXT_MARGIN_TOP);
        }
        m_isMarked = VFX_FALSE;
    }

    /* set the positions */
    VfxS32 a_x, b_x, c_x = 0, t_x = 0;
    if (RIGHT == m_side)
    {
        m_container->setAnchor(1.0f, 0.0f);
        m_arrow->setAnchor(1.0f, 0.5f);
        m_bubble->setAnchor(1.0f, 0.0f);
        x = getSize().width - BUBBLE_EXT_MARGIN_RIGHT;
        a_x = m_container->getSize().width;
        b_x = a_x - BUBBLE_ARROW_WIDTH + BUBBLE_ARROW_SPACING;
        if (m_content)
        {
            m_content->setAnchor(1.0f, 0.0f);
            c_x = b_x - BUBBLE_INT_MARGIN_RIGHT;
        }
        if (m_timeText)
        {
            m_timeText->setAnchor(1.0f, 0.0f);
            t_x = b_x - BUBBLE_TIME_OFFSET_RIGHT;
        }
    }
    else
    {
        m_arrow->setAnchor(0.0f, 0.5f);
        a_x = 0;
        b_x = a_x + BUBBLE_ARROW_WIDTH - BUBBLE_ARROW_SPACING;
        if (m_content)
        {
            c_x = b_x + BUBBLE_INT_MARGIN_LEFT;
        }
        if (m_timeText)
        {
            t_x = b_x + BUBBLE_TIME_OFFSET_LEFT;
        }
    }

    m_container->setPos(x, BUBBLE_EXT_MARGIN_TOP + (isTop() ? BUBBLE_EXT_MARGIN_TOP_EXT : 0));
    m_arrow->setPos(a_x, m_bubble->getSize().height / 2);
    m_bubble->setPos(b_x, 0);
    if (m_content)
    {
        m_content->setPos(c_x, BUBBLE_INT_MARGIN_TOP);
    }
    if (m_timeText)
    {
        m_timeText->setPos(t_x, m_bubble->getSize().height + BUBBLE_TIME_MARGIN_TOP);
    }

    if (m_isDisabled)
    {
        m_bubbleMask->setSize(m_bubble->getSize());
        m_bubbleMask->setAnchor(m_bubble->getAnchor());
        m_bubbleMask->setPos(m_bubble->getPos());
        m_arrowMask->setAnchor(m_arrow->getAnchor());
        m_arrowMask->setPos(m_arrow->getPos());
        m_bubbleMask->bringToFront();
        m_arrowMask->bringToFront();
        m_bubbleMask->setHidden(VFX_FALSE);
        m_arrowMask->setHidden(VFX_FALSE);
        if (m_timeText)
        {
            m_timeText->setOpacity(0.3f);
        }
        if (m_checkbox)
        {
            m_checkbox->setOpacity(0.3f);
        }
    }
    else
    {
        m_bubbleMask->setHidden(VFX_TRUE);
        m_arrowMask->setHidden(VFX_TRUE);
        if (m_timeText)
        {
            m_timeText->setOpacity(1.0f);
        }
        if (m_checkbox)
        {
            m_checkbox->setOpacity(1.0f);
        }
    }    
}

void VappMsgDialogCell::onMarkClicked(VfxObject *obj, VfxId id)
{
    if (getStyle() == CHECKBOX && !isDisabled())
    {
        m_isMarked = m_isMarked ? VFX_FALSE : VFX_TRUE;
        needRelayout();
        m_signalMarked.postEmit(this, m_isMarked);
    }
}

void VappMsgDialogCell::onContentBoundsChanged(VfxFrame *frame, const VfxRect &rect)
{
    if (m_content->getSize() == rect.size || m_content->getSize().isEmpty()) 
    {
        return;
    }

    needRelayout();
}

void VappMsgDialogCell::onCellTapped(VcpVarHeightMenuCell *varHeightCell)
{
    if (getStyle() == CHECKBOX && !isDisabled())
    {
        onMarkClicked(NULL, 0);
    }
}

void VappMsgDialogCell::onTimelineStopped(VfxBaseTimeline *timline, VfxBool isComplete)
{
    finishAnimation();
}
