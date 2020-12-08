#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifdef __GADGET_SUPPORT__
<APP id="VAPP_WGTINST" name="STR_ID_VAPP_WGTINST_WIDGET_INSTALLER" hidden_in_mainmenu="true" type="venus">
    <INCLUDE file="GlobalResDef.h"/>
    <MEMORY base="140000" />

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_VAPP_WGTINST_WIDGET_INSTALLER"/>
    <STRING id="STR_ID_VAPP_WGTINST_CANCELED"/>
    <STRING id="STR_ID_VAPP_WGTINST_WIDGET_IS_CORRUPTED"/>
    <STRING id="STR_ID_VAPP_WGTINST_WIDGET_IS_NOT_VALID"/>
    <STRING id="STR_ID_VAPP_WGTINST_STOP_INSTALLATION"/>
    <STRING id="STR_ID_VAPP_WGTINST_VERSION"/>
    <STRING id="STR_ID_VAPP_WGTINST_QUERY_FOR_INSTALL"/>
    <STRING id="STR_ID_VAPP_WGTINST_INSTALLING"/>    
    <STRING id="STR_ID_VAPP_WGTINST_INSTALLED"/>
    <STRING id="STR_ID_VAPP_WGTINST_VERSION_FOUND"/>
    <STRING id="STR_ID_VAPP_WGTINST_CURRENT_VERSION"/>
    <STRING id="STR_ID_VAPP_WGTINST_NEW_VERSION"/>
    <STRING id="STR_ID_VAPP_WGTINST_OLD_VERSION"/>
    <STRING id="STR_ID_VAPP_WGTINST_ALREADY_INSTALLED"/>
    <STRING id="STR_ID_VAPP_WGTINST_REPLACE_WIDGET"/>
    <STRING id="STR_ID_VAPP_WGTINST_OVER_MAX_INSTALL"/>
    <STRING id="STR_ID_VAPP_WGTINST_CONTINUE_INSTALL"/>
    <STRING id="STR_ID_VAPP_WGTINST_WGT_NAME"/>
    <STRING id="STR_ID_VAPP_WGTINST_WGT_AUTHOR"/>
    <STRING id="STR_ID_VAPP_WGTINST_WGT_COPYRIGHT"/>
    <STRING id="STR_ID_VAPP_WGTINST_DISK_SPACE_IS_NOT_ENOUGH"/>
    <STRING id="STR_ID_VAPP_WGTINST_INSTALLING_WIDGET"/>
 
    <IMAGE id="IMG_ID_FMGR_ICON_FILE_TYPE_WGT">RES_IMG_ROOT"\\\\FMGR\\\\ListIcon\\\\Widget.png"</IMAGE>

    <MENUITEM id="MENU_ID_VAPP_WGT_INSTALL" str="STR_GLOBAL_INSTALL"/>

    <MENU id="MENU_ID_VAPP_WGT_TYPE_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_VAPP_WGT_INSTALL</MENUITEM_ID>
    </MENU>

</APP>

<FILE_TYPES>
    <FILE_TYPE_INC file="mmi_rp_vapp_wgtinst_def.h"/>
    <FILE_TYPE type_id="FMGR_TYPE_WGT"
               extension="WGT"
               large_icon="IMG_ID_FMGR_ICON_FILE_TYPE_WGT"
               small_icon="IMG_ID_FMGR_ICON_FILE_TYPE_WGT"
               option="MENU_ID_VAPP_WGT_TYPE_OPTIONS">
    </FILE_TYPE>

    <FILE_OPTION_HDLR option="MENU_ID_VAPP_WGT_INSTALL" handler="vapp_widget_installer_install_wgt"/>
</FILE_TYPES>
#endif /* __GADGET_SUPPORT__ */
