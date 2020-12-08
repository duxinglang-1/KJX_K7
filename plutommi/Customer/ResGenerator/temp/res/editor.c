/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"
#include "CommonScreensResDef.h"
/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_EDITOR">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    <INCLUDE file="GlobalResDef.h,SettingResDef.h,CommonScreensResDef.h,CommonScreensProt.h"/>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */
    /* venus clipboard service will also use clipboard string */
#if defined(__MMI_CLIPBOARD__) || defined(__MMI_VUI_ENGINE__)
    <STRING id="STR_ID_CLIPBOARD_COPY"/>
    <STRING id="STR_ID_CLIPBOARD_CUT"/>
    <STRING id="STR_ID_CLIPBOARD_PASTE"/>
    <STRING id="STR_ID_CLIPBOARD_COPY_ALL"/>
    <STRING id="STR_ID_CLIPBOARD_CUT_ALL"/>
    <STRING id="STR_ID_CLIPBOARD_MARK_TEXT"/>
    <STRING id="STR_ID_CLIPBOARD_EDIT_OPTION"/>
    <STRING id="STR_ID_CLIPBOARD_COPY_SUCESS"/>
    <STRING id="STR_ID_CLIPBOARD_TRUNCATE_FOR_MEMORY"/>
    <STRING id="STR_ID_CLIPBOARD_CUT_UNSUPPORT_CONTENT"/>
    <STRING id="STR_ID_CLIPBOARD_MAX_COPY_TEXT_SELECTED"/>
    <STRING id="STR_ID_CLIPBOARD_MAX_LINE_REACHED"/>
#endif

#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__) ||  defined(__MMI_IMC_CAPITAL_SWITCH__) 
         <STRING id= "STR_IME_SETTINGS_WRITING_LANGUAGE"/>
    #if  defined(__MMI_MIXED_LANG_SUPPORT__)
         <STRING id= "STR_IME_SETTINGS_WRITING_LANGUAGE_MAIN"/>
         <STRING id= "STR_IME_SETTINGS_WRITING_LANGUAGE_SUB"/>
    #endif 
#endif

#if defined (__MMI_IME_V3__)
	<STRING id = "STR_IME_NEW_SETTING"/>

	<STRING id = "STR_ID_FUZZY_PINYIN"/>
	<STRING id = "STR_ID_TOUCH_FEEDBACK"/>
	<STRING id = "STR_ID_AUTO_SPC_AND_CAP"/>
	<STRING id = "STR_ID_CHINESE_SETTING"/>
	<STRING id = "STR_ID_ENGLISH_SETTING"/>

	<STRING id = "STR_ID_ML_SETTING"/>
	<STRING id = "STR_ID_SYSTEM_LANGUAGE"/>
	<STRING id = "STR_ID_AD_SETTING"/>
	<STRING id = "STR_ID_KEYBRD_LANG"/>
	<STRING id = "STR_ID_ONE_PIXEL"/>
	<STRING id = "STR_ID_TWO_PIXEL"/>
	<STRING id = "STR_ID_THREE_PIXEL"/>
	<STRING id = "STR_ID_FOUR_PIXEL"/>
	<STRING id = "STR_ID_FIVE_PIXEL"/>
	<STRING id = "STR_ID_LANG_FOLO_KEYBOARD"/>
	<STRING id = "STR_ID_HW_WIDTH"/>
	<STRING id = "STR_ID_IME_FOLLOW_KEYBOARD"/>
	<STRING id = "STR_ID_IME_VIBRATION"/>
	<STRING id = "STR_ID_IME_SOUND_FEEDBACK"/>
	<STRING id = "STR_ID_IME_AUTO_SPACE"/>
	<STRING id = "STR_ID_IME_ASSOCIATION"/>
	<STRING id = "STR_ID_IME_TRACE_WIDTH"/>
	<STRING id = "STR_ID_IME_TRACE_COLOR"/>
	<STRING id = "STR_ID_IME_HW_SPEED"/>
    <STRING id="STR_INPUT_METHOD_IME_SETTINGS"/>
#endif
	<!-- handwriting setting string -->
#if defined(__MMI_TOUCH_SCREEN__)
    <STRING id = "STR_HANDWRITING_SETTING"/>
    <STRING id = "STR_HANDWRITING_PEN_SPEED"/>
    <STRING id = "STR_HANDWRITING_PEN_COLOR"/>
	<STRING id = "STR_ID_HW_SETTING"/>
#endif
    <STRING id="STR_INPUT_METHOD_MENU_INSERT_SYMBOLS"/>
    <STRING id="STR_INPUT_METHOD_MENU_SELECT_SYMBOL"/>

    <STRING id="STR_INPUT_METHOD_OPTIONS"/>
    #if defined (__MMI_IME_INPUT_PATTERN_SETTING__) || defined(__MMI_VUI_ENGINE__)
    <STRING id="STR_INPUT_METHOD_KEYBOARD_TYPE"/>	 
    <STRING id="STR_INPUT_METHOD_QWERTY"/>
        #if defined (__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
        <STRING id="STR_INPUT_METHOD_ALPHANUMERIC"/>
        #endif
        #if !defined(__MMI_NO_HANDWRITING__) 
        <STRING id="STR_INPUT_METHOD_HANDWRITING"/>	 
        #endif
    #endif
    <STRING id="STR_INPUT_METHOD_ADVANCED_OPTIONS"/>
    #if defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
    <STRING id="STR_INPUT_METHOD_AUTO_CAPITALIZATION"/>
    #endif
    #if defined (__MMI_IME_AUTO_COMPLETION_SETTING__)
    <STRING id="STR_INPUT_METHOD_AUTO_COMPLETION"/>
    #endif
    #if defined (__MMI_IME_PHONETIC_PREDICTION_SETTING__)
    <STRING id="STR_INPUT_METHOD_CHINESE_PREDICTION"/>	 
    #endif
    #if defined (__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
    <STRING id="STR_INPUT_METHOD_ALPHABETIC_PREDICTION"/>
    #endif

    <STRING id="STR_INPUT_METHOD_HANDWRITING_SPEED"/>
    <STRING id="STR_INPUT_METHOD_SETTINGS"/>

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
#if defined(__MMI_T9__)
     <STRING id="STR_INPUT_METHOD_MENU_SET_T9"/>
#elif defined(__MMI_ZI__)
     <STRING id="STR_INPUT_METHOD_MENU_SET_ZI"/>
#elif defined(__MMI_CSTAR__)
     <STRING id="STR_INPUT_METHOD_MENU_SET_CSTAR"/>
#elif defined(__MMI_GUOBI__)
     <STRING id="STR_INPUT_METHOD_MENU_SET_GUOBI"/>
#endif 
#endif

#if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && ( defined(__MMI_IME_USER_DATABASE__)||  ( defined(__MMI_CSTAR_USER_DICT__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_IME_USER_DATABASE__))   ) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_IME_FTE_ENHANCE__))
#if defined(__MMI_T9__)
     <STRING id="STR_INPUT_METHOD_MENU_NEW_T9_WORD"/>	 
#elif defined(__MMI_ZI__)
      <STRING id="STR_INPUT_METHOD_MENU_NEW_ZI_WORD"/>
#elif defined(__MMI_CSTAR__)
      <STRING id="STR_INPUT_METHOD_MENU_NEW_CSTAR_WORD"/>
#elif defined(__MMI_GUOBI__)
      <STRING id="STR_INPUT_METHOD_MENU_NEW_GUOBI_WORD"/>
#endif 
#endif


#if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
    <STRING id="STR_INPUT_METHOD_WRITING_LANGUAGE"/>
    #if  defined(__MMI_MIXED_LANG_SUPPORT__)
        <STRING id="STR_WRITING_LANGUAGE_MAIN"/>
        <STRING id="STR_WRITING_LANGUAGE_SUB"/> 
    #endif
    <STRING id="STR_ID_IME_WRITING_LANGUAGE_123"/>
#endif
    <STRING id="STR_ID_INPUT_MODE_PINYIN"/>
    <STRING id="STR_ID_INPUT_MODE_BIHUA"/>
#if defined(__MMI_PREFER_INPUT_METHOD__)
    <STRING id="STR_INPUT_METHOD_PREFERED_INPUT_METHOD"/>
#endif
#if defined (__MMI_IME_V3__)
	<SCREEN id = "GRP_ID_IME_MENU"/>
	<SCREEN id = "GRP_ID_ADVANCE_SETTING_MENU"/>
	<SCREEN id = "GRP_ID_FEEDBACK_SETTING_MENU"/>
	<SCREEN id = "GRP_ID_AUTO_SPC_AND_CAP_MENU"/>
	<SCREEN id = "GRP_ID_FUZZY_PINYIN_MENU"/>
	<SCREEN id = "SCR_INPUT_LANG_FOLLOW_KEYBRD"/>
#endif
	<SCREEN id = "GRP_ID_PHNSET_HANDWRITING"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */

    /* Example: How to use compile option in path, __MMI_RES_TYPE_WALLPAPER__ is defined in mmi_features.h */

    /* For the detail of scope="XML" please check user manual */
#if defined(__VENUS_MMI__) && defined(__COSMOS_MMI__)
<THEME>
	<IMAGE id="IMG_ID_IME_VK_CHANGE_MODE" />
	<IMAGE id="IMG_ID_IME_VK_CHANGE_SETTING" />
</THEME>
#else
	<IMAGE id="IMG_ID_IME_VK_CHANGE_MODE" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VK3\\\\PopupList_ChangeMode.png"</IMAGE>
	<IMAGE id="IMG_ID_IME_VK_CHANGE_SETTING" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VK3\\\\PopupList_Setting.png"</IMAGE>
#endif
    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */
#if defined(__MMI_IME_PLUG_IN_SETTING__)
        <MENUITEM id="MENU_ID_EDITOR_OPT_INSERT_SYMBOL" str="STR_INPUT_METHOD_MENU_INSERT_SYMBOLS" group="MENU_GROUP_EDITOR"/>
        <MENUITEM id="MENU_ID_EDITOR_OPT_INPUT_METHOD" str="STR_GLOBAL_INPUT_METHOD" group="MENU_GROUP_EDITOR"/>
		#if defined (__MMI_IME_V3__)
		<MENUITEM id="MENU_ID_EDITOR_OPT_INPUT_METHOD_SETTING" str="STR_INPUT_METHOD_IME_SETTINGS" group="MENU_GROUP_EDITOR"/>
		#else
        <MENU id="MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS" type="OPTION" str="STR_INPUT_METHOD_OPTIONS" group="MENU_GROUP_EDITOR">
        #if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        #if  defined(__MMI_MIXED_LANG_SUPPORT__)
    	    <MENU id="MENU_ID_EDITOR_OPT_WRITING_LANGUAGE" type="OPTION" str="STR_INPUT_METHOD_WRITING_LANGUAGE" highlight = "mmi_ime_commonscreens_highlight_writinglanguage" >
                <MENUITEM id="MENU_ID_COMMONSCREENS_IME_MAIN_LANGUAGE" str="STR_WRITING_LANGUAGE_MAIN" hint = "mmi_ime_commonscreens_hint_sublanguage"/>
                <MENUITEM id="MENU_ID_COMMONSCREENS_IME_SUB_LANGUAGE" str="STR_WRITING_LANGUAGE_SUB" hint =  "mmi_ime_commonscreens_hint_mainlanguage"/>
            </MENU>
        #else
            <MENUITEM id="MENU_ID_EDITOR_OPT_WRITING_LANGUAGE" str="STR_INPUT_METHOD_WRITING_LANGUAGE"/>
        #endif
        #endif

        #if defined(__MMI_IME_INPUT_ADVANCED_SETTING__)
            <MENUITEM id="MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS" str="STR_INPUT_METHOD_ADVANCED_OPTIONS"/>
        #endif
        </MENU>
       #endif 
#else
    #if defined(__MMI_EDITOR_OPTION_MENU_STYLE_1__)
        <MENUITEM id="MENU_ID_EDITOR_OPT_INSERT_SYMBOL" str="STR_INPUT_METHOD_MENU_INSERT_SYMBOLS" group="MENU_GROUP_EDITOR"/>
        #if defined(__MMI_IMC_CAPITAL_SWITCH__)
            <MENUITEM id="MENU_ID_EDITOR_OPT_INPUT_METHOD" str="STR_GLOBAL_INPUT_METHOD" group="MENU_GROUP_EDITOR"/>
            <MENUITEM id="MENU_ID_EDITOR_OPT_WRITING_LANGUAGE" str="STR_INPUT_METHOD_WRITING_LANGUAGE" group="MENU_GROUP_EDITOR"/>
        #else
        <MENUITEM id="MENU_ID_EDITOR_OPT_INPUT_METHOD" str="STR_GLOBAL_INPUT_METHOD" group="MENU_GROUP_EDITOR"/>
        #endif
    
        #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
            #if defined(__MMI_ZI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_ZI" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_T9__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_T9" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_CSTAR__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_CSTAR" group="MENU_GROUP_EDITOR"/>
            
            #elif defined(__MMI_GUOBI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_GUOBI" group="MENU_GROUP_EDITOR"/>
            #endif
        #endif
    
    #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && ( defined(__MMI_IME_USER_DATABASE__)||  ( defined(__MMI_CSTAR_USER_DICT__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_IME_USER_DATABASE__))   ) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_IME_FTE_ENHANCE__))
            #if defined(__MMI_ZI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_ZI_WORD" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_T9__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_T9_WORD" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_CSTAR__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_CSTAR_WORD" group="MENU_GROUP_EDITOR"/>
            #endif
            #elif defined(__MMI_GUOBI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_GUOBI" group="MENU_GROUP_EDITOR"/>
            
        #endif
    
    #elif defined(__MMI_EDITOR_OPTION_MENU_STYLE_2__)
        <MENUITEM id="MENU_ID_EDITOR_OPT_INSERT_SYMBOL" str="STR_INPUT_METHOD_MENU_INSERT_SYMBOLS" group="MENU_GROUP_EDITOR"/>
    
        #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
            #if defined(__MMI_ZI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_ZI" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_T9__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_T9" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_CSTAR__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_CSTAR" group="MENU_GROUP_EDITOR"/>
           
            #elif defined(__MMI_GUOBI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_GUOBI" group="MENU_GROUP_EDITOR"/>
            #endif
        #endif
    
    #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && ( defined(__MMI_IME_USER_DATABASE__)||  ( defined(__MMI_CSTAR_USER_DICT__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_IME_USER_DATABASE__))   ) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_IME_FTE_ENHANCE__))
            #if defined(__MMI_ZI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_ZI_WORD" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_T9__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_T9_WORD" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_CSTAR__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_CSTAR_WORD" group="MENU_GROUP_EDITOR"/>
            #endif
           #elif defined(__MMI_GUOBI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_GUOBI_WORD" group="MENU_GROUP_EDITOR"/>
             
        #endif
    
        #if defined(__MMI_IMC_CAPITAL_SWITCH__)
            <MENUITEM id="MENU_ID_EDITOR_OPT_WRITING_LANGUAGE" str="STR_INPUT_METHOD_WRITING_LANGUAGE" group="MENU_GROUP_EDITOR"/>
        #else
            <MENUITEM id="MENU_ID_EDITOR_OPT_INPUT_METHOD" str="STR_GLOBAL_INPUT_METHOD" group="MENU_GROUP_EDITOR"/>
        #endif
        
    #elif defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
        <MENUITEM id="MENU_ID_EDITOR_OPT_INSERT_SYMBOL" str="STR_INPUT_METHOD_MENU_INSERT_SYMBOLS" group="MENU_GROUP_EDITOR"/>
        <MENUITEM id="MENU_ID_EDITOR_OPT_INPUT_METHOD" str="STR_GLOBAL_INPUT_METHOD" group="MENU_GROUP_EDITOR"/>
		#if defined (__MMI_IME_V3__)
		<MENUITEM id="MENU_ID_EDITOR_OPT_INPUT_METHOD_SETTING" str="STR_INPUT_METHOD_IME_SETTINGS" group="MENU_GROUP_EDITOR"/>
		#else
        <MENU id="MENU_ID_EDITOR_OPT_INPUT_METHOD_OPTIONS" type="OPTION" str="STR_INPUT_METHOD_OPTIONS" highlight = "mmi_ime_commonscreens_highlight_imeoptions" group="MENU_GROUP_EDITOR">
        #if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        #if  defined(__MMI_MIXED_LANG_SUPPORT__)
	    <MENU id="MENU_ID_EDITOR_OPT_WRITING_LANGUAGE" type="OPTION" str="STR_INPUT_METHOD_WRITING_LANGUAGE" highlight = "mmi_ime_commonscreens_highlight_writinglanguage" >
            <MENUITEM id="MENU_ID_COMMONSCREENS_IME_MAIN_LANGUAGE" str="STR_WRITING_LANGUAGE_MAIN" hint = "mmi_ime_commonscreens_hint_sublanguage"/>
            <MENUITEM id="MENU_ID_COMMONSCREENS_IME_SUB_LANGUAGE" str="STR_WRITING_LANGUAGE_SUB" hint =  "mmi_ime_commonscreens_hint_mainlanguage"/>
         </MENU>
        #else
            <MENUITEM id="MENU_ID_EDITOR_OPT_WRITING_LANGUAGE" str="STR_INPUT_METHOD_WRITING_LANGUAGE" highlight = "mmi_ime_commonscreens_highlight_writinglanguage" />
        #endif
        #endif
    
					    
        #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
            #if defined(__MMI_ZI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_ZI" highlight = "mmi_ime_commonscreens_highlight_dictionary" />
            #elif defined(__MMI_T9__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_T9" highlight = "mmi_ime_commonscreens_highlight_dictionary" />
            #elif defined(__MMI_CSTAR__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_CSTAR" highlight = "mmi_ime_commonscreens_highlight_dictionary" />
            #elif defined(__MMI_GUOBI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_GUOBI" highlight = "mmi_ime_commonscreens_highlight_dictionary" />
            
            #endif
        #endif
    
    #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && ( defined(__MMI_IME_USER_DATABASE__)||  ( defined(__MMI_CSTAR_USER_DICT__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_IME_USER_DATABASE__))   ) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_IME_FTE_ENHANCE__))
    
            #if defined(__MMI_ZI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_ZI_WORD" highlight = "mmi_ime_commonscreens_highlight_newword" />
            #elif defined(__MMI_T9__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_T9_WORD" highlight = "mmi_ime_commonscreens_highlight_newword" />
            #elif defined(__MMI_CSTAR__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_CSTAR_WORD" highlight = "mmi_ime_commonscreens_highlight_newword "/>
            #elif defined(__MMI_GUOBI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_GUOBI_WORD" highlight = "mmi_ime_commonscreens_highlight_newword "/> 
            #endif
        #endif
    
    
      #if defined (__MMI_IME_INPUT_PATTERN_SETTING__)
                <MENU id="MENU_ID_COMMONSCREENS_IME_KEYBOARDTYPE" type="OPTION" str="STR_INPUT_METHOD_KEYBOARD_TYPE" highlight = "mmi_ime_commonscreens_highlight_keyboard" >
	        #if defined (__MMI_IME_ALPHANUMERIC_VK_SUPPORT__)
                <MENUITEM id="MENU_ID_COMMONSCREENS_KEYPAD_ALPHANUMERIC" str="STR_INPUT_METHOD_ALPHANUMERIC"/>
	        #endif
                <MENUITEM id="MENU_ID_COMMONSCREENS_KEYPAD_QWERTY" str="STR_INPUT_METHOD_QWERTY"/>
	        #if !defined(__MMI_NO_HANDWRITING__) 
                <MENUITEM id="MENU_ID_COMMONSCREENS_KEYPAD_HANDWRITING" str="STR_INPUT_METHOD_HANDWRITING"/>
	        #endif
		    </MENU>
        #endif	
    
        #if defined(__MMI_IME_INPUT_ADVANCED_SETTING__)
            <MENU id="MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS" type="OPTION" str="STR_INPUT_METHOD_ADVANCED_OPTIONS" highlight = "mmi_ime_commonscreens_highlight_advancedoptions ">
            #if defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
                <MENUITEM id="MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS_AUTOCAPITALIZATION" str="STR_INPUT_METHOD_AUTO_CAPITALIZATION"/>
            #endif
            #if defined (__MMI_IME_AUTO_COMPLETION_SETTING__)
                <MENUITEM id="MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS_AUTOCOMPLETION" str="STR_INPUT_METHOD_AUTO_COMPLETION"/>
            #endif
            #if defined (__MMI_IME_PHONETIC_PREDICTION_SETTING__)
                <MENUITEM id="MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS_CHINESEPREDICTION" str="STR_INPUT_METHOD_CHINESE_PREDICTION"/>
            #endif
            #if defined (__MMI_IME_ALPHABETIC_PREDICTION_SETTING__)
                <MENUITEM id="MENU_ID_COMMONSCREENS_IME_ADVANCEDOPTIONS_ALPHABETICPREDICTION" str="STR_INPUT_METHOD_ALPHABETIC_PREDICTION"/>
            #endif
		    </MENU>	
	    #endif
         </MENU>
    #endif
    #else
        #if defined(__MMI_IMC_CAPITAL_SWITCH__)
            <MENUITEM id="MENU_ID_EDITOR_OPT_WRITING_LANGUAGE" str="STR_INPUT_METHOD_WRITING_LANGUAGE" group="MENU_GROUP_EDITOR"/>
        #else
        #if defined(__MMI_PREFER_WRITING_LANG__) || defined(__MMI_MIXED_LANG_SUPPORT__)
        <MENUITEM id="MENU_ID_EDITOR_OPT_WRITING_LANGUAGE" str="STR_INPUT_METHOD_WRITING_LANGUAGE" group="MENU_GROUP_EDITOR"/>
        #endif 
            <MENUITEM id="MENU_ID_EDITOR_OPT_INPUT_METHOD" str="STR_GLOBAL_INPUT_METHOD" group="MENU_GROUP_EDITOR"/>
        #endif
    
        #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) || defined(__MMI_SMART_PHONETIC_INPUT_METHODS__)
            #if defined(__MMI_ZI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_ZI" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_T9__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_T9" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_CSTAR__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_CSTAR" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_GUOBI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_CONFIG_SMART_INPUT_METHOD" str="STR_INPUT_METHOD_MENU_SET_GUOBI" group="MENU_GROUP_EDITOR"/>
            #endif
        #endif
    
    #if defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && ( defined(__MMI_IME_USER_DATABASE__)||  ( defined(__MMI_CSTAR_USER_DICT__) && !defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_IME_USER_DATABASE__))   ) && (defined(__MMI_NORMAL_KEYPAD__) || defined(__MMI_IME_FTE_ENHANCE__))
            #if defined(__MMI_ZI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_ZI_WORD" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_T9__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_T9_WORD" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_CSTAR__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_CSTAR_WORD" group="MENU_GROUP_EDITOR"/>
            #elif defined(__MMI_GUOBI__)
                <MENUITEM id="MENU_ID_EDITOR_OPT_ADD_NEW_WORD" str="STR_INPUT_METHOD_MENU_NEW_GUOBI_WORD" group="MENU_GROUP_EDITOR"/>
            #endif
        #endif
    #endif
#endif /* __MMI_IME_PLUG_IN_SETTING__ */

#ifdef __MMI_CLIPBOARD__

    <MENUITEM id="MENU_ID_CLIPBOARD_OPTION_COPY" str="STR_ID_CLIPBOARD_COPY" highlight="mmi_frm_highlight_clipboard_edit_option_copy" group="MENU_GROUP_CLIPBOARD"/>
    <MENUITEM id="MENU_ID_CLIPBOARD_EDIT_OPTION_COPY_ALL" str="STR_ID_CLIPBOARD_COPY_ALL" highlight="mmi_frm_highlight_clipboard_edit_option_copy_all" group="MENU_GROUP_CLIPBOARD"/>
    <MENUITEM id="MENU_ID_CLIPBOARD_OPTION_CUT" str="STR_ID_CLIPBOARD_CUT" highlight="mmi_frm_highlight_clipboard_edit_option_cut" group="MENU_GROUP_CLIPBOARD"/>
    <MENUITEM id="MENU_ID_CLIPBOARD_EDIT_OPTION_CUT_ALL" str="STR_ID_CLIPBOARD_CUT_ALL" highlight="mmi_frm_highlight_clipboard_edit_option_cut_all" group="MENU_GROUP_CLIPBOARD"/>
    <MENUITEM id="MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE" str="STR_ID_CLIPBOARD_PASTE" highlight="mmi_frm_highlight_clipboard_edit_option_paste" group="MENU_GROUP_CLIPBOARD"/>
    <MENUITEM id="MENU_ID_CLIPBOARD_EDIT_OPTION" str="STR_ID_CLIPBOARD_EDIT_OPTION"/>
    <MENUITEM id="MENU_ID_CLIPBOARD_EDIT_OPTION_MARK" str="STR_ID_CLIPBOARD_MARK_TEXT" highlight="mmi_frm_highlight_clipboard_edit_option_mark"/>
    
    /* Menu for clipboard cascading menu */
    <MENU id="MENU_ID_CLIPBOARD_OPTION" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_CLIPBOARD_OPTION_COPY</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLIPBOARD_EDIT_OPTION_COPY_ALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLIPBOARD_OPTION_CUT</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLIPBOARD_EDIT_OPTION_CUT_ALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE</MENUITEM_ID>
    </MENU>
    
    /* Menu for Edit options */
    <MENU id="MENU_ID_EDITOR_OPT_EDIT_OPTIONS" type="OPTION" str="STR_ID_CLIPBOARD_EDIT_OPTION" group="MENU_GROUP_EDITOR">
        <MENUITEM_ID>MENU_ID_CLIPBOARD_EDIT_OPTION_MARK</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLIPBOARD_EDIT_OPTION_COPY_ALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLIPBOARD_EDIT_OPTION_CUT_ALL</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_CLIPBOARD_EDIT_OPTION_PASTE</MENUITEM_ID>
    </MENU>
#endif    

    /* Used for APP add menu id in app create tree */
    <MENUITEM id="MENU_ID_EDIT_OPTS"/>

    <MENUSET id="MENU_SET_EDITOR_OPT">
		<MENUITEM_ID>MENU_ID_EDITOR_OPT_INSERT_SYMBOL</MENUITEM_ID>
		<MENUITEM_ID>MENU_ID_EDITOR_OPT_INPUT_METHOD</MENUITEM_ID>
		 #if !defined(__MMI_EDITOR_OPTION_MENU_STYLE_3__)
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
    </MENUSET>

	/* Editor CUI menu */
    <MENUITEM id="MENU_ID_EDITOR_CUI_OPT_DONE" str="STR_GLOBAL_DONE" group="MENU_GROUP_EDITOR_CUI_OPTIONS"/>
    <MENUITEM id="MENU_ID_EDITOR_CUI_OPT_CANCEL" str="STR_GLOBAL_CANCEL" group="MENU_GROUP_EDITOR_CUI_OPTIONS"/>

    <MENU id="MENU_ID_EDITOR_CUI_OPT" type="OPTION" str="STR_GLOBAL_OPTIONS">
        <MENUITEM_ID>MENU_ID_EDITOR_CUI_OPT_DONE</MENUITEM_ID>
        <MENUITEM_ID>MENU_ID_EDITOR_CUI_OPT_CANCEL</MENUITEM_ID>
        <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>

/* inline input method and Done */
    <MENUITEM id="MENU_ID_INLINE_EDITOR_OPT_DONE" str="STR_GLOBAL_DONE"/>
		
    <MENU id="MENU_ID_INLINE_EDITOR_OPT" type="OPTION">
    <MENUITEM_ID>MENU_ID_INLINE_EDITOR_OPT_DONE</MENUITEM_ID>
    <MENUSET_ID>MENU_SET_EDITOR_OPT</MENUSET_ID>
    </MENU>

#if defined (__MMI_IME_V3__)
    <!-- IMEv3 Main Menu ---------------------------------------------------------->
    <MENU id = "MENU_ITEM_IME_SETTING" type = "APP_SUB" str = "STR_IME_NEW_SETTING">
		<MENUITEM id = "MENU_ID_MULTI_LANGUAGE" str = "STR_ID_ML_SETTING"/>
#if (defined(__MMI_SMART_ALPHABETIC_INPUT_METHODS__) && defined(__MMI_IME_ENGLISH__)) || defined (__MMI_IME_AUTO_CAPITALIZATION_SETTING__)
		<MENUITEM id = "MENU_ID_ENGLISH_SETTING" str = "STR_ID_ENGLISH_SETTING"/>
#endif
#if defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__) || defined(__MMI_IME_FUZZY_PINYIN__)
		<MENUITEM_ID>MENU_ID_CHINESE_SETTING</MENUITEM_ID>
#endif
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
		<MENUITEM id = "MENU_ID_HW_SETTING" str = "STR_ID_HW_SETTING"/>
#if !((!defined(__MMI_NO_HANDWRITING__) && defined(__MMI_IME_V3__) && defined(__MMI_VIRTUAL_KEYBOARD__)) && !defined(__MMI_IME_VK_TYPE_QWERTY__) &&  !defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__))
		<MENUITEM id = "MENU_ID_FOLO_KEYBRD" str = "STR_ID_KEYBRD_LANG"/>
#endif
#endif
		/* <MENUITEM id = "MENU_ID_TOUCH_FEEDBACK_SETTING" str = "STR_ID_TOUCH_FEEDBACK"/> */
    </MENU>

    <!-- IMEv3 Main Menu ---------------------------------------------------------->
#if defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__) || defined(__MMI_IME_FUZZY_PINYIN__)    
    <MENU id = "MENU_ID_CHINESE_SETTING" type = "APP_SUB" str = "STR_ID_CHINESE_SETTING">
	#if defined(__MMI_IME_PHONETIC_PREDICTION_SETTING__)
		<MENUITEM id = "MENU_ID_ASSOCIATION" str = "STR_ID_IME_ASSOCIATION"/>
		#endif
		 #ifdef __MMI_IME_FUZZY_PINYIN__ 
		<MENUITEM id = "MENU_ID_FUZZY_PINYIN_SETTING" str = "STR_ID_FUZZY_PINYIN"/>
		 #endif 
    </MENU>
#endif 

#endif   

    <RECEIVER id="EVT_ID_IME_ENTRY_INPUT_METHOD_SCREEN" proc="mmi_imc_input_method_screen_handler"/>
    <!--Menu Tree Area-->

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

<CACHEDATA type="byte" id="NVRAM_IME_SMART_MODE_CONFIG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
        <CACHEDATA type="byte" id="NVRAM_IME_AUTO_CAPITALIZATION_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_IME_AUTO_COMPLETION_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_IME_ALPHABETIC_WORD_PREDICTION_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_IME_CHINESE_WORD_PREDICTION_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_IME_AUTO_SPACE_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_IME_VIBRATION_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_IME_SOUND_FEEDBACK_FLAG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    
    <CACHEDATA type="byte" id="NVRAM_IME_INPUT_PATTERN" restore_flag="TRUE">
    #if defined(__MMI_IME_VK_TYPE_ALPHANUMERIC__)
    		<DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
    #else 
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
    #endif
        <DESCRIPTION> Byte Cache </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="short" id="NVRAM_SETTING_PREFER_INPUT_METHOD" restore_flag="TRUE" restore_id="@RESTORE_PREFER_INPUT_METHOD">
        <DEFAULT_VALUE> [0x0D, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current preferred input method </DESCRIPTION>
        <FIELD>
            <OPTION HINT="123"> [0x01, 0x00] </OPTION>
            <OPTION HINT="123_SYMBOLS"> [0x02, 0x00] </OPTION>
            /* English */
            <OPTION HINT="MULTITAP_UPPERCASE_ABC"> [0x03, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_ABC"> [0x04, 0x00] </OPTION>
            <OPTION HINT="MULTITAP_UPPERCASE_ABC_NO_NUMERIC"> [0x05, 0x00] </OPTION>
            <OPTION HINT="MULTITAP_LOWERCASE_ABC_NO_NUMERIC"> [0x06, 0x00] </OPTION>
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_ABC"> [0x07, 0x00] </OPTION> 
            <OPTION HINT="SMART_LOWERCASE_ABC"> [0x08, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_ABC"> [0x09, 0x00] </OPTION> 
            <OPTION HINT="SMART_FIRST_UPPERCASE_ABC"> [0x0A, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_ARABIC__)
            <OPTION HINT="ARABIC_NUMERIC"> [0x0B, 0x00] </OPTION>
            #endif
            <OPTION HINT="FLOAT_123"> [0x0C, 0x00] </OPTION>
            <OPTION HINT="HK_STROKE"> [0x0D, 0x00] </OPTION>    
            <OPTION HINT="KEYPAD_NUMERIC"> [0x0E, 0x00] </OPTION>
            <OPTION HINT="MAGIC_NUMBER"> [0x0F, 0x00] </OPTION>
            <OPTION HINT="PHONE_NUMBER"> [0x10, 0x00] </OPTION>
            <OPTION HINT="PHONE_NUMBER_WILDCHAR"> [0x11, 0x00] </OPTION>
            <OPTION HINT="SIGNED_123"> [0x12, 0x00] </OPTION>
            <OPTION HINT="SIGNED_FLOAT_123"> [0x13, 0x00] </OPTION>
            <OPTION HINT="SIM_NUMERIC"> [0x14, 0x00] </OPTION>


        /*Afrikaans*/ 
        #if defined(__MMI_MULTITAP_AFRIKAANS__)
            <OPTION HINT="MULTITAP_UPPERCASE_AFRIKAANS"> [0x15, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_AFRIKAANS"> [0x16, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_AFRIKAANS"> [0x17, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_AFRIKAANS__) || defined (__MMI_CSTAR_AFRIKAANS__) ||defined(__MMI_ZI_AFRIKAANS__)
            <OPTION HINT="SMART_LOWERCASE_AFRIKAANS"> [0x18, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_AFRIKAANS"> [0x19, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_AFRIKAANS"> [0x1A, 0x00] </OPTION>
            #endif
        #endif
        /*Albanian*/ 
        #if defined(__MMI_MULTITAP_ALBANIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_ALBANIAN"> [0x1B, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_ALBANIAN"> [0x1C, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_ALBANIAN"> [0x1D, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_ALBANIAN__) || defined (__MMI_CSTAR_ALBANIAN__) ||defined(__MMI_ZI_ALBANIAN__)
            <OPTION HINT="SMART_LOWERCASE_ALBANIAN"> [0x1E, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_ALBANIAN"> [0x1F, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_ALBANIAN"> [0x20, 0x00] </OPTION>
            #endif
        #endif
        /*ARMENIAN*/ 
        #if defined(__MMI_MULTITAP_ARMENIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_ARMENIAN"> [0x21, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_ARMENIAN"> [0x22, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_ARMENIAN"> [0x23, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_ARMENIAN__) || defined (__MMI_CSTAR_ARMENIAN__) ||defined(__MMI_ZI_ARMENIAN__)
            <OPTION HINT="SMART_LOWERCASE_ARMENIAN"> [0x24, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_ARMENIAN"> [0x25, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_ARMENIAN"> [0x26, 0x00] </OPTION>
            #endif
        #endif

        /*Arabic*/
        #if defined(__MMI_MULTITAP_ARABIC__)
            <OPTION HINT="MULTITAP_ARABIC"> [0x27, 0x00] </OPTION> 
        #endif   
        #if defined(__MMI_T9_ARABIC__) || defined(__MMI_ZI_ARABIC__) || defined(__MMI_CSTAR_ARABIC__) || defined(__MMI_GB_ARABIC__)
            <OPTION HINT="SMART_ARABIC"> [0x28, 0x00] </OPTION>
        #endif
        /*Assamese*/
        #if defined(__MMI_MULTITAP_ASSAMESE__)
            <OPTION HINT="MULTITAP_ASSAMESE"> [0x29, 0x00] </OPTION> 
        #endif   
        #if defined(__MMI_T9_ASSAMESE__) || defined(__MMI_ZI_ASSAMESE__) || defined(__MMI_CSTAR_ASSAMESE__)
            <OPTION HINT="SMART_ASSAMESE"> [0x2A, 0x00] </OPTION>
        #endif

        /*Azerbaijani*/ 
        #if defined(__MMI_MULTITAP_AZERBAIJANI__)
            <OPTION HINT="MULTITAP_UPPERCASE_AZERBAIJANI"> [0x2B, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_AZERBAIJANI"> [0x2C, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_AZERBAIJANI"> [0x2D, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_AZERBAIJANI__) || defined (__MMI_CSTAR_AZERBAIJANI__) ||defined(__MMI_ZI_AZERBAIJANI__)
            <OPTION HINT="SMART_LOWERCASE_AZERBAIJANI"> [0x2E, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_AZERBAIJANI"> [0x2F, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_AZERBAIJANI"> [0x30, 0x00] </OPTION>
            #endif
        #endif
        /*Basque*/ 
        #if defined(__MMI_MULTITAP_BASQUE__)
            <OPTION HINT="MULTITAP_UPPERCASE_BASQUE"> [0x31, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_BASQUE"> [0x32, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_BASQUE"> [0x33, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_BASQUE__) || defined (__MMI_CSTAR_BASQUE__) ||defined(__MMI_ZI_BASQUE__)
            <OPTION HINT="SMART_LOWERCASE_BASQUE"> [0x34, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_BASQUE"> [0x35, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_BASQUE"> [0x36, 0x00] </OPTION>
            #endif
        #endif

        /*Bengali*/
        #if defined(__MMI_MULTITAP_BENGALI__)
            <OPTION HINT="MULTITAP_BENGALI"> [0x37, 0x00] </OPTION> 
        #endif   
        #if defined(__MMI_T9_BENGALI__) || defined(__MMI_ZI_BENGALI__) || defined(__MMI_CSTAR_BENGALI__)
            <OPTION HINT="SMART_BENGALI"> [0x38, 0x00] </OPTION>
        #endif

        /*Bulgarian*/ 
        #if defined(__MMI_MULTITAP_BULGARIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_BULGARIAN"> [0x39, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_BULGARIAN"> [0x3A, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_BULGARIAN"> [0x3B, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_BULGARIAN__) || defined (__MMI_CSTAR_BULGARIAN__) ||defined(__MMI_ZI_BULGARIAN__)
            <OPTION HINT="SMART_LOWERCASE_BULGARIAN"> [0x3C, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_BULGARIAN"> [0x3D, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_BULGARIAN"> [0x3E, 0x00] </OPTION>
            #endif
        #endif
        /*Catalan*/ 
        #if defined(__MMI_MULTITAP_CATALAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_CATALAN"> [0x3F, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_CATALAN"> [0x40, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_CATALAN"> [0x41, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_CATALAN__) || defined (__MMI_CSTAR_CATALAN__) ||defined(__MMI_ZI_CATALAN__)
            <OPTION HINT="SMART_LOWERCASE_CATALAN"> [0x42, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_CATALAN"> [0x43, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_CATALAN"> [0x44, 0x00] </OPTION>
            #endif
        #endif
        /*Croatian*/ 
        #if defined(__MMI_MULTITAP_CROATIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_CROATIAN"> [0x45, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_CROATIAN"> [0x46, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_CROATIAN"> [0x47, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_CROATIAN__) || defined (__MMI_CSTAR_CROATIAN__) ||defined(__MMI_ZI_CROATIAN__)
            <OPTION HINT="SMART_LOWERCASE_CROATIAN"> [0x48, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_CROATIAN"> [0x49, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_CROATIAN"> [0x4A, 0x00] </OPTION>
            #endif
        #endif
        /*Czech*/ 
        #if defined(__MMI_MULTITAP_CZECH__)
            <OPTION HINT="MULTITAP_UPPERCASE_CZECH"> [0x4B, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_CZECH"> [0x4C, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_CZECH"> [0x4D, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_CZECH__) || defined (__MMI_CSTAR_CZECH__) ||defined(__MMI_ZI_CZECH__)
            <OPTION HINT="SMART_LOWERCASE_CZECH"> [0x4E, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_CZECH"> [0x4F, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_CZECH"> [0x50, 0x00] </OPTION>
            #endif
        #endif
        /*Danish*/ 
        #if defined(__MMI_MULTITAP_DANISH__)
            <OPTION HINT="MULTITAP_UPPERCASE_DANISH"> [0x51, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_DANISH"> [0x52, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_DANISH"> [0x53, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_DANISH__) || defined (__MMI_CSTAR_DANISH__) ||defined(__MMI_ZI_DANISH__)
            <OPTION HINT="SMART_LOWERCASE_DANISH"> [0x54, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_DANISH"> [0x55, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_DANISH"> [0x56, 0x00] </OPTION>
            #endif
        #endif
        /*Dutch*/ 
        #if defined(__MMI_MULTITAP_DUTCH__)
            <OPTION HINT="MULTITAP_UPPERCASE_DUTCH"> [0x57, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_DUTCH"> [0x58, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_DUTCH"> [0x59, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_DUTCH__) || defined (__MMI_CSTAR_DUTCH__) ||defined(__MMI_ZI_DUTCH__)
            <OPTION HINT="SMART_LOWERCASE_DUTCH"> [0x5A, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_DUTCH"> [0x5B, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_DUTCH"> [0x5C, 0x00] </OPTION>
            #endif
        #endif

        /*Estonian*/ 
        #if defined(__MMI_MULTITAP_ESTONIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_ESTONIAN"> [0x5D, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_ESTONIAN"> [0x5E, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_ESTONIAN"> [0x5F, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_ESTONIAN__) || defined (__MMI_CSTAR_ESTONIAN__) ||defined(__MMI_ZI_ESTONIAN__)
            <OPTION HINT="SMART_LOWERCASE_ESTONIAN"> [0x60, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_ESTONIAN"> [0x61, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_ESTONIAN"> [0x62, 0x00] </OPTION>
            #endif
        #endif
        /*Filipino*/ 
        #if defined(__MMI_MULTITAP_FILIPINO__)
            <OPTION HINT="MULTITAP_UPPERCASE_FILIPINO"> [0x63, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_FILIPINO"> [0x64, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_FILIPINO"> [0x65, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_FILIPINO__) || defined (__MMI_CSTAR_FILIPINO__) ||defined(__MMI_ZI_FILIPINO__)
            <OPTION HINT="SMART_LOWERCASE_FILIPINO"> [0x66, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_FILIPINO"> [0x67, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_FILIPINO"> [0x68, 0x00] </OPTION>
            #endif
        #endif
        /*Finnish*/ 
        #if defined(__MMI_MULTITAP_FINNISH__)
            <OPTION HINT="MULTITAP_UPPERCASE_FINNISH"> [0x69, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_FINNISH"> [0x6A, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_FINNISH"> [0x6B, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_FINNISH__) || defined (__MMI_CSTAR_FINNISH__) ||defined(__MMI_ZI_FINNISH__)
            <OPTION HINT="SMART_LOWERCASE_FINNISH"> [0x6C, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_FINNISH"> [0x6D, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_FINNISH"> [0x6E, 0x00] </OPTION>
            #endif
        #endif
        /*French*/ 
        #if defined(__MMI_MULTITAP_FRENCH__)
            <OPTION HINT="MULTITAP_UPPERCASE_FRENCH"> [0x6F, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_FRENCH"> [0x70, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_FRENCH"> [0x71, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_FRENCH__) || defined (__MMI_CSTAR_FRENCH__) ||defined(__MMI_ZI_FRENCH__) || defined(__MMI_ZI_CA_FRENCH__) || defined(__MMI_ZI_EU_FRENCH__) || defined(__MMI_GB_FRENCH__)
            <OPTION HINT="SMART_LOWERCASE_FRENCH"> [0x72, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_FRENCH"> [0x73, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_FRENCH"> [0x74, 0x00] </OPTION>
            #endif
        #endif
        /*Galician*/ 
        #if defined(__MMI_MULTITAP_GALICIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_GALICIAN"> [0x75, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_GALICIAN"> [0x76, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_GALICIAN"> [0x77, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_GALICIAN__) || defined (__MMI_CSTAR_GALICIAN__) ||defined(__MMI_ZI_GALICIAN__)
            <OPTION HINT="SMART_LOWERCASE_GALICIAN"> [0x78, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_GALICIAN"> [0x79, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_GALICIAN"> [0x7A, 0x00] </OPTION>
            #endif
        #endif

        /*Georgian*/
        #if defined(__MMI_MULTITAP_GEORGIAN__)
            <OPTION HINT="MULTITAP_GEORGIAN"> [0x7B, 0x00] </OPTION> 
        #endif   

        #if defined(__MMI_T9_GEORGIAN__) || defined(__MMI_ZI_GEORGIAN__) || defined(__MMI_CSTAR_GEORGIAN__)
            <OPTION HINT="SMART_GEORGIAN"> [0x7C, 0x00] </OPTION>
        #endif

        /*German*/ 
        #if defined(__MMI_MULTITAP_GERMAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_GERMAN"> [0x7D, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_GERMAN"> [0x7E, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_GERMAN"> [0x7F, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_GERMAN__) || defined (__MMI_CSTAR_GERMAN__) ||defined(__MMI_ZI_GERMAN__)
            <OPTION HINT="SMART_LOWERCASE_GERMAN"> [0x80, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_GERMAN"> [0x81, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_GERMAN"> [0x82, 0x00] </OPTION>
            #endif
        #endif
        /*Greek*/ 
        #if defined(__MMI_MULTITAP_GREEK__)
            <OPTION HINT="MULTITAP_UPPERCASE_GREEK"> [0x83, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_GREEK"> [0x84, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_GREEK"> [0x85, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_GREEK__) || defined (__MMI_CSTAR_GREEK__) ||defined(__MMI_ZI_GREEK__)
            <OPTION HINT="SMART_LOWERCASE_GREEK"> [0x86, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_GREEK"> [0x87, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_GREEK"> [0x88, 0x00] </OPTION>
            #endif
        #endif

        /*Gujarati*/
        #if defined(__MMI_MULTITAP_GUJARATI__)
            <OPTION HINT="MULTITAP_GUJARATI"> [0x89, 0x00] </OPTION> 
        #endif   
        #if defined(__MMI_T9_GUJARATI__) || defined(__MMI_ZI_GUJARATI__) || defined(__MMI_CSTAR_GUJARATI__)
            <OPTION HINT="SMART_GUJARATI"> [0x8A, 0x00] </OPTION>
        #endif

        /*Hausa*/ 
        #if defined(__MMI_MULTITAP_HAUSA__)
            <OPTION HINT="MULTITAP_UPPERCASE_HAUSA"> [0x8B, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_HAUSA"> [0x8C, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_HAUSA"> [0x8D, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_HAUSA__) || defined (__MMI_CSTAR_HAUSA__) ||defined(__MMI_ZI_HAUSA__)
            <OPTION HINT="SMART_LOWERCASE_HAUSA"> [0x8E, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_HAUSA"> [0x8F, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_HAUSA"> [0x90, 0x00] </OPTION>
            #endif
        #endif

        /*Hebrew*/
        #if defined(__MMI_MULTITAP_HEBREW__)
            <OPTION HINT="MULTITAP_HEBREW"> [0x91, 0x00] </OPTION> 
        #endif   
        #if defined(__MMI_T9_HEBREW__) || defined(__MMI_ZI_HEBREW__) || defined(__MMI_CSTAR_HEBREW__)
            <OPTION HINT="SMART_HEBREW"> [0x92, 0x00] </OPTION>
        #endif
        /*Hindi*/
        #if defined(__MMI_MULTITAP_HINDI__)
            <OPTION HINT="MULTITAP_HINDI"> [0x93, 0x00] </OPTION> 
        #endif   
        #if defined(__MMI_T9_HINDI__) || defined(__MMI_ZI_HINDI__) || defined(__MMI_CSTAR_HINDI__) || defined(__MMI_GB_HINDI__)
            <OPTION HINT="SMART_HINDI"> [0x94, 0x00] </OPTION>
        #endif


        /*Hungarian*/ 
        #if defined(__MMI_MULTITAP_HUNGARIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_HUNGARIAN"> [0x95, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_HUNGARIAN"> [0x96, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_HUNGARIAN"> [0x97, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_HUNGARIAN__) || defined (__MMI_CSTAR_HUNGARIAN__) ||defined(__MMI_ZI_HUNGARIAN__)
            <OPTION HINT="SMART_LOWERCASE_HUNGARIAN"> [0x98, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_HUNGARIAN"> [0x99, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_HUNGARIAN"> [0x9A, 0x00] </OPTION>
            #endif
        #endif
        /*Icelandic*/ 
        #if defined(__MMI_MULTITAP_ICELANDIC__)
            <OPTION HINT="MULTITAP_UPPERCASE_ICELANDIC"> [0x9B, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_ICELANDIC"> [0x9C, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_ICELANDIC"> [0x9D, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_ICELANDIC__) || defined (__MMI_CSTAR_ICELANDIC__) ||defined(__MMI_ZI_ICELANDIC__)
            <OPTION HINT="SMART_LOWERCASE_ICELANDIC"> [0x9E, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_ICELANDIC"> [0x9F, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_ICELANDIC"> [0xA0, 0x00] </OPTION>
            #endif
        #endif
        /*Igbo*/ 
        #if defined(__MMI_MULTITAP_IGBO__)
            <OPTION HINT="MULTITAP_UPPERCASE_IGBO"> [0xA1, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_IGBO"> [0xA2, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_IGBO"> [0xA3, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_IGBO__) || defined (__MMI_CSTAR_IGBO__) ||defined(__MMI_ZI_IGBO__)
            <OPTION HINT="SMART_LOWERCASE_IGBO"> [0xA4, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_IGBO"> [0xA5, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_IGBO"> [0xA6, 0x00] </OPTION>
            #endif
        #endif
        /*Indonesian*/ 
        #if defined(__MMI_MULTITAP_INDONESIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_INDONESIAN"> [0xA7, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_INDONESIAN"> [0xA8, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_INDONESIAN"> [0xA9, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_INDONESIAN__) || defined (__MMI_CSTAR_INDONESIAN__) ||defined(__MMI_ZI_INDONESIAN__)||defined(__MMI_GB_INDONESIAN__)
            <OPTION HINT="SMART_LOWERCASE_INDONESIAN"> [0xAA, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_INDONESIAN"> [0xAB, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_INDONESIAN"> [0xAC, 0x00] </OPTION>
            #endif
        #endif
        /*Irish*/ 
        #if defined(__MMI_MULTITAP_IRISH__)
            <OPTION HINT="MULTITAP_UPPERCASE_IRISH"> [0xAD, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_IRISH"> [0xAE, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_IRISH"> [0xAF, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_IRISH__) || defined (__MMI_CSTAR_IRISH__) ||defined(__MMI_ZI_IRISH__)
            <OPTION HINT="SMART_LOWERCASE_IRISH"> [0xB0, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_IRISH"> [0xB1, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_IRISH"> [0xB2, 0x00] </OPTION>
            #endif
        #endif
        /*Italian*/ 
        #if defined(__MMI_MULTITAP_ITALIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_ITALIAN"> [0xB3, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_ITALIAN"> [0xB4, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_ITALIAN"> [0xB5, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_ITALIAN__) || defined (__MMI_CSTAR_ITALIAN__) ||defined(__MMI_ZI_ITALIAN__)
            <OPTION HINT="SMART_LOWERCASE_ITALIAN"> [0xB6, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_ITALIAN"> [0xB7, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_ITALIAN"> [0xB8, 0x00] </OPTION>
            #endif
        #endif


        /*Kannada*/
        #if defined(__MMI_MULTITAP_KANNADA__)
            <OPTION HINT="MULTITAP_KANNADA"> [0xB9, 0x00] </OPTION> 
        #endif   
        #if defined(__MMI_T9_KANNADA__) || defined(__MMI_ZI_KANNADA__) || defined(__MMI_CSTAR_KANNADA__)
            <OPTION HINT="SMART_KANNADA"> [0xBA, 0x00] </OPTION>
        #endif

        /*Kazakh*/ 
        #if defined(__MMI_MULTITAP_KAZAKH__)
            <OPTION HINT="MULTITAP_UPPERCASE_KAZAKH"> [0xBB, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_KAZAKH"> [0xBC, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_KAZAKH"> [0xBD, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_KAZAKH__) || defined (__MMI_CSTAR_KAZAKH__) ||defined(__MMI_ZI_KAZAKH__)
            <OPTION HINT="SMART_LOWERCASE_KAZAKH"> [0xBE, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_KAZAKH"> [0xBF, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_KAZAKH"> [0xC0, 0x00] </OPTION>
            #endif
        #endif

        <OPTION HINT="MULTITAP_KOREAN"> [0xC1, 0x00] </OPTION>

        /*Latvian*/ 
        #if defined(__MMI_MULTITAP_LATVIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_LATVIAN"> [0xC2, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_LATVIAN"> [0xC3, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_LATVIAN"> [0xC4, 0x00] </OPTION> 
            #endif
    #endif

    #if defined(__MMI_T9_LATVIAN__) || defined (__MMI_CSTAR_LATVIAN__) ||defined(__MMI_ZI_LATVIAN__)
        <OPTION HINT="SMART_LOWERCASE_LATVIAN"> [0xC5, 0x00] </OPTION> 
        <OPTION HINT="SMART_UPPERCASE_LATVIAN"> [0xC6, 0x00] </OPTION> 
        #if defined(__MMI_SMART_FIRST_UPPERCASE__)
        <OPTION HINT="SMART_FIRST_UPPERCASE_LATVIAN"> [0xC7, 0x00] </OPTION>
        #endif
    #endif
    /*Lithuanian*/ 
    #if defined(__MMI_MULTITAP_LITHUANIAN__)
        <OPTION HINT="MULTITAP_UPPERCASE_LITHUANIAN"> [0xC8, 0x00] </OPTION>    
        <OPTION HINT="MULTITAP_LOWERCASE_LITHUANIAN"> [0xC9, 0x00] </OPTION>
        #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
        <OPTION HINT="MULTITAP_FIRST_UPPERCASE_LITHUANIAN"> [0xCA, 0x00] </OPTION> 
        #endif
    #endif

    #if defined(__MMI_T9_LITHUANIAN__) || defined (__MMI_CSTAR_LITHUANIAN__) ||defined(__MMI_ZI_LITHUANIAN__)
        <OPTION HINT="SMART_LOWERCASE_LITHUANIAN"> [0xCB, 0x00] </OPTION> 
        <OPTION HINT="SMART_UPPERCASE_LITHUANIAN"> [0xCC, 0x00] </OPTION> 
        #if defined(__MMI_SMART_FIRST_UPPERCASE__)
        <OPTION HINT="SMART_FIRST_UPPERCASE_LITHUANIAN"> [0xCD, 0x00] </OPTION>
        #endif
    #endif
    /*Macedonian*/ 
    #if defined(__MMI_MULTITAP_MACEDONIAN__)
        <OPTION HINT="MULTITAP_UPPERCASE_MACEDONIAN"> [0xCE, 0x00] </OPTION>    
        <OPTION HINT="MULTITAP_LOWERCASE_MACEDONIAN"> [0xCF, 0x00] </OPTION>
        #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
        <OPTION HINT="MULTITAP_FIRST_UPPERCASE_MACEDONIAN"> [0xD0, 0x00] </OPTION> 
        #endif
    #endif

    #if defined(__MMI_T9_MACEDONIAN__) || defined (__MMI_CSTAR_MACEDONIAN__) ||defined(__MMI_ZI_MACEDONIAN__)
        <OPTION HINT="SMART_LOWERCASE_MACEDONIAN"> [0xD1, 0x00] </OPTION> 
        <OPTION HINT="SMART_UPPERCASE_MACEDONIAN"> [0xD2, 0x00] </OPTION> 
        #if defined(__MMI_SMART_FIRST_UPPERCASE__)
        <OPTION HINT="SMART_FIRST_UPPERCASE_MACEDONIAN"> [0xD3, 0x00] </OPTION>
        #endif
    #endif
    /*Malay*/ 
    #if defined(__MMI_MULTITAP_MALAY__)
        <OPTION HINT="MULTITAP_UPPERCASE_MALAY"> [0xD4, 0x00] </OPTION>    
        <OPTION HINT="MULTITAP_LOWERCASE_MALAY"> [0xD5, 0x00] </OPTION>
        #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
          <OPTION HINT="MULTITAP_FIRST_UPPERCASE_MALAY"> [0xD6, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_MALAY__) || defined (__MMI_CSTAR_MALAY__) ||defined(__MMI_ZI_MALAY__)
            <OPTION HINT="SMART_LOWERCASE_MALAY"> [0xD7, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_MALAY"> [0xD8, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_MALAY"> [0xD9, 0x00] </OPTION>
            #endif
        #endif


        /*Malayalam*/
        #if defined(__MMI_MULTITAP_MALAYALAM__)
            <OPTION HINT="MULTITAP_MALAYALAM"> [0xDA, 0x00] </OPTION> 
        #endif 


        #if defined(__MMI_MULTITAP_LAO__)
            <OPTION HINT="MULTITAP_LAO"> [0xDB, 0x00] </OPTION> 
        #endif 

        #if defined(__MMI_MULTITAP_KHMER__)
            <OPTION HINT="MULTITAP_KHMER"> [0xDC, 0x00] </OPTION> 
        #endif 
        #if defined(__MMI_T9_KHMER__) 
            <OPTION HINT="SMART_KHMER"> [0xDD, 0x00] </OPTION>
        #endif
        #if defined(__MMI_MULTITAP_MYANMAR__)
            <OPTION HINT="MULTITAP_MYANMAR"> [0xDE, 0x00] </OPTION> 
        #endif 


        #if defined(__MMI_T9_MALAYALAM__) || defined(__MMI_ZI_MALAYALAM__) || defined(__MMI_CSTAR_MALAYALAM__)
            <OPTION HINT="SMART_MALAYALAM"> [0xDF, 0x00] </OPTION>
        #endif

        /*Marathi*/
        #if defined(__MMI_MULTITAP_MARATHI__)
            <OPTION HINT="MULTITAP_MARATHI"> [0xE0, 0x00] </OPTION> 
        #endif   
        #if defined(__MMI_T9_MARATHI__) || defined(__MMI_ZI_MARATHI__) || defined(__MMI_CSTAR_MARATHI__)
            <OPTION HINT="SMART_MARATHI"> [0xE1, 0x00] </OPTION>
        #endif


        /*Moldovan*/ 
        #if defined(__MMI_MULTITAP_MOLDOVAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_MOLDOVAN"> [0xE2, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_MOLDOVAN"> [0xE3, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_MOLDOVAN"> [0xE4, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_MOLDOVAN__) || defined (__MMI_CSTAR_MOLDOVAN__) ||defined(__MMI_ZI_MOLDOVAN__)
            <OPTION HINT="SMART_LOWERCASE_MOLDOVAN"> [0xE5, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_MOLDOVAN"> [0xE6, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_MOLDOVAN"> [0xE7, 0x00] </OPTION>
            #endif
        #endif
        /*Norwegian*/ 
        #if defined(__MMI_MULTITAP_NORWEGIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_NORWEGIAN"> [0xE8, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_NORWEGIAN"> [0xE9, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_NORWEGIAN"> [0xEA, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_NORWEGIAN__) || defined (__MMI_CSTAR_NORWEGIAN__) ||defined(__MMI_ZI_NORWEGIAN__)
            <OPTION HINT="SMART_LOWERCASE_NORWEGIAN"> [0xEB, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_NORWEGIAN"> [0xEC, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_NORWEGIAN"> [0xED, 0x00] </OPTION>
            #endif
        #endif

        /*Oriya*/
        #if defined(__MMI_MULTITAP_ORIYA__)
            <OPTION HINT="MULTITAP_ORIYA"> [0xEE, 0x00] </OPTION> 
        #endif   
        #if defined(__MMI_T9_ORIYA__) || defined(__MMI_ZI_ORIYA__) || defined(__MMI_CSTAR_ORIYA__)
            <OPTION HINT="SMART_ORIYA"> [0xEF, 0x00] </OPTION>
        #endif

        /*Persian*/
        #if defined(__MMI_MULTITAP_PERSIAN__)
            <OPTION HINT="MULTITAP_PERSIAN"> [0xF0, 0x00] </OPTION> 
        #endif   
        #if defined(__MMI_T9_PERSIAN__) || defined(__MMI_ZI_PERSIAN__) || defined(__MMI_CSTAR_PERSIAN__) || defined(__MMI_GB_PERSIAN__)
            <OPTION HINT="SMART_PERSIAN"> [0xF1, 0x00] </OPTION>
        #endif


        /*Polish*/ 
        #if defined(__MMI_MULTITAP_POLISH__)
            <OPTION HINT="MULTITAP_UPPERCASE_POLISH"> [0xF2, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_POLISH"> [0xF3, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_POLISH"> [0xF4, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_POLISH__) || defined (__MMI_CSTAR_POLISH__) ||defined(__MMI_ZI_POLISH__)
            <OPTION HINT="SMART_LOWERCASE_POLISH"> [0xF5, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_POLISH"> [0xF6, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_POLISH"> [0xF7, 0x00] </OPTION>
            #endif
        #endif
        /*Portuguese*/ 
        #if defined(__MMI_MULTITAP_PORTUGUESE__)
            <OPTION HINT="MULTITAP_UPPERCASE_PORTUGUESE"> [0xF8, 0x00] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_PORTUGUESE"> [0xF9, 0x00] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_PORTUGUESE"> [0xFA, 0x00] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_PORTUGUESE__) || defined (__MMI_CSTAR_PORTUGUESE__) ||defined(__MMI_ZI_EU_PORTUGUESE__)
            <OPTION HINT="SMART_LOWERCASE_PORTUGUESE"> [0xFB, 0x00] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_PORTUGUESE"> [0xFC, 0x00] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_PORTUGUESE"> [0xFD, 0x00] </OPTION>
            #endif
        #endif

        /*Punjabi*/
        #if defined(__MMI_MULTITAP_PUNJABI__)
            <OPTION HINT="MULTITAP_PUNJABI"> [0xFE, 0x00] </OPTION> 
        #endif   
        #if defined(__MMI_T9_PUNJABI__) || defined(__MMI_ZI_PUNJABI__) || defined(__MMI_CSTAR_PUNJABI__)
            <OPTION HINT="SMART_PUNJABI"> [0xFF, 0x00] </OPTION>
        #endif



        /*Romanian*/ 
        #if defined(__MMI_MULTITAP_ROMANIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_ROMANIAN"> [0x00, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_ROMANIAN"> [0x01, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_ROMANIAN"> [0x02, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_ROMANIAN__) || defined (__MMI_CSTAR_ROMANIAN__) ||defined(__MMI_ZI_ROMANIAN__)
            <OPTION HINT="SMART_LOWERCASE_ROMANIAN"> [0x03, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_ROMANIAN"> [0x04, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_ROMANIAN"> [0x05, 0x01] </OPTION>
            #endif
        #endif
        /*Russian*/ 
        #if defined(__MMI_MULTITAP_RUSSIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_RUSSIAN"> [0x06, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_RUSSIAN"> [0x07, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_RUSSIAN"> [0x08, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_RUSSIAN__) || defined (__MMI_CSTAR_RUSSIAN__) ||defined(__MMI_ZI_RUSSIAN__)
            <OPTION HINT="SMART_LOWERCASE_RUSSIAN"> [0x09, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_RUSSIAN"> [0x0A, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_RUSSIAN"> [0x0B, 0x01] </OPTION>
            #endif
        #endif
        /*Serbian*/ 
        #if defined(__MMI_MULTITAP_SERBIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_SERBIAN"> [0x0C, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_SERBIAN"> [0x0D, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_SERBIAN"> [0x0E, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_SERBIAN__) || defined (__MMI_CSTAR_SERBIAN__) ||defined(__MMI_ZI_SERBIAN__)
            <OPTION HINT="SMART_LOWERCASE_SERBIAN"> [0x0F, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_SERBIAN"> [0x10, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_SERBIAN"> [0x11, 0x01] </OPTION>
            #endif
        #endif
        /*Sesotho*/ 
        #if defined(__MMI_MULTITAP_SESOTHO__)
            <OPTION HINT="MULTITAP_UPPERCASE_SESOTHO"> [0x12, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_SESOTHO"> [0x13, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_SESOTHO"> [0x14, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_SESOTHO__) || defined (__MMI_CSTAR_SESOTHO__) ||defined(__MMI_ZI_SESOTHO__)
            <OPTION HINT="SMART_LOWERCASE_SESOTHO"> [0x15, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_SESOTHO"> [0x16, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_SESOTHO"> [0x17, 0x01] </OPTION>
            #endif
        #endif
        /*Slovak*/ 
        #if defined(__MMI_MULTITAP_SLOVAK__)
            <OPTION HINT="MULTITAP_UPPERCASE_SLOVAK"> [0x18, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_SLOVAK"> [0x19, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_SLOVAK"> [0x1A, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_SLOVAK__) || defined (__MMI_CSTAR_SLOVAK__) ||defined(__MMI_ZI_SLOVAK__)|| defined(__MMI_CSTAR_SLOVAKIAN__)
            <OPTION HINT="SMART_LOWERCASE_SLOVAK"> [0x1B, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_SLOVAK"> [0x1C, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_SLOVAK"> [0x1D, 0x01] </OPTION>
            #endif
        #endif
        /*Slovenian*/ 
        #if defined(__MMI_MULTITAP_SLOVENIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_SLOVENIAN"> [0x1E, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_SLOVENIAN"> [0x1F, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_SLOVENIAN"> [0x20, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_SLOVENIAN__) || defined (__MMI_CSTAR_SLOVENIAN__) ||defined(__MMI_ZI_SLOVENIAN__)
            <OPTION HINT="SMART_LOWERCASE_SLOVENIAN"> [0x21, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_SLOVENIAN"> [0x22, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_SLOVENIAN"> [0x23, 0x01] </OPTION>
            #endif
        #endif
        /*Spanish*/ 
        #if defined(__MMI_MULTITAP_SPANISH__)
            <OPTION HINT="MULTITAP_UPPERCASE_SPANISH"> [0x24, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_SPANISH"> [0x25, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_SPANISH"> [0x26, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_SPANISH__) || defined (__MMI_CSTAR_SPANISH__) ||defined(__MMI_ZI_SPANISH__) || defined(__MMI_ZI_EU_SPANISH__) || defined(__MMI_ZI_SA_SPANISH__)
            <OPTION HINT="SMART_LOWERCASE_SPANISH"> [0x27, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_SPANISH"> [0x28, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_SPANISH"> [0x29, 0x01] </OPTION>
            #endif
        #endif

        /*Swahili*/ 
        #if defined(__MMI_MULTITAP_SWAHILI__)
            <OPTION HINT="MULTITAP_UPPERCASE_SWAHILI"> [0x2A, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_SWAHILI"> [0x2B, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_SWAHILI"> [0x2C, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_SWAHILI__) || defined (__MMI_CSTAR_SWAHILI__) ||defined(__MMI_ZI_SWAHILI__)
            <OPTION HINT="SMART_LOWERCASE_SWAHILI"> [0x2D, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_SWAHILI"> [0x2E, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_SWAHILI"> [0x2F, 0x01] </OPTION>
            #endif
        #endif
        /*Swedish*/ 
        #if defined(__MMI_MULTITAP_SWEDISH__)
            <OPTION HINT="MULTITAP_UPPERCASE_SWEDISH"> [0x30, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_SWEDISH"> [0x31, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_SWEDISH"> [0x32, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_SWEDISH__) || defined (__MMI_CSTAR_SWEDISH__) ||defined(__MMI_ZI_SWEDISH__)
            <OPTION HINT="SMART_LOWERCASE_SWEDISH"> [0x33, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_SWEDISH"> [0x34, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_SWEDISH"> [0x35, 0x01] </OPTION>
            #endif
        #endif
        /*Tagalog*/ 
        #if defined(__MMI_MULTITAP_TAGALOG__)
            <OPTION HINT="MULTITAP_UPPERCASE_TAGALOG"> [0x36, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_TAGALOG"> [0x37, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_TAGALOG"> [0x38, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_TAGALOG__) || defined (__MMI_CSTAR_TAGALOG__) ||defined(__MMI_ZI_TAGALOG__)
            <OPTION HINT="SMART_LOWERCASE_TAGALOG"> [0x39, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_TAGALOG"> [0x3A, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_TAGALOG"> [0x3B, 0x01] </OPTION>
            #endif
        #endif

        /*Tamil*/
        #if defined(__MMI_MULTITAP_TAMIL__)
            <OPTION HINT="MULTITAP_TAMIL"> [0x3C, 0x01] </OPTION> 
        #endif   
        #if defined(__MMI_T9_TAMIL__) || defined(__MMI_ZI_TAMIL__) || defined(__MMI_CSTAR_TAMIL__)
            <OPTION HINT="SMART_TAMIL"> [0x3D, 0x01] </OPTION>
        #endif
        /*Telugu*/
        #if defined(__MMI_MULTITAP_TELUGU__)
            <OPTION HINT="MULTITAP_TELUGU"> [0x3E, 0x01] </OPTION> 
        #endif   
        #if defined(__MMI_T9_TELUGU__) || defined(__MMI_ZI_TELUGU__) || defined(__MMI_CSTAR_TELUGU__)
            <OPTION HINT="SMART_TELUGU"> [0x3F, 0x01] </OPTION>
        #endif

        /*Thai*/
        #if defined(__MMI_MULTITAP_THAI__)
            <OPTION HINT="MULTITAP_THAI"> [0x40, 0x01] </OPTION> 
        #endif   
        #if defined(__MMI_T9_THAI__) || defined(__MMI_ZI_THAI__) || defined(__MMI_CSTAR_THAI__)
            <OPTION HINT="SMART_THAI"> [0x41, 0x01] </OPTION>
        #endif

        /*Turkish*/ 
        #if defined(__MMI_MULTITAP_TURKISH__)
            <OPTION HINT="MULTITAP_UPPERCASE_TURKISH"> [0x42, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_TURKISH"> [0x43, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_TURKISH"> [0x44, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_TURKISH__) || defined (__MMI_CSTAR_TURKISH__) ||defined(__MMI_ZI_TURKISH__)
            <OPTION HINT="SMART_LOWERCASE_TURKISH"> [0x45, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_TURKISH"> [0x46, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_TURKISH"> [0x47, 0x01] </OPTION>
            #endif
        #endif
        /*Ukrainian*/ 
        #if defined(__MMI_MULTITAP_UKRAINIAN__)
            <OPTION HINT="MULTITAP_UPPERCASE_UKRAINIAN"> [0x48, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_UKRAINIAN"> [0x49, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_UKRAINIAN"> [0x4A, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_UKRAINIAN__) || defined (__MMI_CSTAR_UKRAINIAN__) ||defined(__MMI_ZI_UKRAINIAN__)
            <OPTION HINT="SMART_LOWERCASE_UKRAINIAN"> [0x4B, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_UKRAINIAN"> [0x4C, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_UKRAINIAN"> [0x4D, 0x01] </OPTION>
            #endif
        #endif

        /*Urdu*/
        #if defined(__MMI_MULTITAP_URDU__)
            <OPTION HINT="MULTITAP_URDU"> [0x4E, 0x01] </OPTION> 
        #endif   
        #if defined(__MMI_T9_URDU__) || defined(__MMI_ZI_URDU__) || defined(__MMI_CSTAR_URDU__)
            <OPTION HINT="SMART_URDU"> [0x4F, 0x01] </OPTION>
        #endif

        /*Vietnamese*/ 
        #if defined(__MMI_MULTITAP_VIETNAMESE__)
            <OPTION HINT="MULTITAP_UPPERCASE_VIETNAMESE"> [0x50, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_VIETNAMESE"> [0x51, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_VIETNAMESE"> [0x52, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_VIETNAMESE__) || defined (__MMI_CSTAR_VIETNAMESE__) ||defined(__MMI_ZI_VIETNAMESE__)
            <OPTION HINT="SMART_LOWERCASE_VIETNAMESE"> [0x53, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_VIETNAMESE"> [0x54, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_VIETNAMESE"> [0x55, 0x01] </OPTION>
            #endif
        #endif
        /*Xhosa*/ 
        #if defined(__MMI_MULTITAP_XHOSA__)
            <OPTION HINT="MULTITAP_UPPERCASE_XHOSA"> [0x56, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_XHOSA"> [0x57, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_XHOSA"> [0x58, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_XHOSA__) || defined (__MMI_CSTAR_XHOSA__) ||defined(__MMI_ZI_XHOSA__)
            <OPTION HINT="SMART_LOWERCASE_XHOSA"> [0x59, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_XHOSA"> [0x5A, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_XHOSA"> [0x5B, 0x01] </OPTION>
            #endif
        #endif
        /*Yoruba*/ 
        #if defined(__MMI_MULTITAP_YORUBA__)
            <OPTION HINT="MULTITAP_UPPERCASE_YORUBA"> [0x5C, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_YORUBA"> [0x5D, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_YORUBA"> [0x5E, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_YORUBA__) || defined (__MMI_CSTAR_YORUBA__) ||defined(__MMI_ZI_YORUBA__)
            <OPTION HINT="SMART_LOWERCASE_YORUBA"> [0x5F, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_YORUBA"> [0x60, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_YORUBA"> [0x61, 0x01] </OPTION>
            #endif
        #endif
        /*Zulu*/ 
        #if defined(__MMI_MULTITAP_ZULU__)
            <OPTION HINT="MULTITAP_UPPERCASE_ZULU"> [0x62, 0x01] </OPTION>    
            <OPTION HINT="MULTITAP_LOWERCASE_ZULU"> [0x63, 0x01] </OPTION>
            #if defined(__MMI_MULTITAP_FIRST_UPPERCASE__)
            <OPTION HINT="MULTITAP_FIRST_UPPERCASE_ZULU"> [0x64, 0x01] </OPTION> 
            #endif
        #endif

        #if defined(__MMI_T9_ZULU__) || defined (__MMI_CSTAR_ZULU__) ||defined(__MMI_ZI_ZULU__)
            <OPTION HINT="SMART_LOWERCASE_ZULU"> [0x65, 0x01] </OPTION> 
            <OPTION HINT="SMART_UPPERCASE_ZULU"> [0x66, 0x01] </OPTION> 
            #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_ZULU"> [0x67, 0x01] </OPTION>
            #endif
        #endif


        /* dialects*/
        #if defined(__MMI_ZI_UK_ENGLISH__)
            <OPTION HINT="SMART_UPPERCASE_UK_ABC"> [0x68, 0x01] </OPTION>
            <OPTION HINT="SMART_LOWERCASE_UK_ABC"> [0x69, 0x01] </OPTION>
        #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_UK_ABC"> [0x6A, 0x01] </OPTION>
        #endif
        #endif /* defined(__MMI_ZI_UK_ENGLISH__)*/ 

        #if defined(__MMI_ZI_CA_FRENCH__)
            <OPTION HINT="SMART_UPPERCASE_CA_FRENCH"> [0x6B, 0x01] </OPTION>
            <OPTION HINT="SMART_LOWERCASE_CA_FRENCH"> [0x6C, 0x01] </OPTION>
        #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_CA_FRENCH"> [0x6D, 0x01] </OPTION>
        #endif
        #endif /* defined(__MMI_ZI_CA_FRENCH__)*/ 

        #if defined(__MMI_CSTAR_HINGLISH__) || defined(__MMI_GB_HINGLISH__)
             <OPTION HINT="SMART_UPPERCASE_HINGLISH"> [0x6E, 0x01] </OPTION>
             <OPTION HINT="SMART_LOWERCASE_HINGLISH"> [0x6F, 0x01] </OPTION>
        #endif/* #if defined(__MMI_CSTAR_HINGLISH__) || defined(__MMI_GB_HINGLISH__) */

        #if defined(__MMI_ZI_SA_SPANISH__)
            <OPTION HINT="SMART_UPPERCASE_SA_SPANISH"> [0x70, 0x01] </OPTION>
            <OPTION HINT="SMART_LOWERCASE_SA_SPANISH"> [0x71, 0x01] </OPTION>
        #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_SA_SPANISH"> [0x72, 0x01] </OPTION>
        #endif
        #endif /* defined(__MMI_ZI_SA_SPANISH__)*/ 


        #if defined(__MMI_ZI_SA_PORTUGUESE__)
            <OPTION HINT="SMART_UPPERCASE_SA_PORTUGUESE"> [0x73, 0x01] </OPTION>
            <OPTION HINT="SMART_LOWERCASE_SA_PORTUGUESE"> [0x74, 0x01] </OPTION>
        #if defined(__MMI_SMART_FIRST_UPPERCASE__)
            <OPTION HINT="SMART_FIRST_UPPERCASE_SA_PORTUGUESE"> [0x75, 0x01] </OPTION>
        #endif
        #endif /* defined(__MMI_ZI_SA_PORTUGUESE__) */ 


            /* Chinese*/
            <OPTION HINT="TR_BOPOMO"> [0x76, 0x01] </OPTION>
            #if (defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__))
            <OPTION HINT="TR_MULTITAP_BOPOMO"> [0x77, 0x01] </OPTION>
            #endif
            #if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)
            <OPTION HINT="TR_STROKE"> [0x78, 0x01] </OPTION>
            #endif

            #if (defined(__MMI_ZI_TR_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_TR_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__))
            <OPTION HINT="QUICK_SEARCH_BOPOMO"> [0x79, 0x01] </OPTION>
            #endif
            #if defined(__MMI_ZI_HK_CHINESE__) && defined(__MMI_ZI_STROKE_INPUT__)
            <OPTION HINT="QUICK_SEARCH_HK_STROKE"> [0x7A, 0x01] </OPTION>    
            #endif
            #if (defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__))  || (defined(__MMI_GB_SM_CHINESE__) && defined(__MMI_GB_MULTITAP_PHONETIC_INPUT__))
            <OPTION HINT="QUICK_SEARCH_PINYIN"> [0x7B, 0x01] </OPTION>
            #endif
            #if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_SM_STROKE_INPUT__)
            <OPTION HINT="QUICK_SEARCH_SM_STROKE"> [0x7C, 0x01] </OPTION>
            #endif
            #if defined(__MMI_T9_TR_CHINESE__) && defined(__MMI_T9_STROKE_INPUT__)
            <OPTION HINT="QUICK_SEARCH_TR_STROKE"> [0x7D, 0x01] </OPTION>
            #endif
            #if (defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_MULTITAP_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_MULTITAP_PHONETIC_INPUT__)) ||(defined(__MMI_GB_SM_CHINESE__) && defined(__MMI_GB_MULTITAP_PHONETIC_INPUT__)) 
            <OPTION HINT="SM_MULTITAP_PINYIN"> [0x7E, 0x01] </OPTION>
            #endif
            #if (defined(__MMI_ZI_SM_CHINESE__) && defined(__MMI_ZI_SMART_PHONETIC_INPUT__)) || (defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_T9_SMART_PHONETIC_INPUT__)) || (defined(__MMI_CSTAR_SM_CHINESE__) && defined(__MMI_CSTAR_SMART_PHONETIC_INPUT__)) || (defined(__MMI_GB_SM_CHINESE__) && defined(__MMI_GB_SMART_PHONETIC_INPUT__))
            <OPTION HINT="SM_PINYIN"> [0x7F, 0x01] </OPTION>
            #endif
            #if defined(__MMI_T9_SM_CHINESE__) && defined(__MMI_SM_STROKE_INPUT__)
            <OPTION HINT="SM_STROKE"> [0x80, 0x01] </OPTION>
            #endif
        </FIELD>   
    </CACHEDATA>
    <CACHEDATA type="short" id="RESTORE_PREFER_INPUT_METHOD">
        <DEFAULT_VALUE> [0x0D, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> Short Cache </DESCRIPTION>
    </CACHEDATA>
     <CACHEDATA type="short" id="NVRAM_SETTING_WRITING_LANG" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> current writing language value </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="short" id="NVRAM_SETTING_WRITING_LANG_SUB" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> current sub writing language value </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="short" id="NVRAM_SETTING_ENABLED_WRITING_LANGUAGE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF, 0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> Double cache </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_SETTING_PEN_SPEED" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> pen speed </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_SETTING_LANGUAGE_FOLLOW_VK" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x02] </DEFAULT_VALUE>
        <DESCRIPTION> language follow vk, default value is IME_WRITING_LANG_ABC </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_SETTING_HANDWRITING_ON" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00] </DEFAULT_VALUE>
        <DESCRIPTION> nvram handwriting on </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_SETTING_PEN_WIDTH" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> pen trace width </DESCRIPTION>
    </CACHEDATA>
    <CACHEDATA type="byte" id="NVRAM_SETTING_STROKE_COLOR_INDEX" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x01] </DEFAULT_VALUE>
        <DESCRIPTION> pen stroke color index </DESCRIPTION>
    </CACHEDATA>

#ifdef __MMI_IME_FUZZY_PINYIN__
	<CACHEDATA type="short" id="NVRAM_SETTING_ENABLED_FUZZY_PINYIN" restore_flag="TRUE">
        <DEFAULT_VALUE> [0x00, 0x00] </DEFAULT_VALUE>
        <DESCRIPTION> current enabled fuzzy pinyin </DESCRIPTION>
    </CACHEDATA>      
#endif
#if defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__)
    <CACHEDATA type="byte" id="NVRAM_PEN_SPEED" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> pen speed </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_PEN_COLOR" restore_flag="TRUE">
        <DEFAULT_VALUE> [0xFF] </DEFAULT_VALUE>
        <DESCRIPTION> pen color </DESCRIPTION>
    </CACHEDATA>
#endif /* defined(__MMI_TOUCH_SCREEN__) && !defined(__MMI_NO_HANDWRITING__) */

<TIMER id="POPUP_TIMER"/>
<TIMER id="POPUP_SUBLCD"/>
</APP>


