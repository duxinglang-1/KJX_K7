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
 *  vapp_widget_3d_music_player.cpp
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the 3D music player widget.
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

#if defined(__MMI_VUI_WIDGET_3D_MUSIC_PLAYER__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "vapp_widget_def.h"
#include "vapp_widget_native_factory.h"
#include "mmi_rp_vapp_widget_3d_music_player_def.h"
#include "mmi_rp_vapp_music_player_def.h"

// Pluto MMI headers 
extern "C"
{
#include "MMI_common_app_trc.h"  //Trace header
#include "AppMgrSrvGprot.h"      // To launch music player
#include "UCMSrvGProt.h"         // To check calling status
}

#include "vfx_object.h"
#include "vapp_widget_3d_music_player.h"
#include "vcp_include.h"
#include "vdat_systime.h"
#include "vfx_world.h"
#include "vfx_mesh.h"
#include "vfx_node.h"
#include "vfx_material.h"
#include "vfx_transformable.h"
#include "vfx_asset_loader.h"
#include "vapp_setting_framework_gprot.h"
#include "vfx_bounding_volume.h"
#include "vapp_music_player_ctrlplsv.h" //m_provider

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

#define MPL_MEASURE_TIME_START(_symbol_) SLA_CustomLogging(##_symbol_##, SA_start);
#define MPL_MEASURE_TIME_STOP(_symbol_)  SLA_CustomLogging(##_symbol_##, SA_stop);
#else
#define MPL_MEASURE_TIME_START(_symbol_)
#define MPL_MEASURE_TIME_STOP(_symbol_)
#endif

/*****************************************************************************
 * 3D  Music Player Widget
 *****************************************************************************/
VFX_IMPLEMENT_CLASS("VappWidget3dMusicPlayerPanel", VappWidget3dMusicPlayerPanel, VappWidgetMusicPlayerBase);

VappWidget3dMusicPlayerPanel::VappWidget3dMusicPlayerPanel():
    sceneWorld(NULL),
    m_2dMode(VFX_TRUE),
    m_isAniPlayed(VFX_FALSE),
    m_isPlayNext(VFX_FALSE),
    m_lableCD1Frame(NULL),
    m_lableCoverFrame(NULL),
    m_groupParticle(NULL),
    m_refTlParticle(NULL)
{
}
VappWidget3dMusicPlayerPanel::~VappWidget3dMusicPlayerPanel()
{
    /* Deregister app event callback */
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_MUSICPLY_OPEN_CLOSE,(mmi_proc_func)&VappWidget3dMusicPlayerPanel::onAppOpenClose, this);
    mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE,(mmi_proc_func)&VappWidget3dMusicPlayerPanel::staticEventHandler, this);
    mmi_frm_cb_dereg_event(EVT_ID_VAPP_MUSICPLY_SHOW_HIDE,(mmi_proc_func)&VappWidget3dMusicPlayerPanel::onAppShowHide, this);

}

void VappWidget3dMusicPlayerPanel::onInit()
{
    VfxControl::onInit();
    
    // Create Add button to add songs
    VFX_OBJ_CREATE(m_btnAdd, VcpButton, this);
    m_btnAdd->setOpacity(0.0f);
    m_btnAdd->setId(BTN_ADD_SONGS);
    m_btnAdd->setText(VFX_WSTR("Add"));
    m_btnAdd->m_signalClicked.connect(this, &VappWidget3dMusicPlayerPanel::onBtnClicked);

    //world
    VFX_OBJ_CREATE(sceneWorld, VfxWorld, this);
    setWorld(sceneWorld);

    // Load scene
    VfxAssetLoader::loadSceneBegin(sceneWorld,VAPP_WIDGET_3D_MUSIC_PLAYER_SCN);

    // Find play mesh to replace image
    VfxString name_play = VFX_STR("Btn_Play-node");
    VfxString name_next = VFX_STR("Btn_Next-node");
    VfxString name_prev = VFX_STR("Btn_Prev-node");   
        
    m_meshPlay = (VfxMesh *)VfxAssetLoader::findObjByName(name_play);
    m_meshPrev = (VfxMesh *)VfxAssetLoader::findObjByName(name_prev);
    m_meshNext = (VfxMesh *)VfxAssetLoader::findObjByName(name_next);    
    
    VfxString nameCover2D = VFX_STR("Cover-node");
    VfxString nameCD1 = VFX_STR("CD1-node");    
    VfxString nameSong = VFX_STR("Song-node");
    VfxString nameSong3D = VFX_STR("Song2-node");
    VfxString nameArtist = VFX_STR("Artist-node");
    VfxString nameAlbum = VFX_STR("Album-node");
    VfxString nameSliderBar = VFX_STR("ProgressBar-node");
    VfxString nameDuration = VFX_STR("Time-node");
    VfxString nameTextTap = VFX_STR("AddSong-node");
    VfxString nameTextTap3D = VFX_STR("AddSong2-node");    
    
    m_meshCover2D = (VfxMesh *)VfxAssetLoader::findObjByName(nameCover2D);
    m_meshCD1 = (VfxMesh *)VfxAssetLoader::findObjByName(nameCD1);
    m_meshSong = (VfxMesh *)VfxAssetLoader::findObjByName(nameSong);
    m_meshSong3D = (VfxMesh *)VfxAssetLoader::findObjByName(nameSong3D);    
    m_meshArtist = (VfxMesh *)VfxAssetLoader::findObjByName(nameArtist);  
    m_meshAlbum = (VfxMesh *)VfxAssetLoader::findObjByName(nameAlbum);
    m_meshSliderBar = (VfxMesh *)VfxAssetLoader::findObjByName(nameSliderBar);
    m_meshDuration = (VfxMesh *)VfxAssetLoader::findObjByName(nameDuration);    
    m_meshTextTap  = (VfxMesh *)VfxAssetLoader::findObjByName(nameTextTap);    
    m_meshTextTap3D  = (VfxMesh *)VfxAssetLoader::findObjByName(nameTextTap3D);    

 	VfxAssetLoader::loadSceneEnd();    

    //Config for all of timeline and animation.
    configAnimation();

    // Initialize texture frame for song, artist and albume name.
    initTextureFrame();
    
    resetPanel();

    // If music player already running, get play and list control 
    getAppControl();

    // Update content
    updatePanel();

    // Register for app open/close event 
    mmi_frm_cb_reg_event(EVT_ID_VAPP_MUSICPLY_OPEN_CLOSE,(mmi_proc_func)&VappWidget3dMusicPlayerPanel::onAppOpenClose, this);
    mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE,(mmi_proc_func)&VappWidget3dMusicPlayerPanel::staticEventHandler, this);
    mmi_frm_cb_reg_event(EVT_ID_VAPP_MUSICPLY_SHOW_HIDE,(mmi_proc_func)&VappWidget3dMusicPlayerPanel::onAppShowHide, this);

    //2nd pass loading opening animation
    VfxTimer *s_openingAniTimer;
    VFX_OBJ_CREATE(s_openingAniTimer, VfxTimer, this);
    s_openingAniTimer->setStartDelay(400);
    s_openingAniTimer->m_signalTick.connect(this, &VappWidget3dMusicPlayerPanel::onLoad1stAni);
    s_openingAniTimer->start();

}

void VappWidget3dMusicPlayerPanel::onLoad1stAni(VfxTimer *timer)
{
    //Opening animation
    playAnimation();
    
    //Load Particle, not loaded at onInit for the performance consideration
    loadParticle();
}

void VappWidget3dMusicPlayerPanel::initTextureFrame()
{
    //get pass of button's material for each mesh
    m_playPauseShaderVal = m_meshPlay->getMaterial(0)->getPass(0)->getUniformVariable(VFX_STR("uDiffuseSampler"));
    m_prevShaderVal = m_meshPrev->getMaterial(0)->getPass(0)->getUniformVariable(VFX_STR("uDiffuseSampler"));
    m_nextShaderVal = m_meshNext->getMaterial(0)->getPass(0)->getUniformVariable(VFX_STR("uDiffuseSampler"));

    //images of play & pause btn 
    VFX_OBJ_CREATE_EX(playNormalTexture, VfxTexture2D, 
        m_playPauseShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PLAY_NORMAL));    //normal
    VFX_OBJ_CREATE_EX(pauseNormalTexture, VfxTexture2D, 
        m_playPauseShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PAUSE_NORMAL));
    VFX_OBJ_CREATE_EX(prevNormalTexture, VfxTexture2D, 
        m_prevShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PREV_NORMAL));
    VFX_OBJ_CREATE_EX(nextNormalTexture, VfxTexture2D, 
        m_nextShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_NEXT_NORMAL));
    
    VFX_OBJ_CREATE_EX(playPressTexture, VfxTexture2D, 
        m_playPauseShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PLAY_PRESS));     //press
    VFX_OBJ_CREATE_EX(pausePressTexture, VfxTexture2D, 
        m_playPauseShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PAUSE_PRESS));
    VFX_OBJ_CREATE_EX(prevPressTexture, VfxTexture2D, 
        m_prevShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PREV_PRESS));
    VFX_OBJ_CREATE_EX(nextPressTexture, VfxTexture2D, 
        m_nextShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_NEXT_PRESS));    
   
    VFX_OBJ_CREATE_EX(playDisableTexture, VfxTexture2D, 
        m_playPauseShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PLAY_DISABLE));   //disable 
    VFX_OBJ_CREATE_EX(pauseDisableTexture, VfxTexture2D, 
        m_playPauseShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PAUSE_DISABLE));
    VFX_OBJ_CREATE_EX(nextDisableTexture, VfxTexture2D, 
        m_nextShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_NEXT_DISABLE));
    VFX_OBJ_CREATE_EX(prevDisableTexture, VfxTexture2D, 
        m_prevShaderVal,(IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PREV_DISABLE));

    // Add lable frame texture
    //Cover Frame
    VFX_OBJ_CREATE(m_lableCoverFrame, VfxFrame, this);
    m_lableCoverFrame->setSize(150, 150);
    m_lableCoverFrame->setImgContent(VfxImageSrc(IMG_ID_VAPP_WIDGET_3D_MUSPLY_DEFAULT_COVER)); //default cover
    m_lableCoverFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);

    //CD1 Frame
    VFX_OBJ_CREATE(m_lableCD1Frame, VfxFrame, this);
    m_lableCD1Frame->setSize(150, 150);
    m_lableCD1Frame->setImgContent(VfxImageSrc(IMG_ID_VAPP_WIDGET_3D_MUSPLY_DEFAULT_COVER));   //default cover    
    m_lableCD1Frame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);

    //Song Frame
    VfxFrame *m_lableSongFrame;
    VFX_OBJ_CREATE(m_lableSongFrame, VfxFrame, this);
    m_lableSongFrame->setSize(MESH_SONG_SIZE_X, MESH_SONG_SIZE_Y);
    m_lableSongFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);

    //Song Frame 3D side
    VfxFrame *m_lableSongFrame3D;
    VFX_OBJ_CREATE(m_lableSongFrame3D, VfxFrame, this);
    m_lableSongFrame3D->setSize(MESH_SONG_SIZE_X, MESH_SONG_SIZE_Y);
    m_lableSongFrame3D->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);    

    //Tap Frame
    VfxFrame *m_lableTapFrame;
    VFX_OBJ_CREATE(m_lableTapFrame, VfxFrame, this);
    m_lableTapFrame->setSize(MESH_TAP_SIZE_X, MESH_TAP_SIZE_Y);
    m_lableTapFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);

    //Tap Frame 3D
    VfxFrame *m_lableTapFrame3D;
    VFX_OBJ_CREATE(m_lableTapFrame3D, VfxFrame, this);
    m_lableTapFrame3D->setSize(MESH_TAP_SIZE_X, MESH_TAP_SIZE_Y);
    m_lableTapFrame3D->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);    

    //Artist Frame
    VfxFrame *m_lableArtistFrame;
    VFX_OBJ_CREATE(m_lableArtistFrame, VfxFrame, this);
    m_lableArtistFrame->setSize(MESH_ARTIST_SIZE_X, MESH_ARTIST_SIZE_Y);
    m_lableArtistFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);

    //Album Frame
    VfxFrame *m_lableAlbumFrame;
    VFX_OBJ_CREATE(m_lableAlbumFrame, VfxFrame, this);
    m_lableAlbumFrame->setSize(MESH_ALBUM_SIZE_X,MESH_ALBUM_SIZE_Y);
    m_lableAlbumFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);

    //Duation Frame
    VfxFrame *m_lableDurationFrame;
    VFX_OBJ_CREATE(m_lableDurationFrame, VfxFrame, this);
    m_lableDurationFrame->setSize(MESH_DURATION_SIZE_X,MESH_DURATION_SIZE_Y);
    m_lableDurationFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
    
    // add text frame 
    //Song 2D text
    VFX_OBJ_CREATE(m_songTextFrame, VfxTextFrame, m_lableSongFrame);
    VfxFontDesc m_songFontDesc;
    m_songFontDesc.size = VFX_FONT_DESC_VF_SIZE(FONT_SONG);
    m_songFontDesc.attr = VFX_FONT_DESC_ATTR_BOLD;
    m_songFontDesc.effect = VFX_FE1_9;
    m_songTextFrame->setFont(m_songFontDesc);
    m_songTextFrame->setColor(VFX_COLOR_WHITE);
    m_songTextFrame->setFullLineHeightMode(VFX_FALSE);
    m_songTextFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_songTextFrame->setVerticalToCenter(VFX_TRUE);
    m_songTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_songTextFrame->setAnchor(0.5f, 0.5f);
    m_songTextFrame->setPos(m_lableSongFrame->getSize().width / 2, m_lableSongFrame->getSize().height/2);
    m_songTextFrame->setSize(MESH_SONG_SIZE_X, MESH_SONG_SIZE_Y);
    m_songTextFrame->setAutoResized(VFX_FALSE);
    m_songTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_songTextFrame->setString(VFX_WSTR(" "));

    //Song 3D text
    VFX_OBJ_CREATE(m_songTextFrame3D, VfxTextFrame, m_lableSongFrame3D);
    VfxFontDesc m_songFontDesc3D;
    m_songFontDesc3D.size = VFX_FONT_DESC_VF_SIZE(FONT_SONG);
    m_songFontDesc3D.attr = VFX_FONT_DESC_ATTR_BOLD;
    m_songFontDesc3D.effect = VFX_FE1_9;
    m_songTextFrame3D->setFont(m_songFontDesc3D);
    m_songTextFrame3D->setColor(VFX_COLOR_WHITE);
    m_songTextFrame3D->setFullLineHeightMode(VFX_FALSE);
    m_songTextFrame3D->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_songTextFrame3D->setVerticalToCenter(VFX_TRUE);
    m_songTextFrame3D->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_songTextFrame3D->setAnchor(0.5f, 0.5f);
    m_songTextFrame3D->setPos(m_lableSongFrame3D->getSize().width / 2, m_lableSongFrame3D->getSize().height/2);
    m_songTextFrame3D->setSize(MESH_SONG_SIZE_X, MESH_SONG_SIZE_Y);
    m_songTextFrame3D->setAutoResized(VFX_FALSE);
    m_songTextFrame3D->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_songTextFrame3D->setString(VFX_WSTR(" "));    

    //Text of tap to add songs
    VFX_OBJ_CREATE(m_tapTextFrame, VfxTextFrame, m_lableTapFrame);
    VfxFontDesc m_tapFontDesc;
    m_tapFontDesc.size = VFX_FONT_DESC_VF_SIZE(FONT_TAP);
    m_tapFontDesc.attr = VFX_FONT_DESC_ATTR_BOLD;
    m_tapFontDesc.effect = VFX_FE1_9;
    m_tapTextFrame->setFont(m_tapFontDesc);
    m_tapTextFrame->setColor(VFX_COLOR_WHITE);
    m_tapTextFrame->setFullLineHeightMode(VFX_FALSE);
    m_tapTextFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_tapTextFrame->setVerticalToCenter(VFX_TRUE);
    m_tapTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_tapTextFrame->setAnchor(0.5f, 0.5f);
    m_tapTextFrame->setPos(m_lableTapFrame->getSize().width / 2, m_lableTapFrame->getSize().height/2);
    m_tapTextFrame->setSize(MESH_TAP_SIZE_X, MESH_TAP_SIZE_X);
    m_tapTextFrame->setAutoResized(VFX_FALSE);
    m_tapTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_tapTextFrame->setString(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_3D_MUSIC_TAP_TO_ADD_SONG));


    //Text of tap to add songs 3D
    VFX_OBJ_CREATE(m_tapTextFrame3D, VfxTextFrame, m_lableTapFrame3D);
    VfxFontDesc m_tapFontDesc3D;
    m_tapFontDesc3D.size = VFX_FONT_DESC_VF_SIZE(FONT_TAP);
    m_tapFontDesc3D.attr = VFX_FONT_DESC_ATTR_BOLD;
    m_tapFontDesc3D.effect = VFX_FE1_9;
    m_tapTextFrame3D->setFont(m_tapFontDesc3D);
    m_tapTextFrame3D->setColor(VFX_COLOR_WHITE);
    m_tapTextFrame3D->setFullLineHeightMode(VFX_FALSE);
    m_tapTextFrame3D->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_tapTextFrame3D->setVerticalToCenter(VFX_TRUE);
    m_tapTextFrame3D->setAlignMode(VfxTextFrame::ALIGN_MODE_CENTER);
    m_tapTextFrame3D->setAnchor(0.5f, 0.5f);
    m_tapTextFrame3D->setPos(m_lableTapFrame3D->getSize().width / 2, m_lableTapFrame3D->getSize().height/2);
    m_tapTextFrame3D->setSize(MESH_TAP_SIZE_X, MESH_TAP_SIZE_X);
    m_tapTextFrame3D->setAutoResized(VFX_FALSE);
    m_tapTextFrame3D->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_tapTextFrame3D->setString(VFX_WSTR_RES(STR_ID_VAPP_WIDGET_3D_MUSIC_TAP_TO_ADD_SONG));    

    //Artist
    VFX_OBJ_CREATE(m_artistTextFrame, VfxTextFrame, m_lableArtistFrame);
    VfxFontDesc m_artistFontDesc;
    m_artistFontDesc.size = VFX_FONT_DESC_VF_SIZE(FONT_ARTIST);
    m_artistFontDesc.attr = VFX_FONT_DESC_ATTR_BOLD;
    m_artistFontDesc.effect = VFX_FE1_9;
    m_artistTextFrame->setFont(m_artistFontDesc);
    m_artistTextFrame->setColor(VRT_COLOR_SILVER);
    m_artistTextFrame->setFullLineHeightMode(VFX_TRUE);
    m_artistTextFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_artistTextFrame->setVerticalToCenter(VFX_TRUE);
    m_artistTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_artistTextFrame->setAnchor(0.5f, 0.5f);
    m_artistTextFrame->setPos(m_lableArtistFrame->getSize().width / 2, m_lableArtistFrame->getSize().height/2);
    m_artistTextFrame->setSize(MESH_ARTIST_SIZE_X, MESH_ARTIST_SIZE_Y);
    m_artistTextFrame->setAutoResized(VFX_FALSE);
    m_artistTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_artistTextFrame->setString(VFX_WSTR(" "));

    //Album
    VFX_OBJ_CREATE(m_albumTextFrame, VfxTextFrame, m_lableAlbumFrame);
    VfxFontDesc m_albumFontDesc;
    m_albumFontDesc.size = VFX_FONT_DESC_VF_SIZE(FONT_ALBUM);
    m_albumFontDesc.attr = VFX_FONT_DESC_ATTR_BOLD;
    m_albumFontDesc.effect = VFX_FE1_9;
    m_albumTextFrame->setFont(m_albumFontDesc);
    m_albumTextFrame->setColor(VRT_COLOR_SILVER);
    m_albumTextFrame->setFullLineHeightMode(VFX_TRUE);
    m_albumTextFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_albumTextFrame->setVerticalToCenter(VFX_TRUE);
    m_albumTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_LEFT);
    m_albumTextFrame->setAnchor(0.5f, 0.5f);
    m_albumTextFrame->setPos(m_lableAlbumFrame->getSize().width / 2, m_lableAlbumFrame->getSize().height/ 2);
    m_albumTextFrame->setSize(MESH_ALBUM_SIZE_X, MESH_ALBUM_SIZE_Y);
    m_albumTextFrame->setAutoResized(VFX_FALSE);
    m_albumTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_albumTextFrame->setString(VFX_WSTR(" "));

    //slider background
    VFX_OBJ_CREATE(m_sliderBgImgFrame, VfxImageFrame, this);                         //m_labelSliderBgFrame
    m_sliderBgImgFrame->setHints(VFX_FRAME_HINTS_TEXTURE_HIDDEN);
    m_sliderBgImgFrame->setBounds(VfxRect(0, 0, SLIDER_BG_BUNS_X,SLIDER_BG_BUNS_Y));
    m_sliderBgImgFrame->setPos(80,153);
    VfxSize bgSilderSize = m_sliderBgImgFrame->getSize();
    m_sliderBgImgFrame->setResId(VAPP_WIDGET_3D_MUSIC_PLAYER_SLIDER_BG);
    m_sliderBgImgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_sliderBgImgFrame->setSize(bgSilderSize);

    //slider bar
    VFX_OBJ_CREATE(m_sliderBarImgFrame, VfxImageFrame, m_sliderBgImgFrame);            //m_labelSliderBarFrame
    m_sliderBarImgFrame->setBounds(VfxRect(0, 0, SLIDER_BG_BUNS_X ,SLIDER_BAR_BUNS_Y));
    m_sliderBarImgFrame->setPos(SLIDE_BG_POS_X, (m_sliderBgImgFrame->getSize().height/2)-SLIDE_BG_POS_Y_OFFSET);
    m_slider_bar_size = m_sliderBarImgFrame->getSize();
    m_sliderBarImgFrame->setResId(VAPP_WIDGET_3D_MUSIC_PLAYER_SLIDER_BAR);
    m_sliderBarImgFrame->setContentPlacement(VFX_FRAME_CONTENT_PLACEMENT_TYPE_RESIZE);
    m_sliderBarImgFrame->setHidden(VFX_TRUE);

    //Duration Time Text
    VFX_OBJ_CREATE(m_durationTextFrame, VfxTextFrame, m_lableDurationFrame);
    VfxFontDesc m_durationFontDesc;
    m_durationFontDesc.size = VFX_FONT_DESC_VF_SIZE(FONT_DURATION);
    m_durationFontDesc.attr = VFX_FONT_DESC_ATTR_BOLD;
    m_durationFontDesc.effect = VFX_FE1_9;
    m_durationTextFrame->setFont(m_durationFontDesc);
    m_durationTextFrame->setColor(VFX_COLOR_WHITE);
    m_durationTextFrame->setFullLineHeightMode(VFX_TRUE);
    m_durationTextFrame->setLineMode(VfxTextFrame::LINE_MODE_SINGLE);
    m_durationTextFrame->setVerticalToCenter(VFX_TRUE);
    m_durationTextFrame->setAlignMode(VfxTextFrame::ALIGN_MODE_RIGHT);
    m_durationTextFrame->setAnchor(0.5f, 0.5f);
    m_durationTextFrame->setPos(m_lableDurationFrame->getSize().width / 2, m_lableDurationFrame->getSize().height/2);
    m_durationTextFrame->setSize(MESH_DURATION_SIZE_X, MESH_DURATION_SIZE_Y);
    m_durationTextFrame->setAutoResized(VFX_FALSE);
    m_durationTextFrame->setTruncateMode(VfxTextFrame::TRUNCATE_MODE_END);
    m_durationTextFrame->setString(VFX_WSTR(" "));

    //Pass it as a texture to the fragment shader

    //2D Album Cover
    VfxShaderVariable *m_cover2dShaderVal;
    m_cover2dShaderVal = m_meshCover2D->getMaterial(0)->getPass(0)->getUniformVariable(VFX_STR("uDiffuseSampler"));
    VfxTextureFrame *m_cover2dTexture;
    VFX_OBJ_CREATE_EX(m_cover2dTexture, VfxTextureFrame,m_cover2dShaderVal,(m_lableCoverFrame));
    m_cover2dShaderVal->setValue(m_cover2dTexture);

    //3D Album Cover
    VfxShaderVariable *m_coverCD1ShaderVal;  
    m_coverCD1ShaderVal = m_meshCD1->getMaterial(0)->getPass(0)->getUniformVariable(VFX_STR("uDiffuseSampler"));
    VfxTextureFrame *m_coverCD1Texture;
    VFX_OBJ_CREATE_EX(m_coverCD1Texture, VfxTextureFrame,m_coverCD1ShaderVal,(m_lableCD1Frame));
    m_coverCD1ShaderVal->setValue(m_coverCD1Texture);    
    
    //Song_text_2D
    VfxShaderUniforms *m_songLableUni = 
        m_meshSong->getMaterial(0)->getPass(0)->getShaderUniformList().begin()->get();
    VfxShaderVariable *m_songLableVar = 
        m_songLableUni->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    VfxTextureFrame *m_songLabelTexture;
    VFX_OBJ_CREATE_EX(m_songLabelTexture, VfxTextureFrame, m_songLableVar, (m_lableSongFrame));
    m_songLableVar->setValue(m_songLabelTexture);

    //Song_text_3D
    VfxShaderUniforms *m_songLableUni3D = 
        m_meshSong3D->getMaterial(0)->getPass(0)->getShaderUniformList().begin()->get();
    VfxShaderVariable *m_songLableVar3D = 
        m_songLableUni3D->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    VfxTextureFrame *m_songLabelTexture3D;
    VFX_OBJ_CREATE_EX(m_songLabelTexture3D, VfxTextureFrame, m_songLableVar3D, (m_lableSongFrame3D));
    m_songLableVar3D->setValue(m_songLabelTexture3D);    

    //Tap to add songs
    VfxShaderUniforms *m_tapLableUni = 
        m_meshTextTap->getMaterial(0)->getPass(0)->getShaderUniformList().begin()->get();
    VfxShaderVariable *m_tapLableVar = 
        m_tapLableUni->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    VfxTextureFrame *m_tapLabelTexture;
    VFX_OBJ_CREATE_EX(m_tapLabelTexture, VfxTextureFrame, m_tapLableVar, (m_lableTapFrame));
    m_tapLableVar->setValue(m_tapLabelTexture);

    //Tap to add songs3D
    VfxShaderUniforms *m_tapLableUni3D = 
        m_meshTextTap3D->getMaterial(0)->getPass(0)->getShaderUniformList().begin()->get();
    VfxShaderVariable *m_tapLableVar3D = 
        m_tapLableUni3D->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    VfxTextureFrame *m_tapLabelTexture3D;
    VFX_OBJ_CREATE_EX(m_tapLabelTexture3D, VfxTextureFrame, m_tapLableVar3D, (m_lableTapFrame3D));
    m_tapLableVar3D->setValue(m_tapLabelTexture3D);
    
    //Artist
    VfxShaderUniforms *m_artistLableUni = 
        m_meshArtist->getMaterial(0)->getPass(0)->getShaderUniformList().begin()->get();
    VfxShaderVariable *m_artistLableVar = 
        m_artistLableUni->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    VfxTextureFrame *m_artistLabelTexture;
    VFX_OBJ_CREATE_EX(m_artistLabelTexture, VfxTextureFrame, m_artistLableVar, (m_lableArtistFrame));
    m_artistLableVar->setValue(m_artistLabelTexture); 

    //Album
    VfxShaderUniforms *m_albumLableUni = 
        m_meshAlbum->getMaterial(0)->getPass(0)->getShaderUniformList().begin()->get();
    VfxShaderVariable *m_albumLableVar = 
        m_albumLableUni->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    VfxTextureFrame *m_albumLabelTexture;
    VFX_OBJ_CREATE_EX(m_albumLabelTexture, VfxTextureFrame, m_albumLableVar, (m_lableAlbumFrame));
    m_albumLableVar->setValue(m_albumLabelTexture);     

    //slider background
    VfxShaderUniforms *m_SliderBgLableUni = 
        m_meshSliderBar->getMaterial(0)->getPass(0)->getShaderUniformList().begin()->get();
    VfxShaderVariable *m_sliderBgLableVar = 
        m_SliderBgLableUni->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    VfxTextureFrame *m_sliderBgTexture;
    VFX_OBJ_CREATE_EX(m_sliderBgTexture, VfxTextureFrame, m_sliderBgLableVar, (m_sliderBgImgFrame));
    m_sliderBgLableVar->setValue(m_sliderBgTexture);

    //Duration Time text
    VfxShaderUniforms *m_durationLableUni = 
        m_meshDuration->getMaterial(0)->getPass(0)->getShaderUniformList().begin()->get();
    m_durationLableVar = 
        m_durationLableUni->addUniformVariable(VFX_STR("uDiffuseSampler"), VFX_TYPE_ID_SAMPLER, 1);
    VFX_OBJ_CREATE_EX(m_durationLabelTexture, VfxTextureFrame, m_durationLableVar, (m_lableDurationFrame));
    m_durationLableVar->setValue(m_durationLabelTexture);      

    // Start a timer to update slider time
    VFX_OBJ_CREATE(m_timer_curr_time, VfxTimer, this);
    m_timer_curr_time->setStartDelay(0);
    m_timer_curr_time->setDuration(WIDGET_MP_TIMER_UPDATE_DURATION);
    m_timer_curr_time->m_signalTick.connect(this, &VappWidget3dMusicPlayerPanel::onCurrTimeTimerExpir);
    m_timer_curr_time->start();

    m_btnAdd->bringToFront();
}

void VappWidget3dMusicPlayerPanel::onCurrTimeTimerExpir(VfxTimer *timer)
{
    // If not in play state, do not update contect
    if((m_ctrlPlayback != NULL) && (PB_STATE_PLAY != m_ctrlPlayback->getPlayState()))
    {
        m_timer_curr_time->stop();
        return;
    }
    
    updateCurrentTime();
}

void VappWidget3dMusicPlayerPanel::onMDICallback(VfxS32 result)
{
    switch (result)
    {
        case VAPP_MUSICPLY_PRE_END_OF_FILE:
            m_sliderBarImgFrame->setHidden(VFX_FALSE);
            m_sliderBarImgFrame->setSize(m_slider_bar_size.width, m_slider_bar_size.height);
            break;

        case MDI_AUDIO_END_OF_FILE:
            // Not handle this case, it will be check in the state change signal
            break;

        case MDI_AUDIO_DUR_UPDATED:
        case VAPP_MUSICPLY_INTERRUPT_CB_INTERRUPT:
            updateDuration();
            break;

        default:
            break;
    }
}

void VappWidget3dMusicPlayerPanel::onPlaybackStateChange(PlaybackStateEnum state)
{
    switch(state)
    {
        case PB_STATE_NONE:
            updatePanel();
            break;
            
        case PB_STATE_OPEN:
            updatePanel();
            break;
            
        case PB_STATE_PLAY:
            //progress bar for duration
            m_timer_curr_time->start();
            updateButton();

            //play music note animation in 3d view
            if (m_2dMode == VFX_FALSE)
            {
                playLoopAnimation();
            }
            break;
            
        case PB_STATE_PAUSE:
            updateCurrentTime();
            updateButton();
            
            //stop music note animation in 3d view
            stopLoopAnimation();
          
            break;
            
        case PB_STATE_STOP:
            updateDuration();
            updateButton();

            //stop music note animation in 3d view
            stopLoopAnimation();
            break;
            
        case PB_STATE_CLOSE:
            updatePanel();
            break;
            
        case PB_STATE_PLAYBACK_FAIL:
            updateButton();
            break;            
            
        default:
            updateButton();
            break;
    }

}

mmi_ret VappWidget3dMusicPlayerPanel::staticEventHandler(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SRV_UCM_STATUS_CHANGE:
        {
            VappWidget3dMusicPlayerPanel* widget = (VappWidget3dMusicPlayerPanel*) evt->user_data;

            if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
            {
                widget->m_playPauseShaderVal->setValue(widget->playDisableTexture);
                widget->m_nextShaderVal->setValue(widget->nextDisableTexture);
                widget->m_prevShaderVal->setValue(widget->prevDisableTexture);
                
                widget->m_meshPlay->setPickable(VFX_FALSE);
                widget->m_meshPrev->setPickable(VFX_FALSE);
                widget->m_meshNext->setPickable(VFX_FALSE);                
            }
            else
            {
                if(widget->isValidState())
                {
                    widget->m_playPauseShaderVal->setValue(widget->playNormalTexture);
                    widget->m_nextShaderVal->setValue(widget->nextNormalTexture);
                    widget->m_prevShaderVal->setValue(widget->prevNormalTexture);
                    //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_NORMAL_PLAY);
                    widget->m_meshPlay->setPickable(VFX_TRUE);
                    widget->m_meshPrev->setPickable(VFX_TRUE);
                    widget->m_meshNext->setPickable(VFX_TRUE);   
                }
            }
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}


mmi_ret VappWidget3dMusicPlayerPanel::onAppOpenClose(mmi_event_struct *evt)
{
    VappMusicPlayerOpenCloseEvtStruct *openCloseEvt = (VappMusicPlayerOpenCloseEvtStruct*) evt;
    VappWidget3dMusicPlayerPanel* widget = (VappWidget3dMusicPlayerPanel*) evt->user_data;

    // App close
    if(openCloseEvt->isOpen)
    {
        widget->getAppControl();
        widget->updatePanel();
    }
    else
    {
        widget->m_mplayerSrv = NULL;
        widget->updatePanel();
    }

    widget->m_signalAppOpenClose.emit(widget, openCloseEvt->isOpen);
    
    return MMI_RET_OK;
}


mmi_ret VappWidget3dMusicPlayerPanel::onAppShowHide(mmi_event_struct *evt)
{
    VappMusicPlayerShowHideEvtStruct *showHideEvt = (VappMusicPlayerShowHideEvtStruct*) evt;
    VappWidget3dMusicPlayerPanel* widget = (VappWidget3dMusicPlayerPanel*) evt->user_data;

    /* Exit App */
    if(!showHideEvt->isShow)
    {
        widget->updatePanel();
    }

    return MMI_RET_OK;
}


void VappWidget3dMusicPlayerPanel::onBtnClicked(VfxObject *sender, VfxId id)
{
    switch (id)
    {
        case BTN_ADD_SONGS:

	          mmi_app_launch_param_struct launchParam;
	          launchParam.cat = MMI_LAUNCH_APP_IN_OPEN_CATEGORY;
	          VfxBool isNotLaunchFromMainMenu = VFX_TRUE;
	          launchParam.param = (void*)(&isNotLaunchFromMainMenu);
	          srv_appmgr_launch_ex("native.mtk.musicplayer", &launchParam, sizeof(mmi_app_launch_param_struct));

            updatePanel();
        break;
    }
}


void VappWidget3dMusicPlayerPanel::onPrevNext(VfxBool is_next)
{
    if(!m_2dMode)
    {
        // MAUI_03139017
        // Music note playing animation reset after playing a song for 1 second
        //if(is_next)
        //{
               playChangeSongAnimation();
        //}

       //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_ON_PREV_NEXT);
    }
    updatePanel();
}

void VappWidget3dMusicPlayerPanel::updateButton(void)
{
    //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_UPDATE_BTN);

    VfxBool in_call = VFX_FALSE;

    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        in_call = VFX_TRUE;
    }

    if(in_call || (m_ctrlPlayback == NULL) || !isValidState())
    {
        m_playPauseShaderVal->setValue(playDisableTexture);
        m_nextShaderVal->setValue(nextDisableTexture);
        m_prevShaderVal->setValue(prevDisableTexture);
        
        m_meshPlay->setPickable(VFX_FALSE);
        m_meshPrev->setPickable(VFX_FALSE);
        m_meshNext->setPickable(VFX_FALSE);
        //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_NOT_PLAYING);
    }
    else
    {
        VfxBool isPlayImage = VFX_TRUE;
        
        if (m_ctrlPlayback)
        {
            isPlayImage = m_ctrlPlayback->getPlayPauseState();
        }

        if(isPlayImage)
        {
            m_playPauseShaderVal->setValue(playNormalTexture);
            m_nextShaderVal->setValue(nextNormalTexture);
            m_prevShaderVal->setValue(prevNormalTexture);
            
            //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_NORMAL_PLAY);
        }
        else
        {
            m_playPauseShaderVal->setValue(pauseNormalTexture);
            m_nextShaderVal->setValue(nextNormalTexture);
            m_prevShaderVal->setValue(prevNormalTexture);
            //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_NORMAL_PAUSE);
        }

        // Check if need to disable play icon
        // Playback fail or interrupted in playback fail state, do not enable UI
        InterruptStruct interrupt = m_ctrlPlayback->getInterruptedInfo();
        if ((m_ctrlPlayback->getPlayState() == PB_STATE_PLAYBACK_FAIL) || (interrupt.isInterrupted && (interrupt.state == PB_STATE_PLAYBACK_FAIL)))
        {
            m_playPauseShaderVal->setValue(playDisableTexture);
            m_meshPlay->setPickable(VFX_FALSE);

        }
        else
        {
            //m_playPauseShaderVal->setValue(pauseNormalTexture);
            m_meshPlay->setPickable(VFX_TRUE);

        }
        m_meshPrev->setPickable(VFX_TRUE);
        m_meshNext->setPickable(VFX_TRUE);
    }
}

void VappWidget3dMusicPlayerPanel::updateCurrentTime(void)
{
    if(m_ctrlPlayback != NULL)
    {
        VfxU32 curr_time;
        VfxFloat bar_percent = 0;

        curr_time = m_ctrlPlayback->getCurrTime();

        if(m_duration > 0)
        {
            if(curr_time >= m_duration)
            {
                bar_percent = 1;
            }
            else
            {
                bar_percent = (VfxFloat)curr_time / (VfxFloat)m_duration;
            }
        }
        m_sliderBarImgFrame->setHidden(VFX_FALSE);
        m_sliderBarImgFrame->setSize(m_slider_bar_size.width*bar_percent, m_slider_bar_size.height);
        m_durationLableVar->setValue(m_durationLabelTexture);

    }
}

void VappWidget3dMusicPlayerPanel::updatePanel()
{
    if(!isValidState())
    {
        resetPanel();
        
        // Show tap to add songs string
        setTapTextVisible(VFX_TRUE);
        return;
     }
    
    // Hide tap to add songs string
    setTapTextVisible(VFX_FALSE);

    // If not in play state, do not update contect
    if(m_ctrlPlayback != NULL)
    {
        if(PB_STATE_NONE == m_ctrlPlayback->getPlayState())
        {
            resetPanel();
            return;
        }
    }    

    // Update image
    if(m_mplayerSrv != NULL)
    {
        VfxImageBuffer imgBuf;
        SongInfoStruct song_info;
        m_mplayerSrv->getCurrInfo(song_info);
        m_mplayerSrv->getAlbumCoverByDefaultBuffer(song_info.id, imgBuf);

        if(imgBuf.ptr != NULL)
        {
            VfxImageSrc imgSrc;
            imgSrc.setImageBuffer(imgBuf);
            setCover(imgSrc);
        }
        else
        {
            setCover(VfxImageSrc(IMG_ID_VAPP_WIDGET_3D_MUSPLY_DEFAULT_COVER));
        }
    }
    else
    {
        setCover(VfxImageSrc(IMG_ID_VAPP_WIDGET_3D_MUSPLY_DEFAULT_COVER));
    }

    // Get detail info and update title, album and artist 
   if(isValidState())
   {
       srv_plst_media_details_struct *detail_info = NULL;
       VFX_ALLOC_MEM(detail_info, sizeof(srv_plst_media_details_struct), this);

       if(m_mplayerSrv->getCurrDetailInfo(detail_info))
       {
            m_songTextFrame->setString(VFX_WSTR_MEM(detail_info->title));
            m_songTextFrame3D->setString(VFX_WSTR_MEM(detail_info->title));
            m_artistTextFrame->setString(VFX_WSTR_MEM(detail_info->album));
            m_albumTextFrame->setString(VFX_WSTR_MEM(detail_info->artist));
       }
       else
       {
           resetPanel();
       }

       VFX_FREE_MEM(detail_info);
   }
   else
   {
       resetPanel();
   }

    // Update duration and progress bar
    updateDuration();

    //Update button   
    updateButton();
    
}

void VappWidget3dMusicPlayerPanel::updateDuration(void)
{
    if(m_ctrlPlayback != NULL)
    {
        VfxU32 curr_time;

        // Update duration Text
        m_duration = m_ctrlPlayback->getDuration();
        curr_time = m_ctrlPlayback->getCurrTime();

        VfxWString strDuration;
        strDuration.format("%02d:%02d", m_duration/(60*1000), m_duration%(60*1000)/1000);
        m_durationTextFrame->setString(strDuration);

        // Update slider length 
        VfxFloat barPercent = 0;
        if(m_duration > 0)
        {
            if(curr_time >= m_duration)
            {
                barPercent = 1;
            }
            else
            {
                barPercent = (VfxFloat)curr_time / (VfxFloat)m_duration;
            }
        }
        m_sliderBarImgFrame->setHidden(VFX_FALSE);
        m_sliderBarImgFrame->setSize(m_slider_bar_size.width*barPercent, m_slider_bar_size.height);
    }
    else
    {
        // Update duration Text
        m_durationTextFrame->setString(VFX_WSTR(""));
        // Update slider length 
        //Todo: 0 not work, use hidden instead.
        m_sliderBarImgFrame->setSize(0, m_slider_bar_size.height);
        m_sliderBarImgFrame->setHidden(VFX_FALSE);
    }

}

void VappWidget3dMusicPlayerPanel::resetPanel(void)
{
    setCover(VfxImageSrc(IMG_ID_VAPP_WIDGET_3D_MUSPLY_DEFAULT_COVER));
    m_songTextFrame->setString(VFX_WSTR(" "));
    m_songTextFrame3D->setString(VFX_WSTR(" "));
    m_artistTextFrame->setString(VFX_WSTR(" "));
    m_albumTextFrame->setString(VFX_WSTR(" "));
    m_durationTextFrame->setString(VFX_WSTR(" "));
    m_sliderBarImgFrame->setSize(0, m_slider_bar_size.height);
    updateButton();
}

void VappWidget3dMusicPlayerPanel::setCover(const VfxImageSrc &value)
{
    m_lableCoverFrame->setImgContent(value);
    m_lableCD1Frame->setImgContent(value);

    //force frame dirty to update images
    m_lableCoverFrame->invalidate();
    m_lableCD1Frame->invalidate();
}
void VappWidget3dMusicPlayerPanel::setTapTextVisible(VfxBool is_visible)
{
    m_meshTextTap->setVisible(is_visible);
    m_meshTextTap3D->setVisible(is_visible);    
}

void VappWidget3dMusicPlayerPanel::playAnimation()
{
    //to control first swipe up and down
    m_isAniPlayed = VFX_TRUE;
    
    if (m_2dMode) //2d to 3d
    {
        m_refTimeLine->setDuration(2000);
        m_refTimeLine->setFromValue(0.0f);
        m_refTimeLine->setToValue(0.32f);
        
        m_2dMode = VFX_FALSE;
        m_refTimeLine->m_signalStopped.connect(this,&VappWidget3dMusicPlayerPanel::on1stAniStopped);

        //adjust the bounds of add song button in 3d view
        m_btnAdd->setBounds(VfxRect(0, 0, BTN_BundAddX3D, BTN_BundAddY3D));
        m_btnAdd->setPos(VfxPoint(BTN_ADD_X_3D, BTN_ADD_Y_3D));
    }
    else         //3d to 2d
    {
        //disable particle
        m_groupParticle->setVisible(VFX_FALSE);
        m_refTlParticle->stop();
        
        m_refTimeLine->setDuration(1500);
        m_refTimeLine->setFromValue(0.78f);//0.35 for music sign
        m_refTimeLine->setToValue(1.0f);
        
        m_2dMode = VFX_TRUE;
        
        //adjust the bounds of add song button in 2d view
        m_btnAdd->setBounds(VfxRect(0, 0, BTN_BundAddX2D, BTN_BundAddY2D));
        m_btnAdd->setPos(VfxPoint(BTN_ADD_X_2D, BTN_ADD_Y_2D));   
    }

    anim->setTimelineTime(m_refTimeLine); 
    m_refTimeLine->start();
}


void VappWidget3dMusicPlayerPanel::configAnimation(void)
{
    //Create Animation
    VFX_OBJ_CREATE(anim, VfxAnimation, sceneWorld);
    VfxAssetLoader::loadAnimation(anim, sceneWorld, VAPP_WIDGET_3D_MUSIC_PLAYER_ANI);

    //Create reference timeline for angle.
    VFX_OBJ_CREATE(m_refTimeAngle, VfxFloatTimeline, sceneWorld);
    m_refTimeAngle->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTimeAngle->setTarget(sceneWorld);
    m_refTimeAngle->setAutoReversed(VFX_TRUE);
    m_refTimeAngle->setDuration(5000);
    m_refTimeAngle->setRepeatCount(1);

    //Create reference timeline for change disk animation
    VFX_OBJ_CREATE(m_tlChangeDisk, VfxFloatTimeline, sceneWorld);
    m_tlChangeDisk->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_tlChangeDisk->setTarget(sceneWorld);
    m_tlChangeDisk->setDuration(1000);
    m_tlChangeDisk->setRepeatCount(1);
   
    // Create reference timeline for reverse.
    VFX_OBJ_CREATE(m_refTimeLine, VfxFloatTimeline, sceneWorld);
    m_refTimeLine->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTimeLine->setTarget(sceneWorld);

    m_refTimeLine->setAutoReversed(VFX_TRUE);
    m_refTimeLine->setRepeatCount(1);

    //Create time line for repeating music note.  
    VFX_OBJ_CREATE(m_refTimeLineLoop, VfxFloatTimeline, sceneWorld);
    m_refTimeLineLoop->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTimeLineLoop->setTarget(sceneWorld);
    m_refTimeLineLoop->setDuration(1500);
    m_refTimeLineLoop->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);

    //Create background timeline to avoid timeline reset by VRT
    VFX_OBJ_CREATE(m_refTimeBg, VfxFloatTimeline, sceneWorld);
    m_refTimeBg->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTimeBg->setTarget(sceneWorld);
    m_refTimeBg->setDuration(1500);
    m_refTimeBg->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);    
   
}

void VappWidget3dMusicPlayerPanel::stopLoopAnimation(void)
{
    if(m_tlChangeDisk->getIsEnabled() || m_refTimeLine->getIsEnabled())
    {
        return;
    }
    
    if (m_2dMode == VFX_FALSE)
    {
        m_refTimeLineLoop->stop();
        m_refTimeLine->stop();

        //particle           
        m_refTlParticle->stop();
        m_groupParticle->setVisible(VFX_FALSE);
    }  
}
void VappWidget3dMusicPlayerPanel::playLoopAnimation(void)
{
    if(m_refTimeLine->getIsEnabled() || m_tlChangeDisk->getIsEnabled())
    {
        return;
    }

    // Play music note continuously if it is a playing song
    m_refTimeLineLoop->setFromValue(0.32f);
    m_refTimeLineLoop->setToValue(0.68f);
    anim->setTimelineTime(m_refTimeLineLoop);
    m_refTimeLineLoop->start();

    //loadParticle();
    m_refTlParticle->start();
    m_groupParticle->setVisible(VFX_TRUE);
}

void VappWidget3dMusicPlayerPanel::play0To0Animation(void)
{
    // no playing song, animation stopped.
    // set anim value from 1 to 1 (or 0 to 0) to avoid it starts from 0, while widget return from dailler.
    // Reason: VRT will clean the timeline to 0 when widget left home screen

    m_refTimeBg->setFromValue(0.0f);
    m_refTimeBg->setToValue(0.0f);
    m_refTimeBg->setRepeatCount(1);
    anim->setTimelineTime(m_refTimeBg);
    m_refTimeBg->start();     
}
void VappWidget3dMusicPlayerPanel::play1To1Animation(void)
{
    if(m_refTimeLine->getIsEnabled())
    {
        return;
    }

    m_refTimeBg->setFromValue(0.78f);
    m_refTimeBg->setToValue(0.78f);
    m_refTimeBg->setRepeatCount(1);
    anim->setTimelineTime(m_refTimeBg);
    m_refTimeBg->start(); 
}

void VappWidget3dMusicPlayerPanel::playChangeSongAnimation(void)
{
    m_tlChangeDisk->setFromValue(0.68f);
    m_tlChangeDisk->setToValue(0.78f);
    m_tlChangeDisk->setRepeatCount(1);
    anim->setTimelineTime(m_tlChangeDisk);
    m_tlChangeDisk->m_signalStopped.connect(this,&VappWidget3dMusicPlayerPanel::onSongAniChanged);
    m_tlChangeDisk->start(); 

}

void VappWidget3dMusicPlayerPanel::onSongAniChanged(VfxBaseTimeline *source, VfxBool isComplete)
{
    //Scenario: 1st song-> 2nd song automatically or use BT swtiching.
    //therefore, need to make sure change disc has been played completely.
    if(!m_2dMode)
    {
        if ((m_ctrlPlayback != NULL) && (PB_STATE_PLAY == m_ctrlPlayback->getPlayState()))
        {
            //play loop animation
            m_refTimeLineLoop->setFromValue(0.32f);
            m_refTimeLineLoop->setToValue(0.68f);
            anim->setTimelineTime(m_refTimeLineLoop);
            m_refTimeLineLoop->start();
            //loadParticle();
            m_refTlParticle->start();
            m_groupParticle->setVisible(VFX_TRUE);
        }
        else
        {
            //stop music particle
            m_refTlParticle->stop();
            m_groupParticle->setVisible(VFX_FALSE);
        }
    }
}

void VappWidget3dMusicPlayerPanel::on1stAniStopped(VfxBaseTimeline *source, VfxBool isComplete)
{
    if (isComplete)
    {
        onSelectNextAnimation();
    }
}

void VappWidget3dMusicPlayerPanel::onSelectNextAnimation()
{
    // Play music note continuously if it is a playing song. 
    if(m_2dMode) //2d mode
    {
        play0To0Animation();
    }
    else         //3d mode
    {
        if((m_ctrlPlayback != NULL) && (PB_STATE_PLAY == m_ctrlPlayback->getPlayState()))            
        {
            playLoopAnimation(); //TODO: refactoring to playAnimation(timeline,range(loop,1to1,..etc),callback,);
        }
        else 
        {
            play1To1Animation();
        }
    }

}

void VappWidget3dMusicPlayerPanel::loadParticle()
{
    //load particle scene
    VfxResId particleScene = 0, particleAni = 0;
    particleScene = VAPP_WIDGET_3D_MUSIC_PLAYER_PARTICLE_SCN;
    particleAni = VAPP_WIDGET_3D_MUSIC_PLAYER_PARTICLE_ANI;
    
    VFX_OBJ_CLOSE(m_groupParticle);
    VFX_OBJ_CREATE(m_groupParticle, VfxGroup, sceneWorld);
    VfxAssetLoader::loadScene(m_groupParticle, particleScene);

    VfxAnimation *m_animParticle;       
    VFX_OBJ_CREATE(m_animParticle, VfxAnimation, m_groupParticle);
    VfxAssetLoader::loadAnimation(m_animParticle, m_groupParticle,particleAni);     
    m_groupParticle->setVisible(VFX_FALSE);

    VFX_OBJ_CREATE(m_refTlParticle, VfxFloatTimeline, m_groupParticle);
    m_refTlParticle->setTargetPropertyId(VRT_CUSTOM_PROPERTY_ID_VAR_FLOAT);
    m_refTlParticle->setTarget(m_groupParticle);
    m_refTlParticle->setDuration(3000);
    m_refTlParticle->setRepeatCount(VFX_TIMELINE_REPEAT_INFINITE);
    m_refTlParticle->setFromValue(0.0f);
    m_refTlParticle->setToValue(1.0f);
    m_animParticle->setTimelineTime(m_refTlParticle);
    m_refTlParticle->start();//start on first init.
}

VfxBool VappWidget3dMusicPlayerPanel::onPenInput(VfxPenEvent &event)
{
    if(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_NO_CSD, NULL) > 0)
    {
        return 0;
    }

    VfxPoint pos = event.getRelPos(this);
    VfxSize size = this->getSize();
    VfxFloat x = (VfxFloat)pos.x;
    VfxFloat y = (VfxFloat)pos.y;
    VfxFloat w = (VfxFloat)size.width;
    VfxFloat h = (VfxFloat)size.height;

    //Camera
    VfxCamera *camera;
    camera = sceneWorld->getActiveCamera();
    VFX_DEV_ASSERT(camera != NULL);
    
    VfxVector3f orig;
    camera->getWorldPosition(orig);

    VfxVector3f worldPos = camera->unproject(VfxVector3f(
        (VfxFloat)(pos.x * 2) / w - 1.0f,
        -((VfxFloat)(pos.y * 2) / h - 1.0f),
        -1.0f));
    VfxVector3f dir = worldPos - orig;
    VfxNode *pickNode = sceneWorld->pick(orig, dir);
    
    //check if it is playing
    VfxBool isPlayImage = VFX_TRUE;
    if (m_ctrlPlayback)
    {
            isPlayImage = m_ctrlPlayback->getPlayPauseState();
    }

    switch (event.type)
    {
    //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_PEN_RECEIVED);
    
	    case VFX_PEN_EVENT_TYPE_DOWN:
            //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_PEN_DOWN);

            //set pressed button effect
            if (pickNode == m_meshPlay)
            {
                if (isPlayImage)
                {
                    m_playPauseShaderVal->setValue(playPressTexture);            
                }
                else
                {
                    m_playPauseShaderVal->setValue(pausePressTexture);
                }

            }
            else if (pickNode == m_meshPrev)
            {
                m_prevShaderVal->setValue(prevPressTexture);                    
                //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_PRESSED_PREV);
            }
            else if (pickNode == m_meshNext)
            {
                m_nextShaderVal->setValue(nextPressTexture);
                //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_PRESSED_NEXT);                 
            }
            else
            {
                updateButton();
            }            
            break;
            
        case VFX_PEN_EVENT_TYPE_UP:
            //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_PEN_UP);
            if (pickNode == m_meshPlay)
            {
                updateButton(); // to get normal button images
                onPlayPause();
            }
            else if (pickNode == m_meshPrev)
            {
                updateButton();
                m_isPlayNext = VFX_FALSE;

                //play previous song
                    onPrev();
                }
            else if (pickNode == m_meshNext)
            {
                updateButton();
                m_isPlayNext = VFX_TRUE;
                
                //play next song
                    onNext();
                }
            else
            {
                updateButton();
            }
            break;

        case VFX_PEN_EVENT_TYPE_MOVE:
                //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_PEN_MOVE);
		updateButton();
		break;

		case VFX_PEN_EVENT_TYPE_ABORT:
                //MMI_TRACE(MMI_COMMON_TRC_G3_IDLE,TRC_VAPP_WIDGET_3D_MPLYER_PEN_ABORT);
	        updateButton();
            break;
                
        default:
            updateButton();
            break;            
    }

    return VFX_TRUE;
}


/*****************************************************************************
 * 3D  Music Player Widget
 *****************************************************************************/

VAPP_WIDGET_SYS_PUBLISH_NATIVE(
    VappWidget3dMusicPlayer,
    VAPP_WIDGET_TYPE_3D_MUSIC_PLAYER,
    VappWidget3dMusicPlayerPublisher);

VAPP_WIDGET_IMPLEMENT_CLASS(VappWidget3dMusicPlayer,VappWidgetMiniStage);

VappWidget3dMusicPlayer::VappWidget3dMusicPlayer() :
    m_contentPanel(NULL)
{
    // Do nothing.
}

VappWidgetId VappWidget3dMusicPlayer::getId() const
{
    return VappWidgetId(VAPP_WIDGET_SRC_NATIVE, VAPP_WIDGET_TYPE_3D_MUSIC_PLAYER);
}

VfxSize VappWidget3dMusicPlayer::getMaxSize() const
{
    return VfxSize(MAX_SIZE_WIDTH, MAX_SIZE_HEIGHT);
}

VfxS32 VappWidget3dMusicPlayer::getName(VfxWChar *string, VfxS32 size) const
{
    const VfxWChar *str = vfxSysResGetStr(STR_ID_VAPP_WIDGET_3D_MUSIC_PLAYER);

    VFX_ASSERT(string && size > 0);

    mmi_wcsncpy((WCHAR *)string, (const WCHAR *)str, size - 1);

    return vfx_sys_wcslen(string);

}

VfxFrame *VappWidget3dMusicPlayer::createIcon(VfxObject *parentObj)
{
    VfxImageFrame *icon;
	VFX_OBJ_CREATE(icon, VfxImageFrame, parentObj);
    icon->setResId(IMG_ID_VAPP_WIDGET_3D_MUSIC_PLAYER_ICON);

    return icon;
}

void VappWidget3dMusicPlayer::onCreateView()
{
    MPL_MEASURE_TIME_START("MCR");

    VappWidgetMiniStage::onCreateView();

    setBounds(VfxRect(0, 0, WIDTH, HEIGHT));
   
    VFX_OBJ_CREATE(m_contentPanel, VappWidget3dMusicPlayerPanel,this);
    m_contentPanel->setSize(WIDTH,HEIGHT);
    m_contentPanel->setPos(0,0);
    
    MPL_MEASURE_TIME_STOP("MCR");

}

void VappWidget3dMusicPlayer::onSwipeUp()
{
    //2d to 3d
    
    if (m_contentPanel->m_2dMode == VFX_TRUE)
    {
        if(m_contentPanel->m_isAniPlayed == VFX_TRUE &&
            m_contentPanel->m_refTimeBg->getIsEnabled())
        {
            m_contentPanel->m_refTimeBg->stop();
        }    
        m_contentPanel->playAnimation();
    }
}

void VappWidget3dMusicPlayer::onSwipeDown()
{
    //3d to 2d
    
    if (m_contentPanel->m_2dMode == VFX_FALSE)
    {
        if(m_contentPanel->m_isAniPlayed == VFX_TRUE &&
            m_contentPanel->m_refTimeBg->getIsEnabled() ||
            m_contentPanel->m_refTimeLine->getIsEnabled())
        {
            m_contentPanel->m_refTimeBg->stop();
            m_contentPanel->m_refTimeLine->stop();
        }
        m_contentPanel->playAnimation();
    }

}

void VappWidget3dMusicPlayer::onSwipeToNearestView()
{
}

void VappWidget3dMusicPlayer::onRotateX(VfxFloat angle)
{
}

VfxPoint VappWidget3dMusicPlayer::onGetEditButtonOffset()
{
    return VfxPoint(getSize().width - EDIT_BTN_2D_OFFSET_X, EDIT_BTN_2D_OFFSET_Y);
}


void VappWidget3dMusicPlayer::onSuspend()
{
    setCacheMode(VFX_CACHE_MODE_FREEZE);
}
void VappWidget3dMusicPlayer::onResume()
{
    setCacheMode(VFX_CACHE_MODE_AUTO);
}


void VappWidget3dMusicPlayer::onRestoreViewForPageSwitch(VfxArchive *ar)
{

    m_contentPanel->onSelectNextAnimation();
}

void VappWidget3dMusicPlayer::onRestoreView(VfxArchive *ar)
{

    MPL_MEASURE_TIME_START("MRS");
    
    m_contentPanel->onSelectNextAnimation();

    MPL_MEASURE_TIME_STOP("MRS");

}
void VappWidget3dMusicPlayer::onReleaseView()
{
    MPL_MEASURE_TIME_START("MRL");

    VFX_OBJ_CLOSE(m_contentPanel);
    VappWidgetMiniStage::onReleaseView();

    MPL_MEASURE_TIME_START("MRL");    
}
#endif /* defined(__MMI_VUI_WIDGET_3D_MUSIC_PLAYER__) */
