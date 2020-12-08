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
 *  vapp_widget_3d_music_player.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the 3d music player widget
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

#ifndef VAPP_WIDGET_3D_MUSIC_PLAYER_H
#define VAPP_WIDGET_3D_MUSIC_PLAYER_H

#include "MMI_features.h"

#if defined(__MMI_VUI_WIDGET_3D_MUSIC_PLAYER__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vcp_include.h"

#include "vapp_widget_def.h"
#include "vapp_widget.h"
#include "vapp_widget_mini_stage.h"
#include "Vfx_node.h"
#include "Vfx_mesh.h"
#include "Vfx_camera.h"
#include "vapp_widget_music_player.h"
#include "Vapp_music_player_ctrlplayback.h"
#include "vfx_shader_uniforms.h"
#include "vfx_texture.h";


/*****************************************************************************
 * 3D Music Player Widget ContentPanel
 *****************************************************************************/
class VappWidget3dMusicPlayerPanel : public VappWidgetMusicPlayerBase
{
    VFX_DECLARE_CLASS(VappWidget3dMusicPlayerPanel);


//Define
#define WIDGET_MP_TIMER_UPDATE_DURATION (600)    
#define WIDGET_MP_TIMER_ANIMATION (250)


// Public Functions

public:
    VappWidget3dMusicPlayerPanel();
    ~VappWidget3dMusicPlayerPanel();    
    virtual void onInit();
    
    static mmi_ret onAppOpenClose(mmi_event_struct *evt);   
    static mmi_ret staticEventHandler(mmi_event_struct *evt);    
    static mmi_ret onAppShowHide(mmi_event_struct *evt);    
    
    void playAnimation();
    void onSelectNextAnimation();    

    // Music player app open/close event
    VfxSignal2 <
        VappWidget3dMusicPlayerPanel*,    // Sender
        VfxBool                           // isOpen
    > m_signalAppOpenClose;    

private:

    void onBtnClicked(VfxObject *sender, VfxId id);
    void updatePanel();
    void resetPanel();
    virtual void onPlaybackStateChange(PlaybackStateEnum state);
    virtual void onMDICallback(VfxS32 result);
    virtual void onPrevNext(VfxBool is_next);
    void on1stAniStopped(VfxBaseTimeline *source, VfxBool isComplete);    
    void onSongAniChanged(VfxBaseTimeline *source, VfxBool isComplete);     
    virtual VfxBool onPenInput(VfxPenEvent & event);
    void updateDuration(void);    
    void onCurrTimeTimerExpir(VfxTimer *timer);
    void onLoad1stAni(VfxTimer *timer);
    void updateCurrentTime(void);    

    void initTextureFrame();
    void updateButton(void);    
    void playLoopAnimation(void);
    void stopLoopAnimation(void);    
    void play0To0Animation(void);
    void play1To1Animation(void);    
    void playChangeSongAnimation(void);    
    void configAnimation(void);
    void setTapTextVisible(VfxBool is_hidden);
    void setCover(const VfxImageSrc &value);
    void loadParticle();
   
//Variable 
public:

    VfxTextFrame *m_tap_text;
    VfxFloatTimeline *m_refTimeLine;
    VfxFloatTimeline *m_refTimeLineLoop;
    VfxFloatTimeline *m_refTimeBg;  
    VfxFloatTimeline *m_refTlParticle;    
    VfxFloatTimeline *m_refTimeAngle;    
    VfxFloatTimeline *m_tlChangeDisk;    
    
    VfxAnimation *anim;
    VfxBool m_2dMode;
    VfxBool m_isAniPlayed;
    VfxBool m_isPlayNext;

private:

    VfxGroup *m_groupParticle;
    VfxTextFrame *m_songTextFrame;
    VfxTextFrame *m_songTextFrame3D;
    VfxTextFrame *m_albumTextFrame;
    VfxTextFrame *m_artistTextFrame;
    VfxTextFrame *m_tapTextFrame;    
    VfxTextFrame *m_tapTextFrame3D;    
    VfxTextFrame *m_durationTextFrame;
    VfxTextFrame *m_albumText;
    VfxTextFrame *m_artistText;
    
    VfxWorld *sceneWorld;
    VfxMesh *m_meshPlay; 
    VfxMesh *m_meshPrev;
    VfxMesh *m_meshNext;
    VfxMesh *m_meshMusicSign;    
    VfxMesh *m_meshSong;
    VfxMesh *m_meshSong3D;    
    VfxMesh *m_meshCover2D;
    VfxMesh *m_meshCD1;
    VfxMesh *m_meshArtist;
    VfxMesh *m_meshAlbum;
    VfxMesh *m_meshSliderBar;
    VfxMesh *m_meshDuration;
    VfxMesh *m_meshTextTap;    
    VfxMesh *m_meshTextTap3D;    
    VfxMaterial *m_mtlPlay;
    VfxMaterial *m_mtlNext;
    VfxMaterial *m_mtlPrev;
    VcpButton *m_btnAdd;

    VfxShaderVariable *m_playPauseShaderVal;
    VfxShaderVariable *m_prevShaderVal;    
    VfxShaderVariable *m_nextShaderVal;
    VfxShaderVariable *m_durationLableVar;
    VfxTextureFrame *m_durationLabelTexture;

    VfxTexture2D *playNormalTexture;
    VfxTexture2D *pauseNormalTexture;
    VfxTexture2D *nextNormalTexture;
    VfxTexture2D *prevNormalTexture;
    
    VfxTexture2D *playPressTexture;
    VfxTexture2D *pausePressTexture;
    VfxTexture2D *nextPressTexture;
    VfxTexture2D *prevPressTexture;

    VfxTexture2D *playDisableTexture;
    VfxTexture2D *pauseDisableTexture;
    VfxTexture2D *nextDisableTexture;
    VfxTexture2D *prevDisableTexture;    

    VfxNode *m_parentMusicSign;
    VfxNode *m_nodeSong1;
    
    VfxImageFrame *m_sliderBgImgFrame;
    VfxImageFrame *m_sliderBarImgFrame;  
    VfxU32 m_duration;
    VfxSize m_slider_bar_size;
    VfxTimer *m_timer_curr_time;    
    VfxFrame *m_lableCoverFrame;
    VfxFrame *m_lableCD1Frame;

    enum
    {
        #if defined(__MMI_MAINLCD_480X800__) //WVGA
            WIDTH = 480,
            HEIGHT = 440,
            BTN_BundAddX2D = 320,
            BTN_BundAddY2D = 90,
            BTN_BundAddX3D = 170,
            BTN_BundAddY3D = 155,
            TXT_ADD_X = 265,
            TXT_ADD_Y = 135,
            TXT_ADD_SIZE_X = 300,
            TXT_ADD_SIZE_Y = 30,
            BTN_ADD_X_2D = 90,
            BTN_ADD_Y_2D = 95,
            BTN_ADD_X_3D = 150,
            BTN_ADD_Y_3D = 165,
            MESH_SONG_SIZE_X = 520,
            MESH_SONG_SIZE_Y = 80,
            MESH_TAP_SIZE_X = 520,
            MESH_TAP_SIZE_Y = 100,
            MESH_ARTIST_SIZE_X = 520,
            MESH_ARTIST_SIZE_Y = 44,
            MESH_ALBUM_SIZE_X = 520,
            MESH_ALBUM_SIZE_Y = 44,
            MESH_DURATION_SIZE_X = 390,//130*11
            MESH_DURATION_SIZE_Y = 33,
            SLIDER_BG_BUNS_X = 768,
            SLIDER_BG_BUNS_Y = 28,
            SLIDER_BAR_BUNS_Y = 25,
            SLIDE_BG_POS_X=0,
            SLIDE_BG_POS_Y_OFFSET=12,            
            FONT_SONG = 55,
            FONT_TAP = 55,
            FONT_ARTIST = 38,
            FONT_ALBUM = 38,
            FONT_DURATION = 33,

        #elif defined(__MMI_MAINLCD_320X480__) //HVGA
            WIDTH = 320,
            HEIGHT = 300,
            BTN_BundAddX2D = 175,
            BTN_BundAddY2D = 75,
            BTN_BundAddX3D = 115,
            BTN_BundAddY3D = 95,
            TXT_ADD_X = 90,
            TXT_ADD_Y = 85,
            TXT_ADD_SIZE_X = 300,
            TXT_ADD_SIZE_Y = 30,            
            BTN_ADD_X_2D = 90,
            BTN_ADD_Y_2D = 70,
            BTN_ADD_X_3D = 100,
            BTN_ADD_Y_3D = 115,
            MESH_SONG_SIZE_X = 453,
            MESH_SONG_SIZE_Y = 66,
            MESH_TAP_SIZE_X = 340,
            MESH_TAP_SIZE_Y = 80,   
            MESH_ARTIST_SIZE_X = 270,
            MESH_ARTIST_SIZE_Y = 22, 
            MESH_ALBUM_SIZE_X = 270,
            MESH_ALBUM_SIZE_Y = 22,
            MESH_DURATION_SIZE_X = 60,
            MESH_DURATION_SIZE_Y = 22,
            SLIDER_BG_BUNS_X = 768,
            SLIDER_BG_BUNS_Y = 28,
            SLIDER_BAR_BUNS_Y = 25,
            SLIDE_BG_POS_X =1,
            SLIDE_BG_POS_Y_OFFSET =11,
            FONT_SONG = 50,
            FONT_TAP = 40,
            FONT_ARTIST = 25,
            FONT_ALBUM = 25,
            FONT_DURATION = 20,            
        #else //WQVA & QVGA
            WIDTH = 200,
            HEIGHT = 192,    
            BTN_BundAddX2D = 120,
            BTN_BundAddY2D = 55,
            BTN_BundAddX3D = 70,
            BTN_BundAddY3D = 65,
            TXT_ADD_X = 90,
            TXT_ADD_Y = 95,
            TXT_ADD_SIZE_X = 300,
            TXT_ADD_SIZE_Y = 30,            
            BTN_ADD_X_2D = 55,
            BTN_ADD_Y_2D = 35,
            BTN_ADD_X_3D = 60,
            BTN_ADD_Y_3D = 75,
            MESH_SONG_SIZE_X = 270,
            MESH_SONG_SIZE_Y = 40,
            MESH_TAP_SIZE_X = 520,
            MESH_TAP_SIZE_Y = 80,   
            MESH_ARTIST_SIZE_X = 270,
            MESH_ARTIST_SIZE_Y = 22, 
            MESH_ALBUM_SIZE_X = 270,
            MESH_ALBUM_SIZE_Y = 22,
            MESH_DURATION_SIZE_X = 270,
            MESH_DURATION_SIZE_Y = 22,
            SLIDER_BG_BUNS_X = 768,
            SLIDER_BG_BUNS_Y = 28,
            SLIDER_BAR_BUNS_Y = 25,
            SLIDE_BG_POS_X =1,
            SLIDE_BG_POS_Y_OFFSET =11,            
            FONT_SONG = 38,
            FONT_TAP = 55,
            FONT_ARTIST = 25,
            FONT_ALBUM = 25,
            FONT_DURATION = 25,
        #endif  
    };

    enum 
    {
		BTN_ADD_SONGS
    };    
};

/*****************************************************************************
 * 3D Music Player Widget
 *****************************************************************************/

class VappWidget3dMusicPlayer: public VappWidgetMiniStage
{
    VAPP_WIDGET_DECLARE_CLASS(VappWidget3dMusicPlayer);

 
// Constructor / Destructor
public:
    // Default constructor
    VappWidget3dMusicPlayer();

public:
    enum
    {
    #if defined(__MMI_MAINLCD_480X800__)
            MAX_SIZE_WIDTH = 480,
            MAX_SIZE_HEIGHT = 480,
            WIDTH = 480,
            HEIGHT = 440,
            EDIT_BTN_2D_OFFSET_X = 55,
            EDIT_BTN_2D_OFFSET_Y = 90,
            EDIT_BTN_3D_OFFSET_X = 50,
            EDIT_BTN_3D_OFFSET_Y = 52,       
    #elif defined(__MMI_MAINLCD_320X480__) 
            MAX_SIZE_WIDTH = 320,
            MAX_SIZE_HEIGHT = 336,
            WIDTH = 320,
            HEIGHT = 300,
            EDIT_BTN_2D_OFFSET_X = 48,
            EDIT_BTN_2D_OFFSET_Y = 62,
            EDIT_BTN_3D_OFFSET_X = 48,
            EDIT_BTN_3D_OFFSET_Y = 62,            
    #elif defined(__MMI_MAINLCD_240X400__)
            MAX_SIZE_WIDTH = 240,
            MAX_SIZE_HEIGHT = 280,    
            WIDTH = 200,
            HEIGHT = 192,    
            EDIT_BTN_2D_OFFSET_X = 32,
            EDIT_BTN_2D_OFFSET_Y = 40,
            EDIT_BTN_3D_OFFSET_X = 48,
            EDIT_BTN_3D_OFFSET_Y = 62,  

    #elif defined(__MMI_MAINLCD_240X320__)
            MAX_SIZE_WIDTH = 240,
            MAX_SIZE_HEIGHT = 210,    
            WIDTH = 200,
            HEIGHT = 192,    
            EDIT_BTN_2D_OFFSET_X = 26,
            EDIT_BTN_2D_OFFSET_Y = 37,  
            EDIT_BTN_3D_OFFSET_X = 48,
            EDIT_BTN_3D_OFFSET_Y = 62, 
    #else
            MAX_SIZE_WIDTH = 480,
            MAX_SIZE_HEIGHT = 480,
            WIDTH = 480,
            HEIGHT = 440,
            EDIT_BTN_2D_OFFSET_X = 55,
            EDIT_BTN_2D_OFFSET_Y = 70,
            EDIT_BTN_3D_OFFSET_X = 50,
            EDIT_BTN_3D_OFFSET_Y = 52,             
    #endif
    END_OF_ENUM
    };

// Override
public:
    virtual VappWidgetId getId() const;

    virtual VfxSize getMaxSize() const;


    virtual VfxS32 getName(
        VfxWChar *string, 
        VfxS32 size
    ) const;

    virtual VfxFrame *createIcon(
        VfxObject *parentObj
    );

    virtual void onSwipeUp();
    virtual void onSwipeDown();
    virtual void onSwipeToNearestView();
    virtual void onRotateX(
        VfxFloat angle          // [IN] Rotation degree
    );

// Override
    virtual void onCreateView();

    virtual void onReleaseView();

    virtual VfxPoint onGetEditButtonOffset();

    virtual void onRestoreView(
        VfxArchive *ar
    );

    virtual void onRestoreViewForPageSwitch(
        VfxArchive *ar
    );

    virtual void onSuspend();
    virtual void onResume();


// Variable
private:
    VappWidget3dMusicPlayerPanel *m_contentPanel;
    VfxFloat stageAngel;    
    
};
#endif /* defined(__MMI_VUI_WIDGET_3D_MUSIC_PLAYER__) */
#endif /* VAPP_WIDGET_3D_MUSIC_PLAYER_H */
