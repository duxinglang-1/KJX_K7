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
 *  vapp_theme_menu.cpp
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Theme AP
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h" 
#ifdef __MMI_THEMES_APPLICATION__
#include "MMIDataType.h"

#include "mmi_rp_srv_venus_component_list_menu_def.h"
#include "mmi_rp_app_cosmos_global_def.h"
#include "mmi_rp_vapp_theme_def.h"

#include "vfx_xml_loader.h"
#include "vcp_list_menu.h"
#include "vcp_async_image_frame.h"
#include "vapp_theme_menu.h"

#ifdef __MTK_TARGET__
//#define __MAUI_SOFTWARE_LA__
#endif

extern "C"
{
#include "FileMgrSrvGprot.h"
#ifdef __MAUI_SOFTWARE_LA__
#include "SST_sla.h"
#endif

#include "app_mem.h"
}

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_THEME_CELL_BG_COLOR VfxColor(255, 130, 130, 130)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
/***************************************************************************** 
 *	VappThemeViewCell implementataion
 *****************************************************************************/
VappThemeViewCell::VappThemeViewCell() 
	: m_icon(NULL),
	  m_iconOuter(NULL),
	  m_text(NULL),
	  m_pos(-1, -1)
{
}

	
VappThemeViewCell::VappThemeViewCell(VcpMenuPos pos) 
	: m_icon(NULL),
	  m_iconOuter(NULL),
	  m_text(NULL),
	  m_pos(pos)
{
}


void VappThemeViewCell::onInit()
{
	VfxControl::onInit();
	
	setSize(VappThemeViewCell::WIDTH, VappThemeViewCell::HEIGHT);	
	onCreate();
	
	setBgColor(VFX_COLOR_RES(CLR_COSMOS_BG_MAIN));
}

void VappThemeViewCell::onDeinit()
{
	VappThemeMatrixMenu *menu = VFX_STATIC_CAST(getParentFrame()->getParentFrame(), VappThemeMatrixMenu *);

	IVappThemeMatrixMenuContentProvider *provider = menu->getContentProvider();
	VfxImageSrc src = m_icon->getImgContent();
	provider->freeItemImage(m_pos, src);
	
	VfxControl::onDeinit();
}

VfxPoint VappThemeViewCell::getSelPos(void) const
{
	return VfxPoint((OUTER_WIDTH - 1), OUTER_HEIGHT);
}

void VappThemeViewCell::setContent(const VfxImageSrc &imgSrc, const VfxWString &text)
{
	m_icon->setImgContent(imgSrc);
	m_text->setString(text);

	onLayout();
}

void VappThemeViewCell::setImage(const VfxImageSrc &imgSrc)
{
	m_icon->setImgContent(imgSrc);
}

VfxImageSrc VappThemeViewCell::getImgSrc(void)
{
	return m_icon->getImgContent();
}

void VappThemeViewCell::onCreate(void)
{
#if 1
	VFX_OBJ_CREATE(m_iconOuter, VfxImageFrame, this);
	m_iconOuter->setResId(IMG_ID_VAPP_THEME_SMALL_BG);
	m_iconOuter->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);

	VFX_OBJ_CREATE(m_cover, VfxFrame, this);
	m_cover->setBgColor(VAPP_THEME_CELL_BG_COLOR);
	m_cover->setAnchor(0.5F, 0.5F);
	
	m_icon = createImage();
	m_icon->setAnchor(0.5F, 0.5F);
	
	VFX_OBJ_CREATE(m_text, VfxTextFrame, this);
	m_text->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
	m_text->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(TXT_SIZE), VFX_FE1_9));
	m_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
	m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
	m_text->setAnchor(1.0F, 1.0F);

#elif
	if (VfxXmlLoader::loadBegin(this, VAPP_THEME_MENU_CELL_LAYOUT))
	{
		m_iconOuter = VFX_OBJ_DYNAMIC_CAST(
			VfxXmlLoader::findObjByName(VFX_WSTR("iconOuter")),
			VfxImageFrame);

		m_cover = VFX_OBJ_DYNAMIC_CAST(
			VfxXmlLoader::findObjByName(VFX_WSTR("cover")),
			VfxFrame);
		m_cover->setBgColor(VAPP_THEME_CELL_BG_COLOR);

		m_icon = VFX_OBJ_DYNAMIC_CAST(
			VfxXmlLoader::findObjByName(VFX_WSTR("icon")),
			VfxImageFrame);

		m_text = VFX_OBJ_DYNAMIC_CAST(
			VfxXmlLoader::findObjByName(VFX_WSTR("name")),
			VfxTextFrame);

		m_text->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_MAIN));
		m_text->setFont(VfxFontDesc(TXT_SIZE, VFX_FE1_9));
		m_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
		m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
		
		VfxXmlLoader::loadEnd();
	}
#endif

}


VfxFrame * VappThemeViewCell::createImage(void)
{
	VfxImageFrame *imageFrame;
	VFX_OBJ_CREATE(imageFrame, VfxImageFrame, this);
	
	return imageFrame;
}

void VappThemeViewCell::onLayout(void)
{
#if 1
	m_iconOuter->setSize(OUTER_WIDTH, OUTER_HEIGHT);

	m_cover->setSize(IMG_WIDTH, IMG_HEIGHT);
	VfxS32 covHeight = (OUTER_HEIGHT - (SHADOW_TOP + SHADOW_BOTTOM)) / 2;
	m_cover->setPos((OUTER_WIDTH / 2), (SHADOW_TOP + covHeight));
	
	m_icon->setPos(m_cover->getPos());
	
	//m_text->setPos(0, (m_iconOuter->getSize().height + GAP));
	m_text->setPos(getSize().width, getSize().height);
	m_text->setSize(getSize().width, m_text->getMeasureBounds().getHeight());
#endif
}

void VappThemeViewCell::setHighlight(VfxBool isHighlight, VfxBool isAnim)
{
    if (m_isHighlight == isHighlight)
    {
    	return;
    }
	
    m_isHighlight = isHighlight;

    //VfxAutoAnimate::begin();
    //VfxAutoAnimate::setDisable(!isAnim);

	//
	// The same highlight mode with main menu.
	//
	if (isHighlight)
    {
		setOpacity(0.5F);
    }
    else
    {
		setOpacity(1.0F);
    }            
   
    //VfxAutoAnimate::commit();
}


#ifdef __MMI_THEME_SUPPORT_ASYNC_IMAGE__
/***************************************************************************** 
 * Class VappThemeViewAsyncCell
 *****************************************************************************/
void VappThemeViewAsyncCell::onDeinit()
{
	//
	// Obviously free membuffer.
	//
	VfxImageSrc imgSrc = m_icon->getImgContent();
	if (imgSrc.getType() != VFX_IMAGE_SRC_TYPE_MEM)
	{
		VappThemeMatrixMenu *menu = VFX_STATIC_CAST(getParentFrame()->getParentFrame(), VappThemeMatrixMenu *);		
		IVappThemeMatrixMenuContentProvider *provider = menu->getContentProvider();

		provider->freeItemImage(m_pos, m_imageSrc);
	}
	
	VappThemeViewCell::onDeinit();
}

VfxFrame *VappThemeViewAsyncCell::createImage(void)

{
	VcpAsyncImageFrame *asyncFrm;

    VFX_OBJ_CREATE_EX(
		asyncFrm,
		VcpAsyncImageFrame, 
		this, 
		(m_imageSrc, 
		 m_previewImageId, 
		 m_imageSrc.getSize(), 
		 2, 
		 VappThemeViewAsyncCell::allocMem, 
		 VappThemeViewAsyncCell::freeMem, 
		 m_provider));
	
	return asyncFrm;
}

void VappThemeViewAsyncCell::setContent(const VfxImageSrc &imgSrc, const VfxWString &text)
{
	m_text->setString(text);
	onLayout();
}

void VappThemeViewAsyncCell::setImage(const VfxImageSrc &imgSrc)
{
	// Do nothing.
}


void *VappThemeViewAsyncCell::allocMem(VfxU32 size, void *userData)
{
	IVappThemeMatrixMenuContentProvider *provider = (IVappThemeMatrixMenuContentProvider *)userData;
	return provider->allocNcMem(size, NULL);
}


void VappThemeViewAsyncCell::freeMem(void *mem, void *userData)
{
	IVappThemeMatrixMenuContentProvider *provider = (IVappThemeMatrixMenuContentProvider *)userData;

	provider->freeNcMem(mem, NULL);
}
#endif // __MMI_THEME_SUPPORT_ASYNC_IMAGE__

/***************************************************************************** 
 * VappThemeMatrixMenuHeader Implement
 *****************************************************************************/
void VappThemeMatrixMenuHeader::onInit()
{
    VfxControl::onInit();

    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);

    m_textFrame->setFont(VfxFontDesc(VCP_LIST_MENU_FONT_SIZE_SMALL, VFX_FE1_9));
    m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textFrame->setAnchor(0.0f, 0.5f);
 	m_textFrame->setColor(VFX_COLOR_RES(VCP_COL_LIST_MENU_HEADER_TEXT));


    update();

    m_signalBoundsChanged.connect(this, &VappThemeMatrixMenuHeader::onBoundsValueChanged);

    setImgContent(VfxImageSrc(VCP_IMG_LIST_MENU_GROUP_HEADER_BG));
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setAutoAnimate(VFX_TRUE);
}


void VappThemeMatrixMenuHeader::onBoundsValueChanged(VfxFrame *source, const VfxRect &oldBounds)
{
    m_textFrame->setPos(GAP, getSize().height / 2);
    m_textFrame->setSize(getSize().width - GAP * 2, getSize().height);
}


VappThemeMatrixMenu* VappThemeMatrixMenuHeader::getMenu()
{
    if (getParentFrame() && getParentFrame()->getParentFrame())
    {
        return VFX_STATIC_CAST(getParentFrame()->getParentFrame(), VappThemeMatrixMenu*);
    }
    
    return NULL;
}

IVappThemeMatrixMenuContentProvider* VappThemeMatrixMenuHeader::getContentProvider()
{
    VappThemeMatrixMenu *menu = getMenu();

    if (menu)
    {
        return menu->getContentProvider();
    }

    return NULL;
}

void VappThemeMatrixMenuHeader::onUpdate()
{
    update();
}

void VappThemeMatrixMenuHeader::update()
{
    IVappThemeMatrixMenuContentProvider* contentProvider = getContentProvider();

    if (contentProvider)
    {
        VfxWString headerText;

        if (contentProvider->getItemText(VcpMenuPos(m_group, -1), headerText))
        {
            m_textFrame->setString(headerText);
            m_textFrame->forceUpdate();
        }
    }
}


/***************************************************************************** 
 * VappThemeMatrixMenu Implement
 *****************************************************************************/
void VappThemeMatrixMenu::setContentProvider(IVappThemeMatrixMenuContentProvider *content)
{
	if (m_provider != content)
	{
		m_provider = content;

		VappThemeMatrixLayout *layout = (VappThemeMatrixLayout *)getLayout();
		layout->setProvider(content);
		
		updateLayout();
	}
}

void VappThemeMatrixMenu::setItemHeight(const VfxS32 &height)
{
	VappThemeMatrixLayout *layout = (VappThemeMatrixLayout *)getLayout();
	layout->setCellHeight(height);
}

void VappThemeMatrixMenu::updateCachedImage(void)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());

    VcpMenuPos p;

	VappThemeViewCell *cell;
    while(!itr.isEnd())
    {
        p = itr.next();
        if(p.isGroupHeader())
        {
            continue;
        }
		
        cell = (VappThemeViewCell *)getCellIfPresent(p.group, p.pos);
		if (cell != NULL)
		{
			VfxImageSrc src;
			m_provider->getItemImage(p, src);
        	cell->setImage(src);
		}
    }
}


void VappThemeMatrixMenu::releaseCachedImage(void)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());

    VcpMenuPos p;

	VappThemeViewCell *cell;
    while(!itr.isEnd())
    {
        p = itr.next();
        if(p.isGroupHeader())
        {
            continue;
        }
		
        cell = (VappThemeViewCell *)getCellIfPresent(p.group, p.pos);
		if (cell != NULL)
		{
			VfxImageSrc src = cell->getImgSrc();
        	cell->setImage(VfxImageSrc(IMG_ID_VAPP_THEME_DEFAULT));
			m_provider->freeItemImage(p, src);
		}
    }
}

void VappThemeMatrixMenu::onInit(void)
{
	VcpBaseMenu::onInit();

	VFX_OBJ_CREATE(m_selectIcon, VfxImageFrame, this);
	m_selectIcon->setResId(IMG_ID_VAPP_THEME_SELECT_ICON);
	m_selectIcon->setAnchor(0.75F, 0.75F);

	m_signalBoundsChanged.connect(this, &VappThemeMatrixMenu::onBoundsChanged);
}

void VappThemeMatrixMenu::onUpdate()
{
	VcpBaseMenu::onUpdate();


	//
	// Below codesegment is from VcpBaseListMenu
	//
	if (m_layout->getGroupCount() == 0 ||
		(m_layout->getGroupCount() == 1 && !m_layout->hasGroupHeader(0) && m_layout->getCellCount(0) == 0))
	{
		VfxWString text;
		
		if (m_provider->getMenuEmptyText(text))
		{
			if (m_emptyText == NULL)
			{
				VFX_OBJ_CREATE(m_emptyText, VfxTextFrame, this);
				addChildFrame(m_emptyText);
			}

			m_emptyText->setString(text);
			m_emptyText->setLineMode(VfxTextFrame::LINE_MODE_MULTI);
			m_emptyText->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
			m_emptyText->setAutoResized(VFX_TRUE);

			VfxAutoAnimate::begin();
			VfxAutoAnimate::setDisable(VFX_TRUE);
			m_emptyText->setSize((VfxS32)(getSize().width * VCP_LIST_MENU_EMPTY_TEXT_WITH_RATIO), 0);
			m_emptyText->forceUpdate();
			VfxAutoAnimate::commit();

#if defined(__MMI_VUI_COSMOS_CP__)
			m_emptyText->setColor(VFX_COLOR_RES(CLR_COSMOS_TEXT_EMPTY));
			m_emptyText->setFont(VFX_FONT_RES(FNT_COSMOS_TEXT_EMPTY));
#else /* defined(__MMI_VUI_COSMOS_CP__) */
			m_emptyText->setColor(VFX_COLOR_GREY);
#endif /* defined(__MMI_VUI_COSMOS_CP__) */
			m_emptyText->setAnchor(0.5, 0.5);

			updateEmptyText();

			m_emptyText->setAutoAnimate(VFX_TRUE);
		}
	}
	else if (m_emptyText)
	{
		VFX_OBJ_CLOSE(m_emptyText);
		m_emptyText = NULL;
	}

}

void VappThemeMatrixMenu::updateEmptyText(void)
{
	if (m_emptyText != NULL)
	{
    	m_emptyText->setPos(getSize().width / 2, getSize().height / 2);
	}
}


VcpBaseMenuLayout* VappThemeMatrixMenu::createLayout()
{
    VappThemeMatrixLayout *layout;

    VFX_OBJ_CREATE_EX(layout, VappThemeMatrixLayout, this, (this));
    
	VfxImageSrc headerImgSrc(VCP_IMG_LIST_MENU_GROUP_HEADER_BG);
	layout->setHeaderHeight(headerImgSrc.getSize().height);
   
    return layout;
}

VfxFrame* VappThemeMatrixMenu::createCell(VfxS32 group, VfxS32 pos)
{
#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("tcc", SA_start);
#endif

	VfxWString text;
	m_provider->getItemText(VcpMenuPos(group, pos), text);

	VfxImageSrc imgSrc;
	m_provider->getItemImage(VcpMenuPos(group, pos), imgSrc);
	
	VappThemeViewCell *cell;
#ifdef __MMI_THEME_SUPPORT_ASYNC_IMAGE__
	if (m_provider->isAsyncImage(VcpMenuPos(group, pos)))
	{
		VappThemeViewAsyncCell *asyncCell;
		VFX_OBJ_CREATE_EX(asyncCell, 
						  VappThemeViewAsyncCell, 
						  this, 
						  (imgSrc, IMG_ID_VAPP_THEME_DEFAULT, m_provider, VcpMenuPos(group, pos)));
		cell = asyncCell;
	}
	else
#endif // __MMI_THEME_SUPPORT_ASYNC_IMAGE__
	{
		VFX_OBJ_CREATE_EX(cell, VappThemeViewCell, this, (VcpMenuPos(group, pos)));
		cell->setCacheMode(VFX_CACHE_MODE_FREEZE);
	}

	cell->setContent(imgSrc, text);

#ifdef __MAUI_SOFTWARE_LA__
	SLA_CustomLogging("tcc", SA_stop);
#endif

	m_counter++;
	return (VfxFrame *)cell;
}

void VappThemeMatrixMenu::onAfterCreateLayout()
{
	VappThemeMatrixLayout *layout = (VappThemeMatrixLayout *)getLayout();
	
	VfxRect rect;
	
	rect.size = ((VfxFrame*)getParent())->getSize();	
	
	makeVisible(rect, VFX_TRUE);
}

void VappThemeMatrixMenu::onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
{
	if (cellFrame->getRect().contains(m_selectIcon->getPos()))
	{
		m_selectIcon->setHidden(VFX_TRUE);
		m_selectIcon->setPos(VFX_POINT_ZERO);
	}

	VFX_OBJ_CLOSE(cellFrame);
	m_counter--;
}

void VappThemeMatrixMenu::onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
{
	cell->setRect(rect);

	VappThemeViewCell *themeCell = (VappThemeViewCell *)cell;
	themeCell->getSelPos();

	if (m_selectIcon->getPos().isZero() &&
		(m_provider->getItemState(VcpMenuPos(group, pos)) == VAPP_THEMEE_MENU_ITEM_STATE_SELECTED))
	{
		VfxPoint pt = rect.origin;
		pt.x += themeCell->getSelPos().x;
		pt.y += themeCell->getSelPos().y;
		
		m_selectIcon->setHidden(VFX_FALSE);
		m_selectIcon->setPos(pt);
		m_selectIcon->bringToFront();
	}
	else
	{
		if (rect.contains(m_selectIcon->getPos()))
		{
			m_selectIcon->setHidden(VFX_FALSE);
			m_selectIcon->bringToFront();
		}
	}
}

void VappThemeMatrixMenu::onTouchCell(VcpMenuPos cellPos, CellTouchTypeEnum	touchType, VfxPoint	pt, VfxFrame *cell)
{
	MMI_TRACE(TRACE_GROUP_3, VAPP_THEME_MENU_ON_TOUCH, cellPos.group, cellPos.pos, touchType);
	
    // do nothing for group header
    if (cellPos.pos == -1)
    {
        return;
    }

	switch(touchType)
    {
	    case TouchDown:
	        getLayout()->setFocusItem(cellPos);
	        break;

	    case TouchUp:
			if (!m_isNeedClear)
			{
	        getLayout()->clearFocusItem();
			}
	        break;

	    case TouchTap:
		{
		//	VappThemeViewCell *viewCell = (VappThemeViewCell *)cell;
	        m_signalTap.postEmit(this, cellPos);
			m_isNeedClear = VFX_TRUE;
	        break;
	    }
		
	    default:
	        break;
    };

}

void VappThemeMatrixMenu::onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
{
	VappThemeViewCell* cell;
	
    if (previousFocusItem.isValid() && !previousFocusItem.isGroupHeader())
    {
        cell = (VappThemeViewCell *)getCellIfPresent(previousFocusItem.group, previousFocusItem.pos);
        
        if (cell != NULL)
        {
            cell->setHighlight(VFX_FALSE, VFX_FALSE);
			m_isNeedClear = VFX_FALSE;
        }
    }
    
    if (focusItem.isValid() && !focusItem.isGroupHeader())
    {
        cell = (VappThemeViewCell*) getCellIfPresent(focusItem.group, focusItem.pos);
        
        if (cell != NULL)
        {
            cell->setHighlight(VFX_TRUE, VFX_FALSE);
        }
    }
}


VfxFrame* VappThemeMatrixMenu::createGroupHeader(VfxS32 group)
{
	VappThemeMatrixMenuHeader *header;

	VFX_OBJ_CREATE_EX(header, VappThemeMatrixMenuHeader, this, (group));

	return header;
}

void VappThemeMatrixMenu::onUpdateGroupHeader(const VfxRect &rect, VfxS32 group, VfxFrame* obj, VfxU32 flag)
{
    VappThemeMatrixMenuHeader *header = (VappThemeMatrixMenuHeader *)obj;
    header->setRect(rect);
	header->checkUpdate();
	
	VappThemeMatrixLayout *layout = (VappThemeMatrixLayout *)getLayout();
	layout->setHeaderHeight(header->getSize().height);
}

void VappThemeMatrixMenu::onCloseGroupHeader(VfxS32 group, VfxFrame* groupFrame)
{
	VFX_OBJ_CLOSE(groupFrame);
}


void VappThemeMatrixMenu::onBoundsChanged(VfxFrame *source, const VfxRect &oldBounds)
{
	updateEmptyText();
}


void VappThemeMatrixMenu::forceCache(void)
{
    VcpMenuRegionIter itr(this, getRealContentRegion());

    VcpMenuPos p;

	VappThemeViewCell *cell;
    while(!itr.isEnd())
    {
        p = itr.next();
        if(p.isGroupHeader())
        {
            continue;
        }
		
        cell = (VappThemeViewCell *)getCellIfPresent(p.group, p.pos);
		if (cell != NULL)
		{
            cell->preCache();
		}
    }
}

/***************************************************************************** 
 *  VappThemeMatrixLayout implementataion
 *****************************************************************************/
void VappThemeMatrixLayout::onInit()
{
	VcpBaseMenuLayout::onInit();

	m_columnCnt = COLUMN_COUNT;
	m_headerHeight = 20;
	m_cellHeight = VappThemeViewCell::HEIGHT;
	m_cellWidth = VappThemeViewCell::WIDTH;
}

VfxS32 VappThemeMatrixLayout::getContentLength()
{
	if (m_provider == NULL)
	{
		return 0;
	}
	
	VfxS32 len = 0;

	for (VfxS32 i = 0; i < m_provider->getGroupCount(); i++)
	{
		if (m_provider->hasGroupHeader(i))
		{
			len += m_headerHeight;
		}

		len  += getGroupCellTotalHeight(i);
	}

	return len;	
}

VfxRect VappThemeMatrixLayout::queryCellRect(VcpMenuPos pos)
{	
    VfxS32 x, y;

	x = (pos.pos % m_columnCnt) * (m_cellWidth + m_horiGap) + m_horiGap;
    y = (pos.pos / m_columnCnt) * (m_cellHeight + m_vertGap) + m_vertGap;

	y += m_goupCellStartPos[pos.group].y;
	
    return VfxRect(x, y, m_cellWidth, m_cellHeight);
}

VcpMenuRegion VappThemeMatrixLayout::queryRegion(const VfxRect& r)
{
    return VcpMenuRegion(
            queryPosByPt(r.origin),
            queryPosByPt(VfxPoint(r.getMaxX(), r.getMaxY())));
}

VfxBool VappThemeMatrixLayout::navDir(NavDirEnum dir)
{
    if (dir == NAV_DIR_LEFT|| dir == NAV_DIR_RIGHT)
    {
        return VFX_FALSE;
    }
	
	VcpMenuRegion visibleRegion = queryRegion(m_viewRect);

	VcpMenuPos pos = (dir == NAV_DIR_UP) ? (visibleRegion.begin) : (visibleRegion.end);
	VfxRect rect = (pos.pos == -1) ? (queryGroupHeaderRect(pos.group)) : (queryCellRect(pos));
	VfxRect targetRect = m_viewRect;

	if (dir == NAV_DIR_UP)
	{
		/* if the first item is not half-visible */
		if (m_viewRect.getMinY() <= rect.getMinY())
		{
			VcpMenuPos newPos = pos.getPrevPos(this, VFX_TRUE);
			rect = (newPos.pos == -1) ? (queryGroupHeaderRect(newPos.group)) : (queryCellRect(newPos));
		}
		
		targetRect.origin.y = rect.getMaxY() - m_viewRect.getHeight() + 1;
	}
	else /* (dir == NAV_DIR_DOWN) */
	{
		/* if the last item is not half-visible */
		if (m_viewRect.getMaxY() >= rect.getMaxY())
		{
			VcpMenuPos newPos = pos.getNextPos(this, VFX_TRUE);
			if (newPos.isValid())
			{
				rect = (newPos.pos == -1) ? (queryGroupHeaderRect(newPos.group)) : (queryCellRect(newPos));
			}
		}
		
		targetRect.origin.y = rect.getMinY();
	}

	m_pMenu->makeVisible(targetRect, VFX_TRUE);

	return VFX_TRUE;
}


VcpMenuPos VappThemeMatrixLayout::queryPosByPt(const VfxPoint& pt)
{
	if (m_provider == NULL)
	{
		return VcpMenuPos(-1, -1);
	}

	VcpMenuPos pos;
	VfxS32 col, row, height;

	pos.group = 0;
	VfxRect rect;
	
	for (VfxS32 i = 0; i < m_provider->getGroupCount(); i++)
	{
		if (m_provider->hasGroupHeader(i))
		{
			rect = queryGroupHeaderRect(i);

			if (pt.y >= rect.getY())
			{
				if (pt.y <= rect.getMaxY())
				{
					pos.setGroupHeader(i);
					
					return pos; 
				}
				pos.group = i;
			}
		}
	}

	height = pt.y - rect.getMaxY();
	
	row = height / (m_cellHeight + m_vertGap);
	//row = (row >= 1) ? (row - 1) : 0; 
	if (row < 0)
	{
		row = 0;
	}
	
	col = pt.x / (m_cellWidth + m_horiGap);
	col = (col >= 1) ? (col - 1) : 0; 
	
	pos.pos = row * m_columnCnt + col;

	if (pos.pos >= getCellCount(pos.group))
	{
		pos.pos = getCellCount(pos.group) - 1;
	}
	
	return pos;

}


VfxS32 VappThemeMatrixLayout::getGroupCellTotalHeight(const VfxS32 &group)
{
	VfxS32 row, remain, lastGap;
	
	if (m_provider->getCount(group) == 0)
	{
		row = lastGap = 0;
	}
	else
	{
		remain = m_provider->getCount(group) % m_columnCnt;
		row = m_provider->getCount(group) / m_columnCnt;
	
		if (remain != 0)
		{
			row += 1;
		}
		lastGap = m_vertGap;
	}
	
	return (row * (m_cellHeight + m_vertGap) + lastGap);
}

VfxRect VappThemeMatrixLayout::queryGroupHeaderRect(VfxS32 group)
{
    if (!m_provider->hasGroupHeader(group))
    {
        return VfxRect(0, 0, 0, 0);
    }

    VfxS32 y = 0, height = 0;
	
    for (VfxS32 i = 0; i <= group; i++)
    {
        if (m_provider->hasGroupHeader(i))
        {
            y += m_headerHeight;
        }

        if (i < group)
        {			
        	y  += getGroupCellTotalHeight(i);
        }
        else if (m_provider->hasGroupHeader(i))
        {
            y -= m_headerHeight;
            height = m_headerHeight;
            break;
        }
    }

	m_goupCellStartPos[group].x = 0;
	m_goupCellStartPos[group].y = y + height;
	
    return VfxRect(0, y, getViewSize().width, height);
}


void VappThemeMatrixLayout::onViewChanged()
{
	VfxFloat fGap = (VfxFloat)(getViewSize().width - (m_cellWidth * m_columnCnt));
	fGap = fGap / ((VfxFloat)(m_columnCnt + 1));
	m_horiGap =  (VfxS32)vfx_sys_ceil(fGap);
	m_vertGap = VERT_GAP;
}

#endif /*__MMI_THEMES_APPLICATION__*/
