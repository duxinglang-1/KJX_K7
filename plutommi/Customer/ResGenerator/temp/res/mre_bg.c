#include "MMI_features.h"
#include "custresdef.h"

#if defined(__MRE_BGMEM_SIZE__) && ( !defined(__COSMOS_MMI_PACKAGE__) || defined(__MRE_BG_CONC_LAUNCHER__) )

<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_MRE_BG" name="STR_ID_APP_MRE_BG">

    <MEMORY heap="$(MRE_SYS_BGMEM_SIZE)" inc="vmopt.h"/>
    <APPCONCURRENT concurrent_w_order="APP_MRE_BG, APP_IDLE"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id ="STR_ID_APP_MRE_BG"/>
    
</APP>

#endif /* __MRE_BGMEM_SIZE__ */

