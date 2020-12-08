/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_VENUS_COMPONENT_LIST_MENU">

#if defined(__MMI_VUI_COSMOS_CP__)

<THEME>
    <IMAGE id = "VCP_IMG_LIST_MENU_REORDER_THUMB" desc = "Reorder indicator icon of menu item"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_REORDERING_ITEM_BACKGROUND" desc = "Background image of menu item in reorder mode"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_HIGHLIGHT_ITEM_BACKGROUND" desc = "Background image of highlighted item"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_CHECK_BOX_ON" desc = "Chack box icon in on state of menu item"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_CHECK_BOX_OFF" desc = "Chack box icon in off state of menu item"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_RADIO_BUTTON_ON" desc = "Radio button icon in on state of menu item"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_RADIO_BUTTON_OFF" desc = "Radio button icon in off state of menu item"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_GROUP_HEADER_BG" desc = "Background image of group header item"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_CHECK_MARK" desc = "Check mark icon of menu item"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE" desc = "Disclosure icon of menu item"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE" desc = "Disclosure icon of highlighted menu item"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_TOP_SHADOW_D" desc = "Downward shadow image in top part of menu item"/>
    <IMAGE id = "VCP_IMG_LIST_MENU_TOP_SHADOW_U" desc = "Upward shadow image in top part of of menu item "/>
    <IMAGE id = "VCP_IMG_LIST_MENU_SEARCH" desc = "Search icon of search editor inputbox in list menu"/>

    <COLOR id = "VCP_COL_LIST_MENU_BG" desc = "Background color of list menu"/>
    <COLOR id = "VCP_COL_LIST_MENU_NORMAL_TEXT" desc = "Normal text color of menu item"/>
    <COLOR id = "VCP_COL_LIST_MENU_HIGHLIGHT_TEXT" desc = "Highlight text color of menu item"/>
    <COLOR id = "VCP_COL_LIST_MENU_LOWLIGHT_TEXT" desc = "Lowlight or hint text color of menu item"/>
    <COLOR id = "VCP_COL_LIST_MENU_DISABLED_TEXT" desc = "Text color of disabled menu item"/>
    <COLOR id = "VCP_COL_LIST_MENU_FOCUS_NORMAL_TEXT" desc = "Normal text color of highlighted menu item"/>
    <COLOR id = "VCP_COL_LIST_MENU_FOCUS_HIGHLIGHT_TEXT" desc = "Highlight text color of highlighted menu item"/>
    <COLOR id = "VCP_COL_LIST_MENU_FOCUS_LOWLIGHT_TEXT" desc = "Lowlight or hint text color of highlighted menu item"/>
    <COLOR id = "VCP_COL_LIST_MENU_FOCUS_DISABLED_TEXT" desc = "Text color of highlighted and disabled menu item"/>
    <COLOR id = "VCP_COL_LIST_MENU_DISABLE_FG" desc = "Disabled foreground color of list menu item"/>
    <COLOR id = "VCP_COL_LIST_MENU_HEADER_TEXT" desc = "Header text color of list menu"/>
</THEME>

#else /* defined(__MMI_VUI_COSMOS_CP__) */

    /* for shell images */
    <IMAGE id = "VCP_IMG_LIST_MENU_REORDER_THUMB">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\Components\\\\Listmenu\\\\List\\\\SetIndicator.png"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_REORDERING_ITEM_BACKGROUND">CUST_IMG_PATH"\\\\\MainLCD\\\\VUI\\\\Shell\\\\Components\\\\Listmenu\\\\List\\\\List_Shadow.9slice.png"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_HIGHLIGHT_ITEM_BACKGROUND">CUST_IMG_PATH"\\\\\MainLCD\\\\VUI\\\\Shell\\\\Components\\\\Listmenu\\\\List\\\\List_Pre.9slice.png"</IMAGE>;

    /* not used, for avoiding build error only */
    <IMAGE id = "VCP_IMG_LIST_MENU_CHECK_BOX_ON">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_CHECK_BOX_OFF">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_RADIO_BUTTON_ON">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_RADIO_BUTTON_OFF">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_GROUP_HEADER_BG">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_CHECK_MARK">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_DEFAULT_DISCLOSURE">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_DEFAULT_HIGHLIGHT_DISCLOSURE">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_TOP_SHADOW_D">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_TOP_SHADOW_U">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>;
    <IMAGE id = "VCP_IMG_LIST_MENU_SEARCH">CUST_IMG_BASE_PATH"\\\\EmptyImage.bmp"</IMAGE>;

#endif /* defined(__MMI_VUI_COSMOS_CP__) */

</APP>

