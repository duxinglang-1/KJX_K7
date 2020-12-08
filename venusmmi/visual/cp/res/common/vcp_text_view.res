#include "mmi_features.h"
#include "custresdef.h"


<?xml version="1.0" encoding="UTF-8"?>
<APP id="SRV_VENUS_COMPONENT_TEXT_VIEW">
    <!-----------------------------------------------------Theme Resource Area----------------------------------------------------->
    <THEME>
        <IMAGE id="VCP_IMG_TEXT_VIEW_NORMAL_BG" desc="text view normal background image when not activated" />
        <IMAGE id="VCP_IMG_TEXT_VIEW_HIGHLIGHT_BG" desc="text view background image when activated" />
        <IMAGE id="VCP_IMG_TEXT_EDITOR_DEL_ICON" desc="singleline editor delete icon on the right side when set delete button (setDeleteButton)" />
        <IMAGE id="VCP_IMG_TEXT_HLT_BG" desc="text view text highlight image which covers above the text, MUST be translucent" />
        <IMAGE id="VCP_IMG_TEXT_MAGNIFIER_BG" desc="text view magnifier background image" />
        <IMAGE id="VCP_IMG_TEXT_MAGNIFIER_MASK" desc="text view magnifier mask image which covers above the text and should be transparent on the center" />
        <IMAGE id="VCP_IMG_TEXT_MAGNIFIER_MARK_CURSOR" desc="text view magnifier cursor shape when enter select text mode" />
        
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_LEFT_H" desc="clipboard floating menu left button pressed state image" />
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_LEFT_N" desc="clipboard floating menu left button unpressed state image" />
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_MIDDLE_H" desc="clipboard floating menu middle button pressed state image" />
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_MIDDLE_N" desc="clipboard floating menu middle button unpressed state image" />
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_RIGHT_H" desc="clipboard floating menu right button pressed state image" />
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_RIGHT_N" desc="clipboard floating menu right button unpressed state image" />
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_SINGLE_H" desc="clipboard floating menu single button pressed state image" />
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_SINGLE_N" desc="clipboard floating menu single button unpressed state image" />
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_ARROW_H" desc="clipboard floating menu down arrow image when pressed" />
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_ARROW_N" desc="clipboard floating menu down arrow image when unpressed" />
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_UP_ARROW_H" desc="clipboard floating menu up arrow image when pressed" />
        <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_UP_ARROW_N" desc="clipboard floating menu up arrow image when unpressed" />

        <COLOR id = "VCP_COL_TEXT_VIEW_HINT_TEXT" desc="text view hint text color when content is empty" />
        <COLOR id = "VCP_COL_TEXT_VIEW_HLT_TEXT" desc="text view highlight text color" />
        <COLOR id = "VCP_COL_TEXT_VIEW_NRML_TEXT" desc="text view normal text color" />
        <COLOR id = "VCP_COL_TEXT_VIEW_HLT_BG" desc="text view highlight background color" />
        <COLOR id = "VCP_COL_TEXT_VIEW_UNDERLINE" desc="text view underline color" />
        <COLOR id = "VCP_COL_TEXT_VIEW_HYPELINK" desc="text view hyperlink text color" />
        <COLOR id = "VCP_COL_TEXT_EDITOR_CURSOR" desc="text editor cursor color" />

        <FONTSTYLE id = "VCP_FNT_TEXT_VIEW_TXT" desc = "text view font"></FONTSTYLE>
    </THEME>
    
    <!-----------------------------------------------------String Resource Area----------------------------------------------------->


    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>
    <IMAGE id="VCP_IMG_TEXT_VIEW_NORMAL_BG">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Editor_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_VIEW_HIGHLIGHT_BG">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Editor_H.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_EDITOR_DEL_ICON">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Delete.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_HLT_BG">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Text_BG.9slice.png"</IMAGE>
    
    <IMAGE id="VCP_IMG_TEXT_MAGNIFIER_BG">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Magnifier_BG.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_MAGNIFIER_MASK">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Magnifier_Mask.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_MAGNIFIER_MARK_CURSOR">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\C_Cursor.9slice.png"</IMAGE>
    
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_LEFT_H">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Left_P.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_LEFT_N">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Left_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_MIDDLE_H">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Middle_P.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_MIDDLE_N">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Middle_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_RIGHT_H">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Right_P.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_RIGHT_N">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Right_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_SINGLE_H">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Whole_P.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_SINGLE_N">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Whole_N.9slice.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_ARROW_H">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Arrow_P.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_ARROW_N">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Arrow_N.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_UP_ARROW_H">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Arrow_Top_P.png"</IMAGE>
    <IMAGE id="VCP_IMG_TEXT_CLIPBOARD_FM_UP_ARROW_N">RES_THEME_ROOT"\\\\\Theme1\\\\Components\\\\TextEditor\\\\Clipboard\\\\Arrow_Top_N.png"</IMAGE>
</APP>

