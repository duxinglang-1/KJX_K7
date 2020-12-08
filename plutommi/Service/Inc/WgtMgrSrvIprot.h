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
 * WgtMgrSrvIprot.h
 *
 * Project:
 * --------
 * MAUI
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef WGTMGR_SRV_IPROT_H
#define WGTMGR_SRV_IPROT_H

#include "kal_general_types.h"
#include "MMIDataType.h"
#include "WgtMgrSrvGprot.h"
#include "widget_adp_struct.h"
#ifdef __PLUTO_MMI_PACKAGE__
#include "vadp_p2v_hs.h"
#endif

#ifdef __cplusplus
extern "C"
{
#endif

/************************************************************************/
/* Structure and Definition                                             */
/************************************************************************/
#ifdef __WGTMGR_MGR_PHONE_WIDGET__
#define SRV_WGTMGR_MAX_PHONE_WGT_NUM       (VADP_P2V_HS_PHONE_WIDGET_NUM)
#else
#define SRV_WGTMGR_MAX_PHONE_WGT_NUM       (0)
#endif

#ifdef __COSMOS_MMI_PACKAGE__
#define SRV_WGTMGT_MAX_ENABLED_WGT_NUM     (SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM)
#else
#define SRV_WGTMGT_MAX_ENABLED_WGT_NUM     (VADP_P2V_HS_MAX_WIDGET_NUM)
#endif

#define SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM  (WIDGET_MGR_MAX_INSTALLED_WGT_NUM)
#define SRV_WGTMGR_MAX_TOTAL_WGT_NUM       (SRV_WGTMGR_MAX_PHONE_WGT_NUM + SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM)

#define SRV_WGTMGR_MAX_WGT_NAME_LEN       WIDGET_MGR_MAX_WGT_NAME_LEN  /* The maximum length of a widget name */
#define SRV_WGTMGR_MAX_WGT_VERSION_LEN    WIDGET_MGR_MAX_WGT_VERSION_LEN  /* The maximum length of a widget version */
#define SRV_WGTMGR_MAX_WGT_AUTHOR_LEN     WIDGET_MGR_MAX_WGT_AUTHOR_LEN
#define SRV_WGTMGR_MAX_WGT_COPYRIGHT_LEN  WIDGET_MGR_MAX_WGT_COPYRIGHT_LEN
#define SRV_WGTMGR_MAX_WGT_SIZE_LEN      (8)   /* The maximum length of a widget size */
#define SRV_WGTMGR_MAX_WGT_ICON_PATH_LEN (30)  /* The maximum length of the path of a widget icon */
#define SRV_WGTMGR_MAX_WGT_MAIN_VIEW_PATH_LEN (30)
#define SRV_WGTMGR_MAX_WGT_MANIFEST_PATH_LEN  (40)

#define SRV_WGTMGR_ATTR_NETWORK_ACCESS   WIDGET_MGR_ATTR_NETWORK_ACCESS /* the widget which needs network access */
#define SRV_WGTMGR_ATTR_UNDELETABLE      WIDGET_MGR_ATTR_UNDELETABLE /* the widget which is not deletable */
#define SRV_WGTMGR_ATTR_NOT_DISABLE      WIDGET_MGR_ATTR_NOT_DISABLE /* the widget which is not disable   */
#define SRV_WGTMGR_ATTR_PREINSTALL       WIDGET_MGR_ATTR_PREINSTALL
#define SRV_WGTMGR_ATTR_PRELOAD          WIDGET_MGR_ATTR_PRELOAD
#define SRV_WGTMGR_ATTR_MAINMENU         WIDGET_MGR_ATTR_MAINMENU


/* the sort order of installed widgets */
typedef enum
{
    SRV_WGTMGR_SORT_BY_NAME,            /* sort by name */
    SRV_WGTMGR_SORT_BY_INSTALLED_TIME,  /* sort by installed time */
    SRV_WGTMGR_SORT_BY_TOTAL_NUM
} srv_wgtmgr_sort_order_enum;


/* The result of verification of a widget */
typedef struct
{

    WCHAR wgt_name[SRV_WGTMGR_MAX_WGT_NAME_LEN + 1];       /* widget name    */
    WCHAR wgt_version_install[SRV_WGTMGR_MAX_WGT_VERSION_LEN + 1]; /* version of widget to install */
    WCHAR wgt_version_original[SRV_WGTMGR_MAX_WGT_VERSION_LEN + 1]; /* verison of widget currently */
    WCHAR wgt_author[SRV_WGTMGR_MAX_WGT_AUTHOR_LEN + 1];
    WCHAR wgt_copyright[SRV_WGTMGR_MAX_WGT_COPYRIGHT_LEN + 1];
    srv_wgtmgr_result_enum result;                         /* result of verification */
} srv_wgtmgr_install_wgt_result_struct;


typedef struct 
{
   WCHAR wgt_name[SRV_WGTMGR_MAX_WGT_NAME_LEN + 1];       
   WCHAR wgt_version[SRV_WGTMGR_MAX_WGT_VERSION_LEN + 1]; 
   WCHAR wgt_author[SRV_WGTMGR_MAX_WGT_AUTHOR_LEN + 1];
   WCHAR wgt_copyright[SRV_WGTMGR_MAX_WGT_COPYRIGHT_LEN + 1];
   srv_wgtmgr_result_enum result;
   S32 wgt_id;
} srv_wgtmgr_wgt_detail_struct;

	

/* The information of a downloaded widget */
typedef struct
{
    WCHAR     version[SRV_WGTMGR_MAX_WGT_VERSION_LEN + 1]; /* widget version (UCS2)  */
    WCHAR     name[SRV_WGTMGR_MAX_WGT_NAME_LEN + 1];       /* widget name (UCS2)     */
    WCHAR     size[SRV_WGTMGR_MAX_WGT_SIZE_LEN + 1];       /* widget size (UCS2) */
    MMI_BOOL  enabled;   /* whether a widget is enabled or not*/
    U32       install_time;
    U8        attribute; /* the attribute of a widget */    
} srv_wgtmgr_downloaded_wgt_info_struct;


/* The information of a phone widget */
typedef struct
{
    U16       name;        /* widget name (string id) */
    MMI_BOOL  enabled;     /* whether a widget is enabled or not */
    U8        attribute;   /* the attribute of a widget */
} srv_wgtmgr_phone_wgt_info_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/* the drive that a widget is installed in */
typedef enum
{ 
    SRV_WGTMGR_DRIVE_SYSTEM = WIDGET_MGR_DRIVE_SYSTEM,      /* system drive */
    SRV_WGTMGR_DRIVE_PUBLIC = WIDGET_MGR_DRIVE_PUBLIC,      /* public drive */
    SRV_WGTMGR_DRIVE_MEMORY_CARD = WIDGET_MGR_DRIVE_MEMORY_CARD, /* memory card  */
    SRV_WGTMGR_DRIVE_TOTAL_NUM
} srv_wgtmgr_wgt_drive_enum;


typedef enum
{
    SRV_WGTMGR_INSTALL_CONT,
    SRV_WGTMGR_INSTALL_CANCEL
} srv_wgtmgr_op_enum;


/* this contains the information of a widget */
typedef struct
{
    U32 install_time; /* the time of installation */
    U16 size;         /* the size of installed widget folder  */
    U16 idle_width;   /* the width of idle view */
    U16 idle_height;  /* the height of idle view */
    U8  attribute;    /* the attribute of a widget            */
    U8  drive : 3;        /* the drive that a widget is installed */
    U8  max_resolution : 4;
} srv_wgtmgr_wgt_item_struct;


/* this structure contains the information kept when ASM is allocated */
typedef struct
{
    U16 sort_id_list[SRV_WGTMGR_MAX_TOTAL_WGT_NUM];                     /* this contains the sorted widget id */
    U8 sort_type_list[SRV_WGTMGR_MAX_TOTAL_WGT_NUM];
    srv_wgtmgr_wgt_item_struct dwgt[SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM];	 /* this contains the detail information of installed widgets */
    WCHAR dwgt_name[SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM][SRV_WGTMGR_MAX_WGT_NAME_LEN + 1]; /* this contains the names of installed widgets */
    WCHAR version[SRV_WGTMGR_MAX_DOWNLOADED_WGT_NUM][SRV_WGTMGR_MAX_WGT_VERSION_LEN + 1];/* this contains the versions of installed widgets */	
} srv_wgtmgr_wgt_asm_data_struct;


/* this structure contains the information of preload widgets */
typedef struct
{
    S16 id;
    S16 page;	
    S16 x_pos;
    S16 y_pos;		
} srv_wgtmgt_preload_wgt_struct;


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_wgtmgr_start_cb_func_ptr
 * DESCRIPTION
 *  Callback function to notify Widget Manager App that the service is ready
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void (*srv_wgtmgr_start_cb_func_ptr)(void * user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_wgtmgr_delete_wgt_cb_func_ptr
 * DESCRIPTION
 *  Callback function to notify Widget Manager App that the deletion is finished
 * PARAMETERS
 *  result:  [IN]   The result
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void (*srv_wgtmgr_delete_wgt_cb_func_ptr)(void *user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_wgtmgr_verify_wgt_cb_func_ptr
 * DESCRIPTION
 *  Callback function to notify Widget Manager App that the verification is finished
 * PARAMETERS
 *  result_ptr: [IN] The result
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void (*srv_wgtmgr_install_wgt_cont_cb_func_ptr)(S16 wgt_id, srv_wgtmgr_install_wgt_result_struct *result_ptr, void* user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_wgtmgr_install_wgt_finished_cb_func_ptr
 * DESCRIPTION
 *  Callback function to notify Widget Manager App that the installation is finished
 * PARAMETERS
 *  result:  [IN]   The result
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void (*srv_wgtmgr_install_wgt_finished_cb_func_ptr)(srv_wgtmgr_result_enum result, void* user_data);


/*****************************************************************************
 * <GROUP  CallBackFunctions>
 * FUNCTION
 *  srv_wgtmgr_get_wgt_detail_cb_func_ptr
 * DESCRIPTION
 *  Callback function to get detail information of a widget
 * PARAMETERS
 *  widget detail info
 * RETURNS
 *  void
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void (*srv_wgtmgr_get_wgt_detail_cb_func_ptr)(srv_wgtmgr_wgt_detail_struct *info, void* user_data);


/************************************************************************/
/* Function Declaration                                                 */
/************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_start
 * DESCRIPTION
 *  This function is to start the native service of Widget Manager Serive
 * PARAMETERS
 *  mem_ptr : [IN] The pointer of ASM
 *  callback: [IN] The callback invoked when native service is ready
 *  user_data: [IN] The user data of application
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_start(void *mem_ptr, srv_wgtmgr_start_cb_func_ptr callback, void* user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_stop
 * DESCRIPTION
 *  This function is to stop the native service of Widget Manager Serive
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_stop(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_wgt_list
 * DESCRIPTION
 *  This function is used to the list of downloaded widgets
 * PARAMETERS
 *  list : [IN\OUT] widget id list 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_get_downloaded_wgt_list(S32 *list);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_enable_wgt
 * DESCRIPTION
 *  This function is used to enable a widget
 * PARAMETERS
 *  type:  [IN] The widget type
 *  id  :  [IN] The widget id
 * RETURNS
 *  The result of the operation
 *****************************************************************************/
extern S32 srv_wgtmgr_enable_wgt(srv_wgtmgr_wgt_type_enum type, S32 id);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_disable_wgt
 * DESCRIPTION
 *  This function is used to disable a widget
 * PARAMETERS
 *  type:  [IN] The widget type
 *  id  :  [IN] The widget id
 * RETURNS
 *  The result of the operation
 *****************************************************************************/
extern S32 srv_wgtmgr_disable_wgt(srv_wgtmgr_wgt_type_enum type, S32 id);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_wgt_info
 * DESCRIPTION
 *  This is used to get the information of a widget for displaying on Widget Manager App
 * PARAMETERS
 *  type: [IN]  The widget type
 *  id  : [IN]  The widget id
 *  info: [OUT] The widget information
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_get_phone_wgt_info(S32 id, srv_wgtmgr_phone_wgt_info_struct *info);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_wgt_info
 * DESCRIPTION
 *  This is used to get the information of a widget for displaying on Widget Manager App
 * PARAMETERS
 *  type: [IN]  The widget type
 *  id  : [IN]  The widget id
 *  info: [OUT] The widget information
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_get_downloaded_wgt_info(S32 id, srv_wgtmgr_downloaded_wgt_info_struct *info);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_is_wgt_enabled
 * DESCRIPTION
 *  This function is used to check if a widget is enabled
 * PARAMETERS
 *  type: [IN] the type of widget
 *  id: [IN] the index of widget
 * RETURNS
 *  MMI_TRUE if the widget is enabled
 *****************************************************************************/
extern MMI_BOOL srv_wgtmgr_is_wgt_enabled(srv_wgtmgr_wgt_type_enum type, S32 id);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_phone_wgt_icon_id
 * DESCRIPTION
 *  This is used to get the information of a widget for displaying on Widget Manager App
 * PARAMETERS
 *  type: [IN]  The widget type
 *  id  : [OUT] The widget information
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_wgtmgr_get_phone_wgt_icon_id(S32 index, S32 *id);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_data_account
 * DESCRIPTION
 *  This is used to set data account of installed widgets.
 * PARAMETERS
 *  index: [IN] data account index
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_set_data_account(U32 index);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_default_data_account
 * DESCRIPTION
 *  This is used to set data account of installed widgets.
 * PARAMETERS
 *  sim: [IN] sim id
 *  account_id: [IN] data account id
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_set_default_data_account(srv_wgtmgr_sim_enum sim, U32 account_id);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_da_app_id
 * DESCRIPTION
 *   This is used to get data account app id of widget manager.
 * PARAMETERS
 *   void
 * RETURNS
 *   U8 data account app id
 *****************************************************************************/
extern U8 srv_wgtmgr_get_da_app_id(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_network_access
 * DESCRIPTION
 *  This is used to set network access setting of installed widgets.
 * PARAMETERS
 *  index: [IN] network access setting
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_set_network_access(srv_wgtmgr_network_access_enum index);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_wifi_only
 * DESCRIPTION
 *  This function is used to set if widgets connect network with WiFi only
 * PARAMETERS
 *  wifi_only : [IN]
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_set_wifi_only(MMI_BOOL wifi_only);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_sort_order
 * DESCRIPTION
 *  This is used to get sort order of installed widgets.
 * PARAMETERS
 *  void
 * RETURNS
 *  sort order
 *****************************************************************************/
extern srv_wgtmgr_sort_order_enum srv_wgtmgr_get_sort_order(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_set_sort_order
 * DESCRIPTION
 *  This is used to set sort order of installed widgets.
 * PARAMETERS
 *  index: [IN] the index of sort order
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_set_sort_order(srv_wgtmgr_sort_order_enum index);

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_install_wgt
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_INSTALL_WGT_REQ to WIDGET task
 * PARAMETERS
 *  path: [IN] the path of widget file to install
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_install_wgt(WCHAR *path, srv_wgtmgr_install_wgt_cont_cb_func_ptr callback, void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_install_wgt_cont
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_INSTALL_WGT_CONT_REQ to WIDGET task
 * PARAMETERS
 *  path: [IN] the path of widget file to install
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_install_wgt_cont(srv_wgtmgr_op_enum op, srv_wgtmgr_wgt_drive_enum drive, srv_wgtmgr_install_wgt_finished_cb_func_ptr callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_delete_wgt
 * DESCRIPTION
 *  This function is used to send WIDGET_MGR_DELETE_WGT_REQ to WIDGET task
 * PARAMETERS
 *  instance_id: [IN] the instance id of widget to delete
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_delete_wgt(S32 id, srv_wgtmgr_delete_wgt_cb_func_ptr callback, void * user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_recover_gadget_folder
 * DESCRIPTION
 *  this funciton is to recover all gadget folders
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_recover_gadget_folder(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_wgt_detail
 * DESCRIPTION
 *  This function is used to get widget detail
 * PARAMETERS
 *  id: [IN] the id of widget in query
 *  callback : [IN] the callback which will be invoked when information is ready
 *  user_data: [IN] the user_data will be a parameter of callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_wgtmgr_get_downloaded_wgt_detail(S32 id, srv_wgtmgr_get_wgt_detail_cb_func_ptr callback, void* user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_downloaded_wgt_installed_drive
 * DESCRIPTION
 *  This function is used to get the drive where widget is installed
 * PARAMETERS
 *  id: [IN] the id of widget in query
 * RETURNS
 *  drive
 *****************************************************************************/
extern srv_wgtmgr_wgt_drive_enum srv_wgtmgr_get_downloaded_wgt_installed_drive(S32 id);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_preinstall_widget
 * DESCRIPTION
 *  This function is to check if a id is valid
 * PARAMETERS
 *  id:  [IN] data account id 
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_wgtmgr_preinstall_widget(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_preload_widget_num
 * DESCRIPTION
 *  This function is to get number of preload widgets
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_wgtmgr_get_preload_widget_num(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_preload_widget_list
 * DESCRIPTION
 *  This function is to get list of preload widgets
 * PARAMETERS
 *  list:  [IN/OUT] widget list
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_wgtmgr_get_preload_widget_list(srv_wgtmgt_preload_wgt_struct *list);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_mainmenu_wgt_list
 * DESCRIPTION
 *  This function is to get number of mainmenu widgets
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_wgtmgr_get_mainmenu_wgt_num(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_get_mainmenu_wgt_list
 * DESCRIPTION
 *  This function is to get list of mainmenu widgets
 * PARAMETERS
 *  list:  [IN/OUT] widget list
 * RETURNS
 *  S32
 *****************************************************************************/
extern void srv_wgtmgr_get_mainmenu_wgt_list(mmi_app_package_name_struct *list_ptr);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_bearer_disconnect
 * DESCRIPTION
 *  This function is to notify bearer disconnect event
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
extern void srv_wgtmgr_bearer_disconnect(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wgtmgr_bearer_switch
 * DESCRIPTION
 *  This function is to notify bearer switch event
 * PARAMETERS
 *  user_reulst:  [IN] user selection result
 *  switch_type: [IN] bear switch type
 * RETURNS
 *  S32
 *****************************************************************************/
extern void srv_wgtmgr_bearer_switch(kal_bool user_result,int switch_type);

#ifdef __cplusplus
}
#endif
#endif /* WGTMGR_SRV_IPROT_H */
