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
 *  vapp_gallery_viewer.h
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
#include "cp\vapp_image_viewer_cp.h"
#if defined(__MMI_FTO_GALLERY__) && defined(__VAPP_IMAGE_VIEWER_CP_ENABLE_SLIDESHOW__)
#if defined(__MMI_FTO_GALLERY__) && defined(__COSMOS_3D_V10__)

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "vfx_mc_include.h" 
#include "vapp_gallery_slideshow_3d.h"
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
#include "vcp_page_panel_3d.h"

static VfxFloat TABLE_OFFSET = -10.0f;
static VfxFloat SHADOW_Z = 0;
static VfxMsec OPEN_DURATION = 1000;
static VfxMsec MOVE_DURATION = 1000;
static VfxMsec MOVE_DELAY = 300;
static VfxMsec DROP_DELAY = 150;
static VfxFloat Z_FACTOR = -1;
static VfxFloat Z_OFFSET = -1;
static VfxFloat MOVE_X_CENTER = 645;
static VfxFloat MOVE_X_RANGE = 30;
static VfxFloat MOVE_Y_CENTER = 215;
static VfxFloat MOVE_Y_RANGE = 50;
static VfxFloat DEG_RANGE = 17;
static VfxFloat CAMERA_Y = 0;
static VfxFloat CAMERA_RY = 0;
static VfxFloat CAMERA_RX = 0;
static VfxBool g_useCorner = VFX_FALSE;
static VfxBool g_useStateIcon = VFX_FALSE;

class VappGalleryLensEffect : public VfxProceduralMesh
{
    virtual vrt_u32 getVertexArrayCount() const
    {
        return 1;
    }

    virtual vrt_u32 getVertexCount() const
    {
        return 4;
    }

    virtual vrt_u32 getComponentCount(vrt_u32 i) const
    {
        return 2;
    }

    virtual vrt_type_id_enum getComponentDataType(vrt_u32 i) const
    {
        return VRT_TYPE_ID_FLOAT;
    }

    virtual const vrt_char *getAttributeName(vrt_u32 i) const
    {
        const vrt_char *m_attributeName[] =
        {
            "a_vertexScreenPos",
        };
        return m_attributeName[0];
    }

    virtual vrt_bool isNormalized(vrt_u32 i) const
    {
        return VRT_FALSE;
    }

    virtual const vrt_float *getScaleVector(vrt_u32 i) const
    {
        static const vrt_float m_scale[] = {1.0f, 1.0f, 1.0f, 1.0f};
        return m_scale;
    }

    virtual const vrt_float *getBiasVector(vrt_u32 i) const
    {
        static const vrt_float m_bias[] = {0.0f, 0.0f, 0.0f, 0.0f};
        return m_bias;
    }

    /* index buffer */
    virtual vrt_u32 getIndexBufferCount() const
    {
        return 1;
    }

    virtual VrtPrimitiveType getPrimitiveType(vrt_u32 i) const
    {
        return VRT_PRIMITIVE_TRIANGLE_FAN;
    }

    virtual vrt_u32 getIndexCount(vrt_u32 i) const
    {
        return getVertexCount();
    }

    virtual vrt_type_id_enum getIndexDataType(vrt_u32 i) const
    {
        return VRT_TYPE_ID_UNKNOWN;
    }

    virtual void initVertexArrays(void **va_buffers) const
    {
        float *screenPos = (float *)va_buffers[0];

        screenPos[0] = -1.f;
        screenPos[1] = -1.f;

        screenPos[2] = -1.f;
        screenPos[3] = 1.f;
        
        screenPos[4] = 1.f;
        screenPos[5] = 1.f;

        screenPos[6] = 1.f;
        screenPos[7] = -1.f;
    }

    virtual void initIndexBuffers(void **data) const
    {
    }

};

void VappGallerySceneSlideshow::onDebugBtn(VfxObject *sender, VfxId id)
{
    switch(id)
    {
    case 'ROTP':
        g_useCorner = !g_useCorner;
        break;
    case 'LOWR':
        TABLE_OFFSET -= 10;
        if(m_table)
        {
            m_table->setTranslation(VfxVector3f(0, 0, TABLE_OFFSET));
        }
        break;
    case 'DELU':
        MOVE_DELAY += 100;
        break;
    case 'DELD':
        MOVE_DELAY -= 100;
        break;
    case 'FLR+':
        SHADOW_Z += 1;
        if(m_floorZ)
            m_floorZ->setValue((VfxFloat)SHADOW_Z);
        break;
    case 'FLR-':
        SHADOW_Z -= 1;
        if(m_floorZ)
            m_floorZ->setValue((VfxFloat)SHADOW_Z);
        break;

    case '_CY+':
        CAMERA_Y += 100;
        break;
    case '_CY-':
        CAMERA_Y -= 100;
        break;
    case '_CRX':
        CAMERA_RX += 10;
        break;
    case '_CRY':
        CAMERA_RY += 10;
        break;        
    }
    
    if(m_world)
    {
        VfxCamera *cam = m_world->getActiveCamera();
        cam->setTranslation(VfxVector3f(0, CAMERA_Y, 0));
        cam->setRotation(VfxQuaternionf());
        cam->rotateX(VFX_DEG_TO_RAD(CAMERA_RX));
    }
}

////////////////////////////////
// Scene slideshow
////////////////////////////////
VappGallerySceneSlideshow::VappGallerySceneSlideshow():
    m_debugPanel(NULL),
    m_worldFrame(NULL),
    m_world(NULL),
    m_photoAnim(NULL),
    m_light(NULL),
    m_table(NULL),
    m_floorZ(NULL),
    m_openEndBlackTimeline(NULL),
    m_openEndSceneTimeline(NULL),
    m_photos(),
    m_dropDelayTimer(NULL),
    m_moveDelayTimer(NULL),
    m_animFinishTimer(NULL),
    m_camTimeline(NULL),
    m_camAnimation(NULL),
    m_camPosTimeline(NULL),
    m_camRotTimeline(NULL),
    m_enlargeMedia(VFX_FALSE),
    m_tableTimeline(NULL),
    m_slideshowStateIcon(NULL),
    m_ignoreInput(VFX_FALSE),
    m_mask(NULL)
{
}
    
void VappGallerySceneSlideshow::onInit()
{
    VappGallerySlideshowBase::onInit();

    VFX_OBJ_CREATE(m_dropDelayTimer, VfxTimer, this);
    m_dropDelayTimer->m_signalTick.connect(this, &VappGallerySceneSlideshow::onStartDrop);
    VFX_OBJ_CREATE(m_moveDelayTimer, VfxTimer, this);
    m_moveDelayTimer->m_signalTick.connect(this, &VappGallerySceneSlideshow::onStartMove);
    VFX_OBJ_CREATE(m_animFinishTimer, VfxTimer, this);
    m_animFinishTimer->m_signalTick.connect(this, &VappGallerySceneSlideshow::onAnimationFinish);

    m_photos.init(this);

    // prepare scene
    loadScene();
}

void VappGallerySceneSlideshow::loadScene()
{
    GALLERY_MEASURE_TIME("SS1");

    // slideshow page have black background
    setBgColor(VFX_COLOR_BLACK);
    setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    
    // create a child frame that host the 3D world
    VFX_OBJ_CREATE(m_worldFrame, VfxFrame, this);
    m_worldFrame->setPos(0, 0);
    m_worldFrame->setSize(LCD_HEIGHT, LCD_WIDTH);
    m_worldFrame->setHidden(VFX_FALSE);
    m_worldFrame->bringToFront();
    VFX_OBJ_CREATE(m_world, VfxWorld, m_worldFrame);
    m_worldFrame->setWorld(m_world);
    // m_worldFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    m_worldFrame->setHints((VfxFrameHintsEnum)(VFX_FRAME_HINTS_DISABLE_COLOR_KEY | VFX_CACHE_MODE_PREVENT_PARENTS));
    m_worldFrame->setCacheMode(VFX_CACHE_MODE_PREVENT_PARENTS);

    // play-pause animating icon
    if(g_useStateIcon)
    {
        VFX_OBJ_CREATE(m_slideshowStateIcon, VfxFrame, this);
        m_slideshowStateIcon->setPos(GDI_LCD_HEIGHT / 2, GDI_LCD_WIDTH / 2);
        m_slideshowStateIcon->setAnchor(0.5f, 0.5f);
        m_slideshowStateIcon->setBgColor(VFX_COLOR_TRANSPARENT);
        m_slideshowStateIcon->bringToFront();
        m_slideshowStateIcon->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_TRANSLUCENT);
        m_slideshowStateIcon->setImgContent(VfxImageSrc(VAPP_GALLERY_3D_SLIDESHOW_PAUSE_OVERLAY));
        m_slideshowStateIcon->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_CENTER);
        m_slideshowStateIcon->setAutoAnimate(VFX_TRUE);
        m_slideshowStateIcon->setSize(300, 300);
        m_slideshowStateIcon->setHidden(VFX_TRUE);
    }
        
    // load the scene
    VfxAssetLoader::loadSceneBegin(m_world, VAPP_GALLERY_3D_SLIDESHOW_SCENE);
    
    do
    {
        // retrieve light object to attach to newly loaded photo mesh.
        m_light = VFX_OBJ_DYNAMIC_CAST(VfxAssetLoader::findObjByName(VFX_STR("Spot001-node")), VfxLight);

        // offset the floor z-pos to compensate timeline interpolation issue
        // (Venus 3D timeline interpolator are different from MAX)
        m_table = VFX_OBJ_DYNAMIC_CAST(VfxAssetLoader::findObjByName(VFX_STR("Box_Floor-node")), VfxMesh);
        if(m_table)
        {
            m_table->translate(VfxVector3f(0, 0, TABLE_OFFSET));
            VfxMaterial *mat = m_table->getMaterial(0);
            VfxPass *pass = mat->getPass(0);
            VfxShaderProgram *prog = pass->getShaderProgram();
            VFX_OBJ_CLOSE(prog);
            VFX_OBJ_CREATE_EX(prog, VfxShaderProgram, mat, (VAPP_GALLERY_3D_SLIDESHOW_B6_VS, VAPP_GALLERY_3D_SLIDESHOW_B6_FS));
            pass->setShaderProgram(prog);
        }
    }while(0);
    VfxAssetLoader::loadSceneEnd();
    
    // the "dark corner"
    if(g_useCorner)
    {
        VappGalleryLensEffect *lensMesh = NULL;
        VFX_OBJ_CREATE(lensMesh, VappGalleryLensEffect, m_world);
        m_mask = lensMesh;
        
        VfxMaterial *mat = NULL;
        VFX_OBJ_CREATE(mat, VfxMaterial, lensMesh);
        lensMesh->setMaterial(0, mat);

        VfxPass *pass = NULL;
        VFX_OBJ_CREATE(pass, VfxPass, mat);
        mat->setPass(0, pass);

        // turn off z-test and back face culling
        VfxCompositingMode *modeConfig;
        VFX_OBJ_CREATE(modeConfig, VfxCompositingMode, pass);
        modeConfig->setDepthTestEnable(VFX_FALSE);
        modeConfig->setDepthWriteEnable(VFX_FALSE);
        pass->setCompositingMode(modeConfig);
        VfxPolygonMode *polygonMode;
        VFX_OBJ_CREATE(polygonMode, VfxPolygonMode, pass);
        polygonMode->setCulling(VFX_CULLING_NONE);
        pass->setPolygonMode(polygonMode);

        // assign shader and texture
        VfxShaderProgram *prog;
        VFX_OBJ_CREATE_EX(prog, VfxShaderProgram, pass, (VAPP_GALLERY_3D_SLIDESHOW_CORNER_VS, VAPP_GALLERY_3D_SLIDESHOW_CORNER_FS));
        pass->setShaderProgram(prog);
        VfxShaderUniforms *uniforms;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        pass->addShaderUniforms(uniforms);
        VfxShaderVariable *var = uniforms->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
        VfxImage2D *img = NULL;
        VfxTexture2D *tex2D = NULL;
        VFX_OBJ_CREATE_EX(img, VfxImage2D, var, (VAPP_GALLERY_3D_SLIDESHOW_DARK_CORNER));
        VFX_OBJ_CREATE_EX(tex2D, VfxTexture2D, var, (img));
        var->setValue(tex2D);
    }

    // adjust camera parameter
    VfxCamera *cam = m_world->getActiveCamera();
    if(cam)
    {
        const VfxVector3f camPos = cam->getTranslation();
        VfxVector3f camWorldPos;
        cam->getWorldPosition(camWorldPos);
        VfxVector3f translation = cam->getTranslation();
        VfxQuaternionf orientation = cam->getRotation();
        
        VfxMatrix4f proj = cam->getProjectionMatrix();
        cam->setGeneric(proj);
    } 

    // opening animation
    
    m_isOpening = VFX_TRUE;
    /*
    VFX_OBJ_CREATE(m_openEndBlackTimeline, VfxFloatTimeline, this);
    m_openEndBlackTimeline->setTarget(this);
    m_openEndBlackTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_openEndBlackTimeline->setFromValue(0.0f);
    m_openEndBlackTimeline->setToValue(1.0f);
    m_openEndBlackTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
    m_openEndBlackTimeline->setDuration(OPEN_DURATION);
    m_openEndBlackTimeline->start();
    */
    setOpacity(1.0f);
    m_worldFrame->setOpacity(0.0f);
    VFX_OBJ_CREATE(m_openEndSceneTimeline, VfxFloatTimeline, m_worldFrame);
    m_openEndSceneTimeline->setTarget(m_worldFrame);
    m_openEndSceneTimeline->setTargetPropertyId(VRT_FRAME_PROPERTY_ID_OPACITY);
    m_openEndSceneTimeline->setFromValue(0.0f);
    m_openEndSceneTimeline->setToValue(1.0f);
    m_openEndSceneTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN);
    // m_openEndSceneTimeline->setStartDelay(OPEN_DURATION);
    m_openEndSceneTimeline->setStartDelay(0);
    m_openEndSceneTimeline->setDuration(OPEN_DURATION);
    m_openEndSceneTimeline->start();
    m_openEndSceneTimeline->m_signalStopped.connect(this, &VappGallerySceneSlideshow::onOpeningFinish);
    
    // debug panel
    // createSceneSlideshowDebugPanel();
}

void VappGallerySceneSlideshow::onDeinit()
{
    VappGallerySlideshowBase::onDeinit();   
}

void VappGallerySceneSlideshow::getOrientationLimit(
        VfxBool &hasLimit, 
        VfxScrRotateTypeEnum &orientation)
{
    hasLimit = VFX_TRUE;
    VfxTopLevel *topLevel = VFX_OBJ_GET_INSTANCE(VfxTopLevel);
    if(topLevel)
    {
        const VfxScrRotateTypeEnum currentOrientation = topLevel->getScreenRotateType();
        if(VFX_SCR_ROTATE_TYPE_270 == currentOrientation ||
           VFX_SCR_ROTATE_TYPE_90 == currentOrientation)
        {
            // if current orientation is 90 or 270, keep it.
            orientation = currentOrientation;
            return;
        }
    }
    
    // by default, opt for 270
    orientation = VFX_SCR_ROTATE_TYPE_270;
    return;
}

void VappGallerySceneSlideshow::playOpening()
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SceneSlideshow]playOpening");
    m_signalFinished.postEmit(NULL, FT_OPENING, VFX_TRUE);
}

void VappGallerySceneSlideshow::onOpeningFinish(VfxBaseTimeline *sender, VfxBool finished)
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SceneSlideshow]playOpening finished");
    
}

void VappGallerySceneSlideshow::playEnding()
{   
    m_ignoreInput = VFX_TRUE;
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SceneSlideshow]playEnding");
    // first we hide all texture frames
    for(PhotoList::It i = m_photos.begin(); i != m_photos.end(); ++i)
    {
        PhotoInfo &info = *i;
        if(info.m_mediaTexFrame.isValid())
        {
            info.m_mediaTexFrame->setOpacity(0);
        }
    }
    
    if(m_world && m_openEndBlackTimeline && m_openEndSceneTimeline)
    {
        // scene fade to black
        m_openEndSceneTimeline->setFromValue(1.0f);
        m_openEndSceneTimeline->setToValue(0.0f);
        m_openEndSceneTimeline->setStartDelay(0);
        m_openEndSceneTimeline->start();

        // black fade to image viewer
        //m_openEndBlackTimeline->setFromValue(1.0f);
        //m_openEndBlackTimeline->setToValue(0.0f);
        //m_openEndBlackTimeline->setStartDelay(OPEN_DURATION);
        //m_openEndBlackTimeline->start();

        m_world->setPropertyDirty(VFX_OBJECT3D_TIMELINE_DIRTY);
        // m_openEndBlackTimeline->m_signalStopped.connect(this, &VappGallerySceneSlideshow::onEndingFinished);
        m_openEndSceneTimeline->m_signalStopped.connect(this, &VappGallerySceneSlideshow::onEndingFinished);
    }
    else
    {
        m_signalFinished.postEmit(NULL, FT_ENDING, VFX_TRUE);
    }
}

void VappGallerySceneSlideshow::onEndingFinished(VfxBaseTimeline *timeline, VfxBool finished)
{
    if(timeline)
    {
        // disconnect to prevent emit redundant endings?
        timeline->m_signalStopped.disconnect(this, &VappGallerySceneSlideshow::onEndingFinished);
    }
    m_signalFinished.postEmit(NULL, FT_ENDING, VFX_TRUE);
}

VfxFloat VappGallerySceneSlideshow::randomRange(VfxFloat center, VfxFloat range)
{
    VfxFloat uniformRandom = (rand() % 10) / 10.f;
    return center + (uniformRandom - 0.5f) * 2 * range;
}

void VappGallerySceneSlideshow::setNextMedia(VfxFrame *frame)
{
    GALLERY_MEASURE_TIME("SS2");
    PhotoInfo photo;
    photo.m_media = frame;

    // setup texture
    // retrieve frame image source
    VappGalleryViewerPanel *viewPanel = static_cast<VappGalleryViewerPanel*>(photo.m_media.get());
    VfxImageSrc imgSrc;
    VfxImageBuffer buf;
    if(viewPanel->hasCachedBuffer() && viewPanel->getPreviewCachedBuffer(buf))
    {
        imgSrc.setImageBuffer(buf);
    }
    else
    {
        viewPanel->getPreviewImage(imgSrc);
    }
    viewPanel->setHidden(VFX_TRUE);
    photo.m_mediaSize = imgSrc.getSize();
    
    // create an aspect-fill frame
    VfxFrame *texFrame = NULL;
    VfxSize texSize;
    VFX_OBJ_CREATE(texFrame, VfxFrame, this);
    photo.getTextureSize(texSize);
    texFrame->setPos(-LCD_HEIGHT, -LCD_HEIGHT);
    texFrame->setSize(texSize);    
    texFrame->setCacheMode(VFX_CACHE_MODE_RESOURCE);
    texFrame->setOpaqueMode(VFX_FRAME_OPAQUE_MODE_FULLY_OPAQUE);
    texFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
    texFrame->setBgColor(VFX_COLOR_BLACK);
    texFrame->setImgContent(imgSrc);
    // we want center-crop the input image
    texFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE_ASPECT_FILL);
    texFrame->sendToBack();
    texFrame->setHidden(VFX_FALSE);
    // texFrame->setHidden(VFX_TRUE);
    texFrame->setOpacity(1.0f); // set to 0.0f causes mess!
    photo.m_mediaTexFrame = texFrame;
            
    // if we're not the first media,
    // pick a random start position for the media.
    if(!m_photos.empty())
    {
        photo.m_pos.x = randomRange(MOVE_X_CENTER, MOVE_X_RANGE);
        // make sure we zig-zag y position, so invert the sign
        static VfxBool inverted = VFX_FALSE;
        const VfxFloat sign = inverted ? -1.0f : 1.0f;
        inverted = !inverted;
        photo.m_pos.y = randomRange(sign * MOVE_Y_CENTER, MOVE_Y_RANGE);
        photo.m_pos.z = 0;
        photo.m_degree = randomRange(0, DEG_RANGE);
    }
    else
    {
        photo.m_degree = 0;
    }
    m_photos.pushBack(photo);
}

void VappGallerySceneSlideshow::loadPhotoNode(
        PhotoInfo &photo, 
        VfxGroup *parentNode,
        VfxMesh *&photoMesh)
{
    VFX_ASSERT(parentNode);
    VfxAssetLoader::loadSceneBegin(parentNode, photo.getSceneId());
    VfxString name;
    photo.getNodeName(name);
    photoMesh = VFX_OBJ_DYNAMIC_CAST(VfxAssetLoader::findObjByName(name), VfxMesh);
    VfxAssetLoader::loadSceneEnd();
}

void VappGallerySceneSlideshow::playMedia()
{
    GALLERY_MEASURE_TIME("SS3");
    VFX_ASSERT(!m_photos.empty());

    // create new group for new photo
    PhotoInfo &photo = m_photos.back();
    VFX_OBJ_CREATE(photo.m_group, VfxGroup, m_world);

    // load the photo drop mesh
    VfxMesh *photoMesh = NULL;
    VFX_OBJ_CREATE(photo.m_dropNode, VfxGroup, photo.m_group.get());
    loadPhotoNode(photo, photo.m_dropNode.get(), photoMesh);
    do
    {
        // perturb photo mesh orientation
        if(photo.m_degree)
        {
            photo.m_group->localRotateZ(VFX_DEG_TO_RAD(photo.m_degree));
        }
        // set correct starting position, we want the mesh
        // to be at least above z = 0
        const VfxBoundingVolume *meshBound = photoMesh->getBoundingVolume();
        if(meshBound)
        {
            photo.m_pos.z = meshBound->m_box.z - meshBound->m_center.z;
        }
        photo.m_group->setTranslation(photo.m_pos);
        // photo is invisible until start dropping
        photo.m_group->setVisible(VFX_FALSE);
        
        // adjust photo material
        for(VfxS32 i = 0; i < 3; ++i)
        {
            VfxMaterial *m = photoMesh->getMaterial(i);
            VfxPass *pass = m->getPass(0);

            // add z-offset to photo material, to prevent fighting with shadow
            VfxCompositingMode *modeConfig;
            VFX_OBJ_CREATE(modeConfig, VfxCompositingMode, pass);
            modeConfig->setDepthOffset(Z_FACTOR, Z_OFFSET);
            modeConfig->setDepthFunc(VFX_DEPTH_FUNC_LEQUAL);
            pass->setCompositingMode(modeConfig);

            // rebind light position
            VfxShaderVariable *varPos = pass->getUniformVariable(VFX_STR("uLightPos"));
            if(varPos)
            {
                varPos->bindValue(m_light, VFX_BINDING_WORLD_SPACE_POSITION);
            }

            // for photo main material only, change the photo texture
            if(1 == i && photo.m_mediaTexFrame.isValid())
            {
                VfxShaderVariable *varTex = pass->getUniformVariable(VFX_STR("uDiffuseSampler"));
                if(varTex)
                {
                    VfxTextureFrame *textureInput = NULL;
                    VFX_OBJ_CREATE_EX(textureInput, VfxTextureFrame, photoMesh, (photo.m_mediaTexFrame.get()));
                    varTex->setValue(textureInput);
                }
            }
            pass->setPropertyDirty(VFX_PASS_SHADER_UNIFORMS_DIRTY);
              
            // add shadow pass
            VfxPass *shadowPass = NULL;
            VFX_OBJ_CREATE(shadowPass, VfxPass, m);
            VfxShaderProgram *program;
            VFX_OBJ_CREATE_EX(program, VfxShaderProgram, shadowPass, (VAPP_GALLERY_3D_SLIDESHOW_SHADOW_VS, VAPP_GALLERY_3D_SLIDESHOW_SHADOW_FS));
            shadowPass->setShaderProgram(program);
            VfxShaderUniforms *shadowUniforms;
            VFX_OBJ_CREATE(shadowUniforms, VfxShaderUniforms, m);
            shadowPass->addShaderUniforms(shadowUniforms);
            VfxShaderVariable *shadowVar = shadowUniforms->addUniformVariable(VFX_STR("u_LightPos"), VFX_TYPE_ID_VEC3, 1);
            shadowVar->bindValue(m_light, VFX_BINDING_WORLD_SPACE_POSITION);
            m_floorZ = shadowUniforms->addUniformVariable(VFX_STR("u_floorZ"), VFX_TYPE_ID_FLOAT, 1);
            m_floorZ->setValue((VfxFloat)SHADOW_Z);
            m->setPassCount(2);
            m->setPass(0, pass);
            m->setPass(1, shadowPass);
        }
    }while(0);

    if(m_mask)
    {
        m_mask->bringToFront();
    }

    // trigger drop animation
    m_dropDelayTimer->setStartDelay(DROP_DELAY);
    m_dropDelayTimer->start();
        
    // also shift the photo when it falls
    m_moveDelayTimer->setStartDelay(MOVE_DELAY);
    m_moveDelayTimer->start();

    // animation finished
    m_animFinishTimer->setStartDelay(3000);
    m_animFinishTimer->start();
}

void VappGallerySceneSlideshow::onStartMove(VfxTimer *sender)
{
    if(m_photos.empty() || m_photos.size() == 1)
    {
        return;
    } 

    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SceneSlideshow]onStartMove");
    // generate movement
    const PhotoInfo &lastPhoto = m_photos.back();
    // use photo z because we don't want to change z-value of photo
    const VfxVector3f camLookAt(0, 0, lastPhoto.m_pos.z);
    const VfxVector3f offset = camLookAt - lastPhoto.m_pos;
    for(PhotoList::It i = m_photos.begin(); i != m_photos.end(); ++i)
    {
        PhotoInfo &info = *i;
        const VfxVector3f newPos = info.m_pos + offset;
        if(info.m_group.isValid())
        {
            translateGroup(info.m_group.get(), info.m_pos, newPos);
        }
        info.m_pos = newPos;
    }
    
    // old table moving out
    if(m_table)
    {
        const VfxVector2f TABLE_TEX_COORD_DIM(5.0f, 15.0F);
        const VfxVector2f TABLE_GEO_DIM(1500, 2000);

        // convert offset from geometry movement to tex coord animation
        VfxVector2f texOffset;
        texOffset.x = -1.0f * offset.x * TABLE_TEX_COORD_DIM.x / TABLE_GEO_DIM.x;
        texOffset.y = offset.y * TABLE_TEX_COORD_DIM.y / TABLE_GEO_DIM.y;
        const VfxVector2f to = m_tableTexCoord + texOffset;
        moveTable(m_tableTexCoord, to);
        
        // re-normalize table texture coordinate between 0-1
        // to manitain precision
        m_tableTexCoord = to;
        m_tableTexCoord.x = fmod(m_tableTexCoord.x, 1.0f);
        m_tableTexCoord.y = fmod(m_tableTexCoord.y, 1.0f);
    }
}

void VappGallerySceneSlideshow::onStartDrop(VfxTimer *sender)
{
    // start dropping animation
    const PhotoInfo &photo = m_photos.back();

    VfxAnimation *dropAnim = NULL;
    VFX_OBJ_CREATE(dropAnim, VfxAnimation, photo.m_dropNode.get());
    VfxAssetLoader::loadAnimation(dropAnim, 
                                  photo.m_dropNode.get(), 
                                  photo.getAnimationId()
                                  );

    dropAnim->start();
    photo.m_group->setVisible(VFX_TRUE);
    photo.m_dropNode->setPropertyDirty(VFX_OBJECT3D_TIMELINE_DIRTY);
}

void VappGallerySceneSlideshow::onAnimationFinish(VfxTimer *sender)
{
    kal_wap_trace(MOD_MMI_MEDIA_APP, TRACE_GROUP_2, "[SceneSlideshow]onAnimationFinish");

    if(m_photos.size() > 2)
    {
        PhotoInfo p = m_photos.front();
        m_photos.popFront();
        VFX_OBJ_CLOSE(p.m_group);
        VFX_OBJ_CLOSE(p.m_mediaTexFrame);
    }
    m_signalFinished.postEmit(NULL, FT_MEDIA, VFX_TRUE);
}

void VappGallerySceneSlideshow::moveTable(const VfxVector2f &from, const VfxVector2f &to)
{
    if(NULL == m_table)
    {
        return;
    }

    if(NULL == m_tableTimeline)
    {
        VfxMaterial *tableMaterial = m_table->getMaterial(0);
        VfxPass *pass = tableMaterial->getPass(0);
        VfxShaderUniforms *uniforms = NULL;
        VFX_OBJ_CREATE(uniforms, VfxShaderUniforms, pass);
        VfxShaderVariable *texScroll = uniforms->addUniformVariable(VFX_STR("u_TexScroll"), VFX_TYPE_ID_VEC2, 1);
        pass->addShaderUniforms(uniforms);
        VFX_OBJ_CREATE(m_tableTimeline, VfxVector2fTimeline, texScroll);
        m_tableTimeline->setTarget(texScroll);
        m_tableTimeline->setTargetPropertyId(VRT_SHADER_VARIABLE_PROPERTY_ID_VEC2);
        m_tableTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
        m_tableTimeline->setDuration(MOVE_DURATION);
    }
    m_tableTimeline->setFromValue(from);
    m_tableTimeline->setToValue(to);
    m_tableTimeline->start();
}

void VappGallerySceneSlideshow::translateGroup(VfxNode *group, const VfxVector3f &from, const VfxVector3f &to)
{
    VfxVector3fTimeline *tlTranslation = NULL;
    VFX_OBJ_CREATE(tlTranslation, VfxVector3fTimeline, group);
    tlTranslation->setTarget(group);
    tlTranslation->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
    tlTranslation->setFromValue(from);
    tlTranslation->setToValue(to);
    tlTranslation->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
    tlTranslation->setDuration(MOVE_DURATION);
    tlTranslation->start();
}

void VappGallerySceneSlideshow::createCameraTimeline()
{
    if(NULL == m_camAnimation)
    {
        VFX_OBJ_CREATE(m_camAnimation, VfxAnimation, m_worldFrame);    
    }
    
    if(NULL == m_camTimeline)
    {
        VfxCamera *cam = m_world->getActiveCamera();
        VFX_OBJ_CREATE(m_camPosTimeline, VfxVector3fTimeline, m_camAnimation);
        m_camPosTimeline->setTarget(cam);
        m_camPosTimeline->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_TRANSLATION);
        m_camPosTimeline->setFromValue(VfxVector3f(0, 0, 0));
        m_camPosTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
        m_camPosTimeline->setStartDelay(300);
        m_camPosTimeline->setDuration(600);
        m_camPosTimeline->setAutoReversed(VFX_FALSE);

        VFX_OBJ_CREATE(m_camRotTimeline, VfxQuaternionfTimeline, m_camAnimation);
        m_camRotTimeline->setTarget(cam);
        m_camRotTimeline->setTargetPropertyId(VRT_TRANSFORMABLE_PROPERTY_ID_ORIENTATION);
        m_camRotTimeline->setFromValue(VfxQuaternionf());
        m_camRotTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
        m_camRotTimeline->setStartDelay(0);
        m_camRotTimeline->setDuration(700);
        m_camRotTimeline->setAutoReversed(VFX_FALSE);

        VFX_OBJ_CREATE(m_camTimeline, VfxFloatTimeline, cam);
        m_camTimeline->setTarget(cam);
        m_camTimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
        m_camTimeline->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_IN_EASE_OUT);
        m_camTimeline->setDuration(1300);
        m_camTimeline->setAutoReversed(VFX_FALSE);
        m_camTimeline->setFromValue(0.0f);
        m_camTimeline->setToValue(1.0f);
        
        m_camAnimation->setTimelineTime(m_camTimeline);
    }
}

void VappGallerySceneSlideshow::showStateIcon(const VfxImageSrc &icon)
{
    if(NULL == m_slideshowStateIcon)
    {
        return;
    }
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDisable(VFX_TRUE);
    m_slideshowStateIcon->setHidden(VFX_FALSE);
    m_slideshowStateIcon->setImgContent(icon);
    m_slideshowStateIcon->setOpacity(0.5f);
    m_slideshowStateIcon->setSize(300, 300);
    m_slideshowStateIcon->setTransform(VfxTransform());
    VfxAutoAnimate::commit();
    VfxTransform t;
    t.data.affine.sx = 2.0f;
    t.data.affine.sy = 2.0f;
    VfxAutoAnimate::begin();
    VfxAutoAnimate::setDuration(1000);
    m_slideshowStateIcon->setTransform(t);
    m_slideshowStateIcon->setOpacity(0.0f);
    VfxAutoAnimate::commit();
}

VfxBool VappGallerySceneSlideshow::handleGesture(VappGalleryGestureTranslator *sender, VappGalleryGesture gesture)
{
    if(m_ignoreInput)
    {
        return VFX_TRUE;
    }

    switch(gesture)
    {
    case VG_TAP:
        createCameraTimeline();
        if(!m_enlargeMedia && m_camTimeline && m_camAnimation)
        {
            m_enlargeMedia = VFX_TRUE;
            showStateIcon(VfxImageSrc(VAPP_GALLERY_3D_SLIDESHOW_PAUSE_OVERLAY));
            
            // adjust target values
            if(!m_photos.empty())
            {
                const PhotoInfo &photo = m_photos.back();
                const VfxFloat camPushZ = photo.isPortrait() ? 190.f : -20.f;
                const VfxFloat camPushY = photo.isPortrait() ? 20.f : 0.f;
                m_camPosTimeline->setToValue(VfxVector3f(0, camPushY, camPushZ));
                
                const VfxFloat angleX = VFX_DEG_TO_RAD(-30.0f / 2);
                const VfxQuaternionf rotX(VfxVector3f(vfxSin(angleX), 0, 0), vfxCos(angleX));
                const VfxFloat angleZ = VFX_DEG_TO_RAD(photo.m_degree / 2);
                const VfxQuaternionf rotZ(VfxVector3f(0, 0, vfxSin(angleZ)), vfxCos(angleZ));
                m_camRotTimeline->setToValue(rotZ * rotX);
            }
            
            // move camera in
            m_camTimeline->setFromValue(0.0f);
            m_camTimeline->setToValue(1.0f);
            m_camTimeline->start();
        }
        else
        {
            m_enlargeMedia = VFX_FALSE;
            showStateIcon(VfxImageSrc(VAPP_GALLERY_3D_SLIDESHOW_PLAY_OVERLAY));
            
            m_camTimeline->setFromValue(1.0f);
            m_camTimeline->setToValue(0.0f);
            m_camTimeline->start();
            // move media will be triggered by still timer checker.
        }
        break;
    case VG_DRAG:
        if(m_light)
        {
            const VfxPenEvent &event = sender->getLastPenEvent();
            const VfxS32 xOffset = (event.pos.x - event.prevPos.x);
            const VfxS32 yOffset = (event.pos.y - event.prevPos.y);
            VfxVector3f lightTranslation = m_light->getTranslation();
            const VfxFloat BOUNDS = 700;
            const VfxFloat SCREEN = (VfxFloat)GDI_LCD_HEIGHT;
            lightTranslation.x += xOffset * BOUNDS / SCREEN * 2;
            lightTranslation.y += yOffset * BOUNDS / SCREEN * 2;
            lightTranslation.x = vfxMin(BOUNDS, vfxMax(-BOUNDS, lightTranslation.x));
            lightTranslation.y = vfxMin(BOUNDS, vfxMax(-BOUNDS, lightTranslation.y));
            m_light->setTranslation(lightTranslation);
        }
        break;
    default:
        return VFX_FALSE;
    }
    
    return VFX_TRUE;
}

VfxBool VappGallerySceneSlideshow::canPlayMedia()
{
    return !m_enlargeMedia;
}

VfxBool VappGallerySceneSlideshow::PhotoInfo::isPortrait()const
{
    return m_mediaSize.width < m_mediaSize.height;
}

VappGallerySceneSlideshow::PhotoInfo::AspectRatioType VappGallerySceneSlideshow::PhotoInfo::getAspectRatioType() const
{
    // always make sure a >= b
    VfxFloat a = (VfxFloat)m_mediaSize.width;
    VfxFloat b = (VfxFloat)m_mediaSize.height;
    if(b > a)
    {
        vfxSwap(a, b);
    }

    const VfxFloat aspect = a / b;
    const AspectRatioType types[] = {ASPECT_3v2,
                                     ASPECT_4v3,
                                     ASPECT_5v3,
                                     ASPECT_16v9};
    const VfxFloat aspects[] = {3.f / 2.f,
                                4.f / 3.f,
                                5.f / 3.f,
                                16.f / 9.f};
    
    VfxS32 nearestIdx = -1;
    VfxFloat nearestAspect = 10000.f;    // can be any number that is guranteed to be larger than possible aspect differences.
    for(VfxS32 i = 0; i < sizeof(types) / sizeof(types[0]); ++i)
    {
        const VfxFloat diff = vfxAbs(aspect - aspects[i]);
        if(nearestAspect > diff)
        {
            nearestIdx = i;
            nearestAspect = diff;
        }
    }

    VFX_ASSERT(nearestIdx != -1);

    return types[nearestIdx];
}

VfxResId VappGallerySceneSlideshow::PhotoInfo::getSceneId() const
{
    if(!isPortrait())
    {
        const VfxResId sceneIds[] = {VAPP_GALLERY_3D_SLIDESHOW_PHOTO_H_32,
                                     VAPP_GALLERY_3D_SLIDESHOW_PHOTO_H_43,
                                     VAPP_GALLERY_3D_SLIDESHOW_PHOTO_H_53,
                                     VAPP_GALLERY_3D_SLIDESHOW_PHOTO_H_169};
        return sceneIds[getAspectRatioType()];
    }
    else
    {
        const VfxResId sceneIds[] = {VAPP_GALLERY_3D_SLIDESHOW_PHOTO_V_32,
                                     VAPP_GALLERY_3D_SLIDESHOW_PHOTO_V_43,
                                     VAPP_GALLERY_3D_SLIDESHOW_PHOTO_V_53,
                                     VAPP_GALLERY_3D_SLIDESHOW_PHOTO_V_169};
        return sceneIds[getAspectRatioType()];
    }
}

VfxResId VappGallerySceneSlideshow::PhotoInfo::getAnimationId() const
{

    if(!isPortrait())
    {
        const VfxResId animIds[] = {VAPP_GALLERY_3D_SLIDESHOW_PHOTO_H_32_ANIM,
                                    VAPP_GALLERY_3D_SLIDESHOW_PHOTO_H_43_ANIM,
                                    VAPP_GALLERY_3D_SLIDESHOW_PHOTO_H_53_ANIM,
                                    VAPP_GALLERY_3D_SLIDESHOW_PHOTO_H_169_ANIM};
        return animIds[getAspectRatioType()];
    }
    else
    {
        const VfxResId animIds[] = {VAPP_GALLERY_3D_SLIDESHOW_PHOTO_V_32_ANIM,
                                    VAPP_GALLERY_3D_SLIDESHOW_PHOTO_V_43_ANIM,
                                    VAPP_GALLERY_3D_SLIDESHOW_PHOTO_V_53_ANIM,
                                    VAPP_GALLERY_3D_SLIDESHOW_PHOTO_V_169_ANIM};
        return animIds[getAspectRatioType()];
    }
}

void VappGallerySceneSlideshow::PhotoInfo::getNodeName(VfxString &name) const
{
    // create names like "Box-Photo-V-32-node" or "Box-Photo-H-169-node"
    const char orientation = isPortrait() ? 'V' : 'H';
    const char *ratio = NULL;
    switch(getAspectRatioType())
    {
    case ASPECT_3v2:
        ratio = "32";
        break;
    case ASPECT_4v3:
        ratio = "43";
        break;
    case ASPECT_5v3:
        ratio = "53";
        break;
    case ASPECT_16v9:
    default:
        ratio = "169";
        break;
    }
    name.format("Box-Photo-%c-%s-node", orientation, ratio);
}

void VappGallerySceneSlideshow::PhotoInfo::getTextureSize(VfxSize &size) const
{
    const VfxS32 PHOTO_WIDTH = GDI_LCD_WIDTH * 2 / 3;
    const VfxS32 PHOTO_HEIGHT = GDI_LCD_HEIGHT * 2 / 3;
    switch(getAspectRatioType())
    {
    case ASPECT_3v2:
        size.width = PHOTO_WIDTH / 2 * 3;
        size.height = PHOTO_WIDTH;
        break;
    case ASPECT_4v3:
        size.width = PHOTO_WIDTH / 3 * 4;
        size.height = PHOTO_WIDTH;
        break;
    case ASPECT_5v3:
        size.width = PHOTO_WIDTH / 3 * 5;
        size.height = PHOTO_WIDTH;
        break;
    case ASPECT_16v9:
        size.width = PHOTO_HEIGHT;
        size.height = PHOTO_HEIGHT / 16 * 9;
        break;
    }
    
    if(isPortrait())
    {
        vfxSwap(size.width, size.height);
    }
}

#endif // defined(__MMI_FTO_GALLERY__) && defined(__COSMOS_3D_V10__)
#endif
