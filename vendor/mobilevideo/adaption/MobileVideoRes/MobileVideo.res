/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"

#ifdef __MMI_MOBILE_VIDEO__

#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_MOBILEVIDEO">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    /* CS Main Menu */
    <STRING id="STR_ID_APP_MVAPP">"Mobile Video"</STRING>
    <STRING id="STR_ID_APP_MVAPP_01"/>
    <STRING id="STR_ID_APP_MVAPP_02"/>
    <STRING id="STR_ID_APP_MVAPP_03"/>        

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_LOADING_SCREEN">CUST_IMG_PATH"\\\\MainLCD\\\\MobileVideo\\\\background.png"</IMAGE>
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <!--Menu Tree Area-->
    /* DEVAPP Main Menu*/
    
    
    /* DEVAPP menuitems */
    


    <!------------------------------------------------------Screen ID Resource Area------------------------------------------------->
    <SCREEN id="SCR_ID_APP_MOBILEVIDEO" />
    <SCREEN id="SCR_ID_CATEGORY_EDITOR" />

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
#ifdef __MMI_USB_SUPPORT__
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_mobilevideo_usb_enter_ms_mode_hdlr"/>
#endif /* __MMI_USB_SUPPORT__ */

</APP>

#endif /* __MMI_MOBILE_VIDEO__ */


