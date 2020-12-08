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
 *  vapp_gallery_index.h
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
 ****************************************************************************/

#ifndef __VAPP_GALLERY_PICTURE_H__
#define __VAPP_GALLERY_PICTURE_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"
#include "vapp_gallery.h"
#include "vapp_gallery_data.h"
#include "vapp_gallery_db.h"
#include "vapp_gallery_util.h"

#if defined(__MMI_VUI_COSMOS_CP__)
#include "mmi_rp_app_cosmos_global_def.h"
#endif /*defined(__MMI_VUI_COSMOS_CP__)*/

enum VappGalleryFolderListLayoutEnum
{
    DEFAULT_FONT_WHITENESS = 21,        // font color of folder list
    DEFAULT_COUNT_WHITENESS = 0xC0,     // font color of image count in folder list
    COLLAGE_NAME_COUNT_PAD = 4,         // spacing between folder name and image count
    COLLAGE_NAME_MARGIN = 2,            // margin on left/rigth side of description text area

#if defined(__MMI_MAINLCD_320X480__)
    COLUMN_COUNT = 2,
    ROW_COUNT = 3,
    COLLAGE_W = 110,
    COLLAGE_H = 82,
    COLLAGE_DESC_H = 20,
    COLLAGE_CX = 5 + COLLAGE_W / 2,
    COLLAGE_CY = 3 + COLLAGE_H / 2 ,
    COLLAGE_FONT_SIZE = 14,

#elif defined(__MMI_MAINLCD_480X800__)
    COLUMN_COUNT = 2,
    ROW_COUNT = 3,
    COLLAGE_W = 190,
    COLLAGE_H = 141,
    COLLAGE_DESC_H = 40,
    COLLAGE_CX = COLLAGE_W / 2,
    COLLAGE_CY = 66,
    COLLAGE_FONT_SIZE = 25,
#elif defined(__MMI_MAINLCD_240X320__)
    COLUMN_COUNT = 2,
    ROW_COUNT = 2,
    COLLAGE_W = 90,
    COLLAGE_H = 72,
    COLLAGE_DESC_H = 20,
    COLLAGE_CX = 5 + COLLAGE_W / 2,
    COLLAGE_CY = 3 + COLLAGE_H / 2 ,
    COLLAGE_FONT_SIZE = 13,

#elif defined(__MMI_MAINLCD_240X400__)
    COLUMN_COUNT = 2,
    ROW_COUNT = 3,
    COLLAGE_W = 90,
    COLLAGE_H = 72,
    COLLAGE_DESC_H = 20,
    COLLAGE_CX = 5 + COLLAGE_W / 2,
    COLLAGE_CY = 3 + COLLAGE_H / 2 ,
    COLLAGE_FONT_SIZE = 13,

#else
    COLUMN_COUNT = 2,
    ROW_COUNT = 4,
    COLLAGE_W = 110,
    COLLAGE_H = 82,
    COLLAGE_DESC_H = 20,
    COLLAGE_CX = 5 + COLLAGE_W / 2,
    COLLAGE_CY = 3 + COLLAGE_H / 2 ,
    COLLAGE_FONT_SIZE = 14,
#endif
};


/***************************************************************************** 
 * Class 
 *****************************************************************************/
 
// a class that draws a rounded-cornered photo.
// the photo can also have a flash-in effect.
class VappGalleryImageCell : public VfxFrame
{
public:
#if defined(__MMI_MAINLCD_320X480__)
    static const VfxS32 DEFAULT_DIM_W = 56;       // size of the entire cell
    static const VfxS32 DEFAULT_DIM_H = 57;       // size of the entire cell
    static const VfxS32 DEFAILT_THUMB_OFFSET = 3; // size of the inner thumbnail
    static const VfxS32 DEFAILT_THUMB_SIZE = 50; // size of the inner thumbnail
    static const VfxS32 DEFAILT_THUMB_WHITENESS = 226; // default bg color (same for RGB) of thumbnail

#elif defined(__MMI_MAINLCD_480X800__)
    static const VfxS32 DEFAULT_DIM_W = 87;       // size of the entire cell
    static const VfxS32 DEFAULT_DIM_H = 91;       // size of the entire cell
    static const VfxS32 DEFAILT_THUMB_OFFSET = 4; // size of the inner thumbnail
    static const VfxS32 DEFAILT_THUMB_SIZE = 79;  // size of the inner thumbnail
    static const VfxS32 DEFAILT_THUMB_WHITENESS = 226; // default bg color (same for RGB) of thumbnail

#elif defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
    static const VfxS32 DEFAULT_DIM_W = 44;       // size of the entire cell (frame.png)
    static const VfxS32 DEFAULT_DIM_H = 46;       // size of the entire cell (frame.png)
    static const VfxS32 DEFAILT_THUMB_OFFSET = 2; // size of the inner thumbnail
    static const VfxS32 DEFAILT_THUMB_SIZE = 40;  // size of the inner thumbnail
    static const VfxS32 DEFAILT_THUMB_WHITENESS = 226; // default bg color (same for RGB) of thumbnail

#else
    static const VfxS32 DEFAULT_DIM_W = 44;       // size of the entire cell (frame.png)
    static const VfxS32 DEFAULT_DIM_H = 46;       // size of the entire cell (frame.png)
    static const VfxS32 DEFAILT_THUMB_OFFSET = 2; // size of the inner thumbnail
    static const VfxS32 DEFAILT_THUMB_SIZE = 40;  // size of the inner thumbnail
    static const VfxS32 DEFAILT_THUMB_WHITENESS = 226; // default bg color (same for RGB) of thumbnail
#endif

public:
    VappGalleryImageCell();
    virtual void onInit();
    virtual void onDraw(VfxDrawContext &dc);

public:
    void setSizeAndThumbSize(const VfxSize &cellSize, const VfxSize &thumbSize);
    void setThumb(const VfxImageSrc &src);
    void setEmptyContent();     // display empty background to allow overlaying other icons
    void setDefaultIcon();      // display a default icon for empty folder
    void setRotation(const VfxFloat degree);
    void setPressed(VfxBool pressed);
    
    
protected:
    void flashIn();
    void setBorderIcon();       // display border; mutual excludes setDefaultIcon().

protected:
    VfxBool m_showDefaultIcon;
    VfxBool m_isPressed;
    VfxImageSrc m_thumbImgSrc;
};

// a collage of images that layout in a randomized fashion.
// used for "All pictures" panel
class VappGalleryImageCollage : public VfxFrame
{
public:
    static const VfxS32 MAX_IMAGE_COUNT = 5;
    static const VfxS32 PRESS_DOWN_OFFSET = 2;
    static const VfxFloat PRESS_DOWN_SCALE; 

public:
    VappGalleryImageCollage();
    virtual void onInit();
public:
    // get current active image count
    virtual VfxS32 getActiveImageCount();

    // set current active image count
    // inactive image resource are released immediately,
    // and layout changes automatically
    virtual VfxBool setActiveImageCount(VfxS32 activeCount);

    // set a specific thumbnail. note you must also call setActiveImageCount()
    // to actually show the image.
    virtual VfxBool setThumbnail(VfxS32 index, const VfxImageSrc &imgSrc);

    // set active image to 1 and display an special icon for empty collage
    virtual void showEmptyThumbnail();

    // set the collage in a pressed state
    virtual void setPressed(VfxBool pressed);

protected:
    // arrange images according to active image count
    // active image means image to be displayed
    virtual void layoutCollage();

    virtual void showWaitIcon(VfxBool bShow);

protected:
    VappGalleryImageCell *m_images[MAX_IMAGE_COUNT];
    VfxS32 m_activeImageCount;
    VcpActivityIndicator *m_waitIcon;
};

// a collage of images that layout in a randomized fashion.
// this is used in Folder List, which have a tighter layout.
class VappGalleryFolderCollage : public VappGalleryImageCollage
{
protected:
    // arrange images according to active image count
    // active image means image to be displayed
    virtual void layoutCollage();
};

class VappGalleryFolderCollageButton : public VcpImageButton
{
public:
    const static VfxS32 MAX_DISPLAY_IMAGE_COUNT;
public:
    VappGalleryFolderCollageButton();

// override
public:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

public:
    VfxBool getLabelString(VfxWString &labelStr);

    // image file count in the folder (e.g. 700 images)
    void setImageCount(VfxS32 imageCount);

    // number of thumbnails in collage
    void setThumbnailCount(VfxS32 thumbCount);
    // thumbnail image source in collage
    void setThumbnail(VfxS32 index, VfxImageSrc src);

protected:
    VappGalleryImageCollage *m_collage;
    VfxTextFrame *m_txtLabel;   // label ("Images") of the button
    VfxTextFrame *m_txtDesc;    // descript (XXX pictures) of the button
    VfxS32  m_imageCount;       // number of images, used to format m_txtDesc
};

class IVappGalleryMenuUpdatable
{
public:
    virtual VfxRect getViewRect() = 0;
    // returns VFX_TRUE if the cell requires further update or enhance
    virtual VfxBool needUpdate(
                        const VcpMenuPos &pos, // position of the cell
                        VfxFrame *frame  // the cell object
                        ) = 0;

    // update the cell content
    // returns VFX_FALSE if there is no slow action triggered, updater
    //                   should proceed to next cell directly.
    virtual VfxBool updateMenuCell(
                        const VcpMenuPos &pos, // position of the cell
                        const VfxFrame *frame, // the cel object
                        VfxBool canEnhance     // VFX_TRUE if menu can trigger an async "enhance" operation,
                                               //           e.g. start decoding video thumbnail
                                               // VFX_FALSE if menu should simply fetch a quick result and update cell
                                               //           e.g. in-memory cache or a loading icon
                        ) = 0;
};

// Update items in a base menu
// The stretagy is to to a quick refresh for one round,
// and then re-start over for a slower, high-quality update
class VappGalleryMenuUpdater : public VfxObject
{
public:
    VappGalleryMenuUpdater():
        m_updateTimer(NULL),
		m_menu(NULL),
		m_updatable(NULL),
        m_isScrolling(VFX_FALSE)
    {
    }
    
// method for updated menu to call
public:
    // set the menu that is to be updated.
    // the menu must
    // 1. based on VcpBaseMenu
    // 2. support IVappUpdatableMenu
    void setMenu(VcpBaseMenu *menu, IVappGalleryMenuUpdatable *updatable)
    {
        m_menu = menu;
        m_updatable = updatable;
    }

    void forceStartCheck()
    {
        m_updateTimer->start();
    }

    void forceStopCheck()
    {
        m_updateTimer->stop();
    }
    
    void startScroll()
    {
        m_isScrolling = VFX_TRUE;
        // no update during scrolling
        // cells should properly display
        // results if they can in FIRST_INIT
        m_updateTimer->stop();

        // invalidate the checked position, since we scrolled
        m_lastCheckedPos.invalid();
    }

    void endScroll()
    {
        m_isScrolling = VFX_FALSE;
        refreshNextVisibleCell();
        m_updateTimer->start();
    }

protected:
    virtual void onInit()
    {
        VFX_OBJ_CREATE(m_updateTimer, VfxTimer, this);
        m_updateTimer->setStartDelay(100);
        m_updateTimer->setDuration(100);
        m_updateTimer->m_signalTick.connect(this, &VappGalleryMenuUpdater::onUpdateTick);
    }

    void onUpdateTick(VfxTimer *updateTimer)
    {
        if(m_isScrolling)
        {
            return;
        }

        // stop the timer. following functions will re-start it
        // if needed
        m_updateTimer->stop();
        
        // check next cell that should be updated
        if(m_lastCheckedPos.isValid())
        {
            refreshNextVisibleCell();
        }
        else
        {
            searchCellToUpdate();
        }
    }

    void refreshNextVisibleCell()
    {
        if(NULL == m_menu)
        {
            return;
        }

        const VcpMenuRegion rgn = m_menu->getRealContentRegion();
        if(rgn.isEmpty())
        {
            return;
        }

        // see if we start a new quick search, or
        // advance to next cell
        const VcpMenuPos posToCheck = m_lastCheckedPos.isValid() ? 
                                      m_lastCheckedPos.getNextPos(m_menu->getLayout(), VFX_FALSE) :
                                      rgn.begin;
        if(!rgn.isWithin(posToCheck))
        {
            // no next cell to update.
            m_lastCheckedPos.invalid();
            // start searching for slower enhance / heavy update
            searchCellToUpdate();
            return;
        }

        // check if cell is created, if so, quick update it.
        VfxFrame *cell = m_menu->getCellIfPresent(posToCheck.group, posToCheck.pos);
        if (cell && m_updatable->needUpdate(posToCheck, cell))
        {
            // let updatable menu do a quick update
            m_updatable->updateMenuCell(posToCheck, cell, VFX_FALSE);
        }
        m_lastCheckedPos = posToCheck;
        // continue next cell to refresh
        m_updateTimer->start();
    }

    void searchCellToUpdate()
    {
        if (m_isScrolling)
            return;

        VcpMenuRegionIter itr(m_menu, m_menu->getRealContentRegion());
        VcpBaseMenuLayout *layout = m_menu->getLayout();
        while(!itr.isEnd())
        {
            const VcpMenuPos curPos = itr.next();
            if(curPos.isGroupHeader())
                continue;

            // check if cell is created
            VfxFrame *cell = m_menu->getCellIfPresent(curPos.group, curPos.pos);
            if(NULL == cell)
                continue;

            // check if cell is visible
            const VfxRect cellRect = layout->queryCellRect(curPos);
            VfxRect viewRect = m_updatable->getViewRect();
            const VfxSize intersectedSize = viewRect.intersectWith(cellRect).size;
            const VfxBool cellVisible = intersectedSize.width > 0 && intersectedSize.height > 0;
            if(!cellVisible)
                continue;

            // if the cell can be further enhanced/updated,
            // let updatable menu do a "heavy" update
            if(m_updatable->needUpdate(curPos, cell))
            {
                GALLERY_MEASURE_TIME("UNB");
                if(!m_updatable->updateMenuCell(curPos, cell, VFX_TRUE))
                {
                    // do a next scan
                    m_updateTimer->start();
                }
                // otherwise we're waiting for the slow update action to finish.
                return;
            }
        }

        // all cells searched but none of them needs to update.
        // stop the timer until view changes
        m_updateTimer->stop();
    }
    
protected:
    VfxTimer *m_updateTimer;
    VcpBaseMenu *m_menu;
    IVappGalleryMenuUpdatable *m_updatable;
    VfxBool m_isScrolling;
    VcpMenuPos m_lastCheckedPos;    // cache checked position to prevent repeatedly scans visible region
    
};

// layout for BaseMenu
class VappGalleryFolderListLayout : public VcpBaseMenuLayout
{
// Constructor / Destructor
public:
    VappGalleryFolderListLayout(VcpBaseMenu* menu) : 
        VcpBaseMenuLayout(menu),
        m_folderList(NULL)
    {
    }
    
    virtual ~VappGalleryFolderListLayout(){}

// Method
public:
    void setFolderList(VappGalleryFmgrFolderList *folderList)
    {
        m_folderList = folderList;
    }
    
// Override
public:
    virtual void onInit()
    {
        VcpBaseMenuLayout::onInit();
        m_cellWidth = m_cellHeight = 30;
        resetCache();
    }

    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }
    
    virtual VfxS32 getGroupCount()
    {
        // foler list always 1 group
        return 1;
    }
    
    virtual VfxS32 getCellCount(VfxS32 group)
    {
        if(NULL == m_folderList)
        {
            return 0;
        }
        else
        {
            return m_folderList->getTotalFileCount();
        }
    }

    virtual VfxS32 getContentLength()
    {
        // folder list support only 1 group
        return getWholeGroupHeight(0);
    }

    virtual VfxBool hasGroupHeader(VfxS32 group)
    {
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
        const VfxS32 row = pt.y / m_cellHeight;
        const VfxS32 col = VFX_MAX(pt.x - 1, 0) / m_cellWidth;
        p.pos = row * COLUMN_COUNT + col;
        if (p.pos >= getCellCount(p.group))
        {
            p.pos = getCellCount(p.group) - 1;
        }
        return p;
    }    

    // Return a cell rect
    virtual VfxRect queryCellRect(VcpMenuPos pos)
    {
        // there is only 1 group supported in folder list
        VFX_ASSERT(pos.group == 0);

        // support no group header
        if(pos.pos < -1)
            return VfxRect(-1, -1, 0, 0);

        if(pos.pos >= getCellCount(pos.group))
            return VfxRect(-1, -1, 0, 0);

        VfxS32 row = (pos.pos / COLUMN_COUNT) * m_cellHeight;
        VfxS32 col = (pos.pos % COLUMN_COUNT) * m_cellWidth;
                
        return VfxRect(col, row, m_cellWidth, m_cellHeight);
    }

    virtual void getPreferFocusMargin(VfxS32 margin[4])
    {
        margin[0] = m_cellHeight;
        margin[1] = m_cellHeight;
        margin[2] = m_cellHeight;
        margin[3] = m_cellHeight;
    }

    virtual void onViewChanged()
    {
        resetCache();
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
            // keypad, so move to visible region
            setFocusItem(p, VFX_TRUE);
            return VFX_TRUE;
        }

        VcpMenuPos p;
        if (dir == NAV_DIR_UP)
        {
            p = getFocusItem();

            VfxS32 c = p.pos % COLUMN_COUNT, r = p.pos / COLUMN_COUNT;
            VfxS32 group_row = (getCellCount(p.group)-1) / COLUMN_COUNT;

            if (r > 0)
            {
                r --;
                p.pos = r * COLUMN_COUNT + c;
            }
            else
            {
                if (p.group <= 0)
                {
                    p.group = 0;
                    p.pos = 0;
                }
                else
                {
                    p.group--;

                    VfxS32 n_group_row = getCellCount(p.group) / COLUMN_COUNT;

                    p.pos = n_group_row * COLUMN_COUNT + c;
                    if (p.pos >= getCellCount(p.group))
                    {
                        p.pos = getCellCount(p.group) - 1;
                    }
                }

            }
        }
        if (dir == NAV_DIR_DOWN)
        {
            p = getFocusItem();

            VfxS32 c = p.pos % COLUMN_COUNT, r = p.pos / COLUMN_COUNT;
            VfxS32 group_row = (getCellCount(p.group) - 1) / COLUMN_COUNT;

            if (r >= group_row)
            {
                p.group ++;
                if (p.group >= getGroupCount())
                {
                    p.group = getGroupCount() - 1;
                    p.pos = getCellCount(p.group) - 1;
                }
                else
                {
                    p.pos = c;
                    if (p.pos >= getCellCount(p.group))
                    {
                        p.pos = getCellCount(p.group) - 1;
                    }
                }
            }
            else
            {
                p.pos = (r + 1) * COLUMN_COUNT + c;
                if (p.pos >= getCellCount(p.group))
                {
                    p.pos = getCellCount(p.group) - 1;
                }
            }
        }
        if (dir == NAV_DIR_LEFT)
        {
            p = getFocusItem().getPrevPos(this, VFX_FALSE);
        }
        if (dir == NAV_DIR_RIGHT)
        {
            p = getFocusItem().getNextPos(this, VFX_FALSE);
        }
        if (p)
        {
            // keypad, so move to visible region
            setFocusItem(p, VFX_TRUE);
            return VFX_TRUE;
        }
        return VFX_FALSE;
    }

// workaround getViewPos & getViewSize non-public issue
public:
    VfxRect getViewRect()
    {
        const VfxPoint viewPos = getViewPos();
        const VfxSize viewSize = getViewSize();
        return VfxRect(viewPos, viewSize);
    }

// Variable
protected:
    VfxS32 m_cellHeight;
    VfxS32 m_cellWidth;
    VfxS32 m_groupStartPt[4];
    VappGalleryFmgrFolderList *m_folderList;
    
//Implementation
protected:
    VfxS32 getWholeGroupHeight(VfxS32 group)
    {
        const VfxS32 row = (getCellCount(group) + COLUMN_COUNT - 1) / COLUMN_COUNT;
        return row * m_cellHeight;
    }

    void resetCache()
    {
        m_cellWidth = getViewSize().width / COLUMN_COUNT;
        m_cellHeight = getViewSize().height / ROW_COUNT;
        m_groupStartPt[0] = 0;

        for (VfxS32 i = 1; i < 4; i++)
        {
            m_groupStartPt[i] = m_groupStartPt[i - 1] + getWholeGroupHeight(i - 1) ;
        }    
    }
};

class VappGalleryFolderListView : public VcpBaseMenu, public IVappGalleryMenuUpdatable
{
    class VappGalleryFolderCell : public VfxControl
    {
        VfxTextFrame     *m_textFrame;  // folder name
        VfxTextFrame     *m_countFrame; // image count in folder
        VfxFloatTimeline *m_timeline1;
        VfxBool          m_highlight;
        VappGalleryFolderCollage        *m_collage;
        VfxS32           m_group, m_pos;
        VfxTimer         *m_withdrawTimer;
        VfxRect          m_originalBounds;      // backup of bounds to detect bounds change

    public:
        VappGalleryFolderCell():
            m_textFrame(NULL),
            m_countFrame(NULL),
            m_timeline1(NULL),
            m_collage(NULL),
            m_withdrawTimer(NULL)
        {
        }

        VappGalleryFolderListView* getMenu()
        {
            if (getParentFrame() && getParentFrame()->getParentFrame())
                return (VappGalleryFolderListView*) getParentFrame()->getParentFrame();
            return NULL;
        }

        VcpMenuPos getMenuPos()
        {
            VappGalleryFolderListView* pMenu = getMenu();

            VcpMenuRegionIter itr(pMenu, pMenu->getRealContentRegion());
            while(!itr.isEnd())
            {
                VcpMenuPos p = itr.next();
                
                if (p.isGroupHeader())
                {
                    if (pMenu->getHeaderIfPresent(p.group) == this)
                        return p;
                }
                else
                {
                    if (pMenu->getCellIfPresent(p.group, p.pos) == this)
                        return p;
                }
            }
            // The menu item is not in menu anymore, maybe remove from menu
            return VcpMenuPos();
        }

        virtual void onInit()
        {
            VfxControl::onInit();

            sendToBack();
            setOpacity(0);
            setAnchor(VfxFPoint(0.5, 0.5));
            setIsCached(VFX_TRUE);
                        
            m_highlight = VFX_FALSE;

            m_collage = NULL;
            VFX_OBJ_CREATE(m_collage, VappGalleryFolderCollage, this);

            // folder name
            VFX_OBJ_CREATE(m_textFrame, VfxTextFrame, this);
            m_textFrame->setColor(VFX_COLOR_RES(COR_ID_VAPP_GALLERY_PIC_FOLDER_LIST_DEFAULT_FONT_WHITENESS));
            m_textFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
            m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            m_textFrame->setAutoFontSize(VFX_FALSE);
            m_textFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(COLLAGE_FONT_SIZE)));

            // image count in folder
            VFX_OBJ_CREATE(m_countFrame, VfxTextFrame, this);
            m_countFrame->setColor(VFX_COLOR_RES(COR_ID_VAPP_GALLERY_PIC_FOLDER_LIST_DEFAULT_COUNT_WHITENESS));
            m_countFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
            m_countFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_NONE);
            m_countFrame->setAutoFontSize(VFX_FALSE);
            m_countFrame->setAutoResized(VFX_TRUE);
            m_countFrame->setFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(COLLAGE_FONT_SIZE)));

            VFX_OBJ_CREATE(m_timeline1, VfxFloatTimeline, this);
            m_timeline1->setTarget(this);
            m_timeline1->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
            m_timeline1->setDurationTime(250);
            
            VFX_OBJ_CREATE(m_withdrawTimer, VfxTimer, this);
            m_withdrawTimer->setStartDelay(300);
            m_withdrawTimer->m_signalTick.connect(this, &VappGalleryFolderCell::onWithdrawTimerCB);            

            layoutElements(getRect());
            setAutoAnimate(VFX_TRUE);
        }
        virtual void onDeinit()
        {
            m_timeline1->stop();
            VfxControl::onDeinit();
        }
        void setHighlight(VfxBool isHighLight, VfxBool isAnim)
        {
            m_highlight = isHighLight;
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(!isAnim);

            m_collage->setPressed(m_highlight);

            VfxAutoAnimate::commit();

            checkUpdate();
        }

        virtual void onUpdate()
        {
            return;
        }

        void enter(const VfxRect& r, VfxBool animation, VfxS32 delay)
        {
            if (animation)
            {
                // set the position without animation
                // But timeline will not be affect
                updatePos(r, VFX_FALSE);
                m_timeline1->setStartTime(delay);
                m_timeline1->setToValue(1.0f);
                m_timeline1->setFromValue(0.0f);
                m_timeline1->setToValue(1.0f);
                m_timeline1->start();
            }
            else
            {
                updatePos(r, VFX_FALSE);
                setOpacity(1.0f);
            }
        }

        void onWithdrawTimerCB(VfxTimer *source)
        {
            VappGalleryFolderCell* _this = this;
            VFX_OBJ_CLOSE(_this);
        }

        void withdraw()
        {
            VfxPoint pt = getPos();
            pt.x += 300;
            setPos(pt);
            setOpacity(0);
            m_withdrawTimer->start();
        }

        void leave(const VfxRect& r)
        {
            m_timeline1->stop();
            m_timeline1->setStartTime(0);
            m_timeline1->setFromValue(1.0f);
            m_timeline1->setToValue(0.0f);
            m_timeline1->start();
        }

        void updatePos(const VfxRect& r, VfxBool isAnim)
        {
            VfxAutoAnimate::begin();
            VfxAutoAnimate::setDisable(!isAnim);

            setPos(VfxPoint(r.getMidX(), r.getMidY()));
            setBounds(VfxRect(VfxPoint(0, 0), r.size));
            layoutElements(r);
            VfxAutoAnimate::commit();
        }
        void layoutElements(const VfxRect &value)
        {
            if(NULL == m_textFrame || 
               NULL == m_countFrame ||
               NULL == m_collage)
            {
                return;
            }

            const VfxSize &s = value.size;
            // desc = name + (count)
            const VfxFontDesc &font = m_textFrame->getFont();
            const VfxS32 countWidth = font.measureStr(m_countFrame->getString()).width;
            const VfxS32 nameWidth = vfxMin(font.measureStr(m_textFrame->getString()).width,
                                            value.size.width - countWidth - COLLAGE_NAME_COUNT_PAD - 2 * COLLAGE_NAME_MARGIN);
            const VfxS32 descWidth = countWidth + COLLAGE_NAME_COUNT_PAD + nameWidth + 2 * COLLAGE_NAME_MARGIN;
            m_textFrame->setSize(nameWidth,
                                 COLLAGE_DESC_H);
            const VfxS32 left = (value.size.width - descWidth) / 2;
            m_textFrame->setPos(VfxPoint(left, 
                                s.height - COLLAGE_DESC_H));
            m_countFrame->setPos(VfxPoint(left + nameWidth + COLLAGE_NAME_COUNT_PAD,
                                s.height - COLLAGE_DESC_H));

            m_collage->setPos(s.width / 2, (s.height - COLLAGE_DESC_H) / 2);
            m_collage->setSize(getSize().width, COLLAGE_H);
            // force relayout if size change
            if(m_originalBounds.size != value.size)
            {
                m_collage->setActiveImageCount(m_collage->getActiveImageCount());
            }
            m_originalBounds = value;
        }
        virtual void setBounds(const VfxRect &value)
        {
            VfxControl::setBounds(value);
            layoutElements(value);
        }
        void setCaption(const VfxWString& folderName, const VfxS32 count)
        {
            if(NULL == m_textFrame || 
               NULL == m_countFrame)
            {
                return;
            }
            
            VfxWString countStr;
            if(count >= 0)
            {
                countStr.format("(%d)", count);
                m_countFrame->setString(countStr);
                m_countFrame->setAutoResized(VFX_TRUE);
            }
            else
            {
                VfxWString emptyStr;
                emptyStr.setEmpty();
                m_countFrame->setString(emptyStr);
            }
            
            m_textFrame->setString(folderName);
            m_textFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
            layoutElements(getBounds());
        }
        void setTextVisible(VfxBool visible)
        {
            m_textFrame->setHidden(!visible);
        }
        void setThumbnailCount(VfxS32 count)
        {
            if(m_collage)
            {
                m_collage->setActiveImageCount(count);
            }
        }
        void setThumbnail(VfxS32 index, VfxImageSrc thumbSrc)
        {
            if(m_collage)
            {
                m_collage->setThumbnail(index, thumbSrc);
            }
        }
        void setEmptyIcon()
        {
            if(m_collage)
            {
                m_collage->showEmptyThumbnail();
            }
        }
        VfxBool isNeedUpdate()
        {
            return m_collage->getActiveImageCount() <= 0;
        }
    };

// Constructor / Destructor
public:
    VappGalleryFolderListView() : 
        m_folderList(NULL),
        m_imageScanner(NULL),
        m_folderThumbDecoder(NULL),
        m_decoderOutput(NULL),
        m_folderInfoCache(NULL),
        m_fileFilter(NULL),
        m_updater(NULL),
        m_decoding(VFX_FALSE),       
        m_forceNoUpdate(VFX_FALSE),
        m_pDB(NULL),
        m_decoderTempBuf(NULL)
    {
    }
    virtual ~VappGalleryFolderListView(){}

// Override
public:
    virtual void onInit()
    {
        m_isSupportTransition = VFX_TRUE;
        m_firstPos = 0;

        // create in-memory cache
        VFX_OBJ_CREATE(m_folderInfoCache, FolderInfoCache, this);
        

        // connect image scanner event
        // note that image scanner is created upon request.
        m_signalImageListReady.connect(this, &VappGalleryFolderListView::onImageScannerReady);

        // call this after create VappGalleryFmgrFolderList,
        // since layout is created in onInit().
        VcpBaseMenu::onInit();

        // updater relies on VcpBaseMenu
        VFX_OBJ_CREATE(m_updater, VappGalleryMenuUpdater, this);
        m_updater->setMenu(this, this);
    }

    virtual void onDeinit()
    {
        // thumb decoder must be de-init first,
        // since it may accessing cache
        VFX_OBJ_CLOSE(m_folderThumbDecoder);
        VFX_OBJ_CLOSE(m_decoderOutput);
        VFX_OBJ_CLOSE(m_imageScanner);

        // Close all cell in the screen
        // TODO: this is workaround, VcpBaseMenu will fix this
        m_cache.clear();
        
        VcpBaseMenu::onDeinit();
    }

    virtual VcpBaseMenuLayout* createLayout()
    {
        VappGalleryFolderListLayout* layout = NULL;
        VFX_OBJ_CREATE_EX(layout, VappGalleryFolderListLayout, this, (this));
        layout->setFolderList(m_folderList);
        return layout;
    }

    virtual void onUpdate()
    {
        VcpBaseMenu::onUpdate();
        if(m_updater)
        {
            // kick off menu refresh
            m_updater->forceStartCheck();
        }
    }

    virtual VfxFrame* createGroupHeader(VfxS32 group)
    {
        return NULL;
    }

    virtual VfxFrame* createCell(VfxS32 group, VfxS32 pos)
    {
        VappGalleryFolderCell* item;
        VFX_OBJ_CREATE(item, VappGalleryFolderCell, this);
            
        VfxWString cellCaption;
        if(m_folderList)
        {
            if(getItemCaption(VcpMenuPos(group, pos), cellCaption))
            {
                item->setCaption(cellCaption, -1);
            }
        }
        item->setTextVisible(VFX_TRUE);
        item->setHighlight(VFX_FALSE, VFX_FALSE);

        const VcpMenuPos menuPos(group, pos);
        if (getLayout()->getFocusItem() == menuPos)
        {
            item->setHighlight(VFX_TRUE, VFX_TRUE);
        }

        return item;
    }
    
    virtual void onCloseGroupHeader(VfxS32 group, VfxFrame* groupFrame)
    {
        VFX_OBJ_CLOSE(groupFrame);
    }
    
    virtual void onCloseCell(VfxS32 group, VfxS32 pos, VfxFrame* cellFrame)
    {
        if(m_folderInfoCache)
        {
            m_folderInfoCache->unlockCache(convertItemIdFromMenuPos(VcpMenuPos(group, pos)));
        }
        VFX_OBJ_CLOSE(cellFrame);
    }
    
    virtual void onUpdateGroupHeader(const VfxRect &rect, VfxS32 group, VfxFrame* header, VfxU32 flag)
    {
        return;
    }

    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem)
    {
        if (previousFocusItem.isValid() && !previousFocusItem.isGroupHeader())
        {
            VappGalleryFolderCell* item = (VappGalleryFolderCell*) getCellIfPresent(previousFocusItem.group, previousFocusItem.pos);
            if (item)
            {
                item->setHighlight(VFX_FALSE, VFX_TRUE);
            }
        }
        if (focusItem.isValid() && !focusItem.isGroupHeader())
        {
            VappGalleryFolderCell* item = (VappGalleryFolderCell*) getCellIfPresent(focusItem.group, focusItem.pos);
            if (item)
            {
                item->setHighlight(VFX_TRUE, VFX_TRUE);
            }
        }
    }

    virtual void onBeforeUpdate(
        const VcpMenuRegion& currentRegion,
        const VcpMenuRegion& targetRegion
    )
    {
        m_firstPos = currentRegion.begin.pos;
    }

    virtual void onUpdateCell(const VfxRect &rect, VfxS32 group, VfxS32 pos, VfxFrame* cell, VfxU32 flag)
    {
        VappGalleryFolderCell* item = (VappGalleryFolderCell*) cell;

        VfxRect r = rect;
        r.origin.x += 1;
        r.origin.y += 1;
        r.size.width -= 2;
        r.size.height -= 2;

        if (flag & VCP_CELL_FLAG_FIRSTINIT)
        {
            if (flag & VCP_CELL_FLAG_OPENING)
            {
                item->enter(r, VFX_TRUE, (pos - m_firstPos) * 50);
            }
            else
            {
                item->enter(r, VFX_FALSE, 0);
            }
            // show thumbnail if it is already in cache.
            setCellThumbByCache(item, VcpMenuPos(group, pos));
        }
        else if (flag & VCP_CELL_FLAG_CLOSING)
        {
            item->leave(r);
        }
        else if (flag & VCP_CELL_FLAG_FORCESET)
        {
            item->updatePos(r, VFX_FALSE);
        }
        else
        {
            item->updatePos(r, VFX_TRUE);
        }
    }

    virtual void onTapGroupHeader(VfxS32 group, VfxFrame* groupObject)
    {
        return;
    }
    
    virtual void onTapCell(VfxS32 group, VfxS32 pos, VfxFrame* cell)
    {
        //VappGalleryFolderCell* item = (VappGalleryFolderCell*) cell;
        m_signalTapped.postEmit(this, VcpMenuPos(group, pos));
    }

    virtual void onTouchCell(
        VcpMenuPos          cellPos,     // [IN] The cell position
        CellTouchTypeEnum   touchType,   // [IN] The touch type
        VfxPoint            pt,          // [IN] The pen position
        VfxFrame            *cell        // [IN] The cell object
    )
    {
        //VappGalleryFolderCell* item = (VappGalleryFolderCell*) cell;
        switch(touchType)
        {
        case TouchDown:
            // do not move into visible region, since this is a touch event,
            // it's strange to move the cell by itself.
            getLayout()->setFocusItem(cellPos, VFX_FALSE);
            break;
        case TouchUp:
            getLayout()->clearFocusItem();
            break;
        }
    }

    virtual void onDragStart()
    {
        VFX_TRACE(("onDragStart\n"));
        
        VcpBaseMenu::onDragStart();
        
        // note: we don't stop decoding jobs
        // when start scrolling, since
        // user may be just scroll a little bit.
        
        // notify updater stop issue decoding jobs
        m_updater->startScroll();
    }

    virtual void onDragEnd()
    {
        VFX_TRACE(("onDragEnd\n"));
        
        VcpBaseMenu::onDragEnd();
        VFX_TRACE(("Real: (%d, %d), Bounds:(%d, %d)\n", 
            m_view->forceGetBounds().origin.x, 
            m_view->forceGetBounds().origin.y, 
            m_view->getBounds().origin.x, 
            m_view->getBounds().origin.y
        ));

        m_updater->endScroll();
    }

    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset)
    {
        VFX_TRACE(("onDrag: %d %d\n", xoffset, yoffset));
        getLayout()->clearFocusItem();
    }

    void startDragCell(VcpMenuPos pos, VfxFrame* dragCell)
    {
        getLayout()->clearFocusItem();

        VfxS32     minDistance = 1000 * 1000 + 1000 * 1000; // Set a max distance
        VcpMenuPos pointCell;

        VfxS32 cx = dragCell->getPos().x + VfxS32(dragCell->getBounds().size.width * (0.5f - dragCell->getAnchor().x));
        VfxS32 cy = dragCell->getPos().y + VfxS32(dragCell->getBounds().size.height * (0.5f - dragCell->getAnchor().y));

        VcpMenuRegionIter itr(this, getRealContentRegion());
        while(!itr.isEnd())
        {
            VcpMenuPos p = itr.next();

            if (!p.isGroupHeader())
            {
                VfxRect r = getLayout()->queryCellRect(p);                
                VfxS32 x = r.getMidX();
                VfxS32 y = r.getMidY();
                VfxS32 distance = VFX_ABS(cx - x) * VFX_ABS(cx - x) + VFX_ABS(cy - y) * VFX_ABS(cy - y);

                if (minDistance > distance)
                {
                    minDistance = distance;
                    pointCell = p;
                }
            }
        }
        if (pointCell.isValid() && pointCell != pos)
        {
            swapCell(pointCell, pos);
            makeVisible(pointCell);
            makeVisible(pos);
        }
    }

    void endDragCell(VcpMenuPos pos, VfxFrame* dragCell)
    {
        updateLayout();
    }

    virtual VfxBool IsSupportTransition()
    {
        return m_isSupportTransition;
    }

    virtual VfxBool onKeyInput(VfxKeyEvent &event)
    {
        if(VFX_KEY_CODE_ARROW_UP == event.keyCode|| VFX_KEY_CODE_ARROW_DOWN == event.keyCode) 
        {
            if(VFX_KEY_EVENT_TYPE_DOWN == event.type || VFX_KEY_EVENT_TYPE_REPEAT == event.type)
            {
                // find the reference point for next view
                const VfxRect currentView = getViewBounds();            
                VfxPoint p = VfxPoint(0, currentView.getY() + currentView.getHeight());
                if (event.keyCode == VFX_KEY_CODE_ARROW_UP) 
                {
                    p.y = currentView.getY();
                }

                 // calculate the top-left point of next view
                VappGalleryFolderListLayout* layout = (VappGalleryFolderListLayout*)getLayout();
                const VcpMenuPos   pos = layout->getCellByPos(p);
                if(-1 == pos.group)
                {
                    // do nothing to avoid loop menu
                    return VFX_TRUE;
                }                
                const VfxRect cellRect = layout->queryCellRect(pos);
                VfxS32 yTopLeft = cellRect.getY();
                if (event.keyCode == VFX_KEY_CODE_ARROW_UP)
                {
                    yTopLeft = cellRect.getY() + cellRect.getHeight() - currentView.getHeight();
                }
                
                VfxRect nextView = VfxRect(currentView.getX(), yTopLeft, currentView.getWidth(), currentView.getHeight());
                makeVisible(nextView, VFX_TRUE);

                return VFX_TRUE;
            }
        }
        //return VcpBaseMenu::onKeyInput(event);
        return VFX_TRUE;
    }
// support updatable
public:
    virtual VfxRect getViewRect()
    {
        VappGalleryFolderListLayout *layout = (VappGalleryFolderListLayout*)getLayout();
        return layout->getViewRect();
    }

    // returns VFX_TRUE if the cell requires further update or enhance
    virtual VfxBool needUpdate(
                        const VcpMenuPos &pos, // position of the cell
                        VfxFrame *frame)
    {
        // it must be a folder cell.
        VappGalleryFolderCell *folderCell = (VappGalleryFolderCell*)(frame);
        return folderCell->isNeedUpdate();
    }

    // update the cell content
    virtual VfxBool updateMenuCell(
                        const VcpMenuPos &pos, // position of the cell
                        const VfxFrame *frame, // the cel object
                        VfxBool canEnhance)
    {
        if(m_decoding || m_forceNoUpdate)
        {
            return VFX_TRUE;
        }
        if(canEnhance && !m_decoding)
        {
            m_decoding = VFX_TRUE;
            m_decodingPos = pos;
            VfxWString path;
            m_folderList->getPathName(pos, path);

            VFX_OBJ_CLOSE(m_folderThumbDecoder);
            VFX_OBJ_CLOSE(m_decoderOutput);
            
            if(m_imageScanner)
            {
                VFX_OBJ_CLOSE(m_imageScanner);
                m_imageScanner = NULL;
            }
            
            VFX_OBJ_CREATE(m_imageScanner, VappGalleryFmgrImageList, this);
            m_imageScanner->configFolder(path, &m_signalImageListReady);
            if(m_fileFilter)
            {
                m_imageScanner->configFileTypeLimit(m_fileFilter);
            }
            m_imageScanner->prepare();

            return VFX_TRUE;
        }
        return VFX_FALSE;
    }

    void onImageScannerReady(VappGalleryPrepareResult prepareResult)
    {
        VappGalleryFolderCell *cell = (VappGalleryFolderCell*)getCellIfPresent(m_decodingPos.group, m_decodingPos.pos);
        if(cell && m_folderList && m_imageScanner)
        {
            // folder count retrieved, set caption of folder
            VfxWString folderName;
            const VfxS32 imageCount = m_imageScanner->getTotalFileCount();
            m_folderList->getFileName(m_decodingPos, folderName);
            cell->setCaption(folderName, imageCount);
            
            // start decoding thumbnail
            VFX_OBJ_CLOSE(m_folderThumbDecoder);
            VFX_OBJ_CLOSE(m_decoderOutput);
            
            // check empty folder case
            if(0 >= imageCount)
            {
                cell->setEmptyIcon();
                m_decoding = VFX_FALSE;
            }
            else
            {
                VFX_OBJ_CREATE(m_folderThumbDecoder, VappGalleryFolderThumbnailDecoder, this);
                VFX_OBJ_CREATE(m_decoderOutput, VappGalleryMyPictureFolderThumbnailOutput, this);
                m_folderThumbDecoder->getDecodeSignal()->connect(this, &VappGalleryFolderListView::onFolderThumbDecoded);                
                // lock in-memory cache for decoding
                VappGalleryFolderInfoCacheItem *pItem = m_folderInfoCache->lockCache(convertItemIdFromMenuPos(m_decodingPos));
                m_decoderOutput->config(pItem);
                m_folderThumbDecoder->config(m_decoderOutput, m_imageScanner, m_pDB.get(), m_decoderTempBuf);
                m_folderThumbDecoder->start();
            }            
        }
        m_updater->forceStartCheck();
    }

    void onFolderThumbDecoded(VappGalleryFolderThumbnailDecoder *source, VappGalleryDecodeResult result)
    {
        if(NULL == m_folderInfoCache)
        {
            return;
        }
        
        // the decoded result is stored in a locked cache item,
        // we must unlock it if we don't assign it to a cell
        VfxBool shouldKeepLock = VFX_FALSE;
        do
        {
            VappGalleryFolderCell *cell = (VappGalleryFolderCell*)getCellIfPresent(m_decodingPos.group, m_decodingPos.pos);
            if(NULL == cell)
                break;

            if(OK != result)
            {
                // we need to update the cell so that it is "marked empty/error"
                // otherwise it'll be updated again            
                cell->setEmptyIcon();
                break;
            }

            setCellThumbByCache(cell, m_decodingPos);
            shouldKeepLock = VFX_TRUE;
        }while(0);


        if(!shouldKeepLock)
        {
            m_folderInfoCache->unlockCache(convertItemIdFromMenuPos(m_decodingPos));
        }
        
        // resume updating the list view
        m_decoding = VFX_FALSE;
        m_updater->forceStartCheck();
    }

    void setCellThumbByCache(VappGalleryFolderCell *cell, const VcpMenuPos pos)
    {
        if(NULL == cell || !pos.isValid() || NULL == m_folderInfoCache)
        {
            return;
        }
        // check the cache does indeed exist,
        // then set the image buffer to the collage thumbnails.
        VappGalleryFolderInfoCacheItem *pItem = m_folderInfoCache->lockCacheIfPresent(convertItemIdFromMenuPos(pos));
        if(NULL == pItem)
        {
            return;
        }

        // check empty case.
        if(0 == pItem->m_thumbCount)
        {
            cell->setEmptyIcon();
        }
        else
        {
            for(VfxU32 i = 0 ; i < pItem->m_thumbCount; ++i)
            {
                VfxImageSrc src;
                src.setImageBuffer(pItem->getImageBuffer(i));
                cell->setThumbnail(i, src);
            }
            cell->setThumbnailCount(pItem->m_thumbCount);
            VfxWString cellCaption = VFX_WSTR_EMPTY;
            if(getItemCaption(pos, cellCaption))
            {
                cell->setCaption(cellCaption, pItem->m_fileCount);
            }
        }
    }

    void setCellTextVisible(VfxBool visible)
    {
        VcpMenuRegionIter itr(this, getRealContentRegion());
        while(!itr.isEnd())
        {
            VcpMenuPos p = itr.next();
            if(!p.isGroupHeader())
            {
                VappGalleryFolderCell* cell = (VappGalleryFolderCell*)getCellIfPresent(p.group, p.pos);
                if (cell)
                {
                    cell->setTextVisible(visible);
                }
            }
        }
    }

    void setFolderList(VappGalleryFmgrFolderList *folderList)
    {
        m_folderList = folderList;
        VFX_ASSERT(m_folderList->isPrepared());
        if(getLayout())
        {
            VappGalleryFolderListLayout *layout = (VappGalleryFolderListLayout*)getLayout();
            layout->setFolderList(m_folderList);
            updateLayout();
        }
    }

    void setFileFilter(const FMGR_FILTER *filter)
    {
        m_fileFilter = filter;
    }

    VfxBool getItemCaption(
                const VcpMenuPos &pos,  // [IN] position of the item
                VfxWString &caption     // [OUT] caption of the item
                )
    {
        if(NULL == m_folderList)
        {
            return VFX_FALSE;
        }
        if(OK == m_folderList->getFileName(pos, caption))
        {
            return VFX_TRUE;
        }

        // faile case
        caption.setNull();
        return VFX_FALSE;
    }
    

    VfxBool getItemPath(
                const VcpMenuPos &pos,  // [IN] position of the item
                VfxWString &folderPath  // [OUT] full path to the folder item
                )
    {
        if(NULL == m_folderList)
        {
            return VFX_FALSE;
        }
        if(OK == m_folderList->getPathName(pos, folderPath))
        {
            return VFX_TRUE;
        }

        // faile case
        folderPath.setNull();
        return VFX_FALSE;
    }

    // stops all background update activity
    void stopUpdate()
    {

        if(m_folderThumbDecoder)
        {
            m_folderThumbDecoder->cancel();
        }

        if(m_imageScanner)
        {
            m_imageScanner->stop();
        }

        m_decoding = VFX_FALSE;
    }

    void setForceNoUpdate(VfxBool noUpdate)
    {
        m_forceNoUpdate = noUpdate;
    }
    
public:
    // config DB to speed respond time
    void configDB(VappGalleryDB *pDB, U8* decoderTempBuf)
    {
        m_pDB = pDB;
        m_decoderTempBuf = decoderTempBuf;
    }
    
public:
    VfxSignal2<VfxObject*, VcpMenuPos> m_signalTapped;
    
// type
protected:
    typedef VappGalleryCache<VappGalleryFolderInfoCacheItem> FolderInfoCache;
// Variable
protected:
    VfxS32  m_firstPos;
    VfxBool m_isSupportTransition;

    // folder list source folder scanning
    VappGalleryFmgrFolderList *m_folderList;
    
    // for scan images in folders.
    // scan only 1 folder at a time.
    VappGalleryFmgrImageList *m_imageScanner;
    VappGalleryFolderThumbnailDecoder *m_folderThumbDecoder;
    VappGalleryMyPictureFolderThumbnailOutput *m_decoderOutput;
    FolderInfoCache *m_folderInfoCache;
    IVappGalleryMediaList::ListEvent m_signalImageListReady;
    const FMGR_FILTER *m_fileFilter;

    // for cell update logic
    VappGalleryMenuUpdater *m_updater;
    VfxBool m_decoding;
    VfxBool m_forceNoUpdate;        // VFX_TRUE, then perform no cell update (file scan/decode)
    VcpMenuPos m_decodingPos;
    
    VfxWeakPtr<VappGalleryDB> m_pDB;
    U8* m_decoderTempBuf;
};


class VappGalleryPicturePage : public VappGalleryPage
{
    VFX_DECLARE_CLASS(VappGalleryPicturePage);
// Override
public:
    VappGalleryPicturePage();
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEntered();
    virtual void onUpdate();
    virtual void onExit(VfxBool isBackward);
    virtual void onExited2();

// Method
public:
    // create a thumbnail list page
    // showing given folder, and notify
    // parent screen to show it.
    void gotoFolderThumbnailPage(const VfxWString &folder, const VfxWString &caption);

protected:
    // retrieves root folder to scan sub-folders and images.
    // based on settings of storage. (e.g. Phone/Card)
    void getRootFolder(VfxWString &path, 
                       const VappGalleryFmgrDefaultFolder::DEFAULT_FOLDER_TYPE type = VappGalleryFmgrDefaultFolder::MY_PICTURE);

    // initializes UI by scanning medias in folder
    void startRefreshUI();

    // create the "Images" collage button
    void createImagesButton();

    // create the folder list view
    void createFolderListView();

protected:
    // image files in Images folder has scan complete
    void onImageFileListReady(VappGalleryPrepareResult prepareResult);

    // image files in recieved folder has scan complete
    void onReceivedImageFileListReady(VappGalleryPrepareResult prepareResult);

    // folders in Images folder has scan complete
    void onFolderListReady(VappGalleryPrepareResult prepareResult);

    void onMyPicturesThumbDecoded(VappGalleryFolderThumbnailDecoder *source, VappGalleryDecodeResult result);

    // user taps images button
    void onImageFolderBtnClicked(VfxObject* btn, VfxId id);

    // user taps some folder item in folder list view
    void onFolderTapped(VfxObject *source, VcpMenuPos pos);
        
    // create DB and init working memory for decoder
    void setupDB();

    // destory DB and working memory
    void destroyDB();

private:
    VappGalleryFmgrImageList *m_imageFileList;
    VappGalleryFmgrFolderList *m_folderList;
    VappGalleryFmgrImageList *m_receivedImageFileList;
    IVappGalleryMediaList::ListEvent m_signalFolderListReady;
    IVappGalleryMediaList::ListEvent m_signalImageFileListReady;
    IVappGalleryMediaList::ListEvent m_signalReceivedImageFileListReady;

    // Folder list view
    VfxFrame *m_folderViewPanel;
    VappGalleryFolderListView *m_folderView;
    VcpBaseMenuViewState m_viewState; // restore folder view state after re-enter the page

    // "Images" button (My Picture button) data are hosted by page itself
    VappGalleryFolderCollageButton *m_imageFolderBtn;    
    VappGalleryFolderThumbnailDecoder *m_folderThumbDecoder;
    VappGalleryFolderInfoCacheItem *m_thumbnailData;
    VappGalleryMyPictureFolderThumbnailOutput *m_decoderOutput;

    VappGalleryDB *m_pDB;
    VfxU8 *m_decoderWorkingBuf;
};



#endif /* __VAPP_GALLERY_INDEX_H__ */

