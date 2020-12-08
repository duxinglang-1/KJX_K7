#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_TITLE_BAR">
    <!-----------------------------------------------------Theme Resource Area----------------------------------------------------->
    <THEME>
        <IMAGE id="VCP_IMG_TITLEBAR_BACKGROUND_NORMAL" desc="Title bar normal background image"/>
        <IMAGE id="VCP_IMG_TITLEBAR_SHADOW" desc="Title bar shadow Image"/>
    </THEME>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Components\\\\MultimediaCP\\\\TitleBar\\\\"
    <IMAGE id="VCP_IMG_TITLEBAR_BACKGROUND_TRANSLUCENT">ROOT_PATH"TitleBar.9slice.png"</IMAGE>

#ifdef __COSMOS_3D_V10__
    <BINARY3D id="VCP_BINARY_TITLEBAR_EFFECT_FS" base_path="current">"shader\\\\vcp_title_effect_3d.fs"</BINARY3D>

#endif // __COSMOS_3D_V10__

</APP>

