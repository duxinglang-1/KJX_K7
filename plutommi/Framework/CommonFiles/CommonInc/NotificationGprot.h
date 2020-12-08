/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 * NotificationGprot.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef NOTIFICATIONGPROT_H
#define NOTIFICATIONGPROT_H

/***************************************************************************** 
 * Header file
 *****************************************************************************/

//RHR Add    
#include "MMIDataType.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h" 

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define MMI_FRM_NMGR_SOUND  0x0001
#define MMI_FRM_NMGR_VIB    0x0002
#define MMI_FRM_NMGR_BL     0x0004
#define MMI_FRM_NMGR_SCRN   0x0008

/* option for alert (popup, balloon, text preview) and notify */
#define MMI_FRM_NMGR_DISABLE_PREVIEW          0x0001
#define MMI_FRM_NMGR_DISABLE_STATUS_ICON      0x0002
#define MMI_FRM_NMGR_ICON_BLINKING            0x0004
#define MMI_FRM_NMGR_ICON_ANIMATION           0x0008
#define MMI_FRM_NMGR_DISABLE_TONE             0x0010
#define MMI_FRM_NMGR_DISABLE_VIB              0x0020
#define MMI_FRM_NMGR_DISABLE_POPUP          0x0040

/* Maximum string size and buffer number of text preview, balloon, popup */
#define MMI_FRM_NMGR_MAX_TEXT_PREVIEW_ITEM_NUM   (10)

#define MMI_FRM_NMGR_TEXT_PREVIEW_CHAR_COUNT     (60)
#define MMI_FRM_NMGR_TEXT_PREVIEW_TEXT_BUF_LEN   (MMI_FRM_NMGR_TEXT_PREVIEW_CHAR_COUNT + 2)

#define MMI_FRM_NMGR_BALLOON_TEXT_CHAR_COUNT     (100)
#define MMI_FRM_NMGR_BALLOON_TEXT_CHAR_BUF_LEN   (MMI_FRM_NMGR_BALLOON_TEXT_CHAR_COUNT + 2)

#define MMI_FRM_NMGR_TEXT_PREVIEW_LONG_DURATION  (1000)
#define MMI_FRM_NMGR_TEXT_PREVIEW_SHORT_DURATION (200)

#define MMI_RET_FORCE_DEFER    0x500

#define MMI_FRM_NMGR_POPUP_TEXT_CHAR_COUNT     (60)
#define MMI_FRM_NMGR_POPUP_TEXT_BUF_LEN   (MMI_FRM_NMGR_POPUP_TEXT_CHAR_COUNT + 2)

#define MMI_FRM_NMGR_BUTTON_TEXT_CHAR_COUNT     (20)
#define MMI_FRM_NMGR_BUTTON_TEXT_BUF_LEN   (MMI_FRM_NMGR_BUTTON_TEXT_CHAR_COUNT + 2)


#define MMI_FRM_NMGR_USER_DATA_LEN (100)

#define MMI_MAX_CONCURRENT_POPUP_NUM  (5)

/*nmgr alert UI and behavior mask*/
/*UI mask is used for checking user input data is valid or not*/
#define MMI_FRM_NMGR_UI_STATUS_ICON_MASK 0x1
#define MMI_FRM_NMGR_UI_STATUS_BAR_MASK 0x2
#define MMI_FRM_NMGR_UI_POPUP_MASK 0x4

/*Behavior mask is created for NMGR to determine the alert behavior*/
/*Prefix is PREFER_, means NMGR will check NSS at first and follow the prefer behavior if NSS not exist*/
/*Prefix is FORCE_, means NMGR will always follow the force behavior even NSS exist*/
#define MMI_FRM_NMGR_BEHAVIOR_NSS_MASK 0x1
//#define MMI_FRM_NMGR_UI_STATUS_BAR_MASK 0x2
//#define MMI_FRM_NMGR_UI_POPUP_MASK 0x4
#define MMI_FRM_NMGR_BEHAVIOR_SHOW_ICON_MASK 0x8


#define PREFER_POPUP (MMI_FRM_NMGR_BEHAVIOR_NSS_MASK|MMI_FRM_NMGR_UI_POPUP_MASK)
#define PREFER_STATUS_BAR (MMI_FRM_NMGR_BEHAVIOR_NSS_MASK|MMI_FRM_NMGR_UI_STATUS_BAR_MASK)
#define PREFER_DEFAULT (PREFER_STATUS_BAR)

#define FORCE_ICON_ONLY MMI_FRM_NMGR_BEHAVIOR_SHOW_ICON_MASK
#define FORCE_POPUP (MMI_FRM_NMGR_UI_POPUP_MASK)
#define FORCE_STATUS_BAR (MMI_FRM_NMGR_UI_STATUS_BAR_MASK)

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
typedef enum {
    MMI_BEHAVIOR_ALL_NONE           = 0x0000,
    MMI_BEHAVIOR_SCRN_NONE          = 0x0000,
    MMI_BEHAVIOR_SND_NONE           = 0x0000,
    MMI_BEHAVIOR_VIB_NONE           = 0x0000,
    MMI_BEHAVIOR_BL_NONE            = 0x0000,
    /* Screen behavior */
    MMI_BEHAVIOR_SCRN_NO_DEFER      = 0x0001,
    /* Screen could be deferred */
    MMI_BEHAVIOR_SCRN_DEFER         = 0x0002,
    MMI_BEHAVIOR_SCRN_DEFER_FIRST   = 0x0004,
    MMI_BEHAVIOR_SCRN_DEFAULT       = MMI_BEHAVIOR_SCRN_DEFER,
    MMI_BEHAVIOR_SCRN_MASK          = MMI_BEHAVIOR_SCRN_NO_DEFER | MMI_BEHAVIOR_SCRN_DEFER | MMI_BEHAVIOR_SCRN_DEFER_FIRST,
    /* Sound behavior */
    MMI_BEHAVIOR_SND_PROFILE        = 0x0010,
    /* Sound should be change to beep in some scenario like in-call. */
    MMI_BEHAVIOR_SND_SUBTLE         = 0x0020,
    MMI_BEHAVIOR_SND_CUSTOM         = 0x0040,
    MMI_BEHAVIOR_SND_VIB_THEN_RING  = 0x0080,
    MMI_BEHAVIOR_SND_DEFAULT        = MMI_BEHAVIOR_SND_PROFILE,
    MMI_BEHAVIOR_SND_MASK           = MMI_BEHAVIOR_SND_PROFILE | MMI_BEHAVIOR_SND_SUBTLE | MMI_BEHAVIOR_SND_CUSTOM | MMI_BEHAVIOR_SND_VIB_THEN_RING,
    /* Vibrator behavior */
    MMI_BEHAVIOR_VIB_PROFILE        = 0x0100,
    MMI_BEHAVIOR_VIB_SMS            = 0x0200,
    MMI_BEHAVIOR_VIB_ON             = 0x0400,
    MMI_BEHAVIOR_VIB_CUSTOM         = 0x0800,
    MMI_BEHAVIOR_VIB_DEFAULT        = MMI_BEHAVIOR_VIB_NONE,
    MMI_BEHAVIOR_VIB_MASK           = MMI_BEHAVIOR_VIB_PROFILE | MMI_BEHAVIOR_VIB_SMS | MMI_BEHAVIOR_VIB_ON | MMI_BEHAVIOR_VIB_CUSTOM,
    /* Backlight behavior */
    MMI_BEHAVIOR_BL_SHORT_ON        = 0x1000,
    MMI_BEHAVIOR_BL_ALWAYS_ON       = 0x2000,
    MMI_BEHAVIOR_BL_TWINKLE         = 0x4000,
    MMI_BEHAVIOR_BL_DEFAULT         = MMI_BEHAVIOR_BL_SHORT_ON,
    MMI_BEHAVIOR_BL_MASK            = MMI_BEHAVIOR_BL_SHORT_ON | MMI_BEHAVIOR_BL_ALWAYS_ON | MMI_BEHAVIOR_BL_TWINKLE,
    /* Normal popup screen invoked by mmi_frm_nmgr_popup won't be deferred */
    MMI_BEHAVIOR_GENERAL            = MMI_BEHAVIOR_SCRN_DEFAULT | MMI_BEHAVIOR_SND_DEFAULT | MMI_BEHAVIOR_VIB_DEFAULT | MMI_BEHAVIOR_BL_DEFAULT,
    MMI_BEHAVIOR_END
    /* if bits used is changed, shall mmi_frm_behavior_type as well */
} mmi_nmgr_behavior_enum;

/* status bar notify type - text preview or balloon*/
typedef enum
{
    MMI_FRM_NMGR_ALERT_ST_PREVIEW_TYPE,
    MMI_FRM_NMGR_ALERT_ST_BALLOON_TYPE,
    
    MMI_FRM_NMGR_ALERT_ST_MAX_TYPE
} mmi_nmgr_alert_st_type_enum;

/* popup notify type - one button(confirm) or two button(user defeind and cancel)*/
typedef enum
{
    MMI_FRM_NMGR_ALERT_POPUP_ONE_BUTTON_TYPE,
    MMI_FRM_NMGR_ALERT_POPUP_TWO_BUTTON_TYPE,
    
    MMI_FRM_NMGR_ALERT_POPUP_MAX
} mmi_nmgr_alert_popup_type_enum;

/*Image type for alert text preview and popup usage*/
typedef enum
{
    MMI_NMGR_IMG_RES_ID,
    MMI_NMGR_IMG_FILE_PATH,
    MMI_NMGR_IMG_DATA_BUFF,
    MMI_NMGR_IMG_RAW_DATA_BUFF,

    MMI_NMGR_IMG_MAX
} mmi_nmgr_img_type_enum;

/*Sound type for alert text preview and popup usage*/
typedef enum
{
    MMI_NMGR_SND_NONE, /*NMGR will get tone id from mmi_events_notify_tbl by this case*/
    MMI_NMGR_SND_RES_ID,
    MMI_NMGR_SND_FILE_PATH,
    MMI_NMGR_SND_RAW_DATA_BUFF,

    MMI_NMGR_SND_MAX
} mmi_nmgr_snd_type_enum;

typedef enum
{
    MMI_NMGR_BALLOON_TYPE_FAILURE,
    MMI_NMGR_BALLOON_TYPE_INFO,
    MMI_NMGR_BALLOON_TYPE_WARNING,
    MMI_NMGR_BALLOON_TYPE_SUCCESS,
    MMI_NMGR_BALLOON_TYPE_PROGRESS,
    MMI_NMGR_BALLOON_TYPE_TOTAL    
} mmi_nmgr_balloon_type_enum;

typedef enum
{
    MMI_NMGR_BALLOON_UNDER_STATUS_BAR,
    MMI_NMGR_BALLOON_ABOVE_TOOL_BAR
} mmi_nmgr_balloon_pattern_enum;

typedef enum
{    
    EVT_ID_NMGR_TEXT_PREVIEW_APP_LAUNCH = SRV_NMGR_BASE + 1,
    EVT_ID_NMGR_POPUP_APP_LAUNCH,
    EVT_ID_NMGR_ALERT_END,
    
    EVT_ID_NMGR_EVT_MAX
} mmi_nmgr_evt_enum;

typedef MMI_BOOL (*mmi_noti_scrn_func_ptr)(mmi_scenario_id scen_id, void *arg);

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_scenario_id scenario_id;
} mmi_nmgr_custom_evt_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_scenario_id scenario_id;
} mmi_nmgr_sublcd_evt_struct;


/* structure of notification */
typedef struct
{
    /* Text Preview Info */
    const WCHAR                 *text;
    /* Option */
    U32                  option;
} mmi_frm_notification_para_struct;

/* Status bar icon information*/
typedef struct
{    
    S32 icon_id;
} mmi_frm_nmgr_alert_status_bar_icon_struct;


/* Popup information*/
typedef struct
{    
    mmi_nmgr_alert_popup_type_enum popup_type;
    mmi_nmgr_img_type_enum image_type;
    /*image information for popup icon*/
    union{
      /*resource id*/
      U16 id;
      /*image file path*/
      WCHAR *file_path;
      /*data buffer with 8 bytes header(size + format)*/
      U8 *data;
      /*raw data buffer wo 8 bytes header*/
      struct
       {    
           U8 *buff; 
           U32 size;
           U32 format;
       }raw_data;       
    }image;        
    /*Show on popup message*/
    const WCHAR *popup_string;
	MMI_STR_ID popup_str_id;
    /*Show on one of the popup button, another one is always "cancel" */
    const WCHAR *popup_button_string;
	MMI_STR_ID popup_button_str_id;
} mmi_frm_nmgr_alert_popup_struct;

/*status bar parameter*/    
typedef struct {
    mmi_nmgr_alert_st_type_enum status_bar_type;    
    mmi_nmgr_img_type_enum image_type;   
    /*image information for status bar*/    
    union{
      /*resource id*/
      U16 id;
      /*image file path*/
      WCHAR *file_path;
      /*data buffer with 8 bytes header(size + format)*/
      U8 *data;
      /*raw data buffer wo 8 bytes header*/
      struct
       {    
           U8 *buff; 
           U32 size;
           U32 format;
       }raw_data;       
    }image;               
    /*string information for text preview or balloon string*/        
    const WCHAR *display_string;   
}mmi_frm_nmgr_alert_status_bar_struct;

typedef struct
{
    /*NMGR will send event to notify the app launch or cancel for user to free their own mem*/
    mmi_proc_func scrn_group_proc;    
    void *user_data;
    U32  data_size;
} mmi_frm_nmgr_alert_app_proc_struct;

/*sound parameter*/    
typedef struct {
    mmi_nmgr_snd_type_enum sound_type;
    union{
      /*resource id*/  
      U16 tone_id;
      /*tone file path*/  
      WCHAR *file_path;
      /*tone raw data buffer*/  
      struct
       {    
           U8 *buff; 
           U32 size;
           U32 format;
       }raw_data;       
    }sound;                
}mmi_frm_nmgr_alert_snd_struct;

typedef struct
{
    /*For NSS query to retrieve the app's notification setting*/
    MMI_ID app_id;
    /*Scenario ID*/
    mmi_scenario_id           scen_id;
    /*Event ID*/
    mmi_event_notify_enum     event_type;

    /*Notification configuration*/
    /*Used for check input parameter*/
    U16 ui_mask;
    /*NMGR will follow the behavior mask to show notification*/
    U16 behavior_mask;
    /*User can disable notification ability by this option*/  
    U32 alert_option;

    /*status bar parameter*/
    mmi_frm_nmgr_alert_status_bar_struct status_bar_para;   
    /*popup parameter*/    
    mmi_frm_nmgr_alert_popup_struct popup_para; 
    /*status bar icon parameter*/    
    mmi_frm_nmgr_alert_status_bar_icon_struct  status_bar_icon_para; 
    /*app launch parameter*/    
    mmi_frm_nmgr_alert_app_proc_struct app_proc_para; 
    /*sound parameter*/    
    mmi_frm_nmgr_alert_snd_struct snd_para;
} mmi_frm_nmgr_alert_struct;

/*4 bytes MMI_ID + 2 bytes event type + 2 bytes icon id*/
typedef U64 NMGR_HANDLE;  

typedef struct
{
    MMI_EVT_PARAM_HEADER
    mmi_scenario_id notify_scenario_id;
    mmi_scenario_id active_scenario_id;
} mmi_nmgr_defer_check_evt_struct;


/***************************************************************************** 
 * Extern Global Function
 *****************************************************************************/
    
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_alert
 * DESCRIPTION
 *  This function helps to 
 *    1. Check alert type (none or popup or status bar) from app's notification setting (NSS) 
 *    2. Set the app launch callback for user to launch app from the notification (popup or staus bar)
 *
 * PARAMETERS
 *  alert_info  : [IN] alert parameter
 * RETURNS
 *  NMGR_HANDLE, used for cancel alert
 *****************************************************************************/
NMGR_HANDLE mmi_frm_nmgr_alert(mmi_frm_nmgr_alert_struct *alert_info);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_alert_cancel
 * DESCRIPTION
 *  This function is used by posting eventto cancel defer alert and remove related status bar icon
 *  which belong to the specific appid and type
 *  
 * PARAMETERS
 *  open_handle      : [IN] alert_handle 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_frm_nmgr_alert_cancel(NMGR_HANDLE open_handle);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_alert_cancel
 * DESCRIPTION
 *  This function is used by sending event to cancel defer alert and remove related status bar icon
 *  which belong to the specific appid and type
 *  
 * PARAMETERS
 *  open_handle      : [IN] alert_handle 
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_nmgr_alert_cancel_send(NMGR_HANDLE open_handle);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_compose_alert_handle
 * DESCRIPTION
 *  This function is used to compose nmgr handle for cancel alert
 *  
 * PARAMETERS
 *  app_id : application identity 
 *  event_type : event id, if you did not use event id to show notification (Ex. show icon only) then you need to use "MMI_EVENT_DEFAULT(0)" as your input 
 *  icon_id : status bar icon id, if you did not use icon id to show status bar icon (Ex. show text perview only), then you need to use "STATUS_ICON_INVALID_ID(-1)" as your input
 * RETURNS
 *  NMGR_JANDLE
 *****************************************************************************/
            
NMGR_HANDLE mmi_frm_nmgr_compose_alert_handle(MMI_ID app_id, mmi_event_notify_enum event_type, S32 icon_id);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_balloon
 * DESCRIPTION
 *  This function is used to send a notification by application
 *  in FTO project, nmgr will help to do text preview and add status icon
 *
 * PARAMETERS
 *  scenario_id       : [IN] scenario id to determine priority
 *  type              : [IN] notify event type
 *  balloon_type      : [IN] balloon type
 *  string            : [IN] balloon string
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_nmgr_balloon(
    mmi_scenario_id scenario_id,
    mmi_event_notify_enum type,
    mmi_nmgr_balloon_type_enum balloon_type,
    const WCHAR *string);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_notify
 * DESCRIPTION
 *  This function is used to send a notification by application
 *  in FTO project, nmgr will help to do text preview and add status icon
 *
 * PARAMETERS
 *  scen_id       : [IN] scenario id to determine priority
 *  type          : [IN] notify event type
 *  notification  : [IN] notification parameter
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_nmgr_notify(
    mmi_scenario_id                  scen_id, 
    mmi_event_notify_enum               type,
    mmi_frm_notification_para_struct *notification);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_cancel
 * DESCRIPTION
 *  This function is used to cancel notifications which belong to type by application
 *  in FTO project, nmgr will help to remove status icon
 *
 * PARAMETERS
 *
 *  type          : [IN] notify event type
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_nmgr_cancel(mmi_event_notify_enum type);


/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_popup
 * DESCRIPTION
 *  Notify a event which will invoke a popup screen, if the screen can't be displayed
 *  during current scenario, then it will be dropped and won't be displayed anymore.
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event;
 *  type :          [IN] event type which could get config-info of the notifcation event, e.g. tone id, img id, etc;
 *  string :        [IN] display string pointer;
 * RETURNS
 *  Return MMI_TRUE if screen could be shown,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_nmgr_popup(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR *string);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_notify_by_idle
 * DESCRIPTION
 *  Notify a event which scenario priority is low, this type of notification event 
 *  is controlled by idle notification mechanism now which cover mech. of async-collect app info.
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event
 *  type :          [IN] event type which could get config-info of the notifcation event, e.g. tone id, img id, etc;
 *  string :        [IN] display string pointer;
 * RETURNS
 *  Return MMI_TRUE if screen could be shown,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_nmgr_notify_by_idle(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR *string);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_notify_by_app
 * DESCRIPTION
 *  Notify a event whose screen is controlled by app, this interface also support
 *  defer mechanism which means if app's screen can't be displayed during current scenario,
 *  its entry function ptr & arg ptr could be recorded, then nmgr will invoke this screen
 *  by comparing priority between active scenario and notification scenario when current scenario is ended.
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event
 *  type :          [IN] event type which could get config-info of the notifcation event, e.g. tone id, img id, etc;
 *  screen_entry :  [IN] screen entry function pointer;
 *  arg :           [IN] argument pointer;
 * RETURNS
 *  Return MMI_TRUE if screen could be shown,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_nmgr_notify_by_app(mmi_scenario_id scenario_id, mmi_event_notify_enum type, mmi_noti_scrn_func_ptr screen_entry, void *arg);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_notify_sublcd
 * DESCRIPTION
 *  Notify a event to sublcd if user don't use
 *  mmi_frm_nmgr_popup
 *  mmi_frm_nmgr_notify_by_idle
 *  mmi_frm_nmgr_notify_by_app
 *  to nofity a event but he also hope NMGR help to display info on sublcd
 *
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event
 *
 * RETURNS
 *  Return MMI_TRUE if sublcd screen could be shown,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_nmgr_notify_sublcd(mmi_scenario_id scenario_id);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_cancel_deferred_scenario
 * DESCRIPTION
 *  Cancel deferred scenario with designated screen entry funcion and argument pointer.
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event
 *  screen_entry :  [IN] screen entry function pointer;
 *  arg :           [IN] argument pointer;
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_nmgr_cancel_deferred_scenario(mmi_scenario_id scen_id, mmi_noti_scrn_func_ptr scrn_entry_func, void *arg);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_is_scenario_deferred
 * DESCRIPTION
 *  Check if scenario with designated screen entry funcion and argument pointer has been deferred.
 * PARAMETERS
 *  scenario_id :   [IN] scenario id of notification event
 *  screen_entry :  [IN] screen entry function pointer;
 *  arg :           [IN] argument pointer;
 * RETURNS
 *  Return MMI_TRUE if has been deferred,
 *  otherwise return MMI_FALSE.
 *****************************************************************************/
extern MMI_BOOL mmi_frm_nmgr_is_scenario_deferred(mmi_scenario_id scen_id, mmi_noti_scrn_func_ptr scrn_entry_func, void *arg);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_get_defer_notification_count
 * DESCRIPTION
 *  Get the deferred events count.
 * PARAMETERS
 *  void
 * RETURNS
 *  Deferred events count
 *****************************************************************************/
extern U8 mmi_frm_nmgr_get_defer_notification_count(void);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_invoke_deder_event
 * DESCRIPTION
 *  Invoke defer event in nmgr defer queue, this interface is invoked by idle
 *  module (IdleEventCfg.c) when go back to idle screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_nmgr_invoke_deder_event(void);
/* DOM-NOT_FOR_SDK-END */

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_control_end
 * DESCRIPTION
 *  This is the ending action of nmgr containing stop sound, turn off vibrator.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_nmgr_control_end(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_set_only_disp_scrn
 * DESCRIPTION
 *  This interface could control nmgr only display screen, won't play sound, vibrator
 *   and backlight.
 * PARAMETERS
 *  flag :   [IN] switch flag
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_nmgr_set_only_disp_scrn(MMI_BOOL flag);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_block_sound_vib_stop
 * DESCRIPTION
 *  This function is used to block sound or vib stop by FW
 *  (mmi_frm_nmgr_control_end)
 * PARAMETERS
 *  noti_type  : [IN]  MMI_FRM_NMGR_SOUND or MMI_FRM_NMGR_VIB or
 *                     MMI_FRM_NMGR_VIB | MMI_FRM_NMGR_SOUND
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_nmgr_block_sound_vib_stop(U8 noti_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_unblock_sound_vib_stop
 * DESCRIPTION
 *  This function is used to unblock sound or vib stop by FW
 *  (mmi_frm_nmgr_control_end)
 *
 * PARAMETERS
 *  noti_type  : [IN]  MMI_FRM_NMGR_SOUND or MMI_FRM_NMGR_VIB or
 *                     MMI_FRM_NMGR_VIB | MMI_FRM_NMGR_SOUND
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_frm_nmgr_unblock_sound_vid_stop(U8 noti_type);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_mem_init
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_frm_nmgr_mem_init(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_mem_malloc
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void *mmi_frm_nmgr_mem_malloc(U32 size);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_nmgr_mem_free
 * DESCRIPTION
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
void mmi_frm_nmgr_mem_free(void *ptr);

/*****************************************************************************
 * FUNCTION
 *  mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal
 * DESCRIPTION
 *  This function is used alloc temp nmgr buffer and copy src string to temp buffer 
 *     and then assign to dst buff
 *  
 * PARAMETERS
 * dst str
 * src str
 * max copy len
 * RETURNS 
 *****************************************************************************/
WCHAR* mmi_frm_alloc_and_copy_string_to_nmgr_buff_internal(WCHAR *src_str, S32 max_len);
void* mmi_frm_alloc_and_copy_data_to_nmgr_buff_internal(void *src_str, S32 size);

/* DOM-NOT_FOR_SDK-BEGIN */
/*****************************************************************************
* FUNCTION
*  mmi_nmgr_sub_lcd_hdlr
* DESCRIPTION
*  nmgr sub lcd event handler
* PARAMETERS
*  evt          : [IN] event that sub lcd nmgr is interested in
* RETURNS
*  MMI_RET_OK
*****************************************************************************/
#ifdef __MMI_SUBLCD__
extern mmi_ret mmi_nmgr_sub_lcd_hdlr(mmi_event_struct *evt);
#endif /* __MMI_SUBLCD__ */

extern void mmi_frm_nmgr_disable_notification(void);

#ifdef __COSMOS_MMI_PACKAGE__
extern void mmi_frm_nmgr_status_bar_balloon_update(void);
#endif
/* DOM-NOT_FOR_SDK-END */
#endif /* NOTIFICATIONGPROT_H */

