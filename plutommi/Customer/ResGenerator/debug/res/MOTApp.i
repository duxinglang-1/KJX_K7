# 1 "temp/res/MOTApp.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/MOTApp.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 2 "temp/res/MOTApp.c" 2


# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 5 "temp/res/MOTApp.c" 2

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_MOT"
name = "STR_ID_MOT_APP_NAME"
type="pluto"
# 24 "temp/res/MOTApp.c"
>
<INCLUDE file="GlobalResDef.h"/>

<!----------------------------------------------------- Memory Config Area ----------------------------------------------------->
    <MEMORY heap= "0" extra_base="base(SRV_MOT)+ MMI_MOT_APP_CONTEXT_BUF_SIZE" fg="fg(SRV_MOT)" inc="MotGprot.h"/>

<!--------------------------------------String resource area------------------->
    <STRING id="STR_ID_MOT_APP_NAME"/>
    <STRING id="STR_ID_MOT_DURATION"/>
    <STRING id="STR_ID_MOT_UNKNOWN_FILENAME"/>
    <STRING id="STR_ID_MOT_UNKNOWN_CLASS"/>
    <STRING id="STR_ID_MOT_FILENAME"/>
    <STRING id="STR_ID_MOT_MOVIE_NAME"/>
    <STRING id="STR_ID_MOT_STARRING"/>
    <STRING id="STR_ID_MOT_YEAR"/>
    <STRING id="STR_ID_MOT_PLOT"/>
    <STRING id="STR_ID_MOT_CATEGORY"/>

<!--------------------------------------Image resource area------------------->
<IMAGE id="IMG_ID_MOT_APP_ICON" >"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MOT\\\\SB_MOT.bmp"</IMAGE>
<IMAGE id="IMG_ID_MOT_DEFAULT_THUMBNAIL" >"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MOT\\\\MOT_thumbnail_default.png"</IMAGE>





<!--------------------------------------Menu resource area------------------->
    <MENU id="MENU_ID_MOT_APP" type="APP_MAIN" str="STR_ID_MOT_APP_NAME" img="IMG_ID_MOT_APP_ICON" highlight="mmi_mot_highlight_app">
    </MENU>

    <MENUITEM id="MENU_ID_MOT_CATEGORY_LIST_OPEN" str="STR_GLOBAL_OPEN"/>
    <MENUITEM id="MENU_ID_MOT_CATEGORY_LIST_REFRESH" str="STR_GLOBAL_REFRESH"/>
    <MENU id="MENU_ID_MOT_CATEGORY_LIST_OPTIONS" type="OPTION" str="STR_ID_MOT_APP_NAME">
            <MENUITEM_ID>MENU_ID_MOT_CATEGORY_LIST_OPEN</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MOT_CATEGORY_LIST_REFRESH</MENUITEM_ID>
    </MENU>

    <MENUITEM id="MENU_ID_MOT_VIDEO_LIST_PLAY_VIDEO" str="STR_GLOBAL_PLAY"/>
    <MENUITEM id="MENU_ID_MOT_VIDEO_LIST_DETAILS" str="STR_GLOBAL_DETAILS"/>
    <MENU id="MENU_ID_MOT_VIDEO_LIST_OPTIONS" type="OPTION" str="STR_ID_MOT_APP_NAME">
            <MENUITEM_ID>MENU_ID_MOT_VIDEO_LIST_PLAY_VIDEO</MENUITEM_ID>
            <MENUITEM_ID>MENU_ID_MOT_VIDEO_LIST_DETAILS</MENUITEM_ID>
    </MENU>

    <!-------------------------------------------------------------------Screen resource area----------------------------------------------------------->
    <SCREEN id="GRP_ID_MOT"/>
    <SCREEN id="GRP_ID_MOT_VIDEO_CATEGORY"/>
    <SCREEN id="GRP_ID_MOT_VIDEO_DETAILS"/>
    <SCREEN id="SCR_ID_MOT_WAITING_SCREEN"/>
    <SCREEN id="SCR_ID_MOT_VIDEO_CAT_LIST"/>
    <SCREEN id="SCR_ID_MOT_VIDEO_LIST"/>
    <SCREEN id="SCR_ID_MOT_VIDEO_DETAILS"/>

    <!------------------------------------------------------CM Resource---------------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_mot_app_proc"/>
</APP>
