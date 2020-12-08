#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
#ifdef __COSMOS_3D_V10__
<APP id="SRV_VENUS_COMPONENT_FRAME_EFFECT">
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#if defined(__MMI_VUI_COSMOS_CP__)
    <THEME>
    </THEME>
#else
	            
#endif
	<BINARY3D id="VCP_FRG_FRAME_EFFECT_BLING_H" base_path="current">"shader\\\\vcp_frame_effect_bling_h.fs"</BINARY3D>
      <BINARY3D id="VCP_FRG_FRAME_EFFECT_BLING_V" base_path="current">"shader\\\\vcp_frame_effect_bling_v.fs"</BINARY3D>
      <BINARY3D id="VCP_FRG_FRAME_EFFECT_BLUR_H" base_path="current">"shader\\\\vcp_frame_effect_blur_h.fs"</BINARY3D>
      <BINARY3D id="VCP_FRG_FRAME_EFFECT_BLUR_V" base_path="current">"shader\\\\vcp_frame_effect_blur_v.fs"</BINARY3D>
      
      #define ROOT_PATH_POPUP RES_THEME_ROOT"\\\\default\\\\3D\\\\Components\\\\Bling\\\\"
 	<IMAGE id="VCP_IMG_FRAME_EFFECT_BLING">ROOT_PATH_POPUP"bling.9slice.png"</IMAGE>

	<!--------------  3D Circle ------------------>
	<BINARY3D id="VCP_VTX_FRAME_EFFECT_3D_CIRCLE" base_path="current">"shader\\\\vcp_frame_effect_3D_Circle.vs"</BINARY3D>
	<BINARY3D id="VCP_FRG_FRAME_EFFECT_3D_CIRCLE" base_path="current">"shader\\\\vcp_frame_effect_3D_Circle.fs"</BINARY3D>
</APP>
#endif

