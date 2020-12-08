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
 *  vapp_widget_sns_viewer.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the viewer of the SNS sticky widget.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef VAPP_WIDGET_SNS_VIEW_H
#define VAPP_WIDGET_SNS_VIEW_H

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#if defined(__MMI_VUI_HOMESCREEN_SNS__)
#if defined(__MMI_VUI_WIDGET_SNS_STICKY__)

#include "vcp_include.h"
#include "vapp_widget_def.h"
#include "vapp_widget.h"
#include "vapp_sns_base.h"
#include "vapp_widget_sns_agent.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
#define VAPP_WIDGET_SNS_FADE_OUT_TIME                   300
#define VAPP_WIDGET_SNS_FADE_IN_TIME                    300
#define VAPP_WIDGET_SNS_MAX_SLIDE_SHOW_FRAME    3
#define VAPP_WIDGET_SNS_MAX_IMAGE_FRAME         (VAPP_WIDGET_SNS_MAX_SLIDE_SHOW_FRAME+1)
#if (defined(__MMI_MAINLCD_480X800__) || defined(__MMI_MAINLCD_320X480__))
#define VAPP_WIDGET_SNS_RANDOM_X_RANGE            10
#else
#define VAPP_WIDGET_SNS_RANDOM_X_RANGE            5
#endif
#define VAPP_WIDGET_SNS_RANDOM_Y_RANGE            3
#define VAPP_WIDGET_SNS_PANEL_ORI_POS_X                 50
#define VAPP_WIDGET_SNS_PANEL_ORI_POS_Y                 50
#define VAPP_WIDGET_SNS_FRAME_POS_X               5
#define VAPP_WIDGET_SNS_FRAME_POS_Y               5
/***************************************************************************** 
 * VappWidgetSnsViewerPanel
 *****************************************************************************/
class VappWidgetSnsViewerPanel : public VfxFrame
{
    VFX_DECLARE_CLASS(VappWidgetSnsViewerPanel);
    
// Constructor
public:
    VappWidgetSnsViewerPanel();
    enum {

#if defined(__MMI_MAINLCD_320X480__)
        CARD_WIDTH = 284,
        CARD_HEIGHT = 133,
        TOP_MARGIN = 6,
        RIGHT_MARGIN = 8,
        LEFT_MARGIN = 8,
        TOP_OFFSET = 8,
        BOTTOM_MARGIN = 1,
        BOTTOM_OFFSET = 7,
        LEFT_OFFSET = 8,
        RIGHT_OFFSET = 8,
        NAME_HEIGHT = 50,
        NAME_X = 15,
        NAME_Y = 8,
        NAME_FONT_SIZE = 20,
        MESSAGE_X = 15,
        MESSAGE_Y = 33,
        MESSAGE_FONT_SIZE = 14,
        MESSAGE_LINE_NUM = 4,
        PIC_WIDTH = 120,
        PIC_HEIGHT = 70,
        DATE_WIDTH = 100,
        DATE_HEIGHT = 15,
        DATE_X = 15,     
        DATE_FONT_SIZE = 14,
        INDEX_WIDTH = 30,
        INDEX_HEIGHT = 15,
        USER_PIC_WIDTH = 130,       
        USER_PIC_Y = 1,
        SNS_ICON_WIDTH = 24,
        SNS_ICON_HEIGHT = 24,
#elif defined(__MMI_MAINLCD_480X800__)
        CARD_WIDTH = 426,
        CARD_HEIGHT = 203,
        TOP_MARGIN = 1,
        RIGHT_MARGIN = 12,
        LEFT_MARGIN = 12,
        TOP_OFFSET = 14,
        BOTTOM_MARGIN = 15,
        BOTTOM_OFFSET = 14,
        LEFT_OFFSET = 14,
        RIGHT_OFFSET = 20,
        NAME_HEIGHT = 50,
        NAME_X = 25,
        NAME_Y = 18,
        NAME_FONT_SIZE = 30,
        MESSAGE_X = 25,
        MESSAGE_Y = 60,
        MESSAGE_FONT_SIZE = 21,
        MESSAGE_LINE_NUM = 4,
        PIC_WIDTH = 120,
        PIC_HEIGHT = 90,        
        DATE_WIDTH = 100,
        DATE_HEIGHT = 15,
        DATE_X = 25,
        DATE_FONT_SIZE = 18,
        INDEX_WIDTH = 30,
        INDEX_HEIGHT = 15,       
        USER_PIC_WIDTH = 183,
        USER_PIC_Y = 1,
        SNS_ICON_WIDTH = 32,
        SNS_ICON_HEIGHT = 32,
#else
        CARD_WIDTH = 220,
        CARD_HEIGHT = 102,
        TOP_MARGIN = 3,
        RIGHT_MARGIN = 8,
        LEFT_MARGIN = 6,
        TOP_OFFSET = 5,
        BOTTOM_MARGIN = 4,
        BOTTOM_OFFSET = 3,
        LEFT_OFFSET = 5,
        RIGHT_OFFSET = 5,
        NAME_HEIGHT = 50,
        NAME_X = 10,
        NAME_Y = TOP_OFFSET,
        NAME_FONT_SIZE = 18,
        MESSAGE_X = 10,
        MESSAGE_Y = 30,
        MESSAGE_LINE_NUM = 3,
        MESSAGE_FONT_SIZE = 13,
        PIC_WIDTH = 90,
        PIC_HEIGHT = 50,
        
        DATE_WIDTH = 100,
        DATE_HEIGHT = 15,
        DATE_X = 10,
        DATE_FONT_SIZE = 13,
        INDEX_WIDTH = 30,
        INDEX_HEIGHT = 15,
        
        USER_PIC_WIDTH = 107,
       
        USER_PIC_Y = 1,
        SNS_ICON_WIDTH = 20,
        SNS_ICON_HEIGHT = 20,
#endif      
        MESSAGE_HEIGHT = CARD_HEIGHT - 2 * MESSAGE_Y,
        MSG_AFTER_PIC_X = MESSAGE_X + PIC_WIDTH + LEFT_OFFSET + LEFT_MARGIN,
        MSG_AFTER_PIC_WIDTH = CARD_WIDTH - MSG_AFTER_PIC_X - RIGHT_OFFSET - RIGHT_MARGIN,
        DATE_Y = CARD_HEIGHT - BOTTOM_OFFSET - DATE_HEIGHT - BOTTOM_MARGIN,
        INDEX_X = CARD_WIDTH - RIGHT_OFFSET - INDEX_WIDTH - RIGHT_MARGIN,
        INDEX_Y = CARD_HEIGHT - BOTTOM_OFFSET - INDEX_HEIGHT - BOTTOM_MARGIN,
        USER_PIC_HEIGHT = CARD_HEIGHT - BOTTOM_MARGIN - TOP_MARGIN,
        USER_PIC_X = CARD_WIDTH - USER_PIC_WIDTH - RIGHT_MARGIN,
        SNS_ICON_X = CARD_WIDTH - RIGHT_MARGIN - SNS_ICON_WIDTH - RIGHT_OFFSET,
        SNS_ICON_Y = TOP_OFFSET,
        MESSAGE_WIDTH = CARD_WIDTH - 2 * MESSAGE_X,
        NAME_WIDTH = SNS_ICON_X - RIGHT_MARGIN - NAME_X,
    };

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Method
public: 
    void setPanelId(VfxS32 id);
    VfxS32 getPanelId() const;
    void setActivityIndex(VfxS32 id, VfxS32 total);
    VfxS32 getActivityIndex() const;
    void setPrepared(VfxBool isPrepared);
    VfxBool getIsPrepared();
    void setPic(VfxWString path, VappSnsItemUpdatedTypeEnum type);
    VfxBool isDefaultPic();
    void setBackgroundPic();
    void clear();
    void setRotation(const VfxFloat degree);
    void setActivityContent(srv_sns_activity_struct *activity, VfxFileRawData &icon);
    void* getActivityContent();

    void showErrorString(VfxResId id);
    void hideErrorString();  

	void showLoading();

	void hideLoading();
    
    VfxBool isLoading();

#ifdef __LOW_COST_SUPPORT_COMMON__
    void hideContent(VfxBool hide);
#endif

    VfxWString &getTimeString(VfxU32 timestamp, VfxDateTime &date, VfxU32 flag = VFX_DATE_TIME_FORMAT_AUTO_DETECT_DATE_DISPLAY);
    
public:
    VfxBool m_isPanelPrepared;
    VfxS32  m_panelId;
    VfxS32  m_activity_index;
    VfxTextFrame *m_name;
	VfxTextFrame *m_message;
	VfxTextFrame *m_date;
    VfxTextFrame *m_index;
    VfxTextFrame *m_errorStr;
#ifndef __LOW_COST_SUPPORT_COMMON__    
    VfxFrame *m_user_pic;
#endif
    VfxImageFrame *m_snsIcon;
    VfxFrame  *m_pic;
	VcpActivityIndicator *m_indicator;
    srv_sns_activity_struct *m_activity;
};

/***************************************************************************** 
 * VappWidgetSnsViewer
 *****************************************************************************/
class VappWidgetSnsViewer : public VfxControl
{
    VFX_DECLARE_CLASS(VappWidgetSnsViewer);

private:
// State enum
    enum State {
        STATE_INIT,
        STATE_LOADING,
        STATE_RUNNING,
        STATE_NO_ACCOUNTS,
        STATE_NO_FRIENDS,
        STATE_IN_MS_MODE,
        STATE_MEMORY_CARD_PLUGGED_OUT,
        STATE_ERROR,
        STATE_NOT_READY,
        STATE_STOPPED,
    };

    enum {
            MOUSE_MOVE_THRESHHOLD = 20,
    };

    enum Motion {
        MOTION_TO_NEXT,
        MOTION_TO_PREV,
    };

// Constructor
public:
    VappWidgetSnsViewer();

// Override
protected:
    virtual void onInit();
    virtual void onDeinit();

// Method
public: 

    void changeToNextActivity();
    void changeToPrevActivity();

	// record current pic id for SerializeView
	VfxS32 getFadeoutPicId();
    
    void onRestoreView();

    void onSerializeView();

    void autoRefresh(VfxTimer* pTimer);

   // static mmi_ret eventHandler(mmi_event_struct *event);

private:

        
    virtual VfxBool onPenInput(VfxPenEvent & event);  
    
    void resetPanelPos(VappWidgetSnsViewerPanel *panel);

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
    
    void prepareDefaultPanel(VappWidgetSnsViewerPanel *panel, VfxS32 picIndex);
    void preparePanel(VappWidgetSnsViewerPanel *panel, VfxS32 picIndex, srv_sns_activity_struct *activity);

    void setActivityToPanel(VappWidgetSnsViewerPanel *panel, VfxS32 picIndex, srv_sns_activity_struct *activity);

    void resetViewer();

    void refreshViewer();

    void tlFadeOutStoppedHandler(
        VfxBaseTimeline *timeline, 
        VfxBool isCompleted
    );

    void tlFadeInStoppedHandler(
        VfxBaseTimeline *timeline, 
        VfxBool isCompleted
    );

    VfxS32 getNextAvailablePanelId();
    VfxS32 getFadeOutPanelId();
    VfxS32 getFadeInPanelId();
    VappWidgetSnsViewerPanel* getNextAvailablePanel();
    VappWidgetSnsViewerPanel* getPanelById(VfxS32 id);

    VfxS32 getPanelIdAfterIndex(VfxS32 index);
    VfxS32 getPanelIdBeforeIndex(VfxS32 index);
    void onFadeOutFinished(VfxFrame *frame, VfxBool isComplete);
    void panelAppearingControlHandler();

	void showDefaultPic();

    // rotate panel with random deg. and translate panel with random offset
    void transformPanel(VappWidgetSnsViewerPanel* panel);

    // get next picture index
    VfxS32 getNextActivityId();
    VfxS32 getPrevActivityId();
/*
    void onUSBEnterMS();
    void onUSBExitMS();
    void onMemoryCardPlugInOut(mmi_event_struct *event);
*/
// Variable
public:

    // used to determined the rotation direction, clockwise or anticlockwise
    VfxBool m_rotateDirFlag;
    
    VfxS32 m_nextLockPicId;

    VfxS32 m_fadeOutPanelId;
    VfxS32 m_fadeInPanelId;

    // after lock image, it will assign to m_nextPanelId
    VfxS32 m_nextAvailablePanelId;

	VfxS32 m_usedPanelNum;  

    VfxS32 m_totalPanelNum;    

    VfxS32 m_maxConcurrentShowingPanelNum;

    // used to control white arrow animation
    VfxFloatTimeline *m_tlFrameFadeOut;

    // used to control white arrow animation
    VfxFloatTimeline *m_tlFrameFadeIn;

    VcpFrameEffect *m_fadeOutEffect;
    VcpFrameEffect *m_fadeInEffect;

    VfxTimer *m_refreshTimer;

    State m_state;

    Motion m_motion;

    Motion m_lastMotion;

    VappWidgetSnsViewerPanel *m_picPanel[VAPP_WIDGET_SNS_MAX_IMAGE_FRAME];

    VappSnsWidgetAgent *m_agent;
	
    VfxS32 m_listId;
    
    VfxS32 m_count;
    
    VfxS32 m_currentActivityIndex;  // activity index
    
    VfxS32 m_currentPanelIndex;

    VfxBool m_refresh;

    VfxS32 m_last_y;
    VfxBool m_moving;

    VfxBool m_launchApp;

    VfxBool m_serialized;

    VfxS32 m_lastError;

};

#endif /* __MMI_VUI_WIDGET_SNS_STICKY__ */
#endif /* __MMI_VUI_HOMESCREEN_SNS__ */
#endif /* VAPP_WIDGET_SNS_VIEW_H */
