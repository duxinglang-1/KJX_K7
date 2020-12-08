#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifdef __MMI_CBM_CONNECTION_MANAGER__

<APP id="VAPP_CNMGR" package_name="native.mtk.cnmgr" name="STR_ID_VAPP_CNMGR" img="IMG_ID_VAPP_CNMGR" launch="vapp_cnmgr_launch" type="venus">

   <MEMORY heap="1024*200" />

    <THEME>
        <IMAGE id="IMG_ID_VAPP_CNMGR" desc="Main menu connection manager icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\CNMGR.png"</IMAGE>
    </THEME>
    <STRING id = "STR_ID_VAPP_CNMGR"/>
</APP>

#endif /* MMI_CBM_CONNECTION_MANAGER */