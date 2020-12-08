#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_TAB_BAR">
    <!-----------------------------------------------------Theme Resource Area----------------------------------------------------->
#if defined(__MMI_VUI_COSMOS_CP__)
    <THEME>
		<IMAGE id="VCP_IMG_TAB_BAR_ICON_BG"            desc="Black round icon image shown behind the icons of highlighted tabs"/>           

		<IMAGE id="VCP_IMG_TAB_BAR_TAB_HZ_N"           desc="Background image for non-highlighted tab in normal state"/>               
		
		<IMAGE id="VCP_IMG_TAB_BAR_LEFT_TAB_HZ_N_P"    desc="Background image for leftmost non-highlighted tab in pressed state"/>      
		<IMAGE id="VCP_IMG_TAB_BAR_MIDDLE_TAB_HZ_N_P"  desc="Background image for middle non-highlighted tab in pressed state"/>            
		<IMAGE id="VCP_IMG_TAB_BAR_RIGHT_TAB_HZ_N_P"   desc="Background image for rightmost non-highlighted tab in pressed state"/>         
		<IMAGE id="VCP_IMG_TAB_BAR_TAB_HZ_H"           desc="Background image for highlighted tab in normal state"/>                    
		<IMAGE id="VCP_IMG_TAB_BAR_TAB_HZ_H_P"         desc="Background image for highlighted tab in pressed state"/>                       

		<IMAGE id="VCP_IMG_TAB_BAR_TAB_HZ_D"           desc="Background image for tab in disabled state"/>

		<IMAGE id="VCP_IMG_TAB_BAR_HZ_LINE_N"          desc="Normal state Tab-bar line, shown below the tabs"/>          
		<IMAGE id="VCP_IMG_TAB_BAR_HZ_LINE_P"          desc="Pressed state Tab-bar line, shown below the tabs"/>     

		<IMAGE id="VCP_IMG_TAB_BAR_HZ_TAB_SEP"         desc="Small separator images shown between two tabs"/>      

#if defined(MULTI_LAYOUT_SUPPORT)
		<IMAGE id="VCP_IMG_TAB_BAR_TAB_VT_H"/>
		<IMAGE id="VCP_IMG_TAB_BAR_TAB_VT_H_P"/>
		<IMAGE id="VCP_IMG_TAB_BAR_TAB_VT_N"/>
		<IMAGE id="VCP_IMG_TAB_BAR_TAB_VT_N_P"/>

		<IMAGE id="VCP_IMG_TAB_BAR_VT_LINE_N"/>
		<IMAGE id="VCP_IMG_TAB_BAR_VT_LINE_P"/>
#endif		
        <COLOR id = "VCP_COL_TAB_BAR_TEXT" desc = "Text color for tabs"/>		
    </THEME>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="VCP_IMG_TAB_BAR_NOTIFICATION_ICON">RES_IMG_ROOT"\\\\Common\\\\vcp_tab_notify.9slice.png"</IMAGE>
#else
//#elif defined(__MMI_VUI_SHELL_CP__)
    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\Components\\\\Tab\\\\"
    <IMAGE id="VCP_IMG_TABBAR_TOP_P">ROOT_PATH"Top_Tab_Bar_Pre.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TABBAR_TOP_H">ROOT_PATH"Top_Tab_Bar_High.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TABBAR_BOTTOM_P">ROOT_PATH"Bottom_Tab_Bar_Pre.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TABBAR_BOTTOM_H">ROOT_PATH"Bottom_Tab_Bar_High.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TABBAR_BUTTON_TOP_P">ROOT_PATH"Top_Tab_Button_Pre.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TABBAR_BUTTON_TOP_H">ROOT_PATH"Top_Tab_Button_High.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TABBAR_BUTTON_BOTTOM_P">ROOT_PATH"Bottom_Tab_Button_Pre.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TABBAR_BUTTON_BOTTOM_H">ROOT_PATH"Bottom_Tab_Button_High.9slice.png"</IMAGE>

    <IMAGE id="VCP_IMG_TAB_BAR_TAB_HZ_N">ROOT_PATH"Top_Tab_Bar_High.9slice.png"</IMAGE> 
    <IMAGE id="VCP_IMG_TAB_BAR_TAB_HZ_N_P">ROOT_PATH"Top_Tab_Button_Pre.9slice.png"</IMAGE> 
    <IMAGE id="VCP_IMG_TAB_BAR_TAB_HZ_H">ROOT_PATH"Top_Tab_Button_High.9slice.png"</IMAGE> 
    <IMAGE id="VCP_IMG_TAB_BAR_TAB_HZ_H_P">ROOT_PATH"Top_Tab_Button_Pre.9slice.png"</IMAGE> 

    <IMAGE id="VCP_IMG_TAB_BAR_LEFT_TAB_HZ_N_P">ROOT_PATH"Top_Tab_Button_Pre.9slice.png"</IMAGE> 
    <IMAGE id="VCP_IMG_TAB_BAR_MIDDLE_TAB_HZ_N_P">ROOT_PATH"Top_Tab_Button_Pre.9slice.png"</IMAGE> 
    <IMAGE id="VCP_IMG_TAB_BAR_RIGHT_TAB_HZ_N_P">ROOT_PATH"Top_Tab_Button_Pre.9slice.png"</IMAGE> 

    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\TabBar\\\\"    
    <IMAGE id="VCP_IMG_TAB_BAR_ICON_BG">ROOT_PATH"Icon_BG_H.png"</IMAGE>
    <IMAGE id="VCP_IMG_TAB_BAR_BG">ROOT_PATH"Tabbar_BG.png"</IMAGE>    
    
    
    <IMAGE id="VCP_IMG_TAB_BAR_TAB_HZ_D">ROOT_PATH"Tab_D.9slice.png"</IMAGE> 
    
    <IMAGE id="VCP_IMG_TAB_BAR_HZ_LINE_N">ROOT_PATH"Tab_Line_H_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TAB_BAR_HZ_LINE_P">ROOT_PATH"Tab_Line_H_P.9slice.png"</IMAGE>
    
    <IMAGE id="VCP_IMG_TAB_BAR_HZ_TAB_SEP">ROOT_PATH"Tab_Separator.9slice.png"</IMAGE>
    
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\TabBar\\\\Vertical_Tab\\\\"    
    <IMAGE id="VCP_IMG_TAB_BAR_TAB_VT_H">ROOT_PATH"Tab_H.9slice.png"</IMAGE> 
    <IMAGE id="VCP_IMG_TAB_BAR_TAB_VT_H_P">ROOT_PATH"Tab_H_P.9slice.png"</IMAGE> 
    <IMAGE id="VCP_IMG_TAB_BAR_TAB_VT_N">ROOT_PATH"Tab_N.9slice.png"</IMAGE> 
    <IMAGE id="VCP_IMG_TAB_BAR_TAB_VT_N_P">ROOT_PATH"Tab_N_P.9slice.png"</IMAGE> 
    
    <IMAGE id="VCP_IMG_TAB_BAR_VT_LINE_N">ROOT_PATH"Tab_Line_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TAB_BAR_VT_LINE_P">ROOT_PATH"Tab_Line_P.9slice.png"</IMAGE>    

#endif

</APP>

