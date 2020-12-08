/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "CustResDef.h"
/* Need this line to tell parser that XML start, must after all #include. */
#ifdef __MMI_VUI_HOMESCREEN_SNS__
#ifdef __COSMOS_MMI_PACKAGE__
<?xml version="1.0" encoding="UTF-8"?>
/* APP tag, include your app name defined in MMIDataType.h */
<APP package_name="native.mtk.sns_widget_dummy" id="VAPP_WIDGET_SNS_DUMMY" name="STR_ID_VAPP_WIDGET_DUMMY_APP" type="venus" hidden_in_mainmenu="true">
<MEMORY extra_base="22 * 1024" />
          
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_DUMMY_APP"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
    <SCREEN id="GRP_ID_WIDGET_SNS_DUMMY"/>
</APP>
#endif
#endif
