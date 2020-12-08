#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifndef __MMI_WLAN_FEATURES__

<APP id="VCUI_DATA_ACCOUNT_WLAN"></APP>

#else

<APP id="VCUI_DATA_ACCOUNT_WLAN" name="STR_ID_VCUI_WLAN" type="venus">
    <MEMORY 
#ifdef __MMI_OP01_WIFI__
     base="1024*200" cui="VCUI_FMGR"/>
#else
     base="1024*200" />
#endif

<!-- 
**************************************** String Id ****************************************
-->
   
    <STRING id="STR_ID_VCUI_WLAN"/>
             
<!-- 
**************************************** Image section ****************************************
-->

<!-- 
**************************************** Callback Manager Receiver ****************************************
-->

</APP>

#endif
