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
 *  vapp_screen_lock_key_unlockitem.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_SCREEN_LOCK_KEY_UNLOCKITEM_H
#define VAPP_SCREEN_LOCK_KEY_UNLOCKITEM_H

#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_screen_lock_key_def.h"
#include "vapp_screen_lock_key_unlock.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

/*
 * Macro to declare a unlock card.
 */
#define VAPP_SCREEN_LOCK_KEY_UNLOCK_DECLARE_CLASS(_className)                                        \
                                                                                                \
    VFX_DECLARE_CLASS(_className);                                                              \
                                                                                                \
    public:                                                                                     \
        static VappScreenLockKeyUnlockItem *createUnlockCard(VfxObject *parentObj)


/*
 * Macro to implement a unlock card.
 */
#define VAPP_SCREEN_LOCK_KEY_UNLOCK_IMPLEMENT_CLASS(_className, _parentClassName)                    \
                                                                            		            \
    VFX_IMPLEMENT_CLASS(#_className, _className, _parentClassName);         		            \
                                                                            		            \
    VappScreenLockKeyUnlockItem *_className::createUnlockCard(VfxObject *parentObj)                    \
    {                                                                       		            \
        _className *unlockCard;                                                 	            \
        VFX_OBJ_CREATE(unlockCard, _className, parentObj);                                      \
        return unlockCard;                                                      	            \
    }


/*****************************************************************************
 * VappScreenLockKeyUnlockItem
 *****************************************************************************/

class VappScreenLockKeyUnlockItem : public IVappScreenLockKeyUnlock
{
    VFX_DECLARE_CLASS(VappScreenLockKeyUnlockItem);
    
/*----------------------------------------------------------------*/
/* Functions                                                      */
/*----------------------------------------------------------------*/

public:

    void setDirection(
        VappScreenLockKeyDirectionEnum direction
    );

    void onEnterOperationState();

    void onEnterBackToNormalState();

    void onBgSlideIn(
        VfxBaseTimeline *timeline, 
        VfxBool isComplete
    );

#ifndef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
    void onBgEnteredCentryTap(
        VfxBaseTimeline *timeline, 
        VfxBool isComplete
    );
#endif

    void onBreath();
    
    void onBreathTimerTick(
        VfxTimer * timer
    );

    void onBreathStop(
        VfxBaseTimeline *timeline, 
        VfxBool isComplete
    );

    void onSlideIn(
        VfxBaseTimeline *timeline, 
        VfxBool isComplete
    );

    void stopTimeline(
        VfxBaseTimeline *timeline, 
        VfxBool isComplete
    );

    VfxPoint getBgNormalPos();

    VfxPoint getBgOperationPos();

    VfxPoint getCardNormalPos();

    VfxPoint getCardOperationPos();

    VfxPoint getExternalCenter();

    VfxPoint getInternalCenter(); 

protected:

    void unlockSlideIn();

    void unlockSlideOut();

    void posAnimationHdlr(
        VfxPointTimeline *timeline,
        VfxAnimatable *target,
        VfxPoint fromValue,
        VfxPoint toValue,
        VfxMsec duration,
        VfxMsec startTime
    );

    void opacityAnimationHdlr(
        VfxFloatTimeline *timeline,
        VfxAnimatable *target,
        VfxFloat fromValue,
        VfxFloat toValue,
        VfxMsec duration,
        VfxMsec startTime
    );

    void setBgNormalPos(
        VfxPoint pos
    );

    void setBgOperationPos(
        VfxPoint pos
    );

    void setCardNormalPos(
        VfxPoint pos
    );

    void setCardOperationPos(
        VfxPoint pos
    );       

protected:  //override VfxControl

    virtual void onInit();
    
    virtual void onDeinit();

public:     //children should override this

    virtual void showNotify();
    
    virtual VfxS32 getRadius();

protected:  //children should override this

    virtual void initComponents();

    virtual void onUnlock();

protected:  //override IVappScreenLockKeyUnlcok

    virtual void enterIdleState();

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK

    virtual void enterBackToNormalState();

    virtual void enterUnlockSelectState(
        VappScreenLockKeyDirectionEnum direction
    );

    virtual void enterUnlockUnselectState(
        VappScreenLockKeyDirectionEnum direction
    );
        
#else

    virtual void enterCentryTapState();

    virtual void enterCentryTapFromNormalState();

    virtual void enterUnlockTapState(
        VappScreenLockKeyDirectionEnum direction
    );

    virtual void enterUnlockRestoreState(
        VappScreenLockKeyDirectionEnum direction
    );

#endif

    virtual void enterUnlockState(
        VappScreenLockKeyDirectionEnum direction
    );

/*----------------------------------------------------------------*/
/* Variables                                                      */
/*----------------------------------------------------------------*/

public:

    VappScreenLockKeyDirectionEnum m_direction;

    /* emit when enter operation screen animation finish, notify miss number hint and arrow to show */
    VfxSignal0 m_signalBgSlideIn;

#ifndef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
    VfxSignal0 m_signalEnteredCentryTap;
#endif

protected:

    VfxFloatTimeline *m_timelineBgOp;
    VfxFloatTimeline *m_timelineCardOp;
    VfxFloatTimeline *m_timelineNotifyOp;
    VfxPointTimeline *m_timelineBgPos;
    VfxPointTimeline *m_timelineCardPos;
    VfxFloatTimeline *m_timelineBreath;

    VfxImageFrame    *m_bg;
    VfxImageFrame    *m_card;
    VfxTextFrame     *m_notify;
    VfxTimer         *m_timerBreath;    
    
    VfxPoint          m_bgNormalPos;
    VfxPoint          m_bgOperationPos;
    VfxPoint          m_cardNormalPos;
    VfxPoint          m_cardOperationPos;
    
    VfxS32            m_bgResId;
    VfxS32            m_selectResId;
    VfxS32            m_breathBaseResId;
    VfxS32            m_breathStep;
    
    static const VfxS32 s_breathMap[];

};


#endif

#endif

