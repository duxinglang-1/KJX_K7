/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#if defined (__MMI_YOUTUBE_SHORTCUT__)
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_YOUTUBE" package_name = "native.mtk.youtube" name = "STR_ID_APP_YOUTUBE" img = "IMG_ID_APP_YOUTUBE" 
    launch = "vapp_YOUTUBE_launch" >
    
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_APP_YOUTUBE"/> 

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
#ifdef __COSMOS_MMI_PACKAGE__
    <THEME>
        <IMAGE id="IMG_ID_APP_YOUTUBE" desc="Main menu opera icon">RES_THEME_ROOT"\\\\Default\\\\Mainmenu_Icon\\\\Youtube.png"</IMAGE>
    </THEME>
#else
    <IMAGE id="IMG_ID_APP_YOUTUBE">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\Youtube.png"</IMAGE>
#endif 
 <!--Menu Tree Area-->
    <MENU id="SERVICES_YOUTUBE_SHORTCUT_MENU_ID" str="STR_ID_APP_YOUTUBE" img="IMG_ID_APP_YOUTUBE" shortcut="ON" shortcut_img="IMG_ID_APP_YOUTUBE" launch="vapp_YOUTUBE_launch">
    </MENU>   
</APP>

#endif /*__MMI_YOUTUBE_SHORTCUT__*/

