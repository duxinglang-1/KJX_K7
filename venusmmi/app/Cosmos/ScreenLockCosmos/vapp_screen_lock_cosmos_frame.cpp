/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*******************************************************************************
 * Filename:
 * ---------
 *  vapp_screen_lock_frame.cpp
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "MMI_features.h" 

#if defined(__MMI_VUI_SCREEN_LOCK_COSMOS__)

#include "vapp_screen_lock_cosmos_frame.h"
#include "vapp_screen_lock_cosmos_card.h"
#include "vcp_bubble_effect.h"
//#include "mmi_rp_vapp_screen_lock_def.h"
#include "mmi_rp_vapp_screen_lock_cosmos_def.h"

#include "mmi_trc.h"
#include "vfx_adp_device.h"

/* Pluto MMI headers: */
#ifdef __cplusplus
extern "C"
{
#endif

// extern pluto setting api
#include "GpioSrvGProt.h"

#ifdef __cplusplus
}
#endif

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define VAPP_SCREEN_LOCK_TOP_POS_Z  -2
#define VAPP_SCREEN_LOCK_LOW_POS_Z  0

#if defined (__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
#endif
    
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}

#define SLK_MEASURE_TIME_START(_symbol_) SLA_CustomLogging(##_symbol_##, SA_start);
#define SLK_MEASURE_TIME_STOP(_symbol_)  SLA_CustomLogging(##_symbol_##, SA_stop);
#else
#define SLK_MEASURE_TIME_START(_symbol_)
#define SLK_MEASURE_TIME_STOP(_symbol_)
#endif


/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappScreenLockFrame", VappScreenLockFrame, VfxControl);

VappScreenLockFrame::VappScreenLockFrame():
    m_isUnlocking(VFX_FALSE),
    m_isBacklightOff(VFX_FALSE),
    m_numCards(0),
    m_currCardIndex(0),
    m_cardOriginPosY(0),
    m_unlockAreaHeight(0),
    m_activeCardIndex(-1),
    m_card(NULL),
    m_imgFg(NULL),
    m_unlockHint(NULL),
    m_imgArrow(NULL),
    m_tlArrowOpacity(NULL),
    m_transformTimeline(NULL),
    m_targetCard(NULL),
    m_transformCardFlipTimeline(NULL),
    m_bubbleEffect(NULL),
    m_oldTick(0)
{
    // variable initiation 
    m_unlockAreaHeight = VAPP_SCREEN_LOCK_UNLOCK_AREA_Y;

    // set initial rotation angle for each card
    m_rotateDeg[0] = -VAPP_SCREEN_LOCK_CARD_ORIGIN_ROTATION_ANGLE;
    m_rotateDeg[1] = 0;
    m_rotateDeg[2] = VAPP_SCREEN_LOCK_CARD_ORIGIN_ROTATION_ANGLE;

    m_cardOriginPosY = VAPP_SCREEN_LOCK_CARD_POS_Y + VAPP_SCREEN_LOCK_REAL_CARD_HEIGHT/2;
}

void VappScreenLockFrame::onInit()
{
    VfxControl::onInit();
   
    this->setIsZSortChild(VFX_TRUE);
       
    // Opacity frame
    VFX_OBJ_CREATE(m_imgFg, VfxFrame, this);
    m_imgFg->setBgColor(VFX_COLOR_BLACK);
    m_imgFg->setOpacity(0);
    m_imgFg->setBounds(0, 0, getScreenSize().width, m_unlockAreaHeight);

    VFX_ALLOC_MEM(m_card, sizeof(VappScreenLockCard *) * VAPP_SCREEN_LOCK_MAX_CARD_NUM, this);

    VFX_OBJ_CREATE(m_imgArrow, VfxImageFrame, this);
    m_imgArrow->setResId(IMG_ID_VAPP_SCREEN_LOCK_ARROW);
    m_imgArrow->setAnchor(0.5, 0);
    m_imgArrow->setOpacity(0);

    // unlock hint text frame 
    VFX_OBJ_CREATE(m_unlockHint, VfxTextFrame, this);
    m_unlockHint->setAnchor(0.5, 1);
    m_unlockHint->setOpacity(0);
    //m_unlockHint->setFont(g_vfxFontSmall);
    m_unlockHint->setColor(VFX_COLOR_WHITE);
    m_unlockHint->setPos(getScreenSize().width/2, m_imgFg->getSize().height-10);   

    // arrow timeline
    VFX_OBJ_CREATE(m_tlArrowOpacity, VfxFloatTimeline, this);
    m_tlArrowOpacity->setTarget(m_imgArrow);
    m_tlArrowOpacity->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_tlArrowOpacity->setDuration(VAPP_SCREEN_LOCK_WHITE_ARROW_FADE_IN);

    // unlock card flip timeline
    VFX_OBJ_CREATE(m_transformCardFlipTimeline, VfxTransformTimeline, this);
    
    // unlock card fly away timeline
    VFX_OBJ_CREATE(m_transformTimeline, VfxTransformTimeline, this);
    m_transformTimeline->m_signalStopped.connect(this, &VappScreenLockFrame::notifyBubbleExplode);

    // Bubble Effect
    //VFX_OBJ_CREATE(m_bubbleEffect, VcpBubbleEffect, this);
    //Change the number of bubble to 12 for the performance consideration.
    VFX_OBJ_CREATE_EX(m_bubbleEffect, VcpBubbleEffect, this, (12));
    m_bubbleEffect->setBounds(0, 0, getScreenSize().width, getScreenSize().height);
    m_bubbleEffect->m_signalOnStopFinished.connect(this, &VappScreenLockFrame::notifyUnlock);
    m_bubbleEffect->setThresholdY(m_unlockAreaHeight);
    m_bubbleEffect->setPosZ(VAPP_SCREEN_LOCK_LOW_POS_Z);

}

void VappScreenLockFrame::onDeinit()
{
    m_transformTimeline->m_signalStopped.disconnect(this, &VappScreenLockFrame::notifyBubbleExplode);
    m_bubbleEffect->m_signalOnStopFinished.disconnect(this, &VappScreenLockFrame::notifyUnlock);

    VFX_OBJ_CLOSE(m_imgFg);
    VFX_OBJ_CLOSE(m_imgArrow);
    VFX_OBJ_CLOSE(m_unlockHint);
    VFX_OBJ_CLOSE(m_tlArrowOpacity);
    VFX_OBJ_CLOSE(m_transformTimeline);
    VFX_OBJ_CLOSE(m_transformCardFlipTimeline);
    if (m_card)
    {
        VFX_FREE_MEM(m_card);
    }

    VfxControl::onDeinit();
}


void VappScreenLockFrame::addCard(VappScreenLockCard *card)
{
    VFX_OBJ_ASSERT_VALID(card);
    VFX_DEV_ASSERT(m_numCards <= VAPP_SCREEN_LOCK_MAX_CARD_NUM);
    m_card[m_numCards] = card;
    m_numCards++;

    this->addChildFrame(card);

    card->setIsDisabled(VFX_TRUE);
    card->setOpacity(VAPP_SCREEN_LOCK_CARD_INITIAL_OPACITY);
    card->setAutoAnimate(VFX_TRUE);
}


void VappScreenLockFrame::layoutCards()
{
    if(m_numCards == 0)
    {
        return;
    }

    // control rotate each card by which axis
    m_oriModelX[0] = -getFirstCard()->getSize().width/2;
    m_oriModelY[0] = -getFirstCard()->getSize().height/2;
    m_oriModelX[1] = -getFirstCard()->getSize().width/2;
    m_oriModelY[1] = -getFirstCard()->getSize().height/2;
    m_oriModelX[2] = -getFirstCard()->getSize().width/2;
    m_oriModelY[2] = -getFirstCard()->getSize().height/2;

    VappScreenLockCard *card;
    VfxS32 index=0;

    VfxMatrix4x4 camera;
    camera.setCamera(1, 1, getSize().width/2, m_cardOriginPosY, 240, 240, 0, 0, 0);

    VfxS32 gap = VAPP_SCREEN_LOCK_CARD_ORIGINAL_X_GAP;

    for (card = getFirstCard();
         card != NULL;
         card = getNextCard())
    {
        VFX_DEV_ASSERT(card);
    
        // Model matrix
        VfxMatrix4x4 M;
        M.setTranslation(m_oriModelX[index], m_oriModelY[index], 0);

        // Rotate a angle 
        VfxMatrix4x4 R;
        R.setRotateByY(VFX_DEG_TO_RAD(m_rotateDeg[index]));

        // translate position according by camera and model matrix
        VfxMatrix4x4 T;
        T.setTranslation((index-1)*gap, 0, vfxAbs(index-1)*VAPP_SCREEN_LOCK_CARD_ORIGIN_POS_Z);

        index++;

        // total
        VfxTransform tempTransform;
        VfxMatrix4x4 total = camera * T * R * M; 
        tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;
        total.initMatrix3x3(tempTransform.data.matrix3x3);

        card->setTransform(tempTransform);
        
        // Scenario: for the use of reset screen lock into init. status.
        // other components initiation
        card->setOpacity(1.0);
        card->setReleased();
    }
}


void VappScreenLockFrame::initialCardsZOrder()
{
    // target card should put above the other cards
    VappScreenLockCard *card;
    for (card = getFirstCard();
         card != NULL;
         card = getNextCard())
    {
        card->setPosZ(VAPP_SCREEN_LOCK_LOW_POS_Z);
    }
}


void VappScreenLockFrame::setCardDragStart(
        VappScreenLockCard *targetCard,         // [IN] Moving control (card)
        VfxPenEvent &event)         // [IN] Pen event
{
    VfxPoint pos(event.getRelPos(this));
    VfxPoint downPos(event.getRelDownPos(this));

    initialCardsZOrder();

    targetCard->setPosZ(VAPP_SCREEN_LOCK_TOP_POS_Z);
    targetCard->setOpacity(1);
    targetCard->setClicked();

    VfxS32 gap = VAPP_SCREEN_LOCK_CARD_DRAGGING_X_GAP;

    // Camera matrix
    VfxMatrix4x4 camera;
    camera.setCamera(1, 1, getSize().width/2, m_cardOriginPosY, 240, 240, 0, 0, 0);

    // Model matrix
    VfxMatrix4x4 M;
    M.setTranslation(m_oriModelX[m_activeCardIndex], m_oriModelY[m_activeCardIndex], 0);

     // Rotate a angle 
     VfxMatrix4x4 R;
     R.setRotateByY(VFX_DEG_TO_RAD(VFX_DEG_TO_RAD(0)));
     
     // translate position according by camera and model matrix
     VfxMatrix4x4 T;
     T.setTranslation((m_activeCardIndex-1)*gap, 0, 0);

    // total
    VfxTransform tempTransform;
    VfxMatrix4x4 total; 
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    total = camera * T * R * M; 
    total.initMatrix3x3(tempTransform.data.matrix3x3);
    targetCard->setTransform(tempTransform);

    // trigger card flip animation
    m_transformCardFlipTimeline->setTarget(targetCard);
    m_transformCardFlipTimeline->setFromValue(targetCard->getTransform());
    m_transformCardFlipTimeline->setDuration(VAPP_SCREEN_LOCK_CARD_FLIP_TIME);
    m_transformCardFlipTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);
    m_transformCardFlipTimeline->setToValue(tempTransform);
    m_transformCardFlipTimeline->start();
    
    m_imgFg->setOpacity(0.3);

    // white arrow animation
    m_tlArrowOpacity->setFromValue(0);
    m_tlArrowOpacity->setToValue(1);
    m_tlArrowOpacity->start();
    m_imgArrow->setOpacity(1);
    
    VfxMatrix3x3Ex tmpMatrix = VfxMatrix3x3Ex(tempTransform.data.matrix3x3);
    VfxPoint point = tmpMatrix.transform(VfxPoint(
                                            targetCard->getPos().x+targetCard->getSize().width/2, 
                                            targetCard->getPos().y));

    m_bubbleEffect->startFloat(VfxPoint(point.x, point.y+targetCard->getSize().height/2));

    // set arrow position
    point.y = point.y - VAPP_SCREEN_LOCK_REAL_CARD_HEIGHT ;
    m_imgArrow->setPos(point);  
    m_unlockHint->setOpacity(1);
    m_unlockHint->setString((targetCard->m_unlockHint));

    //suspend wallpaper when card has been dragged
    m_signalIsSuspendWallpaper.emit(VFX_TRUE);
}


void VappScreenLockFrame::setCardDrag(
        VappScreenLockCard *targetCard,         // [IN] Moving control (card)
        VfxPenEvent &event)         // [IN] Pen event
{

    // Force VRT suspend, for 36 performance consideration
    VfxRenderer *renderer = VFX_OBJ_GET_INSTANCE(VfxRenderer);
    renderer->suspendUntilCommit();

    SLK_MEASURE_TIME_START("SL1");
    // stop flip card timeline  
    m_transformCardFlipTimeline->stop();

    // stop arrow timeline and set arrow opacity
    if(m_tlArrowOpacity->getIsEnabled())
    {
        m_tlArrowOpacity->stop();
        m_imgArrow->setOpacity(1);
    }

    // calculate card transformation
    VfxPoint pos(event.getRelPos(this));
    VfxPoint downPos(event.getRelDownPos(this));
    VfxS32 gap = VAPP_SCREEN_LOCK_CARD_DRAGGING_X_GAP;

    // Camera matrix
    VfxMatrix4x4 camera;
    camera.setCamera(1, 1, getSize().width/2, m_cardOriginPosY, 240, 240, 0, 0, 0);

    // Model matrix
    VfxMatrix4x4 M;
    M.setTranslation(m_oriModelX[m_activeCardIndex], m_oriModelY[m_activeCardIndex], 0);
 
    // Rotate a angle 
    VfxMatrix4x4 R;
    R.setRotateByY(VFX_DEG_TO_RAD(VFX_DEG_TO_RAD(0)));
    
    // translate position according by camera and model matrix
    VfxMatrix4x4 T;
    T.setTranslation((m_activeCardIndex-1)*gap + pos.x - downPos.x, pos.y - downPos.y, 0);

    // total
    VfxTransform tempTransform;
    VfxMatrix4x4 total; 
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    total = camera * T * R * M; 
    total.initMatrix3x3(tempTransform.data.matrix3x3);
    SLK_MEASURE_TIME_STOP("SL1");

    SLK_MEASURE_TIME_START("SL2");
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    targetCard->setTransform(tempTransform);

    VfxAutoAnimate::commit();
    SLK_MEASURE_TIME_STOP("SL2");

    SLK_MEASURE_TIME_START("SL3");    
    // scale light dot according to card position
    VfxMatrix3x3Ex tmpMatrix;
    VfxPoint point;
    tmpMatrix = VfxMatrix3x3Ex(targetCard->forceGetTransform().data.matrix3x3);
    point = tmpMatrix.transform(VfxPoint( targetCard->getPos().x + targetCard->getSize().width/2, targetCard->getPos().y));

    //calculate the diff of time,x and y to set the speed criteria for big circle rotating
    VfxMsec tDiff = vfxMsecDiff(event.timeStamp, event.prevTimeStamp);

    if(tDiff == 0 )
	{
		return;
	}
        
    VfxS32 xDiff = VFX_ABS(event.prevPos.x - event.pos.x);
    VfxS32 yDiff = VFX_ABS(event.prevPos.y - event.pos.y);

    //MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_ROTATE_DIFF,(int)((xDiff+yDiff)/(tDiff/1000.0f)),xDiff, yDiff );

    // check the  circling speed and degrade the bubble if quick speed is detected
    // cons: it may increase the sw overhead since the loop fucntion inside
	if((xDiff+yDiff) / (tDiff) < VAPP_SCREEN_LOCK_SPEED_CRITERIA)
    {
        // normal bubble mode
        m_bubbleEffect->setSuspendEeject(VFX_FALSE);
    }
    else
    {
        // big circle rotating occurs and degrade bubbles to ZERO
        m_bubbleEffect->setSuspendEeject(VFX_TRUE);
    }

    SLK_MEASURE_TIME_START("SL4"); 
    m_bubbleEffect->shiftFloat(VfxPoint(point.x, point.y+targetCard->getSize().height/2));
    SLK_MEASURE_TIME_STOP("SL4"); 

    VfxFloat ratio = (VfxFloat)(point.y - m_imgArrow->getPos().y)/m_imgArrow->getSize().height;
    if(ratio >= 1)
    {
        m_imgArrow->setOpacity(1);
    }
    else if(ratio <= 0)
    {
        m_imgArrow->setOpacity(0);
    }
    else
    {
        m_imgArrow->setOpacity(ratio);
    }
    SLK_MEASURE_TIME_STOP("SL3");
}


void VappScreenLockFrame::setCardDragEnd(
        VappScreenLockCard *targetCard,         // [IN] Moving control (card)
        VfxPenEvent &event)         // [IN] Pen event.
{
    VfxPoint pos(event.getRelPos(this));
    VfxPoint downPos(event.getRelDownPos(this));

    initialCardsZOrder();

    targetCard->setOpacity(VAPP_SCREEN_LOCK_CARD_INITIAL_OPACITY);

    VfxMatrix3x3Ex tmpMatrix;
    VfxPoint point;
    VfxS32 gap = VAPP_SCREEN_LOCK_CARD_ORIGINAL_X_GAP;

    // Camera matrix
    VfxMatrix4x4 camera;
    camera.setCamera(1, 1, getSize().width/2, m_cardOriginPosY, 240, 240, 0, 0, 0);

    // Model matrix
    VfxMatrix4x4 M;
    M.setTranslation(m_oriModelX[m_activeCardIndex], m_oriModelY[m_activeCardIndex], 0);
    
    // Rotate a angle 
    VfxMatrix4x4 R;
    R.setRotateByY(VFX_DEG_TO_RAD(VFX_DEG_TO_RAD(0)));
    
    // translate position according by camera and model matrix
    VfxMatrix4x4 T;
    
    // total
    VfxTransform tempTransform;
    VfxMatrix4x4 total; 
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tmpMatrix = VfxMatrix3x3Ex(targetCard->forceGetTransform().data.matrix3x3);
    point = tmpMatrix.transform(VfxPoint(targetCard->getPos().x + targetCard->getSize().width/2, targetCard->getPos().y + targetCard->getSize().height));

    // card reach unlock threshold
    if(pos.y <= m_unlockAreaHeight)
    {
        setUnlocking(VFX_TRUE);
        
        // trigger card fly out animation
        m_transformTimeline->setTarget(targetCard);
        m_transformTimeline->setFromValue(targetCard->getTransform());
        m_transformTimeline->setDuration(VAPP_SCREEN_LOCK_CARD_FLY_AWAY_TIME);
        m_transformTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_TRANSFORM);

//        T.setTranslation((m_activeCardIndex-1)*gap + (m_activeCardIndex-1)*targetCard->getSize().width/2 + pos.x - downPos.x, -m_cardOriginPosY-m_targetCard->getSize().height/2, 0);
        T.setTranslation(point.x - getScreenSize().width/2, -m_cardOriginPosY-m_targetCard->getSize().height/2, 0);

        total = camera * T * M; 
        total.initMatrix3x3(tempTransform.data.matrix3x3);
        m_transformTimeline->setToValue(tempTransform);
        m_transformTimeline->start();

        // fade out card during fly out
        targetCard->setOpacity(0.2);
    }
    else    // translate card to original pos
    {
        // card initiation
        targetCard->setReleased();
            
        R.setRotateByY(VFX_DEG_TO_RAD(m_rotateDeg[m_activeCardIndex]));
        T.setTranslation((m_activeCardIndex-1)*gap, 0, vfxAbs(m_activeCardIndex-1)*VAPP_SCREEN_LOCK_CARD_ORIGIN_POS_Z);
        total = camera * T * R * M; 
        total.initMatrix3x3(tempTransform.data.matrix3x3);
        targetCard->setTransform(tempTransform);

        // other components initiation
        m_imgFg->setOpacity(0);
        m_imgArrow->setOpacity(0);
        m_unlockHint->setOpacity(0);
        m_bubbleEffect->stopFloat(VFX_FALSE);

        //Do not meet unlocking certeria, thus, resume wallpaper
        m_signalIsSuspendWallpaper.emit(VFX_FALSE);

        // m_targetCard should not reset if achieve unlock, 
        // because it need to use on notifyUnlock
        m_targetCard = NULL;
    }
    m_tlArrowOpacity->stop();
    m_transformCardFlipTimeline->stop();
}


void VappScreenLockFrame::setCardDragAbort(
        VappScreenLockCard *targetCard,         // [IN] Moving control (card)
        VfxPenEvent &event)                     // [IN] Pen event.
{
    VfxPoint pos(event.getRelPos(this));
    VfxPoint downPos(event.getRelDownPos(this));

    initialCardsZOrder();

    targetCard->setOpacity(VAPP_SCREEN_LOCK_CARD_INITIAL_OPACITY);

    VfxMatrix3x3Ex tmpMatrix;
    VfxPoint point;
    VfxS32 gap = VAPP_SCREEN_LOCK_CARD_ORIGINAL_X_GAP;

    // Camera matrix
    VfxMatrix4x4 camera;
    camera.setCamera(1, 1, getSize().width/2, m_cardOriginPosY, 240, 240, 0, 0, 0);

    // Model matrix
    VfxMatrix4x4 M;
    M.setTranslation(m_oriModelX[m_activeCardIndex], m_oriModelY[m_activeCardIndex], 0);
    
    // Rotate a angle 
    VfxMatrix4x4 R;
    R.setRotateByY(VFX_DEG_TO_RAD(VFX_DEG_TO_RAD(0)));
    
    // translate position according by camera and model matrix
    VfxMatrix4x4 T;
    
    // total
    VfxTransform tempTransform;
    VfxMatrix4x4 total; 
    tempTransform.type = VFX_TRANSFORM_TYPE_MATRIX3X3;

    tmpMatrix = VfxMatrix3x3Ex(targetCard->forceGetTransform().data.matrix3x3);
    point = tmpMatrix.transform(VfxPoint(targetCard->getPos().x + targetCard->getSize().width/2, targetCard->getPos().y + targetCard->getSize().height));

    // reset cards
    targetCard->setReleased();
        
    R.setRotateByY(VFX_DEG_TO_RAD(m_rotateDeg[m_activeCardIndex]));
    T.setTranslation((m_activeCardIndex-1)*gap, 0, vfxAbs(m_activeCardIndex-1)*VAPP_SCREEN_LOCK_CARD_ORIGIN_POS_Z);
    total = camera * T * R * M; 
    total.initMatrix3x3(tempTransform.data.matrix3x3);
    targetCard->setTransform(tempTransform);

    // other components initiation
    m_imgFg->setOpacity(0);
    m_imgArrow->setOpacity(0);
    m_unlockHint->setOpacity(0);
    m_tlArrowOpacity->stop();
    m_transformCardFlipTimeline->stop();
    m_bubbleEffect->stopFloat(VFX_FALSE);

    //not meet unlocking certeria, thus, resume wallpaper
    m_signalIsSuspendWallpaper.emit(VFX_FALSE);  

    m_targetCard = NULL;
}


void VappScreenLockFrame::notifyBubbleExplode(
    VfxBaseTimeline *timeline, 
    VfxBool isCompleted)
{
    if(isCompleted)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_FRAME_NOTIFY_BUBBLE_EXPLODE, 200);
        //no need to anymore, used to avoid LCD dim while unlocking
        //srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        m_bubbleEffect->stopFloat(VFX_TRUE);
    }
}


void VappScreenLockFrame::notifyUnlock()
{
    if(srv_backlight_is_on(SRV_BACKLIGHT_TYPE_MAINLCD) == MMI_FALSE )
    //if(m_isBacklightOff)
    {
        // reset screen lock to initial status.
        // scenario: while screen lock is unlocking and press power key to turn off backlight immediately.
        
        // card initiation
        layoutCards();

        // other components initiation        
        m_imgFg->setOpacity(0);
        m_imgArrow->setOpacity(0);
        m_unlockHint->setOpacity(0);
        m_tlArrowOpacity->stop();
        m_transformTimeline->stop();
        m_transformCardFlipTimeline->stop();
        m_bubbleEffect->stopFloat(VFX_FALSE);

        // set not to unlocked
        setUnlocking(VFX_FALSE);

        return;
    }

    VFX_OBJ_ASSERT_VALID(m_targetCard);
    m_targetCard->setUnlocked();

    // emit unlock signal
    m_signalUnlocked.emit(this);
    
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_SCREEN_LOCK_FRAME_NOTIFY_UNLOCK, 200);
}


VfxBool VappScreenLockFrame::onPenInput(VfxPenEvent &event)
{
    if(isUnlocking())
    {
        return VFX_TRUE;
    }

    // dispatch event directly
    switch (event.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            // for the 36 performance consideration
            // since MMI do not have enought time , so force to get time from VRT 
            m_oldTick = vrt_set_busy_sleep_tick(3);
            
            m_targetCard = NULL;
            if(isTapOnAnyCard(event.getRelPos(this), m_activeCardIndex, &m_targetCard))
            {
                setCardDragStart(m_targetCard, event);
                vfx_adp_touch_fb_play(VFX_ADP_TOUCH_FB_TYPE_DOWN);

                return VFX_TRUE;            
            }
            break;
            
        case VFX_PEN_EVENT_TYPE_UP:
            //reset the orginal tick  to VRT
            vrt_set_busy_sleep_tick(m_oldTick);
            
            if(m_targetCard != NULL)
            {
                setCardDragEnd(m_targetCard, event);
                m_activeCardIndex = -1;
            
                return VFX_TRUE;
            }
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
            if(m_targetCard != NULL)
            {
                setCardDrag(m_targetCard, event);
                return VFX_TRUE;
            }
            break;

        case VFX_PEN_EVENT_TYPE_ABORT:
            //reset the orginal tick  to VRT
            vrt_set_busy_sleep_tick(m_oldTick);
            
            if(m_targetCard != NULL)
            {
                setCardDragAbort(m_targetCard, event);
                m_targetCard = NULL;
                
                return VFX_TRUE;
            }
            break;
            
        default:
            break;
    }
    return VfxControl::onPenInput(event);
}


void VappScreenLockFrame::isBacklightOff(VfxBool isBacklightOff)
{
    m_isBacklightOff = isBacklightOff;
}


VfxBool VappScreenLockFrame::isUnlocking()
{
    return m_isUnlocking;
}


void VappScreenLockFrame::setUnlocking(VfxBool isUnlocking)
{
    m_isUnlocking = isUnlocking;
}


void VappScreenLockFrame::setHideUnlockHint(VfxBool hide)
{
    m_unlockHint->setHidden(hide);
}


VfxBool VappScreenLockFrame::isTapOnAnyCard(VfxPoint pos, VfxS32 &cardIndex, VappScreenLockCard **targetCard)
{
    VappScreenLockCard *card;
    VfxMatrix3x3Ex tmpMatrix;
    VfxPoint point;
    VfxS32 index=0;
    
    *targetCard = NULL;
    
    for (card = getFirstCard();
         card != NULL;
         card = getNextCard())
    {
        if(card->getHidden())
        {
            index++;
            continue;
        }
        
        tmpMatrix = VfxMatrix3x3Ex(card->forceGetTransform().data.matrix3x3);
        tmpMatrix.inverse();
        point = tmpMatrix.transform(pos);
        point = convertPointTo(point, card);
        if (card->getBounds().contains(point))
        {
            *targetCard = card;
            cardIndex = index;
            return VFX_TRUE;
        }
        index++;
    }
     return VFX_FALSE;
}


VappScreenLockCard *VappScreenLockFrame::getFirstCard()
{
    if (!m_card)
    {
        return NULL;
    }

    m_currCardIndex = 0;

    return m_card[m_currCardIndex++];
}


VappScreenLockCard *VappScreenLockFrame::getNextCard()
{
    if (!m_card || m_currCardIndex >= m_numCards)
    {
        return NULL;
    }

    return m_card[m_currCardIndex++];
}


VfxBool VappScreenLockFrame::onContainPoint(const VfxPoint &point) const
{
    if(point.y < m_unlockAreaHeight)
    {
        return VFX_FALSE;
    }
    else
    {
        return VFX_TRUE;
    }
}


VfxSize VappScreenLockFrame::getScreenSize()
{
    vrt_size_struct main_screen_size;
    vrt_color_type_enum main_screen_color_format;

    vrt_sys_get_main_screen_info(&main_screen_size, &main_screen_color_format);

    return VfxSize(main_screen_size.width, main_screen_size.height);
}

#endif /* __MMI_VUI_SCREEN_LOCK_COSMOS__ */
