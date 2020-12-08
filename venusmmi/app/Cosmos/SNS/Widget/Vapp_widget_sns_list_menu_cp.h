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
 *   vapp_widget_sns_list_menu_cp.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements component used in the page.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#ifndef __VAPP_SNS_MENU_LIST_CP_H__
#define __VAPP_SNS_MENU_LIST_CP_H__

#include "MMI_features.h"
#if defined(__MMI_VUI_HOMESCREEN_SNS__)
#if defined (__MMI_VUI_WIDGET_SNS_TABBAR__)

#include "vapp_sns_base_cp.h"

#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_widget_sns_cosmos_def.h"
#include "vapp_sns_utility.h"

#define COL_ID_PHB_LIST VFX_COLOR_WHITE

/* List menu cell - used in VcpListMenu/VcpGroupListMenu list */
// VappSnsListMenuItemBase class declaration
class VappWidgetSnsListMenuItemBase : public VcpListMenuCellClientBaseFrame
{
    VFX_DECLARE_CLASS(VappWidgetSnsListMenuItemBase);

// Enum
public:
    enum {
    #if defined(__MMI_MAINLCD_240X320__) || defined (__MMI_MAINLCD_240X400__)
        DEFAULT_GAPS    = 3,
        IMG_WIDTH       = 40,
        IMG_HEIGHT      = 40,
        TEXT_WIDTH      = 150,
        ICON_WIDTH      = 9,
        ICON_HEIGHT     = 12,
        BTN_WIDTH       = 36,
        BTN_HEIGHT      = 36,
    #elif defined(__MMI_MAINLCD_320X480__)    
        DEFAULT_GAPS    = 5,
        IMG_WIDTH       = 45,
        IMG_HEIGHT      = 45,
        TEXT_WIDTH      = 150,
        ICON_WIDTH      = 11,
        ICON_HEIGHT     = 13,
        BTN_WIDTH       = 40,
        BTN_HEIGHT      = 40,
    #elif defined(__MMI_MAINLCD_480X800__)
        DEFAULT_GAPS    = 14,
        IMG_WIDTH       = 60,
        IMG_HEIGHT      = 60,
        TEXT_WIDTH      = 200,
        ICON_WIDTH      = 18,
        ICON_HEIGHT     = 18,
        BTN_WIDTH       = 50,
        BTN_HEIGHT      = 50,
    #endif
    };

    enum ListModeEnum
    {
        VCP_LIST_MENU_CELL_STYLE_REMOVE,
        VCP_LIST_MENU_CELL_STYLE_ADD,
        VCP_LIST_MENU_CELL_STYLE_ADD_DISABLE,
        VCP_LIST_MENU_CELL_STYLE_TOTAL
    };
    
// Constructor / Destructor
public:
    // Default constructor
    VappWidgetSnsListMenuItemBase(ListModeEnum listMode = VCP_LIST_MENU_CELL_STYLE_ADD);

// Overridable
public:
    virtual void onCreateElements(void);
    virtual void onCloseElements(void);
    virtual void onLayoutElements(void);
    virtual void onUpdateElements(void);

// Implementation
public:

    // Set list mode
    void setListMode(ListModeEnum listMode);

    VcpButton *setButtonId(VfxU32 id);
    
// Variable
private:

    ListModeEnum m_listMode;
    // Image frame
    VappSnsPhotoBorderFrame *m_imageFrame;

    // Text frame
    VfxTextFrame *m_textFrame;
    VfxTextFrame *m_subText1;

    VcpButton *m_button;
    
    // Icon frame1
    VfxImageFrame *m_iconFrame1;
    VfxFrame *m_disableFrame1;

};

/* List menu cell - used in VcpListMenu/VcpGroupListMenu list */
// VappSnsListMenuItemBase Implementation
VFX_IMPLEMENT_CLASS("VappWidgetSnsListMenuItemBase", VappWidgetSnsListMenuItemBase, VcpListMenuCellClientBaseFrame);
VappWidgetSnsListMenuItemBase::VappWidgetSnsListMenuItemBase(ListModeEnum listMode) :
    m_listMode(listMode),
    m_imageFrame(NULL),
    m_textFrame(NULL),
    m_subText1(NULL),
    m_button(NULL),
    m_iconFrame1(NULL),
    m_disableFrame1(NULL)
{

}

void VappWidgetSnsListMenuItemBase::onCreateElements()
{
    /* common  */
    if (!m_textFrame)
    {
        VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
    }

    if (VCP_LIST_MENU_CELL_STYLE_REMOVE == m_listMode)
    {
        if (!m_imageFrame)
        {
            VFX_OBJ_CREATE(m_imageFrame, VappSnsPhotoBorderFrame, this);
        }

        if (!m_button)
        {
            VFX_OBJ_CREATE(m_button, VcpButton, this);
            m_button->setId(getCell()->m_pos);
        }
    }   
    else
    {
        if (!m_subText1)
        {
            VFX_OBJ_CREATE(m_subText1, VfxTextFrame, this);
        }

        if (!m_iconFrame1)
        {
            VFX_OBJ_CREATE(m_iconFrame1, VfxImageFrame, this);
        }
    }

    if (VCP_LIST_MENU_CELL_STYLE_ADD_DISABLE== m_listMode)
    {
        if (!m_disableFrame1)
        {
            VFX_OBJ_CREATE(m_disableFrame1, VfxFrame, this);
        }
    }
}

void VappWidgetSnsListMenuItemBase::onCloseElements()
{
    if (m_imageFrame)
    {
        VFX_OBJ_CLOSE(m_imageFrame);
    }

    if (m_textFrame)
    {
        VFX_OBJ_CLOSE(m_textFrame);
    }

    if (m_subText1)
    {
        VFX_OBJ_CLOSE(m_subText1);
    }

    if (m_button)
    {
        VFX_OBJ_CLOSE(m_button);
    }

    
    if (m_iconFrame1)
    {
        VFX_OBJ_CLOSE(m_iconFrame1);
    }

    if (m_disableFrame1)
    {
        VFX_OBJ_CLOSE(m_disableFrame1);
    }

}

void VappWidgetSnsListMenuItemBase::onLayoutElements()
{
    if (m_imageFrame)
    {
        m_imageFrame->setAnchor(0.0, 0.5);
        m_imageFrame->setPos(DEFAULT_GAPS, getSize().height/2);
        m_imageFrame->setSize(VfxSize(IMG_WIDTH, IMG_HEIGHT));
        m_imageFrame->setMaxSize(VfxSize(IMG_WIDTH, IMG_HEIGHT));
        m_imageFrame->setAlignParent(
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_SIDE, 
                VFX_FRAME_ALIGNER_MODE_NONE, 
                VFX_FRAME_ALIGNER_MODE_NONE);
    }

    if (m_textFrame)
    {
        m_textFrame->setAnchor(0.0, 0.5);
        if (m_imageFrame)
        {
            m_textFrame->setPos(m_imageFrame->getSize().width + DEFAULT_GAPS * 4, getSize().height/2);
        }
        else
        {
            m_textFrame->setPos(DEFAULT_GAPS, getSize().height/2);
        }
        m_textFrame->setSize(getSize().width - IMG_WIDTH - DEFAULT_GAPS * 4 - BTN_WIDTH - DEFAULT_GAPS * 2, getSize().height);
        m_textFrame->setAutoResized(VFX_TRUE);
    }
    
    if (m_subText1)
    {
        m_textFrame->setAnchor(0.0, 0.5);
        m_textFrame->setPos(DEFAULT_GAPS, getSize().height * 1 / 3);
        m_textFrame->setSize(getSize().width - DEFAULT_GAPS * 4 - ICON_WIDTH - DEFAULT_GAPS * 2, getSize().height * 2 / 3);
        m_textFrame->setAutoResized(VFX_TRUE);

        m_subText1->setAnchor(0.0, 0.5);
        m_subText1->setPos(DEFAULT_GAPS, getSize().height * 2 / 3);
        m_subText1->setSize(getSize().width - DEFAULT_GAPS * 4 - ICON_WIDTH - DEFAULT_GAPS * 2, getSize().height / 3);
        m_subText1->setAutoResized(VFX_TRUE);
        m_subText1->setString(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_SNS_AT_MOST_CONTACT));
    }

    VfxU32 iconPosX = getSize().width - DEFAULT_GAPS;
    VfxU32 iconPosY = (getSize().height - 2 * DEFAULT_GAPS - ICON_HEIGHT)/2;

    if (m_button)
    {
        VcpStateImage imgList;
        imgList.setImage(
            VfxImageSrc(SNS_IMG(SNS_EXT_VCP_IMG_BUTTON_DELETE)),
            VfxImageSrc(SNS_IMG(SNS_EXT_VCP_IMG_BUTTON_DELETE)),
            VfxImageSrc(SNS_IMG(SNS_EXT_VCP_IMG_BUTTON_DELETE)),
            VfxImageSrc(SNS_IMG(SNS_EXT_VCP_IMG_BUTTON_DELETE)));
        m_button->setImage(imgList);
        m_button->setRect(VfxRect(getSize().width - DEFAULT_GAPS - BTN_WIDTH, (getSize().height - BTN_HEIGHT)/2, BTN_WIDTH, BTN_HEIGHT));
        m_button->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    }
    
    
    if (m_iconFrame1)
    {
        m_iconFrame1->setAnchor(1.0, 0.5);
        m_iconFrame1->setPos(getSize().width - DEFAULT_GAPS, getSize().height/2);
        m_iconFrame1->setSize(ICON_WIDTH, ICON_HEIGHT);
    }

    if (m_disableFrame1)
	{
        m_disableFrame1->setRect(0, 0, getBounds().getWidth(), getBounds().getHeight());
        m_disableFrame1->setBgColor(VFX_COLOR_RES(SNS_CLR(SNS_EXT_VCP_COL_LIST_MENU_DISABLE_FG)));
        m_disableFrame1->setOpacity(0.5f);
    }
        
}

void VappWidgetSnsListMenuItemBase::onUpdateElements()
{
    IVcpListMenuContentProviderInt *contentProvider = getContentProvider();

    VfxImageSrc image;
    VfxWString text;

    if (contentProvider)
    {
        if (m_imageFrame)
        {
            VcpListMenuTextColorEnum color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
            contentProvider->getItemText(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON, text, color);
            m_imageFrame->setImgContent(text);   
            m_imageFrame->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_MAX_SIZE);
            m_imageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
            m_imageFrame->setIsUnhittable(VFX_TRUE);
        }
        
        if (m_textFrame)
        {
            VcpListMenuTextColorEnum color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
            
            text.setNull();
            contentProvider->getItemText(getCell()->m_pos, VCP_LIST_MENU_FIELD_TEXT, text, color);

            m_textFrame->setString(text);
            m_textFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCP_LIST_MENU_FONT_SIZE_MEDIUM)));
            m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
            m_textFrame->setColor(getCell()->getTextColor(color));
        }

        if (m_subText1)
        {
            VcpListMenuTextColorEnum color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
            
            text.setNull();
            contentProvider->getItemText(getCell()->m_pos, VCP_LIST_MENU_FIELD_SUB_TEXT1, text, color);

            m_subText1->setString(text);
            m_subText1->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCP_LIST_MENU_FONT_SIZE_SMALL)));
            m_subText1->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            m_subText1->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
            m_subText1->setColor(getCell()->getTextColor(color));

        }
        
        if (m_iconFrame1)
        {
            image.setNull();
            if (getCell()->m_isHighlight)
            {
                contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON_EXTRA2, image);
            }
            else
            {
                contentProvider->getItemImage(getCell()->m_pos, VCP_LIST_MENU_FIELD_ICON_EXTRA1, image);
            }
            m_iconFrame1->setImgContent(image);   
            m_iconFrame1->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        }

        if (m_disableFrame1)
        {
            m_disableFrame1->bringToFront();
        }
    }       
}



void VappWidgetSnsListMenuItemBase::setListMode(ListModeEnum listMode)
{
    m_listMode = listMode;
}

VcpButton *VappWidgetSnsListMenuItemBase::setButtonId(VfxU32 id)
{
    if (m_button)
    {
        m_button->setId(id);
    }
    return m_button;  
}

#endif /* #if defined (__MMI_VUI_WIDGET_SNS_TABBAR__) */
#endif /* __MMI_VUI_HOMESCREEN_SNS__ */
#endif 
