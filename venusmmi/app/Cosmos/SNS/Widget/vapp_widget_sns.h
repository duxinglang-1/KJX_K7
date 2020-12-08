/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  vapp_widget_sns.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the sns widget.
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
#ifndef VAPP_WIDGET_SNS_H
#define VAPP_WIDGET_SNS_H

#include "MMI_features.h"
#if defined(__MMI_VUI_HOMESCREEN_SNS__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"
#include "vapp_sns_base.h"
#include "vapp_widget_sns_view.h"
#include "vapp_widget_sns_agent.h"
#include "vapp_widget_sns_cp.h"
#include "vcp_async_image_frame.h"


class VappWidgetSns : public VfxApp
{
    VFX_DECLARE_CLASS(VappWidgetSns);

// Override
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual mmi_ret onProc(mmi_event_struct *evt);
protected:
	virtual VfxBool onScrBack(VfxAppScr *scr);
private:
	VfxU16 m_type;
    pageInformation m_info;
};

class VappWidgetSnsScrn : public VfxMainScr
{
     VFX_DECLARE_CLASS(VappWidgetSnsScrn);
public:
    VappWidgetSnsScrn();

    VappWidgetSnsScrn(pageInformation *info);
    
    virtual void on1stReady();

protected:
	//virtual void processEnter(VfxBool isBackward, VfxScrRotateTypeEnum rotateType);
	virtual void onEnter(VfxBool isBackward);

    virtual void onEntered(VfxBool isBackward);
private:
    pageInformation *m_info;
};

/*****************************************************************************
 * Clock Widget
 *****************************************************************************/
enum VappSnsWidgetTypeEnum
{
	SNS_WIDGET_STYLE_STICKY,
	SNS_WIDGET_STYLE_TABBAR,
};

#if defined (__MMI_VUI_WIDGET_SNS_STICKY__)

class VappWidgetSnsSticky : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetSnsSticky);

public:
    enum
    {
        HORIZ_TILE_NUM = 4,
        VERTI_TILE_NUM = 3,

#ifdef __MMI_MAINLCD_320X480__
        WIDTH = 300,
        HEIGHT = 240,
        EDIT_BUTTON_OFFSET_X = WIDTH - 10,
        EDIT_BUTTON_OFFSET_Y = 5, 
#elif defined(__MMI_MAINLCD_480X800__)
        WIDTH = 460,
        HEIGHT = 370,
        EDIT_BUTTON_OFFSET_X = WIDTH - 25,
        EDIT_BUTTON_OFFSET_Y = 5,
#else
        WIDTH = 220,
        HEIGHT = 140,
        EDIT_BUTTON_OFFSET_X = WIDTH - 10,
        EDIT_BUTTON_OFFSET_Y = 15,
#endif
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetSnsSticky();

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);
    
public:
// Overide
public:
    virtual void onCreateView();

    virtual void onReleaseView();

    VappWidgetSnsViewer* getSnsViewer();

 // Override
protected:

    virtual void onSerializeView(VfxArchive *ar);

    virtual void onRestoreView(VfxArchive *ar);

    virtual void onTap(const VfxPoint &pos);
    
    virtual VfxPoint onGetEditButtonOffset();
  

private:
    // Get time string
    VfxWString &getTimeString(
        VfxU32 timestamp,
        VfxDateTime &date,
        VfxU32 flag = VFX_DATE_TIME_FORMAT_AUTO_DETECT_DATE_DISPLAY
    );

private:

    VfxFloatTimeline *m_Timeline;
    VappWidgetSnsViewer *m_snsViewer;

    VfxBool m_isPopup;


};
#endif

#if defined (__MMI_VUI_WIDGET_SNS_TABBAR__)

class VappWidgetSnsTabBar : public VappWidget
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidgetSnsTabBar);

public:

    enum type {
        TYPE_SELECTED,
        TYPE_ADDED,
        TYPE_REMOVED,
    };
    
    enum state {
        STATE_INIT,
        STATE_LOADING,
        STATE_RUNNING,
        STATE_NO_ACCOUNTS,
        STATE_NO_FRIENDS,
        STATE_NOT_READY,
        STATE_IN_MS_MODE,
        STATE_MEMORY_CARD_PLUGGED_OUT,
        STATE_ERROR,
        STATE_STOPPED,
    };
    
    enum
    {
        MAX_SELECTED_FIRENDS = 5,
        HORIZ_TILE_NUM = 4,
        VERTI_TILE_NUM = 3,

#if defined(__MMI_MAINLCD_320X480__)
        WIDTH = 295,
        HEIGHT = 209,
        BOTTOM_MARGIN = 8,
        LEFT_MARGIN = 3,
        RIGHT_MARGIN = 3,
        LEFT_OFFSET = 8,
        RIGHT_OFFSET = 8,
        BOTTOM_OFFSET = 5,
        TAB_HEIGHT = 57,
        BG_HEIGHT = 207,        
        IND_WIDTH = 60,
        IND_HEIGHT = 60,
        SNS_ICON_WIDTH = 24, 
        SNS_ICON_HEIGHT = 24,        
        SNS_ICON_Y = TAB_HEIGHT + 5,
        SETTING_WIDTH = 68,
        SETTING_HEIGHT = 36,
        NAME_Y = TAB_HEIGHT + 5,
        NAME_HEIGHT = 25,
        NAME_FONT_SIZE = 20,        
        MESSAGE_Y = NAME_Y + NAME_HEIGHT + 5,
        MESSAGE_HEIGHT = 60,
        MESSAGE_FONT_SIZE = 14,
        PIC_Y = NAME_Y + NAME_HEIGHT + 0,
        PIC_WIDTH = 120,
        PIC_HEIGHT = 80,
        DATE_WIDTH = 100,
        DATE_HEIGHT = 20,
        DATE_FONT_SIZE = 14,
        ERROR_HEIGHT = 30,
        ERROR_FONT_SIZE = 14,   
        EDIT_BUTTON_OFFSET_X = WIDTH - 15,
#elif defined(__MMI_MAINLCD_480X800__)
        WIDTH = 438,
        HEIGHT = 289,
        BOTTOM_MARGIN = 17,
        LEFT_MARGIN = 6,
        RIGHT_MARGIN = 6,
        LEFT_OFFSET = 14,
        RIGHT_OFFSET = 14,
        BOTTOM_OFFSET = 10,
        TAB_HEIGHT = 84,
        BG_HEIGHT = 277,        
        IND_WIDTH = 90,
        IND_HEIGHT = 90,
        SNS_ICON_WIDTH = 32, 
        SNS_ICON_HEIGHT = 32,        
        SNS_ICON_Y = TAB_HEIGHT + 10,
        SETTING_WIDTH = 90,
        SETTING_HEIGHT = 46,
        NAME_Y = TAB_HEIGHT + 10,
        NAME_HEIGHT = 30,
        NAME_FONT_SIZE = 30,        
        MESSAGE_Y = NAME_Y + NAME_HEIGHT + 10,
        MESSAGE_HEIGHT = 120,
        MESSAGE_FONT_SIZE = 21,
        PIC_Y = NAME_Y + NAME_HEIGHT + 10,
        PIC_WIDTH = 120,
        PIC_HEIGHT = 90,
        DATE_WIDTH = 100,
        DATE_HEIGHT = 20,
        DATE_FONT_SIZE = 18,
        ERROR_HEIGHT = 30,
        ERROR_FONT_SIZE = 21,  
        EDIT_BUTTON_OFFSET_X = WIDTH - 10,
#else
        WIDTH = 240,
        HEIGHT = 170,
        BOTTOM_MARGIN = 5,
        LEFT_MARGIN = 6,
        RIGHT_MARGIN = 5,
        LEFT_OFFSET = 10,
        RIGHT_OFFSET = 10,
        BOTTOM_OFFSET = 6,
        TAB_HEIGHT = 47,
        BG_HEIGHT = 170,        
        IND_WIDTH = 40,
        IND_HEIGHT = 40,
        SNS_ICON_WIDTH = 20, 
        SNS_ICON_HEIGHT = 20,        
        SNS_ICON_Y = TAB_HEIGHT + 5,
        SETTING_WIDTH = 64,
        SETTING_HEIGHT = 32,
        NAME_Y = TAB_HEIGHT + 8,
        NAME_HEIGHT = 20,
        NAME_FONT_SIZE = 18,        
        MESSAGE_Y = NAME_Y + NAME_HEIGHT,
        MESSAGE_HEIGHT = 120,
        MESSAGE_FONT_SIZE = 13,
        PIC_Y = NAME_Y + NAME_HEIGHT + 5,
        PIC_WIDTH = 90,
        PIC_HEIGHT = 60,
        DATE_WIDTH = 100,
        DATE_HEIGHT = 15,
        DATE_FONT_SIZE = 13,
        ERROR_HEIGHT = 30,
        ERROR_FONT_SIZE = 21,
        EDIT_BUTTON_OFFSET_X = WIDTH - 15,
#endif
        BG_Y = HEIGHT - BG_HEIGHT,
        SNS_ICON_X = WIDTH - RIGHT_OFFSET - SNS_ICON_WIDTH,
        SETTING_Y = HEIGHT - BOTTOM_OFFSET - SETTING_HEIGHT - BOTTOM_MARGIN,
        SETTING_X = WIDTH - RIGHT_OFFSET - SETTING_WIDTH,
        NAME_X = LEFT_MARGIN + LEFT_OFFSET,
        NAME_WIDTH = SNS_ICON_X - NAME_X - LEFT_MARGIN - RIGHT_MARGIN,
        MESSAGE_X = LEFT_OFFSET + LEFT_MARGIN,
        MESSAGE_WIDTH = WIDTH - LEFT_OFFSET - RIGHT_OFFSET - LEFT_MARGIN - RIGHT_MARGIN,
        MSG_AFTER_PIC_X = MESSAGE_X + PIC_WIDTH + LEFT_OFFSET + LEFT_MARGIN,
        MSG_AFTER_PIC_WIDTH = WIDTH - MESSAGE_X - PIC_WIDTH - LEFT_OFFSET - RIGHT_OFFSET - LEFT_MARGIN - RIGHT_MARGIN,
        DATE_X = LEFT_OFFSET + LEFT_MARGIN,
        DATE_Y = HEIGHT - BOTTOM_OFFSET - DATE_HEIGHT - BOTTOM_MARGIN,
        ERROR_WIDTH = WIDTH - LEFT_OFFSET - RIGHT_OFFSET,
        ERROR_X = LEFT_OFFSET,
        ERROR_Y = (HEIGHT - TAB_HEIGHT - ERROR_HEIGHT)/2,
        
    };

// Constructor / Destructor
public:
    // Default constructor
    VappWidgetSnsTabBar();

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;

    virtual VfxFrame *createIcon(VfxObject *parentObj);

    VappSnsWidgetAgent *getAgent();
public:

// Overide
public:
    virtual void onCreateView();

    virtual void onReleaseView();

    void showHideActivityContent(VfxBool show);

    void autoRefresh(VfxTimer* pTimer);

  //  static mmi_ret eventHandler(mmi_event_struct *event);
    
// Override
protected:
    virtual void onSerializeView(VfxArchive *ar);

    virtual void onRestoreView(VfxArchive *ar);

    virtual void onTap(const VfxPoint &pos);

    virtual VfxPoint onGetEditButtonOffset();

    void onTabSwitched(VfxObject *obj, VfxId tabId);

    // Item updated
    // Please override this function to handle item updated event
    void onItemUpdated(
        VfxS32 listId,
        VfxU16 index, 
        VappSnsItemUpdatedTypeEnum type, 
        VfxWChar *path
    );

    // Load callback 
    // Please override this function to handle load callback event
    void onGetLoadResults(
        VfxS32 listId, 
        VfxU16 total, 
        VfxS16 startIndex, 
        VfxS16 endIndex
    );

    void onSrvStatusChanged(
        VfxBool ready, 
        srv_sns_result err_code, 
        VfxU32 listId
    );

    // on button clicked, emit tab switch event
    void onButtonClicked (VfxObject* sender, VfxId Id);

private:

    VfxBool checkCurrentState();
    
    // Get time string
    VfxWString &getTimeString(
        VfxU32 timestamp,
        VfxDateTime &date,
        VfxU32 flag = VFX_DATE_TIME_FORMAT_AUTO_DETECT_DATE_DISPLAY
    );

    void initObjects();

    static void *memAllocator(
        VfxU32 size, 
        void *userData
    );

    static void memDeallocator(
        void *mem, 
        void *userData
    );

 //   void onUSBEnterMS();
 //   void onUSBExitMS();
 //   void onMemoryCardPlugInOut(mmi_event_struct *event);
    void resetView();

private:

    VappSnsWidgetAgent *m_agent;
	VfxTextFrame *m_name;
	VfxTextFrame *m_message;
    VfxTextFrame *m_error;
	VfxTextFrame *m_date;

    VcpActivityIndicator *m_actInd;
	VfxFrame *m_bg;
    VappSnsWidgetTabBarCp *m_tab_bar;
    VcpButton *m_setting;
    VfxS32 m_activityListId[MAX_SELECTED_FIRENDS];
    VfxS32 m_memberListId;
    VfxS32 m_lastError;
    VfxU16 m_count;
    VfxU16 m_activityCount[MAX_SELECTED_FIRENDS];
    VfxU16 m_loadedCount;  // loaded activity list count
    VfxId m_highlightId;
    state m_state;
    srv_sns_activity m_activity[MAX_SELECTED_FIRENDS];
    VfxImageFrame *m_providerIcon;
    VcpAsyncImageFrame *m_async_pic;
    VfxTimer        *m_refreshTimer;
    VfxBool m_launchApp;
    VfxBool m_serialized;
    VfxBool m_refresh;
    VfxBool m_isPopup;
    srv_sns_user_list_struct m_selectedUsers[MAX_SELECTED_FIRENDS];
};
#endif /* __MMI_VUI_WIDGET_SNS_TABBAR__ */

#endif /* VAPP_WIDGET_SNS_H */
#endif /* __MMI_VUI_HOMESCREEN_SNS__ */
