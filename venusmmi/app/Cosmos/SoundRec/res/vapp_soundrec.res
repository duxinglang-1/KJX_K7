#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_SOUNDREC"
     package_name = "native.mtk.soundrec"
     name = "STR_ID_VAPP_SNDREC_APP"
     img = "IMG_ID_VAPP_SNDREC"
     launch = "vapp_soundrec_launch"
     package_proc = "vapp_soundrec_package_proc" type="venus">

    <MEMORY heap="250*1024 + $(SRV_FMGR_FOLDER_FILELIST_MEM_SIZE)" cui="VCUI_MSGCOMPOSER" inc="FileMgrSrvGProt.h"/>

    <LAYOUT file="vapp_soundrec.xml" />

    <!-----------------------------------------------------NVRAM data Area---------------------------------------------------------->    
    <CACHEDATA type="short" id="NVRAM_APP_SNDREC_FILE_SEQ"> 
    <DEFAULT_VALUE>[0x01,0x00]</DEFAULT_VALUE>            
    <DESCRIPTION>Current filename sequence</DESCRIPTION> 
    </CACHEDATA>

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->

    <STRING id="STR_ID_VAPP_SNDREC_APP"/>
    <STRING id="STR_ID_VAPP_SNDREC_FILENAME_PREFIX"/>    
    <STRING id="STR_ID_VAPP_SNDREC_RECLIST"/>
    <STRING id="STR_ID_VAPP_SNDREC_RECLIST_EMPTY"/>
    <STRING id="STR_ID_VAPP_SNDREC_DELETE_TITLE"/>    
    <STRING id="STR_ID_VAPP_SNDREC_SETTING_QUALITY"/>
    <STRING id="STR_ID_VAPP_SNDREC_SETTING_HIGH"/>
    <STRING id="STR_ID_VAPP_SNDREC_SETTING_NORMAL"/>
    <STRING id="STR_ID_VAPP_SNDREC_AVAILABLE_TIME"/>
    <STRING id="STR_ID_VAPP_SNDREC_AVAILABLE_TIME_LARGER"/>
    <STRING id="STR_ID_VAPP_SNDREC_AVAILABLE_TIME_IS"/>        
    <STRING id="STR_ID_VAPP_SNDREC_TIME_HOUR"/>
    <STRING id="STR_ID_VAPP_SNDREC_TIME_HOURS"/>
    <STRING id="STR_ID_VAPP_SNDREC_TIME_MIN"/>
    <STRING id="STR_ID_VAPP_SNDREC_TIME_MINS"/>
    <STRING id="STR_ID_VAPP_SNDREC_TIME_SEC"/>
    <STRING id="STR_ID_VAPP_SNDREC_TIME_SECS"/>
    <STRING id="STR_ID_VAPP_SNDREC_NEW_RECORD"/>
    <STRING id="STR_ID_VAPP_SNDREC_RE_RECORD"/>
    <STRING id="STR_ID_VAPP_SNDREC_SET_AS_RINGTONE"/>
    <STRING id="STR_ID_VAPP_SNDREC_SHARE_RECORDING"/>
    <STRING id="STR_ID_VAPP_SNDREC_SHARE_BY_MMS"/>
    <STRING id="STR_ID_VAPP_SNDREC_SHARE_BY_BT"/>
    <STRING id="STR_ID_VAPP_SNDREC_SHARE_BY_EMAIL"/>
    <STRING id="STR_ID_VAPP_SNDREC_REACH_LIMIT"/>    
    <STRING id="STR_ID_VAPP_SNDREC_RECORD_SAVED"/>
    <STRING id="STR_ID_VAPP_SNDREC_DELETE_RECORD"/>    
    <STRING id="STR_ID_VAPP_SNDREC_DELETE_MULTI"/>    
    <STRING id="STR_ID_VAPP_SNDREC_ERR_MAX_SEQ"/>
    <STRING id="STR_ID_VAPP_SNDREC_ERR_CHECK_REMAIN_TIME"/>
    <STRING id="STR_ID_VAPP_SNDREC_ERR_DEL_ABORT"/>
    <STRING id="STR_ID_VAPP_SNDREC_ERR_LOAD_LIST"/>
    <STRING id="STR_ID_VAPP_SNDREC_ERR_LIST_DIRTY"/>  
    <STRING id="STR_ID_VAPP_SNDREC_PLAY_TIME"/>  
    <STRING id="STR_ID_VAPP_SNDREC_QUALITY"/> 
    <STRING id="STR_ID_VAPP_SNDREC_INSERT_MEMORY_CARD"/>         
    <STRING id="STR_ID_VAPP_SNDREC_ERR_CREATE_PATH"/>  

    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>  

    <THEME>
        <IMAGE id="IMG_ID_VAPP_SNDREC" desc="Main menu sound recorder icon">RES_IMG_ROOT"\\\\"__MMI_MAINMENU_ICON_DEFAULT_PATH__"\\\\SoundRecorder.png"</IMAGE>
    </THEME>
    <IMAGE id="IMG_ID_VAPP_SNDREC_BACKGROUND">RES_IMG_ROOT"\\\\SoundRec\\\\bg.9slice.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNDREC_CASSETTE">RES_IMG_ROOT"\\\\SoundRec\\\\cassette.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNDREC_TAPE">RES_IMG_ROOT"\\\\SoundRec\\\\tape.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNDREC_TAPE_AXIS">RES_IMG_ROOT"\\\\SoundRec\\\\tape_axis.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_SNDREC_TAPE_BACKGROUND">RES_IMG_ROOT"\\\\Common\\\\Grid_BG.9slice.png"</IMAGE>    
	<IMAGE id="IMG_ID_VAPP_SNDREC_ROLL_CENTER">RES_IMG_ROOT"\\\\SoundRec\\\\roll_center.png"</IMAGE>

	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_BG1_N">RES_IMG_ROOT"\\\\SoundRec\\\\btn_bg01_n.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_BG1_P">RES_IMG_ROOT"\\\\SoundRec\\\\btn_bg01_p.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_BG2_N">RES_IMG_ROOT"\\\\SoundRec\\\\btn_bg02_n.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_BG2_P">RES_IMG_ROOT"\\\\SoundRec\\\\btn_bg02_p.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_NEXT">RES_IMG_ROOT"\\\\SoundRec\\\\btn_next_n.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_NEXT_D">RES_IMG_ROOT"\\\\SoundRec\\\\btn_next_d.png"</IMAGE>	
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_PAUSE">RES_IMG_ROOT"\\\\SoundRec\\\\btn_pause_n.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_PLAY">RES_IMG_ROOT"\\\\SoundRec\\\\btn_play_n.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_PRE">RES_IMG_ROOT"\\\\SoundRec\\\\btn_pre_n.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_PRE_D">RES_IMG_ROOT"\\\\SoundRec\\\\btn_pre_d.png"</IMAGE>	
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_REC">RES_IMG_ROOT"\\\\SoundRec\\\\btn_rec_n.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_REC_D">RES_IMG_ROOT"\\\\SoundRec\\\\btn_rec_d.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_STOP">RES_IMG_ROOT"\\\\SoundRec\\\\btn_stop_n.png"</IMAGE>
	<IMAGE id="IMG_ID_VAPP_SNDREC_BTN_STOP_D">RES_IMG_ROOT"\\\\SoundRec\\\\btn_stop_d.png"</IMAGE>
</APP>

