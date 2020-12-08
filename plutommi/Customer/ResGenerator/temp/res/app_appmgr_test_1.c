#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP    id="APP_APPMGR_TEST_1" 
#ifdef __MAUI_SDK_TEST__
        package_name="native.mtk.appmgr_test_1"
        name="STR_ID_APP_APPMGR_TEST_1"
        img="IMG_ID_APP_APPMGR_TEST_1"
        launch="srv_appmgr_test_1_launch"
        package_proc="srv_appmgr_test_1_package_proc"
        hidden_in_mainmenu="true">

#ifdef __COSMOS_MMI_PACKAGE__
    <MEMORY base="1024*300" />
#endif
    <STRING id = "STR_ID_APP_APPMGR_TEST_1"/>
    <IMAGE id = "IMG_ID_APP_APPMGR_TEST_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Softkey\\\\Option_CSK.pbm"</IMAGE>
#else
>    
#endif /* __MAUI_SDK_TEST__ */
</APP>


