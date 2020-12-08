#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_SWITCH">
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

#ifdef __COSMOS_MMI__
    <THEME>
        <IMAGE id="VCP_IMG_SWITCH_BG_ON"          desc="Background image in ON state"/>                        
        <IMAGE id="VCP_IMG_SWITCH_BG_OFF"         desc="Background image in OFF state"/>                       
        <IMAGE id="VCP_IMG_SWITCH_SLIDE_BALL_ON"  desc="Slider ball image in ON state"/>                           
        <IMAGE id="VCP_IMG_SWITCH_SLIDE_BALL_OFF" desc="Slider ball image in OFF state"/>                          
        <IMAGE id="VCP_IMG_SWITCH_ICON_ON"        desc="Small icon shown along with ball, in ON state"/>       
        <IMAGE id="VCP_IMG_SWITCH_ICON_OFF"       desc="Small icon shown along with ball, in OFF state"/>      
    </THEME>

#else
    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\Components\\\\Switch\\\\"
    <IMAGE id="VCP_IMG_SWITCH_BG_ON">ROOT_PATH"OnOff_BG_Nor.png"</IMAGE>
    <IMAGE id="VCP_IMG_SWITCH_BG_OFF">ROOT_PATH"OnOff_BG_Dis.png"</IMAGE>    
    <IMAGE id="VCP_IMG_SWITCH_SLIDE_BALL_ON">ROOT_PATH"OnOff_ROU_Nor.png"</IMAGE>    
    <IMAGE id="VCP_IMG_SWITCH_SLIDE_BALL_OFF">ROOT_PATH"OnOff_ROU_Dis.png"</IMAGE>    
    <IMAGE id="VCP_IMG_SWITCH_ICON_ON">ROOT_PATH"On.png"</IMAGE>    
    <IMAGE id="VCP_IMG_SWITCH_ICON_OFF">ROOT_PATH"Off.png"</IMAGE>

#endif
</APP>

