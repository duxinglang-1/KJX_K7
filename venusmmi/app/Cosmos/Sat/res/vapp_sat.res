#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SAT" package_name="native.mtk.sat" name="STR_ID_VAPP_SAT" img="IMG_ID_VAPP_SAT" launch="vapp_sat_user_launch" type="venus">
    <MEMORY heap="500*1024" fg="10*1024" cui="VCUI_LANGUAGE_SETTING"/>

    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_ID_VAPP_SAT"/>
    <STRING id="STR_ID_VAPP_SAT_CALL"/>
    <STRING id="STR_ID_VAPP_SAT_LAUNCH"/>
    <STRING id="STR_ID_VAPP_SAT_TERMINATE"/>
    <STRING id="STR_ID_VAPP_SAT_NO_SERVICES"/>
    <STRING id="STR_ID_VAPP_SAT_SIM_REFRESH"/>
    <STRING id="STR_ID_VAPP_SAT_SIM_RESET"/>
    <STRING id="STR_ID_VAPP_SAT_LANGUAGE_RESET"/>
    <STRING id="STR_ID_VAPP_SAT_GET_INPUT_LENGTH_NOT_ENOUGH"/>
    <STRING id="STR_ID_VAPP_SAT_SIM1"/>
    <STRING id="STR_ID_VAPP_SAT_SIM2"/>
    <STRING id="STR_ID_VAPP_SAT_SIM3"/>
    <STRING id="STR_ID_VAPP_SAT_SIM4"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define SAT_ROOT_PATH 			 RES_IMG_ROOT"\\\\SAT\\\\"

    <THEME>
        <IMAGE id="IMG_ID_VAPP_SAT" desc="Main menu SIM tool kit icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\SAT.png"</IMAGE>
    </THEME>

    <IMAGE id="IMG_ID_VAPP_SAT_PREVIEW">RES_IMG_ROOT"\\\\StatusIcon\\\\Sat.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_SAT_SIM1">SAT_ROOT_PATH"\\\\TabIcon\\\\Sim1.png"</IMAGE>

#if (MMI_MAX_SIM_NUM >= 2)
    <IMAGE id="IMG_ID_VAPP_SAT_SIM2">SAT_ROOT_PATH"\\\\TabIcon\\\\Sim2.png"</IMAGE>

#if (MMI_MAX_SIM_NUM >= 3)
    <IMAGE id="IMG_ID_VAPP_SAT_SIM3">SAT_ROOT_PATH"\\\\TabIcon\\\\Sim3.png"</IMAGE>
    
#if (MMI_MAX_SIM_NUM >= 4)
    <IMAGE id="IMG_ID_VAPP_SAT_SIM4">SAT_ROOT_PATH"\\\\TabIcon\\\\Sim4.png"</IMAGE>

#endif
#endif
#endif /* MMI_MAX_SIM_NUM >= 2 */
#ifndef __SAT_DISABLE_ICON_SUPPORT__
    <IMAGE id="IMG_ID_VAPP_SAT_HELP">SAT_ROOT_PATH"\\\\ListIcon\\\\Help.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_VAPP_SAT_HELP2">SAT_ROOT_PATH"\\\\ToolbarIcon\\\\Help.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SAT_LAUNCH">SAT_ROOT_PATH"\\\\ToolbarIcon\\\\LaunchBrowser.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SAT_TERMINATE">SAT_ROOT_PATH"\\\\ToolbarIcon\\\\Terminate.png"</IMAGE>

    <IMAGE id="IMG_ID_VAPP_SAT_CALL">RES_IMG_ROOT"\\\\Message\\\\ToolBarIcon\\\\Call.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SAT_OK">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Ok.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SAT_CANCEL">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Cancel.png"</IMAGE>

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

    <RECEIVER id="EVT_ID_SRV_SAT_PROACTIVE_SIM" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SETUP_MENU" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SIM_REFRESH" proc="mmi_sat_recv_ind"/>
    <RECEIVER id="EVT_ID_SRV_SAT_SESSION_END" proc="mmi_sat_recv_ind"/>

    <RECEIVER id="EVT_ID_VAPP_LAUNCHER_ACTIVE" proc="mmi_sat_recv_idle_ind"/>

#if defined(__SIM_HOT_SWAP_SUPPORT__) || defined(__SIM_RECOVERY_ENHANCEMENT__)
    <RECEIVER id="EVT_ID_SRV_SIM_CTRL_AVAILABILITY_CHANGED" proc="mmi_sat_sim_change_ind"/>
#endif //__SIM_RECOVERY_ENHANCEMENT__ || __SIM_HOT_SWAP_SUPPORT__
		<RECEIVER id="EVT_ID_SRV_SAT_SETUP_IDLE_DISPLAY" proc="vapp_sat_onRecvIdleTextInd"/>
		<RECEIVER id="EVT_ID_SRV_MODE_SWITCH_FINISH_NOTIFY" proc="mmi_sat_mode_switch_ind"/>
</APP>
