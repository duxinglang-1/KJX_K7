#include "CustomCfg.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "custresdef.h"

#if defined(__MMI_3D_GAME_INTERGRAFX__) && defined(__COSMOS_MMI_PACKAGE__)

<?xml version="1.0" encoding="UTF-8"?>
    
<APP id="VAPP_3DGAME"  
    package_name="native.mtk.3dgame" 
    name="STR_ID_3D_GAME_INTERGRAFX" 
    img = "IMG_ID_3D_GAME_INTERGRAFX" 
    launch = "vapp_3d_game_launch" 
    type="venus">

#if defined(__VENUS_3D_UI_ENGINE__)
    #if defined(__MMI_MAINLCD_480X800__)
        <MEMORY base="max(17*1024*1024, total(SRV_MDI_VDOPLY))" />
    #else    
        <MEMORY base="max(15*1024*1024, total(SRV_MDI_VDOPLY))" />
    #endif
#elif defined(__MMI_3D_GAME_INTERGRAFX_NO_CG__)
    #if defined(__MMI_MAINLCD_480X800__)
        <MEMORY fg="8*1024*1024" />
    #else    
        <MEMORY fg="6*1024*1024" />
    #endif
#else
    #if defined(__MMI_MAINLCD_480X800__)
        <MEMORY fg="8*1024*1024 + total(SRV_MDI_VDOPLY)" />
    #else    
        <MEMORY fg="6*1024*1024 + total(SRV_MDI_VDOPLY)" />
    #endif
#endif



    <!----------------------------------------------------- string resource ---------------------------------------------------------->
    <STRING id="STR_ID_3D_GAME_INTERGRAFX"/>

    <!--Screen ID Area-->
    <SCREEN id="SCR_ID_IG_MAIN"/>

    
    <!----------------------------------------------------- Image resource ---------------------------------------------------------->
    <IMAGE id="IMG_ID_3D_GAME_INTERGRAFX">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\PhotoEditor.png"</IMAGE>

</APP>

#endif
