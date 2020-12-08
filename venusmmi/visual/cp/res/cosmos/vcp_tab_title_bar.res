#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_TAB_TITLE_BAR">
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
#if defined(__MMI_VUI_COSMOS_CP__)
    <THEME>
        <IMAGE id="VCP_IMG_TAB_TITLE_BAR_BG" desc="Background image of the whole tab bar"/>
        <IMAGE id="VCP_IMG_TAB_TITLE_BAR_SHADOW" desc="Shadow image shown just below the tab bar"/>
    </THEME>
    
    #define ROOT_PATH RES_IMG_ROOT"\\\\Contact\\\\TabIcon\\\\"
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CL">ROOT_PATH"CallLog.png"</IMAGE>
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CT">ROOT_PATH"Contact.png"</IMAGE>    
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_DL">ROOT_PATH"Dialpad.png"</IMAGE>    
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_SNS">ROOT_PATH"SNS.png"</IMAGE>
#else
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\TabBar\\\\Horizontal_Tab\\\\"    
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_TAB_N">ROOT_PATH"Tab_N.9slice.png"</IMAGE> 
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_TAB_P">ROOT_PATH"Tab_P.9slice.png"</IMAGE> 
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_TAB_D">ROOT_PATH"Tab_D.9slice.png"</IMAGE> 
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_TAB_H">ROOT_PATH"Tab_H.9slice.png"</IMAGE> 
    
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_H_LINE_N">ROOT_PATH"Tab_Line_H_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_H_LINE_P">ROOT_PATH"Tab_Line_H_P.9slice.png"</IMAGE>
    
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_ICON_BG">ROOT_PATH"Icon_BG_H.png"</IMAGE>
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_H_TAB_SEP">ROOT_PATH"Tab_Separator.9slice.png"</IMAGE>
    
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\TabTitleBar\\\\"
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_BG">ROOT_PATH"TitleBar_BG.9slice.png"</IMAGE>     
    
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\NaviTitleBar\\\\"
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_BACK_N">ROOT_PATH"Back_N.png"</IMAGE>
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_BACK_P">ROOT_PATH"Back_P.png"</IMAGE>
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_BACK_D">ROOT_PATH"Back_D.png"</IMAGE>    
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_BACK_H">ROOT_PATH"Back_H.png"</IMAGE>

	#define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\TabBar\\\\"
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CL">ROOT_PATH"DEMO\\\\CallLog.png"</IMAGE>
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_CT">ROOT_PATH"DEMO\\\\Contact.png"</IMAGE>    
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_DL">ROOT_PATH"DEMO\\\\Dialer.png"</IMAGE>   
    <IMAGE id="VCP_IMG_TAB_TITLE_BAR_DEMO_ICON_SNS">ROOT_PATH"DEMO\\\\SNS.png"</IMAGE>             
#endif

</APP>


