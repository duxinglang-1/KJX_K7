#include "mmi_features.h"
#include "custresdef.h"

#if defined(__MMI_VIDEO_CLIPPER__)

<?xml version="1.0" encoding="UTF-8"?>
<APP id="VAPP_VIDEOCLIPPER_SLIDER">
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <!----- THEME ----->
    <THEME>         
    <IMAGE id="IMG_ID_VAPPP_VDOCLIPPER_SLIDER_THUMB_PLAY" desc = "play thumb"/>  
    <IMAGE id="IMG_ID_VAPPP_VDOCLIPPER_SLIDER_HRZT_BG" desc = "slider bar background image"/>
    <IMAGE id="IMG_ID_VAPPP_VDOCLIPPER_SLIDER_PLAY_H" desc = "slider bar play highlight"/>
    </THEME>

    #define ROOT_PATH    RES_IMG_ROOT"\\\\VideoClipper\\\\"
 
    <IMAGE id="IMG_ID_VAPPP_VDOCLIPPER_SLIDER_THUMB_CLIP_START">ROOT_PATH"btn_front.png"</IMAGE> 
    <IMAGE id="IMG_ID_VAPPP_VDOCLIPPER_SLIDER_THUMB_CLIP_END">ROOT_PATH"btn_after.png"</IMAGE> 
    <IMAGE id="IMG_ID_VAPPP_VDOCLIPPER_SLIDER_HRZT_H">ROOT_PATH"clipper_bg.9slice.png"</IMAGE>
  	
</APP>

#endif
