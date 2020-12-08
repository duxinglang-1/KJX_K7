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
 *  vapp_widget_3d_clock.res
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the resources of 3d clock widget
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
 * 04 12 2012 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Clock & Music Player Widgets Check In
 * Wrap new 3D compile option .
 *
 * 01 18 2012 ch.ko
 * [MAUI_03118855] Check-in Cosmos 2.0 launcher and screen lock
 * Check-in patch.
 *
 * 11 21 2011 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Clock & Music Player Widgets Check In
 * . [Clock] Particle & Reflection(stencil buffer) check in and bugs fixed.
 *
 * 10 13 2011 andy.kauo
 * [MAUI_03041392] [Resgen][3D] 3D resource auto gen
 * . support auto resource gen to reduce resource range..
 *
 * 09 15 2011 andy.kauo
 * [MAUI_02986399] [Cosmos 3D] 3D Clock & Music Player Widgets Check In
 * . 
 * Morphing effect added.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "CustResDef.h"

#if defined(__MMI_VUI_WIDGET_3D_CLOCK__)

/*****************************************************************************
 * XML
 *****************************************************************************/
<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_3D_CLOCK" type="venus">
    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_3D_CLOCK"/>
    <!-- Image Resource Area--------------------------------------------------->

#ifndef RES_BIN_V3D_THEME_ROOT
#define RES_BIN_V3D_THEME_ROOT          RES_THEME_ROOT
#define RES_BIN_V3D_COMMON_PATH         RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Common\\\\"
#define RES_BIN_V3D_COMMON_SHADER_PATH  RES_BIN_V3D_COMMON_PATH"\\\\Shader\\\\"
#define RES_BIN_V3D_COMMON_IMAGE_PATH   RES_BIN_V3D_COMMON_PATH"\\\\Image\\\\"
#endif /* RES_BIN_V3D_THEME_ROOT */


    <!--App stencil reflection shader -->
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_REFLECT_VS" base_path="current">"pnt2tlvn_refl.vs"</BINARY3D>
    		
		<!--App Scene & Animation-->
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_CLOCK_ICON">RES_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\Clock\\\\Icon\\\\3d_clock.png"</IMAGE>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_ANI">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Clock\\\\Clock.ani"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_SCN">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Clock\\\\Clock.scn"</BINARY3D>
    
    <!-- App Particle -->
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_PARTICLE_NOON_SCN">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Particle_leaf\\\\Particle_leaf.scn"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_PARTICLE_NOON_ANI">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Particle_leaf\\\\Particle_leaf.ani"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_PARTICLE_MORNING_SCN">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Particle_dandelion\\\\Particle_dandelion.scn"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_PARTICLE_MORNING_ANI">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Particle_dandelion\\\\Particle_dandelion.ani"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_PARTICLE_SUNSET_SCN">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Particle_bird\\\\Particle_bird.scn"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_PARTICLE_SUNSET_ANI">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Particle_bird\\\\Particle_bird.ani"</BINARY3D>    
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_PARTICLE_NIGHT_SCN">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Particle_firefly\\\\Particle_firefly.scn"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_PARTICLE_NIGHT_ANI">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Particle_firefly\\\\Particle_firefly.ani"</BINARY3D>        

    <!--App Background replacement_Morning -->
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_MORNING_SKY">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\MorningNoon_Scene\\\\Sky_Morning.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_MORNING_CLOUD">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\MorningNoon_Scene\\\\Cloud_Morning.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_MORNING_PLANET">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\MorningNoon_Scene\\\\Planet_Morning.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_MORNING_LIGHT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\MorningNoon_Scene\\\\Light_Morning.mtl"</BINARY3D>    
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_MORNING_LOFT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\MorningNoon_Scene\\\\Loft_Morning.mtl"</BINARY3D>     
       
    <!--App Background replacement_Noon -->
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NOON_SKY">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\MorningNoon_Scene\\\\Sky_Noon.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NOON_CLOUD">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\MorningNoon_Scene\\\\Cloud_Noon.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NOON_PLANET">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\MorningNoon_Scene\\\\Planet_Noon.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NOON_LIGHT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\MorningNoon_Scene\\\\Light_Noon.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NOON_LOFT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\MorningNoon_Scene\\\\Loft_Noon.mtl"</BINARY3D>
    
    <!--App Background replacement_Sunset -->
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_SUNSET_SKY">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\NightSunset_Scene\\\\Sky_Sunset.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_SUNSET_CLOUD">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\NightSunset_Scene\\\\Cloud_Sunset.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_SUNSET_PLANET">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\NightSunset_Scene\\\\Planet_Sunset.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_SUNSET_LIGHT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\NightSunset_Scene\\\\Light_Sunset.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_SUNSET_LOFT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\NightSunset_Scene\\\\Loft_Sunset.mtl"</BINARY3D>

    <!--App Background replacement_NightFall -->
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NIGHT_SKY">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\NightSunset_Scene\\\\Sky_Night.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NIGHT_CLOUD">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\NightSunset_Scene\\\\Cloud_Night.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NIGHT_PLANET">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\NightSunset_Scene\\\\Planet_Night.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NIGHT_LIGHT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\NightSunset_Scene\\\\Light_Night.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NIGHT_LOFT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\NightSunset_Scene\\\\Loft_Night.mtl"</BINARY3D>
            
    <!--APP Font Model -->
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT0">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Num0-mesh.msh"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT1">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Num1-mesh.msh"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT2">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Num2-mesh.msh"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT3">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Num3-mesh.msh"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT4">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Num4-mesh.msh"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT5">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Num5-mesh.msh"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT6">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Num6-mesh.msh"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT7">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Num7-mesh.msh"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT8">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Num8-mesh.msh"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT9">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Num9-mesh.msh"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONTP">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Text_P-mesh.msh"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONTA">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font\\\\Text_A-mesh.msh"</BINARY3D>
    
    <!--APP Font materials -->
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT_MTL_MORNING1">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font_Mtl\\\\Font_Morning1.mtl"</BINARY3D>    
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT_MTL_MORNING2">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font_Mtl\\\\Font_Morning2.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT_MTL_NOON1">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font_Mtl\\\\Font_Noon1.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT_MTL_NOON2">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font_Mtl\\\\Font_Noon2.mtl"</BINARY3D>    
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT_MTL_SUNSET1">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font_Mtl\\\\Font_Sunset1.mtl"</BINARY3D>        
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT_MTL_SUNSET2">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font_Mtl\\\\Font_Sunset2.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT_MTL_NIGHT1">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font_Mtl\\\\Font_Night1.mtl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_FONT_MTL_NIGHT2">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Font_Mtl\\\\Font_Night2.mtl"</BINARY3D>     
    
    <!-- APP Light Scale-->
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NIGHT_LIGHT1">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Light_Scale_Ani\\\\Light_Scale_Ani_Light_1_S2-node-scale.tl"</BINARY3D> 
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NIGHT_LIGHT2">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Light_Scale_Ani\\\\Light_Scale_Ani_Light_2_S2-node-scale.tl"</BINARY3D>

    <!-- App Ambient -->
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NIGHT_AMBIENT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Ambient\\\\Ambient_Night\\\\Ambient_Night_uAmbient.tl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NIGHT_AMBIENT_1">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Ambient\\\\Ambient_Night\\\\Ambient_Night_uAmbient1.tl"</BINARY3D>
    <!-- ambient, new converter with prefix name-->
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_MORNING_AMBIENT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Ambient\\\\Ambient_Morning\\\\uAmbient.tl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_MORNING_AMBIENT_1">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Ambient\\\\Ambient_Morning\\\\uAmbient1.tl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NOON_AMBIENT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Ambient\\\\Ambient_Noon\\\\Ambient_Noon_uAmbient.tl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_NOON_AMBIENT_1">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Ambient\\\\Ambient_Noon\\\\Ambient_Noon_uAmbient1.tl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_SUNSET_AMBIENT">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Ambient\\\\Ambient_Sunset\\\\Ambient_Sunset_uAmbient.tl"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_CLOCK_SUNSET_AMBIENT_1">RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Widget\\\\Clock\\\\Ambient\\\\Ambient_Sunset\\\\Ambient_Sunset_uAmbient1.tl"</BINARY3D>    
		                                                                                                                      
    <!--The resources from converter are listed below-->
    <!-- Night Light -->
    <BINARY3D id="V3D_GEN_ID__DEFAULT_3D_WIDGET_CLOCK_LIGHT_SCALE_ANI_LIGHT_SCALE_ANI_LIGHT_1_S2_NODE_SCALE_KFS">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\Clock\\\\Light_Scale_Ani\\\\Light_Scale_Ani_Light_1_S2-node-scale.kfs"</BINARY3D>
    <BINARY3D id="V3D_GEN_ID__DEFAULT_3D_WIDGET_CLOCK_LIGHT_SCALE_ANI_LIGHT_SCALE_ANI_LIGHT_2_S2_NODE_SCALE_KFS">RES_BIN_V3D_THEME_ROOT"\\\\default\\\\3D\\\\Widget\\\\Clock\\\\Light_Scale_Ani\\\\Light_Scale_Ani_Light_2_S2-node-scale.kfs"</BINARY3D>

    <!-- Event Area (Receiver) ------------------------------------------------>
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidget3dClockPublisher"/>
</APP>
#endif /*__MMI_VUI_WIDGET_3D_CLOCK__*/
