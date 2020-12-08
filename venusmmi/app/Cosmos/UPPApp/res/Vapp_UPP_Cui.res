/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#ifdef WAP_SUPPORT

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VCUI_WAP_PROV"  name="STR_ID_VAPP_PROV_CUI" type="venus">


    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>
     <MEMORY heap="200*1024" />
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="STR_ID_VAPP_PROV_CUI"/>
    

</APP>
#endif

