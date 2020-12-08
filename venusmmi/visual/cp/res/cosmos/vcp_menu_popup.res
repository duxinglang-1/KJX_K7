#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_MENU_POPUP">
    <!-----------------------------------------------------Theme Resource Area----------------------------------------------------->
#if defined(__MMI_VUI_COSMOS_CP__)
    <THEME>
		<IMAGE id="VCP_IMG_MENU_POPUP_TITLE_BG" desc="Title background image"/>        
        <IMAGE id="VCP_IMG_MENU_POPUP_BG" desc="Background image of the popup menu"/>        
        <IMAGE id="VCP_IMG_MENU_POPUP_HIGHLIGHT_ITEM_BACKGROUND" desc="background image of highlighted item"/>
        <IMAGE id="VCP_IMG_MENU_POPUP_SEP_LINE" desc="Separator line image shown between two items"/> 

        <COLOR id = "VCP_COL_MENU_POPUP_TITLE_TEXT"/>
        <COLOR id = "VCP_COL_MENU_POPUP_CELL_N_TEXT"/>
        <COLOR id = "VCP_COL_MENU_POPUP_CELL_H_TEXT"/>  
        <COLOR id = "VCP_COL_MENU_POPUP_CELL_HINT_TEXT"/>  
    </THEME>
#else
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\"
    <IMAGE id="VCP_IMG_MENU_POPUP_BG">ROOT_PATH"Popup\\\\Pop_ContextMenu_BG02.9slice.png"</IMAGE>
	<IMAGE id="VCP_IMG_MENU_POPUP_TITLE_BG">ROOT_PATH"Popup\\\\Pop_ContextMenu_BG01.9slice.png"</IMAGE>
	<IMAGE id="VCP_IMG_MENU_POPUP_HIGHLIGHT_ITEM_BACKGROUND">ROOT_PATH"ListMenu\\\\List_P.9slice.png"</IMAGE>
	#define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Common\\\\"
	<IMAGE id="VCP_IMG_MENU_POPUP_SEP_LINE">ROOT_PATH"SeperatorLine.9slice.png"</IMAGE>
#endif
</APP>

