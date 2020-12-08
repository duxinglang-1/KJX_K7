#include "mmi_features.h"
#include "custresdef.h"



<?xml version="1.0" encoding="UTF-8"?>
#if defined(__MMI_VUI_APP_ICON_ROBOT__) || defined(__MMI_VUI_APP_ICON_MM__) || defined(__MMI_VUI_DOWNLOADABLE_APP_ICON__)
<APP id="VAPP_THEME_APPICON" name="STR_ID_VAPP_THEME_APPICON" type="venus">
		<INCLUDE file = "GlobalResDef.h"/>
		<MEMORY heap = "VAPP_THEME_HEAP_SIZE" 
				vrt_mem_factor = "VAPP_THEME_CELL_MEM_FACTOR" 
				fg = "VAPP_THEME_TOTAL_CELL_MEM" 
				cui = "VCUI_THEME_SWITCH"
				inc = "vapp_theme_gprot.h" />
		
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define APPICON_PATH RES_IMG_ROOT"\\\\App_Icon\\\\"
    
    <STRING id="STR_ID_VAPP_THEME_APPICON">"App icon"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON1">"Icon 1"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON2">"Icon 2"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON3">"Icon 3"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON_CHANGED">"App icon changed"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON_NO">"No downloadable app icon"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON_LOADING">"Loading downloadable app icon"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON_DEFAULT">"Default application icons"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON_SYS">"System application icons"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON_DLT">"Downladable application icons"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON_SWITCH">"Switching application icons"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON_CHANGE">"Application icons changed"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON_COMPATIBLE_ASK">"Application icons might not be compatible. Continue?"</STRING>
    <STRING id="STR_ID_VAPP_THEME_APPICON_INVALID">"Invalid application icons"</STRING>
    
    <IMAGE id="IMG_ID_VAPP_APPICON_DEFAULT_PREVIEW">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\preview.jpg"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_APPICON_DEFAULT_THUMBNAIL">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\thumbnail.jpg"</IMAGE>
    
#ifdef __MMI_VUI_DOWNLOADABLE_APP_ICON__
    <MENUITEM id = "MENU_ID_VAPP_THEME_APPICON_FMGR_ACTIVATE" str = "@OID:STR_GLOBAL_ACTIVATE"/>

    <MENU id="MENU_ID_FMGR_VAPP_THEME_APPICON_TYPE_OPTIONS" type="OPTION" str="@OID:STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_VAPP_THEME_APPICON_FMGR_ACTIVATE</MENUITEM_ID>
    </MENU>


		<FILE_TYPES>
    		<FILE_TYPE type_id="FMGR_TYPE_APPICON" extension="ACO" option="MENU_ID_FMGR_VAPP_THEME_APPICON_TYPE_OPTIONS">
    		</FILE_TYPE>

    		<FILE_OPTION_HDLR option="MENU_ID_VAPP_THEME_APPICON_FMGR_ACTIVATE" enabler="vapp_theme_appicon_fmgr_use_enabler" handler="vapp_theme_appicon_fmgr_use_handler"/>
		</FILE_TYPES>
    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_ADV_ACTION" proc="vapp_theme_appicon_evt_handlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="vapp_theme_appicon_evt_handlr"/>
		<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="vapp_theme_appicon_evt_handlr"/>
		
		<RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="vapp_theme_appicon_evt_handlr"/>
		<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vapp_theme_appicon_evt_handlr"/>
#else

    <CACHEDATA type="double" id="NVRAM_THEME_APPICON_ACTIVE_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION>active appicon index</DESCRIPTION>
    </CACHEDATA>
    
#endif /* __MMI_VUI_DOWNLOADABLE_APP_ICON__ */  
</APP>
#endif /*__MMI_VUI_APP_ICON_ROBOT__ || __MMI_VUI_APP_ICON_MM__ || __MMI_VUI_DOWNLOADABLE_APP_ICON__*/