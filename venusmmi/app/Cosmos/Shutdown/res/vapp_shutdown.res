/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_SHUTDOWN" name="STR_ID_VAPP_SHUTDOWN_APP_NAME" type="venus">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
    <MEMORY base="100000"/>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <IMAGE id="IMG_ID_VAPP_SHUTDOWN_ANIMATION" flag="REPLACEABLE">RES_IMG_ROOT"\\\\BootupShutdown\\\\Animation\\\\POWER_OFF_ANI.gif"</IMAGE>
    
    <RECEIVER id="EVT_ID_SRV_SHUTDOWN_NORMAL_START" proc="vapp_shutdown_normal_start"/>

    <TIMER id="VAPP_SHUTDOWN_GUARD_TIMER"/>

</APP>

