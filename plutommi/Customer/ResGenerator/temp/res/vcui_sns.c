#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

#if defined(__SOCIAL_NETWORK_SUPPORT__) && defined (__COSMOS_MMI_PACKAGE__)
<APP id="VCUI_SNS_SLIM_UPLOAD_PIC" name="STR_ID_VCUI_SNS_SLIM" type="venus">   
    <MEMORY extra_base="240000" heap="153600"/> 
</APP>

<APP id="VCUI_SNS_UPLOAD_PIC" name="STR_ID_VCUI_SNS" type="venus">
    <INCLUDE file="GlobalResDef.h"/>
#ifndef __LOW_COST_SUPPORT_COMMON__
    <MEMORY extra_base="$(VCUI_SNS_THUMB_BUF_SIZE)+$(VCUI_SNS_RESIZE_UPLOADED_PIC_BUF_SIZE)" cui="max(VCUI_GALLERY_IMAGE_PICKER, VCUI_SLIM_CAMERA)" heap="153600" inc="vapp_sns_mem_def.h"/>
#else
    <MEMORY extra_base="$(VCUI_SNS_THUMB_BUF_SIZE)+$(VCUI_SNS_RESIZE_UPLOADED_PIC_BUF_SIZE)" cui="VCUI_GALLERY_IMAGE_PICKER" heap="153600" inc="vapp_sns_mem_def.h"/>
#endif
    <!-- Image Resource Are --------------------------------------------------->
    <IMAGE id="IMG_ID_VCUI_SNS_TOOL_BAR_UPLOAD">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Upload.png"</IMAGE>
    <IMAGE id="IMG_ID_VCUI_SNS_TOOL_BAR_REPLACE">RES_IMG_ROOT"\\\\SNS\\\\ToolbarIcon\\\\Replace_Img.png"</IMAGE>
    <!-- String Resource Area-------------------------------------------------->
    <STRING id="STR_ID_VCUI_SNS_TITLE_UPLOAD_PICTURE"/>
    <STRING id="STR_ID_VCUI_SNS_EDIT_PICTURE"/>
    <STRING id="STR_ID_VCUI_SNS_SELECT_FROM_GALLERY"/>
    <STRING id="STR_ID_VCUI_SNS_TAKE_A_PHOTO"/>
    <STRING id="STR_ID_VCUI_SNS_UPLOADED"/>
    <STRING id="STR_ID_VCUI_SNS_FAILED_TO_UPLOAD"/>
    <STRING id="STR_ID_VCUI_SNS_RETRY"/>
    <STRING id="STR_ID_VCUI_SNS_PLEASE_WAIT"/>
    <STRING id="STR_ID_VCUI_SNS_DESC_EDITOR_HINT"/>
    <STRING id="STR_ID_VCUI_SNS_FAILED_TO_RESIZE"/>
</APP>

<APP id="VCUI_SNS_CONTACTS_PICKER" name="STR_ID_VCUI_SNS_CONTACT_PICKER" type="venus">
    <MEMORY heap="500*1024"/>
</APP>

#ifdef __MMI_SNS_MESSAGES__
<APP id="VCUI_SNS_MSG_COMPOSER" name="STR_ID_VCUI_SNS_MSG_COMPOSER" type="venus">
    <MEMORY heap="200*1024" cui="VCUI_SNS_CONTACTS_PICKER"/>

    <STRING id="STR_ID_VCUI_SNS_MSG_COMPOSER"/>
    <STRING id="STR_ID_VCUI_SNS_MSG_NEW_MSG"/>
    <STRING id="STR_ID_VCUI_SNS_MSG_LEFT_PARENTHESIS"/>
    <STRING id="STR_ID_VCUI_SNS_MSG_RIGHT_PARENTHESIS"/>
    <STRING id="STR_ID_VCUI_SNS_MSG_TO_HINT"/>
    <STRING id="STR_ID_VCUI_SNS_MSG_TAP_TO_COMPOSE"/>
    <STRING id="STR_ID_VCUI_SNS_MSG_SELECT_FRIEND"/>

    <IMAGE id="IMG_ID_VCUI_SNS_MSG_DELETE">RES_IMG_ROOT"\\\\Common\\\\Button\\\\Delete.png"</IMAGE>
</APP>
#endif /* __MMI_SNS_MESSAGES__ */
#endif /* __SOCIAL_NETWORK_SUPPORT__ */
