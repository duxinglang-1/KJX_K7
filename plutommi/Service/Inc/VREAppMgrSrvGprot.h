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
 *  VREAppMgrSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Interface of VRE application manager service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __VRE_APPMGR_SRV_GPROT_H__
#define __VRE_APPMGR_SRV_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMIDataType.h"
#include "AppMgrSrvGprot.h"
#include "FileMgrSrvGProt.h"
#include "app_datetime.h"

/* DOM-NOT_FOR_SDK-BEGIN */
/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef enum
{
    SRV_VRE_APPMGR_APP_TYPE_UNKNOWN = 0,    /* UNKNOWN */
    SRV_VRE_APPMGR_APP_TYPE_DOWNLOAD,       /* dwonload from server */
    SRV_VRE_APPMGR_APP_TYPE_ROM,            /* build-in app */
    SRV_VRE_APPMGR_APP_TYPE_LOCAL_INSTALL,  /* install from local */
    SRV_VRE_APPMGR_APP_TYPE_SHORTCUT,       /* shortcut app */
    SRV_VRE_APPMGR_APP_TYPE_END_OF_ENUM
} srv_vre_appmgr_app_type_enum;

/* Application storage position type */
typedef enum
{
    SRV_VRE_APPMGR_APP_POSITION_UNKNOWN = 0,    /* UNKNOWN */
    SRV_VRE_APPMGR_APP_POSITION_PHONE,          /* Phone */
    SRV_VRE_APPMGR_APP_POSITION_CARD,           /* Memory card */
    SRV_VRE_APPMGR_APP_POSITION_ROM,            /* build-in app */
    SRV_VRE_APPMGR_APP_POSITION_END_OF_ENUM
} srv_vre_appmgr_app_storage_position_enum;

typedef enum
{
    SRV_VRE_APPMGR_CHECK_UPDATE_YES = 0,
    SRV_VRE_APPMGR_CHECK_UPDATE_NO,
    SRV_VRE_APPMGR_CHECK_UPDATE_FAIL,
    SRV_VRE_APPMGR_CHECK_UPDATE_END_OF_ENUM
} srv_vre_appmgr_check_update_state_enum;

/* Before update an application, you should get update state by this callback */
typedef void (*srv_vre_appmgr_app_update_check_cb_t) (U32 appid, srv_vre_appmgr_check_update_state_enum state,
                                                      U32 filesize, U16 *filename);

typedef enum
{
    SRV_VRE_APPMGR_UPDATE_SUCCESS = 0,
    SRV_VRE_APPMGR_UPDATE_FAIL,
    SRV_VRE_APPMGR_UPDATE_END_OF_ENUM
} srv_vre_appmgr_update_state_enum;

/* Update callback */
typedef void (*srv_vre_appmgr_app_update_cb_t) (U32 appid, srv_vre_appmgr_update_state_enum state, void *user_data);

/* Before start a download, you should get app info by this callback */
typedef enum
{
    SRV_VRE_APPMGR_DOWNLOAD_GETINFO_SUCCESS = 0,
    SRV_VRE_APPMGR_DOWNLOAD_GETINFO_FAIL,
    SRV_VRE_APPMGR_DOWNLOAD_GETINFO_END_OF_ENUM
} srv_vre_appmgr_download_getinfo_state_enum;
typedef void (*srv_vre_appmgr_download_getinfo_cb_t) (U32 app_id, srv_vre_appmgr_download_getinfo_state_enum state,
                                                      U32 file_size, U16 *file_name);

/* When start a download, you can get download info by this callback */
typedef enum
{
    SRV_VRE_APPMGR_DOWNLOAD_DOWNLOADING,        /* downloading */
    SRV_VRE_APPMGR_DOWNLOAD_DONE,               /* app download successfully */
    SRV_VRE_APPMGR_DOWNLOAD_NETWORK_ERROR,      /* network error */
    SRV_VRE_APPMGR_DOWNLOAD_MEMORY_FULL_ERROR,  /* not enough memory */
    SRV_VRE_APPMGR_DOWNLOAD_IO_ERROR,           /* I/O error */
    SRV_VRE_APPMGR_DOWNLOAD_OTHER_ERROR,        /* other error */
    SRV_VRE_APPMGR_DOWNLOAD_END_OF_ENUM
} srv_vre_appmgr_download_state_enum;
typedef void (*srv_vre_appmgr_download_cb_t) (U32 app_id, srv_vre_appmgr_download_state_enum state, U32 file_size);

/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_file_path
 * DESCRIPTION
 *  Get file path of the application.
 * PARAMETERS
 *  app_name : [IN] the application package identification.
 *  filepath : [OUT] get the application file path.
 * RETURN VALUES
 *  MMI_RET_OK: If successful.
 *  MMI_RET_ERR: If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_get_file_path(mmi_app_package_char *app_name, U16 *filepath);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_num
 * DESCRIPTION
 *  Get the number of all the VRE applications, including build-in applications and shortcut applications.
 * PARAMETERS
 *  flag : [IN] application manager service flag.
 * RETURNS
 *  return the number of all application package
 *****************************************************************************/
extern U32 srv_vre_appmgr_get_app_num(S32 flag);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_installed_app_num
 * DESCRIPTION
 *  Get the number of the installed applications, including build-in applications. But not include shortcut applications.
 * PARAMETERS
 *  void
 * RETURNS
 *  return the number of all application package
 *****************************************************************************/
extern U32 srv_vre_appmgr_get_installed_app_num(void);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_list
 * DESCRIPTION
 *  Get the application identifications, including shortcut application.
 *  The caller should call srv_vre_appmgr_get_app_num() firstly to prepare the array size.
 * PARAMETERS
 *  flag : [IN] application manager service flag.
 *  name_array : [OUT] get the application name of all installed applications.
 *  num : [IN]  the array size.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application list successfully.
 *  MMI_RET_ERR: Get the application list fail.
 *****************************************************************************/
extern mmi_ret srv_vre_appmgr_get_app_list(S32 flag, mmi_app_package_name_struct *name_array, U32 num);


/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_installed_app_list
 * DESCRIPTION
 *  Get the application identifications, not include shortcut application.
 *  The caller should call srv_vre_appmgr_get_app_num() firstly to prepare the array size.
 * PARAMETERS
 *  name_array : [OUT] get the application name of all installed applications.
 *  num : [IN]  the array size.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application list successfully.
 *  MMI_RET_ERR: Get the application list fail.
 *****************************************************************************/
extern mmi_ret srv_vre_appmgr_get_installed_app_list(mmi_app_package_name_struct *name_array, U32 num);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_name
 * DESCRIPTION
 *  Get the name of application.
 * PARAMETERS
 *  app_name  : [IN] the application package identification.
 *  string    : [OUT] the application name.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application name successfully.
 *  MMI_RET_ERR: Get the application name fail.
 *****************************************************************************/
extern mmi_ret srv_vre_appmgr_get_app_name(mmi_app_package_char *app_name, WCHAR *string);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_image
 * DESCRIPTION
 *  Get the image of application.
 * PARAMETERS
 *  app_name  : [IN] the application identification.
 *  image     : [OUT] the application image.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application image successfully.
 *  MMI_RET_ERR: Get the application image fail.
 *****************************************************************************/
extern mmi_ret srv_vre_appmgr_get_app_image(mmi_app_package_char *app_name, mmi_image_src_struct *image);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_info
 * DESCRIPTION
 *  Get the information of application.
 * PARAMETERS
 *  app_name  : [IN] the application identification.
 *  info      : [OUT] the application information.
 * RETURN VALUES
 *  MMI_RET_OK: Get the application information successfully.
 *  MMI_RET_ERR: Get the application information failed.
 *****************************************************************************/
extern mmi_ret srv_vre_appmgr_get_app_info(mmi_app_package_char *app_name, srv_app_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_launch
 * DESCRIPTION
 *  Launch the application
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  param : [IN] the launch parameter.
 *  param_size : [IN] the parameter size.
 * RETURNS
 *  return the application instance id. You could use the application instance
 *  id to communicate between the different running applications.
 *****************************************************************************/
extern MMI_ID srv_vre_appmgr_launch(mmi_app_package_char *app_name, void *param, U32 param_size);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_launch_by_filepath
 * DESCRIPTION
 *  Launch an application by file path.
 * PARAMETERS
 *  app_path : [IN] the application path.
 * RETURNS
 *  
 *****************************************************************************/
extern MMI_ID srv_vre_appmgr_launch_by_filepath(U16 *app_path);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_type
 * DESCRIPTION
 *  Get application type.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 * RETURNS
 *  return app type.
 *****************************************************************************/
extern srv_vre_appmgr_app_type_enum srv_vre_appmgr_get_app_type(mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_storage_position
 * DESCRIPTION
 *  Get application storage position.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 * RETURNS
 *  return app storage position.
 *****************************************************************************/
extern srv_vre_appmgr_app_storage_position_enum srv_vre_appmgr_get_app_storage_position(
                                                    mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_description
 * DESCRIPTION
 *  Get the description of a VRE application. If p_desc is NULL, then return the description size by desc_size.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  p_desc : [OUT] Pointer to app description buffer.
 *  desc_size : [OUT] Size of app description.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_get_app_description(mmi_app_package_char *app_name, U16 *p_desc, U32 *desc_size);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_size
 * DESCRIPTION
 *  Get application size.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 * RETURNS
 *  return app size.
 *****************************************************************************/
extern U32 srv_vre_appmgr_get_app_size(mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_developer
 * DESCRIPTION
 *  Get the developer name of a VRE application. If p_developer is NULL, then return the name size by developer_size.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  p_developer : [OUT] Pointer to developer name buffer, and the length of number less than 10.
 *  developer_size : [OUT] Size of developer name.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_get_app_developer(mmi_app_package_char *app_name, U16 *p_developer, U32 *developer_size);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_tel
 * DESCRIPTION
 *  Get the telephone number of the developer.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  p_tel : [OUT] Pointer to telephone number buffer, and the length of number less than 20.
 * RETURN VALUES
 *  MMI_TRUE : If successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_get_app_tel(mmi_app_package_char *app_name, U16 *p_tel);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_is_support_uninstall
 * DESCRIPTION
 *  Uninstall an application.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 * RETURN VALUES
 *  MMI_TRUE : If uninstall successful.
 *  MMI_FALSE : If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_app_uninstall(mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_is_bg_downloading
 * DESCRIPTION
 *  Check if the application is downloading in background.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 * RETURN VALUES
 *  MMI_TRUE : If downloading in background.
 *  MMI_FALSE : If not downloading in background.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_is_bg_downloading(mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_is_bg_downloading_by_path
 * DESCRIPTION
 *  Check if the application is downloading in background.
 * PARAMETERS
 *  app_path : [IN] the application file path.
 * RETURN VALUES
 *  MMI_TRUE : If downloading in background.
 *  MMI_FALSE : If not downloading in background.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_is_bg_downloading_by_path(U16 *app_path);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_download
 * DESCRIPTION
 *  Download a shortcut application from main menu.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_vre_appmgr_download(mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_is_bg_running
 * DESCRIPTION
 *  Check if the application is running in background.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 * RETURN VALUES
 *  MMI_TRUE : If running in background.
 *  MMI_FALSE : If not running in background.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_is_bg_running(mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_is_app_exist
 * DESCRIPTION
 *  Check if the application exist or not.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 * RETURN VALUES
 *  MMI_TRUE : If app exists.
 *  MMI_FALSE : If app not exist.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_is_app_exist(mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_is_shortcut_app
 * DESCRIPTION
 *  Check if the application is shortcut app.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 * RETURN VALUES
 *  MMI_TRUE : If it is shortcut app.
 *  MMI_FALSE : If it is not shortcut app.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_is_shortcut_app(mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_get_app_install_time
 * DESCRIPTION
 *  Get the install time.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  install_time : [OUT] install time
 * RETURN VALUES
 *  MMI_TRUE: Get install time successfully.
 *  MMI_FALSE: Get install time failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_get_app_installed_time(
                    mmi_app_package_char *app_name,
                    applib_time_struct *install_time);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_install_app
 * DESCRIPTION
 *  Install an application.
 * PARAMETERS
 *  app_path : [IN] the application path.
 *  app_type : [IN] the application type.
 *  app_name : [OUT] the application identification.
 * RETURN VALUES
 *  MMI_TRUE: If successful.
 *  MMI_FALSE: If failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_install_app(
                    U16 *app_path,
                    srv_vre_appmgr_app_type_enum app_type,
                    mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_is_support_uninstall
 * DESCRIPTION
 *  Check if the application support uninstall.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 * RETURN VALUES
 *  MMI_TRUE : If support uninstall.
 *  MMI_FALSE : If not support uninstall.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_is_support_uninstall(mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_is_app_installed
 * DESCRIPTION
 *  Check if the application is installed.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 * RETURN VALUES
 *  MMI_TRUE : If the app is installed.
 *  MMI_FALSE : If the app is not installed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_is_app_installed(mmi_app_package_char *app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_is_app_installed_by_path
 * DESCRIPTION
 *  Check if the application is installed by app path.
 * PARAMETERS
 *  app_path : [IN] the application path.
 * RETURN VALUES
 *  MMI_TRUE : If the app is installed.
 *  MMI_FALSE : If the app is not installed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_is_app_installed_by_path(U16 *app_path);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_check_update
 * DESCRIPTION
 *  Check if the application need to update.
 * PARAMETERS
 *  app_name : [IN] the application identification.
 *  check_cb : [IN] get update state by this callback.
 * RETURN VALUES
 *  MMI_TRUE : If start check update request successfully.
 *  MMI_FALSE : If start check update request failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_check_update(
                    mmi_app_package_char *app_name,
                    srv_vre_appmgr_app_update_check_cb_t check_cb);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_cancel_check_update
 * DESCRIPTION
 *  Cancel the check update operation.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_vre_appmgr_cancel_check_update(void);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_app_update
 * DESCRIPTION
 *  Start update application, the download will be added to DLAgent.
 * PARAMETERS
 *  appid : [IN] application id.
 *  filename : [IN] after dwonloaded, save as this filename. You should get this filename by srv_vre_appmgr_check_update().
 *  filesize : [IN] file total size.
 *  update_cb : [IN] update callback funtion.
 *  user_data : [IN] user data.
 * RETURN VALUES
 *  MMI_TRUE : If start update request successfully.
 *  MMI_FALSE : If start update request failed.
 *****************************************************************************/
extern MMI_BOOL srv_vre_appmgr_app_update(
                    U32 appid, 
                    U16 *filename, 
                    U32 *filesize, 
                    srv_vre_appmgr_app_update_cb_t update_cb,
                    void *user_data);

/****************************************************************************
 * The following api provided for download agent.
 * 1. srv_vre_appmgr_download_get_app_info
 * 2. srv_vre_appmgr_download_start
 * 3. srv_vre_appmgr_download_stop
 * 4. srv_vre_appmgr_download_cancel
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_da_download_get_app_info
 * DESCRIPTION
 *  Before start a download, you should call this function to get filesize and filename.
 * PARAMETERS
 *  appid : [IN] the application id.
 *  getinfo_cb : [IN] get application file size and file name by this callback.
 * RETURN VALUES
 *  MMI_RET_OK: If start a getinfo request successfully.
 *  MMI_RET_ERR: If failed.
 *****************************************************************************/
extern mmi_ret srv_vre_appmgr_da_download_get_app_info(U32 appid, srv_vre_appmgr_download_getinfo_cb_t getinfo_cb);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_da_download_cancel_get_app_info
 * DESCRIPTION
 *  Cancel the get info operation.
 * PARAMETERS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
extern void srv_vre_appmgr_da_download_cancel_get_app_info(void);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_da_download_start
 * DESCRIPTION
 *  Start a download.
 * PARAMETERS
 *  appid : [IN] the application id.
 *  filepath : [IN] after download, save as this filepath. You should get this filename by srv_vre_appmgr_da_download_get_app_info().
 *  download_cb : [IN] get download status and information by this callback.
 * RETURN VALUES
 *  MMI_RET_OK: If start download request successfully.
 *  MMI_RET_ERR: If failed.
 *****************************************************************************/
extern mmi_ret srv_vre_appmgr_da_download_start(U32 appid, U16 *filepath, srv_vre_appmgr_download_cb_t download_cb);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_da_download_stop
 * DESCRIPTION
 *  Stop a download. After stop a download, it will be pause state in DLAgent.
 * PARAMETERS
 *  appid : [IN] the application id.
 * RETURN VALUES
 *  MMI_RET_OK: If stop download successfully.
 *  MMI_RET_ERR: If failed.
 *****************************************************************************/
extern mmi_ret srv_vre_appmgr_da_download_stop(U32 appid);

/*****************************************************************************
 * FUNCTION
 *  srv_vre_appmgr_da_download_cancel
 * DESCRIPTION
 *  Cancel a download. Means stop the download and delete the temp file, when download it again, will start from the beginning.
 * PARAMETERS
 *  appid : [IN] the application id.
 * RETURN VALUES
 *  MMI_RET_OK: If cancel download successfully.
 *  MMI_RET_ERR: If failed.
 *****************************************************************************/
extern mmi_ret srv_vre_appmgr_da_download_cancel(U32 appid);

/* DOM-NOT_FOR_SDK-END */

#endif /* __VRE_APPMGR_SRV_GPROT_H__ */ 

