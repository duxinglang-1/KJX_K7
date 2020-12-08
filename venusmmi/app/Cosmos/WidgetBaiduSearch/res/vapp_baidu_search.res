#include "mmi_features.h"

#ifdef __MMI_BAIDU_SEARCH_COSMOS__

#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_BAIDU_SEARCH" 
    package_name = "native.mtk.baidu"
    name="STR_ID_VAPP_BAIDU_SEARCH"
    img = "IMG_ID_VAPP_BAIDU_SEARCH"
    launch = "vapp_baidu_search_launch"
    type="venus">
    
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
    
    <MEMORY base="1024*150"/>
    
    <LAYOUT file="vapp_baidu_search.xml" />    
    
    <!-- Image IDs define -->
    <IMAGE id="IMG_ID_VAPP_BAIDU_SEARCH">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\BaiduSearch.png"</IMAGE>           
    <IMAGE id="IMG_ID_VAPP_BAIDU_ICON">RES_IMG_ROOT"\\\\Widget\\\\Search\\\\baidu.png"</IMAGE>       
    <IMAGE id="IMG_ID_VAPP_BAIDU_SEARCH_LIST_SEARCH_ICON">RES_THEME_ROOT"\\\\Default\\\\Widget\\\\Search\\\\List_Search.png"</IMAGE>    
    <IMAGE id="IMG_ID_VAPP_BAIDU_SEARCH_BUTTON_N">RES_IMG_ROOT"\\\\Widget\\\\Search\\\\search_n.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_BAIDU_SEARCH_BUTTON_P">RES_IMG_ROOT"\\\\Widget\\\\Search\\\\search_P.png"</IMAGE>  		
		<IMAGE id="IMG_ID_VAPP_BAIDU_SEARCH_TITLE_BG">RES_IMG_ROOT"\\\\Widget\\\\Search\\\\title_bg.png"</IMAGE>   
#ifdef __MMI_VUI_WIDGET_BAIDU_SEARCH__
    <IMAGE id="IMG_ID_VAPP_BAIDU_SEARCH_WIDGET_SEARCH_BAR_BG">RES_IMG_ROOT"\\\\Widget\\\\Search\\\\SearchBar_BG.png"</IMAGE>	
#endif

    <!-- String IDs define  -->
    <STRING id = "STR_ID_VAPP_BAIDU_SEARCH"/>    
    <STRING id = "STR_ID_VAPP_BAIDU_SEARCH_SEARCH"/>    
#ifdef __MMI_VUI_WIDGET_BAIDU_SEARCH__
    <STRING id = "STR_ID_VAPP_WIDGET_BAIDU_NAME"/>    
    <STRING id = "STR_ID_BAIDU_HINT"/>    
#endif

#ifdef OPERA_BROWSER
    <APPCONCURRENT concurrent_w_order="VAPP_BAIDU_SEARCH, APP_OPERA"/>
#endif

#ifdef __MMI_VUI_WIDGET_BAIDU_SEARCH__
    <RECEIVER id="EVT_ID_VAPP_WIDGET_SYS_INIT" proc="VappWidgetBaiduSearchPublisher"/>
#endif

</APP>
#endif
