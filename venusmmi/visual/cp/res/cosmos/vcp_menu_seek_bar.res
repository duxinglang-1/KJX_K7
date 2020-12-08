#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_MENU_SEEK_BAR">
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#if defined(__MMI_VUI_COSMOS_CP__)
    <THEME>
    <IMAGE id="VCP_IMG_MENU_SEEK_BAR_DOT" desc="Menu seek bar dot image"/>
    <IMAGE id="VCP_IMG_MENU_SEEK_BAR_HINT" desc="Menu seek bar Hint Image"/>
    <COLOR id="VCP_CLR_MENU_SEEK_BAR_HINT_TXT" desc="Menu seek bar hint text color"/>
    </THEME>
#else
	#define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\SeekBar\\\\"
	<IMAGE id="VCP_IMG_MENU_SEEK_BAR_DOT">ROOT_PATH"Seekbar_Dot.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_MENU_SEEK_BAR_HINT">ROOT_PATH"Seekbar_Hint.9slice.png"</IMAGE>
#endif

</APP>

