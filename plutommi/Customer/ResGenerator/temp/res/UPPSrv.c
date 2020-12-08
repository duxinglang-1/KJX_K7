/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#ifdef WAP_SUPPORT

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_WAP_PROF">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>
       
  <!------------------------------------------------------Other Resource---------------------------------------------------------->
 #if 0
    <CACHEDATA type="byte" id="NVRAM_WAP_PROF_ACTIVE_WAP_WLAN_PROFILE_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active WAP WLAN profile ID </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_WAP_PROFILE_INDEX">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_WAP_PROF_ACTIVE_WAP_PROFILE_INDEX </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_MMS_PROFILE_INDEX">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> NVRAM_WAP_PROF_ACTIVE_MMS_PROFILE_INDEX </DESCRIPTION>
    </CACHEDATA>
#endif

    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_WAP_SIM1_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active WAP SIM 1 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

 #ifdef MMS_SUPPORT
	<CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_MMS_SIM1_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active MMS SIM 1 dtcnt ID </DESCRIPTION>
    </CACHEDATA>
#endif

 #if (MMI_MAX_SIM_NUM >= 2)
    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_WAP_SIM2_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active WAP SIM 2 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

#ifdef  MMS_SUPPORT
      <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_MMS_SIM2_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active MMS SIM 2 dtcnt ID </DESCRIPTION>
    </CACHEDATA>
  #endif
  #endif

#if (MMI_MAX_SIM_NUM >= 3)
    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_WAP_SIM3_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active WAP SIM 3 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

#ifdef MMS_SUPPORT
     <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_MMS_SIM3_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active MMS SIM 3 dtcnt ID </DESCRIPTION>
    </CACHEDATA>
#endif
#endif

#if (MMI_MAX_SIM_NUM >= 4) 
    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_WAP_SIM4_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active WAP SIM 4 dtcnt ID </DESCRIPTION>
    </CACHEDATA>

#ifdef  MMS_SUPPORT
    <CACHEDATA type="short" id="NVRAM_WAP_PROF_ACTIVE_MMS_SIM4_DTCNT_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Active MMS SIM 4 dtcnt ID </DESCRIPTION>
    </CACHEDATA>
#endif
#endif


</APP>
#endif

