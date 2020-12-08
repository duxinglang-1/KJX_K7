<?xml version="1.0" encoding="UTF-8"?>

#include "MMI_features.h" 

<APP id="SRV_IMGEDT">
    
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

<!-- 
**************************************** String section ***************************************
-->

#ifdef __MMI_SRV_IES__
    <STRING id="STR_ID_IES_EFFECT_NEGATIVE"/>
    <STRING id="STR_ID_IES_EFFECT_GRAYSCALE"/>
    <STRING id="STR_ID_IES_EFFECT_MIRROR"/>
    <STRING id="STR_ID_IES_EFFECT_BRIGHTNESS"/>
    <STRING id="STR_ID_IES_EFFECT_CONTRAST"/>
    <STRING id="STR_ID_IES_EFFECT_SEPIA"/>
    <STRING id="STR_ID_IES_EFFECT_SHARPNESS"/>
    <STRING id="STR_ID_IES_EFFECT_OILPAINT"/>
    <STRING id="STR_ID_IES_EFFECT_HUE_SATURATION"/>
    <STRING id="STR_ID_IES_EFFECT_BCSH_ADJUST"/>
    <STRING id="STR_ID_IES_EFFECT_PARAM_BRIGHTNESS"/>
    <STRING id="STR_ID_IES_EFFECT_PARAM_CONTRAST"/>
    <STRING id="STR_ID_IES_EFFECT_PARAM_HUE"/>
    <STRING id="STR_ID_IES_EFFECT_PARAM_SATURATION"/>
    
    <STRING id="STR_ID_IES_ERR_IMAGE_TOO_SMALL"/>
    <STRING id="STR_ID_IES_ERR_IMAGE_TOO_LARGE"/>
    <STRING id="STR_ID_IES_ERR_CANNOT_WRITE_FILE"/>
#endif

</APP>
