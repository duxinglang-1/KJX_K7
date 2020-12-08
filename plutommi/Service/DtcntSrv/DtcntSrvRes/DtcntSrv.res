/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_DTCNT">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#ifdef __MMI_WLAN_FEATURES__
    <STRING id="STR_ID_SRV_DTCNT_WLAN"/>
#endif

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
   

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
	
#ifdef __TCPIP__
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_ACTIVE" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_CONNECTED" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_INACTIVE" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_SCAN" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_CONNECT" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_BEARER_STATUS" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_CONN_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_DISC_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_IPADDR_UPDATE" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_IPADDR_CONFLICT_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_CURR_AP_INFO" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_WPS_INFO" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_CHANGE_BEARER_TO_WLAN" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_CHANGE_BEARER_TO_CELLULAR_NETWORK" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_PROV_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_PROV_INSTALL_RES_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_PROV_DONE_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_CHANGE_REAL_ACCT_IND" type="SENDER"/>	
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_DISC_RES_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_SCAN_RES_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_QRY" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WIFI_CHIP_INVALID" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_SEARCH_AP_OPEN_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_SEARCH_AP_CLOSE_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_BEARER_INIT_WLAN_AP_QUERY_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_BEARER_DEINIT_WLAN_AP_QUERY_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_AP_LIST_QUERY_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_LOGOUT_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_IPADDR_CHANGE_CNF" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_SWITCH_SAME_SSID_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_NET_STATUS_IND" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_CONN_PROF" type="SENDER"/>
    <EVENT id="EVT_ID_SRV_DTCNT_WLAN_SLEEP" type="SENDER"/>
    #ifdef __MMI_WLAN_FEATURES__ 
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="srv_dtcnt_wlan_lcd_sleep_evt_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="srv_dtcnt_wlan_lcd_sleep_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CHARBAT_NOTIFY" proc="srv_dtcnt_wlan_charbat_notify_evt_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_CBM_WLAN_UNUSED" proc="srv_dtcnt_wlan_cbm_notification_evt_hdlr"/>
    #endif
#endif

</APP>

