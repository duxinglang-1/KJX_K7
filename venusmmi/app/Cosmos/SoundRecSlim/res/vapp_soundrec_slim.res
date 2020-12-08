#include "mmi_features.h"
#include "custresdef.h"

#ifdef __MMI_SOUNDREC_SLIM__

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SOUNDREC"
     package_name = "native.mtk.soundrec"
     name = "STR_ID_VAPP_SNDREC_APP"
     img = "IMG_ID_VAPP_SNDREC"
     launch = "vapp_soundrec_launch"
     type="venus">

    <MEMORY heap="50*1024"
    vrt_mem_factor = "2.0"/>

    <!-----------------------------------------------------NVRAM data Area---------------------------------------------------------->    
    <CACHEDATA type="short" id="NVRAM_APP_SNDREC_FILE_SEQ"> 
    <DEFAULT_VALUE>[0x01,0x00]</DEFAULT_VALUE>            
    <DESCRIPTION>Current filename sequence</DESCRIPTION> 
    </CACHEDATA>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="STR_ID_VAPP_SNDREC_APP"/>
    <STRING id="STR_ID_VAPP_SNDREC_FILENAME_PREFIX"/>    
    <STRING id="STR_ID_VAPP_SNDREC_RECLIST"/>
    <STRING id="STR_ID_VAPP_SNDREC_AVAILABLE_TIME"/>
    <STRING id="STR_ID_VAPP_SNDREC_AVAILABLE_TIME_LARGER"/>
    <STRING id="STR_ID_VAPP_SNDREC_AVAILABLE_TIME_IS"/>        
    <STRING id="STR_ID_VAPP_SNDREC_TIME_HOUR"/>
    <STRING id="STR_ID_VAPP_SNDREC_TIME_HOURS"/>
    <STRING id="STR_ID_VAPP_SNDREC_TIME_MIN"/>
    <STRING id="STR_ID_VAPP_SNDREC_TIME_MINS"/>
    <STRING id="STR_ID_VAPP_SNDREC_TIME_SEC"/>
    <STRING id="STR_ID_VAPP_SNDREC_TIME_SECS"/>
    <STRING id="STR_ID_VAPP_SNDREC_RECORD_SAVED"/>
    <STRING id="STR_ID_VAPP_SNDREC_ERR_MAX_SEQ"/>
    <STRING id="STR_ID_VAPP_SNDREC_ERR_CHECK_REMAIN_TIME"/>
    <STRING id="STR_ID_VAPP_SNDREC_INSERT_MEMORY_CARD"/>         
    <STRING id="STR_ID_VAPP_SNDREC_ERR_CREATE_PATH"/>  
    <STRING id="STR_ID_VAPP_SNDREC_SELECT_STORAGE"/>

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>  

    <THEME>
        <IMAGE id="IMG_ID_VAPP_SNDREC" desc="Main menu sound recorder icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\SoundRecorder.png"</IMAGE>
    </THEME>
    
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_BG1_N">RES_IMG_ROOT"\\\\Redesign\\\\SoundRec\\\\btn_bg.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_BG1_P">RES_IMG_ROOT"\\\\Redesign\\\\SoundRec\\\\btn_bg_pressed.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_PAUSE">RES_IMG_ROOT"\\\\Redesign\\\\SoundRec\\\\btn_rec_pause.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_REC">RES_IMG_ROOT"\\\\Redesign\\\\SoundRec\\\\btn_rec.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_REC_D">RES_IMG_ROOT"\\\\Redesign\\\\SoundRec\\\\btn_rec_d.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_STOP">RES_IMG_ROOT"\\\\Redesign\\\\SoundRec\\\\btn_stop_n.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_STOP_D">RES_IMG_ROOT"\\\\Redesign\\\\SoundRec\\\\btn_stop_d.png"</IMAGE>
</APP>

#endif // __MMI_SOUNDREC_SLIM__