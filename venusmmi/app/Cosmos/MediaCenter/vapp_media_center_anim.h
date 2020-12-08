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
 *  vapp_media_center_anim.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  MediaCenter APP, screen and CUI classes
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/

#ifndef __VAPP_MEDIA_CENTER_ANIM_H__
#define __VAPP_MEDIA_CENTER_ANIM_H__

#include "MMI_features.h"
#ifdef __MMI_3D_MEDIA_CENTER__

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h"

#include "vfx_asset_loader.h"
#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_pass.h"
#include "vfx_shader_uniforms.h"
#include "vfx_shader.h"
#include "vfx_texture.h"
#include "vfx_light.h"
#include "vfx_bounding_volume.h"
#include "vfx_render_buffer.h"

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
class VappMediaCenterAnimTimeline;
class VappMediaCenterAnimPlayerOption;
class VappMediaCenterAnimPlayer;

/***************************************************************************** 
 * Class : VappMediaCenterAnimTimeline
 *****************************************************************************/

// note the target of VappMediaCenterAnimTimeline is its parent
class VappMediaCenterAnimTimeline : public VfxFloatTimeline
{    
    VFX_DECLARE_CLASS(VappMediaCenterAnimTimeline);
public:
    VappMediaCenterAnimTimeline()
        :m_anim(NULL), 
         m_discardPreAnim(VFX_TRUE){};

protected:
    virtual void onInit();
    virtual void onDeinit();

public:
    VfxBool getDiscardPreAnim() const;    
    void setDiscardPreAnim(const VfxBool b);
    void configAnim(const VfxResId id, VfxGroup* target);
    void configAnim(const VfxWString &path, VfxGroup* target);    
    void configAnim(VfxAnimation *anim, VfxGroup* target);
    void configAnimEx(VfxAnimation *anim, 
						VfxGroup* target,
                        const VfxMsec  duration,
                        const VfxFloat fromValue,
                        const VfxFloat toValue,
                        const VfxS32   repeateCount,
                        const VfxFloat isAutoReversed);
    
    void unconfigAnim();

    void startEx(VfxBool randomDecks = VFX_FALSE);

private:    
    VfxWeakPtr<VfxAnimation> m_anim;
    VfxBool m_discardPreAnim;   // VFX_TRUE if need delet m_anim while call unconfigAnim()
};


/***************************************************************************** 
 * Class : VappMediaCenterAnimPlayer
 * VappMediaCenterAnimPlayer supports playing a set of animation depondon play list
 *****************************************************************************/

// TODO: support animaiton which is composed of a set animation, or multiple playlist support
// TODO: ex: action animation of pet widget

class VappMediaCenterAnimPlayerOption : public VfxBase
{
public:
    VappMediaCenterAnimPlayerOption()
        : m_shouldShuffle(VFX_TRUE), 
          m_repeateForever(VFX_TRUE),
          m_randomDecks(VFX_FALSE){};

    void configAsGeneralCase()
    {
        m_shouldShuffle = VFX_TRUE; 
        m_repeateForever = VFX_TRUE;
        m_randomDecks = VFX_FALSE;
    };

    void  configAsRadioDJ()
    {
        m_shouldShuffle = VFX_TRUE; 
        m_repeateForever = VFX_TRUE;
        m_randomDecks = VFX_TRUE;
    };
    
    VfxBool shouldShuffle() const
    {
        return m_shouldShuffle;
    };
    VfxBool shouldRepeate() const
    {
        return m_repeateForever;
    };

    VfxBool randomDecks() const
    {
        return m_randomDecks;
    }

    void setShuffle(const VfxBool b){m_shouldShuffle = b;}
    void setRepeat(const VfxBool b){m_repeateForever = b;}
    void setRandomDecks(const VfxBool b){m_randomDecks = b;}
    
private:
    VfxBool m_shouldShuffle;
    VfxBool m_repeateForever;
    VfxBool m_randomDecks;
};

class VappMediaCenterAnimPlayer : public VfxObject
{
    VFX_DECLARE_CLASS(VappMediaCenterAnimPlayer);
public:
    VappMediaCenterAnimPlayer()
        :m_animPly(NULL),
        m_target(NULL),
        m_currentAnimIndex(-1){};
    VappMediaCenterAnimPlayer(const VappMediaCenterAnimPlayerOption &option)
        :m_animPly(NULL),
        m_target(NULL),
        m_option(option),
        m_currentAnimIndex(-1){};
    
protected:
    virtual void onInit();
    virtual void onDeinit();

public:
    // init the anim playback target and create m_animPly
    // note configTarget() should be called before any player operator
    // note playerlist will be reset if we reset target    
    void configTarget(VfxGroup* target);
    void unconfigTarget();

    // playlist operator    
    void resetPlaylist();
    void addToPlaylist(VfxAnimation *anim);
    VfxS32 getTotalAnimCount() const;   
    
    //player operator    
    void stop();
    void play();    
    void playAnAnim(const VfxU32 index);

    
private:
    void onPlayAnAnimFinished(VfxBaseTimeline *timeline, VfxBool isComplete);

private:
    VfxBool isValidAnimIndex(const VfxS32 index) const ;
    VfxBool isLastAnim(const VfxS32 index) const;
    VfxAnimation* getAnimByIndex(const VfxS32 index);
    void setCurrentAnimIndex(const VfxS32 index);
    VfxS32 getCurrentAnimIndex()const;
    VfxS32 getNextAnimIndex() const;
    
private:
    VappMediaCenterAnimPlayerOption m_option;
    VappMediaCenterAnimTimeline *m_animPly;    
    VfxList<VfxAnimation *> m_playlist;
    VfxGroup *m_target;
    
    VfxS32 m_currentAnimIndex;
};

#endif // __COSMOS_3D_MEDIA_CENTER__
#endif // __VAPP_MEDIA_CENTER_ANIM_H__

