#include "MMI_features.h" 

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
