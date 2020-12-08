/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#include "gui_config.h"
#include "MMIDataType.h"
#include "gdi_features.h"


/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="APP_UIFRAMEWORK">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
#ifdef __UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__
<STRING id = "WGUI_UCE_SMS_STRING_ID">SMS</STRING>;
<STRING id = "WGUI_UCE_MMS_STRING_ID">MMS</STRING>;

#ifdef __MMI_TOUCH_SCREEN__
<IMAGE id = "WGUI_UCE_ATTACHFILE_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\LAttachfile.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_AUDIO_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\LAudio.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_PICTURE_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\LPic.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_VIDEO_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\LVideo.bmp"</IMAGE>;
#else
<IMAGE id = "WGUI_UCE_ATTACHFILE_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\SAttachfile.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_AUDIO_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\SAudio.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_PICTURE_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Spic.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_VIDEO_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\SVideo.bmp"</IMAGE>;
#endif 

<IMAGE id = "WGUI_UCE_PRE_BUTTON_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Left_arrow_normal.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_PRE_BUTTON_DISABLE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Left_arrow_disable.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_NEXT_BUTTON_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Right_arrow_normal.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_NEXT_BUTTON_DISABLE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Right_arrow_disable.bmp"</IMAGE>;

#ifdef __MMI_FTE_SUPPORT__
<IMAGE id = "WGUI_UCE_FTE_PRE_BUTTON_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_upL.png"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_PRE_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_downL.png"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_PRE_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_disableL.PNG"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_NEXT_BUTTON_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_upR.png"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_NEXT_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_downR.png"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_NEXT_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_disableR.PNG"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_BUTTON_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Background.png"</IMAGE>;
#endif 

#ifdef __MMI_FTE_SUPPORT__
<IMAGE id = "WGUI_UCE_FTE_ATTACHE_BUTTON_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Attachment_Button_Normal.png"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_ATTACHE_BUTTON_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Attachment_Button_Highlight.png"</IMAGE>;
/*
<IMAGE id = "WGUI_UCE_FTE_AUDIO_BUTTON_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Audio_Button_Normal.png"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_AUDIO_BUTTON_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Audio_Button_Highlight.png"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_RECIPIENT_BUTTON_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\To_Button_Normal.png"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_RECIPIENT_BUTTON_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\To_Button_Highlight.png"</IMAGE>;
*/
#else
<IMAGE id = "WGUI_UCE_FTE_ATTACHE_BUTTON_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_attach.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_ATTACHE_BUTTON_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_attach.bmp"</IMAGE>;
/*
<IMAGE id = "WGUI_UCE_FTE_AUDIO_BUTTON_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\audio.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_AUDIO_BUTTON_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\audio.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_TO_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Editor\\\\To.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_CC_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Editor\\\\CC.bmp"</IMAGE>;
<IMAGE id = "WGUI_UCE_FTE_BCC_BUTTON">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Editor\\\\BCC.bmp"</IMAGE>;
*/
#endif 
#endif 
#if defined(__UI_UNIFIED_COMPOSER_EDITOR_CATEGORY__) || defined(__UI_MMS_VIEWER_CATEGORY__)
#if defined(__MMI_SLIM_IMG_RES__)
<IMAGE id = "WGUI_DEFAULT_PREVIEW_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\broken.bmp"</IMAGE>;
<IMAGE id = "WGUI_DEFAULT_PREVIEW_AVIDEO_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\broken_video.bmp"</IMAGE>;
#else /* __MMI_SLIM_IMG_RES__ */
<IMAGE id = "WGUI_DEFAULT_PREVIEW_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\broken.gif"</IMAGE>;
<IMAGE id = "WGUI_DEFAULT_PREVIEW_AVIDEO_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\broken_video.gif"</IMAGE>;
#endif /* __MMI_SLIM_IMG_RES__ */
#endif 


#ifdef __UI_MMS_VIEWER_CATEGORY__
#if defined(__UI_MMS_VIEWER_CATEGORY__) && defined(__MMI_MSG_FTE_ENHANCE__)
<IMAGE id = "WGUI_DEFAULT_VIEW_ATTACH_HIGHLIGHT_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Attachment_Button_Highlight.png"</IMAGE>;
<IMAGE id = "WGUI_DEFAULT_VIEW_ATTACH_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UCE\\\\Attachment_Button_Normal.png"</IMAGE>;
<IMAGE id = "WGUI_DEFAULT_VIEW_NORMAL_HIGHLIGHT_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Full_Screen_Close_highlight.png"</IMAGE>;
<IMAGE id = "WGUI_DEFAULT_VIEW_NORMAL_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Full_Screen_Close_normal.png"</IMAGE>;
<IMAGE id = "WGUI_DEFAULT_VIEW_FULL_HIGHLIGHT_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Full_Screen_Open_highlight.png"</IMAGE>;
<IMAGE id = "WGUI_DEFAULT_VIEW_FULL_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Full_Screen_Open_normal.png"</IMAGE>;
 #endif 
    <IMAGE id = "WGUI_MV_ATTACHFILE_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_attach.bmp"</IMAGE>;
    <IMAGE id = "WGUI_MV_REFERENCE_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_ref.bmp"</IMAGE>;
    <IMAGE id = "WGUI_MV_RING_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_Ring.bmp"</IMAGE>;
#if defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "WGUI_MV_TITLE_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Background.9slice.png"</IMAGE>;
#endif 
    <IMAGE id = "WGUI_MV_BAR_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\BAR.bmp"</IMAGE>;
    <IMAGE id = "WGUI_MV_RING_STOP_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_RingStop.bmp"</IMAGE>;
#ifndef __MMI_FTE_SUPPORT__
    <IMAGE id = "WGUI_MV_LEFT_ARROW_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_LA.png"</IMAGE>;
    <IMAGE id = "WGUI_MV_LEFT_ARROW_DOWN_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_LADown.png"</IMAGE>;
    <IMAGE id = "WGUI_MV_RIGHT_ARROW_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_RA.png"</IMAGE>;
    <IMAGE id = "WGUI_MV_RIGHT_ARROW_DOWN_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_RADown.png"</IMAGE>;
#else

    <IMAGE id = "WGUI_MV_LEFT_ARROW_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\ARROW\\\\Th_upL.png"</IMAGE>;
    <IMAGE id = "WGUI_MV_LEFT_ARROW_DOWN_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\ARROW\\\\Th_downL.png"</IMAGE>;
    <IMAGE id = "WGUI_MV_RIGHT_ARROW_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\ARROW\\\\Th_upR.png"</IMAGE>;
    <IMAGE id = "WGUI_MV_RIGHT_ARROW_DOWN_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\ARROW\\\\Th_downR.png"</IMAGE>;
    <IMAGE id = "WGUI_MV_RIGHT_ARROW_DISABLE_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\ARROW\\\\Th_disableR.png"</IMAGE>;
    <IMAGE id = "WGUI_MV_LEFT_ARROW_DISABLE_ICON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\ARROW\\\\Th_disableL.PNG"</IMAGE>;
#endif
#ifdef __DRM_SUPPORT__
    <IMAGE id = "WGUI_MV_DRM_IMAGE_LOCK_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Image_lock.gif"</IMAGE>;
    <IMAGE id = "WGUI_MV_DRM_VIDEO_LOCK_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\Video_lock.gif"</IMAGE>;
#endif /* __DRM_SUPPORT__ */
#if !defined(__MMI_SLIM_MMS_2__)
    <IMAGE id = "WGUI_MV_PAUSE_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_pause.bmp"</IMAGE>;
    <IMAGE id = "WGUI_MV_RESUME_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MMS\\\\Smil\\\\MMS_resume.bmp"</IMAGE>;
#endif /* __MMI_SLIM_MMS_2__ */
#endif 


#if defined(__MMI_LANG_RUSSIAN__) || defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_SA_SPANISH__)\
    || defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_CA_FRENCH__) || defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__) \
    || defined(__MMI_LANG_GERMAN__) || defined(__MMI_LANG_ITALIAN__) || defined(__MMI_LANG_TURKISH__) \
    || defined(__MMI_LANG_POLISH__) || defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_SLOVAK__) \
    || defined(__MMI_LANG_CROATIAN__) || defined(__MMI_LANG_SLOVENIAN__) || defined(__MMI_LANG_DANISH__) \
    || defined(__MMI_LANG_HUNGARIAN__) || defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_ROMANIAN__) \
    || defined(__MMI_LANG_GREEK__) || defined(__MMI_LANG_BULGARIAN__) || defined(__MMI_LANG_MOLDOVAN__) \
    || defined(__MMI_LANG_CATALAN__)|| defined(__MMI_LANG_HAUSA__)|| defined(__MMI_LANG_ICELANDIC__)\
    || defined(__MMI_LANG_AZERBAIJANI__)|| defined(__MMI_LANG_YORUBA__)\
    || defined(__MMI_LANG_NORWEGIAN__)  || defined(__MMI_LANG_LITHUANIAN__)
    
#define  __MMI_VKBD_EUROPEAN_SUPPORT__

#endif 

#if defined(__MMI_MAINLCD_96X64__)
    <IMAGE id = "WGUI_CATEGORY_ABC_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\96_64UppercaseAbc.bmp"</IMAGE>;
    <IMAGE id = "WGUI_CATEGORY_abc_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\96_64LowercaseAbc.bmp"</IMAGE>;
#else
    <STRING id = "WGUI_CATEGORY_ABC_STRING_ID">ABC</STRING>;
    <STRING id = "WGUI_CATEGORY_abc_STRING_ID">abc</STRING>;
#endif

#if defined(__MMI_SMART_FIRST_UPPERCASE__)  || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    <STRING id = "WGUI_CATEGORY_Abc_STRING_ID">Abc</STRING>;
#endif
#if defined(__MMI_LANG_UK_ENGLISH__)
<STRING id = "WGUI_CATEGORY_UK_ABC_STRING_ID">ABC-UK</STRING>;
    <STRING id = "WGUI_CATEGORY_uk_abc_STRING_ID">abc-uk</STRING>;
#if defined(__MMI_SMART_FIRST_UPPERCASE__)  || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    <STRING id = "WGUI_CATEGORY_UK_Abc_STRING_ID">Abc-Uk</STRING>;
#endif
#endif

#if defined(__MMI_MAINLCD_96X64__)
    <IMAGE id = "WGUI_CATEGORY_123_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\96_64numeric123.bmp"</IMAGE>;
#else
    <STRING id = "WGUI_CATEGORY_123_STRING_ID">123</STRING>;
#endif

#if defined(__MMI_MULTITAP_THAI__) || defined(__MMI_ZI_THAI__)  ||  defined (__MMI_T9_THAI__) || defined (__MMI_CSTAR_THAI__) || defined (__MMI_GB_THAI__)
    <STRING id = "WGUI_CATEGORY_thai_STRING_ID">TH</STRING>;
#endif 
#if defined(__MMI_MULTITAP_HEBREW__)
    <STRING id = "WGUI_CATEGORY_hebrew_STRING_ID">He</STRING>;
#endif 
#if defined(__MMI_MULTITAP_SPANISH__)||defined(__MMI_T9_SPANISH__)||defined(__MMI_ZI_EU_SPANISH__)||defined(__MMI_ZI_SA_SPANISH__) || defined(__MMI_CSTAR_SPANISH__)||defined(__MMI_GB_SA_SPANISH__) || defined(__MMI_GB_SPANISH__)
    <STRING id = "WGUI_CATEGORY_SPANISH_STRING_ID">ES</STRING>;
    <STRING id = "WGUI_CATEGORY_spanish_STRING_ID">es</STRING>;
    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__)  || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_SPANISH_STRING_ID">Es</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_POLISH__)||defined(__MMI_IME_POLISH__)
    <STRING id = "WGUI_CATEGORY_POLISH_STRING_ID">PO</STRING>;
    <STRING id = "WGUI_CATEGORY_polish_STRING_ID">po</STRING>;
        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)  || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_POLISH_STRING_ID">Po</STRING>;
    #endif
#endif
#if defined(__MMI_MULTITAP_DANISH__)||defined(__MMI_T9_DANISH__)||defined(__MMI_ZI_DANISH__) || defined(__MMI_CSTAR_DANISH__) || defined(__MMI_GB_DANISH__)
    <STRING id = "WGUI_CATEGORY_DANISH_STRING_ID">DA</STRING>;
    <STRING id = "WGUI_CATEGORY_danish_STRING_ID">da</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)  || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_DANISH_STRING_ID">Da</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_SERBIAN__)||defined(__MMI_T9_SERBIAN__)||defined(__MMI_ZI_SERBIAN__)||defined(__MMI_GB_SERBIAN__)
    <STRING id = "WGUI_CATEGORY_SERBIAN_STRING_ID">SR</STRING>;
    <STRING id = "WGUI_CATEGORY_serbian_STRING_ID">sr</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_SERBIAN_STRING_ID">Sr</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_ICELANDIC__)||defined(__MMI_T9_ICELANDIC__)
    <STRING id = "WGUI_CATEGORY_ICELANDIC_STRING_ID">IS</STRING>;
    <STRING id = "WGUI_CATEGORY_icelandic_STRING_ID">is</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_ICELANDIC_STRING_ID">Is</STRING>;
    #endif
#endif  

#if defined(__MMI_MULTITAP_AZERBAIJANI__)||defined(__MMI_T9_AZERBAIJANI__)
    <STRING id = "WGUI_CATEGORY_AZERBAIJANI_STRING_ID">AZ</STRING>;
    <STRING id = "WGUI_CATEGORY_azerbaijani_STRING_ID">az</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_AZERBAIJANI_STRING_ID">Az</STRING>;
    #endif
#endif
#if defined(__MMI_MULTITAP_CATALAN__)||defined(__MMI_T9_CATALAN__)
    <STRING id = "WGUI_CATEGORY_CATALAN_STRING_ID">CA</STRING>;
    <STRING id = "WGUI_CATEGORY_catalan_STRING_ID">ca</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_CATALAN_STRING_ID">Ca</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_KAZAKH__)||defined(__MMI_T9_KAZAKH__)
    <STRING id = "WGUI_CATEGORY_KAZAKH_STRING_ID">KA</STRING>;
    <STRING id = "WGUI_CATEGORY_kazakh_STRING_ID">ka</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_KAZAKH_STRING_ID">Ka</STRING>;
    #endif
#endif
#if defined(__MMI_MULTITAP_HAUSA__)||defined(__MMI_T9_HAUSA__)
    <STRING id = "WGUI_CATEGORY_HAUSA_STRING_ID">HA</STRING>;
    <STRING id = "WGUI_CATEGORY_hausa_STRING_ID">ha</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_HAUSA_STRING_ID">Ha</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_MACEDONIAN__)||defined(__MMI_T9_MACEDONIAN__)||defined(__MMI_GB_MACEDONIAN__)
    <STRING id = "WGUI_CATEGORY_MACEDONIAN_STRING_ID">MK</STRING>;
    <STRING id = "WGUI_CATEGORY_macedonian_STRING_ID">mk</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_MACEDONIAN_STRING_ID">Mk</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_TAGALOG__)||defined(__MMI_T9_TAGALOG__)||defined(__MMI_ZI_TAGALOG__)
    <STRING id = "WGUI_CATEGORY_TAGALOG_STRING_ID">TG</STRING>;
    <STRING id = "WGUI_CATEGORY_tagalog_STRING_ID">tg</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_TAGALOG_STRING_ID">Tg</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_YORUBA__)||defined(__MMI_T9_YORUBA__)
    <STRING id = "WGUI_CATEGORY_YORUBA_STRING_ID">YO</STRING>;
    <STRING id = "WGUI_CATEGORY_yoruba_STRING_ID">yo</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_YORUBA_STRING_ID">Yo</STRING>;
    #endif
#endif
#if defined(__MMI_MULTITAP_SESOTHO__)||defined(__MMI_T9_SESOTHO__)
    <STRING id = "WGUI_CATEGORY_SESOTHO_STRING_ID">ST</STRING>;
    <STRING id = "WGUI_CATEGORY_sesotho_STRING_ID">st</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_SESOTHO_STRING_ID">St</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_GALICIAN__)||defined(__MMI_T9_GALICIAN__)
    <STRING id = "WGUI_CATEGORY_GALICIAN_STRING_ID">GL</STRING>;
    <STRING id = "WGUI_CATEGORY_galician_STRING_ID">gl</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_GALICIAN_STRING_ID">Gl</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_BASQUE__)||defined(__MMI_T9_BASQUE__)||defined(__MMI_GB_BASQUE__)
    <STRING id = "WGUI_CATEGORY_U_BASQUE_STRING_ID">BA</STRING>;
    <STRING id = "WGUI_CATEGORY_BASQUE_STRING_ID">ba</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_BASQUE_STRING_ID">Ba</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_IGBO__)||defined(__MMI_T9_IGBO__)
    <STRING id = "WGUI_CATEGORY_IGBO_STRING_ID">IG</STRING>;
    <STRING id = "WGUI_CATEGORY_igbo_STRING_ID">ig</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    <STRING id = "WGUI_CATEGORY_FIRST_U_IGBO_STRING_ID">Ig</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_FILIPINO__)||defined(__MMI_T9_FILIPINO__)||defined(__MMI_GB_FILIPINO__)
    <STRING id = "WGUI_CATEGORY_FILIPINO_STRING_ID">FIL</STRING>;
    <STRING id = "WGUI_CATEGORY_filipino_STRING_ID">fil</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    <STRING id = "WGUI_CATEGORY_FIRST_U_FILIPINO_STRING_ID">Fil</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_IRISH__)||defined(__MMI_T9_IRISH__)
    <STRING id = "WGUI_CATEGORY_IRISH_STRING_ID">GA</STRING>;
    <STRING id = "WGUI_CATEGORY_irish_STRING_ID">ga</STRING>;
            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)|| defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
    <STRING id = "WGUI_CATEGORY_FIRST_U_IRISH_STRING_ID">Ga</STRING>;
    #endif
#endif  
    
    
#if defined(__MMI_MULTITAP_FRENCH__)||defined(__MMI_T9_FRENCH__)||defined(__MMI_ZI_CA_FRENCH__)||defined(__MMI_ZI_EU_FRENCH__) || defined(__MMI_CSTAR_FRENCH__) || defined(__MMI_GB_FRENCH__)
    <STRING id = "WGUI_CATEGORY_FRENCH_STRING_ID">FR</STRING>;
    <STRING id = "WGUI_CATEGORY_french_STRING_ID">fr</STRING>;
                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__)  || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_FRENCH_STRING_ID">Fr</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_GERMAN__)||defined(__MMI_T9_GERMAN__)||defined(__MMI_ZI_GERMAN__) || defined(__MMI_CSTAR_GERMAN__)
    <STRING id = "WGUI_CATEGORY_GERMAN_STRING_ID">DE</STRING>;
    <STRING id = "WGUI_CATEGORY_german_STRING_ID">de</STRING>;
                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_GERMAN_STRING_ID">De</STRING>;
    #endif
#endif  

#if defined(__MMI_MULTITAP_KOREAN__)||defined(__MMI_T9_KOREAN__)||defined(__MMI_ZI_KOREAN__) || defined(__MMI_CSTAR_KOREAN__)
    <STRING id = "WGUI_CATEGORY_KOREAN_STRING_ID">KO</STRING>;

#endif  

#if defined(__MMI_MULTITAP_ITALIAN__)||defined(__MMI_IME_ITALIAN__)
    <STRING id = "WGUI_CATEGORY_ITALIAN_STRING_ID">IT</STRING>;
    <STRING id = "WGUI_CATEGORY_italian_STRING_ID">it</STRING>;
                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_ITALIAN_STRING_ID">It</STRING>;
    #endif
#endif  

#if defined (__MMI_T9_RUSSIAN__) || defined(__MMI_MULTITAP_RUSSIAN__)||defined(__MMI_ZI_RUSSIAN__)||defined(__MMI_ZI_RECOMMENDED_SIZE_RUSSIAN__) || defined(__MMI_CSTAR_RUSSIAN__)
    <STRING id = "WGUI_CATEGORY_RUSSIAN_STRING_ID">RU</STRING>;
    <STRING id = "WGUI_CATEGORY_russian_STRING_ID">ru</STRING>;
                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_RUSSIAN_STRING_ID">Ru</STRING>;
    #endif
#endif  
#if defined (__MMI_T9_BULGARIAN__) || defined(__MMI_MULTITAP_BULGARIAN__)||defined(__MMI_ZI_BULGARIAN__) || defined(__MMI_CSTAR_BULGARIAN__) || defined(__MMI_GB_BULGARIAN__)
    <STRING id = "WGUI_CATEGORY_BULGARIAN_STRING_ID">BG</STRING>;
    <STRING id = "WGUI_CATEGORY_bulgarian_STRING_ID">bg</STRING>;
                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_BULGARIAN_STRING_ID">Bg</STRING>;
    #endif
#endif
#if defined (__MMI_T9_UKRAINIAN__) || defined(__MMI_MULTITAP_UKRAINIAN__)||defined(__MMI_ZI_UKRAINIAN__) || defined(__MMI_CSTAR_UKRAINIAN__) || defined(__MMI_GB_UKRAINIAN__)
    <STRING id = "WGUI_CATEGORY_UKRAINIAN_STRING_ID">UK</STRING>;
    <STRING id = "WGUI_CATEGORY_L_UKRAINIAN_STRING_ID">uk</STRING>;
                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_UKRAINIAN_STRING_ID">Uk</STRING>;
    #endif
#endif
#if defined(__MMI_MULTITAP_TURKISH__)||defined(__MMI_ZI_TURKISH__)||defined(__MMI_T9_TURKISH__) || defined(__MMI_CSTAR_TURKISH__)
    <STRING id = "WGUI_CATEGORY_TURKISH_STRING_ID">TR</STRING>;
    <STRING id = "WGUI_CATEGORY_turkish_STRING_ID">tr</STRING>;
                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_TURKISH_STRING_ID">Tr</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_HEBREW__)||defined(__MMI_IME_HEBREW__)
    <STRING id = "WGUI_CATEGORY_HEBREW_STRING_ID">HE</STRING>;
    <STRING id = "WGUI_CATEGORY_hebrew_STRING_ID">he</STRING>;
#endif
#if defined(__MMI_MULTITAP_PORTUGUESE__)||defined(__MMI_T9_PORTUGUESE__)||defined(__MMI_ZI_EU_PORTUGUESE__)||defined(__MMI_ZI_SA_PORTUGUESE__)||defined(__MMI_ZI_BZ_PORTUGUESE__) || defined(__MMI_CSTAR_PORTUGUESE__) || defined(__MMI_GB_PORTUGUESE__) || defined(__MMI_GB_SA_PORTUGUESE__)
    <STRING id = "WGUI_CATEGORY_PORTUGUESE_STRING_ID">PT</STRING>;
    <STRING id = "WGUI_CATEGORY_portuguese_STRING_ID">pt</STRING>;
    <STRING id = "WGUI_CATEGORY_SA_PORTUGUESE_STRING_ID">SP</STRING>;
    <STRING id = "WGUI_CATEGORY_SA_portuguese_STRING_ID">sp</STRING>;
                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_PORTUGUESE_STRING_ID">Pt</STRING>;
        <STRING id = "WGUI_CATEGORY_FIRST_U_SA_PORTUGUESE_STRING_ID">Sp</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_INDONESIAN__)||defined(__MMI_ZI_INDONESIAN__)||defined(__MMI_T9_INDONESIAN__)   || defined(__MMI_CSTAR_INDONESIAN__)|| defined(__MMI_GB_INDONESIAN__)
    <STRING id = "WGUI_CATEGORY_INDONESIAN_STRING_ID">ID</STRING>;
    <STRING id = "WGUI_CATEGORY_indonesian_STRING_ID">id</STRING>;
                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_INDONESIAN_STRING_ID">Id</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_CZECH__)||defined(__MMI_T9_CZECH__)||defined(__MMI_ZI_CZECH__) || defined(__MMI_CSTAR_CZECH__)
    <STRING id = "WGUI_CATEGORY_CZECH_STRING_ID">CZ</STRING>;
    <STRING id = "WGUI_CATEGORY_czech_STRING_ID">cz</STRING>;
                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_CZECH_STRING_ID">Cz</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_MALAY__)||defined(__MMI_ZI_MALAY__)||defined(__MMI_T9_MALAY__) || defined(__MMI_CSTAR_MALAY__)
    <STRING id = "WGUI_CATEGORY_MALAY_STRING_ID">MS</STRING>;
    <STRING id = "WGUI_CATEGORY_malay_STRING_ID">ms</STRING>;
                                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_MALAY_STRING_ID">Ms</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_VIETNAMESE__)||defined(__MMI_ZI_VIETNAMESE__)||defined(__MMI_T9_VIETNAMESE__)   || defined(__MMI_CSTAR_VIETNAMESE__)
    <STRING id = "WGUI_CATEGORY_VIETNAMESE_STRING_ID">VI</STRING>;
    <STRING id = "WGUI_CATEGORY_vietnamese_STRING_ID">vi</STRING>;
                                                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_VIETNAMESE_STRING_ID">Vi</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_FINNISH__)||defined(__MMI_T9_FINNISH__)||defined(__MMI_ZI_FINNISH__) || defined(__MMI_CSTAR_FINNISH__)
    <STRING id = "WGUI_CATEGORY_FINNISH_STRING_ID">FI</STRING>;
    <STRING id = "WGUI_CATEGORY_finnish_STRING_ID">fi</STRING>;
                                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_FINNISH_STRING_ID">Fi</STRING>;
    #endif
#endif
#if  defined(__MMI_IME_HINGLISH__)
    <STRING id = "WGUI_CATEGORY_HINGLISH_STRING_ID">HABC</STRING>;
    <STRING id = "WGUI_CATEGORY_hinglish_STRING_ID">habc</STRING>;
#endif  

#if defined(__MMI_MULTITAP_HUNGARIAN__)||defined(__MMI_T9_HUNGARIAN__)||defined(__MMI_ZI_HUNGARIAN__)  || defined(__MMI_CSTAR_HUNGARIAN__)  || defined(__MMI_GB_HUNGARIAN__)
    <STRING id = "WGUI_CATEGORY_HUNGARIAN_STRING_ID">HG</STRING>;
    <STRING id = "WGUI_CATEGORY_hungarian_STRING_ID">hg</STRING>;
                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_HUNGARIAN_STRING_ID">Hg</STRING>;
    #endif
#endif  
#if defined(__MMI_LANG_ARABIC__)
    #if defined(__MMI_MAINLCD_96X64__)
    <IMAGE id = "WGUI_CATEGORY_ARABIC_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\96_64arabic.bmp"</IMAGE>;
    #else
    <STRING id = "WGUI_CATEGORY_ARABIC_STRING_ID">AR</STRING>;
    #endif
#endif  
#if defined(__MMI_LANG_ARABIC__)
    #if defined(__MMI_MAINLCD_96X64__)
    <IMAGE id = "WGUI_CATEGORY_ARABIC_NUMERIC_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\96_64Multitaparabic123.bmp"</IMAGE>;
    #else
    <STRING id = "WGUI_CATEGORY_ARABIC_NUMERIC_STRING_ID">AR123</STRING>;
    #endif
#endif  
#if defined(__MMI_MULTITAP_PERSIAN__) || defined(__MMI_ZI_PERSIAN__)|| defined(__MMI_CSTAR_PERSIAN__)|| defined(__MMI_GB_PERSIAN__)
    <STRING id = "WGUI_CATEGORY_PERSIAN_STRING_ID">FA</STRING>;
#endif  

#if defined(__MMI_MULTITAP_URDU__) || defined(__MMI_IME_URDU__)
    <STRING id = "WGUI_CATEGORY_URDU_STRING_ID">UR</STRING>;
#endif  

#if defined(__MMI_MULTITAP_HINDI__)||defined(__MMI_T9_HINDI__) || defined(__MMI_ZI_HINDI__)||defined(__MMI_CSTAR_HINDI__)||defined(__MMI_GB_HINDI__)
    #if defined(__MMI_MAINLCD_96X64__)
    <IMAGE id = "WGUI_CATEGORY_HINDI_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\96_64Hindi.bmp"</IMAGE>;
    #else
    <STRING id = "WGUI_CATEGORY_HINDI_STRING_ID">HI</STRING>;
    #endif
#endif
#if defined(__MMI_MULTITAP_MARATHI__) || defined(__MMI_ZI_MARATHI__)||defined(__MMI_T9_MARATHI__)
    <STRING id = "WGUI_CATEGORY_MARATHI_STRING_ID">MR</STRING>;
#endif
#if defined(__MMI_MULTITAP_TAMIL__) || defined(__MMI_ZI_TAMIL__)||defined(__MMI_T9_TAMIL__)
    <STRING id = "WGUI_CATEGORY_TAMIL_STRING_ID">TA</STRING>;
#endif
#if defined(__MMI_MULTITAP_BENGALI__) || defined(__MMI_ZI_BENGALI__)||defined(__MMI_T9_BENGALi__)  
    <STRING id = "WGUI_CATEGORY_BENGALI_STRING_ID">BN</STRING>;
#endif
#if defined(__MMI_MULTITAP_ASSAMESE__)||defined(__MMI_T9_ASSAMESE__)   
    <STRING id = "WGUI_CATEGORY_ASSAMESE_STRING_ID">AS</STRING>;
#endif
#if defined(__MMI_MULTITAP_PUNJABI__) || defined(__MMI_ZI_PUNJABI__)||defined(__MMI_T9_PUNJABI__)   
    <STRING id = "WGUI_CATEGORY_PUNJABI_STRING_ID">PA</STRING>;
#endif
#if defined(__MMI_MULTITAP_TELUGU__) || defined(__MMI_ZI_TELUGU__)||defined(__MMI_T9_TELUGU__) 
    <STRING id = "WGUI_CATEGORY_TELUGU_STRING_ID">TE</STRING>;
#endif

#if defined(__MMI_MULTITAP_KANNADA__) || defined(__MMI_ZI_KANNADA__) ||defined(__MMI_T9_KANNADA__)
    <STRING id = "WGUI_CATEGORY_KANNADA_STRING_ID">KN</STRING>;
#endif

#if defined(__MMI_MULTITAP_MALAYALAM__) || defined(__MMI_ZI_MALAYALAM__) ||defined(__MMI_T9_MALAYALAM__)
    <STRING id = "WGUI_CATEGORY_MALAYALAM_STRING_ID">ML</STRING>;
#endif
#if defined(__MMI_MULTITAP_LAO__) || defined(__MMI_ZI_LAO__) ||defined(__MMI_T9_LAO__) ||defined(__MMI_GB_LAO__)
    <STRING id = "WGUI_CATEGORY_LAO_STRING_ID">LO</STRING>;
#endif
#if defined(__MMI_MULTITAP_KHMER__) || defined(__MMI_ZI_KHMER__) ||defined(__MMI_T9_KHMER__) ||defined(__MMI_GB_KHMER__)
    <STRING id = "WGUI_CATEGORY_KHMER_STRING_ID">KM</STRING>;
#endif
#if defined(__MMI_MULTITAP_MYANMAR__) || defined(__MMI_ZI_MYANMAR__) ||defined(__MMI_T9_MYANMAR__) ||defined(__MMI_CSTAR_MYANMAR__)
    <STRING id = "WGUI_CATEGORY_MYANMAR_STRING_ID">MY</STRING>;
#endif
#if defined(__MMI_MULTITAP_GUJARATI__) || defined(__MMI_ZI_GUJARATI__) ||defined(__MMI_T9_GUJARATI__)
    <STRING id = "WGUI_CATEGORY_GUJARATI_STRING_ID">GU</STRING>;
#endif
#if defined(__MMI_MULTITAP_ORIYA__) || defined(__MMI_ZI_ORIYA__)||defined(__MMI_T9_ORIYA__) 
    <STRING id = "WGUI_CATEGORY_ORIYA_STRING_ID">OR</STRING>;
#endif

#if defined(__MMI_MULTITAP_NORWEGIAN__)||defined(__MMI_IME_NORWEGIAN__)
    <STRING id = "WGUI_CATEGORY_NORWEGIAN_STRING_ID">NO</STRING>;
    <STRING id = "WGUI_CATEGORY_norwegian_STRING_ID">no</STRING>;
                                                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_NORWEGIAN_STRING_ID">No</STRING>;
    #endif
#endif
#if defined(__MMI_MULTITAP_SLOVAK__)||defined(__MMI_T9_SLOVAK__)||defined(__MMI_ZI_SLOVAK__) || defined(__MMI_CSTAR_SLOVAKIAN__)
    <STRING id = "WGUI_CATEGORY_SLOVAK_STRING_ID">SK</STRING>;
    <STRING id = "WGUI_CATEGORY_slovak_STRING_ID">sk</STRING>;
                                                                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_SLOVAK_STRING_ID">Sk</STRING>;
    #endif
#endif
#if defined(__MMI_MULTITAP_DUTCH__)||defined(__MMI_ZI_DUTCH__)||defined(__MMI_T9_DUTCH__)   || defined(__MMI_CSTAR_DUTCH__)
    <STRING id = "WGUI_CATEGORY_DUTCH_STRING_ID">NL</STRING>;
    <STRING id = "WGUI_CATEGORY_dutch_STRING_ID">nl</STRING>;
                                                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_DUTCH_STRING_ID">Nl</STRING>;
    #endif
#endif
#if defined(__MMI_MULTITAP_SWEDISH__)||defined(__MMI_T9_SWEDISH__)||defined(__MMI_ZI_SWEDISH__) || defined(__MMI_CSTAR_SWEDISH__)
    <STRING id = "WGUI_CATEGORY_SWEDISH_STRING_ID">SV</STRING>;
    <STRING id = "WGUI_CATEGORY_swedish_STRING_ID">sv</STRING>;
                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_SWEDISH_STRING_ID">Sv</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_CROATIAN__)||defined(__MMI_T9_CROATIAN__)||defined(__MMI_ZI_CROATIAN__) || defined(__MMI_CSTAR_CROATIAN__) || defined(__MMI_GB_CROATIAN__)
    <STRING id = "WGUI_CATEGORY_CROATIAN_STRING_ID">HR</STRING>;
    <STRING id = "WGUI_CATEGORY_croatian_STRING_ID">hr</STRING>;
                                                                                        
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_CROATIAN_STRING_ID">Hr</STRING>;
    #endif
#endif
#if defined(__MMI_MULTITAP_ROMANIAN__)||defined(__MMI_ZI_ROMANIAN__)||defined(__MMI_T9_ROMANIAN__) || defined(__MMI_CSTAR_ROMANIAN__)
    <STRING id = "WGUI_CATEGORY_ROMANIAN_STRING_ID">RO</STRING>;
    <STRING id = "WGUI_CATEGORY_romanian_STRING_ID">ro</STRING>;
                                                                                            
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_ROMANIAN_STRING_ID">"Ro"</STRING>;
    #endif
#endif
#if defined(__MMI_MULTITAP_SLOVENIAN__)||defined(__MMI_T9_SLOVENIAN__)||defined(__MMI_ZI_SLOVENIAN__) || defined(__MMI_CSTAR_SLOVENIAN__)
    <STRING id = "WGUI_CATEGORY_SLOVENIAN_STRING_ID">SL</STRING>;
    <STRING id = "WGUI_CATEGORY_slovenian_STRING_ID">sl</STRING>;
                                                                                                
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_SLOVENIAN_STRING_ID">Sl</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_GREEK__)||defined(__MMI_T9_GREEK__)||defined(__MMI_ZI_GREEK__) || defined(__MMI_CSTAR_GREEK__)
    <STRING id = "WGUI_CATEGORY_GREEK_STRING_ID">EL</STRING>;
    <STRING id = "WGUI_CATEGORY_greek_STRING_ID">el</STRING>;
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_GREEK_STRING_ID">El</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_XHOSA__)||defined(__MMI_T9_XHOSA__)||defined(__MMI_ZI_XHOSA__) || defined(__MMI_CSTAR_XHOSA__)
    <STRING id = "WGUI_CATEGORY_U_XHOSA_STRING_ID">XH</STRING>;
    <STRING id = "WGUI_CATEGORY_L_XHOSA_STRING_ID">xh</STRING>;
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_XHOSA_STRING_ID">Xh</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_SWAHILI__)||defined(__MMI_T9_SWAHILI__)||defined(__MMI_ZI_SWAHILI__) || defined(__MMI_CSTAR_SWAHILI__) || defined(__MMI_GB_SWAHILI__)
    <STRING id = "WGUI_CATEGORY_U_SWAHILI_STRING_ID">SW</STRING>;
    <STRING id = "WGUI_CATEGORY_L_SWAHILI_STRING_ID">sw</STRING>;
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_SWAHILI_STRING_ID">Sw</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_AFRIKAANS__)||defined(__MMI_T9_AFRIKAANS__)||defined(__MMI_ZI_AFRIKAANS__) || defined(__MMI_CSTAR_AFRIKAANS__) || defined(__MMI_GB_AFRIKAANS__)
    <STRING id = "WGUI_CATEGORY_U_AFRIKAANS_STRING_ID">AF</STRING>;
    <STRING id = "WGUI_CATEGORY_L_AFRIKAANS_STRING_ID">af</STRING>;
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_AFRIKAANS_STRING_ID">Af</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_ZULU__)||defined(__MMI_T9_ZULU__)||defined(__MMI_ZI_ZULU__) || defined(__MMI_CSTAR_ZULU__)
    <STRING id = "WGUI_CATEGORY_U_ZULU_STRING_ID">ZU</STRING>;
    <STRING id = "WGUI_CATEGORY_L_ZULU_STRING_ID">zu</STRING>;
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_ZULU_STRING_ID">Zu</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_LITHUANIAN__)||defined(__MMI_T9_LITHUANIAN__)||defined(__MMI_ZI_LITHUANIAN__) || defined(__MMI_CSTAR_LITHUANIAN__)
    <STRING id = "WGUI_CATEGORY_U_LITHUANIAN_STRING_ID">LT</STRING>;
    <STRING id = "WGUI_CATEGORY_L_LITHUANIAN_STRING_ID">lt</STRING>;
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_LITHUANIAN_STRING_ID">Lt</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_LATVIAN__)||defined(__MMI_T9_LATVIAN__)||defined(__MMI_ZI_LATVIAN__) || defined(__MMI_CSTAR_LATVIAN__)
    <STRING id = "WGUI_CATEGORY_U_LATVIAN_STRING_ID">LV</STRING>;
    <STRING id = "WGUI_CATEGORY_L_LATVIAN_STRING_ID">lv</STRING>;
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_LATVIAN_STRING_ID">Lv</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_ESTONIAN__)||defined(__MMI_T9_ESTONIAN__)||defined(__MMI_ZI_ESTONIAN__) || defined(__MMI_CSTAR_ESTONIAN__)
    <STRING id = "WGUI_CATEGORY_U_ESTONIAN_STRING_ID">ET</STRING>;
    <STRING id = "WGUI_CATEGORY_L_ESTONIAN_STRING_ID">et</STRING>;
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_ESTONIAN_STRING_ID">"Et"</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_ALBANIAN__)||defined(__MMI_T9_ALBANIAN__)||defined(__MMI_ZI_ALBANIAN__) || defined(__MMI_CSTAR_ALBANIAN__) || defined(__MMI_GB_ALBANIAN__)
    <STRING id = "WGUI_CATEGORY_U_ALBANIAN_STRING_ID">SQ</STRING>;
    <STRING id = "WGUI_CATEGORY_L_ALBANIAN_STRING_ID">sq</STRING>;
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_ALBANIAN_STRING_ID">Sq</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_ARMENIAN__)||defined(__MMI_T9_ARMENIAN__)||defined(__MMI_ZI_ARMENIAN__) || defined(__MMI_CSTAR_ARMENIAN__)
    <STRING id = "WGUI_CATEGORY_U_ARMENIAN_STRING_ID">HY</STRING>;
    <STRING id = "WGUI_CATEGORY_L_ARMENIAN_STRING_ID">hy</STRING>;
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_ARMENIAN_STRING_ID">Hy</STRING>;
    #endif
#endif

#if defined(__MMI_MULTITAP_GEORGIAN__)||defined(__MMI_T9_GEORGIAN__)||defined(__MMI_ZI_GEORGIAN__) || defined(__MMI_CSTAR_GEORGIAN__) || defined(__MMI_GB_GEORGIAN__)
    <STRING id = "WGUI_CATEGORY_GEORGIAN_STRING_ID">KA</STRING>;
#endif

#if defined(__MMI_MULTITAP_MOLDOVAN__)||defined(__MMI_T9_MOLDOVAN__)||defined(__MMI_ZI_MOLDOVAN__) || defined(__MMI_CSTAR_MOLDOVAN__)
    <STRING id = "WGUI_CATEGORY_U_MOLDOVAN_STRING_ID">MO</STRING>;
    <STRING id = "WGUI_CATEGORY_L_MOLDOVAN_STRING_ID">mo</STRING>;
                                                                                                    
    #if defined(__MMI_SMART_FIRST_UPPERCASE__) || defined(__MMI_MULTITAP_FIRST_UPPERCASE__) || defined(__MMI_QWERTY_KEYPAD_SUPPORT__)
        <STRING id = "WGUI_CATEGORY_FIRST_U_MOLDOVAN_STRING_ID">Mo</STRING>;
    #endif
#endif


#if defined(__MMI_IME_USER_DATABASE__) || defined(__MMI_CSTAR_USER_DICT__)
    <STRING id = "STR_INPUT_METHOD_SPELL_WORD">SpellWord</STRING>;
    <STRING id = "STR_INPUT_METHOD_WORD_ALREADY_EXISTS">Thiswordalreadyexists</STRING>;
#endif

#ifdef __MMI_HANDWRITING_MEMORY_CARD_SUPPORT__
    <STRING id="STR_INPUT_METHOD_NO_HW_DATA"/>
#endif 

#if defined(__MMI_IME_FTE_ENHANCE__) 
    <STRING id = "STR_IME_PEN_INPUT_STYLE_VK_QWERTY">QWERTYvirtualkeyboard</STRING>;
    <STRING id = "STR_IME_PEN_INPUT_STYLE_VK_ALPHANUMERIC">Alphanumericvirtualkeyboard</STRING>;
    <STRING id = "STR_IME_PEN_INPUT_STYLE_HW">Handwriting</STRING>;
    
#endif

#ifdef __MMI_SUBLCD__
    <STRING id = "STR_SUBLCD_CHI_SUNDAY">S</STRING>;
    <STRING id = "STR_SUBLCD_CHI_MONDAY">M</STRING>;
    <STRING id = "STR_SUBLCD_CHI_TUESDAY">T</STRING>;
    <STRING id = "STR_SUBLCD_CHI_WEDNESDAY">W</STRING>;
    <STRING id = "STR_SUBLCD_CHI_THURSDAY">T</STRING>;
    <STRING id = "STR_SUBLCD_CHI_FRIDAY">F</STRING>;
    <STRING id = "STR_SUBLCD_CHI_SATURDAY">S</STRING>;

     <STRING id = "STR_SUBLCD_ENG_SUNDAY">S</STRING>;
    <STRING id = "STR_SUBLCD_ENG_MONDAY">M</STRING>;
    <STRING id = "STR_SUBLCD_ENG_TUESDAY">T</STRING>;
    <STRING id = "STR_SUBLCD_ENG_WEDNESDAY">W</STRING>;
    <STRING id = "STR_SUBLCD_ENG_THURSDAY">T</STRING>;
    <STRING id = "STR_SUBLCD_ENG_FRIDAY">F</STRING>;
    <STRING id = "STR_SUBLCD_ENG_SATURDAY">S</STRING>;
#endif 

#ifdef __MMI_DATE_TIME_IN_DIFF_LANG__
    <STRING id = "STR_GUI_TIME_AM">AM</STRING>;
    <STRING id = "STR_GUI_TIME_PM">PM</STRING>;

    <STRING id = "STR_GUI_TIME_AM_ENG">AM</STRING>;
    <STRING id = "STR_GUI_TIME_PM_ENG">PM</STRING>;
#endif 

#if !defined(__MMI_BASIC_UI_STYLE__)
    <STRING id = "STR_DOW_SUNDAY">S</STRING>;
    <STRING id = "STR_DOW_MONDAY">M</STRING>;
    <STRING id = "STR_DOW_TUESDAY">T</STRING>;
    <STRING id = "STR_DOW_WEDNESDAY">W</STRING>;
    <STRING id = "STR_DOW_THURSDAY">T</STRING>;
    <STRING id = "STR_DOW_FRIDAY">F</STRING>;
    <STRING id = "STR_DOW_SATURDAY">S</STRING>;
#endif /* __MMI_BASIC_UI_STYLE__ */

#ifdef __MMI_INLINE_ITEM_DOW__    
    <STRING id = "WGUI_CATEGORY_ON_STRING_ID">On</STRING>;
#endif

#if 1 /*!defined(__COSMOS_MMI__)*/
#ifdef __MMI_SLIM_IMG_RES__
    <IMAGE id = "WGUI_VOLUME_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_BG.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_FILL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_FILL.png"</IMAGE>;
#elif defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "WGUI_VOLUME_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC_LOUDSPEAKER.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_PROGRESS_ON">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC_VOLUME.9slice.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_PROGRESS_OFF">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC_BG.9slice.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL0">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC00.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC01.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC02.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC03.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL4">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC04.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL5">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC05.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL6">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC06.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL7">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC07.png"</IMAGE>;
#else /*__MMI_SLIM_IMG_RES__*/
    <IMAGE id = "WGUI_VOLUME_LEVEL0">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC00.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC01.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC02.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC03.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL4">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC04.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL5">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC05.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL6">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC06.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_LEVEL7">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_SC07.png"</IMAGE>;
#endif /*__MMI_SLIM_IMG_RES__*/

#if !defined(__MMI_SLIM_IMG_RES__) && !defined(__MMI_FTE_SUPPORT__)
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    <IMAGE id = "WGUI_VOLUME_UP_UP_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_up_up.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_UP_DOWN_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_up_down.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_UP_DISABLE_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_up_up_dis.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_DOWN_UP_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_down_up.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_DOWN_DOWN_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_down_down.png"</IMAGE>;
    <IMAGE id = "WGUI_VOLUME_DOWN_DISABLE_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_down_up_dis.png"</IMAGE>;
#endif /*__MMI_WALLPAPER_ON_BOTTOM__*/
#endif
#endif /*__COSMOS_MMI__*/
    
#ifdef __MMI_FTE_SUPPORT__
    //<IMAGE id = "WGUI_SLIDE_CONTROL_BG_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\MAP.9slice.png"</IMAGE>;
    //<IMAGE id = "WGUI_SLIDE_CONTROL_FOCUSE_BG_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\MAP_highlight.9slice.png"</IMAGE>;
    //<IMAGE id = "WGUI_SLIDE_CONTROL_SI_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\INDICATE.png"</IMAGE>;
    //<IMAGE id = "WGUI_SLIDE_CONTROL_FOCUSE_SI_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\INDICATE_highligh.png"</IMAGE>;
#else 
   #if defined(__MMI_MAINLCD_96X64__) 
      <IMAGE id = "WGUI_SLIDE_CONTROL_BG_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\SliderBar.bmp"</IMAGE>;
      <IMAGE id = "WGUI_SLIDE_CONTROL_SI_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\Scroller.bmp"</IMAGE>;
   #else
      <IMAGE id = "WGUI_SLIDE_CONTROL_BG_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\MAP.9slice.png"</IMAGE>;
      <IMAGE id = "WGUI_SLIDE_CONTROL_SI_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Valuemap\\\\INDICATE.BMP"</IMAGE>;
   #endif
#endif 


#ifdef SVG12_SUPPORT
    <IMAGE id = "IMG_SVG_DEFAULT_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\FileManager\\\\svg_tiny_logo.svg"</IMAGE>;
#endif

    
#if defined(__MMI_TOUCH_DIAL_SCREEN__)

#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__

#if defined(__MMI_CAT_VIDEO_CALL__) && !defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMG_DIALING_SCREEN">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\4KEY_DUALMODE_TH_DIALING_SCREEN.BMP"</IMAGE>;
#else /* __MMI_CAT_VIDEO_CALL__ */
#if defined(__MMI_FTE_SUPPORT__)
    #if !defined(__MMI_FWUI_SLIM__)
    	<IMAGE id = "IMG_DIALING_SCREEN">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_SCREEN.9slice.png"</IMAGE>;
    #endif /*__MMI_FWUI_SLIM__*/
#else /* defined(__MMI_FTE_SUPPORT__) */
    <IMAGE id = "IMG_DIALING_SCREEN">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_SCREEN.BMP"</IMAGE>;
#endif /* defined(__MMI_FTE_SUPPORT__) */
#endif /* __MMI_CAT_VIDEO_CALL__ */

#if defined(__MMI_SLIM_IMG_RES__) && defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMG_DIALING_P">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_P.9slice.png"</IMAGE>;
#else /* __MMI_SLIM_IMG_RES__ && __MMI_MAINLCD_240X320__ && !__MMI_FTE_SUPPORT__ */ 
    <IMAGE id = "IMG_DIALING_KEY_0">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY0.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_1">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY1.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_2">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY2.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_3">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY3.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_4">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY4.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_5">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY5.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_6">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY6.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_7">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY7.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_8">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY8.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_9">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY9.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_HASH">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY_HASH.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_STAR">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_KEY_STAR.PNG"</IMAGE>;
#endif /* __MMI_SLIM_IMG_RES__ && __MMI_MAINLCD_240X320__ && !__MMI_FTE_SUPPORT__ */
#else   
#if defined(__MMI_CAT_VIDEO_CALL__) && !defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMG_DIALING_SCREEN">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\3KEY_TH_DIALING_SCREEN.BMP"</IMAGE>;
#else /* __MMI_CAT_VIDEO_CALL__ && !__MMI_FTE_SUPPORT__ */
#if defined(__MMI_FTE_SUPPORT__)
    #if !defined(__MMI_FWUI_SLIM__)
    	<IMAGE id = "IMG_DIALING_SCREEN">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_SCREEN.9slice.png"</IMAGE>;
    #endif /*__MMI_FWUI_SLIM__*/
#else /* __MMI_FTE_SUPPORT__ */
    <IMAGE id = "IMG_DIALING_SCREEN">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_SCREEN.BMP"</IMAGE>;
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_CAT_VIDEO_CALL__ && !__MMI_FTE_SUPPORT__ */

 #if defined(__MMI_SLIM_IMG_RES__) && defined(__MMI_MAINLCD_240X320__) && !defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMG_DIALING_P">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_P.9slice.png"</IMAGE>;
#else /* __MMI_SLIM_IMG_RES__ && __MMI_MAINLCD_240X320__ && !__MMI_FTE_SUPPORT__ */ 
    <IMAGE id = "IMG_DIALING_KEY_0">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY0.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_1">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY1.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_2">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY2.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_3">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY3.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_4">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY4.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_5">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY5.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_6">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY6.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_7">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY7.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_8">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY8.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_9">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY9.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_HASH">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY_HASH.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_STAR">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_KEY_STAR.PNG"</IMAGE>;
#endif /* __MMI_SLIM_IMG_RES__ && __MMI_MAINLCD_240X320__ && !__MMI_FTE_SUPPORT__ */
#endif  

#if defined (__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)


#ifdef __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__

#if defined(__MMI_CAT_VIDEO_CALL__) && !defined(__MMI_FTE_SUPPORT__)

    <IMAGE id = "IMG_DIALING_KEY_PHB">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\4KEY_DUALMODE_TH_DIALING_PHONEBOOK.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\4KEY_DUALMODE_TH_DIALING_CALL.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_SLAVE">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\4KEY_DUALMODE_TH_DIALING_CALL_SLAVE.PNG"</IMAGE>;
#if !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_360X640__) && !defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMG_DIALING_KEY_PHB_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\4KEY_DUALMODE_TH_DIALING_PHONEBOOK_DISABLED.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\4KEY_DUALMODE_TH_DIALING_CALL_DISABLED.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_SLAVE_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\4KEY_DUALMODE_TH_DIALING_CALL_SLAVE_DISABLED.PNG"</IMAGE>;
#endif  /*!defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_360X640__) && !defined(__MMI_FTE_SUPPORT__)*/

    <IMAGE id = "IMG_DIALING_KEY_VIDEO">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\4KEY_DUALMODE_TH_DIALING_CALL.PNG"</IMAGE>;
#if !defined(__MMI_MAINLCD_320X480__)
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\4KEY_DUALMODE_TH_DIALING_CALL_DISABLED.PNG"</IMAGE>;
#endif  /* __MMI_MAINLCD_320X480__ */

#else /* __MMI_CAT_VIDEO_CALL__ && !__MMI_FTE_SUPPORT__ */

    <IMAGE id = "IMG_DIALING_KEY_PHB">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_PHONEBOOK.PNG"</IMAGE>;
 #if (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
    <IMAGE id = "IMG_DIALING_KEY_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_SLAVE">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL_SLAVE.PNG"</IMAGE>;
#else 
    <IMAGE id = "IMG_DIALING_KEY_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_CALL.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_EMERGENCY_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_EMERGENCY_CALL.PNG"</IMAGE>;
#endif 
#if !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_360X640__) && !defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMG_DIALING_KEY_PHB_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_PHONEBOOK_DISABLED.PNG"</IMAGE>;
#if (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
    <IMAGE id = "IMG_DIALING_KEY_CALL_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL_DISABLED.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_SLAVE_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_CALL_SLAVE_DISABLED.PNG"</IMAGE>;
#else 
    <IMAGE id = "IMG_DIALING_KEY_CALL_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_CALL_DISABLED.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_EMERGENCY_CALL_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_EMERGENCY_CALL_DISABLED.PNG"</IMAGE>;
#endif 
#endif  /*!defined(__MMI_MAINLCD_320X480__)&& !defined(__MMI_MAINLCD_360X640__) && !defined(__MMI_FTE_SUPPORT__)*/

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
#ifdef __MMI_CAT_VIDEO_CALL__
    <IMAGE id = "IMG_DIALING_KEY_VIDEO">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\3KEY_TH_DIALING_CALL_Video.png"</IMAGE>;
#if !defined(__MMI_MAINLCD_320X480__)
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\3KEY_TH_DIALING_CALL_Video_DIS.png"</IMAGE>;
#endif  /* __MMI_MAINLCD_320X480__ */
#endif /* __MMI_CAT_VIDEO_CALL__ */
#endif 

#endif /* __MMI_CAT_VIDEO_CALL__ */

#else /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */

#if defined(__MMI_CAT_DIALER_3_FUNC_KEY__)

    <IMAGE id = "IMG_DIALING_KEY_PHB">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\3KEY_TH_DIALING_PHONEBOOK.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\3KEY_TH_DIALING_CALL.PNG"</IMAGE>;
#if !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_360X640__) && !defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMG_DIALING_KEY_PHB_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\3KEY_TH_DIALING_PHONEBOOK_DISABLED.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\3KEY_TH_DIALING_CALL_DISABLED.PNG"</IMAGE>;
#endif /* !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_360X640__) && !defined(__MMI_FTE_SUPPORT__) */

#ifdef __MMI_CAT_VIDEO_CALL__
    <IMAGE id = "IMG_DIALING_KEY_VIDEO">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\3KEY_TH_DIALING_CALL_Video.png"</IMAGE>;
#if !defined(__MMI_MAINLCD_320X480__)
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\3KEY_TH_DIALING_CALL_Video_DIS.png"</IMAGE>;
#endif  /* __MMI_MAINLCD_320X480__ */
#endif /* __MMI_CAT_VIDEO_CALL__ */

#else /* __MMI_CAT_DIALER_3_FUNC_KEY__ */

#if (defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__))
#ifdef __MMI_CAT_VIDEO_CALL__
    <IMAGE id = "IMG_DIALING_KEY_VIDEO">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\3KEY_TH_DIALING_CALL_Video.png"</IMAGE>;
#if !defined(__MMI_MAINLCD_320X480__)
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\3KEY_TH_DIALING_CALL_Video_DIS.png"</IMAGE>;
#endif  /* __MMI_MAINLCD_320X480__ */
#endif /* __MMI_CAT_VIDEO_CALL__ */
#endif 

    <IMAGE id = "IMG_DIALING_KEY_PHB">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_PHONEBOOK.PNG"</IMAGE>;
#if (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
    <IMAGE id = "IMG_DIALING_KEY_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_CALL.PNG"</IMAGE>;
#else 
    <IMAGE id = "IMG_DIALING_KEY_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_CALL.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_EMERGENCY_CALL">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_EMERGENCY_CALL.PNG"</IMAGE>;
#endif 
#if !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_360X640__) && !defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMG_DIALING_KEY_PHB_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_PHONEBOOK_DISABLED.PNG"</IMAGE>;
#if (!(defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)))
    <IMAGE id = "IMG_DIALING_KEY_CALL_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\TH_DIALING_CALL_DISABLED.PNG"</IMAGE>;
#else 
    <IMAGE id = "IMG_DIALING_KEY_CALL_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\TH_DIALING_CALL_DISABLED.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_EMERGENCY_CALL_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_EMERGENCY_CALL_DISABLED.PNG"</IMAGE>;
#endif 
#endif /* !defined(__MMI_MAINLCD_320X480__) && !defined(__MMI_MAINLCD_360X640__) && !defined(__MMI_FTE_SUPPORT__) */

#endif /* __MMI_CAT_DIALER_3_FUNC_KEY__ */

#endif  /* __DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__ */


#endif  /* __MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__ */


#if defined(__MMI_FTE_SUPPORT__)

#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)
#define DIALING_SCREEN_PATH     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\"
#else 
#define DIALING_SCREEN_PATH     CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\"
#endif 

    <IMAGE id = "IMG_DIALING_KEY_0_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY0_down.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_1_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY1_down.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_2_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY2_down.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_3_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY3_down.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_4_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY4_down.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_5_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY5_down.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_6_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY6_down.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_7_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY7_down.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_8_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY8_down.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_9_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY9_down.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_HASH_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY_HASH_down.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_STAR_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY_STAR_down.PNG"</IMAGE>;

    <IMAGE id = "IMG_DIALING_KEY_BUTTON_UP">DIALING_SCREEN_PATH"TH_DIALING_KEY.9slice.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_BUTTON_DOWN">DIALING_SCREEN_PATH"TH_DIALING_KEY_DOWN.9slice.PNG"</IMAGE>;

#if defined(__MMI_TOUCH_DIAL_SCREEN_WITH_FUNCTION__)

#if defined(__DUALMODE_TOUCH_DIAL_SCREEN_WITH_SLAVE_FUNCTION__)

    <IMAGE id = "IMG_DIALING_KEY_PHB_BUTTON_UP">DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_PHB_BUTTON_DOWN">DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY_DOWN.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_PHB_BUTTON_DISABLED">DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY_DISABLED.9slice.png"</IMAGE>;
    
    <IMAGE id = "IMG_DIALING_KEY_CALL_BUTTON_UP">DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_CALL_KEY.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_BUTTON_DOWN">DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_CALL_KEY_DOWN.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_BUTTON_DISABLED">DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_CALL_KEY_DISABLED.9slice.png"</IMAGE>;

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
    <IMAGE id = "IMG_DIALING_KEY_EMERGENCY_CALL_BUTTON_UP">DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_EMERGENCY_CALL_KEY.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_EMERGENCY_CALL_BUTTON_DOWN">DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_EMERGENCY_CALL_KEY_DOWN.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_EMERGENCY_CALL_BUTTON_DISABLED">DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_EMERGENCY_CALL_KEY_DISABLED.9slice.png"</IMAGE>;
#if defined(__MMI_CAT_VIDEO_CALL__)
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_BUTTON_UP">DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_CALL_KEY.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_BUTTON_DOWN">DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_CALL_KEY_DOWN.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_BUTTON_DISABLED">DIALING_SCREEN_PATH"DUALMODE_TH_DIALING_CALL_KEY_DISABLED.9slice.png"</IMAGE>; 
#endif /* __MMI_CAT_VIDEO_CALL__ */
#endif 

#else 

#if defined(__MMI_CAT_DIALER_3_FUNC_KEY__) 

    <IMAGE id = "IMG_DIALING_KEY_PHB_BUTTON_UP">DIALING_SCREEN_PATH"3KEY_TH_DIALING_PHONEBOOK_KEY.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_PHB_BUTTON_DOWN">DIALING_SCREEN_PATH"3KEY_TH_DIALING_PHONEBOOK_KEY_DOWN.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_PHB_BUTTON_DISABLED">DIALING_SCREEN_PATH"3KEY_TH_DIALING_PHONEBOOK_KEY_DISABLED.png"</IMAGE>;

    <IMAGE id = "IMG_DIALING_KEY_CALL_BUTTON_UP">DIALING_SCREEN_PATH"3KEY_TH_DIALING_CALL_KEY.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_BUTTON_DOWN">DIALING_SCREEN_PATH"3KEY_TH_DIALING_CALL_KEY_DOWN.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_BUTTON_DISABLED">DIALING_SCREEN_PATH"3KEY_TH_DIALING_CALL_KEY_DISABLED.PNG"</IMAGE>;

    <IMAGE id = "IMG_DIALING_KEY_VIDEO_BUTTON_UP">DIALING_SCREEN_PATH"3KEY_TH_DIALING_CALL_KEY.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_BUTTON_DOWN">DIALING_SCREEN_PATH"3KEY_TH_DIALING_CALL_KEY_DOWN.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_BUTTON_DISABLED">DIALING_SCREEN_PATH"3KEY_TH_DIALING_CALL_KEY_DISABLED.PNG"</IMAGE>;    

#else /* __MMI_CAT_DIALER_3_FUNC_KEY__ */

    <IMAGE id = "IMG_DIALING_KEY_PHB_BUTTON_UP">DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_PHB_BUTTON_DOWN">DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY_DOWN.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_PHB_BUTTON_DISABLED">DIALING_SCREEN_PATH"TH_DIALING_PHONEBOOK_KEY_DISABLED.9slice.png"</IMAGE>;
    
    <IMAGE id = "IMG_DIALING_KEY_CALL_BUTTON_UP">DIALING_SCREEN_PATH"TH_DIALING_CALL_KEY.9slice.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_BUTTON_DOWN">DIALING_SCREEN_PATH"TH_DIALING_CALL_KEY_DOWN.9slice.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_CALL_BUTTON_DISABLED">DIALING_SCREEN_PATH"TH_DIALING_CALL_KEY_DISABLED.9slice.PNG"</IMAGE>;

#if defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__) || defined(__MMI_DIALER_DYNAMIC_CALL_UI__)
#if defined(__MMI_CAT_VIDEO_CALL__)
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_BUTTON_UP">DIALING_SCREEN_PATH"3KEY_TH_DIALING_CALL_KEY.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_BUTTON_DOWN">DIALING_SCREEN_PATH"3KEY_TH_DIALING_CALL_KEY_DOWN.PNG"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_VIDEO_BUTTON_DISABLED">DIALING_SCREEN_PATH"3KEY_TH_DIALING_CALL_KEY_DISABLED.PNG"</IMAGE>; 
#endif /* __MMI_CAT_VIDEO_CALL__ */
    <IMAGE id = "IMG_DIALING_KEY_EMERGENCY_CALL_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_EMERGENCY_CALL_KEY.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_EMERGENCY_CALL_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_EMERGENCY_CALL_KEY_DOWN.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_DIALING_KEY_EMERGENCY_CALL_BUTTON_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\DUALMODE_TH_DIALING_EMERGENCY_CALL_KEY_DISABLED.9slice.png"</IMAGE>;
#endif 
#endif /* __MMI_CAT_DIALER_3_FUNC_KEY__ */


#endif 

#endif 

#endif 


#endif 

#if defined(__MMI_FTE_SUPPORT__) && defined(__SLIM_UCM__)
    <IMAGE id="IMG_ID_UCM_LOCK_ICON_UP_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock_bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_UCM_LOCK_ICON_DOWN_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Lock\\\\CL_lock_down_bg.9slice.png"</IMAGE>
#endif /*defined(__MMI_FTE_SUPPORT__) && defined(__SLIM_UCM__)*/
	
#if defined(__MMI_MAINLCD_320X480__)
    <IMAGE id = "IMG_CALLING_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Answer\\\\answer_up.png"</IMAGE>;
    <IMAGE id = "IMG_CALLING_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Answer\\\\answer_down.png"</IMAGE>;
    <IMAGE id = "IMG_CALLING_BUTTON_DISABLE">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Answer\\\\answer_disable.png"</IMAGE>;
#endif 

#ifdef __MMI_SCREEN_ROTATE__
    <IMAGE id = "IMG_SCREEN_ROTATE_TITLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Horizontal\\\\Rotated_title.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCREEN_ROTATE_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Horizontal\\\\Rotated_bkgrnd.gif"</IMAGE>; 
    <IMAGE id = "IMG_SCREEN_ROTATE_TOP_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Horizontal\\\\rotate_top.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCREEN_ROTATE_BOTTOM_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Horizontal\\\\rotate_bottom.bmp"</IMAGE>;
#endif 

#ifdef __MMI_TOUCH_SCREEN__
    #ifndef __LOW_COST_SUPPORT_COMMON__
    
    <IMAGE id = "IMG_PEN_WAITING_LONGPRESS">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Touch\\\\TH_LongPress.gif"</IMAGE>;       
    #endif

#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)
#if defined(__MMI_MAINLCD_320X480__)

    
    <IMAGE id = "IMG_VKBD_STANDARD">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_STANDARD.PNG"</IMAGE>;   
    <IMAGE id = "IMG_VKBD_EXTENDED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_EXTENDED.PNG"</IMAGE>;   
    <IMAGE id = "IMG_VKBD_TRAY">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_TRAY.PNG"</IMAGE>;
    <IMAGE id = "IMG_VKBD_NUM_TRAY">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_NUM_TRAY.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CHINESE_SYMBOL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CHINESE_SYMBOL.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_NUMBER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_NUM.PNG"</IMAGE>;
    <IMAGE id = "IMG_VKBD_PINYIN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_PINYIN.PNG"</IMAGE>;
    <IMAGE id = "IMG_VKBD_PINYIN_DISPAREA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_PINYIN_DISPAREA.PNG"</IMAGE>;

#if defined(__MMI_LANG_KAZAKH__)
  <IMAGE id = "IMG_VKBD_FARSI_HUNGARIAN_ARABICSYMBOL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_HUNGARIAN_FARSI.PNG"</IMAGE>;
#endif 

#if defined(__MMI_LANG_TR_CHINESE__)
    <IMAGE id = "IMG_VKBD_BOPOMO">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_BOPOMO.PNG"</IMAGE>;
    <IMAGE id = "IMG_VKBD_BOPOMO_DISPAREA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_BOPOMO_DISPAREA.PNG"</IMAGE>;
#endif 

#if (defined( __MMI_LANG_BULGARIAN__) || defined(__MMI_LANG_RUSSIAN__) || defined(__MMI_LANG_UKRAINIAN__) || defined(__MMI_LANG_THAI__)|| defined(__MMI_LANG_SERBIAN__))
    <IMAGE id = "IMG_VKBD_THAI">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_THAI.PNG"</IMAGE>;
#endif 

#if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_URDU__)
    <IMAGE id = "IMG_VKBD_ARABIC">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_Cyrillic.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_FARSI_HUNGARIAN_ARABICSYMBOL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_THAI.png"</IMAGE>;
#endif

    <IMAGE id = "IMG_VKBD_EUROPEAN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_European.png"</IMAGE>;
    
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_NUM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\123.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_ABC">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\abc.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_ABC">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ABCABC.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_EN_SYM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\EnglishSymbol.png"</IMAGE>;

#if defined(__MMI_LANG_TR_CHINESE__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_BOPOMO">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\bopomo.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_TR_STROKE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\tr_stroke.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_SM_CHINESE__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_PINYIN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\piyin.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_SM_STROKE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\sm_stroke.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_HK_CHINESE__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_HK_STROKE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\hk_stroke.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_TR_CHINESE__) || defined(__MMI_LANG_SM_CHINESE__) || defined(__MMI_LANG_HK_CHINESE__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CH_SYM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ChineseSymbol.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_ARABIC__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_AR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\AR.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_AR_NUM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\AR123.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_URDU__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_UR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\UR.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_BULGARIAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\bg.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\BGBG.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_KOREAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_KR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\kr.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_GERMAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_DE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\de.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_DE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\DEDE.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_AZERBAIJANI__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_AZ">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\az.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_AZ">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\AZAZ.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_CATALAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ca.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_CA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\CACA.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_HAUSA__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_HA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ha.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_HA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HAHA.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_KAZAKH__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_KK">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\kk.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_KK">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\KKKK.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_MACEDONIAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_MK">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\mk.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_MK">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\MKMK.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_SESOTHO__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_ST">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\st.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_ST">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\STST.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_TAGALOG__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_TL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\tl.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_TL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\TLTL.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_YORUBA__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_YO">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\yo.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_YO">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\YOYO.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_SERBIAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_SR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\SR.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_SR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\SRSR.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_ICELANDIC__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_IS">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\is.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_IS">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ISIS.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_GALICIAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_GL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\gl.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_GL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\GLGL.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_BASQUE__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_EU">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\eu.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_EU">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\EUEU.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_IGBO__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_IG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ig.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_IG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\IGIG.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_FILIPINO__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_FIL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\fil.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_FIL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\FILFIL.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_IRISH__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_IR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ga.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_IR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\GAGA.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_ALBANIAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_SQ">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\sq.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_SQ">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\SQSQ.png"</IMAGE>;
#endif


#if defined(__MMI_LANG_SPANISH__) || defined(__MMI_LANG_SA_SPANISH__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_ES">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\es.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_ES">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ESES.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_HINDI__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_HI">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HIHI.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_MARATHI__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_MA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\MRMR.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_PUNJABI__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_PU">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\PAPA.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_KANNADA__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_KN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\KN.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_MALAYALAM__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_MALAYALAM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ML.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_LAO__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_LAO">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\LO.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_KHMER__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_KHMER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\KH.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_MYANMAR__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_MYANMAR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\MY.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_TAMIL__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_TA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\TA.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_TELUGU__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_TE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\TE.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_ORIYA__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_OR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\OR.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_GUJARATI__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_GU">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\GU.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_BENGALI__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_BE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\BNBN.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_ASSAMESE__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_AS">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\AS.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_FRENCH__) || defined(__MMI_LANG_CA_FRENCH__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_FR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\fr.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_FR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\FRFR.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_ITALIAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_IT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\it.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_IT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ITIT.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_POLISH__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_PO">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\pl.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_PO">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\PLPL.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_PORTUGUESE__) || defined(__MMI_LANG_SA_PORTUGUESE__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_PT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\pt.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_PT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\PTPT.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_RUSSIAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_RU">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ru.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_RU">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\RURU.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_TURKISH__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_TR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\tr.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_TR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\TRTR.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_UKRAINIAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_UK">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\uk.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_UK">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\UKUK.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_VIETNAMESE__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_VI">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\vi.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_VI">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\VIVI.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_MALAY__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_ML">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\ms.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_ML">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\MSMS.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_INDONESIAN__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\id.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_CAP_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\IDID.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_THAI__)
    <IMAGE id = "IMG_VKBD_CUSTOM_IM_ICON_TH">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\thai.png"</IMAGE>;
#endif
#if defined(__MMI_INDIC_VK__)
    <IMAGE id = "IMG_VKBD_CUSTOM_INDIC_SYMBPICKER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_SYMBPICKER.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_INDIC_CAPSON">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_CAPS_ON.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_INDIC_CAPSOFF">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_CAPS_OFF.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_INDIC_SYMBOLS">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_SYMBOLS.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_INDIC_BACK">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_BACK.png"</IMAGE>;   
#endif

    <IMAGE id = "IMG_VKBD_CUSTOM_HIDE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HIDE.png"</IMAGE>;

    <IMAGE id = "IMG_VKBD_CUSTOM_HIDE_SMALL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HAND_SMALL.png"</IMAGE>;

    <IMAGE id = "IMG_VKBD_CUSTOM_SHOW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SHOW.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_SWITCH_KEYBOARD">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_KEYBOARD.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_SWITCH_HANDWRITING">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HAND.png"</IMAGE>;    
    <IMAGE id = "IMG_VKBD_CUSTOM_BACKSPACE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_BAKSPACE.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_CAPSLOCK">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_CAPS.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_SPACE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SPACE.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_SYMBPICKER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SYMBPICKER.png"</IMAGE>;
#if defined(__MMI_VKBD_EUROPEAN_SUPPORT__)
    <IMAGE id = "IMG_VKBD_CUSTOM_EUROSYMB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_EUROSYMB.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_VKBD_CUSTOM_ENTER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_ENTER.png"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_BRACKET">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_BRACKET.png"</IMAGE>;


#else 

    
    <IMAGE id = "IMG_VKBD_STANDARD">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_STANDARD.PNG"</IMAGE>;   
    <IMAGE id = "IMG_VKBD_EXTENDED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_EXTENDED.PNG"</IMAGE>;   
    <IMAGE id = "IMG_VKBD_TRAY">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_TRAY.PNG"</IMAGE>;
    <IMAGE id = "IMG_VKBD_NUMBER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_NUM.PNG"</IMAGE>;
    <IMAGE id = "IMG_VKBD_PINYIN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_PINYIN.PNG"</IMAGE>;
    <IMAGE id = "IMG_VKBD_PINYIN_DISPAREA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_PINYIN_DISPAREA.PNG"</IMAGE>;
    #if defined(__MMI_LANG_TR_CHINESE__)
    <IMAGE id = "IMG_VKBD_BOPOMO">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_BOPOMO.PNG"</IMAGE>;
    <IMAGE id = "IMG_VKBD_BOPOMO_DISPAREA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_BOPOMO_DISPAREA.PNG"</IMAGE>;
    #endif 
#if (defined(__MMI_LANG_CZECH__) || defined(__MMI_LANG_SLOVAK__) || defined(__MMI_LANG_LITHUANIAN__)  || defined(__MMI_LANG_ESTONIAN__))
  <IMAGE id = "IMG_VKBD_CZECH">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CZECH_SLOVAK.PNG"</IMAGE>;
#endif 
#ifdef __MMI_LANG_HEBREW__
  <IMAGE id = "IMG_VKBD_HEBREW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_HEBREW.PNG"</IMAGE>;
#endif 
#if (defined( __MMI_LANG_BULGARIAN__))
  <IMAGE id = "IMG_VKBD_BULGARIAN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_BULGARIAN.PNG"</IMAGE>;
#endif 
#if (defined(__MMI_LANG_DANISH__) || defined(__MMI_LANG_NORWEGIAN__))
  <IMAGE id = "IMG_VKBD_DANISH_NORWEGIAN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_DANISH_NORWEGIAN.PNG"</IMAGE>;
#endif 
#ifdef __MMI_LANG_GREEK__
  <IMAGE id = "IMG_VKBD_GREEK">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_GREEK.PNG"</IMAGE>;
#endif 
#if (defined(__MMI_LANG_PERSIAN__) || defined(__MMI_LANG_HUNGARIAN__)|| defined(__MMI_LANG_KAZAKH__) || defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_ARMENIAN__)  || defined(__MMI_LANG_URDU__) || defined(__MMI_LANG_LATVIAN__))
  <IMAGE id = "IMG_VKBD_FARSI_HUNGARIAN_ARABICSYMBOL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_HUNGARIAN_FARSI.PNG"</IMAGE>;
#endif 
#ifdef __MMI_LANG_PERSIAN__
  <IMAGE id = "IMG_VKBD_FARSI_SYMBOL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_FARSI_SYMBOL.PNG"</IMAGE>;
#endif 
#if (defined(__MMI_LANG_FINNISH__) || defined(__MMI_LANG_SWEDISH__))
  <IMAGE id = "IMG_VKBD_FINNISH_SWEDISH">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_FINNISH_SWEDISH.PNG"</IMAGE>;
#endif 
#ifdef __MMI_LANG_VIETNAMESE__
  <IMAGE id = "IMG_VKBD_VIETNAMESE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_VIETNAMESE.PNG"</IMAGE>;
#endif
#if defined(__MMI_LANG_ARABIC__) || defined(__MMI_LANG_GEORGIAN__)
  <IMAGE id = "IMG_VKBD_ARABIC">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_ARABIC.PNG"</IMAGE>;
#endif
#if defined(__MMI_LANG_THAI__)
  <IMAGE id = "IMG_VKBD_THAI">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_THAI.PNG"</IMAGE>;
#endif
#if defined(__MMI_INDIC_VK_TAMIL__)
  <IMAGE id = "IMG_VKBD_TAMIL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_TAMIL.PNG"</IMAGE>;
#endif
#if defined(__MMI_INDIC_VK_PUNJABI__) && defined (__MMI_MAINLCD_128X160__)
  <IMAGE id = "IMG_VKBD_PUNJABI_128x160">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_PUNJABI_128x160.png"</IMAGE>;
#endif
#if defined(__MMI_LANG_UKRAINIAN__)
  <IMAGE id = "IMG_VKBD_UKRAINIAN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_UKRAINIAN.PNG"</IMAGE>;
#endif

#if defined(__MMI_INDIC_VK__)
    <IMAGE id = "IMG_VKBD_CUSTOM_INDIC_SYMBPICKER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_SYMBPICKER.BMP"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_INDIC_CAPSON">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_CAPS_ON.BMP"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_INDIC_CAPSOFF">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_CAPS_OFF.BMP"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_INDIC_SYMBOLS">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_SYMBOLS.BMP"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_INDIC_BACK">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_INDIC_BACK.BMP"</IMAGE>;   
#endif

    <IMAGE id = "IMG_VKBD_CUSTOM_HIDE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HIDE.BMP"</IMAGE>;

    <IMAGE id = "IMG_VKBD_CUSTOM_HIDE_SMALL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HAND_SMALL.BMP"</IMAGE>;

    <IMAGE id = "IMG_VKBD_CUSTOM_SHOW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SHOW.BMP"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_SWITCH_KEYBOARD">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_KEYBOARD.BMP"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_SWITCH_HANDWRITING">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_HAND.BMP"</IMAGE>;    
    <IMAGE id = "IMG_VKBD_CUSTOM_BACKSPACE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_BAKSPACE.BMP"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_CAPSLOCK">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_CAPS.BMP"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_SPACE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SPACE.BMP"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_SYMBPICKER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_SYMBPICKER.BMP"</IMAGE>;
#if defined(__MMI_VKBD_EUROPEAN_SUPPORT__)
    <IMAGE id = "IMG_VKBD_CUSTOM_EUROSYMB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_EUROSYMB.BMP"</IMAGE>;
#endif
    <IMAGE id = "IMG_VKBD_CUSTOM_ENTER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_ENTER.BMP"</IMAGE>;
    <IMAGE id = "IMG_VKBD_CUSTOM_BRACKET">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\V_KBD_CUSTOM_BRACKET.BMP"</IMAGE>;
#endif 
#endif




    #ifdef __MMI_VK_POPUP_HINT__ 
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_1__)

        <IMAGE id = "IMG_VKBD_LARGE_ICON_BG_ZOOM_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\vk_large_icon_left.png"</IMAGE>;
        <IMAGE id = "IMG_VKBD_LARGE_ICON_BG_ZOOM_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\vk_large_icon_right.png"</IMAGE>;
#endif
    #endif 
#endif 

#if !defined(__MMI_OP11_MENU_12MATRIX__)
    <IMAGE id = "IMG_SELECTOR_FILLER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\selector_filler.bmp"</IMAGE>;
#endif

#ifdef UI_SCROLLBAR_STYLE_3
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\button_up.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\button_down.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\v_bar_top.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\v_bar_middle.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\v_bar_bottom.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\h_bar_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\h_bar_middle.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style3\\\\h_bar_right.bmp"</IMAGE>;  
#endif 

#if defined(UI_SCROLLBAR_STYLE_7) || defined(UI_SCROLLBAR_WIDER_STYLE_7)

    <IMAGE id = "IMG_SCROLLBAR_V_BAR_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_up.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_m.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_down.png"</IMAGE>;

    <IMAGE id = "IMG_SCROLLBAR_H_BAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_hl.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_hm.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_hr.png"</IMAGE>;

#endif 

#if defined(UI_SCROLLBAR_STYLE_5) || defined(UI_SCROLLBAR_WIDER_STYLE_5)
#ifdef __MMI_TOUCH_SCREEN__
#ifndef __MMI_FTE_SUPPORT__
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_up.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_down.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_UP_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_up_pressed.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_DOWN_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_down_pressed.bmp"</IMAGE>;
#endif
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\v_bar_top.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\v_bar_middle.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\v_bar_bottom.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_BGD">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\v_bar_bg.bmp"</IMAGE>;
    
#ifndef __MMI_FTE_SUPPORT__
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_right.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_LEFT_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_left_pressed.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_RIGHT_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\button_right_pressed.bmp"</IMAGE>;
#endif
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\h_bar_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\h_bar_middle.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\h_bar_right.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_BGD">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5_touch\\\\h_bar_bg.bmp"</IMAGE>;
#else
#ifndef __MMI_FTE_SUPPORT__
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_up.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_down.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_UP_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_up_pressed.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_DOWN_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_down_pressed.bmp"</IMAGE>;
#endif
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\v_bar_top.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\v_bar_middle.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\v_bar_bottom.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_BGD">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\v_bar_bg.bmp"</IMAGE>;
    
#ifndef __MMI_FTE_SUPPORT__
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_right.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_LEFT_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_left_pressed.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_BUTTON_RIGHT_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\button_right_pressed.bmp"</IMAGE>;
#endif
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\h_bar_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\h_bar_middle.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\h_bar_right.bmp"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_BGD">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Style5\\\\h_bar_bg.bmp"</IMAGE>;
#endif
#endif 


#if defined(UI_SCROLLBAR_STYLE_8)

    <IMAGE id = "IMG_SCROLLBAR_V_BAR_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_Top.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_MiddleBG.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_Bottom.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_BGD">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_Middle.png"</IMAGE>;

    <IMAGE id = "IMG_SCROLLBAR_V_BAR_BGD_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_TOP.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_BGD_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_Bottom.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_MiddleDot.png"</IMAGE>;

    <IMAGE id = "IMG_SCROLLBAR_H_BAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_left_H.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_MiddleBG_H.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_right_H.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_BGD">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_Middle_H.png"</IMAGE>;

    <IMAGE id = "IMG_SCROLLBAR_H_BAR_BGD_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_left_H.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_BGD_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollBG_right_H.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\Vodafone_Style\\\\ScrollROCK_MiddleDot_H.png"</IMAGE>;

#endif 


#if defined(UI_SCROLLBAR_STYLE_7)

    <IMAGE id = "IMG_SCROLLBAR_V_BAR_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_up.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_m.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_V_BAR_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_down.png"</IMAGE>;

    <IMAGE id = "IMG_SCROLLBAR_H_BAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_hl.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_hm.png"</IMAGE>;
    <IMAGE id = "IMG_SCROLLBAR_H_BAR_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Scrollbar\\\\style7\\\\indicator_hr.png"</IMAGE>;

#endif 

#if defined(__MMI_IME_FTE_ENHANCE__)
#if defined(__MMI_ZI__) || defined(__MMI_T9__) || defined(__MMI_CSTAR__)|| defined(__MMI_GUOBI__)
#if defined(__COSMOS_MMI__)
    <IMAGE id = "IMG_ID_IME_INDICATOR_BPMF">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\IME\\\\bpmf.png"</IMAGE>;
    <IMAGE id = "IMG_ID_IME_INDICATOR_TR_STROKE">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\IME\\\\tr_Stroke.png"</IMAGE>;
    <IMAGE id = "IMG_ID_IME_INDICATOR_PINYIN">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\IME\\\\pinyin.png"</IMAGE>;
    <IMAGE id = "IMG_ID_IME_INDICATOR_SM_STROKE">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\IME\\\\sm_stroke.png"</IMAGE>;
#else
    <IMAGE id = "IMG_ID_IME_INDICATOR_BPMF">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\Bpmf.png"</IMAGE>;
    <IMAGE id = "IMG_ID_IME_INDICATOR_TR_STROKE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\TR_Stroke.png"</IMAGE>;
    <IMAGE id = "IMG_ID_IME_INDICATOR_PINYIN">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\Pinyin.png"</IMAGE>;
    <IMAGE id = "IMG_ID_IME_INDICATOR_SM_STROKE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\SM_Stroke.png"</IMAGE>;
#endif
#endif
#else
#if defined(__MMI_ZI__)
    <IMAGE id = "WGUI_ZI_EZITEXT_LOGO">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\eZiText_N12px_col.bmp"</IMAGE>;
    <IMAGE id = "WGUI_ZI_EZITEXT_BPMF_LOGO">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\TC_eZiText_Bopomofo_N12px_col.bmp"</IMAGE>;
    <IMAGE id = "WGUI_ZI_EZITEXT_PINYIN_LOGO">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SC_eZiText_Pinyin_N12px_col.bmp"</IMAGE>;
    <IMAGE id = "WGUI_ZI_EZITEXT_SM_STROKE_LOGO">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SC_eZiText_Stroke_N12px_col.bmp"</IMAGE>;
    <IMAGE id = "WGUI_ZI_EZITEXT_TR_STROKE_LOGO">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\TC_eZiText_Stroke_N12px_col.bmp"</IMAGE>;
    <IMAGE id = "WGUI_ZI_EZITEXT_HK_STROKE_LOGO">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\HC_eZiText_Stroke_N12px_col.bmp"</IMAGE>;    
#elif defined(__MMI_T9__)||defined(__MMI_ITAP__)||defined(__MMI_KA__) || defined(__MMI_CSTAR__) || defined(__MMI_GUOBI__)
#if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__))|| (defined(__MMI_GB_TR_CHINESE__) && defined(__MMI_GB_MULTITAP_PHONETIC_INPUT__))
    <IMAGE id = "WGUI_IME_MULTITAP_BPMF_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Multitap BPMF.bmp"</IMAGE>;
#endif
    #if defined(__MMI_MAINLCD_96X64__)
    <IMAGE id = "WGUI_IME_MULTITAP_PINYIN_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\96_64MultitapPinyin.bmp"</IMAGE>;
    #else
    <IMAGE id = "WGUI_IME_MULTITAP_PINYIN_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Multiatp Pinyin.bmp"</IMAGE>;
    #endif
#if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__))
    <IMAGE id = "WGUI_IME_SMART_BPMF_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Smart BPMF.bmp"</IMAGE>;
#endif
    #if defined(__MMI_MAINLCD_96X64__)
    <IMAGE id = "WGUI_IME_SMART_PINYIN_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\96_64SmartPinyin.bmp"</IMAGE>;
    #else
    <IMAGE id = "WGUI_IME_SMART_PINYIN_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Smart Pinyin.bmp"</IMAGE>;
    #endif
    <IMAGE id = "WGUI_IME_SM_STROKE_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Simplified Chinese stroke.bmp"</IMAGE>;
#if (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_STROKE_INPUT__))||(defined(__MMI_T9_HK_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__))
    <IMAGE id = "WGUI_IME_TR_STROKE_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Traditonal Chinese stroke.bmp"</IMAGE>;
#endif
#endif
#endif 
    

#if defined(__MMI_IME_FTE_ENHANCE__)
#if defined(__COSMOS_MMI__)
#if defined (__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
#if defined(__MMI_GUOBI__)
    <IMAGE id = "WGUI_IME_SMART_ENGLISH_IMG">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\IME\\\\smart_amb_guobi.png"</IMAGE>;
#else
    <IMAGE id = "WGUI_IME_SMART_ENGLISH_IMG">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\IME\\\\smart_amb.png"</IMAGE>;
#endif
#endif
#if defined(__MMI_GUOBI__)
    <IMAGE id = "WGUI_INPUT_INFORMATION_ICON1">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\IME\\\\mut_guobi.png"</IMAGE>;
#else
    <IMAGE id = "WGUI_INPUT_INFORMATION_ICON1">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\IME\\\\mut.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_ID_IME_INDICATOR_BG">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\IME\\\\Bg_Ime.9slice.png"</IMAGE>;
#else
#if defined (__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
#if defined(__MMI_GUOBI__)
    <IMAGE id = "WGUI_IME_SMART_ENGLISH_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\Smartamb_guobi.png"</IMAGE>;
#else
    <IMAGE id = "WGUI_IME_SMART_ENGLISH_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\Smartamb.png"</IMAGE>;
#endif
#endif
#if defined(__MMI_GUOBI__)
    <IMAGE id = "WGUI_INPUT_INFORMATION_ICON1">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\MUT_guobi.png"</IMAGE>;
#else
    <IMAGE id = "WGUI_INPUT_INFORMATION_ICON1">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\MUT.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_ID_IME_INDICATOR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons_PNG\\\\IME\\\\Background.9slice.png"</IMAGE>;
#endif
#else
#if defined (__MMI_SMART_ALPHABETIC_INPUT_METHODS__)
    #if defined(__MMI_MAINLCD_96X64__)
    <IMAGE id = "WGUI_IME_SMART_ENGLISH_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\96_64Smart.bmp"</IMAGE>;
    #else
    <IMAGE id = "WGUI_IME_SMART_ENGLISH_IMG">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Smartamb.bmp"</IMAGE>;
    #endif
#endif
    #if defined(__MMI_MAINLCD_96X64__)
    <IMAGE id = "WGUI_INPUT_INFORMATION_ICON1">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\96_64MUT.bmp"</IMAGE>;
    #else
    <IMAGE id = "WGUI_INPUT_INFORMATION_ICON1">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\MUT.BMP"</IMAGE>;
    #endif
#endif
    
#if defined(__MMI_QWERTY_KEYPAD_SUPPORT__)&& defined(__COSMOS_MMI__)
    <IMAGE id = "IMG_IME_QWERTY_FN">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\Edit\\\\SI_fn.bmp"</IMAGE>;
    <IMAGE id = "IMG_IME_QWERTY_FN_LOCK">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\Edit\\\\SI_Afn.bmp"</IMAGE>;
    <IMAGE id = "IMG_IME_QWERTY_SHIFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\Edit\\\\SI_shift.bmp"</IMAGE>;
    <IMAGE id = "IMG_IME_QWERTY_SHIFT_LOCK">CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\Edit\\\\SI_Ashift.bmp"</IMAGE>;
#else
    <IMAGE id = "IMG_IME_QWERTY_FN">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SI_fn.bmp"</IMAGE>;
    <IMAGE id = "IMG_IME_QWERTY_FN_LOCK">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SI_Afn.bmp"</IMAGE>;
    <IMAGE id = "IMG_IME_QWERTY_SHIFT">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SI_shift.bmp"</IMAGE>;
    <IMAGE id = "IMG_IME_QWERTY_SHIFT_LOCK">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\SI_Ashift.bmp"</IMAGE>;
#endif

#ifdef __MMI_FTE_SUPPORT__
    //<IMAGE id = "IMG_INLINE_ML_HIGHLIGHT_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\inline_button_highlight_up.9slice.png"</IMAGE>;
    //<IMAGE id = "IMG_INLINE_ML_NORMAL_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\inline_button_normal_up.9slice.png"</IMAGE>;

    <IMAGE id = "IMG_INLINE_ML_HIGHLIGHT_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\Multiline_editor_highlight.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_INLINE_ML_NORMAL_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\Multiline_editor_normal.9slice.png"</IMAGE>;

    <IMAGE id = "IMG_INLINE_DISPLAY_ONLY_HIGHLIGHT_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\inline_button_highlight_up.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_INLINE_DISPLAY_ONLY_NORMAL_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\inline_button_normal_up.9slice.png"</IMAGE>;
#endif

    <IMAGE id = "IMG_INLINE_BUTTON_HIGHLIGHT_UP_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\inline_button_highlight_up.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_INLINE_BUTTON_NORMAL_UP_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\inline_button_normal_up.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_INLINE_BUTTON_HIGHLIGHT_DOWN_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\Inline_button_highlight_down.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_INLINE_BUTTON_NORMAL_DOWN_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\edit\\\\Inline_button_normal_down.9slice.png"</IMAGE>;

#if defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMG_H_SELECT_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL.png"</IMAGE>;
    <IMAGE id = "IMG_H_SELECT_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR.png"</IMAGE>;
#else
    <IMAGE id = "IMG_H_SELECT_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL.bmp"</IMAGE>;
    <IMAGE id = "IMG_H_SELECT_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR.bmp"</IMAGE>;
#endif

#ifdef __MMI_FTE_SUPPORT__
    <IMAGE id = "RIGHT_RED_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR.png"</IMAGE>;
    <IMAGE id = "LEFT_RED_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL.png"</IMAGE>;
#else
    <IMAGE id = "RIGHT_RED_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR.bmp"</IMAGE>;
    <IMAGE id = "LEFT_RED_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL.bmp"</IMAGE>;
#endif

#ifdef __MMI_FTE_SUPPORT__	
    <IMAGE id = "RIGHT_RED_ARROW_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR.png"</IMAGE>;
    <IMAGE id = "LEFT_RED_ARROW_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL.png"</IMAGE>;
#ifndef __MMI_FWUI_SLIM__
	<IMAGE id = "RIGHT_RED_ARROW_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR_disabled.png"</IMAGE>;
    <IMAGE id = "LEFT_RED_ARROW_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL_disabled.png"</IMAGE>;
#endif
	<IMAGE id = "RIGHT_RED_ARROW_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR_pressed.png"</IMAGE>;
    <IMAGE id = "LEFT_RED_ARROW_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL_pressed.png"</IMAGE>;
#else
#if !defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id = "RIGHT_RED_ARROW_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR.bmp"</IMAGE>;
    <IMAGE id = "LEFT_RED_ARROW_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL.bmp"</IMAGE>;
    <IMAGE id = "RIGHT_RED_ARROW_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR_pressed.bmp"</IMAGE>;
    <IMAGE id = "LEFT_RED_ARROW_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL_pressed.bmp"</IMAGE>;
#endif
    <IMAGE id = "RIGHT_RED_ARROW_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR_disabled.bmp"</IMAGE>;
    <IMAGE id = "LEFT_RED_ARROW_DISABLED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL_disabled.bmp"</IMAGE>;
#endif

#if defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "LEFT_ARROW_DOWN">CUST_IMG_PATH"\\\\MAINLCD\\\\UIElement\\\\Arrow\\\\PV_ARL_pressed.png"</IMAGE>;
    <IMAGE id = "LEFT_ARROW_UP">CUST_IMG_PATH"\\\\MAINLCD\\\\UIElement\\\\Arrow\\\\PV_ARL.png"</IMAGE>;
    <IMAGE id = "RIGHT_ARROW_DOWN">CUST_IMG_PATH"\\\\MAINLCD\\\\UIElement\\\\Arrow\\\\PV_ARR_pressed.png"</IMAGE>;
    <IMAGE id = "RIGHT_ARROW_UP">CUST_IMG_PATH"\\\\MAINLCD\\\\UIElement\\\\Arrow\\\\PV_ARR.png"</IMAGE>;
    // baiwenlin 20130821  
#elif 1//defined(__MMI_MAINLCD_128X64__)||defined(__MMI_MAINLCD_128X36__)||defined(__MMI_MAINLCD_240X240__)
    <IMAGE id = "LEFT_ARROW_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\LEFT_ARROW_DOWN.bmp"</IMAGE>;
    <IMAGE id = "LEFT_ARROW_UP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\LEFT_ARROW_UP.bmp"</IMAGE>;
    <IMAGE id = "RIGHT_ARROW_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\RIGHT_ARROW_DOWN.bmp"</IMAGE>;
    <IMAGE id = "RIGHT_ARROW_UP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\RIGHT_ARROW_UP.bmp"</IMAGE>;
#elif defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_320X240__) || defined(__MMI_MAINLCD_240X400__) || defined ( __MMI_MAINLCD_320X480__) || defined ( __MMI_MAINLCD_360X640__) || defined(__MMI_MAINLCD_240X240__)
#if !defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id = "LEFT_ARROW_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\LEFT_ARROW_DOWN.bmp"</IMAGE>;
    <IMAGE id = "LEFT_ARROW_UP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\LEFT_ARROW_UP.bmp"</IMAGE>;
    <IMAGE id = "RIGHT_ARROW_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\RIGHT_ARROW_DOWN.bmp"</IMAGE>;
    <IMAGE id = "RIGHT_ARROW_UP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\RIGHT_ARROW_UP.bmp"</IMAGE>;
#endif
#endif
#ifndef __MMI_FWUI_SLIM__
    <IMAGE id = "IMG_LEFT_DISABLED_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\CascadingMenu\\\\Arrow_Disable_L.png"</IMAGE>;
    <IMAGE id = "IMG_RIGHT_DISABLED_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\CascadingMenu\\\\Arrow_Disable_R.png"</IMAGE>;
#endif
#ifndef __MMI_TOUCH_DIAL_SCREEN__
    #if (!(defined(__MMI_SLIM_IMG_RES__) || (defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__)))) 
        #if defined(__MMI_MAINLCD_128X64__)
            <IMAGE id = "IMG_DIALING_SCREEN_BG_UP">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_top.png"</IMAGE>;
            <IMAGE id = "IMG_DIALING_SCREEN_BG_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_botton.png"</IMAGE>;
            <IMAGE id = "IMG_DIALING_SCREEN_BG_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_left.png"</IMAGE>;
            <IMAGE id = "IMG_DIALING_SCREEN_BG_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_right.png"</IMAGE>;
        #elif (!defined ( __MMI_MAINLCD_128X128__ ) && !defined ( __MMI_MAINLCD_128X160__ )) 
            #if (defined(MT6223) || defined(MT6223P)) && defined(__MMI_MAINLCD_240X320__)
                <IMAGE id = "IMG_DIALING_SCREEN_BG_UP" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_top.png"</IMAGE>;
                <IMAGE id = "IMG_DIALING_SCREEN_BG_DOWN" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_botton.png"</IMAGE>;
                <IMAGE id = "IMG_DIALING_SCREEN_BG_LEFT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_left.png"</IMAGE>;
                <IMAGE id = "IMG_DIALING_SCREEN_BG_RIGHT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_right.png"</IMAGE>;
            #else
                <IMAGE id = "IMG_DIALING_SCREEN_BG_UP">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_top.png"</IMAGE>;
                <IMAGE id = "IMG_DIALING_SCREEN_BG_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_botton.png"</IMAGE>;
                <IMAGE id = "IMG_DIALING_SCREEN_BG_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_left.png"</IMAGE>;
                <IMAGE id = "IMG_DIALING_SCREEN_BG_RIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\idle_right.png"</IMAGE>;
            #endif    
        #endif /*defined(__MMI_MAINLCD_128X64__)*/
    #else /*(!(defined(__MMI_SLIM_IMG_RES__) || (defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__)))) */
    	#if defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__)
            <IMAGE id = "IMG_DIALING_SCREEN_BG_SLIM">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DualSIM\\\\Idle_fte_key_only.9slice.png"</IMAGE>;
        #endif /*defined(__MMI_FTE_SUPPORT__) && !defined(__MMI_TOUCH_SCREEN__)*/
    #endif
#endif

#ifdef __MMI_UI_DALMATIAN_EDITOR__
    <IMAGE id = "IMG_EDITOR_DALMATIAN">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Dalmatian\\\\EDITOR_DALMATIAN_IMAGE.gif"</IMAGE>;
    <IMAGE id = "IMG_EDITOR_DALMATIAN_SMALL">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\Dalmatian\\\\EDITOR_DALMATIAN_IMAGE_SMALL.gif"</IMAGE>;
#endif

//#if defined(__COSMOS_MMI__) || defined(__MMI_FTE_SUPPORT__)
//    <IMAGE id = "IMG_SOFTKEY_BAR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\softkey\\\\softkey.9slice.png"</IMAGE>;
//#else
//    <IMAGE id = "IMG_SOFTKEY_BAR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\softkey\\\\softkey.bmp"</IMAGE>;
//#endif

#ifdef __MMI_SUBLCD__
    <IMAGE id = "IMG_SUBLCD_ANALOG_CLOCK">CUST_IMG_PATH"\\\\SubLCD\\\\Active\\\\SB_Analog.gif"</IMAGE>;
#endif
#ifdef __MMI_EDITABLE_AUDIO_EQUALIZER__
    <IMAGE id = "SOUND_EFFECT_AUDIO_EQ_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\AudioEqualizer\\\\EQ_BG.gif"</IMAGE>;
    <IMAGE id = "SOUND_EFFECT_AUDIO_EQ_ACTIVE_BAR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\AudioEqualizer\\\\EQ_BAR.bmp"</IMAGE>;
    <IMAGE id = "SOUND_EFFECT_AUDIO_EQ_VAL_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\AudioEqualizer\\\\EQ_indicator.bmp"</IMAGE>;
#endif
#ifdef __MMI_TOUCH_SCREEN__
        #endif  
    <IMAGE id = "IMG_CSK_DIAL_ICON">CUST_IMG_PATH"\\\\MainLCD\\\\Call\\\\Touch\\\\Call.bmp"</IMAGE>;

#ifdef __MMI_CALENDAR__
#ifdef __MMI_UI_DALMATIAN_CALENDAR__ 
    <IMAGE id = "IMG_CALENDAR_JAN">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\JAN.BMP"</IMAGE>;
#else
    #ifdef __OP01__
       <IMAGE id = "IMG_CALENDAR_JAN">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\new_bg.BMP"</IMAGE>;
    #endif
#endif
#ifdef __MMI_UI_DALMATIAN_CALENDAR__ 
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_JAN">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\JAN.gif"</IMAGE>;
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_FEB">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\FEB.gif"</IMAGE>;
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_MAR">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\MARCH.gif"</IMAGE>;
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_APR">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\APRIL.gif"</IMAGE>;
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_MAY">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\MAY.gif"</IMAGE>;
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_JUN">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\JUNE.gif"</IMAGE>;
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_JUL">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\JULY.gif"</IMAGE>;
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_AUG">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\AUG.gif"</IMAGE>;
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_SEP">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\SEP.gif"</IMAGE>;
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_OCT">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\OCT.gif"</IMAGE>;
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_NOV">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\NOV.gif"</IMAGE>;
    <IMAGE id = "DALMATIAN_WEEK_HIGHLIGHTER_IMAGE_ID_DEC">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\DALMATIAN\\\\WEEK\\\\DEC.gif"</IMAGE>;
#endif

#if defined(__MMI_FTE_SUPPORT__)
    #ifndef __MMI_CLNDR_FTE_SLIM_RES__
    <IMAGE id = "CAL_LEFT_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_upL.png"</IMAGE>;
    <IMAGE id = "CAL_LEFT_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_downL.png"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_upR.png"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_downR.png"</IMAGE>;
    <IMAGE id = "CAL_LEFT_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_disableL.PNG"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\Th_disableR.PNG"</IMAGE>;
    #endif
    
#ifdef __MMI_TOUCH_SCREEN__
    //#if defined(__32_32_SEG__) && defined(__MMI_MAINLCD_240X320__)
    #ifdef __MMI_CLNDR_FTE_SLIM_RES__
    <IMAGE id = "CAL_UP_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_up_s.png"</IMAGE>;
    <IMAGE id = "CAL_UP_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_down_s.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_up_s.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_down_s.png"</IMAGE>;
    <IMAGE id = "CAL_UP_ARROW_BG_9SLICE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_up_bg.9slice.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_BG_9SLICE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_down_bg.9slice.png"</IMAGE>;
    #else
    <IMAGE id = "CAL_UP_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_up.png"</IMAGE>;
    <IMAGE id = "CAL_UP_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_down.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_up.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_down.png"</IMAGE>;
    <IMAGE id = "CAL_UP_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_disable.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_disable.png"</IMAGE>;    
    #endif /*__MMI_CLNDR_FTE_SLIM_RES__*/
    #endif

#elif defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id = "CAL_LEFT_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL.bmp"</IMAGE>;
    <IMAGE id = "CAL_LEFT_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL.bmp"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR.bmp"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR.bmp"</IMAGE>;
    <IMAGE id = "CAL_LEFT_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARL_disabled.bmp"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\PV_ARR_disabled.bmp"</IMAGE>;
#ifdef __MMI_TOUCH_SCREEN__
    <IMAGE id = "CAL_UP_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_up.png"</IMAGE>;
    <IMAGE id = "CAL_UP_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_up.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_up.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_up.png"</IMAGE>;
    <IMAGE id = "CAL_UP_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_up.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_up.png"</IMAGE>;
#endif
#elif defined(__MMI_MAINLCD_320X480__)
    <IMAGE id = "CAL_LEFT_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upL.png"</IMAGE>;
    <IMAGE id = "CAL_LEFT_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_downL.png"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upR.png"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_downR.png"</IMAGE>;
    <IMAGE id = "CAL_LEFT_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upL_disable.png"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upR_disable.png"</IMAGE>;
#ifdef __MMI_TOUCH_SCREEN__
    <IMAGE id = "CAL_UP_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_up.png"</IMAGE>;
    <IMAGE id = "CAL_UP_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_down.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_up.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_down.png"</IMAGE>;
    <IMAGE id = "CAL_UP_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_disable.png"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_disable.png"</IMAGE>;
#endif
#else 
    <IMAGE id = "CAL_LEFT_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upL.bmp"</IMAGE>;
    <IMAGE id = "CAL_LEFT_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_downL.bmp"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upR.bmp"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_downR.bmp"</IMAGE>;
    <IMAGE id = "CAL_LEFT_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upL_disable.bmp"</IMAGE>;
    <IMAGE id = "CAL_RIGHT_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_upR_disable.bmp"</IMAGE>;
#ifdef __MMI_TOUCH_SCREEN__
    <IMAGE id = "CAL_UP_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_up.bmp"</IMAGE>;
    <IMAGE id = "CAL_UP_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_down.bmp"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_up.bmp"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_down.bmp"</IMAGE>;
    <IMAGE id = "CAL_UP_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_top_disable.bmp"</IMAGE>;
    <IMAGE id = "CAL_DOWN_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Th_bottom_disable.bmp"</IMAGE>;
#endif
#endif /* __MMI_FTE_SUPPORT__ */ 
#endif /* __MMI_CALENDAR__ */
#ifdef __MMI_FTE_SUPPORT__
    #ifndef __MMI_CLNDR_FTE_SLIM_RES__ //lhm
    <IMAGE id = "IMG_CALENDAR_HORIZONTAL_SELECT_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Touch\\\\Background.9slice.png"</IMAGE>;
    #endif
    <IMAGE id = "IMG_CALENDAR_HORIZONTAL_STRING_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\Date_bar.9slice.png"</IMAGE>;

    <IMAGE id = "MENSTURAL_LEFT_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\Left_arrow_normal.png"</IMAGE>;
    <IMAGE id = "MENSTURAL_LEFT_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\Left_arrow_highlight.png"</IMAGE>;
    <IMAGE id = "MENSTURAL_RIGHT_ARROW_UP_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\Right_arrow_normal.png"</IMAGE>;
    <IMAGE id = "MENSTURAL_RIGHT_ARROW_DOWN_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\Right_arrow_highlight.png"</IMAGE>;
    <IMAGE id = "MENSTURAL_LEFT_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\Left_arrow_disable.png"</IMAGE>;
    <IMAGE id = "MENSTURAL_RIGHT_ARROW_DISABLE_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\Health\\\\Right_arrow_disable.png"</IMAGE>;
#endif 


#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    <STRING id = "STR_IDLESCREEN_SUNDAY">Sunday</STRING>;
    <STRING id = "STR_IDLESCREEN_MONDAY">Monday</STRING>;
    <STRING id = "STR_IDLESCREEN_TUESDAY">Tuesday</STRING>;
    <STRING id = "STR_IDLESCREEN_WEDNESDAY">Wednesday</STRING>;
    <STRING id = "STR_IDLESCREEN_THURSDAY">Thursday</STRING>;
    <STRING id = "STR_IDLESCREEN_FRIDAY">Friday</STRING>;
    <STRING id = "STR_IDLESCREEN_SATURDAY">Saturday</STRING>;
    
    <IMAGE id = "IMG_TECHNO_ANALOG_CLOCK">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\ANALOG_CLOCK.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DIGITAL_CLOCK.png"</IMAGE>;
#ifdef __MMI_DIGITAL_CLOCK_STYLE_BACKGROUND__
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_DAY_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\day.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_NIGHT_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\night.png"</IMAGE>;
#endif 
#endif 
#ifdef __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_0">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0030.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_1">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0031.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_2">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0032.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_3">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0033.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_4">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0034.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_5">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0035.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_6">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0036.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_7">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0037.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_8">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0038.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_9">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0039.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_AM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\am.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_PM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\pm.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_CLOCK_COLON">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\DigitalClock\\\\0021.png"</IMAGE>;
#endif 
#if defined(__MMI_FANCY_SCREEN_LOCK__)
    #if !defined(__FTE_NON_SLIM_RES__)
        <IMAGE id = "IMG_KEYPAD_LOCK_UNLOCK_BAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\Bar\\\\UnlockBar_BG.9slice.png"</IMAGE>;
        <IMAGE id = "IMG_KEYPAD_LOCK_UNLOCK_TIME_BAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\Bar\\\\UnlockTimeBar_BG.9slice.png"</IMAGE>;
    #else
        <IMAGE id = "IMG_KEYPAD_LOCK_UNLOCK_BAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\Bar\\\\UnlockBar_BG.png"</IMAGE>;
        <IMAGE id = "IMG_KEYPAD_LOCK_UNLOCK_TIME_BAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\Bar\\\\UnlockTimeBar_BG.png"</IMAGE>;
    #endif
    <IMAGE id = "IMG_KEYPAD_LOCK_UNLOCK_BUTTON0">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\LongPressButton\\\\Unlock_button0.png"</IMAGE>;
    <IMAGE id = "IMG_KEYPAD_LOCK_UNLOCK_BUTTON5">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\PhoneLockUnlock\\\\LongPressButton\\\\Unlock_button5.png"</IMAGE>;
#endif

#ifdef __MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK__
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_0">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_1">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_2">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\2.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_3">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\3.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_4">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\4.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_5">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\5.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_6">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\6.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_7">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\7.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_8">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\8.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_9">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\9.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_AM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\am.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_PM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\pm.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_COLON">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Time\\\\Colon.png"</IMAGE>;
#elif (defined __OPTR_NONE__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) ||defined(__MMI_MAINLCD_480X800__) ) && (!defined(__LOW_COST_SUPPORT_COMMON__))
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_0" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0030.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0031.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0032.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0033.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0034.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_5" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0035.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_6" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0036.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_7" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0037.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_8" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0038.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_9" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0039.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_AM" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\am.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_PM" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\pm.png"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_COLON" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0021.png"</IMAGE>;
#else
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_0" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0030.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0031.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0032.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0033.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0034.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_5" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0035.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_6" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0036.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_7" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0037.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_8" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0038.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_9" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0039.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_AM" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\am.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_PM" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\pm.bmp"</IMAGE>;
    <IMAGE id = "IMG_TECHNO_DIGITAL_SMALL_CLOCK_COLON" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Techno\\\\SmallClock\\\\0021.bmp"</IMAGE>;
#endif
#endif /* __MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK__ */

#if defined(__MMI_VUI_ENGINE__)
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_0">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM0.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_1">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM1.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_2">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM2.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_3">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM3.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_4">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM4.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_5">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM5.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_6">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM6.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_7">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM7.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_8">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM8.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_9">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM9.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_NUMBER_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_NUM_gray.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_TIME_SEPERATOR_FOREGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_Colon.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_TIME_SEPERATOR_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_Colon_gray.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_AM_FOREGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_AM_on.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_AM_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_AM_dis.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_PM_FOREGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_PM_on.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_DIGITAL_IMAGE_CLOCK_PM_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Digital_PM_dis.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_ANALOG_IMAGE_CLOCK_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Simulate_BG.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_ANALOG_IMAGE_CLOCK_COVER">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Simulate_cover.png"</IMAGE>;

    <IMAGE id = "IMG_ID_VENUS_ANALOG_IMAGE_CLOCK_HOUR_HAND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Simulate_SecondHand.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_ANALOG_IMAGE_CLOCK_MINUTE_HAND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Simulate_SecondHand.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_ANALOG_IMAGE_CLOCK_SECOND_HAND">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clock\\\\Clock_Simulate_SecondHand.png"</IMAGE>;
    
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_LEFT_H">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_left_highlight.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_LEFT_N">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_left_normal.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_MIDDLE_H">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_middle_highlight.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_MIDDLE_N">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_middle_normal.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_RIGHT_H">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_right_highlight.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_RIGHT_N">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_right_normal.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_SINGLE_H">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_whole_h.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_SINGLE_N">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_whole_n.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_BOTTOM_ARROW_H">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_bottom-arrow_h.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_BOTTOM_ARROW_N">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_bottom-arrow_n.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_TOP_ARROW_H">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_top-arrow_h.png"</IMAGE>;
    <IMAGE id = "IMG_ID_VENUS_CLIPBOARD_FM_TOP_ARROW_N">CUST_IMG_PATH"\\\\MainLCD\\\\VUI\\\\Common\\\\Clipboard\\\\CutCopyPaste_top-arrow_n.png"</IMAGE>;

#endif 
        

#if !defined(__MMI_FWUI_SLIM__)
#if (!defined(__MMI_FTE_SUPPORT__)) && defined(__MMI_MAINLCD_320X240__) && defined(__MMI_DUAL_SIM_MASTER__)
    <IMAGE id = "IMAGE_VIEW_TITLEBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\DualSIM\\\\TB_IV_BG_DUAL.bmp"</IMAGE>;
#else
    <IMAGE id = "IMAGE_VIEW_TITLEBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_IV_BG.bmp"</IMAGE>;
#endif 
#else
#if (!defined(__MMI_FTE_SUPPORT__)) && defined(__MMI_MAINLCD_320X240__) && defined(__MMI_DUAL_SIM_MASTER__)
    <IMAGE id = "IMAGE_VIEW_TITLEBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\DualSIM\\\\TB_IV_BG_DUAL.bmp"</IMAGE>;
#elif !defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMAGE_VIEW_TITLEBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_IV_BG.bmp"</IMAGE>;
#endif  
#endif

#ifdef __MMI_SMALL_LIST_SCREEN__
    <IMAGE id = "IMG_FLEXIBLE_TITLEBAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\Titlebar\\\\TB_FLEXIBLE.bmp"</IMAGE>;
#endif
#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    <IMAGE id = "TWO_LINE_VOLUME_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SlideControls\\\\V_INLINE.gif"</IMAGE>;
#endif
#ifdef __MMI_TOUCH_SCREEN__
#ifdef __COSMOS_MMI__
	<IMAGE id = "IMG_CAT1004_CLOSE_ICON_UP">RES_THEME_ROOT"\\\\Default\\\\VK3\\\\close_n.png"</IMAGE>;
	<IMAGE id = "IMG_CAT1004_CLOSE_ICON_DOWN">RES_THEME_ROOT"\\\\Default\\\\VK3\\\\close_h.png"</IMAGE>;
#else
	<IMAGE id = "IMG_CAT1004_CLOSE_ICON_UP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VK3\\\\close_n.png"</IMAGE>;
	<IMAGE id = "IMG_CAT1004_CLOSE_ICON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VK3\\\\close_h.png"</IMAGE>;
#endif
#endif

#if defined (__MMI_MAINLCD_128X128__)
    <IMAGE id = "IMG_HORIZONTAL_NORMAL_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_middle.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NORMAL_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NORMAL_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_right.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_FOCUSED_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_middle.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_FOCUSED_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_FOCUSED_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_right.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_BLINKING_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_middle.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_BLINKING_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_BLINKING_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink.bmp"</IMAGE>;
    #ifdef __MMI_OP11_TAB_BAR__    
    <IMAGE id = "IMG_HORIZONTAL_NO_RESPONSE_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_no_response_middle.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NO_RESPONSE_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_no_response_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NO_RESPONSE_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_no_response_right.bmp"</IMAGE>;
    #endif /* __MMI_OP11_TAB_BAR__  */
    #if !defined(__MMI_FTE_SUPPORT__) || defined(__MMI_CSB_BROWSER__)
    #ifdef GDI_USING_GIF
    <IMAGE id = "IMG_HORIZONTAL_TAB_L_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_L.GIF"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_TAB_R_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_R.GIF"</IMAGE>;
    #else
    <IMAGE id = "IMG_HORIZONTAL_TAB_L_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_L.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_TAB_R_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_R.bmp"</IMAGE>;
    #endif
    #endif
    <IMAGE id = "IMG_HORIZONTAL_TAB_HINT_AREA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TITLEBAR.bmp"</IMAGE>;
#elif defined(__MMI_MAINLCD_320X480__)  
    <IMAGE id = "IMG_HORIZONTAL_NORMAL_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_middle.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NORMAL_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_left.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NORMAL_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_right.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_FOCUSED_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_middle.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_FOCUSED_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_left.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_FOCUSED_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_right.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_BLINKING_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_middle.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_BLINKING_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_left.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_BLINKING_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_right.png"</IMAGE>;
    #ifdef __MMI_OP11_TAB_BAR__    
    <IMAGE id = "IMG_HORIZONTAL_NO_RESPONSE_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_no_response_middle.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NO_RESPONSE_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_no_response_left.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NO_RESPONSE_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_no_response_right.png"</IMAGE>;
    #endif /* __MMI_OP11_TAB_BAR__  */
    #if !defined(__MMI_FTE_SUPPORT__) || defined(__MMI_CSB_BROWSER__)
    #ifdef GDI_USING_GIF
    <IMAGE id = "IMG_HORIZONTAL_TAB_L_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_L.GIF"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_TAB_R_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_R.GIF"</IMAGE>;
    #else
    <IMAGE id = "IMG_HORIZONTAL_TAB_L_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_L.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_TAB_R_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_R.bmp"</IMAGE>;
    #endif
    #endif
    <IMAGE id = "IMG_HORIZONTAL_TAB_HINT_AREA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TITLEBAR.png"</IMAGE>;
#else  
    <IMAGE id = "IMG_HORIZONTAL_NORMAL_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_middle.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NORMAL_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_left.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NORMAL_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_right.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_FOCUSED_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_middle.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_FOCUSED_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_left.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_FOCUSED_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\focused_tab_bar_right.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_BLINKING_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_middle.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_BLINKING_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_left.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_BLINKING_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_blink_right.png"</IMAGE>;
    #ifdef __MMI_OP11_TAB_BAR__    
    <IMAGE id = "IMG_HORIZONTAL_NO_RESPONSE_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_no_response_middle.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NO_RESPONSE_LEFT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_no_response_left.png"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_NO_RESPONSE_RIGHT_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\tab_bar_no_response_right.png"</IMAGE>;
    #endif /* __MMI_OP11_TAB_BAR__  */
    #if !defined(__MMI_FTE_SUPPORT__) || defined(__MMI_CSB_BROWSER__)
    #ifdef GDI_USING_GIF
    <IMAGE id = "IMG_HORIZONTAL_TAB_L_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_L.GIF"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_TAB_R_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_R.GIF"</IMAGE>;
    #else
    <IMAGE id = "IMG_HORIZONTAL_TAB_L_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_L.bmp"</IMAGE>;
    <IMAGE id = "IMG_HORIZONTAL_TAB_R_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TAB_ARROW_R.bmp"</IMAGE>;
    #endif
    #endif
    <IMAGE id = "IMG_HORIZONTAL_TAB_HINT_AREA">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\TITLEBAR.GIF"</IMAGE>;
#endif 

    <IMAGE id = "IMG_HORIZONTAL_DISABLED_TAB">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TabBar\\\\Tab_bar_disable.9slice.png"</IMAGE>;

#ifdef __MMI_MAINLCD_128X64__
    <IMAGE id = "IMG_PERCENTAGE_BAR_LEFT_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\load_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_PERCENTAGE_BAR_RIGHT_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\load_right.bmp"</IMAGE>;
    <IMAGE id = "IMG_PERCENTAGE_BAR_BG_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\load_bg.bmp"</IMAGE>;
#else
#ifdef __DM_PROGRESS_BAR_9_SLICE_BG_IMAGE__ /*lhm*/
     <IMAGE id = "IMG_PERCENTAGE_BAR_BG_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\load.9slice.bmp"</IMAGE>;
#else
    <IMAGE id = "IMG_PERCENTAGE_BAR_LEFT_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\load_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_PERCENTAGE_BAR_RIGHT_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\load_right.bmp"</IMAGE>;
    <IMAGE id = "IMG_PERCENTAGE_BAR_BG_IMAGE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ProgressBar\\\\load_bg.bmp"</IMAGE>;
#endif
#endif

    <IMAGE id = "GUI_COLOR_SLIDER_ARROW_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ColorSlider\\\\color_slider_arrow.bmp"</IMAGE>;
    
#if(EMS_DISPLAY_SPECIAL_CHARACTERS)
    <IMAGE id = "WGUI_CR_CHARACTER_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\EMSCR.BMP"</IMAGE>;
    <IMAGE id = "WGUI_ESC_CHARACTER_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\EMSESC.BMP"</IMAGE>;
    <IMAGE id = "WGUI_LF_CHARACTER_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\Edit\\\\EMSLF.BMP"</IMAGE>;
#endif
    
#if !defined(__MMI_FWUI_SLIM__)
    <IMAGE id = "WGUI_IMG_TEXT_BG_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\TBG_TOP.png"</IMAGE>;
#if defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "WGUI_IMG_TEXT_BG_MID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\information_background.9slice.png"</IMAGE>;
#elif defined(__MMI_SLIM_IMG_RES__)
	<IMAGE id = "WGUI_IMG_TEXT_BG_MID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\TBG_MID.9slice.png"</IMAGE>;
#else    
    <IMAGE id = "WGUI_IMG_TEXT_BG_MID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\TBG_MID.png"</IMAGE>;
#endif    
    <IMAGE id = "WGUI_IMG_TEXT_BG_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\TBG_BOTTOM.png"</IMAGE>;
#endif
#ifndef __MMI_FWUI_SLIM__    
    <IMAGE id = "WGUI_IMG_TEXT_BG_PREVIEW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\TBG_Preview.png"</IMAGE>;
#else    
    <IMAGE id = "WGUI_IMG_TEXT_BG_PREVIEW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\TBG_Preview.9slice.png"</IMAGE>;
#endif
    
#if defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMG_CAT412_PROG_BAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\PROGRESS_BG.9slice.bmp"</IMAGE>;
    <IMAGE id = "IMG_CAT412_PROG_BAR_FULL">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\PROGRESS_Full.9slice.bmp"</IMAGE>;
#elif defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_BASIC_UI_STYLE__)
    <IMAGE id = "IMG_CAT412_PROG_BAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\PROGRESS_BG.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_CAT412_PROG_BAR_FULL">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\PROGRESS_Full.9slice.png"</IMAGE>;
#else /* __MMI_SLIM_IMG_RES__ */
    //<IMAGE id = "IMG_CAT412_PROG_BAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\PROGRESS_BG.bmp"</IMAGE>;
    //<IMAGE id = "IMG_CAT412_PROG_BAR_FULL">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\PROGRESS_Full.bmp"</IMAGE>;
    <IMAGE id = "IMG_CAT412_PROG_BAR_BG">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\PROGRESS_BG.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_CAT412_PROG_BAR_FULL">CUST_IMG_PATH"\\\\MainLCD\\\\DLAgent\\\\PROGRESS_Full.9slice.png"</IMAGE>;
#endif /* __MMI_SLIM_IMG_RES__ */
 
#ifdef __MMI_ANIMATED_DIAL__
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_1"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_2"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_3"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_4">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_4"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_5">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_5"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_6">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_6"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_7">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_7"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_8">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_8"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_9">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_9"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_0">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_0"</IMAGE>;
    
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_STAR">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_star"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_PLUS">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_plus"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_P">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_p"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_W">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_w"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_POUND">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_pound"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_QUEST">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_quest"</IMAGE>;

    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_1">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_1"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_2">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_2"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_3">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_3"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_4">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_4"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_5">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_5"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_6">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_6"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_7">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_7"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_8">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_8"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_9">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_9"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_0">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_0"</IMAGE>;
    
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_STAR">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_star"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_PLUS">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_plus"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_P">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_p"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_W">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_w"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_POUND">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_pound"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_S_QUEST">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_s_quest"</IMAGE>;
    
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_BG">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_ball_bg.png"</IMAGE>;

    <IMAGE id = "IMG_ID_ANIMATED_DIAL_CURSOR">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_cursor"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIMATED_DIAL_CURSOR_S">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\animated_dial_cursor_s"</IMAGE>;

    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_1">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\1"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_2">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\2"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_3">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\3"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_4">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\4"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_5">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\5"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_6">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\6"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_7">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\7"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_8">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\8"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_9">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\9"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_0">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\0"</IMAGE>;
    
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_STAR">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\star"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_PLUS">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\plus"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_P">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\p"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_W">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\w"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_POUND">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\pound"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_QUEST">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\quest"</IMAGE>;

    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_1">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\1"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_2">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\2"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_3">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\3"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_4">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\4"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_5">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\5"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_6">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\6"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_7">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\7"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_8">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\8"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_9">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\9"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_0">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\0"</IMAGE>;
    
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_STAR">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\star"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_PLUS">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\plus"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_P">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\p"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_W">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\w"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_POUND">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\pound"</IMAGE>;
    <IMAGE id = "IMG_ID_ANIM_DIAL_DSPR_S_QUEST">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\AnimatedDial\\\\disappear\\\\small\\\\quest"</IMAGE>;
#endif 

    
#ifdef __MMI_OP11_SIDEBAR__
    <IMAGE id = "IMG_SIDE_BAR_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_LeftBG.png"</IMAGE>;
    <IMAGE id = "IMG_SIDE_BAR_MENU_TOP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_top.png"</IMAGE>;
    <IMAGE id = "IMG_SIDE_BAR_MENU_TOP2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_top2.png"</IMAGE>;
    <IMAGE id = "IMG_SIDE_BAR_MENU_MIDDLE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_middle.png"</IMAGE>;
    <IMAGE id = "IMG_SIDE_BAR_MENU_BOTTOM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_bottom.png"</IMAGE>;
    <IMAGE id = "IMG_SIDE_BAR_MENU_BOTTOM2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_bottom2.png"</IMAGE>;
    <IMAGE id = "IMG_SIDE_BAR_MENU_LEFT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_left.png"</IMAGE>;

    <IMAGE id = "IMG_SIDE_BAR_MENU_HIGHLIGHT_WITHOUT_SCROLLBAR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_Highlight_NonTouch_NonScrollbar.png"</IMAGE>;
#ifndef __MMI_TOUCH_SCREEN__
    <IMAGE id = "IMG_SIDE_BAR_MENU_HIGHLIGHT_WITH_SCROLLBAR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_Highlight_NonTouch_Scrollbar.png"</IMAGE>;
#else
    <IMAGE id = "IMG_SIDE_BAR_MENU_HIGHLIGHT_WITH_SCROLLBAR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SideBar\\\\HomePOP_Highlight_Touch_Scrollbar.png"</IMAGE>;
#endif
#endif
    
#ifdef __MMI_OP12_TOOLBAR__   
    <IMAGE id = "IMG_TOOLBAR_LEFT_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_arrow_left.bmp"</IMAGE>;
    <IMAGE id = "IMG_TOOLBAR_RIGHT_ARROW">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_arrow_right.bmp"</IMAGE>;
    <IMAGE id = "IMG_TOOLBAR_BAR_BG_INACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_IDLE_nomal.png"</IMAGE>;
    <IMAGE id = "IMG_TOOLBAR_BAR_BG_EVENT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_IDLE_select.png"</IMAGE>;
    <IMAGE id = "IMG_TOOLBAR_BAR_BG_EVENT_INACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_IDLE_select_transparent.png"</IMAGE>;
    <IMAGE id = "IMG_TOOLBAR_MENU_ITEM_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_listbg.png"</IMAGE>;
    <IMAGE id = "IMG_TOOLBAR_BAR_BG_ACTIVE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_nomal.png"</IMAGE>;
    <IMAGE id = "IMG_TOOLBAR_BAR_BG_HIGHLIGHT">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_select.png"</IMAGE>;
    <IMAGE id = "IMG_TOOLBAR_TITLE_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\toolbar_TAB_Title.png"</IMAGE>;

    <IMAGE id = "IMG_TOOLBAR_MENU_HIGHLIGHT_WITH_SCROLLBAR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\Toolbar_highlight_scrollbar.png"</IMAGE>;
    <IMAGE id = "IMG_TOOLBAR_MENU_HIGHLIGHT_WITHOUT_SCROLLBAR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\Toolbar_highlight.png"</IMAGE>;
    <IMAGE id = "IMG_TOOLBAR_MENU_HIGHLIGHT_DOUBLE_LINE_WITH_SCROLLBAR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\Toolbar_2line_highlight_scrollbar.png"</IMAGE>;
    <IMAGE id = "IMG_TOOLBAR_MENU_HIGHLIGHT_DOUBLE_LINE_WITHOUT_SCROLLBAR">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\ToolBar\\\\Toolbar_2line_highlight.png"</IMAGE>;
#endif

    
    <IMAGE id = "IMG_STATUS_ICON_TIME_AM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\AM.bmp"</IMAGE>;
    <IMAGE id = "IMG_STATUS_ICON_TIME_PM">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\PM.bmp"</IMAGE>;
    <IMAGE id = "IMG_STATUS_ICON_TIME_AM_CH">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\AM_CH.bmp"</IMAGE>;
    <IMAGE id = "IMG_STATUS_ICON_TIME_PM_CH">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\StatusiconTime\\\\PM_CH.bmp"</IMAGE>;

#ifdef __MMI_CAT116_SUPPORT__
    <IMAGE id = "IMG_ID_CALL_PLAN_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\TextBG\\\\BG.png"</IMAGE>;
#endif

#if defined(__MMI_CAT116_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    <IMAGE id = "IMG_ID_CAT116_SEND_KEY_UP">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\USSD\\\\SendKey_Up.png"</IMAGE>;
    <IMAGE id = "IMG_ID_CAT116_SEND_KEY_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\USSD\\\\SendKey_Down.png"</IMAGE>;
#endif /* __MMI_CAT116_SUPPORT__ && __MMI_TOUCH_SCREEN__ */

#if defined(__MMI_BT_SUPPORT__) || defined(__MMI_PICT_BRIDGE_SUPPORT__) || defined(__MMI_CSB_BROWSER__)
    <IMAGE id = "SMALL_CHECKBOX_ON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELement\\\\Checkbox\\\\S_CK_S.BMP"</IMAGE>;
    <IMAGE id = "SMALL_CHECKBOX_OFF_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELement\\\\Checkbox\\\\S_CK_UNS.BMP"</IMAGE>;
#endif
#ifdef __MMI_ECOMPASS__
    <IMAGE id = "IMG_ID_COMPASS_BACKGROUND">CUST_IMG_PATH"\\\\MainLCD\\\\Compass\\\\EC_background.png"</IMAGE>;
#endif

#ifdef __MMI_MESSAGES_EMS__
    <AUDIO id = "AUD_ID_EMS_CHIMES_HIGH">CUST_ADO_PATH"\\\\EMS\\\\EMS01_ChimesHigh.mid"</AUDIO>;
    <AUDIO id = "AUD_ID_EMS_CHIMES_LOW">CUST_ADO_PATH"\\\\EMS\\\\EMS02_ChimesLow.mid"</AUDIO>;
    <AUDIO id = "AUD_ID_EMS_DING">CUST_ADO_PATH"\\\\EMS\\\\EMS03_Ding.mid"</AUDIO>;
    <AUDIO id = "AUD_ID_EMS_TADA">CUST_ADO_PATH"\\\\EMS\\\\EMS04_TaDa.mid"</AUDIO>;
    <AUDIO id = "AUD_ID_EMS_NOTIFY">CUST_ADO_PATH"\\\\EMS\\\\EMS05_Notify.mid"</AUDIO>;
    <AUDIO id = "AUD_ID_EMS_DRUM">CUST_ADO_PATH"\\\\EMS\\\\EMS06_Drum.mid"</AUDIO>;
    <AUDIO id = "AUD_ID_EMS_CLAPS">CUST_ADO_PATH"\\\\EMS\\\\EMS07_Claps.mid"</AUDIO>;
    <AUDIO id = "AUD_ID_EMS_FANFAR">CUST_ADO_PATH"\\\\EMS\\\\EMS08_FanFar.mid"</AUDIO>;
    <AUDIO id = "AUD_ID_EMS_CHORE_HGH">CUST_ADO_PATH"\\\\EMS\\\\EMS09_ChordHigh.mid"</AUDIO>;
    <AUDIO id = "AUD_ID_EMS_CHORE_LOW">CUST_ADO_PATH"\\\\EMS\\\\EMS10_ChordLow.mid"</AUDIO>;
#endif

#if defined(__MMI_MAINLCD_128X160__) && defined(__MMI_CALENDAR_ON_IDLE_SCREEN__) && (defined(__MMI_OP11_HOMESCREEN_0301__) || defined(__MMI_OP11_HOMESCREEN_0302__))
    <IMAGE id = "IMG_ID_IDLE_CALENDAR_NUM_0">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0030.bmp"</IMAGE>;
    <IMAGE id = "IMG_ID_IDLE_CALENDAR_NUM_1">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0031.bmp"</IMAGE>;
    <IMAGE id = "IMG_ID_IDLE_CALENDAR_NUM_2">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0032.bmp"</IMAGE>;
    <IMAGE id = "IMG_ID_IDLE_CALENDAR_NUM_3">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0033.bmp"</IMAGE>;
    <IMAGE id = "IMG_ID_IDLE_CALENDAR_NUM_4">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0034.bmp"</IMAGE>;
    <IMAGE id = "IMG_ID_IDLE_CALENDAR_NUM_5">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0035.bmp"</IMAGE>;
    <IMAGE id = "IMG_ID_IDLE_CALENDAR_NUM_6">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0036.bmp"</IMAGE>;
    <IMAGE id = "IMG_ID_IDLE_CALENDAR_NUM_7">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0037.bmp"</IMAGE>;
    <IMAGE id = "IMG_ID_IDLE_CALENDAR_NUM_8">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0038.bmp"</IMAGE>;
    <IMAGE id = "IMG_ID_IDLE_CALENDAR_NUM_9">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\0039.bmp"</IMAGE>;
    <IMAGE id = "IMG_ID_IDLE_CALENDAR_HORIZONTAL_STRING">CUST_IMG_PATH"\\\\MainLCD\\\\Calendar\\\\week\\\\week.bmp"</IMAGE>;
#endif

      #ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
      <IMAGE id = "IMG_TITLE_SCROLL">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\AnimationEffects\\\\Title\\\\AnimationTitle.gif"</IMAGE>;
      #endif

      #ifdef __MMI_UI_LIST_ANIMATE_HIGHLIGHT_EFFECTS__
        <IMAGE id = "IMG_LIST_HIGHLIGHTER">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\AnimationEffects\\\\List\\\\AnimationHighlighter.gif"</IMAGE>;
      #endif
#if ((ENABLE_CIRCULAR_3D_MENU) || (ENABLE_ROTATE_MENU))
    <IMAGE id = "CM3D_COMMON_IMAGE0_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\CM3D4ball.gif"</IMAGE>;
    <IMAGE id = "CM3D_COMMON_IMAGE1_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\CM3D5ball.gif"</IMAGE>;
    <IMAGE id = "CM3D_COMMON_IMAGE2_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\CM3D6ball.gif"</IMAGE>;
    <IMAGE id = "CM3D_COMMON_IMAGE3_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\MainMenu\\\\CIRCULAR_3D\\\\CM3D7ball.gif"</IMAGE>;
#endif    

    <IMAGE id = "IMG_BOOTUP_SCANNING_LOGO" flag = "MULTIBIN">CUST_IMG_PATH"\\\\MainLCD\\\\Active\\\\poweronoff\\\\logo."__MMI_RES_TYPE_BOOTUP_LOGO_IMAGE__</IMAGE>;

    <IMAGE id = "RADIO_ON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELement\\\\Radiobutton\\\\RO_S.png"</IMAGE>;
    <IMAGE id = "RADIO_OFF_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELement\\\\Radiobutton\\\\RO_UNS.png"</IMAGE>;
    <IMAGE id = "CHECKBOX_ON_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELement\\\\Checkbox\\\\CK_S.png"</IMAGE>;
    <IMAGE id = "CHECKBOX_OFF_IMAGE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIELement\\\\Checkbox\\\\CK_UNS.png"</IMAGE>;

    
#if defined(__MMI_TOUCH_IDLESCREEN_SHORTCUTS__)
    <IMAGE id = "IMG_IDLE_MAINMENU_SHORCUT">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Touch\\\\TH_MM_UP.png"</IMAGE>;
    <IMAGE id = "IMG_IDLE_MESSAGE_SHORTCUT">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Touch\\\\TH_MG_UP.png"</IMAGE>;
    <IMAGE id = "IMG_IDLE_PHONEBOOK_SHORTCUT">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Touch\\\\TH_PB_UP.png"</IMAGE>;
    <IMAGE id = "IMG_IDLE_DIALING_SCREEN_SHORTCUT">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Touch\\\\TH_DS_UP.png"</IMAGE>;
    <IMAGE id = "IMG_IDLE_MAINMENU_SHORCUT_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Touch\\\\TH_MM_DOWN.png"</IMAGE>;
    <IMAGE id = "IMG_IDLE_MESSAGE_SHORTCUT_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Touch\\\\TH_MG_DOWN.png"</IMAGE>;
    <IMAGE id = "IMG_IDLE_PHONEBOOK_SHORTCUT_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Touch\\\\TH_PB_DOWN.png"</IMAGE>;
    <IMAGE id = "IMG_IDLE_DIALING_SCREEN_SHORTCUT_PRESSED">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Touch\\\\TH_DS_DOWN.png"</IMAGE>;
#endif 

#if defined(__MMI_CAT203_SUPPORT__) && defined(__MMI_FTE_SUPPORT__)
    <IMAGE id = "IMG_CAT203_BS_BUTTON_DOWN">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DialerSearch\\\\Backspace_BG_down.png"</IMAGE>;
    <IMAGE id = "IMG_CAT203_BS_BUTTON_NORMAL">CUST_IMG_PATH"\\\\MainLCD\\\\DialingScreen\\\\DialerSearch\\\\Backspace_BG_normal.png"</IMAGE>;  
#endif
#if (defined(GEMINI_PLUS) && (GEMINI_PLUS == 3))
	<IMAGE id = "IMG_SIM_NORMAL_PETAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM1_BG_Normal.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_HIGHLIGHT_PETAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM1_BG_Highlight.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_PETAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM1_BG_Disable.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_HIGHLIGHT_PETAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM1_BG_Disable_Highlight.png"</IMAGE>;
	
	
	<IMAGE id = "IMG_SIM_NORMAL_PETAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM2_BG_Normal.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_HIGHLIGHT_PETAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM2_BG_Highlight.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_PETAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM2_BG_Disable.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_HIGHLIGHT_PETAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM2_BG_Disable_Highlight.png"</IMAGE>;
	
	<IMAGE id = "IMG_SIM_NORMAL_PETAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM3_BG_Normal.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_HIGHLIGHT_PETAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM3_BG_Highlight.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_PETAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM3_BG_Disable.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_HIGHLIGHT_PETAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM3_BG_Disable_Highlight.png"</IMAGE>;
	
	<IMAGE id = "IMG_SIM_SPACE_INFO_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM_SPACE_Info_BG.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_SELECTOR_LINE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM_Selector_Line.png"</IMAGE>;
	
	<IMAGE id = "IMG_SIM1_SIGNAL_0">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM1_Signal1.png"</IMAGE>;
	<IMAGE id = "IMG_SIM1_SIGNAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM1_Signal2.png"</IMAGE>;
	<IMAGE id = "IMG_SIM1_SIGNAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM1_Signal3.png"</IMAGE>;
	<IMAGE id = "IMG_SIM1_SIGNAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM1_Signal4.png"</IMAGE>;
	
		
	<IMAGE id = "IMG_SIM2_SIGNAL_0">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM2_Signal1.png"</IMAGE>;
	<IMAGE id = "IMG_SIM2_SIGNAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM2_Signal2.png"</IMAGE>;
	<IMAGE id = "IMG_SIM2_SIGNAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM2_Signal3.png"</IMAGE>;
	<IMAGE id = "IMG_SIM2_SIGNAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM2_Signal4.png"</IMAGE>;
	
		
	<IMAGE id = "IMG_SIM3_SIGNAL_0">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM3_Signal1.png"</IMAGE>;
	<IMAGE id = "IMG_SIM3_SIGNAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM3_Signal2.png"</IMAGE>;
	<IMAGE id = "IMG_SIM3_SIGNAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM3_Signal3.png"</IMAGE>;
	<IMAGE id = "IMG_SIM3_SIGNAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM3_Signal4.png"</IMAGE>;
	
	
	<IMAGE id = "IMG_SIM_SIGNAL_LINE1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM_Signal_L1.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_SIGNAL_LINE2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\3SIM\\\\SIM_Signal_L2.png"</IMAGE>;
#endif
#if (defined(GEMINI_PLUS) && (GEMINI_PLUS == 4))
	<IMAGE id = "IMG_SIM_NORMAL_PETAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM1_BG_Normal.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_HIGHLIGHT_PETAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM1_BG_Highlight.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_PETAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM1_BG_Disable.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_HIGHLIGHT_PETAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM1_BG_Disable_Highlight.png"</IMAGE>;
	
	
	<IMAGE id = "IMG_SIM_NORMAL_PETAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM2_BG_Normal.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_HIGHLIGHT_PETAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM2_BG_Highlight.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_PETAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM2_BG_Disable.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_HIGHLIGHT_PETAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM2_BG_Disable_Highlight.png"</IMAGE>;
	
	<IMAGE id = "IMG_SIM_NORMAL_PETAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM3_BG_Normal.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_HIGHLIGHT_PETAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM3_BG_Highlight.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_PETAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM3_BG_Disable.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_HIGHLIGHT_PETAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM3_BG_Disable_Highlight.png"</IMAGE>;
	
	<IMAGE id = "IMG_SIM_NORMAL_PETAL_4">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM4_BG_Normal.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_HIGHLIGHT_PETAL_4">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM4_BG_Highlight.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_PETAL_4">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM4_BG_Disable.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_GREY_HIGHLIGHT_PETAL_4">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM4_BG_Disable_Highlight.png"</IMAGE>;
	
	<IMAGE id = "IMG_SIM_SPACE_INFO_BG">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM_SPACE_Info_BG.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_SELECTOR_LINE">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM_Selector_Line.png"</IMAGE>;
	
	<IMAGE id = "IMG_SIM1_SIGNAL_0">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM1_Signal1.png"</IMAGE>;
	<IMAGE id = "IMG_SIM1_SIGNAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM1_Signal2.png"</IMAGE>;
	<IMAGE id = "IMG_SIM1_SIGNAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM1_Signal3.png"</IMAGE>;
	<IMAGE id = "IMG_SIM1_SIGNAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM1_Signal4.png"</IMAGE>;
	
		
	<IMAGE id = "IMG_SIM2_SIGNAL_0">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM2_Signal1.png"</IMAGE>;
	<IMAGE id = "IMG_SIM2_SIGNAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM2_Signal2.png"</IMAGE>;
	<IMAGE id = "IMG_SIM2_SIGNAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM2_Signal3.png"</IMAGE>;
	<IMAGE id = "IMG_SIM2_SIGNAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM2_Signal4.png"</IMAGE>;
	
		
	<IMAGE id = "IMG_SIM3_SIGNAL_0">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM3_Signal1.png"</IMAGE>;
	<IMAGE id = "IMG_SIM3_SIGNAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM3_Signal2.png"</IMAGE>;
	<IMAGE id = "IMG_SIM3_SIGNAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM3_Signal3.png"</IMAGE>;
	<IMAGE id = "IMG_SIM3_SIGNAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM3_Signal4.png"</IMAGE>;
	
		
	<IMAGE id = "IMG_SIM4_SIGNAL_0">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM4_Signal1.png"</IMAGE>;
	<IMAGE id = "IMG_SIM4_SIGNAL_1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM4_Signal2.png"</IMAGE>;
	<IMAGE id = "IMG_SIM4_SIGNAL_2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM4_Signal3.png"</IMAGE>;
	<IMAGE id = "IMG_SIM4_SIGNAL_3">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM4_Signal4.png"</IMAGE>;
	
	<IMAGE id = "IMG_SIM_SIGNAL_LINE1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM_Signal_L1.png"</IMAGE>;
	<IMAGE id = "IMG_SIM_SIGNAL_LINE2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SPACE\\\\4SIM\\\\SIM_Signal_L2.png"</IMAGE>;
#endif

#if defined(__MMI_UM_CONVERSATION_BOX_ENHANCE__)
    <IMAGE id = "IMG_SMS_CONVERSATION_L_HIGHLIGHTED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\img_sms_conversation_l_highlighted.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_SMS_CONVERSATION_L_UNHIGHLIGHTED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\img_sms_conversation_l_unhighlighted.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_SMS_CONVERSATION_R_HIGHLIGHTED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\img_sms_conversation_r_highlighted.9slice.png"</IMAGE>;
    <IMAGE id = "IMG_SMS_CONVERSATION_R_UNHIGHLIGHTED">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\Arrow\\\\img_sms_conversation_r_unhighlighted.9slice.png"</IMAGE>;
#endif /* __MMI_UM_CONVERSATION_BOX_ENHANCE__ */

#if defined(__MMI_TOUCH_FEEDBACK_SUPPORT__)
    <AUDIO id= "AUD_ID_TOUCH_FEEDBACK">CUST_ADO_PATH"\\\\Sound\\\\1.wav"</AUDIO>
    <AUDIO id= "AUD_ID_TOUCH_FEEDBACK_SLIENT">CUST_ADO_PATH"\\\\Sound\\\\Silence.imy"</AUDIO>
#endif    

#if defined(__SOCIAL_NETWORK_SUPPORT__)
    <STRING id = "WGUI_SNS_GET_MORE_STRING_ID">get more</STRING>;
    <IMAGE id = "IMG_SNS_LIKE_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\USSD\\\\Like.png"</IMAGE>;
    <IMAGE id = "IMG_SNS_COMMENT_ID">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\USSD\\\\Comments.png"</IMAGE>;
#endif /* __SOCIAL_NETWORK_SUPPORT__ */

    <STRING id = "STR_ID_MTE_PIN">PIN</STRING>;

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
	
	<EVENT id="EVT_ID_GUI_INPUTS_CURSOR_CHANGED" type="SENDER"/>
	<EVENT id="EVT_ID_IME_CURSOR_UPDATED" type="SENDER"/>
	<EVENT id="EVT_ID_IME_INVOKE_SPELL_WORD_SCREEN" type="SENDER"/>
	<EVENT id="EVT_ID_IME_ENTRY_INPUT_METHOD_SCREEN" type="SENDER"/>
	<EVENT id="EVT_ID_INLINE_IMAGETEXT_PEN_UP" type="SENDER"/>
	
	<TIMER id="BLINKING_CURSOR"/>
	<TIMER id="FMGR_DELAY_DECODE_0"/>
	<TIMER id="CAT9010_TIMER"/>
</APP>


