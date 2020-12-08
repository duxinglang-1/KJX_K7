#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_SLIDER">
#if defined(__MMI_VUI_COSMOS_CP__)
    <!-----------------------------------------------------Theme Resource Area----------------------------------------------------->
	 <THEME> 
		<IMAGE id="VCP_IMG_SLIDER_THUMB_CTRL" desc="Image of the thumb control ball"/>                                            
		<IMAGE id="VCP_IMG_SLIDER_HRZT_BG"    desc="Background image of the slider track (Horizontal layout)"/>                   
		<IMAGE id="VCP_IMG_SLIDER_HRZT_H"     desc="Slider track image which signifies the completed region (Horizontal layout)"/>
		<IMAGE id="VCP_IMG_SLIDER_VERT_BG"    desc="Background image of the slider track (Vertical layout)"/>                     
		<IMAGE id="VCP_IMG_SLIDER_VERT_H"     desc="Slider track image which signifies the completed region (Horizontal layout)"/>
    </THEME>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#else
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Slider\\\\"    
    <IMAGE id="VCP_IMG_SLIDER_THUMB_CTRL">ROOT_PATH"Control.png"</IMAGE>
    <IMAGE id="VCP_IMG_SLIDER_HRZT_BG">ROOT_PATH"Horizontal_BG.9slice.png"</IMAGE>    
    <IMAGE id="VCP_IMG_SLIDER_HRZT_H">ROOT_PATH"Horizontal_H.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SLIDER_VERT_BG">ROOT_PATH"Vertical_BG.9slice.png"</IMAGE>    
    <IMAGE id="VCP_IMG_SLIDER_VERT_H">ROOT_PATH"Vertical_H.9slice.png"</IMAGE>    
#endif
</APP>

