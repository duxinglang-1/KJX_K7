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
 *  vapp_cube_imgview.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Cube Image View Header File
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_3D_CUBE_APP_IMGVIEW_H__
#define __VAPP_3D_CUBE_APP_IMGVIEW_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/

/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum
{
    MMI_VAPP_CUBE_IMGVIEW_SORT_STATE_IDLE = 0,
    MMI_VAPP_CUBE_IMGVIEW_SORT_STATE_DOING,
    MMI_VAPP_CUBE_IMGVIEW_SORT_STATE_OVER,
        
    MMI_VAPP_CUBE_IMGVIEW_SORT_STATE_ALL
} mmi_vapp_cube_imgview_sort_state_enum;

typedef enum
{
    MMI_VAPP_CUBE_IMGVIEW_APP_MODE_UNKNOWN = 0,
    MMI_VAPP_CUBE_IMGVIEW_APP_MODE_NAVIGATION,
    MMI_VAPP_CUBE_IMGVIEW_APP_MODE_VIEW,
    MMI_VAPP_CUBE_IMGVIEW_APP_MODE_TURN_TO_BACK,
    MMI_VAPP_CUBE_IMGVIEW_APP_MODE_TURN_TO_FRONT,

    MMI_VAPP_CUBE_IMGVIEW_APP_MODE_ALL
} mmi_vapp_cube_imgview_app_mode_enum;

typedef enum 
{
	MMI_VAPP_CUBE_IMGVIEW_STATE_INITED_UNKNOWN = 0,
    MMI_VAPP_CUBE_IMGVIEW_STATE_INITED,
    MMI_VAPP_CUBE_IMGVIEW_STATE_DEINITED,

    MMI_VAPP_CUBE_IMGVIEW_STATE_ALL
} mmi_vapp_cube_imgview_state_enum;

typedef enum 
{
    MMI_VAPP_CUBE_IMGVIEW_FILELIST_CREATE_SUCCESS = 0,
    MMI_VAPP_CUBE_IMGVIEW_FILELIST_CREATE_LOADING,
    MMI_VAPP_CUBE_IMGVIEW_FILELIST_CREATE_FAIL,
        
    MMI_VAPP_CUBE_IMGVIEW_FILELIST_CREATE_ALL
} mmi_vapp_cube_imgview_filelist_create_enum;

/***************************************************************************** 
 * Class VappMediaCubeCell
 *****************************************************************************/
#define MMI_VAPP_CUBE_IMGVIEW_CELL_CLASS_NAME             "CUBE_IMGVIEW_CELL"
#define MMI_VAPP_CUBE_IMGVIEW_MENU_LAYOUT_CLASS_NAME      "CUBE_IMGVIEW_MENU_LAYOUT"
#define MMI_VAPP_CUBE_IMGVIEW_MENU_LAYOUT2_CLASS_NAME     "CUBE_IMGVIEW_MENU_LAYOUT2"
#define MMI_VAPP_CUBE_IMGVIEW_MENU_CLASS_NAME             "CUBE_IMGVIEW_MENU"
#define MMI_VAPP_CUBE_IMGVIEW_SCR_CLASS_NAME              "CUBE_IMGVIEW_SCR"
#define MMI_VAPP_CUBE_IMGVIEW_VIEW_CLASS_NAME             "CUBE_IMGVIEW_VIEW"
#define MMI_VAPP_CUBE_IMGVIEW_BUTTON2_CLASS_NAME           "CUBE_IMGVIEW_BUTTON2"


/*navigation mode cell/layout/menu*/
class VappCubeImgviewCell : public VfxFrame
{
    //VFX_DECLARE_CLASS(VappCubeImgviewCell);

public:
    enum
    {
        DATA_TYPE_MEMORY     = 0,       
        DATA_TYPE_DB,
        DATA_TYPE_FILE,
        DATE_TYPE_DEFAULT
    };

    enum
    {
        IMAGE_STATE_NULL = 0,       
        IMAGE_STATE_LOADING,
        IMAGE_STATE_DISPLAY,
        IMAGE_STATE_ERROR,
        IMAGE_STATE_LOCKING
    };

public:
    VappCubeImgviewCell(VcpBaseMenuLayout *layout);
    //VfxBool updateImage();

public:
    void onInit();
    void onDeinit();

    void setBgPos(const VfxPoint &value);
    void setContentPos(const VfxPoint &value);

    void setBgBounds(const VfxRect &value);
    void setContentBounds(const VfxRect &value);

    void updateCellImage(VfxS32 group, VfxS32 pos);
    void updatePos(const VfxRect& r, VfxBool animation);

    void enter(VfxRect rect, VfxBool is_animation);
    void leave(VfxRect rect);

    //void setContent(VfxImage *value);
    void setContentIndex(VfxS32 index);
    void addDisplayRights();
    void reduceDisplayRights();

    void closeImage();
    void setErrorIcon();
    void setLockingIcon();
    void setLoadingIcon();

    void setImageBuffer(void *buffer_p, S32 width, S32 height);

    VfxS32 getImageState()
    {
        return m_state;
    }
    void* getBuffer()
    {
        return m_memoryPtr;
    }

    //todo
    VfxS32 m_index;
private:
    VfxImageFrame* m_bgImage;
    VfxImageFrame* m_contentImage;
    VfxImage* m_image;
    VfxFrame* m_frame;
    
    VcpBaseMenuLayout *m_layout;
    void *m_imageBuffer;
    VfxU8 m_displayRights;
    VfxU8 m_state;
    void *m_memoryPtr;
};

class VappCubeImgviewMenuLayout : public VcpBaseMenuLayout
{
    //VFX_DECLARE_CLASS(VappCubeImgviewMenuLayout);

    // Constructor / Destructor
public:
    //VappCubeImgviewMenuLayout(VcpBaseMenu* menu) : VcpBaseMenuLayout() {};
    //VappCubeImgviewMenuLayout(VcpBaseMenu* menu) : VcpBaseMenuLayout(menu) {}

    VappCubeImgviewMenuLayout(VcpBaseMenu* menu);

    // Override
public:
    virtual void onInit();
    
    virtual void onDeinit();
    
    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }

    // Return the number of cells of a group.
    // Inherit should override this method.
    virtual VfxS32 getCellCount(
        VfxS32 group    // [IN] The group index
        );

    // Return the whole size of the menu.
    // Inherit should override this method.
    virtual VfxS32 getContentLength();
    
    // Return the region within a rectangle.
    virtual VcpMenuRegion queryRegion(
        const VfxRect& r    // [IN] The rectangle to query the menu region
        );
    
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    // Return a cell rect
    virtual VfxRect queryCellRect(
        VcpMenuPos pos  // [IN] The cell index to query
    );

    virtual VfxRect queryCellContentRectByPos(
        VcpMenuPos pos
        );

    virtual VfxSize getContentSize();

    virtual void getPreferFocusMargin(
        VfxS32 margin[4] // [OUT] the focus margin in Left, Up, Right, Down
    );

    
    virtual void setFocusItem(
        VcpMenuPos focus,                   // [IN] The focus index
        VfxBool isMoveToVisible = VFX_TRUE  // [IN] whether move focus item to be visible
    );
	virtual void onViewChanged();

// Method
public:
    void setCellWidth(VfxS32 value) { m_cellWidth = value; }
    void setCellHeight( VfxS32 value ) { m_cellHeight = value; }   
    void setCellContentWidth(VfxS32 value) { m_CellContentWidth = value; }
    void setCellContentHeight( VfxS32 value ) { m_cellContentHeight = value; }   

    void setCellCount( VfxS32 value ) 
	{ 
		m_cellCount = value; 
		update(); 
	}  

    VfxS32 getCellWidth() { return m_cellWidth; }
    VfxS32 getCellHeight() { return m_cellHeight ;}
    VfxS32 getCellContentWidth() { return m_CellContentWidth; }
    VfxS32 getCellContentHeight() { return m_cellContentHeight; }
    void disableAnimation();

    // Method
private:
    VcpMenuPos getCellPosByPt(
        VfxPoint pt
        );

// Variable
private:
    VfxS32 m_cellCount;
    VfxS32 m_cellWidth;
    VfxS32 m_cellHeight;
    VfxS32 m_CellContentWidth;
    VfxS32 m_cellContentHeight;
};

class VappCubeImgviewMenu : public VcpBaseMenu
{
    VFX_DECLARE_CLASS(VappCubeImgviewMenu);

public:
    VappCubeImgviewMenu();

// Signal
public:
    // Pen down signal
    VfxSignal2 <VfxS32 , VfxFrame*>    m_eventTapCell;
    
// Override
public:
    // On init
    virtual void onInit();

    virtual void onDeinit();
    
    virtual VcpBaseMenuLayout* createLayout();
    
    virtual VfxFrame* createCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos              // [IN] The cell index
    );

    // A notify that menu is going to close a cell
    virtual void onCloseCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index
        VfxFrame* cellFrame     // [IN] The cell will be closed
    );
    
    // Notify to update a cell's attributes
    // Inheritor should override this function.
    virtual void onUpdateCell(
        const VfxRect &rect,    // [IN] The position that layouter report
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell,         // [IN] The cell object
        VfxU32 flag             // [IN] The state about this cell
    );
    
    // Notify when a cell is clicked
    virtual void onTapCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell          // [IN] The cell object
    );
    
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem);

    void getCellWidthHeight(S32 index, PS32 width, PS32 height);
    void setCacheNumber(VfxS32 number);

    virtual void onDragStart();    
    virtual void onDragEnd();

    virtual void onViewScrollStart();
    virtual void onViewScrollEnd();
    
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);
    virtual void onAfterUpdate(const VcpMenuRegion& currentRegion, const VcpMenuRegion& targetRegion);
    
// Method
public:
    void setCellWidth(
        VfxS32 value
        );
    
    void setCellHeight(
        VfxS32 value
        );  
    
    void setCellCount(
        VfxS32 value
    );
    
    VfxBool getSkipUpdate()
    {
        return m_skipUpdate;
    }
    void setSkipUpdate(VfxBool value)
    {
        m_skipUpdate = value;
    }
    
    void updateMenu();
    
    void onFocusChange(VfxS32 group, VfxS32 pos);
    S32 findInBackBuffer(S32 index);
    void backUpCellBuffer();

    void heavyUpdate(VfxS32 index, VfxS32 error_code);

    void heavyUpdate();

    static void decodeCallBack(void* user_data, VfxS32 index, VfxS32 error_code);
    void VappCubeImgviewMenu::onTimerTick(VfxTimer *source);
    void closeAllImage(void);
    void restorAllImage(void);

    VfxTimer *m_timer;

private:
    VfxBool m_cancelFreeMode;
    VfxBool m_skipUpdate;
    VfxImage* m_image;
};


/*view mode button/cell/layout/menu*/
class VappCubeImgviewButton2 : public VfxControl
{
    VFX_DECLARE_CLASS(VappCubeImgviewButton2);

    // Constructor / Destructor      
public:
    // Default constructor
    VappCubeImgviewButton2();
    
    // Destructor
    virtual ~VappCubeImgviewButton2();
    
    // Signal
public:
    // Pen down signal
    VfxSignal1 <VfxPenEvent &> m_eventPenDown;
    
    // Pen up signal
    VfxSignal1 <VfxPenEvent &> m_eventPenUp;
    
    // Method
public:
    // Set image resource ID
    void setImage(
        VfxS32 image    // [IN] image ID
        );
    
    // Set image resource ID
    void setImageHighLight(
        VfxS32 highLightImage     // [IN] highlight image ID
        );
    
    // Set display flag
    void setDisplay(
        VfxBool isDisplay   // [IN] display flag
        );
    
    void setDraw(
        VfxPenEventTypeEnum type        
        );
    
    // Override    
private:
    // On init
    virtual void onInit();
    
    // On Deinit
    virtual void onDeinit();
    
    // On pen input
    // RETURNS: VfxBool    
    virtual VfxBool onPenInput(
        VfxPenEvent &event
        );
    
    // Variable
private:
    VfxImageFrame *m_image;
    VfxImageFrame *m_imageHighLight;
    VfxS32 m_imageId;
    VfxS32 m_imageHighLightImageId;
    VfxS32 m_currPentype;
};

class VappCubeImgviewCell2 : public VfxFrame
{
    //VFX_DECLARE_CLASS(VappCubeImgviewCell);
public:
    enum
    {
        IMAGE_STATE_NULL = 0,       
            IMAGE_STATE_LOADING,
            IMAGE_STATE_DISPLAY_L2,
            IMAGE_STATE_DISPLAY_L1,
            IMAGE_STATE_ERROR,
            IMAGE_STATE_LOCKING
    } cell_state_enum;

public:
    VappCubeImgviewCell2(VcpBaseMenuLayout *layout);
    ~VappCubeImgviewCell2();
    //VfxBool updateImage();

public:
    void onInit();
    void onDeinit();

    void setBgPos(const VfxPoint &value);
    void setContentPos(const VfxPoint &value);

    void setBgBounds(const VfxRect &value);
    void setContentBounds(const VfxRect &value);

    void updateCellImgae(VfxS32 group, VfxS32 pos);
    virtual void onDraw( VfxDrawContext &dc );

    void setCellPos(VfxS32 index);
    VfxS32 getCellPos() {return m_pos;}
    void setCellFileIndex(VfxS32 index){m_index = index;}    
    void closeImage();
    //void setImageBuffer(void *buffer_p);
    VfxS32 getImageState()
    {
        return m_state;
    }
    void *getImageBufPtr()
    {
        return m_memoryPtr;
    }
    void updateCellImage(VfxS32 group, VfxS32 pos);
    void setImageBuffer(void *buffer_p);
    void displayPhotoFrame();
    void setImageState(S32 state);
    void setImageBufferWidthHeight(S32 width, S32 height);
    void setErrorIcon();
    void setLockingIcon();
    void setLoadingIcon();
    VfxS32 getImageBufferNoblocking(void* menu_ptr, VfxS32 expect_source);

private:
    VfxImageFrame *m_bgImageFrame;
    VfxImageFrame *m_photoFrame;
    VfxImage *m_bgImage;
    VfxImageFrame *m_contentImage;
    VfxImage *m_image;

    VfxS32 m_pos;
    VcpBaseMenuLayout *m_layout;
    
    void *m_imageBuffer;
    
    VfxS32 m_state;
    void *m_memoryPtr;
    VfxS32 m_index;

    VfxS32 m_cellBufferWidth;
    VfxS32 m_cellBufferHeight;
};


class VappCubeImgviewMenuLayout2 : public VcpBaseMenuLayout
{
    //VFX_DECLARE_CLASS(VappCubeImgviewMenuLayout2);

    // Constructor / Destructor
public:
    //VappCubeImgviewMenuLayout(VcpBaseMenu* menu) : VcpBaseMenuLayout() {};
    //VappCubeImgviewMenuLayout2() {};
    VappCubeImgviewMenuLayout2(VcpBaseMenu* menu);
    
    // Override
public:
    virtual void onInit();
    
    virtual void onDeinit();

    virtual ScrollDirEnum getScrollDir()
    {
        return SCROLLDIR_VERT;
    }
    // Return the number of cells of a group.
    // Inherit should override this method.
    virtual VfxS32 getCellCount(
        VfxS32 group    // [IN] The group index
        );
    
    // Return the whole size of the menu.
    // Inherit should override this method.
    virtual VfxS32 getContentLength();
    
    // Return the region within a rectangle.
    virtual VcpMenuRegion queryRegion(
        const VfxRect& r    // [IN] The rectangle to query the menu region
        );
    
    // Return a cell rect
    virtual VfxRect queryCellRect(
        VcpMenuPos pos  // [IN] The cell index to query
        );
    
    virtual VfxRect queryCellContentRectByPos(
        VcpMenuPos pos
        );
    
    virtual VfxSize getContentSize();
    
    virtual void getPreferFocusMargin(
        VfxS32 margin[4] // [OUT] the focus margin in Left, Up, Right, Down
        );
    virtual void onViewChanged();
    
    // Method
public:
    VcpMenuPos getCellPosByPt(VfxPoint pt);

    void setCellWidth(VfxS32 value) { m_cellWidth = value; }
    VfxS32 getCellWidth() { return m_cellWidth; }
    
    void setCellHeight(VfxS32 value) { m_cellHeight = value;}   
    VfxS32 getCellHeight() { return m_cellHeight ;}
    
    void setCellCount(VfxS32 value) { m_cellCount = value; update();}  
    
    void setCellBgWidth(VfxS32 value) { m_cellBgWidth = value; }
    VfxS32 getCellBgWidth() { return m_cellBgWidth; }
    
    void setCellBgHeight(VfxS32 value){ m_cellBgHeight = value; }
    VfxS32 getCellBgHeight() { return m_cellBgHeight; }
    
    void setCellBgStartPoint(VfxPoint pt) { m_cellBgStartX = pt.x; m_cellBgStartY = pt.y; }
    VfxPoint getCellStartPoint() { return VfxPoint(m_cellBgStartX, m_cellBgStartY); }
    
    void setCellContentWidth(VfxS32 value) { m_CellContentWidth = value; }
    VfxS32 getCellContentWidth() { return m_CellContentWidth; }
    
    void setCellContentHeight(VfxS32 value) { m_cellContentHeight = value; }
    VfxS32 getCellContentHeight() { return m_cellContentHeight; }
    
    void setCellContentStartPoint(VfxPoint pt) { m_cellContentStartX = pt.x; m_cellContentStartY = pt.y; }
    VfxPoint getCellContentStartPoint() { VfxPoint(m_cellContentStartX, m_cellContentStartY); }

    VfxRect getViewRect();

    // Variable
private:
    VfxS32 m_cellCount;
    VfxS32 m_cellWidth;
    VfxS32 m_cellHeight;

    VfxS32 m_cellBgStartX;
    VfxS32 m_cellBgStartY;
    VfxS32 m_cellBgWidth;
    VfxS32 m_cellBgHeight;
    
    VfxS32 m_cellContentStartX;
    VfxS32 m_cellContentStartY;
    VfxS32 m_CellContentWidth;
    VfxS32 m_cellContentHeight;
};

class VappCubeImgviewMenu2 : public VcpBaseMenu
{
    //VFX_DECLARE_CLASS(VappCubeImgviewMenu);

public:
    VappCubeImgviewMenu2();
    ~VappCubeImgviewMenu2();

// Signal
public:
    // Pen down signal
    VfxSignal2 <VfxS32 , VfxFrame*>    m_eventTapCell;
    VfxSignal2 <VfxS32 , VfxFrame*>    m_imageMove;
    VfxSignal2 <VfxS32, VfxS32> m_viewModeFocusChange;

// Override
public:
    // On init
    virtual void onInit();

    virtual void onDeinit();
    
    virtual VcpBaseMenuLayout* createLayout();
    
    virtual VfxFrame* createCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos              // [IN] The cell index
    );

    
    // A notify that menu is going to close a cell
    virtual void onCloseCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index
        VfxFrame* cellFrame     // [IN] The cell will be closed
    );
    
    // Notify to update a cell's attributes
    // Inheritor should override this function.
    virtual void onUpdateCell(
        const VfxRect &rect,    // [IN] The position that layouter report
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell,         // [IN] The cell object
        VfxU32 flag             // [IN] The state about this cell
    );
    
    // Notify when a cell is clicked
    virtual void onTapCell(
        VfxS32 group,           // [IN] The group index
        VfxS32 pos,             // [IN] The cell index in the group
        VfxFrame* cell          // [IN] The cell object
    );
    
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual void onFocusIndexChange(VcpMenuPos focusItem, VcpMenuPos previousFocusItem);
    void setFocusItem(VcpMenuPos focus, VfxBool isMoveToVisible);
    void getCellWidthHeight(S32 index, PS32 width, PS32 height);
    virtual void onDragEnd();
    virtual void onDragStart();
    virtual void onDrag(VfxS32 xoffset, VfxS32 yoffset);
    virtual void onAfterUpdate(const VcpMenuRegion& currentRegion, const VcpMenuRegion& targetRegion);

    virtual void onViewScrollStart();
    virtual void onViewScrollEnd();

// Method
public:
    VcpMenuPos getCellPosByPt(
        VfxPoint pt
        );
    
    void setCellWidth(
        VfxS32 value
        );
    
    void setCellHeight(
        VfxS32 value
        );
    VfxRect queryCellRect(VfxS32 index);

    void setCellCount(VfxS32 value);

    VfxRect queryCellRectByPos(VfxS32 index);
    void setCacheNumber(VfxS32 number);
    void setEffectFinished(VfxBool value) {m_effectFiniished = value;}
    VfxBool getSkipUpdate()
    {
        return m_skipUpdate;
    }
    void setSkipUpdate(VfxBool value)
    {
        m_skipUpdate = value;
    }
    S32 getFocusIndexByRect(VfxRect r);
    VfxRect getViewRect();    
    void closeAllImage();
    void heavyUpdate(VfxS32 index, VfxS32 error_code);
    void heavyUpdate(void);
    static void decodeCallBack(void* user_data, VfxS32 index, VfxS32 error_code);

private:  
    VfxBool m_effectFiniished;
    VfxBool m_skipUpdate;
    VfxBool m_cancelFreeMode;
};


// screen
class VappCubeImgViewScr : public VappCubeScr
{
    VFX_DECLARE_CLASS(VappCubeImgViewScr);
    
// Constructor / Destructor
public:
    // Default constructor
    VappCubeImgViewScr();
    

// Override
private:
    // On init
    virtual void onInit();

    // On deinit
    virtual void onDeinit();
    
    // On pen input
    virtual VfxBool onPenInput(VfxPenEvent &event);
    
// Method
public:
    static void onSortOver(void* user_data, VfxS32 count, VfxS32 sort_state);
    static void onDecodeOver(void* user_data, VfxS32 index, void* memory_addr, S32 state, S32 mode);

    void onSetState(VfxS32 state);
    void onBackEffectFinished(VfxFrame *frame, VfxBool isComplete);
    void onFrontEffectFinished(VfxFrame *frame, VfxBool isComplete);
    //void startTimeLine();
    void onEventUpClose(
        VfxPenEvent &event
    );
    void onTimerDrag(VfxTimer *timer);

    VfxRect getAvailRect();
    void startTimeLine();
    void stopTimeLine();
    void onTimeLineStop(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void setArrowHidden(VfxBool hidden);
    static mmi_vapp_cube_imgview_app_mode_enum getAppState();
    static void setAppState(mmi_vapp_cube_imgview_app_mode_enum state);
    //static void clipCallback(U32* handle, S32 layer_w, S32 layer_h, srv_mediacache_rect_struct *img_org, srv_mediacache_rect_struct *img_resized, void *user_data);
    
    void onViewModeEventTapCell(VfxS32 index, VfxFrame* cell);

    void getTargetWidthHeight(S32 index, S32 mode, PS32 width, PS32 height);

    void onImageMode(VfxS32 value, VfxFrame *frame);

    void regDefaultPageAct(VfxControl *obj)
    {
        VappCubeScr::regDefaultPageAct(this);
    }

    void deregDefaultPageAct(VfxControl *obj)
    {
        VappCubeScr::deregDefaultPageAct(this);
    }

	VfxS32 createFileList(VfxS32 *count);

    void startViewModeUpdateTimer();
    void stopViewModeUpdateTimer();

// Method
private:
    void onEventTapCell(
        VfxS32 index,
        VfxFrame* cell 
    );
	void onLoadingTimerExpir(VfxTimer *timer);
    void onViewModeUpdate(VfxTimer *timer);    

private:
    //common shared field
    VfxRect m_rectAvailRegion;
    VfxS32 m_cellCount;

    VfxFrame *m_loadingContainer;
    VfxImageFrame *m_loadingBg;
    VfxImageFrame *m_loading;
    VfxImageFrame *m_popupIcon;
	VfxS32 m_loadingCount;
	VfxTimer *m_timer;
    VfxTimer *m_timerViewModeUpdate;
    VcpMarquee *m_text;

    VcpFrameEffect *m_effectFront;
    VcpFrameEffect *m_effectBack;
    VfxFrame *m_currCell;
    static mmi_vapp_cube_imgview_app_mode_enum m_appState;

    // navigation mode field
    VappCubeImgviewMenu *m_navigationModeMenu;
    VfxImageFrame *m_navigationModeBg;

    
    /*
    VappCubeImgviewMenu2 *m_viewModeMenu;
    VfxImageFrame *m_viewModeBg;
    VappCubeImgviewButton2 *m_button;
    VfxImageFrame *m_prevArrow;
    VfxImageFrame *m_nextArrow;
    VfxFloatTimeline *m_upArrowTimeLine;
    VfxFloatTimeline *m_downArrowTimeLine;
    */
    VfxFrame *m_viewModeFrame;
    VappCubeImgviewMenu2 *m_viewModeMenu;
    VfxImageFrame *m_viewModeBg;
    VappCubeImgviewButton2 *m_button;
    VfxImageFrame *m_prevArrow;
    VfxImageFrame *m_nextArrow;
    VfxFloatTimeline *m_upArrowTimeLine;
    VfxFloatTimeline *m_downArrowTimeLine;
    VfxControl *m_opacityFrame;
};

typedef struct 
{
    S32 index;
    PU8 buffer;
} vapp_cube_imgview_backup_buffer;

// app structure
typedef struct 
{
    //VfxU8 cube_style;
    VfxS32 currCellPos;
	//VfxPoint contentOffset;
    VfxS32 focusIndex;
    mmi_vapp_cube_imgview_state_enum state;
    VfxBool is_give_up_sort_result; // this sort is last time sort
	mmi_vapp_cube_imgview_app_mode_enum mode;
} mmi_vapp_cube_imgview_cntx_struct;

#endif /* __VAPP_3D_CUBE_APP_IMGVIEW_H__ */

