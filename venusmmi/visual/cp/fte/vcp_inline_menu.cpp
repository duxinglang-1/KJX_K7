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
*  vcp_inline_menu.cpp
*
* Project:
* --------
*  Venus
*
* Description:
* ------------
*  Inline menu source file
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
 *
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
*
 * removed!
 * removed!
 * removed!
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
#include "vcp_inline_menu.h"
#include "vfx_cpp_base.h"
#include "vadp_sys_trc.h"
#include "vfx_datatype.h"
#include "string.h"
#include "vcp_scrollable.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "kal_trace.h"
#include "vfx_system.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "vfx_string.h"
#include "vfx_frame.h"
#include "vfx_basic_type.h"
#include "vrt_datatype.h"
#include "vfx_image_src.h"
#include "mmi_rp_srv_venus_component_inline_menu_def.h"
#include "vfx_signal.h"
#include "vfx_auto_animate.h"
#include "vfx_animation.h"
#include "vcp_option_menu.h"
#include "vfx_input_event.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vfx_control.h"
#include "vfx_primitive_frame.h"
#include "GlobalResDef.h"
#include "vcp_switch.h"
/***************************************************************************** 
* Define
*****************************************************************************/
#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif



/***************************************************************************** 
* Class VcpInlineMenu
*****************************************************************************/
VcpInlineMenu::VcpInlineMenu():
m_groupcount(0),
m_layout(NULL),	
m_focusedCell(0xFFFFFFFF),
m_activeRadioList(NULL)
{
    memset(m_cellCountInGroup, 0, sizeof(VfxS32)*MAX_CELLS);
}

VcpInlineMenu::~VcpInlineMenu()
{}

class VcpInlineMenuLayout;
void VcpInlineMenu::onInit()
{
    VcpScrollable::onInit();	

    setIsCached(VFX_TRUE);
    setIsOpaque(VFX_TRUE);
    setAutoAnimate(VFX_TRUE);

    m_layout = (VcpInlineMenuLayout *)createLayout();
    VFX_OBJ_CREATE(m_indexer, VcpInlineCellIndexer, this);
    //m_visual = createVisual();    
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_INITIALIZED_MSG);
}
void VcpInlineMenu::onDeinit()
{
    VFX_OBJ_CLOSE(m_layout);	
    VFX_OBJ_CLOSE(m_indexer);
    VFX_OBJ_CLOSE(m_activeRadioList);
    VcpScrollable::onDeinit();	
}

void VcpInlineMenu::onPendingActivityCompletion(VfxId cellid, VfxBool success)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_ACT_COMP_MSG, cellid, success);
    //resumeMenu();
    if(VFX_TRUE== success) // Swicth can be toggled
    {
        VcpInlineCellSwitch *cellframe = (VcpInlineCellSwitch*) m_indexer->getCell(cellid);
        ASSERT(cellframe->m_Celltype == VCP_INL_CELLTYPE_SWITCH);
        cellframe->setSwitchStatus(!cellframe->getSwitchStatus());
    }
}

VcpInlineMenuLayout* VcpInlineMenu::createLayout()
{
    VcpInlineMenuLayout *layout;
    VFX_OBJ_CREATE_EX(layout, VcpInlineMenuLayout, this, (this));
    return layout;
}

VfxBool VcpInlineMenu::groupHasHeader(VfxS32 idx)
{
    VcpInlineGroup *grp = (VcpInlineGroup*)m_indexer->getCell(idx, -1);
    if(grp->getCaption() != VFX_WSTR_EMPTY)
        return VFX_TRUE;
    else
        return VFX_FALSE;
}

VfxFrame* VcpInlineMenu::createGroupHeader(VfxS32 group)// To add at end, use m_groupcount as input (It can't be set as default parameter)
{
    if(group > m_groupcount || // Groups cannot be left blank.
        m_groupcount >= MAX_CELLS) 
    {
        return NULL;
    }
    VcpInlineGroup *grp;
    VFX_OBJ_CREATE_EX(grp, VcpInlineGroup, this, (group));
    m_groupcount++;	
    m_cellCountInGroup[group] = 0;

    grp->setPos(m_layout->getGroupPos(group));	
    grp->setBounds(	0,
        0, 
        getBounds().size.width - m_layout->MenuGroupLeftGap - m_layout->GroupMenuRightGap,
        0
        );
    grp->setBgColor(VFX_COLOR_GREY);
    grp->setCaption(VFX_WSTR_EMPTY);
    grp->m_currentFrameSize = grp->getBounds().size;
    grp->SetVisibleState(VFX_TRUE);

    if(group > 0)
    {
        VfxImageSrc img;
        img.setResId(VCP_INL_IMG_GROUP_SEP);        
        VFX_OBJ_CREATE(grp->m_sep_frameimg, VfxFrame, grp);
        grp->m_sep_frameimg->setPos(0,0);
        grp->m_sep_frameimg->setBounds(VfxRect(VfxPoint(0,0), VfxSize(grp->getSize().width, img.getSize().height)));
        grp->m_sep_frameimg->setImgContent(img);
        grp->m_sep_frameimg->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    }

    m_indexer->addNewCell(group, -1, VCP_INL_GROUP_ID_BASE + m_groupcount,(VfxFrame *) grp);
    return grp;

}


VfxFrame* VcpInlineMenu::createCell(
                                    VfxS32 group,           // [IN] The group index
                                    VfxS32 pos,             // [IN] The cell index
                                    VfxId id,				// Cell ID
                                    VcpInlineCellTypeEnum celltype
                                    )
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_CREATECELL_MSG, id, group, pos, celltype);
    VcpInlineCellBase *aCell;
    VcpInlineGroup *grp; 
    if(group > m_groupcount)
    {
        return NULL;
    }
    else if (group == m_groupcount && m_groupcount < MAX_CELLS)
    {
        grp = (VcpInlineGroup *)createGroupHeader(group);
    }
    else
    {
        grp = (VcpInlineGroup *)m_indexer->getCell(group, -1);	
        ASSERT(grp);
    }

    if(pos == -1) // If just group was req.
    {
        return grp;
    }

    switch(celltype)
    {

    case VCP_INL_CELLTYPE_BUTTON:			
        VFX_OBJ_CREATE(aCell, VcpInlineCellButton, grp);
        ((VcpInlineCellButton*)aCell)->tapped.connect(this, &VcpInlineMenu::onCellTapped);
        break;
    case VCP_INL_CELLTYPE_SWITCH:	
        VFX_OBJ_CREATE(aCell, VcpInlineCellSwitch, grp);
        ((VcpInlineCellSwitch*)aCell)->SwitchToggled.connect(this, &VcpInlineMenu::onSwitchToggle);
        break;
    case VCP_INL_CELLTYPE_RADIOLIST:			
        VFX_OBJ_CREATE(aCell, VcpInlineCellRadioList, grp);
        ((VcpInlineCellRadioList*)aCell)->SelectionChanged.connect(this, &VcpInlineMenu::onNewOptionSelection);
        ((VcpInlineCellRadioList*)aCell)->tapped.connect(this, &VcpInlineMenu::launch_RadioList);
        break;
    default:
        return NULL;
    }    
    aCell->pos = VcpInlineCellPos(group, pos);
    aCell->id = id;

    m_indexer->addNewCell(group, pos, id, (VfxFrame *) aCell);
    m_cellCountInGroup[group]++;

    //Group bounds need to be extended for new cell
    VfxS32 gap = 0;
    if(aCell->pos.pos) 
    {
        gap += m_layout->CellCellVertGap;
    }
    else //If it's the first cell for this group
    {	
        if(group)
            gap += m_layout->GroupCellTopGap; // Skip this for the very first group

        gap += m_layout->CellGroupBottomGap;	
    }

    VfxRect Grp_bounds = grp->getBounds();	
    grp->setBounds(Grp_bounds.origin.x, 
        Grp_bounds.origin.y, 
        Grp_bounds.size.width, 
        Grp_bounds.size.height + gap);

    m_layout->adjustCell(aCell, grp);	
    m_layout->updateContentSize(); 
    if(group)
        grp->m_sep_frameimg->bringToFront();
    return (VfxFrame*)aCell;		
}

VfxFrame* VcpInlineMenu::createCell(
                                    VcpInlineCellTypeEnum celltype,
                                    VfxId id,					   	// Cell ID        
                                    VfxS32 group = 0	           	// [IN] The group index    
                                    )
{
    return createCell(group, m_cellCountInGroup[group], id, celltype);
}


void VcpInlineMenu::fillCellData(VfxId cellid, VcpInlineCellButtonData *data) 	
{
    VfxFrame *cellframe = m_indexer->getCell(cellid);
    ((VcpInlineCellButton *)cellframe)->update(data);
}

void VcpInlineMenu::fillCellData(VfxId cellid, VcpInlineCellSwitchData *data) 	
{
    VfxFrame *cellframe = m_indexer->getCell(cellid);
    ((VcpInlineCellSwitch *)cellframe)->update(data);
}

void VcpInlineMenu::fillCellData(VfxId cellid, VcpInlineCellRadioListData *data) 	
{
    VfxFrame *cellframe = m_indexer->getCell(cellid);
    ((VcpInlineCellRadioList *)cellframe)->update(data);
}


void VcpInlineMenu::relayoutCellsBelow(VcpInlineCellBase *aCell)
{
    VfxS32 idx = m_indexer->getIndex(aCell->pos.group, aCell->pos.pos);
    VfxFrame *temp_cell = aCell;
    VfxS32 g = aCell->pos.group;
    VfxS32 p = aCell->pos.pos;
    while(temp_cell && p > -1)
    {
        m_layout->adjustCell((VcpInlineCellBase*)temp_cell, (VcpInlineGroup*)m_indexer->getCell(g, -1) );
        temp_cell = m_indexer->getFrame(++idx, g, p);
    }
    while(temp_cell && g < m_layout->getGroupCount())
    {
        temp_cell->setPos(m_layout->getGroupPos(g++));
        temp_cell = m_indexer->getCell( g, -1);		
    }
    m_layout->updateContentSize();

#if defined(__MTK_INTERNAL__)    
#if defined(VCP_INLINE_DEBUGGING_MODE)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

}

VfxFlag VcpInlineMenu::updateCellText(VfxId cellid, VfxWString text)
{
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_BUTTON:
    case VCP_INL_CELLTYPE_SWITCH:
    case VCP_INL_CELLTYPE_RADIOLIST:
        cell->setCellText(text);
        return 1;
    default:
        return 0; //Invalid Cell
    }		

}

VfxFlag VcpInlineMenu::updateCellIcon(VfxId cellid, VfxResId icon)
{
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_BUTTON:
    case VCP_INL_CELLTYPE_SWITCH:
    case VCP_INL_CELLTYPE_RADIOLIST:
        cell->setCellIcon(icon);
        return 1;
    default:
        return 0; //Invalid Cell
    }		
}

VfxFlag VcpInlineMenu::updateCellHinttext(VfxId cellid, VfxWString text)
{
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_BUTTON:
        ((VcpInlineCellButton *)cell)->setCellHintText(text);
        break;
    default:
        return 0; //Invalid Cell
    }		
    relayoutCellsBelow(cell);
    return 1;
}

VfxFlag VcpInlineMenu::updateCellaccessory(VfxId cellid, VcpInlineAccessoryEnum Acc)
{
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_BUTTON:
    case VCP_INL_CELLTYPE_RADIOLIST:
        cell->setAccessory(Acc);
        return 1;
    default:
        return 0; //Invalid Cell
    }		
}

VfxFlag VcpInlineMenu::updateCellSwitchStatus(VfxId cellid, VfxBool switchState)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_UPDATE_SWITCH_MSG, cellid, switchState);
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_SWITCH:	
        ((VcpInlineCellSwitch *)cell)->setSwitchStatus(switchState);
        return 1;
    default:
        return 0; //Invalid Cell
    }		
}

VfxFlag VcpInlineMenu::updateCellOptionList(VfxId cellid, VcpInlineRadioListOptionStruct *optionlist)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_UPDATE_OPTION_LIST_MSG, cellid);
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_RADIOLIST:	
        ((VcpInlineCellRadioList *)cell)->setOptionList(optionlist);
        return 1;
    default:
        return 0; //Invalid Cell
    }		

}

VfxFlag VcpInlineMenu::updateCellSelectedOption(VfxId cellid, VfxS32 selected)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_UPDATE_SELCTD_OPTION_MSG, cellid, selected);
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_RADIOLIST:	
        ((VcpInlineCellRadioList *)cell)->setSelectedOption(selected);
        return 1;
    default:
        return 0; //Invalid Cell
    }		
}	

VfxFlag VcpInlineMenu::updateCellIncrementTotalOptions(VfxId cellid, VfxS32 optionsIncreased)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_UPDATE_ADD_OPTION_MSG, cellid, optionsIncreased);
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_RADIOLIST:
        ((VcpInlineCellRadioList *)cell)->setTotalOptions(((VcpInlineCellRadioList *)cell)->getTotalOptions() + optionsIncreased);
        return 1;
    default:
        return 0; //Invalid Cell
    }		 
}

VfxFlag VcpInlineMenu::updateCellSetTotalOptions(VfxId cellid, VfxS32 optionsCount)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_SET_TOTAL_OPTIONS_MSG, cellid, optionsCount);
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_RADIOLIST:
        ((VcpInlineCellRadioList *)cell)->setTotalOptions(optionsCount);
        return 1;
    default:
        return 0; //Invalid Cell
    }		
}

VfxS32 VcpInlineMenu::queryCellGetTotalOptions(VfxId cellid)
{
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_RADIOLIST:                
        return ((VcpInlineCellRadioList *)cell)->getTotalOptions();
    default:
        return -1; //Invalid Cell
    }		
}

VfxFlag VcpInlineMenu::updateCellVisibility(VfxId cellid, VfxBool visibility)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_UPDATE_VISIBILITY_MSG, cellid, visibility);
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_BUTTON:
    case VCP_INL_CELLTYPE_SWITCH:
    case VCP_INL_CELLTYPE_RADIOLIST:
        cell->SetVisibility(visibility);
        break;
    default:
        return 0; //Invalid Cell
    }		

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_FALSE);    
    VfxAutoAnimate::setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);   
    VfxAutoAnimate::setDuration(300);

    relayoutCellsBelow(cell);

    VfxAutoAnimate::commit();	
}

VfxFlag VcpInlineMenu::updateCellActiveState(VfxId cellid, VfxBool state)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_UPDATE_ACTIVE_STATE_MSG, cellid, state);
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    cell->m_isActive = state;
    if(VFX_FALSE == state)
    {
        VFX_OBJ_CREATE(cell->m_cover, VfxFrame, cell->getParentFrame());
        cell->m_cover->setPos(cell->getPos());        
        cell->m_cover->setBounds(cell->getBounds());		
        cell->m_cover->setBgColor(VFX_COLOR_BLACK);
        cell->m_cover->setOpacity(0.125);
    }
    else
    {
        VFX_OBJ_CLOSE(cell->m_cover);
    }
    cell->update();
    return 1;
}

void VcpInlineMenu::onCellTapped(VfxId cellid)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_ONCELLTAP_MSG, cellid);
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);

    VcpInlineCellBase *currentFocus = (VcpInlineCellBase*)m_indexer->getCell(m_focusedCell);

    if(currentFocus)
    {	
        currentFocus->m_isFocussed = VFX_FALSE;
        currentFocus->update();
        cell->m_isFocussed = VFX_TRUE;
        m_focusedCell = cellid;
        cell->update();
    }


    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_BUTTON:
    case VCP_INL_CELLTYPE_RADIOLIST:
        VFX_LOG(VFX_INFO2, VCP_INLINEMENU_ONCELLTAP_EMIT, cellid);
        Cell_Tapped.emit(cellid);
        break;
    default:
        break;
    }	
}


void VcpInlineMenu::launch_RadioList(VfxId cellid)	
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_RADIOLIST_LAUNCH_MSG, cellid);
    VcpInlineCellRadioList *cell = (VcpInlineCellRadioList *)m_indexer->getCell(cellid);
    VFX_OBJ_CREATE(cell->m_RadioListMenu, VcpOptionMenu, findScreen());
    m_activeRadioList = cell->m_RadioListMenu;
    cell->m_RadioListMenu->setIsAutoClose(VFX_TRUE);
    cell->fillOptionList();
    cell->m_RadioListMenu->m_signalMenuCallback.connect(cell, &VcpInlineCellRadioList::onCloseRadiolist);            
    cell->m_RadioListMenu->showMenu();
}


void VcpInlineMenu::onSwitchToggle(VfxId cellid, VfxBool newState)
{
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_SWITCH:
        {
            VcpInlineCellSwitch *cellSwitch = (VcpInlineCellSwitch *)cell;

            //Nullify the switch toggle done by VcpSwitch (should be done after app. processes the event)
            cellSwitch->setSwitchStatus(!cellSwitch->getSwitchStatus(), VFX_FALSE);
            SwitchChangedTo.emit(cellid, newState);
        }
        break;
    default:
        break;
    }		
}

void VcpInlineMenu::onNewOptionSelection(VfxId cellid, VfxS32 newSelection)
{
    VcpInlineCellBase *cell = (VcpInlineCellBase*)m_indexer->getCell(cellid);
    switch(cell->m_Celltype)
    {
    case VCP_INL_CELLTYPE_RADIOLIST:
        NewOptionSelected.emit(cellid, newSelection);
        break;
    default:
        break;
    }		
}



VfxBool VcpInlineMenu::onPenInput(VfxPenEvent &event)
{
    return VcpScrollable::onPenInput(event);
}


void VcpInlineMenu::suspendMenu()
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_SUSPEND_MSG); 
    VFX_OBJ_CREATE(m_cover, VfxFrame, getParentFrame());
    m_cover->setPos(getPos());        
    m_cover->setBounds(VfxRect(VfxPoint(0,0),m_view->getContentSize()));
    m_cover->setBgColor(VFX_COLOR_BLACK);
    m_cover->setOpacity(0.5);
}

void VcpInlineMenu::resumeMenu()
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_RESUME_MSG); 
    VFX_OBJ_CLOSE(m_cover);
}
/*****************************************************************************
* Class VcpInlineCellIndexer
*****************************************************************************/
VcpInlineCellIndexer::VcpInlineCellIndexer():
m_itemCount(0), 
m_availableCount(data_chunk)
{
    VFX_ALLOC_MEM(cellTable , (VfxU32)m_availableCount * sizeof(Celldata), this);
    memset(cellTable , 0, sizeof(Celldata ) * m_availableCount);

    VFX_ALLOC_MEM(cellIdTable, (VfxU32)m_availableCount * sizeof(CellIdIndexedData), this);     
    memset(cellIdTable , 0, sizeof(CellIdIndexedData ) * m_availableCount);
}

VcpInlineCellIndexer::~VcpInlineCellIndexer()
{
    for (VfxU32 i = 0; i < m_itemCount; i++)
    {
        VFX_DELETE(cellTable[i]);

        VFX_DELETE(cellIdTable[i]);
    }
    VFX_FREE_MEM(cellTable);
    VFX_FREE_MEM(cellIdTable);

    cellTable = NULL;
    cellIdTable = NULL;

    m_itemCount = 0;
    m_availableCount = 0;
}

VfxS32 VcpInlineCellIndexer::bisect_left(Key key)
{
    VfxS32 lo = 0, hi = m_itemCount, mid;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (cellTable[mid]->key < key) 
            lo = mid + 1;
        else
            hi = mid;
    }
    return lo;
}


void VcpInlineCellIndexer::addNewCell(VfxS32 group, VfxS32 pos, VfxId cellid, VfxFrame *cellframe)
{
    if (group < 0 || pos < -1 || (!cellframe)) // Invalid position
    {
        VFX_DEV_ASSERT(0);
        return;
    }

    if(pos > -1 && 
        (cellid > VCP_INL_GROUP_ID_BASE && cellid < VCP_INL_GROUP_ID_END )) // Reserved range shoudl not be used for cells
    {
        VFX_DEV_ASSERT(0);
        return;
    }

    if (getIndex(cellid) >= 0 ||
        getIndex(group, pos) >= 0 ) // ID already indexed
    {
        VFX_DEV_ASSERT(0);
        return;
    }	

    Key key = makeKey(group, pos);
    VfxS32 idx = bisect_left(key);

    VfxS32 idx_in_id_table;
    /* Search the location for new id in list sorted with cell_id */
    VfxS32 lo = 0, hi = m_itemCount, mid;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (cellIdTable[mid]->cellid < cellid) 
            lo = mid + 1;
        else
            hi = mid;
    }
    idx_in_id_table = lo;


    VFX_DEV_ASSERT(idx <= m_itemCount);

    if (m_itemCount == m_availableCount)
    {
        // the space is not enough
        Celldata 			**new_cells;
        CellIdIndexedData 	**new_id_cells;

        m_availableCount += m_availableCount + data_chunk;


        VFX_ALLOC_MEM(new_cells, (VfxU32)m_availableCount * sizeof(Celldata), this);
        VFX_ALLOC_MEM(new_id_cells, (VfxU32)m_availableCount * sizeof(CellIdIndexedData), this);     

        memset(new_cells, 0, sizeof(Celldata*) * m_availableCount);
        memcpy(new_cells, cellTable, sizeof(Celldata*) * m_itemCount);

        memset(new_id_cells, 0, sizeof(CellIdIndexedData*) * m_availableCount);
        memcpy(new_id_cells, cellIdTable, sizeof(CellIdIndexedData*) * m_itemCount);

        VFX_FREE_MEM(cellTable);
        VFX_FREE_MEM(cellIdTable);

        cellTable = new_cells;
        cellIdTable = new_id_cells;
    }

    VFX_DEV_ASSERT(m_availableCount > m_itemCount);

    m_itemCount++;
    VfxS32 i;
    for (i = m_itemCount - 1; i > idx; i--)
    {
        cellTable[i] = cellTable[i - 1];	
    }

    VFX_ALLOC_NEW(cellTable[idx], Celldata, this);
    cellTable[idx]->key = key;
    cellTable[idx]->cellframe = cellframe;


    for (i = m_itemCount - 1; i > idx_in_id_table; i--)
    {     
        cellIdTable[i] = cellIdTable[i - 1];
    }
    VFX_ALLOC_NEW(cellIdTable[idx_in_id_table], CellIdIndexedData, this);
    cellIdTable[idx_in_id_table]->cellid = cellid;
    cellIdTable[idx_in_id_table]->cellframe = cellframe;	
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

VfxFrame* VcpInlineCellIndexer::getCell(VfxS32 group, VfxS32 pos)
{
    VfxS32 idx = getIndex(group, pos);
    if(idx >= 0)
        return cellTable[idx]->cellframe;    
    else
        return NULL;
}

VfxS32 VcpInlineCellIndexer::getIndex(VfxS32 group, VfxS32 pos)
{
    if (group < 0 || pos < -1)
        return -1;

    Key key = makeKey(group, pos);
    VfxS32 idx = bisect_left(key);
    if (idx >= m_itemCount) // cannot find
        return -1;

    if (cellTable[idx]->key != key)
        return -1;

    return idx;    	
}

VfxFrame *VcpInlineCellIndexer::getFrame(VfxS32 idx, VfxS32 &g, VfxS32 &p)
{
    g = 0;
    p = 0;
    if(idx >= m_itemCount || idx < 0)
        return  NULL;
    VcpInlineCellPos cellpos = decodeKey(cellTable[idx]->key);
    g = cellpos.group;
    p = cellpos.pos;
    return cellTable[idx]->cellframe;	
}



VfxFrame *VcpInlineCellIndexer::getCell(VfxId cellid)
{
    VfxS32 idx = getIndex(cellid);
    if(idx >= 0)
        return cellIdTable[idx]->cellframe;    
    else
        return NULL;
}

VfxS32 VcpInlineCellIndexer::getIndex(VfxId cellid)
{
    VfxS32 idx;
    /* Search the location for new id in list sorted with cell_id */
    VfxS32 lo = 0, hi = m_itemCount, mid;
    while (lo < hi)
    {
        mid = (lo + hi) / 2;
        if (cellIdTable[mid]->cellid < cellid) 
            lo = mid + 1;
        else
            hi = mid;
    }
    idx = lo;

    if (idx >= m_itemCount) // cannot find
        return -1;

    if (cellIdTable[idx]->cellid != cellid)
        return -1;

    return idx;    	
}

VfxFrame *VcpInlineCellIndexer::getFrame(VfxS32 idx, VfxId &cellid)
{
    cellid = 0;
    if(idx >= m_itemCount || idx < 0)
        return  NULL;
    cellid = cellIdTable[idx]->cellid;	
    return cellIdTable[idx]->cellframe;	
}

/*****************************************************************************
* Class VcpInlineGroup
*****************************************************************************/

VcpInlineGroup::VcpInlineGroup():
m_caption(NULL),
m_cellCount(0),
m_visibility(VFX_TRUE),
m_sep_frameimg(NULL),
m_currentFrameSize(VfxSize(0,0))
{}

VcpInlineGroup::VcpInlineGroup(VfxS32 idx, VfxWString *text):
m_caption(NULL),
m_sep_frameimg(NULL),
m_cellCount(0)
{
}

VcpInlineGroup::~VcpInlineGroup()
{}

void VcpInlineGroup::setCaption(const VfxWString& text)
{
    if(!m_caption)
    {
        VFX_OBJ_CREATE(m_caption, VfxTextFrame, this);
    }       
    VfxS32 caption_height = 50;
    m_caption->setString((const VfxWString &)text);        
    m_caption->setPos(5,5);
    m_caption->setSize(100, 30);
    m_caption->setColor(VFX_COLOR_WHITE);
    m_caption->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));
    m_caption->setBounds(0,0,150,caption_height); // TODO: pick it up from m_layout
    m_caption->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_caption->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_caption->setAutoResized(VFX_FALSE);    

    VfxRect prevBounds = getBounds();

    if(text == VFX_WSTR_EMPTY)
        caption_height = 0;

    setBounds(prevBounds.origin.x, prevBounds.origin.y, prevBounds.size.width, prevBounds.size.height + caption_height);
}

void VcpInlineGroup::setBkgImage(VfxResId img)
{
}


VfxWString VcpInlineGroup::getCaption()
{
    return m_caption->getString();
}

void VcpInlineGroup::SetVisibleState(VfxBool state)
{
    m_visibility = state;
    if(VFX_TRUE == m_visibility)
    {
        setBounds(0,0,m_currentFrameSize.width, m_currentFrameSize.height);
        setHidden(VFX_FALSE); 
    }
    else
    {
        m_currentFrameSize = getBounds().size; // Save the bounds
        setHidden(VFX_TRUE); // Hide the frame
    }
}

VfxBool VcpInlineGroup::isVisible()
{
    return m_visibility;
}

VfxBool VcpInlineGroup::onPenInput(VfxPenEvent &event)
{    
    return VfxControl::onPenInput(event);
}

/*****************************************************************************
* Class VcpInlineCellBase
*****************************************************************************/
VcpInlineCellBase::VcpInlineCellBase():
m_textframe(NULL),
m_iconframe(NULL),
m_accframe(NULL),
m_isFocussed(VFX_FALSE),
Cellheight(50),
pos(VcpInlineCellPos(-1,-1)),
m_visibility(VFX_TRUE),
m_currentFrameSize(VfxSize(0,0)),
m_isActive(VFX_TRUE),
m_cover(NULL)
{}

VcpInlineCellBase::VcpInlineCellBase(VcpInlineCellPos p):
m_textframe(NULL),
m_iconframe(NULL),
m_accframe(NULL),
m_isFocussed(VFX_FALSE),
Cellheight(30),
pos(p),
m_currentFrameSize(VfxSize(0,0))
{}

VcpInlineCellBase::~VcpInlineCellBase()
{}

void VcpInlineCellBase::setPos(const VfxPoint &value)
{
    VfxFrame::setPos(value);
    if(m_cover)
        m_cover->setPos(value);
}

void VcpInlineCellBase::setBounds(const VfxRect &value)
{
    VfxFrame::setBounds(value);
    if(m_cover)
        m_cover->setBounds(value);
}

void VcpInlineCellBase::onInit()
{	
    VfxControl::onInit();
    Cellheight = VCP_INL_CELL_HEIGHT;

    m_bkg.setResId(VCP_INL_IMG_CELL_BKG_NORM);
    setImgContent(m_bkg);
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

    VFX_OBJ_CREATE(m_iconframe, VfxImageFrame, this);
    m_iconframe->setHidden(VFX_TRUE);

    VFX_OBJ_CREATE(m_textframe, VfxTextFrame, this);
    m_textframe->setPos(VCP_INL_TEXT_LEFT_GAP,5);
    m_textframe->setBounds(0,0,70,Cellheight);		

    VFX_OBJ_CREATE(m_accframe, VfxImageFrame, this);	
    m_accframe->setHidden(VFX_TRUE);

    setIsCached(VFX_TRUE);
    setIsOpaque(VFX_TRUE);

    setBounds(VfxRect(0,0,0,0));

    setAutoAnimate(VFX_TRUE);

}

void VcpInlineCellBase::setCellBounds(VfxS32 x, VfxS32 y, VfxS32 width, VfxS32 height)
{
    setBounds(VfxRect(x, y, width, height));
}

void VcpInlineCellBase::onDeinit()
{
    VFX_OBJ_CLOSE(m_textframe);
    VFX_OBJ_CLOSE(m_iconframe);
    VFX_OBJ_CLOSE(m_accframe);		

    VfxControl::onDeinit();
}

void VcpInlineCellBase::setCellText(VfxWString text)
{
    m_textframe->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_MEDIUM)); //Ask visual obj to get these values
    m_textframe->setColor(VRT_COLOR_MAKE(255, 26,26,26));
    m_textframe->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_textframe->setPos(VCP_INL_TEXT_LEFT_GAP,
        (getBounds().size.height - 18)>>1 ); //Center aligned (vertically)

    m_textframe->setString((const VfxWString &)text);
    m_textframe->setSize(150, 30);
    m_textframe->setAutoResized(VFX_FALSE);
    m_textframe->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
}

void VcpInlineCellBase::setCellIcon(VfxResId icon)
{
    m_iconframe->setResId(icon);
}

void VcpInlineCellBase::update()
{
    if(VFX_TRUE == m_isActive)
    {
        m_textframe->setColor(VRT_COLOR_MAKE(255, 26,26,26));	
    }
    else
    {
        m_textframe->setColor(VRT_COLOR_MAKE(255, 138,138,138));
    }
}


void VcpInlineCellBase::setAccessory(VcpInlineAccessoryEnum accessory)
{
    m_accessory = accessory;
    VfxImageSrc acc_img;    
    switch(accessory)
    {
    case VCP_INL_ACC_NONE:
        acc_img.setResId(IMG_NONE);       
        return;
    case VCP_INL_ACC_NEXT_STEP_IND:
        acc_img.setResId(VCP_INL_IMG_ACC_NEXT_ITEM_NORM);
        break;
    case VCP_INL_ACC_CHECK_MARK:
        acc_img.setResId(IMG_NONE);
        break;
    case VCP_INL_ACC_POPUP_RADIO_LIST:
        acc_img.setResId(IMG_NONE);
        break;
    default:
        break;
    }	
    m_accframe->setImgContent(acc_img);
    m_accframe->setPos(getSize().width - VCP_INL_ACC_RIGHT_GAP - acc_img.getSize().width , (getSize().height - acc_img.getSize().height)>>1 );
    m_accframe->setBounds(0,0,20,20);
    m_accframe->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_TOP_LEFT);
    m_accframe->setHidden(VFX_FALSE);
}

VfxWString VcpInlineCellBase::getCellText()
{
    return (VfxWString)(m_textframe->getString());
}

VfxResId VcpInlineCellBase::getCellIcon()
{
    return m_iconframe->getResId();
}

VcpInlineAccessoryEnum VcpInlineCellBase::getAccessory()
{
    return m_accessory;
} 

void VcpInlineCellBase::SetVisibility(VfxBool state)
{
    m_visibility = state;
}

VfxBool VcpInlineCellBase::isVisible()
{
    return m_visibility;
}


VfxBool VcpInlineCellBase::onPenInput(VfxPenEvent &event)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_CELLBASE_PEN_EVENT, event.type);
    if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
    {
        m_bkg.setResId(VCP_INL_IMG_CELL_BKG_PRESSED);
        setImgContent(m_bkg);    
    }
    else if (event.type == VFX_PEN_EVENT_TYPE_UP ||
                   event.type == VFX_PEN_EVENT_TYPE_ABORT)
    {
        m_bkg.setResId(VCP_INL_IMG_CELL_BKG_NORM);        
        setImgContent(m_bkg);    
    }
    VfxControl::onPenInput(event);
    return VFX_TRUE;
}

/*****************************************************************************
* Class VcpInlineCellButton
*****************************************************************************/
VcpInlineCellButton::VcpInlineCellButton():
m_hinttext(NULL)
{}

void VcpInlineCellButton::onInit()
{
    VcpInlineCellBase::onInit();
    m_Celltype = VCP_INL_CELLTYPE_BUTTON;
    setIsCached(VFX_TRUE);
    setIsOpaque(VFX_TRUE);

}

void VcpInlineCellButton::onDeinit()
{
    VcpInlineCellBase::onDeinit();
}

void VcpInlineCellButton::update(VcpInlineCellButtonData *data)
{
    setCellText(VFX_WSTR_RES(data->text));
    setCellIcon(data->icon);
    setAccessory(data->accessory);	
}
VfxBool VcpInlineCellButton::onPenInput(VfxPenEvent &event)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_CELLBTN_PEN_EVENT, event.type);
    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_UP:
        if(m_bkg.getResId() == VCP_INL_IMG_CELL_BKG_PRESSED)
        {
            tapped.emit(id);
        }
    default:
        break;
    }		
    VcpInlineCellBase::onPenInput(event);
    return VFX_TRUE;    
}

void VcpInlineCellButton::setCellHintText(VfxWString hinttext)
{
    if(!m_hinttext)
        VFX_OBJ_CREATE(m_hinttext, VfxTextFrame, this);
    if(m_hinttext->getString() == VFX_WSTR_EMPTY)
    {
        Cellheight = VCP_INL_CELL_HEIGHT;
    }
    else
    {
        Cellheight = VCP_INL_WIDE_CELL_HEIGHT;
        m_textframe->setPos(VCP_INL_TEXT_LEFT_GAP,
            (Cellheight - VCP_INL_NORMAL_FONT_SIZE - VCP_INL_HINT_FONT_SIZE - VCP_INL_TEXT_HINT_VERT_GAP)>>1 );
    }

    m_hinttext->setString((const VfxWString)hinttext);
    m_hinttext->setColor(VRT_COLOR_MAKE(255, 138,138,138));
    m_hinttext->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));
    m_hinttext->setPos(VCP_INL_TEXT_LEFT_GAP, 
        m_textframe->getPos().y + VCP_INL_NORMAL_FONT_SIZE + VCP_INL_TEXT_HINT_VERT_GAP);
    m_hinttext->setSize(100, 20);
    m_hinttext->setAutoResized(VFX_FALSE);
    m_hinttext->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);                        
}

/*****************************************************************************
* Class VcpInlineCellSwitch
*****************************************************************************/
VcpInlineCellSwitch::VcpInlineCellSwitch():
m_switch(NULL)
{}

VcpInlineCellSwitch::~VcpInlineCellSwitch()
{}

void VcpInlineCellSwitch::onInit()
{
    VcpInlineCellBase::onInit();
    m_accframe->setHidden(VFX_TRUE);
    VFX_OBJ_CREATE(m_switch, VcpSwitch, this);
    m_switch->setChecked(VFX_FALSE);
    m_switch->m_signalSwitchChanged.connect(this, &VcpInlineCellSwitch::onSwitchToggled);
    m_Celltype = VCP_INL_CELLTYPE_SWITCH;

    setIsCached(VFX_TRUE);
    setIsOpaque(VFX_TRUE);

}

void VcpInlineCellSwitch::onDeinit()
{
    VFX_OBJ_CLOSE(m_switch);
    VcpInlineCellBase::onDeinit();
}


void VcpInlineCellSwitch::setSwitchStatus(VfxBool status, VfxBool isAnim) //Sets the status as specified
{
    m_switch->setChecked(status, isAnim);
}

VfxBool VcpInlineCellSwitch::getSwitchStatus()
{
    return m_switch->getChecked();
}

void VcpInlineCellSwitch::update(VcpInlineCellSwitchData *data)
{
    setCellText(VFX_WSTR_RES(data->text));
    setCellIcon(data->icon);
    setSwitchStatus(data->switchState);
    m_switch->setPos(getSize().width - VCP_INL_SWITCH_RIGHT_GAP - m_switch->getSize().width , 
        (getSize().height - m_switch->getSize().height)>>1 );
}

void VcpInlineCellSwitch::onSwitchToggled(VcpSwitch *theSwitch, VfxBool newState)
{
    VFX_UNUSED(theSwitch);    
    SwitchToggled.emit(id, newState);
}

/*****************************************************************************
* Class VcpInlineCellRadioList
*****************************************************************************/
VcpInlineCellRadioList::VcpInlineCellRadioList()
{}

VcpInlineCellRadioList::~VcpInlineCellRadioList()
{}

void VcpInlineCellRadioList::onInit()
{
    VcpInlineCellBase::onInit();
    VFX_OBJ_CREATE(m_hinttext, VfxTextFrame, this);
    m_Celltype = VCP_INL_CELLTYPE_RADIOLIST;
    m_totalOptions = 0;
    Cellheight = VCP_INL_WIDE_CELL_HEIGHT;
    setIsCached(VFX_TRUE);
    setIsOpaque(VFX_TRUE);

}

void VcpInlineCellRadioList::onDeinit()
{
    VcpInlineCellBase::onDeinit();
}
void VcpInlineCellRadioList::setOptionList(VcpInlineRadioListOptionStruct *optionlist)
{
    m_optionList = optionlist;
}
void VcpInlineCellRadioList::setSelectedOption(VfxS32 idx) //Sets the given index as selected option
{
    if(NULL == m_optionList)
    {
        return;
    }
    ASSERT((idx >=0) && (idx < m_totalOptions));
    m_selectedOption = idx;
    m_hinttext->setString((const VfxWString &)(m_optionList[m_selectedOption].text));
    m_hinttext->setColor(VRT_COLOR_MAKE(255, 138,138,138));
    m_hinttext->setFont(VfxFontDesc(VFX_FONT_DESC_SIZE_SMALL));
    m_textframe->setPos(VCP_INL_TEXT_LEFT_GAP,		
        (Cellheight - VCP_INL_NORMAL_FONT_SIZE - VCP_INL_HINT_FONT_SIZE - VCP_INL_TEXT_HINT_VERT_GAP)>>1 );

    m_hinttext->setPos(VCP_INL_TEXT_LEFT_GAP, 
        m_textframe->getPos().y + VCP_INL_TEXT_HINT_VERT_GAP+ VCP_INL_NORMAL_FONT_SIZE);
    m_hinttext->setSize(100, 20);
    m_hinttext->setAutoResized(VFX_FALSE);
    m_hinttext->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);


}

void VcpInlineCellRadioList::setTotalOptions(VfxS32 options)
{
    m_totalOptions = options;
}


void VcpInlineCellRadioList::addOptionToList(VfxWString text)
{
    VcpOptionMenuItem *newitem = m_RadioListMenu->createRadioMenuItem(m_totalOptions, text, VFX_FALSE);
    m_RadioListMenu->appendItem(NULL, newitem);
}


void VcpInlineCellRadioList::removeOptionFromList(VfxS32 idx)
{}

void VcpInlineCellRadioList::update(VcpInlineCellRadioListData *data)
{
    setCellText(VFX_WSTR_RES(data->text));
    setCellIcon(data->icon);
    setAccessory(data->accessory);
    setOptionList(data->optionList);
    //The order for following two calls is important. It shouldn't change.
    setTotalOptions(data->total_options);
    setSelectedOption(data->selectedoption);
}

void VcpInlineCellRadioList::fillOptionList()
{
    VfxBool OptionCheckState = VFX_FALSE;    
    for(VfxS32 i=0; i< m_totalOptions; i++)
    {	
        if(m_selectedOption == i)
            OptionCheckState  = VFX_TRUE;
        else
            OptionCheckState  = VFX_FALSE;

        VcpOptionMenuItem *newitem = m_RadioListMenu->createRadioMenuItem((VfxU32)i, (VfxWString)m_optionList[i].text, OptionCheckState, (VfxImageSrc)m_optionList[i].icon  );
        m_RadioListMenu->appendItem(NULL, newitem);
    }
}

void VcpInlineCellRadioList::onCloseRadiolist(VcpOptionMenu* opMenu, VcpOptionMenu::VcpOptionMenuEventEnum list_event, VcpOptionMenuItem* item)
{
    switch(list_event)
    {
    case VcpOptionMenu::VCP_OPTION_MENU_EVENT_ITEM_SELECTED:
        setSelectedOption(item->getId());
        SelectionChanged.emit(id, item->getId());
    case VcpOptionMenu::VCP_OPTION_MENU_EVENT_MENU_CANCEL:
    case VcpOptionMenu::VCP_OPTION_MENU_EVENT_MENU_CLOSE:
        break;
    default:
        break;
    }
}

VfxBool VcpInlineCellRadioList::onPenInput(VfxPenEvent &event)
{
    VFX_LOG(VFX_INFO2, VCP_INLINEMENU_CELLRADIO_PEN_EVENT, event.type);
    switch(event.type)
    {
    case VFX_PEN_EVENT_TYPE_UP:
        if(m_bkg.getResId() == VCP_INL_IMG_CELL_BKG_PRESSED)
        {
            tapped.emit(id);
        }
        break;
    default:
        break;
    }		
    VcpInlineCellBase::onPenInput(event);
    return VFX_TRUE;    
}

/*****************************************************************************
* Class VcpInlineMenuLayout
*****************************************************************************/
VcpInlineMenuLayout::VcpInlineMenuLayout(VcpInlineMenu* menu) : 
m_pMenu(menu),
FocusedCellExpansion(0),
CellWidth(0),
GroupCellTopGap(5),
CellGroupBottomGap(0),		
GroupCellLeftGap(0),
CellGroupRightGap(0),
MenuGroupLeftGap(0),
MenuGroupTopGap(0),	
GroupMenuRightGap(0),
GroupMenuBottomGap(0),
GroupGroupVertGap(0),
CellCellVertGap(0)
{
}

void VcpInlineMenuLayout::updateContentSize()
{
    VfxS32 width  = m_pMenu->m_indexer->getCell(0, -1)->getBounds().size.width;
    VfxS32 height = 0;
    for(VfxS32 i=0; i< m_pMenu->m_groupcount; i++)
    {
        VcpInlineGroup *grp = (VcpInlineGroup*)m_pMenu->m_indexer->getCell(i, -1);
        height += grp->getBounds().size.height;
        height += GroupGroupVertGap;
    }
    height += GroupMenuBottomGap;
    m_pMenu->setContentSize(VfxSize(width, height));
}

VfxS32 VcpInlineMenuLayout::getGroupCount()
{
    return m_pMenu->m_groupcount;
}


VfxPoint VcpInlineMenuLayout::getGroupPos(VfxS32 g)
{
    if(m_pMenu->m_groupcount < g)
        return VfxPoint(-1,-1);
    if(0==g)
        return VfxPoint(MenuGroupLeftGap, MenuGroupTopGap);

    VfxFrame *prev = (VfxFrame *)m_pMenu->m_indexer->getCell(g-1, -1);

    VfxRect rect = prev->getBounds();
    return VfxPoint(MenuGroupLeftGap, prev->getPos().y + rect.size.height + GroupGroupVertGap);		
}

VfxRect VcpInlineMenuLayout::getDefaultGroupBounds()
{
    return VfxRect(0,0, m_pMenu->getBounds().size.width - 2*(MenuGroupLeftGap),0);
}

VfxPoint VcpInlineMenuLayout::getCellPos(VfxS32 g, VfxS32 p)
{
    ASSERT((MAX_CELLS > g) && (g > -1));
    ASSERT((MAX_CELLS > p) && (p >= -1));

    if(-1 == p)
    {
        return getGroupPos(g);
    }
    if(0==p)
    {
        VfxS32 offset = 0;
        if(g)
            offset += GroupCellTopGap;
        if(m_pMenu->groupHasHeader(g))
            offset += 50;
        return VfxPoint( GroupCellLeftGap, offset);
    }
    VfxFrame *prev = (VfxFrame *)m_pMenu->m_indexer->getCell(g, p-1);
    VfxRect rect = prev->getBounds();
    VfxPoint prevOrigin = prev->getPos();
    if(rect.size.height)
    {
        return VfxPoint(prevOrigin.x, prevOrigin.y + rect.size.height + CellCellVertGap);		
    }
    else
    {
        return VfxPoint(prevOrigin.x, prevOrigin.y); // If previous cell height is 0, do not add any gap.
    }

}

VfxRect VcpInlineMenuLayout::getDefaultCellBounds()
{
    return VfxRect(0,0, 150,50);
}


VfxS32 VcpInlineMenuLayout::getCellCount(
    VfxS32 group    // [IN] The group index
    ) 					// Should be maintained internally by VcpInlineMenu 
{
    return m_pMenu->m_cellCountInGroup[group];
}

VfxS32 VcpInlineMenuLayout::getContentLength() // Should be maintained internally by VcpInlineMenu    
{
    return 0;
}


void VcpInlineMenuLayout::adjustCell(VcpInlineCellBase *aCell, VcpInlineGroup *grp)
{

    aCell->setPos(getCellPos(aCell->pos.group,aCell->pos.pos));
    VfxRect Grp_bounds = grp->getBounds();	
    grp->setBounds(Grp_bounds.origin.x, 
        Grp_bounds.origin.y, 
        Grp_bounds.size.width, 
        Grp_bounds.size.height - aCell->getBounds().size.height);
    if(aCell->m_visibility ==  VFX_TRUE) //Cell is visible
    {
        aCell->setCellBounds(0,0, grp->getBounds().size.width - GroupCellLeftGap - CellGroupRightGap, aCell->Cellheight);
    }
    else
    {
        aCell->setCellBounds(0,0, grp->getBounds().size.width - GroupCellLeftGap - CellGroupRightGap, 0);
    }
    if(aCell->m_cover)
    {
        aCell->m_cover->setBounds(aCell->getBounds());
    }

    aCell->m_currentFrameSize = aCell->getBounds().size;
    Grp_bounds = grp->getBounds();	
    grp->setBounds(Grp_bounds.origin.x, 
        Grp_bounds.origin.y, 
        Grp_bounds.size.width, 
        Grp_bounds.size.height + aCell->getBounds().size.height);

    grp->m_currentFrameSize = grp->getBounds().size;
}


/*****************************************************************************
* Class VcpInlineMenuDefaultContentProvider
*****************************************************************************/

VcpInlineMenuDefaultContentProvider::VcpInlineMenuDefaultContentProvider():
m_parentMenu(NULL),
m_cellcount(0)
{}

VcpInlineMenuDefaultContentProvider::VcpInlineMenuDefaultContentProvider(VcpInlineMenu *parent_menu):
m_parentMenu(parent_menu),
m_cellcount(0)
{}

void VcpInlineMenuDefaultContentProvider::setClientMenu(VcpInlineMenu *menu)
{
    m_parentMenu = menu;
}

void VcpInlineMenuDefaultContentProvider::PopulateMenu()
{
    VfxS32 group_itr = 0;
    VfxS32 pos_itr = 0;
    for( VfxU32 i=0; i < m_cellcount ; i++)
    {
        if(NULL == m_cellLookupTable[i].cellData)
        {
            group_itr++;
            pos_itr = 0;
        }
        else
        {
            switch(m_cellLookupTable[i].celltype)
            {	
            case VCP_INL_CELLTYPE_BUTTON:
                CREATE_CELL_FROM_DATA(m_parentMenu, (VcpInlineCellButtonData*)m_cellLookupTable[i].cellData, group_itr, pos_itr, m_cellLookupTable[i].cellid, m_cellLookupTable[i].celltype);
                break;
            case VCP_INL_CELLTYPE_SWITCH:
                CREATE_CELL_FROM_DATA(m_parentMenu, (VcpInlineCellSwitchData*)m_cellLookupTable[i].cellData, group_itr, pos_itr, m_cellLookupTable[i].cellid, m_cellLookupTable[i].celltype);
                break;
            case VCP_INL_CELLTYPE_RADIOLIST:
                CREATE_CELL_FROM_DATA(m_parentMenu, (VcpInlineCellRadioListData*)m_cellLookupTable[i].cellData, group_itr, pos_itr, m_cellLookupTable[i].cellid, m_cellLookupTable[i].celltype);
                break;
            default:
                break;
            }

            pos_itr++;
        }
    }
} 


