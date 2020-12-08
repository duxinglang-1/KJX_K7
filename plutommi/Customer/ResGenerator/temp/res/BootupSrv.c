/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_BOOTUP">

    <SENDER id="EVT_ID_SRV_BOOTUP_START" hfile="BootupSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_BOOTUP_EARLY_INIT" hfile="BootupSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_BOOTUP_NORMAL_INIT" hfile="BootupSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_BOOTUP_BEFORE_IDLE" hfile="BootupSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_BOOTUP_COMPLETED" hfile="BootupSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_BOOTUP_SIM_STATUS_CHANGED" hfile="BootupSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_BOOTUP_SIM_SLOT_READY" hfile="BootupSrvGprot.h"/>

</APP>

