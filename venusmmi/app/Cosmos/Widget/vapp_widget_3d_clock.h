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
 *  vapp_widget_3d_clock.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the 3d clock widget
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef VAPP_WIDGET_3D_CLOCK_H
#define VAPP_WIDGET_3D_CLOCK_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_3D_CLOCK__)


/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"

#include "vapp_widget_def.h"
#include "vapp_widget.h"
#include "vapp_widget_mini_stage.h"

//stencil & particle
class VfxGroup;
class VfxLight;
class VfxCompositingMode;
class VfxRenderMode;
class VfxShaderUniforms;

/*****************************************************************************
 * 3D Clock Widget ContentPanel
 *****************************************************************************/
class VappWidget3dClockContentPanel : public VfxControl
{
    VFX_DECLARE_CLASS(VappWidget3dClockContentPanel);

public:
    enum LoadToMeshEnum
    {
        FRONT_MESH =1,
        BACK_MESH =2
    };


public:
    VappWidget3dClockContentPanel();
    ~VappWidget3dClockContentPanel();    
    virtual void onInit();
    void updateTime();
    void playAnimation();
    void sceneMorphing(void);
    void configPolygonOffset(); 
    void onRestoreDelayTimer(
        VfxTimer *timer
        );      
    void setSwipeAngle(
        VfxFloat swipeAngle
        );
    
    void setParticleAnimation(
        VfxBool isVisible,
        VfxBool isStart
        );    
    void setAmbient();
    void rotateViewAngle(const VfxVector3f axis, const VfxFloat theta);

    void changeViewAngle(const VfxVector3f axis, const VfxFloat theta, const VfxBool treatAsEnd = VFX_FALSE);
    void changeViewAngle2(VfxBaseTimeline *timeline, VfxBool isStop);
    void swipCamera(const VfxId id);
    void setSceneVisible(
            LoadToMeshEnum type, 
            VfxBool isHide);

    
private:
    void onTimeChanged(
        VfxU32 flag
        );
    void startColonTimer();
    void replaceMeshs();
    void loadMorningToBack();
    void loadNoonToBack();
    void loadSunsetToBack();
    void loadNightToBack();    
    void loadParticle();
    void startParticleTimer();
    void onParticleTimeout(
        VfxTimer *particleTimer
    );

    void onColonTimerTick(
        VfxTimer *timer
    );

    void onTimerCallBackOpacity(
        VfxTimer *opTimer
     );
    void onBtnClicked(
        VfxObject *sender, 
        VfxId id);
    void on1stAnimationStopped(
        VfxBaseTimeline *source, 
        VfxBool isComplete);    
    void onMorphingStopped(
        VfxBaseTimeline *source, 
        VfxBool isComplete);       
    void initTextureFrame(); 
    void initStageReflection(void);
    void initBackgroundScene(void);  
  
    void setFontModelTransform();
    void getFontModelTransform();
    void getMeshsFromScene();

    void configAnimation(void);

    void addReflectionPass(
        VfxMaterial *material
        );

    VfxFloatTimeline *setOpacityTL(
        VfxMesh *targetMesh,
        const VfxMsec duration,
        const VfxFloat fromValue,
        const VfxFloat toValue);
    
    void setPolygonOffset(
        VfxMaterial *front,
        VfxMaterial *back);

    void setFontMaterial(void);
    void loadHaloAnimation(LoadToMeshEnum type);
    /*void setSceneVisible(
        LoadToMeshEnum type, 
        VfxBool isHide);*/
    void swapFrontBackMeshes(void);
    void setAmPmOpacity();
    void onLoad1stAni(VfxTimer *timer);

//Variable
public:
    VfxTextFrame *m_frmText;
    VfxBool m_2dMode;
    VfxBool m_widgetActive;
    VfxWorld *sceneWorld;    
    VfxAnimation *m_animBackground;
    VfxAnimation *m_anim;
    VfxAnimation *m_animParticle;    
    VfxFloatTimeline *m_refTimeLine; 
    VfxFloatTimeline *m_refTimeBg;
    VfxFloatTimeline *m_refTimeMtl;    
    VfxFloatTimeline *m_refTimeAngle;
    VfxFloatTimeline *m_refTlParticle;    
	VfxS8 m_currentScene;
	VfxS8 m_newScene;

private:
    applib_time_struct currTime;

    VfxTextFrame *m_weekTextFrame;
    VfxTextFrame *m_dateTextFrame;    
    VfxFloat m_swipeAngle;
    //VfxWString am_str;
    VfxBool m_isFirstAniPlayed;
    VfxBool m_isAmExist;
   	kal_uint8 m_intH1;
	kal_uint8 m_intH2;
	kal_uint8 m_intM1;
	kal_uint8 m_intM2;
    kal_uint8 m_intSec;

    kal_uint8 m_intDay;
	kal_uint8 m_meridian; // 1 =pm 0=am
 
    VfxBool m_colonStatus;
    VcpButton *m_btnSetTime;
    
    VfxGroup *groupParticle;
    //parent of font mesh
    VfxNode *m_parentH1;
    VfxNode *m_parentH2;
    VfxNode *m_parentM1;
    VfxNode *m_parentM2;    
    VfxNode *m_parentA;
   
    //find obj mesh by name
    VfxMesh *m_meshH1;
    VfxMesh *m_meshH2; 
    VfxMesh *m_meshC;
    VfxMesh *m_meshM1;
    VfxMesh *m_meshM2;  
    VfxMesh *m_meshA;
    VfxMesh *m_meshM;
    VfxMesh *m_meshColon; 
    VfxLight *m_light;

    VfxMesh *m_meshStage;    
    
    VfxMesh *m_meshSkyFront;
    VfxMesh *m_meshSkyBack;    
    VfxMesh *m_meshCloud1Front;
    VfxMesh *m_meshCloud2Front;
    VfxMesh *m_meshCloud1Back;
    VfxMesh *m_meshCloud2Back;
    VfxMesh *m_meshPlanetFront;   
    VfxMesh *m_meshPlanetBack;  
    VfxMesh *m_meshLoftFront;
    VfxMesh *m_meshLoftBack;
    VfxMesh *m_meshLight1Front;
    VfxMesh *m_meshLight2Front;    
    VfxMesh *m_meshLight1Back;
    VfxMesh *m_meshLight2Back;    
    VfxMesh *m_meshDate;
    VfxMesh *m_meshWeek;
    
    // pivot
    VfxMatrix4f m_pivotH1;
    VfxMatrix4f m_pivotH2;
    VfxMatrix4f m_pivotM1;        
    VfxMatrix4f m_pivotM2;            
    VfxMatrix4f m_pivotA;                
    
    //rotation
    VfxQuaternionf m_quatH1;
    VfxQuaternionf m_quatH2;    
    VfxQuaternionf m_quatM1;    
    VfxQuaternionf m_quatM2;    
    VfxQuaternionf m_quatA;    

    //scale
    VfxVector3f m_scaleH1;
    VfxVector3f m_scaleH2;    
    VfxVector3f m_scaleM1;
    VfxVector3f m_scaleM2;   
    VfxVector3f m_scaleA;    

    //translation
    VfxVector3f m_translationH1;
    VfxVector3f m_translationH2;
    VfxVector3f m_translationM1;
    VfxVector3f m_translationM2;    
    VfxVector3f m_translationA;
    
    //font materials
    VfxMaterial *m_materialH1; //multi-material into one mesh
    VfxMaterial *m_materialH1_2;

    //scene materials
    VfxMaterial *m_materialSkyFront;
    VfxMaterial *m_materialSkyBack;
    VfxMaterial *m_materialPlanetFront;
    VfxMaterial *m_materialPlanetBack;
    VfxMaterial *m_materialCloudFront;
    VfxMaterial *m_materialCloudBack;    
    VfxMaterial *m_materialLightFront;
    VfxMaterial *m_materialLightBack;
    VfxMaterial *m_materialLoftFront;
    VfxMaterial *m_materialLoftBack;    

    VfxCompositingMode *m_polyOffset;

    VfxRenderMode *m_reflectScope;
    VfxShaderUniforms *m_reflectUniforms;

    //replacement
    VfxMesh *m_replaceH1;
    VfxMesh *m_replaceH2;
    VfxMesh *m_replaceM1;    
    VfxMesh *m_replaceM2;    
    VfxMesh *m_replaceA;  
  
    VfxKeyframeTimeline *m_nightLight1;
    VfxKeyframeTimeline *m_nightLight2;
    VfxFloatTimeline *m_timelineLight1;
    VfxFloatTimeline *m_timelineLight2;
    VfxKeyframeTimeline *m_tlAmbient;
    VfxKeyframeTimeline *m_tlAmbient2;

    enum
    {
        MORNING = 6,
        NOON= 11,
        SUNSET = 16,
        NIGHTFALL = 20,
        WIDTH = 480,
        HEIGHT = 440,
        BTN_SET_TIME,
        BTN_CHANGE_SCENE,
        BTN_ADD_TO_55
    };

    enum
    {
        #if defined(__MMI_MAINLCD_480X800__)
            BTN_SET_TIME_SIZE_2D_X = 320,
            BTN_SET_TIME_SIZE_2D_Y = 145,
            BTN_SET_TIME_POS_2D_X = 85,
            BTN_SET_TIME_POS_2D_Y = 120,

            BTN_SET_TIME_SIZE_3D_X = 320,
            BTN_SET_TIME_SIZE_3D_Y = 115,
            BTN_SET_TIME_POS_3D_X = 85,
            BTN_SET_TIME_POS_3D_Y = 170,
            MESH_WEEK_SIZE_X = 168,
	    MESH_WEEK_SIZE_Y = 40,
	    MESH_DATE_SIZE_X = 168,
	    MESH_DATE_SIZE_Y = 40,
	    FONT_SIZE_WEEK = 30,
	    FONT_SIZE_DATE = 30,

        #elif defined(__MMI_MAINLCD_320X480__) 
            BTN_SET_TIME_SIZE_2D_X = 220,
            BTN_SET_TIME_SIZE_2D_Y = 95,
            BTN_SET_TIME_POS_2D_X = 55,
            BTN_SET_TIME_POS_2D_Y = 110,

            BTN_SET_TIME_SIZE_3D_X = 230,
            BTN_SET_TIME_SIZE_3D_Y = 88,
            BTN_SET_TIME_POS_3D_X = 50,
            BTN_SET_TIME_POS_3D_Y = 132,         
	    MESH_WEEK_SIZE_X = 168,
	    MESH_WEEK_SIZE_Y = 40,
	    MESH_DATE_SIZE_X = 168,
	    MESH_DATE_SIZE_Y = 40,
	    FONT_SIZE_WEEK = 30,
	    FONT_SIZE_DATE = 30,

        #else //WQVGA & QVGA
            BTN_SET_TIME_SIZE_2D_X = 140,
            BTN_SET_TIME_SIZE_2D_Y = 70,
            BTN_SET_TIME_POS_2D_X = 35,
            BTN_SET_TIME_POS_2D_Y = 60,
            
            BTN_SET_TIME_SIZE_3D_X = 120,
            BTN_SET_TIME_SIZE_3D_Y = 65,
            BTN_SET_TIME_POS_3D_X = 50,
            BTN_SET_TIME_POS_3D_Y = 75,
            MESH_WEEK_SIZE_X = 210,     //origin mesh size is 70*12 in Q&WQVGA
	    MESH_WEEK_SIZE_Y = 36,
	    MESH_DATE_SIZE_X = 150,     //orgin mesh size is 50*12
	    MESH_DATE_SIZE_Y = 36,
	    FONT_SIZE_WEEK = 33,        //different from WVGA & HVGA
	    FONT_SIZE_DATE = 27,
			
        #endif  
    };    
};

/*****************************************************************************
 * 3D Clock Widget
 *****************************************************************************/

class VappWidget3dClock : public VappWidgetMiniStage
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidget3dClock);

public:
enum
{
    #if defined(__MMI_MAINLCD_480X800__)
        MAX_SIZE_WIDTH = 480,
        MAX_SIZE_HEIGHT = 480,
        EDIT_BTN_OFFSET_X = 65,
        EDIT_BTN_OFFSET_Y = 110,
        WIDTH = 480,
        HEIGHT = 440,
    #elif defined(__MMI_MAINLCD_320X480__) 
        MAX_SIZE_WIDTH = 320,
        MAX_SIZE_HEIGHT = 336,
        EDIT_BTN_OFFSET_X = 45,
        EDIT_BTN_OFFSET_Y = 68,
        WIDTH = 320,
        HEIGHT = 300,
    #elif defined(__MMI_MAINLCD_240X400__)
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 280,
        EDIT_BTN_OFFSET_X = 30,
        EDIT_BTN_OFFSET_Y = 50,
        WIDTH = 200,
        HEIGHT = 192,
    #elif defined(__MMI_MAINLCD_240X320__)
        MAX_SIZE_WIDTH = 240,
        MAX_SIZE_HEIGHT = 210,
        EDIT_BTN_OFFSET_X = 28,
        EDIT_BTN_OFFSET_Y = 45,
        WIDTH = 200,
        HEIGHT = 192,
    #else
        MAX_SIZE_WIDTH = 320,
        MAX_SIZE_HEIGHT = 336,
        EDIT_BTN_OFFSET_X = 38,
        EDIT_BTN_OFFSET_Y = 16,    
        WIDTH = 320,
        HEIGHT = 336,
    #endif
END_OF_ENUM
};

// Constructor / Destructor
public:
    // Default constructor
    VappWidget3dClock();

// Override
public:
    virtual VappWidgetId getId() const;
    virtual VfxSize getMaxSize() const;

    virtual VfxS32 getName(VfxWChar *string, VfxS32 size) const;
    virtual VfxFrame *createIcon(VfxObject *parentObj) ;
    virtual void onSerializeViewForPageSwitch(VfxArchive * ar);    
    virtual void onSerializeView(VfxArchive * ar); 
    virtual void onSwipeUp();
    virtual void onSwipeDown();
    virtual void onSwipeToNearestView();
    virtual void onRotateX(
        VfxFloat angle          // [IN] Rotation degree
    );
    virtual void onSuspend();
    virtual void onResume();

// Override
    virtual void onCreateView();

    virtual void onReleaseView();

    virtual VfxPoint onGetEditButtonOffset();

    virtual void onRestoreViewForPageSwitch(
          VfxArchive *ar);
    virtual void onRestoreView(VfxArchive *ar);
          
    
// Variable
private:
    VappWidget3dClockContentPanel *m_contentPanel;
    VfxFloat stageAngle;
    VfxFloat oldAngle; 
    VfxFloat newAngle;
    VfxBool firstRotate;
};

#endif /* __MMI_VUI_WIDGET_3D_CLOCK__ */
#endif /* VAPP_WIDGET_3D_CLOCK_H */
