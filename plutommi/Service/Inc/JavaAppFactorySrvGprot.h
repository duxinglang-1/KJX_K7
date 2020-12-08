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
 *  JavaAppFactorySrvGprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JAVA_APPFACTORY_SRV_GPROT_H_
#define _JAVA_APPFACTORY_SRV_GPROT_H_
/***************************************************************************** 
 * Include
 *****************************************************************************/
 #ifdef __J2ME__
#include "MMI_include.h"
#include "AppMgrSrvGprot.h"
#include "AppMgrSrvProt.h"
#include "mmidatatype.h"

 /***************************************************************************** 
 * Define
 *****************************************************************************/
#define _MAX_FILE_NAME_LENGTH      260
typedef void(*unify_srv_callback)(void* user_data, U32 result);
extern kal_char g_mmi_java_current_launching_app_name[MMI_APP_NAME_MAX_LEN+1];
/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 typedef enum
{
    PHONE_DISK,
    MEMORY_CARD,
    RESERVED
}java_storage_position_enum;

typedef struct _java_info_struct_t
{
    kal_wchar *mids_name;   //[Name]  java app package name
    kal_uint32 mids_size;   //[Size] java app size
    kal_wchar *mids_version; //[Version] java app version
    kal_wchar *mids_vendor; //[Vendor] java app vendor
    kal_wchar *mids_description; //[Description] java app description
    kal_wchar *mids_website; //[Website] java app download website
    kal_bool mids_authorized; //[Connections] connections URL
    applib_time_struct  install_time; //java app install time 
    kal_wchar icon_path[_MAX_FILE_NAME_LENGTH]; //java app icon path
    java_storage_position_enum storage_type;//get_jar_path_from_storage_name(kal_uint32 MIDS_ID)
    kal_bool can_be_uninstall; //can be uninstall or not
    kal_bool can_be_update; // can be update or not
    void* user_data;
} java_info_struct;
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
static __inline WCHAR *GET_FILE_NAME_BUFF(void)
{
    WCHAR* file_name_buff = NULL;
    file_name_buff = (WCHAR*)get_ctrl_buffer(sizeof(WCHAR) * _MAX_FILE_NAME_LENGTH);
    return file_name_buff;
}

static __inline void FREE_FILE_NAME_BUFF(WCHAR * file_name_buff)
{
    free_ctrl_buffer(file_name_buff);
}
/*****************************************************************************
 * FUNCTION
 *  srv_java_appfactory_get_reg_mid_num
 * DESCRIPTION
 *  get the total number of installed midlet suite.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 extern U32 srv_java_appfactory_get_reg_mid_num(srv_appmgr_flag_type flag);
 
 /*****************************************************************************
 * FUNCTION
 *  srv_java_appfactory_get_reg_app_list
 * DESCRIPTION
 *  get the name list of installed midlet suite.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 extern mmi_ret srv_java_appfactory_get_reg_app_list(srv_appmgr_flag_type flag,mmi_app_package_name_struct * item, U32 num);

  /*****************************************************************************
 * FUNCTION
 *  srv_java_appfactory_get_string
 * DESCRIPTION
 *  get the name list of a midlet suite by app name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 extern mmi_ret srv_java_appfactory_get_string(CHAR * app_name, WCHAR * string);
  
/*****************************************************************************
 * FUNCTION
 *  srv_java_appfactory_get_image
 * DESCRIPTION
 *  get the name list of a midlet suite by app name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 extern mmi_ret srv_java_appfactory_get_image(CHAR * app_name, mmi_image_src_struct* img);

/*****************************************************************************
 * FUNCTION
 *  srv_java_appfactory_get_image
 * DESCRIPTION
 *  get the name list of a midlet suite by app name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 extern mmi_ret srv_java_appfactory_get_info(CHAR * app_name, srv_app_info_struct * info);

/*****************************************************************************
 * FUNCTION
 *  srv_java_appfactory_launch
 * DESCRIPTION
 *  Launch the  midlet suite by app name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_ID srv_java_appfactory_launch(srv_appfactory_launch_type_enum type, CHAR *app_name, void* param, U32 parm_size);


/*****************************************************************************
 * FUNCTION
 *  srv_java_appfactory_gen_file
 * DESCRIPTION
 *  Launch the  midlet suite by app name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
//extern mmi_ret srv_java_appfactory_gen_file(void);


/*****************************************************************************
 * FUNCTION
 *  srv_java_appfactory_get_mids_info
 * DESCRIPTION
 *  get the detail of the midlet suite by app name.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret srv_java_appfactory_get_mids_info(CHAR * app_name, java_info_struct** info);


/*****************************************************************************
* FUNCTION
 *  srv_java_appfactory_get_reg_id_list
 * DESCRIPTION
 *  get the app id list of installed midlet suite.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret srv_java_appfactory_get_reg_id_list(srv_appmgr_flag_type flag, U32 *id, U32 num);


/*****************************************************************************
* FUNCTION
 *  srv_java_appfactory_get_app_name_by_id
 * DESCRIPTION
 *  get the app name by app id
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern mmi_ret srv_java_appfactory_get_app_name_by_id(U32 id, CHAR *app_name);


/*****************************************************************************
* FUNCTION
 *  srv_java_appfactory_get_id_by_app_name
 * DESCRIPTION
 *  get the app id by app name
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern U32	srv_java_appfactory_get_id_by_app_name(const CHAR *app_name);


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_is_app_exit
* DESCRIPTION
*  check the exixtence of the java app
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern MMI_BOOL srv_java_appfactory_is_app_exit(mmi_app_package_char * app_name);


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_is_app_running
* DESCRIPTION
*  check whther the mids is running
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern MMI_BOOL srv_java_appfactory_is_app_running(mmi_app_package_char * app_name);


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_check_update_app
* DESCRIPTION
*  check whther is there available version for updating
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern void srv_java_appfactory_check_update_app(CHAR * app_name, unify_srv_callback callback);

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_get_running_app_num
* DESCRIPTION
*  Get count of running midlet
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern kal_int32 srv_java_appfactory_get_running_app_num(void);
    
/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_remove_all_records
* DESCRIPTION
*  Remove all java application records
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern mmi_ret srv_java_appfactory_remove_all_records(void);


/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_is_busy
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern kal_bool srv_java_appfactory_is_busy(void);
    

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_delete
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern mmi_ret srv_java_appfactory_delete(CHAR* app_name, srv_appmgr_uninstall_cb callback, void * user_data);

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_vk_is_on
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern kal_bool srv_java_appfactory_vk_is_on(kal_char * storage_name); 

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_vk_is_on_by_app_name
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern kal_bool srv_java_appfactory_vk_is_on_by_app_name(kal_char * app_name);

/*****************************************************************************
* FUNCTION
*  srv_java_appfactory_set_vk_on
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
extern mmi_ret srv_java_appfactory_set_vk_on(kal_bool is_on,kal_char* app_name);    
#endif
#endif
