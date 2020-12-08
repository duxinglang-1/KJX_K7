# 1 "temp/res/CCA.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/CCA.c"
# 125 "temp/res/CCA.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 126 "temp/res/CCA.c" 2






# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 133 "temp/res/CCA.c" 2

<?xml version = "1.0" encoding="UTF-8"?>

<APP id = "APP_CCA">

<!----------------- Include Area ---------------------------------------------->

    <INCLUDE file = "MMI_features.h"/>
    <INCLUDE file = "MMIDataType.h"/>
    <INCLUDE file = "GlobalResDef.h"/>


<!----------------- Common Area ----------------------------------------------->

<!----------------- String Id ----------------------------------------->
    <STRING id= "STR_ID_CCA_SETTINGS_MESSAGE"/>
    <STRING id = "STR_ID_CCA_PROGRESS_CONTENT">Configuring system, please wait</STRING>
    <STRING id = "STR_ID_CCA_PREINFO_CONTENT">Settings for:</STRING>
    <STRING id = "STR_ID_CCA_POSTINFO_TITLE">Summary report</STRING>
    <STRING id = "STR_ID_CCA_AUTH_CONTENT">Please input PIN</STRING>

    <STRING id = "STR_ID_CCA_CONFIGURED">Configured</STRING>
    <STRING id = "STR_ID_CCA_INVALID_SETTING">Invalid settings</STRING>
    <STRING id = "STR_ID_CCA_SETTING_SKIPPED">Skipped</STRING>
    <STRING id = "STR_ID_CCA_CORRUPTED_SETTING">Corrupted settings</STRING>
    <STRING id = "STR_ID_CCA_MISSING_DATA">Incomplete settings</STRING>

    <STRING id = "STR_ID_CCA_INSTALL_SETTING">Install settings</STRING>
    <STRING id = "STR_ID_CCA_REPLACE_SETTING">Replace settings</STRING>
    <STRING id = "STR_ID_CCA_SKIP_PROFILE">Skip this profile?</STRING>
    <STRING id = "STR_ID_CCA_PROFILE_IN_USE">Profile in use</STRING>
    <STRING id = "STR_ID_CCA_SKIP">Skip</STRING>
    <STRING id = "STR_ID_CCA_ABORT_ASK">Cancel?</STRING>





    <STRING id = "STR_ID_CCA_UPDATED">Updated</STRING>
    <STRING id = "STR_ID_CCA_FAILED">Failed</STRING>


    <STRING id = "STR_ID_CCA_PROFILE">Profile</STRING>
    <STRING id = "STR_ID_CCA_NEW_SETTING">New settings</STRING>
    <STRING id = "STR_ID_CCA_SETTING_INFO">Settings info</STRING>

    <STRING id = "STR_ID_CCA_PIN_RETRY">Incorrect PIN, please try again</STRING>
    <STRING id = "STR_ID_CCA_PIN_EMPTY">Please input PIN</STRING>

    <STRING id = "STR_ID_CCA_DATA_ACCOUNT_WITH_COLON">Data account:</STRING>
# 199 "temp/res/CCA.c"
    <STRING id = "STR_ID_CCA_MMS">MMS</STRING>
    <STRING id = "STR_ID_CCA_MMS_WITH_COLON">MMS:</STRING>
# 239 "temp/res/CCA.c"
    <STRING id = "STR_ID_CCA_NOAPP">Unsupported settings</STRING>
    <STRING id = "STR_ID_CCA_AUTH_FAILED">Authentication failed</STRING>
# 259 "temp/res/CCA.c"
    <STRING id = "STR_ID_CCA_INSTALLING_RETRY">Installing</STRING>

<!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_CCA_PRE_INFO"/>
    <SCREEN id = "SCR_ID_CCA_PROGRESS"/>
    <SCREEN id = "SCR_ID_CCA_POST_INFO"/>
    <SCREEN id = "SCR_ID_CCA_NEW_SETTING_CONF"/>
    <SCREEN id = "SCR_ID_CCA_AUTH"/>
    <SCREEN id = "GRP_ID_CCA"/>


<!----------------- Image Id ------------------------------------------->

    <IMAGE id = "IMG_ID_CCA_MAIN_ICON"> "..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\TitleBar\\\\TB_CCA.png"</IMAGE>
# 300 "temp/res/CCA.c"
                <IMAGE id = "IMG_ID_CCA_NEW_SETTING_IDLE">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\SMS\\\\Receiving\\\\SS_IdleMSG.GIF"</IMAGE>






<TIMER id = "TIMER_ID_CCA_NMGR_POPUP"/>

<!----------------- XML END --------------------------------------------------->


</APP>
