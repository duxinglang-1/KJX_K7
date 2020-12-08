#if (defined(__COSMOS_MMI_PACKAGE__) && defined(OPERA_BROWSER))

/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="VCUI_BKM" name="STR_VCUI_BKM" type="venus">
    <MEMORY base="200*1024" heap="200*1024"/>

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    <STRING id="STR_ID_VCUI_BKM_OPERA_NO_BOOKMARKS"/>
    <STRING id="STR_ID_VCUI_BKM_OPERA_ADD_BOOKMARK"/>
    <STRING id="STR_ID_VCUI_BKM_OPERA_NAME"/>
    <STRING id="STR_ID_VCUI_BKM_OPERA_SELECT_FOLDER"/>


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    <IMAGE id="IMG_ID_VCUI_BKM_OPERA_FOLDER_ICON">RES_IMG_ROOT"\\\\Browser\\\\ListIcon\\\\Folder.png"</IMAGE>
    <IMAGE id="IMG_ID_VCUI_BKM_OPERA_DEFAULT_FAVICON">RES_IMG_ROOT"\\\\Browser\\\\ListIcon\\\\Bookmark.png"</IMAGE>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!--Menu Tree Area-->


    <!------------------------------------------------------Other Resource---------------------------------------------------------->


</APP>

#endif /* defined(__COSMOS_MMI_PACKAGE__) && defined(OPERA_BROWSER) */

