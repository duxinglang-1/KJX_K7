#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

#ifdef __MMI_WLAN_FEATURES__

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_CBM" name="STR_ID_VAPP_CBM" type="venus">
     <MEMORY 
     	heap = "70 * 1024"
     	cui = "VCUI_DATA_ACCOUNT_WLAN"/>

    <!------------------------String Resource Area-------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_VAPP_CBM"/>
    <STRING id="STR_ID_VAPP_CBM_WLAN_NOT_AVAILABLE_USE_CELLULAR"/>
    <STRING id="STR_ID_VAPP_CBM_WLAN_NOT_AVAILABLE_USE_CELLULAR_NO_MORE_ASK"/>
    <STRING id="STR_ID_VAPP_CBM_WLAN_SIGNAL_AVAILABLE_USE_NOW"/>
    <STRING id="STR_ID_VAPP_CBM_WLAN_CONNECTION_FAILED_USE_OTHER"/>
    <STRING id="STR_ID_VAPP_CBM_WLAN_CONNECTION_FAILED_USE_CELLULAR"/>
    <STRING id="STR_ID_VAPP_CBM_WLAN_DISCONNECTED_USE_OTHER"/>
    <STRING id="STR_ID_VAPP_CBM_WLAN_DISCONNECTED_USE_CELLULAR"/>
    <STRING id="STR_ID_VAPP_CBM_WLAN_SIGNAL_AVAILABLE_WARNING"/>
    <STRING id="STR_ID_VAPP_CBM_WLAN_CONNECTION_FAILED"/>
    <STRING id="STR_ID_VAPP_CBM_WLAN_DISCONNECTED"/>
    <STRING id="STR_ID_VAPP_CBM_USE_WLAN_NETWORK"/>
    <STRING id="STR_ID_VAPP_CBM_USE_CELLULAR"/>

    <!------------------------Image Resource Area--------------------------->

    <!-------------------------Menu Resource Area--------------------------->

    <!------------------------Screen Resource Area-------------------------->

    <!---------------------------Other Resource----------------------------->
    <RECEIVER id="EVT_ID_SRV_CBM_WLAN_QUERY" proc="vappCbmSrvCbmWlanQueryEvtHdlr"/>
    <RECEIVER id="EVT_ID_VAPP_SCREEN_LOCK_LOCKED_EVT" proc="vappCbmEvtProcHdlr"/>
    <RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="vappCbmEvtProcHdlr"/>
#if defined(__MMI_NCENTER_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    <RECEIVER id="EVT_ID_VAPP_NCENTER_ENTERED" proc="vappCbmEvtProcHdlr"/>
    <RECEIVER id="EVT_ID_VAPP_NCENTER_EXITED" proc="vappCbmEvtProcHdlr"/>
#endif
    <RECEIVER id="EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND" proc="vappCbmEvtProcHdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="vappCbmEvtProcHdlr"/>

</APP>

#else /* __MMI_WLAN_FEATURES__ */

<APP id="VAPP_CBM"></APP>

#endif /* __MMI_WLAN_FEATURES__ */
