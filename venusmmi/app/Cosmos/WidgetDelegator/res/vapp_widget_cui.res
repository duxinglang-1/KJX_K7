/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
#ifdef __GADGET_SUPPORT__
<?xml version="1.0" encoding="UTF-8"?>
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_WIDGET_CUI" name="STR_ID_VAPP_WIDGET_CUI" type="venus" hidden_in_mainmenu="true">
    <MEMORY heap="1024*10"
    			  extra_base="0"
            cui="max(VCUI_SLIM_CAMERA, VCUI_GALLERY_IMAGE_PICKER)"/>
    <APPCONCURRENT concurrent_w_order ="VAPP_WIDGET_ADP, VAPP_WIDGET_CUI"/>
    <APPCONCURRENT concurrent ="VAPP_WIDGET_DELEGATOR, VAPP_WIDGET_CUI"/>
           
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_CUI"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
    <SCREEN id="GRP_ID_WIDGET_CUI"/>
</APP>
#endif /* __GADGET_SUPPORT__ */
