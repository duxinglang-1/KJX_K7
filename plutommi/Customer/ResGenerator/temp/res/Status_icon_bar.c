/* Needed header files of the compile option in XML files, if you need others need to add here */
#include "mmi_features.h"
#include "custresdef.h"

#include "CustomCfg.h"

#ifdef FIRST_PASS
#include "BuildCfg.h"
#endif

#if defined(__J2ME__)
#include "j2me_custom_option.h"
#endif /* defined(__J2ME__) */

#include "MMIDataType.h"

#if ((defined(__MMI_FTE_SUPPORT__)&&!defined(__MMI_FWUI_SLIM__)) || ((defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__)) && (!defined(__LOW_COST_SUPPORT_COMMON__))))
    #define STATUS_ICON_IMAGE_FILE_PATH "_png"
#else
    #define STATUS_ICON_IMAGE_FILE_PATH ""
#endif

/* We will use FTE_240x320 image.zip in FTE_Slim,QVGA non-32+32 segment, status icon should use with xxx_png sub-folder in idle folder */
#if (defined(__FLAVOR_FTE_SLIM_HVGA__))
    #ifdef STATUS_ICON_IMAGE_FILE_PATH
        #undef STATUS_ICON_IMAGE_FILE_PATH
        #define STATUS_ICON_IMAGE_FILE_PATH "_png"
    #endif
#endif


/* Need this line to tell parser that XML start, must after all #include. */
<?xml version="1.0" encoding="UTF-8"?>

/* APP tag, include your app name defined in MMIDataType.h */
<APP id="SRV_STATUS_ICONS">

    /* When you use any ID of other module, you need to add
       that header file here, so that Resgen can find the ID */
    <!--Include Area-->

    <!-----------------------------------------------------String Resource Area----------------------------------------------------->
    /* String ID of you Application, we will get string from ref_list.txt for all languages */    
 
#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
	<THEME>
		<IMAGE id = "WGUI_IMG_STATUS_BAR_BKG" />
		<COLOR id = "WGUI_COL_STATUS_BAR_TEXT" desc = "color of text show in status bar" />
  </THEME>
    <IMAGE id = "WGUI_IMG_STATUS_BAR_SPECIAL_BKG">RES_THEME_ROOT"\\\\default\\\\Components\\\\MultimediaCP\\\\StatusBar\\\\Default_BG.9slice.png"</IMAGE>;
    <IMAGE id = "WGUI_IMG_STATUS_BAR_SPECIAL_TRANSPARENT_BKG">RES_THEME_ROOT"\\\\default\\\\Components\\\\MultimediaCP\\\\StatusBar\\\\Transparent_BG.9slice.png"</IMAGE>;
	
 #if defined(__MMI_MAINLCD_128X64__)	|| defined(__MMI_MAINLCD_240X240__)	
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\signal\\\\SI_SIG"</IMAGE>;
 #else
 	// baiwenlin 20130830  
#if defined(__OLED_BW_MMI__)
#if defined(__MMI_MAINLCD_128X36__)
     <IMAGE id = "IMG_SI_SIGNAL_STRENGTH" >"..\\\\..\\\\Customer\\\\Images\\\\Oled_bw_img\\\\signal"</IMAGE>;
#elif defined(__MMI_MAINLCD_128X64__)				
     <IMAGE id = "IMG_SI_SIGNAL_STRENGTH" >"..\\\\..\\\\Customer\\\\Images\\\\OLED_BW_128X64\\\\signal"</IMAGE>;
#endif /* __MMI_MAINLCD_128X36__ */
#else /*__OLED_BW_MMI__*/
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\signal\\\\sim"</IMAGE>;
#endif /* __OLED_BW_MMI__ */
#endif
   
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))

    <IMAGE id = "IMG_SI_SIGNAL_NO_SIM" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\NoSIM_Card.png"</IMAGE>;
   
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\signal\\\\sim1"</IMAGE>;
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_CLOSED" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\SIM1_CLOSE.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\signal\\\\sim2"</IMAGE>;
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_CLOSED" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\SIM2_CLOSE.png"</IMAGE>;
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    <IMAGE id = "IMG_SI_SIM3_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\signal\\\\SIM3"</IMAGE>;
    <IMAGE id = "IMG_SI_SIM3_SIGNAL_CLOSED" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\SIM3_CLOSE.png"</IMAGE>;
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
    <IMAGE id = "IMG_SI_SIM4_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\signal\\\\SIM4"</IMAGE>;
    <IMAGE id = "IMG_SI_SIM4_SIGNAL_CLOSED" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\SIM4_CLOSE.png"</IMAGE>;
#endif
  



 
#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__    
    
#ifdef __MMI_MAINLCD_128X64__
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH_L1" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\signal\\\\SI_SIG_L1"</IMAGE>;
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH_L2" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\signal\\\\SI_SIG_L2"</IMAGE>;
#else
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\signal\\\\sim"</IMAGE>;
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\signal\\\\sim"</IMAGE>;
#endif
#else
    <IMAGE id = "IMG_SI_LINE_L1" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\signal\\\\sim"</IMAGE>;
    <IMAGE id = "IMG_SI_LINE_L2" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\signal\\\\sim"</IMAGE>;
#endif
#ifdef __MMI_MAINLCD_128X64__
    <IMAGE id = "IMG_SI_BATTERY_STRENGTH" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\battery\\\\SI_BAT"</IMAGE>;
#else
	// baiwenlin 20130830  
#if defined(__OLED_BW_MMI__)
#if defined(__MMI_MAINLCD_128X36__)
    <IMAGE id = "IMG_SI_BATTERY_STRENGTH" >"..\\\\..\\\\Customer\\\\Images\\\\Oled_bw_img\\\\battery"</IMAGE>;
#elif defined(__MMI_MAINLCD_128X64__)				
    <IMAGE id = "IMG_SI_BATTERY_STRENGTH" >"..\\\\..\\\\Customer\\\\Images\\\\OLED_BW_128X64\\\\battery"</IMAGE>;
#endif /* __MMI_MAINLCD_128X36__ */
#else /*__OLED_BW_MMI__*/
    <IMAGE id = "IMG_SI_BATTERY_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\battery\\\\default"</IMAGE>;
#endif /* __OLED_BW_MMI__ */
#endif

#if defined(__MMI_MAINLCD_240X240__)
    <IMAGE id = "IMG_SI_BATTERY_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\battery\\\\default"</IMAGE>;
#endif

    <IMAGE id = "IMG_SI_BATTERY_CHARGE_STRENGTH_1" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\battery\\\\1"</IMAGE>;
    <IMAGE id = "IMG_SI_BATTERY_CHARGE_STRENGTH_2" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\battery\\\\2"</IMAGE>;
    <IMAGE id = "IMG_SI_BATTERY_CHARGE_STRENGTH_3" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\battery\\\\3"</IMAGE>;
    <IMAGE id = "IMG_SI_BATTERY_CHARGE_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\effect\\\\batterycharging"</IMAGE>;
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__      
    <IMAGE id = "IMG_SI_3G" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\3G.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_3G_CONNECT" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_3G"</IMAGE>;
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__  
    <IMAGE id = "IMG_SI_2G" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\2G.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_ANY" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_ANY.png"</IMAGE>;
#ifdef __MMI_VOIP__    
    <IMAGE id = "IMG_SI_VOIP" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VOIP.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_KEYPAD_LOCK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_LOCK.png"</IMAGE>;
    <IMAGE id = "IMG_SI_KEYPAD_UNLOCK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_UNLOCK.png"</IMAGE>;
    <IMAGE id = "IMG_SI_VIBRATE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\vibration.png"</IMAGE>;
    <IMAGE id = "IMG_SI_SILENT" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\silent.png"</IMAGE>;
    <IMAGE id = "IMG_SI_VIBRATE_AND_RING" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\vibRing.png"</IMAGE>;
    <IMAGE id = "IMG_SI_FLIGHT_MODE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Flight_Mode.png"</IMAGE>;
    <IMAGE id = "IMG_SI_ALARM_ACTIVATED" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\alarm.png"</IMAGE>;
    <IMAGE id = "IMG_SI_STOPWATCH_ACTIVATED" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Stopwatch.png"</IMAGE>;
	<IMAGE id = "IMG_SI_TIMER_ACTIVATED" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Timer.png"</IMAGE>;


#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    <IMAGE id = "IMG_SI_ROAMING_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\roam_sim1.png"</IMAGE>;
#else
    <IMAGE id = "IMG_SI_ROAMING_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\roam_sim.png"</IMAGE>;
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    <IMAGE id = "IMG_SI_MASTER_ROAMING_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Roam_Sim1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_SLAVE_ROAMING_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Roam_Sim2.png"</IMAGE>;
#endif  
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    <IMAGE id = "IMG_SI_SIM3_ROAMING_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Roam_Sim3.png"</IMAGE>;
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
    <IMAGE id = "IMG_SI_SIM4_ROAMING_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Roam_Sim4.png"</IMAGE>;
#endif  

    <IMAGE id = "IMG_SI_MISSED_CALL_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\call_miss.png"</IMAGE>;

    <IMAGE id = "IMG_SI_WIFI_TETHERING" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\WiFi.png"</IMAGE>;


    <IMAGE id = "IMG_SI_EARPHONE_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\ear_phone.png"</IMAGE>;

    <IMAGE id = "IMG_SI_USB" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Usb.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_SPEAKER_CALL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Speaker_call.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_SPEAKER_MUTE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Speaker_Mute.png"</IMAGE>;
    


    <IMAGE id = "IMG_SI_MMS_UNREAD_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MMSU.png"</IMAGE>;
    <IMAGE id = "IMG_SI_MMS_BUSY_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MMSB.png"</IMAGE>;

#if defined(__MMI_MMS_2__)
    <IMAGE id = "IMG_SI_MMS_RECEIVING" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\MMSReceiving"</IMAGE>;
#endif

#if (defined __OPTR_NONE__)
     <IMAGE id = "IMG_SI_IR_INDICATOR" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IR"</IMAGE>;
#else
     <IMAGE id = "IMG_SI_IR_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IR.gif"</IMAGE>;
#endif

     <IMAGE id = "IMG_SI_BT" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\bt.png"</IMAGE>;
     <IMAGE id = "IMG_SI_BT_CON" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\bt_connected.png"</IMAGE>;

#ifdef __NFC_SUPPORT__
	 <IMAGE id = "IMG_SI_NFC" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\NFC.png"</IMAGE>;
#endif
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__           
     <IMAGE id = "IMG_SI_BT_TRANSFERRING" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\effect\\\\BluetoothTransferring"</IMAGE>;
#endif

#if defined(__MMI_MULTI_VCARD__) || defined(__VCARD_CLOUD_SUPPORT__)     
     <IMAGE id = "IMG_SI_CONTACTS_BACKUP" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\\Contact_Bak.png"</IMAGE>;
     <IMAGE id = "IMG_SI_CONTACTS_RESTORE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\\Contact_Restore.png"</IMAGE>;
#endif
     <IMAGE id = "IMG_SI_CONTACTS_RESTORE_ERROR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\\Contact_Restore_Error.png"</IMAGE>;
     
     <IMAGE id = "IMG_SI_DOWNLOADING" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\Downloading"</IMAGE>;
     <IMAGE id = "IMG_SI_DOWNLOAD" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\\Downloading.png"</IMAGE>;
     <IMAGE id = "IMG_SI_DOWNLOAD_COMPLETE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\\Download_Complete.png"</IMAGE>;
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__    
     <IMAGE id = "IMG_SI_DOWNLOAD_ERROR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\\Download_Error.png"</IMAGE>;
#endif
     <IMAGE id = "IMG_SI_DOWNLOAD_FULL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\\Dl_Memory_Full.png"</IMAGE>;


#ifdef __MMI_BG_SOUND_EFFECT__
     <IMAGE id = "IMG_SI_BGSND" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_BGSND.png"</IMAGE>;
#endif

#ifdef __MMI_AUDIO_REVERB_EFFECT__
     <IMAGE id = "IMG_SI_REVERBSND" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUDREVERB.png"</IMAGE>;
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
     <IMAGE id = "IMG_SI_SURROUNDSND" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_3DSound.png"</IMAGE>;
#endif

#ifdef  __HOMEZONE_SUPPORT__ 

#ifndef __MMI_DUAL_SIM_MASTER__
     <IMAGE id = "IMG_SI_HZONE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_HZONE.png"</IMAGE>;
#else
    <IMAGE id = "IMG_SI_HZONE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Homezone\\\\SI_home1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HZONE_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Homezone\\\\SI_home2.png"</IMAGE>;
#endif
     <IMAGE id = "IMG_SI_CZONE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_CZONE.png"</IMAGE>;
#endif

#ifdef __CTM_SUPPORT__
     <IMAGE id = "IMG_SI_TTY_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_TTY.png"</IMAGE>;
#endif

#ifdef __MMI_EMAIL__

#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
    <IMAGE id = "IMG_SI_EMAIL_SENDING" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\EmailSending"</IMAGE>;  
    <IMAGE id = "IMG_SI_EMAIL_REFRESHING" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\RefreshingEmail"</IMAGE>;
#endif

    <IMAGE id = "IMG_SI_UNREAD_EMAIL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Email_Unread.png"</IMAGE>;   
    <IMAGE id = "IMG_SI_EMAIL_SEND" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Email_Send.png"</IMAGE>;  
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
    <IMAGE id = "IMG_SI_EMAIL_SEND_ERROR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Email_SendingError.png"</IMAGE>;  
    <IMAGE id = "IMG_SI_EMAIL_REF" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\email_refreshing.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EMAIL_FAIL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Email_FAILED.png"</IMAGE>;  
    <IMAGE id = "IMG_SI_EMAIL_FULL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Email_FULL.png"</IMAGE>;  
#endif

#endif /* __MMI_EMAIL__ */
    
    <IMAGE id = "IMG_SI_PUSH_CONNECT" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\push_connect.png"</IMAGE>; 
    <IMAGE id = "IMG_SI_PUSH_RECEIVE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\push_receive.png"</IMAGE>; 
    <IMAGE id = "IMG_SI_PUSH_FAIL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\push_fail.png"</IMAGE>; 
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__    
    <IMAGE id = "IMG_SI_PUSHED_OBJ" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Pushed_Object.png"</IMAGE>;  

    <IMAGE id = "IMG_SI_UNREAD_VOICE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\new_voicemail.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_FAX" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\New_SIM_fax.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_SIM_EMAIL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\New_SIM_email.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_NET" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\new_sim_netmessage.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_VIDEO" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\new_sim_Video.png"</IMAGE>;;
#endif    
    
#ifndef __MMI_DUAL_SIM_MASTER__
    <IMAGE id = "IMG_SI_SMS_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sms_unread.png"</IMAGE>;
#else	
    <IMAGE id = "IMG_SI_SMS_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sms_unread.png"</IMAGE>;
#endif	

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 1))
    <IMAGE id = "IMG_SI_CALL_FORWARD" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Call_Forward.png"</IMAGE>;

#else

#ifndef __MMI_DUAL_SIM_MASTER__
    <IMAGE id = "IMG_SI_CALL_DIVERT_L1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\call_forward.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_DIVERT_L2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\call_forward.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_DIVERT_L1L2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\call_forward.png"</IMAGE>;
#else
    <IMAGE id = "IMG_SI_CALL_DIVERT_L1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Call_forward_SIM1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_DIVERT_L2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Call_forward_SIM1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_DIVERT_L1L2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Call_forward_SIM1.png"</IMAGE>;
#endif	

#endif /* (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3)) */

    <IMAGE id = "IMG_SI_VOICE_RECORD" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sound_recorder.png"</IMAGE>;
    <IMAGE id = "IMG_SI_MUTE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Speaker_Mute.png"</IMAGE>;
    <IMAGE id = "IMG_SI_STOPWATCH" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\stop_watch.png"</IMAGE>;
   #if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    <IMAGE id = "IMG_SI_JAVA_BG_VM" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\JAVA.png"</IMAGE>;
    <IMAGE id = "IMG_SI_JAVA_BG_VM_AUDIO" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\JAVA_Audio.png"</IMAGE>;
    <IMAGE id = "IMG_SI_JAVA" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Java.png"</IMAGE>;
    <IMAGE id = "IMG_SI_JAVA_AUDIO" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Java_Audio.png"</IMAGE>;
   #endif
   #ifdef __J2ME__
	#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__    
    <IMAGE id = "IMG_SI_JAVA_PUSH" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Java_Push.png"</IMAGE>;
	#endif
   #endif

    <IMAGE id = "IMG_SI_WAP1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Push\\\\SI_WMAL1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_WAP2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Push\\\\SI_WMAL2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_WAP" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_WMAL.png"</IMAGE>;

#ifndef __MMI_DUAL_SIM_MASTER__
    <IMAGE id = "IMG_SI_NETWORK_CIPHER_GSM" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\GPRS_SIM.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_NETWORK_CIPHER_GPRS" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NCGPRS.png"</IMAGE>;
#ifdef __MMI_AUTO_ANSWER_MACHINE__
    <IMAGE id = "IMG_SI_AUTOAM_REC" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUTOAM_Record.png"</IMAGE>;
    <IMAGE id = "IMG_SI_AUTOAM_UNREAD" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUTOAM_Message.png"</IMAGE>;
    <IMAGE id = "IMG_SI_AUTOAM_ON" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUTOAM.png"</IMAGE>;
#endif  

#ifdef __MMI_IMPS__   
    <IMAGE id = "IMG_SI_IMPS_MSG" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IMPSMG.png"</IMAGE>;
    <IMAGE id = "IMG_SI_IMPS_LOGIN" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IMPS.png"</IMAGE>;
    <IMAGE id = "IMG_SI_IMPS_LOGIN_FAIL" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IMPS_fail.png"</IMAGE>;
#endif 

#ifdef __MMI_WLAN_FEATURES__
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\wifi_disconnect.png"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_SCANNING" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\WiFi"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\WiFi\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\WiFi\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT3" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\WiFi\\\\2.png"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT4" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\WiFi\\\\3.png"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT5" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\WiFi\\\\4.png"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT6" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\WiFi\\\\4.png"</IMAGE>;
    #ifdef __MMI_OP01_WIFI__    
        <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_FOUND_WIFI" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\WiFi\\\\FoundWifi.png"</IMAGE>;
    #endif
#endif

    <IMAGE id = "IMG_SI_EDGE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim_Edge.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim_gprs.png"</IMAGE>;
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__    
    <IMAGE id = "IMG_SI_EDGEC" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim_Edge_NoPDP.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim_gprs_NoPDP.png"</IMAGE>; 
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_EDGE\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_GPRS\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_DOWNLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_EDGE\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_DOWNLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_GPRS\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_EDGE\\\\2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_GPRS\\\\2.png"</IMAGE>;
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    <IMAGE id = "IMG_SI_EDGE_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim1_Edge.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_SERVICE_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim1_gprs.png"</IMAGE>;
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__    
    <IMAGE id = "IMG_SI_EDGEC_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim1_edge_NoPDP.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim1_gprs_NoPDP.png"</IMAGE>;
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_EDGE\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_GPRS\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_DOWNLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_EDGE\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_DOWNLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_GPRS\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_EDGE\\\\2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_GPRS\\\\2.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_EDGE_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim2_edge.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_SERVICE_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim2_gprs.png"</IMAGE>;
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__    
    <IMAGE id = "IMG_SI_EDGEC_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim2_edge_NoPDP.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim2_gprs_NoPDP.png"</IMAGE>;
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM2_EDGE\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPLINK_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM2_GPRS\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_DOWNLINK_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM2_EDGE\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_DOWNLINK_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM2_GPRS\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM2_EDGE\\\\2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM2_GPRS\\\\2.png"</IMAGE>;

#endif
#endif
    
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    <IMAGE id = "IMG_SI_EDGE_SIM3" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim3_edge.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_SERVICE_SIM3" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim3_gprs.png"</IMAGE>;
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__    
    <IMAGE id = "IMG_SI_EDGEC_SIM3" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim3_edge_NoPDP.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM3" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim3_gprs_NoPDP.png"</IMAGE>;
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK_SIM3" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM3_EDGE\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPLINK_SIM3" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM3_GPRS\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_DOWNLINK_SIM3" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM3_EDGE\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_DOWNLINK_SIM3" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM3_GPRS\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK_SIM3" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM3_EDGE\\\\2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK_SIM3" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM3_GPRS\\\\2.png"</IMAGE>;

#endif
#endif
    
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 4))
    <IMAGE id = "IMG_SI_EDGE_SIM4" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim4_edge.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_SERVICE_SIM4" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim4_gprs.png"</IMAGE>;
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__    
    <IMAGE id = "IMG_SI_EDGEC_SIM4" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim4_edge_NoPDP.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM4" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim4_gprs_NoPDP.png"</IMAGE>;
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK_SIM4" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM4_EDGE\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPLINK_SIM4" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM4_GPRS\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_DOWNLINK_SIM4" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM4_EDGE\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_DOWNLINK_SIM4" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM4_GPRS\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK_SIM4" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM4_EDGE\\\\2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK_SIM4" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM4_GPRS\\\\2.png"</IMAGE>;

#endif
#endif

    


#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    <IMAGE id = "IMG_SI_CSD_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\CSD\\\\SI_CSD3.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CSD_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\CSD\\\\SI_CSD4.png"</IMAGE>;

#endif

#ifndef __MMI_DUAL_SIM_MASTER__
    <IMAGE id = "IMG_SI_CSD" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_CSD.png"</IMAGE>;
#else
    <IMAGE id = "IMG_SI_CSD_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\CSD\\\\SI_CSD1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CSD_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\CSD\\\\SI_CSD2.png"</IMAGE>;
#endif 


#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    <IMAGE id = "IMG_SI_PRINT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_PRINT.png"</IMAGE>;
    <IMAGE id = "IMG_SI_PRINT_FAIL" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_PRINT_FAIL.png"</IMAGE>;
#endif

#ifdef __MMI_CALL_INDICATOR__
    <IMAGE id = "IMG_SI_CALL_INDICATOR_ACTIVE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\call.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_INDICATOR_HOLD" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\call.png"</IMAGE>;
#endif 

#ifdef __MMI_ATV_SUPPORT__
    <IMAGE id = "IMG_SI_MTV_SIGNAL" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\MobileTVPlayer\\\\Signal"</IMAGE>;
#endif 
#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
    <IMAGE id = "IMG_SI_DTV_SIGNAL" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\DTVPlayer\\\\Signal"</IMAGE>;
#endif


#if defined(OBIGO_Q05A) && defined(WAP_SUPPORT)
    <IMAGE id = "IMG_SI_SECURITY" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_KEY.png"</IMAGE>;
#endif

#ifdef __UNIFIED_MESSAGE_BACKGROUND_SEND_SUPPORT__
    <IMAGE id = "IMG_SI_OUTBOX_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_OUTBOXIND.png"</IMAGE>;
#endif
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__
    <IMAGE id = "IMG_SI_MESSAGE_SENDING" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\MessageSending"</IMAGE>;
	<IMAGE id = "IMG_SI_MESSAGE_SEND_FAIL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Message_Sendfail.Png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_MESSAGE_UNREAD" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Message_Unread.png"</IMAGE>;
    
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__    
    <IMAGE id = "IMG_SI_SNS_UPLOAD" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\upload.png"</IMAGE>;
    <IMAGE id = "IMG_SI_SNS_FAIL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Failed.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_SNS_COMMENT" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Comments.png"</IMAGE>;
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__    
    <IMAGE id = "IMG_SI_SNS_REFRESH" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Refresh.png"</IMAGE>;
#endif    
    <IMAGE id = "IMG_SI_UPGRADE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Updated.png"</IMAGE>;
    
//#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    <IMAGE id = "IMG_SI_MSG_FULL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Message_Full.png"</IMAGE>;
//#else
    
#ifdef __MMI_DUAL_SIM_MASTER__    

#else
    <IMAGE id = "IMG_SI_SMS_FULL_SIM" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Sms_Full_SIM.png"</IMAGE>;
#endif
<IMAGE id = "IMG_SI_MMS_FULL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\mms.png"</IMAGE>;

//#endif /* (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3)) */

    <IMAGE id = "IMG_SI_SMS_SENDING" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\statusbar\\\\events\\\\sms_sending.png"</IMAGE>;

#ifdef __MMI_AUDIO_PLAYER__
    <IMAGE id = "IMG_SI_AUDPLY" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\musicplay.png"</IMAGE>;
#endif

#if defined(__MMI_MEDIA_PLAYER__) || defined(__COSMOS_MUSICPLY__)|| defined(__MMI_MUSIC_PLAYER_SLIM__)
    <IMAGE id = "IMG_SI_MEDPLY" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\musicplay.png"</IMAGE>;
#endif

    <IMAGE id = "IMG_SI_FM" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Fm.png"</IMAGE>;

    <IMAGE id = "IMG_SI_PROVMSG" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\provioning.png"</IMAGE>;
    
#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
    <IMAGE id = "IMG_SI_AGPS_STATE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\GPS_Use.png"</IMAGE>;
#endif
#ifdef __SYNCML_SUPPORT__
    <IMAGE id = "IMG_SI_SYNCML" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Sync.png"</IMAGE>;
#endif
#ifndef __MMI_COSMOS_STATUS_BAR_SLIM__    
    <IMAGE id = "IMG_SI_SYNCML_ERROR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Sync_Error.png"</IMAGE>;
    <IMAGE id = "IMG_SI_SYNCML_PROCESS" force_type = "FORCE_ABM_SEQUENCE">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SyncingProcess"</IMAGE>;
#endif

#ifdef __QQIM_SUPPORT__
    <IMAGE id = "IMG_SI_QQIM_AWAY" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_AWAY.png"</IMAGE>;
    <IMAGE id = "IMG_SI_QQIM_INVISIBLE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_INVISIBLE.png"</IMAGE>;
    <IMAGE id = "IMG_SI_QQIM_MSG" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_MSG.png"</IMAGE>;
    <IMAGE id = "IMG_SI_QQIM_OFFLINE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_OFFLINE.png"</IMAGE>;
    <IMAGE id = "IMG_SI_QQIM_ONLINE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_ONLINE.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_MRE_DEFAULT" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\DEFAULT.png"</IMAGE>;
//    <IMAGE id = "IMG_SI_MRE_FETION" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MRE_FETION.png"</IMAGE>;
//    <IMAGE id = "IMG_SI_MRE_MSN" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MRE_MSN.png"</IMAGE>;
//    <IMAGE id = "IMG_SI_MRE_PUSHMAIL" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MRE_PUSHMAIL.png"</IMAGE>;
//    <IMAGE id = "IMG_SI_MRE_QQ" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MRE_QQ.png"</IMAGE>;
	<IMAGE id = "IMG_SI_MRE_FETION" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\DEFAULT.png"</IMAGE>;
	<IMAGE id = "IMG_SI_MRE_MSN" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\DEFAULT.png"</IMAGE>;
	<IMAGE id = "IMG_SI_MRE_PUSHMAIL" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\DEFAULT.png"</IMAGE>;
	<IMAGE id = "IMG_SI_MRE_QQ" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\DEFAULT.png"</IMAGE>;
	<IMAGE id = "IMG_SI_MRE_PUSH" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\MRE_push.png"</IMAGE>;

#ifdef __MMI_STATUS_ICONBAR_COSMOS_STYLE__
    <IMAGE id = "IMG_SI_LEFT_HIDE" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Extension.png"</IMAGE>;
#endif


#ifdef __OP01_3G__
    <IMAGE id = "IMG_SI_TDC" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim_T_NoPDP.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TD" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim_T.png"</IMAGE>;
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_TD_UPLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_TD\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TD_DOWNLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_TD\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TD_UPDOWNLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_TD\\\\2.png"</IMAGE>;
#endif
#endif
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    <IMAGE id = "IMG_SI_HSPA_NO_PDP" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\Sim_h_NoPDP.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_PDP_ACTIVATED" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\Sim_h.png"</IMAGE>;
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_HSPA_UPLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_HSPA\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_DOWNLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_HSPA\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_UPDOWNLINK" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM_HSPA\\\\2.png"</IMAGE>;
#endif
#endif

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    #ifdef __OP01_3G__
    <IMAGE id = "IMG_SI_TDC_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim1_T_NoPDP.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TD_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\sim1_T.png"</IMAGE>;
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_TD_UPLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_TD\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TD_DOWNLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_TD\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TD_UPDOWNLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_TD\\\\2.png"</IMAGE>;
#endif
    #endif

    #if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    <IMAGE id = "IMG_SI_HSPA_NO_PDP_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\Sim1_h_NoPDP.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_PDP_ACTIVATED_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\Sim1_h.png"</IMAGE>;
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_HSPA_UPLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_HSPA\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_DOWNLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_HSPA\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_UPDOWNLINK_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM1_HSPA\\\\2.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_HSPA_NO_PDP_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\Sim2_h_NoPDP.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_PDP_ACTIVATED_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\Sim2_h.png"</IMAGE>;
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_HSPA_UPLINK_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM2_HSPA\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_DOWNLINK_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM2_HSPA\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_UPDOWNLINK_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Effect\\\\SIM2_HSPA\\\\2.png"</IMAGE>;
#endif
    #endif
#endif
    

    
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    <IMAGE id = "IMG_SI_35G" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\35G.png"</IMAGE>; 
#endif

    <IMAGE id = "IMG_SI_SIGNAL_NO_SIM" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\NoSIM_CARD.png"</IMAGE>;
    


#ifdef __MMI_DUAL_SIM_MASTER__ 
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_NO_SIM" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\NoSIM1_CARD.png"</IMAGE>;

    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_NO_SIM" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\NoSIM2_CARD.png"</IMAGE>;

    <IMAGE id = "IMG_SI_MASTER_NETWORK_CIPHER_GSM" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\GPRS_SIM1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_SLAVE_NETWORK_CIPHER_GSM" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\GPRS_SIM2.png"</IMAGE>;


    <IMAGE id = "IMG_SLAVE_CALL_FORWARD" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Call_forward_SIM2.png"</IMAGE>;
    <IMAGE id = "IMG_SLAVE_CALL_FORWARD_L1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Call_forward_SIM2.png"</IMAGE>;
    <IMAGE id = "IMG_SLAVE_CALL_FORWARD_L2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\Call_forward_SIM2.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_SLAVE_SMS_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sms_unread.png"</IMAGE>;

    <IMAGE id = "IMG_SI_MMS_UNREAD_INDICATOR_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\MMS\\\\Master\\\SI_UNREAD_1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_MMS_UNREAD_INDICATOR_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\MMS\\\\Slave\\\SI_UNREAD_2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_MMS_BUSY_INDICATOR_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\MMS\\\\Master\\\SI_BUSY_1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_MMS_BUSY_INDICATOR_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\MMS\\\\Slave\\\SI_BUSY_2.png"</IMAGE>;

    
    <IMAGE id = "IMG_SI_CARD1MISSED_CALL_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\call_miss.png"</IMAGE>;
        
    <IMAGE id = "IMG_SI_CARD2MISSED_CALL_INDICATOR" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\call_miss.png"</IMAGE>;
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    <IMAGE id = "IMG_SI_35G_SIM1" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\35G.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_35G_SIM2" force_type = "FORCE_ABM">RES_THEME_ROOT"\\\\default\\\\StatusIcon\\\\sim_connected\\\\35G.png"</IMAGE>;
#endif
                           
#endif

    <IMAGE id = "IMG_SLSI_SILENT">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_SIL.BMP"</IMAGE>;
#ifdef __MMI_DUAL_SIM_MASTER__
	<IMAGE id = "IMG_SLSI_SIGNAL_STRENGTH">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG_SIM1"</IMAGE>;
	<IMAGE id = "IMG_SLSI_SLAVE_SIGNAL_STRENGTH">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG_SIM2"</IMAGE>;
	<IMAGE id = "IMG_SLSI_SIGNAL_CLOSE">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG_1_CLOSE.bmp"</IMAGE>;
	<IMAGE id = "IMG_SLSI_SLAVE_SIGNAL_CLOSE">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG_2_CLOSE.bmp"</IMAGE>;
#else 
    <IMAGE id = "IMG_SLSI_SIGNAL_STRENGTH">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG"</IMAGE>;
#endif
    <IMAGE id = "IMG_SLSI_BATTERY_STRENGTH">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\battery\\\\SB_BAT"</IMAGE>;
#ifdef __MMI_DUAL_SIM_MASTER__    
    <IMAGE id = "IMG_SLSI_SMS_INDICATOR">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MG_SIM1.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_SLAVE_SMS_INDICATOR">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MG_SIM2.BMP"</IMAGE>;
#else
    <IMAGE id = "IMG_SLSI_SMS_INDICATOR">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MG.BMP"</IMAGE>;
#endif        
    <IMAGE id = "IMG_SLSI_RING">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_RING.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_VIBRATE">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_VIB.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_VIBRATE_AND_RING">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_VR.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_VIBRATE_THEN_RING">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_VTR.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_ALARM">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_ALARM.BMP"</IMAGE>;
#ifdef __MMI_DUAL_SIM_MASTER__    
    <IMAGE id = "IMG_SLSI_MISSED_CALL">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MCA.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_SLAVE_MISSED_CALL">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MCA_SIM2.BMP"</IMAGE>;
#else   
    <IMAGE id = "IMG_SLSI_MISSED_CALL">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MCA.BMP"</IMAGE>;
#endif    

#ifdef __MMI_DUAL_SIM_MASTER__
    <IMAGE id = "WGUI_IMG_IDLE_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SimCard\\\\SI_Sim1.png"</IMAGE>;
    <IMAGE id = "WGUI_IMG_IDLE_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SimCard\\\\SI_Sim2.png"</IMAGE>;
#endif    

#ifdef __MMI_COSMOS_STATUS_BAR_SLIM__
<IMAGE id = "IMG_SI_COMMON_ERROR">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\error.png"</IMAGE>;
<IMAGE id = "IMG_SI_COMMON_NEW">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\Default.png"</IMAGE>;
<IMAGE id = "IMG_SI_COMMON_SYNC">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\SYNC.png"</IMAGE>;
<IMAGE id = "IMG_SI_COMMON_SENDING">RES_THEME_ROOT"\\\\Default\\\\StatusIcon\\\\sending.png"</IMAGE>;
#endif
	
#else /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)) && (!defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__))
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;
#else
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\signal\\\\SI_SIG"</IMAGE>;
#endif
#if defined(__MMI_MAINLCD_240X240__)
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\signal\\\\SI_SIG"</IMAGE>;
#endif
#ifdef __MMI_STATUS_ICON_SIGNAL_WITH_LINE_SWITCH__
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)) && (!defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__))
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;
#else
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\signal\\\\SI_SIG_L1"</IMAGE>;
    <IMAGE id = "IMG_SI_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\signal\\\\SI_SIG_L2"</IMAGE>;
#endif
#else
    <IMAGE id = "IMG_SI_LINE_L1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_L1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_LINE_L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_L2.png"</IMAGE>;
#endif

    <IMAGE id = "IMG_SI_BATTERY_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\battery\\\\SI_BAT"</IMAGE>;

#if defined(__MMI_MAINLCD_240X240__)
    <IMAGE id = "IMG_SI_BATTERY_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\battery\\\\SI_BAT"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_CHARGER_CONNECT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_charger.png"</IMAGE>;

#if defined(__MMI_PREF_NETWORK__) || (defined(__GSM_RAT__) && (defined(__UMTS_RAT__) || defined(__OP01_3G__)))
    <IMAGE id = "IMG_SI_3G" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_3G.png"</IMAGE>;
    <IMAGE id = "IMG_SI_2G" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_2G.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_ANY" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_ANY.png"</IMAGE>;
#ifdef __OP01_3G__
    <IMAGE id = "IMG_SI_TD" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_TD.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TDC" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_TDC.png"</IMAGE>;
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_TD_UPLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_TD\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TD_DOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_TD\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TD_UPDOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_TD\\\\2.png"</IMAGE>;
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
    <IMAGE id = "IMG_SI_TD_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\\SI_TD_SIM1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TDC_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\\SI_TDC_SIM1.png"</IMAGE>;
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_TD_UPLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_TD\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TD_DOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_TD\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_TD_UPDOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_TD\\\\2.png"</IMAGE>;
#endif
#endif
#endif
#ifdef __MMI_VOIP__    
    <IMAGE id = "IMG_SI_VOIP" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VOIP.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_KEYPAD_LOCK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_LOCK.png"</IMAGE>;

    <IMAGE id = "IMG_SI_VIBRATE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VIB.png"</IMAGE>;
    <IMAGE id = "IMG_SI_SILENT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_SILENT.png"</IMAGE>;
    <IMAGE id = "IMG_SI_RING" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_RING.png"</IMAGE>;
    <IMAGE id = "IMG_SI_VIBRATE_AND_RING" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VR.png"</IMAGE>;
    <IMAGE id = "IMG_SI_VIBRATE_THEN_RING" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VTR.png"</IMAGE>;
    <IMAGE id = "IMG_SI_ALARM_ACTIVATED" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_ALARM.png"</IMAGE>;

    <IMAGE id = "IMG_SI_ROAMING_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_RM.png"</IMAGE>;
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ 
#if (defined(__MMI_DUAL_SIM_MASTER__) || (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)))
    <IMAGE id = "IMG_SI_ROAMING_INDICATOR_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Master\\\\SI_RM_1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_ROAMING_INDICATOR_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_RM_2.png"</IMAGE>;
#endif
#endif
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    <IMAGE id = "IMG_SI_ROAMING_INDICATOR_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Callforward\\\\SI_RM_3.png"</IMAGE>;
    <IMAGE id = "IMG_SI_ROAMING_INDICATOR_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Callforward\\\\SI_RM_4.png"</IMAGE>;
#endif


    <IMAGE id = "IMG_SI_MISSED_CALL_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MCA.png"</IMAGE>;

    #ifdef __MMI_TETHERING__
    <IMAGE id = "IMG_SI_WIFI_TETHERING" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_WiFi_Router.png"</IMAGE>;
    #endif
    
		#ifdef __MMI_MAINLCD_96X64__
		    <IMAGE id = "IMG_SI_EARPHONE_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EARPHONE.png"</IMAGE>;
		#else
		    <IMAGE id = "IMG_SI_EARPHONE_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EAR.png"</IMAGE>;
		#endif

    #if defined(__MMI_USB_SUPPORT__)
    <IMAGE id = "IMG_SI_USB" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_USB.png"</IMAGE>;
    #endif

    #ifdef __MMI_MMS_2__
    <IMAGE id = "IMG_SI_MMS_UNREAD_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MMSU.png"</IMAGE>;
    <IMAGE id = "IMG_SI_MMS_BUSY_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MMSB.png"</IMAGE>;
    #endif

#if (defined __OPTR_NONE__)
#ifdef __MMI_MAINLCD_128X64__
     <IMAGE id = "IMG_SI_IR_INDICATOR" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IR"</IMAGE>;
#else
     <IMAGE id = "IMG_SI_IR_INDICATOR" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IR"</IMAGE>;
#endif
#else
     <IMAGE id = "IMG_SI_IR_INDICATOR">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IR.gif"</IMAGE>;
#endif

     <IMAGE id = "IMG_SI_BT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_BT.png"</IMAGE>;
     <IMAGE id = "IMG_SI_BT_CON" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_BT_CON.png"</IMAGE>;

#ifdef __KJX_FUN__
    <IMAGE id = "IMG_SI_GPS_OFF" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GPS\\\\gps_off.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPS_ON" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GPS\\\\gps_on.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPS_OK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GPS\\\\gps_ok.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_CHECK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GPRS\\\\gprs_check.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GPRS\\\\gprs_off.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_LINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GPRS\\\\gprs_on.png"</IMAGE>;
	<IMAGE id = "IMG_SI_SIGNAL_NO_SIM" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\signal\\\\SI_NO_SIM\\\\no_sim.bmp"</IMAGE>;	
	<IMAGE id = "IMG_SI_RFID_ON" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\rfid_on.png"</IMAGE>;		
	<IMAGE id = "IMG_SI_BLE_ON" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\ble_on.png"</IMAGE>;		
#endif

#ifdef __NFC_SUPPORT__
	 <IMAGE id = "IMG_SI_NFC" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NFC.png"</IMAGE>;
#endif

     <IMAGE id = "IMG_SI_DOWNLOADING" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Downloading.png"</IMAGE>;
     <IMAGE id = "IMG_SI_DOWNLOAD_COMPLETE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\\Download_Complete.png"</IMAGE>;
     <IMAGE id = "IMG_SI_DOWNLOAD_ERROR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\\Download_Error.png"</IMAGE>;

#ifdef __MMI_BG_SOUND_EFFECT__
     <IMAGE id = "IMG_SI_BGSND" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_BGSND.png"</IMAGE>;
#endif

#ifdef __MMI_AUDIO_REVERB_EFFECT__
     <IMAGE id = "IMG_SI_REVERBSND" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUDREVERB.png"</IMAGE>;
#endif

#ifdef __MMI_AUDIO_SURROUND_EFFECT__
     <IMAGE id = "IMG_SI_SURROUNDSND" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_3DSound.png"</IMAGE>;
#endif

#ifdef  __HOMEZONE_SUPPORT__ 

    <IMAGE id = "IMG_SI_HZONE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_HZONE.png"</IMAGE>;
#if (defined(__MMI_DUAL_SIM_MASTER__) || (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2)))
    <IMAGE id = "IMG_SI_HZONE_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Homezone\\\\SI_home1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HZONE_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Homezone\\\\SI_home2.png"</IMAGE>;
#endif
#if defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3)
    <IMAGE id = "IMG_SI_HZONE_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Homezone\\\\SI_home3.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HZONE_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Homezone\\\\SI_home4.png"</IMAGE>;
#endif
     <IMAGE id = "IMG_SI_CZONE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_CZONE.png"</IMAGE>;
#endif

#ifdef __CTM_SUPPORT__
     <IMAGE id = "IMG_SI_TTY_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_TTY.png"</IMAGE>;
#endif


    #ifdef __MMI_EMAIL__
    <IMAGE id = "IMG_SI_UNREAD_EMAIL" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EMUR.png"</IMAGE>;
    <IMAGE id = "IMG_SI_NEW_EMAIL" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EMNEW.png"</IMAGE>;
    #endif
    
    
    <IMAGE id = "IMG_SI_PUSH_CONNECT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_CONNECT.png"</IMAGE>; 
    <IMAGE id = "IMG_SI_PUSH_RECEIVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_RECEIVE.png"</IMAGE>; 
    <IMAGE id = "IMG_SI_PUSH_FAIL" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FAIL.png"</IMAGE>; 
#if defined(__MMI_SLIM_IMG_RES__) || defined(__MMI_NCENTER_SUPPORT__)
    <IMAGE id = "IMG_SI_UNREAD_VOICE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VOML.png"</IMAGE>;
#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    <IMAGE id = "IMG_SI_UNREAD_FAX" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FM.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_EMAIL_MSG" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EM.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_NET" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NET.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_VIDEO" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VDL.png"</IMAGE>;
#endif
#else
    <IMAGE id = "IMG_SI_UNREAD_VOICE_L1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VOML1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_VOICE_L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VOML2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_VOICE_L1L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VOML12.png"</IMAGE>;
#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    <IMAGE id = "IMG_SI_UNREAD_FAX_L1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FM1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_FAX_L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FM2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_FAX_L1L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FM12.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_EMAIL_L1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EM1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_EMAIL_L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EM2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_EMAIL_L1L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EM12.png"</IMAGE>;    

    <IMAGE id = "IMG_SI_UNREAD_NET_L1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NETL1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_NET_L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NETL2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_NET_L1L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NETL12.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_UNREAD_VIDEO_L1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VDL1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_VIDEO_L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VDL2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_VIDEO_L1L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_VDL12.png"</IMAGE>;
#endif    
#endif
   
    <IMAGE id = "IMG_SI_SMS_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MGE.png"</IMAGE>;

    <IMAGE id = "IMG_SI_SNS_UPLOAD" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_SNS_UPLOAD.png"</IMAGE>;
    <IMAGE id = "IMG_SI_SNS_FAIL" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_SNS_FAILED.png"</IMAGE>;
    <IMAGE id = "IMG_SI_SNS_COMMENT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_SNS_COMMENTS.png"</IMAGE>;
    <IMAGE id = "IMG_SI_SNS_REFRESH" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_SNS_REFRESH"</IMAGE>;
    <IMAGE id = "IMG_SI_SNS_MESSAGE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_SNS_MESSAGES.png"</IMAGE>;
    <IMAGE id = "IMG_SI_SNS_FRIEND" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_SNS_FRIENDS.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UPGRADE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_Upgrade.png"</IMAGE>;

	<IMAGE id = "IMG_SI_FULL_SMS_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Message_Full\\\\SI_MGE_FULL1.png"</IMAGE>;
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 2))
	<IMAGE id = "IMG_SI_MASTER_FULL_SMS_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Message_Full\\\\SI_MGE_FULL1.png"</IMAGE>;
	<IMAGE id = "IMG_SI_SLAVE_FULL_SMS_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Message_Full\\\\SI_MGE_FULL2.png"</IMAGE>;
#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
	<IMAGE id = "IMG_SI_SIM3_FULL_SMS_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Message_Full\\\\SI_MGE_FULL3.png"</IMAGE>;
	<IMAGE id = "IMG_SI_SIM4_FULL_SMS_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Message_Full\\\\SI_MGE_FULL4.png"</IMAGE>;
#endif /* 3 */
#endif /* 2 */


#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    <IMAGE id = "IMG_SI_CALL_DIVERT_L1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_DIVERT_L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_DIVERT_L1L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR.png"</IMAGE>;
#else
#ifndef __MMI_DUAL_SIM_MASTER__
    <IMAGE id = "IMG_SI_CALL_DIVERT_L1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_DIVERT_L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_DIVERT_L1L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR.png"</IMAGE>;
#else
    <IMAGE id = "IMG_SI_CALL_DIVERT_L1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_DIVERT_L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_DIVERT_L1L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_FOR.png"</IMAGE>;
#endif	
#endif
//#ifndef __MMI_STATUS_ICON_BAR_SLIM__   
//    <IMAGE id = "IMG_SI_VOICE_RECORD" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_REC.png"</IMAGE>;
//#endif
    <IMAGE id = "IMG_SI_MUTE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MUTE.png"</IMAGE>;
    
    #ifdef __MMI_STOPWATCH__
    <IMAGE id = "IMG_SI_STOPWATCH" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_STWATCH.png"</IMAGE>;
    #endif
    
   #if defined(__J2ME__) && defined(J2ME_SUPPORT_BACKGROUND)
    <IMAGE id = "IMG_SI_JAVA_BG_VM" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_JAVA.png"</IMAGE>;
    <IMAGE id = "IMG_SI_JAVA_BG_VM_AUDIO" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AJAVA.png"</IMAGE>;
   #endif
   #ifdef __J2ME__
    <IMAGE id = "IMG_SI_JAVA_PUSH" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Java_Push.png"</IMAGE>;
   #endif
    #ifdef WAP_SUPPORT
//#ifndef __MMI_STATUS_ICON_BAR_SLIM__    
//    <IMAGE id = "IMG_SI_WAP1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Push\\\\SI_WMAL1.png"</IMAGE>;
//    <IMAGE id = "IMG_SI_WAP2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Push\\\\SI_WMAL2.png"</IMAGE>;
//#endif
    <IMAGE id = "IMG_SI_WAP" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_WMAL.png"</IMAGE>;
    #endif

#if (defined(__MMI_FTE_SUPPORT__) || !defined(__MMI_DUAL_SIM_MASTER__))
    <IMAGE id = "IMG_SI_NETWORK_CIPHER_GSM" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NCGSM.png"</IMAGE>;
#endif

#if defined(__MMI_NETWORK_CIPHER_SUPPORT__)
    <IMAGE id = "IMG_SI_NETWORK_CIPHER_GPRS" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_NCGPRS.png"</IMAGE>;
#endif

#ifdef __MMI_AUTO_ANSWER_MACHINE__
    <IMAGE id = "IMG_SI_AUTOAM_REC" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUTOAM_Record.png"</IMAGE>;
    <IMAGE id = "IMG_SI_AUTOAM_UNREAD" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUTOAM_Message.png"</IMAGE>;
    <IMAGE id = "IMG_SI_AUTOAM_ON" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUTOAM.png"</IMAGE>;
#endif  

#ifdef __MMI_IMPS__
    <IMAGE id = "IMG_SI_IMPS_MSG" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IMPSMG.png"</IMAGE>;
    <IMAGE id = "IMG_SI_IMPS_LOGIN" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IMPS.png"</IMAGE>;
    <IMAGE id = "IMG_SI_IMPS_LOGIN_FAIL" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_IMPS_fail.png"</IMAGE>;
#endif

#ifdef __MMI_WLAN_FEATURES__
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_DISCONNECT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\wifi_disconnect.png"</IMAGE>;
#ifdef __MMI_MAINLCD_128X64__    
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_SCANNING" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI"</IMAGE>;
#else
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_SCANNING" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI"</IMAGE>;
#endif   
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\2.png"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\3.png"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT5" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\4.png"</IMAGE>;
    <IMAGE id = "IMG_ID_DTCNT_WLAN_STATUS_CONNECT6" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\WiFi\\\\SI_WIFI\\\\5.png"</IMAGE>;
#endif


#ifdef __MMI_PICT_BRIDGE_SUPPORT__
    <IMAGE id = "IMG_SI_PRINT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_PRINT.png"</IMAGE>;
    <IMAGE id = "IMG_SI_PRINT_FAIL" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_PRINT_FAIL.png"</IMAGE>;
#endif

#ifdef __MMI_CALL_INDICATOR__
    <IMAGE id = "IMG_SI_CALL_INDICATOR_ACTIVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_CallActive.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CALL_INDICATOR_HOLD" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_CallHold.png"</IMAGE>;
#endif 


#ifdef __MMI_ATV_SUPPORT__
#ifdef __MMI_MAINLCD_128X64__
    <IMAGE id = "IMG_SI_MTV_SIGNAL" >CUST_IMG_PATH"\\\\MainLCD\\\\MobileTVPlayer\\\\Signal"</IMAGE>;
#else
    <IMAGE id = "IMG_SI_MTV_SIGNAL" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\MobileTVPlayer\\\\Signal"</IMAGE>;
#endif
#endif 
#ifdef __MMI_MOBILE_TV_CMMB_SUPPORT__
    <IMAGE id = "IMG_SI_DTV_SIGNAL" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\DTVPlayer\\\\Signal"</IMAGE>;
#endif


#if defined(OBIGO_Q05A) && defined(WAP_SUPPORT)
    <IMAGE id = "IMG_SI_SECURITY" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_KEY.png"</IMAGE>;
#endif

#ifndef __MMI_UM_SLIM__
    <IMAGE id = "IMG_SI_OUTBOX_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_OUTBOXIND.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_SMS_SENDING" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_SMSSENDING.png"</IMAGE>;

#ifdef __MMI_AUDIO_PLAYER__
    <IMAGE id = "IMG_SI_AUDPLY" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_AUDPLY.png"</IMAGE>;
#endif

#if defined(__MMI_MEDIA_PLAYER__) || defined(__COSMOS_MUSICPLY__)
    <IMAGE id = "IMG_SI_MEDPLY" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MPLAYER.png"</IMAGE>;
#endif

#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    <IMAGE id = "IMG_SI_PROVMSG" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_ProvMsg.png"</IMAGE>;
//#ifdef __MMI_DUAL_SIM_MASTER__
//    <IMAGE id = "IMG_SI_PROVMSG_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\ProvBox\\\\SI_ProvMsgSIM1.png"</IMAGE>;
//    <IMAGE id = "IMG_SI_PROVMSG_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\ProvBox\\\\SI_ProvMsgSIM2.png"</IMAGE>;
//#endif
#endif


    #ifdef __MMI_EMAIL__    
    <IMAGE id = "IMG_SI_EMAIL_REF" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EMRF.png"</IMAGE>;
    #endif
    <IMAGE id = "IMG_SI_PUSHED_OBJ" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Pushed_Object.png"</IMAGE>;  

#if defined(__AGPS_SUPPORT__) && defined(__SUPL_SUPPORT__)
    <IMAGE id = "IMG_SI_AGPS_STATE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GPS"</IMAGE>;
#endif
#ifdef __MMI_SYNCML_STATUS_ICON_SUPPORT__    
    <IMAGE id = "IMG_SI_SYNCML" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_DS.png"</IMAGE>;
#endif
#ifdef __QQIM_SUPPORT__
    <IMAGE id = "IMG_SI_QQIM_AWAY" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_AWAY.png"</IMAGE>;
    <IMAGE id = "IMG_SI_QQIM_INVISIBLE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_INVISIBLE.png"</IMAGE>;
    <IMAGE id = "IMG_SI_QQIM_MSG" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_MSG.png"</IMAGE>;
    <IMAGE id = "IMG_SI_QQIM_OFFLINE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_OFFLINE.png"</IMAGE>;
    <IMAGE id = "IMG_SI_QQIM_ONLINE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_QQIM_ONLINE.png"</IMAGE>;
#endif

    <IMAGE id = "IMG_SI_MRE_DEFAULT" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MRE_DEFAULT.png"</IMAGE>;
    <IMAGE id = "IMG_SI_MRE_FETION" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MRE_DEFAULT.png"</IMAGE>;
    <IMAGE id = "IMG_SI_MRE_MSN" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MRE_DEFAULT.png"</IMAGE>;
    <IMAGE id = "IMG_SI_MRE_PUSHMAIL" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MRE_DEFAULT.png"</IMAGE>;
    <IMAGE id = "IMG_SI_MRE_QQ" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MRE_DEFAULT.png"</IMAGE>;
    <IMAGE id = "IMG_SI_MRE_PUSH" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_MRE_push.png"</IMAGE>;

#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))
    <IMAGE id = "IMG_SI_CSD_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\CSD\\\\SI_CSD1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CSD_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\CSD\\\\SI_CSD2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CSD_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\CSD\\\\SI_CSD3.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CSD_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\CSD\\\\SI_CSD4.png"</IMAGE>;

#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    <IMAGE id = "IMG_SI_HSPA_NO_PDP_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\\SI_HSPAC_SIM1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_PDP_ACTIVATED_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\\SI_HSPA_SIM1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_35G_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_35G.png"</IMAGE>;

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_HSPA_UPLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_HSPA\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_DOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_HSPA\\\\1.png"</IMAGE>;
     <IMAGE id = "IMG_SI_HSPA_UPDOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_HSPA\\\\2.png"</IMAGE>;
#endif   
    <IMAGE id = "IMG_SI_HSPA_NO_PDP_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\\SI_HSPAC_SIM2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_PDP_ACTIVATED_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\\SI_HSPA_SIM2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_35G_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_35G.png"</IMAGE>;                                 

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_HSPA_UPLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_HSPA\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_DOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_HSPA\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_UPDOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_HSPA\\\\2.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_HSPA_NO_PDP_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_HSPAC_SIM3.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_PDP_ACTIVATED_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_HSPA_SIM3.png"</IMAGE>;
    <IMAGE id = "IMG_SI_35G_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_35G.png"</IMAGE>;                                 

    <IMAGE id = "IMG_SI_HSPA_NO_PDP_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_HSPAC_SIM4.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_PDP_ACTIVATED_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_HSPA_SIM4.png"</IMAGE>;
    <IMAGE id = "IMG_SI_35G_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_35G.png"</IMAGE>;                                 
#endif
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ 
    <IMAGE id = "IMG_SI_EDGE_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_EDGE_SIM1.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_GPRS_SERVICE_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_GPRS_SIM1.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_EDGEC_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_EDGEC_SIM1.png"</IMAGE>;
  
    <IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_GPRSC_SIM1.png"</IMAGE>;
#endif  

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_EDGE\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_GPRS\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_EDGE_DOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_EDGE\\\\1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_DOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_GPRS\\\\1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_EDGE\\\\2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_GPRS\\\\2.png"</IMAGE>;
#endif
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    <IMAGE id = "IMG_SI_EDGE_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_EDGE_SIM2.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_GPRS_SERVICE_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_GPRS_SIM2.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_EDGEC_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_EDGEC_SIM2.png"</IMAGE>;
     
    <IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_GPRSC_SIM2.png"</IMAGE>;
#endif

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_EDGE\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_GPRS\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_EDGE_DOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_EDGE\\\\1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_DOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_GPRS\\\\1.png"</IMAGE>;
        
    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_EDGE\\\\2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_GPRS\\\\2.png"</IMAGE>;
#endif
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    <IMAGE id = "IMG_SI_EDGE_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_EDGE_SIM3.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_GPRS_SERVICE_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_GPRS_SIM3.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_EDGEC_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_EDGEC_SIM3.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_GPRSC_SIM3.png"</IMAGE>;
#endif 

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM3_EDGE\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPLINK_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM3_GPRS\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_EDGE_DOWNLINK_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM3_EDGE\\\\1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_DOWNLINK_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM3_GPRS\\\\1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM3_EDGE\\\\2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK_SIM3" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM3_GPRS\\\\2.png"</IMAGE>;
#endif
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__
    <IMAGE id = "IMG_SI_EDGE_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_EDGE_SIM4.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_GPRS_SERVICE_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_GPRS_SIM4.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_EDGEC_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_EDGEC_SIM4.png"</IMAGE>;

    
    <IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\GPRS\\\\SI_GPRSC_SIM4.png"</IMAGE>;
#endif

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM4_EDGE\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPLINK_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM4_GPRS\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_EDGE_DOWNLINK_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM4_EDGE\\\\1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_DOWNLINK_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM4_GPRS\\\\1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM4_EDGE\\\\2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK_SIM4" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM4_GPRS\\\\2.png"</IMAGE>;
#endif
#else
#ifdef __MMI_DUAL_SIM_MASTER__ 
    <IMAGE id = "IMG_SI_CSD_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\CSD\\\\SI_CSD1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_CSD_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\CSD\\\\SI_CSD2.png"</IMAGE>;

#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    <IMAGE id = "IMG_SI_HSPA_NO_PDP_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\\SI_HSPAC_SIM1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_PDP_ACTIVATED_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\\SI_HSPA_SIM1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_35G_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_35G.png"</IMAGE>;

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_HSPA_UPLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_HSPA\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_DOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_HSPA\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_UPDOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_HSPA\\\\2.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_HSPA_NO_PDP_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\\SI_HSPAC_SIM2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_PDP_ACTIVATED_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\\SI_HSPA_SIM2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_35G_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_35G.png"</IMAGE>;                                 

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_HSPA_UPLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_HSPA\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_DOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_HSPA\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_UPDOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_HSPA\\\\2.png"</IMAGE>;
#endif
#endif
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ 
    <IMAGE id = "IMG_SI_EDGE_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_EDGE_SIM1.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_GPRS_SERVICE_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_GPRS_SIM1.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_EDGEC_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_EDGEC_SIM1.png"</IMAGE>;

	<IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_GPRSC_SIM1.png"</IMAGE>;
#endif    

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_EDGE\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_GPRS\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_EDGE_DOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_EDGE\\\\1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_DOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_GPRS\\\\1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_EDGE\\\\2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_GPRS\\\\2.png"</IMAGE>;
#endif
#ifndef __MMI_NW_INFO_DN_STATUS_SLIM__ 
    <IMAGE id = "IMG_SI_EDGE_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_EDGE_SIM2.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_GPRS_SERVICE_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_GPRS_SIM2.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_EDGEC_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_EDGEC_SIM2.png"</IMAGE>;
  
    <IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Slave\\\SI_GPRSC_SIM2.png"</IMAGE>;
#endif 

#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_EDGE\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_GPRS\\\\0.png"</IMAGE>;

    <IMAGE id = "IMG_SI_EDGE_DOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_EDGE\\\\1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_DOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_GPRS\\\\1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_EDGE\\\\2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM2_GPRS\\\\2.png"</IMAGE>;
#endif
#endif
#endif
#if !defined(__MMI_DUAL_SIM_MASTER__) || defined(__MMI_DYNAMIC_SIM_DYNAMIC_UI__)
    <IMAGE id = "IMG_SI_CSD" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_CSD.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EDGE.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGEC" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EDGEC.png"</IMAGE>;
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_EDGE\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_DOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_EDGE\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_EDGE\\\\2.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_GPRS_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_GPRS.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_GPRSC.png"</IMAGE>;   
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_GPRS_UPLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_GPRS\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_DOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_GPRS\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_GPRS\\\\2.png"</IMAGE>;
#endif
#else
    <IMAGE id = "IMG_SI_CSD" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\CSD\\\\SI_CSD1.png"</IMAGE>;
#ifndef __MMI_STATUS_ICON_BAR_SLIM__
    <IMAGE id = "IMG_SI_EDGE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_EDGE_SIM1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGEC" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\GPRS\\\\Master\\\SI_EDGEC_SIM1.png"</IMAGE>;
#else	
    <IMAGE id = "IMG_SI_EDGE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EDGE.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGEC" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_EDGEC.png"</IMAGE>;
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_EDGE_UPLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_EDGE\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_DOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_EDGE\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_EDGE_UPDOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_EDGE\\\\2.png"</IMAGE>;
#endif
#ifndef __MMI_STATUS_ICON_BAR_SLIM__
	<IMAGE id = "IMG_SI_GPRS_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GPRS\\\\Master\\\SI_GPRS_SIM1.png"</IMAGE>;
	<IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GPRS\\\\Master\\\SI_GPRSC_SIM1.png"</IMAGE>;   
#else
	<IMAGE id = "IMG_SI_GPRS_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_GPRS.png"</IMAGE>;
	<IMAGE id = "IMG_SI_GPRS_ATT_NO_PDP_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_GPRSC.png"</IMAGE>;   
#endif
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_GPRS_UPLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_GPRS\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_DOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_GPRS\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_GPRS_UPDOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM1_GPRS\\\\2.png"</IMAGE>;
#endif
#endif
#if (defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__))
    <IMAGE id = "IMG_SI_HSPA_NO_PDP" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_HSPAC.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_PDP_ACTIVATED" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_HSPA.png"</IMAGE>;
#ifdef __MMI_NW_INFO_DN_STATUS_ULINK_DLINK_ICONS__
    <IMAGE id = "IMG_SI_HSPA_UPLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_HSPA\\\\0.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_DOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_HSPA\\\\1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_HSPA_UPDOWNLINK" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\Effect\\\\SIM_HSPA\\\\2.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_35G" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\SI_35G.png"</IMAGE>; 
#endif


#if (defined(MMI_MAX_SIM_NUM) && (MMI_MAX_SIM_NUM >= 3))

    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;

    #if defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;
    #else
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_L1"</IMAGE>;
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_L2"</IMAGE>;
    #endif
    
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_CLOSED" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_CLOSE\\\\SI_SIG_1_CLOSE.png"</IMAGE>;

    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2"</IMAGE>;

    #if defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2"</IMAGE>;
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2"</IMAGE>;
    #else
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_L1"</IMAGE>;
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_L2"</IMAGE>;
    #endif
    
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_CLOSED" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_CLOSE\\\\SI_SIG_2_CLOSE.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_SIM3_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG3"</IMAGE>;
    #if defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id = "IMG_SI_SIM3_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG3"</IMAGE>;
    <IMAGE id = "IMG_SI_SIM3_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG3"</IMAGE>;
    #else
    <IMAGE id = "IMG_SI_SIM3_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG3_L1"</IMAGE>;
    <IMAGE id = "IMG_SI_SIM3_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG3_L2"</IMAGE>;
    #endif
    <IMAGE id = "IMG_SI_SIM3_SIGNAL_CLOSED" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG3_CLOSE\\\\SI_SIG_3_CLOSE.png"</IMAGE>;

    <IMAGE id = "IMG_SI_SIM4_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG4"</IMAGE>;
    #if defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id = "IMG_SI_SIM4_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG4"</IMAGE>;
    <IMAGE id = "IMG_SI_SIM4_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG4"</IMAGE>;
    #else
    <IMAGE id = "IMG_SI_SIM4_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG4_L1"</IMAGE>;
    <IMAGE id = "IMG_SI_SIM4_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG4_L2"</IMAGE>;
    #endif
    
    <IMAGE id = "IMG_SI_SIM4_SIGNAL_CLOSED" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\GeminiPlus\\\\Signal\\\\SI_SIG4_CLOSE\\\\SI_SIG_4_CLOSE.png"</IMAGE>;
#else

#ifdef __MMI_DUAL_SIM_MASTER__ 

#ifdef __MMI_MAINLCD_128X64__
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;
    #if defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L1" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L2" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;
    #else
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L1" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_L1"</IMAGE>;
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L2" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_L2"</IMAGE>;
    #endif
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_CLOSED" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_CLOSE\\\\SI_SIG_1_CLOSE.png"</IMAGE>;

    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2"</IMAGE>;
    #if defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L1" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2"</IMAGE>;
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L2" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2"</IMAGE>;
    #else
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L1" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_L1"</IMAGE>;
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L2" >CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_L2"</IMAGE>;
    #endif
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_CLOSED" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_CLOSE\\\\SI_SIG_2_CLOSE.png"</IMAGE>;
#else
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;

    #if defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1"</IMAGE>;
    #else
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_L1"</IMAGE>;
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_L2"</IMAGE>;
    #endif
    
    <IMAGE id = "IMG_SI_MASTER_SIGNAL_CLOSED" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Master\\\\SI_SIG1_CLOSE\\\\SI_SIG_1_CLOSE.png"</IMAGE>;

    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2"</IMAGE>;
    
    #if defined(__MMI_SLIM_IMG_RES__)
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2"</IMAGE>;
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2"</IMAGE>;
    #else
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L1" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_L1"</IMAGE>;
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_STRENGTH_L2" force_type = "FORCE_ABM_SEQUENCE">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_L2"</IMAGE>;
    #endif
    
    <IMAGE id = "IMG_SI_SLAVE_SIGNAL_CLOSED" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Slave\\\\SI_SIG2_CLOSE\\\\SI_SIG_2_CLOSE.png"</IMAGE>;
#endif
#endif    
#endif

#ifdef __MMI_DUAL_SIM_MASTER__ 

    #if defined(__MMI_NETWORK_CIPHER_SUPPORT__ )
    <IMAGE id = "IMG_SI_MASTER_NETWORK_CIPHER_GSM" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Master\\\\SI_Ncipher.png"</IMAGE>;

    <IMAGE id = "IMG_SI_SLAVE_NETWORK_CIPHER_GSM" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_Ncipher.png"</IMAGE>;
    #endif
    
    #if defined(__MMI_SLIM_IMG_RES__)
    
    #else
    <IMAGE id = "IMG_SI_UNREAD_VOICE_L1_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VOML1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_VOICE_L2_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VOML2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_VOICE_L1L2_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VOML12.png"</IMAGE>;

#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    <IMAGE id = "IMG_SI_UNREAD_FAX_L1_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_FM1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_FAX_L2_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_FM2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_FAX_L1L2_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_FM12.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_EMAIL_L1_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_EM1.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_EMAIL_L2_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_EM2.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_EMAIL_L1L2_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_EM12.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_NET_L1_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_NETL1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_NET_L2_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_NETL2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_NET_L1L2_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_NETL12.png"</IMAGE>;
    <IMAGE id = "IMG_SI_UNREAD_VIDEO_L1_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VDL1.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_UNREAD_VIDEO_L2_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VDL2.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_UNREAD_VIDEO_L1L2_MASTER" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Master\\\\SI_VDL12.png"</IMAGE>;
#endif
    <IMAGE id = "IMG_SI_UNREAD_VOICE_L1_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VOML1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_VOICE_L2_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VOML2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_VOICE_L1L2_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VOML12.png"</IMAGE>;

#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    <IMAGE id = "IMG_SI_UNREAD_FAX_L1_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_FM1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_FAX_L2_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_FM2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_FAX_L1L2_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_FM12.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_EMAIL_L1_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_EM1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_EMAIL_L2_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_EM2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_EMAIL_L1L2_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_EM12.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_NET_L1_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_NETL1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_NET_L2_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_NETL2.png"</IMAGE>;

    <IMAGE id = "IMG_SI_UNREAD_NET_L1L2_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_NETL12.png"</IMAGE>;
       
    <IMAGE id = "IMG_SI_UNREAD_VIDEO_L1_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VDL1.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_UNREAD_VIDEO_L2_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VDL2.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_UNREAD_VIDEO_L1L2_SLAVE" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\Statusicons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\SMSwaitting\\\\Slave\\\\SI_VDL12.png"</IMAGE>;
#endif
    #endif
    
    <IMAGE id = "IMG_SLAVE_CALL_FORWARD" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_FOR_2.png"</IMAGE>;
    <IMAGE id = "IMG_SLAVE_CALL_FORWARD_L1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_FOR_2.png"</IMAGE>;
    <IMAGE id = "IMG_SLAVE_CALL_FORWARD_L2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\\SI_FOR_2.png"</IMAGE>;
    
    <IMAGE id = "IMG_SI_SLAVE_SMS_INDICATOR" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\Callforward\\\\Slave\\\SI_MGE_2.png"</IMAGE>;

#ifndef __MMI_STATUS_ICON_BAR_SLIM__ 
    <IMAGE id = "IMG_SI_MMS_UNREAD_INDICATOR_SIM1" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\MMS\\\\Master\\\SI_UNREAD_1.png"</IMAGE>;

    <IMAGE id = "IMG_SI_MMS_UNREAD_INDICATOR_SIM2" force_type = "FORCE_ABM">CUST_IMG_PATH"\\\\MainLCD\\\\IdleScreen\\\\StatusIcons"STATUS_ICON_IMAGE_FILE_PATH"\\\\DualSIM\\\\MMS\\\\Slave\\\SI_UNREAD_2.png"</IMAGE>;
#endif
                     
#endif

    <IMAGE id = "IMG_SLSI_SILENT">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_SIL.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_SIGNAL_STRENGTH">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG"</IMAGE>;
#ifdef __MMI_DUAL_SIM_MASTER__
	<IMAGE id = "IMG_SLSI_MASTER_SIGNAL_STRENGTH">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG_SIM1"</IMAGE>;
	<IMAGE id = "IMG_SLSI_SLAVE_SIGNAL_STRENGTH">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG_SIM2"</IMAGE>;	
	<IMAGE id = "IMG_SLSI_SIGNAL_CLOSE">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG_1_CLOSE.bmp"</IMAGE>;
	<IMAGE id = "IMG_SLSI_SLAVE_SIGNAL_CLOSE">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\signal\\\\SB_SIG_2_CLOSE.bmp"</IMAGE>;
#endif
    <IMAGE id = "IMG_SLSI_BATTERY_STRENGTH">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\battery\\\\SB_BAT"</IMAGE>;
#ifdef __MMI_DUAL_SIM_MASTER__    
    <IMAGE id = "IMG_SLSI_SMS_INDICATOR">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MG.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_SLAVE_SMS_INDICATOR">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MG_SIM2.BMP"</IMAGE>;
#else
    <IMAGE id = "IMG_SLSI_SMS_INDICATOR">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MG.BMP"</IMAGE>;
#endif        
    <IMAGE id = "IMG_SLSI_RING">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_RING.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_VIBRATE">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_VIB.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_VIBRATE_AND_RING">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_VR.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_VIBRATE_THEN_RING">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_VTR.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_ALARM">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_ALARM.BMP"</IMAGE>;
#ifdef __MMI_DUAL_SIM_MASTER__    
    <IMAGE id = "IMG_SLSI_MISSED_CALL">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MCA.BMP"</IMAGE>;
    <IMAGE id = "IMG_SLSI_SLAVE_MISSED_CALL">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MCA_SIM2.BMP"</IMAGE>;
#else   
    <IMAGE id = "IMG_SLSI_MISSED_CALL">CUST_IMG_PATH"\\\\SubLCD\\\\StatusIcons\\\\SB_MCA.BMP"</IMAGE>;
#endif    

#if defined(__MMI_DUAL_SIM_MASTER__)||defined(__KJX_FUN__)
    <IMAGE id = "WGUI_IMG_IDLE_SIM1">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SIM1.bmp"</IMAGE>;
    <IMAGE id = "WGUI_IMG_IDLE_SIM2">CUST_IMG_PATH"\\\\MainLCD\\\\UIElement\\\\SIM\\\\SIM2.bmp"</IMAGE>;
#endif

#endif /* __MMI_STATUS_ICONBAR_COSMOS_STYLE__ */     
    <!-----------------------------------------------------Image Resource Area------------------------------------------------------>

</APP>


