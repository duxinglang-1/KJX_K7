/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#ifdef WAP_SUPPORT

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_WAP_PROF"  name="STR_ID_VAPP_WAP_PROF_CBM_BROWSER" type="venus">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
     <MEMORY heap="0" cui="VCUI_DTCNT" />
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
	<STRING id="STR_ID_VAPP_WAP_PROF_CBM_BROWSER"/>
   #if 0
      <STRING id="STR_ID_VAPP_PROV_INSTALL_SETTING"/>
	  <STRING id="STR_ID_VAPP_WAP_PROF_DTCNT_ALREADY_CONFIGURED"/>
   #endif /*slim for 6260, this string never be used*/

	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_BOOKMARKS_COLON"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_BOOKMARK"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_COLON_CHAR"/>
	#if 0
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_ERR_MSG_BKM_NOT_AVAILABLE"/>
	#endif /*slim for 6260, this string never be used*/
	<STRING id="STR_ID_VAPP_WAP_PROF_ERR_MSG_INVALID_DATA_ACCOUNT"/>

#if defined(__MMI_MMS_2__)
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTINGS"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_CM_COLON"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_RM_COLON"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_MA_COLON"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_MS_COLON"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_PCADDR_COLON"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_VALUE_RESTRICTED"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_VALUE_WARNING"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_VALUE_FREE"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_VALUE_DISABLE"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_VALUE_ENABLE"/>
	<STRING id="STR_ID_VAPP_WAP_PROF_PROV_MMS_SETTING_VALUE_LOCKED"/>
#endif 
	
  <!------------------------------------------------------Other Resource---------------------------------------------------------->
	<SCREEN id="GRP_ID_VAPP_PROF_DTCNT_DISPLAY"/>
    <SCREEN id="SCR_ID_VAPP_PROF_PROV_DISPLAY_INFO"/>
  
 #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\Default\\\\USB\\\\"
    <IMAGE id="VAPP_PROV_IMG_SKIP">ROOT_PATH""</IMAGE>
    <IMAGE id="VAPP_PROV_IMG_INSTALL">ROOT_PATH""</IMAGE>  
/* Event Handlers Begin*/

/*****************************UPP Srv events ***********************************************/
	
    <SENDER id="EVT_ID_SRV_UPP_CREATE_PROV_SCR_IND" hfile="WAPProfileSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_RECREATE_PROV_SCR_IND" hfile="WAPProfileSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_PREENTRY_PROV_SCR_IND" hfile="WAPProfileSrvGProt.h"/>
    <SENDER id="EVT_ID_SRV_UPP_ENTER_DTCNT_CUI_IND" hfile="WAPProfileSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_ACTIVATE_PROFILE_IND" hfile="WAPProfileSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_CLOSE_CUI_IND" hfile="WAPProfileSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_DTCNT_READY_CHECK_IND" hfile="WAPProfileSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_DTCNT_VALID_CHECK_IND" hfile="WAPProfileSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_CHECK_DTCNT_VALID" hfile="WAPProfileSrvGProt.h"/>
	<SENDER id="EVT_ID_SRV_UPP_RE_ENTRY_ALLOWED" hfile="WAPProfileSrvGProt.h"/>

	<RECEIVER id="EVT_ID_SRV_UPP_CREATE_PROV_SCR_IND" proc="vapp_wap_prof_prov_app_prov_screen_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_RECREATE_PROV_SCR_IND" proc="vapp_wap_prof_prov_app_prov_screen_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_PREENTRY_PROV_SCR_IND" proc="vapp_wap_prof_prov_app_prov_screen_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_ENTER_DTCNT_CUI_IND" proc="vapp_wap_prof_app_entry_cui_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_CLOSE_CUI_IND" proc="vapp_wap_prof_app_close_cui"/>
	<RECEIVER id="EVT_ID_SRV_UPP_ACTIVATE_PROFILE_IND" proc="vapp_wap_prof_app_activate_profile_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_DTCNT_READY_CHECK_IND" proc="vapp_wap_prof_app_dtcnt_ready_check_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_DTCNT_VALID_CHECK_IND" proc="vapp_wap_prof_app_is_dtcnt_valid_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_CHECK_DTCNT_VALID" proc="vapp_wap_prof_app_is_dtcnt_valid_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UPP_RE_ENTRY_ALLOWED" proc="vapp_wap_prof_app_is_re_entry_allowed"/>

/*****************************UPP Srv events ***********************************************/ 
 
</APP>
#endif

  

