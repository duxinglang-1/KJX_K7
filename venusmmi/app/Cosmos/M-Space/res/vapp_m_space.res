#include "mmi_features.h"
#include "custresdef.h"
#include "vfx_config.h"

<?xml version = "1.0" encoding = "UTF-8"?>

<APP id = "VAPP_M_SPACE" 
        name="STR_ID_VAPP_M_SPACE_NAME"
#ifdef __MMI_MRE_MSPACE__
        package_name="native.mtk.m_space"         
        img="IMG_ID_VAPP_M_SPACE_MAIN_MENU_ICON" 
        launch="vapp_m_space_launch"
#endif
     type="venus">
    <MEMORY heap="400*1024" cui = "VCUI_DIALER_MAKE_CALL" fg="500*1024" vrt_mem_factor="2.0"/> 

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id ="STR_ID_VAPP_M_SPACE_NAME"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_TITLE"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_INSTALL"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_UPDATE"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_UPDATING"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_CONNECT_SERVER_FAILED"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_NO_APP"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_RETRY"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_DOWNLOADING"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_DOWNLOAD_SUCCESS"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_DOWNLOAD_FAIL"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_INSTALLING"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_INSTALL_SUCCESS"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_INSTALL_FAIL"/>
    <STRING id ="STR_ID_VAPP_M_SPACE_MEMORY_LIMITATION"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <THEME>
        <IMAGE id="IMG_ID_VAPP_M_SPACE_MAIN_MENU_ICON" desc="Main menu m space icon">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\M_Space.png"</IMAGE>
    </THEME>
    <IMAGE id="IMG_ID_VAPP_M_SPACE_APP_DEFAULT_ICON">RES_IMG_ROOT"\\\\MSpace\\\\MRE.png"</IMAGE>    
    <IMAGE id="IMG_ID_VAPP_M_SPACE_APP_STATUS_DEFAULT_ICON">RES_IMG_ROOT"\\\\MSpace\\\\Default.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_M_SPACE_APP_STATUS_INSTALLED_ICON">RES_IMG_ROOT"\\\\MSpace\\\\Installed.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_M_SPACE_APP_STATUS_UPDATE_ICON">RES_IMG_ROOT"\\\\MSpace\\\\Update.png"</IMAGE>
#if defined(__COSMOS_MMI_PACKAGE__) && defined(__MMI_MRE_MSPACE__)
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="vapp_m_space_handle_event"/>
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="vapp_m_space_handle_event"/>
    <RECEIVER id="EVT_ID_SRV_APPMGR_INSTALL_PACKAGE" proc="vapp_m_space_handle_event"/>
    <RECEIVER id="EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE" proc="vapp_m_space_handle_event"/>
#endif    
</APP>
