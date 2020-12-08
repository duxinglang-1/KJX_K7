#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#ifdef __MMI_CONVERTER__
<APP id="VAPP_CONVERTER"
    package_name="native.mtk.app_converter"
    name="STR_ID_VAPP_CONVERTER"
    img="IMG_ID_VAPP_CONVERTER"
    launch="vappConverterLaunch" type="venus">
    <MEMORY base="350000" />

    // string id
    // <STRING id="STR_ID_VAPP_CONVERTER"/>
    <STRING id="STR_ID_VAPP_CONVERTER_TYPE"/>
    <STRING id="STR_ID_VAPP_CONVERTER_WEIGHT"/>
    <STRING id="STR_ID_VAPP_CONVERTER_LENGTH"/>
    <STRING id="STR_ID_VAPP_CONVERTER_CURRENCY"/>

    /* The following weight units string will be used with enum value, don't insert other string in between,
       the same to other units, currency don't need follow this rule */
    // WEIGHT   
    <STRING id="STR_ID_VAPP_CONVERTER_KILOGRAM"/>
    <STRING id="STR_ID_VAPP_CONVERTER_POUND"/>
    <STRING id="STR_ID_VAPP_CONVERTER_OUNCE"/>
    <STRING id="STR_ID_VAPP_CONVERTER_UNIT1"/>    
    <STRING id="STR_ID_VAPP_CONVERTER_UNIT2"/>
    <STRING id="STR_ID_VAPP_CONVERTER_CURRENCY1"/>
    <STRING id="STR_ID_VAPP_CONVERTER_CURRENCY2"/>

    // LENGTH
    <STRING id="STR_ID_VAPP_CONVERTER_CENTERMETER"/>
    <STRING id="STR_ID_VAPP_CONVERTER_METER"/>
    <STRING id="STR_ID_VAPP_CONVERTER_KILOMETER"/>
    <STRING id="STR_ID_VAPP_CONVERTER_INCH"/>
    <STRING id="STR_ID_VAPP_CONVERTER_YARD"/>
    <STRING id="STR_ID_VAPP_CONVERTER_FOOT"/>
    <STRING id="STR_ID_VAPP_CONVERTER_MILE"/>

    // CURRENCY
    <STRING id="STR_ID_VAPP_CONVERTER_CHY"/>
    <STRING id="STR_ID_VAPP_CONVERTER_USD"/>
    <STRING id="STR_ID_VAPP_CONVERTER_EUR"/>
    <STRING id="STR_ID_VAPP_CONVERTER_GBP"/>
    <STRING id="STR_ID_VAPP_CONVERTER_HKD"/>
    <STRING id="STR_ID_VAPP_CONVERTER_JPY"/>
    <STRING id="STR_ID_VAPP_CONVERTER_KRW"/>
    <STRING id="STR_ID_VAPP_CONVERTER_SEK"/>
    <STRING id="STR_ID_VAPP_CONVERTER_AUD"/>
    <STRING id="STR_ID_VAPP_CONVERTER_CHF"/>

    // OTHERS
    <STRING id="STR_ID_VAPP_CONVERTER_SET_CURRECNY_RATES"/>
    <STRING id="STR_ID_VAPP_CONVERTER_SELECT_A_CONVERTER_TYPE"/>
    <STRING id="STR_ID_VAPP_CONVERTER_SELECT_A_UNIT"/>
    <STRING id="STR_ID_VAPP_CONVERTER_SELECT_A_CURRENCY"/>
    <STRING id="STR_ID_VAPP_CONVERTER_ERROR_MAXIMUM_VALUE_EXCEEDED"/>
    <STRING id="STR_ID_VAPP_CONVERTER_INVALID_CURRECNY_RATE"/>
    <STRING id="STR_ID_VAPP_CONVERTER_EMPTY_CURRECNY_RATE"/>

    // image
    <THEME>
        <IMAGE id = "IMG_ID_VAPP_CONVERTER" desc = "Main menu converter icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Converters.png"</IMAGE>    
    </THEME>
    <IMAGE id = "IMG_ID_VAPP_CONVERTER_SET_CURRENCY">RES_IMG_ROOT"\\\\Converter\\\\SetCurrency.png"</IMAGE>
    // mmi cache
    <CACHEDATA type="byte" id="NVRAM_CONVERTER_LAST_USE_TYPE" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X00] </DEFAULT_VALUE>
        <DESCRIPTION> current value 0,1,2 </DESCRIPTION>
    </CACHEDATA>

    <CACHEDATA type="byte" id="NVRAM_CONVERTER_FIRST_LAUNCH" restore_flag="TRUE">
        <DEFAULT_VALUE> [0X01] </DEFAULT_VALUE>
        <DESCRIPTION> current value 0,1 </DESCRIPTION>
    </CACHEDATA>
</APP>
#endif

