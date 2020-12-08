#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id = "VCUI_CONTACT_LIST" name = "STR_ID_VCUI_PHB_LIST" type = "venus">
    <MEMORY heap = "400 * 1024"/>
</APP>

<APP id = "VCUI_CONTACT_SAVE" name = "STR_ID_VCUI_PHB_SAVE" type = "venus">
#ifndef __LOW_COST_SUPPORT_COMMON__
#ifdef __MMI_COSMOS_IMAGECLIPPER__
    <MEMORY heap = "600 * 1024" cui = "VCUI_CONTACT_LIST + max(VCUI_STANDARD_CAMERA, VCUI_GALLERY_IMAGE_PICKER) + VCUI_IMGCLIP"/>
#else
    <MEMORY heap = "600 * 1024" cui = "VCUI_CONTACT_LIST + max(VCUI_STANDARD_CAMERA, VCUI_GALLERY_IMAGE_PICKER)"/>
#endif
#else
    <MEMORY heap = "200 * 1024" cui = "VCUI_TONE_SELECTOR"/>
#endif
</APP>

<APP id = "VCUI_CONTACT_SAVE2" name = "STR_ID_VCUI_PHB_SAVE2" type = "venus">
#ifndef __LOW_COST_SUPPORT_COMMON__
#ifdef __MMI_COSMOS_IMAGECLIPPER__
    <MEMORY heap = "600 * 1024" cui = "max(VCUI_TONE_SELECTOR, (max(VCUI_STANDARD_CAMERA, VCUI_GALLERY_IMAGE_PICKER) + VCUI_IMGCLIP))"/>
#else 
    <MEMORY heap = "600 * 1024" cui = "max(VCUI_TONE_SELECTOR, (max(VCUI_STANDARD_CAMERA, VCUI_GALLERY_IMAGE_PICKER)))"/>
#endif
#else
#ifdef __MMI_COSMOS_IMAGECLIPPER__
    <MEMORY heap = "200 * 1024" cui = "max(VCUI_TONE_SELECTOR, (VCUI_GALLERY_IMAGE_PICKER + VCUI_IMGCLIP))"/>
#else
	<MEMORY heap = "200 * 1024" cui = "max(VCUI_TONE_SELECTOR, VCUI_GALLERY_IMAGE_PICKER)" extra_base = "10 * 1024"/>
#endif
#endif
</APP>

<APP id = "VCUI_CONTACT_VIEW" name = "STR_ID_VCUI_PHB_VIEW" type = "venus">
#ifndef __LOW_COST_SUPPORT_COMMON__
    <MEMORY heap = "600 * 1024" cui = "VCUI_CONTACT_SAVE2"/>
#else
#if !defined (__MMI_CONTACT_SLIM__)
    <MEMORY heap = "300 * 1024" cui = "VCUI_CONTACT_SAVE2"/>   
#else
#ifdef __MMI_SMS_COMPOSER__
    <MEMORY heap = "150 * 1024" cui = "max(VCUI_CONTACT_SAVE2, VCUI_SMS_COMPOSER)" extra_base = "10 * 1024"/>
#else
#if defined (__MMI_UNIFIED_COMPOSER__) && !defined(__MMI_PHB_TCARD_STORAGE_SUPPORT__)
    <MEMORY heap = "150 * 1024"  extra_base = "10 * 1024" />
    <MEMORY cui = "max(VCUI_CONTACT_SAVE2, VCUI_MSGCOMPOSER)"/>
#else
    <MEMORY heap = "150 * 1024"  extra_base = "10 * 1024"  cui = "VCUI_CONTACT_SAVE2"/>
#endif
#endif
#endif
#endif
</APP>

<APP id = "VCUI_SIM_LOCATE" name = "STR_ID_VCUI_SIM_LOCATE" type = "venus">
    <MEMORY heap = "300 * 1024"/>
</APP>

<APP id = "VCUI_CONTACT_ADPTER" name = "STR_ID_VAPP_CONTACT_ADPTER" type = "venus">
    <MEMORY heap = "100 * 1024" cui = "VCUI_CONTACT_SAVE2"/>
    <STRING id = "STR_ID_VAPP_CONTACT_ADPTER"/>
</APP>

<APP id = "VCUI_CONTACT_ADPTER_NOTIFY" name = "STR_ID_VAPP_CONTACT_ADPTER_NOTIFY" type = "venus">
    <MEMORY heap = "100 * 1024" cui = "VCUI_CONTACT_SAVE2"/>
    <STRING id = "STR_ID_VAPP_CONTACT_ADPTER_NOTIFY"/>
</APP>
#ifdef __MMI_VCARD__ 
<APP id = "VCUI_CONTACT_VCARD_VIEW" name = "STR_ID_VCUI_VCARD_VIEW" type = "venus">
    <MEMORY base = "500 * 1024" heap = "200 * 1024"/>
    <STRING id = "STR_ID_VCUI_VCARD_VIEW"/>
</APP>
#endif
<APP id = "VCUI_CONTACT_SETTING" name = "STR_ID_VCUI_SETTING" type = "venus">
#ifdef __MMI_CONTACT_SLIM__
    <MEMORY heap = "200 * 1024"
#else
    <MEMORY heap = "400 * 1024"
#endif
#ifdef __MMI_SYNCML_APP_SYNC_MENU_SUPPORT__
    cui = "VCUI_CONTACT_LIST + VCUI_SYNC"/>
#else
    cui = "VCUI_CONTACT_LIST"/>
#endif
    <STRING id = "STR_ID_VCUI_SETTING"/>
</APP>

