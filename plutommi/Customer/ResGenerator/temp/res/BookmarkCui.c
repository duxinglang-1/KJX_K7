#ifdef OPERA_BROWSER

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="CUI_BKM">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_CUI_OPERA_BKM_BOOKMARKS"/>
    <STRING id="STR_ID_CUI_OPERA_BKM_ADD_BOOKMARK"/>
    <STRING id="STR_ID_CUI_OPERA_BKM_TITLE"/>
    <STRING id="STR_ID_CUI_OPERA_BKM_FOLDER"/>
    <STRING id="STR_ID_CUI_OPERA_BKM_SAVE_BOOKMARK"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_ID_CUI_OPERA_BKM_BOOKMARKS">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\SW_BOMK.pbm"</IMAGE>
    #if defined(__COSMOS_MMI__)
    <IMAGE id="IMG_ID_CUI_OPERA_BKM_FOLDER_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_Folder.pbm"</IMAGE>
    #else
    <IMAGE id="IMG_ID_CUI_OPERA_BKM_FOLDER_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_Folder.bmp"</IMAGE>
    #endif
    <IMAGE id="IMG_ID_CUI_OPERA_BKM_DEFAULT_FAVICON">CUST_IMG_PATH"\\\\MainLCD\\\\WAP\\\\Bookmark\\\\BM_USER.pbm"</IMAGE>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
    <MENUITEM id="MENU_ID_CUI_OPERA_BKM_SELECT_FOLDER_OPTIONS_OPEN" str="STR_GLOBAL_OPEN"/>
    <MENUITEM id="MENU_ID_CUI_OPERA_BKM_SELECT_FOLDER_OPTIONS_SELECT" str="STR_GLOBAL_SELECT"/>

    <!--Menu Tree Area-->
    <MENU id="MENU_ID_CUI_OPERA_BKM_SELECT_FOLDER_OPTIONS" type="OPTION" str="STR_GLOBAL_OPTIONS" img="IMG_ID_CUI_OPERA_BKM_BOOKMARKS">
        <MENUITEM_ID>MENU_ID_CUI_OPERA_BKM_SELECT_FOLDER_OPTIONS_OPEN</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CUI_OPERA_BKM_SELECT_FOLDER_OPTIONS_SELECT</MENUITEM_ID>
    </MENU>


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="GRP_ID_CUI_OPERA_BKM_SELECT_BOOKMARK"/>
    <SCREEN id="GRP_ID_CUI_OPERA_BKM_ADD_BOOKMARK"/>
    <SCREEN id="SCR_ID_CUI_OPERA_BKM_PROGRESSING"/>
    <SCREEN id="SCR_ID_CUI_OPERA_BKM_BOOKMARK_LIST"/>
    <SCREEN id="SCR_ID_CUI_OPERA_BKM_BOOKMARK_FOLDER_LIST"/>


</APP>

#endif /* OPERA_BROWSER */

