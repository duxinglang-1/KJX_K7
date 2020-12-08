/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#ifdef __ALIPAY_SUPPORT__

/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

<APP id="APP_ALIPAY_ADP" name="STR_ID_ALIPAY_START">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */

    <STRING id="STR_ID_ALIPAY_DEMO_LIST1"/>
    <STRING id="STR_ID_ALIPAY_DEMO_LIST2"/>
    <STRING id="STR_ID_ALIPAY_DEMO_LIST3"/>
    <STRING id="STR_ID_ALIPAY_DEMO_LIST4"/>
    <STRING id="STR_ID_ALIPAY_DEMO_LIST5"/>
    <STRING id="STR_ID_ALIPAY_DEMO_LIST6"/>
    <STRING id="STR_ID_ALIPAY_DEMO_LIST7"/>
    
    <STRING id="STR_ID_ALIPAY_DEMO_ORDER1"/>
    <STRING id="STR_ID_ALIPAY_DEMO_ORDER2"/>
    <STRING id="STR_ID_ALIPAY_DEMO_ORDER3"/>
    <STRING id="STR_ID_ALIPAY_DEMO_ORDER4"/>
    <STRING id="STR_ID_ALIPAY_DEMO_ORDER5"/>
    <STRING id="STR_ID_ALIPAY_DEMO_ORDER6"/>
    <STRING id="STR_ID_ALIPAY_DEMO_ORDER7"/>
    <STRING id="STR_ID_ALIPAY_DEMO_TITLE"/>
    
    <STRING id="STR_ID_ALIPAY_HELP"/>
    <STRING id="STR_ID_ALIPAY_START"/>
   
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    /* Image Id and path of you Application , you can use compile option in Path, but need out of "" */
    
    #define ALIPAY_IMG_PATH    CUST_IMG_PATH"\\\\MainLCD\\\\alipay\\\\"

    <IMAGE id="IMG_ID_ALIPAY_BOTTOM">ALIPAY_IMG_PATH"bottom.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_LARGE">ALIPAY_IMG_PATH"error_large.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_SAMLL">ALIPAY_IMG_PATH"error_small.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_GAP">ALIPAY_IMG_PATH"gap.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_INFO_LARGE">ALIPAY_IMG_PATH"info_large.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_INFO_SMALL">ALIPAY_IMG_PATH"info_small.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_LIST_NORMAL">ALIPAY_IMG_PATH"list_normal.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_LIST_FOCUS">ALIPAY_IMG_PATH"list_focus.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_LOGO">ALIPAY_IMG_PATH"logo.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_LIST_TITLE">ALIPAY_IMG_PATH"list_title.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_QUESION_LARGE">ALIPAY_IMG_PATH"question_large.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_QUESION_SMALL">ALIPAY_IMG_PATH"question_small.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_SUCESS_LARGE">ALIPAY_IMG_PATH"success_large.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_SUCESS_SMALL">ALIPAY_IMG_PATH"success_small.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_TITLE">ALIPAY_IMG_PATH"title.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_WARNING_LARGE">ALIPAY_IMG_PATH"warning_large.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_WARNING_SMALL">ALIPAY_IMG_PATH"warning_small.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_BUTTON_NORMAL">ALIPAY_IMG_PATH"button\\\\button_n.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_BUTTON_FOCUS">ALIPAY_IMG_PATH"button\\\\button_focus.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_INPUTBOX_NORMAL_LEFT">ALIPAY_IMG_PATH"input\\\\inputbox_n_left.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_INPUTBOX_NORMAL_MID">ALIPAY_IMG_PATH"input\\\\inputbox_n_mid.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_INPUTBOX_NORMAL_RIGHT">ALIPAY_IMG_PATH"input\\\\inputbox_n_right.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_INPUTBOX_FOCUS_LEFT">ALIPAY_IMG_PATH"input\\\\inputbox_focus_left.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_INPUTBOX_FOCUS_MID">ALIPAY_IMG_PATH"input\\\\inputbox_focus_mid.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_INPUTBOX_FOCUS_RIGHT">ALIPAY_IMG_PATH"input\\\\inputbox_focus_right.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_NORMAL_LEFT">ALIPAY_IMG_PATH"combox\\\\combox_n_left.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_NORMAL_MID">ALIPAY_IMG_PATH"combox\\\\combox_n_mid.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_NORMAL_RIGHT">ALIPAY_IMG_PATH"combox\\\\combox_n_right.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_FOCUS_LEFT">ALIPAY_IMG_PATH"combox\\\\combox_focus_left.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_FOCUS_MID">ALIPAY_IMG_PATH"combox\\\\combox_focus_mid.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_FOCUD_RIGHT">ALIPAY_IMG_PATH"combox\\\\combox_focus_right.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_ITEM_FOCUS_LEFT">ALIPAY_IMG_PATH"combox\\\\mouseover_left.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_ITEM_FOCUS_MID">ALIPAY_IMG_PATH"combox\\\\mouseover_mid.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_ITEM_FOCUS_RIGHT">ALIPAY_IMG_PATH"combox\\\\mouseover_right.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_ITEM_TOP_LEFT">ALIPAY_IMG_PATH"combox\\\\combox_top_left.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_ITEM_TOP_RIGHT">ALIPAY_IMG_PATH"combox\\\\combox_top_right.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_ITEM_BOTTOM_LEFT">ALIPAY_IMG_PATH"combox\\\\combox_bottom_left.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_ITEM_BOTTOM_RIGHT">ALIPAY_IMG_PATH"combox\\\\combox_bottom_right.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_ITEM_LEFT">ALIPAY_IMG_PATH"combox\\\\combox_left.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_ITEM_MID">ALIPAY_IMG_PATH"combox\\\\combox_mid.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_COMBOX_ITEM_RIGHT">ALIPAY_IMG_PATH"combox\\\\combox_right.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_CHECKBOX_NORMAL_UNSELECT">ALIPAY_IMG_PATH"checkbox\\\\checkbox_n.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_CHECKBOX_NORMAL_SELECT">ALIPAY_IMG_PATH"checkbox\\\\checkbox_select.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_CHECKBOX_FOCUS_UNCELECT">ALIPAY_IMG_PATH"checkbox\\\\checkbox_n_forcus.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_CHECKBOX_FOCUS_SELECT">ALIPAY_IMG_PATH"checkbox\\\\checkbox_select_forcus.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_PROCESSING">ALIPAY_IMG_PATH"loading.gif"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_MSGBOX_LEFT">ALIPAY_IMG_PATH"msgbox\\\\mesg_box_left.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_MSGBOX_MID">ALIPAY_IMG_PATH"msgbox\\\\mesg_box_mid.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_MSGBOX_RIGHT">ALIPAY_IMG_PATH"msgbox\\\\mesg_box_right.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_ROLL_TOP">ALIPAY_IMG_PATH"roll\\\\roll_top.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_ROLL_MID">ALIPAY_IMG_PATH"roll\\\\roll_mid.png"</IMAGE>
    <IMAGE id="IMG_ID_AILPAY_ROLL_BUTTON">ALIPAY_IMG_PATH"roll\\\\roll_bottom.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_VKEY_LETT">ALIPAY_IMG_PATH"vkey\\\\vkey_lett.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_VKEY_NUM">ALIPAY_IMG_PATH"vkey\\\\vkey_num.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_VKEY_FOCUS">ALIPAY_IMG_PATH"vkey\\\\vkey_focus.png"</IMAGE>
     <IMAGE id="IMG_ID_ALIPAY_VKEY_KONGGE">ALIPAY_IMG_PATH"vkey\\\\kongge.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_VKEY_TO_BIG">ALIPAY_IMG_PATH"vkey\\\\to_big.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_VKEY_TO_CHAR">ALIPAY_IMG_PATH"vkey\\\\to_char.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_VKEY_TO_SMALL">ALIPAY_IMG_PATH"vkey\\\\to_small.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_VKEY_TO_AB">ALIPAY_IMG_PATH"vkey\\\\to_Ab.png"</IMAGE>
    <IMAGE id="IMG_ID_ALIPAY_LOADING_LOGO">ALIPAY_IMG_PATH"loading_logo.png"</IMAGE>


    <!------------------------------------------------------Menu Resource Area------------------------------------------------------>
    /* Only MENUITEM need compile option, MENUITEM_ID does not need */

    <!--Menu Tree Area-->

    <!------------------------------------------------------Other Resource---------------------------------------------------------->
    <SCREEN id="SCR_ID_ALIPAY_DEMO"/>
    <SCREEN id="SCR_ID_ALIPAY_START"/>
    <SCREEN id="SCR_ID_ALIPAY_INPUT"/>
    
    <TIMER id="ALIPAY_TIMER_ID0"/>
    <TIMER id="ALIPAY_TIMER_ID1"/>
    <TIMER id="ALIPAY_TIMER_ID2"/>
    <TIMER id="ALIPAY_TIMER_ID3"/>
    <TIMER id="ALIPAY_TIMER_ID4"/>
    <TIMER id="ALIPAY_TIMER_ID5"/>
    <TIMER id="ALIPAY_TIMER_ID6"/>
    <TIMER id="ALIPAY_TIMER_ID7"/>
    <TIMER id="ALIPAY_TIMER_ID8"/>
    <TIMER id="ALIPAY_TIMER_ID9"/>

</APP>

#endif /* __ALIPAY_SUPPORT__ */

