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
 *  vcp_option_menu.h
 *
 * Project:
 * --------
 *  VenusMMI
 *
 * Description:
 * ------------
 *  Option menu header
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VCP_OPTION_MENU_H__
#define __VCP_OPTION_MENU_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vcp_res.h"
#include "vcp_base_menu.h"
#include "vcp_button.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_frame.h"
#include "vfx_draw_context.h"
#include "vrt_datatype.h"
#include "vfx_control.h"
#include "vfx_image_src.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vfx_string.h"
#include "vfx_class_info.h"
#include "vfx_text_frame.h"
#include "vfx_primitive_frame.h"
#include "vfx_signal.h"
#include "vfx_animation.h"
#include "vfx_base_popup.h"
#include "vfx_input_event.h"
#include "mmi_rp_srv_venus_component_option_menu_def.h"
#include "vcp_state_image.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
/***************************************************************************** 
 * class VcpOptionBaseMenuLayout
 *****************************************************************************/
class VcpOptionBaseMenuLayout : public VcpBaseMenuLayout
{
    friend class VcpOptionBaseMenu;

// Constructor / Destructor
public:    
    // <group DOM_OptionMenu_VcpOptionBaseMenuLayout_Constructor/Destructor>
    // Constructor
    VcpOptionBaseMenuLayout(VcpBaseMenu* menu) : VcpBaseMenuLayout(menu) {}

// Overridable
public:
    virtual void onInit()        
    {
        VcpBaseMenuLayout::onInit();

        m_cellWidth = CELL_WIDTH;
        m_cellHeight = CELL_HEIGHT;
        m_headerHeight = 0;
        m_columnCount = 1;
        m_groupGap = 0;
        m_cellCount = 0;
    }

    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }

    virtual VfxS32 getGroupCount()
    {
        return 1;
    }
    
    virtual VfxS32 getCellCount(VfxS32 group)
    {
        VFX_UNUSED(group);
        return m_cellCount;
    }

    virtual VfxS32 getContentLength()
    {
        return m_cellCount * m_cellHeight;
    }

    virtual VfxBool hasGroupHeader(VfxS32 group)
    {
        VFX_UNUSED(group);
        return VFX_FALSE;
    }

    virtual VcpMenuRegion queryRegion(const VfxRect& r)
    {
        return VcpMenuRegion(
            getCellByPos(r.origin),
            getCellByPos(VfxPoint(r.getMaxX(), r.getMaxY()))
        );
    }

    VcpMenuPos getCellByPos(VfxPoint pt)
    {
        VcpMenuPos p;
        p.group = 0;
        p.pos = pt.y / m_cellHeight;        
        return p;
    }    

    // Return a cell rect
    virtual VfxRect queryCellRect(VcpMenuPos pos)
    {            
        return VfxRect(0, pos.pos * m_cellHeight, m_cellWidth, m_cellHeight);
    }

    virtual void getPreferFocusMargin(VfxS32 margin[4])
    {
        margin[0] = 0;
        margin[1] = m_cellHeight;
        margin[2] = 0;
        margin[3] = m_cellHeight;
    }

    virtual VfxBool navDir(NavDirEnum dir)
    {
        // If there is no one is focused, we pick up one in the screen
        if (!getFocusItem().isValid())
        {
            VcpMenuPos p = getCellByPos(m_viewRect.origin);
            // we cannot focus on the header
            if (p.isGroupHeader()) 
            {
                p.pos = 0;
            }
            setFocusItem(p);
            return VFX_TRUE;
        }

        VcpMenuPos p;
        if (dir == NAV_DIR_UP)
        {
            p = getFocusItem();

            p.pos--;
            if (p.pos < 0)
            {
                p.pos = 0;
            }
        }
        if (dir == NAV_DIR_DOWN)
        {
            p = getFocusItem();

            p.pos++;

            if (p.pos >= getCellCount(p.group))
            {
                p.pos = getCellCount(p.group) - 1;
            }
        }

        if (p.isValid())
        {
            setFocusItem(p);
            return VFX_TRUE;
        }
        
        return VFX_FALSE;
    }

// Method
public:
    // <group DOM_OptionMenu_VcpOptionBaseMenuLayout_Constructor/Destructor>
    // Gets the number of cells
    // RETURNS: cell number
    VfxS32 getCellNum() const
    {
        return m_cellCount;
    }
    
    // <group DOM_OptionMenu_VcpOptionBaseMenuLayout_Constructor/Destructor>
    // Sets the number of cells
    void setCellNum(
        VfxS32 num  // [IN] cell number
    )
    {
        if (num < 0)
        {
            num = 0;
        }
        m_cellCount = num;
    }

    // <group DOM_OptionMenu_VcpOptionBaseMenuLayout_Constructor/Destructor>
    // Gets the cell size.
    // RETURNS: cell size
    const VfxSize getCellSize() const
    {
        return VfxSize(m_cellWidth, m_cellHeight);
    }

    // <group DOM_OptionMenu_VcpOptionBaseMenuLayout_Constructor/Destructor>
    // Sets the cell size.
    void setCellSize(
        const VfxSize &cellSize // [IN] cell size
    )
    {
        m_cellWidth = cellSize.width;
        m_cellHeight = cellSize.height;
    }

// Variable
protected:
    VfxS32 m_cellHeight;
    VfxS32 m_cellWidth;
    VfxS32 m_headerHeight;
    VfxS32 m_columnCount;
    VfxS32 m_groupGap;
    VfxS32 m_groupStartPt[4];

    VfxS32 m_cellCount;

private:
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)    
        // 320x480
        CELL_WIDTH = 150,
        CELL_HEIGHT = 52
#elif defined(__MMI_MAINLCD_240X400__)
        // 240x400
        CELL_WIDTH = 200,
        CELL_HEIGHT = 42   
#else
        // 240x320
        CELL_WIDTH = 200,
        CELL_HEIGHT = 42       
#endif
    };
};


/***************************************************************************** 
 * class VcpOptionMenuItemSeparator
 *****************************************************************************/
class VcpOptionMenuItemSeparator : public VfxFrame
{
// Declaration
// Constructor / Destructor
public:
    // <group DOM_OptionMenu_VcpOptionMenuItemSeparator_Constructor/Destructor>
    // Constructor    
    VcpOptionMenuItemSeparator() {}
    
// Overridable
protected:
    virtual void onInit()
    {
        VfxFrame::onInit();
        setOpacity(0.45f);
        setSize(0, 2);
    }    

    virtual void onDraw(VfxDrawContext &dc)
    {        
        dc.setStrokeColor(VFX_COLOR_BLACK);
        dc.drawLine(0, 0, getSize().width - 1, 0);
        dc.setStrokeColor(VFX_COLOR_WHITE);
        dc.drawLine(0, 1, getSize().width - 1, 1);        
    }
};


/*****************************************************************************
 * Class VcpOptionMenuItem
 *****************************************************************************/
class VcpOptionMenuItem : public VfxControl
{
    VFX_DECLARE_CLASS(VcpOptionMenuItem);

// Constructor / Destructor
public:
    // <group DOM_OptionMenu_VcpOptionMenuItem_Constructor/Destructor>
    // Constructor
    VcpOptionMenuItem() :
        m_icon(VFX_IMAGE_SRC_NULL),
        m_flag(0),
        m_level(0),
#if defined(__MMI_VUI_COSMOS_CP__)
        m_first_level_bg(0, 0, 0, VCP_IMG_LIST_MENU_HIGHLIGHT_ITEM_BACKGROUND),
#else
        m_first_level_bg(VCP_IMG_OPTION_MENU_ITEM_FIRST_LEVEL_N, VCP_IMG_OPTION_MENU_ITEM_FIRST_LEVEL_P, 0, VCP_IMG_OPTION_MENU_ITEM_FIRST_LEVEL_H),
#endif
        m_firstChild(NULL),
        m_lastChild(NULL),
        m_next(NULL),
        m_prev(NULL),
        m_parent(NULL)
    {
    }

// Overridable
protected:
    virtual void onInit()
    {
        VfxControl::onInit();
        setImgContent(m_first_level_bg.getImageNormal());
		setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
        VFX_OBJ_CREATE(m_separator, VcpOptionMenuItemSeparator, this);
    }

// Method
public:
    // <group DOM_OptionMenu_VcpOptionMenuItem_Overridable>
    // Sets the text.
    virtual void setText(
        const VfxWString &str   // [IN] Text]
    )
    {
        m_text = str;
    }

    // <group DOM_OptionMenu_VcpOptionMenuItem_Method>
    // Gets the text.
    // RETURNS: the text
    VfxWString getText() const
    {
        return m_text;
    }    

    // <group DOM_OptionMenu_VcpOptionMenuItem_Method>
    // Gets the parent item.
    // RETURNS: the parent item
    VcpOptionMenuItem* getParentItem()
    {
        if ((VfxFrame*)getParentMenuItem() != getParentFrame())
        {   // level 1 items
            return (VcpOptionMenuItem*)getParentMenuItem();
        }

        // levle 0, parent is the menu
        return NULL;
    }

    // <group DOM_OptionMenu_VcpOptionMenuItem_Overridable>
    // Sets the checked state.
    virtual void setChecked(
        VfxBool isChecked   // [IN] check state
    )
    {
        VFX_UNUSED(isChecked);
    }

    // <group DOM_OptionMenu_VcpOptionMenuItem_Overridable>
    // Gets the checked state.
    // RETURNS: checked state
    virtual VfxBool getChecked()
    {
        return VFX_FALSE;
    }

    virtual void setBounds(const VfxRect &value)
    {
        m_separator->setRect(0, value.getHeight() - m_separator->getSize().height, value.getWidth(), m_separator->getSize().height);            
        VfxControl::setBounds(value);
    }

    // <group DOM_OptionMenu_VcpOptionMenuItem_Enum>
    // menu item event enum
    enum VcpOptionMenuItemEventEnum
    {
        MENU_ITEM_EVENT_TAP,
        MENU_ITEM_EVENT_GET_CHECKED,
        MENU_ITEM_EVENT_SET_CHECKED,
        MENU_ITEM_EVENT_SET_FOCUS,
        MENU_ITEM_EVENT_END_OF_ENUM
    };

    virtual VfxBool onEvent(VcpOptionMenuItemEventEnum event, VfxU32 param, VfxU32 *ret);

    enum VcpOptionMenuItemFlagEnum
    {
        IS_HAS_CHILD = 1 << 0,
        IS_CHILD_EXPAND = 1 << 1
    };

    // <group DOM_OptionMenu_VcpOptionMenuItem_Method>
    // Gets the item flag
    // RETURNS: item flag is set or not
    VfxBool getFlag(
        VcpOptionMenuItemFlagEnum flag  // [IN] flag
    )
    {
        return (m_flag & flag) ? VFX_TRUE : VFX_FALSE;
    }

    // <group DOM_OptionMenu_VcpOptionMenuItem_Method>
    // Sets the item flag    
    void setFlag(
        VcpOptionMenuItemFlagEnum flag, // [IN] flag 
        VfxBool isTrue                  // [IN] flag state
    )
    {
        if (isTrue)
        {
            m_flag |= flag;
        }
        else
        {
            m_flag &= ~flag;
        }
    }

    // <group DOM_OptionMenu_VcpOptionMenuItem_Method>
    // Sets the item level
    virtual void setLevel(
        VfxS32 level    // [IN] level
    )
    {
        // switch level visual if level is different
        if (level != m_level)            
        {
            if (level)
            {
                if ((VcpOptionMenuItem*)getPrevFrame() == getParent())
                {   // first item in the second level
                    setImgContent(VfxImageSrc(VCP_IMG_OPTION_MENU_ITEM_SECOND_LEVEL_P));
                }
                else
                {   // other items
                   setImgContent(VfxImageSrc(VCP_IMG_OPTION_MENU_ITEM_SECOND_LEVEL_N));
                }                    
            }
            else
            {
               setImgContent(m_first_level_bg.getImageNormal());
            }
        }
        
        m_level = level;    
    }

    // <group DOM_OptionMenu_VcpOptionMenuItem_Method>
    // Gets the item level.
    // RETURNS: item level
    VfxS32 getLevel()
    {
        return m_level;
    }

    // <group DOM_OptionMenu_VcpOptionMenuItem_Method>
    // Sets the item id
    void setId(
        VfxId id    // [IN] id
    )
    {
        m_id = id;
    }

    // <group DOM_OptionMenu_VcpOptionMenuItem_Method>
    // Gets the item id.
    // RETURNS: item id
    VfxId getId() const
    {
        return m_id;
    }

    // <group DOM_OptionMenu_VcpOptionMenuItem_Method>
    // Sets the check state
    void setCheck(
        VfxBool isChecked   // [IN] check state
    )
    {
        onEvent(MENU_ITEM_EVENT_SET_CHECKED, (VfxU32)isChecked, NULL);
    }

    // <group DOM_OptionMenu_VcpOptionMenuItem_Method>
    // Gets the check state.
    // RETURNS: check state
    VfxBool getCheck()
    {
        VfxBool ret;
        VfxU32 isChecked = 0;
        
        ret = onEvent(MENU_ITEM_EVENT_GET_CHECKED, 0, &isChecked);

        if (ret && isChecked)
        {
            return VFX_TRUE;
        }

        return VFX_FALSE;        
    }

    enum
    {
        FIRST_LEVEL_TEXT_GAP = 24,
        SECOND_LEVEL_TEXT_GAP = 34,
        ICON_TEXT_GAP = 2
    };
        
//Method
public:
    void addChild(VcpOptionMenuItem* item)
    {
        // Add
        item->m_parent = this;
        item->m_prev = m_lastChild;
        item->m_next = NULL;

        // If there is no child newFrame, set the new frame to the first one
        if (m_firstChild == NULL)
        {
            m_firstChild = item;
        }
        
        if (m_lastChild != NULL)
        {
            m_lastChild->m_next = item;
        }
        m_lastChild = item;    
    }

	VcpOptionMenuItem *getParentMenuItem()
	{
		return m_parent;
	}
protected:
    VfxWString m_text;
    VfxImageSrc m_icon;
    VfxU32 m_flag;    
    VfxS32 m_level;
    VfxId m_id;
    VcpStateImage m_first_level_bg;

private:
    VcpOptionMenuItemSeparator *m_separator;
    VcpOptionMenuItem *m_firstChild;
    VcpOptionMenuItem *m_lastChild;
    VcpOptionMenuItem *m_next;
    VcpOptionMenuItem *m_prev;
    VcpOptionMenuItem *m_parent;
    
};


/*****************************************************************************
 * Class VcpOptionMenuTextItem
 *****************************************************************************/
class VcpOptionMenuTextItem : public VcpOptionMenuItem
{
    VFX_DECLARE_CLASS(VcpOptionMenuTextItem);

// Constructor / Destructor    
public:
    // <group DOM_OptionMenu_VcpOptionMenuTextItem_Constructor/Destructor>
    // Constructor
    VcpOptionMenuTextItem() : 
        m_iconFrame(NULL) 
    {}

// Overridable
protected:
    virtual void onInit()
    {
        VcpOptionMenuItem::onInit();

        VFX_OBJ_CREATE(m_subGroupIndicator, VfxControl, this);
        m_subGroupIndicator->setSize(VfxImageSrc(VCP_IMG_OPTION_MENU_ITEM_SUBGROUP_INDICATOR_N).getSize());
        m_subGroupIndicator->setImgContent(VfxImageSrc(VCP_IMG_OPTION_MENU_ITEM_SUBGROUP_INDICATOR_N));
        m_subGroupIndicator->setAnchor(0, 0.5f);
                
        VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
        m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

        enableSubGroupIndicator(VFX_FALSE);

        // TODO: use theme
        m_textFrame->setColor(VFX_COLOR_BLACK);
        m_textFrame->setAnchor(0, 0.5f);
        
        // default level 0
        setLevel(0);
    }

// Overridable
public:
    virtual VfxBool onEvent(VcpOptionMenuItemEventEnum event, VfxU32 param, VfxU32 *ret)
    {        
        switch (event)
        {
            case MENU_ITEM_EVENT_TAP:
                // group item tap
                if (!m_subGroupIndicator->getHidden())
                {
                    onSubGroup();

                    // unfocus the expanded group, the visual type is changed to pressed to put emphasis.
                    if (getFlag(IS_CHILD_EXPAND))
                    {
                        setImgContent(m_first_level_bg.getImagePressed());
                    }
                    else
                    {
                       setImgContent(m_first_level_bg.getImageNormal());
                    }
                    
                    return VFX_TRUE;
                }
                break;

            default:
                break;
        }

        VfxBool ret_code = VcpOptionMenuItem::onEvent(event, param, ret);

        // unfocus the expanded group, the visual type is changed to pressed to put emphasis.
        if ((event == MENU_ITEM_EVENT_SET_FOCUS) && !param && getFlag(IS_CHILD_EXPAND))
        {
           setImgContent(m_first_level_bg.getImagePressed());
        }
        
        return ret_code;
    }

    virtual void setLevel(VfxS32 level)
    {
        VcpOptionMenuItem::setLevel(level);

        update();
    }

    virtual void update();

    virtual void setText(const VfxWString &str)
    {
        m_text = str;
        m_textFrame->setAutoResized(VFX_FALSE);
        m_textFrame->setString(m_text);

        VfxRect b;
        b = m_textFrame->getMeasureBounds();
        m_textFrame->setSize(b.size);        
    }

    virtual void setIcon(const VfxImageSrc &icon)
    {
        m_icon = icon;

        if (m_iconFrame == NULL)
        {
            VFX_OBJ_CREATE(m_iconFrame, VfxImageFrame, this);
            m_iconFrame->setAnchor(0, 0.5f);                
        }                
                
        m_iconFrame->setImgContent(m_icon);
    }

    virtual void setBounds(const VfxRect &value)
    {        
        VcpOptionMenuItem::setBounds(value);

        update();        
    }

// Method
public:
    // <group DOM_OptionMenu_VcpOptionMenuTextItem_Method>
    // Enables the subgroup indicator
    void enableSubGroupIndicator(
        VfxBool isEnabled   // [IN] is enable subgroup indicator
    )
    {
        VfxSize indicatorSize = m_subGroupIndicator->getSize();
    
        m_subGroupIndicator->setHidden(!isEnabled);
        m_subGroupIndicator->setPos(getSize().width - indicatorSize.width - SUBGROUP_INDICATOR_RIGHT_GAP, getSize().height / 2);

        // resize text
        if (isEnabled)
        {
            VfxRect textBounds = m_textFrame->getBounds();

            textBounds.size.width = getSize().width - m_textFrame->getPos().x - indicatorSize.width - SUBGROUP_INDICATOR_RIGHT_GAP;
            m_textFrame->setBounds(textBounds);
        }
        
        setFlag(IS_HAS_CHILD, isEnabled);
    }

// Implementation
private:
    void onSubGroup()    
    {
        setFlag(IS_CHILD_EXPAND, !getFlag(IS_CHILD_EXPAND));

        if (getFlag(IS_CHILD_EXPAND))
        {
          m_subGroupIndicator->setImgContent(VfxImageSrc(VCP_IMG_OPTION_MENU_ITEM_SUBGROUP_INDICATOR_P));

        }
        else
        {
           m_subGroupIndicator->setImgContent(VfxImageSrc(VCP_IMG_OPTION_MENU_ITEM_SUBGROUP_INDICATOR_N));
        }
    }   

// Variable
private:
    enum
    {
        SUBGROUP_INDICATOR_RIGHT_GAP = 12
    };

    VfxControl *m_subGroupIndicator;
    VfxImageFrame *m_iconFrame;
protected:
    VfxTextFrame *m_textFrame;
};


/*****************************************************************************
 * Class VcpOptionMenuCheckItem
 *****************************************************************************/
class VcpOptionMenuCheckItem : public VcpOptionMenuItem
{
// Constructor / Destructor
public:
    // <group DOM_OptionMenu_VcpOptionMenuCheckItem_Constructor/Destructor>
    // Constructor
    VcpOptionMenuCheckItem() : 
      m_checkFrame(NULL),
      m_textFrame(NULL),
      m_iconFrame(NULL),
      m_isChecked(VFX_FALSE)
    {
    }

// Overridable
public:
    virtual void onInit()
    {
        VcpOptionMenuItem::onInit();

        VFX_OBJ_CREATE(m_checkFrame, VfxControl, this);
        
        m_checkFrame->setSize(VfxImageSrc(VCP_IMG_OPTION_MENU_CHECK_BOX_N).getSize());

        // init text
        VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
        m_textFrame->setPos(m_checkFrame->getSize().width, 0);
        m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
        
        // TODO: use theme
        m_textFrame->setColor(VFX_COLOR_BLACK);
        m_textFrame->setAnchor(0, 0.5f);

        setCheck(VFX_FALSE);
        setLevel(0);        
    }
   
    virtual VfxBool onEvent(VcpOptionMenuItemEventEnum event, VfxU32 param, VfxU32 *ret);

    // <group DOM_OptionMenu_VcpOptionMenuCheckItem_Overridable>
    // Sets the text.
    virtual void setText(
        const VfxWString &str   // [IN] string
    )
    {
        m_text = str;
        m_textFrame->setAutoResized(VFX_FALSE);
        m_textFrame->setString(m_text);

        VfxRect b;
        b = m_textFrame->getMeasureBounds();
        m_textFrame->setSize(b.size);
    }

    // <group DOM_OptionMenu_VcpOptionMenuCheckItem_Overridable>
    // Sets the icon.
    virtual void setIcon(
        const VfxImageSrc &icon // [IN] icon
    )
    {
        m_icon = icon;

        if (m_iconFrame == NULL)
        {
            VFX_OBJ_CREATE(m_iconFrame, VfxImageFrame, this);
            m_iconFrame->setAnchor(0, 0.5f);                
        }                
                
        m_iconFrame->setImgContent(m_icon);
    }
    
    virtual void update();

    // <group DOM_OptionMenu_VcpOptionMenuCheckItem_Overridable>
    // Sets the level.
    virtual void setLevel(VfxS32 level)
    {
        VcpOptionMenuItem::setLevel(level);

        update();
    }

    virtual void setBounds(const VfxRect &value)
    {
        VcpOptionMenuItem::setBounds(value);
        
        if (m_textFrame)
        {
            update();
        }
    }

// Method
public:
    // <group DOM_OptionMenu_VcpOptionMenuCheckItem_Method>
    // Sets the check state.
    void setCheck(
        VfxBool isChecked   // [IN] check state
    )
    {
        m_isChecked = isChecked;
        update();
    }

    // <group DOM_OptionMenu_VcpOptionMenuCheckItem_Method>
    // Gets the check state
    // RETURNS: check state
    VfxBool getCheck() const
    {
        return m_isChecked;
    }

// Implementation
protected:
    void onCheck()
    {
        setCheck(!getCheck());
        update();
    }

// Variable
protected:
    enum
    {
        CHECK_BOX_TO_TEXT_GAP = 1
    };

    VfxControl *m_checkFrame;
    VfxTextFrame *m_textFrame;
    VfxImageFrame *m_iconFrame;
    
    VfxBool m_isChecked;
};


/*****************************************************************************
 * Class VcpOptionMenuRadioItem
 *****************************************************************************/
class VcpOptionMenuRadioItem : public VcpOptionMenuCheckItem
{
    VFX_DECLARE_CLASS(VcpOptionMenuRadioItem);

// Declaration
public:
    // <group DOM_OptionMenu_VcpOptionMenuRadioItem_Enum>
    // style enum
    enum VcpOptionMenuRadioItemStyleEnum
    {
        VCP_OPTION_MENU_RADIO_ITEM_STYLE_DEFAULT,        
        VCP_OPTION_MENU_RADIO_ITEM_STYLE_ICON_RIGHT_ALIGN,
        VCP_OPTION_MENU_RADIO_ITEM_STYLE_END_OF_ENUM
    };

// Constructor / Destructor
public:
    // <group DOM_OptionMenu_VcpOptionMenuRadioItem_Constructor/Destructor>
    // Constructor
    VcpOptionMenuRadioItem() :
        m_onImg(VFX_IMAGE_SRC_NULL),
        m_offImg(VFX_IMAGE_SRC_NULL),
        m_style(VCP_OPTION_MENU_RADIO_ITEM_STYLE_DEFAULT)
    {
    }

// Method
public:
    // <group DOM_OptionMenu_VcpOptionMenuRadioItem_Method>
    // Sets the radio button image source.
    void setRadioImage(
        VfxImageSrc on,     // [IN] radio on image source
        VfxImageSrc off     // [IN] radio off image source
    )
    {
        m_onImg = on;
        m_offImg = off;
    }

    // <group DOM_OptionMenu_VcpOptionMenuRadioItem_Method>    
    // Sets the menu item style.
    void setStyle(
        VcpOptionMenuRadioItemStyleEnum style   // [IN] radio menu item style
    )
    {
        m_style = style;
    }

// Overridable
protected:
    virtual void onInit()
    {
        VcpOptionMenuCheckItem::onInit();
        m_checkFrame->setSize(VfxImageSrc(VCP_IMG_OPTION_MENU_RADIO_BOX_N).getSize());
        setCheck(VFX_FALSE);
        setLevel(0);
    }

    virtual void update();

// Variable
private:
    VfxImageSrc m_onImg, m_offImg;   
    VcpOptionMenuRadioItemStyleEnum m_style;
    
    enum
    {
        RADIO_BOX_TO_RIGHT_GAP = 4,
        RADIO_TEXT_TO_BUTTON_GAP = 3
    };    
};


/*****************************************************************************
 * Class VcpOptionBaseMenu
 *****************************************************************************/
class VcpOptionBaseMenu : public VcpBaseMenu
{
// Constructor / Destructor
public:
    class VcpOptionMenu;

    // <group DOM_OptionMenu_VcpOptionBaseMenu_Constructor/Destructor>
    // Constructor
    VcpOptionBaseMenu() : m_expandedSubGroup(NULL) {}

// Method
public:
    // <group DOM_OptionMenu_VcpOptionBaseMenu_Method>
    // update menu layout
    void update()
    {
        // clear layout cache
        m_cache.clear();
        updateLayout();
    }
    
protected:
    virtual void onInit();

    virtual VcpBaseMenuLayout* createLayout()
    {
        VFX_OBJ_CREATE_EX(m_layout, VcpOptionBaseMenuLayout, this, (this));
        return m_layout;
    }        

    VfxFrame *getCellByPos(VfxS32 pos);
    VfxS32 getPosByCell(VfxFrame *cellFrame);
    
    virtual VfxFrame* createCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos              // [IN] The cell index        
    )
    {
        VFX_UNUSED(group);
        return getCellByPos(pos);
    }


    // A notify that menu is going to close a cell
    virtual void onCloseCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index
        VfxFrame* cellFrame     // [IN] The cell will be closed
    )
    {
        VFX_UNUSED(group);
        VFX_UNUSED(pos);
        VFX_UNUSED(cellFrame);
        // VFX_OBJ_CLOSE(cellFrame);
    }

    // Notify to update a cell's attributes
    // Inheritor should override this function.
    virtual void onUpdateCell(
        const VfxRect &rect,    // [IN] The position that layouter report
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell,         // [IN] The cell object
        VfxU32 flag             // [IN] The state about this cell
    )
    {
        VFX_UNUSED(rect);
        VFX_UNUSED(group);
        VFX_UNUSED(flag);
        // cell->setAutoAnimate(VFX_TRUE);
        // do not update cells inside the clip
        if ((cell != m_subGroupClip) && (cell->getParentFrame() != m_subGroupClip))
        {
            cell->setPos(0, pos * m_layout->getCellSize().height);
        }
    }

    // Notify when a cell or header is interact.
    virtual void onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The pen position
        VfxFrame            *cell        // [IN] The cell object
    );

    virtual void onFocusIndexChange(
        VcpMenuPos focusItem,           // [IN] The focus item index now
        VcpMenuPos previousFocusItem    // [IN] The previous focus item index
    );

    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);

public:

    enum VcpOptionBaseMenuEventEnum
    {
        MENU_EVENT_ITEM_SELECTED,
        MENU_EVENT_END_OF_ENUM
    };

    // menu event signal
    VfxSignal3 <VcpOptionBaseMenu*, VcpOptionBaseMenuEventEnum, VcpOptionMenuItem*> m_signalMenu;

private:
    void expandGroup(VfxFrame *groupParent);
    void foldGroup(VfxFrame *groupParent);
    void setRadioGroupExclusive(VfxFrame *checkedGroupItem);
    void onSubGroupAnimStop(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void stopSubGroupAnim();

private:
    VcpOptionBaseMenuLayout *m_layout;

    void tapCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell          // [IN] The cell object
    );

    VfxFrame *m_subGroupClip;
    VfxS32Timeline *m_subGroupClipTl;

    VfxFrame *m_expandedSubGroup;
};


/*****************************************************************************
 * Class VcpOptionMenu
 *****************************************************************************/
class VcpOptionMenu : public VfxBasePopup
{
// Constructor / Destructor
public:
    // <group DOM_OptionMenu_VcpOptionMenu_Constructor/Destructor>
    // Constructor
    VcpOptionMenu();

// Overridable
protected:
    virtual void onInit();
    
    virtual VfxBool onPenInput(VfxPenEvent &event)
    {
        if (event.type == VFX_PEN_EVENT_TYPE_DOWN)
        {
            return VFX_TRUE;
        }

        return VfxBasePopup::onPenInput(event);
    }
    
    virtual void onPenInputOnOutside(VfxPenEvent &event)
    {
        if (m_isAutoCancel && !m_showCancelButton)
        {   // auto close the menu if pen down outside

            // emit menu cancel signal
            m_signalMenuCallback.postEmit(this, VCP_OPTION_MENU_EVENT_MENU_CANCEL, NULL);

            vfxPostInvoke1(this, &VcpOptionMenu::closeMenu, VFX_TRUE);
            
            return;
        }

        VfxBasePopup::onPenInputOnOutside(event);
    }

    virtual void setBounds(const VfxRect &value)
    {
        VfxBasePopup::setBounds(value);
        onSize();
    }

// Method
public:
    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Sets the title string
    virtual void setTitle(
        const VfxWString &title // [IN] title string
    );

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Gets the title string
    // RETURNS: title string
    VfxWString getTitle() const
    {
        return m_titleText;
    }        

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Sets the auto close flag
    void setIsAutoClose(
        VfxBool isAutoClose     // [IN] auto close flagf
    )
    {
        m_isAutoClose = isAutoClose;
    }

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Gets the auto close flag
    // RETURNS: auto close flag
    VfxBool getIsAutoClose() const
    {
        return m_isAutoClose;
    }

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Sets the auto cancel flag to enable/disable auto closing
    // menu when clicking outside the menu
    void setIsAutoCancel(
        VfxBool isAutoCancel    // [IN] auto cancel flag
    )
    {
        m_isAutoCancel = isAutoCancel;
    }

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Gets the auto cancel flag
    // RETURNS: auto cancel flag
    VfxBool getIsAutoCancel() const
    {
        return m_isAutoCancel;
    }

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Append items from the menu resource
    // RETURNS: VFX_TRUE if sucessful; otherwise, VFX_FALSE
    VfxBool loadFromRes(
        VfxResId id     // [IN] menu resource id
    );

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Creates a text menu item
    // RETURNS: created menu item    
    VcpOptionMenuItem* createMenuItem(
        VfxId itemId,           // [IN] item id
        VfxWString itemText,    // [IN] item iext
        VfxImageSrc itemIcon = VFX_IMAGE_SRC_NULL   // [IN] item icon
    );

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Creates a radio menu item
    // RETURNS: created menu item    
    VcpOptionMenuItem* createRadioMenuItem(
        VfxId itemId,           // [IN] item id
        VfxWString itemText,    // [IN] item iext
        VfxBool checkedState,   // [IN] checked state
        VfxImageSrc itemIcon = VFX_IMAGE_SRC_NULL,                            // [IN] item icon
        VfxImageSrc onImage  = VfxImageSrc(VCP_IMG_OPTION_MENU_RADIO_BOX_P),  // [IN] on image
        VfxImageSrc offImage = VfxImageSrc(VCP_IMG_OPTION_MENU_RADIO_BOX_N),  // [IN] off image
        VcpOptionMenuRadioItem::VcpOptionMenuRadioItemStyleEnum style = VcpOptionMenuRadioItem::VCP_OPTION_MENU_RADIO_ITEM_STYLE_ICON_RIGHT_ALIGN
    );

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Creates a check menu item
    // RETURNS: created menu item
    VcpOptionMenuItem* createCheckMenuItem(
        VfxId itemId,           // [IN] item id
        VfxWString itemText,    // [IN] item iext
        VfxBool checkedState,   // [IN] checked state
        VfxImageSrc itemIcon = VFX_IMAGE_SRC_NULL   // [IN] item icon
    );

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Appends an item
    void appendItem(
        VcpOptionMenuItem* parent,  // [IN] parent menu item
        VcpOptionMenuItem* item     // [IN] item to be inserted
    );

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Inserts an item after the specified item
    void insertItem(
        VcpOptionMenuItem* parent,          // [IN] parent menu item, NULL if the item to be inserted in the first level
		VcpOptionMenuItem* insertAfterItem, // [IN] insert after this item 
		VcpOptionMenuItem* item             // [IN] item to be inserted
    );

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Removes an item
    void removeItem(
        VcpOptionMenuItem* item     // [IN] menu item object
    );

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Closes an item
    void closeItem(
        VcpOptionMenuItem* item     // [IN] menu item object
    );

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Shows the option menu
    void showMenu()
    {
        // auto resize to fit items do not exceed the default menu size
        autoResize();
    
        // show popup
        show(VFX_TRUE);
    }

    // <group DOM_OptionMenu_VcpOptionMenu_Method>
    // Closes the menu
    void closeMenu(VfxBool isAnimated = VFX_TRUE)
    {
        // emit menu close signal
        m_signalMenuCallback.postEmit(this, VCP_OPTION_MENU_EVENT_MENU_CLOSE, NULL);

        // popup exit
        vfxPostInvoke1(this, &VcpOptionMenu::exit, isAnimated);
    }

    // <group DOM_OptionMenu_VcpOptionMenu_Enum>
    // menu event enum
    enum VcpOptionMenuEventEnum
    {
        VCP_OPTION_MENU_EVENT_ITEM_SELECTED,    // a menu item is selected
        VCP_OPTION_MENU_EVENT_MENU_CANCEL,      // the menu is cancelled by click outside or the close button
        VCP_OPTION_MENU_EVENT_MENU_CLOSE        // the menu is to be closed
    };

// Property
public:
    // <group DOM_OptionMenu_VcpOptionMenu_Event>
    // menu event signal
    VfxSignal3 <
        VcpOptionMenu*,         // option menu
        VcpOptionMenuEventEnum, // menu event
        VcpOptionMenuItem*      // menu item
    > m_signalMenuCallback;

// Implementation
private:
    void onMenuItemEvent(VcpOptionBaseMenu *menu, VcpOptionBaseMenu::VcpOptionBaseMenuEventEnum event, VcpOptionMenuItem *item);
    void onCloseButtonClick(VfxObject* sender, VfxId id);

protected:
	virtual void onSize();    
	virtual void autoResize();

// Variable
protected:
    // title background image frame
    VfxFrame *m_titleBg;
    // title text frame
    VfxTextFrame *m_titleFrame;
    
    VfxBool m_showCancelButton;

    // title string
    VfxWString m_titleText;
    enum
    {
        TITLE_VERTICAL_GAP = 6,
        TITLE_CLOSE_BUTTON_WIDTH = 25,
#if defined (__MMI_VUI_COSMOS_CP__)
        BG_IMG_GAP_LEFT = 4,
        BG_IMG_GAP_RIGHT = 4,
        BG_IMG_GAP_TOP = 0,
        BG_IMG_GAP_BOTTOM = 15,
#else
        BG_IMG_GAP_LEFT = 12,
        BG_IMG_GAP_RIGHT = 12,
        BG_IMG_GAP_TOP = 16,
        BG_IMG_GAP_BOTTOM = 16,
#endif
        MENU_RIGHT_GAP = 1,
        CANCEL_BUTTON_VERTICAL_GAP = 2
    };    
    // menu layout
    VcpOptionBaseMenuLayout *m_layout;
    // menu
    VcpOptionBaseMenu *m_menu;
    
    // background image
    VfxFrame *m_background;
    
private:
    // title close button
    VcpButton *m_closeButton;

    // auto close flag
    VfxBool m_isAutoClose;
    // auto cancel flag
    VfxBool m_isAutoCancel;

    // cancel button
    VcpButton *m_cancelButton;
};


#endif /* __VCP_OPTION_MENU_H__ */


