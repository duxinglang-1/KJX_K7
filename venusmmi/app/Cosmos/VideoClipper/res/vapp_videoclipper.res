#include "mmi_features.h"
#include "custresdef.h"

#if defined(__MMI_VIDEO_CLIPPER__)

<?xml version="1.0" encoding="UTF-8"?>
<APP id="VAPP_VIDEOCLIPPER">
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH    RES_IMG_ROOT"\\\\VideoClipper\\\\"
    
    <IMAGE id="IMG_ID_VAPPP_VDOCLIPPER_PLAY_ICON">ROOT_PATH"btn_play.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPPP_VDOCLIPPER_PAUSE_ICON">ROOT_PATH"btn_pause.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPPP_VDOCLIPPER_TRIM_ICON">ROOT_PATH"btn_clipper.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPPP_VDOCLIPPER_HINT_BG">ROOT_PATH"setting_bg.png"</IMAGE> 
    <IMAGE id="IMG_ID_VAPPP_VDOCLIPPER_SLIDER_BG">ROOT_PATH"bottom_bg.9slice.png"</IMAGE>
   	
    <STRING id="STR_ID_VAPP_VDOCLIPPER_SAVE_ORIGINAL"/>
    <STRING id="STR_ID_VAPP_VDOCLIPPER_SAVE_NEW"/>
    <STRING id="STR_ID_VAPP_VDOCLIPPER_SAVE_NEW_TITLE"/>
    
</APP>

#endif
