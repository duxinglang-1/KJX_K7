#include "MMI_features.h"
#include "MMIDataType.h"
#include "CustResDef.h"
#include "CustDataProts.h"

<?xml version="1.0" encoding="UTF-8"?>
<APP id="APP_VENUS_SHELL_IV">

#ifdef __MMI_VUI_SHELL_IMAGE_VIEWER__
    <STRING id="VAPP_SHELL_STR_IV_CARD_REMOVE"/>
    <STRING id="VAPP_SHELL_STR_SELECT_STORAGE"/>
    <STRING id="VAPP_SHELL_STR_DELETE_IMAGE"/>
    <STRING id="VAPP_SHELL_STR_IMAGE_VIEWER_TITLE"/>
    <STRING id="VAPP_SHELL_STR_NO_IMAGE"/>

    #ifdef __MMI_VUI_SHELL_IMAGE_VIEWER_SLIM__
    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell_Low\\\\ImageViewer\\\\"
    #else
    #define ROOT_PATH CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Shell\\\\ImageViewer\\\\"
    #endif
    <IMAGE id="VAPP_SHELL_IMG_IV_DRM_LOCKED_ICON">ROOT_PATH"Default_Lock.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_IV_DEFAULT_ICON">ROOT_PATH"Default_Update.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_IV_UNSUPPORT_ICON">ROOT_PATH"Default_Que.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_IV_NO_IMAGE">ROOT_PATH"NoImage.png"</IMAGE>    
    <IMAGE id="VAPP_SHELL_IMG_IV_SEND_DISABLE">ROOT_PATH"Send_Dis.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_IV_SEND_UP">ROOT_PATH"Send_Nor.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_IV_SEND_DOWN">ROOT_PATH"Send_Pre.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_IV_USE_DISABLE">ROOT_PATH"Use_Dis.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_IV_USE_UP">ROOT_PATH"Use_Nor.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_IV_USE_DOWN">ROOT_PATH"Use_Pre.png"</IMAGE>    
    <IMAGE id="VAPP_SHELL_IMG_IV_BORDER">ROOT_PATH"ImageMin_BG.9slice.png"</IMAGE>     
    <IMAGE id="VAPP_SHELL_IMG_IV_STORAGE_DISABLE">ROOT_PATH"Folder_Dis.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_IV_STORAGE_UP">ROOT_PATH"Folder_Nor.png"</IMAGE>
    <IMAGE id="VAPP_SHELL_IMG_IV_STORAGE_DOWN">ROOT_PATH"Folder_Pre.png"</IMAGE>
#endif

</APP>
