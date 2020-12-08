#include "mmi_features.h"
#ifdef   __MMI_CUSTOMER_SERVICE__

#include "custresdef.h"
<?xml version="1.0" encoding="UTF-8"?>
<APP id="VAPP_CUSTOMER_SERVICE"
    package_name="native.mtk.customerservice"
	name="STR_ID_VAPP_CUSTOMER_TITLE" 
	launch="vapp_customer_service_launch" 
	img="IMG_ID_VAPP_CUSTOMER_ICON"
	type="venus">
    <MEMORY base="200*1024"/>

	<!------------------------------------------String Resource Area------------------------------------------------>
	<STRING id="STR_ID_VAPP_CUSTOMER_TITLE"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_GUIDELINE"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_SALE"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_SMS_SALE"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_HOTLINE"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_MANAGER"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_MYMONWAP"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_SETTING"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_GUIDELINE_CONTENT"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_MYMONWAP_CONTENT"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_MONWAP_SMS"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_MONWAP_MMS"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_MONWAP"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_MONWAP_SMS_CONTENT"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_MONWAP_MMS_CONTENT"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_SETTING_HOTLINE"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_SETTING_MANAGER"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_SETTING_MANAGER_NUM"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_SETTING_MANAGER_NAME"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_CALL"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_CALL_VOICE"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_CALL_VEDIO"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_NOTIFY_POP"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_PRE"/>
	<STRING id="STR_ID_VAPP_CUSTOMER_NEXT"/>

	
	<!------------------------------------------Image Resource Area------------------------------------------------->
	<IMAGE id="IMG_ID_VAPP_CUSTOMER_ICON">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\SV.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_CUSTOMER_GUIDELINE">RES_IMG_ROOT"\\\\CustomerService_Icon\\\\GuideLine.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CUSTOMER_SALE">RES_IMG_ROOT"\\\\CustomerService_Icon\\\\PalmSale.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CUSTOMER_SMS_SALE">RES_IMG_ROOT"\\\\CustomerService_Icon\\\\SmsSale.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CUSTOMER_HOTLINE">RES_IMG_ROOT"\\\\CustomerService_Icon\\\\CSHotLine.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CUSTOMER_MANAGER">RES_IMG_ROOT"\\\\CustomerService_Icon\\\\CSManager.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CUSTOMER_MYMONWAP">RES_IMG_ROOT"\\\\CustomerService_Icon\\\\CSWapNet.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CUSTOMER_TB_WAP">RES_IMG_ROOT"\\\\CustomerService_Icon\\\\CSwap.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CUSTOMER_TB_MMS">RES_IMG_ROOT"\\\\CustomerService_Icon\\\\CSmms.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CUSTOMER_TB_SMS">RES_IMG_ROOT"\\\\CustomerService_Icon\\\\CSsms.png"</IMAGE>

	<!------------------------------------------Menu Item Area------------------------------------------------------>

	<!------------------------------------------Menu Tree Area------------------------------------------------------>
	#ifdef __SIM_HOT_SWAP_SUPPORT__
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_EVENT_DETECTED" proc="vapp_customer_service_simctrl_process"/>
    #endif
	<!------------------------------------------Scren Group Area---------------------------------------------------->	
</APP>

#endif
