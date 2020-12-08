# 1 "temp/res/rightsmgr.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/rightsmgr.c"

# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 3 "temp/res/rightsmgr.c" 2
# 1 "../customerinc/CustResDef.h" 1
# 191 "../customerinc/CustResDef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/CustResDef.h" 2
# 4 "temp/res/rightsmgr.c" 2
<?xml version = "1.0" encoding = "UTF-8"?>


<APP id="APP_RMGR" name="STR_ID_RMGR">
        <INCLUDE file="GlobalResDef.h"/>
        <INCLUDE file="mmi_rp_app_mainmenu_def.h"/>

                        <!--------------------------------------------------------------------------------------------------------------------->
        <CACHEDATA type="byte" id="NVRAM_RMGR_DB_CHECK" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
        </CACHEDATA>
        <!--String Resource Area-->

        <STRING id="STR_ID_RMGR_LIST_RO"/>
        <STRING id="STR_ID_RMGR_INFO"/>
        <STRING id="STR_ID_RMGR_DB_PROC"/>
        <STRING id="STR_ID_RMGR_SWEEP"/>







        <STRING id="STR_ID_RMGR_SCAN_DISK"/>
        <STRING id="STR_ID_RMGR_SCANNING"/>
        <STRING id="STR_ID_RMGR_SWEEP_REMOVE_RIGHTS"/>
        <STRING id="STR_ID_RMGR_BACKUP_AND_REBOOT"/>
        <STRING id="STR_ID_RMGR_RESTORE_AND_REBOOT"/>





        <STRING id="STR_ID_RMGR_DELETE_QUERY"/>
        <STRING id="STR_ID_RMGR_DELETE_ALL_QUERY"/>
        <STRING id="STR_ID_RMGR_SPACE_CHECK"/>
        <STRING id="STR_ID_RMGR_SPACE_PROMPT"/>
# 107 "temp/res/rightsmgr.c"
        <STRING id="STR_ID_DRM_INVALID_KEY"/>
        <STRING id="STR_ID_DRM_EOF"/>
        <STRING id="STR_ID_DRM_TRUNCATED"/>
        <STRING id="STR_ID_DRM_PROCESS_ERROR"/>
        <STRING id="STR_ID_DRM_DB_LOCKED_BY_APP"/>
        <STRING id="STR_ID_DRM_NO_RIGHT_SPACE"/>
        <STRING id="STR_ID_DRM_PLAY"/>
        <STRING id="STR_ID_DRM_DISPLAY"/>
        <STRING id="STR_ID_DRM_EXECUTE"/>
        <STRING id="STR_ID_DRM_PRINT"/>





        <STRING id="STR_ID_RMGR_DETAIL_RIGHT"/>
        <STRING id="STR_ID_RMGR_DETAIL_PROTECTED"/>
        <STRING id="STR_ID_RMGR_DETAIL_UNPROTECTED"/>
        <STRING id="STR_ID_RMGR_DETAIL_UNLIMITED"/>
        <STRING id="STR_ID_RMGR_DETAIL_COUNT"/>
        <STRING id="STR_ID_RMGR_DETAIL_START"/>
        <STRING id="STR_ID_RMGR_DETAIL_END"/>
        <STRING id="STR_ID_RMGR_SUMMARY"/>
        <STRING id="STR_ID_DRM_INVALID_RO"/>


        <STRING id="STR_ID_RMGR_DETAIL_LEFT_COUNT"/>
        <STRING id="STR_ID_RMGR_DETAIL_LEFT_TIME"/>
        <STRING id="STR_ID_RMGR_DETAIL_LEFT_DAYS"/>
        <STRING id="STR_ID_RMGR_DETAIL_LEFT_HOURS"/>
        <STRING id="STR_ID_RMGR_DETAIL_LEFT_LAST"/>
        <STRING id="STR_ID_RMGR_DETAIL_INSTALLABLE"/>
        <STRING id="STR_ID_RMGR_DETAIL_UNINSTALLABLE"/>
        <STRING id="STR_ID_RMGR_DETAIL_FORWARDABLE"/>
        <STRING id="STR_ID_RMGR_DETAIL_UNFORWARDABLE"/>
        <STRING id="STR_ID_RMGR_DETAIL_PRINTABLE"/>
# 155 "temp/res/rightsmgr.c"
        <STRING id="STR_ID_RMGR_VERSION"/>
        <STRING id="STR_ID_RMGR_TIME"/>
        <STRING id="STR_ID_RMGR_REQ_RIGHTS"/>
        <STRING id="STR_ID_RMGR_REQ_RITS"/>
        <STRING id="STR_ID_RMGR_MORE_RITS"/>
        <STRING id="STR_ID_RMGR_MORE_RITS_QUERY"/>
        <STRING id="STR_ID_RMGR_REQ_RITS_EXPIRE_DETAIL"/>
        <STRING id="STR_ID_RMGR_REQ_RITS_EXTEND_DETAIL"/>
        <STRING id="STR_ID_RMGR_USE_NOW"/>
        <STRING id="STR_ID_RMGR_RO_RECEIVED"/>
        <STRING id="STR_ID_RMGR_ACTIVATE_COMPLETED"/>
        <STRING id="STR_ID_RMGR_PROCESSING"/>
        <STRING id="STR_ID_RMGR_COLON"/>
# 178 "temp/res/rightsmgr.c"
        <IMAGE id="IMG_ID_RMGR_ICON">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\RightsManager\\\\RM_DRMManger.bmp"</IMAGE>
        <IMAGE id="IMG_ID_RMGR_LOCK">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\RightsManager\\\\RM_DRMlock.bmp"</IMAGE>
        <IMAGE id="IMG_ID_RMGR_UNLOCK">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\RightsManager\\\\RM_DRMunlock.bmp"</IMAGE>

                                <!--End Image Resource Area-->
        <!--End Image Resource Area-->
        <!--------------------------------------------------------------------------------------------------------------------->


<!--------------------------------------------------------------------------------------------------------------------->
        <!--Menu Item Area-->
        <!--Menu Item Area-->

        <!--Menu Tree Area-->
        <MENUITEM id="MENU_ID_RMGR_LIST_RO" str="STR_ID_RMGR_LIST_RO" img="0" highlight="mmi_rmgr_highlight_list_ro"/>
        <MENUITEM id="MENU_ID_RMGR_INFO" str="STR_ID_RMGR_INFO" img="0" highlight="mmi_rmgr_highlight_info"/>
# 211 "temp/res/rightsmgr.c"
        <MENU id="MENU_ID_RMGR" type="APP_MAIN" parent="MAIN_MENU_SERVICES_MENUID" str="STR_ID_RMGR" img="IMG_ID_RMGR_ICON" highlight="mmi_rmgr_highlight_main">
                        <MENUITEM_ID>MENU_ID_RMGR_LIST_RO</MENUITEM_ID>
                        <MENUITEM_ID>MENU_ID_RMGR_INFO</MENUITEM_ID>
                        <MENUITEM_ID>MENU_ID_RMGR_WHITE_LIST</MENUITEM_ID>
                        <MENUITEM_ID>MENU_ID_RMGR_TRANS</MENUITEM_ID>
                        <MENUITEM_ID>MENU_ID_RMGR_DB_PROC</MENUITEM_ID>
                        <MENUITEM_ID>MENU_ID_RMGR_CERMGR</MENUITEM_ID>
        </MENU>


        <!--Menu Tree Area-->
        <MENUITEM id="MENU_ID_RMGR_LIST_RO_DETAIL" str="STR_GLOBAL_DETAILS" img="0"/>
        <MENUITEM id="MENU_ID_RMGR_LIST_RO_DELETE" str="STR_GLOBAL_DELETE" img="0"/>
        <MENUITEM id="MENU_ID_RMGR_LIST_RO_DELETEALL" str="STR_GLOBAL_DELETE_ALL" img="0"/>

        <MENU id="MENU_ID_RMGR_RO_OPTIONS" type="APP_OPT" parent="0" str="STR_GLOBAL_OPTIONS" img="0">
                        <MENUITEM_ID>MENU_ID_RMGR_LIST_RO_DETAIL</MENUITEM_ID>
                        <MENUITEM_ID>MENU_ID_RMGR_LIST_RO_DELETE</MENUITEM_ID>
                        <MENUITEM_ID>MENU_ID_RMGR_LIST_RO_DELETEALL</MENUITEM_ID>
        </MENU>

        <!--Menu Tree Area-->
        <MENUITEM id="MENU_ID_RMGR_DB_CHECK" str="STR_ID_RMGR_SPACE_CHECK" img="0" hint="mmi_rmgr_db_hint"/>
        <MENUITEM id="MENU_ID_RMGR_SCAN_DISK" str="STR_ID_RMGR_SCAN_DISK" img="0" hint="mmi_rmgr_hint_scan_disk"/>
        <MENUITEM id="MENU_ID_RMGR_DB_SWEEP" str="STR_ID_RMGR_SWEEP" img="0"/>






        <MENU id="MENU_ID_RMGR_DB_PROC" type="APP_SUB" parent="MENU_ID_RMGR" str="STR_ID_RMGR_DB_PROC" img="0" highlight="mmi_rmgr_highlight_db_proc">
                        <MENUITEM_ID>MENU_ID_RMGR_DB_CHECK</MENUITEM_ID>
                        <MENUITEM_ID>MENU_ID_RMGR_SCAN_DISK</MENUITEM_ID>
                        <MENUITEM_ID>MENU_ID_RMGR_DB_SWEEP</MENUITEM_ID>
                        <MENUITEM_ID>MENU_ID_RMGR_DB_BACKUP</MENUITEM_ID>
                        <MENUITEM_ID>MENU_ID_RMGR_DB_RESTORE</MENUITEM_ID>
        </MENU>

        <!--Menu Item Area-->
        <MENUITEM id="MENU_ID_RMGR_LIST_RO_DETAIL" str="STR_GLOBAL_DETAILS" img="IMG_GLOBAL_L1"/>
        <MENUITEM id="MENU_ID_RMGR_LIST_RO_DELETE" str="STR_GLOBAL_DELETE" img="IMG_GLOBAL_L2"/>

        <!--Menu Tree Area-->
        <MENU id="MENU_ID_RMGR_LIST_RO_ALIAS_OPTION" type="OPTION" parent="0" str="0" img="0">
                <MENUITEM_ID>MENU_ID_RMGR_LIST_RO_DETAIL</MENUITEM_ID>
                <MENUITEM_ID>MENU_ID_RMGR_LIST_RO_DELETE</MENUITEM_ID>
        </MENU>

<RECEIVER id="EVT_ID_SRV_NITZ_UPDATE" proc="mmi_rmgr_nitz_update_cb"/>
<RECIEVER id="EVT_ID_SRV_RMGR_DL_NOTIFY" proc="mmi_rmgr_dlagent_notify_handler"/>

        <!--------------------------------------------------------------------------------------------------------------------->
        <!--Screen ID Area-->
        <!--Screen ID Area-->
  <SCREEN id="SCR_ID_RMGR_MAIN"/>
        <SCREEN id="SCR_ID_RMGR_LIST_RO_MAIN"/>
        <SCREEN id="SCR_ID_RMGR_LIST_RO_OPTION"/>
        <SCREEN id="SCR_ID_RMGR_LIST_RO_DELETE"/>
        <SCREEN id="SCR_ID_RMGR_LIST_RO_DETAIL"/>
        <SCREEN id="SCR_ID_RMGR_WHITE_LIST_MAIN"/>
        <SCREEN id="SCR_ID_RMGR_WHITE_LIST_OPTION"/>
        <SCREEN id="SCR_ID_RMGR_WHITE_LIST_EDIT"/>
        <SCREEN id="SCR_ID_RMGR_WHITE_LIST_EDIT_OPTION"/>
        <SCREEN id="SCR_ID_RMGR_WHITE_LIST_CLEAN"/>
        <SCREEN id="SCR_ID_RMGR_GEN_INFO_MAIN"/>
        <SCREEN id="SCR_ID_RMGR_PROGRESS"/>
        <SCREEN id="SCR_ID_RMGR_DB_PROC"/>
        <SCREEN id="SCR_ID_DRM_AUTH"/>
        <SCREEN id="SCR_ID_DRM_SHOW_PERCENTAGE"/>
        <SCREEN id="SCR_ID_DRM_GET_CONFIRM"/>
        <SCREEN id="SCR_ID_DRM_NOTIFY_INFO"/>
        <SCREEN id="SCR_ID_DRM_PROCESSING_START"/>
        <SCREEN id="SCR_ID_DRM_START_REGISTER_AGENT"/>
        <SCREEN id="SCR_ID_DRM_START_ACQUIRE_RO"/>
        <SCREEN id="SCR_ID_DRM_START_DOMAIN_JOIN"/>
        <SCREEN id="SCR_ID_DRM_START_DOMAIN_LEAVE"/>
        <SCREEN id="SCR_ID_DRM_START_PREVIEW_DOWNLOAD"/>
        <SCREEN id="SCR_ID_DRM_START_SILENT_DOWNLOAD"/>
        <SCREEN id="SCR_ID_DRM_START_TIME_SYNC"/>
        <SCREEN id="SCR_ID_DRM_PROCESSING_END"/>
        <SCREEN id="SCR_ID_RMGR_ACTIVATE_PROCESS"/>
        <SCREEN id="SCR_ID_RMGR_ACTIVATE_CONFIRM"/>
        <SCREEN id="SCR_ID_RMGR_CONFIRM"/>
        <SCREEN id="SCR_ID_RMGR_USE_NOW_CONFIRM"/>

                                <!--End Screen Resource Area-->
        <!--End Screen Resource Area-->

<!--------------------------------------------------------------------------------------------------------------------->
        <!--Timer ID Area-->
    <TIMER id="BOOTUP_POPUP_TIMER"/>

    <TIMER id="RMGR_SCAN_DISK_TIMER"/>

    <!--End Timer ID Area-->
<!--------------------------------------------------------------------------------------------------------------------->

</APP>
