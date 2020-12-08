/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_EDITOR">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h"/>

    <MENUSET id="MENU_SET_EDITOR_OPT">
      <MENUITEM_ID>MENU_ID_EDITOR_OPT_INSERT_SYMBOL</MENUITEM_ID>
      <MENUITEM_ID>MENU_ID_EDITOR_OPT_INPUT_METHOD</MENUITEM_ID>
      #if !defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__) && !defined(__MMI_IME_PLUG_IN_SETTING__)
      <MENUITEM_ID>MENU_ID_EDITOR_OPT_WRITING_LANGUAGE</MENUITEM_ID>
      <MENUITEM_ID>MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD</MENUITEM_ID>
      <MENUITEM_ID>MENU_ID_EDITOR_OPT_ADD_NEW_WORD</MENUITEM_ID>
      #endif
		#if defined (__MMI_IME_V3__)
		<MENUITEM_ID>MENU_ID_EDITOR_OPT_INPUT_METHOD_SETTING</MENUITEM_ID>
		#else
      <MENUITEM_ID>MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS</MENUITEM_ID>
		#endif
      <MENUITEM_ID>MENU_ID_EDITOR_OPT_EDIT_OPTIONS</MENUITEM_ID>
      <MENUITEM_ID>MENU_ID_COMMONSCREENS_IMEOPTIONS</MENUITEM_ID>
    </MENUSET>

    <!--Menu Tree Area-->

    <!------------------------------------------------------Other Resource---------------------------------------------------------->


</APP>


