/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

#ifdef __GADGET_SUPPORT__

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_WIDGET_DELEGATOR_IDLE"
    package_name = "native.mtk.vapp_widget_delegator_idle" 
    name="STR_ID_VAPP_WIDGET_DELEGATOR_IDLE" type="venus"
    hidden_in_mainmenu="true">

    <MEMORY extra_base="($(VAPP_WIDGET_IDLE_FG_SIZE) + fg(SRV_MDI_AUDPLY))"            
            inc="../../../venusmmi/app/Cosmos/WidgetDelegator/vapp_widget_defs.h"/>
</APP>

<APP id="VAPP_WIDGET_DELEGATOR" 
    package_name = "native.mtk.vapp_widget_delegator" 
	  name="STR_ID_VAPP_WIDGET_DELEGATOR" type="venus" 
	  package_proc = "vapp_widget_delegator_proc" 
	  hidden_in_mainmenu="true">
    
    <MEMORY heap="1024*200"
            extra_base="base(SRV_MDI_AUDPLY)"
            fg="($(VAPP_WIDGET_DETAILS_FG_SIZE) + fg(SRV_MDI_AUDPLY))"            
            inc="../../../venusmmi/app/Cosmos/WidgetDelegator/vapp_widget_defs.h"/>
            
#ifdef OPERA_BROWSER
    <APPCONCURRENT concurrent_w_order ="VAPP_WIDGET_DELEGATOR, APP_OPERA"/>
#endif
    
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_VAPP_WIDGET_PERMISSION_NOT_GRANTED"/>
    <STRING id="STR_ID_VAPP_WIDGET_PATH_NOT_FOUND"/>
    <STRING id="STR_ID_VAPP_WIDGET_FAILED_LOAD_WIDGET"/>
    <STRING id="STR_ID_VAPP_WIDGET_REMOVE_SOME_WIDGETS_FIRST"/>
    <STRING id="STR_ID_VAPP_WIDGET_MEMORY_FULL"/>
    <STRING id="STR_ID_VAPP_WIDGET_ALLOW_NETWORK_ACCESS"/>
    <STRING id="STR_ID_VAPP_WIDGET_MAXIMUM_REACHED"/>
    <STRING id="STR_ID_VAPP_WIDGET_ALLOW_SEND_SMS"/>
    <STRING id="STR_ID_VAPP_WIDGET_DOWNLOADED_WIDGETS"/>
    <STRING id="STR_ID_VAPP_WIDGET_NOT_AVAILABLE_IN_USB_MODE"/>
    <STRING id="STR_ID_VAPP_WIDGET_BUSY_NOW_PLEASE_TRY_LATER"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    /*
    <IMAGE id="IMG_ID_TEMPLATE_01" >CUST_IMG_PATH"\\\\MainLCD\\\\Test\\\\01.bmp"</IMAGE>
    <IMAGE id="IMG_ID_TEMPLATE_02" >CUST_IMG_PATH"\\\\MainLCD\\\\Test\\\\02.bmp"</IMAGE>
    <IMAGE id="IMG_ID_TEMPLATE_03" force_type="FORCE_AB2">CUST_IMG_PATH"\\\\MainLCD\\\\Test\\\\03.bmp"</IMAGE>
     */
    /* Example: How to use compile option in path, __MMI_RES_TYPE_WALLPAPER__ is defined in mmi_features.h */
    /* #define __MMI_RES_TYPE__ ".gif" */

    /* For the detail of scope="XML" please check user manual */

    <IMAGE id="IMG_ID_VAPP_WIDGET_SETTING_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Homescreen\\\\widget\\\\WidgetDelegator\\\\Widget_setting_up.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_SETTING_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Homescreen\\\\widget\\\\WidgetDelegator\\\\Widget_setting_down.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_LOAD_BACKGROUND">RES_IMG_ROOT"\\\\Widget\\\\Widget_BG.9slice.png"</IMAGE>   
    <IMAGE id="IMG_ID_VAPP_WIDGET_TEXT_BACKGROUND">RES_THEME_ROOT"\\\\Theme1\\\\Widget\\\\Text_BG01.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_TEXT_BTN_D">RES_THEME_ROOT"\\\\Theme1\\\\Widget\\\\OK_D.png"</IMAGE>   
    <IMAGE id="IMG_ID_VAPP_WIDGET_TEXT_BTN_N">RES_THEME_ROOT"\\\\Theme1\\\\Widget\\\\OK_N.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_WIDGET_TEXT_BTN_P">RES_THEME_ROOT"\\\\Theme1\\\\Widget\\\\OK_P.png"</IMAGE>      


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
    <SCREEN id="GRP_ID_WIDGET_VIEW"/>
    <SCREEN id="GRP_ID_WIDGET_EDITOR"/>
    <SCREEN id="SCR_ID_WIDGET_VIEW"/>
    <SCREEN id="SCR_ID_WIDGET_EDITOR"/>

    <!------------------------------------------------------CallBack Manager---------------------------------------------------------->    
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="widget_fmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="widget_fmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_MODE_SWITCH_PRE_NOTIFY" proc="widget_mode_switch_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_WGTMGR_FILE_NOT_EXISTS_IND" proc="widget_wgtmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_WGTMGR_DELETE_WIDGET_IND" proc="widget_wgtmgr_notify_hdlr"/>
#ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vapp_widget_usb_notify_hdlr"/>
    <RECEIVER id="EVT_ID_USB_EXIT_MS_MODE" proc="vapp_widget_usb_notify_hdlr"/>
#endif

</APP>

#else

<APP id="VAPP_WIDGET_DELEGATOR_IDLE" 
		name="STR_ID_VAPP_WIDGET_DELEGATOR_IDLE" 
		type="venus" hidden_in_mainmenu="true"> 

</APP>

<APP id="VAPP_WIDGET_DELEGATOR" 
		name="STR_ID_VAPP_WIDGET_DELEGATOR" 
		type="venus" hidden_in_mainmenu="true"> 

</APP>

#endif /* __MMI_GADGET_SUPPORT__ */
