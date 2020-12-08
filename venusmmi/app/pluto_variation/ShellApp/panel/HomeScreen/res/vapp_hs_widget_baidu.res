/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"


/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_VENUS_HS_WG_BAIDU">

#if defined(__MMI_VUI_HOMESCREEN_BAIDU_SEARCH__)

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id = "VAPP_HS_STR_WG_BAIDU_SEARCH_TITLE">Baidu Search</STRING>;
#if !(defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
    <STRING id = "VAPP_HS_STR_WG_BAIDU_SEARCH_EDIT_TITLE">Baidu Search</STRING>;
#endif


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BaiduSearch_Baidu.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BaiduSearch_Image.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_NEWS">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BaiduSearch_News.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_FORUM">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BaiduSearch_Forum.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_KNOWLEDGE">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BaiduSearch_Knowledge.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BaiduSearch_BG.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BaiduSearch_Search_Up.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BaiduSearch_Search_Down.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\Widgeticon_Baidu.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BS_Text_Web_Underline.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_WEB_TEXT_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BS_Text_Web_Bold.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_IMAGE_TEXT_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BS_Text_Image_Underline.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_IMAGE_TEXT_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BS_Text_Image_Bold.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_NEWS_TEXT_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BS_Text_News_Underline.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_NEWS_TEXT_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BS_Text_News_Bold.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_FORUM_TEXT_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BS_Text_Forum_Underline.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_FORUM_TEXT_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BS_Text_Forum_Bold.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_KNOWLEDGE_TEXT_UP">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BS_Text_Knowledge_Underline.png"</IMAGE>
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_CATEGORY_KNOWLEDGE_TEXT_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\BS_Text_Knowledge_Bold.png"</IMAGE>
#if !(defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
    <IMAGE id="VAPP_HS_IMG_WG_BAIDU_SEARCH_EDIT_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\HomeScreen\\\\Widget\\\\BaiduSearch\\\\TB_Baidu.pbm"</IMAGE>
#endif

    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */


    <!------------------------------------------------------Other Resource---------------------------------------------------------->
#if !(defined(__MMI_QWERTY_KEYPAD_SUPPORT__))
    <SCREEN id="GRP_ID_BAIDU_SEARCH_WIDGET"/>
    <SCREEN id="VAPP_HS_SCR_WG_BAIDU_SEARCH_EDIT"/>
    <SCREEN id="VAPP_HS_SCR_WG_BAIDU_SEARCH_EDIT_OPTION"/>
#endif

#endif /* defined(__MMI_VUI_HOMESCREEN_BAIDU_SEARCH__) */


</APP>


