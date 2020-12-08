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
 *  vapp_browser_home_page.cpp
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

#ifndef _VAPP_BRW_HOMEPAGE_CPP_
#define _VAPP_BRW_HOMEPAGE_CPP_

#include "MMI_features.h" 

#ifndef __MMI_BRW_SLIM__
#ifdef __MMI_BROWSER_2__

#include "vapp_brw_home_page.h"
#include "mmi_rp_vapp_browser_def.h"
#include "vapp_brw_main.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappBrwHomePage", VappBrwHomePage, VfxControl);

VappBrwHomePage::VappBrwHomePage() :
	m_currentIconItem(NULL)
{
    VfxS32 i;
    for (i = 0; i < TOTAL_HOME_PAGE_ITEMS; i++)
    {
        m_iconItems[i] = NULL;
    }
}

void VappBrwHomePage::updateItems(VfxU8 index)
{
    VfxBool lock;
    VfxImageSrc imgData; 
    VfxWString textData;
    m_callback.invoke(index, imgData, textData, lock);
    m_iconItems[index]->updateItem(imgData,textData,lock);
}

void VappBrwHomePage::updateItems(void)
{
    VfxU8 i;
    for (i = 0; i < TOTAL_HOME_PAGE_ITEMS; i++)
    {
        updateItems(i);
    }
}

void VappBrwHomePage::setHomePageElementsSize(VfxU16 iconWidth,VfxU16 iconHeight,VfxU16 lockIconWidth,VfxU16 lockIconHeight,VfxU16 iconTextHeight,VfxU16 iconTitleMargin, VfxU16 HorizontalpageMargin,VfxU16 IconTextFontSize, VfxU16 VerticalpageMargin,VfxU16 HorizontalExtraMargin,VfxU16 VerticalExtraMargin, VfxU16 LockTitleTextMargin)
{
    m_iconWidth = iconWidth;
    m_iconHeight = iconHeight;
    m_lockIconWidth = lockIconWidth;
    m_lockIconHeight = lockIconHeight;
    m_iconTextHeight = iconTextHeight;
    m_iconTitleMargin = iconTitleMargin;
    m_LockTitleTextMargin = LockTitleTextMargin;
    m_HorizontalpageMargin = HorizontalpageMargin;
	m_iconTextFontSize = IconTextFontSize;
	m_VerticalpageMargin = VerticalpageMargin;
	m_VerticalExtraMargin = VerticalExtraMargin;
	m_HorizontalExtraMargin = HorizontalExtraMargin;
}

void VappBrwHomePage::onDeinit(void)
{
    VfxControl::onDeinit();
}

void VappBrwHomePage::onUpdate(void)
{
    VfxControl::onUpdate();
}

void VappBrwHomePage::portraitPenDownEffect(VfxFrame *portraitBgFrame)
{
    m_currentIconItem->m_image->setOpacity(0.5f);
}

void VappBrwHomePage::portraitPenUpEffect(void)
{
    m_currentIconItem->m_image->setOpacity(1.0f);
}

void VappBrwHomePage::onClickPortrait(void)
{
    m_iconItemTap.emit(m_currentIconItem->getUniqueIconID());
}

void VappBrwHomePage::layoutItems()
{
    VfxS32 i, j, k = 0;
    VfxS32 x, y, width, height, widthNoMargin,hightNoMargin;
    VfxRect rect = getParentFrame()->getRect();
	VfxS32 gap_width = (rect.getWidth() - (2 * m_HorizontalExtraMargin) - (m_numColumns + 1) * m_HorizontalpageMargin) % m_numColumns;
	VfxS32 gap_height = (rect.getHeight() - (2 * m_VerticalExtraMargin) - (m_numRows + 1) * m_VerticalpageMargin) % m_numRows;
    widthNoMargin = (rect.getWidth() - (2 * m_HorizontalExtraMargin) - m_HorizontalpageMargin);
    hightNoMargin = (rect.getHeight() - (2 * m_VerticalExtraMargin) - m_VerticalpageMargin);
    width =  widthNoMargin / m_numColumns;
    height = hightNoMargin / m_numRows;
    x = ((widthNoMargin - width * m_numColumns) / 2) + m_HorizontalpageMargin + (gap_width / 2) + m_HorizontalExtraMargin;
    y = ((hightNoMargin - height * m_numRows) /2) + m_VerticalpageMargin + (gap_height / 2) + m_VerticalExtraMargin;
    for (i = 0; i < m_numRows; i++)
    {
        for(j = 0; j < m_numColumns; j++)
        {
          
			m_iconItems[k]->setMaxSize(VfxSize((width-m_HorizontalpageMargin), (height-m_VerticalpageMargin)));
            m_iconItems[k]->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
			m_iconItems[k]->setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
            m_iconItems[k]->setPos(VfxPoint(x /* + width / 2 */, y /*+ height / 2 *//* - HOME_PAGE_IMAGE_Y*/));
            x = x + width;
            k++;
            if (k >= TOTAL_HOME_PAGE_ITEMS)
            {
                break;
            }
        }
        x = ((widthNoMargin - width * m_numColumns) / 2) + m_HorizontalpageMargin + m_HorizontalExtraMargin;
        y = y + height;
    }
}

void VappBrwHomePage::onShortcutItemTap(VfxU8 index)
{
	m_iconItemTap.emit(index);
}

void VappBrwHomePage::onShortcutLongTap(VfxU8 index)
{
	 m_iconItemLongPress.emit(index);
}

void VappBrwHomePage::setRowsColumns(VfxS32 numRows, VfxS32 numColumns)
{
    VfxS32 i, count; 
    m_numRows = numRows;
    m_numColumns = numColumns;
    count = m_numRows * m_numColumns;
    if (count > TOTAL_HOME_PAGE_ITEMS)
    {
        count = TOTAL_HOME_PAGE_ITEMS;
    }
    // Create a image frame
    for (i = 0; i < count; i++)
    {
        if (m_iconItems[i] == NULL)
        {
            VfxBool lock;
            VfxImageSrc imgData; 
            VfxWString textData;
            m_callback.invoke(i,imgData,textData, lock);
            VFX_OBJ_CREATE_EX(m_iconItems[i], VappBrwHomePageIcon, this, (i,imgData,textData,lock));
			m_iconItems[i]->m_iconItemLongPress.connect(this, &VappBrwHomePage::onShortcutLongTap);
            m_iconItems[i]->m_iconItemTap.connect(this, &VappBrwHomePage::onShortcutItemTap);
            //m_iconItems[i]->setAnchor(VfxFPoint(0.5F, 0.5F));
        }
        m_iconItems[i]->setHomePageIconElemntsSize(m_iconWidth,m_iconHeight,m_lockIconWidth,m_lockIconHeight,m_iconTextHeight,m_iconTitleMargin,m_iconTextFontSize,m_LockTitleTextMargin);
    }
    layoutItems();
}


VFX_IMPLEMENT_CLASS("VappBrwHomePageIcon", VappBrwHomePageIcon, VcpPhotoBorderFrame);

void VappBrwHomePageIcon::onInit()
{    
    VcpPhotoBorderFrame::onInit();

	setPlacement(VCP_PHOTO_BORDER_FRAME_PLACEMENT_FIT_EXACT_SIZE);
	setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    VFX_OBJ_CREATE(m_iconDataFrame, VfxFrame, this);
	setImageFrame(m_iconDataFrame);
    m_iconDataFrame->setAnchor(VfxFPoint(0.5F, 0.5F));
    VFX_OBJ_CREATE(m_image, VfxFrame, m_iconDataFrame);
	m_image->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    m_image->setAnchor(VfxFPoint(0.5F, 0.5F));
    if(!m_textData.isEmpty())
    {
        VFX_OBJ_CREATE(m_textImage, VfxImageFrame, m_iconDataFrame);
        VFX_OBJ_CREATE(m_text, VfxTextFrame, m_iconDataFrame);
        if(m_lock)
        {
            VFX_OBJ_CREATE(m_lockImage, VfxImageFrame, m_iconDataFrame);
            m_lockImage->setImgContent(VfxImageSrc(IMG_ID_VAPP_BRW_LOCK));
			m_lockImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        }

		m_text->setAutoResized(VFX_FALSE); 
        m_text->setVerticalToCenter(VFX_TRUE);
        m_textImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        m_textImage->setImgContent(VfxImageSrc(IMG_ID_VAPP_BRW_WEBSITE_BG));
        m_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    }
    m_signalBoundsChanged.connect(this, &VappBrwHomePageIcon::onBoundsValueChange);
    m_signalClicked.connect(this, &VappBrwHomePageIcon::onItemClicked);
    m_signalLongPress.connect(this, &VappBrwHomePageIcon::onItemLongTapped);
    VfxRect rect = getBounds();
}

void VappBrwHomePageIcon::onItemClicked(void)
{
    m_iconItemTap.emit(getUniqueIconID());
}

void VappBrwHomePageIcon::onItemLongTapped(void)
{
    m_iconItemLongPress.emit(getUniqueIconID()); 
}

void VappBrwHomePageIcon::onBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds)
{
    VFX_UNUSED(source);
    VFX_UNUSED(oldBounds);
    VfxRect rect = getBounds();
    m_iconDataFrame->setPos(VfxPoint(rect.size.width / 2, rect.size.height / 2));
    m_iconDataFrame->setSize(m_iconWidth, (m_iconHeight + m_iconTextHeight));
    rect = m_iconDataFrame->getBounds();
    m_image->setPos(VfxPoint(rect.size.width / 2, (rect.size.height - m_iconTextHeight) / 2));
    m_image->setSize(m_iconWidth, m_iconHeight);
    if(m_text)
    {
        m_image->setPos(VfxPoint(rect.size.width / 2, (rect.size.height - m_iconTextHeight) / 2));
		m_text->setPos(VfxPoint(m_image->getRect().getX(), (m_image->getRect().getHeight())));
        m_textImage->setPos(VfxPoint(m_image->getRect().getX(), (m_image->getRect().getHeight())));
        m_text->setSize(m_iconWidth, m_iconTextHeight);
        m_textImage->setSize(m_iconWidth , m_iconTextHeight);
        m_image->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
        if (m_lockImage)
        {
            m_lockImage->setPos(VfxPoint((m_iconDataFrame->getBounds().getX()+m_iconTitleMargin), (m_iconDataFrame->getBounds().getY() + m_iconHeight + ((m_iconTextHeight -m_lockIconHeight)/2))));
            m_lockImage->setSize(m_lockIconWidth, m_lockIconHeight);
        }
    }
    else
    {
        m_image->setPos(VfxPoint(rect.size.width / 2, (rect.size.height)/ 2));
		m_image->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    }
    setIconData();
	checkUpdate();
}

void VappBrwHomePage::enableTap(VfxBool enable)
{
    checkUpdate();
}

void VappBrwHomePage::onInit(void)
{
    VfxControl::onInit();
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setImgContent(VfxImageSrc(IMG_COSMOS_GRID_BG));
}

void VappBrwHomePageIcon::setHomePageIconElemntsSize(VfxU16 iconWidth,VfxU16 iconHeight,	VfxU16 lockIconWidth,VfxU16 lockIconHeight,VfxU16 iconTextHeight,VfxU16 iconTitleMargin,VfxU16 IconTextFontSize,VfxU16 LockTitleTextMargin)
{
    m_iconWidth = iconWidth;
    m_iconHeight = iconHeight;
    m_lockIconWidth = lockIconWidth;
    m_lockIconHeight = lockIconHeight;
    m_iconTextHeight = iconTextHeight;
    m_iconTitleMargin = iconTitleMargin;
	m_iconTextFontSize = IconTextFontSize;
    m_LockTitleTextMargin = LockTitleTextMargin;
}

void VappBrwHomePageIcon::updateItem (VfxImageSrc &imgData,VfxWString textData, VfxBool lock)
{
    m_lock = lock;
    if (imgData.getType() == VFX_IMAGE_SRC_TYPE_RES_ID)
    {
        m_imgData.setResId(imgData.getResId());
    }
    else if (imgData.getType() == VFX_IMAGE_SRC_TYPE_PATH)
    {
        m_imgData.setPath(imgData.getPath());
    }
    m_textData = textData;
    setIconData();
    checkUpdate();
}

void VappBrwHomePageIcon::onDeinit()
{       
    VcpPhotoBorderFrame::onDeinit();
}

void VappBrwHomePageIcon::updateString(void)
{   
    m_text->setString(m_textData);
    m_text->setColor(VFX_COLOR_WHITE);
    VfxFontDesc font;
	font.size = VFX_FONT_DESC_VF_SIZE(m_iconTextFontSize);
    font.effect |= VFX_FE1_9;
    m_text->setFont(font);
    if(m_lock)
    {
        m_text->setMargins(m_lockIconWidth + (m_iconTitleMargin  + m_LockTitleTextMargin), 0, 0, 0);
    }
    else
    {
        m_text->setMargins(m_iconTitleMargin, 0, 0, 0);
    }
}

void VappBrwHomePageIcon::setIconData()
{   
    VfxRect rect = getBounds();
    if (m_imgData.getType() == VFX_IMAGE_SRC_TYPE_RES_ID)
    {
        m_image->setImgContent(VfxImageSrc(m_imgData.getResId())); 
	}    
    else if (m_imgData.getType() == VFX_IMAGE_SRC_TYPE_PATH)
    {
        m_image->setImgContent(VfxImageSrc(m_imgData.getPath()));
	}
	m_image->setCacheMode(VFX_CACHE_MODE_FORCE);// suggets by jimmy
    if(m_text)
    {
        m_text->setString(m_textData);
        m_text->setColor(VFX_COLOR_WHITE);
        VfxFontDesc font;
        //font.size = VFX_FONT_DESC_VF_SIZE(14);
		font.size = VFX_FONT_DESC_VF_SIZE(m_iconTextFontSize); 
        m_text->setFont(font);
        if(m_lock)
        {
            m_text->setMargins(m_lockIconWidth + (m_iconTitleMargin + m_LockTitleTextMargin), 0, 0, 0);
        }
        else
        {
            m_text->setMargins(m_iconTitleMargin, 0, 0, 0);
        }

        if(m_lock)
        {
            if (m_lockImage == NULL)
            {
                VFX_OBJ_CREATE(m_lockImage, VfxImageFrame, m_iconDataFrame);
                m_lockImage->setImgContent(VfxImageSrc(IMG_ID_VAPP_BRW_LOCK));
				m_lockImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            }
            m_lockImage->setPos(VfxPoint(rect.getX()+m_iconTitleMargin, (rect.getY() + m_iconHeight + ((m_iconTextHeight -m_lockIconHeight)/2))));
            m_lockImage->setSize(m_lockIconWidth, m_lockIconHeight);
        }
        else
        {
            if (m_lockImage)
            {
                VFX_OBJ_CLOSE(m_lockImage);
            }
        }
    }
}

void VappBrwHomePageIcon::onUpdate(void)
{
    VcpPhotoBorderFrame::onUpdate();
    VfxRect rect = m_iconDataFrame->getBounds();
    if (m_text)
    {
        if(m_textData.isEmpty())
        {
            VFX_OBJ_CLOSE(m_textImage);
            VFX_OBJ_CLOSE(m_text);
            if (m_lockImage)
            {
                VFX_OBJ_CLOSE(m_lockImage);
            }
            m_image->setPos(VfxPoint(rect.size.width / 2, (rect.size.height)/ 2));
			m_image->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);		
        }
    }
    else
    {
        if(!m_textData.isEmpty())
        {
            VFX_OBJ_CREATE(m_textImage, VfxImageFrame, m_iconDataFrame);
            VFX_OBJ_CREATE(m_text, VfxTextFrame, m_iconDataFrame);
            if(m_lock)
            {
                if (m_lockImage == NULL)
                {
                    VFX_OBJ_CREATE(m_lockImage, VfxImageFrame, m_iconDataFrame);
                    m_lockImage->setImgContent(VfxImageSrc(IMG_ID_VAPP_BRW_LOCK));
					m_lockImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
                }
                m_lockImage->setPos(VfxPoint(rect.getX()+m_iconTitleMargin, (rect.getY() + m_iconHeight + ((m_iconTextHeight -m_lockIconHeight)/2))));
                m_lockImage->setSize(m_lockIconWidth, m_lockIconHeight);
            }
            else
            {
                if (m_lockImage)
                {
                    VFX_OBJ_CLOSE(m_lockImage);
                }
            }
            m_text->setAutoResized(VFX_FALSE); 
            m_text->setVerticalToCenter(VFX_TRUE);
            m_image->setPos(VfxPoint(rect.size.width / 2, (rect.size.height - m_iconTextHeight) / 2));
            m_image->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT);
            m_textImage->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
            m_textImage->setImgContent(VfxImageSrc(IMG_ID_VAPP_BRW_WEBSITE_BG));
            m_text->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            m_text->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
            	m_text->setPos(VfxPoint(m_image->getRect().getX(), (m_image->getRect().getHeight())));
        m_textImage->setPos(VfxPoint(m_image->getRect().getX(), (m_image->getRect().getHeight())));
            m_text->setSize(m_iconWidth, m_iconTextHeight);
            m_textImage->setSize(m_iconWidth, m_iconTextHeight);
            updateString();
        }
    }
}
#endif
#endif

#endif /* _VAPP_BRW_HOMEPAGE_CPP_ */
