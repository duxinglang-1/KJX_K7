# 1 "temp/res/SoundRecSrv.c"
# 1 "<built-in>"
# 1 "<command line>"
# 1 "temp/res/SoundRecSrv.c"
# 1 "../../mmi/inc/MMI_features.h" 1
# 69 "../../mmi/inc/MMI_features.h"
# 1 "../../mmi/inc/MMI_features_switch.h" 1
# 67 "../../mmi/inc/MMI_features_switch.h"
# 1 "../../mmi/inc/MMI_features_type.h" 1
# 68 "../../mmi/inc/MMI_features_switch.h" 2
# 70 "../../mmi/inc/MMI_features.h" 2
# 2 "temp/res/SoundRecSrv.c" 2

<?xml version="1.0" encoding="UTF-8"?>

<APP id="SRV_SOUNDREC">

<!--
**************************************** NVRAM section ***************************************
-->

    <CACHEDATA type="byte" id="NVRAM_SRV_SNDREC_STORAGE" restore_flag="TRUE">
        <DEFAULT_VALUE>[0xFF]</DEFAULT_VALUE>
        <DESCRIPTION>The storage location of sound recorder</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_SRV_SNDREC_QUALITY" restore_flag="TRUE">
        <DEFAULT_VALUE>[0xFF]</DEFAULT_VALUE>
        <DESCRIPTION>The record quality of sound recorder</DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_AUTO_VM_SETTING_AUTO_VM" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Sound recorder </DESCRIPTION>
    </CACHEDATA>
</APP>
