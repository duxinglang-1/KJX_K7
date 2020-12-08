#ifdef OPERA_BROWSER

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_OPERA"
#if (defined(__COSMOS_MMI_PACKAGE__) || defined(__MMI_APP_MANAGER_SUPPORT__))
    package_name="native.mtk.opera" 
    name="STR_ID_APP_OPERA"
    img="IMG_ID_APP_OPERA" 
    launch="vapp_opera_launch"
#else /* __COSMOS_MMI_PACKAGE__ || __MMI_APP_MANAGER_SUPPORT__ */
    name="STR_ID_APP_OPERA"
#endif    
>
    
#ifdef OPERA_V10_BROWSER
    <MEMORY heap="0"
            extra_base="$(OPERA_BROWSER_POOL_SIZE) + base(SRV_MDI_AUDPLY)"
            fg="fg(SRV_MDI_AUDPLY)"
            cui="max(max(APP_OPERA_ADP, VCUI_CBM), VCUI_BT_SEND_PREPARE)" 
            inc="opera_adp_cfg.h"/>
#elif defined(OPERA_V11_BROWSER)
    <MEMORY heap="0"
            extra_base="$(OPERA_BROWSER_POOL_SIZE) + base(SRV_MDI_AUDPLY)"
            fg="fg(SRV_MDI_AUDPLY)"
            cui="APP_OPERA_ADP" 
            inc="opera_adp_cfg.h"/>
#endif
    <APPCONCURRENT concurrent="APP_OPERA, APP_MUSIC_PLAYER"/>
#if (defined(__OP02__) && defined(__COSMOS_MMI_PACKAGE__))
    <APPCONCURRENT concurrent="APP_OPERA, VAPP_MSG"/>
#endif
#if defined(__COSMOS_MMI_PACKAGE__)
    <APPCONCURRENT concurrent_w_order="APP_OPERA, VAPP_DLAGENT, VAPP_CBM"/>
    <APPCONCURRENT concurrent_w_order="APP_OPERA, VAPP_CBM"/>
#endif

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_APP_OPERA"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
#ifdef __COSMOS_MMI_PACKAGE__
    <THEME>
        <IMAGE id="IMG_ID_APP_OPERA" desc="Main menu opera icon">RES_THEME_ROOT"\\\\Default\\\\Mainmenu_Icon\\\\Opera.png"</IMAGE>
    </THEME>
#else
    <IMAGE id="IMG_ID_APP_OPERA">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Launcher\\\\Mainmenu\\\\Icons\\\\Opera.png"</IMAGE>
#endif 
    
</APP>
<APP id="APP_OPERA_PARTIAL" name="STR_ID_APP_OPERA_PARTIAL">
#ifdef OPERA_V10_BROWSER
    <MEMORY heap="0"
            extra_base="(12 * 1024 * 1024) + base(SRV_MDI_AUDPLY)"
            fg="fg(SRV_MDI_AUDPLY)"
            cui="max(max(APP_OPERA_ADP, VCUI_CBM), VCUI_BT_SEND_PREPARE)"/>
#elif defined(OPERA_V11_BROWSER)
    <MEMORY heap="0"
            extra_base="(12 * 1024 * 1024) + base(SRV_MDI_AUDPLY)"
            fg="fg(SRV_MDI_AUDPLY)"
            cui="APP_OPERA_ADP"/>
#endif
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_APP_OPERA_PARTIAL"/>
</APP>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_OPERA_ADP" name="STR_ID_APP_OPERA_ADP">

#ifdef __COSMOS_MMI_PACKAGE__
#ifdef OPERA_V10_BROWSER
    <MEMORY heap="150 * 1024" cui="max(VCUI_DTCNT, VCUI_SMSONLYCOMPOSER)" />
#elif defined(OPERA_V11_BROWSER)
    <MEMORY heap="150 * 1024" cui="VCUI_DTCNT" />
#endif
#endif /* __COSMOS_MMI_PACKAGE__ */

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="SERVICES_OPERA_SHORTCUT_STRING_ID"/>
    <STRING id="STR_ID_APP_OPERA_ADP"/>
    <STRING id="STR_ID_APP_OPERA_ADP_ALWAYS_USE_WIFI"/>
    <STRING id="STR_ID_APP_OPERA_ADP_DEFAULT_DATA_ACCOUNT"/>
    <STRING id="STR_ID_APP_OPERA_ADP_NOT_AVAILABLE_USB_TETHERING_ACTIVATED"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="SERVICES_OPERA_SHORTCUT_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Opera\\\\SB_opera.pbm"</IMAGE>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!--Menu Tree Area-->
    <MENU id="SERVICES_OPERA_SHORTCUT_MENU_ID" str="SERVICES_OPERA_SHORTCUT_STRING_ID" img="SERVICES_OPERA_SHORTCUT_IMAGE_ID" shortcut="ON" shortcut_img="SERVICES_OPERA_SHORTCUT_IMAGE_ID" launch="goto_mobile_suite_screen">
    </MENU>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_DELETE_IND" proc="opera_adp_prof_account_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_ACCT_UPDATE_IND" proc="opera_adp_prof_account_changed_hdlr"/>
    <RECEIVER id="EVT_ID_SRV_DTCNT_SIM_PREFERENCE_UPDATE_IND" proc="opera_adp_prof_sim_preference_update_hdlr"/>


</APP>

#endif /* OPERA_BROWSER */

