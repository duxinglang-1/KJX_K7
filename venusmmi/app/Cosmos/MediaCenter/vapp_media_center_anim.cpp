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
 *  vapp_media_center_anim.cpp
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
 ****************************************************************************/

#include "MMI_features.h" 
#ifdef __MMI_3D_MEDIA_CENTER__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_config.h"
#include "vfx_object.h"
#include "vcp_include.h"
#include "vapp_media_center_anim.h"
#include "vapp_media_center_util.h"

extern "C"
{
#include "mmi_rp_vapp_media_center_def.h"
#include "MMI_media_app_trc.h"
}


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Class Implementation
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappMediaCenterAnimTimeline", VappMediaCenterAnimTimeline, VfxFloatTimeline);
VFX_IMPLEMENT_CLASS("VappMediaCenterAnimPlayer", VappMediaCenterAnimPlayer, VfxObject);

/***************************************************************************** 
 * Class Implementation : VappMediaCenterApp
 *****************************************************************************/
void VappMediaCenterAnimTimeline::onInit()
{
    VfxFloatTimeline::onInit();
}
    
void VappMediaCenterAnimTimeline::onDeinit()
{
    stop();
    unconfigAnim();
    
    VfxFloatTimeline::onDeinit();
}

void VappMediaCenterAnimTimeline::setDiscardPreAnim(const VfxBool b)
{
    m_discardPreAnim = b;
};

VfxBool VappMediaCenterAnimTimeline::getDiscardPreAnim() const
{
    return m_discardPreAnim;
};

void VappMediaCenterAnimTimeline::configAnim(const VfxResId id, VfxGroup* target)
{
    VfxAnimation *anim = NULL;
    VFX_OBJ_CREATE(anim, VfxAnimation, target);    
    VfxAssetLoader::loadAnimation(anim, target, id);
    
    configAnimEx(anim, target, anim->getTotalDuration(), 0.f, 1.f, 1, VFX_FALSE);
}

void VappMediaCenterAnimTimeline::configAnim(const VfxWString &path, VfxGroup* target)
{
    VfxAnimation *anim = NULL;
    VFX_OBJ_CREATE(anim, VfxAnimation, target);    
    VfxAssetLoader::loadAnimation(anim, target, path);
    
    configAnimEx(anim, target, anim->getTotalDuration(), 0.f, 1.f, 1, VFX_FALSE);
}

void VappMediaCenterAnimTimeline::configAnim(VfxAnimation *anim, VfxGroup* target)
{
    configAnimEx(anim, target, anim->getTotalDuration(), 0.f, 1.f, 1, VFX_FALSE);
}

void VappMediaCenterAnimTimeline::configAnimEx( 
							VfxAnimation *anim, 
							VfxGroup *target,
							const VfxMsec  duration,
							const VfxFloat fromValue,
							const VfxFloat toValue,
							const VfxS32   repeateCount,
							const VfxFloat isAutoReversed)
{
    VFX_DEV_ASSERT(anim);
    
    _ME_TRACE("[MediaCenter][ATL] configAnimEx");
    _ME_TRACE("[MediaCenter][ATL] configAnimEx");
    
    unconfigAnim();
    m_anim = anim;

    // config target
    setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    setTarget(target);

    // set timeline parameter
    setDuration(duration);
    setFromValue(fromValue);
    setToValue(toValue);    
    setRepeatCount(repeateCount);
    setAutoReversed(isAutoReversed);    
    setIsFromCurrent(VFX_FALSE);

    // set reference timeline
    m_anim->setTimelineTime(this);
    
    MEDIA_CENTER_STOP("[MediaCenter][ATL] configAnimEx");
}

void VappMediaCenterAnimTimeline::unconfigAnim()
{
    _ME_TRACE("[MediaCenter][ATL] unconfigAnim");
    
    if(m_anim.isValid())
    {
        m_anim.get()->setTimelineTime(NULL);
    }
    
    if(getDiscardPreAnim())
    {
        VFX_OBJ_CLOSE(m_anim);
        m_anim = NULL;
    }
}

VfxS32 g_randomDecksBase = 250;
VfxS32 g_randomDecksOffset = 200;
VfxS32 g_randomDecksFactor = 4;

void VappMediaCenterAnimTimeline::startEx(VfxBool randomDecks)
{
    _ME_TRACE("[MediaCenter][ATL] startEx");

    if(!randomDecks)
    {
        //setIsFromCurrent(VFX_FALSE);
        //setDuration(m_anim->getDuration());
        start();
		return;
    }

    VfxFloat toValue = (rand() % 20) / 20.f;
	toValue = (0.2f > toValue)? (0.9f - toValue): toValue;
    
    VfxS32 duration = (rand() % g_randomDecksFactor) * g_randomDecksOffset + g_randomDecksBase;
    
    setIsFromCurrent(VFX_TRUE);
    setToValue(toValue);
    setDuration(duration);
    start();
}

/***************************************************************************** 
 * Class Implementation : VappMediaCenterMenuCache
 *****************************************************************************/
void VappMediaCenterAnimPlayer::onInit()
{
    VfxObject::onInit();
    
    // init playlist
    m_playlist.init(this);    
}; 

void VappMediaCenterAnimPlayer::onDeinit()
{
    unconfigTarget();
    VfxObject::onDeinit();
}

void VappMediaCenterAnimPlayer::configTarget(VfxGroup* target)
{
    unconfigTarget();
    m_target = target;

    VFX_OBJ_CREATE(m_animPly, VappMediaCenterAnimTimeline, this);
    m_animPly->setDiscardPreAnim(VFX_FALSE);    
}

void VappMediaCenterAnimPlayer::unconfigTarget()
{
    if(m_animPly)
    {
        m_animPly->stop();
    }

    m_target = NULL;
    resetPlaylist();

    VFX_OBJ_CLOSE(m_animPly);
    m_animPly = NULL;
}

void VappMediaCenterAnimPlayer::resetPlaylist()
{
    VfxList<VfxAnimation *>::It iter;
    for(iter = m_playlist.begin(); !iter.isNull(); ++iter)
    {
        VfxAnimation *anim = (*iter);
        anim->setTimelineTime(NULL);

        VFX_OBJ_CLOSE(anim);
        anim = NULL;
    }
    
    m_playlist.clear();
    m_currentAnimIndex = -1;
}

void VappMediaCenterAnimPlayer::addToPlaylist(VfxAnimation *anim)
{
    m_playlist.pushBack(anim);
}

VfxS32 VappMediaCenterAnimPlayer::getTotalAnimCount() const
{
    return m_playlist.size();
}

void VappMediaCenterAnimPlayer::stop()
{
    if(!m_animPly){return;}
    
    m_animPly->m_signalStopped.disconnect(this, &VappMediaCenterAnimPlayer::onPlayAnAnimFinished);
    m_animPly->stop();
}

void VappMediaCenterAnimPlayer::play()
{
    _ME_TRACE("[MediaCenter][AnimPlayer] play()");

    VfxS32 nextAnimIndex = getNextAnimIndex();
    if(!isValidAnimIndex(nextAnimIndex))
    {
        return;
    }

    // check if the last anim is already played and repeate option turn off
    if(isLastAnim(m_currentAnimIndex )&& 
       !m_option.shouldRepeate())
    {
        return;
    }
    
    playAnAnim(nextAnimIndex);
}

void VappMediaCenterAnimPlayer::playAnAnim(const VfxU32 index)
{
    _ME_TRACE_1("[MediaCenter][AnimPlayer] playAnAnim(), animIndex = %d", index);

    VfxAnimation *anim = getAnimByIndex(index);
    if(m_animPly && anim && m_target)
    {
        setCurrentAnimIndex(index);
        
        m_animPly->configAnim(anim, m_target);
        m_animPly->m_signalStopped.connect(this, &VappMediaCenterAnimPlayer::onPlayAnAnimFinished);
        m_animPly->startEx(m_option.randomDecks());
    }
}

void VappMediaCenterAnimPlayer::onPlayAnAnimFinished(VfxBaseTimeline *timeline, VfxBool isComplete)
{
    _ME_TRACE_1("[MediaCenter][AnimPlayer] onPlayAnAnimFinished[]%d", isComplete);
    if(!isComplete){return;}

    if(NULL == m_animPly){return;}

    m_animPly->m_signalStopped.disconnect(this, &VappMediaCenterAnimPlayer::onPlayAnAnimFinished);
    if(m_option.shouldRepeate())
    {
        play();
    }
}

VfxBool VappMediaCenterAnimPlayer::isValidAnimIndex(const VfxS32 index)const
{
    if( m_playlist.size() <= index || 0 > index )
    {
        return VFX_FALSE;
    }
    return VFX_TRUE;
}

VfxBool VappMediaCenterAnimPlayer::isLastAnim(const VfxS32 index) const
{
    if(!isValidAnimIndex(index))
    {
        return VFX_FALSE;
    }

    if(getTotalAnimCount() == m_currentAnimIndex + 1)
    {
        return VFX_TRUE;
    }
    return VFX_FALSE;
}

VfxAnimation* VappMediaCenterAnimPlayer::getAnimByIndex(const VfxS32 index)
{
    VfxAnimation * anim = NULL;
    VfxS32 i = 0;
    VfxList<VfxAnimation *>::It iter;
    for(iter = m_playlist.begin(); !iter.isNull(); ++iter, i++)
    {
        if(index == i)
        {
            anim = (*iter);
            break;
        }
    }
    return anim;
}

void VappMediaCenterAnimPlayer::setCurrentAnimIndex(const VfxS32 index)
{
    m_currentAnimIndex = index;
}

VfxS32 VappMediaCenterAnimPlayer::getCurrentAnimIndex()const
{
    return m_currentAnimIndex;
}

VfxS32 VappMediaCenterAnimPlayer::getNextAnimIndex() const
{
    _ME_TRACE("[MediaCenter][AnimPlayer] getNextAnimIndex");

    if(0 > getTotalAnimCount())
    {
        return -1;
    }

    VfxS32 nextAnimIndex = m_currentAnimIndex;
    if(m_option.shouldShuffle())
    {
        VfxU32 tick;
        kal_get_time(&tick);    
        srand(tick);
        do
        {
            nextAnimIndex = rand() % getTotalAnimCount();
        }while(m_currentAnimIndex == nextAnimIndex && 1 < getTotalAnimCount());
    }
    else
    {
        nextAnimIndex = (getTotalAnimCount() == nextAnimIndex + 1)? 0 : m_currentAnimIndex + 1;
    }
	return nextAnimIndex;
}

#endif // __COSMOS_3D_MEDIA_CENTER__
