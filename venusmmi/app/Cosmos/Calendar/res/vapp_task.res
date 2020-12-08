
#include "mmi_features.h"
#include "custresdef.h"

<?xml version = "1.0" encoding = "UTF-8"?>
#ifdef __MMI_CAL_SLIM__

<APP id="VAPP_TASK"></APP>
#else

<APP id="VAPP_TASK" package_name="native.mtk.task" name="STR_ID_VAPP_TASK" img="IMG_ID_VAPP_TASK" launch="vapp_task_launch" type="venus">

    <MEMORY heap="400*1024"  cui="VCUI_BT_SEND_PREPARE" vrt_mem_factor = "2.0"/>
    
    <STRING id="STR_ID_VAPP_TASK"/>

    <THEME>
        <IMAGE id="IMG_ID_VAPP_TASK" desc="Main menu task icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Tasks.png"</IMAGE>
    </THEME>

</APP>
#endif


