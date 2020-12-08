#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>
#ifdef __MMI_CALCULATOR__
<APP id="VAPP_CALCULATOR" 
    package_name="native.mtk.calculator"
    name="STR_ID_VAPP_CALCULATOR_TITLE"
    img="IMG_ID_VAPP_CALCULATOR_MAIN_MENU_ICON"
    launch="vapp_calculator_launch" type="venus">
#ifdef __LOW_COST_SUPPORT_COMMON__
		<MEMORY base="100*1024" vrt_mem_factor = "2.0f"/>
#else
    <MEMORY base="200*1024" />
#endif
    <LAYOUT file="vapp_calculator.xml" />
    
    <!-----------------------------------------------------String Resource Area------------------------------------------------------>
	<STRING id="STR_ID_VAPP_CALCULATOR_TITLE"/>
	<STRING id="STR_ID_VAPP_CALCULATOR_ERROR_INVALID_EXPRESSION"/>
	<STRING id="STR_ID_VAPP_CALCULATOR_ERROR_EXPRESSION_TOO_LONG"/>
	<STRING id="STR_ID_VAPP_CALCULATOR_ERROR_UNABLE_TO_DIVIDE_BY_ZERO"/>
	<STRING id="STR_ID_VAPP_CALCULATOR_ERROR_UNABLE_TO_EXTRACT_A_ROOT_OF_NEGATIVE"/>
	<STRING id="STR_ID_VAPP_CALCULATOR_ERROR_MAXIMUM_NUMBER_OF_CHARACTERS_EXCEEDED"/>
		<STRING id="STR_ID_VAPP_CALCULATOR_ERROR_INVALID_OPERAND"/>
	<STRING id="STR_ID_VAPP_CALCULATOR_ERROR_RESULT_TOO_LARGE_TO_DISPLAY"/>	
	<STRING id="STR_ID_VAPP_CALCULATOR_ERROR_BRACKETS_DO_NOT_MATCH"/>	
    
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <THEME>
        <IMAGE id="IMG_ID_VAPP_CALCULATOR_MAIN_MENU_ICON" desc="Main menu calculator icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\Calculator.png"</IMAGE>
    </THEME>
    
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BG">RES_IMG_ROOT"\\\\Calculator\\\\bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_LCD">RES_IMG_ROOT"\\\\Calculator\\\\lcd.9slice.png" </IMAGE>
#ifndef __LOW_COST_SUPPORT_COMMON__
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_HIGHT_LIGHT">RES_IMG_ROOT"\\\\Calculator\\\\high_light.9slice.png"</IMAGE>
#endif
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_EQUAL">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_equal.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_EQUAL_BG">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_equal.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_PLUS">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_plus.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_MINUS">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_minus.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_MULT">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_mult.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_DIV">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_div.png"</IMAGE>    
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_OPEN_PAREN">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_left_paren.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_CLOSE_PAREN">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_right_paren.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_RECIPROCAL">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_reciprocal.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_SQUARE">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_square.png"</IMAGE>   
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_SQUARE_ROOT">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_square_root.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_BACKSPACE">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_backspace.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_AC">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_all_clear.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_AC_BG">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_all_clear.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_NUM_BG">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_num.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_CALCULATOR_BUTTON_PUNC_BG">RES_IMG_ROOT"\\\\Calculator\\\\btn\\\\btn_punc.9slice.png"</IMAGE>

</APP>
#endif  /*__MMI_CALCULATOR__*/
