# 1 "temp/res/VdoplyappRes.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/VdoplyappRes.c"
# 253 "temp/res/VdoplyappRes.c"
# 1 "../../mmi/inc/mmi_features.h" 1
# 69 "../../mmi/inc/mmi_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/mmi_features.h" 2
# 254 "temp/res/VdoplyappRes.c" 2
# 1 "../customerinc/custresdef.h" 1
# 191 "../customerinc/custresdef.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 192 "../customerinc/custresdef.h" 2
# 255 "temp/res/VdoplyappRes.c" 2
# 1 "../../mmi/inc/MMI_features_video.h" 1
# 714 "../../mmi/inc/MMI_features_video.h"
# 1 "../../mmi/inc/MMI_features.h" 1
# 715 "../../mmi/inc/MMI_features_video.h" 2
# 256 "temp/res/VdoplyappRes.c" 2

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VDOPLY"
name = "STR_ID_VDOPLY_APP_NAME"
type="pluto"
# 274 "temp/res/VdoplyappRes.c"
>
<INCLUDE file="GlobalResDef.h"/>
<INCLUDE file="MainMenuDef.h"/>
<INCLUDE file="CustomCfg.h"/>

<INCLUDE file="mmi_rp_app_filemanager_def.h"/>
# 1002 "temp/res/VdoplyappRes.c"
    <CACHEDATA type="byte" id="NVRAM_VDOPLY_VOLUMN" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x07] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player settings </DESCRIPTION>
        <FIELD min="0" max="16">
            <OPTION hint="level 0"> [0x00]</OPTION>
                        <OPTION hint="level 1"> [0x01]</OPTION>
                        <OPTION hint="level 2"> [0x02]</OPTION>
                        <OPTION hint="level 3"> [0x03]</OPTION>
                        <OPTION hint="level 4"> [0x04]</OPTION>
                        <OPTION hint="level 5"> [0x05]</OPTION>
                        <OPTION hint="level 6"> [0x06]</OPTION>
                        <OPTION hint="level 7"> [0x07]</OPTION>
                        <OPTION hint="level 8"> [0x08]</OPTION>
                        <OPTION hint="level 9"> [0x09]</OPTION>
                        <OPTION hint="level 10"> [0x0A]</OPTION>
                        <OPTION hint="level 11"> [0x0B]</OPTION>
                        <OPTION hint="level 12"> [0x0C]</OPTION>
                        <OPTION hint="level 13"> [0x0D]</OPTION>
                        <OPTION hint="level 14"> [0x0E]</OPTION>
                        <OPTION hint="level 15"> [0x0F]</OPTION>
                        <OPTION hint="mute"> [0x10]</OPTION>
                </FIELD>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VDOPLY_ACTIVE_PROFILE_IDX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VDOPLY_PROXY_IP1">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VDOPLY_PROXY_IP2">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VDOPLY_PROXY_IP3">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VDOPLY_PROXY_IP4">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_VDOPLY_PROXY_ON_OFF">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_VDOPLY_SNAPSHOT_SEQ_NO">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_VDOPLY_STORAGE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player Storage </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_VDOPLY_OPTION_BRIGHTNESS" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_VDOPLY_OPTION_CONTRAST" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_VDOPLY_OPTION_REPEAT" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_VDOPLY_OPTION_PLAY_MODE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Video Player setting </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_VDOPLY_STREAM_SEQ_NO">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_VDOPLY_PROXY_PORT">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_VDOPLY_HIGHEST_UDP_PORT">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="double" id="NVRAM_VDOPLY_LOWEST_UDP_PORT">
        <DEFAULT_VALUE> [0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>




</APP>
