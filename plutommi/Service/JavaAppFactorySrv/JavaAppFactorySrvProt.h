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
 *  JavaAppFactorySrvProt.h
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
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _JAVA_APPFACTORY_SRV_PROT_H_
#define _JAVA_APPFACTORY_SRV_PROT_H_
#ifdef __J2ME__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_include.h"

 /***************************************************************************** 
 * Define
 *****************************************************************************/
#define LEN 30
#define STORAGE_LEN 20
#define MIDLET_NAME_LEN    50
#define MIDLET_VENDOR_LEN  30
#define MIDLET_VERSION_LEN 30
#define MIDLET_INSTALL_PATH_LEN 80 

/***************************************************************************** 
 * Typedef
 *****************************************************************************/
 
typedef struct _mmi_java_app_factory_record_struct_t
{
    kal_char  storage_name[STORAGE_LEN]; //strorage name
    WCHAR mids_name[MMI_APP_NAME_MAX_LEN]; // MIDlet name
    WCHAR mids_vendor[MIDLET_VENDOR_LEN]; // MIDlet vendor name
    CHAR  mids_version[MIDLET_VERSION_LEN]; // MIDlet vendor name
    kal_bool is_default; // default game flag
    kal_bool is_op_mids; // operator reqirement mdis flag
    kal_bool is_vk_on; // VK is on
    kal_char installed_drive; // installed drive
    kal_bool is_bg_enabled;
    kal_bool is_installed;     //installed  or not ;
    WCHAR install_path[MIDLET_INSTALL_PATH_LEN];
} mmi_java_app_factory_record_struct;

typedef void(*mids_delete_callback)(void* user_data, kal_int32 result);
/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
extern kal_char g_mmi_java_current_launching_app_name[MMI_APP_NAME_MAX_LEN+1];
extern CHAR g_java_current_install_app_name[MMI_APP_NAME_MAX_LEN];
/***************************************************************************** 
 * Function
 *****************************************************************************/
 
extern mmi_ret srv_java_appfactory_add_record(mmi_java_app_factory_record_struct* record);
extern mmi_ret srv_java_appfactory_remove_record(CHAR * app_name);

extern mmi_ret srv_java_appfactory_gen_file(void);
extern void srv_java_appfactory_get_mids_info_cnf(void* para);

extern mmi_ret srv_java_appfactory_get_storage_name_by_app_name(CHAR* storage_name,CHAR * app_name);
extern void srv_java_appfactory_get_app_name_by_storage_name(CHAR * app_name, kal_char* storage_name);

extern kal_bool srv_java_appfactory_get_bg_enabled_apname(kal_bool* is_on, CHAR *app_name);
extern kal_bool srv_java_appfactory_get_bg_enabled(kal_bool* is_on, kal_int32 vm_id);
extern kal_bool srv_java_appfactory_set_bg_enabled_apname(kal_bool is_on, CHAR *app_name);
extern kal_bool srv_java_appfactory_set_bg_enabled(kal_bool is_on, kal_int32 vm_id);

extern MMI_BOOL srv_java_appfactory_is_app_running(mmi_app_package_char * app_name);
extern kal_bool srv_java_appfactory_get_preinstall_mids_path(WCHAR*mids_jad_path,WCHAR* mids_jar_path,kal_bool * is_installed,kal_char * app_name);   
extern void srv_java_appfactory_preinstall_mids_install(kal_char * app_name);    
extern kal_bool srv_java_appfactory_mids_is_default(kal_char * storage_name);   
extern void srv_java_appfactory_timer_callback(void);

#endif
#endif
