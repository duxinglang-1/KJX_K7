#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP    id="APP_APPMGR_TEST_3" 
#ifdef __MAUI_SDK_TEST__
        name="STR_ID_APP_APPMGR_TEST_3"
        package_name="native.mtk.appmgr_test_3"
        launch="srv_appmgr_test_3_launch"
        package_proc="srv_appmgr_test_3_package_proc"
        hidden_in_mainmenu="true">

#ifdef __COSMOS_MMI_PACKAGE__
    <MEMORY base="1024*300" />
#endif
    <STRING id = "STR_ID_APP_APPMGR_TEST_3"/>
#else
>    
#endif /* __MAUI_SDK_TEST__ */    
</APP>

