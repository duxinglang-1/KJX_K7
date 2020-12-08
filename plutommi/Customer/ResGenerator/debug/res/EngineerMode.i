# 1 "temp/res/EngineerMode.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/EngineerMode.c"
# 948 "temp/res/EngineerMode.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 949 "temp/res/EngineerMode.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 950 "temp/res/EngineerMode.c" 2
# 1 "../../../interface/hal/drv_sw_def/drv_sw_features_color.h" 1
# 74 "../../../interface/hal/drv_sw_def/drv_sw_features_color.h"
# 1 "../../../hal/drv_def/drv_features_color.h" 1
# 74 "../../../hal/drv_def/drv_features_color.h"
# 1 "../../../hal/drv_def/drv_features_chip_select.h" 1
# 161 "../../../hal/drv_def/drv_features_chip_select.h"
# 1 "../../../hal/drv_def/drv_features_6260.h" 1
# 162 "../../../hal/drv_def/drv_features_chip_select.h" 2
# 75 "../../../hal/drv_def/drv_features_color.h" 2
# 75 "../../../interface/hal/drv_sw_def/drv_sw_features_color.h" 2
# 951 "temp/res/EngineerMode.c" 2

<?xml version = "1.0" encoding="UTF-8"?>

<APP id = "APP_ENGINEERMODE1">

<!----------------- Include Area ---------------------------------------------->

    <INCLUDE file = "MMI_features.h"/>
    <INCLUDE file = "MMIDataType.h"/>
    <INCLUDE file = "GlobalResDef.h"/>




<!----------------- Common Area ----------------------------------------------->

    <!----------------- Timer Id ------------------------------------------>
    <TIMER id = "EM_NOTIFYDURATION_TIMER"/>
    <TIMER id = "EM_RINGTONE_HIGHLIGHT_TIMER"/>
    <TIMER id = "EM_GPRS_PING_TIMER"/>
    <TIMER id = "EM_GPRS_SOC_DEMO_APP_TIMER"/>

    <!----------------- Event Id ------------------------------------------>

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_GLOBAL_PROCESSING">Processing...</STRING>
    <STRING id = "STR_ID_EM_SIM_CARD_IS_NOT_AVAILABLE">This SIM card is not available</STRING>
    <STRING id = "STR_ID_EM_WARNING">Not allow or conflict!</STRING> <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_SET_LSK">Set</STRING>
    <STRING id = "STR_ID_EM_NOTICE_SUCCESS_REBOO">Done.\nPower off in 3 sec</STRING>
    <STRING id = "STR_ID_EM_GLOBAL_AUTO">Auto</STRING>
    <STRING id = "STR_ID_EM_TRUE">True</STRING>
    <STRING id = "STR_ID_EM_FALSE">False</STRING>





    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "GRP_ID_EM_ROOT"/>
    <SCREEN id = "SCR_ID_EM_CMN_SCRN"/>
    <SCREEN id = "SCR_ID_EM_DUALMODE_SWITCH_PROGRESS"/>

<!----------------- Menu Id ------------------------------------------->
    <MENUSET id = "MENUSET_ON_OFF">
        <MENUITEM id = "MENU_ID_EM_MISC_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_MISC_OFF" str = "STR_GLOBAL_OFF"/>
    </MENUSET>

    <MENUSET id = "MENUSET_TRUE_FALSE">
        <MENUITEM id = "MENU_ID_EM_TRUE" str = "STR_ID_EM_TRUE"/>
        <MENUITEM id = "MENU_ID_EM_FALSE" str = "STR_ID_EM_FALSE"/>
    </MENUSET>

<!----------------- Level1 Menu : Mainmenu ------------------------------------>

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_APP_NAME">Engineering mode</STRING>

    <!----------------- Image Id ------------------------------------------>
    <IMAGE id = "IMG_ID_EM_MAIN_ICON">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\TitleBar\\\\TB_EM.png"</IMAGE>

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_MAIN_MENU" type = "APP_MAIN" str = "STR_ID_EM_APP_NAME">





        <MENUITEM_ID>MENU_ID_EM_DEVICE</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_EM_AUDIO</MENUITEM_ID>




        <MENUITEM_ID>MENU_ID_EM_MISC</MENUITEM_ID>
# 1042 "temp/res/EngineerMode.c"
        <MENUITEM_ID>MENU_ID_EM_PROFILING</MENUITEM_ID>
# 1057 "temp/res/EngineerMode.c"
   </MENU>

<!----------------- EM Item End ----------------------------------------------->


<!----------------- Level2 Menu | Network Setting ----------------------------->
# 1122 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Network Setting | Network Info ---------------------------->
# 1183 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Network Setting | Band Selection--------------------------->
# 1251 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Network Setting | Prefer Rat ------------------------------>
# 1271 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Network Setting | Cell Lock ------------------------------->
# 1287 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Network Setting | Network WCDMA PREFERRED --------------------------->
# 1304 "temp/res/EngineerMode.c"
<!----------------- EM Item End ------------------------------------------->

<!----------------- Network Setting | IVSR -------------------------------->
# 1328 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Network Setting | Network Event --------------------------->
# 1363 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Network Setting | PLMN List ------------------------------->
# 1381 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Network Setting | Service selection ------------------------------->
# 1393 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Network Setting | Gprs Connection ------------------------------->







<!----------------- EM Item End ----------------------------------------------->


<!----------------- Network Setting | 3G_info --------------------------------->
# 1488 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Network Setting | TDD --------------------------------->
# 1569 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->




<!----------------- Level2 Menu | Device -------------------------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_DEVICE">Device</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_DEVICE" type = "APP_SUB" str = "STR_ID_EM_DEVICE">

        <MENUITEM_ID>MENU_ID_EM_DEV_SET_UART</MENUITEM_ID>






        <MENUITEM_ID>MENU_ID_EM_MM_COLOR</MENUITEM_ID>
# 1616 "temp/res/EngineerMode.c"
        <MENUITEM_ID>MENU_ID_EM_DEV_DCM_MODE</MENUITEM_ID>
# 1686 "temp/res/EngineerMode.c"
    </MENU>
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | GPIO ----------------------------------------->
# 1714 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | MM Color ----------------------------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_DEV_MM_COLOR">MM Color Adjust</STRING>
    <STRING id = "STR_ID_EM_DEV_SHARP">Sharpness</STRING>
    <STRING id = "STR_ID_EM_DEV_CONTRAST">Contrast</STRING>
    <STRING id = "STR_ID_EM_DEV_SATURATION">Saturation</STRING>
    <!----------------- Menu Id ------------------------------------------->
    <MENUITEM id = "MENU_ID_EM_MM_COLOR" str = "STR_ID_EM_DEV_MM_COLOR"/>

<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | Backlight ------------------------------------------>
# 1748 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Device | EINT ----------------------------------------->
# 1763 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | ADC ------------------------------------------>
# 1778 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | CLAM ----------------------------------------->
# 1792 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | HW Level ----------------------------------------->
# 1819 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | Set UART ----------------------------------------->

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_DEV_UART_POWER_ONOFF_MENU"/>

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_DEV_SET_UART">Set UART</STRING> <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_SET_UART_SETTING">UART setting</STRING> <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_SET_UART_TST_PS">TST-PS config</STRING> <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_SET_UART_TST_L1">TST-L1 config</STRING> <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_SET_UART_PS">PS config</STRING> <!-- Engineer Mode Menu Caption String -->


    <STRING id = "STR_ID_EM_DEV_USB_PORT">USB port</STRING> <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_USB_PORT2">USB port 2</STRING> <!-- Engineer Mode Menu Caption String -->






    <STRING id = "STR_ID_EM_DEV_UART_1">UART 1</STRING> <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_UART_2">UART 2</STRING> <!-- Engineer Mode Menu Caption String -->
    <STRING id = "STR_ID_EM_DEV_UART_3">UART 3</STRING> <!-- Engineer Mode Menu Caption String -->
# 1861 "temp/res/EngineerMode.c"
    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_DEV_SET_UART" type = "APP_SUB" str = "STR_ID_EM_DEV_SET_UART">
        <MENUITEM id = "MENU_ID_EM_DEV_UART_SETTING" str = "STR_ID_EM_DEV_SET_UART_SETTING"/>
    </MENU>


<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | Sleep Mode --------------------------------------->
# 1882 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | DCM Mode ----------------------------------------->


    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_DEV_DCM_MODE">DCM mode</STRING> <!-- Engineer Mode Menu Caption String -->

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_DEV_DCM_MODE" type = "APP_SUB" str = "STR_ID_EM_DEV_DCM_MODE" flag = "RADIO">
        <MENUITEM id = "MENU_ID_EM_DEV_DCM_MODE_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_DEV_DCM_MODE_OFF" str = "STR_GLOBAL_OFF"/>
    </MENU>


<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | NAND Format -------------------------------------->
# 1913 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | MTV Setting --------------------------------------->
# 1944 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Device | Video Setting --------------------------------------->
# 1995 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Device | Video Streaming setting --------------------------------------->
# 2017 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Device | USB ---------------------------------------------->
# 2054 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | Memory TEST ---------------------------------------------->
# 2075 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | FM Radio ----------------------------------------->
# 2117 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | TST Output Mode----------------------------------->
# 2136 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->




<!----------------- Device | USB Logging -------------------------------------->
# 2161 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | CAM AF Constshot --------------------------------->
# 2265 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->




<!----------------- Device | Mini GPS ----------------------------------------->
# 2446 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | Motion ------------------------------------------->
# 2554 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Device | Speed lcd ------------------------------------>
# 2569 "temp/res/EngineerMode.c"
<!----------------- Speech lcd End ---------------------------------------->

<!----------------- Device | PMU register setting ------------------------->
# 2585 "temp/res/EngineerMode.c"
<!----------------- Speech lcd End ---------------------------------------->

<!----------------- Device | PXS sensor ------------------------------------------->
# 2626 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Device | WLAN EAP Mode ------------------------------------>
# 2657 "temp/res/EngineerMode.c"
<!------------------------- Switch End ---------------------------------------->


<!----------------- Device | NFC ----------------------------------------->
# 2885 "temp/res/EngineerMode.c"
<!----------------- Device | NFC end ------------------------------------->
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Level2 Menu | Audio --------------------------------------->
    <!----------------- Screen Id ----------------------------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_AUDIO">Audio</STRING>





    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_AUDIO" type = "APP_SUB" str = "STR_ID_EM_AUDIO">
# 2917 "temp/res/EngineerMode.c"
        <MENUITEM_ID>MENU_ID_EM_AUD_AUTO_VM_SETTING</MENUITEM_ID>

    </MENU>


<!----------------- EM Item End ----------------------------------------------->


<!----------------- Audio | Set Mode ------------------------------------------>
# 3028 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Audio | Speech Enhancement -------------------------------->
# 3110 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Audio | Ring Tone ----------------------------------------->
# 3128 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- EM Item End ----------------------------------------------->



<!----------------- Audio | Debug Info ---------------------------------------->
# 3144 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Audio | Auto VM Setting ----------------------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_AUD_AUTO_VM_SETTING">Auto record setting</STRING>
    <STRING id = "STR_ID_EM_AUD_VM_SUPPORT">VM Support</STRING>
    <STRING id = "STR_ID_EM_AUD_AUTO_VM_SPH">Auto Speech Record</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_AUD_VM_SUPPORT" type = "APP_SUB" str = "STR_ID_EM_AUD_VM_SUPPORT" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>
    <MENU id = "MENU_ID_EM_AUD_AUTO_VM_SPH" type = "APP_SUB" str = "STR_ID_EM_AUD_AUTO_VM_SPH" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>
    <MENU id = "MENU_ID_EM_AUD_AUTO_VM_SETTING" type = "APP_SUB" str = "STR_ID_EM_AUD_AUTO_VM_SETTING">


        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>



<!----------------- EM Item End ----------------------------------------------->


<!----------------- Level2 Menu | GPRS Act ------------------------------------>
# 3343 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Level2 Menu | Misc.---------------------------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_MISC">Misc.</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_MISC" type = "APP_SUB" str = "STR_ID_EM_MISC">
# 3374 "temp/res/EngineerMode.c"
        <MENUITEM_ID>MENU_ID_EM_MISC_MEMORY_DUMP</MENUITEM_ID>
# 3462 "temp/res/EngineerMode.c"
        <MENUITEM_ID>MENU_ID_EM_MRE</MENUITEM_ID>





    </MENU>

<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Auto Answer --------------------------------------->
# 3483 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | High Speed SIM ------------------------------------>
# 3497 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Misc. | Backlight Mode ------------------------------------>
# 3510 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Auto Reset -------------------------------->
# 3523 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Misc. | RAM Test ------------------------------------------>







<!----------------- EM Item End ----------------------------------------------->



<!----------------- Misc. | Memory Dump --------------------------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_MISC_MEMORY_DUMP">Memory dump</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_MISC_MEMORY_DUMP" type = "APP_SUB" str = "STR_ID_EM_MISC_MEMORY_DUMP" flag = "RADIO">
        <MENUSET_ID>MENUSET_ON_OFF</MENUSET_ID>
    </MENU>

<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | AMR ----------------------------------------------->
# 3563 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Misc. | Internet Application ------------------------------>
# 3635 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Misc. | Touch Screen -------------------------------------->
# 3659 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Video High Bit Rate ------------------------------->
# 3673 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Misc. | Cell reselection ---------------------------------->
# 3693 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Cascade Menu ---------------------------------------->
# 3706 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Check Drive --------------------------------------->
# 3723 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Software Tracer ----------------------------------->
# 3737 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | DM Self Register --------------------------------------->
# 3777 "temp/res/EngineerMode.c"
<!----------------- DM Self Register Item End ----------------------------->

<!----------------- Misc. | DM Self Register --------------------------------------->
# 3806 "temp/res/EngineerMode.c"
<!----------------- DM Self Register Item End ----------------------------->


<!----------------- Misc. | DCD Network Paramter ------------------------------>
# 3838 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | FOTA Debug ---------------------------------------->
# 3865 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | DM Add APN ---------------------------------------->
# 3886 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Video Parameter ----------------------------------->
# 3911 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->
# 3946 "temp/res/EngineerMode.c"
<!----------------- Misc. | Software Patch ------------------------------------>
# 3957 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Level3 Menu | JAVA ---------------------------------------->
# 3983 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->
# 4138 "temp/res/EngineerMode.c"
<!----------------- JAVA | Heap Size Setting ---------------------------------->
# 4172 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- JAVA | Performance ---------------------------------------->
# 4200 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- JAVA | JUI Debug ------------------------------------------>
# 4224 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- MED Memory Setting ------------------------------------------>
# 4242 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Misc | Rf desense ----------------------------------------->
# 4259 "temp/res/EngineerMode.c"
<!----------------- Misc | Rf desense end ------------------------------------->


<!----------------- X download ----------------------------------------------->
# 4274 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Level3 Menu | MRE ---------------------------------------->
    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_MRE">MRE</STRING>

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_MISC_MRE_INFO"></SCREEN>

    <!----------------- Menu Id ------------------------------------------->

    <MENUITEM id = "MENU_ID_EM_MRE" str = "STR_ID_EM_MRE"/>


<!----------------- EM Item End ----------------------------------------------->


<!----------------- Misc. | Power on CPU query ------------------------------->
# 4308 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Level2 Menu | Debug Info ---------------------------------->
# 4333 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Debug Info | Last Exception ------------------------------->
# 4345 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Debug Info | System Stats --------------------------------->
# 4362 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Debug Info | Drive Letter --------------------------------->
# 4379 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Iperf ----------------------------------------------------->
# 4465 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Level2 Menu | Bluetooth ----------------------------------->
# 4498 "temp/res/EngineerMode.c"
<!----------------- Bluetooth Item End ----------------------------------------------->



<!----------------- Bluetooth | General Test --------------------------------->

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_BT_BD_ADDR">BD address</STRING>
# 4608 "temp/res/EngineerMode.c"
<!----------------- Bluetooth | Avrcp connect tg actively -------------------->







<!----------------- Avrcp connect tg actively Item End ------------------------>



<!----------------- Bluetooth | RF Test --------------------------------------->
# 4679 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Bluetooth | Get Chip Version ------------------------------>
# 4692 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Bluetooth | UPF IOT Test ---------------------------------->
# 4706 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->





<!----------------- Level2 Menu | Profiling ----------------------------------->
    <SCREEN id = "GRP_ID_EM_MISC_MEDIA_MEMORY_SETTING"></SCREEN>


    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_PROFILING">Profiling</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_PROFILING" type = "APP_SUB" str = "STR_ID_EM_PROFILING">
# 4731 "temp/res/EngineerMode.c"
        <MENUITEM_ID>MENU_ID_EM_PROFILING_FRAMEWORK</MENUITEM_ID>
# 4760 "temp/res/EngineerMode.c"
                <MENUITEM_ID>MENU_ID_EM_PROFILING_SWLA</MENUITEM_ID>


    </MENU>

<!----------------- EM Item End ----------------------------------------------->


<!----------------- Profiling | SWLA ----------------------------->


    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id="GRP_ID_EM_PROFILING_SWLA_RESULT_INFOR_GROUP"/>
    <SCREEN id="SCR_ID_EM_PROFILING_SWLA_RESULT_INFOR_SCRN"/>

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_PROFILING_SWLA">SWLA</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SWLA_RESUILT_INFOR">SWLA result infor</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_PROFILING_SWLA" type = "APP_SUB" str = "STR_ID_EM_PROFILING_SWLA" flag="RADIO">

        <MENUITEM id = "MENU_ID_EM_PROFILING_SWLA_ON" str = "STR_GLOBAL_ON"/>
        <MENUITEM id = "MENU_ID_EM_PROFILING_SWLA_OFF" str = "STR_GLOBAL_OFF"/>

    </MENU>


<!----------------- EM Item End ----------------------------------------------->






<!----------------- Profiling | GDI Profiling -------------------------->
# 4858 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Profiling | MultiMedia Profiling -------------------------->
# 4926 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Profiling | Framework Profiling -------------------------->

    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_PROFILING_FRM"></SCREEN>

    <!----------------- String Id ----------------------------------------->
    <STRING id = "STR_ID_EM_PROFILING_FRM">Frame profiling</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_DISPLAY_TIME_TEXT">Display Time</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_GDI_PROFILE_TEXT">GDI Image Profile</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_SCREEN_DELAY_TEXT">Screen Delay (ms)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_MATRIX_DELAY_TEXT">Matrix Delay (ms)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_LIST_DELAY_TEXT">List Delay (ms)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_FRM_DELAY_OFFSET_TEXT">Time Offset (ms)</STRING>

    <!----------------- Menu Id ------------------------------------------->
    <MENU id = "MENU_ID_EM_PROFILING_FRAMEWORK" type = "APP_SUB" str = "STR_ID_EM_PROFILING_FRM">
    </MENU>


<!----------------- EM Item End ----------------------------------------------->



<!----------------- Profiling | UI Benchmark ---------------------------------->
# 4968 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Profiling | Memory Monitor -------------------------------->
# 5001 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Profiling | Memory Stat. ---------------------------------->
# 5025 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Profiling | Venus Debug Panel ----------------------------->
# 5051 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- Profiling | FS Test -------------------------------------->
# 5065 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Profiling | CSB Browser ----------------------------------->
# 5081 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Profiling | Multimedia | xxx --------------------------------->
    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "GRP_ID_EM_PROFILING_AUTO_PLAY"></SCREEN>
    <SCREEN id = "GRP_ID_EM_PROFILING_VDOPLY"></SCREEN>
# 5095 "temp/res/EngineerMode.c"
    <SCREEN id = "GRP_ID_EM_PROFILING_CAMERA"></SCREEN>
    <SCREEN id = "GRP_ID_EM_PROFILING_CAMERA_APP_CAPTURE"></SCREEN>
    <SCREEN id = "GRP_ID_EM_PROFILING_IMAGE_DECODE"></SCREEN>
    <SCREEN id = "GRP_ID_EM_PROFILING_VDOREC"></SCREEN>

    <!----------------- String Id ------------------------------------------->
# 5129 "temp/res/EngineerMode.c"
    <!----------------- String Id ------------------------------------------->
    <STRING id = "STR_ID_EM_PROFILING_EXTRA_LAYER">Extra layer</STRING>
    <STRING id = "STR_ID_EM_PROFILING_ROTATE">Rotate</STRING>
    <STRING id = "STR_ID_EM_PROFILING_PLAY_SIZE">Play size</STRING>
    <STRING id = "STR_ID_EM_PROFILING_TVOUT_MODE">TV-Out mode</STRING>
    <STRING id = "STR_ID_EM_PROFILING_ROTATE_0">Rotate 0</STRING>
    <STRING id = "STR_ID_EM_PROFILING_ROTATE_90">Rotate 90</STRING>
    <STRING id = "STR_ID_EM_PROFILING_ROTATE_180">Rotate 180</STRING>
    <STRING id = "STR_ID_EM_PROFILING_ROTATE_270">Rotate 270</STRING>
    <STRING id = "STR_ID_EM_PROFILING_TV_FULL_SCREEN">Full screen</STRING>
    <STRING id = "STR_ID_EM_PROFILING_TV_LCD_SCREEN">LCD screen</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_SQCIF">SQCIF (128x96)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_QCIF">SQCIF (128x96)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_CIF">CIF (352x288)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_QQVGA">QQVGA (160x120)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_QVGA">QVGA (320x240)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_VGA">VGA (640x480)</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SIZE_LCD">LCD Size</STRING>
    <STRING id = "STR_ID_EM_PROFILING_RECORD_SIZE">Record Size</STRING>
    <STRING id = "STR_ID_EM_PROFILING_PREVIEW_SIZE">Preview Size</STRING>
    <STRING id = "STR_ID_EM_PROFILING_SETTING">Setting</STRING>

    <!----------------- Menu Id ------------------------------------------->

    <MENU id="MENU_ID_EM_PROFILING_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_EM_PROFILING_START</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EM_PROFILING_SETTING</MENUITEM_ID>
    </MENU>
    <MENUITEM id="MENU_ID_EM_PROFILING_START" str="STR_GLOBAL_START"/>
    <MENUITEM id="MENU_ID_EM_PROFILING_SETTING" str="STR_GLOBAL_SETTINGS"/>



<!----------------- EM Item End ----------------------------------------------->


<!----------------- Profiling | Gesture Test --------------------------------->
# 5175 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- Level2 Menu | RF Test Tool -------------------------------->
    <!----------------- Screen Id ----------------------------------------->
    <SCREEN id = "SCR_ID_EM_DUALMODE_SWITCH_PROGRESS"/>

    <!----------------- String Id ----------------------------------------->



    <STRING id = "STR_ID_EM_RF_TEST_GSM_CONFIRM_NOTIFY_TEST">Wifi must be off. Will power off after test.</STRING> <!-- Engineer Mode RF Test GSM Menu Caption String-->

    <!----------------- Menu Id ------------------------------------------->
# 5307 "temp/res/EngineerMode.c"
<!----------------- RF Test Tool | GSM RF Test -------------------------------->
# 5349 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- RF Test Tool | WIFI RF Test ------------------------------->
# 5480 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- Level2 Menu | VoIP ---------------------------------------->
# 5524 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->



<!----------------- VoIP | VoIP Settings -------------------------------------->






<!----------------- EM Item End ----------------------------------------------->



<!----------------- VoIP | SIP Support ---------------------------------------->
# 5550 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- VoIP | SIP Require ---------------------------------------->
# 5564 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->


<!----------------- VoIP | VoIP Log ------------------------------------------->
# 5579 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->




<!----------------- Audio | CacheData ----------------------------------------->
    <CACHEDATA type="double" id="NVRAM_AUDIO_DEBUG_INFO1" restore_flag="FALSE" restore_id="@NVRAM_CACHE_ID_RESERVED">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_AUDIO_DEBUG_INFO2" restore_flag="FALSE" restore_id="@NVRAM_CACHE_ID_RESERVED">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_AUDIO_DEBUG_INFO3" restore_flag="FALSE" restore_id="@NVRAM_CACHE_ID_RESERVED">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_AUDIO_DEBUG_INFO4" restore_flag="FALSE" restore_id="@NVRAM_CACHE_ID_RESERVED">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>



<!----------------- EM Item End ----------------------------------------------->

<!----------------- GDI image decode ------------------------------------------>
# 5627 "temp/res/EngineerMode.c"
<!----------------- EM Item End ----------------------------------------------->

<!----------------- XML END --------------------------------------------------->

</APP>
