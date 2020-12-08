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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  AppMgrSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Global interface of application manager service.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_APPMGR_GPROT_H__
#define __SRV_APPMGR_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_include.h"
#include "FileMgrSrvGProt.h"

/****************************************************************************
 * Define
 ****************************************************************************/

/* application manager service flag */
#define SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE   (0x0001) /* Applications to be displayed in main menu */
#define SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE                (0x0002) /* All application, include native, service, built-id, installed and shortcut app */
#define SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE		    (0x0004) /* Installed app. Only this type of app is allowed to be uninstalled */
#define SRV_APPMGR_SHORTCUT_APP_PACKAGE_FLAG_TYPE           (0x0008) /* Shortcut app */
#define SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE		SRV_APPMGR_SHORTCUT_APP_PACKAGE_FLAG_TYPE /* Obsolete, use SRV_APPMGR_SHORTCUT_APP_PACKAGE_FLAG_TYPE instead */

#define SRV_APPMGR_RUNNING_APP_FLAG_TYPE					(0x0300)
#define SRV_APPMGR_BG_RUNNING_APP_FLAG_TYPE				    (0x0200)

#define SRV_APPMGR_BADGE_MAX_LEN                            (3)
#define SRV_APPMGR_EVENT_DATA_MAX_LEN                       (16)

/****************************************************************************
 * Typedef
 ****************************************************************************/
/*
 * DESCRIPTION
 *  Event IDs of application manager service events.
 */
typedef enum
{
    EVT_ID_SRV_APPMGR_INSTALL_PACKAGE = SRV_APPMGR_BASE,  /* New application package was installed */
    EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE,           /* Application package was updated */
    EVT_ID_SRV_APPMGR_UNINSTALL_PACKAGE,                  /* Application package was uninstalled */
    EVT_ID_SRV_APPMGR_UPDATE_BADGE,                       /* Badge info was updated */
    EVT_ID_SRV_APPMGR_UPDATE_ALL_INSTALLED_PACKAGE,       /* Update all installed packages when insert/remove memory card, enter/leave USB mode */
    EVT_ID_SRV_APPMGR_INSTALL_START,                      /* Install process starts */
    EVT_ID_SRV_APPMGR_INSTALL_PROGRESS,                   /* Install process proceeds (data: percentage to complete) */
    EVT_ID_SRV_APPMGR_INSTALL_FINISH,                     /* Install process finishes */
    EVT_ID_SRV_APPMGR_INSTALL_ERROR,                      /* Something wrong on installation (data: error reason) */
    
    EVT_ID_SRV_APPMGR_MAX
}srv_appmgr_event_enum;

/* AppMgrSrv event structure */
typedef struct
{
    MMI_EVT_PARAM_HEADER                           /* event header */
    mmi_app_package_name_struct app_name;          /* application who initiates the event */
	U8 data[SRV_APPMGR_EVENT_DATA_MAX_LEN];
	U16 data_len;
} srv_appmgr_update_event_struct;

/* the flag of application manager service flag */
typedef U32 srv_appmgr_flag_type;

/* the application package type */
typedef enum 
{
    SRV_APPMGR_UNKNOWN_APP_PACKAGE_TYPE,           /* Unknown application */
    SRV_APPMGR_MRE_APP_PACKAGE_TYPE,               /* MRE application */
    SRV_APPMGR_NATIVE_APP_PACKAGE_TYPE,            /* Native application */
    SRV_APPMGR_JAVA_APP_PACKAGE_TYPE,              /* JAVA application */
#ifdef __GADGET_SUPPORT__
    SRV_APPMGR_WIDGET_APP_PACKAGE_TYPE,
#endif
    SRV_APPMGR_CUSTOMIZE_APP_PACKAGE_TYPE = 0x100, /* Customized application */
    SRV_APPMGR_MAX_APP_PACKAGE_TYPE,
}srv_appmgr_app_package_type_enum;

/* Application information */
typedef struct
{
    WCHAR                   string[MMI_APP_NAME_MAX_LEN+1];    /* Display name */
    mmi_image_src_struct    image;                             /* Display icon */
    WCHAR                   badge[SRV_APPMGR_BADGE_MAX_LEN+1]; /* Badge */
}srv_app_info_struct;

/* Uninstall */
typedef enum
{
    SRV_APPMGR_CB_EVENT_DONE,     /* Done */
    SRV_APPMGR_CB_EVENT_ERROR,    /* Something wrong */
    SRV_APPMGR_CB_EVENT_CANCEL,   /* Cancelled */

    SRV_APPMGR_CB_EVENT_MAX
} srv_appmgr_cb_event_enum;

typedef void (*srv_appmgr_uninstall_cb)(srv_appmgr_cb_event_enum result, void* user_data);

/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_get_app_package_num
 * DESCRIPTION
 *  Query the number of the application packages according the flag.
 * PARAMETERS
 *  flag    : [IN] SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE or SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE
 * RETURNS
 *  return the number of all application package
 *****************************************************************************/
extern U32 srv_appmgr_get_app_package_num(srv_appmgr_flag_type flag);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_get_app_package_list
 * DESCRIPTION
 *  Query the application package identification list according the flag. 
 *  The caller should call srv_appmgr_get_app_package_num() first to prepare the array size.
 * PARAMETERS
 *  flag        : [IN] SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE or SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE
 *  name_array  : [OUT] get the application name of all application packages.
 *  num         : [IN]  get the array size.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application list successfully.
 *  MMI_RET_ERR: Get the application list fail.
 *****************************************************************************/
extern mmi_ret srv_appmgr_get_app_package_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num);
/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_get_app_package_id_list
 * DESCRIPTION
 *  Query the application package identification list according the flag. This 
 *  function is useful if the RAM/NVRAM usage is a concern for the application using AppMgrSrv.
 *  The caller should call srv_appmgr_get_app_package_num() first to prepare the array size.
 * PARAMETERS
 *  flag        : [IN] SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE or SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE
 *  id_array    : [OUT] get the application ID of all application packages.
 *  num         : [IN]  get the array size.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application list successfully.
 *  MMI_RET_ERR: Get the application list failed.
 *****************************************************************************/
extern mmi_ret srv_appmgr_get_app_package_id_list(srv_appmgr_flag_type flag, U32 *id_array, U32 num);
/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_get_app_package_name_by_id
 * DESCRIPTION
 *  Query application package name by ID. 
 *  AppMgrSrv uses application package name as the key to query application info and launch app. 
 *  If a client of AppMgrSrv stores ID list instead of name list, it has to get application package name
 *  before using AppMgrSrv to query application info and launch app.
 * PARAMETERS
 *  id          : [IN] Application ID.
 *  app_name    : [OUT] Corresponding application package name.
 * RETURN VALUES
 *  MMI_RET_OK: Get application package name successfully.
 *  MMI_RET_ERR: Get application package name failed.
 *****************************************************************************/
extern mmi_ret srv_appmgr_get_app_package_name_by_id(U32 id, mmi_app_package_name_struct app_name);
/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_get_id_by_app_package_name
 * DESCRIPTION
 *  Query ID by application package name.
 *  In some case, applications may wish to store 4-byte ID instead of 60-byte name string
 *  for the identification of a give application.
 * PARAMETERS
 *  app_name    : [OUT] Application package name.
 * RETURN VALUES
 *  Application ID
 *****************************************************************************/
extern U32 srv_appmgr_get_id_by_app_package_name(mmi_app_package_name_struct app_name);
/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_get_app_package_name
 * DESCRIPTION
 *  Query the name of application packages.
 * PARAMETERS
 *  app_name  : [IN] the application package identification.
 *  string    : [OUT] the application name.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application name successfully.
 *  MMI_RET_ERR: Get the application name fail.
 *****************************************************************************/
extern mmi_ret srv_appmgr_get_app_package_name(const mmi_app_package_char *app_name, WCHAR *string);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_get_app_package_image
 * DESCRIPTION
 *  Query the image of application packages.
 * PARAMETERS
 *  app_name  : [IN] the application package identification.
 *  image     : [OUT] the application image.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application image successfully.
 *  MMI_RET_ERR: Get the application image fail.
 *****************************************************************************/
extern mmi_ret srv_appmgr_get_app_package_image(const mmi_app_package_char *app_name, mmi_image_src_struct *image);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_get_app_package_info
 * DESCRIPTION
 *  Query the information of application packages.
 * PARAMETERS
 *  app_name  : [IN] the application package identification.
 *  info      : [OUT] the application information.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application information successfully.
 *  MMI_RET_ERR: Get the application information fail.
 *****************************************************************************/
extern mmi_ret srv_appmgr_get_app_package_info(const mmi_app_package_char *app_name, srv_app_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_get_app_package_type
 * DESCRIPTION
 *  Query the type (native/Java/MRE) of application packages.
 * PARAMETERS
 *  app_name  : [IN] the application package identification.
 * RETURN VALUES
 *  SRV_APPMGR_NATIVE_APP_PACKAGE_TYPE  : it is the native application package.
 *  SRV_APPMGR_JAVA_APP_PACKAGE_TYPE    : it is JAVA application package.
 *  SRV_APPMGR_MRE_APP_PACKAGE_TYPE     : it is MRE application package.
 *  SRV_APPMGR_UNKNOWN_APP_PACKAGE_TYPE : it is unknown application package.
 *****************************************************************************/
extern srv_appmgr_app_package_type_enum srv_appmgr_get_app_package_type(const mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_is_app_package_running
 * DESCRIPTION
 *  Query if the application package is running.
 * PARAMETERS
 *  app_name  : [IN] the application package identification.
 * RETURN VALUES
 *  MMI_TRUE: The application is running.
 *  MMI_FALSE: The application is not running.
 *****************************************************************************/
extern MMI_BOOL srv_appmgr_is_app_package_running(const mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_launch
 * DESCRIPTION
 *  Launch the application package
 * PARAMETERS
 *  app_name  : [IN] the application package identification.
 * RETURNS
 *  return the application instance id. You could use the application instance
 *  id to communicate between the different running applications.
 *****************************************************************************/
extern MMI_ID srv_appmgr_launch(const mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_launch_ex
 * DESCRIPTION
 *  Launch the application package with the parameter list
 * PARAMETERS
 *  app_name    : [IN] the application package identification.
 *  param       : [IN] the parameter.
 *  param_size  : [IN] the parameter size.
 * RETURNS
 *  return the application instance id. You could use the application instance
 *  id to communicate between the different running applications.
 *****************************************************************************/
extern MMI_ID srv_appmgr_launch_ex(const mmi_app_package_char *app_name, mmi_app_launch_param_struct* param, U32 param_size);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_get_running_app_num
 * DESCRIPTION
 *  Query the number of all running applications according the flag
 * PARAMETERS
 *  flag    : [IN] SRV_APPMGR_RUNNING_APP_FLAG_TYPE or SRV_APPMGR_BG_RUNNING_APP_FLAG_TYPE
 * RETURNS
 *  return the number of running applications
 *****************************************************************************/
extern U32 srv_appmgr_get_running_app_num(srv_appmgr_flag_type flag);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_get_running_app_list
 * DESCRIPTION
 *  Query the all running applications according the flag. The caller should call
 *  srv_appmgr_get_running_app_num() first to prepare the array size.
 * PARAMETERS
 *  flag        : [IN] SRV_APPMGR_RUNNING_APP_FLAG_TYPE or SRV_APPMGR_BG_RUNNING_APP_FLAG_TYPE
 *  name_array  : [OUT] get the application name of all running applications.
 *  num         : [IN]  get the array size.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application list successfully.
 *  MMI_RET_ERR: Get the application list fail.
 *****************************************************************************/
extern mmi_ret srv_appmgr_get_running_app_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_query_instance_num
 * DESCRIPTION
 *  Query the application instance number according the identification.
 * PARAMETERS
 *  app_name  : [IN] the application package identification.
 * RETURNS
 *  return the number of the application instances.
 *****************************************************************************/
extern U32 srv_appmgr_query_instance_num(const mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_query_instance_single_id
 * DESCRIPTION
 *  Query the first one application instance id according the identification. 
 * PARAMETERS
 *  app_name            : [IN] the application package identification.
 * RETURN VALUES
 *  return the instance id directly. If the application package doesn't run, returns GRP_ID_INVALID.
 *****************************************************************************/
extern MMI_ID srv_appmgr_query_instance_single_id(const mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_query_instance_id
 * DESCRIPTION
 *  Query the application instance list according the identification. 
 *  The caller should call srv_appmgr_query_instance_num() first to prepare the array size.
 * PARAMETERS
 *  app_name            : [IN] the application package identification.
 *  instance_id_array   : [OUT] get the application instance id array.
 *  num                 : [IN]  get the array size.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application instance id array successfully.
 *  MMI_RET_ERR: Get the application instances fail.
 *****************************************************************************/
extern mmi_ret srv_appmgr_query_instance_id(const mmi_app_package_char *app_name, MMI_ID *instance_id_array, U32 num);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_close_app
 * DESCRIPTION
 *  Close the running appliction by application instance id. The caller could
 *  use srv_appmgr_query_instance_id() to get the instance id.
 * PARAMETERS
 *  app_instance_id : [IN] the running applicatio instance id.
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_appmgr_close_app(MMI_ID app_instance_id);

 /* Config */
/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_config
 * DESCRIPTION
 *  Config the running appliction with the parameter list by application identification.
 *  The caller could use srv_appmgr_query_instance_id() to get the instance id.
 * PARAMETERS
 *  app_instance_id : [IN] the running applicatio instance id.
 *  inject_string   : [IN] the inject string content.
 *  inject_index    : [IN] the inject index value.
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_appmgr_config(MMI_ID app_instance_id, CHAR* inject_string, U8 inject_index);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_send_evt
 * DESCRIPTION
 *  The applications could use this function to send the individual event to 
 *  other application instance. The event id and event structure only need
 *  to be known by sender and receiver applications.
 * PARAMETERS
 *  sender_app_instance_id  : [IN] the sender application instance id (return value of launch API).
 *  rec_app_instance_id     : [IN] the receiver application instance id (return value of launch API).
 *  mmi_event_struct        : [IN] the event structure.
 * RETURN VALUES
 *  MMI_RET_OK: send the event successfully
 *  others: send the event successfully and return the value.
 *****************************************************************************/
extern mmi_ret srv_appmgr_send_evt(MMI_ID sender_app_instance_id, MMI_ID rec_app_instance_id, mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_post_evt
 * DESCRIPTION
 *  The applications could use this function to send the individual event to 
 *  other application instance. The event id and event structure only need
 *  to be known by sender & receiver applications and this event size should be less than 100 bytes.
 * PARAMETERS
 *  sender_app_instance_id  : [IN] the sender application instance id (return value of launch API).
 *  rec_app_instance_id     : [IN] the receiver application instance id (return value of launch API).
 *  mmi_event_struct        : [IN] the event structure.
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_appmgr_post_evt(MMI_ID sender_app_instance_id, MMI_ID rec_app_instance_id, mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_post_evt_ex
 * DESCRIPTION
 *  The applications could use this function to send the individual event to 
 *  other application instance. The event id and event structure only need
 *  to be known by sender & receiver applications and this event size should
 *  be less than 100 bytes. Framework will carry the result back to self_gid group proc.
 * PARAMETERS
 *  sender_app_instance_id  : [IN] the sender application instance id (return value of launch API).
 *  rec_app_instance_id     : [IN] the receiver application instance id (return value of launch API).
 *  mmi_event_struct        : [IN] the event structure.
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_appmgr_post_evt_ex(MMI_ID sender_app_instance_id, MMI_ID rec_app_instance_id, mmi_event_struct *evt);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_update_app_info
 * DESCRIPTION
 *  An application could use this function to notify other applications the update
 *  of its information. AppMgrSrv will broadcast the update information out via 
 *  Callback Manager. The applications (e.g. Main Menu or Home Screen) who are
 *  interested in the update of applications could use srv_appmgr_get_app_package_info
 *  to get updated information and update UI accordingly when receiving the event from
 *  Callback Manager.
 * PARAMETERS
 *  app_name                : [IN] the application who initiates the update
 *  event                   : [IN] the reason of this update
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_appmgr_update_app_info(const mmi_app_package_char *app_name, srv_appmgr_event_enum event);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_update_app_info_ex
 * DESCRIPTION
 *  An application could use this function to notify other applications the update
 *  of its information. AppMgrSrv will broadcast the update information out via 
 *  Callback Manager. The applications (e.g. Main Menu or Home Screen) who are
 *  interested in the update of applications could use srv_appmgr_get_app_package_info
 *  to get updated information and update UI accordingly when receiving the event from
 *  Callback Manager.
 * PARAMETERS
 *  app_name                : [IN] the application who initiates the update
 *  event                   : [IN] the reason of this update
 *  data                    : [IN] the data associated with the event
 *  data_len                : [IN] the length of data. Maximum size is SRV_APPMGR_EVENT_DATA_MAX_LEN 
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_appmgr_update_app_info_ex(const mmi_app_package_char *app_name, srv_appmgr_event_enum event, void* data, U16 data_len);

/*****************************************************************************
 * FUNCTION
 *  srv_appmgr_uninstall_app
 * DESCRIPTION
 *  This API is used to uninstall an application. Note that only the application
 *  of SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE type could be uninstalled.
 * PARAMETERS
 *  app_name                : [IN] the application to be uninstalled
 *  cb_fct                  : [IN] callback function
 *  user_data               : [IN] user data
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern mmi_ret srv_appmgr_uninstall_app(const mmi_app_package_char *app_name, srv_appmgr_uninstall_cb cb_fct, void* user_data);

#endif /* __SRV_APPMGR_GPROT_H__ */

