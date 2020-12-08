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
 *  vapp_theme_menu.h
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __MMI_THEMES_APPLICATION__
#ifndef __VAPP_THEME_MENU_H__
#define __VAPP_THEME_MENU_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_datatype.h"
#include "vcp_base_menu.h"

#include "vapp_theme_gprot.h"
/***************************************************************************** 
 * define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
enum VappThemeMenuItemStateEnum
{
    VAPP_THEMEE_MENU_ITEM_STATE_NONE,
    VAPP_THEMEE_MENU_ITEM_STATE_UNSELECTED,
    VAPP_THEMEE_MENU_ITEM_STATE_SELECTED
};

enum VappThemeCellStateEnum
{
	VAPP_THEMEE_CELL_STATE_UNKNOWN,
	VAPP_THEMEE_CELL_STATE_INVALID,
	VAPP_THEMEE_CELL_STATE_VALID,
	VAPP_THEMEE_CELL_STATE_TOTAL
};


/***************************************************************************** 
 * Interface
 *****************************************************************************/
class IVappThemeMatrixMenuContentProvider 
{
// Overridable
public:
	virtual VfxBool getMenuEmptyText(VfxWString &text) {return VFX_FALSE;}   
	virtual VfxBool getItemText(VcpMenuPos pos, VfxWString &text){ return VFX_FALSE; } 
	virtual VfxBool getItemImage(VcpMenuPos pos, VfxImageSrc &src){ return VFX_FALSE; }
	virtual VfxBool freeItemImage(VcpMenuPos pos, VfxImageSrc &src){ return VFX_TRUE; }
	// should be non-cacheble memory
	virtual void * allocNcMem(VfxU32 size, void *userData) { return NULL; }
	virtual void freeNcMem(void *mem, void *userData) {}
	virtual VfxFrame *getCustomFrame(VfxFrame *parentFrame, VcpMenuPos pos){ return NULL; }
	virtual void closeCustomFrame(VcpMenuPos pos, VfxFrame *cell){}
	virtual VfxU32 getCount(VfxU32 group) const {return 0;}
	virtual VfxU32 getGroupCount() const {return 0;}
	virtual VfxBool hasGroupHeader(VfxS32 group) const { return VFX_FALSE;}
	virtual VfxBool check(VcpMenuPos pos) { return VFX_FALSE; }
	virtual VfxBool isAsyncImage(VcpMenuPos pos) {return VFX_FALSE; }
	virtual VappThemeMenuItemStateEnum getItemState(VcpMenuPos pos ) const
	{
		return VAPP_THEMEE_MENU_ITEM_STATE_NONE;
	}
};


/***************************************************************************** 
 * Class VappThemeViewCell
 *****************************************************************************/
class VappThemeViewCell : public VfxControl
{
// Interface
public:

	VappThemeViewCell();
    VappThemeViewCell(VcpMenuPos pos);
	
	VfxImageSrc getImgSrc(void);
	VfxPoint getSelPos(void) const;
	void setHighlight(VfxBool isHighlight, VfxBool isAnim);

	virtual void setContent(const VfxImageSrc &imgSrc, const VfxWString &text);
	virtual void setImage(const VfxImageSrc &imgSrc);


    enum
	{
		SHADOW_LEFT = 4,
		SHADOW_RIGHT = 4,
		SHADOW_TOP = 2,
		SHADOW_BOTTOM = 6,
		BORDER_WIDTH = 4,
		IMG_WIDTH = VAPP_THEME_CELL_IMG_WIDTH,
		IMG_HEIGHT = VAPP_THEME_CELL_IMG_HEIGHT,
		OUTER_HEIGHT = VAPP_THEME_CELL_HEIGHT,
#ifdef __MMI_MAINLCD_480X800__ /* WVGA */
		OUTER_WIDTH = 138,
		TXT_SIZE = 23,
		GAP = 3,
		HEIGHT = (OUTER_HEIGHT + GAP + TXT_SIZE),
		WIDTH = OUTER_WIDTH,
#elif defined  __MMI_MAINLCD_320X480__ /* HVGA */
		OUTER_WIDTH = 99,
		TXT_SIZE = 16,
		GAP = 0,
		HEIGHT = (OUTER_HEIGHT + GAP + TXT_SIZE),
		WIDTH = OUTER_WIDTH,
#elif defined	__MMI_MAINLCD_240X320__ /* QVGA */
		OUTER_WIDTH = 72,
		TXT_SIZE = 14,
		GAP = 0,
		HEIGHT = 109,//(OUTER_HEIGHT + GAP + TXT_SIZE),
		WIDTH = OUTER_WIDTH,
#elif defined	__MMI_MAINLCD_240X400__ /* WQVGA */
		OUTER_WIDTH = 72,
		TXT_SIZE = 14,
		GAP = 0,
		HEIGHT = (OUTER_HEIGHT + GAP + TXT_SIZE),
		WIDTH = OUTER_WIDTH,
#else // temp value
		OUTER_WIDTH = 64,
		TXT_SIZE = 21,
		GAP = 5,
		HEIGHT = (OUTER_HEIGHT + GAP + TXT_SIZE),
		WIDTH = OUTER_WIDTH,
#endif
    };
	
// Override
protected:
    virtual void onInit();
	virtual void onDeinit();
	virtual void onCreate(void);
	virtual VfxFrame *createImage(void);
	virtual void onLayout(void);

// Implement
protected:

	VfxFrame *m_icon;
	VfxImageFrame *m_iconOuter;
	VfxFrame *m_cover;
	VfxTextFrame *m_text;
	VcpMenuPos m_pos;
	VfxBool m_isHighlight;
};

#ifdef __MMI_THEME_SUPPORT_ASYNC_IMAGE__
/***************************************************************************** 
 * Class VappThemeViewAsyncCell
 *****************************************************************************/
class VappThemeViewAsyncCell : public VappThemeViewCell
{
// Interface
public:

	VappThemeViewAsyncCell() : VappThemeViewCell() {}
	VappThemeViewAsyncCell(
		const VfxImageSrc &imgSrc, 
		const VfxResId &previewImgId,
		IVappThemeMatrixMenuContentProvider *provider, 
		VcpMenuPos pos) : VappThemeViewCell(pos), m_imageSrc(imgSrc), m_previewImageId(previewImgId), m_provider(provider)
	{		
	}
	
public:
	virtual void setContent(const VfxImageSrc &imgSrc, const VfxWString &text);
	virtual void setImage(const VfxImageSrc &imgSrc);

// Override
protected:
	virtual void onDeinit();
	virtual VfxFrame *createImage(void);

private:
	VfxImageSrc m_imageSrc;
	VfxResId m_previewImageId;
	IVappThemeMatrixMenuContentProvider *m_provider;

	static void *allocMem(VfxU32 size, void *userData);	
	static void freeMem(void *mem, void *userData);
};

#endif // __MMI_THEME_SUPPORT_ASYNC_IMAGE__

/***************************************************************************** 
 * VappThemeMatrixMenuHeader 
 *****************************************************************************/
class VappThemeMatrixMenu;
class VappThemeMatrixMenuHeader : public VfxControl
{
// Constructor / Destructor
public:
    VappThemeMatrixMenuHeader(VfxU32 group) : m_group(group){}
    
// Override
protected:
    virtual void onInit();
    virtual void onUpdate();

// Overridable
protected:
    VappThemeMatrixMenu* getMenu();
    IVappThemeMatrixMenuContentProvider *getContentProvider();

// Implementation
private:
    void onBoundsValueChanged(VfxFrame *source, const VfxRect &oldBounds);
    void update();

private:

	// Copy from Listmenu
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        GAP = 10,
#elif defined(__MMI_MAINLCD_480X800__)
        GAP = 14,
#elif defined(__MMI_VUI_COSMOS_CP__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X240__))
        GAP = 5,
#else /* Shell: QVGA / WQVGA */
        GAP = 11,
#endif
    };

    VfxTextFrame *m_textFrame;
    VfxU32 m_group;

};


/***************************************************************************** 
 * VappThemeMatrixMenu 
 *****************************************************************************/
class VappThemeMatrixMenu : public VcpBaseMenu
{
// Constructor
public:
	VappThemeMatrixMenu() : m_provider(NULL),
									m_selectIcon(NULL),
									m_emptyText(NULL),
									m_currCheckPos(-1, -1),
									m_isNeedClear(VFX_FALSE),
									m_counter(0)
	{}

public:
	void setContentProvider(IVappThemeMatrixMenuContentProvider *content);
	IVappThemeMatrixMenuContentProvider *getContentProvider(void)
	{
		return m_provider;
	}
	
	VfxSignal2<VappThemeMatrixMenu *, VcpMenuPos> m_signalTap;

    void setItemHeight(const VfxS32 &height);
	
	void releaseCachedImage(void);
	void updateCachedImage(void);
	void forceCache(void);

	
// Override
protected:
	virtual void onInit(void);
	virtual void onUpdate();
    virtual VcpBaseMenuLayout* createLayout();
    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos);
    virtual void onAfterCreateLayout();

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

    virtual void onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The pen position
        VfxFrame            *cell        // [IN] The cell object
    );
	virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem);

	virtual VfxFrame* createGroupHeader(VfxS32 group);
	virtual void onUpdateGroupHeader(const VfxRect &rect, VfxS32 group, VfxFrame* obj, VfxU32 flag);
    virtual void onCloseGroupHeader(VfxS32 group, VfxFrame* groupFrame);
	void onBoundsChanged(VfxFrame *source, const VfxRect &oldBounds);

private:
	void updateEmptyText(void);
	
// Methods
private:
	IVappThemeMatrixMenuContentProvider *m_provider;
	VfxImageFrame *m_selectIcon;
	VfxTextFrame  *m_emptyText;
	VcpMenuPos m_currCheckPos;
	VfxBool m_isNeedClear;
	VfxS32 m_counter;
};


/***************************************************************************** 
 * Class VappThemeMatrixLayout
 *****************************************************************************/
class VappThemeMatrixLayout : public VcpBaseMenuLayout
{
// Constructor
public:
    VappThemeMatrixLayout() : VcpBaseMenuLayout(NULL) {};
    VappThemeMatrixLayout(VcpBaseMenu* menu) : VcpBaseMenuLayout(menu) {};

	void setHeaderHeight(const VfxS32 &height) { m_headerHeight = height; }
	VfxS32 getHeaderHeight(void) const { return m_headerHeight; }
	
    void setCellHeight(const VfxS32 &height) { m_cellHeight = height; }
    VfxS32 getCellHeight(void) const { return m_cellHeight; }
	
    void setColCount(const VfxS32 &count) { m_columnCnt = count; }

	void setProvider(IVappThemeMatrixMenuContentProvider *provider)
	{
		m_provider = provider;
	}
	
protected:
    virtual void onInit();
    virtual VfxS32 getCellCount(VfxS32 group)
    {
    	return (m_provider ? m_provider->getCount(group) : 0);
    }
    virtual VfxS32 getGroupCount()
    {
    	return (m_provider ? m_provider->getGroupCount() : 0);
    }
    virtual VfxBool hasGroupHeader(VfxS32 group)
    {
    	return (m_provider ? m_provider->hasGroupHeader(group) : VFX_FALSE);
    }
    virtual ScrollDirEnum getScrollDir(){ return SCROLLDIR_VERT; }

	// view height
    virtual VfxS32 getContentLength();

	// The pos & size of this pos
    virtual VfxRect queryCellRect(VcpMenuPos pos);

	// Return the start cell and end cell
    virtual VcpMenuRegion queryRegion(const VfxRect& r);

	// Key support
	virtual VfxBool navDir(NavDirEnum dir);

	virtual VfxRect queryGroupHeaderRect(VfxS32 group);
	virtual void onViewChanged();
	
private:
	VcpMenuPos queryPosByPt(const VfxPoint& pt);
	VfxS32 getGroupCellTotalHeight(const VfxS32 &group);
	
private:

	enum
	{
		COLUMN_COUNT = 3,
		HORI_GAP = 5,
		MAX_GROUP = 5,
#ifdef __MMI_MAINLCD_480X800__ /* WVGA */
		VERT_GAP = 23,
#elif defined  __MMI_MAINLCD_320X480__ /* HVGA */
		VERT_GAP = 6,
#elif defined	__MMI_MAINLCD_240X320__ /* QVGA */
		VERT_GAP = 8,
#elif defined	__MMI_MAINLCD_240X400__ /* WQVGA */
		VERT_GAP = 8,
#else // temp value
		VERT_GAP = 8,
#endif

	};




	IVappThemeMatrixMenuContentProvider *m_provider;
	VfxS32 m_headerHeight;
	VfxS32 m_cellHeight;
	VfxS32 m_cellWidth;
	VfxS32 m_columnCnt;
	VfxS32 m_horiGap;
	VfxS32 m_vertGap;
	VfxPoint m_goupCellStartPos[MAX_GROUP];
};


#endif /* __VAPP_THEME_MENU_H__ */
#endif /*__MMI_THEMES_APPLICATION__*/
