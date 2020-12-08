#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_BASE_PICKER">
#if defined(__MMI_VUI_COSMOS_CP__)
	    <THEME>
	        <IMAGE id="VCP_IMG_BASE_PICKER_BG" desc="Base picker background Image"/>
	        <IMAGE id="VCP_IMG_BASE_PICKER_LEFT_ARROW"  desc="Picker background Image"/>
	        <IMAGE id="VCP_IMG_BASE_PICKER_RIGHT_ARROW" desc="Picker right arrow image"/>
	        <IMAGE id="VCP_IMG_BASE_PICKER_FIELD_BG" desc="picker field background image"/>
	        <IMAGE id="VCP_IMG_BASE_PICKER_SHADOW_DOWN" desc="picker down shadow image"/>
	        <IMAGE id="VCP_IMG_BASE_PICKER_SHADOW_UP" desc="picker up shadow image"/>
	        <COLOR id="CLR_COSMOS_BASE_PICKER_TXT" desc="Item text color"/>
	    		<COLOR id="CLR_COSMOS_BASE_PICKER_FOCUS_TXT" desc="Focus Item text color"/>
	    		<COLOR id="CLR_COSMOS_BASE_PICKER_UNIT_TXT" desc="Unit text color"/>
	    </THEME>
#else
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Picker\\\\"
    <IMAGE id="VCP_IMG_BASE_PICKER_BG"> ROOT_PATH"Picker_BG.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_BASE_PICKER_LEFT_ARROW"> ROOT_PATH"Left.png" </IMAGE>
    <IMAGE id="VCP_IMG_BASE_PICKER_RIGHT_ARROW"> ROOT_PATH"Right.png" </IMAGE>
    <IMAGE id="VCP_IMG_BASE_PICKER_FIELD_BG"> ROOT_PATH"Front_White.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_BASE_PICKER_SHADOW_DOWN"> ROOT_PATH"Shadow_Down.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_BASE_PICKER_SHADOW_UP"> ROOT_PATH"Shadow_Up.9slice.png" </IMAGE>
#endif

</APP>

