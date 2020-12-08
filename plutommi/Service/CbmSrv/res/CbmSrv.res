#include "MMI_features.h" 
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>
    
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_CBM">

#ifdef __TCPIP__

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!------------------------String Resource Area-------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    
/* take care of using the string "STR_ID_SRV_CBM_DISALLOW_ERROR" */
#ifndef __ABM_CBM_SLIM__
    <STRING id="STR_ID_SRV_CBM_DISALLOW_ERROR"/>
#endif

    <!------------------------Image Resource Area--------------------------->

    <!------------------------Screen Resource Area-------------------------->

    <!-------------------------Menu Resource Area--------------------------->

    <!------------------------Screen Resource Area-------------------------->

    <!---------------------------Other Resource----------------------------->
	<SENDER id="EVT_ID_SRV_CBM_BEARER_UNAVAILABLE" hfile="CbmSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_CBM_BEARER_AVAILABLE" hfile="CbmSrvGprot.h"/>
	<SENDER id="EVT_ID_SRV_CBM_BEARER_INFO" hfile="CbmSrvIprot.h"/>
	<SENDER id="EVT_ID_SRV_CBM_BEARER_EVENT" hfile="CbmSrvIprot.h"/>
	<SENDER id="EVT_ID_SRV_CBM_WLAN_QUERY" hfile="CbmSrvIprot.h"/>
	<SENDER id="EVT_ID_SRV_CBM_WLAN_UNUSED" hfile="CbmSrvIprot.h"/>

#ifdef __MMI_WLAN_FEATURES__
    <TIMER id="SRV_CBM_WLAN_AUTO_SEARCH_TIMER"/>
    <TIMER id="SRV_CBM_WLAN_PREFER_DELAY_TIMER"/>
#endif /* __MMI_WLAN_FEATURES__ */

#endif /* __TCPIP__ */

</APP>
