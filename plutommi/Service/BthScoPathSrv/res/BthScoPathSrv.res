/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

#ifdef __MMI_BT_AUDIO_SUPPORT__

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_BTSCO">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------BTSCO Service Events begin--------------------------------------------------->
    <EVENT id="EVT_ID_SRV_BTSCO_CLOSE_IND"   type="SENDER"/>

    <!-----------------BTSCO Service Events end--------------------------------------------------->

    <!-----------------BTSCO Service Timer begin--------------------------------------------------->
    <TIMER id="BT_SCO_CONNECT_TIMER"/>
    <TIMER id="BT_SCO_ENABLE_CONNECT_DELAY_TIMER"/>
    
    <!-----------------BTSCO Service Timer end--------------------------------------------------->

</APP>

#endif /* __MMI_BT_AUDIO_SUPPORT__ */