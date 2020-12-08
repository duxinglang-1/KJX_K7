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
 *  vapp_gallery_slideshow_3d.h
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

#ifndef __VAPP_GALLERY_SLIDESHOW_3D_H__
#define __VAPP_GALLERY_SLIDESHOW_3D_H__
#include "MMI_features.h"
#include "cp\vapp_image_viewer_cp.h"

#if defined(__MMI_FTO_GALLERY__) && defined(__VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__)
#ifdef __COSMOS_3D_V10__
#include "vapp_gallery_viewer.h"
#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_mesh.h"
#include "vfx_material.h"
#include "vfx_texture.h"
#include "vfx_light.h"
#include "vfx_render_buffer.h"

/***************************************************************************** 
 * Include
 *****************************************************************************/
class VappGallerySceneSlideshow : public VappGallerySlideshowBase
{
public:
    VappGallerySceneSlideshow();
    
    virtual void onInit();
    virtual void onDeinit();

    virtual void getOrientationLimit(VfxBool &hasLimit, VfxScrRotateTypeEnum &orientation);
    
    virtual void playOpening();
    virtual void playEnding();

    virtual void setNextMedia(VfxFrame *frame);
    virtual void playMedia();

    virtual VfxBool handleGesture(VappGalleryGestureTranslator *sender, VappGalleryGesture gesture);
    virtual VfxBool canPlayMedia();


// debugging functions
public:
    void onDebugBtn(VfxObject *sender, VfxId btnId);

protected:
    class PhotoInfo : public VfxBase
    {
    public:
        VfxWeakPtr<VfxFrame> m_media;       // input viewer panel
        VfxWeakPtr<VfxFrame> m_mediaTexFrame; // input media (cropped) for frame texture
        VfxWeakPtr<VfxGroup> m_group;       // node of entire photo & shadow
        VfxWeakPtr<VfxGroup> m_dropNode;    // node of photo drop animation
        VfxVector3f m_pos;
        VfxSize m_mediaSize;                // displayed media size (in pixels)
        VfxFloat m_degree;
    public:
        void getNodeName(VfxString &name) const;
        VfxResId getSceneId() const;
        VfxResId getAnimationId() const;
        void getTextureSize(VfxSize &size) const;
    
        enum AspectRatioType
        {
            ASPECT_3v2,
            ASPECT_4v3,
            ASPECT_5v3,
            ASPECT_16v9,
        };

        AspectRatioType getAspectRatioType() const;     // returns aspect ratio type (regardless landscape or portrait)
        VfxBool isPortrait() const;                     // VFX_TRUE if we should use portrait mesh
    };

protected:
    void loadScene();
    void loadPhotoNode(
            PhotoInfo &photo, 
            VfxGroup *parentNode,
            VfxMesh *&photoMesh);
                        

    void onEndingFinished(VfxBaseTimeline *, VfxBool);

    void onAnimationFinish(VfxTimer *sender);
    void onStartDrop(VfxTimer *sender);
    
    void onStartMove(VfxTimer *sender);
    void translateGroup(VfxNode *group, const VfxVector3f &from, const VfxVector3f &to);
    void moveTable(const VfxVector2f &from, const VfxVector2f &to);

    void createCameraTimeline();

    void showStateIcon(const VfxImageSrc &icon);

    // returns a value between [center - range, center + range]
    VfxFloat randomRange(VfxFloat center, VfxFloat range);

    void onOpeningFinish(VfxBaseTimeline *sender, VfxBool finished);
    
protected:
    VfxFrame *m_debugPanel;
    VfxFrame *m_currentMedia;
    VfxFrame *m_nextMedia;

    VfxFrame *m_worldFrame;
    VfxWorld *m_world;
    VfxLight *m_light;
    VfxAnimation *m_photoAnim;

    VfxShaderVariable *m_floorZ;    // HACK : adjut floor z pos in shader
    VfxTimer *m_dropDelayTimer;     // wait X sec to start drop animation
    VfxTimer *m_moveDelayTimer;     // wait Y sec to start moving camera
    VfxTimer *m_animFinishTimer;    // when will total animation effect finish

    VfxFloatTimeline *m_openEndBlackTimeline;
    VfxFloatTimeline *m_openEndSceneTimeline;

    VfxFloatTimeline *m_camTimeline;
    VfxAnimation *m_camAnimation;
    VfxVector3fTimeline *m_camPosTimeline;
    VfxQuaternionfTimeline *m_camRotTimeline;

    
    VfxMesh *m_table;
    VfxVector2f m_tableTexCoord;
    VfxVector2fTimeline *m_tableTimeline;
    typedef VfxList<PhotoInfo> PhotoList;
    PhotoList m_photos;

    VfxNode *m_mask;

    VfxBool m_enlargeMedia;
    VfxBool m_isOpening;
    VfxBool m_ignoreInput;
    VfxFrame *m_slideshowStateIcon;
};
#endif // __COSMOS_3D_V10__
#endif
#endif // __VAPP_GALLERY_SLIDESHOW_3D_H__
