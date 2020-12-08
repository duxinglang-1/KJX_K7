#include "mmi_features.h"

#include "CustResDef.h"
<?xml version="1.0" encoding="UTF-8"?>


<APP id="VAPP_FONTMGR" name="STR_ID_VAPP_FONT_MGR_MAINMENU" type="venus">

    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,mmi_rp_file_type_def.h"/>

	<MEMORY heap="100*1024" cui="max(VCUI_FMGR)"/>

    #if defined(__MMI_FE_VECTOR_FONT_ON_FILE_SYSTEM__)
    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="IMG_ID_VAPP_VECTOR_FONT_FILE_TYPE_IMAGE">RES_IMG_ROOT"\\\\FMGR\\\\ListIcon\\\\TTF.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_VECTOR_FONT_FILE_TYPE_ICON">RES_IMG_ROOT"\\\\FMGR\\\\ListIcon\\\\TTF.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_VECTOR_FONT_SETTING_IMAGE">RES_IMG_ROOT"\\\\Settings\\\\FontSetting.png"</IMAGE>
    
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    <MENUITEM id="MENU_FMGR_VECTOR_FONT_OPTION_INSTALL" str="STR_GLOBAL_INSTALL"/>
    <MENU id="MENU_ID_FMGR_VECTOR_FONT_TYPE_OPTIONS" type="OPTION">
        <MENUITEM_ID>MENU_FMGR_VECTOR_FONT_OPTION_INSTALL</MENUITEM_ID>
    </MENU>
    
    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <FILE_TYPES>
    <FILE_GROUP_TYPE type_id="FMGR_TYPE_GRP_VECTOR_FONT"
        small_icon="IMG_ID_VAPP_VECTOR_FONT_FILE_TYPE_ICON"
        option="MENU_ID_FMGR_VECTOR_FONT_TYPE_OPTIONS"
        >
    <FILE_OPTION_HDLR option="MENU_FMGR_VECTOR_FONT_OPTION_INSTALL" handler="vapp_font_mgr_install_handler"/>
    <FILE_TYPE type_id="FMGR_TYPE_TTF" extension="TTF" large_icon="IMG_ID_VAPP_VECTOR_FONT_FILE_TYPE_IMAGE"/>
    <FILE_TYPE type_id="FMGR_TYPE_CCC" extension="CCC" large_icon="IMG_ID_VAPP_VECTOR_FONT_FILE_TYPE_IMAGE"/>
    <FILE_TYPE type_id="FMGR_TYPE_STF" extension="STF" large_icon="IMG_ID_VAPP_VECTOR_FONT_FILE_TYPE_IMAGE"/>
    </FILE_GROUP_TYPE>
    </FILE_TYPES>


	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="vapp_font_mgr_fmgr_notify_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_SOFT_MOUNT" proc="vapp_font_mgr_fmgr_notify_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="vapp_font_mgr_fmgr_notify_hdlr"/>

	<RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="vapp_font_mgr_usb_ms_plug_in_hdlr"/>
	
	<EVENT id="EVT_ID_VAPP_FONT_CHANGED" type="SENDER"/>
	
    #endif

</APP>

