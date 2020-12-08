#include "mmi_features.h"
#include "custresdef.h"

#if defined(__MMI_VUI_WIDGET_3D_PET__)

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_WIDGET_3D_PET" type="venus">

<!-----------------------------------------------------String Section------------------------------------------------------>
    <STRING id="STR_ID_VAPP_WIDGET_3D_PET_NAME">"Pet"</STRING>

<!-----------------------------------------------------Image Section ------------------------------------------------------>
    <IMAGE id="IMG_ID_VAPP_WIDGET_3D_PET_ICON">RES_IMG_ROOT"\\\\Widget\\\\3dPet\\\\3d_pet.png"</IMAGE>


<!-----------------------------------------------------  3D Section  ------------------------------------------------------>
#ifndef RES_BIN_V3D_THEME_ROOT
#define RES_BIN_V3D_THEME_ROOT          RES_THEME_ROOT
#define RES_BIN_V3D_COMMON_PATH         RES_BIN_V3D_THEME_ROOT"\\\\Default\\\\3D\\\\Common\\\\"
#define RES_BIN_V3D_COMMON_SHADER_PATH  RES_BIN_V3D_COMMON_PATH"\\\\Shader\\\\"
#define RES_BIN_V3D_COMMON_IMAGE_PATH   RES_BIN_V3D_COMMON_PATH"\\\\Image\\\\"
#endif

    <!------------------ animation ------------------->
    #define RES_VAPP_WIDGET_3D_PET_ROOT           RES_IMG_ROOT"\\\\3D\\\\Widget\\\\Sheep\\\\"
    #define RES_VAPP_WIDGET_3D_PET_STAGE          RES_IMG_ROOT"\\\\3D\\\\Widget\\\\Sheep\\\\stage\\\\"
    #define RES_VAPP_WIDGET_3D_PET_SHEEP          RES_IMG_ROOT"\\\\3D\\\\Widget\\\\Sheep\\\\sheep\\\\"
    #define RES_VAPP_WIDGET_3D_PET_SYM_Z          RES_IMG_ROOT"\\\\3D\\\\Widget\\\\Sheep\\\\text_Z\\\\"    
    #define RES_VAPP_WIDGET_3D_PET_SYM_E          RES_IMG_ROOT"\\\\3D\\\\Widget\\\\Sheep\\\\text_E\\\\"    
    #define RES_VAPP_WIDGET_3D_PET_SYM_Q          RES_IMG_ROOT"\\\\3D\\\\Widget\\\\Sheep\\\\text_Q\\\\"        
    #define RES_VAPP_WIDGET_3D_PET_SYM_1UP        RES_IMG_ROOT"\\\\3D\\\\Widget\\\\Sheep\\\\text_1up\\\\"
    #define RES_VAPP_WIDGET_3D_PET_GRASS          RES_IMG_ROOT"\\\\3D\\\\Widget\\\\Sheep\\\\grass\\\\"
    #define RES_VAPP_WIDGET_3D_PET_RAILING          RES_IMG_ROOT"\\\\3D\\\\Widget\\\\Sheep\\\\railing\\\\"
    #define RES_VAPP_WIDGET_3D_PET_TEXTURE        RES_IMG_ROOT"\\\\3D\\\\Widget\\\\Sheep\\\\texture\\\\"
    
    <!-- stage, symbols and sheep char -->
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_STAGE">RES_VAPP_WIDGET_3D_PET_STAGE"stage.scn"</BINARY3D> 
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_STAGE_ANIM">RES_VAPP_WIDGET_3D_PET_STAGE"stage.ani"</BINARY3D>          
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_CHR">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep.chr"</BINARY3D>
    
    <!-- sheep animation -->
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_WALK_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_166_566.ani"</BINARY3D>    
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_STAND_LOOK_AROUND_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_1000_4366.ani"</BINARY3D>  
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_STAND_STRETCH_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_4500_7733.ani"</BINARY3D>  
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_STAND_SHAKE_HEAD_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_7833_9333.ani"</BINARY3D>  

    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_EAT_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_9500_12333.ani"</BINARY3D>  
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_SLEEP_START_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_12666_15500.ani"</BINARY3D>  
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_SLEEP_LOOP_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_15666_20666.ani"</BINARY3D>  
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_SLEEP_END_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_21000_22433.ani"</BINARY3D>  

    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_HI_1_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_22500_25266.ani"</BINARY3D>  
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_HI_2_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_25333_27833.ani"</BINARY3D>  
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_JUMP_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_28000_30733.ani"</BINARY3D>  
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_LEAP_ANIM">RES_VAPP_WIDGET_3D_PET_SHEEP"sheep_30833_31666.ani"</BINARY3D>  

    <!-- sheep face -->
    <IMAGE id="VAPP_WIDGET_3D_PET_SHEEP_FACE_NORMAL">RES_VAPP_WIDGET_3D_PET_TEXTURE"tex_head.ktx"</IMAGE>
    <IMAGE id="VAPP_WIDGET_3D_PET_SHEEP_FACE_EAT">RES_VAPP_WIDGET_3D_PET_TEXTURE"tex_head_eat.ktx"</IMAGE>
    <IMAGE id="VAPP_WIDGET_3D_PET_SHEEP_FACE_HI_1">RES_VAPP_WIDGET_3D_PET_TEXTURE"tex_head_hi1.ktx"</IMAGE>
    <IMAGE id="VAPP_WIDGET_3D_PET_SHEEP_FACE_HI_2">RES_VAPP_WIDGET_3D_PET_TEXTURE"tex_head_hi2.ktx"</IMAGE>
    <IMAGE id="VAPP_WIDGET_3D_PET_SHEEP_FACE_HI_3">RES_VAPP_WIDGET_3D_PET_TEXTURE"tex_head_hi3.ktx"</IMAGE>    
    <IMAGE id="VAPP_WIDGET_3D_PET_SHEEP_FACE_SNAP">RES_VAPP_WIDGET_3D_PET_TEXTURE"tex_head_snap.ktx"</IMAGE>
    
    <!-- symbol -->
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_Z">RES_VAPP_WIDGET_3D_PET_SYM_Z"text_Z.scn"</BINARY3D>    
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_E">RES_VAPP_WIDGET_3D_PET_SYM_E"text_E.scn"</BINARY3D>    
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_Q">RES_VAPP_WIDGET_3D_PET_SYM_Q"text_Q.scn"</BINARY3D>    
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_1UP">RES_VAPP_WIDGET_3D_PET_SYM_1UP"text_1up.scn"</BINARY3D>    
    
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_Z_ANIM">RES_VAPP_WIDGET_3D_PET_SYM_Z"text_Z.ani"</BINARY3D>    
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_E_ANIM">RES_VAPP_WIDGET_3D_PET_SYM_E"text_E.ani"</BINARY3D>    
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_Q_ANIM">RES_VAPP_WIDGET_3D_PET_SYM_Q"text_Q.ani"</BINARY3D>    
    <BINARY3D id="VAPP_WIDGET_3D_PET_SHEEP_SYM_TEXT_1UP_ANIM">RES_VAPP_WIDGET_3D_PET_SYM_1UP"text_1up.ani"</BINARY3D>  
    
    <!-- grass -->
    <BINARY3D id="VAPP_WIDGET_3D_PET_GRASS_SCENE">RES_VAPP_WIDGET_3D_PET_GRASS"grass.scn"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_PET_GRASS_GROW_ANIM">RES_VAPP_WIDGET_3D_PET_GRASS"grass_0_1666.ani"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_PET_GRASS_CLEAN_ANIM">RES_VAPP_WIDGET_3D_PET_GRASS"grass_2000_2666.ani"</BINARY3D>  

    <!-- railing -->
    <BINARY3D id="VAPP_WIDGET_3D_PET_RAILING">RES_VAPP_WIDGET_3D_PET_RAILING"railing.scn"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_PET_RAILING_UP_ANIM">RES_VAPP_WIDGET_3D_PET_RAILING"railing_0_666.ani"</BINARY3D>
    <BINARY3D id="VAPP_WIDGET_3D_PET_RAILING_DOWN_ANIM">RES_VAPP_WIDGET_3D_PET_RAILING"railing_833_1300.ani"</BINARY3D>  

    <!-- Event Area (Receiver) ------------------------------------------------>
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidget3dPetPublisher"/>
</APP>

#endif