#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_SCROLLABLE">
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\Components\\\\Scrollbar\\\\"

#if defined(__COSMOS_MMI__)
    <THEME>
        <IMAGE id="VCP_IMG_SCROLLABLE_INDICATOR" desc="Scrollbar image"/>
        <COLOR id="VCP_CLR_SCROLLABLE_LIGHT" desc="Scrollable boundary light color"/>
    </THEME>
#else
    <IMAGE id="VCP_IMG_SCROLLABLE_INDICATOR">ROOT_PATH"Scrollbar.9slice.png"</IMAGE>
#endif
#ifdef __COSMOS_3D_V10__
    #define ROOT_PATH_SCROLLABLE RES_THEME_ROOT"\\\\default\\\\3D\\\\Components\\\\Scrollable\\\\"

    <IMAGE id="VCP_IMG_SCROLLABLE_BOUNDARY_LIGHT">ROOT_PATH_SCROLLABLE"edge_glow.9slice.png"</IMAGE>    
    <BINARY3D id="VCP_FRG_SCROLLABLE_BOUNDARY_LIGHT" base_path="current">"shader\\\\vcp_scrollable_boundarylight.fs"</BINARY3D>
    <BINARY3D id="VCP_FRG_SCROLLABLE_INDICATOR" base_path="current">"shader\\\\vcp_scrollable_indicator.fs"</BINARY3D>
#endif
</APP>

