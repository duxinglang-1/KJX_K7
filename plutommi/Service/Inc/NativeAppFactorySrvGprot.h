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
 *  NativeAppFactorySrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Global interface of native application factory service.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_NATIVEAPPFACTORY_GPROT_H__
#define __SRV_NATIVEAPPFACTORY_GPROT_H__

/****************************************************************************
 * Include
 ****************************************************************************/
#include "AppMgrSrvGprot.h"

/****************************************************************************
 * Define
 ****************************************************************************/
/* Send these events to native application package to get/notify information */
typedef enum
{
    EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_NAME,         /* Query application name string */
    EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_IMAGE,        /* Query application image */
    EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_INFO,         /* Query application name string & image */
    EVT_ID_SRV_NATIVEAPPFACTORY_QUERY_APP_BADGE,        /* Query application badge */
    EVT_ID_SRV_NATIVEAPPFACTORY_LAUNCH_APP,             /* Launch application */
    
    EVT_ID_SRV_NATIVEAPPFACTORY_MAX
}srv_nativeappfactory_event_enum;

/****************************************************************************
 * Typedef
 ****************************************************************************/
typedef struct _srv_nativeappfactory_query_app_name_evt_struct  /* EVT_ID_GROUP_POST_CALLER_NOTIFY & EVT_ID_GROUP_POST_PARENT_NOTIFY */
{
    MMI_EVT_PARAM_HEADER                                /* evt_id: event ID; user_data: the receiver's user_data */
    WCHAR   app_string[MMI_APP_NAME_MAX_LEN+1];
}srv_nativeappfactory_query_app_name_evt_struct;

typedef struct _srv_nativeappfactory_query_app_image_evt_struct  /* EVT_ID_GROUP_POST_CALLER_NOTIFY & EVT_ID_GROUP_POST_PARENT_NOTIFY */
{
    MMI_EVT_PARAM_HEADER                                /* evt_id: event ID; user_data: the receiver's user_data */
    mmi_image_src_struct app_img;
}srv_nativeappfactory_query_app_image_evt_struct;

typedef struct _srv_nativeappfactory_query_app_info_evt_struct  /* EVT_ID_GROUP_POST_CALLER_NOTIFY & EVT_ID_GROUP_POST_PARENT_NOTIFY */
{
    MMI_EVT_PARAM_HEADER                                /* evt_id: event ID; user_data: the receiver's user_data */
    WCHAR                app_string[MMI_APP_NAME_MAX_LEN+1];
    mmi_image_src_struct app_img;
}srv_nativeappfactory_query_app_info_evt_struct;

typedef struct _srv_nativeappfactory_query_app_badge_evt_struct  /* EVT_ID_GROUP_POST_CALLER_NOTIFY & EVT_ID_GROUP_POST_PARENT_NOTIFY */
{
    MMI_EVT_PARAM_HEADER                                /* evt_id: event ID; user_data: the receiver's user_data */
    WCHAR                badge[SRV_APPMGR_BADGE_MAX_LEN+1];
}srv_nativeappfactory_query_app_badge_evt_struct;

typedef struct _srv_nativeappfactory_launch_app_evt_struct  /* EVT_ID_GROUP_POST_CALLER_NOTIFY & EVT_ID_GROUP_POST_PARENT_NOTIFY */
{
    MMI_EVT_PARAM_HEADER                                /* evt_id: event ID; user_data: the receiver's user_data */
    mmi_app_launch_param_struct *param;
    U32     					param_size;
}srv_nativeappfactory_launch_app_evt_struct;

/****************************************************************************
 * Functions
 ****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_nativeappfactory_get_app_package_num
 * DESCRIPTION
 *  Query the number of the application packages according the flag.
 * PARAMETERS
 *  flag        : [IN] SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE or SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE
 * RETURNS
 *  return the number of all native application package
 *****************************************************************************/
extern U32 srv_nativeappfactory_get_app_package_num(srv_appmgr_flag_type flag);

/*****************************************************************************
 * FUNCTION
 *  srv_nativeappfactory_get_app_package_list
 * DESCRIPTION
 *  Query the native application package identification list according the flag. 
 *  The caller should call srv_nativeappfactory_get_app_package_num() first to prepare the array size.
 * PARAMETERS
 *  flag        : [IN] SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE or SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE
 *  name_array  : [OUT] get the application name of all native application packages.
 *  num         : [IN]  get the array size.
 * RETURN VALUES
 *  MMI_RET_OK: Get the native application list successfully.
 *  MMI_RET_ERR: Get the native application list fail.
 *****************************************************************************/
extern mmi_ret srv_nativeappfactory_get_app_package_list(srv_appmgr_flag_type flag, mmi_app_package_name_struct *name_array, U32 num);

/*****************************************************************************
 * FUNCTION
 *  srv_nativeappfactory_get_app_package_name
 * DESCRIPTION
 *  Query the name of native application packages.
 * PARAMETERS
 *  app_name  : [IN] the native application package identification.
 *  string    : [OUT] the application name.
 * RETURN VALUES
 *  MMI_RET_OK: Get the native application name successfully.
 *  MMI_RET_ERR: Get the native application name fail.
 *****************************************************************************/
extern mmi_ret srv_nativeappfactory_get_app_package_name(const mmi_app_package_char *app_name, WCHAR *string);

/*****************************************************************************
 * FUNCTION
 *  srv_nativeappfactory_get_app_package_image
 * DESCRIPTION
 *  Query the image of native application packages.
 * PARAMETERS
 *  app_name  : [IN] the native application package identification.
 *  image     : [OUT] the native application image.
 * RETURN VALUES
 *  MMI_RET_OK: Get the native application image successfully.
 *  MMI_RET_ERR: Get the native application image fail.
 *****************************************************************************/
extern mmi_ret srv_nativeappfactory_get_app_package_image(const mmi_app_package_char *app_name, mmi_image_src_struct *image);

/*****************************************************************************
 * FUNCTION
 *  srv_nativeappfactory_get_app_package_info
 * DESCRIPTION
 *  Query the information of native application packages.
 * PARAMETERS
 *  app_name  : [IN] the native application package identification.
 *  info      : [OUT] the native application information.
 * RETURN VALUES
 *  MMI_RET_OK: Get the native application information successfully.
 *  MMI_RET_ERR: Get the native application information fail.
 *****************************************************************************/
extern mmi_ret srv_nativeappfactory_get_app_package_info(const mmi_app_package_char *app_name, srv_app_info_struct *info);

/*****************************************************************************
 * FUNCTION
 *  srv_nativeappfactory_launch
 * DESCRIPTION
 *  Launch the native application package with the parameter list
 * PARAMETERS
 *  app_name    : [IN] the native application package identification.
 *  param       : [IN] the parameter.
 *  param_size   : [IN] the parameter size.
 * RETURNS
 *  return the native application instance id. You could use the application instance
 *  id to communicate between the different running applications.
 *****************************************************************************/
extern MMI_ID srv_nativeappfactory_launch(const mmi_app_package_char *app_name, mmi_app_launch_param_struct* param, U32 param_size);

/*****************************************************************************
 * FUNCTION
 *  srv_nativeappfactory_get_app_package_id_list
 * DESCRIPTION
 *  Query the native application package identification list according the flag. 
 *  The caller should call srv_nativeappfactory_get_app_package_num() first to prepare the array size.
 * PARAMETERS
 *  flag        : [IN] SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE or SRV_APPMGR_ALL_APP_PACKAGE_FLAG_TYPE
 *  id_array    : [OUT] get the application name of all native application packages.
 *  num         : [IN]  get the array size.
 * RETURN VALUES
 *  MMI_RET_OK: Get the native application list successfully.
 *  MMI_RET_ERR: Get the native application list fail.
 *****************************************************************************/
extern mmi_ret srv_nativeappfactory_get_app_package_id_list(srv_appmgr_flag_type flag, U32 *id_array, U32 num);

/*****************************************************************************
 * FUNCTION
 *  srv_nativeappfactory_get_app_package_name_by_id
 * DESCRIPTION
 *  Query the native application package name by a given id. 
 * PARAMETERS
 *  id          : [IN]  id.
 *  app_name    : [OUT] application package name.
 * RETURN VALUES
 *  MMI_RET_OK: Get the native application package name successfully.
 *  MMI_RET_ERR: Get the native application package name failed.
 *****************************************************************************/
extern mmi_ret srv_nativeappfactory_get_app_package_name_by_id(U32 id, mmi_app_package_name_struct app_name);

/*****************************************************************************
 * FUNCTION
 *  srv_nativeappfactory_get_id_by_app_package_name
 * DESCRIPTION
 *  Query the native app ID by application package name.
 * PARAMETERS
 *  app_name    : [IN]  application package name.
 * RETURN VALUES
 *  App ID
 *****************************************************************************/
extern U32 srv_nativeappfactory_get_id_by_app_package_name(mmi_app_package_name_struct app_name);

#endif /* __SRV_NATIVEAPPFACTORY_GPROT_H__ */

