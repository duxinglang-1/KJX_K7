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
 *  vapp_ncenter.h
 *
 * Project:
 * --------
 *  COSMOS Notification Center
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#include "MMI_features.h"


#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_KEY_ONLY_NCENTER__)


#ifndef __VAPP_NCENTER_H__
#define __VAPP_NCENTER_H__


#include "vcp_status_icon_bar.h"
#include "vfx_app_cat_scr.h"
#include "vfx_primitive_frame.h"

#include "vcp_tab_bar.h"
#include "vfx_container.h"

#include "vsrv_ncenter.h"
#include "vapp_ncenter_pure_key_base_cell.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
class VappNCenterOperatorCell;
class VappQuickSettingCell;
class VappSafeModeNotificationCell;

// NCenter event
enum VappNCenterEventEnum
{
    VAPP_NCENTER_EVENT_ENTER,
    VAPP_NCENTER_EVENT_ENTERED,
    VAPP_NCENTER_EVENT_EXIT,
    VAPP_NCENTER_EVENT_EXITED,
    VAPP_NCENTER_EVENT_END_OF_ENUM
};


enum VappNCenterOptionsMenuType
{
    VAPP_NCENTER_OPTIONS_MENU_TYPE_2,
    VAPP_NCENTER_OPTIONS_MENU_TYPE_3,
    VAPP_NCENTER_OPTIONS_MENU_TOTAL
};



#if defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__)
#define  VAPP_NCENTER_SOFTKEY_BAR_HEIGHT  (23)
#define  VAPP_NCENTER_SOFTKEY_BAR_GAP (12)
#define  VAPP_NCENTER_SOFTKEY_WIDTH (LCD_WIDTH/3)
#define  VAPP_NCENTER_SOFTKEY_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(18)

#define  VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM (3)
#define  VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT (MMI_MENUITEM_HEIGHT)
#define  VAPP_NCENTER_OPTIONS_MENU_FONT_SIZE (18)

#define  VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y (10)
#define  VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X (8)
#define  VAPP_NCENTER_OPTIONS_MENU_TEXT_OFFSET_X (8)
#define  VAPP_NCENTER_OPTIONS_MENU_HIGHLIGHT_OFFSET_X (2)

#elif defined(__MMI_MAINLCD_320X240__)
#define  VAPP_NCENTER_SOFTKEY_BAR_HEIGHT  (20)
#define  VAPP_NCENTER_SOFTKEY_BAR_GAP (30)
#define  VAPP_NCENTER_SOFTKEY_WIDTH (120)
#define  VAPP_NCENTER_SOFTKEY_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(18)

#define  VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM (3)
#define  VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT (MMI_MENUITEM_HEIGHT)
#define  VAPP_NCENTER_OPTIONS_MENU_FONT_SIZE (18)

#define  VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y (10)
#define  VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X (8)
#define  VAPP_NCENTER_OPTIONS_MENU_TEXT_OFFSET_X (8)
#define  VAPP_NCENTER_OPTIONS_MENU_HIGHLIGHT_OFFSET_X (2)

#else
#define  VAPP_NCENTER_SOFTKEY_BAR_HEIGHT  (30)
#define  VAPP_NCENTER_SOFTKEY_BAR_GAP (20)
#define  VAPP_NCENTER_SOFTKEY_WIDTH (LCD_WIDTH/3)
#define  VAPP_NCENTER_SOFTKEY_FONT_SIZE   VFX_FONT_DESC_VF_SIZE(22)

#define  VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM (3)
#define  VAPP_NCENTER_OPTIONS_MENU_ITEM_HEIGHT (MMI_MENUITEM_HEIGHT)
#define  VAPP_NCENTER_OPTIONS_MENU_FONT_SIZE (20)

#define  VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_Y (10)
#define  VAPP_NCENTER_OPTIONS_MENU_BG_IMG_GAP_X (8)
#define  VAPP_NCENTER_OPTIONS_MENU_TEXT_OFFSET_X (8)
#define  VAPP_NCENTER_OPTIONS_MENU_HIGHLIGHT_OFFSET_X (2)

#endif



/***************************************************************************** 
 * Class VappNCenterScr
 *****************************************************************************/

class VappNCenterScr : public VfxAppCatScr
{

    VFX_DECLARE_CLASS(VappNCenterScr);
// Constructor / Destructor
public:
    // Default constructor
    VappNCenterScr() : m_dir(VFX_SCR_ROTATE_TYPE_NORMAL)
    {
        setIsSmallScreen();
    };

// Override
protected:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);    
private:
    VfxScrRotateTypeEnum m_dir;
};

/***************************************************************************** 
 * Class VappNCenter 
 *****************************************************************************/

class VappNCenter : public VfxControl//, public VfxNObserver
{
    VFX_DECLARE_CLASS(VappNCenter);
    VFX_OBJ_DECLARE_SINGLETON_CLASS(VappNCenter);
// Constructor / Destructor
public:
    // Default constructor
    VappNCenter();   
    enum
    {
        VAPP_NCENTER_CONFIRM_POPUP,
        VAPP_NCENTER_REMIND_POPUP
    };

private:
    enum
    {
        VAPP_NCENTER_MAIN_SCREEN,
        VAPP_NCENTER_OPTION_SCREEN,
        VAPP_NCENTER_CONFIRM_POPUP_SCREEN,
        VAPP_NCENTER_REMIND_POPUP_SCREEN,
        VAPP_NCENTER_MAIN_TOTAL
    };

// Method
public:
    void enter();
    void entryByKey(VfxU8 key_type);
    void leave();

    void requestLeave(VsrvNotification* noti);
    
     
    void disableLeaveOnScreenChange()
    {
        m_disableLeave = VFX_TRUE;
    }
    
    VfxBool getDisableLeaveOnScreeChange()
    {
        return m_disableLeave;
    }

    void onRotate(VfxScreenRotateParam param);

    VfxBool getDisableDrag()
    {
        return m_disableDrag;
    }

    void setDisableDrag(VfxBool value)
    {
        m_disableDrag = value;
    }

    void setNCenterScr(VappNCenterScr *nc)
    {
        m_ncenterScrPtr = nc;
    }

    VappNCenterScr* getNCenterScr()
    {
        return m_ncenterScrPtr.get();
    }

    VfxBool getNCenterEntered()
    {
        return m_entered;        
    }

    void clearListFocus(void)
    {
        m_list->clearFocusItem();
    }

    VfxBool isInOptionsMenu()
    {
        return (m_screen_id == VAPP_NCENTER_OPTION_SCREEN) ? VFX_TRUE : VFX_FALSE;       
    }

    VfxBool isInConfirmPopup()
    {
        return (m_screen_id == VAPP_NCENTER_CONFIRM_POPUP_SCREEN) ? VFX_TRUE : VFX_FALSE;        
    }
    
    VfxBool isInRemindPopup()
    {
        return (m_screen_id == VAPP_NCENTER_REMIND_POPUP_SCREEN) ? VFX_TRUE : VFX_FALSE;        
    }

    VfxBool isInMainScreen()
    {
        return (m_screen_id == VAPP_NCENTER_MAIN_SCREEN) ? VFX_TRUE : VFX_FALSE;        
    }

    void setLSKString(VfxId string_id)
    {
        m_softkeybar->setSoftkey(VCP_SOFTKEY_LSK, VFX_WSTR_RES(string_id), VFX_IMAGE_SRC_NULL);
    }


    VfxBool isFocusOnQuickSetting();
    void clearQuickSettingFocus();

    void showOptionsMenu(VappNCenterOptionsMenuType type);
    void closeOptionsMenu();
    void showPopup(const VfxWString &str, VfxResId icon_id, VfxResId lsk_id, VfxResId rsk_id, VfxS32 popup_type);
    void closePopup(void);
    void setQuickSettingSoftkey(void);

    void setPopupHandle(VfxS32 popupHandle) { m_popupHandle = popupHandle; };

    void emitEvent(VappNCenterEventEnum event);
    
            
// Overridable
public:
    // IVfxAllocatable interfaces
    virtual vrt_allocator_handle getAllocator();

// Override
protected:
    virtual void onInit();
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    void onCloseContentView(void);
    void onCreateContentView(VfxFrame* parent);
    
    VfxS32 onCreateContentTop(VfxFrame* parent);
    VfxS32 onCreateContentBottom(VfxFrame* parent); 

    void optionsMenuItemMoveDown();
    void optionsMenuItemMoveUp();
    
// Signal
public:
    VfxSignal1 <VappNCenterEventEnum>  m_signalEvent;
    
// Implementation
private:
    void onLeaveEnd(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void onEnterEnd(VfxTimer *source);

    void onEventClearAll(VfxObject* sender, VfxId id);
    

    void createSystemView();
    void releaseSystemView();


    
    void onActiveScreenEnter(VfxWeakPtr <VfxScreen> scr);
    void onActiveScreenExit(VfxWeakPtr <VfxScreen> scr);
    
    void leaveInternal();
    void leaveInternalEx(VfxTimer *source);   


    void createNoTextFrame();

    void onNotificationChanged(VsrvNotification* noti, VsrvNStatusType status);
    VfxBool checkNotification(VsrvNotification *noti);
    VfxBool checkIsTheSameType(VsrvNotification *noti, VappNCenterListCellStruct* data);

    VfxBool createCell(VsrvNotification *noti, VfxId refId, VfxBool addBeforeRef = VFX_FALSE);
    VfxBool closeCell(VsrvNotification *noti);

    void onEventLsk(VcpSoftkeyEventEnum event_type);
    void onEventCsk(VcpSoftkeyEventEnum event_type);
    void onEventRsk(VcpSoftkeyEventEnum event_type);
    VfxS32 getOptionsIndexByPos(VfxPoint pos);
    VfxBool optionsMenuPenHandler(VfxPenEvent &event);
    void onTimer(VfxTimer* pTime);

private:
    VfxContext *m_context;             // For allocate memory
    VsrvNotification* m_callbackNoti; 

    VfxTextFrame *m_noTextFrame;       // Text for "No notifications"
    VfxS32 m_eventCount;       // event item count, only for removeable items
    VfxS32 m_ongoingCount;     // ongoing item count

    VappNCenterList *m_list;   // Ncenter list frame

    VfxFrame *m_panel;         // Ncenter base frame
    VfxTimer *m_enterTimer;    // while draw down Ncenter from status icon bar, start timer to display animate after pen up
    VfxPointTimeline *m_leaveTimeline;
    VfxFrame *m_bottom;        // Ncenter handle frame, "m_bottomRegion"?
    VfxImageFrame *m_bottomImage;      // handle icon, not the background image
    VcpSoftkey              *m_softkeybar;

    VfxS32 m_screen_id;
    VfxFrame *m_darkScreen; 
    VfxFrame *m_emptyFrame;  // for pen event handle
    VfxFrame *m_optionsMenu; 
    VfxImageFrame *m_optionsMenuBg;
    VfxImageFrame *m_optionsMenuHighlight;
    VfxTextFrame *m_optionsMenuText[VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM];
    VfxFrame *m_optionsMenuDivideLine[VAPP_NCENTER_OPTIONS_MENU_ITEM_NUM - 1];
    VfxS32 m_optionItemsNum;
    VfxS32 m_optionHighlightIndex;

    VfxFrame *m_popup; 
    VfxImageFrame *m_popupBg;
#if !defined(__MMI_BASIC_UI_STYLE__)
    VfxAnimImageFrame *m_popupIcon;
#endif
    VfxTextFrame *m_popupText;

    VfxS32 m_originY;          // Y-offset of "m_panel", for pen move handler
    VfxS32 m_topHeight;        // "m_topRegion" height
    VfxFrame* m_panelContent;  // List frame 
    VfxFrame* m_topRegion;     // Tab + status icon bar frame
    VfxFrame* m_bottomRegion;  // Ncenter handle frame

    VfxS32 m_bottomHeight;  // "m_bottomRegion" height

    VappQuickSettingCell *m_quickSettingCell; // Quick setting frame
    
    VfxBool m_disableLeave;
    VfxBool m_disableDrag;
    VfxBool m_isInCallBack;
    
    VfxWeakPtr <VappNCenterScr> m_ncenterScrPtr;
    VfxBool m_entered;
    VfxBool m_isDrag;
    VfxBool m_isOnAnim;

    VfxS32 m_popupHandle;
    VsrvNotification *m_popupNoti;
    /*
    vsrv_ngroup_handle m_ghandle;
    vsrv_notification_handle m_nhandle;
    */
    VfxId m_ongoingId;


protected:
    virtual void processRegisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target);
    virtual void processUnregisterAccessKeyHandler(VfxKeyCodeEnum keyCode, VfxControl *target);
    virtual void processUnregisterAllAccessKeyHandler(VfxControl *target);
    virtual VfxBool VappNCenter::processFocusKey(VfxKeyEvent &event);

// Variable
protected:
    // Access key manager.
    VfxAccessKeyMgr     *m_pAccessKeyMgr;    

    friend class VappNCenterScr;
};


#endif /* __VAPP_NCENTER_H__ */

#endif /* defined(__MMI_NCENTER_SUPPORT__) */

