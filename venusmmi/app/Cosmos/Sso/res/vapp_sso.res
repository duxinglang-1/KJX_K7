#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#if defined(__MMI_SSO__)
<APP id="VAPP_SSO" name="STR_ID_SSO_APP" type="venus">
    <MEMORY extra_base="10240+$(SRV_CLOUD_ASM_SIZE)" heap="153600" inc="CloudSrvGprot.h"/>

    <!-- NVRAM related -->
    <CACHEDATA type="byte" id="NVRAM_SSO_WIZARD_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION>Deside to run sso wizard or not</DESCRIPTION>
    </CACHEDATA>
</APP>
#endif

#if defined(__SOCIAL_NETWORK_SUPPORT__) || defined(__MMI_SSO__)
<APP id="VAPP_SNS_SSO_COMMON"
    package_name="native.mtk.sns_sso_common" 
    name="STR_ID_VAPP_SNS_SSO_COMMON"
    hidden_in_mainmenu="true"
    type="venus">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <IMAGE id="IMG_ID_VAPP_SSO_TOOLBAR_RESTORE">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Restore.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SSO_TOOLBAR_SYNCINTERVAL">RES_IMG_ROOT"\\\\Contact\\\\ToolbarIcon\\\\Sync.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SSO_TOOLBAR_BACKUP">RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\Backup.png"</IMAGE>

    <!-- String Resource Area-------------------------------------------------->


    <STRING id="STR_ID_VAPP_ACCOUNTS_SETTINGS"/>
    <STRING id="STR_ID_VAPP_SSO_NO_NETWORK_CONNECTION"/>
    <STRING id="STR_ID_VAPP_SSO_NO_MEMORY_CARD"/>
    <STRING id="STR_ID_VAPP_SSO_NO_APP_DATA_TO_BACKUP"/>
    <STRING id="STR_ID_VAPP_SSO_NO_APP_DATA_TO_RESTORE"/>
	<STRING id="STR_ID_VCUI_SSO_LOGGINGOUT"/>
	<STRING id="STR_ID_VCUI_SSO_LOGIN"/>
	<STRING id="STR_ID_VCUI_SSO_LOGGINGIN"/>
	<STRING id="STR_ID_VCUI_SSO_LOGOUT"/>
	<STRING id="STR_ID_VCUI_SSO_SIGNUP"/>
	<STRING id="STR_ID_VCUI_SSO_ACCOUNT"/>
	<STRING id="STR_ID_VAPP_SSO_FAILED_TO_UPDATED"/>
	<STRING id="STR_ID_VAPP_SSO_UPDATED"/>

    <RECEIVER id="EVT_ID_SRV_SSO_PLUGINS_UPGRADED"     proc="vapp_sso_upgrade_result_handler"/>

</APP>
#endif
