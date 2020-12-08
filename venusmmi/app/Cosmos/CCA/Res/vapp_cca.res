#include "mmi_features.h"
#include "custresdef.h"

#define xstr(s) str(s)
#define str(s) #s

#if defined(SYNCML_DM_SUPPORT) && defined(__CCA_SUPPORT__)
	#define OPTION_VCUI_DM_OTAP   VCUI_DM_OTAP
#else 
	#define OPTION_VCUI_DM_OTAP    0
#endif



#ifdef __MMI_EMAIL_OTAP__
	#define OPTION_VCUI_EMAIL_OTAP VCUI_EMAIL_OTAP
#else
	#define OPTION_VCUI_EMAIL_OTAP  0
#endif 




#ifdef __MMI_AGPS_OTAP__
	#define OPTION_VCUI_GPS_SETTING_OTAP  VCUI_GPS_SETTING_OTAP
#else 
	#define OPTION_VCUI_GPS_SETTING_OTAP  0
#endif

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_CCA" name="STR_APP_VCCA" type="venus">

	#ifdef __MMI_CCA_SUPPORT__ 
      <MEMORY heap="200*1024" cui=xstr(max((VCUI_WAP_PROV + VAPP_DTCNT_PROV), OPTION_VCUI_DM_OTAP, OPTION_VCUI_EMAIL_OTAP, OPTION_VCUI_GPS_SETTING_OTAP))/>

	<STRING id = "STR_ID_VAPP_CCA_INSTALL_PROGRESS">Configuring</STRING>
    <STRING id = "STR_ID_VAPP_CCA_PIN_TITLE">Please input PIN</STRING>
    <STRING id = "STR_ID_VAPP_CCA_INVALID_SETTINGS">Invalid settings</STRING>
    <STRING id = "STR_ID_VAPP_CCA_INVALID_PIN">Incorrect PIN</STRING>
    <STRING id = "STR_ID_VAPP_CCA_INSTALL_LIST_TITLE">New settings</STRING>
    <STRING id = "STR_ID_VAPP_CCA_INSTALL_RESULT_TITLE">Install summary report</STRING>
    <STRING id = "STR_ID_VAPP_CCA_MEM_FULL">Insufficiate memory</STRING>
    <STRING id = "STR_ID_VAPP_CCA_NO_APP">Unsupported settings</STRING>
    <STRING id = "STR_ID_VAPP_CCA_NO_AVAILABLE">Not available</STRING>
    <STRING id = "STR_ID_VAPP_CCA_PIN_ABORT">Abort</STRING>
    <STRING id = "STR_ID_VAPP_CCA_PIN_NEED_RETRY">Please retry</STRING>
    <STRING id = "STR_ID_VAPP_CCA_PIN_FAIL">Pin verify fail</STRING>
    <STRING id = "STR_ID_VAPP_CCA_PIN_PASS">Pass verify</STRING>
    <STRING id = "STR_ID_VAPP_CCA_MODIFY">Modify</STRING>
    <STRING id = "STR_ID_VAPP_CCA_AUTH_FAIL">Authentication failed</STRING>
        
#if defined(__MMI_WLAN_OTAP_OMAEXT__) || defined(__MMI_WLAN_OTAP_DMP__)
    <STRING id = "STR_ID_VAPP_CCA_WLAN">Wireless LAN</STRING>
#endif
#ifdef BROWSER_SUPPORT
    <STRING id = "STR_ID_VAPP_CCA_BROWSER">Browser</STRING>
#endif
#ifdef MMS_SUPPORT
    <STRING id = "STR_ID_VAPP_CCA_MMS">MMS</STRING>
#endif
#ifdef __MMI_VOIP_OTAP_DMP__
    <STRING id = "STR_ID_VAPP_CCA_SIP">VoIP</STRING>
#endif
#ifdef __MMI_SYNCML_CCA_SUPPORT__
    <STRING id = "STR_ID_VAPP_CCA_SYNCMLDS">Synchronization</STRING>
#endif
#ifdef SYNCML_DM_SUPPORT
    <STRING id = "STR_ID_VAPP_CCA_SYNCMLDM">Device management</STRING>
#endif
#ifdef __MMI_IMPS_OTA__
    <STRING id = "STR_ID_VAPP_CCA_IMPS">Instant message</STRING>
#endif
#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__
    <STRING id = "STR_ID_VAPP_CCA_PUSH">Service message</STRING>
#endif
#ifdef __MMI_STREAMING_OTAP__
    <STRING id = "STR_ID_VAPP_CCA_RTSP">RTSP</STRING>
#endif
#ifdef __MMI_AGPS_OTAP__
    <STRING id = "STR_ID_VAPP_CCA_SUPL">AGPS</STRING>
#endif
    <STRING id = "STR_ID_VAPP_CCA_CONFIGURED">Configured</STRING>
    <STRING id = "STR_ID_VAPP_CCA_FAILED">Failed</STRING>
    <STRING id = "STR_ID_VAPP_CCA_INVALID_SETTING">Invalid</STRING>
    <STRING id = "STR_ID_VAPP_CCA_UPDATED">Updated</STRING>
    <STRING id = "STR_ID_VAPP_CCA_SKIPPED">Skipped</STRING>
    <STRING id = "STR_ID_VAPP_CCA_NOT_INSTALLED">Not installed</STRING>
    <STRING id = "STR_ID_VAPP_CCA_CONFIGURATION">Configuration:</STRING>
	<STRING id = "STR_ID_VAPP_CCA_CORRUPTED_SETTING">Corrupted settings</STRING>
	<STRING id = "STR_ID_VAPP_CCA_MISSING_DATA">Incomplete settings</STRING>
	<STRING id = "STR_ID_VAPP_CCA_INSTALL_SETTING">Install settings</STRING>
    <STRING id = "STR_ID_VAPP_CCA_REPLACE_SETTING">Replace settings</STRING>
    <STRING id = "STR_ID_VAPP_CCA_SKIP_PROFILE">Skip this profile?</STRING>
    <STRING id = "STR_ID_VAPP_CCA_PROFILE_IN_USE">Profile in use</STRING>
    <STRING id = "STR_ID_VAPP_CCA_SKIP">Skip</STRING>
    <STRING id = "STR_ID_VAPP_CCA_ABORT_ASK">Cancel?</STRING>
    <STRING id = "STR_ID_VAPP_CCA_UPDATE_PROFILE">Update existing profile</STRING>
	<STRING id = "STR_ID_VAPP_CCA_PROFILE">Profile</STRING>
	<STRING id = "STR_ID_VAPP_CCA_NEW_SETTING">New settings</STRING> 
    <STRING id = "STR_ID_VAPP_CCA_PIN_EMPTY">Please input PIN</STRING>
    <STRING id = "STR_ID_VAPP_CCA_GET_MSG_FAILED">Failed to get settings</STRING>
    <STRING id = "STR_ID_VAPP_CCA_UPDATE_MSG_FAILED">Failed to update settings</STRING>
    <STRING id = "STR_ID_VAPP_CCA_EXIT_INSTALL_CONFIRM">Exit installing settings? Installed settings will be saved</STRING>
  
#ifndef __MMI_PROV_IN_UM__   
    <STRING id = "STR_ID_VAPP_CCA_INSTALLING_RETRY">Please complete installing one first</STRING>
    <STRING id = "STR_ID_VAPP_CCA_NCENTER_NEW_SETTING">new settings</STRING>
	  <STRING id = "STR_ID_VAPP_CCA_NCENTER_SETTING_MESSAGE">Settings message</STRING>	
#endif /* __MMI_PROV_IN_UM__ */

    #define MSG_ROOT_PATH RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\"
    #define CCA_ROOT_PATH RES_IMG_ROOT"\\\\\\\\"
    #define VCP_ROOT_PATH RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\"
    <IMAGE id="IMG_ID_VAPP_CCA_SKIP">MSG_ROOT_PATH"Skin.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CCA_REPLACE">MSG_ROOT_PATH"Replace.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CCA_INSTALL">VCP_ROOT_PATH"Install.png"</IMAGE>
 
#ifndef __MMI_PROV_IN_UM__   
		<TIMER id = "TIMER_ID_VAPP_CCA_NMGR_POPUP"/>
#endif /* __MMI_PROV_IN_UM__ */


#endif /* __MMI_CCA_SUPPORT__ */
</APP>
