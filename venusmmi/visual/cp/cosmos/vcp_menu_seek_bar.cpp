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
 *  vcp_menu_seek_bar.cpp
 *
 * Project:
 * --------
 *  Venus UI Components
 *
 * Description:
 * ------------
 *  Menu Seek Bar component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "vfx_cpp_base.h"
#include "vfx_object.h"
#include "vfx_sys_memory.h"
#include "vfx_class_info.h"
#include "vfx_datatype.h"
#include "vfx_string.h"
#include "vfx_image_src.h"
#include "vfx_control.h"
#include "vrt_datatype.h"
#include "vrt_system.h"
#include "vfx_basic_type.h"
#include "vfx_text_frame.h"
#include "vfx_font_desc.h"
#include "vfx_frame.h"
#include "vfx_signal.h"
#include "vfx_input_event.h"
#include "vcp_button.h"
#include "vfx_object_list.h"
#include "vcp_menu_seek_bar.h"
#include "mmi_rp_srv_venus_component_menu_seek_bar_def.h"


/***************************************************************************** 
 * Class VcpTabBar
 *****************************************************************************/
//VFX_IMPLEMENT_CLASS("VcpMenuSeekBarItem", VcpMenuSeekBarItem, VfxObject);


VcpMenuSeekBarItem::VcpMenuSeekBarItem():
m_string_item(VFX_WSTR_NULL),    
m_image_item(VfxImageSrc()),
id(0xFFFFFFFF)
{
}

/***************************************************************************** 
 * Class VcpTabBar
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VcpMenuSeekBar", VcpMenuSeekBar, VfxControl);


VcpMenuSeekBar::VcpMenuSeekBar():
    m_count(0),    
    m_highlightedId(0xFFFFFFFF),
    m_textFrame(NULL),
    m_imageFrame(NULL), 
    m_state(VCP_MENUSEEKBAR_STATE_NORMAL)
{
}

    
void VcpMenuSeekBar::onInit()
{
    VfxControl::onInit();
    // set default size
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;
    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);
    setSize(VfxSize(VCP_MENU_SEEK_BAR_DEFAULT_WIDTH, main_screen_size.height));
    setImgContent(VfxImageSrc(VCP_IMG_MENU_SEEK_BAR_DOT)); 
    setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    setOpacity(0.5f);
    setAutoAnimate(VFX_TRUE);


    // create image frame
    VFX_OBJ_CREATE(m_imageFrame, VfxFrame, getParentFrame()->getParentFrame());
    m_imageFrame->bringToFront();
    m_imageFrame->setSize(VCP_MENU_SEEK_BAR_HINT_SIZE, VCP_MENU_SEEK_BAR_HINT_SIZE);
    m_imageFrame->setHidden(VFX_TRUE);
    m_imageFrame->setImgContent(VfxImageSrc(VCP_IMG_MENU_SEEK_BAR_HINT));
    m_imageFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_imageFrame->setOpacity(1.0f);
    
    // create text frame
    VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, m_imageFrame);
    m_textFrame->setPos(0,0);
    m_textFrame->setSize((VCP_MENU_SEEK_BAR_HINT_SIZE - VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_MARGIN),
        (VCP_MENU_SEEK_BAR_HINT_SIZE - VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_MARGIN));
    m_textFrame->setHidden(VFX_TRUE);
    m_textFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(VCP_MENU_SEEK_BAR_HINT_FONT_SIZE)));
    m_textFrame->setColor(VfxColor(255,255,255,255));
    m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_textFrame->setMargins(0, VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_TT_MARGIN, 0, VCP_MENU_SEEK_BAR_HINT_CONTENT_FRAME_TB_MARGIN);
    m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_textFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
    m_textFrame->setAutoResized(VFX_FALSE);

    // register signal
    m_signalBoundsChanged.connect(this, &VcpMenuSeekBar::onBoundsChanged);
}

void VcpMenuSeekBar::onUpdate()
{
    VfxSize size = getSize();
    VfxPoint position = getPos();
    VfxPoint imageFramePos = m_imageFrame->getPos();
    m_imageFrame->setPos(((position.x - VCP_MENU_SEEK_BAR_HINT_SIZE)>>1), imageFramePos.y);
    if(!m_count)
    {
        m_maxItemHeight = size.height;
        return;
    }
    if (size.height > m_count)
    {
        m_maxItemHeight = (size.height /m_count);
    }

}

VfxBool VcpMenuSeekBar::onPenInput(VfxPenEvent &event)
{
    VfxPoint p = event.getRelPos(this);
    VfxS32 index;   
    VcpMenuSeekBarItem *pItem;
    switch(event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            {
                if (!getIsDisabled())
                {
                    index = convertYToIndex(p.y);
                    pItem =   getItemFromMenuSeekBar(index);
                    if ((!pItem) ||(pItem->m_string_item.isNull()) && (pItem->m_image_item.isNull()))
                    {
                        resetMenuSeekBarState();
                        break;
                    }
                    m_state = VCP_MENUSEEKBAR_STATE_PRESSED;
                    setItemToHint(pItem, p.y);
                    m_signalMenuSeekBarTouch.postEmit(m_highlightedId);
                }
                break;
            }

        case VFX_PEN_EVENT_TYPE_MOVE:
            {
                if (m_state == VCP_MENUSEEKBAR_STATE_PRESSED )
                {
                    index = convertYToIndex(p.y);
                    pItem =   getItemFromMenuSeekBar(index);
                    if((!pItem) || ((pItem->m_string_item.isNull()) && (pItem->m_image_item.isNull())) || (p.y < 0))
                    {
                        resetMenuSeekBarState();
                        break;
                    }
                    setItemToHint(pItem, p.y);
                    m_signalMenuSeekBarTouch.postEmit(m_highlightedId);
                }
                else if (!getIsDisabled())
                {
                    index = convertYToIndex(p.y);
                    pItem =   getItemFromMenuSeekBar(index);
                    if((!pItem) ||((pItem->m_string_item.isNull()) && (pItem->m_image_item.isNull())) || (p.y < 0))
                    {
                        resetMenuSeekBarState();
                        break;
                    }
                    m_state = VCP_MENUSEEKBAR_STATE_PRESSED;
                    setItemToHint(pItem, p.y);
                    m_signalMenuSeekBarTouch.postEmit(m_highlightedId);
                }
            }
            break;

        case VFX_PEN_EVENT_TYPE_UP:
            if (m_state == VCP_MENUSEEKBAR_STATE_PRESSED)
            {
                resetMenuSeekBarState();
            }
            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            resetMenuSeekBarState();
            break;

        default:
            break;
    }

    checkUpdate();

    // handle all events
    return VFX_TRUE;
}


VfxBool VcpMenuSeekBar::onContainPoint(const VfxPoint &point) const
{
    VfxRect bounds = getBounds();
    if (bounds.size.width < VCP_MENU_SEEK_BAR_TOUCH_MINIMAL_SIZE)
    {
        bounds.origin.x -= (VCP_MENU_SEEK_BAR_TOUCH_MINIMAL_SIZE - bounds.size.width) / 2;
        bounds.size.width = VCP_MENU_SEEK_BAR_TOUCH_MINIMAL_SIZE;
    }
    if (bounds.size.height < VCP_MENU_SEEK_BAR_TOUCH_MINIMAL_SIZE)
    {
        bounds.origin.y -= (VCP_MENU_SEEK_BAR_TOUCH_MINIMAL_SIZE - bounds.size.height) / 2;
        bounds.size.height = VCP_MENU_SEEK_BAR_TOUCH_MINIMAL_SIZE;
    }
    return bounds.contains(point);
}

void VcpMenuSeekBar::addTextItem(
    VfxId id,
    VfxResId resId)
{
    addTextItem(id, VFX_WSTR_RES(resId));
}

void VcpMenuSeekBar::addTextItem(
    VfxId id,
    const VfxWChar *text)
{
    addTextItem(id, VFX_WSTR_MEM(text));
}


void VcpMenuSeekBar::addTextItem (VfxId id, const VfxWString &text)
{
    VcpMenuSeekBarItem *item;
    VFX_OBJ_CREATE(item, VcpMenuSeekBarItem, this);
    item->m_string_item = text;
    item->id = id;
    m_list.append(item);
    m_count ++;
    checkUpdate();
    invalidate();
}
void VcpMenuSeekBar::insertTextItem (
    VfxId id,
    VfxResId resId,
    VfxId beforeId)
{
    insertTextItem(id, VFX_WSTR_RES(resId), beforeId);
}
void VcpMenuSeekBar::insertTextItem (
    VfxId id,
    const VfxWChar *text,
    VfxId beforeId)
{
    insertTextItem(id, VFX_WSTR_MEM(text), beforeId);
}

void VcpMenuSeekBar:: insertTextItem (VfxId id, const VfxWString &text, VfxId beforeId)
{
    VcpMenuSeekBarItem *item;
    VFX_OBJ_CREATE(item, VcpMenuSeekBarItem, this);
    item->m_string_item = text;
    item->id = id;
	insertItemInt(item, beforeId);
}
void VcpMenuSeekBar::insertItemInt (VcpMenuSeekBarItem *item, VfxId beforeId)
{	
    VfxBool isEnd = VFX_TRUE;
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpMenuSeekBarItem *pItem = (VcpMenuSeekBarItem *)i->get();
        if (pItem->id == beforeId)
        {
            m_list.insertBefore(i, item);
            isEnd = VFX_FALSE;
        }
    }
    if (isEnd)
    {   
        m_list.append(item);
    }
    m_count ++;
    checkUpdate();
    invalidate();
}
void VcpMenuSeekBar::addImageItem (VfxId id, const VfxImageSrc &img)
{
    VcpMenuSeekBarItem *item;
    VFX_OBJ_CREATE(item, VcpMenuSeekBarItem, this);
    item->m_image_item = img;
    item->id = id;
    m_list.append(item);
    m_count ++;
    checkUpdate();
    invalidate();
}

void VcpMenuSeekBar:: insertImageItem (VfxId id, const VfxImageSrc &img, VfxId beforeId)
{
    VcpMenuSeekBarItem *item;
    VFX_OBJ_CREATE(item, VcpMenuSeekBarItem, this);
    item->m_image_item = img;
    item->id = id;

  	insertItemInt(item, beforeId);
}

void VcpMenuSeekBar::deleteItem (VfxId id)
{
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = i->getValidNext())
    {
        VcpMenuSeekBarItem *pItem = (VcpMenuSeekBarItem *)i->get();

        if (pItem->id == id)
        {   
            m_list.removeOne(pItem);
            VFX_OBJ_CLOSE(pItem);
            m_count --;
        }
    }
    checkUpdate();
}

void VcpMenuSeekBar::clearAllItems ()
{
    VfxObjListEntry *j;
    for (VfxObjListEntry *i = m_list.getValidHead() ; i != NULL ; i = j)
    {
        j = i->getValidNext();        
        VcpMenuSeekBarItem *pItem = (VcpMenuSeekBarItem *)i->get();    
        m_list.removeOne(pItem);
        VFX_OBJ_CLOSE(pItem);
	 m_count--;
   }  
   checkUpdate();
}

void VcpMenuSeekBar::setHeight(VfxS32 height )
{
    VfxSize size = getSize();
    size.height = height;
    setSize(size);
    checkUpdate();
}

VfxS32 VcpMenuSeekBar::getMaxItemCount(void)
{
    return VCP_MENU_SEEK_BAR_MAX_ITEM_COUNT;

}

VfxS32 VcpMenuSeekBar::convertYToIndex(VfxS32 y)
{
    if (y > m_maxItemHeight)
    {
        return (y/m_maxItemHeight) ;
    }
    else
    {
        return 0;
    }

}

VcpMenuSeekBarItem* VcpMenuSeekBar::getItemFromMenuSeekBar(VfxS32 index) 
{
    VcpMenuSeekBarItem *pItem = NULL;
    VfxU32 initial_index = 0;

    if (index >= m_count)
    {
        return NULL;
    }
    for (VfxObjListEntry *i = m_list.getValidHead(); i != NULL && initial_index <= index ; i = i->getValidNext(), initial_index++)
    {
        pItem = (VcpMenuSeekBarItem *)i->get();
    }
    return pItem;
}

void VcpMenuSeekBar::resetMenuSeekBarState()
{
    m_textFrame->setHidden(VFX_TRUE);
    m_imageFrame->setHidden(VFX_TRUE);
    m_state = VCP_MENUSEEKBAR_STATE_NORMAL;
    setOpacity(0.5f);
}


void VcpMenuSeekBar::setItemToHint(VcpMenuSeekBarItem * item, VfxS32 y)
{
    VfxPoint controlPos = getPos();
    VfxSize controlSize = getSize();
    VfxPoint imageFramePos = m_imageFrame->getPos();
    VfxSize imageFrameSize = m_imageFrame->getSize();
    if(m_imageFrame->getHidden())
    {
        m_imageFrame->setHidden(VFX_FALSE);
    }   
    if(m_textFrame->getHidden())
    {
        m_textFrame->setHidden(VFX_FALSE);
    }
    if (!(item->m_string_item.isNull()))
    {
        m_textFrame->setImgContent(VFX_IMAGE_SRC_NULL);
        m_textFrame->setString(item->m_string_item);
        
    }
    else
    {
        m_textFrame->setImgContent(item->m_image_item);
        m_textFrame->setString(VFX_WSTR_NULL);
    }
    /*
    if ( (y + imageFrameSize.height - 1) >=  controlSize.height)
    {
        y = controlSize.height - imageFrameSize.height;
    }
    */
    imageFramePos.y = controlPos.y + VCP_MENU_SEEK_BAR_REL_HINT_POSITION;
    m_imageFrame->setPos(imageFramePos);
    m_highlightedId = item->id;
    setOpacity(1.0f);
}
