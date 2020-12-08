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
 *  vapp_widget_3d_music_player.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resources of 3d music player widget
 *
 * Author:
 * -------
 *  Andy Kauo (mtk03823)
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 08 2012 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Clock & Music Player Widgets Check In
 * . Pop-up theme resource of slider bar images.
 *
 * 04 12 2012 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Clock & Music Player Widgets Check In
 * Wrap new 3D compile option .
 *
 * 04 03 2012 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Clock & Music Player Widgets Check In
 * . Change image resource from png to ktx.
 *
 * 01 18 2012 ch.ko
 * [MAUI_03118855] Check-in Cosmos 2.0 launcher and screen lock
 * Check-in patch.
 *
 * 11 08 2011 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Clock & Music Player Widgets Check In
 * . Check in new music particle model and bugs fixed.
 *
 * 10 13 2011 andy.kauo
 * [MAUI_03041392] [Resgen][3D] 3D resource auto gen
 * . support auto resource gen to reduce resource range..
 *
 * 10 10 2011 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Clock & Music Player Widgets Check In
 * . [3D Music Player] Check in new design model.
 *
 * 08 26 2011 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Clock & Music Player Widgets Check In
 * .Add new feature and fix bugs.
 *
 * 08 06 2011 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Clock & Music Player Widgets Check In
 * Bugs fixed.
 *
 * 08 03 2011 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Music Player Check In
 * 3D check in.
 *
 * 07 25 2011 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Music Player Check In
 * Music & Clock Check in.
 *
 * 07 19 2011 pablo.sun
 * [MAUI_02986150] [COSMOS 3D]3D slideshow check-in
 * .fix 3D widget resgen error
 *
 * 07 18 2011 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Music Player Check In
 * 3D Widgets Resource Check In.
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "CustResDef.h"

#if defined(__MMI_VUI_WIDGET_3D_MUSIC_PLAYER__) && defined(__MMI_VUI_WIDGET_MUSIC_PLAYER__)

/*****************************************************************************
 * XML
 *****************************************************************************/
<?xml version="1.0" encoding="UTF-8"?>
<APP id="VAPP_WIDGET_3D_MUSIC_PLAYER" type="venus">

    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_3D_MUSIC_PLAYER"/>
    <STRING id="STR_ID_VAPP_WIDGET_3D_MUSIC_TAP_TO_ADD_SONG"/>

#ifndef RES_BIN_V3D_THEME_ROOT
#define RES_BIN_V3D_THEME_ROOT          RES_THEME_ROOT
#define RES_BIN_V3D_COMMON_PATH         RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Common\\\\"
#define RES_BIN_V3D_COMMON_SHADER_PATH  RES_BIN_V3D_COMMON_PATH"\\\\Shader\\\\"
#define RES_BIN_V3D_COMMON_IMAGE_PATH   RES_BIN_V3D_COMMON_PATH"\\\\Image\\\\"
#endif /* RES_BIN_V3D_THEME_ROOT */

    <!--3D scene & animation-->
    <BINARY3D id="VAPP_WIDGET_3D_MUSIC_PLAYER_ANI">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\MusicPlayer\\\\MusicPlayer.ani"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_MUSIC_PLAYER_SCN">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\MusicPlayer\\\\MusicPlayer.scn"</BINARY3D>
    
    <!--Particle -->
    <BINARY3D id="VAPP_WIDGET_3D_MUSIC_PLAYER_PARTICLE_ANI">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\MusicPlayer_Particle\\\\MusicPlayer_Particle.ani"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_MUSIC_PLAYER_PARTICLE_SCN">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\MusicPlayer_Particle\\\\MusicPlayer_Particle.scn"</BINARY3D>
    
    <!-- ICON & Slider Bar-->
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSIC_PLAYER_ICON">RES_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Icon\\\\3d_music_player.png"</IMAGE>

    <THEME>
        <IMAGE id="VAPP_WIDGET_3D_MUSIC_PLAYER_SLIDER_BG" desc="wiget music player progress bar background"/>
        <IMAGE id="VAPP_WIDGET_3D_MUSIC_PLAYER_SLIDER_BAR" desc="wiget music player progress bar"/>
    </THEME>
    
    <!-- Default album cover -->
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_DEFAULT_COVER">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\MusicSignDefault.ktx"</IMAGE>       
    
    <!-- Button-->
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PLAY_NORMAL">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_play_normal.ktx"</IMAGE>   
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PAUSE_NORMAL">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_pause_normal.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_NEXT_NORMAL">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_next_normal.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PREV_NORMAL">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_prev_normal.ktx"</IMAGE>
    
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PLAY_PRESS">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_play_press.ktx"</IMAGE>   
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PAUSE_PRESS">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_pause_press.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_NEXT_PRESS">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_next_press.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PREV_PRESS">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_prev_press.ktx"</IMAGE>
    
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PLAY_DISABLE">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_play_disable.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PAUSE_DISABLE">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_pause_disable.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_NEXT_DISABLE">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_next_disable.ktx"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_MUSPLY_BTN_PREV_DISABLE">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\MusicPlayer\\\\Texture\\\\btn_prev_disable.ktx"</IMAGE>

    <!-- Event Area (Receiver) ------------------------------------------------>
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidget3dMusicPlayerPublisher"/>
</APP>
#endif /*__MMI_VUI_WIDGET_3D_MUSIC_PLAYER__*/
