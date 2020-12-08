/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "vfx_config.h"
#include "MMIDataType.h"

#ifdef __MMI_RESOURCE_ENFB_SUPPORT__
    extern int disableENFB;
#endif

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_VENUS_COMPONENT_SOFTKEY">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#if defined(__MMI_VUI_ENGINE__)
    <IMAGE id = "VCP_IMG_SOFTKEY_LSK_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VCP\\\\lskdown.png"</IMAGE>;
    <IMAGE id = "VCP_IMG_SOFTKEY_LSK_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VCP\\\\lskup.png"</IMAGE>;
    <IMAGE id = "VCP_IMG_SOFTKEY_RSK_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VCP\\\\rskdown.png"</IMAGE>;
    <IMAGE id = "VCP_IMG_SOFTKEY_RSK_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VCP\\\\rskup.png"</IMAGE>;
#endif 

</APP>

