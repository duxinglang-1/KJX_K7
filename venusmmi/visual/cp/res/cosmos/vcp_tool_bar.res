#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_TOOL_BAR">
    <!-----------------------------------------------------Theme Resource Area----------------------------------------------------->
#if defined(__MMI_VUI_COSMOS_CP__)
    <THEME>
        <IMAGE id="VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL"/>
        <IMAGE id="VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED"/>
        <IMAGE id="VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED"/>
        <IMAGE id="VCP_IMG_TOOL_BAR_SHADOW"/>
    </THEME>
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
#else
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    #define ROOT_PATH RES_THEME_ROOT"\\\\Theme1\\\\Components\\\\Toolbar\\\\"
    <IMAGE id="VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL"> ROOT_PATH"Toolbar_BG_N.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED"> ROOT_PATH"Toolbar_BG_P.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED"> ROOT_PATH"Toolbar_BG_D.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_SHADOW"> ROOT_PATH"Toolbar_Shadow.9slice.png" </IMAGE>
    
#endif

    <!-- Common Item -->
    #define ROOT_TRANSLUCENT_PATH RES_IMG_ROOT"\\\\Components\\\\MultimediaCP\\\\Toolbar\\\\"
    <IMAGE id="VCP_IMG_TOOL_BAR_BUTTON_VISUAL_NORMAL_TRANSLUCENT"> ROOT_TRANSLUCENT_PATH"Toolbar_BG_N.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_BUTTON_VISUAL_PRESSED_TRANSLUCENT"> ROOT_TRANSLUCENT_PATH"Toolbar_BG_P.9slice.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_BUTTON_VISUAL_DISABLED_TRANSLUCENT"> ROOT_TRANSLUCENT_PATH"Toolbar_BG_D.9slice.png" </IMAGE>

    #define ROOT_PATH RES_IMG_ROOT"\\\\Components\\\\Toolbar\\\\CommonIcon\\\\"
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD"> ROOT_PATH"Add.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_ADD_FILE"> ROOT_PATH"Add_File.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_CANCEL"> ROOT_PATH"Cancel.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_CLEAR"> ROOT_PATH"Clear.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_COPY"> ROOT_PATH"Copy.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_DELETE"> ROOT_PATH"Delete.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT"> ROOT_PATH"Edit.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_EDIT_FOLDER"> ROOT_PATH"Edit_Folder.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_EXIT"> ROOT_PATH"Exit.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_EXPORT"> ROOT_PATH"Export.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_FOLD"> ROOT_PATH"Fold.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_FORMAT"> ROOT_PATH"Format.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_FORWARD"> ROOT_PATH"Forward.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_IMPORT"> ROOT_PATH"Insert.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_INSERT"> ROOT_PATH"Insert.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_INSTALL"> ROOT_PATH"Install.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_LIST"> ROOT_PATH"List.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_LOGIN"> ROOT_PATH"Login.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_MORE"> ROOT_PATH"More.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_MOVE"> ROOT_PATH"Move.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_NEW_FOLDER"> ROOT_PATH"New_Folder.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_OK"> ROOT_PATH"Ok.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_PREVIEW"> ROOT_PATH"Preview.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_REFRESH"> ROOT_PATH"Refresh.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_REMOVE"> ROOT_PATH"Remove.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_REPLY"> ROOT_PATH"Reply.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_RESTORE"> ROOT_PATH"Restore.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_SAVE"> ROOT_PATH"Save.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_SEARCH"> ROOT_PATH"Search.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_SELECT_ALL"> ROOT_PATH"Select_All.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_SEND"> ROOT_PATH"Send.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_SETTING"> ROOT_PATH"Settings.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_SHARE"> ROOT_PATH"Share.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_SORT"> ROOT_PATH"Sort.png" </IMAGE>
    <IMAGE id="VCP_IMG_TOOL_BAR_COMMON_ITEM_UNSELECT_ALL"> ROOT_PATH"Unselect_All.png" </IMAGE>

#if defined(__MMI_VUI_COSMOS_CP__)
<!-----------------------------------------------------String Resource Area----------------------------------------------------->
    <STRING id="VCP_STR_TOOL_BAR_FOLD"> "Fold" </STRING>
    
    <!-- Common Item -->
    <STRING id="VCP_STR_TOOL_BAR_UNSELECT_ALL"/>
    <STRING id="VCP_STR_TOOL_BAR_SORT"/>
    <STRING id="VCP_STR_TOOL_BAR_SHARE"/>
    <STRING id="VCP_STR_TOOL_BAR_SETTINGS"/>
    <STRING id="VCP_STR_TOOL_BAR_SEND"/>
    <STRING id="VCP_STR_TOOL_BAR_SELECT_ALL"/>
    <STRING id="VCP_STR_TOOL_BAR_SEARCH"/>
    <STRING id="VCP_STR_TOOL_BAR_SAVE"/>
    <STRING id="VCP_STR_TOOL_BAR_RESTORE"/>
    <STRING id="VCP_STR_TOOL_BAR_REPLY"/>
    <STRING id="VCP_STR_TOOL_BAR_REMOVE"/>
    <STRING id="VCP_STR_TOOL_BAR_REFRESH"/>
    <STRING id="VCP_STR_TOOL_BAR_PREVIEW"/>
    <STRING id="VCP_STR_TOOL_BAR_OK"/>
    <STRING id="VCP_STR_TOOL_BAR_NEW_FOLDER"/>
    <STRING id="VCP_STR_TOOL_BAR_MORE"/>
    <STRING id="VCP_STR_TOOL_BAR_MOVE"/>
    <STRING id="VCP_STR_TOOL_BAR_LOGIN"/>
    <STRING id="VCP_STR_TOOL_BAR_INSTALL"/>
    <STRING id="VCP_STR_TOOL_BAR_INSERT"/>
    <STRING id="VCP_STR_TOOL_BAR_IMPORT"/>
    <STRING id="VCP_STR_TOOL_BAR_FORWARD"/>
    <STRING id="VCP_STR_TOOL_BAR_FORMAT"/>
    <STRING id="VCP_STR_TOOL_BAR_FOLD"/>
    <STRING id="VCP_STR_TOOL_BAR_EXPORT"/>
    <STRING id="VCP_STR_TOOL_BAR_EXIT"/>
    <STRING id="VCP_STR_TOOL_BAR_EDIT_FOLDER"/>
    <STRING id="VCP_STR_TOOL_BAR_EDIT"/>
    <STRING id="VCP_STR_TOOL_BAR_DELETE"/>
    <STRING id="VCP_STR_TOOL_BAR_COPY"/>
    <STRING id="VCP_STR_TOOL_BAR_CLEAR"/>
    <STRING id="VCP_STR_TOOL_BAR_CANCEL"/>
    <STRING id="VCP_STR_TOOL_BAR_ADD_FILE"/>
    <STRING id="VCP_STR_TOOL_BAR_ADD"/>
    <STRING id="VCP_STR_TOOL_BAR_LIST"/>
#endif
</APP>

