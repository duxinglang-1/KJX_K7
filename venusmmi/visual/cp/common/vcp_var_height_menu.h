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
 *  vcp_var_height_menu.h
 *
 * Project:
 * --------
 *  Venus 
 *
 * Description:
 * ------------
 *  Variable Height Menu
 *
 *  The classes defined in this file are intended to be used by Message and Call only
 *  Please contact the owner if you want to use them for other applications
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
 * removed!
 *
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

#ifndef __VCP_VAR_HEIGHT_MENU_H__
#define __VCP_VAR_HEIGHT_MENU_H__

#include "vcp_include.h"

class VcpVarHeightMenuCurCellsIter;
class VcpVarHeightMenuCell;
class VcpVarHeightMenu;
class VcpVarHeightMenuLayout;

#include "vfx_container.h"

#define VCP_VAR_HEIGHT_MENU_INVALID_ID 0xFFFFFFFF
/***************************************************************************** 
 * Class VcpVarHeightMenuCurCellsIter
 *****************************************************************************/

class VcpVarHeightMenuCurCellsIter : VfxBase
{
// Constructor
public:
    VcpVarHeightMenuCurCellsIter(VcpVarHeightMenu *menu);    

// Method
public:
    VfxBool isEnd();
    VcpVarHeightMenuCell *next();

// Variable
protected:
    VcpMenuRegionIter m_itr;
    VcpVarHeightMenu *m_menu;
    VcpVarHeightMenuCell *m_curr;
};

/***************************************************************************** 
 * Class VcpVarHeightMenuCell
 *****************************************************************************/

class VcpVarHeightMenuCell : public VfxControl
{

// Constructor / Destructor
public:
    VcpVarHeightMenuCell(VcpMenuPos menupos);

// Override
protected:
    virtual void onInit();

// Overridable
public:
    // return the valid rect for touch down, touch up, tap event in cell coordinates
    virtual VfxRect getHitRect();

    // update the look of the cell on touch down, touch up
    virtual void setHighlight(VfxBool isHighlight);
    
    virtual void onBoundsChanged(VfxFrame *frame, const VfxRect &rect);

    // should be pure virtual function
    virtual VfxBool isReadyForAnimation() { return VFX_FALSE; }

    // should be pure virtual function
    virtual void playAnimation(VfxU32 start_seq) {}

// Methods
public:
    VcpVarHeightMenu *getMenu();

    VfxBool isTop();

    VfxBool isBottom();

// Properties
public:
    VcpMenuPos m_menupos;

// Events
public:
    VfxSignal1 <VcpVarHeightMenuCell *> m_signalTapped;    
    VfxSignal1 <VcpVarHeightMenuCell *> m_signalTouchDown;    
    VfxSignal1 <VcpVarHeightMenuCell *> m_signalTouchUp;    
    VfxSignal1 <VcpVarHeightMenuCell *> m_signalLongPressed;    
};


class VcpVarHeightMenuItem : public VfxBase
{
// Constructor
public:
    VcpVarHeightMenuItem():
        m_id(VCP_VAR_HEIGHT_MENU_INVALID_ID), m_accumulatedLength(0), m_userData(NULL), m_userDataSize(0)
    {};

    VcpVarHeightMenuItem(VfxId id, VfxS32 accumulatedLength):
        m_id(id), m_accumulatedLength(accumulatedLength), m_userData(NULL), m_userDataSize(0)
    {};


// Variable
public:
    VfxId m_id;
    VfxS32 m_accumulatedLength;
    void* m_userData;
    VfxS32 m_userDataSize;    
};

/***************************************************************************** 
 * Class VcpVarHeightMenu
 *
 * Methods sub-classes must implement in order to be a concrete class: 
 * 1. virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);   
 * 2. virtual VfxU32 getCount();
 * 3. virtual VfxU32 getItemHeight(VfxU32 index);                     
 *****************************************************************************/

class VcpVarHeightMenu : public VcpBaseMenu 
{

public:
    enum VcpVarHeightMenuLayoutType {
        LAYOUT_NORMAL,
        LAYOUT_REVERSE  
    };

// Constructor / Destructor
public:
    VcpVarHeightMenu(VcpVarHeightMenuLayoutType type = LAYOUT_NORMAL);

// Method
public:
    void setCount(VfxS32 count);
    void setDefaultHeight(VfxS32 height);
    VfxS32 getCellCount()
    {
        return m_cellCount;
    }
    VfxS32 getDefaultHeight()
    {
        return m_defaultHeight;
    }
    void setItemHeight(VfxS32 index, VfxS32 height);
    VfxS32 getItemHeight(VfxS32 index);
    VfxS32 getAccumulatedItemHeight(VfxS32 index);
    
	VfxBool addItem(VfxId id, VfxS32 h, void* userData = NULL, VfxS32 size = 0);
	VfxBool insertItem(VfxId id, VfxS32 h, VfxId refId, VfxBool addBeforeRef, void* userData = NULL, VfxS32 size = 0);
  	VfxBool insertItem(VfxId id, VfxS32 h, VfxS32 index, void* userData = NULL, VfxS32 size = 0);
	VfxBool removeItem(VfxId id);
	VfxBool removeItem(VfxS32 index);    
	VfxBool updateItem(VfxId id);
	VfxBool updateItem(VfxS32 index); 
    void* getItemData(VfxS32 index);
    void* getItemData(VfxId id);
    VfxId getItemId(VfxS32 index);
    VfxS32 getItemIndex(VfxId id);    


    // get an iterator to iterate current cells which are within view + cache
    VcpVarHeightMenuCurCellsIter getCurrentCellsIter();


    VfxBool isReverse();

    void setHasHighlight(VfxBool has_highlight);

    VfxBool hasHighlight();

    void setHasAnimation(VfxBool has_animation);

    VfxBool hasAnimation();

    // set external ready flag to true
    void setReadyForAnimation();

    // check if all cells are ready and set interal ready flag to true
    void checkReadyForAnimation(VfxObject* content, VfxBool isReady);

    // coordinate all cells to play animation
    void playAnimation();

    // see if animation has been played
    VfxBool isAnimationPlayed();

    void forceUpdateCell(VcpMenuPos pos);

// Overridable
public:

    virtual VfxBool getMenuEmptyText(
        VfxWString &text,                // [OUT] the text resource
        VcpListMenuTextColorEnum &color  // [OUT] the text color
    ) {return VFX_FALSE;}

    // add a margin area item, the newer, the inner
    virtual void addMarginItem(
       VcpBaseMenuMarginAreaEnum area,                     // [IN] The margin area type
       VcpBaseMenuMarginAreaFramePlacementEnum placement,  // [IN] The frame placement
       VfxFrame *frame                                     // [IN] The frame to be added
    );

    virtual void removeMarginItem(
       VfxFrame *frame // [IN] The frame to be removed
    );

    virtual void removeMarginItem(
         VcpMenuPos pos // [IN] The frame to be removed
    );

// Override
public:
    virtual void onInit(); 
    virtual void onDeinit();
    

    virtual void setBounds(const VfxRect &value);

    virtual void setImgContent(const VfxImageSrc &value);

    virtual void onAfterCreateLayout();
    
// Override
protected:
    // create VcpVarHeightMenuLayout
    virtual VcpBaseMenuLayout* createLayout();

    virtual void onCloseCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index
        VfxFrame* cellFrame     // [IN] The cell will be closed
    );

    virtual void onUpdateCell(
        const VfxRect &rect,    // [IN] The position that layouter report
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell,         // [IN] The cell object
        VfxU32 flag             // [IN] The state about this cell
    );

    // handle touch down,  touch up and tap events
    virtual void onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The touch position
        VfxFrame            *cell        // [IN] The cell object
    );

    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);

    virtual void onFocusIndexChange(
        VcpMenuPos focusItem,           // [IN] The focus item index now
        VcpMenuPos previousFocusItem    // [IN] The previous focus item index
    );

    virtual void onViewBoundsValueChange(VfxFrame *source, const VfxRect &oldBounds);

    virtual void onUpdate();


    virtual VfxBool IsSupportTransition();

// Implementation
private:
    VfxBool isReadyForAnimation();

    void updateOrigin();
    void updateCountAndDefaultHeight();

// Variable
protected:
    VfxArray <VcpVarHeightMenuItem> m_items;
    VfxImageFrame *m_bkgd;
private:

    VfxS32 m_defaultHeight;
    VfxS32 m_cellCount;
    VcpVarHeightMenuLayoutType m_type;
    VfxBool m_hasHighlight;
    VfxBool m_hasAnimation;
    VfxBool m_animationReadyInternal;
    VfxBool m_animationReadyExternal;
    VfxBool m_animationPlayed;
    VfxTextFrame *m_emptyText;

};

/***************************************************************************** 
 * Class VcpVarHeightMenuLayout
 *****************************************************************************/

class VcpVarHeightMenuLayout : public VcpBaseMenuLayout
{

// Constructor / Destructor
public:
    VcpVarHeightMenuLayout(VcpVarHeightMenu *menu);


// Overridable
public:
   

    virtual VfxS32 getContentLength();
    virtual VcpMenuRegion queryRegion(const VfxRect& r);
    virtual VfxRect queryCellRect(VcpMenuPos pos);

    virtual VcpBaseMenuLayout::ScrollDirEnum getScrollDir();
    virtual VfxBool navDir(NavDirEnum dir);
    virtual VfxRect queryMarginItemRect(VcpMenuPos pos);    

    virtual VfxS32 getCellCount(VfxS32 group);

// Overridable
protected:
    virtual VcpMenuPos queryPosByPt(VfxS32 y);

// Implementation
protected:

    VcpVarHeightMenu *getVarHeightMenu() { return (VcpVarHeightMenu *)m_pMenu;}

// Variable
protected:
    

   
};

#endif /* __VCP_VAR_HEIGHT_MENU_H__ */
