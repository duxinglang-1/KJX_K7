/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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

#include "vapp_camco_express_cp_advance_menu.h"
#ifdef __VAPP_CAMCO_EXPRESS__

void VappCamcoCpAdvanceMenuSlider::onInit()
{
    VfxControl::onInit();
    setBgColor(VFX_COLOR_TRANSPARENT);

    VFX_OBJ_CREATE(m_maxValue, VfxImageFrame, this);
    VFX_OBJ_CREATE(m_slider, VcpSlider, this);

    m_maxValue->setAnchor(0.5, 0.5);
    m_maxValue->setAutoAnimate(VFX_FALSE);
    m_maxValue->setIsUnhittable(VFX_TRUE);

    m_slider->setAnchor(0.5, 0.5);
    m_slider->setLayout(VCP_SLIDER_LAYOUT_HORZ);
    m_slider->setSliderMode(VCP_SLIDER_MODE_INTERACTIVE_DISCRETE);
    m_slider->setFuzzy(VFX_FALSE);

    setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    m_signalBoundsChanged.connect(this, &VappCamcoCpAdvanceMenuSlider::onBoundUpdate);
}

void VappCamcoCpAdvanceMenuSlider::onDeinit()
{
    VfxControl::onDeinit();
}

void VappCamcoCpAdvanceMenuSlider::onBoundUpdate(VfxFrame * f, const VfxRect & R)
{
    m_maxValue->setPos(
        VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV + (m_maxValue->getSize().width>>1),
        getSize().height>>1);

    m_slider->setPos(
        (getSize().width + m_maxValue->getSize().width + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV)/2,
        getSize().height>>1);
    m_slider->setLength(getSize().width - m_maxValue->getSize().width - VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV * 3);
}

VfxBool VappCamcoCpAdvanceMenuSlider::onContainPoint(const VfxPoint &point) const
{
    if(m_slider->getBounds().contains(point))
        return VFX_TRUE;
    else
        return VFX_FALSE;
}

VfxBool VappCamcoCpAdvanceMenuSlider::onPenAbortAccepted(VfxControl *aborter, VfxPenAbortReasonEnum reason)
{
    // no let scrollable get the pen
    return VFX_FALSE;
}

void VappCamcoCpAdvanceMenuBtnList::onInit()
{
    VcpScrollable::onInit();
    setBgColor(VFX_COLOR_TRANSPARENT);
    enableHorizontalScrollIndicator(VFX_FALSE);

    VFX_OBJ_CREATE(m_leftArrow, VfxImageFrame, this);
    addChildFrame((VfxFrame *) m_leftArrow);
    m_leftArrow->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_AD_SETTING_IND_ICON));
    m_leftArrow->setAnchor(0.5, 0.5);
    m_leftArrow->setIsUnhittable(VFX_TRUE);
    m_leftArrow->setAutoAnimate(VFX_FALSE);
    m_leftArrow->bringToFront();

    VfxTransform t;
    t.setIdentity();
    t.data.affine.sx = -1;
    m_leftArrow->setTransform(t);

    VFX_OBJ_CREATE(m_rightArrow, VfxImageFrame, this);
    addChildFrame((VfxFrame *) m_rightArrow);
    m_rightArrow->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_AD_SETTING_IND_ICON));
    m_rightArrow->setAnchor(0.5, 0.5);
    m_rightArrow->setIsUnhittable(VFX_TRUE);
    m_rightArrow->setAutoAnimate(VFX_FALSE);
    m_rightArrow->bringToFront();

    for(VfxU32 i = 0; i < VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_ITEM_CAOUNT; i++)
    {
        m_btn[i] = NULL;
        m_text[i] = NULL;
        m_Hilite[i] = NULL;
    }

    setAlignParent(
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE,
        VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_SIDE);

    m_signalScrolling.connect(this, &VappCamcoCpAdvanceMenuBtnList::notifyScrollStart);
    m_signalScrollStopped.connect(this, &VappCamcoCpAdvanceMenuBtnList::notifyScrollStop);

    list_type = VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_END;
}

void VappCamcoCpAdvanceMenuBtnList::onDeinit()
{
    VcpScrollable::onDeinit();
}

void VappCamcoCpAdvanceMenuBtnList::setListType(vapp_camco_cp_advance_menu_btn_list_type_enum type)
{
    list_type = type;
}

void VappCamcoCpAdvanceMenuBtnList::setListData(VfxU32 idx, VfxControl* btn, VfxTextFrame *text)
{
    if(list_type == VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_ICON_TEXT)
    {
        VcpImageButton *b = (VcpImageButton*)btn;

        m_btn[idx] = btn;
        m_text[idx] = text;

        b->setAnchor(0.5, 0.5);
        b->setAutoAnimate(VFX_FALSE);
        b->setIsEffect(VFX_TRUE);
        b->setEffectSize(VfxSize(b->getSize()));

        m_text[idx]->setAnchor(0.5, 0.5);
        m_text[idx]->setAutoAnimate(VFX_FALSE);
        m_text[idx]->setColor(VFX_COLOR_RES(VCP_COL_BTN_TXT_DEFAULT_NRML));
        VfxFontDesc font = m_text[idx]->getFont();
    #if defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(16);
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(14);
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(12);
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(12);
    #else
        font.size = VFX_FONT_DESC_VF_SIZE(12);
    #endif
        m_text[idx]->setFont(font);
        m_text[idx]->setAutoResized(VFX_FALSE);
        m_text[idx]->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_text[idx]->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_text[idx]->setIsUnhittable(VFX_TRUE);

        if(!m_Hilite[idx])
        {
            VFX_OBJ_CREATE(m_Hilite[idx], VfxFrame, this);
            //addChildFrame((VfxFrame *) m_Hilite[idx]);
            m_Hilite[idx]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            m_Hilite[idx]->setImgContent(VfxImageSrc(VCP_IMG_PHOTO_BORDER_FRAME_FG));
            m_Hilite[idx]->setIsUnhittable(VFX_TRUE);
            m_Hilite[idx]->setAnchor(0.5, 0.5);
            m_Hilite[idx]->bringToFront();
        }
    }
    else if(list_type == VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_TEXT_ONLY)
    {
        VcpButton *b = (VcpButton*)btn;

        m_btn[idx] = btn;
        m_text[idx] = text;

        b->setAnchor(0.5, 0.5);
        b->setAutoAnimate(VFX_FALSE);
        b->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        b->setIsAutoResized(VFX_FALSE);

        VfxFontDesc font = b->getTextFont();
    #if defined(VAPP_CAMCO_OSD_LAYOUT_WVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(18);
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_HVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(16);
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_WQVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(14);
    #elif defined(VAPP_CAMCO_OSD_LAYOUT_QVGA)
        font.size = VFX_FONT_DESC_VF_SIZE(14);
    #else
        font.size = VFX_FONT_DESC_VF_SIZE(14);
    #endif
        b->setTextFont(font);

        m_text[idx]->setFont(b->getTextFont());
        m_text[idx]->setAutoResized(VFX_TRUE);
        m_text[idx]->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_text[idx]->setHidden(VFX_TRUE);
        m_text[idx]->setIsUnhittable(VFX_TRUE);
    }
    else
    {
        ASSERT(0);
    }
}

void VappCamcoCpAdvanceMenuBtnList::setEnable(VfxU32 idx)
{
    if(list_type == VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_ICON_TEXT)
    {
        m_btn[idx]->setOpacity(1);
        m_text[idx]->setOpacity(1);
        m_btn[idx]->setIsDisabled(VFX_FALSE);
        m_btn[idx]->setBorder(VFX_COLOR_BLUE, 0);

        m_Hilite[idx]->setImgContent(VfxImageSrc(VCP_IMG_PHOTO_BORDER_FRAME_FG));
        m_Hilite[idx]->setPos(m_btn[idx]->getPos());
        m_Hilite[idx]->setSize(m_btn[idx]->getSize().width + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE*2, m_btn[idx]->getSize().height + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE*2);
    }
    else if(list_type == VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_TEXT_ONLY)
    {
        ((VcpButton*)m_btn[idx])->setStyle(VCP_BUTTON_STYLE_DEFAULT_01);
        ((VcpButton*)m_btn[idx])->setIsDisabled(VFX_FALSE);
    }
    else
    {
        ASSERT(0);
    }
}

void VappCamcoCpAdvanceMenuBtnList::setDisable(VfxU32 idx)
{
    if(list_type == VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_ICON_TEXT)
    {
        m_btn[idx]->setOpacity(0.3);
        m_text[idx]->setOpacity(0.3);
        m_btn[idx]->setIsDisabled(VFX_TRUE);
        m_btn[idx]->setBorder(VFX_COLOR_BLUE, 0);

        m_Hilite[idx]->setImgContent(VfxImageSrc(VCP_IMG_PHOTO_BORDER_FRAME_FG));
        m_Hilite[idx]->setPos(m_btn[idx]->getPos());
        m_Hilite[idx]->setSize(m_btn[idx]->getSize().width + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE*2, m_btn[idx]->getSize().height + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE*2);
    }
    else if(list_type == VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_TEXT_ONLY)
    {
        ((VcpButton*)m_btn[idx])->setStyle(VCP_BUTTON_STYLE_GREY);
        ((VcpButton*)m_btn[idx])->setIsDisabled(VFX_TRUE);
    }
    else
    {
        ASSERT(0);
    }
}

void VappCamcoCpAdvanceMenuBtnList::setHilite(VfxU32 idx)
{
    if(list_type == VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_ICON_TEXT)
    {
        m_btn[idx]->setOpacity(1);
        m_text[idx]->setOpacity(1);
        m_btn[idx]->setIsDisabled(VFX_FALSE);
        m_btn[idx]->setBorder(VFX_COLOR_BLUE, 0);

        m_Hilite[idx]->setImgContent(VfxImageSrc(VCP_IMG_PHOTO_BORDER_FRAME_FG_P));
        m_Hilite[idx]->setPos(m_btn[idx]->getPos());
        m_Hilite[idx]->setSize(m_btn[idx]->getSize().width + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE*2, m_btn[idx]->getSize().height + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE*2);
    }
    else if(list_type == VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_TEXT_ONLY)
    {
        ((VcpButton*)m_btn[idx])->setStyle(VCP_BUTTON_STYLE_DEFAULT_02);
        ((VcpButton*)m_btn[idx])->setIsDisabled(VFX_FALSE);
    }
    else
    {
        ASSERT(0);
    }
}

void VappCamcoCpAdvanceMenuBtnList::setContentSize(const VfxSize &size)
{
    VcpScrollable::setContentSize(size);

    if(getSize().width < size.width)
    {
        m_leftArrow->setPos((VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN/2), getSize().height / 2);
        m_rightArrow->setPos(getSize().width - (VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN/2), getSize().height / 2);

        if(getViewBounds().origin.x <= 0)
        {
            m_leftArrow->setHidden(VFX_TRUE);
        }
        else
        {
            m_leftArrow->setHidden(VFX_FALSE);
        }

        if(getViewBounds().origin.x >= size.width - getSize().width)
        {
            m_rightArrow->setHidden(VFX_TRUE);
        }
        else
        {
            m_rightArrow->setHidden(VFX_FALSE);
        }

    }
    else
    {
        m_leftArrow->setHidden(VFX_TRUE);
        m_rightArrow->setHidden(VFX_TRUE);
    }
}

void VappCamcoCpAdvanceMenuBtnList::notifyScrollStart(VcpScrollable *s)
{
    m_leftArrow->setHidden(VFX_TRUE);
    m_rightArrow->setHidden(VFX_TRUE);
}

void VappCamcoCpAdvanceMenuBtnList::notifyScrollStop(VcpScrollable *s)
{
    if(getSize().width < getContentSize().width)
    {
        m_leftArrow->setPos((VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN/2), getSize().height / 2);
        m_rightArrow->setPos(getSize().width - (VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN/2), getSize().height / 2);

        if(getViewBounds().origin.x <= (VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN/2))
        {
            m_leftArrow->setHidden(VFX_TRUE);
        }
        else
        {
            VfxBool isOverlap = VFX_FALSE;
            for(VfxU32 i = 0; i < VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_ITEM_CAOUNT; i++)
            {
                if(m_btn[i])
                {
                    VfxRect r  = m_btn[i]->getBounds();
                    r.origin.x = m_btn[i]->getPos().x - (m_btn[i]->getAnchor().x * m_btn[i]->getSize().width) - getViewBounds().origin.x;
                    r.origin.y = m_btn[i]->getPos().y - (m_btn[i]->getAnchor().y * m_btn[i]->getSize().height) - getViewBounds().origin.y;
                    VfxRect r2  = m_leftArrow->getBounds();
                    r2.origin.x = m_leftArrow->getPos().x - (m_leftArrow->getAnchor().x * m_leftArrow->getSize().width);
                    r2.origin.y = m_leftArrow->getPos().y - (m_leftArrow->getAnchor().y * m_leftArrow->getSize().height);
                    r.intersectWith(r2);

                    if(r.size.height >= 0 && r.size.width >= 0)
                    {
                        isOverlap = VFX_TRUE;
                        break;
                    }
                }
            }
            if(isOverlap)
                m_leftArrow->setHidden(VFX_TRUE);
            else
                m_leftArrow->setHidden(VFX_FALSE);
        }

        if(getViewBounds().origin.x >= getContentSize().width - getSize().width - (VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN/2))
        {
            m_rightArrow->setHidden(VFX_TRUE);
        }
        else
        {
            VfxBool isOverlap = VFX_FALSE;
            for(VfxU32 i = 0; i < VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_ITEM_CAOUNT; i++)
            {
                if(m_btn[i])
                {
                    VfxRect r  = m_btn[i]->getBounds();
                    r.origin.x = m_btn[i]->getPos().x - (m_btn[i]->getAnchor().x * m_btn[i]->getSize().width) - getViewBounds().origin.x;
                    r.origin.y = m_btn[i]->getPos().y - (m_btn[i]->getAnchor().y * m_btn[i]->getSize().height) - getViewBounds().origin.y;
                    VfxRect r2  = m_rightArrow->getBounds();
                    r2.origin.x = m_rightArrow->getPos().x - (m_rightArrow->getAnchor().x * m_rightArrow->getSize().width);;
                    r2.origin.y = m_rightArrow->getPos().y - (m_rightArrow->getAnchor().y * m_rightArrow->getSize().height);
                    r.intersectWith(r2);

                    if(r.size.height >= 0 && r.size.width >= 0)
                    {
                        isOverlap = VFX_TRUE;
                        break;
                    }
                }
            }
            if(isOverlap)
                m_rightArrow->setHidden(VFX_TRUE);
            else
                m_rightArrow->setHidden(VFX_FALSE);
        }
    }
    else
    {
        m_leftArrow->setHidden(VFX_TRUE);
        m_rightArrow->setHidden(VFX_TRUE);
    }
}

VfxBool VappCamcoCpAdvanceMenuBtnList::onContainPoint(const VfxPoint &point) const
{
    VfxControl *b = NULL;
    for(VfxU32 i = 0; i < VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_ITEM_CAOUNT; i++)
    {
        if(m_btn[i])
        {
            b = m_btn[i];
            if(m_btn[i]->getBounds().contains(point))
                return VFX_TRUE;
        }
    }
    if(b)
    {
        if((point.y > b->getPos().y - b->getAnchor().y * b->getSize().height) && (point.y < b->getPos().y + (1.0 - b->getAnchor().y) * b->getSize().height))
            return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappCamcoCpAdvanceMenu::onInit()
{
    Super::onInit();

    setAnchor(0.5, 0.5);
    setAutoAnimate(VFX_FALSE);
    setBgColor(VRT_COLOR_TRANSPARENT);

    VFX_OBJ_CREATE(m_form, VcpForm, this);

    m_form->setAnchor(0.5, 0.5);

    m_form->setTopShadowIsHidden(VFX_TRUE);

#if defined(__VAPP_CAMCO_HIGHEND_SETTING__)
    VfxColor c = m_form->getBgColor();
    c.setA(115);
    m_form->setBgColor(c);
#endif

    m_form->m_signalScrollStarted.connect(this, &VappCamcoCpAdvanceMenu::notifyScrollStart);

    for(VfxU32 i = 0; i < VAPP_CAMCO_CP_ADVANCE_MENU_MAX_CELL_CAOUNT; i++)
    {
        m_itemCount[i] = 0;
        VFX_OBJ_CREATE(m_cell[i], VcpFormItemCustomFrame, m_form);
        m_cell[i]->setBgColor(VRT_COLOR_TRANSPARENT);
    }
    for(VfxU32 i = 0; i < 4; i++)
    {
        VFX_OBJ_CREATE(m_shadow[i], VfxFrame, this);

        m_shadow[i]->setAnchor(0.5, 0.5);
        m_shadow[i]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_shadow[i]->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_AD_SETTING_SHADOW_ICON));
        m_shadow[i]->setIsUnhittable(VFX_TRUE);

        m_shadow[i]->setSize(
            VfxImageSrc(IMG_ID_VAPP_CAMCO_AD_SETTING_SHADOW_ICON).getSize().width,
            g_vapp_camco_skin.menuControlSize[1]);

        VfxTransform t;
        t.setIdentity();

        if(i == 0)
        {
            // up
            t.data.affine.rz = VFX_DEG_TO_RAD(270);
            m_shadow[i]->setTransform(t);
        }
        else if(i == 1)
        {
            // down
            t.data.affine.rz = VFX_DEG_TO_RAD(90);
            m_shadow[i]->setTransform(t);
        }
        else if(i == 2)
        {
            // left
            t.data.affine.rz = VFX_DEG_TO_RAD(180);
            m_shadow[i]->setTransform(t);
        }
        else if(i == 3)
        {
            // right
            t.data.affine.rz = VFX_DEG_TO_RAD(0);
            m_shadow[i]->setTransform(t);
        }
    }
    m_signalBoundsChanged.connect(this, &VappCamcoCpAdvanceMenu::onBoundUpdate);
}

void VappCamcoCpAdvanceMenu::onDeinit()
{
    Super::onDeinit();
}

void VappCamcoCpAdvanceMenu::onBoundUpdate(VfxFrame * f, const VfxRect & R)
{
    m_form->setSize(
        getSize().width - VfxImageSrc(IMG_ID_VAPP_CAMCO_AD_SETTING_SHADOW_ICON).getSize().width*2,
        getSize().height - VfxImageSrc(IMG_ID_VAPP_CAMCO_AD_SETTING_SHADOW_ICON).getSize().width*2);
    m_form->setPos(getSize().width/2, getSize().height/2);

    m_shadow[0]->setPos(getSize().width/2, VfxImageSrc(IMG_ID_VAPP_CAMCO_AD_SETTING_SHADOW_ICON).getSize().width/2);
    m_shadow[1]->setPos(getSize().width/2, getSize().height - VfxImageSrc(IMG_ID_VAPP_CAMCO_AD_SETTING_SHADOW_ICON).getSize().width/2);
    m_shadow[2]->setPos(VfxImageSrc(IMG_ID_VAPP_CAMCO_AD_SETTING_SHADOW_ICON).getSize().width/2, getSize().height/2);
    m_shadow[3]->setPos(getSize().width - VfxImageSrc(IMG_ID_VAPP_CAMCO_AD_SETTING_SHADOW_ICON).getSize().width/2, getSize().height/2);
}

void VappCamcoCpAdvanceMenu::notifyScrollStart(VcpScrollable* sender)
{
    m_signalItemSelected.emit(VAPP_CAMCO_CP_ADVANCE_MENU_DUMMY_SETTING, 0);
}

void VappCamcoCpAdvanceMenu::setCount(VfxS32 count)
{
    m_settingCount = count;
}

VfxU32 VappCamcoCpAdvanceMenu::getCount()
{
    return m_settingCount;
}

void VappCamcoCpAdvanceMenu::setItemCount(VfxU32 idx, VfxU32 Count)
{
    m_itemCount[idx] = Count;
}

VfxU32 VappCamcoCpAdvanceMenu::getItemCount(VfxU32 idx)
{
    return m_itemCount[idx];
}

void VappCamcoCpAdvanceMenu::setSettingData(VfxU32 idx, const vapp_camco_cp_advance_menu_cell_struct &data)
{
    memcpy(&m_settingList[idx], &data, sizeof(vapp_camco_cp_advance_menu_cell_struct));

    if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_NORMAL)
    {
        VappCamcoCpAdvanceMenuBtnList *scrollableFrame;
       // VcpFormItemCustomFrame *cusFrame;
       // VappCamcoCpAdvanceMenuBtnList *scrollable;

        VcpFormItemCaption *caption;
        VFX_OBJ_CREATE(caption, VcpFormItemCaption, m_form);
        caption->setText(data.text);
        caption->setIsUnhittable(VFX_TRUE);
        caption->setBgColor(VFX_COLOR_TRANSPARENT);
        caption->setIsUnhittable(VFX_TRUE);
        m_form->addItem(caption, (m_settingList[idx].ID * 100));

        VFX_OBJ_CREATE(scrollableFrame, VappCamcoCpAdvanceMenuBtnList, m_cell[idx]);
        scrollableFrame->setListType(VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_ICON_TEXT);

        m_cell[idx]->attachCustomFrame(scrollableFrame);
        m_form->addItem(m_cell[idx], (m_settingList[idx].ID * 100 + 1));
    }
    else if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_TEXT)
    {
        VappCamcoCpAdvanceMenuBtnList *scrollableFrame;
        //VcpFormItemCustomFrame *cusFrame;
        //VappCamcoCpAdvanceMenuBtnList *scrollable;

        VcpFormItemCaption *caption;
        VFX_OBJ_CREATE(caption, VcpFormItemCaption, m_form);
        caption->setText(data.text);
        caption->setIsUnhittable(VFX_TRUE);
        caption->setBgColor(VFX_COLOR_TRANSPARENT);
        caption->setIsUnhittable(VFX_TRUE);
        m_form->addItem(caption, (m_settingList[idx].ID * 100));

        VFX_OBJ_CREATE(scrollableFrame, VappCamcoCpAdvanceMenuBtnList, m_cell[idx]);
        scrollableFrame->setListType(VAPP_CAMCO_CP_ADVANCE_MENU_LIST_TYPE_TEXT_ONLY);

        m_cell[idx]->attachCustomFrame(scrollableFrame);
        m_form->addItem(m_cell[idx], (m_settingList[idx].ID * 100 + 1));
    }
    else if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_SLIDER)
    {
        VappCamcoCpAdvanceMenuSlider  *sliderFrame;

        VcpFormItemCaption *caption;
        VFX_OBJ_CREATE(caption, VcpFormItemCaption, m_form);
        caption->setText(data.text);
        caption->setIsUnhittable(VFX_TRUE);
        caption->setBgColor(VFX_COLOR_TRANSPARENT);
        caption->setIsUnhittable(VFX_TRUE);
        m_form->addItem(caption, (m_settingList[idx].ID * 100));

        VFX_OBJ_CREATE(sliderFrame, VappCamcoCpAdvanceMenuSlider, m_cell[idx]);

        sliderFrame->m_slider->m_signalThumbDrag.connect(this, &VappCamcoCpAdvanceMenu::onSliderMove);

        m_cell[idx]->attachCustomFrame(sliderFrame);
        m_form->addItem(m_cell[idx], (m_settingList[idx].ID * 100 + 1));
    }
    else if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_SWITCHER)
    {
        m_form->insertSeparator();

        VcpFormItemSwitchCell *switchCell;
        VFX_OBJ_CREATE(switchCell, VcpFormItemSwitchCell, m_form);

        switchCell->setSwitchStatus(VFX_FALSE);
        switchCell->setIsTappable(VFX_FALSE);
        switchCell->setMainText(data.text);
        switchCell->setBgColor(VFX_COLOR_TRANSPARENT);

        switchCell->m_signalSwitchChangeReq.connect(this, &VappCamcoCpAdvanceMenu::onSwitchChange);

        m_form->addItem(switchCell, (m_settingList[idx].ID * 100 + 1));
    }
    else
    {
        ASSERT(0);
    }
}

void VappCamcoCpAdvanceMenu::setItemData(VfxU32 idx, VfxU32 subIdx, const vapp_camco_cp_advance_menu_cell_struct &data)
{
    ASSERT(subIdx < m_itemCount[idx]);

    memcpy(&m_itemList[idx][subIdx], &data, sizeof(vapp_camco_cp_advance_menu_cell_struct));

    if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_NORMAL)
    {
        VcpFormItemCustomFrame *cusFrame;
        VappCamcoCpAdvanceMenuBtnList *scrollable;

        cusFrame = (VcpFormItemCustomFrame*)m_form->getItem(m_settingList[idx].ID * 100 + 1);
        scrollable = (VappCamcoCpAdvanceMenuBtnList*)cusFrame->getFrame();

        VcpImageButton *b;
        VfxTextFrame *t;

        VFX_OBJ_CREATE(b, VcpImageButton, scrollable);
        VFX_OBJ_CREATE(t, VfxTextFrame, scrollable);

        // set btn and text to list
        scrollable->setListData(subIdx, (VfxControl*)b, t);

        // set btn content and size
        VcpStateImage SI = VcpStateImage(data.img, data.img, data.img, data.img);
        b->setImage(SI);
        b->setSize(SI.getImageNormal().getSize().width, SI.getImageNormal().getSize().height);
        b->setEffectSize(VfxSize(b->getSize()));
        b->setPos(
            VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_ICON_DIS * (2 * subIdx + 1) / 2,
            VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV + (b->getSize().height>>1) + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE);
        b->setId(m_settingList[idx].ID * 100 + m_itemList[idx][subIdx].ID);
        b->m_signalClicked.connect(this, &VappCamcoCpAdvanceMenu::onSettingBtnClicked);
        b->setFuzzy(VFX_FALSE);

        // set text content and size
        t->setString(data.text);
        t->setSize(VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_ICON_DIS, SI.getImageNormal().getSize().height/2);
        t->setPos(
            b->getPos().x,
            (VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV * 1.5) + (VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE * 2) + b->getSize().height + (t->getSize().height >> 1));

        scrollable->setSize(
            m_form->getSize().width,
            (b->getSize().height + t->getSize().height + + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HILITE * 2 + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV * 2.2));

        scrollable->setContentSize(
            VfxSize(
                m_itemCount[idx] * VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_ICON_DIS,
                scrollable->getSize().height));

        m_cell[idx]->setHeight(scrollable->getSize().height);
        m_cell[idx]->setSize(scrollable->getSize());
    }
    else if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_TEXT)
    {

        VcpFormItemCustomFrame *cusFrame;
        VappCamcoCpAdvanceMenuBtnList *scrollable;

        cusFrame = (VcpFormItemCustomFrame*)m_form->getItem(m_settingList[idx].ID * 100 + 1);
        scrollable = (VappCamcoCpAdvanceMenuBtnList*)cusFrame->getFrame();

        VcpButton *b;
        VfxTextFrame *t;

        VFX_OBJ_CREATE(b, VcpButton, scrollable);
        VFX_OBJ_CREATE(t, VfxTextFrame, scrollable);

        // set btn and text to list
        scrollable->setListData(subIdx, (VfxControl*)b, t);

        // set text content and size
        t->setString(data.text);

        // set btn content and size
        b->setText(data.text);
        b->setId(m_settingList[idx].ID * 100 + m_itemList[idx][subIdx].ID);
        b->m_signalClicked.connect(this, &VappCamcoCpAdvanceMenu::onSettingBtnClicked);
        b->setFuzzy(VFX_FALSE);

        VfxU32 bW;
        if(m_itemCount[idx] != 3)
        {
            bW = (m_form->getSize().width -  (3 * VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV)) / 2;
        }
        else
        {
            bW = (m_form->getSize().width -  (4 * VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV)) / 3;
        }

        b->setSize(
            bW,
            VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HEIGHT);
        b->setPos(
            ((subIdx + 1) * VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN) + ((2 * subIdx + 1) * (b->getSize().width>>1)),
            VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BTN_HEIGHT/2 + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV);

        // layout
        VfxU32 L = bW + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN;

        scrollable->setSize(
            m_form->getSize().width,
            (b->getSize().height + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV*2));

        scrollable->setContentSize(
            VfxSize(
                m_itemCount[idx] * L + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN,
                scrollable->getSize().height));

        m_cell[idx]->setHeight(scrollable->getSize().height);
        m_cell[idx]->setSize(scrollable->getSize());
    }
    else if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_SLIDER)
    {
        VcpFormItemCustomFrame *cusFrame;
        VappCamcoCpAdvanceMenuSlider *slider;

        cusFrame = (VcpFormItemCustomFrame*)m_form->getItem(m_settingList[idx].ID * 100 + 1);
        slider = (VappCamcoCpAdvanceMenuSlider*)cusFrame->getFrame();

        slider->m_maxValue->setResId(IMG_ID_VAPP_CAMCO_EV_PLUS_ICON);
        if(slider->m_maxValue->getSize().height > slider->m_slider->getSize().height)
            slider->setSize(m_form->getSize().width, slider->m_maxValue->getSize().height + (VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV*2));
        else
            slider->setSize(m_form->getSize().width, slider->m_slider->getSize().height + (VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_VERT_DIV*2));
        m_cell[idx]->setHeight(slider->getSize().height);
        m_cell[idx]->setSize(slider->getSize());

        slider->m_maxValue->setPos(
            VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV + (slider->m_maxValue->getSize().width>>1),
            m_cell[idx]->getSize().height>>1);

        slider->m_slider->setPos(
            (m_cell[idx]->getSize().width + slider->m_maxValue->getSize().width + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV)/2,
            m_cell[idx]->getSize().height>>1);
        slider->m_slider->setLength(m_cell[idx]->getSize().width - slider->m_maxValue->getSize().width - VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV*3);
        slider->m_slider->setMaxValue(m_itemCount[idx] - 1);
    }
    else if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_SWITCHER)
    {
    }
    else
    {
        ASSERT(0);
    }
}

void VappCamcoCpAdvanceMenu::updateSettingData(VfxU32 idx, VfxU32 subIdx, const vapp_camco_cp_advance_menu_cell_status_struct &data, VfxBool isUpdateView)
{
    if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_NORMAL || m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_TEXT)
    {

        VcpFormItemCustomFrame *cusFrame = (VcpFormItemCustomFrame*)m_form->getItem(m_settingList[idx].ID * 100 + 1);
        VappCamcoCpAdvanceMenuBtnList *scrollable = (VappCamcoCpAdvanceMenuBtnList*)cusFrame->getFrame();

        if(data.isSettingEnable)
        {
            cusFrame->setIsDisabled(VFX_FALSE);
        }
        else
        {
            cusFrame->setIsDisabled(VFX_TRUE);
        }
        if(data.isItemEnable)
        {
            if(data.isItemSelected)
            {
                scrollable->setHilite(subIdx);

                if(isUpdateView && scrollable->getContentSize().width > m_form->getSize().width)
                {
                    // move the selected item to the 1st item
                    if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_NORMAL)
                    {
                        VfxU32 firstIndex = subIdx;
                        if(subIdx > m_itemCount[idx] - 4)
                            firstIndex = m_itemCount[idx] - 4;

                        scrollable->setContentOffset(VfxPoint(firstIndex * VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_ICON_DIS, 0));
                    }
                    else
                    {
                        VfxU32 bW;
                        VfxU32 firstIndex = subIdx;
                        if(m_itemCount[idx] != 3)
                        {
                            if(subIdx > m_itemCount[idx] - 2)
                                firstIndex = m_itemCount[idx] - 2;

                            bW = (m_form->getSize().width -  (3 * VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV)) / 2;
                        }
                        else
                        {
                            if(subIdx > m_itemCount[idx] - 3)
                                firstIndex = m_itemCount[idx] - 3;

                            bW = (m_form->getSize().width -  (4 * VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_HORZ_DIV)) / 3;
                        }
                        scrollable->setContentOffset(VfxPoint(firstIndex * (bW + VAPP_CAMCO_CP_ADVANCE_MENU_LAYOUT_SIZE_BETWEEN_BTN), 0));
                    }
                    // force update the arrow
                    scrollable->setContentSize(scrollable->getContentSize());
                }
            }
            else
            {
                scrollable->setEnable(subIdx);
            }
        }
        else
        {
            scrollable->setDisable(subIdx);
        }
        cusFrame->setBgColor(VRT_COLOR_TRANSPARENT);
    }
    else if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_SLIDER)
    {
        VcpFormItemCustomFrame *cusFrame;
        VappCamcoCpAdvanceMenuSlider *slider;
        cusFrame = (VcpFormItemCustomFrame*)m_form->getItem(m_settingList[idx].ID * 100 + 1);
        slider = (VappCamcoCpAdvanceMenuSlider*)cusFrame->getFrame();

        if(data.isSettingEnable)
        {
            cusFrame->setIsDisabled(VFX_FALSE);
            if(data.isItemSelected)
                slider->m_slider->setCurrentValue(subIdx);
        }
        else
        {
            cusFrame->setIsDisabled(VFX_TRUE);
        }
        cusFrame->setBgColor(VRT_COLOR_TRANSPARENT);
    }
    else if(m_settingList[idx].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_SWITCHER)
    {
        VcpFormItemSwitchCell *switcher;
        switcher = (VcpFormItemSwitchCell*)m_form->getItem(m_settingList[idx].ID * 100 + 1);

        if(data.isSettingEnable)
        {
            switcher->setIsDisabled(VFX_FALSE);
            if(data.isItemSelected && subIdx == 0)
            {
                switcher->setSwitchStatus(VFX_FALSE);
                switcher->setHintText(m_itemList[idx][subIdx].text);
            }
            else if(data.isItemSelected && subIdx == 1)
            {
                switcher->setSwitchStatus(VFX_TRUE);
                switcher->setHintText(m_itemList[idx][subIdx].text);
            }
        }
        else
        {
            switcher->setIsDisabled(VFX_TRUE);
        }
        switcher->setBgColor(VRT_COLOR_TRANSPARENT);
    }
    else
    {
        ASSERT(0);
    }
}

void VappCamcoCpAdvanceMenu::onSettingBtnClicked(VfxObject* obj, VfxId id)
{
    VfxU32 idx = (id/100);
    VfxU32 value = (id%100);

    m_signalItemSelected.emit(idx, value);
}

void VappCamcoCpAdvanceMenu::onSliderMove(VcpSlider *slider, VfxFloat value)
{
    for(VfxU32 i = 0; i <  m_settingCount; i++)
    {
        if(m_settingList[i].type == VAPP_CAMCO_CP_ADVANCE_MENU_CELL_TYPE_SLIDER)
        {
            VcpFormItemCustomFrame *cusFrame = (VcpFormItemCustomFrame*)m_form->getItem(m_settingList[i].ID * 100 + 1);
            VfxFrame* f = cusFrame->getFrame();

            VfxFrame *tempFrame = f->getFirstChildFrame();
            while (tempFrame)
            {
                if((VcpSlider*)tempFrame == slider)
                {
                    m_signalItemSelected.emit(m_settingList[i].ID, m_itemList[i][(VfxU32)(value+0.5)].ID);
                    return;
                }
                tempFrame = tempFrame->getNextFrame();
            }
        }
    }
}

void VappCamcoCpAdvanceMenu::onSwitchChange(VcpFormItemSwitchCell* item, VfxId id, VfxBool newStatus)
{
    // ON is 1, OFF is 0
    if(newStatus)
        m_signalItemSelected.emit(id/100, 1);
    else
        m_signalItemSelected.emit(id/100, 0);
    return;
}

#endif

