#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_INFO_BALLOON">
#if defined(__MMI_VUI_COSMOS_CP__)
    <THEME>
	    <IMAGE id="VCP_IMG_INFO_BALLOON_BG" desc="Info Balloon background Image"/>
	    <IMAGE id="VCP_IMG_INFO_BALLOON_BG_LEFT" desc="Info balloon left background image"/>
	    <IMAGE id="VCP_IMG_INFO_BALLOON_BG_CENTER" desc="Info balloon centre background image"/>
	    <IMAGE id="VCP_IMG_INFO_BALLOON_BG_RIGHT" desc="Info balloon right background image"/>
            <IMAGE id="VCP_IMG_INFO_BALLOON_BG_CENTER_LEFT" desc="Info balloon center left background image"/>
            <IMAGE id="VCP_IMG_INFO_BALLOON_BG_CENTER_RIGHT" desc="Info balloon center right background image"/>
	    <IMAGE id="VCP_IMG_INFO_BALLOON_PROGRESS" desc="Info balloon progress image"/>
	    <IMAGE id="VCP_IMG_INFO_BALLOON_FAILURE" desc="Info balloon failure image"/>
	    <IMAGE id="VCP_IMG_INFO_BALLOON_INFO" desc="Info balloon normal image"/>
	    <IMAGE id="VCP_IMG_INFO_BALLOON_WARNING" desc="Info balloon warning image"/>
	    <IMAGE id="VCP_IMG_INFO_BALLOON_SUCCESS" desc="Info balloon success image"/>
	    <COLOR id="CLR_COSMOS_INFO_BALLOON_TXT" desc="Color for the info balloon text"/>
    </THEME>
#else

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Balloon\\\\"
    <IMAGE id="VCP_IMG_INFO_BALLOON_BG"> ROOT_PATH"Balloon_Down.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_INFO_BALLOON_BG_LEFT"> ROOT_PATH"Balloon_L.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_INFO_BALLOON_BG_CENTER"> ROOT_PATH"Balloon_M.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_INFO_BALLOON_BG_RIGHT"> ROOT_PATH"Balloon_R.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_INFO_BALLOON_BG_CENTER_LEFT"> ROOT_PATH"Balloon_ML.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_INFO_BALLOON_BG_CENTER_RIGHT"> ROOT_PATH"Balloon_MR.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_INFO_BALLOON_PROGRESS"> ROOT_PATH"APP_PRO.png" </IMAGE>
    <IMAGE id="VCP_IMG_INFO_BALLOON_FAILURE"> ROOT_PATH"APP_ERR.png" </IMAGE>
    <IMAGE id="VCP_IMG_INFO_BALLOON_INFO"> ROOT_PATH"APP_INF.png" </IMAGE>
    <IMAGE id="VCP_IMG_INFO_BALLOON_WARNING"> ROOT_PATH"APP_WARN.png" </IMAGE>
    <IMAGE id="VCP_IMG_INFO_BALLOON_SUCCESS"> ROOT_PATH"APP_DONE.png" </IMAGE>
#endif
</APP>

