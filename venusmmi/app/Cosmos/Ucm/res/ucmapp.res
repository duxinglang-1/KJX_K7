#include "mmi_features.h"
#include "custresdef.h"

<?xml version="1.0" encoding="UTF-8"?>

<APP id="VAPP_UCM" name="STR_ID_VAPP_UCM_CALL" type="venus">
#ifdef __MMI_VIDEO_TELEPHONY__
    #ifdef __LOW_COST_SUPPORT_COMMON__
        <MEMORY cui="VCUI_FMGR" extra_base="base(SRV_MDI_VT) + VAPP_UCM_RES_MAX_W*VAPP_UCM_RES_MAX_H*VAPP_UCM_VDO_FRAME_FACTOR + VAPP_UCM_VDO_FRAME_ENCODE_LAYER_SIZE + VAPP_UCM_RES_MAX_W*VAPP_UCM_RES_MAX_H*MDI_VT_SRV_FACTOR" inc="med_global.h,Vapp_ucm_res_def.h" />
    #else
        <MEMORY cui="VCUI_FMGR+VCUI_SMSONLYCOMPOSER" extra_base="base(SRV_MDI_VT) + VAPP_UCM_RES_MAX_W*VAPP_UCM_RES_MAX_H*VAPP_UCM_VDO_FRAME_FACTOR + VAPP_UCM_VDO_FRAME_ENCODE_LAYER_SIZE + VAPP_UCM_RES_MAX_W*VAPP_UCM_RES_MAX_H*MDI_VT_SRV_FACTOR" inc="med_global.h,Vapp_ucm_res_def.h" />
    #endif
#else
    #if defined (__MMI_UCM_SLIM__)
        <MEMORY heap="140 * 1024"/>
    #elif defined (__LOW_COST_SUPPORT_COMMON__)
        <MEMORY cui="VCUI_SMSONLYCOMPOSER" />
    #endif
#endif /* __MMI_VIDEO_TELEPHONY__ */
    <LAYOUT file="vapp_ucmapp.xml" />

    <STRING id="STR_ID_VAPP_UCM_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_LINE1"/>
    <STRING id="STR_ID_VAPP_UCM_LINE2"/>
    <STRING id="STR_ID_VAPP_UCM_NEW_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_HOLD"/>
    <STRING id="STR_ID_VAPP_UCM_RECORD"/>
#ifndef __MMI_UCM_SLIM__
    <STRING id="STR_ID_VAPP_UCM_MORE"/>
    <STRING id="STR_ID_VAPP_UCM_BT"/>
#endif
    <STRING id="STR_ID_VAPP_UCM_MUTE"/>    
    <STRING id="STR_ID_VAPP_UCM_KEYPAD"/>
    <STRING id="STR_ID_VAPP_UCM_SPEAKER"/>
    <STRING id="STR_ID_VAPP_UCM_END_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_DIALING"/>
    <STRING id="STR_ID_VAPP_UCM_SWITCH"/>
    <STRING id="STR_ID_VAPP_UCM_HIDE"/>
    <STRING id="STR_ID_VAPP_UCM_FRONT_CAMERA"/>
    <STRING id="STR_ID_VAPP_UCM_INCOMING"/>
    <STRING id="STR_ID_VAPP_UCM_ACCEPT"/>
    <STRING id="STR_ID_VAPP_UCM_REJECT"/>
    <STRING id="STR_ID_VAPP_UCM_SLIENT"/>
#ifdef __MMI_UCM_REJECT_BY_SMS__
    <STRING id="STR_ID_VAPP_UCM_MSG_REJECT"/>
    <STRING id="STR_ID_VAPP_UCM_SELECT_REJECT_MSG"/>
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
    <STRING id="STR_ID_VAPP_UCM_CONNECTING"/>
    <STRING id="STR_ID_VAPP_UCM_SEND_LOCAL_IMG"/>
    <STRING id="STR_ID_VAPP_UCM_NOT_SEND"/>
#ifdef __MMI_UCM_SLIM__
    <STRING id="STR_ID_VAPP_UCM_ACCEPT_CALL"/>
#endif /* __MMI_UCM_SLIM__ */
    <STRING id="STR_ID_VAPP_UCM_SMS_TEMPLATE"/>
    <STRING id="STR_ID_VAPP_UCM_UNHOLD"/>
    <STRING id="STR_ID_VAPP_UCM_STOP_RECORD"/>
    <STRING id="STR_ID_VAPP_UCM_NOTES"/>
#ifdef __CTM_SUPPORT__
    <STRING id="STR_ID_VAPP_UCM_CTM_SETTINGS"/>
#endif /* __CTM_SUPPORT__ */
    <STRING id="STR_ID_VAPP_UCM_ON_HOLD"/>
    <STRING id="STR_ID_VAPP_UCM_SWAP"/>
    <STRING id="STR_ID_VAPP_UCM_CONFERENCE"/>
    <STRING id="STR_ID_VAPP_UCM_SPLIT_THIS_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_END_THIS_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_REPLACE_EXISTING_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_REAR_CAMERA"/>
    <STRING id="STR_ID_VAPP_UCM_CAMERA_OFF"/>
    <STRING id="STR_ID_VAPP_UCM_UNHIDE"/>
    <STRING id="STR_ID_VAPP_UCM_SNAPSHOT"/>
    <STRING id="STR_ID_VAPP_UCM_ADJUST_LOCAL_IMG"/>
    <STRING id="STR_ID_VAPP_UCM_SWITCH_TO_VOICE_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_SNAPSHOT_SAVED"/>
    <STRING id="STR_ID_VAPP_UCM_NO_ANSWER_REDIAL"/>
    <STRING id="STR_ID_VAPP_UCM_REDIAL"/>
    <STRING id="STR_ID_VAPP_UCM_REDIAL_PROMPT"/>
    <STRING id="STR_ID_VAPP_UCM_CALL_ENDING"/>
    <STRING id="STR_ID_VAPP_UCM_REDIAL_VIDEO_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_SEND_MSG"/>
    <STRING id="STR_ID_VAPP_UCM_CALL_ENDED"/>
    <STRING id="STR_ID_VAPP_UCM_NUM_TYPE_MOBILE"/>
    <STRING id="STR_ID_VAPP_UCM_NUM_TYPE_OFFICE"/>
    <STRING id="STR_ID_VAPP_UCM_NUM_TYPE_HOME"/>
    <STRING id="STR_ID_VAPP_UCM_NUM_TYPE_FAX"/>
    <STRING id="STR_ID_VAPP_UCM_VIDEO_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_NCENTER_STR_ACTIVE"/>
    <STRING id="STR_ID_VAPP_UCM_NCENTER_STR_HELD"/>
    <STRING id="STR_ID_VAPP_UCM_SELECT_CONF_PEER"/>
    <STRING id="STR_ID_VAPP_UCM_END_ALL_CALLS"/>
    <STRING id="STR_ID_VAPP_UCM_CALL_WILL_BE_ENDED"/>
    <STRING id="STR_ID_VAPP_UCM_REDIAL_VOICE_CALL"/>
    <STRING id="STR_ID_UCM_QUESTION_MARK"/>
    <STRING id="STR_ID_UCM_SENDING_DTMF"/>
    <STRING id="STR_ID_UCM_PROCESSING"/>
    <STRING id="STR_ID_UCM_DTMF"/>
    <STRING id="STR_ID_VAPP_UCM_END_THIS_CALL_Q_MARK"/>
    <STRING id="STR_ID_VAPP_UCM_DEFAULT_SMS"/>
    <STRING id="STR_ID_VAPP_UCM_RECORDING_STOP"/>
    <STRING id="STR_ID_VAPP_UCM_DATA_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_CSD_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_VOICE_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_VIDEO_CALL"/>
    <STRING id="STR_ID_VAPP_UCM_SMS"/>
    <STRING id="STR_ID_VAPP_UCM_NOT_ALLOW_TO_HOLD"/>
    <STRING id="STR_ID_VAPP_UCM_NOT_ALLOW_TO_SWAP"/>
    <STRING id="STR_ID_VAPP_UCM_ENABLE_DMNR"/>
    <STRING id="STR_ID_VAPP_UCM_DISABLE_DMNR"/>
    <STRING id="STR_ID_VAPP_UCM_DMNR_ON"/>
    <STRING id="STR_ID_VAPP_UCM_DMNR_OFF"/>
    <STRING id="STR_ID_VAPP_UCM_INSERT_MEMORY_CARD"/>
#ifdef __MMI_UCM_SLIM__
    <STRING id="STR_ID_VAPP_UCM_SLIDE_DOWN_UNLOCK"/>
#endif /* __MMI_UCM_SLIM__ */

#if (!defined(__LOW_COST_SUPPORT_COMMON__) && !defined(__MMI_UCM_SLIM__))
    <IMAGE id="IMG_ID_VAPP_UCM_DIALING_ANI_LEFT">RES_IMG_ROOT"\\\\UCM\\\\Dial_Animation_Left"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_DIALING_ANI_RIGHT">RES_IMG_ROOT"\\\\UCM\\\\Dial_Animation_Right"</IMAGE>
#endif
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_ACCEPT">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Accept.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_ACTIVE">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Active.png"</IMAGE>
#ifndef __MMI_UCM_SLIM__
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_BT">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Bluetooth.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_MORE">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\More.png"</IMAGE>
#endif /* __MMI_UCM_SLIM__ */
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_CONF">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Conference.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_HOLD">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Hold.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_KEYPAD">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Keypad.png"</IMAGE>
#ifdef __MMI_UCM_REJECT_BY_SMS__
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_MESSAGE">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Message.png"</IMAGE>
#endif /* __MMI_UCM_REJECT_BY_SMS__ */
#ifdef __MMI_UCM_SLIM__
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_LOCK">RES_IMG_ROOT"\\\\ScreenLock\\\\Rhythm\\\\Lock.png"</IMAGE>
#endif /* __MMI_UCM_SLIM__ */
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_MUTE">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Mute.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_NEW_CALL">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\NewCall.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_REC">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Record.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_REJECT">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Reject.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_SLIENT">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Silent.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_SPEAKER">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Speaker.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_SWAP">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Swap.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_UNMUTE">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Unmute.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_RECORDING">RES_IMG_ROOT"\\\\UCM\\\\Record.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_NMGR_ACTIVE">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_call_active.png"</IMAGE>
    <IMAGE id="IMG_ID_VAPP_UCM_NMGR_HELD">RES_IMG_ROOT"\\\\NMGR_Icon\\\\icon_call_held.png"</IMAGE>
#ifdef __MMI_VIDEO_TELEPHONY__
    <IMAGE id="VAPP_UCM_VT_CAMERA">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\FrontCamera.png"</IMAGE>
    <IMAGE id="VAPP_UCM_VT_HIDE">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Hide.png"</IMAGE>
    <IMAGE id="VAPP_UCM_VT_UNHIDE">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Unhide.png"</IMAGE>
    <IMAGE id="VAPP_UCM_VT_SWITCH">RES_IMG_ROOT"\\\\UCM\\\\DialIcon\\\\Switch.png"</IMAGE>
#endif /* __MMI_VIDEO_TELEPHONY__ */

<THEME>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_DIAL_D" desc="In-call dialpad button. Disabled"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_DIAL_N" desc="In-call dialpad button. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_DIAL_P" desc="In-call dialpad button. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_DELETE_D" desc="In-call dialpad delete button. Disabled"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_DELETE_N" desc="In-call dialpad delete button. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_DELETE_P" desc="In-call dialpad delete button. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_EDITOR" desc="In-call dialpad editor"/>
    <IMAGE id="IMG_ID_VAPP_UCM_EDITOR_BG1" desc="In-call dialpad background 1"/>
    <IMAGE id="IMG_ID_VAPP_UCM_EDITOR_BG2" desc="In-call dialpad background 2"/>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_HOR_BAR_ENABLE" desc="Switchbar enable"/>
    <IMAGE id="IMG_ID_VAPP_UCM_ICON_HOR_BAR_DISABLE" desc="Switchbar disable"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_ACCEPT_N" desc="Accept call button. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_ACCEPT_P" desc="Accept call button. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_REJECT_N" desc="Reject call button. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_REJECT_P" desc="Reject call button. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_LEFT_N" desc="Action area button-Left. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_LEFT_P" desc="Action area button-Left. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_LEFTDOWN_N" desc="Action area button-LeftDown. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_LEFTDOWN_P" desc="Action area button-LeftDown. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_LEFTUP_N" desc="Action area button-LeftUp. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_LEFTUP_P" desc="Action area button-LeftUp. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_MIDDLE_N" desc="Action area button-Middle. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_MIDDLE_P" desc="Action area button-Middle. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_MIDDLEDOWN_N" desc="Action area button-MiddleDown. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_MIDDLEDOWN_P" desc="Action area button-MiddleDown. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_MIDDLEUP_N" desc="Action area button-MiddleUp. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_MIDDLEUP_P" desc="Action area button-MiddleUp. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_RIGHT_N" desc="Action area button-Right. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_RIGHT_P" desc="Action area button-Right. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_RIGHTDOWN_N" desc="Action area button-RightDown. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_RIGHTDOWN_P" desc="Action area button-RightDown. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_RIGHTUP_N" desc="Action area button-RightUp. Normal"/>
    <IMAGE id="IMG_ID_VAPP_UCM_BTN_RIGHTUP_P" desc="Action area button-RightUp. Pressed"/>
    <IMAGE id="IMG_ID_VAPP_UCM_TITLE_BG" desc="Background image of infor bar"/>
    <IMAGE id="IMG_ID_VAPP_UCM_TIME_BG" desc="Background image of call status"/>
#ifndef __MMI_UCM_SLIM__
    <IMAGE id="IMG_ID_VAPP_UCM_LOCK_ACCEPT_CALL" desc="Lockscreen accept call button"/>
    <IMAGE id="IMG_ID_VAPP_UCM_LOCK_REJECT_CALL" desc="Lockscreen reject call button"/>
#endif /* __MMI_UCM_SLIM__ */   
    <IMAGE id="IMG_ID_VAPP_UCM_CONFERENCE_CALL" desc="Conferenct call-caller picture"/>
#ifdef __MMI_VIDEO_TELEPHONY__
    <IMAGE id="VAPP_UCM_VT_DIAL" desc="Video call dial icon"/>
    <IMAGE id="VAPP_UCM_VT_VFRAME_DEFAULT_BORDER" desc="Video frame border"/>
#endif /* __MMI_VIDEO_TELEPHONY__ */
</THEME>

	<RECEIVER id="EVT_ID_SRV_UCM_ACTION_NOTIFY" proc="vm_ivr_handler"/>
	<RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="vm_ivr_handler"/>
	<RECEIVER id="EVT_ID_SRV_UCM_STATUS_CHANGE" proc="vm_ivr_handler"/>
	
    <SENDER id="EVT_ID_VAPP_UCM_BG_RUN_START" hfile="UcmGProt.h"/>
    <SENDER id="EVT_ID_VAPP_UCM_BG_RUN_END" hfile="UcmGProt.h"/>
	<RECEIVER id="EVT_ID_SRV_UCM_ACTION_NOTIFY" proc="vapp_ucm_act_notify_hdlr"/>
	<RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="vapp_ucm_ind_hdlr"/>
#ifdef __MMI_URI_AGENT__
	<RECEIVER id="EVT_ID_SRV_UCM_INDICATION" proc="mmi_ucm_uha_ind_hdlr"/>
#endif /* __MMI_URI_AGENT__ */
    <RECEIVER id="EVT_ID_SRV_UCM_CNF_INDICATION" proc="vapp_ucm_conf_ind_hdlr"/>

    <RECEIVER id="EVT_ID_MDI_AUDIO_SPEECH_STATUS_IND" proc="vapp_ucm_speech_status_ind_hdlr"/>
    <RECEIVER id="EVT_ID_GPIO_EXT_DEV_KEY_1" proc="vapp_ucm_headset_key_hdlr"/>
    <RECEIVER id="EVT_ID_VAPP_UCM_BG_RUN_START" proc="vapp_ucm_update_ncell"/>
    <RECEIVER id="EVT_ID_VAPP_UCM_BG_RUN_END" proc="vapp_ucm_update_ncell"/>
#ifdef __MMI_UCM_VT_MSG__
    <RECEIVER id="EVT_ID_SRV_SMS_READY" proc="vapp_ucm_sms_is_ready_hdlr"/>
#endif /* __MMI_UCM_VT_MSG__ */
</APP>
