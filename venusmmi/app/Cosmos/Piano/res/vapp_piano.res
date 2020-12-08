#include "mmi_features.h"
#include "custresdef.h"

#if (defined(__MMI_FTO_PIANO__) && defined(__J2ME__))

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_PIANO" name="STR_ID_VAPP_PIANO_AP_NAME"
     package_name = "native.mtk.piano"
     img = "IMG_ID_VAPP_PIANO_APP_ICON"
     launch = "vapp_piano_launch"
     package_proc = "vapp_piano_package_proc" type="venus">
    
    <MEMORY base="1024*300" />
    
    <!----- MMI CACHE ------->
    <CACHEDATA 
          type="byte" 
          id="NVRAM_VAPP_PIANO_SETTING_SW_LABEL"
          restore_flag="TRUE"
          >
        <DEFAULT_VALUE>[0x00]</DEFAULT_VALUE>            
        <DESCRIPTION>Hidden piano key label</DESCRIPTION>   
    </CACHEDATA>
    <CACHEDATA 
          type="byte" 
          id="NVRAM_VAPP_PIANO_SETTING_MIDI_PROGRAM"
          restore_flag="TRUE"
          >
        <DEFAULT_VALUE>[0x00]</DEFAULT_VALUE>            
        <DESCRIPTION>Piano midi program</DESCRIPTION>   
    </CACHEDATA>
    
    <!----- String ----->
    <STRING id="STR_ID_VAPP_PIANO_AP_NAME">"Piano"</STRING>
    <STRING id="STR_ID_VAPP_PIANO_TITLE">"Piano"</STRING>
    <STRING id="STR_ID_VAPP_PIANO_SETTING_TITLE">"Settings"</STRING>
    <STRING id="STR_ID_VAPP_PIANO_SETTING_VOLUME">"Volume"</STRING>
    <STRING id="STR_ID_VAPP_PIANO_SETTING_SW_LABEL">"Hide key labels"</STRING>
    <STRING id="STR_ID_VAPP_PIANO_SETTING_SW_MIDI">"Play midi sound"</STRING>
    <STRING id="STR_ID_VAPP_PIANO_SETTING_MIDI_PROGRAME">"Instrument"</STRING>
    <STRING id="STR_ID_VAPP_PIANO_MIDI_PROGRAME_0">"Piano"</STRING>
    <STRING id="STR_ID_VAPP_PIANO_MIDI_PROGRAME_1">"Glockenspiel"</STRING>
    <STRING id="STR_ID_VAPP_PIANO_MIDI_PROGRAME_2">"Electric Bass"</STRING>
    <STRING id="STR_ID_VAPP_PIANO_MIDI_PROGRAME_3">"Church Organ"</STRING>
    <STRING id="STR_ID_VAPP_PIANO_MIDI_PROGRAME_4">"Xylophone"</STRING>
    
    <!----- Images ----->
    #define PIANO_IMG_PATH    RES_IMG_ROOT"\\\\PIANO\\\\"
    
    <THEME>
        <IMAGE id="IMG_ID_VAPP_PIANO_APP_ICON" desc="Main menu piano icon">RES_IMG_ROOT"\\\\Mainmenu_Icon\\\\Piano.png"</IMAGE>
    </THEME>
    
    <IMAGE id="IMG_ID_VAPP_PIANO_TOP_FRAME">PIANO_IMG_PATH"top_frame.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_PIANO_SETTING_BTN">PIANO_IMG_PATH"setting_button.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_PIANO_BACK_BTN">PIANO_IMG_PATH"back_button.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_PIANO_KEY">PIANO_IMG_PATH"key.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_PIANO_KEY_CLICKED">PIANO_IMG_PATH"key_clicked.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_PIANO_SHARPKEY">PIANO_IMG_PATH"sharpkey.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_PIANO_SHARPKEY_CLICKED">PIANO_IMG_PATH"sharpkey_clicked.png"</IMAGE>
    
</APP>

#endif