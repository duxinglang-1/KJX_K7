/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_NMGR">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#ifdef __MMI_SUBLCD__	  
	  <IMAGE id = "IMG_ID_ALARM_ANIMATION_INDICATION_SUBLCD">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_alarm.gif"</IMAGE>   
    <IMAGE id = "IMG_ID_UCM_SUBLCD_INCOMING_CALL">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\Call\\\\SB_MOMT.GIF"</IMAGE>
    <IMAGE id="IMG_ID_UCM_SUBLCD_CALLING">CUST_IMG_PATH"\\\\SUBLCD\\\\Active\\\\Call\\\\SB_MOMT.GIF"</IMAGE>
#endif

#ifdef __MMI_NCENTER_SUPPORT__
	  <IMAGE id = "IMG_ID_DEFAULT_PREVIEW_ICON" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Default.png"</IMAGE>
#endif
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_NMGR_MESSGAGE_CONFIRM"/>
#ifdef __MMI_SUBLCD__		
		<SCREEN id="SCR_ID_ALARM_SUBLCD_IND"/>
		<SCREEN id="SCR_ID_UCM_INCOMING_CALL_SUBLCD"/>
		<SCREEN id="SCR_ID_UCM_OUTGOING_CALL_SUBLCD"/>
#endif
     
#ifdef __MMI_SUBLCD__
	  <RECEIVER id="EVT_ID_SCENARIO_END" proc="mmi_nmgr_sub_lcd_hdlr"/>
	  <RECEIVER id="EVT_ID_GPIO_CLAM_OPEN" proc="mmi_nmgr_sub_lcd_hdlr"/>
	  <RECEIVER id="EVT_ID_GPIO_CLAM_CLOSE" proc="mmi_nmgr_sub_lcd_hdlr"/>
	  <RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="mmi_nmgr_sub_lcd_hdlr"/>
	  <RECEIVER id="EVT_ID_NMGR_SUBLCD_NOTIFY" proc="mmi_nmgr_sub_lcd_hdlr"/>
	  <RECEIVER id="EVT_ID_SRV_UCM_ACTION_NOTIFY" proc="mmi_nmgr_sub_lcd_hdlr"/>

#endif
#ifdef __COSMOS_MMI_PACKAGE__
	  <RECEIVER id="EVT_ID_SCRN_ENTER_SUCCESS_NOFITY" proc="mmi_nmgr_listen_scrn_enter"/>
#endif

    <TIMER id="MMI_NOTIFICATION_SERVICE_TIMER"/>
    <TIMER id="MMI_NMGR_VIB_THEN_RING_TIMER"/>
#ifdef __COSMOS_MMI_PACKAGE__
    <TIMER id="MMI_NOTIFICATION_AUDIO_TIMER"/>
#endif
    <SENDER id="EVT_ID_NMGR_FORCE_DEFER_QUERY" hfile="GlobalResDef.h"/>
#if (defined(__OP01__) || defined(__OP02__)) && !defined(__COSMOS_MMI_PACKAGE__)
    <RECEIVER id="EVT_ID_NMGR_FORCE_DEFER_QUERY" proc="mmi_nmgr_op01_defer_check_hdlr"/>
    <RECEIVER id="EVT_ID_MMI_UM_ENTRY_FOLDER" proc="mmi_nmgr_um_cb"/>
#endif

</APP>


