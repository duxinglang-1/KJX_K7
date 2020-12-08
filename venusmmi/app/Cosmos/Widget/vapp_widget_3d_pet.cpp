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
 *  vapp_widget_3d_pet.cpp
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

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_3D_PET__)

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "vapp_widget_3d_Pet.h"
#include "Mmi_rp_vapp_widget_3d_pet_def.h"
#include "vcp_include.h"

// 3D related include file
#include "Vfx_world.h"
#include "Vfx_mesh.h"
#include "Vfx_node.h"
#include "Vfx_material.h"
#include "vfx_asset_loader.h"
#include "vrt_math.h"
#include "vfx_pass.h"
#include "vfx_shader_uniforms.h"
#include "vfx_texture.h"
#include "vfx_render_buffer.h"
#include "vfx_compositing_mode.h"
#include "vfx_bounding_volume.h"
#include "vfx_renderer.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
// utitliy
#if defined(__MTK_INTERNAL__) && defined(__MTK_TARGET__) && defined(__MM_DEBUG_MEASURE__)
#ifdef __cplusplus
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef __cplusplus
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#else
#define PET_MEASURE_TIME_START(_symbol_)
#define PET_MEASURE_TIME_STOP(_symbol_)
#endif

#define DEGREES_TO_RADIANS(D) D * VFX_PI / 180.f
#define RADIANS_TO_DEGREES(R) 180.f * R / VFX_PI

// constant
#define VAPP_WIDGET_3d_PET_TRANSITION_DURATION 300
#define VAPP_WIDGET_3d_PET_SHEEP_EAT_FACE_REPEAT_DURATION   1000

// resource related control
static VfxBool g_isDebugMode = VFX_FALSE;
static VfxBool g_isResMode = VFX_TRUE;

// static
static  VfxVector3f g_tCamera = VfxVector3f(0,0,0);
static VfxFloat g_ryCamera = 0;

/***************************************************************************** 
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidget3dPetStopMotionPlayer", VappWidget3dPetStopMotionPlayer, VfxObject);
VFX_IMPLEMENT_CLASS("VappWidget3dPetSheepWorld", VappWidget3dPetSheepWorld, VappWidget3dPetWorld);
VFX_IMPLEMENT_CLASS("VappWidget3dPetDevelopFrame", VappWidget3dPetDevelopFrame, VfxFrame);
VAPP_WIDGET_IMPLEMENT_CLASS(VappWidget3dPet, VappWidgetMiniStage);
VAPP_WIDGET_SYS_PUBLISH_NATIVE(VappWidget3dPet, VAPP_WIDGET_TYPE_3D_PET, VappWidget3dPetPublisher);

/*****************************************************************************
 * stop motion animation
 *****************************************************************************/
VappWidget3dPetStopMotionPlayer::VappWidget3dPetStopMotionPlayer()
                                    :m_target(NULL),
                                    m_animTimer(NULL),
                                    m_isRepeated(VFX_FALSE),
                                    m_repeatedDuration(0),
                                    m_motionTimer(NULL),
                                    m_tex2D(NULL),
                                    m_img2D(NULL)
{
}

void VappWidget3dPetStopMotionPlayer::play(VappWidget3dPetMotion motion, 
                                          VfxBool isRepeated, 
                                          VfxMsec repeatedDuration)
{
    stop();
    
    setCurrentMotion(motion);
    m_isRepeated = isRepeated;
    m_repeatedDuration = repeatedDuration;

    startAnimTimer();
}

void VappWidget3dPetStopMotionPlayer::stop()
{
    if(m_motionTimer)
        m_motionTimer->stop();
    if(m_animTimer)
        m_animTimer->stop();
}

void VappWidget3dPetStopMotionPlayer::setCurrentMotion(VappWidget3dPetMotion motion)
{
    m_currentMotion = motion;
}

void VappWidget3dPetStopMotionPlayer::motion()
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);    
    changeFrame(m_currentMotion.getMotionImgSrc());
    VfxAutoAnimate::commit();

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_FALSE);    
    VfxAutoAnimate::setDuration(m_currentMotion.getMotioningDuration());
    changeFrame(m_currentMotion.getMotioningImgSrc());
    VfxAutoAnimate::commit();

    // create motion timer
    if(NULL == m_motionTimer)
    {
        VFX_OBJ_CREATE(m_motionTimer, VfxTimer, this);
    }
    // start motion timer
    m_motionTimer->m_signalTick.connect(this, &VappWidget3dPetStopMotionPlayer::motioning);    
    startMotionTimer(m_currentMotion.getMotionDuration());
}

void VappWidget3dPetStopMotionPlayer::motioning(VfxTimer *timer)
{
    timer->stop();
    m_motionTimer->m_signalTick.disconnect(this, &VappWidget3dPetStopMotionPlayer::motioning);

    m_motionTimer->m_signalTick.connect(this, &VappWidget3dPetStopMotionPlayer::motioned);
    startMotionTimer(m_currentMotion.getMotioningDuration());
}

void VappWidget3dPetStopMotionPlayer::motioned(VfxTimer *timer)
{
    timer->stop();
    m_motionTimer->m_signalTick.disconnect(this, &VappWidget3dPetStopMotionPlayer::motioned);

    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_FALSE);    
    VfxAutoAnimate::setDuration(m_currentMotion.getMotionedDuration());
    changeFrame(m_currentMotion.getMotionedImgSrc());
    VfxAutoAnimate::commit();
}

void VappWidget3dPetStopMotionPlayer::startMotionTimer(const VfxMsec duration)
{   
    m_motionTimer->setStartDelay(duration);
    m_motionTimer->setDuration(duration);
    m_motionTimer->start();    
}

void VappWidget3dPetStopMotionPlayer::changeFrame(const VfxImageSrc &imgSrc)
{
    // get pass
    VfxPass *pass = m_target->getMaterial(0)->getPass(0);
    VfxShaderVariable *varTex = pass->getUniformVariable(VFX_STR("uDiffuseSampler"));

    // create the new texture
    VfxImage2D *img2D;
    VFX_OBJ_CREATE_EX(img2D, VfxImage2D, pass, (imgSrc));
    VfxTexture2D *tex2D;
    VFX_OBJ_CREATE_EX(tex2D, VfxTexture2D, pass, (img2D));

    // update texture
    varTex->setValue(tex2D);
    pass->setPropertyDirty(VFX_PASS_SHADER_UNIFORMS_DIRTY);	

    // release previous resources
    VFX_OBJ_CLOSE(m_tex2D);
    VFX_OBJ_CLOSE(m_img2D);
    m_img2D = img2D;
    m_tex2D = tex2D;	
}

void VappWidget3dPetStopMotionPlayer::startAnimTimer()
{
    if(NULL == m_animTimer)
    {
        VFX_OBJ_CREATE(m_animTimer, VfxTimer, this);
        m_animTimer->m_signalTick.connect(this, &VappWidget3dPetStopMotionPlayer::onAnimTimeout);
    }
    // note m_repeatedDuration indicates the duration for repeating a motion anim
    m_animTimer->setStartDelay(m_repeatedDuration);
    m_animTimer->setDuration(m_repeatedDuration);
    m_animTimer->start();
    // start stop-motion anim immediately
    motion();
}
void VappWidget3dPetStopMotionPlayer::onAnimTimeout(VfxTimer *timer)
{
    if(!m_isRepeated)
    {
        timer->stop();
        return;
    }

    motion();
}

/*****************************************************************************
 * Animation playback control
 *****************************************************************************/
VappWidget3dPetAnimTL::VappWidget3dPetAnimTL():m_anim(NULL),
                                                        m_tlDuration(0)
{
}
void VappWidget3dPetAnimTL::configAnimation(VfxAnimation *anim)
{
    configAnimationEx(anim, 1000, 0.f, 1.f, 1, VFX_FALSE);
}

void VappWidget3dPetAnimTL::configAnimationEx(VfxAnimation *anim, 
                                    const VfxMsec duration,
                                    const VfxFloat fromValue,
                                    const VfxFloat toValue, 
                                    const VfxS32 repeateCount,
                                    const VfxFloat isAutoReversed)
{        
    setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    setPlaybackPara(duration, fromValue, toValue, repeateCount, isAutoReversed);

    m_anim = anim; 
    m_anim->setTimelineTime(this);
}

void VappWidget3dPetAnimTL::setPlaybackPara(const VfxMsec duration,
                                                 const VfxFloat fromValue,
                                                 const VfxFloat toValue,
                                                 const VfxS32 repeateCount,
                                                 const VfxFloat isAutoReversed)
{
    m_tlDuration = duration;

    // set to timeline
    setDuration(duration);
    setFromValue(fromValue);
    setToValue(toValue);    
    setRepeatCount(repeateCount);
    setAutoReversed(isAutoReversed);
}


VFX_IMPLEMENT_CLASS("VappWidget3dPetAnimPlayer", VappWidget3dPetAnimPlayer, VfxObject);

VappWidget3dPetAnimPlayer::VappWidget3dPetAnimPlayer()
                                :m_shouldLoopTLRepeatInifinte(VFX_FALSE),
                                m_startAnimTL(NULL),
                                m_loopAnimTL(NULL),
                                m_endAnimTL(NULL),
                                m_duration(0),
                                m_loopRepeatCount(1),
                                m_alreadyRepeated(0),
                                m_needStop(VFX_FALSE)
{
}
void VappWidget3dPetAnimPlayer::configAnimTL(
                        VappWidget3dPetAnimTL *startTL, 
                        VappWidget3dPetAnimTL *loopTL, 
                        VappWidget3dPetAnimTL *endTL)
{    
    VFX_ASSERT(startTL || loopTL || endTL);
    
    forceStop();

    m_startAnimTL = startTL;
    m_loopAnimTL  = loopTL;
    m_endAnimTL   = endTL;

    // reset whole duration    
    // note m_duraiton = start(1) + loop(1) + end(1)
    m_duration = 0;
    if(m_startAnimTL){m_duration += m_startAnimTL->getTLDuraion();}
    if(m_loopAnimTL) {m_duration += m_loopAnimTL->getTLDuraion();}
    if(m_endAnimTL)  {m_duration += m_endAnimTL->getTLDuraion();}

    // reset loop repeate related parametor
    setShouldLoopTLRepeatInifinte(VFX_FALSE);
    setLoopRepeatCount(1);
    resetLoopPlayedRecord();
}

VfxBool VappWidget3dPetAnimPlayer::isEndAnimPlaying() const
{
    if(NULL == m_endAnimTL)
    {
        return VFX_FALSE;
    }

    if(m_endAnimTL->getIsEnabled())
    {
        return VFX_TRUE;
    }

    return VFX_FALSE;
}

void VappWidget3dPetAnimPlayer::stop()
{
    m_needStop = VFX_TRUE;
}

void VappWidget3dPetAnimPlayer::stopEx()
{
    // TODO: if user call stopEx during play startAnim
    if(m_startAnimTL)
    {        
        m_startAnimTL->m_signalStopped.disconnect(this, &VappWidget3dPetAnimPlayer::onStartTLStopped);
        m_startAnimTL->stop();
    }
    if(m_loopAnimTL)
    {        
        m_loopAnimTL->m_signalStopped.disconnect(this, &VappWidget3dPetAnimPlayer::onLoopTLStopped);
        m_loopAnimTL->stop(); 
    }

    if(m_endAnimTL)
    {
        playEndTL();
        return;
    }
    m_sigPlayFinished.emit(this);
    return;   
}

void VappWidget3dPetAnimPlayer::forceStop()
{
    if(m_startAnimTL)
    {        
        m_startAnimTL->m_signalStopped.disconnect(this, &VappWidget3dPetAnimPlayer::onStartTLStopped);
        m_startAnimTL->stop();
    }
    if(m_loopAnimTL)
    {        
        m_loopAnimTL->m_signalStopped.disconnect(this, &VappWidget3dPetAnimPlayer::onLoopTLStopped);
        m_loopAnimTL->stop(); 
    }
    if(m_endAnimTL)
    {        
        m_endAnimTL->m_signalStopped.disconnect(this, &VappWidget3dPetAnimPlayer::onEndTLStopped);
        m_endAnimTL->stop();  
    }
}

void VappWidget3dPetAnimPlayer::play()
{    
    playEx(VFX_FALSE, 1);
}

void VappWidget3dPetAnimPlayer::play(const VfxMsec duration)
{ 
    if(PLAY_ONCE == duration)
    {
        playEx(VFX_FALSE, 1);
        return;
    }
    if(0 == duration || PLAY_INFINITE == duration)
    {
        playEx(VFX_TRUE, VFX_TIMELINE_REPEAT_INFINITE);
        return;
    }
    
    // TODO: duration should not include either startTL.duration or endTL.duration
    VfxS32 repeatCount = (VfxS32)(vfxCeil(duration / (m_loopAnimTL->getTLDuraion())));
    if(0 == repeatCount)
    {
       m_loopAnimTL->setDuration(duration);
       repeatCount = 1;
    }
    playEx(VFX_FALSE, repeatCount);
}

void VappWidget3dPetAnimPlayer::playEx(const VfxBool souldLoopRepeatInifinte, const VfxS32 repeateCount)
{
    resetLoopPlayedRecord();
    setShouldLoopTLRepeatInifinte(souldLoopRepeatInifinte);
    setLoopRepeatCount(repeateCount);
    if(m_startAnimTL){playStartTL();}
	else{playLoopTL();}    
}

void VappWidget3dPetAnimPlayer::resetLoopPlayedRecord()
{
    m_alreadyRepeated = 0;
    m_needStop = VFX_FALSE;
}
void VappWidget3dPetAnimPlayer::setShouldLoopTLRepeatInifinte(const VfxBool b)
{
    m_shouldLoopTLRepeatInifinte = b;
}
void VappWidget3dPetAnimPlayer::setLoopRepeatCount(const VfxS32 repeateCount)
{
    m_loopRepeatCount = repeateCount;
}

void VappWidget3dPetAnimPlayer::playStartTL()
{
    if(m_startAnimTL)
    {
        m_startAnimTL->m_signalStopped.connect(this, &VappWidget3dPetAnimPlayer::onStartTLStopped);
        m_startAnimTL->start();
    }
}
void VappWidget3dPetAnimPlayer::playLoopTL()
{
    m_loopAnimTL->m_signalStopped.connect(this, &VappWidget3dPetAnimPlayer::onLoopTLStopped);
    m_loopAnimTL->start();
}
void VappWidget3dPetAnimPlayer::playEndTL()
{
    if(m_endAnimTL)
    {
        m_endAnimTL->m_signalStopped.connect(this, &VappWidget3dPetAnimPlayer::onEndTLStopped);
        m_endAnimTL->start();
    }
}

void VappWidget3dPetAnimPlayer::onStartTLStopped(VfxBaseTimeline *timeline, VfxBool isCompleted)
{    
    if(isCompleted)
    {
        m_startAnimTL->m_signalStopped.disconnect(this, &VappWidget3dPetAnimPlayer::onStartTLStopped);
        playLoopTL();
    }
}

void VappWidget3dPetAnimPlayer::onLoopTLStopped(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if(isCompleted)
    {
        m_alreadyRepeated ++;

        if(m_needStop ||
        (!m_shouldLoopTLRepeatInifinte && (m_alreadyRepeated >= m_loopRepeatCount)))
        {
            m_loopAnimTL->m_signalStopped.disconnect(this, &VappWidget3dPetAnimPlayer::onLoopTLStopped);
            m_sigLoopAnimFinished.emit(this);
            if(NULL == m_endAnimTL)
            {
                m_sigPlayFinished.emit(this);
                return;
            }
            playEndTL();
            return;
        }

        m_loopAnimTL->start(); 
    }
}

void VappWidget3dPetAnimPlayer::onEndTLStopped(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    if(isCompleted)
    {
        m_endAnimTL->m_signalStopped.disconnect(this, &VappWidget3dPetAnimPlayer::onEndTLStopped);
        m_sigPlayFinished.emit(this);
    }
}

/*****************************************************************************
 * VappWidget3dPetGroup
 *****************************************************************************/

VappWidget3dPetGroup::VappWidget3dPetGroup() 
                    : m_physicalItem(NULL),
                      m_animPlayer(NULL),
                      m_loopAnim(NULL),
                      m_loopAnimTL(NULL)
{}

void VappWidget3dPetGroup::onInit()
{
    VfxGroup::onInit();
    
    configModel();
}

void VappWidget3dPetGroup::configModel()
{
    if(NULL == m_physicalItem)
    {
        VFX_OBJ_CREATE(m_physicalItem, VfxGroup, this);
    }    
    
    if(g_isResMode)
    {
        VfxAssetLoader::loadScene(m_physicalItem, getSceneResId());
    }
    else
    {
        VfxWString path = VFX_WSTR_EMPTY;
        getSceneFile(path);
        VfxAssetLoader::loadScene(m_physicalItem, path);
    }
}

VfxBool VappWidget3dPetGroup::isPicked(VfxNode *node)
{    
    VFX_UNUSED(node);
    return VFX_FALSE;
}

void VappWidget3dPetGroup::configAnim()
{
    if(NULL == m_animPlayer)
    {
        VFX_OBJ_CREATE(m_animPlayer, VappWidget3dPetAnimPlayer, this);
    }

    if(m_animPlayer)
    {
        VfxWString path = VFX_WSTR_EMPTY;
        getAnimFile(path);
        
        VfxMsec duraiton = getAnimDuration();    
        VfxResId res = getAnimResId();

        VfxAnimation *loopAnim = NULL;
	    VFX_OBJ_CREATE(loopAnim, VfxAnimation, m_physicalItem); 

        if(g_isResMode)
	        VfxAssetLoader::loadAnimation(loopAnim, m_physicalItem, res);
        else    
	        VfxAssetLoader::loadAnimation(loopAnim, m_physicalItem, path);

        // animation playerback control timeline
        VappWidget3dPetAnimTL *loopAnimTL = NULL;
        VFX_OBJ_CREATE(loopAnimTL, VappWidget3dPetAnimTL, m_physicalItem);
        loopAnimTL->configAnimationEx(loopAnim, duraiton, 0.f, 1.f, 1, VFX_FALSE);
	    loopAnimTL->setTarget(m_physicalItem);
    
        // config to animaiton player        
        m_animPlayer->configAnimTL(NULL, loopAnimTL, NULL);

        // close old anim and tl
        VFX_OBJ_CLOSE(m_loopAnim);
        VFX_OBJ_CLOSE(m_loopAnimTL);
        m_loopAnim = loopAnim;
        m_loopAnimTL = loopAnimTL;
    }    
}

void VappWidget3dPetGroup::playAnim()
{
    configAnim();
    m_animPlayer->m_sigPlayFinished.connect(this, &VappWidget3dPetGroup::onPlayFinished);
    m_animPlayer->play();  
}

void VappWidget3dPetGroup::playAnim(const VfxId id)
{
    setAnimId(id);
    playAnim();
}

void VappWidget3dPetGroup::onPlayFinished(VappWidget3dPetAnimPlayer *plyer)
{
    m_animPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetGroup::onPlayFinished);
    m_sigAnimFinished.emit(this);
}

/*****************************************************************************
 * Other subordinate items
 *****************************************************************************/

void VappWidget3dPetRailing::getSceneFile(VfxWString &path) const
{
    path = VFX_WSTR("E:\\Sheep_v3\\railing\\railing.scn");
}

void VappWidget3dPetRailing::getAnimFile(VfxWString &path) const
{
    if('UP' == m_animId)        
        path = VFX_WSTR("E:\\Sheep_v3\\railing\\railing_0_666.ani");
    else        
        path = VFX_WSTR("E:\\Sheep_v3\\railing\\railing_833_1300.ani");
}

VfxResId VappWidget3dPetRailing::getSceneResId() const
{
    return VAPP_WIDGET_3D_PET_RAILING;
}

VfxResId VappWidget3dPetRailing::getAnimResId()const
{
    if('UP' == m_animId)
        return VAPP_WIDGET_3D_PET_RAILING_UP_ANIM;
    else 
        return VAPP_WIDGET_3D_PET_RAILING_DOWN_ANIM;
}

VfxMsec VappWidget3dPetRailing::getAnimDuration() const
{
    if('UP' == m_animId){return 666;}
    else{return 467;}
}

////////////////////////////////////////////////////////////////////////////////

void VappWidget3dPetGrass::getSceneFile(VfxWString &path) const
{
    path = VFX_WSTR("E:\\Sheep_v3\\grass\\grass.scn");
}

void VappWidget3dPetGrass::getAnimFile(VfxWString &path) const
{
    if('GROW' == m_animId)        
        path = VFX_WSTR("E:\\Sheep_v3\\grass\\grass_0_1666.ani");
    else        
        path = VFX_WSTR("E:\\Sheep_v3\\grass\\grass_2000_2666.ani");
}

VfxResId VappWidget3dPetGrass::getSceneResId() const
{
    return VAPP_WIDGET_3D_PET_GRASS_SCENE;
}

VfxResId VappWidget3dPetGrass::getAnimResId()const
{
    if('GROW' == m_animId)
        return VAPP_WIDGET_3D_PET_GRASS_GROW_ANIM;
    else 
        return VAPP_WIDGET_3D_PET_GRASS_CLEAN_ANIM;
}

VfxMsec VappWidget3dPetGrass::getAnimDuration() const
{
    if('GROW' == m_animId){return 300;}
    else{return 666;}
}

void VappWidget3dPetGrass::configPos(const VfxVector3f pos)
{
    m_pos = pos;
    setTranslation(pos);
}

void VappWidget3dPetSheepSymbol::getSceneFile(VfxWString &path) const
{
    switch(m_animId)
    {
        case SYM_TEXT_Z:
            path = VFX_WSTR("E:\\Sheep_v3\\text_Z\\text_Z.scn");
            break;
        case SYM_TEXT_E:
            path = VFX_WSTR("E:\\Sheep_v3\\text_E\\text_E.scn");
            break;
        case SYM_TEXT_Q:
            path = VFX_WSTR("E:\\Sheep_v3\\text_Q\\text_Q.scn");
            break;
        case SYM_TEXT_1_UP:
            path = VFX_WSTR("E:\\Sheep_v3\\text_1up\\text_1up.scn");
            break;
        default:
            path = VFX_WSTR_EMPTY;
            break;
    }            
}
void VappWidget3dPetSheepSymbol::getAnimFile(VfxWString &path) const
{
    switch(m_animId)
    {
        case SYM_TEXT_Z:
            path = VFX_WSTR("E:\\Sheep_v3\\text_Z\\text_Z.ani");
            break;
        case SYM_TEXT_E:
            path = VFX_WSTR("E:\\Sheep_v3\\text_E\\text_E.ani");
            break;
        case SYM_TEXT_Q:
            path = VFX_WSTR("E:\\Sheep_v3\\text_Q\\text_Q.ani");
            break;
        case SYM_TEXT_1_UP:
            path = VFX_WSTR("E:\\Sheep_v3\\text_1up\\text_1up.ani");
            break;
        default:
            path = VFX_WSTR_EMPTY;
            break;
    }  
}
VfxResId VappWidget3dPetSheepSymbol::getSceneResId() const
{
    switch(m_animId)
    {
        case SYM_TEXT_Z:
            return VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_Z;
        case SYM_TEXT_E:
            return VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_E;
        case SYM_TEXT_Q:
            return VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_Q;
        case SYM_TEXT_1_UP:
            return VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_1UP;
        default:
            return VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_Z;
    }  
}
VfxResId VappWidget3dPetSheepSymbol::getAnimResId() const
{
    switch(m_animId)
    {
        case SYM_TEXT_Z:
            return VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_Z_ANIM;
        case SYM_TEXT_E:
            return VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_E_ANIM;
        case SYM_TEXT_Q:
            return VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_Q_ANIM;
        case SYM_TEXT_1_UP:
            return VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_1UP_ANIM;
        default:
            return VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_Z_ANIM;
    }  
}
VfxMsec VappWidget3dPetSheepSymbol::getAnimDuration() const
{
    switch(m_animId)
    {
        case SYM_TEXT_Z:
            return 1500;
        case SYM_TEXT_E:
            return 2000;
        case SYM_TEXT_Q:
            return 2000;
        case SYM_TEXT_1_UP:
            return 1000;
        default:
            return 0;
    }  
}

void VappWidget3dPetSheepStage::getSceneFile(VfxWString &path) const
{
    path = VFX_WSTR("E:\\Sheep_v3\\stage\\stage.scn");
}

void VappWidget3dPetSheepStage::getAnimFile(VfxWString &path) const
{
    path = VFX_WSTR("E:\\Sheep_v3\\stage\\stage.ani");
}

VfxResId VappWidget3dPetSheepStage::getSceneResId() const
{
    return VAPP_WIDGET_3D_PET_SHEEP_STAGE;
}

VfxResId VappWidget3dPetSheepStage::getAnimResId() const
{
    return VAPP_WIDGET_3D_PET_SHEEP_STAGE_ANIM;
}

VfxMsec VappWidget3dPetSheepStage::getAnimDuration() const
{
    return 333;
}

void VappWidget3dPetSheepStage::playAnim()
{
    configAnim();
    m_animPlayer->m_sigPlayFinished.connect(this, &VappWidget3dPetSheepStage::onPlayFinished);
    m_animPlayer->play();  
}
void VappWidget3dPetSheepStage::onPlayFinished(VappWidget3dPetAnimPlayer *plyer)
{
    m_animPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetSheepStage::onPlayFinished);
    VFX_OBJ_CLOSE(m_animPlayer);
    
    m_sigAnimFinished.emit(this);
}

/*****************************************************************************
 * Character
 *****************************************************************************/
const VfxFloat VappWidget3dPetCharSheep::s_walkAvgVelocity = (float) STAGE_BOARD_WIDTH / 5.f;
VappWidget3dPetCharSheep::VappWidget3dPetCharSheep():
                                            m_state(SHEEP_INIT),
                                            m_physicalSheep(NULL),
                                            m_headMesh(NULL),
                                            m_bodyMesh(NULL),
                                            m_isGreeting(VFX_FALSE),
                                            m_doJump(VFX_FALSE),
                                            m_idleStartDelaytimer(NULL),
                                            m_isSleepInLastIdleState(VFX_FALSE),
                                            m_symbolZGeneratorTimer(NULL),
                                            m_moveTimer(NULL),
                                            m_translationTL(NULL),
                                            m_actionAnimPlayer(NULL),
                                            m_startAnim(NULL),
                                            m_loopAnim(NULL), 
                                            m_endAnim(NULL),
                                            m_startAnimTL(NULL),
                                            m_loopAnimTL(NULL),
                                            m_endAnimTL(NULL),
                                            m_railing(NULL),
                                            m_faceAnimPlayer(NULL),
                                            m_currentAnimPlayerID(SHEEP_ANIM_END),
                                            m_eatingGrass(NULL)
{
}

void VappWidget3dPetCharSheep::onInit()
{
    VappWidget3dPetChar::onInit();
    configChractorModel();
    resetSheepTransformation();

    m_grassList.init(this);

    setAutoAnimate(VFX_TRUE);
}

void VappWidget3dPetCharSheep::configChractorModel()
{
    // create physical sheep object to load chr scene
    if(NULL == m_physicalSheep)
    {
        VFX_OBJ_CREATE(m_physicalSheep, VfxGroup, this);
    }
    
    // load charactor recource
    if(g_isResMode)
        VfxAssetLoader::loadSceneBegin(m_physicalSheep, VAPP_WIDGET_3D_PET_SHEEP_CHR);
    else
        VfxAssetLoader::loadSceneBegin(m_physicalSheep, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep.chr"));

    VfxGroup *sheepBip = NULL;
    do
    {
        // head releated control 
        VfxString strHeadMesh = VFX_STR("sheep_head-node");
        VfxString strBodyMesh = VFX_STR("sheep_body-node");
        m_headMesh = (VfxMesh *)VfxAssetLoader::findObjByName(strHeadMesh); 
        m_bodyMesh = (VfxMesh *)VfxAssetLoader::findObjByName(strBodyMesh);    
    }while(0);
    VfxAssetLoader::loadSceneEnd();

    // set pickable 
    if(m_headMesh)     m_headMesh->setPickable(VFX_TRUE);
    if(m_bodyMesh)     m_bodyMesh->setPickable(VFX_TRUE);

    // correct sheep's center point to the origin of its local coordinate
    if(sheepBip)
    {
        VfxMatrix4f mat = sheepBip->getPivot();
        mat.inverse();
        m_physicalSheep->setTranslation(- mat.col[3].x, - mat.col[3].y, 0.f);
    }

    // face motion animation player
    if(m_faceAnimPlayer)
    {
        m_faceAnimPlayer->stop();
        VFX_OBJ_CLOSE(m_faceAnimPlayer);
    }
    VFX_OBJ_CREATE(m_faceAnimPlayer, VappWidget3dPetStopMotionPlayer, m_physicalSheep);
    if(m_faceAnimPlayer){m_faceAnimPlayer->configTarget(m_headMesh);}  

    // workaround
    if(NULL == m_actionAnimPlayer)
    {
        VFX_OBJ_CREATE(m_actionAnimPlayer, VappWidget3dPetAnimPlayer, m_physicalSheep);
    }

    // create m_translationTL
    createTranslationTL();
}

void VappWidget3dPetCharSheep::greet(const VfxVector3f pEye)
{
    VfxVector3f p;
    getCurrentWorldPos(p);
    const VfxVector3f nvEyeXY = normalize(VfxVector3f(pEye.x - p.x, pEye.y - p.y, 0.f));

    const VfxFloat angle = calculateMinRotationAngle(m_nvFront, nvEyeXY);
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDuration(500);    
    rotate(VfxVector3f(0.f, 0.f, 1.f), angle);
    VfxAutoAnimate::commit(); 
    m_nvFront = nvEyeXY;

    if(m_actionAnimPlayer)
    {
         m_actionAnimPlayer->m_sigPlayFinished.connect(this, &VappWidget3dPetCharSheep::onGreet);
    }
    leap(833);    
}

void VappWidget3dPetCharSheep::leap(const VfxMsec duration)
{
    configActionAnim(SHEEP_ANIM_LEAP);
    m_actionAnimPlayer->play(duration);
    setCurrentActivePlayer(SHEEP_ANIM_LEAP);
}

void VappWidget3dPetCharSheep::onGreet(VappWidget3dPetAnimPlayer *plyer)
{
    m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::onGreet);

    if(m_faceAnimPlayer)
    {
        m_faceAnimPlayer->play(createFaceMotionContent(SF_HI), VFX_FALSE, 3000);
    }

    const U8 offset = rand() % 2;;
    const SheepAnim anim = (SheepAnim)(SHEEP_ANIM_HI_1+ offset);    
    configActionAnim(anim);
    m_actionAnimPlayer->m_sigPlayFinished.connect(this, &VappWidget3dPetCharSheep::handleGreetAnimFinished);    
    m_actionAnimPlayer->play();
    setCurrentActivePlayer(anim);   
}

static VfxS32 zDuration = 800;
void VappWidget3dPetCharSheep::sleep(const VfxMsec duration)
{
    if(m_faceAnimPlayer)
    {
        m_faceAnimPlayer->play(createFaceMotionContent(SF_SLEEP), VFX_FALSE, 2834 + 5000 + 1433 + 200);
    }

    configActionAnim(SHEEP_ANIM_SLEEP);
    m_actionAnimPlayer->m_sigPlayFinished.connect(this, &VappWidget3dPetCharSheep::handleSleepAnimFinished);
    m_actionAnimPlayer->play(duration);
    setCurrentActivePlayer(SHEEP_ANIM_SLEEP);

    m_actionAnimPlayer->m_sigLoopAnimFinished.connect(this, &VappWidget3dPetCharSheep::stopSymbolZGenerator);
    startSymbolZGenerator(zDuration, zDuration);
}

void VappWidget3dPetCharSheep::eat(const VfxMsec duration)
{
    // eat animation   
    if(m_faceAnimPlayer)
    {
        m_faceAnimPlayer->play(createFaceMotionContent(SF_EAT), VFX_TRUE, VAPP_WIDGET_3d_PET_SHEEP_EAT_FACE_REPEAT_DURATION);
    }

    configActionAnim(SHEEP_ANIM_EAT);
    m_actionAnimPlayer->m_sigPlayFinished.connect(this, &VappWidget3dPetCharSheep::handleEatFinished);
    m_actionAnimPlayer->play(duration);
    setCurrentActivePlayer(SHEEP_ANIM_EAT);
}

void VappWidget3dPetCharSheep::move(const VfxVector3f pMoveTo, 
                                    const VfxMsec durTurnDiration,
                                    const VfxFloat dTurnDiration)
{
    VfxVector3f p1;            getCurrentWorldPos(p1);
    const VfxVector3f p2     = pMoveTo;
    const VfxVector3f nvDir1 = m_nvFront; 
    const VfxVector3f nvDir2 = normalize(p2 - p1);
    
    const VfxFloat aTurnDirection = calculateMinRotationAngle(nvDir1, nvDir2);
    const VfxVector3f pAfterRotation = normalize(p2 - p1)* dTurnDiration + p1;
    setFrontTo(nvDir2);

    // set behavior animaiton and duration according the distance
    VfxMsec duration = 0;
    VfxMsec durationTurnDir = 0;
    do
    {        
        // note sheep will turn direction and then go forward to destination
        // hence the forward move vector(m_vDestination) = p2 - pAfterRotation
        const VfxVector3f vMove = p2 - pAfterRotation;
        const VfxFloat distance = vrt_sqrt(vMove.x * vMove.x + 
                                           vMove.y * vMove.y + 
                                           vMove.z * vMove.z);
        {
            walk(0);
            duration = vrt_ceil(distance / s_walkAvgVelocity * 1000);
            durationTurnDir = vrt_ceil(dTurnDiration / s_walkAvgVelocity * 1000);
        }
    }while(0);
    
    VfxMsec durationMove = duration - durationTurnDir;
    if(0 > duration - durationTurnDir )
    {
        durationMove = 1;
    }
    resetMoveRecord(pAfterRotation, p2, pAfterRotation, durationMove);

    // turn diretion
    turnDirectionDuringMoving(aTurnDirection, pAfterRotation - p1, durationTurnDir);
}

void VappWidget3dPetCharSheep::resetMoveRecord(const VfxVector3f pStart, 
                                               const VfxVector3f pDes, 
                                               const VfxVector3f pCurrent, 
                                               const VfxMsec expectDuration)
{
    m_moveRecord.pStart = pStart;
    m_moveRecord.pDes = pDes;
    m_moveRecord.pCurrent = pCurrent;
    m_moveRecord.pNext = pCurrent;
    
    const VfxFloat factor = 250.f / expectDuration;
    m_moveRecord.vUnitMove = (pDes - pCurrent) * factor;
    m_moveRecord.durUnitMove = 250;
    m_moveRecord.durTotal = expectDuration;
    m_moveRecord.tMoved = 0;
}

void VappWidget3dPetCharSheep::turnDirectionDuringMoving(
                                const VfxFloat theta, 
                                const VfxVector3f vMove, 
                                const VfxMsec durTurnDiration)
{
    if(NULL == m_moveTimer)
    {
        VFX_OBJ_CREATE(m_moveTimer, VfxTimer, this);
    }
    m_moveTimer->m_signalTick.connect(this, &VappWidget3dPetCharSheep::startMove); 
    m_moveTimer->setStartDelay(durTurnDiration);
    m_moveTimer->setDuration(durTurnDiration);    
    m_moveTimer->start();

    // update sheep's pos
    VfxVector3f p;
    getCurrentWorldPos(p);
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setTranslation(p);
    VfxAutoAnimate::commit();

    // turn dirction 
    const VfxVector3f p2 = p + vMove;
   
    VfxAutoAnimate::begin();    
    VfxAutoAnimate::setDisable(VFX_FALSE);
    VfxAutoAnimate::setDuration(durTurnDiration);
    rotate(VfxVector3f(0.f, 0.f, 1.f), theta);
    setTranslation(p2);
    VfxAutoAnimate::commit();
}


void VappWidget3dPetCharSheep::startMove(VfxTimer *timer)
{
    timer->m_signalTick.disconnect(this, &VappWidget3dPetCharSheep::startMove); 
    timer->stop();

    VfxVector3f p;
    getCurrentWorldPos(p);
    const VfxVector3f p1 = m_moveRecord.pCurrent;
    const VfxVector3f p2 = m_moveRecord.pDes;
    
    m_translationTL->setFromValue(p1);
    m_translationTL->setToValue(p2);
    m_translationTL->setDuration(m_moveRecord.durTotal);
    m_translationTL->setAutoReversed(VFX_FALSE);
    m_translationTL->setRepeatCount(1);
    m_translationTL->m_signalStopped.connect(this, &VappWidget3dPetCharSheep::endMove);
    m_translationTL->start();
}

void VappWidget3dPetCharSheep::endMove(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    m_translationTL->m_signalStopped.disconnect(this, &VappWidget3dPetCharSheep::endMove);

    if(isCompleted)
    {
        m_actionAnimPlayer->forceStop();
        changeState(SHEEP_STANDING);  
    }
}

void VappWidget3dPetCharSheep::walk(const VfxMsec duration)
{
    configActionAnim(SHEEP_ANIM_WALK);
    m_actionAnimPlayer->play(duration);
    setCurrentActivePlayer(SHEEP_ANIM_WALK);
}

VfxImageSrc VappWidget3dPetCharSheep::queryFaceImgSrc(const SheepFace face)
{    
    VfxImageSrc src;
    if(g_isResMode)
    {
        VfxResId res;
        switch(face)
        {
            case SHEEP_FACE_EAT:
                res = VAPP_WIDGET_3D_PET_SHEEP_FACE_EAT;
                break;
            case SHEEP_FACE_HI_1:
                res = VAPP_WIDGET_3D_PET_SHEEP_FACE_HI_1;
                break;
            case SHEEP_FACE_HI_2:
                res = VAPP_WIDGET_3D_PET_SHEEP_FACE_HI_2;
                break;
            case SHEEP_FACE_HI_3:
                res = VAPP_WIDGET_3D_PET_SHEEP_FACE_HI_3;
                break;  
            case SHEEP_FACE_SNAP:
                res = VAPP_WIDGET_3D_PET_SHEEP_FACE_SNAP;
                break;
            default:
                res = VAPP_WIDGET_3D_PET_SHEEP_FACE_NORMAL;
                break;  
        }    
	    src = VfxImageSrc(res);
    }
    else
    {
        VfxWString imgSrcPath;
        switch(face)
        {
            case SHEEP_FACE_EAT:
                imgSrcPath.format("E:\\Sheep_v3\\texture\\tex_head_eat.ktx");
                break;
            case SHEEP_FACE_HI_1:
                imgSrcPath.format("E:\\Sheep_v3\\texture\\tex_head_hi1.ktx");
                break;
            case SHEEP_FACE_HI_2:
                imgSrcPath.format("E:\\Sheep_v3\\texture\\tex_head_hi2.ktx");
                break;
            case SHEEP_FACE_HI_3:
                imgSrcPath.format("E:\\Sheep_v3\\texture\\tex_head_hi3.ktx");
                break;
            case SHEEP_FACE_SNAP:            
                imgSrcPath.format("E:\\Sheep_v3\\texture\\tex_head_snap.ktx");
                break;
            default:
                imgSrcPath.format("E:\\Sheep_v3\\texture\\tex_head.ktx");
                break;  
        }
	    src = VfxImageSrc(imgSrcPath);
    }
    return src;
}
VappWidget3dPetMotion VappWidget3dPetCharSheep::createFaceMotionContent(const SheepFaceStopMotion expression)
{
    // TODO: motion content factory
    // TODO: add duration attribute
    VappWidget3dPetMotion motion;
    switch(expression)
    {
        case SF_EAT:
        {
            motion.configContent(queryFaceImgSrc(SHEEP_FACE_NORMAL),
                                 queryFaceImgSrc(SHEEP_FACE_EAT),
                                 queryFaceImgSrc(SHEEP_FACE_NORMAL),
                                 300,
                                 400,
                                 300);
            break;

        }
        case SF_SLEEP:
        {
            motion.configContent(queryFaceImgSrc(SHEEP_FACE_NORMAL),
                                 queryFaceImgSrc(SHEEP_FACE_SNAP),
                                 queryFaceImgSrc(SHEEP_FACE_NORMAL),
                                 500,
                                 2334 + 5000,
                                 500);
            break;

        }
        case SF_HI:
        {
            const VfxU8 offset = rand() % 2;
            const VfxU8 faceHi = SHEEP_FACE_HI_2 + offset;
            motion.configContent(queryFaceImgSrc((SheepFace)faceHi),
                                 queryFaceImgSrc((SheepFace)faceHi),
                                 queryFaceImgSrc((SheepFace)faceHi),
                                 300,
                                 2000,
                                 300);
            break;

        }        
        case SF_WINK:
		default:
		{
            motion.configContent(queryFaceImgSrc(SHEEP_FACE_NORMAL),
                                 queryFaceImgSrc(SHEEP_FACE_SNAP),
                                 queryFaceImgSrc(SHEEP_FACE_NORMAL),
                                 250,
                                  50,
                                 250);
            break;
		}
    }
	return motion;
}

VappWidget3dPetAnimItem VappWidget3dPetCharSheep::s_animItems[33] = {\
    // duration,  from,     to,  repeate, isAutoReversed, path, res
    // walk    
	{   NULL},
    {  400,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_166_566.ani"), VAPP_WIDGET_3D_PET_SHEEP_WALK_ANIM},
	{   NULL},
    // eat    
    {   NULL},
    {   2833,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_9500_12333.ani"), VAPP_WIDGET_3D_PET_SHEEP_EAT_ANIM},
    {   NULL},
    // sleep    
    {   2834,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_12666_15500.ani"), VAPP_WIDGET_3D_PET_SHEEP_SLEEP_START_ANIM},
    {   5000,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_15666_20666.ani"), VAPP_WIDGET_3D_PET_SHEEP_SLEEP_LOOP_ANIM},
    {   1433,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_21000_22433.ani"), VAPP_WIDGET_3D_PET_SHEEP_SLEEP_END_ANIM},

    // stand 1
	{   NULL},
    {  3366,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_1000_4366.ani"), VAPP_WIDGET_3D_PET_SHEEP_STAND_LOOK_AROUND_ANIM},
	{   NULL},
    // stand 2 
	{   NULL},
    {  3233,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_4500_7733.ani"), VAPP_WIDGET_3D_PET_SHEEP_STAND_STRETCH_ANIM},
	{   NULL},
    // stand 3 
	{   NULL},
    {  2433,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_7833_9333.ani"), VAPP_WIDGET_3D_PET_SHEEP_STAND_SHAKE_HEAD_ANIM},
	{   NULL},
    // Hi 1
	{   NULL},
    {  2766,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_22500_25266.ani"), VAPP_WIDGET_3D_PET_SHEEP_HI_1_ANIM},
	{   NULL},
    // Hi 2 
	{   NULL},
    {  2500,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_25333_27833.ani"), VAPP_WIDGET_3D_PET_SHEEP_HI_2_ANIM},
	{   NULL}, 
    // jump    
	{   NULL},
    {   2733,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_28000_30733.ani"), VAPP_WIDGET_3D_PET_SHEEP_JUMP_ANIM},
    {   NULL},
    // leap    
    {   NULL},
    {   833,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_30833_31666.ani"), VAPP_WIDGET_3D_PET_SHEEP_LEAP_ANIM},
    {   NULL}, 
    // sleep end 
	{   NULL},
    {   1433,   0.f, 1.f,   1,      VFX_FALSE, VFX_WSTR("E:\\Sheep_v3\\sheep\\sheep_21000_22433.ani"), VAPP_WIDGET_3D_PET_SHEEP_SLEEP_END_ANIM},
    {   NULL}, 
};

VfxS8 VappWidget3dPetCharSheep::getAnimItemId(SheepAnim playerId, VfxId animId)
{
    return playerId * 3 + animId;
}

void VappWidget3dPetCharSheep::configActionAnim(const SheepAnim id)
{
    VappWidget3dPetAnimItem startItem = s_animItems[getAnimItemId(id, 0)];
    VappWidget3dPetAnimItem loopItem  = s_animItems[getAnimItemId(id, 1)];
    VappWidget3dPetAnimItem endItem   = s_animItems[getAnimItemId(id, 2)];

    // anim
    VfxAnimation *startAnim = NULL;
    if(NULL != startItem.duration)
    {
        VFX_OBJ_CREATE(startAnim, VfxAnimation, m_physicalSheep);
        if(g_isResMode)
            VfxAssetLoader::loadAnimation(startAnim, m_physicalSheep, startItem.res);
        else 
            VfxAssetLoader::loadAnimation(startAnim, m_physicalSheep, startItem.path);
    }
    
    VfxAnimation *loopAnim = NULL;
	if(NULL != loopItem.duration)
    {        
		VFX_OBJ_CREATE(loopAnim, VfxAnimation, m_physicalSheep);    
        if(g_isResMode)
            VfxAssetLoader::loadAnimation(loopAnim, m_physicalSheep, loopItem.res);
        else 
		    VfxAssetLoader::loadAnimation(loopAnim, m_physicalSheep, loopItem.path);
	}

    VfxAnimation *endAnim = NULL;
	if(NULL != endItem.duration)
	{
		VFX_OBJ_CREATE(endAnim, VfxAnimation, m_physicalSheep);    
        if(g_isResMode)
            VfxAssetLoader::loadAnimation(endAnim, m_physicalSheep, endItem.res);
        else
            VfxAssetLoader::loadAnimation(endAnim, m_physicalSheep, endItem.path);
	}

    // animation playerback control timeline
    VappWidget3dPetAnimTL *startTL = NULL;
    if(startAnim)
    {
        VFX_OBJ_CREATE(startTL, VappWidget3dPetAnimTL, m_physicalSheep);
        startTL->configAnimationEx(startAnim, startItem.duration, startItem.fromValue, startItem.toValue, startItem.repeateCount, startItem.isAutoReversed);
        startTL->setTarget(m_physicalSheep);
    }
    
    VappWidget3dPetAnimTL *loopTL = NULL;
	if(loopAnim)
    {
		VFX_OBJ_CREATE(loopTL, VappWidget3dPetAnimTL, m_physicalSheep);
		loopTL->configAnimationEx(loopAnim, loopItem.duration, loopItem.fromValue, loopItem.toValue, loopItem.repeateCount, loopItem.isAutoReversed);
		loopTL->setTarget(m_physicalSheep);
	}

    VappWidget3dPetAnimTL *endTL = NULL;
	if(endAnim)
	{
		VFX_OBJ_CREATE(endTL, VappWidget3dPetAnimTL, m_physicalSheep);
		endTL->configAnimationEx(endAnim, endItem.duration, endItem.fromValue, endItem.toValue, endItem.repeateCount, endItem.isAutoReversed);
		endTL->setTarget(m_physicalSheep);    
	}

    // animaiton player
    if(NULL == m_actionAnimPlayer)
    {
        VFX_OBJ_CREATE(m_actionAnimPlayer, VappWidget3dPetAnimPlayer, m_physicalSheep);
    }
    m_actionAnimPlayer->configAnimTL(startTL, loopTL, endTL);

///////////////
    VFX_OBJ_CLOSE(m_startAnimTL);
    VFX_OBJ_CLOSE(m_loopAnimTL);
    VFX_OBJ_CLOSE(m_endAnimTL);
    VFX_OBJ_CLOSE(m_startAnim);
    VFX_OBJ_CLOSE(m_loopAnim);
    VFX_OBJ_CLOSE(m_endAnim);

    m_startAnim = startAnim;
    m_loopAnim = loopAnim;
    m_endAnim = endAnim;
    m_startAnimTL = startTL;
    m_loopAnimTL = loopTL;
    m_endAnimTL = endTL;
/////////////
}

void VappWidget3dPetCharSheep::handleWalkAnimFinished(VappWidget3dPetAnimPlayer *plyer)
{
    m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleWalkAnimFinished);    
} 

void VappWidget3dPetCharSheep::handleSleepAnimFinished(VappWidget3dPetAnimPlayer *plyer)
{
    //m_symbolZGeneratorTimer->stop();
    m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleSleepAnimFinished);        
    if(m_faceAnimPlayer){m_faceAnimPlayer->stop();}

    const U8 offset = rand() % 3;
    const SheepAnim standAnim = (SheepAnim)(SHEEP_ANIM_STAND_LOOK_AROUND + offset);
    configActionAnim(standAnim);
    m_actionAnimPlayer->m_sigPlayFinished.connect(this, &VappWidget3dPetCharSheep::handleSleepFinished);
    m_actionAnimPlayer->play();
    setCurrentActivePlayer(standAnim);
}

void VappWidget3dPetCharSheep::handleGreetAnimFinished(VappWidget3dPetAnimPlayer *plyer)
{
    m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleGreetAnimFinished);    

    if(m_faceAnimPlayer){m_faceAnimPlayer->stop();}

    setIsGreeting(VFX_FALSE);
    changeState(SHEEP_STANDING);    
}

VappWidget3dPetAnimPlayer* VappWidget3dPetCharSheep::getPlayerById(SheepAnim id)
{
    return m_actionAnimPlayer;
}

void VappWidget3dPetCharSheep::setCurrentActivePlayer(SheepAnim id)
{
    m_currentAnimPlayerID = id;
};

VfxBool VappWidget3dPetCharSheep::disconnectPlyDefaultCallBackById(SheepAnim id)
{
    switch(id)
    {
        case SHEEP_ANIM_WALK:        
            m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleWalkAnimFinished);
            return VFX_TRUE;
        case SHEEP_ANIM_SLEEP:    
            m_actionAnimPlayer->m_sigLoopAnimFinished.disconnect(this, &VappWidget3dPetCharSheep::stopSymbolZGenerator);        
            m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleSleepAnimFinished);
            m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleSleepFinished); 
            return VFX_TRUE;
        case SHEEP_ANIM_STAND_LOOK_AROUND:
        case SHEEP_ANIM_STAND_LOOK_STRETCH:     
        case SHEEP_ANIM_STAND_SHAKE_HEAD:              
            m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleSleepFinished);             
            m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleStandingState2);
            return VFX_TRUE;
        case SHEEP_ANIM_EAT:
            m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleEatFinished);
            return VFX_TRUE;
        case SHEEP_ANIM_LEAP:            
            m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::onGreet);
            return VFX_TRUE;
        case SHEEP_ANIM_HI_1:
        case SHEEP_ANIM_HI_2:            
            m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleGreetAnimFinished);    
            return VFX_TRUE;
        default:
            return VFX_FALSE;
    }
}

void VappWidget3dPetCharSheep::rotatePet(const VfxVector3f axis, const VfxFloat theta)
{
    rotate(axis, theta);
}

void VappWidget3dPetCharSheep::rotatePetEx(const VfxVector3f axis, 
                    const VfxFloat theta, 
                    const VfxBool autoAnimateDisabled,
                    const VfxMsec duration)
{   
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(autoAnimateDisabled);
    VfxAutoAnimate::setDuration(duration);    
    rotate(axis, theta);
    VfxAutoAnimate::commit();    
}

void VappWidget3dPetCharSheep::translatePet(const VfxVector3f v)
{
    translate(v);
}

void VappWidget3dPetCharSheep::translatePetEx(const VfxVector3f v,
                                              const VfxBool autoAnimateDisabled,
                                              const VfxMsec duration)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(autoAnimateDisabled);
    VfxAutoAnimate::setDuration(duration);    
    translate(v);
    VfxAutoAnimate::commit();  
}

void VappWidget3dPetCharSheep::transformPetEx(const VfxVector3f axis, const VfxFloat theta,
                        const VfxVector3f v,
                        const VfxBool autoAnimateDisabled,
                        const VfxMsec duration)
{
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(autoAnimateDisabled);
    VfxAutoAnimate::setDuration(duration);
    rotate(axis, theta);
    translate(v);
    VfxAutoAnimate::commit(); 
}

void VappWidget3dPetCharSheep::resetSheepTransformation()
{
    // reset sheep transformation 
    VfxAutoAnimate::begin();    
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setTranslation(VfxVector3f(0, 0, 0));
    setRotation(VfxVector3f(0.f, 0.f, 1.f), 0);
    VfxAutoAnimate::commit(); 

    // reset font direction vector
    m_nvFront = VfxVector3f(0.f, -1.f, 0);    
}

void VappWidget3dPetCharSheep::getCurrentWorldPos(VfxVector3f &pos)
{
    // query sheep position in VRT task 
    forceGetTranslation(pos);
}

void VappWidget3dPetCharSheep::setPosAndFrontTo(VfxVector3f p, VfxVector3f nvFront)
{
    // translate to the origin
    VfxVector3f currentPos = VfxVector3f(0.f, 0.f, 0.f);
    getCurrentWorldPos(currentPos);
   
    VfxFloat theta1 = calculateMinRotationAngle(m_nvFront, VfxVector3f(1.f, 0.f, 0.f));
    VfxFloat theta2 = calculateMinRotationAngle(VfxVector3f(1.f, 0.f, 0.f), nvFront);
    m_nvFront = nvFront;
    
    VfxAutoAnimate::begin();    
    VfxAutoAnimate::setDisable(VFX_TRUE);    
    setRotation(VfxVector3f(0.f, 0.f, 1.f), theta1 + theta2);
    setTranslation(p);     
    VfxAutoAnimate::commit(); 
}

void VappWidget3dPetCharSheep::stopAllBehavior()
{
    if(m_faceAnimPlayer){ m_faceAnimPlayer->stop();}

    if(m_actionAnimPlayer)
    {
        m_actionAnimPlayer->forceStop();
    }
    
    if(m_symbolZGeneratorTimer)
    {
        m_symbolZGeneratorTimer->stop();
    }

    if(m_translationTL)
    {
        m_translationTL->stop();
    }
}

VfxBool VappWidget3dPetCharSheep::isPicked(VfxNode *node)
{    
    if(m_headMesh == node || m_bodyMesh == node)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxBool VappWidget3dPetCharSheep::interrupt(const VappWidget3ePetSheepInterruptOption option)
{
    // check if interrupt happened in valid time
    do
    {        
        // not allow to interrupt sheep behavior while sheep is eating or 
        // do greeting behavior
        if(SHEEP_EATING != getState() && !m_isGreeting && !getDoJump())
        {
            break;
        }
        return VFX_FALSE;
    }while(0);

    // stop all posible active timers/timelines
    do
    {
        if(m_idleStartDelaytimer)
        {
            m_idleStartDelaytimer->m_signalTick.disconnect(this, &VappWidget3dPetCharSheep::onIdleStartDelayTimout);
            m_idleStartDelaytimer->stop();
        }

        if(m_moveTimer)
        {
            m_moveTimer->m_signalTick.disconnect(this, &VappWidget3dPetCharSheep::startMove);
            m_moveTimer->stop();
        }

        if(m_symbolZGeneratorTimer)
        {
            m_symbolZGeneratorTimer->m_signalTick.disconnect(this, &VappWidget3dPetCharSheep::onSymbolZGeneratorTimeput);
            m_symbolZGeneratorTimer->stop();
        }
    }while(0);
    
    // show symbol to indicate sheep feeling about this interrupt
    processInterrupScenario(option);

    // stop to sheep current action animation    
    const VfxBool shouldTransmitCurrentAction = disconnectPlyDefaultCallBackById(m_currentAnimPlayerID);
    if(m_actionAnimPlayer && shouldTransmitCurrentAction && SHEEP_IDLE != getState() && SHEEP_MOVING != getState())
    {        
        m_actionAnimPlayer->m_sigPlayFinished.connect(this, &VappWidget3dPetCharSheep::handleInterrupted);
        if(m_actionAnimPlayer->isEndAnimPlaying())
        {
            // while end action anim is playing, do nothing to prevent that it is played repeatedly
            return VFX_TRUE;
        }
        else if(SHEEP_SLEEPING == m_state)
        {
            m_actionAnimPlayer->stopEx(); 
        }
        else
        {
            m_actionAnimPlayer->stop();
        }
    }
    else
    {
        if(SHEEP_MOVING == m_state)
        {
            m_translationTL->m_signalStopped.disconnect(this, &VappWidget3dPetCharSheep::endMove);            
            m_translationTL->stop();            
            m_actionAnimPlayer->forceStop();
        } 
       handleInterrupted(NULL);
    }

    return VFX_TRUE;
}

void VappWidget3dPetCharSheep::handleInterrupted(VappWidget3dPetAnimPlayer *ply)
{
    if(ply)
    {
        ply->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleInterrupted);
    }
    
    // workaround for jumpping railing interrupt happen while tap sheep or grow grass instantly
    if(!getDoJump())
    {
        changeState(SHEEP_STANDING);
    }
}

void VappWidget3dPetCharSheep::processInterrupScenario(const VappWidget3ePetSheepInterruptOption option)
{
    SheepSymbol symbolType = SYM_TEXT_END;
    switch(option.m_type)
    {
        case SI_GROW_GRASS:
        {
            symbolType = SYM_TEXT_E;
            break;
        }
        case SI_TAP_SHEEP:
        {
            setIsGreeting(VFX_TRUE);
            m_pViewer = option.m_pViewer; 
            symbolType = SYM_TEXT_Q;
            break;
        }
        default:
            break;
    }

    // show sybol
    if(SYM_TEXT_END != symbolType)
    {
        VfxU8 pSymbolOffset = rand() % 20;
        VfxVector3f p;
        getCurrentWorldPos(p);
        p.x = p.x + (m_nvFront.x * pSymbolOffset);    
        p.y = p.y + (m_nvFront.y * pSymbolOffset);
        p.z = 80 + pSymbolOffset;
        addSymbol(p, symbolType, VFX_TRUE, 2.f);
    }
}

void VappWidget3dPetCharSheep::addGrassToEatList(VappWidget3dPetGrass *grass)
{    
    m_grassList.pushBack(grass);

    VappWidget3ePetSheepInterruptOption option;
    option.m_pViewer = VfxVector3f();
    option.m_type = SI_GROW_GRASS;
    interrupt(option);     
}   

VfxS32 VappWidget3dPetCharSheep::getGrassCount()
{
    return m_grassList.size();
}

void VappWidget3dPetCharSheep::actionAnimTest(const SheepAnim id)
{
    m_actionAnimPlayer->forceStop();
    if(SHEEP_ANIM_END == id)
    {
        resetSheepTransformation();
        return;
    }
    
    configActionAnim(id);
    if(SHEEP_ANIM_SLEEP == id)m_actionAnimPlayer->play();
    else m_actionAnimPlayer->play(0);
    setCurrentActivePlayer(id);    
}

VfxBool VappWidget3dPetCharSheep::changeState(const VappWidget3dPetCharSheepState newState)
{
    // stop m_idleStartDelaytimer to avoid signal loop or unexpect state change caused by
    // user interact with sheep while m_idleStartDelaytimer lauched but dose not time out
    if(m_idleStartDelaytimer)
    {
        m_idleStartDelaytimer->stop();
    }
    if(getDoJump())
    {
        jump();
        return VFX_TRUE;
    }
    
    const VappWidget3dPetCharSheepState oldState = getState();
    m_state = newState;

    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_CHANGE_STATE, oldState, newState);

    switch(newState)
    {
        case SHEEP_STANDING:
            handleStandingState(oldState);
            break;
        case SHEEP_IDLE:
            handleIdleState(oldState);
            break;
        case SHEEP_MOVING:
            handleMovingState(oldState);
            break;        
        case SHEEP_GREETING:
            handleGreetingState(oldState);
            break;
        case SHEEP_SLEEPING:
            handleSleepingState(oldState);
            break;
        case SHEEP_EATING:
            handleEatingState(oldState);
            break;
        default:
            return VFX_FALSE;
    }
    
    return VFX_TRUE;
}

void VappWidget3dPetCharSheep::handleStandingState(const VappWidget3dPetCharSheepState oldState)
{    
    // TODO: close old state relevant animation if not close yet
    if(m_faceAnimPlayer){m_faceAnimPlayer->stop();}
    if(m_isGreeting)
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_HANDLE_STANDING_STATE_IS_GREETING);
        changeState(SHEEP_GREETING);
        return;
    }

    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_HANDLE_STANDING_STATE_NEW_TURN);
  
    // start the new turn
    VappWidget3dPetGrass *grass = getNearestGrass();
    if(grass)
    {
        m_eatingGrass = grass;
        if(isGrassInEatArea(grass))
        {
            changeState(SHEEP_EATING);
            return;
        }

        VfxVector3f pDest;
        getPositionNearToEatGrass(grass->getPos(), pDest);
        m_pDestination = pDest;

        // if there are more than 1 grass, sheep look around to find the nearest grass
        if(1 < getGrassCount())
        {
            configActionAnim(SHEEP_ANIM_STAND_LOOK_AROUND);
            m_actionAnimPlayer->m_sigPlayFinished.connect(this, &VappWidget3dPetCharSheep::handleStandingState2);
            m_actionAnimPlayer->play(500);
            setCurrentActivePlayer(SHEEP_ANIM_STAND_LOOK_AROUND);
            return;
        }
        
        changeState(SHEEP_MOVING);
    }
    else
    {
        changeState(SHEEP_IDLE);
    }
}

void VappWidget3dPetCharSheep::handleStandingState2(VappWidget3dPetAnimPlayer *ply)
{
    if(ply)
    {
        ply->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleStandingState2);
    }
    
    changeState(SHEEP_MOVING);
}

void VappWidget3dPetCharSheep::handleIdleState(const VappWidget3dPetCharSheepState oldState)
{    
    VfxU32 tick;
    kal_get_time(&tick);    
    srand(tick);
    VfxFloat option = (rand() % 10) * 0.1f;
    
    if(0.3 > option && !getIsSleepInLastIdleState())
    {
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_HANDLE_IDLE_STATE_DO_SLEEP);       
        startIdleDelayTimer();
        setIsSleepInLastIdleState(VFX_TRUE);
    }
    else
    {   
        MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_HANDLE_IDLE_STATE_DO_WALK_AROUND);        
        setDestinationRandomly();        
        setIsSleepInLastIdleState(VFX_FALSE);
        changeState(SHEEP_MOVING);
    }
}

void VappWidget3dPetCharSheep::handleMovingState(const VappWidget3dPetCharSheepState oldState)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_HANDLE_MOVING_STATE);   

    VfxMsec durTurnDiration = VAPP_WIDGET_3d_PET_TRANSITION_DURATION;
    VfxFloat dTurnDiration = 27.6f; 

    if(m_faceAnimPlayer){m_faceAnimPlayer->play(createFaceMotionContent(SF_WINK), VFX_TRUE, 1000);}
    move(m_pDestination, durTurnDiration, dTurnDiration);    
}

void VappWidget3dPetCharSheep::handleGreetingState(const VappWidget3dPetCharSheepState oldState)
{   
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_HANDLE_GREETING_STATE);    
    greet(m_pViewer);
}

void VappWidget3dPetCharSheep::handleSleepingState(const VappWidget3dPetCharSheepState oldState)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_HANDLE_SLEEPING_STATE);       
    sleep(VappWidget3dPetAnimPlayer::PLAY_ONCE);
}

void VappWidget3dPetCharSheep::handleEatingState(const VappWidget3dPetCharSheepState oldState)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_HANDLE_EATING_STATE);       
    eat(VappWidget3dPetAnimPlayer::PLAY_ONCE);
}

void VappWidget3dPetCharSheep::handleSleepFinished(VappWidget3dPetAnimPlayer *plyer)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_HANDLE_SLEEPING_FINISHED);        
    m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleSleepFinished);        
    changeState(SHEEP_STANDING);
}  

void VappWidget3dPetCharSheep::handleEatFinished(VappWidget3dPetAnimPlayer *plyer)
{  
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_HANDLE_EATING_FINISHED);    
    m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleEatFinished);
    if(m_faceAnimPlayer){m_faceAnimPlayer->stop();}

    VfxVector3f p = m_eatingGrass->getPos();
    VfxList<VappWidget3dPetGrass *>::It i;
    for(i = m_grassList.begin(); !i.isNull(); ++i)
    {
        VappWidget3dPetGrass *g = (*i);
        if(p == g->getPos())
        {            
            m_grassList.erase(i);
            m_eatingGrass = NULL;
            g->m_sigAnimFinished.connect(this, &VappWidget3dPetCharSheep::handleAteGrass);
            g->playAnim('CLEA');
            break;
        }
    }
    changeState(SHEEP_STANDING);

}

void VappWidget3dPetCharSheep::createTranslationTL()
{
    if(NULL == m_translationTL)
    {
        VFX_OBJ_CREATE(m_translationTL, VfxVector3fTimeline, this);
        m_translationTL->setTarget(this);
        m_translationTL->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
    }
}

void VappWidget3dPetCharSheep::setDestination(const VfxVector3f p)
{
    m_pDestination = p;
}

void VappWidget3dPetCharSheep::setIsGreeting(VfxBool b)
{
    m_isGreeting = b;
};

void VappWidget3dPetCharSheep::startIdleDelayTimer()
{
    if(NULL == m_idleStartDelaytimer)
    {
        VFX_OBJ_CREATE(m_idleStartDelaytimer, VfxTimer, this);
        m_idleStartDelaytimer->setStartDelay(500);
        m_idleStartDelaytimer->setDuration(500);
    }
    m_idleStartDelaytimer->m_signalTick.connect(this, &VappWidget3dPetCharSheep::onIdleStartDelayTimout);
    m_idleStartDelaytimer->start();
}

void VappWidget3dPetCharSheep::onIdleStartDelayTimout(VfxTimer* timer)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_SHEEP_ON_IDLE_START_DELAY_TIMEOUT);    
    timer->stop();    
    timer->m_signalTick.disconnect(this, &VappWidget3dPetCharSheep::onIdleStartDelayTimout);

    // note change to standing state only if current state is still idle
    if(SHEEP_IDLE == getState())
    {
        changeState(SHEEP_SLEEPING);
    }
}

void VappWidget3dPetCharSheep::setDestinationRandomly()
{
    VfxVector3f p1;
    getCurrentWorldPos(p1);
    VfxVector3f p2 = m_nvFront * RANDOE_MOVE_OFFSET + p1;
        
    if((STAGE_BOARD_MIN_X + STAGE_VALID_OFFSET > p2.x) || (STAGE_BOARD_MAX_X - STAGE_VALID_OFFSET < p2.x))
    {
        VfxFloat value = calcuateRandomOffset();
        p2.x = p1.x - (m_nvFront * RANDOE_MOVE_OFFSET).x * value;
        if(0 == m_nvFront.y)
        {
            p2.y = p1.x - (m_nvFront * RANDOE_MOVE_OFFSET).x * (1 - value) * 0.8f;
        }
    }

    if((STAGE_BOARD_MIN_Y + STAGE_VALID_OFFSET > p2.y) || (STAGE_BOARD_MAX_Y - STAGE_VALID_OFFSET< p2.y))
    {
        VfxFloat value = calcuateRandomOffset();
        p2.y  = p1.y - (m_nvFront * RANDOE_MOVE_OFFSET).y * value;
        if(0 == m_nvFront.x)
        {
            p2.x = p1.y - (m_nvFront * RANDOE_MOVE_OFFSET).y * (1 - value) * 0.8;
        }
    }
   
    m_pDestination = p2;  
}

VfxFloat VappWidget3dPetCharSheep::calcuateRandomOffset()
{
	VfxFloat value = 1.f - (rand() % 10) / 10.f;
    value = vfxMax(0.8f, vfxMin(value, 0.2f));
    return value;
}

void VappWidget3dPetCharSheep::setIsSleepInLastIdleState(const VfxBool b)
{
    m_isSleepInLastIdleState = b;
}

VfxBool VappWidget3dPetCharSheep::getIsSleepInLastIdleState()
{
    return m_isSleepInLastIdleState;
}

VfxFloat VappWidget3dPetCharSheep::calculateMinRotationAngle(const VfxVector3f nvDir1, const VfxVector3f nvDir2)
{    
    // calculate rotation theta in radians
    VfxFloat dotValue = dot(nvDir1, nvDir2);
    dotValue = vfxMin(vfxMax(dotValue, -1.f), 1.f);
    VfxFloat theta = acos(dotValue);

    // note nvDir1 and nvDir2 is on the xy plane
    // let angle between nvDir1 and X+ is alpha
    // rotate original wolrd coordinate with -alpha in order to
    // map nvDir2 to the coordinate which nvDir1 is start at the origin and points to X+
    // X = x * cos(-alpha) - y * sin(-alpha),  
    // Y = x * sin(-alpha) + x * cos(-alpha)
    // cos(alpha) = nvDir1.x,  sin(alpha) = nvDir1.y
    VfxVector3f v = VfxVector3f( nvDir1.x * nvDir2.x + nvDir1.y * nvDir2.y,
                                -nvDir1.y * nvDir2.x + nvDir1.x * nvDir2.y, 
                                 0);

    // if nvDir2 is located in 3 or 4 quadrant of the local coordinate, 
    // rotate - theta
    if(0 > v.y)
    {        
        theta = - theta;
    }
    return theta;
}

void VappWidget3dPetCharSheep::handleAddingNewGrass(VappWidget3dPetAnimPlayer *ply)
{
    if(ply)
    {
        ply->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleAddingNewGrass);
    }

    changeState(SHEEP_STANDING);
}

void VappWidget3dPetCharSheep::handleAteGrass(VappWidget3dPetGroup *g)
{
    g->m_sigAnimFinished.disconnect(this, &VappWidget3dPetCharSheep::handleAteGrass);    
    VFX_OBJ_CLOSE(g);
}

VfxBool VappWidget3dPetCharSheep::isGrassInEatArea(VappWidget3dPetGrass *grass)
{
    VfxVector3f pSheep;
    getCurrentWorldPos(pSheep);
    const VfxVector3f v = (grass->getPos() - pSheep);

    // check if the grass in the eat area
    const VfxFloat d = vrt_sqrt(v.x * v.x + v.y *v.y + v.z * v.z);
    if(EAT_AREA_R + 3 < d)
    {
        return VFX_FALSE;
    }

    // TODO: check grass relative position to sheep     
    const VfxVector3f nv = normalize(v);
    VfxFloat turnTheta = calculateMinRotationAngle(m_nvFront, nv);
    rotatePet(VfxVector3f(0, 0, 1), turnTheta);
    setFrontTo(nv);
    return VFX_TRUE;

/*  
    // check if the grass in the eat area
    const VfxFloat d = vrt_sqrt(v.x * v.x + v.y *v.y + v.z * v.z);
    if(82 > d)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
*/
}

void VappWidget3dPetCharSheep::getPositionNearToEatGrass(
                                                const VfxVector3f pGrass, 
                                                VfxVector3f &p)
{
    // TODO: err handle
    VfxVector3f pSheep;
    getCurrentWorldPos(pSheep);
    p = pGrass - normalize(pGrass - pSheep) * EAT_AREA_R;
}

void VappWidget3dPetCharSheep::handleSheepTapped(VappWidget3dPetAnimPlayer *plyer)
{   
    if(plyer)
    {
        plyer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleSheepTapped);    
    }
    
    changeState(SHEEP_STANDING);
}

VappWidget3dPetGrass* VappWidget3dPetCharSheep::getNearestGrass()
{
    VfxVector3f pSheep;
    getCurrentWorldPos(pSheep);

    VfxFloat D = 1000;
    VappWidget3dPetGrass *target = NULL;

    // traverse the to-eat list to update the grass distance with sheep
    VfxList<VappWidget3dPetGrass *>::It i;
    for(i = m_grassList.begin(); !i.isNull(); ++i)
    {
        VappWidget3dPetGrass *grass = (*i);
        VfxVector3f pGrass = grass->getPos();
        const VfxVector3f v = (pSheep - pGrass);
        const VfxFloat d = vrt_sqrt(v.x * v.x + v.y *v.y + v.z *v.z);
        if(d < D)
        {
            D = d;
            target = grass;
        }
    }
    
    return target;
};

void VappWidget3dPetCharSheep::addSymbol(const VfxVector3f p, 
                                         const SheepSymbol symbol, 
                                         const VfxBool randomRotation,
                                         const VfxFloat scaleFactor)
{
    VappWidget3dPetSheepSymbol *z = NULL;
    VFX_OBJ_CREATE_EX(z, VappWidget3dPetSheepSymbol, this->getParent(), (symbol));
    z->setTranslation(p);

    if(randomRotation)
    {
        static VfxBool inverted = VFX_FALSE;
        const VfxS8 sign = inverted ? -1.0f : 1.0f;
        inverted = !inverted;    
        const VfxS8 degree = 15 + 2 * sign * rand() % 8;
        const VfxFloat radians = DEGREES_TO_RADIANS(degree);
        z->rotate(VfxVector3f(0, 1, 0), radians);
    }
    if(1.f != scaleFactor)
    {
        z->setScale(scaleFactor);    
    }

    z->m_sigAnimFinished.connect(this, &VappWidget3dPetCharSheep::onSymbolZAnimFinished);
    z->playAnim();
}

void VappWidget3dPetCharSheep::onSymbolZAnimFinished(VappWidget3dPetGroup *z)
{
    z->m_sigAnimFinished.disconnect(this, &VappWidget3dPetCharSheep::onSymbolZAnimFinished);    
    VFX_OBJ_CLOSE(z);
}

void VappWidget3dPetCharSheep::startSymbolZGenerator(const VfxMsec startDelay, const VfxMsec duration)
{
    if(NULL == m_symbolZGeneratorTimer)
    {
        VFX_OBJ_CREATE(m_symbolZGeneratorTimer, VfxTimer, this);
    }
    m_symbolZGeneratorTimer->setStartDelay(startDelay);
    m_symbolZGeneratorTimer->setDuration(duration);
    m_symbolZGeneratorTimer->m_signalTick.connect(this, &VappWidget3dPetCharSheep::onSymbolZGeneratorTimeput);
    m_symbolZGeneratorTimer->start();
}

void VappWidget3dPetCharSheep::onSymbolZGeneratorTimeput(VfxTimer *timer)
{
    timer->setDuration(timer->getDuration() + 70);
    
    VfxU8 offset = rand() % 10;
    VfxVector3f p;
    getCurrentWorldPos(p);
    p.y = p.y - (m_nvFront.y * 50);
    p.z = 30;
    addSymbol(p, SYM_TEXT_Z, VFX_TRUE);
}

void VappWidget3dPetCharSheep::stopSymbolZGenerator(VappWidget3dPetAnimPlayer *ply)
{
    if(ply)
    {
        ply->m_sigLoopAnimFinished.disconnect(this, &VappWidget3dPetCharSheep::stopSymbolZGenerator);
    }
    if(m_symbolZGeneratorTimer)
    {
        m_symbolZGeneratorTimer->stop();
    }
}

void VappWidget3dPetCharSheep::prepareToJumpRailing()
{    
    // check if allow to prepre jump
    if(getDoJump())
    {
        return;
    }

    disconnectPlyDefaultCallBackById(m_currentAnimPlayerID);
    if(m_translationTL)
    {
        m_translationTL->m_signalStopped.disconnect(this, &VappWidget3dPetCharSheep::endMove);            
        m_translationTL->stop();
    }
    if(m_actionAnimPlayer)
    {
        m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::handleInterrupted);
        m_actionAnimPlayer->forceStop();
    }
    if(m_symbolZGeneratorTimer) m_symbolZGeneratorTimer->stop();
    if(m_idleStartDelaytimer) m_idleStartDelaytimer->stop();
    if(m_moveTimer) m_moveTimer->stop();
    

    m_pDestination = VfxVector3f(-100, 0, 0);
    m_state = SHEEP_JUMP_RAILING;
    setDoJump(VFX_TRUE);
    move(m_pDestination, 300, 27.6f);
}

void VappWidget3dPetCharSheep::jump()
{
    showRailing(VFX_TRUE);

	VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setRotation(VfxVector3f(0.f, 0.f, 1.f), VFX_PI / 2);
	VfxAutoAnimate::commit();
    m_nvFront = VfxVector3f(1, 0, 0);

    
    configActionAnim(SHEEP_ANIM_JUMP);
    m_actionAnimPlayer->m_sigPlayFinished.connect(this, &VappWidget3dPetCharSheep::jumpRailingFinished);
    m_actionAnimPlayer->play(VappWidget3dPetAnimPlayer::PLAY_ONCE);


    createTranslationTL();
    m_translationTL->setCustomInterpolateFunc(jumpIntepolateFunc, &m_nvFront, sizeof(m_nvFront));
    m_translationTL->setDuration(2733);    
    m_translationTL->setFromValue(VfxVector3f(-100, 0, 0));
    m_translationTL->setToValue(VfxVector3f(80, 0, 0));
    m_translationTL->start();

    addSymbol(VfxVector3f(-10.f, 0.f, 100.f), SYM_TEXT_1_UP, VFX_FALSE);
}

void VappWidget3dPetCharSheep::setDoJump(const VfxBool b)
{
    m_doJump = b;
};

VfxBool VappWidget3dPetCharSheep::getDoJump()
{
    return m_doJump;
};

void VappWidget3dPetCharSheep::jumpRailingFinished(VappWidget3dPetAnimPlayer *plyer)
{
    m_actionAnimPlayer->m_sigPlayFinished.disconnect(this, &VappWidget3dPetCharSheep::jumpRailingFinished);

    // stop TL
    m_translationTL->stop();

    // update sheep's pos
    VfxVector3f p;
    getCurrentWorldPos(p);
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    setTranslation(p);
    VfxAutoAnimate::commit();
    
    // new timeline
    VFX_OBJ_CLOSE(m_translationTL);
    m_translationTL = NULL;
    createTranslationTL();

    showRailing(VFX_FALSE);
}


VfxTimelineInterpolationRetEnum VappWidget3dPetCharSheep::jumpIntepolateFunc(
    void *output,
    const void *fromValue,
    const void *toValue,
    VfxTypeIdEnum typeId,
    VfxFloat t, 
    void *data,
    VfxU32 dataSize
)
{
    static VfxFloat t_offset = 0.15f;
    VfxFloat T = vfxMin(1.f, vfxMax(0.f, (t + t_offset)));

    VfxVector3f dir=*((VfxVector3f *)data);
    VfxVector3f p1 = *((VfxVector3f *)fromValue);

    static VfxFloat base = 1.5f;
    VfxVector3f p2 = p1 + dir * pow(base, (10.f * T - 10.f)) * (180);

    *((VfxVector3f *)output) = p2;
    return VFX_TIMELINE_INTERPOLATION_RET_DONE;
}

void VappWidget3dPetCharSheep::showRailing(const VfxBool showRailing)
{
    if(showRailing)
    {
        if(NULL == m_railing)
        {
            static VfxFloat railingInverted= VFX_FALSE;
            VfxFloat offset = DEGREES_TO_RADIANS(rand() % 20);
            VfxFloat sign = (railingInverted)? -1.f: 1.f;
            railingInverted = !railingInverted;
            VFX_OBJ_CREATE(m_railing, VappWidget3dPetRailing, getParent());
            m_railing->setRotation(VfxVector3f(0, 0, 1.f), (VFX_PI / 2 + sign * offset));
            m_railing->setTranslation(VfxVector3f(-10.f, 0.f, 0.f));
            m_railing->setAnimId('UP');
            m_railing->playAnim();
        }
        else
        {
            // should not go here
        }
    }
    else
    {
        m_railing->setAnimId('DOWN');
        m_railing->m_sigAnimFinished.connect(this, &VappWidget3dPetCharSheep::onJumpRialingFinished);         
        m_railing->playAnim();
    }
}

void VappWidget3dPetCharSheep::onJumpRialingFinished(VappWidget3dPetGroup* g)
{       
    VFX_OBJ_CLOSE(g);
    m_railing = NULL;

    setDoJump(VFX_FALSE);
    changeState(SHEEP_STANDING);
}

/*****************************************************************************
 * Develop frame
 *****************************************************************************/
void VappWidget3dPetDevelopFrame::onInit()
{
    VfxFrame::onInit();

    setBgColor(VFX_COLOR_TRANSPARENT);    
    setSize(LCD_WIDTH, 80);

    // create hotkeys
    VcpSegmentButton *segBtn;
    VFX_OBJ_CREATE(segBtn, VcpSegmentButton, this);
    segBtn->setPos(0, 0);
    segBtn->setSize(320, 25);
    segBtn->setStyle(VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
    segBtn->setType(VCP_SEGMENT_BUTTON_TYPE_RADIO);

    segBtn->addButton(HK_0, VcpStateImage(0, 0, 0, 0), VFX_WSTR("0"));
    segBtn->addButton(HK_1, VcpStateImage(0, 0, 0, 0), VFX_WSTR("1"));
    segBtn->addButton(HK_2, VcpStateImage(0, 0, 0, 0), VFX_WSTR("2"));
    segBtn->addButton(HK_3, VcpStateImage(0, 0, 0, 0), VFX_WSTR("3"));       
    segBtn->addButton(HK_4, VcpStateImage(0, 0, 0, 0), VFX_WSTR("4"));
    segBtn->addButton(HK_5, VcpStateImage(0, 0, 0, 0), VFX_WSTR("5"));
    segBtn->addButton(HK_6, VcpStateImage(0, 0, 0, 0), VFX_WSTR("6"));    
    segBtn->addButton(HK_7, VcpStateImage(0, 0, 0, 0), VFX_WSTR("7"));    
    segBtn->addButton(HK_8, VcpStateImage(0, 0, 0, 0), VFX_WSTR("8"));   
    segBtn->addButton(HK_9, VcpStateImage(0, 0, 0, 0), VFX_WSTR("9"));
    segBtn->addButton(HK_10, VcpStateImage(0, 0, 0, 0), VFX_WSTR("10"));

    segBtn->m_signalButtonClicked.connect(this, &VappWidget3dPetDevelopFrame::onHotKeyBtnClicked);

    // create transformation controls
    const VfxS32 tw = 30;
    const VfxS32 th = 25;    
    VfxS32 tx = 0, ty = th;
    createTransformationBtn(VFX_WSTR("X+"), 'X+', VFX_COLOR_BLACK, tw, th, tx, ty);  tx += tw;
    createTransformationBtn(VFX_WSTR("X-"), 'X-', VFX_COLOR_BLACK, tw, th, tx, ty);  tx += tw;
    createTransformationBtn(VFX_WSTR("Y+"), 'Y+', VFX_COLOR_RED,   tw, th, tx, ty);  tx += tw;
    createTransformationBtn(VFX_WSTR("Y-"), 'Y-', VFX_COLOR_RED,   tw, th, tx, ty);  tx += tw;
    createTransformationBtn(VFX_WSTR("Z+"), 'Z+', VFX_COLOR_BLUE,  tw, th, tx, ty);  tx += tw;
    createTransformationBtn(VFX_WSTR("Z-"), 'Z-', VFX_COLOR_BLUE,  tw, th, tx, ty);  tx += tw;
    createTransformationBtn(VFX_WSTR("R+"), 'R+', VFX_COLOR_BLUE,  tw, th, tx, ty);  tx += tw;    
    createTransformationBtn(VFX_WSTR("R-"), 'R-', VFX_COLOR_BLUE,  tw, th, tx, ty);  tx += tw;    
    //createTransformationBtn(VFX_WSTR("S+"), 'S+', VFX_COLOR_BLUE,  tx, ty);  tx += tw;    
    //createTransformationBtn(VFX_WSTR("S-"), 'S-', VFX_COLOR_BLUE,  tx, ty);  tx += tw;
    createTransformationBtn(VFX_WSTR("A+"), 'A+', VFX_COLOR_GREEN,  tw, th, tx, ty);  tx += tw;
    createTransformationBtn(VFX_WSTR("A-"), 'A-', VFX_COLOR_GREEN,  tw, th, tx, ty);  tx += tw;

    tx = 0;
    ty += th;
    createCameraBtn(VFX_WSTR("cx+"), 'cx+', VFX_COLOR_BLACK, tw, th, tx, ty);  tx += tw;
    createCameraBtn(VFX_WSTR("cx-"), 'cx-', VFX_COLOR_BLACK, tw, th, tx, ty);  tx += tw;
    createCameraBtn(VFX_WSTR("cy+"), 'cy+', VFX_COLOR_RED,   tw, th, tx, ty);  tx += tw;
    createCameraBtn(VFX_WSTR("cy-"), 'cy-', VFX_COLOR_RED,   tw, th, tx, ty);  tx += tw;
    createCameraBtn(VFX_WSTR("cz+"), 'cz+', VFX_COLOR_BLUE,  tw, th, tx, ty);  tx += tw;
    createCameraBtn(VFX_WSTR("cz-"), 'cz-', VFX_COLOR_BLUE,  tw, th, tx, ty);  tx += tw;
    createCameraBtn(VFX_WSTR("cr+"), 'cr+', VFX_COLOR_BLUE,  tw, th, tx, ty);  tx += tw;    
    createCameraBtn(VFX_WSTR("cr-"), 'cr-', VFX_COLOR_BLUE,  tw, th, tx, ty);  tx += tw;  
}

void VappWidget3dPetDevelopFrame::onHotKeyBtnClicked(VfxObject *sender, VfxId id)
{
    VFX_UNUSED(sender);

    if(HK_0 <= id && HK_END > id)
        m_sigDevHotKeyClicked.emit(id);
}

void VappWidget3dPetDevelopFrame::onTransformationBtnClicked(VfxObject *sender, VfxId id)
{
    VfxS32 x = 0, y = 0, z = 0;
	VfxFloat s = 0, r = 0;
    VfxS32 offsetT = 20;
    VfxFloat offsetS = 1.f;
    VfxFloat offsetR = VFX_PI/ 3;
    switch(id)
    {
        case 'X+':
            x += offsetT;
            break;
        case 'X-':
            x -= offsetT;
            break;
        case 'Y+':
            y += offsetT;
            break;
        case 'Y-': 
            y -= offsetT;
            break;
        case 'Z+':      
            z += offsetT;
            break;
        case 'Z-':      
            z -= offsetT;
            break;
        case 'S+':      
            s += offsetS ;
            break;
        case 'S-':      
            s -= offsetS;
            break;
        case 'R+':      
            r += offsetR;
            break;
        case 'R-':      
            r -= offsetR;
            break;
        case 'A+':
            m_sigAutoAnimaitonEnabled.emit(VFX_TRUE);
            break;
        case 'A-':
            m_sigAutoAnimaitonEnabled.emit(VFX_FALSE);
            break;
        default:
            break;
    }    

	if(0 != x || 0 != y || 0 != z)
		m_sigDevTranslation.emit(x, y, z);
    if(0 != s)
        m_sigDevScale.emit(s);
    if(0 != r)
    {
        m_sigDevRotation.emit(VfxVector3f(0.f, 0.f, 1.f), r);
    }
}

void VappWidget3dPetDevelopFrame::onCameraBtnClicked(VfxObject * sender,VfxId id)
{
    VfxFloat offsetT = 50.f;
    VfxFloat offsetR = VFX_PI / 6;
    switch(id)
    {
        case 'cx+':
            g_tCamera.x += offsetT;
            break;
        case 'cx-':
            g_tCamera.x -= offsetT;
            break;
        case 'cy+':
            g_tCamera.y += offsetT;
            break;
        case 'cy-': 
            g_tCamera.y -= offsetT;
            break;
        case 'cz+':      
            g_tCamera.z += offsetT;
            break;
        case 'cz-':      
            g_tCamera.z -= offsetT;
            break;
        case 'cr+':      
            g_ryCamera+= offsetR;
            break;
        case 'cr-':      
            g_ryCamera -= offsetR;
            break;
        default:
            break;
    }
    m_sigCameraUpdated.emit();
}

void VappWidget3dPetDevelopFrame::createTransformationBtn(const VfxWString &str, const VfxId id, const VfxColor &color, const VfxS32 w, const VfxS32 h, const VfxS32 x, const VfxS32 y)
{   
    VcpButton *btn;
    VFX_OBJ_CREATE(btn, VcpButton, this);
    btn->setSize(w, h);
    btn->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(10)));
    btn->setTextColor(color);
    btn->setText(str);
    btn->setId(id);
	btn->m_signalClicked.connect(this, &VappWidget3dPetDevelopFrame::onTransformationBtnClicked);
    btn->setPos(x, y);
}

void VappWidget3dPetDevelopFrame::createCameraBtn(const VfxWString &str, const VfxId id, const VfxColor &color, const VfxS32 w, const VfxS32 h, const VfxS32 x, const VfxS32 y)
{   
    VcpButton *btn;
    VFX_OBJ_CREATE(btn, VcpButton, this);
    btn->setSize(w, h);
    btn->setTextFont(VfxFontDesc(VFX_FONT_DESC_VF_SIZE(10)));
    btn->setTextColor(color);
    btn->setText(str);
    btn->setId(id);
	btn->m_signalClicked.connect(this, &VappWidget3dPetDevelopFrame::onCameraBtnClicked);
    btn->setPos(x, y);
}

/*****************************************************************************
 * Stage frame
 *****************************************************************************/
VappWidget3dPetSheepWorld::VappWidget3dPetSheepWorld():
                        m_sheep(NULL), 
                        m_cameraQTL(NULL), 
                        m_jumpBtn(NULL),
                        m_stage(NULL)
{};

void VappWidget3dPetSheepWorld::onInit()
{
    VfxFrame::onInit();

    // set 3D world
	VFX_OBJ_CREATE(m_world, VfxWorld, this);
    setWorld(m_world);
    // config scene related data
    configScene(); 

    // create pet charactor
    VFX_OBJ_CREATE(m_sheep, VappWidget3dPetCharSheep, m_world);
}

void VappWidget3dPetSheepWorld::onDeinit()
{
    if(m_sheep)
    {
        m_sheep->stopAllBehavior();
    }
    if(m_cameraQTL)
    {
        m_cameraQTL->stop();
    }
    VfxFrame::onDeinit();
}

VfxBool VappWidget3dPetSheepWorld::onPenInput(VfxPenEvent &event)
{
    if (event.type != VFX_PEN_EVENT_TYPE_UP)
    {
        return VFX_TRUE;
    }
    
    // calculate the incident ray 
    // which starts from camera and points to clicked pos in world coordinate
    VfxVector3f pCamera, pClicked, vIncidentRay;
    do
    {
        getCameraPos(pCamera);
        const VfxPoint pos = event.getRelPos(this);
        const VfxSize size = getSize();
        const VfxFloat w = (VfxFloat)size.width;
        const VfxFloat h = (VfxFloat)size.height;

        pClicked = m_camera->unproject(VfxVector3f(
                                    (VfxFloat)(pos.x * 2) / w - 1.0f,
                                    -((VfxFloat)(pos.y * 2) / h - 1.0f),
                                    -1.0f));
        vIncidentRay = pClicked- pCamera;
    }while(0);


    // sheep greets if tap on sheep
    do
    {        
        // convert incident ray to sheep world coordinate
        VfxMatrix4f sheepTransform, sheepTransformInverse;
        m_sheep->forceGetTransform(sheepTransform);
        sheepTransformInverse = inverse(sheepTransform);
        VfxVector4f pRayInSheep = sheepTransformInverse * VfxVector4f(pCamera, 1.0f);
        VfxVector4f vRayInSheep = sheepTransformInverse * VfxVector4f(vIncidentRay, 0.0f);

        // check if pick on target sheep
        VfxNode *pickNode = m_sheep->pick(pRayInSheep.xyz(), vRayInSheep.xyz());
        if(m_sheep->isPicked(pickNode)) 
        { 
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_WORLD_PICK_SHEEP);
            
            VappWidget3ePetSheepInterruptOption option;
            //option.configByType(SI_TAP_SHEEP, pCamera);
            option.m_type = SI_TAP_SHEEP;
            option.m_pViewer = pCamera;
            m_sheep->interrupt(option);           
            //m_sheep->tapSheep(pCamera);
            return VFX_TRUE;
        }
    }while(0);

    // grow a new grass if tap on board
    do
    {
        // calculate the projection point of clicked pos on the plane which stage borad located
        VfxVector3f pIntersect;
        getIntersectionOnBoard(pCamera, vIncidentRay, pIntersect);  
        if(!isOutOfBounds(pIntersect) && 
           VappWidget3dPetSheepWorld::MAX_GRASS_IN_SHEEP_WORLD > m_sheep->getGrassCount())
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_WORLD_ADD_GRASS);
            addGrass(pIntersect);
            return VFX_TRUE;
        }
    }while(0);

    // check if jump btn is tapped
    do
    {
        VfxNode *pickNode = m_world->pick(pCamera, vIncidentRay);
        if(m_jumpBtn == pickNode)
        {
            MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_WORLD_PRESS_JUMP_BTN);
            if(m_stage){ m_stage->playAnim(); }
            m_sheep->prepareToJumpRailing();        
        }
    }while(0);
  
    return VFX_TRUE;
}

void VappWidget3dPetSheepWorld::configScene()
{
    if(g_isResMode)
        VfxAssetLoader::loadSceneBegin(m_world, VAPP_WIDGET_3D_PET_SHEEP_STAGE);  
    else          
        VfxAssetLoader::loadSceneBegin(m_world, VFX_WSTR("E:\\Sheep_v3\\stage\\stage.scn"));          

    m_jumpBtn = (VfxMesh *)VfxAssetLoader::findObjByName(VFX_STR("btn_jump-node_PIVOT"));  
    if(m_jumpBtn)
    {
        m_jumpBtn->setPickable(VFX_TRUE);
    }
    VfxAssetLoader::loadSceneEnd();

    VFX_OBJ_CREATE_EX(m_stage, VappWidget3dPetSheepStage, m_world, (m_world));

    m_camera = m_world->getActiveCamera();
    if(m_camera)
    {
        VFX_OBJ_CLOSE(m_cameraQTL);
        VFX_OBJ_CREATE(m_cameraQTL, VfxQuaternionfTimeline, m_world);
        m_cameraQTL->setTarget(m_camera);
        m_cameraQTL->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
    }
}

void VappWidget3dPetSheepWorld::getIntersectionOnBoard(const VfxVector3f pRay, const VfxVector3f vRay, VfxVector3f& pos)
{
    // TODO: handle vRay.z = 0
    // note stage board in on x-y plane
    VfxFloat factor = pRay.z / vRay.z;
    pos.x = pRay.x - vRay.x * factor;
    pos.y = pRay.y - vRay.y * factor;
    pos.z = 0;   
}

VfxBool VappWidget3dPetSheepWorld::isOutOfBounds(const VfxVector3f p)
{
    if( (0 != p.z) || 
        (STAGE_BOARD_MIN_X + STAGE_GRASS_VALID_OFFSET > p.x) ||
        (STAGE_BOARD_MAX_X - STAGE_GRASS_VALID_OFFSET < p.x) || 
        (STAGE_BOARD_MIN_Y + STAGE_GRASS_VALID_OFFSET > p.y) ||
        (STAGE_BOARD_MAX_Y - STAGE_GRASS_VALID_OFFSET < p.y))
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

void VappWidget3dPetSheepWorld::addGrass(const VfxVector3f p)
{
    // create a new grass
    VappWidget3dPetGrass *grass;
    VFX_OBJ_CREATE(grass, VappWidget3dPetGrass, m_world);
    grass->configPos(p);
    grass->playAnim('GROW');

    // add to sheep's to-eat list
    m_sheep->addGrassToEatList(grass);
}

void VappWidget3dPetSheepWorld::rotateViewAngle(const VfxVector3f axis, const VfxFloat theta)
{
    if(NULL == m_camera || NULL == m_cameraQTL){return;}

    m_cameraQTL->m_signalStopped.disconnect(this, &VappWidget3dPetSheepWorld::changeViewAngle2);
    m_cameraQTL->stop();
    VfxQuaternionf q1;
    m_camera->forceGetRotation(q1);


    VfxFloat R = theta / 2;
    VfxQuaternionf q2 = VfxQuaternionf(axis * vfxSin(R), vfxCos(R));
    m_cameraQTL->setFromValue(q1);
    m_cameraQTL->setToValue(q2);
    m_cameraQTL->setDuration(250);
    m_cameraQTL->setAutoReversed(VFX_FALSE);
    m_cameraQTL->setRepeatCount(1);
    //m_cameraQTL->m_signalStopped.connect(this, &VappWidget3dPetSheepWorld::changeViewAngle2);    
    m_cameraQTL->start();

}

void VappWidget3dPetSheepWorld::changeViewAngle(const VfxVector3f axis, const VfxFloat theta, const VfxBool treatAsEnd)
{
    if(NULL == m_camera || NULL == m_cameraQTL){return;}

    m_cameraQTL->m_signalStopped.disconnect(this, &VappWidget3dPetSheepWorld::changeViewAngle2);
    m_cameraQTL->stop();
    VfxQuaternionf q1;
    m_camera->forceGetRotation(q1);


    VfxFloat R = theta / 2;
    VfxQuaternionf q2 = VfxQuaternionf(axis * vfxSin(R), vfxCos(R)) * q1;
    m_cameraQTL->setFromValue(q1);
    m_cameraQTL->setToValue(q2);
    m_cameraQTL->setDuration(250);
    m_cameraQTL->setAutoReversed(VFX_FALSE);
    m_cameraQTL->setRepeatCount(1);

    
    //if(treatAsEnd && VfxQuaternionf(1, 0, 0, 1) != q1)
    //{
    //    m_cameraQTL->m_signalStopped.connect(this, &VappWidget3dPetSheepWorld::changeViewAngle2);
    //}
    m_cameraQTL->m_signalStopped.connect(this, &VappWidget3dPetSheepWorld::changeViewAngle2);    
    m_cameraQTL->start();
}

void VappWidget3dPetSheepWorld::changeViewAngle2(VfxBaseTimeline *timeline, VfxBool isCompleted)
{
    m_cameraQTL->m_signalStopped.disconnect(this, &VappWidget3dPetSheepWorld::changeViewAngle2);    
    resetCameraRotation();
}

void VappWidget3dPetSheepWorld::swipCamera(const VfxId id)
{
    const VfxFloat degree = ('UP' == id)? 30 : -30;    
    const VfxFloat radians = DEGREES_TO_RADIANS(degree);
    changeViewAngle(VfxVector3f(1, 0, 0), radians, VFX_TRUE);
}

void VappWidget3dPetSheepWorld::resetCameraRotation()
{
    if(NULL == m_camera || NULL == m_cameraQTL){return;}


    m_cameraQTL->m_signalStopped.disconnect(this, &VappWidget3dPetSheepWorld::changeViewAngle2);
    m_cameraQTL->stop();
    VfxQuaternionf q1;   m_camera->forceGetRotation(q1);
    VfxQuaternionf q2 = VfxQuaternionf(VfxVector3f(1, 0, 0) * vfxSin(0), vfxCos(0));
    if(q2 == q1 || VfxQuaternionf(0, 0, 0, 1) == q1)
    {
        return;
    }

    m_cameraQTL->setFromValue(q1);
    m_cameraQTL->setToValue(q2);
    m_cameraQTL->setDuration(500);
    m_cameraQTL->setAutoReversed(VFX_FALSE);
    m_cameraQTL->setRepeatCount(1);
	m_cameraQTL->start();
}

void VappWidget3dPetSheepWorld::getSheepPosAndFrontTo(VfxVector3f &p, VfxVector3f &nvFront)
{
    m_sheep->getCurrentWorldPos(p);
    nvFront = m_sheep->getFrontTo();
}

void VappWidget3dPetSheepWorld::setSheepPosAndFrontTo(VfxVector3f p, VfxVector3f nvFront)
{
    m_sheep->setPosAndFrontTo(p, nvFront);
}

void VappWidget3dPetSheepWorld::launchStartDelayTimer(const VfxMsec duration)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_WORLD_LAUNCG_START_DELAY_TIMER);   
    VfxTimer *timer;
    VFX_OBJ_CREATE(timer, VfxTimer, this);
    timer->setStartDelay(duration);
    timer->setDuration(duration);
    timer->m_signalTick.connect(this, &VappWidget3dPetSheepWorld::onStartDelayTimeOut);
    timer->start();    
}

void VappWidget3dPetSheepWorld::onStartDelayTimeOut(VfxTimer *timer)
{
    MMI_TRACE(TRACE_GROUP_3, TRC_VAPP_WIDGET_3D_PET_WORLD_LAUNCG_START_DELAY_TIMEOUT);       
    timer->stop();
    timer->m_signalTick.disconnect(this, &VappWidget3dPetSheepWorld::onStartDelayTimeOut);
    VFX_OBJ_CLOSE(timer);
    
    // note change to standing state only if current state is sheep_init
    // in other words, sheep does not active yet
    if(m_sheep && SHEEP_INIT == m_sheep->getState())
    {
        m_sheep->changeState(SHEEP_STANDING);
    }
}

void VappWidget3dPetSheepWorld::slotDevHotKeyClicked(VfxU8 id)
{
    printCameraPos();
    switch (id)
    {
    case 0:        
        m_sheep->actionAnimTest(SHEEP_ANIM_END);
        break;
    case 1:
        m_sheep->actionAnimTest(SHEEP_ANIM_WALK);
        break;
    case 2:        
        m_sheep->actionAnimTest(SHEEP_ANIM_EAT);
         break;
    case 3:
        m_sheep->actionAnimTest(SHEEP_ANIM_SLEEP);
        break;
    case 4:
        m_sheep->actionAnimTest(SHEEP_ANIM_STAND_LOOK_AROUND);
        break;
    case 5:        
        m_sheep->actionAnimTest(SHEEP_ANIM_STAND_LOOK_STRETCH);
        break;
    case 6:        
        m_sheep->actionAnimTest(SHEEP_ANIM_STAND_SHAKE_HEAD);
        break;
    case 7:        
        m_sheep->actionAnimTest(SHEEP_ANIM_HI_1);
        break;
    case 8:        
        m_sheep->actionAnimTest(SHEEP_ANIM_HI_2);
        break;
    case 9:
        m_sheep->actionAnimTest(SHEEP_ANIM_JUMP);
        break;
    case 10: 
        m_sheep->actionAnimTest(SHEEP_ANIM_LEAP);
        break;
    default:
        break;
    }
    printPetPos();
}

void VappWidget3dPetSheepWorld::slotDevTranslationChanged(VfxS32 x, VfxS32 y, VfxS32 z)
{
    m_sheep->translatePet(VfxVector3f(x, y,z));
    printPetPos();
}
void VappWidget3dPetSheepWorld::slotDevScaleChanged(VfxFloat s)
{
    m_sheep->setScale(s);
}
void VappWidget3dPetSheepWorld::slotDevRotationChanged(VfxVector3f axis, VfxFloat theta)
{
    m_sheep->rotatePet(axis, theta);
}

void VappWidget3dPetSheepWorld::slotAutoAnimaitonEnabled(VfxBool isEnabled)
{
    if(isEnabled)
    {
        changeViewAngle(VfxVector3f(1, 0, 0), VFX_PI / 6);
    }
    else
    {
        m_sheep->prepareToJumpRailing();        
    }
}

void VappWidget3dPetSheepWorld::slotCameraUpdated()
{
    if(NULL == m_camera || NULL == m_cameraQTL){return;}

    m_cameraQTL->m_signalStopped.disconnect(this, &VappWidget3dPetSheepWorld::changeViewAngle2);
    m_cameraQTL->stop();
    VfxQuaternionf q1;   m_camera->forceGetRotation(q1);
    VfxFloat R = VFX_PI / 2;
    VfxQuaternionf q2 = VfxQuaternionf(VfxVector3f(0, 0, 1.f) * vfxSin(R), vfxCos(R)) * q1;
    VfxQuaternionf q3 = normalize(q2);
    
    m_cameraQTL->setFromValue(q1);
    m_cameraQTL->setToValue(q3);
    m_cameraQTL->setDuration(1000);
    m_cameraQTL->setAutoReversed(VFX_TRUE);
    m_cameraQTL->setRepeatCount(2);
    m_cameraQTL->start();
}

void VappWidget3dPetSheepWorld::printPetPos()
{
    VfxVector3f petPos;
    m_sheep->getCurrentWorldPos(petPos);
}

void VappWidget3dPetSheepWorld::printCameraPos()
{
    VfxVector3f pCamera;
    getCameraPos(pCamera);
}

/*****************************************************************************
 * Stage
 *****************************************************************************/
VappWidget3dPet::VappWidget3dPet(): m_petFrame(NULL),
                                          m_developFrame(NULL)
{
}

VappWidgetId VappWidget3dPet::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_3D_PET);
}


VfxSize VappWidget3dPet::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}


VfxS32 VappWidget3dPet::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_3D_PET_NAME);
    VFX_ASSERT(string && size > 0);
    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);
    return vfx_sys_wcslen(string);    
}

VfxFrame *VappWidget3dPet::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_3D_PET_ICON);

    return icon;
 
}

void VappWidget3dPet::onRotateX(VfxFloat angle)
{
    angle = -angle;
    angle = vfxMin(45.f, vfxMax( angle, -60.f));
    const VfxFloat radians = DEGREES_TO_RADIANS(angle);
    m_petFrame->rotateViewAngle(VfxVector3f(1, 0, 0), radians);
}

void VappWidget3dPet::onSwipeUp()
{
    m_petFrame->swipCamera('UP');
}

void VappWidget3dPet::onSwipeDown()
{
    m_petFrame->swipCamera('DOWN');
}

void VappWidget3dPet::onSwipeToNearestView()
{
    m_petFrame->resetCameraRotation();
}

void VappWidget3dPet::onRestoreView(VfxArchive *ar)
{
    PET_MEASURE_TIME_START("PRS");
    createContent(ar, VFX_TRUE);
    PET_MEASURE_TIME_STOP("PRS");
}

void VappWidget3dPet::onSerializeView(VfxArchive *ar)
{
    PET_MEASURE_TIME_START("PSE");
    closeContent(ar, VFX_TRUE);
    PET_MEASURE_TIME_STOP("PSE");
}

void VappWidget3dPet::onCreateView()
{
    PET_MEASURE_TIME_START("PCV");
    VappWidgetMiniStage::onCreateView();
    createContent(NULL, VFX_FALSE);
    PET_MEASURE_TIME_STOP("PCV");   
}

void VappWidget3dPet::onReleaseView()
{
    PET_MEASURE_TIME_START("PRV");
    // note to maintain the same child member count between
    // before onCreateView() and after onReleaseView()
    closeContent(NULL, VFX_FALSE);
    VappWidgetMiniStage::onReleaseView();
    PET_MEASURE_TIME_STOP("PRV");  
}

VfxPoint VappWidget3dPet::onGetEditButtonOffset()
{
    return VfxPoint(WIDTH - EDIT_BTN_OFFSET_X, EDIT_BTN_OFFSET_Y);
}

void VappWidget3dPet::onSuspend()
{
    setCacheMode(VFX_CACHE_MODE_FREEZE);
    VappWidgetMiniStage::onSuspend();
}

void VappWidget3dPet::onResume()
{
    setCacheMode(VFX_CACHE_MODE_AUTO);
    VappWidgetMiniStage::onResume();
}

void VappWidget3dPet::readFromArchive(VfxArchive *ar, VfxVector3f & p,VfxVector3f & nvFront)
{
    PET_MEASURE_TIME_START("PRA");

    if(m_petFrame)
    {
        VfxFPoint p1, p2;
        ar->readFPoint(p1);
        ar->readFPoint(p2);

        p = VfxVector3f(p1.x, p1.y, 0.f);
        nvFront = VfxVector3f(p2.x, p2.y, 0.f);
    }

    PET_MEASURE_TIME_STOP("PRA");    
}

void VappWidget3dPet::writeToArchive(VfxArchive *ar)
{
    PET_MEASURE_TIME_START("PWA");        

    if(m_petFrame)
    {
        VfxVector3f p, nvFront;
        m_petFrame->getSheepPosAndFrontTo(p, nvFront); 
        

        ar->writeFPoint(VfxFPoint(p.x, p.y));
        ar->writeFPoint(VfxFPoint(nvFront.x, nvFront.y));
    }

    PET_MEASURE_TIME_STOP("PWA");        
}

void VappWidget3dPet::createContent(VfxArchive * ar, const VfxBool needReadFromArchive)
{
    PET_MEASURE_TIME_START("PCR");

    // pet widget ui setting
	setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

    // pet widget content
    if(NULL == m_petFrame)
    {
        VFX_OBJ_CREATE(m_petFrame, VappWidget3dPetSheepWorld, this);
    }
    m_petFrame->setSize(WIDTH, HEIGHT);
    m_petFrame->setPos(0, 0);
    
    // debug and develop utility UI
    if(g_isDebugMode)
    {
        createDevelopFrame();
    }

    // update pos and front direction
    if(needReadFromArchive)
    {
        VfxVector3f p, nvFront;
        readFromArchive(ar, p, nvFront);
        m_petFrame->setSheepPosAndFrontTo(p, nvFront);
    }

    // launch start delay timer
    m_petFrame->launchStartDelayTimer(2000);

    PET_MEASURE_TIME_STOP("PCR");
}

void VappWidget3dPet::closeContent(VfxArchive * ar, const VfxBool needWriteToArchive)
{
    PET_MEASURE_TIME_START("PCL");

    if(needWriteToArchive && ar)
    {
        writeToArchive(ar);
    }
    VFX_OBJ_CLOSE(m_petFrame);
    VFX_OBJ_CLOSE(m_developFrame);

    PET_MEASURE_TIME_STOP("PCL");
}

void VappWidget3dPet::createDevelopFrame()
{
    if(NULL == m_developFrame)
    {
        VFX_OBJ_CREATE(m_developFrame, VappWidget3dPetDevelopFrame, this);
        m_developFrame->setPos(0, HEIGHT - 80);
        m_developFrame->m_sigDevHotKeyClicked.connect(m_petFrame, &VappWidget3dPetSheepWorld::slotDevHotKeyClicked);
        m_developFrame->m_sigDevTranslation.connect(m_petFrame, &VappWidget3dPetSheepWorld::slotDevTranslationChanged);
        m_developFrame->m_sigDevScale.connect(m_petFrame, &VappWidget3dPetSheepWorld::slotDevScaleChanged);
        m_developFrame->m_sigDevRotation.connect(m_petFrame, &VappWidget3dPetSheepWorld::slotDevRotationChanged);
        m_developFrame->m_sigAutoAnimaitonEnabled.connect(m_petFrame, &VappWidget3dPetSheepWorld::slotAutoAnimaitonEnabled);
        m_developFrame->m_sigCameraUpdated.connect(m_petFrame, &VappWidget3dPetSheepWorld::slotCameraUpdated);
    }
}

#endif /* defined(__COSMOS_3D_V10__) */ 

