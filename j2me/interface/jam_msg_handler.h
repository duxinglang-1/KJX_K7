/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
* permission of MediaTek Inc. (C) 2005
*
* BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
* THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
* RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
* AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
* NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
* SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
* SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
* THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
* NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
* SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
* BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
* LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
* AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
* OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
* MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
* THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
* WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
* LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
* RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
* THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/***************************************************************************** 
 *
 * Filename:
 * ---------
 *   jam_msg_handler.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements J2ME message handler definition
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

#ifndef __J2ME_MSG_HANDLER_H
#define __J2ME_MSG_HANDLER_H

#include "jam_interface.h"
#ifndef JAL_JAM_INTERFACE_H
#error "should include jam_interface.h before jam_msg_handler.h"
#endif 
/*************************************************************************
 * Include Header Files
 *************************************************************************/
/* added for HTTP proxy setting */
#include "wapadp.h"
//#include "wap_ps_struct.h"
#include "profile_struct.h"
#include "MMI_features.h"

#define MIDS_NETWORK_PROF "mids_prof.txt"
#define TEMP_MIDS_NETWORK_PROF "t_mids_prof.txt"
#define MIDS_NETWORK_PROF_CRC "mids_prof_crc.txt"
#define HS_MIDS_TBL "hs_mids_table.txt"

#define MAX_PROF_LINE 200

#if (MMI_MAX_SIM_NUM == 1)
#define SIM_NUM 1
#elif (MMI_MAX_SIM_NUM == 2)
#define SIM_NUM 2
#elif (MMI_MAX_SIM_NUM == 3)
#define SIM_NUM 3
#elif (MMI_MAX_SIM_NUM == 4)
#define SIM_NUM 4
#endif

#ifndef __SUN_RI__
/*************************************************************************
 * Basic Structure and Definition
 *************************************************************************/
/* mids_list_struct */
typedef struct _mids_list_struct_t
{
    kal_uint32 mids_id;
    kal_wchar *mids_name;
    kal_wchar *storage_name;    
    kal_char *mids_icon;
    kal_uint16 mid_count;
    kal_uint8 mids_attributes;  /* attributes are in the mids_attributes_enum */
    kal_uint32 mids_size;
} mids_list_struct;

/* This is a structure that contains MIDlet icons, MIDlet names, and MIDlet IDs. */
/* mid_list_struct */
typedef struct _mid_list_struct_t
{
    kal_uint32 mid_id;
    kal_wchar *mid_name;
    kal_char *mid_icon;
} mid_list_struct;

/* This structure contains all the important fields of a MIDlet suite description file. */
/* mids_info_struct */
typedef struct _mids_info_struct_t
{
    kal_wchar *mids_name;
    kal_uint32 mids_size;
    kal_wchar *mids_version;
    kal_wchar *mids_vendor;
    kal_wchar *mids_description;
    kal_wchar *mids_webside;
    kal_bool mids_authorized;
    kal_wchar *mids_authorized_by;
    kal_wchar *mids_auto_start_connection;
    kal_wchar *mids_filename;
    kal_uint32 mids_mid_count;
    kal_wchar *mids_mid_name_list[1];
} mids_info_struct;

/*************************************************************************
 * Internal Data Structure
 *************************************************************************/

/*************************************************************************
 * Message Interface Structure
 *************************************************************************/
typedef struct _mmi_java_mids_getlist_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    /* Total mids count */
    kal_uint32 mids_count;
    /* actual list from index, and mids_list_count entry */
    kal_int32 start_indx;
    kal_int32 mids_list_count;
    jam_getlist_filter_struct *filter;
    mids_list_struct pmids_list[1];
} mmi_java_mids_getlist_cnf_struct;

/* Get MIDlet Suite/MIDlet List */
typedef struct _mmi_java_mids_getlist_req_struct_t
{
    LOCAL_PARA_HDR
    /* Game type - Java, Eureka, ...etc */
    kal_uint32 game_type;
    /* get list from index, and mids_list_count entry */
    kal_int32 start_indx;
    /* Current useless, because JVM try to get whole from assigned index */
    kal_int32 mids_list_count;
    /* Extend mode means Java unlock mutex instead send back confirm message to meet
       MMI functioncall based framework */
    kal_bool extend_mode;
    mmi_java_mids_getlist_cnf_struct **confirm_data_ptr;
    jam_getlist_filter_struct *filter;
} mmi_java_mids_getlist_req_struct;


typedef struct _mmi_java_mid_getlist_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    kal_uint32 mid_count;
    mid_list_struct pmid_list[1];
} mmi_java_mid_getlist_cnf_struct;

typedef struct _mmi_java_mid_getlist_req_struct_t
{
    LOCAL_PARA_HDR
    /* Game type - Java, Eureka, ...etc */
    kal_uint32 game_type;
    kal_uint32 mids_id;
    kal_bool extend_mode;
    mmi_java_mid_getlist_cnf_struct **confirm_data_ptr;
} mmi_java_mid_getlist_req_struct;

/* MIDlet Start/Stop notification */
/* modified by Justin */
/* from _mmi_java_mid_start_req_struct_t */
/* to mmi_java_mid_start_req_struct */
typedef struct _mmi_java_mid_start_req_struct_t
{
    LOCAL_PARA_HDR
    /* Game type - Java, Eureka, ...etc */
    kal_uint32 mids_id;
    kal_uint32 mid_id;
    kal_bool   is_launch_as_bg_running;
    kal_uint8 wap_prof_id;
    kal_char* storage_name;
    kal_wchar* mid_name;
} mmi_java_mid_start_req_struct;

typedef struct _java_java_mid_start_req_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    /* Game type - Java, Eureka, ...etc */
    kal_uint32 game_type;
    kal_uint32 mids_id;
    kal_int32 mid_id;
    kal_wchar *mid_name;
    kal_char *storage_name;
    kal_bool  is_launch_as_bg_running;
    kal_uint8 wap_prof_id;
} java_java_mid_start_req_struct;

typedef struct _mmi_java_mid_start_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    kal_uint32 vm_id;
    kal_bool   is_launch_as_bg_running;
} mmi_java_mid_start_cnf_struct;

typedef struct _mmi_java_mid_stop_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 exit_code;
    kal_int32 vm_id;
    kal_bool is_timealarm_push_start;
} mmi_java_mid_stop_ind_struct;
typedef struct _mmi_java_shutdown_all_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 exit_code;
} mmi_java_shutdown_all_ind_struct;

typedef struct _mmi_java_mid_stop_res_struct_t
{
    LOCAL_PARA_HDR
} mmi_java_mid_stop_res_struct;

/* Get MIDlet Suite information */
typedef struct _mmi_java_mids_getinfo_req_struct_t
{
    LOCAL_PARA_HDR
    /* Game type - Java, Eureka, ...etc */
    kal_uint32 mids_id;
} mmi_java_mids_getinfo_req_struct;

/* request for Get MIDlet Suite information for appmgr */
typedef struct _mmi_java_get_appmgr_info_req_struct_t
{
    LOCAL_PARA_HDR
    /* Game type - Java, Eureka, ...etc */
    kal_uint32 mids_id;
	kal_wchar *mids_name;   //[Name]  java app package name
    kal_uint32 mids_size;   //[Size] java app size
    kal_wchar *mids_version; //[Version] java app version
    kal_wchar *mids_vendor; //[Vendor] java app vendor
    kal_wchar *mids_description; //[Description] java app description
    kal_wchar *mids_website; //[Website] java app download website
    kal_bool mids_authorized; //[Connections] connections URL
    kal_bool can_be_uninstall; //can be uninstall or not
    kal_bool can_be_update; // can be update or not
    kal_uint8  storage_type;
} mmi_java_get_appmgr_info_req_struct;
/* modified by Justin to add mids_trusted, mids_setting */
/* , and mids_max_setting attributes */
typedef struct _mmi_java_mids_get_setting_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    kal_bool mids_trusted;
    kal_char* storage_name;
    mmi_setting_struct mids_setting;
    mmi_setting_struct mids_max_setting;
} mmi_java_mids_get_setting_cnf_struct;

typedef struct _mmi_java_mids_set_setting_req_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 mids_id;
    mmi_setting_struct mids_setting;
} mmi_java_mids_set_setting_req_struct;

typedef struct _mmi_java_mids_getinfo_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    mids_info_struct mids_info;
} mmi_java_mids_getinfo_cnf_struct;

/* Get/Set MIDlet Suite settings */
typedef struct _mmi_java_mids_get_setting_req_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    /* Game type - Java, Eureka, ...etc */
    kal_uint32 mids_id;
    kal_char* storage_name;
} mmi_java_mids_get_setting_req_struct;

/* modified by Justin. naming problem, */
/* _mmi_java_mids_set_setting_cnf_req_struct_t to */
/* _mmi_java_mids_set_setting_cnf_struct_t */
typedef struct _mmi_java_mids_set_setting_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
} mmi_java_mids_set_setting_cnf_struct;

/* added by Justin */
/* Update MIDlet Suite */
typedef struct _mmi_java_mids_update_req_struct_t
{
    LOCAL_PARA_HDR
    /* Game type - Java, Eureka, ...etc */
    kal_uint32 mids_id;
} mmi_java_mids_update_req_struct;

typedef struct _mmi_java_mids_update_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    kal_wchar *error_string;
    kal_uint32 download_error_code;
} mmi_java_mids_update_cnf_struct;

/* Remove MIDlet Suite */
typedef struct _mmi_java_mids_remove_req_struct_t
{
    LOCAL_PARA_HDR
    /* Game type - Java, Eureka, ...etc */
    kal_uint32 mids_id;
    kal_char* mids_storage_id;
} mmi_java_mids_remove_req_struct;

typedef struct _mmi_java_mids_remove_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    kal_char* mids_storage_id;
} mmi_java_mids_remove_cnf_struct;

/* modified by Justin to fit the naming in SAP */
typedef struct _mmi_java_mids_remove_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_char* storage_name;
    kal_wchar *confirm_msg;
} mmi_java_mids_remove_confirm_ind_struct;

typedef struct _mmi_java_mids_remove_res_struct_t
{
    LOCAL_PARA_HDR
    kal_bool confirm;
} mmi_java_mids_remove_confirm_res_struct;
/* package MIDlet Message */
/* Remove MIDlet Suite */
typedef struct _mmi_java_mids_package_req_struct_t
{
    LOCAL_PARA_HDR
    kal_wchar* file_path;
    kal_wchar* output_dir;
    kal_int32 mids_id;
    kal_wchar* mids_name;
    kal_int32 package_mode;
} mmi_java_mids_package_req_struct;

typedef struct _mmi_java_mids_package_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_int32 error_code;
    kal_wchar* file_path;
} mmi_java_mids_package_cnf_struct;


/* Install MIDlet Suite */
typedef struct _java_wap_install_mids_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_bool jad_file;
    kal_wchar *download_url;
    kal_wchar *file_path_name;
} java_wap_install_mids_ind_struct;

typedef struct _java_wap_install_mids_res_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
} java_wap_install_mids_res_struct;

typedef struct _mmi_java_install_mids_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_bool jad_file;
    kal_wchar *download_url;
    kal_wchar *file_path_name;
} mmi_java_install_mids_ind_struct;

typedef struct _mmi_java_install_mids_res_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
} mmi_java_install_mids_res_struct;

typedef struct _mmi_java_install_mids_req_struct_t
{
    LOCAL_PARA_HDR
    /* Game type - Java, Eureka, ...etc */
    kal_wchar *download_url;
    kal_wchar *jad_file_path;
    kal_wchar *jar_file_path;
} mmi_java_install_mids_req_struct;

/* error_string added by Justin */
typedef struct _mmi_java_install_mids_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    kal_int32 vm_id;
    kal_uint32 download_error_code;
    kal_int32 storage_drive;
    kal_uint32 need_storage_size;
    kal_char installed_drv;
    kal_bool need_lauch;
    kal_int32 mids_id;
    kal_wchar *drm_file_path;
    kal_int32 drm_serial;
    kal_bool acquire_right;
    kal_char* mids_storage_id;
    kal_wchar* mids_name;
    kal_wchar* mids_vendor;
    kal_char* mids_version;    
} mmi_java_install_mids_cnf_struct;

typedef struct _mmi_java_install_confirm_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_wchar *confirm_msg;
} mmi_java_install_confirm_ind_struct;

typedef struct _mmi_java_install_confirm_res_struct_t
{
    LOCAL_PARA_HDR
    kal_bool confirm;
} mmi_java_install_confirm_res_struct;

typedef struct _mmi_java_install_reset_rms_ind_struct_t
{
    LOCAL_PARA_HDR
} mmi_java_install_reset_rms_ind_struct;

typedef struct _mmi_java_install_reset_rms_res_struct_t
{
    LOCAL_PARA_HDR
    kal_bool confirm;
} mmi_java_install_reset_rms_res_struct;

typedef struct _java_local_install_req_struct_t
{
    LOCAL_PARA_HDR
    kal_bool is_force;
    /* Game type - Java, Eureka, ...etc */
    kal_uint32 game_type;
    kal_wchar *jad_file_name;
    kal_wchar *jar_file_name;
} java_local_install_req_struct;

typedef struct java_local_install_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
} java_local_install_cnf_struct;

typedef struct _java_wap_get_file_and_save_req_struct_t
{
    LOCAL_PARA_HDR
    kal_wchar *download_url;
    kal_wchar *save_file_path;
} java_wap_get_file_and_save_req_struct;

typedef struct _java_wap_get_file_and_save_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    kal_uint32 download_error_code;
} java_wap_get_file_and_save_cnf_struct;

typedef struct _mmi_wap_get_file_and_save_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 download_size;
    kal_uint32 total_size;
} mmi_wap_get_file_and_save_ind_struct;

typedef struct _mmi_wap_get_file_and_save_res_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 progress;
} mmi_wap_get_file_and_save_res_struct;

typedef struct _mmi_java_get_file_and_save_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    kal_uint32 download_error_code;
} mmi_java_get_file_and_save_ind_struct;

typedef struct _mmi_java_get_file_and_save_res_struct_t
{
    LOCAL_PARA_HDR
} mmi_java_get_file_and_save_res_struct;

typedef struct _mmi_java_get_file_and_save_progress_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 download_size;
    kal_uint32 total_size;
} mmi_java_get_file_and_save_progress_ind;

typedef struct _mmi_java_get_file_and_save_progress_res_struct_t
{
    LOCAL_PARA_HDR
} mmi_java_get_file_and_save_progress_res;

/* Abort */
typedef struct _mmi_java_abort_req_struct_t
{
    LOCAL_PARA_HDR
    kal_int32 vm_id;
} mmi_java_abort_req_struct;

typedef struct _mmi_java_abort_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
} mmi_java_abort_cnf_struct;

typedef struct _java_wap_abort_req_struct_t
{
    LOCAL_PARA_HDR
} java_wap_abort_req_struct;

typedef struct _java_wap_abort_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
} java_wap_abort_cnf_struct;

typedef struct _java_wap_post_data_req_struct_t
{
    LOCAL_PARA_HDR
    kal_wchar *save_file_path;
    kal_wchar *url;
    kal_char *content_type;
    kal_char *body;
    int body_size;
} java_wap_post_data_req_struct;

typedef struct _java_wap_post_data_cnf_struct_t
{
    LOCAL_PARA_HDR
    int error_code;
    int download_size;
    int total_size;
    int http_return_code;
    char *header;
} java_wap_post_data_cnf_struct;

/* TCK */
typedef struct _mmi_java_pushalarm_permission_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 java_mode;
    kal_bool execute;
} mmi_java_set_mode_req_struct;

typedef struct _mmi_java_set_mode_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    kal_int32 vm_id;
} mmi_java_set_mode_cnf_struct;
typedef struct _mmi_java_tck_result_struct_t
{
    LOCAL_PARA_HDR
    kal_int32 tck_result;
} mmi_java_tck_result_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 title_id;
    trusted_title_display_enum trusted_display;
    kal_int32 *chosen_id;
    kal_wchar *appendix;
} mmi_java_get_permission_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool user_confirm;
} mmi_java_get_permission_cnf_struct;

typedef struct {
    LOCAL_PARA_HDR
    kal_int32 current;    /* you can send in both in bytes */
    kal_int32 total;
    kal_wchar* midlet_name;
}mmi_java_show_percentage_ind_struct;
typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 size;  /* need how much storage space, send in bytes */
} mmi_java_get_install_drv_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool deleteAll;
    kal_char* storage_name;
} mmi_java_remove_mids_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    install_report_info_struct mids_report_info;
} mmi_java_preinstall_mids_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int16 drv;   /* <0 : user cancel */
} mmi_java_get_install_drv_res_struct;
#ifdef __MMI_JAVA_CATEGORY_SUPPORT__

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 category;   /* -1 : user cancel */
} mmi_java_get_install_category_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
} mmi_java_get_install_category_ind_struct;

#endif /*__MMI_JAVA_CATEGORY_SUPPORT__*/

/* Push and TimeAlarm */
typedef struct _mmi_java_timealarm_push_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
    kal_uint32 pushalarm_type;  /* For simplicity, 0 - timealarm, 1 - sms push */
    void *callback_entry;
    kal_char *mids_storage_name;
    kal_char *mid_class_name;
    kal_int32 mid_id;
    kal_bool close_dummy_group;
    kal_bool show_busy_popup;
} mmi_java_timealarm_push_ind_struct;


typedef struct _mmi_java_push_install_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 push_install_type;  /* For simplicity, 0 - timealarm, 1 - sms push */
    kal_wchar *drm_file_path;
} mmi_java_push_install_ind_struct;

typedef struct _mmi_java_check_push_mid_running_req_struct_t
{
        LOCAL_PARA_HDR
        kal_char *mid_storage_name;
		kal_int32 mid_id;
}mmi_java_check_push_mid_running_req_struct;

typedef enum
{
    JAM_MIDLET_STATUS_SUITE_NOT_LAUNCH = 1,
    JAM_MIDLET_STATUS_SUITE_LAUNCH_IN_FG = 2,
    JAM_MIDLET_STATUS_SUITE_LAUNCH_IN_BG = 4,    
    JAM_MIDLET_STATUS_SUITE_LAUNCH_BUT_MIDLET = 8,        
    JAM_MIDLET_STATUS_OTHERS_SUITE_LAUNCH_IN_FG = 16,        
    JAM_MIDLET_STATUS_VM_IS_SLOT_FULL = 32,    
    JAM_MIDLET_STATUS_END
} mmi_java_midlet_status_enum;

typedef struct _mmi_java_vm_status_element_struct_t
{
    char* storage;       
    char* name;
    kal_uint8 vm_id;    
               
}mmi_java_vm_status_element_struct;


typedef struct _mmi_java_check_push_mid_running_rsp_struct_t
{
        LOCAL_PARA_HDR
        kal_bool ret;/* true: running;false:not running */
        kal_uint8 result;
}mmi_java_check_push_mid_running_rsp_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 confirm_title;                       /* send STR_ID, must be defined in ref_list.txt */
    kal_uint16 confirm_image;                       /* only used in JAVA_CONFIRM_NOTIFICATION_CATEGORY, send image ID */
    java_get_confirm_enum confirm_enum;             /* refer to java_get_confirm_enum */
    java_get_confirm_category_enum window_category; /* refer to java_get_confirm_category_enum */
    kal_char *confirm_msg;
} mmi_java_get_confirm_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_bool confirm;
} mmi_java_get_confirm_res_struct;

#define MMI_JAVA_AUTH_LEN_USERNAME 31
#define MMI_JAVA_AUTH_LEN_PASSWORD 31

typedef struct
{
    LOCAL_PARA_HDR
} mmi_java_get_auth_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_wchar username[MMI_JAVA_AUTH_LEN_USERNAME];
    kal_wchar password[MMI_JAVA_AUTH_LEN_USERNAME];
} mmi_java_get_auth_res_struct;

/* messages for OGDR 5.0 security settings */
#ifdef OGDR_SECURITY_SETTING
typedef struct
{
    LOCAL_PARA_HDR
}mmi_java_get_domain_list_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 total_domain;
    kal_wchar domains[10][30];
    kal_int32 error_code;
}mmi_java_get_domain_list_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 domain_id;
}mmi_java_get_default_domain_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 domain_id;
    mmi_setting_struct default_setting;
    mmi_setting_struct max_setting;
    kal_int32 error_code;
}mmi_java_get_default_domain_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 domain_id;
    mmi_setting_struct default_setting;
}mmi_java_set_default_domain_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 error_code;
}mmi_java_set_default_domain_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR
}mmi_java_reset_default_domain_req_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 error_code;
}mmi_java_reset_default_domain_cnf_struct;
#endif
typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 error;
    kal_uint8 imsi[17];
}mmi_java_get_imsi_res_struct;
typedef struct
{
    LOCAL_PARA_HDR
    kal_int32   error;
    kal_char    mcc[10];    //MCC
    kal_char    mnc[10];    //MNC
    kal_char    lac[10];    //LAC
    kal_char    cell_id[10];//cell ID
    kal_uint8   nc_info_index; // index in rlc array to acquire the corresponding arfcn, bsic, rxlevel...
} mmi_java_get_lai_res_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int8   sim_id;
} mmi_java_get_imsi_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 value;
    kal_int32 number_of_items;      /* should be 0 now */
    kal_uint8** list_of_items;       /* shoule be NULL now */
} mmi_java_install_progress_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 vm_id;
} mmi_java_pause_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 vm_id;
} mmi_java_resume_ind_struct;
typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 vm_id;
} mmi_java_terminate_ind_struct;

typedef struct
{
    LOCAL_PARA_HDR
    kal_int32 vm_id;
    kal_int32 return_code;
    kal_bool is_timealarm_push_start;
    kal_bool is_tck;
}mmi_java_terminate_notify_struct;

/* TCK */
/*
 * typedef struct _mmi_java_pushalarm_permission_cnf_struct_t {
 * LOCAL_PARA_HDR
 * kal_uint32 java_mode;
 * kal_bool execute;
 * } mmi_java_set_mode_req_struct;
 */

/* wrapper */
//#define java_mmi_timealarm_push_ind_struct mmi_java_timealarm_push_ind_struct
//#define java_mmi_timealarm_push_res_struct mmi_java_timealarm_push_res_struct

typedef struct _java_wap_data_account_ind_struct
{
    LOCAL_PARA_HDR
    int data_account;
} java_wap_data_account_ind_struct;

typedef struct _mmi_java_show_alert_user_dialog_req_struct
{
    LOCAL_PARA_HDR
    char message[2]; /* this pointer should not be free */
} mmi_java_show_alert_user_dialog_req_struct;

typedef struct _mmi_wap_abort_req_struct_t
{
    LOCAL_PARA_HDR
} mmi_wap_abort_req_struct;

typedef struct _mmi_wap_abort_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 error_code;
    kal_bool is_JAD_file;
    kal_bool is_JAR_file;
} mmi_wap_abort_cnf_struct;

typedef struct _mma_event_callback_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 aud_id;
    kal_uint32 seq_id;
    int handle;
    int event;
} mma_event_callback_struct;

typedef struct _eureka_start_req_struct_t
{
    LOCAL_PARA_HDR
    kal_char* ege_command;
} eureka_start_req_struct;
/* home screen get list cnf msg structure */
typedef struct _mmi_java_mids_get_home_screen_cnf_struct_t
{
    kal_uint32 error_code;
    kal_int32 mids_list_count;
    mids_list_struct pmids_list[1];
} mmi_java_mids_get_home_screen_cnf_struct;

/* home screen get list req msg structure */
typedef struct _mmi_java_mids_get_home_screen_req_struct_t
{
    mmi_java_mids_get_home_screen_cnf_struct **confirm_data_ptr;
    
} mmi_java_mids_get_home_screen_req_struct;

typedef struct _mmi_java_mids_get_id_by_storage_req_struct_t
{
    kal_char *mids_storage;
    
} mmi_java_mids_get_id_by_storage_req_struct;

typedef struct _mmi_java_mids_get_id_by_storage_cnf_struct_t
{
    LOCAL_PARA_HDR 
    kal_uint32 mids_id;
    kal_char *mids_storage;    
} mmi_java_mids_get_id_by_storage_cnf_struct;

typedef struct _mmi_java_mids_get_network_profile_req_struct_t
{
    kal_uint8	ref_count;
    kal_uint16	msg_len;
    //kal_wchar *suiteName; 
    //kal_wchar *vendor;    
    kal_wchar *storage;
} mmi_java_mids_get_network_profile_req_struct;

typedef struct _mmi_java_mids_get_network_profile_cnf_struct_t
{
    kal_uint8	ref_count;
    kal_uint16	msg_len;
    kal_int32 sim; 
    kal_wchar profs[SIM_NUM][20];    
    
} mmi_java_mids_get_network_profile_cnf_struct;

typedef struct _mmi_java_mids_put_network_profile_req_struct_t
{
    kal_uint8	ref_count;
    kal_uint16	msg_len;
    mmi_java_mids_np_op_type_enum mode;
    kal_wchar *storage;    
    //kal_wchar *suiteName; 
    //kal_wchar *vendor; 
    kal_int32 sim; 
    kal_uint16 profs[SIM_NUM];  
    
} mmi_java_mids_put_network_profile_req_struct;

typedef struct _mmi_java_mids_put_network_profile_cnf_struct_t
{
    kal_uint8	ref_count;
    kal_uint16	msg_len;
    kal_bool set_result;
    
} mmi_java_mids_put_network_profile_cnf_struct;

typedef struct _mmi_java_mids_hs_np_delete_notify_cnf_struct_t
{
    kal_uint8	ref_count;
    kal_uint16	msg_len;
    kal_int16 id;
    
} mmi_java_mids_hs_np_delete_notify_cnf_struct;
typedef struct _mmi_java_post_notify_start_req_struct_t
{
    LOCAL_PARA_HDR
        
} mmi_java_post_notify_start_req_struct;

typedef struct _mmi_java_post_notify_end_req_struct_t
{
    LOCAL_PARA_HDR
    kal_bool success;
        
} mmi_java_post_notify_end_req_struct;

typedef struct _mmi_java_waiting_right_start_req_struct_t
{
    LOCAL_PARA_HDR
        
} mmi_java_waiting_right_start_req_struct;

typedef struct _mmi_java_waiting_right_end_req_struct_t
{
    LOCAL_PARA_HDR
    kal_bool success;
        
} mmi_java_waiting_right_end_req_struct;

typedef struct _mmi_java_mids_reset_domain_setting_req_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 game_type;
    kal_uint32 mids_id;
    kal_char* storage;
} mmi_java_mids_reset_domain_setting_req_struct;

typedef struct _mmi_java_mids_reset_domain_setting_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_bool success;
    
} mmi_java_mids_reset_domain_setting_cnf_struct;

typedef struct _mmi_java_change_domain_req_struct_t{
    LOCAL_PARA_HDR
    kal_uint32 total_domain;
    kal_bool status[10];
}mmi_java_change_domain_req_struct;

typedef struct _mmi_java_change_domain_cnf_struct_t{
    LOCAL_PARA_HDR
    kal_int32 error_code;
}mmi_java_change_domain_cnf_struct;

typedef struct _mmi_java_get_domain_status_req_struct_t{
    LOCAL_PARA_HDR
}mmi_java_get_domain_status_req_struct;

typedef struct _mmi_java_get_domain_status_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 total_count;
    kal_bool domains_status[10];
    kal_uint16 domains[10];    
}mmi_java_get_domain_status_cnf_struct;

/************************************************************************
  * Java autoverification begin
  ************************************************************************/
typedef struct _jam_jvm_mid_start_req_struct_t
{
    LOCAL_PARA_HDR
    kal_int32 mids_id; 
    kal_wchar* mid_name_str;    
#if defined(__MVM__)
    kal_int32 mid_id; 
    kal_int32 vm_id;
#endif /* __MVM__  */
}jam_jvm_mid_start_req_struct;

typedef struct _jam_jvm_mid_start_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_int32 returnCode;
    kal_wchar *mid_name_str;
}jam_jvm_mid_start_cnf_struct;

typedef struct _jam_jvm_mid_stop_req_struct_t
{
    LOCAL_PARA_HDR
    kal_int32 vm_id;
    kal_int32 returnCode;
    kal_wchar *mid_name_str;
}jam_jvm_mid_stop_req_struct;
typedef struct _jam_jvm_shutdown_all_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_int32 returnCode;
}jam_jvm_shutdown_all_ind_struct;
typedef struct _jam_jvm_tck_stop_req_struct_t
{
    LOCAL_PARA_HDR
    kal_int32 returnCode;
    kal_int32 vm_id;
}jam_jvm_tck_stop_req_struct;
typedef struct _jam_jvm_tck_start_req_struct_t
{
    LOCAL_PARA_HDR
    java_mode_enum tck_mode; 
    kal_bool to_execute;   
    kal_int32 vm_id;
}jam_jvm_tck_start_req_struct;

typedef struct _jam_jvm_general_assist_req_struct_t
{
    LOCAL_PARA_HDR
    kal_int32 index;
    kal_char input[256];
    kal_int32 input_len;
}jam_jvm_general_assist_req_struct;

typedef struct _jam_jvm_general_assist_cnf_struct_t
{
    LOCAL_PARA_HDR
    kal_int32 returnCode;
    void* input;
}jam_jvm_general_assist_cnf_struct;
#ifdef __JAVA_MANAGER__

#define  JAVA_COMMAND_STRING_MAX_LENGTH  (320)

typedef struct _tst_mmi_java_cmd_req_struct_t
{
   kal_uint8   ref_count;
   kal_uint16  params_len;
   kal_uint8   index;
   kal_int8   string[JAVA_COMMAND_STRING_MAX_LENGTH];
}
tst_mmi_java_cmd_req_struct;

typedef struct _mmi_l4c_java_cmd_rsp_struct_t
{
    LOCAL_PARA_HDR
    kal_uint8  errorCode;
    kal_int32 intValue;
    kal_uint8  stringValue[128];
}
mmi_l4c_java_cmd_rsp_struct;

#define JAVA_COMMAND_AT_MAX_LENGTH (128)
typedef struct _java_l4c_inject_at_cmd_struct_t
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   index;
    kal_uint8   string[JAVA_COMMAND_AT_MAX_LENGTH];
}
java_l4c_inject_at_cmd_struct;
typedef struct _java_mmi_cmd_query_rsp_struct_t
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_int8    error_code;
    kal_int32  mids_idx;
    kal_uint8  mids_attrib;
}
java_mmi_cmd_query_rsp_struct;
typedef struct _mmi_java_cmd_query_req_struct_t
{
    kal_uint8   ref_count;
    kal_uint16  msg_len;
    kal_uint8   game_type;
    kal_int32    mids_index;
    kal_wchar* mids_name;
    /* Extend mode means Java unlock mutex instead send back confirm message to meet 
       MMI functioncall based framework */  
    kal_bool extend_mode;
    java_mmi_cmd_query_rsp_struct **confirm_data_ptr;
}
mmi_java_cmd_query_req_struct;

typedef struct _mmi_l4c_ota_status_ind_struct_t
{
    LOCAL_PARA_HDR
    kal_uint8    error_code;
    kal_int32    status_code;/*the ota status report code : 900~912*/
}
mmi_l4c_ota_status_ind_struct;
#endif
/************************************************************************
  * Java autoverification end
  ************************************************************************/

/************************************************************************
  * Java network profile start
  ************************************************************************/
typedef struct _mmi_java_nw_get_global_setting_req_struct_t
    {
        LOCAL_PARA_HDR
        jam_mids_network_struct *network[SIM_NUM];
} mmi_java_nw_get_global_setting_req_struct;

    typedef struct _mmi_java_nw_get_global_setting_rsp_struct_t
    {
        LOCAL_PARA_HDR
        kal_int8 error_code;
} mmi_java_nw_get_global_setting_rsp_struct;


typedef struct _mmi_java_nw_get_local_setting_req_struct_t
{
        LOCAL_PARA_HDR
        jam_mids_network_struct *network[SIM_NUM];
        kal_char* storage;
} mmi_java_nw_get_local_setting_req_struct;


typedef struct _mmi_java_nw_get_local_setting_rsp_struct_t
{
    LOCAL_PARA_HDR
    kal_char* storage;
    kal_int8 error_code;
} mmi_java_nw_get_local_setting_rsp_struct;

typedef struct _mmi_java_nw_set_global_setting_req_struct_t
{
    LOCAL_PARA_HDR
    jam_mids_network_struct    *network[SIM_NUM];
    } mmi_java_nw_set_global_setting_req_struct;

typedef struct _mmi_java_nw_set_global_setting_rsp_struct_t
{
    LOCAL_PARA_HDR
    kal_int8 error_code ;
    } mmi_java_nw_set_global_setting_rsp_struct;


typedef struct _mmi_java_nw_set_local_setting_rsp_struct_t
{
    LOCAL_PARA_HDR
    kal_char *storage ;        
    kal_int8 error_code ;
} mmi_java_nw_set_local_setting_rsp_struct;

typedef struct _mmi_java_nw_set_local_setting_req_struct_t
{
    LOCAL_PARA_HDR
    jam_mids_network_struct    *network[SIM_NUM];
    kal_char *storage ;
} mmi_java_nw_set_local_setting_req_struct;


typedef struct _mmi_java_nw_update_setting_req_struct_t
{
    LOCAL_PARA_HDR
    kal_int32 vm_id;
}
mmi_java_nw_update_setting_req_struct;

typedef struct _jam_is_network_usable_struct_t
{
    LOCAL_PARA_HDR
    kal_bool* is_useable;
}
jam_is_network_usable_struct;

typedef struct _mmi_java_set_audio_volume_struct_t
{
    LOCAL_PARA_HDR
    kal_uint8 volume;
}
mmi_java_set_audio_volume_struct;

/************************************************************************
  * Java network profile end
  ************************************************************************/
typedef struct _mmi_java_get_running_mids_rsp_struct_t
{
    LOCAL_PARA_HDR
    kal_uint32 session_id;
}mmi_java_get_running_mids_rsp_struct;
typedef struct _mmi_running_mids_struct_t
{
    kal_wchar * mid_name;
    kal_int32 vm_id;
}mmi_running_mid;
typedef struct _mmi_java_get_running_mids_req_struct_t
{
    LOCAL_PARA_HDR
    mmi_running_mid**  running_mid_list;
    kal_int32 err_code;
    kal_int32* count;
}mmi_java_get_running_mids_req_struct;
/************************************************************************
  * Java plug in/out tcard begin
  ************************************************************************/
  typedef struct _mmi_java_plug_in_out_tcard_struct_t
{
    LOCAL_PARA_HDR
    kal_uint16 evt_id; /* Event id */                                    
}mmi_java_plug_in_out_tcard_struct;
/************************************************************************
  * Java plug in/out tcard end
  ************************************************************************/


/*************************************************************************
 * Global Declaration
 *************************************************************************/
extern mids_listfile_struct *saved_mids_listfile_ptr;

extern kal_bool is_in_critical_path;

/*java autoverification begin*/
#ifdef __JAVA_MANAGER__
extern void tst_mmi_java_cmd_req_handler(ilm_struct *ilm_ptr);
extern void mmi_java_cmd_query_req_handler (ilm_struct *ilm_ptr);
extern void mmi_java_send_cmd_query_rsp(ilm_struct * ilm_ptr);
#endif
/*java autoverification end*/

/* Get MIDlet Suite/MIDlet List */
extern void jam_mids_getlist_req_handler(ilm_struct *ilm_ptr);
extern void jam_mid_getlist_req_handler(ilm_struct *ilm_ptr);

/* MIDlet Start/Stop notification */
extern void jam_mid_start_req_handler(ilm_struct *ilm_ptr);
extern void jam_mid_stop_res_handler(ilm_struct *ilm_ptr);

/* Get MIDlet Suite information */
extern void jam_mids_getinfo_req_handler(ilm_struct *ilm_ptr);
extern void mids_setsetting_req_handler(ilm_struct *ilm_ptr);

/* Get/Set MIDlet Suite settings */
extern void jam_mids_get_setting_req_handler(ilm_struct *ilm_ptr);
extern void jam_mids_set_setting_req_handler(ilm_struct *ilm_ptr);

/* Update MIDlet Suite */
extern void jam_mids_update_req_handler(ilm_struct *ilm_ptr);

/* Remove MIDlet Suite */
extern void jam_mids_remove_req_handler(ilm_struct *ilm_ptr);

/* Install MIDlet Suite */
extern void jam_install_mids_req_handler(ilm_struct *ilm_ptr);
extern void mids_mmi_install_cnf_res_handler(ilm_struct *ilm_ptr);
extern void wap_getfileandsave_ind_handler(ilm_struct *ilm_ptr);
extern void wap_getfileandsave_cnf_handler(ilm_struct *ilm_ptr);
extern void mmi_getfileandsave_res_handler(ilm_struct *ilm_ptr);
extern void mmi_install_reset_rms_res_handler(ilm_struct *ilm_ptr);
extern void wap_post_data_cnf_handler(ilm_struct *ilm_ptr);

/* Local install */
extern void java_local_install_req_handler(ilm_struct *ilm_ptr);

/* Abort */
extern void jam_abort_req_handler(ilm_struct *ilm_ptr);
extern void jam_abort_cnf_handler(ilm_struct *ilm_ptr);
extern void jam_delete_menu_abort_req_handler(ilm_struct *ilm_ptr);

/* PUSH */
extern void jam_mmiapi_sms_ind_handler(ilm_struct *ilm_ptr);
extern void jam_timealarm_push_res_handler(ilm_struct *ilm_ptr);
extern void jam_appmms_new_mms_ind_handler(ilm_struct *ilm_ptr);

/* TCK */
extern void mmi_java_set_mode_req_handler(ilm_struct *ilm_ptr);
extern void mmi_java_set_mode_cnf_handler(kal_uint32 error_code, kal_int32 tck_result);

/* Security setting for OGDR 5.0 */
extern void jam_get_domain_list_req(ilm_struct *ilm_ptr);
extern void jam_get_default_domain_req(ilm_struct *ilm_ptr);
extern void jam_set_default_domain_req(ilm_struct *ilm_ptr);
extern void jam_reset_default_domain_req(ilm_struct *ilm_ptr);

/* restore factory mode */
extern void jam_restore_factory_mode_req_handler(ilm_struct *ilm_ptr);
/* package midlet message */
extern void jam_mids_package_req_handler(ilm_struct *ilm_ptr);
/* between jam and jvm */
extern void jam_jvm_mid_start_cnf_handler(ilm_struct *ilm_ptr);
extern void jam_jvm_mid_stop_req_handler(ilm_struct *ilm_ptr);
extern void jam_jvm_shutdown_all_ind_handler(ilm_struct *ilm_ptr);
extern void jam_jvm_tck_start_cnf_handler(ilm_struct *ilm_ptr);
extern void jam_jvm_tck_stop_req_handler(ilm_struct *ilm_ptr);
extern void jam_jvm_general_assist_req_handler(ilm_struct *ilm_ptr);
extern void jam_mvm_get_running_mids_list_req_hdlr(ilm_struct *ilm_ptr);

extern void j2me_lcd_mutex_lock(void);
extern void j2me_lcd_mutex_unlock(void);

extern kal_bool j2me_task_general_msg_handler(ilm_struct *ilm_ptr);

/* event callback handler */
extern void jma_audio_event_callback_handler(kal_int32 vm_id, int handle, int event, int aud_id, int seq_id);
extern void jam_send_mma_event_callback(int handle, int event, int aud_id, int seq_id);

/* added by Justin */
extern wap_get_prof_content_rsp_struct wap_prof;
extern kal_int32 get_next_event(
                    kal_bool wait_forever,
                    msg_type state,
                    kal_bool clean_msg,
                    kal_bool must_match,
                    kal_bool *abort_msg_received);
extern kal_int32 jvm_send_and_get_next_event(
                    ilm_struct *send_ilm,
                    kal_bool wait_forever,
                    msg_type state,
                    kal_bool clean_msg,
                    kal_bool must_match,
                    kal_bool *abort_msg_received);
extern kal_wchar *jam_get_string_by_error_code(kal_int32 error_code);
extern kal_int32 removeSuiteFromMIDSLIST( kal_char *storageName);
extern kal_bool jam_vm_is_busy(void);
extern kal_bool jam_is_busy(void);

extern jam_task_state g_jam_task_state;
extern kal_bool jam_vm_task_ready(void);

extern kal_wchar *get_jar_url(kal_wchar *jad_file_name, kal_int32 *error_code);
extern kal_bool get_ca_from_wap(void);
extern void free_jam_ca_list(void);

extern kal_bool g_jam_is_jvm_in_busy;
extern kal_wchar *install_download_url;
extern kal_uint32 download_error_code;
extern kal_uint32 J2ME_active_nw_acc_id[MAX_VM_INSTANCE_NUM];

extern install_update_struct install_update_status;
extern kal_uint32 java_total_used_space;
extern char g_jam_is_op_715;
extern kal_bool pauseThread;
extern void get_disk_info(void);
extern kal_bool j2me_in_tck_mode;
extern void jam_mids_get_network_profile_req_handler(ilm_struct *ilm_ptr);
extern void jam_mids_put_network_profile_req_handler(ilm_struct *ilm_ptr);
extern kal_uint8 jam_get_current_running_mids_prof(void);
extern kal_int32 jam_get_current_running_mids_sim(void);
extern kal_bool jam_mids_get_netwotk_profile(kal_wchar* storage, kal_wchar* sim, kal_wchar profs[][20]);
extern kal_bool jam_mids_put_netwotk_profile(mmi_java_mids_np_op_type_enum mode,kal_wchar* storage, kal_int32 sim, kal_uint16* profs);
extern kal_bool jam_mids_np_crc_check(void);
extern void jam_mids_np_reset(void);
#ifdef __MMI_OP11_HOMESCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
extern kal_int32 jam_get_mids_domain(mids_list_info_struct* mids_info_ptr);
extern kal_int32 jam_mids_get_default_setting( jam_mids_setting_struct *get_setting_ptr, kal_int32 mids_id, mids_list_info_struct *mids_info_ptr);
extern kal_int32 jam_set_domain_status( kal_uint32 total_domain, kal_bool on[DOMAIN_MAX_COUNT]);
extern void jam_get_domain_status( kal_uint32* total_count, kal_bool domains_status[DOMAIN_MAX_COUNT], kal_wchar *domain_name[DOMAIN_MAX_COUNT]);

#ifdef OGDR_SECURITY_SETTING
extern void jam_mids_reset_domain_setting_hdlr(ilm_struct *ilm_ptr);
extern void jam_set_domain_status_req(ilm_struct *ilm_ptr);
extern void jam_get_domain_status_req(ilm_struct *ilm_ptr);
#endif

extern void jam_getlist_detect_response(ilm_struct *ilm_ptr);
extern void jam_check_is_running_mids(ilm_struct *ilm_ptr);

extern void jam_internal_mid_start_req_terminate_notify_handler(ilm_struct *ilm_ptr);

#define TRANS_INTVALUE(a)  \
   ((((a)&0xFF)<<24) + (((a>>8)&0xFF)<<16) + (((a>>16)&0xFF)<<8) + (((a>>24)&0xFF)))

/* moved by Justin */
#define check_incoming_call_and_block()  \
      while(mmi_java_need_block_msg()) \
         kal_sleep_task(10)

/* this definition enables Pause/Resume mechanism */
#if (!defined(J2ME_SLIM_MEMORY_SUPPORT)&&!defined(__MVM__))
#define J2ME_SUPPORT_PAUSE
#endif


#define jam_parse_midslistfile (jam_call_back_functions.jam_get_list)

#endif /* __SUN_RI__ */ 

typedef struct _push_fail_insufficient_mem_t
{
    java_java_mid_start_req_struct*  req;
    struct _push_fail_insufficient_mem_t * next;
} push_fail_insufficient_mem_struct;

extern kal_bool jam_get_g_jam_exit_by_asm(void);
extern kal_bool jam_is_network_service_available(void);

#ifdef J2ME_SLIM_MEMORY_SUPPORT
// this declaration just for temp solution
extern void *jam_wap_mem_alloc(kal_int32 *ret_size);
extern void  jam_wap_mem_free(void *memory);
#endif

#ifdef J2ME_SUPPORT_BACKGROUND
extern kal_bool jam_asm_memory_pool_prepared(void);
#endif
extern kal_bool jam_mvm_disable_vm_support_bg(kal_int32 vm_id);
extern kal_bool jam_mvm_is_vm_support_disable_bg(kal_int32 vm_id);
extern void jam_plug_in_out_tcard_handler(ilm_struct *ilm_ptr);


#endif /* __J2ME_MSG_HANDLER_H */ 

