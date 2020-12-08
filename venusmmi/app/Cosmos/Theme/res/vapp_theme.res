#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifdef __MMI_THEMES_APPLICATION__ 
<APP id="VAPP_THEME" name="STR_ID_VAPP_THEME" type="venus">
		<INCLUDE file = "GlobalResDef.h"/>
		<MEMORY heap = "VAPP_THEME_HEAP_SIZE" 
				vrt_mem_factor = "VAPP_THEME_CELL_MEM_FACTOR" 
				fg = "VAPP_THEME_TOTAL_CELL_MEM" 
				cui = "VCUI_THEME_SWITCH" 
				inc = "vapp_theme_gprot.h" />
	
		
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define THEME_PATH 			 RES_IMG_ROOT"\\\\Theme\\\\"   
    <STRING id="STR_ID_VAPP_THEME">"Themes"</STRING>
    <STRING id="STR_ID_VAPP_THEME1">"Theme 1"</STRING>
    <STRING id="STR_ID_VAPP_THEME2">"Theme 2"</STRING>
    <STRING id="STR_ID_VAPP_THEME3">"Theme 3"</STRING>
    <STRING id="STR_ID_VAPP_THEME_CHNAGE_ASK">"Running applications will be stopped and back to idle. Continue?"</STRING>
    <STRING id="STR_ID_VAPP_THEME_CHANGED">"Theme Changed"</STRING>
    <IMAGE id="IMG_ID_VAPP_THEME_ACTIVE">THEME_PATH"icon_select.png"</IMAGE>

    <STRING id="STR_ID_VAPP_THEME_SYS">"System provided"</STRING>
    <STRING id="STR_ID_VAPP_THEME_DLT">"Downloaded"</STRING>
    <STRING id="STR_ID_VAPP_THEME_INVALID">"Invalid theme"</STRING>
    <STRING id="STR_ID_VAPP_THEME_NO_DLT">"No downloadable theme"</STRING>
    <STRING id="STR_ID_VAPP_THEME_LOADING_DLT">"Loading downloadable theme"</STRING>
    <STRING id="STR_ID_VAPP_THEME_COMPATIBLE_ASK">"Theme might not be compatible, Continue?"</STRING>
    <STRING id="STR_ID_VAPP_THEME_SWITCH">"Theme Switch"</STRING>
    
    <IMAGE id="IMG_ID_VAPP_THEME_ACTIVE">THEME_PATH"icon_select.png"</IMAGE>
    
    <CACHEDATA type="byte" id="NVRAM_THEME_ACTIVE_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION>active theme index</DESCRIPTION>
    </CACHEDATA>
    
    <EVENT id="EVT_ID_VAPP_THEME_CHANGED" type="SENDER"/>

		<IMAGE id="IMG_ID_VAPP_THEME_SELECT_ICON">RES_IMG_ROOT"\\\\Common\\\\\ScreenShot\\\\icon_select.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_THEME_LARGE_BG">RES_IMG_ROOT"\\\\Common\\\\\ScreenShot\\\\Large_BG.9slice.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_THEME_SMALL_BG">RES_IMG_ROOT"\\\\Common\\\\\ScreenShot\\\\Small_BG.9slice.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_THEME_DEFAULT">THEME_PATH"Dlt_default_thumbnail.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_THEME_INVALID">THEME_PATH"File_corrupted.png"</IMAGE>
		
    <STRING id="STR_ID_VAPP_THEME_DLT_ERROR_PROJECT">"Project not match"</STRING>
    <STRING id="STR_ID_VAPP_THEME_DLT_ERROR_VERSION">"Version not match"</STRING>
    <STRING id="STR_ID_VAPP_THEME_DLT_ERROR_RESOLUTION">"Resolution not match"</STRING>

    <IMAGE id="IMG_ID_VAPP_THEME_DLT_DEFAULT_THUMBNAIL" >THEME_PATH"Dlt_default_thumbnail.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_THEME_DLT_DEFAULT_PREVIEW" >THEME_PATH"Dlt_default_preview.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_THEME_DLT_ICON_FILE_TYPE">RES_IMG_ROOT"\\\\FMGR\\\\ListIcon\\\\UnknownFile.png"</IMAGE>

#ifdef __MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__
    <!-- Supported file type option handler -->   

	
    <MENUITEM id = "MENU_ID_VAPP_THEME_FMGR_ACTIVATE" str = "@OID:STR_GLOBAL_ACTIVATE"/>

    <MENU id="MENU_ID_FMGR_VAPP_THEME_TYPE_OPTIONS" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_VAPP_THEME_FMGR_ACTIVATE</MENUITEM_ID>
    </MENU>


		<FILE_TYPES>
    		<FILE_TYPE type_id="FMGR_TYPE_THEME" extension="MED" option="MENU_ID_FMGR_VAPP_THEME_TYPE_OPTIONS">
    		</FILE_TYPE>

    		<FILE_OPTION_HDLR option="MENU_ID_VAPP_THEME_FMGR_ACTIVATE" enabler="vapp_theme_fmgr_use_enabler" handler="vapp_theme_fmgr_use_handler"/>
		</FILE_TYPES>
    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="vapp_theme_evt_handlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="vapp_theme_evt_handlr"/>
		<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="vapp_theme_evt_handlr"/>
		
		<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="vapp_theme_evt_handlr"/>
		<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vapp_theme_evt_handlr"/>
		
#endif /* __MMI_COSMOS_DOWNLOADABLE_THEMES_SUPPORT__ */   
</APP>
#endif /*__MMI_THEMES_APPLICATION__*/

#if defined(__MMI_VUI_SETTING_LAUNCHER_SELECTION__) || defined(__MMI_THEMES_APPLICATION__) || defined(__MMI_VUI_APP_ICON_ROBOT__) || defined(__MMI_VUI_APP_ICON_MM__) || defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__)   
<APP id="VCUI_THEME_SWITCH" name="STR_ID_VAPP_THEME_CHANGING" type="venus">
    <MEMORY heap="20*1024" />
    
    <STRING id="STR_ID_VAPP_THEME_CHANGING">"Themes"</STRING>
</APP>
#endif  /*__MMI_VUI_SETTING_LAUNCHER_SELECTION__ || __MMI_THEMES_APPLICATION__*/