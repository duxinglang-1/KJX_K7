/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#ifdef __MMI_BRW_PUSH_WHITELIST_OTA_SUPPORT__

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VCUI_WAP_PUSH_PROV"  name="STR_ID_VAPP_PUSH_PROV_CUI" type="venus">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
     <MEMORY heap="250*1024" />
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="STR_ID_VAPP_PUSH_PROV_CUI"/>

</APP>
#endif

