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
 *  vapp_cal_reminder.h
 *
 * Project:
 * --------
 *  Cosmos
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
#ifndef __VAPP_CAL_REMINDER_H__
#define __VAPP_CAL_REMINDER_H__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"

extern "C"
{
    #include "todolistsrvgprot.h"
    #include "remindersrvgprot.h"
}

#include "vfx_app.h"
#include "vfx_app_scr.h"
#include "vfx_base_popup.h"
#include "vfx_datatype.h"
#include "vfx_page.h"
#include "vfx_main_scr.h"

#include "vapp_cal_prot.h"
#include "vfx_text_frame.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_320X480__)

    #define VAPP_CAL_REMINDER_POPUP_WIDTH               284
    #define VAPP_CAL_REMINDER_POPUP_HEIGHT              195
    #define VAPP_CAL_REMINDER_POPUP_TITLE_HEIGHT        10
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_X           66
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_Y           10
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_R_MARGIN    14
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_WIDTH   \
                    (VAPP_CAL_REMINDER_POPUP_WIDTH \
                    - VAPP_CAL_REMINDER_POPUP_SUBJECT_X\
                    - VAPP_CAL_REMINDER_POPUP_SUBJECT_R_MARGIN)
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_HEIGHT      50
    #define VAPP_CAL_REMINDER_POPUP_LOC_HEIGHT          20
    #define VAPP_CAL_REMINDER_POPUP_TIME_HEIGHT         20
    #define VAPP_CAL_REMINDER_POPUP_ICON_W_H            36
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_MARGIN       12
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_MID_MARGIN   3
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_WIDTH    \
                    ((VAPP_CAL_REMINDER_POPUP_WIDTH - 2 * VAPP_CAL_REMINDER_POPUP_BUTTON_MARGIN\
                    - VAPP_CAL_REMINDER_POPUP_BUTTON_MID_MARGIN) / 2)
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_HEIGHT       46
    #define VAPP_CAL_REMINDER_POPUP_STRNG_GAP           3
    #define VAPP_CAL_REMINDER_POPUP_BOTTOM_SHADOW       10
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_FONT VFX_FONT_DESC_VF_SIZE(19)
    #define VAPP_CAL_REMINDER_POPUP_LOC_FONT VFX_FONT_DESC_VF_SIZE(14)
    #define VAPP_CAL_REMINDER_POPUP_TIME_FONT VFX_FONT_DESC_VF_SIZE(14)

    #define VAPP_CAL_REMINDER_PAGE_SHADOW_H             135
    #define VAPP_CAL_REMINDER_CARD_W                    280
    #define VAPP_CAL_REMINDER_CARD_H                    140
    #define VAPP_CAL_REMINDER_CARD_SHADOW_UP_OFFSIZE    30
    #define VAPP_CAL_REMINDER_CARD_SHADOW_DOWN_OFFSIZE  20
    #define VAPP_CAL_REMINDER_CARD_TEXT_Y_OFFSIZE       24 
    #define VAPP_CAL_REMINDER_CARD_ARROW_UP_OFFSIZE     6  
    #define VAPP_CAL_REMINDER_CARD_ARROW_DOWN_OFFSIZE   18 
    #define VAPP_CAL_REMINDER_CARD_CONTENT_DOWN_OFFSIZE 5
    #define VAPP_CAL_REMINDER_UP_TEXT_FONT              VFX_FONT_DESC_VF_SIZE(20)
    
#elif defined(__MMI_MAINLCD_480X800__)

    #define VAPP_CAL_REMINDER_POPUP_WIDTH               400
    #define VAPP_CAL_REMINDER_POPUP_HEIGHT              195
    #define VAPP_CAL_REMINDER_POPUP_TITLE_HEIGHT        18
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_X           84
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_Y           5
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_R_MARGIN    18
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_WIDTH   \
                                (VAPP_CAL_REMINDER_POPUP_WIDTH \
                                - VAPP_CAL_REMINDER_POPUP_SUBJECT_X\
                                - VAPP_CAL_REMINDER_POPUP_SUBJECT_R_MARGIN)
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_HEIGHT      70
    #define VAPP_CAL_REMINDER_POPUP_LOC_HEIGHT          32
    #define VAPP_CAL_REMINDER_POPUP_TIME_HEIGHT         32
    #define VAPP_CAL_REMINDER_POPUP_ICON_W_H            45

    #define VAPP_CAL_REMINDER_POPUP_BUTTON_MARGIN       18
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_MID_MARGIN   6
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_WIDTH    \
                ((VAPP_CAL_REMINDER_POPUP_WIDTH - 2 * VAPP_CAL_REMINDER_POPUP_BUTTON_MARGIN\
                - VAPP_CAL_REMINDER_POPUP_BUTTON_MID_MARGIN) / 2)
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_HEIGHT       60
    #define VAPP_CAL_REMINDER_POPUP_STRNG_GAP           6
    #define VAPP_CAL_REMINDER_POPUP_BOTTOM_SHADOW       14
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_FONT        VFX_FONT_DESC_VF_SIZE(32)
    #define VAPP_CAL_REMINDER_POPUP_LOC_FONT            VFX_FONT_DESC_VF_SIZE(24)
    #define VAPP_CAL_REMINDER_POPUP_TIME_FONT           VFX_FONT_DESC_VF_SIZE(24)
    #define VAPP_CAL_REMINDER_PAGE_SHADOW_H             220 
    #define VAPP_CAL_REMINDER_CARD_W                    400
    #define VAPP_CAL_REMINDER_CARD_H                    220
    #define VAPP_CAL_REMINDER_CARD_SHADOW_UP_OFFSIZE    55
    #define VAPP_CAL_REMINDER_CARD_SHADOW_DOWN_OFFSIZE  40
    #define VAPP_CAL_REMINDER_CARD_TEXT_Y_OFFSIZE       40  
    #define VAPP_CAL_REMINDER_CARD_ARROW_UP_OFFSIZE     12  
    #define VAPP_CAL_REMINDER_CARD_ARROW_DOWN_OFFSIZE   30 
    #define VAPP_CAL_REMINDER_CARD_CONTENT_DOWN_OFFSIZE 30
    #define VAPP_CAL_REMINDER_UP_TEXT_FONT              VFX_FONT_DESC_VF_SIZE(30)

#elif (defined  __MMI_MAINLCD_240X320__ || defined  __MMI_MAINLCD_240X400__ )  

    #define VAPP_CAL_REMINDER_POPUP_WIDTH           222
    #define VAPP_CAL_REMINDER_POPUP_HEIGHT          160
    #define VAPP_CAL_REMINDER_POPUP_TITLE_HEIGHT    9
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_X       42
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_Y       8
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_R_MARGIN       8
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_WIDTH   \
                    (VAPP_CAL_REMINDER_POPUP_WIDTH \
                    - VAPP_CAL_REMINDER_POPUP_SUBJECT_X\
                    - VAPP_CAL_REMINDER_POPUP_SUBJECT_R_MARGIN)
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_HEIGHT  40
    #define VAPP_CAL_REMINDER_POPUP_LOC_HEIGHT      20
    #define VAPP_CAL_REMINDER_POPUP_TIME_HEIGHT     20
    #define VAPP_CAL_REMINDER_POPUP_ICON_W_H        28
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_MARGIN   10
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_MID_MARGIN   3
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_WIDTH    \
                    ((VAPP_CAL_REMINDER_POPUP_WIDTH - 2 * VAPP_CAL_REMINDER_POPUP_BUTTON_MARGIN\
                    - VAPP_CAL_REMINDER_POPUP_BUTTON_MID_MARGIN) / 2)
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_HEIGHT   35
    #define VAPP_CAL_REMINDER_POPUP_STRNG_GAP   3
    #define VAPP_CAL_REMINDER_POPUP_BOTTOM_SHADOW      8
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_FONT VFX_FONT_DESC_VF_SIZE(18)
    #define VAPP_CAL_REMINDER_POPUP_LOC_FONT VFX_FONT_DESC_VF_SIZE(13)
    #define VAPP_CAL_REMINDER_POPUP_TIME_FONT VFX_FONT_DESC_VF_SIZE(13)

    #if defined(__MMI_MAINLCD_240X320__)
        #define VAPP_CAL_REMINDER_PAGE_SHADOW_H             90   
        #define VAPP_CAL_REMINDER_CARD_H                    115
    #else
        #define VAPP_CAL_REMINDER_PAGE_SHADOW_H             120
        #define VAPP_CAL_REMINDER_CARD_H                    125
    #endif

    #define VAPP_CAL_REMINDER_CARD_W                    230
    #define VAPP_CAL_REMINDER_CARD_SHADOW_UP_OFFSIZE    20
    #define VAPP_CAL_REMINDER_CARD_SHADOW_DOWN_OFFSIZE  12
    #define VAPP_CAL_REMINDER_CARD_TEXT_Y_OFFSIZE       25 
    #define VAPP_CAL_REMINDER_CARD_ARROW_UP_OFFSIZE     4  
    #define VAPP_CAL_REMINDER_CARD_ARROW_DOWN_OFFSIZE   12 
    #define VAPP_CAL_REMINDER_CARD_CONTENT_DOWN_OFFSIZE 10
    #define VAPP_CAL_REMINDER_UP_TEXT_FONT              VFX_FONT_DESC_VF_SIZE(16)
    
#else //temp value

    #define VAPP_CAL_REMINDER_POPUP_WIDTH           284
    #define VAPP_CAL_REMINDER_POPUP_HEIGHT          195
    #define VAPP_CAL_REMINDER_POPUP_TITLE_HEIGHT    10
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_X       66
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_Y       10
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_R_MARGIN       14
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_WIDTH   \
                    (VAPP_CAL_REMINDER_POPUP_WIDTH \
                    - VAPP_CAL_REMINDER_POPUP_SUBJECT_X\
                    - VAPP_CAL_REMINDER_POPUP_SUBJECT_R_MARGIN)
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_HEIGHT  50
    #define VAPP_CAL_REMINDER_POPUP_LOC_HEIGHT      20
    #define VAPP_CAL_REMINDER_POPUP_TIME_HEIGHT     20
    #define VAPP_CAL_REMINDER_POPUP_ICON_W_H        36
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_MARGIN   12
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_MID_MARGIN   4
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_WIDTH    \
                    ((VAPP_CAL_REMINDER_POPUP_WIDTH - 2 * VAPP_CAL_REMINDER_POPUP_BUTTON_MARGIN\
                    - VAPP_CAL_REMINDER_POPUP_BUTTON_MID_MARGIN) / 2)
    #define VAPP_CAL_REMINDER_POPUP_BUTTON_HEIGHT   46
    #define VAPP_CAL_REMINDER_POPUP_STRNG_GAP   4
    #define VAPP_CAL_REMINDER_POPUP_BOTTOM_SHADOW      10
    #define VAPP_CAL_REMINDER_POPUP_SUBJECT_FONT VFX_FONT_DESC_VF_SIZE(19)
    #define VAPP_CAL_REMINDER_POPUP_LOC_FONT VFX_FONT_DESC_VF_SIZE(14)
    #define VAPP_CAL_REMINDER_POPUP_TIME_FONT VFX_FONT_DESC_VF_SIZE(14)

    #define VAPP_CAL_REMINDER_PAGE_SHADOW_H             135
    #define VAPP_CAL_REMINDER_CARD_W                    280
    #define VAPP_CAL_REMINDER_CARD_H                    140
    #define VAPP_CAL_REMINDER_CARD_SHADOW_UP_OFFSIZE    30
    #define VAPP_CAL_REMINDER_CARD_SHADOW_DOWN_OFFSIZE  20
    #define VAPP_CAL_REMINDER_CARD_TEXT_Y_OFFSIZE       24 
    #define VAPP_CAL_REMINDER_CARD_ARROW_UP_OFFSIZE     6  
    #define VAPP_CAL_REMINDER_CARD_ARROW_DOWN_OFFSIZE   18 
    #define VAPP_CAL_REMINDER_CARD_CONTENT_DOWN_OFFSIZE 5
    #define VAPP_CAL_REMINDER_UP_TEXT_FONT              VFX_FONT_DESC_VF_SIZE(16)

#endif

#define VAPP_CAL_REMINDER_INTERVAL  4
#define VAPP_CAL_REMINDER_SNOOZE_COUNT 10
#define VAPP_CAL_REMINDER_NOTI_TIME 30000
#define VAPP_CAL_REMINDER_CARD_MOVE_TIME 200

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef struct
{
    srv_tdl_vcal_enum type;
    VfxU16 expiriedIdx;
    srv_tdl_event_source_enum source_Id;	
    VfxU32 event_Id;

}VappCalRemInfoStruct;

enum VAPP_CAL_REMINDER_BTN_TYPE
{
    VAPP_CAL_REMINDER_SNOOZE,
    VAPP_CAL_REMINDER_DISMISS
};

enum VAPP_CAL_REMINDER_CARD_STATUS
{
    VAPP_CAL_REMINDER_CARD_MOVE_UP,
    VAPP_CAL_REMINDER_CARD_MOVE_DOWN,
    VAPP_CAL_REMINDER_CARD_NO_MOVE,
    VAPP_CAL_REMINDER_CARD_IS_CLICKED,
    VAPP_CAL_REMINDER_CARD_MOVE_TOTAL
};

extern "C"
{
    mmi_ret vapp_cal_reminder_notify_proc(mmi_event_struct *evt);    
#if defined(__MMI_TASK_APP__)
    mmi_ret vapp_cal_reminder_set_proc(mmi_event_struct *evt);
#endif
    mmi_ret vapp_cal_event_reminder_set_proc(mmi_event_struct *evt);
    mmi_ret vapp_cal_reminder_backlight_proc(mmi_event_struct *evt);
#ifndef  __LOW_COST_SUPPORT_COMMON__
    void vapp_cal_reminder_screen_lock_close();
#endif
}

/***************************************************************************** 
 * Class  VappCalReminderApp
 *****************************************************************************/
class VappCalReminderScreen;
class VappCalReminderCardScreen;
class VappCalReminderPopup;
class VappCalReminderCardPage;
class VappReminderCard;
class VappCalReminderApp : public VfxApp
{
    VFX_DECLARE_CLASS(VappCalReminderApp);
    
public:
    virtual void onRun(void* args, VfxU32 argSize);
    virtual void onDeinit();
    
    
    static void reinitReminder(srv_reminder_evt_struct *remdr_evt);
    
    static void expiriyHandler(srv_reminder_evt_struct *remdr_evt);
    
    static MMI_BOOL showReminder(mmi_scenario_id scen_id, void *arg);

    static void setReminder(
                        const srv_tdl_vcal_enum vcal_type, 
                        const void *data,
                        const U32 index);
    
    static srv_reminder_repeat_enum conv2ReminderRepeatRule(VAPP_CAL_REPEAT_ENUM repeat);
    
#ifdef __MMI_TASK_APP__
    static S32 reminderCompare(U32 exist, U32 curr);
#endif
    static VfxBool needPwrOff(void);
};

/***************************************************************************** 
 * Class  VappCalReminderScreen
 *****************************************************************************/
class VcpStatusIconBar;
class VappCalReminderScreen : public VfxAppScr
{

public:
    VappCalReminderScreen(){}
    VappCalReminderScreen(VappCalRemInfoStruct *arg) 
        : m_type(arg->type), m_eventId(arg->event_Id),m_sourceId(arg->source_Id)
    {
         setIsSmallScreen();
    }
public:
    virtual void onInit();
    virtual void onEnter(VfxBool isBackward);
    virtual void onRotate(const VfxScreenRotateParam &param);	
    virtual void onQueryRotateEx(VfxScreenRotateParam &param);

public:
    void popupLeave(VfxObject* sender, VfxId);
    
private:
    VappCalReminderPopup    *m_popup;
    VcpStatusIconBar	*m_statusBar;
    srv_tdl_vcal_enum       m_type;
    //VfxU16                  m_idx;
    VfxU32 m_eventId;
    srv_tdl_event_source_enum m_sourceId;
};


/***************************************************************************** 
 * Class  VappCalReminderPopup
 *****************************************************************************/
class VcpButton;
class VfxTimer;
class VfxKeyEvent;
class VappCalReminderPopup : public VfxBasePopup
{

public:
    VappCalReminderPopup();
    VappCalReminderPopup(srv_tdl_vcal_enum type, VfxU32 idx, srv_tdl_event_source_enum sourceId);


public:
    virtual void onInit();
    virtual VfxBool onKeyInput(VfxKeyEvent &event);
    virtual void onUpdate(void);
    
public:
    void onButtonClick(VfxObject *sender, VfxId id);
    void postponeReminder();
    void stopReminder();
    void onTimeOut(VfxTimer *obj);
    void adjustAlmType();

public:
   VfxSignal2 <VfxObject*, VfxId> m_signalPopupLeave; 

private:
    srv_tdl_vcal_enum   m_type;
    VfxU32   m_eventId;
    srv_tdl_event_source_enum m_sourceId;
    VcpButton           *m_lskBtn;
    VcpButton           *m_rskBtn;
    VfxU8              m_oldAlmType;
    VfxU8	m_snoozeValue;
};


#ifndef __LOW_COST_SUPPORT_COMMON__
/***************************************************************************** 
 * Class  VappCalReminderCardScreen
 *****************************************************************************/
class VappCalReminderCardScreen : public VfxMainScr
{
    VFX_DECLARE_CLASS(VappCalReminderCardScreen);
    
public:
    VappCalReminderCardScreen(){}
    VappCalReminderCardScreen(VappCalRemInfoStruct *arg)
      : m_type(arg->type), m_eventId(arg->event_Id),m_sourceId(arg->source_Id) {};
    
public:
    void on1stReady();
    void onDeinit();

public:
    void ReminderCardPageLeave(VfxObject* sender, VfxId id);
    void stopReminder();
    void postponeReminder();
    void onTimeOut(VfxTimer *obj);
    void adjustAlmType();
    
    srv_tdl_vcal_enum getType()
    {
        return m_type;
    }
  
    
    srv_tdl_event_source_enum getSourceId() const
    {
         return m_sourceId;
    }


    VfxU32  getEventId() const
    {
         return m_eventId;
    }
    
private:
    srv_tdl_vcal_enum       m_type;
    VfxU32                  m_eventId;
    srv_tdl_event_source_enum m_sourceId;
    VfxU8                   m_oldAlmType;
    VfxU8                   m_snoozeValue;
};


/***************************************************************************** 
 * Class  VappCalReminderCardPage
 *****************************************************************************/
class VappWallpaper;
class VfxPointTimeline;
class VfxBaseTimeline;
class VcpBubbleEffect;
class VfxTextFrame;
class VfxImageFrame;
class VfxPenEvent;
class VappCalReminderCardPage : public VfxPage
{
    VFX_DECLARE_CLASS(VappCalReminderCardPage);
    
public:
    VappCalReminderCardPage();
    
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onEnter(VfxBool isBackward);
    virtual VfxBool onPenInput(VfxPenEvent &event);
    virtual mmi_ret onProc(mmi_event_struct *evt);   
    virtual void onBack();
    VfxBool onKeyInput(VfxKeyEvent & event);
    
private:
    void penDownHandler(VfxPoint &pos);
    void penUpHandler(VfxPoint &pos);
    void resetCard(void);
    void penMoveHandler(VfxPenEvent &event);
    void onTimeLineStop(VfxBaseTimeline *timeline, VfxBool is_stop);
    void setTextAndArrowOpacity(VAPP_CAL_REMINDER_CARD_STATUS status);
    
public:
    void addCard(VappReminderCard *card);
public:
    VfxSignal2 <VfxObject*, VfxId> m_signalDrag; 

public:
    VfxS32 pageH;
    VfxS32 pageW;
    
private:
    VfxPointTimeline *m_cardMoveTimeLine;
    VcpBubbleEffect *m_bubbleEffectUp;
    VcpBubbleEffect *m_bubbleEffectDown;
    VappWallpaper *m_wallpaper;
    VappReminderCard *m_card;
    VfxBool m_isMoveUp;
    VfxBool m_isCardTaped;
    VfxTextFrame *m_upText;
    VfxTextFrame *m_downText;
    VfxImageFrame *m_upArrow;
    VfxImageFrame *m_downArrow;
};


/***************************************************************************** 
 * Class  VappReminderCard
 *****************************************************************************/
class VappReminderCard : public VfxControl
{
    VFX_DECLARE_CLASS(VappReminderCard);
        
public:
    VappReminderCard() {};
    

public:
    void setCardStatus(VAPP_CAL_REMINDER_CARD_STATUS status);
    VfxFrame* getCard();

    virtual VfxBool isMovable(const VfxS32 &disable) { return VFX_TRUE; }
    virtual void stopVib(void){}

protected:
    virtual void onInit();
    virtual VfxBool onContainPoint(const VfxPoint & point);

    virtual VfxBool onKeyInput(VfxKeyEvent & event);
    virtual void onUpdate();

protected:
    
    VfxImageFrame *m_cardShadowUp;
    VfxImageFrame *m_cardShadowDown;
    VfxImageFrame *m_cardShadowMid;

    VfxImageFrame *m_cardFrame;

    VfxImageFrame *m_upArrow;
    VfxImageFrame *m_downArrow;
};


/***************************************************************************** 
 * Class  VappCalReminderCard
 *****************************************************************************/
class VappCalReminderContent;
class VappCalReminderCard : public VappReminderCard
{
    VFX_DECLARE_CLASS(VappCalReminderCard);
            
public:
    VappCalReminderCard() : m_content(NULL) {};
    

    VfxBool isMovable(const VfxS32 &operation);

protected:
    virtual void onInit();

private:
    VappCalReminderContent *m_content;
};
#endif


/***************************************************************************** 
 * Class  VappCalReminderContent
 *****************************************************************************/
class VappCalReminderContent : public VfxFrame
{
    
public:
    VappCalReminderContent(){};

    VappCalReminderContent(srv_tdl_vcal_enum type, VfxU32 idx,srv_tdl_event_source_enum source_Id) : m_type(type),m_eventId(idx),m_sourceId(source_Id){};
    
public:
    virtual void onInit();
    
    static void getReminderDateTimeStr(
                                            srv_tdl_vcal_enum type,
                                            const void* dataPtr,
                                            VfxWString &subBuf);
    
    static void getEventReminderDateTimeStr(const srv_tdl_event_short_struct* pEvent,VfxWString &subBuf);
    
#ifndef __LOW_COST_SUPPORT_COMMON__
    VfxBool isMovable(const VfxS32 &operation);
    void setSubjectColor(VfxColor color);    
#endif

public:
    srv_tdl_vcal_enum       m_type;
    VfxU32   m_eventId;
    srv_tdl_event_source_enum m_sourceId;

    VfxU8	m_snoozeValue;
    VfxTextFrame *m_subjText;
};

#endif //__VAPP_CAL_REMINDER_H__


