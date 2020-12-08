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
 *  vapp_screen_lock_key_arrow.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_SCREEN_LOCK_KEY_ARROW_H
#define VAPP_SCREEN_LOCK_KEY_ARROW_H

#include "MMI_features.h"

#ifdef __MMI_VUI_SCREEN_LOCK_KEY__

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"
#include "vapp_screen_lock_key_def.h"
#include "vapp_screen_lock_key_unlock.h"

/*****************************************************************************
 * VappScreenLockKeyArrow
 *****************************************************************************/


class VappScreenLockKeyArrow : public IVappScreenLockKeyUnlock
{
    
/*----------------------------------------------------------------*/
/* Functions                                                      */
/*----------------------------------------------------------------*/

public:

    VappScreenLockKeyArrow(){}

    VappScreenLockKeyArrow(VappScreenLockKeyDirectionEnum direction, VfxResId resId) : 
        m_direction(direction),
        m_imgId(resId),
        m_breathStep(0)
    {
    
    }

public:

    void onEnterOperationState();

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
    void onCentryRestored();
#endif

private:    

    void initLayout();

    void setMyOpacity(VfxFloat op);

    void show();

    void hide();

    void onBreath();

    void onBreathTimerTick(VfxTimer * timer);

    void changeOpacity(VfxFloat fromOpacity, VfxFloat toOpacity);

    void onOpacityChanged(VfxBaseTimeline *timeline, VfxBool isComplete);
    
protected:  //override VfxControl

    virtual void onInit();

    virtual void onDeinit();

protected:  //override IVappScreenLockKeyUnlock

    virtual void enterIdleState();

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK

    virtual void enterBackToNormalState();
    
    virtual void enterCentryMoveState(VappScreenLockKeyDirectionEnum direction);

    virtual void enterCentryRestoreState(VappScreenLockKeyDirectionEnum direction);

#else

    virtual void enterCentryTapState();

#endif

/*----------------------------------------------------------------*/
/* Variables                                                      */
/*----------------------------------------------------------------*/

public:

#ifdef VAPP_SCREEN_LOCK_KEY_DRAG_UNLOCK
    /* emit when go back to normal state, notify unlock cards to slide out */
    VfxSignal0 m_signalArrowHidden;
#endif

private:

    VappScreenLockKeyDirectionEnum m_direction;
    
    VfxFloatTimeline *m_timelineOp;    
    VfxImageFrame    *m_arrowInside;
    VfxImageFrame    *m_arrowOutside;    
    VfxTimer         *m_timerBreath;
    VfxResId          m_imgId;
    VfxS32            m_breathStep;    

    static const VfxFloat s_opacityTbl[];

};


#endif

#endif

