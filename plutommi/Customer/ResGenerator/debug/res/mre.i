# 1 "temp/res/mre.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/mre.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 2 "temp/res/mre.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 3 "temp/res/mre.c" 2
# 1 "../../../mre/commoninc/vmswitch.h" 1
# 157 "../../../mre/commoninc/vmswitch.h"
# 1 "../../mmi/inc/mmi_features.h" 1
# 158 "../../../mre/commoninc/vmswitch.h" 2
# 1 "../../../mre/commoninc/vmswitch_cfg.h" 1
# 159 "../../../mre/commoninc/vmswitch.h" 2
# 4 "temp/res/mre.c" 2

<?xml version="1.0" encoding="UTF-8"?>


<APP id="APP_MRE" name="STR_ID_APP_MRE">


    <MEMORY heap="$(MRE_SYS_ASM_APP_MEMPOOL_SIZE)" inc="vmopt.h"/>
# 25 "temp/res/mre.c"
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <INCLUDE file="mmi_rp_app_filemanager_def.h"/>


    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="STR_MRE_TITLE"/>
    <STRING id="STR_MRE_NETWORK_CMWAP"/>
    <STRING id="STR_MRE_NETWORK_CMNET"/>
    <STRING id="STR_MRE_NETWORK_CMWAP_ONLY"/>
    <STRING id="STR_MRE_NETWORK_CMNET_ONLY"/>
    <STRING id="STR_MRE_NETWORK_CMWAP_DIS_WLAN"/>
    <STRING id="STR_MRE_NETWORK_CMNET_DIS_WLAN"/>
    <STRING id="STR_MRE_NETWORK_CMWAP_ONLY_DIS_WLAN"/>
    <STRING id="STR_MRE_NETWORK_CMNET_ONLY_DIS_WLAN"/>
    <STRING id="STR_MRE_NETWORK_WIFI"/>
    <STRING id="STR_MRE_APP0"/>
    <STRING id="STR_MRE_APP1"/>
    <STRING id="STR_MRE_APP2"/>
    <STRING id="STR_MRE_APP3"/>
    <STRING id="STR_MRE_APP4"/>
    <STRING id="STR_MRE_REACH_MAX_NUM"/>
    <STRING id="STR_MRE_POPUP_CONFLICTS"/>
    <STRING id="STR_MRE_POPUP_FORCE_FREE"/>

    <STRING id="STR_MRE_APP5"/>
    <STRING id="STR_MRE_APP6"/>
    <STRING id="STR_MRE_APP7"/>
    <STRING id="STR_MRE_APP8"/>
    <STRING id="STR_MRE_APP9"/>
    <STRING id="STR_MRE_OPERA_MINI"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>


    <IMAGE id="IMAGE_MRE_ICON" >"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Submenu\\\\NoSIM\\\\NS_MRE.pbm"</IMAGE>
    <IMAGE id="IMAGE_MRE_LARGE_ICON" >"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\FileManager\\\\FM_VXP.gif"</IMAGE>
    <IMAGE id="IMAGE_MRE_SMALL_ICON" >"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\FileManager\\\\FM_SMALL_VXP.bmp"</IMAGE>
    <IMAGE id="IMAGE_MRE_EDITOR_TITLE" >"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Titlebar\\\\TB_MRE_Editor.pbm"</IMAGE>






    <AUDIO id= "AUD_ID_MRE_FEEDBACK_SLIENT">"..\\\\..\\\\Customer\\\\AUDIO\\\\PLUTO""\\\\Sound\\\\Silence.imy"</AUDIO>
# 81 "temp/res/mre.c"
     <IMAGE id="IMG_ID_AM_APP_MRE_DEFAULT">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\MREAPP\\\\AM_App_Default.gif"</IMAGE>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_MRE_CORE"/>
    <SCREEN id="GRP_ID_MRE0"/>
    <SCREEN id="GRP_ID_MRE1"/>
    <SCREEN id="GRP_ID_MRE2"/>
    <SCREEN id="GRP_ID_MRE3"/>
    <SCREEN id="GRP_ID_MRE4"/>
    <SCREEN id="GRP_ID_MRE5"/>
    <SCREEN id="GRP_ID_MRE6"/>
    <SCREEN id="GRP_ID_MRE7"/>
    <SCREEN id="GRP_ID_MRE8"/>
    <SCREEN id="GRP_ID_MRE9"/>
    <SCREEN id="MRE_SCREEN_ID0"/>
    <SCREEN id="MRE_SCREEN_ID1"/>
    <SCREEN id="MRE_SCREEN_ID2"/>
    <SCREEN id="MRE_SCREEN_ID3"/>
    <SCREEN id="MRE_SCREEN_ID4"/>
    <SCREEN id="MRE_SCREEN_ID5"/>
    <SCREEN id="MRE_SCREEN_ID6"/>
    <SCREEN id="MRE_SCREEN_ID7"/>
    <SCREEN id="MRE_SCREEN_ID8"/>
    <SCREEN id="MRE_SCREEN_ID9"/>
    <SCREEN id="MRE_INPUT_SCREEN_ID"/>

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>

    <MENUITEM id="MENU_ID_FMGR_MRE_FILE_OPEN" str="STR_GLOBAL_OPEN"></MENUITEM>
    <MENUITEM id="MENU_ID_FMGR_MRE_OPTION_INSTALL" str="STR_GLOBAL_INSTALL"></MENUITEM>
     <MENU id="MENU_ID_FMGR_MRE_TYPE_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_FMGR_MRE_OPTION_INSTALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_MRE_FILE_OPEN</MENUITEM_ID>

        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_FORWARD_SEND</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_FORWARD_USE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_FOLDER_CREATE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_MORE_RITS</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_RENAME</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_DELETE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_SORT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_MARK_SEVERAL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_COPY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_MOVE</MENUITEM_ID>



        <MENUITEM_ID>MENU_ID_FMGR_GEN_OPTION_DETAIL</MENUITEM_ID>

     </MENU>

        <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_IN" proc="mmi_mre_fmgr_notify_hdlr"/>
        <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_DEV_PLUG_OUT" proc="mmi_mre_fmgr_notify_hdlr"/>
        <RECEIVER id="EVT_ID_SRV_FMGR_NOTIFICATION_FORMAT" proc="mmi_mre_fmgr_notify_hdlr"/>
    <RECEIVER id="EVT_ID_USB_ENTER_MS_MODE" proc="mmi_mre_enter_usb_mode"/>
    <RECEIVER id="EVT_ID_SRV_NEW_MMS_MSG" proc="mmi_mre_mms_interrupt_hdlr"/>

    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_IN" proc="vm_frm_backlight_notify_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_LCD_SLEEP_OUT" proc="vm_frm_backlight_notify_hdlr"/>
# 150 "temp/res/mre.c"
    <CACHEDATA type="double" id="NVRAM_MRE_SRV_DA_SIM1">
        <DEFAULT_VALUE>[0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF]</DEFAULT_VALUE>
        <DESCRIPTION>MRE Dataaccount SIM1</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_MRE_SRV_DA_SIM1_PX">
        <DEFAULT_VALUE>[0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF]</DEFAULT_VALUE>
        <DESCRIPTION>MRE Dataaccount SIM1 with proxy</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_MRE_SRV_DA_SIM2">
        <DEFAULT_VALUE>[0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF]</DEFAULT_VALUE>
        <DESCRIPTION>MRE Dataaccount SIM2</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_MRE_SRV_DA_SIM2_PX">
        <DEFAULT_VALUE>[0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF]</DEFAULT_VALUE>
        <DESCRIPTION>MRE Dataaccount SIM2 with proxy</DESCRIPTION>
    </CACHEDATA>


    <CACHEDATA type="double" id="NVRAM_MRE_SRV_DA_SIM3">
        <DEFAULT_VALUE>[0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF]</DEFAULT_VALUE>
        <DESCRIPTION>MRE Dataaccount SIM3</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_MRE_SRV_DA_SIM3_PX">
        <DEFAULT_VALUE>[0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF]</DEFAULT_VALUE>
        <DESCRIPTION>MRE Dataaccount SIM3 with proxy</DESCRIPTION>
    </CACHEDATA>


    <CACHEDATA type="double" id="NVRAM_MRE_SRV_DA_SIM4">
        <DEFAULT_VALUE>[0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF]</DEFAULT_VALUE>
        <DESCRIPTION>MRE Dataaccount SIM4</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_MRE_SRV_DA_SIM4_PX">
        <DEFAULT_VALUE>[0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF]</DEFAULT_VALUE>
        <DESCRIPTION>MRE Dataaccount SIM4 with proxy</DESCRIPTION>
    </CACHEDATA>


    <CACHEDATA type="byte" id="NVRAM_MRE_SRV_DA_IS_WIFI_ONLY">
        <DEFAULT_VALUE>[0x0]</DEFAULT_VALUE>
        <DESCRIPTION>MRE Dataaccount only use wifi</DESCRIPTION>
    </CACHEDATA>

     <!--------------------------------------------------Update app area----------------------------------------------------->
     <STRING id="STR_MRE_UPDATE_TITLE"/>
     <STRING id="STR_MRE_UPDATE_QUERY"/>
     <STRING id="STR_MRE_UPDATE_UPDATING"/>
     <STRING id="STR_MRE_UPDATE_SUCCESS"/>
     <STRING id="STR_MRE_UPDATE_FAIL"/>


     <SCREEN id="SCR_ID_MRE_UPDATE_QUERY"/>
     <SCREEN id="SCR_ID_MRE_UPDATE_WAIT"/>
     <SCREEN id="SCR_ID_MRE_UPDATE_RESULT"/>

    <TIMER id="MRE_SYS_TIMER_0"/>
    <TIMER id="MRE_SYS_TIMER_1"/>
    <TIMER id="MRE_SYS_TIMER_2"/>
    <TIMER id="MRE_SYS_TIMER_3"/>
    <TIMER id="MRE_SYS_TIMER_4"/>
    <TIMER id="MRE_SYS_TIMER_5"/>
    <TIMER id="MRE_SYS_TIMER_6"/>
    <TIMER id="MRE_SYS_TIMER_7"/>
    <TIMER id="MRE_SYS_TIMER_8"/>
    <TIMER id="MRE_SYS_TIMER_9"/>
    <TIMER id="MRE_SYS_TIMER_10"/>
    <TIMER id="MRE_SYS_TIMER_11"/>
    <TIMER id="MRE_SYS_TIMER_12"/>
    <TIMER id="MRE_SYS_TIMER_13"/>
    <TIMER id="MRE_SYS_TIMER_14"/>
    <TIMER id="MRE_SYS_TIMER_15"/>
    <TIMER id="MRE_SYS_TIMER_16"/>
    <TIMER id="MRE_SYS_TIMER_17"/>
    <TIMER id="MRE_SYS_TIMER_18"/>
    <TIMER id="MRE_SYS_TIMER_19"/>
    <TIMER id="MRE_SYS_TIMER_20"/>
    <TIMER id="MRE_SYS_TIMER_21"/>
    <TIMER id="MRE_SYS_TIMER_22"/>
    <TIMER id="MRE_SYS_TIMER_23"/>
    <TIMER id="MRE_SYS_TIMER_24"/>
    <TIMER id="MRE_SYS_TIMER_25"/>
    <TIMER id="MRE_SYS_TIMER_26"/>
    <TIMER id="MRE_SYS_TIMER_27"/>
    <TIMER id="MRE_SYS_TIMER_28"/>
    <TIMER id="MRE_SYS_TIMER_29"/>
    <TIMER id="MRE_SYS_TIMER_30"/>
    <TIMER id="MRE_SYS_TIMER_31"/>
    <TIMER id="MRE_SYS_TIMER_32"/>
    <TIMER id="MRE_SYS_TIMER_33"/>
    <TIMER id="MRE_SYS_TIMER_34"/>
    <TIMER id="MRE_SYS_TIMER_35"/>
    <TIMER id="MRE_SYS_TIMER_36"/>
    <TIMER id="MRE_SYS_TIMER_37"/>
    <TIMER id="MRE_SYS_TIMER_38"/>
    <TIMER id="MRE_SYS_TIMER_39"/>
    <TIMER id="MRE_SYS_TIMER_40"/>
    <TIMER id="MRE_SYS_TIMER_41"/>
    <TIMER id="MRE_SYS_TIMER_42"/>
    <TIMER id="MRE_SYS_TIMER_43"/>
    <TIMER id="MRE_SYS_TIMER_44"/>
    <TIMER id="MRE_SYS_TIMER_45"/>
    <TIMER id="MRE_SYS_TIMER_46"/>
    <TIMER id="MRE_SYS_TIMER_47"/>
    <TIMER id="MRE_SYS_TIMER_48"/>
    <TIMER id="MRE_SYS_TIMER_49"/>
    <TIMER id="MRE_SYS_TIMER_50"/>
    <TIMER id="MRE_SYS_TIMER_51"/>
    <TIMER id="MRE_SYS_TIMER_52"/>
    <TIMER id="MRE_SYS_TIMER_53"/>
    <TIMER id="MRE_SYS_TIMER_54"/>
    <TIMER id="MRE_SYS_TIMER_55"/>
    <TIMER id="MRE_SYS_TIMER_56"/>
    <TIMER id="MRE_SYS_TIMER_57"/>
    <TIMER id="MRE_SYS_TIMER_58"/>
    <TIMER id="MRE_SYS_TIMER_59"/>
    <TIMER id="MRE_SYS_TIMER_60"/>
    <TIMER id="MRE_SYS_TIMER_61"/>
    <TIMER id="MRE_SYS_TIMER_62"/>
    <TIMER id="MRE_SYS_TIMER_63"/>
    <TIMER id="MRE_SYS_TIMER_64"/>
    <TIMER id="MRE_SYS_TIMER_65"/>
    <TIMER id="MRE_SYS_TIMER_66"/>
    <TIMER id="MRE_SYS_TIMER_67"/>
    <TIMER id="MRE_SYS_TIMER_68"/>
    <TIMER id="MRE_SYS_TIMER_69"/>
    <TIMER id="MRE_SYS_TIMER_70"/>
    <TIMER id="MRE_SYS_TIMER_71"/>
    <TIMER id="MRE_SYS_TIMER_72"/>
    <TIMER id="MRE_SYS_TIMER_73"/>
    <TIMER id="MRE_SYS_TIMER_74"/>
    <TIMER id="MRE_SYS_TIMER_75"/>
    <TIMER id="MRE_SYS_TIMER_76"/>
    <TIMER id="MRE_SYS_TIMER_77"/>
    <TIMER id="MRE_SYS_TIMER_78"/>
    <TIMER id="MRE_SYS_TIMER_79"/>
    <TIMER id="MRE_SYS_TIMER_80"/>
    <TIMER id="MRE_SYS_TIMER_81"/>
    <TIMER id="MRE_SYS_TIMER_82"/>
    <TIMER id="MRE_SYS_TIMER_83"/>
    <TIMER id="MRE_SYS_TIMER_84"/>
    <TIMER id="MRE_SYS_TIMER_85"/>
    <TIMER id="MRE_SYS_TIMER_86"/>
    <TIMER id="MRE_SYS_TIMER_87"/>
    <TIMER id="MRE_SYS_TIMER_88"/>
    <TIMER id="MRE_SYS_TIMER_89"/>
    <TIMER id="MRE_SYS_TIMER_90"/>
    <TIMER id="MRE_SYS_TIMER_91"/>
    <TIMER id="MRE_SYS_TIMER_92"/>
    <TIMER id="MRE_SYS_TIMER_93"/>
    <TIMER id="MRE_SYS_TIMER_94"/>
    <TIMER id="MRE_SYS_TIMER_95"/>
    <TIMER id="MRE_SYS_TIMER_96"/>
    <TIMER id="MRE_SYS_TIMER_97"/>
    <TIMER id="MRE_SYS_TIMER_98"/>
    <TIMER id="MRE_SYS_TIMER_99"/>
</APP>

        <RECEIVER id="EVT_ID_SRV_PNS_START_REGISTER" proc="srv_mre_push_receiver_broadcast_receiver" />
# 323 "temp/res/mre.c"
<FILE_TYPES>
    <FILE_OPTION_HDLR option="MENU_ID_FMGR_MRE_FILE_OPEN" enabler="mmi_fmgr_vxp_option_enabler" handler="mmi_fmgr_vxp_option_hdlr" />
    <FILE_OPTION_HDLR option="MENU_ID_FMGR_MRE_OPTION_INSTALL" enabler="mmi_fmgr_vxp_option_enabler" handler="mmi_fmgr_vxp_option_hdlr"/>
# 337 "temp/res/mre.c"
    <FILE_TYPE type_id="FMGR_TYPE_VXP" extension="VXP" small_icon="IMAGE_MRE_SMALL_ICON" large_icon="IMAGE_MRE_LARGE_ICON" option="MENU_ID_FMGR_MRE_TYPE_OPTIONS"/>
    <FILE_TYPE type_id="FMGR_TYPE_VPP" extension="VPP" small_icon="IMAGE_MRE_SMALL_ICON" large_icon="IMAGE_MRE_LARGE_ICON" option="MENU_ID_FMGR_MRE_TYPE_OPTIONS"/>
</FILE_TYPES>




    <RECEIVER id="EVT_ID_SRV_REMINDER_NOTIFY" proc="vm_alarm_notify_hdlr"/>
