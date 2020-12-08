#include "MMI_features.h"

<?xml version="1.0" encoding="UTF-8"?>

/* Needed header files of the compile option in XML files, if you need others need to add here */
#ifdef WAP_SUPPORT


/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_PUSH">

    <INCLUDE file = "mmi_rp_all_defs.h"/>

	#ifdef __DM_LAWMO_SUPPORT__
	<RECEIVER id="EVT_ID_SRV_DM_LAWMO_WIPE_IND" proc="srv_wap_push_handle_lawmo_request"/>
	#endif /*__DM_LAWMO_SUPPORT__*/

</APP>

#endif  /*  WAP_SUPPORT  */



