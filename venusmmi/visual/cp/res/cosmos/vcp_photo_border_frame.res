#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_PHOTO_BORDER_FRAME">
#if defined(__MMI_VUI_COSMOS_CP__)
    <!-----------------------------------------------------Theme Resource Area----------------------------------------------------->
    <THEME>
       <IMAGE id="VCP_IMG_PHOTO_BORDER_FRAME_BG"  desc="background image of the frame"/>
       <IMAGE id="VCP_IMG_PHOTO_BORDER_FRAME_FG" desc="Foreground image of the frame, shows as the border (Normal state)"/>
       <IMAGE id="VCP_IMG_PHOTO_BORDER_FRAME_FG_P" desc="Foreground image of the frame, shows as the border (Pressed state)"/>
    </THEME>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
#else
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Photo_Border_BG\\\\"
    <IMAGE id="VCP_IMG_PHOTO_BORDER_FRAME_BG">ROOT_PATH"Default_02.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_PHOTO_BORDER_FRAME_FG">ROOT_PATH"Default_01.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_PHOTO_BORDER_FRAME_FG_P">ROOT_PATH"Default_01_P.9slice.png"</IMAGE>
#endif    
</APP>

