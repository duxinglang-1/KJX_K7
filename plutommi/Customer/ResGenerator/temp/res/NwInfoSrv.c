/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_NW_INFO">

    <SENDER id="EVT_ID_SRV_NW_INFO_STATUS_CHANGED" hfile="NwInfoSrvGprot.h"/>   
    <SENDER id="EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED" hfile="NwInfoSrvGprot.h"/> 
    <SENDER id="EVT_ID_SRV_NW_INFO_SIGNAL_STRENGTH_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_LOCATION_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_ROAMING_STATUS_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_PROTOCOL_CAPABILITY_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_SIM_DN_STATUS_CHANGED" hfile="NwInfoSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_NW_INFO_REGISTER_FAILED" hfile="NwInfoSrvGprot.h"/>
#ifdef __HOMEZONE_SUPPORT__ 
    <SENDER id="EVT_ID_SRV_NW_INFO_HOMEZONE_STATUS_CHANGED" hfile="NwInfoSrvGprot.h"/>
#endif  
#ifdef __MMI_NETWORK_CIPHER_SUPPORT__
    <SENDER id="EVT_ID_SRV_NW_INFO_CIPHER_STATUS_CHANGED" hfile="NwInfoSrvGprot.h"/>
#endif /* __MMI_NETWORK_CIPHER_SUPPORT__ */

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="srv_nw_info_on_sim_availability_changed"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="srv_nw_info_notify_mode_changed"/>
#if defined(__TCPIP__) && defined(__MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__)
    <RECEIVER id="EVT_ID_SRV_CNMGR_NOTIFY_NWINFO" proc="srv_nw_info_cnmgr_notify_nwinfo_hdlr"/>
#endif
    <TIMER id="TIMER_ID_SRV_NW_INFO_SIGNAL_ANIMATION"/>
    
</APP>

