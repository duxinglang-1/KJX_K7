#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_OOM_SCR">

    <!-----------------------------------------------------Theme Resource Area----------------------------------------------------->

    <THEME>
        <IMAGE id="IMG_ID_VAPP_OOMSCR_HINT_BG" desc="OOM Screen Hint background"/>
    </THEME>

  	<!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_APP_OOMSCR_LIST_TITLE"/>
    <STRING id="STR_ID_APP_OOMSCR_CONFIRM_EXIT_NORMAL_TEXT"/>
    <STRING id="STR_ID_APP_OOMSCR_CONFIRM_EXIT_2_JAVA_TEXT"/>
    <STRING id="STR_ID_APP_OOMSCR_CONFIRM_EXIT_MOER_JAVA_TEXT"/>
    <STRING id="STR_ID_APP_OOMSCR_EXIT"/>
    <STRING id="STR_ID_APP_OOMSCR_EXITING"/>
    <STRING id="STR_ID_APP_OOMSCR_MEMORY_ENOUGH_AND_RUN"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_THEME_ROOT"\\\\Default\\\\Common\\\\Button\\\\"
    <IMAGE id="IMG_ID_VAPP_OOMSCR_CLOSE_ICON">ROOT_PATH"Delete.png"</IMAGE>

	<RECEIVER id="EVT_ID_APP_TERMINATED" proc="vadp_p2v_vapp_oom_event_handler"/>

</APP>
