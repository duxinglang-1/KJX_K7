/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

#ifdef __MMI_VPP_UPGRADE__
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_UPGRADE"
    package_name="native.mtk.upgrade" 
    name="STR_ID_VAPP_UPGRADE"
    hidden_in_mainmenu="true"
    type="venus">
    
    <MEMORY heap="5*1024"/>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
    
    <!-- String Resource Area-------------------------------------------------->

    <STRING id="STR_ID_VAPP_UPGRADE"/>
    <STRING id="STR_ID_VAPP_UPGRADE_NEW_UPDATES"/>
    <STRING id="STR_ID_VAPP_UPGRADE_NEW_UPDATE"/>
    <STRING id="STR_ID_VAPP_UPGRADE_TAP_TO_DOWNLOAD"/>
 
    <!-- Image Resource Area--------------------------------------------------->   
    <IMAGE id="IMG_ID_VAPP_UPGRADE_LIST_ICN">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_updated.png"</IMAGE>
    
    <!------------------------------------------------------CallBack Manager---------------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_UPGRADE_DOWNLOAD_REQ"        proc="vapp_upgrade_event_handler"/>    
		
</APP>
#endif /*__MMI_VPP_UPGRADE__ */
