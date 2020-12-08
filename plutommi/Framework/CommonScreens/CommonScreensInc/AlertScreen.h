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
 *  AlertScreen.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  header file for AlertScreen.c
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************    ************************************************************/
#ifndef __ALERT_SCREEN_H__
#define __ALERT_SCREEN_H__

#include "MMI_features.h"
#include "ScreenRotationGprot.h"
#include "MMIDataType.h"
#include "ProfilesSrvGprot.h"
#include "kal_general_types.h"
#include "mmi_frm_events_gprot.h"
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

/*****************************************************************************
 *  Define
 *****************************************************************************/

#define MMI_CONFIRM_SOFTKEY_NUM     (3)


/* alert callback result */
typedef enum _mmi_alert_result_enum
{
    /* time-out, press any key excluding END key (backward compatible only) */
    MMI_POPUP_NORMAL_EXIT,      
    /* Interrupt event come (backward compatible only) */
    MMI_POPUP_INTERRUPT_EXIT,          

    /* time-out, press any key excluding END key [popup] */
    MMI_ALERT_NORMAL_EXIT = MMI_POPUP_NORMAL_EXIT,      
    /* Interrupt event come [popup, confirm] */
    MMI_ALERT_INTERRUPT_EXIT = MMI_POPUP_INTERRUPT_EXIT,
    /* alert is not displayed [popup, confirm] */
    MMI_ALERT_NO_SHOW,          
    /* confirm OK is clicked [confirm] */
    MMI_ALERT_CNFM_OK,          
    /* confirm YES is clicked [confirm] */
    MMI_ALERT_CNFM_YES,         
    /* confirm NO is clicked [confirm] */
    MMI_ALERT_CNFM_NO,          
    /* confirm CANCEL is clicked [confirm] */
    MMI_ALERT_CNFM_CANCEL,      
    /* confirm 1 is clicked (only for CNFM_TYPE_USER_DEFINE) [confirm] */
    MMI_ALERT_CNFM_1,           
    /* confirm 2 is clicked (only for CNFM_TYPE_USER_DEFINE) [confirm] */
    MMI_ALERT_CNFM_2,           
    /* confirm 3 is clicked (only for CNFM_TYPE_USER_DEFINE) [confirm] */
    MMI_ALERT_CNFM_3,           
    MMI_ALERT_END
}mmi_alert_result_enum;

/************************************************************************
  * alert result event struct (please sync. to
  * mmi_event_popoupcallback_result_struct for backward compatible before
  * 10A).                                                                
  ************************************************************************/
typedef struct _mmi_alert_result_evt_struct
{
    MMI_EVT_PARAM_HEADER	                /* basic event header */
    void *user_tag;                         /***********************************************
                                              * caller tag for multi instance in parent proc
                                              ***********************************************/
    MMI_ID alert_id;                        /* alert id (both group and screen) */
    mmi_alert_result_enum result;           /* alert callback result */
} mmi_alert_result_evt_struct;


/* popup property struct */
typedef struct {
    mmi_proc_func               callback;               /* callback proc */
    void *                      user_tag;               /* user parameter that will pass to callback proc */
    mmi_frm_screen_rotate_enum  rotation;               /* rotation type */
    U32                         f_sliding_effect   : 1; /* enable sliding effect or not (default: true) */
    U32                         f_msg_icon         : 1; /* show msg icon or not (default: true) */
    U32                         f_auto_dismiss     : 1; /* auto dismiss or not (default: true) */
    U32                         f_play_tone        : 1; /* play tone or not (default: true) */
    MMI_ID                      parent_id;              /* parent group id */
    U32                         duration;               /* duration in ms. */
    U16                         msg_icon;               /* img id for msg icon. only works if f_msg_icon is true */
    srv_prof_tone_enum               tone_id;                /* tone id. only works if f_play_tone is true */
} mmi_popup_property_struct;


/* confirm softkey struct */
typedef struct {
    WCHAR*      str;				/* String for softkey */
    PS8         img;        /* Image for softkey */
} mmi_confirm_softkey_struct;

/* confirm type */
typedef enum {
    CNFM_TYPE_OK,					/* Softkey only show "OK" */
    CNFM_TYPE_YESNO,      /* Softkey is "Yes" and "No" */
    CNFM_TYPE_CANCEL,     /* Softkey only show "Cancel" */
    CNFM_TYPE_OKCANCEL,   /* Softkey is "OK" and "Cancel" */
    CNFM_TYPE_YESNOCANCEL,/* Softkey is "Yes" "No" and "Cancel" */
    CNFM_TYPE_USER_DEFINE,/* Softkey is defined by caller */
    CNFM_TYPE_END
} mmi_confirm_type_enum;

/* confirm property struct */
typedef struct {
    mmi_proc_func               callback;                           /* callback proc */
    void *                      user_tag;                           /* user parameter that will pass to callback proc */
    mmi_confirm_softkey_struct  softkey[MMI_CONFIRM_SOFTKEY_NUM];   /* str/img info of softkeys */
    mmi_confirm_type_enum       ctype;                              /* confirm type */
    U32                         f_sliding_effect    : 1;            /* enable sliding effect or not (default: true) */
    U32                         f_msg_icon          : 1;            /* show msg icon or not (default: true) */
    U32                         f_enter_history     : 1;            /* enter history or not (default: false) */
    U32                         f_auto_dismiss      : 1;            /* auto dismiss or not (default: true) */
    U32                         f_auto_map_empty_softkey    : 1;    /* auto map empty softkey or not (default: true) */
    U32							f_auto_question_mark  : 1;
    MMI_ID                      parent_id;                          /* parent group id */
    mmi_frm_screen_rotate_enum  rotation;                           /* rotation type */
    U16                         msg_icon;                           /* img id for msg icon. only works if f_msg_icon is true */
    srv_prof_tone_enum          tone_id;                            /* tone id. only works if f_play_tone is true */
} mmi_confirm_property_struct;


/*****************************************************************************
 * External function
 *****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_popup_property_init
 * DESCRIPTION
 *  initialize popup property struct. please do this before using mmi_popup_display
 * PARAMETERS
 *  arg             : [IN]  pointer to popup property
 * RETURNS
 *  void
 *****************************************************************************/
extern void mmi_popup_property_init(mmi_popup_property_struct *arg);


/******************************************************************
  * Description
  * \FUNCTION: mmi_confirm_property_init
  * initialize confirm property struct. please do this before using
  * mmi_confirm_display.
  * Parameters
 *  arg             : [IN]  pointer to confirm property
 *  ctype           : [IN]  confirm type
  * Returns
 *  void
  ******************************************************************/
extern void mmi_confirm_property_init(mmi_confirm_property_struct *arg, mmi_confirm_type_enum ctype);


/*****************************************************************************
 * FUNCTION
 *  mmi_popup_display_simple
 * DESCRIPTION
 *  simply display popup without setting extra properties.
 * PARAMETERS
 *  title           : [IN]  pointer to title string
 *  event_type      : [IN]  alert event type
 *  parent_id       : [IN]  parent id of this popup
 *  user_tag        : [IN]  user tag to use when callback proc invoked
 * RETURNS
 *  alert id
 *****************************************************************************/
extern MMI_ID mmi_popup_display_simple(
                    WCHAR* title, 
                    mmi_event_notify_enum event_type, 
                    MMI_ID parent_id,
                    void * user_tag);
/*****************************************************************************
 * FUNCTION
 *  mmi_popup_display_simple_ext
 * DESCRIPTION
 *  simply display popup without setting extra properties.
 * PARAMETERS
 *  title_id        : [IN]  title string id
 *  event_type      : [IN]  alert event type
 *  parent_id       : [IN]  parent id of this popup
 *  user_tag        : [IN]  user tag to use when callback proc invoked
 * RETURNS
 *  alert id
 *****************************************************************************/
extern MMI_ID mmi_popup_display_simple_ext(
                    MMI_STR_ID title, 
                    mmi_event_notify_enum event_type, 
                    MMI_ID parent_id,
                    void * user_tag);
/*****************************************************************************
 * FUNCTION
 *  mmi_popup_display
 * DESCRIPTION
 *  display popup with given properties.
 * PARAMETERS
 *  title           : [IN]  pointer to title string
 *  event_type      : [IN]  alert event type
 *  arg             : [IN]  pointer to popup property
 * RETURNS
 *  alert id
 *****************************************************************************/
extern MMI_ID mmi_popup_display( 
                    WCHAR* title, 
                	mmi_event_notify_enum event_type, 
                	mmi_popup_property_struct *arg);
/*****************************************************************************
 * FUNCTION
 *  mmi_popup_display_ext
 * DESCRIPTION
 *  display popup with given properties.
 * PARAMETERS
 *  title_id           : [IN]  title string id
 *  event_type         : [IN]  alert event type
 *  arg                : [IN]  pointer to popup property
 * RETURNS
 *  alert id
 *****************************************************************************/
extern MMI_ID mmi_popup_display_ext(
					MMI_STR_ID title_id,
					mmi_event_notify_enum event_type,
					mmi_popup_property_struct *arg);

/*****************************************************************************
 * FUNCTION
 *  mmi_confirm_display
 * DESCRIPTION
 *  display confirm with given properties.
 * PARAMETERS
 *  title           : [IN]  pointer to title string
 *  event_type      : [IN]  alert event type
 *  arg             : [IN]  pointer to confirm property
 * RETURNS
 *  confirm id
 *****************************************************************************/
extern MMI_ID mmi_confirm_display(
                	WCHAR* title, 
                	mmi_event_notify_enum event_type, 
                	mmi_confirm_property_struct *arg);
/*****************************************************************************
 * FUNCTION
 *  mmi_confirm_display_ext
 * DESCRIPTION
 *  display confirm with given properties.
 * PARAMETERS
 *  title_id          : [IN]  title string ID
 *  event_type        : [IN]  alert event type
 *  arg               : [IN]  pointer to confirm property
 * RETURNS
 *  confirm id
 *****************************************************************************/
extern MMI_ID mmi_confirm_display_ext(
					MMI_STR_ID title_id,
					mmi_event_notify_enum event_type,
					mmi_confirm_property_struct *arg);

/*****************************************************
  * FUNCTION
  * mmi_alert_dismiss
  * DESCRIPTION
  * dismiss alert (popup/confirm) with given alert id.
  * Parameters
 *  id              : [IN]  alert (popup or confirm) id to dismiss
  * Returns
  *  if alert does not exist, return false.           
  *****************************************************/
extern MMI_BOOL mmi_alert_dismiss(MMI_ID id);


/*****************************************************************************
 * FUNCTION
 *  mmi_alert_normal_exit_helper
 * DESCRIPTION
 *  helper callback to call desired ap callback for normal popup exit.
 *  please assign this as callback, and ap's callback in user_tag.
 *  then ap's callback will be invoked when popup normal exit.
 * PARAMETERS
 *  evt             : [IN]  alert quit event
 * RETURNS
 *  result
 *****************************************************************************/
extern mmi_ret mmi_alert_normal_exit_helper(mmi_event_struct *evt);

#ifdef __cplusplus
}
#endif 

#endif /* __ALERT_SCREEN_H__ */ 


