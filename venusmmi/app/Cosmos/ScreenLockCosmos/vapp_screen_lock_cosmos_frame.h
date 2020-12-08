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
 *  vapp_screen_lock_frame.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VAPP_SCREEN_LOCK_COSMOS_FRAME_H__
#define __VAPP_SCREEN_LOCK_COSMOS_FRAME_H__

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)


/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"
#include "vcp_include.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined(__MMI_MAINLCD_480X800__)
#define VAPP_SCREEN_LOCK_UNLOCK_AREA_Y                     532
#define VAPP_SCREEN_LOCK_CARD_POS_Y                        565
#define VAPP_SCREEN_LOCK_REAL_CARD_HEIGHT                  170
#define VAPP_SCREEN_LOCK_CARD_ORIGINAL_X_GAP               205  
#define VAPP_SCREEN_LOCK_CARD_DRAGGING_X_GAP               164  
#define VAPP_SCREEN_LOCK_CARD_ORIGIN_POS_Z                 70
#define VAPP_SCREEN_LOCK_CARD_ORIGIN_ROTATION_ANGLE        70
#elif defined(__MMI_MAINLCD_320X480__) 
#define VAPP_SCREEN_LOCK_UNLOCK_AREA_Y                     317
#define VAPP_SCREEN_LOCK_CARD_POS_Y                        337
#define VAPP_SCREEN_LOCK_REAL_CARD_HEIGHT                  105
#define VAPP_SCREEN_LOCK_CARD_ORIGINAL_X_GAP               138
#define VAPP_SCREEN_LOCK_CARD_DRAGGING_X_GAP               105
#define VAPP_SCREEN_LOCK_CARD_ORIGIN_POS_Z                 55
#define VAPP_SCREEN_LOCK_CARD_ORIGIN_ROTATION_ANGLE        62
#elif defined(__MMI_MAINLCD_240X400__)
#define VAPP_SCREEN_LOCK_UNLOCK_AREA_Y                     272
#define VAPP_SCREEN_LOCK_CARD_POS_Y                        280	// 272+8
#define VAPP_SCREEN_LOCK_REAL_CARD_HEIGHT                  85
#define VAPP_SCREEN_LOCK_CARD_ORIGINAL_X_GAP               104
#define VAPP_SCREEN_LOCK_CARD_DRAGGING_X_GAP               79
#define VAPP_SCREEN_LOCK_CARD_ORIGIN_POS_Z                 55
#define VAPP_SCREEN_LOCK_CARD_ORIGIN_ROTATION_ANGLE        62
#elif defined(__MMI_MAINLCD_240X320__)
#define VAPP_SCREEN_LOCK_UNLOCK_AREA_Y                     192
#define VAPP_SCREEN_LOCK_CARD_POS_Y                        200	// 192+8
#define VAPP_SCREEN_LOCK_REAL_CARD_HEIGHT                  85
#define VAPP_SCREEN_LOCK_CARD_ORIGINAL_X_GAP               104
#define VAPP_SCREEN_LOCK_CARD_DRAGGING_X_GAP               79
#define VAPP_SCREEN_LOCK_CARD_ORIGIN_POS_Z                 55
#define VAPP_SCREEN_LOCK_CARD_ORIGIN_ROTATION_ANGLE        62
#else
#define VAPP_SCREEN_LOCK_UNLOCK_AREA_Y                     317
#define VAPP_SCREEN_LOCK_CARD_POS_Y                        330
#define VAPP_SCREEN_LOCK_REAL_CARD_HEIGHT                  105
#define VAPP_SCREEN_LOCK_CARD_ORIGINAL_X_GAP               138
#define VAPP_SCREEN_LOCK_CARD_DRAGGING_X_GAP               105
#define VAPP_SCREEN_LOCK_CARD_ORIGIN_POS_Z                 55
#define VAPP_SCREEN_LOCK_CARD_ORIGIN_ROTATION_ANGLE        62
#endif

#define VAPP_SCREEN_LOCK_MAX_CARD_NUM                      3
#define VAPP_SCREEN_LOCK_CARD_FLY_AWAY_TIME                250
#define VAPP_SCREEN_LOCK_CARD_FLIP_TIME                    1000
#define VAPP_SCREEN_LOCK_CARD_INITIAL_OPACITY              0.9
#define VAPP_SCREEN_LOCK_WHITE_ARROW_FADE_IN               250

// 0.5  = 500 / 1000.f 
// 500  = ceteria of big circle rotating.
// 1000 = (convert ms to s)
#define VAPP_SCREEN_LOCK_SPEED_CRITERIA                    0.5

class VappScreenLockCard;
class VcpBubbleEffect;
/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Class 
 *****************************************************************************/
class VappScreenLockFrame : public VfxControl
{
    VFX_DECLARE_CLASS(VappScreenLockFrame);

// Default Constructor
public:
    VappScreenLockFrame();

// Method
public:
    void addCard(VappScreenLockCard *);
    void setBg();
    
    // This function is used to layout according to number of cards
    void layoutCards();

    void setHideUnlockHint(VfxBool hide);

private:

    // This function gets the pointer to the first card.
    // RETURNS: pointer to the card.
    VappScreenLockCard *getFirstCard();

    // This function gets the next pointer to the card.
    // RETURNS: pointer to the next card.
    VappScreenLockCard *getNextCard();

    VfxSize getScreenSize();

    void notifyUnlock();

    void notifyBubbleExplode(
        VfxBaseTimeline *timeline, 
        VfxBool isCompleted
    );

// Method
public:
    // This function check if it in the unlocking procedure.
    VfxBool isUnlocking();
    
    // This function check if the backlight is off.    
    void isBacklightOff(VfxBool isBacklightOff);
    
private:
    // This block implements the core functions related to the Drag of
    // the cards.

    // This function sets a card to begin the Drag process.
    void setCardDragStart(
        VappScreenLockCard *card,   // [IN] Moving control (card)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function sets a card to move according to the pen move event.
    void setCardDrag(
        VappScreenLockCard *card,   // [IN] Moving control (card)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function sets a catd to terminate the Drag process.
    void setCardDragEnd(
        VappScreenLockCard *card,   // [IN] Moving control (card)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function reset the screen lock
    void setCardDragAbort(
        VappScreenLockCard *card,   // [IN] Moving control (card)
        VfxPenEvent &event      // [IN] Pen event
    );

    // This function reset the z-order of cards
    void initialCardsZOrder();

    // This funciton set the unlocking state
    void setUnlocking(VfxBool isUnlocking);

    // This funciton check if user tap on any card 
    // card is transformed by 3X3 MATRIX, 
    // so it needs to determine it by inverse transform of pen position
    //
    // Parameter:
    // [IN]      pos        : pen position of this frame
    // [OUT]     cardIndex  : tapped card index 
    // [OUT]     targetCard : which card is tapped 
    //
    // Return:
    // return VFX_TRUE if tap on any card, Otherwise, return VFX_FALSE
    VfxBool isTapOnAnyCard(VfxPoint pos, VfxS32 &cardIndex, VappScreenLockCard **targetCard);

// Override
public:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

	// Test if the frame contains the specified point
	// RETURNS:
    //return VFX_TRUE if the clip bound of the frame contains the point
	virtual VfxBool onContainPoint(
		const VfxPoint &point		// [IN] the point in the coordinate of the frame
	) const;

// Signal
public:
    VfxSignal1 <VappScreenLockFrame *> m_signalUnlocked;
    VfxSignal1 <VfxBool> m_signalIsSuspendWallpaper;

// Variable
private:
    // check if in the unlocking procedure
    VfxBool         m_isUnlocking;
    
    // check if the backlight is off
    VfxBool         m_isBacklightOff;

    // Total number of cards
    VfxS32          m_numCards;

    // used to browse all cards
    VfxS32          m_currCardIndex;

    // original card position of y
    VfxS32          m_cardOriginPosY;

    // unlock area height
    VfxS32          m_unlockAreaHeight; 

    // opacity frame
    VfxFrame            *m_imgFg;

    // unlock hint text frame
    VfxTextFrame        *m_unlockHint;

    // arrow frame
    VfxImageFrame       *m_imgArrow;

    // used to control white arrow animation
    VfxFloatTimeline    *m_tlArrowOpacity;

    // transform timeline: used to flip card when clicked
    VfxTransformTimeline    *m_transformCardFlipTimeline;

    // transform timeline: used to fly away card when unlock
    VfxTransformTimeline    *m_transformTimeline;

    // The array of the cards
    VappScreenLockCard        **m_card;

    // target card, used to remember which card is active by pen
    VappScreenLockCard        *m_targetCard;

    VcpBubbleEffect         *m_bubbleEffect;

    VfxS32 m_activeCardIndex; 

    VfxS32 m_rotateDeg[VAPP_SCREEN_LOCK_MAX_CARD_NUM];

    VfxS32 m_oriModelX[VAPP_SCREEN_LOCK_MAX_CARD_NUM];

    VfxS32 m_oriModelY[VAPP_SCREEN_LOCK_MAX_CARD_NUM];

    // used to reset the old tick to VRT.
    VfxU32 m_oldTick;

};
#endif /* __MMI_VUI_SCREEN_LOCK_COSMOS__ */
#endif /* __VAPP_SCREEN_LOCK_COSMOS_FRAME_H__ */

