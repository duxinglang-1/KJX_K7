#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_WALLPAPER_MATRIX">

#if defined(__MMI_VUI_HOMESCREEN_LIVE_WALLPAPER_MATRIX__)
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id = "STR_ID_WALLPAPER_VUI_LIVE_MATRIX"/> 

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>   
    #define MATRIX_BASE     CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Wallpaper\\\\Matrix\\\\"
    #ifndef __VENUS_3D_UI_ENGINE__
    <IMAGE id="VAPP_WALLPAPER_IMG_MATRIX_STRING_LIST">MATRIX_BASE"TheMatrix.jpg"</IMAGE>
    #else
    <IMAGE id="VAPP_WALLPAPER_IMG_MATRIX_STRING_LIST">MATRIX_BASE"TheMatrix.ktx"</IMAGE>
    #endif

    #define COSMOS_WALLPAPER_PATH RES_IMG_ROOT"\\\\Wallpaper\\\\WP_Live\\\\thumbnail\\\\"
    <IMAGE id="IMG_ID_VAPP_WALLPAPER_MATRIX_THUMBNAIL">COSMOS_WALLPAPER_PATH"thumb_matrix.jpg"</IMAGE>

#ifdef __VENUS_3D_UI_ENGINE__
    <BINARY3D id="VAPP_WALLPAPER_MATRIX_VERTEX_SHADER" base_path="current">"matrix.vs"</BINARY3D>
    <BINARY3D id="VAPP_WALLPAPER_MATRIX_FRAGMENT_SHADER" base_path="current">"matrix.fs"</BINARY3D>
#endif

#endif

</APP>


