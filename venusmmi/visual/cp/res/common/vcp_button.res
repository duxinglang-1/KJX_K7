#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_BUTTON">

    <!-----------------------------------------------------Theme Resource Area----------------------------------------------------->
    <THEME>
        <IMAGE id="VCP_IMG_BUTTON_DEFAULT_01_N" desc="Normal state background image in DEFAULT_01 style"/>                
        <IMAGE id="VCP_IMG_BUTTON_DEFAULT_01_P" desc="Pressed state background image in DEFAULT_01 style"/>               
        <IMAGE id="VCP_IMG_BUTTON_DEFAULT_01_D" desc="Disabled state background image in DEFAULT_01 style"/>              
        <IMAGE id="VCP_IMG_BUTTON_DEFAULT_02_N" desc="Normal state background image in DEFAULT_02 style"/>                
        <IMAGE id="VCP_IMG_BUTTON_DEFAULT_02_P" desc="Pressed state background image in DEFAULT_02 style"/>               
        <IMAGE id="VCP_IMG_BUTTON_DEFAULT_02_D" desc="Disabled state background image in DEFAULT_02 style"/>              
        <IMAGE id="VCP_IMG_BUTTON_SIM1_N"       desc="Normal state background image in SIM1 style"/>                      
        <IMAGE id="VCP_IMG_BUTTON_SIM1_P"       desc="Pressed state background image in SIM1 style"/>                     
        <IMAGE id="VCP_IMG_BUTTON_SIM1_D"       desc="Disabled state background image in SIM1 style"/>                    
        <IMAGE id="VCP_IMG_BUTTON_SIM2_N"       desc="Normal state background image in SIM2 style"/>                      
        <IMAGE id="VCP_IMG_BUTTON_SIM2_P"       desc="Pressed state background image in SIM2 style"/>                     
        <IMAGE id="VCP_IMG_BUTTON_SIM2_D"       desc="Disabled state background image in SIM2 style"/>                    
        <IMAGE id="VCP_IMG_BUTTON_CHILD_BKG_N"  desc="Child button icon in normal state (for VcpComboButton)"/>           
        <IMAGE id="VCP_IMG_BUTTON_CHILD_BKG_P"  desc="Child button icon in pressed state (for VcpComboButton)"/>          
        <IMAGE id="VCP_IMG_BUTTON_CHILD_BKG_D"  desc="Child button icon in disabled state (for VcpComboButton)"/>          
        
        <IMAGE id="VCP_IMG_BUTTON_RED_N"        desc="Normal state background image in RED style"/>                       
        <IMAGE id="VCP_IMG_BUTTON_RED_P"        desc="Pressed state background image in RED style"/>                      
        <IMAGE id="VCP_IMG_BUTTON_RED_D"        desc="Disabled state background image in RED style"/>                     
        <IMAGE id="VCP_IMG_BUTTON_GREY_N"       desc="Normal state background image in GREY style"/>                      
        <IMAGE id="VCP_IMG_BUTTON_GREY_P"       desc="Pressed state background image in GREY style"/>                     
        <IMAGE id="VCP_IMG_BUTTON_GREY_D" 	desc="Disabled state background image in GREY style"/>                    	
        
        <IMAGE id="VCP_IMG_BUTTON_ARROW_WHITE"  desc="White Arrow icon shown on VcpArrowButton"/>                         
        <IMAGE id="VCP_IMG_BUTTON_PLUS"         desc="Plus sign icon shown on VcpAddButton"/>                             
        <IMAGE id="VCP_IMG_BUTTON_DELETE"       desc="Cross sign icon shown on VcpCancelButton"/>                          
        <IMAGE id="VCP_IMG_BUTTON_GLOW_EFFECT"  desc="Glowing halo effect shown when VcpImageButton is in pressed state"/>       

        <COLOR id = "VCP_COL_BTN_TXT_DEFAULT_BRDR"/>
        <COLOR id = "VCP_COL_BTN_TXT_DEFAULT_NRML"/>
        <COLOR id = "VCP_COL_BTN_TXT_DEFAULT_PRSD"/>  
        <COLOR id = "VCP_COL_BTN_TXT_DEFAULT_DSBD"/>  
        <COLOR id = "VCP_COL_BTN_TXT_DEFAULT_HLTD"/>  
        <COLOR id = "VCP_COL_BTN_TXT_STYLE_DEFAULT_01"/>
        <COLOR id = "VCP_COL_BTN_TXT_STYLE_DEFAULT_02"/>
        <COLOR id = "VCP_COL_BTN_TXT_STYLE_RED"/>
        <COLOR id = "VCP_COL_BTN_TXT_STYLE_GREY"/>
        <COLOR id = "VCP_COL_BTN_TXT_STYLE_SIM1"/>
        <COLOR id = "VCP_COL_BTN_TXT_STYLE_SIM2"/>
        <COLOR id = "VCP_COL_BTN_TXT_STYLE_NORMAL"/>        
        
        <FONTSTYLE id="VCP_FONT_BTN_STYLE_DEFAULT_01"/>
        <FONTSTYLE id="VCP_FONT_BTN_STYLE_DEFAULT_02"/>
        <FONTSTYLE id="VCP_FONT_BTN_STYLE_RED"/>
        <FONTSTYLE id="VCP_FONT_BTN_STYLE_GREY"/>
        <FONTSTYLE id="VCP_FONT_BTN_STYLE_SIM1"/>
        <FONTSTYLE id="VCP_FONT_BTN_STYLE_SIM2"/>
        <FONTSTYLE id="VCP_FONT_BTN_STYLE_NORMAL"/>
      
    </THEME>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\Components\\\\Button\\\\"
    <IMAGE id="VCP_IMG_BUTTON_N">ROOT_PATH"Button_Nor.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_BUTTON_P">ROOT_PATH"Button_Pre.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_BUTTON_H">ROOT_PATH"Button_High.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_BUTTON_D">ROOT_PATH"Button_Dis.9slice.png"</IMAGE>

#if !defined(__MMI_VUI_COSMOS_CP__)
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Common\\\\"
    <IMAGE id="VCP_IMG_BUTTON_ARROW_WHITE">ROOT_PATH"Button_Arrow_Right.png"</IMAGE>
    <IMAGE id="VCP_IMG_BUTTON_ARROW_GRAY">ROOT_PATH"Button_Arrow_Right.png"</IMAGE>
    <IMAGE id="VCP_IMG_BUTTON_PLUS">ROOT_PATH"Plus.png"</IMAGE>
    <IMAGE id="VCP_IMG_BUTTON_DELETE">ROOT_PATH"Delete.png"</IMAGE>
    <IMAGE id="VCP_IMG_BUTTON_GLOW_EFFECT">ROOT_PATH"halo.png"</IMAGE>

    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Button\\\\"
    <IMAGE id="VCP_IMG_BUTTON_RED_N">ROOT_PATH"Button_Warning_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_BUTTON_RED_P">ROOT_PATH"Button_Warning_P.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_BUTTON_RED_D">ROOT_PATH"Button_Warning_D.9slice.png"</IMAGE>

    <IMAGE id="VCP_IMG_BUTTON_GREY_N">ROOT_PATH"Button_Cancel_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_BUTTON_GREY_P">ROOT_PATH"Button_Cancel_P.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_BUTTON_GREY_D">ROOT_PATH"Button_Cancel_D.9slice.png"</IMAGE>
#endif

    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\3D\\\\Components\\\\ImageBtn\\\\"
#ifdef __COSMOS_3D_V10__
    <IMAGE id="VCP_IMG_GLOW_EFFECT_1">ROOT_PATH"halo_1.png"</IMAGE>
    <IMAGE id="VCP_IMG_GLOW_EFFECT_2">ROOT_PATH"halo_2.png"</IMAGE>
    <BINARY3D id="VCP_BINARY_GLOW_EFFECT_FS" base_path="current">"shader\\\\vcp_glow_effect_3d.fs"</BINARY3D>
    <BINARY3D id="VCP_BINARY_GLOW_EFFECT_FS_2" base_path="current">"shader\\\\vcp_glow_effect_3d_2.fs"</BINARY3D>
    <BINARY3D id="VCP_BINARY_GLOW_EFFECT_VS" base_path="current">"shader\\\\vcp_glow_effect_3d.vs"</BINARY3D>

#endif // __COSMOS_3D_V10__


</APP>

