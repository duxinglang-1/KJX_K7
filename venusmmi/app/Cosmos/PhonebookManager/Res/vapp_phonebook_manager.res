#include "mmi_features.h"
#ifdef __MMI_MOBILE_SERVICE__

#include "custresdef.h"
<?xml version="1.0" encoding="UTF-8"?>
<APP id="VAPP_PHONEBOOK_MANAGER"
    package_name="native.mtk.phonebookmanager"
	name="STR_ID_VAPP_PBM" 
	launch="vapp_phonebook_manager_launch" 
	img="IMG_ID_VAPP_PHONEBOOK_MANAGER_ICON"
	type="venus">
    <MEMORY base="500*1024 + base(VCUI_DTCNT) + base(VCUI_BT_SELDEV)" heap="500*1024" fg="fg(VCUI_DTCNT)"/>
    <LAYOUT file="vapp_phonebook_manager_layout.xml"/>
    
	<!------------------------------------------String Resource Area------------------------------------------------>
	<STRING id="STR_ID_VAPP_PBM"/>
	<STRING id="STR_ID_VAPP_PBM_INTRO"/>
	<STRING id="STR_ID_VAPP_PBM_FEE"/>
	<STRING id="STR_ID_VAPP_PBM_ENTER"/>
	<STRING id="STR_ID_VAPP_PBM_ORDER"/>
	<STRING id="STR_ID_VAPP_PBM_PB"/>
	<STRING id="STR_ID_VAPP_PBM_CHECK"/>
	<STRING id="STR_ID_VAPP_PBM_SYNC"/>
	<STRING id="STR_ID_VAPP_PBM_PROFILE_ID1"/>
	<STRING id="STR_ID_VAPP_PBM_PROFILE_ID2"/>
	<STRING id="STR_ID_VAPP_PBM_PROFILE_ID3"/>
	<STRING id="STR_ID_VAPP_PBM_SYNC_ACCOUNT"/>
	<STRING id="STR_ID_VAPP_PBM_INVALID_SERVER_INPUT"/>
	<STRING id="STR_ID_VAPP_PBM_SETTING"/>
	<STRING id="STR_ID_VAPP_PBM_EDIT_ACCOUNT"/>

	<STRING id="STR_ID_VAPP_SETTING_VERSION_INFO"/>
    <STRING id="STR_ID_VAPP_SETTING_VERSION_INFO_HW"/>
    <STRING id="STR_ID_VAPP_SETTING_VERSION_INFO_SW"/>
    <STRING id="STR_ID_VAPP_SETTING_VERSION_INFO_TIME"/>

	<!------------------------------------------Image Resource Area------------------------------------------------->
	
	<!------------------------------------------Menu Item Area------------------------------------------------------>
	<IMAGE id="IMG_ID_VAPP_PHONEBOOK_MANAGER_ICON">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\PBManager.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_PBM_ORDER">RES_IMG_ROOT"\\\\MobileService_Icon\\\\PBMorder.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_PBM_PB">RES_IMG_ROOT"\\\\MobileService_Icon\\\\PBMphb.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_PBM_CHECK">RES_IMG_ROOT"\\\\MobileService_Icon\\\\PBMquery.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_PBM_TB_FEE">RES_IMG_ROOT"\\\\MobileService_Icon\\\\PBMfee.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_PBM_TB_ENTER">RES_IMG_ROOT"\\\\MobileService_Icon\\\\PBMenter.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_PBM_VERSION">RES_IMG_ROOT"\\\\MobileService_Icon\\\\PBMversion.png"</IMAGE>

	<!------------------------------------------Menu Tree Area------------------------------------------------------>
	
	<!------------------------------------------Scren Group Area---------------------------------------------------->	

	<!------------------------------------------NVRAM_CACHE_DATA---------------------------------------------------->
	<CACHEDATA type="byte" id="NVRAM_EF_VAPP_PBM_ACTIVE_ACCOUNT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION>nvram Phonebook Manager activate Account</DESCRIPTION>
        <FIELD>
        <OPTION hint="account1">0x00</OPTION>
        <OPTION hint="account2"></OPTION>
        <OPTION hint="account3"></OPTION>
        </FIELD>
    </CACHEDATA>

    
</APP>
#endif
