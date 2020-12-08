#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifndef __MMI_WLAN_FEATURES__

<APP id="VCUI_DATA_ACCOUNT_WLAN_SETTING"></APP>

#else

<APP id="VCUI_DATA_ACCOUNT_WLAN_SETTING" name="STR_ID_VCUI_WLAN_SETTING" type="venus">
    <MEMORY 
#ifdef __MMI_OP01_WIFI__
	#ifdef __CERTMAN_SUPPORT__
     	base="512*1000" cui="max(VCUI_FMGR, VAPP_CERTMAN)"/>
	#else
     	base="512*1000" cui="VCUI_FMGR"/>
	#endif     
#else
     base="512*1000" />
#endif

<!-- 
**************************************** String Id ****************************************
-->
           
    <STRING id="STR_ID_VCUI_WLAN_SETTING"/>   
     
<!-- 
**************************************** Image section ****************************************
-->

<!-- 
**************************************** Callback Manager Receiver ****************************************
-->

</APP>

#endif