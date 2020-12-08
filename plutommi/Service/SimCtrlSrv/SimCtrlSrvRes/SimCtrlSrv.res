/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_SIM_CTRL">

    <SENDER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" hfile="SimCtrlSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SIM_CTRL_AVAILABLE" hfile="SimCtrlSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" hfile="SimCtrlSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SIM_CTRL_REFRESHED" hfile="SimCtrlSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SIM_CTRL_NO_SIM_AVAILABLE" hfile="SimCtrlSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SIM_CTRL_HOME_PLMN_CHANGED" hfile="SimCtrlSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SIM_CTRL_IMSI_CHANGED" hfile="SimCtrlSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" hfile="SimCtrlSrvGprot.h"/>
    
</APP>

