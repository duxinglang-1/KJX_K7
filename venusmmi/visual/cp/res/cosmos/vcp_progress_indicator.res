#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_PROGRESS_INDICATOR">
#if defined(__MMI_VUI_COSMOS_CP__)
	    <THEME>
	        <IMAGE id="VCP_IMG_PROGRESS_INDICATOR_BG"/>
	        <IMAGE id="VCP_IMG_PROGRESS_INDICATOR_FG"/>
	    </THEME>
#else
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Indicator\\\\"
    <IMAGE id="VCP_IMG_PROGRESS_INDICATOR_BG"> ROOT_PATH"Background.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_PROGRESS_INDICATOR_FG"> ROOT_PATH"Foreground.9slice.png" </IMAGE>
#endif
</APP>

