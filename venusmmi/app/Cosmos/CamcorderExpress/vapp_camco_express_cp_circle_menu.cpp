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

#include "vapp_camco_express_cp_circle_menu.h"

#ifdef __VAPP_CAMCO_EXPRESS__

void VappCamcoCpDirectSettingMenu::onInit()
{
    VfxControl::onInit();

    setAnchor(0, 0.5);
    setAutoAnimate(VFX_FALSE);
    setBgColor(VRT_COLOR_TRANSPARENT);
    setIsZSortChild(VFX_TRUE);

    VFX_OBJ_CREATE(m_background, VfxFrame, this);
    m_background->setAnchor(0.5, 0.5);
    m_background->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_background->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_BG_ICON));
    m_background->setIsUnhittable(VFX_TRUE);

    VFX_OBJ_CREATE(m_ind, VfxImageFrame, this);
    m_ind->setAnchor(0.5, 0.5);
    m_ind->setImgContent(VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_IND_ICON));
    m_ind->setIsUnhittable(VFX_TRUE);

    for(VfxU32 i = 0; i < VAPP_CAMCO_CP_CIRCLE_MENU_MAX_CAOUNT; i++)
    {
        VFX_OBJ_CREATE(m_cell[i], VappCamcoCpRotatableImageButton, this);
        m_cell[i]->initProperty(0);
        m_cell[i]->m_signalClicked.connect(this, &VappCamcoCpDirectSettingMenu::onCellCliked);
    }

    m_count = 0;

    m_signalBoundsChanged.connect(this, &VappCamcoCpDirectSettingMenu::onBoundUpdate);
}

void VappCamcoCpDirectSettingMenu::onCellCliked(VfxObject* obj, VfxId id)
{
    for(VfxU32 i = 0; i < m_count; i++)
    {
        if(m_cell[i] == obj)
        {
            m_signalItemSet.emit(m_ID[i]);
            return;
        }
    }
}

void VappCamcoCpDirectSettingMenu::onBoundUpdate(VfxFrame * f, const VfxRect & R)
{
    if(m_isVerticalMode)
    {
        VfxU32 d = m_cell[0]->getSize().height;
        VfxU32 h = (m_cell[0]->getSize().height >>1) + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_TO_1ST_ICON;

        for(VfxU32 i = 0; i < m_count; i++)
        {
            m_cell[i]->setPos(getSize().width>>1, i * (d + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_BETWEEN_ICON) + h);
            if(m_focus == i)
            {
                m_ind->setPos(m_cell[i]->getPos().x, m_cell[i]->getPos().y + (m_cell[i]->getSize().height/2) + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_BETWEEN_IND);
            }
        }
        if(m_count)
        {
            m_background->setPos(
                getSize().width>>1,
                (m_cell[0]->getPos().y + m_cell[m_count-1]->getPos().y)/2);
            m_background->setSize(
                VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_BG_ICON).getSize().width,
                d * m_count + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_BETWEEN_ICON * (m_count - 1) + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_TO_1ST_ICON * 2);
        }
    }
    else
    {
        VfxU32 d = m_cell[0]->getSize().width;
        VfxU32 w = (m_cell[0]->getSize().width >>1) + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_TO_1ST_ICON;

        for(VfxU32 i = 0; i < m_count; i++)
        {
            m_cell[i]->setPos(i * (d + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_BETWEEN_ICON) + w, getSize().height>>1);
            if(m_focus == i)
            {
                m_ind->setPos(m_cell[i]->getPos().x, m_cell[i]->getPos().y + (m_cell[i]->getSize().height/2) + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_BETWEEN_IND);
            }
        }
        if(m_count)
        {
            m_background->setPos(
                (m_cell[0]->getPos().x + m_cell[m_count-1]->getPos().x)/2,
                getSize().height>>1);
            m_background->setSize(
                d * m_count + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_BETWEEN_ICON * (m_count - 1) + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_TO_1ST_ICON * 2,
                VfxImageSrc(IMG_ID_VAPP_CAMCO_SETTING_BG_ICON).getSize().height);
        }
    }
}

VfxU32 VappCamcoCpDirectSettingMenu::getDistanceTo1stItem(void)
{
    if(m_isVerticalMode)
    {
        return ((m_cell[0]->getSize().height >>1) + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_TO_1ST_ICON);
    }
    else
    {
        return ((m_cell[0]->getSize().width >>1) + VAPP_CAMCO_CP_CIRCLE_MENU_DIS_TO_1ST_ICON);
    }
}

void VappCamcoCpDirectSettingMenu::setVerticalMode(VfxBool isVertical, VfxBool isMirror)
{
    m_isVerticalMode = isVertical;
    m_isMirrorMode = isMirror;
    if(isVertical)
    {
        if(!isMirror)
            setAnchor(0.5, 0);
        else
            setAnchor(0.5, 1);
    }
    else
    {
        if(!isMirror)
            setAnchor(0, 0.5);
        else
            setAnchor(1, 0.5);
    }
}

VfxS32 VappCamcoCpDirectSettingMenu::getCount()
{
    return m_count;
}

void VappCamcoCpDirectSettingMenu::setCount(VfxS32 count)
{
    ASSERT(count < VAPP_CAMCO_CP_CIRCLE_MENU_MAX_CAOUNT);
    m_count = count;
}

void VappCamcoCpDirectSettingMenu::setCellData(VfxU32 idx, VfxU32 ID, VfxResId imgID)
{
    m_ID[idx] = ID;
    m_cell[idx]->initProperty(imgID);
    onBoundUpdate(this, getBounds());
}

void VappCamcoCpDirectSettingMenu::setFocusItem(VfxU32 idx)
{
    m_focus = idx;
    onBoundUpdate(this, getBounds());
}

#endif
