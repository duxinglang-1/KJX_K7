#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_ACTIVITY_INDICATOR">
#if defined(__MMI_VUI_COSMOS_CP__)
	    <THEME>
	        <IMAGE id="VCP_IMG_ACTIVITY_INDICATOR_WAITING_BALL_LARGE"/>    
	        <IMAGE id="VCP_IMG_ACTIVITY_INDICATOR_WAITING_BALL_MEDIUM"/>    
	        <IMAGE id="VCP_IMG_ACTIVITY_INDICATOR_WAITING_BALL_SMALL"/>   
	        
	    </THEME>
#else
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\WaitingIcon\\\\"
    <IMAGE id="VCP_IMG_ACTIVITY_INDICATOR_WAITING_BALL_LARGE"> ROOT_PATH"Waiting_Large.png" </IMAGE>    
    <IMAGE id="VCP_IMG_ACTIVITY_INDICATOR_WAITING_BALL_MEDIUM"> ROOT_PATH"Waiting_Middle.png" </IMAGE>    
    <IMAGE id="VCP_IMG_ACTIVITY_INDICATOR_WAITING_BALL_SMALL"> ROOT_PATH"Waiting_Small.png" </IMAGE>   
#endif
</APP>

