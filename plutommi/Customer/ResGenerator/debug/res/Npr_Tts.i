# 1 "temp/res/Npr_Tts.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/Npr_Tts.c"







# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 9 "temp/res/Npr_Tts.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 10 "temp/res/Npr_Tts.c" 2


<?xml version="1.0" encoding="UTF-8"?>




<APP id = "APP_NPR_TTS"






        name = "@OID:STR_ID_TTS_SETTING_MENU_TEXT"

>




    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="STR_ID_NPR_TTS_MENU1"/>
    <STRING id="STR_ID_NPR_TTS_MENU2"/>
    <STRING id="STR_ID_NPR_TTS_ABOUT"/>
    <STRING id="STR_ID_NPR_TTS_ABOUT_INFO"/>
    <STRING id="STR_ID_NPR_TTS_VOL"/>
    <STRING id="STR_ID_NPR_TTS_SMS_NOTICE"/>

    <STRING id="STR_ID_TTS_SETTING_MENU_TEXT"/>
    <STRING id="STR_ID_TTS_MENU_READ"/>
    <STRING id="STR_ID_TTS_INCOMING_CALL_READ"/>
    <STRING id="STR_ID_TTS_KEYPAD_READ"/>
    <STRING id="STR_ID_TTS_TIME_READ_SET"/>
    <STRING id="STR_ID_TTS_VOICE_SEL"/>
    <STRING id="STR_ID_TTS_VOL_SET"/>
    <STRING id="STR_ID_TTS_ABOUT"/>
    <STRING id="STR_ID_TTS_TIME_READ_AUTO"/>
    <STRING id="STR_ID_TTS_TIME_READ_HAND"/>

    <STRING id="STR_ID_TTS_SMS_READ_SET"/>

    <STRING id="STR_ID_TTS_SMS_RECV_READ"/>

    <STRING id="STR_ID_TTS_SMS_AUTO_READ"/>

    <STRING id="STR_ID_TTS_TIME_READ_TIPS"/>
    <STRING id="STR_ID_TTS_ABOUT_INFO"/>


    <STRING id="STR_ID_TTS_FEMALE"/>
    <STRING id="STR_ID_TTS_GD"/>
    <STRING id="STR_ID_TTS_SC"/>
    <STRING id="STR_ID_TTS_DB"/>
    <STRING id="STR_ID_TTS_MALE"/>
    <STRING id="STR_ID_TTS_CHILDREN"/>

    <STRING id="STR_ID_NPR_INSERT_SIM_CARD"/>
    <STRING id="STR_ID_NPR_INVALID_SIM_CARD"/>
    <STRING id="STR_ID_NPR_NET_NOT_INITED"/>
    <STRING id="STR_ID_NPR_INSERT_T_CARD"/>


    <STRING id="STR_ID_NPR_TTS_SET_SIM"/>
    <STRING id="STR_ID_NPR_TTS_RESOURCES_DOWN"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

    <IMAGE id="IMG_ID_TTS_SETTING_MENU_ICON">"..\\\\..\\\\mmi\\\\npr\\\\npr_tts\\\\res\\\\icon\\\\tts_menu.png"</IMAGE>

    <IMAGE id="IMG_ID_NPR_TTS_MENU1">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\NPR\\\\npr_Aitalk\\\\menu1.gif"</IMAGE>
    <IMAGE id="IMG_ID_NPR_TTS_MENU2">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\NPR\\\\npr_Aitalk\\\\menu2.gif"</IMAGE>

    <SCREEN id="SCR_ID_TTS_SETTING_MIAN"/>
    <SCREEN id="SCR_ID_TTS_ABOUT"/>
    <SCREEN id="SCR_ID_TTS_VOLUME_SET"/>

    <SCREEN id="SCR_ID_TTS_VOICE_SEL"/>
    <SCREEN id="SCR_ID_TTS_SMS_READ_SET"/>
    <SCREEN id="SCR_ID_TTS_TIME_READ_SET"/>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <!--Menu Tree Area-->

    <MENU id="MENU_ID_TTS_SETTING" str="STR_ID_TTS_SETTING_MENU_TEXT" img="IMG_ID_TTS_SETTING_MENU_ICON" highlight="NPR_TTS_MainScreenHighlight">
    <MENUITEM_ID>@OID:MENU_ID_TTS_MENU_READ</MENUITEM_ID>

    <MENUITEM_ID>@OID:MENU_ID_TTS_INCOMING_CALL_READ</MENUITEM_ID>
    <MENUITEM_ID>@OID:MENU_ID_TTS_SMS_READ_SET</MENUITEM_ID>
    <MENUITEM_ID>@OID:MENU_ID_TTS_KEYPAD_READ</MENUITEM_ID>
    <MENUITEM_ID>@OID:MENU_ID_TTS_VOL_SET</MENUITEM_ID>



    <MENUITEM_ID>@OID:MENU_ID_TTS_ABOUT</MENUITEM_ID>
    </MENU>


    <MENU id="MENU_ID_TTS_MENU_READ" str="STR_ID_TTS_MENU_READ" img="NULL" hint = "NPR_TTS_MenuStatus_Hint" highlight="NPR_TTS_MenuScrenHighlight"/>
    <MENU id="MENU_ID_TTS_INCOMING_CALL_READ" str="STR_ID_TTS_INCOMING_CALL_READ" img="NULL" hint = "NPR_TTS_IncomingCallHint" highlight="NPR_TTS_IncomingCallHighlight"/>
    <MENU id="MENU_ID_TTS_KEYPAD_READ" str="STR_ID_TTS_KEYPAD_READ" img="NULL" hint = "NPR_TTS_KeyplayHint" highlight="NPR_TTS_KeyplayHighlight"/>
    <MENU id="MENU_ID_TTS_ABOUT" str="STR_ID_TTS_ABOUT" img="NULL" highlight="NPR_TTS_AboutScreenHighlight"/>
    <MENU id="MENU_ID_TTS_VOL_SET" str="STR_ID_TTS_VOL_SET" img="NULL" highlight="NPR_TTS_VolumeScreenHighlight"/>





    <MENU id="MENU_ID_TTS_SMS_READ_SET" str="STR_ID_TTS_SMS_READ_SET" img="NULL" highlight="NPR_TTS_SmsReadSetingHighlight">
    <MENUITEM_ID>@OID:MENU_ID_TTS_SMS_RECV_READ</MENUITEM_ID>
    <MENUITEM_ID>@OID:MENU_ID_TTS_SMS_AUTO_READ</MENUITEM_ID>
    </MENU>

    <MENU id="MENU_ID_TTS_SMS_RECV_READ" str="STR_ID_TTS_SMS_RECV_READ" img="NULL" hint = "NPR_TTS_SmsRecvHint" highlight="NPR_TTS_SmsRecvHighlight"/>
    <MENU id="MENU_ID_TTS_SMS_AUTO_READ" str="STR_ID_TTS_SMS_AUTO_READ" img="NULL" hint = "NPR_TTS_SmsAutoReadHint" highlight="NPR_TTS_SmsAutoHighlight"/>



    <!------------------------------------------------------MMI Cache Resource---------------------------------------------------------->
    <CACHEDATA type="byte" id="NVRAM_NPR_TTS_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> TTS Play nvram </DESCRIPTION>
    </CACHEDATA>

   <CACHEDATA type="byte" id="NVRAM_TTS_VOL_LEVEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> TTS Auto Play Time </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_TTS_VOICE_SEL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0XFF] </DEFAULT_VALUE>
        <DESCRIPTION> TTS volume selet </DESCRIPTION>
    </CACHEDATA>




</APP>
