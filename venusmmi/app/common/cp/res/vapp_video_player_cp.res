#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="VAPP_VIDEO_PLAYER_CP">
#if defined(__MMI_VUI_HOMESCREEN_VIDEO_WALLPAPER__) || defined(__COSMOS_MMI_PACKAGE__)
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
#ifdef __COSMOS_MMI_PACKAGE__
    #define GAL_VIDEO_PLAYER_PATH   RES_IMG_ROOT"\\\\Gallery\\\\VideoPlayer\\\\"
    <IMAGE id="IMG_ID_VAPP_GALLERY_VID_ICON_AUDIO_ONLY">GAL_VIDEO_PLAYER_PATH"icon_default.png"</IMAGE>
#endif 

    <!-----------------------------------------------------String Resource Area------------------------------------------------------>   
    <STRING id="STR_ID_VAPP_VIDEOCP_ONLY_SUPPORT_3D_MODE">"Only support 3D mode"</STRING>
    <STRING id="STR_ID_VAPP_VIDEOCP_VIDEO_DOWNLOAD_STOPPED">"Video download stopped"</STRING>
#endif

</APP>


