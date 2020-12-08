/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *  vapp_widget_3d_clock.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the 3D Clock widget.
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
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_3D_CLOCK__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "Mmi_rp_vapp_widget_3d_clock_def.h"

// Pluto MMI headers 
extern "C"
{
#include "MMI_common_app_trc.h" //Trace header
#include "GeneralSettingSrvGprot.h"
#include "GlobalResDef.h"
#include "DateTimeType.h"
#include "DateTimeGprot.h"
}

#include "vfx_object.h"
#include "vapp_widget_3d_clock.h"
#include "vdat_systime.h"
#include "vapp_setting_framework_gprot.h"

//3D headers
#include "vfx_world.h"
#include "vfx_material.h"
#include "vfx_asset_loader.h"
#include "vfx_pass.h"
#include "vfx_shader_uniforms.h"
#include "vfx_mesh.h"
#include "vfx_texture.h"
#include "vfx_compositing_mode.h"
#include "vfx_light.h"
#include "vfx_render_mode.h"
#include "vfx_polygon_mode.h"
#include "vfx_compositing_mode.h"
#include "vfx_stencil.h"
#include "vfx_blender.h"
#include "vfx_shader.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#if defined (__MTK_INTERNAL__) && defined(__MTK_TARGET__)
/* under construction !*/
#endif
    
#ifdef __MAUI_SOFTWARE_LA__
extern "C"
{
#include "SST_sla.h"
}

#define CLOCK_MEASURE_TIME_START(_symbol_) SLA_CustomLogging(##_symbol_##, SA_start);
#define CLOCK_MEASURE_TIME_STOP(_symbol_)  SLA_CustomLogging(##_symbol_##, SA_stop);
#else
#define CLOCK_MEASURE_TIME_START(_symbol_)
#define CLOCK_MEASURE_TIME_STOP(_symbol_)
#endif

//#define __3D_CLOCK_UNIT_TEST_BTN__
#define __3D_CLOCK_ROTATE_ANGLE__


/*****************************************************************************
 * 3D  Clock Widget
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidget3dClockContentPanel", VappWidget3dClockContentPanel, VfxControl);

VappWidget3dClockContentPanel::VappWidget3dClockContentPanel():
    sceneWorld(NULL),
    m_animBackground(NULL),
    m_anim(NULL),
    m_animParticle(NULL),
    m_colonStatus(VFX_FALSE),
    m_isFirstAniPlayed(VFX_FALSE),
    m_isAmExist(VFX_FALSE),
    m_2dMode(VFX_TRUE),
    m_widgetActive(VFX_TRUE),
    m_parentH1(NULL),
    m_parentH2(NULL),
    m_parentM1(NULL),
    m_parentM2(NULL),
    m_parentA(NULL),    
    m_replaceH1(NULL),
    m_replaceH2(NULL),
    m_replaceM1(NULL),
    m_replaceM2(NULL),
    m_replaceA(NULL),
    m_light(NULL),
    m_meshStage(NULL),
    m_meshSkyFront(NULL),
    m_meshSkyBack(NULL),
    m_meshCloud1Front(NULL),
    m_meshCloud2Front(NULL),
    m_meshCloud1Back(NULL),
    m_meshCloud2Back(NULL),
    m_meshPlanetFront(NULL),
    m_meshPlanetBack(NULL),
    m_meshLoftFront(NULL),
    m_meshLoftBack(NULL),
    m_meshLight1Front(NULL),
    m_meshLight2Front(NULL),
    m_meshLight1Back(NULL),
    m_meshLight2Back(NULL),
    m_meshDate(NULL),
    m_meshWeek(NULL),
    m_intH1(0),
    m_intH2(0),
    m_intM1(0),
    m_intM2(0),
    m_meridian(0),
    m_swipeAngle(0),
    m_currentScene(0),
    m_newScene(0),
    m_materialSkyFront(NULL),
    m_materialSkyBack(NULL),
    m_materialPlanetFront(NULL),
    m_materialPlanetBack(NULL),
    m_materialCloudFront(NULL),
    m_materialCloudBack(NULL),
    m_materialLightFront(NULL),
    m_materialLightBack(NULL),
    m_materialLoftFront(NULL),
    m_materialLoftBack(NULL),
    m_reflectScope(NULL),
    m_reflectUniforms(NULL),
    m_polyOffset(NULL),
    m_materialH1(NULL),
    m_materialH1_2(NULL),
    m_weekTextFrame(NULL),
    m_dateTextFrame(NULL),
    groupParticle(NULL),
    m_tlAmbient(NULL),
    m_tlAmbient2(NULL)
{
}
VappWidget3dClockContentPanel::~VappWidget3dClockContentPanel()
{
}

void VappWidget3dClockContentPanel::onInit()
{
    VfxControl::onInit();

    //get real time
    applib_dt_get_rtc_time(&currTime);

    //Create button to launch time setting menu.
    VFX_OBJ_CREATE(m_btnSetTime, VcpButton, this);
    m_btnSetTime->setOpacity(0.0f);
    m_btnSetTime->setBounds(VfxRect(0, 0, BTN_SET_TIME_SIZE_3D_X, BTN_SET_TIME_SIZE_3D_Y));
    m_btnSetTime->setPos(VfxPoint(BTN_SET_TIME_POS_3D_X, BTN_SET_TIME_POS_3D_Y));
    m_btnSetTime->setId(BTN_SET_TIME);
    m_btnSetTime->m_signalClicked.connect(this, &VappWidget3dClockContentPanel::onBtnClicked);

#if defined(__3D_CLOCK_UNIT_TEST_BTN__)
    // uni-test button for scene morphing and change time immediately.
    VcpButton *m_btnChangeScene;
    VFX_OBJ_CREATE(m_btnChangeScene, VcpButton, this);
    m_btnChangeScene->setBounds(VfxRect(0, 0, 140, 60));
    m_btnChangeScene->setPos(VfxPoint(10, 385));
    m_btnChangeScene->setId(BTN_CHANGE_SCENE);
    m_btnChangeScene->setTextFont(VfxFontDesc (6) ); 
    m_btnChangeScene->setText(VFX_WSTR("Change Scene"));
    m_btnChangeScene->setOpacity(0.0f);
    //m_btnChangeScene->setIsDisabled(VFX_TRUE);
    m_btnChangeScene->m_signalClicked.connect(this, &VappWidget3dClockContentPanel::onBtnClicked);

    VcpButton *m_btnSecs;
    VFX_OBJ_CREATE(m_btnSecs, VcpButton, this);
    m_btnSecs->setBounds(VfxRect(0, 0, 120, 60));
    m_btnSecs->setPos(VfxPoint(165, 385));
    m_btnSecs->setId(BTN_ADD_TO_55);
    m_btnSecs->setTextFont(VfxFontDesc (6) ); 
    m_btnSecs->setText(VFX_WSTR("55secs"));
    m_btnSecs->setOpacity(0.0f);
    //m_btnSecs->setIsDisabled(VFX_TRUE);
    m_btnSecs->m_signalClicked.connect(this, &VappWidget3dClockContentPanel::onBtnClicked);
#endif

    //world
    VFX_OBJ_CREATE(sceneWorld, VfxWorld, this);
    setWorld(sceneWorld);
    
    // load scene begin
    VfxAssetLoader::loadSceneBegin(sceneWorld, VAPP_WIDGET_3D_CLOCK_SCN);
    
    //find font & background mesh by name from sence graph.
    getMeshsFromScene();

    //load scene end
    VfxAssetLoader::loadSceneEnd();

    //initialize texture frame for the text of date & day mesh.
    initTextureFrame();

    //set passes for stencil reflection
    //initStageReflection();

    //load first scene
    initBackgroundScene();

    //hide second scene firstly to reduce loading
    setSceneVisible(FRONT_MESH,VFX_FALSE);
    swapFrontBackMeshes();
    
    //start colon timer ticking
    startColonTimer();

    //Get pivot, rotation, scale,translation
    getFontModelTransform();

    //Close default font model.
    VFX_OBJ_CLOSE(m_meshH1);
    VFX_OBJ_CLOSE(m_meshH2);   
    VFX_OBJ_CLOSE(m_meshM1);
    VFX_OBJ_CLOSE(m_meshM2);       
    VFX_OBJ_CLOSE(m_meshA);
        
    //Config Animation (e.g. Create animation or timeline)
    configAnimation();

    //update Time
    updateTime();

    //on background time changed
    VdatTimeNotification *sysTimeSrv = VFX_OBJ_GET_INSTANCE(VdatTimeNotification);
    sysTimeSrv->m_signalTimeChanged.connect(this, &VappWidget3dClockContentPanel::onTimeChanged);
    

    //2nd pass loading opening animation 2d to 3d mode.
    VfxTimer *s_openingAniTimer;
    VFX_OBJ_CREATE(s_openingAniTimer, VfxTimer, this);
    s_openingAniTimer->setStartDelay(400);
    s_openingAniTimer->m_signalTick.connect(this, &VappWidget3dClockContentPanel::onLoad1stAni);
    s_openingAniTimer->start();    

}

void VappWidget3dClockContentPanel::onLoad1stAni(VfxTimer *timer)
{
    //Opening animation
    playAnimation();
}

void VappWidget3dClockContentPanel::initStageReflection(void)
{
    setHintFlag(VFX_FRAME_HINTS_STENCIL_TEST);

#define RENDER_SCOPE_STENCIL_FILL   (VFX_RENDER_SCOPE_USER_BEGIN << 0)
#define RENDER_SCOPE_REFLECTION     (VFX_RENDER_SCOPE_USER_BEGIN << 1)
#define RENDER_SCOPE_STAGE_COLOR    (VFX_RENDER_SCOPE_USER_BEGIN << 2)

    VFX_OBJ_CREATE(m_reflectScope, VfxRenderMode, sceneWorld);
    m_reflectScope->setScope(RENDER_SCOPE_REFLECTION);
    VFX_OBJ_CREATE(m_reflectUniforms, VfxShaderUniforms, sceneWorld);
    VfxShaderVariable *varPos = m_reflectUniforms->addUniformVariable(VFX_STR("uReflectPos"), VFX_TYPE_ID_VEC3, 1);
    varPos->bindValue(m_meshStage, VFX_BINDING_WORLD_SPACE_POSITION);
    VfxShaderVariable *varDir = m_reflectUniforms->addUniformVariable(VFX_STR("uReflectDir"), VFX_TYPE_ID_VEC3, 1);
    varDir->bindValue(m_meshStage, VFX_BINDING_WORLD_SPACE_DIRECTION);
    VfxShaderVariable *varOff = m_reflectUniforms->addUniformVariable(VFX_STR("uReflectOff"), VFX_TYPE_ID_FLOAT, 1);
    varOff->setValue(1.7f);

    // set world material
    VfxMaterial *materialScene;
    VFX_OBJ_CREATE_EX(materialScene, VfxMaterial, sceneWorld, (3));
    sceneWorld->setMaterial(materialScene);

    // stencil fill pass
    VfxPass *passFill;
    VFX_OBJ_CREATE(passFill, VfxPass, materialScene);
    materialScene->setPass(0, passFill);

    VfxRenderMode *rmFill;
    VFX_OBJ_CREATE(rmFill, VfxRenderMode, passFill);
    passFill->setRenderMode(rmFill);
    rmFill->setScope(RENDER_SCOPE_STENCIL_FILL);

    VfxCompositingMode *cmFill;
    VFX_OBJ_CREATE(cmFill, VfxCompositingMode, passFill);
    passFill->setCompositingMode(cmFill);
    cmFill->setColorWriteMask(0x00000000);
    cmFill->setDepthWriteEnable(VFX_FALSE);

    VfxStencil *stencilFill;
    VFX_OBJ_CREATE(stencilFill, VfxStencil, cmFill);
    cmFill->setStencil(stencilFill);
    stencilFill->setStencilFunc(
        VFX_STENCIL_FUNC_ALWAYS, 1, 0xFFFFFFFF,
        VFX_STENCIL_FUNC_ALWAYS, 1, 0xFFFFFFFF);
    stencilFill->setStencilOperation(
        VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_REPLACE,
        VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_KEEP, VFX_STENCIL_OP_REPLACE);

    // reflection pass
    VfxPass *passRefl;
    VFX_OBJ_CREATE(passRefl, VfxPass, materialScene);
    materialScene->setPass(1, passRefl);

    passRefl->setRenderMode(m_reflectScope);

    VfxPolygonMode *pmRefl;
    VFX_OBJ_CREATE(pmRefl, VfxPolygonMode, passRefl);
    passRefl->setPolygonMode(pmRefl);
    pmRefl->setWinding(VFX_WINDING_CW);

    VfxCompositingMode *cmRefl;
    VFX_OBJ_CREATE(cmRefl, VfxCompositingMode, passRefl);
    passRefl->setCompositingMode(cmRefl);

    VfxBlender *blendRefl;
    VFX_OBJ_CREATE(blendRefl, VfxBlender, cmRefl);
    cmRefl->setBlender(blendRefl);
    blendRefl->setBlendFunc(
        VFX_BLEND_FACTOR_SRC_ALPHA, VFX_BLEND_FACTOR_ONE_MINUS_SRC_ALPHA,
        VFX_BLEND_FACTOR_ZERO, VFX_BLEND_FACTOR_ZERO);

    VfxStencil *stencilRefl;
    VFX_OBJ_CREATE(stencilRefl, VfxStencil, cmRefl);
    cmRefl->setStencil(stencilRefl);
    stencilRefl->setStencilFunc(
        VFX_STENCIL_FUNC_EQUAL, 1, 0xFFFFFFFF,
        VFX_STENCIL_FUNC_EQUAL, 1, 0xFFFFFFFF);

    // drawing pass
    VfxPass *passDraw;
    VFX_OBJ_CREATE(passDraw, VfxPass, materialScene);
    materialScene->setPass(2, passDraw);

    VfxRenderMode *rmDraw;
    VFX_OBJ_CREATE(rmDraw, VfxRenderMode, passDraw);
    passDraw->setRenderMode(rmDraw);
    rmDraw->setScope(RENDER_SCOPE_STAGE_COLOR | VFX_RENDER_SCOPE_DEFAULT);

    // stage scopes
    VfxPass *passStage = m_meshStage->getMaterial(0)->getPass(0);

    VfxRenderMode *rmStage;
    VFX_OBJ_CREATE(rmStage, VfxRenderMode, passStage);
    passStage->setRenderMode(rmStage);
    rmStage->setScope(RENDER_SCOPE_STENCIL_FILL | RENDER_SCOPE_STAGE_COLOR);

    // add reflection passes to meshes
    addReflectionPass(m_meshWeek->getMaterial(0));
    addReflectionPass(m_meshDate->getMaterial(0));
}

void VappWidget3dClockContentPanel::addReflectionPass(VfxMaterial *material)
{
    VFX_DEV_ASSERT(material->getPassCount() == 1);
    material->setPassCount(2);

    VfxPass *passOri = material->getPass(0);
    VfxPass *passRefl;
    VFX_OBJ_CREATE(passRefl, VfxPass, material);
    material->setPass(1, passRefl);
    passRefl->setRenderMode(m_reflectScope);

    VfxShaderProgram *program;
    VFX_OBJ_CREATE_EX(program, VfxShaderProgram, passRefl,
        (VfxAssetSrc(VAPP_WIDGET_3D_CLOCK_REFLECT_VS), passOri->getShaderProgram()->getFragmentShader()));
    passRefl->setShaderProgram(program);

    VfxList< VfxWeakPtr<VfxShaderUniforms> >::ConstIt it = passOri->getShaderUniformList().begin();
    for (; !it.isNull(); ++it)
    {
        passRefl->addShaderUniforms(it->get());
    }
    passRefl->addShaderUniforms(m_reflectUniforms);
}

void VappWidget3dClockContentPanel::initBackgroundScene(void)
{
    //init backgroud scene for morphing immediately.
    if (currTime.nHour >=6 && currTime.nHour<11)         //morning
    {
        loadMorningToBack();
        m_currentScene= MORNING; //for immediately morphing        
    }
    else if (currTime.nHour >=11 && currTime.nHour<16)   //noon
    {
        loadNoonToBack();
        m_currentScene= NOON;        
    }
    else if (currTime.nHour >=16 && currTime.nHour <20)  //sunsest
    {
        loadSunsetToBack();
        m_currentScene= SUNSET;
    }        
    else if (currTime.nHour >=20 || currTime.nHour <=5)  //night
    {
        loadNightToBack();
        m_currentScene= NIGHTFALL;        
    }

    //load
    loadParticle();
}

void VappWidget3dClockContentPanel::loadParticle()
{
    //load particle scene
    VfxResId particleScene = 0, particleAni = 0;
    if (currTime.nHour >=6 && currTime.nHour<11)         //morning
    {
        particleScene = VAPP_WIDGET_3D_CLOCK_PARTICLE_MORNING_SCN;
        particleAni = VAPP_WIDGET_3D_CLOCK_PARTICLE_MORNING_ANI;
    }
    else if (currTime.nHour >=11 && currTime.nHour<16)   //noon
    {
        particleScene = VAPP_WIDGET_3D_CLOCK_PARTICLE_NOON_SCN;
        particleAni = VAPP_WIDGET_3D_CLOCK_PARTICLE_NOON_ANI;         
        
    }
    else if (currTime.nHour >=16 && currTime.nHour <20)  //sunsest
    {
        particleScene = VAPP_WIDGET_3D_CLOCK_PARTICLE_SUNSET_SCN;
        particleAni = VAPP_WIDGET_3D_CLOCK_PARTICLE_SUNSET_ANI;        
    }        
    else if (currTime.nHour >=20 || currTime.nHour <=5)  //night
    {
        particleScene = VAPP_WIDGET_3D_CLOCK_PARTICLE_NIGHT_SCN; 
        particleAni = VAPP_WIDGET_3D_CLOCK_PARTICLE_NIGHT_ANI;        
    }
    
    //load particle scene
    VFX_OBJ_CLOSE(groupParticle);
    VFX_OBJ_CREATE(groupParticle, VfxGroup, sceneWorld);
    VfxAssetLoader::loadScene(groupParticle, particleScene);

    //load particle animation
    //VFX_OBJ_CLOSE(m_animParticle);//assert, has been closed.
    VFX_OBJ_CREATE(m_animParticle, VfxAnimation, groupParticle);
    VfxAssetLoader::loadAnimation(m_animParticle, groupParticle,particleAni);     
    groupParticle->setVisible(VFX_FALSE);

    //apply timeline to particle animation
    //VFX_OBJ_CLOSE(m_refTlParticle);//assert, has been closed.
    VFX_OBJ_CREATE(m_refTlParticle, VfxFloatTimeline, groupParticle);
    m_refTlParticle->stop();//1103
    m_refTlParticle->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTlParticle->setTarget(groupParticle);
    m_refTlParticle->setDuration(10000);
    m_refTlParticle->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_refTlParticle->setFromValue(0.0f);
    m_refTlParticle->setToValue(1.0f);
    m_animParticle->setTimelineTime(m_refTlParticle);
    m_refTlParticle->start();//start after morphing or first init.
}

void VappWidget3dClockContentPanel::setSceneVisible(LoadToMeshEnum type, VfxBool isHide)
{
    switch (type)
    {
        case FRONT_MESH:
            m_meshSkyFront->setVisible(isHide);
            m_meshCloud1Front->setVisible(isHide);
            m_meshCloud2Front->setVisible(isHide);
            m_meshPlanetFront->setVisible(isHide);
            m_meshLoftFront->setVisible(isHide);
            m_meshLight1Front->setVisible(isHide);
            m_meshLight2Front->setVisible(isHide);   
            break;
            
        case BACK_MESH:
            m_meshSkyBack->setVisible(isHide);
            m_meshCloud1Back->setVisible(isHide);
            m_meshCloud2Back->setVisible(isHide);
            m_meshPlanetBack->setVisible(isHide);
            m_meshLoftBack->setVisible(isHide);
            m_meshLight1Back->setVisible(isHide);
            m_meshLight2Back->setVisible(isHide);            
            break;
    }
}

void VappWidget3dClockContentPanel::swapFrontBackMeshes()
{
    vfxSwap<VfxMesh*>(m_meshSkyFront, m_meshSkyBack);
    vfxSwap<VfxMesh*>(m_meshCloud1Front, m_meshCloud1Back);
    vfxSwap<VfxMesh*>(m_meshCloud2Front, m_meshCloud2Back);
    vfxSwap<VfxMesh*>(m_meshPlanetFront, m_meshPlanetBack);
    vfxSwap<VfxMesh*>(m_meshLoftFront, m_meshLoftBack);
    vfxSwap<VfxMesh*>(m_meshLight1Front, m_meshLight1Back);
    vfxSwap<VfxMesh*>(m_meshLight2Front, m_meshLight2Back);
    vfxSwap<VfxMaterial*>(m_materialSkyFront, m_materialSkyBack);
    vfxSwap<VfxMaterial*>(m_materialCloudFront, m_materialCloudBack);
    vfxSwap<VfxMaterial*>(m_materialPlanetFront, m_materialPlanetBack);
    vfxSwap<VfxMaterial*>(m_materialLoftFront, m_materialLoftBack);
    vfxSwap<VfxMaterial*>(m_materialLightFront, m_materialLightBack);
}

void VappWidget3dClockContentPanel::getMeshsFromScene()
{
    //Front //Noon
    VfxString nameSkyFront= VFX_STR("Sky_S2-node");
    VfxString nameLoftFront = VFX_STR("Loft_S2-node");      
    VfxString nameLight1Front = VFX_STR("Light_1_S2-node");
    VfxString nameLight2Front = VFX_STR("Light_2_S2-node"); 
    VfxString namePlanetFront= VFX_STR("Planet_S2-node");
    VfxString nameCloud1Front= VFX_STR("Cloud_1_S2-node");
    VfxString nameCloud2Front= VFX_STR("Cloud_2_S2-node");

    //Back //Morning
    VfxString nameSkyBack= VFX_STR("Sky_S1-node");
    VfxString nameLoftBack = VFX_STR("Loft_S1-node");
    VfxString nameLight1Back = VFX_STR("Light_1_S1-node");
    VfxString nameLight2Back = VFX_STR("Light_2_S1-node");
    VfxString namePlanetBack= VFX_STR("Planet_S1-node");
    VfxString nameCloud1Back= VFX_STR("Cloud_1_S1-node");
    VfxString nameCloud2Back= VFX_STR("Cloud_2_S1-node");

    //Font model
    VfxString nameH1 = VFX_STR("H1-node");
    VfxString nameH2 = VFX_STR("H2-node");
    VfxString nameColon = VFX_STR("Colon-node");
    VfxString nameM1 = VFX_STR("M1-node");    
    VfxString nameM2 = VFX_STR("M2-node");    
    VfxString nameA = VFX_STR("Text_A-node");
    VfxString nameM = VFX_STR("Text_M-node");  

    //Week & date
    VfxString nameWeek = VFX_STR("Week-node");
    VfxString nameDate = VFX_STR("Date-node");

    //Light
    VfxString nameOmni = VFX_STR("Omni001-node");
                                  
    //Stage
    VfxString nameStage = VFX_STR("Stage-node");

    m_meshStage = (VfxMesh *)VfxAssetLoader::findObjByName(nameStage);

    m_light = (VfxLight *)VfxAssetLoader::findObjByName(nameOmni);
    m_meshH1 = (VfxMesh *)VfxAssetLoader::findObjByName(nameH1);
    m_meshH2 = (VfxMesh *)VfxAssetLoader::findObjByName(nameH2);
    m_meshM1 = (VfxMesh *)VfxAssetLoader::findObjByName(nameM1);
    m_meshM2 = (VfxMesh *)VfxAssetLoader::findObjByName(nameM2);
    m_meshA = (VfxMesh *)VfxAssetLoader::findObjByName(nameA);
    m_meshM = (VfxMesh *)VfxAssetLoader::findObjByName(nameM);
    m_meshColon= (VfxMesh *)VfxAssetLoader::findObjByName(nameColon);
    
    //sky
    m_meshSkyFront = (VfxMesh *)VfxAssetLoader::findObjByName(nameSkyFront);
    m_meshSkyBack = (VfxMesh *)VfxAssetLoader::findObjByName(nameSkyBack);
   
    //cloud1
    m_meshCloud1Front = (VfxMesh *)VfxAssetLoader::findObjByName(nameCloud1Front);
    m_meshCloud1Back = (VfxMesh *)VfxAssetLoader::findObjByName(nameCloud1Back);

    //cloud2
    m_meshCloud2Front = (VfxMesh *)VfxAssetLoader::findObjByName(nameCloud2Front);       
    m_meshCloud2Back = (VfxMesh *)VfxAssetLoader::findObjByName(nameCloud2Back);
    
    //planet
    m_meshPlanetFront = (VfxMesh *)VfxAssetLoader::findObjByName(namePlanetFront);
    m_meshPlanetBack = (VfxMesh *)VfxAssetLoader::findObjByName(namePlanetBack);

    //light
    m_meshLight1Front =  (VfxMesh *)VfxAssetLoader::findObjByName(nameLight1Front);
    m_meshLight2Front =  (VfxMesh *)VfxAssetLoader::findObjByName(nameLight2Front);  
   
    m_meshLight1Back =  (VfxMesh *)VfxAssetLoader::findObjByName(nameLight1Back);    
    m_meshLight2Back =  (VfxMesh *)VfxAssetLoader::findObjByName(nameLight2Back); 

    //loft
    m_meshLoftFront = (VfxMesh *)VfxAssetLoader::findObjByName(nameLoftFront);
    m_meshLoftBack = (VfxMesh *)VfxAssetLoader::findObjByName(nameLoftBack);
        
    //date &week
    m_meshDate =  (VfxMesh *)VfxAssetLoader::findObjByName(nameDate);
    m_meshWeek = (VfxMesh *)VfxAssetLoader::findObjByName(nameWeek);

    //get parent of each mesh for adding back
    m_parentH1 = m_meshH1->getParentNode();
    m_parentH2 = m_meshH2->getParentNode();
    m_parentM1 = m_meshM1->getParentNode();
    m_parentM2 = m_meshM2->getParentNode();
    m_parentA = m_meshA->getParentNode();
}

void VappWidget3dClockContentPanel::initTextureFrame()
{
    // Add lable frame texture
    VfxFrame *m_lableWeekFrame;
    VFX_OBJ_CREATE(m_lableWeekFrame, VfxFrame, this);
    m_lableWeekFrame->setSize(MESH_WEEK_SIZE_X,MESH_WEEK_SIZE_Y);
    m_lableWeekFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);

    VfxFrame *m_lableDateFrame;
    VFX_OBJ_CREATE(m_lableDateFrame, VfxFrame, this);
    m_lableDateFrame->setSize(MESH_DATE_SIZE_X,MESH_DATE_SIZE_Y);
    m_lableDateFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);

    //add week text frame 
    VFX_OBJ_CREATE(m_weekTextFrame, VfxTextFrame, m_lableWeekFrame);
    VfxFontDesc m_weekFontDesc;
    m_weekFontDesc.size = VFX_FONT_DESC_VF_SIZE(FONT_SIZE_WEEK);
    m_weekFontDesc.attr = VFX_FONT_DESC_ATTR_BOLD;
    m_weekFontDesc.effect = VFX_FE5_1;
    m_weekTextFrame->setFont(m_weekFontDesc);
    m_weekTextFrame->setColor(VFX_COLOR_WHITE);
    m_weekTextFrame->setFullLineHeightMode(VFX_FALSE);
    m_weekTextFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_weekTextFrame->setVerticalToCenter(VFX_TRUE);
    m_weekTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
    m_weekTextFrame->setAnchor(0.5f, 0.5f);
    m_weekTextFrame->setPos(m_lableWeekFrame->getSize().width / 2, m_lableWeekFrame->getSize().height/ 2);
    m_weekTextFrame->setSize(MESH_WEEK_SIZE_X, MESH_WEEK_SIZE_Y);
    m_weekTextFrame->setAutoResized(VFX_FALSE);
    m_weekTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    //add date text frame     
    VFX_OBJ_CREATE(m_dateTextFrame, VfxTextFrame, m_lableDateFrame);
    VfxFontDesc m_dateFontDesc;
    m_dateFontDesc.size = VFX_FONT_DESC_VF_SIZE(FONT_SIZE_DATE);
    m_dateFontDesc.attr = VFX_FONT_DESC_ATTR_BOLD;
    m_dateFontDesc.effect = VFX_FE5_1;
    m_dateTextFrame->setFont(m_dateFontDesc);
    m_dateTextFrame->setColor(VFX_COLOR_WHITE);
    m_dateTextFrame->setFullLineHeightMode(VFX_FALSE);
    m_dateTextFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_dateTextFrame->setVerticalToCenter(VFX_TRUE);
    m_dateTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_dateTextFrame->setAnchor(0.5f, 0.5f);
    m_dateTextFrame->setPos(m_lableDateFrame->getSize().width / 2, m_lableDateFrame->getSize().height/ 2);
    m_dateTextFrame->setSize(MESH_DATE_SIZE_X, MESH_DATE_SIZE_Y);
    m_dateTextFrame->setAutoResized(VFX_FALSE);
    m_dateTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);

    VfxShaderUniforms *m_weekLableUni = 
        m_meshWeek->getMaterial(0)->getPass(0)->getShaderUniformList().begin()->get();
    VfxShaderVariable *m_weekLableVar = 
        m_weekLableUni->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    VfxTextureFrame *m_weekLabelTexture;
    VFX_OBJ_CREATE_EX(m_weekLabelTexture, VfxTextureFrame, m_weekLableVar, (m_lableWeekFrame));
    m_weekLableVar->setValue(m_weekLabelTexture);     

    VfxShaderUniforms *m_dateLableUni = 
        m_meshDate->getMaterial(0)->getPass(0)->getShaderUniformList().begin()->get();
    VfxShaderVariable *m_dateLableVar = 
        m_dateLableUni->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    VfxTextureFrame *m_dateLabelTexture;
    VFX_OBJ_CREATE_EX(m_dateLabelTexture, VfxTextureFrame, m_dateLableVar, (m_lableDateFrame));
    m_dateLableVar->setValue(m_dateLabelTexture);    
}

void VappWidget3dClockContentPanel::startColonTimer()
{
    // Always use 1 second as the duration of timer.
    VfxTimer *s_timer;    
    VFX_OBJ_CREATE(s_timer, VfxTimer, this);
    s_timer->setDuration(1000);
    s_timer->m_signalTick.connect(this, &VappWidget3dClockContentPanel::onColonTimerTick);
    s_timer->start();
}

void VappWidget3dClockContentPanel::startParticleTimer()
{
    VfxTimer *s_particleTimer;    
    VFX_OBJ_CREATE(s_particleTimer, VfxTimer, this);
    s_particleTimer->setStartDelay(2500);
    s_particleTimer->m_signalTick.connect(this, &VappWidget3dClockContentPanel::onParticleTimeout);
    s_particleTimer->start();
}

void VappWidget3dClockContentPanel::configPolygonOffset()
{
    //set polygonOffset for each background mesh.
    setPolygonOffset(m_materialSkyFront, m_materialSkyBack);
    setPolygonOffset(m_materialCloudFront, m_materialCloudBack);
    setPolygonOffset(m_materialLightFront, m_materialLightBack);
    setPolygonOffset(m_materialLoftFront, m_materialLoftBack);
    setPolygonOffset(m_materialPlanetFront, m_materialPlanetBack);
}

void VappWidget3dClockContentPanel::setPolygonOffset(
    VfxMaterial *front,
    VfxMaterial *back)
{
    VFX_DEV_ASSERT(front);
    VFX_DEV_ASSERT(back);

    // add z-offset to shadow material
    VfxS32 Z_FACTOR = -1;
    VfxS32 Z_OFFSET = -1;

    if (m_polyOffset == NULL)
    {
        VFX_OBJ_CREATE(m_polyOffset, VfxCompositingMode, sceneWorld);
        m_polyOffset->setDepthOffset(Z_FACTOR, Z_OFFSET);
        m_polyOffset->setDepthFunc(VFX_DEPTH_FUNC_LEQUAL);
    }

    VfxU32 i;
    for (i = 0; i < front->getPassCount(); ++i)
    {
        front->getPass(i)->setCompositingMode(NULL);
    }
    for (i = 0; i < back->getPassCount(); ++i)
    {
        back->getPass(i)->setCompositingMode(m_polyOffset);
    }
}

inline VfxFloatTimeline *VappWidget3dClockContentPanel::setOpacityTL( 
        VfxMesh *targetMesh,
        const VfxMsec duration,
        const VfxFloat fromValue,
        const VfxFloat toValue)
{
    //start morphing
    VfxFloatTimeline *opacityTL;
    VFX_OBJ_CREATE(opacityTL, VfxFloatTimeline, m_animBackground);
    opacityTL->setTarget(targetMesh);
    opacityTL->setTargetPropertyId(VRT_NODE_PROPERTY_ID_OPACITY);
    opacityTL->setTimingFunc(VFX_TIMING_FUNC_ID_EASE_OUT);
    opacityTL->setFromValue(fromValue);
    opacityTL->setToValue(toValue);
    opacityTL->setDuration(duration);
    opacityTL->start();
    return opacityTL;
}
   
void VappWidget3dClockContentPanel::updateTime()
{

    //get real time
    //note: this api always return 24hr time.
    applib_dt_get_rtc_time(&currTime);

    VfxU8 str_len;
    VfxWChar dTStr[15] = {0};
    VfxDateTime dateTime;
    VfxDateTime timeAmPm;
    timeAmPm.setCurrentTime();
    dateTime.setCurrentTime();

    //check the setting if the 24 hour time exist.
    timeAmPm.getDateTimeString(
    VFX_DATE_TIME_TIME_MINUTE|VFX_DATE_TIME_TIME_HOUR, (VfxWChar*)dTStr,15);
    str_len = vfx_sys_wcslen((VfxWChar*)dTStr);

    //seperate hour and min
    // 5 = 24-hr time on
    // 8 = 24-hr time off
    if (str_len < 6) // setting with 24 hour time, eg. show 23:23
    {
            m_intH1 = (currTime.nHour) / 10;
            m_intH2 = (currTime.nHour) % 10;
    }
    else             // setting without 24 hour time.
    {
        if(currTime.nHour > 12)        //pm
        {
            m_intH1 = (currTime.nHour-12) / 10;
            m_intH2 = (currTime.nHour-12) % 10;
        }
        else                           //am
        {
            // 00:00am should be 12am
            if(currTime.nHour == 0)
            {
                m_intH1= 1;
                m_intH2= 2;
            }
            else
            {
                m_intH1 = currTime.nHour / 10;
                m_intH2 = currTime.nHour % 10;
            }
        }
    }

    m_intM1 = currTime.nMin / 10;
    m_intM2 = currTime.nMin % 10;  
    m_intSec = currTime.nSec;
    m_intDay = currTime.nDay;
    
    // get meridian,  'A'M or 'P'M
    if(currTime.nHour >= 12)
    {
        m_meridian = 1; //pm
    }
    else
    {   
        m_meridian = 0;//am
    }


    //set string of date
    dateTime.getDateTimeString(
        VFX_DATE_TIME_DATE_YEAR | VFX_DATE_TIME_DATE_MONTH | VFX_DATE_TIME_DATE_DAY,
        (VfxWChar*)dTStr,15);
    m_dateTextFrame->setString(VFX_WSTR_MEM(dTStr));    
    
    //set string of day
    dateTime.getDateTimeString(VFX_DATE_TIME_DAY_NORMAL_NAME, (VfxWChar*)dTStr, 15);
    m_weekTextFrame->setString(VFX_WSTR_MEM(dTStr));

    //set newScene after update time to compare with currentScene
    if (currTime.nHour >=6 && currTime.nHour<11)
    {
        m_newScene=MORNING;
    }
    else if(currTime.nHour >=11 && currTime.nHour<16)
    {
        m_newScene=NOON;
    }
    else if(currTime.nHour >=16 && currTime.nHour<20)
    {
        m_newScene=SUNSET;        
    }
    else
    {
        m_newScene=NIGHTFALL;    
    }

    //Replace mesh
    replaceMeshs();

    //if AM-PM exist, set its opacity
    //since 'm_replaceA' be generated from 'replaceMeshs()'
    //so  'setAmPmOpacity()' must after 'replaceMeshs()'
    if (str_len > 6)
    {
        //AMPM exist, set opacity to be darker of the AMPM mesh.
        m_isAmExist = VFX_TRUE;
    }
    else
    {
        m_isAmExist = VFX_FALSE;
    }
    setAmPmOpacity();
}

void VappWidget3dClockContentPanel::onRestoreDelayTimer(VfxTimer *restoreTimer)
{
    // when widget in onRestore view, set a delay timer before morphing.
    setSceneVisible(BACK_MESH,VFX_TRUE);
    initBackgroundScene();
    configPolygonOffset();
    sceneMorphing();

    //load continuing halo of planet.
    loadHaloAnimation(BACK_MESH);

    // only load particle in 3d view
    if(!m_2dMode)
    {
        //load particle
        loadParticle();
        groupParticle->setVisible(VFX_TRUE);    
    }
    
    //close timer
    restoreTimer->stop();
    VFX_OBJ_CLOSE(restoreTimer);
}

void VappWidget3dClockContentPanel::onColonTimerTick(VfxTimer *obj)
{
        if (m_colonStatus)
        {
            m_meshColon->setVisible(VFX_TRUE);
            m_colonStatus = VFX_FALSE;
        }
        else
        {
            m_meshColon->setVisible(VFX_FALSE);
            m_colonStatus = VFX_TRUE;
        }
}
void VappWidget3dClockContentPanel::onParticleTimeout(VfxTimer *particleTimer)
{
    if(m_2dMode == VFX_FALSE)
    {
        //load particle
        loadParticle();
        groupParticle->setVisible(VFX_TRUE); 
    }
    
    particleTimer->stop();
    VFX_OBJ_CLOSE(particleTimer);
}

void VappWidget3dClockContentPanel::loadMorningToBack()
{
     //sky
     VFX_OBJ_CLOSE(m_materialSkyBack);
     VFX_OBJ_CREATE(m_materialSkyBack, VfxMaterial, m_meshSkyBack);
     VfxAssetLoader::loadMaterial(m_materialSkyBack,VAPP_WIDGET_3D_CLOCK_MORNING_SKY);     
     m_meshSkyBack->setMaterial(0, m_materialSkyBack);
     //addReflectionPass(m_materialSkyBack);
     
     //cloud
    VFX_OBJ_CLOSE(m_materialCloudBack);
    VFX_OBJ_CREATE(m_materialCloudBack, VfxMaterial, m_meshCloud1Back);
    VfxAssetLoader::loadMaterial(m_materialCloudBack,VAPP_WIDGET_3D_CLOCK_MORNING_CLOUD);
    m_meshCloud1Back->setMaterial(0,m_materialCloudBack);
    m_meshCloud2Back->setMaterial(0,m_materialCloudBack);
    //addReflectionPass(m_materialCloudBack);

    //Planet
    VFX_OBJ_CLOSE(m_materialPlanetBack);
    VFX_OBJ_CREATE(m_materialPlanetBack, VfxMaterial, m_meshPlanetBack);
    VfxAssetLoader::loadMaterial(m_materialPlanetBack,VAPP_WIDGET_3D_CLOCK_MORNING_PLANET);
    m_meshPlanetBack->setMaterial(0,m_materialPlanetBack);
    //addReflectionPass(m_materialPlanetBack);

    //loft
    VFX_OBJ_CLOSE(m_materialLoftBack);
    VFX_OBJ_CREATE(m_materialLoftBack, VfxMaterial, m_meshLoftBack);
    VfxAssetLoader::loadMaterial(m_materialLoftBack,VAPP_WIDGET_3D_CLOCK_MORNING_LOFT);
    m_meshLoftBack->setMaterial(0,m_materialLoftBack);
    //addReflectionPass(m_materialLoftBack);

    //Light
    VFX_OBJ_CLOSE(m_materialLightBack);
    VFX_OBJ_CREATE(m_materialLightBack, VfxMaterial, m_meshLight1Back);
    VfxAssetLoader::loadMaterial(m_materialLightBack,VAPP_WIDGET_3D_CLOCK_MORNING_LIGHT);
    m_meshLight1Back->setMaterial(0,m_materialLightBack);
    m_meshLight2Back->setMaterial(0,m_materialLightBack);
}

void VappWidget3dClockContentPanel::loadNoonToBack()
{
    //sky
    VFX_OBJ_CLOSE(m_materialSkyBack);
    VFX_OBJ_CREATE(m_materialSkyBack, VfxMaterial, m_meshSkyBack);
    VfxAssetLoader::loadMaterial(m_materialSkyBack, VAPP_WIDGET_3D_CLOCK_NOON_SKY);     
    m_meshSkyBack->setMaterial(0, m_materialSkyBack);
    //addReflectionPass(m_materialSkyBack);

    //cloud
    VFX_OBJ_CLOSE(m_materialCloudBack);
    VFX_OBJ_CREATE(m_materialCloudBack, VfxMaterial, m_meshCloud1Back);
    VfxAssetLoader::loadMaterial(m_materialCloudBack,VAPP_WIDGET_3D_CLOCK_NOON_CLOUD);
    m_meshCloud1Back->setMaterial(0,m_materialCloudBack);
    m_meshCloud2Back->setMaterial(0,m_materialCloudBack);
    //addReflectionPass(m_materialCloudBack);

    //planet
    VFX_OBJ_CLOSE(m_materialPlanetBack);
    VFX_OBJ_CREATE(m_materialPlanetBack, VfxMaterial, m_meshPlanetBack);
    VfxAssetLoader::loadMaterial(m_materialPlanetBack,VAPP_WIDGET_3D_CLOCK_NOON_PLANET);
    m_meshPlanetBack->setMaterial(0,m_materialPlanetBack);
    //addReflectionPass(m_materialPlanetBack);

    //loft
    VFX_OBJ_CLOSE(m_materialLoftBack);
    VFX_OBJ_CREATE(m_materialLoftBack, VfxMaterial, m_meshLoftBack);
    VfxAssetLoader::loadMaterial(m_materialLoftBack,VAPP_WIDGET_3D_CLOCK_NOON_LOFT);
    m_meshLoftBack->setMaterial(0,m_materialLoftBack);
    //addReflectionPass(m_materialLoftBack);

    //light
    VFX_OBJ_CLOSE(m_materialLightBack);
    VFX_OBJ_CREATE(m_materialLightBack, VfxMaterial, m_meshLight1Back);
    VfxAssetLoader::loadMaterial(m_materialLightBack,VAPP_WIDGET_3D_CLOCK_NOON_LIGHT);
    m_meshLight1Back->setMaterial(0,m_materialLightBack);
    m_meshLight2Back->setMaterial(0,m_materialLightBack);
}

void VappWidget3dClockContentPanel::loadSunsetToBack()
{
    //sky
    VFX_OBJ_CLOSE(m_materialSkyBack);
    VFX_OBJ_CREATE(m_materialSkyBack, VfxMaterial, m_meshSkyBack);
    VfxAssetLoader::loadMaterial(m_materialSkyBack,VAPP_WIDGET_3D_CLOCK_SUNSET_SKY);
    m_meshSkyBack->setMaterial(0, m_materialSkyBack);
    //addReflectionPass(m_materialSkyBack);

    //cloud
    VFX_OBJ_CLOSE(m_materialCloudBack);
    VFX_OBJ_CREATE(m_materialCloudBack, VfxMaterial, m_meshCloud1Back);
    VfxAssetLoader::loadMaterial(m_materialCloudBack,VAPP_WIDGET_3D_CLOCK_SUNSET_CLOUD);
    m_meshCloud1Back->setMaterial(0,m_materialCloudBack);
    m_meshCloud2Back->setMaterial(0,m_materialCloudBack);
    //addReflectionPass(m_materialCloudBack);

    //loft
    VFX_OBJ_CLOSE(m_materialLoftBack);
    VFX_OBJ_CREATE(m_materialLoftBack, VfxMaterial, m_meshLoftBack);
    VfxAssetLoader::loadMaterial(m_materialLoftBack,VAPP_WIDGET_3D_CLOCK_SUNSET_LOFT);
    m_meshLoftBack->setMaterial(0,m_materialLoftBack);  
    //addReflectionPass(m_materialLoftBack);

    //planet
    VFX_OBJ_CLOSE(m_materialPlanetBack);
    VFX_OBJ_CREATE(m_materialPlanetBack, VfxMaterial, m_meshPlanetBack);
    VfxAssetLoader::loadMaterial(m_materialPlanetBack,VAPP_WIDGET_3D_CLOCK_SUNSET_PLANET);
    m_meshPlanetBack->setMaterial(0,m_materialPlanetBack);
    //addReflectionPass(m_materialPlanetBack);

    //light
    VFX_OBJ_CLOSE(m_materialLightBack);
    VFX_OBJ_CREATE(m_materialLightBack, VfxMaterial, m_meshLight1Back);
    VfxAssetLoader::loadMaterial(m_materialLightBack,VAPP_WIDGET_3D_CLOCK_SUNSET_LIGHT);
    m_meshLight1Back->setMaterial(0,m_materialLightBack);
    m_meshLight2Back->setMaterial(0,m_materialLightBack);
}

void VappWidget3dClockContentPanel::loadNightToBack()
{
    //sky
    VFX_OBJ_CLOSE(m_materialSkyBack);
    VFX_OBJ_CREATE(m_materialSkyBack, VfxMaterial, m_meshSkyBack);
    VfxAssetLoader::loadMaterial(m_materialSkyBack,VAPP_WIDGET_3D_CLOCK_NIGHT_SKY);
    m_meshSkyBack->setMaterial(0, m_materialSkyBack);
    //addReflectionPass(m_materialSkyBack);

    //cloud
    VFX_OBJ_CLOSE(m_materialCloudBack);
    VFX_OBJ_CREATE(m_materialCloudBack, VfxMaterial, m_meshCloud1Back);
    VfxAssetLoader::loadMaterial(m_materialCloudBack,VAPP_WIDGET_3D_CLOCK_NIGHT_CLOUD);
    m_meshCloud1Back->setMaterial(0,m_materialCloudBack); 
    m_meshCloud2Back->setMaterial(0,m_materialCloudBack);
    //addReflectionPass(m_materialCloudBack);

    //planet
    VFX_OBJ_CLOSE(m_materialPlanetBack);
    VFX_OBJ_CREATE(m_materialPlanetBack, VfxMaterial, m_meshPlanetBack);
    VfxAssetLoader::loadMaterial(m_materialPlanetBack,VAPP_WIDGET_3D_CLOCK_NIGHT_PLANET);
    m_meshPlanetBack->setMaterial(0,m_materialPlanetBack);
    //addReflectionPass(m_materialPlanetBack);

    //loft
    VFX_OBJ_CLOSE(m_materialLoftBack);
    VFX_OBJ_CREATE(m_materialLoftBack, VfxMaterial, m_meshLoftBack);
    VfxAssetLoader::loadMaterial(m_materialLoftBack,VAPP_WIDGET_3D_CLOCK_NIGHT_LOFT);
    m_meshLoftBack->setMaterial(0,m_materialLoftBack);  
    //addReflectionPass(m_materialLoftBack);

    //light
    VFX_OBJ_CLOSE(m_materialLightBack);
    VFX_OBJ_CREATE(m_materialLightBack, VfxMaterial, m_meshLight1Back);
    VfxAssetLoader::loadMaterial(m_materialLightBack,VAPP_WIDGET_3D_CLOCK_NIGHT_LIGHT);
    m_meshLight1Back->setMaterial(0,m_materialLightBack);
    m_meshLight2Back->setMaterial(0,m_materialLightBack);
}

void VappWidget3dClockContentPanel::configAnimation()
{

    //Create Animation
    VFX_OBJ_CREATE(m_anim, VfxAnimation, sceneWorld);
    VfxAssetLoader::loadAnimation(m_anim, sceneWorld,VAPP_WIDGET_3D_CLOCK_ANI);

    //Create BG timeline to avoild timeline reset to 0 by VRT,
    //while widget turn back from in-active status.
    VFX_OBJ_CREATE(m_refTimeBg, VfxFloatTimeline, sceneWorld);
    m_refTimeBg->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTimeBg->setTarget(sceneWorld);
    m_refTimeBg->setDuration(2000);
    m_refTimeBg->setRepeatCount(1);

    // Create reference timeline for reverse.
    VFX_OBJ_CREATE(m_refTimeLine, VfxFloatTimeline, sceneWorld);
    m_refTimeLine->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTimeLine->setTarget(sceneWorld);
    m_refTimeLine->setAutoReversed(VFX_TRUE);
    m_refTimeLine->setRepeatCount(1);

    //Create reference timeline for angle.
    VFX_OBJ_CREATE(m_refTimeAngle, VfxFloatTimeline, sceneWorld);
    m_refTimeAngle->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTimeAngle->setTarget(sceneWorld);
    m_refTimeAngle->setAutoReversed(VFX_FALSE);
    m_refTimeAngle->setDuration(2000);// time for onNearnest view not RotateX
    m_refTimeAngle->setRepeatCount(1);

    //Create reference timelinfe to adujst the halo of planet. 
    VFX_OBJ_CREATE(m_timelineLight1, VfxFloatTimeline, sceneWorld);
    m_timelineLight1->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_timelineLight1->setTarget(this);
    m_timelineLight1->setDuration(1500);
    m_timelineLight1->setFromValue(0.0f);
    m_timelineLight1->setToValue(1.0f);
    m_timelineLight1->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    
    VFX_OBJ_CREATE(m_timelineLight2, VfxFloatTimeline, sceneWorld);
    m_timelineLight2->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_timelineLight2->setTarget(this);
    m_timelineLight2->setDuration(1500);
    m_timelineLight2->setFromValue(0.0f);
    m_timelineLight2->setToValue(1.0f);
    m_timelineLight2->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

    //load keyframe timeline of halo
    VFX_OBJ_CREATE(m_nightLight1, VfxKeyframeTimeline, sceneWorld);
    VfxAssetLoader::loadKeyframe(m_nightLight1, VAPP_WIDGET_3D_CLOCK_NIGHT_LIGHT1);
    VFX_OBJ_CREATE(m_nightLight2, VfxKeyframeTimeline, sceneWorld);
    VfxAssetLoader::loadKeyframe(m_nightLight2, VAPP_WIDGET_3D_CLOCK_NIGHT_LIGHT2);

    VFX_OBJ_CREATE(m_refTimeMtl, VfxFloatTimeline, sceneWorld);
    m_refTimeMtl->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTimeMtl->setTarget(sceneWorld);

}

void VappWidget3dClockContentPanel::playAnimation()
{

    if (m_2dMode) //2d to 3d //Swipe Up
    {
        m_refTimeLine->setDuration(6000);
        if(VFX_FALSE == m_isFirstAniPlayed) // for opening        
        {
            m_refTimeLine->setFromValue(0.0f);
            m_refTimeLine->setToValue(1.0f);
            m_isFirstAniPlayed = VFX_TRUE;
        }
        else
        {
            //change to isFromCurrent? and set duration
            if( m_swipeAngle <13.68){m_swipeAngle = 13.68;}
            m_refTimeLine->setFromValue(vfxAbs(m_swipeAngle/360));
            m_refTimeLine->setToValue(1.0f);
        }

        m_2dMode = VFX_FALSE;      
        m_btnSetTime->setBounds(VfxRect(0, 0, BTN_SET_TIME_SIZE_3D_X, BTN_SET_TIME_SIZE_3D_Y));
        m_btnSetTime->setPos(VfxPoint(BTN_SET_TIME_POS_3D_X, BTN_SET_TIME_POS_3D_Y));
        //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_CLOCK_ANI_ANGEL_2D,(int)m_swipeAngle);
        
        startParticleTimer();
        m_refTimeLine->m_signalStopped.connect(this,&VappWidget3dClockContentPanel::on1stAnimationStopped);
    }
    else         //3d to 2d  //Swipe Down
    {
        //disable particle
        groupParticle->setVisible(VFX_FALSE);
        m_refTlParticle->stop();
        m_refTimeLine->setDuration(2000);
        m_refTimeLine->setFromValue(0.17);
        m_refTimeLine->setToValue(0.0f);
        m_2dMode = VFX_TRUE;                
        m_btnSetTime->setBounds(VfxRect(0, 0, BTN_SET_TIME_SIZE_2D_X, BTN_SET_TIME_SIZE_2D_Y));
        m_btnSetTime->setPos(VfxPoint(BTN_SET_TIME_POS_2D_X, BTN_SET_TIME_POS_2D_Y));        
        //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_CLOCK_ANI_ANGEL_3D,(int)m_swipeAngle);        
    }
    m_anim->setTimelineTime(m_refTimeLine);
    m_refTimeLine->start();
}

void VappWidget3dClockContentPanel::setParticleAnimation(VfxBool isVisible,VfxBool isStart)
{
    if (isStart)
    {
        groupParticle->setVisible(isVisible);
        m_refTlParticle->start();
            
    }
    else
    {
        groupParticle->setVisible(isVisible);
        m_refTlParticle->stop();
    
    }
}

void VappWidget3dClockContentPanel::onTimeChanged(VfxU32 flag)
{
    //check if time changed.
    if (flag & VDAT_SYSTIME_CHANGED_MIN)
    {
        updateTime();
    }
}

void VappWidget3dClockContentPanel::onMorphingStopped(VfxBaseTimeline *source, VfxBool isComplete)
{
    if (isComplete)
    {
        setSceneVisible(FRONT_MESH,VFX_FALSE);        
        swapFrontBackMeshes();
    }
}

void VappWidget3dClockContentPanel::on1stAnimationStopped(VfxBaseTimeline *source, VfxBool isComplete)
{
    if(isComplete)
    {
        // in 3d view
        // set anim value from 1 to 1 to avoid it starts from 0, while widget returns from dailler.
        // Reason: VRT will clean the timeline to 0 when widget left home screen.
        if(m_2dMode == VFX_FALSE)
        {
            //load halo animation of planet.
            loadHaloAnimation(FRONT_MESH);
        }
    }
}

void VappWidget3dClockContentPanel::onBtnClicked(VfxObject *sender, VfxId id)
{
    MYTIME updateTime;
    GetDateTime(&updateTime);
    applib_time_struct curr_time2;
    applib_dt_get_rtc_time(&curr_time2);

    switch (id)
    {
        //lauch time setting menu while tapping time mesh.
        case BTN_SET_TIME:
            vapp_setting_launch_by_menu_id(SETTING_MENU_DATE_TIME_SETTING);
            break;
            
        //change to specific time for scene morphing
        case BTN_CHANGE_SCENE:
             switch (currTime.nHour)
            {
               case 0:
                    updateTime.nHour = 05;
                    updateTime.nMin = 59;
                    updateTime.nSec = 55;
                    break;
                case 6:
                    updateTime.nHour = 10;
                    updateTime.nMin = 59;                
                    updateTime.nSec = 55;
                    break;
                case 11:
                    updateTime.nHour = 15;
                    updateTime.nMin = 59;                
                    updateTime.nSec = 55;
                    break; 
                case 16:
                    updateTime.nHour = 19;
                    updateTime.nMin = 59;                
                    updateTime.nSec = 55;
                    break; 
                default:
                    updateTime.nHour = 05;
                    updateTime.nMin = 59;
                    updateTime.nSec = 55;                    
                    break;
            }
            break;
            
        case BTN_ADD_TO_55:
            updateTime.nSec = 55;
            break;

    }
mmi_dt_set_rtc_dt(&updateTime);
}

void VappWidget3dClockContentPanel::loadHaloAnimation(LoadToMeshEnum type)
{
    switch (type)
    {
        case FRONT_MESH:
            m_nightLight1->setTarget(m_meshLight1Front);
            m_nightLight2->setTarget(m_meshLight2Front);               
            break;
        case BACK_MESH:
            m_nightLight1->setTarget(m_meshLight1Back);
            m_nightLight2->setTarget(m_meshLight2Back);
            break;
        default:
            break;
    }

    m_nightLight1->setTimelineTime(m_timelineLight1);
    m_nightLight2->setTimelineTime(m_timelineLight2);
    m_timelineLight1->start();
    m_timelineLight2->start();
}
void VappWidget3dClockContentPanel::sceneMorphing(void)
{
    //Sky1-Sky2-loft1-loft2-planet1-planet2-light1-light2-cloud1(,1_1)-cloud2(,2_1)
    //1=noon 2=morning
    //noon->front , morning->back
    m_meshSkyFront->bringToFront();//sky1
    m_meshSkyBack->bringToFront();//sky2 
    m_meshLoftFront->bringToFront();//loft1
    m_meshLoftBack->bringToFront();//loft2
    m_meshPlanetFront->bringToFront();//Planet1
    m_meshPlanetBack->bringToFront();//Planet2
    m_meshLight1Front->bringToFront();//light1
    m_meshLight1Back->bringToFront();//light1_1
    m_meshLight2Front->bringToFront();//light2
    m_meshLight2Back->bringToFront();//light2_1
    m_meshCloud1Front->bringToFront();//cloud1
    m_meshCloud1Back->bringToFront();//cloud1_1
    m_meshCloud2Front->bringToFront();//cloud2
    m_meshCloud2Back->bringToFront();//cloud2_1 

    //Set opacity time for each mesh and start morphing
    VFX_OBJ_CLOSE(m_animBackground);
    VFX_OBJ_CREATE(m_animBackground, VfxAnimation, this);
    setOpacityTL(m_meshSkyFront,3000,1,0);
    setOpacityTL(m_meshSkyBack,3000,0,1);
    setOpacityTL(m_meshPlanetFront,3000,1,0);
    setOpacityTL(m_meshPlanetBack,3000,0,1);
    setOpacityTL(m_meshCloud1Front,3000,1,0);
    setOpacityTL(m_meshCloud1Back,3000,0,1);
    setOpacityTL(m_meshCloud2Front,3000,1,0);
    setOpacityTL(m_meshCloud2Back,3000,0,1);
    setOpacityTL(m_meshLight1Front,3000,1,0);
    setOpacityTL(m_meshLight1Back,3000,0,1);
    setOpacityTL(m_meshLight2Front,3000,1,0);
    VfxFloatTimeline *opacityTL = setOpacityTL(m_meshLight2Back,3000,0,1);

    //when last mesh morphing is stopped, hide the 2nd scene.
    opacityTL->m_signalStopped.connect(this,&VappWidget3dClockContentPanel::onMorphingStopped);
}

void VappWidget3dClockContentPanel::replaceMeshs()
{
    //Replace 4 background scenes 
    if(m_currentScene != m_newScene)
    {
        if(m_widgetActive == VFX_TRUE)
        {
            setSceneVisible(BACK_MESH,VFX_TRUE);
            initBackgroundScene();
            configPolygonOffset();
            sceneMorphing();

            //only load particle in 3d view
            if(!m_2dMode)
            {
                loadParticle();
                groupParticle->setVisible(VFX_TRUE);   
            }
            loadHaloAnimation(BACK_MESH);
        }
    }
  
    //Replace hours , mins, and meridian    
    if(m_parentH2 != NULL && m_parentH1 != NULL 
       && m_parentM1 != NULL && m_parentM2 != NULL && m_parentA != NULL)
    {
   
        //close replacement mesh before create a new one if it has been created.
        //Hour1
        VFX_OBJ_CLOSE(m_replaceH1);
        VFX_OBJ_CREATE(m_replaceH1, VfxMesh, m_parentH1);
        
        //Hour2
        VFX_OBJ_CLOSE(m_replaceH2);
        VFX_OBJ_CREATE(m_replaceH2, VfxMesh, m_parentH2);

        //Min1
        VFX_OBJ_CLOSE(m_replaceM1);
        VFX_OBJ_CREATE(m_replaceM1, VfxMesh, m_parentM1);
        
        //Min2
        VFX_OBJ_CLOSE(m_replaceM2);
        VFX_OBJ_CREATE(m_replaceM2, VfxMesh, m_parentM2);
        
        //Am
        VFX_OBJ_CLOSE(m_replaceA);
        VFX_OBJ_CREATE(m_replaceA, VfxMesh, m_parentA);

        //Replace mesh        
        switch (m_meridian)
        {
            case 0: //am
                VfxAssetLoader::loadMesh(m_replaceA, VAPP_WIDGET_3D_CLOCK_FONTA);

                break;
            case 1: //pm
                VfxAssetLoader::loadMesh(m_replaceA, VAPP_WIDGET_3D_CLOCK_FONTP);
                break;    
        }

        switch (m_intH1)
        {
            case 0:
                VfxAssetLoader::loadMesh(m_replaceH1, VAPP_WIDGET_3D_CLOCK_FONT0);

                break;
            case 1:
                VfxAssetLoader::loadMesh(m_replaceH1, VAPP_WIDGET_3D_CLOCK_FONT1);

                break;
            case 2:
                VfxAssetLoader::loadMesh(m_replaceH1, VAPP_WIDGET_3D_CLOCK_FONT2);

                break;
            case 3:
                VfxAssetLoader::loadMesh(m_replaceH1, VAPP_WIDGET_3D_CLOCK_FONT3);

                break;
            case 4:
                VfxAssetLoader::loadMesh(m_replaceH1, VAPP_WIDGET_3D_CLOCK_FONT4);

                break;
            case 5:
                VfxAssetLoader::loadMesh(m_replaceH1, VAPP_WIDGET_3D_CLOCK_FONT5);

                break;
            case 6:
                VfxAssetLoader::loadMesh(m_replaceH1, VAPP_WIDGET_3D_CLOCK_FONT6);

                break;
            case 7:
                VfxAssetLoader::loadMesh(m_replaceH1, VAPP_WIDGET_3D_CLOCK_FONT7);

                break;
            case 8:
                VfxAssetLoader::loadMesh(m_replaceH1, VAPP_WIDGET_3D_CLOCK_FONT8);

                break;
            case 9:
                VfxAssetLoader::loadMesh(m_replaceH1, VAPP_WIDGET_3D_CLOCK_FONT9);

                break;
        }

        switch (m_intH2)
        {
            case 0:
                VfxAssetLoader::loadMesh(m_replaceH2, VAPP_WIDGET_3D_CLOCK_FONT0);

                break;
            case 1:
                VfxAssetLoader::loadMesh(m_replaceH2, VAPP_WIDGET_3D_CLOCK_FONT1);

                break;
            case 2:
                VfxAssetLoader::loadMesh(m_replaceH2, VAPP_WIDGET_3D_CLOCK_FONT2);

                break;
            case 3:
                VfxAssetLoader::loadMesh(m_replaceH2, VAPP_WIDGET_3D_CLOCK_FONT3);

                break;
            case 4:
                VfxAssetLoader::loadMesh(m_replaceH2, VAPP_WIDGET_3D_CLOCK_FONT4);

                break;
            case 5:
                VfxAssetLoader::loadMesh(m_replaceH2, VAPP_WIDGET_3D_CLOCK_FONT5);

                break;
            case 6:
                VfxAssetLoader::loadMesh(m_replaceH2, VAPP_WIDGET_3D_CLOCK_FONT6);

                break;
            case 7:
                VfxAssetLoader::loadMesh(m_replaceH2, VAPP_WIDGET_3D_CLOCK_FONT7);

                break;
            case 8:
                VfxAssetLoader::loadMesh(m_replaceH2, VAPP_WIDGET_3D_CLOCK_FONT8);

                break;
            case 9:
                VfxAssetLoader::loadMesh(m_replaceH2, VAPP_WIDGET_3D_CLOCK_FONT9);

                break;
        }        

        switch (m_intM1)
        {
            case 0:
                VfxAssetLoader::loadMesh(m_replaceM1, VAPP_WIDGET_3D_CLOCK_FONT0);

                break;
            case 1:
                VfxAssetLoader::loadMesh(m_replaceM1, VAPP_WIDGET_3D_CLOCK_FONT1);

                break;
            case 2:
                VfxAssetLoader::loadMesh(m_replaceM1, VAPP_WIDGET_3D_CLOCK_FONT2);

                break;
            case 3:
                VfxAssetLoader::loadMesh(m_replaceM1, VAPP_WIDGET_3D_CLOCK_FONT3);

                break;
            case 4:
                VfxAssetLoader::loadMesh(m_replaceM1, VAPP_WIDGET_3D_CLOCK_FONT4);

                break;
            case 5:
                VfxAssetLoader::loadMesh(m_replaceM1, VAPP_WIDGET_3D_CLOCK_FONT5);

                break;
            case 6:
                VfxAssetLoader::loadMesh(m_replaceM1, VAPP_WIDGET_3D_CLOCK_FONT6);

                break;
            case 7:
                VfxAssetLoader::loadMesh(m_replaceM1, VAPP_WIDGET_3D_CLOCK_FONT7);

                break;
            case 8:
                VfxAssetLoader::loadMesh(m_replaceM1, VAPP_WIDGET_3D_CLOCK_FONT8);

                break;
            case 9:
                VfxAssetLoader::loadMesh(m_replaceM1, VAPP_WIDGET_3D_CLOCK_FONT9);

                break;
        }

        switch (m_intM2)
        {
            case 0:
                VfxAssetLoader::loadMesh(m_replaceM2, VAPP_WIDGET_3D_CLOCK_FONT0);

                break;
            case 1:
                VfxAssetLoader::loadMesh(m_replaceM2, VAPP_WIDGET_3D_CLOCK_FONT1);

                break;
            case 2:
                VfxAssetLoader::loadMesh(m_replaceM2, VAPP_WIDGET_3D_CLOCK_FONT2);

                break;
            case 3:
                VfxAssetLoader::loadMesh(m_replaceM2, VAPP_WIDGET_3D_CLOCK_FONT3);

                break;
            case 4:
                VfxAssetLoader::loadMesh(m_replaceM2, VAPP_WIDGET_3D_CLOCK_FONT4);

                break;
            case 5:
                VfxAssetLoader::loadMesh(m_replaceM2, VAPP_WIDGET_3D_CLOCK_FONT5);

                break;
            case 6:
                VfxAssetLoader::loadMesh(m_replaceM2, VAPP_WIDGET_3D_CLOCK_FONT6);

                break;
            case 7:
                VfxAssetLoader::loadMesh(m_replaceM2, VAPP_WIDGET_3D_CLOCK_FONT7);

                break;
            case 8:
                VfxAssetLoader::loadMesh(m_replaceM2, VAPP_WIDGET_3D_CLOCK_FONT8);

                break;
            case 9:
                VfxAssetLoader::loadMesh(m_replaceM2, VAPP_WIDGET_3D_CLOCK_FONT9);

                break;      
        } 

        setFontModelTransform();

    }
    
    //After replacing background material, the sky can be seen in 2d view (uOpacity=1)
    //To avoid this, thererfore,re-create animation to re-apply new material into animation
    //Then, play the aniamtion with value 0 , or bind new font mtl to animation.
    //bind material & ambient back to animation while 'each' mesh has been replaced (e.g. 00:01-->00:02)
    VFX_OBJ_CLOSE(m_anim);        
    VFX_OBJ_CREATE(m_anim, VfxAnimation, sceneWorld);
    VfxAssetLoader::loadAnimation(m_anim, sceneWorld,VAPP_WIDGET_3D_CLOCK_ANI);        
    
    // bind ambient when mesh has been replaced.
    setAmbient();    

    // bind material 
    if (m_2dMode == VFX_TRUE)
    {
        m_refTimeMtl->setFromValue(0.0f);
        m_refTimeMtl->setToValue(0.0f);
    }
    else
    {
        m_refTimeMtl->setFromValue(1.0f);
        m_refTimeMtl->setToValue(1.0f);
    }
    m_refTimeMtl->setRepeatCount(1);
    m_anim->setTimelineTime(m_refTimeMtl);
    m_refTimeMtl->start();
}

void VappWidget3dClockContentPanel::getFontModelTransform()
{
    m_pivotH1 = m_meshH1->getPivot();
    m_pivotH2 = m_meshH2->getPivot();
    m_pivotM1 = m_meshM1->getPivot();
    m_pivotM2 = m_meshM2->getPivot();
    m_pivotA = m_meshA->getPivot();

    m_quatH1 = m_meshH1->getRotation();
    m_quatH2 = m_meshH2->getRotation();
    m_quatM1 = m_meshM1->getRotation();
    m_quatM2 = m_meshM2->getRotation();
    m_quatA = m_meshA->getRotation();
    
    m_scaleH1 = m_meshH1->getScale();
    m_scaleH2 = m_meshH2->getScale();
    m_scaleM1 = m_meshM1->getScale();
    m_scaleM2 = m_meshM2->getScale();
    m_scaleA= m_meshA->getScale();
    
    m_translationH1 = m_meshH1->getTranslation();
    m_translationH2 = m_meshH2->getTranslation();
    m_translationM1 = m_meshM1->getTranslation();
    m_translationM2 = m_meshM2->getTranslation();
    m_translationA = m_meshA->getTranslation();    
}

void VappWidget3dClockContentPanel::setFontModelTransform()
{
    m_replaceH1->setPivot(m_pivotH1);
    m_replaceH1->setRotation(m_quatH1);
    m_replaceH1->setTranslation(m_translationH1);
    m_replaceH1->setScale(m_scaleH1);

    m_replaceH2->setPivot(m_pivotH2);
    m_replaceH2->setRotation(m_quatH2);
    m_replaceH2->setTranslation(m_translationH2);
    m_replaceH2->setScale(m_scaleH2);        

    m_replaceM1->setPivot(m_pivotM1);
    m_replaceM1->setRotation(m_quatM1);
    m_replaceM1->setTranslation(m_translationM1);
    m_replaceM1->setScale(m_scaleM1);        

    m_replaceM2->setPivot(m_pivotM2);
    m_replaceM2->setRotation(m_quatM2);
    m_replaceM2->setTranslation(m_translationM2);
    m_replaceM2->setScale(m_scaleM2);

    m_replaceA->setPivot(m_pivotA);
    m_replaceA->setRotation(m_quatA);
    m_replaceA->setTranslation(m_translationA);
    m_replaceA->setScale(m_scaleA);

    // set each font mesh material
    setFontMaterial();

    //set target look up
    #if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
}

void VappWidget3dClockContentPanel::setSwipeAngle(VfxFloat stageAngel)
{
    m_swipeAngle = stageAngel;
}

void VappWidget3dClockContentPanel::setAmbient()
{
    VfxResId ambientTl1 = 0,ambientTl2 =0;
    if (currTime.nHour >=6 && currTime.nHour<11)         //morning
    {
        ambientTl1 = VAPP_WIDGET_3D_CLOCK_MORNING_AMBIENT;
        ambientTl2 = VAPP_WIDGET_3D_CLOCK_MORNING_AMBIENT_1;
    }
    else if (currTime.nHour >=11 && currTime.nHour<16)   //noon
    {
        ambientTl1 = VAPP_WIDGET_3D_CLOCK_NOON_AMBIENT;
        ambientTl2 = VAPP_WIDGET_3D_CLOCK_NOON_AMBIENT_1;
    }
    else if (currTime.nHour >=16 && currTime.nHour <20)  //sunsest
    {
        ambientTl1 = VAPP_WIDGET_3D_CLOCK_SUNSET_AMBIENT;
        ambientTl2 = VAPP_WIDGET_3D_CLOCK_SUNSET_AMBIENT_1;

    }        
    else if (currTime.nHour >=20 || currTime.nHour <=5)  //night
    {
        ambientTl1 = VAPP_WIDGET_3D_CLOCK_NIGHT_AMBIENT;
        ambientTl2 = VAPP_WIDGET_3D_CLOCK_NIGHT_AMBIENT_1;

    }

    VfxShaderVariable *varAmbient = NULL;
    VfxShaderVariable *var2Ambient2 = NULL;
    
    varAmbient = m_materialH1->getPass(0)->getUniformVariable(VFX_STR("uAmbient"));
    var2Ambient2 = m_materialH1_2->getPass(0)->getUniformVariable(VFX_STR("uAmbient"));

    //VFX_OBJ_CLOSE(m_tlAmbient);// if added-> Assert here cuz m_anim has been closed
    VFX_OBJ_CREATE(m_tlAmbient, VfxKeyframeTimeline, m_anim);
    VfxAssetLoader::loadKeyframe(m_tlAmbient,ambientTl1);
    m_tlAmbient->setTarget(varAmbient);

    VFX_OBJ_CREATE(m_tlAmbient2, VfxKeyframeTimeline, m_anim);
    VfxAssetLoader::loadKeyframe(m_tlAmbient2,ambientTl2);
    m_tlAmbient2->setTarget(var2Ambient2);
}

void VappWidget3dClockContentPanel::setAmPmOpacity()
{

    // set AM mesh darker if it is 24hr-time in 2d mode .
    // AM mesh cannot be seen if it is 24hr-time in 3d mode.
    if(m_isAmExist) //am exist, set opacity1 in either 2d or 3d mode
    {
        m_replaceA->setOpacity(1.0);
        m_meshM->setOpacity(1.0);//never replace meshM when time ticking.

    }
    else         //am not exist, 24hr-time
    {
        m_replaceA->setOpacity(0.1);
        m_meshM->setOpacity(0.1);
    }
}

void VappWidget3dClockContentPanel::setFontMaterial()
{
        
        VfxResId fontMtl1 = 0 ,fontMtl2 = 0;

        if (currTime.nHour >=6 && currTime.nHour<11)         //morning
        {
            fontMtl1 = VAPP_WIDGET_3D_CLOCK_FONT_MTL_MORNING1;
            fontMtl2 = VAPP_WIDGET_3D_CLOCK_FONT_MTL_MORNING2;
        }
        else if (currTime.nHour >=11 && currTime.nHour<16)   //noon
        {
            fontMtl1 = VAPP_WIDGET_3D_CLOCK_FONT_MTL_NOON1;
            fontMtl2 = VAPP_WIDGET_3D_CLOCK_FONT_MTL_NOON2;
        }
        else if (currTime.nHour >=16 && currTime.nHour <20)  //sunsest
        {
            fontMtl1 = VAPP_WIDGET_3D_CLOCK_FONT_MTL_SUNSET1;
            fontMtl2 = VAPP_WIDGET_3D_CLOCK_FONT_MTL_SUNSET2;
        }        
        else if (currTime.nHour >=20 || currTime.nHour <=5)   //night
        {
            fontMtl1 = VAPP_WIDGET_3D_CLOCK_FONT_MTL_NIGHT1;
            fontMtl2 = VAPP_WIDGET_3D_CLOCK_FONT_MTL_NIGHT2;
        }

        //must add after load mesh, otherwise only 1 material can be loaded.
        //note:cant close m_materlH1 cuz replaceH1 has been closed
        VFX_OBJ_CREATE(m_materialH1, VfxMaterial, m_replaceH1);//m_replaceH1
        VfxAssetLoader::loadMaterial(m_materialH1,fontMtl1);
        m_materialH1->getPass(0)->getUniformVariable(VFX_STR("uLightPos"))->bindValue(m_light, VFX_BINDING_WORLD_SPACE_POSITION);
        m_replaceH1->setMaterial(0, m_materialH1);
        
        //addReflectionPass(m_materialH1);

        VFX_OBJ_CREATE(m_materialH1_2, VfxMaterial, m_replaceH1); //m_replaceH1_2
        VfxAssetLoader::loadMaterial(m_materialH1_2,fontMtl2);
        m_materialH1_2->getPass(0)->getUniformVariable(VFX_STR("uLightPos"))->bindValue(m_light, VFX_BINDING_WORLD_SPACE_POSITION);
        m_replaceH1->setMaterial(1, m_materialH1_2);
        
        //addReflectionPass(m_materialH1_2);
        
        m_replaceH2->setMaterial(0, m_materialH1);
        m_replaceH2->setMaterial(1, m_materialH1_2);
        m_replaceM1->setMaterial(0, m_materialH1);
        m_replaceM1->setMaterial(1, m_materialH1_2);
        m_replaceM2->setMaterial(0, m_materialH1);
        m_replaceM2->setMaterial(1, m_materialH1_2);
        m_replaceA->setMaterial(0, m_materialH1);
        m_replaceA->setMaterial(1, m_materialH1_2);
        m_meshM->setMaterial(0, m_materialH1);
        m_meshM->setMaterial(1, m_materialH1_2);
        m_meshColon->setMaterial(0, m_materialH1);    
        m_meshColon->setMaterial(1, m_materialH1_2);
}


/*****************************************************************************
 * 3D  Clock Widget
 *****************************************************************************/

VAPP_WIDGET_SYS_PUBLISH_NATIVE(
    VappWidget3dClock,
    VAPP_WIDGET_TYPE_3D_CLOCK,
    VappWidget3dClockPublisher);

VAPP_WIDGET_IMPLEMENT_CLASS(VappWidget3dClock,VappWidgetMiniStage);

VappWidget3dClock::VappWidget3dClock() :
    m_contentPanel(NULL),
    firstRotate(VFX_FALSE),
    stageAngle(0),
    oldAngle(0),
    newAngle(0)
{
    // Do nothing.
}

VappWidgetId VappWidget3dClock::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_3D_CLOCK);
}


VfxSize VappWidget3dClock::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}

VfxS32 VappWidget3dClock::getName(VfxWChar *string, VfxS32 size) const
{

    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_3D_CLOCK);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);
}

VfxFrame *VappWidget3dClock::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;
    VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_3D_CLOCK_ICON);

    return icon;
}

void VappWidget3dClock::onCreateView()
{
    CLOCK_MEASURE_TIME_START("CCR");
    VappWidgetMiniStage::onCreateView();

    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));

    // create 3d content panel 
    VFX_OBJ_CREATE(m_contentPanel, VappWidget3dClockContentPanel,this);
    m_contentPanel->setSize(WIDTH,HEIGHT);
    m_contentPanel->setPos(0,0);

    CLOCK_MEASURE_TIME_STOP("CCR");
}

void VappWidget3dClock::onSerializeView(VfxArchive *ar)
{
    m_contentPanel->m_widgetActive = VFX_FALSE;

}

void VappWidget3dClock::onSerializeViewForPageSwitch(VfxArchive *ar)
{
    CLOCK_MEASURE_TIME_START("CSE");

    m_contentPanel->m_widgetActive = VFX_FALSE;

    CLOCK_MEASURE_TIME_STOP("CSE");
}

void VappWidget3dClock::onSwipeUp()
{
    //2d mode to 3d mode
    if (m_contentPanel->m_2dMode == VFX_TRUE)
    {
        //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_CLOCK_SWIPEUP_ENTRY);    
        //Create Animation to re-apply new material into animation
        VFX_OBJ_CLOSE(m_contentPanel->m_anim);
        VFX_OBJ_CREATE(m_contentPanel->m_anim, VfxAnimation, m_contentPanel->sceneWorld);
        VfxAssetLoader::loadAnimation(m_contentPanel->m_anim, m_contentPanel->sceneWorld,VAPP_WIDGET_3D_CLOCK_ANI);

        //add ambient to scene after animation changed
        m_contentPanel->setAmbient();
        
        //play animation

        m_contentPanel->setSwipeAngle(stageAngle);
        m_contentPanel->playAnimation();
        
    }
    oldAngle = 0;
    newAngle = 0;
    stageAngle = 0;
    firstRotate = VFX_FALSE;
}

void VappWidget3dClock::onSwipeDown()
{
    //3d mode to 2d mode
    if (m_contentPanel->m_2dMode == VFX_FALSE)
    {
        //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_CLOCK_SWIPEDOWN_ENTRY);    
        //Create Animation to re-apply new material into animation
        VFX_OBJ_CLOSE(m_contentPanel->m_anim);        
        VFX_OBJ_CREATE(m_contentPanel->m_anim, VfxAnimation, m_contentPanel->sceneWorld);
        VfxAssetLoader::loadAnimation(m_contentPanel->m_anim, m_contentPanel->sceneWorld,VAPP_WIDGET_3D_CLOCK_ANI);

        //add ambient to scene after animation changed
        m_contentPanel->setAmbient();

        //play animation    
        m_contentPanel->setSwipeAngle(stageAngle);
        m_contentPanel->playAnimation();
    }
    oldAngle = 0;
    newAngle = 0;
    stageAngle =0;//did not work
    firstRotate = VFX_FALSE;
}

void VappWidget3dClock::onSwipeToNearestView()
{

    //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_CLOCK_NEAREST_ENTRY); 
    
    if(m_contentPanel->m_2dMode == VFX_TRUE)                            //in 2d mode
    {
        if(stageAngle > 30.8) //if angle >45 degree then swipe up to 3d view
        {
            m_contentPanel->m_refTimeAngle->stop();
            m_contentPanel->m_refTimeAngle->setDuration(6000);            
            //m_contentPanel->m_refTimeAngle->setFromValue(stageAngle/270);//1010
            m_contentPanel->m_refTimeAngle->setIsFromCurrent(VFX_TRUE);
            m_contentPanel->m_refTimeAngle->setToValue(1.0f);
            m_contentPanel->m_refTimeAngle->start();
            m_contentPanel->m_2dMode = VFX_FALSE;

            //config particle animation,setVisible and isStart
            m_contentPanel->setParticleAnimation(VFX_TRUE,VFX_TRUE);  
        }
        else
        {
            m_contentPanel->m_refTimeAngle->stop();
            m_contentPanel->m_refTimeAngle->setDuration(2000);              
            //m_contentPanel->m_refTimeAngle->setFromValue(stageAngle/270);//1010
            m_contentPanel->m_refTimeAngle->setIsFromCurrent(VFX_TRUE);
            m_contentPanel->m_refTimeAngle->setToValue(0.0f);
            m_contentPanel->m_refTimeAngle->start();
            m_contentPanel->m_2dMode = VFX_TRUE;   

            //config particle animation,setVisible and isStart 
            m_contentPanel->setParticleAnimation(VFX_FALSE,VFX_FALSE); 
        }
        //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_CLOCK_NEAREST_ANGEL_2D,(int)stageAngle); 
    }
    else                                                                //in 3d mode
    {
        if(stageAngle >23.2) //if angle >60 degree then swipe down to 2d view
        {
            m_contentPanel->m_refTimeAngle->stop();
            m_contentPanel->m_refTimeAngle->setDuration(3500);              
            m_contentPanel->m_refTimeAngle->setIsFromCurrent(VFX_TRUE);
            m_contentPanel->m_refTimeAngle->setToValue(0.0f);

            m_contentPanel->m_refTimeAngle->start();
            m_contentPanel->m_2dMode = VFX_TRUE;

            m_contentPanel->setParticleAnimation(VFX_FALSE,VFX_FALSE); //setVisible and isStart            
        }
        else
        {
            m_contentPanel->m_refTimeAngle->stop();
            m_contentPanel->m_refTimeAngle->setDuration(6000);
            //m_contentPanel->m_refTimeAngle->setFromValue(vfxAbs((stageAngle/270)-0.38));///-1//1011
            m_contentPanel->m_refTimeAngle->setIsFromCurrent(VFX_TRUE);
            m_contentPanel->m_refTimeAngle->setToValue(1.0f);
            m_contentPanel->m_refTimeAngle->start();
            m_contentPanel->m_2dMode = VFX_FALSE;

            m_contentPanel->setParticleAnimation(VFX_TRUE,VFX_TRUE); //setVisible and isStart
        }
    //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_CLOCK_NEAREST_ANGEL_3D,(int)stageAngle); 
    }
    oldAngle = 0;
    newAngle = 0;
    firstRotate = VFX_FALSE;

}
void VappWidget3dClock::onRotateX(VfxFloat angle)
{
     
}

VfxPoint VappWidget3dClock::onGetEditButtonOffset()
{
    return VfxPoint(getSize().width - EDIT_BTN_OFFSET_X, EDIT_BTN_OFFSET_Y);
}


void VappWidget3dClock::onSuspend()
{
    setCacheMode(VFX_CACHE_MODE_FREEZE);
}
void VappWidget3dClock::onResume()
{
    setCacheMode(VFX_CACHE_MODE_AUTO);
}


void VappWidget3dClock::onRestoreView(VfxArchive *ar)
{
    m_contentPanel->m_widgetActive = VFX_TRUE;
    
    //updateTime for scene morphing.
    m_contentPanel->updateTime();
}

void VappWidget3dClock::onRestoreViewForPageSwitch(VfxArchive *ar)
{
    CLOCK_MEASURE_TIME_START("CRS");

    m_contentPanel->m_widgetActive = VFX_TRUE;
    
    //updateTime for scene morphing.
    m_contentPanel->updateTime();

    CLOCK_MEASURE_TIME_STOP("CRS");    
}
void VappWidget3dClock::onReleaseView()
{
    CLOCK_MEASURE_TIME_START("CRL");

    VFX_OBJ_CLOSE(m_contentPanel);
    VappWidgetMiniStage::onReleaseView();

    CLOCK_MEASURE_TIME_STOP("CRL");
}
#endif /* defined(__MMI_VUI_WIDGET_3D_CLOCK__) */

