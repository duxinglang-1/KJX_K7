#include "mmi_features.h"

#ifdef __MMI_GOOGLE_SEARCH_COSMOS__

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

/*****************************************************************************
 * This is for google app & google widget, don't modify
 *****************************************************************************/

<APP id="VAPP_GOOGLE_SEARCH"
	package_name = "native.mtk.google"
	name = "STR_ID_VAPP_GOOGLE_SEARCH"
	img = "IMG_ID_VAPP_GOOGLE_SEARCH"
	launch = "vapp_google_search_launch"
	package_proc = "vapp_google_search_package_proc"
	type = "venus">

    <MEMORY heap="150*1024" />

#ifdef OPERA_BROWSER
    <APPCONCURRENT concurrent_w_order ="VAPP_GOOGLE_SEARCH, APP_OPERA"/>
#endif
    
		<!-- Image IDs define -->
    <IMAGE id="IMG_ID_VAPP_GOOGLE_SEARCH">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\GoogleSearch.png"</IMAGE>    
	  <IMAGE id="IMG_ID_VAPP_GOOGLE_SEARCH_LIST_SEARCH_ICON">RES_THEME_ROOT"\\\\Default\\\\Widget\\\\Search\\\\List_Search.png"</IMAGE>    
    <IMAGE id="IMG_ID_VAPP_GOOGLE_SEARCH_BUTTON_N">RES_IMG_ROOT"\\\\Widget\\\\Search\\\\search_n.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_GOOGLE_SEARCH_BUTTON_P">RES_IMG_ROOT"\\\\Widget\\\\Search\\\\search_P.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_GOOGLE_SEARCH_TITLE_BG">RES_IMG_ROOT"\\\\Widget\\\\Search\\\\title_bg.png"</IMAGE>        
#ifdef  __MMI_VUI_WIDGET_GOOGLE__
		<IMAGE id="IMG_ID_VAPP_GOOGLE_SEARCH_WIDGET_BG">RES_IMG_ROOT"\\\\Widget\\\\Search\\\\SearchBar_BG.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_GOOGLE_SEARCH_WIDGET_BG_2">RES_IMG_ROOT"\\\\Widget\\\\Search\\\\SearchBar_BG_2.png"</IMAGE>
		<IMAGE id="IMG_ID_VAPP_GOOGLE_PLUS_BG">RES_IMG_ROOT"\\\\Widget\\\\Search\\\\PLUS_BG.png"</IMAGE>
#endif

    <!-- String IDs define  -->
		<STRING id="STR_ID_VAPP_GOOGLE_SEARCH"/>    
		<STRING id="STR_ID_VAPP_GOOGLE_SEARCH_SEARCH"/>
#ifdef  __MMI_VUI_WIDGET_GOOGLE__
    <STRING id = "STR_ID_VAPP_WIDGET_GOOGLE_NAME"/>
    <STRING id = "STR_ID_GOOGLE_HINT"/>
#endif

#ifdef  __MMI_VUI_WIDGET_GOOGLE__
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetGoogleSearchPublisher"/>
#endif

</APP>
#endif
