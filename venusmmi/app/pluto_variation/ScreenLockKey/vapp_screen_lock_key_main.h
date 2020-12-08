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
 *  vapp_screen_lock_key_main.h
 *
 * Project:
 * --------
 *  MAUI
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_SCREEN_LOCK_KEY_MAIN_H
#define VAPP_SCREEN_LOCK_KEY_MAIN_H

#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_screen_lock_key_def.h"
#include "vapp_launcher_key_clock.h"
#include "vapp_screen_lock_key_unlockitem.h"
#include "vapp_screen_lock_key_arrow.h"
#include "vapp_screen_lock_key_factory.h"
#if defined(__MMI_NCENTER_SUPPORT__)
#include "vapp_screen_lock_key_notification.h"
#endif
#include "vapp_wallpaper.h"
#include "vcp_status_icon_bar.h"

#include "vfx_input_event.h"


/*****************************************************************************
 * VappScreenLockKeyMain
 *****************************************************************************/

class VappScreenLockKeyMain : public VfxAppCatScr
{
    VFX_DECLARE_CLASS(VappScreenLockKeyMain);

/*----------------------------------------------------------------*/
/* Functions                                                      */
/*----------------------------------------------------------------*/

public:

    VappScreenLockKeyMain() :
        m_isCentryTapped(VFX_FALSE),
    #ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
        m_isUnlockSelected(VFX_FALSE),
        m_isPenMoved(VFX_FALSE),
    #else
        m_isTapCentryCard(VFX_FALSE),
        m_isTapUnlockCard(VFX_FALSE),
    #endif
        m_centryMoveDirection(VAPP_SCREEN_LOCK_KEY_UNLOCK_TOTAL),
        m_state(VAPP_SCREEN_LOCK_KEY_STATE_EXIT)        
    {
        
    }

public:

    VappScreenLockKeyStateEnum getState();

    void enterScreenLockState(
        VappScreenLockKeyStateEnum state
    );

    void closeScreenLock();

    void switchBacklight(
        VfxBool isOn
    );

    void onResumeWallpaper(
        VfxTimer *timer
    );

    static mmi_ret systemEventHdlr(
        mmi_event_struct *event
    );

    void lcdSleepInHdlr();

    void lcdSleepOutHdlr();

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
    mmi_ret onKeyInputDragUnlock(
        VfxKeyEvent & event
    );
#endif

    void onSlideOver(
        VfxBaseTimeline * timeline,
        VfxBool isComplete
    );

private:

    void createWallpaper();

    void destroyWallpaper();

    void createStatusIconBar();

    void createClock();
#if defined(__MMI_NCENTER_SUPPORT__)
    void createNotification();
#endif
    void createUnlock();

    void connectSignals();

    VfxBool isBacklightOn();

    void setBacklight();

    void resetBacklight();

    void storeScreenLockState();

    VfxPoint getSlideToPos();

    void registerCBEvent();

    void deregisterCBEvent();

    void rollbackScreenLockState(VappScreenLockKeyStateEnum state);

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
    //void onKeyInputDragUnlock(
    //    VfxKeyEvent & event
    //);
    
    void onPenInputDragUnlock(
        VfxPenEvent & event
    );
#else
    void onKeyInputTapUnlock(
        VfxKeyEvent & event
    );
    
    void onPenInputTapUnlock(
        VfxPenEvent & event
    );
#endif

    VfxBool isTapUnlockCard(
        VfxPoint pos, 
        VappScreenLockKeyUnlockItem *card
    );

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
    //if centry unlock card cover another unlock card
    VfxBool isCatchUnlockCard();

    //update direction when move centry unlock card
    VfxBool updateCentryMoveDirection(
        VfxPenEvent & event
    ); 
    
#else   /*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/

    //if user tap centry unlock card
    VappScreenLockKeyUnlockItem * getTappedCard(
        VfxPoint pos
    );
    
#endif/*VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK*/

protected:  //override VfxControl

    virtual void onInit();

    virtual void onDeinit();

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    virtual VfxBool onPenInput(
        VfxPenEvent & event
    );

/*----------------------------------------------------------------*/
/* Variables                                                      */
/*----------------------------------------------------------------*/

private:

    VappScreenLockKeyStateEnum      m_state;
    VappScreenLockKeyStateEnum      m_prevState;
    VappScreenLockKeyDirectionEnum  m_centryMoveDirection;
    
    VfxBool m_isBacklightOn;
    VfxBool m_isCentryTapped;
#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
    VfxBool m_isPenMoved;
    VfxBool m_isUnlockSelected;
#else
    VfxBool m_isTapCentryCard;
    VfxBool m_isTapUnlockCard;    
#endif

    VappWallpaper                 *m_wallpaper;
    VcpStatusIconBar              *m_iconBar;    
    VappLauncherKeyClock          *m_clock;
#if defined(__MMI_NCENTER_SUPPORT__)
    VappScreenLockKeyNotification *m_notify;
#endif
    VfxTimer                      *m_timer;
    VfxPointTimeline              *m_timelineSlide;
    
    VappScreenLockKeyUnlockItem   *m_unlockCentry;
    VappScreenLockKeyUnlockItem   *m_unlockUp;
    VappScreenLockKeyUnlockItem   *m_unlockLeft;
    VappScreenLockKeyUnlockItem   *m_unlockRight;
    VappScreenLockKeyUnlockItem   *s_unlockTbl[VAPP_SCREEN_LOCK_KEY_UNLOCK_TOTAL];
    
    VappScreenLockKeyArrow        *m_arrowUp;   
    VappScreenLockKeyArrow        *m_arrowLeft;
    VappScreenLockKeyArrow        *m_arrowRight;
    VappScreenLockKeyArrow        *s_arrowTbl[VAPP_SCREEN_LOCK_KEY_UNLOCK_CENTRY];

    //use this signal to notify unlock card and arrow to enter related state
    VfxSignal2<VappScreenLockKeyStateEnum, VappScreenLockKeyDirectionEnum>m_signalOnEnterState;

};


#endif

#endif

