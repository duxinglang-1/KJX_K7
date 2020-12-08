/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_VENUS_HS_WG_BKM">

#if defined(__MMI_VUI_HOMESCREEN_BOOKMARK__)
    
    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="VAPP_HS_STR_WG_BOOKMARKS"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="VAPP_HS_IMG_WG_ICON_BOOKMARK">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Widgeticon_Bookmark.png"</IMAGE>
#if defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__)
    <IMAGE id="VAPP_HS_IMG_WG_BOOKMARK_BG">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Bookmark\\\\Bookmark_BG.BMP"</IMAGE>
#else /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
    <IMAGE id="VAPP_HS_IMG_WG_BOOKMARK_BG">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Bookmark\\\\Bookmark_BG.PNG"</IMAGE>
#endif /* defined(__MMI_VUI_HOMESCREEN_LITE_DISPLAY__) */
    <IMAGE id="VAPP_HS_IMG_WG_BOOKMARK_DEFAULT_THUMBNAIL_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Bookmark\\\\Bookmark_Default.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BOOKMARK_UP_ARROW_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Bookmark\\\\Bookmark_UpArrow_Up.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BOOKMARK_UP_ARROW_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Bookmark\\\\Bookmark_UpArrow_Down.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BOOKMARK_UP_ARROW_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Bookmark\\\\Bookmark_UpArrow_Dis.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BOOKMARK_DOWN_ARROW_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Bookmark\\\\Bookmark_DownArrow_Up.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BOOKMARK_DOWN_ARROW_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Bookmark\\\\Bookmark_DownArrow_Down.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BOOKMARK_DOWN_ARROW_DIS">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Bookmark\\\\Bookmark_DownArrow_Dis.png"</IMAGE>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */


    <!------------------------------------------------------Other Resource---------------------------------------------------------->


#endif /* defined(__MMI_VUI_HOMESCREEN_BOOKMARK__) */

</APP>

