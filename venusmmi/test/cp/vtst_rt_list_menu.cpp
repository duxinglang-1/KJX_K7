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
 *  vtst_rt_menu.cpp
 *
 * Project:
 * --------
 *  Venus Regression Test for menu
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vadp_mmi_frm.h"
#include "vfx_uc_include.h"
#include "vcp_app_scr.h"
#include "vcp_list_menu.h"
#include "vtst_rt_main.h"
#include "vcp_include.h"
#include "ui_core\base\vfx_basic_type.h"
#include "vcp_res.h"

#include "GlobalResDef.h"
#include "mmi_rp_app_uiframework_def.h"

#ifdef __AFX_RT_TEST__

class VtstRtListMenuUTPanel : public VfxControl
{
// Implementation
private:
    
    #define BUTTON_VER_GAP 2
    #define BUTTON_HOR_GAP 0

// Constructor / Destructor
public:

    VtstRtListMenuUTPanel(VcpBaseListMenu *menu) : 
        m_menu(menu),
        m_statusText(NULL),
        m_btnDone(NULL),
        m_btnCellStyle(NULL),
        m_btnMenuMode(NULL),
        m_btnControlMode(NULL),
        m_btnSearchBar(NULL),
        //m_btnSeekBar(NULL),
        m_btnSeparator(NULL),
        m_lastLayoutX(0),
        m_lastLayoutY(0),
        m_lastLineHeight(0)
    {
    }

    virtual ~VtstRtListMenuUTPanel(){}

// Method
public:

    void addUTItem(VfxFrame *frame)
    {
        if (m_lastLayoutX + frame->getSize().width + BUTTON_HOR_GAP - 1 > getSize().width - 1)
        {
            VFX_ASSERT(m_lastLineHeight);
            m_lastLayoutY += m_lastLineHeight;
            m_lastLayoutX = 0;
            m_lastLineHeight = 0;
        }
            
        frame->setPos(m_lastLayoutX + BUTTON_HOR_GAP, m_lastLayoutY + BUTTON_VER_GAP);

        m_lastLayoutX += (BUTTON_HOR_GAP + frame->getSize().width);

        if (m_lastLineHeight < frame->getSize().height + BUTTON_VER_GAP)
        {
            m_lastLineHeight = frame->getSize().height + BUTTON_VER_GAP;

            setSize(getSize().width, frame->getPos().y + frame->getSize().height + BUTTON_VER_GAP - 1);
        }
    }

// Override:
protected:

    virtual void onInit()
    {
        VfxControl::onInit();

        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
        setBounds(VfxRect(0, 0, main_screen_size.width, 0));

        VFX_OBJ_CREATE(m_statusText, VfxTextFrame, this);

        m_statusText->setFont(VFX_FONT_DESC_SMALL);
        m_statusText->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_statusText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_statusText->setString(VFX_WSTR("Press buttons to change menu config"));
        m_statusText->setSize(main_screen_size.width - BUTTON_HOR_GAP * 2, m_statusText->getBounds().getHeight());
        addUTItem(m_statusText);
        
        VFX_OBJ_CREATE(m_btnCellStyle, VcpButton, this);

        m_btnCellStyle->setId('CELL');
        m_btnCellStyle->setIsAutoResized(VFX_TRUE);
        m_btnCellStyle->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnCellStyle->setText(VFX_WSTR("Style"));
        m_btnCellStyle->m_signalClicked.connect(this, &VtstRtListMenuUTPanel::onDebugButtonClicked);
        m_btnCellStyle->forceUpdate();
        addUTItem(m_btnCellStyle);
    
#if !defined(__MRE_SDK__)
        VFX_OBJ_CREATE(m_btnSearchBar, VcpButton, this);

        m_btnSearchBar->setId('SRCH');
        m_btnSearchBar->setIsAutoResized(VFX_TRUE);
        m_btnSearchBar->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnSearchBar->setText(VFX_WSTR("Search bar"));
        m_btnSearchBar->m_signalClicked.connect(this, &VtstRtListMenuUTPanel::onDebugButtonClicked);
        m_btnSearchBar->forceUpdate();
        addUTItem(m_btnSearchBar);
#endif

#if defined(__MMI_VUI_COSMOS_CP__)
        VFX_OBJ_CREATE(m_btnSeekBar, VcpButton, this);

        m_btnSeekBar->setId('SEEK');
        m_btnSeekBar->setIsAutoResized(VFX_TRUE);
        m_btnSeekBar->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnSeekBar->setText(VFX_WSTR("Seek bar"));
        m_btnSeekBar->m_signalClicked.connect(this, &VtstRtListMenuUTPanel::onDebugButtonClicked);
        m_btnSeekBar->forceUpdate();
        addUTItem(m_btnSeekBar);
#endif
        VFX_OBJ_CREATE(m_btnDone, VcpButton, this);

        m_btnDone->setId('DONE');
        m_btnDone->setIsAutoResized(VFX_TRUE);
        m_btnDone->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnDone->setText(VFX_WSTR("Done"));
        m_btnDone->m_signalClicked.connect(this, &VtstRtListMenuUTPanel::onDebugButtonClicked);
        m_btnDone->forceUpdate();
        addUTItem(m_btnDone);

        VFX_OBJ_CREATE(m_btnMenuMode, VcpButton, this);

        m_btnMenuMode->setId('MODE');
        m_btnMenuMode->setIsAutoResized(VFX_TRUE);
        m_btnMenuMode->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnMenuMode->setText(VFX_WSTR("Menu mode"));
        m_btnMenuMode->m_signalClicked.connect(this, &VtstRtListMenuUTPanel::onDebugButtonClicked);
        m_btnMenuMode->forceUpdate();
        addUTItem(m_btnMenuMode);

        VFX_OBJ_CREATE(m_btnControlMode, VcpButton, this);

        m_btnControlMode->setId('CMOD');
        m_btnControlMode->setIsAutoResized(VFX_TRUE);
        m_btnControlMode->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnControlMode->setText(VFX_WSTR("Control mode"));
        m_btnControlMode->m_signalClicked.connect(this, &VtstRtListMenuUTPanel::onDebugButtonClicked);
        m_btnControlMode->forceUpdate();
        addUTItem(m_btnControlMode);
        
        VFX_OBJ_CREATE(m_btnSeparator, VcpButton, this);

        m_btnSeparator->setId('SPTR');
        m_btnSeparator->setIsAutoResized(VFX_TRUE);
        m_btnSeparator->setTextFont(VFX_FONT_DESC_SMALL);
        m_btnSeparator->setText(VFX_WSTR("Separators"));
        m_btnSeparator->m_signalClicked.connect(this, &VtstRtListMenuUTPanel::onDebugButtonClicked);
        m_btnSeparator->forceUpdate();
        addUTItem(m_btnSeparator);
    }

// Implementation
private:

    VcpBaseListMenu *m_menu;

    VfxTextFrame *m_statusText;

    VcpButton *m_btnDone;

    VcpButton *m_btnCellStyle;

    VcpButton *m_btnMenuMode;

    VcpButton *m_btnControlMode;
    
#if !defined(__MRE_SDK__)
    VcpButton *m_btnSearchBar;
#endif

#if defined(__MMI_VUI_COSMOS_CP__)
    VcpButton *m_btnSeekBar;
#endif

    VcpButton *m_btnSeparator;

    VfxS32 m_lastLayoutX;

    VfxS32 m_lastLayoutY;

    VfxS32 m_lastLineHeight;
    
// Implementation
private:

    void onDebugButtonClicked(VfxObject *btn, VfxId id)
    {
        //VcpButton *button = (VcpButton *)btn;

        switch (id)
        {
        case 'DONE':
			{
				VtstRtScr *rtScr = (VtstRtScr *)VFX_OBJ_GET_INSTANCE(VfxTopLevel)->getActiveScr();
                rtScr->endPhase();
			}
            break;

        case 'CELL':
            {
                VcpListMenuCellStyleEnum cellStyle = m_menu->getCellStyle();
                
                if (cellStyle + 1 == VCP_LIST_MENU_CELL_STYLE_MAX)
                {
                    cellStyle = VCP_LIST_MENU_CELL_STYLE_CUSTOM;
                }
                else
                {
                    cellStyle = (VcpListMenuCellStyleEnum)((VfxU32)cellStyle + 1);
                }
                
                m_menu->setCellStyle(cellStyle);
                m_menu->reset();
                m_statusText->setString(getCellStyleString(cellStyle));
            }
            break;

        case 'MODE':
            {
                VcpListMenuModeEnum mode = m_menu->getMenuMode();

                if (mode + 1 == VCP_LIST_MENU_MODE_MAX)
                {
                    mode = VCP_LIST_MENU_MODE_NORMAL;
                }
                else
                {
                    mode = (VcpListMenuModeEnum)((VfxU32)mode + 1);

                    if (m_menu->isKindOf(VFX_OBJ_CLASS_INFO(VcpGroupListMenu)) && 
                        mode == VCP_LIST_MENU_MODE_REORDER)
                    {
                        mode = (VcpListMenuModeEnum)((VfxU32)mode + 1);
                    }
                }

                m_menu->setMenuMode(mode, VFX_TRUE);
                //m_menu->reset();
                m_statusText->setString(getMenuModeString(mode));
            }
            break;

        case 'CMOD':
            {
                VcpListMenuControlModeEnum controlMode = m_menu->getMenuControlMode();
                
                if (controlMode + 1 == VCP_LIST_MENU_CONTROL_MODE_MAX)
                {
                    controlMode = VCP_LIST_MENU_CONTROL_MODE_NORMAL;
                }
                else
                {
                    controlMode = (VcpListMenuControlModeEnum)((VfxU32)controlMode + 1);
                }

                m_menu->setMenuControlMode(controlMode, VFX_TRUE);
                //m_menu->reset();
                m_statusText->setString(getControlModeString(controlMode));
            }
            break;
    #if !defined(__MRE_SDK__)
        case 'SRCH':
            {
                if (m_menu->isSearchBarEnabled())
                {
                    m_menu->disableSearchBar();
                    m_statusText->setString(VFX_WSTR("Search bar is disabled"));
                }
                else
                {
                    m_menu->enableSearchBar();
                    m_statusText->setString(VFX_WSTR("Search bar is enabled"));
                }

                break;
            }
    #endif /* #if !defined(__MRE_SDK__) */

    #if defined(__MMI_VUI_COSMOS_CP__)
        case 'SEEK':
            {
                if (m_menu->isSeekBarEnabled())
                {
                    m_menu->disableSeekBar(VFX_TRUE);
                    m_statusText->setString(VFX_WSTR("Seek bar is disabled"));
                }
                else
                {
                    m_menu->enableSeekBar(VFX_TRUE);
                    m_statusText->setString(VFX_WSTR("Seek bar is enabled"));
                }
                
                break;
            }
    #endif /* #if defined(__MMI_VUI_COSMOS_CP__) */

        case 'SPTR':
            {
                if (m_menu->getItemSeparatorHidden())
                {
                    m_menu->setItemSeparatorHidden(VFX_FALSE);
                    m_statusText->setString(VFX_WSTR("Separator lines are enabled"));
                }
                else
                {
                    m_menu->setItemSeparatorHidden(VFX_TRUE);
                    m_statusText->setString(VFX_WSTR("Separator lines are disabled"));
                }
                
                break;
            }
            break;
    
        default:
            break;
        }
    }

    VfxWString getCellStyleString(VcpListMenuCellStyleEnum cellStyle)
    {
        switch (cellStyle)
        {
        case VCP_LIST_MENU_CELL_STYLE_CUSTOM:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_CUSTOM");
            break;
        case VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT");
            break;
        case VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT");
            break;
    #if !defined(__MRE_SDK__)
        case VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT_EX:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_MULTI_TEXT_EX");
            break;
        case VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT");
            break;
        case VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT_EX:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_TRIPLE_TEXT_EX");
            break;
        case VCP_LIST_MENU_CELL_STYLE_QUADRUPLE_TEXT:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_QUADRUPLE_TEXT");
            break;
        case VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT");
            break;
        case VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX");
            break;
		case VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX2:
			return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_ICON_SINGLE_TEXT_EX2");
			break;
        case VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT");
            break;
        case VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT_EX:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_ICON_MULTI_TEXT_EX");
            break;
        case VCP_LIST_MENU_CELL_STYLE_ICON_TRIPLE_TEXT:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_ICON_TRIPLE_TEXT");
            break;
        case VCP_LIST_MENU_CELL_STYLE_ICON_TRIPLE_TEXT_EX:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_ICON_TRIPLE_TEXT_EX");
            break;
        case VCP_LIST_MENU_CELL_STYLE_ICON_QUADRUPLE_TEXT:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_ICON_QUADRUPLE_TEXT");
            break;
        case VCP_LIST_MENU_CELL_STYLE_ICON_QUINTUPLE_TEXT:
            return VFX_WSTR("VCP_LIST_MENU_CELL_STYLE_ICON_QUINTUPLE_TEXT");
            break;
    #endif /* #if !defined(__MRE_SDK__) */

        default:
            VFX_ASSERT(0);
            break;
        }

        return VFX_WSTR_EMPTY;
    }

    VfxWString getMenuModeString(VcpListMenuModeEnum mode)
    {
        switch (mode)
        {
        case VCP_LIST_MENU_MODE_NORMAL:
            return VFX_WSTR("VCP_LIST_MENU_MODE_NORMAL");
            break;
    #if !defined(__MRE_SDK__)
        case VCP_LIST_MENU_MODE_REORDER:
            return VFX_WSTR("VCP_LIST_MENU_MODE_REORDER");
            break;
    #endif
        case VCP_LIST_MENU_MODE_SINGLE_SELECTION:
            return VFX_WSTR("VCP_LIST_MENU_MODE_SINGLE_SELECTION");
            break;
        case VCP_LIST_MENU_MODE_MULTI_SELECTION:
            return VFX_WSTR("VCP_LIST_MENU_MODE_MULTI_SELECTION");
            break;
        case VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK:
            return VFX_WSTR("VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK");
            break;
        case VCP_LIST_MENU_MODE_HEAD_MULTI_CHECK_MARK:
            return VFX_WSTR("VCP_LIST_MENU_MODE_HEAD_MULTI_CHECK_MARK");
            break;
        case VCP_LIST_MENU_MODE_TAIL_SINGLE_CHECK_MARK:
            return VFX_WSTR("VCP_LIST_MENU_MODE_TAIL_SINGLE_CHECK_MARK");
            break;
        case VCP_LIST_MENU_MODE_TAIL_MULTI_CHECK_MARK:
            return VFX_WSTR("VCP_LIST_MENU_MODE_TAIL_MULTI_CHECK_MARK");

        default:
            VFX_ASSERT(0);
            break;
        }

        return VFX_WSTR_EMPTY;
    }

    VfxWString getControlModeString(VcpListMenuControlModeEnum mode)
    {
        switch (mode)
        {
        case VCP_LIST_MENU_CONTROL_MODE_NORMAL:
            return VFX_WSTR("VCP_LIST_MENU_CONTROL_MODE_NORMAL");
            break;
        case VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON:
            return VFX_WSTR("VCP_LIST_MENU_CONTROL_MODE_CMD_BUTTON");
            break;
        case VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE:
            return VFX_WSTR("VCP_LIST_MENU_CONTROL_MODE_DISCLOSURE");
            break;
        default:
            VFX_ASSERT(0);
            break;
        }

        return VFX_WSTR_EMPTY;
    }
};

// VcpListMenu RT test

class VtstRtListMenuCustomContentFrame : public VcpListMenuCellClientBaseFrame
{
// Constructor / Destructor
public:

    VtstRtListMenuCustomContentFrame(){}
    virtual ~VtstRtListMenuCustomContentFrame(){}

// Override
public:

    virtual void onCreateElements()
    {
        VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);

        m_textFrame->setString(VFX_WSTR("This is a custom frame"));

        m_textFrame->setColor(VFX_COLOR_BLACK);
        m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
        m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_textFrame->setAutoAnimate(VFX_TRUE);
    }

    virtual void onCloseElements(){}

    virtual void onLayoutElements()
    {
        m_textFrame->setRect(VfxRect(3, 
                                     getRect().getMidY() - m_textFrame->getRect().getHeight() / 2,
                                     getRect().getWidth() - 3 - 3,
                                     m_textFrame->getRect().getHeight()));

        m_textFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE,
                                    VFX_FRAME_ALIGNER_MODE_SIDE);
    }

    virtual void onUpdateElements(){}

private:

    VfxTextFrame *m_textFrame;

};

class VtstRtListMenuContentProvider : public VfxObject, public IVcpListMenuContentProvider
{
// Override
public:

    virtual void setMenu(VcpListMenu *menu){list = menu;}

    virtual VfxBool getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
    {
        if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            //text = VFX_WSTR("Did you see this by chance");
            text = VFX_WSTR("Today");
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        }
#if !defined(__MRE_SDK__)
		else if (fieldType == VCP_LIST_MENU_FIELD_TAIL_TEXT)
        {
            text = VFX_WSTR("(3)");
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	    }
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
        {
            text = VFX_WSTR("Yesterday");
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT3)
        {
            text = VFX_WSTR("10:12");
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        }
#endif
        else
        {
            text = VFX_WSTR("Hello world");
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        }
        
        return VFX_TRUE;
    }

    virtual VfxBool getItemTextFormat(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VcpRichText &format        
        ) 
    {
        return VFX_FALSE;
    } 

    virtual VfxBool getItemTextFrameFormat(VfxU32 index, VcpListMenuFieldEnum fieldType, VfxTextFrame * frame)
    {
        if (index == 1 && fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            VfxFontDesc font = frame->getFont();
            font.setAttr(VFX_FONT_DESC_ATTR_BOLD);
            frame->setFont(font);
        }
		return VFX_TRUE;
    }

    virtual VfxBool getItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
    {
        if (fieldType == VCP_LIST_MENU_FIELD_ICON)
        {
            if (index % 3 == 0)
            {
                image.setResId(IMG_GLOBAL_L1);
            }
            else if (index % 3 == 1)
            {
                image.setResId(IMG_GLOBAL_L2);
            }
            else if (index % 3 == 2)
            {
                image.setResId(IMG_GLOBAL_L3);
            }
            else
            {
                return VFX_FALSE;
            }
        }
#if !defined(__MRE_SDK__)

        else if (fieldType == VCP_LIST_MENU_FIELD_ICON_EXTRA1)
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
        #endif
            {
                return VFX_FALSE;
            }
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_ICON_EXTRA2)
        {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
            {
                return VFX_FALSE;
            }
        }
#endif
        else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL)
        {
            image.setResId(RIGHT_RED_ARROW_NORMAL);
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
        {
            image.setResId(RIGHT_RED_ARROW_PRESSED);
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED)
        {
            image.setResId(RIGHT_RED_ARROW_NORMAL);
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
        {
            image.setResId(RIGHT_RED_ARROW_NORMAL);
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_HIGHLIGHT_DISCLOSURE_IMG)
        {
            return VFX_FALSE;
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
        {
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
        {
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
        }
        
        return VFX_TRUE;
    }

    virtual VfxBool getItemIsDisabled(VfxU32 index) const 
    {
        if (index == 3 || index == 7)
        {
            return VFX_TRUE;
        }
        
        return VFX_FALSE;
    }

    
    virtual void closeItemImage(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType, 
        VfxImageSrc Image               
        ) {}

    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color) 
    {
        text = VFX_WSTR("List is empty");
        return VFX_TRUE;
    }

    virtual VfxU32 getCount() const {return 30; }

    virtual VcpListMenuItemStateEnum getItemState(
        VfxU32 index   
        ) const 
    { 
        if (selectedIndex == index)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else if (index == 5 || index == 9)
        {
            return VCP_LIST_MENU_ITEM_STATE_NONE;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }

    
    virtual VfxBool swapItem(
        VfxU32 index1, 
        VfxU32 index2 
        ) 
    {
        
        return VFX_TRUE;
    }

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VfxU32 index,
        VfxFrame *parentFrame
        )
    {
        if (list->getCellStyle() == VCP_LIST_MENU_CELL_STYLE_CUSTOM)
        {
            VtstRtListMenuCustomContentFrame *custFrame = NULL;

            VFX_OBJ_CREATE(custFrame, VtstRtListMenuCustomContentFrame, parentFrame);

            return (VcpListMenuCellClientBaseFrame *)custFrame;
        }
        else
        {
            return NULL;
        }
    }

    virtual void closeItemCustomContentFrame(
        VfxU32 index,  
        VcpListMenuCellClientBaseFrame *cell 
        )
    {
        if (cell)
        {
            VFX_OBJ_CLOSE(cell);
        }
    }

    virtual VfxU32 getSeekBarEntryCount()
    {
        return getCount();
    }

    virtual VfxBool getSeekBarEntryText(VfxU32 index, VfxWString &text)
    {
        text.format("%c", 'A'+index);
        
        return VFX_TRUE;
    }

    virtual VfxBool getItemIndexNeedJumpTo(VfxU32 touchedSeekBarEntryIndex, VfxU32 &indexJumpTo)
    {
        indexJumpTo = touchedSeekBarEntryIndex;
        return VFX_TRUE;
    }

public:

    VfxU32 selectedIndex;

    VcpListMenu *list;

};

/*static VcpListMenuThemeStruct s_rt_list_menu_theme = {
    VRT_COLOR_MAKE(166, 0, 0, 0),
    VRT_COLOR_MAKE(153, 255, 255, 255),
    VRT_COLOR_MAKE(153, 255, 255, 255),
    VRT_COLOR_MAKE(153, 255, 255, 255),
    VRT_COLOR_GREY,
    VRT_COLOR_MAKE(255, 0, 0, 0),
    VRT_COLOR_MAKE(255, 0, 0, 0),
    VRT_COLOR_MAKE(255, 0, 0, 0),
    VRT_COLOR_GREY,
    VCP_IMG_LIST_MENU_HIGHLIGHT_ITEM_BACKGROUND,
    0,
    0,
    0,
    0,
    0,
    0
};*/




class VtstRtListMenu : public VtstRtScr
{
// Variable
public:
    VcpListMenu *m_menu;
    
    VtstRtListMenuContentProvider *m_listMenuContentProvider;

    VcpListMenuModeEnum m_mode;

    VtstRtListMenuUTPanel *m_debugPanel;
    
// Constructor / Destructor
public:
    VtstRtListMenu() : m_menu(NULL) {}

protected:

    VcpListMenuCellStyleEnum m_style;

    VcpListMenuThemeStruct m_backupTheme;
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VFX_OBJ_CREATE(m_menu, VcpListMenu, this);

        VFX_OBJ_CREATE(m_listMenuContentProvider, VtstRtListMenuContentProvider, this);

        m_listMenuContentProvider->selectedIndex = 0;

        m_menu->setContentProvider(m_listMenuContentProvider);

        m_menu->m_signalItemSelectionStateChanged.connect(this, &VtstRtListMenu::onSelectionChanged);

        m_backupTheme = m_menu->getThemeData();

        m_style = VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT;

        m_menu->setCellStyle(m_style);
        
		vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
        
        VFX_OBJ_CREATE_EX(m_debugPanel, VtstRtListMenuUTPanel, this, (m_menu));

        m_debugPanel->setAnchor(0, 1);

        m_debugPanel->setPos(0, main_screen_size.height - 1);

        m_menu->setPos(VfxPoint(0, 0));
        m_menu->setBounds(VfxRect(0, 0, main_screen_size.width, main_screen_size.height - m_debugPanel->getSize().height));

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
        
        setFocused(VFX_TRUE);
    }


    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
        
        VFX_OBJ_CLOSE(m_debugPanel);
        
        VFX_OBJ_CREATE_EX(m_debugPanel, VtstRtListMenuUTPanel, this, (m_menu));

        m_debugPanel->setAnchor(0, 1);

        m_debugPanel->setPos(0, main_screen_size.height - 1);

        m_menu->setPos(VfxPoint(0, 0));
        m_menu->setBounds(VfxRect(0, 0, main_screen_size.width, main_screen_size.height - m_debugPanel->getSize().height));

        VtstRtScr::onRotate(param);
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        //confirm(VFX_WSTR("Does it work?"));
        return -1;
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_UP)
        {
            if (event.keyCode == VFX_KEY_CODE_1)
            {
                m_menu->setItemSeparatorHidden(!m_menu->getItemSeparatorHidden());
            }
#if defined(__MMI_VUI_COSMOS_CP__)

            else if (event.keyCode == VFX_KEY_CODE_4)
            {
                if (m_menu->isSeekBarEnabled())
                {
                    m_menu->disableSeekBar(VFX_TRUE);
                }
                else
                {
                    m_menu->enableSeekBar(VFX_TRUE);
                }
                
                return VFX_TRUE;
            }
#endif
            else if (event.keyCode == VFX_KEY_CODE_3)
            {
                m_menu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
                
                return VFX_TRUE;
            }
            else if (event.keyCode == VFX_KEY_CODE_5)
            {
                if (m_style + 1 == VCP_LIST_MENU_CELL_STYLE_MAX)
                {
                    m_style = VCP_LIST_MENU_CELL_STYLE_CUSTOM;
                }
                else
                {
                    m_style = (VcpListMenuCellStyleEnum)((VfxU32)m_style + 1);
                }
                
                m_menu->setCellStyle(m_style);
                m_menu->reset();
                return VFX_TRUE;
            }
            else if (event.keyCode == VFX_KEY_CODE_6)
            {
                m_mode = m_menu->getMenuMode();

                if (m_mode + 1 == VCP_LIST_MENU_MODE_MAX)
                {
                    m_mode = VCP_LIST_MENU_MODE_NORMAL;
                }
                else
                {
                    m_mode = (VcpListMenuModeEnum)((VfxU32)m_mode + 1);
                }

                m_menu->setMenuMode(m_mode, VFX_TRUE);

                m_menu->reset();
                return VFX_TRUE;
            }
#if !defined(__MRE_SDK__)
            else if (event.keyCode == VFX_KEY_CODE_7)
            {
                if (m_menu->isSearchBarEnabled())
                {
                    m_menu->disableSearchBar();
                }
                else
                {
                    m_menu->enableSearchBar();
                }
                
                return VFX_TRUE;
            }
#endif
            else if (event.keyCode == VFX_KEY_CODE_8)
            {
                VcpListMenuControlModeEnum controlMode = m_menu->getMenuControlMode();
                
                if (controlMode + 1 == VCP_LIST_MENU_CONTROL_MODE_MAX)
                {
                    controlMode = VCP_LIST_MENU_CONTROL_MODE_NORMAL;
                }
                else
                {
                    controlMode = (VcpListMenuControlModeEnum)((VfxU32)controlMode + 1);
                }

                m_menu->setMenuControlMode(controlMode, VFX_TRUE);

                m_menu->reset();
                return VFX_TRUE;
            }
        }

        return VtstRtScr::onKeyInput(event);
    }

    void onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
    {
        if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        m_listMenuContentProvider->selectedIndex = index;
    }
};

VtstTestResultEnum vtst_rt_list_menu(VfxU32 param)
{
    VTST_START_SCRN(VtstRtListMenu);
    return VTST_TR_OK;
}

#if !defined(__MRE_SDK__)
// VcpGroupListMenu RT test

class VtstRtGroupListMenuContentProvider : public VfxObject, public IVcpGroupListMenuContentProvider
{
// Override
public:

    virtual void setMenu(VcpGroupListMenu *menu){list = menu;}

    virtual VfxU32 getCount(VfxU32 group) const {return 4;}

    virtual VfxU32 getGroupCount() const {return 26;}

    virtual VfxBool hasGroupHeader(VfxS32 group) const 
    {
        return VFX_TRUE;
    }

    virtual VfxBool getItemText(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
    {
        if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            text = VFX_WSTR("Today");
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        }
		else if (fieldType == VCP_LIST_MENU_FIELD_TAIL_TEXT)
        {
            text = VFX_WSTR("(3)");
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
	    }
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT2)
        {
            text = VFX_WSTR("Today");
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT3)
        {
            text = VFX_WSTR("10:12");
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_GROUP_HEADER_TEXT)
        {
            text.format("%c", 'A'+pos.group);
            color = VCP_LIST_MENU_TEXT_COLOR_LOWLIGHT;
        }        
        else
        {
            text = VFX_WSTR("Abcdefghijklmnopqrstuvwxyz");
            color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
        }
        
        return VFX_TRUE;
    }

    virtual VfxBool getMenuEmptyText(VfxWString &text, VcpListMenuTextColorEnum &color) 
    {
        text = VFX_WSTR("List is empty");
        return VFX_TRUE;
    }

    virtual VfxBool getItemIsDisabled(VcpMenuPos pos) const 
    {
        if (pos.pos == 2 || pos.pos == 7)
        {
            return VFX_TRUE;
        }
        
        return VFX_FALSE;
    }

    virtual VfxBool getItemTextFormat(
        VcpMenuPos pos,                  
        VcpListMenuFieldEnum fieldType,  
        VcpRichText &format        
        ) 
    {
        if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            format.setTextColor(VRT_COLOR_RED);
            format.setTextBgColor(VRT_COLOR_GREEN);
            format.setRange(0, 1);
            //return VFX_TRUE;
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_SUB_TEXT1)
        {
            format.setTextColor(VRT_COLOR_RED);
            format.setTextBgColor(VRT_COLOR_GREEN);
            format.setRange(0, 3);
            //return VFX_TRUE;
        }
        //format.setFont(numberFont);
        
        return VFX_FALSE;
    } 

    virtual VfxBool getItemTextFrameFormat(
        VcpMenuPos pos,                  
        VcpListMenuFieldEnum fieldType,  
        VfxTextFrame *frame
    ) 
    {
        if (pos.pos == 1 && fieldType == VCP_LIST_MENU_FIELD_TEXT)
        {
            VfxFontDesc font = frame->getFont();
            font.setAttr(VFX_FONT_DESC_ATTR_BOLD);
            frame->setFont(font);
        }
        return VFX_TRUE;
    }

    virtual VfxBool getItemImage(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType,  
        VfxImageSrc &image              
        ) 
    {
        if (fieldType == VCP_LIST_MENU_FIELD_ICON)
        {
            if (pos.pos % 3 == 0)
            {
                image.setResId(IMG_GLOBAL_L1);
            }
            else if (pos.pos % 3 == 1)
            {
                image.setResId(IMG_GLOBAL_L2);
            }
            else if (pos.pos % 3 == 2)
            {
                image.setResId(IMG_GLOBAL_L3);
            }
            else
            {
                return VFX_FALSE;
            }
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_ICON_EXTRA1)
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
        #endif
            {
                return VFX_FALSE;
            }
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_ICON_EXTRA2)
        {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
            {
                return VFX_FALSE;
            }
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_NORMAL)
        {
            image.setResId(RIGHT_RED_ARROW_NORMAL);
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_PRESSED)
        {
            image.setResId(RIGHT_RED_ARROW_PRESSED);
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_DISABLED)
        {
            image.setResId(RIGHT_RED_ARROW_NORMAL);
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_CMD_BUT_IMG_HIGHLIGHT)
        {
            image.setResId(RIGHT_RED_ARROW_NORMAL);
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
        {
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
        }
        else if (fieldType == VCP_LIST_MENU_FIELD_DISCLOSURE_IMG)
        {
            image.setResId(VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE);
        }
        
        return VFX_TRUE;
    }

    
    virtual void closeItemImage(
        VcpMenuPos pos,                    
        VcpListMenuFieldEnum fieldType, 
        VfxImageSrc Image               
        ) {}

    virtual VcpListMenuItemStateEnum getItemState(
        VcpMenuPos pos  
        ) const 
    { 
        if (selectedIndex == pos)
        {
            return VCP_LIST_MENU_ITEM_STATE_SELECTED;
        }
        else
        {
            return VCP_LIST_MENU_ITEM_STATE_UNSELECTED;
        }
    }

    virtual VcpListMenuCellClientBaseFrame *getItemCustomContentFrame(
        VcpMenuPos pos,
        VfxFrame *parentFrame
        )
    {
        if (list->getCellStyle() == VCP_LIST_MENU_CELL_STYLE_CUSTOM)
        {
            VtstRtListMenuCustomContentFrame *custFrame = NULL;

            VFX_OBJ_CREATE(custFrame, VtstRtListMenuCustomContentFrame, parentFrame);

            return (VcpListMenuCellClientBaseFrame *)custFrame;
        }
        else
        {
            return NULL;
        }
    }

    virtual void closeItemCustomContentFrame(
        VcpMenuPos pos,  
        VcpListMenuCellClientBaseFrame *cell 
        )
    {
        if (cell)
        {
            VFX_OBJ_CLOSE(cell);
        }
    }

    virtual VfxU32 getSeekBarEntryCount()
    {
        return getGroupCount();
    }

    virtual VfxBool getSeekBarEntryText(VfxU32 index, VfxWString &text)
    {
        text.format("%c", 'A'+index);
        
        return VFX_TRUE;
    }

    virtual VfxBool getItemPosNeedJumpTo(VfxU32 touchedSeekBarEntryIndex, VcpMenuPos &posJumpTo)
    {
        posJumpTo.group = touchedSeekBarEntryIndex;
        posJumpTo.pos = -1;
        return VFX_TRUE;
    }

public:

    VcpMenuPos selectedIndex;

    VcpGroupListMenu *list;

};


class VtstRtGroupListMenu : public VtstRtScr
{
// Variable
public:
    VcpGroupListMenu *m_menu;
    
    VtstRtGroupListMenuContentProvider *m_listMenuContentProvider;

    VcpListMenuModeEnum m_mode;
    
    VtstRtListMenuUTPanel *m_debugPanel;
    
// Constructor / Destructor
public:
    VtstRtGroupListMenu() : m_menu(NULL) {}

protected:

    VcpListMenuCellStyleEnum m_style;

    VcpListMenuThemeStruct m_backupTheme;
    
// Override
protected:
    virtual void onInit()
    {
        VtstRtScr::onInit();

        VFX_OBJ_CREATE(m_menu, VcpGroupListMenu, this);

        VFX_OBJ_CREATE(m_listMenuContentProvider, VtstRtGroupListMenuContentProvider, this);

        m_listMenuContentProvider->selectedIndex = VcpMenuPos(0, 0);

        m_menu->setContentProvider(m_listMenuContentProvider);

        m_menu->m_signalItemSelectionStateChanged.connect(this, &VtstRtGroupListMenu::onSelectionChanged);

        m_backupTheme = m_menu->getThemeData();

        m_style = VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT;

        m_menu->setCellStyle(m_style);
        
        
		vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
        
        VFX_OBJ_CREATE_EX(m_debugPanel, VtstRtListMenuUTPanel, this, (m_menu));

        m_debugPanel->setAnchor(0, 1);

        m_debugPanel->setPos(0, main_screen_size.height - 1);

        m_menu->setPos(VfxPoint(0, 0));
        m_menu->setBounds(VfxRect(0, 0, main_screen_size.width, main_screen_size.height - m_debugPanel->getSize().height));

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
    
        setFocused(VFX_TRUE);
    }

    
    virtual void onRotate(
        const VfxScreenRotateParam &param // The parameter to rotate
    )
    {
        vrt_size_struct main_screen_size;
        vrt_color_type_enum main_screen_color_format;
        vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
        
        VFX_OBJ_CLOSE(m_debugPanel);
        
        VFX_OBJ_CREATE_EX(m_debugPanel, VtstRtListMenuUTPanel, this, (m_menu));
    
        m_debugPanel->setAnchor(0, 1);
    
        m_debugPanel->setPos(0, main_screen_size.height - 1);
    
        m_menu->setPos(VfxPoint(0, 0));
        m_menu->setBounds(VfxRect(0, 0, main_screen_size.width, main_screen_size.height - m_debugPanel->getSize().height));
    
        VtstRtScr::onRotate(param);
    }

    virtual int start()
    {      
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx)
    {
        //confirm(VFX_WSTR("Does it work?"));
        return -1;
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if (event.type == VFX_KEY_EVENT_TYPE_UP)
        {
            if (event.keyCode == VFX_KEY_CODE_1)
            {
                m_menu->setItemSeparatorHidden(!m_menu->getItemSeparatorHidden());
            }
		#if defined(__MMI_VUI_COSMOS_CP__)
            else if (event.keyCode == VFX_KEY_CODE_4)
            {
                if (m_menu->isSeekBarEnabled())
                {
                    m_menu->disableSeekBar(VFX_TRUE);
                }
                else
                {
                    m_menu->enableSeekBar(VFX_TRUE);
                }
                
                return VFX_TRUE;
            }
        #endif /* #if defined(__MMI_VUI_COSMOS_CP__) */
            else if (event.keyCode == VFX_KEY_CODE_5)
            {
                if (m_style + 1 == VCP_LIST_MENU_CELL_STYLE_MAX)
                {
                    m_style = VCP_LIST_MENU_CELL_STYLE_CUSTOM;
                }
                else
                {
                    m_style = (VcpListMenuCellStyleEnum)((VfxU32)m_style + 1);
                }
                
                m_menu->setCellStyle(m_style);
                m_menu->reset();
                return VFX_TRUE;
            }
            else if (event.keyCode == VFX_KEY_CODE_3)
            {
                m_menu->setMenuMode(VCP_LIST_MENU_MODE_NORMAL, VFX_TRUE);
                
                return VFX_TRUE;
            }
            else if (event.keyCode == VFX_KEY_CODE_6)
            {
                m_mode = m_menu->getMenuMode();

                if (m_mode + 1 == VCP_LIST_MENU_MODE_MAX)
                {
                    m_mode = VCP_LIST_MENU_MODE_NORMAL;
                }
                else
                {
                    m_mode = (VcpListMenuModeEnum)((VfxU32)m_mode + 1);

                    if (m_mode == VCP_LIST_MENU_MODE_REORDER)
                        m_mode = (VcpListMenuModeEnum)((VfxU32)m_mode + 1);
                }

                m_menu->setMenuMode(m_mode, VFX_TRUE);

                m_menu->reset();
                return VFX_TRUE;
            }
            else if (event.keyCode == VFX_KEY_CODE_7)
            {
                if (m_menu->isSearchBarEnabled())
                {
                    m_menu->disableSearchBar();
                }
                else
                {
                    m_menu->enableSearchBar();
                }
                
                return VFX_TRUE;
            }
            else if (event.keyCode == VFX_KEY_CODE_8)
            {
                VcpListMenuControlModeEnum controlMode = m_menu->getMenuControlMode();
                
                if (controlMode + 1 == VCP_LIST_MENU_CONTROL_MODE_MAX)
                {
                    controlMode = VCP_LIST_MENU_CONTROL_MODE_NORMAL;
                }
                else
                {
                    controlMode = (VcpListMenuControlModeEnum)((VfxU32)controlMode + 1);
                }

                m_menu->setMenuControlMode(controlMode, VFX_TRUE);

                m_menu->reset();
                return VFX_TRUE;
            }
            else if (event.keyCode == VFX_KEY_CODE_9)
            {
                VfxBool isHeaderHidden = m_menu->getGroupHeaderHidden();
                
                m_menu->setGroupHeaderHidden(!isHeaderHidden);
                return VFX_TRUE;
            }
        }

        return VtstRtScr::onKeyInput(event);
    }

    void onSelectionChanged(VcpGroupListMenu *menu, VcpMenuPos pos, VcpListMenuItemStateEnum newState)
    {
        if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
        m_listMenuContentProvider->selectedIndex = pos;
    }
};
#endif
VtstTestResultEnum vtst_rt_group_list_menu(VfxU32 param)
{
#if !defined(__MRE_SDK__)
    VTST_START_SCRN(VtstRtGroupListMenu);
#endif
    return VTST_TR_OK;
}


#endif // __AFX_RT_TEST__
