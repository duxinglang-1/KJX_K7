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
 *  vapp_setting_framework_cell_list.cpp
 *
 * Project:
 * --------
 *  Venus
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
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
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_setting_framework_cell_list.h"
#include "vapp_setting_config.h"
#include "vapp_setting_framework_gprot.h"
#include "vapp_setting_framework_caption_gprot.h"
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
/***************************************************************************** 
 * VappSettingFWBaseCell
 *****************************************************************************/
#pragma arm section code = "DYNAMIC_CODE_SETTING_ROCODE", rodata = "DYNAMIC_CODE_SETTING_RODATA"  
VFX_IMPLEMENT_CLASS("VappSettingFWBaseCell", VappSettingFWBaseCell, VcpFormItemLauncherCell);
void VappSettingFWBaseCell::updateCell()
{
    if (m_titleStringId)
	{
	    setMainText(m_titleStringId);
	}
    if (m_hintStringId)
	{
	    setHintText(m_hintStringId);
	}    
    m_signalTap.connect(this, &VappSettingFWBaseCell::onTap);
}

/***************************************************************************** 
 * VappSettingFWPublicCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingFWPublicCell", VappSettingFWPublicCell, VappSettingFWBaseCell);
void VappSettingFWPublicCell::onTap(VcpFormItemCell* sender, VfxId senderId)
{
    if (m_launchHdlr)
	{
        VfxMainScr *mainScr = VFX_OBJ_DYNAMIC_CAST(findScreen(), VfxMainScr);
        if (mainScr)
    	{
    	    (*m_launchHdlr)(mainScr);
    	}	    
	}
    else
    {
        m_signalEntryMenu.emit(m_menuId);
    }
}

/***************************************************************************** 
 * VappSettingFWIconCell
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingFWIconCell", VappSettingFWIconCell, VappSettingFWPublicCell);
void VappSettingFWIconCell::onInit()
{
    VappSettingFWPublicCell::onInit();
    VFX_OBJ_CREATE(m_imageFrame, VfxImageFrame, this);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    m_imageFrame->setAnchor(0, 0.5);
    m_imageFrame->setSize(IMG_MAX_WIDTH, IMG_MAX_HEIGHT);
    m_imageFrame->setPos(IMG_LEFT_GAPS, getBounds().getHeight() / 2);

    m_imageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);

    m_mainText->setRect(VfxRect(TEXT_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH, 
                                 m_mainText->getPos().y,
                                 getRect().getWidth() - TEXT_LEFT_GAPS - TEXT_RIGHT_GAPS - (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH) - (ACCESSORY_WIDTH + ACCESSORY_RIGHT_GAPS),
                                 m_mainText->getRect().getHeight()));
}

void VappSettingFWIconCell::onUpdate()
{
    VappSettingFWPublicCell::onUpdate();
    
    if (m_mainText)
    {
        m_mainText->setPos(TEXT_LEFT_GAPS + IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH, m_mainText->getPos().y);	
	m_mainText->setSize(getRect().getWidth() - TEXT_LEFT_GAPS - TEXT_RIGHT_GAPS - (IMG_LEFT_GAPS + IMG_RIGHT_GAPS + IMG_MAX_WIDTH) - (ACCESSORY_WIDTH + ACCESSORY_RIGHT_GAPS), m_mainText->getRect().getHeight());
    }
}

/***************************************************************************** 
 * VappSettingFWCellList
 *****************************************************************************/

VFX_IMPLEMENT_CLASS("VappSettingFWCellList", VappSettingFWCellList, VfxObject);

VcpFormItemBase* VappSettingFWCellList::getNext()
{
    if (m_currentCellContainer->nextContainer)
	{
	    m_currentCellContainer = m_currentCellContainer->nextContainer;
        return getCell();
	}
    else
    {
        return NULL;
    }    
}

void VappSettingFWCellList::addCell(VcpFormItemBase* cell)
{
    if (!cell)
	{
	    VFX_ASSERT(0);
	}
    if (m_currentCellContainer)
	{
	    VFX_ALLOC_MEM(m_currentCellContainer->nextContainer, sizeof(VappSettingFWItemContainer), this);
        m_currentCellContainer = m_currentCellContainer->nextContainer;
        m_currentCellContainer->cell = cell;
        m_currentCellContainer->nextContainer = NULL;
	}
    else
    {
        // currently no cell
        //m_currentCellContainer = new(VappSettingFWItemContainer);
        VFX_ALLOC_MEM(m_currentCellContainer, sizeof(VappSettingFWItemContainer), this);
        m_currentCellContainer->cell = cell;
        m_currentCellContainer->nextContainer = NULL;
        m_cellContainterHead = m_currentCellContainer;
    }
}

VappSettingFWCellList::~VappSettingFWCellList()
{
	// Search from the header
	reset();
	if (!m_currentCellContainer)
	{
	    return;
	}
    while(m_currentCellContainer->nextContainer)
    {
        VappSettingFWItemContainer *tempContainer = m_currentCellContainer;
        m_currentCellContainer = m_currentCellContainer->nextContainer;
        VFX_FREE_MEM(tempContainer);
    }   
    if (m_currentCellContainer)
    {
        VFX_FREE_MEM(m_currentCellContainer);
        m_currentCellContainer = NULL;
    }
}

/***************************************************************************** 
 * VappSettingFWCelllistCreator
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappSettingFWCelllistCreator", VappSettingFWCelllistCreator, VfxObject);
VappSettingFWCellList* VappSettingFWCelllistCreator::getMenuCellList(VfxId menuId, VfxPage *page)
{
    VappSettingFWCellList *cellList;
    VFX_OBJ_CREATE(cellList, VappSettingFWCellList, page);	       

    VappSettingConfigStruct* configStruct = getItemStruct(menuId);    
    if (!configStruct)
	{
	    return NULL;
	}
    
    while(configStruct)
    {
        VcpFormItemBase *formCell = createCell(configStruct, page);
        if (formCell)
    	{
            cellList->addCell(formCell);	
    	}
        configStruct = getItemStruct(menuId);
    }
    m_searchId = 0;
    return cellList;
}

VfxWString VappSettingFWCelllistCreator::getPublicMenuTitle(VfxId menuId)
{
    if (menuId == SETTING_MAIN_MENU)
	{
	    return VFX_WSTR_RES(STR_ID_SETTING_MAIN_MENU_TITLE);
	}
    VappSettingConfigStruct *menuStruct = getConfigStruct(menuId);
    if (menuStruct && menuStruct->titleStringId)
	{
	    return VFX_WSTR_RES(menuStruct->titleStringId);
	}
    return VFX_WSTR_NULL;
}

VfxBool VappSettingFWCelllistCreator::checkIsSubItem(VfxId menuId)
{
    if(getItemStruct(menuId))
    {
        m_searchId = 0;
        return VFX_TRUE;
    }   
    else
    {
        return VFX_FALSE;
    }        
}

VappSettingConfigStruct* VappSettingFWCelllistCreator::getConfigStruct(VfxId menuId)
{
    VappSettingConfigStruct *searchPtr = (VappSettingConfigStruct*)(&VappSettingMenuStruct[0]);
    while (searchPtr)
	{
	    if (searchPtr->menuId == menuId)
		{
		    return searchPtr;
		}
	    searchPtr++;
	}
    return NULL;
}

VappSettingConfigStruct* VappSettingFWCelllistCreator::getItemStruct(VfxId parentMenuId)
{
    if (parentMenuId != m_searchId)
	{
	    m_searchId = parentMenuId;
	    m_searchPointer = (VappSettingConfigStruct*)&VappSettingMenuStruct[0];
	}
    while(m_searchPointer->parentId != 0)
    {
        if (m_searchPointer->parentId == parentMenuId)
    	{
    	    return m_searchPointer++;
    	}
		m_searchPointer++;
    }
    return NULL;
}

VcpFormItemBase* VappSettingFWCelllistCreator::createCell(VappSettingConfigStruct* configStruct, VfxPage *page)
{
    if (configStruct->checkHdlr && (*configStruct->checkHdlr)() == VFX_FALSE)
	{
	    // Do not create hidden cell
	    return NULL;
	}
    // Config with form cell
    if ((configStruct->createCellHandler) && (configStruct->titleStringId))
	{
	    VappSettingFrameworkCaptionCell *captionCell;
	    VFX_OBJ_CREATE_EX(captionCell, VappSettingFrameworkCaptionCell, page, (configStruct->titleStringId));
        return (VcpFormItemBase*)captionCell;
	}

    if ((configStruct->createCellHandler) && (!configStruct->titleStringId))
    {
        return (VcpFormItemBase*)(configStruct->createCellHandler(page));
    }
 
    VappSettingFWBaseCell *launcherCell;
    if (configStruct->parentId == SETTING_MAIN_MENU)
	{
	    VFX_OBJ_CREATE(launcherCell, VappSettingFWIconCell, page);
        ((VappSettingFWIconCell*)launcherCell)->setIconResId(configStruct->iconId);
	}
    else
    {
	    VFX_OBJ_CREATE(launcherCell, VappSettingFWPublicCell, page);
    }
    
    if (configStruct->launcherSettingHandler)
	{
	    // an APP cell
        ((VappSettingFWPublicCell*)launcherCell)->m_launchHdlr = configStruct->launcherSettingHandler;
	}
    else
    {
        ((VappSettingFWPublicCell*)launcherCell)->m_menuId = configStruct->menuId;
    }
    launcherCell->m_titleStringId = configStruct->titleStringId;
    launcherCell->m_hintStringId = configStruct->hintStringId;

    launcherCell->setAccessory(VCPFORM_NEXT_ITEM_ICON);
    launcherCell->updateCell();
    return launcherCell;
}
#pragma arm section code, rodata


