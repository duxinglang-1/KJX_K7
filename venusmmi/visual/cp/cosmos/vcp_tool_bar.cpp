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
 *  vcp_tool_bar.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Toolbar/Function bar component
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
extern "C"
{
    #include "GlobalResDef.h"
}

#include "vfx_uc_include.h"
#include "vcp_include.h"
//#include "vcp_state_image_visual.h"
//#include "..\..\..\visual\custom\mtk\vcp_state_image_visual.h"
#include "vcp_res.h"
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vcp_tool_bar.h"
#include "vfx_class_info.h"
#include "vfx_page_bar.h"
#include "vfx_datatype.h"
#include "vcp_button.h"
#include "string.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "mmi_rp_srv_venus_component_tool_bar_def.h"
#include "vfx_image_src.h"
#include "vfx_string.h"
//#include "vfx_visual.h"
#include "vcp_state_image.h"
#include "vfx_font_desc.h"
#include "vfx_signal.h"
#include "kal_public_api.h"
#include "vrt_datatype.h"

// For SWLA logs
#if defined(__MTK_TARGET__) && defined(__VENUS_SWLA_DBG_ON__)
	#define __MAUI_SOFTWARE_LA__
#endif // __MTK_TARGET__ && __VENUS_SWLA_DBG_ON__

#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}
#endif


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpToolBar 
 *****************************************************************************/  
VFX_IMPLEMENT_CLASS("VcpToolBar", VcpToolBar, VfxPageBar);

VcpToolBar::VcpToolBar():
    m_count(0),
    m_segmentButtonBaseFrame(NULL),
    m_rowHeight(0),
    m_lowerFrame(NULL),
    m_upperFrame(NULL),
    m_foldButton(NULL),
    m_normalButtonCount(0),
    m_segmentButtonCount(0),
    m_layout(VFX_SCR_ROTATE_TYPE_NORMAL),
    m_foldTimer(NULL),
    m_isFolded(VFX_TRUE),
    m_translucent(VFX_FALSE),
    m_isFoldDisabled(VFX_FALSE)
{
    memset(m_buttonArray, 0, sizeof(VcpButton*) * VCP_TOOL_BAR_MAX_BUTTONS_COUNT);
}


void VcpToolBar::onInit()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB1", SA_start);
#endif
    VfxPageBar::onInit();

    setAutoAnimate(VFX_TRUE);

    m_rowHeight = VCP_TOOL_BAR_HEIGHT;

    setPos(VfxPoint(VCP_TOOL_BAR_X, VCP_TOOL_BAR_Y));
    VfxPageBar::setBounds(VfxRect(0,0, VCP_TOOL_BAR_PORTRAIT_WIDTH, VCP_TOOL_BAR_HEIGHT));

#if defined(__MMI_VUI_COSMOS_CP__)
    VfxFrame * shadowFrame;
    VFX_OBJ_CREATE(shadowFrame, VfxFrame, this);
    shadowFrame->setImgContent(VfxImageSrc(VCP_IMG_TOOL_BAR_SHADOW));
    shadowFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    shadowFrame->setSize(getSize().width, VCP_TOOL_BAR_SHADOW_HEIGHT);
    setShadowFrame(shadowFrame);
#endif

    //setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    //setImgContent(VfxImageSrc(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
    //setIsCached(VFX_TRUE);

    VFX_OBJ_CREATE(m_upperFrame, VfxFrame, this);
    m_upperFrame->setPos(0, 0);
    m_upperFrame->setSize(VCP_TOOL_BAR_PORTRAIT_WIDTH, VCP_TOOL_BAR_HEIGHT);
    m_upperFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_upperFrame->setImgContent(VfxImageSrc(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
    m_upperFrame->setIsCached(VFX_TRUE);

    VFX_OBJ_CREATE(m_lowerFrame, VfxFrame, this);
    m_lowerFrame->setPos(0, 0);
    m_lowerFrame->setSize(VCP_TOOL_BAR_PORTRAIT_WIDTH, VCP_TOOL_BAR_HEIGHT);
    m_lowerFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_lowerFrame->setImgContent(VfxImageSrc(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
    m_lowerFrame->setIsCached(VFX_TRUE);
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB1", SA_stop);
#endif
}


VfxBool VcpToolBar::addItemStruct(const VcpToolBarItemStruct &item)
{
    return addItem(item.id, item.string, item.icon);
}


VfxBool VcpToolBar::addItem(VfxId buttonId, const VfxWString &buttonString, VfxResId buttonIcon, VfxId beforeId)
{
    return addItem(buttonId, buttonString, VfxImageSrc(NULL), beforeId, buttonIcon);
}

/* vaib mem reduction*/
VfxBool VcpToolBar::addItem(VfxId buttonId, VfxResId buttonString, VfxResId buttonIcon, VfxId beforeId)
{
    return addItem(buttonId, VFX_WSTR_RES(buttonString), VfxImageSrc(NULL), beforeId, buttonIcon);
}

/* vaib mem reduction*/
VfxBool VcpToolBar::addItem(VfxId buttonId, const VfxWChar* buttonString, VfxResId buttonIcon, VfxId beforeId)
{
    return addItem(buttonId, VFX_WSTR_MEM(buttonString), VfxImageSrc(NULL), beforeId, buttonIcon);
}

VfxBool VcpToolBar::addItem(VfxId buttonId, const VfxWString &buttonString, const VfxImageSrc &buttonIconSrc, VfxId beforeId)
{
    return addItem(buttonId, buttonString, buttonIconSrc, beforeId, -1);
}

/* vaib mem reduction*/
VfxBool VcpToolBar::addItem(VfxId buttonId, VfxResId buttonString, const VfxImageSrc &buttonIconSrc, VfxId beforeId)
{
    return addItem(buttonId, VFX_WSTR_RES(buttonString), buttonIconSrc, beforeId, -1);
}

/* vaib mem reduction*/
VfxBool VcpToolBar::addItem(VfxId buttonId, const VfxWChar* buttonString, const VfxImageSrc &buttonIconSrc, VfxId beforeId)
{
    return addItem(buttonId, VFX_WSTR_MEM(buttonString), buttonIconSrc, beforeId, -1);
}

void VcpToolBar::addItemButtonInt(VfxU32 index, VfxFrame *barFrame)
{
    VFX_OBJ_CREATE(m_buttonArray[index], VcpButton, barFrame);
    m_buttonArray[index]->m_signalClicked.connect(this, &VcpToolBar::onItemClick);
    m_buttonArray[index]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_TOP);
    VfxFontDesc font_desc;
    font_desc.size = VFX_FONT_DESC_VF_SIZE(VCP_TOOL_BAR_BUTTON_FONT_SIZE);
    m_buttonArray[index]->setTextFont(font_desc);
    m_buttonArray[index]->setTextColor(VfxColor(255, 255, 255, 255));
    m_buttonArray[index]->setMargin(VCP_TOOL_BAR_BUTTON_FONT_MARGIN_LEFT, 
                                  VCP_TOOL_BAR_BUTTON_FONT_MARGIN_UP, 
                                  VCP_TOOL_BAR_BUTTON_FONT_MARGIN_RIGHT, 
                                  VCP_TOOL_BAR_BUTTON_FONT_MARGIN_DOWN);
}


void VcpToolBar::addFoldButtonInt()
{
    VFX_OBJ_CREATE(m_foldButton, VcpButton, m_lowerFrame);
    m_foldButton->setId(VCP_TOOL_BAR_FOLD_BUTTON_ID);
    m_foldButton->setText(VFX_WSTR_RES(VCP_STR_TOOL_BAR_MORE));
    
    VcpStateImage img_list = VcpStateImage(VCP_IMG_TOOL_BAR_COMMON_ITEM_MORE);
    m_foldButton->setImage(img_list);
    m_foldButton->setHidden(VFX_TRUE);
    m_foldButton->m_signalClicked.connect(this, &VcpToolBar::onFoldButtonClick);
    
    m_foldButton->setPos((VCP_TOOL_BAR_SCREEN_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS) * (VCP_TOOL_BAR_MAX_ROW_BUTTONS - 1), 0);
    m_foldButton->setBounds(0, 0, (VCP_TOOL_BAR_SCREEN_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS), VCP_TOOL_BAR_HEIGHT);
    m_foldButton->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_TOP);
    
    VfxFontDesc font_desc;
    font_desc.size = VFX_FONT_DESC_VF_SIZE(VCP_TOOL_BAR_BUTTON_FONT_SIZE);
    m_foldButton->setTextFont(font_desc);
    m_foldButton->setTextColor(VfxColor(255, 255, 255, 255));
    m_foldButton->setMargin(VCP_TOOL_BAR_BUTTON_FONT_MARGIN_LEFT, 
                            VCP_TOOL_BAR_BUTTON_FONT_MARGIN_UP, 
                            VCP_TOOL_BAR_BUTTON_FONT_MARGIN_RIGHT, 
                            VCP_TOOL_BAR_BUTTON_FONT_MARGIN_DOWN);
    if(!m_translucent)
    {
        m_foldButton->setBgImageList(VcpStateImage(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL, 
                                                    VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED, 
                                                    VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED, 
                                                    VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
    }
    else
    {
        m_foldButton->setBgImageList(VcpStateImage(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL_TRANSLUCENT, 
                                                    VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED_TRANSLUCENT, 
                                                    VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED_TRANSLUCENT, 
                                                    VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL_TRANSLUCENT));
    }

}


VfxBool VcpToolBar::addItem(VfxId buttonId, const VfxWString &buttonString, const VfxImageSrc &buttonIconSrc, VfxId beforeId, VfxResId buttonIcon)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB2", SA_start);
#endif
    VfxU32 new_index = m_normalButtonCount;
    if((m_count == VCP_TOOL_BAR_MAX_BUTTONS_COUNT) || ((buttonIcon != -1) && !buttonIcon))
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TB2", SA_stop);
#endif
        return VFX_FALSE;
    }

    //Check if the VfxID is unique i.e. this button is not already in the toolbar.
    for(VfxU32 i = 0; i < m_normalButtonCount; i++)
    {
        if(m_buttonArray[i]->getId() == buttonId)
        {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TB2", SA_stop);
#endif
            return VFX_FALSE;
        }
    }

    //Check for the button is to be placed before some other button.
    if(beforeId != VCP_TOOL_BAR_INVALID_ID)
    {
        for(VfxU32 i = 0; i < m_normalButtonCount; i++)
        {
            if(m_buttonArray[i]->getId() == beforeId)
            {
                new_index = i;
				VcpButton *tempButton = m_buttonArray[m_normalButtonCount];
                for(VfxU32 j = m_normalButtonCount; j > i; j--)
                {
                    m_buttonArray[j] = m_buttonArray[j-1];
                }
				if(tempButton)
                {    
					m_buttonArray[i] = tempButton;
                }
                else
                {
                    m_buttonArray[i] = NULL;
                }
                break;
            }
        }
    }

    if((m_layout == VFX_SCR_ROTATE_TYPE_LANDSCAPE) || (m_layout == VFX_SCR_ROTATE_TYPE_90)) // Landscape    
    {
        if(!m_buttonArray[new_index])
        {
            addItemButtonInt(new_index, m_lowerFrame);
        }
        else
        {
            m_lowerFrame->addChildFrame(m_buttonArray[new_index]);
        }
    }
    else // Portrait
    {
        VfxU32 new_position = new_index + m_segmentButtonCount;

        if(m_count > VCP_TOOL_BAR_MAX_ROW_BUTTONS)  // Fold button
        {
            if(new_position >= VCP_TOOL_BAR_MAX_ROW_BUTTONS)
            {
                new_position++;
            }
        }

        if(new_position < VCP_TOOL_BAR_MAX_ROW_BUTTONS)
        {
            // If segment button, check for the row
            if(m_segmentButtonCount)
            {
                if(m_count < VCP_TOOL_BAR_MAX_ROW_BUTTONS)
                {
                    if(!m_buttonArray[new_index])
                    {
                        addItemButtonInt(new_index, m_lowerFrame);
                    }
                    else
                    {
                        m_lowerFrame->addChildFrame(m_buttonArray[new_index]);
                    }
                }
                else if(m_count == VCP_TOOL_BAR_MAX_ROW_BUTTONS)
                {
                    if(!m_buttonArray[new_index])
                    {
                        addItemButtonInt(new_index, m_lowerFrame);
                    }
                    else
                    {
                        m_lowerFrame->addChildFrame(m_buttonArray[new_index]);
                    }
                    m_upperFrame->addChildFrame(m_buttonArray[VCP_TOOL_BAR_MAX_ROW_BUTTONS - m_segmentButtonCount]);
                }
                else // Fold button exists, so new button will be placed in the upper row.
                {
                    if(!m_buttonArray[new_index])
                    {
                        addItemButtonInt(new_index, m_upperFrame);
                    }
                    else
                    {
                        m_upperFrame->addChildFrame(m_buttonArray[new_index]);
                    }
                }
            }
            else
            {
                if(m_count < VCP_TOOL_BAR_MAX_ROW_BUTTONS)
                {
                    if(!m_buttonArray[new_index])
                    {
                        addItemButtonInt(new_index, m_lowerFrame);
                    }
                    else
                    {
                        m_lowerFrame->addChildFrame(m_buttonArray[new_index]);
                    }
                }
                else if(m_count == VCP_TOOL_BAR_MAX_ROW_BUTTONS)
                {
                    if(!m_buttonArray[new_index])
                    {
                        addItemButtonInt(new_index, m_lowerFrame);
                    }
                    else
                    {
                        m_lowerFrame->addChildFrame(m_buttonArray[new_index]);
                        m_upperFrame->addChildFrame(m_buttonArray[VCP_TOOL_BAR_MAX_ROW_BUTTONS]);
                    }
                }
                else // Fold button exists.
                {
                    if(!m_buttonArray[new_index])
                    {
                        addItemButtonInt(new_index, m_lowerFrame);
                    }
                    else
                    {
                        m_lowerFrame->addChildFrame(m_buttonArray[new_index]);
                    }
                    m_upperFrame->addChildFrame(m_buttonArray[VCP_TOOL_BAR_MAX_ROW_BUTTONS - 1]);
                }
            }
        }
        else
        {
            if(!m_buttonArray[new_index])
            {
                addItemButtonInt(new_index, m_upperFrame);
            }
            else
            {
                m_upperFrame->addChildFrame(m_buttonArray[new_index]);
            }
        }
    }
    
    m_buttonArray[new_index]->setId(buttonId);
    m_buttonArray[new_index]->setText(buttonString);

    if(buttonIcon != -1)
    {
        m_buttonArray[new_index]->setImage(VcpStateImage(buttonIcon));
    }
    else
    {
        VcpStateImage temp = VcpStateImage();
        temp.setImage(buttonIconSrc, buttonIconSrc, buttonIconSrc, buttonIconSrc);
        m_buttonArray[new_index]->setImage(temp);
    }
    
    m_buttonArray[new_index]->setHidden(VFX_TRUE);
    m_buttonArray[new_index]->setIsDisabled(VFX_FALSE);
    if(!m_translucent)
    {
        m_buttonArray[new_index]->setBgImageList(VcpStateImage(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
    }
    else
    {
        m_buttonArray[new_index]->setBgImageList(VcpStateImage(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL_TRANSLUCENT, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED_TRANSLUCENT, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED_TRANSLUCENT, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL_TRANSLUCENT));
    }

    m_normalButtonCount++;
    m_count++;

    if((m_count == VCP_TOOL_BAR_MAX_ROW_BUTTONS + 1) && 
        (m_layout == VFX_SCR_ROTATE_TYPE_NORMAL || m_layout == VFX_SCR_ROTATE_TYPE_180))
    {
        // Fold button drawing in addItem() only once, it will just hide/show in onUpdate().
        if(!m_foldButton)
        {
            addFoldButtonInt();
        }
        m_upperFrame->addChildFrame(m_buttonArray[m_normalButtonCount - 2]);
    }

    checkUpdate();
    if(VfxAutoAnimate::getDisable())
    {    
        processUpdate();
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB2", SA_stop);
#endif
    return VFX_TRUE;
}


VfxBool VcpToolBar::changeItem(VfxId buttonId, const VfxWString &buttonString, VfxResId buttonIcon)
{
    return changeItem(buttonId, buttonString, VfxImageSrc(NULL), buttonIcon);
}

/* vaib mem reduction*/
VfxBool VcpToolBar::changeItem(VfxId buttonId, VfxResId buttonString, VfxResId buttonIcon)
{
    return changeItem(buttonId, VFX_WSTR_RES(buttonString), VfxImageSrc(NULL), buttonIcon);
}

/* vaib mem reduction*/
VfxBool VcpToolBar::changeItem(VfxId buttonId, const VfxWChar* buttonString, VfxResId buttonIcon)
{
    return changeItem(buttonId, VFX_WSTR_MEM(buttonString), VfxImageSrc(NULL), buttonIcon);
}

VfxBool VcpToolBar::changeItem(VfxId buttonId, const VfxWString &buttonString, const VfxImageSrc &buttonIconSrc)
{
    return changeItem(buttonId, buttonString, buttonIconSrc, -1);
}

/* vaib mem reduction*/
VfxBool VcpToolBar::changeItem(VfxId buttonId, VfxResId buttonString, const VfxImageSrc &buttonIconSrc)
{
    return changeItem(buttonId, VFX_WSTR_RES(buttonString), buttonIconSrc, -1);
}

/* vaib mem reduction*/
VfxBool VcpToolBar::changeItem(VfxId buttonId, const VfxWChar* buttonString, const VfxImageSrc &buttonIconSrc)
{
    return changeItem(buttonId, VFX_WSTR_MEM(buttonString), buttonIconSrc, -1);
}

VfxBool VcpToolBar::changeItem(VfxId buttonId, const VfxWString &buttonString, const VfxImageSrc &buttonIconSrc, VfxResId buttonIcon)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB3", SA_start);
#endif
    if((m_count == VCP_TOOL_BAR_MAX_BUTTONS_COUNT) || ((buttonIcon != -1) && !buttonIcon))
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TB3", SA_stop);
#endif
        return VFX_FALSE;
    }

    VfxS32 changeIndex = -1; 
    //Check if the VfxID is unique i.e. this button is already not in the toolbar.
    for(VfxU32 i = 0; i < m_normalButtonCount; i++)
    {
        if(m_buttonArray[i]->getId() == buttonId)
        {
            changeIndex = i;
            break;
        }
    }

    if (changeIndex == -1)
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TB3", SA_stop);
#endif
        return VFX_FALSE;
    }

    m_buttonArray[changeIndex]->setText(buttonString);

    if(buttonIcon != -1)
    {
        m_buttonArray[changeIndex]->setImage(VcpStateImage(buttonIcon));
    }
    else
    {
        VcpStateImage temp = VcpStateImage();
        temp.setImage(buttonIconSrc, buttonIconSrc, buttonIconSrc, buttonIconSrc);
        m_buttonArray[changeIndex]->setImage(temp);
    }
    
    checkUpdate();
    if(VfxAutoAnimate::getDisable())
    {    
        processUpdate();
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB3", SA_stop);
#endif
    return VFX_TRUE;
}


VcpToolBarDisableEnum VcpToolBar::getIsItemDisabled(VfxId buttonId)
{
    if(m_normalButtonCount == 0)
    {
        return VCP_TOOL_BAR_ITEM_NOT_EXIST;
    }

    // Search  VfxID.
    for(VfxU32 i = 0; i < m_normalButtonCount; i++)
    {
        if(m_buttonArray[i]->getId() == buttonId)
        {
            return m_buttonArray[i]->getIsDisabled() ? VCP_TOOL_BAR_ITEM_DISABLED : VCP_TOOL_BAR_ITEM_ENABLED;
        }
    }

    return VCP_TOOL_BAR_ITEM_NOT_EXIST;
}
      
        
VfxFrame* VcpToolBar::addControlFrame(VcpToolBarSegmentButtonCountEnum buttonCount)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB4", SA_start);
#endif
    if((m_segmentButtonCount != 0) ||                         // Only one segment button is supported
        (buttonCount < VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_BASE) ||
        (buttonCount > VCP_TOOL_BAR_SEGMENT_BUTTON_COUNT_MAX) ||           // No of buttons inside a segment button can either be 2 or 3
        ((m_count + VCP_TOOL_BAR_MAX_SEGMENT_BUTTONS_COUNT) > VCP_TOOL_BAR_MAX_BUTTONS_COUNT))     // Tool bar already full
    {
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TB4", SA_stop);
#endif
        return NULL;
    }

    // Initialize Segment button frame
    if(!m_segmentButtonBaseFrame)
    {
        VFX_OBJ_CREATE(m_segmentButtonBaseFrame, VfxFrame, m_lowerFrame);
        m_segmentButtonBaseFrame->setPos(VCP_TOOL_BAR_SEGMENT_BUTTON_GAP, VCP_TOOL_BAR_SEGMENT_BUTTON_GAP);
        m_segmentButtonBaseFrame->setBounds(0, 0, 
            ((VCP_TOOL_BAR_SCREEN_WIDTH/VCP_TOOL_BAR_MAX_ROW_BUTTONS) * VCP_TOOL_BAR_MAX_SEGMENT_BUTTONS_COUNT) - (VCP_TOOL_BAR_SEGMENT_BUTTON_GAP * 2), 
            m_rowHeight - (VCP_TOOL_BAR_SEGMENT_BUTTON_GAP * 2));
    }
    m_segmentButtonBaseFrame->setHidden(VFX_TRUE);

    m_segmentButtonCount = VCP_TOOL_BAR_MAX_SEGMENT_BUTTONS_COUNT;
    m_count += m_segmentButtonCount;

    // Add Fold button
    if((m_count >= VCP_TOOL_BAR_MAX_ROW_BUTTONS + 1) && 
        (m_layout == VFX_SCR_ROTATE_TYPE_NORMAL || m_layout == VFX_SCR_ROTATE_TYPE_180))
    {
        if(!m_foldButton)
        {
            addFoldButtonInt();
        }

        VfxS32 lower_button_count;
        VfxS32 buttons_to_move = 0, cur = 0;
        cur = VCP_TOOL_BAR_MAX_ROW_BUTTONS - m_segmentButtonCount - 1; // 1 For fold button

        lower_button_count = m_count - m_segmentButtonCount;
        if(lower_button_count > VCP_TOOL_BAR_MAX_ROW_BUTTONS)
        {
           lower_button_count = VCP_TOOL_BAR_MAX_ROW_BUTTONS - 1; // 1 For fold button
        }

        buttons_to_move = lower_button_count - cur;

        for(VfxS32 i = 0; i < buttons_to_move; i++)
        {
            m_upperFrame->addChildFrame(m_buttonArray[i + cur]);
        }
    }

    // Reposition other buttons
    checkUpdate();
    if(VfxAutoAnimate::getDisable())
    {    
        processUpdate();
    }
    
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB4", SA_stop);
#endif
    return m_segmentButtonBaseFrame;
}


VfxBool VcpToolBar::removeItem(VfxId buttonId)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB5", SA_start);
#endif
    for(VfxS32 i = 0; i < m_normalButtonCount; i++)
    {
        if(buttonId == m_buttonArray[i]->getId())
        {
            m_buttonArray[i]->setHidden(VFX_TRUE);
            VcpButton *tempButton = m_buttonArray[i];

            // Reset other button's position
            // (Remove Fold button)
            m_count--;
            m_normalButtonCount--;

            for(VfxS32 j = i; j < m_normalButtonCount; j++)
            {
                m_buttonArray[j] = m_buttonArray[j + 1];
            }
            m_buttonArray[m_normalButtonCount] = tempButton;

            if((m_count == VCP_TOOL_BAR_MAX_ROW_BUTTONS) && 
                (m_layout == VFX_SCR_ROTATE_TYPE_NORMAL || m_layout == VFX_SCR_ROTATE_TYPE_180))
            {
                m_lowerFrame->addChildFrame(m_buttonArray[m_normalButtonCount - 1]); // Last item
                if(m_normalButtonCount - 1)
                {
                    m_lowerFrame->addChildFrame(m_buttonArray[m_normalButtonCount - 2]); // Last to last item
                }
                m_foldButton->setHidden(VFX_TRUE);
                switchFoldMode();
            }
            else if (m_count > VCP_TOOL_BAR_MAX_ROW_BUTTONS)
            {
                VfxS32 lower_button_count = 0;
                lower_button_count = VCP_TOOL_BAR_MAX_ROW_BUTTONS - m_segmentButtonCount - 1;
                
                if((lower_button_count - 1) == i)
                {
                    m_lowerFrame->addChildFrame(m_buttonArray[i]);
                }
            }

            if(m_count)
            {
                checkUpdate();
                if(VfxAutoAnimate::getDisable())
                {    
                    processUpdate();
                }
            }
            
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TB5", SA_stop);
#endif
            return VFX_TRUE;
        }
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB5", SA_stop);
#endif
    return VFX_FALSE;
}


VfxBool VcpToolBar::removeControlFrame(void)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB6", SA_start);
#endif
    if(m_segmentButtonCount)
    {
        // Check for button re-shuffle
        VfxS32 buttons_to_move = 0, cur = 0;

        if(m_count >= (VCP_TOOL_BAR_MAX_ROW_BUTTONS + 1))
        {
            cur = VCP_TOOL_BAR_MAX_ROW_BUTTONS - m_segmentButtonCount - 1; // 1 For fold button
            buttons_to_move = m_normalButtonCount - cur;
            if(m_normalButtonCount > VCP_TOOL_BAR_MAX_ROW_BUTTONS)
            {
                buttons_to_move = VCP_TOOL_BAR_MAX_ROW_BUTTONS - 1 - cur; // 1 For fold button
            }
        }

        m_count -= m_segmentButtonCount;

        // (Remove Fold button)
        if(m_layout == VFX_SCR_ROTATE_TYPE_NORMAL || m_layout == VFX_SCR_ROTATE_TYPE_180)
        {
            for(VfxS32 i = 0; i < buttons_to_move; i++)
            {
                m_lowerFrame->addChildFrame(m_buttonArray[i + cur]);
            }

            if(m_count <= VCP_TOOL_BAR_MAX_ROW_BUTTONS)
            {
                if(m_foldButton)
                {
                    m_foldButton->setHidden(VFX_TRUE);
                }
                switchFoldMode();
            }
        }

        m_segmentButtonCount = 0;
        m_segmentButtonBaseFrame->setHidden(VFX_TRUE);

        // Reposition buttons
        if(m_count)
        {
            checkUpdate();
            if(VfxAutoAnimate::getDisable())
            {    
                processUpdate();
            }
        }
        
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TB6", SA_stop);
#endif
        return VFX_TRUE;
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB6", SA_stop);
#endif
    return VFX_FALSE;
}


void VcpToolBar::removeAllItems()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB7", SA_start);
#endif
    for(VfxS32 i = 0; i < m_normalButtonCount; i++)
    {
        m_buttonArray[i]->setHidden(VFX_TRUE);
    }
    if(m_foldButton) 
    {
        m_foldButton->setHidden(VFX_TRUE);
    }
    if(m_segmentButtonBaseFrame) 
    {
        m_segmentButtonBaseFrame->setHidden(VFX_TRUE);
    }
    m_count = 0;
    m_normalButtonCount = 0;
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB7", SA_stop);
#endif
}


VfxBool VcpToolBar::isFolded(void) const
{
    return m_isFolded;
}


void VcpToolBar::switchFoldMode(void)
{
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TB8", SA_start);
#endif    
    if(m_count <= VCP_TOOL_BAR_MAX_ROW_BUTTONS)
    {
        if(m_isFolded)
        {
#ifdef __MAUI_SOFTWARE_LA__
                        SLA_CustomLogging("TB8", SA_stop);
#endif    
            return;
        }
        m_isFolded = VFX_TRUE;
    }
    else
    {
        m_isFolded = !m_isFolded;
    }
    resetLayout();
    checkUpdate();
    if(VfxAutoAnimate::getDisable())
    {    
        processUpdate();
    }
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("TB8", SA_stop);
#endif    
}

void VcpToolBar::resetLayout(void)
{
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("TB9", SA_start);
#endif    
    if(!m_isFolded)
    {
        // Stop animation
        VfxAutoAnimate::begin();
        VfxAutoAnimate::setDisable(VFX_TRUE);
        m_lowerFrame->setPos(VfxPoint(0, 0));
        VfxAutoAnimate::commit();

        m_lowerFrame->setAutoAnimate(VFX_TRUE);
        
        // Start animation
        VfxAutoAnimate::initAnimateBegin();
        VfxPageBar::setBounds(VfxRect(0, 0, getSize().width, m_rowHeight * 2));
        setPos(VfxPoint(0, getPos().y - m_rowHeight));
        m_lowerFrame->setPos(VfxPoint(0, m_rowHeight));
        VfxAutoAnimate::initAnimateEnd();

        if(m_foldButton)
        {
            VcpStateImage img_list = VcpStateImage(VCP_IMG_TOOL_BAR_COMMON_ITEM_FOLD);
            m_foldButton->setImage(img_list);
            m_foldButton->setText(VFX_WSTR_RES(VCP_STR_TOOL_BAR_FOLD));
        }
        m_upperFrame->setHidden(VFX_FALSE);
    }
    else
    {
        // Start animation
        VfxAutoAnimate::initAnimateBegin();
        setPos(VfxPoint(0, getPos().y + m_rowHeight));
        VfxPageBar::setBounds(VfxRect(0, 0, getSize().width, m_rowHeight));
        m_lowerFrame->setPos(VfxPoint(0, 0));
        VfxAutoAnimate::initAnimateEnd();

        VfxMsec dur = 0;
        dur = VfxAutoAnimate::getDuration();

        // Check if More button is pressed again while animation didn't complete!!! 
        if(m_foldTimer)
        {
            m_foldTimer->stop();
        }
        else
        {
            VFX_OBJ_CREATE(m_foldTimer, VfxTimer, this);
        }
        m_foldTimer->setStartDelay(dur);
        m_foldTimer->m_signalTick.connect(this, &VcpToolBar::onFoldedTimer);
        m_foldTimer->start();

        if(m_foldButton)
        {
            VcpStateImage img_list = VcpStateImage(VCP_IMG_TOOL_BAR_COMMON_ITEM_MORE);
            m_foldButton->setImage(img_list);
            m_foldButton->setText(VFX_WSTR_RES(VCP_STR_TOOL_BAR_MORE));
        }
    }
#ifdef __MAUI_SOFTWARE_LA__
                    SLA_CustomLogging("TB9", SA_stop);
#endif    
}


void VcpToolBar::onFoldedTimer(VfxTimer *timer)
{
    VFX_UNUSED(timer);
    VFX_OBJ_CLOSE(m_foldTimer);
    m_foldTimer = NULL;
    if(m_isFolded)
    {
        m_upperFrame->setHidden(VFX_TRUE);
    }
}


void VcpToolBar::show()
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB0", SA_start);
#endif
    //VFX_ASSERT(m_count);
    VFX_ASSERT(m_rowHeight);

    
    VfxU32 bar_width = getSize().width;

    switch(m_layout)
    {
        case VFX_SCR_ROTATE_TYPE_NORMAL:
        case VFX_SCR_ROTATE_TYPE_180:
        {
            VfxU32 segment_button_width = 0, normal_button_width = 0, row_button_count = 0;

            // Lower row
            if(m_segmentButtonCount)
            {
                segment_button_width = m_segmentButtonBaseFrame->getSize().width + (2 * VCP_TOOL_BAR_SEGMENT_BUTTON_GAP);
                m_segmentButtonBaseFrame->setHidden(VFX_FALSE);
            }

            if(!m_normalButtonCount)
            {
#ifdef __MAUI_SOFTWARE_LA__
                SLA_CustomLogging("TB0", SA_stop);
#endif
                return;
            }

            if(m_count > VCP_TOOL_BAR_MAX_ROW_BUTTONS)
            {
                row_button_count = (VCP_TOOL_BAR_MAX_ROW_BUTTONS - m_segmentButtonCount) - 1; // 1 for fold button
                normal_button_width = (bar_width - segment_button_width)/(row_button_count + 1); // 1 for uniform width
                m_foldButton->setHidden(VFX_FALSE);
                m_foldButton->bringToFront();
            }
            else
            {
                row_button_count = m_normalButtonCount;
                normal_button_width = (bar_width - segment_button_width)/row_button_count; // 1 for uniform width
                if(bar_width > (normal_button_width * row_button_count))
                {
                    normal_button_width++;
                }
            }
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE); // disable auto animation while the buttons are repositioning
            
            VfxU32 i = 0;
            for(; i < row_button_count; i++)
            {
                m_buttonArray[i]->setPos(segment_button_width + (normal_button_width * i), 0);
                if((i == (row_button_count - 1)) && (normal_button_width > (bar_width - normal_button_width * (row_button_count - 1) - segment_button_width)))
                {
                    normal_button_width = bar_width - normal_button_width * (row_button_count - 1) - segment_button_width;
                }
                m_buttonArray[i]->setBounds(0, 0, normal_button_width, m_rowHeight);
                m_buttonArray[i]->setHidden(VFX_FALSE);
            }

            if(m_count > VCP_TOOL_BAR_MAX_ROW_BUTTONS)
            {
                // Upper row
                row_button_count = m_normalButtonCount - row_button_count;
                normal_button_width = bar_width/row_button_count;
                if(bar_width > (normal_button_width * row_button_count))
                {
                    normal_button_width++;
                }

                for(VfxU32 j = 0; j < row_button_count; j++, i++)
                {
                    m_buttonArray[i]->setPos(normal_button_width * j, 0);
                    if((j == (row_button_count - 1)) && (normal_button_width > (bar_width - normal_button_width * (row_button_count - 1))))
                    {
                        normal_button_width = bar_width - normal_button_width * (row_button_count - 1);
                    }
                    m_buttonArray[i]->setBounds(0, 0, normal_button_width, m_rowHeight);
                    m_buttonArray[i]->setHidden(VFX_FALSE);
                }
            }
            VfxAutoAnimate::commit();
            break;
        }        

        case VFX_SCR_ROTATE_TYPE_LANDSCAPE:
        case VFX_SCR_ROTATE_TYPE_90:
        {
            VfxU32 normal_button_width, normal_button_offset = 0;
            VfxU32 i = 0;
            VfxU32 segment_button_width = 0;

            normal_button_width = bar_width / m_count; // 1 pixel for uniform width
            if(bar_width > (normal_button_width * m_count))
            {
                normal_button_width++;
            }

            // Draw Segment button space
            if(m_segmentButtonCount)
            {
                
                normal_button_width = bar_width / VCP_TOOL_BAR_MAX_BUTTONS_COUNT; // 1 pixel for uniform width
                segment_button_width = m_segmentButtonBaseFrame->getSize().width + (2 * VCP_TOOL_BAR_SEGMENT_BUTTON_GAP);
                m_segmentButtonBaseFrame->setHidden(VFX_FALSE);
                normal_button_offset = normal_button_width * VCP_TOOL_BAR_MAX_SEGMENT_BUTTONS_COUNT;
                normal_button_width = (m_normalButtonCount ? (((bar_width - normal_button_offset)/ m_normalButtonCount)): normal_button_width);
                if(bar_width > (normal_button_width * m_normalButtonCount))
                {
                    normal_button_width++;
                }
            }

            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(VFX_TRUE);  // disable auto animation while the buttons are repositioning
            // Draw buttons on lower row 
            for(i = 0; i < m_normalButtonCount; i++)
            {
                m_buttonArray[i]->setPos(normal_button_width * i + normal_button_offset, 0);
                if((i == (m_normalButtonCount - 1)) && (normal_button_width > (bar_width - normal_button_width * (m_normalButtonCount - 1) - segment_button_width)))
                {
                    normal_button_width = bar_width - normal_button_width * (m_normalButtonCount - 1) - segment_button_width;
                }
                m_buttonArray[i]->setBounds(0, 0, normal_button_width, m_rowHeight);
                m_buttonArray[i]->setHidden(VFX_FALSE);
            }
            VfxAutoAnimate::commit();
            break;
        }

        default:
            // Layout not supported
            VFX_ASSERT(0);
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TB0", SA_stop);
#endif
}


void VcpToolBar::onItemClick(VfxObject *obj, VfxId id)
{

    m_signalButtonTap.emit(this, id);
}


void VcpToolBar::onFoldButtonClick(VfxObject *obj, VfxId id)
{
    switchFoldMode();
    m_signalBarFolded.emit(this, m_isFolded);
}


VfxBool VcpToolBar::setDisableItemStruct(const VcpToolBarDisableItemStruct &item)
{
    return setDisableItem(item.id, item.is_disable);
}


VfxBool VcpToolBar::setDisableItem(VfxId id, VfxBool isEnable)
{
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TBa", SA_start);
#endif    
    VfxS32 index = -1;

    for(VfxU32 i = 0; i < m_normalButtonCount; i++)
    {
        if(m_buttonArray[i]->getId() == id)
        {
            index = i;
            break;
        }
    }

    if(index == -1) 
    {
#ifdef __MAUI_SOFTWARE_LA__
                    SLA_CustomLogging("TBa", SA_stop);
#endif    
        return VFX_FALSE;
    }

    m_buttonArray[index]->setIsDisabled(isEnable);
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TBa", SA_stop);
#endif    
    return VFX_TRUE;
}
void VcpToolBar::setDisableFoldButton(VfxBool isDisabled)
{
    if(m_isFoldDisabled != isDisabled)
    {
        m_isFoldDisabled = isDisabled;
        checkUpdate();
    }   
}
VfxBool VcpToolBar::getIsFoldButtonDisabled()
{
    return m_isFoldDisabled;
}


void VcpToolBar::onSetTranslucent(VfxBool translucent)
{
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TBb", SA_start);
#endif    
    if (m_translucent == translucent)
    {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TBb", SA_stop);
#endif    
        return;
    }

    m_translucent = translucent;
    if(m_isFolded)
    {
        m_upperFrame->setHidden(VFX_TRUE);
    }

    if(m_translucent)
    {
        m_lowerFrame->setImgContent(VfxImageSrc(0));
        m_upperFrame->setImgContent(VfxImageSrc(0));
        if(m_foldButton)
        {
            m_foldButton->setBgImageList(VcpStateImage(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL_TRANSLUCENT, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED_TRANSLUCENT, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED_TRANSLUCENT, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL_TRANSLUCENT));
        }
        for(VfxS32 i = 0; i < m_normalButtonCount; i++)
        {
            m_buttonArray[i]->setBgImageList(VcpStateImage(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL_TRANSLUCENT, 
                                                            VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED_TRANSLUCENT, 
                                                            VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED_TRANSLUCENT, 
                                                            VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL_TRANSLUCENT));
        }
    }
    else
    {
        m_lowerFrame->setImgContent(VfxImageSrc(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
        m_upperFrame->setImgContent(VfxImageSrc(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
        if(m_foldButton)
        {
            m_foldButton->setBgImageList(VcpStateImage(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED, 
                                                        VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
        }
        for(VfxS32 i = 0; i < m_normalButtonCount; i++)
        {
            m_buttonArray[i]->setBgImageList(VcpStateImage(VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL, 
                                                            VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED, 
                                                            VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED, 
                                                            VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL));
        }
    }

    checkUpdate();
    if(VfxAutoAnimate::getDisable())
    {    
        processUpdate();
    }
#ifdef __MAUI_SOFTWARE_LA__
        SLA_CustomLogging("TBb", SA_stop);
#endif    
}


void VcpToolBar::onUpdate()
{
#ifdef __MAUI_SOFTWARE_LA__
SLA_CustomLogging("TBc", SA_start);
#endif    
    if((m_layout == VFX_SCR_ROTATE_TYPE_NORMAL || m_layout == VFX_SCR_ROTATE_TYPE_180)
        && (m_count >= VCP_TOOL_BAR_MAX_ROW_BUTTONS + 1))
    {
        for(VfxU32 i = VCP_TOOL_BAR_MAX_ROW_BUTTONS - m_segmentButtonCount - 1; i < m_normalButtonCount; i++)
        {
            m_upperFrame->addChildFrame(m_buttonArray[i]);
        }
        if(!m_foldButton)
        {
            addFoldButtonInt();
        }
            if(m_isFolded)
            {
                VcpStateImage img_list = VcpStateImage(VCP_IMG_TOOL_BAR_COMMON_ITEM_MORE);
                m_foldButton->setImage(img_list);
                m_foldButton->setText(VFX_WSTR_RES(VCP_STR_TOOL_BAR_MORE));
            }
            else
            {
                VcpStateImage img_list = VcpStateImage(VCP_IMG_TOOL_BAR_COMMON_ITEM_FOLD);
                m_foldButton->setImage(img_list);
                m_foldButton->setText(VFX_WSTR_RES(VCP_STR_TOOL_BAR_FOLD));
            }
            m_foldButton->setIsDisabled(m_isFoldDisabled);
        }
    else
    {
        if(m_foldButton)
        {
            m_foldButton->setHidden(VFX_TRUE);
        }
        if(m_count >= VCP_TOOL_BAR_MAX_ROW_BUTTONS + 1)
        {
            for(VfxU32 i = VCP_TOOL_BAR_MAX_ROW_BUTTONS - 1 - m_segmentButtonCount; i < m_normalButtonCount; i++)
            {
                m_lowerFrame->addChildFrame(m_buttonArray[i]);
            }
        }

        if(!m_isFolded)
        {
            setPos(VfxPoint(0, getPos().y + m_rowHeight));
        }
        
        m_isFolded = VFX_TRUE;
        VfxPageBar::setBounds(VfxRect(0, 0, getSize().width, m_rowHeight));
        m_upperFrame->setPos(VfxPoint(0, 0));
        m_lowerFrame->setPos(VfxPoint(0, 0));
        //resetLayout();
    }

    m_upperFrame->setBounds(VfxRect(0, 0, getSize().width, m_rowHeight));
    m_lowerFrame->setBounds(VfxRect(0, 0, getSize().width, m_rowHeight));

    show();
#ifdef __MAUI_SOFTWARE_LA__
SLA_CustomLogging("TBc", SA_stop);
#endif    
}


void VcpToolBar::setBounds(const VfxRect &value)
{
    VfxPageBar::setBounds(value);
    checkUpdate();
    if(VfxAutoAnimate::getDisable())
    {    
        processUpdate();
    }
}


void VcpToolBar::setLayout(VfxScrRotateTypeEnum rotate)
{
#ifdef __MAUI_SOFTWARE_LA__
SLA_CustomLogging("TBd", SA_start);
#endif
    if(m_layout == rotate)
    {
#ifdef __MAUI_SOFTWARE_LA__
            SLA_CustomLogging("TBd", SA_stop);
#endif
       return;
    }

    // Upper frame is behind in both cases.
    m_upperFrame->setHidden(VFX_TRUE);

    m_layout = rotate;
    checkUpdate();
    if(VfxAutoAnimate::getDisable())
    {    
        processUpdate();
    }
#ifdef __MAUI_SOFTWARE_LA__
    SLA_CustomLogging("TBd", SA_stop);
#endif
}


