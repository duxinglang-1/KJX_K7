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
*  MREAppMgrSrvGprot.h
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  Interface of MRE application manager service.
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef __MRE_APPMGR_SRV_GPROT_H__
#define __MRE_APPMGR_SRV_GPROT_H__

/****************************************************************************
* Include
****************************************************************************/
#include "MMIDataType.h"
#include "AppMgrSrvGprot.h"
#include "FileMgrSrvGProt.h"
#include "app_datetime.h"
#include "vmswitch.h"
#include "PnSrvGprot.h"
#include "mmi_res_range_def.h"
#include "custom_launcher_config.h"
#include "custom_screen_lock_config.h"
#include "custom_widget_config.h"
#include "custom_wallpaper_config.h"
/* DOM-NOT_FOR_SDK-BEGIN */
/****************************************************************************
* Typedef
****************************************************************************/

#define SRV_MRE_APPMGR_MRE_FOLDER L"z:\\@mre"
//#define SRV_MRE_APPMGR_APP_FOLDER L"z:\\@mre\\app\\"
//#if (defined(__PLUTO_MMI_PACKAGE__))&&(  !defined(__MMI_FTE_SUPPORT__))
#define SRV_MRE_APPMGR_IMG_FOLDER L":\\mre\\image\\"
#define SRV_MRE_APPMGR_IMG_FIRST_FOLDER L":\\mre\\"
//#else
//#define SRV_MRE_APPMGR_IMG_FOLDER L"z:\\@mre\\image\\"
//#endif
#define SRV_MRE_APPMGR_MAP_FOLDER L"z:\\@mre\\map\\"
#define SRV_MRE_APPMGR_MAP_FILE L"z:\\@mre\\map\\idmapname"
#define SRV_MRE_APPMGR_RESTORE_FACTORY_FILE L"z:\\@mre\\map\\restore"

#define SRV_MRE_APPMGR_PUSH_FOLDER L"z:\\@mre\\push\\"
#define SRV_MRE_APPMGR_PRELOAD_DRV SRV_FMGR_CARD_DRV
#define SRV_MRE_APPMGR_PHONE_DRV  SRV_FMGR_PHONE_DRV
#define SRV_MRE_APPMGR_PRELOAD_FOLDER L":\\mre\\"
#define SRV_MRE_APPMGR_PRELOAD_FILE  L"preinstall.txt"
#define SRV_MRE_APPMGR_PRELOAD_FILE_RESULT  L"t_preinstall_result.txt"
#define SRV_MRE_APPMGR_PATH_SIZE (14+MMI_APP_NAME_MAX_LEN)
#define SRV_MRE_APPMGR_SEPCHAR L"."
#define SRV_MRE_APPMGR_IMG_POSTFIX L".img"
#define SRV_MRE_APPMGR_PBM_POSTFIX L".pbm"
#define SRV_MRE_APPMGR_AB2_POSTFIX L".ab2"
#define SRV_MRE_APPMGR_FILEPATH_LEN (SRV_FMGR_PATH_MAX_LEN + 1)
#define SRV_MRE_APPMGR_ID_PREFIX L"mre."
#define SRV_MRE_APPMGR_SHORTCUT_ID_PREFIX L"mre.shortcut."
#define SRV_MRE_APPMGR_DEFAULT_DEVELOPER L"unknown"
#define SRV_MRE_APPMGR_DEVELOPER_NAME_LEN 20//10
#define SRV_MRE_APPMGR_DEVELOPER_NAME_LEN_SAVE 30
#define SRV_MRE_APPMGR_TEL_NUM_LEN 20
#define SRV_MRE_APPMGR_APP_NAME_LEN 15
#define SRV_MRE_APPMGR_MAX_ROM_PATH_LEN 18
#define SRV_MRE_APPMGR_INSTALLED_LAUNCHER_MAX  CUSTOM_LAUNCHER_MRE_MAX_NUM
#define SRV_MRE_APPMGR_INSTALLED_SCREEN_LOCK_MAX  CUSTOM_SCREEN_LOCK_MRE_MAX_NUM
#define SRV_MRE_APPMGR_INSTALLED_WIDGET_MAX  CUSTOM_WIDGET_MRE_MAX_NUM
#define SRV_MRE_APPMGR_INSTALLED_WALLPAPER_MAX  CUSTOM_WALLPAPER_MRE_MAX_NUM
#ifndef __MRE_CONTENT_NUMBER__
#define __MRE_CONTENT_NUMBER__  32
#endif
#define SRV_MRE_APPMGR_INSTALLED_APP_MAX   (__MRE_CONTENT_NUMBER__+SRV_MRE_APPMGR_INSTALLED_LAUNCHER_MAX+SRV_MRE_APPMGR_INSTALLED_SCREEN_LOCK_MAX + SRV_MRE_APPMGR_INSTALLED_WIDGET_MAX + SRV_MRE_APPMGR_INSTALLED_WALLPAPER_MAX)

#if defined(__COSMOS_MMI_PACKAGE__)||defined(__MMI_APP_MANAGER_SUPPORT__)
#define SRV_MRE_APPMGR_INSTALLED_PUSH_MAX  16
#else 
#define SRV_MRE_APPMGR_INSTALLED_PUSH_MAX  10
#endif

#define SRV_MRE_APPMGR_FILEPATH_LEN (SRV_FMGR_PATH_MAX_LEN + 1)
#define MMI_PNS_SENDERID_LEN 37
#define MMI_PNS_MAX_MSGBODY_SIZE 257

#define SRV_MRE_APPMGR_ID_BASE MRE_APPMGR_BASE
#define SRV_MRE_APPMGR_ID_MAX MRE_APPMGR_BASE_MAX
#ifndef MRE_PUSH_MAX_PAYLOAD
#define MRE_PUSH_MAX_PAYLOAD 4
#endif

#define FORMAT_MRE_LEN 8
#define CURRENT_MRE_VERSION "MRE0000"

#define SRV_MRE_APPMGR_ROM_UPDATE_APP_FLAG               (0x1)
#define SRV_MRE_APPMGR_SHORTCUT_UPDATE_APP_FLAG    (0x2)
//#ifdef WIN32
//#define SRV_MRE_APPMGR_SEARCH_PATTERN L"*.dll"
//#else
#define SRV_MRE_APPMGR_SEARCH_PATTERN L"*.vxp"
//#endif
#define SRV_APPMGR_INSTALLED_WIDGET_PACKAGE_FLAG_TYPE       (0x8001) /* mre widget app */
#define SRV_APPMGR_INSTALLED_WALLPAPER_PACKAGE_FLAG_TYPE       (0x8002) /* mre wallpaper app */
#define SRV_APPMGR_INSTALLED_LAUNCHER_PACKAGE_FLAG_TYPE       (0x8004) /* mre launcher app */
#define SRV_APPMGR_INSTALLED_SCRLOCK_PACKAGE_FLAG_TYPE       (0x8008) /* mre screen lock app */

#define SRV_APPMGR_INSTALLED_VSP_FLAG_TYPE    (0x8010)
#define SRV_APPMGR_INSTALLED_VPP_PACKAGE_FLAG_TYPE \
    (SRV_APPMGR_INSTALLED_WIDGET_PACKAGE_FLAG_TYPE |\
    SRV_APPMGR_INSTALLED_WALLPAPER_PACKAGE_FLAG_TYPE |\
    SRV_APPMGR_INSTALLED_LAUNCHER_PACKAGE_FLAG_TYPE |\
    SRV_APPMGR_INSTALLED_SCRLOCK_PACKAGE_FLAG_TYPE)

/****************************************************************************
* Typedef
****************************************************************************/
typedef enum
{
    SRV_MRE_APPMGR_APP_TYPE_UNKNOWN = 0,    /* UNKNOWN */
    SRV_MRE_APPMGR_APP_TYPE_DOWNLOAD = 0x0001,       /* dwonload from server */
    SRV_MRE_APPMGR_APP_TYPE_ROM = 0x0002,            /* build-in app */
    SRV_MRE_APPMGR_APP_TYPE_LOCAL_INSTALL = 0x0004,  /* install from local */
    SRV_MRE_APPMGR_APP_TYPE_SHORTCUT = 0x0008,       /* shortcut app */
    SRV_MRE_APPMGR_APP_TYPE_ROM_VPP = 0x0010, /*ROM VPP*/

    SRV_MRE_APPMGR_APP_TYPE_VXP = 0x1000,       /*vxp */
    SRV_MRE_APPMGR_APP_TYPE_SERVICE = 0x1001,       /*vsp */    
    SRV_MRE_APPMGR_APP_TYPE_VPP = 0x2000,       /*vpp */
    SRV_MRE_APPMGR_APP_TYPE_WIDGET = 0x2001,   /*widget app */
    SRV_MRE_APPMGR_APP_TYPE_WALLPAPER = 0x2002,   /*wallpaper app */
    SRV_MRE_APPMGR_APP_TYPE_LAUNCHER = 0x2004,   /*widget app */
    SRV_MRE_APPMGR_APP_TYPE_SCRLOCK = 0x2008,   /*wallpaper app */
    SRV_MRE_APPMGR_APP_TYPE_OTHERS = 0x2100,
    SRV_MRE_APPMGR_APP_TYPE_END_OF_ENUM
} srv_mre_appmgr_app_type_enum;

typedef struct
{
    WCHAR * app_folder;
    WCHAR * app_package_name_prefix;
    srv_mre_appmgr_app_type_enum app_type;
}srv_mre_appmgr_app_package_name_prefix;

// Application storage position type 

typedef enum
{
    SRV_MRE_APPMGR_APP_POSITION_UNKNOWN = 0,     //UNKNOWN 
    SRV_MRE_APPMGR_APP_POSITION_PHONE,          // Phone 
    SRV_MRE_APPMGR_APP_POSITION_CARD,           // Memory card
    SRV_MRE_APPMGR_APP_POSITION_ROM,            //build-in app 
    SRV_MRE_APPMGR_APP_POSITION_END_OF_ENUM
} srv_mre_appmgr_app_storage_position_enum;
/*mark this for mreappmgrsrv.c: download related features is phase out

typedef enum
{
SRV_MRE_APPMGR_CHECK_UPDATE_YES = 0,
SRV_MRE_APPMGR_CHECK_UPDATE_NO,
SRV_MRE_APPMGR_CHECK_UPDATE_FAIL,
SRV_MRE_APPMGR_CHECK_UPDATE_END_OF_ENUM
} srv_mre_appmgr_check_update_state_enum;
typedef enum
{
SRV_MRE_APPMGR_UPDATE_SUCCESS = 0,
SRV_MRE_APPMGR_UPDATE_FAIL,
SRV_MRE_APPMGR_UPDATE_END_OF_ENUM
} srv_mre_appmgr_update_state_enum;


// Before update an application, you should get update state by this callback 
typedef void (*srv_mre_appmgr_app_update_check_cb_t) (U32 appid, srv_mre_appmgr_check_update_state_enum state,
U32 filesize, U16 *filename);


//Update callback 
typedef void (*srv_mre_appmgr_app_update_cb_t) (U32 appid, srv_mre_appmgr_update_state_enum state, void *user_data);

//Before start a download, you should get app info by this callback 
typedef enum
{
SRV_MRE_APPMGR_DOWNLOAD_GETINFO_SUCCESS = 0,
SRV_MRE_APPMGR_DOWNLOAD_GETINFO_FAIL,
SRV_MRE_APPMGR_DOWNLOAD_GETINFO_END_OF_ENUM
} srv_mre_appmgr_download_getinfo_state_enum;
typedef void (*srv_mre_appmgr_download_getinfo_cb_t) (U32 app_id, srv_mre_appmgr_download_getinfo_state_enum state,
U32 file_size, U16 *file_name);

// When start a download, you can get download info by this callback 
typedef enum
{
SRV_MRE_APPMGR_DOWNLOAD_DOWNLOADING,        // downloading 
SRV_MRE_APPMGR_DOWNLOAD_DONE,               // app download successfully 
SRV_MRE_APPMGR_DOWNLOAD_NETWORK_ERROR,      //network error 
SRV_MRE_APPMGR_DOWNLOAD_MEMORY_FULL_ERROR,  //not enough memory 
SRV_MRE_APPMGR_DOWNLOAD_IO_ERROR,           // I/O error 
SRV_MRE_APPMGR_DOWNLOAD_OTHER_ERROR,        // other error 
SRV_MRE_APPMGR_DOWNLOAD_END_OF_ENUM
} srv_mre_appmgr_download_state_enum;
typedef void (*srv_mre_appmgr_download_cb_t) (U32 app_id, srv_mre_appmgr_download_state_enum state, U32 file_size);
*/

typedef struct
{
    U32 app_id; /*come from vxp*/
    U32 app_size;
    U32 autostart;
    srv_mre_appmgr_app_type_enum app_type;
    srv_mre_appmgr_app_storage_position_enum store_pos;
    applib_time_struct installed_time;
    U32 app_unique_id;  /*come from res def*/
    U16 width;
    U16 height;
    U16 developer[SRV_MRE_APPMGR_DEVELOPER_NAME_LEN_SAVE];
    U16 tel[SRV_MRE_APPMGR_TEL_NUM_LEN];
    U16 app_name[3][SRV_MRE_APPMGR_APP_NAME_LEN];
    U16 app_path[SRV_MRE_APPMGR_FILEPATH_LEN];
    U32 child_unique_id;
} srv_mre_appmgr_installed_info_struct;
typedef struct 
{
    char mre[FORMAT_MRE_LEN]; // MRE0000
    U32  mreappmgr_id;        // resgen appid if change,should format
}srv_mre_appmgr_format_check;
//unique id map packagename

typedef enum
{
    SRV_MRE_APPMGR_ICON_PBM = 1,
    SRV_MRE_APPMGR_ICON_AB2,
    SRV_MRE_APPMGR_ICON_IMG,
    SRV_MRE_APPMGR_ICON_END_OF_ENUM
} srv_mre_appmgr_app_icon_type_enum;

typedef struct
{
    U16 unique_appid; //the data is 0 or 1
    U16 app_install_type;
    mmi_app_package_char app_install_name[MMI_APP_NAME_MAX_LEN];
#ifdef __LOW_COST_SUPPORT_COMMON__
    U16 app_name[2][SRV_MRE_APPMGR_APP_NAME_LEN];
#else
    U16 app_name[3][SRV_MRE_APPMGR_APP_NAME_LEN];
#endif
    U16 rom_app_path[SRV_MRE_APPMGR_MAX_ROM_PATH_LEN]; // rom app's path in the rom address
    U32 app_id;
    U16 badge;
    srv_mre_appmgr_app_icon_type_enum  icon_type;	// identify icon image type: 1- pbm, 2- ab2, 3 - others
    MMI_BOOL has_image_in_tcard;// 0: no image, 1:has image
    MMI_BOOL image_position;     // 0:image in T-card; 1:image in phone card
}srv_mre_appmgr_map_table;

typedef struct
{
    U32 normal_launch_count;                                  // from mainmeun without badge and launch from file manager
    U32 ncenter_launch_count;                                 // launch from n-center and the payload without custom defined key
    U32 ncenter_launch_has_custom_key_count;    //launch from n-center and the payload has custom defined key
    U32 popup_launch_count;                                   // launch app from popup and the payload without custom defined key
    U32 popup_launch_has_custom_key_count;      // launch app from popup and the payload has custom defined key
    U32 textpreview_launch_count;                          //launch app from textpreview and the payload without custom defined key
    U32 textpreview_launch_has_custom_key_count;  //launch app from textpreview and the payload has custom defined key
    U32 badge_launch_count;                   //launch app from badge.
}srv_mre_appmgr_click_rate_struct;


typedef struct
{ 
    U32  app_unique_id; /*equal to srv_mre_appmgr_installed_info_struct->app_unique_id*/
    U32		style;
    U32 	_badge;	
    U16  	SenderID[MMI_PNS_SENDERID_LEN];
    U16  	app_install_name[MMI_APP_NAME_MAX_LEN];
    U16 	app_path[SRV_MRE_APPMGR_FILEPATH_LEN];
    U32     defer_notification;
    srv_mre_appmgr_click_rate_struct  click_rate;
    U32 	app_id; /*come from vxp for push id*/
} srv_mre_appmgr_push_installed_info_struct;

typedef struct
{
    U32 query_index;                         /*for app to query payload*/
    applib_time_struct receive_time;  /*the receive time for handset reboot to show */
    U8   payload[MMI_PNS_MAX_MSGBODY_SIZE]; /*one payload message*/
}multiple_payload_internal_struct;

typedef struct 
{
    U32 payload_count;        /*the useful load has received for one app to count*/
    multiple_payload_internal_struct  multiple_payload[MRE_PUSH_MAX_PAYLOAD]; /*the payload array*/
}srv_mre_appmgr_push_multiple_payload_struct;

typedef struct
{
    U32 	app_id;      /*the app_id  or push_id is for speedup for not to read file system if one app query continus*/
    srv_mre_appmgr_push_multiple_payload_struct app_payload; /*app payload array struct*/
}srv_mre_appmgr_push_payload_ram_struct;

/*the total push information saved in file system*/
typedef struct
{
    U32  app_unique_id; 
    U32		style;
    U32 	_badge;
    U16		SenderID[MMI_PNS_SENDERID_LEN];	
    U16 	app_install_name[MMI_APP_NAME_MAX_LEN];
    U16 	app_path[SRV_MRE_APPMGR_FILEPATH_LEN];
    U32     defer_notification;
    srv_mre_appmgr_click_rate_struct  click_rate;
    U32 	app_id;
    srv_mre_appmgr_push_multiple_payload_struct app_payload;
} srv_mre_appmgr_push_payload_info_struct;

#ifdef __MRE_SAL_PN__ 
typedef struct mmi_pns_msg_event_struct
{
    srv_pns_msg_event_struct		*original_message;
    U8 							*push_app_image;
    U32							image_size;
}mmi_pns_msg_event_struct;
#endif

typedef struct _srv_mre_appmgr_shortcut_vsm_info_struct
{
    U32     vsm_id;
    CHAR*   vsm_name;
    struct _srv_mre_appmgr_shortcut_vsm_info_struct* next;
}srv_mre_appmgr_shortcut_vsm_info_struct;

typedef struct
{
    U32 app_id;
    U16 icon_id;    /* app icon resource id */
    U16 name_id;    /* app name resource id */
    CHAR* url;
    srv_mre_appmgr_shortcut_vsm_info_struct* vsm;
} srv_mre_appmgr_shortcut_info_struct;

typedef struct
{
    U32 restore_to_factory_mode;
    U32 t_card_has_install;
}srv_mre_appmgr_t_card_install_strut;
/****************************************************************************
* Functions
****************************************************************************/

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_file_path
* DESCRIPTION
*  Get file path of the application.
* PARAMETERS
*  app_name : [IN] the application package identification.
*  filepath : [OUT] get the application file path.
* RETURN VALUES
*  MMI_RET_OK: If successful.
*  MMI_RET_ERR: If failed.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_get_file_path(mmi_app_package_char *app_name, U16 *filepath);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_num
* DESCRIPTION
*  Get the number of all the MRE applications, including build-in applications and shortcut applications.
* PARAMETERS
*  flag : [IN] application manager service flag.
* RETURNS
*  return the number of all application package
*****************************************************************************/
extern U32 srv_mre_appmgr_get_app_num(S32 flag);


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_installed_app_num
* DESCRIPTION
*  Get the number of the installed applications, including build-in applications. But not include shortcut applications.
* PARAMETERS
*  void
* RETURNS
*  return the number of all application package
*****************************************************************************/
extern U32 srv_mre_appmgr_get_installed_app_num(void);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_list
* DESCRIPTION
*  Get the application identifications, including shortcut application.
*  The caller should call srv_mre_appmgr_get_app_num() firstly to prepare the array size.
* PARAMETERS
*  flag : [IN] application manager service flag.
*  name_array : [OUT] get the application name of all installed applications.
*  num : [IN]  the array size.
* RETURN VALUES
*  MMI_RET_OK: Get the application list successfully.
*  MMI_RET_ERR: Get the application list fail.
*****************************************************************************/
extern mmi_ret srv_mre_appmgr_get_app_list(S32 flag, mmi_app_package_name_struct *name_array, U32 num);


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_installed_app_list
* DESCRIPTION
*  Get the application identifications, not include shortcut application.
*  The caller should call srv_mre_appmgr_get_app_num() firstly to prepare the array size.
* PARAMETERS
*  name_array : [OUT] get the application name of all installed applications.
*  num : [IN]  the array size.
* RETURN VALUES
*  MMI_RET_OK: Get the application list successfully.
*  MMI_RET_ERR: Get the application list fail.
*****************************************************************************/
extern mmi_ret srv_mre_appmgr_get_installed_app_list(mmi_app_package_name_struct *name_array, U32 num);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_name
* DESCRIPTION
*  Get the name of application.
* PARAMETERS
*  app_name  : [IN] the application package identification.
*  string    : [OUT] the application name.
* RETURN VALUES
*  MMI_RET_OK: Get the application name successfully.
*  MMI_RET_ERR: Get the application name fail.
*****************************************************************************/
extern mmi_ret srv_mre_appmgr_get_app_name(mmi_app_package_char *app_name, WCHAR *string);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_image
* DESCRIPTION
*  Get the image of application.
* PARAMETERS
*  app_name  : [IN] the application identification.
*  image     : [OUT] the application image.
* RETURN VALUES
*  MMI_RET_OK: Get the application image successfully.
*  MMI_RET_ERR: Get the application image fail.
*****************************************************************************/
extern mmi_ret srv_mre_appmgr_get_app_image(mmi_app_package_char *app_name, mmi_image_src_struct *image);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_info
* DESCRIPTION
*  Get the information of application.
* PARAMETERS
*  app_name  : [IN] the application identification.
*  info      : [OUT] the application information.
* RETURN VALUES
*  MMI_RET_OK: Get the application information successfully.
*  MMI_RET_ERR: Get the application information failed.
*****************************************************************************/
extern mmi_ret srv_mre_appmgr_get_app_info(mmi_app_package_char *app_name, srv_app_info_struct *info);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_launch
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
extern MMI_ID srv_mre_appmgr_launch(mmi_app_package_char *app_name, void *param, U32 param_size);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_launch_by_filepath
* DESCRIPTION
*  Launch an application by file path.
* PARAMETERS
*  app_path : [IN] the application path.
* RETURNS
*  
*****************************************************************************/
extern MMI_ID srv_mre_appmgr_launch_by_filepath(U16 *app_path);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_type
* DESCRIPTION
*  Get application type.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  return app type.
*****************************************************************************/
extern srv_mre_appmgr_app_type_enum srv_mre_appmgr_get_app_type(mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_storage_position
* DESCRIPTION
*  Get application storage position.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  return app storage position.
*****************************************************************************/
extern srv_mre_appmgr_app_storage_position_enum srv_mre_appmgr_get_app_storage_position(
    mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_description
* DESCRIPTION
*  Get the description of a MRE application. If p_desc is NULL, then return the description size by desc_size.
* PARAMETERS
*  app_name : [IN] the application identification.
*  p_desc : [OUT] Pointer to app description buffer.
*  desc_size : [OUT] Size of app description.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_get_app_description(mmi_app_package_char *app_name, U16 *p_desc, U32 *desc_size);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_size
* DESCRIPTION
*  Get application size.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  return app size.
*****************************************************************************/
extern U32 srv_mre_appmgr_get_app_size(mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_developer
* DESCRIPTION
*  Get the developer name of a MRE application. If p_developer is NULL, then return the name size by developer_size.
* PARAMETERS
*  app_name : [IN] the application identification.
*  p_developer : [OUT] Pointer to developer name buffer, and the length of number less than 10.
*  developer_size : [OUT] Size of developer name.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_get_app_developer(mmi_app_package_char *app_name, U16 *p_developer, U32 *developer_size);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_tel
* DESCRIPTION
*  Get the telephone number of the developer.
* PARAMETERS
*  app_name : [IN] the application identification.
*  p_tel : [OUT] Pointer to telephone number buffer, and the length of number less than 20.
* RETURN VALUES
*  MMI_TRUE : If successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_get_app_tel(mmi_app_package_char *app_name, U16 *p_tel);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_resolution
* DESCRIPTION
*  Get the resolution of application.
* PARAMETERS
*  app_name  : [IN] the application package identification.
*  width    : [OUT] width.
*  height    : [OUT] height. 
* RETURN VALUES
*  MMI_RET_OK: Get the application resolution successfully.
*  MMI_RET_ERR: Get the application resolution fail.
*****************************************************************************/
mmi_ret srv_mre_appmgr_get_app_resolution(mmi_app_package_char *app_name, U32 *width, U32 *height);


/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_support_uninstall
* DESCRIPTION
*  Uninstall an application.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If uninstall successful.
*  MMI_FALSE : If failed.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_app_uninstall(mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_bg_downloading
* DESCRIPTION
*  Check if the application is downloading in background.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If downloading in background.
*  MMI_FALSE : If not downloading in background.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_is_bg_downloading(mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_bg_downloading_by_path
* DESCRIPTION
*  Check if the application is downloading in background.
* PARAMETERS
*  app_path : [IN] the application file path.
* RETURN VALUES
*  MMI_TRUE : If downloading in background.
*  MMI_FALSE : If not downloading in background.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_is_bg_downloading_by_path(U16 *app_path);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_download
* DESCRIPTION
*  Download a shortcut application from main menu.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  void
*****************************************************************************/
extern void srv_mre_appmgr_download(mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_bg_running
* DESCRIPTION
*  Check if the application is running in background.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If running in background.
*  MMI_FALSE : If not running in background.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_is_bg_running(mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_app_exist
* DESCRIPTION
*  Check if the application exist or not.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If app exists.
*  MMI_FALSE : If app not exist.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_is_app_exist(mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_shortcut_app
* DESCRIPTION
*  Check if the application is shortcut app.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If it is shortcut app.
*  MMI_FALSE : If it is not shortcut app.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_is_shortcut_app(mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_install_time
* DESCRIPTION
*  Get the install time.
* PARAMETERS
*  app_name : [IN] the application identification.
*  install_time : [OUT] install time
* RETURN VALUES
*  MMI_TRUE: Get install time successfully.
*  MMI_FALSE: Get install time failed.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_get_app_installed_time(
    mmi_app_package_char *app_name,
    applib_time_struct *install_time);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_install_app
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
extern MMI_BOOL srv_mre_appmgr_install_app(
    U16 *app_path,
    srv_mre_appmgr_app_type_enum app_type,
    mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_support_uninstall
* DESCRIPTION
*  Check if the application support uninstall.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If support uninstall.
*  MMI_FALSE : If not support uninstall.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_is_support_uninstall(mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_app_installed
* DESCRIPTION
*  Check if the application is installed.
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURN VALUES
*  MMI_TRUE : If the app is installed.
*  MMI_FALSE : If the app is not installed.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_is_app_installed(mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_app_installed_by_path
* DESCRIPTION
*  Check if the application is installed by app path.
* PARAMETERS
*  app_path : [IN] the application path.
* RETURN VALUES
*  MMI_TRUE : If the app is installed.
*  MMI_FALSE : If the app is not installed.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_is_app_installed_by_path(U16 *app_path);

//#ifdef __MRE_LIB_NETWORK__
/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_check_update
* DESCRIPTION
*  Check if the application need to update.
* PARAMETERS
*  app_name : [IN] the application identification.
*  check_cb : [IN] get update state by this callback.
* RETURN VALUES
*  MMI_TRUE : If start check update request successfully.
*  MMI_FALSE : If start check update request failed.
*****************************************************************************/
/*extern MMI_BOOL srv_mre_appmgr_check_update(
mmi_app_package_char *app_name,
srv_mre_appmgr_app_update_check_cb_t check_cb);*/

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_cancel_check_update
* DESCRIPTION
*  Cancel the check update operation.
* PARAMETERS
*  void
* RETURN VALUES
*  void
*****************************************************************************/
//extern void srv_mre_appmgr_cancel_check_update(void);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_app_update
* DESCRIPTION
*  Start update application, the download will be added to DLAgent.
* PARAMETERS
*  appid : [IN] application id.
*  filename : [IN] after dwonloaded, save as this filename. You should get this filename by srv_mre_appmgr_check_update().
*  filesize : [IN] file total size.
*  update_cb : [IN] update callback funtion.
*  user_data : [IN] user data.
* RETURN VALUES
*  MMI_TRUE : If start update request successfully.
*  MMI_FALSE : If start update request failed.
*****************************************************************************/
/*extern MMI_BOOL srv_mre_appmgr_app_update(
U32 appid, 
U16 *filename, 
U32 *filesize, 
srv_mre_appmgr_app_update_cb_t update_cb,
void *user_data);*/

/****************************************************************************
* The following api provided for download agent.
* 1. srv_mre_appmgr_download_get_app_info
* 2. srv_mre_appmgr_download_start
* 3. srv_mre_appmgr_download_stop
* 4. srv_mre_appmgr_download_cancel
****************************************************************************/

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_da_download_get_app_info
* DESCRIPTION
*  Before start a download, you should call this function to get filesize and filename.
* PARAMETERS
*  appid : [IN] the application id.
*  getinfo_cb : [IN] get application file size and file name by this callback.
* RETURN VALUES
*  MMI_RET_OK: If start a getinfo request successfully.
*  MMI_RET_ERR: If failed.
*****************************************************************************/
//extern mmi_ret srv_mre_appmgr_da_download_get_app_info(U32 appid, srv_mre_appmgr_download_getinfo_cb_t getinfo_cb);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_da_download_cancel_get_app_info
* DESCRIPTION
*  Cancel the get info operation.
* PARAMETERS
*  void
* RETURN VALUES
*  void
*****************************************************************************/
//extern void srv_mre_appmgr_da_download_cancel_get_app_info(void);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_da_download_start
* DESCRIPTION
*  Start a download.
* PARAMETERS
*  appid : [IN] the application id.
*  filepath : [IN] after download, save as this filepath. You should get this filename by srv_mre_appmgr_da_download_get_app_info().
*  download_cb : [IN] get download status and information by this callback.
* RETURN VALUES
*  MMI_RET_OK: If start download request successfully.
*  MMI_RET_ERR: If failed.
*****************************************************************************/
//extern mmi_ret srv_mre_appmgr_da_download_start(U32 appid, U16 *filepath, srv_mre_appmgr_download_cb_t download_cb);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_da_download_stop
* DESCRIPTION
*  Stop a download. After stop a download, it will be pause state in DLAgent.
* PARAMETERS
*  appid : [IN] the application id.
* RETURN VALUES
*  MMI_RET_OK: If stop download successfully.
*  MMI_RET_ERR: If failed.
*****************************************************************************/
//extern mmi_ret srv_mre_appmgr_da_download_stop(U32 appid);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_da_download_cancel
* DESCRIPTION
*  Cancel a download. Means stop the download and delete the temp file, when download it again, will start from the beginning.
* PARAMETERS
*  appid : [IN] the application id.
* RETURN VALUES
*  MMI_RET_OK: If cancel download successfully.
*  MMI_RET_ERR: If failed.
*****************************************************************************/
//extern mmi_ret srv_mre_appmgr_da_download_cancel(U32 appid);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_generate_identification
* DESCRIPTION
*  Generate identification (app name).
* PARAMETERS
*  app_path:[IN] application file path.
*  app_name : [OUT] the application identification.
* RETURN VALUES
*  MMI_TRUE: If successful.
*  MMI_FALSE: If failed.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_generate_identification(U16 *app_path, U16 *app_name);

extern MMI_BOOL srv_mre_appmgr_is_able_to_install(U16 *app_path);
/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_app_unique_id_list
* DESCRIPTION
*  Get the application identifications, including shortcut application.
*  The caller should call srv_mre_appmgr_get_app_num() firstly to prepare the array size.
* PARAMETERS
*  flag : [IN] application manager service flag.
*  name_array : [OUT] get the application id of all installed applications.
*  num : [IN]  the array size.
* RETURN VALUES
*  MMI_RET_OK: Get the application list successfully.
*  MMI_RET_ERR: Get the application list fail.
*****************************************************************************/
extern mmi_ret srv_mre_appmgr_get_unique_app_id_list(S32 flag, U32 *unique_id_array, U32 num);
/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_package_name_by_unique_id
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  
*****************************************************************************/
extern mmi_ret srv_mre_appmgr_get_package_name_by_unique_id(U32 id,mmi_app_package_char *app_name);

/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_get_unique_app_id
* DESCRIPTION
*  
* PARAMETERS
*  app_name : [IN] the application identification.
* RETURNS
*  
*****************************************************************************/
extern U32 srv_mre_appmgr_get_unique_app_id(mmi_app_package_char *app_name);

//#endif /* __MRE_LIB_NETWORK__ */
extern U32 srv_mre_appmgr_get_autostart(mmi_app_package_char *app_name);
/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_update_install
* DESCRIPTION
*  install app when update
* PARAMETERS
*  app_path:[IN] application file path.
* RETURN VALUES
*  MMI_TRUE: If successful.
*  MMI_FALSE: If failed.
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_update_install(U16 *app_path);
/*****************************************************************************
* FUNCTION
*  srv_mre_appmgr_is_app_installed_by_develop_and_name
* DESCRIPTION
*  by app_name and app develop name to determine a mre app is installed or not.
* PARAMETERS
*  app_name ,app_dev: [IN] the application identification. [OUT]app_package_name
* RETURN VALUES
*  void
*****************************************************************************/
extern MMI_BOOL srv_mre_appmgr_is_app_installed_by_develop_and_name(S32 app_type, U16 *app_name,U16* app_dev,U16 *app_package_name);
extern MMI_BOOL srv_mre_appmgr_is_shortcut_app_by_id(U32 app_id);

extern S32 srv_mre_appmgr_get_shortcut_app_info(mmi_app_package_char *app_name,srv_mre_appmgr_shortcut_info_struct* info);

extern CHAR* srv_mre_appmgr_get_app_url(mmi_app_package_char *app_name);

extern S32 srv_mre_appmgr_get_shortcut_app_name_package(U32 app_id, mmi_app_package_char *app_name);

extern U32 srv_mre_appmgr_get_appid(U16 *app_name);
#ifdef __MRE_SAL_PN__
extern U32 srv_mre_appmgr_get_push_app_num(void);
extern mmi_ret srv_mre_push_reveiver_get_click_rate(U32 push_id, srv_mre_appmgr_click_rate_struct *click);
extern mmi_ret srv_mre_push_reveiver_set_click_rate(U32 push_id);
#endif

#ifdef __MMI_MRE_PREINSTALL_TCARD_PACKAGE__
extern void srv_mre_appmgr_preinstall_tcard_app_uninstall(void);
#endif


/* DOM-NOT_FOR_SDK-END */

#endif /* __MRE_APPMGR_SRV_GPROT_H__ */ 

