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
 *  vapp_shell_imageviewer.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  Shell Image Viewer Panel
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SHELL_IMAGEVIEWER_H__
#define __VAPP_SHELL_IMAGEVIEWER_H__


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_VUI_SHELL_IMAGE_VIEWER__
#include "vrt_datatype.h"
#include "vcp_wheel_menu.h"
#include "vcp_popup.h"
#include "ShellApp\base\vapp_shell_panel.h"
#include "ShellApp\panel\ImageViewer\vadp_shell_imageviewer.h"
#include "vcp_wheel_menu.h"
#include "vcp_popup.h"
#include "vapp_shell_panel.h"
#include "vfx_control.h"
#include "vfx_datatype.h"
#include "vfx_cpp_base.h"
#include "vfx_basic_type.h"
#include "vfx_timer.h"
#include "vfx_frame.h"
#include "vadp_shell_imageviewer_config.h"
#include "vfx_signal.h"
#include "vfx_weak_ptr.h"
#include "vcp_frame_effect.h"
#include "vfx_sys_memory.h"
#include "vfx_object.h"
#include "vcp_segment_button.h"
#include "vcp_waiting_icon.h"
#include "vfx_primitive_frame.h"
#include "vfx_text_frame.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif
#include "FileMgrSrvGProt.h"
#include "MediaCacheSrvGprot.h"
#ifdef __cplusplus
#include "MMIDataType.h"
}
#endif
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

 
/***************************************************************************** 
 * Class VappShellIVCell
 *****************************************************************************/
class VappShellIVCell : public VfxControl
{
// Declaration
public:
    enum
    {
        DATA_TYPE_MEMORY     = 0,       
        DATA_TYPE_DB,
        DATA_TYPE_FILE,
        DATE_TYPE_DEFAULT
    };

    // The title position
    enum
    {
        STATE_EXIT     = 0,       
        STATE_DEFAULT,
        STATE_IMAGE
    };
    
// Constructor / Destructor
public:
    // Default constructor
    VappShellIVCell(VfxS32 index);

    // Destructor
    virtual ~VappShellIVCell();

// Override
public:
    // On init
    virtual void onInit();

    // On deinit
    virtual void onDeinit();
    
// Method
public:
    //setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    //bringToFront();
    void onHightLight();

    void onDeHightLight();
    
    VfxBool updateImage(VfxS32 type);

    void closeImage();

    void setDefaultIcon();

    void setErrorIcon();

    void setDRMIcon();
    
    void setImageBuffer(void *buffer_p);
    
    void updatePos(const VfxRect& r, VfxBool animation);

    VfxS32 getImageState()
    {
        return m_state;
    }

    VfxBool getIsHighlight()
    {
       return m_isHighlight;
    }

    VfxS32 getIndex()
    {
       return m_index;
    }
    
    void onSetImageTimerTick(VfxTimer *source);

    VfxBool getIsBorderContainPoint(
        const VfxPoint &point
    ) const;

    VfxRect getBorderRect() const;

    void stopSetImageTimer();
    
// Variable
private:
    VfxS32 m_index;
    VfxS32 m_state;
    VfxS32 m_width;
    VfxS32 m_height;
    VfxS32 m_imageWidth;
    VfxS32 m_imageHeight;
    VfxBool m_isHighlight;
    void *m_imageBuf;
    VfxFrame *m_picFrame;
    VfxFrame *m_border;
    VfxTimer *m_timer;
};


/***************************************************************************** 
 * Class VappShellIVMenu
 *****************************************************************************/

class VappShellIVMenu : public VcpWheelMenu
{       
public:
    enum
    {
        IMG_MAX_WIDTH     = VADP_SHELLIV_CELL_WIDTH,
        IMG_MAX_HEIGHT    = VADP_SHELLIV_CELL_HEIGHT,        
#if defined(__MMI_MAINLCD_320X480__)
        DEFAULT_WIDTH     = 278,
        DEFAULT_HEIGHT    = 182,
#elif defined(__MMI_MAINLCD_240X400__)
        DEFAULT_WIDTH     = 206,
        DEFAULT_HEIGHT    = 164,
#else 
        DEFAULT_WIDTH     = 176,
        DEFAULT_HEIGHT    = 132,
#endif
    };

    enum
    {
        BORDER_PIXELS     = 4       
    };

    enum
    {
        CELL_ITEM_HEIGHT     = IMG_MAX_HEIGHT + 2*BORDER_PIXELS,

#if defined(__MMI_VUI_SHELL_IMAGE_VIEWER_SLIM__)
        CELL_ITEM_AHEAD_COUNT = 1,
        CELL_ITEM_BEHIND_COUNT = 1
#else
        CELL_ITEM_AHEAD_COUNT = 3,
        CELL_ITEM_BEHIND_COUNT = 3
#endif
    };

    enum
    {
        DELETE_ANIMATION_DURATION = 750
    };

    enum
    {
        DELETE_STATE_INIT = 0,
        DELETE_STATE_FADEOUT,
        DELETE_STATE_DONE    
    };
    
public:
    VfxSignal0 m_eventDelAnimateEnd;
    VfxSignal1 <VfxS32> m_eventFocusChange;
    
// Override
protected:
    virtual void onInit();

    virtual void onDeinit();
    
    // Return the count of menu items.
    // Derived class should override this function.
    virtual VfxS32 getCount();

    // Return the visible menu item count which behind the focus item.
    // Derived class should override this function.
    virtual VfxS32 getBehindCount()
    {
        return m_behindCount;
    }

    // Return the visible menu item count which ahead the focus item.
    // Derived class should override this function.
    virtual VfxS32 getAheadCount()
    {
        return m_aheadCount;
    }

    // Return the frame effect callback.
    // Derived class should override this function.
    virtual VcpWheelMenuFrameEffectCBFuncPtr getFrameEffectCB();

    // Create a cell object.
    // Inheritor should override this function.
    // RETURNS: a cell object 
    virtual VfxFrame* createCell(
        VfxS32 pos,              // [IN] The cell index
        VfxS32 subcell
    );
    
    // Notify to update a cell's position.
    // Inheritor should override this function.
    virtual void onUpdateCell(
        VfxS32 cell,                // [IN] The cell index in the group
        VfxS32 subcell,             // [IN] The sub cell index in the group
        VfxFrame* cellFrame         // [IN] The cell object
    );

    // A notify that menu is going to close a cell
    virtual void onCloseCell(
        VfxS32 cell,                // [IN] The cell index in the group
        VfxS32 subcell,             // [IN] The sub cell index in the group
        VfxFrame* cellFrame     // [IN] The cell will be closed
    );
    
    virtual void onAfterUpdateCell();
        
    // Notify when the focus item is change
    virtual void onFocusIndexChange(
        VfxS32 focusItem,               // [IN] The focus item index now
        VfxS32 preFocusItem             // [IN] The previous focus item index
    );

    // Notify when the user start drag the menu
    virtual void onDragStart();

    // Notify when the user stop drag the menu
    virtual void onDragEnd(
        VfxS32 xspeed,        // [IN] how fast to release the pen in x direction. Unit is point / 1sec.
        VfxS32 yspeed         // [IN] how fast to release the pen in y direction. Unit is point / 1sec.
    );

    // Notify when the menu is dragged
    virtual void onDrag(
        VfxS32 xoffset, 
        VfxS32 yoffset
    );

    // Notify when the menu is tapped
    virtual void onTap(
        VfxPoint pt
    );

    virtual void onAfterWithdrawCellClosed();

public:
    void setCount(
        VfxS32 count
    );
    
    static vrt_render_dirty_type_enum FrameEffectCB(
        VfxS32                              cell,           // [IN] the cell index
        VfxS32                              subCell,        // [IN] the sub cell index
        VfxFloat                            cellRelPos,     // [IN] the cell position
        vrt_frame_visual_property_struct    *target_frame,  // [IN] the cell frame
        VfxFloat                            fPos,           // [IN] animating index value
        VfxS32                              focus,          // the focus value of the menu
        VfxRect                             viewBounds,     // the menu bounds
        void                                *userData,      // user data
        VfxU32                              userDataSize,   // user data size
        VcpWheelMenuState                   state,          // [IN] the state of Menu
        VfxFloat                            level           // [IN] the level of state
    );

    void updateCellImage();

    /* Free image buffer and set back to default image */
    void closeCellImage();
    
    void updateDecodeResult(VfxS32 index, VfxS32 error_code);
    
    static void decodeCallBack(void* user_data, VfxS32 index, VfxS32 error_code);

    void onTimerTick(VfxTimer *source);

    void onDelTimerTick(VfxTimer *source);

    void onFrameEffectFinished(
        VfxFrame *target, 
        VfxBool isCompleted);
        
    void deleteFocusItem();

    VfxS32 getHighlightIndex();

    static void resizeImgCallback(
        U32* handle, 
        VfxS32* layer_w, 
        VfxS32* layer_h, 
        srv_mediacache_rect_struct *img_org, 
        srv_mediacache_rect_struct *img_resized, 
        void *user_data
    );

//variable
private:
    VfxS32 m_lcdWidth;
    VfxS32 m_lcdHeight;
    VfxS32 m_count;
    VfxS32 m_aheadCount;
    VfxS32 m_behindCount;
    VfxTimer *m_timer;
    VfxTimer *m_delAnimateTimer;
    VfxBool m_isDragging;
    VfxBool m_isDeleting;
    VcpFrameEffect *m_frameEffect;
    VfxFrame *m_removedFrame;
};

/***************************************************************************** 
 * Class VappShellIVPanel
 *****************************************************************************/

class VappShellIVPanel : public VappShellPanel
{   
    VAPP_SHELL_PANEL_CREATE(VappShellIVPanel, VFX_FALSE);

    enum
    {
        BUTTON_STORAGE  = 0,
        BUTTON_SENDAS,
        BUTTON_USEAS,
        BUTTON_DELETE
    };

    enum
    {
        DELETE_MENU_ID_DELETE   = 0,
        DELETE_MENU_ID_CANCEL,
    };

    enum
    {
        STORAGE_MENU_ID_CANCEL = SRV_FMGR_DRV_TOTAL + 1
    };
    
    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        TOOLBAR_POS_X   = 35,
        TOOLBAR_POS_Y   = 364,
        TOOLBAR_WIDTH   = 250,
        TOOLBAR_HEIGHT  = 53,
#elif defined(__MMI_MAINLCD_240X400__)
        TOOLBAR_POS_X   = 24,
        TOOLBAR_POS_Y   = 300,
        TOOLBAR_WIDTH   = 198,
        TOOLBAR_HEIGHT  = 40,
#else
        TOOLBAR_POS_X   = 30,
        TOOLBAR_POS_Y   = 224,
        TOOLBAR_WIDTH   = 180,
        TOOLBAR_HEIGHT  = 36,
#endif
    };

    enum
    {
#if defined(__MMI_MAINLCD_320X480__)
        NOIMAGE_ICON_POS_X   = 80,
        NOIMAGE_ICON_POS_Y   = 100,
        NOIMAGE_STR_POS_X   = 0,
        NOIMAGE_STR_POS_Y   = 255,        
        NOIMAGE_STR_HEIGHT  = 30,
#elif defined(__MMI_MAINLCD_240X400__)
        NOIMAGE_ICON_POS_X   = 54,
        NOIMAGE_ICON_POS_Y   = 94,
        NOIMAGE_STR_POS_X   = 0,
        NOIMAGE_STR_POS_Y   = 224,        
        NOIMAGE_STR_HEIGHT  = 30,
#else
        NOIMAGE_ICON_POS_X   = 73,
        NOIMAGE_ICON_POS_Y   = 62,
        NOIMAGE_STR_POS_X   = 0,
        NOIMAGE_STR_POS_Y   = 148,        
        NOIMAGE_STR_HEIGHT  = 30,
#endif
    };

    enum
    {
        OPTION_MAX_COUNT = 10,
        OPTION_MENU_ID_CANCEL = OPTION_MAX_COUNT + 1    
    };
    
// Override
protected:
    virtual void onInit();
    
    virtual void onDeinit();
    
    // init view. application can create components here
    virtual void onInitView();
    
    // deinit view. applicaiton can close components which are created in onInitView stage
    virtual void onDeinitView();
    
    // enter view. Application can create components which waste
    // lots of resources here.
    virtual void onEnterView();
    
    // exit view. Application can release those resources which
    // is obtained in onEnterView
    virtual void onExitView(
        ShellExitCauseEnum cause
    );

private :
    void enterView();

    void exitView();
    
    void onDelAnimateDone();

    void onToolBarButtonClicked(
        VfxObject* sender, 
        VfxId buttonId
    );

    void onStorageMenuButtonClicked(
        VfxObject* sender, 
        VfxId buttonId
    );

    void onSendAsMenuButtonClicked(
        VfxObject* sender, 
        VfxId buttonId
    );

    void onUseAsMenuButtonClicked(
        VfxObject* sender, 
        VfxId buttonId
    );

    void onDlelteMenuButtonClicked(
        VfxObject* sender, 
        VfxId buttonId
    );

    void onFocusChange(
        VfxS32 index
    );
        
    void createMenu();

    void destroyMenu();

    void checkFileCount();

    void drawNoStorageStr();

    void drawNoImageIcon();

    void hideNoImageIcon();

    void drawWaiting();

    void stopDrawWaiting();

    void showStorageSelect();

    void showSendAsSelect();

    void showUseAsSelect();

    void showDeleteSelect();
    
public : 
    static void listReadyCallBack(
        void* user_data
    );

    static void deleteDoneCallBack(
        void* user_data
    );

    static void refreshingListCallBack(
        void* user_data
    );
    
// Variable
private:
    VappShellIVMenu   *m_menu;
    VcpSegmentButton  *m_toolBar;
    VfxWeakPtr <VcpCommandPopup>   m_popupMenu;
    VcpWaitingIcon    *m_waitingIcon;
    VfxBool            m_isListReday;
    VfxBool            m_isDelAnimateDone;
    VfxU32             m_cellCount;
    VfxS32             m_focusIdx;
    VfxS32             m_deleteIdx;
    VfxImageFrame      *m_noImageIcon;
    VfxImageFrame      *m_bg;
    VfxTextFrame       *m_noImageString;
    VfxTextFrame       *m_noStorageStr;
    static VfxU8       m_storage;
};

#endif /* __MMI_VUI_SHELL_IMAGE_VIEWER__ */
#endif /* __VAPP_SHELL_IMAGEVIEWER_H__ */

