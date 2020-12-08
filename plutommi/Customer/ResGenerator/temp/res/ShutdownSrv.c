/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_SHUTDOWN">

    <SENDER id="EVT_ID_SRV_SHUTDOWN_NORMAL_START" hfile="ShutdownSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SHUTDOWN_DEINIT" hfile="ShutdownSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SHUTDOWN_HANDLER_RESET" hfile="ShutdownSrvGprot.h"/>
    <SENDER id="EVT_ID_SRV_SHUTDOWN_FINAL_DEINIT" hfile="ShutdownSrvGprot.h"/>

</APP>

