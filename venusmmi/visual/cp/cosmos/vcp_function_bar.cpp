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
 *  vcp_function_bar.cpp
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Function bar component
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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

#include "mmi_features.h"

#if defined(__MMI_VUI_COSMOS_CP__)

#include "vfx_uc_include.h"
#include "vcp_include.h"
#include "vcp_res.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class VcpFunctionBar 
 *****************************************************************************/  
VFX_IMPLEMENT_CLASS("VcpFunctionBar", VcpFunctionBar, VfxFrame);

VcpFunctionBar::VcpFunctionBar():
    m_count(0),
    m_isSpecialButtonSet(VFX_FALSE)
{
    memset(m_buttonArray, 0, sizeof(VcpButton*) * VCP_FUNCTION_BAR_MAX_BUTTONS_COUNT);
}


void VcpFunctionBar::onInit()
{
    VfxFrame::onInit();

    //setAutoAnimate(VFX_TRUE);

    setPos(VfxPoint(0, 0));
    setBounds(VfxRect(0, 0, 0, VCP_FUNCTION_BAR_HEIGHT));

    m_signalBoundsChanged.connect(this,&VcpFunctionBar::onBoundsChanged);
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setImgContent(VfxImageSrc(VCP_IMG_FUNCTION_BAR_BG_IMAGE));
    setIsCached(VFX_TRUE);
}


void VcpFunctionBar::onBoundsChanged(VfxFrame *frame, const VfxRect &old)
{
    setSize(getSize().width, VCP_FUNCTION_BAR_HEIGHT);
    show();
}


VfxBool VcpFunctionBar::addItem(VfxId button_id, const VfxWString &button_string)
{
    return addItemInt(button_id, button_string, -1);
}

/* vaib mem reduction*/
VfxBool VcpFunctionBar::addItem(VfxResId button_string, VfxId button_id)
{
    return addItemInt(button_id, VFX_WSTR_RES(button_string), -1);
}

/* vaib mem reduction*/
VfxBool VcpFunctionBar::addItem(VfxId button_id, const VfxWChar* button_string)
{
    return addItemInt(button_id, VFX_WSTR_MEM(button_string), -1);
}

VfxBool VcpFunctionBar::addItem(VfxId button_id, VfxResId button_icon)
{
    return addItemInt(button_id, VFX_WSTR(""), button_icon);
}


VfxBool VcpFunctionBar::addItemInt(VfxId button_id, const VfxWString &button_string, VfxResId button_icon)
{
    if(button_icon == -1)
    {
        VFX_ASSERT(!button_string.isEmpty());
    }
    else
    {
        VFX_ASSERT(button_icon);
    }

    if((m_count == VCP_FUNCTION_BAR_MAX_BUTTONS_COUNT))
    {
        return VFX_FALSE;
    }

    //Check if the VfxID is unique i.e. this button is already not in the bar.
    for(VfxU32 i = 0; i < m_count; i++)
    {
        if(m_buttonArray[i]->getId() == button_id)
        {
            return VFX_FALSE;
        }
    }

    VFX_OBJ_CREATE(m_buttonArray[m_count], VcpButton, this);
    m_buttonArray[m_count]->setId(button_id);
    if(button_icon == -1)
    {
        m_buttonArray[m_count]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        m_buttonArray[m_count]->setText(button_string);
        // Apply the Font size on the button
        VfxFontDesc font_desc;
        font_desc.size = VFX_FONT_DESC_VF_SIZE(VCP_FUNCTION_BAR_BUTTON_FONT_SIZE);
        m_buttonArray[m_count]->setTextFont(font_desc);
    }
    else
    {
        m_buttonArray[m_count]->setImage(VcpStateImage(button_icon));
        m_buttonArray[m_count]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
    }
    m_buttonArray[m_count]->m_signalClicked.connect(this, &VcpFunctionBar::onItemClick);

    if(m_isSpecialButtonSet)
    {
        VcpButton *tempButton;
        tempButton = m_buttonArray[m_count - 1];
        m_buttonArray[m_count - 1] = m_buttonArray[m_count];
        m_buttonArray[m_count] = tempButton;
    }

    m_count++;
    show();
    return VFX_TRUE;
}


VfxBool VcpFunctionBar::changeItem(VfxId buttonId, const VfxWString &buttonString)
{
    return changeItemInt(buttonId, buttonString, -1);
}

/* vaib mem reduction*/
VfxBool VcpFunctionBar::changeItem(VfxResId buttonString, VfxId buttonId)
{
    return changeItemInt(buttonId, VFX_WSTR_RES(buttonString), -1);
}

/* vaib mem reduction*/
VfxBool VcpFunctionBar::changeItem(VfxId buttonId, const VfxWChar* buttonString)
{
    return changeItemInt(buttonId, VFX_WSTR_MEM(buttonString), -1);
}


VfxBool VcpFunctionBar::changeItem(VfxId buttonId, VfxResId buttonIcon)
{
    return changeItemInt(buttonId, VFX_WSTR(""), buttonIcon);
}


VfxBool VcpFunctionBar::changeItemInt(VfxId buttonId, const VfxWString &buttonString, VfxResId buttonIcon)
{
    if(buttonIcon == -1)
    {
        VFX_ASSERT(!buttonString.isEmpty());
    }
    else
    {
        VFX_ASSERT(buttonIcon);
    }

    VfxS32 changeIndex = -1; 
    //Check if the VfxID is unique i.e. this button is already not in the bar.
    for(VfxU32 i = 0; i < m_count; i++)
    {
        if(m_buttonArray[i]->getId() == buttonId)
        {
            changeIndex = i;
            break;
        }
    }

    if (changeIndex == -1)
    {
        return VFX_FALSE;
    }

    if(buttonIcon == -1)
    {
        if(m_buttonArray[changeIndex]->getText() == buttonString)
        {
            return VFX_TRUE;
        }

        if(m_buttonArray[changeIndex]->getPlacement() == VCP_BUTTON_PLACEMENT_IMAGE_ONLY)
        {
            m_buttonArray[changeIndex]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY);
        }

        m_buttonArray[changeIndex]->setText(buttonString);
    }
    else
    {
        if(m_buttonArray[changeIndex]->getPlacement() == VCP_BUTTON_PLACEMENT_TEXT_ONLY)
        {
            m_buttonArray[changeIndex]->setPlacement(VCP_BUTTON_PLACEMENT_IMAGE_ONLY);
        }
        
        m_buttonArray[changeIndex]->setImage(VcpStateImage(buttonIcon));
    }
    
    show();
    return VFX_TRUE;
}


VfxBool VcpFunctionBar::removeItem(VfxId button_id)
{
    for(VfxU32 i = 0; i < m_count; i++)
    {
        if(button_id == m_buttonArray[i]->getId())
        {
            VFX_OBJ_CLOSE(m_buttonArray[i]);

            if(i == m_count - 1)
            {
                // If last button, then it maybe special button.
                m_isSpecialButtonSet = VFX_FALSE;
            }

            // Reset other button's position
            m_count--;

            for(VfxU32 j = i; j < m_count; j++)
            {
                m_buttonArray[j] = m_buttonArray[j + 1];
            }

            if(m_count)
            {
                show();
            }
            
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


VfxBool VcpFunctionBar::setItemSpecial(VfxId button_id)
{
    if(m_isSpecialButtonSet || !m_count)
    {
        return VFX_FALSE;
    }

    for(VfxU32 i = 0; i < m_count; i++)
    {
        if(button_id == m_buttonArray[i]->getId())
        {
            m_isSpecialButtonSet = VFX_TRUE;

            VcpButton *tempButton;
            tempButton = m_buttonArray[i];
            tempButton->setStyle(VCP_BUTTON_STYLE_DEFAULT_02);

            tempButton->setTextColor(VFX_COLOR_RES(VCP_COL_FUNC_BAR_BTN_FONT_SPCL));
            //tempButton->setMargin(VCP_FUNCTION_BAR_BUTTON_LEFT_MARGIN,0,VCP_FUNCTION_BAR_BUTTON_RIGHT_MARGIN,0);

            for(VfxU32 j = i; j < m_count; j++)
            {
                m_buttonArray[j] = m_buttonArray[j+1];  
            }
            m_buttonArray[m_count - 1] = tempButton;

            show();
            return VFX_TRUE;
        }
    }
    return VFX_FALSE;
}


VfxBool VcpFunctionBar::setDisableItem(VfxId id, VfxBool is_enable)
{
    VFX_ASSERT(m_count);

    VfxS32 index = -1;

    for(VfxU32 i = 0; i < m_count; i++)
    {
        if(m_buttonArray[i]->getId() == id)
        {
            index = i;
            break;
        }
    }

    if(index == -1) 
    {
        return VFX_FALSE;
    }

    m_buttonArray[index]->setIsDisabled(is_enable);
    return VFX_TRUE;
}


void VcpFunctionBar::show()
{
    if(!m_count)
    {
        return;
    }

    VfxU32 button_width, button_space;
    VfxRect s;
    s = (VfxRect)getBounds();
    button_space = (s.size.width / VCP_FUNCTION_BAR_MAX_BUTTONS_COUNT);
    button_width = button_space - VCP_FUNCTION_BAR_BUTTON_GAP;

    VfxS32 i;
    for(i = 0; i < m_count - 1; i++)
    {
        m_buttonArray[i]->setPos(button_space  * i + VCP_FUNCTION_BAR_BUTTON_GAP, VCP_FUNCTION_BAR_BUTTON_OFFSET);
        m_buttonArray[i]->setBounds(0, 0, button_width, VCP_FUNCTION_BAR_BUTTON_HEIGHT);
    }

    // Last button
    if(m_isSpecialButtonSet)
    {
        m_buttonArray[i]->setPos(button_space  * (VCP_FUNCTION_BAR_MAX_BUTTONS_COUNT - 1) + VCP_FUNCTION_BAR_BUTTON_GAP, VCP_FUNCTION_BAR_BUTTON_OFFSET);
    }
    else
    {
        m_buttonArray[i]->setPos(button_space  * i + VCP_FUNCTION_BAR_BUTTON_GAP, VCP_FUNCTION_BAR_BUTTON_OFFSET);
    }
    m_buttonArray[i]->setBounds(0, 0, button_width, VCP_FUNCTION_BAR_BUTTON_HEIGHT);
}


void VcpFunctionBar::setLayout(VfxScrRotateTypeEnum rotate)
{
    switch(rotate)
    {  
        case VFX_SCR_ROTATE_TYPE_NORMAL:                
        case VFX_SCR_ROTATE_TYPE_180:                
            {
                setSize(VCP_FUNCTION_BAR_WIDTH, getSize().height);
                break;
            }
        case VFX_SCR_ROTATE_TYPE_90:                
        case VFX_SCR_ROTATE_TYPE_LANDSCAPE:
            {
                setSize(VCP_FUNCTION_BAR_WIDTH_LANDSCAPE, getSize().height);
                break;
            }
        default:
            break;
    }
    
    show();
}


void VcpFunctionBar::onItemClick(VfxObject *obj, VfxId id)
{
    m_signalButtonTap.emit(this, id);
}

#endif /* defined(__MMI_VUI_COSMOS_CP__) */


