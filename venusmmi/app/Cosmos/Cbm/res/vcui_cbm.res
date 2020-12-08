#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#ifdef __MMI_CBM_ALWAYS_ASK__
<APP id="VCUI_CBM" name="STR_APP_COSMOS_CBM" type="venus">
     <MEMORY base="base(VCUI_DTCNT)" fg="fg(VCUI_DTCNT)"/>

<!-- 
**************************************** String Id ****************************************
-->
    <STRING id="STR_APP_COSMOS_CBM"/>
</APP>
#else

<APP id="VCUI_CBM"> </APP>

#endif /* __MMI_CBM_ALWAYS_ASK__ */
