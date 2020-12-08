# 1 "temp/res/PhbSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/PhbSrv.c"
# 158 "temp/res/PhbSrv.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 159 "temp/res/PhbSrv.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 160 "temp/res/PhbSrv.c" 2


<?xml version="1.0" encoding="UTF-8"?>


<APP id="SRV_PHB">



    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="STR_ID_PHB_MOBILE_NUMBER"/>
    <STRING id="STR_HOME_NUMBER"/>
    <STRING id="STR_OFFICE_NUMBER"/>
    <STRING id="STR_FAX_NUMBER"/>
    <STRING id="STR_EMERGENCY_NUMBER"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
# 205 "temp/res/PhbSrv.c"
    <IMAGE id="IMG_PHB_DEFAULT">"..\\\\..\\\\Customer\\\\Images\\\\PLUTO""\\\\MainLCD\\\\Call\\\\Connect\\\\CL_NET.png"</IMAGE>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>


        <SENDER id="EVT_ID_PHB_ADD_CONTACT" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_UPD_CONTACT" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_DEL_CONTACT" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_PRE_UPDATE_CONTACT" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_READY" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_OWNER_NUMBER_CHANGED" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_OP_GROUP" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_MULTI_OP_STATUS" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_STORAGE_CHANGE" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_NAME_SEQUENCE_CHANGE" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_BACKUP_RESTORE_NCENTER" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_FIELD_TYPE_CHNAGED_IND" hfile="PhbSrvGprot.h"/>
        <SENDER id="EVT_ID_PHB_MULTI_OP_DONE" hfile="PhbSrvGprot.h"/>
# 234 "temp/res/PhbSrv.c"
    <!------------------------------------------------------NARAM Resource---------------------------------------------------------->

    <CACHEDATA type="byte" id="NVRAM_PHB_SPEAK_NAME_ON_OFF" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_SPEAK_NAME </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PHB_STARTUP_COPY_SIM">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_STARTUP_COPY_1 </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PHB_STARTUP_COPY_SIM2">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_STARTUP_COPY_2 </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PHB_STARTUP_COPY_SIM3">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_STARTUP_COPY_3 </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PHB_STARTUP_COPY_SIM4">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_STARTUP_COPY_4 </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PHB_NAME_DISPLAY_TYPE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Phonebook name display type </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_PHB_STORAGE_LOCATION" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x02, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Phonebook prefer storage </DESCRIPTION>
    <FIELD>
    <OPTION hint="Phone"> [0x02, 0x00] </OPTION>


                  <OPTION hint="SIM"> [0x04, 0x00] </OPTION>
# 295 "temp/res/PhbSrv.c"
                        <OPTION hint="All"> [0x06, 0x00] </OPTION>
# 315 "temp/res/PhbSrv.c"
        </FIELD>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_PHB_NAME_LIST_FILTER" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_NLF </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_PHB_VCARD_VERSION" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> VCARD VERSION </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PHB_SAVE_CONTACT_NOTIFY" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> PHB_SAVE_NOTIFY </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SSC_DISABLE_FLAG">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_IDLE_DIALER_SEARCH_SETTING" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Dialer search on / off </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SETTING_SPEED_DIAL" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> Speed dial status </DESCRIPTION>
    </CACHEDATA>

</APP>
