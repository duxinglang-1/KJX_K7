/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="CUI_VERIFY">

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_UNAVAILABLE" proc="cui_verify_sim_on_sim_unavailable"/>

</APP>

