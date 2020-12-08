#include "mmi_features.h"
#include "custresdef.h"
#define __MIRAGE_MMI__

<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_FORM">
#if defined(__MMI_VUI_COSMOS_CP__)
    <!-----------------------------------------------------Theme Resource Area----------------------------------------------------->
    <THEME>
        <IMAGE id="VCP_IMG_NEXT_ITEM_ICON_N"         desc="Small Arrow icon shown on the right end of VcpFormItemLauncherCell (Normal state)"/> 
        <IMAGE id="VCP_IMG_NEXT_ITEM_ICON_P"         desc="Small Arrow icon shown on the right end of VcpFormItemLauncherCell (Pressed state)"/>
        <IMAGE id="VCP_IMG_TOP_SHADOW"               desc="Top shadow image"/>                                     
        <IMAGE id="VCP_IMG_FORM_SEP_LINE"            desc="Separator line shown between two form items"/>                                     
        <IMAGE id="VCP_IMG_FORM_CAPTION_BG"          desc="Background image for VcpFormItemCaption item"/>                                    
        <IMAGE id="VCP_IMG_FORM_HIGHLIGHTED_CELL_BG" desc="Background image for a highlighted item which is derived from VcpFormItemCell"/>
        
        <COLOR id = "VCP_COL_FORM_BG" />
        <COLOR id = "VCP_COL_FORM_HIDDEN_BG" />
        <COLOR id = "VCP_COL_FORM_ITEM_BG" />
        <COLOR id = "VCP_COL_FORM_ITEM_CAPTION_BG" />
        <COLOR id = "VCP_COL_FORM_HIGHLIGHTED_FONT" />
        <COLOR id = "VCP_COL_FORM_MAIN_FONT" />
        <COLOR id = "VCP_COL_FORM_MAIN_FONT_DISABLED" />
        <COLOR id = "VCP_COL_FORM_HINT_TEXT" />
        <COLOR id = "VCP_COL_FORM_HINT_TEXT_DISABLED" />
        <COLOR id = "VCP_COL_FORM_DISABLED_OVERLAY" />
        <COLOR id = "VCP_COL_FORM_WARNING_TEXT" />
        <COLOR id = "VCP_COL_FORM_CAPTION_TEXT" />        
    </THEME>
#else    
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>       
    	#define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Common\\\\"
    	<IMAGE id="VCP_IMG_NEXT_ITEM_ICON_N">ROOT_PATH"Arrow_Gray.png"</IMAGE>
    	<IMAGE id="VCP_IMG_NEXT_ITEM_ICON_P">ROOT_PATH"Arrow_Gray.png"</IMAGE>
    	<IMAGE id="VCP_IMG_TOP_SHADOW">ROOT_PATH"List_Shadow_D.png"</IMAGE>
    	<IMAGE id="VCP_IMG_PLUS_ICON">ROOT_PATH"Plus.png"</IMAGE>
	<IMAGE id="VCP_IMG_DELETE_ICON">ROOT_PATH"Delete.png"</IMAGE>       
	<IMAGE id="VCP_IMG_FORM_SEP_LINE">ROOT_PATH"SeperatorLine.9slice.png"</IMAGE>  

	#define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\ListMenu\\\\"
	<IMAGE id="VCP_IMG_FORM_CAPTION_BG">ROOT_PATH"GroupSep.9slice.png"</IMAGE>       
	<IMAGE id="VCP_IMG_FORM_HIGHLIGHTED_CELL_BG">ROOT_PATH"List_P.9slice.png"</IMAGE>       
#endif
</APP>