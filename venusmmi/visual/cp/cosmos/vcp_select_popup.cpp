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
 *  vcp_select_popup.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_uc_include.h"
#include "vcp_popup_data_type.h"
#include "vcp_select_popup.h"
#include "vadp_mmi_frm.h"
extern "C"
{
#include "custom_events_notify.h"
#include "profilesSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
}

#include "vfx_base_popup.h"
#include "vfx_cpp_base.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_frame.h"
#include "mmi_rp_srv_venus_component_popup_def.h"
#include "vfx_image_src.h"
#include "vfx_datatype.h"
#include "vfx_text_frame.h"
#include "vfx_basic_type.h"
#include "vfx_input_event.h"
#include "vfx_string.h"
#include "vrt_datatype.h"
#include "vfx_timer.h"
#include "vfx_signal.h"
#include "vcp_button.h"
#include "vcp_list_menu.h"



/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/


/*****************************************************************************
 * Class VcpSelectPopup
 *****************************************************************************/


void VcpSelectCoreMenu::onInit()
{
    VcpListMenu::onInit();
    m_signalItemSelectionStateChanged.connect(this, &VcpSelectCoreMenu::onSelectionChanged);
    m_signalItemTapped.connect(this, &VcpSelectCoreMenu::onTapped);
    setBgColor(VFX_COLOR_TRANSPARENT);
}
    
void VcpSelectCoreMenu::onDeinit()
{
    if (m_data)
    {
        for (VfxS32 i = 0; i < m_dataCount; i++)
        {
            VFX_DELETE(m_data[i]);
        }
        VFX_FREE_MEM(m_data);
    }
    VcpListMenu::onDeinit();
}
    
void VcpSelectCoreMenu::onUpdate()
{   
    update();  
   
    setMenuMode(m_type, VFX_FALSE);
    VcpListMenu::onUpdate();
}
void VcpSelectCoreMenu::update()
{
    setContentProvider(this);
	setCellStyle(VCP_LIST_MENU_CELL_STYLE_SINGLE_TEXT);
}

    // IVcpListMenuContentProvider
VfxBool VcpSelectCoreMenu::getItemText(
        VfxU32 index,                    
        VcpListMenuFieldEnum fieldType,  
        VfxWString &text,                
        VcpListMenuTextColorEnum &color  
        )
{
    if (fieldType == VCP_LIST_MENU_FIELD_TEXT)
    {
        text = m_data[index]->m_text;
        color = VCP_LIST_MENU_TEXT_COLOR_NORMAL;
    }

    return VFX_TRUE;
}

VfxU32 VcpSelectCoreMenu::getCount() const
{
    return m_dataCount;   
}

VcpListMenuItemStateEnum VcpSelectCoreMenu::getItemState(VfxU32 index) const
{
	return (m_data[index]->m_isSelect ? VCP_LIST_MENU_ITEM_STATE_SELECTED : VCP_LIST_MENU_ITEM_STATE_UNSELECTED);
}

VfxBool VcpSelectCoreMenu::getItemIsDisabled(VfxU32 index) const
{
    if (m_data[index]->m_isDisable)
    {
        return VFX_TRUE;
    }
    else
    {
        return VFX_FALSE;
    }
}
void VcpSelectCoreMenu::addItem(const VcpSelectCoreData* item)
{
    if (m_dataCount == m_bufferCount)
    {
        VcpSelectCoreData **new_data;
        
        m_bufferCount += 7;

		VFX_ALLOC_MEM(new_data, m_bufferCount * sizeof(VcpSelectCoreData *), this);

        memset(new_data, 0, sizeof(VcpSelectCoreData *) * m_bufferCount);
        memcpy(new_data, m_data, sizeof(VcpSelectCoreData *) * m_dataCount);

		VFX_FREE_MEM(m_data);

        m_data = new_data;
    }
	VFX_ALLOC_NEW(m_data[m_dataCount], VcpSelectCoreData, this);
    m_data[m_dataCount]->m_id = item->m_id;
    m_data[m_dataCount]->m_text = item->m_text;
    m_data[m_dataCount]->m_isSelect = item->m_isSelect;
    m_data[m_dataCount]->m_isDisable = item->m_isDisable;

    m_dataCount++;

    checkUpdate();
}
void VcpSelectCoreMenu::updateItem(const VcpSelectCoreData& item)
{     
	for (VfxS32 i = 0; i < m_dataCount; i++)
    {
        if (m_data[i]->m_id == item.m_id)
        {
			m_data[i]->m_text = item.m_text;
			VcpListMenu::updateItem(i);				
            return;
        }
    }
}	

VfxBool VcpSelectCoreMenu::getIsSelected(VfxS32 index)
{
    if (index < 0 || index >= m_dataCount)
    {
        return VFX_FALSE;
    }

    return m_data[index]->m_isSelect;
}

VfxId VcpSelectCoreMenu::getItemId(VfxS32 index)
{
    if (index < 0 || index >= m_dataCount)
    {
        return 0;
    }

    return m_data[index]->m_id;
}

void VcpSelectCoreMenu::setIsDisableItem(VfxId id, VfxBool isDisabled)
{
    VfxS32 i;
    for (i = 0; i < m_dataCount; i++)
    {
        if (m_data[i]->m_id == id &&
			m_data[i]->m_isDisable != isDisabled )
        {
            m_data[i]->m_isDisable = isDisabled;
			 VcpListMenu::updateItem(i);	
            return;
        }
    }
}

VfxBool VcpSelectCoreMenu::getIsDisableItem(VfxId id)
{
    VfxS32 i;
    for (i = 0; i < m_dataCount; i++)
    {
        if (m_data[i]->m_id == id)
        {
            return m_data[i]->m_isDisable;
        }
    }
    return VFX_FALSE;
}

void VcpSelectCoreMenu::setType(VcpListMenuModeEnum type)
{
    m_type = type;
    // it may remove if list Menu bug fixed.
    setMenuMode(m_type, VFX_FALSE);
    resetAllItems();
    checkUpdate();       
}

void VcpSelectCoreMenu::onSelectionChanged(VcpListMenu *menu, VfxU32 index, VcpListMenuItemStateEnum newState)
{
    if (index >= m_dataCount)
    {
       VFX_ASSERT(0);
    }
    
    if (newState == VCP_LIST_MENU_ITEM_STATE_SELECTED)
    {
        if (m_type == VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK || m_type == VCP_LIST_MENU_MODE_SINGLE_SELECTION)
        {
            // reset all item
            for (VfxS32 i = 0; i < m_dataCount; i++)
            {
                m_data[i]->m_isSelect = VFX_FALSE;
            }
        }
        m_data[index]->m_isSelect = VFX_TRUE;
    }
    else if (newState == VCP_LIST_MENU_ITEM_STATE_UNSELECTED)
    {
        m_data[index]->m_isSelect = VFX_FALSE;
    }
}

void VcpSelectCoreMenu::onTapped(VcpListMenu *sender, VfxU32 index)
{
    m_signalQuickSelected.emit(this, index);
}
    
VcpSelectPopup::VcpSelectPopup() :
    // m_backgroundTop(NULL),
    m_textFrame(NULL),
    m_RadioMenu(NULL),
    m_itemCount(0),
    // m_textHeight(0),
    // m_upRegionHeight(VCP_SELECT_POPUP_UP_HEIGHT),
    // m_bottomRegionHeight(0),
    m_buttonPressed(VFX_FALSE),
    m_type(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK),
    m_isAllowedEmptySelect(VFX_TRUE)
{
}


VcpSelectPopup::VcpSelectPopup(VcpSelectCoreMenu* radioMenu) :
    // m_backgroundTop(NULL),
    m_textFrame(NULL),
    m_RadioMenu(radioMenu),
    m_itemCount(0),
    // m_textHeight(0),
    // m_upRegionHeight(VCP_SELECT_POPUP_UP_HEIGHT),
    // m_bottomRegionHeight(0),
    m_buttonPressed(VFX_FALSE),
    m_type(VCP_SELECT_POPUP_BUTTON_TYPE_QUICK),
    m_isAllowedEmptySelect(VFX_TRUE)
{
}


void VcpSelectPopup::onInit()
{
    VfxBasePopup::onInit();

    setAutoAnimate(VFX_TRUE);
    setBounds(0, 0, VCP_SELECT_POPUP_WIDTH_PORTRAIT, VCP_SELECT_POPUP_UP_HEIGHT);

	VfxFrame *backgroundTop;
    VFX_OBJ_CREATE(backgroundTop, VfxFrame, this);
    backgroundTop->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_TOP));
    backgroundTop->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    backgroundTop->setBounds(0, 0, VCP_SELECT_POPUP_WIDTH_PORTRAIT, VCP_SELECT_POPUP_UP_HEIGHT);
    backgroundTop->setIsCached(VFX_TRUE);
    backgroundTop->setAutoAnimate(VFX_TRUE);
    backgroundTop->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    VFX_OBJ_CREATE(m_backgroundBottomImage, VfxFrame, this);
    m_backgroundBottomImage->setImgContent(VfxImageSrc(VCP_IMG_POPUP_MORE_BACKGROUND_BOTTOM));
    m_backgroundBottomImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_backgroundBottomImage->setIsCached(VFX_TRUE);
    m_backgroundBottomImage->setPos(0, VCP_SELECT_POPUP_UP_HEIGHT);
    m_backgroundBottomImage->setAutoAnimate(VFX_TRUE);
    m_backgroundBottomImage->setSize(VCP_SELECT_POPUP_WIDTH_PORTRAIT, VCP_SELECT_POPUP_BOTTOM_HEIGHT);

    VFX_OBJ_CREATE(m_backgroundBottom, VfxFrame, this);
    m_backgroundBottom->setIsCached(VFX_TRUE);
    m_backgroundBottom->setPos(0, VCP_SELECT_POPUP_UP_HEIGHT);
    m_backgroundBottom->setAutoAnimate(VFX_TRUE);
    m_backgroundBottom->setSize(VCP_SELECT_POPUP_WIDTH_PORTRAIT, VCP_SELECT_POPUP_BOTTOM_HEIGHT);

    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, backgroundTop);
    m_textFrame->setAnchor(0.5,0.5);
    m_textFrame->setFullLineHeightMode(VFX_FALSE);
    m_textFrame->setPos(VCP_SELECT_POPUP_TEXT_X, (VCP_SELECT_POPUP_UP_HEIGHT + 1)/2);
    m_textFrame->setSize(VCP_SELECT_POPUP_TEXT_WIDTH, 20);    
    m_textFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_textFrame->setColor(VfxColor(255,255,255,255));

    m_textFrame->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);
    m_textFrame->setAutoAnimate(VFX_TRUE);
    
    VfxFontDesc fontDesc;
    fontDesc.size = VFX_FONT_DESC_VF_SIZE(VCP_SELECT_POPUP_TEXT_SIZE);
    fontDesc.effect = VFX_FE1_9;
    m_textFrame->setFont(fontDesc);
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	if (m_RadioMenu == NULL)
	{
		VFX_OBJ_CREATE(m_RadioMenu, VcpSelectCoreMenu, m_backgroundBottom);
	}
	else
	{
		m_backgroundBottom->addChildFrame(m_RadioMenu);
	}
    m_RadioMenu->setAnchor(0.5, 0);
    m_RadioMenu->setPos(VCP_SELECT_POPUP_WIDTH_PORTRAIT/2, VCP_SELECT_POPUP_RADIO_Y);
    m_RadioMenu->m_signalQuickSelected.connect(this, &VcpSelectPopup::onSelectionChanged);
    m_RadioMenu->setAutoAnimate(VFX_TRUE);
	m_RadioMenu->enableBoundaryLight(VFX_FALSE);

    #if defined(__MMI_VUI_COSMOS_CP__)
    m_RadioMenu->setShadowIsDisabled(VFX_TRUE);
    #endif
    //m_RadioMenu->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    VFX_OBJ_CREATE(m_buttonPanel, VfxFrame, m_backgroundBottom);
    
    m_buttonPanel->setSize(VCP_SELECT_POPUP_WIDTH_PORTRAIT, VCP_SELECT_POPUP_BUTTON_HEIGHT + VCP_BUTTON_SHADOW_MARGIN_BOTTOM);
    m_buttonPanel->setAutoAnimate(VFX_TRUE);
    m_buttonPanel->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    VFX_OBJ_CREATE(m_button[0], VcpButton, m_buttonPanel);
    
    m_button[0]->setText(VFX_WSTR_RES(STR_GLOBAL_OK));
    //m_button[0]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);
    m_button[0]->setInnerRect(VfxRect(
                                VCP_SELECT_POPUP_BUTTON_1_X, 
                                0,
                                VCP_SELECT_POPUP_BUTTON_WIDTH, 
                                VCP_SELECT_POPUP_BUTTON_HEIGHT
                             ));
    m_button[0]->setId(VCP_SELECT_POPUP_BUTTON_OK);
    m_button[0]->m_signalClicked.connect(this, &VcpSelectPopup::onButtonClick);

    //m_button[0]->changeVisual(VfxVisualFactory::create(VIS_ID_COMMAND_POPUP_BUTTON_NORMAL, m_button[0]));
    //m_button[0]->setTextColor(VfxColor(255,0,0,0));
    m_button[0]->setAutoAnimate(VFX_TRUE);
    m_button[0]->setAlignParent(VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_NONE);


    VFX_OBJ_CREATE(m_button[1], VcpButton, m_buttonPanel);
    
    m_button[1]->setText(VFX_WSTR_RES(STR_GLOBAL_CANCEL));
    //m_button[1]->setPlacement(VCP_BUTTON_PLACEMENT_TEXT_ONLY_LEFT);
    m_button[1]->setInnerRect(VfxRect(
                                VCP_SELECT_POPUP_BUTTON_2_X, 
                                0,
                                VCP_SELECT_POPUP_BUTTON_WIDTH, 
                                VCP_SELECT_POPUP_BUTTON_HEIGHT
                             ));
    m_button[1]->setId(VCP_SELECT_POPUP_BUTTON_CANCEL);
    m_button[1]->m_signalClicked.connect(this, &VcpSelectPopup::onButtonClick);

    //m_button[1]->changeVisual(VfxVisualFactory::create(VIS_ID_COMMAND_POPUP_BUTTON_NORMAL, m_button[1]));
    //m_button[1]->setTextColor(VfxColor(255,0,0,0));
    m_button[1]->setStyle(VCP_BUTTON_STYLE_GREY);
    m_button[1]->setAutoAnimate(VFX_TRUE);
    m_button[1]->setAlignParent(VFX_FRAME_ALIGNER_MODE_MID, VFX_FRAME_ALIGNER_MODE_NONE, VFX_FRAME_ALIGNER_MODE_SIDE, VFX_FRAME_ALIGNER_MODE_NONE);

    
    checkUpdate();
}


void VcpSelectPopup::onEnter()
{
    VfxBasePopup::onEnter();
    
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    onUpdate();
    VfxAutoAnimate::commit();
   
    m_buttonPressed = VFX_FALSE;
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void VcpSelectPopup::show(VfxBool isAnim)
{
	if (m_type == VCP_SELECT_POPUP_BUTTON_TYPE_SINGLE ||
		m_type == VCP_SELECT_POPUP_BUTTON_TYPE_QUICK)
	{
		VfxS32 index = getNextSelectedIndex(-1);
		if (index > -1)
		{
			m_RadioMenu->setVisibleMenuItem(index);        
		}
	}
	VfxBasePopup::show(isAnim);
}

void VcpSelectPopup::onLeaveStack()
{
    if (!m_buttonPressed)
    {
         m_signalButtonClicked.postEmit(this, VCP_POPUP_BUTTON_NO_PRESSED);
    }
    VfxBasePopup::onLeaveStack();
}


void VcpSelectPopup::onRotate(const VfxScreenRotateParam &param)
{
    VfxBasePopup::onRotate(param);
    onUpdate();
}


VfxBool VcpSelectPopup::onKeyInput(VfxKeyEvent &event)
{
    if (event.keyCode == VFX_KEY_CODE_BACK && event.type == VFX_KEY_EVENT_TYPE_DOWN)
    {
        if (m_type != VCP_SELECT_POPUP_BUTTON_TYPE_QUICK)
        {
            // press back key = press cancel button
            m_signalButtonClicked.postEmit(this, m_button[1]->getId());
            m_buttonPressed = VFX_TRUE;
        }
        leave(VFX_TRUE);
        return VFX_TRUE;
    }

    return VfxBasePopup::onKeyInput(event);
}


void VcpSelectPopup::onUpdate()
{   
    VfxS32 bottomRegionHeight = m_RadioMenu->getItemHeight(0) * m_itemCount;
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    VfxS32 maxPanelHeight;
    VfxS32 finalWidth;
    VfxS32 radioWidth;
    if (topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_0 || topLevel->getScreenRotateType() == VFX_SCR_ROTATE_TYPE_180)
    {
        if (m_type == VCP_SELECT_POPUP_BUTTON_TYPE_QUICK)
        {
            maxPanelHeight = VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_PORTRAIT;
        }
        else
        {
            maxPanelHeight = VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_PORTRAIT - m_RadioMenu->getItemHeight(0);
        }
        finalWidth = VCP_SELECT_POPUP_WIDTH_PORTRAIT;
        radioWidth = VCP_SELECT_POPUP_RADIO_WIDTH_PORTRAIT;
    }
    else
    {
        if (m_type == VCP_SELECT_POPUP_BUTTON_TYPE_QUICK)
        {
            maxPanelHeight = VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE;
        }
        else
        {
            maxPanelHeight = VCP_SELECT_POPUP_MAX_PANEL_HEIGHT_LANDSCAPE - m_RadioMenu->getItemHeight(0);
        }
        finalWidth = VCP_SELECT_POPUP_WIDTH_LANDSCAPE;
        radioWidth = VCP_SELECT_POPUP_RADIO_WIDTH_LANDSCAPE;
    }

    if (bottomRegionHeight > maxPanelHeight)
    {
        bottomRegionHeight = maxPanelHeight;    
    }
    m_RadioMenu->setPos(finalWidth/2, VCP_SELECT_POPUP_RADIO_Y);
    m_RadioMenu->setSize(radioWidth, bottomRegionHeight);

    if (m_type == VCP_SELECT_POPUP_BUTTON_TYPE_SINGLE || m_type == VCP_SELECT_POPUP_BUTTON_TYPE_MULTI)
    {
        m_buttonPanel->setHidden(VFX_FALSE);
        m_buttonPanel->setPos(0, bottomRegionHeight + VCP_SELECT_POPUP_BUTTON_Y_SHIFT);
        bottomRegionHeight += VCP_SELECT_POPUP_BUTTON_HEIGHT + VCP_SELECT_POPUP_BOTTOM_HEIGHT + VCP_SELECT_POPUP_BUTTON_Y_SHIFT + VCP_BUTTON_SHADOW_MARGIN_BOTTOM;
    }
    else
    {
        m_buttonPanel->setHidden(VFX_TRUE);
        bottomRegionHeight += VCP_SELECT_POPUP_BOTTOM_HEIGHT_QUICK;
    }
    if (!m_isAllowedEmptySelect && getFirstSeletedIndex() == -1)
	{
		m_button[0]->setIsDisabled(VFX_TRUE);
	}
    m_backgroundBottom->setSize(finalWidth, bottomRegionHeight);
    m_backgroundBottomImage->setSize(finalWidth, bottomRegionHeight);
    setBounds(0,0,finalWidth, VCP_SELECT_POPUP_UP_HEIGHT + bottomRegionHeight);
}


void VcpSelectPopup::addItem(VfxId id, const VfxWString &text, VfxBool isSelected)
{   
    VcpSelectCoreData tempItem;
    tempItem.m_id = id;
    tempItem.m_text = text;
    tempItem.m_isSelect = isSelected;
    tempItem.m_isDisable = VFX_FALSE;

	this->m_RadioMenu->addItem(&tempItem);
    
    m_itemCount ++;
    checkUpdate();
}

void VcpSelectPopup::updateItem(VfxId id, const VfxWString &text)
{
	VcpSelectCoreData tempItem;
    tempItem.m_id = id;
    tempItem.m_text = text;    
    m_RadioMenu->updateItem(tempItem);
}
void VcpSelectPopup::setTextAlignMode(VfxTextFrame::AlignModeEnum value)
{
    m_textFrame->setAlignMode(value);
    checkUpdate();
}


void VcpSelectPopup::setType(VcpSelectPopupTypeEnum type)
{
    m_type = type;
    switch (m_type)
    {
        case VCP_SELECT_POPUP_BUTTON_TYPE_QUICK:
            m_RadioMenu->setType(VCP_LIST_MENU_MODE_HEAD_SINGLE_CHECK_MARK);
            break;
        case VCP_SELECT_POPUP_BUTTON_TYPE_SINGLE:
            m_RadioMenu->setType(VCP_LIST_MENU_MODE_SINGLE_SELECTION);
            break;
        case VCP_SELECT_POPUP_BUTTON_TYPE_MULTI:
            m_RadioMenu->setType(VCP_LIST_MENU_MODE_MULTI_SELECTION);
            break;
        default:
            break;
    }
    checkUpdate();
}


void VcpSelectPopup::setText(const VfxWString &text)
{
    m_textFrame->setString(text);
    checkUpdate();
}

VfxS32 VcpSelectPopup::getFirstSeletedIndex()
{
    return getNextSelectedIndex(-1);
}

VfxS32 VcpSelectPopup::getNextSelectedIndex(VfxS32 index)
{
    VfxS32 i;
    for (i = index + 1; i < m_itemCount; i++)
    {
        if (m_RadioMenu->getIsSelected(i))
        {
            return i;
        }
    }
    return -1;
}

VfxId VcpSelectPopup::getIdbyIndex(VfxS32 index)
{
    if (index < 0 || index >= m_itemCount)
    {
        return 0;
    }

    return m_RadioMenu->getItemId(index);
}


void VcpSelectPopup::onButtonClick(VfxObject* sender, VfxId id)
{
    if (m_buttonPressed)
    {
        return;
    }
    m_buttonPressed = VFX_TRUE;
    
    m_signalButtonClicked.postEmit(this, id);
    leave(VFX_TRUE);
}


void VcpSelectPopup::onSelectionChanged(VfxObject* sender, VfxU32 index)
{
    if (m_type == VCP_SELECT_POPUP_BUTTON_TYPE_QUICK)
    {
        m_signalButtonClicked.postEmit(this, VCP_SELECT_POPUP_BUTTON_OK);
		m_buttonPressed = VFX_TRUE;
        leave(VFX_TRUE);
    }
	else if (!m_isAllowedEmptySelect && getFirstSeletedIndex() == -1)
	{
		m_button[0]->setIsDisabled(VFX_TRUE);
	}
	else
	{
		m_button[0]->setIsDisabled(VFX_FALSE);
	}
}

void VcpSelectPopup::setIsDisableItem(VfxId id, VfxBool isDisable)
{
    m_RadioMenu->setIsDisableItem(id, isDisable);
}

VfxBool VcpSelectPopup::getIsDisableItem(VfxId id)
{
    return m_RadioMenu->getIsDisableItem(id);
}
    // set title text
void VcpSelectPopup::setText(const VfxWChar* text)
{
    setText(VFX_WSTR_MEM(text));
}
void VcpSelectPopup::addItem(VfxId id, const VfxWChar* text, VfxBool isSelected)
{
    addItem(id, VFX_WSTR_MEM(text), isSelected);
}
void VcpSelectPopup::updateItem(VfxId id, const VfxWChar* text)
{
    updateItem(id, VFX_WSTR_MEM(text));
}
void VcpSelectPopup::setText(VfxResId text)
{
    setText(VFX_WSTR_RES(text));
}
void VcpSelectPopup::addItem(VfxId id, VfxResId text, VfxBool isSelected)
{
    addItem(id, VFX_WSTR_RES(text), isSelected);
}

void VcpSelectPopup::updateItem(VfxId id, VfxResId text)
{
    updateItem(id, VFX_WSTR_RES(text));
}
