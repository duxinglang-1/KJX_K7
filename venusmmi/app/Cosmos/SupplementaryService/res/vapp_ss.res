/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SS" name="STR_ID_VAPP_SS_SIM1" type="venus">
    <MEMORY heap="200*1024"/>
    <LAYOUT file="vapp_ss.xml" />

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------Event Resource Area----------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_SS_ACT_NOTIFY" proc="vapp_ss_hdlr_act_notify"/>
    <RECEIVER id="EVT_ID_SRV_SS_INDICATION" proc="vapp_ss_hdlr_ind"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <STRING id="STR_ID_VAPP_SS_TITLE"/>
    <STRING id="STR_ID_VAPP_SS_REQUESTING"/>
    <STRING id="STR_ID_VAPP_SS_SIM1"/>
    <STRING id="STR_ID_VAPP_SS_USSD_MSG"/>
    <STRING id="STR_ID_VAPP_SS_ABORTED"/>
    <STRING id="STR_ID_VAPP_SS_TIMEOUT"/>
    <STRING id="STR_ID_VAPP_SS_TIMEOUT2"/>

    /* used by ss core */
    <STRING id="STR_ID_SS_PERIOD"/>
    <STRING id="STR_ID_SS_SECOND"/>
    <STRING id="STR_ID_SS_CHANGE_PSW_SUC"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    /* For the detail of scope="XML" please check user manual */


</APP>


#if (MMI_MAX_SIM_NUM >= 2)
<APP id="VAPP_SS_2" name="STR_ID_VAPP_SS_SIM2" type="venus">
    <MEMORY heap="200*1024"/>
    
    <STRING id="STR_ID_VAPP_SS_SIM2"/>  
</APP>
#if (MMI_MAX_SIM_NUM >= 3)
<APP id="VAPP_SS_3" name="STR_ID_VAPP_SS_SIM3" type="venus">
    <MEMORY heap="200*1024"/>
    
    <STRING id="STR_ID_VAPP_SS_SIM3"/>  
</APP>
#if (MMI_MAX_SIM_NUM >= 4)
<APP id="VAPP_SS_4" name="STR_VAPP_ID_SS_SIM4" type="venus">
    <MEMORY heap="200*1024"/>
    
    <STRING id="STR_ID_VAPP_SS_SIM4"/>  
</APP>
#endif /* (MMI_MAX_SIM_NUM >= 4) */
#endif /* (MMI_MAX_SIM_NUM >= 3) */
#endif /* (MMI_MAX_SIM_NUM >= 2) */

