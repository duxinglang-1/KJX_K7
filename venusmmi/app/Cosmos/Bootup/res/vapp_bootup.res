/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VAPP_BOOTUP" name="STR_ID_VAPP_BOOTUP_APP_NAME" type="venus">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#if 0    
    <STRING id="STR_ID_VAPP_BOOTUP_NAND_NOT_SUPPORTED"/>
    <STRING id="STR_ID_VAPP_BOOTUP_USER_DRIVE_CORRUPTED"/>
#endif    
    <STRING id="STR_ID_VAPP_BOOTUP_SYSTEM_DRIVE_CORRUPTED"/>
    <STRING id="STR_ID_VAPP_BOOTUP_NAND_VERSION_MISMATCH"/>
    <STRING id="STR_ID_VAPP_BOOTUP_NAND_QUOTA_OVER_DISK"/>
    <STRING id="STR_ID_VAPP_BOOTUP_NAND_QUOTA_USAGE_WARNING"/>
    <STRING id="STR_ID_VAPP_BOOTUP_EMERGENCY"/>
    <STRING id="STR_ID_VAPP_BOOTUP_INPUT_PHONE_PASSWORD"/>
    <STRING id="STR_ID_VAPP_BOOTUP_WRONG_PHONE_PASSWORD"/>
    <STRING id="STR_ID_VAPP_BOOTUP_REMAINING_TRIALS_PROMPT"/>
    
    <STRING id="STR_ID_VAPP_BOOTUP_INPUT_CHV1"/>
    <STRING id="STR_ID_VAPP_BOOTUP_INPUT_UBCHV1"/>
    <STRING id="STR_ID_VAPP_BOOTUP_NEW_CHV1"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_INPUT_CHV1"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_INPUT_UBCHV1"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_NEW_CHV1"/>
#endif
    <STRING id="STR_ID_VAPP_BOOTUP_WRONG_CHV1"/>
    <STRING id="STR_ID_VAPP_BOOTUP_WRONG_UBCHV1"/>
    <STRING id="STR_ID_VAPP_BOOTUP_CONFIRM_NEW_CHV1"/>
    <STRING id="STR_ID_VAPP_BOOTUP_CHV1_NOT_MATCH"/>
    
    <STRING id="STR_ID_VAPP_BOOTUP_INPUT_NP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_INPUT_NSP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_INPUT_SP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_INPUT_CP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_INPUT_SIMP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_INPUT_NSSP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_INPUT_SIMCP"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_INPUT_NP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_INPUT_NSP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_INPUT_SP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_INPUT_CP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_INPUT_SIMP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_INPUT_NSSP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_INPUT_SIMCP"/>
#endif

    <STRING id="STR_ID_VAPP_BOOTUP_WRONG_NP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_WRONG_NSP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_WRONG_SP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_WRONG_CP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_WRONG_SIMP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_WRONG_NSSP"/>
    <STRING id="STR_ID_VAPP_BOOTUP_WRONG_SIMCP"/>
    
    <STRING id="STR_ID_VAPP_BOOTUP_SIM_REMOVED"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIM_ACCESS_ERROR"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIM_CHV1_BLOCKED"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIM_BLOCKED"/>
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_REMOVED"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_ACCESS_ERROR"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_CHV1_BLOCKED"/>
    <STRING id="STR_ID_VAPP_BOOTUP_SIMX_BLOCKED"/>
#endif
    
#if (MMI_MAX_SIM_NUM >= 2)
    <STRING id="STR_ID_VAPP_BOOTUP_SELECT_SIM"/>
#endif
    <STRING id="STR_ID_VAPP_BOOTUP_WAIT_FOR_SIM"/>
    <STRING id="STR_ID_VAPP_BOOTUP_POWER_OFF"/>
    <STRING id="STR_ID_VAPP_BOOTUP_EMPTY_SIM_SLOT"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_ID_VAPP_BOOTUP_ANIMATION" flag="REPLACEABLE">RES_IMG_ROOT"\\\\BootupShutdown\\\\Animation\\\\POWER_ON_ANI.gif"</IMAGE>

    <MEMORY heap="200000" cui="max(VCUI_PEN_CALIBRATION, VCUI_DIALER_MAKE_CALL)"/>

    <RECEIVER id="EVT_ID_SRV_BOOTUP_START" proc="vapp_bootup_flow_start"/>
    
    <TIMER id="VAPP_BOOTUP_WAITING_EVENT_TIMER"/>
		<TIMER id="VAPP_BOOTUP_DCM_TIMER"/>
</APP>

