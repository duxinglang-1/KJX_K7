#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifdef __MMI_OP02_LEMEI_FTO__
<APP id = "VAPP_LEMEI" package_name="native.mtk.lemei" 
						name = "STR_ID_VAPP_LEMEI"
						img="IMG_ID_VAPP_LEMEI"
						launch="vapp_lemei_launch" type="venus">

    <!--package app: contact -->
    
    <STRING id="STR_ID_VAPP_LEMEI"/>
    <STRING id="STR_ID_VAPP_LOCAL_AUDIO"/>
    <STRING id="STR_ID_VAPP_LOCAL_PICTURE"/>
    <STRING id="STR_ID_VAPP_LOCAL_VIDEO"/>
    <STRING id="STR_ID_VAPP_FILE_TOO_LARGE"/>
    <STRING id="STR_ID_VAPP_LEMEI_SUBJECT"/>
    <STRING id="STR_ID_VAPP_LEMEI_NOT_READY"/>
    
    #define ROOT_PATH RES_IMG_ROOT"\\\\Lemei\\\\"
    <IMAGE id="IMG_ID_VAPP_LEMEI">  RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\Lemei.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_LEMEI_CAMERA_UP">   ROOT_PATH"LM_TakePho_UP.png" </IMAGE>
    <IMAGE id="IMG_ID_VAPP_LEMEI_CAMERA_DOWN">   ROOT_PATH"LM_TakePho_DN.png" </IMAGE>
    <IMAGE id="IMG_ID_VAPP_LEMEI_VIDEO_RECORDER_UP">   ROOT_PATH"LM_Video_UP.png" </IMAGE>
    <IMAGE id="IMG_ID_VAPP_LEMEI_VIDEO_RECORDER_DOWN">   ROOT_PATH"LM_Video_DN.png" </IMAGE>
    <IMAGE id="IMG_ID_VAPP_LEMEI_AUDIO_RECORDER_UP">   ROOT_PATH"LM_REC_UP.png" </IMAGE>
    <IMAGE id="IMG_ID_VAPP_LEMEI_AUDIO_RECORDER_DOWN">   ROOT_PATH"LM_REC_DN.png" </IMAGE>
    <IMAGE id="IMG_ID_VAPP_LEMEI_BG">   ROOT_PATH"LM_BG.jpg" </IMAGE>
    
    <!--Memory config ------------------------------------------------------------------------------------>
    <MEMORY heap = "750*1024" cui="max(VCUI_GALLERY_IMAGE_PICKER, max(VCUI_GALLERY_VIDEO_PICKER, max(VCUI_CAMCO, max(VCUI_MSGCOMPOSER, VCUI_SOUNDREC))))"/>
</APP>
#endif