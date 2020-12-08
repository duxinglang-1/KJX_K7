#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_NCENTER" type="venus">

	<!----------------- Event Id ----------------------------------------->
	<SENDER id="EVT_ID_VAPP_NCENTER_DRAG" hfile="vapp_ncenter_gprot.h"/>
	<SENDER id="EVT_ID_VAPP_NCENTER_ENTER" hfile="vapp_ncenter_gprot.h"/>
	<SENDER id="EVT_ID_VAPP_NCENTER_ENTERED" hfile="vapp_ncenter_gprot.h"/>
	<SENDER id="EVT_ID_VAPP_NCENTER_EXIT" hfile="vapp_ncenter_gprot.h"/>
	<SENDER id="EVT_ID_VAPP_NCENTER_EXITED" hfile="vapp_ncenter_gprot.h"/>	

  <RECEIVER id="EVT_ID_SETTING_LANGUAGE_CHANGED" proc="vapp_ncenter_pure_key_bootup_handler"/>

  <!-- Common Resource Area -------------------------------------------------->
   <CACHEDATA type="short" id="NVRAM_NCENTER_PURE_KEY_IS_ENTERED" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00,0x00] </DEFAULT_VALUE>
        <DESCRIPTION>entry flag</DESCRIPTION>
   </CACHEDATA>
    
	
	<!----------------- Screen Id ----------------------------------------->
  <SCREEN id = "SCR_ID_NCENTER"/>
 
	<!-----------------------------------------------------String Resource Area----------------------------------------------------->
  <STRING id="STR_ID_VAPP_NCENTER_NOTIFICATION"/>
  <STRING id="STR_ID_VAPP_NCENTER_ONGOING"/>
  <STRING id="STR_ID_VAPP_NCENTER_NO_NOTIFICATION"/>
  <STRING id="STR_ID_VAPP_NCENTER_CLEAR_NOTIFICATION"/>
  <STRING id="STR_ID_VAPP_NCENTER_OOM"/>
  <STRING id="STR_ID_VAPP_NCENTER_SYS_CELL_NO_SERVICE"/>
  <STRING id="STR_ID_VAPP_NCENTER_USAGE_HINT"/>
  <STRING id="STR_ID_VAPP_NCENTER_CLEAR_ALL"/>
  <STRING id="STR_ID_VAPP_NCENTER_CHANGE"/>
  <STRING id="STR_ID_VAPP_NCENTER_CLEAR_ASK"/>
  <STRING id="STR_ID_VAPP_NCENTER_CLEAR_ALL_ASK"/>
  <STRING id="STR_ID_QSETTING_WLAN_IN_FLIGHT_MODE_ASK"/>
  <STRING id="STR_ID_QSETTING_WLAN_TURN_OFF_HOT_SPOT"/>
  <STRING id="STR_ID_QSETTING_BT_IN_FLIGHT_MODE_ASK"/>
  <STRING id="STR_ID_QSETTING_BT_TURN_OFF_WITH_CONNECTION_CONFIRM"/>
  <STRING id="STR_ID_QSETTING_BUTTON_ON"/>
  <STRING id="STR_ID_QSETTING_BUTTON_OFF"/>
  <STRING id="STR_ID_QSETTING_BUTTON_OK"/>
  <STRING id="STR_ID_QSETTING_BUTTON_CANCEL"/>
  <STRING id="STR_ID_QSETTING_NOT_AVAILABLE"/>
  <STRING id="STR_ID_QSETTING_BALLOON_IN_CALL"/>

  <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

#if defined(__VENUS_MMI__) && defined(__COSMOS_MMI__)
	#define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\NCenter\\\\"
#else
	#define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\NCenter\\\\"
#endif

  <IMAGE id="VAPP_IMG_NCENTER_OPERATOR_BACKGROUND">ROOT_PATH"bg_top.9slice.png"</IMAGE>
  <IMAGE id="VAPP_IMG_NCENTER_DRAG_BAR">ROOT_PATH"drag_bar.png"</IMAGE>
  <IMAGE id="VAPP_IMG_NCENTER_DRAG_BAR_BG">ROOT_PATH"bg_drag_bar.9slice.png"</IMAGE>
  <IMAGE id="VAPP_IMG_NCENTER_DEFAULT_EVENT_ICON">ROOT_PATH"icon_info.png"</IMAGE>
  <IMAGE id="VAPP_IMG_NCENTER_TAB_ICON_NOTIFICATION">ROOT_PATH"notification.png"</IMAGE>
  <IMAGE id="VAPP_IMG_NCENTER_TAB_ICON_ONGOING">ROOT_PATH"ongoing.png"</IMAGE>  
  <IMAGE id="VAPP_IMG_NCENTER_FOLD_ICON">ROOT_PATH"icon_fold.png"</IMAGE>
  <IMAGE id="VAPP_IMG_NCENTER_LIST_GROUP_HEADER_BG">ROOT_PATH"GroupSep.9slice.png"</IMAGE>   
  <IMAGE id="VAPP_IMG_NCENTER_LIST_HIGHLIGHT_BACKGROUND">CUST_IMG_PATH"\\\\\MainLCD\\\\VUI\\\\Shell\\\\Components\\\\Listmenu\\\\List\\\\List_Pre.9slice.png"</IMAGE>;   
  <IMAGE id="VAPP_IMG_NCENTER_OPTIONS_MENU_BG">ROOT_PATH"Options_menu_bg.9slice.png"</IMAGE>; 

#if defined(__VENUS_MMI__) && defined(__COSMOS_MMI__)
	#define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Common\\\\Button\\\\"  
#endif
  <IMAGE id="VAPP_IMG_NCENTER_CLOSE_ICON">ROOT_PATH"Delete.png"</IMAGE>


  
#if defined(__VENUS_MMI__) && defined(__COSMOS_MMI__)  
  #define IMG_ROOT_PATH RES_IMG_ROOT"\\\\Widget\\\\QuickSwitch\\\\"
#else 
 #if defined(__MMI_FTE_SUPPORT__)
    #define IMG_ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\Widget\\\\QuickSwitch\\\\"
 #else
    #define IMG_ROOT_PATH
 #endif
#endif
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_BG_N">IMG_ROOT_PATH"BG_N.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_LINE">IMG_ROOT_PATH"SeperatorLine.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_WIFI_H">IMG_ROOT_PATH"WIFI_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_WIFI_N">IMG_ROOT_PATH"WIFI_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_BT_H">IMG_ROOT_PATH"BT_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_BT_N">IMG_ROOT_PATH"BT_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_SILENT_H">IMG_ROOT_PATH"Silent_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_SILENT_N">IMG_ROOT_PATH"Silent_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_FLIGHT_H">IMG_ROOT_PATH"Flight_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_FLIGHT_N">IMG_ROOT_PATH"Flight_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_BRIGHTNESS_H">IMG_ROOT_PATH"Brightness_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_BRIGHTNESS_N">IMG_ROOT_PATH"Brightness_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_INDICATOR_H">IMG_ROOT_PATH"Indicator_H.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_QUICK_SETTING_INDICATOR_N">IMG_ROOT_PATH"Indicator_N.png"</IMAGE>
    
#if (MMI_MAX_SIM_NUM == 1)
  #define ICON_PATH RES_IMG_ROOT"\\\\NMGR_Icon\\\\"
  <IMAGE id="IMG_ID_VAPP_NCENTER_SINGLE_SIM_ICON">ICON_PATH"SIM_Card.png"</IMAGE>
#endif  
</APP>

