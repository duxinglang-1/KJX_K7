#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_SEGMENT_BUTTON">
#if defined(__MMI_VUI_COSMOS_CP__)
    <!-----------------------------------------------------Theme Resource Area----------------------------------------------------->
    <THEME>
		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_N"   desc="Normal state background image for leftmost button"/>              
		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_P"   desc="Pressed state background image for leftmost button"/>             
		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_H"   desc="Highlighted state background image for leftmost button"/>         
		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_D"   desc="Disabled state background image for leftmost button"/>            

		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_N"  desc="Normal state background image for rightmost button"/>             
		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_P"  desc="Pressed state background image for rightmost button"/>            
		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_H"  desc="Highlighted state background image for rightmost button"/>        
		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_D"  desc="Disabled state background image for rightmost button"/>       
		   
		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_N" desc="Normal state background image for middle button"/>            
		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_P" desc="Pressed state background image for middle button"/>           
		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_H" desc="Highlighted state background image for middle button"/>       
		<IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_D" desc="Disabled state background image for middle button"/>         
		
		<COLOR id = "VCP_COL_SEG_BTN_NRML_TEXT" desc = "Text color for normal button"/>
		<COLOR id = "VCP_COL_SEG_BTN_PRSD_TEXT" desc = "Text color for pressed button"/>
		
        <FONTSTYLE id="VCP_FONT_SEG_BTN_HLTD"/>
        <FONTSTYLE id="VCP_FONT_SEG_BTN_NRML"/>

    </THEME>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
#else

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\Components\\\\Segment\\\\"
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_N">ROOT_PATH"Segment_Left_Nor.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_P">ROOT_PATH"Segment_Left_Pre.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_H">ROOT_PATH"Segment_Left_High.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_D">ROOT_PATH"Segment_Left_Dis.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_N">ROOT_PATH"Segment_Mid_Nor.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_P">ROOT_PATH"Segment_Mid_Pre.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_H">ROOT_PATH"Segment_Mid_High.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_D">ROOT_PATH"Segment_Mid_Dis.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_N">ROOT_PATH"Segment_Right_Nor.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_P">ROOT_PATH"Segment_Right_Pre.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_H">ROOT_PATH"Segment_Right_High.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_D">ROOT_PATH"Segment_Right_Dis.9slice.png"</IMAGE>
#endif
#if 0
	#define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Segment\\\\"
	<IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_N">ROOT_PATH"Left_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_P">ROOT_PATH"Left_H.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_H">ROOT_PATH"Left_H.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_LEFT_D">ROOT_PATH"Left_N.9slice.png"</IMAGE>
    
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_N">ROOT_PATH"Right_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_P">ROOT_PATH"Right_H.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_H">ROOT_PATH"Right_H.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_RIGHT_D">ROOT_PATH"Right_N.9slice.png"</IMAGE>	 
       
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_N">ROOT_PATH"Middle_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_P">ROOT_PATH"Middle_H.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_H">ROOT_PATH"Middle_H.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_SEGMENT_BUTTON_MIDDLE_D">ROOT_PATH"Middle_N.9slice.png"</IMAGE>
#endif
</APP>

