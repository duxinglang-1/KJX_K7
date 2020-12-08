/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

#ifdef __MMI_PROV_MESSAGE_SUPPORT__

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_PROVBOX">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------ProvBox Service Events begin--------------------------------------------------->
    <EVENT id="EVT_ID_SRV_PROVBOX_NOTIFY_IND"   type="SENDER"/>
    <EVENT id="EVT_ID_SRV_PROVBOX_NEW_MSG_IND"  type="SENDER"/>
    <EVENT id="EVT_ID_SRV_PROVBOX_EVT_IND"      type="SENDER"/>

    <!-----------------ProvBox Service Events end--------------------------------------------------->
</APP>

#endif /* __MMI_PROV_MESSAGE_SUPPORT__ */