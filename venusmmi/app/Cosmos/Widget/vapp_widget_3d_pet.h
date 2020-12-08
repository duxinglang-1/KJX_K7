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
 *  vapp_widget_3d_pet.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Cosmos 3D pet widget
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_3D_PET_H
#define VAPP_WIDGET_3D_PET_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_3D_PET__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_widget_def.h"
#include "vcp_include.h" 
#include "vapp_widget_mini_stage.h"
#include "vfx_camera.h"
#include "vfx_mesh.h"
#include "vfx_texture.h"
#include "vfx_group.h"
#include "vfx_light.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
enum VAPP_WIDGET_3D_PET_STAGE_BOARD_LAYOUT
{
#if defined(__MMI_MAINLCD_320X480__)
    STAGE_BOARD_MIN_X = - 240,
    STAGE_BOARD_MAX_X =   240,
    STAGE_BOARD_MIN_Y = - 240,
    STAGE_BOARD_MAX_Y =   240,
    STAGE_BOARD_WIDTH =   480,
    STAGE_BOARD_HEIGHT =  480,
    STAGE_VALID_OFFSET =  112,
    STAGE_GRASS_VALID_OFFSET = 65, 
#else
    STAGE_BOARD_MIN_X = - 240,
    STAGE_BOARD_MAX_X =   240,
    STAGE_BOARD_MIN_Y = - 240,
    STAGE_BOARD_MAX_Y =   240,
    STAGE_BOARD_WIDTH =   480,
    STAGE_BOARD_HEIGHT =  480,
    STAGE_VALID_OFFSET = 112,
    STAGE_GRASS_VALID_OFFSET = 65,   
#endif
    STAGE_END_OF_BOARD_LAYOUT
};

// sheep sate
enum VappWidget3dPetCharSheepState
{
    SHEEP_INIT = 0,
    SHEEP_STANDING,
    SHEEP_IDLE,
    SHEEP_MOVING,
    SHEEP_GREETING,
    SHEEP_SLEEPING,
    SHEEP_EATING,
    SHEEP_JUMP_RAILING,
    SHEEP_END_OF_STATE
};

enum SheepFaceStopMotion
{
    SF_EAT = 0,    
    SF_WINK,
    SF_SLEEP,
    SF_HI,
    SF_END_OF_FACE_STOP_MOTION
};

enum SheepFace
{
    SHEEP_FACE_NORMAL = 0,
    SHEEP_FACE_EAT,
    SHEEP_FACE_HI_1,
    SHEEP_FACE_HI_2, 
    SHEEP_FACE_HI_3,
    SHEEP_FACE_SNAP,
    SHEEP_FACE_WAKE,
    SHEEP_FACE_END 
};

enum SheepSymbol
{
    SYM_TEXT_Z = 0,
    SYM_TEXT_E, 
    SYM_TEXT_Q, 
    SYM_TEXT_1_UP,
    SYM_TEXT_END
};

enum SheepAnim
{
    SHEEP_ANIM_WALK = 0,
    SHEEP_ANIM_EAT, 
    SHEEP_ANIM_SLEEP,
    SHEEP_ANIM_STAND_LOOK_AROUND,
    SHEEP_ANIM_STAND_LOOK_STRETCH,     
    SHEEP_ANIM_STAND_SHAKE_HEAD,
    SHEEP_ANIM_HI_1,
    SHEEP_ANIM_HI_2,
    SHEEP_ANIM_JUMP,
    SHEEP_ANIM_LEAP,
    SHEEP_ANIM_SLEEP_END,
    SHEEP_ANIM_END 
};

enum SheepInterrupt
{
    SI_TAP_SHEEP = 0, 
    SI_GROW_GRASS,
    SI_PREPARE_JUMP_RAILING,
    SI_END
};

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappWidget3dPetMotion;
class VappWidget3dPetStopMotionPlayer;
class VappWidget3dPetAnimItem;
class VappWidget3dPetAnimTL;
class VappWidget3dPetAnimPlayer;

class VappWidget3dPetGroup;
class VappWidget3dPetRailing;
class VappWidget3dPetGrass;
class VappWidget3dPetSheepSymbol;
class VappWidget3dPetSheepStage;

class VappWidget3ePetSheepInterruptOption;
class VappWidget3dPetMovingRecord;
class VappWidget3dPetChar;
class VappWidget3dPetCharSheep;
class VappWidget3dPetDevelopFrame;
class VappWidget3dPetWorld;
class VappWidget3dPetSheepWorld;
class VappWidget3dPet;

/*****************************************************************************
 *  Class : stop Motion Animation 
 *****************************************************************************/
class VappWidget3dPetMotion
{
public:
    VappWidget3dPetMotion(){};
    void configContent(const VfxImageSrc &motionImgSrc,
                       const VfxImageSrc &motioningImgSrc,
                       const VfxImageSrc &motionedImgSrc,
                       const VfxMsec durationStartToKey,    
                       const VfxMsec durationShowKey,
                       const VfxMsec durationKeyToEnd)
    {
        m_startImgSrc = motionImgSrc;
        m_keyImgSrc   = motioningImgSrc;
        m_endImgSrc   = motionedImgSrc;
        m_durationStartToKey = durationStartToKey;
        m_durationShowKey = durationShowKey;
        m_durationKeyToEnd = durationKeyToEnd;
    }
    VfxImageSrc getMotionImgSrc(){return m_startImgSrc;};
    VfxImageSrc getMotioningImgSrc(){return m_keyImgSrc;};
    VfxImageSrc getMotionedImgSrc(){return m_endImgSrc;};        
    VfxMsec getMotionDuration(){return m_durationStartToKey;};    
    VfxMsec getMotioningDuration(){return m_durationShowKey;};
    VfxMsec getMotionedDuration(){return m_durationKeyToEnd;}     

private:
    VfxImageSrc m_startImgSrc;
    VfxImageSrc m_keyImgSrc;
    VfxImageSrc m_endImgSrc;    
    VfxMsec m_durationStartToKey;    
    VfxMsec m_durationShowKey;
    VfxMsec m_durationKeyToEnd;
};

class VappWidget3dPetStopMotionPlayer : public VfxObject
{
public:    
    VFX_DECLARE_CLASS(VappWidget3dPetStopMotionPlayer);
    
public:
    VappWidget3dPetStopMotionPlayer();
    void configTarget(VfxMesh *target){m_target = target;};
    void play(VappWidget3dPetMotion motion, VfxBool isRepeated, VfxMsec repeatedDuration);
    void stop();

private:    
    void setCurrentMotion(VappWidget3dPetMotion motion);
    void motion();
    void motioning(VfxTimer *timer);
    void motioned(VfxTimer *timer);
    void startMotionTimer(const VfxMsec duration);
    void changeFrame(const VfxImageSrc &imgSrc);
    
    void startAnimTimer();
    void onAnimTimeout(VfxTimer *timer);
private:
    VfxMesh *m_target;
    VfxTimer *m_animTimer;
    VfxBool m_isRepeated;
    
    // the duration for repeating a stop-motion anim
    // note m_repeatedDuration = D1 + D2
    // D1 = total duraion of a motion = SUM duration{motion, motioning, motioned}
    // D2 = transition duration between two motion
    //
    //    [motion]                 [motion]
    //  --x------------------------x--
    //    <-- m_repeatedDuration -->
    //    <-D1-><------- D2 ------->
    VfxMsec m_repeatedDuration; // TODO: fix naming ambigulaty
    
    // for motion control
    VfxTimer *m_motionTimer;
    VappWidget3dPetMotion m_currentMotion;

    // for changing frame
    VfxTexture2D *m_tex2D;
    VfxImage2D *m_img2D;
};


/*****************************************************************************
 * Class : animation playback control
 *****************************************************************************/
class VappWidget3dPetAnimItem
{
public:
    VfxMsec  duration;
    VfxFloat fromValue;
    VfxFloat toValue;
    VfxS32   repeateCount;
    VfxFloat isAutoReversed;    
    VfxWString path;
    VfxResId res;
};

// TODO: add auto animaiton struc
// TODO: add AnimTL (begin, loop, end) struc
class VappWidget3dPetAnimTL : public VfxFloatTimeline
{    
    //    VFX_DECLARE_CLASS(VappWidget3dPetAnimTLPlayer);
public:
    VappWidget3dPetAnimTL();

protected:
    virtual void onInit()
    {
        VfxFloatTimeline::onInit();
    };

    virtual void onDeinit()
    {
        stop();
        VfxFloatTimeline::onDeinit();
    };

public:
    void configAnimation(VfxAnimation *anim);
	
    void configAnimationEx(VfxAnimation *anim, 
                                    const VfxMsec  duration,
                                    const VfxFloat fromValue,
                                    const VfxFloat toValue,
                                    const VfxS32   repeateCount,
                                    const VfxFloat isAutoReversed);
    
	void setPlaybackPara(const VfxMsec duration,
                             const VfxFloat fromValue,
                             const VfxFloat toValue, 
                             const VfxS32   repeateCount,
                             const VfxFloat isAutoReversed);
    VfxMsec getTLDuraion(){return m_tlDuration;};
private:
    VfxAnimation *m_anim;
    VfxMsec m_tlDuration;
};

class VappWidget3dPetAnimPlayer : public VfxObject
{
public:    
    VFX_DECLARE_CLASS(VappWidget3dPetAnimPlayer);

public:
    VappWidget3dPetAnimPlayer();    
    VfxSignal1<VappWidget3dPetAnimPlayer *> m_sigPlayFinished;
    VfxSignal1<VappWidget3dPetAnimPlayer *> m_sigLoopAnimFinished;

    const static VfxS8 PLAY_ONCE = -1;
    const static VfxS8 PLAY_INFINITE = 0;

public:
    
    void configAnimTL(VappWidget3dPetAnimTL *startTL, 
                      VappWidget3dPetAnimTL *loopTL, 
                      VappWidget3dPetAnimTL *endTL);

    VfxBool isEndAnimPlaying() const;

    // stop in next loop iteration, and then play end anim
    void stop();
    // force stop loop anim instandly, then play end anim
    void stopEx();
    // force stop all anim
    void forceStop();

    // play once = start(1) + loop(1) + end(1)
    void play();
    // play with duraiton, note duration 0 means play anim and REPEAT_INFINITE
    void play(const VfxMsec duration);

private:
    void playEx(const VfxBool souldLoopRepeatInifinte, const VfxS32 repeateCount);
    void resetLoopPlayedRecord();
    void setShouldLoopTLRepeatInifinte(const VfxBool b);
    void setLoopRepeatCount(const VfxS32 repeateCount);

    void playStartTL();
    void playLoopTL();
    void playEndTL();    
    void onStartTLStopped(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void onLoopTLStopped(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void onEndTLStopped(VfxBaseTimeline *timeline, VfxBool isCompleted);
    
// action animation playbac  
private:
    VappWidget3dPetAnimTL *m_startAnimTL;
    VappWidget3dPetAnimTL *m_loopAnimTL;
    VappWidget3dPetAnimTL *m_endAnimTL;

// action animation player control variable
private:
    VfxBool m_shouldLoopTLRepeatInifinte;
    VfxS32 m_loopRepeatCount;
    VfxS32 m_alreadyRepeated;
    // m_duraiton = start(1) + loop(1) + end(1)
    VfxMsec m_duration;
    VfxBool m_needStop;
};

/*****************************************************************************
 * Class : VappWidget3dPetGroup
 *****************************************************************************/

// VappWidget3dPetGroup provides lazy loop anim config / play once support 
// if need the full/custom utility of VappWidget3dPetAnimPlayer,
// overwrite configAnim() and playAnim() 
class VappWidget3dPetGroup : public VfxGroup
{
public:
    VappWidget3dPetGroup();
    VfxSignal1<VappWidget3dPetGroup *> m_sigAnimFinished;

protected:
    virtual void onInit();

protected:   
    virtual void getSceneFile(VfxWString &path) const = 0;    
    virtual void getAnimFile(VfxWString &path) const = 0;
    virtual VfxResId getSceneResId() const = 0 ;
    virtual VfxResId getAnimResId() const = 0;
    virtual VfxMsec getAnimDuration() const = 0;

    virtual void configModel();
    virtual void configAnim();
    virtual void onPlayFinished(VappWidget3dPetAnimPlayer *plyer);
    
public:
    virtual VfxBool isPicked(VfxNode *n);      
    void setAnimId(const VfxId animId){m_animId = animId;};    
    virtual void playAnim();    
    virtual void playAnim(const VfxId id);

protected:    
    VfxGroup* m_physicalItem;
    
    // animation playback
    VappWidget3dPetAnimPlayer *m_animPlayer;
    VfxAnimation              *m_loopAnim;
    VappWidget3dPetAnimTL     *m_loopAnimTL;
    
    VfxId m_animId;    
};


/*****************************************************************************
 * Class : sther subordinate items
 *****************************************************************************/

class VappWidget3dPetRailing : public VappWidget3dPetGroup
{
public: 
    VappWidget3dPetRailing(){m_animId ='UP';};    
protected:    
    virtual void getSceneFile(VfxWString &path) const;    
    virtual void getAnimFile(VfxWString &path) const;
    virtual VfxResId getSceneResId() const;
    virtual VfxResId getAnimResId() const;
    virtual VfxMsec getAnimDuration() const;
};

//////////////////////////////////////////////////////////////////

class VappWidget3dPetGrass : public VappWidget3dPetGroup
{
public: 
    VappWidget3dPetGrass(){m_animId ='GROW';};    
    
protected:    
    virtual void getSceneFile(VfxWString &path) const;    
    virtual void getAnimFile(VfxWString &path) const;
    virtual VfxResId getSceneResId() const;
    virtual VfxResId getAnimResId() const;
    virtual VfxMsec getAnimDuration() const;
public: 
    void configPos(const VfxVector3f pos);
    VfxVector3f getPos(){return m_pos;};  
    VfxVector3f m_pos;
};

//////////////////////////////////////////////////////////////////

class VappWidget3dPetSheepSymbol : public VappWidget3dPetGroup
{
public: 
    VappWidget3dPetSheepSymbol(){};
    VappWidget3dPetSheepSymbol(SheepSymbol symbol){m_animId = symbol;};
    
protected:    
    virtual void getSceneFile(VfxWString &path) const;    
    virtual void getAnimFile(VfxWString &path) const;
    virtual VfxResId getSceneResId() const;
    virtual VfxResId getAnimResId() const;
    virtual VfxMsec getAnimDuration() const;
};

class VappWidget3dPetSheepStage : public VappWidget3dPetGroup
{
public: 
    VappWidget3dPetSheepStage(){};
    VappWidget3dPetSheepStage(VfxGroup *g){m_physicalItem = g;};
    
protected:    
    virtual void getSceneFile(VfxWString &path) const;    
    virtual void getAnimFile(VfxWString &path) const;
    virtual VfxResId getSceneResId() const;
    virtual VfxResId getAnimResId() const;
    virtual VfxMsec getAnimDuration() const;

    virtual void configModel(){};
    virtual void onPlayFinished(VappWidget3dPetAnimPlayer *plyer);

public:    
    virtual void playAnim();    
};

/*****************************************************************************
 * Class : character
 *****************************************************************************/
class VappWidget3ePetSheepInterruptOption 
{
public:
    void configByType(SheepInterrupt type, VfxVector3f pViewer = VfxVector3f());
//    SheepInterrupt getType(){return m_type;};
//    VfxVector3f getViewerPos(){return m_pViewer;};

    SheepInterrupt m_type;
    VfxVector3f m_pViewer;
};

class VappWidget3dPetMovingRecord
{
public:
    VfxVector3f pStart;
    VfxVector3f pDes;
    VfxVector3f pCurrent;
    VfxVector3f pNext;

    VfxVector3f vUnitMove;
    VfxMsec durUnitMove;
    VfxMsec durTotal;
    VfxMsec tMoved;
};

class VappWidget3dPetChar : public VfxGroup
{
    ///VFX_DECLARE_CLASS(VappWidget3dPetChar);
public:  
    VappWidget3dPetChar(){};
    
protected:    
    virtual void configChractorModel() = 0;
    virtual void greet(const VfxVector3f pEye) = 0;
    virtual void sleep(VfxMsec duration) = 0;
    virtual void eat(const VfxMsec duration) = 0;
    virtual void move(const VfxVector3f pMoveTo,
                      const VfxMsec durTurnDiration,
                      const VfxFloat dTurnDiration) = 0;
};

class VappWidget3dPetCharSheep: public VappWidget3dPetChar
{
   // VFX_DECLARE_CLASS(VappWidget3dPetCharSheep);
public:  
    VappWidget3dPetCharSheep();

protected:    
    virtual void onInit();

// note behavior funtions are composed of action operators
protected:
    virtual void configChractorModel();
    virtual void greet(const VfxVector3f pEye);
    virtual void sleep(const VfxMsec duration);
    virtual void eat(const VfxMsec duration);
    virtual void move(const VfxVector3f pMoveTo, 
                      const VfxMsec durTurnDiration,
                      const VfxFloat dTurnDiration);
 
// action operators
private:
    void resetMoveRecord(const VfxVector3f pStart, 
                               const VfxVector3f pDst, 
                               const VfxVector3f pCurrent, 
                               const VfxMsec expectDuration);
    
    void turnDirectionDuringMoving(const VfxFloat theta, 
                                   const VfxVector3f vMove, 
                                   const VfxMsec durTurnDiration);
    void startMove(VfxTimer *timer);
    void endMove(VfxBaseTimeline *timeline, VfxBool isCompleted);

    void walk(const VfxMsec duration);
    void leap(const VfxMsec duration);    
    void onGreet(VappWidget3dPetAnimPlayer *plyer);

// face motion animaiton player
private:
    VfxImageSrc queryFaceImgSrc(const SheepFace face);
    VappWidget3dPetMotion createFaceMotionContent(const SheepFaceStopMotion expression);  

// animation player
private:
    // create animation player     
    VfxS8 getAnimItemId(SheepAnim playerId, VfxId animId);
    void configActionAnim(const SheepAnim id);
    
    // animaiton play finished handle
    void handleWalkAnimFinished(VappWidget3dPetAnimPlayer *plyer);
    void handleSleepAnimFinished(VappWidget3dPetAnimPlayer *plyer);
    void handleGreetAnimFinished(VappWidget3dPetAnimPlayer *plyer);

    // set/get player
    VappWidget3dPetAnimPlayer* getPlayerById(SheepAnim id);    
    void setCurrentActivePlayer(SheepAnim id);

    // stop player
    VfxBool disconnectPlyDefaultCallBackById(SheepAnim id);

// transformation operator
public: 
    void rotatePet(const VfxVector3f axis, const VfxFloat theta);
    void rotatePetEx(const VfxVector3f axis, 
                        const VfxFloat theta, 
                        const VfxBool autoAnimateDisabled,
                        const VfxMsec duration);
    void translatePet(const VfxVector3f v);        
    void translatePetEx(const VfxVector3f v,
                           const VfxBool autoAnimateDisabled,
                           const VfxMsec duration);
    void transformPetEx(const VfxVector3f axis, const VfxFloat theta,
                            const VfxVector3f v,
                            const VfxBool autoAnimateDisabled,
                            const VfxMsec duration);

// implementation
public:
    VfxGroup* getSheep(){return m_physicalSheep;};
    void resetSheepTransformation();
    void getCurrentWorldPos(VfxVector3f &pos);

    VfxVector3f getFrontTo(){return m_nvFront;};
    void setFrontTo(const VfxVector3f nv){m_nvFront = nv;};
    void setPosAndFrontTo(VfxVector3f p, VfxVector3f nvFront);

    void stopAllBehavior();

    // return VFX_TRUE while allow to interrupt sheep cruurent behavior
    VfxBool interrupt(const VappWidget3ePetSheepInterruptOption option);
    VfxBool isPicked(VfxNode *node);
    
    void addGrassToEatList(VappWidget3dPetGrass *grass);
    VfxS32 getGrassCount();

    void addSymbol(const VfxVector3f p, 
                       const SheepSymbol symbol, 
                       const VfxBool randomRotation = VFX_FALSE, 
                       const VfxFloat scaleFactor = 1.f);

    void prepareToJumpRailing(); 
        
    void actionAnimTest(const SheepAnim id);

// state machine implementation
public:
    VfxBool changeState(const VappWidget3dPetCharSheepState newState);
    VappWidget3dPetCharSheepState getState(){return m_state;};   

// state machine transition handle
private:
    void handleStandingState(const VappWidget3dPetCharSheepState oldState);
    void handleStandingState2(VappWidget3dPetAnimPlayer *ply);
    
    void handleIdleState(const VappWidget3dPetCharSheepState oldState);
    void handleMovingState(const VappWidget3dPetCharSheepState oldState);
    void handleGreetingState(const VappWidget3dPetCharSheepState oldState);
    void handleSleepingState(const VappWidget3dPetCharSheepState oldState);
    void handleEatingState(const VappWidget3dPetCharSheepState oldState);

    // state process finished hadle
    void handleSleepFinished(VappWidget3dPetAnimPlayer *plyer);
    void handleEatFinished(VappWidget3dPetAnimPlayer *plyer);

// implementation
private:
    // create translation timeline
    void createTranslationTL();
    
    // set move destination   
    void setDestination(const VfxVector3f p);

    // turn on/off greeting state
    void setIsGreeting(VfxBool b);

    // idle state process
    void startIdleDelayTimer();
    void onIdleStartDelayTimout(VfxTimer* timer);
    void setDestinationRandomly();
    VfxFloat calcuateRandomOffset();    
    void setIsSleepInLastIdleState(const VfxBool b);
    VfxBool getIsSleepInLastIdleState();
    
    // calcultate the minimal roatae angle in degrees
    // note only support rotate sehhp in XY plane now
    VfxFloat calculateMinRotationAngle(const VfxVector3f nvDir1, 
                                       const VfxVector3f nvDir2);

    // interrupt handle
    // return VFX_TRUE while allow to interrupt sheep cruurent behavior
    void handleInterrupted(VappWidget3dPetAnimPlayer *ply);
    void processInterrupScenario(const VappWidget3ePetSheepInterruptOption option);

    // [interrupt] tap on sheep 
    void handleSheepTapped(VappWidget3dPetAnimPlayer *plyer);

    // [interrupt] add new grass 
    void handleAddingNewGrass(VappWidget3dPetAnimPlayer *ply);
    void handleAteGrass(VappWidget3dPetGroup *g);
    
    void getPositionNearToEatGrass(const VfxVector3f pGrass, VfxVector3f &p);    
    VfxBool isGrassInEatArea(VappWidget3dPetGrass *grass);
    VappWidget3dPetGrass* getNearestGrass();  

    void onSymbolZAnimFinished(VappWidget3dPetGroup *z);
    void startSymbolZGenerator(const VfxMsec startDelay, const VfxMsec duration);
    void onSymbolZGeneratorTimeput(VfxTimer *timer);
    void stopSymbolZGenerator(VappWidget3dPetAnimPlayer *ply);

    // jump railing
    void showRailing(const VfxBool showRailing);
    void onJumpRialingFinished(VappWidget3dPetGroup* g);

    static VfxTimelineInterpolationRetEnum jumpIntepolateFunc(
        void *output,
        const void *fromValue,
        const void *toValue,
        VfxTypeIdEnum typeId,
        VfxFloat t, 
        void *data,
        VfxU32 dataSize
    );

    void jumpRailingFinished(VappWidget3dPetAnimPlayer *plyer);
    void jump();
    void setDoJump(const VfxBool b);
    VfxBool getDoJump();

public:
    VfxGroup *m_physicalSheep;
    VfxMesh  *m_headMesh;        // the mesh for change face
    VfxMesh  *m_bodyMesh;

    VappWidget3dPetStopMotionPlayer *m_faceAnimPlayer;

private:
    VappWidget3dPetCharSheepState m_state;  //sheep's state
    VfxVector3f m_nvFront;  // unit vector which pointed direction front of sheep
    VfxVector3f m_pViewer;  // pos in the world coordinate

    VfxList<VappWidget3dPetGrass *> m_grassList;
    VappWidget3dPetGrass *m_eatingGrass;

    // interrupt handle flag
    VfxBool m_isGreeting;
    VfxBool m_doJump;

    // idle start dealy timer    
    VfxTimer *m_idleStartDelaytimer;
    VfxBool m_isSleepInLastIdleState;

    // sleep    
    VfxTimer *m_symbolZGeneratorTimer;
    
    // move
    VfxVector3f m_pDestination;
    VfxTimer   *m_moveTimer;
    VfxMsec     m_movingDuration;
    VappWidget3dPetMovingRecord m_moveRecord;
    VfxVector3fTimeline *m_translationTL;

    // player    
    static VappWidget3dPetAnimItem s_animItems[33];    
    SheepAnim m_currentAnimPlayerID;
    
    VappWidget3dPetAnimPlayer *m_actionAnimPlayer;
    VfxAnimation *m_startAnim;
    VfxAnimation *m_loopAnim;
    VfxAnimation *m_endAnim;
    VappWidget3dPetAnimTL *m_startAnimTL;
    VappWidget3dPetAnimTL *m_loopAnimTL;
    VappWidget3dPetAnimTL *m_endAnimTL;    

    // jump railing
    VappWidget3dPetRailing *m_railing;
    
public:
    const static VfxS32 RANDOE_MOVE_OFFSET = 120;    
    const static VfxS32 RANDOE_TURN_DIRECTION = 30;
    const static VfxFloat s_walkAvgVelocity;
    const static VfxS32 EAT_AREA_R = 80; 
};


/*****************************************************************************
 * Class :develop frame
 *****************************************************************************/
class VappWidget3dPetDevelopFrame : public VfxFrame
{
    VFX_DECLARE_CLASS(VappWidget3dPetDevelopFrame); 
public:
    VappWidget3dPetDevelopFrame(){};

    VfxSignal1<VfxU8> m_sigDevHotKeyClicked;
    VfxSignal3<VfxS32, VfxS32, VfxS32> m_sigDevTranslation;
    VfxSignal1<VfxFloat> m_sigDevScale;
    VfxSignal2<VfxVector3f, VfxFloat> m_sigDevRotation;
    VfxSignal1<VfxBool> m_sigAutoAnimaitonEnabled;
    VfxSignal0 m_sigCameraUpdated;

protected:
    virtual void onInit();
private:
    enum
    {
        HK_0,
        HK_1,
        HK_2,
        HK_3,
        HK_4, 
        HK_5,
        HK_6,
        HK_7,
        HK_8,
        HK_9,
        HK_10,
        HK_END
    };
    
    void onHotKeyBtnClicked(VfxObject *sender, VfxId id);
    void onTransformationBtnClicked(VfxObject *sender, VfxId id);
    void onCameraBtnClicked(VfxObject *sender, VfxId id);
    void createTransformationBtn(const VfxWString &str, const VfxId id, const VfxColor &color, const VfxS32 w, const VfxS32 h, const VfxS32 x, const VfxS32 y);    
    void createCameraBtn(const VfxWString &str, const VfxId id, const VfxColor &color, const VfxS32 w, const VfxS32 h, const VfxS32 x, const VfxS32 y);    
};

/*****************************************************************************
 * Class : stage frame
 *****************************************************************************/
class VappWidget3dPetWorld : public VfxControl
{
    //VFX_DECLARE_CLASS(VappWidget3dPetWorld);
public:
    VappWidget3dPetWorld(): m_world(NULL),
                            m_camera(NULL),
                            m_light(NULL) {};
   
protected:
    // config scene related data
    virtual void configScene() = 0;
    
    // calculate the intersection point of an arbitrarily incident ray and the stage plane
    virtual void getIntersectionOnBoard(
        const VfxVector3f pRay, 
        const VfxVector3f vRay, 
        VfxVector3f& pos) = 0;

    // return true while the point p is located outside the stage borad
    virtual VfxBool isOutOfBounds(const VfxVector3f p) = 0;

    // get camera position in world coordinate
    virtual void getCameraPos(VfxVector3f &pCamera, const VfxBool queryVfx = VFX_FALSE)
    {
        VFX_ASSERT(m_camera);
        VfxVector3f pVFX, pVRT;
        m_camera->getWorldPosition(pVFX);
        m_camera->forceGetTranslation(pVRT);
        pCamera = pVFX;
    };

    virtual void getCameraRotation(VfxQuaternionf &q)
    {
        VFX_ASSERT(m_camera);
        m_camera->forceGetRotation(q);
    }
protected:
    VfxWorld *m_world;    
    VfxCamera *m_camera;
    VfxLight *m_light;
};


class VappWidget3dPetSheepWorld : public VappWidget3dPetWorld
{
    VFX_DECLARE_CLASS(VappWidget3dPetSheepWorld); 
public:
    VappWidget3dPetSheepWorld();

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual VfxBool onPenInput(VfxPenEvent &event);

// override for VappWidget3dPetWorld
protected:
    virtual void configScene();

    virtual void getIntersectionOnBoard(
        const VfxVector3f pRay, 
        const VfxVector3f vRay, 
        VfxVector3f& pos);
    
    virtual VfxBool isOutOfBounds(const VfxVector3f p);

// implementation
public:
    void rotateViewAngle(const VfxVector3f axis, const VfxFloat theta);

    void changeViewAngle(const VfxVector3f axis, const VfxFloat theta, const VfxBool treatAsEnd = VFX_FALSE);
    void changeViewAngle2(VfxBaseTimeline *timeline, VfxBool isCompleted);
    void swipCamera(const VfxId id);
    void resetCameraRotation();

    void getSheepPosAndFrontTo(VfxVector3f &p, VfxVector3f &nvFront);
    void setSheepPosAndFrontTo(VfxVector3f p, VfxVector3f nvFront);

    // start sheep start dealy timer
    void launchStartDelayTimer(const VfxMsec duration);
    
// implementation
private:
    // add grass to stage
    void addGrass(const VfxVector3f p);
    
    // sheep start dealy time out handle
    void onStartDelayTimeOut(VfxTimer *timer);
    

// develop utility
public: 
    void slotDevHotKeyClicked(VfxU8 id);
    void slotDevTranslationChanged(VfxS32 x, VfxS32 y, VfxS32 z);
    void slotDevScaleChanged(VfxFloat s);
    void slotDevRotationChanged(VfxVector3f axis, VfxFloat theta);
    void slotAutoAnimaitonEnabled(VfxBool isEnabled);
    void slotCameraUpdated();
    void printPetPos();
    void printCameraPos();

public: 
    static const VfxU8 MAX_GRASS_IN_SHEEP_WORLD = 3;
    
private:     
    VappWidget3dPetCharSheep *m_sheep;
    VfxQuaternionfTimeline *m_cameraQTL;    
    VfxQuaternionf m_rqCamera;
    VfxMesh *m_jumpBtn;
    VappWidget3dPetSheepStage *m_stage;    
};


/*****************************************************************************
 * Class : VappWidget3dPet
 *****************************************************************************/

class VappWidget3dPet : public VappWidgetMiniStage
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidget3dPet);

public:
    enum
    {
#if defined(__MMI_MAINLCD_480X800__)
        MAX_SIZE_WIDTH = 480,
        MAX_SIZE_HEIGHT = 480,
        WIDTH  = 480,
        HEIGHT = 480,
        EDIT_BTN_OFFSET_X = 48,
        EDIT_BTN_OFFSET_Y = 48,    
#elif defined(__MMI_MAINLCD_320X480__)
        MAX_SIZE_WIDTH = 320,
        MAX_SIZE_HEIGHT = 336,
        WIDTH  = 320,
        HEIGHT = 336,
        EDIT_BTN_OFFSET_X = 32,
        EDIT_BTN_OFFSET_Y = 36,
#elif defined(__MMI_MAINLCD_240X400__)
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 280,
        WIDTH  = 210,
        HEIGHT = 284,
        EDIT_BTN_OFFSET_X = 21,
        EDIT_BTN_OFFSET_Y = 28,    
#elif defined(__MMI_MAINLCD_240X320__)
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 210,
        WIDTH  = 240,
        HEIGHT = 210,
        EDIT_BTN_OFFSET_X = 24,
        EDIT_BTN_OFFSET_Y = 21,   
#else
        MAX_SIZE_WIDTH = 320,
        MAX_SIZE_HEIGHT = 336,
        WIDTH  = 320,
        HEIGHT = 336,
        EDIT_BTN_OFFSET_X = 32,
        EDIT_BTN_OFFSET_Y = 36, 
#endif
        END_OF_ENUM
    };

public:
    VappWidget3dPet();

// override
public:
    virtual VappWidgetId getId() const;
    virtual VfxSize getMaxSize() const;
    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;
    virtual VfxFrame *createIcon(VfxObject *parentObj);
    virtual void onRotateX(VfxFloat angle);
    virtual void onSwipeUp();
    virtual void onSwipeDown();    
    virtual void onSwipeToNearestView();
    virtual void onRestoreView(VfxArchive *ar);
    virtual void onSerializeView(VfxArchive * ar);
    virtual void onCreateView();
    virtual void onReleaseView();
    virtual VfxPoint onGetEditButtonOffset();
    // Override this virtual to suspend widget
    virtual void onSuspend();
    // Override this virtual to resume widget
    virtual void onResume();

private:
    void createContent(VfxArchive * ar, const VfxBool needReadFromArchive);
    void closeContent(VfxArchive * ar, const VfxBool needWriteToArchive);
    void readFromArchive(VfxArchive *ar, VfxVector3f & p,VfxVector3f & nvFront);
    void writeToArchive(VfxArchive *ar);
    void createDevelopFrame();
    
    VappWidget3dPetSheepWorld *m_petFrame;
    VappWidget3dPetDevelopFrame *m_developFrame;
};

#endif /* defined(__COSMOS_3D_V10__) */
#endif /* VAPP_WIDGET_3D_PET_H */


