/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "MMIDataType.h"
/* No need to include this file at resgen time #include "gui_virtual_keyboard_misc_res.h" */ 
#include "CustDataProts.h"
#include "MMI_features.h"
#include "CustResDef.h"

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_VIRTUAL_KEYBOARD_MISC">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->
    
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */    
 
 		<!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
#if defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__)

<IMAGE id = "IMG_ID_VKBD_CUSTOM_LARGE_ICON"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\VK_LARGE_ICON_BG.9slice.png"</IMAGE>;


<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_OPTION_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_LIST_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_OPTION_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_LIST_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_OPTION_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_LIST_D.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_MATRIX_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_MATRIX_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_MATRIX_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_MATRIX_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_MATRIX_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_MATRIX_D.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_HANDWRITING_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_HANDWRITING_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_HANDWRITING_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_HANDWRITING_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_INPUT_STYLE_HANDWRITING_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_HANDWRITING_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_OPTION_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\KEY_LIST_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_OPTION_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\KEY_LIST_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_OPTION_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\KEY_LIST_D.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_MATRIX_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\KEY_MATRIX_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_MATRIX_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\KEY_MATRIX_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_MATRIX_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\KEY_MATRIX_D.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_QWERTY_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\KEY_HW_HW_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_QWERTY_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\KEY_HW_HW_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_HANDWRITING_INPUT_STYLE_QWERTY_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\KEY_HW_HW_D.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_HANDWRITING_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\KEY_MATRIX_HANDWRITING_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_HANDWRITING_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\KEY_MATRIX_HANDWRITING_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_HANDWRITING_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\KEY_MATRIX_HANDWRITING_D.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_OPTION_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\KEY_MATRIX_LIST_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_OPTION_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\KEY_MATRIX_LIST_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_OPTION_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\KEY_MATRIX_LIST_D.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_QWERTY_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\KEY_MATRIX_QWERTY_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_QWERTY_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\KEY_MATRIX_QWERTY_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_INPUT_STYLE_QWERTY_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\KEY_MATRIX_QWERTY_D.png"</IMAGE>;


<IMAGE id = "IMG_ID_VKBD_CUSTOM_SYM_LOCK_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_SYM_LOCK_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_SYM_LOCK_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_SYM_LOCK_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_SYM_LOCK_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_SYM_LOCK_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_SYM_UNLOCK_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_SYM_UNLOCK_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_SYM_UNLOCK_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_SYM_UNLOCK_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_SYM_UNLOCK_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_SYM_UNLOCK_D.png"</IMAGE>;



<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ABC_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_ABC_LOWER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ABC_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_ABC_LOWER_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ABC_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_ABC_LOWER_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ABC_UPPERCASE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_ABC_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ABC_UPPERCASE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_ABC_UPPER_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ABC_UPPERCASE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_ABC_UPPER_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ABC_FIRST_UPPERCASE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_ABC_FIRST_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ABC_FIRST_UPPERCASE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_ABC_FIRST_UPPER_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ABC_FIRST_UPPERCASE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_ABC_FIRST_UPPER_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_NUMBER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_NUMBER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_NUMBER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_NUMBER_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_NUMBER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_NUMBER_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_PINYIN_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_SM_PINYIN_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_PINYIN_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_SM_PINYIN_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_PINYIN_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_SM_PINYIN_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SM_STROKE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_SM_STROKE_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SM_STROKE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_SM_STROKE_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SM_STROKE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_SM_STROKE_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ZHUYIN_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_TR_ZHUYIN_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ZHUYIN_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_TR_ZHUYIN_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_ZHUYIN_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_TR_ZHUYIN_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_TR_STROKE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_TR_STROKE_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_TR_STROKE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_TR_STROKE_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_TR_STROKE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\images\\\\ICON_IME_TR_STROKE_N.png"</IMAGE>;


<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ABC_LOWER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ABC_LOWER_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ABC_LOWER_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_UPPERCASE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ABC_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_UPPERCASE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ABC_UPPER_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_UPPERCASE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ABC_UPPER_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_FIRST_UPPERCASE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ABC_FIRST_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_FIRST_UPPERCASE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ABC_FIRST_UPPER_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ABC_FIRST_UPPERCASE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ABC_FIRST_UPPER_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_NUMBER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_NUMBER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_NUMBER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_NUMBER_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_NUMBER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_NUMBER_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_ACTIVATE_ITEM"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\checkbox\\\\CK_V.bmp"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_IND_NUMBER_AND_SYMBOL"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Inpute_English.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_IND_ABC_NUMBER_AND_SYMBOL"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Inpute_Chinese.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_IND_SYMBOL"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Inpute_Symbol.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_LONGTAP_POPUP_BG"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Character\\\\Latin\\\\VK_POPUP_ICON_BG.9slice.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PINYIN_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_SM_PINYIN_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PINYIN_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_SM_PINYIN_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PINYIN_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_SM_PINYIN_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SM_STROKE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_SM_STROKE_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SM_STROKE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_SM_STROKE_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SM_STROKE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_SM_STROKE_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ZHUYIN_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TR_ZHUYIN_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ZHUYIN_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TR_ZHUYIN_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ZHUYIN_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TR_ZHUYIN_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TR_STROKE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TR_STROKE_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TR_STROKE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TR_STROKE_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TR_STROKE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TR_STROKE_N.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_FIRST_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_VI_FIRST_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_FIRST_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_VI_FIRST_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_FIRST_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_VI_FIRST_UPPER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_LOWER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_VI_LOWER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_LOWER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_VI_LOWER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_LOWER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_VI_LOWER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_VI_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_VI_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_VI_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_VI_UPPER_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_FIRST_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_PT_FIRST_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_FIRST_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_PT_FIRST_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_FIRST_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_PT_FIRST_UPPER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_LOWER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_PT_LOWER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_LOWER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_PT_LOWER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_LOWER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_PT_LOWER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_PT_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_PT_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_PT_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_PT_UPPER_H.png"</IMAGE>;
   
<IMAGE id="IMG_ID_VKBD_CUSTOM_ICON_QWERTY_HI_UPPER_N" > CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_HI_N.png"</IMAGE>;
<IMAGE id=" IMG_ID_VKBD_CUSTOM_ICON_QWERTY_HI_UPPER_D" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_HI_D.png"</IMAGE>;
<IMAGE id="  IMG_ID_VKBD_CUSTOM_ICON_QWERTY_HI_UPPER_H" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_HI_H.png"</IMAGE>;

   
<IMAGE id="IMG_ID_VKBD_CUSTOM_ICON_QWERTY_AR_UPPER_N" > CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_AR_N.png"</IMAGE>;
<IMAGE id=" IMG_ID_VKBD_CUSTOM_ICON_QWERTY_AR_UPPER_D" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_AR_D.png"</IMAGE>;
<IMAGE id="  IMG_ID_VKBD_CUSTOM_ICON_QWERTY_AR_UPPER_H" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_AR_H.png"</IMAGE>;

  
<IMAGE id="IMG_ID_VKBD_CUSTOM_ICON_QWERTY_BN_UPPER_N" > CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_BN_N.png"</IMAGE>;
<IMAGE id=" IMG_ID_VKBD_CUSTOM_ICON_QWERTY_BN_UPPER_D" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_BN_D.png"</IMAGE>;
<IMAGE id="  IMG_ID_VKBD_CUSTOM_ICON_QWERTY_BN_UPPER_H" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_BN_H.png"</IMAGE>;

   
<IMAGE id="IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TH_UPPER_N" > CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TH_N.png"</IMAGE>;
<IMAGE id=" IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TH_UPPER_D" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TH_D.png"</IMAGE>;
<IMAGE id="  IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TH_UPPER_H" >CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TH_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_FIRST_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_RU_FIRST_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_FIRST_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_RU_FIRST_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_FIRST_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_RU_FIRST_UPPER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_LOWER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_RU_LOWER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_LOWER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_RU_LOWER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_LOWER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_RU_LOWER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_RU_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_RU_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_RU_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_RU_UPPER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_FIRST_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TURKISH_FIRST_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_FIRST_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TURKISH_FIRST_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_FIRST_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TURKISH_FIRST_UPPER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_LOWER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TURKISH_LOWER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_LOWER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TURKISH_LOWER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_LOWER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TURKISH_LOWER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TURKISH_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TURKISH_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_TU_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_TURKISH_UPPER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_FIRST_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_MALAY_FIRST_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_FIRST_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_MALAY_FIRST_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_FIRST_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_MALAY_FIRST_UPPER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_LOWER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_MALAY_LOWER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_LOWER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_MALAY_LOWER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_LOWER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_MALAY_LOWER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_MALAY_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_MALAY_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ML_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_MALAY_UPPER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_FIRST_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ID_FIRST_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_FIRST_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ID_FIRST_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_FIRST_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ID_FIRST_UPPER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_LOWER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ID_LOWER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_LOWER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ID_LOWER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_LOWER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ID_LOWER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ID_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ID_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ID_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ID_UPPER_H.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_FIRST_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ES_FIRST_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_FIRST_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ES_FIRST_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_FIRST_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ES_FIRST_UPPER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_LOWER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ES_LOWER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_LOWER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ES_LOWER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_LOWER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ES_LOWER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_UPPER_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ES_UPPER_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_UPPER_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ES_UPPER_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_ES_UPPER_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\images\\\\ICON_IME_ES_UPPER_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SEARCH_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_Search_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SEARCH_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_Search_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SEARCH_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_Search_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_DONE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_Done_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_DONE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_Done_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_DONE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\KEY_Done_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SEARCH_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_Search_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SEARCH_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_Search_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SEARCH_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_Search_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_DONE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_Done_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_DONE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_Done_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_DONE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Character\\\\Common\\\\KEY_Done_H.png"</IMAGE>;

#if defined(__MMI_MAINLCD_480X800__)
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\72x71_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\72x71_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\72x71_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\120x54_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\120x54_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\120x54_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\120x85_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\120x85_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\120x85_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\200x54_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\200x54_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\200x54_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\72x68_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\72x68_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\72x68_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\160x54_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\160x54_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\160x54_Blue_H.png"</IMAGE>;

#elif defined(__MMI_MAINLCD_320X480__)
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\48x42_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\48x42_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\48x42_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\72x36_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\72x36_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\72x36_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\80x50_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\80x50_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\80x50_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\120x36_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\120x36_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\120x36_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\48x40_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\48x40_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\48x40_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\96x36_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\96x36_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\96x36_Blue_H.png"</IMAGE>;

#elif defined(__MMI_MAINLCD_240X400__)
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\36x31_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\36x31_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\36x31_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\48x28_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\48x28_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\48x28_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\60x36_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\60x36_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\60x36_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\100x28_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\100x28_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\100x28_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\36x31_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\36x31_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\36x31_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\80x28_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\80x28_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\80x28_Blue_H.png"</IMAGE>;

#elif defined(__MMI_MAINLCD_240X320__)
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\36x31_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\36x31_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background\\\\36x31_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\48x28_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\48x28_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_QWERTY_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Qwerty\\\\Background_Landscape\\\\48x28_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\60x31_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\60x31_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background\\\\60x31_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\80x28_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\80x28_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_MATRIX_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\Matrix\\\\Background_Landscape\\\\80x28_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\36x31_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\36x31_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background\\\\36x31_Blue_H.png"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\48x28_Blue_N.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\48x28_Blue_D.png"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_ICON_HW_SPECIAL_ENTER_BG_LANDSCAPE_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\VirtualKeyboard\\\\HW\\\\Background_Landscape\\\\48x28_Blue_H.png"</IMAGE>;

#endif

<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A1_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00A1_N.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A1_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00A1_H.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A1_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00A1_D.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A1_L"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00A1_L.PNG"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A4_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00A4_N.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A4_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00A4_H.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A4_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00A4_D.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00A4_L"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00A4_L.PNG"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00BF_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00BF_N.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00BF_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00BF_H.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00BF_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00BF_D.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_QWERTY_CHARACTER_00BF_L"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\QWERTY\\\\CHARACTER\\\\COMMON\\\\KEY_00BF_L.PNG"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005B_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_005B_N.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005B_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_005B_H.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005B_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_005B_D.PNG"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005D_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_005D_N.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005D_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_005D_H.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005D_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_005D_D.PNG"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005E_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_005E_N.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005E_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_005E_H.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_005E_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_005E_D.PNG"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_0060_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_0060_N.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_0060_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_0060_H.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_0060_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_0060_D.PNG"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A1_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_00A1_N.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A1_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_00A1_H.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A1_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_00A1_D.PNG"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A4_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_00A4_N.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A4_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_00A4_H.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00A4_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_00A4_D.PNG"</IMAGE>;

<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00BF_N"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_00BF_N.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00BF_H"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_00BF_H.PNG"</IMAGE>;
<IMAGE id = "IMG_ID_VKBD_CUSTOM_MATRIX_CHARACTER_00BF_D"> CUST_IMG_PATH"\\\\MainLCD\\\\UIELEMENT\\\\VIRTUALKEYBOARD\\\\MATRIX\\\\CHARACTER\\\\COMMON\\\\KEY_00BF_D.PNG"</IMAGE>;

#endif /*  defined(__MMI_UI_VIRTUAL_KEYBOARD_DEFAULT_VERSION_2__) */

    <!------------------------------------------------------Other Resource---------------------------------------------------------->

</APP>

