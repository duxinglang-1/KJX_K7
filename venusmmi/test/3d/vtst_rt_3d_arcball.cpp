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
 *  vtst_rt_arcball.cpp
 *
 * Project:
 * --------
 *  Arc ball to view mesh
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/

#include "vfx_config.h"

#ifdef __AFX_RT_TEST__

#include "vtst_rt_main.h"

#ifdef __VENUS_3D_UI_ENGINE__

#include "vfx_control.h"
#include "vfx_node.h"
#include "vfx_material.h"
#include "vfx_world.h"
#include "vfx_camera.h"
#include "vfx_mesh.h"
#include "vfx_asset_loader.h"
#include "vfx_context.h"
#include "vapp_platform_context.h" 
#include "vcp_button.h"
#include "vcp_segment_button.h"
#include "vcp_slider.h"
extern "C"
{
#include "FileMgrSrvGprot.h"
#include "fs_type.h"
#include "fs_func.h"
}

#ifdef __COSMOS_MMI_PACKAGE__
extern "C"
{
#include "vapp_fmgr_cui_gprot.h"
}
#define cui_file_selector_create vcui_file_selector_create
#define CUI_FILE_SELECTOR_STYLE_FILE_ONLY VCUI_FILE_SELECTOR_STYLE_FILE_ONLY
#define CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL VCUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL
#define cui_file_selector_run vcui_file_selector_run
#define EVT_ID_CUI_FILE_SELECTOR_RESULT EVT_ID_VCUI_FILE_SELECTOR_RESULT
#define cui_file_selector_result_event_struct vcui_file_selector_result_event_struct
#define cui_file_selector_get_selected_filepath vcui_file_selector_get_selected_filepath
#define cui_file_selector_close vcui_file_selector_close
#else
extern "C"
{
#include "FileMgrCuiGprot.h"
}
#endif


class VtstRtArcBall : public VfxControl
{
    VFX_DECLARE_CLASS(VtstRtArcBall);
    
public:
    enum OperationModeEnum
    {
        OP_MODE_ROTATE,
        OP_MODE_MOVE_FORWARD,
        OP_MODE_MOVE_FRONT_FORWARD,
        OP_MODE_MOVE_ON_PLANE,

        OP_MODE_END_OF_ENUM
    };

private:

    struct CameraParameter
    {
        VfxFloat fovy;
        VfxVector3f normUp;
        VfxVector3f target;
        VfxVector3f pos;
    };

    VfxWeakPtr<VfxNode> m_node;
    OperationModeEnum m_opMode;
    CameraParameter m_activeCameraParam;
    VfxWeakPtr<VfxCamera> m_virtualCamera;
    VfxWeakPtr<VfxCamera> m_oriSceneCamera;
    VfxWeakPtr<VfxAnimation> m_animation;

    inline VfxFloat getCameraFovy()
    {
        return m_activeCameraParam.fovy;
    }

    inline const VfxVector3f &getNormCameraUp()
    {
        return m_activeCameraParam.normUp;
    }

    inline const VfxVector3f &getCameraTarget()
    {
        return m_activeCameraParam.target;
    }

    static inline VfxFloat getPositionOperFactor(const VfxS32 maxUnitInOneOper)
    {
        return (0.75f / static_cast<VfxFloat>(maxUnitInOneOper));
    }

    template <class T>
    static inline T square(const T& val)
    {
        return (val * val);
    }

    static inline VfxFloat adjustMoveDist(VfxFloat v)
    {
        if (vfxAbs(v) < 1.0f)
        {
            return (v < 0.0f) ? -1.0f : 1.0f;
        }
        return v;
    }
    

    void setActiveCameraToDefault(VfxCamera *camera);
    void applyCameraParamToActive(VfxCamera *camera, const CameraParameter& param);

    void getCameraParameters(
        const VfxCamera *camera,
        CameraParameter &outParam);

    void rotate(
        VfxNode *node,
        const VfxQuaternionf &oriRotation,
        const VfxVector3f &rotateDirVector,
        const VfxVector3f &cameraTarget,
        VfxFloat theta);

    void moveForward(
        VfxNode *node,
        const VfxVector3f &oriTranslation,
        VfxFloat unit);

    void moveFrontForward(
        VfxNode *node,
        const VfxVector3f &oriTranslation,
        const VfxVector3f &cameraTarget,
        VfxFloat unit);
    
    void moveOnPlane(
        VfxNode *node,
        const VfxVector3f &oriTranslation,
        const VfxVector3f &normCameraUp,
        const VfxVector3f &cameraTarget,
        VfxFloat up,
        VfxFloat right);

    void convertToViewPortVector(
        const VfxVector3f &normCameraUp,
        const VfxVector3f &cameraTarget,
        const VfxPoint &in_framePos,
        VfxVector3f *out_viewPortPos);

    VfxFloat getDistanceToCamera(const VfxNode *node);
    virtual VfxBool onPenInput(VfxPenEvent &penEvt);
    
    VfxQuaternionf m_nodeOriRotation;
    void processRotate(VfxPenEvent &penEvt);

    VfxVector3f m_nodeOriTranslation;
    VfxFloat m_nodeOriDist;
    VfxFloat m_nodeOriProjLenOnCameraView;

    void processMoveForward(VfxPenEvent &penEvt);
    void processMoveFrontForward(VfxPenEvent &penEvt);

    VfxFloat VtstRtArcBall::getProjLenOnCameraView(
        const VfxNode *node,
        const VfxVector3f& cameraTarget);

    VfxFloat m_tanCameraFovy_2;
    void processMoveOnPlane(VfxPenEvent &penEvt);

    const VfxCamera *findCamera(const VfxGroup *group);

protected:

    virtual void onInit();

public:

    VtstRtArcBall():
        m_node(NULL),
        m_opMode(OP_MODE_ROTATE),
        m_tanCameraFovy_2(0.0f) // dynamically calculated
    {
    }

    void associateNode(VfxNode *node);
    void associateScene(VfxWorld *sceneWorld, VfxGroup *virtualGroup);
    void associateScene(VfxGroup *sceneGroup);

    VfxNode *getAssociatedNode()
    {
        return m_node.get();
    }

    void setOperationMode(OperationModeEnum mode)
    {
        m_opMode = mode;
    }

    void setAnimationToNode(VfxAnimation *ani);

    VfxAnimation *getAnimation()
    {
        return m_animation.get();
    }
    
    void startAnimation();
    void stopAnimation();
};


VFX_IMPLEMENT_CLASS("VtstRtArcBall", VtstRtArcBall, VfxControl);


void VtstRtArcBall::onInit()
{
    VfxControl::onInit();

    setBgColor(VFX_COLOR_BLUE);
}


void VtstRtArcBall::associateNode(VfxNode *node)
{
    VfxWorld *world = getWorld();

    if (world == NULL)
    {
        VFX_OBJ_CREATE(world, VfxWorld, this);

        VFX_OBJ_CREATE(m_virtualCamera, VfxCamera, world);
        // We should pass the camera to setActiveCameraToDefault()
        // because we don't set world yet to imply the "active" camera
        // We can not set world first then bind the camera, otherwise
        // nothing can be seen.
        setActiveCameraToDefault(m_virtualCamera.get());
        world->setActiveCamera(m_virtualCamera.get());

        world->addChildNode(node);
        m_node = node;

        setWorld(world);
    }
    else if (m_node.get() != node)
    {
        if (!m_virtualCamera.isValid())
        {
            VFX_OBJ_CREATE(m_virtualCamera, VfxCamera, world);
        }
        setActiveCameraToDefault(m_virtualCamera.get());
        world->setActiveCamera(m_virtualCamera.get());

        if (m_node.isValid())
        {
            world->removeChildNode(m_node.get());
        }

        world->addChildNode(node);
        m_node = node;
    }

    m_oriSceneCamera = NULL;
    m_animation = NULL;
}


void VtstRtArcBall::setActiveCameraToDefault(VfxCamera *camera)
{
    m_activeCameraParam.fovy = (VFX_PI / 2.0);
    m_activeCameraParam.normUp = VfxVector3f(0.0, 1.0, 0.0);
    m_activeCameraParam.target = VfxVector3f(0.0, 0.0, 0.0);
    m_activeCameraParam.pos = VfxVector3f(0.0, 0.0, 60.0);

    applyCameraParamToActive(camera, m_activeCameraParam);
}


void VtstRtArcBall::applyCameraParamToActive(
    VfxCamera *camera,
    const CameraParameter& param)
{
    if (&param != &m_activeCameraParam)
    {
        m_activeCameraParam = param;
    }

    VfxSize frameSize = getSize();
    camera->setPerspective(
        m_activeCameraParam.fovy,
        static_cast<VfxFloat>(frameSize.width) / static_cast<VfxFloat>(frameSize.height),
        1.0,
        1000.0);
    camera->setLookAt(
        m_activeCameraParam.pos,
        m_activeCameraParam.target,
        m_activeCameraParam.normUp);
}


void VtstRtArcBall::getCameraParameters(
    const VfxCamera *camera,
    CameraParameter &outParam)
{
    const VfxMatrix4f &cameraProj = camera->getProjectionMatrix();
    outParam.fovy = vrt_atan(1.0f / cameraProj[1][1]) * 2.0f;

    VfxMatrix4f cameraTrans;
    camera->getWorldTransform(cameraTrans);
    outParam.normUp = normalize(cameraTrans[1].xyz());
    outParam.pos = cameraTrans[3].xyz();
    outParam.target = outParam.pos - cameraTrans[2].xyz();
}


void VtstRtArcBall::associateScene(VfxWorld *sceneWorld, VfxGroup *virtualGroup)
{
    VfxSize frameSize = getSize();

    VfxCamera *oriSceneCamera = sceneWorld->getActiveCamera();
    CameraParameter cameraParam;
    getCameraParameters(oriSceneCamera, cameraParam);
    // Correct the perspective by frame size
    oriSceneCamera->setPerspective(
        cameraParam.fovy,
        static_cast<VfxFloat>(frameSize.width) / static_cast<VfxFloat>(frameSize.height),
        1.0,
        1000.0);
    
    // Move children of sceneWorld to virtualGroup
    // NOTE: Because VfxAssetLoader::loadScene() stores something for animation.
    // So after we replaced the root, we can not load animation anymore.
    const VfxGroup::NodeList sceneChildren(this, sceneWorld->getChildren());
    sceneWorld->removeAllChildNodes();
    for (VfxGroup::NodeList::ConstIt iter = sceneChildren.begin(); iter != sceneChildren.end(); iter++)
    {
        if (iter->isValid())
        {
            virtualGroup->addChildNode(iter->get());
        }
    }

    associateNode(virtualGroup);
    m_oriSceneCamera = oriSceneCamera;
    
    VfxCamera *worldCamera = getWorld()->getActiveCamera();
    applyCameraParamToActive(worldCamera, cameraParam);
    
    // useless but ony for debug
    VfxMatrix4f worldCameraTrans;
    worldCamera->getWorldTransform(worldCameraTrans);
}


const VfxCamera *VtstRtArcBall::findCamera(const VfxGroup *group)
{
    const VfxCamera *camera = NULL;

    const VfxGroup::NodeList& children = group->getChildren();
    for (VfxGroup::NodeList::ConstIt iter = children.begin(); iter != children.end(); iter++)
    {
        const VfxNode *node = iter->get();

        if (node->isKindOf(VFX_OBJ_CLASS_INFO(VfxCamera)))
        {
            return static_cast<const VfxCamera*>(node);
        }
        
        if (node->isKindOf(VFX_OBJ_CLASS_INFO(VfxGroup)))
        {
            camera = findCamera(static_cast<const VfxGroup*>(node));
            if (camera != NULL)
            {
                return camera;
            }
        }
    }

    return camera;
}


void VtstRtArcBall::associateScene(VfxGroup *sceneGroup)
{
    VfxSize frameSize = getSize();

    VfxCamera *oriSceneCamera = const_cast<VfxCamera*>(findCamera(sceneGroup));
    if (oriSceneCamera == NULL)
    {
        //return;
        VFX_OBJ_CREATE(oriSceneCamera, VfxCamera, sceneGroup);
        oriSceneCamera->setPerspective(
            VRT_PI_2,
            (vrt_float)frameSize.width / (vrt_float)frameSize.height,
            1.0f, 1000.0f);
        oriSceneCamera->setLookAt(VrtVector3f(0, 0, 100), VrtVector3f(0, 0, 0), VrtVector3f(0, 1, 0));
    }

    CameraParameter cameraParam;
    getCameraParameters(oriSceneCamera, cameraParam);
    // Correct the perspective by frame size
    oriSceneCamera->setPerspective(
        cameraParam.fovy,
        static_cast<VfxFloat>(frameSize.width) / static_cast<VfxFloat>(frameSize.height),
        1.0,
        1000.0);

    associateNode(sceneGroup);
    m_oriSceneCamera = oriSceneCamera;
    
    VfxCamera *worldCamera = getWorld()->getActiveCamera();
    applyCameraParamToActive(worldCamera, cameraParam);
    
    // useless but ony for debug
    VfxMatrix4f worldCameraTrans;
    worldCamera->getWorldTransform(worldCameraTrans);
}


void VtstRtArcBall::setAnimationToNode(VfxAnimation *ani)
{
    // restore camera
    if (m_oriSceneCamera.isValid())
    {
        getWorld()->setActiveCamera(m_oriSceneCamera.get());
    }
    m_animation = ani;
}


void VtstRtArcBall::startAnimation()
{
    VFX_ASSERT(m_animation.isValid());
    m_animation->start();
}


void VtstRtArcBall::stopAnimation()
{
    if (m_animation.isValid())
    {
        m_animation->stop();
    }
}


void VtstRtArcBall::rotate(
    VfxNode *node,
    const VfxQuaternionf &oriRotation,
    const VfxVector3f &rotateDirVector,
    const VfxVector3f &cameraTarget,
    VfxFloat theta)
{
    if (theta == 0.0f)
    {
        node->setRotation(oriRotation);
        return;
    }

    VfxWorld *world = getWorld();
    VfxCamera *camera = world->getActiveCamera();

    VfxVector3f cameraPos;
    camera->getWorldPosition(cameraPos);
    
    VfxVector3f rotatePlaneNormal =
        normalize(cross(cameraPos - cameraTarget, rotateDirVector));
    // Assume that the node is just under the world
    VfxMatrix4f worldToNodeTrans = inverse(convert(oriRotation));
    rotatePlaneNormal =
        (worldToNodeTrans * VfxVector4f(rotatePlaneNormal, 0)).xyz();
        
    VfxQuaternionf nodeRotation = VfxQuaternionf(
        rotatePlaneNormal * vfxSin(theta / 2.0f),
        vfxCos(theta / 2.0f));
        
    node->setRotation(oriRotation * nodeRotation);
}


void VtstRtArcBall::moveForward(
    VfxNode *node,
    const VfxVector3f &oriTranslation,
    VfxFloat unit)
{
    if (unit == 0.0)
    {
        node->setTranslation(oriTranslation);
        return;
    }

    VfxWorld *world = getWorld();
    VfxCamera *camera = world->getActiveCamera();
    VfxVector3f nodePosInWorld, cameraPosInWorld;
    node->getWorldPosition(nodePosInWorld);
    camera->getWorldPosition(cameraPosInWorld);
    
    VfxVector3f forwardUnitVectorInWorld;
    if (nodePosInWorld == cameraPosInWorld)
    {
        forwardUnitVectorInWorld = normalize(getCameraTarget() - cameraPosInWorld);
    }
    else
    {
        forwardUnitVectorInWorld = normalize(nodePosInWorld - cameraPosInWorld);
    }
        
    VfxVector3f forwardVectorInWorld = forwardUnitVectorInWorld * unit;

    // We assume node is just under world, otherwise we have to multiply
    // forwardVectorInWorld by the inverse of world transform matrix
    node->setTranslation(oriTranslation + forwardVectorInWorld);
}


void VtstRtArcBall::moveFrontForward(
    VfxNode *node,
    const VfxVector3f &oriTranslation,
    const VfxVector3f &cameraTarget,
    VfxFloat unit)
{
    if (unit == 0.0)
    {
        node->setTranslation(oriTranslation);
        return;
    }

    VfxWorld *world = getWorld();
    VfxCamera *camera = world->getActiveCamera();
    VfxVector3f cameraPosInWorld;
    camera->getWorldPosition(cameraPosInWorld);
    
    VfxVector3f forwardUnitVectorInWorld;
    forwardUnitVectorInWorld = normalize(cameraTarget - cameraPosInWorld);
        
    VfxVector3f forwardVectorInWorld = forwardUnitVectorInWorld * unit;

    // We assume node is just under world, otherwise we have to multiply
    // forwardVectorInWorld by the inverse of world transform matrix
    node->setTranslation(oriTranslation + forwardVectorInWorld);
}


void VtstRtArcBall::moveOnPlane(
    VfxNode *node,
    const VfxVector3f &oriTranslation,
    const VfxVector3f &normCameraUp,
    const VfxVector3f &cameraTarget,
    VfxFloat up,
    VfxFloat right)
{
    if (up == 0.0f && right == 0.0f)
    {
        node->setTranslation(oriTranslation);
        return;
    }

    VfxCamera *camera = getWorld()->getActiveCamera();
    VfxVector3f cameraPosInWorld;
    camera->getWorldPosition(cameraPosInWorld);
    VfxVector3f targetToCamera = cameraPosInWorld - cameraTarget;

    VfxVector3f cameraHoriBasis =
        normalize(cross(normCameraUp, targetToCamera));

    VfxVector3f transInWorld =
        (normCameraUp * up + cameraHoriBasis * right);

    // We assume node is just under world, otherwise we have to multiply
    // transInWorld by the inverse of world transform matrix
    node->setTranslation(oriTranslation + transInWorld);
}


void VtstRtArcBall::convertToViewPortVector(
    const VfxVector3f &normCameraUp,
    const VfxVector3f &cameraTarget,
    const VfxPoint & in_framePos,
    VfxVector3f *out_viewPortPos)
{
    VfxCamera *camera = getWorld()->getActiveCamera();
    
    VfxVector3f viewPlaneNormal;
    camera->getWorldPosition(viewPlaneNormal);
    viewPlaneNormal = viewPlaneNormal - cameraTarget;

    VfxSize frameSize = getSize();
    
    VfxFloat x_onTargetPlane = static_cast<VfxFloat>(in_framePos.x - (frameSize.width / 2));
    VfxFloat y_onTargetPlane = -(static_cast<VfxFloat>(in_framePos.y - (frameSize.height / 2)));

    *out_viewPortPos = (normCameraUp * y_onTargetPlane);
    VfxVector3f cameraHoriBasis = normalize(cross(normCameraUp, viewPlaneNormal));
    *out_viewPortPos = *out_viewPortPos + (cameraHoriBasis * x_onTargetPlane);
}


VfxBool VtstRtArcBall::onPenInput(VfxPenEvent &penEvt)
{
    if (m_node.isValid())
    {
        switch (m_opMode)
        {
            case OP_MODE_ROTATE:
                processRotate(penEvt);
                break;

            case OP_MODE_MOVE_FORWARD:
                processMoveForward(penEvt);
                break;

            case OP_MODE_MOVE_FRONT_FORWARD:
                processMoveFrontForward(penEvt);
                break;

            case OP_MODE_MOVE_ON_PLANE:
                processMoveOnPlane(penEvt);
                break;
        }

        return VFX_TRUE;
    }

    return VFX_FALSE;
}


void VtstRtArcBall::processRotate(VfxPenEvent &penEvt)
{
    VfxPoint downPos = penEvt.getRelDownPos(this);
    VfxPoint currPos = penEvt.getRelPos(this);

    switch (penEvt.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            m_nodeOriRotation = m_node->getRotation();
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
        case VFX_PEN_EVENT_TYPE_UP:
        {
            VfxVector3f viewPlaneSrcPos, viewPlaneDestPos;

            // TODO: elimiate duplicated calculation to speed up
            convertToViewPortVector(
                getNormCameraUp(), getCameraTarget(), downPos, &viewPlaneSrcPos);
            convertToViewPortVector(
                getNormCameraUp(), getCameraTarget(), currPos, &viewPlaneDestPos);

            VfxSize frameSize = getSize();
            VfxFloat piDistance = static_cast<VfxFloat>(vfxMin(frameSize.width, frameSize.height));
            VfxFloat downToCurrDistance =
                vfxSqrt(static_cast<VfxFloat>(
                    square(currPos.x - downPos.x) + square(currPos.y - downPos.y)));
            VfxFloat theta = VFX_PI * (downToCurrDistance / piDistance);

            rotate(
                m_node.get(),
                m_nodeOriRotation,
                viewPlaneDestPos - viewPlaneSrcPos,
                getCameraTarget(),
                theta);
                
            break;
        }
    }
}


VfxFloat VtstRtArcBall::getDistanceToCamera(const VfxNode *node)
{
    VfxCamera *camera = getWorld()->getActiveCamera();
    
    VfxVector3f nodeInWorld, cameraInWorld;
    node->getWorldPosition(nodeInWorld);
    camera->getWorldPosition(cameraInWorld);

    return length(cameraInWorld - nodeInWorld);
}


VfxFloat VtstRtArcBall::getProjLenOnCameraView(
    const VfxNode *node,
    const VfxVector3f& cameraTarget)
{
    VfxCamera *camera = getWorld()->getActiveCamera();
    
    VfxVector3f nodeInWorld, cameraInWorld;
    node->getWorldPosition(nodeInWorld);
    camera->getWorldPosition(cameraInWorld);
    
    VfxVector3f cameraView = cameraTarget - cameraInWorld;
    VfxVector3f cameraToNode = nodeInWorld - cameraInWorld;
    
    VfxVector3f projOnView =
        cameraView *
        (dot(cameraView, cameraToNode) / dot(cameraView, cameraView));

    return length(projOnView);
}


void VtstRtArcBall::processMoveForward(VfxPenEvent &penEvt)
{
    VfxPoint downPos = penEvt.getRelDownPos(this);
    VfxPoint currPos = penEvt.getRelPos(this);

    switch (penEvt.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            m_nodeOriTranslation = m_node->getTranslation();
            m_nodeOriDist = getDistanceToCamera(m_node.get());
            break;
    
        case VFX_PEN_EVENT_TYPE_MOVE:
        case VFX_PEN_EVENT_TYPE_UP:
        {
            VfxSize frameSize = getSize();
            VfxFloat opFactor = getPositionOperFactor(frameSize.height);

            VfxS32 unitOnFrame = downPos.y - currPos.y;
            VfxFloat unitToMoveInWorld = adjustMoveDist(m_nodeOriDist) * opFactor * unitOnFrame;
            moveForward(m_node.get(), m_nodeOriTranslation, unitToMoveInWorld);

            break;
        }
    }
}


void VtstRtArcBall::processMoveFrontForward(VfxPenEvent &penEvt)
{
    VfxPoint downPos = penEvt.getRelDownPos(this);
    VfxPoint currPos = penEvt.getRelPos(this);

    switch (penEvt.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
            m_nodeOriTranslation = m_node->getTranslation();
            m_nodeOriProjLenOnCameraView = getProjLenOnCameraView(m_node.get(), getCameraTarget());
            break;
    
        case VFX_PEN_EVENT_TYPE_MOVE:
        case VFX_PEN_EVENT_TYPE_UP:
        {
            VfxSize frameSize = getSize();
            VfxFloat opFactor = getPositionOperFactor(frameSize.height);

            VfxS32 unitOnFrame = downPos.y - currPos.y;
            VfxFloat unitToMoveInWorld =
                adjustMoveDist(m_nodeOriProjLenOnCameraView) * opFactor * unitOnFrame;
            moveFrontForward(
                m_node.get(),
                m_nodeOriTranslation,
                getCameraTarget(),
                unitToMoveInWorld);

            break;
        }
    }
}


void VtstRtArcBall::processMoveOnPlane(VfxPenEvent &penEvt)
{
    VfxPoint downPos = penEvt.getRelDownPos(this);
    VfxPoint currPos = penEvt.getRelPos(this);

    switch (penEvt.type)
    {
        case VFX_PEN_EVENT_TYPE_DOWN:
        {
            m_nodeOriTranslation = m_node->getTranslation();
            m_nodeOriProjLenOnCameraView = getProjLenOnCameraView(m_node.get(), getCameraTarget());
            VfxFloat cameraFovy = getCameraFovy();
            m_tanCameraFovy_2 = vfxSin(cameraFovy / 2.0f) / vfxCos(cameraFovy / 2.0f);
            break;
        }
    
        case VFX_PEN_EVENT_TYPE_MOVE:
        case VFX_PEN_EVENT_TYPE_UP:
        {
            VfxSize frameSize = getSize();

            VfxFloat upRatio =
                -(static_cast<VfxFloat>(currPos.y - downPos.y) / static_cast<VfxFloat>(frameSize.height));
            VfxFloat rightRatio =
                static_cast<VfxFloat>(currPos.x - downPos.x) / static_cast<VfxFloat>(frameSize.width);
            VfxFloat aspectRatio =
                static_cast<VfxFloat>(frameSize.width) / static_cast<VfxFloat>(frameSize.height);

            VfxFloat planeWidth = m_tanCameraFovy_2 * m_nodeOriProjLenOnCameraView * 2.0f;
            if (planeWidth < 1.0f)
            {
                planeWidth = 1.0f;
            }
            moveOnPlane(
                m_node.get(),
                m_nodeOriTranslation,
                getNormCameraUp(),
                getCameraTarget(),
                planeWidth * upRatio,
                planeWidth * rightRatio * aspectRatio);

            break;
        }
    }
}


// VtstRtScr will not enter history, so we have to create our own app
class VtstRtArcBallApp : public VfxApp
{
    VFX_DECLARE_CLASS(VtstRtArcBallApp);

private:
    enum LoadTypeEnum
    {
        LOAD_NONE = 0,
        LOAD_MESH,
        LOAD_MATERIAL,
        LOAD_SCENE,
        LOAD_ANIMATION,

        LOAD_END_OF_ENUM
    };

    enum LayoutConfig
    {
#if defined(__MMI_MAINLCD_480X800__)
        LAYOUT_MARGIN = 10,
        LAYOUT_BUTTON_WIDTH = 120,
        LAYOUT_BUTTON_HEIGHT = 80,
        LAYOUT_SLIDER_HEIGHT = 60,
#else
        LAYOUT_MARGIN = 5,
        LAYOUT_BUTTON_WIDTH = 60,
        LAYOUT_BUTTON_HEIGHT = 40,
        LAYOUT_SLIDER_HEIGHT = 30,
#endif

        LAYOUT_END_OF_ENUM
    };

    WCHAR *m_prevCurrDir;
    void storeCurrDir();
    void setCurrDir(const WCHAR *filepath);
    
    VfxAppScr *m_appScr;
    VtstRtArcBall *m_arcBall;
    VcpButton *m_loadMeshButton;
    VcpSegmentButton *m_optButton;
    VcpSegmentButton *m_loadMaterialButton;
    VcpButton *m_aniPlayButton, *m_aniStopButton;
    VcpSlider *m_aniSlider;
    VfxWeakPtr<VfxFloatTimeline> m_aniSeekTimeline;
    VfxS32 m_matIndexToLoad;
    VfxS32 m_matButtonNum;
    MMI_ID m_file_sel_cui;
    LoadTypeEnum m_loadType;

    VfxWeakPtr<VfxNode> m_createdNodes[3];
    VfxS32 m_createdNodesTop;
    
    void pushNewlyCreatedNode(VfxNode *node)
    {
        m_createdNodes[m_createdNodesTop++] = node;
    }

    void closeAllCreatedNodes();
    
    void onLoadClicked(VfxObject *obj, VfxId id);
    void onLoadMaterialClicked(VfxObject *obj, VfxId id);
    void openFileSelector();
    static mmi_ret onFileSelected(mmi_event_struct *evt);
    void loadMesh(const WCHAR* filepath);
    void loadMaterial(const WCHAR* filepath);
    void loadScene(const WCHAR* filepath);
    void loadAnimation(const WCHAR* filepath);
    void onOptSelected(VfxObject *obj, VfxId id);
    void onAniStopClicked(VfxObject *obj, VfxId id);
    void onAniPlayClicked(VfxObject *obj, VfxId id);
    void onAniSliderChanged(VfxObject *obj, VfxFloat oldValue, VfxFloat newValue);
    static VfxBool getBaseDir(
        const WCHAR *filepath,
        WCHAR *out_base_dir,
        VfxS32 len_out_base_dir);

protected:
    virtual void onInit();
    virtual void onDeinit();
    virtual void onRun(void* args, VfxU32 argSize);

public:
    VtstRtArcBallApp() :
        m_appScr(NULL),
        m_arcBall(NULL),
        m_loadMeshButton(NULL),
        m_loadMaterialButton(NULL),
        m_matIndexToLoad(0),
        m_prevCurrDir(NULL),
        m_loadType(LOAD_NONE),
        m_createdNodesTop(0)
    {
    }
    
    virtual VfxS32 start()
    {
        return 1;
    }

    virtual VfxS32 phase(VfxS32 idx);
};


VFX_IMPLEMENT_CLASS("VtstRtArcBallApp", VtstRtArcBallApp, VfxApp);


VfxS32 VtstRtArcBallApp::phase(VfxS32 idx)
{
    return (idx == 0 ? VTST_RT_TESTCASE_NEEDCONFIRM : 0);
}


void VtstRtArcBallApp::onInit()
{
    VfxApp::onInit();

    VFX_OBJ_CREATE(m_appScr, VfxAppScr, this);
    m_appScr->setSize(GDI_LCD_WIDTH, GDI_LCD_HEIGHT);
    m_appScr->setBgColor(VFX_COLOR_BLACK);

    VfxS32 layoutY = LAYOUT_MARGIN;
    VfxSize scrSize = m_appScr->getSize();

    VfxS32 layoutX = LAYOUT_MARGIN;
    VFX_OBJ_CREATE(m_loadMeshButton, VcpButton, m_appScr);
    m_loadMeshButton->setPos(layoutX, layoutY);
    m_loadMeshButton->setSize(LAYOUT_BUTTON_WIDTH, LAYOUT_BUTTON_HEIGHT);
    m_loadMeshButton->setText(VFX_WSTR("Load"));
    m_loadMeshButton->m_signalClicked.connect(this, &VtstRtArcBallApp::onLoadClicked);
    layoutX += LAYOUT_BUTTON_WIDTH + LAYOUT_MARGIN;
    VFX_OBJ_CREATE(m_loadMaterialButton, VcpSegmentButton, m_appScr);
    m_loadMaterialButton->setPos(layoutX, layoutY);
    m_loadMaterialButton->setSize(scrSize.width - layoutX - LAYOUT_MARGIN * 2, LAYOUT_BUTTON_HEIGHT);
    m_loadMaterialButton->setType(VCP_SEGMENT_BUTTON_TYPE_GROUP);
    m_loadMaterialButton->setStyle(VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
    m_loadMaterialButton->addButton(0, VcpStateImage(0, 0, 0, 0), VFX_WSTR("0"));
    m_matButtonNum = 1;
    m_loadMaterialButton->setButtonIsHighlighted(0, VFX_FALSE);
    m_loadMaterialButton->setIsDisabled(VFX_TRUE);
    m_loadMaterialButton->m_signalButtonClicked.connect(this, &VtstRtArcBallApp::onLoadMaterialClicked);
    layoutY += LAYOUT_BUTTON_HEIGHT;

    layoutY += LAYOUT_MARGIN;

    // Operation mode segment button
    VFX_OBJ_CREATE(m_optButton, VcpSegmentButton, m_appScr);
    m_optButton->setPos(LAYOUT_MARGIN, layoutY);
    m_optButton->setSize(scrSize.width - LAYOUT_MARGIN * 2, LAYOUT_BUTTON_HEIGHT);
    m_optButton->setType(VCP_SEGMENT_BUTTON_TYPE_RADIO);
    m_optButton->setStyle(VCP_SEGMENT_BUTTON_STYLE_TEXT_ONLY);
    m_optButton->addButton(
        VtstRtArcBall::OP_MODE_ROTATE,
        VcpStateImage(0, 0, 0, 0),
        VFX_WSTR("Rotate"));
    m_optButton->addButton(
        VtstRtArcBall::OP_MODE_MOVE_FORWARD,
        VcpStateImage(0, 0, 0, 0),
        VFX_WSTR("Dist"));
    m_optButton->addButton(
        VtstRtArcBall::OP_MODE_MOVE_FRONT_FORWARD,
        VcpStateImage(0, 0, 0, 0),
        VFX_WSTR("F-Zoom"));
    m_optButton->addButton(
        VtstRtArcBall::OP_MODE_MOVE_ON_PLANE,
        VcpStateImage(0, 0, 0, 0),
        VFX_WSTR("Move"));
    m_optButton->setButtonIsHighlighted(VtstRtArcBall::OP_MODE_ROTATE, VFX_TRUE);
    m_optButton->m_signalButtonClicked.connect(this, &VtstRtArcBallApp::onOptSelected);
    // Animation control buttons
    layoutX = LAYOUT_MARGIN;
    VFX_OBJ_CREATE(m_aniStopButton, VcpButton, m_appScr);
    m_aniStopButton->setText(VFX_WSTR("Stop"));
    m_aniStopButton->setPos(layoutX, layoutY);
    m_aniStopButton->setSize(LAYOUT_BUTTON_WIDTH, LAYOUT_BUTTON_HEIGHT);
    m_aniStopButton->m_signalClicked.connect(this, &VtstRtArcBallApp::onAniStopClicked);
    layoutX += LAYOUT_BUTTON_WIDTH + LAYOUT_MARGIN;
    VFX_OBJ_CREATE(m_aniPlayButton, VcpButton, m_appScr);
    m_aniPlayButton->setText(VFX_WSTR("Play"));
    m_aniPlayButton->setPos(layoutX, layoutY);
    m_aniPlayButton->setSize(LAYOUT_BUTTON_WIDTH, LAYOUT_BUTTON_HEIGHT);
    m_aniPlayButton->m_signalClicked.connect(this, &VtstRtArcBallApp::onAniPlayClicked);
    // Visible only if animation is loaded
    m_aniPlayButton->setHidden(VFX_TRUE);
    m_aniStopButton->setHidden(VFX_TRUE);
    layoutY += LAYOUT_BUTTON_HEIGHT;

    layoutY += LAYOUT_MARGIN;

    VFX_OBJ_CREATE(m_arcBall, VtstRtArcBall, m_appScr);
    m_arcBall->setPos(0, layoutY);
    m_arcBall->setSize(scrSize.width, scrSize.height - layoutY);
    m_arcBall->setOperationMode(VtstRtArcBall::OP_MODE_ROTATE);

    VFX_OBJ_CREATE(m_aniSlider, VcpSlider, m_appScr);
    m_aniSlider->setPos(LAYOUT_MARGIN, scrSize.height - LAYOUT_SLIDER_HEIGHT);
    m_aniSlider->setSize(scrSize.width - 2 * LAYOUT_MARGIN, LAYOUT_SLIDER_HEIGHT);
    m_aniSlider->setMinValue(0.0f);
    m_aniSlider->setMaxValue(1.0f);
    m_aniSlider->setCurrentValue(0.0f);
    m_aniSlider->setOpacity(0.5f);
    m_aniSlider->m_signalUserChangedValue.connect(this, &VtstRtArcBallApp::onAniSliderChanged);
    m_aniSlider->setHidden(VFX_TRUE);
}


void VtstRtArcBallApp::onDeinit()
{
    // Restore previous CurrentDir
    if (m_prevCurrDir != NULL)
    {
        FS_SetCurrentDir(m_prevCurrDir);
        VFX_FREE_MEM(m_prevCurrDir);
    }
}


void VtstRtArcBallApp::onRun(void* args, VfxU32 argSize)
{
    m_appScr->show();
}


void VtstRtArcBallApp::closeAllCreatedNodes()
{
    for (VfxS32 i = 0; i < m_createdNodesTop; i++)
    {
        VFX_OBJ_CLOSE(m_createdNodes[i]);
    }
    m_createdNodesTop = 0;
}


void VtstRtArcBallApp::openFileSelector()
{
    FMGR_FILTER filter;
    FMGR_FILTER_INIT(&filter);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_ALL);
    FMGR_FILTER_SET(&filter, FMGR_TYPE_FOLDER);

    m_file_sel_cui = cui_file_selector_create(
        getGroupId(),
        (WCHAR*)SRV_FMGR_PATH_ROOT,
        &filter,
        CUI_FILE_SELECTOR_STYLE_FILE_ONLY,
        CUI_FILE_SELECTOR_OPT_FOLDER_TRAVERSE_ALL);
    mmi_frm_group_set_caller_proc(m_file_sel_cui, &VtstRtArcBallApp::onFileSelected, this);
    if (m_file_sel_cui != GRP_ID_INVALID)
    {
        cui_file_selector_run(m_file_sel_cui);
    }
}


void VtstRtArcBallApp::onLoadClicked(VfxObject *obj, VfxId id)
{
    openFileSelector();
}


void VtstRtArcBallApp::onLoadMaterialClicked(VfxObject *obj, VfxId id)
{
    m_matIndexToLoad = static_cast<VfxS32>(id);
    m_loadType = LOAD_MATERIAL;
    openFileSelector();
}


void VtstRtArcBallApp::onOptSelected(VfxObject *obj, VfxId id)
{
    VFX_ASSERT(obj == m_optButton);

    m_arcBall->setOperationMode(static_cast<VtstRtArcBall::OperationModeEnum>(id));
}


void VtstRtArcBallApp::onAniStopClicked(VfxObject *obj, VfxId id)
{
    m_arcBall->stopAnimation();
    VfxAnimation *ani = m_arcBall->getAnimation();
    if (ani != NULL)
    {
        ani->setTimelineTime(NULL);
    }
    if (m_aniSeekTimeline.isValid())
    {
        VFX_OBJ_CLOSE(m_aniSeekTimeline);
    }

    m_aniStopButton->setIsDisabled(VFX_TRUE);
    m_aniPlayButton->setIsDisabled(VFX_FALSE);
    m_aniSlider->setHidden(VFX_FALSE);
}


void VtstRtArcBallApp::onAniPlayClicked(VfxObject *obj, VfxId id)
{
    VfxAnimation *ani = m_arcBall->getAnimation();
    if (ani != NULL)
    {
        m_aniStopButton->setIsDisabled(VFX_FALSE);
        m_aniPlayButton->setIsDisabled(VFX_TRUE);
        m_aniSlider->setHidden(VFX_TRUE);
        m_aniSlider->setCurrentValue(0.0f);

        // Remove timeline time
        ani->setTimelineTime(NULL);
        if (m_aniSeekTimeline.isValid())
        {
            VFX_OBJ_CLOSE(m_aniSeekTimeline);
        }
        
        m_arcBall->startAnimation();
    }
}


void VtstRtArcBallApp::onAniSliderChanged(VfxObject *obj, VfxFloat oldValue, VfxFloat newValue)
{
    VfxAnimation *ani = m_arcBall->getAnimation();
    if (ani != NULL)
    {
        if (!m_aniSeekTimeline.isValid())
        {
            VfxNode *node = m_arcBall->getAssociatedNode();
            VFX_OBJ_CREATE(m_aniSeekTimeline, VfxFloatTimeline, node);
            m_aniSeekTimeline->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
            m_aniSeekTimeline->setTarget(node);
            m_aniSeekTimeline->setDuration(1000);
            m_aniSeekTimeline->setAutoReversed(VFX_TRUE);
            ani->setTimelineTime(m_aniSeekTimeline.get());
        }
        m_aniSeekTimeline->stop();
        m_aniSeekTimeline->setFromValue(newValue);
        m_aniSeekTimeline->setToValue(newValue);
        m_aniSeekTimeline->start();
    }
}


mmi_ret VtstRtArcBallApp::onFileSelected(mmi_event_struct *evt)
{
    VtstRtArcBallApp *inst = static_cast<VtstRtArcBallApp*>(evt->user_data);
    LoadTypeEnum loadType = inst->m_loadType;

    if (evt->evt_id != EVT_ID_CUI_FILE_SELECTOR_RESULT)
    {
        return MMI_RET_OK;
    }
    
    cui_file_selector_result_event_struct *result_evt =
        reinterpret_cast<cui_file_selector_result_event_struct*>(evt);

    if (result_evt->result > 0)
    {
        srv_fmgr_fileinfo_struct fileinfo;
        WCHAR *path_buffer;
        VFX_ALLOC_MEM(path_buffer, SRV_FMGR_PATH_BUFFER_SIZE, inst);
        
        cui_file_selector_get_selected_filepath(
            result_evt->sender_id,
            &fileinfo,
            path_buffer,
            SRV_FMGR_PATH_BUFFER_SIZE);

        WCHAR *ext_name = srv_fmgr_path_get_extension_ptr(path_buffer);

        if (mmi_wcscmp(ext_name, (const WCHAR*)L"msh") == 0)
        {
            loadType = LOAD_MESH;
            inst->loadMesh(path_buffer);
        }
        else if (mmi_wcscmp(ext_name, (const WCHAR*)L"mtl") == 0)
        {
            loadType = LOAD_MATERIAL;
            inst->loadMaterial(path_buffer);
        }
        else if (mmi_wcscmp(ext_name, (const WCHAR*)L"scn") == 0)
        {
            loadType = LOAD_SCENE;
            inst->loadScene(path_buffer);
        }
        else if (mmi_wcscmp(ext_name, (const WCHAR*)L"ani") == 0)
        {
            loadType = LOAD_ANIMATION;
            inst->loadAnimation(path_buffer);
        }

        VFX_FREE_MEM(path_buffer);
    }

    cui_file_selector_close(result_evt->sender_id);
    VFX_ASSERT(inst->m_file_sel_cui == result_evt->sender_id);
    inst->m_file_sel_cui = GRP_ID_INVALID;


    VfxNode *node = inst->m_arcBall->getAssociatedNode();
    if (loadType == LOAD_MATERIAL && node != NULL)
    {
        VfxS32 matIndexToLoad = inst->m_matIndexToLoad;
        VfxMesh *mesh = VFX_OBJ_DYNAMIC_CAST(node, VfxMesh);
        if (mesh != NULL)
        {
            if (mesh->getMaterial(matIndexToLoad) == NULL)
            {
                inst->m_loadMaterialButton->setButtonIsHighlighted(matIndexToLoad, VFX_FALSE);
            }
            else
            {
                inst->m_loadMaterialButton->setButtonIsHighlighted(matIndexToLoad, VFX_TRUE);
            }
        }
    }

    inst->m_loadType = LOAD_NONE;

    return MMI_RET_OK;
}


void VtstRtArcBallApp::loadMesh(const WCHAR* filepath)
{
    closeAllCreatedNodes();

    VfxMesh *mesh;
    VFX_OBJ_CREATE(mesh, VfxMesh, m_appScr);
    
    if (VfxAssetLoader::loadMesh(mesh, VFX_WSTR_MEM(filepath)))
    {
        pushNewlyCreatedNode(mesh);
        
        m_arcBall->associateNode(mesh);

        // Refresh material index button
        m_loadMaterialButton->setIsDisabled(VFX_FALSE);
        if (m_matButtonNum < (VfxS32)mesh->getSubMeshCount())
        {
            WCHAR buttonIndexBuffer[2];
            buttonIndexBuffer[1] = L'\0';
            while (m_matButtonNum < (VfxS32)mesh->getSubMeshCount() && m_matButtonNum < 10)
            {
                buttonIndexBuffer[0] = L'0' + m_matButtonNum;
                m_loadMaterialButton->addButton(
                    m_matButtonNum,
                    VcpStateImage(0, 0, 0, 0),
                    VFX_WSTR_MEM(buttonIndexBuffer));
                m_matButtonNum++;
            }
        }
        else if (m_matButtonNum > (VfxS32)mesh->getSubMeshCount())
        {
            while (m_matButtonNum > (VfxS32)mesh->getSubMeshCount() && m_matButtonNum > 1)
            {
                m_matButtonNum--;
                m_loadMaterialButton->removeButton(m_matButtonNum);
            }
        }
        // Reset button state
        for (VfxS32 i = 0; i < m_matButtonNum; i++)
        {
            m_loadMaterialButton->setButtonIsHighlighted(i, VFX_FALSE);
        }
        m_matIndexToLoad = 0;

        // Let operation options visible
        m_optButton->setHidden(VFX_FALSE);
        // Hide play/stop/slider
        m_aniPlayButton->setHidden(VFX_TRUE);
        m_aniStopButton->setHidden(VFX_TRUE);
        m_aniSlider->setHidden(VFX_TRUE);
    }
    else
    {
        VFX_OBJ_CLOSE(mesh);
    }
}


void VtstRtArcBallApp::loadMaterial(const WCHAR* filepath)
{
    VfxNode *node = m_arcBall->getAssociatedNode();
    if (node != NULL)
    {
        VfxMesh *mesh = VFX_OBJ_DYNAMIC_CAST(node, VfxMesh);
        if (mesh == NULL)
        {
            return;
        }
        
        VfxMaterial *material;
        VFX_OBJ_CREATE(material, VfxMaterial, mesh);

        setCurrDir(filepath);
        if (VfxAssetLoader::loadMaterial(material, VFX_WSTR_MEM(filepath)))
        {
            VfxMaterial *oriMaterial = mesh->getMaterial(m_matIndexToLoad);

            if (oriMaterial != NULL)
            {
                VFX_OBJ_CLOSE(oriMaterial);
            }
            mesh->setMaterial(m_matIndexToLoad, material);
        }
        else
        {
            VFX_OBJ_CLOSE(material);
        }
    }
}


void VtstRtArcBallApp::storeCurrDir()
{
    // VfxAssetLoader::loadScene() needs to load children files
    // but does not have the full path of children. We have to
    // set current dir for the children.
    if (m_prevCurrDir == NULL)
    {
        VFX_ALLOC_MEM(m_prevCurrDir, SRV_FMGR_PATH_BUFFER_SIZE, this);
        FS_GetCurrentDir(m_prevCurrDir, SRV_FMGR_PATH_BUFFER_SIZE / sizeof(WCHAR) - 1);
    }
}


void VtstRtArcBallApp::setCurrDir(const WCHAR *filepath)
{
    storeCurrDir();
    
    WCHAR *fileDir;
    VFX_ALLOC_MEM(fileDir, SRV_FMGR_PATH_BUFFER_SIZE, this);
    if (getBaseDir(filepath, fileDir, SRV_FMGR_PATH_BUFFER_SIZE / sizeof(WCHAR)))
    {
        FS_SetCurrentDir(fileDir);
    }
    VFX_FREE_MEM(fileDir);
}


void VtstRtArcBallApp::loadScene(const WCHAR* filepath)
{
    closeAllCreatedNodes();

    VfxGroup *sceneGroup;
    VFX_OBJ_CREATE(sceneGroup, VfxGroup, m_appScr);

    setCurrDir(filepath);
    if (VfxAssetLoader::loadScene(sceneGroup, VFX_WSTR_MEM(filepath)))
    {
        pushNewlyCreatedNode(sceneGroup);
        
        m_arcBall->associateScene(sceneGroup);

        // Reset & disable material index button
        m_loadMaterialButton->setIsDisabled(VFX_TRUE);
        m_loadMaterialButton->setButtonIsHighlighted(0, VFX_TRUE);
        while (m_matButtonNum > 1)
        {
            m_matButtonNum--;
            m_loadMaterialButton->removeButton(m_matButtonNum);
        }
        m_matIndexToLoad = 0;

        // Let operation options visible
        m_optButton->setHidden(VFX_FALSE);
        // Hide play/stop/slider
        m_aniPlayButton->setHidden(VFX_TRUE);
        m_aniStopButton->setHidden(VFX_TRUE);
        m_aniSlider->setHidden(VFX_TRUE);
    }
    else
    {
        VFX_OBJ_CLOSE(sceneGroup);
    }
}


void VtstRtArcBallApp::loadAnimation(const WCHAR* filepath)
{
    VfxNode *node = m_arcBall->getAssociatedNode();
    if (node != NULL)
    {
        VfxAnimation *oldAni = m_arcBall->getAnimation();
        if (oldAni != NULL)
        {
            VFX_OBJ_CLOSE(oldAni);
        }
    
        VfxAnimation *ani;
        VFX_OBJ_CREATE(ani, VfxAnimation, node);

        setCurrDir(filepath);
        if (VfxAssetLoader::loadAnimation(ani, node, VFX_WSTR_MEM(filepath)))
        {
            m_arcBall->setAnimationToNode(ani);
            // Let play/stop/slider
            m_aniPlayButton->setHidden(VFX_FALSE);
            m_aniStopButton->setHidden(VFX_FALSE);
            m_aniSlider->setHidden(VFX_FALSE);
            // Hide operation options
            m_optButton->setHidden(VFX_TRUE);

            m_aniStopButton->setIsDisabled(VFX_TRUE);
            m_aniPlayButton->setIsDisabled(VFX_FALSE);
        }
        else
        {
            VFX_OBJ_CLOSE(ani);
        }
    }
}


VfxBool VtstRtArcBallApp::getBaseDir(
        const WCHAR *filepath,
        WCHAR *out_base_dir,
        VfxS32 len_out_base_dir)
{
    VfxS32 dir_len = 0;
    
    for (VfxS32 i = 0; filepath[i] != L'\0'; i++)
    {
        if (filepath[i] == L'\\')
        {
            dir_len = i;
        }
    }

    if (dir_len >= len_out_base_dir)
    {
        // Insufficient buffer space
        out_base_dir[0] = L'\0';
        return VFX_FALSE;
    }

    mmi_wcsncpy(out_base_dir, filepath, dir_len);
    out_base_dir[dir_len] = L'\0'; // make sure null-terminated

    return VFX_TRUE;
}
#endif /* __VENUS_3D_UI_ENGINE__ */


VtstTestResultEnum vtst_rt_3d_arcball(VfxU32 param)
{
#ifdef __VENUS_3D_UI_ENGINE__
    VfxId appId = VfxAppLauncher::launch(
        APP1_BASE,
        VFX_OBJ_CLASS_INFO(VtstRtArcBallApp),
        GRP_ID_ROOT);
#endif

    return VTST_TR_OK;
}

#endif /* __AFX_RT_TEST__ */

