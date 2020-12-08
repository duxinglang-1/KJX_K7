/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
#ifdef __GADGET_SUPPORT__
#include "custom_gadget_cfg.h"

<?xml version="1.0" encoding="UTF-8"?>
/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_WIDGET_ADP" name="STR_ID_VAPP_WIDGET_ADP" type="venus" hidden_in_mainmenu="true">
#ifdef __MMI_USE_MMV2__
#ifdef GADGET_HEAP_SOURCE_GLOBLE
    <MEMORY heap="$(GADGET_CUSTOM_CFG_ASM_MEM_SIZE)"
            heap_shrink="$(GADGET_CUSTOM_CFG_ASM_SHRINK_MEM_SIZE)" 
            heap_source="global"
            inc="custom_gadget_config.h"/>
#else  /*GADGET_HEAP_SOURCE_GLOBLE*/
    <MEMORY heap="$(GADGET_CUSTOM_CFG_ASM_MEM_SIZE)"
            heap_shrink="$(GADGET_CUSTOM_CFG_ASM_SHRINK_MEM_SIZE)" 
            inc="custom_gadget_config.h"/>
#endif /*GADGET_HEAP_SOURCE_GLOBLE*/
#else  /* __MMI_USE_MMV2__*/
    <MEMORY extra_base="$(GADGET_CUSTOM_CFG_ASM_MEM_SIZE)" 
            inc="custom_gadget_config.h"/>
#endif /* __MMI_USE_MMV2__*/

    <APPCONCURRENT concurrent_w_order ="VAPP_WIDGET_ADP, VAPP_WIDGET_DELEGATOR"/>
           
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_VAPP_WIDGET_ADP"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->    
    <SCREEN id="GRP_ID_WIDGET_ADP"/>
</APP>
#endif /* __GADGET_SUPPORT__ */
