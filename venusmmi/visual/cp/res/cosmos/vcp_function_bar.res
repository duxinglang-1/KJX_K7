#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_FUNCTION_BAR">
#if defined(__MMI_VUI_COSMOS_CP__)
    <THEME>
        <IMAGE id="VCP_IMG_FUNCTION_BAR_BG_IMAGE"/>
        <COLOR id="VCP_COL_FUNC_BAR_BTN_FONT_SPCL" desc="Font color of Special button on fucntion bar"/>
    </THEME>
#else
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\FunctionBar\\\\"
    <IMAGE id="VCP_IMG_FUNCTION_BAR_BG_IMAGE"> ROOT_PATH"FB_BG.9slice.png" </IMAGE>
#endif
</APP>

