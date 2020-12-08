#include "mmi_features.h"
#include "custresdef.h"
<?xml version="1.0" encoding="UTF-8"?>
<APP id="VAPP_JAVA" name= "STR_ID_VAPP_SCR_JAVA_CAPTION" type="venus">
	<INCLUDE file="GlobalResDef.h"/>
#ifdef __J2ME__

#ifdef __LOW_COST_SUPPORT_COMMON__    
    <MEMORY heap="200*1024"/>
#else
    <MEMORY heap="400*1024"/>
#endif
    <APPCONCURRENT concurrent_w_order="APP_OPERA, VAPP_JAVA"/>

#endif
<!------------------------------------ String ID --------------------------------->
	<STRING id="STR_ID_VAPP_SCR_JAVA_CAPTION">Java</STRING>
	<STRING id="STR_ID_VAPP_JAVA_TASK_MANAGER_DESC">The maximum of MIDlet suite number has reached. Please choose to exit one MIDlet</STRING>
	<STRING id="STR_ID_VAPP_JAVA_INSTALL">Install</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_TASK_MANAGER">Java task manager</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_ERROR_OVERMAX_LAUNCH_NUM">Over the maximum of launch number</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_APP_SETTINGS">Java settings</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_VM_BUSY" >Java enginee busy</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_OVERMAX_LAUNCH_CONFIRM">Over the maximum of launch number.Stop the running application now?</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_MIDS_RUNNING_WARNING">Please exit the running application</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_RESET_RMS_ASK">Keep old RMS?</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_ERROR_CODE_JAR_NOT_FOUND">JAR not found</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_VM_TERMINATING">Java is terminating</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_TERMINATE">Terminate</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_MINIMIZE">Minimize</STRING>
  	<STRING id="STR_ID_VAPP_JAVA_RESOURCE_CONFLICT"/>
	<STRING id ="STR_ID_VAPP_JAVA_VK_SWITCH">Java virtual keypad</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_PERMISSION">Permission</STRING>
	<STRING id ="STR_ID_VAPP_JAVA_WLAN_ONLY_SUB">Always use WLAN</STRING>
<!------------------------------------ Image ID ---------------------------------->
<IMAGE id="IMG_ID_VJAVA_PLAY">CUST_IMG_PATH"\\\\MainLCD\\\\JAVA\\\\SB_PLAY.PBM"</IMAGE>
<IMAGE id="IMG_JAVA_COSMOS_FMGR">RES_IMG_ROOT"\\\\FMGR\\\\ListIcon\\\\JAVA.png"</IMAGE>
#ifdef __COSMOS_MMI_PACKAGE__	
<THEME>
<IMAGE id="IMG_ID_VJAVA_MAINMENU_ICON" desc="Main menu java default icon">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\Java.png"</IMAGE>
</THEME>
<THEME>
<IMAGE id="IMG_ID_VJAVA_MAINMENU_TCARD_ICON" desc="Main menu java default tcard icon">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\TCard.png"</IMAGE>
</THEME>
#endif
<!----------------------------------------Menu ID ----------------------------------------->
#ifdef __COSMOS_MMI_PACKAGE__	
	<MENU id="MENU_ID_VENUS_FMGR_JAD_TYPE_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
		<MENUITEM_ID>MENU_ID_VENUS_FMGR_JAVA_OPTION_EXECUTE</MENUITEM_ID>
	</MENU>		
	<MENUITEM id="MENU_ID_VENUS_FMGR_JAVA_OPTION_EXECUTE" str="STR_ID_VAPP_JAVA_INSTALL" />
#endif
</APP>
#ifdef __J2ME__
#ifdef __COSMOS_MMI_PACKAGE__
<APP id="VAPP_JAVA_TEXTBOX" name="STR_JAVA_TEXTBOX">

#ifdef __LOW_COST_SUPPORT_COMMON__
    <MEMORY heap="200*1024"/>
#else
  <MEMORY heap="400*1024" fg="$(HW_LAYER_BUFFER_SIZE)" cui="VCUI_CONTACT_LIST" inc="J2me_custom_param.h,GlobalResDef.h"/>
#endif
  
  <STRING id="STR_JAVA_TEXTBOX">TextBox</STRING>
</APP>
<FILE_TYPES>
	<FILE_OPTION_HDLR option = "MENU_ID_VENUS_FMGR_JAD_TYPE_OPTIONS" enabler = "mmi_java_jad_option_enabler" />
	<FILE_OPTION_HDLR option ="MENU_ID_VENUS_FMGR_JAVA_OPTION_EXECUTE" handler="mmi_java_fmgr_install_hdlr"/>
	<FILE_TYPE type_id="FMGR_COSMOS_TYPE_JAD" extension="JAD" small_icon="IMG_JAVA_COSMOS_FMGR" large_icon="IMG_JAVA_COSMOS_FMGR" option="MENU_ID_VENUS_FMGR_JAD_TYPE_OPTIONS"/>
	<FILE_TYPE type_id="FMGR_COSMOS_TYPE_JAR" extension="JAR" small_icon="IMG_JAVA_COSMOS_FMGR" large_icon="IMG_JAVA_COSMOS_FMGR" option="MENU_ID_VENUS_FMGR_JAD_TYPE_OPTIONS"/>
</FILE_TYPES>
#endif
#ifdef __MMI_USB_SUPPORT__
<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="jam_enter_usb_ms_callback"/>
#endif
#endif
