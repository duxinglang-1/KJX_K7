#include "MMI_features.h"
#include "..\..\..\venusmmi\app\common\platform\vapp_platform_context_cfg.h"

#define xstr(s) str(s)
#define str(s) #s

<?xml version = "1.0" encoding = "UTF-8"?>
<APP id="VAPP_PLATFORM_CONTEXT" name="STR_PLATFORM_CONTEXT">

    #if defined(__VAPP_PLATFORM_CONTEXT_USE_MMV2__)
    <MEMORY heap=xstr(VAPP_PLATFORM_CONTEXT_TOTAL) heap_shrink=xstr(VAPP_PLATFORM_CONTEXT_BASE) heap_source="global"/>
    #endif

</APP>

