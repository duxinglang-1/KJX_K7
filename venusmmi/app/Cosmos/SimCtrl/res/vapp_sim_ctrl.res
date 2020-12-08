/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_SIM_CTRL" name="STR_ID_VAPP_SIM_CTRL_APP_NAME" type="venus">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_VAPP_SIM_CTRL_APP_NAME"/>
    <STRING id="STR_ID_VAPP_SIM_CTRL_SIM_REMOVED"/>
    <STRING id="STR_ID_VAPP_SIM_CTRL_SIM_ACCESS_ERROR"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_SIM_CTRL_SIMX_REMOVED"/>
    <STRING id="STR_ID_VAPP_SIM_CTRL_SIMX_ACCESS_ERROR"/>
#endif
#if (MMI_MAX_SIM_NUM >= 2) && defined(__UMTS_RAT__)
    <STRING id="STR_ID_VAPP_SIM_CTRL_3G_SLOT_HINT"/>
#endif

#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)

    <STRING id="STR_ID_VAPP_SIM_CTRL_SIM_INSERTED"/>
    <STRING id="STR_ID_VAPP_SIM_CTRL_SIMX_INSERTED"/>


#endif /* __SIM_HOT_SWAP_SUPPORT__ */

    <STRING id="STR_ID_VAPP_SIM_CTRL_SIM_CAME_OFF"/>
    <STRING id="STR_ID_VAPP_SIM_CTRL_SIMX_CAME_OFF"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

    <MEMORY base="80000"/>

    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="vapp_sim_ctrl_on_sim_avai_changed"/>
#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="vapp_sim_ctrl_on_sim_event_detected"/>
#endif

</APP>

